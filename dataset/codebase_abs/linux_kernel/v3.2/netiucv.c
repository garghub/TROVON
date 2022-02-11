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
static char * F_9 ( char * V_8 )
{
static char V_9 [ 9 ] ;
char * V_10 = V_9 ;
memcpy ( V_9 , V_8 , 8 ) ;
V_9 [ 8 ] = '\0' ;
while ( * V_10 && ( ! isspace ( * V_10 ) ) )
V_10 ++ ;
* V_10 = '\0' ;
return V_9 ;
}
static void F_10 ( void )
{
if ( V_11 )
F_11 ( V_11 ) ;
if ( V_12 )
F_11 ( V_12 ) ;
if ( V_13 )
F_11 ( V_13 ) ;
}
static int F_12 ( void )
{
V_11 = F_13 ( V_14 ,
V_15 ,
V_16 ,
V_17 ) ;
V_12 = F_13 ( V_18 ,
V_19 ,
V_20 ,
V_21 ) ;
V_13 = F_13 ( V_22 ,
V_23 ,
V_24 ,
V_25 ) ;
if ( ( V_11 == NULL ) || ( V_12 == NULL ) ||
( V_13 == NULL ) ) {
F_10 () ;
return - V_26 ;
}
F_14 ( V_11 , & V_27 ) ;
F_15 ( V_11 , V_28 ) ;
F_14 ( V_12 , & V_27 ) ;
F_15 ( V_12 , V_29 ) ;
F_14 ( V_13 , & V_27 ) ;
F_15 ( V_13 , V_30 ) ;
return 0 ;
}
static void F_16 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = V_32 -> V_37 ;
struct V_38 V_39 ;
V_39 . V_36 = V_36 ;
V_39 . V_40 = V_34 ;
F_17 ( V_36 -> V_41 , V_42 , & V_39 ) ;
}
static void F_18 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = V_32 -> V_37 ;
struct V_38 V_39 ;
V_39 . V_36 = V_36 ;
V_39 . V_40 = V_34 ;
F_17 ( V_36 -> V_41 , V_43 , & V_39 ) ;
}
static void F_19 ( struct V_31 * V_32 , T_2 V_44 [ 16 ] )
{
struct V_35 * V_36 = V_32 -> V_37 ;
F_17 ( V_36 -> V_41 , V_45 , V_36 ) ;
}
static int F_20 ( struct V_31 * V_32 ,
T_2 V_46 [ 8 ] , T_2 V_44 [ 16 ] )
{
struct V_35 * V_36 = V_32 -> V_37 ;
struct V_38 V_39 ;
int V_47 ;
if ( memcmp ( V_48 , V_44 , 16 ) )
return - V_49 ;
V_47 = - V_49 ;
F_21 ( & V_50 ) ;
F_22 (conn, &iucv_connection_list, list) {
if ( strncmp ( V_46 , V_36 -> V_51 , 8 ) )
continue;
V_36 -> V_32 = V_32 ;
V_39 . V_36 = V_36 ;
V_39 . V_40 = V_32 ;
F_17 ( V_36 -> V_41 , V_52 , & V_39 ) ;
V_47 = 0 ;
}
F_23 ( & V_50 ) ;
return V_47 ;
}
static void F_24 ( struct V_31 * V_32 , T_2 V_44 [ 16 ] )
{
struct V_35 * V_36 = V_32 -> V_37 ;
F_17 ( V_36 -> V_41 , V_53 , V_36 ) ;
}
static void F_25 ( struct V_31 * V_32 , T_2 V_44 [ 16 ] )
{
struct V_35 * V_36 = V_32 -> V_37 ;
F_17 ( V_36 -> V_41 , V_54 , V_36 ) ;
}
static void F_26 ( struct V_31 * V_32 , T_2 V_44 [ 16 ] )
{
struct V_35 * V_36 = V_32 -> V_37 ;
F_17 ( V_36 -> V_41 , V_55 , V_36 ) ;
}
static void F_27 ( T_3 * V_56 , int V_57 , void * V_58 )
{
}
static void F_28 ( struct V_35 * V_36 ,
struct V_59 * V_60 )
{
struct V_3 * V_4 = V_36 -> V_61 ;
struct V_5 * V_62 = F_3 ( V_4 ) ;
T_4 V_63 = 0 ;
F_29 ( V_60 , V_64 ) ;
V_60 -> V_4 = V_4 ;
V_60 -> V_65 = V_66 ;
V_60 -> V_67 = F_30 ( V_68 ) ;
while ( 1 ) {
struct V_59 * V_69 ;
struct V_70 * V_71 = (struct V_70 * ) V_60 -> V_40 ;
if ( ! V_71 -> V_72 )
break;
F_31 ( V_60 , V_64 ) ;
V_71 -> V_72 -= V_63 ;
V_63 += V_71 -> V_72 ;
V_71 -> V_72 -= V_64 ;
if ( F_32 ( V_60 ) < V_71 -> V_72 ) {
F_33 ( V_40 , 2 , L_1 ,
V_71 -> V_72 , F_32 ( V_60 ) ) ;
return;
}
F_29 ( V_60 , V_71 -> V_72 ) ;
F_34 ( V_60 ) ;
V_69 = F_35 ( V_60 -> V_73 ) ;
if ( ! V_69 ) {
F_36 ( V_40 , 2 ,
L_2 ) ;
V_62 -> V_74 . V_75 ++ ;
return;
}
F_37 ( V_60 , F_29 ( V_69 , V_60 -> V_73 ) ,
V_60 -> V_73 ) ;
F_34 ( V_69 ) ;
V_69 -> V_4 = V_60 -> V_4 ;
V_69 -> V_67 = V_60 -> V_67 ;
V_60 -> V_65 = V_76 ;
V_62 -> V_74 . V_77 ++ ;
V_62 -> V_74 . V_78 += V_69 -> V_73 ;
F_38 ( V_69 ) ;
F_31 ( V_60 , V_71 -> V_72 ) ;
F_29 ( V_60 , V_64 ) ;
}
}
static void F_39 ( T_3 * V_56 , int V_57 , void * V_58 )
{
struct V_38 * V_39 = V_58 ;
struct V_35 * V_36 = V_39 -> V_36 ;
struct V_33 * V_34 = V_39 -> V_40 ;
struct V_5 * V_62 = F_3 ( V_36 -> V_61 ) ;
int V_47 ;
F_36 ( V_79 , 4 , V_80 ) ;
if ( ! V_36 -> V_61 ) {
F_40 ( V_36 -> V_32 , V_34 ) ;
F_36 ( V_40 , 2 ,
L_3 ) ;
return;
}
if ( V_34 -> V_81 > V_36 -> V_82 ) {
F_40 ( V_36 -> V_32 , V_34 ) ;
V_62 -> V_74 . V_75 ++ ;
F_33 ( V_40 , 2 , L_4 ,
V_34 -> V_81 , V_36 -> V_82 ) ;
return;
}
V_36 -> V_83 -> V_40 = V_36 -> V_83 -> V_84 ;
F_41 ( V_36 -> V_83 ) ;
V_36 -> V_83 -> V_73 = 0 ;
V_47 = F_42 ( V_36 -> V_32 , V_34 , 0 , V_36 -> V_83 -> V_40 ,
V_34 -> V_81 , NULL ) ;
if ( V_47 || V_34 -> V_81 < 5 ) {
V_62 -> V_74 . V_85 ++ ;
F_33 ( V_40 , 2 , L_5 , V_47 ) ;
return;
}
F_28 ( V_36 , V_36 -> V_83 ) ;
}
static void F_43 ( T_3 * V_56 , int V_57 , void * V_58 )
{
struct V_38 * V_39 = V_58 ;
struct V_35 * V_36 = V_39 -> V_36 ;
struct V_33 * V_34 = V_39 -> V_40 ;
struct V_33 V_86 ;
struct V_5 * V_62 = NULL ;
T_5 V_87 = V_34 -> V_88 ;
T_5 V_89 = 0 ;
T_5 V_90 = 0 ;
T_5 V_91 = 0 ;
struct V_59 * V_69 ;
unsigned long V_92 ;
struct V_70 V_71 ;
int V_47 ;
F_36 ( V_79 , 4 , V_80 ) ;
if ( V_36 && V_36 -> V_61 )
V_62 = F_3 ( V_36 -> V_61 ) ;
V_36 -> V_93 . V_94 -- ;
if ( V_87 ) {
if ( ( V_69 = F_44 ( & V_36 -> V_95 ) ) ) {
F_45 ( & V_69 -> V_96 ) ;
if ( V_62 ) {
V_62 -> V_74 . V_97 ++ ;
V_62 -> V_74 . V_98 +=
( V_69 -> V_73 - V_64
- V_64 ) ;
}
F_46 ( V_69 ) ;
}
}
V_36 -> V_99 -> V_40 = V_36 -> V_99 -> V_84 ;
F_41 ( V_36 -> V_99 ) ;
V_36 -> V_99 -> V_73 = 0 ;
F_47 ( & V_36 -> V_100 , V_92 ) ;
while ( ( V_69 = F_44 ( & V_36 -> V_101 ) ) ) {
V_71 . V_72 = V_36 -> V_99 -> V_73 + V_69 -> V_73 + V_64 ;
memcpy ( F_29 ( V_36 -> V_99 , V_64 ) , & V_71 ,
V_64 ) ;
F_37 ( V_69 ,
F_29 ( V_36 -> V_99 , V_69 -> V_73 ) ,
V_69 -> V_73 ) ;
V_89 += V_69 -> V_73 ;
V_90 ++ ;
V_91 ++ ;
F_45 ( & V_69 -> V_96 ) ;
F_46 ( V_69 ) ;
}
if ( V_36 -> V_102 > V_36 -> V_93 . V_103 )
V_36 -> V_93 . V_103 = V_36 -> V_102 ;
V_36 -> V_102 = 0 ;
F_48 ( & V_36 -> V_100 , V_92 ) ;
if ( V_36 -> V_99 -> V_73 == 0 ) {
F_49 ( V_56 , V_104 ) ;
return;
}
V_71 . V_72 = 0 ;
memcpy ( F_29 ( V_36 -> V_99 , V_64 ) , & V_71 , V_64 ) ;
V_36 -> V_93 . V_105 = F_50 () ;
V_86 . V_106 = 0 ;
V_86 . V_88 = 0 ;
V_47 = F_51 ( V_36 -> V_32 , & V_86 , 0 , 0 ,
V_36 -> V_99 -> V_40 , V_36 -> V_99 -> V_73 ) ;
V_36 -> V_93 . V_107 ++ ;
V_36 -> V_93 . V_108 += V_36 -> V_99 -> V_73 ;
V_36 -> V_93 . V_94 ++ ;
if ( V_36 -> V_93 . V_94 > V_36 -> V_93 . V_109 )
V_36 -> V_93 . V_109 = V_36 -> V_93 . V_94 ;
if ( V_47 ) {
V_36 -> V_93 . V_94 -- ;
F_49 ( V_56 , V_104 ) ;
if ( V_62 )
V_62 -> V_74 . V_110 += V_90 ;
F_33 ( V_40 , 2 , L_6 , V_47 ) ;
} else {
if ( V_62 ) {
V_62 -> V_74 . V_97 += V_90 ;
V_62 -> V_74 . V_98 += V_89 ;
}
if ( V_91 > V_36 -> V_93 . V_111 )
V_36 -> V_93 . V_111 = V_91 ;
}
}
static void F_52 ( T_3 * V_56 , int V_57 , void * V_58 )
{
struct V_38 * V_39 = V_58 ;
struct V_35 * V_36 = V_39 -> V_36 ;
struct V_31 * V_32 = V_39 -> V_40 ;
struct V_3 * V_61 = V_36 -> V_61 ;
struct V_5 * V_62 = F_3 ( V_61 ) ;
int V_47 ;
F_36 ( V_79 , 3 , V_80 ) ;
V_36 -> V_32 = V_32 ;
V_32 -> V_112 = V_113 ;
V_32 -> V_114 = 0 ;
V_47 = F_53 ( V_32 , & V_115 , NULL , V_36 ) ;
if ( V_47 ) {
F_33 ( V_116 , 2 , L_7 , V_47 ) ;
return;
}
F_49 ( V_56 , V_104 ) ;
V_61 -> V_117 = V_36 -> V_32 -> V_112 ;
F_17 ( V_62 -> V_41 , V_118 , V_61 ) ;
}
static void F_54 ( T_3 * V_56 , int V_57 , void * V_58 )
{
struct V_38 * V_39 = V_58 ;
struct V_31 * V_32 = V_39 -> V_40 ;
F_36 ( V_79 , 3 , V_80 ) ;
F_55 ( V_32 , NULL ) ;
}
static void F_56 ( T_3 * V_56 , int V_57 , void * V_58 )
{
struct V_35 * V_36 = V_58 ;
struct V_3 * V_61 = V_36 -> V_61 ;
struct V_5 * V_62 = F_3 ( V_61 ) ;
F_36 ( V_79 , 3 , V_80 ) ;
F_57 ( & V_36 -> V_119 ) ;
F_49 ( V_56 , V_104 ) ;
V_61 -> V_117 = V_36 -> V_32 -> V_112 ;
F_17 ( V_62 -> V_41 , V_118 , V_61 ) ;
}
static void F_58 ( T_3 * V_56 , int V_57 , void * V_58 )
{
struct V_35 * V_36 = V_58 ;
F_36 ( V_79 , 3 , V_80 ) ;
F_57 ( & V_36 -> V_119 ) ;
F_55 ( V_36 -> V_32 , NULL ) ;
F_49 ( V_56 , V_120 ) ;
}
static void F_59 ( T_3 * V_56 , int V_57 , void * V_58 )
{
struct V_35 * V_36 = V_58 ;
struct V_3 * V_61 = V_36 -> V_61 ;
struct V_5 * V_62 = F_3 ( V_61 ) ;
F_36 ( V_79 , 3 , V_80 ) ;
F_57 ( & V_36 -> V_119 ) ;
F_55 ( V_36 -> V_32 , NULL ) ;
F_60 ( V_62 -> V_4 , L_8
L_9 ) ;
F_36 ( V_40 , 2 ,
L_10 ) ;
F_49 ( V_56 , V_120 ) ;
F_17 ( V_62 -> V_41 , V_121 , V_61 ) ;
}
static void F_61 ( T_3 * V_56 , int V_57 , void * V_58 )
{
struct V_35 * V_36 = V_58 ;
struct V_3 * V_61 = V_36 -> V_61 ;
struct V_5 * V_62 = F_3 ( V_61 ) ;
int V_47 ;
F_36 ( V_79 , 3 , V_80 ) ;
F_49 ( V_56 , V_120 ) ;
F_33 ( V_116 , 2 , L_11 ,
V_61 -> V_8 , V_36 -> V_51 ) ;
F_49 ( V_56 , V_122 ) ;
V_36 -> V_32 = F_62 ( V_113 , 0 , V_123 ) ;
V_47 = F_63 ( V_36 -> V_32 , & V_115 , V_36 -> V_51 ,
NULL , V_48 , V_36 ) ;
switch ( V_47 ) {
case 0 :
V_61 -> V_117 = V_36 -> V_32 -> V_112 ;
F_64 ( & V_36 -> V_119 , V_124 ,
V_125 , V_36 ) ;
return;
case 11 :
F_65 ( V_62 -> V_4 ,
L_12 ,
F_9 ( V_36 -> V_51 ) ) ;
F_49 ( V_56 , V_120 ) ;
break;
case 12 :
F_65 ( V_62 -> V_4 ,
L_13
L_14 , F_9 ( V_36 -> V_51 ) ) ;
F_49 ( V_56 , V_120 ) ;
break;
case 13 :
F_66 ( V_62 -> V_4 ,
L_15
L_16 ) ;
F_49 ( V_56 , V_126 ) ;
break;
case 14 :
F_66 ( V_62 -> V_4 ,
L_17
L_18 ,
F_9 ( V_36 -> V_51 ) ) ;
F_49 ( V_56 , V_126 ) ;
break;
case 15 :
F_66 ( V_62 -> V_4 ,
L_19
L_20 ) ;
F_49 ( V_56 , V_126 ) ;
break;
default:
F_66 ( V_62 -> V_4 ,
L_21 ,
V_47 ) ;
F_49 ( V_56 , V_126 ) ;
break;
}
F_33 ( V_116 , 5 , L_22 , V_47 ) ;
F_67 ( V_36 -> V_32 ) ;
V_36 -> V_32 = NULL ;
}
static void F_68 ( struct V_127 * V_128 )
{
struct V_59 * V_69 ;
while ( ( V_69 = F_44 ( V_128 ) ) ) {
F_45 ( & V_69 -> V_96 ) ;
F_46 ( V_69 ) ;
}
}
static void F_69 ( T_3 * V_56 , int V_57 , void * V_58 )
{
struct V_38 * V_39 = V_58 ;
struct V_35 * V_36 = V_39 -> V_36 ;
struct V_3 * V_61 = V_36 -> V_61 ;
struct V_5 * V_62 = F_3 ( V_61 ) ;
F_36 ( V_79 , 3 , V_80 ) ;
F_57 ( & V_36 -> V_119 ) ;
F_49 ( V_56 , V_129 ) ;
F_68 ( & V_36 -> V_101 ) ;
if ( V_36 -> V_32 ) {
F_36 ( V_79 , 5 , L_23 ) ;
F_55 ( V_36 -> V_32 , V_48 ) ;
F_67 ( V_36 -> V_32 ) ;
V_36 -> V_32 = NULL ;
}
F_68 ( & V_36 -> V_95 ) ;
F_17 ( V_62 -> V_41 , V_121 , V_61 ) ;
}
static void F_70 ( T_3 * V_56 , int V_57 , void * V_58 )
{
struct V_35 * V_36 = V_58 ;
struct V_3 * V_61 = V_36 -> V_61 ;
F_33 ( V_40 , 2 , L_24 ,
V_61 -> V_8 , V_36 -> V_51 ) ;
}
static void F_71 ( T_3 * V_56 , int V_57 , void * V_58 )
{
struct V_3 * V_4 = V_58 ;
struct V_5 * V_62 = F_3 ( V_4 ) ;
F_36 ( V_79 , 3 , V_80 ) ;
F_49 ( V_56 , V_130 ) ;
F_17 ( V_62 -> V_36 -> V_41 , V_131 , V_62 -> V_36 ) ;
}
static void
F_72 ( T_3 * V_56 , int V_57 , void * V_58 )
{
struct V_3 * V_4 = V_58 ;
struct V_5 * V_62 = F_3 ( V_4 ) ;
struct V_38 V_39 ;
F_36 ( V_79 , 3 , V_80 ) ;
V_39 . V_36 = V_62 -> V_36 ;
F_49 ( V_56 , V_132 ) ;
F_17 ( V_62 -> V_36 -> V_41 , V_133 , & V_39 ) ;
}
static void
F_73 ( T_3 * V_56 , int V_57 , void * V_58 )
{
struct V_3 * V_4 = V_58 ;
struct V_5 * V_62 = F_3 ( V_4 ) ;
F_36 ( V_79 , 3 , V_80 ) ;
switch ( F_74 ( V_56 ) ) {
case V_130 :
F_49 ( V_56 , V_134 ) ;
F_60 ( V_62 -> V_4 ,
L_25
L_26 , V_62 -> V_36 -> V_51 ) ;
F_36 ( V_116 , 3 ,
L_27 ) ;
break;
case V_132 :
F_36 ( V_40 , 2 ,
L_28 ) ;
break;
}
}
static void
F_75 ( T_3 * V_56 , int V_57 , void * V_58 )
{
F_36 ( V_79 , 3 , V_80 ) ;
switch ( F_74 ( V_56 ) ) {
case V_134 :
F_49 ( V_56 , V_130 ) ;
break;
case V_132 :
F_49 ( V_56 , V_135 ) ;
F_36 ( V_116 , 3 , L_29 ) ;
break;
}
}
static int F_76 ( struct V_35 * V_36 ,
struct V_59 * V_69 )
{
struct V_33 V_34 ;
unsigned long V_92 ;
struct V_70 V_71 ;
int V_47 ;
if ( F_74 ( V_36 -> V_41 ) != V_104 ) {
int V_136 = V_69 -> V_73 + V_64 ;
F_47 ( & V_36 -> V_100 , V_92 ) ;
if ( V_36 -> V_102 + V_136 >
( V_36 -> V_82 - V_64 ) ) {
V_47 = - V_137 ;
F_36 ( V_40 , 2 ,
L_30 ) ;
} else {
F_77 ( & V_69 -> V_96 ) ;
F_78 ( & V_36 -> V_101 , V_69 ) ;
V_36 -> V_102 += V_136 ;
V_47 = 0 ;
}
F_48 ( & V_36 -> V_100 , V_92 ) ;
} else {
struct V_59 * V_138 = V_69 ;
unsigned long V_139 = ( ( unsigned long ) ( F_79 ( V_69 ) +
V_64 ) ) >> 31 ;
int V_140 = 0 ;
if ( V_139 || ( F_32 ( V_69 ) < 2 ) ) {
V_138 = F_80 ( V_69 -> V_73 + V_64 +
V_64 , V_141 | V_142 ) ;
if ( ! V_138 ) {
F_36 ( V_40 , 2 , L_31 ) ;
V_47 = - V_26 ;
return V_47 ;
} else {
F_81 ( V_138 , V_64 ) ;
memcpy ( F_29 ( V_138 , V_69 -> V_73 ) ,
V_69 -> V_40 , V_69 -> V_73 ) ;
}
V_140 = 1 ;
}
V_71 . V_72 = V_138 -> V_73 + V_64 ;
memcpy ( F_82 ( V_138 , V_64 ) , & V_71 , V_64 ) ;
V_71 . V_72 = 0 ;
memcpy ( F_29 ( V_138 , V_64 ) , & V_71 , V_64 ) ;
F_49 ( V_36 -> V_41 , V_143 ) ;
V_36 -> V_93 . V_105 = F_50 () ;
V_34 . V_88 = 1 ;
V_34 . V_106 = 0 ;
V_47 = F_51 ( V_36 -> V_32 , & V_34 , 0 , 0 ,
V_138 -> V_40 , V_138 -> V_73 ) ;
V_36 -> V_93 . V_144 ++ ;
V_36 -> V_93 . V_108 += V_69 -> V_73 ;
V_36 -> V_93 . V_94 ++ ;
if ( V_36 -> V_93 . V_94 > V_36 -> V_93 . V_109 )
V_36 -> V_93 . V_109 = V_36 -> V_93 . V_94 ;
if ( V_47 ) {
struct V_5 * V_62 ;
F_49 ( V_36 -> V_41 , V_104 ) ;
V_36 -> V_93 . V_94 -- ;
V_62 = F_3 ( V_36 -> V_61 ) ;
if ( V_62 )
V_62 -> V_74 . V_110 ++ ;
if ( V_140 )
F_83 ( V_138 ) ;
else {
F_31 ( V_69 , V_64 ) ;
F_84 ( V_69 , V_69 -> V_73 - V_64 ) ;
}
F_33 ( V_40 , 2 , L_6 , V_47 ) ;
} else {
if ( V_140 )
F_83 ( V_69 ) ;
F_77 ( & V_138 -> V_96 ) ;
F_78 ( & V_36 -> V_95 , V_138 ) ;
}
}
return V_47 ;
}
static int F_85 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_17 ( V_6 -> V_41 , V_145 , V_4 ) ;
return 0 ;
}
static int F_86 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_17 ( V_6 -> V_41 , V_146 , V_4 ) ;
return 0 ;
}
static int F_87 ( struct V_147 * V_4 )
{
F_36 ( V_79 , 3 , V_80 ) ;
return 0 ;
}
static void F_88 ( struct V_147 * V_4 )
{
F_36 ( V_79 , 3 , V_80 ) ;
return;
}
static int F_89 ( struct V_147 * V_4 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
struct V_3 * V_148 = NULL ;
int V_47 = 0 ;
F_36 ( V_79 , 3 , V_80 ) ;
if ( V_6 && V_6 -> V_36 )
V_148 = V_6 -> V_36 -> V_61 ;
if ( ! V_148 )
goto V_149;
F_91 ( V_148 ) ;
V_6 -> V_150 = F_74 ( V_6 -> V_41 ) ;
V_47 = F_86 ( V_148 ) ;
V_149:
return V_47 ;
}
static int F_92 ( struct V_147 * V_4 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
struct V_3 * V_148 = NULL ;
int V_47 = 0 ;
F_36 ( V_79 , 3 , V_80 ) ;
if ( V_6 && V_6 -> V_36 )
V_148 = V_6 -> V_36 -> V_61 ;
if ( ! V_148 )
goto V_149;
switch ( V_6 -> V_150 ) {
case V_134 :
case V_130 :
V_47 = F_85 ( V_148 ) ;
break;
default:
break;
}
F_93 ( V_148 ) ;
V_149:
return V_47 ;
}
static int F_94 ( struct V_59 * V_69 , struct V_3 * V_4 )
{
struct V_5 * V_62 = F_3 ( V_4 ) ;
int V_47 ;
F_36 ( V_79 , 4 , V_80 ) ;
if ( V_69 == NULL ) {
F_36 ( V_40 , 2 , L_32 ) ;
V_62 -> V_74 . V_151 ++ ;
return V_152 ;
}
if ( F_95 ( V_69 ) < V_64 ) {
F_36 ( V_40 , 2 ,
L_33 ) ;
F_83 ( V_69 ) ;
V_62 -> V_74 . V_151 ++ ;
return V_152 ;
}
if ( F_74 ( V_62 -> V_41 ) != V_134 ) {
F_83 ( V_69 ) ;
V_62 -> V_74 . V_151 ++ ;
V_62 -> V_74 . V_110 ++ ;
V_62 -> V_74 . V_153 ++ ;
return V_152 ;
}
if ( F_6 ( V_4 ) ) {
F_36 ( V_40 , 2 , L_34 ) ;
return V_154 ;
}
V_4 -> V_155 = V_156 ;
V_47 = F_76 ( V_62 -> V_36 , V_69 ) ;
F_2 ( V_4 ) ;
return V_47 ? V_154 : V_152 ;
}
static struct V_157 * F_96 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_36 ( V_79 , 5 , V_80 ) ;
return & V_6 -> V_74 ;
}
static int F_97 ( struct V_3 * V_4 , int V_158 )
{
F_36 ( V_79 , 3 , V_80 ) ;
if ( V_158 < 576 || V_158 > V_159 ) {
F_36 ( V_116 , 2 , L_35 ) ;
return - V_49 ;
}
V_4 -> V_160 = V_158 ;
return 0 ;
}
static T_6 F_98 ( struct V_147 * V_4 , struct V_161 * V_162 ,
char * V_163 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 5 , V_80 ) ;
return sprintf ( V_163 , L_36 , F_9 ( V_6 -> V_36 -> V_51 ) ) ;
}
static T_6 F_99 ( struct V_147 * V_4 , struct V_161 * V_162 ,
const char * V_163 , T_7 V_164 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
struct V_3 * V_148 = V_6 -> V_36 -> V_61 ;
char * V_10 ;
char * V_9 ;
char V_165 [ 9 ] ;
int V_166 ;
struct V_35 * V_167 ;
F_36 ( V_79 , 3 , V_80 ) ;
if ( V_164 > 9 ) {
F_33 ( V_116 , 2 ,
L_37 , ( int ) V_164 ) ;
return - V_49 ;
}
V_9 = F_100 ( ( char * * ) & V_163 , L_38 ) ;
for ( V_166 = 0 , V_10 = V_9 ; V_166 < 8 && * V_10 ; V_166 ++ , V_10 ++ ) {
if ( isalnum ( * V_10 ) || ( * V_10 == '$' ) ) {
V_165 [ V_166 ] = toupper ( * V_10 ) ;
continue;
}
if ( * V_10 == '\n' ) {
break;
}
F_33 ( V_116 , 2 ,
L_39 , * V_10 ) ;
return - V_49 ;
}
while ( V_166 < 8 )
V_165 [ V_166 ++ ] = ' ' ;
V_165 [ 8 ] = '\0' ;
if ( memcmp ( V_165 , V_6 -> V_36 -> V_51 , 9 ) &&
( V_148 -> V_114 & ( V_168 | V_169 ) ) ) {
F_36 ( V_116 , 2 , L_40 ) ;
return - V_170 ;
}
F_21 ( & V_50 ) ;
F_22 (cp, &iucv_connection_list, list) {
if ( ! strncmp ( V_165 , V_167 -> V_51 , 9 ) && V_167 -> V_61 != V_148 ) {
F_23 ( & V_50 ) ;
F_33 ( V_116 , 2 , L_41
L_42 , V_165 ) ;
return - V_171 ;
}
}
F_23 ( & V_50 ) ;
memcpy ( V_6 -> V_36 -> V_51 , V_165 , 9 ) ;
return V_164 ;
}
static T_6 F_101 ( struct V_147 * V_4 , struct V_161 * V_162 ,
char * V_163 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 5 , V_80 ) ;
return sprintf ( V_163 , L_43 , V_6 -> V_36 -> V_82 ) ;
}
static T_6 F_102 ( struct V_147 * V_4 , struct V_161 * V_162 ,
const char * V_163 , T_7 V_164 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
struct V_3 * V_148 = V_6 -> V_36 -> V_61 ;
char * V_172 ;
int V_173 ;
F_36 ( V_79 , 3 , V_80 ) ;
if ( V_164 >= 39 )
return - V_49 ;
V_173 = F_103 ( V_163 , & V_172 , 0 ) ;
if ( V_172 && ( ! isspace ( * V_172 ) ) ) {
F_33 ( V_116 , 2 , L_44 , * V_172 ) ;
return - V_49 ;
}
if ( V_173 > V_174 ) {
F_33 ( V_116 , 2 ,
L_45 ,
V_173 ) ;
return - V_49 ;
}
if ( ( V_148 -> V_114 & V_169 ) &&
( V_173 < ( V_148 -> V_160 + V_64 + 2 ) ) ) {
F_33 ( V_116 , 2 ,
L_46 ,
V_173 ) ;
return - V_49 ;
}
if ( V_173 < ( 576 + V_64 + V_64 ) ) {
F_33 ( V_116 , 2 ,
L_46 ,
V_173 ) ;
return - V_49 ;
}
V_6 -> V_36 -> V_82 = V_173 ;
if ( ! ( V_148 -> V_114 & V_169 ) )
V_148 -> V_160 = V_173 - V_64 - V_64 ;
return V_164 ;
}
static T_6 F_104 ( struct V_147 * V_4 , struct V_161 * V_162 ,
char * V_163 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 5 , V_80 ) ;
return sprintf ( V_163 , L_36 , F_105 ( V_6 -> V_41 ) ) ;
}
static T_6 F_106 ( struct V_147 * V_4 ,
struct V_161 * V_162 , char * V_163 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 5 , V_80 ) ;
return sprintf ( V_163 , L_36 , F_105 ( V_6 -> V_36 -> V_41 ) ) ;
}
static T_6 F_107 ( struct V_147 * V_4 ,
struct V_161 * V_162 , char * V_163 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 5 , V_80 ) ;
return sprintf ( V_163 , L_47 , V_6 -> V_36 -> V_93 . V_103 ) ;
}
static T_6 F_108 ( struct V_147 * V_4 ,
struct V_161 * V_162 ,
const char * V_163 , T_7 V_164 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 4 , V_80 ) ;
V_6 -> V_36 -> V_93 . V_103 = 0 ;
return V_164 ;
}
static T_6 F_109 ( struct V_147 * V_4 , struct V_161 * V_162 ,
char * V_163 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 5 , V_80 ) ;
return sprintf ( V_163 , L_47 , V_6 -> V_36 -> V_93 . V_111 ) ;
}
static T_6 F_110 ( struct V_147 * V_4 , struct V_161 * V_162 ,
const char * V_163 , T_7 V_164 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 4 , V_80 ) ;
V_6 -> V_36 -> V_93 . V_111 = 0 ;
return V_164 ;
}
static T_6 F_111 ( struct V_147 * V_4 , struct V_161 * V_162 ,
char * V_163 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 5 , V_80 ) ;
return sprintf ( V_163 , L_47 , V_6 -> V_36 -> V_93 . V_144 ) ;
}
static T_6 F_112 ( struct V_147 * V_4 , struct V_161 * V_162 ,
const char * V_163 , T_7 V_164 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 4 , V_80 ) ;
V_6 -> V_36 -> V_93 . V_144 = 0 ;
return V_164 ;
}
static T_6 F_113 ( struct V_147 * V_4 , struct V_161 * V_162 ,
char * V_163 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 5 , V_80 ) ;
return sprintf ( V_163 , L_47 , V_6 -> V_36 -> V_93 . V_107 ) ;
}
static T_6 F_114 ( struct V_147 * V_4 , struct V_161 * V_162 ,
const char * V_163 , T_7 V_164 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 5 , V_80 ) ;
V_6 -> V_36 -> V_93 . V_107 = 0 ;
return V_164 ;
}
static T_6 F_115 ( struct V_147 * V_4 , struct V_161 * V_162 ,
char * V_163 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 5 , V_80 ) ;
return sprintf ( V_163 , L_47 , V_6 -> V_36 -> V_93 . V_108 ) ;
}
static T_6 F_116 ( struct V_147 * V_4 , struct V_161 * V_162 ,
const char * V_163 , T_7 V_164 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 4 , V_80 ) ;
V_6 -> V_36 -> V_93 . V_108 = 0 ;
return V_164 ;
}
static T_6 F_117 ( struct V_147 * V_4 , struct V_161 * V_162 ,
char * V_163 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 5 , V_80 ) ;
return sprintf ( V_163 , L_47 , V_6 -> V_36 -> V_93 . V_175 ) ;
}
static T_6 F_118 ( struct V_147 * V_4 , struct V_161 * V_162 ,
const char * V_163 , T_7 V_164 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 4 , V_80 ) ;
V_6 -> V_36 -> V_93 . V_175 = 0 ;
return V_164 ;
}
static T_6 F_119 ( struct V_147 * V_4 , struct V_161 * V_162 ,
char * V_163 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 5 , V_80 ) ;
return sprintf ( V_163 , L_47 , V_6 -> V_36 -> V_93 . V_94 ) ;
}
static T_6 F_120 ( struct V_147 * V_4 , struct V_161 * V_162 ,
const char * V_163 , T_7 V_164 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 4 , V_80 ) ;
V_6 -> V_36 -> V_93 . V_94 = 0 ;
return V_164 ;
}
static T_6 F_121 ( struct V_147 * V_4 , struct V_161 * V_162 ,
char * V_163 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 5 , V_80 ) ;
return sprintf ( V_163 , L_47 , V_6 -> V_36 -> V_93 . V_109 ) ;
}
static T_6 F_122 ( struct V_147 * V_4 , struct V_161 * V_162 ,
const char * V_163 , T_7 V_164 )
{
struct V_5 * V_6 = F_90 ( V_4 ) ;
F_36 ( V_79 , 4 , V_80 ) ;
V_6 -> V_36 -> V_93 . V_109 = 0 ;
return V_164 ;
}
static int F_123 ( struct V_147 * V_4 )
{
int V_176 ;
F_36 ( V_79 , 3 , V_80 ) ;
V_176 = F_124 ( & V_4 -> V_177 , & V_178 ) ;
if ( V_176 )
return V_176 ;
V_176 = F_124 ( & V_4 -> V_177 , & V_179 ) ;
if ( V_176 )
F_125 ( & V_4 -> V_177 , & V_178 ) ;
return V_176 ;
}
static void F_126 ( struct V_147 * V_4 )
{
F_36 ( V_79 , 3 , V_80 ) ;
F_125 ( & V_4 -> V_177 , & V_179 ) ;
F_125 ( & V_4 -> V_177 , & V_178 ) ;
}
static int F_127 ( struct V_3 * V_148 )
{
struct V_5 * V_6 = F_3 ( V_148 ) ;
struct V_147 * V_4 = F_128 ( sizeof( struct V_147 ) , V_123 ) ;
int V_176 ;
F_36 ( V_79 , 3 , V_80 ) ;
if ( V_4 ) {
F_129 ( V_4 , L_48 , V_148 -> V_8 ) ;
V_4 -> V_180 = & V_181 ;
V_4 -> V_182 = V_183 ;
V_4 -> V_184 = ( void ( * ) ( struct V_147 * ) ) F_67 ;
V_4 -> V_185 = & V_186 ;
} else
return - V_26 ;
V_176 = F_130 ( V_4 ) ;
if ( V_176 ) {
F_131 ( V_4 ) ;
return V_176 ;
}
V_176 = F_123 ( V_4 ) ;
if ( V_176 )
goto V_187;
V_6 -> V_4 = V_4 ;
F_132 ( V_4 , V_6 ) ;
return 0 ;
V_187:
F_133 ( V_4 ) ;
return V_176 ;
}
static void F_134 ( struct V_147 * V_4 )
{
F_36 ( V_79 , 3 , V_80 ) ;
F_126 ( V_4 ) ;
F_133 ( V_4 ) ;
}
static struct V_35 * F_135 ( struct V_3 * V_4 ,
char * V_165 )
{
struct V_35 * V_36 ;
V_36 = F_128 ( sizeof( * V_36 ) , V_123 ) ;
if ( ! V_36 )
goto V_149;
F_136 ( & V_36 -> V_101 ) ;
F_136 ( & V_36 -> V_95 ) ;
F_137 ( & V_36 -> V_100 ) ;
V_36 -> V_82 = V_188 ;
V_36 -> V_61 = V_4 ;
V_36 -> V_83 = F_80 ( V_36 -> V_82 , V_123 | V_142 ) ;
if ( ! V_36 -> V_83 )
goto V_189;
V_36 -> V_99 = F_80 ( V_36 -> V_82 , V_123 | V_142 ) ;
if ( ! V_36 -> V_99 )
goto V_190;
V_36 -> V_41 = F_138 ( L_49 , V_191 ,
V_192 , V_193 ,
V_194 , V_195 , V_196 ,
V_123 ) ;
if ( ! V_36 -> V_41 )
goto V_197;
F_139 ( V_36 -> V_41 , & V_36 -> V_119 ) ;
F_49 ( V_36 -> V_41 , V_198 ) ;
if ( V_165 ) {
memcpy ( V_36 -> V_51 , V_165 , 9 ) ;
F_49 ( V_36 -> V_41 , V_129 ) ;
}
F_140 ( & V_50 ) ;
F_141 ( & V_36 -> V_199 , & V_200 ) ;
F_142 ( & V_50 ) ;
return V_36 ;
V_197:
F_143 ( V_36 -> V_99 ) ;
V_190:
F_143 ( V_36 -> V_83 ) ;
V_189:
F_67 ( V_36 ) ;
V_149:
return NULL ;
}
static void F_144 ( struct V_35 * V_36 )
{
F_36 ( V_79 , 3 , V_80 ) ;
F_140 ( & V_50 ) ;
F_145 ( & V_36 -> V_199 ) ;
F_142 ( & V_50 ) ;
F_57 ( & V_36 -> V_119 ) ;
F_68 ( & V_36 -> V_101 ) ;
if ( V_36 -> V_32 ) {
F_55 ( V_36 -> V_32 , V_48 ) ;
F_67 ( V_36 -> V_32 ) ;
V_36 -> V_32 = NULL ;
}
F_68 ( & V_36 -> V_95 ) ;
F_146 ( V_36 -> V_41 ) ;
F_143 ( V_36 -> V_83 ) ;
F_143 ( V_36 -> V_99 ) ;
}
static void F_147 ( struct V_3 * V_4 )
{
struct V_5 * V_62 = F_3 ( V_4 ) ;
F_36 ( V_79 , 3 , V_80 ) ;
if ( ! V_4 )
return;
if ( V_62 ) {
if ( V_62 -> V_36 )
F_144 ( V_62 -> V_36 ) ;
if ( V_62 -> V_41 )
F_146 ( V_62 -> V_41 ) ;
V_62 -> V_36 = NULL ; V_62 -> V_41 = NULL ;
}
F_148 ( V_4 ) ;
}
static void F_149 ( struct V_3 * V_4 )
{
V_4 -> V_160 = V_201 ;
V_4 -> V_202 = F_147 ;
V_4 -> V_203 = V_64 ;
V_4 -> V_204 = 0 ;
V_4 -> type = V_205 ;
V_4 -> V_117 = V_113 ;
V_4 -> V_114 = V_206 | V_207 ;
V_4 -> V_208 = & V_209 ;
}
static struct V_3 * F_150 ( char * V_165 )
{
struct V_5 * V_62 ;
struct V_3 * V_4 ;
V_4 = F_151 ( sizeof( struct V_5 ) , L_50 ,
F_149 ) ;
if ( ! V_4 )
return NULL ;
if ( F_152 ( V_4 , V_4 -> V_8 ) < 0 )
goto V_210;
V_62 = F_3 ( V_4 ) ;
V_62 -> V_41 = F_138 ( L_51 , V_211 ,
V_212 , V_213 , V_214 ,
V_215 , V_216 , V_123 ) ;
if ( ! V_62 -> V_41 )
goto V_210;
V_62 -> V_36 = F_135 ( V_4 , V_165 ) ;
if ( ! V_62 -> V_36 ) {
F_36 ( V_116 , 2 , L_52 ) ;
goto V_217;
}
F_49 ( V_62 -> V_41 , V_135 ) ;
return V_4 ;
V_217:
F_146 ( V_62 -> V_41 ) ;
V_210:
F_148 ( V_4 ) ;
return NULL ;
}
static T_6 F_153 ( struct V_218 * V_219 ,
const char * V_163 , T_7 V_164 )
{
const char * V_10 ;
char V_165 [ 9 ] ;
int V_166 , V_47 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_35 * V_167 ;
F_36 ( V_79 , 3 , V_80 ) ;
if ( V_164 > 9 ) {
F_36 ( V_116 , 2 , L_53 ) ;
return - V_49 ;
}
for ( V_166 = 0 , V_10 = V_163 ; V_166 < 8 && * V_10 ; V_166 ++ , V_10 ++ ) {
if ( isalnum ( * V_10 ) || * V_10 == '$' ) {
V_165 [ V_166 ] = toupper ( * V_10 ) ;
continue;
}
if ( * V_10 == '\n' )
break;
F_33 ( V_116 , 2 ,
L_54 , * V_10 ) ;
return - V_49 ;
}
while ( V_166 < 8 )
V_165 [ V_166 ++ ] = ' ' ;
V_165 [ 8 ] = '\0' ;
F_21 ( & V_50 ) ;
F_22 (cp, &iucv_connection_list, list) {
if ( ! strncmp ( V_165 , V_167 -> V_51 , 9 ) ) {
F_23 ( & V_50 ) ;
F_33 ( V_116 , 2 , L_55
L_42 , V_165 ) ;
return - V_171 ;
}
}
F_23 ( & V_50 ) ;
V_4 = F_150 ( V_165 ) ;
if ( ! V_4 ) {
F_36 ( V_116 , 2 , L_56 ) ;
return - V_220 ;
}
V_47 = F_127 ( V_4 ) ;
if ( V_47 ) {
F_33 ( V_116 , 2 ,
L_57 , V_47 ) ;
goto V_221;
}
V_6 = F_3 ( V_4 ) ;
F_154 ( V_4 , V_6 -> V_4 ) ;
V_47 = F_155 ( V_4 ) ;
if ( V_47 )
goto V_187;
F_60 ( V_6 -> V_4 , L_58
L_59 , F_9 ( V_165 ) ) ;
return V_164 ;
V_187:
F_134 ( V_6 -> V_4 ) ;
V_221:
F_147 ( V_4 ) ;
return V_47 ;
}
static T_6 F_156 ( struct V_218 * V_219 ,
const char * V_163 , T_7 V_164 )
{
struct V_35 * V_167 ;
struct V_3 * V_148 ;
struct V_5 * V_6 ;
struct V_147 * V_4 ;
char V_8 [ V_222 ] ;
const char * V_10 ;
int V_166 ;
F_36 ( V_79 , 3 , V_80 ) ;
if ( V_164 >= V_222 )
V_164 = V_222 - 1 ;
for ( V_166 = 0 , V_10 = V_163 ; V_166 < V_164 && * V_10 ; V_166 ++ , V_10 ++ ) {
if ( * V_10 == '\n' || * V_10 == ' ' )
break;
V_8 [ V_166 ] = * V_10 ;
}
V_8 [ V_166 ] = '\0' ;
F_21 ( & V_50 ) ;
F_22 (cp, &iucv_connection_list, list) {
V_148 = V_167 -> V_61 ;
V_6 = F_3 ( V_148 ) ;
V_4 = V_6 -> V_4 ;
if ( strncmp ( V_8 , V_148 -> V_8 , V_164 ) )
continue;
F_23 ( & V_50 ) ;
if ( V_148 -> V_114 & ( V_168 | V_169 ) ) {
F_65 ( V_4 , L_60
L_61 ,
V_6 -> V_36 -> V_51 ) ;
F_36 ( V_40 , 2 , L_62 ) ;
return - V_170 ;
}
F_157 ( V_148 ) ;
F_134 ( V_4 ) ;
return V_164 ;
}
F_23 ( & V_50 ) ;
F_36 ( V_40 , 2 , L_63 ) ;
return - V_49 ;
}
static void F_158 ( void )
{
F_159 ( L_64 ) ;
}
static void T_8 F_160 ( void )
{
struct V_35 * V_167 ;
struct V_3 * V_148 ;
struct V_5 * V_6 ;
struct V_147 * V_4 ;
F_36 ( V_79 , 3 , V_80 ) ;
while ( ! F_161 ( & V_200 ) ) {
V_167 = F_162 ( V_200 . V_72 ,
struct V_35 , V_199 ) ;
V_148 = V_167 -> V_61 ;
V_6 = F_3 ( V_148 ) ;
V_4 = V_6 -> V_4 ;
F_157 ( V_148 ) ;
F_134 ( V_4 ) ;
}
F_133 ( V_223 ) ;
F_163 ( & V_186 ) ;
F_164 ( & V_115 , 1 ) ;
F_10 () ;
F_159 ( L_65 ) ;
return;
}
static int T_9 F_165 ( void )
{
int V_47 ;
V_47 = F_12 () ;
if ( V_47 )
goto V_149;
V_47 = F_166 ( & V_115 , 1 ) ;
if ( V_47 )
goto V_224;
F_36 ( V_79 , 3 , V_80 ) ;
V_186 . V_225 = V_226 ;
V_47 = F_167 ( & V_186 ) ;
if ( V_47 ) {
F_33 ( V_116 , 2 , L_66 , V_47 ) ;
goto V_227;
}
V_223 = F_128 ( sizeof( struct V_147 ) , V_123 ) ;
if ( ! V_223 ) {
V_47 = - V_26 ;
goto V_228;
}
F_129 ( V_223 , L_67 ) ;
V_223 -> V_180 = & V_181 ;
V_223 -> V_182 = V_183 ;
V_223 -> V_184 = ( void ( * ) ( struct V_147 * ) ) F_67 ;
V_223 -> V_185 = & V_186 ;
V_47 = F_130 ( V_223 ) ;
if ( V_47 ) {
F_131 ( V_223 ) ;
goto V_228;
}
F_158 () ;
return V_47 ;
V_228:
F_163 ( & V_186 ) ;
V_227:
F_164 ( & V_115 , 1 ) ;
V_224:
F_10 () ;
V_149:
return V_47 ;
}
