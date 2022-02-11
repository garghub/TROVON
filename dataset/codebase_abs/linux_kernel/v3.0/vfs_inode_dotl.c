static T_1 F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 == NULL ) ;
if ( V_2 -> V_3 & V_4 ) {
return V_2 -> V_5 ;
}
return F_3 () ;
}
static struct V_6 * F_4 ( struct V_1 * V_1 )
{
struct V_6 * V_6 ;
F_5 ( & V_1 -> V_7 ) ;
F_2 ( F_6 ( V_1 -> V_3 ) && ! F_7 ( & V_1 -> V_8 ) ) ;
V_6 = F_8 ( V_1 -> V_8 . V_9 , struct V_6 , V_10 ) ;
F_9 ( & V_1 -> V_7 ) ;
return V_6 ;
}
static struct V_1 * F_10 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
struct V_17 * V_18 )
{
int V_19 ;
unsigned long V_20 ;
struct V_1 * V_1 ;
struct V_21 * V_22 = V_12 -> V_23 ;
V_20 = F_11 ( V_14 ) ;
V_1 = F_12 ( V_12 , V_20 ) ;
if ( ! V_1 )
return F_13 ( - V_24 ) ;
if ( ! ( V_1 -> V_25 & V_26 ) )
return V_1 ;
V_19 = F_14 ( V_22 , V_1 , V_18 -> V_27 ) ;
if ( V_19 )
goto error;
F_15 ( V_18 , V_1 ) ;
#ifdef F_16
F_17 ( V_1 , & V_18 -> V_14 ) ;
F_18 ( V_1 ) ;
#endif
V_19 = F_19 ( V_1 , V_16 ) ;
if ( V_19 )
goto error;
F_20 ( V_1 ) ;
return V_1 ;
error:
F_20 ( V_1 ) ;
F_21 ( V_1 ) ;
return F_13 ( V_19 ) ;
}
struct V_1 *
F_22 ( struct V_21 * V_22 , struct V_15 * V_16 ,
struct V_11 * V_12 )
{
struct V_17 * V_18 ;
struct V_1 * V_1 = NULL ;
V_18 = F_23 ( V_16 , V_28 ) ;
if ( F_24 ( V_18 ) )
return F_25 ( V_18 ) ;
V_1 = F_10 ( V_12 , & V_18 -> V_14 , V_16 , V_18 ) ;
F_26 ( V_18 ) ;
return V_1 ;
}
static int
F_27 ( struct V_1 * V_29 , struct V_6 * V_6 , int V_30 ,
struct V_31 * V_32 )
{
int V_33 = 0 ;
T_1 V_34 ;
int V_35 ;
T_2 V_36 ;
char * V_37 = NULL ;
struct V_38 * V_39 ;
struct V_13 V_14 ;
struct V_1 * V_1 ;
struct V_15 * V_16 = NULL ;
struct V_40 * V_41 ;
struct V_15 * V_42 , * V_43 , * V_44 ;
struct V_21 * V_22 ;
struct V_45 * V_46 = NULL , * V_47 = NULL ;
V_22 = F_28 ( V_29 ) ;
if ( V_32 && V_32 -> V_35 & V_48 )
V_35 = V_32 -> V_49 . V_50 . V_35 - 1 ;
else {
return F_29 ( V_29 , V_6 , V_30 , 0 ) ;
}
V_37 = ( char * ) V_6 -> V_51 . V_37 ;
F_30 ( V_52 , L_1
L_2 , V_37 , V_35 , V_30 ) ;
V_42 = F_31 ( V_6 -> V_53 ) ;
if ( F_24 ( V_42 ) ) {
V_33 = F_32 ( V_42 ) ;
F_30 ( V_52 , L_3 , V_33 ) ;
return V_33 ;
}
V_43 = F_33 ( V_42 , 0 , NULL , 1 ) ;
if ( F_24 ( V_43 ) ) {
V_33 = F_32 ( V_43 ) ;
F_30 ( V_52 , L_4 , V_33 ) ;
return V_33 ;
}
V_34 = F_1 ( V_29 ) ;
V_36 = V_30 ;
V_33 = F_34 ( V_29 , & V_36 , & V_47 , & V_46 ) ;
if ( V_33 ) {
F_30 ( V_52 ,
L_5 , V_33 ) ;
goto error;
}
V_33 = F_35 ( V_43 , V_37 , V_35 , V_36 , V_34 , & V_14 ) ;
if ( V_33 < 0 ) {
F_30 ( V_52 ,
L_6 ,
V_33 ) ;
goto error;
}
F_36 ( V_29 ) ;
V_16 = F_33 ( V_42 , 1 , & V_37 , 1 ) ;
if ( F_24 ( V_16 ) ) {
V_33 = F_32 ( V_16 ) ;
F_30 ( V_52 , L_4 , V_33 ) ;
V_16 = NULL ;
goto error;
}
V_1 = F_37 ( V_22 , V_16 , V_29 -> V_54 ) ;
if ( F_24 ( V_1 ) ) {
V_33 = F_32 ( V_1 ) ;
F_30 ( V_52 , L_7 , V_33 ) ;
goto error;
}
F_38 ( V_6 , V_1 ) ;
V_33 = F_39 ( V_6 , V_16 ) ;
if ( V_33 < 0 )
goto error;
F_40 ( V_6 , V_47 , V_46 ) ;
V_41 = F_41 ( V_1 ) ;
F_42 ( & V_41 -> V_55 ) ;
if ( V_22 -> V_56 && ! V_41 -> V_57 &&
( ( V_35 & V_58 ) != V_59 ) ) {
V_44 = F_43 ( V_6 ) ;
if ( F_24 ( V_44 ) ) {
V_33 = F_32 ( V_44 ) ;
F_44 ( & V_41 -> V_55 ) ;
goto V_60;
}
V_41 -> V_57 = ( void * ) V_44 ;
}
F_44 ( & V_41 -> V_55 ) ;
V_39 = F_45 ( V_32 , V_6 , V_61 ) ;
if ( F_24 ( V_39 ) ) {
V_33 = F_32 ( V_39 ) ;
goto V_60;
}
V_39 -> V_62 = V_43 ;
#ifdef F_16
if ( V_22 -> V_56 )
F_46 ( V_1 , V_39 ) ;
#endif
return 0 ;
error:
if ( V_16 )
F_47 ( V_16 ) ;
V_60:
if ( V_43 )
F_47 ( V_43 ) ;
return V_33 ;
}
static int F_48 ( struct V_1 * V_29 ,
struct V_6 * V_6 , int V_30 )
{
int V_33 ;
struct V_21 * V_22 ;
struct V_15 * V_16 = NULL , * V_42 = NULL ;
T_1 V_34 ;
char * V_37 ;
T_2 V_36 ;
struct V_1 * V_1 ;
struct V_13 V_14 ;
struct V_6 * V_63 ;
struct V_45 * V_47 = NULL , * V_46 = NULL ;
F_30 ( V_52 , L_8 , V_6 -> V_51 . V_37 ) ;
V_33 = 0 ;
V_22 = F_28 ( V_29 ) ;
V_30 |= V_64 ;
if ( V_29 -> V_3 & V_4 )
V_30 |= V_4 ;
V_63 = F_4 ( V_29 ) ;
V_42 = F_31 ( V_63 ) ;
if ( F_24 ( V_42 ) ) {
V_33 = F_32 ( V_42 ) ;
F_30 ( V_52 , L_3 , V_33 ) ;
V_42 = NULL ;
goto error;
}
V_34 = F_1 ( V_29 ) ;
V_36 = V_30 ;
V_33 = F_34 ( V_29 , & V_36 , & V_47 , & V_46 ) ;
if ( V_33 ) {
F_30 ( V_52 ,
L_9 , V_33 ) ;
goto error;
}
V_37 = ( char * ) V_6 -> V_51 . V_37 ;
V_33 = F_49 ( V_42 , V_37 , V_36 , V_34 , & V_14 ) ;
if ( V_33 < 0 )
goto error;
if ( V_22 -> V_56 == V_65 || V_22 -> V_56 == V_66 ) {
V_16 = F_33 ( V_42 , 1 , & V_37 , 1 ) ;
if ( F_24 ( V_16 ) ) {
V_33 = F_32 ( V_16 ) ;
F_30 ( V_52 , L_4 ,
V_33 ) ;
V_16 = NULL ;
goto error;
}
V_1 = F_37 ( V_22 , V_16 , V_29 -> V_54 ) ;
if ( F_24 ( V_1 ) ) {
V_33 = F_32 ( V_1 ) ;
F_30 ( V_52 , L_7 ,
V_33 ) ;
goto error;
}
F_38 ( V_6 , V_1 ) ;
V_33 = F_39 ( V_6 , V_16 ) ;
if ( V_33 < 0 )
goto error;
V_16 = NULL ;
} else {
V_1 = F_50 ( V_29 -> V_54 , V_36 ) ;
if ( F_24 ( V_1 ) ) {
V_33 = F_32 ( V_1 ) ;
goto error;
}
F_38 ( V_6 , V_1 ) ;
}
F_40 ( V_6 , V_47 , V_46 ) ;
F_51 ( V_29 ) ;
F_36 ( V_29 ) ;
error:
if ( V_16 )
F_47 ( V_16 ) ;
return V_33 ;
}
static int
F_52 ( struct V_67 * V_68 , struct V_6 * V_6 ,
struct V_69 * V_70 )
{
int V_33 ;
struct V_21 * V_22 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
F_30 ( V_52 , L_10 , V_6 ) ;
V_33 = - V_71 ;
V_22 = F_53 ( V_6 ) ;
if ( V_22 -> V_56 == V_65 || V_22 -> V_56 == V_66 ) {
F_54 ( V_6 -> V_72 , V_70 ) ;
return 0 ;
}
V_16 = F_31 ( V_6 ) ;
if ( F_24 ( V_16 ) )
return F_32 ( V_16 ) ;
V_18 = F_23 ( V_16 , V_73 ) ;
if ( F_24 ( V_18 ) )
return F_32 ( V_18 ) ;
F_15 ( V_18 , V_6 -> V_72 ) ;
F_54 ( V_6 -> V_72 , V_70 ) ;
V_70 -> V_74 = V_18 -> V_75 ;
F_26 ( V_18 ) ;
return 0 ;
}
int F_55 ( struct V_6 * V_6 , struct V_76 * V_76 )
{
int V_19 ;
struct V_21 * V_22 ;
struct V_15 * V_16 ;
struct V_77 V_78 ;
F_30 ( V_52 , L_11 ) ;
V_19 = F_56 ( V_6 -> V_72 , V_76 ) ;
if ( V_19 )
return V_19 ;
V_78 . V_79 = V_76 -> V_80 ;
V_78 . V_36 = V_76 -> V_81 ;
V_78 . V_82 = V_76 -> V_83 ;
V_78 . V_34 = V_76 -> V_84 ;
V_78 . V_85 = V_76 -> V_86 ;
V_78 . V_87 = V_76 -> V_88 . V_89 ;
V_78 . V_90 = V_76 -> V_88 . V_91 ;
V_78 . V_92 = V_76 -> V_93 . V_89 ;
V_78 . V_94 = V_76 -> V_93 . V_91 ;
V_19 = - V_71 ;
V_22 = F_53 ( V_6 ) ;
V_16 = F_31 ( V_6 ) ;
if ( F_24 ( V_16 ) )
return F_32 ( V_16 ) ;
if ( F_57 ( V_6 -> V_72 -> V_3 ) )
F_58 ( V_6 -> V_72 -> V_95 ) ;
V_19 = F_59 ( V_16 , & V_78 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ( V_76 -> V_80 & V_96 ) &&
V_76 -> V_86 != F_60 ( V_6 -> V_72 ) )
F_61 ( V_6 -> V_72 , V_76 -> V_86 ) ;
F_36 ( V_6 -> V_72 ) ;
F_62 ( V_6 -> V_72 , V_76 ) ;
F_63 ( V_6 -> V_72 ) ;
if ( V_76 -> V_80 & V_97 ) {
V_19 = F_64 ( V_6 ) ;
if ( V_19 < 0 )
return V_19 ;
}
return 0 ;
}
void
F_15 ( struct V_17 * V_70 , struct V_1 * V_1 )
{
struct V_40 * V_41 = F_41 ( V_1 ) ;
if ( ( V_70 -> V_98 & V_28 ) == V_28 ) {
V_1 -> V_99 . V_89 = V_70 -> V_100 ;
V_1 -> V_99 . V_91 = V_70 -> V_101 ;
V_1 -> V_102 . V_89 = V_70 -> V_103 ;
V_1 -> V_102 . V_91 = V_70 -> V_104 ;
V_1 -> V_105 . V_89 = V_70 -> V_106 ;
V_1 -> V_105 . V_91 = V_70 -> V_107 ;
V_1 -> V_108 = V_70 -> V_109 ;
V_1 -> V_5 = V_70 -> V_110 ;
V_1 -> V_111 = V_70 -> V_112 ;
V_1 -> V_3 = V_70 -> V_27 ;
V_1 -> V_113 = F_65 ( V_70 -> V_114 ) ;
if ( ( F_66 ( V_1 -> V_3 ) ) || ( F_67 ( V_1 -> V_3 ) ) )
F_68 ( V_1 , V_1 -> V_3 , V_1 -> V_113 ) ;
F_69 ( V_1 , V_70 -> V_115 ) ;
V_1 -> V_116 = V_70 -> V_117 ;
} else {
if ( V_70 -> V_98 & V_118 ) {
V_1 -> V_99 . V_89 = V_70 -> V_100 ;
V_1 -> V_99 . V_91 = V_70 -> V_101 ;
}
if ( V_70 -> V_98 & V_119 ) {
V_1 -> V_102 . V_89 = V_70 -> V_103 ;
V_1 -> V_102 . V_91 = V_70 -> V_104 ;
}
if ( V_70 -> V_98 & V_120 ) {
V_1 -> V_105 . V_89 = V_70 -> V_106 ;
V_1 -> V_105 . V_91 = V_70 -> V_107 ;
}
if ( V_70 -> V_98 & V_121 )
V_1 -> V_108 = V_70 -> V_109 ;
if ( V_70 -> V_98 & V_122 )
V_1 -> V_5 = V_70 -> V_110 ;
if ( V_70 -> V_98 & V_123 )
V_1 -> V_111 = V_70 -> V_112 ;
if ( V_70 -> V_98 & V_124 ) {
V_1 -> V_3 = V_70 -> V_27 ;
if ( ( F_66 ( V_1 -> V_3 ) ) ||
( F_67 ( V_1 -> V_3 ) ) )
F_68 ( V_1 , V_1 -> V_3 ,
V_1 -> V_113 ) ;
}
if ( V_70 -> V_98 & V_125 )
V_1 -> V_113 = F_65 ( V_70 -> V_114 ) ;
if ( V_70 -> V_98 & V_126 )
F_69 ( V_1 , V_70 -> V_115 ) ;
if ( V_70 -> V_98 & V_127 )
V_1 -> V_116 = V_70 -> V_117 ;
}
if ( V_70 -> V_98 & V_128 )
V_1 -> V_129 = V_70 -> V_130 ;
V_41 -> V_131 &= ~ V_132 ;
}
static int
F_70 ( struct V_1 * V_29 , struct V_6 * V_6 ,
const char * V_133 )
{
int V_33 ;
T_1 V_34 ;
char * V_37 ;
struct V_13 V_14 ;
struct V_1 * V_1 ;
struct V_15 * V_42 ;
struct V_15 * V_16 = NULL ;
struct V_21 * V_22 ;
V_37 = ( char * ) V_6 -> V_51 . V_37 ;
F_30 ( V_52 , L_12 ,
V_29 -> V_20 , V_37 , V_133 ) ;
V_22 = F_28 ( V_29 ) ;
V_42 = F_31 ( V_6 -> V_53 ) ;
if ( F_24 ( V_42 ) ) {
V_33 = F_32 ( V_42 ) ;
F_30 ( V_52 , L_3 , V_33 ) ;
return V_33 ;
}
V_34 = F_1 ( V_29 ) ;
V_33 = F_71 ( V_42 , V_37 , ( char * ) V_133 , V_34 , & V_14 ) ;
if ( V_33 < 0 ) {
F_30 ( V_52 , L_13 , V_33 ) ;
goto error;
}
F_36 ( V_29 ) ;
if ( V_22 -> V_56 ) {
V_16 = F_33 ( V_42 , 1 , & V_37 , 1 ) ;
if ( F_24 ( V_16 ) ) {
V_33 = F_32 ( V_16 ) ;
F_30 ( V_52 , L_4 ,
V_33 ) ;
V_16 = NULL ;
goto error;
}
V_1 = F_37 ( V_22 , V_16 , V_29 -> V_54 ) ;
if ( F_24 ( V_1 ) ) {
V_33 = F_32 ( V_1 ) ;
F_30 ( V_52 , L_7 ,
V_33 ) ;
goto error;
}
F_38 ( V_6 , V_1 ) ;
V_33 = F_39 ( V_6 , V_16 ) ;
if ( V_33 < 0 )
goto error;
V_16 = NULL ;
} else {
V_1 = F_50 ( V_29 -> V_54 , V_134 ) ;
if ( F_24 ( V_1 ) ) {
V_33 = F_32 ( V_1 ) ;
goto error;
}
F_38 ( V_6 , V_1 ) ;
}
error:
if ( V_16 )
F_47 ( V_16 ) ;
return V_33 ;
}
static int
F_72 ( struct V_6 * V_135 , struct V_1 * V_29 ,
struct V_6 * V_6 )
{
int V_33 ;
char * V_37 ;
struct V_6 * V_63 ;
struct V_15 * V_42 , * V_136 ;
struct V_21 * V_22 ;
F_30 ( V_52 , L_14 ,
V_29 -> V_20 , V_135 -> V_51 . V_37 ,
V_6 -> V_51 . V_37 ) ;
V_22 = F_28 ( V_29 ) ;
V_63 = F_4 ( V_29 ) ;
V_42 = F_31 ( V_63 ) ;
if ( F_24 ( V_42 ) )
return F_32 ( V_42 ) ;
V_136 = F_31 ( V_135 ) ;
if ( F_24 ( V_136 ) )
return F_32 ( V_136 ) ;
V_37 = ( char * ) V_6 -> V_51 . V_37 ;
V_33 = F_73 ( V_42 , V_136 , ( char * ) V_6 -> V_51 . V_37 ) ;
if ( V_33 < 0 ) {
F_30 ( V_52 , L_15 , V_33 ) ;
return V_33 ;
}
F_36 ( V_29 ) ;
if ( V_22 -> V_56 == V_65 || V_22 -> V_56 == V_66 ) {
struct V_15 * V_16 ;
V_16 = F_31 ( V_135 ) ;
if ( F_24 ( V_16 ) )
return F_32 ( V_16 ) ;
F_74 ( V_16 , V_135 -> V_72 ) ;
}
F_75 ( V_135 -> V_72 ) ;
F_38 ( V_6 , V_135 -> V_72 ) ;
return V_33 ;
}
static int
F_29 ( struct V_1 * V_29 , struct V_6 * V_6 , int V_30 ,
T_3 V_137 )
{
int V_33 ;
T_1 V_34 ;
char * V_37 ;
T_2 V_36 ;
struct V_21 * V_22 ;
struct V_15 * V_16 = NULL , * V_42 = NULL ;
struct V_1 * V_1 ;
struct V_13 V_14 ;
struct V_6 * V_63 ;
struct V_45 * V_47 = NULL , * V_46 = NULL ;
F_30 ( V_52 ,
L_16 , V_29 -> V_20 ,
V_6 -> V_51 . V_37 , V_30 , F_76 ( V_137 ) , F_77 ( V_137 ) ) ;
if ( ! F_78 ( V_137 ) )
return - V_138 ;
V_22 = F_28 ( V_29 ) ;
V_63 = F_4 ( V_29 ) ;
V_42 = F_31 ( V_63 ) ;
if ( F_24 ( V_42 ) ) {
V_33 = F_32 ( V_42 ) ;
F_30 ( V_52 , L_3 , V_33 ) ;
V_42 = NULL ;
goto error;
}
V_34 = F_1 ( V_29 ) ;
V_36 = V_30 ;
V_33 = F_34 ( V_29 , & V_36 , & V_47 , & V_46 ) ;
if ( V_33 ) {
F_30 ( V_52 ,
L_17 , V_33 ) ;
goto error;
}
V_37 = ( char * ) V_6 -> V_51 . V_37 ;
V_33 = F_79 ( V_42 , V_37 , V_36 , V_137 , V_34 , & V_14 ) ;
if ( V_33 < 0 )
goto error;
F_36 ( V_29 ) ;
if ( V_22 -> V_56 == V_65 || V_22 -> V_56 == V_66 ) {
V_16 = F_33 ( V_42 , 1 , & V_37 , 1 ) ;
if ( F_24 ( V_16 ) ) {
V_33 = F_32 ( V_16 ) ;
F_30 ( V_52 , L_4 ,
V_33 ) ;
V_16 = NULL ;
goto error;
}
V_1 = F_37 ( V_22 , V_16 , V_29 -> V_54 ) ;
if ( F_24 ( V_1 ) ) {
V_33 = F_32 ( V_1 ) ;
F_30 ( V_52 , L_7 ,
V_33 ) ;
goto error;
}
F_38 ( V_6 , V_1 ) ;
V_33 = F_39 ( V_6 , V_16 ) ;
if ( V_33 < 0 )
goto error;
V_16 = NULL ;
} else {
V_1 = F_50 ( V_29 -> V_54 , V_36 ) ;
if ( F_24 ( V_1 ) ) {
V_33 = F_32 ( V_1 ) ;
goto error;
}
F_38 ( V_6 , V_1 ) ;
}
F_40 ( V_6 , V_47 , V_46 ) ;
error:
if ( V_16 )
F_47 ( V_16 ) ;
return V_33 ;
}
static void *
F_80 ( struct V_6 * V_6 , struct V_31 * V_32 )
{
int V_19 ;
struct V_15 * V_16 ;
char * V_139 = F_81 () ;
char * V_140 ;
F_30 ( V_52 , L_18 , V_6 -> V_51 . V_37 ) ;
if ( ! V_139 ) {
V_139 = F_13 ( - V_24 ) ;
goto V_141;
}
V_16 = F_31 ( V_6 ) ;
if ( F_24 ( V_16 ) ) {
F_82 ( V_139 ) ;
V_139 = F_25 ( V_16 ) ;
goto V_141;
}
V_19 = F_83 ( V_16 , & V_140 ) ;
if ( ! V_19 ) {
strcpy ( V_139 , V_140 ) ;
F_26 ( V_140 ) ;
goto V_141;
}
F_82 ( V_139 ) ;
V_139 = F_13 ( V_19 ) ;
V_141:
F_84 ( V_32 , V_139 ) ;
return NULL ;
}
int F_74 ( struct V_15 * V_16 , struct V_1 * V_1 )
{
T_4 V_142 ;
struct V_17 * V_18 ;
struct V_21 * V_22 ;
V_22 = F_28 ( V_1 ) ;
V_18 = F_23 ( V_16 , V_73 ) ;
if ( F_24 ( V_18 ) )
return F_32 ( V_18 ) ;
F_5 ( & V_1 -> V_7 ) ;
V_142 = V_1 -> V_142 ;
F_15 ( V_18 , V_1 ) ;
if ( V_22 -> V_56 )
V_1 -> V_142 = V_142 ;
F_9 ( & V_1 -> V_7 ) ;
F_26 ( V_18 ) ;
return 0 ;
}
