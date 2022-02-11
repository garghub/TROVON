static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
F_2 ( V_4 , V_2 -> V_7 + V_5 , V_6 ) ;
}
static int F_3 ( struct V_8 * V_9 )
{
struct V_1 * V_2 =
F_4 ( V_9 -> V_10 , struct V_1 , V_11 ) ;
switch ( V_9 -> V_12 ) {
case V_13 :
V_2 -> V_14 = V_9 -> V_15 ;
break;
}
return 0 ;
}
static int F_5 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
struct V_20 * V_21 )
{
static const unsigned int V_22 [] = {
V_23 ,
V_24 ,
} ;
return F_6 ( V_17 , V_19 , V_21 , V_22 ,
F_7 ( V_22 ) ) ;
}
static int F_8 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
struct V_25 * V_26 )
{
if ( V_26 -> V_27 )
return - V_28 ;
if ( V_26 -> V_21 != V_23 &&
V_26 -> V_21 != V_24 )
return - V_28 ;
V_26 -> V_29 = V_30 ;
V_26 -> V_31 = V_32 ;
V_26 -> V_33 = V_30 ;
V_26 -> V_34 = V_32 ;
return 0 ;
}
static struct V_35 * F_9 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
unsigned int V_36 )
{
return F_10 ( & V_2 -> V_37 . V_17 , V_19 , V_36 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_18 * V_38 ,
unsigned int V_36 , struct V_39 * V_40 )
{
struct V_39 * V_41 ;
switch ( V_36 ) {
case F_12 ( 0 ) :
if ( V_40 -> V_21 != V_23 &&
V_40 -> V_21 != V_24 )
V_40 -> V_21 = V_24 ;
break;
default:
V_41 = F_13 ( & V_2 -> V_37 , V_38 ,
F_12 ( 0 ) ) ;
V_40 -> V_21 = V_41 -> V_21 ;
break;
}
V_40 -> V_42 = F_14 ( V_40 -> V_42 , V_30 , V_32 ) ;
V_40 -> V_43 = F_14 ( V_40 -> V_43 , V_30 , V_32 ) ;
V_40 -> V_44 = V_45 ;
V_40 -> V_46 = V_47 ;
}
static int F_15 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
struct V_48 * V_40 )
{
struct V_1 * V_2 = F_16 ( V_17 ) ;
struct V_18 * V_38 ;
struct V_39 * V_41 ;
int V_49 = 0 ;
F_17 ( & V_2 -> V_37 . V_50 ) ;
V_38 = F_18 ( & V_2 -> V_37 , V_19 , V_40 -> V_51 ) ;
if ( ! V_38 ) {
V_49 = - V_28 ;
goto V_52;
}
F_11 ( V_2 , V_38 , V_40 -> V_36 , & V_40 -> V_41 ) ;
V_41 = F_13 ( & V_2 -> V_37 , V_38 , V_40 -> V_36 ) ;
* V_41 = V_40 -> V_41 ;
if ( V_40 -> V_36 != V_2 -> V_37 . V_53 ) {
struct V_35 * V_54 ;
V_54 = F_9 ( V_2 , V_38 , V_40 -> V_36 ) ;
V_54 -> V_55 = 0 ;
V_54 -> V_56 = 0 ;
V_54 -> V_42 = V_41 -> V_42 ;
V_54 -> V_43 = V_41 -> V_43 ;
}
if ( V_40 -> V_36 == F_12 ( 0 ) ) {
unsigned int V_57 ;
for ( V_57 = 0 ; V_57 <= V_2 -> V_37 . V_53 ; ++ V_57 ) {
V_41 = F_13 ( & V_2 -> V_37 ,
V_38 , V_57 ) ;
V_41 -> V_21 = V_40 -> V_41 . V_21 ;
}
}
V_52:
F_19 ( & V_2 -> V_37 . V_50 ) ;
return V_49 ;
}
static int F_20 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_16 ( V_17 ) ;
struct V_18 * V_38 ;
if ( V_59 -> V_36 == V_2 -> V_37 . V_53 )
return - V_28 ;
switch ( V_59 -> V_60 ) {
case V_61 :
V_59 -> V_62 . V_55 = 0 ;
V_59 -> V_62 . V_56 = 0 ;
V_59 -> V_62 . V_42 = V_32 ;
V_59 -> V_62 . V_43 = V_32 ;
return 0 ;
case V_63 :
V_38 = F_18 ( & V_2 -> V_37 , V_19 ,
V_59 -> V_51 ) ;
if ( ! V_38 )
return - V_28 ;
F_17 ( & V_2 -> V_37 . V_50 ) ;
V_59 -> V_62 = * F_9 ( V_2 , V_38 , V_59 -> V_36 ) ;
F_19 ( & V_2 -> V_37 . V_50 ) ;
return 0 ;
default:
return - V_28 ;
}
}
static int F_21 ( struct V_16 * V_17 ,
struct V_18 * V_19 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_16 ( V_17 ) ;
struct V_18 * V_38 ;
struct V_39 * V_41 ;
struct V_35 * V_54 ;
int V_49 = 0 ;
if ( V_59 -> V_36 == V_2 -> V_37 . V_53 )
return - V_28 ;
if ( V_59 -> V_60 != V_63 )
return - V_28 ;
F_17 ( & V_2 -> V_37 . V_50 ) ;
V_38 = F_18 ( & V_2 -> V_37 , V_19 , V_59 -> V_51 ) ;
if ( ! V_38 ) {
V_49 = - V_28 ;
goto V_52;
}
V_41 = F_13 ( & V_2 -> V_37 , V_38 ,
V_2 -> V_37 . V_53 ) ;
V_59 -> V_62 . V_55 = F_22 (unsigned int, sel->r.left, 0 , format->width - 1 ) ;
V_59 -> V_62 . V_56 = F_22 (unsigned int, sel->r.top, 0 , format->height - 1 ) ;
V_41 = F_13 ( & V_2 -> V_37 , V_38 , V_59 -> V_36 ) ;
V_59 -> V_62 . V_42 = V_41 -> V_42 ;
V_59 -> V_62 . V_43 = V_41 -> V_43 ;
V_54 = F_9 ( V_2 , V_38 , V_59 -> V_36 ) ;
* V_54 = V_59 -> V_62 ;
V_52:
F_19 ( & V_2 -> V_37 . V_50 ) ;
return V_49 ;
}
static void F_23 ( struct V_64 * V_37 ,
struct V_65 * V_66 ,
struct V_3 * V_4 ,
enum V_67 V_68 )
{
struct V_1 * V_2 = F_16 ( & V_37 -> V_17 ) ;
struct V_39 * V_41 ;
unsigned int V_69 ;
unsigned int V_57 ;
if ( V_68 != V_70 )
return;
V_41 = F_13 ( & V_2 -> V_37 , V_2 -> V_37 . V_38 ,
V_2 -> V_37 . V_53 ) ;
V_69 = V_66 -> V_71 ? V_66 -> V_71 -> V_41 . V_69 : 0 ;
F_1 ( V_2 , V_4 , V_72 ,
V_69 & V_73 ?
0 : V_74 ) ;
F_1 ( V_2 , V_4 , V_75 ,
( V_41 -> V_42 << V_76 ) |
( V_41 -> V_43 << V_77 ) ) ;
F_1 ( V_2 , V_4 , V_78 , 0 ) ;
F_1 ( V_2 , V_4 , V_79 , V_2 -> V_14 |
( 0xff << V_80 ) ) ;
if ( V_37 -> type == V_81 )
F_1 ( V_2 , V_4 , V_82 ,
F_24 ( 1 ) |
F_25 ( V_83 ) |
F_26 ( V_83 ) ) ;
for ( V_57 = 0 ; V_57 < V_2 -> V_37 . V_53 ; ++ V_57 ) {
bool V_84 = false ;
T_1 V_9 = 0 ;
if ( V_2 -> V_85 [ V_57 ] . V_86 ) {
V_9 |= V_87 ;
V_84 = V_2 -> V_85 [ V_57 ] . V_86 -> V_41 . V_69
& V_73 ;
} else {
V_9 |= F_27 ( V_83 )
| F_28 ( V_83 ) ;
}
if ( V_57 == 0 )
V_9 |= V_88 ;
if ( ! ( V_37 -> type == V_81 && V_57 == 1 ) )
V_9 |= F_29 ( V_57 ) ;
F_1 ( V_2 , V_4 , F_30 ( V_57 ) , V_9 ) ;
F_1 ( V_2 , V_4 , F_31 ( V_57 ) ,
V_89 |
( V_84 ? V_90 :
V_91 ) |
V_92 |
V_93 |
( 0xff << V_94 ) ) ;
}
}
struct V_1 * F_32 ( struct V_95 * V_96 ,
enum V_97 type )
{
struct V_1 * V_2 ;
unsigned int V_98 ;
const char * V_99 ;
int V_49 ;
V_2 = F_33 ( V_96 -> V_100 , sizeof( * V_2 ) , V_101 ) ;
if ( V_2 == NULL )
return F_34 ( - V_102 ) ;
V_2 -> V_7 = type == V_81 ? V_103 : V_104 ;
V_2 -> V_37 . V_105 = & V_106 ;
V_2 -> V_37 . type = type ;
if ( type == V_81 ) {
V_98 = V_96 -> V_107 -> V_108 + 1 ;
V_99 = L_1 ;
} else {
V_98 = 3 ;
V_99 = L_2 ;
}
V_49 = F_35 ( V_96 , & V_2 -> V_37 , V_99 , V_98 , & V_109 ,
V_110 ) ;
if ( V_49 < 0 )
return F_34 ( V_49 ) ;
F_36 ( & V_2 -> V_11 , 1 ) ;
F_37 ( & V_2 -> V_11 , & V_111 , V_13 ,
0 , 0xffffff , 1 , 0 ) ;
V_2 -> V_14 = 0 ;
V_2 -> V_37 . V_17 . V_112 = & V_2 -> V_11 ;
if ( V_2 -> V_11 . error ) {
F_38 ( V_96 -> V_100 , L_3 , V_99 ) ;
V_49 = V_2 -> V_11 . error ;
F_39 ( & V_2 -> V_37 ) ;
return F_34 ( V_49 ) ;
}
return V_2 ;
}
