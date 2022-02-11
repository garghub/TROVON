static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
F_2 ( L_1 , V_2 -> V_8 ) ;
V_2 -> V_9 = V_10 -> V_11 ;
if ( F_3 ( V_2 , sizeof( struct V_12 ) ) < 0 )
return - V_13 ;
V_7 = F_4 ( V_2 , 3 ) ;
if ( V_7 )
return V_7 ;
V_6 = V_2 -> V_14 + 0 ;
V_6 -> type = V_15 ;
V_6 -> V_16 = V_17 | V_18 | V_19 ;
V_6 -> V_20 = V_10 -> V_21 ;
V_6 -> V_22 = ( 1 << V_10 -> V_23 ) - 1 ;
V_6 -> V_24 = & V_25 ;
V_6 -> V_26 = 16 ;
V_6 -> V_27 = V_28 ;
V_6 -> V_29 = V_30 ;
V_6 = V_2 -> V_14 + 1 ;
V_6 -> type = V_31 ;
V_6 -> V_16 = V_32 ;
V_6 -> V_20 = 1 ;
V_6 -> V_22 = 0xffff ;
V_6 -> V_24 = & V_33 ;
V_6 -> V_34 = V_35 ;
V_6 -> V_27 = V_36 ;
V_6 = V_2 -> V_14 + 2 ;
if ( V_10 -> V_37 ) {
V_6 -> type = V_38 ;
V_6 -> V_16 = V_17 | V_32 ;
V_6 -> V_20 = 16 ;
V_6 -> V_22 = 1 ;
V_6 -> V_24 = & V_39 ;
V_6 -> V_40 = V_41 ;
V_6 -> V_42 = V_43 ;
} else {
V_6 -> type = V_44 ;
}
F_2 ( L_2 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
}
static int V_28 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_45 * V_46 , unsigned int * V_47 )
{
int V_48 , V_49 ;
unsigned int V_50 ;
unsigned int V_51 ;
for ( V_48 = 0 ; V_48 < V_46 -> V_48 ; V_48 ++ ) {
#define F_6 100
for ( V_49 = 0 ; V_49 < F_6 ; V_49 ++ ) {
V_51 = 1 ;
if ( V_51 )
break;
}
if ( V_49 == F_6 ) {
F_2 ( L_3 ) ;
return - V_52 ;
}
V_50 = 0 ;
V_50 ^= 1 << ( V_10 -> V_23 - 1 ) ;
V_47 [ V_48 ] = V_50 ;
}
return V_48 ;
}
static int V_30 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_53 * V_54 )
{
int V_55 = 0 ;
int V_56 ;
V_56 = V_54 -> V_57 ;
V_54 -> V_57 &= V_58 ;
if ( ! V_54 -> V_57 || V_56 != V_54 -> V_57 )
V_55 ++ ;
V_56 = V_54 -> V_59 ;
V_54 -> V_59 &= V_60 | V_61 ;
if ( ! V_54 -> V_59 || V_56 != V_54 -> V_59 )
V_55 ++ ;
V_56 = V_54 -> V_62 ;
V_54 -> V_62 &= V_60 | V_61 ;
if ( ! V_54 -> V_62 || V_56 != V_54 -> V_62 )
V_55 ++ ;
V_56 = V_54 -> V_63 ;
V_54 -> V_63 &= V_64 ;
if ( ! V_54 -> V_63 || V_56 != V_54 -> V_63 )
V_55 ++ ;
V_56 = V_54 -> V_65 ;
V_54 -> V_65 &= V_64 | V_66 ;
if ( ! V_54 -> V_65 || V_56 != V_54 -> V_65 )
V_55 ++ ;
if ( V_55 )
return 1 ;
if ( V_54 -> V_59 != V_60 &&
V_54 -> V_59 != V_61 )
V_55 ++ ;
if ( V_54 -> V_62 != V_60 && V_54 -> V_62 != V_61 )
V_55 ++ ;
if ( V_54 -> V_65 != V_64 && V_54 -> V_65 != V_66 )
V_55 ++ ;
if ( V_55 )
return 2 ;
if ( V_54 -> V_67 != 0 ) {
V_54 -> V_67 = 0 ;
V_55 ++ ;
}
#define F_7 10000
#define F_8 1000000000
if ( V_54 -> V_59 == V_60 ) {
if ( V_54 -> V_68 < F_7 ) {
V_54 -> V_68 = F_7 ;
V_55 ++ ;
}
if ( V_54 -> V_68 > F_8 ) {
V_54 -> V_68 = F_8 ;
V_55 ++ ;
}
} else {
if ( V_54 -> V_68 > 9 ) {
V_54 -> V_68 = 9 ;
V_55 ++ ;
}
}
if ( V_54 -> V_62 == V_60 ) {
if ( V_54 -> V_69 < F_7 ) {
V_54 -> V_69 = F_7 ;
V_55 ++ ;
}
if ( V_54 -> V_69 > F_8 ) {
V_54 -> V_69 = F_8 ;
V_55 ++ ;
}
} else {
if ( V_54 -> V_69 > 9 ) {
V_54 -> V_69 = 9 ;
V_55 ++ ;
}
}
if ( V_54 -> V_70 != V_54 -> V_71 ) {
V_54 -> V_70 = V_54 -> V_71 ;
V_55 ++ ;
}
if ( V_54 -> V_65 == V_64 ) {
if ( V_54 -> V_72 > 0x00ffffff ) {
V_54 -> V_72 = 0x00ffffff ;
V_55 ++ ;
}
} else {
if ( V_54 -> V_72 != 0 ) {
V_54 -> V_72 = 0 ;
V_55 ++ ;
}
}
if ( V_55 )
return 3 ;
if ( V_54 -> V_59 == V_60 ) {
V_56 = V_54 -> V_68 ;
F_9 ( & V_54 -> V_68 ,
V_54 -> V_73 & V_74 ) ;
if ( V_56 != V_54 -> V_68 )
V_55 ++ ;
}
if ( V_54 -> V_62 == V_60 ) {
V_56 = V_54 -> V_69 ;
F_9 ( & V_54 -> V_69 ,
V_54 -> V_73 & V_74 ) ;
if ( V_56 != V_54 -> V_69 )
V_55 ++ ;
if ( V_54 -> V_59 == V_60 &&
V_54 -> V_68 <
V_54 -> V_69 * V_54 -> V_70 ) {
V_54 -> V_68 =
V_54 -> V_69 * V_54 -> V_70 ;
V_55 ++ ;
}
}
if ( V_55 )
return 4 ;
return 0 ;
}
static int F_9 ( unsigned int * V_75 , int V_76 )
{
return * V_75 ;
}
static int V_35 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_45 * V_46 , unsigned int * V_47 )
{
int V_49 ;
int V_77 = F_10 ( V_46 -> V_78 ) ;
F_2 ( L_4 ) ;
for ( V_49 = 0 ; V_49 < V_46 -> V_48 ; V_49 ++ ) {
V_79 -> V_80 [ V_77 ] = V_47 [ V_49 ] ;
}
return V_49 ;
}
static int V_36 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_45 * V_46 , unsigned int * V_47 )
{
int V_49 ;
int V_77 = F_10 ( V_46 -> V_78 ) ;
for ( V_49 = 0 ; V_49 < V_46 -> V_48 ; V_49 ++ )
V_47 [ V_49 ] = V_79 -> V_80 [ V_77 ] ;
return V_49 ;
}
static int V_41 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_45 * V_46 , unsigned int * V_47 )
{
if ( V_47 [ 0 ] ) {
V_6 -> V_81 &= ~ V_47 [ 0 ] ;
V_6 -> V_81 |= V_47 [ 0 ] & V_47 [ 1 ] ;
}
return V_46 -> V_48 ;
}
static int V_43 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_45 * V_46 , unsigned int * V_47 )
{
int V_77 = F_10 ( V_46 -> V_78 ) ;
switch ( V_47 [ 0 ] ) {
case V_82 :
V_6 -> V_83 |= 1 << V_77 ;
break;
case V_84 :
V_6 -> V_83 &= ~ ( 1 << V_77 ) ;
break;
case V_85 :
V_47 [ 1 ] =
( V_6 -> V_83 & ( 1 << V_77 ) ) ? V_86 : V_87 ;
return V_46 -> V_48 ;
break;
default:
return - V_88 ;
break;
}
return V_46 -> V_48 ;
}
static int T_1 F_11 ( struct V_89 * V_2 ,
const struct V_90 * V_91 )
{
return F_12 ( V_2 , & V_92 ) ;
}
static void T_2 F_13 ( struct V_89 * V_2 )
{
F_14 ( V_2 ) ;
}
static int T_3 F_15 ( void )
{
int V_93 ;
V_93 = F_16 ( & V_92 ) ;
if ( V_93 < 0 )
return V_93 ;
V_94 . V_11 = ( char * ) V_92 . V_95 ;
return F_17 ( & V_94 ) ;
}
static void T_4 F_18 ( void )
{
F_19 ( & V_94 ) ;
F_20 ( & V_92 ) ;
}
static int T_3 F_15 ( void )
{
return F_16 ( & V_92 ) ;
}
static void T_4 F_18 ( void )
{
F_20 ( & V_92 ) ;
}
