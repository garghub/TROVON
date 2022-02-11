static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 , V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_4 ( V_2 -> V_4 . V_5 , V_3 , V_6 ) ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_2 =
F_6 ( V_8 -> V_9 , struct V_1 , V_10 ) ;
if ( ! F_7 ( & V_2 -> V_4 ) )
return 0 ;
switch ( V_8 -> V_11 ) {
case V_12 :
F_3 ( V_2 , V_13 , V_8 -> V_14 |
( 0xff << V_15 ) ) ;
break;
}
return 0 ;
}
static int F_8 ( struct V_16 * V_17 , int V_18 )
{
struct V_19 * V_20 = F_9 ( & V_17 -> V_4 ) ;
struct V_1 * V_2 = F_10 ( V_17 ) ;
struct V_21 * V_22 ;
unsigned int V_23 ;
unsigned int V_24 ;
int V_25 ;
V_25 = F_11 ( & V_2 -> V_4 , V_18 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_18 )
return 0 ;
V_22 = & V_2 -> V_4 . V_26 [ V_27 ] ;
V_23 = V_20 -> V_28 ? V_20 -> V_28 -> V_29 . V_22 . V_23 : 0 ;
F_3 ( V_2 , V_30 ,
V_23 & V_31 ?
0 : V_32 ) ;
F_3 ( V_2 , V_33 ,
( V_22 -> V_34 << V_35 ) |
( V_22 -> V_36 << V_37 ) ) ;
F_3 ( V_2 , V_38 , 0 ) ;
F_3 ( V_2 , V_39 , F_12 ( 1 ) |
F_13 ( V_40 ) |
F_14 ( V_40 ) ) ;
for ( V_24 = 0 ; V_24 < 4 ; ++ V_24 ) {
bool V_41 = false ;
T_1 V_8 = 0 ;
if ( V_2 -> V_42 [ V_24 ] . V_43 ) {
V_8 |= V_44 ;
V_41 = V_2 -> V_42 [ V_24 ] . V_43 -> V_29 . V_22 . V_23
& V_31 ;
} else {
V_8 |= F_15 ( V_40 )
| F_16 ( V_40 ) ;
}
if ( V_24 == 0 )
V_8 |= V_45 ;
if ( V_24 != 1 )
V_8 |= F_17 ( V_24 ) ;
F_3 ( V_2 , F_18 ( V_24 ) , V_8 ) ;
F_3 ( V_2 , F_19 ( V_24 ) ,
V_46 |
( V_41 ? V_47 :
V_48 ) |
V_49 |
V_50 |
( 0xff << V_51 ) ) ;
}
return 0 ;
}
static int F_20 ( struct V_16 * V_17 ,
struct V_52 * V_53 ,
struct V_54 * V_55 )
{
static const unsigned int V_56 [] = {
V_57 ,
V_58 ,
} ;
struct V_1 * V_2 = F_10 ( V_17 ) ;
struct V_21 * V_22 ;
if ( V_55 -> V_59 == F_21 ( 0 ) ) {
if ( V_55 -> V_60 >= F_22 ( V_56 ) )
return - V_61 ;
V_55 -> V_55 = V_56 [ V_55 -> V_60 ] ;
} else {
if ( V_55 -> V_60 )
return - V_61 ;
V_22 = F_23 ( & V_2 -> V_4 , V_53 ,
F_21 ( 0 ) , V_55 -> V_62 ) ;
V_55 -> V_55 = V_22 -> V_55 ;
}
return 0 ;
}
static int F_24 ( struct V_16 * V_17 ,
struct V_52 * V_53 ,
struct V_63 * V_64 )
{
if ( V_64 -> V_60 )
return - V_61 ;
if ( V_64 -> V_55 != V_57 &&
V_64 -> V_55 != V_58 )
return - V_61 ;
V_64 -> V_65 = V_66 ;
V_64 -> V_67 = V_68 ;
V_64 -> V_69 = V_66 ;
V_64 -> V_70 = V_68 ;
return 0 ;
}
static struct V_71 * F_25 ( struct V_1 * V_2 ,
struct V_52 * V_53 ,
unsigned int V_59 , T_1 V_62 )
{
switch ( V_62 ) {
case V_72 :
return F_26 ( & V_2 -> V_4 . V_17 , V_53 , V_59 ) ;
case V_73 :
return & V_2 -> V_42 [ V_59 ] . V_74 ;
default:
return NULL ;
}
}
static int F_27 ( struct V_16 * V_17 , struct V_52 * V_53 ,
struct V_75 * V_76 )
{
struct V_1 * V_2 = F_10 ( V_17 ) ;
V_76 -> V_22 = * F_23 ( & V_2 -> V_4 , V_53 , V_76 -> V_59 ,
V_76 -> V_62 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 , struct V_52 * V_53 ,
unsigned int V_59 , struct V_21 * V_76 ,
enum V_77 V_62 )
{
struct V_21 * V_22 ;
switch ( V_59 ) {
case F_21 ( 0 ) :
if ( V_76 -> V_55 != V_57 &&
V_76 -> V_55 != V_58 )
V_76 -> V_55 = V_58 ;
break;
default:
V_22 = F_23 ( & V_2 -> V_4 , V_53 ,
F_21 ( 0 ) , V_62 ) ;
V_76 -> V_55 = V_22 -> V_55 ;
break;
}
V_76 -> V_34 = F_29 ( V_76 -> V_34 , V_66 , V_68 ) ;
V_76 -> V_36 = F_29 ( V_76 -> V_36 , V_66 , V_68 ) ;
V_76 -> V_78 = V_79 ;
V_76 -> V_80 = V_81 ;
}
static int F_30 ( struct V_16 * V_17 , struct V_52 * V_53 ,
struct V_75 * V_76 )
{
struct V_1 * V_2 = F_10 ( V_17 ) ;
struct V_21 * V_22 ;
F_28 ( V_2 , V_53 , V_76 -> V_59 , & V_76 -> V_22 , V_76 -> V_62 ) ;
V_22 = F_23 ( & V_2 -> V_4 , V_53 , V_76 -> V_59 ,
V_76 -> V_62 ) ;
* V_22 = V_76 -> V_22 ;
if ( V_76 -> V_59 != V_27 ) {
struct V_71 * V_74 ;
V_74 = F_25 ( V_2 , V_53 , V_76 -> V_59 , V_76 -> V_62 ) ;
V_74 -> V_82 = 0 ;
V_74 -> V_83 = 0 ;
V_74 -> V_34 = V_22 -> V_34 ;
V_74 -> V_36 = V_22 -> V_36 ;
}
if ( V_76 -> V_59 == F_21 ( 0 ) ) {
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 <= V_27 ; ++ V_24 ) {
V_22 = F_23 ( & V_2 -> V_4 , V_53 ,
V_24 , V_76 -> V_62 ) ;
V_22 -> V_55 = V_76 -> V_22 . V_55 ;
}
}
return 0 ;
}
static int F_31 ( struct V_16 * V_17 ,
struct V_52 * V_53 ,
struct V_84 * V_85 )
{
struct V_1 * V_2 = F_10 ( V_17 ) ;
if ( V_85 -> V_59 == V_27 )
return - V_61 ;
switch ( V_85 -> V_86 ) {
case V_87 :
V_85 -> V_88 . V_82 = 0 ;
V_85 -> V_88 . V_83 = 0 ;
V_85 -> V_88 . V_34 = V_68 ;
V_85 -> V_88 . V_36 = V_68 ;
return 0 ;
case V_89 :
V_85 -> V_88 = * F_25 ( V_2 , V_53 , V_85 -> V_59 , V_85 -> V_62 ) ;
return 0 ;
default:
return - V_61 ;
}
}
static int F_32 ( struct V_16 * V_17 ,
struct V_52 * V_53 ,
struct V_84 * V_85 )
{
struct V_1 * V_2 = F_10 ( V_17 ) ;
struct V_21 * V_22 ;
struct V_71 * V_74 ;
if ( V_85 -> V_59 == V_27 )
return - V_61 ;
if ( V_85 -> V_86 != V_89 )
return - V_61 ;
V_22 = F_23 ( & V_2 -> V_4 , V_53 , V_27 ,
V_85 -> V_62 ) ;
V_85 -> V_88 . V_82 = F_33 (unsigned int, sel->r.left, 0 , format->width - 1 ) ;
V_85 -> V_88 . V_83 = F_33 (unsigned int, sel->r.top, 0 , format->height - 1 ) ;
V_22 = F_23 ( & V_2 -> V_4 , V_53 , V_85 -> V_59 ,
V_85 -> V_62 ) ;
V_85 -> V_88 . V_34 = V_22 -> V_34 ;
V_85 -> V_88 . V_36 = V_22 -> V_36 ;
V_74 = F_25 ( V_2 , V_53 , V_85 -> V_59 , V_85 -> V_62 ) ;
* V_74 = V_85 -> V_88 ;
return 0 ;
}
struct V_1 * F_34 ( struct V_90 * V_5 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 ;
int V_25 ;
V_2 = F_35 ( V_5 -> V_91 , sizeof( * V_2 ) , V_92 ) ;
if ( V_2 == NULL )
return F_36 ( - V_93 ) ;
V_2 -> V_4 . type = V_94 ;
V_25 = F_37 ( V_5 , & V_2 -> V_4 , 5 ) ;
if ( V_25 < 0 )
return F_36 ( V_25 ) ;
V_17 = & V_2 -> V_4 . V_17 ;
F_38 ( V_17 , & V_95 ) ;
V_17 -> V_4 . V_96 = & V_97 ;
V_17 -> V_98 = & V_99 ;
snprintf ( V_17 -> V_100 , sizeof( V_17 -> V_100 ) , L_1 ,
F_39 ( V_5 -> V_91 ) ) ;
F_40 ( V_17 , V_2 ) ;
V_17 -> V_23 |= V_101 ;
F_41 ( V_17 , NULL ) ;
F_42 ( & V_2 -> V_10 , 1 ) ;
F_43 ( & V_2 -> V_10 , & V_102 , V_12 ,
0 , 0xffffff , 1 , 0 ) ;
V_2 -> V_4 . V_17 . V_103 = & V_2 -> V_10 ;
if ( V_2 -> V_10 . error ) {
F_44 ( V_5 -> V_91 , L_2 ) ;
V_25 = V_2 -> V_10 . error ;
F_45 ( & V_2 -> V_4 ) ;
return F_36 ( V_25 ) ;
}
return V_2 ;
}
