static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( & V_2 -> V_5 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_6 * V_7 )
{
struct V_1 * V_2 =
F_4 ( V_7 -> V_8 , struct V_1 , V_9 ) ;
if ( ! F_5 ( & V_2 -> V_5 ) )
return 0 ;
switch ( V_7 -> V_10 ) {
case V_11 :
F_1 ( V_2 , V_12 , V_7 -> V_13 |
( 0xff << V_14 ) ) ;
break;
}
return 0 ;
}
static int F_6 ( struct V_15 * V_16 , int V_17 )
{
struct V_18 * V_19 = F_7 ( & V_16 -> V_5 ) ;
struct V_1 * V_2 = F_8 ( V_16 ) ;
struct V_20 * V_21 ;
unsigned int V_22 ;
unsigned int V_23 ;
int V_24 ;
V_24 = F_9 ( & V_2 -> V_5 , V_17 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( ! V_17 )
return 0 ;
V_21 = & V_2 -> V_5 . V_25 [ V_2 -> V_5 . V_26 ] ;
V_22 = V_19 -> V_27 ? V_19 -> V_27 -> V_21 . V_22 : 0 ;
F_1 ( V_2 , V_28 ,
V_22 & V_29 ?
0 : V_30 ) ;
F_1 ( V_2 , V_31 ,
( V_21 -> V_32 << V_33 ) |
( V_21 -> V_34 << V_35 ) ) ;
F_1 ( V_2 , V_36 , 0 ) ;
F_1 ( V_2 , V_37 , F_10 ( 1 ) |
F_11 ( V_38 ) |
F_12 ( V_38 ) ) ;
for ( V_23 = 0 ; V_23 < V_2 -> V_5 . V_26 ; ++ V_23 ) {
bool V_39 = false ;
T_1 V_7 = 0 ;
if ( V_2 -> V_40 [ V_23 ] . V_41 ) {
V_7 |= V_42 ;
V_39 = V_2 -> V_40 [ V_23 ] . V_41 -> V_21 . V_22
& V_29 ;
} else {
V_7 |= F_13 ( V_38 )
| F_14 ( V_38 ) ;
}
if ( V_23 == 0 )
V_7 |= V_43 ;
if ( V_23 != 1 )
V_7 |= F_15 ( V_23 ) ;
F_1 ( V_2 , F_16 ( V_23 ) , V_7 ) ;
F_1 ( V_2 , F_17 ( V_23 ) ,
V_44 |
( V_39 ? V_45 :
V_46 ) |
V_47 |
V_48 |
( 0xff << V_49 ) ) ;
}
return 0 ;
}
static int F_18 ( struct V_15 * V_16 ,
struct V_50 * V_51 ,
struct V_52 * V_53 )
{
static const unsigned int V_54 [] = {
V_55 ,
V_56 ,
} ;
struct V_1 * V_2 = F_8 ( V_16 ) ;
struct V_20 * V_21 ;
if ( V_53 -> V_57 == F_19 ( 0 ) ) {
if ( V_53 -> V_58 >= F_20 ( V_54 ) )
return - V_59 ;
V_53 -> V_53 = V_54 [ V_53 -> V_58 ] ;
} else {
if ( V_53 -> V_58 )
return - V_59 ;
V_21 = F_21 ( & V_2 -> V_5 , V_51 ,
F_19 ( 0 ) , V_53 -> V_60 ) ;
V_53 -> V_53 = V_21 -> V_53 ;
}
return 0 ;
}
static int F_22 ( struct V_15 * V_16 ,
struct V_50 * V_51 ,
struct V_61 * V_62 )
{
if ( V_62 -> V_58 )
return - V_59 ;
if ( V_62 -> V_53 != V_55 &&
V_62 -> V_53 != V_56 )
return - V_59 ;
V_62 -> V_63 = V_64 ;
V_62 -> V_65 = V_66 ;
V_62 -> V_67 = V_64 ;
V_62 -> V_68 = V_66 ;
return 0 ;
}
static struct V_69 * F_23 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
unsigned int V_57 , T_1 V_60 )
{
switch ( V_60 ) {
case V_70 :
return F_24 ( & V_2 -> V_5 . V_16 , V_51 , V_57 ) ;
case V_71 :
return & V_2 -> V_40 [ V_57 ] . V_72 ;
default:
return NULL ;
}
}
static int F_25 ( struct V_15 * V_16 , struct V_50 * V_51 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
V_74 -> V_21 = * F_21 ( & V_2 -> V_5 , V_51 , V_74 -> V_57 ,
V_74 -> V_60 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 , struct V_50 * V_51 ,
unsigned int V_57 , struct V_20 * V_74 ,
enum V_75 V_60 )
{
struct V_20 * V_21 ;
switch ( V_57 ) {
case F_19 ( 0 ) :
if ( V_74 -> V_53 != V_55 &&
V_74 -> V_53 != V_56 )
V_74 -> V_53 = V_56 ;
break;
default:
V_21 = F_21 ( & V_2 -> V_5 , V_51 ,
F_19 ( 0 ) , V_60 ) ;
V_74 -> V_53 = V_21 -> V_53 ;
break;
}
V_74 -> V_32 = F_27 ( V_74 -> V_32 , V_64 , V_66 ) ;
V_74 -> V_34 = F_27 ( V_74 -> V_34 , V_64 , V_66 ) ;
V_74 -> V_76 = V_77 ;
V_74 -> V_78 = V_79 ;
}
static int F_28 ( struct V_15 * V_16 , struct V_50 * V_51 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
struct V_20 * V_21 ;
F_26 ( V_2 , V_51 , V_74 -> V_57 , & V_74 -> V_21 , V_74 -> V_60 ) ;
V_21 = F_21 ( & V_2 -> V_5 , V_51 , V_74 -> V_57 ,
V_74 -> V_60 ) ;
* V_21 = V_74 -> V_21 ;
if ( V_74 -> V_57 != V_2 -> V_5 . V_26 ) {
struct V_69 * V_72 ;
V_72 = F_23 ( V_2 , V_51 , V_74 -> V_57 , V_74 -> V_60 ) ;
V_72 -> V_80 = 0 ;
V_72 -> V_81 = 0 ;
V_72 -> V_32 = V_21 -> V_32 ;
V_72 -> V_34 = V_21 -> V_34 ;
}
if ( V_74 -> V_57 == F_19 ( 0 ) ) {
unsigned int V_23 ;
for ( V_23 = 0 ; V_23 <= V_2 -> V_5 . V_26 ; ++ V_23 ) {
V_21 = F_21 ( & V_2 -> V_5 , V_51 ,
V_23 , V_74 -> V_60 ) ;
V_21 -> V_53 = V_74 -> V_21 . V_53 ;
}
}
return 0 ;
}
static int F_29 ( struct V_15 * V_16 ,
struct V_50 * V_51 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
if ( V_83 -> V_57 == V_2 -> V_5 . V_26 )
return - V_59 ;
switch ( V_83 -> V_84 ) {
case V_85 :
V_83 -> V_86 . V_80 = 0 ;
V_83 -> V_86 . V_81 = 0 ;
V_83 -> V_86 . V_32 = V_66 ;
V_83 -> V_86 . V_34 = V_66 ;
return 0 ;
case V_87 :
V_83 -> V_86 = * F_23 ( V_2 , V_51 , V_83 -> V_57 , V_83 -> V_60 ) ;
return 0 ;
default:
return - V_59 ;
}
}
static int F_30 ( struct V_15 * V_16 ,
struct V_50 * V_51 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
struct V_20 * V_21 ;
struct V_69 * V_72 ;
if ( V_83 -> V_57 == V_2 -> V_5 . V_26 )
return - V_59 ;
if ( V_83 -> V_84 != V_87 )
return - V_59 ;
V_21 = F_21 ( & V_2 -> V_5 , V_51 ,
V_2 -> V_5 . V_26 , V_83 -> V_60 ) ;
V_83 -> V_86 . V_80 = F_31 (unsigned int, sel->r.left, 0 , format->width - 1 ) ;
V_83 -> V_86 . V_81 = F_31 (unsigned int, sel->r.top, 0 , format->height - 1 ) ;
V_21 = F_21 ( & V_2 -> V_5 , V_51 , V_83 -> V_57 ,
V_83 -> V_60 ) ;
V_83 -> V_86 . V_32 = V_21 -> V_32 ;
V_83 -> V_86 . V_34 = V_21 -> V_34 ;
V_72 = F_23 ( V_2 , V_51 , V_83 -> V_57 , V_83 -> V_60 ) ;
* V_72 = V_83 -> V_86 ;
return 0 ;
}
struct V_1 * F_32 ( struct V_88 * V_89 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_24 ;
V_2 = F_33 ( V_89 -> V_90 , sizeof( * V_2 ) , V_91 ) ;
if ( V_2 == NULL )
return F_34 ( - V_92 ) ;
V_2 -> V_5 . type = V_93 ;
V_24 = F_35 ( V_89 , & V_2 -> V_5 ,
V_89 -> V_94 -> V_95 + 1 ) ;
if ( V_24 < 0 )
return F_34 ( V_24 ) ;
V_16 = & V_2 -> V_5 . V_16 ;
F_36 ( V_16 , & V_96 ) ;
V_16 -> V_5 . V_97 = & V_89 -> V_98 ;
V_16 -> V_99 = & V_100 ;
snprintf ( V_16 -> V_101 , sizeof( V_16 -> V_101 ) , L_1 ,
F_37 ( V_89 -> V_90 ) ) ;
F_38 ( V_16 , V_2 ) ;
V_16 -> V_22 |= V_102 ;
F_39 ( V_16 , NULL ) ;
F_40 ( & V_2 -> V_9 , 1 ) ;
F_41 ( & V_2 -> V_9 , & V_103 , V_11 ,
0 , 0xffffff , 1 , 0 ) ;
V_2 -> V_5 . V_16 . V_104 = & V_2 -> V_9 ;
if ( V_2 -> V_9 . error ) {
F_42 ( V_89 -> V_90 , L_2 ) ;
V_24 = V_2 -> V_9 . error ;
F_43 ( & V_2 -> V_5 ) ;
return F_34 ( V_24 ) ;
}
return V_2 ;
}
