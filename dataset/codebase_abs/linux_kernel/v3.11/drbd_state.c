static inline bool F_1 ( union V_1 V_2 )
{
return V_2 . V_3 || V_2 . V_4 || V_2 . V_5 ;
}
bool F_2 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
bool V_10 = true ;
int V_11 ;
F_3 () ;
F_4 (&tconn->volumes, mdev, vnr) {
if ( V_9 -> V_12 . V_13 != V_14 ||
V_9 -> V_12 . V_15 != V_16 ||
V_9 -> V_12 . V_17 != V_18 ) {
V_10 = false ;
break;
}
}
F_5 () ;
return V_10 ;
}
static enum V_19 F_6 ( enum V_19 V_20 , enum V_19 V_21 )
{
if ( V_20 == V_22 || V_21 == V_22 )
return V_22 ;
if ( V_20 == V_18 || V_21 == V_18 )
return V_18 ;
return V_23 ;
}
static enum V_19 F_7 ( enum V_19 V_20 , enum V_19 V_21 )
{
if ( V_20 == V_23 || V_21 == V_23 )
return V_23 ;
if ( V_20 == V_18 || V_21 == V_18 )
return V_18 ;
return V_22 ;
}
enum V_19 F_8 ( struct V_6 * V_7 )
{
enum V_19 V_17 = V_23 ;
struct V_8 * V_9 ;
int V_11 ;
F_3 () ;
F_4 (&tconn->volumes, mdev, vnr)
V_17 = F_6 ( V_17 , V_9 -> V_12 . V_17 ) ;
F_5 () ;
return V_17 ;
}
enum V_19 F_9 ( struct V_6 * V_7 )
{
enum V_19 V_24 = V_23 ;
struct V_8 * V_9 ;
int V_11 ;
F_3 () ;
F_4 (&tconn->volumes, mdev, vnr)
V_24 = F_6 ( V_24 , V_9 -> V_12 . V_24 ) ;
F_5 () ;
return V_24 ;
}
enum V_25 F_10 ( struct V_6 * V_7 )
{
enum V_25 V_26 = V_14 ;
struct V_8 * V_9 ;
int V_11 ;
F_3 () ;
F_4 (&tconn->volumes, mdev, vnr)
V_26 = F_11 ( enum V_25 , V_26 , V_9 -> V_12 . V_13 ) ;
F_5 () ;
return V_26 ;
}
enum V_25 F_12 ( struct V_6 * V_7 )
{
enum V_25 V_26 = V_27 ;
struct V_8 * V_9 ;
int V_11 ;
F_3 () ;
F_4 (&tconn->volumes, mdev, vnr)
V_26 = F_13 ( enum V_25 , V_26 , V_9 -> V_12 . V_13 ) ;
F_5 () ;
return V_26 ;
}
enum V_25 F_14 ( struct V_6 * V_7 )
{
enum V_25 V_26 = V_14 ;
struct V_8 * V_9 ;
int V_11 ;
F_3 () ;
F_4 (&tconn->volumes, mdev, vnr)
V_26 = F_11 ( enum V_25 , V_26 , V_9 -> V_12 . V_28 ) ;
F_5 () ;
return V_26 ;
}
enum V_29 F_15 ( struct V_6 * V_7 )
{
enum V_29 V_15 = V_30 ;
struct V_8 * V_9 ;
int V_11 ;
F_3 () ;
F_4 (&tconn->volumes, mdev, vnr)
V_15 = F_13 ( enum V_29 , V_15 , V_9 -> V_12 . V_15 ) ;
F_5 () ;
return V_15 ;
}
static bool F_16 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_11 ;
bool V_10 = true ;
F_3 () ;
F_4 (&tconn->volumes, mdev, vnr)
if ( V_9 -> V_12 . V_15 == V_31 ) {
V_10 = false ;
break;
}
F_5 () ;
return V_10 ;
}
static int F_17 ( struct V_8 * V_9 ,
union V_1 V_32 , union V_1 V_33 )
{
return ( V_32 . V_15 >= V_34 && V_33 . V_15 >= V_34 &&
( ( V_32 . V_17 != V_22 && V_33 . V_17 == V_22 ) ||
( V_32 . V_15 != V_35 && V_33 . V_15 == V_35 ) ||
( V_32 . V_15 != V_36 && V_33 . V_15 == V_36 ) ||
( V_32 . V_13 != V_37 && V_33 . V_13 == V_37 ) ) ) ||
( V_32 . V_15 >= V_34 && V_33 . V_15 == V_38 ) ||
( V_32 . V_15 == V_34 && V_33 . V_15 == V_39 ) ||
( V_32 . V_15 == V_34 && V_33 . V_15 == V_31 ) ;
}
static union V_1
F_18 ( union V_1 V_32 , union V_1 V_40 , union V_1 V_41 )
{
union V_1 V_33 ;
V_33 . V_42 = ( V_32 . V_42 & ~ V_40 . V_42 ) | V_41 . V_42 ;
return V_33 ;
}
enum V_43
F_19 ( struct V_8 * V_9 , enum V_44 V_45 ,
union V_1 V_40 , union V_1 V_41 )
{
unsigned long V_46 ;
union V_1 V_33 ;
enum V_43 V_10 ;
F_20 ( & V_9 -> V_7 -> V_47 , V_46 ) ;
V_33 = F_18 ( F_21 ( V_9 ) , V_40 , V_41 ) ;
V_10 = F_22 ( V_9 , V_33 , V_45 , NULL ) ;
F_23 ( & V_9 -> V_7 -> V_47 , V_46 ) ;
return V_10 ;
}
void F_24 ( struct V_8 * V_9 ,
union V_1 V_40 , union V_1 V_41 )
{
F_19 ( V_9 , V_48 , V_40 , V_41 ) ;
}
static enum V_43
F_25 ( struct V_8 * V_9 , union V_1 V_40 ,
union V_1 V_41 )
{
union V_1 V_32 , V_33 ;
unsigned long V_46 ;
enum V_43 V_10 ;
if ( F_26 ( V_49 , & V_9 -> V_46 ) )
return V_50 ;
if ( F_26 ( V_51 , & V_9 -> V_46 ) )
return V_52 ;
F_20 ( & V_9 -> V_7 -> V_47 , V_46 ) ;
V_32 = F_21 ( V_9 ) ;
V_33 = F_27 ( V_9 , F_18 ( V_32 , V_40 , V_41 ) , NULL ) ;
V_10 = F_28 ( V_32 , V_33 ) ;
if ( V_10 >= V_53 )
V_10 = V_54 ;
if ( ! F_17 ( V_9 , V_32 , V_33 ) )
V_10 = V_55 ;
if ( V_10 == V_54 ) {
V_10 = F_29 ( V_9 , V_33 ) ;
if ( V_10 >= V_53 ) {
V_10 = F_30 ( V_32 , V_33 , V_9 -> V_7 ) ;
if ( V_10 >= V_53 )
V_10 = V_54 ;
}
}
F_23 ( & V_9 -> V_7 -> V_47 , V_46 ) ;
return V_10 ;
}
static enum V_43
F_31 ( struct V_8 * V_9 , union V_1 V_40 ,
union V_1 V_41 , enum V_44 V_45 )
{
struct V_56 V_57 ;
unsigned long V_46 ;
union V_1 V_32 , V_33 ;
enum V_43 V_10 ;
F_32 ( & V_57 ) ;
if ( V_45 & V_58 )
F_33 ( V_9 -> V_59 ) ;
F_20 ( & V_9 -> V_7 -> V_47 , V_46 ) ;
V_32 = F_21 ( V_9 ) ;
V_33 = F_27 ( V_9 , F_18 ( V_32 , V_40 , V_41 ) , NULL ) ;
V_10 = F_28 ( V_32 , V_33 ) ;
if ( V_10 < V_53 ) {
F_23 ( & V_9 -> V_7 -> V_47 , V_46 ) ;
goto abort;
}
if ( F_17 ( V_9 , V_32 , V_33 ) ) {
V_10 = F_29 ( V_9 , V_33 ) ;
if ( V_10 == V_53 )
V_10 = F_30 ( V_32 , V_33 , V_9 -> V_7 ) ;
F_23 ( & V_9 -> V_7 -> V_47 , V_46 ) ;
if ( V_10 < V_53 ) {
if ( V_45 & V_60 )
F_34 ( V_9 , V_32 , V_33 , V_10 ) ;
goto abort;
}
if ( F_35 ( V_9 , V_40 , V_41 ) ) {
V_10 = V_52 ;
if ( V_45 & V_60 )
F_34 ( V_9 , V_32 , V_33 , V_10 ) ;
goto abort;
}
F_36 ( V_9 -> V_61 ,
( V_10 = F_25 ( V_9 , V_40 , V_41 ) ) ) ;
if ( V_10 < V_53 ) {
if ( V_45 & V_60 )
F_34 ( V_9 , V_32 , V_33 , V_10 ) ;
goto abort;
}
F_20 ( & V_9 -> V_7 -> V_47 , V_46 ) ;
V_33 = F_18 ( F_21 ( V_9 ) , V_40 , V_41 ) ;
V_10 = F_22 ( V_9 , V_33 , V_45 , & V_57 ) ;
} else {
V_10 = F_22 ( V_9 , V_33 , V_45 , & V_57 ) ;
}
F_23 ( & V_9 -> V_7 -> V_47 , V_46 ) ;
if ( V_45 & V_62 && V_10 == V_53 ) {
F_37 ( V_63 != V_9 -> V_7 -> V_64 . V_65 ) ;
F_38 ( & V_57 ) ;
}
abort:
if ( V_45 & V_58 )
F_39 ( V_9 -> V_59 ) ;
return V_10 ;
}
enum V_43
F_40 ( struct V_8 * V_9 , union V_1 V_40 ,
union V_1 V_41 , enum V_44 V_45 )
{
enum V_43 V_10 ;
F_36 ( V_9 -> V_61 ,
( V_10 = F_31 ( V_9 , V_40 , V_41 , V_45 ) ) != V_66 ) ;
return V_10 ;
}
static void F_41 ( struct V_8 * V_9 , char * V_67 , union V_1 V_33 )
{
F_42 ( V_68 , L_1 ,
V_67 ,
F_43 ( V_33 . V_15 ) ,
F_44 ( V_33 . V_17 ) ,
F_44 ( V_33 . V_24 ) ,
F_45 ( V_33 . V_13 ) ,
F_45 ( V_33 . V_28 ) ,
F_1 ( V_33 ) ? 's' : 'r' ,
V_33 . V_69 ? 'a' : '-' ,
V_33 . V_70 ? 'p' : '-' ,
V_33 . V_71 ? 'u' : '-' ,
V_33 . V_5 ? 'F' : '-' ,
V_33 . V_4 ? 'N' : '-'
) ;
}
void F_34 ( struct V_8 * V_9 , union V_1 V_32 ,
union V_1 V_33 , enum V_43 V_72 )
{
if ( V_72 == V_66 )
return;
F_42 ( V_68 , L_2 , F_46 ( V_72 ) ) ;
F_41 ( V_9 , L_3 , V_32 ) ;
F_41 ( V_9 , L_4 , V_33 ) ;
}
static long F_47 ( char * V_73 , union V_1 V_32 , union V_1 V_33 ,
enum V_44 V_46 )
{
char * V_74 ;
V_74 = V_73 ;
* V_74 = 0 ;
if ( V_33 . V_17 != V_32 . V_17 && V_46 & V_75 )
V_74 += sprintf ( V_74 , L_5 ,
F_44 ( V_32 . V_17 ) ,
F_44 ( V_33 . V_17 ) ) ;
if ( V_33 . V_24 != V_32 . V_24 && V_46 & V_76 )
V_74 += sprintf ( V_74 , L_6 ,
F_44 ( V_32 . V_24 ) ,
F_44 ( V_33 . V_24 ) ) ;
if ( V_33 . V_15 != V_32 . V_15 && V_46 & V_77 )
V_74 += sprintf ( V_74 , L_7 ,
F_43 ( V_32 . V_15 ) ,
F_43 ( V_33 . V_15 ) ) ;
if ( V_33 . V_13 != V_32 . V_13 && V_46 & V_78 )
V_74 += sprintf ( V_74 , L_8 ,
F_45 ( V_32 . V_13 ) ,
F_45 ( V_33 . V_13 ) ) ;
if ( V_33 . V_28 != V_32 . V_28 && V_46 & V_79 )
V_74 += sprintf ( V_74 , L_9 ,
F_45 ( V_32 . V_28 ) ,
F_45 ( V_33 . V_28 ) ) ;
return V_74 - V_73 ;
}
static void F_48 ( struct V_8 * V_9 , union V_1 V_32 , union V_1 V_33 ,
enum V_44 V_46 )
{
char V_73 [ 300 ] ;
char * V_74 = V_73 ;
V_74 += F_47 ( V_74 , V_32 , V_33 , V_46 ^ V_80 ) ;
if ( V_33 . V_69 != V_32 . V_69 )
V_74 += sprintf ( V_74 , L_10 ,
V_32 . V_69 ,
V_33 . V_69 ) ;
if ( V_33 . V_70 != V_32 . V_70 )
V_74 += sprintf ( V_74 , L_11 ,
V_32 . V_70 ,
V_33 . V_70 ) ;
if ( V_33 . V_71 != V_32 . V_71 )
V_74 += sprintf ( V_74 , L_12 ,
V_32 . V_71 ,
V_33 . V_71 ) ;
if ( V_74 != V_73 )
F_49 ( V_68 , L_13 , V_73 ) ;
}
static void F_50 ( struct V_6 * V_7 , union V_1 V_32 , union V_1 V_33 ,
enum V_44 V_46 )
{
char V_73 [ 300 ] ;
char * V_74 = V_73 ;
V_74 += F_47 ( V_74 , V_32 , V_33 , V_46 ) ;
if ( F_1 ( V_33 ) != F_1 ( V_32 ) && V_46 & V_81 )
V_74 += sprintf ( V_74 , L_14 ,
F_1 ( V_32 ) ,
F_1 ( V_33 ) ) ;
if ( V_74 != V_73 )
F_51 ( V_7 , L_13 , V_73 ) ;
}
static enum V_43
F_29 ( struct V_8 * V_9 , union V_1 V_33 )
{
enum V_82 V_83 ;
enum V_43 V_10 = V_53 ;
struct V_84 * V_85 ;
F_3 () ;
V_83 = V_86 ;
if ( F_52 ( V_9 ) ) {
V_83 = F_53 ( V_9 -> V_87 -> V_88 ) -> V_89 ;
F_54 ( V_9 ) ;
}
V_85 = F_53 ( V_9 -> V_7 -> V_84 ) ;
if ( V_85 ) {
if ( ! V_85 -> V_90 && V_33 . V_17 == V_22 ) {
if ( V_33 . V_24 == V_22 )
V_10 = V_91 ;
else if ( F_9 ( V_9 -> V_7 ) == V_22 )
V_10 = V_92 ;
}
}
if ( V_10 <= 0 )
;
else if ( V_33 . V_17 == V_18 && V_9 -> V_93 )
V_10 = V_94 ;
else if ( V_33 . V_17 == V_22 && V_33 . V_15 < V_34 && V_33 . V_13 < V_95 )
V_10 = V_96 ;
else if ( V_83 >= V_97 &&
V_33 . V_17 == V_22 && V_33 . V_15 < V_34 && V_33 . V_28 >= V_98 )
V_10 = V_99 ;
else if ( V_33 . V_17 == V_22 && V_33 . V_13 <= V_100 && V_33 . V_28 <= V_100 )
V_10 = V_96 ;
else if ( V_33 . V_15 > V_34 && V_33 . V_13 < V_100 )
V_10 = V_101 ;
else if ( V_33 . V_15 > V_34 && V_33 . V_28 < V_100 )
V_10 = V_102 ;
else if ( V_33 . V_15 > V_34 && V_33 . V_13 < V_95 && V_33 . V_28 < V_95 )
V_10 = V_96 ;
else if ( ( V_33 . V_15 == V_34 ||
V_33 . V_15 == V_103 ||
V_33 . V_15 == V_104 ||
V_33 . V_15 == V_105 ) &&
V_33 . V_13 == V_106 )
V_10 = V_107 ;
else if ( ( V_33 . V_15 == V_39 || V_33 . V_15 == V_108 ) &&
( V_85 -> V_109 [ 0 ] == 0 ) )
V_10 = V_110 ;
else if ( ( V_33 . V_15 == V_39 || V_33 . V_15 == V_108 ) &&
V_9 -> V_7 -> V_111 < 88 )
V_10 = V_112 ;
else if ( V_33 . V_17 == V_22 && V_33 . V_13 < V_95 && V_33 . V_28 < V_95 )
V_10 = V_96 ;
else if ( ( V_33 . V_15 == V_36 || V_33 . V_15 == V_35 ) &&
V_33 . V_28 == V_98 )
V_10 = V_113 ;
else if ( V_33 . V_15 >= V_34 && V_33 . V_28 == V_98 )
V_10 = V_107 ;
F_5 () ;
return V_10 ;
}
static enum V_43
F_30 ( union V_1 V_32 , union V_1 V_33 , struct V_6 * V_7 )
{
enum V_43 V_10 = V_53 ;
if ( ( V_33 . V_15 == V_35 || V_33 . V_15 == V_36 ) &&
V_32 . V_15 > V_34 )
V_10 = V_114 ;
if ( V_33 . V_15 == V_38 && V_32 . V_15 == V_16 )
V_10 = V_115 ;
if ( V_33 . V_13 > V_116 && V_32 . V_13 == V_14 )
V_10 = V_117 ;
if ( V_33 . V_15 == V_118 && V_32 . V_15 < V_119 )
V_10 = V_120 ;
if ( V_33 . V_13 == V_106 && V_32 . V_13 < V_106 && V_32 . V_13 != V_116 )
V_10 = V_121 ;
if ( V_33 . V_15 == V_38 && V_32 . V_15 == V_119 )
V_10 = V_66 ;
if ( F_55 ( V_122 , & V_7 -> V_46 ) &&
! ( V_32 . V_15 == V_31 ||
( V_33 . V_15 == V_31 && V_32 . V_15 == V_118 ) ) )
V_10 = V_66 ;
if ( ( V_33 . V_15 == V_39 || V_33 . V_15 == V_108 ) && V_32 . V_15 < V_34 )
V_10 = V_113 ;
if ( ( V_33 . V_15 == V_39 || V_33 . V_15 == V_108 ) &&
V_33 . V_15 != V_32 . V_15 && V_32 . V_15 > V_34 )
V_10 = V_114 ;
if ( ( V_33 . V_15 == V_36 || V_33 . V_15 == V_35 ) &&
V_32 . V_15 < V_34 )
V_10 = V_113 ;
if ( ( V_33 . V_15 == V_123 || V_33 . V_15 == V_104 )
&& V_32 . V_15 < V_31 )
V_10 = V_113 ;
if ( V_33 . V_15 == V_38 && V_33 . V_28 == V_106 &&
V_32 . V_15 < V_34 && V_32 . V_28 > V_106 )
V_10 = V_124 ;
return V_10 ;
}
static enum V_43
F_56 ( enum V_29 V_125 , enum V_29 V_85 )
{
if ( V_125 == V_85 )
return V_126 ;
if ( V_125 == V_16 && V_85 == V_38 )
return V_115 ;
if ( V_125 == V_16 && V_85 != V_119 )
return V_113 ;
if ( V_125 < V_31 && V_85 >= V_34 )
return V_113 ;
if ( V_125 >= V_127 && V_125 <= V_128 && V_85 != V_119 && V_85 != V_38 )
return V_66 ;
if ( V_125 == V_38 && V_85 != V_16 )
return V_66 ;
return V_53 ;
}
static enum V_43
F_28 ( union V_1 V_32 , union V_1 V_33 )
{
enum V_43 V_10 ;
V_10 = F_56 ( V_32 . V_15 , V_33 . V_15 ) ;
if ( V_33 . V_13 == V_37 && V_32 . V_13 == V_14 )
V_10 = V_117 ;
return V_10 ;
}
static void F_57 ( struct V_8 * V_9 , enum V_129 V_130 )
{
static const char * V_131 [] = {
[ V_132 ] = L_15 ,
[ V_133 ] = L_16 ,
[ V_134 ] = L_17 ,
[ V_135 ] = L_18 ,
[ V_136 ] = L_19 ,
[ V_137 ] = L_20 ,
} ;
if ( V_130 != V_132 )
F_58 ( V_68 , L_13 , V_131 [ V_130 ] ) ;
}
static union V_1 F_27 ( struct V_8 * V_9 , union V_1 V_33 ,
enum V_129 * V_130 )
{
enum V_82 V_83 ;
enum V_25 V_138 , V_139 , V_140 , V_141 ;
if ( V_130 )
* V_130 = V_132 ;
V_83 = V_86 ;
if ( F_52 ( V_9 ) ) {
F_3 () ;
V_83 = F_53 ( V_9 -> V_87 -> V_88 ) -> V_89 ;
F_5 () ;
F_54 ( V_9 ) ;
}
if ( V_33 . V_15 < V_34 ) {
V_33 . V_70 = 0 ;
V_33 . V_24 = V_23 ;
if ( V_33 . V_28 > V_98 || V_33 . V_28 < V_100 )
V_33 . V_28 = V_98 ;
}
if ( V_33 . V_15 == V_16 && V_33 . V_13 == V_14 && V_33 . V_17 == V_18 )
V_33 . V_69 = 0 ;
if ( V_33 . V_15 > V_34 && ( V_33 . V_13 <= V_37 || V_33 . V_28 <= V_37 ) ) {
if ( V_130 )
* V_130 = V_33 . V_15 == V_39 || V_33 . V_15 == V_108 ?
V_133 : V_134 ;
V_33 . V_15 = V_34 ;
}
if ( V_33 . V_15 < V_34 && V_33 . V_13 == V_142 &&
F_59 ( V_9 , V_142 ) ) {
if ( V_9 -> V_143 == V_9 -> V_87 -> V_144 . V_145 [ V_146 ] ) {
V_33 . V_13 = V_9 -> V_147 . V_13 ;
V_33 . V_28 = V_9 -> V_147 . V_28 ;
} else {
if ( V_130 )
* V_130 = V_135 ;
V_33 . V_13 = V_14 ;
V_33 . V_28 = V_98 ;
}
F_54 ( V_9 ) ;
}
if ( V_33 . V_15 >= V_34 && V_33 . V_15 < V_148 ) {
if ( V_33 . V_13 == V_149 || V_33 . V_13 == V_106 )
V_33 . V_13 = V_95 ;
if ( V_33 . V_28 == V_149 || V_33 . V_28 == V_106 )
V_33 . V_28 = V_95 ;
}
V_138 = V_14 ;
V_139 = V_95 ;
V_140 = V_100 ;
V_141 = V_98 ;
switch ( (enum V_29 ) V_33 . V_15 ) {
case V_150 :
case V_151 :
case V_35 :
case V_152 :
case V_153 :
V_138 = V_100 ;
V_139 = V_106 ;
V_140 = V_95 ;
V_141 = V_95 ;
break;
case V_39 :
case V_108 :
V_138 = V_95 ;
V_139 = V_95 ;
V_140 = V_95 ;
V_141 = V_95 ;
break;
case V_34 :
V_138 = V_14 ;
V_139 = V_95 ;
V_140 = V_14 ;
V_141 = V_95 ;
break;
case V_103 :
case V_105 :
case V_36 :
case V_148 :
V_138 = V_95 ;
V_139 = V_95 ;
V_140 = V_100 ;
V_141 = V_149 ;
break;
case V_123 :
V_138 = V_100 ;
V_139 = V_100 ;
V_140 = V_95 ;
V_141 = V_95 ;
break;
case V_104 :
V_138 = V_95 ;
V_139 = V_95 ;
V_140 = V_100 ;
V_141 = V_100 ;
break;
case V_16 :
case V_38 :
case V_119 :
case V_127 :
case V_154 :
case V_155 :
case V_156 :
case V_128 :
case V_118 :
case V_31 :
case V_30 :
break;
}
if ( V_33 . V_13 > V_139 )
V_33 . V_13 = V_139 ;
if ( V_33 . V_13 < V_138 ) {
if ( V_130 )
* V_130 = V_136 ;
V_33 . V_13 = V_138 ;
}
if ( V_33 . V_28 > V_141 )
V_33 . V_28 = V_141 ;
if ( V_33 . V_28 < V_140 ) {
if ( V_130 )
* V_130 = V_137 ;
V_33 . V_28 = V_140 ;
}
if ( V_83 == V_157 &&
( V_33 . V_17 == V_22 && V_33 . V_15 < V_34 && V_33 . V_28 > V_106 ) )
V_33 . V_5 = 1 ;
if ( V_9 -> V_7 -> V_158 . V_159 == V_160 &&
( V_33 . V_17 == V_22 && V_33 . V_13 < V_95 && V_33 . V_28 < V_95 ) )
V_33 . V_4 = 1 ;
if ( V_33 . V_69 || V_33 . V_70 || V_33 . V_71 ) {
if ( V_33 . V_15 == V_104 )
V_33 . V_15 = V_105 ;
if ( V_33 . V_15 == V_123 )
V_33 . V_15 = V_151 ;
} else {
if ( V_33 . V_15 == V_105 )
V_33 . V_15 = V_104 ;
if ( V_33 . V_15 == V_151 )
V_33 . V_15 = V_123 ;
}
return V_33 ;
}
void F_60 ( struct V_8 * V_9 )
{
if ( F_26 ( V_161 , & V_9 -> V_46 ) )
F_49 ( V_68 , L_21 ) ;
}
static void F_61 ( struct V_8 * V_9 , enum V_29 V_162 )
{
if ( V_9 -> V_7 -> V_111 < 90 )
V_9 -> V_163 = 0 ;
V_9 -> V_164 = F_62 ( V_9 ) ;
V_9 -> V_165 = 0 ;
if ( V_162 == V_108 ) {
V_9 -> V_163 = ~ ( V_166 ) 0 ;
} else {
unsigned long V_167 = F_63 ( V_9 -> V_163 ) ;
if ( V_167 >= V_9 -> V_164 ) {
V_9 -> V_163 =
F_64 ( V_9 -> V_164 - 1 ) ;
V_9 -> V_164 = 1 ;
} else
V_9 -> V_164 -= V_167 ;
V_9 -> V_165 = V_9 -> V_163 ;
}
V_9 -> V_168 = V_9 -> V_164 ;
}
enum V_43
F_65 ( struct V_8 * V_9 , union V_1 V_33 ,
enum V_44 V_46 , struct V_56 * V_57 )
{
union V_1 V_32 ;
enum V_43 V_10 = V_53 ;
enum V_129 V_169 ;
struct V_170 * V_171 ;
bool V_172 , V_173 ;
V_32 = F_21 ( V_9 ) ;
V_33 = F_27 ( V_9 , V_33 , & V_169 ) ;
if ( V_33 . V_42 == V_32 . V_42 )
return V_126 ;
V_10 = F_28 ( V_32 , V_33 ) ;
if ( V_10 < V_53 )
return V_10 ;
if ( ! ( V_46 & V_48 ) ) {
V_10 = F_29 ( V_9 , V_33 ) ;
if ( V_10 < V_53 ) {
if ( F_29 ( V_9 , V_32 ) == V_10 )
V_10 = F_30 ( V_32 , V_33 , V_9 -> V_7 ) ;
} else
V_10 = F_30 ( V_32 , V_33 , V_9 -> V_7 ) ;
}
if ( V_10 < V_53 ) {
if ( V_46 & V_60 )
F_34 ( V_9 , V_32 , V_33 , V_10 ) ;
return V_10 ;
}
F_57 ( V_9 , V_169 ) ;
F_48 ( V_9 , V_32 , V_33 , V_46 ) ;
if ( ! ( V_46 & V_81 ) )
F_50 ( V_9 -> V_7 , V_32 , V_33 , ( V_46 & ~ V_80 ) | V_81 ) ;
if ( ( V_32 . V_13 != V_37 && V_33 . V_13 == V_37 ) ||
( V_32 . V_13 != V_14 && V_33 . V_13 == V_14 ) )
F_66 ( & V_9 -> V_174 ) ;
V_172 = F_67 ( V_9 -> V_12 ) ;
V_9 -> V_12 . V_42 = V_33 . V_42 ;
V_173 = F_67 ( V_9 -> V_12 ) ;
V_9 -> V_7 -> V_3 = V_33 . V_3 ;
V_9 -> V_7 -> V_4 = V_33 . V_4 ;
V_9 -> V_7 -> V_5 = V_33 . V_5 ;
if ( V_172 != V_173 )
F_68 ( V_9 -> V_7 ) ;
if ( V_32 . V_13 == V_116 && V_33 . V_13 >= V_142 )
F_69 ( V_9 , L_22 ) ;
if ( V_32 . V_15 == V_31 && V_33 . V_15 != V_31 &&
F_16 ( V_9 -> V_7 ) )
F_70 ( V_122 , & V_9 -> V_7 -> V_46 ) ;
F_71 ( & V_9 -> V_175 ) ;
F_71 ( & V_9 -> V_61 ) ;
F_71 ( & V_9 -> V_7 -> V_176 ) ;
if ( ( V_32 . V_15 == V_39 || V_32 . V_15 == V_108 ) &&
V_33 . V_15 <= V_34 ) {
V_9 -> V_163 =
F_64 ( F_62 ( V_9 ) - V_9 -> V_168 ) ;
if ( V_9 -> V_168 )
F_49 ( V_68 , L_23 ,
( unsigned long long ) V_9 -> V_163 ) ;
}
if ( ( V_32 . V_15 == V_151 || V_32 . V_15 == V_105 ) &&
( V_33 . V_15 == V_123 || V_33 . V_15 == V_104 ) ) {
F_49 ( V_68 , L_24 ) ;
V_9 -> V_177 += ( long ) V_178
- ( long ) V_9 -> V_179 [ V_9 -> V_180 ] ;
if ( V_33 . V_15 == V_123 )
F_72 ( & V_9 -> V_181 , V_178 ) ;
}
if ( ( V_32 . V_15 == V_123 || V_32 . V_15 == V_104 ) &&
( V_33 . V_15 == V_151 || V_33 . V_15 == V_105 ) ) {
F_49 ( V_68 , L_25 ) ;
V_9 -> V_179 [ V_9 -> V_180 ] = V_178 ;
}
if ( V_32 . V_15 == V_34 &&
( V_33 . V_15 == V_39 || V_33 . V_15 == V_108 ) ) {
unsigned long V_182 = V_178 ;
int V_42 ;
F_61 ( V_9 , V_33 . V_15 ) ;
V_9 -> V_183 = V_182 ;
V_9 -> V_184 = 0 ;
V_9 -> V_185 = 0 ;
V_9 -> V_186 = 0 ;
V_9 -> V_187 = 0 ;
for ( V_42 = 0 ; V_42 < V_188 ; V_42 ++ ) {
V_9 -> V_189 [ V_42 ] = V_9 -> V_168 ;
V_9 -> V_179 [ V_42 ] = V_182 ;
}
F_73 ( V_9 ) ;
if ( V_33 . V_15 == V_39 ) {
F_49 ( V_68 , L_26 ,
( unsigned long long ) V_9 -> V_165 ) ;
F_72 ( & V_9 -> V_181 , V_178 ) ;
}
}
if ( F_52 ( V_9 ) ) {
T_1 V_190 = V_9 -> V_87 -> V_144 . V_46 & ~ ( V_191 | V_192 |
V_193 | V_194 |
V_195 | V_196 ) ;
V_190 &= ~ V_197 ;
if ( F_55 ( V_198 , & V_9 -> V_46 ) )
V_190 |= V_196 ;
if ( V_9 -> V_12 . V_17 == V_22 ||
( V_9 -> V_12 . V_28 < V_100 && V_9 -> V_12 . V_24 == V_22 ) )
V_190 |= V_192 ;
if ( V_9 -> V_12 . V_15 > V_31 )
V_190 |= V_193 ;
if ( V_9 -> V_12 . V_13 > V_100 )
V_190 |= V_191 ;
if ( V_9 -> V_12 . V_13 > V_106 )
V_190 |= V_194 ;
if ( V_9 -> V_12 . V_28 <= V_106 && V_9 -> V_12 . V_28 >= V_100 )
V_190 |= V_195 ;
if ( V_190 != V_9 -> V_87 -> V_144 . V_46 ) {
V_9 -> V_87 -> V_144 . V_46 = V_190 ;
F_74 ( V_9 ) ;
}
if ( V_32 . V_13 < V_149 && V_33 . V_13 >= V_149 )
F_75 ( V_9 , V_9 -> V_87 -> V_144 . V_145 [ V_146 ] ) ;
F_54 ( V_9 ) ;
}
if ( V_32 . V_13 == V_100 && V_32 . V_28 == V_100 &&
V_32 . V_24 == V_18 && V_33 . V_24 == V_22 )
F_76 ( V_199 , & V_9 -> V_46 ) ;
if ( V_32 . V_15 != V_38 && V_33 . V_15 == V_38 )
F_77 ( & V_9 -> V_7 -> V_200 ) ;
if ( V_32 . V_15 != V_16 && V_33 . V_15 == V_16 )
F_77 ( & V_9 -> V_7 -> V_200 ) ;
if ( V_32 . V_15 > V_118 &&
V_33 . V_15 <= V_128 && V_33 . V_15 >= V_127 )
F_78 ( & V_9 -> V_7 -> V_200 ) ;
if ( V_32 . V_15 < V_34 && V_33 . V_15 >= V_34 ) {
F_60 ( V_9 ) ;
V_9 -> V_7 -> V_201 ++ ;
}
if ( ( V_32 . V_13 == V_116 || V_32 . V_13 == V_142 ) &&
V_33 . V_13 > V_142 )
V_9 -> V_202 = V_178 ;
V_171 = F_79 ( sizeof( * V_171 ) , V_203 ) ;
if ( V_171 ) {
V_171 -> V_32 = V_32 ;
V_171 -> V_33 = V_33 ;
V_171 -> V_46 = V_46 ;
V_171 -> V_204 . V_205 = V_206 ;
V_171 -> V_204 . V_9 = V_9 ;
V_171 -> V_57 = V_57 ;
F_80 ( & V_9 -> V_7 -> V_207 , & V_171 -> V_204 ) ;
} else {
F_42 ( V_68 , L_27 ) ;
}
return V_10 ;
}
static int V_206 ( struct V_208 * V_204 , int V_209 )
{
struct V_170 * V_171 =
F_81 ( V_204 , struct V_170 , V_204 ) ;
struct V_8 * V_9 = V_204 -> V_9 ;
F_82 ( V_9 , V_171 -> V_32 , V_171 -> V_33 , V_171 -> V_46 ) ;
if ( V_171 -> V_46 & V_62 ) {
F_37 ( V_171 -> V_57 != NULL ) ;
F_83 ( V_171 -> V_57 ) ;
}
F_84 ( V_171 ) ;
return 0 ;
}
static void F_85 ( struct V_8 * V_9 , int V_10 )
{
if ( V_10 ) {
F_42 ( V_68 , L_28 ) ;
F_40 ( V_9 , F_86 ( V_15 , V_34 ) , V_60 ) ;
return;
}
switch ( V_9 -> V_12 . V_15 ) {
case V_35 :
F_40 ( V_9 , F_86 ( V_15 , V_152 ) , V_60 ) ;
break;
case V_36 :
F_87 ( V_9 , V_104 ) ;
break;
}
}
int F_88 ( struct V_8 * V_9 ,
int (* F_89)( struct V_8 * ) ,
char * V_210 , enum V_211 V_46 )
{
int V_10 ;
F_37 ( V_63 == V_9 -> V_7 -> V_64 . V_65 ) ;
F_76 ( V_212 , & V_9 -> V_46 ) ;
F_90 ( V_9 , V_210 , V_46 ) ;
V_10 = F_89 ( V_9 ) ;
F_91 ( V_9 ) ;
F_92 ( V_9 ) ;
return V_10 ;
}
static void F_82 ( struct V_8 * V_9 , union V_1 V_32 ,
union V_1 V_33 , enum V_44 V_46 )
{
struct V_213 V_214 ;
V_214 . V_215 = V_216 ;
V_214 . V_32 = V_32 ;
V_214 . V_33 = V_33 ;
if ( V_32 . V_15 != V_34 && V_33 . V_15 == V_34 ) {
F_70 ( V_198 , & V_9 -> V_46 ) ;
if ( V_9 -> V_217 )
V_9 -> V_217 [ V_218 ] &= ~ ( ( V_219 ) 2 ) ;
}
F_93 ( V_9 , & V_214 ) ;
if ( ! ( V_32 . V_17 == V_22 && V_32 . V_13 < V_95 && V_32 . V_28 < V_95 ) &&
( V_33 . V_17 == V_22 && V_33 . V_13 < V_95 && V_33 . V_28 < V_95 ) )
F_94 ( V_9 , L_29 ) ;
if ( V_33 . V_4 ) {
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_220 V_221 = V_222 ;
F_95 ( & V_7 -> V_47 ) ;
if ( V_32 . V_15 < V_34 && F_15 ( V_7 ) >= V_34 )
V_221 = V_223 ;
if ( ( V_32 . V_13 == V_116 || V_32 . V_13 == V_142 ) &&
F_12 ( V_7 ) > V_142 )
V_221 = V_224 ;
if ( V_7 -> V_4 && V_221 != V_222 ) {
F_96 ( V_7 , V_221 ) ;
F_97 (tconn,
(union drbd_state) { { .susp_nod = 1 } },
(union drbd_state) { { .susp_nod = 0 } },
CS_VERBOSE) ;
}
F_98 ( & V_7 -> V_47 ) ;
}
if ( V_33 . V_5 ) {
struct V_6 * V_7 = V_9 -> V_7 ;
F_95 ( & V_7 -> V_47 ) ;
if ( V_7 -> V_5 && F_15 ( V_7 ) >= V_34 ) {
struct V_8 * V_225 ;
int V_11 ;
F_3 () ;
F_4 (&tconn->volumes, odev, vnr)
F_70 ( V_226 , & V_225 -> V_46 ) ;
F_5 () ;
F_96 ( V_7 , V_223 ) ;
F_97 (tconn,
(union drbd_state) { { .susp_fen = 1 } },
(union drbd_state) { { .susp_fen = 0 } },
CS_VERBOSE) ;
}
F_98 ( & V_7 -> V_47 ) ;
}
if ( ( V_32 . V_15 != V_104 && V_32 . V_15 != V_105 ) &&
( V_33 . V_15 == V_104 || V_33 . V_15 == V_105 ) &&
V_9 -> V_7 -> V_111 >= 96 && F_52 ( V_9 ) ) {
F_99 ( V_9 ) ;
F_54 ( V_9 ) ;
}
if ( V_32 . V_28 == V_14 &&
V_33 . V_28 > V_14 && V_33 . V_28 != V_98 ) {
V_9 -> V_164 = 0 ;
V_9 -> V_227 = 0 ;
F_100 ( & V_9 -> V_228 , 0 ) ;
F_101 ( V_9 ) ;
F_102 ( V_9 ) ;
F_103 ( V_9 , V_33 ) ;
}
if ( V_32 . V_15 != V_103 && V_33 . V_15 == V_103 &&
V_9 -> V_12 . V_15 == V_103 )
F_104 ( V_9 , & V_229 , NULL ,
L_30 ,
V_230 ) ;
if ( ( V_32 . V_28 >= V_100 &&
V_32 . V_28 != V_98 &&
V_32 . V_28 != V_106 )
&& ( V_33 . V_28 < V_100 ||
V_33 . V_28 == V_98 ||
V_33 . V_28 == V_106 ) ) {
if ( F_52 ( V_9 ) ) {
if ( ( V_33 . V_17 == V_22 || V_33 . V_24 == V_22 ) &&
V_9 -> V_87 -> V_144 . V_145 [ V_231 ] == 0 && V_33 . V_13 >= V_95 ) {
if ( F_105 ( V_9 ) ) {
F_76 ( V_226 , & V_9 -> V_46 ) ;
} else {
F_106 ( V_9 ) ;
F_102 ( V_9 ) ;
}
}
F_54 ( V_9 ) ;
}
}
if ( V_33 . V_28 < V_100 && F_52 ( V_9 ) ) {
if ( V_32 . V_24 == V_18 && V_33 . V_24 == V_22 &&
V_9 -> V_87 -> V_144 . V_145 [ V_231 ] == 0 && V_33 . V_13 >= V_95 ) {
F_106 ( V_9 ) ;
F_102 ( V_9 ) ;
}
if ( V_32 . V_24 == V_22 && V_33 . V_24 == V_18 )
F_88 ( V_9 , & V_232 ,
L_31 , V_233 ) ;
F_54 ( V_9 ) ;
}
if ( V_32 . V_17 == V_22 && V_33 . V_17 == V_18 &&
V_9 -> V_12 . V_15 <= V_34 && F_52 ( V_9 ) ) {
F_88 ( V_9 , & V_232 ,
L_32 , V_230 ) ;
F_54 ( V_9 ) ;
}
if ( V_33 . V_15 >= V_34 &&
V_32 . V_13 == V_116 && V_33 . V_13 == V_142 ) {
F_107 ( V_9 , 0 , 0 ) ;
F_102 ( V_9 ) ;
F_103 ( V_9 , V_33 ) ;
}
if ( V_33 . V_15 >= V_34 &&
( ( V_32 . V_69 != V_33 . V_69 ) ||
( V_32 . V_71 != V_33 . V_71 ) ) )
F_103 ( V_9 , V_33 ) ;
if ( ( ! V_32 . V_69 && ! V_32 . V_70 && ! V_32 . V_71 ) &&
( V_33 . V_69 || V_33 . V_70 || V_33 . V_71 ) )
F_108 ( V_9 ) ;
if ( V_32 . V_15 == V_31 && V_33 . V_15 >= V_34 )
F_103 ( V_9 , V_33 ) ;
if ( V_32 . V_15 != V_148 && V_33 . V_15 == V_148 )
F_103 ( V_9 , V_33 ) ;
if ( ( V_32 . V_15 != V_35 && V_33 . V_15 == V_35 ) ||
( V_32 . V_15 != V_36 && V_33 . V_15 == V_36 ) )
F_104 ( V_9 ,
& V_234 , & F_85 ,
L_33 , V_230 ) ;
if ( V_32 . V_13 != V_37 && V_33 . V_13 == V_37 ) {
enum V_235 V_236 = V_237 ;
int V_238 = 0 ;
if ( V_9 -> V_87 ) {
F_3 () ;
V_236 = F_53 ( V_9 -> V_87 -> V_88 ) -> V_239 ;
F_5 () ;
V_238 = F_26 ( V_240 , & V_9 -> V_46 ) ;
if ( V_238 && V_236 == V_241 )
F_94 ( V_9 , L_34 ) ;
if ( F_26 ( V_242 , & V_9 -> V_46 ) )
F_109 ( V_9 ) ;
if ( V_9 -> V_12 . V_13 != V_37 )
F_42 ( V_68 ,
L_35 ,
F_45 ( V_9 -> V_12 . V_13 ) ) ;
if ( V_33 . V_15 >= V_34 )
F_103 ( V_9 , V_33 ) ;
F_101 ( V_9 ) ;
F_110 ( V_9 ) ;
}
F_54 ( V_9 ) ;
}
if ( V_32 . V_13 != V_14 && V_33 . V_13 == V_14 ) {
if ( V_9 -> V_12 . V_13 != V_14 )
F_42 ( V_68 ,
L_36 ,
F_45 ( V_9 -> V_12 . V_13 ) ) ;
if ( V_33 . V_15 >= V_34 )
F_103 ( V_9 , V_33 ) ;
F_54 ( V_9 ) ;
}
if ( V_32 . V_13 == V_95 && V_33 . V_13 == V_100 && V_33 . V_15 >= V_34 )
F_103 ( V_9 , V_33 ) ;
if ( V_33 . V_13 > V_142 && V_33 . V_28 > V_142 &&
F_26 ( V_243 , & V_9 -> V_46 ) ) {
if ( V_33 . V_15 == V_34 )
F_111 ( V_9 ) ;
}
if ( ( V_32 . V_15 > V_34 && V_33 . V_15 <= V_34 ) ||
( V_32 . V_70 && ! V_33 . V_70 ) ||
( V_32 . V_71 && ! V_33 . V_71 ) )
F_112 ( V_9 ) ;
if ( V_32 . V_13 < V_95 && V_32 . V_15 >= V_104 && V_33 . V_15 == V_34 )
F_103 ( V_9 , V_33 ) ;
if ( V_32 . V_15 == V_39 && V_33 . V_15 == V_34
&& F_113 ( V_9 ) )
F_103 ( V_9 , V_33 ) ;
if ( V_32 . V_15 > V_34 && V_33 . V_15 <= V_34 && F_52 ( V_9 ) ) {
F_104 ( V_9 , & V_244 , NULL ,
L_37 , V_245 ) ;
F_54 ( V_9 ) ;
}
if ( V_33 . V_13 == V_14 &&
V_33 . V_15 == V_16 &&
V_33 . V_17 == V_18 ) {
if ( V_32 . V_69 != V_33 . V_69 )
F_112 ( V_9 ) ;
}
F_110 ( V_9 ) ;
}
static int F_114 ( struct V_208 * V_204 , int V_209 )
{
struct V_246 * V_247 =
F_81 ( V_204 , struct V_246 , V_204 ) ;
struct V_6 * V_7 = V_204 -> V_7 ;
enum V_29 V_125 = V_247 -> V_125 ;
union V_1 V_248 = V_247 -> V_248 ;
struct V_8 * V_9 ;
int V_11 ;
F_84 ( V_247 ) ;
if ( V_125 == V_16 && V_248 . V_15 == V_119 )
F_115 ( & V_7 -> V_200 ) ;
if ( V_125 == V_38 && V_248 . V_15 == V_16 ) {
struct V_84 * V_249 ;
F_33 ( & V_7 -> V_250 ) ;
V_249 = V_7 -> V_84 ;
V_7 -> V_251 = 0 ;
V_7 -> V_252 = 0 ;
F_116 ( V_7 -> V_84 , NULL ) ;
F_117 ( V_7 ) ;
F_39 ( & V_7 -> V_250 ) ;
F_118 () ;
F_84 ( V_249 ) ;
}
if ( V_248 . V_5 ) {
if ( V_248 . V_28 <= V_106 ) {
F_3 () ;
F_4 (&tconn->volumes, mdev, vnr) {
if ( F_55 ( V_226 , & V_9 -> V_46 ) ) {
F_106 ( V_9 ) ;
F_70 ( V_226 , & V_9 -> V_46 ) ;
}
}
F_5 () ;
F_95 ( & V_7 -> V_47 ) ;
F_96 ( V_7 , V_253 ) ;
F_97 (tconn,
(union drbd_state) { { .susp_fen = 1 } },
(union drbd_state) { { .susp_fen = 0 } },
CS_VERBOSE) ;
F_98 ( & V_7 -> V_47 ) ;
}
}
F_119 ( & V_7 -> V_254 , & V_255 ) ;
F_120 ( V_7 ) ;
return 0 ;
}
void F_121 ( struct V_6 * V_7 , union V_1 * V_256 , enum V_44 * V_257 )
{
enum V_44 V_46 = ~ 0 ;
struct V_8 * V_9 ;
int V_11 , V_258 = 1 ;
union V_259 V_32 , V_162 = {
{ . V_17 = V_18 ,
. V_24 = V_23 ,
. V_15 = V_7 -> V_260 ,
. V_13 = V_14 ,
. V_28 = V_98 ,
} } ;
F_3 () ;
F_4 (&tconn->volumes, mdev, vnr) {
V_32 = V_9 -> V_12 ;
if ( V_258 ) {
V_162 = V_32 ;
V_258 = 0 ;
continue;
}
if ( V_162 . V_17 != V_32 . V_17 )
V_46 &= ~ V_75 ;
if ( V_162 . V_24 != V_32 . V_24 )
V_46 &= ~ V_76 ;
if ( V_162 . V_15 != V_32 . V_15 )
V_46 &= ~ V_77 ;
if ( V_162 . V_13 != V_32 . V_13 )
V_46 &= ~ V_78 ;
if ( V_162 . V_28 != V_32 . V_28 )
V_46 &= ~ V_79 ;
}
F_5 () ;
* V_257 |= V_80 ;
* V_257 &= V_46 ;
( * V_256 ) . V_42 = V_162 . V_42 ;
}
static enum V_43
F_122 ( struct V_6 * V_7 , union V_1 V_40 , union V_1 V_41 ,
enum V_44 V_46 )
{
enum V_43 V_10 = V_53 ;
union V_1 V_33 , V_32 ;
struct V_8 * V_9 ;
int V_11 ;
F_3 () ;
F_4 (&tconn->volumes, mdev, vnr) {
V_32 = F_21 ( V_9 ) ;
V_33 = F_27 ( V_9 , F_18 ( V_32 , V_40 , V_41 ) , NULL ) ;
if ( V_46 & V_261 && V_33 . V_13 == V_106 && V_32 . V_13 < V_106 )
V_33 . V_13 = V_32 . V_13 ;
if ( V_33 . V_42 == V_32 . V_42 )
continue;
V_10 = F_28 ( V_32 , V_33 ) ;
if ( V_10 < V_53 )
break;
if ( ! ( V_46 & V_48 ) ) {
V_10 = F_29 ( V_9 , V_33 ) ;
if ( V_10 < V_53 ) {
if ( F_29 ( V_9 , V_32 ) == V_10 )
V_10 = F_30 ( V_32 , V_33 , V_7 ) ;
} else
V_10 = F_30 ( V_32 , V_33 , V_7 ) ;
}
if ( V_10 < V_53 )
break;
}
F_5 () ;
if ( V_10 < V_53 && V_46 & V_60 )
F_34 ( V_9 , V_32 , V_33 , V_10 ) ;
return V_10 ;
}
void
F_123 ( struct V_6 * V_7 , union V_1 V_40 , union V_1 V_41 ,
union V_1 * V_262 , union V_1 * V_263 , enum V_44 V_46 )
{
union V_1 V_33 , V_32 , V_248 = { } ;
union V_1 V_264 = {
{ . V_17 = V_265 ,
. V_24 = V_265 ,
. V_15 = V_41 . V_15 ,
. V_13 = V_27 ,
. V_28 = V_27
} } ;
struct V_8 * V_9 ;
enum V_43 V_10 ;
int V_11 , V_266 = 0 ;
if ( V_40 . V_15 == V_30 ) {
if ( V_7 -> V_260 != V_31 && V_41 . V_15 == V_31 )
V_7 -> V_267 = V_178 ;
V_7 -> V_260 = V_41 . V_15 ;
}
F_3 () ;
F_4 (&tconn->volumes, mdev, vnr) {
V_266 ++ ;
V_32 = F_21 ( V_9 ) ;
V_33 = F_18 ( V_32 , V_40 , V_41 ) ;
V_33 = F_27 ( V_9 , V_33 , NULL ) ;
if ( V_46 & V_261 && V_33 . V_13 == V_106 && V_32 . V_13 < V_106 )
V_33 . V_13 = V_32 . V_13 ;
V_10 = F_65 ( V_9 , V_33 , V_46 , NULL ) ;
if ( V_10 < V_53 )
F_124 () ;
V_33 . V_42 = V_9 -> V_12 . V_42 ;
V_248 . V_17 = F_6 ( V_33 . V_17 , V_248 . V_17 ) ;
V_248 . V_24 = F_6 ( V_33 . V_24 , V_248 . V_24 ) ;
V_248 . V_15 = F_11 ( enum V_29 , V_33 . V_15 , V_248 . V_15 ) ;
V_248 . V_13 = F_11 ( enum V_25 , V_33 . V_13 , V_248 . V_13 ) ;
V_248 . V_28 = F_11 ( enum V_25 , V_33 . V_28 , V_248 . V_28 ) ;
V_264 . V_17 = F_7 ( V_33 . V_17 , V_264 . V_17 ) ;
V_264 . V_24 = F_7 ( V_33 . V_24 , V_264 . V_24 ) ;
V_264 . V_15 = F_13 ( enum V_29 , V_33 . V_15 , V_264 . V_15 ) ;
V_264 . V_13 = F_13 ( enum V_25 , V_33 . V_13 , V_264 . V_13 ) ;
V_264 . V_28 = F_13 ( enum V_25 , V_33 . V_28 , V_264 . V_28 ) ;
}
F_5 () ;
if ( V_266 == 0 ) {
V_264 = V_248 = (union V_1 ) { {
. V_17 = V_18 ,
. V_24 = V_23 ,
. V_15 = V_41 . V_15 ,
. V_13 = V_14 ,
. V_28 = V_98
} } ;
}
V_264 . V_3 = V_248 . V_3 = V_7 -> V_3 ;
V_264 . V_4 = V_248 . V_4 = V_7 -> V_4 ;
V_264 . V_5 = V_248 . V_5 = V_7 -> V_5 ;
* V_262 = V_264 ;
* V_263 = V_248 ;
}
static enum V_43
F_125 ( struct V_6 * V_7 , union V_1 V_40 , union V_1 V_41 )
{
enum V_43 V_10 ;
if ( F_26 ( V_268 , & V_7 -> V_46 ) )
return V_50 ;
if ( F_26 ( V_269 , & V_7 -> V_46 ) )
return V_52 ;
V_10 = F_122 ( V_7 , V_40 , V_41 , 0 ) ;
if ( V_10 == V_53 && V_7 -> V_260 == V_31 )
V_10 = V_54 ;
return V_10 ;
}
enum V_43
F_97 ( struct V_6 * V_7 , union V_1 V_40 , union V_1 V_41 ,
enum V_44 V_46 )
{
enum V_43 V_10 = V_53 ;
struct V_246 * V_247 ;
enum V_29 V_125 = V_7 -> V_260 ;
union V_1 V_248 , V_264 , V_32 ;
bool V_270 = false ;
if ( V_40 . V_15 ) {
V_10 = F_56 ( V_125 , V_41 . V_15 ) ;
if ( V_10 < V_53 )
goto abort;
}
V_10 = F_122 ( V_7 , V_40 , V_41 , V_46 ) ;
if ( V_10 < V_53 )
goto abort;
if ( V_125 == V_31 && V_41 . V_15 == V_38 &&
! ( V_46 & ( V_271 | V_48 ) ) ) {
F_98 ( & V_7 -> V_47 ) ;
F_33 ( & V_7 -> V_272 ) ;
V_270 = true ;
F_76 ( V_273 , & V_7 -> V_46 ) ;
if ( F_126 ( V_7 , V_40 , V_41 ) ) {
F_70 ( V_273 , & V_7 -> V_46 ) ;
V_10 = V_52 ;
goto V_274;
}
if ( V_41 . V_15 == V_38 )
F_76 ( V_275 , & V_7 -> V_46 ) ;
F_95 ( & V_7 -> V_47 ) ;
F_127 ( V_7 -> V_176 ,
( V_10 = F_125 ( V_7 , V_40 , V_41 ) ) ,
V_7 -> V_47 ) ;
F_70 ( V_273 , & V_7 -> V_46 ) ;
if ( V_10 < V_53 )
goto abort;
}
F_121 ( V_7 , & V_32 , & V_46 ) ;
V_46 |= V_81 ;
F_123 ( V_7 , V_40 , V_41 , & V_264 , & V_248 , V_46 ) ;
F_50 ( V_7 , V_32 , V_248 , V_46 ) ;
V_247 = F_79 ( sizeof( * V_247 ) , V_203 ) ;
if ( V_247 ) {
V_247 -> V_125 = V_32 . V_15 ;
V_247 -> V_264 = V_264 ;
V_247 -> V_248 = V_248 ;
V_247 -> V_46 = V_46 ;
V_247 -> V_204 . V_205 = F_114 ;
F_128 ( & V_7 -> V_254 ) ;
V_247 -> V_204 . V_7 = V_7 ;
F_80 ( & V_7 -> V_207 , & V_247 -> V_204 ) ;
} else {
F_129 ( V_7 , L_38 ) ;
}
abort:
if ( V_270 ) {
F_98 ( & V_7 -> V_47 ) ;
V_274:
F_39 ( & V_7 -> V_272 ) ;
F_95 ( & V_7 -> V_47 ) ;
}
if ( V_10 < V_53 && V_46 & V_60 ) {
F_129 ( V_7 , L_2 , F_46 ( V_10 ) ) ;
F_129 ( V_7 , L_39 , V_40 . V_42 , V_41 . V_42 ) ;
F_129 ( V_7 , L_40 , F_43 ( V_125 ) , F_43 ( V_41 . V_15 ) ) ;
}
return V_10 ;
}
enum V_43
F_130 ( struct V_6 * V_7 , union V_1 V_40 , union V_1 V_41 ,
enum V_44 V_46 )
{
enum V_43 V_10 ;
F_95 ( & V_7 -> V_47 ) ;
V_10 = F_97 ( V_7 , V_40 , V_41 , V_46 ) ;
F_98 ( & V_7 -> V_47 ) ;
return V_10 ;
}
