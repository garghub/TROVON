static u8 xor_chksum_set(void *data)
{
int idx;
u8 *val, checksum = 0;
val = data;
for (idx = 0; idx < 7; idx++)
checksum ^= val[idx];
return checksum;
}
static void set_prod_idx(struct hinic_api_cmd_chain *chain)
{
enum hinic_api_cmd_chain_type chain_type = chain->chain_type;
struct hinic_hwif *hwif = chain->hwif;
u32 addr, prod_idx;
addr = HINIC_CSR_API_CMD_CHAIN_PI_ADDR(chain_type);
prod_idx = hinic_hwif_read_reg(hwif, addr);
prod_idx = HINIC_API_CMD_PI_CLEAR(prod_idx, IDX);
prod_idx |= HINIC_API_CMD_PI_SET(chain->prod_idx, IDX);
hinic_hwif_write_reg(hwif, addr, prod_idx);
}
static u32 get_hw_cons_idx(struct hinic_api_cmd_chain *chain)
{
u32 addr, val;
addr = HINIC_CSR_API_CMD_STATUS_ADDR(chain->chain_type);
val = hinic_hwif_read_reg(chain->hwif, addr);
return HINIC_API_CMD_STATUS_GET(val, CONS_IDX);
}
static int chain_busy(struct hinic_api_cmd_chain *chain)
{
struct hinic_hwif *hwif = chain->hwif;
struct pci_dev *pdev = hwif->pdev;
u32 prod_idx;
switch (chain->chain_type) {
case HINIC_API_CMD_WRITE_TO_MGMT_CPU:
chain->cons_idx = get_hw_cons_idx(chain);
prod_idx = chain->prod_idx;
if (chain->cons_idx == MASKED_IDX(chain, prod_idx + 1)) {
dev_err(&pdev->dev, "API CMD chain %d is busy\n",
chain->chain_type);
return -EBUSY;
}
break;
default:
dev_err(&pdev->dev, "Unknown API CMD Chain type\n");
break;
}
return 0;
}
static u8 get_cell_data_size(enum hinic_api_cmd_chain_type type)
{
u8 cell_data_size = 0;
switch (type) {
case HINIC_API_CMD_WRITE_TO_MGMT_CPU:
cell_data_size = ALIGN(API_CMD_CELL_DESC_SIZE +
API_CMD_CELL_DATA_ADDR_SIZE,
API_CMD_CELL_ALIGNMENT);
break;
default:
break;
}
return cell_data_size;
}
static void prepare_cell_ctrl(u64 *cell_ctrl, u16 data_size)
{
u8 chksum;
u64 ctrl;
ctrl = HINIC_API_CMD_CELL_CTRL_SET(SIZE_8BYTES(data_size), DATA_SZ) |
HINIC_API_CMD_CELL_CTRL_SET(RD_DMA_ATTR_DEFAULT, RD_DMA_ATTR) |
HINIC_API_CMD_CELL_CTRL_SET(WR_DMA_ATTR_DEFAULT, WR_DMA_ATTR);
chksum = xor_chksum_set(&ctrl);
ctrl |= HINIC_API_CMD_CELL_CTRL_SET(chksum, XOR_CHKSUM);
*cell_ctrl = cpu_to_be64(ctrl);
}
static void prepare_api_cmd(struct hinic_api_cmd_chain *chain,
enum hinic_node_id dest,
void *cmd, u16 cmd_size)
{
struct hinic_api_cmd_cell *cell = chain->curr_node;
struct hinic_api_cmd_cell_ctxt *cell_ctxt;
struct hinic_hwif *hwif = chain->hwif;
struct pci_dev *pdev = hwif->pdev;
cell_ctxt = &chain->cell_ctxt[chain->prod_idx];
switch (chain->chain_type) {
case HINIC_API_CMD_WRITE_TO_MGMT_CPU:
cell->desc = HINIC_API_CMD_DESC_SET(SGE_DATA, API_TYPE) |
HINIC_API_CMD_DESC_SET(API_CMD_WRITE, RD_WR) |
HINIC_API_CMD_DESC_SET(NO_BYPASS, MGMT_BYPASS);
break;
default:
dev_err(&pdev->dev, "unknown Chain type\n");
return;
}
cell->desc |= HINIC_API_CMD_DESC_SET(dest, DEST) |
HINIC_API_CMD_DESC_SET(SIZE_4BYTES(cmd_size), SIZE);
cell->desc |= HINIC_API_CMD_DESC_SET(xor_chksum_set(&cell->desc),
XOR_CHKSUM);
cell->desc = cpu_to_be64(cell->desc);
memcpy(cell_ctxt->api_cmd_vaddr, cmd, cmd_size);
}
static void prepare_cell(struct hinic_api_cmd_chain *chain,
enum hinic_node_id dest,
void *cmd, u16 cmd_size)
{
struct hinic_api_cmd_cell *curr_node = chain->curr_node;
u16 data_size = get_cell_data_size(chain->chain_type);
prepare_cell_ctrl(&curr_node->ctrl, data_size);
prepare_api_cmd(chain, dest, cmd, cmd_size);
}
static inline void cmd_chain_prod_idx_inc(struct hinic_api_cmd_chain *chain)
{
chain->prod_idx = MASKED_IDX(chain, chain->prod_idx + 1);
}
static void api_cmd_status_update(struct hinic_api_cmd_chain *chain)
{
enum hinic_api_cmd_chain_type chain_type;
struct hinic_api_cmd_status *wb_status;
struct hinic_hwif *hwif = chain->hwif;
struct pci_dev *pdev = hwif->pdev;
u64 status_header;
u32 status;
wb_status = chain->wb_status;
status_header = be64_to_cpu(wb_status->header);
status = be32_to_cpu(wb_status->status);
if (HINIC_API_CMD_STATUS_GET(status, CHKSUM_ERR)) {
dev_err(&pdev->dev, "API CMD status: Xor check error\n");
return;
}
chain_type = HINIC_API_CMD_STATUS_HEADER_GET(status_header, CHAIN_ID);
if (chain_type >= HINIC_API_CMD_MAX) {
dev_err(&pdev->dev, "unknown API CMD Chain %d\n", chain_type);
return;
}
chain->cons_idx = HINIC_API_CMD_STATUS_GET(status, CONS_IDX);
}
static int wait_for_status_poll(struct hinic_api_cmd_chain *chain)
{
int err = -ETIMEDOUT;
unsigned long end;
end = jiffies + msecs_to_jiffies(API_CMD_TIMEOUT);
do {
api_cmd_status_update(chain);
if (chain->cons_idx == chain->prod_idx) {
err = 0;
break;
}
msleep(20);
} while (time_before(jiffies, end));
return err;
}
static int wait_for_api_cmd_completion(struct hinic_api_cmd_chain *chain)
{
struct hinic_hwif *hwif = chain->hwif;
struct pci_dev *pdev = hwif->pdev;
int err;
switch (chain->chain_type) {
case HINIC_API_CMD_WRITE_TO_MGMT_CPU:
err = wait_for_status_poll(chain);
if (err) {
dev_err(&pdev->dev, "API CMD Poll status timeout\n");
break;
}
break;
default:
dev_err(&pdev->dev, "unknown API CMD Chain type\n");
err = -EINVAL;
break;
}
return err;
}
static int api_cmd(struct hinic_api_cmd_chain *chain,
enum hinic_node_id dest, u8 *cmd, u16 cmd_size)
{
struct hinic_api_cmd_cell_ctxt *ctxt;
int err;
down(&chain->sem);
if (chain_busy(chain)) {
up(&chain->sem);
return -EBUSY;
}
prepare_cell(chain, dest, cmd, cmd_size);
cmd_chain_prod_idx_inc(chain);
wmb();
set_prod_idx(chain);
ctxt = &chain->cell_ctxt[chain->prod_idx];
chain->curr_node = ctxt->cell_vaddr;
err = wait_for_api_cmd_completion(chain);
up(&chain->sem);
return err;
}
int hinic_api_cmd_write(struct hinic_api_cmd_chain *chain,
enum hinic_node_id dest, u8 *cmd, u16 size)
{
if (chain->chain_type == HINIC_API_CMD_WRITE_TO_MGMT_CPU)
return api_cmd(chain, dest, cmd, size);
return -EINVAL;
}
static int api_cmd_hw_restart(struct hinic_api_cmd_chain *chain)
{
struct hinic_hwif *hwif = chain->hwif;
int err = -ETIMEDOUT;
unsigned long end;
u32 reg_addr, val;
reg_addr = HINIC_CSR_API_CMD_CHAIN_REQ_ADDR(chain->chain_type);
val = hinic_hwif_read_reg(hwif, reg_addr);
val = HINIC_API_CMD_CHAIN_REQ_CLEAR(val, RESTART);
val |= HINIC_API_CMD_CHAIN_REQ_SET(1, RESTART);
hinic_hwif_write_reg(hwif, reg_addr, val);
end = jiffies + msecs_to_jiffies(API_CMD_TIMEOUT);
do {
val = hinic_hwif_read_reg(hwif, reg_addr);
if (!HINIC_API_CMD_CHAIN_REQ_GET(val, RESTART)) {
err = 0;
break;
}
msleep(20);
} while (time_before(jiffies, end));
return err;
}
static void api_cmd_ctrl_init(struct hinic_api_cmd_chain *chain)
{
struct hinic_hwif *hwif = chain->hwif;
u32 addr, ctrl;
u16 cell_size;
addr = HINIC_CSR_API_CMD_CHAIN_CTRL_ADDR(chain->chain_type);
cell_size = API_CMD_CELL_SIZE_VAL(chain->cell_size);
ctrl = hinic_hwif_read_reg(hwif, addr);
ctrl = HINIC_API_CMD_CHAIN_CTRL_CLEAR(ctrl, RESTART_WB_STAT) &
HINIC_API_CMD_CHAIN_CTRL_CLEAR(ctrl, XOR_ERR) &
HINIC_API_CMD_CHAIN_CTRL_CLEAR(ctrl, AEQE_EN) &
HINIC_API_CMD_CHAIN_CTRL_CLEAR(ctrl, XOR_CHK_EN) &
HINIC_API_CMD_CHAIN_CTRL_CLEAR(ctrl, CELL_SIZE);
ctrl |= HINIC_API_CMD_CHAIN_CTRL_SET(1, XOR_ERR) |
HINIC_API_CMD_CHAIN_CTRL_SET(XOR_CHK_ALL, XOR_CHK_EN) |
HINIC_API_CMD_CHAIN_CTRL_SET(cell_size, CELL_SIZE);
hinic_hwif_write_reg(hwif, addr, ctrl);
}
static void api_cmd_set_status_addr(struct hinic_api_cmd_chain *chain)
{
struct hinic_hwif *hwif = chain->hwif;
u32 addr, val;
addr = HINIC_CSR_API_CMD_STATUS_HI_ADDR(chain->chain_type);
val = upper_32_bits(chain->wb_status_paddr);
hinic_hwif_write_reg(hwif, addr, val);
addr = HINIC_CSR_API_CMD_STATUS_LO_ADDR(chain->chain_type);
val = lower_32_bits(chain->wb_status_paddr);
hinic_hwif_write_reg(hwif, addr, val);
}
static void api_cmd_set_num_cells(struct hinic_api_cmd_chain *chain)
{
struct hinic_hwif *hwif = chain->hwif;
u32 addr, val;
addr = HINIC_CSR_API_CMD_CHAIN_NUM_CELLS_ADDR(chain->chain_type);
val = chain->num_cells;
hinic_hwif_write_reg(hwif, addr, val);
}
static void api_cmd_head_init(struct hinic_api_cmd_chain *chain)
{
struct hinic_hwif *hwif = chain->hwif;
u32 addr, val;
addr = HINIC_CSR_API_CMD_CHAIN_HEAD_HI_ADDR(chain->chain_type);
val = upper_32_bits(chain->head_cell_paddr);
hinic_hwif_write_reg(hwif, addr, val);
addr = HINIC_CSR_API_CMD_CHAIN_HEAD_LO_ADDR(chain->chain_type);
val = lower_32_bits(chain->head_cell_paddr);
hinic_hwif_write_reg(hwif, addr, val);
}
static void api_cmd_chain_hw_clean(struct hinic_api_cmd_chain *chain)
{
struct hinic_hwif *hwif = chain->hwif;
u32 addr, ctrl;
addr = HINIC_CSR_API_CMD_CHAIN_CTRL_ADDR(chain->chain_type);
ctrl = hinic_hwif_read_reg(hwif, addr);
ctrl = HINIC_API_CMD_CHAIN_CTRL_CLEAR(ctrl, RESTART_WB_STAT) &
HINIC_API_CMD_CHAIN_CTRL_CLEAR(ctrl, XOR_ERR) &
HINIC_API_CMD_CHAIN_CTRL_CLEAR(ctrl, AEQE_EN) &
HINIC_API_CMD_CHAIN_CTRL_CLEAR(ctrl, XOR_CHK_EN) &
HINIC_API_CMD_CHAIN_CTRL_CLEAR(ctrl, CELL_SIZE);
hinic_hwif_write_reg(hwif, addr, ctrl);
}
static int api_cmd_chain_hw_init(struct hinic_api_cmd_chain *chain)
{
struct hinic_hwif *hwif = chain->hwif;
struct pci_dev *pdev = hwif->pdev;
int err;
api_cmd_chain_hw_clean(chain);
api_cmd_set_status_addr(chain);
err = api_cmd_hw_restart(chain);
if (err) {
dev_err(&pdev->dev, "Failed to restart API CMD HW\n");
return err;
}
api_cmd_ctrl_init(chain);
api_cmd_set_num_cells(chain);
api_cmd_head_init(chain);
return 0;
}
static void free_cmd_buf(struct hinic_api_cmd_chain *chain, int cell_idx)
{
struct hinic_api_cmd_cell_ctxt *cell_ctxt;
struct hinic_hwif *hwif = chain->hwif;
struct pci_dev *pdev = hwif->pdev;
cell_ctxt = &chain->cell_ctxt[cell_idx];
dma_free_coherent(&pdev->dev, API_CMD_BUF_SIZE,
cell_ctxt->api_cmd_vaddr,
cell_ctxt->api_cmd_paddr);
}
static int alloc_cmd_buf(struct hinic_api_cmd_chain *chain,
struct hinic_api_cmd_cell *cell, int cell_idx)
{
struct hinic_api_cmd_cell_ctxt *cell_ctxt;
struct hinic_hwif *hwif = chain->hwif;
struct pci_dev *pdev = hwif->pdev;
dma_addr_t cmd_paddr;
u8 *cmd_vaddr;
int err = 0;
cmd_vaddr = dma_zalloc_coherent(&pdev->dev, API_CMD_BUF_SIZE,
&cmd_paddr, GFP_KERNEL);
if (!cmd_vaddr) {
dev_err(&pdev->dev, "Failed to allocate API CMD DMA memory\n");
return -ENOMEM;
}
cell_ctxt = &chain->cell_ctxt[cell_idx];
cell_ctxt->api_cmd_vaddr = cmd_vaddr;
cell_ctxt->api_cmd_paddr = cmd_paddr;
switch (chain->chain_type) {
case HINIC_API_CMD_WRITE_TO_MGMT_CPU:
cell->write.hw_cmd_paddr = cpu_to_be64(cmd_paddr);
break;
default:
dev_err(&pdev->dev, "Unsupported API CMD chain type\n");
free_cmd_buf(chain, cell_idx);
err = -EINVAL;
break;
}
return err;
}
static int api_cmd_create_cell(struct hinic_api_cmd_chain *chain,
int cell_idx,
struct hinic_api_cmd_cell *pre_node,
struct hinic_api_cmd_cell **node_vaddr)
{
struct hinic_api_cmd_cell_ctxt *cell_ctxt;
struct hinic_hwif *hwif = chain->hwif;
struct pci_dev *pdev = hwif->pdev;
struct hinic_api_cmd_cell *node;
dma_addr_t node_paddr;
int err;
node = dma_zalloc_coherent(&pdev->dev, chain->cell_size,
&node_paddr, GFP_KERNEL);
if (!node) {
dev_err(&pdev->dev, "Failed to allocate dma API CMD cell\n");
return -ENOMEM;
}
node->read.hw_wb_resp_paddr = 0;
cell_ctxt = &chain->cell_ctxt[cell_idx];
cell_ctxt->cell_vaddr = node;
cell_ctxt->cell_paddr = node_paddr;
if (!pre_node) {
chain->head_cell_paddr = node_paddr;
chain->head_node = node;
} else {
pre_node->next_cell_paddr = cpu_to_be64(node_paddr);
}
switch (chain->chain_type) {
case HINIC_API_CMD_WRITE_TO_MGMT_CPU:
err = alloc_cmd_buf(chain, node, cell_idx);
if (err) {
dev_err(&pdev->dev, "Failed to allocate cmd buffer\n");
goto err_alloc_cmd_buf;
}
break;
default:
dev_err(&pdev->dev, "Unsupported API CMD chain type\n");
err = -EINVAL;
goto err_alloc_cmd_buf;
}
*node_vaddr = node;
return 0;
err_alloc_cmd_buf:
dma_free_coherent(&pdev->dev, chain->cell_size, node, node_paddr);
return err;
}
static void api_cmd_destroy_cell(struct hinic_api_cmd_chain *chain,
int cell_idx)
{
struct hinic_api_cmd_cell_ctxt *cell_ctxt;
struct hinic_hwif *hwif = chain->hwif;
struct pci_dev *pdev = hwif->pdev;
struct hinic_api_cmd_cell *node;
dma_addr_t node_paddr;
size_t node_size;
cell_ctxt = &chain->cell_ctxt[cell_idx];
node = cell_ctxt->cell_vaddr;
node_paddr = cell_ctxt->cell_paddr;
node_size = chain->cell_size;
if (cell_ctxt->api_cmd_vaddr) {
switch (chain->chain_type) {
case HINIC_API_CMD_WRITE_TO_MGMT_CPU:
free_cmd_buf(chain, cell_idx);
break;
default:
dev_err(&pdev->dev, "Unsupported API CMD chain type\n");
break;
}
dma_free_coherent(&pdev->dev, node_size, node,
node_paddr);
}
}
static void api_cmd_destroy_cells(struct hinic_api_cmd_chain *chain,
int num_cells)
{
int cell_idx;
for (cell_idx = 0; cell_idx < num_cells; cell_idx++)
api_cmd_destroy_cell(chain, cell_idx);
}
static int api_cmd_create_cells(struct hinic_api_cmd_chain *chain)
{
struct hinic_api_cmd_cell *node = NULL, *pre_node = NULL;
struct hinic_hwif *hwif = chain->hwif;
struct pci_dev *pdev = hwif->pdev;
int err, cell_idx;
for (cell_idx = 0; cell_idx < chain->num_cells; cell_idx++) {
err = api_cmd_create_cell(chain, cell_idx, pre_node, &node);
if (err) {
dev_err(&pdev->dev, "Failed to create API CMD cell\n");
goto err_create_cell;
}
pre_node = node;
}
node->next_cell_paddr = cpu_to_be64(chain->head_cell_paddr);
chain->curr_node = chain->head_node;
return 0;
err_create_cell:
api_cmd_destroy_cells(chain, cell_idx);
return err;
}
static int api_chain_init(struct hinic_api_cmd_chain *chain,
struct hinic_api_cmd_chain_attr *attr)
{
struct hinic_hwif *hwif = attr->hwif;
struct pci_dev *pdev = hwif->pdev;
size_t cell_ctxt_size;
chain->hwif = hwif;
chain->chain_type = attr->chain_type;
chain->num_cells = attr->num_cells;
chain->cell_size = attr->cell_size;
chain->prod_idx = 0;
chain->cons_idx = 0;
sema_init(&chain->sem, 1);
cell_ctxt_size = chain->num_cells * sizeof(*chain->cell_ctxt);
chain->cell_ctxt = devm_kzalloc(&pdev->dev, cell_ctxt_size, GFP_KERNEL);
if (!chain->cell_ctxt)
return -ENOMEM;
chain->wb_status = dma_zalloc_coherent(&pdev->dev,
sizeof(*chain->wb_status),
&chain->wb_status_paddr,
GFP_KERNEL);
if (!chain->wb_status) {
dev_err(&pdev->dev, "Failed to allocate DMA wb status\n");
return -ENOMEM;
}
return 0;
}
static void api_chain_free(struct hinic_api_cmd_chain *chain)
{
struct hinic_hwif *hwif = chain->hwif;
struct pci_dev *pdev = hwif->pdev;
dma_free_coherent(&pdev->dev, sizeof(*chain->wb_status),
chain->wb_status, chain->wb_status_paddr);
}
static struct hinic_api_cmd_chain *
api_cmd_create_chain(struct hinic_api_cmd_chain_attr *attr)
{
struct hinic_hwif *hwif = attr->hwif;
struct pci_dev *pdev = hwif->pdev;
struct hinic_api_cmd_chain *chain;
int err;
if (attr->num_cells & (attr->num_cells - 1)) {
dev_err(&pdev->dev, "Invalid number of cells, must be power of 2\n");
return ERR_PTR(-EINVAL);
}
chain = devm_kzalloc(&pdev->dev, sizeof(*chain), GFP_KERNEL);
if (!chain)
return ERR_PTR(-ENOMEM);
err = api_chain_init(chain, attr);
if (err) {
dev_err(&pdev->dev, "Failed to initialize chain\n");
return ERR_PTR(err);
}
err = api_cmd_create_cells(chain);
if (err) {
dev_err(&pdev->dev, "Failed to create cells for API CMD chain\n");
goto err_create_cells;
}
err = api_cmd_chain_hw_init(chain);
if (err) {
dev_err(&pdev->dev, "Failed to initialize chain HW\n");
goto err_chain_hw_init;
}
return chain;
err_chain_hw_init:
api_cmd_destroy_cells(chain, chain->num_cells);
err_create_cells:
api_chain_free(chain);
return ERR_PTR(err);
}
static void api_cmd_destroy_chain(struct hinic_api_cmd_chain *chain)
{
api_cmd_chain_hw_clean(chain);
api_cmd_destroy_cells(chain, chain->num_cells);
api_chain_free(chain);
}
int hinic_api_cmd_init(struct hinic_api_cmd_chain **chain,
struct hinic_hwif *hwif)
{
enum hinic_api_cmd_chain_type type, chain_type;
struct hinic_api_cmd_chain_attr attr;
struct pci_dev *pdev = hwif->pdev;
size_t hw_cell_sz;
int err;
hw_cell_sz = sizeof(struct hinic_api_cmd_cell);
attr.hwif = hwif;
attr.num_cells = API_CHAIN_NUM_CELLS;
attr.cell_size = API_CMD_CELL_SIZE(hw_cell_sz);
chain_type = HINIC_API_CMD_WRITE_TO_MGMT_CPU;
for ( ; chain_type < HINIC_API_CMD_MAX; chain_type++) {
attr.chain_type = chain_type;
if (chain_type != HINIC_API_CMD_WRITE_TO_MGMT_CPU)
continue;
chain[chain_type] = api_cmd_create_chain(&attr);
if (IS_ERR(chain[chain_type])) {
dev_err(&pdev->dev, "Failed to create chain %d\n",
chain_type);
err = PTR_ERR(chain[chain_type]);
goto err_create_chain;
}
}
return 0;
err_create_chain:
type = HINIC_API_CMD_WRITE_TO_MGMT_CPU;
for ( ; type < chain_type; type++) {
if (type != HINIC_API_CMD_WRITE_TO_MGMT_CPU)
continue;
api_cmd_destroy_chain(chain[type]);
}
return err;
}
void hinic_api_cmd_free(struct hinic_api_cmd_chain **chain)
{
enum hinic_api_cmd_chain_type chain_type;
chain_type = HINIC_API_CMD_WRITE_TO_MGMT_CPU;
for ( ; chain_type < HINIC_API_CMD_MAX; chain_type++) {
if (chain_type != HINIC_API_CMD_WRITE_TO_MGMT_CPU)
continue;
api_cmd_destroy_chain(chain[chain_type]);
}
}
