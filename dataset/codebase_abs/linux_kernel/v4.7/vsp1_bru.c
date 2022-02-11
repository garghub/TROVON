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
V_37 = F_17 ( & V_2 -> V_36 , V_18 , V_39 -> V_48 ) ;
if ( ! V_37 )
return - V_27 ;
F_11 ( V_2 , V_37 , V_39 -> V_35 , & V_39 -> V_40 ) ;
V_40 = F_13 ( & V_2 -> V_36 , V_37 , V_39 -> V_35 ) ;
* V_40 = V_39 -> V_40 ;
if ( V_39 -> V_35 != V_2 -> V_36 . V_49 ) {
struct V_34 * V_50 ;
V_50 = F_9 ( V_2 , V_37 , V_39 -> V_35 ) ;
V_50 -> V_51 = 0 ;
V_50 -> V_52 = 0 ;
V_50 -> V_41 = V_40 -> V_41 ;
V_50 -> V_42 = V_40 -> V_42 ;
}
if ( V_39 -> V_35 == F_12 ( 0 ) ) {
unsigned int V_53 ;
for ( V_53 = 0 ; V_53 <= V_2 -> V_36 . V_49 ; ++ V_53 ) {
V_40 = F_13 ( & V_2 -> V_36 ,
V_37 , V_53 ) ;
V_40 -> V_20 = V_39 -> V_40 . V_20 ;
}
}
return 0 ;
}
static int F_18 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 = F_16 ( V_16 ) ;
struct V_17 * V_37 ;
if ( V_55 -> V_35 == V_2 -> V_36 . V_49 )
return - V_27 ;
switch ( V_55 -> V_56 ) {
case V_57 :
V_55 -> V_58 . V_51 = 0 ;
V_55 -> V_58 . V_52 = 0 ;
V_55 -> V_58 . V_41 = V_31 ;
V_55 -> V_58 . V_42 = V_31 ;
return 0 ;
case V_59 :
V_37 = F_17 ( & V_2 -> V_36 , V_18 ,
V_55 -> V_48 ) ;
if ( ! V_37 )
return - V_27 ;
V_55 -> V_58 = * F_9 ( V_2 , V_37 , V_55 -> V_35 ) ;
return 0 ;
default:
return - V_27 ;
}
}
static int F_19 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 = F_16 ( V_16 ) ;
struct V_17 * V_37 ;
struct V_38 * V_40 ;
struct V_34 * V_50 ;
if ( V_55 -> V_35 == V_2 -> V_36 . V_49 )
return - V_27 ;
if ( V_55 -> V_56 != V_59 )
return - V_27 ;
V_37 = F_17 ( & V_2 -> V_36 , V_18 , V_55 -> V_48 ) ;
if ( ! V_37 )
return - V_27 ;
V_40 = F_13 ( & V_2 -> V_36 , V_37 ,
V_2 -> V_36 . V_49 ) ;
V_55 -> V_58 . V_51 = F_20 (unsigned int, sel->r.left, 0 , format->width - 1 ) ;
V_55 -> V_58 . V_52 = F_20 (unsigned int, sel->r.top, 0 , format->height - 1 ) ;
V_40 = F_13 ( & V_2 -> V_36 , V_37 , V_55 -> V_35 ) ;
V_55 -> V_58 . V_41 = V_40 -> V_41 ;
V_55 -> V_58 . V_42 = V_40 -> V_42 ;
V_50 = F_9 ( V_2 , V_37 , V_55 -> V_35 ) ;
* V_50 = V_55 -> V_58 ;
return 0 ;
}
static void F_21 ( struct V_60 * V_36 ,
struct V_61 * V_62 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = F_16 ( & V_36 -> V_16 ) ;
struct V_38 * V_40 ;
unsigned int V_63 ;
unsigned int V_53 ;
V_40 = F_13 ( & V_2 -> V_36 , V_2 -> V_36 . V_37 ,
V_2 -> V_36 . V_49 ) ;
V_63 = V_62 -> V_64 ? V_62 -> V_64 -> V_40 . V_63 : 0 ;
F_1 ( V_2 , V_4 , V_65 ,
V_63 & V_66 ?
0 : V_67 ) ;
F_1 ( V_2 , V_4 , V_68 ,
( V_40 -> V_41 << V_69 ) |
( V_40 -> V_42 << V_70 ) ) ;
F_1 ( V_2 , V_4 , V_71 , 0 ) ;
F_1 ( V_2 , V_4 , V_72 , V_2 -> V_13 |
( 0xff << V_73 ) ) ;
F_1 ( V_2 , V_4 , V_74 , F_22 ( 1 ) |
F_23 ( V_75 ) |
F_24 ( V_75 ) ) ;
for ( V_53 = 0 ; V_53 < V_2 -> V_36 . V_49 ; ++ V_53 ) {
bool V_76 = false ;
T_1 V_8 = 0 ;
if ( V_2 -> V_77 [ V_53 ] . V_78 ) {
V_8 |= V_79 ;
V_76 = V_2 -> V_77 [ V_53 ] . V_78 -> V_40 . V_63
& V_66 ;
} else {
V_8 |= F_25 ( V_75 )
| F_26 ( V_75 ) ;
}
if ( V_53 == 0 )
V_8 |= V_80 ;
if ( V_53 != 1 )
V_8 |= F_27 ( V_53 ) ;
F_1 ( V_2 , V_4 , F_28 ( V_53 ) , V_8 ) ;
F_1 ( V_2 , V_4 , F_29 ( V_53 ) ,
V_81 |
( V_76 ? V_82 :
V_83 ) |
V_84 |
V_85 |
( 0xff << V_86 ) ) ;
}
}
struct V_1 * F_30 ( struct V_87 * V_88 )
{
struct V_1 * V_2 ;
int V_89 ;
V_2 = F_31 ( V_88 -> V_90 , sizeof( * V_2 ) , V_91 ) ;
if ( V_2 == NULL )
return F_32 ( - V_92 ) ;
V_2 -> V_36 . V_93 = & V_94 ;
V_2 -> V_36 . type = V_95 ;
V_89 = F_33 ( V_88 , & V_2 -> V_36 , L_1 ,
V_88 -> V_96 -> V_97 + 1 , & V_98 ) ;
if ( V_89 < 0 )
return F_32 ( V_89 ) ;
F_34 ( & V_2 -> V_10 , 1 ) ;
F_35 ( & V_2 -> V_10 , & V_99 , V_12 ,
0 , 0xffffff , 1 , 0 ) ;
V_2 -> V_13 = 0 ;
V_2 -> V_36 . V_16 . V_100 = & V_2 -> V_10 ;
if ( V_2 -> V_10 . error ) {
F_36 ( V_88 -> V_90 , L_2 ) ;
V_89 = V_2 -> V_10 . error ;
F_37 ( & V_2 -> V_36 ) ;
return F_32 ( V_89 ) ;
}
return V_2 ;
}
