static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned V_7 )
{
int V_8 ;
if ( V_7 > V_6 -> V_9 )
return - V_10 ;
if ( V_4 -> V_11 ) {
F_2 ( L_1 ) ;
return - V_12 ;
}
if ( V_6 -> V_13 ) {
F_2 ( L_2 ) ;
return - V_12 ;
}
if ( ! V_6 -> V_14 )
return - V_15 ;
V_7 = ( V_7 + V_16 - 1 ) & V_17 ;
V_8 = F_3 ( V_2 , V_4 , V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_4 -> V_18 ) {
V_8 = V_4 -> V_18 ( V_2 , V_4 , V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
}
F_2 ( L_3 ,
V_2 -> V_19 , ( int ) ( V_4 - V_2 -> V_20 ) , V_6 -> V_21 ) ;
return 0 ;
}
static T_1 F_4 ( struct V_22 * V_2 ,
struct V_23 * V_24 , char * V_25 )
{
T_1 V_8 ;
struct V_26 * V_27 = F_5 ( V_2 ) ;
unsigned V_28 = 0 ;
struct V_3 * const V_29 =
F_6 ( V_27 ) ;
F_7 ( & V_27 -> V_22 -> V_30 ) ;
if ( V_29 &&
( V_29 -> V_31 & V_32 ) &&
V_29 -> V_6 ) {
V_28 = V_29 -> V_6 -> V_9 /
V_33 ;
}
V_8 = snprintf ( V_25 , V_16 , L_4 , V_28 ) ;
F_8 ( & V_27 -> V_22 -> V_30 ) ;
return V_8 ;
}
static T_1 F_9 ( struct V_22 * V_2 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_34 )
{
struct V_26 * V_27 = F_5 ( V_2 ) ;
unsigned int V_35 ;
unsigned int V_36 ;
int V_37 ;
struct V_3 * const V_29 =
F_6 ( V_27 ) ;
V_37 = F_10 ( V_25 , 10 , & V_35 ) ;
if ( V_37 )
return V_37 ;
if ( V_35 > ( V_38 / V_33 ) )
return - V_15 ;
V_36 = V_35 * V_33 ;
F_7 ( & V_27 -> V_22 -> V_30 ) ;
if ( V_29 == NULL ||
( V_29 -> V_31 & V_32 ) == 0 ||
V_29 -> V_6 == NULL ) {
F_8 ( & V_27 -> V_22 -> V_30 ) ;
return - V_15 ;
}
V_29 -> V_6 -> V_9 = V_36 ;
F_8 ( & V_27 -> V_22 -> V_30 ) ;
return V_34 ;
}
static T_1 F_11 ( struct V_22 * V_2 ,
struct V_23 * V_24 , char * V_25 )
{
T_1 V_8 ;
struct V_26 * V_27 = F_5 ( V_2 ) ;
unsigned V_39 = 0 ;
struct V_3 * const V_29 =
F_6 ( V_27 ) ;
F_7 ( & V_27 -> V_22 -> V_30 ) ;
if ( V_29 &&
( V_29 -> V_31 & V_32 ) &&
V_29 -> V_6 ) {
V_39 = V_29 -> V_6 -> V_21 /
V_33 ;
}
V_8 = snprintf ( V_25 , V_16 , L_4 , V_39 ) ;
F_8 ( & V_27 -> V_22 -> V_30 ) ;
return V_8 ;
}
static T_1 F_12 ( struct V_22 * V_2 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_34 )
{
struct V_26 * V_27 = F_5 ( V_2 ) ;
unsigned int V_40 ;
unsigned int V_7 ;
int V_8 ;
int V_37 ;
struct V_3 * const V_29 =
F_6 ( V_27 ) ;
V_37 = F_10 ( V_25 , 10 , & V_40 ) ;
if ( V_37 )
return V_37 ;
if ( V_40 > ( V_38 / V_33 ) )
return - V_15 ;
V_7 = V_40 * V_33 ;
F_7 ( & V_27 -> V_22 -> V_30 ) ;
if ( V_29 == NULL ||
( V_29 -> V_31 & V_32 ) == 0 ||
V_29 -> V_6 == NULL ) {
F_8 ( & V_27 -> V_22 -> V_30 ) ;
return - V_15 ;
}
V_8 = F_1 ( V_27 -> V_22 , V_29 ,
V_29 -> V_6 , V_7 ) ;
F_8 ( & V_27 -> V_22 -> V_30 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_34 ;
}
static T_1 F_13 ( struct V_22 * V_2 ,
struct V_23 * V_24 ,
char * V_25 )
{
T_1 V_8 ;
struct V_26 * V_27 = F_5 ( V_2 ) ;
unsigned V_28 = 0 ;
struct V_3 * const V_41 =
F_14 ( V_27 ) ;
F_7 ( & V_27 -> V_22 -> V_30 ) ;
if ( V_41 &&
( V_41 -> V_31 & V_42 ) &&
V_41 -> V_6 ) {
V_28 = V_41 -> V_6 -> V_9 /
V_33 ;
}
V_8 = snprintf ( V_25 , V_16 , L_4 , V_28 ) ;
F_8 ( & V_27 -> V_22 -> V_30 ) ;
return V_8 ;
}
static T_1 F_15 ( struct V_22 * V_2 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_34 )
{
struct V_26 * V_27 = F_5 ( V_2 ) ;
unsigned int V_35 ;
unsigned int V_36 ;
int V_37 ;
struct V_3 * const V_41 =
F_14 ( V_27 ) ;
V_37 = F_10 ( V_25 , 10 , & V_35 ) ;
if ( V_37 )
return V_37 ;
if ( V_35 > ( V_38 / V_33 ) )
return - V_15 ;
V_36 = V_35 * V_33 ;
F_7 ( & V_27 -> V_22 -> V_30 ) ;
if ( V_41 == NULL ||
( V_41 -> V_31 & V_42 ) == 0 ||
V_41 -> V_6 == NULL ) {
F_8 ( & V_27 -> V_22 -> V_30 ) ;
return - V_15 ;
}
V_41 -> V_6 -> V_9 = V_36 ;
F_8 ( & V_27 -> V_22 -> V_30 ) ;
return V_34 ;
}
static T_1 F_16 ( struct V_22 * V_2 ,
struct V_23 * V_24 , char * V_25 )
{
T_1 V_8 ;
struct V_26 * V_27 = F_5 ( V_2 ) ;
unsigned V_39 = 0 ;
struct V_3 * const V_41 =
F_14 ( V_27 ) ;
F_7 ( & V_27 -> V_22 -> V_30 ) ;
if ( V_41 &&
( V_41 -> V_31 & V_42 ) &&
V_41 -> V_6 ) {
V_39 = V_41 -> V_6 -> V_21 /
V_33 ;
}
V_8 = snprintf ( V_25 , V_16 , L_4 , V_39 ) ;
F_8 ( & V_27 -> V_22 -> V_30 ) ;
return V_8 ;
}
static T_1 F_17 ( struct V_22 * V_2 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_34 )
{
struct V_26 * V_27 = F_5 ( V_2 ) ;
unsigned int V_40 ;
unsigned int V_7 ;
int V_8 ;
int V_37 ;
struct V_3 * const V_41 =
F_14 ( V_27 ) ;
V_37 = F_10 ( V_25 , 10 , & V_40 ) ;
if ( V_37 )
return V_37 ;
if ( V_40 > ( V_38 / V_33 ) )
return - V_15 ;
V_7 = ( ( V_43 ) V_40 ) * V_33 ;
F_7 ( & V_27 -> V_22 -> V_30 ) ;
if ( V_41 == NULL ||
( V_41 -> V_31 & V_42 ) == 0 ||
V_41 -> V_6 == NULL ) {
F_8 ( & V_27 -> V_22 -> V_30 ) ;
return - V_15 ;
}
V_8 = F_1 ( V_27 -> V_22 , V_41 ,
V_41 -> V_6 , V_7 ) ;
F_8 ( & V_27 -> V_22 -> V_30 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_34 ;
}
static long F_18 ( struct V_44 * V_44 , unsigned int V_45 ,
unsigned long V_46 )
{
const unsigned V_19 = F_19 ( V_44 -> V_47 -> V_48 ) ;
struct V_26 * V_49 =
F_20 ( V_19 ) ;
struct V_1 * V_2 ;
int V_50 ;
if ( V_49 == NULL || V_49 -> V_22 == NULL )
return - V_51 ;
V_2 = V_49 -> V_22 ;
F_7 ( & V_2 -> V_30 ) ;
if ( V_45 == V_52 ) {
V_50 = F_21 ( V_2 ,
(struct V_53 V_54 * ) V_46 ) ;
goto V_55;
}
if ( ! V_2 -> V_56 ) {
F_2 ( L_5 , V_2 -> V_19 ) ;
V_50 = - V_51 ;
goto V_55;
}
switch ( V_45 ) {
case V_57 :
V_50 = F_22 ( V_2 ,
(struct V_58 V_54 * ) V_46 ) ;
break;
case V_59 :
V_50 = F_23 ( V_2 , (struct V_60 V_54 * ) V_46 ,
V_44 ) ;
break;
case V_61 :
V_50 = F_24 ( V_2 ,
(struct V_62 V_54 * ) V_46 ,
V_44 ) ;
break;
case V_63 :
V_50 = F_25 ( V_2 , ( void V_54 * ) V_46 ) ;
break;
case V_64 :
V_50 = F_26 ( V_2 , ( void V_54 * ) V_46 ) ;
break;
case V_65 :
V_50 = F_27 ( V_2 ,
(struct V_66 V_54 * ) V_46 ,
V_44 ) ;
break;
case V_67 :
V_50 = F_28 ( V_2 , V_46 , V_44 ) ;
break;
case V_68 :
V_50 = F_29 ( V_2 , V_46 , V_44 ) ;
break;
case V_69 :
V_50 = F_30 ( V_2 , V_46 , V_44 ) ;
break;
case V_70 :
V_50 = F_31 ( V_2 , (struct V_71 V_54 * ) V_46 , V_44 ) ;
break;
case V_72 :
V_50 = F_32 ( V_2 , (struct V_71 V_54 * ) V_46 ,
V_44 ) ;
break;
case V_73 :
V_50 = F_33 ( V_2 ,
(struct V_74 V_54 * ) V_46 ,
V_44 ) ;
break;
case V_75 :
V_50 = F_34 ( V_2 , (struct V_76 V_54 * ) V_46 ,
V_44 ) ;
break;
case V_77 :
V_50 = F_35 ( V_2 , V_46 , V_44 ) ;
break;
default:
V_50 = - V_78 ;
break;
}
V_55:
F_8 ( & V_2 -> V_30 ) ;
return V_50 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_53 V_54 * V_46 )
{
struct V_53 V_79 ;
int V_37 ;
unsigned char * V_80 = NULL ;
int V_81 ;
if ( ! F_36 ( V_82 ) )
return - V_10 ;
if ( V_46 == NULL ) {
if ( F_37 ( V_2 ) )
return - V_12 ;
if ( V_2 -> V_56 ) {
struct V_83 * V_84 = V_2 -> V_85 -> V_83 ;
F_38 ( V_2 ) ;
F_39 ( V_84 ) ;
}
return 0 ;
}
if ( F_40 ( & V_79 , V_46 , sizeof( struct V_53 ) ) )
return - V_86 ;
V_79 . V_87 [ V_88 - 1 ] = 0 ;
if ( F_41 ( V_79 . V_89 , 0 ) &&
V_79 . V_89 [ V_90 ] ) {
int V_91 ;
V_81 = V_79 . V_89 [ V_90 ] ;
if ( V_81 < 0 )
return - V_86 ;
V_80 = F_42 ( V_81 ) ;
if ( ! V_80 )
return - V_92 ;
if ( F_40 ( V_80 ,
F_41 ( V_79 . V_89 , 0 ) , V_81 ) ) {
F_43 ( V_80 ) ;
return - V_86 ;
}
V_79 . V_89 [ V_93 ] =
( unsigned long ) V_80 ;
if ( sizeof( void * ) > sizeof( int ) ) {
V_91 = sizeof( int ) * 8 ;
V_79 . V_89 [ V_94 ] =
( ( unsigned long ) V_80 ) >> V_91 ;
} else
V_79 . V_89 [ V_94 ] = 0 ;
}
V_37 = F_44 ( V_2 , & V_79 ) ;
if ( V_37 == 0 ) {
if ( ! F_45 ( V_2 -> V_85 -> V_83 ) ) {
F_38 ( V_2 ) ;
V_37 = - V_95 ;
}
}
if ( V_80 )
F_43 ( V_80 ) ;
return V_37 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_58 V_54 * V_46 )
{
struct V_58 V_96 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_8 = 0 ;
if ( F_40 ( & V_96 , V_46 , sizeof( struct V_58 ) ) )
return - V_86 ;
if ( V_96 . V_97 >= V_2 -> V_98 || V_96 . V_97 < 0 )
return - V_15 ;
V_4 = V_2 -> V_20 + V_96 . V_97 ;
V_6 = V_4 -> V_6 ;
if ( ! V_6 ) {
F_2 ( L_6 ) ;
V_96 . V_99 = 0 ;
V_96 . V_100 = 0 ;
goto V_101;
}
if ( V_96 . V_100 ) {
if ( ! F_36 ( V_82 ) )
return - V_10 ;
V_6 -> V_9 = V_96 . V_100 ;
}
if ( V_96 . V_99 ) {
V_8 = F_1 ( V_2 , V_4 , V_6 , V_96 . V_99 ) ;
if ( V_8 < 0 )
return V_8 ;
}
V_96 . V_99 = V_6 -> V_21 ;
V_96 . V_100 = V_6 -> V_9 ;
V_101:
if ( F_46 ( V_46 , & V_96 , sizeof( struct V_58 ) ) )
return - V_86 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_60 V_54 * V_46 ,
struct V_44 * V_44 )
{
struct V_60 V_102 ;
const unsigned V_19 = F_19 ( V_44 -> V_47 -> V_48 ) ;
struct V_26 * V_49 =
F_20 ( V_19 ) ;
struct V_3 * V_103 =
F_6 ( V_49 ) ;
struct V_3 * V_104 =
F_14 ( V_49 ) ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_105 = V_106 ;
V_102 . V_107 = V_2 -> V_98 ;
F_47 ( V_102 . V_108 , V_2 -> V_85 -> V_108 , V_88 ) ;
F_47 ( V_102 . V_87 , V_2 -> V_87 , V_88 ) ;
if ( V_103 )
V_102 . V_29 = V_103 - V_2 -> V_20 ;
else
V_102 . V_29 = - 1 ;
if ( V_104 )
V_102 . V_41 = V_104 - V_2 -> V_20 ;
else
V_102 . V_41 = - 1 ;
if ( F_46 ( V_46 , & V_102 , sizeof( struct V_60 ) ) )
return - V_86 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_62 V_54 * V_46 , void * V_44 )
{
int V_37 , V_109 ;
struct V_62 * V_110 , * V_111 ;
struct V_3 * V_4 ;
V_110 =
F_48 ( V_2 -> V_98 , sizeof( struct V_62 ) ,
V_112 ) ;
if ( ! V_110 )
return - V_92 ;
for ( V_109 = 0 ; V_109 < V_2 -> V_98 ; V_109 ++ ) {
V_4 = V_2 -> V_20 + V_109 ;
V_111 = V_110 + V_109 ;
V_111 -> type = V_4 -> type ;
V_111 -> V_113 = V_4 -> V_113 ;
V_111 -> V_114 = V_4 -> V_31 ;
if ( F_49 ( V_4 ) & V_115 )
V_111 -> V_114 |= V_116 ;
#define F_50 5
V_111 -> V_117 = F_50 ;
V_111 -> V_118 = V_4 -> V_118 ;
V_111 -> V_119 = V_4 -> V_119 ;
if ( V_4 -> V_120 ) {
V_111 -> V_121 =
( V_109 << 24 ) | ( 0 << 16 ) | ( V_4 -> V_120 -> V_122 ) ;
} else {
V_111 -> V_121 = 0 ;
}
V_111 -> V_123 = V_4 -> V_123 ;
if ( V_4 -> V_11 )
V_111 -> V_114 |= V_124 ;
if ( V_4 -> V_11 == V_44 )
V_111 -> V_114 |= V_125 ;
if ( V_4 -> V_126 )
V_111 -> V_114 |= V_127 ;
if ( V_4 -> V_126 == V_44 )
V_111 -> V_114 |= V_128 ;
if ( ! V_4 -> V_119 && V_4 -> V_129 )
V_111 -> V_114 |= V_130 ;
if ( V_4 -> V_131 )
V_111 -> V_114 |= V_132 ;
if ( V_4 -> V_133 )
V_111 -> V_114 |= V_134 ;
if ( V_4 -> V_135 )
V_111 -> V_114 |= V_136 ;
if ( V_4 -> V_137 != & V_138 )
V_111 -> V_139 = V_140 ;
else
V_111 -> V_139 = V_141 ;
V_111 -> V_142 = V_4 -> V_142 ;
}
V_37 = F_46 ( V_46 , V_110 ,
V_2 -> V_98 * sizeof( struct V_62 ) ) ;
F_51 ( V_110 ) ;
return V_37 ? - V_86 : 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_143 V_54 * V_46 )
{
struct V_3 * V_4 ;
struct V_143 V_79 ;
if ( F_40 ( & V_79 , V_46 , sizeof( struct V_143 ) ) )
return - V_86 ;
if ( V_79 . V_144 >= V_2 -> V_98 )
return - V_15 ;
V_4 = V_2 -> V_20 + V_79 . V_144 ;
if ( V_79 . V_129 ) {
if ( V_4 -> V_119 || ! V_4 -> V_129 )
return - V_15 ;
if ( F_46 ( V_79 . V_129 , V_4 -> V_129 ,
V_4 -> V_113 * sizeof( unsigned int ) ) )
return - V_86 ;
}
if ( V_79 . V_131 ) {
if ( ! V_4 -> V_131 )
return - V_15 ;
if ( F_46 ( V_79 . V_131 , V_4 -> V_131 ,
V_4 -> V_113 * sizeof( unsigned int ) ) )
return - V_86 ;
}
if ( V_79 . V_145 ) {
int V_109 ;
if ( ! V_4 -> V_133 )
return - V_15 ;
for ( V_109 = 0 ; V_109 < V_4 -> V_113 ; V_109 ++ ) {
int V_146 ;
V_146 = ( V_2 -> V_19 << 28 ) | ( V_79 . V_144 << 24 ) | ( V_109 << 16 ) |
( V_4 -> V_133 [ V_109 ] -> V_122 ) ;
if ( F_52 ( V_146 , V_79 . V_145 + V_109 ) )
return - V_86 ;
}
#if 0
if (copy_to_user(it.rangelist, s->range_type_list,
s->n_chan * sizeof(unsigned int)))
return -EFAULT;
#endif
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_66 V_54 * V_46 , void * V_44 )
{
struct V_66 V_147 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( F_40 ( & V_147 , V_46 , sizeof( struct V_66 ) ) )
return - V_86 ;
if ( V_147 . V_97 >= V_2 -> V_98 || V_147 . V_97 < 0 )
return - V_15 ;
V_4 = V_2 -> V_20 + V_147 . V_97 ;
if ( V_4 -> V_126 && V_4 -> V_126 != V_44 )
return - V_148 ;
V_6 = V_4 -> V_6 ;
if ( ! V_6 ) {
F_2 ( L_6 ) ;
V_147 . V_149 = 0 ;
V_147 . V_150 = 0 ;
V_147 . V_151 = 0 ;
V_147 . V_152 = 0 ;
V_147 . V_153 = 0 ;
V_147 . V_154 = 0 ;
goto V_101;
}
if ( ! V_4 -> V_11 ) {
V_147 . V_153 = 0 ;
V_147 . V_154 = 0 ;
goto V_155;
}
if ( V_4 -> V_11 != V_44 )
return - V_148 ;
if ( V_147 . V_153 && ( V_4 -> V_31 & V_32 ) ) {
V_147 . V_153 = F_53 ( V_6 , V_147 . V_153 ) ;
F_54 ( V_6 , V_147 . V_153 ) ;
if ( ! ( F_49 ( V_4 ) & ( V_156 |
V_115 ) )
&& V_6 -> V_151 == V_6 -> V_152 ) {
F_55 ( V_2 , V_4 ) ;
}
}
if ( V_147 . V_154 && ( V_4 -> V_31 & V_42 ) ) {
V_147 . V_154 =
F_56 ( V_6 , V_147 . V_154 ) ;
F_57 ( V_6 , V_147 . V_154 ) ;
}
V_155:
V_147 . V_151 = V_6 -> V_151 ;
V_147 . V_149 = V_6 -> V_149 ;
V_147 . V_152 = V_6 -> V_152 ;
V_147 . V_150 = V_6 -> V_150 ;
V_101:
if ( F_46 ( V_46 , & V_147 , sizeof( struct V_66 ) ) )
return - V_86 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_74 V_54 * V_46 , void * V_44 )
{
struct V_74 V_157 ;
struct V_76 * V_158 = NULL ;
unsigned int * V_159 = NULL ;
int V_109 = 0 ;
int V_37 = 0 ;
if ( F_40 ( & V_157 , V_46 , sizeof( struct V_74 ) ) )
return - V_86 ;
V_159 = F_58 ( sizeof( unsigned int ) * V_160 , V_112 ) ;
if ( ! V_159 ) {
F_2 ( L_7 ) ;
V_37 = - V_92 ;
goto error;
}
V_158 =
F_48 ( V_157 . V_161 , sizeof( struct V_76 ) , V_112 ) ;
if ( ! V_158 ) {
F_2 ( L_7 ) ;
V_37 = - V_92 ;
goto error;
}
if ( F_40 ( V_158 , V_157 . V_158 ,
sizeof( struct V_76 ) * V_157 . V_161 ) ) {
F_2 ( L_8 ) ;
V_37 = - V_86 ;
goto error;
}
for ( V_109 = 0 ; V_109 < V_157 . V_161 ; V_109 ++ ) {
if ( V_158 [ V_109 ] . V_162 > V_160 ) {
F_2 ( L_9 ) ;
V_37 = - V_15 ;
goto error;
}
if ( V_158 [ V_109 ] . V_163 & V_164 ) {
if ( F_40 ( V_159 , V_158 [ V_109 ] . V_159 ,
V_158 [ V_109 ] . V_162 * sizeof( unsigned int ) ) ) {
F_2 ( L_8 ) ;
V_37 = - V_86 ;
goto error;
}
}
V_37 = F_59 ( V_2 , V_158 + V_109 , V_159 , V_44 ) ;
if ( V_37 < 0 )
goto error;
if ( V_158 [ V_109 ] . V_163 & V_165 ) {
if ( F_46 ( V_158 [ V_109 ] . V_159 , V_159 ,
V_158 [ V_109 ] . V_162 * sizeof( unsigned int ) ) ) {
F_2 ( L_10 ) ;
V_37 = - V_86 ;
goto error;
}
}
if ( F_60 () )
F_61 () ;
}
error:
F_51 ( V_158 ) ;
F_51 ( V_159 ) ;
if ( V_37 < 0 )
return V_37 ;
return V_109 ;
}
static int F_62 ( struct V_76 * V_163 ,
unsigned int * V_159 )
{
if ( V_163 -> V_162 < 1 )
return - V_15 ;
switch ( V_159 [ 0 ] ) {
case V_166 :
case V_167 :
case V_168 :
case V_169 :
if ( V_163 -> V_162 == 1 )
return 0 ;
break;
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
if ( V_163 -> V_162 == 2 )
return 0 ;
break;
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
if ( V_163 -> V_162 == 3 )
return 0 ;
break;
case V_193 :
case V_194 :
if ( V_163 -> V_162 == 5 )
return 0 ;
break;
default:
F_63 ( V_195
L_11
L_12
L_13
L_14 , V_159 [ 0 ] , V_196 ,
__FILE__ , V_163 -> V_162 ) ;
return 0 ;
break;
}
return - V_15 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_76 * V_163 ,
unsigned int * V_159 , void * V_44 )
{
struct V_3 * V_4 ;
int V_37 = 0 ;
int V_109 ;
if ( V_163 -> V_163 & V_197 ) {
switch ( V_163 -> V_163 ) {
case V_198 :
{
struct V_199 V_200 ;
if ( V_163 -> V_162 != 2 ) {
V_37 = - V_15 ;
break;
}
F_64 ( & V_200 ) ;
V_159 [ 0 ] = V_200 . V_201 ;
V_159 [ 1 ] = V_200 . V_202 ;
V_37 = 2 ;
break;
}
case V_203 :
if ( V_163 -> V_162 != 1 || V_159 [ 0 ] >= 100000 ) {
V_37 = - V_15 ;
break;
}
F_65 ( V_159 [ 0 ] / 1000 ) ;
V_37 = 1 ;
break;
case V_204 :
if ( V_163 -> V_162 != 1 ) {
V_37 = - V_15 ;
break;
}
if ( V_163 -> V_144 >= V_2 -> V_98 ) {
F_2 ( L_15 ,
V_163 -> V_144 ) ;
V_37 = - V_15 ;
break;
}
V_4 = V_2 -> V_20 + V_163 -> V_144 ;
if ( ! V_4 -> V_6 ) {
F_2 ( L_16 ) ;
V_37 = - V_15 ;
break;
}
if ( ! V_4 -> V_6 -> V_205 ) {
F_2 ( L_17 ) ;
V_37 = - V_206 ;
break;
}
V_37 = V_4 -> V_6 -> V_205 ( V_2 , V_4 , V_163 -> V_159 [ 0 ] ) ;
if ( V_37 >= 0 )
V_37 = 1 ;
break;
default:
F_2 ( L_18 ) ;
V_37 = - V_15 ;
break;
}
} else {
unsigned int V_119 ;
if ( V_163 -> V_144 >= V_2 -> V_98 ) {
F_2 ( L_19 , V_163 -> V_144 ) ;
V_37 = - V_15 ;
goto V_207;
}
V_4 = V_2 -> V_20 + V_163 -> V_144 ;
if ( V_4 -> type == V_208 ) {
F_2 ( L_15 , V_163 -> V_144 ) ;
V_37 = - V_209 ;
goto V_207;
}
if ( V_4 -> V_126 && V_4 -> V_126 != V_44 ) {
F_2 ( L_20 ) ;
V_37 = - V_148 ;
goto V_207;
}
V_37 = F_66 ( V_4 , 1 , & V_163 -> V_210 ) ;
if ( V_37 < 0 ) {
V_37 = - V_15 ;
F_2 ( L_21 ) ;
goto V_207;
}
if ( V_4 -> V_11 ) {
V_37 = - V_12 ;
goto V_207;
}
V_4 -> V_11 = & F_59 ;
switch ( V_163 -> V_163 ) {
case V_211 :
V_37 = V_4 -> V_212 ( V_2 , V_4 , V_163 , V_159 ) ;
break;
case V_213 :
V_119 = V_4 -> V_129
? V_4 -> V_129 [ F_67 ( V_163 -> V_210 ) ]
: V_4 -> V_119 ;
for ( V_109 = 0 ; V_109 < V_163 -> V_162 ; ++ V_109 ) {
if ( V_159 [ V_109 ] > V_119 ) {
V_37 = - V_15 ;
F_2 ( L_22 ) ;
break;
}
}
if ( V_37 == 0 )
V_37 = V_4 -> V_214 ( V_2 , V_4 , V_163 , V_159 ) ;
break;
case V_215 :
if ( V_163 -> V_162 != 2 ) {
V_37 = - V_15 ;
} else {
unsigned int V_216 ;
unsigned int V_217 ;
V_217 = V_159 [ 0 ] ;
if ( V_4 -> V_113 <= 32 ) {
V_216 = F_67 ( V_163 -> V_210 ) ;
if ( V_216 > 0 ) {
V_163 -> V_210 = 0 ;
V_159 [ 0 ] <<= V_216 ;
V_159 [ 1 ] <<= V_216 ;
}
} else
V_216 = 0 ;
V_37 = V_4 -> V_137 ( V_2 , V_4 , V_163 , V_159 ) ;
V_159 [ 0 ] = V_217 ;
if ( V_216 > 0 )
V_159 [ 1 ] >>= V_216 ;
}
break;
case V_218 :
V_37 = F_62 ( V_163 , V_159 ) ;
if ( V_37 )
break;
V_37 = V_4 -> V_219 ( V_2 , V_4 , V_163 , V_159 ) ;
break;
default:
V_37 = - V_15 ;
break;
}
V_4 -> V_11 = NULL ;
}
V_207:
return V_37 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_76 V_54 * V_46 , void * V_44 )
{
struct V_76 V_163 ;
unsigned int * V_159 = NULL ;
int V_37 = 0 ;
V_159 = F_58 ( sizeof( unsigned int ) * V_160 , V_112 ) ;
if ( ! V_159 ) {
V_37 = - V_92 ;
goto error;
}
if ( F_40 ( & V_163 , V_46 , sizeof( struct V_76 ) ) ) {
V_37 = - V_86 ;
goto error;
}
if ( V_163 . V_162 > V_160 )
V_163 . V_162 = V_160 ;
if ( V_163 . V_163 & V_164 ) {
if ( F_40 ( V_159 ,
V_163 . V_159 ,
V_163 . V_162 * sizeof( unsigned int ) ) ) {
V_37 = - V_86 ;
goto error;
}
}
V_37 = F_59 ( V_2 , & V_163 , V_159 , V_44 ) ;
if ( V_37 < 0 )
goto error;
if ( V_163 . V_163 & V_165 ) {
if ( F_46 ( V_163 . V_159 ,
V_159 ,
V_163 . V_162 * sizeof( unsigned int ) ) ) {
V_37 = - V_86 ;
goto error;
}
}
V_37 = V_163 . V_162 ;
error:
F_51 ( V_159 ) ;
return V_37 ;
}
static void F_68 ( struct V_3 * V_4 ,
unsigned V_220 , unsigned V_221 )
{
unsigned long V_123 ;
F_69 ( & V_4 -> V_222 , V_123 ) ;
V_4 -> V_223 &= ~ V_220 ;
V_4 -> V_223 |= ( V_221 & V_220 ) ;
F_70 ( & V_4 -> V_222 , V_123 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_71 V_54 * V_45 , void * V_44 )
{
struct V_71 V_224 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_37 = 0 ;
unsigned int V_54 * V_225 = NULL ;
if ( F_40 ( & V_224 , V_45 , sizeof( struct V_71 ) ) ) {
F_2 ( L_23 ) ;
return - V_86 ;
}
V_225 = V_224 . V_226 ;
if ( V_224 . V_144 >= V_2 -> V_98 ) {
F_2 ( L_24 , V_224 . V_144 ) ;
return - V_51 ;
}
V_4 = V_2 -> V_20 + V_224 . V_144 ;
V_6 = V_4 -> V_6 ;
if ( V_4 -> type == V_208 ) {
F_2 ( L_25 , V_224 . V_144 ) ;
return - V_209 ;
}
if ( ! V_4 -> V_135 || ! V_4 -> V_227 || ! V_4 -> V_6 ) {
F_2 ( L_26 ,
V_224 . V_144 ) ;
return - V_209 ;
}
if ( V_4 -> V_126 && V_4 -> V_126 != V_44 ) {
F_2 ( L_27 ) ;
return - V_148 ;
}
if ( V_4 -> V_11 ) {
F_2 ( L_28 ) ;
return - V_12 ;
}
V_4 -> V_11 = V_44 ;
if ( V_224 . V_228 > V_4 -> V_118 ) {
F_2 ( L_29 ,
V_224 . V_228 , V_4 -> V_118 ) ;
V_37 = - V_15 ;
goto V_229;
}
if ( V_224 . V_228 < 1 ) {
F_2 ( L_30 ,
V_224 . V_228 ) ;
V_37 = - V_15 ;
goto V_229;
}
F_51 ( V_6 -> V_45 . V_226 ) ;
V_6 -> V_45 = V_224 ;
V_6 -> V_45 . V_159 = NULL ;
V_6 -> V_45 . V_226 =
F_58 ( V_6 -> V_45 . V_228 * sizeof( int ) , V_112 ) ;
if ( ! V_6 -> V_45 . V_226 ) {
F_2 ( L_31 ) ;
V_37 = - V_92 ;
goto V_229;
}
if ( F_40 ( V_6 -> V_45 . V_226 , V_224 . V_226 ,
V_6 -> V_45 . V_228 * sizeof( int ) ) ) {
F_2 ( L_32 ) ;
V_37 = - V_86 ;
goto V_229;
}
V_37 = F_66 ( V_4 ,
V_6 -> V_45 . V_228 ,
V_6 -> V_45 . V_226 ) ;
if ( V_37 < 0 ) {
F_2 ( L_33 ) ;
goto V_229;
}
V_37 = V_4 -> V_227 ( V_2 , V_4 , & V_6 -> V_45 ) ;
if ( V_6 -> V_45 . V_123 & V_230 || V_37 ) {
F_2 ( L_34 , V_37 ) ;
V_224 = V_6 -> V_45 ;
V_224 . V_226 = V_225 ;
V_224 . V_159 = NULL ;
if ( F_46 ( V_45 , & V_224 , sizeof( struct V_71 ) ) ) {
F_2 ( L_35 ) ;
V_37 = - V_86 ;
goto V_229;
}
V_37 = - V_206 ;
goto V_229;
}
if ( ! V_6 -> V_21 ) {
V_37 = - V_92 ;
F_2 ( L_36 ) ;
goto V_229;
}
F_71 ( V_6 ) ;
V_6 -> V_231 =
V_232 | V_233 | V_234 |
V_235 ;
if ( V_6 -> V_45 . V_123 & V_236 )
V_6 -> V_231 |= V_237 ;
F_68 ( V_4 , ~ 0 , V_238 | V_115 ) ;
V_37 = V_4 -> V_135 ( V_2 , V_4 ) ;
if ( V_37 == 0 )
return 0 ;
V_229:
F_55 ( V_2 , V_4 ) ;
return V_37 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_71 V_54 * V_46 , void * V_44 )
{
struct V_71 V_224 ;
struct V_3 * V_4 ;
int V_37 = 0 ;
unsigned int * V_226 = NULL ;
unsigned int V_54 * V_225 = NULL ;
if ( F_40 ( & V_224 , V_46 , sizeof( struct V_71 ) ) ) {
F_2 ( L_23 ) ;
return - V_86 ;
}
V_225 = V_224 . V_226 ;
if ( V_224 . V_144 >= V_2 -> V_98 ) {
F_2 ( L_24 , V_224 . V_144 ) ;
return - V_51 ;
}
V_4 = V_2 -> V_20 + V_224 . V_144 ;
if ( V_4 -> type == V_208 ) {
F_2 ( L_25 , V_224 . V_144 ) ;
return - V_209 ;
}
if ( ! V_4 -> V_135 || ! V_4 -> V_227 ) {
F_2 ( L_26 ,
V_224 . V_144 ) ;
return - V_209 ;
}
if ( V_224 . V_228 > V_4 -> V_118 ) {
F_2 ( L_37 ,
V_224 . V_228 , V_4 -> V_118 ) ;
V_37 = - V_15 ;
goto V_229;
}
if ( V_224 . V_226 ) {
V_226 =
F_58 ( V_224 . V_228 * sizeof( int ) , V_112 ) ;
if ( ! V_226 ) {
F_2 ( L_31 ) ;
V_37 = - V_92 ;
goto V_229;
}
if ( F_40 ( V_226 , V_224 . V_226 ,
V_224 . V_228 * sizeof( int ) ) ) {
F_2 ( L_32 ) ;
V_37 = - V_86 ;
goto V_229;
}
V_37 = F_66 ( V_4 , V_224 . V_228 , V_226 ) ;
if ( V_37 < 0 ) {
F_2 ( L_33 ) ;
goto V_229;
}
V_224 . V_226 = V_226 ;
}
V_37 = V_4 -> V_227 ( V_2 , V_4 , & V_224 ) ;
V_224 . V_226 = V_225 ;
if ( F_46 ( V_46 , & V_224 , sizeof( struct V_71 ) ) ) {
F_2 ( L_23 ) ;
V_37 = - V_86 ;
goto V_229;
}
V_229:
F_51 ( V_226 ) ;
return V_37 ;
}
static int F_28 ( struct V_1 * V_2 , unsigned int V_46 ,
void * V_44 )
{
int V_37 = 0 ;
unsigned long V_123 ;
struct V_3 * V_4 ;
if ( V_46 >= V_2 -> V_98 )
return - V_15 ;
V_4 = V_2 -> V_20 + V_46 ;
F_69 ( & V_4 -> V_222 , V_123 ) ;
if ( V_4 -> V_11 || V_4 -> V_126 )
V_37 = - V_12 ;
else
V_4 -> V_126 = V_44 ;
F_70 ( & V_4 -> V_222 , V_123 ) ;
#if 0
if (ret < 0)
return ret;
if (s->lock_f)
ret = s->lock_f(dev, s);
#endif
return V_37 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned int V_46 ,
void * V_44 )
{
struct V_3 * V_4 ;
if ( V_46 >= V_2 -> V_98 )
return - V_15 ;
V_4 = V_2 -> V_20 + V_46 ;
if ( V_4 -> V_11 )
return - V_12 ;
if ( V_4 -> V_126 && V_4 -> V_126 != V_44 )
return - V_148 ;
if ( V_4 -> V_126 == V_44 ) {
#if 0
if (s->unlock)
s->unlock(dev, s);
#endif
V_4 -> V_126 = NULL ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , unsigned int V_46 ,
void * V_44 )
{
struct V_3 * V_4 ;
if ( V_46 >= V_2 -> V_98 )
return - V_15 ;
V_4 = V_2 -> V_20 + V_46 ;
if ( V_4 -> V_6 == NULL )
return - V_15 ;
if ( V_4 -> V_126 && V_4 -> V_126 != V_44 )
return - V_148 ;
if ( ! V_4 -> V_11 )
return 0 ;
if ( V_4 -> V_11 != V_44 )
return - V_12 ;
return F_72 ( V_2 , V_4 ) ;
}
static int F_35 ( struct V_1 * V_2 , unsigned int V_46 ,
void * V_44 )
{
struct V_3 * V_4 ;
if ( V_46 >= V_2 -> V_98 )
return - V_15 ;
V_4 = V_2 -> V_20 + V_46 ;
if ( V_4 -> V_126 && V_4 -> V_126 != V_44 )
return - V_148 ;
if ( ! V_4 -> V_11 )
return 0 ;
if ( V_4 -> V_11 != V_44 )
return - V_12 ;
if ( V_4 -> V_239 )
return V_4 -> V_239 ( V_2 , V_4 ) ;
return - V_15 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_37 = 0 ;
if ( ( F_49 ( V_4 ) & V_115 ) && V_4 -> V_240 )
V_37 = V_4 -> V_240 ( V_2 , V_4 ) ;
F_55 ( V_2 , V_4 ) ;
return V_37 ;
}
static void F_73 ( struct V_241 * V_242 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_6 = V_242 -> V_243 ;
V_2 = V_6 -> V_97 -> V_22 ;
F_7 ( & V_2 -> V_30 ) ;
V_6 -> V_13 ++ ;
F_8 ( & V_2 -> V_30 ) ;
}
static void F_74 ( struct V_241 * V_242 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_6 = V_242 -> V_243 ;
V_2 = V_6 -> V_97 -> V_22 ;
F_7 ( & V_2 -> V_30 ) ;
V_6 -> V_13 -- ;
F_8 ( & V_2 -> V_30 ) ;
}
static int F_75 ( struct V_44 * V_44 , struct V_241 * V_244 )
{
const unsigned V_19 = F_19 ( V_44 -> V_47 -> V_48 ) ;
struct V_5 * V_6 = NULL ;
unsigned long V_245 = V_244 -> V_246 ;
unsigned long V_99 ;
int V_247 ;
int V_109 ;
int V_8 ;
struct V_3 * V_4 ;
struct V_26 * V_49 ;
struct V_1 * V_2 ;
V_49 = F_20 ( V_19 ) ;
if ( V_49 == NULL )
return - V_51 ;
V_2 = V_49 -> V_22 ;
if ( V_2 == NULL )
return - V_51 ;
F_7 ( & V_2 -> V_30 ) ;
if ( ! V_2 -> V_56 ) {
F_2 ( L_38 , V_2 -> V_19 ) ;
V_8 = - V_51 ;
goto V_55;
}
if ( V_244 -> V_248 & V_249 )
V_4 = F_14 ( V_49 ) ;
else
V_4 = F_6 ( V_49 ) ;
if ( V_4 == NULL ) {
V_8 = - V_15 ;
goto V_55;
}
V_6 = V_4 -> V_6 ;
if ( V_6 == NULL ) {
V_8 = - V_15 ;
goto V_55;
}
if ( V_244 -> V_250 != 0 ) {
F_2 ( L_39 ) ;
V_8 = - V_15 ;
goto V_55;
}
V_99 = V_244 -> V_251 - V_244 -> V_246 ;
if ( V_99 > V_6 -> V_21 ) {
V_8 = - V_86 ;
goto V_55;
}
if ( V_99 & ( ~ V_17 ) ) {
V_8 = - V_86 ;
goto V_55;
}
V_247 = V_99 >> V_252 ;
for ( V_109 = 0 ; V_109 < V_247 ; ++ V_109 ) {
if ( F_76 ( V_244 , V_245 ,
F_77 ( F_78
( V_6 -> V_253
[ V_109 ] . V_254 ) ) , V_16 ,
V_255 ) ) {
V_8 = - V_206 ;
goto V_55;
}
V_245 += V_16 ;
}
V_244 -> V_256 = & V_257 ;
V_244 -> V_243 = V_6 ;
V_6 -> V_13 ++ ;
V_8 = 0 ;
V_55:
F_8 ( & V_2 -> V_30 ) ;
return V_8 ;
}
static unsigned int F_79 ( struct V_44 * V_44 , T_3 * V_258 )
{
unsigned int V_220 = 0 ;
const unsigned V_19 = F_19 ( V_44 -> V_47 -> V_48 ) ;
struct V_3 * V_103 ;
struct V_3 * V_104 ;
struct V_26 * V_49 ;
struct V_1 * V_2 ;
V_49 = F_20 ( V_19 ) ;
if ( V_49 == NULL )
return - V_51 ;
V_2 = V_49 -> V_22 ;
if ( V_2 == NULL )
return - V_51 ;
F_7 ( & V_2 -> V_30 ) ;
if ( ! V_2 -> V_56 ) {
F_2 ( L_38 , V_2 -> V_19 ) ;
F_8 ( & V_2 -> V_30 ) ;
return 0 ;
}
V_220 = 0 ;
V_103 = F_6 ( V_49 ) ;
if ( V_103 ) {
F_80 ( V_44 , & V_103 -> V_6 -> V_259 , V_258 ) ;
if ( ! V_103 -> V_11
|| F_81 ( V_103 -> V_6 ) > 0
|| ! ( F_49 ( V_103 ) &
V_115 ) ) {
V_220 |= V_260 | V_261 ;
}
}
V_104 = F_14 ( V_49 ) ;
if ( V_104 ) {
F_80 ( V_44 , & V_104 -> V_6 -> V_259 , V_258 ) ;
F_56 ( V_104 -> V_6 ,
V_104 -> V_6 -> V_21 ) ;
if ( ! V_104 -> V_11
|| ! ( F_49 ( V_104 ) &
V_115 )
|| F_82 ( V_104 -> V_6 ) >=
F_83 ( V_104 -> V_6 -> V_97 ) ) {
V_220 |= V_262 | V_263 ;
}
}
F_8 ( & V_2 -> V_30 ) ;
return V_220 ;
}
static T_1 F_84 ( struct V_44 * V_44 , const char V_54 * V_25 ,
T_2 V_264 , T_4 * V_265 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_162 , V_266 , V_34 = 0 , V_8 = 0 ;
F_85 ( V_258 , V_267 ) ;
const unsigned V_19 = F_19 ( V_44 -> V_47 -> V_48 ) ;
struct V_26 * V_49 ;
struct V_1 * V_2 ;
V_49 = F_20 ( V_19 ) ;
if ( V_49 == NULL )
return - V_51 ;
V_2 = V_49 -> V_22 ;
if ( V_2 == NULL )
return - V_51 ;
if ( ! V_2 -> V_56 ) {
F_2 ( L_38 , V_2 -> V_19 ) ;
V_8 = - V_51 ;
goto V_55;
}
V_4 = F_14 ( V_49 ) ;
if ( V_4 == NULL ) {
V_8 = - V_209 ;
goto V_55;
}
V_6 = V_4 -> V_6 ;
if ( ! V_264 ) {
V_8 = 0 ;
goto V_55;
}
if ( ! V_4 -> V_11 ) {
V_8 = 0 ;
goto V_55;
}
if ( V_4 -> V_11 != V_44 ) {
V_8 = - V_148 ;
goto V_55;
}
F_86 ( & V_6 -> V_259 , & V_258 ) ;
while ( V_264 > 0 && ! V_8 ) {
F_87 ( V_268 ) ;
if ( ! ( F_49 ( V_4 ) & V_115 ) ) {
if ( V_34 == 0 ) {
if ( F_49 ( V_4 ) &
V_156 ) {
V_8 = - V_269 ;
} else {
V_8 = 0 ;
}
F_55 ( V_2 , V_4 ) ;
}
break;
}
V_162 = V_264 ;
V_266 = V_162 ;
if ( V_6 -> V_149 + V_266 > V_6 -> V_21 )
V_266 = V_6 -> V_21 - V_6 -> V_149 ;
F_56 ( V_6 , V_6 -> V_21 ) ;
if ( V_266 > F_82 ( V_6 ) )
V_266 = F_82 ( V_6 ) ;
if ( V_266 < V_162 )
V_162 = V_266 ;
if ( V_162 == 0 ) {
if ( V_44 -> V_270 & V_271 ) {
V_8 = - V_206 ;
break;
}
F_61 () ;
if ( F_88 ( V_267 ) ) {
V_8 = - V_272 ;
break;
}
if ( ! V_4 -> V_11 )
break;
if ( V_4 -> V_11 != V_44 ) {
V_8 = - V_148 ;
break;
}
continue;
}
V_266 = F_40 ( V_6 -> V_14 + V_6 -> V_149 ,
V_25 , V_162 ) ;
if ( V_266 ) {
V_162 -= V_266 ;
V_8 = - V_86 ;
}
F_57 ( V_6 , V_162 ) ;
V_34 += V_162 ;
V_264 -= V_162 ;
V_25 += V_162 ;
break;
}
F_87 ( V_273 ) ;
F_89 ( & V_6 -> V_259 , & V_258 ) ;
V_55:
return V_34 ? V_34 : V_8 ;
}
static T_1 F_90 ( struct V_44 * V_44 , char V_54 * V_25 , T_2 V_264 ,
T_4 * V_265 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_162 , V_266 , V_34 = 0 , V_8 = 0 ;
F_85 ( V_258 , V_267 ) ;
const unsigned V_19 = F_19 ( V_44 -> V_47 -> V_48 ) ;
struct V_26 * V_49 ;
struct V_1 * V_2 ;
V_49 = F_20 ( V_19 ) ;
if ( V_49 == NULL )
return - V_51 ;
V_2 = V_49 -> V_22 ;
if ( V_2 == NULL )
return - V_51 ;
if ( ! V_2 -> V_56 ) {
F_2 ( L_38 , V_2 -> V_19 ) ;
V_8 = - V_51 ;
goto V_55;
}
V_4 = F_6 ( V_49 ) ;
if ( V_4 == NULL ) {
V_8 = - V_209 ;
goto V_55;
}
V_6 = V_4 -> V_6 ;
if ( ! V_264 ) {
V_8 = 0 ;
goto V_55;
}
if ( ! V_4 -> V_11 ) {
V_8 = 0 ;
goto V_55;
}
if ( V_4 -> V_11 != V_44 ) {
V_8 = - V_148 ;
goto V_55;
}
F_86 ( & V_6 -> V_259 , & V_258 ) ;
while ( V_264 > 0 && ! V_8 ) {
F_87 ( V_268 ) ;
V_162 = V_264 ;
V_266 = F_81 ( V_6 ) ;
if ( V_6 -> V_150 + V_266 > V_6 -> V_21 )
V_266 = V_6 -> V_21 - V_6 -> V_150 ;
if ( V_266 < V_162 )
V_162 = V_266 ;
if ( V_162 == 0 ) {
if ( ! ( F_49 ( V_4 ) & V_115 ) ) {
F_55 ( V_2 , V_4 ) ;
if ( F_49 ( V_4 ) &
V_156 ) {
V_8 = - V_269 ;
} else {
V_8 = 0 ;
}
break;
}
if ( V_44 -> V_270 & V_271 ) {
V_8 = - V_206 ;
break;
}
F_61 () ;
if ( F_88 ( V_267 ) ) {
V_8 = - V_272 ;
break;
}
if ( ! V_4 -> V_11 ) {
V_8 = 0 ;
break;
}
if ( V_4 -> V_11 != V_44 ) {
V_8 = - V_148 ;
break;
}
continue;
}
V_266 = F_46 ( V_25 , V_6 -> V_14 +
V_6 -> V_150 , V_162 ) ;
if ( V_266 ) {
V_162 -= V_266 ;
V_8 = - V_86 ;
}
F_53 ( V_6 , V_162 ) ;
F_54 ( V_6 , V_162 ) ;
V_34 += V_162 ;
V_264 -= V_162 ;
V_25 += V_162 ;
break;
}
if ( ! ( F_49 ( V_4 ) & ( V_156 | V_115 ) ) &&
V_6 -> V_152 - V_6 -> V_151 == 0 ) {
F_55 ( V_2 , V_4 ) ;
}
F_87 ( V_273 ) ;
F_89 ( & V_6 -> V_259 , & V_258 ) ;
V_55:
return V_34 ? V_34 : V_8 ;
}
void F_55 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
F_68 ( V_4 , V_115 , 0 ) ;
if ( V_6 ) {
F_71 ( V_6 ) ;
V_6 -> V_205 = NULL ;
} else {
F_63 ( V_274
L_40 ) ;
}
V_4 -> V_11 = NULL ;
}
static int F_91 ( struct V_275 * V_275 , struct V_44 * V_44 )
{
const unsigned V_19 = F_19 ( V_275 ) ;
struct V_26 * V_49 =
F_20 ( V_19 ) ;
struct V_1 * V_2 =
V_49 ? V_49 -> V_22 : NULL ;
if ( V_2 == NULL ) {
F_2 ( L_41 ) ;
return - V_51 ;
}
F_7 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_56 )
goto V_276;
if ( ! F_36 ( V_277 ) && V_2 -> V_278 ) {
F_2 ( L_42 ) ;
F_8 ( & V_2 -> V_30 ) ;
return - V_51 ;
}
if ( F_36 ( V_277 ) && V_2 -> V_278 )
goto V_276;
V_2 -> V_278 = 1 ;
#ifdef F_92
F_8 ( & V_2 -> V_30 ) ;
F_93 ( L_43 , V_279 , V_2 -> V_19 ) ;
F_7 ( & V_2 -> V_30 ) ;
#endif
V_2 -> V_278 = 0 ;
if ( ! V_2 -> V_56 && ! F_36 ( V_277 ) ) {
F_2 ( L_44 ) ;
F_8 ( & V_2 -> V_30 ) ;
return - V_51 ;
}
V_276:
F_94 ( V_280 ) ;
if ( V_2 -> V_56 ) {
if ( ! F_45 ( V_2 -> V_85 -> V_83 ) ) {
F_39 ( V_280 ) ;
F_8 ( & V_2 -> V_30 ) ;
return - V_95 ;
}
}
if ( V_2 -> V_56 && V_2 -> V_281 == 0 && V_2 -> V_282 ) {
int V_50 = V_2 -> V_282 ( V_2 ) ;
if ( V_50 < 0 ) {
F_39 ( V_2 -> V_85 -> V_83 ) ;
F_39 ( V_280 ) ;
F_8 ( & V_2 -> V_30 ) ;
return V_50 ;
}
}
V_2 -> V_281 ++ ;
F_8 ( & V_2 -> V_30 ) ;
return 0 ;
}
static int F_95 ( struct V_275 * V_275 , struct V_44 * V_44 )
{
const unsigned V_19 = F_19 ( V_275 ) ;
struct V_3 * V_4 = NULL ;
int V_109 ;
struct V_26 * V_49 ;
struct V_1 * V_2 ;
V_49 = F_20 ( V_19 ) ;
if ( V_49 == NULL )
return - V_51 ;
V_2 = V_49 -> V_22 ;
if ( V_2 == NULL )
return - V_51 ;
F_7 ( & V_2 -> V_30 ) ;
if ( V_2 -> V_20 ) {
for ( V_109 = 0 ; V_109 < V_2 -> V_98 ; V_109 ++ ) {
V_4 = V_2 -> V_20 + V_109 ;
if ( V_4 -> V_11 == V_44 )
F_72 ( V_2 , V_4 ) ;
if ( V_4 -> V_126 == V_44 )
V_4 -> V_126 = NULL ;
}
}
if ( V_2 -> V_56 && V_2 -> V_281 == 1 && V_2 -> V_283 )
V_2 -> V_283 ( V_2 ) ;
F_39 ( V_280 ) ;
if ( V_2 -> V_56 )
F_39 ( V_2 -> V_85 -> V_83 ) ;
V_2 -> V_281 -- ;
F_8 ( & V_2 -> V_30 ) ;
if ( V_44 -> V_270 & V_284 )
F_96 ( - 1 , V_44 , 0 ) ;
return 0 ;
}
static int F_96 ( int V_285 , struct V_44 * V_44 , int V_286 )
{
const unsigned V_19 = F_19 ( V_44 -> V_47 -> V_48 ) ;
struct V_26 * V_49 ;
struct V_1 * V_2 ;
V_49 = F_20 ( V_19 ) ;
if ( V_49 == NULL )
return - V_51 ;
V_2 = V_49 -> V_22 ;
if ( V_2 == NULL )
return - V_51 ;
return F_97 ( V_285 , V_44 , V_286 , & V_2 -> V_287 ) ;
}
static void F_98 ( void )
{
unsigned V_109 ;
for ( V_109 = 0 ; V_109 < V_288 ; V_109 ++ )
F_99 ( V_109 ) ;
}
static int T_5 F_100 ( void )
{
int V_109 ;
int V_8 ;
F_63 ( V_289 L_45 V_290
L_46 ) ;
if ( V_288 < 0 ||
V_288 > V_291 ) {
F_63 ( V_274 L_47
L_48
L_49 , V_291 ) ;
return - V_15 ;
}
if ( V_292 == 0 && V_288 == 0 )
V_288 = 16 ;
memset ( V_293 , 0 ,
sizeof( struct V_26 * ) * V_294 ) ;
V_8 = F_101 ( F_102 ( V_279 , 0 ) ,
V_294 , L_50 ) ;
if ( V_8 )
return - V_209 ;
F_103 ( & V_295 , & V_296 ) ;
V_295 . V_297 = V_280 ;
F_104 ( & V_295 . V_298 , L_50 ) ;
if ( F_105 ( & V_295 , F_102 ( V_279 , 0 ) , V_294 ) ) {
F_106 ( F_102 ( V_279 , 0 ) ,
V_294 ) ;
return - V_209 ;
}
V_299 = F_107 ( V_280 , L_50 ) ;
if ( F_108 ( V_299 ) ) {
F_63 ( V_274 L_51 ) ;
F_109 ( & V_295 ) ;
F_106 ( F_102 ( V_279 , 0 ) ,
V_294 ) ;
return F_110 ( V_299 ) ;
}
V_299 -> V_300 = V_301 ;
F_111 () ;
for ( V_109 = 0 ; V_109 < V_288 ; V_109 ++ ) {
int V_19 ;
V_19 = F_112 ( NULL ) ;
if ( V_19 < 0 ) {
F_98 () ;
F_109 ( & V_295 ) ;
F_106 ( F_102 ( V_279 , 0 ) ,
V_294 ) ;
return V_19 ;
}
}
return 0 ;
}
static void T_6 F_113 ( void )
{
int V_109 ;
F_98 () ;
for ( V_109 = 0 ; V_109 < V_294 ; ++ V_109 )
F_114 ( V_293 [ V_109 ] ) ;
F_115 ( V_299 ) ;
F_109 ( & V_295 ) ;
F_106 ( F_102 ( V_279 , 0 ) , V_294 ) ;
F_116 () ;
}
void F_117 ( const struct V_1 * V_2 , const char * V_4 )
{
F_63 ( V_274 L_52 , V_2 -> V_19 ,
V_2 -> V_85 -> V_108 , V_4 ) ;
}
void F_118 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned V_223 = 0 ;
unsigned V_302 = 0 ;
if ( ( F_49 ( V_4 ) & V_115 ) == 0 )
return;
if ( V_4 ->
V_6 -> V_303 & ( V_232 | V_234 |
V_235 ) ) {
V_302 |= V_115 ;
}
if ( V_4 -> V_6 -> V_303 & ( V_234 | V_235 ) ) {
V_302 |= V_156 ;
V_223 |= V_156 ;
}
if ( V_302 ) {
F_68 ( V_4 , V_302 , V_223 ) ;
}
if ( V_6 -> V_231 & V_4 -> V_6 -> V_303 ) {
if ( F_49 ( V_4 ) & V_238 ) {
F_119 ( & V_6 -> V_259 ) ;
if ( V_4 -> V_31 & V_32 )
F_120 ( & V_2 -> V_287 , V_304 , V_305 ) ;
if ( V_4 -> V_31 & V_42 )
F_120 ( & V_2 -> V_287 , V_304 , V_306 ) ;
} else {
if ( V_6 -> V_307 )
V_6 -> V_307 ( V_4 -> V_6 -> V_303 , V_6 -> V_308 ) ;
}
}
V_4 -> V_6 -> V_303 = 0 ;
}
unsigned F_49 ( struct V_3 * V_4 )
{
unsigned long V_123 ;
unsigned V_223 ;
F_69 ( & V_4 -> V_222 , V_123 ) ;
V_223 = V_4 -> V_223 ;
F_70 ( & V_4 -> V_222 , V_123 ) ;
return V_223 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_109 ;
if ( ! V_2 -> V_56 )
return 0 ;
for ( V_109 = 0 ; V_109 < V_2 -> V_98 ; V_109 ++ ) {
V_4 = V_2 -> V_20 + V_109 ;
if ( V_4 -> V_11 )
return 1 ;
if ( V_4 -> V_6 && V_4 -> V_6 -> V_13 )
return 1 ;
}
return 0 ;
}
static void F_121 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_122 ( & V_2 -> V_309 ) ;
F_123 ( & V_2 -> V_30 ) ;
V_2 -> V_19 = - 1 ;
}
static void F_124 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_7 ( & V_2 -> V_30 ) ;
F_38 ( V_2 ) ;
F_8 ( & V_2 -> V_30 ) ;
F_125 ( & V_2 -> V_30 ) ;
}
int F_112 ( struct V_22 * V_310 )
{
struct V_26 * V_27 ;
struct V_22 * V_311 ;
unsigned V_109 ;
V_27 = F_126 ( sizeof( struct V_26 ) , V_112 ) ;
if ( V_27 == NULL )
return - V_92 ;
V_27 -> V_22 = F_126 ( sizeof( struct V_1 ) , V_112 ) ;
if ( V_27 -> V_22 == NULL ) {
F_51 ( V_27 ) ;
return - V_92 ;
}
V_27 -> V_310 = V_310 ;
F_121 ( V_27 -> V_22 ) ;
V_222 ( & V_312 ) ;
for ( V_109 = 0 ; V_109 < V_291 ; ++ V_109 ) {
if ( V_293 [ V_109 ] == NULL ) {
V_293 [ V_109 ] = V_27 ;
break;
}
}
F_127 ( & V_312 ) ;
if ( V_109 == V_291 ) {
F_124 ( V_27 -> V_22 ) ;
F_51 ( V_27 -> V_22 ) ;
F_51 ( V_27 ) ;
F_63 ( V_274
L_53
L_54 ) ;
return - V_12 ;
}
V_27 -> V_22 -> V_19 = V_109 ;
V_311 = F_128 ( V_299 , V_310 ,
F_102 ( V_279 , V_109 ) , NULL , L_55 , V_109 ) ;
if ( ! F_108 ( V_311 ) )
V_27 -> V_22 -> V_313 = V_311 ;
F_129 ( V_311 , V_27 ) ;
return V_109 ;
}
void F_99 ( unsigned V_19 )
{
struct V_26 * V_27 ;
F_114 ( V_19 >= V_291 ) ;
V_222 ( & V_312 ) ;
V_27 = V_293 [ V_19 ] ;
V_293 [ V_19 ] = NULL ;
F_127 ( & V_312 ) ;
if ( V_27 ) {
struct V_1 * V_2 = V_27 -> V_22 ;
if ( V_2 ) {
if ( V_2 -> V_313 ) {
F_130 ( V_299 ,
F_102 ( V_279 , V_2 -> V_19 ) ) ;
}
F_124 ( V_2 ) ;
F_51 ( V_2 ) ;
}
F_51 ( V_27 ) ;
}
}
int F_131 ( struct V_22 * V_310 )
{
int V_19 ;
struct V_26 * V_27 ;
for ( V_19 = 0 ; V_19 < V_291 ; V_19 ++ ) {
V_222 ( & V_312 ) ;
V_27 = V_293 [ V_19 ] ;
if ( V_27 && V_27 -> V_310 == V_310 ) {
F_127 ( & V_312 ) ;
return V_19 ;
}
F_127 ( & V_312 ) ;
}
return - V_51 ;
}
int F_132 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_26 * V_27 ;
struct V_22 * V_311 ;
unsigned V_109 ;
V_27 = F_58 ( sizeof( struct V_26 ) , V_112 ) ;
if ( V_27 == NULL )
return - V_92 ;
V_27 -> V_22 = V_2 ;
V_27 -> V_29 = V_4 ;
V_27 -> V_41 = V_4 ;
V_222 ( & V_312 ) ;
for ( V_109 = V_314 ; V_109 < V_294 ; ++ V_109 ) {
if ( V_293 [ V_109 ] == NULL ) {
V_293 [ V_109 ] = V_27 ;
break;
}
}
F_127 ( & V_312 ) ;
if ( V_109 == V_294 ) {
F_51 ( V_27 ) ;
F_63 ( V_274
L_53
L_54 ) ;
return - V_12 ;
}
V_4 -> V_19 = V_109 ;
V_311 = F_128 ( V_299 , V_2 -> V_313 ,
F_102 ( V_279 , V_109 ) , NULL , L_56 ,
V_2 -> V_19 , ( int ) ( V_4 - V_2 -> V_20 ) ) ;
if ( ! F_108 ( V_311 ) )
V_4 -> V_313 = V_311 ;
F_129 ( V_311 , V_27 ) ;
return V_109 ;
}
void F_133 ( struct V_3 * V_4 )
{
struct V_26 * V_27 ;
if ( V_4 == NULL )
return;
if ( V_4 -> V_19 < 0 )
return;
F_114 ( V_4 -> V_19 >= V_294 ) ;
F_114 ( V_4 -> V_19 < V_314 ) ;
V_222 ( & V_312 ) ;
V_27 = V_293 [ V_4 -> V_19 ] ;
V_293 [ V_4 -> V_19 ] = NULL ;
F_127 ( & V_312 ) ;
if ( V_4 -> V_313 ) {
F_130 ( V_299 , F_102 ( V_279 , V_4 -> V_19 ) ) ;
V_4 -> V_313 = NULL ;
}
F_51 ( V_27 ) ;
}
struct V_26 * F_20 ( unsigned V_19 )
{
struct V_26 * V_27 ;
F_114 ( V_19 >= V_294 ) ;
V_222 ( & V_312 ) ;
V_27 = V_293 [ V_19 ] ;
F_127 ( & V_312 ) ;
return V_27 ;
}
