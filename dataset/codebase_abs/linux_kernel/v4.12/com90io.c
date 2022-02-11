static T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_4 = V_2 -> V_5 ;
F_2 ( V_3 >> 8 , V_4 , V_6 ) ;
F_2 ( V_3 & 0xff , V_4 , V_7 ) ;
return F_3 ( V_4 , V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 ,
T_1 V_9 )
{
int V_4 = V_2 -> V_5 ;
F_2 ( V_3 >> 8 , V_4 , V_6 ) ;
F_2 ( V_3 & 0xff , V_4 , V_7 ) ;
F_2 ( V_9 , V_4 , V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_10 , char * V_11 )
{
int V_4 = V_2 -> V_5 ;
F_2 ( ( V_3 >> 8 ) | V_12 , V_4 , V_6 ) ;
F_2 ( V_3 & 0xff , V_4 , V_7 ) ;
while ( V_10 -- )
#ifdef F_6
* ( V_11 ++ ) = F_1 ( V_2 , V_3 ++ ) ;
#else
* ( V_11 ++ ) = F_3 ( V_4 , V_8 ) ;
#endif
}
static void F_7 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_10 , char * V_11 )
{
int V_4 = V_2 -> V_5 ;
F_2 ( ( V_3 >> 8 ) | V_12 , V_4 , V_6 ) ;
F_2 ( V_3 & 0xff , V_4 , V_7 ) ;
while ( V_10 -- )
#ifdef F_8
F_4 ( V_2 , V_3 ++ , * ( V_11 ++ ) ) ;
#else
F_2 ( * ( V_11 ++ ) , V_4 , V_8 ) ;
#endif
}
static int T_2 F_9 ( struct V_1 * V_2 )
{
int V_4 = V_2 -> V_5 , V_13 ;
unsigned long V_14 ;
if ( F_10 ( V_15 ) ) {
F_11 ( L_1 , L_2 ) ;
F_11 ( L_3 ) ;
}
if ( ! V_4 ) {
F_12 ( V_15 , V_2 , L_4 ) ;
return - V_16 ;
}
if ( ! F_13 ( V_4 , V_17 , L_5 ) ) {
F_12 ( V_18 , V_2 , L_6 ,
V_4 , V_4 + V_17 - 1 ) ;
return - V_19 ;
}
if ( F_3 ( V_4 , V_20 ) == 0xFF ) {
F_12 ( V_18 , V_2 , L_7 ,
V_4 ) ;
goto V_21;
}
F_3 ( V_4 , V_22 ) ;
F_14 ( V_23 ) ;
V_13 = F_3 ( V_4 , V_20 ) ;
if ( ( V_13 & 0x9D ) != ( V_24 | V_25 | V_26 | V_27 ) ) {
F_12 ( V_18 , V_2 , L_8 ,
V_13 ) ;
goto V_21;
}
F_12 ( V_18 , V_2 , L_9 , V_13 ) ;
F_2 ( V_28 | V_29 | V_30 ,
V_4 , V_31 ) ;
F_12 ( V_18 , V_2 , L_10 ,
V_13 ) ;
V_13 = F_3 ( V_4 , V_20 ) ;
if ( V_13 & V_27 ) {
F_12 ( V_18 , V_2 , L_11 ,
V_13 ) ;
goto V_21;
}
F_2 ( ( 0x16 | V_32 ) & ~ V_33 ,
V_4 , V_34 ) ;
F_2 ( V_12 , V_4 , V_6 ) ;
F_2 ( 0 , V_4 , V_7 ) ;
V_13 = F_3 ( V_4 , V_8 ) ;
if ( V_13 != 0xd1 ) {
F_12 ( V_18 , V_2 , L_12 ,
V_13 ) ;
goto V_21;
}
if ( ! V_2 -> V_35 ) {
V_14 = F_15 () ;
F_2 ( V_24 , V_4 , V_36 ) ;
F_16 ( 1 ) ;
F_2 ( 0 , V_4 , V_36 ) ;
V_2 -> V_35 = F_17 ( V_14 ) ;
if ( ( int ) V_2 -> V_35 <= 0 ) {
F_12 ( V_18 , V_2 , L_13 ) ;
goto V_21;
}
}
F_18 ( V_4 , V_17 ) ;
return F_19 ( V_2 ) ;
V_21:
F_18 ( V_4 , V_17 ) ;
return - V_16 ;
}
static int T_2 F_19 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
int V_4 = V_2 -> V_5 ;
int V_39 ;
if ( F_20 ( V_2 -> V_35 , V_40 , 0 ,
L_14 , V_2 ) ) {
F_12 ( V_15 , V_2 , L_15 , V_2 -> V_35 ) ;
return - V_16 ;
}
if ( ! F_13 ( V_2 -> V_5 , V_17 ,
L_14 ) ) {
F_21 ( V_2 -> V_35 , V_2 ) ;
return - V_41 ;
}
V_38 = F_22 ( V_2 ) ;
V_38 -> V_42 = L_16 ;
V_38 -> V_43 . V_44 = V_45 ;
V_38 -> V_43 . V_13 = V_46 ;
V_38 -> V_43 . V_47 = V_48 ;
V_38 -> V_43 . V_49 = V_50 ;
V_38 -> V_43 . V_51 = V_52 ;
V_38 -> V_43 . V_53 = V_54 ;
V_38 -> V_43 . V_55 = V_56 ;
V_38 -> V_57 = ( 0x16 | V_32 ) & ~ V_33 ;
F_2 ( V_38 -> V_57 , V_4 , V_34 ) ;
V_2 -> V_58 [ 0 ] = F_1 ( V_2 , 1 ) ;
V_39 = F_23 ( V_2 ) ;
if ( V_39 ) {
F_2 ( F_3 ( V_4 , V_34 ) & ~ V_32 ,
V_4 , V_34 ) ;
F_21 ( V_2 -> V_35 , V_2 ) ;
F_18 ( V_2 -> V_5 , V_17 ) ;
return V_39 ;
}
F_12 ( V_15 , V_2 , L_17 ,
V_2 -> V_58 [ 0 ] , V_2 -> V_5 , V_2 -> V_35 ) ;
return 0 ;
}
static int V_50 ( struct V_1 * V_2 , int V_59 )
{
struct V_37 * V_38 = F_22 ( V_2 ) ;
short V_4 = V_2 -> V_5 ;
F_12 ( V_60 , V_2 , L_18 ,
V_2 -> V_61 , F_3 ( V_4 , V_20 ) ) ;
if ( V_59 ) {
F_3 ( V_4 , V_22 ) ;
F_14 ( V_23 ) ;
}
V_38 -> V_57 = ( 0x1C | V_32 ) & ~ V_33 ;
F_2 ( V_38 -> V_57 , V_4 , V_34 ) ;
F_2 ( V_28 | V_29 , V_4 , V_31 ) ;
F_2 ( V_28 | V_30 , V_4 , V_31 ) ;
if ( F_1 ( V_2 , 0 ) != V_62 ) {
F_12 ( V_15 , V_2 , L_19 ) ;
return 1 ;
}
F_2 ( V_63 | V_64 , V_4 , V_31 ) ;
return 0 ;
}
static void V_45 ( struct V_1 * V_2 , int V_65 )
{
short V_4 = V_2 -> V_5 ;
F_2 ( V_65 , V_4 , V_31 ) ;
}
static int V_46 ( struct V_1 * V_2 )
{
short V_4 = V_2 -> V_5 ;
return F_3 ( V_4 , V_20 ) ;
}
static void V_48 ( struct V_1 * V_2 , int V_66 )
{
short V_4 = V_2 -> V_5 ;
F_2 ( V_66 , V_4 , V_36 ) ;
}
static void V_54 ( struct V_1 * V_2 , int V_67 ,
int V_3 , void * V_68 , int V_69 )
{
TIME ( V_2 , L_20 , V_69 ,
F_7 ( V_2 , V_67 * 512 + V_3 , V_69 , V_68 ) ) ;
}
static void V_56 ( struct V_1 * V_2 , int V_67 ,
int V_3 , void * V_68 , int V_69 )
{
TIME ( V_2 , L_21 , V_69 ,
F_5 ( V_2 , V_67 * 512 + V_3 , V_69 , V_68 ) ) ;
}
static int T_2 F_24 ( char * V_70 )
{
int V_71 [ 4 ] ;
V_70 = F_25 ( V_70 , 4 , V_71 ) ;
if ( ! V_71 [ 0 ] )
return 0 ;
switch ( V_71 [ 0 ] ) {
default:
F_26 ( L_22 ) ;
case 2 :
V_35 = V_71 [ 2 ] ;
case 1 :
V_72 = V_71 [ 1 ] ;
}
if ( * V_70 )
snprintf ( V_73 , sizeof( V_73 ) , L_23 , V_70 ) ;
return 1 ;
}
static int T_2 F_27 ( void )
{
struct V_1 * V_2 ;
int V_39 ;
V_2 = F_28 ( V_73 ) ;
if ( ! V_2 )
return - V_74 ;
V_2 -> V_5 = V_72 ;
V_2 -> V_35 = V_35 ;
if ( V_2 -> V_35 == 2 )
V_2 -> V_35 = 9 ;
V_39 = F_9 ( V_2 ) ;
if ( V_39 ) {
F_29 ( V_2 ) ;
return V_39 ;
}
V_75 = V_2 ;
return 0 ;
}
static void T_3 F_30 ( void )
{
struct V_1 * V_2 = V_75 ;
int V_4 = V_2 -> V_5 ;
F_31 ( V_2 ) ;
F_2 ( F_3 ( V_4 , V_34 ) & ~ V_32 ,
V_4 , V_34 ) ;
F_21 ( V_2 -> V_35 , V_2 ) ;
F_18 ( V_2 -> V_5 , V_17 ) ;
F_29 ( V_2 ) ;
}
