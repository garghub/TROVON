T_1 F_1 ( void * V_1 , T_1 V_2 , void * V_3 ,
T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
T_1 V_8 = 0 ;
int V_9 ;
F_2 ( V_10 > 0 ) ;
F_2 ( V_3 != NULL ) ;
if ( V_7 ) {
F_3 ( V_7 -> V_11 != NULL ) ;
V_9 = (* V_7 -> V_12 . V_13 ) (
V_7 -> V_11 , V_3 ,
V_2 , V_4 , V_5 ) ;
if ( V_4 == 0 )
V_4 = 1 ;
if ( ! V_9 )
V_8 = V_4 ;
}
return V_8 ;
}
int F_4 ( struct V_6 * * V_14 ,
const char * V_15 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_22 V_23 ;
struct V_24 V_25 ;
T_1 V_26 ;
struct V_27 * V_28 = NULL ;
struct V_29 * V_30 = F_5 ( V_31 ) ;
int V_9 = 0 ;
F_2 ( V_10 > 0 ) ;
F_2 ( V_14 != NULL ) ;
F_2 ( V_15 != NULL ) ;
V_9 = F_6 ( ( void * ) & V_19 ) ;
if ( V_9 ) {
F_7 ( V_31 , L_1 ,
V_32 ) ;
goto V_33;
}
F_8 ( & V_21 , V_15 ) ;
if ( V_30 && V_30 -> V_27 ) {
V_28 = V_30 -> V_27 ;
} else {
V_9 = - V_34 ;
F_9 ( L_2 , V_32 ) ;
}
if ( ! V_9 ) {
F_3 ( V_21 ) ;
V_7 = F_10 ( sizeof( struct V_6 ) , V_35 ) ;
if ( V_7 ) {
V_7 -> V_17 = V_17 ;
V_7 -> V_36 = NULL ;
V_7 -> V_37 = NULL ;
V_7 -> V_38 = NULL ;
V_7 -> V_39 = NULL ;
V_7 -> V_40 = V_41 ;
V_7 -> V_42 = V_28 ;
V_7 -> V_43 = V_44 ;
F_11 ( V_21 ,
& V_7 -> V_12 ) ;
V_9 = ( V_7 -> V_12 . V_45 )
( & V_7 -> V_11 , V_7 ,
V_19 ) ;
F_3 ( V_9
|| ( V_7 -> V_11 != NULL ) ) ;
} else {
V_9 = - V_46 ;
}
}
if ( ! V_9 )
V_9 = F_12 ( V_7 ) ;
if ( ! V_9 ) {
V_23 . V_47 = V_48 ;
V_25 . V_49 = V_19 -> V_50 ;
V_25 . V_51 =
( V_19 -> V_52 & V_53 ) ;
V_25 . V_40 = V_41 ;
V_23 . V_40 = V_41 ;
V_26 = V_19 -> V_54 ;
if ( V_26 ) {
V_25 . V_55 = V_19 -> V_56 [ 1 ] +
V_19 -> V_57 ;
V_25 . V_58 =
V_19 -> V_59 [ 1 ] -
V_19 -> V_57 ;
} else {
V_25 . V_55 = 0 ;
V_25 . V_58 = 0 ;
F_9 ( L_3 ,
V_32 ) ;
}
V_9 = F_13 ( & V_7 -> V_37 , V_7 , & V_23 ) ;
if ( V_9 == - V_60 ) {
V_9 = 0 ;
}
V_9 = F_14 ( & V_7 -> V_61 ,
(struct V_6 * ) V_7 , NULL ) ;
if ( ! V_9 && V_7 -> V_37 ) {
V_9 = F_15 ( & V_7 -> V_62 , V_7 ,
& V_25 ) ;
}
if ( ! V_9 ) {
V_9 = F_16 ( & V_7 -> V_38 , V_7 ) ;
}
V_9 = F_17 ( & V_7 -> V_63 ,
(struct V_6 * ) V_7 , NULL ) ;
}
if ( ! V_9 )
V_9 = F_18 ( V_28 , V_7 ) ;
if ( ! V_9 )
F_19 ( & V_7 -> V_64 ) ;
V_33:
if ( ! V_9 ) {
* V_14 = V_7 ;
} else {
if ( V_7 ) {
if ( V_7 -> V_36 )
F_20 ( V_7 -> V_36 ) ;
if ( V_7 -> V_63 )
F_21 ( V_7 -> V_63 ) ;
F_22 ( V_7 ) ;
}
* V_14 = NULL ;
}
F_23 ( ( ! V_9 && * V_14 ) || ( V_9 && ! * V_14 ) ) ;
return V_9 ;
}
int F_24 ( struct V_6 * V_65 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_65 ;
F_2 ( V_10 > 0 ) ;
F_2 ( V_65 ) ;
F_3 ( ! V_7 -> V_66 ) ;
V_9 = F_25 ( & V_7 -> V_66 , V_65 ) ;
if ( V_9 )
V_7 -> V_66 = NULL ;
F_23 ( ( ! V_9 && V_7 -> V_66 != NULL )
|| ( V_9 && V_7 -> V_66 == NULL ) ) ;
return V_9 ;
}
int F_26 ( struct V_6 * V_65 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_65 ;
F_2 ( V_10 > 0 ) ;
F_2 ( V_65 ) ;
if ( V_7 -> V_66 ) {
if ( F_27 ( V_7 -> V_66 ) )
V_9 = - V_34 ;
else
V_7 -> V_66 = NULL ;
}
F_23 ( ( ! V_9 && V_7 -> V_66 == NULL ) || V_9 ) ;
return V_9 ;
}
int F_28 ( struct V_6 * V_65 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_65 ;
F_2 ( V_10 > 0 ) ;
if ( V_65 ) {
if ( V_7 -> V_36 ) {
F_20 ( V_7 -> V_36 ) ;
V_7 -> V_36 = NULL ;
}
if ( V_7 -> V_66 ) {
F_27 ( V_7 -> V_66 ) ;
V_7 -> V_66 = NULL ;
}
if ( V_7 -> V_62 ) {
F_29 ( V_7 -> V_62 ) ;
V_7 -> V_62 = NULL ;
}
if ( V_7 -> V_37 ) {
F_30 ( V_7 -> V_37 ) ;
V_7 -> V_37 = NULL ;
}
if ( V_7 -> V_67 ) {
F_31 ( V_7 -> V_67 ) ;
V_7 -> V_67 = NULL ;
}
if ( V_7 -> V_38 ) {
F_32 ( V_7 -> V_38 ) ;
V_7 -> V_38 = NULL ;
}
if ( V_7 -> V_61 ) {
F_33 ( V_7 -> V_61 , true ) ;
V_7 -> V_61 = NULL ;
}
if ( V_7 -> V_63 ) {
F_21 ( V_7 -> V_63 ) ;
V_7 -> V_63 = NULL ;
}
if ( V_7 -> V_11 ) {
V_9 = (* V_7 -> V_12 . V_68 )
( V_7 -> V_11 ) ;
V_7 -> V_11 = NULL ;
} else
V_9 = - V_34 ;
if ( ! V_9 ) {
F_34 ( V_7 -> V_42 , V_7 ) ;
F_22 ( V_7 ) ;
V_7 = NULL ;
}
} else {
V_9 = - V_69 ;
}
return V_9 ;
}
int F_35 ( struct V_6 * V_65 ,
struct V_37 * * V_70 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_65 ;
F_2 ( V_10 > 0 ) ;
F_2 ( V_70 != NULL ) ;
if ( V_65 ) {
* V_70 = V_7 -> V_37 ;
} else {
* V_70 = NULL ;
V_9 = - V_69 ;
}
F_23 ( ! V_9 || ( V_70 != NULL && * V_70 == NULL ) ) ;
return V_9 ;
}
int F_36 ( struct V_6 * V_65 ,
struct V_71 * * V_70 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_65 ;
F_2 ( V_10 > 0 ) ;
F_2 ( V_70 != NULL ) ;
if ( V_65 ) {
* V_70 = V_7 -> V_61 ;
} else {
* V_70 = NULL ;
V_9 = - V_69 ;
}
F_23 ( ! V_9 || ( V_70 != NULL && * V_70 == NULL ) ) ;
return V_9 ;
}
int F_37 ( struct V_6 * V_65 ,
struct V_72 * * V_70 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_65 ;
F_2 ( V_10 > 0 ) ;
F_2 ( V_70 != NULL ) ;
if ( V_65 ) {
* V_70 = V_7 -> V_63 ;
} else {
* V_70 = NULL ;
V_9 = - V_69 ;
}
F_23 ( ! V_9 || ( V_70 != NULL && * V_70 == NULL ) ) ;
return V_9 ;
}
int F_38 ( struct V_6 * V_65 ,
struct V_73 * * V_36 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_65 ;
F_2 ( V_10 > 0 ) ;
F_2 ( V_36 != NULL ) ;
if ( V_65 ) {
* V_36 = V_7 -> V_36 ;
} else {
* V_36 = NULL ;
V_9 = - V_69 ;
}
F_23 ( ! V_9 || ( V_36 != NULL && * V_36 == NULL ) ) ;
return V_9 ;
}
int F_39 ( struct V_6 * V_65 ,
struct V_38 * * V_74 )
{
int V_9 = 0 ;
F_2 ( V_10 > 0 ) ;
F_2 ( V_74 != NULL ) ;
F_2 ( V_65 ) ;
if ( V_65 ) {
* V_74 = V_65 -> V_38 ;
} else {
* V_74 = NULL ;
V_9 = - V_69 ;
}
return V_9 ;
}
int F_40 ( struct V_6 * V_65 ,
struct V_16 * * V_75 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_65 ;
F_2 ( V_10 > 0 ) ;
F_2 ( V_75 != NULL ) ;
if ( V_65 ) {
* V_75 = V_7 -> V_17 ;
} else {
* V_75 = NULL ;
V_9 = - V_69 ;
}
F_23 ( ! V_9 || ( V_75 != NULL && * V_75 == NULL ) ) ;
return V_9 ;
}
struct V_6 * F_41 ( void )
{
struct V_6 * V_7 = NULL ;
V_7 = (struct V_6 * ) F_42 () ;
return V_7 ;
}
int F_43 ( struct V_6 * V_65 ,
struct V_20 * * V_76 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_65 ;
F_2 ( V_10 > 0 ) ;
F_2 ( V_76 != NULL ) ;
if ( V_65 ) {
* V_76 = & V_7 -> V_12 ;
} else {
* V_76 = NULL ;
V_9 = - V_69 ;
}
F_23 ( ! V_9 || ( ( V_76 != NULL ) && ( * V_76 == NULL ) ) ) ;
return V_9 ;
}
int F_44 ( struct V_6 * V_65 ,
struct V_77 * * V_78 )
{
int V_9 = 0 ;
F_2 ( V_10 > 0 ) ;
F_2 ( V_78 != NULL ) ;
F_2 ( V_65 ) ;
if ( V_65 ) {
* V_78 = V_65 -> V_62 ;
} else {
* V_78 = NULL ;
V_9 = - V_69 ;
}
return V_9 ;
}
struct V_6 * F_45 ( struct V_6 * V_65 )
{
struct V_6 * V_79 = NULL ;
if ( V_65 ) {
V_79 = (struct V_6 * )
F_46 ( ( T_1 ) V_65 ) ;
}
return V_79 ;
}
void F_47 ( struct V_6 * V_65 , struct V_67 * * V_80 )
{
F_2 ( V_10 > 0 ) ;
F_2 ( V_80 != NULL ) ;
F_2 ( V_65 ) ;
* V_80 = V_65 -> V_67 ;
}
int F_48 ( struct V_6 * V_65 ,
struct V_66 * * V_81 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_65 ;
F_2 ( V_10 > 0 ) ;
F_2 ( V_81 != NULL ) ;
if ( V_65 ) {
* V_81 = V_7 -> V_66 ;
} else {
* V_81 = NULL ;
V_9 = - V_69 ;
}
F_23 ( ! V_9 || ( V_81 != NULL && * V_81 == NULL ) ) ;
return V_9 ;
}
int F_49 ( struct V_6 * V_65 ,
const char * V_82 , T_1 * V_83 )
{
int V_9 = 0 ;
struct V_73 * V_36 ;
F_2 ( V_10 > 0 ) ;
F_2 ( V_82 != NULL && V_83 != NULL ) ;
if ( V_65 ) {
V_9 = F_38 ( V_65 , & V_36 ) ;
if ( V_36 )
V_9 = F_50 ( V_36 , ( char * ) V_82 ,
V_83 ) ;
else
V_9 = - V_69 ;
}
return V_9 ;
}
int F_51 ( struct V_6 * V_65 ,
struct V_84 * * V_85 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_65 ;
F_2 ( V_10 > 0 ) ;
F_2 ( V_85 != NULL ) ;
if ( V_65 ) {
* V_85 = V_7 -> V_11 ;
} else {
* V_85 = NULL ;
V_9 = - V_69 ;
}
F_23 ( ! V_9 || ( ( V_85 != NULL ) &&
( * V_85 == NULL ) ) ) ;
return V_9 ;
}
void F_52 ( void )
{
F_2 ( V_10 > 0 ) ;
V_10 -- ;
if ( V_10 == 0 ) {
F_53 () ;
F_54 () ;
}
F_23 ( V_10 >= 0 ) ;
}
bool F_55 ( void )
{
bool V_86 , V_87 , V_88 = true ;
F_2 ( V_10 >= 0 ) ;
if ( V_10 == 0 ) {
V_86 = F_56 () ;
V_87 = F_57 () ;
V_88 = V_86 && V_87 ;
if ( ! V_88 ) {
if ( V_86 )
F_53 () ;
if ( V_87 )
F_54 () ;
}
}
if ( V_88 )
V_10 ++ ;
F_23 ( ( V_88 && ( V_10 > 0 ) ) || ( ! V_88 && ( V_10 >= 0 ) ) ) ;
return V_88 ;
}
int F_58 ( struct V_6 * V_7 , T_1 V_88 )
{
struct V_89 * V_90 ;
F_59 (curr, &dev_obj->proc_list)
F_60 ( ( void * ) V_90 , V_88 ) ;
return 0 ;
}
int F_61 ( struct V_16 * V_17 )
{
struct V_6 * V_65 ;
int V_9 = 0 ;
struct V_29 * V_30 = F_5 ( V_31 ) ;
if ( ! V_30 )
V_9 = - V_91 ;
if ( ! V_17 )
V_9 = - V_69 ;
if ( ! V_9 ) {
if ( ! strcmp ( ( char * ) ( (struct V_92 * ) V_17 ) -> V_93 ,
L_4 ) ) {
V_65 = V_30 -> V_6 ;
V_9 = F_28 ( V_65 ) ;
} else {
V_9 = - V_34 ;
}
}
if ( V_9 )
F_9 ( L_5 , V_32 , V_9 ) ;
return V_9 ;
}
int F_62 ( struct V_6 * V_65 ,
struct V_37 * V_94 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_65 ;
F_2 ( V_10 > 0 ) ;
if ( V_65 )
V_7 -> V_37 = V_94 ;
else
V_9 = - V_69 ;
F_23 ( V_9 || ( V_7 -> V_37 == V_94 ) ) ;
return V_9 ;
}
void F_63 ( struct V_6 * V_65 , struct V_67 * V_94 )
{
F_2 ( V_10 > 0 ) ;
F_2 ( V_65 ) ;
V_65 -> V_67 = V_94 ;
}
int F_64 ( struct V_16 * V_17 )
{
struct V_6 * V_65 = NULL ;
char * V_95 = L_6 ;
int V_9 ;
struct V_96 * V_97 = NULL ;
struct V_29 * V_30 = F_5 ( V_31 ) ;
F_2 ( V_10 > 0 ) ;
V_9 = F_4 ( & V_65 , V_95 ,
V_17 ) ;
if ( ! V_9 ) {
if ( ! V_30 || ! V_17 ) {
V_9 = - V_69 ;
F_9 ( L_5 , V_32 , V_9 ) ;
} else if ( ! ( strcmp ( ( char * ) V_17 , L_4 ) ) ) {
V_30 -> V_6 = ( void * ) V_65 ;
}
if ( ! V_9 ) {
V_9 = F_65 ( & V_97 , V_17 ) ;
if ( V_9 && ! ( strcmp ( ( char * ) V_17 ,
L_4 ) ) ) {
V_30 -> V_6 = NULL ;
}
}
if ( V_9 ) {
F_28 ( V_65 ) ;
V_65 = NULL ;
}
}
return V_9 ;
}
static int F_66 ( int V_98 , ... )
{
return - V_60 ;
}
static int F_12 ( struct V_6 * V_7 )
{
int V_9 = 0 ;
char * V_99 = L_7 ;
F_2 ( V_10 > 0 ) ;
F_2 ( ! V_7 || ( V_7 -> V_36 == NULL ) ) ;
V_9 = F_67 ( & V_7 -> V_36 , V_99 ) ;
return V_9 ;
}
int F_68 ( struct V_6 * V_65 ,
T_1 V_100 , bool * V_101 )
{
struct V_6 * V_7 = (struct V_6 * ) V_65 ;
F_2 ( V_10 > 0 ) ;
F_2 ( V_7 ) ;
F_2 ( V_100 != 0 ) ;
F_2 ( V_101 != NULL ) ;
if ( ! F_69 ( & V_7 -> V_64 ) )
* V_101 = true ;
F_70 ( (struct V_89 * ) V_100 , & V_7 -> V_64 ) ;
return 0 ;
}
int F_71 ( struct V_6 * V_65 , T_1 V_100 )
{
int V_9 = - V_34 ;
struct V_89 * V_102 ;
struct V_6 * V_7 = (struct V_6 * ) V_65 ;
F_2 ( V_7 ) ;
F_2 ( V_100 != 0 ) ;
F_2 ( ! F_69 ( & V_7 -> V_64 ) ) ;
F_59 (cur_elem, &dev_obj->proc_list) {
if ( ( T_1 ) V_102 == V_100 ) {
F_72 ( V_102 ) ;
V_9 = 0 ;
break;
}
}
return V_9 ;
}
int F_73 ( struct V_6 * V_7 , T_2 * V_43 )
{
* V_43 = V_7 -> V_43 ;
return 0 ;
}
static void F_11 ( struct V_20 * V_21 ,
struct V_20 * V_103 )
{
T_1 V_104 ;
#define F_74 ( T_3 , T_4 ) \
(intf_fxns->pfn = ((drv_fxns->pfn != NULL) ? drv_fxns->pfn : \
(cast)fxn_not_implemented))
F_2 ( V_103 != NULL ) ;
F_2 ( V_21 != NULL ) ;
F_2 ( F_75 ( V_21 -> V_105 ,
V_21 -> V_106 ) <= V_107 ) ;
V_104 = F_75 ( V_21 -> V_105 ,
V_21 -> V_106 ) ;
V_103 -> V_105 = V_21 -> V_105 ;
V_103 -> V_106 = V_21 -> V_106 ;
if ( V_104 > 0 ) {
F_74 ( V_108 , V_45 ) ;
F_74 ( V_109 , V_68 ) ;
F_74 ( V_110 , V_111 ) ;
F_74 ( V_112 , V_113 ) ;
F_74 ( V_114 , V_115 ) ;
F_74 ( V_116 , V_117 ) ;
F_74 ( V_118 , V_119 ) ;
F_74 ( V_120 , V_121 ) ;
F_74 ( V_122 , V_13 ) ;
F_74 ( V_123 , V_124 ) ;
F_74 ( V_125 , V_126 ) ;
F_74 ( V_127 , V_128 ) ;
F_74 ( V_129 , V_130 ) ;
F_74 ( V_131 , V_132 ) ;
F_74 ( V_133 , F_13 ) ;
F_74 ( V_134 , F_30 ) ;
F_74 ( V_135 , V_136 ) ;
F_74 ( V_137 , V_138 ) ;
F_74 ( V_139 , V_140 ) ;
F_74 ( V_141 , V_142 ) ;
F_74 ( V_143 , V_144 ) ;
F_74 ( V_145 , V_146 ) ;
F_74 ( V_147 , V_148 ) ;
F_74 ( V_149 , V_150 ) ;
F_74 ( V_151 , V_152 ) ;
F_74 ( V_153 , V_154 ) ;
F_74 ( V_155 , F_15 ) ;
F_74 ( V_156 , F_29 ) ;
F_74 ( V_157 , V_158 ) ;
F_74 ( V_159 , V_160 ) ;
F_74 ( V_161 , V_162 ) ;
F_74 ( V_163 , V_164 ) ;
F_74 ( V_165 , F_31 ) ;
F_74 ( V_166 , V_167 ) ;
F_74 ( V_168 , V_169 ) ;
F_74 ( V_170 , V_171 ) ;
F_74 ( V_172 , V_173 ) ;
F_74 ( V_174 , V_175 ) ;
}
F_23 ( V_103 -> V_45 != NULL ) ;
F_23 ( V_103 -> V_68 != NULL ) ;
F_23 ( V_103 -> V_111 != NULL ) ;
F_23 ( V_103 -> V_113 != NULL ) ;
F_23 ( V_103 -> V_115 != NULL ) ;
F_23 ( V_103 -> V_117 != NULL ) ;
F_23 ( V_103 -> V_119 != NULL ) ;
F_23 ( V_103 -> V_121 != NULL ) ;
F_23 ( V_103 -> V_13 != NULL ) ;
F_23 ( V_103 -> F_13 != NULL ) ;
F_23 ( V_103 -> F_30 != NULL ) ;
F_23 ( V_103 -> V_136 != NULL ) ;
F_23 ( V_103 -> V_138 != NULL ) ;
F_23 ( V_103 -> V_140 != NULL ) ;
F_23 ( V_103 -> V_142 != NULL ) ;
F_23 ( V_103 -> V_144 != NULL ) ;
F_23 ( V_103 -> V_146 != NULL ) ;
F_23 ( V_103 -> V_148 != NULL ) ;
F_23 ( V_103 -> V_150 != NULL ) ;
F_23 ( V_103 -> V_152 != NULL ) ;
F_23 ( V_103 -> V_154 != NULL ) ;
F_23 ( V_103 -> F_15 != NULL ) ;
F_23 ( V_103 -> F_29 != NULL ) ;
F_23 ( V_103 -> V_158 != NULL ) ;
F_23 ( V_103 -> V_160 != NULL ) ;
F_23 ( V_103 -> V_175 != NULL ) ;
#undef F_74
}
