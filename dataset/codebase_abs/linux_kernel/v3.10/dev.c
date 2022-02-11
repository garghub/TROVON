T_1 F_1 ( void * V_1 , T_1 V_2 , void * V_3 ,
T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
T_1 V_8 = 0 ;
int V_9 ;
if ( V_7 ) {
V_9 = (* V_7 -> V_10 . V_11 ) (
V_7 -> V_12 , V_3 ,
V_2 , V_4 , V_5 ) ;
if ( V_4 == 0 )
V_4 = 1 ;
if ( ! V_9 )
V_8 = V_4 ;
}
return V_8 ;
}
int F_2 ( struct V_6 * * V_13 ,
const char * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_21 V_22 ;
struct V_23 V_24 ;
T_1 V_25 ;
struct V_26 * V_27 = NULL ;
struct V_28 * V_29 = F_3 ( V_30 ) ;
int V_9 = 0 ;
V_9 = F_4 ( ( void * ) & V_18 ) ;
if ( V_9 ) {
F_5 ( V_30 , L_1 ,
V_31 ) ;
goto V_32;
}
F_6 ( & V_20 , V_14 ) ;
if ( V_29 && V_29 -> V_26 ) {
V_27 = V_29 -> V_26 ;
} else {
V_9 = - V_33 ;
F_7 ( L_2 , V_31 ) ;
}
if ( ! V_9 ) {
V_7 = F_8 ( sizeof( struct V_6 ) , V_34 ) ;
if ( V_7 ) {
V_7 -> V_16 = V_16 ;
V_7 -> V_35 = NULL ;
V_7 -> V_36 = NULL ;
V_7 -> V_37 = NULL ;
V_7 -> V_38 = NULL ;
V_7 -> V_39 = V_40 ;
V_7 -> V_41 = V_27 ;
V_7 -> V_42 = V_43 ;
F_9 ( V_20 ,
& V_7 -> V_10 ) ;
V_9 = ( V_7 -> V_10 . V_44 )
( & V_7 -> V_12 , V_7 ,
V_18 ) ;
} else {
V_9 = - V_45 ;
}
}
if ( ! V_9 )
V_9 = F_10 ( V_7 ) ;
if ( ! V_9 ) {
V_22 . V_46 = V_47 ;
V_24 . V_48 = V_18 -> V_49 ;
V_24 . V_50 =
( V_18 -> V_51 & V_52 ) ;
V_24 . V_39 = V_40 ;
V_22 . V_39 = V_40 ;
V_25 = V_18 -> V_53 ;
if ( V_25 ) {
V_24 . V_54 = V_18 -> V_55 [ 1 ] +
V_18 -> V_56 ;
V_24 . V_57 =
V_18 -> V_58 [ 1 ] -
V_18 -> V_56 ;
} else {
V_24 . V_54 = 0 ;
V_24 . V_57 = 0 ;
F_7 ( L_3 ,
V_31 ) ;
}
V_9 = F_11 ( & V_7 -> V_36 , V_7 , & V_22 ) ;
if ( V_9 == - V_59 ) {
V_9 = 0 ;
}
V_9 = F_12 ( & V_7 -> V_60 ,
(struct V_6 * ) V_7 , NULL ) ;
if ( ! V_9 && V_7 -> V_36 ) {
V_9 = F_13 ( & V_7 -> V_61 , V_7 ,
& V_24 ) ;
}
if ( ! V_9 ) {
V_9 = F_14 ( & V_7 -> V_37 , V_7 ) ;
}
V_9 = F_15 ( & V_7 -> V_62 ,
(struct V_6 * ) V_7 , NULL ) ;
}
if ( ! V_9 )
V_9 = F_16 ( V_27 , V_7 ) ;
if ( ! V_9 )
F_17 ( & V_7 -> V_63 ) ;
V_32:
if ( ! V_9 ) {
* V_13 = V_7 ;
} else {
if ( V_7 ) {
if ( V_7 -> V_35 )
F_18 ( V_7 -> V_35 ) ;
if ( V_7 -> V_62 )
F_19 ( V_7 -> V_62 ) ;
F_20 ( V_7 ) ;
}
* V_13 = NULL ;
}
return V_9 ;
}
int F_21 ( struct V_6 * V_64 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_64 ;
V_9 = F_22 ( & V_7 -> V_65 , V_64 ) ;
if ( V_9 )
V_7 -> V_65 = NULL ;
return V_9 ;
}
int F_23 ( struct V_6 * V_64 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_64 ;
if ( V_7 -> V_65 ) {
if ( F_24 ( V_7 -> V_65 ) )
V_9 = - V_33 ;
else
V_7 -> V_65 = NULL ;
}
return V_9 ;
}
int F_25 ( struct V_6 * V_64 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_64 ;
if ( V_64 ) {
if ( V_7 -> V_35 ) {
F_18 ( V_7 -> V_35 ) ;
V_7 -> V_35 = NULL ;
}
if ( V_7 -> V_65 ) {
F_24 ( V_7 -> V_65 ) ;
V_7 -> V_65 = NULL ;
}
if ( V_7 -> V_61 ) {
F_26 ( V_7 -> V_61 ) ;
V_7 -> V_61 = NULL ;
}
if ( V_7 -> V_36 ) {
F_27 ( V_7 -> V_36 ) ;
V_7 -> V_36 = NULL ;
}
if ( V_7 -> V_66 ) {
F_28 ( V_7 -> V_66 ) ;
V_7 -> V_66 = NULL ;
}
if ( V_7 -> V_37 ) {
F_29 ( V_7 -> V_37 ) ;
V_7 -> V_37 = NULL ;
}
if ( V_7 -> V_60 ) {
F_30 ( V_7 -> V_60 , true ) ;
V_7 -> V_60 = NULL ;
}
if ( V_7 -> V_62 ) {
F_19 ( V_7 -> V_62 ) ;
V_7 -> V_62 = NULL ;
}
if ( V_7 -> V_12 ) {
V_9 = (* V_7 -> V_10 . V_67 )
( V_7 -> V_12 ) ;
V_7 -> V_12 = NULL ;
} else
V_9 = - V_33 ;
if ( ! V_9 ) {
F_31 ( V_7 -> V_41 , V_7 ) ;
F_20 ( V_7 ) ;
V_7 = NULL ;
}
} else {
V_9 = - V_68 ;
}
return V_9 ;
}
int F_32 ( struct V_6 * V_64 ,
struct V_36 * * V_69 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_64 ;
if ( V_64 ) {
* V_69 = V_7 -> V_36 ;
} else {
* V_69 = NULL ;
V_9 = - V_68 ;
}
return V_9 ;
}
int F_33 ( struct V_6 * V_64 ,
struct V_70 * * V_69 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_64 ;
if ( V_64 ) {
* V_69 = V_7 -> V_60 ;
} else {
* V_69 = NULL ;
V_9 = - V_68 ;
}
return V_9 ;
}
int F_34 ( struct V_6 * V_64 ,
struct V_71 * * V_69 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_64 ;
if ( V_64 ) {
* V_69 = V_7 -> V_62 ;
} else {
* V_69 = NULL ;
V_9 = - V_68 ;
}
return V_9 ;
}
int F_35 ( struct V_6 * V_64 ,
struct V_72 * * V_35 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_64 ;
if ( V_64 ) {
* V_35 = V_7 -> V_35 ;
} else {
* V_35 = NULL ;
V_9 = - V_68 ;
}
return V_9 ;
}
int F_36 ( struct V_6 * V_64 ,
struct V_37 * * V_73 )
{
int V_9 = 0 ;
if ( V_64 ) {
* V_73 = V_64 -> V_37 ;
} else {
* V_73 = NULL ;
V_9 = - V_68 ;
}
return V_9 ;
}
int F_37 ( struct V_6 * V_64 ,
struct V_15 * * V_74 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_64 ;
if ( V_64 ) {
* V_74 = V_7 -> V_16 ;
} else {
* V_74 = NULL ;
V_9 = - V_68 ;
}
return V_9 ;
}
struct V_6 * F_38 ( void )
{
struct V_6 * V_7 = NULL ;
V_7 = (struct V_6 * ) F_39 () ;
return V_7 ;
}
int F_40 ( struct V_6 * V_64 ,
struct V_19 * * V_75 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_64 ;
if ( V_64 ) {
* V_75 = & V_7 -> V_10 ;
} else {
* V_75 = NULL ;
V_9 = - V_68 ;
}
return V_9 ;
}
int F_41 ( struct V_6 * V_64 ,
struct V_76 * * V_77 )
{
int V_9 = 0 ;
if ( V_64 ) {
* V_77 = V_64 -> V_61 ;
} else {
* V_77 = NULL ;
V_9 = - V_68 ;
}
return V_9 ;
}
struct V_6 * F_42 ( struct V_6 * V_64 )
{
struct V_6 * V_78 = NULL ;
if ( V_64 ) {
V_78 = (struct V_6 * )
F_43 ( ( T_1 ) V_64 ) ;
}
return V_78 ;
}
void F_44 ( struct V_6 * V_64 , struct V_66 * * V_79 )
{
* V_79 = V_64 -> V_66 ;
}
int F_45 ( struct V_6 * V_64 ,
struct V_65 * * V_80 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_64 ;
if ( V_64 ) {
* V_80 = V_7 -> V_65 ;
} else {
* V_80 = NULL ;
V_9 = - V_68 ;
}
return V_9 ;
}
int F_46 ( struct V_6 * V_64 ,
const char * V_81 , T_1 * V_82 )
{
int V_9 = 0 ;
struct V_72 * V_35 ;
if ( V_64 ) {
V_9 = F_35 ( V_64 , & V_35 ) ;
if ( V_35 )
V_9 = F_47 ( V_35 , ( char * ) V_81 ,
V_82 ) ;
else
V_9 = - V_68 ;
}
return V_9 ;
}
int F_48 ( struct V_6 * V_64 ,
struct V_83 * * V_84 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_64 ;
if ( V_64 ) {
* V_84 = V_7 -> V_12 ;
} else {
* V_84 = NULL ;
V_9 = - V_68 ;
}
return V_9 ;
}
int F_49 ( struct V_6 * V_7 , T_1 V_85 )
{
struct V_86 * V_87 ;
F_50 (curr, &dev_obj->proc_list)
F_51 ( ( void * ) V_87 , V_85 ) ;
return 0 ;
}
int F_52 ( struct V_15 * V_16 )
{
struct V_6 * V_64 ;
int V_9 = 0 ;
struct V_28 * V_29 = F_3 ( V_30 ) ;
if ( ! V_29 )
V_9 = - V_88 ;
if ( ! V_16 )
V_9 = - V_68 ;
if ( ! V_9 ) {
if ( ! strcmp ( ( char * ) ( (struct V_89 * ) V_16 ) -> V_90 ,
L_4 ) ) {
V_64 = V_29 -> V_6 ;
V_9 = F_25 ( V_64 ) ;
} else {
V_9 = - V_33 ;
}
}
if ( V_9 )
F_7 ( L_5 , V_31 , V_9 ) ;
return V_9 ;
}
int F_53 ( struct V_6 * V_64 ,
struct V_36 * V_91 )
{
int V_9 = 0 ;
struct V_6 * V_7 = V_64 ;
if ( V_64 )
V_7 -> V_36 = V_91 ;
else
V_9 = - V_68 ;
return V_9 ;
}
void F_54 ( struct V_6 * V_64 , struct V_66 * V_91 )
{
V_64 -> V_66 = V_91 ;
}
int F_55 ( struct V_15 * V_16 )
{
struct V_6 * V_64 = NULL ;
char * V_92 = L_6 ;
int V_9 ;
struct V_93 * V_94 = NULL ;
struct V_28 * V_29 = F_3 ( V_30 ) ;
V_9 = F_2 ( & V_64 , V_92 ,
V_16 ) ;
if ( ! V_9 ) {
if ( ! V_29 || ! V_16 ) {
V_9 = - V_68 ;
F_7 ( L_5 , V_31 , V_9 ) ;
} else if ( ! ( strcmp ( ( char * ) V_16 , L_4 ) ) ) {
V_29 -> V_6 = ( void * ) V_64 ;
}
if ( ! V_9 ) {
V_9 = F_56 ( & V_94 , V_16 ) ;
if ( V_9 && ! ( strcmp ( ( char * ) V_16 ,
L_4 ) ) ) {
V_29 -> V_6 = NULL ;
}
}
if ( V_9 ) {
F_25 ( V_64 ) ;
V_64 = NULL ;
}
}
return V_9 ;
}
static int F_57 ( int V_95 , ... )
{
return - V_59 ;
}
static int F_10 ( struct V_6 * V_7 )
{
int V_9 = 0 ;
char * V_96 = L_7 ;
V_9 = F_58 ( & V_7 -> V_35 , V_96 ) ;
return V_9 ;
}
int F_59 ( struct V_6 * V_64 ,
T_1 V_97 , bool * V_98 )
{
struct V_6 * V_7 = (struct V_6 * ) V_64 ;
if ( ! F_60 ( & V_7 -> V_63 ) )
* V_98 = true ;
F_61 ( (struct V_86 * ) V_97 , & V_7 -> V_63 ) ;
return 0 ;
}
int F_62 ( struct V_6 * V_64 , T_1 V_97 )
{
int V_9 = - V_33 ;
struct V_86 * V_99 ;
struct V_6 * V_7 = (struct V_6 * ) V_64 ;
F_50 (cur_elem, &dev_obj->proc_list) {
if ( ( T_1 ) V_99 == V_97 ) {
F_63 ( V_99 ) ;
V_9 = 0 ;
break;
}
}
return V_9 ;
}
int F_64 ( struct V_6 * V_7 , T_2 * V_42 )
{
* V_42 = V_7 -> V_42 ;
return 0 ;
}
static void F_9 ( struct V_19 * V_20 ,
struct V_19 * V_100 )
{
T_1 V_101 ;
#define F_65 ( T_3 , T_4 ) \
(intf_fxns->pfn = ((drv_fxns->pfn != NULL) ? drv_fxns->pfn : \
(cast)fxn_not_implemented))
V_101 = F_66 ( V_20 -> V_102 ,
V_20 -> V_103 ) ;
V_100 -> V_102 = V_20 -> V_102 ;
V_100 -> V_103 = V_20 -> V_103 ;
if ( V_101 > 0 ) {
F_65 ( V_104 , V_44 ) ;
F_65 ( V_105 , V_67 ) ;
F_65 ( V_106 , V_107 ) ;
F_65 ( V_108 , V_109 ) ;
F_65 ( V_110 , V_111 ) ;
F_65 ( V_112 , V_113 ) ;
F_65 ( V_114 , V_115 ) ;
F_65 ( V_116 , V_117 ) ;
F_65 ( V_118 , V_11 ) ;
F_65 ( V_119 , V_120 ) ;
F_65 ( V_121 , V_122 ) ;
F_65 ( V_123 , V_124 ) ;
F_65 ( V_125 , V_126 ) ;
F_65 ( V_127 , V_128 ) ;
F_65 ( V_129 , F_11 ) ;
F_65 ( V_130 , F_27 ) ;
F_65 ( V_131 , V_132 ) ;
F_65 ( V_133 , V_134 ) ;
F_65 ( V_135 , V_136 ) ;
F_65 ( V_137 , V_138 ) ;
F_65 ( V_139 , V_140 ) ;
F_65 ( V_141 , V_142 ) ;
F_65 ( V_143 , V_144 ) ;
F_65 ( V_145 , V_146 ) ;
F_65 ( V_147 , V_148 ) ;
F_65 ( V_149 , V_150 ) ;
F_65 ( V_151 , F_13 ) ;
F_65 ( V_152 , F_26 ) ;
F_65 ( V_153 , V_154 ) ;
F_65 ( V_155 , V_156 ) ;
F_65 ( V_157 , V_158 ) ;
F_65 ( V_159 , V_160 ) ;
F_65 ( V_161 , F_28 ) ;
F_65 ( V_162 , V_163 ) ;
F_65 ( V_164 , V_165 ) ;
F_65 ( V_166 , V_167 ) ;
F_65 ( V_168 , V_169 ) ;
F_65 ( V_170 , V_171 ) ;
}
#undef F_65
}
