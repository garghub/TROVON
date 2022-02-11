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
} else if ( V_25 -> V_78 -> V_79 ) {
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
V_10 -> V_135 = V_13 -> V_135 ;
V_10 -> V_130 = V_13 -> V_109 ;
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
if ( F_10 ( ! V_69 ) )
goto V_134;
V_103 -> V_129 = F_72 ( V_69 ) ;
if ( F_10 ( ! V_103 -> V_129 ) ) {
F_73 ( V_69 ) ;
goto V_134;
}
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
if ( ! memcmp ( V_149 , L_11 , 3 ) )
V_13 -> V_109 . V_117 = V_73 ;
else if ( ! memcmp ( V_149 , L_12 , 3 ) )
V_13 -> V_109 . V_119 = V_73 ;
else
goto V_155;
break;
default:
V_155:
F_75 ( L_13 , V_149 ) ;
return - V_46 ;
}
if ( ! V_152 )
break;
V_149 = V_152 + 1 ;
}
return 0 ;
}
static struct V_126 *
F_77 ( struct V_156 * V_157 , int V_50 ,
const char * V_135 , void * V_149 )
{
struct V_133 V_13 = {
. V_109 = {
. V_115 = V_154 | 0600 ,
. V_117 = 0 ,
. V_119 = 0
} ,
. V_145 = V_153 | 0500 ,
} ;
int V_16 ;
F_18 () ;
V_16 = F_78 ( V_135 ) ;
if ( F_10 ( V_16 < 0 ) )
return F_79 ( V_16 ) ;
V_16 = F_74 ( & V_13 , V_149 ) ;
if ( F_10 ( V_16 < 0 ) )
return F_79 ( V_16 ) ;
V_13 . V_135 = V_135 ;
return F_80 ( V_157 , V_50 , & V_13 , F_70 ) ;
}
static void
F_81 ( struct V_102 * V_103 )
{
F_18 () ;
F_82 ( V_103 ) ;
if ( V_103 -> V_128 )
F_83 ( V_103 -> V_128 ) ;
}
static int F_84 ( void )
{
int V_16 ;
F_18 () ;
V_16 = F_85 ( & V_158 ) ;
if ( F_38 ( ! V_16 ) )
F_24 ( L_14 ) ;
else
F_75 ( L_15 , V_16 ) ;
return V_16 ;
}
static void F_86 ( void )
{
F_18 () ;
F_24 ( L_16 ) ;
F_87 ( & V_158 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
F_18 () ;
F_89 ( & V_10 -> V_159 ) ;
}
static void F_41 ( struct V_9 * V_10 )
{
F_18 () ;
F_89 ( & V_10 -> V_159 ) ;
F_89 ( & V_10 -> V_160 ) ;
}
static void F_83 ( struct V_9 * V_10 )
{
F_18 () ;
if ( F_10 ( F_90 ( & V_10 -> V_159 ) ) ) {
F_24 ( L_17 , V_161 ) ;
F_91 ( V_10 ) ;
F_92 ( F_93 ( & V_10 -> V_40 ) ||
F_94 ( & V_10 -> V_18 . V_21 . V_22 ) ||
F_95 ( & V_10 -> V_18 . V_21 ) ||
F_95 ( & V_10 -> V_12 . V_92 ) ) ;
F_33 ( V_10 ) ;
}
}
static void F_43 ( struct V_9 * V_10 )
{
F_18 () ;
if ( F_90 ( & V_10 -> V_160 ) ) {
V_10 -> V_43 = V_47 ;
F_96 ( V_10 ) ;
}
F_83 ( V_10 ) ;
}
static struct V_9 * F_71 ( void )
{
struct V_9 * V_10 = F_51 ( sizeof *V_10 , V_67 ) ;
if ( F_10 ( ! V_10 ) )
return 0 ;
F_18 () ;
F_97 ( & V_10 -> V_159 , 1 ) ;
F_97 ( & V_10 -> V_160 , 0 ) ;
V_10 -> V_43 = V_44 ;
F_98 ( & V_10 -> V_40 ) ;
F_99 ( & V_10 -> V_91 ) ;
F_100 ( & V_10 -> V_18 . V_21 ) ;
F_101 ( & V_10 -> V_12 ) ;
V_10 -> V_18 . V_32 = 1 ;
return V_10 ;
}
static void F_91 ( struct V_9 * V_10 )
{
F_18 () ;
if ( F_102 ( V_49 , & V_10 -> V_50 ) )
F_103 ( V_10 ) ;
F_92 ( V_10 -> V_25 ) ;
if ( V_10 -> V_162 )
F_104 ( V_10 -> V_162 , V_10 -> V_163 ) ;
F_33 ( V_10 -> V_164 ) ;
F_33 ( V_10 -> V_165 ) ;
F_33 ( V_10 -> V_166 ) ;
}
static void F_96 ( struct V_9 * V_10 )
{
F_18 () ;
F_91 ( V_10 ) ;
V_10 -> V_162 = NULL ;
V_10 -> V_164 = NULL ;
V_10 -> V_165 = NULL ;
V_10 -> V_166 = NULL ;
V_10 -> V_167 = 0 ;
V_10 -> V_168 = 0 ;
V_10 -> V_169 = 0 ;
V_10 -> V_170 = 0 ;
V_10 -> V_171 = 0 ;
V_10 -> V_172 = 0 ;
V_10 -> V_163 = 0 ;
V_10 -> V_18 . V_63 = 0 ;
V_10 -> V_43 = V_44 ;
V_10 -> V_29 = V_30 ;
V_10 -> V_50 = 0 ;
}
static int F_105 ( struct V_9 * V_10 , struct V_173 * V_174 )
{
struct V_175 * * V_176 ;
int V_177 ;
F_18 () ;
if ( F_49 ( V_10 -> V_43 != V_48
|| F_106 ( V_178 , & V_10 -> V_50 ) ) )
return - V_55 ;
V_177 = F_107 ( V_174 , V_10 -> V_171 ) ;
if ( F_10 ( V_177 < 0 ) )
return V_177 ;
V_10 -> V_15 = F_108 ( V_174 -> V_25 -> V_26 , V_67 ) ;
if ( F_10 ( ! V_10 -> V_15 ) )
return - V_68 ;
V_10 -> V_15 -> F_47 = F_3 ;
V_10 -> V_15 -> V_11 = V_10 ;
V_176 = V_10 -> V_166 ;
for ( V_176 = V_10 -> V_166 ; * V_176 ; ++ V_176 ) {
struct V_179 * V_180 = ( * V_176 ) -> V_181 ;
int V_182 = V_177 ;
for (; V_180 -> V_183 ; ++ V_182 , ++ V_180 )
V_180 -> V_182 = V_182 ;
}
V_10 -> V_25 = V_174 -> V_25 ;
F_88 ( V_10 ) ;
return 0 ;
}
static void F_109 ( struct V_9 * V_10 )
{
F_18 () ;
if ( ! F_49 ( ! V_10 -> V_25 ) ) {
F_110 ( V_10 -> V_25 -> V_26 , V_10 -> V_15 ) ;
V_10 -> V_15 = NULL ;
V_10 -> V_25 = NULL ;
F_83 ( V_10 ) ;
}
}
static int F_27 ( struct V_9 * V_10 )
{
struct V_87 * V_88 , * V_162 ;
unsigned V_59 , V_63 ;
F_18 () ;
V_63 = V_10 -> V_163 ;
V_162 = F_111 ( V_63 , sizeof( * V_162 ) , V_67 ) ;
if ( ! V_162 )
return - V_68 ;
V_88 = V_162 ;
for ( V_59 = 1 ; V_59 <= V_63 ; ++ V_59 , ++ V_88 ) {
V_88 -> V_10 = V_10 ;
F_98 ( & V_88 -> V_40 ) ;
F_100 ( & V_88 -> V_92 ) ;
sprintf ( V_162 -> V_125 , L_18 , V_59 ) ;
if ( ! F_10 ( F_66 ( V_10 -> V_103 , V_162 -> V_125 , V_88 ,
& V_184 ,
& V_88 -> V_126 ) ) ) {
F_104 ( V_162 , V_59 - 1 ) ;
return - V_68 ;
}
}
V_10 -> V_162 = V_162 ;
return 0 ;
}
static void F_104 ( struct V_87 * V_162 , unsigned V_63 )
{
struct V_87 * V_88 = V_162 ;
F_18 () ;
for (; V_63 ; -- V_63 , ++ V_88 ) {
F_92 ( F_93 ( & V_88 -> V_40 ) ||
F_95 ( & V_88 -> V_92 ) ) ;
if ( V_88 -> V_126 ) {
F_112 ( V_88 -> V_126 ) ;
F_68 ( V_88 -> V_126 ) ;
V_88 -> V_126 = NULL ;
}
}
F_33 ( V_162 ) ;
}
static int F_113 ( struct V_173 * V_174 ,
struct V_185 * V_186 ,
struct V_9 * V_10 )
{
struct V_1 * V_76 ;
int V_16 ;
F_18 () ;
V_76 = F_51 ( sizeof *V_76 , V_67 ) ;
if ( F_10 ( ! V_76 ) )
return - V_68 ;
V_76 -> V_4 . V_125 = L_19 ;
V_76 -> V_4 . V_181 = V_10 -> V_166 ;
V_76 -> V_4 . V_187 = V_188 ;
V_76 -> V_4 . V_189 = V_190 ;
V_76 -> V_4 . V_191 = V_192 ;
V_76 -> V_4 . V_193 = V_194 ;
V_76 -> V_4 . V_19 = V_195 ;
V_76 -> V_4 . V_196 = V_197 ;
V_76 -> V_4 . V_198 = V_199 ;
V_76 -> V_200 = V_186 ;
V_76 -> V_25 = V_174 -> V_25 ;
V_76 -> V_10 = V_10 ;
F_88 ( V_10 ) ;
V_16 = F_114 ( V_186 , & V_76 -> V_4 ) ;
if ( F_10 ( V_16 ) )
F_115 ( V_76 ) ;
return V_16 ;
}
static void F_115 ( struct V_1 * V_76 )
{
F_18 () ;
F_83 ( V_76 -> V_10 ) ;
F_33 ( V_76 -> V_201 ) ;
F_33 ( V_76 ) ;
}
static void F_116 ( struct V_1 * V_76 )
{
struct V_82 * V_6 = V_76 -> V_201 ;
struct V_87 * V_88 = V_76 -> V_10 -> V_162 ;
unsigned V_63 = V_76 -> V_10 -> V_163 ;
unsigned long V_50 ;
F_117 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
do {
if ( F_38 ( V_6 -> V_6 ) )
F_118 ( V_6 -> V_6 ) ;
V_88 -> V_6 = NULL ;
++ V_6 ;
++ V_88 ;
} while ( -- V_63 );
F_119 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
}
static int F_120 ( struct V_1 * V_76 )
{
struct V_9 * V_10 = V_76 -> V_10 ;
struct V_82 * V_6 = V_76 -> V_201 ;
struct V_87 * V_88 = V_10 -> V_162 ;
unsigned V_63 = V_10 -> V_163 ;
unsigned long V_50 ;
int V_16 = 0 ;
F_117 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
do {
struct V_202 * V_203 ;
V_203 = V_6 -> V_204 [ V_6 -> V_204 [ 1 ] ? 1 : 0 ] ;
V_6 -> V_6 -> V_83 = V_6 ;
V_6 -> V_6 -> V_205 = V_203 ;
V_16 = F_121 ( V_6 -> V_6 ) ;
if ( F_38 ( ! V_16 ) ) {
V_88 -> V_6 = V_6 ;
V_88 -> V_93 = F_122 ( V_203 ) ;
V_88 -> V_94 = F_123 ( V_203 ) ;
} else {
break;
}
F_124 ( & V_88 -> V_92 ) ;
++ V_6 ;
++ V_88 ;
} while ( -- V_63 );
F_119 ( & V_76 -> V_10 -> V_91 , V_50 ) ;
return V_16 ;
}
static int T_5 F_125 ( char * V_13 , unsigned V_14 ,
T_6 V_206 , void * V_207 )
{
struct V_208 * V_209 = ( void * ) V_13 ;
T_7 V_24 ;
int V_16 ;
F_18 () ;
if ( V_14 < 2 ) {
F_14 ( L_20 ) ;
return - V_46 ;
}
V_24 = V_209 -> V_210 ;
if ( V_14 < V_24 ) {
F_14 ( L_21 ) ;
return - V_46 ;
}
#define F_126 ( T_8 ) 1
#define F_127 ( T_8 ) (val)
#define F_128 ( T_8 ) ((val) & USB_ENDPOINT_NUMBER_MASK)
#define F_129 ( type , T_8 ) do { \
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
switch ( V_209 -> V_211 ) {
case V_212 :
case V_213 :
case V_214 :
case V_215 :
F_14 ( L_22 ,
V_209 -> V_211 ) ;
return - V_46 ;
case V_216 : {
struct V_217 * V_203 = ( void * ) V_209 ;
F_14 ( L_23 ) ;
if ( V_24 != sizeof *V_203 )
goto V_218;
F_129 ( V_219 , V_203 -> V_220 ) ;
if ( V_203 -> V_221 )
F_129 ( STRING , V_203 -> V_221 ) ;
}
break;
case V_222 : {
struct V_202 * V_203 = ( void * ) V_209 ;
F_14 ( L_24 ) ;
if ( V_24 != V_223 &&
V_24 != V_224 )
goto V_218;
F_129 ( V_225 , V_203 -> V_226 ) ;
}
break;
case V_227 :
if ( V_24 != sizeof( struct V_228 ) )
goto V_218;
break;
case V_229 : {
struct V_230 * V_203 = ( void * ) V_209 ;
F_14 ( L_25 ) ;
if ( V_24 != sizeof *V_203 )
goto V_218;
if ( V_203 -> V_231 )
F_129 ( STRING , V_203 -> V_231 ) ;
}
break;
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
F_14 ( L_26 , V_209 -> V_211 ) ;
return - V_46 ;
default:
F_14 ( L_27 , V_209 -> V_211 ) ;
return - V_46 ;
V_218:
F_14 ( L_28 ,
V_209 -> V_210 , V_209 -> V_211 ) ;
return - V_46 ;
}
#undef F_129
#undef V_237
#undef F_126
#undef F_127
#undef F_128
return V_24 ;
}
static int T_5 F_130 ( unsigned V_63 , char * V_13 , unsigned V_14 ,
T_6 V_206 , void * V_207 )
{
const unsigned V_238 = V_14 ;
unsigned long V_101 = 0 ;
F_18 () ;
for (; ; ) {
int V_16 ;
if ( V_101 == V_63 )
V_13 = NULL ;
V_16 = V_206 ( V_239 , ( T_7 * ) V_101 , ( void * ) V_13 , V_207 ) ;
if ( F_10 ( V_16 < 0 ) ) {
F_16 ( L_29 ,
V_101 , V_16 ) ;
return V_16 ;
}
if ( ! V_13 )
return V_238 - V_14 ;
V_16 = F_125 ( V_13 , V_14 , V_206 , V_207 ) ;
if ( F_10 ( V_16 < 0 ) ) {
F_16 ( L_30 , V_161 , V_16 ) ;
return V_16 ;
}
V_14 -= V_16 ;
V_13 += V_16 ;
++ V_101 ;
}
}
static int F_131 ( enum V_240 type ,
T_7 * V_241 , struct V_208 * V_205 ,
void * V_207 )
{
struct V_9 * V_10 = V_207 ;
F_18 () ;
switch ( type ) {
case V_239 :
break;
case V_242 :
if ( * V_241 >= V_10 -> V_172 )
V_10 -> V_172 = * V_241 + 1 ;
break;
case V_243 :
if ( * V_241 > V_10 -> V_171 )
V_10 -> V_171 = * V_241 ;
break;
case V_244 :
if ( ( * V_241 & V_245 ) > V_10 -> V_163 )
V_10 -> V_163 = ( * V_241 & V_245 ) ;
break;
}
return 0 ;
}
static int F_25 ( struct V_9 * V_10 ,
char * const V_131 , T_1 V_14 )
{
unsigned V_246 , V_247 ;
int V_248 , V_16 = - V_46 ;
char * V_13 = V_131 ;
F_18 () ;
if ( F_10 ( F_132 ( V_13 ) != V_249 ||
F_132 ( V_13 + 4 ) != V_14 ) )
goto error;
V_246 = F_132 ( V_13 + 8 ) ;
V_247 = F_132 ( V_13 + 12 ) ;
if ( ! V_246 && ! V_247 )
goto V_250;
V_13 += 16 ;
V_14 -= 16 ;
if ( F_38 ( V_246 ) ) {
V_248 = F_130 ( V_246 , V_13 , V_14 ,
F_131 , V_10 ) ;
if ( F_10 ( V_248 < 0 ) ) {
V_16 = V_248 ;
goto error;
}
V_13 += V_248 ;
V_14 -= V_248 ;
} else {
V_248 = 0 ;
}
if ( F_38 ( V_247 ) ) {
V_16 = F_130 ( V_247 , V_13 , V_14 ,
F_131 , V_10 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
} else {
V_16 = 0 ;
}
if ( F_10 ( V_14 != V_16 ) )
goto V_250;
V_10 -> V_168 = V_248 ;
V_10 -> V_167 = V_248 + V_16 ;
V_10 -> V_164 = V_131 ;
V_10 -> V_169 = V_246 ;
V_10 -> V_170 = V_247 ;
return 0 ;
V_250:
V_16 = - V_46 ;
error:
F_33 ( V_131 ) ;
return V_16 ;
}
static int F_26 ( struct V_9 * V_10 ,
char * const V_131 , T_1 V_14 )
{
T_9 V_251 , V_252 , V_253 ;
struct V_175 * * V_166 , * V_157 ;
struct V_179 * V_181 , * V_183 ;
const char * V_13 = V_131 ;
F_18 () ;
if ( F_10 ( F_132 ( V_13 ) != V_254 ||
F_132 ( V_13 + 4 ) != V_14 ) )
goto error;
V_251 = F_132 ( V_13 + 8 ) ;
V_253 = F_132 ( V_13 + 12 ) ;
if ( F_10 ( ! V_251 != ! V_253 ) )
goto error;
V_252 = V_10 -> V_171 ;
if ( F_10 ( V_251 < V_252 ) )
goto error;
if ( ! V_252 ) {
F_33 ( V_131 ) ;
return 0 ;
}
{
struct {
struct V_175 * V_166 [ V_253 + 1 ] ;
struct V_175 V_255 [ V_253 ] ;
struct V_179 V_181 [ V_253 * ( V_252 + 1 ) ] ;
} * V_256 ;
unsigned V_59 = 0 ;
V_256 = F_39 ( sizeof *V_256 , V_67 ) ;
if ( F_10 ( ! V_256 ) ) {
F_33 ( V_131 ) ;
return - V_68 ;
}
V_166 = V_256 -> V_166 ;
V_157 = V_256 -> V_255 ;
V_59 = V_253 ;
do {
* V_166 ++ = V_157 ++ ;
} while ( -- V_59 );
* V_166 = NULL ;
V_166 = V_256 -> V_166 ;
V_157 = V_256 -> V_255 ;
V_183 = V_256 -> V_181 ;
V_181 = V_183 ;
}
V_13 += 16 ;
V_14 -= 16 ;
do {
unsigned V_257 = V_252 ;
if ( F_10 ( V_14 < 3 ) )
goto V_258;
V_157 -> V_259 = F_133 ( V_13 ) ;
V_157 -> V_181 = V_183 ;
++ V_157 ;
V_13 += 2 ;
V_14 -= 2 ;
do {
T_1 V_24 = F_134 ( V_13 , V_14 ) ;
if ( F_10 ( V_24 == V_14 ) )
goto V_258;
if ( F_38 ( V_257 ) ) {
V_183 -> V_183 = V_13 ;
-- V_257 ;
++ V_183 ;
}
V_13 += V_24 + 1 ;
V_14 -= V_24 + 1 ;
} while ( -- V_251 );
V_183 -> V_182 = 0 ;
V_183 -> V_183 = NULL ;
++ V_183 ;
} while ( -- V_253 );
if ( F_10 ( V_14 ) )
goto V_258;
V_10 -> V_166 = V_166 ;
V_10 -> V_165 = V_131 ;
return 0 ;
V_258:
F_33 ( V_166 ) ;
error:
F_33 ( V_131 ) ;
return - V_46 ;
}
static void F_135 ( struct V_9 * V_10 ,
enum V_260 type )
{
enum V_260 V_261 , V_262 = type ;
int V_263 = 0 ;
if ( V_10 -> V_29 == V_52 )
V_10 -> V_29 = V_38 ;
switch ( type ) {
case V_264 :
V_262 = V_265 ;
case V_265 :
case V_61 :
V_261 = type ;
break;
case V_266 :
case V_267 :
case V_268 :
case V_269 :
V_261 = V_265 ;
V_262 = V_264 ;
V_263 = 1 ;
break;
default:
F_136 () ;
}
{
T_7 * V_18 = V_10 -> V_18 . V_60 , * V_270 = V_18 ;
unsigned V_56 = V_10 -> V_18 . V_63 ;
for (; V_56 ; -- V_56 , ++ V_18 )
if ( ( * V_18 == V_261 || * V_18 == V_262 ) == V_263 )
* V_270 ++ = * V_18 ;
else
F_14 ( L_31 , * V_18 ) ;
V_10 -> V_18 . V_63 = V_270 - V_10 -> V_18 . V_60 ;
}
F_14 ( L_32 , type ) ;
V_10 -> V_18 . V_60 [ V_10 -> V_18 . V_63 ++ ] = type ;
F_137 ( & V_10 -> V_18 . V_21 ) ;
}
static void F_138 ( struct V_9 * V_10 ,
enum V_260 type )
{
unsigned long V_50 ;
F_117 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
F_135 ( V_10 , type ) ;
F_119 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
}
static int F_139 ( enum V_240 type , T_7 * V_241 ,
struct V_208 * V_205 ,
void * V_207 )
{
struct V_202 * V_203 = ( void * ) V_205 ;
struct V_1 * V_76 = V_207 ;
struct V_82 * V_82 ;
const int V_271 = V_76 -> V_4 . V_272 != NULL ;
unsigned V_273 ;
if ( type != V_239 )
return 0 ;
if ( V_271 )
V_76 -> V_4 . V_272 [ ( long ) V_241 ] = V_205 ;
else
V_76 -> V_4 . V_274 [ ( long ) V_241 ] = V_205 ;
if ( ! V_205 || V_205 -> V_211 != V_222 )
return 0 ;
V_273 = ( V_203 -> V_226 & V_245 ) - 1 ;
V_82 = V_76 -> V_201 + V_273 ;
if ( F_10 ( V_82 -> V_204 [ V_271 ] ) ) {
F_14 ( L_33 ,
V_271 ? L_34 : L_35 ,
V_203 -> V_226 & V_245 ) ;
return - V_46 ;
}
V_82 -> V_204 [ V_271 ] = V_203 ;
F_140 ( L_36 , V_203 , V_203 -> V_210 ) ;
if ( V_82 -> V_6 ) {
V_203 -> V_226 = V_82 -> V_204 [ 0 ] -> V_226 ;
if ( ! V_203 -> V_275 )
V_203 -> V_275 = V_82 -> V_204 [ 0 ] -> V_275 ;
} else {
struct V_7 * V_8 ;
struct V_5 * V_6 ;
F_14 ( L_37 ) ;
V_6 = F_141 ( V_76 -> V_25 , V_203 ) ;
if ( F_10 ( ! V_6 ) )
return - V_276 ;
V_6 -> V_83 = V_76 -> V_201 + V_273 ;
V_8 = F_108 ( V_6 , V_67 ) ;
if ( F_10 ( ! V_8 ) )
return - V_68 ;
V_82 -> V_6 = V_6 ;
V_82 -> V_8 = V_8 ;
V_76 -> V_277 [ V_203 -> V_226 &
V_245 ] = V_273 + 1 ;
}
F_140 ( L_38 , V_203 , V_203 -> V_210 ) ;
return 0 ;
}
static int F_142 ( enum V_240 type , T_7 * V_241 ,
struct V_208 * V_205 ,
void * V_207 )
{
struct V_1 * V_76 = V_207 ;
unsigned V_273 ;
T_7 V_278 ;
switch ( type ) {
default:
case V_239 :
return 0 ;
case V_242 :
V_273 = * V_241 ;
if ( V_76 -> V_279 [ V_273 ] < 0 ) {
int V_182 = F_143 ( V_76 -> V_200 , & V_76 -> V_4 ) ;
if ( F_10 ( V_182 < 0 ) )
return V_182 ;
V_76 -> V_279 [ V_273 ] = V_182 ;
}
V_278 = V_76 -> V_279 [ V_273 ] ;
break;
case V_243 :
V_278 = V_76 -> V_10 -> V_166 [ 0 ] -> V_181 [ * V_241 - 1 ] . V_182 ;
break;
case V_244 :
if ( V_205 -> V_211 == V_222 )
return 0 ;
V_273 = ( * V_241 & V_245 ) - 1 ;
if ( F_10 ( ! V_76 -> V_201 [ V_273 ] . V_6 ) )
return - V_46 ;
{
struct V_202 * * V_204 ;
V_204 = V_76 -> V_201 [ V_273 ] . V_204 ;
V_278 = V_204 [ V_204 [ 0 ] ? 0 : 1 ] -> V_226 ;
}
break;
}
F_14 ( L_39 , * V_241 , V_278 ) ;
* V_241 = V_278 ;
return 0 ;
}
static int V_188 ( struct V_185 * V_186 ,
struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
const int V_280 = ! ! V_76 -> V_10 -> V_169 ;
const int V_281 = F_144 ( V_76 -> V_25 ) &&
V_76 -> V_10 -> V_170 ;
int V_16 ;
struct {
struct V_82 V_201 [ V_10 -> V_163 ] ;
struct V_208
* V_282 [ V_280 ? V_10 -> V_169 + 1 : 0 ] ;
struct V_208
* V_283 [ V_281 ? V_10 -> V_170 + 1 : 0 ] ;
short V_284 [ V_10 -> V_172 ] ;
char V_164 [ V_281 ? V_10 -> V_167
: V_10 -> V_168 ] ;
} * V_13 ;
F_18 () ;
if ( F_10 ( ! ( V_280 | V_281 ) ) )
return - V_276 ;
V_13 = F_39 ( sizeof *V_13 , V_67 ) ;
if ( F_10 ( ! V_13 ) )
return - V_68 ;
memset ( V_13 -> V_201 , 0 , sizeof V_13 -> V_201 ) ;
memcpy ( V_13 -> V_164 , V_10 -> V_164 + 16 , sizeof V_13 -> V_164 ) ;
memset ( V_13 -> V_284 , 0xff , sizeof V_13 -> V_284 ) ;
for ( V_16 = V_10 -> V_163 ; V_16 ; -- V_16 )
V_13 -> V_201 [ V_16 ] . V_101 = - 1 ;
V_76 -> V_201 = V_13 -> V_201 ;
V_76 -> V_279 = V_13 -> V_284 ;
if ( F_38 ( V_280 ) ) {
V_76 -> V_4 . V_274 = V_13 -> V_282 ;
V_16 = F_130 ( V_10 -> V_169 ,
V_13 -> V_164 ,
sizeof V_13 -> V_164 ,
F_139 , V_76 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
} else {
V_16 = 0 ;
}
if ( F_38 ( V_281 ) ) {
V_76 -> V_4 . V_272 = V_13 -> V_283 ;
V_16 = F_130 ( V_10 -> V_170 ,
V_13 -> V_164 + V_16 ,
( sizeof V_13 -> V_164 ) - V_16 ,
F_139 , V_76 ) ;
}
V_16 = F_130 ( V_10 -> V_169 +
( V_281 ? V_10 -> V_170 : 0 ) ,
V_13 -> V_164 , sizeof V_13 -> V_164 ,
F_142 , V_76 ) ;
if ( F_10 ( V_16 < 0 ) )
goto error;
F_138 ( V_10 , V_266 ) ;
return 0 ;
error:
return V_16 ;
}
static void V_190 ( struct V_185 * V_186 ,
struct V_2 * V_3 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
F_18 () ;
if ( V_10 -> V_76 == V_76 ) {
F_116 ( V_76 ) ;
V_10 -> V_76 = NULL ;
}
F_138 ( V_10 , V_267 ) ;
F_115 ( V_76 ) ;
}
static int V_192 ( struct V_2 * V_3 ,
unsigned V_285 , unsigned V_286 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
int V_16 = 0 , V_287 ;
if ( V_286 != ( unsigned ) - 1 ) {
V_287 = F_45 ( V_76 , V_285 ) ;
if ( F_10 ( V_287 < 0 ) )
return V_287 ;
}
if ( V_10 -> V_76 )
F_116 ( V_10 -> V_76 ) ;
if ( V_10 -> V_43 != V_48 )
return - V_77 ;
if ( V_286 == ( unsigned ) - 1 ) {
V_10 -> V_76 = NULL ;
F_138 ( V_10 , V_268 ) ;
return 0 ;
}
V_10 -> V_76 = V_76 ;
V_16 = F_120 ( V_76 ) ;
if ( F_38 ( V_16 >= 0 ) )
F_138 ( V_10 , V_269 ) ;
return V_16 ;
}
static void V_194 ( struct V_2 * V_3 )
{
V_192 ( V_3 , 0 , ( unsigned ) - 1 ) ;
}
static int V_195 ( struct V_2 * V_3 ,
const struct V_288 * V_289 )
{
struct V_1 * V_76 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_76 -> V_10 ;
unsigned long V_50 ;
int V_16 ;
F_18 () ;
F_14 ( L_40 , V_289 -> V_53 ) ;
F_14 ( L_41 , V_289 -> V_290 ) ;
F_14 ( L_42 , F_6 ( V_289 -> V_291 ) ) ;
F_14 ( L_43 , F_6 ( V_289 -> V_292 ) ) ;
F_14 ( L_44 , F_6 ( V_289 -> V_20 ) ) ;
if ( V_10 -> V_43 != V_48 )
return - V_77 ;
switch ( V_289 -> V_53 & V_293 ) {
case V_294 :
V_16 = F_45 ( V_76 , F_6 ( V_289 -> V_292 ) ) ;
if ( F_10 ( V_16 < 0 ) )
return V_16 ;
break;
case V_295 :
V_16 = F_145 ( V_76 , F_6 ( V_289 -> V_292 ) ) ;
if ( F_10 ( V_16 < 0 ) )
return V_16 ;
break;
default:
return - V_296 ;
}
F_117 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
V_10 -> V_18 . V_19 = * V_289 ;
V_10 -> V_18 . V_19 . V_292 = F_146 ( V_16 ) ;
F_135 ( V_10 , V_61 ) ;
F_119 ( & V_10 -> V_18 . V_21 . V_22 , V_50 ) ;
return 0 ;
}
static void V_197 ( struct V_2 * V_3 )
{
F_18 () ;
F_138 ( F_1 ( V_3 ) -> V_10 , V_265 ) ;
}
static void V_199 ( struct V_2 * V_3 )
{
F_18 () ;
F_138 ( F_1 ( V_3 ) -> V_10 , V_264 ) ;
}
static int F_145 ( struct V_1 * V_76 , T_7 V_101 )
{
V_101 = V_76 -> V_277 [ V_101 & V_245 ] ;
return V_101 ? V_101 : - V_297 ;
}
static int F_45 ( struct V_1 * V_76 , T_7 V_287 )
{
short * V_298 = V_76 -> V_279 ;
unsigned V_63 = V_76 -> V_10 -> V_172 ;
for (; V_63 ; -- V_63 , ++ V_298 ) {
if ( * V_298 >= 0 && * V_298 == V_287 )
return V_298 - V_76 -> V_279 ;
}
return - V_297 ;
}
static int F_20 ( struct V_40 * V_40 , unsigned V_299 )
{
return V_299
? F_38 ( F_147 ( V_40 ) ) ? 0 : - V_66
: F_148 ( V_40 ) ;
}
static char * F_21 ( const char * T_3 V_23 , T_1 V_14 )
{
char * V_13 ;
if ( F_10 ( ! V_14 ) )
return NULL ;
V_13 = F_39 ( V_14 , V_67 ) ;
if ( F_10 ( ! V_13 ) )
return F_79 ( - V_68 ) ;
if ( F_10 ( F_52 ( V_13 , V_23 , V_14 ) ) ) {
F_33 ( V_13 ) ;
return F_79 ( - V_64 ) ;
}
F_14 ( L_45 ) ;
F_140 ( L_46 , V_13 , V_14 ) ;
return V_13 ;
}
