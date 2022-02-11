static inline bool F_1 ( int V_1 , int V_2 )
{
return F_2 ( V_1 ) == V_2 ;
}
void T_1 F_3 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
F_4 ( V_7 L_1 ) ;
F_5 () ;
if ( F_6 () == 1 )
F_7 ( V_4 , V_6 ) ;
return;
}
bool T_1 F_8 ( void )
{
unsigned char V_8 = 0 , V_9 = 0 , V_10 = 0 ;
switch ( V_11 -> V_12 -> V_13 ) {
case V_14 :
V_8 = F_9 ( V_15 , V_16 ) ;
F_10 ( V_16 , V_15 , 0x03 , V_17 + V_18 ) ;
break;
case V_19 :
case V_20 :
V_8 = F_9 ( V_15 , V_16 ) ;
F_10 ( V_16 , V_15 , 0x03 , V_17 + V_18 ) ;
V_9 = F_9 ( V_15 , V_21 ) ;
F_10 ( V_21 , V_15 , 0xC0 , V_22 + V_23 ) ;
break;
default:
V_9 = F_9 ( V_15 , V_21 ) ;
F_10 ( V_21 , V_15 , 0xF0 , V_24 +
V_25 + V_22 + V_23 ) ;
V_10 = F_9 ( V_15 , V_26 ) ;
F_10 ( V_26 , V_15 , 0x0 , V_25 ) ;
break;
}
V_11 -> V_12 -> V_27 . V_28 = V_29 ;
V_11 -> V_12 ->
V_27 . V_30 = V_31 ;
V_11 -> V_12 -> V_27 . V_32 = V_33 ;
if ( F_1 ( V_34 , V_35 ) ) {
F_11 ( 0x08 , 0x3b ) ;
F_4 ( V_7 L_2 ) ;
F_4 ( V_7 L_3 ,
V_11 -> V_12 -> V_27 . V_28 ) ;
F_4 ( V_7 L_3 ,
V_11 -> V_12 -> V_27 . V_32 ) ;
return true ;
} else {
V_11 -> V_12 -> V_27 . V_32 = V_36 ;
if ( F_1 ( V_34 , V_35 ) ) {
F_11 ( 0x08 , 0x3b ) ;
F_4 ( V_7 L_2 ) ;
F_4 ( V_7 L_3 ,
V_11 -> V_12 ->
V_27 . V_28 ) ;
F_4 ( V_7 L_3 ,
V_11 -> V_12 ->
V_27 . V_32 ) ;
return true ;
}
}
V_11 -> V_12 -> V_27 . V_28 = V_37 ;
if ( ( V_11 -> V_12 -> V_13 == V_38 ) &&
( ( V_39 == V_40 ) ||
( V_39 == V_41 ) ) ) {
F_4 ( V_7 L_4 ) ;
return true ;
}
switch ( V_11 -> V_12 -> V_13 ) {
case V_14 :
F_12 ( V_16 , V_15 , V_8 ) ;
break;
case V_19 :
case V_20 :
F_12 ( V_16 , V_15 , V_8 ) ;
F_12 ( V_21 , V_15 , V_9 ) ;
break;
default:
F_12 ( V_21 , V_15 , V_9 ) ;
F_12 ( V_26 , V_15 , V_10 ) ;
break;
}
V_11 -> V_12 ->
V_27 . V_28 = V_42 ;
V_11 -> V_12 -> V_27 .
V_30 = V_31 ;
return false ;
}
static void F_11 ( int V_43 , T_2 V_44 )
{
F_13 ( V_11 -> V_12 -> V_27 . V_32 ,
V_11 -> V_12 -> V_27 . V_30 ,
V_43 , V_44 ) ;
}
static int F_2 ( int V_43 )
{
T_2 V_44 ;
F_14 ( V_11 -> V_12 -> V_27 . V_32 ,
( T_2 ) V_11 -> V_12 -> V_27 . V_30 ,
( T_2 ) V_43 , & V_44 ) ;
return V_44 ;
}
static int F_15 ( int V_43 , T_2 * V_45 , int V_46 )
{
F_16 ( V_11 -> V_12 -> V_27 . V_32 ,
( T_2 ) V_11 -> V_12 -> V_27 . V_30 ,
( T_2 ) V_43 , V_45 , V_46 ) ;
return 0 ;
}
void F_17 ( struct V_47 * V_48 , int V_49 ,
int V_50 )
{
struct V_47 * V_51 ;
struct V_52 * V_53 ;
unsigned long V_54 , V_55 ;
V_53 = V_48 -> V_56 ;
V_54 = V_53 -> V_57
* V_53 -> V_56 . V_58 * V_53 -> V_56 . V_59
/ 1000000 ;
V_55 = ( unsigned long ) V_11 ->
V_60 -> V_61 ;
F_4 ( V_7 L_5 ) ;
if ( ( V_55 != 0 ) && ( V_54 > V_55 ) ) {
V_51 = F_18 ( V_48 -> V_56 [ 0 ] . V_56 . V_62 ,
V_48 -> V_56 [ 0 ] . V_56 . V_63 ) ;
if ( V_51 ) {
V_48 = V_51 ;
V_53 = V_51 -> V_56 ;
}
}
F_19 ( V_53 , V_48 , V_49 / 8 , V_50 ) ;
}
int F_5 ( void )
{
T_2 V_64 = 0 , V_65 = 0 , V_66 = 0 , V_67 = 0 ,
V_68 = 0 , V_69 = 0 , V_44 ;
int V_70 = false ;
F_4 ( V_7 L_6 ) ;
if ( V_11 -> V_12 -> V_13 == V_71 ) {
V_64 = F_9 ( V_15 , V_21 ) ;
F_12 ( V_21 , V_15 , V_64 | 0x30 ) ;
V_66 = F_9 ( V_72 , V_73 ) ;
F_12 ( V_73 , V_72 , V_66 | 0x08 ) ;
V_67 = F_9 ( V_72 , V_74 ) ;
F_12 ( V_74 , V_72 , 0x1D ) ;
V_68 = F_9 ( V_72 , V_75 ) ;
F_12 ( V_75 , V_72 , 0x01 ) ;
} else {
V_64 = F_9 ( V_15 , V_21 ) ;
F_12 ( V_21 , V_15 , V_64 | 0xF0 ) ;
V_65 = F_9 ( V_15 , V_26 ) ;
F_12 ( V_26 , V_15 , V_65 & ( ~ 0x20 ) ) ;
V_67 = F_9 ( V_72 , V_74 ) ;
F_12 ( V_74 , V_72 , 0x1D ) ;
V_69 = F_9 ( V_72 , V_76 ) ;
F_12 ( V_76 , V_72 , 0x01 ) ;
}
V_44 = ( T_2 ) F_2 ( 0x09 ) ;
if ( V_44 & 0x04 )
V_70 = true ;
if ( V_70 == false ) {
if ( F_6 () )
V_70 = true ;
}
F_12 ( V_21 , V_15 , V_64 ) ;
F_12 ( V_74 , V_72 , V_67 ) ;
if ( V_11 -> V_12 -> V_13 == V_71 ) {
F_12 ( V_73 , V_72 , V_66 ) ;
F_12 ( V_75 , V_72 , V_68 ) ;
} else {
F_12 ( V_26 , V_15 , V_65 ) ;
F_12 ( V_76 , V_72 , V_69 ) ;
}
return V_70 ;
}
static int F_6 ( void )
{
T_2 V_77 , V_78 ;
int V_79 ;
F_4 ( V_7 L_7 ) ;
V_79 = V_11 -> V_12 -> V_27 . V_30 ;
V_11 -> V_12 -> V_27 . V_30 = 0xA0 ;
V_77 = ( T_2 ) F_2 ( 0x00 ) ;
V_78 = ( T_2 ) F_2 ( 0x01 ) ;
if ( ( V_77 == 0 ) && ( V_78 == 0xFF ) ) {
V_11 -> V_12 ->
V_27 . V_30 = V_79 ;
return V_80 ;
}
return false ;
}
static void T_1 F_7 (
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_81 , V_79 ;
unsigned char V_82 [ 18 ] ;
F_4 ( V_7 L_8 ) ;
V_79 = V_4 -> V_30 ;
V_4 -> V_30 = 0xA0 ;
for ( V_81 = 0x25 ; V_81 < 0x6D ; V_81 ++ ) {
switch ( V_81 ) {
case 0x36 :
case 0x48 :
case 0x5A :
case 0x6C :
F_15 ( V_81 , V_82 , 10 ) ;
if ( ! ( V_82 [ 0 ] || V_82 [ 1 ] ) ) {
if ( V_82 [ 3 ] == 0xFD ) {
V_6 -> V_61 =
V_82 [ 9 ] * 10 ;
}
}
break;
default:
break;
}
}
F_4 ( V_7 L_9 ,
V_6 -> V_61 ) ;
V_4 -> V_30 = V_79 ;
}
void F_20 ( void )
{
if ( V_11 -> V_12 ->
V_27 . V_83 == V_84 )
F_12 ( V_85 , V_72 ,
F_9 ( V_72 , V_85 ) | 0x08 ) ;
}
static void F_21 ( void )
{
F_10 ( V_86 , V_15 , 0 , V_18 ) ;
F_10 ( V_16 , V_15 , 0 , V_24 ) ;
switch ( V_11 -> V_12 -> V_13 ) {
case V_20 :
{
if ( ( V_11 -> V_60 -> V_87 == 1600 ) &&
( V_11 -> V_60 -> V_88 ==
1200 ) )
F_10 ( V_89 , V_72 , 0x03 ,
V_17 + V_18 + V_90 ) ;
else
F_10 ( V_89 , V_72 , 0x07 ,
V_17 + V_18 + V_90 ) ;
break;
}
case V_19 :
{
F_10 ( V_89 , V_72 , 0x07 ,
V_17 + V_18 + V_90 + V_91 ) ;
F_10 ( V_86 , V_15 , 0x02 , V_18 ) ;
F_10 ( V_16 , V_15 , 0x10 , V_24 ) ;
break;
}
default:
{
break;
}
}
}
static void F_22 ( void )
{
switch ( V_11 -> V_12 -> V_13 ) {
case V_14 :
{
F_10 ( V_92 , V_72 , 0x03 , V_17 + V_18 ) ;
break;
}
case V_19 :
{
F_10 ( V_92 , V_72 , 0x08 ,
V_17 + V_18 + V_90 + V_91 ) ;
break;
}
case V_20 :
{
F_10 ( V_92 , V_72 , 0x0F ,
V_17 + V_18 + V_90 + V_91 ) ;
break;
}
default:
{
break;
}
}
}
void F_23 ( void )
{
T_2 V_44 ;
switch ( V_11 -> V_12 -> V_27 . V_83 ) {
case V_93 :
F_10 ( V_73 , V_72 , 0x01 , V_17 ) ;
F_10 ( V_94 , V_72 , 0x21 , V_17 + V_25 ) ;
F_21 () ;
if ( V_11 -> V_12 -> V_13 == V_71 )
F_11 ( 0x88 , 0x3b ) ;
else
F_24 ( V_72 , 0x91 , 0x00 , 0x20 ) ;
break;
case V_95 :
if ( V_11 -> V_12 -> V_13 == V_71 )
F_10 ( V_75 , V_72 , 0x21 , V_17 + V_25 ) ;
if ( V_11 -> V_12 -> V_13 == V_71 )
F_11 ( 0x88 , 0x3b ) ;
else
F_24 ( V_72 , 0x91 , 0x00 , 0x20 ) ;
if ( V_96 == 1 ) {
F_10 ( V_74 , V_72 , 0x1f , 0x1f ) ;
F_10 ( V_97 , V_72 , 0x00 , V_22 + V_17 ) ;
if ( V_98 == 24 ) {
if ( V_99 == 1 )
V_44 = 0x3F ;
else
V_44 = 0x37 ;
F_13 ( V_11 -> V_12 ->
V_27 . V_32 ,
V_11 -> V_12 ->
V_27 . V_30 ,
0x08 , V_44 ) ;
}
}
break;
case V_100 :
if ( V_11 -> V_12 -> V_13 != V_71 )
F_24 ( V_72 , V_101 , 0x03 , 0x03 ) ;
F_24 ( V_72 , 0x91 , 0x00 , 0x20 ) ;
break;
case V_102 :
if ( V_11 -> V_12 -> V_13 == V_71 )
break;
F_22 () ;
F_24 ( V_72 , 0x91 , 0x00 , 0x20 ) ;
break;
case V_84 :
F_10 ( V_74 , V_72 , 0 , V_23 ) ;
F_10 ( V_85 , V_72 , 0 , V_91 ) ;
break;
}
if ( V_11 -> V_60 -> V_103 == V_104 ) {
F_10 ( V_105 , V_72 , 0x00 , V_17 ) ;
}
}
