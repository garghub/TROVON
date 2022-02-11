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
} else if ( V_13 -> V_19 == V_20 )
V_2 -> V_25 = V_13 -> V_26 ;
}
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
int F_7 ( void * V_28 ,
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
F_4 (cur_dist_list, epdist_list, list) {
if ( V_34 -> V_7 == V_16 )
continue;
if ( V_34 -> V_35 > 0 ) {
V_34 -> V_5 +=
V_34 -> V_35 ;
V_34 -> V_35 = 0 ;
if ( V_34 -> V_5 >
V_34 -> V_8 )
F_9 ( V_2 ,
V_34 ,
V_34 -> V_8 ) ;
if ( V_34 -> V_5 >
V_34 -> V_27 )
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
static void F_21 ( struct V_62 * V_63 ,
struct V_50 * V_64 )
{
F_22 ( & V_63 -> V_65 ) ;
F_23 ( & V_64 -> V_26 , & V_63 -> V_66 ) ;
F_24 ( & V_63 -> V_65 ) ;
}
static struct V_50 * F_25 ( struct V_62 * V_63 ,
bool V_67 )
{
struct V_50 * V_51 = NULL ;
struct V_10 * V_68 ;
V_68 = V_67 ? & V_63 -> V_66 : & V_63 -> V_69 ;
F_22 ( & V_63 -> V_65 ) ;
if ( F_26 ( V_68 ) ) {
F_24 ( & V_63 -> V_65 ) ;
return NULL ;
}
V_51 = F_27 ( V_68 , struct V_50 , V_26 ) ;
F_28 ( & V_51 -> V_26 ) ;
F_24 ( & V_63 -> V_65 ) ;
if ( V_67 )
V_51 -> V_47 = V_51 -> V_70 + V_57 ;
return V_51 ;
}
static void F_29 ( struct V_62 * V_63 ,
struct V_71 * V_7 ,
struct V_50 * V_51 )
{
V_51 -> V_72 = NULL ;
V_51 -> V_47 += V_57 ;
if ( ! V_51 -> V_73 )
return;
F_30 ( L_5 ,
V_51 -> V_73 , V_51 -> V_7 , V_51 -> V_58 ,
V_51 -> V_41 . V_67 . V_74 ) ;
F_22 ( & V_63 -> V_75 ) ;
V_7 -> V_76 . V_35 +=
V_51 -> V_41 . V_67 . V_74 ;
V_7 -> V_76 . V_36 = F_31 ( & V_7 -> V_77 ) ;
F_2 ( V_78 , L_6 ,
V_63 -> V_79 , & V_63 -> V_80 ) ;
F_15 ( V_63 -> V_79 ,
& V_63 -> V_80 ,
V_45 ) ;
F_24 ( & V_63 -> V_75 ) ;
}
static void F_32 ( struct V_71 * V_7 ,
struct V_10 * V_77 )
{
if ( F_26 ( V_77 ) )
return;
F_2 ( V_78 ,
L_7 ,
V_7 -> V_60 , F_31 ( V_77 ) ) ;
F_33 ( V_7 -> V_63 -> V_81 -> V_82 , V_77 ) ;
}
static void F_34 ( struct V_62 * V_63 ,
struct V_50 * V_51 )
{
struct V_71 * V_7 = & V_63 -> V_7 [ V_51 -> V_7 ] ;
struct V_10 V_83 ;
F_2 ( V_78 , L_8 ,
V_51 -> V_41 . V_67 . V_84 ) ;
F_29 ( V_63 , V_7 , V_51 ) ;
F_35 ( & V_83 ) ;
F_23 ( & V_51 -> V_26 , & V_83 ) ;
F_32 ( V_7 , & V_83 ) ;
}
static void F_36 ( struct V_62 * V_63 ,
struct V_85 * V_86 )
{
struct V_71 * V_7 ;
struct V_50 * V_51 ;
struct V_10 V_87 ;
int V_88 ;
F_35 ( & V_87 ) ;
F_2 ( V_78 ,
L_9 ,
V_86 -> V_48 , V_86 -> V_89 ) ;
if ( V_86 -> V_73 )
F_30 ( L_10 , V_86 -> V_73 ) ;
V_51 = V_86 -> V_90 [ 0 ] . V_51 ;
V_7 = & V_63 -> V_7 [ V_51 -> V_7 ] ;
for ( V_88 = 0 ; V_88 < V_86 -> V_89 ; V_88 ++ ) {
V_51 = V_86 -> V_90 [ V_88 ] . V_51 ;
if ( ! V_51 ) {
F_5 ( 1 ) ;
return;
}
V_51 -> V_73 = V_86 -> V_73 ;
F_29 ( V_63 , V_7 , V_51 ) ;
F_23 ( & V_51 -> V_26 , & V_87 ) ;
}
F_37 ( V_63 -> V_81 -> V_82 , V_86 ) ;
F_32 ( V_7 , & V_87 ) ;
}
static int F_38 ( struct V_62 * V_63 ,
struct V_50 * V_51 )
{
int V_73 ;
bool V_91 = false ;
T_3 V_92 , V_93 ;
if ( ! V_51 -> V_72 )
V_91 = true ;
V_93 = V_51 -> V_58 + V_57 ;
V_92 = F_39 ( V_63 , V_93 ) ;
F_2 ( V_78 ,
L_11 ,
V_93 , V_51 -> V_41 . V_67 . V_84 , V_92 ,
V_63 -> V_81 -> V_82 -> V_94 . V_95 ,
V_91 ? L_12 : L_13 ) ;
if ( V_91 ) {
V_73 = F_40 ( V_63 -> V_81 -> V_82 ,
V_63 -> V_81 -> V_82 -> V_94 . V_95 ,
V_51 -> V_47 , V_92 ,
V_96 ) ;
V_51 -> V_73 = V_73 ;
V_51 -> V_47 += V_57 ;
} else
V_73 = F_41 ( V_63 -> V_81 -> V_82 ,
V_63 -> V_81 -> V_82 -> V_94 . V_95 ,
V_51 -> V_47 , V_92 ,
V_97 , V_51 ) ;
return V_73 ;
}
static int F_42 ( struct V_62 * V_63 ,
struct V_71 * V_98 , T_2 * V_52 ,
enum V_99 V_60 , unsigned int V_48 ,
int * V_100 )
{
* V_100 = ( V_48 > V_63 -> V_101 ) ?
F_43 ( V_48 , V_63 -> V_101 ) : 1 ;
F_2 ( V_6 , L_14 ,
* V_100 , V_98 -> V_76 . V_5 ) ;
if ( V_98 -> V_76 . V_5 < * V_100 ) {
if ( V_60 == V_16 )
return - V_102 ;
V_98 -> V_76 . V_40 = * V_100 - V_98 -> V_76 . V_5 ;
F_11 ( V_63 -> V_79 , & V_98 -> V_76 ) ;
V_98 -> V_76 . V_40 = 0 ;
if ( V_98 -> V_76 . V_5 < * V_100 ) {
F_2 ( V_6 ,
L_15 ,
V_60 ) ;
return - V_102 ;
}
}
V_98 -> V_76 . V_5 -= * V_100 ;
V_98 -> V_103 . V_104 += * V_100 ;
if ( V_98 -> V_76 . V_5 < V_98 -> V_76 . V_18 ) {
V_98 -> V_76 . V_40 =
V_98 -> V_76 . V_18 - V_98 -> V_76 . V_5 ;
F_11 ( V_63 -> V_79 , & V_98 -> V_76 ) ;
if ( V_98 -> V_76 . V_5 < V_98 -> V_76 . V_18 ) {
* V_52 |= V_105 ;
V_98 -> V_103 . V_106 += 1 ;
F_2 ( V_6 ,
L_16 ) ;
}
}
return 0 ;
}
static void F_44 ( struct V_62 * V_63 ,
struct V_71 * V_7 ,
struct V_10 * V_107 )
{
int V_100 ;
T_2 V_52 ;
struct V_50 * V_51 ;
unsigned int V_48 ;
while ( true ) {
V_52 = 0 ;
if ( F_26 ( & V_7 -> V_77 ) )
break;
V_51 = F_27 ( & V_7 -> V_77 , struct V_50 ,
V_26 ) ;
F_2 ( V_78 ,
L_17 ,
V_51 , F_31 ( & V_7 -> V_77 ) ) ;
V_48 = F_39 ( V_63 ,
V_51 -> V_58 + V_57 ) ;
if ( F_42 ( V_63 , V_7 , & V_52 ,
V_51 -> V_7 , V_48 , & V_100 ) )
break;
V_51 = F_27 ( & V_7 -> V_77 , struct V_50 ,
V_26 ) ;
F_45 ( & V_51 -> V_26 , V_107 ) ;
V_51 -> V_41 . V_67 . V_74 = V_100 ;
V_51 -> V_72 = F_34 ;
V_51 -> V_108 = V_63 ;
V_7 -> V_103 . V_109 += 1 ;
V_51 -> V_41 . V_67 . V_52 = V_52 ;
V_51 -> V_41 . V_67 . V_84 = V_7 -> V_84 ;
V_7 -> V_84 ++ ;
}
}
static int F_46 ( unsigned int V_110 , int * V_48 ,
struct V_71 * V_98 )
{
int V_111 , V_112 ;
V_111 = * V_48 % V_110 ;
if ( ! V_111 )
return 0 ;
if ( ! ( V_98 -> V_113 & V_114 ) )
return - 1 ;
V_112 = * V_48 < V_110 ? ( V_110 - * V_48 ) : V_111 ;
if ( ( V_112 > 0 ) && ( V_112 <= 255 ) )
* V_48 += V_112 ;
else
return - 1 ;
return V_112 ;
}
static int F_47 ( struct V_62 * V_63 ,
struct V_71 * V_7 ,
struct V_85 * V_86 ,
int V_115 ,
struct V_10 * V_107 )
{
struct V_50 * V_51 ;
int V_88 , V_48 , V_116 , V_112 ;
int V_73 = 0 ;
V_116 = V_63 -> V_117 ;
for ( V_88 = 0 ; V_88 < V_115 ; V_88 ++ ) {
V_86 -> V_90 [ V_88 ] . V_51 = NULL ;
if ( F_26 ( V_107 ) )
break;
V_51 = F_27 ( V_107 , struct V_50 , V_26 ) ;
V_48 = F_39 ( V_63 ,
V_51 -> V_58 + V_57 ) ;
V_112 = F_46 ( V_63 -> V_101 ,
& V_48 , V_7 ) ;
if ( V_112 < 0 || V_116 < V_48 ) {
V_73 = - V_118 ;
break;
}
V_116 -= V_48 ;
F_28 ( & V_51 -> V_26 ) ;
V_86 -> V_90 [ V_88 ] . V_51 = V_51 ;
F_19 ( V_51 ,
V_51 -> V_41 . V_67 . V_52 | V_119 ,
V_112 , V_51 -> V_41 . V_67 . V_84 ) ;
F_16 ( & V_51 -> V_47 ,
V_51 -> V_58 + V_57 ) ;
V_86 -> V_90 [ V_88 ] . V_47 = V_51 -> V_47 ;
V_86 -> V_90 [ V_88 ] . V_48 = V_48 ;
V_86 -> V_48 += V_48 ;
V_86 -> V_89 ++ ;
F_2 ( V_78 ,
L_18 ,
V_88 , V_51 , V_51 -> V_41 . V_67 . V_84 , V_48 , V_116 ) ;
}
if ( V_86 -> V_89 < V_120 ) {
for ( V_88 = V_86 -> V_89 - 1 ; V_88 >= 0 ; V_88 -- ) {
V_51 = V_86 -> V_90 [ V_88 ] . V_51 ;
if ( V_51 ) {
V_51 -> V_47 += V_57 ;
F_48 ( & V_51 -> V_26 , V_107 ) ;
}
}
return - V_121 ;
}
return V_73 ;
}
static void F_49 ( struct V_71 * V_7 ,
struct V_10 * V_107 ,
int * V_122 , int * V_123 )
{
struct V_62 * V_63 = V_7 -> V_63 ;
struct V_85 * V_86 = NULL ;
int V_115 , V_124 = 0 , V_125 = 0 ;
int V_73 ;
while ( true ) {
V_73 = 0 ;
V_115 = F_31 ( V_107 ) ;
V_115 = F_12 ( V_115 , V_63 -> V_126 ) ;
if ( V_115 < V_120 )
break;
V_86 = F_50 ( V_63 -> V_81 -> V_82 ) ;
if ( ! V_86 ) {
F_2 ( V_78 ,
L_19 ) ;
break;
}
F_2 ( V_78 , L_20 ,
V_115 ) ;
V_86 -> V_48 = 0 ;
V_86 -> V_89 = 0 ;
V_73 = F_47 ( V_63 , V_7 ,
V_86 , V_115 ,
V_107 ) ;
if ( V_73 == - V_121 ) {
F_37 ( V_63 -> V_81 -> V_82 , V_86 ) ;
break;
}
V_86 -> V_127 = F_36 ;
V_124 ++ ;
V_125 += V_86 -> V_89 ;
F_2 ( V_78 ,
L_21 ,
V_86 -> V_48 , V_86 -> V_89 ) ;
F_51 ( V_63 -> V_81 , V_86 , false ) ;
if ( V_73 )
break;
}
* V_122 = V_124 ;
* V_123 = V_125 ;
F_2 ( V_78 , L_22 ,
V_124 ) ;
return;
}
static void F_52 ( struct V_62 * V_63 ,
struct V_71 * V_7 )
{
struct V_10 V_77 ;
struct V_50 * V_51 ;
int V_128 ;
int V_129 ;
F_22 ( & V_63 -> V_75 ) ;
V_7 -> V_130 ++ ;
if ( V_7 -> V_130 > 1 ) {
V_7 -> V_130 -- ;
F_24 ( & V_63 -> V_75 ) ;
F_2 ( V_78 , L_23 ) ;
return;
}
F_35 ( & V_77 ) ;
while ( true ) {
if ( F_26 ( & V_7 -> V_77 ) )
break;
F_44 ( V_63 , V_7 , & V_77 ) ;
if ( F_26 ( & V_77 ) )
break;
F_24 ( & V_63 -> V_75 ) ;
V_128 = 0 ;
V_129 = 0 ;
while ( true ) {
if ( ( V_63 -> V_131 ) &&
( F_31 ( & V_77 ) >=
V_120 ) ) {
int V_132 = 0 , V_133 = 0 ;
F_49 ( V_7 , & V_77 ,
& V_132 , & V_133 ) ;
V_128 += V_132 ;
V_129 += V_133 ;
}
if ( F_26 ( & V_77 ) )
break;
V_51 = F_27 ( & V_77 , struct V_50 ,
V_26 ) ;
F_28 ( & V_51 -> V_26 ) ;
F_19 ( V_51 , V_51 -> V_41 . V_67 . V_52 ,
0 , V_51 -> V_41 . V_67 . V_84 ) ;
F_38 ( V_63 , V_51 ) ;
}
F_22 ( & V_63 -> V_75 ) ;
V_7 -> V_103 . V_134 += V_128 ;
V_7 -> V_103 . V_135 += V_129 ;
}
V_7 -> V_130 = 0 ;
F_24 ( & V_63 -> V_75 ) ;
}
static bool F_53 ( struct V_62 * V_63 ,
struct V_71 * V_7 ,
struct V_50 * V_136 )
{
struct V_137 V_138 ;
int V_36 ;
bool V_139 = false ;
V_138 = V_7 -> V_138 ;
F_22 ( & V_63 -> V_75 ) ;
V_36 = F_31 ( & V_7 -> V_77 ) ;
F_24 ( & V_63 -> V_75 ) ;
if ( V_36 >= V_7 -> V_140 )
V_139 = true ;
if ( V_139 )
F_2 ( V_78 ,
L_24 ,
V_7 -> V_60 , V_36 ,
V_7 -> V_140 ) ;
if ( V_139 && V_138 . V_141 ) {
if ( V_138 . V_141 ( V_7 -> V_63 , V_136 ) ==
V_142 ) {
V_7 -> V_103 . V_143 += 1 ;
return false ;
}
}
F_22 ( & V_63 -> V_75 ) ;
F_23 ( & V_136 -> V_26 , & V_7 -> V_77 ) ;
F_24 ( & V_63 -> V_75 ) ;
F_52 ( V_63 , V_7 ) ;
return true ;
}
static void F_54 ( struct V_62 * V_63 )
{
struct V_71 * V_7 ;
struct V_3 * V_76 ;
F_4 (cred_dist, &target->cred_dist_list, list) {
V_7 = V_76 -> V_144 ;
F_22 ( & V_63 -> V_75 ) ;
if ( ! F_26 ( & V_7 -> V_77 ) ) {
F_2 ( V_78 ,
L_25 ,
V_76 -> V_7 ,
V_7 -> V_76 . V_5 ,
F_31 ( & V_7 -> V_77 ) ) ;
F_24 ( & V_63 -> V_75 ) ;
F_52 ( V_63 , V_7 ) ;
F_22 ( & V_63 -> V_75 ) ;
}
F_24 ( & V_63 -> V_75 ) ;
}
}
static int F_55 ( struct V_62 * V_63 )
{
struct V_50 * V_145 = NULL ;
int V_73 ;
V_145 = F_25 ( V_63 , true ) ;
if ( ! V_145 )
return - V_146 ;
if ( V_63 -> V_147 >= V_148 ) {
struct V_149 * V_150 ;
T_3 V_52 = 0 ;
V_150 =
(struct V_149 * ) V_145 -> V_47 ;
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
V_150 -> V_151 =
F_56 ( V_152 ) ;
if ( V_63 -> V_126 > 0 ) {
V_52 |= V_153 ;
V_150 -> V_154 =
V_63 -> V_126 ;
}
memcpy ( & V_150 -> V_52 , & V_52 ,
sizeof( V_150 -> V_52 ) ) ;
F_57 ( V_145 , NULL , ( T_2 * ) V_150 ,
sizeof( struct V_149 ) ,
V_16 , V_155 ) ;
} else {
struct V_156 * V_157 ;
V_157 = (struct V_156 * ) V_145 -> V_47 ;
memset ( V_157 , 0 , sizeof( struct V_156 ) ) ;
V_157 -> V_151 = F_56 ( V_158 ) ;
F_57 ( V_145 , NULL , ( T_2 * ) V_157 ,
sizeof( struct V_156 ) ,
V_16 , V_155 ) ;
}
V_145 -> V_72 = NULL ;
F_19 ( V_145 , 0 , 0 , 0 ) ;
V_73 = F_38 ( V_63 , V_145 ) ;
if ( V_145 != NULL )
F_21 ( V_63 , V_145 ) ;
return V_73 ;
}
void F_8 ( struct V_62 * V_63 ,
struct V_1 * V_79 ,
T_1 V_159 [] , int V_160 )
{
struct V_71 * V_7 ;
int V_88 , V_98 ;
V_63 -> V_79 = V_79 ;
F_23 ( & V_63 -> V_7 [ V_16 ] . V_76 . V_26 ,
& V_63 -> V_80 ) ;
for ( V_88 = 0 ; V_88 < V_160 ; V_88 ++ ) {
for ( V_98 = V_161 ; V_98 < V_162 ; V_98 ++ ) {
V_7 = & V_63 -> V_7 [ V_98 ] ;
if ( V_7 -> V_19 == V_159 [ V_88 ] ) {
F_23 ( & V_7 -> V_76 . V_26 ,
& V_63 -> V_80 ) ;
break;
}
}
if ( V_98 >= V_162 ) {
F_5 ( 1 ) ;
return;
}
}
}
int F_58 ( struct V_62 * V_63 , struct V_50 * V_51 )
{
struct V_71 * V_7 ;
struct V_10 V_107 ;
F_2 ( V_78 ,
L_26 ,
V_51 -> V_7 , V_51 -> V_47 , V_51 -> V_58 ) ;
if ( V_51 -> V_7 >= V_162 ) {
F_5 ( 1 ) ;
return - V_102 ;
}
V_7 = & V_63 -> V_7 [ V_51 -> V_7 ] ;
if ( ! F_53 ( V_63 , V_7 , V_51 ) ) {
V_51 -> V_73 = ( V_63 -> V_163 & V_164 ) ?
- V_165 : - V_118 ;
F_35 ( & V_107 ) ;
F_48 ( & V_51 -> V_26 , & V_107 ) ;
F_32 ( V_7 , & V_107 ) ;
}
return 0 ;
}
void F_59 ( struct V_62 * V_63 ,
enum V_99 V_60 , T_1 V_166 )
{
struct V_50 * V_51 , * V_167 ;
struct V_10 V_168 , V_83 ;
struct V_71 * V_7 = & V_63 -> V_7 [ V_60 ] ;
if ( ! V_7 -> V_19 ) {
F_5 ( 1 ) ;
return;
}
F_35 ( & V_168 ) ;
F_22 ( & V_63 -> V_75 ) ;
F_60 (packet, tmp_pkt, &endpoint->txq, list) {
if ( ( V_166 == V_169 ) ||
( V_166 == V_51 -> V_41 . V_67 . V_166 ) )
F_45 ( & V_51 -> V_26 , & V_168 ) ;
}
F_24 ( & V_63 -> V_75 ) ;
F_60 (packet, tmp_pkt, &discard_q, list) {
V_51 -> V_73 = - V_165 ;
F_28 ( & V_51 -> V_26 ) ;
F_2 ( V_78 ,
L_27 ,
V_51 , V_51 -> V_58 ,
V_51 -> V_7 , V_51 -> V_41 . V_67 . V_166 ) ;
F_35 ( & V_83 ) ;
F_23 ( & V_51 -> V_26 , & V_83 ) ;
F_32 ( V_7 , & V_83 ) ;
}
}
static void F_61 ( struct V_62 * V_63 )
{
struct V_71 * V_7 ;
int V_88 ;
F_62 ( V_63 ) ;
for ( V_88 = V_16 ; V_88 < V_162 ; V_88 ++ ) {
V_7 = & V_63 -> V_7 [ V_88 ] ;
if ( V_7 -> V_19 == 0 )
continue;
F_59 ( V_63 , V_88 , V_169 ) ;
}
}
void F_63 ( struct V_62 * V_63 ,
enum V_99 V_60 , bool V_170 )
{
struct V_71 * V_7 = & V_63 -> V_7 [ V_60 ] ;
bool V_171 = false ;
if ( V_7 -> V_19 == 0 ) {
F_5 ( 1 ) ;
return;
}
F_22 ( & V_63 -> V_75 ) ;
if ( V_170 ) {
if ( ! ( V_7 -> V_76 . V_22 & V_23 ) ) {
V_7 -> V_76 . V_22 |= V_23 ;
V_171 = true ;
}
} else {
if ( V_7 -> V_76 . V_22 & V_23 ) {
V_7 -> V_76 . V_22 &= ~ V_23 ;
V_171 = true ;
}
}
if ( V_171 ) {
V_7 -> V_76 . V_36 =
F_31 ( & V_7 -> V_77 ) ;
F_2 ( V_78 ,
L_28 ,
V_63 -> V_79 , & V_63 -> V_80 ) ;
F_15 ( V_63 -> V_79 ,
& V_63 -> V_80 ,
V_46 ) ;
}
F_24 ( & V_63 -> V_75 ) ;
if ( V_171 && ! V_170 )
F_54 ( V_63 ) ;
}
static inline void F_64 ( struct V_71 * V_7 ,
int V_172 )
{
V_7 -> V_103 . V_173 ++ ;
if ( V_172 == 1 )
V_7 -> V_103 . V_174 ++ ;
else if ( V_172 > 1 )
V_7 -> V_103 . V_175 ++ ;
}
static inline bool F_65 ( struct V_62 * V_63 ,
enum V_99 V_60 , int V_48 )
{
return ( V_60 == V_63 -> V_81 -> V_82 -> V_176 ) ?
V_48 <= V_177 : V_48 <= V_178 ;
}
static int F_66 ( struct V_62 * V_63 , struct V_50 * V_51 )
{
struct V_10 V_107 ;
F_35 ( & V_107 ) ;
F_23 ( & V_51 -> V_26 , & V_107 ) ;
return F_67 ( V_63 , & V_107 ) ;
}
static void F_68 ( struct V_62 * V_63 ,
struct V_50 * V_51 ,
struct V_71 * V_98 )
{
if ( V_51 -> V_41 . V_179 . V_180 & V_181 ) {
F_69 ( V_51 ) ;
V_51 -> V_73 = - V_165 ;
V_98 -> V_138 . V_179 ( V_98 -> V_63 , V_51 ) ;
} else {
F_69 ( V_51 ) ;
F_66 ( ( void * ) ( V_63 ) , V_51 ) ;
}
}
static void F_70 ( struct V_62 * V_63 ,
struct V_50 * V_51 )
{
F_22 ( & V_63 -> V_65 ) ;
F_23 ( & V_51 -> V_26 , & V_63 -> V_69 ) ;
F_24 ( & V_63 -> V_65 ) ;
}
static int F_71 ( struct V_62 * V_63 ,
struct V_50 * V_51 ,
T_3 V_182 )
{
struct V_183 * V_81 = V_63 -> V_81 ;
T_3 V_92 ;
int V_73 ;
V_92 = F_39 ( V_63 , V_182 ) ;
if ( V_92 > V_51 -> V_184 ) {
F_30 ( L_29 ,
V_92 , V_182 , V_51 -> V_184 ) ;
return - V_146 ;
}
F_2 ( V_78 ,
L_30 ,
V_51 , V_51 -> V_41 . V_179 . V_185 ,
V_92 , V_81 -> V_82 -> V_94 . V_95 ) ;
V_73 = F_40 ( V_81 -> V_82 ,
V_81 -> V_82 -> V_94 . V_95 ,
V_51 -> V_47 , V_92 ,
V_186 ) ;
V_51 -> V_73 = V_73 ;
return V_73 ;
}
static void F_72 ( T_3 V_187 ,
struct V_71 * V_7 ,
struct V_50 * V_51 )
{
struct V_55 * V_188 = (struct V_55 * ) & V_187 ;
if ( V_188 -> V_60 == V_51 -> V_7 ) {
if ( ! F_26 ( & V_7 -> V_189 ) )
V_51 -> V_41 . V_179 . V_190 |=
V_191 ;
}
}
static void F_73 ( struct V_71 * V_7 )
{
struct V_137 V_138 = V_7 -> V_138 ;
if ( V_138 . V_192 > 0 ) {
F_22 ( & V_7 -> V_63 -> V_193 ) ;
if ( F_31 ( & V_7 -> V_189 )
< V_138 . V_192 ) {
F_24 ( & V_7 -> V_63 -> V_193 ) ;
V_138 . V_194 ( V_7 -> V_63 , V_7 -> V_60 ) ;
return;
}
F_24 ( & V_7 -> V_63 -> V_193 ) ;
}
}
static int F_74 ( struct V_62 * V_63 ,
struct V_71 * V_98 ,
T_3 * V_195 , struct V_10 * V_107 , int V_196 )
{
struct V_50 * V_51 ;
struct V_55 * V_188 = (struct V_55 * ) V_195 ;
struct V_137 V_138 ;
int V_73 = 0 , V_197 , V_198 ;
bool V_199 ;
V_198 = F_39 ( V_63 ,
F_75 ( V_188 -> V_59 ) +
sizeof( * V_188 ) ) ;
if ( ! F_65 ( V_63 , V_98 -> V_60 , V_198 ) ) {
F_76 ( L_31 ) ;
return - V_102 ;
}
V_138 = V_98 -> V_138 ;
for ( V_197 = 0 ; V_197 < V_196 ; V_197 ++ ) {
V_199 = false ;
if ( V_138 . V_200 &&
( V_198 > V_138 . V_201 ) ) {
V_98 -> V_103 . V_202 += 1 ;
V_98 -> V_103 . V_203 +=
F_75 ( V_188 -> V_59 ) ;
F_24 ( & V_63 -> V_193 ) ;
V_199 = true ;
V_51 = V_138 . V_200 ( V_98 -> V_63 , V_98 -> V_60 ,
V_198 ) ;
F_22 ( & V_63 -> V_193 ) ;
} else {
if ( F_26 ( & V_98 -> V_189 ) ) {
if ( V_138 . V_194 ) {
F_24 ( & V_63 -> V_193 ) ;
V_138 . V_194 ( V_98 -> V_63 , V_98 -> V_60 ) ;
F_22 ( & V_63 -> V_193 ) ;
}
}
if ( F_26 ( & V_98 -> V_189 ) )
V_51 = NULL ;
else {
V_51 = F_27 ( & V_98 -> V_189 ,
struct V_50 , V_26 ) ;
F_28 ( & V_51 -> V_26 ) ;
}
}
if ( ! V_51 ) {
V_63 -> V_204 |= V_205 ;
V_63 -> V_206 = V_98 -> V_60 ;
return - V_118 ;
}
V_51 -> V_41 . V_179 . V_180 = 0 ;
V_51 -> V_41 . V_179 . V_190 = 0 ;
V_51 -> V_73 = 0 ;
if ( V_199 )
V_51 -> V_41 . V_179 . V_180 |= V_181 ;
F_23 ( & V_51 -> V_26 , V_107 ) ;
if ( V_63 -> V_163 & V_164 ) {
V_73 = - V_165 ;
break;
}
if ( V_197 ) {
V_51 -> V_41 . V_179 . V_180 |= V_207 ;
V_51 -> V_41 . V_179 . V_185 = 0xFFFFFFFF ;
} else
V_51 -> V_41 . V_179 . V_185 = * V_195 ;
V_51 -> V_58 = F_75 ( V_188 -> V_59 ) +
V_57 ;
}
return V_73 ;
}
static int F_77 ( struct V_62 * V_63 ,
T_3 V_195 [] , int V_208 ,
struct V_71 * V_7 ,
struct V_10 * V_107 )
{
int V_73 = 0 ;
struct V_50 * V_51 , * V_167 ;
struct V_55 * V_188 ;
int V_88 , V_196 ;
F_22 ( & V_63 -> V_193 ) ;
for ( V_88 = 0 ; V_88 < V_208 ; V_88 ++ ) {
V_188 = (struct V_55 * ) & V_195 [ V_88 ] ;
if ( V_188 -> V_60 >= V_162 ) {
F_30 ( L_32 ,
V_188 -> V_60 ) ;
V_73 = - V_146 ;
break;
}
if ( V_188 -> V_60 != V_7 -> V_60 ) {
F_30 ( L_33 ,
V_188 -> V_60 , V_7 -> V_60 , V_88 ) ;
V_73 = - V_146 ;
break;
}
if ( F_75 ( V_188 -> V_59 ) > V_209 ) {
F_30 ( L_34 ,
V_188 -> V_59 ,
( T_3 ) V_209 ) ;
V_73 = - V_146 ;
break;
}
if ( V_7 -> V_19 == 0 ) {
F_30 ( L_35 , V_188 -> V_60 ) ;
V_73 = - V_146 ;
break;
}
if ( V_188 -> V_52 & V_210 ) {
V_196 = ( V_188 -> V_52 & V_210 ) >>
V_211 ;
V_196 ++ ;
if ( V_196 > V_63 -> V_126 ) {
V_73 = - V_146 ;
break;
}
V_7 -> V_103 . V_212 += 1 ;
F_2 ( V_78 ,
L_36 ,
V_196 ) ;
} else
V_196 = 1 ;
V_73 = F_74 ( V_63 , V_7 , & V_195 [ V_88 ] ,
V_107 , V_196 ) ;
if ( V_73 == - V_118 ) {
F_24 ( & V_63 -> V_193 ) ;
return 0 ;
}
if ( V_73 )
break;
}
F_24 ( & V_63 -> V_193 ) ;
if ( V_73 ) {
F_60 (packet, tmp_pkt, queue, list) {
F_28 ( & V_51 -> V_26 ) ;
F_68 ( V_63 , V_51 ,
& V_63 -> V_7 [ V_51 -> V_7 ] ) ;
}
}
return V_73 ;
}
static void F_78 ( struct V_62 * V_108 , struct V_50 * V_213 )
{
if ( V_213 -> V_7 != V_16 ) {
F_5 ( 1 ) ;
return;
}
if ( V_213 -> V_73 == - V_165 ) {
F_70 ( V_108 , V_213 ) ;
return;
}
if ( V_213 -> V_58 > 0 ) {
F_30 ( L_37 ,
V_213 -> V_58 + V_57 ) ;
F_79 ( V_78 ,
L_38 , L_39 ,
V_213 -> V_47 - V_57 ,
V_213 -> V_58 + V_57 ) ;
}
F_68 ( V_108 , V_213 , & V_108 -> V_7 [ 0 ] ) ;
}
static void F_80 ( struct V_62 * V_63 ,
struct V_214 * V_215 ,
int V_216 ,
enum V_99 V_217 )
{
struct V_71 * V_7 ;
int V_12 = 0 , V_88 ;
bool V_171 = false ;
F_22 ( & V_63 -> V_75 ) ;
for ( V_88 = 0 ; V_88 < V_216 ; V_88 ++ , V_215 ++ ) {
if ( V_215 -> V_60 >= V_162 ) {
F_5 ( 1 ) ;
F_24 ( & V_63 -> V_75 ) ;
return;
}
V_7 = & V_63 -> V_7 [ V_215 -> V_60 ] ;
F_2 ( V_6 ,
L_40 ,
V_215 -> V_60 , V_215 -> V_5 ) ;
V_7 -> V_103 . V_218 += 1 ;
V_7 -> V_103 . V_219 += V_215 -> V_5 ;
if ( V_217 == V_215 -> V_60 ) {
V_7 -> V_103 . V_220 += V_215 -> V_5 ;
V_7 -> V_103 . V_221 += 1 ;
} else if ( V_217 == V_16 ) {
V_7 -> V_103 . V_222 += V_215 -> V_5 ;
V_7 -> V_103 . V_223 += 1 ;
} else {
V_7 -> V_103 . V_224 += V_215 -> V_5 ;
V_7 -> V_103 . V_225 += 1 ;
}
if ( V_215 -> V_60 == V_16 )
V_7 -> V_76 . V_5 += V_215 -> V_5 ;
else {
V_7 -> V_76 . V_35 += V_215 -> V_5 ;
V_171 = true ;
}
V_7 -> V_76 . V_36 =
F_31 ( & V_7 -> V_77 ) ;
V_12 += V_215 -> V_5 ;
}
if ( V_171 ) {
F_15 ( V_63 -> V_79 ,
& V_63 -> V_80 ,
V_45 ) ;
}
F_24 ( & V_63 -> V_75 ) ;
if ( V_12 )
F_54 ( V_63 ) ;
}
static int F_81 ( struct V_62 * V_63 ,
struct V_226 * V_227 ,
T_2 * V_228 , T_3 * V_229 ,
enum V_99 V_7 ,
int * V_230 )
{
struct V_231 * V_232 ;
struct V_233 * V_187 ;
int V_48 ;
switch ( V_227 -> V_234 ) {
case V_235 :
V_48 = V_227 -> V_48 / sizeof( struct V_214 ) ;
if ( ! V_48 ) {
F_5 ( 1 ) ;
return - V_102 ;
}
F_80 ( V_63 ,
(struct V_214 * ) V_228 ,
V_48 , V_7 ) ;
break;
case V_236 :
V_48 = V_227 -> V_48 / sizeof( * V_187 ) ;
if ( ! V_48 ) {
F_5 ( 1 ) ;
return - V_102 ;
}
V_187 = (struct V_233 * ) V_228 ;
if ( ( V_187 -> V_237 == ( ( ~ V_187 -> V_238 ) & 0xFF ) )
&& V_229 ) {
F_2 ( V_78 ,
L_41 ,
V_187 -> V_237 , V_187 -> V_238 ) ;
memcpy ( ( T_2 * ) & V_229 [ 0 ] , V_187 -> V_187 , 4 ) ;
F_79 ( V_78 ,
L_42 ,
L_39 , V_229 , 4 ) ;
* V_230 = 1 ;
}
break;
case V_239 :
V_48 = V_227 -> V_48 / sizeof( * V_232 ) ;
if ( ! V_48 || ( V_48 > V_240 ) ) {
F_5 ( 1 ) ;
return - V_102 ;
}
if ( V_229 ) {
int V_88 ;
V_232 =
(struct V_231 * ) V_228 ;
F_79 ( V_78 , L_43 ,
L_39 , V_228 , V_227 -> V_48 ) ;
for ( V_88 = 0 ; V_88 < V_48 ; V_88 ++ ) {
memcpy ( ( T_2 * ) & V_229 [ V_88 ] ,
V_232 -> V_187 , 4 ) ;
V_232 ++ ;
}
* V_230 = V_88 ;
}
break;
default:
F_30 ( L_44 ,
V_227 -> V_234 , V_227 -> V_48 ) ;
break;
}
return 0 ;
}
static int F_82 ( struct V_62 * V_63 ,
T_2 * V_47 , int V_48 , T_3 * V_229 ,
int * V_230 , enum V_99 V_7 )
{
struct V_226 * V_227 ;
int V_241 ;
int V_73 ;
T_2 * V_228 ;
T_2 * V_242 ;
F_2 ( V_78 , L_45 , V_48 ) ;
F_79 ( V_78 , NULL , L_39 , V_47 , V_48 ) ;
V_242 = V_47 ;
V_241 = V_48 ;
V_73 = 0 ;
while ( V_48 > 0 ) {
if ( V_48 < sizeof( struct V_226 ) ) {
V_73 = - V_146 ;
break;
}
V_227 = (struct V_226 * ) V_47 ;
V_48 -= sizeof( struct V_226 ) ;
V_47 += sizeof( struct V_226 ) ;
if ( V_227 -> V_48 > V_48 ) {
F_30 ( L_46 ,
V_227 -> V_48 , V_227 -> V_234 , V_48 ) ;
V_73 = - V_146 ;
break;
}
V_228 = V_47 ;
V_73 = F_81 ( V_63 , V_227 , V_228 ,
V_229 , V_7 , V_230 ) ;
if ( V_73 )
break;
V_47 += V_227 -> V_48 ;
V_48 -= V_227 -> V_48 ;
}
if ( V_73 )
F_79 ( V_78 , L_47 ,
L_39 , V_242 , V_241 ) ;
return V_73 ;
}
static int F_83 ( struct V_62 * V_63 ,
struct V_50 * V_51 ,
T_3 * V_243 , int * V_244 )
{
int V_73 = 0 ;
T_1 V_245 ;
T_3 V_187 ;
struct V_55 * V_188 = (struct V_55 * ) V_51 -> V_47 ;
if ( V_244 != NULL )
* V_244 = 0 ;
V_245 = F_75 ( F_84 ( & V_188 -> V_59 ) ) ;
memcpy ( ( T_2 * ) & V_187 , V_51 -> V_47 , sizeof( V_187 ) ) ;
if ( V_51 -> V_41 . V_179 . V_180 & V_207 ) {
V_51 -> V_41 . V_179 . V_185 = V_187 ;
V_51 -> V_58 = V_245 + V_57 ;
if ( V_51 -> V_58 > V_51 -> V_184 ) {
F_30 ( L_48 ,
V_245 , V_187 ) ;
V_51 -> V_58 = F_12 ( V_51 -> V_58 , V_51 -> V_184 ) ;
V_73 = - V_146 ;
goto V_246;
}
if ( V_51 -> V_7 != V_188 -> V_60 ) {
F_30 ( L_49 ,
V_188 -> V_60 , V_51 -> V_7 ) ;
V_73 = - V_146 ;
goto V_246;
}
}
if ( V_187 != V_51 -> V_41 . V_179 . V_185 ) {
F_30 ( L_50 ,
V_247 , V_51 , V_51 -> V_41 . V_179 . V_180 ) ;
F_79 ( V_78 , L_51 ,
L_39 , & V_51 -> V_41 . V_179 . V_185 , 4 ) ;
F_79 ( V_78 , L_52 ,
L_39 , ( T_2 * ) & V_187 , sizeof( V_187 ) ) ;
V_73 = - V_146 ;
goto V_246;
}
if ( V_188 -> V_52 & V_248 ) {
if ( V_188 -> V_61 [ 0 ] < sizeof( struct V_226 ) ||
V_188 -> V_61 [ 0 ] > V_245 ) {
F_30 ( L_53 ,
V_247 , V_245 , V_188 -> V_61 [ 0 ] ) ;
V_73 = - V_146 ;
goto V_246;
}
if ( V_51 -> V_41 . V_179 . V_180 & V_249 ) {
V_243 = NULL ;
V_244 = NULL ;
}
V_73 = F_82 ( V_63 , V_51 -> V_47 + V_57
+ V_245 - V_188 -> V_61 [ 0 ] ,
V_188 -> V_61 [ 0 ] , V_243 ,
V_244 , V_51 -> V_7 ) ;
if ( V_73 )
goto V_246;
V_51 -> V_58 -= V_188 -> V_61 [ 0 ] ;
}
V_51 -> V_47 += V_57 ;
V_51 -> V_58 -= V_57 ;
V_246:
if ( V_73 )
F_79 ( V_78 , L_54 ,
L_39 , V_51 -> V_47 , V_51 -> V_58 ) ;
return V_73 ;
}
static void F_85 ( struct V_71 * V_7 ,
struct V_50 * V_51 )
{
F_2 ( V_78 ,
L_55 ,
V_7 -> V_60 , V_51 ) ;
V_7 -> V_138 . V_179 ( V_7 -> V_63 , V_51 ) ;
}
static int F_86 ( struct V_62 * V_63 ,
struct V_10 * V_250 ,
struct V_10 * V_251 ,
int * V_252 , bool V_253 )
{
struct V_85 * V_86 ;
struct V_50 * V_51 ;
int V_254 = V_63 -> V_255 ;
int V_256 , V_73 = 0 , V_88 , V_48 ;
V_256 = F_31 ( V_250 ) ;
V_256 = F_12 ( V_256 , V_63 -> V_126 ) ;
if ( ( F_31 ( V_250 ) - V_256 ) > 0 ) {
V_253 = true ;
F_76 ( L_56 ,
V_247 , F_31 ( V_250 ) , V_256 ) ;
}
V_48 = 0 ;
F_2 ( V_78 ,
L_57 ,
F_31 ( V_250 ) , V_256 ) ;
V_86 = F_50 ( V_63 -> V_81 -> V_82 ) ;
if ( V_86 == NULL )
goto V_257;
for ( V_88 = 0 ; V_88 < V_256 ; V_88 ++ ) {
int V_258 ;
V_51 = F_27 ( V_250 , struct V_50 , V_26 ) ;
F_28 ( & V_51 -> V_26 ) ;
V_258 = F_39 ( V_63 ,
V_51 -> V_58 ) ;
if ( ( V_254 - V_258 ) < 0 ) {
F_48 ( & V_51 -> V_26 , V_250 ) ;
break;
}
V_254 -= V_258 ;
if ( V_253 || ( V_88 < ( V_256 - 1 ) ) )
V_51 -> V_41 . V_179 . V_180 |=
V_249 ;
V_86 -> V_90 [ V_88 ] . V_47 = V_51 -> V_47 ;
V_86 -> V_90 [ V_88 ] . V_48 = V_258 ;
V_51 -> V_41 . V_179 . V_180 |= V_259 ;
F_23 ( & V_51 -> V_26 , V_251 ) ;
F_5 ( ! V_86 -> V_90 [ V_88 ] . V_48 ) ;
V_48 += V_86 -> V_90 [ V_88 ] . V_48 ;
}
V_86 -> V_48 = V_48 ;
V_86 -> V_89 = V_88 ;
V_73 = F_51 ( V_63 -> V_81 , V_86 , true ) ;
if ( ! V_73 )
* V_252 = V_88 ;
F_37 ( V_63 -> V_81 -> V_82 , V_86 ) ;
V_257:
return V_73 ;
}
static int F_87 ( struct V_62 * V_63 ,
struct V_10 * V_260 ,
T_3 V_195 [] ,
int * V_261 )
{
struct V_50 * V_51 , * V_167 ;
struct V_71 * V_98 ;
int V_73 = 0 ;
F_60 (packet, tmp_pkt, comp_pktq, list) {
V_98 = & V_63 -> V_7 [ V_51 -> V_7 ] ;
V_73 = F_83 ( V_63 , V_51 , V_195 ,
V_261 ) ;
if ( V_73 )
return V_73 ;
F_28 ( & V_51 -> V_26 ) ;
if ( F_26 ( V_260 ) ) {
if ( * V_261 > 0 )
F_72 ( V_195 [ 0 ] ,
V_98 , V_51 ) ;
} else
V_51 -> V_41 . V_179 . V_190 |=
V_191 ;
F_64 ( V_98 , * V_261 ) ;
if ( V_51 -> V_41 . V_179 . V_180 & V_259 )
V_98 -> V_103 . V_262 += 1 ;
F_85 ( V_98 , V_51 ) ;
}
return V_73 ;
}
static int F_88 ( struct V_62 * V_63 ,
struct V_10 * V_263 ,
struct V_10 * V_260 )
{
int V_264 ;
bool V_253 = false ;
int V_73 = 0 ;
struct V_10 V_265 ;
struct V_50 * V_51 , * V_167 ;
while ( ! F_26 ( V_263 ) ) {
V_264 = 0 ;
F_35 ( & V_265 ) ;
if ( V_63 -> V_266 && ( F_31 ( V_263 ) > 1 ) ) {
V_73 = F_86 ( V_63 , V_263 ,
& V_265 ,
& V_264 ,
V_253 ) ;
if ( V_73 )
goto V_246;
if ( ! F_26 ( V_263 ) )
V_253 = true ;
F_89 ( & V_265 , V_260 ) ;
}
if ( ! V_264 ) {
V_51 = F_27 ( V_263 , struct V_50 ,
V_26 ) ;
V_51 -> V_72 = NULL ;
if ( ! F_90 ( V_263 ) )
V_51 -> V_41 . V_179 . V_180 |=
V_249 ;
V_73 = F_71 ( V_63 , V_51 ,
V_51 -> V_58 ) ;
F_45 ( & V_51 -> V_26 , & V_265 ) ;
if ( V_73 )
goto V_246;
F_89 ( & V_265 , V_260 ) ;
}
}
return 0 ;
V_246:
F_60 (packet, tmp_pkt, rx_pktq, list) {
F_28 ( & V_51 -> V_26 ) ;
F_68 ( V_63 , V_51 ,
& V_63 -> V_7 [ V_51 -> V_7 ] ) ;
}
F_60 (packet, tmp_pkt, &tmp_rxq, list) {
F_28 ( & V_51 -> V_26 ) ;
F_68 ( V_63 , V_51 ,
& V_63 -> V_7 [ V_51 -> V_7 ] ) ;
}
return V_73 ;
}
int F_91 ( struct V_62 * V_63 ,
T_3 V_267 , int * V_268 )
{
struct V_50 * V_213 , * V_167 ;
struct V_71 * V_7 ;
struct V_10 V_263 , V_260 ;
int V_73 = 0 ;
T_3 V_269 [ V_240 ] ;
int V_270 = 1 ;
enum V_99 V_271 ;
int V_272 = 0 ;
* V_268 = 0 ;
V_269 [ 0 ] = V_267 ;
while ( true ) {
V_271 = ( (struct V_55 * ) & V_269 [ 0 ] ) -> V_60 ;
V_7 = & V_63 -> V_7 [ V_271 ] ;
if ( V_271 >= V_162 ) {
F_30 ( L_58 ,
V_271 ) ;
V_73 = - V_146 ;
break;
}
F_35 ( & V_263 ) ;
F_35 ( & V_260 ) ;
V_73 = F_77 ( V_63 , V_269 ,
V_270 , V_7 ,
& V_263 ) ;
if ( V_73 )
break;
if ( F_31 ( & V_263 ) >= 2 )
V_63 -> V_273 = 1 ;
V_272 += F_31 ( & V_263 ) ;
V_270 = 0 ;
V_73 = F_88 ( V_63 , & V_263 , & V_260 ) ;
if ( ! V_73 )
F_73 ( V_7 ) ;
V_73 = F_87 ( V_63 , & V_260 ,
V_269 ,
& V_270 ) ;
if ( ! V_270 || V_73 )
break;
V_63 -> V_273 = 1 ;
}
if ( V_73 ) {
F_30 ( L_59 ,
V_73 ) ;
F_60 (packets, tmp_pkt, &comp_pktq, list) {
F_28 ( & V_213 -> V_26 ) ;
F_68 ( V_63 , V_213 ,
& V_63 -> V_7 [ V_213 -> V_7 ] ) ;
}
if ( V_63 -> V_163 & V_164 ) {
F_76 ( L_60 ) ;
F_92 ( V_63 -> V_81 , false ) ;
}
}
if ( V_63 -> V_204 & V_205 ) {
F_76 ( L_61 ) ;
F_92 ( V_63 -> V_81 , false ) ;
}
* V_268 = V_272 ;
return V_73 ;
}
static struct V_50 * F_93 ( struct V_62 * V_63 )
{
struct V_50 * V_51 = NULL ;
struct V_55 * V_188 ;
T_3 V_274 ;
if ( F_94 ( V_63 -> V_81 , & V_274 ,
V_275 ) )
return NULL ;
F_2 ( V_78 ,
L_62 , V_274 ) ;
V_188 = (struct V_55 * ) & V_274 ;
if ( V_188 -> V_60 != V_16 )
return NULL ;
V_51 = F_25 ( V_63 , false ) ;
if ( ! V_51 )
return NULL ;
V_51 -> V_41 . V_179 . V_180 = 0 ;
V_51 -> V_41 . V_179 . V_185 = V_274 ;
V_51 -> V_58 = F_75 ( V_188 -> V_59 ) + V_57 ;
if ( V_51 -> V_58 > V_51 -> V_184 )
goto V_276;
V_51 -> V_72 = NULL ;
if ( F_71 ( V_63 , V_51 , V_51 -> V_58 ) )
goto V_276;
V_51 -> V_73 = F_83 ( V_63 , V_51 , NULL , NULL ) ;
if ( V_51 -> V_73 ) {
F_30 ( L_63 ,
V_51 -> V_73 ) ;
goto V_276;
}
return V_51 ;
V_276:
if ( V_51 != NULL ) {
F_69 ( V_51 ) ;
F_70 ( V_63 , V_51 ) ;
}
return NULL ;
}
int F_67 ( struct V_62 * V_63 ,
struct V_10 * V_277 )
{
struct V_71 * V_7 ;
struct V_50 * V_278 ;
bool V_279 = false ;
int V_73 = 0 , V_280 ;
if ( F_26 ( V_277 ) )
return - V_146 ;
V_278 = F_27 ( V_277 , struct V_50 , V_26 ) ;
if ( V_278 -> V_7 >= V_162 )
return V_73 ;
V_280 = F_31 ( V_277 ) ;
F_2 ( V_78 ,
L_64 ,
V_278 -> V_7 , V_280 , V_278 -> V_184 ) ;
V_7 = & V_63 -> V_7 [ V_278 -> V_7 ] ;
if ( V_63 -> V_163 & V_164 ) {
struct V_50 * V_51 , * V_167 ;
F_60 (packet, tmp_pkt, pkt_queue, list) {
V_51 -> V_73 = - V_165 ;
F_28 ( & V_51 -> V_26 ) ;
F_85 ( V_7 , V_51 ) ;
}
return V_73 ;
}
F_22 ( & V_63 -> V_193 ) ;
F_89 ( V_277 , & V_7 -> V_189 ) ;
if ( V_63 -> V_204 & V_205 ) {
if ( V_63 -> V_206 == V_278 -> V_7 ) {
F_2 ( V_78 ,
L_65 ,
V_63 -> V_206 ) ;
V_63 -> V_204 &= ~ V_205 ;
V_63 -> V_206 = V_162 ;
V_279 = true ;
}
}
F_24 ( & V_63 -> V_193 ) ;
if ( V_279 && ! ( V_63 -> V_163 & V_164 ) )
F_92 ( V_63 -> V_81 , true ) ;
return V_73 ;
}
void F_95 ( struct V_62 * V_63 )
{
struct V_71 * V_7 ;
struct V_50 * V_51 , * V_167 ;
int V_88 ;
for ( V_88 = V_16 ; V_88 < V_162 ; V_88 ++ ) {
V_7 = & V_63 -> V_7 [ V_88 ] ;
if ( ! V_7 -> V_19 )
continue;
F_22 ( & V_63 -> V_193 ) ;
F_60 (packet, tmp_pkt,
&endpoint->rx_bufq, list) {
F_28 ( & V_51 -> V_26 ) ;
F_24 ( & V_63 -> V_193 ) ;
F_2 ( V_78 ,
L_66 ,
V_51 , V_51 -> V_184 ,
V_51 -> V_7 ) ;
F_96 ( V_51 -> V_281 ) ;
F_22 ( & V_63 -> V_193 ) ;
}
F_24 ( & V_63 -> V_193 ) ;
}
}
int F_97 ( struct V_62 * V_63 ,
struct V_282 * V_283 ,
struct V_284 * V_285 )
{
struct V_50 * V_286 = NULL ;
struct V_50 * V_136 = NULL ;
struct V_287 * V_288 ;
struct V_289 * V_290 ;
struct V_71 * V_7 ;
enum V_99 V_291 = V_162 ;
unsigned int V_292 = 0 ;
int V_73 = 0 ;
F_2 ( V_78 ,
L_67 ,
V_63 , V_283 -> V_19 ) ;
if ( V_283 -> V_19 == V_293 ) {
V_291 = V_16 ;
V_292 = V_294 ;
} else {
V_136 = F_25 ( V_63 , true ) ;
if ( ! V_136 )
return - V_146 ;
V_290 = (struct V_289 * ) V_136 -> V_47 ;
memset ( V_290 , 0 , sizeof( * V_290 ) ) ;
V_290 -> V_151 = F_56 ( V_295 ) ;
V_290 -> V_19 = F_56 ( V_283 -> V_19 ) ;
V_290 -> V_113 = F_56 ( V_283 -> V_113 ) ;
F_57 ( V_136 , NULL , ( T_2 * ) V_290 ,
sizeof( * V_290 ) + V_290 -> V_296 ,
V_16 , V_155 ) ;
V_136 -> V_72 = NULL ;
F_19 ( V_136 , 0 , 0 , 0 ) ;
V_73 = F_38 ( V_63 , V_136 ) ;
if ( V_73 )
goto V_297;
V_286 = F_93 ( V_63 ) ;
if ( ! V_286 ) {
V_73 = - V_146 ;
goto V_297;
}
V_288 = (struct V_287 * ) V_286 -> V_47 ;
if ( ( F_75 ( V_288 -> V_151 ) != V_298 )
|| ( V_286 -> V_58 < sizeof( * V_288 ) ) ) {
V_73 = - V_146 ;
goto V_297;
}
V_285 -> V_299 = V_288 -> V_73 ;
if ( V_288 -> V_73 != V_300 ) {
F_30 ( L_68 ,
V_288 -> V_19 , V_288 -> V_73 ) ;
V_73 = - V_146 ;
goto V_297;
}
V_291 = (enum V_99 ) V_288 -> V_60 ;
V_292 = F_75 ( V_288 -> V_292 ) ;
}
if ( V_291 >= V_162 || ! V_292 ) {
V_73 = - V_146 ;
goto V_297;
}
V_7 = & V_63 -> V_7 [ V_291 ] ;
V_7 -> V_60 = V_291 ;
if ( V_7 -> V_19 ) {
V_73 = - V_146 ;
goto V_297;
}
V_285 -> V_7 = V_291 ;
V_285 -> V_301 = V_292 ;
V_7 -> V_19 = V_283 -> V_19 ;
V_7 -> V_140 = V_283 -> V_140 ;
V_7 -> V_301 = V_292 ;
V_7 -> V_138 = V_283 -> V_138 ;
V_7 -> V_76 . V_19 = V_283 -> V_19 ;
V_7 -> V_76 . V_144 = V_7 ;
V_7 -> V_76 . V_7 = V_291 ;
V_7 -> V_76 . V_110 = V_63 -> V_101 ;
if ( V_283 -> V_302 ) {
if ( V_283 -> V_302 > V_292 ) {
V_73 = - V_146 ;
goto V_297;
}
V_7 -> V_76 . V_18 =
V_283 -> V_302 / V_63 -> V_101 ;
} else
V_7 -> V_76 . V_18 =
V_292 / V_63 -> V_101 ;
if ( ! V_7 -> V_76 . V_18 )
V_7 -> V_76 . V_18 = 1 ;
V_7 -> V_113 = V_283 -> V_52 ;
V_297:
if ( V_136 )
F_21 ( V_63 , V_136 ) ;
if ( V_286 ) {
F_69 ( V_286 ) ;
F_70 ( V_63 , V_286 ) ;
}
return V_73 ;
}
static void F_98 ( struct V_62 * V_63 )
{
struct V_71 * V_7 ;
int V_88 ;
for ( V_88 = V_16 ; V_88 < V_162 ; V_88 ++ ) {
V_7 = & V_63 -> V_7 [ V_88 ] ;
memset ( & V_7 -> V_76 , 0 , sizeof( V_7 -> V_76 ) ) ;
V_7 -> V_19 = 0 ;
V_7 -> V_301 = 0 ;
V_7 -> V_140 = 0 ;
memset ( & V_7 -> V_103 , 0 ,
sizeof( V_7 -> V_103 ) ) ;
F_35 ( & V_7 -> V_189 ) ;
F_35 ( & V_7 -> V_77 ) ;
V_7 -> V_63 = V_63 ;
}
F_35 ( & V_63 -> V_80 ) ;
}
int F_99 ( struct V_62 * V_63 ,
enum V_99 V_7 )
{
int V_303 ;
F_22 ( & V_63 -> V_193 ) ;
V_303 = F_31 ( & ( V_63 -> V_7 [ V_7 ] . V_189 ) ) ;
F_24 ( & V_63 -> V_193 ) ;
return V_303 ;
}
static void F_100 ( struct V_62 * V_63 )
{
V_63 -> V_126 = F_12 ( V_240 ,
V_63 -> V_126 ) ;
if ( F_101 ( V_63 -> V_81 -> V_82 ) ) {
V_63 -> V_126 = 0 ;
return;
}
V_63 -> V_126 = F_12 ( V_63 -> V_304 ,
V_63 -> V_126 ) ;
F_2 ( V_305 ,
L_69 ,
V_63 -> V_126 ) ;
V_63 -> V_255 = V_63 -> V_306 ;
V_63 -> V_117 = F_12 ( V_307 ,
V_63 -> V_306 ) ;
F_2 ( V_305 , L_70 ,
V_63 -> V_255 , V_63 -> V_117 ) ;
if ( V_63 -> V_117 )
V_63 -> V_131 = true ;
if ( V_63 -> V_255 )
V_63 -> V_266 = true ;
if ( ( V_63 -> V_101 % V_63 -> V_308 ) != 0 ) {
F_76 ( L_71 ,
V_63 -> V_101 ) ;
V_63 -> V_131 = false ;
}
}
int F_102 ( struct V_62 * V_63 )
{
struct V_50 * V_51 = NULL ;
struct V_309 * V_310 ;
struct V_282 V_311 ;
struct V_284 V_312 ;
int V_73 ;
V_51 = F_93 ( V_63 ) ;
if ( ! V_51 )
return - V_146 ;
V_310 = (struct V_309 * ) V_51 -> V_47 ;
if ( ( F_75 ( V_310 -> V_313 . V_151 ) != V_314 ) ||
( V_51 -> V_58 < sizeof( struct V_315 ) ) ) {
V_73 = - V_146 ;
goto V_316;
}
if ( ! V_310 -> V_313 . V_317 || ! V_310 -> V_313 . V_110 ) {
V_73 = - V_146 ;
goto V_316;
}
V_63 -> V_318 = F_75 ( V_310 -> V_313 . V_317 ) ;
V_63 -> V_101 = F_75 ( V_310 -> V_313 . V_110 ) ;
F_2 ( V_305 ,
L_72 ,
V_63 -> V_318 , V_63 -> V_101 ) ;
if ( V_51 -> V_58 >= sizeof( struct V_309 ) ) {
V_63 -> V_147 = V_310 -> V_319 ;
V_63 -> V_126 = V_310 -> V_320 ;
} else {
V_63 -> V_147 = V_321 ;
V_63 -> V_126 = 0 ;
}
F_2 ( V_305 , L_73 ,
( V_63 -> V_147 == V_321 ) ? L_74 : L_75 ,
V_63 -> V_147 ) ;
if ( V_63 -> V_126 > 0 )
F_100 ( V_63 ) ;
memset ( & V_311 , 0 , sizeof( V_311 ) ) ;
memset ( & V_312 , 0 , sizeof( V_312 ) ) ;
V_311 . V_138 . V_179 = F_78 ;
V_311 . V_138 . V_194 = NULL ;
V_311 . V_138 . V_141 = NULL ;
V_311 . V_140 = V_322 ;
V_311 . V_19 = V_293 ;
V_73 = F_97 ( ( void * ) V_63 , & V_311 , & V_312 ) ;
if ( V_73 )
F_103 ( V_63 -> V_81 -> V_82 ) ;
V_316:
if ( V_51 ) {
F_69 ( V_51 ) ;
F_70 ( V_63 , V_51 ) ;
}
return V_73 ;
}
int F_104 ( struct V_62 * V_63 )
{
struct V_50 * V_51 ;
int V_73 ;
memset ( & V_63 -> V_81 -> V_323 , 0 ,
sizeof( V_63 -> V_81 -> V_323 ) ) ;
F_105 ( V_63 -> V_81 ) ;
V_63 -> V_163 = 0 ;
V_63 -> V_204 = 0 ;
while ( ( V_51 = F_25 ( V_63 , false ) ) != NULL ) {
V_73 = F_66 ( V_63 , V_51 ) ;
if ( V_73 )
return V_73 ;
}
F_3 ( V_63 -> V_79 , & V_63 -> V_80 ,
V_63 -> V_318 ) ;
F_62 ( V_63 ) ;
V_73 = F_55 ( V_63 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_106 ( V_63 -> V_81 ) ;
if ( V_73 )
F_107 ( V_63 ) ;
return V_73 ;
}
static int F_108 ( struct V_62 * V_63 )
{
T_3 V_324 , V_325 ;
struct V_50 * V_51 ;
int V_88 ;
F_98 ( V_63 ) ;
V_324 = V_63 -> V_81 -> V_82 -> V_94 . V_324 ;
V_325 = ( V_324 > V_294 ) ?
( V_324 + V_57 ) :
( V_294 + V_57 ) ;
for ( V_88 = 0 ; V_88 < V_322 ; V_88 ++ ) {
V_51 = F_109 ( sizeof( * V_51 ) , V_326 ) ;
if ( ! V_51 )
return - V_146 ;
V_51 -> V_70 = F_109 ( V_325 , V_326 ) ;
if ( ! V_51 -> V_70 ) {
F_110 ( V_51 ) ;
return - V_146 ;
}
V_51 -> V_184 = V_325 ;
if ( V_88 < V_327 ) {
V_51 -> V_58 = 0 ;
V_51 -> V_47 = V_51 -> V_70 ;
V_51 -> V_7 = V_16 ;
F_23 ( & V_51 -> V_26 , & V_63 -> V_69 ) ;
} else
F_23 ( & V_51 -> V_26 , & V_63 -> V_66 ) ;
}
return 0 ;
}
void F_107 ( struct V_62 * V_63 )
{
F_22 ( & V_63 -> V_65 ) ;
V_63 -> V_163 |= V_164 ;
F_24 ( & V_63 -> V_65 ) ;
F_111 ( V_63 -> V_81 ) ;
F_61 ( V_63 ) ;
F_95 ( V_63 ) ;
F_108 ( V_63 ) ;
}
void * F_112 ( struct V_328 * V_82 )
{
struct V_62 * V_63 = NULL ;
int V_73 = 0 ;
V_63 = F_109 ( sizeof( * V_63 ) , V_326 ) ;
if ( ! V_63 ) {
F_30 ( L_76 ) ;
return NULL ;
}
V_63 -> V_81 = F_109 ( sizeof( * V_63 -> V_81 ) , V_326 ) ;
if ( ! V_63 -> V_81 ) {
F_30 ( L_76 ) ;
V_73 = - V_146 ;
goto V_329;
}
F_113 ( & V_63 -> V_65 ) ;
F_113 ( & V_63 -> V_193 ) ;
F_113 ( & V_63 -> V_75 ) ;
F_35 ( & V_63 -> V_66 ) ;
F_35 ( & V_63 -> V_69 ) ;
F_35 ( & V_63 -> V_80 ) ;
V_63 -> V_81 -> V_82 = V_82 ;
V_63 -> V_81 -> V_330 = V_63 ;
V_63 -> V_206 = V_162 ;
V_73 = F_114 ( V_63 -> V_81 ) ;
if ( V_73 )
goto V_329;
V_73 = F_108 ( V_63 ) ;
if ( V_73 )
goto V_329;
return V_63 ;
V_329:
F_115 ( V_63 ) ;
return NULL ;
}
void F_115 ( struct V_62 * V_63 )
{
struct V_50 * V_51 , * V_331 ;
F_103 ( V_63 -> V_81 -> V_82 ) ;
F_60 (packet, tmp_packet,
&target->free_ctrl_txbuf, list) {
F_28 ( & V_51 -> V_26 ) ;
F_110 ( V_51 -> V_70 ) ;
F_110 ( V_51 ) ;
}
F_60 (packet, tmp_packet,
&target->free_ctrl_rxbuf, list) {
F_28 ( & V_51 -> V_26 ) ;
F_110 ( V_51 -> V_70 ) ;
F_110 ( V_51 ) ;
}
F_110 ( V_63 -> V_81 ) ;
F_110 ( V_63 ) ;
}
