static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
F_2 ( L_1 , V_6 ) ;
V_4 = F_3 ( sizeof( struct V_3 ) , V_7 ) ;
if ( ! V_4 )
return - V_8 ;
F_4 ( & V_4 -> V_9 ) ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
V_4 -> V_12 = 0 ;
F_5 ( V_2 -> V_13 [ 0 ] , V_4 ) ;
F_6 ( & V_2 -> V_13 [ 0 ] -> V_14 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_15 ; ++ V_5 ) {
int V_16 ;
V_2 -> V_13 [ V_5 ] -> V_17 -> V_18 = V_2 -> V_18 ;
V_16 = F_7 ( V_2 -> V_13 [ V_5 ] -> V_17 ,
V_7 ) ;
if ( V_16 )
F_8 ( & V_2 -> V_18 -> V_18 ,
L_2 ) ;
F_2 ( L_3 , V_6 ) ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_5 ;
F_2 ( L_1 , V_6 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_15 ; ++ V_5 )
F_10 ( V_2 -> V_13 [ V_5 ] -> V_17 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_5 ;
F_2 ( L_1 , V_6 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_15 ; ++ V_5 ) {
F_12 ( F_13 ( V_2 -> V_13 [ V_5 ] ) ) ;
}
}
static int F_14 ( struct V_19 * V_20 ,
struct V_21 * V_13 )
{
struct V_3 * V_4 ;
unsigned long V_22 ;
int V_16 = 0 ;
F_2 ( L_4 , V_6 , V_13 -> V_23 ) ;
F_2 ( L_5 , V_6 ) ;
F_15 ( V_13 -> V_2 -> V_18 , V_13 -> V_24 -> V_25 ) ;
V_4 = F_13 ( V_13 ) ;
F_16 ( & V_4 -> V_9 , V_22 ) ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
V_4 -> V_12 = 0 ;
F_17 ( & V_4 -> V_9 , V_22 ) ;
return V_16 ;
}
static void F_18 ( struct V_21 * V_13 )
{
F_2 ( L_4 , V_6 , V_13 -> V_23 ) ;
if ( V_13 -> V_2 -> V_18 ) {
F_10 ( V_13 -> V_24 ) ;
F_10 ( V_13 -> V_26 ) ;
}
}
static int F_19 ( struct V_19 * V_20 ,
struct V_21 * V_13 , const unsigned char * V_27 , int V_28 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = F_13 ( V_13 ) ;
unsigned long V_22 ;
int V_16 ;
int V_29 ;
F_2 ( L_4 , V_6 , V_13 -> V_23 ) ;
if ( V_28 == 0 ) {
F_2 ( L_6 , V_6 ) ;
return 0 ;
}
F_20 ( & V_13 -> V_9 ) ;
if ( V_13 -> V_30 ) {
F_21 ( & V_13 -> V_9 ) ;
F_2 ( L_7 , V_6 ) ;
return 0 ;
}
V_13 -> V_30 = 1 ;
F_21 ( & V_13 -> V_9 ) ;
F_16 ( & V_4 -> V_9 , V_22 ) ;
if ( V_28 + V_4 -> V_11 > sizeof( V_4 -> V_31 ) ) {
V_4 -> V_11 = 0 ;
V_13 -> V_30 = 0 ;
F_17 ( & V_4 -> V_9 , V_22 ) ;
return 0 ;
}
memcpy ( V_4 -> V_31 + V_4 -> V_11 , V_27 , V_28 ) ;
F_22 ( V_32 , & V_13 -> V_18 , V_6 , V_28 ,
V_4 -> V_31 + V_4 -> V_11 ) ;
V_4 -> V_11 += V_28 ;
if ( V_4 -> V_11 >= 3 ) {
V_29 = ( ( int ) V_4 -> V_31 [ 2 ] << 8 ) + V_4 -> V_31 [ 1 ] + 3 ;
F_2 ( L_8 , V_6 , V_29 ) ;
} else
V_29 = sizeof( V_4 -> V_31 ) ;
if ( V_4 -> V_11 >= V_29 ) {
int V_33 ;
F_2 ( L_9 , V_6 ) ;
V_33 = ( V_29 > V_13 -> V_34 ) ?
V_13 -> V_34 : V_29 ;
memcpy ( V_13 -> V_24 -> V_35 , V_4 -> V_31 , V_33 ) ;
V_4 -> V_12 = V_33 ;
F_23 ( V_13 -> V_24 , V_2 -> V_18 ,
F_24 ( V_2 -> V_18 , V_13 -> V_36 ) ,
V_13 -> V_24 -> V_35 , V_33 ,
( ( V_2 -> type -> V_37 ) ?
V_2 -> type -> V_37 :
V_38 ) ,
V_13 ) ;
V_16 = F_7 ( V_13 -> V_24 , V_39 ) ;
if ( V_16 ) {
F_8 ( & V_13 -> V_18 ,
L_10 ,
V_6 , V_16 ) ;
V_4 -> V_11 = 0 ;
V_4 -> V_12 = 0 ;
F_17 ( & V_4 -> V_9 , V_22 ) ;
V_13 -> V_30 = 0 ;
return 0 ;
}
F_2 ( L_11 , V_6 , V_4 -> V_12 ) ;
F_2 ( L_12 , V_6 , V_4 -> V_11 ) ;
if ( V_4 -> V_12 >= V_4 -> V_11 ) {
F_2 ( L_13 , V_6 ) ;
memset ( V_4 -> V_31 , 0 , sizeof( V_4 -> V_31 ) ) ;
V_4 -> V_11 = 0 ;
V_4 -> V_12 = 0 ;
}
}
F_17 ( & V_4 -> V_9 , V_22 ) ;
return V_28 ;
}
static int F_25 ( struct V_19 * V_20 )
{
return V_40 ;
}
static void F_26 ( struct V_41 * V_41 )
{
struct V_21 * V_13 = V_41 -> V_42 ;
struct V_3 * V_4 = F_13 ( V_13 ) ;
unsigned char * V_43 = V_41 -> V_35 ;
int V_44 = V_41 -> V_44 ;
int V_16 ;
F_2 ( L_4 , V_6 , V_13 -> V_23 ) ;
if ( V_44 )
return;
F_22 ( V_32 , & V_13 -> V_18 , V_6 ,
V_41 -> V_45 , V_43 ) ;
if ( V_41 -> V_45 == 4 && V_43 [ 0 ] == 0x01 ) {
short V_46 ;
unsigned short V_47 = ( ( unsigned short ) V_43 [ 3 ] << 8 ) + V_43 [ 2 ] + 3 ;
F_27 ( & V_4 -> V_9 ) ;
V_46 = V_4 -> V_10 ;
if ( V_46 + V_47 < V_46 ) {
F_2 ( L_14 ) ;
F_28 ( & V_4 -> V_9 ) ;
goto V_48;
}
V_4 -> V_10 += V_47 ;
F_2 ( L_15 , V_6 , V_4 -> V_10 ) ;
F_28 ( & V_4 -> V_9 ) ;
if ( ! V_46 ) {
V_13 -> V_26 -> V_18 = V_13 -> V_2 -> V_18 ;
V_16 = F_7 ( V_13 -> V_26 , V_39 ) ;
if ( V_16 )
F_8 ( & V_13 -> V_18 , L_16
L_17 ,
V_6 , V_16 ) ;
F_2 ( L_18 , V_6 ) ;
}
}
V_48:
V_13 -> V_17 -> V_18 = V_13 -> V_2 -> V_18 ;
V_16 = F_7 ( V_13 -> V_17 , V_39 ) ;
if ( V_16 )
F_8 ( & V_13 -> V_18 , L_2 ) ;
F_2 ( L_3 , V_6 ) ;
}
static void F_29 ( struct V_41 * V_41 )
{
struct V_21 * V_13 = V_41 -> V_42 ;
struct V_3 * V_4 = F_13 ( V_13 ) ;
struct V_19 * V_20 ;
unsigned char * V_43 = V_41 -> V_35 ;
short V_49 ;
int V_16 ;
int V_44 = V_41 -> V_44 ;
F_2 ( L_4 , V_6 , V_13 -> V_23 ) ;
F_22 ( V_32 , & V_13 -> V_18 , V_6 ,
V_41 -> V_45 , V_43 ) ;
if ( V_44 ) {
F_2 ( L_19 ,
V_6 , V_44 ) ;
return;
}
V_20 = F_30 ( & V_13 -> V_13 ) ;
if ( ! V_20 ) {
F_2 ( L_20 , V_6 ) ;
return;
}
if ( V_41 -> V_45 ) {
F_31 ( V_20 , V_43 , V_41 -> V_45 ) ;
F_32 ( V_20 ) ;
}
F_33 ( V_20 ) ;
F_27 ( & V_4 -> V_9 ) ;
V_4 -> V_10 -= V_41 -> V_45 ;
if ( V_4 -> V_10 < 0 )
V_4 -> V_10 = 0 ;
V_49 = V_4 -> V_10 ;
F_28 ( & V_4 -> V_9 ) ;
F_2 ( L_15 , V_6 , V_49 ) ;
if ( V_49 ) {
V_13 -> V_26 -> V_18 = V_13 -> V_2 -> V_18 ;
V_16 = F_7 ( V_13 -> V_26 , V_39 ) ;
if ( V_16 )
F_8 ( & V_13 -> V_18 , L_21
L_22 , V_6 , V_16 ) ;
F_2 ( L_18 , V_6 ) ;
}
}
static void V_38 ( struct V_41 * V_41 )
{
struct V_21 * V_13 = V_41 -> V_42 ;
struct V_3 * V_4 = F_13 ( V_13 ) ;
int V_44 = V_41 -> V_44 ;
F_2 ( L_4 , V_6 , V_13 -> V_23 ) ;
V_13 -> V_30 = 0 ;
if ( V_44 ) {
F_2 ( L_23 ,
V_6 , V_44 ) ;
return;
}
F_27 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_11 ) {
int V_33 , V_50 , V_16 ;
F_2 ( L_24 , V_6 ) ;
V_33 = ( ( V_4 -> V_11 - V_4 -> V_12 ) > V_13 -> V_34 ) ?
V_13 -> V_34 : ( V_4 -> V_11 - V_4 -> V_12 ) ;
memcpy ( V_13 -> V_24 -> V_35 ,
V_4 -> V_31 + V_4 -> V_12 , V_33 ) ;
V_4 -> V_12 += V_33 ;
F_23 ( V_13 -> V_24 , V_13 -> V_2 -> V_18 ,
F_24 ( V_13 -> V_2 -> V_18 , V_13 -> V_36 ) ,
V_13 -> V_24 -> V_35 , V_33 ,
( ( V_13 -> V_2 -> type -> V_37 ) ?
V_13 -> V_2 -> type -> V_37 :
V_38 ) ,
V_13 ) ;
V_16 = F_7 ( V_13 -> V_24 , V_39 ) ;
if ( V_16 ) {
F_8 ( & V_13 -> V_18 ,
L_25 ,
V_6 , V_16 ) ;
V_4 -> V_11 = 0 ;
V_4 -> V_12 = 0 ;
goto exit;
}
F_2 ( L_11 , V_6 , V_4 -> V_12 ) ;
F_2 ( L_12 , V_6 , V_4 -> V_11 ) ;
V_50 = ( ( int ) V_4 -> V_31 [ 2 ] << 8 ) + V_4 -> V_31 [ 1 ] + 3 ;
if ( V_4 -> V_12 >= V_4 -> V_11 ||
V_4 -> V_12 >= V_50 ) {
F_2 ( L_13 , V_6 ) ;
memset ( V_4 -> V_31 , 0 , sizeof( V_4 -> V_31 ) ) ;
V_4 -> V_11 = 0 ;
V_4 -> V_12 = 0 ;
}
}
exit:
F_28 ( & V_4 -> V_9 ) ;
F_34 ( V_13 ) ;
}
static int T_1 F_35 ( void )
{
int V_51 ;
V_51 = F_36 ( & V_52 ) ;
if ( V_51 )
goto V_53;
V_51 = F_37 ( & V_54 ) ;
if ( V_51 )
goto V_55;
F_38 (KERN_INFO KBUILD_MODNAME L_26 DRIVER_VERSION L_27
DRIVER_AUTHOR L_28 ) ;
F_38 (KERN_INFO KBUILD_MODNAME L_26 DRIVER_DESC L_28 ) ;
return 0 ;
V_55:
F_39 ( & V_52 ) ;
V_53:
return V_51 ;
}
static void T_2 F_40 ( void )
{
F_41 ( & V_54 ) ;
F_39 ( & V_52 ) ;
}
