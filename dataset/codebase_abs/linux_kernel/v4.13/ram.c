static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 = 0 ;
V_4 -> V_7 = 0 ;
V_4 -> V_8 = 0 ;
V_4 -> V_9 = 0 ;
return 0 ;
}
static struct V_10 *
F_2 ( struct V_10 * V_11 [] , T_1 * V_12 , T_1 V_13 ,
T_2 * V_14 ,
enum V_15 * V_16 , enum V_15 type ,
bool V_17 )
{
struct V_10 * V_18 ;
int V_19 = ( * V_12 ) ++ ;
if ( ! V_11 || V_19 >= V_13 )
return NULL ;
V_18 = V_11 [ V_19 ] ;
if ( ! V_18 )
return NULL ;
if ( V_17 )
F_3 ( V_18 ) ;
if ( ! F_4 ( V_18 ) )
return NULL ;
* V_16 = type ;
* V_14 = V_19 ;
return V_18 ;
}
static int F_5 ( char * V_20 , struct V_21 * time ,
bool * V_22 )
{
char V_23 ;
int V_24 = 0 ;
if ( sscanf ( V_20 , V_25 L_1 , & time -> V_26 ,
& time -> V_27 , & V_23 , & V_24 ) == 3 ) {
if ( V_23 == 'C' )
* V_22 = true ;
else
* V_22 = false ;
} else if ( sscanf ( V_20 , V_25 L_2 ,
& time -> V_26 , & time -> V_27 , & V_24 ) == 2 ) {
* V_22 = false ;
} else {
time -> V_26 = 0 ;
time -> V_27 = 0 ;
* V_22 = false ;
}
return V_24 ;
}
static bool F_6 ( struct V_10 * V_18 )
{
return ! ! V_18 && ! ! ( F_4 ( V_18 ) +
F_7 ( V_18 , NULL , 0 ) ) ;
}
static T_3 F_8 ( struct V_10 * V_28 ,
struct V_10 * V_29 )
{
T_4 V_30 , V_31 , V_32 , V_33 , V_34 ;
T_4 V_35 = 0 , V_36 = 0 , V_37 = 0 ;
void * V_38 ;
struct V_39 * V_40 , * V_41 , * V_42 ;
T_4 V_43 = sizeof( struct V_39 ) ;
V_33 = V_28 -> V_44 % V_43 ;
V_30 = V_28 -> V_44 - V_33 ;
V_34 = V_29 -> V_44 % V_43 ;
V_31 = V_29 -> V_44 - V_34 ;
V_32 = V_30 + V_31 ;
V_38 = F_9 ( V_32 , V_45 ) ;
if ( ! V_38 )
return - V_46 ;
V_40 = (struct V_39 * ) ( V_28 -> V_47 + V_33 ) ;
V_41 = (struct V_39 * ) ( V_29 -> V_47 + V_34 ) ;
V_42 = (struct V_39 * ) ( V_38 ) ;
while ( V_30 > 0 && V_31 > 0 ) {
if ( F_10 ( & V_40 [ V_35 ] ) <
F_10 ( & V_41 [ V_36 ] ) ) {
V_42 [ V_37 ++ ] = V_40 [ V_35 ++ ] ;
V_30 -= V_43 ;
} else {
V_42 [ V_37 ++ ] = V_41 [ V_36 ++ ] ;
V_31 -= V_43 ;
}
}
while ( V_30 > 0 ) {
V_42 [ V_37 ++ ] = V_40 [ V_35 ++ ] ;
V_30 -= V_43 ;
}
while ( V_31 > 0 ) {
V_42 [ V_37 ++ ] = V_41 [ V_36 ++ ] ;
V_31 -= V_43 ;
}
F_11 ( V_28 -> V_47 ) ;
V_28 -> V_47 = V_38 ;
V_28 -> V_44 = V_32 ;
return 0 ;
}
static T_3 F_12 ( struct V_48 * V_49 )
{
T_3 V_50 = 0 ;
struct V_3 * V_4 = V_49 -> V_2 -> V_5 ;
struct V_10 * V_18 = NULL ;
int V_24 = 0 ;
bool V_51 = false ;
V_49 -> time . V_26 = 0 ;
V_49 -> time . V_27 = 0 ;
V_49 -> V_22 = false ;
while ( V_4 -> V_6 < V_4 -> V_52 && ! V_18 ) {
V_18 = F_2 ( V_4 -> V_53 , & V_4 -> V_6 ,
V_4 -> V_52 , & V_49 -> V_14 ,
& V_49 -> type ,
V_54 , 1 ) ;
if ( ! F_6 ( V_18 ) )
continue;
V_24 = F_5 ( F_13 ( V_18 ) ,
& V_49 -> time ,
& V_49 -> V_22 ) ;
if ( ! V_24 ) {
F_14 ( V_18 ) ;
F_15 ( V_18 ) ;
V_18 = NULL ;
}
}
if ( ! F_6 ( V_18 ) )
V_18 = F_2 ( & V_4 -> V_55 , & V_4 -> V_7 ,
1 , & V_49 -> V_14 , & V_49 -> type ,
V_56 , 0 ) ;
if ( ! F_6 ( V_18 ) )
V_18 = F_2 ( & V_4 -> V_57 , & V_4 -> V_9 ,
1 , & V_49 -> V_14 , & V_49 -> type ,
V_58 , 0 ) ;
if ( ! F_6 ( V_18 ) ) {
if ( ! ( V_4 -> V_59 & V_60 ) ) {
V_18 = F_2 ( V_4 -> V_61 ,
& V_4 -> V_8 , 1 , & V_49 -> V_14 ,
& V_49 -> type , V_62 , 0 ) ;
} else {
struct V_10 * V_63 , * V_64 ;
V_63 = F_16 ( sizeof( struct V_10 ) ,
V_45 ) ;
if ( ! V_63 )
return - V_46 ;
V_51 = true ;
while ( V_4 -> V_8 < V_4 -> V_65 ) {
V_64 = F_2 ( V_4 -> V_61 ,
& V_4 -> V_8 ,
V_4 -> V_65 ,
& V_49 -> V_14 ,
& V_49 -> type ,
V_62 , 0 ) ;
if ( ! F_6 ( V_64 ) )
continue;
V_63 -> V_66 = V_64 -> V_66 ;
V_63 -> V_67 +=
V_64 -> V_67 ;
V_63 -> V_68 += V_64 -> V_68 ;
V_50 = F_8 ( V_63 , V_64 ) ;
if ( V_50 )
goto V_69;
}
V_49 -> V_14 = 0 ;
V_18 = V_63 ;
}
}
if ( ! F_6 ( V_18 ) ) {
V_50 = 0 ;
goto V_69;
}
V_50 = F_4 ( V_18 ) - V_24 ;
V_49 -> V_70 = F_7 ( V_18 , NULL , 0 ) ;
V_49 -> V_71 = F_9 ( V_50 + V_49 -> V_70 + 1 , V_45 ) ;
if ( V_49 -> V_71 == NULL ) {
V_50 = - V_46 ;
goto V_69;
}
memcpy ( V_49 -> V_71 , ( char * ) F_13 ( V_18 ) + V_24 ,
V_50 ) ;
F_7 ( V_18 , V_49 -> V_71 + V_50 ,
V_49 -> V_70 + 1 ) ;
V_69:
if ( V_51 ) {
F_11 ( V_18 -> V_47 ) ;
F_11 ( V_18 ) ;
}
return V_50 ;
}
static T_4 F_17 ( struct V_10 * V_18 ,
struct V_48 * V_49 )
{
char * V_72 ;
T_4 V_73 ;
V_72 = F_18 ( V_74 , V_25 L_3 ,
V_49 -> time . V_26 ,
V_49 -> time . V_27 / 1000 ,
V_49 -> V_22 ? 'C' : 'D' ) ;
F_19 ( ! V_72 ) ;
V_73 = V_72 ? strlen ( V_72 ) : 0 ;
F_20 ( V_18 , V_72 , V_73 ) ;
F_11 ( V_72 ) ;
return V_73 ;
}
static int T_5 F_21 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = V_49 -> V_2 -> V_5 ;
struct V_10 * V_18 ;
T_4 V_50 , V_75 ;
if ( V_49 -> type == V_56 ) {
if ( ! V_4 -> V_55 )
return - V_46 ;
F_20 ( V_4 -> V_55 , V_49 -> V_71 , V_49 -> V_50 ) ;
return 0 ;
} else if ( V_49 -> type == V_62 ) {
int V_76 ;
if ( ! V_4 -> V_61 )
return - V_46 ;
if ( V_4 -> V_59 & V_60 )
V_76 = F_22 () ;
else
V_76 = 0 ;
F_20 ( V_4 -> V_61 [ V_76 ] , V_49 -> V_71 ,
V_49 -> V_50 ) ;
return 0 ;
} else if ( V_49 -> type == V_58 ) {
F_23 ( L_4 , V_77 ) ;
return - V_78 ;
}
if ( V_49 -> type != V_54 )
return - V_78 ;
if ( V_49 -> V_79 != V_80 &&
V_49 -> V_79 != V_81 )
return - V_78 ;
if ( V_49 -> V_79 == V_80 && ! V_4 -> V_82 )
return - V_78 ;
if ( V_49 -> V_83 != 1 )
return - V_84 ;
if ( ! V_4 -> V_53 )
return - V_84 ;
V_18 = V_4 -> V_53 [ V_4 -> V_85 ] ;
V_75 = F_17 ( V_18 , V_49 ) ;
V_50 = V_49 -> V_50 ;
if ( V_50 + V_75 > V_18 -> V_86 )
V_50 = V_18 -> V_86 - V_75 ;
F_20 ( V_18 , V_49 -> V_71 , V_50 ) ;
V_4 -> V_85 = ( V_4 -> V_85 + 1 ) % V_4 -> V_52 ;
return 0 ;
}
static int T_5 F_24 ( struct V_48 * V_49 ,
const char T_6 * V_71 )
{
if ( V_49 -> type == V_58 ) {
struct V_3 * V_4 = V_49 -> V_2 -> V_5 ;
if ( ! V_4 -> V_57 )
return - V_46 ;
return F_25 ( V_4 -> V_57 , V_71 , V_49 -> V_50 ) ;
}
return - V_78 ;
}
static int F_26 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = V_49 -> V_2 -> V_5 ;
struct V_10 * V_18 ;
switch ( V_49 -> type ) {
case V_54 :
if ( V_49 -> V_14 >= V_4 -> V_52 )
return - V_78 ;
V_18 = V_4 -> V_53 [ V_49 -> V_14 ] ;
break;
case V_56 :
V_18 = V_4 -> V_55 ;
break;
case V_62 :
if ( V_49 -> V_14 >= V_4 -> V_65 )
return - V_78 ;
V_18 = V_4 -> V_61 [ V_49 -> V_14 ] ;
break;
case V_58 :
V_18 = V_4 -> V_57 ;
break;
default:
return - V_78 ;
}
F_14 ( V_18 ) ;
F_15 ( V_18 ) ;
return 0 ;
}
static void F_27 ( struct V_3 * V_4 )
{
int V_19 ;
if ( V_4 -> V_53 ) {
for ( V_19 = 0 ; V_19 < V_4 -> V_52 ; V_19 ++ )
F_28 ( V_4 -> V_53 [ V_19 ] ) ;
F_11 ( V_4 -> V_53 ) ;
V_4 -> V_52 = 0 ;
}
if ( V_4 -> V_61 ) {
for ( V_19 = 0 ; V_19 < V_4 -> V_65 ; V_19 ++ )
F_28 ( V_4 -> V_61 [ V_19 ] ) ;
F_11 ( V_4 -> V_61 ) ;
V_4 -> V_65 = 0 ;
}
}
static int F_29 ( const char * V_87 ,
struct V_88 * V_89 , struct V_3 * V_4 ,
struct V_10 * * * V_11 ,
T_7 * V_90 , T_4 V_91 ,
T_3 V_43 ,
unsigned int * V_92 , T_8 V_93 , T_8 V_59 )
{
int V_94 = - V_46 ;
int V_19 ;
T_4 V_95 ;
struct V_10 * * V_96 ;
if ( V_91 == 0 || V_43 == 0 ) {
* V_92 = 0 ;
return 0 ;
}
if ( V_43 < 0 ) {
if ( * V_92 == 0 )
return 0 ;
V_43 = V_91 / * V_92 ;
if ( V_43 == 0 ) {
F_30 ( V_89 , L_5 ,
V_87 , V_91 , * V_92 ) ;
goto V_97;
}
} else {
* V_92 = V_91 / V_43 ;
if ( * V_92 == 0 ) {
F_30 ( V_89 , L_6 ,
V_87 , V_91 , V_43 ) ;
goto V_97;
}
}
if ( * V_90 + V_91 - V_4 -> V_98 > V_4 -> V_50 ) {
F_30 ( V_89 , L_7 ,
V_87 ,
V_91 , ( unsigned long long ) * V_90 ,
V_4 -> V_50 , ( unsigned long long ) V_4 -> V_98 ) ;
goto V_97;
}
V_95 = V_91 / * V_92 ;
if ( ! V_95 ) {
F_30 ( V_89 , L_8 , V_87 ) ;
goto V_97;
}
V_96 = F_31 ( * V_92 , sizeof( * * V_11 ) , V_45 ) ;
if ( ! V_96 )
goto V_97;
for ( V_19 = 0 ; V_19 < * V_92 ; V_19 ++ ) {
V_96 [ V_19 ] = F_32 ( * V_90 , V_95 , V_93 ,
& V_4 -> V_66 ,
V_4 -> V_99 , V_59 ) ;
if ( F_33 ( V_96 [ V_19 ] ) ) {
V_94 = F_34 ( V_96 [ V_19 ] ) ;
F_30 ( V_89 , L_9 ,
V_87 , V_43 ,
( unsigned long long ) * V_90 , V_94 ) ;
while ( V_19 > 0 ) {
V_19 -- ;
F_28 ( V_96 [ V_19 ] ) ;
}
F_11 ( V_96 ) ;
goto V_97;
}
* V_90 += V_95 ;
}
* V_11 = V_96 ;
return 0 ;
V_97:
* V_92 = 0 ;
return V_94 ;
}
static int F_35 ( const char * V_87 ,
struct V_88 * V_89 , struct V_3 * V_4 ,
struct V_10 * * V_18 ,
T_7 * V_90 , T_4 V_100 , T_8 V_93 )
{
if ( ! V_100 )
return 0 ;
if ( * V_90 + V_100 - V_4 -> V_98 > V_4 -> V_50 ) {
F_30 ( V_89 , L_7 ,
V_87 , V_100 , ( unsigned long long ) * V_90 ,
V_4 -> V_50 , ( unsigned long long ) V_4 -> V_98 ) ;
return - V_46 ;
}
* V_18 = F_32 ( * V_90 , V_100 , V_93 , & V_4 -> V_66 ,
V_4 -> V_99 , 0 ) ;
if ( F_33 ( * V_18 ) ) {
int V_94 = F_34 ( * V_18 ) ;
F_30 ( V_89 , L_9 ,
V_87 , V_100 , ( unsigned long long ) * V_90 , V_94 ) ;
return V_94 ;
}
F_15 ( * V_18 ) ;
* V_90 += V_100 ;
return 0 ;
}
static int F_36 ( struct V_101 * V_102 ,
const char * V_103 , T_8 * V_104 )
{
T_8 V_105 = 0 ;
int V_106 ;
V_106 = F_37 ( V_102 -> V_89 . V_107 , V_103 , & V_105 ) ;
if ( V_106 < 0 && V_106 != - V_78 ) {
F_30 ( & V_102 -> V_89 , L_10 ,
V_103 , V_106 ) ;
return V_106 ;
}
if ( V_105 > V_108 ) {
F_30 ( & V_102 -> V_89 , L_11 , V_103 , V_105 ) ;
return - V_109 ;
}
* V_104 = V_105 ;
return 0 ;
}
static int F_38 ( struct V_101 * V_102 ,
struct V_110 * V_111 )
{
struct V_112 * V_107 = V_102 -> V_89 . V_107 ;
struct V_113 * V_114 ;
T_8 V_104 ;
int V_106 ;
F_39 ( & V_102 -> V_89 , L_12 ) ;
V_114 = F_40 ( V_102 , V_115 , 0 ) ;
if ( ! V_114 ) {
F_30 ( & V_102 -> V_89 ,
L_13 ) ;
return - V_78 ;
}
V_111 -> V_116 = F_41 ( V_114 ) ;
V_111 -> V_117 = V_114 -> V_118 ;
V_111 -> V_119 = F_42 ( V_107 , L_14 ) ;
V_111 -> V_82 = ! F_42 ( V_107 , L_15 ) ;
#define F_43 ( V_87 , T_9 ) { \
ret = ramoops_parse_dt_size(pdev, name, &value); \
if (ret < 0) \
return ret; \
field = value; \
}
F_43 ( L_16 , V_111 -> V_43 ) ;
F_43 ( L_17 , V_111 -> V_120 ) ;
F_43 ( L_18 , V_111 -> V_121 ) ;
F_43 ( L_19 , V_111 -> V_122 ) ;
F_43 ( L_20 , V_111 -> V_66 . V_123 ) ;
F_43 ( L_21 , V_111 -> V_59 ) ;
#undef F_43
return 0 ;
}
static int F_44 ( struct V_101 * V_102 )
{
struct V_88 * V_89 = & V_102 -> V_89 ;
struct V_110 * V_111 = V_89 -> V_124 ;
struct V_3 * V_4 = & V_125 ;
T_4 V_126 ;
T_7 V_90 ;
int V_94 = - V_78 ;
if ( F_45 ( V_89 ) && ! V_111 ) {
V_111 = F_46 ( & V_102 -> V_89 , sizeof( * V_111 ) , V_45 ) ;
if ( ! V_111 ) {
F_47 ( L_22 ) ;
V_94 = - V_46 ;
goto V_127;
}
V_94 = F_38 ( V_102 , V_111 ) ;
if ( V_94 < 0 )
goto V_127;
}
if ( V_4 -> V_52 ) {
F_47 ( L_23 ) ;
goto V_127;
}
if ( ! V_111 ) {
F_47 ( L_24 ) ;
goto V_127;
}
if ( ! V_111 -> V_116 || ( ! V_111 -> V_43 && ! V_111 -> V_120 &&
! V_111 -> V_121 && ! V_111 -> V_122 ) ) {
F_47 ( L_25
L_26 ) ;
goto V_127;
}
if ( V_111 -> V_43 && ! F_48 ( V_111 -> V_43 ) )
V_111 -> V_43 = F_49 ( V_111 -> V_43 ) ;
if ( V_111 -> V_120 && ! F_48 ( V_111 -> V_120 ) )
V_111 -> V_120 = F_49 ( V_111 -> V_120 ) ;
if ( V_111 -> V_121 && ! F_48 ( V_111 -> V_121 ) )
V_111 -> V_121 = F_49 ( V_111 -> V_121 ) ;
if ( V_111 -> V_122 && ! F_48 ( V_111 -> V_122 ) )
V_111 -> V_122 = F_49 ( V_111 -> V_122 ) ;
V_4 -> V_50 = V_111 -> V_116 ;
V_4 -> V_98 = V_111 -> V_117 ;
V_4 -> V_99 = V_111 -> V_119 ;
V_4 -> V_43 = V_111 -> V_43 ;
V_4 -> V_120 = V_111 -> V_120 ;
V_4 -> V_121 = V_111 -> V_121 ;
V_4 -> V_122 = V_111 -> V_122 ;
V_4 -> V_82 = V_111 -> V_82 ;
V_4 -> V_59 = V_111 -> V_59 ;
V_4 -> V_66 = V_111 -> V_66 ;
V_90 = V_4 -> V_98 ;
V_126 = V_4 -> V_50 - V_4 -> V_120 - V_4 -> V_121
- V_4 -> V_122 ;
V_94 = F_29 ( L_27 , V_89 , V_4 , & V_4 -> V_53 , & V_90 ,
V_126 , V_4 -> V_43 ,
& V_4 -> V_52 , 0 , 0 ) ;
if ( V_94 )
goto V_127;
V_94 = F_35 ( L_28 , V_89 , V_4 , & V_4 -> V_55 , & V_90 ,
V_4 -> V_120 , 0 ) ;
if ( V_94 )
goto V_128;
V_4 -> V_65 = ( V_4 -> V_59 & V_60 )
? V_129
: 1 ;
V_94 = F_29 ( L_29 , V_89 , V_4 , & V_4 -> V_61 , & V_90 ,
V_4 -> V_121 , - 1 ,
& V_4 -> V_65 , V_130 ,
( V_4 -> V_59 & V_60 )
? V_131 : 0 ) ;
if ( V_94 )
goto V_132;
V_94 = F_35 ( L_30 , V_89 , V_4 , & V_4 -> V_57 , & V_90 ,
V_4 -> V_122 , 0 ) ;
if ( V_94 )
goto V_133;
V_4 -> V_134 . V_5 = V_4 ;
if ( V_4 -> V_120 )
V_4 -> V_134 . V_135 = 1024 ;
V_4 -> V_134 . V_135 = V_13 ( V_4 -> V_43 , V_4 -> V_134 . V_135 ) ;
V_4 -> V_134 . V_71 = F_9 ( V_4 -> V_134 . V_135 , V_45 ) ;
if ( ! V_4 -> V_134 . V_71 ) {
F_47 ( L_31 ) ;
V_94 = - V_46 ;
goto V_136;
}
F_50 ( & V_4 -> V_134 . V_137 ) ;
V_4 -> V_134 . V_59 = V_138 ;
if ( V_4 -> V_120 )
V_4 -> V_134 . V_59 |= V_139 ;
if ( V_4 -> V_121 )
V_4 -> V_134 . V_59 |= V_140 ;
if ( V_4 -> V_122 )
V_4 -> V_134 . V_59 |= V_141 ;
V_94 = F_51 ( & V_4 -> V_134 ) ;
if ( V_94 ) {
F_47 ( L_32 ) ;
goto V_142;
}
V_116 = V_111 -> V_116 ;
V_117 = V_111 -> V_117 ;
V_43 = V_111 -> V_43 ;
V_82 = V_111 -> V_82 ;
V_143 = V_111 -> V_120 ;
V_144 = V_111 -> V_122 ;
V_145 = V_111 -> V_121 ;
F_52 ( L_33 ,
V_4 -> V_50 , ( unsigned long long ) V_4 -> V_98 ,
V_4 -> V_66 . V_123 , V_4 -> V_66 . V_146 ) ;
return 0 ;
V_142:
F_11 ( V_4 -> V_134 . V_71 ) ;
V_136:
V_4 -> V_134 . V_135 = 0 ;
F_28 ( V_4 -> V_57 ) ;
V_133:
V_132:
F_28 ( V_4 -> V_55 ) ;
V_128:
F_27 ( V_4 ) ;
V_127:
return V_94 ;
}
static int F_53 ( struct V_101 * V_102 )
{
struct V_3 * V_4 = & V_125 ;
F_54 ( & V_4 -> V_134 ) ;
F_11 ( V_4 -> V_134 . V_71 ) ;
V_4 -> V_134 . V_135 = 0 ;
F_28 ( V_4 -> V_57 ) ;
F_28 ( V_4 -> V_55 ) ;
F_27 ( V_4 ) ;
return 0 ;
}
static void F_55 ( void )
{
if ( ! V_116 )
return;
F_52 ( L_34 ) ;
V_147 = F_16 ( sizeof( * V_147 ) , V_45 ) ;
if ( ! V_147 ) {
F_52 ( L_35 ) ;
return;
}
V_147 -> V_116 = V_116 ;
V_147 -> V_117 = V_117 ;
V_147 -> V_119 = V_119 ;
V_147 -> V_43 = V_43 ;
V_147 -> V_120 = V_143 ;
V_147 -> V_121 = V_145 ;
V_147 -> V_122 = V_144 ;
V_147 -> V_82 = V_82 ;
V_147 -> V_59 = V_60 ;
V_147 -> V_66 . V_123 = V_148 == 1 ? 16 : V_148 ;
V_149 = F_56 ( NULL , L_36 , - 1 ,
V_147 , sizeof( struct V_110 ) ) ;
if ( F_33 ( V_149 ) ) {
F_52 ( L_37 ,
F_34 ( V_149 ) ) ;
}
}
static int T_10 F_57 ( void )
{
F_55 () ;
return F_58 ( & V_150 ) ;
}
static void T_11 F_59 ( void )
{
F_60 ( & V_150 ) ;
F_61 ( V_149 ) ;
F_11 ( V_147 ) ;
}
