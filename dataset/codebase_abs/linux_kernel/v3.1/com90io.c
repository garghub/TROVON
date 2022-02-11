static T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_4 = V_2 -> V_5 ;
F_2 ( V_3 >> 8 , V_6 ) ;
F_2 ( V_3 & 0xff , V_7 ) ;
return F_3 ( V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 , T_1 V_9 )
{
int V_4 = V_2 -> V_5 ;
F_2 ( V_3 >> 8 , V_6 ) ;
F_2 ( V_3 & 0xff , V_7 ) ;
F_2 ( V_9 , V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_10 , char * V_11 )
{
int V_4 = V_2 -> V_5 ;
F_2 ( ( V_3 >> 8 ) | V_12 , V_6 ) ;
F_2 ( V_3 & 0xff , V_7 ) ;
while ( V_10 -- )
#ifdef F_6
* ( V_11 ++ ) = F_1 ( V_2 , V_3 ++ ) ;
#else
* ( V_11 ++ ) = F_3 ( V_8 ) ;
#endif
}
static void F_7 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_10 , char * V_11 )
{
int V_4 = V_2 -> V_5 ;
F_2 ( ( V_3 >> 8 ) | V_12 , V_6 ) ;
F_2 ( V_3 & 0xff , V_7 ) ;
while ( V_10 -- )
#ifdef F_8
F_4 ( V_2 , V_3 ++ , * ( V_11 ++ ) ) ;
#else
F_2 ( * ( V_11 ++ ) , V_8 ) ;
#endif
}
static int T_2 F_9 ( struct V_1 * V_2 )
{
int V_4 = V_2 -> V_5 , V_13 ;
unsigned long V_14 ;
F_10 (D_NORMAL) F_11 ( V_15 ) ;
F_10 (D_NORMAL) F_11 ( L_1 ) ;
if ( ! V_4 ) {
F_12 ( V_16 , L_2
L_3 ) ;
return - V_17 ;
}
if ( ! F_13 ( V_4 , V_18 , L_4 ) ) {
F_12 ( V_19 , L_5 ,
V_4 , V_4 + V_18 - 1 ) ;
return - V_20 ;
}
if ( F_14 () == 0xFF ) {
F_12 ( V_19 , L_6 , V_4 ) ;
goto V_21;
}
F_3 ( V_22 ) ;
F_15 ( V_23 ) ;
V_13 = F_14 () ;
if ( ( V_13 & 0x9D ) != ( V_24 | V_25 | V_26 | V_27 ) ) {
F_12 ( V_19 , L_7 , V_13 ) ;
goto V_21;
}
F_12 ( V_19 , L_8 , V_13 ) ;
F_16 ( V_28 | V_29 | V_30 ) ;
F_12 ( V_19 , L_9 , V_13 ) ;
V_13 = F_14 () ;
if ( V_13 & V_27 ) {
F_12 ( V_19 , L_10 , V_13 ) ;
goto V_21;
}
F_2 ( ( 0x16 | V_31 ) & ~ V_32 , V_33 ) ;
F_2 ( V_12 , V_6 ) ;
F_2 ( 0 , V_7 ) ;
if ( ( V_13 = F_3 ( V_8 ) ) != 0xd1 ) {
F_12 ( V_19 , L_11
L_12 , V_13 ) ;
goto V_21;
}
if ( ! V_2 -> V_34 ) {
V_14 = F_17 () ;
F_2 ( V_24 , V_35 ) ;
F_18 ( 1 ) ;
F_2 ( 0 , V_35 ) ;
V_2 -> V_34 = F_19 ( V_14 ) ;
if ( ( int ) V_2 -> V_34 <= 0 ) {
F_12 ( V_19 , L_13 ) ;
goto V_21;
}
}
F_20 ( V_4 , V_18 ) ;
return F_21 ( V_2 ) ;
V_21:
F_20 ( V_4 , V_18 ) ;
return - V_17 ;
}
static int T_2 F_21 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
int V_4 = V_2 -> V_5 ;
int V_38 ;
if ( F_22 ( V_2 -> V_34 , V_39 , 0 , L_14 , V_2 ) ) {
F_12 ( V_16 , L_15 , V_2 -> V_34 ) ;
return - V_17 ;
}
if ( ! F_13 ( V_2 -> V_5 , V_18 , L_14 ) ) {
F_23 ( V_2 -> V_34 , V_2 ) ;
return - V_40 ;
}
V_37 = F_24 ( V_2 ) ;
V_37 -> V_41 = L_16 ;
V_37 -> V_42 . V_43 = V_44 ;
V_37 -> V_42 . V_13 = V_45 ;
V_37 -> V_42 . V_46 = V_47 ;
V_37 -> V_42 . V_48 = V_49 ;
V_37 -> V_42 . V_50 = V_51 ;
V_37 -> V_42 . V_52 = V_53 ;
V_37 -> V_42 . V_54 = V_55 ;
V_37 -> V_56 = ( 0x16 | V_31 ) & ~ V_32 ;
F_25 () ;
V_2 -> V_57 [ 0 ] = F_1 ( V_2 , 1 ) ;
V_38 = F_26 ( V_2 ) ;
if ( V_38 ) {
F_2 ( ( F_3 ( V_33 ) & ~ V_31 ) , V_33 ) ;
F_23 ( V_2 -> V_34 , V_2 ) ;
F_20 ( V_2 -> V_5 , V_18 ) ;
return V_38 ;
}
F_12 ( V_16 , L_17 ,
V_2 -> V_57 [ 0 ] , V_2 -> V_5 , V_2 -> V_34 ) ;
return 0 ;
}
static int V_49 ( struct V_1 * V_2 , int V_58 )
{
struct V_36 * V_37 = F_24 ( V_2 ) ;
short V_4 = V_2 -> V_5 ;
F_12 ( V_59 , L_18 , V_2 -> V_60 , F_14 () ) ;
if ( V_58 ) {
F_3 ( V_22 ) ;
F_15 ( V_23 ) ;
}
V_37 -> V_56 = ( 0x1C | V_31 ) & ~ V_32 ;
F_25 () ;
F_16 ( V_28 | V_29 ) ;
F_16 ( V_28 | V_30 ) ;
if ( F_1 ( V_2 , 0 ) != V_61 ) {
F_12 ( V_16 , L_19 ) ;
return 1 ;
}
F_16 ( V_62 | V_63 ) ;
return 0 ;
}
static void V_44 ( struct V_1 * V_2 , int V_64 )
{
short V_4 = V_2 -> V_5 ;
F_16 ( V_64 ) ;
}
static int V_45 ( struct V_1 * V_2 )
{
short V_4 = V_2 -> V_5 ;
return F_14 () ;
}
static void V_47 ( struct V_1 * V_2 , int V_65 )
{
short V_4 = V_2 -> V_5 ;
F_27 ( V_65 ) ;
}
static void V_53 ( struct V_1 * V_2 , int V_66 , int V_3 ,
void * V_67 , int V_68 )
{
TIME ( L_20 , V_68 , F_7 ( V_2 , V_66 * 512 + V_3 , V_68 , V_67 ) ) ;
}
static void V_55 ( struct V_1 * V_2 , int V_66 , int V_3 ,
void * V_67 , int V_68 )
{
TIME ( L_21 , V_68 , F_5 ( V_2 , V_66 * 512 + V_3 , V_68 , V_67 ) ) ;
}
static int T_2 F_28 ( char * V_69 )
{
int V_70 [ 4 ] ;
V_69 = F_29 ( V_69 , 4 , V_70 ) ;
if ( ! V_70 [ 0 ] )
return 0 ;
switch ( V_70 [ 0 ] ) {
default:
F_11 ( L_22 ) ;
case 2 :
V_34 = V_70 [ 2 ] ;
case 1 :
V_71 = V_70 [ 1 ] ;
}
if ( * V_69 )
snprintf ( V_72 , sizeof( V_72 ) , L_23 , V_69 ) ;
return 1 ;
}
static int T_2 F_30 ( void )
{
struct V_1 * V_2 ;
int V_38 ;
V_2 = F_31 ( V_72 ) ;
if ( ! V_2 )
return - V_73 ;
V_2 -> V_5 = V_71 ;
V_2 -> V_34 = V_34 ;
if ( V_2 -> V_34 == 2 )
V_2 -> V_34 = 9 ;
V_38 = F_9 ( V_2 ) ;
if ( V_38 ) {
F_32 ( V_2 ) ;
return V_38 ;
}
V_74 = V_2 ;
return 0 ;
}
static void T_3 F_33 ( void )
{
struct V_1 * V_2 = V_74 ;
int V_4 = V_2 -> V_5 ;
F_34 ( V_2 ) ;
F_2 ( ( F_3 ( V_33 ) & ~ V_31 ) , V_33 ) ;
F_23 ( V_2 -> V_34 , V_2 ) ;
F_20 ( V_2 -> V_5 , V_18 ) ;
F_32 ( V_2 ) ;
}
