static int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 , unsigned char * V_5 )
{
struct V_6 V_7 [] = {
{
. V_8 = V_2 -> V_8 ,
. V_9 = 1 ,
. V_5 = & V_3 ,
} ,
{
. V_8 = V_2 -> V_8 ,
. V_10 = V_11 ,
. V_9 = V_4 ,
. V_5 = V_5
} ,
} ;
if ( ( F_2 ( V_2 -> V_12 , V_7 , 2 ) ) != 2 ) {
F_3 ( & V_2 -> V_13 , L_1 , V_14 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned char V_3 , unsigned char V_4 ,
unsigned char * V_5 )
{
int V_16 , V_17 ;
for ( V_16 = 0 ; V_16 < V_4 ; V_16 ++ ) {
unsigned char V_18 [ 2 ] = { V_3 + V_16 , V_5 [ V_16 ] } ;
V_17 = F_5 ( V_2 , V_18 , sizeof( V_18 ) ) ;
if ( V_17 != sizeof( V_18 ) ) {
F_3 ( & V_2 -> V_13 ,
L_2 ,
V_14 , V_17 , V_18 [ 0 ] , V_18 [ 1 ] ) ;
return - V_15 ;
}
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , bool V_19 )
{
unsigned char V_5 ;
int V_17 ;
V_17 = F_1 ( V_2 , V_20 , 1 , & V_5 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_19 )
V_5 |= V_21 ;
else
V_5 &= ~ V_21 ;
V_5 &= ~ ( V_22 | V_23 ) ;
V_17 = F_4 ( V_2 , V_20 , 1 , & V_5 ) ;
if ( V_17 < 0 ) {
F_3 ( & V_2 -> V_13 , L_3 , V_14 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned char * V_24 ,
unsigned char * V_25 )
{
unsigned char V_5 ;
int V_17 ;
V_17 = F_1 ( V_2 , V_20 , 1 , & V_5 ) ;
if ( V_17 )
return V_17 ;
if ( V_24 )
* V_24 = ! ! ( V_5 & V_21 ) ;
if ( V_25 )
* V_25 = ! ! ( V_5 & V_22 ) ;
return 0 ;
}
static T_1 F_8 ( int V_26 , void * V_27 )
{
struct V_28 * V_28 = F_9 ( V_27 ) ;
int V_17 ;
char V_29 ;
V_17 = F_7 ( V_28 -> V_2 , NULL , & V_29 ) ;
if ( V_17 )
return V_30 ;
if ( V_29 ) {
F_10 ( V_28 -> V_31 , 1 , V_32 | V_33 ) ;
F_6 ( V_28 -> V_2 , 1 ) ;
return V_34 ;
}
return V_30 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_28 * V_28 = F_9 ( V_2 ) ;
unsigned char V_5 [ 9 ] ;
int V_17 ;
V_17 = F_1 ( V_2 , V_37 , 9 , V_5 ) ;
if ( V_17 )
return V_17 ;
if ( V_5 [ V_38 ] & V_39 ) {
V_28 -> V_40 = 1 ;
F_3 ( & V_2 -> V_13 ,
L_4 ) ;
return - V_41 ;
}
F_12 ( & V_2 -> V_13 ,
L_5
L_6 ,
V_14 ,
V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] ,
V_5 [ 4 ] , V_5 [ 5 ] , V_5 [ 6 ] , V_5 [ 7 ] ,
V_5 [ 8 ] ) ;
V_36 -> V_42 = F_13 ( V_5 [ V_38 ] & 0x7F ) ;
V_36 -> V_43 = F_13 ( V_5 [ V_44 ] & 0x7F ) ;
V_36 -> V_45 = F_13 ( V_5 [ V_46 ] & 0x3F ) ;
V_36 -> V_47 = F_13 ( V_5 [ V_48 ] & 0x3F ) ;
V_36 -> V_49 = V_5 [ V_50 ] & 0x07 ;
V_36 -> V_51 = F_13 ( V_5 [ V_52 ] & 0x1F ) - 1 ;
V_36 -> V_53 = F_13 ( V_5 [ V_54 ] ) ;
if ( V_36 -> V_53 < 70 )
V_36 -> V_53 += 100 ;
V_28 -> V_55 = ( V_5 [ V_52 ] & V_56 ) ?
( V_36 -> V_53 >= 100 ) : ( V_36 -> V_53 < 100 ) ;
F_12 ( & V_2 -> V_13 , L_7
L_8 ,
V_14 ,
V_36 -> V_42 , V_36 -> V_43 , V_36 -> V_45 ,
V_36 -> V_47 , V_36 -> V_51 , V_36 -> V_53 , V_36 -> V_49 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_28 * V_28 = F_9 ( V_2 ) ;
unsigned char V_5 [ 9 ] ;
F_12 ( & V_2 -> V_13 , L_9
L_8 ,
V_14 ,
V_36 -> V_42 , V_36 -> V_43 , V_36 -> V_45 ,
V_36 -> V_47 , V_36 -> V_51 , V_36 -> V_53 , V_36 -> V_49 ) ;
V_5 [ V_38 ] = F_15 ( V_36 -> V_42 ) ;
V_5 [ V_44 ] = F_15 ( V_36 -> V_43 ) ;
V_5 [ V_46 ] = F_15 ( V_36 -> V_45 ) ;
V_5 [ V_48 ] = F_15 ( V_36 -> V_47 ) ;
V_5 [ V_52 ] = F_15 ( V_36 -> V_51 + 1 ) ;
V_5 [ V_54 ] = F_15 ( V_36 -> V_53 % 100 ) ;
if ( V_28 -> V_55 ? ( V_36 -> V_53 >= 100 ) : ( V_36 -> V_53 < 100 ) )
V_5 [ V_52 ] |= V_56 ;
V_5 [ V_50 ] = V_36 -> V_49 & 0x07 ;
return F_4 ( V_2 , V_38 ,
9 - V_38 , V_5 + V_38 ) ;
}
static int F_16 ( struct V_57 * V_13 , unsigned int V_58 , unsigned long V_59 )
{
struct V_28 * V_28 = F_9 ( F_17 ( V_13 ) ) ;
struct V_35 V_36 ;
switch ( V_58 ) {
case V_60 :
if ( V_28 -> V_40 )
F_18 ( V_13 , L_4 ) ;
if ( F_19 ( ( void V_61 * ) V_59 , & V_28 -> V_40 ,
sizeof( int ) ) )
return - V_62 ;
return 0 ;
case V_63 :
if ( F_11 ( F_17 ( V_13 ) , & V_36 ) )
F_14 ( F_17 ( V_13 ) , & V_36 ) ;
V_28 -> V_40 = 0 ;
return 0 ;
default:
return - V_64 ;
}
}
static int F_20 ( struct V_57 * V_13 , struct V_35 * V_36 )
{
return F_11 ( F_17 ( V_13 ) , V_36 ) ;
}
static int F_21 ( struct V_57 * V_13 , struct V_35 * V_36 )
{
return F_14 ( F_17 ( V_13 ) , V_36 ) ;
}
static int F_22 ( struct V_57 * V_13 , struct V_65 * V_36 )
{
struct V_1 * V_2 = F_17 ( V_13 ) ;
unsigned char V_5 [ 4 ] ;
int V_17 ;
V_17 = F_1 ( V_2 , V_66 , 4 , V_5 ) ;
if ( V_17 )
return V_17 ;
F_12 ( & V_2 -> V_13 ,
L_10 ,
V_14 , V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] ) ;
V_36 -> time . V_43 = F_13 ( V_5 [ 0 ] & 0x7F ) ;
V_36 -> time . V_45 = F_13 ( V_5 [ 1 ] & 0x3F ) ;
V_36 -> time . V_47 = F_13 ( V_5 [ 2 ] & 0x3F ) ;
V_36 -> time . V_49 = F_13 ( V_5 [ 3 ] & 0x7 ) ;
V_36 -> time . V_51 = - 1 ;
V_36 -> time . V_53 = - 1 ;
V_36 -> time . V_67 = - 1 ;
V_36 -> time . V_68 = - 1 ;
V_17 = F_7 ( V_2 , & V_36 -> V_69 , & V_36 -> V_29 ) ;
if ( V_17 < 0 )
return V_17 ;
F_12 ( & V_2 -> V_13 , L_11
L_12 , V_14 , V_36 -> time . V_43 ,
V_36 -> time . V_45 , V_36 -> time . V_47 , V_36 -> time . V_49 ,
V_36 -> V_69 , V_36 -> V_29 ) ;
return 0 ;
}
static int F_23 ( struct V_57 * V_13 , struct V_65 * V_36 )
{
struct V_1 * V_2 = F_17 ( V_13 ) ;
unsigned char V_5 [ 4 ] ;
int V_17 ;
if ( V_36 -> time . V_42 ) {
T_2 V_70 = F_24 ( & V_36 -> time ) ;
V_70 += 60 - V_36 -> time . V_42 ;
F_25 ( V_70 , & V_36 -> time ) ;
}
F_12 ( V_13 , L_13
L_14 , V_14 ,
V_36 -> time . V_43 , V_36 -> time . V_45 , V_36 -> time . V_49 ,
V_36 -> time . V_47 , V_36 -> V_69 , V_36 -> V_29 ) ;
V_5 [ 0 ] = F_15 ( V_36 -> time . V_43 ) ;
V_5 [ 1 ] = F_15 ( V_36 -> time . V_45 ) ;
V_5 [ 2 ] = F_15 ( V_36 -> time . V_47 ) ;
V_5 [ 3 ] = V_36 -> time . V_49 & 0x07 ;
V_17 = F_4 ( V_2 , V_66 , 4 , V_5 ) ;
if ( V_17 )
return V_17 ;
return F_6 ( V_2 , 1 ) ;
}
static int F_26 ( struct V_57 * V_13 , unsigned int V_69 )
{
F_12 ( V_13 , L_15 , V_14 , V_69 ) ;
return F_6 ( F_17 ( V_13 ) , ! ! V_69 ) ;
}
static unsigned long F_27 ( struct V_71 * V_72 ,
unsigned long V_73 )
{
struct V_28 * V_28 = F_28 ( V_72 ) ;
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned char V_5 ;
int V_74 = F_1 ( V_2 , V_75 , 1 , & V_5 ) ;
if ( V_74 < 0 )
return 0 ;
V_5 &= V_76 ;
return V_77 [ V_74 ] ;
}
static long F_29 ( struct V_71 * V_72 , unsigned long V_78 ,
unsigned long * V_79 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < F_30 ( V_77 ) ; V_16 ++ )
if ( V_77 [ V_16 ] <= V_78 )
return V_77 [ V_16 ] ;
return 0 ;
}
static int F_31 ( struct V_71 * V_72 , unsigned long V_78 ,
unsigned long V_73 )
{
struct V_28 * V_28 = F_28 ( V_72 ) ;
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned char V_5 ;
int V_74 = F_1 ( V_2 , V_75 , 1 , & V_5 ) ;
int V_16 ;
if ( V_74 < 0 )
return V_74 ;
for ( V_16 = 0 ; V_16 < F_30 ( V_77 ) ; V_16 ++ )
if ( V_77 [ V_16 ] == V_78 ) {
V_5 &= ~ V_76 ;
V_5 |= V_16 ;
V_74 = F_4 ( V_2 ,
V_75 , 1 ,
& V_5 ) ;
return V_74 ;
}
return - V_41 ;
}
static int F_32 ( struct V_71 * V_72 , bool V_80 )
{
struct V_28 * V_28 = F_28 ( V_72 ) ;
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned char V_5 ;
int V_74 = F_1 ( V_2 , V_75 , 1 , & V_5 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_80 )
V_5 |= V_81 ;
else
V_5 &= ~ V_81 ;
V_74 = F_4 ( V_2 , V_75 , 1 , & V_5 ) ;
return V_74 ;
}
static int F_33 ( struct V_71 * V_72 )
{
return F_32 ( V_72 , 1 ) ;
}
static void F_34 ( struct V_71 * V_72 )
{
F_32 ( V_72 , 0 ) ;
}
static int F_35 ( struct V_71 * V_72 )
{
struct V_28 * V_28 = F_28 ( V_72 ) ;
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned char V_5 ;
int V_74 = F_1 ( V_2 , V_75 , 1 , & V_5 ) ;
if ( V_74 < 0 )
return V_74 ;
return ! ! ( V_5 & V_81 ) ;
}
static struct V_82 * F_36 ( struct V_28 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_83 * V_84 = V_2 -> V_13 . V_85 ;
struct V_82 * V_82 ;
struct V_86 V_87 ;
int V_74 ;
unsigned char V_5 ;
V_5 = 0 ;
V_74 = F_4 ( V_2 , V_75 , 1 , & V_5 ) ;
if ( V_74 < 0 )
return F_37 ( V_74 ) ;
V_87 . V_88 = L_16 ;
V_87 . V_89 = & V_90 ;
V_87 . V_10 = 0 ;
V_87 . V_91 = NULL ;
V_87 . V_92 = 0 ;
V_28 -> V_93 . V_87 = & V_87 ;
F_38 ( V_84 , L_17 , & V_87 . V_88 ) ;
V_82 = F_39 ( & V_2 -> V_13 , & V_28 -> V_93 ) ;
if ( ! F_40 ( V_82 ) )
F_41 ( V_84 , V_94 , V_82 ) ;
return V_82 ;
}
static int F_42 ( struct V_1 * V_2 ,
const struct V_95 * V_96 )
{
struct V_28 * V_28 ;
int V_17 ;
unsigned char V_5 ;
unsigned char V_97 ;
F_12 ( & V_2 -> V_13 , L_18 , V_14 ) ;
if ( ! F_43 ( V_2 -> V_12 , V_98 ) )
return - V_99 ;
V_28 = F_44 ( & V_2 -> V_13 , sizeof( struct V_28 ) ,
V_100 ) ;
if ( ! V_28 )
return - V_101 ;
F_45 ( V_2 , V_28 ) ;
V_28 -> V_2 = V_2 ;
F_46 ( & V_2 -> V_13 , 1 ) ;
V_5 = V_102 ;
V_17 = F_4 ( V_2 , V_103 , 1 , & V_5 ) ;
if ( V_17 < 0 ) {
F_3 ( & V_2 -> V_13 , L_3 , V_14 ) ;
return V_17 ;
}
V_17 = F_7 ( V_2 , NULL , & V_97 ) ;
if ( V_17 ) {
F_3 ( & V_2 -> V_13 , L_1 , V_14 ) ;
return V_17 ;
}
if ( V_97 )
F_6 ( V_2 , 0 ) ;
V_28 -> V_31 = F_47 ( & V_2 -> V_13 ,
V_104 . V_105 . V_88 ,
& V_106 , V_107 ) ;
if ( F_40 ( V_28 -> V_31 ) )
return F_48 ( V_28 -> V_31 ) ;
if ( V_2 -> V_26 > 0 ) {
V_17 = F_49 ( & V_2 -> V_13 , V_2 -> V_26 ,
NULL , F_8 ,
V_108 | V_109 | V_110 ,
V_28 -> V_31 -> V_88 , V_2 ) ;
if ( V_17 ) {
F_3 ( & V_2 -> V_13 , L_19 ,
V_2 -> V_26 ) ;
return V_17 ;
}
}
#ifdef F_50
F_36 ( V_28 ) ;
#endif
V_28 -> V_31 -> V_111 = 1 ;
return 0 ;
}
