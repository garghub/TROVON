static inline struct spi_gpio * __pure
spi_to_spi_gpio(const struct spi_device *spi)
{
const struct spi_bitbang *bang;
struct spi_gpio *spi_gpio;
bang = spi_master_get_devdata(spi->master);
spi_gpio = container_of(bang, struct spi_gpio, bitbang);
return spi_gpio;
}
static inline struct spi_gpio_platform_data * __pure
spi_to_pdata(const struct spi_device *spi)
{
return &spi_to_spi_gpio(spi)->pdata;
}
static inline void setsck(const struct spi_device *spi, int is_on)
{
gpio_set_value_cansleep(SPI_SCK_GPIO, is_on);
}
static inline void setmosi(const struct spi_device *spi, int is_on)
{
gpio_set_value_cansleep(SPI_MOSI_GPIO, is_on);
}
static inline int getmiso(const struct spi_device *spi)
{
return !!gpio_get_value_cansleep(SPI_MISO_GPIO);
}
static u32 spi_gpio_txrx_word_mode0(struct spi_device *spi,
unsigned nsecs, u32 word, u8 bits)
{
return bitbang_txrx_be_cpha0(spi, nsecs, 0, 0, word, bits);
}
static u32 spi_gpio_txrx_word_mode1(struct spi_device *spi,
unsigned nsecs, u32 word, u8 bits)
{
return bitbang_txrx_be_cpha1(spi, nsecs, 0, 0, word, bits);
}
static u32 spi_gpio_txrx_word_mode2(struct spi_device *spi,
unsigned nsecs, u32 word, u8 bits)
{
return bitbang_txrx_be_cpha0(spi, nsecs, 1, 0, word, bits);
}
static u32 spi_gpio_txrx_word_mode3(struct spi_device *spi,
unsigned nsecs, u32 word, u8 bits)
{
return bitbang_txrx_be_cpha1(spi, nsecs, 1, 0, word, bits);
}
static u32 spi_gpio_spec_txrx_word_mode0(struct spi_device *spi,
unsigned nsecs, u32 word, u8 bits)
{
unsigned flags = spi->master->flags;
return bitbang_txrx_be_cpha0(spi, nsecs, 0, flags, word, bits);
}
static u32 spi_gpio_spec_txrx_word_mode1(struct spi_device *spi,
unsigned nsecs, u32 word, u8 bits)
{
unsigned flags = spi->master->flags;
return bitbang_txrx_be_cpha1(spi, nsecs, 0, flags, word, bits);
}
static u32 spi_gpio_spec_txrx_word_mode2(struct spi_device *spi,
unsigned nsecs, u32 word, u8 bits)
{
unsigned flags = spi->master->flags;
return bitbang_txrx_be_cpha0(spi, nsecs, 1, flags, word, bits);
}
static u32 spi_gpio_spec_txrx_word_mode3(struct spi_device *spi,
unsigned nsecs, u32 word, u8 bits)
{
unsigned flags = spi->master->flags;
return bitbang_txrx_be_cpha1(spi, nsecs, 1, flags, word, bits);
}
static void spi_gpio_chipselect(struct spi_device *spi, int is_active)
{
struct spi_gpio *spi_gpio = spi_to_spi_gpio(spi);
unsigned long cs = spi_gpio->cs_gpios[spi->chip_select];
if (is_active)
setsck(spi, spi->mode & SPI_CPOL);
if (cs != SPI_GPIO_NO_CHIPSELECT) {
gpio_set_value_cansleep(cs, (spi->mode & SPI_CS_HIGH) ? is_active : !is_active);
}
}
static int spi_gpio_setup(struct spi_device *spi)
{
unsigned long cs;
int status = 0;
struct spi_gpio *spi_gpio = spi_to_spi_gpio(spi);
struct device_node *np = spi->master->dev.of_node;
if (np) {
cs = spi_gpio->cs_gpios[spi->chip_select];
} else {
cs = (uintptr_t) spi->controller_data;
}
if (!spi->controller_state) {
if (cs != SPI_GPIO_NO_CHIPSELECT) {
status = gpio_request(cs, dev_name(&spi->dev));
if (status)
return status;
status = gpio_direction_output(cs,
!(spi->mode & SPI_CS_HIGH));
}
}
if (!status) {
spi_gpio->cs_gpios[spi->chip_select] = cs;
status = spi_bitbang_setup(spi);
}
if (status) {
if (!spi->controller_state && cs != SPI_GPIO_NO_CHIPSELECT)
gpio_free(cs);
}
return status;
}
static void spi_gpio_cleanup(struct spi_device *spi)
{
struct spi_gpio *spi_gpio = spi_to_spi_gpio(spi);
unsigned long cs = spi_gpio->cs_gpios[spi->chip_select];
if (cs != SPI_GPIO_NO_CHIPSELECT)
gpio_free(cs);
spi_bitbang_cleanup(spi);
}
static int spi_gpio_alloc(unsigned pin, const char *label, bool is_in)
{
int value;
value = gpio_request(pin, label);
if (value == 0) {
if (is_in)
value = gpio_direction_input(pin);
else
value = gpio_direction_output(pin, 0);
}
return value;
}
static int spi_gpio_request(struct spi_gpio_platform_data *pdata,
const char *label, u16 *res_flags)
{
int value;
if (SPI_MOSI_GPIO != SPI_GPIO_NO_MOSI) {
value = spi_gpio_alloc(SPI_MOSI_GPIO, label, false);
if (value)
goto done;
} else {
*res_flags |= SPI_MASTER_NO_TX;
}
if (SPI_MISO_GPIO != SPI_GPIO_NO_MISO) {
value = spi_gpio_alloc(SPI_MISO_GPIO, label, true);
if (value)
goto free_mosi;
} else {
*res_flags |= SPI_MASTER_NO_RX;
}
value = spi_gpio_alloc(SPI_SCK_GPIO, label, false);
if (value)
goto free_miso;
goto done;
free_miso:
if (SPI_MISO_GPIO != SPI_GPIO_NO_MISO)
gpio_free(SPI_MISO_GPIO);
free_mosi:
if (SPI_MOSI_GPIO != SPI_GPIO_NO_MOSI)
gpio_free(SPI_MOSI_GPIO);
done:
return value;
}
static int spi_gpio_probe_dt(struct platform_device *pdev)
{
int ret;
u32 tmp;
struct spi_gpio_platform_data *pdata;
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *of_id =
of_match_device(spi_gpio_dt_ids, &pdev->dev);
if (!of_id)
return 0;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
ret = of_get_named_gpio(np, "gpio-sck", 0);
if (ret < 0) {
dev_err(&pdev->dev, "gpio-sck property not found\n");
goto error_free;
}
pdata->sck = ret;
ret = of_get_named_gpio(np, "gpio-miso", 0);
if (ret < 0) {
dev_info(&pdev->dev, "gpio-miso property not found, switching to no-rx mode\n");
pdata->miso = SPI_GPIO_NO_MISO;
} else
pdata->miso = ret;
ret = of_get_named_gpio(np, "gpio-mosi", 0);
if (ret < 0) {
dev_info(&pdev->dev, "gpio-mosi property not found, switching to no-tx mode\n");
pdata->mosi = SPI_GPIO_NO_MOSI;
} else
pdata->mosi = ret;
ret = of_property_read_u32(np, "num-chipselects", &tmp);
if (ret < 0) {
dev_err(&pdev->dev, "num-chipselects property not found\n");
goto error_free;
}
pdata->num_chipselect = tmp;
pdev->dev.platform_data = pdata;
return 1;
error_free:
devm_kfree(&pdev->dev, pdata);
return ret;
}
static inline int spi_gpio_probe_dt(struct platform_device *pdev)
{
return 0;
}
static int spi_gpio_probe(struct platform_device *pdev)
{
int status;
struct spi_master *master;
struct spi_gpio *spi_gpio;
struct spi_gpio_platform_data *pdata;
u16 master_flags = 0;
bool use_of = 0;
int num_devices;
status = spi_gpio_probe_dt(pdev);
if (status < 0)
return status;
if (status > 0)
use_of = 1;
pdata = dev_get_platdata(&pdev->dev);
#ifdef GENERIC_BITBANG
if (!pdata || (!use_of && !pdata->num_chipselect))
return -ENODEV;
#endif
if (use_of && !SPI_N_CHIPSEL)
num_devices = 1;
else
num_devices = SPI_N_CHIPSEL;
status = spi_gpio_request(pdata, dev_name(&pdev->dev), &master_flags);
if (status < 0)
return status;
master = spi_alloc_master(&pdev->dev, sizeof(*spi_gpio) +
(sizeof(unsigned long) * num_devices));
if (!master) {
status = -ENOMEM;
goto gpio_free;
}
spi_gpio = spi_master_get_devdata(master);
platform_set_drvdata(pdev, spi_gpio);
spi_gpio->pdev = pdev;
if (pdata)
spi_gpio->pdata = *pdata;
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(1, 32);
master->flags = master_flags;
master->bus_num = pdev->id;
master->num_chipselect = num_devices;
master->setup = spi_gpio_setup;
master->cleanup = spi_gpio_cleanup;
#ifdef CONFIG_OF
master->dev.of_node = pdev->dev.of_node;
if (use_of) {
int i;
struct device_node *np = pdev->dev.of_node;
if (!SPI_N_CHIPSEL)
spi_gpio->cs_gpios[0] = SPI_GPIO_NO_CHIPSELECT;
else
for (i = 0; i < SPI_N_CHIPSEL; i++) {
status = of_get_named_gpio(np, "cs-gpios", i);
if (status < 0) {
dev_err(&pdev->dev,
"invalid cs-gpios property\n");
goto gpio_free;
}
spi_gpio->cs_gpios[i] = status;
}
}
#endif
spi_gpio->bitbang.master = master;
spi_gpio->bitbang.chipselect = spi_gpio_chipselect;
if ((master_flags & (SPI_MASTER_NO_TX | SPI_MASTER_NO_RX)) == 0) {
spi_gpio->bitbang.txrx_word[SPI_MODE_0] = spi_gpio_txrx_word_mode0;
spi_gpio->bitbang.txrx_word[SPI_MODE_1] = spi_gpio_txrx_word_mode1;
spi_gpio->bitbang.txrx_word[SPI_MODE_2] = spi_gpio_txrx_word_mode2;
spi_gpio->bitbang.txrx_word[SPI_MODE_3] = spi_gpio_txrx_word_mode3;
} else {
spi_gpio->bitbang.txrx_word[SPI_MODE_0] = spi_gpio_spec_txrx_word_mode0;
spi_gpio->bitbang.txrx_word[SPI_MODE_1] = spi_gpio_spec_txrx_word_mode1;
spi_gpio->bitbang.txrx_word[SPI_MODE_2] = spi_gpio_spec_txrx_word_mode2;
spi_gpio->bitbang.txrx_word[SPI_MODE_3] = spi_gpio_spec_txrx_word_mode3;
}
spi_gpio->bitbang.setup_transfer = spi_bitbang_setup_transfer;
spi_gpio->bitbang.flags = SPI_CS_HIGH;
status = spi_bitbang_start(&spi_gpio->bitbang);
if (status < 0) {
gpio_free:
if (SPI_MISO_GPIO != SPI_GPIO_NO_MISO)
gpio_free(SPI_MISO_GPIO);
if (SPI_MOSI_GPIO != SPI_GPIO_NO_MOSI)
gpio_free(SPI_MOSI_GPIO);
gpio_free(SPI_SCK_GPIO);
spi_master_put(master);
}
return status;
}
static int spi_gpio_remove(struct platform_device *pdev)
{
struct spi_gpio *spi_gpio;
struct spi_gpio_platform_data *pdata;
spi_gpio = platform_get_drvdata(pdev);
pdata = dev_get_platdata(&pdev->dev);
spi_bitbang_stop(&spi_gpio->bitbang);
if (SPI_MISO_GPIO != SPI_GPIO_NO_MISO)
gpio_free(SPI_MISO_GPIO);
if (SPI_MOSI_GPIO != SPI_GPIO_NO_MOSI)
gpio_free(SPI_MOSI_GPIO);
gpio_free(SPI_SCK_GPIO);
spi_master_put(spi_gpio->bitbang.master);
return 0;
}
