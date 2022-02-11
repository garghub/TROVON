static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
F_2 ( V_4 , V_5 , V_6 ) ;
}
static int F_3 ( struct V_7 * V_8 )
{
struct V_1 * V_2 =
F_4 ( V_8 -> V_9 , struct V_1 , V_10 ) ;
switch ( V_8 -> V_11 ) {
case V_12 :
V_2 -> V_13 = V_8 -> V_14 ;
break;
}
return 0 ;
}
static int F_5 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_19 * V_20 )
{
static const unsigned int V_21 [] = {
V_22 ,
V_23 ,
} ;
return F_6 ( V_16 , V_18 , V_20 , V_21 ,
F_7 ( V_21 ) ) ;
}
static int F_8 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_24 * V_25 )
{
if ( V_25 -> V_26 )
return - V_27 ;
if ( V_25 -> V_20 != V_22 &&
V_25 -> V_20 != V_23 )
return - V_27 ;
V_25 -> V_28 = V_29 ;
V_25 -> V_30 = V_31 ;
V_25 -> V_32 = V_29 ;
V_25 -> V_33 = V_31 ;
return 0 ;
}
static struct V_34 * F_9 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
unsigned int V_35 )
{
return F_10 ( & V_2 -> V_36 . V_16 , V_18 , V_35 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_17 * V_37 ,
unsigned int V_35 , struct V_38 * V_39 )
{
struct V_38 * V_40 ;
switch ( V_35 ) {
case F_12 ( 0 ) :
if ( V_39 -> V_20 != V_22 &&
V_39 -> V_20 != V_23 )
V_39 -> V_20 = V_23 ;
break;
default:
V_40 = F_13 ( & V_2 -> V_36 , V_37 ,
F_12 ( 0 ) ) ;
V_39 -> V_20 = V_40 -> V_20 ;
break;
}
V_39 -> V_41 = F_14 ( V_39 -> V_41 , V_29 , V_31 ) ;
V_39 -> V_42 = F_14 ( V_39 -> V_42 , V_29 , V_31 ) ;
V_39 -> V_43 = V_44 ;
V_39 -> V_45 = V_46 ;
}
static int F_15 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_47 * V_39 )
{
struct V_1 * V_2 = F_16 ( V_16 ) ;
struct V_17 * V_37 ;
struct V_38 * V_40 ;
int V_48 = 0 ;
F_17 ( & V_2 -> V_36 . V_49 ) ;
V_37 = F_18 ( & V_2 -> V_36 , V_18 , V_39 -> V_50 ) ;
if ( ! V_37 ) {
V_48 = - V_27 ;
goto V_51;
}
F_11 ( V_2 , V_37 , V_39 -> V_35 , & V_39 -> V_40 ) ;
V_40 = F_13 ( & V_2 -> V_36 , V_37 , V_39 -> V_35 ) ;
* V_40 = V_39 -> V_40 ;
if ( V_39 -> V_35 != V_2 -> V_36 . V_52 ) {
struct V_34 * V_53 ;
V_53 = F_9 ( V_2 , V_37 , V_39 -> V_35 ) ;
V_53 -> V_54 = 0 ;
V_53 -> V_55 = 0 ;
V_53 -> V_41 = V_40 -> V_41 ;
V_53 -> V_42 = V_40 -> V_42 ;
}
if ( V_39 -> V_35 == F_12 ( 0 ) ) {
unsigned int V_56 ;
for ( V_56 = 0 ; V_56 <= V_2 -> V_36 . V_52 ; ++ V_56 ) {
V_40 = F_13 ( & V_2 -> V_36 ,
V_37 , V_56 ) ;
V_40 -> V_20 = V_39 -> V_40 . V_20 ;
}
}
V_51:
F_19 ( & V_2 -> V_36 . V_49 ) ;
return V_48 ;
}
static int F_20 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_16 ( V_16 ) ;
struct V_17 * V_37 ;
if ( V_58 -> V_35 == V_2 -> V_36 . V_52 )
return - V_27 ;
switch ( V_58 -> V_59 ) {
case V_60 :
V_58 -> V_61 . V_54 = 0 ;
V_58 -> V_61 . V_55 = 0 ;
V_58 -> V_61 . V_41 = V_31 ;
V_58 -> V_61 . V_42 = V_31 ;
return 0 ;
case V_62 :
V_37 = F_18 ( & V_2 -> V_36 , V_18 ,
V_58 -> V_50 ) ;
if ( ! V_37 )
return - V_27 ;
F_17 ( & V_2 -> V_36 . V_49 ) ;
V_58 -> V_61 = * F_9 ( V_2 , V_37 , V_58 -> V_35 ) ;
F_19 ( & V_2 -> V_36 . V_49 ) ;
return 0 ;
default:
return - V_27 ;
}
}
static int F_21 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_16 ( V_16 ) ;
struct V_17 * V_37 ;
struct V_38 * V_40 ;
struct V_34 * V_53 ;
int V_48 = 0 ;
if ( V_58 -> V_35 == V_2 -> V_36 . V_52 )
return - V_27 ;
if ( V_58 -> V_59 != V_62 )
return - V_27 ;
F_17 ( & V_2 -> V_36 . V_49 ) ;
V_37 = F_18 ( & V_2 -> V_36 , V_18 , V_58 -> V_50 ) ;
if ( ! V_37 ) {
V_48 = - V_27 ;
goto V_51;
}
V_40 = F_13 ( & V_2 -> V_36 , V_37 ,
V_2 -> V_36 . V_52 ) ;
V_58 -> V_61 . V_54 = F_22 (unsigned int, sel->r.left, 0 , format->width - 1 ) ;
V_58 -> V_61 . V_55 = F_22 (unsigned int, sel->r.top, 0 , format->height - 1 ) ;
V_40 = F_13 ( & V_2 -> V_36 , V_37 , V_58 -> V_35 ) ;
V_58 -> V_61 . V_41 = V_40 -> V_41 ;
V_58 -> V_61 . V_42 = V_40 -> V_42 ;
V_53 = F_9 ( V_2 , V_37 , V_58 -> V_35 ) ;
* V_53 = V_58 -> V_61 ;
V_51:
F_19 ( & V_2 -> V_36 . V_49 ) ;
return V_48 ;
}
static void F_23 ( struct V_63 * V_36 ,
struct V_64 * V_65 ,
struct V_3 * V_4 ,
enum V_66 V_67 )
{
struct V_1 * V_2 = F_16 ( & V_36 -> V_16 ) ;
struct V_38 * V_40 ;
unsigned int V_68 ;
unsigned int V_56 ;
if ( V_67 != V_69 )
return;
V_40 = F_13 ( & V_2 -> V_36 , V_2 -> V_36 . V_37 ,
V_2 -> V_36 . V_52 ) ;
V_68 = V_65 -> V_70 ? V_65 -> V_70 -> V_40 . V_68 : 0 ;
F_1 ( V_2 , V_4 , V_71 ,
V_68 & V_72 ?
0 : V_73 ) ;
F_1 ( V_2 , V_4 , V_74 ,
( V_40 -> V_41 << V_75 ) |
( V_40 -> V_42 << V_76 ) ) ;
F_1 ( V_2 , V_4 , V_77 , 0 ) ;
F_1 ( V_2 , V_4 , V_78 , V_2 -> V_13 |
( 0xff << V_79 ) ) ;
F_1 ( V_2 , V_4 , V_80 , F_24 ( 1 ) |
F_25 ( V_81 ) |
F_26 ( V_81 ) ) ;
for ( V_56 = 0 ; V_56 < V_2 -> V_36 . V_52 ; ++ V_56 ) {
bool V_82 = false ;
T_1 V_8 = 0 ;
if ( V_2 -> V_83 [ V_56 ] . V_84 ) {
V_8 |= V_85 ;
V_82 = V_2 -> V_83 [ V_56 ] . V_84 -> V_40 . V_68
& V_72 ;
} else {
V_8 |= F_27 ( V_81 )
| F_28 ( V_81 ) ;
}
if ( V_56 == 0 )
V_8 |= V_86 ;
if ( V_56 != 1 )
V_8 |= F_29 ( V_56 ) ;
F_1 ( V_2 , V_4 , F_30 ( V_56 ) , V_8 ) ;
F_1 ( V_2 , V_4 , F_31 ( V_56 ) ,
V_87 |
( V_82 ? V_88 :
V_89 ) |
V_90 |
V_91 |
( 0xff << V_92 ) ) ;
}
}
struct V_1 * F_32 ( struct V_93 * V_94 )
{
struct V_1 * V_2 ;
int V_48 ;
V_2 = F_33 ( V_94 -> V_95 , sizeof( * V_2 ) , V_96 ) ;
if ( V_2 == NULL )
return F_34 ( - V_97 ) ;
V_2 -> V_36 . V_98 = & V_99 ;
V_2 -> V_36 . type = V_100 ;
V_48 = F_35 ( V_94 , & V_2 -> V_36 , L_1 ,
V_94 -> V_101 -> V_102 + 1 , & V_103 ,
V_104 ) ;
if ( V_48 < 0 )
return F_34 ( V_48 ) ;
F_36 ( & V_2 -> V_10 , 1 ) ;
F_37 ( & V_2 -> V_10 , & V_105 , V_12 ,
0 , 0xffffff , 1 , 0 ) ;
V_2 -> V_13 = 0 ;
V_2 -> V_36 . V_16 . V_106 = & V_2 -> V_10 ;
if ( V_2 -> V_10 . error ) {
F_38 ( V_94 -> V_95 , L_2 ) ;
V_48 = V_2 -> V_10 . error ;
F_39 ( & V_2 -> V_36 ) ;
return F_34 ( V_48 ) ;
}
return V_2 ;
}
