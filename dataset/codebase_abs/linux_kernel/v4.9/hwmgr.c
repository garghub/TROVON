T_1 F_1 ( T_2 V_1 )
{
return ( T_1 ) ( ( 6200 - ( V_1 * V_2 ) ) / 25 ) ;
}
int F_2 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_7 * V_8 ;
if ( ( V_6 == NULL ) || ( V_4 == NULL ) )
return - V_9 ;
V_8 = F_3 ( sizeof( struct V_7 ) , V_10 ) ;
if ( V_8 == NULL )
return - V_11 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_12 = V_6 -> V_13 ;
V_8 -> V_14 = V_4 -> V_14 ;
V_8 -> V_15 = V_4 -> V_15 ;
V_8 -> V_16 = V_4 -> V_16 ;
V_8 -> V_17 = V_18 ;
V_8 -> V_19 = V_20 ;
V_8 -> V_21 = V_22 ;
F_4 ( V_8 ) ;
F_5 ( V_8 ) ;
switch ( V_8 -> V_15 ) {
case V_23 :
F_6 ( V_8 ) ;
break;
case V_24 :
switch ( V_8 -> V_16 ) {
case V_25 :
F_7 ( V_8 ) ;
V_8 -> V_26 &= ~ ( V_27 |
V_28 |
V_29 ) ;
V_8 -> V_21 = V_30 ;
break;
case V_31 :
F_8 ( V_8 ) ;
V_8 -> V_26 &= ~ ( V_27 |
V_28 ) ;
break;
case V_32 :
F_9 ( V_8 ) ;
V_8 -> V_26 &= ~ ( V_27 |
V_28 |
V_29 ) ;
break;
case V_33 :
case V_34 :
F_10 ( V_8 ) ;
V_8 -> V_26 &= ~ ( V_35 ) ;
break;
default:
return - V_9 ;
}
F_11 ( V_8 ) ;
break;
default:
return - V_9 ;
}
return 0 ;
}
int F_12 ( struct V_7 * V_8 )
{
if ( V_8 == NULL || V_8 -> V_36 == NULL )
return - V_9 ;
F_13 ( V_8 -> V_37 ) ;
F_13 ( V_8 -> V_38 ) ;
F_13 ( V_8 -> V_39 . V_40 ) ;
F_13 ( V_8 -> V_41 . V_40 ) ;
F_13 ( V_8 -> V_36 ) ;
F_13 ( V_8 -> V_42 ) ;
F_13 ( V_8 -> V_43 ) ;
F_13 ( V_8 ) ;
return 0 ;
}
int F_14 ( struct V_7 * V_8 )
{
int V_44 ;
unsigned int V_45 ;
unsigned int V_46 ;
struct V_47 * V_48 ;
int V_49 ;
if ( V_8 -> V_50 -> V_51 == NULL )
return - V_9 ;
if ( V_8 -> V_50 -> V_52 == NULL )
return - V_9 ;
V_8 -> V_53 = V_46 = V_8 -> V_50 -> V_51 ( V_8 ) ;
V_8 -> V_54 = V_49 = V_8 -> V_50 -> V_52 ( V_8 ) +
sizeof( struct V_47 ) ;
V_8 -> V_36 = F_3 ( V_49 * V_46 , V_10 ) ;
if ( V_8 -> V_36 == NULL )
return - V_11 ;
V_8 -> V_43 = F_3 ( V_49 , V_10 ) ;
if ( V_8 -> V_43 == NULL )
return - V_11 ;
V_8 -> V_42 = F_3 ( V_49 , V_10 ) ;
if ( V_8 -> V_42 == NULL )
return - V_11 ;
V_48 = V_8 -> V_36 ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ ) {
V_44 = V_8 -> V_50 -> V_55 ( V_8 , V_45 , V_48 ) ;
if ( V_48 -> V_56 . V_57 & V_58 ) {
V_8 -> V_59 = V_48 ;
memcpy ( V_8 -> V_42 , V_48 , V_49 ) ;
memcpy ( V_8 -> V_43 , V_48 , V_49 ) ;
}
V_48 -> V_60 = V_45 + 1 ;
if ( V_48 -> V_56 . V_57 & V_61 )
V_8 -> V_62 = V_48 ;
V_48 = (struct V_47 * ) ( ( unsigned long ) V_48 + V_49 ) ;
}
return 0 ;
}
int F_15 ( struct V_7 * V_8 , T_3 V_63 ,
T_3 V_64 , T_3 V_65 )
{
T_3 V_45 ;
T_3 V_66 ;
if ( V_8 == NULL || V_8 -> V_14 == NULL ) {
F_16 ( V_67 L_1 ) ;
return - V_9 ;
}
for ( V_45 = 0 ; V_45 < V_8 -> V_17 ; V_45 ++ ) {
V_66 = F_17 ( V_8 -> V_14 , V_63 ) ;
if ( ( V_66 & V_65 ) == ( V_64 & V_65 ) )
break;
F_18 ( 1 ) ;
}
if ( V_45 == V_8 -> V_17 )
return - 1 ;
return 0 ;
}
void F_19 ( struct V_7 * V_8 ,
T_3 V_68 ,
T_3 V_63 ,
T_3 V_64 ,
T_3 V_65 )
{
if ( V_8 == NULL || V_8 -> V_14 == NULL ) {
F_16 ( V_67 L_1 ) ;
return;
}
F_20 ( V_8 -> V_14 , V_68 , V_63 ) ;
F_15 ( V_8 , V_68 + 1 , V_65 , V_64 ) ;
}
bool F_21 ( struct V_7 * V_8 )
{
return F_22 ( V_8 -> V_69 . V_70 , V_71 ) ;
}
bool F_23 ( struct V_7 * V_8 )
{
return F_22 ( V_8 -> V_69 . V_70 , V_72 ) ;
}
int F_24 ( struct V_73 * V_74 )
{
T_3 V_45 , V_75 ;
T_2 V_76 ;
bool V_77 = false ;
struct V_73 * V_78 ;
F_25 ((NULL != vol_table),
L_2 , return -EINVAL) ;
V_78 = F_3 ( sizeof( struct V_73 ) ,
V_10 ) ;
if ( NULL == V_78 )
return - V_9 ;
V_78 -> V_79 = V_74 -> V_79 ;
V_78 -> V_80 = V_74 -> V_80 ;
for ( V_45 = 0 ; V_45 < V_74 -> V_81 ; V_45 ++ ) {
V_76 = V_74 -> V_82 [ V_45 ] . V_64 ;
V_77 = false ;
for ( V_75 = 0 ; V_75 < V_78 -> V_81 ; V_75 ++ ) {
if ( V_76 == V_78 -> V_82 [ V_75 ] . V_64 ) {
V_77 = true ;
break;
}
}
if ( ! V_77 ) {
V_78 -> V_82 [ V_78 -> V_81 ] . V_64 = V_76 ;
V_78 -> V_82 [ V_78 -> V_81 ] . V_83 =
V_74 -> V_82 [ V_45 ] . V_83 ;
V_78 -> V_81 ++ ;
}
}
memcpy ( V_74 , V_78 , sizeof( struct V_73 ) ) ;
F_13 ( V_78 ) ;
return 0 ;
}
int F_26 ( struct V_73 * V_74 ,
T_4 * V_84 )
{
T_3 V_45 ;
int V_44 ;
F_25 ((0 != dep_table->count),
L_3 , return -EINVAL) ;
F_25 ((NULL != vol_table),
L_4 , return -EINVAL) ;
V_74 -> V_79 = 0 ;
V_74 -> V_80 = 0 ;
V_74 -> V_81 = V_84 -> V_81 ;
for ( V_45 = 0 ; V_45 < V_84 -> V_81 ; V_45 ++ ) {
V_74 -> V_82 [ V_45 ] . V_64 = V_84 -> V_82 [ V_45 ] . V_85 ;
V_74 -> V_82 [ V_45 ] . V_83 = 0 ;
}
V_44 = F_24 ( V_74 ) ;
F_25 ((0 == result),
L_5 , return result) ;
return 0 ;
}
int F_27 ( struct V_73 * V_74 ,
T_4 * V_84 )
{
T_3 V_45 ;
int V_44 ;
F_25 ((0 != dep_table->count),
L_3 , return -EINVAL) ;
F_25 ((NULL != vol_table),
L_4 , return -EINVAL) ;
V_74 -> V_79 = 0 ;
V_74 -> V_80 = 0 ;
V_74 -> V_81 = V_84 -> V_81 ;
for ( V_45 = 0 ; V_45 < V_84 -> V_81 ; V_45 ++ ) {
V_74 -> V_82 [ V_45 ] . V_64 = V_84 -> V_82 [ V_45 ] . V_86 ;
V_74 -> V_82 [ V_45 ] . V_83 = 0 ;
}
V_44 = F_24 ( V_74 ) ;
F_25 ((0 == result),
L_6 , return result) ;
return 0 ;
}
int F_28 ( struct V_73 * V_74 ,
T_5 * V_87 )
{
int V_45 = 0 ;
F_25 ((0 != lookup_table->count),
L_7 , return -EINVAL) ;
F_25 ((NULL != vol_table),
L_4 , return -EINVAL) ;
V_74 -> V_79 = 0 ;
V_74 -> V_80 = 0 ;
V_74 -> V_81 = V_87 -> V_81 ;
for ( V_45 = 0 ; V_45 < V_74 -> V_81 ; V_45 ++ ) {
V_74 -> V_82 [ V_45 ] . V_64 = V_87 -> V_82 [ V_45 ] . V_88 ;
V_74 -> V_82 [ V_45 ] . V_83 = 0 ;
}
return 0 ;
}
void F_29 ( T_3 V_89 ,
struct V_73 * V_74 )
{
unsigned int V_45 , V_90 ;
if ( V_74 -> V_81 <= V_89 )
return;
V_90 = V_74 -> V_81 - V_89 ;
for ( V_45 = 0 ; V_45 < V_89 ; V_45 ++ )
V_74 -> V_82 [ V_45 ] = V_74 -> V_82 [ V_45 + V_90 ] ;
V_74 -> V_81 = V_89 ;
return;
}
int F_30 ( void * V_78 ,
T_3 V_81 , int V_91 )
{
int V_45 ;
struct V_92 * V_93 = (struct V_92 * ) V_78 ;
V_93 -> V_81 = V_81 > V_91 ? V_91 : V_81 ;
for ( V_45 = 0 ; V_45 < V_93 -> V_81 ; V_45 ++ )
V_93 -> V_94 [ V_45 ] . V_95 = false ;
return 0 ;
}
void F_31 (
void * V_78 ,
T_3 V_63 , T_3 V_96 ,
T_3 V_97 )
{
struct V_92 * V_93 = (struct V_92 * ) V_78 ;
V_93 -> V_94 [ V_63 ] . V_64 = V_96 ;
V_93 -> V_94 [ V_63 ] . V_98 = V_97 ;
V_93 -> V_94 [ V_63 ] . V_95 = 1 ;
}
T_6 F_32 ( void * V_78 )
{
T_6 V_45 ;
T_6 V_65 = 0 ;
struct V_92 * V_93 = (struct V_92 * ) V_78 ;
for ( V_45 = V_93 -> V_81 ; V_45 > 0 ; V_45 -- ) {
V_65 = V_65 << 1 ;
if ( V_93 -> V_94 [ V_45 - 1 ] . V_95 )
V_65 |= 0x1 ;
else
V_65 &= 0xFFFFFFFE ;
}
return V_65 ;
}
T_1 F_33 (
struct T_5 * V_87 , T_2 V_99 )
{
T_1 V_81 = ( T_1 ) ( V_87 -> V_81 ) ;
T_1 V_45 ;
F_25 ((NULL != lookup_table),
L_8 , return 0 ) ;
F_25 ((0 != count),
L_8 , return 0 ) ;
for ( V_45 = 0 ; V_45 < V_87 -> V_81 ; V_45 ++ ) {
if ( V_87 -> V_82 [ V_45 ] . V_88 >= V_99 )
return V_45 ;
}
return V_45 - 1 ;
}
T_1 F_34 ( V_73 * V_100 ,
T_3 V_99 )
{
T_1 V_81 = ( T_1 ) ( V_100 -> V_81 ) ;
T_1 V_45 = 0 ;
F_25 ((NULL != voltage_table),
L_2 , return 0;) ;
F_25 ((0 != count),
L_2 , return 0;) ;
for ( V_45 = 0 ; V_45 < V_81 ; V_45 ++ ) {
if ( V_100 -> V_82 [ V_45 ] . V_64 >= V_99 )
return V_45 ;
}
return V_45 - 1 ;
}
T_2 F_35 ( struct V_73 * V_101 , T_2 V_86 )
{
T_3 V_45 ;
for ( V_45 = 0 ; V_45 < V_101 -> V_81 ; V_45 ++ ) {
if ( V_101 -> V_82 [ V_45 ] . V_64 >= V_86 )
return V_101 -> V_82 [ V_45 ] . V_64 ;
}
F_25 (false,
L_9 ,
return vddci_table->entries[i-1].value) ;
}
int F_36 ( void * V_78 ,
T_3 V_64 , T_3 * V_102 )
{
int V_44 = - V_9 ;
T_3 V_45 ;
struct V_92 * V_93 = (struct V_92 * ) V_78 ;
for ( V_45 = 0 ; V_45 < V_93 -> V_81 ; V_45 ++ ) {
if ( V_64 == V_93 -> V_94 [ V_45 ] . V_64 ) {
* V_102 = V_45 ;
V_44 = 0 ;
}
}
return V_44 ;
}
int F_37 ( struct V_7 * V_8 ,
T_5 * V_87 ,
T_2 V_103 , T_6 * V_104 )
{
T_1 V_105 ;
T_1 V_106 ;
struct V_107 * V_108 =
(struct V_107 * ) ( V_8 -> V_109 ) ;
F_25 (lookup_table->count != 0 , L_10 , return -EINVAL) ;
for ( V_105 = 0 ; V_105 < V_108 -> V_110 -> V_81 ; V_105 ++ ) {
V_106 = V_108 -> V_110 -> V_82 [ V_105 ] . V_111 ;
if ( V_87 -> V_82 [ V_106 ] . V_88 == V_103 )
break;
}
F_25 (entryId < table_info->vdd_dep_on_sclk->count,
L_11 ,
return -EINVAL;
) ;
* V_104 = V_108 -> V_110 -> V_82 [ V_105 ] . V_112 ;
return 0 ;
}
int F_38 ( struct V_7 * V_8 )
{
T_3 V_113 ;
struct V_114 * V_115 ;
struct V_107 * V_116 = (struct V_107 * ) ( V_8 -> V_109 ) ;
V_113 = sizeof( T_3 ) + 4 * sizeof( struct V_117 ) ;
V_115 = F_3 ( V_113 , V_10 ) ;
if ( NULL == V_115 ) {
F_16 ( V_67 L_12 ) ;
return - V_11 ;
} else {
V_115 -> V_81 = 4 ;
V_115 -> V_82 [ 0 ] . V_112 = V_118 ;
V_115 -> V_82 [ 0 ] . V_119 = 0 ;
V_115 -> V_82 [ 1 ] . V_112 = V_120 ;
V_115 -> V_82 [ 1 ] . V_119 = 720 ;
V_115 -> V_82 [ 2 ] . V_112 = V_121 ;
V_115 -> V_82 [ 2 ] . V_119 = 810 ;
V_115 -> V_82 [ 3 ] . V_112 = V_122 ;
V_115 -> V_82 [ 3 ] . V_119 = 900 ;
if ( V_116 != NULL )
V_116 -> V_123 = V_115 ;
V_8 -> V_124 . V_123 = V_115 ;
}
return 0 ;
}
int F_39 ( struct V_7 * V_8 )
{
if ( NULL != V_8 -> V_124 . V_123 ) {
F_13 ( V_8 -> V_124 . V_123 ) ;
V_8 -> V_124 . V_123 = NULL ;
}
if ( NULL != V_8 -> V_38 ) {
F_13 ( V_8 -> V_38 ) ;
V_8 -> V_38 = NULL ;
}
return 0 ;
}
T_3 F_40 ( struct V_7 * V_8 , T_3 V_65 )
{
T_3 V_125 = 0 ;
while ( 0 == ( V_65 & ( 1 << V_125 ) ) )
V_125 ++ ;
return V_125 ;
}
void F_41 ( struct V_7 * V_8 )
{
struct V_107 * V_108 =
(struct V_107 * ) V_8 -> V_109 ;
struct V_114 * V_78 =
V_108 -> V_123 ;
struct T_4 * V_126 ;
enum V_127 V_128 = V_8 -> V_128 ;
T_3 V_129 = 0 , V_130 , V_45 ;
if ( ! V_78 || V_78 -> V_81 <= 0
|| V_128 < V_118
|| V_128 > V_122 )
return;
for ( V_45 = 0 ; V_45 < V_78 -> V_81 ; V_45 ++ ) {
if ( V_128 == V_78 -> V_82 [ V_45 ] . V_112 ) {
V_129 = V_78 -> V_82 [ V_45 ] . V_119 ;
break;
}
}
V_126 = V_108 -> V_110 ;
for ( V_45 = 0 ; V_45 < V_126 -> V_81 ; V_45 ++ ) {
if ( V_129 <= V_126 -> V_82 [ V_45 ] . V_1 ) {
V_130 = ( ( ( T_3 ) V_126 -> V_82 [ V_45 ] . V_1 ) * V_2 ) ;
F_42 ( V_8 -> V_12 ,
V_131 , V_130 ) ;
return;
}
}
F_16 ( V_67 L_13
L_14 ) ;
}
void F_4 ( struct V_7 * V_8 )
{
F_43 ( V_8 -> V_69 . V_70 , V_132 ) ;
F_43 ( V_8 -> V_69 . V_70 , V_133 ) ;
F_43 ( V_8 -> V_69 . V_70 , V_134 ) ;
F_43 ( V_8 -> V_69 . V_70 , V_135 ) ;
F_43 ( V_8 -> V_69 . V_70 , V_136 ) ;
F_43 ( V_8 -> V_69 . V_70 , V_137 ) ;
F_43 ( V_8 -> V_69 . V_70 , V_138 ) ;
F_43 ( V_8 -> V_69 . V_70 , V_139 ) ;
F_43 ( V_8 -> V_69 . V_70 , V_140 ) ;
F_44 ( V_8 -> V_69 . V_70 , V_141 ) ;
F_43 ( V_8 -> V_69 . V_70 , V_142 ) ;
F_43 ( V_8 -> V_69 . V_70 , V_143 ) ;
F_43 ( V_8 -> V_69 . V_70 , V_144 ) ;
F_43 ( V_8 -> V_69 . V_70 , V_145 ) ;
F_43 ( V_8 -> V_69 . V_70 , V_146 ) ;
F_43 ( V_8 -> V_69 . V_70 , V_147 ) ;
F_43 ( V_8 -> V_69 . V_70 , V_148 ) ;
F_44 ( V_8 -> V_69 . V_70 , V_149 ) ;
F_44 ( V_8 -> V_69 . V_70 , V_150 ) ;
if ( F_45 ( V_8 -> V_14 , V_151 ) &&
F_45 ( V_8 -> V_14 , V_152 ) )
F_44 ( V_8 -> V_69 . V_70 , V_145 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_153 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_154 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_155 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_156 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_157 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_158 ) ;
return;
}
int F_5 ( struct V_7 * V_8 )
{
if ( V_159 )
F_44 ( V_8 -> V_69 . V_70 ,
V_160 ) ;
else
F_43 ( V_8 -> V_69 . V_70 ,
V_160 ) ;
if ( V_161 )
F_44 ( V_8 -> V_69 . V_70 ,
V_162 ) ;
else
F_43 ( V_8 -> V_69 . V_70 ,
V_162 ) ;
V_8 -> V_26 = V_163 ;
return 0 ;
}
int F_46 ( struct V_7 * V_8 , T_1 V_164 ,
T_3 V_104 , T_2 V_60 , T_2 * V_99 )
{
T_3 V_165 ;
int V_166 = 0 ;
if ( V_8 -> V_16 < V_31 ) {
V_166 = F_47 ( V_8 , V_60 , V_99 ) ;
} else if ( V_8 -> V_16 < V_34 ) {
V_166 = F_48 ( V_8 , V_164 , V_104 , V_60 , V_99 ) ;
if ( * V_99 >= 2000 || * V_99 == 0 )
* V_99 = 1150 ;
} else {
V_166 = F_49 ( V_8 , V_164 , V_104 , V_60 , & V_165 ) ;
* V_99 = ( T_2 ) ( V_165 / 100 ) ;
}
return V_166 ;
}
int F_10 ( struct V_7 * V_8 )
{
F_44 ( V_8 -> V_69 . V_70 ,
V_167 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_168 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_169 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_170 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_171 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_172 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_173 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_174 ) ;
if ( V_8 -> V_16 == V_33 )
F_44 ( V_8 -> V_69 . V_70 ,
V_175 ) ;
return 0 ;
}
int F_9 ( struct V_7 * V_8 )
{
F_43 ( V_8 -> V_69 . V_70 ,
V_167 ) ;
F_43 ( V_8 -> V_69 . V_70 ,
V_168 ) ;
F_43 ( V_8 -> V_69 . V_70 ,
V_169 ) ;
F_43 ( V_8 -> V_69 . V_70 ,
V_170 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_174 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_171 ) ;
return 0 ;
}
int F_8 ( struct V_7 * V_8 )
{
F_43 ( V_8 -> V_69 . V_70 ,
V_167 ) ;
F_43 ( V_8 -> V_69 . V_70 ,
V_168 ) ;
F_43 ( V_8 -> V_69 . V_70 ,
V_169 ) ;
F_43 ( V_8 -> V_69 . V_70 ,
V_170 ) ;
F_43 ( V_8 -> V_69 . V_70 ,
V_71 ) ;
F_43 ( V_8 -> V_69 . V_70 ,
V_72 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_174 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_171 ) ;
return 0 ;
}
int F_7 ( struct V_7 * V_8 )
{
F_43 ( V_8 -> V_69 . V_70 ,
V_167 ) ;
F_43 ( V_8 -> V_69 . V_70 ,
V_168 ) ;
F_43 ( V_8 -> V_69 . V_70 ,
V_169 ) ;
F_43 ( V_8 -> V_69 . V_70 ,
V_170 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_174 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_171 ) ;
F_44 ( V_8 -> V_69 . V_70 ,
V_176 ) ;
return 0 ;
}
