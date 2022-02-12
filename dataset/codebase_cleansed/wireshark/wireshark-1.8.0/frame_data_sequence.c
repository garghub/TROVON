frame_data_sequence *
new_frame_data_sequence(void)
{
frame_data_sequence *fds;
fds = g_malloc(sizeof *fds);
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
leaf = g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
node = &leaf[0];
fds->ptree_root = leaf;
} else if (fds->count < NODES_PER_LEVEL) {
leaf = fds->ptree_root;
node = &leaf[fds->count];
} else if (fds->count == NODES_PER_LEVEL) {
level1 = g_malloc((sizeof *level1)*NODES_PER_LEVEL);
memset(level1, 0, (sizeof *level1)*NODES_PER_LEVEL);
level1[0] = fds->ptree_root;
leaf = g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
level1[1] = leaf;
node = &leaf[0];
fds->ptree_root = level1;
} else if (fds->count < NODES_PER_LEVEL*NODES_PER_LEVEL) {
level1 = fds->ptree_root;
leaf = level1[fds->count >> LOG2_NODES_PER_LEVEL];
if (leaf == NULL) {
leaf = g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
level1[fds->count >> LOG2_NODES_PER_LEVEL] = leaf;
}
node = &leaf[LEAF_INDEX(fds->count)];
} else if (fds->count == NODES_PER_LEVEL*NODES_PER_LEVEL) {
level2 = g_malloc((sizeof *level2)*NODES_PER_LEVEL);
memset(level2, 0, (sizeof *level2)*NODES_PER_LEVEL);
level2[0] = fds->ptree_root;
level1 = g_malloc((sizeof *level1)*NODES_PER_LEVEL);
memset(level1, 0, (sizeof *level1)*NODES_PER_LEVEL);
level2[1] = level1;
leaf = g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
level1[0] = leaf;
node = &leaf[0];
fds->ptree_root = level2;
} else if (fds->count < NODES_PER_LEVEL*NODES_PER_LEVEL*NODES_PER_LEVEL) {
level2 = fds->ptree_root;
level1 = level2[fds->count >> (LOG2_NODES_PER_LEVEL+LOG2_NODES_PER_LEVEL)];
if (level1 == NULL) {
level1 = g_malloc((sizeof *level1)*NODES_PER_LEVEL);
memset(level1, 0, (sizeof *level1)*NODES_PER_LEVEL);
level2[fds->count >> (LOG2_NODES_PER_LEVEL+LOG2_NODES_PER_LEVEL)] = level1;
}
leaf = level1[LEVEL_1_INDEX(fds->count)];
if (leaf == NULL) {
leaf = g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
level1[LEVEL_1_INDEX(fds->count)] = leaf;
}
node = &leaf[LEAF_INDEX(fds->count)];
} else if (fds->count == NODES_PER_LEVEL*NODES_PER_LEVEL*NODES_PER_LEVEL) {
level3 = g_malloc((sizeof *level3)*NODES_PER_LEVEL);
memset(level3, 0, (sizeof *level3)*NODES_PER_LEVEL);
level3[0] = fds->ptree_root;
level2 = g_malloc((sizeof *level2)*NODES_PER_LEVEL);
memset(level2, 0, (sizeof *level2)*NODES_PER_LEVEL);
level3[1] = level2;
level1 = g_malloc((sizeof *level1)*NODES_PER_LEVEL);
memset(level1, 0, (sizeof *level1)*NODES_PER_LEVEL);
level2[0] = level1;
leaf = g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
level1[0] = leaf;
node = &leaf[0];
fds->ptree_root = level3;
} else {
level3 = fds->ptree_root;
level2 = level3[LEVEL_3_INDEX(fds->count)];
if (level2 == NULL) {
level2 = g_malloc((sizeof *level2)*NODES_PER_LEVEL);
memset(level2, 0, (sizeof *level2)*NODES_PER_LEVEL);
level3[LEVEL_3_INDEX(fds->count)] = level2;
}
level1 = level2[LEVEL_2_INDEX(fds->count)];
if (level1 == NULL) {
level1 = g_malloc((sizeof *level1)*NODES_PER_LEVEL);
memset(level1, 0, (sizeof *level1)*NODES_PER_LEVEL);
level2[LEVEL_2_INDEX(fds->count)] = level1;
}
leaf = level1[LEVEL_1_INDEX(fds->count)];
if (leaf == NULL) {
leaf = g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
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
leaf = fds->ptree_root;
return &leaf[num];
}
if (fds->count <= NODES_PER_LEVEL*NODES_PER_LEVEL) {
level1 = fds->ptree_root;
leaf = level1[num >> LOG2_NODES_PER_LEVEL];
return &leaf[LEAF_INDEX(num)];
}
if (fds->count <= NODES_PER_LEVEL*NODES_PER_LEVEL*NODES_PER_LEVEL) {
level2 = fds->ptree_root;
level1 = level2[num >> (LOG2_NODES_PER_LEVEL+LOG2_NODES_PER_LEVEL)];
leaf = level1[(num >> LOG2_NODES_PER_LEVEL) & (NODES_PER_LEVEL - 1)];
return &leaf[LEAF_INDEX(num)];
}
level3 = fds->ptree_root;
level2 = level3[num >> (LOG2_NODES_PER_LEVEL+LOG2_NODES_PER_LEVEL+LOG2_NODES_PER_LEVEL)];
level1 = level2[(num >> (LOG2_NODES_PER_LEVEL+LOG2_NODES_PER_LEVEL)) & (NODES_PER_LEVEL - 1)];
leaf = level1[(num >> LOG2_NODES_PER_LEVEL) & (NODES_PER_LEVEL - 1)];
return &leaf[LEAF_INDEX(num)];
}
void
free_frame_data_sequence(frame_data_sequence *fds)
{
frame_data **level1;
frame_data ***level2;
frame_data ****level3;
guint i, j, k;
if (fds->count == 0) {
return;
}
if (fds->count <= NODES_PER_LEVEL) {
g_free(fds->ptree_root);
} else if (fds->count <= NODES_PER_LEVEL*NODES_PER_LEVEL) {
level1 = fds->ptree_root;
for (i = 0; i < NODES_PER_LEVEL && level1[i] != NULL; i++)
g_free(level1[i]);
g_free(level1);
} else if (fds->count <= NODES_PER_LEVEL*NODES_PER_LEVEL*NODES_PER_LEVEL) {
level2 = fds->ptree_root;
for (i = 0; i < NODES_PER_LEVEL && level2[i] != NULL; i++) {
level1 = level2[i];
for (j = 0; j < NODES_PER_LEVEL && level1[i] != NULL; j++)
g_free(level1[j]);
g_free(level1);
}
g_free(level2);
return;
} else {
level3 = fds->ptree_root;
for (i = 0; i < NODES_PER_LEVEL && level3[i] != NULL; i++) {
level2 = level3[i];
for (j = 0; j < NODES_PER_LEVEL && level2[i] != NULL; j++) {
level1 = level2[j];
for (k = 0; k < NODES_PER_LEVEL && level1[k] != NULL; k++)
g_free(level1[k]);
}
g_free(level2);
}
g_free(level3);
}
g_free(fds);
}
