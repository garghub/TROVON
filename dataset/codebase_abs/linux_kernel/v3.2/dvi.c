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
void F_17 ( const struct V_47 * V_48 , int V_49 )
{
struct V_47 V_50 = * V_48 ;
struct V_51 * V_52 ;
int V_53 ;
V_53 = V_11 -> V_54 -> V_55 . V_56 ;
if ( V_53 && F_18 ( V_48 -> V_57 ) / 1000 > V_53 ) {
V_52 = F_19 ( V_48 -> V_58 , V_48 -> V_59 , 60 ) ;
if ( V_52 )
F_20 ( & V_50 , V_52 ) ;
}
F_21 ( & V_50 , V_49 ) ;
}
int F_5 ( void )
{
T_2 V_60 = 0 , V_61 = 0 , V_62 = 0 , V_63 = 0 ,
V_64 = 0 , V_65 = 0 , V_44 ;
int V_66 = false ;
F_4 ( V_7 L_5 ) ;
if ( V_11 -> V_12 -> V_13 == V_67 ) {
V_60 = F_9 ( V_15 , V_21 ) ;
F_12 ( V_21 , V_15 , V_60 | 0x30 ) ;
V_62 = F_9 ( V_68 , V_69 ) ;
F_12 ( V_69 , V_68 , V_62 | 0x08 ) ;
V_63 = F_9 ( V_68 , V_70 ) ;
F_12 ( V_70 , V_68 , 0x1D ) ;
V_64 = F_9 ( V_68 , V_71 ) ;
F_12 ( V_71 , V_68 , 0x01 ) ;
} else {
V_60 = F_9 ( V_15 , V_21 ) ;
F_12 ( V_21 , V_15 , V_60 | 0xF0 ) ;
V_61 = F_9 ( V_15 , V_26 ) ;
F_12 ( V_26 , V_15 , V_61 & ( ~ 0x20 ) ) ;
V_63 = F_9 ( V_68 , V_70 ) ;
F_12 ( V_70 , V_68 , 0x1D ) ;
V_65 = F_9 ( V_68 , V_72 ) ;
F_12 ( V_72 , V_68 , 0x01 ) ;
}
V_44 = ( T_2 ) F_2 ( 0x09 ) ;
if ( V_44 & 0x04 )
V_66 = true ;
if ( V_66 == false ) {
if ( F_6 () )
V_66 = true ;
}
F_12 ( V_21 , V_15 , V_60 ) ;
F_12 ( V_70 , V_68 , V_63 ) ;
if ( V_11 -> V_12 -> V_13 == V_67 ) {
F_12 ( V_69 , V_68 , V_62 ) ;
F_12 ( V_71 , V_68 , V_64 ) ;
} else {
F_12 ( V_26 , V_15 , V_61 ) ;
F_12 ( V_72 , V_68 , V_65 ) ;
}
return V_66 ;
}
static int F_6 ( void )
{
T_2 V_73 , V_74 ;
int V_75 ;
F_4 ( V_7 L_6 ) ;
V_75 = V_11 -> V_12 -> V_27 . V_30 ;
V_11 -> V_12 -> V_27 . V_30 = 0xA0 ;
V_73 = ( T_2 ) F_2 ( 0x00 ) ;
V_74 = ( T_2 ) F_2 ( 0x01 ) ;
if ( ( V_73 == 0 ) && ( V_74 == 0xFF ) ) {
V_11 -> V_12 ->
V_27 . V_30 = V_75 ;
return V_76 ;
}
return false ;
}
static void T_1 F_7 (
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_77 , V_75 ;
unsigned char V_78 [ 18 ] ;
F_4 ( V_7 L_7 ) ;
V_75 = V_4 -> V_30 ;
V_4 -> V_30 = 0xA0 ;
for ( V_77 = 0x25 ; V_77 < 0x6D ; V_77 ++ ) {
switch ( V_77 ) {
case 0x36 :
case 0x48 :
case 0x5A :
case 0x6C :
F_15 ( V_77 , V_78 , 10 ) ;
if ( ! ( V_78 [ 0 ] || V_78 [ 1 ] ) ) {
if ( V_78 [ 3 ] == 0xFD ) {
V_6 -> V_56 =
V_78 [ 9 ] * 10 ;
}
}
break;
default:
break;
}
}
F_4 ( V_7 L_8 ,
V_6 -> V_56 ) ;
V_4 -> V_30 = V_75 ;
}
void F_22 ( void )
{
if ( V_11 -> V_12 ->
V_27 . V_79 == V_80 )
F_12 ( V_81 , V_68 ,
F_9 ( V_68 , V_81 ) | 0x08 ) ;
}
static void F_23 ( void )
{
F_10 ( V_82 , V_15 , 0 , V_18 ) ;
F_10 ( V_16 , V_15 , 0 , V_24 ) ;
switch ( V_11 -> V_12 -> V_13 ) {
case V_20 :
{
if ( ( V_11 -> V_55 -> V_83 == 1600 ) &&
( V_11 -> V_55 -> V_84 ==
1200 ) )
F_10 ( V_85 , V_68 , 0x03 ,
V_17 + V_18 + V_86 ) ;
else
F_10 ( V_85 , V_68 , 0x07 ,
V_17 + V_18 + V_86 ) ;
break;
}
case V_19 :
{
F_10 ( V_85 , V_68 , 0x07 ,
V_17 + V_18 + V_86 + V_87 ) ;
F_10 ( V_82 , V_15 , 0x02 , V_18 ) ;
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
F_10 ( V_88 , V_68 , 0x03 , V_17 + V_18 ) ;
break;
}
case V_19 :
{
F_10 ( V_88 , V_68 , 0x08 ,
V_17 + V_18 + V_86 + V_87 ) ;
break;
}
case V_20 :
{
F_10 ( V_88 , V_68 , 0x0F ,
V_17 + V_18 + V_86 + V_87 ) ;
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
T_2 V_44 ;
switch ( V_11 -> V_12 -> V_27 . V_79 ) {
case V_89 :
F_10 ( V_69 , V_68 , 0x01 , V_17 ) ;
F_10 ( V_90 , V_68 , 0x21 , V_17 + V_25 ) ;
F_23 () ;
if ( V_11 -> V_12 -> V_13 == V_67 )
F_11 ( 0x88 , 0x3b ) ;
else
F_26 ( V_68 , 0x91 , 0x00 , 0x20 ) ;
break;
case V_91 :
if ( V_11 -> V_12 -> V_13 == V_67 )
F_10 ( V_71 , V_68 , 0x21 , V_17 + V_25 ) ;
if ( V_11 -> V_12 -> V_13 == V_67 )
F_11 ( 0x88 , 0x3b ) ;
else
F_26 ( V_68 , 0x91 , 0x00 , 0x20 ) ;
if ( V_92 == 1 ) {
F_10 ( V_70 , V_68 , 0x1f , 0x1f ) ;
F_10 ( V_93 , V_68 , 0x00 , V_22 + V_17 ) ;
if ( V_94 == 24 ) {
if ( V_95 == 1 )
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
case V_96 :
if ( V_11 -> V_12 -> V_13 != V_67 )
F_26 ( V_68 , V_97 , 0x03 , 0x03 ) ;
F_26 ( V_68 , 0x91 , 0x00 , 0x20 ) ;
break;
case V_98 :
if ( V_11 -> V_12 -> V_13 == V_67 )
break;
F_24 () ;
F_26 ( V_68 , 0x91 , 0x00 , 0x20 ) ;
break;
case V_80 :
F_10 ( V_70 , V_68 , 0 , V_23 ) ;
F_10 ( V_81 , V_68 , 0 , V_87 ) ;
break;
}
if ( V_11 -> V_55 -> V_99 == V_100 ) {
F_10 ( V_101 , V_68 , 0x00 , V_17 ) ;
}
}
