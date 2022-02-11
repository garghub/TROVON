struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
T_2 V_5 ;
V_4 = F_2 ( V_2 -> V_6 , V_3 , & V_5 ) ;
if ( V_4 == NULL )
return NULL ;
memset ( V_4 , 0 , sizeof( struct V_1 ) ) ;
V_4 -> V_7 = V_5 ;
V_4 -> V_2 = V_2 ;
F_3 ( & V_4 -> V_8 ) ;
F_3 ( & V_4 -> V_9 ) ;
return V_4 ;
}
static void F_4 ( struct V_2 * V_2 , struct V_1 * V_4 , struct V_10 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_14 * V_14 = V_12 -> V_14 ;
struct V_15 * V_16 ;
bool V_17 ;
T_3 V_18 ;
V_17 = F_5 ( V_10 -> V_19 ) ;
V_4 -> V_20 = F_6 ( V_10 -> V_21 -> V_22 . V_23 ) ;
V_16 = (struct V_15 * ) V_4 -> V_21 -> V_24 ;
if ( V_16 ) {
V_4 -> V_25 = V_16 -> V_26 ;
V_4 -> V_27 = V_16 -> V_28 ;
} else {
V_4 -> V_25 = 2 ;
V_4 -> V_27 = 1 ;
}
if ( F_7 ( V_10 -> V_19 ) )
V_18 = V_29 ;
else {
T_4 V_30 ;
V_30 = F_6 ( V_14 -> V_31 -> V_32 ) ;
V_18 = F_8 ( V_30 ) - 1 ;
if ( V_18 > V_2 -> V_33 . V_18 )
V_18 = V_2 -> V_33 . V_18 ;
}
V_4 -> V_34 . V_35 = F_9 (
F_10 ( F_11 ( V_10 -> V_19 ) )
| ( V_17 ? V_36 : V_37 )
| F_12 ( V_10 -> V_19 )
| F_13 ( F_14 ( V_12 -> V_38 ) )
| F_15 ( V_4 -> V_20 )
) ;
V_4 -> V_34 . V_39 = F_9 (
F_16 ( V_4 -> V_27 )
| F_17 ( 0 )
| F_18 ( 3 )
| F_19 ( 3 )
| F_20 ( V_4 -> V_25 - 1 )
) ;
V_4 -> V_34 . V_40 = F_9 (
F_21 ( V_18 )
| F_22 ( 0 )
) ;
V_4 -> V_34 . V_41 = F_9 ( ( 1 << V_4 -> V_27 ) - 1 ) ;
}
void F_23 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
V_4 -> V_42 = V_4 -> V_43 = V_4 -> V_44 = 0 ;
V_4 -> V_34 . V_45 = F_9 ( F_24 ( 8 ) | V_46 ) ;
V_4 -> V_34 . V_47 = V_4 -> V_34 . V_47 & V_48 ;
V_4 -> V_34 . V_49 = 0 ;
V_4 -> V_34 . V_50 [ 0 ] = 0 ;
V_4 -> V_34 . V_50 [ 1 ] = 0 ;
V_4 -> V_34 . V_50 [ 2 ] = 0 ;
memset ( & V_4 -> V_34 . V_51 , 0 , sizeof( V_4 -> V_34 . V_51 ) ) ;
F_25 ( & V_4 -> V_52 ) ;
}
void F_26 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
V_4 -> V_53 = 0 ;
V_4 -> V_34 . V_47 &= ~ V_48 ;
V_4 -> V_34 . V_41 = F_9 ( ( 1 << V_4 -> V_27 ) - 1 ) ;
}
struct V_1 * F_27 ( struct V_2 * V_2 , struct V_10 * V_10 ,
T_1 V_3 )
{
struct V_1 * V_4 ;
V_4 = V_10 -> V_21 -> V_54 ;
if ( V_4 == NULL ) {
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_21 = V_10 -> V_21 ;
V_10 -> V_21 -> V_54 = V_4 ;
F_4 ( V_2 , V_4 , V_10 ) ;
}
return V_4 ;
}
void F_28 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
V_4 -> remove = 0 ;
F_29 ( & V_4 -> V_8 ) ;
F_30 ( & V_4 -> V_52 ) ;
}
enum V_55 F_31 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
struct V_56 * V_57 ;
enum V_55 V_58 = 0 ;
F_32 (std, &qset->stds, list_node) {
struct V_59 * V_60 ;
T_5 V_47 ;
if ( V_4 -> V_44 >= V_61
|| ( V_4 -> V_62 && V_57 -> V_10 != V_4 -> V_62 ) )
break;
if ( V_57 -> V_60 )
continue;
V_60 = V_57 -> V_60 = & V_4 -> V_60 [ V_4 -> V_43 ] ;
if ( F_7 ( V_57 -> V_10 -> V_19 ) )
memcpy ( V_60 -> V_63 , V_57 -> V_10 -> V_64 , 8 ) ;
V_47 = V_65 | F_33 ( V_57 -> V_66 ) ;
if ( F_34 ( V_57 ) && F_5 ( V_57 -> V_10 -> V_19 ) )
V_47 |= V_67 ;
if ( V_57 -> V_68 < V_61 ) {
int V_69 ;
V_69 = ( V_4 -> V_43 + V_57 -> V_68 ) % V_61 ;
V_47 |= F_35 ( V_69 ) ;
} else if ( F_36 ( V_57 -> V_10 -> V_19 ) )
V_4 -> V_62 = V_57 -> V_10 ;
if ( V_57 -> V_70 )
V_60 -> V_71 = F_9 ( V_72 ) ;
else
V_60 -> V_71 = F_9 ( V_72 | V_73 ) ;
V_60 -> V_74 = F_37 ( V_57 -> V_75 ) ;
V_60 -> V_47 = F_9 ( V_47 ) ;
if ( F_38 ( V_4 -> V_34 . V_47 ) == V_4 -> V_43 )
V_58 = V_76 ;
if ( ++ V_4 -> V_43 >= V_61 )
V_4 -> V_43 = 0 ;
V_4 -> V_44 ++ ;
}
return V_58 ;
}
static void F_39 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
V_4 -> V_60 [ V_4 -> V_42 ] . V_47 = 0 ;
if ( ++ V_4 -> V_42 >= V_61 )
V_4 -> V_42 = 0 ;
V_4 -> V_44 -- ;
}
static void F_40 ( struct V_2 * V_2 , struct V_56 * V_57 )
{
struct V_77 * V_78 ;
void * V_79 ;
T_6 V_80 , V_81 ;
V_79 = V_57 -> V_82 ;
V_80 = V_57 -> V_66 ;
V_78 = V_57 -> V_83 ;
V_81 = V_57 -> V_84 ;
while ( V_80 ) {
T_6 V_66 ;
V_66 = F_41 ( V_78 -> V_85 - V_81 , V_80 ) ;
memcpy ( F_42 ( V_78 ) + V_81 , V_79 , V_66 ) ;
V_79 += V_66 ;
V_80 -= V_66 ;
V_81 += V_66 ;
if ( V_81 >= V_78 -> V_85 ) {
V_78 = F_43 ( V_78 ) ;
V_81 = 0 ;
}
}
}
void F_44 ( struct V_2 * V_2 , struct V_56 * V_57 )
{
F_45 ( & V_57 -> V_8 ) ;
if ( V_57 -> V_82 ) {
bool V_17 = F_5 ( V_57 -> V_10 -> V_19 ) ;
T_2 V_75 ;
if ( V_57 -> V_70 )
V_75 = F_46 ( V_57 -> V_86 [ 0 ] . V_87 ) ;
else
V_75 = V_57 -> V_75 ;
F_47 ( V_2 -> V_33 . V_13 , V_75 ,
V_57 -> V_66 , V_17 ? V_88 : V_89 ) ;
if ( ! V_17 )
F_40 ( V_2 , V_57 ) ;
F_48 ( V_57 -> V_82 ) ;
}
if ( V_57 -> V_86 ) {
if ( V_57 -> V_75 )
F_47 ( V_2 -> V_33 . V_13 , V_57 -> V_75 ,
V_57 -> V_70 * sizeof( struct V_90 ) ,
V_88 ) ;
F_48 ( V_57 -> V_86 ) ;
V_57 -> V_86 = NULL ;
}
F_48 ( V_57 ) ;
}
static void F_49 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_10 * V_10 )
{
struct V_56 * V_57 , * V_91 ;
F_50 (std, t, &qset->stds, list_node) {
if ( V_57 -> V_10 != V_10 )
break;
if ( V_57 -> V_60 != NULL )
F_39 ( V_2 , V_4 ) ;
F_44 ( V_2 , V_57 ) ;
}
}
static void F_51 ( struct V_1 * V_4 , struct V_10 * V_10 )
{
struct V_56 * V_57 , * V_91 ;
F_50 (std, t, &qset->stds, list_node) {
if ( V_57 -> V_10 == V_10 )
F_44 ( V_4 -> V_2 , V_57 ) ;
}
}
static int F_52 ( struct V_2 * V_2 , struct V_56 * V_57 , T_1 V_3 )
{
T_2 V_75 = V_57 -> V_75 ;
T_2 V_92 , V_21 ;
T_6 V_93 ;
int V_94 ;
if ( V_57 -> V_66 <= V_95 ) {
V_57 -> V_70 = 0 ;
return 0 ;
}
V_92 = V_75 & ~ ( V_95 - 1 ) ;
V_21 = V_75 + V_57 -> V_66 ;
V_57 -> V_70 = F_53 ( V_21 - V_92 , V_95 ) ;
V_93 = V_57 -> V_70 * sizeof( struct V_90 ) ;
V_57 -> V_86 = F_54 ( V_93 , V_3 ) ;
if ( V_57 -> V_86 == NULL )
return - V_96 ;
V_57 -> V_75 = F_55 ( V_2 -> V_33 . V_13 , V_57 -> V_86 , V_93 , V_88 ) ;
for ( V_94 = 0 ; V_94 < V_57 -> V_70 ; V_94 ++ ) {
V_57 -> V_86 [ V_94 ] . V_87 = F_37 ( V_75 ) ;
V_75 = ( V_75 + V_95 ) & ~ ( V_95 - 1 ) ;
}
return 0 ;
}
static void F_56 ( struct V_97 * V_98 )
{
struct V_99 * V_100 = F_57 ( V_98 , struct V_99 , V_101 ) ;
struct V_1 * V_4 = V_100 -> V_4 ;
struct V_2 * V_2 = V_4 -> V_2 ;
unsigned long V_102 ;
if ( V_100 -> V_103 == true )
F_58 ( V_2 , V_104
| V_105
| V_106 ) ;
else
F_59 ( V_2 , V_107
| V_108
| V_109 ) ;
F_60 ( & V_2 -> V_110 , V_102 ) ;
F_61 ( V_2 , V_4 , V_100 -> V_10 , V_100 -> V_47 ) ;
F_62 ( & V_2 -> V_110 , V_102 ) ;
}
static struct V_56 * F_63 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_10 * V_10 , T_1 V_3 )
{
struct V_56 * V_57 ;
V_57 = F_64 ( sizeof( struct V_56 ) , V_3 ) ;
if ( V_57 == NULL )
return NULL ;
V_57 -> V_10 = V_10 ;
V_57 -> V_60 = NULL ;
F_3 ( & V_57 -> V_8 ) ;
F_65 ( & V_57 -> V_8 , & V_4 -> V_9 ) ;
return V_57 ;
}
static int F_66 ( struct V_2 * V_2 , struct V_1 * V_4 , struct V_10 * V_10 ,
T_1 V_3 )
{
T_6 V_80 ;
struct V_77 * V_78 ;
int V_111 ;
int V_44 = 0 ;
struct V_56 * V_57 = NULL ;
struct V_90 * V_112 ;
T_2 V_113 = 0 ;
T_6 V_93 ;
int V_94 = 0 ;
V_80 = V_10 -> V_114 ;
F_67 (urb->sg, sg, urb->num_sgs, i) {
T_2 V_75 ;
T_6 V_115 ;
T_2 V_92 , V_21 ;
int V_70 ;
if ( V_80 == 0 ) {
break;
}
V_75 = F_68 ( V_78 ) ;
V_115 = F_69 ( T_6 , F_70 ( V_78 ) , V_80 ) ;
while ( V_115 ) {
T_6 V_116 ;
if ( ! V_57
|| ( V_113 & ( V_95 - 1 ) )
|| ( V_75 & ( V_95 - 1 ) )
|| V_57 -> V_66 + V_95 > V_117 ) {
if ( V_57 && V_57 -> V_66 % V_4 -> V_20 != 0 )
return - V_118 ;
V_57 = F_63 ( V_2 , V_4 , V_10 , V_3 ) ;
if ( V_57 == NULL ) {
return - V_96 ;
}
V_44 ++ ;
V_94 = 0 ;
}
V_116 = V_115 ;
if ( V_57 -> V_66 + V_116 > V_117 ) {
V_116 = ( V_117 / V_4 -> V_20 )
* V_4 -> V_20 - V_57 -> V_66 ;
}
V_57 -> V_66 += V_116 ;
V_57 -> V_68 = - 1 ;
V_92 = V_75 & ~ ( V_95 - 1 ) ;
V_21 = V_75 + V_116 ;
V_70 = F_53 ( V_21 - V_92 , V_95 ) ;
V_57 -> V_70 += V_70 ;
V_93 = V_57 -> V_70 * sizeof( struct V_90 ) ;
V_57 -> V_86 = F_71 ( V_57 -> V_86 , V_93 , V_3 ) ;
if ( V_57 -> V_86 == NULL ) {
return - V_96 ;
}
for (; V_94 < V_57 -> V_70 ; V_94 ++ , V_112 ++ ) {
V_57 -> V_86 [ V_94 ] . V_87 = F_37 ( V_75 ) ;
V_75 = ( V_75 + V_95 ) & ~ ( V_95 - 1 ) ;
}
V_113 = V_75 = V_21 ;
V_115 -= V_116 ;
V_80 -= V_116 ;
}
}
F_32 (std, &qset->stds, list_node) {
if ( V_57 -> V_68 == - 1 ) {
V_93 = V_57 -> V_70 * sizeof( struct V_90 ) ;
V_57 -> V_68 = V_44 -- ;
V_57 -> V_75 = F_55 ( V_2 -> V_33 . V_13 , V_57 -> V_86 ,
V_93 , V_88 ) ;
}
}
return 0 ;
}
static int F_72 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_10 * V_10 , T_1 V_3 )
{
bool V_17 = F_5 ( V_10 -> V_19 ) ;
T_6 V_119 ;
T_6 V_80 ;
int V_44 = 0 ;
struct V_56 * V_57 = NULL ;
void * V_79 = NULL ;
struct V_77 * V_78 ;
int V_111 ;
V_119 = V_4 -> V_27 * V_4 -> V_20 ;
V_80 = V_10 -> V_114 ;
F_67 (urb->sg, sg, urb->num_sgs, i) {
T_6 V_66 ;
T_6 V_120 ;
void * V_121 ;
if ( V_80 == 0 ) {
break;
}
V_120 = F_69 ( T_6 , V_80 , V_78 -> V_85 ) ;
V_121 = F_42 ( V_78 ) ;
while ( V_120 ) {
if ( ! V_57 || V_57 -> V_66 == V_119 ) {
V_57 = F_63 ( V_2 , V_4 , V_10 , V_3 ) ;
if ( V_57 == NULL )
return - V_96 ;
V_57 -> V_82 = F_54 ( V_119 , V_3 ) ;
if ( V_57 -> V_82 == NULL )
return - V_96 ;
V_57 -> V_83 = V_78 ;
V_57 -> V_84 = V_121 - F_42 ( V_78 ) ;
V_79 = V_57 -> V_82 ;
V_44 ++ ;
}
V_66 = F_41 ( V_120 , V_119 - V_57 -> V_66 ) ;
if ( V_17 )
memcpy ( V_79 , V_121 , V_66 ) ;
V_57 -> V_66 += V_66 ;
V_57 -> V_68 = - 1 ;
V_79 += V_66 ;
V_121 += V_66 ;
V_120 -= V_66 ;
V_80 -= V_66 ;
}
}
F_32 (std, &qset->stds, list_node) {
if ( V_57 -> V_68 != - 1 )
continue;
V_57 -> V_75 = F_55 ( & V_2 -> V_122 -> V_13 , V_57 -> V_82 , V_57 -> V_66 ,
V_17 ? V_88 : V_89 ) ;
if ( F_52 ( V_2 , V_57 , V_3 ) < 0 )
return - V_96 ;
V_57 -> V_68 = V_44 -- ;
}
return 0 ;
}
int F_73 ( struct V_2 * V_2 , struct V_1 * V_4 , struct V_10 * V_10 ,
T_1 V_3 )
{
struct V_99 * V_100 ;
int V_80 = V_10 -> V_114 ;
T_7 V_123 = V_10 -> V_123 ;
int V_68 ;
int V_124 ;
V_100 = F_64 ( sizeof( struct V_99 ) , V_3 ) ;
if ( V_100 == NULL )
goto V_125;
V_10 -> V_54 = V_100 ;
V_100 -> V_4 = V_4 ;
V_100 -> V_10 = V_10 ;
F_74 ( & V_100 -> V_101 , F_56 ) ;
if ( V_10 -> V_126 ) {
V_124 = F_66 ( V_2 , V_4 , V_10 , V_3 ) ;
if ( V_124 == - V_118 ) {
F_51 ( V_4 , V_10 ) ;
V_124 = F_72 ( V_2 , V_4 , V_10 , V_3 ) ;
}
if ( V_124 < 0 )
goto V_125;
return 0 ;
}
V_68 = F_53 ( V_80 , V_117 ) ;
if ( V_68 == 0 )
V_68 = 1 ;
while ( V_68 ) {
struct V_56 * V_57 ;
T_6 V_127 ;
V_127 = V_80 ;
if ( V_127 > V_117 )
V_127 = V_117 ;
V_57 = F_63 ( V_2 , V_4 , V_10 , V_3 ) ;
if ( V_57 == NULL )
goto V_125;
V_57 -> V_75 = V_123 ;
V_57 -> V_66 = V_127 ;
V_57 -> V_68 = V_68 ;
if ( F_52 ( V_2 , V_57 , V_3 ) < 0 )
goto V_125;
V_68 -- ;
V_80 -= V_127 ;
V_123 += V_127 ;
}
return 0 ;
V_125:
F_51 ( V_4 , V_10 ) ;
return - V_96 ;
}
void F_61 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_10 * V_10 , int V_47 )
{
struct V_33 * V_33 = & V_2 -> V_33 ;
struct V_99 * V_100 = V_10 -> V_54 ;
F_75 ( & V_33 -> V_128 , V_10 ) ;
F_76 ( & V_2 -> V_110 ) ;
F_77 ( V_33 , V_10 , V_47 ) ;
F_78 ( & V_2 -> V_110 ) ;
F_48 ( V_100 ) ;
}
static int F_79 ( struct V_10 * V_10 , T_8 V_47 )
{
if ( V_47 & V_129 ) {
if ( V_47 & V_130 )
return F_36 ( V_10 -> V_19 ) ? - V_131 : - V_132 ;
else if ( V_47 & V_133 )
return - V_134 ;
else if ( V_47 & V_135 )
return - V_136 ;
return - V_137 ;
}
if ( F_36 ( V_10 -> V_19 )
&& ( V_10 -> V_138 & V_139 )
&& V_10 -> V_140 < V_10 -> V_114 )
return - V_141 ;
return 0 ;
}
void F_80 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_59 * V_60 )
{
struct V_56 * V_57 = F_81 ( & V_4 -> V_9 , struct V_56 , V_8 ) ;
struct V_10 * V_10 = V_57 -> V_10 ;
T_5 V_47 ;
bool F_30 ;
V_47 = F_82 ( V_60 -> V_47 ) ;
V_10 -> V_140 += V_57 -> V_66 - F_83 ( V_47 ) ;
if ( F_36 ( V_10 -> V_19 ) && ( V_47 & V_67 ) )
F_30 = true ;
else
F_30 = F_34 ( V_57 ) ;
F_39 ( V_2 , V_4 ) ;
F_44 ( V_2 , V_57 ) ;
if ( F_30 ) {
F_49 ( V_2 , V_4 , V_10 ) ;
F_61 ( V_2 , V_4 , V_10 , F_79 ( V_10 , V_47 ) ) ;
if ( ! ( V_47 & V_142 ) )
V_4 -> V_42 = V_4 -> V_43
= F_38 ( F_6 ( V_4 -> V_34 . V_47 ) ) ;
V_4 -> V_62 = NULL ;
}
}
void F_84 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_59 * V_60 )
{
struct V_56 * V_57 = F_81 ( & V_4 -> V_9 , struct V_56 , V_8 ) ;
struct V_10 * V_10 = V_57 -> V_10 ;
int V_143 ;
V_143 = F_79 ( V_10 , F_82 ( V_60 -> V_47 ) ) ;
F_49 ( V_2 , V_4 , V_10 ) ;
F_61 ( V_2 , V_4 , V_10 , V_143 ) ;
F_32 (std, &qset->stds, list_node) {
if ( V_4 -> V_44 == 0 )
break;
F_39 ( V_2 , V_4 ) ;
V_57 -> V_60 = NULL ;
}
V_4 -> remove = 1 ;
}
void F_85 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
F_86 ( V_2 -> V_6 , V_4 , V_4 -> V_7 ) ;
}
void F_87 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
F_88 ( & V_4 -> V_52 ) ;
F_85 ( V_2 , V_4 ) ;
}
