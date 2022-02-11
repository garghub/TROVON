static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
F_2 ( V_6 , L_1 ,
V_4 -> V_7 , V_5 ) ;
V_4 -> V_5 += V_5 ;
V_4 -> V_8 += V_5 ;
V_2 -> V_9 -= V_5 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
int V_12 )
{
struct V_3 * V_13 ;
int V_14 ;
F_2 ( V_6 , L_2 , V_12 ) ;
V_2 -> V_9 = V_12 ;
V_2 -> V_15 = V_12 ;
F_4 (cur_ep_dist, ep_list, list) {
if ( V_13 -> V_7 == V_16 )
continue;
V_13 -> V_17 = V_13 -> V_18 ;
if ( V_12 > 4 ) {
if ( ( V_13 -> V_19 == V_20 ) ||
( V_13 -> V_19 == V_21 ) ) {
F_1 ( V_2 ,
V_13 ,
V_13 -> V_17 ) ;
V_13 -> V_22 |= V_23 ;
}
}
if ( V_13 -> V_19 == V_24 ) {
F_1 ( V_2 , V_13 ,
V_13 -> V_17 ) ;
V_13 -> V_22 |= V_23 ;
}
}
V_2 -> V_25 = V_13 -> V_26 ;
F_5 ( V_2 -> V_9 <= 0 ) ;
F_4 (cur_ep_dist, ep_list, list) {
if ( V_13 -> V_7 == V_16 )
continue;
if ( V_13 -> V_19 == V_24 )
V_13 -> V_27 = V_13 -> V_18 ;
else {
V_14 = ( V_2 -> V_9 /
V_13 -> V_18 )
* V_13 -> V_18 ;
V_14 = ( V_14 * 3 ) >> 2 ;
V_14 = F_6 ( V_14 , V_13 -> V_18 ) ;
V_13 -> V_27 = V_14 ;
}
F_2 ( V_6 ,
L_3 ,
V_13 -> V_7 ,
V_13 -> V_19 ,
V_13 -> V_5 ,
V_13 -> V_18 ,
V_13 -> V_27 ,
V_13 -> V_17 ) ;
}
}
static int F_7 ( struct V_28 * V_28 ,
struct V_1 * V_2 )
{
T_1 V_29 [ 5 ] ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_29 [ 0 ] = V_24 ;
V_29 [ 1 ] = V_30 ;
V_29 [ 2 ] = V_31 ;
V_29 [ 3 ] = V_21 ;
V_29 [ 4 ] = V_20 ;
F_8 ( V_28 , V_2 , V_29 , 5 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_32 )
{
int V_5 ;
F_2 ( V_6 , L_4 ,
V_4 -> V_7 , V_32 ) ;
V_4 -> V_8 = V_32 ;
if ( V_4 -> V_5 <= V_32 )
return;
V_5 = V_4 -> V_5 - V_32 ;
V_4 -> V_5 -= V_5 ;
V_2 -> V_9 += V_5 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_10 * V_33 )
{
struct V_3 * V_34 ;
F_4 (cur_list, epdist_list, list) {
if ( V_34 -> V_7 == V_16 )
continue;
if ( V_34 -> V_35 > 0 ) {
V_34 -> V_5 += V_34 -> V_35 ;
V_34 -> V_35 = 0 ;
if ( V_34 -> V_5 > V_34 -> V_8 )
F_9 ( V_2 ,
V_34 ,
V_34 -> V_8 ) ;
if ( V_34 -> V_5 > V_34 -> V_27 )
F_9 ( V_2 , V_34 ,
V_34 -> V_27 ) ;
if ( ! ( V_34 -> V_22 & V_23 ) ) {
if ( V_34 -> V_36 == 0 )
F_9 ( V_2 ,
V_34 , 0 ) ;
}
}
}
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_37 ;
int V_5 = 0 ;
int V_38 ;
if ( V_4 -> V_19 == V_24 )
goto V_39;
if ( ( V_4 -> V_19 == V_31 ) ||
( V_4 -> V_19 == V_30 ) )
if ( ( V_4 -> V_8 >= V_4 -> V_27 ) )
goto V_39;
V_5 = F_12 ( V_2 -> V_9 , V_4 -> V_40 ) ;
if ( V_5 >= V_4 -> V_40 )
goto V_39;
F_13 (curdist_list,
&cred_info->lowestpri_ep_dist,
list) {
if ( V_37 == V_4 )
break;
V_38 = V_4 -> V_40 - V_2 -> V_9 ;
if ( ( V_37 -> V_8 - V_38 ) >=
V_37 -> V_17 ) {
F_9 ( V_2 , V_37 ,
V_37 -> V_8 - V_38 ) ;
if ( V_2 -> V_9 >=
V_4 -> V_40 )
break;
}
if ( V_37 -> V_7 == V_16 )
break;
}
V_5 = F_12 ( V_2 -> V_9 , V_4 -> V_40 ) ;
V_39:
if ( V_5 )
F_1 ( V_2 , V_4 , V_5 ) ;
V_4 -> V_40 = 0 ;
}
static void F_14 ( struct V_1 * V_41 ,
struct V_10 * V_42 )
{
struct V_3 * V_37 ;
F_4 (curdist_list, ep_dist_list, list) {
if ( V_37 -> V_7 == V_16 )
continue;
if ( ( V_37 -> V_19 == V_20 ) ||
( V_37 -> V_19 == V_21 ) )
V_37 -> V_22 |= V_23 ;
if ( ( V_37 -> V_19 != V_24 ) &&
! ( V_37 -> V_22 & V_23 ) ) {
if ( V_37 -> V_36 == 0 )
F_9 ( V_41 , V_37 , 0 ) ;
else
F_9 ( V_41 ,
V_37 ,
V_37 -> V_17 ) ;
}
}
}
static void F_15 ( struct V_1 * V_2 ,
struct V_10 * V_42 ,
enum V_43 V_44 )
{
switch ( V_44 ) {
case V_45 :
F_10 ( V_2 , V_42 ) ;
break;
case V_46 :
F_14 ( V_2 , V_42 ) ;
break;
default:
break;
}
F_5 ( V_2 -> V_9 > V_2 -> V_15 ) ;
F_5 ( V_2 -> V_9 < 0 ) ;
}
static void F_16 ( T_2 * * V_47 , unsigned long V_48 )
{
T_2 * V_49 ;
if ( ! F_17 ( ( unsigned long ) * V_47 , 4 ) ) {
V_49 = F_18 ( * V_47 - 4 , 4 ) ;
memmove ( V_49 , * V_47 , V_48 ) ;
* V_47 = V_49 ;
}
}
static void F_19 ( struct V_50 * V_51 , T_2 V_52 ,
int V_53 , int V_54 )
{
struct V_55 * V_56 ;
V_51 -> V_47 -= V_57 ;
V_56 = (struct V_55 * ) V_51 -> V_47 ;
F_20 ( ( T_1 ) V_51 -> V_58 , & V_56 -> V_59 ) ;
V_56 -> V_52 = V_52 ;
V_56 -> V_60 = V_51 -> V_7 ;
V_56 -> V_61 [ 0 ] = V_53 ;
V_56 -> V_61 [ 1 ] = V_54 ;
}
static void F_21 ( struct V_28 * V_62 ,
struct V_50 * V_63 )
{
F_22 ( & V_62 -> V_64 ) ;
F_23 ( & V_63 -> V_26 , & V_62 -> V_65 ) ;
F_24 ( & V_62 -> V_64 ) ;
}
static struct V_50 * F_25 ( struct V_28 * V_62 ,
bool V_66 )
{
struct V_50 * V_51 = NULL ;
struct V_10 * V_67 ;
V_67 = V_66 ? & V_62 -> V_65 : & V_62 -> V_68 ;
F_22 ( & V_62 -> V_64 ) ;
if ( F_26 ( V_67 ) ) {
F_24 ( & V_62 -> V_64 ) ;
return NULL ;
}
V_51 = F_27 ( V_67 , struct V_50 , V_26 ) ;
F_28 ( & V_51 -> V_26 ) ;
F_24 ( & V_62 -> V_64 ) ;
if ( V_66 )
V_51 -> V_47 = V_51 -> V_69 + V_57 ;
return V_51 ;
}
static void F_29 ( struct V_28 * V_62 ,
struct V_70 * V_7 ,
struct V_50 * V_51 )
{
V_51 -> V_71 = NULL ;
V_51 -> V_47 += V_57 ;
if ( ! V_51 -> V_72 )
return;
F_30 ( L_5 ,
V_51 -> V_72 , V_51 -> V_7 , V_51 -> V_58 ,
V_51 -> V_41 . V_66 . V_73 ) ;
F_22 ( & V_62 -> V_74 ) ;
V_7 -> V_75 . V_35 +=
V_51 -> V_41 . V_66 . V_73 ;
V_7 -> V_75 . V_36 = F_31 ( & V_7 -> V_76 ) ;
F_2 ( V_77 , L_6 ,
V_62 -> V_78 , & V_62 -> V_79 ) ;
F_15 ( V_62 -> V_78 ,
& V_62 -> V_79 ,
V_45 ) ;
F_24 ( & V_62 -> V_74 ) ;
}
static void F_32 ( struct V_70 * V_7 ,
struct V_10 * V_76 )
{
if ( F_26 ( V_76 ) )
return;
F_2 ( V_77 ,
L_7 ,
V_7 -> V_60 , F_31 ( V_76 ) ) ;
F_33 ( V_7 -> V_62 , V_76 ) ;
}
static void F_34 ( struct V_28 * V_62 ,
struct V_50 * V_51 )
{
struct V_70 * V_7 = & V_62 -> V_7 [ V_51 -> V_7 ] ;
struct V_10 V_80 ;
F_2 ( V_77 , L_8 ,
V_51 -> V_41 . V_66 . V_81 ) ;
F_29 ( V_62 , V_7 , V_51 ) ;
F_35 ( & V_80 ) ;
F_23 ( & V_51 -> V_26 , & V_80 ) ;
F_32 ( V_7 , & V_80 ) ;
}
static void F_36 ( struct V_28 * V_62 ,
struct V_82 * V_83 )
{
struct V_70 * V_7 ;
struct V_50 * V_51 ;
struct V_10 V_84 ;
int V_85 ;
F_35 ( & V_84 ) ;
F_2 ( V_77 ,
L_9 ,
V_83 -> V_48 , V_83 -> V_86 ) ;
if ( V_83 -> V_72 )
F_30 ( L_10 , V_83 -> V_72 ) ;
V_51 = V_83 -> V_87 [ 0 ] . V_51 ;
V_7 = & V_62 -> V_7 [ V_51 -> V_7 ] ;
for ( V_85 = 0 ; V_85 < V_83 -> V_86 ; V_85 ++ ) {
V_51 = V_83 -> V_87 [ V_85 ] . V_51 ;
if ( ! V_51 ) {
F_5 ( 1 ) ;
return;
}
V_51 -> V_72 = V_83 -> V_72 ;
F_29 ( V_62 , V_7 , V_51 ) ;
F_23 ( & V_51 -> V_26 , & V_84 ) ;
}
F_37 ( V_62 -> V_88 -> V_89 , V_83 ) ;
F_32 ( V_7 , & V_84 ) ;
}
static int F_38 ( struct V_28 * V_62 ,
struct V_50 * V_51 )
{
int V_72 ;
bool V_90 = false ;
T_3 V_91 , V_92 ;
if ( ! V_51 -> V_71 )
V_90 = true ;
V_92 = V_51 -> V_58 + V_57 ;
V_91 = F_39 ( V_62 , V_92 ) ;
F_2 ( V_77 ,
L_11 ,
V_92 , V_51 -> V_41 . V_66 . V_81 , V_91 ,
V_62 -> V_88 -> V_89 -> V_93 . V_94 ,
V_90 ? L_12 : L_13 ) ;
if ( V_90 ) {
V_72 = F_40 ( V_62 -> V_88 -> V_89 ,
V_62 -> V_88 -> V_89 -> V_93 . V_94 ,
V_51 -> V_47 , V_91 ,
V_95 ) ;
V_51 -> V_72 = V_72 ;
V_51 -> V_47 += V_57 ;
} else
V_72 = F_41 ( V_62 -> V_88 -> V_89 ,
V_62 -> V_88 -> V_89 -> V_93 . V_94 ,
V_51 -> V_47 , V_91 ,
V_96 , V_51 ) ;
F_42 ( V_72 , V_51 -> V_7 , V_51 -> V_47 , V_92 ) ;
return V_72 ;
}
static int F_43 ( struct V_28 * V_62 ,
struct V_70 * V_97 , T_2 * V_52 ,
enum V_98 V_60 , unsigned int V_48 ,
int * V_99 )
{
* V_99 = ( V_48 > V_62 -> V_100 ) ?
F_44 ( V_48 , V_62 -> V_100 ) : 1 ;
F_2 ( V_6 , L_14 ,
* V_99 , V_97 -> V_75 . V_5 ) ;
if ( V_97 -> V_75 . V_5 < * V_99 ) {
if ( V_60 == V_16 )
return - V_101 ;
V_97 -> V_75 . V_40 = * V_99 - V_97 -> V_75 . V_5 ;
F_11 ( V_62 -> V_78 , & V_97 -> V_75 ) ;
V_97 -> V_75 . V_40 = 0 ;
if ( V_97 -> V_75 . V_5 < * V_99 ) {
F_2 ( V_6 ,
L_15 ,
V_60 ) ;
return - V_101 ;
}
}
V_97 -> V_75 . V_5 -= * V_99 ;
V_97 -> V_102 . V_103 += * V_99 ;
if ( V_97 -> V_75 . V_5 < V_97 -> V_75 . V_18 ) {
V_97 -> V_75 . V_40 =
V_97 -> V_75 . V_18 - V_97 -> V_75 . V_5 ;
F_11 ( V_62 -> V_78 , & V_97 -> V_75 ) ;
if ( V_97 -> V_75 . V_5 < V_97 -> V_75 . V_18 ) {
* V_52 |= V_104 ;
V_97 -> V_102 . V_105 += 1 ;
F_2 ( V_6 ,
L_16 ) ;
}
}
return 0 ;
}
static void F_45 ( struct V_28 * V_62 ,
struct V_70 * V_7 ,
struct V_10 * V_106 )
{
int V_99 ;
T_2 V_52 ;
struct V_50 * V_51 ;
unsigned int V_48 ;
while ( true ) {
V_52 = 0 ;
if ( F_26 ( & V_7 -> V_76 ) )
break;
V_51 = F_27 ( & V_7 -> V_76 , struct V_50 ,
V_26 ) ;
F_2 ( V_77 ,
L_17 ,
V_51 , F_31 ( & V_7 -> V_76 ) ) ;
V_48 = F_39 ( V_62 ,
V_51 -> V_58 + V_57 ) ;
if ( F_43 ( V_62 , V_7 , & V_52 ,
V_51 -> V_7 , V_48 , & V_99 ) )
break;
V_51 = F_27 ( & V_7 -> V_76 , struct V_50 ,
V_26 ) ;
F_46 ( & V_51 -> V_26 , V_106 ) ;
V_51 -> V_41 . V_66 . V_73 = V_99 ;
V_51 -> V_71 = F_34 ;
V_51 -> V_107 = V_62 ;
V_7 -> V_102 . V_108 += 1 ;
V_51 -> V_41 . V_66 . V_52 = V_52 ;
V_51 -> V_41 . V_66 . V_81 = V_7 -> V_81 ;
V_7 -> V_81 ++ ;
}
}
static int F_47 ( unsigned int V_109 , int * V_48 ,
struct V_70 * V_97 )
{
int V_110 , V_111 ;
V_110 = * V_48 % V_109 ;
if ( ! V_110 )
return 0 ;
if ( ! ( V_97 -> V_112 & V_113 ) )
return - 1 ;
V_111 = * V_48 < V_109 ? ( V_109 - * V_48 ) : V_110 ;
if ( ( V_111 > 0 ) && ( V_111 <= 255 ) )
* V_48 += V_111 ;
else
return - 1 ;
return V_111 ;
}
static int F_48 ( struct V_28 * V_62 ,
struct V_70 * V_7 ,
struct V_82 * V_83 ,
int V_114 ,
struct V_10 * V_106 )
{
struct V_50 * V_51 ;
int V_85 , V_48 , V_115 , V_111 ;
int V_72 = 0 ;
T_2 V_52 ;
V_115 = V_62 -> V_116 ;
for ( V_85 = 0 ; V_85 < V_114 ; V_85 ++ ) {
V_83 -> V_87 [ V_85 ] . V_51 = NULL ;
if ( F_26 ( V_106 ) )
break;
V_51 = F_27 ( V_106 , struct V_50 , V_26 ) ;
V_48 = F_39 ( V_62 ,
V_51 -> V_58 + V_57 ) ;
V_111 = F_47 ( V_62 -> V_100 ,
& V_48 , V_7 ) ;
if ( V_111 < 0 || V_115 < V_48 ) {
V_72 = - V_117 ;
break;
}
V_115 -= V_48 ;
F_28 ( & V_51 -> V_26 ) ;
V_83 -> V_87 [ V_85 ] . V_51 = V_51 ;
V_52 = V_51 -> V_41 . V_66 . V_52 | V_118 ;
F_19 ( V_51 , V_52 ,
V_111 , V_51 -> V_41 . V_66 . V_81 ) ;
F_16 ( & V_51 -> V_47 ,
V_51 -> V_58 + V_57 ) ;
V_83 -> V_87 [ V_85 ] . V_47 = V_51 -> V_47 ;
V_83 -> V_87 [ V_85 ] . V_48 = V_48 ;
V_83 -> V_48 += V_48 ;
V_83 -> V_86 ++ ;
F_2 ( V_77 ,
L_18 ,
V_85 , V_51 , V_51 -> V_41 . V_66 . V_81 , V_48 , V_115 ) ;
}
if ( V_83 -> V_86 < V_119 ) {
for ( V_85 = V_83 -> V_86 - 1 ; V_85 >= 0 ; V_85 -- ) {
V_51 = V_83 -> V_87 [ V_85 ] . V_51 ;
if ( V_51 ) {
V_51 -> V_47 += V_57 ;
F_49 ( & V_51 -> V_26 , V_106 ) ;
}
}
return - V_120 ;
}
return V_72 ;
}
static void F_50 ( struct V_70 * V_7 ,
struct V_10 * V_106 ,
int * V_121 , int * V_122 )
{
struct V_28 * V_62 = V_7 -> V_62 ;
struct V_82 * V_83 = NULL ;
int V_114 , V_123 = 0 , V_124 = 0 , V_85 ;
struct V_50 * V_51 ;
int V_72 ;
T_3 V_125 ;
T_2 V_126 = V_127 ;
if ( ( V_128 != V_7 -> V_19 ) &&
( V_24 != V_7 -> V_19 ) )
V_126 = V_62 -> V_88 -> V_89 -> V_129 [ V_7 -> V_60 ] ;
while ( true ) {
V_72 = 0 ;
V_114 = F_31 ( V_106 ) ;
V_114 = F_12 ( V_114 , V_62 -> V_130 ) ;
if ( V_114 < V_119 )
break;
V_83 = F_51 ( V_62 -> V_88 -> V_89 ) ;
if ( ! V_83 ) {
F_2 ( V_77 ,
L_19 ) ;
break;
}
if ( ( V_126 < V_127 ) && ( V_126 != V_131 ) ) {
if ( V_132 == V_126 )
V_125 = ( 1 << V_131 ) ;
else
V_125 = ( ( 1 << V_126 ) - 1 ) ;
if ( V_83 -> V_133 < V_134 )
V_62 -> V_135 &= ~ V_125 ;
else
V_62 -> V_135 |= V_125 ;
}
F_2 ( V_77 , L_20 ,
V_114 ) ;
V_83 -> V_48 = 0 ;
V_83 -> V_86 = 0 ;
V_72 = F_48 ( V_62 , V_7 ,
V_83 , V_114 ,
V_106 ) ;
if ( V_72 == - V_120 ) {
F_37 ( V_62 -> V_88 -> V_89 , V_83 ) ;
break;
}
V_83 -> V_136 = F_36 ;
V_123 ++ ;
V_124 += V_83 -> V_86 ;
F_2 ( V_77 ,
L_21 ,
V_83 -> V_48 , V_83 -> V_86 ) ;
for ( V_85 = 0 ; V_85 < V_83 -> V_86 ; V_85 ++ ) {
V_51 = V_83 -> V_87 [ V_85 ] . V_51 ;
F_42 ( V_51 -> V_72 , V_51 -> V_7 ,
V_51 -> V_47 , V_51 -> V_58 ) ;
}
F_52 ( V_62 -> V_88 , V_83 , false ) ;
if ( V_72 )
break;
}
* V_121 = V_123 ;
* V_122 = V_124 ;
F_2 ( V_77 , L_22 ,
V_123 ) ;
return;
}
static void F_53 ( struct V_28 * V_62 ,
struct V_70 * V_7 )
{
struct V_10 V_76 ;
struct V_50 * V_51 ;
int V_137 ;
int V_138 ;
T_2 V_126 = V_127 ;
int V_72 ;
F_22 ( & V_62 -> V_74 ) ;
V_7 -> V_139 ++ ;
if ( V_7 -> V_139 > 1 ) {
V_7 -> V_139 -- ;
F_24 ( & V_62 -> V_74 ) ;
F_2 ( V_77 , L_23 ) ;
return;
}
F_35 ( & V_76 ) ;
if ( ( V_128 != V_7 -> V_19 ) &&
( V_24 != V_7 -> V_19 ) )
V_126 = V_62 -> V_88 -> V_89 -> V_129 [ V_7 -> V_60 ] ;
while ( true ) {
if ( F_26 ( & V_7 -> V_76 ) )
break;
F_45 ( V_62 , V_7 , & V_76 ) ;
if ( F_26 ( & V_76 ) )
break;
F_24 ( & V_62 -> V_74 ) ;
V_137 = 0 ;
V_138 = 0 ;
while ( true ) {
if ( ( V_62 -> V_135 ) &&
( F_31 ( & V_76 ) >=
V_119 ) ) {
int V_140 = 0 , V_141 = 0 ;
if ( V_62 -> V_135 & ( 1 << V_126 ) ) {
F_50 ( V_7 , & V_76 ,
& V_140 , & V_141 ) ;
V_137 += V_140 ;
V_138 += V_141 ;
}
}
if ( F_26 ( & V_76 ) )
break;
V_51 = F_27 ( & V_76 , struct V_50 ,
V_26 ) ;
F_28 ( & V_51 -> V_26 ) ;
F_19 ( V_51 , V_51 -> V_41 . V_66 . V_52 ,
0 , V_51 -> V_41 . V_66 . V_81 ) ;
V_72 = F_38 ( V_62 , V_51 ) ;
if ( V_72 ) {
V_51 -> V_72 = V_72 ;
V_51 -> V_71 ( V_51 -> V_107 , V_51 ) ;
}
}
F_22 ( & V_62 -> V_74 ) ;
V_7 -> V_102 . V_142 += V_137 ;
V_7 -> V_102 . V_143 += V_138 ;
if ( ! V_137 ) {
if ( ! ( V_62 -> V_135 & ( 1 << V_126 ) ) &&
( V_126 < V_127 ) ) {
if ( ++ V_62 -> V_144 [ V_126 ] >=
V_145 ) {
V_62 -> V_144 [ V_126 ] = 0 ;
V_62 -> V_135 |= ( 1 << V_126 ) ;
}
}
} else {
if ( V_126 < V_127 )
V_62 -> V_144 [ V_126 ] = 0 ;
}
}
V_7 -> V_139 = 0 ;
F_24 ( & V_62 -> V_74 ) ;
}
static bool F_54 ( struct V_28 * V_62 ,
struct V_70 * V_7 ,
struct V_50 * V_146 )
{
struct V_147 V_148 ;
int V_36 ;
bool V_149 = false ;
V_148 = V_7 -> V_148 ;
F_22 ( & V_62 -> V_74 ) ;
V_36 = F_31 ( & V_7 -> V_76 ) ;
F_24 ( & V_62 -> V_74 ) ;
if ( V_36 >= V_7 -> V_150 )
V_149 = true ;
if ( V_149 )
F_2 ( V_77 ,
L_24 ,
V_7 -> V_60 , V_36 ,
V_7 -> V_150 ) ;
if ( V_149 && V_148 . V_151 ) {
if ( V_148 . V_151 ( V_7 -> V_62 , V_146 ) ==
V_152 ) {
V_7 -> V_102 . V_153 += 1 ;
return false ;
}
}
F_22 ( & V_62 -> V_74 ) ;
F_23 ( & V_146 -> V_26 , & V_7 -> V_76 ) ;
F_24 ( & V_62 -> V_74 ) ;
F_53 ( V_62 , V_7 ) ;
return true ;
}
static void F_55 ( struct V_28 * V_62 )
{
struct V_70 * V_7 ;
struct V_3 * V_75 ;
F_4 (cred_dist, &target->cred_dist_list, list) {
V_7 = V_75 -> V_154 ;
F_22 ( & V_62 -> V_74 ) ;
if ( ! F_26 ( & V_7 -> V_76 ) ) {
F_2 ( V_77 ,
L_25 ,
V_75 -> V_7 ,
V_7 -> V_75 . V_5 ,
F_31 ( & V_7 -> V_76 ) ) ;
F_24 ( & V_62 -> V_74 ) ;
F_53 ( V_62 , V_7 ) ;
F_22 ( & V_62 -> V_74 ) ;
}
F_24 ( & V_62 -> V_74 ) ;
}
}
static int F_56 ( struct V_28 * V_62 )
{
struct V_50 * V_155 = NULL ;
int V_72 ;
V_155 = F_25 ( V_62 , true ) ;
if ( ! V_155 )
return - V_156 ;
if ( V_62 -> V_157 >= V_158 ) {
struct V_159 * V_160 ;
T_3 V_52 = 0 ;
V_160 =
(struct V_159 * ) V_155 -> V_47 ;
memset ( V_160 , 0 , sizeof( * V_160 ) ) ;
V_160 -> V_161 =
F_57 ( V_162 ) ;
if ( V_62 -> V_130 > 0 ) {
V_52 |= V_163 ;
V_160 -> V_164 =
V_62 -> V_130 ;
}
memcpy ( & V_160 -> V_52 , & V_52 ,
sizeof( V_160 -> V_52 ) ) ;
F_58 ( V_155 , NULL , ( T_2 * ) V_160 ,
sizeof( struct V_159 ) ,
V_16 , V_165 ) ;
} else {
struct V_166 * V_167 ;
V_167 = (struct V_166 * ) V_155 -> V_47 ;
memset ( V_167 , 0 , sizeof( struct V_166 ) ) ;
V_167 -> V_161 = F_57 ( V_168 ) ;
F_58 ( V_155 , NULL , ( T_2 * ) V_167 ,
sizeof( struct V_166 ) ,
V_16 , V_165 ) ;
}
V_155 -> V_71 = NULL ;
F_19 ( V_155 , 0 , 0 , 0 ) ;
V_72 = F_38 ( V_62 , V_155 ) ;
if ( V_155 != NULL )
F_21 ( V_62 , V_155 ) ;
return V_72 ;
}
static void F_8 ( struct V_28 * V_62 ,
struct V_1 * V_78 ,
T_1 V_169 [] , int V_170 )
{
struct V_70 * V_7 ;
int V_85 , V_97 ;
V_62 -> V_78 = V_78 ;
F_23 ( & V_62 -> V_7 [ V_16 ] . V_75 . V_26 ,
& V_62 -> V_79 ) ;
for ( V_85 = 0 ; V_85 < V_170 ; V_85 ++ ) {
for ( V_97 = V_171 ; V_97 < V_172 ; V_97 ++ ) {
V_7 = & V_62 -> V_7 [ V_97 ] ;
if ( V_7 -> V_19 == V_169 [ V_85 ] ) {
F_23 ( & V_7 -> V_75 . V_26 ,
& V_62 -> V_79 ) ;
break;
}
}
if ( V_97 >= V_172 ) {
F_5 ( 1 ) ;
return;
}
}
}
static int F_59 ( struct V_28 * V_62 ,
struct V_50 * V_51 )
{
struct V_70 * V_7 ;
struct V_10 V_106 ;
F_2 ( V_77 ,
L_26 ,
V_51 -> V_7 , V_51 -> V_47 , V_51 -> V_58 ) ;
if ( V_51 -> V_7 >= V_172 ) {
F_5 ( 1 ) ;
return - V_101 ;
}
V_7 = & V_62 -> V_7 [ V_51 -> V_7 ] ;
if ( ! F_54 ( V_62 , V_7 , V_51 ) ) {
V_51 -> V_72 = ( V_62 -> V_173 & V_174 ) ?
- V_175 : - V_117 ;
F_35 ( & V_106 ) ;
F_49 ( & V_51 -> V_26 , & V_106 ) ;
F_32 ( V_7 , & V_106 ) ;
}
return 0 ;
}
static void F_60 ( struct V_28 * V_62 ,
enum V_98 V_60 , T_1 V_176 )
{
struct V_50 * V_51 , * V_177 ;
struct V_10 V_178 , V_80 ;
struct V_70 * V_7 = & V_62 -> V_7 [ V_60 ] ;
if ( ! V_7 -> V_19 ) {
F_5 ( 1 ) ;
return;
}
F_35 ( & V_178 ) ;
F_22 ( & V_62 -> V_74 ) ;
F_61 (packet, tmp_pkt, &endpoint->txq, list) {
if ( ( V_176 == V_179 ) ||
( V_176 == V_51 -> V_41 . V_66 . V_176 ) )
F_46 ( & V_51 -> V_26 , & V_178 ) ;
}
F_24 ( & V_62 -> V_74 ) ;
F_61 (packet, tmp_pkt, &discard_q, list) {
V_51 -> V_72 = - V_175 ;
F_28 ( & V_51 -> V_26 ) ;
F_2 ( V_77 ,
L_27 ,
V_51 , V_51 -> V_58 ,
V_51 -> V_7 , V_51 -> V_41 . V_66 . V_176 ) ;
F_35 ( & V_80 ) ;
F_23 ( & V_51 -> V_26 , & V_80 ) ;
F_32 ( V_7 , & V_80 ) ;
}
}
static void F_62 ( struct V_28 * V_62 )
{
struct V_70 * V_7 ;
int V_85 ;
F_63 ( V_62 ) ;
for ( V_85 = V_16 ; V_85 < V_172 ; V_85 ++ ) {
V_7 = & V_62 -> V_7 [ V_85 ] ;
if ( V_7 -> V_19 == 0 )
continue;
F_60 ( V_62 , V_85 , V_179 ) ;
}
}
static void F_64 ( struct V_28 * V_62 ,
enum V_98 V_60 ,
bool V_180 )
{
struct V_70 * V_7 = & V_62 -> V_7 [ V_60 ] ;
bool V_181 = false ;
if ( V_7 -> V_19 == 0 ) {
F_5 ( 1 ) ;
return;
}
F_22 ( & V_62 -> V_74 ) ;
if ( V_180 ) {
if ( ! ( V_7 -> V_75 . V_22 & V_23 ) ) {
V_7 -> V_75 . V_22 |= V_23 ;
V_181 = true ;
}
} else {
if ( V_7 -> V_75 . V_22 & V_23 ) {
V_7 -> V_75 . V_22 &= ~ V_23 ;
V_181 = true ;
}
}
if ( V_181 ) {
V_7 -> V_75 . V_36 =
F_31 ( & V_7 -> V_76 ) ;
F_2 ( V_77 ,
L_28 ,
V_62 -> V_78 , & V_62 -> V_79 ) ;
F_15 ( V_62 -> V_78 ,
& V_62 -> V_79 ,
V_46 ) ;
}
F_24 ( & V_62 -> V_74 ) ;
if ( V_181 && ! V_180 )
F_55 ( V_62 ) ;
}
static inline void F_65 ( struct V_70 * V_7 ,
int V_182 )
{
V_7 -> V_102 . V_183 ++ ;
if ( V_182 == 1 )
V_7 -> V_102 . V_184 ++ ;
else if ( V_182 > 1 )
V_7 -> V_102 . V_185 ++ ;
}
static inline bool F_66 ( struct V_28 * V_62 ,
enum V_98 V_60 , int V_48 )
{
return ( V_60 == V_62 -> V_88 -> V_89 -> V_186 ) ?
V_48 <= V_187 : V_48 <= V_188 ;
}
static int F_67 ( struct V_28 * V_62 , struct V_50 * V_51 )
{
struct V_10 V_106 ;
F_35 ( & V_106 ) ;
F_23 ( & V_51 -> V_26 , & V_106 ) ;
return F_68 ( V_62 , & V_106 ) ;
}
static void F_69 ( struct V_28 * V_62 ,
struct V_50 * V_51 ,
struct V_70 * V_97 )
{
if ( V_51 -> V_41 . V_189 . V_190 & V_191 ) {
F_70 ( V_51 ) ;
V_51 -> V_72 = - V_175 ;
V_97 -> V_148 . V_189 ( V_97 -> V_62 , V_51 ) ;
} else {
F_70 ( V_51 ) ;
F_67 ( ( void * ) ( V_62 ) , V_51 ) ;
}
}
static void F_71 ( struct V_28 * V_62 ,
struct V_50 * V_51 )
{
F_22 ( & V_62 -> V_64 ) ;
F_23 ( & V_51 -> V_26 , & V_62 -> V_68 ) ;
F_24 ( & V_62 -> V_64 ) ;
}
static int F_72 ( struct V_28 * V_62 ,
struct V_50 * V_51 ,
T_3 V_192 )
{
struct V_193 * V_88 = V_62 -> V_88 ;
T_3 V_91 ;
int V_72 ;
V_91 = F_39 ( V_62 , V_192 ) ;
if ( V_91 > V_51 -> V_194 ) {
F_30 ( L_29 ,
V_91 , V_192 , V_51 -> V_194 ) ;
return - V_156 ;
}
F_2 ( V_77 ,
L_30 ,
V_51 , V_51 -> V_41 . V_189 . V_195 ,
V_91 , V_88 -> V_89 -> V_93 . V_94 ) ;
V_72 = F_40 ( V_88 -> V_89 ,
V_88 -> V_89 -> V_93 . V_94 ,
V_51 -> V_47 , V_91 ,
V_196 ) ;
V_51 -> V_72 = V_72 ;
return V_72 ;
}
static void F_73 ( T_3 V_197 ,
struct V_70 * V_7 ,
struct V_50 * V_51 )
{
struct V_55 * V_198 = (struct V_55 * ) & V_197 ;
if ( V_198 -> V_60 == V_51 -> V_7 ) {
if ( ! F_26 ( & V_7 -> V_199 ) )
V_51 -> V_41 . V_189 . V_200 |=
V_201 ;
}
}
static void F_74 ( struct V_70 * V_7 )
{
struct V_147 V_148 = V_7 -> V_148 ;
if ( V_148 . V_202 > 0 ) {
F_22 ( & V_7 -> V_62 -> V_203 ) ;
if ( F_31 ( & V_7 -> V_199 )
< V_148 . V_202 ) {
F_24 ( & V_7 -> V_62 -> V_203 ) ;
V_148 . V_204 ( V_7 -> V_62 , V_7 -> V_60 ) ;
return;
}
F_24 ( & V_7 -> V_62 -> V_203 ) ;
}
}
static int F_75 ( struct V_28 * V_62 ,
struct V_70 * V_97 ,
T_3 * V_205 , struct V_10 * V_106 , int V_206 )
{
struct V_50 * V_51 ;
struct V_55 * V_198 = (struct V_55 * ) V_205 ;
struct V_147 V_148 ;
int V_72 = 0 , V_207 , V_208 ;
bool V_209 ;
V_208 = F_39 ( V_62 ,
F_76 ( V_198 -> V_59 ) +
sizeof( * V_198 ) ) ;
if ( ! F_66 ( V_62 , V_97 -> V_60 , V_208 ) ) {
F_77 ( L_31 ,
V_198 -> V_60 , V_198 -> V_52 ,
F_76 ( V_198 -> V_59 ) ) ;
return - V_101 ;
}
V_148 = V_97 -> V_148 ;
for ( V_207 = 0 ; V_207 < V_206 ; V_207 ++ ) {
V_209 = false ;
if ( V_148 . V_210 &&
( V_208 > V_148 . V_211 ) ) {
V_97 -> V_102 . V_212 += 1 ;
V_97 -> V_102 . V_213 +=
F_76 ( V_198 -> V_59 ) ;
F_24 ( & V_62 -> V_203 ) ;
V_209 = true ;
V_51 = V_148 . V_210 ( V_97 -> V_62 , V_97 -> V_60 ,
V_208 ) ;
F_22 ( & V_62 -> V_203 ) ;
} else {
if ( F_26 ( & V_97 -> V_199 ) ) {
if ( V_148 . V_204 ) {
F_24 ( & V_62 -> V_203 ) ;
V_148 . V_204 ( V_97 -> V_62 , V_97 -> V_60 ) ;
F_22 ( & V_62 -> V_203 ) ;
}
}
if ( F_26 ( & V_97 -> V_199 ) )
V_51 = NULL ;
else {
V_51 = F_27 ( & V_97 -> V_199 ,
struct V_50 , V_26 ) ;
F_28 ( & V_51 -> V_26 ) ;
}
}
if ( ! V_51 ) {
V_62 -> V_214 |= V_215 ;
V_62 -> V_216 = V_97 -> V_60 ;
return - V_117 ;
}
V_51 -> V_41 . V_189 . V_190 = 0 ;
V_51 -> V_41 . V_189 . V_200 = 0 ;
V_51 -> V_72 = 0 ;
if ( V_209 )
V_51 -> V_41 . V_189 . V_190 |= V_191 ;
F_23 ( & V_51 -> V_26 , V_106 ) ;
if ( V_62 -> V_173 & V_174 ) {
V_72 = - V_175 ;
break;
}
if ( V_207 ) {
V_51 -> V_41 . V_189 . V_190 |= V_217 ;
V_51 -> V_41 . V_189 . V_195 = 0xFFFFFFFF ;
} else
V_51 -> V_41 . V_189 . V_195 = * V_205 ;
V_51 -> V_58 = F_76 ( V_198 -> V_59 ) +
V_57 ;
}
return V_72 ;
}
static int F_78 ( struct V_28 * V_62 ,
T_3 V_205 [] , int V_218 ,
struct V_70 * V_7 ,
struct V_10 * V_106 )
{
int V_72 = 0 ;
struct V_50 * V_51 , * V_177 ;
struct V_55 * V_198 ;
int V_85 , V_206 ;
F_22 ( & V_62 -> V_203 ) ;
for ( V_85 = 0 ; V_85 < V_218 ; V_85 ++ ) {
V_198 = (struct V_55 * ) & V_205 [ V_85 ] ;
if ( V_198 -> V_60 >= V_172 ) {
F_30 ( L_32 ,
V_198 -> V_60 ) ;
V_72 = - V_156 ;
break;
}
if ( V_198 -> V_60 != V_7 -> V_60 ) {
F_30 ( L_33 ,
V_198 -> V_60 , V_7 -> V_60 , V_85 ) ;
V_72 = - V_156 ;
break;
}
if ( F_76 ( V_198 -> V_59 ) > V_219 ) {
F_30 ( L_34 ,
V_198 -> V_59 ,
( T_3 ) V_219 ) ;
V_72 = - V_156 ;
break;
}
if ( V_7 -> V_19 == 0 ) {
F_30 ( L_35 , V_198 -> V_60 ) ;
V_72 = - V_156 ;
break;
}
if ( V_198 -> V_52 & V_220 ) {
V_206 = ( V_198 -> V_52 & V_220 ) >>
V_221 ;
V_206 ++ ;
if ( V_206 > V_62 -> V_130 ) {
V_72 = - V_156 ;
break;
}
V_7 -> V_102 . V_222 += 1 ;
F_2 ( V_77 ,
L_36 ,
V_206 ) ;
} else
V_206 = 1 ;
V_72 = F_75 ( V_62 , V_7 , & V_205 [ V_85 ] ,
V_106 , V_206 ) ;
if ( V_72 == - V_117 ) {
F_24 ( & V_62 -> V_203 ) ;
return 0 ;
}
if ( V_72 )
break;
}
F_24 ( & V_62 -> V_203 ) ;
if ( V_72 ) {
F_61 (packet, tmp_pkt, queue, list) {
F_28 ( & V_51 -> V_26 ) ;
F_69 ( V_62 , V_51 ,
& V_62 -> V_7 [ V_51 -> V_7 ] ) ;
}
}
return V_72 ;
}
static void F_79 ( struct V_28 * V_107 , struct V_50 * V_223 )
{
if ( V_223 -> V_7 != V_16 ) {
F_5 ( 1 ) ;
return;
}
if ( V_223 -> V_72 == - V_175 ) {
F_71 ( V_107 , V_223 ) ;
return;
}
if ( V_223 -> V_58 > 0 ) {
F_30 ( L_37 ,
V_223 -> V_58 + V_57 ) ;
F_80 ( V_77 ,
L_38 , L_39 ,
V_223 -> V_47 - V_57 ,
V_223 -> V_58 + V_57 ) ;
}
F_69 ( V_107 , V_223 , & V_107 -> V_7 [ 0 ] ) ;
}
static void F_81 ( struct V_28 * V_62 ,
struct V_224 * V_225 ,
int V_226 ,
enum V_98 V_227 )
{
struct V_70 * V_7 ;
int V_12 = 0 , V_85 ;
bool V_181 = false ;
F_22 ( & V_62 -> V_74 ) ;
for ( V_85 = 0 ; V_85 < V_226 ; V_85 ++ , V_225 ++ ) {
if ( V_225 -> V_60 >= V_172 ) {
F_5 ( 1 ) ;
F_24 ( & V_62 -> V_74 ) ;
return;
}
V_7 = & V_62 -> V_7 [ V_225 -> V_60 ] ;
F_2 ( V_6 ,
L_40 ,
V_225 -> V_60 , V_225 -> V_5 ) ;
V_7 -> V_102 . V_228 += 1 ;
V_7 -> V_102 . V_229 += V_225 -> V_5 ;
if ( V_227 == V_225 -> V_60 ) {
V_7 -> V_102 . V_230 += V_225 -> V_5 ;
V_7 -> V_102 . V_231 += 1 ;
} else if ( V_227 == V_16 ) {
V_7 -> V_102 . V_232 += V_225 -> V_5 ;
V_7 -> V_102 . V_233 += 1 ;
} else {
V_7 -> V_102 . V_234 += V_225 -> V_5 ;
V_7 -> V_102 . V_235 += 1 ;
}
if ( V_225 -> V_60 == V_16 )
V_7 -> V_75 . V_5 += V_225 -> V_5 ;
else {
V_7 -> V_75 . V_35 += V_225 -> V_5 ;
V_181 = true ;
}
V_7 -> V_75 . V_36 =
F_31 ( & V_7 -> V_76 ) ;
V_12 += V_225 -> V_5 ;
}
if ( V_181 ) {
F_15 ( V_62 -> V_78 ,
& V_62 -> V_79 ,
V_45 ) ;
}
F_24 ( & V_62 -> V_74 ) ;
if ( V_12 )
F_55 ( V_62 ) ;
}
static int F_82 ( struct V_28 * V_62 ,
struct V_236 * V_237 ,
T_2 * V_238 , T_3 * V_239 ,
enum V_98 V_7 ,
int * V_240 )
{
struct V_241 * V_242 ;
struct V_243 * V_197 ;
int V_48 ;
switch ( V_237 -> V_244 ) {
case V_245 :
V_48 = V_237 -> V_48 / sizeof( struct V_224 ) ;
if ( ! V_48 ) {
F_5 ( 1 ) ;
return - V_101 ;
}
F_81 ( V_62 ,
(struct V_224 * ) V_238 ,
V_48 , V_7 ) ;
break;
case V_246 :
V_48 = V_237 -> V_48 / sizeof( * V_197 ) ;
if ( ! V_48 ) {
F_5 ( 1 ) ;
return - V_101 ;
}
V_197 = (struct V_243 * ) V_238 ;
if ( ( V_197 -> V_247 == ( ( ~ V_197 -> V_248 ) & 0xFF ) ) &&
V_239 ) {
F_2 ( V_77 ,
L_41 ,
V_197 -> V_247 , V_197 -> V_248 ) ;
memcpy ( ( T_2 * ) & V_239 [ 0 ] , V_197 -> V_197 , 4 ) ;
F_80 ( V_77 ,
L_42 ,
L_39 , V_239 , 4 ) ;
* V_240 = 1 ;
}
break;
case V_249 :
V_48 = V_237 -> V_48 / sizeof( * V_242 ) ;
if ( ! V_48 || ( V_48 > V_250 ) ) {
F_5 ( 1 ) ;
return - V_101 ;
}
if ( V_239 ) {
int V_85 ;
V_242 =
(struct V_241 * ) V_238 ;
F_80 ( V_77 , L_43 ,
L_39 , V_238 , V_237 -> V_48 ) ;
for ( V_85 = 0 ; V_85 < V_48 ; V_85 ++ ) {
memcpy ( ( T_2 * ) & V_239 [ V_85 ] ,
V_242 -> V_197 , 4 ) ;
V_242 ++ ;
}
* V_240 = V_85 ;
}
break;
default:
F_30 ( L_44 ,
V_237 -> V_244 , V_237 -> V_48 ) ;
break;
}
return 0 ;
}
static int F_83 ( struct V_28 * V_62 ,
T_2 * V_47 , int V_48 , T_3 * V_239 ,
int * V_240 , enum V_98 V_7 )
{
struct V_236 * V_237 ;
int V_251 ;
int V_72 ;
T_2 * V_238 ;
T_2 * V_252 ;
F_2 ( V_77 , L_45 , V_48 ) ;
F_80 ( V_77 , NULL , L_39 , V_47 , V_48 ) ;
V_252 = V_47 ;
V_251 = V_48 ;
V_72 = 0 ;
while ( V_48 > 0 ) {
if ( V_48 < sizeof( struct V_236 ) ) {
V_72 = - V_156 ;
break;
}
V_237 = (struct V_236 * ) V_47 ;
V_48 -= sizeof( struct V_236 ) ;
V_47 += sizeof( struct V_236 ) ;
if ( V_237 -> V_48 > V_48 ) {
F_30 ( L_46 ,
V_237 -> V_48 , V_237 -> V_244 , V_48 ) ;
V_72 = - V_156 ;
break;
}
V_238 = V_47 ;
V_72 = F_82 ( V_62 , V_237 , V_238 ,
V_239 , V_7 , V_240 ) ;
if ( V_72 )
break;
V_47 += V_237 -> V_48 ;
V_48 -= V_237 -> V_48 ;
}
if ( V_72 )
F_80 ( V_77 , L_47 ,
L_39 , V_252 , V_251 ) ;
return V_72 ;
}
static int F_84 ( struct V_28 * V_62 ,
struct V_50 * V_51 ,
T_3 * V_253 , int * V_254 )
{
int V_72 = 0 ;
T_1 V_255 ;
T_3 V_197 ;
struct V_55 * V_198 = (struct V_55 * ) V_51 -> V_47 ;
if ( V_254 != NULL )
* V_254 = 0 ;
V_255 = F_76 ( F_85 ( & V_198 -> V_59 ) ) ;
memcpy ( ( T_2 * ) & V_197 , V_51 -> V_47 , sizeof( V_197 ) ) ;
if ( V_51 -> V_41 . V_189 . V_190 & V_217 ) {
V_51 -> V_41 . V_189 . V_195 = V_197 ;
V_51 -> V_58 = V_255 + V_57 ;
if ( V_51 -> V_58 > V_51 -> V_194 ) {
F_30 ( L_48 ,
V_255 , V_197 ) ;
V_51 -> V_58 = F_12 ( V_51 -> V_58 , V_51 -> V_194 ) ;
V_72 = - V_156 ;
goto V_256;
}
if ( V_51 -> V_7 != V_198 -> V_60 ) {
F_30 ( L_49 ,
V_198 -> V_60 , V_51 -> V_7 ) ;
V_72 = - V_156 ;
goto V_256;
}
}
if ( V_197 != V_51 -> V_41 . V_189 . V_195 ) {
F_30 ( L_50 ,
V_257 , V_51 , V_51 -> V_41 . V_189 . V_190 ) ;
F_80 ( V_77 , L_51 ,
L_39 , & V_51 -> V_41 . V_189 . V_195 , 4 ) ;
F_80 ( V_77 , L_52 ,
L_39 , ( T_2 * ) & V_197 , sizeof( V_197 ) ) ;
V_72 = - V_156 ;
goto V_256;
}
if ( V_198 -> V_52 & V_258 ) {
if ( V_198 -> V_61 [ 0 ] < sizeof( struct V_236 ) ||
V_198 -> V_61 [ 0 ] > V_255 ) {
F_30 ( L_53 ,
V_257 , V_255 , V_198 -> V_61 [ 0 ] ) ;
V_72 = - V_156 ;
goto V_256;
}
if ( V_51 -> V_41 . V_189 . V_190 & V_259 ) {
V_253 = NULL ;
V_254 = NULL ;
}
V_72 = F_83 ( V_62 , V_51 -> V_47 + V_57
+ V_255 - V_198 -> V_61 [ 0 ] ,
V_198 -> V_61 [ 0 ] , V_253 ,
V_254 , V_51 -> V_7 ) ;
if ( V_72 )
goto V_256;
V_51 -> V_58 -= V_198 -> V_61 [ 0 ] ;
}
V_51 -> V_47 += V_57 ;
V_51 -> V_58 -= V_57 ;
V_256:
if ( V_72 )
F_80 ( V_77 , L_54 ,
L_39 , V_51 -> V_47 , V_51 -> V_58 ) ;
return V_72 ;
}
static void F_86 ( struct V_70 * V_7 ,
struct V_50 * V_51 )
{
F_2 ( V_77 ,
L_55 ,
V_7 -> V_60 , V_51 ) ;
V_7 -> V_148 . V_189 ( V_7 -> V_62 , V_51 ) ;
}
static int F_87 ( struct V_28 * V_62 ,
struct V_10 * V_260 ,
struct V_10 * V_261 ,
int * V_262 , bool V_263 )
{
struct V_82 * V_83 ;
struct V_50 * V_51 ;
int V_264 = V_62 -> V_265 ;
int V_266 , V_72 = 0 , V_85 , V_48 ;
V_266 = F_31 ( V_260 ) ;
V_266 = F_12 ( V_266 , V_62 -> V_130 ) ;
if ( ( F_31 ( V_260 ) - V_266 ) > 0 ) {
V_263 = true ;
F_77 ( L_56 ,
V_257 , F_31 ( V_260 ) , V_266 ) ;
}
V_48 = 0 ;
F_2 ( V_77 ,
L_57 ,
F_31 ( V_260 ) , V_266 ) ;
V_83 = F_51 ( V_62 -> V_88 -> V_89 ) ;
if ( V_83 == NULL )
goto V_267;
for ( V_85 = 0 ; V_85 < V_266 ; V_85 ++ ) {
int V_268 ;
V_51 = F_27 ( V_260 , struct V_50 , V_26 ) ;
F_28 ( & V_51 -> V_26 ) ;
V_268 = F_39 ( V_62 ,
V_51 -> V_58 ) ;
if ( ( V_264 - V_268 ) < 0 ) {
F_49 ( & V_51 -> V_26 , V_260 ) ;
break;
}
V_264 -= V_268 ;
if ( V_263 || ( V_85 < ( V_266 - 1 ) ) )
V_51 -> V_41 . V_189 . V_190 |=
V_259 ;
V_83 -> V_87 [ V_85 ] . V_47 = V_51 -> V_47 ;
V_83 -> V_87 [ V_85 ] . V_48 = V_268 ;
V_51 -> V_41 . V_189 . V_190 |= V_269 ;
F_23 ( & V_51 -> V_26 , V_261 ) ;
F_5 ( ! V_83 -> V_87 [ V_85 ] . V_48 ) ;
V_48 += V_83 -> V_87 [ V_85 ] . V_48 ;
}
V_83 -> V_48 = V_48 ;
V_83 -> V_86 = V_85 ;
V_72 = F_52 ( V_62 -> V_88 , V_83 , true ) ;
if ( ! V_72 )
* V_262 = V_85 ;
F_37 ( V_62 -> V_88 -> V_89 , V_83 ) ;
V_267:
return V_72 ;
}
static int F_88 ( struct V_28 * V_62 ,
struct V_10 * V_270 ,
T_3 V_205 [] ,
int * V_271 )
{
struct V_50 * V_51 , * V_177 ;
struct V_70 * V_97 ;
int V_72 = 0 ;
F_61 (packet, tmp_pkt, comp_pktq, list) {
V_97 = & V_62 -> V_7 [ V_51 -> V_7 ] ;
F_89 ( V_51 -> V_72 , V_51 -> V_7 ,
V_51 -> V_47 , V_51 -> V_58 ) ;
V_72 = F_84 ( V_62 , V_51 , V_205 ,
V_271 ) ;
if ( V_72 )
return V_72 ;
F_28 ( & V_51 -> V_26 ) ;
if ( F_26 ( V_270 ) ) {
if ( * V_271 > 0 )
F_73 ( V_205 [ 0 ] ,
V_97 , V_51 ) ;
} else
V_51 -> V_41 . V_189 . V_200 |=
V_201 ;
F_65 ( V_97 , * V_271 ) ;
if ( V_51 -> V_41 . V_189 . V_190 & V_269 )
V_97 -> V_102 . V_272 += 1 ;
F_86 ( V_97 , V_51 ) ;
}
return V_72 ;
}
static int F_90 ( struct V_28 * V_62 ,
struct V_10 * V_273 ,
struct V_10 * V_270 )
{
int V_274 ;
bool V_263 = false ;
int V_72 = 0 ;
struct V_10 V_275 ;
struct V_50 * V_51 , * V_177 ;
while ( ! F_26 ( V_273 ) ) {
V_274 = 0 ;
F_35 ( & V_275 ) ;
if ( V_62 -> V_276 && ( F_31 ( V_273 ) > 1 ) ) {
V_72 = F_87 ( V_62 , V_273 ,
& V_275 ,
& V_274 ,
V_263 ) ;
if ( V_72 )
goto V_256;
if ( ! F_26 ( V_273 ) )
V_263 = true ;
F_91 ( & V_275 , V_270 ) ;
}
if ( ! V_274 ) {
V_51 = F_27 ( V_273 , struct V_50 ,
V_26 ) ;
V_51 -> V_71 = NULL ;
if ( ! F_92 ( V_273 ) )
V_51 -> V_41 . V_189 . V_190 |=
V_259 ;
V_72 = F_72 ( V_62 , V_51 ,
V_51 -> V_58 ) ;
F_46 ( & V_51 -> V_26 , & V_275 ) ;
if ( V_72 )
goto V_256;
F_91 ( & V_275 , V_270 ) ;
}
}
return 0 ;
V_256:
F_61 (packet, tmp_pkt, rx_pktq, list) {
F_28 ( & V_51 -> V_26 ) ;
F_69 ( V_62 , V_51 ,
& V_62 -> V_7 [ V_51 -> V_7 ] ) ;
}
F_61 (packet, tmp_pkt, &tmp_rxq, list) {
F_28 ( & V_51 -> V_26 ) ;
F_69 ( V_62 , V_51 ,
& V_62 -> V_7 [ V_51 -> V_7 ] ) ;
}
return V_72 ;
}
int F_93 ( struct V_28 * V_62 ,
T_3 V_277 , int * V_278 )
{
struct V_50 * V_223 , * V_177 ;
struct V_70 * V_7 ;
struct V_10 V_273 , V_270 ;
int V_72 = 0 ;
T_3 V_279 [ V_250 ] ;
int V_280 = 1 ;
enum V_98 V_281 ;
int V_282 = 0 ;
F_35 ( & V_270 ) ;
* V_278 = 0 ;
V_279 [ 0 ] = V_277 ;
while ( true ) {
V_281 = ( (struct V_55 * ) & V_279 [ 0 ] ) -> V_60 ;
V_7 = & V_62 -> V_7 [ V_281 ] ;
if ( V_281 >= V_172 ) {
F_30 ( L_58 ,
V_281 ) ;
V_72 = - V_156 ;
break;
}
F_35 ( & V_273 ) ;
F_35 ( & V_270 ) ;
V_72 = F_78 ( V_62 , V_279 ,
V_280 , V_7 ,
& V_273 ) ;
if ( V_72 )
break;
if ( F_31 ( & V_273 ) >= 2 )
V_62 -> V_283 = 1 ;
V_282 += F_31 ( & V_273 ) ;
V_280 = 0 ;
V_72 = F_90 ( V_62 , & V_273 , & V_270 ) ;
if ( ! V_72 )
F_74 ( V_7 ) ;
V_72 = F_88 ( V_62 , & V_270 ,
V_279 ,
& V_280 ) ;
if ( ! V_280 || V_72 )
break;
V_62 -> V_283 = 1 ;
}
if ( V_72 ) {
F_30 ( L_59 ,
V_72 ) ;
F_61 (packets, tmp_pkt, &comp_pktq, list) {
F_28 ( & V_223 -> V_26 ) ;
F_69 ( V_62 , V_223 ,
& V_62 -> V_7 [ V_223 -> V_7 ] ) ;
}
if ( V_62 -> V_173 & V_174 ) {
F_77 ( L_60 ) ;
F_94 ( V_62 -> V_88 , false ) ;
}
}
if ( V_62 -> V_214 & V_215 ) {
F_77 ( L_61 ) ;
F_94 ( V_62 -> V_88 , false ) ;
}
* V_278 = V_282 ;
return V_72 ;
}
static struct V_50 * F_95 ( struct V_28 * V_62 )
{
struct V_50 * V_51 = NULL ;
struct V_55 * V_198 ;
T_3 V_284 ;
if ( F_96 ( V_62 -> V_88 , & V_284 ,
V_285 ) )
return NULL ;
F_2 ( V_77 ,
L_62 , V_284 ) ;
V_198 = (struct V_55 * ) & V_284 ;
if ( V_198 -> V_60 != V_16 )
return NULL ;
V_51 = F_25 ( V_62 , false ) ;
if ( ! V_51 )
return NULL ;
V_51 -> V_41 . V_189 . V_190 = 0 ;
V_51 -> V_41 . V_189 . V_195 = V_284 ;
V_51 -> V_58 = F_76 ( V_198 -> V_59 ) + V_57 ;
if ( V_51 -> V_58 > V_51 -> V_194 )
goto V_286;
V_51 -> V_71 = NULL ;
if ( F_72 ( V_62 , V_51 , V_51 -> V_58 ) )
goto V_286;
F_89 ( V_51 -> V_72 , V_51 -> V_7 ,
V_51 -> V_47 , V_51 -> V_58 ) ;
V_51 -> V_72 = F_84 ( V_62 , V_51 , NULL , NULL ) ;
if ( V_51 -> V_72 ) {
F_30 ( L_63 ,
V_51 -> V_72 ) ;
goto V_286;
}
return V_51 ;
V_286:
if ( V_51 != NULL ) {
F_70 ( V_51 ) ;
F_71 ( V_62 , V_51 ) ;
}
return NULL ;
}
static int F_68 ( struct V_28 * V_62 ,
struct V_10 * V_287 )
{
struct V_70 * V_7 ;
struct V_50 * V_288 ;
bool V_289 = false ;
int V_72 = 0 , V_290 ;
if ( F_26 ( V_287 ) )
return - V_156 ;
V_288 = F_27 ( V_287 , struct V_50 , V_26 ) ;
if ( V_288 -> V_7 >= V_172 )
return V_72 ;
V_290 = F_31 ( V_287 ) ;
F_2 ( V_77 ,
L_64 ,
V_288 -> V_7 , V_290 , V_288 -> V_194 ) ;
V_7 = & V_62 -> V_7 [ V_288 -> V_7 ] ;
if ( V_62 -> V_173 & V_174 ) {
struct V_50 * V_51 , * V_177 ;
F_61 (packet, tmp_pkt, pkt_queue, list) {
V_51 -> V_72 = - V_175 ;
F_28 ( & V_51 -> V_26 ) ;
F_86 ( V_7 , V_51 ) ;
}
return V_72 ;
}
F_22 ( & V_62 -> V_203 ) ;
F_91 ( V_287 , & V_7 -> V_199 ) ;
if ( V_62 -> V_214 & V_215 ) {
if ( V_62 -> V_216 == V_288 -> V_7 ) {
F_2 ( V_77 ,
L_65 ,
V_62 -> V_216 ) ;
V_62 -> V_214 &= ~ V_215 ;
V_62 -> V_216 = V_172 ;
V_289 = true ;
}
}
F_24 ( & V_62 -> V_203 ) ;
if ( V_289 && ! ( V_62 -> V_173 & V_174 ) )
F_94 ( V_62 -> V_88 , true ) ;
return V_72 ;
}
static void F_97 ( struct V_28 * V_62 )
{
struct V_70 * V_7 ;
struct V_50 * V_51 , * V_177 ;
int V_85 ;
for ( V_85 = V_16 ; V_85 < V_172 ; V_85 ++ ) {
V_7 = & V_62 -> V_7 [ V_85 ] ;
if ( ! V_7 -> V_19 )
continue;
F_22 ( & V_62 -> V_203 ) ;
F_61 (packet, tmp_pkt,
&endpoint->rx_bufq, list) {
F_28 ( & V_51 -> V_26 ) ;
F_24 ( & V_62 -> V_203 ) ;
F_2 ( V_77 ,
L_66 ,
V_51 , V_51 -> V_194 ,
V_51 -> V_7 ) ;
if ( V_51 -> V_7 == V_16 ) {
F_98 ( V_51 -> V_69 ) ;
F_98 ( V_51 ) ;
} else {
F_99 ( V_51 -> V_291 ) ;
}
F_22 ( & V_62 -> V_203 ) ;
}
F_24 ( & V_62 -> V_203 ) ;
}
}
static int F_100 ( struct V_28 * V_62 ,
struct V_292 * V_293 ,
struct V_294 * V_295 )
{
struct V_50 * V_296 = NULL ;
struct V_50 * V_146 = NULL ;
struct V_297 * V_298 ;
struct V_299 * V_300 ;
struct V_70 * V_7 ;
enum V_98 V_301 = V_172 ;
unsigned int V_302 = 0 ;
int V_72 = 0 ;
T_1 V_161 ;
F_2 ( V_77 ,
L_67 ,
V_62 , V_293 -> V_19 ) ;
if ( V_293 -> V_19 == V_128 ) {
V_301 = V_16 ;
V_302 = V_303 ;
} else {
V_146 = F_25 ( V_62 , true ) ;
if ( ! V_146 )
return - V_156 ;
V_300 = (struct V_299 * ) V_146 -> V_47 ;
memset ( V_300 , 0 , sizeof( * V_300 ) ) ;
V_300 -> V_161 = F_57 ( V_304 ) ;
V_300 -> V_19 = F_57 ( V_293 -> V_19 ) ;
V_300 -> V_112 = F_57 ( V_293 -> V_112 ) ;
F_58 ( V_146 , NULL , ( T_2 * ) V_300 ,
sizeof( * V_300 ) + V_300 -> V_305 ,
V_16 , V_165 ) ;
V_146 -> V_71 = NULL ;
F_19 ( V_146 , 0 , 0 , 0 ) ;
V_72 = F_38 ( V_62 , V_146 ) ;
if ( V_72 )
goto V_306;
V_296 = F_95 ( V_62 ) ;
if ( ! V_296 ) {
V_72 = - V_156 ;
goto V_306;
}
V_298 = (struct V_297 * ) V_296 -> V_47 ;
V_161 = F_76 ( V_298 -> V_161 ) ;
if ( ( V_161 != V_307 ) ||
( V_296 -> V_58 < sizeof( * V_298 ) ) ) {
V_72 = - V_156 ;
goto V_306;
}
V_295 -> V_308 = V_298 -> V_72 ;
if ( V_298 -> V_72 != V_309 ) {
F_30 ( L_68 ,
V_298 -> V_19 , V_298 -> V_72 ) ;
V_72 = - V_156 ;
goto V_306;
}
V_301 = (enum V_98 ) V_298 -> V_60 ;
V_302 = F_76 ( V_298 -> V_302 ) ;
}
if ( F_101 ( V_301 == V_310 ||
V_301 >= V_172 || ! V_302 ) ) {
V_72 = - V_156 ;
goto V_306;
}
V_7 = & V_62 -> V_7 [ V_301 ] ;
V_7 -> V_60 = V_301 ;
if ( V_7 -> V_19 ) {
V_72 = - V_156 ;
goto V_306;
}
V_295 -> V_7 = V_301 ;
V_295 -> V_311 = V_302 ;
V_7 -> V_19 = V_293 -> V_19 ;
V_7 -> V_150 = V_293 -> V_150 ;
V_7 -> V_311 = V_302 ;
V_7 -> V_148 = V_293 -> V_148 ;
V_7 -> V_75 . V_19 = V_293 -> V_19 ;
V_7 -> V_75 . V_154 = V_7 ;
V_7 -> V_75 . V_7 = V_301 ;
V_7 -> V_75 . V_109 = V_62 -> V_100 ;
switch ( V_7 -> V_19 ) {
case V_20 :
V_7 -> V_312 = V_313 / 3 ;
break;
default:
V_7 -> V_312 = V_314 ;
break;
}
if ( V_293 -> V_315 ) {
if ( V_293 -> V_315 > V_302 ) {
V_72 = - V_156 ;
goto V_306;
}
V_7 -> V_75 . V_18 =
V_293 -> V_315 / V_62 -> V_100 ;
} else
V_7 -> V_75 . V_18 =
V_302 / V_62 -> V_100 ;
if ( ! V_7 -> V_75 . V_18 )
V_7 -> V_75 . V_18 = 1 ;
V_7 -> V_112 = V_293 -> V_52 ;
V_306:
if ( V_146 )
F_21 ( V_62 , V_146 ) ;
if ( V_296 ) {
F_70 ( V_296 ) ;
F_71 ( V_62 , V_296 ) ;
}
return V_72 ;
}
static void F_102 ( struct V_28 * V_62 )
{
struct V_70 * V_7 ;
int V_85 ;
for ( V_85 = V_16 ; V_85 < V_172 ; V_85 ++ ) {
V_7 = & V_62 -> V_7 [ V_85 ] ;
memset ( & V_7 -> V_75 , 0 , sizeof( V_7 -> V_75 ) ) ;
V_7 -> V_19 = 0 ;
V_7 -> V_311 = 0 ;
V_7 -> V_150 = 0 ;
memset ( & V_7 -> V_102 , 0 ,
sizeof( V_7 -> V_102 ) ) ;
F_35 ( & V_7 -> V_199 ) ;
F_35 ( & V_7 -> V_76 ) ;
V_7 -> V_62 = V_62 ;
}
F_35 ( & V_62 -> V_79 ) ;
}
static int F_103 ( struct V_28 * V_62 ,
enum V_98 V_7 )
{
int V_316 ;
F_22 ( & V_62 -> V_203 ) ;
V_316 = F_31 ( & ( V_62 -> V_7 [ V_7 ] . V_199 ) ) ;
F_24 ( & V_62 -> V_203 ) ;
return V_316 ;
}
static void F_104 ( struct V_28 * V_62 )
{
V_62 -> V_130 = F_12 ( V_250 ,
V_62 -> V_130 ) ;
if ( F_105 ( V_62 -> V_88 -> V_89 ) ) {
V_62 -> V_130 = 0 ;
return;
}
V_62 -> V_130 = F_12 ( V_62 -> V_317 ,
V_62 -> V_130 ) ;
F_2 ( V_318 ,
L_69 ,
V_62 -> V_130 ) ;
V_62 -> V_265 = V_62 -> V_319 ;
V_62 -> V_116 = F_12 ( V_320 ,
V_62 -> V_319 ) ;
F_2 ( V_318 , L_70 ,
V_62 -> V_265 , V_62 -> V_116 ) ;
if ( V_62 -> V_116 )
V_62 -> V_135 = ( 1 << V_127 ) - 1 ;
if ( V_62 -> V_265 )
V_62 -> V_276 = true ;
if ( ( V_62 -> V_100 % V_62 -> V_321 ) != 0 ) {
F_77 ( L_71 ,
V_62 -> V_100 ) ;
V_62 -> V_135 = 0 ;
}
}
static int F_106 ( struct V_28 * V_62 )
{
struct V_50 * V_51 = NULL ;
struct V_322 * V_323 ;
struct V_292 V_324 ;
struct V_294 V_325 ;
int V_72 ;
V_51 = F_95 ( V_62 ) ;
if ( ! V_51 )
return - V_156 ;
V_323 = (struct V_322 * ) V_51 -> V_47 ;
if ( ( F_76 ( V_323 -> V_326 . V_161 ) != V_327 ) ||
( V_51 -> V_58 < sizeof( struct V_328 ) ) ) {
V_72 = - V_156 ;
goto V_329;
}
if ( ! V_323 -> V_326 . V_330 || ! V_323 -> V_326 . V_109 ) {
V_72 = - V_156 ;
goto V_329;
}
V_62 -> V_331 = F_76 ( V_323 -> V_326 . V_330 ) ;
V_62 -> V_100 = F_76 ( V_323 -> V_326 . V_109 ) ;
F_2 ( V_318 ,
L_72 ,
V_62 -> V_331 , V_62 -> V_100 ) ;
if ( V_51 -> V_58 >= sizeof( struct V_322 ) ) {
V_62 -> V_157 = V_323 -> V_332 ;
V_62 -> V_130 = V_323 -> V_333 ;
} else {
V_62 -> V_157 = V_334 ;
V_62 -> V_130 = 0 ;
}
F_2 ( V_318 , L_73 ,
( V_62 -> V_157 == V_334 ) ? L_74 : L_75 ,
V_62 -> V_157 ) ;
if ( V_62 -> V_130 > 0 )
F_104 ( V_62 ) ;
memset ( & V_324 , 0 , sizeof( V_324 ) ) ;
memset ( & V_325 , 0 , sizeof( V_325 ) ) ;
V_324 . V_148 . V_189 = F_79 ;
V_324 . V_148 . V_204 = NULL ;
V_324 . V_148 . V_151 = NULL ;
V_324 . V_150 = V_335 ;
V_324 . V_19 = V_128 ;
V_72 = F_100 ( ( void * ) V_62 , & V_324 , & V_325 ) ;
if ( V_72 )
F_107 ( V_62 -> V_88 -> V_89 ) ;
V_329:
if ( V_51 ) {
F_70 ( V_51 ) ;
F_71 ( V_62 , V_51 ) ;
}
return V_72 ;
}
static int F_108 ( struct V_28 * V_62 )
{
struct V_50 * V_51 ;
int V_72 ;
memset ( & V_62 -> V_88 -> V_336 , 0 ,
sizeof( V_62 -> V_88 -> V_336 ) ) ;
F_109 ( V_62 -> V_88 ) ;
V_62 -> V_173 = 0 ;
V_62 -> V_214 = 0 ;
while ( ( V_51 = F_25 ( V_62 , false ) ) != NULL ) {
V_72 = F_67 ( V_62 , V_51 ) ;
if ( V_72 )
return V_72 ;
}
F_3 ( V_62 -> V_78 , & V_62 -> V_79 ,
V_62 -> V_331 ) ;
F_63 ( V_62 ) ;
V_72 = F_56 ( V_62 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_110 ( V_62 -> V_88 ) ;
if ( V_72 )
F_111 ( V_62 ) ;
return V_72 ;
}
static int F_112 ( struct V_28 * V_62 )
{
T_3 V_337 , V_338 ;
struct V_50 * V_51 ;
int V_85 ;
F_102 ( V_62 ) ;
V_337 = V_62 -> V_88 -> V_89 -> V_93 . V_337 ;
V_338 = ( V_337 > V_303 ) ?
( V_337 + V_57 ) :
( V_303 + V_57 ) ;
for ( V_85 = 0 ; V_85 < V_335 ; V_85 ++ ) {
V_51 = F_113 ( sizeof( * V_51 ) , V_339 ) ;
if ( ! V_51 )
return - V_156 ;
V_51 -> V_69 = F_113 ( V_338 , V_339 ) ;
if ( ! V_51 -> V_69 ) {
F_98 ( V_51 ) ;
return - V_156 ;
}
V_51 -> V_194 = V_338 ;
if ( V_85 < V_340 ) {
V_51 -> V_58 = 0 ;
V_51 -> V_47 = V_51 -> V_69 ;
V_51 -> V_7 = V_16 ;
F_23 ( & V_51 -> V_26 , & V_62 -> V_68 ) ;
} else
F_23 ( & V_51 -> V_26 , & V_62 -> V_65 ) ;
}
return 0 ;
}
static void F_111 ( struct V_28 * V_62 )
{
F_22 ( & V_62 -> V_64 ) ;
V_62 -> V_173 |= V_174 ;
F_24 ( & V_62 -> V_64 ) ;
F_114 ( V_62 -> V_88 ) ;
F_62 ( V_62 ) ;
F_97 ( V_62 ) ;
F_112 ( V_62 ) ;
}
static void * F_115 ( struct V_341 * V_89 )
{
struct V_28 * V_62 = NULL ;
int V_72 = 0 ;
V_62 = F_113 ( sizeof( * V_62 ) , V_339 ) ;
if ( ! V_62 ) {
F_30 ( L_76 ) ;
return NULL ;
}
V_62 -> V_88 = F_113 ( sizeof( * V_62 -> V_88 ) , V_339 ) ;
if ( ! V_62 -> V_88 ) {
F_30 ( L_76 ) ;
V_72 = - V_156 ;
goto V_342;
}
F_116 ( & V_62 -> V_64 ) ;
F_116 ( & V_62 -> V_203 ) ;
F_116 ( & V_62 -> V_74 ) ;
F_35 ( & V_62 -> V_65 ) ;
F_35 ( & V_62 -> V_68 ) ;
F_35 ( & V_62 -> V_79 ) ;
V_62 -> V_88 -> V_89 = V_89 ;
V_62 -> V_88 -> V_343 = V_62 ;
V_62 -> V_216 = V_172 ;
V_72 = F_117 ( V_62 -> V_88 ) ;
if ( V_72 )
goto V_342;
V_72 = F_112 ( V_62 ) ;
if ( V_72 )
goto V_342;
return V_62 ;
V_342:
F_118 ( V_62 ) ;
return NULL ;
}
static void F_118 ( struct V_28 * V_62 )
{
struct V_50 * V_51 , * V_344 ;
F_107 ( V_62 -> V_88 -> V_89 ) ;
F_61 (packet, tmp_packet,
&target->free_ctrl_txbuf, list) {
F_28 ( & V_51 -> V_26 ) ;
F_98 ( V_51 -> V_69 ) ;
F_98 ( V_51 ) ;
}
F_61 (packet, tmp_packet,
&target->free_ctrl_rxbuf, list) {
F_28 ( & V_51 -> V_26 ) ;
F_98 ( V_51 -> V_69 ) ;
F_98 ( V_51 ) ;
}
F_98 ( V_62 -> V_88 ) ;
F_98 ( V_62 ) ;
}
void F_119 ( struct V_341 * V_89 )
{
V_89 -> V_345 = & V_346 ;
}
