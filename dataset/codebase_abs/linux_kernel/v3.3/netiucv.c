static inline int F_1 ( T_1 * V_1 , int V_2 )
{
return ( V_2 <= V_1 -> V_2 ) ;
}
static inline void F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_4 ( 0 , & V_6 -> V_7 ) ;
F_5 ( V_4 ) ;
}
static inline int F_6 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_7 ( V_4 ) ;
return F_8 ( 0 , & V_6 -> V_7 ) ;
}
static char * F_9 ( char * V_8 , int V_9 )
{
static char V_10 [ 17 ] ;
char * V_11 = V_10 ;
memcpy ( V_10 , V_8 , V_9 ) ;
V_10 [ V_9 ] = '\0' ;
while ( * V_11 && ( ( V_11 - V_10 ) < V_9 ) && ( ! isspace ( * V_11 ) ) )
V_11 ++ ;
* V_11 = '\0' ;
return V_10 ;
}
static char * F_10 ( struct V_12 * V_13 )
{
static char V_14 [ 9 ] ;
static char V_15 [ 17 ] ;
static char V_16 [ 100 ] ;
if ( memcmp ( V_13 -> V_17 , V_18 , 16 ) ) {
V_14 [ 8 ] = '\0' ;
V_15 [ 16 ] = '\0' ;
memcpy ( V_14 , V_13 -> V_19 , 8 ) ;
memcpy ( V_14 , F_9 ( V_14 , 8 ) , 8 ) ;
memcpy ( V_15 , V_13 -> V_17 , 16 ) ;
F_11 ( V_15 , 16 ) ;
memcpy ( V_15 , F_9 ( V_15 , 16 ) , 16 ) ;
sprintf ( V_16 , L_1 , V_14 , V_15 ) ;
return V_16 ;
} else
return F_9 ( V_13 -> V_19 , 8 ) ;
}
static void F_12 ( void )
{
if ( V_20 )
F_13 ( V_20 ) ;
if ( V_21 )
F_13 ( V_21 ) ;
if ( V_22 )
F_13 ( V_22 ) ;
}
static int F_14 ( void )
{
V_20 = F_15 ( V_23 ,
V_24 ,
V_25 ,
V_26 ) ;
V_21 = F_15 ( V_27 ,
V_28 ,
V_29 ,
V_30 ) ;
V_22 = F_15 ( V_31 ,
V_32 ,
V_33 ,
V_34 ) ;
if ( ( V_20 == NULL ) || ( V_21 == NULL ) ||
( V_22 == NULL ) ) {
F_12 () ;
return - V_35 ;
}
F_16 ( V_20 , & V_36 ) ;
F_17 ( V_20 , V_37 ) ;
F_16 ( V_21 , & V_36 ) ;
F_17 ( V_21 , V_38 ) ;
F_16 ( V_22 , & V_36 ) ;
F_17 ( V_22 , V_39 ) ;
return 0 ;
}
static void F_18 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_12 * V_13 = V_41 -> V_44 ;
struct V_45 V_46 ;
V_46 . V_13 = V_13 ;
V_46 . V_47 = V_43 ;
F_19 ( V_13 -> V_48 , V_49 , & V_46 ) ;
}
static void F_20 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_12 * V_13 = V_41 -> V_44 ;
struct V_45 V_46 ;
V_46 . V_13 = V_13 ;
V_46 . V_47 = V_43 ;
F_19 ( V_13 -> V_48 , V_50 , & V_46 ) ;
}
static void F_21 ( struct V_40 * V_41 , T_2 V_51 [ 16 ] )
{
struct V_12 * V_13 = V_41 -> V_44 ;
F_19 ( V_13 -> V_48 , V_52 , V_13 ) ;
}
static int F_22 ( struct V_40 * V_41 ,
T_2 V_53 [ 8 ] , T_2 V_51 [ 16 ] )
{
struct V_12 * V_13 = V_41 -> V_44 ;
struct V_45 V_46 ;
static char V_54 [ 9 ] ;
static char V_15 [ 17 ] ;
int V_55 ;
V_55 = - V_56 ;
memcpy ( V_54 , F_9 ( V_53 , 8 ) , 8 ) ;
memcpy ( V_15 , V_51 , 16 ) ;
F_11 ( V_15 , 16 ) ;
F_23 ( & V_57 ) ;
F_24 (conn, &iucv_connection_list, list) {
if ( strncmp ( V_53 , V_13 -> V_19 , 8 ) ||
strncmp ( V_51 , V_13 -> V_17 , 16 ) )
continue;
V_13 -> V_41 = V_41 ;
V_46 . V_13 = V_13 ;
V_46 . V_47 = V_41 ;
F_19 ( V_13 -> V_48 , V_58 , & V_46 ) ;
V_55 = 0 ;
}
F_25 ( V_59 , 2 , L_2 ,
V_54 , F_9 ( V_15 , 16 ) ) ;
F_26 ( & V_57 ) ;
return V_55 ;
}
static void F_27 ( struct V_40 * V_41 , T_2 V_51 [ 16 ] )
{
struct V_12 * V_13 = V_41 -> V_44 ;
F_19 ( V_13 -> V_48 , V_60 , V_13 ) ;
}
static void F_28 ( struct V_40 * V_41 , T_2 V_51 [ 16 ] )
{
struct V_12 * V_13 = V_41 -> V_44 ;
F_19 ( V_13 -> V_48 , V_61 , V_13 ) ;
}
static void F_29 ( struct V_40 * V_41 , T_2 V_51 [ 16 ] )
{
struct V_12 * V_13 = V_41 -> V_44 ;
F_19 ( V_13 -> V_48 , V_62 , V_13 ) ;
}
static void F_30 ( T_3 * V_63 , int V_64 , void * V_65 )
{
}
static void F_31 ( struct V_12 * V_13 ,
struct V_66 * V_67 )
{
struct V_3 * V_4 = V_13 -> V_68 ;
struct V_5 * V_69 = F_3 ( V_4 ) ;
T_4 V_70 = 0 ;
F_32 ( V_67 , V_71 ) ;
V_67 -> V_4 = V_4 ;
V_67 -> V_72 = V_73 ;
V_67 -> V_74 = F_33 ( V_75 ) ;
while ( 1 ) {
struct V_66 * V_76 ;
struct V_77 * V_78 = (struct V_77 * ) V_67 -> V_47 ;
if ( ! V_78 -> V_79 )
break;
F_34 ( V_67 , V_71 ) ;
V_78 -> V_79 -= V_70 ;
V_70 += V_78 -> V_79 ;
V_78 -> V_79 -= V_71 ;
if ( F_35 ( V_67 ) < V_78 -> V_79 ) {
F_25 ( V_47 , 2 , L_3 ,
V_78 -> V_79 , F_35 ( V_67 ) ) ;
return;
}
F_32 ( V_67 , V_78 -> V_79 ) ;
F_36 ( V_67 ) ;
V_76 = F_37 ( V_67 -> V_9 ) ;
if ( ! V_76 ) {
F_38 ( V_47 , 2 ,
L_4 ) ;
V_69 -> V_80 . V_81 ++ ;
return;
}
F_39 ( V_67 , F_32 ( V_76 , V_67 -> V_9 ) ,
V_67 -> V_9 ) ;
F_36 ( V_76 ) ;
V_76 -> V_4 = V_67 -> V_4 ;
V_76 -> V_74 = V_67 -> V_74 ;
V_67 -> V_72 = V_82 ;
V_69 -> V_80 . V_83 ++ ;
V_69 -> V_80 . V_84 += V_76 -> V_9 ;
F_40 ( V_76 ) ;
F_34 ( V_67 , V_78 -> V_79 ) ;
F_32 ( V_67 , V_71 ) ;
}
}
static void F_41 ( T_3 * V_63 , int V_64 , void * V_65 )
{
struct V_45 * V_46 = V_65 ;
struct V_12 * V_13 = V_46 -> V_13 ;
struct V_42 * V_43 = V_46 -> V_47 ;
struct V_5 * V_69 = F_3 ( V_13 -> V_68 ) ;
int V_55 ;
F_38 ( V_85 , 4 , V_86 ) ;
if ( ! V_13 -> V_68 ) {
F_42 ( V_13 -> V_41 , V_43 ) ;
F_38 ( V_47 , 2 ,
L_5 ) ;
return;
}
if ( V_43 -> V_87 > V_13 -> V_88 ) {
F_42 ( V_13 -> V_41 , V_43 ) ;
V_69 -> V_80 . V_81 ++ ;
F_25 ( V_47 , 2 , L_6 ,
V_43 -> V_87 , V_13 -> V_88 ) ;
return;
}
V_13 -> V_89 -> V_47 = V_13 -> V_89 -> V_90 ;
F_43 ( V_13 -> V_89 ) ;
V_13 -> V_89 -> V_9 = 0 ;
V_55 = F_44 ( V_13 -> V_41 , V_43 , 0 , V_13 -> V_89 -> V_47 ,
V_43 -> V_87 , NULL ) ;
if ( V_55 || V_43 -> V_87 < 5 ) {
V_69 -> V_80 . V_91 ++ ;
F_25 ( V_47 , 2 , L_7 , V_55 ) ;
return;
}
F_31 ( V_13 , V_13 -> V_89 ) ;
}
static void F_45 ( T_3 * V_63 , int V_64 , void * V_65 )
{
struct V_45 * V_46 = V_65 ;
struct V_12 * V_13 = V_46 -> V_13 ;
struct V_42 * V_43 = V_46 -> V_47 ;
struct V_42 V_92 ;
struct V_5 * V_69 = NULL ;
T_5 V_93 = V_43 -> V_94 ;
T_5 V_95 = 0 ;
T_5 V_96 = 0 ;
T_5 V_97 = 0 ;
struct V_66 * V_76 ;
unsigned long V_98 ;
struct V_77 V_78 ;
int V_55 ;
F_38 ( V_85 , 4 , V_86 ) ;
if ( V_13 && V_13 -> V_68 )
V_69 = F_3 ( V_13 -> V_68 ) ;
V_13 -> V_99 . V_100 -- ;
if ( V_93 ) {
if ( ( V_76 = F_46 ( & V_13 -> V_101 ) ) ) {
F_47 ( & V_76 -> V_102 ) ;
if ( V_69 ) {
V_69 -> V_80 . V_103 ++ ;
V_69 -> V_80 . V_104 +=
( V_76 -> V_9 - V_71
- V_71 ) ;
}
F_48 ( V_76 ) ;
}
}
V_13 -> V_105 -> V_47 = V_13 -> V_105 -> V_90 ;
F_43 ( V_13 -> V_105 ) ;
V_13 -> V_105 -> V_9 = 0 ;
F_49 ( & V_13 -> V_106 , V_98 ) ;
while ( ( V_76 = F_46 ( & V_13 -> V_107 ) ) ) {
V_78 . V_79 = V_13 -> V_105 -> V_9 + V_76 -> V_9 + V_71 ;
memcpy ( F_32 ( V_13 -> V_105 , V_71 ) , & V_78 ,
V_71 ) ;
F_39 ( V_76 ,
F_32 ( V_13 -> V_105 , V_76 -> V_9 ) ,
V_76 -> V_9 ) ;
V_95 += V_76 -> V_9 ;
V_96 ++ ;
V_97 ++ ;
F_47 ( & V_76 -> V_102 ) ;
F_48 ( V_76 ) ;
}
if ( V_13 -> V_108 > V_13 -> V_99 . V_109 )
V_13 -> V_99 . V_109 = V_13 -> V_108 ;
V_13 -> V_108 = 0 ;
F_50 ( & V_13 -> V_106 , V_98 ) ;
if ( V_13 -> V_105 -> V_9 == 0 ) {
F_51 ( V_63 , V_110 ) ;
return;
}
V_78 . V_79 = 0 ;
memcpy ( F_32 ( V_13 -> V_105 , V_71 ) , & V_78 , V_71 ) ;
V_13 -> V_99 . V_111 = F_52 () ;
V_92 . V_112 = 0 ;
V_92 . V_94 = 0 ;
V_55 = F_53 ( V_13 -> V_41 , & V_92 , 0 , 0 ,
V_13 -> V_105 -> V_47 , V_13 -> V_105 -> V_9 ) ;
V_13 -> V_99 . V_113 ++ ;
V_13 -> V_99 . V_114 += V_13 -> V_105 -> V_9 ;
V_13 -> V_99 . V_100 ++ ;
if ( V_13 -> V_99 . V_100 > V_13 -> V_99 . V_115 )
V_13 -> V_99 . V_115 = V_13 -> V_99 . V_100 ;
if ( V_55 ) {
V_13 -> V_99 . V_100 -- ;
F_51 ( V_63 , V_110 ) ;
if ( V_69 )
V_69 -> V_80 . V_116 += V_96 ;
F_25 ( V_47 , 2 , L_8 , V_55 ) ;
} else {
if ( V_69 ) {
V_69 -> V_80 . V_103 += V_96 ;
V_69 -> V_80 . V_104 += V_95 ;
}
if ( V_97 > V_13 -> V_99 . V_117 )
V_13 -> V_99 . V_117 = V_97 ;
}
}
static void F_54 ( T_3 * V_63 , int V_64 , void * V_65 )
{
struct V_45 * V_46 = V_65 ;
struct V_12 * V_13 = V_46 -> V_13 ;
struct V_40 * V_41 = V_46 -> V_47 ;
struct V_3 * V_68 = V_13 -> V_68 ;
struct V_5 * V_69 = F_3 ( V_68 ) ;
int V_55 ;
F_38 ( V_85 , 3 , V_86 ) ;
V_13 -> V_41 = V_41 ;
V_41 -> V_118 = V_119 ;
V_41 -> V_120 = 0 ;
V_55 = F_55 ( V_41 , & V_121 , V_13 -> V_17 , V_13 ) ;
if ( V_55 ) {
F_25 ( V_59 , 2 , L_9 , V_55 ) ;
return;
}
F_51 ( V_63 , V_110 ) ;
V_68 -> V_122 = V_13 -> V_41 -> V_118 ;
F_19 ( V_69 -> V_48 , V_123 , V_68 ) ;
}
static void F_56 ( T_3 * V_63 , int V_64 , void * V_65 )
{
struct V_45 * V_46 = V_65 ;
struct V_40 * V_41 = V_46 -> V_47 ;
F_38 ( V_85 , 3 , V_86 ) ;
F_57 ( V_41 , NULL ) ;
}
static void F_58 ( T_3 * V_63 , int V_64 , void * V_65 )
{
struct V_12 * V_13 = V_65 ;
struct V_3 * V_68 = V_13 -> V_68 ;
struct V_5 * V_69 = F_3 ( V_68 ) ;
F_38 ( V_85 , 3 , V_86 ) ;
F_59 ( & V_13 -> V_124 ) ;
F_51 ( V_63 , V_110 ) ;
V_68 -> V_122 = V_13 -> V_41 -> V_118 ;
F_19 ( V_69 -> V_48 , V_123 , V_68 ) ;
}
static void F_60 ( T_3 * V_63 , int V_64 , void * V_65 )
{
struct V_12 * V_13 = V_65 ;
F_38 ( V_85 , 3 , V_86 ) ;
F_59 ( & V_13 -> V_124 ) ;
F_57 ( V_13 -> V_41 , V_13 -> V_17 ) ;
F_51 ( V_63 , V_125 ) ;
}
static void F_61 ( T_3 * V_63 , int V_64 , void * V_65 )
{
struct V_12 * V_13 = V_65 ;
struct V_3 * V_68 = V_13 -> V_68 ;
struct V_5 * V_69 = F_3 ( V_68 ) ;
F_38 ( V_85 , 3 , V_86 ) ;
F_59 ( & V_13 -> V_124 ) ;
F_57 ( V_13 -> V_41 , V_13 -> V_17 ) ;
F_62 ( V_69 -> V_4 , L_10
L_11 , F_10 ( V_13 ) ) ;
F_38 ( V_47 , 2 ,
L_12 ) ;
F_51 ( V_63 , V_125 ) ;
F_19 ( V_69 -> V_48 , V_126 , V_68 ) ;
}
static void F_63 ( T_3 * V_63 , int V_64 , void * V_65 )
{
struct V_12 * V_13 = V_65 ;
struct V_3 * V_68 = V_13 -> V_68 ;
struct V_5 * V_69 = F_3 ( V_68 ) ;
int V_55 ;
F_38 ( V_85 , 3 , V_86 ) ;
F_51 ( V_63 , V_125 ) ;
F_51 ( V_63 , V_127 ) ;
V_13 -> V_41 = F_64 ( V_119 , 0 , V_128 ) ;
F_25 ( V_59 , 2 , L_13 ,
V_68 -> V_8 , F_10 ( V_13 ) ) ;
V_55 = F_65 ( V_13 -> V_41 , & V_121 , V_13 -> V_19 ,
NULL , V_13 -> V_17 , V_13 ) ;
switch ( V_55 ) {
case 0 :
V_68 -> V_122 = V_13 -> V_41 -> V_118 ;
F_66 ( & V_13 -> V_124 , V_129 ,
V_130 , V_13 ) ;
return;
case 11 :
F_67 ( V_69 -> V_4 ,
L_14 ,
F_9 ( V_13 -> V_19 , 8 ) ) ;
F_51 ( V_63 , V_125 ) ;
break;
case 12 :
F_67 ( V_69 -> V_4 ,
L_15
L_16 , F_9 ( V_13 -> V_19 , 8 ) ) ;
F_51 ( V_63 , V_125 ) ;
break;
case 13 :
F_68 ( V_69 -> V_4 ,
L_17
L_18 ) ;
F_51 ( V_63 , V_131 ) ;
break;
case 14 :
F_68 ( V_69 -> V_4 ,
L_19
L_20 ,
F_9 ( V_13 -> V_19 , 8 ) ) ;
F_51 ( V_63 , V_131 ) ;
break;
case 15 :
F_68 ( V_69 -> V_4 ,
L_21
L_22 ) ;
F_51 ( V_63 , V_131 ) ;
break;
default:
F_68 ( V_69 -> V_4 ,
L_23 ,
V_55 ) ;
F_51 ( V_63 , V_131 ) ;
break;
}
F_25 ( V_59 , 5 , L_24 , V_55 ) ;
F_69 ( V_13 -> V_41 ) ;
V_13 -> V_41 = NULL ;
}
static void F_70 ( struct V_132 * V_133 )
{
struct V_66 * V_76 ;
while ( ( V_76 = F_46 ( V_133 ) ) ) {
F_47 ( & V_76 -> V_102 ) ;
F_48 ( V_76 ) ;
}
}
static void F_71 ( T_3 * V_63 , int V_64 , void * V_65 )
{
struct V_45 * V_46 = V_65 ;
struct V_12 * V_13 = V_46 -> V_13 ;
struct V_3 * V_68 = V_13 -> V_68 ;
struct V_5 * V_69 = F_3 ( V_68 ) ;
F_38 ( V_85 , 3 , V_86 ) ;
F_59 ( & V_13 -> V_124 ) ;
F_51 ( V_63 , V_134 ) ;
F_70 ( & V_13 -> V_107 ) ;
if ( V_13 -> V_41 ) {
F_38 ( V_85 , 5 , L_25 ) ;
F_57 ( V_13 -> V_41 , V_13 -> V_17 ) ;
F_69 ( V_13 -> V_41 ) ;
V_13 -> V_41 = NULL ;
}
F_70 ( & V_13 -> V_101 ) ;
F_19 ( V_69 -> V_48 , V_126 , V_68 ) ;
}
static void F_72 ( T_3 * V_63 , int V_64 , void * V_65 )
{
struct V_12 * V_13 = V_65 ;
struct V_3 * V_68 = V_13 -> V_68 ;
F_25 ( V_47 , 2 , L_26 ,
V_68 -> V_8 , V_13 -> V_19 ) ;
}
static void F_73 ( T_3 * V_63 , int V_64 , void * V_65 )
{
struct V_3 * V_4 = V_65 ;
struct V_5 * V_69 = F_3 ( V_4 ) ;
F_38 ( V_85 , 3 , V_86 ) ;
F_51 ( V_63 , V_135 ) ;
F_19 ( V_69 -> V_13 -> V_48 , V_136 , V_69 -> V_13 ) ;
}
static void
F_74 ( T_3 * V_63 , int V_64 , void * V_65 )
{
struct V_3 * V_4 = V_65 ;
struct V_5 * V_69 = F_3 ( V_4 ) ;
struct V_45 V_46 ;
F_38 ( V_85 , 3 , V_86 ) ;
V_46 . V_13 = V_69 -> V_13 ;
F_51 ( V_63 , V_137 ) ;
F_19 ( V_69 -> V_13 -> V_48 , V_138 , & V_46 ) ;
}
static void
F_75 ( T_3 * V_63 , int V_64 , void * V_65 )
{
struct V_3 * V_4 = V_65 ;
struct V_5 * V_69 = F_3 ( V_4 ) ;
F_38 ( V_85 , 3 , V_86 ) ;
switch ( F_76 ( V_63 ) ) {
case V_135 :
F_51 ( V_63 , V_139 ) ;
F_62 ( V_69 -> V_4 ,
L_27
L_28 ,
F_10 ( V_69 -> V_13 ) ) ;
F_38 ( V_59 , 3 ,
L_29 ) ;
break;
case V_137 :
F_38 ( V_47 , 2 ,
L_30 ) ;
break;
}
}
static void
F_77 ( T_3 * V_63 , int V_64 , void * V_65 )
{
F_38 ( V_85 , 3 , V_86 ) ;
switch ( F_76 ( V_63 ) ) {
case V_139 :
F_51 ( V_63 , V_135 ) ;
break;
case V_137 :
F_51 ( V_63 , V_140 ) ;
F_38 ( V_59 , 3 , L_31 ) ;
break;
}
}
static int F_78 ( struct V_12 * V_13 ,
struct V_66 * V_76 )
{
struct V_42 V_43 ;
unsigned long V_98 ;
struct V_77 V_78 ;
int V_55 ;
if ( F_76 ( V_13 -> V_48 ) != V_110 ) {
int V_141 = V_76 -> V_9 + V_71 ;
F_49 ( & V_13 -> V_106 , V_98 ) ;
if ( V_13 -> V_108 + V_141 >
( V_13 -> V_88 - V_71 ) ) {
V_55 = - V_142 ;
F_38 ( V_47 , 2 ,
L_32 ) ;
} else {
F_79 ( & V_76 -> V_102 ) ;
F_80 ( & V_13 -> V_107 , V_76 ) ;
V_13 -> V_108 += V_141 ;
V_55 = 0 ;
}
F_50 ( & V_13 -> V_106 , V_98 ) ;
} else {
struct V_66 * V_143 = V_76 ;
unsigned long V_144 = ( ( unsigned long ) ( F_81 ( V_76 ) +
V_71 ) ) >> 31 ;
int V_145 = 0 ;
if ( V_144 || ( F_35 ( V_76 ) < 2 ) ) {
V_143 = F_82 ( V_76 -> V_9 + V_71 +
V_71 , V_146 | V_147 ) ;
if ( ! V_143 ) {
F_38 ( V_47 , 2 , L_33 ) ;
V_55 = - V_35 ;
return V_55 ;
} else {
F_83 ( V_143 , V_71 ) ;
memcpy ( F_32 ( V_143 , V_76 -> V_9 ) ,
V_76 -> V_47 , V_76 -> V_9 ) ;
}
V_145 = 1 ;
}
V_78 . V_79 = V_143 -> V_9 + V_71 ;
memcpy ( F_84 ( V_143 , V_71 ) , & V_78 , V_71 ) ;
V_78 . V_79 = 0 ;
memcpy ( F_32 ( V_143 , V_71 ) , & V_78 , V_71 ) ;
F_51 ( V_13 -> V_48 , V_148 ) ;
V_13 -> V_99 . V_111 = F_52 () ;
V_43 . V_94 = 1 ;
V_43 . V_112 = 0 ;
V_55 = F_53 ( V_13 -> V_41 , & V_43 , 0 , 0 ,
V_143 -> V_47 , V_143 -> V_9 ) ;
V_13 -> V_99 . V_149 ++ ;
V_13 -> V_99 . V_114 += V_76 -> V_9 ;
V_13 -> V_99 . V_100 ++ ;
if ( V_13 -> V_99 . V_100 > V_13 -> V_99 . V_115 )
V_13 -> V_99 . V_115 = V_13 -> V_99 . V_100 ;
if ( V_55 ) {
struct V_5 * V_69 ;
F_51 ( V_13 -> V_48 , V_110 ) ;
V_13 -> V_99 . V_100 -- ;
V_69 = F_3 ( V_13 -> V_68 ) ;
if ( V_69 )
V_69 -> V_80 . V_116 ++ ;
if ( V_145 )
F_85 ( V_143 ) ;
else {
F_34 ( V_76 , V_71 ) ;
F_86 ( V_76 , V_76 -> V_9 - V_71 ) ;
}
F_25 ( V_47 , 2 , L_8 , V_55 ) ;
} else {
if ( V_145 )
F_85 ( V_76 ) ;
F_79 ( & V_143 -> V_102 ) ;
F_80 ( & V_13 -> V_101 , V_143 ) ;
}
}
return V_55 ;
}
static int F_87 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_19 ( V_6 -> V_48 , V_150 , V_4 ) ;
return 0 ;
}
static int F_88 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_19 ( V_6 -> V_48 , V_151 , V_4 ) ;
return 0 ;
}
static int F_89 ( struct V_152 * V_4 )
{
F_38 ( V_85 , 3 , V_86 ) ;
return 0 ;
}
static void F_90 ( struct V_152 * V_4 )
{
F_38 ( V_85 , 3 , V_86 ) ;
return;
}
static int F_91 ( struct V_152 * V_4 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
struct V_3 * V_153 = NULL ;
int V_55 = 0 ;
F_38 ( V_85 , 3 , V_86 ) ;
if ( V_6 && V_6 -> V_13 )
V_153 = V_6 -> V_13 -> V_68 ;
if ( ! V_153 )
goto V_154;
F_93 ( V_153 ) ;
V_6 -> V_155 = F_76 ( V_6 -> V_48 ) ;
V_55 = F_88 ( V_153 ) ;
V_154:
return V_55 ;
}
static int F_94 ( struct V_152 * V_4 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
struct V_3 * V_153 = NULL ;
int V_55 = 0 ;
F_38 ( V_85 , 3 , V_86 ) ;
if ( V_6 && V_6 -> V_13 )
V_153 = V_6 -> V_13 -> V_68 ;
if ( ! V_153 )
goto V_154;
switch ( V_6 -> V_155 ) {
case V_139 :
case V_135 :
V_55 = F_87 ( V_153 ) ;
break;
default:
break;
}
F_95 ( V_153 ) ;
V_154:
return V_55 ;
}
static int F_96 ( struct V_66 * V_76 , struct V_3 * V_4 )
{
struct V_5 * V_69 = F_3 ( V_4 ) ;
int V_55 ;
F_38 ( V_85 , 4 , V_86 ) ;
if ( V_76 == NULL ) {
F_38 ( V_47 , 2 , L_34 ) ;
V_69 -> V_80 . V_156 ++ ;
return V_157 ;
}
if ( F_97 ( V_76 ) < V_71 ) {
F_38 ( V_47 , 2 ,
L_35 ) ;
F_85 ( V_76 ) ;
V_69 -> V_80 . V_156 ++ ;
return V_157 ;
}
if ( F_76 ( V_69 -> V_48 ) != V_139 ) {
F_85 ( V_76 ) ;
V_69 -> V_80 . V_156 ++ ;
V_69 -> V_80 . V_116 ++ ;
V_69 -> V_80 . V_158 ++ ;
return V_157 ;
}
if ( F_6 ( V_4 ) ) {
F_38 ( V_47 , 2 , L_36 ) ;
return V_159 ;
}
V_4 -> V_160 = V_161 ;
V_55 = F_78 ( V_69 -> V_13 , V_76 ) ;
F_2 ( V_4 ) ;
return V_55 ? V_159 : V_157 ;
}
static struct V_162 * F_98 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_38 ( V_85 , 5 , V_86 ) ;
return & V_6 -> V_80 ;
}
static int F_99 ( struct V_3 * V_4 , int V_163 )
{
F_38 ( V_85 , 3 , V_86 ) ;
if ( V_163 < 576 || V_163 > V_164 ) {
F_38 ( V_59 , 2 , L_37 ) ;
return - V_56 ;
}
V_4 -> V_165 = V_163 ;
return 0 ;
}
static T_6 F_100 ( struct V_152 * V_4 , struct V_166 * V_167 ,
char * V_16 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 5 , V_86 ) ;
return sprintf ( V_16 , L_38 , F_10 ( V_6 -> V_13 ) ) ;
}
static int F_101 ( const char * V_16 , T_7 V_168 , char * V_169 ,
char * V_17 )
{
const char * V_11 ;
int V_170 ;
V_11 = strchr ( V_16 , '.' ) ;
if ( ( V_11 && ( ( V_168 > 26 ) ||
( ( V_11 - V_16 ) > 8 ) ||
( V_16 + V_168 - V_11 > 18 ) ) ) ||
( ! V_11 && ( V_168 > 9 ) ) ) {
F_38 ( V_59 , 2 , L_39 ) ;
return - V_56 ;
}
for ( V_170 = 0 , V_11 = V_16 ; V_170 < 8 && * V_11 && * V_11 != '.' ; V_170 ++ , V_11 ++ ) {
if ( isalnum ( * V_11 ) || * V_11 == '$' ) {
V_169 [ V_170 ] = toupper ( * V_11 ) ;
continue;
}
if ( * V_11 == '\n' )
break;
F_25 ( V_59 , 2 ,
L_40 , * V_11 ) ;
return - V_56 ;
}
while ( V_170 < 8 )
V_169 [ V_170 ++ ] = ' ' ;
V_169 [ 8 ] = '\0' ;
if ( * V_11 == '.' ) {
V_11 ++ ;
for ( V_170 = 0 ; V_170 < 16 && * V_11 ; V_170 ++ , V_11 ++ ) {
if ( * V_11 == '\n' )
break;
V_17 [ V_170 ] = toupper ( * V_11 ) ;
}
while ( V_170 > 0 && V_170 < 16 )
V_17 [ V_170 ++ ] = ' ' ;
} else
memcpy ( V_17 , V_171 , 16 ) ;
V_17 [ 16 ] = '\0' ;
F_102 ( V_17 , 16 ) ;
return 0 ;
}
static T_6 F_103 ( struct V_152 * V_4 , struct V_166 * V_167 ,
const char * V_16 , T_7 V_168 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
struct V_3 * V_153 = V_6 -> V_13 -> V_68 ;
char V_169 [ 9 ] ;
char V_17 [ 17 ] ;
int V_55 ;
struct V_12 * V_172 ;
F_38 ( V_85 , 3 , V_86 ) ;
V_55 = F_101 ( V_16 , V_168 , V_169 , V_17 ) ;
if ( V_55 )
return V_55 ;
if ( memcmp ( V_169 , V_6 -> V_13 -> V_19 , 9 ) &&
( V_153 -> V_120 & ( V_173 | V_174 ) ) ) {
F_38 ( V_59 , 2 , L_41 ) ;
return - V_175 ;
}
F_23 ( & V_57 ) ;
F_24 (cp, &iucv_connection_list, list) {
if ( ! strncmp ( V_169 , V_172 -> V_19 , 9 ) &&
! strncmp ( V_17 , V_172 -> V_17 , 17 ) && V_172 -> V_68 != V_153 ) {
F_26 ( & V_57 ) ;
F_25 ( V_59 , 2 , L_42
L_43 , F_10 ( V_172 ) ) ;
return - V_176 ;
}
}
F_26 ( & V_57 ) ;
memcpy ( V_6 -> V_13 -> V_19 , V_169 , 9 ) ;
memcpy ( V_6 -> V_13 -> V_17 , V_17 , 17 ) ;
return V_168 ;
}
static T_6 F_104 ( struct V_152 * V_4 , struct V_166 * V_167 ,
char * V_16 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 5 , V_86 ) ;
return sprintf ( V_16 , L_44 , V_6 -> V_13 -> V_88 ) ;
}
static T_6 F_105 ( struct V_152 * V_4 , struct V_166 * V_167 ,
const char * V_16 , T_7 V_168 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
struct V_3 * V_153 = V_6 -> V_13 -> V_68 ;
char * V_177 ;
int V_178 ;
F_38 ( V_85 , 3 , V_86 ) ;
if ( V_168 >= 39 )
return - V_56 ;
V_178 = F_106 ( V_16 , & V_177 , 0 ) ;
if ( V_177 && ( ! isspace ( * V_177 ) ) ) {
F_25 ( V_59 , 2 , L_45 ,
* V_177 ) ;
return - V_56 ;
}
if ( V_178 > V_179 ) {
F_25 ( V_59 , 2 ,
L_46 ,
V_178 ) ;
return - V_56 ;
}
if ( ( V_153 -> V_120 & V_174 ) &&
( V_178 < ( V_153 -> V_165 + V_71 + 2 ) ) ) {
F_25 ( V_59 , 2 ,
L_47 ,
V_178 ) ;
return - V_56 ;
}
if ( V_178 < ( 576 + V_71 + V_71 ) ) {
F_25 ( V_59 , 2 ,
L_47 ,
V_178 ) ;
return - V_56 ;
}
V_6 -> V_13 -> V_88 = V_178 ;
if ( ! ( V_153 -> V_120 & V_174 ) )
V_153 -> V_165 = V_178 - V_71 - V_71 ;
return V_168 ;
}
static T_6 F_107 ( struct V_152 * V_4 , struct V_166 * V_167 ,
char * V_16 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 5 , V_86 ) ;
return sprintf ( V_16 , L_38 , F_108 ( V_6 -> V_48 ) ) ;
}
static T_6 F_109 ( struct V_152 * V_4 ,
struct V_166 * V_167 , char * V_16 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 5 , V_86 ) ;
return sprintf ( V_16 , L_38 , F_108 ( V_6 -> V_13 -> V_48 ) ) ;
}
static T_6 F_110 ( struct V_152 * V_4 ,
struct V_166 * V_167 , char * V_16 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 5 , V_86 ) ;
return sprintf ( V_16 , L_48 , V_6 -> V_13 -> V_99 . V_109 ) ;
}
static T_6 F_111 ( struct V_152 * V_4 ,
struct V_166 * V_167 ,
const char * V_16 , T_7 V_168 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 4 , V_86 ) ;
V_6 -> V_13 -> V_99 . V_109 = 0 ;
return V_168 ;
}
static T_6 F_112 ( struct V_152 * V_4 , struct V_166 * V_167 ,
char * V_16 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 5 , V_86 ) ;
return sprintf ( V_16 , L_48 , V_6 -> V_13 -> V_99 . V_117 ) ;
}
static T_6 F_113 ( struct V_152 * V_4 , struct V_166 * V_167 ,
const char * V_16 , T_7 V_168 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 4 , V_86 ) ;
V_6 -> V_13 -> V_99 . V_117 = 0 ;
return V_168 ;
}
static T_6 F_114 ( struct V_152 * V_4 , struct V_166 * V_167 ,
char * V_16 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 5 , V_86 ) ;
return sprintf ( V_16 , L_48 , V_6 -> V_13 -> V_99 . V_149 ) ;
}
static T_6 F_115 ( struct V_152 * V_4 , struct V_166 * V_167 ,
const char * V_16 , T_7 V_168 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 4 , V_86 ) ;
V_6 -> V_13 -> V_99 . V_149 = 0 ;
return V_168 ;
}
static T_6 F_116 ( struct V_152 * V_4 , struct V_166 * V_167 ,
char * V_16 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 5 , V_86 ) ;
return sprintf ( V_16 , L_48 , V_6 -> V_13 -> V_99 . V_113 ) ;
}
static T_6 F_117 ( struct V_152 * V_4 , struct V_166 * V_167 ,
const char * V_16 , T_7 V_168 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 5 , V_86 ) ;
V_6 -> V_13 -> V_99 . V_113 = 0 ;
return V_168 ;
}
static T_6 F_118 ( struct V_152 * V_4 , struct V_166 * V_167 ,
char * V_16 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 5 , V_86 ) ;
return sprintf ( V_16 , L_48 , V_6 -> V_13 -> V_99 . V_114 ) ;
}
static T_6 F_119 ( struct V_152 * V_4 , struct V_166 * V_167 ,
const char * V_16 , T_7 V_168 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 4 , V_86 ) ;
V_6 -> V_13 -> V_99 . V_114 = 0 ;
return V_168 ;
}
static T_6 F_120 ( struct V_152 * V_4 , struct V_166 * V_167 ,
char * V_16 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 5 , V_86 ) ;
return sprintf ( V_16 , L_48 , V_6 -> V_13 -> V_99 . V_180 ) ;
}
static T_6 F_121 ( struct V_152 * V_4 , struct V_166 * V_167 ,
const char * V_16 , T_7 V_168 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 4 , V_86 ) ;
V_6 -> V_13 -> V_99 . V_180 = 0 ;
return V_168 ;
}
static T_6 F_122 ( struct V_152 * V_4 , struct V_166 * V_167 ,
char * V_16 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 5 , V_86 ) ;
return sprintf ( V_16 , L_48 , V_6 -> V_13 -> V_99 . V_100 ) ;
}
static T_6 F_123 ( struct V_152 * V_4 , struct V_166 * V_167 ,
const char * V_16 , T_7 V_168 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 4 , V_86 ) ;
V_6 -> V_13 -> V_99 . V_100 = 0 ;
return V_168 ;
}
static T_6 F_124 ( struct V_152 * V_4 , struct V_166 * V_167 ,
char * V_16 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 5 , V_86 ) ;
return sprintf ( V_16 , L_48 , V_6 -> V_13 -> V_99 . V_115 ) ;
}
static T_6 F_125 ( struct V_152 * V_4 , struct V_166 * V_167 ,
const char * V_16 , T_7 V_168 )
{
struct V_5 * V_6 = F_92 ( V_4 ) ;
F_38 ( V_85 , 4 , V_86 ) ;
V_6 -> V_13 -> V_99 . V_115 = 0 ;
return V_168 ;
}
static int F_126 ( struct V_152 * V_4 )
{
int V_181 ;
F_38 ( V_85 , 3 , V_86 ) ;
V_181 = F_127 ( & V_4 -> V_182 , & V_183 ) ;
if ( V_181 )
return V_181 ;
V_181 = F_127 ( & V_4 -> V_182 , & V_184 ) ;
if ( V_181 )
F_128 ( & V_4 -> V_182 , & V_183 ) ;
return V_181 ;
}
static void F_129 ( struct V_152 * V_4 )
{
F_38 ( V_85 , 3 , V_86 ) ;
F_128 ( & V_4 -> V_182 , & V_184 ) ;
F_128 ( & V_4 -> V_182 , & V_183 ) ;
}
static int F_130 ( struct V_3 * V_153 )
{
struct V_5 * V_6 = F_3 ( V_153 ) ;
struct V_152 * V_4 = F_131 ( sizeof( struct V_152 ) , V_128 ) ;
int V_181 ;
F_38 ( V_85 , 3 , V_86 ) ;
if ( V_4 ) {
F_132 ( V_4 , L_49 , V_153 -> V_8 ) ;
V_4 -> V_185 = & V_186 ;
V_4 -> V_187 = V_188 ;
V_4 -> V_189 = ( void ( * ) ( struct V_152 * ) ) F_69 ;
V_4 -> V_190 = & V_191 ;
} else
return - V_35 ;
V_181 = F_133 ( V_4 ) ;
if ( V_181 ) {
F_134 ( V_4 ) ;
return V_181 ;
}
V_181 = F_126 ( V_4 ) ;
if ( V_181 )
goto V_192;
V_6 -> V_4 = V_4 ;
F_135 ( V_4 , V_6 ) ;
return 0 ;
V_192:
F_136 ( V_4 ) ;
return V_181 ;
}
static void F_137 ( struct V_152 * V_4 )
{
F_38 ( V_85 , 3 , V_86 ) ;
F_129 ( V_4 ) ;
F_136 ( V_4 ) ;
}
static struct V_12 * F_138 ( struct V_3 * V_4 ,
char * V_169 ,
char * V_17 )
{
struct V_12 * V_13 ;
V_13 = F_131 ( sizeof( * V_13 ) , V_128 ) ;
if ( ! V_13 )
goto V_154;
F_139 ( & V_13 -> V_107 ) ;
F_139 ( & V_13 -> V_101 ) ;
F_140 ( & V_13 -> V_106 ) ;
V_13 -> V_88 = V_193 ;
V_13 -> V_68 = V_4 ;
V_13 -> V_89 = F_82 ( V_13 -> V_88 , V_128 | V_147 ) ;
if ( ! V_13 -> V_89 )
goto V_194;
V_13 -> V_105 = F_82 ( V_13 -> V_88 , V_128 | V_147 ) ;
if ( ! V_13 -> V_105 )
goto V_195;
V_13 -> V_48 = F_141 ( L_50 , V_196 ,
V_197 , V_198 ,
V_199 , V_200 , V_201 ,
V_128 ) ;
if ( ! V_13 -> V_48 )
goto V_202;
F_142 ( V_13 -> V_48 , & V_13 -> V_124 ) ;
F_51 ( V_13 -> V_48 , V_203 ) ;
if ( V_17 )
memcpy ( V_13 -> V_17 , V_17 , 17 ) ;
if ( V_169 ) {
memcpy ( V_13 -> V_19 , V_169 , 9 ) ;
F_51 ( V_13 -> V_48 , V_134 ) ;
}
F_143 ( & V_57 ) ;
F_144 ( & V_13 -> V_204 , & V_205 ) ;
F_145 ( & V_57 ) ;
return V_13 ;
V_202:
F_146 ( V_13 -> V_105 ) ;
V_195:
F_146 ( V_13 -> V_89 ) ;
V_194:
F_69 ( V_13 ) ;
V_154:
return NULL ;
}
static void F_147 ( struct V_12 * V_13 )
{
F_38 ( V_85 , 3 , V_86 ) ;
F_143 ( & V_57 ) ;
F_148 ( & V_13 -> V_204 ) ;
F_145 ( & V_57 ) ;
F_59 ( & V_13 -> V_124 ) ;
F_70 ( & V_13 -> V_107 ) ;
if ( V_13 -> V_41 ) {
F_57 ( V_13 -> V_41 , V_13 -> V_17 ) ;
F_69 ( V_13 -> V_41 ) ;
V_13 -> V_41 = NULL ;
}
F_70 ( & V_13 -> V_101 ) ;
F_149 ( V_13 -> V_48 ) ;
F_146 ( V_13 -> V_89 ) ;
F_146 ( V_13 -> V_105 ) ;
}
static void F_150 ( struct V_3 * V_4 )
{
struct V_5 * V_69 = F_3 ( V_4 ) ;
F_38 ( V_85 , 3 , V_86 ) ;
if ( ! V_4 )
return;
if ( V_69 ) {
if ( V_69 -> V_13 )
F_147 ( V_69 -> V_13 ) ;
if ( V_69 -> V_48 )
F_149 ( V_69 -> V_48 ) ;
V_69 -> V_13 = NULL ; V_69 -> V_48 = NULL ;
}
F_151 ( V_4 ) ;
}
static void F_152 ( struct V_3 * V_4 )
{
V_4 -> V_165 = V_206 ;
V_4 -> V_207 = F_150 ;
V_4 -> V_208 = V_71 ;
V_4 -> V_209 = 0 ;
V_4 -> type = V_210 ;
V_4 -> V_122 = V_119 ;
V_4 -> V_120 = V_211 | V_212 ;
V_4 -> V_213 = & V_214 ;
}
static struct V_3 * F_153 ( char * V_169 , char * V_17 )
{
struct V_5 * V_69 ;
struct V_3 * V_4 ;
V_4 = F_154 ( sizeof( struct V_5 ) , L_51 ,
F_152 ) ;
if ( ! V_4 )
return NULL ;
if ( F_155 ( V_4 , V_4 -> V_8 ) < 0 )
goto V_215;
V_69 = F_3 ( V_4 ) ;
V_69 -> V_48 = F_141 ( L_52 , V_216 ,
V_217 , V_218 , V_219 ,
V_220 , V_221 , V_128 ) ;
if ( ! V_69 -> V_48 )
goto V_215;
V_69 -> V_13 = F_138 ( V_4 , V_169 , V_17 ) ;
if ( ! V_69 -> V_13 ) {
F_38 ( V_59 , 2 , L_53 ) ;
goto V_222;
}
F_51 ( V_69 -> V_48 , V_140 ) ;
return V_4 ;
V_222:
F_149 ( V_69 -> V_48 ) ;
V_215:
F_151 ( V_4 ) ;
return NULL ;
}
static T_6 F_156 ( struct V_223 * V_224 ,
const char * V_16 , T_7 V_168 )
{
char V_169 [ 9 ] ;
char V_17 [ 17 ] ;
int V_55 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_12 * V_172 ;
F_38 ( V_85 , 3 , V_86 ) ;
V_55 = F_101 ( V_16 , V_168 , V_169 , V_17 ) ;
if ( V_55 )
return V_55 ;
F_23 ( & V_57 ) ;
F_24 (cp, &iucv_connection_list, list) {
if ( ! strncmp ( V_169 , V_172 -> V_19 , 9 ) &&
! strncmp ( V_17 , V_172 -> V_17 , 17 ) ) {
F_26 ( & V_57 ) ;
F_25 ( V_59 , 2 , L_54
L_43 , F_10 ( V_172 ) ) ;
return - V_176 ;
}
}
F_26 ( & V_57 ) ;
V_4 = F_153 ( V_169 , V_17 ) ;
if ( ! V_4 ) {
F_38 ( V_59 , 2 , L_55 ) ;
return - V_225 ;
}
V_55 = F_130 ( V_4 ) ;
if ( V_55 ) {
F_25 ( V_59 , 2 ,
L_56 , V_55 ) ;
goto V_226;
}
V_6 = F_3 ( V_4 ) ;
F_157 ( V_4 , V_6 -> V_4 ) ;
V_55 = F_158 ( V_4 ) ;
if ( V_55 )
goto V_192;
F_62 ( V_6 -> V_4 , L_57
L_58 ,
F_10 ( V_6 -> V_13 ) ) ;
return V_168 ;
V_192:
F_137 ( V_6 -> V_4 ) ;
V_226:
F_150 ( V_4 ) ;
return V_55 ;
}
static T_6 F_159 ( struct V_223 * V_224 ,
const char * V_16 , T_7 V_168 )
{
struct V_12 * V_172 ;
struct V_3 * V_153 ;
struct V_5 * V_6 ;
struct V_152 * V_4 ;
char V_8 [ V_227 ] ;
const char * V_11 ;
int V_170 ;
F_38 ( V_85 , 3 , V_86 ) ;
if ( V_168 >= V_227 )
V_168 = V_227 - 1 ;
for ( V_170 = 0 , V_11 = V_16 ; V_170 < V_168 && * V_11 ; V_170 ++ , V_11 ++ ) {
if ( * V_11 == '\n' || * V_11 == ' ' )
break;
V_8 [ V_170 ] = * V_11 ;
}
V_8 [ V_170 ] = '\0' ;
F_23 ( & V_57 ) ;
F_24 (cp, &iucv_connection_list, list) {
V_153 = V_172 -> V_68 ;
V_6 = F_3 ( V_153 ) ;
V_4 = V_6 -> V_4 ;
if ( strncmp ( V_8 , V_153 -> V_8 , V_168 ) )
continue;
F_26 ( & V_57 ) ;
if ( V_153 -> V_120 & ( V_173 | V_174 ) ) {
F_67 ( V_4 , L_59
L_60 ,
V_6 -> V_13 -> V_19 ) ;
F_38 ( V_47 , 2 , L_61 ) ;
return - V_175 ;
}
F_160 ( V_153 ) ;
F_137 ( V_4 ) ;
return V_168 ;
}
F_26 ( & V_57 ) ;
F_38 ( V_47 , 2 , L_62 ) ;
return - V_56 ;
}
static void F_161 ( void )
{
F_162 ( L_63 ) ;
}
static void T_8 F_163 ( void )
{
struct V_12 * V_172 ;
struct V_3 * V_153 ;
struct V_5 * V_6 ;
struct V_152 * V_4 ;
F_38 ( V_85 , 3 , V_86 ) ;
while ( ! F_164 ( & V_205 ) ) {
V_172 = F_165 ( V_205 . V_79 ,
struct V_12 , V_204 ) ;
V_153 = V_172 -> V_68 ;
V_6 = F_3 ( V_153 ) ;
V_4 = V_6 -> V_4 ;
F_160 ( V_153 ) ;
F_137 ( V_4 ) ;
}
F_136 ( V_228 ) ;
F_166 ( & V_191 ) ;
F_167 ( & V_121 , 1 ) ;
F_12 () ;
F_162 ( L_64 ) ;
return;
}
static int T_9 F_168 ( void )
{
int V_55 ;
V_55 = F_14 () ;
if ( V_55 )
goto V_154;
V_55 = F_169 ( & V_121 , 1 ) ;
if ( V_55 )
goto V_229;
F_38 ( V_85 , 3 , V_86 ) ;
V_191 . V_230 = V_231 ;
V_55 = F_170 ( & V_191 ) ;
if ( V_55 ) {
F_25 ( V_59 , 2 , L_65 , V_55 ) ;
goto V_232;
}
V_228 = F_131 ( sizeof( struct V_152 ) , V_128 ) ;
if ( ! V_228 ) {
V_55 = - V_35 ;
goto V_233;
}
F_132 ( V_228 , L_66 ) ;
V_228 -> V_185 = & V_186 ;
V_228 -> V_187 = V_188 ;
V_228 -> V_189 = ( void ( * ) ( struct V_152 * ) ) F_69 ;
V_228 -> V_190 = & V_191 ;
V_55 = F_133 ( V_228 ) ;
if ( V_55 ) {
F_134 ( V_228 ) ;
goto V_233;
}
F_161 () ;
return V_55 ;
V_233:
F_166 ( & V_191 ) ;
V_232:
F_167 ( & V_121 , 1 ) ;
V_229:
F_12 () ;
V_154:
return V_55 ;
}
