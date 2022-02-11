static void F_1 ( T_1 * V_1 , T_2 * V_2 ,
T_3 * V_3 , int V_4 )
{
if ( ( V_2 -> V_5 & V_6 )
|| ! ( V_3 -> V_7 -> V_5 & V_8 ) )
F_2 ( V_1 , L_1 ) ;
else
{
int V_9 ;
F_3 ( V_10 ) * V_11 = V_3 -> V_7 -> V_12 ;
V_10 * V_13 ;
F_2 ( V_1 , L_2 ) ;
for ( V_9 = 0 ; V_9 < F_4 ( V_11 ) ; V_9 ++ )
{
V_13 = F_5 ( V_11 , V_9 ) ;
if ( V_9 )
F_2 ( V_1 , L_3 ) ;
F_6 ( V_1 , V_13 ) ;
}
F_2 ( V_1 , L_4 ) ;
}
}
static void F_7 ( char * V_14 , T_4 * V_15 ,
T_2 * V_16 )
{
T_2 * V_17 ;
T_3 * V_3 ;
int V_9 ;
T_1 * V_1 ;
V_1 = F_8 ( V_18 , V_19 ) ;
if ( ! V_16 )
V_16 = V_15 -> V_20 + V_15 -> V_21 ;
else
V_16 ++ ;
F_9 ( V_1 , L_5 , V_14 ) ;
F_9 ( V_1 , L_6 , V_16 - V_15 -> V_20 ) ;
for ( V_17 = V_15 -> V_20 ; V_17 != V_16 ; V_17 ++ )
{
F_9 ( V_1 , L_7 ,
V_17 - V_15 -> V_20 , V_17 -> V_5 ) ;
for ( V_9 = 0 ; V_9 < F_10 ( V_17 -> V_22 ) ; V_9 ++ )
{
V_3 = F_11 ( V_17 -> V_22 , V_9 ) ;
F_12 ( V_1 , V_3 , 2 ) ;
F_1 ( V_1 , V_17 , V_3 , 2 ) ;
F_9 ( V_1 , L_8 , V_3 -> V_7 -> V_5 ) ;
}
if ( V_17 -> V_23 )
F_12 ( V_1 , V_17 -> V_23 , 2 ) ;
}
F_13 ( V_1 ) ;
}
static int F_14 ( T_2 * V_16 ,
const T_5 * V_7 )
{
T_2 * V_24 = V_16 - 1 ;
T_3 * V_3 ;
int V_9 , V_25 = 0 ;
for ( V_9 = 0 ; V_9 < F_10 ( V_24 -> V_22 ) ; V_9 ++ )
{
V_3 = F_11 ( V_24 -> V_22 , V_9 ) ;
if ( F_15 ( V_24 , V_3 , V_7 -> V_26 ) )
{
if ( ! F_16 ( V_16 , V_7 , V_3 , NULL ) )
return 0 ;
V_25 = 1 ;
}
}
if ( ! V_25 && V_24 -> V_23 )
{
if ( ! F_16 ( V_16 , V_7 , V_24 -> V_23 , NULL ) )
return 0 ;
}
return 1 ;
}
static int F_17 ( T_2 * V_16 ,
const T_6 * V_27 )
{
int V_9 ;
T_5 * V_7 ;
for ( V_9 = 0 ; V_9 < F_18 ( V_27 -> V_7 ) ; V_9 ++ )
{
V_7 = F_19 ( V_27 -> V_7 , V_9 ) ;
#if 0
if ((data->flags & POLICY_DATA_FLAG_MAPPED_ANY)
&& !(curr->flags & X509_V_FLAG_INHIBIT_ANY))
continue;
#endif
if ( ! F_14 ( V_16 , V_7 ) )
return 0 ;
}
return 1 ;
}
static int F_20 ( T_2 * V_16 ,
const T_6 * V_27 ,
const V_10 * V_28 ,
T_3 * V_3 ,
T_4 * V_15 )
{
T_5 * V_7 ;
if ( V_28 == NULL )
V_28 = V_3 -> V_7 -> V_26 ;
V_7 = F_21 ( NULL , V_28 , F_22 ( V_3 ) ) ;
if ( V_7 == NULL )
return 0 ;
V_7 -> V_29 = V_27 -> V_23 -> V_29 ;
V_7 -> V_5 |= V_30 ;
if ( ! F_16 ( V_16 , V_7 , V_3 , V_15 ) )
{
F_23 ( V_7 ) ;
return 0 ;
}
return 1 ;
}
static int F_24 ( T_2 * V_16 ,
const T_6 * V_27 ,
T_3 * V_3 ,
T_4 * V_15 )
{
const T_2 * V_24 = V_16 - 1 ;
int V_9 ;
if ( ( V_24 -> V_5 & V_6 )
|| ! ( V_3 -> V_7 -> V_5 & V_31 ) )
{
if ( V_3 -> V_32 )
return 1 ;
if ( ! F_20 ( V_16 , V_27 , NULL , V_3 , V_15 ) )
return 0 ;
}
else
{
F_3 ( V_10 ) * V_33 = V_3 -> V_7 -> V_12 ;
if ( V_3 -> V_32 == F_4 ( V_33 ) )
return 1 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_33 ) ; V_9 ++ )
{
V_10 * V_13 = F_5 ( V_33 , V_9 ) ;
if ( F_25 ( V_16 , V_3 , V_13 ) )
continue;
if ( ! F_20 ( V_16 , V_27 , V_13 , V_3 , V_15 ) )
return 0 ;
}
}
return 1 ;
}
static int F_26 ( T_2 * V_16 ,
const T_6 * V_27 ,
T_4 * V_15 )
{
int V_9 ;
T_3 * V_3 ;
T_2 * V_24 = V_16 - 1 ;
for ( V_9 = 0 ; V_9 < F_10 ( V_24 -> V_22 ) ; V_9 ++ )
{
V_3 = F_11 ( V_24 -> V_22 , V_9 ) ;
if ( ! F_24 ( V_16 , V_27 , V_3 , V_15 ) )
return 0 ;
#if 0
if (node->nchild)
continue;
data = policy_data_new(NULL, node->data->valid_policy,
node_critical(node));
if (data == NULL)
return 0;
data->qualifier_set = cache->anyPolicy->qualifier_set;
data->flags |= POLICY_DATA_FLAG_SHARED_QUALIFIERS;
if (!level_add_node(curr, data, node, tree))
{
policy_data_free(data);
return 0;
}
#endif
}
if ( V_24 -> V_23 )
{
if ( ! F_16 ( V_16 , V_27 -> V_23 ,
V_24 -> V_23 , NULL ) )
return 0 ;
}
return 1 ;
}
static int F_27 ( T_4 * V_15 , T_2 * V_16 )
{
F_3 ( T_3 ) * V_22 ;
T_3 * V_3 ;
int V_9 ;
V_22 = V_16 -> V_22 ;
if ( V_16 -> V_5 & V_6 )
{
for ( V_9 = F_10 ( V_22 ) - 1 ; V_9 >= 0 ; V_9 -- )
{
V_3 = F_11 ( V_22 , V_9 ) ;
if ( V_3 -> V_7 -> V_5 & V_8 )
{
V_3 -> V_34 -> V_32 -- ;
F_28 ( V_3 ) ;
( void ) F_29 ( V_22 , V_9 ) ;
}
}
}
for(; ; ) {
-- V_16 ;
V_22 = V_16 -> V_22 ;
for ( V_9 = F_10 ( V_22 ) - 1 ; V_9 >= 0 ; V_9 -- )
{
V_3 = F_11 ( V_22 , V_9 ) ;
if ( V_3 -> V_32 == 0 )
{
V_3 -> V_34 -> V_32 -- ;
F_28 ( V_3 ) ;
( void ) F_29 ( V_22 , V_9 ) ;
}
}
if ( V_16 -> V_23 && ! V_16 -> V_23 -> V_32 )
{
if ( V_16 -> V_23 -> V_34 )
V_16 -> V_23 -> V_34 -> V_32 -- ;
F_28 ( V_16 -> V_23 ) ;
V_16 -> V_23 = NULL ;
}
if ( V_16 == V_15 -> V_20 )
{
if ( ! V_16 -> V_23 )
return 2 ;
return 1 ;
}
}
return 1 ;
}
static int F_30 ( T_4 * V_15 )
{
int V_35 , V_9 ;
T_2 * V_16 = V_15 -> V_20 + 1 ;
const T_6 * V_27 ;
for( V_9 = 1 ; V_9 < V_15 -> V_21 ; V_9 ++ , V_16 ++ )
{
V_27 = F_31 ( V_16 -> V_36 ) ;
if ( ! F_17 ( V_16 , V_27 ) )
return 0 ;
if ( ! ( V_16 -> V_5 & V_37 )
&& ! F_26 ( V_16 , V_27 , V_15 ) )
return 0 ;
F_7 ( L_9 , V_15 , V_16 ) ;
V_35 = F_27 ( V_15 , V_16 ) ;
if ( V_35 != 1 )
return V_35 ;
}
return 1 ;
}
static void F_32 ( T_3 * V_3 )
{
if ( V_3 -> V_7 && ( V_3 -> V_7 -> V_5 & V_38 ) )
F_28 ( V_3 ) ;
}
void F_33 ( T_4 * V_15 )
{
T_2 * V_16 ;
int V_9 ;
if ( ! V_15 )
return;
F_34 ( V_15 -> V_39 ) ;
F_35 ( V_15 -> V_40 , F_32 ) ;
for( V_9 = 0 , V_16 = V_15 -> V_20 ; V_9 < V_15 -> V_21 ; V_9 ++ , V_16 ++ )
{
if ( V_16 -> V_36 )
F_36 ( V_16 -> V_36 ) ;
if ( V_16 -> V_22 )
F_35 ( V_16 -> V_22 ,
V_41 ) ;
if ( V_16 -> V_23 )
V_41 ( V_16 -> V_23 ) ;
}
if ( V_15 -> V_42 )
F_37 ( V_15 -> V_42 ,
F_23 ) ;
F_28 ( V_15 -> V_20 ) ;
F_28 ( V_15 ) ;
}
