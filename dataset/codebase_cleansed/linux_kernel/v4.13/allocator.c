static void uwb_rsv_fill_column_alloc(struct uwb_rsv_alloc_info *ai)
{
int col, mas, safe_mas, unsafe_mas;
unsigned char *bm = ai->bm;
struct uwb_rsv_col_info *ci = ai->ci;
unsigned char c;
for (col = ci->csi.start_col; col < UWB_NUM_ZONES; col += ci->csi.interval) {
safe_mas = ci->csi.safe_mas_per_col;
unsafe_mas = ci->csi.unsafe_mas_per_col;
for (mas = 0; mas < UWB_MAS_PER_ZONE; mas++ ) {
if (bm[col * UWB_MAS_PER_ZONE + mas] == 0) {
if (safe_mas > 0) {
safe_mas--;
c = UWB_RSV_MAS_SAFE;
} else if (unsafe_mas > 0) {
unsafe_mas--;
c = UWB_RSV_MAS_UNSAFE;
} else {
break;
}
bm[col * UWB_MAS_PER_ZONE + mas] = c;
}
}
}
}
static void uwb_rsv_fill_row_alloc(struct uwb_rsv_alloc_info *ai)
{
int mas, col, rows;
unsigned char *bm = ai->bm;
struct uwb_rsv_row_info *ri = &ai->ri;
unsigned char c;
rows = 1;
c = UWB_RSV_MAS_SAFE;
for (mas = UWB_MAS_PER_ZONE - 1; mas >= 0; mas--) {
if (ri->avail[mas] == 1) {
if (rows > ri->used_rows) {
break;
} else if (rows > 7) {
c = UWB_RSV_MAS_UNSAFE;
}
for (col = 0; col < UWB_NUM_ZONES; col++) {
if (bm[col * UWB_NUM_ZONES + mas] != UWB_RSV_MAS_NOT_AVAIL) {
bm[col * UWB_NUM_ZONES + mas] = c;
if(c == UWB_RSV_MAS_SAFE)
ai->safe_allocated_mases++;
else
ai->unsafe_allocated_mases++;
}
}
rows++;
}
}
ai->total_allocated_mases = ai->safe_allocated_mases + ai->unsafe_allocated_mases;
}
static int uwb_rsv_find_best_column_set(struct uwb_rsv_alloc_info *ai, int interval,
int num_safe_mas, int num_unsafe_mas)
{
struct uwb_rsv_col_info *ci = ai->ci;
struct uwb_rsv_col_set_info *csi = &ci->csi;
struct uwb_rsv_col_set_info tmp_csi;
int deep, set, col, start_col_deep, col_start_set;
int start_col, max_mas_in_set, lowest_max_mas_in_deep;
int n_mas;
int found = UWB_RSV_ALLOC_NOT_FOUND;
tmp_csi.start_col = 0;
start_col_deep = interval;
n_mas = num_unsafe_mas + num_safe_mas;
for (deep = 0; ((interval >> deep) & 0x1) == 0; deep++) {
start_col_deep /= 2;
col_start_set = 0;
lowest_max_mas_in_deep = UWB_MAS_PER_ZONE;
for (set = 1; set <= (1 << deep); set++) {
max_mas_in_set = 0;
start_col = start_col_deep + col_start_set;
for (col = start_col; col < UWB_NUM_ZONES; col += interval) {
if (ci[col].max_avail_safe >= num_safe_mas &&
ci[col].max_avail_unsafe >= n_mas) {
if (ci[col].highest_mas[n_mas] > max_mas_in_set)
max_mas_in_set = ci[col].highest_mas[n_mas];
} else {
max_mas_in_set = 0;
break;
}
}
if ((lowest_max_mas_in_deep > max_mas_in_set) && max_mas_in_set) {
lowest_max_mas_in_deep = max_mas_in_set;
tmp_csi.start_col = start_col;
}
col_start_set += (interval >> deep);
}
if (lowest_max_mas_in_deep < 8) {
csi->start_col = tmp_csi.start_col;
found = UWB_RSV_ALLOC_FOUND;
break;
} else if ((lowest_max_mas_in_deep > 8) &&
(lowest_max_mas_in_deep != UWB_MAS_PER_ZONE) &&
(found == UWB_RSV_ALLOC_NOT_FOUND)) {
csi->start_col = tmp_csi.start_col;
found = UWB_RSV_ALLOC_FOUND;
}
}
if (found == UWB_RSV_ALLOC_FOUND) {
csi->interval = interval;
csi->safe_mas_per_col = num_safe_mas;
csi->unsafe_mas_per_col = num_unsafe_mas;
ai->safe_allocated_mases = (UWB_NUM_ZONES / interval) * num_safe_mas;
ai->unsafe_allocated_mases = (UWB_NUM_ZONES / interval) * num_unsafe_mas;
ai->total_allocated_mases = ai->safe_allocated_mases + ai->unsafe_allocated_mases;
ai->interval = interval;
}
return found;
}
static void get_row_descriptors(struct uwb_rsv_alloc_info *ai)
{
unsigned char *bm = ai->bm;
struct uwb_rsv_row_info *ri = &ai->ri;
int col, mas;
ri->free_rows = 16;
for (mas = 0; mas < UWB_MAS_PER_ZONE; mas ++) {
ri->avail[mas] = 1;
for (col = 1; col < UWB_NUM_ZONES; col++) {
if (bm[col * UWB_NUM_ZONES + mas] == UWB_RSV_MAS_NOT_AVAIL) {
ri->free_rows--;
ri->avail[mas]=0;
break;
}
}
}
}
static void uwb_rsv_fill_column_info(unsigned char *bm, int column, struct uwb_rsv_col_info *rci)
{
int mas;
int block_count = 0, start_block = 0;
int previous_avail = 0;
int available = 0;
int safe_mas_in_row[UWB_MAS_PER_ZONE] = {
8, 7, 6, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 2, 1,
};
rci->max_avail_safe = 0;
for (mas = 0; mas < UWB_MAS_PER_ZONE; mas ++) {
if (!bm[column * UWB_NUM_ZONES + mas]) {
available++;
rci->max_avail_unsafe = available;
rci->highest_mas[available] = mas;
if (previous_avail) {
block_count++;
if ((block_count > safe_mas_in_row[start_block]) &&
(!rci->max_avail_safe))
rci->max_avail_safe = available - 1;
} else {
previous_avail = 1;
start_block = mas;
block_count = 1;
}
} else {
previous_avail = 0;
}
}
if (!rci->max_avail_safe)
rci->max_avail_safe = rci->max_avail_unsafe;
}
static void get_column_descriptors(struct uwb_rsv_alloc_info *ai)
{
unsigned char *bm = ai->bm;
struct uwb_rsv_col_info *ci = ai->ci;
int col;
for (col = 1; col < UWB_NUM_ZONES; col++) {
uwb_rsv_fill_column_info(bm, col, &ci[col]);
}
}
static int uwb_rsv_find_best_row_alloc(struct uwb_rsv_alloc_info *ai)
{
int n_rows;
int max_rows = ai->max_mas / UWB_USABLE_MAS_PER_ROW;
int min_rows = ai->min_mas / UWB_USABLE_MAS_PER_ROW;
if (ai->min_mas % UWB_USABLE_MAS_PER_ROW)
min_rows++;
for (n_rows = max_rows; n_rows >= min_rows; n_rows--) {
if (n_rows <= ai->ri.free_rows) {
ai->ri.used_rows = n_rows;
ai->interval = 1;
uwb_rsv_fill_row_alloc(ai);
return UWB_RSV_ALLOC_FOUND;
}
}
return UWB_RSV_ALLOC_NOT_FOUND;
}
static int uwb_rsv_find_best_col_alloc(struct uwb_rsv_alloc_info *ai, int interval)
{
int n_safe, n_unsafe, n_mas;
int n_column = UWB_NUM_ZONES / interval;
int max_per_zone = ai->max_mas / n_column;
int min_per_zone = ai->min_mas / n_column;
if (ai->min_mas % n_column)
min_per_zone++;
if (min_per_zone > UWB_MAS_PER_ZONE) {
return UWB_RSV_ALLOC_NOT_FOUND;
}
if (max_per_zone > UWB_MAS_PER_ZONE) {
max_per_zone = UWB_MAS_PER_ZONE;
}
for (n_mas = max_per_zone; n_mas >= min_per_zone; n_mas--) {
if (uwb_rsv_find_best_column_set(ai, interval, 0, n_mas) == UWB_RSV_ALLOC_NOT_FOUND)
continue;
for (n_safe = n_mas; n_safe >= 0; n_safe--) {
n_unsafe = n_mas - n_safe;
if (uwb_rsv_find_best_column_set(ai, interval, n_safe, n_unsafe) == UWB_RSV_ALLOC_FOUND) {
uwb_rsv_fill_column_alloc(ai);
return UWB_RSV_ALLOC_FOUND;
}
}
}
return UWB_RSV_ALLOC_NOT_FOUND;
}
int uwb_rsv_find_best_allocation(struct uwb_rsv *rsv, struct uwb_mas_bm *available,
struct uwb_mas_bm *result)
{
struct uwb_rsv_alloc_info *ai;
int interval;
int bit_index;
ai = kzalloc(sizeof(struct uwb_rsv_alloc_info), GFP_KERNEL);
if (!ai)
return UWB_RSV_ALLOC_NOT_FOUND;
ai->min_mas = rsv->min_mas;
ai->max_mas = rsv->max_mas;
ai->max_interval = rsv->max_interval;
for_each_clear_bit(bit_index, available->bm, UWB_NUM_MAS)
ai->bm[bit_index] = UWB_RSV_MAS_NOT_AVAIL;
if (ai->max_interval == 1) {
get_row_descriptors(ai);
if (uwb_rsv_find_best_row_alloc(ai) == UWB_RSV_ALLOC_FOUND)
goto alloc_found;
else
goto alloc_not_found;
}
get_column_descriptors(ai);
for (interval = 16; interval >= 2; interval>>=1) {
if (interval > ai->max_interval)
continue;
if (uwb_rsv_find_best_col_alloc(ai, interval) == UWB_RSV_ALLOC_FOUND)
goto alloc_found;
}
get_row_descriptors(ai);
if (uwb_rsv_find_best_row_alloc(ai) == UWB_RSV_ALLOC_FOUND)
goto alloc_found;
else
goto alloc_not_found;
alloc_found:
bitmap_zero(result->bm, UWB_NUM_MAS);
bitmap_zero(result->unsafe_bm, UWB_NUM_MAS);
for (bit_index = 0; bit_index < UWB_NUM_MAS; bit_index++) {
if (ai->bm[bit_index] == UWB_RSV_MAS_SAFE)
set_bit(bit_index, result->bm);
else if (ai->bm[bit_index] == UWB_RSV_MAS_UNSAFE)
set_bit(bit_index, result->unsafe_bm);
}
bitmap_or(result->bm, result->bm, result->unsafe_bm, UWB_NUM_MAS);
result->safe = ai->safe_allocated_mases;
result->unsafe = ai->unsafe_allocated_mases;
kfree(ai);
return UWB_RSV_ALLOC_FOUND;
alloc_not_found:
kfree(ai);
return UWB_RSV_ALLOC_NOT_FOUND;
}
