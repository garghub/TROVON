static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
F_4 ( & V_10 -> V_12 ) ;
}
static int F_5 ( struct V_9 * V_10 , char * V_13 , T_1 V_14 )
{
struct V_7 * V_8 = V_10 -> V_15 ;
int V_16 ;
V_8 -> V_17 = V_14 < F_6 ( V_10 -> V_18 . V_19 . V_20 ) ;
F_7 ( & V_10 -> V_18 . V_21 . V_22 ) ;
V_8 -> V_23 = V_13 ;
V_8 -> V_24 = V_14 ;
if ( V_8 -> V_23 == NULL )
V_8 -> V_23 = ( void * ) 0xDEADBABE ;
F_8 ( & V_10 -> V_12 ) ;
V_16 = F_9 ( V_10 -> V_25 -> V_26 , V_8 , V_27 ) ;
if ( F_10 ( V_16 < 0 ) )
return V_16 ;
V_16 = F_11 ( & V_10 -> V_12 ) ;
if ( F_10 ( V_16 ) ) {
F_12 ( V_10 -> V_25 -> V_26 , V_8 ) ;
return - V_28 ;
}
V_10 -> V_29 = V_30 ;
return V_10 -> V_31 ;
}
static int F_13 ( struct V_9 * V_10 )
{
if ( V_10 -> V_18 . V_32 ) {
F_14 ( L_1 ) ;
F_15 ( V_10 -> V_25 -> V_26 ) ;
V_10 -> V_29 = V_30 ;
return - V_33 ;
} else {
F_16 ( L_2 ) ;
return - V_34 ;
}
}
static T_2 F_17 ( struct V_35 * V_35 , const char T_3 * V_23 ,
T_1 V_14 , T_4 * V_36 )
{
struct V_9 * V_10 = V_35 -> V_37 ;
T_2 V_16 ;
char * V_13 ;
F_18 () ;
if ( F_19 ( V_10 ) == V_38 )
return - V_39 ;
V_16 = F_20 ( & V_10 -> V_40 , V_35 -> V_41 & V_42 ) ;
if ( F_10 ( V_16 < 0 ) )
return V_16 ;
switch ( V_10 -> V_43 ) {
case V_44 :
case V_45 :
if ( F_10 ( V_14 < 16 ) ) {
V_16 = - V_46 ;
break;
}
V_13 = F_21 ( V_23 , V_14 ) ;
if ( F_22 ( V_13 ) ) {
V_16 = F_23 ( V_13 ) ;
break;
}
if ( V_10 -> V_43 == V_44 ) {
F_24 ( L_3 ) ;
V_16 = F_25 ( V_10 , V_13 , V_14 ) ;
if ( F_10 ( V_16 < 0 ) )
break;
V_10 -> V_43 = V_45 ;
V_16 = V_14 ;
} else {
F_24 ( L_4 ) ;
V_16 = F_26 ( V_10 , V_13 , V_14 ) ;
if ( F_10 ( V_16 < 0 ) )
break;
V_16 = F_27 ( V_10 ) ;
if ( F_10 ( V_16 ) ) {
V_10 -> V_43 = V_47 ;
break;
}
V_10 -> V_43 = V_48 ;
F_28 ( & V_10 -> V_40 ) ;
V_16 = F_29 ( V_10 ) ;
if ( F_10 ( V_16 < 0 ) ) {
V_10 -> V_43 = V_47 ;
return V_16 ;
}
F_30 ( V_49 , & V_10 -> V_50 ) ;
return V_14 ;
}
break;
case V_48 :
V_13 = NULL ;
F_31 ( & V_10 -> V_18 . V_21 . V_22 ) ;
switch ( F_19 ( V_10 ) ) {
case V_38 :
V_16 = - V_39 ;
goto V_51;
case V_30 :
V_16 = - V_34 ;
goto V_51;
case V_52 :
break;
}
if ( ! ( V_10 -> V_18 . V_19 . V_53 & V_54 ) ) {
F_7 ( & V_10 -> V_18 . V_21 . V_22 ) ;
V_16 = F_13 ( V_10 ) ;
break;
}
V_14 = F_32 ( V_14 , ( T_1 ) F_6 ( V_10 -> V_18 . V_19 . V_20 ) ) ;
F_7 ( & V_10 -> V_18 . V_21 . V_22 ) ;
V_13 = F_21 ( V_23 , V_14 ) ;
if ( F_22 ( V_13 ) ) {
V_16 = F_23 ( V_13 ) ;
break;
}
F_31 ( & V_10 -> V_18 . V_21 . V_22 ) ;
if ( F_19 ( V_10 ) == V_38 ) {
V_16 = - V_39 ;
V_51:
F_7 ( & V_10 -> V_18 . V_21 . V_22 ) ;
} else {
V_16 = F_5 ( V_10 , V_13 , V_14 ) ;
}
F_33 ( V_13 ) ;
break;
default:
V_16 = - V_55 ;
break;
}
F_28 ( & V_10 -> V_40 ) ;
return V_16 ;
}
static T_2 F_34 ( struct V_9 * V_10 , char T_3 * V_23 ,
T_1 V_56 )
{
struct V_57 V_58 [ V_56 ] ;
unsigned V_59 = 0 ;
memset ( V_58 , 0 , sizeof V_58 ) ;
do {
V_58 [ V_59 ] . type = V_10 -> V_18 . V_60 [ V_59 ] ;
if ( V_58 [ V_59 ] . type == V_61 ) {
V_58 [ V_59 ] . V_62 . V_19 = V_10 -> V_18 . V_19 ;
V_10 -> V_29 = V_52 ;
}
} while ( ++ V_59 < V_56 );
if ( V_56 < V_10 -> V_18 . V_63 ) {
V_10 -> V_18 . V_63 -= V_56 ;
memmove ( V_10 -> V_18 . V_60 , V_10 -> V_18 . V_60 + V_56 ,
V_10 -> V_18 . V_63 * sizeof * V_10 -> V_18 . V_60 ) ;
} else {
V_10 -> V_18 . V_63 = 0 ;
}
F_7 ( & V_10 -> V_18 . V_21 . V_22 ) ;
F_28 ( & V_10 -> V_40 ) ;
return F_10 ( F_35 ( V_23 , V_58 , sizeof V_58 ) )
? - V_64 : sizeof V_58 ;
}
static T_2 F_36 ( struct V_35 * V_35 , char T_3 * V_23 ,
T_1 V_14 , T_4 * V_36 )
{
struct V_9 * V_10 = V_35 -> V_37 ;
char * V_13 = NULL ;
T_1 V_56 ;
int V_16 ;
F_18 () ;
if ( F_19 ( V_10 ) == V_38 )
return - V_39 ;
V_16 = F_20 ( & V_10 -> V_40 , V_35 -> V_41 & V_42 ) ;
if ( F_10 ( V_16 < 0 ) )
return V_16 ;
if ( V_10 -> V_43 != V_48 ) {
V_16 = - V_55 ;
goto V_65;
}
F_31 ( & V_10 -> V_18 . V_21 . V_22 ) ;
switch ( F_19 ( V_10 ) ) {
case V_38 :
V_16 = - V_39 ;
break;
case V_30 :
V_56 = V_14 / sizeof( struct V_57 ) ;
if ( F_10 ( ! V_56 ) ) {
V_16 = - V_46 ;
break;
}
if ( ( V_35 -> V_41 & V_42 ) && ! V_10 -> V_18 . V_63 ) {
V_16 = - V_66 ;
break;
}
if ( F_37 ( V_10 -> V_18 . V_21 ,
V_10 -> V_18 . V_63 ) ) {
V_16 = - V_28 ;
break;
}
return F_34 ( V_10 , V_23 ,
F_32 ( V_56 , ( T_1 ) V_10 -> V_18 . V_63 ) ) ;
case V_52 :
if ( V_10 -> V_18 . V_19 . V_53 & V_54 ) {
F_7 ( & V_10 -> V_18 . V_21 . V_22 ) ;
V_16 = F_13 ( V_10 ) ;
goto V_65;
}
V_14 = F_32 ( V_14 , ( T_1 ) F_6 ( V_10 -> V_18 . V_19 . V_20 ) ) ;
F_7 ( & V_10 -> V_18 . V_21 . V_22 ) ;
if ( F_38 ( V_14 ) ) {
V_13 = F_39 ( V_14 , V_67 ) ;
if ( F_10 ( ! V_13 ) ) {
V_16 = - V_68 ;
goto V_65;
}
}
F_31 ( & V_10 -> V_18 . V_21 . V_22 ) ;
if ( F_19 ( V_10 ) == V_38 ) {
V_16 = - V_39 ;
break;
}
V_16 = F_5 ( V_10 , V_13 , V_14 ) ;
if ( F_38 ( V_16 > 0 ) && F_10 ( F_35 ( V_23 , V_13 , V_14 ) ) )
V_16 = - V_64 ;
goto V_65;
default:
V_16 = - V_55 ;
break;
}
F_7 ( & V_10 -> V_18 . V_21 . V_22 ) ;
V_65:
F_28 ( & V_10 -> V_40 ) ;
F_33 ( V_13 ) ;
return V_16 ;
}
static int F_40 ( struct V_69 * V_69 , struct V_35 * V_35 )
{
struct V_9 * V_10 = V_69 -> V_70 ;
F_18 () ;
if ( F_10 ( V_10 -> V_43 == V_47 ) )
return - V_71 ;
V_35 -> V_37 = V_10 ;
F_41 ( V_10 ) ;
return 0 ;
}
static int F_42 ( struct V_69 * V_69 , struct V_35 * V_35 )
{
struct V_9 * V_10 = V_35 -> V_37 ;
F_18 () ;
F_43 ( V_10 ) ;
return 0 ;
}
static long F_44 ( struct V_35 * V_35 , unsigned V_72 , unsigned long V_73 )
{
struct V_9 * V_10 = V_35 -> V_37 ;
struct V_74 * V_25 = V_10 -> V_25 ;
long V_16 ;
F_18 () ;
if ( V_72 == V_75 ) {
struct V_1 * V_76 = V_10 -> V_76 ;
V_16 = V_76 ? F_45 ( V_76 , V_73 ) : - V_77 ;
} else if ( V_25 && V_25 -> V_78 -> V_79 ) {
V_16 = V_25 -> V_78 -> V_79 ( V_25 , V_72 , V_73 ) ;
} else {
V_16 = - V_80 ;
}
return V_16 ;
}
static void F_46 ( struct V_5 * V_81 , struct V_7 * V_8 )
{
F_18 () ;
if ( F_38 ( V_8 -> V_11 ) ) {
struct V_82 * V_6 = V_81 -> V_83 ;
V_6 -> V_84 = V_8 -> V_84 ? V_8 -> V_84 : V_8 -> V_85 ;
F_47 ( V_8 -> V_11 ) ;
}
}
static T_2 F_48 ( struct V_35 * V_35 ,
char T_3 * V_23 , T_1 V_14 , int V_86 )
{
struct V_87 * V_88 = V_35 -> V_37 ;
struct V_82 * V_6 ;
char * V_13 = NULL ;
T_2 V_16 , V_89 ;
int V_90 ;
if ( F_49 ( V_88 -> V_10 -> V_43 != V_48 ) ) {
V_16 = - V_77 ;
goto error;
}
V_6 = V_88 -> V_6 ;
if ( ! V_6 ) {
if ( V_35 -> V_41 & V_42 ) {
V_16 = - V_66 ;
goto error;
}
V_16 = F_50 ( V_88 -> V_91 , ( V_6 = V_88 -> V_6 ) ) ;
if ( V_16 ) {
V_16 = - V_28 ;
goto error;
}
}
V_90 = ! V_86 == ! V_88 -> V_92 ;
if ( V_90 && V_88 -> V_93 ) {
V_16 = - V_46 ;
goto error;
}
if ( ! V_90 ) {
struct V_74 * V_25 = V_88 -> V_10 -> V_25 ;
V_89 = V_86 ? F_51 ( V_25 , V_6 -> V_6 , V_14 ) : V_14 ;
V_13 = F_39 ( V_89 , V_67 ) ;
if ( F_10 ( ! V_13 ) )
return - V_68 ;
if ( ! V_86 && F_10 ( F_52 ( V_13 , V_23 , V_14 ) ) ) {
V_16 = - V_64 ;
goto error;
}
}
V_16 = F_20 ( & V_88 -> V_40 , V_35 -> V_41 & V_42 ) ;
if ( F_10 ( V_16 ) )
goto error;
F_31 ( & V_88 -> V_10 -> V_94 ) ;
if ( V_88 -> V_6 != V_6 ) {
V_16 = - V_95 ;
F_7 ( & V_88 -> V_10 -> V_94 ) ;
} else if ( V_90 ) {
if ( F_38 ( V_88 -> V_6 == V_6 ) && ! F_49 ( ! V_6 -> V_6 ) )
F_15 ( V_6 -> V_6 ) ;
F_7 ( & V_88 -> V_10 -> V_94 ) ;
V_16 = - V_96 ;
} else {
F_53 ( V_97 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_11 = & V_97 ;
V_8 -> F_47 = F_46 ;
V_8 -> V_23 = V_13 ;
V_8 -> V_24 = V_89 ;
V_16 = F_9 ( V_6 -> V_6 , V_8 , V_27 ) ;
F_7 ( & V_88 -> V_10 -> V_94 ) ;
if ( F_10 ( V_16 < 0 ) ) {
} else if ( F_10 ( F_11 ( & V_97 ) ) ) {
V_16 = - V_28 ;
F_12 ( V_6 -> V_6 , V_8 ) ;
} else {
V_16 = V_6 -> V_84 ;
if ( V_86 && V_16 > 0 &&
F_10 ( F_54 ( V_23 , V_13 ,
F_55 ( T_1 , V_16 , V_14 ) ) ) )
V_16 = - V_64 ;
}
}
F_28 ( & V_88 -> V_40 ) ;
error:
F_33 ( V_13 ) ;
return V_16 ;
}
static T_2
F_56 ( struct V_35 * V_35 , const char T_3 * V_23 , T_1 V_14 ,
T_4 * V_36 )
{
F_18 () ;
return F_48 ( V_35 , ( char T_3 * ) V_23 , V_14 , 0 ) ;
}
static T_2
F_57 ( struct V_35 * V_35 , char T_3 * V_23 , T_1 V_14 , T_4 * V_36 )
{
F_18 () ;
return F_48 ( V_35 , V_23 , V_14 , 1 ) ;
}
static int
F_58 ( struct V_69 * V_69 , struct V_35 * V_35 )
{
struct V_87 * V_88 = V_69 -> V_70 ;
F_18 () ;
if ( F_49 ( V_88 -> V_10 -> V_43 != V_48 ) )
return - V_77 ;
V_35 -> V_37 = V_88 ;
F_41 ( V_88 -> V_10 ) ;
return 0 ;
}
static int
F_59 ( struct V_69 * V_69 , struct V_35 * V_35 )
{
struct V_87 * V_88 = V_69 -> V_70 ;
F_18 () ;
F_43 ( V_88 -> V_10 ) ;
return 0 ;
}
static long F_60 ( struct V_35 * V_35 , unsigned V_72 ,
unsigned long V_73 )
{
struct V_87 * V_88 = V_35 -> V_37 ;
int V_16 ;
F_18 () ;
if ( F_49 ( V_88 -> V_10 -> V_43 != V_48 ) )
return - V_77 ;
F_31 ( & V_88 -> V_10 -> V_94 ) ;
if ( F_38 ( V_88 -> V_6 ) ) {
switch ( V_72 ) {
case V_98 :
V_16 = F_61 ( V_88 -> V_6 -> V_6 ) ;
break;
case V_99 :
F_62 ( V_88 -> V_6 -> V_6 ) ;
V_16 = 0 ;
break;
case V_100 :
V_16 = F_63 ( V_88 -> V_6 -> V_6 ) ;
break;
case V_101 :
V_16 = V_88 -> V_6 -> V_102 ;
break;
default:
V_16 = - V_80 ;
}
} else {
V_16 = - V_77 ;
}
F_7 ( & V_88 -> V_10 -> V_94 ) ;
return V_16 ;
}
static struct V_69 * T_5
F_64 ( struct V_103 * V_104 , void * V_13 ,
const struct V_105 * V_106 ,
const struct V_107 * V_108 ,
struct V_109 * V_110 )
{
struct V_69 * V_69 ;
F_18 () ;
V_69 = F_65 ( V_104 ) ;
if ( F_38 ( V_69 ) ) {
struct V_111 V_112 = V_113 ;
V_69 -> V_114 = F_66 () ;
V_69 -> V_115 = V_110 -> V_116 ;
V_69 -> V_117 = V_110 -> V_118 ;
V_69 -> V_119 = V_110 -> V_120 ;
V_69 -> V_121 = V_112 ;
V_69 -> V_122 = V_112 ;
V_69 -> V_123 = V_112 ;
V_69 -> V_70 = V_13 ;
if ( V_106 )
V_69 -> V_124 = V_106 ;
if ( V_108 )
V_69 -> V_125 = V_108 ;
}
return V_69 ;
}
static struct V_69 * F_67 ( struct V_103 * V_104 ,
const char * V_126 , void * V_13 ,
const struct V_105 * V_106 ,
struct V_127 * * V_128 )
{
struct V_9 * V_10 = V_104 -> V_129 ;
struct V_127 * V_127 ;
struct V_69 * V_69 ;
F_18 () ;
V_127 = F_68 ( V_104 -> V_130 , V_126 ) ;
if ( F_10 ( ! V_127 ) )
return NULL ;
V_69 = F_64 ( V_104 , V_13 , V_106 , NULL , & V_10 -> V_131 ) ;
if ( F_10 ( ! V_69 ) ) {
F_69 ( V_127 ) ;
return NULL ;
}
F_70 ( V_127 , V_69 ) ;
if ( V_128 )
* V_128 = V_127 ;
return V_69 ;
}
static int F_71 ( struct V_103 * V_104 , void * V_132 , int V_133 )
{
struct V_134 * V_13 = V_132 ;
struct V_69 * V_69 ;
struct V_9 * V_10 = V_13 -> V_9 ;
F_18 () ;
V_10 -> V_104 = V_104 ;
V_13 -> V_9 = NULL ;
V_104 -> V_129 = V_10 ;
V_104 -> V_135 = V_136 ;
V_104 -> V_137 = V_138 ;
V_104 -> V_139 = V_140 ;
V_104 -> V_141 = & V_142 ;
V_104 -> V_143 = 1 ;
V_13 -> V_110 . V_116 = V_13 -> V_144 ;
V_69 = F_64 ( V_104 , NULL ,
& V_145 ,
& V_146 ,
& V_13 -> V_110 ) ;
V_104 -> V_130 = F_72 ( V_69 ) ;
if ( F_10 ( ! V_104 -> V_130 ) )
return - V_68 ;
if ( F_10 ( ! F_67 ( V_104 , L_5 , V_10 ,
& V_147 , NULL ) ) )
return - V_68 ;
return 0 ;
}
static int F_73 ( struct V_134 * V_13 , char * V_148 )
{
F_18 () ;
if ( ! V_148 || ! * V_148 )
return 0 ;
for (; ; ) {
unsigned long V_73 ;
char * V_149 , * V_150 ;
V_150 = strchr ( V_148 , ',' ) ;
if ( V_150 )
* V_150 = 0 ;
V_149 = strchr ( V_148 , '=' ) ;
if ( F_10 ( ! V_149 ) ) {
F_74 ( L_6 , V_148 ) ;
return - V_46 ;
}
* V_149 = 0 ;
if ( F_75 ( V_149 + 1 , 0 , & V_73 ) ) {
F_74 ( L_7 , V_148 , V_149 + 1 ) ;
return - V_46 ;
}
switch ( V_149 - V_148 ) {
case 5 :
if ( ! memcmp ( V_148 , L_8 , 5 ) )
V_13 -> V_144 = ( V_73 & 0555 ) | V_151 ;
else if ( ! memcmp ( V_148 , L_9 , 5 ) )
V_13 -> V_110 . V_116 = ( V_73 & 0666 ) | V_152 ;
else
goto V_153;
break;
case 4 :
if ( ! memcmp ( V_148 , L_10 , 4 ) ) {
V_13 -> V_144 = ( V_73 & 0555 ) | V_151 ;
V_13 -> V_110 . V_116 = ( V_73 & 0666 ) | V_152 ;
} else {
goto V_153;
}
break;
case 3 :
if ( ! memcmp ( V_148 , L_11 , 3 ) ) {
V_13 -> V_110 . V_118 = F_76 ( F_77 () , V_73 ) ;
if ( ! F_78 ( V_13 -> V_110 . V_118 ) ) {
F_74 ( L_12 , V_148 , V_73 ) ;
return - V_46 ;
}
} else if ( ! memcmp ( V_148 , L_13 , 3 ) ) {
V_13 -> V_110 . V_120 = F_79 ( F_77 () , V_73 ) ;
if ( ! F_80 ( V_13 -> V_110 . V_120 ) ) {
F_74 ( L_12 , V_148 , V_73 ) ;
return - V_46 ;
}
} else {
goto V_153;
}
break;
default:
V_153:
F_74 ( L_14 , V_148 ) ;
return - V_46 ;
}
if ( ! V_150 )
break;
V_148 = V_150 + 1 ;
}
return 0 ;
}
static struct V_127 *
F_81 ( struct V_154 * V_155 , int V_50 ,
const char * V_156 , void * V_148 )
{
struct V_134 V_13 = {
. V_110 = {
. V_116 = V_152 | 0600 ,
. V_118 = V_157 ,
. V_120 = V_158 ,
} ,
. V_144 = V_151 | 0500 ,
} ;
struct V_127 * V_159 ;
int V_16 ;
void * V_160 ;
struct V_9 * V_10 ;
F_18 () ;
V_16 = F_73 ( & V_13 , V_148 ) ;
if ( F_10 ( V_16 < 0 ) )
return F_82 ( V_16 ) ;
V_10 = F_83 () ;
if ( F_10 ( ! V_10 ) )
return F_82 ( - V_68 ) ;
V_10 -> V_131 = V_13 . V_110 ;
V_10 -> V_156 = F_84 ( V_156 , V_67 ) ;
if ( F_10 ( ! V_10 -> V_156 ) ) {
F_85 ( V_10 ) ;
return F_82 ( - V_68 ) ;
}
V_160 = F_86 ( V_156 ) ;
if ( F_22 ( V_160 ) ) {
F_85 ( V_10 ) ;
return F_87 ( V_160 ) ;
}
V_10 -> V_37 = V_160 ;
V_13 . V_9 = V_10 ;
V_159 = F_88 ( V_155 , V_50 , & V_13 , F_71 ) ;
if ( F_22 ( V_159 ) && V_13 . V_9 ) {
F_89 ( V_13 . V_9 ) ;
F_85 ( V_13 . V_9 ) ;
}
return V_159 ;
}
static void
F_90 ( struct V_103 * V_104 )
{
F_18 () ;
F_91 ( V_104 ) ;
if ( V_104 -> V_129 ) {
F_89 ( V_104 -> V_129 ) ;
F_85 ( V_104 -> V_129 ) ;
}
}
static int F_92 ( void )
{
int V_16 ;
F_18 () ;
V_16 = F_93 ( & V_161 ) ;
if ( F_38 ( ! V_16 ) )
F_24 ( L_15 ) ;
else
F_74 ( L_16 , V_16 ) ;
return V_16 ;
}
static void F_94 ( void )
{
F_18 () ;
F_24 ( L_17 ) ;
F_95 ( & V_161 ) ;
}
static void F_96 ( struct V_9 * V_10 )
{
F_18 () ;
F_97 ( & V_10 -> V_162 ) ;
}
static void F_41 ( struct V_9 * V_10 )
{
F_18 () ;
F_97 ( & V_10 -> V_162 ) ;
F_97 ( & V_10 -> V_163 ) ;
}
static void F_85 ( struct V_9 * V_10 )
{
F_18 () ;
if ( F_10 ( F_98 ( & V_10 -> V_162 ) ) ) {
F_24 ( L_18 , V_164 ) ;
F_99 ( V_10 ) ;
F_100 ( F_101 ( & V_10 -> V_18 . V_21 ) ||
F_101 ( & V_10 -> V_12 . V_91 ) ) ;
F_33 ( V_10 -> V_156 ) ;
F_33 ( V_10 ) ;
}
}
static void F_43 ( struct V_9 * V_10 )
{
F_18 () ;
if ( F_98 ( & V_10 -> V_163 ) ) {
V_10 -> V_43 = V_47 ;
F_102 ( V_10 ) ;
}
F_85 ( V_10 ) ;
}
static struct V_9 * F_83 ( void )
{
struct V_9 * V_10 = F_103 ( sizeof *V_10 , V_67 ) ;
if ( F_10 ( ! V_10 ) )
return NULL ;
F_18 () ;
F_104 ( & V_10 -> V_162 , 1 ) ;
F_104 ( & V_10 -> V_163 , 0 ) ;
V_10 -> V_43 = V_44 ;
F_105 ( & V_10 -> V_40 ) ;
F_106 ( & V_10 -> V_94 ) ;
F_107 ( & V_10 -> V_18 . V_21 ) ;
F_108 ( & V_10 -> V_12 ) ;
V_10 -> V_18 . V_32 = 1 ;
return V_10 ;
}
static void F_99 ( struct V_9 * V_10 )
{
F_18 () ;
if ( F_109 ( V_49 , & V_10 -> V_50 ) )
F_110 ( V_10 ) ;
F_100 ( V_10 -> V_25 ) ;
if ( V_10 -> V_165 )
F_111 ( V_10 -> V_165 , V_10 -> V_166 ) ;
F_33 ( V_10 -> V_167 ) ;
F_33 ( V_10 -> V_168 ) ;
F_33 ( V_10 -> V_169 ) ;
}
static void F_102 ( struct V_9 * V_10 )
{
F_18 () ;
F_99 ( V_10 ) ;
V_10 -> V_165 = NULL ;
V_10 -> V_167 = NULL ;
V_10 -> V_168 = NULL ;
V_10 -> V_169 = NULL ;
V_10 -> V_170 = 0 ;
V_10 -> V_171 = 0 ;
V_10 -> V_172 = 0 ;
V_10 -> V_173 = 0 ;
V_10 -> V_174 = 0 ;
V_10 -> V_175 = 0 ;
V_10 -> V_166 = 0 ;
V_10 -> V_18 . V_63 = 0 ;
V_10 -> V_43 = V_44 ;
V_10 -> V_29 = V_30 ;
V_10 -> V_50 = 0 ;
}
static int F_112 ( struct V_9 * V_10 , struct V_176 * V_177 )
{
struct V_178 * * V_179 ;
int V_180 ;
F_18 () ;
if ( F_49 ( V_10 -> V_43 != V_48
|| F_113 ( V_181 , & V_10 -> V_50 ) ) )
return - V_55 ;
V_180 = F_114 ( V_177 , V_10 -> V_174 ) ;
if ( F_10 ( V_180 < 0 ) )
return V_180 ;
V_10 -> V_15 = F_115 ( V_177 -> V_25 -> V_26 , V_67 ) ;
if ( F_10 ( ! V_10 -> V_15 ) )
return - V_68 ;
V_10 -> V_15 -> F_47 = F_3 ;
V_10 -> V_15 -> V_11 = V_10 ;
V_179 = V_10 -> V_169 ;
for ( V_179 = V_10 -> V_169 ; * V_179 ; ++ V_179 ) {
struct V_182 * V_183 = ( * V_179 ) -> V_184 ;
int V_185 = V_180 ;
for (; V_183 -> V_186 ; ++ V_185 , ++ V_183 )
V_183 -> V_185 = V_185 ;
}
V_10 -> V_25 = V_177 -> V_25 ;
F_96 ( V_10 ) ;
return 0 ;
}
static void F_116 ( struct V_9 * V_10 )
{
F_18 () ;
if ( ! F_49 ( ! V_10 -> V_25 ) ) {
F_117 ( V_10 -> V_25 -> V_26 , V_10 -> V_15 ) ;
V_10 -> V_15 = NULL ;
V_10 -> V_25 = NULL ;
F_118 ( V_181 , & V_10 -> V_50 ) ;
F_85 ( V_10 ) ;
}
}
static int F_27 ( struct V_9 * V_10 )
{
struct V_87 * V_88 , * V_165 ;
unsigned V_59 , V_63 ;
F_18 () ;
V_63 = V_10 -> V_166 ;
V_165 = F_119 ( V_63 , sizeof( * V_165 ) , V_67 ) ;
if ( ! V_165 )
return - V_68 ;
V_88 = V_165 ;
for ( V_59 = 1 ; V_59 <= V_63 ; ++ V_59 , ++ V_88 ) {
V_88 -> V_10 = V_10 ;
F_105 ( & V_88 -> V_40 ) ;
F_107 ( & V_88 -> V_91 ) ;
sprintf ( V_165 -> V_126 , L_19 , V_59 ) ;
if ( ! F_10 ( F_67 ( V_10 -> V_104 , V_165 -> V_126 , V_88 ,
& V_187 ,
& V_88 -> V_127 ) ) ) {
F_111 ( V_165 , V_59 - 1 ) ;
return - V_68 ;
}
}
V_10 -> V_165 = V_165 ;
return 0 ;
}
static void F_111 ( struct V_87 * V_165 , unsigned V_63 )
{
struct V_87 * V_88 = V_165 ;
F_18 () ;
for (; V_63 ; -- V_63 , ++ V_88 ) {
F_100 ( F_120 ( & V_88 -> V_40 ) ||
F_101 ( & V_88 -> V_91 ) ) ;
if ( V_88 -> V_127 ) {
F_121 ( V_88 -> V_127 ) ;
F_69 ( V_88 -> V_127 ) ;
V_88 -> V_127 = NULL ;
}
}
F_33 ( V_165 ) ;
}
static void F_122 ( struct V_1 * V_76 )
{
struct V_82 * V_6 = V_76 -> V_188 ;
struct V_87 * V_88 = V_76 -> V_10 -> V_165 ;
unsigned V_63 = V_76 -> V_10 -> V_166 ;
unsigned long V_50 ;
F_123 ( & V_76 -> V_10 -> V_94 , V_50 ) ;
do {
if ( F_38 ( V_6 -> V_6 ) )
F_124 ( V_6 -> V_6 ) ;
V_88 -> V_6 = NULL ;
++ V_6 ;
++ V_88 ;
} while ( -- V_63 );
F_125 ( & V_76 -> V_10 -> V_94 , V_50 ) ;
}
static int F_126 ( struct V_1 * V_76 )
{
struct V_9 * V_10 = V_76 -> V_10 ;
struct V_82 * V_6 = V_76 -> V_188 ;
struct V_87 * V_88 = V_10 -> V_165 ;
unsigned V_63 = V_10 -> V_166 ;
unsigned long V_50 ;
int V_16 = 0 ;
F_123 ( & V_76 -> V_10 -> V_94 , V_50 ) ;
do {
struct V_189 * V_190 ;
V_190 = V_6 -> V_191 [ V_6 -> V_191 [ 1 ] ? 1 : 0 ] ;
V_6 -> V_6 -> V_83 = V_6 ;
V_6 -> V_6 -> V_192 = V_190 ;
V_16 = F_127 ( V_6 -> V_6 ) ;
if ( F_38 ( ! V_16 ) ) {
V_88 -> V_6 = V_6 ;
V_88 -> V_92 = F_128 ( V_190 ) ;
V_88 -> V_93 = F_129 ( V_190 ) ;
} else {
break;
}
F_130 ( & V_88 -> V_91 ) ;
++ V_6 ;
++ V_88 ;
} while ( -- V_63 );
F_125 ( & V_76 -> V_10 -> V_94 , V_50 ) ;
return V_16 ;
}
static int T_5 F_131 ( char * V_13 , unsigned V_14 ,
T_6 V_193 , void * V_194 )
{
struct V_195 * V_196 = ( void * ) V_13 ;
T_7 V_24 ;
int V_16 ;
F_18 () ;
if ( V_14 < 2 ) {
F_14 ( L_20 ) ;
return - V_46 ;
}
V_24 = V_196 -> V_197 ;
if ( V_14 < V_24 ) {
F_14 ( L_21 ) ;
return - V_46 ;
}
#define F_132 ( T_8 ) 1
#define F_133 ( T_8 ) (val)
#define F_134 ( T_8 ) ((val) & USB_ENDPOINT_NUMBER_MASK)
#define F_135 ( type , T_8 ) do { \
pr_vdebug("entity " #type "(%02x)\n", (val)); \
if (unlikely(!__entity_check_ ##type(val))) { \
pr_vdebug("invalid entity's value\n"); \
return -EINVAL; \
} \
ret = entity(FFS_ ##type, &val, _ds, priv); \
if (unlikely(ret < 0)) { \
pr_debug("entity " #type "(%02x); ret = %d\n", \
(val), ret); \
return ret; \
} \
} while (0)
switch ( V_196 -> V_198 ) {
case V_199 :
case V_200 :
case V_201 :
case V_202 :
F_14 ( L_22 ,
V_196 -> V_198 ) ;
return - V_46 ;
case V_203 : {
struct V_204 * V_190 = ( void * ) V_196 ;
F_14 ( L_23 ) ;
if ( V_24 != sizeof *V_190 )
goto V_205;
F_135 ( V_206 , V_190 -> V_207 ) ;
if ( V_190 -> V_208 )
F_135 ( STRING , V_190 -> V_208 ) ;
}
break;
case V_209 : {
struct V_189 * V_190 = ( void * ) V_196 ;
F_14 ( L_24 ) ;
if ( V_24 != V_210 &&
V_24 != V_211 )
goto V_205;
F_135 ( V_212 , V_190 -> V_213 ) ;
}
break;
case V_214 :
F_14 ( L_25 ) ;
if ( V_24 != sizeof( struct V_215 ) )
goto V_205;
break;
case V_216 :
if ( V_24 != sizeof( struct V_217 ) )
goto V_205;
break;
case V_218 : {
struct V_219 * V_190 = ( void * ) V_196 ;
F_14 ( L_26 ) ;
if ( V_24 != sizeof *V_190 )
goto V_205;
if ( V_190 -> V_220 )
F_135 ( STRING , V_190 -> V_220 ) ;
}
break;
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
F_14 ( L_27 , V_196 -> V_198 ) ;
return - V_46 ;
default:
F_14 ( L_28 , V_196 -> V_198 ) ;
return - V_46 ;
V_205:
F_14 ( L_29 ,
V_196 -> V_197 , V_196 -> V_198 ) ;
return - V_46 ;
}
#undef F_135
#undef V_226
#undef F_132
#undef F_133
#undef F_134
return V_24 ;
}
static int T_5 F_136 ( unsigned V_63 , char * V_13 , unsigned V_14 ,
T_6 V_193 , void * V_194 )
{
const unsigned V_227 = V_14 ;
unsigned long V_102 = 0 ;
F_18 () ;
for (; ; ) {
int V_16 ;
if ( V_102 == V_63 )
V_13 = NULL ;
V_16 = V_193 ( V_228 , ( T_7 * ) V_102 , ( void * ) V_13 , V_194 ) ;
if ( F_10 ( V_16 < 0 ) ) {
F_16 ( L_30 ,
V_102 , V_16 ) ;
return V_16 ;
}
if ( ! V_13 )
return V_227 - V_14 ;
V_16 = F_131 ( V_13 , V_14 , V_193 , V_194 ) ;
if ( F_10 ( V_16 < 0 ) ) {
F_16 ( L_31 , V_164 , V_16 ) ;
return V_16 ;
}
V_14 -= V_16 ;
V_13 += V_16 ;
++ V_102 ;
}
}
static int F_137 ( enum V_229 type ,
T_7 * V_230 , struct V_195 * V_192 ,
void * V_194 )
{
struct V_9 * V_10 = V_194 ;
F_18 () ;
switch ( type ) {
case V_228 :
break;
case V_231 :
if ( * V_230 >= V_10 -> V_175 )
V_10 -> V_175 = * V_230 + 1 ;
break;
case V_232 :
if ( * V_230 > V_10 -> V_174 )
V_10 -> V_174 = * V_230 ;
break;
case V_233 :
if ( ( * V_230 & V_234 ) > V_10 -> V_166 )
V_10 -> V_166 = ( * V_230 & V_234 ) ;
break;
}
return 0 ;
}
static int F_25 ( struct V_9 * V_10 ,
char * const V_132 , T_1 V_14 )
{
unsigned V_235 , V_236 ;
int V_237 , V_16 = - V_46 ;
char * V_13 = V_132 ;
F_18 () ;
if ( F_10 ( F_138 ( V_13 ) != V_238 ||
F_138 ( V_13 + 4 ) != V_14 ) )
goto error;
V_235 = F_138 ( V_13 + 8 ) ;
V_236 = F_138 ( V_13 + 12 ) ;
if ( ! V_235 && ! V_236 )
goto V_239;
V_13 += 16 ;
V_14 -= 16 ;
if ( F_38 ( V_235 ) ) {
V_237 = F_136 ( V_235 , V_13 , V_14 ,
F_137 , V_10 ) ;
if ( F_10 ( V_237 < 0 ) ) {
V_16 = V_237 ;
goto error;
}
V_13 += V_237 ;
V_14 -= V_237 ;
} else {
V_237 = 0 ;
}
if ( F_38 ( V_236 ) ) {
V_16 = F_136 ( V_236 , V_13 , V_14 ,
F_137 , V_10 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
} else {
V_16 = 0 ;
}
if ( F_10 ( V_14 != V_16 ) )
goto V_239;
V_10 -> V_171 = V_237 ;
V_10 -> V_170 = V_237 + V_16 ;
V_10 -> V_167 = V_132 ;
V_10 -> V_172 = V_235 ;
V_10 -> V_173 = V_236 ;
return 0 ;
V_239:
V_16 = - V_46 ;
error:
F_33 ( V_132 ) ;
return V_16 ;
}
static int F_26 ( struct V_9 * V_10 ,
char * const V_132 , T_1 V_14 )
{
T_9 V_240 , V_241 , V_242 ;
struct V_178 * * V_169 , * V_155 ;
struct V_182 * V_184 , * V_186 ;
const char * V_13 = V_132 ;
F_18 () ;
if ( F_10 ( F_138 ( V_13 ) != V_243 ||
F_138 ( V_13 + 4 ) != V_14 ) )
goto error;
V_240 = F_138 ( V_13 + 8 ) ;
V_242 = F_138 ( V_13 + 12 ) ;
if ( F_10 ( ! V_240 != ! V_242 ) )
goto error;
V_241 = V_10 -> V_174 ;
if ( F_10 ( V_240 < V_241 ) )
goto error;
if ( ! V_241 ) {
F_33 ( V_132 ) ;
return 0 ;
}
{
unsigned V_59 = 0 ;
F_139 ( V_244 ) ;
F_140 ( V_244 , struct V_178 * , V_169 ,
V_242 + 1 ) ;
F_140 ( V_244 , struct V_178 , V_245 , V_242 ) ;
F_140 ( V_244 , struct V_182 , V_184 ,
V_242 * ( V_241 + 1 ) ) ;
char * V_246 = F_39 ( F_141 ( V_244 ) , V_67 ) ;
if ( F_10 ( ! V_246 ) ) {
F_33 ( V_132 ) ;
return - V_68 ;
}
V_169 = F_142 ( V_246 , V_244 , V_169 ) ;
V_155 = F_142 ( V_246 , V_244 , V_245 ) ;
V_59 = V_242 ;
do {
* V_169 ++ = V_155 ++ ;
} while ( -- V_59 );
* V_169 = NULL ;
V_169 = F_142 ( V_246 , V_244 , V_169 ) ;
V_155 = F_142 ( V_246 , V_244 , V_245 ) ;
V_186 = F_142 ( V_246 , V_244 , V_184 ) ;
V_184 = V_186 ;
}
V_13 += 16 ;
V_14 -= 16 ;
do {
unsigned V_247 = V_241 ;
if ( F_10 ( V_14 < 3 ) )
goto V_248;
V_155 -> V_249 = F_143 ( V_13 ) ;
V_155 -> V_184 = V_186 ;
++ V_155 ;
V_13 += 2 ;
V_14 -= 2 ;
do {
T_1 V_24 = F_144 ( V_13 , V_14 ) ;
if ( F_10 ( V_24 == V_14 ) )
goto V_248;
if ( F_38 ( V_247 ) ) {
V_186 -> V_186 = V_13 ;
-- V_247 ;
++ V_186 ;
}
V_13 += V_24 + 1 ;
V_14 -= V_24 + 1 ;
} while ( -- V_240 );
V_186 -> V_185 = 0 ;
V_186 -> V_186 = NULL ;
++ V_186 ;
} while ( -- V_242 );
if ( F_10 ( V_14 ) )
goto V_248;
V_10 -> V_169 = V_169 ;
V_10 -> V_168 = V_132 ;
return 0 ;
V_248:
F_33 ( V_169 ) ;
error:
F_33 ( V_132 ) ;
return - V_46 ;
}
static void F_145 ( struct V_9 * V_10 ,
enum V_250 type )
{
enum V_250 V_251 , V_252 = type ;
int V_253 = 0 ;
if ( V_10 -> V_29 == V_52 )
V_10 -> V_29 = V_38 ;
switch ( type ) {
case V_254 :
V_252 = V_255 ;
case V_255 :
case V_61 :
V_251 = type ;
break;
case V_256 :
case V_257 :
case V_258 :
case V_259 :
V_251 = V_255 ;
V_252 = V_254 ;
V_253 = 1 ;
break;
default:
F_146 () ;
}
{
T_7 * V_18 = V_10 -> V_18 . V_60 , * V_260 = V_18 ;
unsigned V_56 = V_10 -> V_18 . V_63 ;
for (; V_56 ; -- V_56 , ++ V_18 )
if ( ( * V_18 == V_251 || * V_18 == V_252 ) == V_253 )
* V_260 ++ = * V_18 ;
else
F_14 ( L_32 , * V_18 ) ;
V_10 -> V_18 . V_63 = V_260 - V_10 -> V_18 . V_60 ;
}
F_14 ( L_33 , type ) ;
V_10 -> V_18 . V_60 [ V_10 -> V_18 . V_63 ++ ] = type ;
F_147 ( & V_10 -> V_18 . V_21 ) ;
}
static void F_148 ( struct V_9 * V_10 ,
enum V_250 type )
{
unsigned long V_50 ;
F_123 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
F_145 ( V_10 , type ) ;
F_125 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
}
static int F_149 ( enum V_229 type , T_7 * V_230 ,
struct V_195 * V_192 ,
void * V_194 )
{
struct V_189 * V_190 = ( void * ) V_192 ;
struct V_1 * V_76 = V_194 ;
struct V_82 * V_82 ;
const int V_261 = V_76 -> V_4 . V_262 != NULL ;
unsigned V_263 ;
if ( type != V_228 )
return 0 ;
if ( V_261 )
V_76 -> V_4 . V_262 [ ( long ) V_230 ] = V_192 ;
else
V_76 -> V_4 . V_264 [ ( long ) V_230 ] = V_192 ;
if ( ! V_192 || V_192 -> V_198 != V_209 )
return 0 ;
V_263 = ( V_190 -> V_213 & V_234 ) - 1 ;
V_82 = V_76 -> V_188 + V_263 ;
if ( F_10 ( V_82 -> V_191 [ V_261 ] ) ) {
F_14 ( L_34 ,
V_261 ? L_35 : L_36 ,
V_190 -> V_213 & V_234 ) ;
return - V_46 ;
}
V_82 -> V_191 [ V_261 ] = V_190 ;
F_150 ( L_37 , V_190 , V_190 -> V_197 ) ;
if ( V_82 -> V_6 ) {
V_190 -> V_213 = V_82 -> V_191 [ 0 ] -> V_213 ;
if ( ! V_190 -> V_265 )
V_190 -> V_265 = V_82 -> V_191 [ 0 ] -> V_265 ;
} else {
struct V_7 * V_8 ;
struct V_5 * V_6 ;
F_14 ( L_38 ) ;
V_6 = F_151 ( V_76 -> V_25 , V_190 ) ;
if ( F_10 ( ! V_6 ) )
return - V_266 ;
V_6 -> V_83 = V_76 -> V_188 + V_263 ;
V_8 = F_115 ( V_6 , V_67 ) ;
if ( F_10 ( ! V_8 ) )
return - V_68 ;
V_82 -> V_6 = V_6 ;
V_82 -> V_8 = V_8 ;
V_76 -> V_267 [ V_190 -> V_213 &
V_234 ] = V_263 + 1 ;
}
F_150 ( L_39 , V_190 , V_190 -> V_197 ) ;
return 0 ;
}
static int F_152 ( enum V_229 type , T_7 * V_230 ,
struct V_195 * V_192 ,
void * V_194 )
{
struct V_1 * V_76 = V_194 ;
unsigned V_263 ;
T_7 V_268 ;
switch ( type ) {
default:
case V_228 :
return 0 ;
case V_231 :
V_263 = * V_230 ;
if ( V_76 -> V_269 [ V_263 ] < 0 ) {
int V_185 = F_153 ( V_76 -> V_270 , & V_76 -> V_4 ) ;
if ( F_10 ( V_185 < 0 ) )
return V_185 ;
V_76 -> V_269 [ V_263 ] = V_185 ;
}
V_268 = V_76 -> V_269 [ V_263 ] ;
break;
case V_232 :
V_268 = V_76 -> V_10 -> V_169 [ 0 ] -> V_184 [ * V_230 - 1 ] . V_185 ;
break;
case V_233 :
if ( V_192 -> V_198 == V_209 )
return 0 ;
V_263 = ( * V_230 & V_234 ) - 1 ;
if ( F_10 ( ! V_76 -> V_188 [ V_263 ] . V_6 ) )
return - V_46 ;
{
struct V_189 * * V_191 ;
V_191 = V_76 -> V_188 [ V_263 ] . V_191 ;
V_268 = V_191 [ V_191 [ 0 ] ? 0 : 1 ] -> V_213 ;
}
break;
}
F_14 ( L_40 , * V_230 , V_268 ) ;
* V_230 = V_268 ;
return 0 ;
}
static inline struct V_271 * F_154 ( struct V_2 * V_3 ,
struct V_272 * V_273 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_271 * V_274 =
F_2 ( V_3 -> V_275 , struct V_271 , V_276 ) ;
int V_16 ;
F_18 () ;
if ( ! V_274 -> V_277 )
F_155 () ;
V_16 = V_274 -> V_278 -> V_279 ? 0 : - V_77 ;
V_76 -> V_10 = V_274 -> V_278 -> V_9 ;
if ( ! V_274 -> V_277 )
F_156 () ;
if ( V_16 )
return F_82 ( V_16 ) ;
V_76 -> V_270 = V_273 ;
V_76 -> V_25 = V_273 -> V_177 -> V_25 ;
F_96 ( V_76 -> V_10 ) ;
if ( ! V_274 -> V_280 ) {
V_16 = F_112 ( V_76 -> V_10 , V_273 -> V_177 ) ;
if ( V_16 )
return F_82 ( V_16 ) ;
}
V_274 -> V_280 ++ ;
V_76 -> V_4 . V_184 = V_76 -> V_10 -> V_169 ;
return V_274 ;
}
static int F_157 ( struct V_272 * V_273 ,
struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
const int V_281 = ! ! V_76 -> V_10 -> V_172 ;
const int V_282 = F_158 ( V_76 -> V_25 ) &&
V_76 -> V_10 -> V_173 ;
int V_16 ;
F_139 ( V_244 ) ;
F_159 ( V_244 , struct V_82 , V_188 , V_10 -> V_166 ) ;
F_159 ( V_244 , struct V_195 * , V_283 ,
V_281 ? V_10 -> V_172 + 1 : 0 ) ;
F_159 ( V_244 , struct V_195 * , V_284 ,
V_282 ? V_10 -> V_173 + 1 : 0 ) ;
F_159 ( V_244 , short , V_285 , V_10 -> V_175 ) ;
F_159 ( V_244 , char , V_167 ,
V_282 ? V_10 -> V_170 : V_10 -> V_171 ) ;
char * V_246 ;
F_18 () ;
if ( F_10 ( ! ( V_281 | V_282 ) ) )
return - V_266 ;
V_246 = F_39 ( F_141 ( V_244 ) , V_67 ) ;
if ( F_10 ( ! V_246 ) )
return - V_68 ;
memset ( F_142 ( V_246 , V_244 , V_188 ) , 0 , V_286 ) ;
memcpy ( F_142 ( V_246 , V_244 , V_167 ) , V_10 -> V_167 + 16 ,
V_287 ) ;
memset ( F_142 ( V_246 , V_244 , V_285 ) , 0xff , V_288 ) ;
for ( V_16 = V_10 -> V_166 ; V_16 ; -- V_16 ) {
struct V_82 * V_36 ;
V_36 = F_142 ( V_246 , V_244 , V_188 ) ;
V_36 [ V_16 ] . V_102 = - 1 ;
}
V_76 -> V_188 = F_142 ( V_246 , V_244 , V_188 ) ;
V_76 -> V_269 = F_142 ( V_246 , V_244 , V_285 ) ;
if ( F_38 ( V_281 ) ) {
V_76 -> V_4 . V_264 = F_142 ( V_246 , V_244 , V_283 ) ;
V_16 = F_136 ( V_10 -> V_172 ,
F_142 ( V_246 , V_244 , V_167 ) ,
V_287 ,
F_149 , V_76 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
} else {
V_16 = 0 ;
}
if ( F_38 ( V_282 ) ) {
V_76 -> V_4 . V_262 = F_142 ( V_246 , V_244 , V_284 ) ;
V_16 = F_136 ( V_10 -> V_173 ,
F_142 ( V_246 , V_244 , V_167 ) + V_16 ,
V_287 - V_16 ,
F_149 , V_76 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
}
V_16 = F_136 ( V_10 -> V_172 +
( V_282 ? V_10 -> V_173 : 0 ) ,
F_142 ( V_246 , V_244 , V_167 ) , V_287 ,
F_152 , V_76 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
F_148 ( V_10 , V_256 ) ;
return 0 ;
error:
return V_16 ;
}
static int F_160 ( struct V_272 * V_273 ,
struct V_2 * V_3 )
{
struct V_271 * V_274 = F_154 ( V_3 , V_273 ) ;
if ( F_22 ( V_274 ) )
return F_23 ( V_274 ) ;
return F_157 ( V_273 , V_3 ) ;
}
static int F_161 ( struct V_2 * V_3 ,
unsigned V_289 , unsigned V_290 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
int V_16 = 0 , V_291 ;
if ( V_290 != ( unsigned ) - 1 ) {
V_291 = F_45 ( V_76 , V_289 ) ;
if ( F_10 ( V_291 < 0 ) )
return V_291 ;
}
if ( V_10 -> V_76 )
F_122 ( V_10 -> V_76 ) ;
if ( V_10 -> V_43 != V_48 )
return - V_77 ;
if ( V_290 == ( unsigned ) - 1 ) {
V_10 -> V_76 = NULL ;
F_148 ( V_10 , V_258 ) ;
return 0 ;
}
V_10 -> V_76 = V_76 ;
V_16 = F_126 ( V_76 ) ;
if ( F_38 ( V_16 >= 0 ) )
F_148 ( V_10 , V_259 ) ;
return V_16 ;
}
static void F_162 ( struct V_2 * V_3 )
{
F_161 ( V_3 , 0 , ( unsigned ) - 1 ) ;
}
static int F_163 ( struct V_2 * V_3 ,
const struct V_292 * V_293 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
unsigned long V_50 ;
int V_16 ;
F_18 () ;
F_14 ( L_41 , V_293 -> V_53 ) ;
F_14 ( L_42 , V_293 -> V_294 ) ;
F_14 ( L_43 , F_6 ( V_293 -> V_295 ) ) ;
F_14 ( L_44 , F_6 ( V_293 -> V_296 ) ) ;
F_14 ( L_45 , F_6 ( V_293 -> V_20 ) ) ;
if ( V_10 -> V_43 != V_48 )
return - V_77 ;
switch ( V_293 -> V_53 & V_297 ) {
case V_298 :
V_16 = F_45 ( V_76 , F_6 ( V_293 -> V_296 ) ) ;
if ( F_10 ( V_16 < 0 ) )
return V_16 ;
break;
case V_299 :
V_16 = F_164 ( V_76 , F_6 ( V_293 -> V_296 ) ) ;
if ( F_10 ( V_16 < 0 ) )
return V_16 ;
break;
default:
return - V_300 ;
}
F_123 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
V_10 -> V_18 . V_19 = * V_293 ;
V_10 -> V_18 . V_19 . V_296 = F_165 ( V_16 ) ;
F_145 ( V_10 , V_61 ) ;
F_125 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
return 0 ;
}
static void F_166 ( struct V_2 * V_3 )
{
F_18 () ;
F_148 ( F_1 ( V_3 ) -> V_10 , V_255 ) ;
}
static void F_167 ( struct V_2 * V_3 )
{
F_18 () ;
F_148 ( F_1 ( V_3 ) -> V_10 , V_254 ) ;
}
static int F_164 ( struct V_1 * V_76 , T_7 V_102 )
{
V_102 = V_76 -> V_267 [ V_102 & V_234 ] ;
return V_102 ? V_102 : - V_301 ;
}
static int F_45 ( struct V_1 * V_76 , T_7 V_291 )
{
short * V_302 = V_76 -> V_269 ;
unsigned V_63 = V_76 -> V_10 -> V_175 ;
for (; V_63 ; -- V_63 , ++ V_302 ) {
if ( * V_302 >= 0 && * V_302 == V_291 )
return V_302 - V_76 -> V_269 ;
}
return - V_301 ;
}
static struct V_160 * F_168 ( const char * V_126 )
{
struct V_160 * V_278 ;
F_169 (dev, &ffs_devices, entry) {
if ( ! V_278 -> V_126 || ! V_126 )
continue;
if ( strcmp ( V_278 -> V_126 , V_126 ) == 0 )
return V_278 ;
}
return NULL ;
}
static struct V_160 * F_170 ( void )
{
struct V_160 * V_278 ;
if ( F_171 ( & V_303 ) ) {
V_278 = F_172 ( & V_303 , struct V_160 , V_304 ) ;
if ( V_278 -> V_305 )
return V_278 ;
}
return NULL ;
}
static struct V_160 * F_173 ( const char * V_126 )
{
struct V_160 * V_278 ;
V_278 = F_170 () ;
if ( V_278 )
return V_278 ;
return F_168 ( V_126 ) ;
}
static inline struct V_271 * F_174 ( struct V_306 * V_307 )
{
return F_2 ( F_175 ( V_307 ) , struct V_271 ,
V_276 . V_308 ) ;
}
static void F_176 ( struct V_306 * V_307 )
{
struct V_271 * V_148 = F_174 ( V_307 ) ;
F_177 ( & V_148 -> V_276 ) ;
}
static void F_178 ( struct V_309 * V_3 )
{
struct V_271 * V_148 ;
V_148 = F_179 ( V_3 ) ;
F_155 () ;
F_180 ( V_148 -> V_278 ) ;
F_156 () ;
F_33 ( V_148 ) ;
}
static int F_181 ( struct V_309 * V_275 , const char * V_126 )
{
struct V_271 * V_148 ;
char * V_36 ;
const char * V_310 ;
int V_311 , V_16 ;
V_311 = strlen ( V_126 ) + 1 ;
if ( V_311 > V_312 )
return - V_313 ;
V_36 = F_182 ( V_126 , V_311 , V_67 ) ;
if ( ! V_36 )
return - V_68 ;
V_148 = F_179 ( V_275 ) ;
V_310 = NULL ;
F_155 () ;
V_310 = V_148 -> V_278 -> V_314 ? V_148 -> V_278 -> V_126 : NULL ;
V_16 = F_183 ( V_148 -> V_278 , V_36 ) ;
if ( V_16 ) {
F_33 ( V_36 ) ;
F_156 () ;
return V_16 ;
}
V_148 -> V_278 -> V_314 = true ;
F_156 () ;
F_33 ( V_310 ) ;
return 0 ;
}
static struct V_309 * F_184 ( void )
{
struct V_271 * V_148 ;
struct V_160 * V_278 ;
V_148 = F_103 ( sizeof( * V_148 ) , V_67 ) ;
if ( ! V_148 )
return F_82 ( - V_68 ) ;
V_148 -> V_276 . V_315 = F_181 ;
V_148 -> V_276 . V_316 = F_178 ;
F_155 () ;
V_278 = F_185 () ;
F_156 () ;
if ( F_22 ( V_278 ) ) {
F_33 ( V_148 ) ;
return F_87 ( V_278 ) ;
}
V_148 -> V_278 = V_278 ;
V_278 -> V_148 = V_148 ;
F_186 ( & V_148 -> V_276 . V_308 , L_46 ,
& V_317 ) ;
return & V_148 -> V_276 ;
}
static void F_187 ( struct V_2 * V_3 )
{
F_33 ( F_1 ( V_3 ) ) ;
}
static void F_188 ( struct V_272 * V_273 ,
struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
struct V_271 * V_148 =
F_2 ( V_3 -> V_275 , struct V_271 , V_276 ) ;
struct V_82 * V_6 = V_76 -> V_188 ;
unsigned V_63 = V_10 -> V_166 ;
unsigned long V_50 ;
F_18 () ;
if ( V_10 -> V_76 == V_76 ) {
F_122 ( V_76 ) ;
V_10 -> V_76 = NULL ;
}
if ( ! -- V_148 -> V_280 )
F_116 ( V_10 ) ;
F_123 ( & V_76 -> V_10 -> V_94 , V_50 ) ;
do {
if ( V_6 -> V_6 && V_6 -> V_8 )
F_117 ( V_6 -> V_6 , V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
++ V_6 ;
} while ( -- V_63 );
F_125 ( & V_76 -> V_10 -> V_94 , V_50 ) ;
F_33 ( V_76 -> V_188 ) ;
V_76 -> V_188 = NULL ;
V_76 -> V_4 . V_264 = NULL ;
V_76 -> V_4 . V_262 = NULL ;
V_76 -> V_269 = NULL ;
F_148 ( V_10 , V_257 ) ;
}
static struct V_2 * F_189 ( struct V_309 * V_275 )
{
struct V_1 * V_76 ;
F_18 () ;
V_76 = F_103 ( sizeof( * V_76 ) , V_67 ) ;
if ( F_10 ( ! V_76 ) )
return F_82 ( - V_68 ) ;
V_76 -> V_4 . V_126 = L_47 ;
V_76 -> V_4 . V_318 = F_160 ;
V_76 -> V_4 . V_319 = F_188 ;
V_76 -> V_4 . V_320 = F_161 ;
V_76 -> V_4 . V_321 = F_162 ;
V_76 -> V_4 . V_19 = F_163 ;
V_76 -> V_4 . V_322 = F_166 ;
V_76 -> V_4 . V_323 = F_167 ;
V_76 -> V_4 . V_324 = F_187 ;
return & V_76 -> V_4 ;
}
struct V_160 * F_185 ( void )
{
struct V_160 * V_278 ;
int V_16 ;
if ( F_170 () )
return F_82 ( - V_71 ) ;
V_278 = F_103 ( sizeof( * V_278 ) , V_67 ) ;
if ( ! V_278 )
return F_82 ( - V_68 ) ;
if ( F_190 ( & V_303 ) ) {
V_16 = F_92 () ;
if ( V_16 ) {
F_33 ( V_278 ) ;
return F_82 ( V_16 ) ;
}
}
F_191 ( & V_278 -> V_304 , & V_303 ) ;
return V_278 ;
}
static int F_183 ( struct V_160 * V_278 , const char * V_126 )
{
struct V_160 * V_325 ;
V_325 = F_168 ( V_126 ) ;
if ( V_325 )
return - V_71 ;
V_278 -> V_126 = V_126 ;
return 0 ;
}
int F_192 ( struct V_160 * V_278 , const char * V_126 )
{
int V_16 ;
F_155 () ;
V_16 = F_183 ( V_278 , V_126 ) ;
F_156 () ;
return V_16 ;
}
int F_193 ( struct V_160 * V_278 )
{
int V_16 ;
V_16 = 0 ;
F_155 () ;
if ( ! F_171 ( & V_303 ) )
V_16 = - V_71 ;
else
V_278 -> V_305 = true ;
F_156 () ;
return V_16 ;
}
void F_180 ( struct V_160 * V_278 )
{
F_194 ( & V_278 -> V_304 ) ;
if ( V_278 -> V_314 )
F_33 ( V_278 -> V_126 ) ;
F_33 ( V_278 ) ;
if ( F_190 ( & V_303 ) )
F_94 () ;
}
static void * F_86 ( const char * V_156 )
{
struct V_160 * V_160 ;
F_18 () ;
F_155 () ;
V_160 = F_173 ( V_156 ) ;
if ( ! V_160 )
V_160 = F_82 ( - V_77 ) ;
else if ( V_160 -> V_326 )
V_160 = F_82 ( - V_71 ) ;
else if ( V_160 -> V_327 &&
V_160 -> V_327 ( V_160 ) )
V_160 = F_82 ( - V_77 ) ;
else
V_160 -> V_326 = true ;
F_156 () ;
return V_160 ;
}
static void F_89 ( struct V_9 * V_9 )
{
struct V_160 * V_160 ;
F_18 () ;
F_155 () ;
V_160 = V_9 -> V_37 ;
if ( V_160 )
V_160 -> V_326 = false ;
if ( V_160 -> V_328 )
V_160 -> V_328 ( V_160 ) ;
F_156 () ;
}
static int F_29 ( struct V_9 * V_10 )
{
struct V_160 * V_329 ;
int V_16 = 0 ;
F_18 () ;
F_155 () ;
V_329 = V_10 -> V_37 ;
if ( ! V_329 ) {
V_16 = - V_46 ;
goto V_97;
}
if ( F_49 ( V_329 -> V_279 ) ) {
V_16 = - V_71 ;
goto V_97;
}
V_329 -> V_279 = true ;
V_329 -> V_9 = V_10 ;
if ( V_329 -> V_330 )
V_16 = V_329 -> V_330 ( V_10 ) ;
V_97:
F_156 () ;
return V_16 ;
}
static void F_110 ( struct V_9 * V_10 )
{
struct V_160 * V_329 ;
F_18 () ;
F_155 () ;
V_329 = V_10 -> V_37 ;
if ( ! V_329 )
goto V_97;
V_329 -> V_279 = false ;
if ( V_329 -> V_331 )
V_329 -> V_331 ( V_10 ) ;
if ( ! V_329 -> V_148 || V_329 -> V_148 -> V_277
|| ! V_329 -> V_148 -> V_276 . V_308 . V_332 . V_333 )
goto V_97;
F_195 ( V_329 -> V_148 ->
V_276 . V_308 . V_332 . V_333 -> V_333 ) ;
V_97:
F_156 () ;
}
static int F_20 ( struct V_40 * V_40 , unsigned V_334 )
{
return V_334
? F_38 ( F_196 ( V_40 ) ) ? 0 : - V_66
: F_197 ( V_40 ) ;
}
static char * F_21 ( const char T_3 * V_23 , T_1 V_14 )
{
char * V_13 ;
if ( F_10 ( ! V_14 ) )
return NULL ;
V_13 = F_39 ( V_14 , V_67 ) ;
if ( F_10 ( ! V_13 ) )
return F_82 ( - V_68 ) ;
if ( F_10 ( F_198 ( V_13 , V_23 , V_14 ) ) ) {
F_33 ( V_13 ) ;
return F_82 ( - V_64 ) ;
}
F_14 ( L_48 ) ;
F_150 ( L_46 , V_13 , V_14 ) ;
return V_13 ;
}
