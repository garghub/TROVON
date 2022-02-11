static enum V_1 F_1 (
struct V_2 * V_3 , T_1 V_4 )
{
V_4 -= V_3 -> V_5 ;
V_4 /= ( V_6 ) V_3 -> V_7 ;
if ( V_3 -> V_5 )
++ V_4 ;
return V_4 ;
}
static T_1 F_2 ( struct V_2 * V_3 ,
enum V_1 V_8 )
{
if ( V_3 -> V_9 != V_10 )
-- V_8 ;
return ( V_8 * V_3 -> V_7 ) + V_3 -> V_5 ;
}
static void F_3 ( struct V_11 * V_11 ,
struct V_2 * V_3 )
{
struct V_2 * * V_12 = V_11 -> V_12 ;
enum V_1 V_8 ;
if ( F_4 ( V_11 , V_13 ) )
V_8 = F_5 ( V_11 ,
V_13 ,
V_3 -> V_14 ) ;
else
V_8 = F_1 ( V_3 , V_3 -> V_14 ) ;
if ( F_4 ( V_11 , V_15 ) )
V_3 -> V_14 = F_5 ( V_11 ,
V_15 ,
V_8 ) ;
if ( V_3 == V_12 [ V_16 ] ) {
if ( V_12 [ V_17 ] -> V_14 != V_18 )
return;
F_6 ( & V_11 -> V_19 -> V_20 ,
V_8 ) ;
} else {
F_6 ( & V_11 -> V_21 -> V_20 ,
V_8 ) ;
}
}
static int F_7 ( struct V_11 * V_11 ,
struct V_2 * V_3 )
{
struct V_2 * * V_12 = V_11 -> V_12 ;
struct V_22 * V_20 ;
int V_23 ;
if ( V_3 == V_12 [ V_16 ] ) {
if ( V_12 [ V_17 ] -> V_14 != V_18 )
return 0 ;
V_20 = & V_11 -> V_19 -> V_20 ;
} else {
V_20 = & V_11 -> V_21 -> V_20 ;
}
V_23 = F_8 ( V_20 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( F_4 ( V_11 , V_15 ) )
V_3 -> V_14 = F_5 ( V_11 ,
V_15 ,
V_20 -> V_8 ) ;
else
V_3 -> V_14 = F_2 ( V_3 ,
V_20 -> V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_24 )
{
struct V_11 * V_11 = F_10 ( V_24 ) ;
struct V_25 * V_19 = V_11 -> V_19 ;
bool V_26 ;
int V_23 ;
switch ( V_24 -> V_9 ) {
case V_27 :
case V_10 :
return F_7 ( V_11 , V_24 ) ;
case V_28 :
V_23 = F_11 ( V_19 ) ;
if ( V_23 < 0 )
return V_23 ;
V_24 -> V_14 = V_19 -> V_8 . V_14 ;
return 0 ;
case V_29 :
V_23 = F_12 ( V_19 , & V_26 ) ;
if ( V_23 < 0 )
return V_23 ;
V_24 -> V_14 = V_26 ;
return 0 ;
case V_30 :
return F_13 ( V_19 , & V_24 -> V_14 ) ;
default:
return - V_31 ;
}
}
static bool F_14 ( struct V_2 * * V_12 )
{
return ( ( V_12 [ V_17 ] -> V_14 != V_32 ) ||
( V_12 [ V_33 ] && ( V_12 [ V_33 ] -> V_14 !=
V_34 ) ) ) ;
}
static int F_15 ( struct V_2 * V_24 )
{
struct V_11 * V_11 = F_10 ( V_24 ) ;
struct V_25 * V_19 = V_11 -> V_19 ;
struct V_22 * V_20 = & V_19 -> V_20 ;
struct V_2 * * V_12 = V_11 -> V_12 ;
bool V_35 ;
int V_23 = 0 ;
switch ( V_24 -> V_9 ) {
case V_36 :
switch ( V_24 -> V_14 ) {
case V_37 :
F_6 ( V_20 , V_38 ) ;
return F_16 ( V_19 , false ) ;
case V_32 :
F_6 ( V_20 , V_38 ) ;
if ( V_12 [ V_33 ] ) {
V_35 = ( V_12 [ V_33 ] -> V_14 ==
V_39 ) ;
V_23 = F_5 ( V_11 ,
V_40 ,
V_35 ) ;
}
return V_23 ;
case V_18 :
if ( V_12 [ V_33 ] ) {
V_23 = F_5 ( V_11 ,
V_40 ,
false ) ;
if ( V_23 < 0 )
return V_23 ;
}
V_23 = F_16 ( V_19 , false ) ;
if ( V_23 < 0 )
return V_23 ;
F_3 ( V_11 ,
V_12 [ V_16 ] ) ;
return 0 ;
}
break;
case V_41 :
V_35 = ( V_24 -> V_14 == V_39 ) ;
if ( V_12 [ V_17 ] -> V_14 != V_32 )
return 0 ;
return F_5 ( V_11 , V_40 ,
V_35 ) ;
case V_42 :
if ( F_14 ( V_12 ) )
return - V_43 ;
return F_16 ( V_19 , true ) ;
case V_44 :
if ( F_14 ( V_12 ) )
return - V_43 ;
return F_16 ( V_19 , false ) ;
case V_45 :
return F_17 ( V_19 , V_24 -> V_14 ) ;
case V_28 :
return F_18 ( V_19 , V_24 -> V_14 ) ;
case V_27 :
case V_10 :
F_3 ( V_11 , V_24 ) ;
return 0 ;
}
return - V_31 ;
}
static void F_19 ( struct V_46 * V_47 ,
struct V_48 * V_24 )
{
V_24 -> V_49 = V_47 -> V_49 ;
V_24 -> V_50 = V_47 -> V_50 ;
V_24 -> V_7 = V_47 -> V_7 ;
V_24 -> V_51 = V_47 -> V_14 ;
}
static void F_20 ( struct V_11 * V_11 ,
struct V_52 * V_53 ,
struct V_54 * V_55 )
{
struct V_25 * V_19 = V_11 -> V_19 ;
const struct V_56 * V_57 = V_19 -> V_58 ;
struct V_22 * V_20 = & V_19 -> V_20 ;
struct V_48 * V_59 ;
V_6 V_60 ;
if ( V_53 -> V_61 ) {
V_55 [ V_62 ] . V_63 = V_30 ;
V_59 = & V_55 [ V_62 ] . V_64 ;
V_59 -> V_9 = V_30 ;
V_59 -> V_50 = V_53 -> V_61 ;
V_59 -> V_65 = V_66 |
V_67 ;
}
V_60 = 1 << V_37 |
1 << V_18 ;
if ( V_20 -> V_65 & V_68 )
V_60 |= 1 << V_32 ;
V_55 [ V_17 ] . V_63 = V_36 ;
V_59 = & V_55 [ V_17 ] . V_64 ;
V_59 -> V_9 = V_36 ;
V_59 -> V_50 = V_18 ;
V_59 -> V_69 = ~ V_60 ;
V_59 -> V_51 = V_37 ;
V_59 -> V_65 = 0 ;
V_55 [ V_16 ] . V_63 = V_27 ;
V_59 = & V_55 [ V_16 ] . V_64 ;
F_19 ( & V_53 -> V_70 , V_59 ) ;
V_59 -> V_9 = V_27 ;
V_59 -> V_65 = V_66 |
V_71 ;
if ( V_11 -> V_21 ) {
V_55 [ V_72 ] . V_63 =
V_10 ;
V_59 = & V_55 [ V_72 ] . V_64 ;
F_19 ( & V_53 -> V_73 ,
V_59 ) ;
V_59 -> V_9 = V_10 ;
V_59 -> V_49 = 0 ;
V_59 -> V_65 = V_66 |
V_71 ;
}
if ( ! ( V_20 -> V_65 & V_68 ) )
return;
V_55 [ V_74 ] . V_63 = V_42 ;
V_59 = & V_55 [ V_74 ] . V_64 ;
V_59 -> V_9 = V_42 ;
V_55 [ V_75 ] . V_63 = V_44 ;
V_59 = & V_55 [ V_75 ] . V_64 ;
V_59 -> V_9 = V_44 ;
if ( V_53 -> V_76 ) {
V_60 = ( 1 << V_34 ) |
( 1 << V_39 ) ;
V_55 [ V_33 ] . V_63 =
V_41 ;
V_59 = & V_55 [ V_33 ] . V_64 ;
V_59 -> V_9 = V_41 ;
V_59 -> V_50 = V_39 ;
V_59 -> V_69 = ~ V_60 ;
V_59 -> V_51 = V_34 ;
}
if ( V_57 -> V_77 ) {
V_55 [ V_78 ] . V_63 =
V_29 ;
V_59 = & V_55 [ V_78 ] . V_64 ;
V_59 -> V_9 = V_29 ;
V_59 -> V_65 = V_66 |
V_67 ;
}
if ( V_57 -> V_79 ) {
V_55 [ V_80 ] . V_63 = V_45 ;
V_59 = & V_55 [ V_80 ] . V_64 ;
F_19 ( & V_19 -> V_81 , V_59 ) ;
V_59 -> V_9 = V_45 ;
}
if ( V_57 -> V_82 ) {
V_55 [ V_83 ] . V_63 = V_28 ;
V_59 = & V_55 [ V_83 ] . V_64 ;
F_19 ( & V_19 -> V_8 , V_59 ) ;
V_59 -> V_9 = V_28 ;
V_59 -> V_65 = V_66 |
V_71 ;
}
}
static int F_21 ( struct V_11 * V_11 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 ;
struct V_2 * V_3 ;
struct V_48 * V_59 ;
int V_84 , V_23 , V_85 = 0 ;
V_11 -> V_12 = F_22 ( V_11 -> V_86 . V_87 ,
sizeof( * V_11 -> V_12 ) *
( V_33 + 1 ) , V_88 ) ;
if ( ! V_11 -> V_12 )
return - V_89 ;
V_55 = F_23 ( V_90 , sizeof( * V_55 ) ,
V_88 ) ;
if ( ! V_55 )
return - V_89 ;
F_20 ( V_11 , V_53 , V_55 ) ;
for ( V_84 = 0 ; V_84 < V_90 ; ++ V_84 )
if ( V_55 [ V_84 ] . V_63 )
++ V_85 ;
F_24 ( & V_11 -> V_91 , V_85 ) ;
for ( V_84 = 0 ; V_84 < V_90 ; ++ V_84 ) {
V_59 = & V_55 [ V_84 ] . V_64 ;
if ( ! V_55 [ V_84 ] . V_63 )
continue;
if ( V_59 -> V_9 == V_36 ||
V_59 -> V_9 == V_41 )
V_3 = F_25 ( & V_11 -> V_91 ,
& V_92 ,
V_59 -> V_9 ,
V_59 -> V_50 ,
V_59 -> V_69 ,
V_59 -> V_51 ) ;
else
V_3 = F_26 ( & V_11 -> V_91 ,
& V_92 ,
V_59 -> V_9 ,
V_59 -> V_49 ,
V_59 -> V_50 ,
V_59 -> V_7 ,
V_59 -> V_51 ) ;
if ( V_3 )
V_3 -> V_65 |= V_59 -> V_65 ;
if ( V_84 <= V_33 )
V_11 -> V_12 [ V_84 ] = V_3 ;
}
F_27 ( V_55 ) ;
if ( V_11 -> V_91 . error ) {
V_23 = V_11 -> V_91 . error ;
goto V_93;
}
F_28 ( & V_11 -> V_91 ) ;
V_11 -> V_86 . V_94 = & V_11 -> V_91 ;
return 0 ;
V_93:
F_29 ( & V_11 -> V_91 ) ;
return V_23 ;
}
static int F_30 ( struct V_11 * V_11 )
{
struct V_25 * V_19 = V_11 -> V_19 ;
struct V_2 * * V_12 = V_11 -> V_12 ;
int V_23 = 0 ;
F_3 ( V_11 , V_12 [ V_16 ] ) ;
if ( V_12 [ V_72 ] )
F_3 ( V_11 ,
V_12 [ V_72 ] ) ;
if ( V_12 [ V_80 ] ) {
V_23 = F_17 ( V_19 ,
V_12 [ V_80 ] -> V_14 ) ;
if ( V_23 < 0 )
return V_23 ;
}
if ( V_12 [ V_83 ] ) {
V_23 = F_18 ( V_19 ,
V_12 [ V_83 ] -> V_14 ) ;
if ( V_23 < 0 )
return V_23 ;
}
if ( V_12 [ V_33 ] &&
V_12 [ V_17 ] -> V_14 != V_18 )
V_23 = F_5 ( V_11 , V_40 ,
V_12 [ V_33 ] -> V_14 ) ;
return V_23 ;
}
static int F_31 ( struct V_95 * V_86 , struct V_96 * V_97 )
{
struct V_11 * V_11 = F_32 ( V_86 ) ;
struct V_25 * V_19 = V_11 -> V_19 ;
struct V_22 * V_20 = & V_19 -> V_20 ;
struct V_25 * V_21 = V_11 -> V_21 ;
struct V_22 * V_98 = NULL ;
int V_23 = 0 ;
if ( ! F_33 ( & V_97 -> V_99 ) )
return 0 ;
F_34 ( & V_20 -> V_100 ) ;
F_35 ( V_20 ) ;
F_36 ( V_20 ) ;
F_37 ( & V_20 -> V_100 ) ;
if ( V_21 ) {
V_98 = & V_21 -> V_20 ;
F_34 ( & V_98 -> V_100 ) ;
F_35 ( V_98 ) ;
F_36 ( V_98 ) ;
F_37 ( & V_98 -> V_100 ) ;
}
V_23 = F_30 ( V_11 ) ;
if ( V_23 < 0 )
goto V_101;
return 0 ;
V_101:
F_34 ( & V_20 -> V_100 ) ;
F_38 ( V_20 ) ;
F_37 ( & V_20 -> V_100 ) ;
if ( V_98 ) {
F_34 ( & V_98 -> V_100 ) ;
F_38 ( V_98 ) ;
F_37 ( & V_98 -> V_100 ) ;
}
return V_23 ;
}
static int F_39 ( struct V_95 * V_86 , struct V_96 * V_97 )
{
struct V_11 * V_11 = F_32 ( V_86 ) ;
struct V_25 * V_19 = V_11 -> V_19 ;
struct V_22 * V_20 = & V_19 -> V_20 ;
struct V_25 * V_21 = V_11 -> V_21 ;
int V_23 = 0 ;
if ( ! F_33 ( & V_97 -> V_99 ) )
return 0 ;
F_34 ( & V_20 -> V_100 ) ;
if ( V_11 -> V_12 [ V_33 ] )
V_23 = F_40 ( V_11 -> V_12 [ V_33 ] ,
V_34 ) ;
F_38 ( V_20 ) ;
F_37 ( & V_20 -> V_100 ) ;
if ( V_21 ) {
struct V_22 * V_98 = & V_21 -> V_20 ;
F_34 ( & V_98 -> V_100 ) ;
F_38 ( V_98 ) ;
F_37 ( & V_98 -> V_100 ) ;
}
return V_23 ;
}
struct V_11 * F_41 (
struct V_102 * V_87 , struct V_103 * V_104 ,
struct V_25 * V_19 ,
struct V_25 * V_21 ,
const struct V_105 * V_58 ,
struct V_52 * V_64 )
{
struct V_11 * V_11 ;
struct V_22 * V_20 ;
struct V_95 * V_86 ;
int V_23 ;
if ( ! V_19 || ! V_58 || ! V_64 )
return F_42 ( - V_31 ) ;
V_20 = & V_19 -> V_20 ;
V_11 = F_22 ( V_20 -> V_87 , sizeof( * V_11 ) ,
V_88 ) ;
if ( ! V_11 )
return F_42 ( - V_89 ) ;
V_86 = & V_11 -> V_86 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_21 = V_21 ;
V_11 -> V_58 = V_58 ;
V_86 -> V_87 = V_87 ;
V_86 -> V_104 = V_104 ;
F_43 ( V_86 , & V_106 ) ;
V_86 -> V_107 = & V_108 ;
V_86 -> V_65 |= V_109 ;
F_44 ( V_86 -> V_110 , V_64 -> V_111 , sizeof( V_86 -> V_110 ) ) ;
V_23 = F_45 ( & V_86 -> V_112 , 0 , NULL , 0 ) ;
if ( V_23 < 0 )
return F_42 ( V_23 ) ;
V_86 -> V_112 . type = V_113 ;
V_23 = F_21 ( V_11 , V_64 ) ;
if ( V_23 < 0 )
goto V_114;
if ( V_86 -> V_104 )
F_46 ( V_86 -> V_104 ) ;
else
F_46 ( V_20 -> V_87 -> V_104 ) ;
V_23 = F_47 ( V_86 ) ;
if ( V_23 < 0 )
goto V_115;
return V_11 ;
V_115:
F_48 ( V_20 -> V_87 -> V_104 ) ;
F_29 ( V_86 -> V_94 ) ;
V_114:
F_49 ( & V_86 -> V_112 ) ;
return F_42 ( V_23 ) ;
}
void F_50 ( struct V_11 * V_11 )
{
struct V_95 * V_86 ;
struct V_22 * V_20 ;
if ( F_51 ( V_11 ) )
return;
V_86 = & V_11 -> V_86 ;
V_20 = & V_11 -> V_19 -> V_20 ;
F_52 ( V_86 ) ;
if ( V_86 -> V_104 )
F_48 ( V_86 -> V_104 ) ;
else
F_48 ( V_20 -> V_87 -> V_104 ) ;
F_29 ( V_86 -> V_94 ) ;
F_49 ( & V_86 -> V_112 ) ;
}
