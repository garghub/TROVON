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
F_8 ( V_10 -> V_12 ) ;
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
T_2 V_16 ;
int V_89 ;
goto V_90;
do {
F_7 ( & V_88 -> V_10 -> V_91 ) ;
F_28 ( & V_88 -> V_40 ) ;
V_90:
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
if ( F_50 ( V_88 -> V_92 ,
( V_6 = V_88 -> V_6 ) ) ) {
V_16 = - V_28 ;
goto error;
}
}
V_89 = ! V_86 == ! V_88 -> V_93 ;
if ( V_89 && V_88 -> V_94 ) {
V_16 = - V_46 ;
goto error;
}
if ( ! V_89 && ! V_13 ) {
V_13 = F_51 ( V_14 , V_67 ) ;
if ( F_10 ( ! V_13 ) )
return - V_68 ;
if ( ! V_86 &&
F_10 ( F_52 ( V_13 , V_23 , V_14 ) ) ) {
V_16 = - V_64 ;
goto error;
}
}
V_16 = F_20 ( & V_88 -> V_40 ,
V_35 -> V_41 & V_42 ) ;
if ( F_10 ( V_16 ) )
goto error;
F_31 ( & V_88 -> V_10 -> V_91 ) ;
} while ( F_10 ( V_88 -> V_6 != V_6 ) );
if ( F_10 ( V_89 ) ) {
if ( F_38 ( V_88 -> V_6 == V_6 ) && ! F_49 ( ! V_6 -> V_6 ) )
F_15 ( V_6 -> V_6 ) ;
F_7 ( & V_88 -> V_10 -> V_91 ) ;
V_16 = - V_95 ;
} else {
F_53 ( V_96 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_11 = & V_96 ;
V_8 -> F_47 = F_46 ;
V_8 -> V_23 = V_13 ;
V_8 -> V_24 = V_14 ;
V_16 = F_9 ( V_6 -> V_6 , V_8 , V_27 ) ;
F_7 ( & V_88 -> V_10 -> V_91 ) ;
if ( F_10 ( V_16 < 0 ) ) {
} else if ( F_10 ( F_11 ( & V_96 ) ) ) {
V_16 = - V_28 ;
F_12 ( V_6 -> V_6 , V_8 ) ;
} else {
V_16 = V_6 -> V_84 ;
if ( V_86 && V_16 > 0 &&
F_10 ( F_54 ( V_23 , V_13 , V_16 ) ) )
V_16 = - V_64 ;
}
}
F_28 ( & V_88 -> V_40 ) ;
error:
F_33 ( V_13 ) ;
return V_16 ;
}
static T_2
F_55 ( struct V_35 * V_35 , const char T_3 * V_23 , T_1 V_14 ,
T_4 * V_36 )
{
F_18 () ;
return F_48 ( V_35 , ( char T_3 * ) V_23 , V_14 , 0 ) ;
}
static T_2
F_56 ( struct V_35 * V_35 , char T_3 * V_23 , T_1 V_14 , T_4 * V_36 )
{
F_18 () ;
return F_48 ( V_35 , V_23 , V_14 , 1 ) ;
}
static int
F_57 ( struct V_69 * V_69 , struct V_35 * V_35 )
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
F_58 ( struct V_69 * V_69 , struct V_35 * V_35 )
{
struct V_87 * V_88 = V_69 -> V_70 ;
F_18 () ;
F_43 ( V_88 -> V_10 ) ;
return 0 ;
}
static long F_59 ( struct V_35 * V_35 , unsigned V_72 ,
unsigned long V_73 )
{
struct V_87 * V_88 = V_35 -> V_37 ;
int V_16 ;
F_18 () ;
if ( F_49 ( V_88 -> V_10 -> V_43 != V_48 ) )
return - V_77 ;
F_31 ( & V_88 -> V_10 -> V_91 ) ;
if ( F_38 ( V_88 -> V_6 ) ) {
switch ( V_72 ) {
case V_97 :
V_16 = F_60 ( V_88 -> V_6 -> V_6 ) ;
break;
case V_98 :
F_61 ( V_88 -> V_6 -> V_6 ) ;
V_16 = 0 ;
break;
case V_99 :
V_16 = F_62 ( V_88 -> V_6 -> V_6 ) ;
break;
case V_100 :
V_16 = V_88 -> V_6 -> V_101 ;
break;
default:
V_16 = - V_80 ;
}
} else {
V_16 = - V_77 ;
}
F_7 ( & V_88 -> V_10 -> V_91 ) ;
return V_16 ;
}
static struct V_69 * T_5
F_63 ( struct V_102 * V_103 , void * V_13 ,
const struct V_104 * V_105 ,
const struct V_106 * V_107 ,
struct V_108 * V_109 )
{
struct V_69 * V_69 ;
F_18 () ;
V_69 = F_64 ( V_103 ) ;
if ( F_38 ( V_69 ) ) {
struct V_110 V_111 = V_112 ;
V_69 -> V_113 = F_65 () ;
V_69 -> V_114 = V_109 -> V_115 ;
V_69 -> V_116 = V_109 -> V_117 ;
V_69 -> V_118 = V_109 -> V_119 ;
V_69 -> V_120 = V_111 ;
V_69 -> V_121 = V_111 ;
V_69 -> V_122 = V_111 ;
V_69 -> V_70 = V_13 ;
if ( V_105 )
V_69 -> V_123 = V_105 ;
if ( V_107 )
V_69 -> V_124 = V_107 ;
}
return V_69 ;
}
static struct V_69 * F_66 ( struct V_102 * V_103 ,
const char * V_125 , void * V_13 ,
const struct V_104 * V_105 ,
struct V_126 * * V_127 )
{
struct V_9 * V_10 = V_103 -> V_128 ;
struct V_126 * V_126 ;
struct V_69 * V_69 ;
F_18 () ;
V_126 = F_67 ( V_103 -> V_129 , V_125 ) ;
if ( F_10 ( ! V_126 ) )
return NULL ;
V_69 = F_63 ( V_103 , V_13 , V_105 , NULL , & V_10 -> V_130 ) ;
if ( F_10 ( ! V_69 ) ) {
F_68 ( V_126 ) ;
return NULL ;
}
F_69 ( V_126 , V_69 ) ;
if ( V_127 )
* V_127 = V_126 ;
return V_69 ;
}
static int F_70 ( struct V_102 * V_103 , void * V_131 , int V_132 )
{
struct V_133 * V_13 = V_131 ;
struct V_69 * V_69 ;
struct V_9 * V_10 ;
F_18 () ;
V_10 = F_71 () ;
if ( F_10 ( ! V_10 ) )
goto V_134;
V_10 -> V_103 = V_103 ;
V_10 -> V_135 = F_72 ( V_13 -> V_135 , V_67 ) ;
if ( F_10 ( ! V_10 -> V_135 ) )
goto V_134;
V_10 -> V_130 = V_13 -> V_109 ;
V_10 -> V_37 = V_13 -> V_37 ;
V_13 -> V_9 = V_10 ;
V_103 -> V_128 = V_10 ;
V_103 -> V_136 = V_137 ;
V_103 -> V_138 = V_139 ;
V_103 -> V_140 = V_141 ;
V_103 -> V_142 = & V_143 ;
V_103 -> V_144 = 1 ;
V_13 -> V_109 . V_115 = V_13 -> V_145 ;
V_69 = F_63 ( V_103 , NULL ,
& V_146 ,
& V_147 ,
& V_13 -> V_109 ) ;
V_103 -> V_129 = F_73 ( V_69 ) ;
if ( F_10 ( ! V_103 -> V_129 ) )
goto V_134;
if ( F_10 ( ! F_66 ( V_103 , L_5 , V_10 ,
& V_148 , NULL ) ) )
goto V_134;
return 0 ;
V_134:
return - V_68 ;
}
static int F_74 ( struct V_133 * V_13 , char * V_149 )
{
F_18 () ;
if ( ! V_149 || ! * V_149 )
return 0 ;
for (; ; ) {
unsigned long V_73 ;
char * V_150 , * V_151 ;
V_151 = strchr ( V_149 , ',' ) ;
if ( V_151 )
* V_151 = 0 ;
V_150 = strchr ( V_149 , '=' ) ;
if ( F_10 ( ! V_150 ) ) {
F_75 ( L_6 , V_149 ) ;
return - V_46 ;
}
* V_150 = 0 ;
if ( F_76 ( V_150 + 1 , 0 , & V_73 ) ) {
F_75 ( L_7 , V_149 , V_150 + 1 ) ;
return - V_46 ;
}
switch ( V_150 - V_149 ) {
case 5 :
if ( ! memcmp ( V_149 , L_8 , 5 ) )
V_13 -> V_145 = ( V_73 & 0555 ) | V_152 ;
else if ( ! memcmp ( V_149 , L_9 , 5 ) )
V_13 -> V_109 . V_115 = ( V_73 & 0666 ) | V_153 ;
else
goto V_154;
break;
case 4 :
if ( ! memcmp ( V_149 , L_10 , 4 ) ) {
V_13 -> V_145 = ( V_73 & 0555 ) | V_152 ;
V_13 -> V_109 . V_115 = ( V_73 & 0666 ) | V_153 ;
} else {
goto V_154;
}
break;
case 3 :
if ( ! memcmp ( V_149 , L_11 , 3 ) ) {
V_13 -> V_109 . V_117 = F_77 ( F_78 () , V_73 ) ;
if ( ! F_79 ( V_13 -> V_109 . V_117 ) ) {
F_75 ( L_12 , V_149 , V_73 ) ;
return - V_46 ;
}
} else if ( ! memcmp ( V_149 , L_13 , 3 ) ) {
V_13 -> V_109 . V_119 = F_80 ( F_78 () , V_73 ) ;
if ( ! F_81 ( V_13 -> V_109 . V_119 ) ) {
F_75 ( L_12 , V_149 , V_73 ) ;
return - V_46 ;
}
} else {
goto V_154;
}
break;
default:
V_154:
F_75 ( L_14 , V_149 ) ;
return - V_46 ;
}
if ( ! V_151 )
break;
V_149 = V_151 + 1 ;
}
return 0 ;
}
static struct V_126 *
F_82 ( struct V_155 * V_156 , int V_50 ,
const char * V_135 , void * V_149 )
{
struct V_133 V_13 = {
. V_109 = {
. V_115 = V_153 | 0600 ,
. V_117 = V_157 ,
. V_119 = V_158 ,
} ,
. V_145 = V_152 | 0500 ,
} ;
struct V_126 * V_159 ;
int V_16 ;
void * V_160 ;
F_18 () ;
V_16 = F_74 ( & V_13 , V_149 ) ;
if ( F_10 ( V_16 < 0 ) )
return F_83 ( V_16 ) ;
V_160 = F_84 ( V_135 ) ;
if ( F_22 ( V_160 ) )
return V_160 ;
V_13 . V_135 = V_135 ;
V_13 . V_37 = V_160 ;
V_159 = F_85 ( V_156 , V_50 , & V_13 , F_70 ) ;
if ( F_22 ( V_159 ) )
F_86 ( V_13 . V_9 ) ;
return V_159 ;
}
static void
F_87 ( struct V_102 * V_103 )
{
F_18 () ;
F_88 ( V_103 ) ;
if ( V_103 -> V_128 ) {
F_86 ( V_103 -> V_128 ) ;
F_89 ( V_103 -> V_128 ) ;
}
}
static int F_90 ( void )
{
int V_16 ;
F_18 () ;
V_16 = F_91 ( & V_161 ) ;
if ( F_38 ( ! V_16 ) )
F_24 ( L_15 ) ;
else
F_75 ( L_16 , V_16 ) ;
return V_16 ;
}
static void F_92 ( void )
{
F_18 () ;
F_24 ( L_17 ) ;
F_93 ( & V_161 ) ;
}
static void F_94 ( struct V_9 * V_10 )
{
F_18 () ;
F_95 ( & V_10 -> V_162 ) ;
}
static void F_41 ( struct V_9 * V_10 )
{
F_18 () ;
F_95 ( & V_10 -> V_162 ) ;
F_95 ( & V_10 -> V_163 ) ;
}
static void F_89 ( struct V_9 * V_10 )
{
F_18 () ;
if ( F_10 ( F_96 ( & V_10 -> V_162 ) ) ) {
F_24 ( L_18 , V_164 ) ;
F_97 ( V_10 ) ;
F_98 ( F_99 ( & V_10 -> V_18 . V_21 ) ||
F_99 ( & V_10 -> V_12 . V_92 ) ) ;
F_33 ( V_10 -> V_135 ) ;
F_33 ( V_10 ) ;
}
}
static void F_43 ( struct V_9 * V_10 )
{
F_18 () ;
if ( F_96 ( & V_10 -> V_163 ) ) {
V_10 -> V_43 = V_47 ;
F_100 ( V_10 ) ;
}
F_89 ( V_10 ) ;
}
static struct V_9 * F_71 ( void )
{
struct V_9 * V_10 = F_51 ( sizeof *V_10 , V_67 ) ;
if ( F_10 ( ! V_10 ) )
return 0 ;
F_18 () ;
F_101 ( & V_10 -> V_162 , 1 ) ;
F_101 ( & V_10 -> V_163 , 0 ) ;
V_10 -> V_43 = V_44 ;
F_102 ( & V_10 -> V_40 ) ;
F_103 ( & V_10 -> V_91 ) ;
F_104 ( & V_10 -> V_18 . V_21 ) ;
F_105 ( & V_10 -> V_12 ) ;
V_10 -> V_18 . V_32 = 1 ;
return V_10 ;
}
static void F_97 ( struct V_9 * V_10 )
{
F_18 () ;
if ( F_106 ( V_49 , & V_10 -> V_50 ) )
F_107 ( V_10 ) ;
F_98 ( V_10 -> V_25 ) ;
if ( V_10 -> V_165 )
F_108 ( V_10 -> V_165 , V_10 -> V_166 ) ;
F_33 ( V_10 -> V_167 ) ;
F_33 ( V_10 -> V_168 ) ;
F_33 ( V_10 -> V_169 ) ;
}
static void F_100 ( struct V_9 * V_10 )
{
F_18 () ;
F_97 ( V_10 ) ;
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
static int F_109 ( struct V_9 * V_10 , struct V_176 * V_177 )
{
struct V_178 * * V_179 ;
int V_180 ;
F_18 () ;
if ( F_49 ( V_10 -> V_43 != V_48
|| F_110 ( V_181 , & V_10 -> V_50 ) ) )
return - V_55 ;
V_180 = F_111 ( V_177 , V_10 -> V_174 ) ;
if ( F_10 ( V_180 < 0 ) )
return V_180 ;
V_10 -> V_15 = F_112 ( V_177 -> V_25 -> V_26 , V_67 ) ;
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
F_94 ( V_10 ) ;
return 0 ;
}
static void F_113 ( struct V_9 * V_10 )
{
F_18 () ;
if ( ! F_49 ( ! V_10 -> V_25 ) ) {
F_114 ( V_10 -> V_25 -> V_26 , V_10 -> V_15 ) ;
V_10 -> V_15 = NULL ;
V_10 -> V_25 = NULL ;
F_89 ( V_10 ) ;
F_115 ( V_181 , & V_10 -> V_50 ) ;
}
}
static int F_27 ( struct V_9 * V_10 )
{
struct V_87 * V_88 , * V_165 ;
unsigned V_59 , V_63 ;
F_18 () ;
V_63 = V_10 -> V_166 ;
V_165 = F_116 ( V_63 , sizeof( * V_165 ) , V_67 ) ;
if ( ! V_165 )
return - V_68 ;
V_88 = V_165 ;
for ( V_59 = 1 ; V_59 <= V_63 ; ++ V_59 , ++ V_88 ) {
V_88 -> V_10 = V_10 ;
F_102 ( & V_88 -> V_40 ) ;
F_104 ( & V_88 -> V_92 ) ;
sprintf ( V_165 -> V_125 , L_19 , V_59 ) ;
if ( ! F_10 ( F_66 ( V_10 -> V_103 , V_165 -> V_125 , V_88 ,
& V_187 ,
& V_88 -> V_126 ) ) ) {
F_108 ( V_165 , V_59 - 1 ) ;
return - V_68 ;
}
}
V_10 -> V_165 = V_165 ;
return 0 ;
}
static void F_108 ( struct V_87 * V_165 , unsigned V_63 )
{
struct V_87 * V_88 = V_165 ;
F_18 () ;
for (; V_63 ; -- V_63 , ++ V_88 ) {
F_98 ( F_117 ( & V_88 -> V_40 ) ||
F_99 ( & V_88 -> V_92 ) ) ;
if ( V_88 -> V_126 ) {
F_118 ( V_88 -> V_126 ) ;
F_68 ( V_88 -> V_126 ) ;
V_88 -> V_126 = NULL ;
}
}
F_33 ( V_165 ) ;
}
static int F_119 ( struct V_176 * V_177 ,
struct V_188 * V_189 ,
struct V_9 * V_10 )
{
struct V_1 * V_76 ;
int V_16 ;
F_18 () ;
V_76 = F_51 ( sizeof *V_76 , V_67 ) ;
if ( F_10 ( ! V_76 ) )
return - V_68 ;
V_76 -> V_4 . V_125 = L_20 ;
V_76 -> V_4 . V_184 = V_10 -> V_169 ;
V_76 -> V_4 . V_190 = V_191 ;
V_76 -> V_4 . V_192 = V_193 ;
V_76 -> V_4 . V_194 = V_195 ;
V_76 -> V_4 . V_196 = V_197 ;
V_76 -> V_4 . V_19 = V_198 ;
V_76 -> V_4 . V_199 = V_200 ;
V_76 -> V_4 . V_201 = V_202 ;
V_76 -> V_203 = V_189 ;
V_76 -> V_25 = V_177 -> V_25 ;
V_76 -> V_10 = V_10 ;
F_94 ( V_10 ) ;
V_16 = F_120 ( V_189 , & V_76 -> V_4 ) ;
if ( F_10 ( V_16 ) )
F_121 ( V_76 ) ;
return V_16 ;
}
static void F_121 ( struct V_1 * V_76 )
{
struct V_82 * V_6 = V_76 -> V_204 ;
unsigned V_63 = V_76 -> V_10 -> V_166 ;
unsigned long V_50 ;
F_18 () ;
F_122 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
do {
if ( V_6 -> V_6 && V_6 -> V_8 )
F_114 ( V_6 -> V_6 , V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
++ V_6 ;
} while ( -- V_63 );
F_123 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
F_89 ( V_76 -> V_10 ) ;
F_33 ( V_76 -> V_204 ) ;
F_33 ( V_76 ) ;
}
static void F_124 ( struct V_1 * V_76 )
{
struct V_82 * V_6 = V_76 -> V_204 ;
struct V_87 * V_88 = V_76 -> V_10 -> V_165 ;
unsigned V_63 = V_76 -> V_10 -> V_166 ;
unsigned long V_50 ;
F_122 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
do {
if ( F_38 ( V_6 -> V_6 ) )
F_125 ( V_6 -> V_6 ) ;
V_88 -> V_6 = NULL ;
++ V_6 ;
++ V_88 ;
} while ( -- V_63 );
F_123 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
}
static int F_126 ( struct V_1 * V_76 )
{
struct V_9 * V_10 = V_76 -> V_10 ;
struct V_82 * V_6 = V_76 -> V_204 ;
struct V_87 * V_88 = V_10 -> V_165 ;
unsigned V_63 = V_10 -> V_166 ;
unsigned long V_50 ;
int V_16 = 0 ;
F_122 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
do {
struct V_205 * V_206 ;
V_206 = V_6 -> V_207 [ V_6 -> V_207 [ 1 ] ? 1 : 0 ] ;
V_6 -> V_6 -> V_83 = V_6 ;
V_6 -> V_6 -> V_208 = V_206 ;
V_16 = F_127 ( V_6 -> V_6 ) ;
if ( F_38 ( ! V_16 ) ) {
V_88 -> V_6 = V_6 ;
V_88 -> V_93 = F_128 ( V_206 ) ;
V_88 -> V_94 = F_129 ( V_206 ) ;
} else {
break;
}
F_130 ( & V_88 -> V_92 ) ;
++ V_6 ;
++ V_88 ;
} while ( -- V_63 );
F_123 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
return V_16 ;
}
static int T_5 F_131 ( char * V_13 , unsigned V_14 ,
T_6 V_209 , void * V_210 )
{
struct V_211 * V_212 = ( void * ) V_13 ;
T_7 V_24 ;
int V_16 ;
F_18 () ;
if ( V_14 < 2 ) {
F_14 ( L_21 ) ;
return - V_46 ;
}
V_24 = V_212 -> V_213 ;
if ( V_14 < V_24 ) {
F_14 ( L_22 ) ;
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
switch ( V_212 -> V_214 ) {
case V_215 :
case V_216 :
case V_217 :
case V_218 :
F_14 ( L_23 ,
V_212 -> V_214 ) ;
return - V_46 ;
case V_219 : {
struct V_220 * V_206 = ( void * ) V_212 ;
F_14 ( L_24 ) ;
if ( V_24 != sizeof *V_206 )
goto V_221;
F_135 ( V_222 , V_206 -> V_223 ) ;
if ( V_206 -> V_224 )
F_135 ( STRING , V_206 -> V_224 ) ;
}
break;
case V_225 : {
struct V_205 * V_206 = ( void * ) V_212 ;
F_14 ( L_25 ) ;
if ( V_24 != V_226 &&
V_24 != V_227 )
goto V_221;
F_135 ( V_228 , V_206 -> V_229 ) ;
}
break;
case V_230 :
F_14 ( L_26 ) ;
if ( V_24 != sizeof( struct V_231 ) )
goto V_221;
break;
case V_232 :
if ( V_24 != sizeof( struct V_233 ) )
goto V_221;
break;
case V_234 : {
struct V_235 * V_206 = ( void * ) V_212 ;
F_14 ( L_27 ) ;
if ( V_24 != sizeof *V_206 )
goto V_221;
if ( V_206 -> V_236 )
F_135 ( STRING , V_206 -> V_236 ) ;
}
break;
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
F_14 ( L_28 , V_212 -> V_214 ) ;
return - V_46 ;
default:
F_14 ( L_29 , V_212 -> V_214 ) ;
return - V_46 ;
V_221:
F_14 ( L_30 ,
V_212 -> V_213 , V_212 -> V_214 ) ;
return - V_46 ;
}
#undef F_135
#undef V_242
#undef F_132
#undef F_133
#undef F_134
return V_24 ;
}
static int T_5 F_136 ( unsigned V_63 , char * V_13 , unsigned V_14 ,
T_6 V_209 , void * V_210 )
{
const unsigned V_243 = V_14 ;
unsigned long V_101 = 0 ;
F_18 () ;
for (; ; ) {
int V_16 ;
if ( V_101 == V_63 )
V_13 = NULL ;
V_16 = V_209 ( V_244 , ( T_7 * ) V_101 , ( void * ) V_13 , V_210 ) ;
if ( F_10 ( V_16 < 0 ) ) {
F_16 ( L_31 ,
V_101 , V_16 ) ;
return V_16 ;
}
if ( ! V_13 )
return V_243 - V_14 ;
V_16 = F_131 ( V_13 , V_14 , V_209 , V_210 ) ;
if ( F_10 ( V_16 < 0 ) ) {
F_16 ( L_32 , V_164 , V_16 ) ;
return V_16 ;
}
V_14 -= V_16 ;
V_13 += V_16 ;
++ V_101 ;
}
}
static int F_137 ( enum V_245 type ,
T_7 * V_246 , struct V_211 * V_208 ,
void * V_210 )
{
struct V_9 * V_10 = V_210 ;
F_18 () ;
switch ( type ) {
case V_244 :
break;
case V_247 :
if ( * V_246 >= V_10 -> V_175 )
V_10 -> V_175 = * V_246 + 1 ;
break;
case V_248 :
if ( * V_246 > V_10 -> V_174 )
V_10 -> V_174 = * V_246 ;
break;
case V_249 :
if ( ( * V_246 & V_250 ) > V_10 -> V_166 )
V_10 -> V_166 = ( * V_246 & V_250 ) ;
break;
}
return 0 ;
}
static int F_25 ( struct V_9 * V_10 ,
char * const V_131 , T_1 V_14 )
{
unsigned V_251 , V_252 ;
int V_253 , V_16 = - V_46 ;
char * V_13 = V_131 ;
F_18 () ;
if ( F_10 ( F_138 ( V_13 ) != V_254 ||
F_138 ( V_13 + 4 ) != V_14 ) )
goto error;
V_251 = F_138 ( V_13 + 8 ) ;
V_252 = F_138 ( V_13 + 12 ) ;
if ( ! V_251 && ! V_252 )
goto V_255;
V_13 += 16 ;
V_14 -= 16 ;
if ( F_38 ( V_251 ) ) {
V_253 = F_136 ( V_251 , V_13 , V_14 ,
F_137 , V_10 ) ;
if ( F_10 ( V_253 < 0 ) ) {
V_16 = V_253 ;
goto error;
}
V_13 += V_253 ;
V_14 -= V_253 ;
} else {
V_253 = 0 ;
}
if ( F_38 ( V_252 ) ) {
V_16 = F_136 ( V_252 , V_13 , V_14 ,
F_137 , V_10 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
} else {
V_16 = 0 ;
}
if ( F_10 ( V_14 != V_16 ) )
goto V_255;
V_10 -> V_171 = V_253 ;
V_10 -> V_170 = V_253 + V_16 ;
V_10 -> V_167 = V_131 ;
V_10 -> V_172 = V_251 ;
V_10 -> V_173 = V_252 ;
return 0 ;
V_255:
V_16 = - V_46 ;
error:
F_33 ( V_131 ) ;
return V_16 ;
}
static int F_26 ( struct V_9 * V_10 ,
char * const V_131 , T_1 V_14 )
{
T_9 V_256 , V_257 , V_258 ;
struct V_178 * * V_169 , * V_156 ;
struct V_182 * V_184 , * V_186 ;
const char * V_13 = V_131 ;
F_18 () ;
if ( F_10 ( F_138 ( V_13 ) != V_259 ||
F_138 ( V_13 + 4 ) != V_14 ) )
goto error;
V_256 = F_138 ( V_13 + 8 ) ;
V_258 = F_138 ( V_13 + 12 ) ;
if ( F_10 ( ! V_256 != ! V_258 ) )
goto error;
V_257 = V_10 -> V_174 ;
if ( F_10 ( V_256 < V_257 ) )
goto error;
if ( ! V_257 ) {
F_33 ( V_131 ) ;
return 0 ;
}
{
struct {
struct V_178 * V_169 [ V_258 + 1 ] ;
struct V_178 V_260 [ V_258 ] ;
struct V_182 V_184 [ V_258 * ( V_257 + 1 ) ] ;
} * V_261 ;
unsigned V_59 = 0 ;
V_261 = F_39 ( sizeof *V_261 , V_67 ) ;
if ( F_10 ( ! V_261 ) ) {
F_33 ( V_131 ) ;
return - V_68 ;
}
V_169 = V_261 -> V_169 ;
V_156 = V_261 -> V_260 ;
V_59 = V_258 ;
do {
* V_169 ++ = V_156 ++ ;
} while ( -- V_59 );
* V_169 = NULL ;
V_169 = V_261 -> V_169 ;
V_156 = V_261 -> V_260 ;
V_186 = V_261 -> V_184 ;
V_184 = V_186 ;
}
V_13 += 16 ;
V_14 -= 16 ;
do {
unsigned V_262 = V_257 ;
if ( F_10 ( V_14 < 3 ) )
goto V_263;
V_156 -> V_264 = F_139 ( V_13 ) ;
V_156 -> V_184 = V_186 ;
++ V_156 ;
V_13 += 2 ;
V_14 -= 2 ;
do {
T_1 V_24 = F_140 ( V_13 , V_14 ) ;
if ( F_10 ( V_24 == V_14 ) )
goto V_263;
if ( F_38 ( V_262 ) ) {
V_186 -> V_186 = V_13 ;
-- V_262 ;
++ V_186 ;
}
V_13 += V_24 + 1 ;
V_14 -= V_24 + 1 ;
} while ( -- V_256 );
V_186 -> V_185 = 0 ;
V_186 -> V_186 = NULL ;
++ V_186 ;
} while ( -- V_258 );
if ( F_10 ( V_14 ) )
goto V_263;
V_10 -> V_169 = V_169 ;
V_10 -> V_168 = V_131 ;
return 0 ;
V_263:
F_33 ( V_169 ) ;
error:
F_33 ( V_131 ) ;
return - V_46 ;
}
static void F_141 ( struct V_9 * V_10 ,
enum V_265 type )
{
enum V_265 V_266 , V_267 = type ;
int V_268 = 0 ;
if ( V_10 -> V_29 == V_52 )
V_10 -> V_29 = V_38 ;
switch ( type ) {
case V_269 :
V_267 = V_270 ;
case V_270 :
case V_61 :
V_266 = type ;
break;
case V_271 :
case V_272 :
case V_273 :
case V_274 :
V_266 = V_270 ;
V_267 = V_269 ;
V_268 = 1 ;
break;
default:
F_142 () ;
}
{
T_7 * V_18 = V_10 -> V_18 . V_60 , * V_275 = V_18 ;
unsigned V_56 = V_10 -> V_18 . V_63 ;
for (; V_56 ; -- V_56 , ++ V_18 )
if ( ( * V_18 == V_266 || * V_18 == V_267 ) == V_268 )
* V_275 ++ = * V_18 ;
else
F_14 ( L_33 , * V_18 ) ;
V_10 -> V_18 . V_63 = V_275 - V_10 -> V_18 . V_60 ;
}
F_14 ( L_34 , type ) ;
V_10 -> V_18 . V_60 [ V_10 -> V_18 . V_63 ++ ] = type ;
F_143 ( & V_10 -> V_18 . V_21 ) ;
}
static void F_144 ( struct V_9 * V_10 ,
enum V_265 type )
{
unsigned long V_50 ;
F_122 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
F_141 ( V_10 , type ) ;
F_123 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
}
static int F_145 ( enum V_245 type , T_7 * V_246 ,
struct V_211 * V_208 ,
void * V_210 )
{
struct V_205 * V_206 = ( void * ) V_208 ;
struct V_1 * V_76 = V_210 ;
struct V_82 * V_82 ;
const int V_276 = V_76 -> V_4 . V_277 != NULL ;
unsigned V_278 ;
if ( type != V_244 )
return 0 ;
if ( V_276 )
V_76 -> V_4 . V_277 [ ( long ) V_246 ] = V_208 ;
else
V_76 -> V_4 . V_279 [ ( long ) V_246 ] = V_208 ;
if ( ! V_208 || V_208 -> V_214 != V_225 )
return 0 ;
V_278 = ( V_206 -> V_229 & V_250 ) - 1 ;
V_82 = V_76 -> V_204 + V_278 ;
if ( F_10 ( V_82 -> V_207 [ V_276 ] ) ) {
F_14 ( L_35 ,
V_276 ? L_36 : L_37 ,
V_206 -> V_229 & V_250 ) ;
return - V_46 ;
}
V_82 -> V_207 [ V_276 ] = V_206 ;
F_146 ( L_38 , V_206 , V_206 -> V_213 ) ;
if ( V_82 -> V_6 ) {
V_206 -> V_229 = V_82 -> V_207 [ 0 ] -> V_229 ;
if ( ! V_206 -> V_280 )
V_206 -> V_280 = V_82 -> V_207 [ 0 ] -> V_280 ;
} else {
struct V_7 * V_8 ;
struct V_5 * V_6 ;
F_14 ( L_39 ) ;
V_6 = F_147 ( V_76 -> V_25 , V_206 ) ;
if ( F_10 ( ! V_6 ) )
return - V_281 ;
V_6 -> V_83 = V_76 -> V_204 + V_278 ;
V_8 = F_112 ( V_6 , V_67 ) ;
if ( F_10 ( ! V_8 ) )
return - V_68 ;
V_82 -> V_6 = V_6 ;
V_82 -> V_8 = V_8 ;
V_76 -> V_282 [ V_206 -> V_229 &
V_250 ] = V_278 + 1 ;
}
F_146 ( L_40 , V_206 , V_206 -> V_213 ) ;
return 0 ;
}
static int F_148 ( enum V_245 type , T_7 * V_246 ,
struct V_211 * V_208 ,
void * V_210 )
{
struct V_1 * V_76 = V_210 ;
unsigned V_278 ;
T_7 V_283 ;
switch ( type ) {
default:
case V_244 :
return 0 ;
case V_247 :
V_278 = * V_246 ;
if ( V_76 -> V_284 [ V_278 ] < 0 ) {
int V_185 = F_149 ( V_76 -> V_203 , & V_76 -> V_4 ) ;
if ( F_10 ( V_185 < 0 ) )
return V_185 ;
V_76 -> V_284 [ V_278 ] = V_185 ;
}
V_283 = V_76 -> V_284 [ V_278 ] ;
break;
case V_248 :
V_283 = V_76 -> V_10 -> V_169 [ 0 ] -> V_184 [ * V_246 - 1 ] . V_185 ;
break;
case V_249 :
if ( V_208 -> V_214 == V_225 )
return 0 ;
V_278 = ( * V_246 & V_250 ) - 1 ;
if ( F_10 ( ! V_76 -> V_204 [ V_278 ] . V_6 ) )
return - V_46 ;
{
struct V_205 * * V_207 ;
V_207 = V_76 -> V_204 [ V_278 ] . V_207 ;
V_283 = V_207 [ V_207 [ 0 ] ? 0 : 1 ] -> V_229 ;
}
break;
}
F_14 ( L_41 , * V_246 , V_283 ) ;
* V_246 = V_283 ;
return 0 ;
}
static int V_191 ( struct V_188 * V_189 ,
struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
const int V_285 = ! ! V_76 -> V_10 -> V_172 ;
const int V_286 = F_150 ( V_76 -> V_25 ) &&
V_76 -> V_10 -> V_173 ;
int V_16 ;
struct {
struct V_82 V_204 [ V_10 -> V_166 ] ;
struct V_211
* V_287 [ V_285 ? V_10 -> V_172 + 1 : 0 ] ;
struct V_211
* V_288 [ V_286 ? V_10 -> V_173 + 1 : 0 ] ;
short V_289 [ V_10 -> V_175 ] ;
char V_167 [ V_286 ? V_10 -> V_170
: V_10 -> V_171 ] ;
} * V_13 ;
F_18 () ;
if ( F_10 ( ! ( V_285 | V_286 ) ) )
return - V_281 ;
V_13 = F_39 ( sizeof *V_13 , V_67 ) ;
if ( F_10 ( ! V_13 ) )
return - V_68 ;
memset ( V_13 -> V_204 , 0 , sizeof V_13 -> V_204 ) ;
memcpy ( V_13 -> V_167 , V_10 -> V_167 + 16 , sizeof V_13 -> V_167 ) ;
memset ( V_13 -> V_289 , 0xff , sizeof V_13 -> V_289 ) ;
for ( V_16 = V_10 -> V_166 ; V_16 ; -- V_16 )
V_13 -> V_204 [ V_16 ] . V_101 = - 1 ;
V_76 -> V_204 = V_13 -> V_204 ;
V_76 -> V_284 = V_13 -> V_289 ;
if ( F_38 ( V_285 ) ) {
V_76 -> V_4 . V_279 = V_13 -> V_287 ;
V_16 = F_136 ( V_10 -> V_172 ,
V_13 -> V_167 ,
sizeof V_13 -> V_167 ,
F_145 , V_76 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
} else {
V_16 = 0 ;
}
if ( F_38 ( V_286 ) ) {
V_76 -> V_4 . V_277 = V_13 -> V_288 ;
V_16 = F_136 ( V_10 -> V_173 ,
V_13 -> V_167 + V_16 ,
( sizeof V_13 -> V_167 ) - V_16 ,
F_145 , V_76 ) ;
}
V_16 = F_136 ( V_10 -> V_172 +
( V_286 ? V_10 -> V_173 : 0 ) ,
V_13 -> V_167 , sizeof V_13 -> V_167 ,
F_148 , V_76 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
F_144 ( V_10 , V_271 ) ;
return 0 ;
error:
return V_16 ;
}
static void V_193 ( struct V_188 * V_189 ,
struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
F_18 () ;
if ( V_10 -> V_76 == V_76 ) {
F_124 ( V_76 ) ;
V_10 -> V_76 = NULL ;
}
F_144 ( V_10 , V_272 ) ;
F_121 ( V_76 ) ;
}
static int V_195 ( struct V_2 * V_3 ,
unsigned V_290 , unsigned V_291 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
int V_16 = 0 , V_292 ;
if ( V_291 != ( unsigned ) - 1 ) {
V_292 = F_45 ( V_76 , V_290 ) ;
if ( F_10 ( V_292 < 0 ) )
return V_292 ;
}
if ( V_10 -> V_76 )
F_124 ( V_10 -> V_76 ) ;
if ( V_10 -> V_43 != V_48 )
return - V_77 ;
if ( V_291 == ( unsigned ) - 1 ) {
V_10 -> V_76 = NULL ;
F_144 ( V_10 , V_273 ) ;
return 0 ;
}
V_10 -> V_76 = V_76 ;
V_16 = F_126 ( V_76 ) ;
if ( F_38 ( V_16 >= 0 ) )
F_144 ( V_10 , V_274 ) ;
return V_16 ;
}
static void V_197 ( struct V_2 * V_3 )
{
V_195 ( V_3 , 0 , ( unsigned ) - 1 ) ;
}
static int V_198 ( struct V_2 * V_3 ,
const struct V_293 * V_294 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
unsigned long V_50 ;
int V_16 ;
F_18 () ;
F_14 ( L_42 , V_294 -> V_53 ) ;
F_14 ( L_43 , V_294 -> V_295 ) ;
F_14 ( L_44 , F_6 ( V_294 -> V_296 ) ) ;
F_14 ( L_45 , F_6 ( V_294 -> V_297 ) ) ;
F_14 ( L_46 , F_6 ( V_294 -> V_20 ) ) ;
if ( V_10 -> V_43 != V_48 )
return - V_77 ;
switch ( V_294 -> V_53 & V_298 ) {
case V_299 :
V_16 = F_45 ( V_76 , F_6 ( V_294 -> V_297 ) ) ;
if ( F_10 ( V_16 < 0 ) )
return V_16 ;
break;
case V_300 :
V_16 = F_151 ( V_76 , F_6 ( V_294 -> V_297 ) ) ;
if ( F_10 ( V_16 < 0 ) )
return V_16 ;
break;
default:
return - V_301 ;
}
F_122 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
V_10 -> V_18 . V_19 = * V_294 ;
V_10 -> V_18 . V_19 . V_297 = F_152 ( V_16 ) ;
F_141 ( V_10 , V_61 ) ;
F_123 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
return 0 ;
}
static void V_200 ( struct V_2 * V_3 )
{
F_18 () ;
F_144 ( F_1 ( V_3 ) -> V_10 , V_270 ) ;
}
static void V_202 ( struct V_2 * V_3 )
{
F_18 () ;
F_144 ( F_1 ( V_3 ) -> V_10 , V_269 ) ;
}
static int F_151 ( struct V_1 * V_76 , T_7 V_101 )
{
V_101 = V_76 -> V_282 [ V_101 & V_250 ] ;
return V_101 ? V_101 : - V_302 ;
}
static int F_45 ( struct V_1 * V_76 , T_7 V_292 )
{
short * V_303 = V_76 -> V_284 ;
unsigned V_63 = V_76 -> V_10 -> V_175 ;
for (; V_63 ; -- V_63 , ++ V_303 ) {
if ( * V_303 >= 0 && * V_303 == V_292 )
return V_303 - V_76 -> V_284 ;
}
return - V_302 ;
}
static int F_20 ( struct V_40 * V_40 , unsigned V_304 )
{
return V_304
? F_38 ( F_153 ( V_40 ) ) ? 0 : - V_66
: F_154 ( V_40 ) ;
}
static char * F_21 ( const char T_3 * V_23 , T_1 V_14 )
{
char * V_13 ;
if ( F_10 ( ! V_14 ) )
return NULL ;
V_13 = F_39 ( V_14 , V_67 ) ;
if ( F_10 ( ! V_13 ) )
return F_83 ( - V_68 ) ;
if ( F_10 ( F_52 ( V_13 , V_23 , V_14 ) ) ) {
F_33 ( V_13 ) ;
return F_83 ( - V_64 ) ;
}
F_14 ( L_47 ) ;
F_146 ( L_48 , V_13 , V_14 ) ;
return V_13 ;
}
