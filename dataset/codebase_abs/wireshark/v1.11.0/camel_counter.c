static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = ( struct V_2 * ) V_1 ;
int V_4 ;
for( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
V_3 -> V_6 [ V_4 ] = 0 ;
}
}
static int F_2 ( void * V_1 ,
T_1 * T_2 V_7 ,
T_3 * T_4 V_7 ,
const void * V_8 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
const struct V_9 * V_10 = (struct V_9 * ) V_8 ;
if ( V_10 -> V_11 != 255 )
V_3 -> V_6 [ V_10 -> V_11 ] ++ ;
return 1 ;
}
static void F_3 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
int V_4 ;
char V_12 [ 256 ] ;
T_5 * V_13 ;
T_6 V_14 ;
V_13 = F_4 ( F_5 ( V_3 -> V_15 ) ) ;
F_6 ( V_13 ) ;
for( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
if( V_3 -> V_6 [ V_4 ] != 0 ) {
F_7 ( V_12 , 256 , L_1 , F_8 ( V_4 , V_16 , L_2 ) ) ;
F_9 ( V_13 , & V_14 ) ;
F_10 ( V_13 , & V_14 ,
0 , V_12 ,
1 , V_3 -> V_6 [ V_4 ] ,
- 1 ) ;
}
}
}
static void F_11 ( T_7 * T_8 V_7 , T_9 V_17 )
{
struct V_2 * V_18 = (struct V_2 * ) V_17 ;
F_12 ( V_18 ) ;
if( V_18 -> V_19 ) {
F_13 ( V_18 -> V_19 ) ;
V_18 -> V_19 = NULL ;
}
F_13 ( V_18 ) ;
}
static void F_14 ( const char * V_20 , void * T_10 V_7 )
{
struct V_2 * V_21 ;
const char * V_19 = NULL ;
T_11 * V_22 ;
T_12 * V_23 ;
T_12 * V_24 ;
if( strncmp ( V_20 , L_3 , 14 ) == 0 ) {
V_19 = V_20 + 14 ;
} else {
V_19 = NULL ;
}
V_21 = (struct V_2 * ) F_15 ( sizeof( struct V_2 ) ) ;
V_21 -> V_19 = F_16 ( V_19 ) ;
F_1 ( V_21 ) ;
V_21 -> T_8 = F_17 ( L_4 ) ;
F_18 ( F_19 ( V_21 -> T_8 ) , TRUE ) ;
F_20 ( F_19 ( V_21 -> T_8 ) , 500 , 300 ) ;
V_21 -> V_25 = F_21 ( V_26 , 3 , FALSE ) ;
F_22 ( F_23 ( V_21 -> V_25 ) , 12 ) ;
F_24 ( V_21 -> T_8 , V_21 -> V_25 , L_5 , V_19 ) ;
V_21 -> V_27 = F_25 ( NULL , NULL ) ;
V_21 -> V_15 = F_26 ( V_21 -> V_27 , V_21 -> V_25 , 2 , V_28 ) ;
V_22 = F_27 ( L_6 , V_21 , V_19 , 0 ,
F_1 ,
F_2 ,
F_3 ) ;
if( V_22 ) {
F_28 ( V_29 , V_30 , L_7 , V_22 -> V_12 ) ;
F_29 ( V_22 , TRUE ) ;
F_13 ( V_21 ) ;
return;
}
V_23 = F_30 ( V_31 , NULL ) ;
F_31 ( F_32 ( V_21 -> V_25 ) , V_23 , FALSE , FALSE , 0 ) ;
V_24 = ( T_12 * ) F_33 ( F_34 ( V_23 ) , V_31 ) ;
F_35 ( V_21 -> T_8 , V_24 , V_32 ) ;
F_36 ( V_21 -> T_8 , L_8 , F_37 ( V_33 ) , NULL ) ;
F_36 ( V_21 -> T_8 , L_9 , F_37 ( F_11 ) , V_21 ) ;
F_38 ( V_21 -> T_8 ) ;
F_39 ( V_21 -> T_8 ) ;
F_40 ( & V_34 ) ;
F_41 ( F_42 ( V_21 -> T_8 ) ) ;
}
void
F_43 ( void )
{
F_44 ( & V_35 , L_10 ,
V_36 ) ;
}
