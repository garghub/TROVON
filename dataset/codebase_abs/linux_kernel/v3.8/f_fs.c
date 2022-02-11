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
char * V_150 , * V_151 , * V_152 ;
unsigned long V_73 ;
V_152 = strchr ( V_149 , ',' ) ;
if ( V_152 )
* V_152 = 0 ;
V_151 = strchr ( V_149 , '=' ) ;
if ( F_10 ( ! V_151 ) ) {
F_75 ( L_6 , V_149 ) ;
return - V_46 ;
}
* V_151 = 0 ;
V_73 = F_76 ( V_151 + 1 , & V_150 , 0 ) ;
if ( F_10 ( * V_150 != ',' && * V_150 != 0 ) ) {
F_75 ( L_7 , V_149 , V_151 + 1 ) ;
return - V_46 ;
}
switch ( V_151 - V_149 ) {
case 5 :
if ( ! memcmp ( V_149 , L_8 , 5 ) )
V_13 -> V_145 = ( V_73 & 0555 ) | V_153 ;
else if ( ! memcmp ( V_149 , L_9 , 5 ) )
V_13 -> V_109 . V_115 = ( V_73 & 0666 ) | V_154 ;
else
goto V_155;
break;
case 4 :
if ( ! memcmp ( V_149 , L_10 , 4 ) ) {
V_13 -> V_145 = ( V_73 & 0555 ) | V_153 ;
V_13 -> V_109 . V_115 = ( V_73 & 0666 ) | V_154 ;
} else {
goto V_155;
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
goto V_155;
}
break;
default:
V_155:
F_75 ( L_14 , V_149 ) ;
return - V_46 ;
}
if ( ! V_152 )
break;
V_149 = V_152 + 1 ;
}
return 0 ;
}
static struct V_126 *
F_82 ( struct V_156 * V_157 , int V_50 ,
const char * V_135 , void * V_149 )
{
struct V_133 V_13 = {
. V_109 = {
. V_115 = V_154 | 0600 ,
. V_117 = V_158 ,
. V_119 = V_159 ,
} ,
. V_145 = V_153 | 0500 ,
} ;
struct V_126 * V_160 ;
int V_16 ;
void * V_161 ;
F_18 () ;
V_16 = F_74 ( & V_13 , V_149 ) ;
if ( F_10 ( V_16 < 0 ) )
return F_83 ( V_16 ) ;
V_161 = F_84 ( V_135 ) ;
if ( F_22 ( V_161 ) )
return V_161 ;
V_13 . V_135 = V_135 ;
V_13 . V_37 = V_161 ;
V_160 = F_85 ( V_157 , V_50 , & V_13 , F_70 ) ;
if ( F_22 ( V_160 ) )
F_86 ( V_13 . V_9 ) ;
return V_160 ;
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
V_16 = F_91 ( & V_162 ) ;
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
F_93 ( & V_162 ) ;
}
static void F_94 ( struct V_9 * V_10 )
{
F_18 () ;
F_95 ( & V_10 -> V_163 ) ;
}
static void F_41 ( struct V_9 * V_10 )
{
F_18 () ;
F_95 ( & V_10 -> V_163 ) ;
F_95 ( & V_10 -> V_164 ) ;
}
static void F_89 ( struct V_9 * V_10 )
{
F_18 () ;
if ( F_10 ( F_96 ( & V_10 -> V_163 ) ) ) {
F_24 ( L_18 , V_165 ) ;
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
if ( F_96 ( & V_10 -> V_164 ) ) {
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
F_101 ( & V_10 -> V_163 , 1 ) ;
F_101 ( & V_10 -> V_164 , 0 ) ;
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
if ( V_10 -> V_166 )
F_108 ( V_10 -> V_166 , V_10 -> V_167 ) ;
F_33 ( V_10 -> V_168 ) ;
F_33 ( V_10 -> V_169 ) ;
F_33 ( V_10 -> V_170 ) ;
}
static void F_100 ( struct V_9 * V_10 )
{
F_18 () ;
F_97 ( V_10 ) ;
V_10 -> V_166 = NULL ;
V_10 -> V_168 = NULL ;
V_10 -> V_169 = NULL ;
V_10 -> V_170 = NULL ;
V_10 -> V_171 = 0 ;
V_10 -> V_172 = 0 ;
V_10 -> V_173 = 0 ;
V_10 -> V_174 = 0 ;
V_10 -> V_175 = 0 ;
V_10 -> V_176 = 0 ;
V_10 -> V_167 = 0 ;
V_10 -> V_18 . V_63 = 0 ;
V_10 -> V_43 = V_44 ;
V_10 -> V_29 = V_30 ;
V_10 -> V_50 = 0 ;
}
static int F_109 ( struct V_9 * V_10 , struct V_177 * V_178 )
{
struct V_179 * * V_180 ;
int V_181 ;
F_18 () ;
if ( F_49 ( V_10 -> V_43 != V_48
|| F_110 ( V_182 , & V_10 -> V_50 ) ) )
return - V_55 ;
V_181 = F_111 ( V_178 , V_10 -> V_175 ) ;
if ( F_10 ( V_181 < 0 ) )
return V_181 ;
V_10 -> V_15 = F_112 ( V_178 -> V_25 -> V_26 , V_67 ) ;
if ( F_10 ( ! V_10 -> V_15 ) )
return - V_68 ;
V_10 -> V_15 -> F_47 = F_3 ;
V_10 -> V_15 -> V_11 = V_10 ;
V_180 = V_10 -> V_170 ;
for ( V_180 = V_10 -> V_170 ; * V_180 ; ++ V_180 ) {
struct V_183 * V_184 = ( * V_180 ) -> V_185 ;
int V_186 = V_181 ;
for (; V_184 -> V_187 ; ++ V_186 , ++ V_184 )
V_184 -> V_186 = V_186 ;
}
V_10 -> V_25 = V_178 -> V_25 ;
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
F_115 ( V_182 , & V_10 -> V_50 ) ;
}
}
static int F_27 ( struct V_9 * V_10 )
{
struct V_87 * V_88 , * V_166 ;
unsigned V_59 , V_63 ;
F_18 () ;
V_63 = V_10 -> V_167 ;
V_166 = F_116 ( V_63 , sizeof( * V_166 ) , V_67 ) ;
if ( ! V_166 )
return - V_68 ;
V_88 = V_166 ;
for ( V_59 = 1 ; V_59 <= V_63 ; ++ V_59 , ++ V_88 ) {
V_88 -> V_10 = V_10 ;
F_102 ( & V_88 -> V_40 ) ;
F_104 ( & V_88 -> V_92 ) ;
sprintf ( V_166 -> V_125 , L_19 , V_59 ) ;
if ( ! F_10 ( F_66 ( V_10 -> V_103 , V_166 -> V_125 , V_88 ,
& V_188 ,
& V_88 -> V_126 ) ) ) {
F_108 ( V_166 , V_59 - 1 ) ;
return - V_68 ;
}
}
V_10 -> V_166 = V_166 ;
return 0 ;
}
static void F_108 ( struct V_87 * V_166 , unsigned V_63 )
{
struct V_87 * V_88 = V_166 ;
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
F_33 ( V_166 ) ;
}
static int F_119 ( struct V_177 * V_178 ,
struct V_189 * V_190 ,
struct V_9 * V_10 )
{
struct V_1 * V_76 ;
int V_16 ;
F_18 () ;
V_76 = F_51 ( sizeof *V_76 , V_67 ) ;
if ( F_10 ( ! V_76 ) )
return - V_68 ;
V_76 -> V_4 . V_125 = L_20 ;
V_76 -> V_4 . V_185 = V_10 -> V_170 ;
V_76 -> V_4 . V_191 = V_192 ;
V_76 -> V_4 . V_193 = V_194 ;
V_76 -> V_4 . V_195 = V_196 ;
V_76 -> V_4 . V_197 = V_198 ;
V_76 -> V_4 . V_19 = V_199 ;
V_76 -> V_4 . V_200 = V_201 ;
V_76 -> V_4 . V_202 = V_203 ;
V_76 -> V_204 = V_190 ;
V_76 -> V_25 = V_178 -> V_25 ;
V_76 -> V_10 = V_10 ;
F_94 ( V_10 ) ;
V_16 = F_120 ( V_190 , & V_76 -> V_4 ) ;
if ( F_10 ( V_16 ) )
F_121 ( V_76 ) ;
return V_16 ;
}
static void F_121 ( struct V_1 * V_76 )
{
struct V_82 * V_6 = V_76 -> V_205 ;
unsigned V_63 = V_76 -> V_10 -> V_167 ;
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
F_33 ( V_76 -> V_205 ) ;
F_33 ( V_76 ) ;
}
static void F_124 ( struct V_1 * V_76 )
{
struct V_82 * V_6 = V_76 -> V_205 ;
struct V_87 * V_88 = V_76 -> V_10 -> V_166 ;
unsigned V_63 = V_76 -> V_10 -> V_167 ;
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
struct V_82 * V_6 = V_76 -> V_205 ;
struct V_87 * V_88 = V_10 -> V_166 ;
unsigned V_63 = V_10 -> V_167 ;
unsigned long V_50 ;
int V_16 = 0 ;
F_122 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
do {
struct V_206 * V_207 ;
V_207 = V_6 -> V_208 [ V_6 -> V_208 [ 1 ] ? 1 : 0 ] ;
V_6 -> V_6 -> V_83 = V_6 ;
V_6 -> V_6 -> V_209 = V_207 ;
V_16 = F_127 ( V_6 -> V_6 ) ;
if ( F_38 ( ! V_16 ) ) {
V_88 -> V_6 = V_6 ;
V_88 -> V_93 = F_128 ( V_207 ) ;
V_88 -> V_94 = F_129 ( V_207 ) ;
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
T_6 V_210 , void * V_211 )
{
struct V_212 * V_213 = ( void * ) V_13 ;
T_7 V_24 ;
int V_16 ;
F_18 () ;
if ( V_14 < 2 ) {
F_14 ( L_21 ) ;
return - V_46 ;
}
V_24 = V_213 -> V_214 ;
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
switch ( V_213 -> V_215 ) {
case V_216 :
case V_217 :
case V_218 :
case V_219 :
F_14 ( L_23 ,
V_213 -> V_215 ) ;
return - V_46 ;
case V_220 : {
struct V_221 * V_207 = ( void * ) V_213 ;
F_14 ( L_24 ) ;
if ( V_24 != sizeof *V_207 )
goto V_222;
F_135 ( V_223 , V_207 -> V_224 ) ;
if ( V_207 -> V_225 )
F_135 ( STRING , V_207 -> V_225 ) ;
}
break;
case V_226 : {
struct V_206 * V_207 = ( void * ) V_213 ;
F_14 ( L_25 ) ;
if ( V_24 != V_227 &&
V_24 != V_228 )
goto V_222;
F_135 ( V_229 , V_207 -> V_230 ) ;
}
break;
case V_231 :
F_14 ( L_26 ) ;
if ( V_24 != sizeof( struct V_232 ) )
goto V_222;
break;
case V_233 :
if ( V_24 != sizeof( struct V_234 ) )
goto V_222;
break;
case V_235 : {
struct V_236 * V_207 = ( void * ) V_213 ;
F_14 ( L_27 ) ;
if ( V_24 != sizeof *V_207 )
goto V_222;
if ( V_207 -> V_237 )
F_135 ( STRING , V_207 -> V_237 ) ;
}
break;
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
F_14 ( L_28 , V_213 -> V_215 ) ;
return - V_46 ;
default:
F_14 ( L_29 , V_213 -> V_215 ) ;
return - V_46 ;
V_222:
F_14 ( L_30 ,
V_213 -> V_214 , V_213 -> V_215 ) ;
return - V_46 ;
}
#undef F_135
#undef V_243
#undef F_132
#undef F_133
#undef F_134
return V_24 ;
}
static int T_5 F_136 ( unsigned V_63 , char * V_13 , unsigned V_14 ,
T_6 V_210 , void * V_211 )
{
const unsigned V_244 = V_14 ;
unsigned long V_101 = 0 ;
F_18 () ;
for (; ; ) {
int V_16 ;
if ( V_101 == V_63 )
V_13 = NULL ;
V_16 = V_210 ( V_245 , ( T_7 * ) V_101 , ( void * ) V_13 , V_211 ) ;
if ( F_10 ( V_16 < 0 ) ) {
F_16 ( L_31 ,
V_101 , V_16 ) ;
return V_16 ;
}
if ( ! V_13 )
return V_244 - V_14 ;
V_16 = F_131 ( V_13 , V_14 , V_210 , V_211 ) ;
if ( F_10 ( V_16 < 0 ) ) {
F_16 ( L_32 , V_165 , V_16 ) ;
return V_16 ;
}
V_14 -= V_16 ;
V_13 += V_16 ;
++ V_101 ;
}
}
static int F_137 ( enum V_246 type ,
T_7 * V_247 , struct V_212 * V_209 ,
void * V_211 )
{
struct V_9 * V_10 = V_211 ;
F_18 () ;
switch ( type ) {
case V_245 :
break;
case V_248 :
if ( * V_247 >= V_10 -> V_176 )
V_10 -> V_176 = * V_247 + 1 ;
break;
case V_249 :
if ( * V_247 > V_10 -> V_175 )
V_10 -> V_175 = * V_247 ;
break;
case V_250 :
if ( ( * V_247 & V_251 ) > V_10 -> V_167 )
V_10 -> V_167 = ( * V_247 & V_251 ) ;
break;
}
return 0 ;
}
static int F_25 ( struct V_9 * V_10 ,
char * const V_131 , T_1 V_14 )
{
unsigned V_252 , V_253 ;
int V_254 , V_16 = - V_46 ;
char * V_13 = V_131 ;
F_18 () ;
if ( F_10 ( F_138 ( V_13 ) != V_255 ||
F_138 ( V_13 + 4 ) != V_14 ) )
goto error;
V_252 = F_138 ( V_13 + 8 ) ;
V_253 = F_138 ( V_13 + 12 ) ;
if ( ! V_252 && ! V_253 )
goto V_256;
V_13 += 16 ;
V_14 -= 16 ;
if ( F_38 ( V_252 ) ) {
V_254 = F_136 ( V_252 , V_13 , V_14 ,
F_137 , V_10 ) ;
if ( F_10 ( V_254 < 0 ) ) {
V_16 = V_254 ;
goto error;
}
V_13 += V_254 ;
V_14 -= V_254 ;
} else {
V_254 = 0 ;
}
if ( F_38 ( V_253 ) ) {
V_16 = F_136 ( V_253 , V_13 , V_14 ,
F_137 , V_10 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
} else {
V_16 = 0 ;
}
if ( F_10 ( V_14 != V_16 ) )
goto V_256;
V_10 -> V_172 = V_254 ;
V_10 -> V_171 = V_254 + V_16 ;
V_10 -> V_168 = V_131 ;
V_10 -> V_173 = V_252 ;
V_10 -> V_174 = V_253 ;
return 0 ;
V_256:
V_16 = - V_46 ;
error:
F_33 ( V_131 ) ;
return V_16 ;
}
static int F_26 ( struct V_9 * V_10 ,
char * const V_131 , T_1 V_14 )
{
T_9 V_257 , V_258 , V_259 ;
struct V_179 * * V_170 , * V_157 ;
struct V_183 * V_185 , * V_187 ;
const char * V_13 = V_131 ;
F_18 () ;
if ( F_10 ( F_138 ( V_13 ) != V_260 ||
F_138 ( V_13 + 4 ) != V_14 ) )
goto error;
V_257 = F_138 ( V_13 + 8 ) ;
V_259 = F_138 ( V_13 + 12 ) ;
if ( F_10 ( ! V_257 != ! V_259 ) )
goto error;
V_258 = V_10 -> V_175 ;
if ( F_10 ( V_257 < V_258 ) )
goto error;
if ( ! V_258 ) {
F_33 ( V_131 ) ;
return 0 ;
}
{
struct {
struct V_179 * V_170 [ V_259 + 1 ] ;
struct V_179 V_261 [ V_259 ] ;
struct V_183 V_185 [ V_259 * ( V_258 + 1 ) ] ;
} * V_262 ;
unsigned V_59 = 0 ;
V_262 = F_39 ( sizeof *V_262 , V_67 ) ;
if ( F_10 ( ! V_262 ) ) {
F_33 ( V_131 ) ;
return - V_68 ;
}
V_170 = V_262 -> V_170 ;
V_157 = V_262 -> V_261 ;
V_59 = V_259 ;
do {
* V_170 ++ = V_157 ++ ;
} while ( -- V_59 );
* V_170 = NULL ;
V_170 = V_262 -> V_170 ;
V_157 = V_262 -> V_261 ;
V_187 = V_262 -> V_185 ;
V_185 = V_187 ;
}
V_13 += 16 ;
V_14 -= 16 ;
do {
unsigned V_263 = V_258 ;
if ( F_10 ( V_14 < 3 ) )
goto V_264;
V_157 -> V_265 = F_139 ( V_13 ) ;
V_157 -> V_185 = V_187 ;
++ V_157 ;
V_13 += 2 ;
V_14 -= 2 ;
do {
T_1 V_24 = F_140 ( V_13 , V_14 ) ;
if ( F_10 ( V_24 == V_14 ) )
goto V_264;
if ( F_38 ( V_263 ) ) {
V_187 -> V_187 = V_13 ;
-- V_263 ;
++ V_187 ;
}
V_13 += V_24 + 1 ;
V_14 -= V_24 + 1 ;
} while ( -- V_257 );
V_187 -> V_186 = 0 ;
V_187 -> V_187 = NULL ;
++ V_187 ;
} while ( -- V_259 );
if ( F_10 ( V_14 ) )
goto V_264;
V_10 -> V_170 = V_170 ;
V_10 -> V_169 = V_131 ;
return 0 ;
V_264:
F_33 ( V_170 ) ;
error:
F_33 ( V_131 ) ;
return - V_46 ;
}
static void F_141 ( struct V_9 * V_10 ,
enum V_266 type )
{
enum V_266 V_267 , V_268 = type ;
int V_269 = 0 ;
if ( V_10 -> V_29 == V_52 )
V_10 -> V_29 = V_38 ;
switch ( type ) {
case V_270 :
V_268 = V_271 ;
case V_271 :
case V_61 :
V_267 = type ;
break;
case V_272 :
case V_273 :
case V_274 :
case V_275 :
V_267 = V_271 ;
V_268 = V_270 ;
V_269 = 1 ;
break;
default:
F_142 () ;
}
{
T_7 * V_18 = V_10 -> V_18 . V_60 , * V_276 = V_18 ;
unsigned V_56 = V_10 -> V_18 . V_63 ;
for (; V_56 ; -- V_56 , ++ V_18 )
if ( ( * V_18 == V_267 || * V_18 == V_268 ) == V_269 )
* V_276 ++ = * V_18 ;
else
F_14 ( L_33 , * V_18 ) ;
V_10 -> V_18 . V_63 = V_276 - V_10 -> V_18 . V_60 ;
}
F_14 ( L_34 , type ) ;
V_10 -> V_18 . V_60 [ V_10 -> V_18 . V_63 ++ ] = type ;
F_143 ( & V_10 -> V_18 . V_21 ) ;
}
static void F_144 ( struct V_9 * V_10 ,
enum V_266 type )
{
unsigned long V_50 ;
F_122 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
F_141 ( V_10 , type ) ;
F_123 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
}
static int F_145 ( enum V_246 type , T_7 * V_247 ,
struct V_212 * V_209 ,
void * V_211 )
{
struct V_206 * V_207 = ( void * ) V_209 ;
struct V_1 * V_76 = V_211 ;
struct V_82 * V_82 ;
const int V_277 = V_76 -> V_4 . V_278 != NULL ;
unsigned V_279 ;
if ( type != V_245 )
return 0 ;
if ( V_277 )
V_76 -> V_4 . V_278 [ ( long ) V_247 ] = V_209 ;
else
V_76 -> V_4 . V_280 [ ( long ) V_247 ] = V_209 ;
if ( ! V_209 || V_209 -> V_215 != V_226 )
return 0 ;
V_279 = ( V_207 -> V_230 & V_251 ) - 1 ;
V_82 = V_76 -> V_205 + V_279 ;
if ( F_10 ( V_82 -> V_208 [ V_277 ] ) ) {
F_14 ( L_35 ,
V_277 ? L_36 : L_37 ,
V_207 -> V_230 & V_251 ) ;
return - V_46 ;
}
V_82 -> V_208 [ V_277 ] = V_207 ;
F_146 ( L_38 , V_207 , V_207 -> V_214 ) ;
if ( V_82 -> V_6 ) {
V_207 -> V_230 = V_82 -> V_208 [ 0 ] -> V_230 ;
if ( ! V_207 -> V_281 )
V_207 -> V_281 = V_82 -> V_208 [ 0 ] -> V_281 ;
} else {
struct V_7 * V_8 ;
struct V_5 * V_6 ;
F_14 ( L_39 ) ;
V_6 = F_147 ( V_76 -> V_25 , V_207 ) ;
if ( F_10 ( ! V_6 ) )
return - V_282 ;
V_6 -> V_83 = V_76 -> V_205 + V_279 ;
V_8 = F_112 ( V_6 , V_67 ) ;
if ( F_10 ( ! V_8 ) )
return - V_68 ;
V_82 -> V_6 = V_6 ;
V_82 -> V_8 = V_8 ;
V_76 -> V_283 [ V_207 -> V_230 &
V_251 ] = V_279 + 1 ;
}
F_146 ( L_40 , V_207 , V_207 -> V_214 ) ;
return 0 ;
}
static int F_148 ( enum V_246 type , T_7 * V_247 ,
struct V_212 * V_209 ,
void * V_211 )
{
struct V_1 * V_76 = V_211 ;
unsigned V_279 ;
T_7 V_284 ;
switch ( type ) {
default:
case V_245 :
return 0 ;
case V_248 :
V_279 = * V_247 ;
if ( V_76 -> V_285 [ V_279 ] < 0 ) {
int V_186 = F_149 ( V_76 -> V_204 , & V_76 -> V_4 ) ;
if ( F_10 ( V_186 < 0 ) )
return V_186 ;
V_76 -> V_285 [ V_279 ] = V_186 ;
}
V_284 = V_76 -> V_285 [ V_279 ] ;
break;
case V_249 :
V_284 = V_76 -> V_10 -> V_170 [ 0 ] -> V_185 [ * V_247 - 1 ] . V_186 ;
break;
case V_250 :
if ( V_209 -> V_215 == V_226 )
return 0 ;
V_279 = ( * V_247 & V_251 ) - 1 ;
if ( F_10 ( ! V_76 -> V_205 [ V_279 ] . V_6 ) )
return - V_46 ;
{
struct V_206 * * V_208 ;
V_208 = V_76 -> V_205 [ V_279 ] . V_208 ;
V_284 = V_208 [ V_208 [ 0 ] ? 0 : 1 ] -> V_230 ;
}
break;
}
F_14 ( L_41 , * V_247 , V_284 ) ;
* V_247 = V_284 ;
return 0 ;
}
static int V_192 ( struct V_189 * V_190 ,
struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
const int V_286 = ! ! V_76 -> V_10 -> V_173 ;
const int V_287 = F_150 ( V_76 -> V_25 ) &&
V_76 -> V_10 -> V_174 ;
int V_16 ;
struct {
struct V_82 V_205 [ V_10 -> V_167 ] ;
struct V_212
* V_288 [ V_286 ? V_10 -> V_173 + 1 : 0 ] ;
struct V_212
* V_289 [ V_287 ? V_10 -> V_174 + 1 : 0 ] ;
short V_290 [ V_10 -> V_176 ] ;
char V_168 [ V_287 ? V_10 -> V_171
: V_10 -> V_172 ] ;
} * V_13 ;
F_18 () ;
if ( F_10 ( ! ( V_286 | V_287 ) ) )
return - V_282 ;
V_13 = F_39 ( sizeof *V_13 , V_67 ) ;
if ( F_10 ( ! V_13 ) )
return - V_68 ;
memset ( V_13 -> V_205 , 0 , sizeof V_13 -> V_205 ) ;
memcpy ( V_13 -> V_168 , V_10 -> V_168 + 16 , sizeof V_13 -> V_168 ) ;
memset ( V_13 -> V_290 , 0xff , sizeof V_13 -> V_290 ) ;
for ( V_16 = V_10 -> V_167 ; V_16 ; -- V_16 )
V_13 -> V_205 [ V_16 ] . V_101 = - 1 ;
V_76 -> V_205 = V_13 -> V_205 ;
V_76 -> V_285 = V_13 -> V_290 ;
if ( F_38 ( V_286 ) ) {
V_76 -> V_4 . V_280 = V_13 -> V_288 ;
V_16 = F_136 ( V_10 -> V_173 ,
V_13 -> V_168 ,
sizeof V_13 -> V_168 ,
F_145 , V_76 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
} else {
V_16 = 0 ;
}
if ( F_38 ( V_287 ) ) {
V_76 -> V_4 . V_278 = V_13 -> V_289 ;
V_16 = F_136 ( V_10 -> V_174 ,
V_13 -> V_168 + V_16 ,
( sizeof V_13 -> V_168 ) - V_16 ,
F_145 , V_76 ) ;
}
V_16 = F_136 ( V_10 -> V_173 +
( V_287 ? V_10 -> V_174 : 0 ) ,
V_13 -> V_168 , sizeof V_13 -> V_168 ,
F_148 , V_76 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
F_144 ( V_10 , V_272 ) ;
return 0 ;
error:
return V_16 ;
}
static void V_194 ( struct V_189 * V_190 ,
struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
F_18 () ;
if ( V_10 -> V_76 == V_76 ) {
F_124 ( V_76 ) ;
V_10 -> V_76 = NULL ;
}
F_144 ( V_10 , V_273 ) ;
F_121 ( V_76 ) ;
}
static int V_196 ( struct V_2 * V_3 ,
unsigned V_291 , unsigned V_292 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
int V_16 = 0 , V_293 ;
if ( V_292 != ( unsigned ) - 1 ) {
V_293 = F_45 ( V_76 , V_291 ) ;
if ( F_10 ( V_293 < 0 ) )
return V_293 ;
}
if ( V_10 -> V_76 )
F_124 ( V_10 -> V_76 ) ;
if ( V_10 -> V_43 != V_48 )
return - V_77 ;
if ( V_292 == ( unsigned ) - 1 ) {
V_10 -> V_76 = NULL ;
F_144 ( V_10 , V_274 ) ;
return 0 ;
}
V_10 -> V_76 = V_76 ;
V_16 = F_126 ( V_76 ) ;
if ( F_38 ( V_16 >= 0 ) )
F_144 ( V_10 , V_275 ) ;
return V_16 ;
}
static void V_198 ( struct V_2 * V_3 )
{
V_196 ( V_3 , 0 , ( unsigned ) - 1 ) ;
}
static int V_199 ( struct V_2 * V_3 ,
const struct V_294 * V_295 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
unsigned long V_50 ;
int V_16 ;
F_18 () ;
F_14 ( L_42 , V_295 -> V_53 ) ;
F_14 ( L_43 , V_295 -> V_296 ) ;
F_14 ( L_44 , F_6 ( V_295 -> V_297 ) ) ;
F_14 ( L_45 , F_6 ( V_295 -> V_298 ) ) ;
F_14 ( L_46 , F_6 ( V_295 -> V_20 ) ) ;
if ( V_10 -> V_43 != V_48 )
return - V_77 ;
switch ( V_295 -> V_53 & V_299 ) {
case V_300 :
V_16 = F_45 ( V_76 , F_6 ( V_295 -> V_298 ) ) ;
if ( F_10 ( V_16 < 0 ) )
return V_16 ;
break;
case V_301 :
V_16 = F_151 ( V_76 , F_6 ( V_295 -> V_298 ) ) ;
if ( F_10 ( V_16 < 0 ) )
return V_16 ;
break;
default:
return - V_302 ;
}
F_122 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
V_10 -> V_18 . V_19 = * V_295 ;
V_10 -> V_18 . V_19 . V_298 = F_152 ( V_16 ) ;
F_141 ( V_10 , V_61 ) ;
F_123 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
return 0 ;
}
static void V_201 ( struct V_2 * V_3 )
{
F_18 () ;
F_144 ( F_1 ( V_3 ) -> V_10 , V_271 ) ;
}
static void V_203 ( struct V_2 * V_3 )
{
F_18 () ;
F_144 ( F_1 ( V_3 ) -> V_10 , V_270 ) ;
}
static int F_151 ( struct V_1 * V_76 , T_7 V_101 )
{
V_101 = V_76 -> V_283 [ V_101 & V_251 ] ;
return V_101 ? V_101 : - V_303 ;
}
static int F_45 ( struct V_1 * V_76 , T_7 V_293 )
{
short * V_304 = V_76 -> V_285 ;
unsigned V_63 = V_76 -> V_10 -> V_176 ;
for (; V_63 ; -- V_63 , ++ V_304 ) {
if ( * V_304 >= 0 && * V_304 == V_293 )
return V_304 - V_76 -> V_285 ;
}
return - V_303 ;
}
static int F_20 ( struct V_40 * V_40 , unsigned V_305 )
{
return V_305
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
