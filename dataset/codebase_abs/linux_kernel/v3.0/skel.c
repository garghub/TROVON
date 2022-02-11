static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 ( L_1 , V_2 -> V_7 ) ;
V_2 -> V_8 = V_9 -> V_10 ;
if ( F_3 ( V_2 , sizeof( struct V_11 ) ) < 0 )
return - V_12 ;
if ( F_4 ( V_2 , 3 ) < 0 )
return - V_12 ;
V_6 = V_2 -> V_13 + 0 ;
V_6 -> type = V_14 ;
V_6 -> V_15 = V_16 | V_17 | V_18 ;
V_6 -> V_19 = V_9 -> V_20 ;
V_6 -> V_21 = ( 1 << V_9 -> V_22 ) - 1 ;
V_6 -> V_23 = & V_24 ;
V_6 -> V_25 = 16 ;
V_6 -> V_26 = V_27 ;
V_6 -> V_28 = V_29 ;
V_6 = V_2 -> V_13 + 1 ;
V_6 -> type = V_30 ;
V_6 -> V_15 = V_31 ;
V_6 -> V_19 = 1 ;
V_6 -> V_21 = 0xffff ;
V_6 -> V_23 = & V_32 ;
V_6 -> V_33 = V_34 ;
V_6 -> V_26 = V_35 ;
V_6 = V_2 -> V_13 + 2 ;
if ( V_9 -> V_36 ) {
V_6 -> type = V_37 ;
V_6 -> V_15 = V_16 | V_31 ;
V_6 -> V_19 = 16 ;
V_6 -> V_21 = 1 ;
V_6 -> V_23 = & V_38 ;
V_6 -> V_39 = V_40 ;
V_6 -> V_41 = V_42 ;
} else {
V_6 -> type = V_43 ;
}
F_2 ( L_2 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_2 ( L_3 , V_2 -> V_7 ) ;
return 0 ;
}
static int V_27 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_44 * V_45 , unsigned int * V_46 )
{
int V_47 , V_48 ;
unsigned int V_49 ;
unsigned int V_50 ;
for ( V_47 = 0 ; V_47 < V_45 -> V_47 ; V_47 ++ ) {
#define F_6 100
for ( V_48 = 0 ; V_48 < F_6 ; V_48 ++ ) {
V_50 = 1 ;
if ( V_50 )
break;
}
if ( V_48 == F_6 ) {
F_2 ( L_4 ) ;
return - V_51 ;
}
V_49 = 0 ;
V_49 ^= 1 << ( V_9 -> V_22 - 1 ) ;
V_46 [ V_47 ] = V_49 ;
}
return V_47 ;
}
static int V_29 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_52 * V_53 )
{
int V_54 = 0 ;
int V_55 ;
V_55 = V_53 -> V_56 ;
V_53 -> V_56 &= V_57 ;
if ( ! V_53 -> V_56 || V_55 != V_53 -> V_56 )
V_54 ++ ;
V_55 = V_53 -> V_58 ;
V_53 -> V_58 &= V_59 | V_60 ;
if ( ! V_53 -> V_58 || V_55 != V_53 -> V_58 )
V_54 ++ ;
V_55 = V_53 -> V_61 ;
V_53 -> V_61 &= V_59 | V_60 ;
if ( ! V_53 -> V_61 || V_55 != V_53 -> V_61 )
V_54 ++ ;
V_55 = V_53 -> V_62 ;
V_53 -> V_62 &= V_63 ;
if ( ! V_53 -> V_62 || V_55 != V_53 -> V_62 )
V_54 ++ ;
V_55 = V_53 -> V_64 ;
V_53 -> V_64 &= V_63 | V_65 ;
if ( ! V_53 -> V_64 || V_55 != V_53 -> V_64 )
V_54 ++ ;
if ( V_54 )
return 1 ;
if ( V_53 -> V_58 != V_59 &&
V_53 -> V_58 != V_60 )
V_54 ++ ;
if ( V_53 -> V_61 != V_59 && V_53 -> V_61 != V_60 )
V_54 ++ ;
if ( V_53 -> V_64 != V_63 && V_53 -> V_64 != V_65 )
V_54 ++ ;
if ( V_54 )
return 2 ;
if ( V_53 -> V_66 != 0 ) {
V_53 -> V_66 = 0 ;
V_54 ++ ;
}
#define F_7 10000
#define F_8 1000000000
if ( V_53 -> V_58 == V_59 ) {
if ( V_53 -> V_67 < F_7 ) {
V_53 -> V_67 = F_7 ;
V_54 ++ ;
}
if ( V_53 -> V_67 > F_8 ) {
V_53 -> V_67 = F_8 ;
V_54 ++ ;
}
} else {
if ( V_53 -> V_67 > 9 ) {
V_53 -> V_67 = 9 ;
V_54 ++ ;
}
}
if ( V_53 -> V_61 == V_59 ) {
if ( V_53 -> V_68 < F_7 ) {
V_53 -> V_68 = F_7 ;
V_54 ++ ;
}
if ( V_53 -> V_68 > F_8 ) {
V_53 -> V_68 = F_8 ;
V_54 ++ ;
}
} else {
if ( V_53 -> V_68 > 9 ) {
V_53 -> V_68 = 9 ;
V_54 ++ ;
}
}
if ( V_53 -> V_69 != V_53 -> V_70 ) {
V_53 -> V_69 = V_53 -> V_70 ;
V_54 ++ ;
}
if ( V_53 -> V_64 == V_63 ) {
if ( V_53 -> V_71 > 0x00ffffff ) {
V_53 -> V_71 = 0x00ffffff ;
V_54 ++ ;
}
} else {
if ( V_53 -> V_71 != 0 ) {
V_53 -> V_71 = 0 ;
V_54 ++ ;
}
}
if ( V_54 )
return 3 ;
if ( V_53 -> V_58 == V_59 ) {
V_55 = V_53 -> V_67 ;
F_9 ( & V_53 -> V_67 ,
V_53 -> V_72 & V_73 ) ;
if ( V_55 != V_53 -> V_67 )
V_54 ++ ;
}
if ( V_53 -> V_61 == V_59 ) {
V_55 = V_53 -> V_68 ;
F_9 ( & V_53 -> V_68 ,
V_53 -> V_72 & V_73 ) ;
if ( V_55 != V_53 -> V_68 )
V_54 ++ ;
if ( V_53 -> V_58 == V_59 &&
V_53 -> V_67 <
V_53 -> V_68 * V_53 -> V_69 ) {
V_53 -> V_67 =
V_53 -> V_68 * V_53 -> V_69 ;
V_54 ++ ;
}
}
if ( V_54 )
return 4 ;
return 0 ;
}
static int F_9 ( unsigned int * V_74 , int V_75 )
{
return * V_74 ;
}
static int V_34 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_44 * V_45 , unsigned int * V_46 )
{
int V_48 ;
int V_76 = F_10 ( V_45 -> V_77 ) ;
F_2 ( L_5 ) ;
for ( V_48 = 0 ; V_48 < V_45 -> V_47 ; V_48 ++ ) {
V_78 -> V_79 [ V_76 ] = V_46 [ V_48 ] ;
}
return V_48 ;
}
static int V_35 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_44 * V_45 , unsigned int * V_46 )
{
int V_48 ;
int V_76 = F_10 ( V_45 -> V_77 ) ;
for ( V_48 = 0 ; V_48 < V_45 -> V_47 ; V_48 ++ )
V_46 [ V_48 ] = V_78 -> V_79 [ V_76 ] ;
return V_48 ;
}
static int V_40 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_44 * V_45 , unsigned int * V_46 )
{
if ( V_45 -> V_47 != 2 )
return - V_80 ;
if ( V_46 [ 0 ] ) {
V_6 -> V_81 &= ~ V_46 [ 0 ] ;
V_6 -> V_81 |= V_46 [ 0 ] & V_46 [ 1 ] ;
}
return 2 ;
}
static int V_42 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_44 * V_45 , unsigned int * V_46 )
{
int V_76 = F_10 ( V_45 -> V_77 ) ;
switch ( V_46 [ 0 ] ) {
case V_82 :
V_6 -> V_83 |= 1 << V_76 ;
break;
case V_84 :
V_6 -> V_83 &= ~ ( 1 << V_76 ) ;
break;
case V_85 :
V_46 [ 1 ] =
( V_6 -> V_83 & ( 1 << V_76 ) ) ? V_86 : V_87 ;
return V_45 -> V_47 ;
break;
default:
return - V_80 ;
break;
}
return V_45 -> V_47 ;
}
static int T_1 F_11 ( struct V_88 * V_2 ,
const struct V_89 * V_90 )
{
return F_12 ( V_2 , V_91 . V_92 ) ;
}
static void T_2 F_13 ( struct V_88 * V_2 )
{
F_14 ( V_2 ) ;
}
static int T_3 F_15 ( void )
{
int V_93 ;
V_93 = F_16 ( & V_91 ) ;
if ( V_93 < 0 )
return V_93 ;
V_94 . V_10 = ( char * ) V_91 . V_92 ;
return F_17 ( & V_94 ) ;
}
static void T_4 F_18 ( void )
{
F_19 ( & V_94 ) ;
F_20 ( & V_91 ) ;
}
static int T_3 F_15 ( void )
{
return F_16 ( & V_91 ) ;
}
static void T_4 F_18 ( void )
{
F_20 ( & V_91 ) ;
}
