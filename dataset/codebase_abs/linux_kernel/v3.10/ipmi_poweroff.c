static int F_1 ( const char * V_1 , struct V_2 * V_3 )
{
int V_4 = F_2 ( V_1 , V_3 ) ;
if ( V_4 )
return V_4 ;
if ( ( V_5 < 0 ) || ( V_5 == V_6 ) )
return 0 ;
F_3 ( V_6 ) ;
F_4 ( V_5 , NULL ) ;
return 0 ;
}
static void F_5 ( struct V_7 * V_8 )
{
F_6 ( & V_9 ) ;
}
static void F_7 ( struct V_10 * V_8 )
{
F_6 ( & V_9 ) ;
}
static void F_8 ( struct V_10 * V_11 , void * V_12 )
{
struct V_13 * V_14 = V_11 -> V_15 ;
if ( V_14 )
F_9 ( V_14 ) ;
}
static int F_10 ( T_1 V_16 ,
struct V_17 * V_18 ,
struct V_19 * V_20 )
{
int V_4 ;
struct V_13 V_14 ;
F_11 ( & V_14 ) ;
V_4 = F_12 ( V_16 , V_18 , 0 , V_20 , & V_14 ,
& V_21 , & V_22 , 0 ) ;
if ( V_4 )
return V_4 ;
F_13 ( & V_14 ) ;
return V_22 . V_8 . V_23 [ 0 ] ;
}
static int F_14 ( T_1 V_16 ,
struct V_17 * V_18 ,
struct V_19 * V_20 )
{
int V_4 ;
F_15 ( & V_9 , 2 ) ;
V_4 = F_12 ( V_16 , V_18 , 0 , V_20 , NULL ,
& V_21 , & V_22 , 0 ) ;
if ( V_4 ) {
F_15 ( & V_9 , 0 ) ;
return V_4 ;
}
while ( F_16 ( & V_9 ) > 0 ) {
F_17 ( V_16 ) ;
F_18 () ;
}
return V_22 . V_8 . V_23 [ 0 ] ;
}
static void F_19 ( T_1 V_16 )
{
struct V_24 V_25 ;
struct V_19 V_20 ;
int V_4 ;
V_25 . V_26 = V_27 ;
V_25 . V_28 = V_29 ;
V_25 . V_30 = 0 ;
F_20 (KERN_INFO PFX L_1 ) ;
V_20 . V_31 = V_32 ;
V_20 . V_33 = V_34 ;
V_20 . V_23 = V_35 ;
V_20 . V_36 = 3 ;
V_4 = F_14 ( V_16 ,
(struct V_17 * ) & V_25 ,
& V_20 ) ;
if ( V_4 && V_4 != V_37 ) {
F_20 (KERN_ERR PFX L_2
L_3 , rv) ;
}
return;
}
static int F_21 ( T_1 V_16 )
{
struct V_24 V_25 ;
struct V_19 V_20 ;
int V_4 ;
unsigned char V_23 [ 1 ] ;
V_25 . V_26 = V_27 ;
V_25 . V_28 = V_29 ;
V_25 . V_30 = 0 ;
V_20 . V_31 = V_38 ;
V_20 . V_33 = V_39 ;
V_23 [ 0 ] = V_40 ;
V_20 . V_23 = V_23 ;
V_20 . V_36 = sizeof( V_23 ) ;
V_4 = F_10 ( V_16 ,
(struct V_17 * ) & V_25 ,
& V_20 ) ;
F_20 (KERN_INFO PFX L_4 ,
mfg_id, prod_id) ;
if ( ( V_41 == V_42 )
&& ( V_43 == V_44 ) ) {
F_20 (KERN_INFO PFX
L_5 ) ;
V_45 = F_19 ;
}
return ! V_4 ;
}
static void F_22 ( T_1 V_16 )
{
struct V_24 V_25 ;
struct V_19 V_20 ;
int V_4 ;
unsigned char V_23 [ 4 ] ;
V_25 . V_26 = V_27 ;
V_25 . V_28 = V_29 ;
V_25 . V_30 = 0 ;
F_20 (KERN_INFO PFX L_6 ) ;
V_20 . V_31 = V_38 ;
V_20 . V_33 = V_46 ;
V_23 [ 0 ] = V_40 ;
V_23 [ 1 ] = 0 ;
V_23 [ 2 ] = 0 ;
V_23 [ 3 ] = 0 ;
V_20 . V_23 = V_23 ;
V_20 . V_36 = sizeof( V_23 ) ;
V_4 = F_14 ( V_16 ,
(struct V_17 * ) & V_25 ,
& V_20 ) ;
if ( V_4 && V_4 != V_37 ) {
F_20 (KERN_ERR PFX L_7
L_3 , rv) ;
goto V_47;
}
if ( V_45 )
V_45 ( V_16 ) ;
V_47:
return;
}
static int F_23 ( T_1 V_16 )
{
return ( ( V_41 == V_48 )
&& ( V_43 == V_49 ) ) ;
}
static void F_24 ( T_1 V_16 )
{
struct V_24 V_25 ;
struct V_50 V_51 ;
struct V_19 V_20 ;
int V_4 ;
unsigned char V_23 [ 1 ] ;
int V_52 ;
unsigned char V_53 ;
unsigned char V_54 ;
unsigned char V_55 ;
V_25 . V_26 = V_27 ;
V_25 . V_28 = V_29 ;
V_25 . V_30 = 0 ;
F_20 (KERN_INFO PFX L_8 ) ;
V_20 . V_31 = V_56 >> 2 ;
V_20 . V_33 = V_57 ;
V_20 . V_23 = NULL ;
V_20 . V_36 = 0 ;
V_4 = F_14 ( V_16 ,
(struct V_17 * ) & V_25 ,
& V_20 ) ;
if ( V_4 )
goto V_47;
V_52 = V_22 . V_8 . V_23 [ 1 ] ;
V_53 = ( V_52 > 9 ) ? ( 0xb0 + 2 * V_52 ) : ( 0xae + 2 * V_52 ) ;
V_20 . V_31 = V_58 >> 2 ;
V_20 . V_33 = V_59 ;
V_20 . V_23 = NULL ;
V_20 . V_36 = 0 ;
V_4 = F_14 ( V_16 ,
(struct V_17 * ) & V_25 ,
& V_20 ) ;
if ( V_4 )
goto V_47;
V_54 = V_22 . V_8 . V_23 [ 1 ] ;
V_55 = V_22 . V_8 . V_23 [ 2 ] ;
V_51 . V_26 = V_60 ;
V_51 . V_28 = 0 ;
V_51 . V_61 = V_54 ;
V_51 . V_30 = V_55 ;
V_20 . V_31 = V_56 >> 2 ;
V_20 . V_33 = V_62 ;
V_20 . V_23 = & V_53 ;
V_20 . V_36 = 1 ;
F_14 ( V_16 ,
(struct V_17 * ) & V_51 ,
& V_20 ) ;
V_20 . V_31 = V_63 >> 2 ;
V_20 . V_33 = V_64 ;
V_20 . V_23 = V_23 ;
V_23 [ 0 ] = 1 ;
V_20 . V_36 = 1 ;
V_4 = F_14 ( V_16 ,
(struct V_17 * ) & V_25 ,
& V_20 ) ;
if ( V_4 )
goto V_47;
V_20 . V_31 = V_63 >> 2 ;
V_20 . V_33 = V_65 ;
V_20 . V_23 = V_23 ;
V_23 [ 0 ] = 1 ;
V_20 . V_36 = 1 ;
V_4 = F_14 ( V_16 ,
(struct V_17 * ) & V_25 ,
& V_20 ) ;
if ( V_4 )
goto V_47;
V_47:
return;
}
static int F_25 ( T_1 V_16 )
{
const char V_66 = V_67 & 0xF ;
const char V_68 = ( V_67 >> 4 ) & 0xF ;
const char V_69 [ 3 ] = V_70 ;
if ( ! memcmp ( V_69 , & V_41 , sizeof( V_69 ) ) &&
V_66 <= 1 &&
V_68 < 5 )
return 1 ;
return 0 ;
}
static int F_26 ( T_1 V_16 )
{
return ( V_71 & 0x80 ) ;
}
static void F_27 ( T_1 V_16 )
{
struct V_24 V_25 ;
struct V_19 V_20 ;
int V_4 ;
unsigned char V_23 [ 1 ] ;
V_25 . V_26 = V_27 ;
V_25 . V_28 = V_29 ;
V_25 . V_30 = 0 ;
V_72:
F_20 (KERN_INFO PFX L_9 ,
(poweroff_powercycle ? L_10 : L_11)) ;
V_20 . V_31 = V_73 ;
V_20 . V_33 = V_74 ;
if ( V_75 )
V_23 [ 0 ] = V_76 ;
else
V_23 [ 0 ] = V_77 ;
V_20 . V_23 = V_23 ;
V_20 . V_36 = sizeof( V_23 ) ;
V_4 = F_14 ( V_16 ,
(struct V_17 * ) & V_25 ,
& V_20 ) ;
if ( V_4 ) {
if ( V_75 ) {
F_20 (KERN_ERR PFX L_12 \
L_13 , rv) ;
V_75 = 0 ;
goto V_72;
}
F_20 (KERN_ERR PFX L_12 \
L_14 , rv) ;
}
}
static void F_28 ( void )
{
if ( ! V_78 )
return;
F_29 ( V_79 ) ;
}
static void F_4 ( int V_80 , struct V_81 * V_81 )
{
struct V_24 V_25 ;
struct V_19 V_20 ;
int V_4 ;
int V_82 ;
if ( V_78 )
return;
if ( ( V_5 >= 0 ) && ( V_5 != V_80 ) )
return;
V_4 = F_30 ( V_80 , & V_83 , NULL ,
& V_79 ) ;
if ( V_4 ) {
F_20 (KERN_ERR PFX L_15 ,
rv) ;
return;
}
V_6 = V_80 ;
V_25 . V_26 = V_27 ;
V_25 . V_28 = V_29 ;
V_25 . V_30 = 0 ;
V_20 . V_31 = V_84 ;
V_20 . V_33 = V_85 ;
V_20 . V_23 = NULL ;
V_20 . V_36 = 0 ;
V_4 = F_10 ( V_79 ,
(struct V_17 * ) & V_25 ,
& V_20 ) ;
if ( V_4 ) {
F_20 (KERN_ERR PFX L_16
L_3 , rv) ;
goto V_86;
}
if ( V_22 . V_8 . V_36 < 12 ) {
F_20 (KERN_ERR PFX L_17
L_18 ,
halt_recv_msg.msg.data_len, 12 ) ;
goto V_86;
}
V_41 = ( V_22 . V_8 . V_23 [ 7 ]
| ( V_22 . V_8 . V_23 [ 8 ] << 8 )
| ( V_22 . V_8 . V_23 [ 9 ] << 16 ) ) ;
V_43 = ( V_22 . V_8 . V_23 [ 10 ]
| ( V_22 . V_8 . V_23 [ 11 ] << 8 ) ) ;
V_71 = V_22 . V_8 . V_23 [ 6 ] ;
V_67 = V_22 . V_8 . V_23 [ 5 ] ;
for ( V_82 = 0 ; V_82 < V_87 ; V_82 ++ ) {
if ( V_88 [ V_82 ] . F_31 ( V_79 ) )
goto V_89;
}
V_86:
F_20 (KERN_ERR PFX L_19
L_20 ) ;
F_32 ( V_79 ) ;
return;
V_89:
F_20 (KERN_INFO PFX L_21 ,
poweroff_functions[i].platform_type) ;
F_29 = V_88 [ V_82 ] . V_90 ;
V_91 = V_92 ;
V_92 = F_28 ;
V_78 = 1 ;
}
static void F_3 ( int V_80 )
{
if ( ! V_78 )
return;
if ( V_6 != V_80 )
return;
V_78 = 0 ;
F_32 ( V_79 ) ;
V_92 = V_91 ;
}
static int T_2 F_33 ( void )
{
int V_4 ;
F_20 ( V_93 L_22
L_23 ) ;
if ( V_75 )
F_20 (KERN_INFO PFX L_24 ) ;
#ifdef F_34
V_94 = F_35 ( V_95 ) ;
if ( ! V_94 ) {
F_20 (KERN_ERR PFX L_25 ) ;
V_4 = - V_96 ;
goto V_86;
}
#endif
V_4 = F_36 ( & V_97 ) ;
#ifdef F_34
if ( V_4 ) {
F_37 ( V_94 ) ;
F_20 (KERN_ERR PFX L_26 , rv) ;
goto V_86;
}
V_86:
#endif
return V_4 ;
}
static void T_3 F_38 ( void )
{
int V_4 ;
#ifdef F_34
F_37 ( V_94 ) ;
#endif
F_39 ( & V_97 ) ;
if ( V_78 ) {
V_4 = F_32 ( V_79 ) ;
if ( V_4 )
F_20 (KERN_ERR PFX L_27
L_28 , rv) ;
V_92 = V_91 ;
}
}
