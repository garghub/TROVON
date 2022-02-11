static inline T_1 F_1 ( T_2 V_1 )
{
F_2 ( V_1 > 200 ) ;
return ( 5000 + 5 * V_1 ) ;
}
static inline T_1 F_3 ( T_1 V_2 )
{
T_1 V_3 ;
if ( V_2 < 5091 )
V_3 = 0x0040 ;
else if ( V_2 < 5321 )
V_3 = 0x0000 ;
else if ( V_2 < 5806 )
V_3 = 0x0080 ;
else
V_3 = 0x0040 ;
return V_3 ;
}
static void F_4 ( struct V_4 * V_5 )
{
static const T_2 V_6 [ 5 ] = { 0x00 , 0x40 , 0x80 , 0x90 , 0xD0 } ;
static const T_2 V_7 [ 5 ] = { 0x00 , 0x01 , 0x05 , 0x06 , 0x0A } ;
T_1 V_8 = F_5 ( V_5 , 0x001E ) ;
int V_9 , V_10 ;
for ( V_9 = 0 ; V_9 < 5 ; V_9 ++ ) {
for ( V_10 = 0 ; V_10 < 5 ; V_10 ++ ) {
if ( V_8 == ( V_6 [ V_9 ] << 4 | V_7 [ V_10 ] ) ) {
F_6 ( V_5 , 0x0069 ,
( V_9 - V_10 ) << 8 | 0x00C0 ) ;
return;
}
}
}
}
static void F_7 ( struct V_4 * V_5 , unsigned int V_1 )
{
T_1 V_11 , V_12 , V_8 ;
V_11 = F_1 ( V_1 ) ;
V_12 = F_5 ( V_5 , 0x0008 ) ;
F_8 ( V_5 , 0x03F0 , V_11 ) ;
F_9 ( V_5 , 0x0008 , V_12 ) ;
V_8 = F_5 ( V_5 , 0x002E ) ;
V_8 &= 0x0080 ;
F_9 ( V_5 , 0x002E , V_8 ) ;
if ( V_11 >= 4920 && V_11 <= 5500 ) {
V_12 = 3 * V_11 / 116 ;
}
F_9 ( V_5 , 0x0007 , ( V_12 << 4 ) | V_12 ) ;
F_9 ( V_5 , 0x0020 , ( V_12 << 4 ) | V_12 ) ;
F_9 ( V_5 , 0x0021 , ( V_12 << 4 ) | V_12 ) ;
F_10 ( V_5 , 0x0022 , 0x000F , ( V_12 << 4 ) ) ;
F_9 ( V_5 , 0x002A , ( V_12 << 4 ) ) ;
F_9 ( V_5 , 0x002B , ( V_12 << 4 ) ) ;
F_10 ( V_5 , 0x0008 , 0x00F0 , ( V_12 << 4 ) ) ;
F_10 ( V_5 , 0x0029 , 0xFF0F , 0x00B0 ) ;
F_9 ( V_5 , 0x0035 , 0x00AA ) ;
F_9 ( V_5 , 0x0036 , 0x0085 ) ;
F_10 ( V_5 , 0x003A , 0xFF20 , F_3 ( V_11 ) ) ;
F_11 ( V_5 , 0x003D , 0x00FF ) ;
F_10 ( V_5 , 0x0081 , 0xFF7F , 0x0080 ) ;
F_11 ( V_5 , 0x0035 , 0xFFEF ) ;
F_10 ( V_5 , 0x0035 , 0xFFEF , 0x0010 ) ;
F_4 ( V_5 ) ;
}
static void F_12 ( struct V_4 * V_5 )
{
F_9 ( V_5 , 0x0004 , 0x00C0 ) ;
F_9 ( V_5 , 0x0005 , 0x0008 ) ;
F_9 ( V_5 , 0x0009 , 0x0040 ) ;
F_9 ( V_5 , 0x0005 , 0x00AA ) ;
F_9 ( V_5 , 0x0032 , 0x008F ) ;
F_9 ( V_5 , 0x0006 , 0x008F ) ;
F_9 ( V_5 , 0x0034 , 0x008F ) ;
F_9 ( V_5 , 0x002C , 0x0007 ) ;
F_9 ( V_5 , 0x0082 , 0x0080 ) ;
F_9 ( V_5 , 0x0080 , 0x0000 ) ;
F_9 ( V_5 , 0x003F , 0x00DA ) ;
F_11 ( V_5 , 0x0005 , ~ 0x0008 ) ;
F_11 ( V_5 , 0x0081 , ~ 0x0010 ) ;
F_11 ( V_5 , 0x0081 , ~ 0x0020 ) ;
F_11 ( V_5 , 0x0081 , ~ 0x0020 ) ;
F_13 ( 1 ) ;
F_10 ( V_5 , 0x0081 , ~ 0x0020 , 0x0010 ) ;
F_13 ( 1 ) ;
F_10 ( V_5 , 0x0005 , ~ 0x0008 , 0x0008 ) ;
F_11 ( V_5 , 0x0085 , ~ 0x0010 ) ;
F_11 ( V_5 , 0x0005 , ~ 0x0008 ) ;
F_11 ( V_5 , 0x0081 , ~ 0x0040 ) ;
F_10 ( V_5 , 0x0081 , ~ 0x0040 , 0x0040 ) ;
F_9 ( V_5 , 0x0005 ,
( F_5 ( V_5 , 0x0081 ) & ~ 0x0008 ) | 0x0008 ) ;
F_6 ( V_5 , 0x0063 , 0xDDC6 ) ;
F_6 ( V_5 , 0x0069 , 0x07BE ) ;
F_6 ( V_5 , 0x006A , 0x0000 ) ;
F_7 ( V_5 , V_5 -> V_13 . V_14 -> V_15 ( V_5 ) ) ;
F_13 ( 1 ) ;
}
static void F_14 ( struct V_4 * V_5 , T_2 V_16 )
{
int V_9 ;
if ( V_5 -> V_13 . V_17 < 3 ) {
if ( V_16 )
for ( V_9 = 0 ; V_9 < V_18 ; V_9 ++ ) {
F_15 ( V_5 ,
V_19 , V_9 , 0xFFF8 ) ;
F_15 ( V_5 ,
V_20 , V_9 , 0xFFF8 ) ;
}
else
for ( V_9 = 0 ; V_9 < V_18 ; V_9 ++ ) {
F_15 ( V_5 ,
V_19 , V_9 , V_21 [ V_9 ] ) ;
F_15 ( V_5 ,
V_20 , V_9 , V_21 [ V_9 ] ) ;
}
} else {
if ( V_16 )
for ( V_9 = 0 ; V_9 < V_18 ; V_9 ++ )
F_15 ( V_5 ,
V_20 , V_9 , 0x0820 ) ;
else
for ( V_9 = 0 ; V_9 < V_22 ; V_9 ++ )
F_15 ( V_5 ,
V_20 , V_9 , V_23 [ V_9 ] ) ;
}
}
static void F_16 ( struct V_4 * V_5 )
{
T_1 V_24 , V_25 , V_26 = 0xFFFF ;
int V_9 ;
F_17 ( V_5 , V_27 , ~ V_28 ) ;
F_18 ( V_5 , F_19 ( 0x1B ) , 0x1000 ) ;
F_20 ( V_5 , F_19 ( 0x82 ) , 0xF0FF , 0x0300 ) ;
F_21 ( V_5 , 0x0009 , 0x0080 ) ;
F_10 ( V_5 , 0x0012 , 0xFFFC , 0x0002 ) ;
F_22 ( V_5 ) ;
F_6 ( V_5 , F_19 ( 0xBA ) , 0x3ED5 ) ;
V_24 = F_23 ( V_5 , V_29 ) ;
F_6 ( V_5 , V_29 , ( V_24 & 0xFFF8 ) | 0x0005 ) ;
F_21 ( V_5 , 0x0004 , 0x0004 ) ;
for ( V_9 = 0x10 ; V_9 <= 0x20 ; V_9 ++ ) {
F_9 ( V_5 , 0x0013 , V_9 ) ;
V_25 = F_23 ( V_5 , V_30 ) & 0x00FF ;
if ( ! V_25 ) {
V_26 = 0x0000 ;
break;
} else if ( V_25 >= 0x0080 )
V_25 = 0x0100 - V_25 ;
if ( V_25 < V_26 )
V_26 = V_25 ;
}
F_6 ( V_5 , V_29 , V_24 ) ;
F_11 ( V_5 , 0x0004 , 0xFFFB ) ;
F_9 ( V_5 , 0x0013 , V_26 ) ;
F_15 ( V_5 , V_31 , 0 , 0xFFEC ) ;
F_6 ( V_5 , F_19 ( 0xB7 ) , 0x1E80 ) ;
F_6 ( V_5 , F_19 ( 0xB6 ) , 0x1C00 ) ;
F_6 ( V_5 , F_19 ( 0xB5 ) , 0x0EC0 ) ;
F_6 ( V_5 , F_19 ( 0xB2 ) , 0x00C0 ) ;
F_6 ( V_5 , F_19 ( 0xB9 ) , 0x1FFF ) ;
F_20 ( V_5 , F_19 ( 0xBB ) , 0xF000 , 0x0053 ) ;
F_20 ( V_5 , V_32 , 0xFE1F , 0x0120 ) ;
F_20 ( V_5 , F_19 ( 0x13 ) , 0x0FFF , 0x3000 ) ;
F_20 ( V_5 , F_19 ( 0x14 ) , 0x0FFF , 0x3000 ) ;
F_15 ( V_5 , V_33 , 6 , 0x0017 ) ;
for ( V_9 = 0 ; V_9 < 6 ; V_9 ++ )
F_15 ( V_5 , V_33 , V_9 , 0x000F ) ;
F_15 ( V_5 , V_33 , 0x0D , 0x000E ) ;
F_15 ( V_5 , V_33 , 0x0E , 0x0011 ) ;
F_15 ( V_5 , V_33 , 0x0F , 0x0013 ) ;
F_6 ( V_5 , F_19 ( 0x33 ) , 0x5030 ) ;
F_18 ( V_5 , V_27 , V_28 ) ;
}
static void F_24 ( struct V_4 * V_5 )
{
}
void F_25 ( struct V_4 * V_5 )
{
struct V_34 * V_13 = & V_5 -> V_13 ;
F_2 ( ( V_13 -> type != V_35 ) &&
( V_13 -> type != V_36 ) ) ;
F_26 () ;
if ( V_13 -> V_17 >= 6 ) {
if ( V_13 -> type == V_35 )
F_17 ( V_5 , F_19 ( 0x1B ) , ~ 0x1000 ) ;
if ( F_23 ( V_5 , V_37 ) & V_38 )
F_18 ( V_5 , V_37 , 0x0010 ) ;
else
F_17 ( V_5 , V_37 , ~ 0x1010 ) ;
}
F_27 ( V_5 ) ;
if ( V_13 -> type == V_35 ) {
if ( V_13 -> V_39 && ( V_13 -> V_17 < 3 ) )
F_18 ( V_5 , 0x0034 , 0x0001 ) ;
F_14 ( V_5 , 0 ) ;
F_18 ( V_5 , V_27 , V_28 ) ;
F_12 ( V_5 ) ;
if ( ( V_5 -> V_5 -> V_40 == V_41 ) &&
( ( V_5 -> V_5 -> V_42 == V_43 ) ||
( V_5 -> V_5 -> V_42 == V_44 ) ) ) {
;
}
if ( V_13 -> V_17 >= 3 )
F_16 ( V_5 ) ;
F_24 ( V_5 ) ;
}
if ( ( V_13 -> type == V_36 ) &&
( V_5 -> V_5 -> V_45 -> V_46 & V_47 ) ) {
F_20 ( V_5 , F_19 ( 0x6E ) , 0xE000 , 0x3CF ) ;
}
}
static int F_28 ( struct V_4 * V_5 )
{
struct V_34 * V_13 = & V_5 -> V_13 ;
struct V_48 * V_49 = V_13 -> V_50 ;
T_3 V_51 , V_52 , V_53 ;
V_51 = ( T_3 ) ( V_5 -> V_5 -> V_45 -> V_54 ) ;
V_52 = ( T_3 ) ( V_5 -> V_5 -> V_45 -> V_55 ) ;
V_53 = ( T_3 ) ( V_5 -> V_5 -> V_45 -> V_56 ) ;
if ( V_51 != 0 && V_52 != 0 && V_53 != 0 &&
V_51 != - 1 && V_52 != - 1 && V_53 != - 1 ) {
if ( ( V_57 ) V_5 -> V_5 -> V_45 -> V_58 != 0 &&
( V_57 ) V_5 -> V_5 -> V_45 -> V_58 != - 1 )
V_49 -> V_59 =
( V_57 ) ( V_5 -> V_5 -> V_45 -> V_58 ) ;
else
V_49 -> V_59 = 62 ;
V_49 -> V_60 = F_29 ( V_5 , V_51 ,
V_52 , V_53 ) ;
if ( ! V_49 -> V_60 )
return - V_61 ;
} else {
V_49 -> V_60 = NULL ;
F_30 ( V_5 -> V_62 , L_1
L_2 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_31 ( struct V_4 * V_5 )
{
struct V_48 * V_49 ;
int V_64 ;
V_49 = F_32 ( sizeof( * V_49 ) , V_65 ) ;
if ( ! V_49 )
return - V_61 ;
V_5 -> V_13 . V_50 = V_49 ;
V_64 = F_28 ( V_5 ) ;
if ( V_64 )
goto V_66;
return 0 ;
V_66:
F_33 ( V_49 ) ;
V_5 -> V_13 . V_50 = NULL ;
return V_64 ;
}
static void F_34 ( struct V_4 * V_5 )
{
struct V_34 * V_13 = & V_5 -> V_13 ;
struct V_48 * V_49 = V_13 -> V_50 ;
const void * V_60 ;
int V_59 ;
V_60 = V_49 -> V_60 ;
V_59 = V_49 -> V_59 ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
V_49 -> V_60 = V_60 ;
V_49 -> V_59 = V_59 ;
}
static void F_35 ( struct V_4 * V_5 )
{
struct V_34 * V_13 = & V_5 -> V_13 ;
struct V_48 * V_49 = V_13 -> V_50 ;
F_33 ( V_49 -> V_60 ) ;
V_49 -> V_60 = NULL ;
F_33 ( V_49 ) ;
V_5 -> V_13 . V_50 = NULL ;
}
static int F_36 ( struct V_4 * V_5 )
{
F_25 ( V_5 ) ;
return 0 ;
}
static inline T_1 F_37 ( struct V_4 * V_5 , T_1 V_67 )
{
if ( ( V_67 & V_68 ) == V_69 ) {
V_67 &= ~ V_68 ;
V_67 |= V_70 ;
}
#if V_71
if ( ( V_67 & V_68 ) == V_72 ) {
F_30 ( V_5 -> V_62 , L_3
L_4 , V_67 ) ;
F_38 () ;
}
if ( ( V_67 & V_68 ) == V_73 ) {
F_30 ( V_5 -> V_62 , L_5
L_4 , V_67 ) ;
F_38 () ;
}
#endif
return V_67 ;
}
static T_1 F_39 ( struct V_4 * V_5 , T_1 V_74 )
{
V_74 = F_37 ( V_5 , V_74 ) ;
F_8 ( V_5 , V_75 , V_74 ) ;
return F_40 ( V_5 , V_76 ) ;
}
static void F_41 ( struct V_4 * V_5 , T_1 V_74 , T_1 V_3 )
{
V_74 = F_37 ( V_5 , V_74 ) ;
F_8 ( V_5 , V_75 , V_74 ) ;
F_8 ( V_5 , V_76 , V_3 ) ;
}
static T_1 F_42 ( struct V_4 * V_5 , T_1 V_74 )
{
F_2 ( V_74 == 1 ) ;
V_74 |= 0x40 ;
F_8 ( V_5 , V_77 , V_74 ) ;
return F_40 ( V_5 , V_78 ) ;
}
static void F_43 ( struct V_4 * V_5 , T_1 V_74 , T_1 V_3 )
{
F_2 ( V_74 == 1 ) ;
F_8 ( V_5 , V_77 , V_74 ) ;
F_8 ( V_5 , V_78 , V_3 ) ;
}
static bool F_44 ( struct V_4 * V_5 )
{
return ( V_5 -> V_13 . V_17 >= 5 ) ;
}
static void F_45 ( struct V_4 * V_5 ,
bool V_79 )
{
struct V_34 * V_13 = & V_5 -> V_13 ;
if ( ! V_79 ) {
if ( V_13 -> V_80 )
return;
F_9 ( V_5 , 0x0004 , 0x00C0 ) ;
F_9 ( V_5 , 0x0005 , 0x0008 ) ;
F_17 ( V_5 , 0x0010 , 0xFFF7 ) ;
F_17 ( V_5 , 0x0011 , 0xFFF7 ) ;
F_12 ( V_5 ) ;
} else {
F_9 ( V_5 , 0x0004 , 0x00FF ) ;
F_9 ( V_5 , 0x0005 , 0x00FB ) ;
F_18 ( V_5 , 0x0010 , 0x0008 ) ;
F_18 ( V_5 , 0x0011 , 0x0008 ) ;
}
}
static int F_46 ( struct V_4 * V_5 ,
unsigned int V_81 )
{
if ( V_81 > 200 )
return - V_82 ;
F_7 ( V_5 , V_81 ) ;
return 0 ;
}
static unsigned int F_47 ( struct V_4 * V_5 )
{
return 36 ;
}
static void F_48 ( struct V_4 * V_5 , int V_83 )
{
struct V_34 * V_13 = & V_5 -> V_13 ;
T_1 V_8 ;
int V_84 = 0 ;
if ( V_83 == V_85 || V_83 == V_86 )
V_84 = 1 ;
F_49 ( V_5 , F_50 ( V_5 ) & ~ V_87 ) ;
F_20 ( V_5 , V_88 , ~ V_89 ,
( V_84 ? V_86 : V_83 ) <<
V_90 ) ;
if ( V_84 ) {
V_8 = F_23 ( V_5 , V_91 ) ;
if ( V_83 == V_86 )
V_8 &= ~ V_92 ;
else
V_8 |= V_92 ;
F_6 ( V_5 , V_91 , V_8 ) ;
}
if ( V_13 -> V_17 < 3 )
F_20 ( V_5 , V_91 , 0xFF00 , 0x24 ) ;
else {
F_18 ( V_5 , V_32 , 0x10 ) ;
if ( V_13 -> V_17 == 3 ) {
F_6 ( V_5 , V_93 , 0x1D ) ;
F_6 ( V_5 , V_94 , 8 ) ;
} else {
F_6 ( V_5 , V_93 , 0x3A ) ;
F_20 ( V_5 , V_94 , 0xFF00 , 8 ) ;
}
}
F_49 ( V_5 , F_50 ( V_5 ) | V_87 ) ;
}
static void F_51 ( struct V_4 * V_5 )
{
}
static enum V_95 F_52 ( struct V_4 * V_5 ,
bool V_96 )
{
return V_97 ;
}
static void F_53 ( struct V_4 * V_5 )
{
}
static void F_54 ( struct V_4 * V_5 )
{
}
