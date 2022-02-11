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
struct V_28 * V_29 = F_3 ( V_27 ) ;
struct V_26 * V_30 ;
struct V_31 * V_32 ;
struct V_33 V_34 ;
T_1 V_35 ;
if ( F_4 ( ! F_5 ( V_36 , & V_6 -> V_37 ) ) )
return;
F_6 ( & V_34 ) ;
if ( F_7 ( & V_6 -> V_38 ) > 20 ) {
F_8 ( V_2 , L_1 ) ;
return;
}
V_35 = V_27 -> V_39 ;
if ( V_29 -> V_40 & V_41 )
V_35 -= V_29 -> V_42 ;
V_30 = F_9 ( sizeof( * V_32 ) + V_29 -> V_42 + V_35 ,
V_43 ) ;
if ( ! V_30 ) {
F_8 ( V_2 , L_2 ) ;
return;
}
V_32 = (struct V_31 * ) F_10 ( V_30 , sizeof( * V_32 ) ) ;
V_32 -> V_44 = F_11 ( V_45 ) ;
V_32 -> V_46 = F_11 ( sizeof( * V_32 ) ) ;
V_32 -> V_47 = F_11 ( V_29 -> V_42 ) ;
V_32 -> V_48 = F_11 ( V_35 ) ;
V_32 -> V_49 = F_12 ( V_2 -> V_50 . V_51 ) ;
V_32 -> V_52 = F_12 ( V_2 -> V_50 . V_53 ) ;
V_32 -> V_54 = F_12 ( V_2 -> V_50 . V_55 ) ;
V_32 -> type = F_12 ( type ) ;
V_32 -> V_56 = V_29 -> V_57 -> V_58 -> V_59 ;
V_32 -> V_60 = V_29 -> V_57 -> V_61 ;
V_32 -> V_62 = F_11 ( V_34 . V_63 ) ;
V_32 -> V_64 = F_11 ( V_34 . V_65 ) ;
if ( ! ( V_29 -> V_40 & V_41 ) )
memcpy ( F_10 ( V_30 , V_29 -> V_42 ) , V_29 -> V_66 ,
V_29 -> V_42 ) ;
memcpy ( F_10 ( V_30 , V_27 -> V_39 ) , V_27 -> V_67 , V_27 -> V_39 ) ;
F_13 ( & V_6 -> V_38 , V_30 ) ;
F_14 ( & V_6 -> V_68 ) ;
if ( ! F_5 ( V_36 , & V_6 -> V_37 ) )
F_15 ( & V_6 -> V_38 ) ;
}
static int F_16 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
struct V_5 * V_6 = V_69 -> V_71 ;
V_70 -> V_72 = V_69 -> V_71 ;
if ( ! F_17 ( V_6 -> V_73 -> V_74 ) )
return - V_75 ;
return 0 ;
}
static int F_18 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
struct V_5 * V_6 = V_70 -> V_72 ;
F_19 ( V_6 -> V_73 -> V_74 ) ;
return 0 ;
}
static int F_20 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
struct V_5 * V_6 = V_69 -> V_71 ;
int V_76 ;
V_76 = F_16 ( V_69 , V_70 ) ;
if ( V_76 )
return V_76 ;
if ( F_21 ( V_36 , & V_6 -> V_37 ) ) {
F_18 ( V_69 , V_70 ) ;
return - V_75 ;
}
return 0 ;
}
static int F_22 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
struct V_5 * V_6 = V_69 -> V_71 ;
F_15 ( & V_6 -> V_38 ) ;
F_23 ( V_36 , & V_6 -> V_37 ) ;
return F_18 ( V_69 , V_70 ) ;
}
static T_2 F_24 ( struct V_70 * V_70 ,
char T_3 * V_77 ,
T_4 V_78 ,
T_5 * V_79 )
{
struct V_5 * V_6 = V_70 -> V_72 ;
struct V_26 * V_27 ;
T_4 V_10 ;
int V_76 ;
if ( V_70 -> V_80 & V_81 )
return - V_82 ;
V_76 =
F_25 ( V_6 -> V_68 ,
( V_27 =
F_26 ( & V_6 -> V_38 ) ) ) ;
if ( V_76 )
return V_76 ;
V_10 = F_27 ( T_4 , V_27 -> V_39 , V_78 ) ;
if ( F_28 ( V_77 , V_27 -> V_67 , V_10 ) ) {
V_10 = - V_83 ;
goto exit;
}
* V_79 += V_10 ;
exit:
F_29 ( V_27 ) ;
return V_10 ;
}
static unsigned int F_30 ( struct V_70 * V_70 ,
T_6 * V_84 )
{
struct V_5 * V_6 = V_70 -> V_72 ;
F_31 ( V_70 , & V_6 -> V_68 , V_84 ) ;
if ( ! F_32 ( & V_6 -> V_38 ) )
return V_85 | V_86 ;
return 0 ;
}
static T_2 F_33 ( struct V_70 * V_70 ,
char T_3 * V_77 ,
T_4 V_78 ,
T_5 * V_79 )
{
struct V_5 * V_6 = V_70 -> V_72 ;
struct V_87 * V_58 ;
unsigned long V_88 ;
unsigned int V_89 = 1 + V_6 -> V_2 -> V_90 ;
T_4 V_91 ;
char * V_67 ;
char * V_92 ;
if ( * V_79 )
return 0 ;
V_67 = F_34 ( V_89 , V_93 , V_94 ) ;
if ( ! V_67 )
return - V_95 ;
V_92 = V_67 +
sprintf ( V_67 , L_3 ) ;
F_35 (intf->rt2x00dev, queue) {
F_36 ( & V_58 -> V_96 , V_88 ) ;
V_92 += sprintf ( V_92 , L_4 ,
V_58 -> V_59 , ( unsigned int ) V_58 -> V_40 ,
V_58 -> V_97 , V_58 -> V_98 , V_58 -> V_78 ,
V_58 -> V_99 [ V_100 ] ,
V_58 -> V_99 [ V_101 ] ,
V_58 -> V_99 [ V_102 ] ) ;
F_37 ( & V_58 -> V_96 , V_88 ) ;
}
V_91 = strlen ( V_67 ) ;
V_91 = F_38 ( V_91 , V_78 ) ;
if ( F_28 ( V_77 , V_67 , V_91 ) ) {
F_39 ( V_67 ) ;
return - V_83 ;
}
F_39 ( V_67 ) ;
* V_79 += V_91 ;
return V_91 ;
}
static T_2 F_40 ( struct V_70 * V_70 ,
char T_3 * V_77 ,
T_4 V_78 ,
T_5 * V_79 )
{
struct V_5 * V_6 = V_70 -> V_72 ;
static const char * const V_103 [] = { L_5 , L_6 , L_7 , L_8 } ;
char * V_67 ;
char * V_92 ;
T_4 V_91 ;
unsigned int V_104 ;
if ( * V_79 )
return 0 ;
V_67 = F_41 ( ( 1 + V_15 ) * V_93 , V_94 ) ;
if ( ! V_67 )
return - V_95 ;
V_92 = V_67 ;
V_92 += sprintf ( V_67 , L_9 ) ;
for ( V_104 = 0 ; V_104 < V_15 ; V_104 ++ ) {
V_92 += sprintf ( V_92 , L_10 , V_103 [ V_104 ] ,
V_6 -> V_16 [ V_104 ] . V_17 ,
V_6 -> V_16 [ V_104 ] . V_19 ,
V_6 -> V_16 [ V_104 ] . V_21 ,
V_6 -> V_16 [ V_104 ] . V_23 ) ;
}
V_91 = strlen ( V_67 ) ;
V_91 = F_38 ( V_91 , V_78 ) ;
if ( F_28 ( V_77 , V_67 , V_91 ) ) {
F_39 ( V_67 ) ;
return - V_83 ;
}
F_39 ( V_67 ) ;
* V_79 += V_91 ;
return V_91 ;
}
static T_2 F_42 ( struct V_70 * V_70 ,
char T_3 * V_77 ,
T_4 V_78 ,
T_5 * V_79 )
{
struct V_5 * V_6 = V_70 -> V_72 ;
char line [ 16 ] ;
T_4 V_91 ;
if ( * V_79 )
return 0 ;
V_91 = sprintf ( line , L_11 , ( unsigned int ) V_6 -> V_2 -> V_40 ) ;
if ( F_28 ( V_77 , line , V_91 ) )
return - V_83 ;
* V_79 += V_91 ;
return V_91 ;
}
static T_2 F_43 ( struct V_70 * V_70 ,
char T_3 * V_77 ,
T_4 V_78 ,
T_5 * V_79 )
{
struct V_5 * V_6 = V_70 -> V_72 ;
char line [ 16 ] ;
T_4 V_91 ;
if ( * V_79 )
return 0 ;
V_91 = sprintf ( line , L_11 , ( unsigned int ) V_6 -> V_2 -> V_105 ) ;
if ( F_28 ( V_77 , line , V_91 ) )
return - V_83 ;
* V_79 += V_91 ;
return V_91 ;
}
static struct V_106 * F_44 ( const char * V_103 ,
struct V_5
* V_6 ,
struct V_107
* V_108 )
{
char * V_67 ;
V_67 = F_41 ( 3 * V_93 , V_94 ) ;
if ( ! V_67 )
return NULL ;
V_108 -> V_67 = V_67 ;
V_67 += sprintf ( V_67 , L_12 , V_6 -> V_2 -> V_109 -> V_103 ) ;
V_67 += sprintf ( V_67 , L_13 , V_110 ) ;
V_108 -> V_91 = strlen ( V_108 -> V_67 ) ;
return F_45 ( V_103 , V_111 , V_6 -> V_112 , V_108 ) ;
}
static struct V_106 * F_46 ( const char * V_103 ,
struct V_5
* V_6 ,
struct
V_107
* V_108 )
{
const struct V_113 * V_73 = V_6 -> V_73 ;
char * V_67 ;
V_67 = F_41 ( 9 * V_93 , V_94 ) ;
if ( ! V_67 )
return NULL ;
V_108 -> V_67 = V_67 ;
V_67 += sprintf ( V_67 , L_14 , V_6 -> V_2 -> V_50 . V_51 ) ;
V_67 += sprintf ( V_67 , L_15 , V_6 -> V_2 -> V_50 . V_53 ) ;
V_67 += sprintf ( V_67 , L_16 , V_6 -> V_2 -> V_50 . V_55 ) ;
V_67 += sprintf ( V_67 , L_17 ) ;
V_67 += sprintf ( V_67 , L_18 ) ;
#define F_47 ( T_7 ) \
{ \
if (debug->__name.read) \
data += sprintf(data, __stringify(__name) \
"\t%d\t%d\t%d\n", \
debug->__name.word_base, \
debug->__name.word_count, \
debug->__name.word_size); \
}
F_47 ( V_114 ) ;
F_47 ( V_115 ) ;
F_47 ( V_116 ) ;
F_47 ( V_53 ) ;
F_47 ( V_117 ) ;
#undef F_47
V_108 -> V_91 = strlen ( V_108 -> V_67 ) ;
return F_45 ( V_103 , V_111 , V_6 -> V_112 , V_108 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
const struct V_113 * V_73 = V_2 -> V_109 -> V_118 ;
struct V_5 * V_6 ;
V_6 = F_41 ( sizeof( struct V_5 ) , V_94 ) ;
if ( ! V_6 ) {
F_49 ( V_2 , L_19 ) ;
return;
}
V_6 -> V_73 = V_73 ;
V_6 -> V_2 = V_2 ;
V_2 -> V_7 = V_6 ;
V_6 -> V_112 =
F_50 ( V_6 -> V_2 -> V_109 -> V_103 ,
V_2 -> V_119 -> V_120 -> V_121 ) ;
if ( F_51 ( V_6 -> V_112 ) || ! V_6 -> V_112 )
goto exit;
V_6 -> V_122 =
F_44 ( L_20 , V_6 , & V_6 -> V_123 ) ;
if ( F_51 ( V_6 -> V_122 ) || ! V_6 -> V_122 )
goto exit;
V_6 -> V_124 =
F_46 ( L_21 ,
V_6 , & V_6 -> V_125 ) ;
if ( F_51 ( V_6 -> V_124 ) || ! V_6 -> V_124 )
goto exit;
V_6 -> V_126 = F_52 ( L_22 , V_111 ,
V_6 -> V_112 , V_6 ,
& V_127 ) ;
if ( F_51 ( V_6 -> V_126 ) || ! V_6 -> V_126 )
goto exit;
V_6 -> V_105 = F_52 ( L_23 , V_111 ,
V_6 -> V_112 , V_6 ,
& V_128 ) ;
if ( F_51 ( V_6 -> V_105 ) || ! V_6 -> V_105 )
goto exit;
V_6 -> V_129 =
F_50 ( L_24 , V_6 -> V_112 ) ;
if ( F_51 ( V_6 -> V_129 ) || ! V_6 -> V_129 )
goto exit;
#define F_53 ( T_8 , T_7 ) \
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
F_53 ( V_6 , V_114 ) ;
F_53 ( V_6 , V_115 ) ;
F_53 ( V_6 , V_116 ) ;
F_53 ( V_6 , V_53 ) ;
F_53 ( V_6 , V_117 ) ;
#undef F_53
V_6 -> V_130 =
F_50 ( L_25 , V_6 -> V_112 ) ;
if ( F_51 ( V_6 -> V_130 ) || ! V_6 -> V_130 )
goto exit;
V_6 -> V_131 =
F_52 ( L_26 , V_111 , V_6 -> V_130 ,
V_6 , & V_132 ) ;
if ( F_51 ( V_6 -> V_131 )
|| ! V_6 -> V_131 )
goto exit;
F_54 ( & V_6 -> V_38 ) ;
F_55 ( & V_6 -> V_68 ) ;
V_6 -> V_133 =
F_52 ( L_25 , V_111 , V_6 -> V_130 ,
V_6 , & V_134 ) ;
#ifdef F_56
if ( F_57 ( V_2 ) )
V_6 -> V_135 =
F_52 ( L_27 , V_136 , V_6 -> V_130 ,
V_6 , & V_137 ) ;
#endif
return;
exit:
F_58 ( V_2 ) ;
F_49 ( V_2 , L_28 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_59 ( ! V_6 ) )
return;
F_15 ( & V_6 -> V_38 ) ;
#ifdef F_56
F_60 ( V_6 -> V_135 ) ;
#endif
F_60 ( V_6 -> V_133 ) ;
F_60 ( V_6 -> V_131 ) ;
F_60 ( V_6 -> V_130 ) ;
F_60 ( V_6 -> V_138 ) ;
F_60 ( V_6 -> V_139 ) ;
F_60 ( V_6 -> V_140 ) ;
F_60 ( V_6 -> V_141 ) ;
F_60 ( V_6 -> V_142 ) ;
F_60 ( V_6 -> V_143 ) ;
F_60 ( V_6 -> V_144 ) ;
F_60 ( V_6 -> V_145 ) ;
F_60 ( V_6 -> V_146 ) ;
F_60 ( V_6 -> V_147 ) ;
F_60 ( V_6 -> V_129 ) ;
F_60 ( V_6 -> V_126 ) ;
F_60 ( V_6 -> V_105 ) ;
F_60 ( V_6 -> V_124 ) ;
F_60 ( V_6 -> V_122 ) ;
F_60 ( V_6 -> V_112 ) ;
F_39 ( V_6 -> V_125 . V_67 ) ;
F_39 ( V_6 -> V_123 . V_67 ) ;
F_39 ( V_6 ) ;
V_2 -> V_7 = NULL ;
}
