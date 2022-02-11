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
struct V_9 * V_10 = V_13 -> V_9 ;
F_18 () ;
V_10 -> V_103 = V_103 ;
V_13 -> V_9 = NULL ;
V_103 -> V_128 = V_10 ;
V_103 -> V_134 = V_135 ;
V_103 -> V_136 = V_137 ;
V_103 -> V_138 = V_139 ;
V_103 -> V_140 = & V_141 ;
V_103 -> V_142 = 1 ;
V_13 -> V_109 . V_115 = V_13 -> V_143 ;
V_69 = F_63 ( V_103 , NULL ,
& V_144 ,
& V_145 ,
& V_13 -> V_109 ) ;
V_103 -> V_129 = F_71 ( V_69 ) ;
if ( F_10 ( ! V_103 -> V_129 ) )
return - V_68 ;
if ( F_10 ( ! F_66 ( V_103 , L_5 , V_10 ,
& V_146 , NULL ) ) )
return - V_68 ;
return 0 ;
}
static int F_72 ( struct V_133 * V_13 , char * V_147 )
{
F_18 () ;
if ( ! V_147 || ! * V_147 )
return 0 ;
for (; ; ) {
unsigned long V_73 ;
char * V_148 , * V_149 ;
V_149 = strchr ( V_147 , ',' ) ;
if ( V_149 )
* V_149 = 0 ;
V_148 = strchr ( V_147 , '=' ) ;
if ( F_10 ( ! V_148 ) ) {
F_73 ( L_6 , V_147 ) ;
return - V_46 ;
}
* V_148 = 0 ;
if ( F_74 ( V_148 + 1 , 0 , & V_73 ) ) {
F_73 ( L_7 , V_147 , V_148 + 1 ) ;
return - V_46 ;
}
switch ( V_148 - V_147 ) {
case 5 :
if ( ! memcmp ( V_147 , L_8 , 5 ) )
V_13 -> V_143 = ( V_73 & 0555 ) | V_150 ;
else if ( ! memcmp ( V_147 , L_9 , 5 ) )
V_13 -> V_109 . V_115 = ( V_73 & 0666 ) | V_151 ;
else
goto V_152;
break;
case 4 :
if ( ! memcmp ( V_147 , L_10 , 4 ) ) {
V_13 -> V_143 = ( V_73 & 0555 ) | V_150 ;
V_13 -> V_109 . V_115 = ( V_73 & 0666 ) | V_151 ;
} else {
goto V_152;
}
break;
case 3 :
if ( ! memcmp ( V_147 , L_11 , 3 ) ) {
V_13 -> V_109 . V_117 = F_75 ( F_76 () , V_73 ) ;
if ( ! F_77 ( V_13 -> V_109 . V_117 ) ) {
F_73 ( L_12 , V_147 , V_73 ) ;
return - V_46 ;
}
} else if ( ! memcmp ( V_147 , L_13 , 3 ) ) {
V_13 -> V_109 . V_119 = F_78 ( F_76 () , V_73 ) ;
if ( ! F_79 ( V_13 -> V_109 . V_119 ) ) {
F_73 ( L_12 , V_147 , V_73 ) ;
return - V_46 ;
}
} else {
goto V_152;
}
break;
default:
V_152:
F_73 ( L_14 , V_147 ) ;
return - V_46 ;
}
if ( ! V_149 )
break;
V_147 = V_149 + 1 ;
}
return 0 ;
}
static struct V_126 *
F_80 ( struct V_153 * V_154 , int V_50 ,
const char * V_155 , void * V_147 )
{
struct V_133 V_13 = {
. V_109 = {
. V_115 = V_151 | 0600 ,
. V_117 = V_156 ,
. V_119 = V_157 ,
} ,
. V_143 = V_150 | 0500 ,
} ;
struct V_126 * V_158 ;
int V_16 ;
void * V_159 ;
struct V_9 * V_10 ;
F_18 () ;
V_16 = F_72 ( & V_13 , V_147 ) ;
if ( F_10 ( V_16 < 0 ) )
return F_81 ( V_16 ) ;
V_10 = F_82 () ;
if ( F_10 ( ! V_10 ) )
return F_81 ( - V_68 ) ;
V_10 -> V_130 = V_13 . V_109 ;
V_10 -> V_155 = F_83 ( V_155 , V_67 ) ;
if ( F_10 ( ! V_10 -> V_155 ) ) {
F_84 ( V_10 ) ;
return F_81 ( - V_68 ) ;
}
V_159 = F_85 ( V_155 ) ;
if ( F_22 ( V_159 ) ) {
F_84 ( V_10 ) ;
return F_86 ( V_159 ) ;
}
V_10 -> V_37 = V_159 ;
V_13 . V_9 = V_10 ;
V_158 = F_87 ( V_154 , V_50 , & V_13 , F_70 ) ;
if ( F_22 ( V_158 ) && V_13 . V_9 ) {
F_88 ( V_13 . V_9 ) ;
F_84 ( V_13 . V_9 ) ;
}
return V_158 ;
}
static void
F_89 ( struct V_102 * V_103 )
{
F_18 () ;
F_90 ( V_103 ) ;
if ( V_103 -> V_128 ) {
F_88 ( V_103 -> V_128 ) ;
F_84 ( V_103 -> V_128 ) ;
}
}
static int F_91 ( void )
{
int V_16 ;
F_18 () ;
V_16 = F_92 ( & V_160 ) ;
if ( F_38 ( ! V_16 ) )
F_24 ( L_15 ) ;
else
F_73 ( L_16 , V_16 ) ;
return V_16 ;
}
static void F_93 ( void )
{
F_18 () ;
F_24 ( L_17 ) ;
F_94 ( & V_160 ) ;
}
static void F_95 ( struct V_9 * V_10 )
{
F_18 () ;
F_96 ( & V_10 -> V_161 ) ;
}
static void F_41 ( struct V_9 * V_10 )
{
F_18 () ;
F_96 ( & V_10 -> V_161 ) ;
F_96 ( & V_10 -> V_162 ) ;
}
static void F_84 ( struct V_9 * V_10 )
{
F_18 () ;
if ( F_10 ( F_97 ( & V_10 -> V_161 ) ) ) {
F_24 ( L_18 , V_163 ) ;
F_98 ( V_10 ) ;
F_99 ( F_100 ( & V_10 -> V_18 . V_21 ) ||
F_100 ( & V_10 -> V_12 . V_92 ) ) ;
F_33 ( V_10 -> V_155 ) ;
F_33 ( V_10 ) ;
}
}
static void F_43 ( struct V_9 * V_10 )
{
F_18 () ;
if ( F_97 ( & V_10 -> V_162 ) ) {
V_10 -> V_43 = V_47 ;
F_101 ( V_10 ) ;
}
F_84 ( V_10 ) ;
}
static struct V_9 * F_82 ( void )
{
struct V_9 * V_10 = F_51 ( sizeof *V_10 , V_67 ) ;
if ( F_10 ( ! V_10 ) )
return 0 ;
F_18 () ;
F_102 ( & V_10 -> V_161 , 1 ) ;
F_102 ( & V_10 -> V_162 , 0 ) ;
V_10 -> V_43 = V_44 ;
F_103 ( & V_10 -> V_40 ) ;
F_104 ( & V_10 -> V_91 ) ;
F_105 ( & V_10 -> V_18 . V_21 ) ;
F_106 ( & V_10 -> V_12 ) ;
V_10 -> V_18 . V_32 = 1 ;
return V_10 ;
}
static void F_98 ( struct V_9 * V_10 )
{
F_18 () ;
if ( F_107 ( V_49 , & V_10 -> V_50 ) )
F_108 ( V_10 ) ;
F_99 ( V_10 -> V_25 ) ;
if ( V_10 -> V_164 )
F_109 ( V_10 -> V_164 , V_10 -> V_165 ) ;
F_33 ( V_10 -> V_166 ) ;
F_33 ( V_10 -> V_167 ) ;
F_33 ( V_10 -> V_168 ) ;
}
static void F_101 ( struct V_9 * V_10 )
{
F_18 () ;
F_98 ( V_10 ) ;
V_10 -> V_164 = NULL ;
V_10 -> V_166 = NULL ;
V_10 -> V_167 = NULL ;
V_10 -> V_168 = NULL ;
V_10 -> V_169 = 0 ;
V_10 -> V_170 = 0 ;
V_10 -> V_171 = 0 ;
V_10 -> V_172 = 0 ;
V_10 -> V_173 = 0 ;
V_10 -> V_174 = 0 ;
V_10 -> V_165 = 0 ;
V_10 -> V_18 . V_63 = 0 ;
V_10 -> V_43 = V_44 ;
V_10 -> V_29 = V_30 ;
V_10 -> V_50 = 0 ;
}
static int F_110 ( struct V_9 * V_10 , struct V_175 * V_176 )
{
struct V_177 * * V_178 ;
int V_179 ;
F_18 () ;
if ( F_49 ( V_10 -> V_43 != V_48
|| F_111 ( V_180 , & V_10 -> V_50 ) ) )
return - V_55 ;
V_179 = F_112 ( V_176 , V_10 -> V_173 ) ;
if ( F_10 ( V_179 < 0 ) )
return V_179 ;
V_10 -> V_15 = F_113 ( V_176 -> V_25 -> V_26 , V_67 ) ;
if ( F_10 ( ! V_10 -> V_15 ) )
return - V_68 ;
V_10 -> V_15 -> F_47 = F_3 ;
V_10 -> V_15 -> V_11 = V_10 ;
V_178 = V_10 -> V_168 ;
for ( V_178 = V_10 -> V_168 ; * V_178 ; ++ V_178 ) {
struct V_181 * V_182 = ( * V_178 ) -> V_183 ;
int V_184 = V_179 ;
for (; V_182 -> V_185 ; ++ V_184 , ++ V_182 )
V_182 -> V_184 = V_184 ;
}
V_10 -> V_25 = V_176 -> V_25 ;
F_95 ( V_10 ) ;
return 0 ;
}
static void F_114 ( struct V_9 * V_10 )
{
F_18 () ;
if ( ! F_49 ( ! V_10 -> V_25 ) ) {
F_115 ( V_10 -> V_25 -> V_26 , V_10 -> V_15 ) ;
V_10 -> V_15 = NULL ;
V_10 -> V_25 = NULL ;
F_116 ( V_180 , & V_10 -> V_50 ) ;
F_84 ( V_10 ) ;
}
}
static int F_27 ( struct V_9 * V_10 )
{
struct V_87 * V_88 , * V_164 ;
unsigned V_59 , V_63 ;
F_18 () ;
V_63 = V_10 -> V_165 ;
V_164 = F_117 ( V_63 , sizeof( * V_164 ) , V_67 ) ;
if ( ! V_164 )
return - V_68 ;
V_88 = V_164 ;
for ( V_59 = 1 ; V_59 <= V_63 ; ++ V_59 , ++ V_88 ) {
V_88 -> V_10 = V_10 ;
F_103 ( & V_88 -> V_40 ) ;
F_105 ( & V_88 -> V_92 ) ;
sprintf ( V_164 -> V_125 , L_19 , V_59 ) ;
if ( ! F_10 ( F_66 ( V_10 -> V_103 , V_164 -> V_125 , V_88 ,
& V_186 ,
& V_88 -> V_126 ) ) ) {
F_109 ( V_164 , V_59 - 1 ) ;
return - V_68 ;
}
}
V_10 -> V_164 = V_164 ;
return 0 ;
}
static void F_109 ( struct V_87 * V_164 , unsigned V_63 )
{
struct V_87 * V_88 = V_164 ;
F_18 () ;
for (; V_63 ; -- V_63 , ++ V_88 ) {
F_99 ( F_118 ( & V_88 -> V_40 ) ||
F_100 ( & V_88 -> V_92 ) ) ;
if ( V_88 -> V_126 ) {
F_119 ( V_88 -> V_126 ) ;
F_68 ( V_88 -> V_126 ) ;
V_88 -> V_126 = NULL ;
}
}
F_33 ( V_164 ) ;
}
static int F_120 ( struct V_175 * V_176 ,
struct V_187 * V_188 ,
struct V_9 * V_10 )
{
struct V_1 * V_76 ;
int V_16 ;
F_18 () ;
V_76 = F_51 ( sizeof *V_76 , V_67 ) ;
if ( F_10 ( ! V_76 ) )
return - V_68 ;
V_76 -> V_4 . V_125 = L_20 ;
V_76 -> V_4 . V_183 = V_10 -> V_168 ;
V_76 -> V_4 . V_189 = V_190 ;
V_76 -> V_4 . V_191 = V_192 ;
V_76 -> V_4 . V_193 = V_194 ;
V_76 -> V_4 . V_195 = V_196 ;
V_76 -> V_4 . V_19 = V_197 ;
V_76 -> V_4 . V_198 = V_199 ;
V_76 -> V_4 . V_200 = V_201 ;
V_76 -> V_202 = V_188 ;
V_76 -> V_25 = V_176 -> V_25 ;
V_76 -> V_10 = V_10 ;
F_95 ( V_10 ) ;
V_16 = F_121 ( V_188 , & V_76 -> V_4 ) ;
if ( F_10 ( V_16 ) )
F_122 ( V_76 ) ;
return V_16 ;
}
static void F_122 ( struct V_1 * V_76 )
{
struct V_82 * V_6 = V_76 -> V_203 ;
unsigned V_63 = V_76 -> V_10 -> V_165 ;
unsigned long V_50 ;
F_18 () ;
F_123 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
do {
if ( V_6 -> V_6 && V_6 -> V_8 )
F_115 ( V_6 -> V_6 , V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
++ V_6 ;
} while ( -- V_63 );
F_124 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
F_84 ( V_76 -> V_10 ) ;
F_33 ( V_76 -> V_203 ) ;
F_33 ( V_76 ) ;
}
static void F_125 ( struct V_1 * V_76 )
{
struct V_82 * V_6 = V_76 -> V_203 ;
struct V_87 * V_88 = V_76 -> V_10 -> V_164 ;
unsigned V_63 = V_76 -> V_10 -> V_165 ;
unsigned long V_50 ;
F_123 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
do {
if ( F_38 ( V_6 -> V_6 ) )
F_126 ( V_6 -> V_6 ) ;
V_88 -> V_6 = NULL ;
++ V_6 ;
++ V_88 ;
} while ( -- V_63 );
F_124 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
}
static int F_127 ( struct V_1 * V_76 )
{
struct V_9 * V_10 = V_76 -> V_10 ;
struct V_82 * V_6 = V_76 -> V_203 ;
struct V_87 * V_88 = V_10 -> V_164 ;
unsigned V_63 = V_10 -> V_165 ;
unsigned long V_50 ;
int V_16 = 0 ;
F_123 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
do {
struct V_204 * V_205 ;
V_205 = V_6 -> V_206 [ V_6 -> V_206 [ 1 ] ? 1 : 0 ] ;
V_6 -> V_6 -> V_83 = V_6 ;
V_6 -> V_6 -> V_207 = V_205 ;
V_16 = F_128 ( V_6 -> V_6 ) ;
if ( F_38 ( ! V_16 ) ) {
V_88 -> V_6 = V_6 ;
V_88 -> V_93 = F_129 ( V_205 ) ;
V_88 -> V_94 = F_130 ( V_205 ) ;
} else {
break;
}
F_131 ( & V_88 -> V_92 ) ;
++ V_6 ;
++ V_88 ;
} while ( -- V_63 );
F_124 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
return V_16 ;
}
static int T_5 F_132 ( char * V_13 , unsigned V_14 ,
T_6 V_208 , void * V_209 )
{
struct V_210 * V_211 = ( void * ) V_13 ;
T_7 V_24 ;
int V_16 ;
F_18 () ;
if ( V_14 < 2 ) {
F_14 ( L_21 ) ;
return - V_46 ;
}
V_24 = V_211 -> V_212 ;
if ( V_14 < V_24 ) {
F_14 ( L_22 ) ;
return - V_46 ;
}
#define F_133 ( T_8 ) 1
#define F_134 ( T_8 ) (val)
#define F_135 ( T_8 ) ((val) & USB_ENDPOINT_NUMBER_MASK)
#define F_136 ( type , T_8 ) do { \
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
switch ( V_211 -> V_213 ) {
case V_214 :
case V_215 :
case V_216 :
case V_217 :
F_14 ( L_23 ,
V_211 -> V_213 ) ;
return - V_46 ;
case V_218 : {
struct V_219 * V_205 = ( void * ) V_211 ;
F_14 ( L_24 ) ;
if ( V_24 != sizeof *V_205 )
goto V_220;
F_136 ( V_221 , V_205 -> V_222 ) ;
if ( V_205 -> V_223 )
F_136 ( STRING , V_205 -> V_223 ) ;
}
break;
case V_224 : {
struct V_204 * V_205 = ( void * ) V_211 ;
F_14 ( L_25 ) ;
if ( V_24 != V_225 &&
V_24 != V_226 )
goto V_220;
F_136 ( V_227 , V_205 -> V_228 ) ;
}
break;
case V_229 :
F_14 ( L_26 ) ;
if ( V_24 != sizeof( struct V_230 ) )
goto V_220;
break;
case V_231 :
if ( V_24 != sizeof( struct V_232 ) )
goto V_220;
break;
case V_233 : {
struct V_234 * V_205 = ( void * ) V_211 ;
F_14 ( L_27 ) ;
if ( V_24 != sizeof *V_205 )
goto V_220;
if ( V_205 -> V_235 )
F_136 ( STRING , V_205 -> V_235 ) ;
}
break;
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
F_14 ( L_28 , V_211 -> V_213 ) ;
return - V_46 ;
default:
F_14 ( L_29 , V_211 -> V_213 ) ;
return - V_46 ;
V_220:
F_14 ( L_30 ,
V_211 -> V_212 , V_211 -> V_213 ) ;
return - V_46 ;
}
#undef F_136
#undef V_241
#undef F_133
#undef F_134
#undef F_135
return V_24 ;
}
static int T_5 F_137 ( unsigned V_63 , char * V_13 , unsigned V_14 ,
T_6 V_208 , void * V_209 )
{
const unsigned V_242 = V_14 ;
unsigned long V_101 = 0 ;
F_18 () ;
for (; ; ) {
int V_16 ;
if ( V_101 == V_63 )
V_13 = NULL ;
V_16 = V_208 ( V_243 , ( T_7 * ) V_101 , ( void * ) V_13 , V_209 ) ;
if ( F_10 ( V_16 < 0 ) ) {
F_16 ( L_31 ,
V_101 , V_16 ) ;
return V_16 ;
}
if ( ! V_13 )
return V_242 - V_14 ;
V_16 = F_132 ( V_13 , V_14 , V_208 , V_209 ) ;
if ( F_10 ( V_16 < 0 ) ) {
F_16 ( L_32 , V_163 , V_16 ) ;
return V_16 ;
}
V_14 -= V_16 ;
V_13 += V_16 ;
++ V_101 ;
}
}
static int F_138 ( enum V_244 type ,
T_7 * V_245 , struct V_210 * V_207 ,
void * V_209 )
{
struct V_9 * V_10 = V_209 ;
F_18 () ;
switch ( type ) {
case V_243 :
break;
case V_246 :
if ( * V_245 >= V_10 -> V_174 )
V_10 -> V_174 = * V_245 + 1 ;
break;
case V_247 :
if ( * V_245 > V_10 -> V_173 )
V_10 -> V_173 = * V_245 ;
break;
case V_248 :
if ( ( * V_245 & V_249 ) > V_10 -> V_165 )
V_10 -> V_165 = ( * V_245 & V_249 ) ;
break;
}
return 0 ;
}
static int F_25 ( struct V_9 * V_10 ,
char * const V_131 , T_1 V_14 )
{
unsigned V_250 , V_251 ;
int V_252 , V_16 = - V_46 ;
char * V_13 = V_131 ;
F_18 () ;
if ( F_10 ( F_139 ( V_13 ) != V_253 ||
F_139 ( V_13 + 4 ) != V_14 ) )
goto error;
V_250 = F_139 ( V_13 + 8 ) ;
V_251 = F_139 ( V_13 + 12 ) ;
if ( ! V_250 && ! V_251 )
goto V_254;
V_13 += 16 ;
V_14 -= 16 ;
if ( F_38 ( V_250 ) ) {
V_252 = F_137 ( V_250 , V_13 , V_14 ,
F_138 , V_10 ) ;
if ( F_10 ( V_252 < 0 ) ) {
V_16 = V_252 ;
goto error;
}
V_13 += V_252 ;
V_14 -= V_252 ;
} else {
V_252 = 0 ;
}
if ( F_38 ( V_251 ) ) {
V_16 = F_137 ( V_251 , V_13 , V_14 ,
F_138 , V_10 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
} else {
V_16 = 0 ;
}
if ( F_10 ( V_14 != V_16 ) )
goto V_254;
V_10 -> V_170 = V_252 ;
V_10 -> V_169 = V_252 + V_16 ;
V_10 -> V_166 = V_131 ;
V_10 -> V_171 = V_250 ;
V_10 -> V_172 = V_251 ;
return 0 ;
V_254:
V_16 = - V_46 ;
error:
F_33 ( V_131 ) ;
return V_16 ;
}
static int F_26 ( struct V_9 * V_10 ,
char * const V_131 , T_1 V_14 )
{
T_9 V_255 , V_256 , V_257 ;
struct V_177 * * V_168 , * V_154 ;
struct V_181 * V_183 , * V_185 ;
const char * V_13 = V_131 ;
F_18 () ;
if ( F_10 ( F_139 ( V_13 ) != V_258 ||
F_139 ( V_13 + 4 ) != V_14 ) )
goto error;
V_255 = F_139 ( V_13 + 8 ) ;
V_257 = F_139 ( V_13 + 12 ) ;
if ( F_10 ( ! V_255 != ! V_257 ) )
goto error;
V_256 = V_10 -> V_173 ;
if ( F_10 ( V_255 < V_256 ) )
goto error;
if ( ! V_256 ) {
F_33 ( V_131 ) ;
return 0 ;
}
{
struct {
struct V_177 * V_168 [ V_257 + 1 ] ;
struct V_177 V_259 [ V_257 ] ;
struct V_181 V_183 [ V_257 * ( V_256 + 1 ) ] ;
} * V_260 ;
unsigned V_59 = 0 ;
V_260 = F_39 ( sizeof *V_260 , V_67 ) ;
if ( F_10 ( ! V_260 ) ) {
F_33 ( V_131 ) ;
return - V_68 ;
}
V_168 = V_260 -> V_168 ;
V_154 = V_260 -> V_259 ;
V_59 = V_257 ;
do {
* V_168 ++ = V_154 ++ ;
} while ( -- V_59 );
* V_168 = NULL ;
V_168 = V_260 -> V_168 ;
V_154 = V_260 -> V_259 ;
V_185 = V_260 -> V_183 ;
V_183 = V_185 ;
}
V_13 += 16 ;
V_14 -= 16 ;
do {
unsigned V_261 = V_256 ;
if ( F_10 ( V_14 < 3 ) )
goto V_262;
V_154 -> V_263 = F_140 ( V_13 ) ;
V_154 -> V_183 = V_185 ;
++ V_154 ;
V_13 += 2 ;
V_14 -= 2 ;
do {
T_1 V_24 = F_141 ( V_13 , V_14 ) ;
if ( F_10 ( V_24 == V_14 ) )
goto V_262;
if ( F_38 ( V_261 ) ) {
V_185 -> V_185 = V_13 ;
-- V_261 ;
++ V_185 ;
}
V_13 += V_24 + 1 ;
V_14 -= V_24 + 1 ;
} while ( -- V_255 );
V_185 -> V_184 = 0 ;
V_185 -> V_185 = NULL ;
++ V_185 ;
} while ( -- V_257 );
if ( F_10 ( V_14 ) )
goto V_262;
V_10 -> V_168 = V_168 ;
V_10 -> V_167 = V_131 ;
return 0 ;
V_262:
F_33 ( V_168 ) ;
error:
F_33 ( V_131 ) ;
return - V_46 ;
}
static void F_142 ( struct V_9 * V_10 ,
enum V_264 type )
{
enum V_264 V_265 , V_266 = type ;
int V_267 = 0 ;
if ( V_10 -> V_29 == V_52 )
V_10 -> V_29 = V_38 ;
switch ( type ) {
case V_268 :
V_266 = V_269 ;
case V_269 :
case V_61 :
V_265 = type ;
break;
case V_270 :
case V_271 :
case V_272 :
case V_273 :
V_265 = V_269 ;
V_266 = V_268 ;
V_267 = 1 ;
break;
default:
F_143 () ;
}
{
T_7 * V_18 = V_10 -> V_18 . V_60 , * V_274 = V_18 ;
unsigned V_56 = V_10 -> V_18 . V_63 ;
for (; V_56 ; -- V_56 , ++ V_18 )
if ( ( * V_18 == V_265 || * V_18 == V_266 ) == V_267 )
* V_274 ++ = * V_18 ;
else
F_14 ( L_33 , * V_18 ) ;
V_10 -> V_18 . V_63 = V_274 - V_10 -> V_18 . V_60 ;
}
F_14 ( L_34 , type ) ;
V_10 -> V_18 . V_60 [ V_10 -> V_18 . V_63 ++ ] = type ;
F_144 ( & V_10 -> V_18 . V_21 ) ;
}
static void F_145 ( struct V_9 * V_10 ,
enum V_264 type )
{
unsigned long V_50 ;
F_123 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
F_142 ( V_10 , type ) ;
F_124 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
}
static int F_146 ( enum V_244 type , T_7 * V_245 ,
struct V_210 * V_207 ,
void * V_209 )
{
struct V_204 * V_205 = ( void * ) V_207 ;
struct V_1 * V_76 = V_209 ;
struct V_82 * V_82 ;
const int V_275 = V_76 -> V_4 . V_276 != NULL ;
unsigned V_277 ;
if ( type != V_243 )
return 0 ;
if ( V_275 )
V_76 -> V_4 . V_276 [ ( long ) V_245 ] = V_207 ;
else
V_76 -> V_4 . V_278 [ ( long ) V_245 ] = V_207 ;
if ( ! V_207 || V_207 -> V_213 != V_224 )
return 0 ;
V_277 = ( V_205 -> V_228 & V_249 ) - 1 ;
V_82 = V_76 -> V_203 + V_277 ;
if ( F_10 ( V_82 -> V_206 [ V_275 ] ) ) {
F_14 ( L_35 ,
V_275 ? L_36 : L_37 ,
V_205 -> V_228 & V_249 ) ;
return - V_46 ;
}
V_82 -> V_206 [ V_275 ] = V_205 ;
F_147 ( L_38 , V_205 , V_205 -> V_212 ) ;
if ( V_82 -> V_6 ) {
V_205 -> V_228 = V_82 -> V_206 [ 0 ] -> V_228 ;
if ( ! V_205 -> V_279 )
V_205 -> V_279 = V_82 -> V_206 [ 0 ] -> V_279 ;
} else {
struct V_7 * V_8 ;
struct V_5 * V_6 ;
F_14 ( L_39 ) ;
V_6 = F_148 ( V_76 -> V_25 , V_205 ) ;
if ( F_10 ( ! V_6 ) )
return - V_280 ;
V_6 -> V_83 = V_76 -> V_203 + V_277 ;
V_8 = F_113 ( V_6 , V_67 ) ;
if ( F_10 ( ! V_8 ) )
return - V_68 ;
V_82 -> V_6 = V_6 ;
V_82 -> V_8 = V_8 ;
V_76 -> V_281 [ V_205 -> V_228 &
V_249 ] = V_277 + 1 ;
}
F_147 ( L_40 , V_205 , V_205 -> V_212 ) ;
return 0 ;
}
static int F_149 ( enum V_244 type , T_7 * V_245 ,
struct V_210 * V_207 ,
void * V_209 )
{
struct V_1 * V_76 = V_209 ;
unsigned V_277 ;
T_7 V_282 ;
switch ( type ) {
default:
case V_243 :
return 0 ;
case V_246 :
V_277 = * V_245 ;
if ( V_76 -> V_283 [ V_277 ] < 0 ) {
int V_184 = F_150 ( V_76 -> V_202 , & V_76 -> V_4 ) ;
if ( F_10 ( V_184 < 0 ) )
return V_184 ;
V_76 -> V_283 [ V_277 ] = V_184 ;
}
V_282 = V_76 -> V_283 [ V_277 ] ;
break;
case V_247 :
V_282 = V_76 -> V_10 -> V_168 [ 0 ] -> V_183 [ * V_245 - 1 ] . V_184 ;
break;
case V_248 :
if ( V_207 -> V_213 == V_224 )
return 0 ;
V_277 = ( * V_245 & V_249 ) - 1 ;
if ( F_10 ( ! V_76 -> V_203 [ V_277 ] . V_6 ) )
return - V_46 ;
{
struct V_204 * * V_206 ;
V_206 = V_76 -> V_203 [ V_277 ] . V_206 ;
V_282 = V_206 [ V_206 [ 0 ] ? 0 : 1 ] -> V_228 ;
}
break;
}
F_14 ( L_41 , * V_245 , V_282 ) ;
* V_245 = V_282 ;
return 0 ;
}
static int V_190 ( struct V_187 * V_188 ,
struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
const int V_284 = ! ! V_76 -> V_10 -> V_171 ;
const int V_285 = F_151 ( V_76 -> V_25 ) &&
V_76 -> V_10 -> V_172 ;
int V_16 ;
struct {
struct V_82 V_203 [ V_10 -> V_165 ] ;
struct V_210
* V_286 [ V_284 ? V_10 -> V_171 + 1 : 0 ] ;
struct V_210
* V_287 [ V_285 ? V_10 -> V_172 + 1 : 0 ] ;
short V_288 [ V_10 -> V_174 ] ;
char V_166 [ V_285 ? V_10 -> V_169
: V_10 -> V_170 ] ;
} * V_13 ;
F_18 () ;
if ( F_10 ( ! ( V_284 | V_285 ) ) )
return - V_280 ;
V_13 = F_39 ( sizeof *V_13 , V_67 ) ;
if ( F_10 ( ! V_13 ) )
return - V_68 ;
memset ( V_13 -> V_203 , 0 , sizeof V_13 -> V_203 ) ;
memcpy ( V_13 -> V_166 , V_10 -> V_166 + 16 , sizeof V_13 -> V_166 ) ;
memset ( V_13 -> V_288 , 0xff , sizeof V_13 -> V_288 ) ;
for ( V_16 = V_10 -> V_165 ; V_16 ; -- V_16 )
V_13 -> V_203 [ V_16 ] . V_101 = - 1 ;
V_76 -> V_203 = V_13 -> V_203 ;
V_76 -> V_283 = V_13 -> V_288 ;
if ( F_38 ( V_284 ) ) {
V_76 -> V_4 . V_278 = V_13 -> V_286 ;
V_16 = F_137 ( V_10 -> V_171 ,
V_13 -> V_166 ,
sizeof V_13 -> V_166 ,
F_146 , V_76 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
} else {
V_16 = 0 ;
}
if ( F_38 ( V_285 ) ) {
V_76 -> V_4 . V_276 = V_13 -> V_287 ;
V_16 = F_137 ( V_10 -> V_172 ,
V_13 -> V_166 + V_16 ,
( sizeof V_13 -> V_166 ) - V_16 ,
F_146 , V_76 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
}
V_16 = F_137 ( V_10 -> V_171 +
( V_285 ? V_10 -> V_172 : 0 ) ,
V_13 -> V_166 , sizeof V_13 -> V_166 ,
F_149 , V_76 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
F_145 ( V_10 , V_270 ) ;
return 0 ;
error:
return V_16 ;
}
static void V_192 ( struct V_187 * V_188 ,
struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
F_18 () ;
if ( V_10 -> V_76 == V_76 ) {
F_125 ( V_76 ) ;
V_10 -> V_76 = NULL ;
}
F_145 ( V_10 , V_271 ) ;
F_122 ( V_76 ) ;
}
static int V_194 ( struct V_2 * V_3 ,
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
F_125 ( V_10 -> V_76 ) ;
if ( V_10 -> V_43 != V_48 )
return - V_77 ;
if ( V_290 == ( unsigned ) - 1 ) {
V_10 -> V_76 = NULL ;
F_145 ( V_10 , V_272 ) ;
return 0 ;
}
V_10 -> V_76 = V_76 ;
V_16 = F_127 ( V_76 ) ;
if ( F_38 ( V_16 >= 0 ) )
F_145 ( V_10 , V_273 ) ;
return V_16 ;
}
static void V_196 ( struct V_2 * V_3 )
{
V_194 ( V_3 , 0 , ( unsigned ) - 1 ) ;
}
static int V_197 ( struct V_2 * V_3 ,
const struct V_292 * V_293 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
unsigned long V_50 ;
int V_16 ;
F_18 () ;
F_14 ( L_42 , V_293 -> V_53 ) ;
F_14 ( L_43 , V_293 -> V_294 ) ;
F_14 ( L_44 , F_6 ( V_293 -> V_295 ) ) ;
F_14 ( L_45 , F_6 ( V_293 -> V_296 ) ) ;
F_14 ( L_46 , F_6 ( V_293 -> V_20 ) ) ;
if ( V_10 -> V_43 != V_48 )
return - V_77 ;
switch ( V_293 -> V_53 & V_297 ) {
case V_298 :
V_16 = F_45 ( V_76 , F_6 ( V_293 -> V_296 ) ) ;
if ( F_10 ( V_16 < 0 ) )
return V_16 ;
break;
case V_299 :
V_16 = F_152 ( V_76 , F_6 ( V_293 -> V_296 ) ) ;
if ( F_10 ( V_16 < 0 ) )
return V_16 ;
break;
default:
return - V_300 ;
}
F_123 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
V_10 -> V_18 . V_19 = * V_293 ;
V_10 -> V_18 . V_19 . V_296 = F_153 ( V_16 ) ;
F_142 ( V_10 , V_61 ) ;
F_124 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
return 0 ;
}
static void V_199 ( struct V_2 * V_3 )
{
F_18 () ;
F_145 ( F_1 ( V_3 ) -> V_10 , V_269 ) ;
}
static void V_201 ( struct V_2 * V_3 )
{
F_18 () ;
F_145 ( F_1 ( V_3 ) -> V_10 , V_268 ) ;
}
static int F_152 ( struct V_1 * V_76 , T_7 V_101 )
{
V_101 = V_76 -> V_281 [ V_101 & V_249 ] ;
return V_101 ? V_101 : - V_301 ;
}
static int F_45 ( struct V_1 * V_76 , T_7 V_291 )
{
short * V_302 = V_76 -> V_283 ;
unsigned V_63 = V_76 -> V_10 -> V_174 ;
for (; V_63 ; -- V_63 , ++ V_302 ) {
if ( * V_302 >= 0 && * V_302 == V_291 )
return V_302 - V_76 -> V_283 ;
}
return - V_301 ;
}
static int F_20 ( struct V_40 * V_40 , unsigned V_303 )
{
return V_303
? F_38 ( F_154 ( V_40 ) ) ? 0 : - V_66
: F_155 ( V_40 ) ;
}
static char * F_21 ( const char T_3 * V_23 , T_1 V_14 )
{
char * V_13 ;
if ( F_10 ( ! V_14 ) )
return NULL ;
V_13 = F_39 ( V_14 , V_67 ) ;
if ( F_10 ( ! V_13 ) )
return F_81 ( - V_68 ) ;
if ( F_10 ( F_52 ( V_13 , V_23 , V_14 ) ) ) {
F_33 ( V_13 ) ;
return F_81 ( - V_64 ) ;
}
F_14 ( L_47 ) ;
F_147 ( L_48 , V_13 , V_14 ) ;
return V_13 ;
}
