void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
enum V_8 V_8 = V_4 -> V_8 ;
enum V_9 V_10 = V_4 -> V_11 ;
if ( V_8 == V_12 )
V_8 = V_13 ;
if ( V_8 == V_14 || V_8 >= V_15 )
return;
V_8 -- ;
V_6 -> V_16 [ V_8 ] . V_17 += ( V_10 == V_18 ) ;
V_6 -> V_16 [ V_8 ] . V_19 += ( V_10 == V_20 ) ;
V_6 -> V_16 [ V_8 ] . V_21 += ( V_10 == V_22 ) ;
V_6 -> V_16 [ V_8 ] . V_23 += ( V_10 == V_24 ) ;
}
void F_2 ( struct V_1 * V_2 ,
enum V_25 type , struct V_26 * V_27 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_28 * V_29 = V_27 -> V_29 ;
struct V_30 * V_31 = F_3 ( V_29 ) ;
struct V_28 * V_32 ;
struct V_33 * V_34 ;
struct V_35 V_36 ;
T_1 V_37 ;
if ( F_4 ( ! F_5 ( V_38 , & V_6 -> V_39 ) ) )
return;
F_6 ( & V_36 ) ;
if ( F_7 ( & V_6 -> V_40 ) > 20 ) {
F_8 ( V_2 , L_1 ) ;
return;
}
V_37 = V_29 -> V_41 ;
if ( V_31 -> V_42 & V_43 )
V_37 -= V_31 -> V_44 ;
V_32 = F_9 ( sizeof( * V_34 ) + V_31 -> V_44 + V_37 ,
V_45 ) ;
if ( ! V_32 ) {
F_8 ( V_2 , L_2 ) ;
return;
}
V_34 = F_10 ( V_32 , sizeof( * V_34 ) ) ;
V_34 -> V_46 = F_11 ( V_47 ) ;
V_34 -> V_48 = F_11 ( sizeof( * V_34 ) ) ;
V_34 -> V_49 = F_11 ( V_31 -> V_44 ) ;
V_34 -> V_50 = F_11 ( V_37 ) ;
V_34 -> V_51 = F_12 ( V_2 -> V_52 . V_53 ) ;
V_34 -> V_54 = F_12 ( V_2 -> V_52 . V_55 ) ;
V_34 -> V_56 = F_12 ( V_2 -> V_52 . V_57 ) ;
V_34 -> type = F_12 ( type ) ;
V_34 -> V_58 = V_27 -> V_59 -> V_60 ;
V_34 -> V_61 = V_27 -> V_62 ;
V_34 -> V_63 = F_11 ( V_36 . V_64 ) ;
V_34 -> V_65 = F_11 ( V_36 . V_66 ) ;
if ( ! ( V_31 -> V_42 & V_43 ) )
F_13 ( V_32 , V_31 -> V_67 , V_31 -> V_44 ) ;
F_13 ( V_32 , V_29 -> V_68 , V_29 -> V_41 ) ;
F_14 ( & V_6 -> V_40 , V_32 ) ;
F_15 ( & V_6 -> V_69 ) ;
if ( ! F_5 ( V_38 , & V_6 -> V_39 ) )
F_16 ( & V_6 -> V_40 ) ;
}
static int F_17 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
struct V_5 * V_6 = V_70 -> V_72 ;
V_71 -> V_73 = V_70 -> V_72 ;
if ( ! F_18 ( V_6 -> V_74 -> V_75 ) )
return - V_76 ;
return 0 ;
}
static int F_19 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
struct V_5 * V_6 = V_71 -> V_73 ;
F_20 ( V_6 -> V_74 -> V_75 ) ;
return 0 ;
}
static int F_21 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
struct V_5 * V_6 = V_70 -> V_72 ;
int V_77 ;
V_77 = F_17 ( V_70 , V_71 ) ;
if ( V_77 )
return V_77 ;
if ( F_22 ( V_38 , & V_6 -> V_39 ) ) {
F_19 ( V_70 , V_71 ) ;
return - V_76 ;
}
return 0 ;
}
static int F_23 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
struct V_5 * V_6 = V_70 -> V_72 ;
F_16 ( & V_6 -> V_40 ) ;
F_24 ( V_38 , & V_6 -> V_39 ) ;
return F_19 ( V_70 , V_71 ) ;
}
static T_2 F_25 ( struct V_71 * V_71 ,
char T_3 * V_78 ,
T_4 V_79 ,
T_5 * V_80 )
{
struct V_5 * V_6 = V_71 -> V_73 ;
struct V_28 * V_29 ;
T_4 V_10 ;
int V_77 ;
if ( V_71 -> V_81 & V_82 )
return - V_83 ;
V_77 =
F_26 ( V_6 -> V_69 ,
( V_29 =
F_27 ( & V_6 -> V_40 ) ) ) ;
if ( V_77 )
return V_77 ;
V_10 = F_28 ( T_4 , V_29 -> V_41 , V_79 ) ;
if ( F_29 ( V_78 , V_29 -> V_68 , V_10 ) ) {
V_10 = - V_84 ;
goto exit;
}
* V_80 += V_10 ;
exit:
F_30 ( V_29 ) ;
return V_10 ;
}
static unsigned int F_31 ( struct V_71 * V_71 ,
T_6 * V_85 )
{
struct V_5 * V_6 = V_71 -> V_73 ;
F_32 ( V_71 , & V_6 -> V_69 , V_85 ) ;
if ( ! F_33 ( & V_6 -> V_40 ) )
return V_86 | V_87 ;
return 0 ;
}
static T_2 F_34 ( struct V_71 * V_71 ,
char T_3 * V_78 ,
T_4 V_79 ,
T_5 * V_80 )
{
struct V_5 * V_6 = V_71 -> V_73 ;
struct V_88 * V_59 ;
unsigned long V_89 ;
unsigned int V_90 = 1 + V_6 -> V_2 -> V_91 ;
T_4 V_92 ;
char * V_68 ;
char * V_93 ;
if ( * V_80 )
return 0 ;
V_68 = F_35 ( V_90 , V_94 , V_95 ) ;
if ( ! V_68 )
return - V_96 ;
V_93 = V_68 +
sprintf ( V_68 , L_3 ) ;
F_36 (intf->rt2x00dev, queue) {
F_37 ( & V_59 -> V_97 , V_89 ) ;
V_93 += sprintf ( V_93 , L_4 ,
V_59 -> V_60 , ( unsigned int ) V_59 -> V_42 ,
V_59 -> V_98 , V_59 -> V_99 , V_59 -> V_79 ,
V_59 -> V_100 [ V_101 ] ,
V_59 -> V_100 [ V_102 ] ,
V_59 -> V_100 [ V_103 ] ) ;
F_38 ( & V_59 -> V_97 , V_89 ) ;
}
V_92 = strlen ( V_68 ) ;
V_92 = F_39 ( V_92 , V_79 ) ;
if ( F_29 ( V_78 , V_68 , V_92 ) ) {
F_40 ( V_68 ) ;
return - V_84 ;
}
F_40 ( V_68 ) ;
* V_80 += V_92 ;
return V_92 ;
}
static T_2 F_41 ( struct V_71 * V_71 ,
char T_3 * V_78 ,
T_4 V_79 ,
T_5 * V_80 )
{
struct V_5 * V_6 = V_71 -> V_73 ;
static const char * const V_104 [] = { L_5 , L_6 , L_7 , L_8 } ;
char * V_68 ;
char * V_93 ;
T_4 V_92 ;
unsigned int V_105 ;
if ( * V_80 )
return 0 ;
V_68 = F_42 ( ( 1 + V_15 ) * V_94 , V_95 ) ;
if ( ! V_68 )
return - V_96 ;
V_93 = V_68 ;
V_93 += sprintf ( V_68 , L_9 ) ;
for ( V_105 = 0 ; V_105 < V_15 ; V_105 ++ ) {
V_93 += sprintf ( V_93 , L_10 , V_104 [ V_105 ] ,
V_6 -> V_16 [ V_105 ] . V_17 ,
V_6 -> V_16 [ V_105 ] . V_19 ,
V_6 -> V_16 [ V_105 ] . V_21 ,
V_6 -> V_16 [ V_105 ] . V_23 ) ;
}
V_92 = strlen ( V_68 ) ;
V_92 = F_39 ( V_92 , V_79 ) ;
if ( F_29 ( V_78 , V_68 , V_92 ) ) {
F_40 ( V_68 ) ;
return - V_84 ;
}
F_40 ( V_68 ) ;
* V_80 += V_92 ;
return V_92 ;
}
static T_2 F_43 ( struct V_71 * V_71 ,
char T_3 * V_78 ,
T_4 V_79 ,
T_5 * V_80 )
{
struct V_5 * V_6 = V_71 -> V_73 ;
char line [ 16 ] ;
T_4 V_92 ;
if ( * V_80 )
return 0 ;
V_92 = sprintf ( line , L_11 , ( unsigned int ) V_6 -> V_2 -> V_42 ) ;
if ( F_29 ( V_78 , line , V_92 ) )
return - V_84 ;
* V_80 += V_92 ;
return V_92 ;
}
static T_2 F_44 ( struct V_71 * V_71 ,
char T_3 * V_78 ,
T_4 V_79 ,
T_5 * V_80 )
{
struct V_5 * V_6 = V_71 -> V_73 ;
char line [ 16 ] ;
T_4 V_92 ;
if ( * V_80 )
return 0 ;
V_92 = sprintf ( line , L_11 , ( unsigned int ) V_6 -> V_2 -> V_106 ) ;
if ( F_29 ( V_78 , line , V_92 ) )
return - V_84 ;
* V_80 += V_92 ;
return V_92 ;
}
static struct V_107 * F_45 ( const char * V_104 ,
struct V_5
* V_6 ,
struct V_108
* V_109 )
{
char * V_68 ;
V_68 = F_42 ( 3 * V_94 , V_95 ) ;
if ( ! V_68 )
return NULL ;
V_109 -> V_68 = V_68 ;
V_68 += sprintf ( V_68 , L_12 , V_6 -> V_2 -> V_110 -> V_104 ) ;
V_68 += sprintf ( V_68 , L_13 , V_111 ) ;
V_109 -> V_92 = strlen ( V_109 -> V_68 ) ;
return F_46 ( V_104 , V_112 , V_6 -> V_113 , V_109 ) ;
}
static struct V_107 * F_47 ( const char * V_104 ,
struct V_5
* V_6 ,
struct
V_108
* V_109 )
{
const struct V_114 * V_74 = V_6 -> V_74 ;
char * V_68 ;
V_68 = F_42 ( 9 * V_94 , V_95 ) ;
if ( ! V_68 )
return NULL ;
V_109 -> V_68 = V_68 ;
V_68 += sprintf ( V_68 , L_14 , V_6 -> V_2 -> V_52 . V_53 ) ;
V_68 += sprintf ( V_68 , L_15 , V_6 -> V_2 -> V_52 . V_55 ) ;
V_68 += sprintf ( V_68 , L_16 , V_6 -> V_2 -> V_52 . V_57 ) ;
V_68 += sprintf ( V_68 , L_17 ) ;
V_68 += sprintf ( V_68 , L_18 ) ;
#define F_48 ( T_7 ) \
{ \
if (debug->__name.read) \
data += sprintf(data, __stringify(__name) \
"\t%d\t%d\t%d\n", \
debug->__name.word_base, \
debug->__name.word_count, \
debug->__name.word_size); \
}
F_48 ( V_115 ) ;
F_48 ( V_116 ) ;
F_48 ( V_117 ) ;
F_48 ( V_55 ) ;
F_48 ( V_118 ) ;
#undef F_48
V_109 -> V_92 = strlen ( V_109 -> V_68 ) ;
return F_46 ( V_104 , V_112 , V_6 -> V_113 , V_109 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
const struct V_114 * V_74 = V_2 -> V_110 -> V_119 ;
struct V_5 * V_6 ;
V_6 = F_42 ( sizeof( struct V_5 ) , V_95 ) ;
if ( ! V_6 ) {
F_50 ( V_2 , L_19 ) ;
return;
}
V_6 -> V_74 = V_74 ;
V_6 -> V_2 = V_2 ;
V_2 -> V_7 = V_6 ;
V_6 -> V_113 =
F_51 ( V_6 -> V_2 -> V_110 -> V_104 ,
V_2 -> V_120 -> V_121 -> V_122 ) ;
if ( F_52 ( V_6 -> V_113 ) || ! V_6 -> V_113 )
goto exit;
V_6 -> V_123 =
F_45 ( L_20 , V_6 , & V_6 -> V_124 ) ;
if ( F_52 ( V_6 -> V_123 ) || ! V_6 -> V_123 )
goto exit;
V_6 -> V_125 =
F_47 ( L_21 ,
V_6 , & V_6 -> V_126 ) ;
if ( F_52 ( V_6 -> V_125 ) || ! V_6 -> V_125 )
goto exit;
V_6 -> V_127 = F_53 ( L_22 , V_112 ,
V_6 -> V_113 , V_6 ,
& V_128 ) ;
if ( F_52 ( V_6 -> V_127 ) || ! V_6 -> V_127 )
goto exit;
V_6 -> V_106 = F_53 ( L_23 , V_112 ,
V_6 -> V_113 , V_6 ,
& V_129 ) ;
if ( F_52 ( V_6 -> V_106 ) || ! V_6 -> V_106 )
goto exit;
V_6 -> V_130 =
F_51 ( L_24 , V_6 -> V_113 ) ;
if ( F_52 ( V_6 -> V_130 ) || ! V_6 -> V_130 )
goto exit;
#define F_54 ( T_8 , T_7 ) \
({ \
if (debug->__name.read) { \
(__intf)->__name##_off_entry = \
debugfs_create_u32(__stringify(__name) "_offset", \
S_IRUSR | S_IWUSR, \
(__intf)->register_folder, \
&(__intf)->offset_##__name); \
if (IS_ERR((__intf)->__name##_off_entry) \
|| !(__intf)->__name##_off_entry) \
goto exit; \
\
(__intf)->__name##_val_entry = \
debugfs_create_file(__stringify(__name) "_value", \
S_IRUSR | S_IWUSR, \
(__intf)->register_folder, \
(__intf), &rt2x00debug_fop_##__name); \
if (IS_ERR((__intf)->__name##_val_entry) \
|| !(__intf)->__name##_val_entry) \
goto exit; \
} \
})
F_54 ( V_6 , V_115 ) ;
F_54 ( V_6 , V_116 ) ;
F_54 ( V_6 , V_117 ) ;
F_54 ( V_6 , V_55 ) ;
F_54 ( V_6 , V_118 ) ;
#undef F_54
V_6 -> V_131 =
F_51 ( L_25 , V_6 -> V_113 ) ;
if ( F_52 ( V_6 -> V_131 ) || ! V_6 -> V_131 )
goto exit;
V_6 -> V_132 =
F_53 ( L_26 , V_112 , V_6 -> V_131 ,
V_6 , & V_133 ) ;
if ( F_52 ( V_6 -> V_132 )
|| ! V_6 -> V_132 )
goto exit;
F_55 ( & V_6 -> V_40 ) ;
F_56 ( & V_6 -> V_69 ) ;
V_6 -> V_134 =
F_53 ( L_25 , V_112 , V_6 -> V_131 ,
V_6 , & V_135 ) ;
#ifdef F_57
if ( F_58 ( V_2 ) )
V_6 -> V_136 =
F_53 ( L_27 , V_137 , V_6 -> V_131 ,
V_6 , & V_138 ) ;
#endif
return;
exit:
F_59 ( V_2 ) ;
F_50 ( V_2 , L_28 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_60 ( ! V_6 ) )
return;
F_16 ( & V_6 -> V_40 ) ;
#ifdef F_57
F_61 ( V_6 -> V_136 ) ;
#endif
F_61 ( V_6 -> V_134 ) ;
F_61 ( V_6 -> V_132 ) ;
F_61 ( V_6 -> V_131 ) ;
F_61 ( V_6 -> V_139 ) ;
F_61 ( V_6 -> V_140 ) ;
F_61 ( V_6 -> V_141 ) ;
F_61 ( V_6 -> V_142 ) ;
F_61 ( V_6 -> V_143 ) ;
F_61 ( V_6 -> V_144 ) ;
F_61 ( V_6 -> V_145 ) ;
F_61 ( V_6 -> V_146 ) ;
F_61 ( V_6 -> V_147 ) ;
F_61 ( V_6 -> V_148 ) ;
F_61 ( V_6 -> V_130 ) ;
F_61 ( V_6 -> V_127 ) ;
F_61 ( V_6 -> V_106 ) ;
F_61 ( V_6 -> V_125 ) ;
F_61 ( V_6 -> V_123 ) ;
F_61 ( V_6 -> V_113 ) ;
F_40 ( V_6 -> V_126 . V_68 ) ;
F_40 ( V_6 -> V_124 . V_68 ) ;
F_40 ( V_6 ) ;
V_2 -> V_7 = NULL ;
}
