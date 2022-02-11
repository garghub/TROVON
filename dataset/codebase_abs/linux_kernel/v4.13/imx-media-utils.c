static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
V_2 -> V_5 = ( V_4 -> V_6 == V_7 ) ?
V_8 : V_9 ;
V_2 -> V_10 = F_2 ( V_2 -> V_5 ) ;
V_2 -> V_11 = F_3 ( V_2 -> V_5 ) ;
V_2 -> V_12 =
F_4 ( V_4 -> V_6 == V_7 ,
V_2 -> V_5 ,
V_2 -> V_11 ) ;
}
static const struct V_3 * F_5 ( T_1 V_13 ,
T_1 V_14 ,
enum V_15 V_16 ,
bool V_17 ,
bool V_18 )
{
const struct V_3 * V_19 , * V_4 , * V_20 = NULL ;
T_1 V_21 ;
int V_22 , V_23 ;
switch ( V_16 ) {
case V_24 :
V_21 = V_25 ;
V_19 = V_26 ;
break;
case V_27 :
V_21 = V_28 ;
V_19 = V_29 ;
break;
case V_30 :
V_21 = V_25 + V_28 ;
V_19 = V_26 ;
break;
default:
return NULL ;
}
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ ) {
if ( V_16 == V_30 && V_22 >= V_25 )
V_4 = & V_29 [ V_22 - V_25 ] ;
else
V_4 = & V_19 [ V_22 ] ;
if ( ( ! V_17 && V_4 -> V_31 [ 0 ] == 0 ) ||
( ! V_18 && V_4 -> V_32 ) )
continue;
if ( V_13 && V_4 -> V_13 == V_13 ) {
V_20 = V_4 ;
goto V_33;
}
for ( V_23 = 0 ; V_14 && V_4 -> V_31 [ V_23 ] ; V_23 ++ ) {
if ( V_14 == V_4 -> V_31 [ V_23 ] ) {
V_20 = V_4 ;
goto V_33;
}
}
}
V_33:
return V_20 ;
}
static int F_6 ( T_1 * V_13 , T_1 * V_14 , T_1 V_34 ,
enum V_15 V_16 ,
bool V_17 ,
bool V_18 )
{
const struct V_3 * V_4 ;
T_1 V_35 = V_36 ;
T_1 V_37 = V_38 ;
T_1 V_39 = V_25 ;
T_1 V_40 = V_28 ;
switch ( V_16 ) {
case V_24 :
if ( V_34 >= V_39 ||
( ! V_17 && V_34 >= V_35 ) )
return - V_41 ;
V_4 = & V_26 [ V_34 ] ;
break;
case V_27 :
if ( V_34 >= V_40 ||
( ! V_17 && V_34 >= V_37 ) )
return - V_41 ;
V_4 = & V_29 [ V_34 ] ;
if ( ! V_18 && V_4 -> V_32 )
return - V_41 ;
break;
case V_30 :
if ( ! V_17 ) {
if ( V_34 >= V_35 ) {
V_34 -= V_35 ;
if ( V_34 >= V_37 )
return - V_41 ;
V_4 = & V_29 [ V_34 ] ;
if ( ! V_18 && V_4 -> V_32 )
return - V_41 ;
} else {
V_4 = & V_26 [ V_34 ] ;
}
} else {
if ( V_34 >= V_39 + V_40 )
return - V_41 ;
if ( V_34 >= V_39 ) {
V_4 = & V_29 [ V_34 - V_39 ] ;
if ( ! V_18 && V_4 -> V_32 )
return - V_41 ;
} else {
V_4 = & V_26 [ V_34 ] ;
}
}
break;
default:
return - V_41 ;
}
if ( V_13 )
* V_13 = V_4 -> V_13 ;
if ( V_14 )
* V_14 = V_4 -> V_31 [ 0 ] ;
return 0 ;
}
const struct V_3 *
F_7 ( T_1 V_13 , enum V_15 V_16 , bool V_18 )
{
return F_5 ( V_13 , 0 , V_16 , true , V_18 ) ;
}
int F_8 ( T_1 * V_13 , T_1 V_34 , enum V_15 V_16 )
{
return F_6 ( V_13 , NULL , V_34 , V_16 , true , false ) ;
}
const struct V_3 *
F_9 ( T_1 V_14 , enum V_15 V_16 ,
bool V_18 )
{
return F_5 ( 0 , V_14 , V_16 , false , V_18 ) ;
}
int F_10 ( T_1 * V_14 , T_1 V_34 , enum V_15 V_16 ,
bool V_18 )
{
return F_6 ( NULL , V_14 , V_34 , V_16 , false , V_18 ) ;
}
const struct V_3 *
F_11 ( T_1 V_14 , enum V_15 V_16 )
{
const struct V_3 * V_19 , * V_4 , * V_20 = NULL ;
T_1 V_21 ;
int V_22 , V_23 ;
switch ( V_16 ) {
case V_24 :
V_21 = V_42 ;
V_19 = V_43 ;
break;
case V_27 :
V_21 = V_44 ;
V_19 = V_45 ;
break;
case V_30 :
V_21 = V_42 + V_44 ;
V_19 = V_43 ;
break;
default:
return NULL ;
}
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ ) {
if ( V_16 == V_30 && V_22 >= V_42 )
V_4 = & V_45 [ V_22 - V_42 ] ;
else
V_4 = & V_19 [ V_22 ] ;
for ( V_23 = 0 ; V_14 && V_4 -> V_31 [ V_23 ] ; V_23 ++ ) {
if ( V_14 == V_4 -> V_31 [ V_23 ] ) {
V_20 = V_4 ;
goto V_33;
}
}
}
V_33:
return V_20 ;
}
int F_12 ( T_1 * V_14 , T_1 V_34 , enum V_15 V_16 )
{
switch ( V_16 ) {
case V_24 :
if ( V_34 >= V_42 )
return - V_41 ;
* V_14 = V_43 [ V_34 ] . V_31 [ 0 ] ;
break;
case V_27 :
if ( V_34 >= V_44 )
return - V_41 ;
* V_14 = V_45 [ V_34 ] . V_31 [ 0 ] ;
break;
case V_30 :
if ( V_34 >= V_42 + V_44 )
return - V_41 ;
if ( V_34 >= V_42 ) {
V_34 -= V_42 ;
* V_14 = V_45 [ V_34 ] . V_31 [ 0 ] ;
} else {
* V_14 = V_43 [ V_34 ] . V_31 [ 0 ] ;
}
break;
default:
return - V_41 ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 ,
T_1 V_46 , T_1 V_47 , T_1 V_14 , T_1 V_48 ,
const struct V_3 * * V_49 )
{
const struct V_3 * V_50 ;
V_2 -> V_46 = V_46 ;
V_2 -> V_47 = V_47 ;
V_2 -> V_48 = V_48 ;
if ( V_14 == 0 )
F_10 ( & V_14 , 0 , V_24 , false ) ;
V_50 = F_9 ( V_14 , V_30 , false ) ;
if ( ! V_50 ) {
V_50 = F_11 ( V_14 , V_30 ) ;
if ( ! V_50 )
return - V_41 ;
}
V_2 -> V_14 = V_14 ;
F_1 ( V_2 , V_50 ) ;
if ( V_49 )
* V_49 = V_50 ;
return 0 ;
}
void F_14 ( struct V_1 * V_51 ,
struct V_1 * V_4 ,
bool V_52 )
{
const struct V_3 * V_49 ;
bool V_53 = false ;
V_49 = F_9 ( V_51 -> V_14 , V_30 , true ) ;
if ( ! V_49 )
V_49 = F_11 ( V_51 -> V_14 , V_30 ) ;
if ( V_49 && V_49 -> V_6 != V_54 )
V_53 = true ;
if ( V_51 -> V_48 == V_55 )
V_51 -> V_48 = V_4 -> V_48 ;
if ( V_51 -> V_5 == V_56 ) {
V_51 -> V_5 = V_4 -> V_5 ;
V_51 -> V_10 = V_4 -> V_10 ;
V_51 -> V_11 = V_4 -> V_11 ;
V_51 -> V_12 = V_4 -> V_12 ;
} else {
if ( V_51 -> V_10 == V_57 ) {
V_51 -> V_10 =
F_2 ( V_51 -> V_5 ) ;
}
if ( V_51 -> V_11 == V_58 ) {
V_51 -> V_11 =
F_3 ( V_51 -> V_5 ) ;
}
if ( V_51 -> V_12 == V_59 ) {
V_51 -> V_12 =
F_4 (
V_53 , V_51 -> V_5 ,
V_51 -> V_11 ) ;
}
}
if ( V_52 ) {
V_51 -> V_12 = V_53 ?
V_60 :
V_61 ;
V_51 -> V_11 = V_62 ;
}
}
int F_15 ( struct V_63 * V_64 ,
struct V_1 * V_2 ,
const struct V_3 * V_49 )
{
T_1 V_65 ;
if ( ! V_49 ) {
V_49 = F_11 ( V_2 -> V_14 , V_30 ) ;
if ( ! V_49 )
V_49 = F_9 ( V_2 -> V_14 , V_30 ,
true ) ;
if ( ! V_49 )
return - V_41 ;
}
if ( V_49 -> V_66 && V_49 -> V_6 == V_54 ) {
T_1 V_14 ;
F_10 ( & V_14 , 0 , V_24 , false ) ;
V_49 = F_9 ( V_14 , V_24 , false ) ;
}
V_65 = V_49 -> V_67 ? V_2 -> V_46 : ( V_2 -> V_46 * V_49 -> V_68 ) >> 3 ;
V_64 -> V_46 = V_2 -> V_46 ;
V_64 -> V_47 = V_2 -> V_47 ;
V_64 -> V_69 = V_49 -> V_13 ;
V_64 -> V_5 = V_2 -> V_5 ;
V_64 -> V_10 = V_2 -> V_10 ;
V_64 -> V_11 = V_2 -> V_11 ;
V_64 -> V_12 = V_2 -> V_12 ;
V_64 -> V_48 = V_2 -> V_48 ;
V_64 -> V_70 = V_65 ;
V_64 -> V_71 = ( V_64 -> V_46 * V_64 -> V_47 * V_49 -> V_68 ) >> 3 ;
return 0 ;
}
int F_16 ( struct V_72 * V_73 ,
struct V_1 * V_2 )
{
int V_20 ;
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
V_20 = F_15 ( & V_73 -> V_64 , V_2 , NULL ) ;
if ( V_20 )
return V_20 ;
V_73 -> V_74 . V_46 = V_2 -> V_46 ;
V_73 -> V_74 . V_47 = V_2 -> V_47 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_72 * V_73 )
{
const struct V_3 * V_4 ;
V_4 = F_7 ( V_73 -> V_64 . V_69 , V_30 , true ) ;
if ( ! V_4 )
return - V_41 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_46 = V_73 -> V_64 . V_46 ;
V_2 -> V_47 = V_73 -> V_64 . V_47 ;
V_2 -> V_14 = V_4 -> V_31 [ 0 ] ;
V_2 -> V_48 = V_73 -> V_64 . V_48 ;
V_2 -> V_5 = V_73 -> V_64 . V_5 ;
V_2 -> V_10 = V_73 -> V_64 . V_10 ;
V_2 -> V_11 = V_73 -> V_64 . V_11 ;
V_2 -> V_12 = V_73 -> V_64 . V_12 ;
return 0 ;
}
void F_18 ( struct V_75 * V_76 ,
struct V_77 * V_78 )
{
if ( V_78 -> V_79 )
F_19 ( V_76 -> V_80 . V_81 , V_78 -> V_82 ,
V_78 -> V_79 , V_78 -> V_83 ) ;
V_78 -> V_79 = NULL ;
V_78 -> V_83 = 0 ;
}
int F_20 ( struct V_75 * V_76 ,
struct V_77 * V_78 ,
int V_84 )
{
F_18 ( V_76 , V_78 ) ;
V_78 -> V_82 = F_21 ( V_84 ) ;
V_78 -> V_79 = F_22 ( V_76 -> V_80 . V_81 , V_78 -> V_82 , & V_78 -> V_83 ,
V_85 | V_86 ) ;
if ( ! V_78 -> V_79 ) {
F_23 ( V_76 -> V_80 . V_81 , L_1 ) ;
return - V_87 ;
}
return 0 ;
}
void F_24 ( char * V_88 , int V_89 , T_1 V_90 , int V_91 )
{
int V_92 ;
switch ( V_90 ) {
case V_93 ... V_94 :
V_92 = ( V_90 >> V_95 ) - 1 ;
snprintf ( V_88 , V_89 , L_2 , V_91 + 1 , V_92 ) ;
break;
case V_96 :
snprintf ( V_88 , V_89 , L_3 , V_91 + 1 ) ;
break;
case V_97 :
snprintf ( V_88 , V_89 , L_4 , V_91 + 1 ) ;
break;
case V_98 :
snprintf ( V_88 , V_89 , L_5 , V_91 + 1 ) ;
break;
case V_99 :
snprintf ( V_88 , V_89 , L_6 , V_91 + 1 ) ;
break;
default:
break;
}
}
struct V_100 *
F_25 ( struct V_75 * V_76 ,
struct V_101 * V_102 )
{
struct V_100 * V_103 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_76 -> V_104 ; V_22 ++ ) {
V_103 = & V_76 -> V_105 [ V_22 ] ;
if ( V_102 == V_103 -> V_102 )
return V_103 ;
}
return F_26 ( - V_106 ) ;
}
struct V_100 *
F_27 ( struct V_75 * V_76 , T_1 V_90 )
{
struct V_100 * V_103 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_76 -> V_104 ; V_22 ++ ) {
V_103 = & V_76 -> V_105 [ V_22 ] ;
if ( V_103 -> V_102 && V_103 -> V_102 -> V_90 == V_90 )
return V_103 ;
}
return F_26 ( - V_106 ) ;
}
int F_28 ( struct V_75 * V_76 ,
struct V_107 * V_108 )
{
int V_109 , V_20 = 0 ;
F_29 ( & V_76 -> V_110 ) ;
V_109 = V_76 -> V_111 ;
if ( V_109 >= V_112 ) {
F_23 ( V_76 -> V_80 . V_81 ,
L_7 ,
V_113 , V_108 -> V_114 -> V_115 ) ;
V_20 = - V_116 ;
goto V_33;
}
V_76 -> V_108 [ V_109 ] = V_108 ;
V_76 -> V_111 ++ ;
V_33:
F_30 ( & V_76 -> V_110 ) ;
return V_20 ;
}
static struct V_117 *
F_31 ( struct V_75 * V_76 ,
struct V_118 * V_119 ,
T_1 V_90 , bool V_120 )
{
struct V_118 * V_121 = V_119 ;
struct V_117 * V_122 = NULL ;
struct V_101 * V_102 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_121 -> V_123 ; V_22 ++ ) {
struct V_117 * V_124 = & V_121 -> V_125 [ V_22 ] ;
if ( ( V_120 && ! ( V_124 -> V_126 & V_127 ) ) ||
( ! V_120 && ! ( V_124 -> V_126 & V_128 ) ) )
continue;
V_122 = F_32 ( V_124 ) ;
if ( ! V_122 || ! F_33 ( V_122 -> V_129 ) )
continue;
V_102 = F_34 ( V_122 -> V_129 ) ;
if ( V_102 -> V_90 & V_90 )
return V_122 ;
return F_31 ( V_76 , V_122 -> V_129 , V_90 , V_120 ) ;
}
return NULL ;
}
static struct V_101 *
F_35 ( struct V_75 * V_76 ,
struct V_118 * V_119 ,
T_1 V_90 )
{
struct V_101 * V_102 ;
struct V_117 * V_122 ;
if ( F_33 ( V_119 ) ) {
V_102 = F_34 ( V_119 ) ;
if ( V_102 -> V_90 & V_90 )
return V_102 ;
}
V_122 = F_31 ( V_76 , V_119 , V_90 , true ) ;
return V_122 ? F_34 ( V_122 -> V_129 ) : NULL ;
}
int F_36 ( struct V_75 * V_76 ,
struct V_118 * V_119 )
{
struct V_117 * V_122 ;
int V_20 = - V_130 ;
V_122 = F_31 ( V_76 , V_119 , V_131 ,
true ) ;
if ( V_122 ) {
V_20 = V_122 -> V_34 - 1 ;
F_37 ( V_76 -> V_80 . V_81 , L_8 ,
V_20 , V_119 -> V_115 ) ;
}
return V_20 ;
}
struct V_100 *
F_38 ( struct V_75 * V_76 ,
struct V_118 * V_119 ,
T_1 V_90 )
{
struct V_101 * V_102 ;
V_102 = F_35 ( V_76 , V_119 , V_90 ) ;
if ( ! V_102 )
return F_26 ( - V_106 ) ;
return F_25 ( V_76 , V_102 ) ;
}
struct V_100 *
F_39 ( struct V_75 * V_76 ,
struct V_118 * V_119 )
{
return F_38 ( V_76 , V_119 ,
V_132 ) ;
}
struct V_100 *
F_40 ( struct V_75 * V_76 ,
struct V_118 * V_119 )
{
struct V_100 * V_133 ;
F_29 ( & V_76 -> V_80 . V_134 ) ;
V_133 = F_39 ( V_76 , V_119 ) ;
F_30 ( & V_76 -> V_80 . V_134 ) ;
return V_133 ;
}
int F_41 ( struct V_75 * V_76 ,
struct V_118 * V_129 ,
bool V_135 )
{
struct V_101 * V_102 ;
int V_20 = 0 ;
if ( ! F_33 ( V_129 ) )
return - V_41 ;
V_102 = F_34 ( V_129 ) ;
F_29 ( & V_76 -> V_80 . V_134 ) ;
if ( V_135 ) {
V_20 = F_42 ( V_129 , & V_76 -> V_136 ) ;
if ( V_20 )
goto V_33;
V_20 = F_43 ( V_102 , V_137 , V_138 , 1 ) ;
if ( V_20 )
F_44 ( V_129 ) ;
} else {
F_43 ( V_102 , V_137 , V_138 , 0 ) ;
if ( V_129 -> V_136 )
F_44 ( V_129 ) ;
}
V_33:
F_30 ( & V_76 -> V_80 . V_134 ) ;
return V_20 ;
}
