static int F_1 ( int * V_1 , void * * V_2 , T_1 * V_3 )
{
const T_2 * V_4 ;
int V_5 ;
if ( V_3 == NULL || ( V_4 = F_2 ( V_3 ) ) == NULL ) {
F_3 ( V_6 , V_7 ) ;
return 0 ;
}
if ( F_4 ( V_4 )
&& ( V_5 = F_5 ( V_4 ) ) )
{
* V_2 = F_6 ( V_5 ) ;
* V_1 = V_8 ;
} else {
T_3 * V_9 = NULL ;
V_9 = F_7 () ;
if ( V_9 == NULL )
return 0 ;
V_9 -> V_10 = F_8 ( V_3 , & V_9 -> V_11 ) ;
if ( V_9 -> V_10 <= 0 ) {
F_9 ( V_9 ) ;
F_3 ( V_6 , V_12 ) ;
return 0 ;
}
* V_2 = V_9 ;
* V_1 = V_13 ;
}
return 1 ;
}
static int F_10 ( T_4 * V_14 , const T_5 * V_15 )
{
T_1 * V_3 = V_15 -> V_15 . V_16 ;
void * V_17 = NULL ;
int V_18 ;
unsigned char * V_19 = NULL , * V_20 ;
int V_21 ;
if ( ! F_1 ( & V_18 , & V_17 , V_3 ) ) {
F_3 ( V_22 , V_12 ) ;
return 0 ;
}
V_21 = F_11 ( V_3 , NULL ) ;
if ( V_21 <= 0 )
goto V_23;
V_19 = F_12 ( V_21 ) ;
if ( V_19 == NULL )
goto V_23;
V_20 = V_19 ;
V_21 = F_11 ( V_3 , & V_20 ) ;
if ( V_21 <= 0 )
goto V_23;
if ( F_13 ( V_14 , F_6 ( V_24 ) ,
V_18 , V_17 , V_19 , V_21 ) )
return 1 ;
V_23:
if ( V_18 == V_8 )
F_14 ( V_17 ) ;
else
F_9 ( V_17 ) ;
F_15 ( V_19 ) ;
return 0 ;
}
static T_1 * F_16 ( int V_18 , const void * V_17 )
{
T_1 * V_25 = NULL ;
if ( V_18 == V_13 ) {
const T_3 * V_9 = V_17 ;
const unsigned char * V_26 = NULL ;
int V_27 ;
V_26 = V_9 -> V_11 ;
V_27 = V_9 -> V_10 ;
if ( ( V_25 = F_17 ( NULL , & V_26 , V_27 ) ) == NULL ) {
F_3 ( V_28 , V_29 ) ;
goto V_30;
}
} else if ( V_18 == V_8 ) {
const T_6 * V_31 = V_17 ;
T_2 * V_4 ;
if ( ( V_25 = F_18 () ) == NULL ) {
F_3 ( V_28 , V_32 ) ;
goto V_30;
}
V_4 = F_19 ( F_20 ( V_31 ) ) ;
if ( V_4 == NULL )
goto V_30;
F_21 ( V_4 , V_33 ) ;
if ( F_22 ( V_25 , V_4 ) == 0 )
goto V_30;
F_23 ( V_4 ) ;
} else {
F_3 ( V_28 , V_29 ) ;
goto V_30;
}
return V_25 ;
V_30:
F_24 ( V_25 ) ;
return NULL ;
}
static int F_25 ( T_5 * V_15 , T_4 * V_34 )
{
const unsigned char * V_20 = NULL ;
const void * V_17 ;
int V_18 , V_35 ;
T_1 * V_25 = NULL ;
T_7 * V_36 ;
if ( ! F_26 ( NULL , & V_20 , & V_35 , & V_36 , V_34 ) )
return 0 ;
F_27 ( NULL , & V_18 , & V_17 , V_36 ) ;
V_25 = F_16 ( V_18 , V_17 ) ;
if ( ! V_25 ) {
F_3 ( V_37 , V_12 ) ;
return 0 ;
}
if ( ! F_28 ( & V_25 , & V_20 , V_35 ) ) {
F_3 ( V_37 , V_29 ) ;
goto V_30;
}
F_29 ( V_15 , V_25 ) ;
return 1 ;
V_30:
F_24 ( V_25 ) ;
return 0 ;
}
static int F_30 ( const T_5 * V_38 , const T_5 * V_39 )
{
int V_40 ;
const T_2 * V_4 = F_2 ( V_39 -> V_15 . V_16 ) ;
const T_8 * V_41 = F_31 ( V_38 -> V_15 . V_16 ) ,
* V_42 = F_31 ( V_39 -> V_15 . V_16 ) ;
V_40 = F_32 ( V_4 , V_41 , V_42 , NULL ) ;
if ( V_40 == 0 )
return 1 ;
if ( V_40 == 1 )
return 0 ;
return - 2 ;
}
static int F_33 ( T_5 * V_15 , const T_9 * V_43 )
{
const unsigned char * V_20 = NULL ;
const void * V_17 ;
int V_18 , V_35 ;
T_1 * V_25 = NULL ;
const T_7 * V_36 ;
if ( ! F_34 ( NULL , & V_20 , & V_35 , & V_36 , V_43 ) )
return 0 ;
F_27 ( NULL , & V_18 , & V_17 , V_36 ) ;
V_25 = F_16 ( V_18 , V_17 ) ;
if ( ! V_25 )
goto V_44;
if ( ! F_35 ( & V_25 , & V_20 , V_35 ) ) {
F_3 ( V_45 , V_29 ) ;
goto V_30;
}
F_29 ( V_15 , V_25 ) ;
return 1 ;
V_44:
F_3 ( V_45 , V_12 ) ;
V_30:
F_24 ( V_25 ) ;
return 0 ;
}
static int F_36 ( T_9 * V_43 , const T_5 * V_15 )
{
T_1 V_3 = * ( V_15 -> V_15 . V_16 ) ;
unsigned char * V_46 , * V_20 ;
int V_47 , V_18 ;
void * V_17 ;
unsigned int V_48 ;
if ( ! F_1 ( & V_18 , & V_17 , & V_3 ) ) {
F_3 ( V_49 , V_29 ) ;
return 0 ;
}
V_48 = F_37 ( & V_3 ) ;
F_38 ( & V_3 , V_48 | V_50 ) ;
V_47 = F_39 ( & V_3 , NULL ) ;
if ( ! V_47 ) {
F_3 ( V_49 , V_12 ) ;
return 0 ;
}
V_46 = F_12 ( V_47 ) ;
if ( V_46 == NULL ) {
F_3 ( V_49 , V_32 ) ;
return 0 ;
}
V_20 = V_46 ;
if ( ! F_39 ( & V_3 , & V_20 ) ) {
F_15 ( V_46 ) ;
F_3 ( V_49 , V_12 ) ;
return 0 ;
}
if ( ! F_40 ( V_43 , F_6 ( V_51 ) , 0 ,
V_18 , V_17 , V_46 , V_47 ) )
return 0 ;
return 1 ;
}
static int F_41 ( const T_5 * V_15 )
{
return F_42 ( V_15 -> V_15 . V_16 ) ;
}
static int F_43 ( const T_5 * V_15 )
{
return F_44 ( F_2 ( V_15 -> V_15 . V_16 ) ) ;
}
static int F_45 ( const T_5 * V_15 )
{
int V_52 = F_43 ( V_15 ) ;
if ( V_52 >= 512 )
return 256 ;
if ( V_52 >= 384 )
return 192 ;
if ( V_52 >= 256 )
return 128 ;
if ( V_52 >= 224 )
return 112 ;
if ( V_52 >= 160 )
return 80 ;
return V_52 / 2 ;
}
static int F_46 ( const T_5 * V_15 )
{
if ( V_15 -> V_15 . V_16 == NULL || F_2 ( V_15 -> V_15 . V_16 ) == NULL )
return 1 ;
return 0 ;
}
static int F_47 ( T_5 * V_53 , const T_5 * V_54 )
{
T_2 * V_4 = F_48 ( F_2 ( V_54 -> V_15 . V_16 ) ) ;
if ( V_4 == NULL )
return 0 ;
if ( V_53 -> V_15 . V_16 == NULL ) {
V_53 -> V_15 . V_16 = F_18 () ;
if ( V_53 -> V_15 . V_16 == NULL )
return 0 ;
}
if ( F_22 ( V_53 -> V_15 . V_16 , V_4 ) == 0 )
return 0 ;
F_23 ( V_4 ) ;
return 1 ;
}
static int F_49 ( const T_5 * V_38 , const T_5 * V_39 )
{
const T_2 * V_55 = F_2 ( V_38 -> V_15 . V_16 ) ,
* V_56 = F_2 ( V_39 -> V_15 . V_16 ) ;
if ( F_50 ( V_55 , V_56 , NULL ) )
return 0 ;
else
return 1 ;
}
static void F_51 ( T_5 * V_15 )
{
F_24 ( V_15 -> V_15 . V_16 ) ;
}
static int F_52 ( T_10 * V_57 , const T_1 * V_58 , int V_59 , T_11 V_60 )
{
const char * V_61 ;
unsigned char * V_62 = NULL , * V_63 = NULL ;
T_12 V_64 = 0 , V_65 = 0 ;
int V_66 = 0 ;
const T_2 * V_4 ;
if ( V_58 == NULL || ( V_4 = F_2 ( V_58 ) ) == NULL ) {
F_3 ( V_67 , V_68 ) ;
return 0 ;
}
if ( V_60 != V_69 ) {
V_65 = F_53 ( V_58 , F_54 ( V_58 ) , & V_63 , NULL ) ;
if ( V_65 == 0 )
goto V_23;
}
if ( V_60 == V_70 && F_55 ( V_58 ) != NULL ) {
V_64 = F_56 ( V_58 , & V_62 ) ;
if ( V_64 == 0 )
goto V_23;
}
if ( V_60 == V_70 )
V_61 = L_1 ;
else if ( V_60 == V_71 )
V_61 = L_2 ;
else
V_61 = L_3 ;
if ( ! F_57 ( V_57 , V_59 , 128 ) )
goto V_23;
if ( F_58 ( V_57 , L_4 , V_61 ,
F_44 ( V_4 ) ) <= 0 )
goto V_23;
if ( V_64 != 0 ) {
if ( F_58 ( V_57 , L_5 , V_59 , L_6 ) <= 0 )
goto V_23;
if ( F_59 ( V_57 , V_62 , V_64 , V_59 + 4 ) == 0 )
goto V_23;
}
if ( V_65 != 0 ) {
if ( F_58 ( V_57 , L_7 , V_59 , L_6 ) <= 0 )
goto V_23;
if ( F_59 ( V_57 , V_63 , V_65 , V_59 + 4 ) == 0 )
goto V_23;
}
if ( ! F_60 ( V_57 , V_4 , V_59 ) )
goto V_23;
V_66 = 1 ;
V_23:
if ( ! V_66 )
F_3 ( V_67 , V_12 ) ;
F_61 ( V_62 , V_64 ) ;
F_15 ( V_63 ) ;
return V_66 ;
}
static int F_62 ( T_5 * V_15 ,
const unsigned char * * V_72 , int V_73 )
{
T_1 * V_25 ;
if ( ( V_25 = F_17 ( NULL , V_72 , V_73 ) ) == NULL ) {
F_3 ( V_74 , V_12 ) ;
return 0 ;
}
F_29 ( V_15 , V_25 ) ;
return 1 ;
}
static int F_63 ( const T_5 * V_15 , unsigned char * * V_72 )
{
return F_8 ( V_15 -> V_15 . V_16 , V_72 ) ;
}
static int F_64 ( T_10 * V_57 , const T_5 * V_15 , int V_75 ,
T_13 * V_76 )
{
return F_52 ( V_57 , V_15 -> V_15 . V_16 , V_75 , V_69 ) ;
}
static int F_65 ( T_10 * V_57 , const T_5 * V_15 , int V_75 ,
T_13 * V_76 )
{
return F_52 ( V_57 , V_15 -> V_15 . V_16 , V_75 , V_71 ) ;
}
static int F_66 ( T_10 * V_57 , const T_5 * V_15 , int V_75 ,
T_13 * V_76 )
{
return F_52 ( V_57 , V_15 -> V_15 . V_16 , V_75 , V_70 ) ;
}
static int F_67 ( T_5 * V_15 ,
const unsigned char * * V_72 , int V_73 )
{
T_1 * V_16 ;
if ( ( V_16 = F_35 ( NULL , V_72 , V_73 ) ) == NULL ) {
F_3 ( V_77 , V_29 ) ;
return 0 ;
}
F_29 ( V_15 , V_16 ) ;
return 1 ;
}
static int F_68 ( const T_5 * V_15 , unsigned char * * V_72 )
{
return F_39 ( V_15 -> V_15 . V_16 , V_72 ) ;
}
static int F_69 ( T_5 * V_15 , int V_78 , long V_79 , void * V_80 )
{
switch ( V_78 ) {
case V_81 :
if ( V_79 == 0 ) {
int V_82 , V_83 ;
T_7 * V_84 , * V_85 ;
F_70 ( V_80 , NULL , & V_84 , & V_85 ) ;
if ( V_84 == NULL || V_84 -> V_86 == NULL )
return - 1 ;
V_83 = F_20 ( V_84 -> V_86 ) ;
if ( V_83 == V_87 )
return - 1 ;
if ( ! F_71 ( & V_82 , V_83 , F_72 ( V_15 ) ) )
return - 1 ;
F_73 ( V_85 , F_6 ( V_82 ) , V_88 , 0 ) ;
}
return 1 ;
#ifndef F_74
case V_89 :
if ( V_79 == 0 ) {
int V_82 , V_83 ;
T_7 * V_84 , * V_85 ;
F_75 ( V_80 , NULL , NULL , & V_84 , & V_85 ) ;
if ( V_84 == NULL || V_84 -> V_86 == NULL )
return - 1 ;
V_83 = F_20 ( V_84 -> V_86 ) ;
if ( V_83 == V_87 )
return - 1 ;
if ( ! F_71 ( & V_82 , V_83 , F_72 ( V_15 ) ) )
return - 1 ;
F_73 ( V_85 , F_6 ( V_82 ) , V_88 , 0 ) ;
}
return 1 ;
case V_90 :
if ( V_79 == 1 )
return F_76 ( V_80 ) ;
else if ( V_79 == 0 )
return F_77 ( V_80 ) ;
return - 2 ;
case V_91 :
* ( int * ) V_80 = V_92 ;
return 1 ;
#endif
case V_93 :
* ( int * ) V_80 = V_94 ;
return 2 ;
case V_95 :
return F_78 ( F_79 ( V_15 ) , V_80 , V_79 , NULL ) ;
case V_96 :
return F_53 ( F_79 ( V_15 ) ,
V_97 , V_80 , NULL ) ;
default:
return - 2 ;
}
}
int F_80 ( T_10 * V_57 , const T_1 * V_58 , int V_59 )
{
int V_98 = F_55 ( V_58 ) != NULL ;
return F_52 ( V_57 , V_58 , V_59 ,
V_98 ? V_70 : V_71 ) ;
}
int F_81 ( T_10 * V_57 , const T_1 * V_58 )
{
return F_52 ( V_57 , V_58 , 4 , V_69 ) ;
}
static int F_82 ( T_14 * V_99 ,
T_7 * V_100 , T_15 * V_34 )
{
const T_6 * V_101 ;
int V_102 ;
const void * V_103 ;
int V_104 = 0 ;
T_5 * V_105 = NULL ;
T_1 * V_106 = NULL ;
const unsigned char * V_20 ;
int V_107 ;
F_27 ( & V_101 , & V_102 , & V_103 , V_100 ) ;
if ( F_20 ( V_101 ) != V_51 )
goto V_23;
if ( V_102 == V_88 || V_102 == V_108 ) {
const T_2 * V_109 ;
T_5 * V_14 ;
V_14 = F_83 ( V_99 ) ;
if ( ! V_14 )
goto V_23;
V_109 = F_2 ( V_14 -> V_15 . V_16 ) ;
V_106 = F_18 () ;
if ( V_106 == NULL )
goto V_23;
if ( ! F_22 ( V_106 , V_109 ) )
goto V_23;
} else {
V_106 = F_16 ( V_102 , V_103 ) ;
if ( ! V_106 )
goto V_23;
}
V_107 = F_84 ( V_34 ) ;
V_20 = F_85 ( V_34 ) ;
if ( ! V_20 || ! V_107 )
goto V_23;
if ( ! F_28 ( & V_106 , & V_20 , V_107 ) )
goto V_23;
V_105 = F_86 () ;
if ( V_105 == NULL )
goto V_23;
F_87 ( V_105 , V_106 ) ;
if ( F_88 ( V_99 , V_105 ) > 0 )
V_104 = 1 ;
V_23:
F_24 ( V_106 ) ;
F_89 ( V_105 ) ;
return V_104 ;
}
static int F_90 ( T_14 * V_99 , int V_110 )
{
int V_111 , V_112 , V_113 ;
const T_16 * V_114 ;
if ( V_110 == V_87 )
return 0 ;
if ( ! F_91 ( V_110 , & V_112 , & V_111 ) )
return 0 ;
if ( V_111 == V_115 )
V_113 = 0 ;
else if ( V_111 == V_116 )
V_113 = 1 ;
else
return 0 ;
if ( F_92 ( V_99 , V_113 ) <= 0 )
return 0 ;
if ( F_93 ( V_99 , V_117 ) <= 0 )
return 0 ;
V_114 = F_94 ( V_112 ) ;
if ( ! V_114 )
return 0 ;
if ( F_95 ( V_99 , V_114 ) <= 0 )
return 0 ;
return 1 ;
}
static int F_96 ( T_14 * V_99 , T_17 * V_118 )
{
int V_104 = 0 ;
T_7 * V_100 , * V_119 = NULL ;
T_18 * V_120 ;
const unsigned char * V_20 ;
unsigned char * V_121 = NULL ;
int V_107 , V_122 ;
const T_19 * V_123 ;
T_20 * V_124 ;
if ( ! F_97 ( V_118 , & V_100 , & V_120 ) )
return 0 ;
if ( ! F_90 ( V_99 , F_20 ( V_100 -> V_86 ) ) ) {
F_3 ( V_125 , V_126 ) ;
return 0 ;
}
if ( V_100 -> V_127 -> type != V_13 )
return 0 ;
V_20 = V_100 -> V_127 -> V_128 . V_129 -> V_11 ;
V_107 = V_100 -> V_127 -> V_128 . V_129 -> V_10 ;
V_119 = F_98 ( NULL , & V_20 , V_107 ) ;
if ( ! V_119 )
goto V_23;
V_124 = F_99 ( V_118 ) ;
if ( ! V_124 )
goto V_23;
V_123 = F_100 ( V_119 -> V_86 ) ;
if ( ! V_123 || F_101 ( V_123 ) != V_130 )
goto V_23;
if ( ! F_102 ( V_124 , V_123 , NULL , NULL , NULL ) )
goto V_23;
if ( F_103 ( V_124 , V_119 -> V_127 ) <= 0 )
goto V_23;
V_122 = F_104 ( V_124 ) ;
if ( F_105 ( V_99 , V_122 ) <= 0 )
goto V_23;
V_107 = F_106 ( & V_121 , V_119 , V_120 , V_122 ) ;
if ( ! V_107 )
goto V_23;
if ( F_107 ( V_99 , V_121 , V_107 ) <= 0 )
goto V_23;
V_121 = NULL ;
V_104 = 1 ;
V_23:
F_108 ( V_119 ) ;
F_15 ( V_121 ) ;
return V_104 ;
}
static int F_76 ( T_17 * V_118 )
{
T_14 * V_99 ;
V_99 = F_109 ( V_118 ) ;
if ( ! V_99 )
return 0 ;
if ( ! F_110 ( V_99 ) ) {
T_7 * V_100 ;
T_15 * V_34 ;
if ( ! F_111 ( V_118 , & V_100 , & V_34 ,
NULL , NULL , NULL ) )
return 0 ;
if ( ! V_100 || ! V_34 )
return 0 ;
if ( ! F_82 ( V_99 , V_100 , V_34 ) ) {
F_3 ( V_131 , V_132 ) ;
return 0 ;
}
}
if ( ! F_96 ( V_99 , V_118 ) ) {
F_3 ( V_131 , V_133 ) ;
return 0 ;
}
return 1 ;
}
static int F_77 ( T_17 * V_118 )
{
T_14 * V_99 ;
T_5 * V_15 ;
T_20 * V_76 ;
int V_122 ;
T_7 * V_134 , * V_135 = NULL ;
const T_6 * V_101 ;
T_15 * V_34 ;
T_3 * V_136 ;
T_18 * V_120 ;
unsigned char * V_19 = NULL ;
int V_21 ;
int V_104 = 0 ;
int V_137 , V_138 , V_111 , V_139 ;
const T_16 * V_114 ;
V_99 = F_109 ( V_118 ) ;
if ( ! V_99 )
return 0 ;
V_15 = F_83 ( V_99 ) ;
if ( ! F_111 ( V_118 , & V_134 , & V_34 ,
NULL , NULL , NULL ) )
goto V_23;
F_27 ( & V_101 , NULL , NULL , V_134 ) ;
if ( V_101 == F_6 ( V_87 ) ) {
T_1 * V_25 = V_15 -> V_15 . V_16 ;
unsigned char * V_20 ;
V_21 = F_11 ( V_25 , NULL ) ;
if ( V_21 <= 0 )
goto V_23;
V_19 = F_12 ( V_21 ) ;
if ( V_19 == NULL )
goto V_23;
V_20 = V_19 ;
V_21 = F_11 ( V_25 , & V_20 ) ;
if ( V_21 <= 0 )
goto V_23;
F_112 ( V_34 , V_19 , V_21 ) ;
V_34 -> V_140 &= ~ ( V_141 | 0x07 ) ;
V_34 -> V_140 |= V_141 ;
V_19 = NULL ;
F_73 ( V_134 , F_6 ( V_51 ) ,
V_88 , NULL ) ;
}
V_138 = F_113 ( V_99 ) ;
if ( V_138 <= 0 )
goto V_23;
if ( ! F_114 ( V_99 , & V_114 ) )
goto V_23;
V_137 = F_115 ( V_99 ) ;
if ( V_137 < 0 )
goto V_23;
else if ( V_137 == 0 )
V_137 = V_115 ;
else if ( V_137 == 1 )
V_137 = V_116 ;
if ( V_138 == V_142 ) {
V_138 = V_117 ;
if ( F_93 ( V_99 , V_138 ) <= 0 )
goto V_23;
} else
goto V_23;
if ( V_114 == NULL ) {
V_114 = F_116 () ;
if ( F_95 ( V_99 , V_114 ) <= 0 )
goto V_23;
}
if ( ! F_97 ( V_118 , & V_134 , & V_120 ) )
goto V_23;
if ( ! F_71 ( & V_111 , F_117 ( V_114 ) , V_137 ) )
goto V_23;
V_76 = F_99 ( V_118 ) ;
V_139 = F_118 ( V_76 ) ;
V_122 = F_104 ( V_76 ) ;
V_135 = F_119 () ;
if ( V_135 == NULL )
goto V_23;
V_135 -> V_86 = F_6 ( V_139 ) ;
V_135 -> V_127 = F_120 () ;
if ( V_135 -> V_127 == NULL )
goto V_23;
if ( F_121 ( V_76 , V_135 -> V_127 ) <= 0 )
goto V_23;
if ( F_122 ( V_135 -> V_127 ) == V_87 ) {
F_123 ( V_135 -> V_127 ) ;
V_135 -> V_127 = NULL ;
}
if ( F_105 ( V_99 , V_122 ) <= 0 )
goto V_23;
V_21 = F_106 ( & V_19 , V_135 , V_120 , V_122 ) ;
if ( ! V_21 )
goto V_23;
if ( F_107 ( V_99 , V_19 , V_21 ) <= 0 )
goto V_23;
V_19 = NULL ;
V_21 = F_124 ( V_135 , & V_19 ) ;
if ( ! V_19 || ! V_21 )
goto V_23;
V_136 = F_7 () ;
if ( V_136 == NULL )
goto V_23;
F_112 ( V_136 , V_19 , V_21 ) ;
V_19 = NULL ;
F_73 ( V_134 , F_6 ( V_111 ) , V_13 , V_136 ) ;
V_104 = 1 ;
V_23:
F_15 ( V_19 ) ;
F_108 ( V_135 ) ;
return V_104 ;
}
