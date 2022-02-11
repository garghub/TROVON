static struct V_1 * F_1 ( unsigned int V_2 )
{
if ( V_2 >= V_3 ) {
F_2 ( V_4 L_1 ) ;
return NULL ;
}
return & V_5 [ V_2 ] ;
}
static int F_3 ( struct V_6 * V_7 , const void * V_8 )
{
struct V_9 * V_10 , * V_11 ;
unsigned long V_12 ;
if ( ! V_7 -> V_13 )
return 0 ;
F_4 (blk, tmp, &ocm_reg->list, list) {
if ( V_10 -> V_8 == V_8 ) {
V_12 = V_8 - V_7 -> V_13 ;
V_7 -> V_14 += V_10 -> V_15 ;
F_5 ( V_7 -> V_16 , V_12 ) ;
F_6 ( & V_10 -> V_17 ) ;
F_7 ( V_10 ) ;
return 1 ;
}
}
return 0 ;
}
static void T_1 F_8 ( int V_18 , struct V_19 * V_20 )
{
struct V_1 * V_21 ;
const unsigned int * V_22 ;
const unsigned int * V_23 ;
int V_24 ;
struct V_25 V_26 ;
int V_27 ;
V_21 = F_1 ( V_18 ) ;
V_22 = F_9 ( V_20 , L_2 , & V_24 ) ;
if ( ! V_22 ) {
F_2 ( V_4 L_3 ) ;
return;
}
V_21 -> V_2 = * V_22 ;
if ( F_10 ( V_20 ) )
V_21 -> V_28 = V_29 ;
V_23 = F_9 ( V_20 , L_4 , & V_24 ) ;
if ( V_23 )
V_21 -> V_23 = * V_23 ;
if ( F_11 ( V_20 , 0 , & V_26 ) ) {
F_2 ( V_4 L_5 ,
V_21 -> V_2 ) ;
return;
}
V_21 -> V_30 = V_26 . V_31 ;
V_21 -> V_32 = ( V_26 . V_33 - V_26 . V_31 + 1 ) ;
F_2 ( V_34 L_6 ,
V_21 -> V_2 , V_21 -> V_32 ,
( V_21 -> V_28 == V_35 ) ? L_7 : L_8 ) ;
if ( V_21 -> V_28 == V_35 )
return;
if ( ! F_12 ( V_21 -> V_30 , V_21 -> V_32 , L_9 ) ) {
F_2 ( V_4 L_10 ,
V_21 -> V_2 ) ;
return;
}
V_21 -> V_36 . V_30 = V_21 -> V_30 ;
V_21 -> V_36 . V_32 = V_21 -> V_32 - V_21 -> V_23 ;
V_21 -> V_36 . V_14 = V_21 -> V_36 . V_32 ;
V_21 -> V_37 . V_30 = V_21 -> V_30 + V_21 -> V_36 . V_32 ;
V_21 -> V_37 . V_32 = V_21 -> V_23 ;
V_21 -> V_37 . V_14 = V_21 -> V_37 . V_32 ;
if ( V_21 -> V_36 . V_32 == 0 )
V_21 -> V_36 . V_30 = 0 ;
if ( V_21 -> V_37 . V_32 == 0 )
V_21 -> V_37 . V_30 = 0 ;
F_2 ( V_34 L_11 ,
V_21 -> V_2 , V_21 -> V_36 . V_32 ) ;
F_2 ( V_34 L_12 ,
V_21 -> V_2 , V_21 -> V_37 . V_32 ) ;
if ( V_21 -> V_36 . V_32 ) {
V_27 = V_38 | V_39 | V_40 ;
V_21 -> V_36 . V_13 = F_13 ( V_21 -> V_36 . V_30 , V_21 -> V_36 . V_32 ,
V_27 ) ;
if ( ! V_21 -> V_36 . V_13 ) {
F_2 ( V_4
L_13 ,
V_21 -> V_2 ) ;
V_21 -> V_36 . V_14 = 0 ;
return;
}
}
if ( V_21 -> V_37 . V_32 ) {
V_27 = V_40 ;
V_21 -> V_37 . V_13 = F_13 ( V_21 -> V_37 . V_30 , V_21 -> V_37 . V_32 ,
V_27 ) ;
if ( ! V_21 -> V_37 . V_13 ) {
F_2 ( V_4
L_14 ,
V_21 -> V_2 ) ;
V_21 -> V_37 . V_14 = 0 ;
return;
}
}
V_21 -> V_41 = 4 ;
if ( V_21 -> V_36 . V_13 ) {
V_21 -> V_36 . V_16 = F_14 ( V_21 -> V_41 ) ;
F_15 ( V_21 -> V_36 . V_16 , 0 , V_21 -> V_36 . V_32 ) ;
}
if ( V_21 -> V_37 . V_13 ) {
V_21 -> V_37 . V_16 = F_14 ( V_21 -> V_41 ) ;
F_15 ( V_21 -> V_37 . V_16 , 0 , V_21 -> V_37 . V_32 ) ;
}
F_16 ( & V_21 -> V_36 . V_17 ) ;
F_16 ( & V_21 -> V_37 . V_17 ) ;
V_21 -> V_42 = 1 ;
return;
}
static int F_17 ( struct V_43 * V_44 , void * V_45 )
{
struct V_9 * V_10 , * V_11 ;
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < V_3 ; V_46 ++ ) {
struct V_1 * V_21 = F_1 ( V_46 ) ;
if ( ! V_21 || ! V_21 -> V_42 )
continue;
F_18 ( V_44 , L_15 , V_21 -> V_2 ) ;
F_18 ( V_44 , L_16 , V_21 -> V_30 ) ;
F_18 ( V_44 , L_17 , V_21 -> V_32 ) ;
F_18 ( V_44 , L_18 , V_21 -> V_36 . V_32 ) ;
F_18 ( V_44 , L_19 , V_21 -> V_37 . V_32 ) ;
F_18 ( V_44 , L_20 ) ;
F_18 ( V_44 , L_21 , V_21 -> V_36 . V_30 ) ;
F_18 ( V_44 , L_22 , V_21 -> V_36 . V_13 ) ;
F_18 ( V_44 , L_23 , V_21 -> V_36 . V_32 ) ;
F_18 ( V_44 , L_24 , V_21 -> V_36 . V_14 ) ;
F_4 (blk, tmp, &ocm->nc.list, list) {
F_18 ( V_44 , L_25 ,
V_10 -> V_15 , V_10 -> V_47 ) ;
}
F_18 ( V_44 , L_20 ) ;
F_18 ( V_44 , L_26 , V_21 -> V_37 . V_30 ) ;
F_18 ( V_44 , L_27 , V_21 -> V_37 . V_13 ) ;
F_18 ( V_44 , L_28 , V_21 -> V_37 . V_32 ) ;
F_18 ( V_44 , L_29 , V_21 -> V_37 . V_14 ) ;
F_4 (blk, tmp, &ocm->c.list, list) {
F_18 ( V_44 , L_30 ,
V_10 -> V_15 , V_10 -> V_47 ) ;
}
F_18 ( V_44 , L_20 ) ;
}
return 0 ;
}
static int F_19 ( struct V_48 * V_48 , struct V_49 * V_49 )
{
return F_20 ( V_49 , F_17 , NULL ) ;
}
static int F_21 ( void )
{
struct V_50 * V_51 ;
V_51 = F_22 ( L_9 , 0 ) ;
if ( ! V_51 ) {
F_2 ( V_52 L_31 ) ;
return - 1 ;
}
if ( F_23 ( L_32 , 0644 , V_51 , NULL , & V_53 ) ) {
F_2 ( V_52 L_33 ) ;
return - 1 ;
}
return 0 ;
}
void * F_24 ( T_2 * V_30 , int V_15 , int V_54 ,
int V_55 , const char * V_47 )
{
void T_3 * V_8 = NULL ;
unsigned long V_12 ;
struct V_1 * V_21 ;
struct V_6 * V_7 ;
struct V_9 * V_56 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_3 ; V_46 ++ ) {
V_21 = F_1 ( V_46 ) ;
if ( ! V_21 || ! V_21 -> V_42 )
continue;
if ( V_55 == V_57 )
V_7 = & V_21 -> V_36 ;
else
V_7 = & V_21 -> V_37 ;
if ( ! V_7 -> V_13 )
continue;
if ( V_54 < V_21 -> V_41 )
V_54 = V_21 -> V_41 ;
V_12 = F_25 ( V_7 -> V_16 , V_15 , V_54 , NULL ) ;
if ( F_26 ( V_12 ) )
continue;
V_56 = F_27 ( sizeof( struct V_9 ) , V_58 ) ;
if ( ! V_56 ) {
F_2 ( V_4 L_34 ) ;
F_5 ( V_7 -> V_16 , V_12 ) ;
break;
}
* V_30 = V_7 -> V_30 + V_12 ;
V_8 = V_7 -> V_13 + V_12 ;
V_15 = F_28 ( V_15 , V_54 ) ;
V_56 -> V_8 = V_8 ;
V_56 -> V_15 = V_15 ;
V_56 -> V_47 = V_47 ;
F_29 ( & V_56 -> V_17 , & V_7 -> V_17 ) ;
V_7 -> V_14 -= V_15 ;
break;
}
return V_8 ;
}
void F_30 ( const void * V_8 )
{
int V_46 ;
if ( ! V_8 )
return;
for ( V_46 = 0 ; V_46 < V_3 ; V_46 ++ ) {
struct V_1 * V_21 = F_1 ( V_46 ) ;
if ( ! V_21 || ! V_21 -> V_42 )
continue;
if ( F_3 ( & V_21 -> V_36 , V_8 ) ||
F_3 ( & V_21 -> V_37 , V_8 ) )
return;
}
}
static int T_1 F_31 ( void )
{
struct V_19 * V_59 ;
int V_18 ;
V_18 = 0 ;
F_32 (np, NULL, L_35 )
V_18 ++ ;
if ( ! V_18 )
return 0 ;
V_5 = F_27 ( ( V_18 * sizeof( struct V_1 ) ) , V_58 ) ;
if ( ! V_5 ) {
F_2 ( V_4 L_36 ) ;
return - V_60 ;
}
V_3 = V_18 ;
V_18 = 0 ;
F_32 (np, NULL, L_35 ) {
F_8 ( V_18 , V_59 ) ;
V_18 ++ ;
}
F_21 () ;
return 0 ;
}
