static int
F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
F_2 ( V_2 -> V_2 , 0 ) ;
if ( V_3 > 1 )
F_2 ( V_2 -> V_2 , 1 ) ;
for ( V_4 = V_3 + 1 ; V_4 < V_5 ; V_4 ++ ) {
unsigned int V_6 = V_7 ;
F_2 ( V_2 -> V_2 , V_4 ) ;
#ifndef F_3
if ( V_3 > 1 && ( V_4 & 1 ) != 0 )
V_6 |= V_8 ;
#endif
F_4 ( V_2 , V_4 , V_6 ) ;
}
F_5 ( V_2 , 30 , 0 ) ;
F_6 ( V_2 , 30 , 0x1d8 ) ;
F_7 ( V_2 , 30 , 0x1e0 ) ;
F_8 ( V_2 , 30 , 0x1d8 ) ;
F_5 ( V_2 , 31 , 0 ) ;
F_6 ( V_2 , 31 , 0x1d8 ) ;
F_7 ( V_2 , 31 , 0x1e0 ) ;
F_8 ( V_2 , 31 , 0x1d8 ) ;
return 0 ;
}
static void
F_9 ( struct V_1 * V_2 , int V_9 )
{
while ( ( F_10 ( V_2 ) & 0x80000000 ) != 0 ) {
if ( V_9 ) {
F_11 ( 1 ) ;
if ( F_12 ( V_10 ) )
break;
}
}
}
static void
F_13 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ )
F_14 ( V_2 -> V_2 , V_4 ) ;
for (; V_4 < V_5 ; V_4 ++ ) {
F_4 ( V_2 , V_4 , V_11 ) ;
F_14 ( V_2 -> V_2 , V_4 ) ;
}
}
static int F_15 ( int V_12 )
{
return F_16 ( V_12 , V_13 , V_14 ) ;
}
static inline int F_17 ( struct V_15 * V_16 , int V_17 )
{
int V_18 = F_18 ( V_16 -> V_2 , V_17 ) & 0xfffffff ;
V_18 -= V_16 -> V_19 [ V_17 ] - 1 ;
return V_18 ;
}
static void F_19 ( unsigned long V_20 )
{
struct V_15 * V_16 = (struct V_15 * ) V_20 ;
int V_21 , V_22 ;
F_20 ( & V_16 -> V_23 ) ;
V_21 = F_17 ( V_16 , 0 ) ;
if ( V_21 < V_16 -> V_24 )
V_22 = V_21 + V_16 -> V_25 - V_16 -> V_24 ;
else
V_22 = V_21 - V_16 -> V_24 ;
V_16 -> V_26 += V_22 ;
V_16 -> V_24 = V_21 ;
F_21 ( & V_16 -> V_27 , V_28 + 1 ) ;
if ( V_16 -> V_26 >= ( int ) V_16 -> V_29 ) {
V_16 -> V_26 %= V_16 -> V_29 ;
F_22 ( & V_16 -> V_23 ) ;
F_23 ( V_16 -> V_30 ) ;
return;
}
F_22 ( & V_16 -> V_23 ) ;
}
static int F_24 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_25 ( V_32 ) ;
struct V_15 * V_16 ;
struct V_33 * V_34 = V_32 -> V_34 ;
V_16 = F_26 ( sizeof( * V_16 ) , V_35 ) ;
if ( ! V_16 )
return - V_36 ;
V_16 -> V_2 = V_2 ;
V_16 -> V_30 = V_32 ;
V_34 -> V_37 = V_16 ;
F_27 ( & V_16 -> V_23 ) ;
F_28 ( & V_16 -> V_27 , F_19 , ( unsigned long ) V_16 ) ;
V_34 -> V_38 = V_39 ;
V_34 -> V_38 . V_40 = V_2 -> V_41 - V_42 * 3 ;
V_34 -> V_38 . V_43 = V_34 -> V_38 . V_40 / 2 ;
F_29 ( V_34 , V_44 ,
( 1000000 + V_45 - 1 ) / V_45 , V_46 ) ;
return 0 ;
}
static int F_30 ( struct V_31 * V_32 )
{
struct V_15 * V_16 = V_32 -> V_34 -> V_37 ;
F_31 ( V_16 ) ;
V_32 -> V_34 -> V_37 = NULL ;
return 0 ;
}
static int F_32 ( int V_47 )
{
int V_48 = 1 << ( V_47 >> 12 ) ;
if ( V_47 & 0x800 ) V_48 += ( V_48 * 0x102e ) / 0x2710 ;
if ( V_47 & 0x400 ) V_48 += ( V_48 * 0x764 ) / 0x2710 ;
if ( V_47 & 0x200 ) V_48 += ( V_48 * 0x389 ) / 0x2710 ;
V_48 += ( V_48 >> 1 ) ;
if ( V_48 > 0xffff ) V_48 = 0xffff ;
return V_48 ;
}
static void F_33 ( struct V_15 * V_16 , int V_17 )
{
struct V_1 * V_38 = V_16 -> V_2 ;
unsigned int V_49 ;
F_34 ( V_38 , V_17 , 0x0080 ) ;
F_5 ( V_38 , V_17 , 0x0000FFFF ) ;
F_35 ( V_38 , V_17 , 0x0000FFFF ) ;
F_36 ( V_38 , V_17 , 0 ) ;
F_37 ( V_38 , V_17 , 0 ) ;
F_38 ( V_38 , V_17 , V_16 -> V_47 ) ;
F_39 ( V_38 , V_17 , 0x8000 ) ;
F_40 ( V_38 , V_17 , 0x7f7f ) ;
F_41 ( V_38 , V_17 , 0x7f7f ) ;
F_42 ( V_38 , V_17 , 0x8000 ) ;
F_43 ( V_38 , V_17 , 0x7f7f ) ;
F_44 ( V_38 , V_17 , 0x0 ) ;
F_45 ( V_38 , V_17 , 0x8000 ) ;
F_46 ( V_38 , V_17 , 0x8000 ) ;
F_47 ( V_38 , V_17 , 0 ) ;
F_48 ( V_38 , V_17 , 0 ) ;
F_49 ( V_38 , V_17 , 0 ) ;
V_49 = V_16 -> V_50 [ V_17 ] ;
V_49 = ( V_49 << 24 ) | ( ( unsigned int ) V_16 -> V_19 [ V_17 ] - 1 ) ;
F_6 ( V_38 , V_17 , V_49 ) ;
V_49 = 0 ;
V_49 = ( V_49 << 24 ) | ( ( unsigned int ) V_16 -> V_19 [ V_17 ] + V_16 -> V_25 - 1 ) ;
F_7 ( V_38 , V_17 , V_49 ) ;
V_49 = 0 ;
V_49 = ( V_49 << 28 ) | ( ( unsigned int ) V_16 -> V_19 [ V_17 ] - 1 ) ;
F_8 ( V_38 , V_17 , V_49 ) ;
F_50 ( V_38 , V_17 , 0 ) ;
F_51 ( V_38 , V_17 , 0 ) ;
}
static void F_52 ( struct V_15 * V_16 , int V_17 )
{
unsigned long V_51 ;
struct V_1 * V_38 = V_16 -> V_2 ;
unsigned int V_49 , V_52 ;
int V_53 = F_32 ( V_16 -> V_47 ) ;
F_53 ( V_38 , V_17 , 0xff00 ) ;
F_5 ( V_38 , V_17 , 0xffff ) ;
F_35 ( V_38 , V_17 , 0xffff ) ;
F_34 ( V_38 , V_17 , 0x7f7f ) ;
V_49 = 0 ;
if ( V_16 -> V_50 [ V_17 ] == 0 )
V_52 = 0xff ;
else
V_52 = ( - V_16 -> V_50 [ V_17 ] ) & 0xff ;
V_49 = ( V_49 << 8 ) | ( V_53 << 16 ) | V_52 ;
F_36 ( V_38 , V_17 , V_49 ) ;
F_37 ( V_38 , V_17 , V_53 << 16 ) ;
F_54 ( & V_16 -> V_23 , V_51 ) ;
if ( ! V_16 -> V_54 ) {
F_21 ( & V_16 -> V_27 , V_28 + 1 ) ;
V_16 -> V_54 = 1 ;
}
F_55 ( & V_16 -> V_23 , V_51 ) ;
}
static void F_56 ( struct V_15 * V_16 , int V_17 )
{
unsigned long V_51 ;
struct V_1 * V_38 = V_16 -> V_2 ;
F_34 ( V_38 , V_17 , 0x807F ) ;
F_54 ( & V_16 -> V_23 , V_51 ) ;
if ( V_16 -> V_54 ) {
F_57 ( & V_16 -> V_27 ) ;
V_16 -> V_54 = 0 ;
}
F_55 ( & V_16 -> V_23 , V_51 ) ;
}
static int F_58 ( struct V_31 * V_32 , int V_55 )
{
struct V_15 * V_16 = V_32 -> V_34 -> V_37 ;
int V_17 ;
switch ( V_55 ) {
case V_56 :
for ( V_17 = 0 ; V_17 < V_16 -> V_57 ; V_17 ++ )
F_52 ( V_16 , V_17 ) ;
V_16 -> V_58 = 1 ;
break;
case V_59 :
V_16 -> V_58 = 0 ;
for ( V_17 = 0 ; V_17 < V_16 -> V_57 ; V_17 ++ )
F_56 ( V_16 , V_17 ) ;
break;
default:
return - V_60 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , int V_61 , unsigned short * V_62 , int V_63 )
{
F_60 ( V_2 , V_61 ) ;
while ( V_63 > 0 ) {
unsigned short V_64 ;
F_61 () ;
if ( F_62 ( V_64 , V_62 ) )
return - V_65 ;
F_63 ( V_2 , V_64 ) ;
V_62 ++ ;
V_63 -- ;
}
return 0 ;
}
static int F_64 ( struct V_31 * V_32 ,
int V_66 ,
T_1 V_67 ,
void * V_68 ,
T_1 V_63 )
{
struct V_15 * V_16 = V_32 -> V_34 -> V_37 ;
struct V_1 * V_2 = V_16 -> V_2 ;
F_9 ( V_2 , 1 ) ;
if ( V_66 == - 1 ) {
unsigned short * V_62 = V_68 ;
int V_4 , V_69 ;
V_63 /= V_16 -> V_57 ;
for ( V_4 = 0 ; V_4 < V_16 -> V_57 ; V_4 ++ ) {
V_69 = F_59 ( V_2 , V_67 + V_16 -> V_19 [ V_4 ] , V_62 , V_63 ) ;
if ( V_69 < 0 )
return V_69 ;
V_62 += V_63 ;
}
return 0 ;
} else {
return F_59 ( V_2 , V_67 + V_16 -> V_19 [ V_66 ] , V_68 , V_63 ) ;
}
}
static int F_65 ( struct V_1 * V_2 , int V_61 , int V_63 )
{
F_60 ( V_2 , V_61 ) ;
while ( V_63 > 0 ) {
F_61 () ;
F_63 ( V_2 , 0 ) ;
V_63 -- ;
}
return 0 ;
}
static int F_66 ( struct V_31 * V_32 ,
int V_66 ,
T_1 V_67 ,
T_1 V_63 )
{
struct V_15 * V_16 = V_32 -> V_34 -> V_37 ;
struct V_1 * V_2 = V_16 -> V_2 ;
F_9 ( V_2 , 1 ) ;
if ( V_66 == - 1 && V_16 -> V_57 == 1 )
V_66 = 0 ;
if ( V_66 == - 1 ) {
int V_69 ;
V_69 = F_65 ( V_2 , V_67 + V_16 -> V_19 [ 0 ] , V_63 / 2 ) ;
if ( V_69 < 0 )
return V_69 ;
return F_65 ( V_2 , V_67 + V_16 -> V_19 [ 1 ] , V_63 / 2 ) ;
} else {
return F_65 ( V_2 , V_67 + V_16 -> V_19 [ V_66 ] , V_63 ) ;
}
}
static int F_64 ( struct V_31 * V_32 ,
int V_66 ,
T_1 V_67 ,
void T_2 * V_68 ,
T_1 V_63 )
{
struct V_15 * V_16 = V_32 -> V_34 -> V_37 ;
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned short T_2 * V_62 = V_68 ;
F_9 ( V_2 , 1 ) ;
F_60 ( V_2 , V_67 + V_16 -> V_19 [ 0 ] ) ;
if ( V_16 -> V_57 > 1 )
F_67 ( V_2 , V_67 + V_16 -> V_19 [ 1 ] ) ;
while ( V_63 -- > 0 ) {
unsigned short V_64 ;
F_61 () ;
if ( F_62 ( V_64 , V_62 ) )
return - V_65 ;
F_63 ( V_2 , V_64 ) ;
V_62 ++ ;
if ( V_16 -> V_57 > 1 ) {
F_61 () ;
if ( F_62 ( V_64 , V_62 ) )
return - V_65 ;
F_68 ( V_2 , V_64 ) ;
V_62 ++ ;
}
}
return 0 ;
}
static int F_66 ( struct V_31 * V_32 ,
int V_66 ,
T_1 V_67 ,
T_1 V_63 )
{
struct V_15 * V_16 = V_32 -> V_34 -> V_37 ;
struct V_1 * V_2 = V_16 -> V_2 ;
F_9 ( V_2 , 1 ) ;
F_60 ( V_2 , V_16 -> V_19 [ 0 ] + V_67 ) ;
if ( V_16 -> V_57 > 1 )
F_67 ( V_2 , V_16 -> V_19 [ 1 ] + V_67 ) ;
while ( V_63 -- > 0 ) {
F_61 () ;
F_63 ( V_2 , 0 ) ;
if ( V_16 -> V_57 > 1 ) {
F_61 () ;
F_68 ( V_2 , 0 ) ;
}
}
return 0 ;
}
static int F_69 ( struct V_31 * V_32 ,
struct V_70 * V_71 )
{
struct V_15 * V_16 = V_32 -> V_34 -> V_37 ;
if ( V_16 -> V_72 ) {
F_70 ( V_16 -> V_2 -> V_73 , V_16 -> V_72 ) ;
V_16 -> V_72 = NULL ;
}
V_16 -> V_74 = F_71 ( V_71 ) + V_42 * 4 ;
V_16 -> V_72 = F_72 ( V_16 -> V_2 -> V_73 , V_16 -> V_74 ) ;
if ( ! V_16 -> V_72 )
return - V_36 ;
V_16 -> V_61 = V_75 + ( V_16 -> V_72 -> V_61 >> 1 ) ;
V_32 -> V_76 . V_77 = F_71 ( V_71 ) ;
return 0 ;
}
static int F_73 ( struct V_31 * V_32 )
{
struct V_15 * V_16 = V_32 -> V_34 -> V_37 ;
if ( V_16 -> V_72 ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_16 -> V_57 ; V_17 ++ )
F_56 ( V_16 , V_17 ) ;
if ( V_16 -> V_78 )
F_13 ( V_16 -> V_2 ) ;
F_70 ( V_16 -> V_2 -> V_73 , V_16 -> V_72 ) ;
V_16 -> V_72 = NULL ;
}
return 0 ;
}
static int F_74 ( struct V_31 * V_32 )
{
struct V_15 * V_16 = V_32 -> V_34 -> V_37 ;
V_16 -> V_47 = 0xe000 + F_15 ( V_32 -> V_34 -> V_79 ) ;
V_16 -> V_24 = 0 ;
V_16 -> V_26 = 0 ;
V_16 -> V_25 = V_32 -> V_34 -> V_80 ;
V_16 -> V_29 = V_32 -> V_34 -> V_29 ;
V_16 -> V_57 = V_32 -> V_34 -> V_3 ;
V_16 -> V_19 [ 0 ] = V_16 -> V_61 + V_42 ;
if ( V_16 -> V_57 > 1 )
V_16 -> V_19 [ 1 ] = V_16 -> V_19 [ 0 ] + V_16 -> V_25 + V_42 ;
if ( V_16 -> V_57 > 1 ) {
V_16 -> V_50 [ 0 ] = 0xff ;
V_16 -> V_50 [ 1 ] = 0x00 ;
} else
V_16 -> V_50 [ 0 ] = 0x80 ;
if ( ! V_16 -> V_78 ) {
int V_69 , V_4 , V_17 ;
F_75 ( V_16 -> V_2 -> V_2 ) ;
if ( ( V_69 = F_1 ( V_16 -> V_2 , V_16 -> V_57 ) ) != 0 )
return V_69 ;
V_16 -> V_78 = 1 ;
F_9 ( V_16 -> V_2 , 0 ) ;
F_60 ( V_16 -> V_2 , V_16 -> V_61 ) ;
for ( V_4 = 0 ; V_4 < V_42 ; V_4 ++ )
F_63 ( V_16 -> V_2 , 0 ) ;
for ( V_17 = 0 ; V_17 < V_16 -> V_57 ; V_17 ++ ) {
F_60 ( V_16 -> V_2 , V_16 -> V_19 [ V_17 ] + V_16 -> V_25 ) ;
for ( V_4 = 0 ; V_4 < V_42 ; V_4 ++ )
F_63 ( V_16 -> V_2 , 0 ) ;
}
}
F_33 ( V_16 , 0 ) ;
if ( V_16 -> V_57 > 1 )
F_33 ( V_16 , 1 ) ;
return 0 ;
}
static T_1 F_76 ( struct V_31 * V_32 )
{
struct V_15 * V_16 = V_32 -> V_34 -> V_37 ;
if ( V_16 -> V_58 )
return F_17 ( V_16 , 0 ) ;
return 0 ;
}
static void F_77 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_37 ;
V_2 -> V_82 = NULL ;
}
int F_78 ( struct V_83 * V_84 , struct V_1 * V_2 , int V_85 )
{
struct V_81 * V_82 ;
int V_69 ;
if ( ( V_69 = F_79 ( V_84 , L_1 , V_85 , 1 , 0 , & V_82 ) ) < 0 )
return V_69 ;
V_82 -> V_37 = V_2 ;
V_82 -> V_86 = F_77 ;
F_80 ( V_82 , V_87 , & V_88 ) ;
V_2 -> V_82 = V_82 ;
F_81 ( V_84 , V_82 ) ;
return 0 ;
}
