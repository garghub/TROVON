static bool F_1 ( T_1 V_1 )
{
return ! ! ( F_2 ( V_1 , V_2 ) ==
V_3 ) ;
}
static bool F_3 ( T_1 V_1 )
{
return ! ! ( F_2 ( V_1 , V_2 ) ==
V_4 ) ;
}
static bool F_4 ( T_1 V_1 , T_2 V_5 )
{
return ! ! ( F_1 ( V_1 ) &&
V_5 == V_6 ) ;
}
static bool F_5 ( T_1 V_1 , T_2 V_5 )
{
return ! ! ( F_3 ( V_1 ) &&
V_5 == V_7 ) ;
}
static bool F_6 ( T_1 V_1 , T_2 V_5 )
{
return ! ! ( F_1 ( V_1 ) &&
V_5 == V_8 ) ;
}
static bool F_7 ( T_1 V_1 , T_2 V_5 )
{
return ! ! ( F_1 ( V_1 ) &&
V_5 == V_9 ) ;
}
static bool F_8 ( T_1 V_1 , T_2 V_5 )
{
return ! ! ( F_3 ( V_1 ) &&
V_5 == V_10 ) ;
}
static void
F_9 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
enum V_15 V_16 ;
int V_17 ;
F_10 ( V_12 , V_18 , L_1 ,
V_14 -> V_19 ) ;
for ( V_17 = 0 ; V_17 < F_11 ( V_20 ) ; V_17 ++ ) {
V_16 = V_20 [ V_17 ] . V_16 ;
F_10 ( V_12 , V_18 ,
L_2 ,
V_20 [ V_17 ] . V_21 , V_14 -> V_22 [ V_16 ] . V_23 ,
V_14 -> V_22 [ V_16 ] . V_24 , V_14 -> V_22 [ V_16 ] . V_25 ,
V_14 -> V_22 [ V_16 ] . V_26 , V_12 -> V_27 . V_28 ) ;
}
}
static void
F_12 ( struct V_13 * V_14 ,
struct V_29 * V_30 ,
bool V_24 ,
bool V_23 ,
T_3 V_31 ,
T_3 V_26 ,
enum V_15 type ,
enum V_32 V_33 )
{
V_14 -> V_22 [ type ] . V_23 = V_23 ;
V_14 -> V_22 [ type ] . V_24 = V_24 ;
V_14 -> V_22 [ type ] . V_25 = V_31 ;
V_14 -> V_22 [ type ] . V_26 = V_26 ;
if ( V_30 -> V_33 == V_33 ) {
if ( V_33 == V_34 )
V_30 -> V_35 = V_26 ;
else
V_30 -> V_36 = V_26 ;
}
}
static void
F_13 ( struct V_13 * V_14 ,
struct V_11 * V_12 ,
bool V_24 ,
bool V_23 ,
T_3 V_31 , T_3 V_26 , enum V_15 type )
{
struct V_29 * V_30 = & V_12 -> V_27 ;
enum V_32 V_33 ;
enum V_15 V_16 ;
char * V_21 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < F_11 ( V_20 ) ; V_17 ++ ) {
V_16 = V_20 [ V_17 ] . V_16 ;
if ( type != V_16 )
continue;
V_33 = V_20 [ V_17 ] . V_33 ;
V_21 = V_20 [ V_17 ] . V_21 ;
F_12 ( V_14 , V_30 , V_24 , V_23 ,
V_31 , V_26 , type , V_33 ) ;
}
}
static bool
F_14 ( struct V_11 * V_12 ,
T_1 V_37 ,
T_2 V_16 , enum V_15 * type )
{
if ( F_6 ( V_37 , V_16 ) ) {
* type = V_38 ;
} else if ( F_7 ( V_37 , V_16 ) ) {
* type = V_39 ;
} else if ( F_5 ( V_37 , V_16 ) ) {
* type = V_40 ;
} else if ( F_4 ( V_37 , V_16 ) ) {
* type = V_41 ;
} else if ( F_8 ( V_37 , V_16 ) ) {
* type = V_42 ;
} else {
* type = V_43 ;
F_15 ( V_12 ,
L_3 ,
V_16 , V_37 ) ;
return false ;
}
return true ;
}
static int
F_16 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_44 * V_45 ,
T_1 V_46 , int V_47 , bool V_19 )
{
T_3 V_26 , V_48 ;
enum V_15 type ;
T_2 V_49 ;
int V_25 ;
bool V_24 ;
int V_17 ;
F_10 ( V_12 , V_18 , L_4 , V_47 ) ;
for ( V_17 = 0 ; V_17 < V_47 ; V_17 ++ ) {
V_49 = F_2 ( V_45 [ V_17 ] . V_50 ,
V_51 ) ;
V_48 = F_2 ( V_45 [ V_17 ] . V_50 ,
V_52 ) ;
V_25 = F_17 ( V_48 ) - 1 ;
if ( V_25 < 0 ) {
F_15 ( V_12 , L_5 ) ;
return - V_53 ;
}
V_26 = F_18 ( V_46 , V_25 ) ;
if ( F_14 ( V_12 , V_45 [ V_17 ] . V_50 ,
V_49 , & type ) ) {
V_24 = ! ( type == V_41 ) ;
F_13 ( V_14 , V_12 , V_24 , true ,
V_25 , V_26 , type ) ;
}
}
if ( ! V_14 -> V_22 [ V_42 ] . V_23 &&
V_14 -> V_22 [ V_39 ] . V_23 ) {
V_26 = V_14 -> V_22 [ V_39 ] . V_26 ;
V_25 = V_14 -> V_22 [ V_39 ] . V_25 ;
F_13 ( V_14 , V_12 , true , true ,
V_25 , V_26 , V_42 ) ;
}
V_26 = V_14 -> V_22 [ V_41 ] . V_26 ;
V_25 = V_14 -> V_22 [ V_41 ] . V_25 ;
for ( type = 0 ; type < V_43 ; type ++ ) {
if ( V_14 -> V_22 [ type ] . V_23 )
continue;
V_24 = ( type == V_41 ) ? false : V_19 ;
F_13 ( V_14 , V_12 , V_24 , true ,
V_25 , V_26 , type ) ;
}
return 0 ;
}
static int F_19 ( struct V_11 * V_12 )
{
struct V_54 * V_55 ;
struct V_44 * V_45 ;
struct V_13 V_56 = { 0 } ;
struct V_57 * V_58 ;
struct V_29 * V_30 ;
T_1 V_46 , V_59 ;
bool V_19 ;
int V_60 ;
int V_61 = 0 ;
V_59 = V_12 -> V_62 -> V_63 . V_59 ;
V_19 = ! ! F_2 ( V_59 , V_64 ) ;
V_55 = & V_12 -> V_62 -> V_63 . V_65 . V_66 ;
V_45 = V_55 -> V_67 ;
V_58 = & V_12 -> V_62 -> V_63 . V_65 . V_68 ;
V_46 = V_58 -> V_46 [ 0 ] ;
V_30 = & V_12 -> V_27 ;
V_60 = F_2 ( V_55 -> V_59 , V_69 ) ;
V_61 = F_16 ( V_12 , & V_56 , V_45 , V_46 ,
V_60 , V_19 ) ;
if ( V_61 )
return V_61 ;
V_30 -> V_28 = F_2 ( V_58 -> V_59 , V_70 ) ;
V_56 . V_71 = V_12 -> V_72 ;
V_56 . V_19 = V_19 ;
F_9 ( V_12 , & V_56 ) ;
memcpy ( & V_12 -> V_62 -> V_73 , & V_56 ,
sizeof( struct V_13 ) ) ;
return 0 ;
}
static int
F_20 ( struct V_11 * V_12 ,
struct V_74 * V_75 ,
struct V_76 * V_14 ,
enum V_77 type )
{
T_1 V_78 , V_79 ;
int V_80 = 0 ;
int V_61 = 0 ;
do {
if ( type == V_81 ) {
F_21 ( V_12 , V_75 , V_14 -> V_82 ,
V_14 -> V_83 , V_14 -> V_84 ) ;
V_78 = V_14 -> V_82 -> V_78 ;
V_79 = V_14 -> V_82 -> V_79 ;
} else {
F_21 ( V_12 , V_75 , V_14 -> V_85 ,
V_14 -> V_83 , V_14 -> V_84 ) ;
V_78 = V_14 -> V_85 -> V_78 ;
V_79 = V_14 -> V_85 -> V_79 ;
}
V_80 ++ ;
F_10 ( V_12 ,
V_18 ,
L_6 ,
type , V_80 , V_78 , V_79 ) ;
} while ( ( V_78 != V_79 ) &&
( V_80 < V_86 ) );
if ( V_80 >= V_86 ) {
F_15 ( V_12 ,
L_7 ,
type , V_80 , V_78 , V_79 ) ;
V_61 = - V_87 ;
}
return V_61 ;
}
static int
F_22 ( struct V_11 * V_12 , struct V_74 * V_75 )
{
struct V_76 V_56 ;
int V_61 = 0 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_83 = V_12 -> V_88 -> V_89 + F_23 ( struct V_90 ,
V_91 ) ;
V_56 . V_92 = V_12 -> V_62 -> V_92 ;
V_56 . V_84 = sizeof( struct V_93 ) ;
F_21 ( V_12 , V_75 , V_56 . V_92 , V_56 . V_83 , V_56 . V_84 ) ;
return V_61 ;
}
static int
F_24 ( struct V_11 * V_12 ,
struct V_74 * V_75 ,
enum V_77 type )
{
struct V_76 V_56 ;
int V_61 = 0 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_83 = V_12 -> V_88 -> V_89 + F_23 ( struct V_90 ,
V_94 ) ;
V_56 . V_82 = V_12 -> V_62 -> V_82 ;
V_56 . V_84 = sizeof( struct V_95 ) ;
V_61 = F_20 ( V_12 , V_75 , & V_56 , type ) ;
return V_61 ;
}
static int
F_25 ( struct V_11 * V_12 ,
struct V_74 * V_75 ,
enum V_77 type )
{
struct V_76 V_56 ;
int V_61 = 0 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_83 = V_12 -> V_88 -> V_89 +
F_23 ( struct V_90 , V_96 ) ;
V_56 . V_85 = & V_12 -> V_62 -> V_63 ;
V_56 . V_84 = sizeof( struct V_97 ) ;
V_61 = F_20 ( V_12 , V_75 , & V_56 , type ) ;
return V_61 ;
}
static int
F_26 ( struct V_11 * V_12 ,
struct V_74 * V_75 , enum V_77 type )
{
struct V_76 V_56 ;
int V_61 = 0 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_83 = V_12 -> V_88 -> V_89 +
F_23 ( struct V_90 , V_98 ) ;
V_56 . V_85 = & V_12 -> V_62 -> V_99 ;
V_56 . V_84 = sizeof( struct V_97 ) ;
V_61 = F_20 ( V_12 , V_75 , & V_56 , type ) ;
return V_61 ;
}
static int
F_27 ( struct V_11 * V_12 , struct V_74 * V_75 )
{
struct V_76 V_56 ;
int V_61 = 0 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_83 = V_12 -> V_88 -> V_89 +
F_23 ( struct V_90 , V_100 ) ;
V_56 . V_101 = & V_12 -> V_62 -> V_101 ;
V_56 . V_84 = sizeof( struct V_102 ) ;
F_21 ( V_12 , V_75 , V_56 . V_101 , V_56 . V_83 , V_56 . V_84 ) ;
return V_61 ;
}
static int F_28 ( struct V_11 * V_12 ,
struct V_74 * V_75 , enum V_77 type )
{
int V_61 = - V_53 ;
switch ( type ) {
case V_103 :
V_61 = F_25 ( V_12 , V_75 , type ) ;
break;
case V_104 :
V_61 = F_26 ( V_12 , V_75 , type ) ;
break;
case V_105 :
V_61 = F_27 ( V_12 , V_75 ) ;
break;
case V_81 :
V_61 = F_24 ( V_12 , V_75 , type ) ;
break;
case V_106 :
V_61 = F_22 ( V_12 , V_75 ) ;
break;
default:
F_15 ( V_12 , L_8 , type ) ;
}
return V_61 ;
}
int
F_29 ( struct V_11 * V_12 ,
struct V_74 * V_75 , enum V_77 type )
{
int V_61 = 0 ;
V_61 = F_28 ( V_12 , V_75 , type ) ;
if ( V_61 )
return V_61 ;
if ( type == V_103 ) {
V_61 = F_19 ( V_12 ) ;
if ( ! V_61 ) {
F_30 ( V_12 , V_75 ) ;
F_31 ( V_12 ) ;
}
}
return V_61 ;
}
int F_32 ( struct V_11 * V_12 )
{
int V_61 = 0 ;
V_12 -> V_62 = F_33 ( sizeof( * V_12 -> V_62 ) , V_107 ) ;
if ( ! V_12 -> V_62 ) {
F_34 ( V_12 ,
L_9 ) ;
V_61 = - V_108 ;
}
return V_61 ;
}
void F_35 ( struct V_11 * V_12 ,
struct V_109 * V_62 )
{
F_36 ( V_12 -> V_62 ) ;
}
static void F_37 ( struct V_110 * V_14 ,
struct V_13 * V_111 ,
enum V_15 type )
{
V_14 -> V_112 = V_111 -> V_22 [ type ] . V_24 ;
V_14 -> V_113 = V_111 -> V_22 [ type ] . V_25 ;
V_14 -> V_114 = V_111 -> V_22 [ type ] . V_26 ;
}
void F_38 ( struct V_13 * V_111 ,
struct V_115 * V_116 )
{
struct V_110 * V_117 ;
bool V_118 = false ;
V_116 -> V_71 = V_111 -> V_71 ;
V_118 = V_111 -> V_22 [ V_38 ] . V_23 ;
V_116 -> V_119 = V_118 ;
V_118 = V_111 -> V_22 [ V_39 ] . V_23 ;
V_116 -> V_120 = V_118 ;
V_118 = V_111 -> V_22 [ V_42 ] . V_23 ;
V_116 -> V_120 = V_118 ;
V_118 = V_111 -> V_22 [ V_40 ] . V_23 ;
V_116 -> V_121 = V_118 ;
V_118 = V_111 -> V_22 [ V_41 ] . V_23 ;
V_116 -> V_122 = V_118 ;
V_117 = & V_116 -> V_123 ;
F_37 ( V_117 , V_111 , V_38 ) ;
V_117 = & V_116 -> V_124 ;
if ( V_111 -> V_22 [ V_39 ] . V_23 )
F_37 ( V_117 , V_111 ,
V_39 ) ;
if ( V_111 -> V_22 [ V_42 ] . V_23 )
F_37 ( V_117 , V_111 ,
V_42 ) ;
V_117 = & V_116 -> V_125 ;
F_37 ( V_117 , V_111 , V_40 ) ;
V_117 = & V_116 -> V_126 ;
F_37 ( V_117 , V_111 , V_41 ) ;
}
