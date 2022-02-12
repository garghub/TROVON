frame_data_sequence *
new_frame_data_sequence(void)
{
frame_data_sequence *fds;
fds = (frame_data_sequence *)g_malloc(sizeof *fds);
fds->count = 0;
fds->ptree_root = NULL;
return fds;
}
frame_data *
frame_data_sequence_add(frame_data_sequence *fds, frame_data *fdata)
{
frame_data *leaf;
frame_data **level1;
frame_data ***level2;
frame_data ****level3;
frame_data *node;
if (fds->count == 0) {
leaf = (frame_data *)g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
node = &leaf[0];
fds->ptree_root = leaf;
} else if (fds->count < NODES_PER_LEVEL) {
leaf = (frame_data *)fds->ptree_root;
node = &leaf[fds->count];
} else if (fds->count == NODES_PER_LEVEL) {
level1 = (frame_data **)g_malloc0((sizeof *level1)*NODES_PER_LEVEL);
level1[0] = (frame_data *)fds->ptree_root;
leaf = (frame_data *)g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
level1[1] = leaf;
node = &leaf[0];
fds->ptree_root = level1;
} else if (fds->count < NODES_PER_LEVEL*NODES_PER_LEVEL) {
level1 = (frame_data **)fds->ptree_root;
leaf = level1[fds->count >> LOG2_NODES_PER_LEVEL];
if (leaf == NULL) {
leaf = (frame_data *)g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
level1[fds->count >> LOG2_NODES_PER_LEVEL] = leaf;
}
node = &leaf[LEAF_INDEX(fds->count)];
} else if (fds->count == NODES_PER_LEVEL*NODES_PER_LEVEL) {
level2 = (frame_data ***)g_malloc0((sizeof *level2)*NODES_PER_LEVEL);
level2[0] = (frame_data **)fds->ptree_root;
level1 = (frame_data **)g_malloc0((sizeof *level1)*NODES_PER_LEVEL);
level2[1] = level1;
leaf = (frame_data *)g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
level1[0] = leaf;
node = &leaf[0];
fds->ptree_root = level2;
} else if (fds->count < NODES_PER_LEVEL*NODES_PER_LEVEL*NODES_PER_LEVEL) {
level2 = (frame_data ***)fds->ptree_root;
level1 = level2[fds->count >> (LOG2_NODES_PER_LEVEL+LOG2_NODES_PER_LEVEL)];
if (level1 == NULL) {
level1 = (frame_data **)g_malloc0((sizeof *level1)*NODES_PER_LEVEL);
level2[fds->count >> (LOG2_NODES_PER_LEVEL+LOG2_NODES_PER_LEVEL)] = level1;
}
leaf = level1[LEVEL_1_INDEX(fds->count)];
if (leaf == NULL) {
leaf = (frame_data *)g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
level1[LEVEL_1_INDEX(fds->count)] = leaf;
}
node = &leaf[LEAF_INDEX(fds->count)];
} else if (fds->count == NODES_PER_LEVEL*NODES_PER_LEVEL*NODES_PER_LEVEL) {
level3 = (frame_data ****)g_malloc0((sizeof *level3)*NODES_PER_LEVEL);
level3[0] = (frame_data ***)fds->ptree_root;
level2 = (frame_data ***)g_malloc0((sizeof *level2)*NODES_PER_LEVEL);
level3[1] = level2;
level1 = (frame_data **)g_malloc0((sizeof *level1)*NODES_PER_LEVEL);
level2[0] = level1;
leaf = (frame_data *)g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
level1[0] = leaf;
node = &leaf[0];
fds->ptree_root = level3;
} else {
level3 = (frame_data ****)fds->ptree_root;
level2 = level3[LEVEL_3_INDEX(fds->count)];
if (level2 == NULL) {
level2 = (frame_data ***)g_malloc0((sizeof *level2)*NODES_PER_LEVEL);
level3[LEVEL_3_INDEX(fds->count)] = level2;
}
level1 = level2[LEVEL_2_INDEX(fds->count)];
if (level1 == NULL) {
level1 = (frame_data **)g_malloc0((sizeof *level1)*NODES_PER_LEVEL);
level2[LEVEL_2_INDEX(fds->count)] = level1;
}
leaf = level1[LEVEL_1_INDEX(fds->count)];
if (leaf == NULL) {
leaf = (frame_data *)g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
level1[LEVEL_1_INDEX(fds->count)] = leaf;
}
node = &leaf[LEAF_INDEX(fds->count)];
}
*node = *fdata;
fds->count++;
return node;
}
frame_data *
frame_data_sequence_find(frame_data_sequence *fds, guint32 num)
{
frame_data *leaf;
frame_data **level1;
frame_data ***level2;
frame_data ****level3;
if (num == 0) {
return NULL;
}
num--;
if (num >= fds->count) {
return NULL;
}
if (fds->count <= NODES_PER_LEVEL) {
leaf = (frame_data *)fds->ptree_root;
return &leaf[num];
}
if (fds->count <= NODES_PER_LEVEL*NODES_PER_LEVEL) {
level1 = (frame_data **)fds->ptree_root;
leaf = level1[num >> LOG2_NODES_PER_LEVEL];
return &leaf[LEAF_INDEX(num)];
}
if (fds->count <= NODES_PER_LEVEL*NODES_PER_LEVEL*NODES_PER_LEVEL) {
level2 = (frame_data ***)fds->ptree_root;
level1 = level2[num >> (LOG2_NODES_PER_LEVEL+LOG2_NODES_PER_LEVEL)];
leaf = level1[(num >> LOG2_NODES_PER_LEVEL) & (NODES_PER_LEVEL - 1)];
return &leaf[LEAF_INDEX(num)];
}
level3 = (frame_data ****)fds->ptree_root;
level2 = level3[num >> (LOG2_NODES_PER_LEVEL+LOG2_NODES_PER_LEVEL+LOG2_NODES_PER_LEVEL)];
level1 = level2[(num >> (LOG2_NODES_PER_LEVEL+LOG2_NODES_PER_LEVEL)) & (NODES_PER_LEVEL - 1)];
leaf = level1[(num >> LOG2_NODES_PER_LEVEL) & (NODES_PER_LEVEL - 1)];
return &leaf[LEAF_INDEX(num)];
}
static void
free_frame_data_array(void *array, guint count, guint level, gboolean last)
{
guint i, level_count;
if (last) {
level_count = (count >> ((level - 1) * LOG2_NODES_PER_LEVEL)) &
(NODES_PER_LEVEL - 1);
if (count & ((1 << ((level - 1) * LOG2_NODES_PER_LEVEL)) - 1)) {
level_count++;
}
}
else {
level_count = NODES_PER_LEVEL;
}
if (level > 1) {
frame_data **real_array = (frame_data **) array;
for (i=0; i < level_count-1; i++) {
free_frame_data_array(real_array[i], count, level-1, FALSE);
}
free_frame_data_array(real_array[level_count-1], count, level-1, last);
}
else if (level == 1) {
frame_data *real_array = (frame_data *) array;
for (i=0; i < level_count; i++) {
frame_data_destroy(&real_array[i]);
}
}
g_free(array);
}
void
free_frame_data_sequence(frame_data_sequence *fds)
{
guint32 count = fds->count;
guint levels = 0;
while (count) {
levels++;
count >>= LOG2_NODES_PER_LEVEL;
}
if (levels > 0) {
free_frame_data_array(fds->ptree_root, fds->count, levels, TRUE);
}
g_free(fds);
}
void
find_and_mark_frame_depended_upon(gpointer data, gpointer user_data)
{
frame_data *dependent_fd;
guint32 dependent_frame = GPOINTER_TO_UINT(data);
frame_data_sequence *frames = (frame_data_sequence *)user_data;
if (dependent_frame && frames) {
dependent_fd = frame_data_sequence_find(frames, dependent_frame);
dependent_fd->flags.dependent_of_displayed = 1;
}
}
