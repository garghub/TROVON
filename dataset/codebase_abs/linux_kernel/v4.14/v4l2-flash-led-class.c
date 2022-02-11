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
F_6 ( V_11 -> V_21 ,
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
V_20 = V_11 -> V_21 ;
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
struct V_22 * V_20 = V_19 ? & V_19 -> V_20 : NULL ;
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
struct V_22 * V_20 = V_19 ? & V_19 -> V_20 : NULL ;
struct V_48 * V_56 ;
V_6 V_57 ;
if ( V_11 -> V_21 ) {
V_55 [ V_58 ] . V_59 =
V_10 ;
V_56 = & V_55 [ V_58 ] . V_60 ;
F_19 ( & V_53 -> V_4 ,
V_56 ) ;
V_56 -> V_9 = V_10 ;
V_56 -> V_49 = 0 ;
V_56 -> V_61 = V_62 |
V_63 ;
}
if ( ! V_20 || F_21 ( ! ( V_20 -> V_61 & V_64 ) ) )
return;
if ( V_53 -> V_65 ) {
V_55 [ V_66 ] . V_59 = V_30 ;
V_56 = & V_55 [ V_66 ] . V_60 ;
V_56 -> V_9 = V_30 ;
V_56 -> V_50 = V_53 -> V_65 ;
V_56 -> V_61 = V_62 |
V_67 ;
}
V_57 = 1 << V_37 |
1 << V_18 ;
if ( V_20 -> V_61 & V_64 )
V_57 |= 1 << V_32 ;
V_55 [ V_17 ] . V_59 = V_36 ;
V_56 = & V_55 [ V_17 ] . V_60 ;
V_56 -> V_9 = V_36 ;
V_56 -> V_50 = V_18 ;
V_56 -> V_68 = ~ V_57 ;
V_56 -> V_51 = V_37 ;
V_56 -> V_61 = 0 ;
V_55 [ V_16 ] . V_59 = V_27 ;
V_56 = & V_55 [ V_16 ] . V_60 ;
F_19 ( & V_53 -> V_4 , V_56 ) ;
V_56 -> V_9 = V_27 ;
V_56 -> V_61 = V_62 |
V_63 ;
V_55 [ V_69 ] . V_59 = V_42 ;
V_56 = & V_55 [ V_69 ] . V_60 ;
V_56 -> V_9 = V_42 ;
V_55 [ V_70 ] . V_59 = V_44 ;
V_56 = & V_55 [ V_70 ] . V_60 ;
V_56 -> V_9 = V_44 ;
if ( V_53 -> V_71 ) {
V_57 = ( 1 << V_34 ) |
( 1 << V_39 ) ;
V_55 [ V_33 ] . V_59 =
V_41 ;
V_56 = & V_55 [ V_33 ] . V_60 ;
V_56 -> V_9 = V_41 ;
V_56 -> V_50 = V_39 ;
V_56 -> V_68 = ~ V_57 ;
V_56 -> V_51 = V_34 ;
}
if ( F_4 ( V_19 , V_72 ) ) {
V_55 [ V_73 ] . V_59 =
V_29 ;
V_56 = & V_55 [ V_73 ] . V_60 ;
V_56 -> V_9 = V_29 ;
V_56 -> V_61 = V_62 |
V_67 ;
}
if ( F_4 ( V_19 , V_74 ) ) {
V_55 [ V_75 ] . V_59 = V_45 ;
V_56 = & V_55 [ V_75 ] . V_60 ;
F_19 ( & V_19 -> V_76 , V_56 ) ;
V_56 -> V_9 = V_45 ;
}
if ( F_4 ( V_19 , V_77 ) ) {
V_55 [ V_78 ] . V_59 = V_28 ;
V_56 = & V_55 [ V_78 ] . V_60 ;
F_19 ( & V_19 -> V_8 , V_56 ) ;
V_56 -> V_9 = V_28 ;
V_56 -> V_61 = V_62 |
V_63 ;
}
}
static int F_22 ( struct V_11 * V_11 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 ;
struct V_2 * V_3 ;
struct V_48 * V_56 ;
int V_79 , V_23 , V_80 = 0 ;
V_11 -> V_12 = F_23 ( V_11 -> V_81 . V_82 ,
sizeof( * V_11 -> V_12 ) *
( V_33 + 1 ) , V_83 ) ;
if ( ! V_11 -> V_12 )
return - V_84 ;
V_55 = F_24 ( V_85 , sizeof( * V_55 ) ,
V_83 ) ;
if ( ! V_55 )
return - V_84 ;
F_20 ( V_11 , V_53 , V_55 ) ;
for ( V_79 = 0 ; V_79 < V_85 ; ++ V_79 )
if ( V_55 [ V_79 ] . V_59 )
++ V_80 ;
F_25 ( & V_11 -> V_86 , V_80 ) ;
for ( V_79 = 0 ; V_79 < V_85 ; ++ V_79 ) {
V_56 = & V_55 [ V_79 ] . V_60 ;
if ( ! V_55 [ V_79 ] . V_59 )
continue;
if ( V_56 -> V_9 == V_36 ||
V_56 -> V_9 == V_41 )
V_3 = F_26 ( & V_11 -> V_86 ,
& V_87 ,
V_56 -> V_9 ,
V_56 -> V_50 ,
V_56 -> V_68 ,
V_56 -> V_51 ) ;
else
V_3 = F_27 ( & V_11 -> V_86 ,
& V_87 ,
V_56 -> V_9 ,
V_56 -> V_49 ,
V_56 -> V_50 ,
V_56 -> V_7 ,
V_56 -> V_51 ) ;
if ( V_3 )
V_3 -> V_61 |= V_56 -> V_61 ;
if ( V_79 <= V_33 )
V_11 -> V_12 [ V_79 ] = V_3 ;
}
F_28 ( V_55 ) ;
if ( V_11 -> V_86 . error ) {
V_23 = V_11 -> V_86 . error ;
goto V_88;
}
F_29 ( & V_11 -> V_86 ) ;
V_11 -> V_81 . V_89 = & V_11 -> V_86 ;
return 0 ;
V_88:
F_30 ( & V_11 -> V_86 ) ;
return V_23 ;
}
static int F_31 ( struct V_11 * V_11 )
{
struct V_25 * V_19 = V_11 -> V_19 ;
struct V_2 * * V_12 = V_11 -> V_12 ;
int V_23 = 0 ;
if ( V_12 [ V_16 ] )
F_3 ( V_11 ,
V_12 [ V_16 ] ) ;
if ( V_12 [ V_58 ] )
F_3 ( V_11 ,
V_12 [ V_58 ] ) ;
if ( V_12 [ V_75 ] ) {
V_23 = F_17 ( V_19 ,
V_12 [ V_75 ] -> V_14 ) ;
if ( V_23 < 0 )
return V_23 ;
}
if ( V_12 [ V_78 ] ) {
V_23 = F_18 ( V_19 ,
V_12 [ V_78 ] -> V_14 ) ;
if ( V_23 < 0 )
return V_23 ;
}
if ( V_12 [ V_33 ] &&
V_12 [ V_17 ] -> V_14 != V_18 )
V_23 = F_5 ( V_11 , V_40 ,
V_12 [ V_33 ] -> V_14 ) ;
return V_23 ;
}
static int F_32 ( struct V_90 * V_81 , struct V_91 * V_92 )
{
struct V_11 * V_11 = F_33 ( V_81 ) ;
struct V_25 * V_19 = V_11 -> V_19 ;
struct V_22 * V_20 = V_19 ? & V_19 -> V_20 : NULL ;
struct V_22 * V_93 = V_11 -> V_21 ;
int V_23 = 0 ;
if ( ! F_34 ( & V_92 -> V_94 ) )
return 0 ;
if ( V_20 ) {
F_35 ( & V_20 -> V_95 ) ;
F_36 ( V_20 ) ;
F_37 ( V_20 ) ;
F_38 ( & V_20 -> V_95 ) ;
}
if ( V_93 ) {
F_35 ( & V_93 -> V_95 ) ;
F_36 ( V_93 ) ;
F_37 ( V_93 ) ;
F_38 ( & V_93 -> V_95 ) ;
}
V_23 = F_31 ( V_11 ) ;
if ( V_23 < 0 )
goto V_96;
return 0 ;
V_96:
if ( V_20 ) {
F_35 ( & V_20 -> V_95 ) ;
F_39 ( V_20 ) ;
F_38 ( & V_20 -> V_95 ) ;
}
if ( V_93 ) {
F_35 ( & V_93 -> V_95 ) ;
F_39 ( V_93 ) ;
F_38 ( & V_93 -> V_95 ) ;
}
return V_23 ;
}
static int F_40 ( struct V_90 * V_81 , struct V_91 * V_92 )
{
struct V_11 * V_11 = F_33 ( V_81 ) ;
struct V_25 * V_19 = V_11 -> V_19 ;
struct V_22 * V_20 = V_19 ? & V_19 -> V_20 : NULL ;
struct V_22 * V_93 = V_11 -> V_21 ;
int V_23 = 0 ;
if ( ! F_34 ( & V_92 -> V_94 ) )
return 0 ;
if ( V_20 ) {
F_35 ( & V_20 -> V_95 ) ;
if ( V_11 -> V_12 [ V_33 ] )
V_23 = F_41 (
V_11 -> V_12 [ V_33 ] ,
V_34 ) ;
F_39 ( V_20 ) ;
F_38 ( & V_20 -> V_95 ) ;
}
if ( V_93 ) {
F_35 ( & V_93 -> V_95 ) ;
F_39 ( V_93 ) ;
F_38 ( & V_93 -> V_95 ) ;
}
return V_23 ;
}
static struct V_11 * F_42 (
struct V_97 * V_82 , struct V_98 * V_99 ,
struct V_25 * V_19 , struct V_22 * V_21 ,
const struct V_100 * V_101 , struct V_52 * V_60 )
{
struct V_11 * V_11 ;
struct V_90 * V_81 ;
int V_23 ;
if ( ! V_60 )
return F_43 ( - V_31 ) ;
V_11 = F_23 ( V_82 , sizeof( * V_11 ) , V_83 ) ;
if ( ! V_11 )
return F_43 ( - V_84 ) ;
V_81 = & V_11 -> V_81 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_21 = V_21 ;
V_11 -> V_101 = V_101 ;
V_81 -> V_82 = V_82 ;
V_81 -> V_102 = V_99 ? V_99 : F_44 ( V_82 ) ;
F_45 ( V_81 , & V_103 ) ;
V_81 -> V_104 = & V_105 ;
V_81 -> V_61 |= V_106 ;
F_46 ( V_81 -> V_107 , V_60 -> V_108 , sizeof( V_81 -> V_107 ) ) ;
V_23 = F_47 ( & V_81 -> V_109 , 0 , NULL ) ;
if ( V_23 < 0 )
return F_43 ( V_23 ) ;
V_81 -> V_109 . V_110 = V_111 ;
V_23 = F_22 ( V_11 , V_60 ) ;
if ( V_23 < 0 )
goto V_112;
F_48 ( V_81 -> V_102 ) ;
V_23 = F_49 ( V_81 ) ;
if ( V_23 < 0 )
goto V_113;
return V_11 ;
V_113:
F_50 ( V_81 -> V_102 ) ;
F_30 ( V_81 -> V_89 ) ;
V_112:
F_51 ( & V_81 -> V_109 ) ;
return F_43 ( V_23 ) ;
}
struct V_11 * F_52 (
struct V_97 * V_82 , struct V_98 * V_99 ,
struct V_25 * V_19 ,
const struct V_100 * V_101 ,
struct V_52 * V_60 )
{
return F_42 ( V_82 , V_99 , V_19 , NULL , V_101 , V_60 ) ;
}
struct V_11 * F_53 (
struct V_97 * V_82 , struct V_98 * V_99 ,
struct V_22 * V_21 ,
struct V_52 * V_60 )
{
return F_42 ( V_82 , V_99 , NULL , V_21 , NULL , V_60 ) ;
}
void F_54 ( struct V_11 * V_11 )
{
struct V_90 * V_81 ;
if ( F_55 ( V_11 ) )
return;
V_81 = & V_11 -> V_81 ;
F_56 ( V_81 ) ;
F_50 ( V_81 -> V_102 ) ;
F_30 ( V_81 -> V_89 ) ;
F_51 ( & V_81 -> V_109 ) ;
}
