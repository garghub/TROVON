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
V_16 -> V_27 . V_28 = V_29 + 1 ;
F_21 ( & V_16 -> V_27 ) ;
if ( V_16 -> V_26 >= ( int ) V_16 -> V_30 ) {
V_16 -> V_26 %= V_16 -> V_30 ;
F_22 ( & V_16 -> V_23 ) ;
F_23 ( V_16 -> V_31 ) ;
return;
}
F_22 ( & V_16 -> V_23 ) ;
}
static int F_24 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_25 ( V_33 ) ;
struct V_15 * V_16 ;
struct V_34 * V_35 = V_33 -> V_35 ;
V_16 = F_26 ( sizeof( * V_16 ) , V_36 ) ;
if ( ! V_16 )
return - V_37 ;
V_16 -> V_2 = V_2 ;
V_16 -> V_31 = V_33 ;
V_35 -> V_38 = V_16 ;
F_27 ( & V_16 -> V_23 ) ;
F_28 ( & V_16 -> V_27 ) ;
V_16 -> V_27 . V_39 = F_19 ;
V_16 -> V_27 . V_20 = ( unsigned long ) V_16 ;
V_35 -> V_40 = V_41 ;
V_35 -> V_40 . V_42 = V_2 -> V_43 - V_44 * 3 ;
V_35 -> V_40 . V_45 = V_35 -> V_40 . V_42 / 2 ;
F_29 ( V_35 , V_46 ,
( 1000000 + V_47 - 1 ) / V_47 , V_48 ) ;
return 0 ;
}
static int F_30 ( struct V_32 * V_33 )
{
struct V_15 * V_16 = V_33 -> V_35 -> V_38 ;
F_31 ( V_16 ) ;
V_33 -> V_35 -> V_38 = NULL ;
return 0 ;
}
static int F_32 ( int V_49 )
{
int V_50 = 1 << ( V_49 >> 12 ) ;
if ( V_49 & 0x800 ) V_50 += ( V_50 * 0x102e ) / 0x2710 ;
if ( V_49 & 0x400 ) V_50 += ( V_50 * 0x764 ) / 0x2710 ;
if ( V_49 & 0x200 ) V_50 += ( V_50 * 0x389 ) / 0x2710 ;
V_50 += ( V_50 >> 1 ) ;
if ( V_50 > 0xffff ) V_50 = 0xffff ;
return V_50 ;
}
static void F_33 ( struct V_15 * V_16 , int V_17 )
{
struct V_1 * V_40 = V_16 -> V_2 ;
unsigned int V_51 ;
F_34 ( V_40 , V_17 , 0x0080 ) ;
F_5 ( V_40 , V_17 , 0x0000FFFF ) ;
F_35 ( V_40 , V_17 , 0x0000FFFF ) ;
F_36 ( V_40 , V_17 , 0 ) ;
F_37 ( V_40 , V_17 , 0 ) ;
F_38 ( V_40 , V_17 , V_16 -> V_49 ) ;
F_39 ( V_40 , V_17 , 0x8000 ) ;
F_40 ( V_40 , V_17 , 0x7f7f ) ;
F_41 ( V_40 , V_17 , 0x7f7f ) ;
F_42 ( V_40 , V_17 , 0x8000 ) ;
F_43 ( V_40 , V_17 , 0x7f7f ) ;
F_44 ( V_40 , V_17 , 0x0 ) ;
F_45 ( V_40 , V_17 , 0x8000 ) ;
F_46 ( V_40 , V_17 , 0x8000 ) ;
F_47 ( V_40 , V_17 , 0 ) ;
F_48 ( V_40 , V_17 , 0 ) ;
F_49 ( V_40 , V_17 , 0 ) ;
V_51 = V_16 -> V_52 [ V_17 ] ;
V_51 = ( V_51 << 24 ) | ( ( unsigned int ) V_16 -> V_19 [ V_17 ] - 1 ) ;
F_6 ( V_40 , V_17 , V_51 ) ;
V_51 = 0 ;
V_51 = ( V_51 << 24 ) | ( ( unsigned int ) V_16 -> V_19 [ V_17 ] + V_16 -> V_25 - 1 ) ;
F_7 ( V_40 , V_17 , V_51 ) ;
V_51 = 0 ;
V_51 = ( V_51 << 28 ) | ( ( unsigned int ) V_16 -> V_19 [ V_17 ] - 1 ) ;
F_8 ( V_40 , V_17 , V_51 ) ;
F_50 ( V_40 , V_17 , 0 ) ;
F_51 ( V_40 , V_17 , 0 ) ;
}
static void F_52 ( struct V_15 * V_16 , int V_17 )
{
unsigned long V_53 ;
struct V_1 * V_40 = V_16 -> V_2 ;
unsigned int V_51 , V_54 ;
int V_55 = F_32 ( V_16 -> V_49 ) ;
F_53 ( V_40 , V_17 , 0xff00 ) ;
F_5 ( V_40 , V_17 , 0xffff ) ;
F_35 ( V_40 , V_17 , 0xffff ) ;
F_34 ( V_40 , V_17 , 0x7f7f ) ;
V_51 = 0 ;
if ( V_16 -> V_52 [ V_17 ] == 0 )
V_54 = 0xff ;
else
V_54 = ( - V_16 -> V_52 [ V_17 ] ) & 0xff ;
V_51 = ( V_51 << 8 ) | ( V_55 << 16 ) | V_54 ;
F_36 ( V_40 , V_17 , V_51 ) ;
F_37 ( V_40 , V_17 , V_55 << 16 ) ;
F_54 ( & V_16 -> V_23 , V_53 ) ;
if ( ! V_16 -> V_56 ) {
V_16 -> V_27 . V_28 = V_29 + 1 ;
F_21 ( & V_16 -> V_27 ) ;
V_16 -> V_56 = 1 ;
}
F_55 ( & V_16 -> V_23 , V_53 ) ;
}
static void F_56 ( struct V_15 * V_16 , int V_17 )
{
unsigned long V_53 ;
struct V_1 * V_40 = V_16 -> V_2 ;
F_34 ( V_40 , V_17 , 0x807F ) ;
F_54 ( & V_16 -> V_23 , V_53 ) ;
if ( V_16 -> V_56 ) {
F_57 ( & V_16 -> V_27 ) ;
V_16 -> V_56 = 0 ;
}
F_55 ( & V_16 -> V_23 , V_53 ) ;
}
static int F_58 ( struct V_32 * V_33 , int V_57 )
{
struct V_15 * V_16 = V_33 -> V_35 -> V_38 ;
int V_17 ;
switch ( V_57 ) {
case V_58 :
for ( V_17 = 0 ; V_17 < V_16 -> V_59 ; V_17 ++ )
F_52 ( V_16 , V_17 ) ;
V_16 -> V_60 = 1 ;
break;
case V_61 :
V_16 -> V_60 = 0 ;
for ( V_17 = 0 ; V_17 < V_16 -> V_59 ; V_17 ++ )
F_56 ( V_16 , V_17 ) ;
break;
default:
return - V_62 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , int V_63 , unsigned short * V_64 , int V_65 )
{
F_60 ( V_2 , V_63 ) ;
while ( V_65 > 0 ) {
unsigned short V_66 ;
F_61 () ;
if ( F_62 ( V_66 , V_64 ) )
return - V_67 ;
F_63 ( V_2 , V_66 ) ;
V_64 ++ ;
V_65 -- ;
}
return 0 ;
}
static int F_64 ( struct V_32 * V_33 ,
int V_68 ,
T_1 V_69 ,
void * V_70 ,
T_1 V_65 )
{
struct V_15 * V_16 = V_33 -> V_35 -> V_38 ;
struct V_1 * V_2 = V_16 -> V_2 ;
F_9 ( V_2 , 1 ) ;
if ( V_68 == - 1 ) {
unsigned short * V_64 = V_70 ;
int V_4 , V_71 ;
V_65 /= V_16 -> V_59 ;
for ( V_4 = 0 ; V_4 < V_16 -> V_59 ; V_4 ++ ) {
V_71 = F_59 ( V_2 , V_69 + V_16 -> V_19 [ V_4 ] , V_64 , V_65 ) ;
if ( V_71 < 0 )
return V_71 ;
V_64 += V_65 ;
}
return 0 ;
} else {
return F_59 ( V_2 , V_69 + V_16 -> V_19 [ V_68 ] , V_70 , V_65 ) ;
}
}
static int F_65 ( struct V_1 * V_2 , int V_63 , int V_65 )
{
F_60 ( V_2 , V_63 ) ;
while ( V_65 > 0 ) {
F_61 () ;
F_63 ( V_2 , 0 ) ;
V_65 -- ;
}
return 0 ;
}
static int F_66 ( struct V_32 * V_33 ,
int V_68 ,
T_1 V_69 ,
T_1 V_65 )
{
struct V_15 * V_16 = V_33 -> V_35 -> V_38 ;
struct V_1 * V_2 = V_16 -> V_2 ;
F_9 ( V_2 , 1 ) ;
if ( V_68 == - 1 && V_16 -> V_59 == 1 )
V_68 = 0 ;
if ( V_68 == - 1 ) {
int V_71 ;
V_71 = F_65 ( V_2 , V_69 + V_16 -> V_19 [ 0 ] , V_65 / 2 ) ;
if ( V_71 < 0 )
return V_71 ;
return F_65 ( V_2 , V_69 + V_16 -> V_19 [ 1 ] , V_65 / 2 ) ;
} else {
return F_65 ( V_2 , V_69 + V_16 -> V_19 [ V_68 ] , V_65 ) ;
}
}
static int F_64 ( struct V_32 * V_33 ,
int V_68 ,
T_1 V_69 ,
void T_2 * V_70 ,
T_1 V_65 )
{
struct V_15 * V_16 = V_33 -> V_35 -> V_38 ;
struct V_1 * V_2 = V_16 -> V_2 ;
unsigned short T_2 * V_64 = V_70 ;
F_9 ( V_2 , 1 ) ;
F_60 ( V_2 , V_69 + V_16 -> V_19 [ 0 ] ) ;
if ( V_16 -> V_59 > 1 )
F_67 ( V_2 , V_69 + V_16 -> V_19 [ 1 ] ) ;
while ( V_65 -- > 0 ) {
unsigned short V_66 ;
F_61 () ;
if ( F_62 ( V_66 , V_64 ) )
return - V_67 ;
F_63 ( V_2 , V_66 ) ;
V_64 ++ ;
if ( V_16 -> V_59 > 1 ) {
F_61 () ;
if ( F_62 ( V_66 , V_64 ) )
return - V_67 ;
F_68 ( V_2 , V_66 ) ;
V_64 ++ ;
}
}
return 0 ;
}
static int F_66 ( struct V_32 * V_33 ,
int V_68 ,
T_1 V_69 ,
T_1 V_65 )
{
struct V_15 * V_16 = V_33 -> V_35 -> V_38 ;
struct V_1 * V_2 = V_16 -> V_2 ;
F_9 ( V_2 , 1 ) ;
F_60 ( V_2 , V_16 -> V_19 [ 0 ] + V_69 ) ;
if ( V_16 -> V_59 > 1 )
F_67 ( V_2 , V_16 -> V_19 [ 1 ] + V_69 ) ;
while ( V_65 -- > 0 ) {
F_61 () ;
F_63 ( V_2 , 0 ) ;
if ( V_16 -> V_59 > 1 ) {
F_61 () ;
F_68 ( V_2 , 0 ) ;
}
}
return 0 ;
}
static int F_69 ( struct V_32 * V_33 ,
struct V_72 * V_73 )
{
struct V_15 * V_16 = V_33 -> V_35 -> V_38 ;
if ( V_16 -> V_74 ) {
F_70 ( V_16 -> V_2 -> V_75 , V_16 -> V_74 ) ;
V_16 -> V_74 = NULL ;
}
V_16 -> V_76 = F_71 ( V_73 ) + V_44 * 4 ;
V_16 -> V_74 = F_72 ( V_16 -> V_2 -> V_75 , V_16 -> V_76 ) ;
if ( ! V_16 -> V_74 )
return - V_37 ;
V_16 -> V_63 = V_77 + ( V_16 -> V_74 -> V_63 >> 1 ) ;
V_33 -> V_78 . V_79 = F_71 ( V_73 ) ;
return 0 ;
}
static int F_73 ( struct V_32 * V_33 )
{
struct V_15 * V_16 = V_33 -> V_35 -> V_38 ;
if ( V_16 -> V_74 ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_16 -> V_59 ; V_17 ++ )
F_56 ( V_16 , V_17 ) ;
if ( V_16 -> V_80 )
F_13 ( V_16 -> V_2 ) ;
F_70 ( V_16 -> V_2 -> V_75 , V_16 -> V_74 ) ;
V_16 -> V_74 = NULL ;
}
return 0 ;
}
static int F_74 ( struct V_32 * V_33 )
{
struct V_15 * V_16 = V_33 -> V_35 -> V_38 ;
V_16 -> V_49 = 0xe000 + F_15 ( V_33 -> V_35 -> V_81 ) ;
V_16 -> V_24 = 0 ;
V_16 -> V_26 = 0 ;
V_16 -> V_25 = V_33 -> V_35 -> V_82 ;
V_16 -> V_30 = V_33 -> V_35 -> V_30 ;
V_16 -> V_59 = V_33 -> V_35 -> V_3 ;
V_16 -> V_19 [ 0 ] = V_16 -> V_63 + V_44 ;
if ( V_16 -> V_59 > 1 )
V_16 -> V_19 [ 1 ] = V_16 -> V_19 [ 0 ] + V_16 -> V_25 + V_44 ;
if ( V_16 -> V_59 > 1 ) {
V_16 -> V_52 [ 0 ] = 0xff ;
V_16 -> V_52 [ 1 ] = 0x00 ;
} else
V_16 -> V_52 [ 0 ] = 0x80 ;
if ( ! V_16 -> V_80 ) {
int V_71 , V_4 , V_17 ;
F_75 ( V_16 -> V_2 -> V_2 ) ;
if ( ( V_71 = F_1 ( V_16 -> V_2 , V_16 -> V_59 ) ) != 0 )
return V_71 ;
V_16 -> V_80 = 1 ;
F_9 ( V_16 -> V_2 , 0 ) ;
F_60 ( V_16 -> V_2 , V_16 -> V_63 ) ;
for ( V_4 = 0 ; V_4 < V_44 ; V_4 ++ )
F_63 ( V_16 -> V_2 , 0 ) ;
for ( V_17 = 0 ; V_17 < V_16 -> V_59 ; V_17 ++ ) {
F_60 ( V_16 -> V_2 , V_16 -> V_19 [ V_17 ] + V_16 -> V_25 ) ;
for ( V_4 = 0 ; V_4 < V_44 ; V_4 ++ )
F_63 ( V_16 -> V_2 , 0 ) ;
}
}
F_33 ( V_16 , 0 ) ;
if ( V_16 -> V_59 > 1 )
F_33 ( V_16 , 1 ) ;
return 0 ;
}
static T_1 F_76 ( struct V_32 * V_33 )
{
struct V_15 * V_16 = V_33 -> V_35 -> V_38 ;
if ( V_16 -> V_60 )
return F_17 ( V_16 , 0 ) ;
return 0 ;
}
static void F_77 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = V_84 -> V_38 ;
V_2 -> V_84 = NULL ;
}
int F_78 ( struct V_85 * V_86 , struct V_1 * V_2 , int V_87 )
{
struct V_83 * V_84 ;
int V_71 ;
if ( ( V_71 = F_79 ( V_86 , L_1 , V_87 , 1 , 0 , & V_84 ) ) < 0 )
return V_71 ;
V_84 -> V_38 = V_2 ;
V_84 -> V_88 = F_77 ;
F_80 ( V_84 , V_89 , & V_90 ) ;
V_2 -> V_84 = V_84 ;
F_81 ( V_86 , V_84 ) ;
return 0 ;
}
