T_1 F_1 ( T_2 V_1 )
{
return ( T_1 ) ( ( 6200 - ( V_1 * V_2 ) ) / 25 ) ;
}
int F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( V_4 == NULL )
return - V_7 ;
V_6 = F_3 ( sizeof( struct V_5 ) , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
V_4 -> V_6 = V_6 ;
V_6 -> V_10 = V_4 -> V_11 ;
V_6 -> V_12 = V_4 -> V_12 ;
V_6 -> V_13 = V_4 -> V_13 ;
V_6 -> V_14 = V_4 -> V_14 ;
V_6 -> V_15 = V_4 -> V_15 ;
V_6 -> V_16 = V_17 ;
V_6 -> V_18 = V_19 ;
V_6 -> V_20 = V_21 ;
V_6 -> V_22 = V_23 ;
F_4 ( V_6 ) ;
F_5 ( V_6 ) ;
switch ( V_6 -> V_13 ) {
case V_24 :
F_6 ( V_6 ) ;
break;
case V_25 :
switch ( V_6 -> V_14 ) {
case V_26 :
F_7 ( V_6 ) ;
V_6 -> V_15 &= ~ ( V_27 |
V_28 ) ;
V_6 -> V_20 = V_29 ;
break;
case V_30 :
F_8 ( V_6 ) ;
V_6 -> V_15 &= ~ V_27 ;
break;
case V_31 :
F_9 ( V_6 ) ;
V_6 -> V_15 &= ~ ( V_27 |
V_28 ) ;
break;
case V_32 :
case V_33 :
case V_34 :
F_10 ( V_6 ) ;
V_6 -> V_15 &= ~ ( V_35 ) ;
break;
default:
return - V_7 ;
}
F_11 ( V_6 ) ;
break;
default:
return - V_7 ;
}
return 0 ;
}
static int F_12 ( struct V_5 * V_6 )
{
int V_36 ;
unsigned int V_37 ;
unsigned int V_38 ;
struct V_39 * V_40 ;
int V_41 ;
if ( V_6 -> V_42 -> V_43 == NULL )
return - V_7 ;
if ( V_6 -> V_42 -> V_44 == NULL )
return - V_7 ;
V_6 -> V_45 = V_38 = V_6 -> V_42 -> V_43 ( V_6 ) ;
V_6 -> V_46 = V_41 = V_6 -> V_42 -> V_44 ( V_6 ) +
sizeof( struct V_39 ) ;
V_6 -> V_47 = F_3 ( V_41 * V_38 , V_8 ) ;
if ( V_6 -> V_47 == NULL )
return - V_9 ;
V_6 -> V_48 = F_3 ( V_41 , V_8 ) ;
if ( V_6 -> V_48 == NULL ) {
F_13 ( V_6 -> V_47 ) ;
V_6 -> V_47 = NULL ;
return - V_9 ;
}
V_6 -> V_49 = F_3 ( V_41 , V_8 ) ;
if ( V_6 -> V_49 == NULL ) {
F_13 ( V_6 -> V_48 ) ;
F_13 ( V_6 -> V_47 ) ;
V_6 -> V_48 = NULL ;
V_6 -> V_47 = NULL ;
return - V_9 ;
}
V_40 = V_6 -> V_47 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
V_36 = V_6 -> V_42 -> V_50 ( V_6 , V_37 , V_40 ) ;
if ( V_40 -> V_51 . V_52 & V_53 ) {
V_6 -> V_54 = V_40 ;
memcpy ( V_6 -> V_49 , V_40 , V_41 ) ;
memcpy ( V_6 -> V_48 , V_40 , V_41 ) ;
}
V_40 -> V_55 = V_37 + 1 ;
if ( V_40 -> V_51 . V_52 & V_56 )
V_6 -> V_57 = V_40 ;
V_40 = (struct V_39 * ) ( ( unsigned long ) V_40 + V_41 ) ;
}
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
if ( V_6 == NULL )
return - V_7 ;
F_13 ( V_6 -> V_49 ) ;
F_13 ( V_6 -> V_48 ) ;
F_13 ( V_6 -> V_47 ) ;
V_6 -> V_48 = NULL ;
V_6 -> V_47 = NULL ;
V_6 -> V_49 = NULL ;
return 0 ;
}
int F_15 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_58 = 0 ;
if ( V_4 == NULL )
return - V_7 ;
V_6 = V_4 -> V_6 ;
if ( V_6 -> V_59 == NULL ||
V_6 -> V_59 -> V_60 == NULL ||
V_6 -> V_42 -> V_61 == NULL )
return - V_7 ;
V_58 = V_6 -> V_59 -> V_60 ( V_6 ) ;
if ( V_58 )
goto V_62;
V_58 = V_6 -> V_42 -> V_61 ( V_6 ) ;
if ( V_58 )
goto V_63;
V_58 = F_12 ( V_6 ) ;
if ( V_58 )
goto V_64;
return 0 ;
V_64:
if ( V_6 -> V_42 -> V_65 )
V_6 -> V_42 -> V_65 ( V_6 ) ;
V_63:
if ( V_6 -> V_59 -> V_66 )
V_6 -> V_59 -> V_66 ( V_6 ) ;
V_62:
F_16 ( L_1 ) ;
return V_58 ;
}
int F_17 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( V_4 == NULL )
return - V_7 ;
V_6 = V_4 -> V_6 ;
if ( V_6 -> V_42 -> V_65 )
V_6 -> V_42 -> V_65 ( V_6 ) ;
if ( V_6 -> V_59 -> V_66 )
V_6 -> V_59 -> V_66 ( V_6 ) ;
return F_14 ( V_6 ) ;
}
int F_18 ( struct V_5 * V_6 , T_3 V_67 ,
T_3 V_68 , T_3 V_69 )
{
T_3 V_37 ;
T_3 V_70 ;
if ( V_6 == NULL || V_6 -> V_12 == NULL ) {
F_16 ( L_2 ) ;
return - V_7 ;
}
for ( V_37 = 0 ; V_37 < V_6 -> V_16 ; V_37 ++ ) {
V_70 = F_19 ( V_6 -> V_12 , V_67 ) ;
if ( ( V_70 & V_69 ) == ( V_68 & V_69 ) )
break;
F_20 ( 1 ) ;
}
if ( V_37 == V_6 -> V_16 )
return - 1 ;
return 0 ;
}
void F_21 ( struct V_5 * V_6 ,
T_3 V_71 ,
T_3 V_67 ,
T_3 V_68 ,
T_3 V_69 )
{
if ( V_6 == NULL || V_6 -> V_12 == NULL ) {
F_16 ( L_2 ) ;
return;
}
F_22 ( V_6 -> V_12 , V_71 , V_67 ) ;
F_18 ( V_6 , V_71 + 1 , V_69 , V_68 ) ;
}
bool F_23 ( struct V_5 * V_6 )
{
return F_24 ( V_6 -> V_72 . V_73 , V_74 ) ;
}
bool F_25 ( struct V_5 * V_6 )
{
return F_24 ( V_6 -> V_72 . V_73 , V_75 ) ;
}
int F_26 ( struct V_76 * V_77 )
{
T_3 V_37 , V_78 ;
T_2 V_79 ;
bool V_80 = false ;
struct V_76 * V_81 ;
F_27 ((NULL != vol_table),
L_3 , return -EINVAL) ;
V_81 = F_3 ( sizeof( struct V_76 ) ,
V_8 ) ;
if ( NULL == V_81 )
return - V_7 ;
V_81 -> V_82 = V_77 -> V_82 ;
V_81 -> V_83 = V_77 -> V_83 ;
for ( V_37 = 0 ; V_37 < V_77 -> V_84 ; V_37 ++ ) {
V_79 = V_77 -> V_85 [ V_37 ] . V_68 ;
V_80 = false ;
for ( V_78 = 0 ; V_78 < V_81 -> V_84 ; V_78 ++ ) {
if ( V_79 == V_81 -> V_85 [ V_78 ] . V_68 ) {
V_80 = true ;
break;
}
}
if ( ! V_80 ) {
V_81 -> V_85 [ V_81 -> V_84 ] . V_68 = V_79 ;
V_81 -> V_85 [ V_81 -> V_84 ] . V_86 =
V_77 -> V_85 [ V_37 ] . V_86 ;
V_81 -> V_84 ++ ;
}
}
memcpy ( V_77 , V_81 , sizeof( struct V_76 ) ) ;
F_13 ( V_81 ) ;
V_81 = NULL ;
return 0 ;
}
int F_28 ( struct V_76 * V_77 ,
T_4 * V_87 )
{
T_3 V_37 ;
int V_36 ;
F_27 ((0 != dep_table->count),
L_4 , return -EINVAL) ;
F_27 ((NULL != vol_table),
L_5 , return -EINVAL) ;
V_77 -> V_82 = 0 ;
V_77 -> V_83 = 0 ;
V_77 -> V_84 = V_87 -> V_84 ;
for ( V_37 = 0 ; V_37 < V_87 -> V_84 ; V_37 ++ ) {
V_77 -> V_85 [ V_37 ] . V_68 = V_87 -> V_85 [ V_37 ] . V_88 ;
V_77 -> V_85 [ V_37 ] . V_86 = 0 ;
}
V_36 = F_26 ( V_77 ) ;
F_27 ((0 == result),
L_6 , return result) ;
return 0 ;
}
int F_29 ( struct V_76 * V_77 ,
T_4 * V_87 )
{
T_3 V_37 ;
int V_36 ;
F_27 ((0 != dep_table->count),
L_4 , return -EINVAL) ;
F_27 ((NULL != vol_table),
L_5 , return -EINVAL) ;
V_77 -> V_82 = 0 ;
V_77 -> V_83 = 0 ;
V_77 -> V_84 = V_87 -> V_84 ;
for ( V_37 = 0 ; V_37 < V_87 -> V_84 ; V_37 ++ ) {
V_77 -> V_85 [ V_37 ] . V_68 = V_87 -> V_85 [ V_37 ] . V_89 ;
V_77 -> V_85 [ V_37 ] . V_86 = 0 ;
}
V_36 = F_26 ( V_77 ) ;
F_27 ((0 == result),
L_7 , return result) ;
return 0 ;
}
int F_30 ( struct V_76 * V_77 ,
T_5 * V_90 )
{
int V_37 = 0 ;
F_27 ((0 != lookup_table->count),
L_8 , return -EINVAL) ;
F_27 ((NULL != vol_table),
L_5 , return -EINVAL) ;
V_77 -> V_82 = 0 ;
V_77 -> V_83 = 0 ;
V_77 -> V_84 = V_90 -> V_84 ;
for ( V_37 = 0 ; V_37 < V_77 -> V_84 ; V_37 ++ ) {
V_77 -> V_85 [ V_37 ] . V_68 = V_90 -> V_85 [ V_37 ] . V_91 ;
V_77 -> V_85 [ V_37 ] . V_86 = 0 ;
}
return 0 ;
}
void F_31 ( T_3 V_92 ,
struct V_76 * V_77 )
{
unsigned int V_37 , V_93 ;
if ( V_77 -> V_84 <= V_92 )
return;
V_93 = V_77 -> V_84 - V_92 ;
for ( V_37 = 0 ; V_37 < V_92 ; V_37 ++ )
V_77 -> V_85 [ V_37 ] = V_77 -> V_85 [ V_37 + V_93 ] ;
V_77 -> V_84 = V_92 ;
return;
}
int F_32 ( void * V_81 ,
T_3 V_84 , int V_94 )
{
int V_37 ;
struct V_95 * V_96 = (struct V_95 * ) V_81 ;
V_96 -> V_84 = V_84 > V_94 ? V_94 : V_84 ;
for ( V_37 = 0 ; V_37 < V_96 -> V_84 ; V_37 ++ )
V_96 -> V_22 [ V_37 ] . V_97 = false ;
return 0 ;
}
void F_33 (
void * V_81 ,
T_3 V_67 , T_3 V_98 ,
T_3 V_99 )
{
struct V_95 * V_96 = (struct V_95 * ) V_81 ;
V_96 -> V_22 [ V_67 ] . V_68 = V_98 ;
V_96 -> V_22 [ V_67 ] . V_100 = V_99 ;
V_96 -> V_22 [ V_67 ] . V_97 = 1 ;
}
T_6 F_34 ( void * V_81 )
{
T_6 V_37 ;
T_6 V_69 = 0 ;
struct V_95 * V_96 = (struct V_95 * ) V_81 ;
for ( V_37 = V_96 -> V_84 ; V_37 > 0 ; V_37 -- ) {
V_69 = V_69 << 1 ;
if ( V_96 -> V_22 [ V_37 - 1 ] . V_97 )
V_69 |= 0x1 ;
else
V_69 &= 0xFFFFFFFE ;
}
return V_69 ;
}
T_1 F_35 (
struct T_5 * V_90 , T_2 V_101 )
{
T_1 V_84 = ( T_1 ) ( V_90 -> V_84 ) ;
T_1 V_37 ;
F_27 ((NULL != lookup_table),
L_9 , return 0 ) ;
F_27 ((0 != count),
L_9 , return 0 ) ;
for ( V_37 = 0 ; V_37 < V_90 -> V_84 ; V_37 ++ ) {
if ( V_90 -> V_85 [ V_37 ] . V_91 >= V_101 )
return V_37 ;
}
return V_37 - 1 ;
}
T_1 F_36 ( V_76 * V_102 ,
T_3 V_101 )
{
T_1 V_84 = ( T_1 ) ( V_102 -> V_84 ) ;
T_1 V_37 = 0 ;
F_27 ((NULL != voltage_table),
L_3 , return 0;) ;
F_27 ((0 != count),
L_3 , return 0;) ;
for ( V_37 = 0 ; V_37 < V_84 ; V_37 ++ ) {
if ( V_102 -> V_85 [ V_37 ] . V_68 >= V_101 )
return V_37 ;
}
return V_37 - 1 ;
}
T_2 F_37 ( struct V_76 * V_103 , T_2 V_89 )
{
T_3 V_37 ;
for ( V_37 = 0 ; V_37 < V_103 -> V_84 ; V_37 ++ ) {
if ( V_103 -> V_85 [ V_37 ] . V_68 >= V_89 )
return V_103 -> V_85 [ V_37 ] . V_68 ;
}
F_27 (false,
L_10 ,
return vddci_table->entries[i-1].value) ;
}
int F_38 ( void * V_81 ,
T_3 V_68 , T_3 * V_104 )
{
int V_36 = - V_7 ;
T_3 V_37 ;
struct V_95 * V_96 = (struct V_95 * ) V_81 ;
for ( V_37 = 0 ; V_37 < V_96 -> V_84 ; V_37 ++ ) {
if ( V_68 == V_96 -> V_22 [ V_37 ] . V_68 ) {
* V_104 = V_37 ;
V_36 = 0 ;
}
}
return V_36 ;
}
int F_39 ( struct V_5 * V_6 ,
T_5 * V_90 ,
T_2 V_105 , T_6 * V_106 )
{
T_1 V_107 ;
T_1 V_108 ;
struct V_109 * V_110 =
(struct V_109 * ) ( V_6 -> V_111 ) ;
F_27 (lookup_table->count != 0 , L_11 , return -EINVAL) ;
for ( V_107 = 0 ; V_107 < V_110 -> V_112 -> V_84 ; V_107 ++ ) {
V_108 = V_110 -> V_112 -> V_85 [ V_107 ] . V_113 ;
if ( V_90 -> V_85 [ V_108 ] . V_91 == V_105 )
break;
}
F_27 (entryId < table_info->vdd_dep_on_sclk->count,
L_12 ,
return -EINVAL;
) ;
* V_106 = V_110 -> V_112 -> V_85 [ V_107 ] . V_114 ;
return 0 ;
}
int F_40 ( struct V_5 * V_6 )
{
T_3 V_115 ;
struct V_116 * V_117 ;
struct V_109 * V_118 = (struct V_109 * ) ( V_6 -> V_111 ) ;
V_115 = sizeof( T_3 ) + 4 * sizeof( struct V_119 ) ;
V_117 = F_3 ( V_115 , V_8 ) ;
if ( NULL == V_117 ) {
F_16 ( L_13 ) ;
return - V_9 ;
} else {
V_117 -> V_84 = 4 ;
V_117 -> V_85 [ 0 ] . V_114 = V_120 ;
V_117 -> V_85 [ 0 ] . V_121 = 0 ;
V_117 -> V_85 [ 1 ] . V_114 = V_122 ;
V_117 -> V_85 [ 1 ] . V_121 = 720 ;
V_117 -> V_85 [ 2 ] . V_114 = V_123 ;
V_117 -> V_85 [ 2 ] . V_121 = 810 ;
V_117 -> V_85 [ 3 ] . V_114 = V_124 ;
V_117 -> V_85 [ 3 ] . V_121 = 900 ;
if ( V_118 != NULL )
V_118 -> V_125 = V_117 ;
V_6 -> V_126 . V_125 = V_117 ;
}
return 0 ;
}
T_3 F_41 ( struct V_5 * V_6 , T_3 V_69 )
{
T_3 V_127 = 0 ;
while ( 0 == ( V_69 & ( 1 << V_127 ) ) )
V_127 ++ ;
return V_127 ;
}
void F_42 ( struct V_5 * V_6 )
{
struct V_109 * V_110 =
(struct V_109 * ) V_6 -> V_111 ;
struct V_116 * V_81 =
V_110 -> V_125 ;
struct T_4 * V_128 ;
enum V_129 V_130 = V_6 -> V_130 ;
T_3 V_131 = 0 , V_132 , V_37 ;
if ( ! V_81 || V_81 -> V_84 <= 0
|| V_130 < V_120
|| V_130 > V_124 )
return;
for ( V_37 = 0 ; V_37 < V_81 -> V_84 ; V_37 ++ ) {
if ( V_130 == V_81 -> V_85 [ V_37 ] . V_114 ) {
V_131 = V_81 -> V_85 [ V_37 ] . V_121 ;
break;
}
}
V_128 = V_110 -> V_112 ;
for ( V_37 = 0 ; V_37 < V_128 -> V_84 ; V_37 ++ ) {
if ( V_131 <= V_128 -> V_85 [ V_37 ] . V_1 ) {
V_132 = ( ( ( T_3 ) V_128 -> V_85 [ V_37 ] . V_1 ) * V_2 ) ;
F_43 ( V_6 -> V_10 ,
V_133 , V_132 ) ;
return;
}
}
F_16 ( L_14
L_15 ) ;
}
void F_4 ( struct V_5 * V_6 )
{
F_44 ( V_6 -> V_72 . V_73 , V_134 ) ;
F_44 ( V_6 -> V_72 . V_73 , V_135 ) ;
F_44 ( V_6 -> V_72 . V_73 , V_136 ) ;
F_44 ( V_6 -> V_72 . V_73 , V_137 ) ;
F_44 ( V_6 -> V_72 . V_73 , V_138 ) ;
F_44 ( V_6 -> V_72 . V_73 , V_139 ) ;
F_44 ( V_6 -> V_72 . V_73 , V_140 ) ;
F_44 ( V_6 -> V_72 . V_73 , V_141 ) ;
F_44 ( V_6 -> V_72 . V_73 , V_142 ) ;
F_45 ( V_6 -> V_72 . V_73 , V_143 ) ;
F_44 ( V_6 -> V_72 . V_73 , V_144 ) ;
F_44 ( V_6 -> V_72 . V_73 , V_145 ) ;
F_44 ( V_6 -> V_72 . V_73 , V_146 ) ;
F_44 ( V_6 -> V_72 . V_73 , V_147 ) ;
F_44 ( V_6 -> V_72 . V_73 , V_148 ) ;
F_44 ( V_6 -> V_72 . V_73 , V_149 ) ;
F_44 ( V_6 -> V_72 . V_73 , V_150 ) ;
F_45 ( V_6 -> V_72 . V_73 , V_151 ) ;
F_45 ( V_6 -> V_72 . V_73 , V_152 ) ;
if ( F_46 ( V_6 -> V_12 , V_153 ) &&
F_46 ( V_6 -> V_12 , V_154 ) )
F_45 ( V_6 -> V_72 . V_73 , V_147 ) ;
F_45 ( V_6 -> V_72 . V_73 ,
V_155 ) ;
F_45 ( V_6 -> V_72 . V_73 ,
V_156 ) ;
F_45 ( V_6 -> V_72 . V_73 ,
V_157 ) ;
F_45 ( V_6 -> V_72 . V_73 ,
V_158 ) ;
F_45 ( V_6 -> V_72 . V_73 ,
V_159 ) ;
F_45 ( V_6 -> V_72 . V_73 ,
V_160 ) ;
return;
}
int F_5 ( struct V_5 * V_6 )
{
if ( V_6 -> V_15 & V_161 )
F_45 ( V_6 -> V_72 . V_73 ,
V_162 ) ;
else
F_44 ( V_6 -> V_72 . V_73 ,
V_162 ) ;
if ( V_6 -> V_15 & V_163 ) {
F_45 ( V_6 -> V_72 . V_73 ,
V_164 ) ;
F_45 ( V_6 -> V_72 . V_73 ,
V_165 ) ;
} else {
F_44 ( V_6 -> V_72 . V_73 ,
V_164 ) ;
F_44 ( V_6 -> V_72 . V_73 ,
V_165 ) ;
}
return 0 ;
}
int F_47 ( struct V_5 * V_6 , T_1 V_166 ,
T_3 V_106 , T_2 V_55 , T_2 * V_101 )
{
T_3 V_167 ;
int V_58 = 0 ;
if ( V_6 -> V_14 < V_30 ) {
V_58 = F_48 ( V_6 , V_55 , V_101 ) ;
} else if ( V_6 -> V_14 < V_33 ) {
V_58 = F_49 ( V_6 , V_166 , V_106 , V_55 , V_101 ) ;
if ( * V_101 >= 2000 || * V_101 == 0 )
* V_101 = 1150 ;
} else {
V_58 = F_50 ( V_6 , V_166 , V_106 , V_55 , & V_167 ) ;
* V_101 = ( T_2 ) ( V_167 / 100 ) ;
}
return V_58 ;
}
int F_10 ( struct V_5 * V_6 )
{
F_45 ( V_6 -> V_72 . V_73 ,
V_168 ) ;
F_45 ( V_6 -> V_72 . V_73 ,
V_169 ) ;
F_45 ( V_6 -> V_72 . V_73 ,
V_170 ) ;
F_45 ( V_6 -> V_72 . V_73 ,
V_171 ) ;
if ( V_6 -> V_14 != V_33 )
F_45 ( V_6 -> V_72 . V_73 ,
V_172 ) ;
if ( V_6 -> V_14 != V_32 ) {
F_45 ( V_6 -> V_72 . V_73 ,
V_173 ) ;
F_45 ( V_6 -> V_72 . V_73 ,
V_174 ) ;
F_45 ( V_6 -> V_72 . V_73 ,
V_175 ) ;
}
return 0 ;
}
int F_9 ( struct V_5 * V_6 )
{
F_44 ( V_6 -> V_72 . V_73 ,
V_168 ) ;
F_44 ( V_6 -> V_72 . V_73 ,
V_173 ) ;
F_44 ( V_6 -> V_72 . V_73 ,
V_174 ) ;
F_44 ( V_6 -> V_72 . V_73 ,
V_175 ) ;
F_45 ( V_6 -> V_72 . V_73 ,
V_171 ) ;
return 0 ;
}
int F_8 ( struct V_5 * V_6 )
{
F_44 ( V_6 -> V_72 . V_73 ,
V_168 ) ;
F_44 ( V_6 -> V_72 . V_73 ,
V_173 ) ;
F_44 ( V_6 -> V_72 . V_73 ,
V_174 ) ;
F_44 ( V_6 -> V_72 . V_73 ,
V_175 ) ;
F_44 ( V_6 -> V_72 . V_73 ,
V_74 ) ;
F_44 ( V_6 -> V_72 . V_73 ,
V_75 ) ;
F_45 ( V_6 -> V_72 . V_73 ,
V_171 ) ;
return 0 ;
}
int F_7 ( struct V_5 * V_6 )
{
F_44 ( V_6 -> V_72 . V_73 ,
V_168 ) ;
F_44 ( V_6 -> V_72 . V_73 ,
V_173 ) ;
F_44 ( V_6 -> V_72 . V_73 ,
V_174 ) ;
F_44 ( V_6 -> V_72 . V_73 ,
V_175 ) ;
F_45 ( V_6 -> V_72 . V_73 ,
V_171 ) ;
F_45 ( V_6 -> V_72 . V_73 ,
V_176 ) ;
return 0 ;
}
