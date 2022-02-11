static inline bool F_1 ( int V_1 , int V_2 )
{
return F_2 ( V_1 ) == V_2 ;
}
void F_3 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
F_4 ( V_7 L_1 ) ;
F_5 () ;
if ( F_6 () == 1 )
F_7 ( V_4 , V_6 ) ;
return;
}
bool F_8 ( void )
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
static void F_11 ( int V_43 , T_1 V_44 )
{
F_13 ( V_11 -> V_12 -> V_27 . V_32 ,
V_11 -> V_12 -> V_27 . V_30 ,
V_43 , V_44 ) ;
}
static int F_2 ( int V_43 )
{
T_1 V_44 ;
F_14 ( V_11 -> V_12 -> V_27 . V_32 ,
( T_1 ) V_11 -> V_12 -> V_27 . V_30 ,
( T_1 ) V_43 , & V_44 ) ;
return V_44 ;
}
static int F_15 ( int V_43 , T_1 * V_45 , int V_46 )
{
F_16 ( V_11 -> V_12 -> V_27 . V_32 ,
( T_1 ) V_11 -> V_12 -> V_27 . V_30 ,
( T_1 ) V_43 , V_45 , V_46 ) ;
return 0 ;
}
void F_17 ( const struct V_47 * V_48 ,
T_2 V_49 , T_2 V_50 , int V_51 )
{
struct V_47 V_52 = * V_48 ;
const struct V_53 * V_54 ;
int V_55 ;
V_55 = V_11 -> V_56 -> V_57 . V_58 ;
if ( V_55 && F_18 ( V_48 -> V_59 ) / 1000 > V_55 ) {
V_54 = F_19 ( V_48 -> V_60 , V_48 -> V_61 , 60 ) ;
if ( V_54 )
F_20 ( & V_52 , V_54 ) ;
}
F_21 ( & V_52 , V_49 , V_50 , V_51 ) ;
}
int F_5 ( void )
{
T_1 V_62 = 0 , V_63 = 0 , V_64 = 0 , V_65 = 0 ,
V_66 = 0 , V_67 = 0 , V_44 ;
int V_68 = false ;
F_4 ( V_7 L_5 ) ;
if ( V_11 -> V_12 -> V_13 == V_69 ) {
V_62 = F_9 ( V_15 , V_21 ) ;
F_12 ( V_21 , V_15 , V_62 | 0x30 ) ;
V_64 = F_9 ( V_70 , V_71 ) ;
F_12 ( V_71 , V_70 , V_64 | 0x08 ) ;
V_65 = F_9 ( V_70 , V_72 ) ;
F_12 ( V_72 , V_70 , 0x1D ) ;
V_66 = F_9 ( V_70 , V_73 ) ;
F_12 ( V_73 , V_70 , 0x01 ) ;
} else {
V_62 = F_9 ( V_15 , V_21 ) ;
F_12 ( V_21 , V_15 , V_62 | 0xF0 ) ;
V_63 = F_9 ( V_15 , V_26 ) ;
F_12 ( V_26 , V_15 , V_63 & ( ~ 0x20 ) ) ;
V_65 = F_9 ( V_70 , V_72 ) ;
F_12 ( V_72 , V_70 , 0x1D ) ;
V_67 = F_9 ( V_70 , V_74 ) ;
F_12 ( V_74 , V_70 , 0x01 ) ;
}
V_44 = ( T_1 ) F_2 ( 0x09 ) ;
if ( V_44 & 0x04 )
V_68 = true ;
if ( V_68 == false ) {
if ( F_6 () )
V_68 = true ;
}
F_12 ( V_21 , V_15 , V_62 ) ;
F_12 ( V_72 , V_70 , V_65 ) ;
if ( V_11 -> V_12 -> V_13 == V_69 ) {
F_12 ( V_71 , V_70 , V_64 ) ;
F_12 ( V_73 , V_70 , V_66 ) ;
} else {
F_12 ( V_26 , V_15 , V_63 ) ;
F_12 ( V_74 , V_70 , V_67 ) ;
}
return V_68 ;
}
static int F_6 ( void )
{
T_1 V_75 , V_76 ;
int V_77 ;
F_4 ( V_7 L_6 ) ;
V_77 = V_11 -> V_12 -> V_27 . V_30 ;
V_11 -> V_12 -> V_27 . V_30 = 0xA0 ;
V_75 = ( T_1 ) F_2 ( 0x00 ) ;
V_76 = ( T_1 ) F_2 ( 0x01 ) ;
if ( ( V_75 == 0 ) && ( V_76 == 0xFF ) ) {
V_11 -> V_12 ->
V_27 . V_30 = V_77 ;
return V_78 ;
}
return false ;
}
static void F_7 (
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_79 , V_77 ;
unsigned char V_80 [ 18 ] ;
F_4 ( V_7 L_7 ) ;
V_77 = V_4 -> V_30 ;
V_4 -> V_30 = 0xA0 ;
for ( V_79 = 0x25 ; V_79 < 0x6D ; V_79 ++ ) {
switch ( V_79 ) {
case 0x36 :
case 0x48 :
case 0x5A :
case 0x6C :
F_15 ( V_79 , V_80 , 10 ) ;
if ( ! ( V_80 [ 0 ] || V_80 [ 1 ] ) ) {
if ( V_80 [ 3 ] == 0xFD ) {
V_6 -> V_58 =
V_80 [ 9 ] * 10 ;
}
}
break;
default:
break;
}
}
F_4 ( V_7 L_8 ,
V_6 -> V_58 ) ;
V_4 -> V_30 = V_77 ;
}
void F_22 ( void )
{
if ( V_11 -> V_12 ->
V_27 . V_81 == V_82 )
F_12 ( V_83 , V_70 ,
F_9 ( V_70 , V_83 ) | 0x08 ) ;
}
static void F_23 ( void )
{
F_10 ( V_84 , V_15 , 0 , V_18 ) ;
F_10 ( V_16 , V_15 , 0 , V_24 ) ;
switch ( V_11 -> V_12 -> V_13 ) {
case V_20 :
{
if ( ( V_11 -> V_57 -> V_85 == 1600 ) &&
( V_11 -> V_57 -> V_86 ==
1200 ) )
F_10 ( V_87 , V_70 , 0x03 ,
V_17 + V_18 + V_88 ) ;
else
F_10 ( V_87 , V_70 , 0x07 ,
V_17 + V_18 + V_88 ) ;
break;
}
case V_19 :
{
F_10 ( V_87 , V_70 , 0x07 ,
V_17 + V_18 + V_88 + V_89 ) ;
F_10 ( V_84 , V_15 , 0x02 , V_18 ) ;
F_10 ( V_16 , V_15 , 0x10 , V_24 ) ;
break;
}
default:
{
break;
}
}
}
static void F_24 ( void )
{
switch ( V_11 -> V_12 -> V_13 ) {
case V_14 :
{
F_10 ( V_90 , V_70 , 0x03 , V_17 + V_18 ) ;
break;
}
case V_19 :
{
F_10 ( V_90 , V_70 , 0x08 ,
V_17 + V_18 + V_88 + V_89 ) ;
break;
}
case V_20 :
{
F_10 ( V_90 , V_70 , 0x0F ,
V_17 + V_18 + V_88 + V_89 ) ;
break;
}
default:
{
break;
}
}
}
void F_25 ( void )
{
T_1 V_44 ;
switch ( V_11 -> V_12 -> V_27 . V_81 ) {
case V_91 :
F_10 ( V_71 , V_70 , 0x01 , V_17 ) ;
F_10 ( V_92 , V_70 , 0x21 , V_17 + V_25 ) ;
F_23 () ;
if ( V_11 -> V_12 -> V_13 == V_69 )
F_11 ( 0x88 , 0x3b ) ;
else
F_26 ( V_70 , 0x91 , 0x00 , 0x20 ) ;
break;
case V_93 :
if ( V_11 -> V_12 -> V_13 == V_69 )
F_10 ( V_73 , V_70 , 0x21 , V_17 + V_25 ) ;
if ( V_11 -> V_12 -> V_13 == V_69 )
F_11 ( 0x88 , 0x3b ) ;
else
F_26 ( V_70 , 0x91 , 0x00 , 0x20 ) ;
if ( V_94 == 1 ) {
F_10 ( V_72 , V_70 , 0x1f , 0x1f ) ;
F_10 ( V_95 , V_70 , 0x00 , V_22 + V_17 ) ;
if ( V_96 == 24 ) {
if ( V_97 == 1 )
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
case V_98 :
if ( V_11 -> V_12 -> V_13 != V_69 )
F_26 ( V_70 , V_99 , 0x03 , 0x03 ) ;
F_26 ( V_70 , 0x91 , 0x00 , 0x20 ) ;
break;
case V_100 :
if ( V_11 -> V_12 -> V_13 == V_69 )
break;
F_24 () ;
F_26 ( V_70 , 0x91 , 0x00 , 0x20 ) ;
break;
case V_82 :
F_10 ( V_72 , V_70 , 0 , V_23 ) ;
F_10 ( V_83 , V_70 , 0 , V_89 ) ;
break;
}
if ( V_11 -> V_57 -> V_101 == V_102 ) {
F_10 ( V_103 , V_70 , 0x00 , V_17 ) ;
}
}
