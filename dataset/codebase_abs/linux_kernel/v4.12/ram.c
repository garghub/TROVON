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
bool V_22 )
{
char * V_72 ;
struct V_21 V_73 ;
T_4 V_74 ;
if ( F_18 ( & V_73 ) ) {
V_73 . V_26 = 0 ;
V_73 . V_27 = 0 ;
}
V_72 = F_19 ( V_75 , V_25 L_3 ,
( long ) V_73 . V_26 , ( long ) ( V_73 . V_27 / 1000 ) ,
V_22 ? 'C' : 'D' ) ;
F_20 ( ! V_72 ) ;
V_74 = V_72 ? strlen ( V_72 ) : 0 ;
F_21 ( V_18 , V_72 , V_74 ) ;
F_11 ( V_72 ) ;
return V_74 ;
}
static int T_5 F_22 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = V_49 -> V_2 -> V_5 ;
struct V_10 * V_18 ;
T_4 V_50 , V_76 ;
if ( V_49 -> type == V_56 ) {
if ( ! V_4 -> V_55 )
return - V_46 ;
F_21 ( V_4 -> V_55 , V_49 -> V_71 , V_49 -> V_50 ) ;
return 0 ;
} else if ( V_49 -> type == V_62 ) {
int V_77 ;
if ( ! V_4 -> V_61 )
return - V_46 ;
if ( V_4 -> V_59 & V_60 )
V_77 = F_23 () ;
else
V_77 = 0 ;
F_21 ( V_4 -> V_61 [ V_77 ] , V_49 -> V_71 ,
V_49 -> V_50 ) ;
return 0 ;
} else if ( V_49 -> type == V_58 ) {
F_24 ( L_4 , V_78 ) ;
return - V_79 ;
}
if ( V_49 -> type != V_54 )
return - V_79 ;
if ( V_49 -> V_80 != V_81 &&
V_49 -> V_80 != V_82 )
return - V_79 ;
if ( V_49 -> V_80 == V_81 && ! V_4 -> V_83 )
return - V_79 ;
if ( V_49 -> V_84 != 1 )
return - V_85 ;
if ( ! V_4 -> V_53 )
return - V_85 ;
V_18 = V_4 -> V_53 [ V_4 -> V_86 ] ;
V_76 = F_17 ( V_18 , V_49 -> V_22 ) ;
V_50 = V_49 -> V_50 ;
if ( V_50 + V_76 > V_18 -> V_87 )
V_50 = V_18 -> V_87 - V_76 ;
F_21 ( V_18 , V_49 -> V_71 , V_50 ) ;
V_4 -> V_86 = ( V_4 -> V_86 + 1 ) % V_4 -> V_52 ;
return 0 ;
}
static int T_5 F_25 ( struct V_48 * V_49 ,
const char T_6 * V_71 )
{
if ( V_49 -> type == V_58 ) {
struct V_3 * V_4 = V_49 -> V_2 -> V_5 ;
if ( ! V_4 -> V_57 )
return - V_46 ;
return F_26 ( V_4 -> V_57 , V_71 , V_49 -> V_50 ) ;
}
return - V_79 ;
}
static int F_27 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = V_49 -> V_2 -> V_5 ;
struct V_10 * V_18 ;
switch ( V_49 -> type ) {
case V_54 :
if ( V_49 -> V_14 >= V_4 -> V_52 )
return - V_79 ;
V_18 = V_4 -> V_53 [ V_49 -> V_14 ] ;
break;
case V_56 :
V_18 = V_4 -> V_55 ;
break;
case V_62 :
if ( V_49 -> V_14 >= V_4 -> V_65 )
return - V_79 ;
V_18 = V_4 -> V_61 [ V_49 -> V_14 ] ;
break;
case V_58 :
V_18 = V_4 -> V_57 ;
break;
default:
return - V_79 ;
}
F_14 ( V_18 ) ;
F_15 ( V_18 ) ;
return 0 ;
}
static void F_28 ( struct V_3 * V_4 )
{
int V_19 ;
if ( V_4 -> V_53 ) {
for ( V_19 = 0 ; V_19 < V_4 -> V_52 ; V_19 ++ )
F_29 ( V_4 -> V_53 [ V_19 ] ) ;
F_11 ( V_4 -> V_53 ) ;
V_4 -> V_52 = 0 ;
}
if ( V_4 -> V_61 ) {
for ( V_19 = 0 ; V_19 < V_4 -> V_65 ; V_19 ++ )
F_29 ( V_4 -> V_61 [ V_19 ] ) ;
F_11 ( V_4 -> V_61 ) ;
V_4 -> V_65 = 0 ;
}
}
static int F_30 ( const char * V_88 ,
struct V_89 * V_90 , struct V_3 * V_4 ,
struct V_10 * * * V_11 ,
T_7 * V_91 , T_4 V_92 ,
T_3 V_43 ,
unsigned int * V_93 , T_8 V_94 , T_8 V_59 )
{
int V_95 = - V_46 ;
int V_19 ;
T_4 V_96 ;
struct V_10 * * V_97 ;
if ( V_92 == 0 || V_43 == 0 ) {
* V_93 = 0 ;
return 0 ;
}
if ( V_43 < 0 ) {
if ( * V_93 == 0 )
return 0 ;
V_43 = V_92 / * V_93 ;
if ( V_43 == 0 ) {
F_31 ( V_90 , L_5 ,
V_88 , V_92 , * V_93 ) ;
goto V_98;
}
} else {
* V_93 = V_92 / V_43 ;
if ( * V_93 == 0 ) {
F_31 ( V_90 , L_6 ,
V_88 , V_92 , V_43 ) ;
goto V_98;
}
}
if ( * V_91 + V_92 - V_4 -> V_99 > V_4 -> V_50 ) {
F_31 ( V_90 , L_7 ,
V_88 ,
V_92 , ( unsigned long long ) * V_91 ,
V_4 -> V_50 , ( unsigned long long ) V_4 -> V_99 ) ;
goto V_98;
}
V_96 = V_92 / * V_93 ;
if ( ! V_96 ) {
F_31 ( V_90 , L_8 , V_88 ) ;
goto V_98;
}
V_97 = F_32 ( * V_93 , sizeof( * * V_11 ) , V_45 ) ;
if ( ! V_97 )
goto V_98;
for ( V_19 = 0 ; V_19 < * V_93 ; V_19 ++ ) {
V_97 [ V_19 ] = F_33 ( * V_91 , V_96 , V_94 ,
& V_4 -> V_66 ,
V_4 -> V_100 , V_59 ) ;
if ( F_34 ( V_97 [ V_19 ] ) ) {
V_95 = F_35 ( V_97 [ V_19 ] ) ;
F_31 ( V_90 , L_9 ,
V_88 , V_43 ,
( unsigned long long ) * V_91 , V_95 ) ;
while ( V_19 > 0 ) {
V_19 -- ;
F_29 ( V_97 [ V_19 ] ) ;
}
F_11 ( V_97 ) ;
goto V_98;
}
* V_91 += V_96 ;
}
* V_11 = V_97 ;
return 0 ;
V_98:
* V_93 = 0 ;
return V_95 ;
}
static int F_36 ( const char * V_88 ,
struct V_89 * V_90 , struct V_3 * V_4 ,
struct V_10 * * V_18 ,
T_7 * V_91 , T_4 V_101 , T_8 V_94 )
{
if ( ! V_101 )
return 0 ;
if ( * V_91 + V_101 - V_4 -> V_99 > V_4 -> V_50 ) {
F_31 ( V_90 , L_7 ,
V_88 , V_101 , ( unsigned long long ) * V_91 ,
V_4 -> V_50 , ( unsigned long long ) V_4 -> V_99 ) ;
return - V_46 ;
}
* V_18 = F_33 ( * V_91 , V_101 , V_94 , & V_4 -> V_66 ,
V_4 -> V_100 , 0 ) ;
if ( F_34 ( * V_18 ) ) {
int V_95 = F_35 ( * V_18 ) ;
F_31 ( V_90 , L_9 ,
V_88 , V_101 , ( unsigned long long ) * V_91 , V_95 ) ;
return V_95 ;
}
F_15 ( * V_18 ) ;
* V_91 += V_101 ;
return 0 ;
}
static int F_37 ( struct V_102 * V_103 ,
const char * V_104 , T_8 * V_105 )
{
T_8 V_106 = 0 ;
int V_107 ;
V_107 = F_38 ( V_103 -> V_90 . V_108 , V_104 , & V_106 ) ;
if ( V_107 < 0 && V_107 != - V_79 ) {
F_31 ( & V_103 -> V_90 , L_10 ,
V_104 , V_107 ) ;
return V_107 ;
}
if ( V_106 > V_109 ) {
F_31 ( & V_103 -> V_90 , L_11 , V_104 , V_106 ) ;
return - V_110 ;
}
* V_105 = V_106 ;
return 0 ;
}
static int F_39 ( struct V_102 * V_103 ,
struct V_111 * V_112 )
{
struct V_113 * V_108 = V_103 -> V_90 . V_108 ;
struct V_114 * V_115 ;
T_8 V_105 ;
int V_107 ;
F_40 ( & V_103 -> V_90 , L_12 ) ;
V_115 = F_41 ( V_103 , V_116 , 0 ) ;
if ( ! V_115 ) {
F_31 ( & V_103 -> V_90 ,
L_13 ) ;
return - V_79 ;
}
V_112 -> V_117 = F_42 ( V_115 ) ;
V_112 -> V_118 = V_115 -> V_119 ;
V_112 -> V_120 = F_43 ( V_108 , L_14 ) ;
V_112 -> V_83 = ! F_43 ( V_108 , L_15 ) ;
#define F_44 ( V_88 , T_9 ) { \
ret = ramoops_parse_dt_size(pdev, name, &value); \
if (ret < 0) \
return ret; \
field = value; \
}
F_44 ( L_16 , V_112 -> V_43 ) ;
F_44 ( L_17 , V_112 -> V_121 ) ;
F_44 ( L_18 , V_112 -> V_122 ) ;
F_44 ( L_19 , V_112 -> V_123 ) ;
F_44 ( L_20 , V_112 -> V_66 . V_124 ) ;
F_44 ( L_21 , V_112 -> V_59 ) ;
#undef F_44
return 0 ;
}
static int F_45 ( struct V_102 * V_103 )
{
struct V_89 * V_90 = & V_103 -> V_90 ;
struct V_111 * V_112 = V_90 -> V_125 ;
struct V_3 * V_4 = & V_126 ;
T_4 V_127 ;
T_7 V_91 ;
int V_95 = - V_79 ;
if ( F_46 ( V_90 ) && ! V_112 ) {
V_112 = F_47 ( & V_103 -> V_90 , sizeof( * V_112 ) , V_45 ) ;
if ( ! V_112 ) {
F_48 ( L_22 ) ;
V_95 = - V_46 ;
goto V_128;
}
V_95 = F_39 ( V_103 , V_112 ) ;
if ( V_95 < 0 )
goto V_128;
}
if ( V_4 -> V_52 ) {
F_48 ( L_23 ) ;
goto V_128;
}
if ( ! V_112 ) {
F_48 ( L_24 ) ;
goto V_128;
}
if ( ! V_112 -> V_117 || ( ! V_112 -> V_43 && ! V_112 -> V_121 &&
! V_112 -> V_122 && ! V_112 -> V_123 ) ) {
F_48 ( L_25
L_26 ) ;
goto V_128;
}
if ( V_112 -> V_43 && ! F_49 ( V_112 -> V_43 ) )
V_112 -> V_43 = F_50 ( V_112 -> V_43 ) ;
if ( V_112 -> V_121 && ! F_49 ( V_112 -> V_121 ) )
V_112 -> V_121 = F_50 ( V_112 -> V_121 ) ;
if ( V_112 -> V_122 && ! F_49 ( V_112 -> V_122 ) )
V_112 -> V_122 = F_50 ( V_112 -> V_122 ) ;
if ( V_112 -> V_123 && ! F_49 ( V_112 -> V_123 ) )
V_112 -> V_123 = F_50 ( V_112 -> V_123 ) ;
V_4 -> V_50 = V_112 -> V_117 ;
V_4 -> V_99 = V_112 -> V_118 ;
V_4 -> V_100 = V_112 -> V_120 ;
V_4 -> V_43 = V_112 -> V_43 ;
V_4 -> V_121 = V_112 -> V_121 ;
V_4 -> V_122 = V_112 -> V_122 ;
V_4 -> V_123 = V_112 -> V_123 ;
V_4 -> V_83 = V_112 -> V_83 ;
V_4 -> V_59 = V_112 -> V_59 ;
V_4 -> V_66 = V_112 -> V_66 ;
V_91 = V_4 -> V_99 ;
V_127 = V_4 -> V_50 - V_4 -> V_121 - V_4 -> V_122
- V_4 -> V_123 ;
V_95 = F_30 ( L_27 , V_90 , V_4 , & V_4 -> V_53 , & V_91 ,
V_127 , V_4 -> V_43 ,
& V_4 -> V_52 , 0 , 0 ) ;
if ( V_95 )
goto V_128;
V_95 = F_36 ( L_28 , V_90 , V_4 , & V_4 -> V_55 , & V_91 ,
V_4 -> V_121 , 0 ) ;
if ( V_95 )
goto V_129;
V_4 -> V_65 = ( V_4 -> V_59 & V_60 )
? V_130
: 1 ;
V_95 = F_30 ( L_29 , V_90 , V_4 , & V_4 -> V_61 , & V_91 ,
V_4 -> V_122 , - 1 ,
& V_4 -> V_65 , V_131 ,
( V_4 -> V_59 & V_60 )
? V_132 : 0 ) ;
if ( V_95 )
goto V_133;
V_95 = F_36 ( L_30 , V_90 , V_4 , & V_4 -> V_57 , & V_91 ,
V_4 -> V_123 , 0 ) ;
if ( V_95 )
goto V_134;
V_4 -> V_135 . V_5 = V_4 ;
if ( V_4 -> V_121 )
V_4 -> V_135 . V_136 = 1024 ;
V_4 -> V_135 . V_136 = V_13 ( V_4 -> V_43 , V_4 -> V_135 . V_136 ) ;
V_4 -> V_135 . V_71 = F_9 ( V_4 -> V_135 . V_136 , V_45 ) ;
if ( ! V_4 -> V_135 . V_71 ) {
F_48 ( L_31 ) ;
V_95 = - V_46 ;
goto V_137;
}
F_51 ( & V_4 -> V_135 . V_138 ) ;
V_4 -> V_135 . V_59 = V_139 ;
if ( V_4 -> V_121 )
V_4 -> V_135 . V_59 |= V_140 ;
if ( V_4 -> V_122 )
V_4 -> V_135 . V_59 |= V_141 ;
if ( V_4 -> V_123 )
V_4 -> V_135 . V_59 |= V_142 ;
V_95 = F_52 ( & V_4 -> V_135 ) ;
if ( V_95 ) {
F_48 ( L_32 ) ;
goto V_143;
}
V_117 = V_112 -> V_117 ;
V_118 = V_112 -> V_118 ;
V_43 = V_112 -> V_43 ;
V_83 = V_112 -> V_83 ;
V_144 = V_112 -> V_121 ;
V_145 = V_112 -> V_123 ;
V_146 = V_112 -> V_122 ;
F_53 ( L_33 ,
V_4 -> V_50 , ( unsigned long long ) V_4 -> V_99 ,
V_4 -> V_66 . V_124 , V_4 -> V_66 . V_147 ) ;
return 0 ;
V_143:
F_11 ( V_4 -> V_135 . V_71 ) ;
V_137:
V_4 -> V_135 . V_136 = 0 ;
F_29 ( V_4 -> V_57 ) ;
V_134:
V_133:
F_29 ( V_4 -> V_55 ) ;
V_129:
F_28 ( V_4 ) ;
V_128:
return V_95 ;
}
static int F_54 ( struct V_102 * V_103 )
{
struct V_3 * V_4 = & V_126 ;
F_55 ( & V_4 -> V_135 ) ;
F_11 ( V_4 -> V_135 . V_71 ) ;
V_4 -> V_135 . V_136 = 0 ;
F_29 ( V_4 -> V_57 ) ;
F_29 ( V_4 -> V_55 ) ;
F_28 ( V_4 ) ;
return 0 ;
}
static void F_56 ( void )
{
if ( ! V_117 )
return;
F_53 ( L_34 ) ;
V_148 = F_16 ( sizeof( * V_148 ) , V_45 ) ;
if ( ! V_148 ) {
F_53 ( L_35 ) ;
return;
}
V_148 -> V_117 = V_117 ;
V_148 -> V_118 = V_118 ;
V_148 -> V_120 = V_120 ;
V_148 -> V_43 = V_43 ;
V_148 -> V_121 = V_144 ;
V_148 -> V_122 = V_146 ;
V_148 -> V_123 = V_145 ;
V_148 -> V_83 = V_83 ;
V_148 -> V_59 = V_60 ;
V_148 -> V_66 . V_124 = V_149 == 1 ? 16 : V_149 ;
V_150 = F_57 ( NULL , L_36 , - 1 ,
V_148 , sizeof( struct V_111 ) ) ;
if ( F_34 ( V_150 ) ) {
F_53 ( L_37 ,
F_35 ( V_150 ) ) ;
}
}
static int T_10 F_58 ( void )
{
F_56 () ;
return F_59 ( & V_151 ) ;
}
static void T_11 F_60 ( void )
{
F_61 ( & V_151 ) ;
F_62 ( V_150 ) ;
F_11 ( V_148 ) ;
}
