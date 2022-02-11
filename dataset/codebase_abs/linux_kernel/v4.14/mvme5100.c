static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = F_3 () ;
if ( V_5 )
F_4 ( V_5 ) ;
V_4 -> V_6 ( & V_2 -> V_7 ) ;
}
static void T_1 F_5 ( void )
{
struct V_8 * V_8 ;
struct V_9 * V_10 ;
struct V_9 * V_11 = NULL ;
unsigned int V_12 ;
unsigned long V_13 = 0 ;
const T_2 * V_14 = NULL ;
V_10 = F_6 ( NULL , L_1 ) ;
if ( ! V_10 ) {
F_7 ( L_2 ) ;
return;
}
V_8 = F_8 ( V_10 , V_15 , 0 , 16 , 256 , L_3 ) ;
F_9 ( V_8 == NULL ) ;
F_10 ( V_10 ) ;
F_11 ( V_8 , 0 , V_15 + 0x10000 ) ;
F_12 ( V_8 ) ;
V_11 = F_13 ( NULL , NULL , L_4 ) ;
if ( V_11 == NULL ) {
F_14 ( L_5 ) ;
return;
}
V_12 = F_15 ( V_11 , 0 ) ;
if ( ! V_12 ) {
F_14 ( L_6 ) ;
return;
}
V_10 = F_13 ( NULL , L_7 , L_8 ) ;
if ( V_10 ) {
V_14 = F_16 ( V_10 , L_9 , NULL ) ;
if ( V_14 )
V_13 = V_14 [ 0 ] ;
F_10 ( V_10 ) ;
}
if ( V_13 )
F_17 ( L_10 ,
V_13 ) ;
F_18 ( V_11 , V_13 ) ;
F_10 ( V_11 ) ;
F_19 ( V_12 , F_1 ) ;
}
static int T_1 F_20 ( struct V_9 * V_16 )
{
const int * V_17 ;
int V_18 ;
struct V_19 * V_20 ;
unsigned short V_21 ;
F_21 ( L_11 , V_16 ) ;
V_17 = F_16 ( V_16 , L_12 , & V_18 ) ;
V_20 = F_22 ( V_16 ) ;
if ( V_20 == NULL )
return - V_22 ;
V_20 -> V_23 = V_17 ? V_17 [ 0 ] : 0 ;
V_20 -> V_24 = V_17 ? V_17 [ 1 ] : 0xff ;
F_23 ( V_20 , 0xfe000cf8 , 0xfe000cfc , 0 ) ;
F_24 ( V_20 , V_16 , 1 ) ;
F_25 ( V_20 , 0 , 0 , V_25 , & V_21 ) ;
if ( V_21 != V_26 ) {
F_7 ( L_13 ) ;
return 0 ;
}
F_26 ( V_20 , 0 , 0 , V_27 , & V_15 ) ;
if ( V_15 == 0 ) {
F_7 ( L_14 ) ;
return 0 ;
}
F_21 ( L_15 , V_15 ) ;
return 0 ;
}
static void T_1 F_27 ( void )
{
struct V_9 * V_10 ;
if ( V_28 . V_29 )
V_28 . V_29 ( L_16 , 0 ) ;
F_28 (np, L_7 , L_17 )
F_20 ( V_10 ) ;
V_30 = F_29 ( V_31 , 4 ) ;
}
static void F_30 ( struct V_32 * V_33 )
{
F_31 ( V_33 , L_18 ) ;
F_31 ( V_33 , L_19 ) ;
}
static void T_3 F_32 ( char * V_34 )
{
F_33 () ;
F_34 ( F_35 () | V_35 ) ;
F_36 ( ( V_36 * ) V_30 , 0x01 ) ;
while ( 1 )
;
}
static int T_1 F_37 ( void )
{
return F_38 ( L_20 ) ;
}
static int T_1 F_39 ( void )
{
F_40 ( NULL , V_37 , NULL ) ;
return 0 ;
}
