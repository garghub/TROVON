static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0 , & V_4 -> V_5 ) ;
F_4 ( V_2 ) ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_6 ( V_2 ) ;
return F_7 ( 0 , & V_4 -> V_5 ) ;
}
static char * F_8 ( char * V_6 , int V_7 )
{
static char V_8 [ 17 ] ;
char * V_9 = V_8 ;
memcpy ( V_8 , V_6 , V_7 ) ;
V_8 [ V_7 ] = '\0' ;
while ( * V_9 && ( ( V_9 - V_8 ) < V_7 ) && ( ! isspace ( * V_9 ) ) )
V_9 ++ ;
* V_9 = '\0' ;
return V_8 ;
}
static char * F_9 ( struct V_10 * V_11 )
{
static char V_12 [ 9 ] ;
static char V_13 [ 17 ] ;
static char V_14 [ 100 ] ;
if ( memcmp ( V_11 -> V_15 , V_16 , 16 ) ) {
V_12 [ 8 ] = '\0' ;
V_13 [ 16 ] = '\0' ;
memcpy ( V_12 , V_11 -> V_17 , 8 ) ;
memcpy ( V_12 , F_8 ( V_12 , 8 ) , 8 ) ;
memcpy ( V_13 , V_11 -> V_15 , 16 ) ;
F_10 ( V_13 , 16 ) ;
memcpy ( V_13 , F_8 ( V_13 , 16 ) , 16 ) ;
sprintf ( V_14 , L_1 , V_12 , V_13 ) ;
return V_14 ;
} else
return F_8 ( V_11 -> V_17 , 8 ) ;
}
static void F_11 ( void )
{
if ( V_18 )
F_12 ( V_18 ) ;
if ( V_19 )
F_12 ( V_19 ) ;
if ( V_20 )
F_12 ( V_20 ) ;
}
static int F_13 ( void )
{
V_18 = F_14 ( V_21 ,
V_22 ,
V_23 ,
V_24 ) ;
V_19 = F_14 ( V_25 ,
V_26 ,
V_27 ,
V_28 ) ;
V_20 = F_14 ( V_29 ,
V_30 ,
V_31 ,
V_32 ) ;
if ( ( V_18 == NULL ) || ( V_19 == NULL ) ||
( V_20 == NULL ) ) {
F_11 () ;
return - V_33 ;
}
F_15 ( V_18 , & V_34 ) ;
F_16 ( V_18 , V_35 ) ;
F_15 ( V_19 , & V_34 ) ;
F_16 ( V_19 , V_36 ) ;
F_15 ( V_20 , & V_34 ) ;
F_16 ( V_20 , V_37 ) ;
return 0 ;
}
static void F_17 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_10 * V_11 = V_39 -> V_42 ;
struct V_43 V_44 ;
V_44 . V_11 = V_11 ;
V_44 . V_45 = V_41 ;
F_18 ( V_11 -> V_46 , V_47 , & V_44 ) ;
}
static void F_19 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_10 * V_11 = V_39 -> V_42 ;
struct V_43 V_44 ;
V_44 . V_11 = V_11 ;
V_44 . V_45 = V_41 ;
F_18 ( V_11 -> V_46 , V_48 , & V_44 ) ;
}
static void F_20 ( struct V_38 * V_39 , T_1 V_49 [ 16 ] )
{
struct V_10 * V_11 = V_39 -> V_42 ;
F_18 ( V_11 -> V_46 , V_50 , V_11 ) ;
}
static int F_21 ( struct V_38 * V_39 ,
T_1 V_51 [ 8 ] , T_1 V_49 [ 16 ] )
{
struct V_10 * V_11 = V_39 -> V_42 ;
struct V_43 V_44 ;
static char V_52 [ 9 ] ;
static char V_13 [ 17 ] ;
int V_53 ;
V_53 = - V_54 ;
memcpy ( V_52 , F_8 ( V_51 , 8 ) , 8 ) ;
memcpy ( V_13 , V_49 , 16 ) ;
F_10 ( V_13 , 16 ) ;
F_22 ( & V_55 ) ;
F_23 (conn, &iucv_connection_list, list) {
if ( strncmp ( V_51 , V_11 -> V_17 , 8 ) ||
strncmp ( V_49 , V_11 -> V_15 , 16 ) )
continue;
V_11 -> V_39 = V_39 ;
V_44 . V_11 = V_11 ;
V_44 . V_45 = V_39 ;
F_18 ( V_11 -> V_46 , V_56 , & V_44 ) ;
V_53 = 0 ;
}
F_24 ( V_57 , 2 , L_2 ,
V_52 , F_8 ( V_13 , 16 ) ) ;
F_25 ( & V_55 ) ;
return V_53 ;
}
static void F_26 ( struct V_38 * V_39 , T_1 V_49 [ 16 ] )
{
struct V_10 * V_11 = V_39 -> V_42 ;
F_18 ( V_11 -> V_46 , V_58 , V_11 ) ;
}
static void F_27 ( struct V_38 * V_39 , T_1 V_49 [ 16 ] )
{
struct V_10 * V_11 = V_39 -> V_42 ;
F_18 ( V_11 -> V_46 , V_59 , V_11 ) ;
}
static void F_28 ( struct V_38 * V_39 , T_1 V_49 [ 16 ] )
{
struct V_10 * V_11 = V_39 -> V_42 ;
F_18 ( V_11 -> V_46 , V_60 , V_11 ) ;
}
static void F_29 ( T_2 * V_61 , int V_62 , void * V_63 )
{
}
static void F_30 ( struct V_10 * V_11 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = V_11 -> V_66 ;
struct V_3 * V_67 = F_2 ( V_2 ) ;
T_3 V_68 = 0 ;
F_31 ( V_65 , V_69 ) ;
V_65 -> V_2 = V_2 ;
V_65 -> V_70 = V_71 ;
V_65 -> V_72 = F_32 ( V_73 ) ;
while ( 1 ) {
struct V_64 * V_74 ;
struct V_75 * V_76 = (struct V_75 * ) V_65 -> V_45 ;
if ( ! V_76 -> V_77 )
break;
F_33 ( V_65 , V_69 ) ;
V_76 -> V_77 -= V_68 ;
V_68 += V_76 -> V_77 ;
V_76 -> V_77 -= V_69 ;
if ( F_34 ( V_65 ) < V_76 -> V_77 ) {
F_24 ( V_45 , 2 , L_3 ,
V_76 -> V_77 , F_34 ( V_65 ) ) ;
return;
}
F_31 ( V_65 , V_76 -> V_77 ) ;
F_35 ( V_65 ) ;
V_74 = F_36 ( V_65 -> V_7 ) ;
if ( ! V_74 ) {
F_37 ( V_45 , 2 ,
L_4 ) ;
V_67 -> V_78 . V_79 ++ ;
return;
}
F_38 ( V_65 , F_31 ( V_74 , V_65 -> V_7 ) ,
V_65 -> V_7 ) ;
F_35 ( V_74 ) ;
V_74 -> V_2 = V_65 -> V_2 ;
V_74 -> V_72 = V_65 -> V_72 ;
V_65 -> V_70 = V_80 ;
V_67 -> V_78 . V_81 ++ ;
V_67 -> V_78 . V_82 += V_74 -> V_7 ;
F_39 ( V_74 ) ;
F_33 ( V_65 , V_76 -> V_77 ) ;
F_31 ( V_65 , V_69 ) ;
}
}
static void F_40 ( T_2 * V_61 , int V_62 , void * V_63 )
{
struct V_43 * V_44 = V_63 ;
struct V_10 * V_11 = V_44 -> V_11 ;
struct V_40 * V_41 = V_44 -> V_45 ;
struct V_3 * V_67 = F_2 ( V_11 -> V_66 ) ;
int V_53 ;
F_37 ( V_83 , 4 , V_84 ) ;
if ( ! V_11 -> V_66 ) {
F_41 ( V_11 -> V_39 , V_41 ) ;
F_37 ( V_45 , 2 ,
L_5 ) ;
return;
}
if ( V_41 -> V_85 > V_11 -> V_86 ) {
F_41 ( V_11 -> V_39 , V_41 ) ;
V_67 -> V_78 . V_79 ++ ;
F_24 ( V_45 , 2 , L_6 ,
V_41 -> V_85 , V_11 -> V_86 ) ;
return;
}
V_11 -> V_87 -> V_45 = V_11 -> V_87 -> V_88 ;
F_42 ( V_11 -> V_87 ) ;
V_11 -> V_87 -> V_7 = 0 ;
V_53 = F_43 ( V_11 -> V_39 , V_41 , 0 , V_11 -> V_87 -> V_45 ,
V_41 -> V_85 , NULL ) ;
if ( V_53 || V_41 -> V_85 < 5 ) {
V_67 -> V_78 . V_89 ++ ;
F_24 ( V_45 , 2 , L_7 , V_53 ) ;
return;
}
F_30 ( V_11 , V_11 -> V_87 ) ;
}
static void F_44 ( T_2 * V_61 , int V_62 , void * V_63 )
{
struct V_43 * V_44 = V_63 ;
struct V_10 * V_11 = V_44 -> V_11 ;
struct V_40 * V_41 = V_44 -> V_45 ;
struct V_40 V_90 ;
struct V_3 * V_67 = NULL ;
T_4 V_91 = V_41 -> V_92 ;
T_4 V_93 = 0 ;
T_4 V_94 = 0 ;
T_4 V_95 = 0 ;
struct V_64 * V_74 ;
unsigned long V_96 ;
struct V_75 V_76 ;
int V_53 ;
F_37 ( V_83 , 4 , V_84 ) ;
if ( ! V_11 || ! V_11 -> V_66 ) {
F_37 ( V_45 , 2 ,
L_8 ) ;
return;
}
V_67 = F_2 ( V_11 -> V_66 ) ;
V_11 -> V_97 . V_98 -- ;
if ( V_91 ) {
if ( ( V_74 = F_45 ( & V_11 -> V_99 ) ) ) {
F_46 ( & V_74 -> V_100 ) ;
if ( V_67 ) {
V_67 -> V_78 . V_101 ++ ;
V_67 -> V_78 . V_102 +=
( V_74 -> V_7 - V_69
- V_69 ) ;
}
F_47 ( V_74 ) ;
}
}
V_11 -> V_103 -> V_45 = V_11 -> V_103 -> V_88 ;
F_42 ( V_11 -> V_103 ) ;
V_11 -> V_103 -> V_7 = 0 ;
F_48 ( & V_11 -> V_104 , V_96 ) ;
while ( ( V_74 = F_45 ( & V_11 -> V_105 ) ) ) {
V_76 . V_77 = V_11 -> V_103 -> V_7 + V_74 -> V_7 + V_69 ;
memcpy ( F_31 ( V_11 -> V_103 , V_69 ) , & V_76 ,
V_69 ) ;
F_38 ( V_74 ,
F_31 ( V_11 -> V_103 , V_74 -> V_7 ) ,
V_74 -> V_7 ) ;
V_93 += V_74 -> V_7 ;
V_94 ++ ;
V_95 ++ ;
F_46 ( & V_74 -> V_100 ) ;
F_47 ( V_74 ) ;
}
if ( V_11 -> V_106 > V_11 -> V_97 . V_107 )
V_11 -> V_97 . V_107 = V_11 -> V_106 ;
V_11 -> V_106 = 0 ;
F_49 ( & V_11 -> V_104 , V_96 ) ;
if ( V_11 -> V_103 -> V_7 == 0 ) {
F_50 ( V_61 , V_108 ) ;
return;
}
V_76 . V_77 = 0 ;
memcpy ( F_31 ( V_11 -> V_103 , V_69 ) , & V_76 , V_69 ) ;
V_11 -> V_97 . V_109 = F_51 () ;
V_90 . V_110 = 0 ;
V_90 . V_92 = 0 ;
V_53 = F_52 ( V_11 -> V_39 , & V_90 , 0 , 0 ,
V_11 -> V_103 -> V_45 , V_11 -> V_103 -> V_7 ) ;
V_11 -> V_97 . V_111 ++ ;
V_11 -> V_97 . V_112 += V_11 -> V_103 -> V_7 ;
V_11 -> V_97 . V_98 ++ ;
if ( V_11 -> V_97 . V_98 > V_11 -> V_97 . V_113 )
V_11 -> V_97 . V_113 = V_11 -> V_97 . V_98 ;
if ( V_53 ) {
V_11 -> V_97 . V_98 -- ;
F_50 ( V_61 , V_108 ) ;
if ( V_67 )
V_67 -> V_78 . V_114 += V_94 ;
F_24 ( V_45 , 2 , L_9 , V_53 ) ;
} else {
if ( V_67 ) {
V_67 -> V_78 . V_101 += V_94 ;
V_67 -> V_78 . V_102 += V_93 ;
}
if ( V_95 > V_11 -> V_97 . V_115 )
V_11 -> V_97 . V_115 = V_95 ;
}
}
static void F_53 ( T_2 * V_61 , int V_62 , void * V_63 )
{
struct V_43 * V_44 = V_63 ;
struct V_10 * V_11 = V_44 -> V_11 ;
struct V_38 * V_39 = V_44 -> V_45 ;
struct V_1 * V_66 = V_11 -> V_66 ;
struct V_3 * V_67 = F_2 ( V_66 ) ;
int V_53 ;
F_37 ( V_83 , 3 , V_84 ) ;
V_11 -> V_39 = V_39 ;
V_39 -> V_116 = V_117 ;
V_39 -> V_118 = 0 ;
V_53 = F_54 ( V_39 , & V_119 , V_11 -> V_15 , V_11 ) ;
if ( V_53 ) {
F_24 ( V_57 , 2 , L_10 , V_53 ) ;
return;
}
F_50 ( V_61 , V_108 ) ;
V_66 -> V_120 = V_11 -> V_39 -> V_116 ;
F_18 ( V_67 -> V_46 , V_121 , V_66 ) ;
}
static void F_55 ( T_2 * V_61 , int V_62 , void * V_63 )
{
struct V_43 * V_44 = V_63 ;
struct V_38 * V_39 = V_44 -> V_45 ;
F_37 ( V_83 , 3 , V_84 ) ;
F_56 ( V_39 , NULL ) ;
}
static void F_57 ( T_2 * V_61 , int V_62 , void * V_63 )
{
struct V_10 * V_11 = V_63 ;
struct V_1 * V_66 = V_11 -> V_66 ;
struct V_3 * V_67 = F_2 ( V_66 ) ;
F_37 ( V_83 , 3 , V_84 ) ;
F_58 ( & V_11 -> V_122 ) ;
F_50 ( V_61 , V_108 ) ;
V_66 -> V_120 = V_11 -> V_39 -> V_116 ;
F_18 ( V_67 -> V_46 , V_121 , V_66 ) ;
}
static void F_59 ( T_2 * V_61 , int V_62 , void * V_63 )
{
struct V_10 * V_11 = V_63 ;
F_37 ( V_83 , 3 , V_84 ) ;
F_58 ( & V_11 -> V_122 ) ;
F_56 ( V_11 -> V_39 , V_11 -> V_15 ) ;
F_50 ( V_61 , V_123 ) ;
}
static void F_60 ( T_2 * V_61 , int V_62 , void * V_63 )
{
struct V_10 * V_11 = V_63 ;
struct V_1 * V_66 = V_11 -> V_66 ;
struct V_3 * V_67 = F_2 ( V_66 ) ;
F_37 ( V_83 , 3 , V_84 ) ;
F_58 ( & V_11 -> V_122 ) ;
F_56 ( V_11 -> V_39 , V_11 -> V_15 ) ;
F_61 ( V_67 -> V_2 , L_11
L_12 , F_9 ( V_11 ) ) ;
F_37 ( V_45 , 2 ,
L_13 ) ;
F_50 ( V_61 , V_123 ) ;
F_18 ( V_67 -> V_46 , V_124 , V_66 ) ;
}
static void F_62 ( T_2 * V_61 , int V_62 , void * V_63 )
{
struct V_10 * V_11 = V_63 ;
struct V_1 * V_66 = V_11 -> V_66 ;
struct V_3 * V_67 = F_2 ( V_66 ) ;
int V_53 ;
F_37 ( V_83 , 3 , V_84 ) ;
F_50 ( V_61 , V_123 ) ;
F_50 ( V_61 , V_125 ) ;
V_11 -> V_39 = F_63 ( V_117 , 0 , V_126 ) ;
F_24 ( V_57 , 2 , L_14 ,
V_66 -> V_6 , F_9 ( V_11 ) ) ;
V_53 = F_64 ( V_11 -> V_39 , & V_119 , V_11 -> V_17 ,
NULL , V_11 -> V_15 , V_11 ) ;
switch ( V_53 ) {
case 0 :
V_66 -> V_120 = V_11 -> V_39 -> V_116 ;
F_65 ( & V_11 -> V_122 , V_127 ,
V_128 , V_11 ) ;
return;
case 11 :
F_66 ( V_67 -> V_2 ,
L_15 ,
F_8 ( V_11 -> V_17 , 8 ) ) ;
F_50 ( V_61 , V_123 ) ;
break;
case 12 :
F_66 ( V_67 -> V_2 ,
L_16
L_17 , F_8 ( V_11 -> V_17 , 8 ) ) ;
F_50 ( V_61 , V_123 ) ;
break;
case 13 :
F_67 ( V_67 -> V_2 ,
L_18
L_19 ) ;
F_50 ( V_61 , V_129 ) ;
break;
case 14 :
F_67 ( V_67 -> V_2 ,
L_20
L_21 ,
F_8 ( V_11 -> V_17 , 8 ) ) ;
F_50 ( V_61 , V_129 ) ;
break;
case 15 :
F_67 ( V_67 -> V_2 ,
L_22
L_23 ) ;
F_50 ( V_61 , V_129 ) ;
break;
default:
F_67 ( V_67 -> V_2 ,
L_24 ,
V_53 ) ;
F_50 ( V_61 , V_129 ) ;
break;
}
F_24 ( V_57 , 5 , L_25 , V_53 ) ;
F_68 ( V_11 -> V_39 ) ;
V_11 -> V_39 = NULL ;
}
static void F_69 ( struct V_130 * V_131 )
{
struct V_64 * V_74 ;
while ( ( V_74 = F_45 ( V_131 ) ) ) {
F_46 ( & V_74 -> V_100 ) ;
F_47 ( V_74 ) ;
}
}
static void F_70 ( T_2 * V_61 , int V_62 , void * V_63 )
{
struct V_43 * V_44 = V_63 ;
struct V_10 * V_11 = V_44 -> V_11 ;
struct V_1 * V_66 = V_11 -> V_66 ;
struct V_3 * V_67 = F_2 ( V_66 ) ;
F_37 ( V_83 , 3 , V_84 ) ;
F_58 ( & V_11 -> V_122 ) ;
F_50 ( V_61 , V_132 ) ;
F_69 ( & V_11 -> V_105 ) ;
if ( V_11 -> V_39 ) {
F_37 ( V_83 , 5 , L_26 ) ;
F_56 ( V_11 -> V_39 , V_11 -> V_15 ) ;
F_68 ( V_11 -> V_39 ) ;
V_11 -> V_39 = NULL ;
}
F_69 ( & V_11 -> V_99 ) ;
F_18 ( V_67 -> V_46 , V_124 , V_66 ) ;
}
static void F_71 ( T_2 * V_61 , int V_62 , void * V_63 )
{
struct V_10 * V_11 = V_63 ;
struct V_1 * V_66 = V_11 -> V_66 ;
F_24 ( V_45 , 2 , L_27 ,
V_66 -> V_6 , V_11 -> V_17 ) ;
}
static void F_72 ( T_2 * V_61 , int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
struct V_3 * V_67 = F_2 ( V_2 ) ;
F_37 ( V_83 , 3 , V_84 ) ;
F_50 ( V_61 , V_133 ) ;
F_18 ( V_67 -> V_11 -> V_46 , V_134 , V_67 -> V_11 ) ;
}
static void
F_73 ( T_2 * V_61 , int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
struct V_3 * V_67 = F_2 ( V_2 ) ;
struct V_43 V_44 ;
F_37 ( V_83 , 3 , V_84 ) ;
V_44 . V_11 = V_67 -> V_11 ;
F_50 ( V_61 , V_135 ) ;
F_18 ( V_67 -> V_11 -> V_46 , V_136 , & V_44 ) ;
}
static void
F_74 ( T_2 * V_61 , int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
struct V_3 * V_67 = F_2 ( V_2 ) ;
F_37 ( V_83 , 3 , V_84 ) ;
switch ( F_75 ( V_61 ) ) {
case V_133 :
F_50 ( V_61 , V_137 ) ;
F_61 ( V_67 -> V_2 ,
L_28
L_29 ,
F_9 ( V_67 -> V_11 ) ) ;
F_37 ( V_57 , 3 ,
L_30 ) ;
break;
case V_135 :
F_37 ( V_45 , 2 ,
L_31 ) ;
break;
}
}
static void
F_76 ( T_2 * V_61 , int V_62 , void * V_63 )
{
F_37 ( V_83 , 3 , V_84 ) ;
switch ( F_75 ( V_61 ) ) {
case V_137 :
F_50 ( V_61 , V_133 ) ;
break;
case V_135 :
F_50 ( V_61 , V_138 ) ;
F_37 ( V_57 , 3 , L_32 ) ;
break;
}
}
static int F_77 ( struct V_10 * V_11 ,
struct V_64 * V_74 )
{
struct V_40 V_41 ;
unsigned long V_96 ;
struct V_75 V_76 ;
int V_53 ;
if ( F_75 ( V_11 -> V_46 ) != V_108 ) {
int V_139 = V_74 -> V_7 + V_69 ;
F_48 ( & V_11 -> V_104 , V_96 ) ;
if ( V_11 -> V_106 + V_139 >
( V_11 -> V_86 - V_69 ) ) {
V_53 = - V_140 ;
F_37 ( V_45 , 2 ,
L_33 ) ;
} else {
F_78 ( & V_74 -> V_100 ) ;
F_79 ( & V_11 -> V_105 , V_74 ) ;
V_11 -> V_106 += V_139 ;
V_53 = 0 ;
}
F_49 ( & V_11 -> V_104 , V_96 ) ;
} else {
struct V_64 * V_141 = V_74 ;
unsigned long V_142 = ( ( unsigned long ) ( F_80 ( V_74 ) +
V_69 ) ) >> 31 ;
int V_143 = 0 ;
if ( V_142 || ( F_34 ( V_74 ) < 2 ) ) {
V_141 = F_81 ( V_74 -> V_7 + V_69 +
V_69 , V_144 | V_145 ) ;
if ( ! V_141 ) {
F_37 ( V_45 , 2 , L_34 ) ;
V_53 = - V_33 ;
return V_53 ;
} else {
F_82 ( V_141 , V_69 ) ;
memcpy ( F_31 ( V_141 , V_74 -> V_7 ) ,
V_74 -> V_45 , V_74 -> V_7 ) ;
}
V_143 = 1 ;
}
V_76 . V_77 = V_141 -> V_7 + V_69 ;
memcpy ( F_83 ( V_141 , V_69 ) , & V_76 , V_69 ) ;
V_76 . V_77 = 0 ;
memcpy ( F_31 ( V_141 , V_69 ) , & V_76 , V_69 ) ;
F_50 ( V_11 -> V_46 , V_146 ) ;
V_11 -> V_97 . V_109 = F_51 () ;
V_41 . V_92 = 1 ;
V_41 . V_110 = 0 ;
V_53 = F_52 ( V_11 -> V_39 , & V_41 , 0 , 0 ,
V_141 -> V_45 , V_141 -> V_7 ) ;
V_11 -> V_97 . V_147 ++ ;
V_11 -> V_97 . V_112 += V_74 -> V_7 ;
V_11 -> V_97 . V_98 ++ ;
if ( V_11 -> V_97 . V_98 > V_11 -> V_97 . V_113 )
V_11 -> V_97 . V_113 = V_11 -> V_97 . V_98 ;
if ( V_53 ) {
struct V_3 * V_67 ;
F_50 ( V_11 -> V_46 , V_108 ) ;
V_11 -> V_97 . V_98 -- ;
V_67 = F_2 ( V_11 -> V_66 ) ;
if ( V_67 )
V_67 -> V_78 . V_114 ++ ;
if ( V_143 )
F_84 ( V_141 ) ;
else {
F_33 ( V_74 , V_69 ) ;
F_85 ( V_74 , V_74 -> V_7 - V_69 ) ;
}
F_24 ( V_45 , 2 , L_9 , V_53 ) ;
} else {
if ( V_143 )
F_84 ( V_74 ) ;
F_78 ( & V_141 -> V_100 ) ;
F_79 ( & V_11 -> V_99 , V_141 ) ;
}
}
return V_53 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_18 ( V_4 -> V_46 , V_148 , V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_18 ( V_4 -> V_46 , V_149 , V_2 ) ;
return 0 ;
}
static int F_88 ( struct V_150 * V_2 )
{
F_37 ( V_83 , 3 , V_84 ) ;
return 0 ;
}
static void F_89 ( struct V_150 * V_2 )
{
F_37 ( V_83 , 3 , V_84 ) ;
return;
}
static int F_90 ( struct V_150 * V_2 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
struct V_1 * V_151 = NULL ;
int V_53 = 0 ;
F_37 ( V_83 , 3 , V_84 ) ;
if ( V_4 && V_4 -> V_11 )
V_151 = V_4 -> V_11 -> V_66 ;
if ( ! V_151 )
goto V_152;
F_92 ( V_151 ) ;
V_4 -> V_153 = F_75 ( V_4 -> V_46 ) ;
V_53 = F_87 ( V_151 ) ;
V_152:
return V_53 ;
}
static int F_93 ( struct V_150 * V_2 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
struct V_1 * V_151 = NULL ;
int V_53 = 0 ;
F_37 ( V_83 , 3 , V_84 ) ;
if ( V_4 && V_4 -> V_11 )
V_151 = V_4 -> V_11 -> V_66 ;
if ( ! V_151 )
goto V_152;
switch ( V_4 -> V_153 ) {
case V_137 :
case V_133 :
V_53 = F_86 ( V_151 ) ;
break;
default:
break;
}
F_94 ( V_151 ) ;
V_152:
return V_53 ;
}
static int F_95 ( struct V_64 * V_74 , struct V_1 * V_2 )
{
struct V_3 * V_67 = F_2 ( V_2 ) ;
int V_53 ;
F_37 ( V_83 , 4 , V_84 ) ;
if ( V_74 == NULL ) {
F_37 ( V_45 , 2 , L_35 ) ;
V_67 -> V_78 . V_154 ++ ;
return V_155 ;
}
if ( F_96 ( V_74 ) < V_69 ) {
F_37 ( V_45 , 2 ,
L_36 ) ;
F_84 ( V_74 ) ;
V_67 -> V_78 . V_154 ++ ;
return V_155 ;
}
if ( F_75 ( V_67 -> V_46 ) != V_137 ) {
F_84 ( V_74 ) ;
V_67 -> V_78 . V_154 ++ ;
V_67 -> V_78 . V_114 ++ ;
V_67 -> V_78 . V_156 ++ ;
return V_155 ;
}
if ( F_5 ( V_2 ) ) {
F_37 ( V_45 , 2 , L_37 ) ;
return V_157 ;
}
V_2 -> V_158 = V_159 ;
V_53 = F_77 ( V_67 -> V_11 , V_74 ) ;
F_1 ( V_2 ) ;
return V_53 ? V_157 : V_155 ;
}
static struct V_160 * F_97 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_37 ( V_83 , 5 , V_84 ) ;
return & V_4 -> V_78 ;
}
static int F_98 ( struct V_1 * V_2 , int V_161 )
{
F_37 ( V_83 , 3 , V_84 ) ;
if ( V_161 < 576 || V_161 > V_162 ) {
F_37 ( V_57 , 2 , L_38 ) ;
return - V_54 ;
}
V_2 -> V_163 = V_161 ;
return 0 ;
}
static T_5 F_99 ( struct V_150 * V_2 , struct V_164 * V_165 ,
char * V_14 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 5 , V_84 ) ;
return sprintf ( V_14 , L_39 , F_9 ( V_4 -> V_11 ) ) ;
}
static int F_100 ( const char * V_14 , T_6 V_166 , char * V_167 ,
char * V_15 )
{
const char * V_9 ;
int V_168 ;
V_9 = strchr ( V_14 , '.' ) ;
if ( ( V_9 && ( ( V_166 > 26 ) ||
( ( V_9 - V_14 ) > 8 ) ||
( V_14 + V_166 - V_9 > 18 ) ) ) ||
( ! V_9 && ( V_166 > 9 ) ) ) {
F_37 ( V_57 , 2 , L_40 ) ;
return - V_54 ;
}
for ( V_168 = 0 , V_9 = V_14 ; V_168 < 8 && * V_9 && * V_9 != '.' ; V_168 ++ , V_9 ++ ) {
if ( isalnum ( * V_9 ) || * V_9 == '$' ) {
V_167 [ V_168 ] = toupper ( * V_9 ) ;
continue;
}
if ( * V_9 == '\n' )
break;
F_24 ( V_57 , 2 ,
L_41 , * V_9 ) ;
return - V_54 ;
}
while ( V_168 < 8 )
V_167 [ V_168 ++ ] = ' ' ;
V_167 [ 8 ] = '\0' ;
if ( * V_9 == '.' ) {
V_9 ++ ;
for ( V_168 = 0 ; V_168 < 16 && * V_9 ; V_168 ++ , V_9 ++ ) {
if ( * V_9 == '\n' )
break;
V_15 [ V_168 ] = toupper ( * V_9 ) ;
}
while ( V_168 > 0 && V_168 < 16 )
V_15 [ V_168 ++ ] = ' ' ;
} else
memcpy ( V_15 , V_169 , 16 ) ;
V_15 [ 16 ] = '\0' ;
F_101 ( V_15 , 16 ) ;
return 0 ;
}
static T_5 F_102 ( struct V_150 * V_2 , struct V_164 * V_165 ,
const char * V_14 , T_6 V_166 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
struct V_1 * V_151 = V_4 -> V_11 -> V_66 ;
char V_167 [ 9 ] ;
char V_15 [ 17 ] ;
int V_53 ;
struct V_10 * V_170 ;
F_37 ( V_83 , 3 , V_84 ) ;
V_53 = F_100 ( V_14 , V_166 , V_167 , V_15 ) ;
if ( V_53 )
return V_53 ;
if ( memcmp ( V_167 , V_4 -> V_11 -> V_17 , 9 ) &&
( V_151 -> V_118 & ( V_171 | V_172 ) ) ) {
F_37 ( V_57 , 2 , L_42 ) ;
return - V_173 ;
}
F_22 ( & V_55 ) ;
F_23 (cp, &iucv_connection_list, list) {
if ( ! strncmp ( V_167 , V_170 -> V_17 , 9 ) &&
! strncmp ( V_15 , V_170 -> V_15 , 17 ) && V_170 -> V_66 != V_151 ) {
F_25 ( & V_55 ) ;
F_24 ( V_57 , 2 , L_43
L_44 , F_9 ( V_170 ) ) ;
return - V_174 ;
}
}
F_25 ( & V_55 ) ;
memcpy ( V_4 -> V_11 -> V_17 , V_167 , 9 ) ;
memcpy ( V_4 -> V_11 -> V_15 , V_15 , 17 ) ;
return V_166 ;
}
static T_5 F_103 ( struct V_150 * V_2 , struct V_164 * V_165 ,
char * V_14 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 5 , V_84 ) ;
return sprintf ( V_14 , L_45 , V_4 -> V_11 -> V_86 ) ;
}
static T_5 F_104 ( struct V_150 * V_2 , struct V_164 * V_165 ,
const char * V_14 , T_6 V_166 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
struct V_1 * V_151 = V_4 -> V_11 -> V_66 ;
char * V_175 ;
int V_176 ;
F_37 ( V_83 , 3 , V_84 ) ;
if ( V_166 >= 39 )
return - V_54 ;
V_176 = F_105 ( V_14 , & V_175 , 0 ) ;
if ( V_175 && ( ! isspace ( * V_175 ) ) ) {
F_24 ( V_57 , 2 , L_46 ,
* V_175 ) ;
return - V_54 ;
}
if ( V_176 > V_177 ) {
F_24 ( V_57 , 2 ,
L_47 ,
V_176 ) ;
return - V_54 ;
}
if ( ( V_151 -> V_118 & V_172 ) &&
( V_176 < ( V_151 -> V_163 + V_69 + 2 ) ) ) {
F_24 ( V_57 , 2 ,
L_48 ,
V_176 ) ;
return - V_54 ;
}
if ( V_176 < ( 576 + V_69 + V_69 ) ) {
F_24 ( V_57 , 2 ,
L_48 ,
V_176 ) ;
return - V_54 ;
}
V_4 -> V_11 -> V_86 = V_176 ;
if ( ! ( V_151 -> V_118 & V_172 ) )
V_151 -> V_163 = V_176 - V_69 - V_69 ;
return V_166 ;
}
static T_5 F_106 ( struct V_150 * V_2 , struct V_164 * V_165 ,
char * V_14 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 5 , V_84 ) ;
return sprintf ( V_14 , L_39 , F_107 ( V_4 -> V_46 ) ) ;
}
static T_5 F_108 ( struct V_150 * V_2 ,
struct V_164 * V_165 , char * V_14 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 5 , V_84 ) ;
return sprintf ( V_14 , L_39 , F_107 ( V_4 -> V_11 -> V_46 ) ) ;
}
static T_5 F_109 ( struct V_150 * V_2 ,
struct V_164 * V_165 , char * V_14 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 5 , V_84 ) ;
return sprintf ( V_14 , L_49 , V_4 -> V_11 -> V_97 . V_107 ) ;
}
static T_5 F_110 ( struct V_150 * V_2 ,
struct V_164 * V_165 ,
const char * V_14 , T_6 V_166 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 4 , V_84 ) ;
V_4 -> V_11 -> V_97 . V_107 = 0 ;
return V_166 ;
}
static T_5 F_111 ( struct V_150 * V_2 , struct V_164 * V_165 ,
char * V_14 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 5 , V_84 ) ;
return sprintf ( V_14 , L_49 , V_4 -> V_11 -> V_97 . V_115 ) ;
}
static T_5 F_112 ( struct V_150 * V_2 , struct V_164 * V_165 ,
const char * V_14 , T_6 V_166 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 4 , V_84 ) ;
V_4 -> V_11 -> V_97 . V_115 = 0 ;
return V_166 ;
}
static T_5 F_113 ( struct V_150 * V_2 , struct V_164 * V_165 ,
char * V_14 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 5 , V_84 ) ;
return sprintf ( V_14 , L_49 , V_4 -> V_11 -> V_97 . V_147 ) ;
}
static T_5 F_114 ( struct V_150 * V_2 , struct V_164 * V_165 ,
const char * V_14 , T_6 V_166 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 4 , V_84 ) ;
V_4 -> V_11 -> V_97 . V_147 = 0 ;
return V_166 ;
}
static T_5 F_115 ( struct V_150 * V_2 , struct V_164 * V_165 ,
char * V_14 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 5 , V_84 ) ;
return sprintf ( V_14 , L_49 , V_4 -> V_11 -> V_97 . V_111 ) ;
}
static T_5 F_116 ( struct V_150 * V_2 , struct V_164 * V_165 ,
const char * V_14 , T_6 V_166 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 5 , V_84 ) ;
V_4 -> V_11 -> V_97 . V_111 = 0 ;
return V_166 ;
}
static T_5 F_117 ( struct V_150 * V_2 , struct V_164 * V_165 ,
char * V_14 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 5 , V_84 ) ;
return sprintf ( V_14 , L_49 , V_4 -> V_11 -> V_97 . V_112 ) ;
}
static T_5 F_118 ( struct V_150 * V_2 , struct V_164 * V_165 ,
const char * V_14 , T_6 V_166 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 4 , V_84 ) ;
V_4 -> V_11 -> V_97 . V_112 = 0 ;
return V_166 ;
}
static T_5 F_119 ( struct V_150 * V_2 , struct V_164 * V_165 ,
char * V_14 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 5 , V_84 ) ;
return sprintf ( V_14 , L_49 , V_4 -> V_11 -> V_97 . V_178 ) ;
}
static T_5 F_120 ( struct V_150 * V_2 , struct V_164 * V_165 ,
const char * V_14 , T_6 V_166 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 4 , V_84 ) ;
V_4 -> V_11 -> V_97 . V_178 = 0 ;
return V_166 ;
}
static T_5 F_121 ( struct V_150 * V_2 , struct V_164 * V_165 ,
char * V_14 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 5 , V_84 ) ;
return sprintf ( V_14 , L_49 , V_4 -> V_11 -> V_97 . V_98 ) ;
}
static T_5 F_122 ( struct V_150 * V_2 , struct V_164 * V_165 ,
const char * V_14 , T_6 V_166 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 4 , V_84 ) ;
V_4 -> V_11 -> V_97 . V_98 = 0 ;
return V_166 ;
}
static T_5 F_123 ( struct V_150 * V_2 , struct V_164 * V_165 ,
char * V_14 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 5 , V_84 ) ;
return sprintf ( V_14 , L_49 , V_4 -> V_11 -> V_97 . V_113 ) ;
}
static T_5 F_124 ( struct V_150 * V_2 , struct V_164 * V_165 ,
const char * V_14 , T_6 V_166 )
{
struct V_3 * V_4 = F_91 ( V_2 ) ;
F_37 ( V_83 , 4 , V_84 ) ;
V_4 -> V_11 -> V_97 . V_113 = 0 ;
return V_166 ;
}
static int F_125 ( struct V_1 * V_151 )
{
struct V_3 * V_4 = F_2 ( V_151 ) ;
struct V_150 * V_2 = F_126 ( sizeof( struct V_150 ) , V_126 ) ;
int V_179 ;
F_37 ( V_83 , 3 , V_84 ) ;
if ( V_2 ) {
F_127 ( V_2 , L_50 , V_151 -> V_6 ) ;
V_2 -> V_180 = & V_181 ;
V_2 -> V_182 = V_183 ;
V_2 -> V_184 = V_185 ;
V_2 -> V_186 = ( void ( * ) ( struct V_150 * ) ) F_68 ;
V_2 -> V_187 = & V_188 ;
} else
return - V_33 ;
V_179 = F_128 ( V_2 ) ;
if ( V_179 ) {
F_129 ( V_2 ) ;
return V_179 ;
}
V_4 -> V_2 = V_2 ;
F_130 ( V_2 , V_4 ) ;
return 0 ;
}
static void F_131 ( struct V_150 * V_2 )
{
F_37 ( V_83 , 3 , V_84 ) ;
F_132 ( V_2 ) ;
}
static struct V_10 * F_133 ( struct V_1 * V_2 ,
char * V_167 ,
char * V_15 )
{
struct V_10 * V_11 ;
V_11 = F_126 ( sizeof( * V_11 ) , V_126 ) ;
if ( ! V_11 )
goto V_152;
F_134 ( & V_11 -> V_105 ) ;
F_134 ( & V_11 -> V_99 ) ;
F_135 ( & V_11 -> V_104 ) ;
V_11 -> V_86 = V_189 ;
V_11 -> V_66 = V_2 ;
V_11 -> V_87 = F_81 ( V_11 -> V_86 , V_126 | V_145 ) ;
if ( ! V_11 -> V_87 )
goto V_190;
V_11 -> V_103 = F_81 ( V_11 -> V_86 , V_126 | V_145 ) ;
if ( ! V_11 -> V_103 )
goto V_191;
V_11 -> V_46 = F_136 ( L_51 , V_192 ,
V_193 , V_194 ,
V_195 , V_196 , V_197 ,
V_126 ) ;
if ( ! V_11 -> V_46 )
goto V_198;
F_137 ( V_11 -> V_46 , & V_11 -> V_122 ) ;
F_50 ( V_11 -> V_46 , V_199 ) ;
if ( V_15 )
memcpy ( V_11 -> V_15 , V_15 , 17 ) ;
if ( V_167 ) {
memcpy ( V_11 -> V_17 , V_167 , 9 ) ;
F_50 ( V_11 -> V_46 , V_132 ) ;
}
F_138 ( & V_55 ) ;
F_139 ( & V_11 -> V_200 , & V_201 ) ;
F_140 ( & V_55 ) ;
return V_11 ;
V_198:
F_141 ( V_11 -> V_103 ) ;
V_191:
F_141 ( V_11 -> V_87 ) ;
V_190:
F_68 ( V_11 ) ;
V_152:
return NULL ;
}
static void F_142 ( struct V_10 * V_11 )
{
F_37 ( V_83 , 3 , V_84 ) ;
F_138 ( & V_55 ) ;
F_143 ( & V_11 -> V_200 ) ;
F_140 ( & V_55 ) ;
F_58 ( & V_11 -> V_122 ) ;
F_69 ( & V_11 -> V_105 ) ;
if ( V_11 -> V_39 ) {
F_56 ( V_11 -> V_39 , V_11 -> V_15 ) ;
F_68 ( V_11 -> V_39 ) ;
V_11 -> V_39 = NULL ;
}
F_69 ( & V_11 -> V_99 ) ;
F_144 ( V_11 -> V_46 ) ;
F_141 ( V_11 -> V_87 ) ;
F_141 ( V_11 -> V_103 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
struct V_3 * V_67 = F_2 ( V_2 ) ;
F_37 ( V_83 , 3 , V_84 ) ;
if ( ! V_2 )
return;
if ( V_67 ) {
if ( V_67 -> V_11 )
F_142 ( V_67 -> V_11 ) ;
if ( V_67 -> V_46 )
F_144 ( V_67 -> V_46 ) ;
V_67 -> V_11 = NULL ; V_67 -> V_46 = NULL ;
}
F_146 ( V_2 ) ;
}
static void F_147 ( struct V_1 * V_2 )
{
V_2 -> V_163 = V_202 ;
V_2 -> V_203 = F_145 ;
V_2 -> V_204 = V_69 ;
V_2 -> V_205 = 0 ;
V_2 -> type = V_206 ;
V_2 -> V_120 = V_117 ;
V_2 -> V_118 = V_207 | V_208 ;
V_2 -> V_209 = & V_210 ;
}
static struct V_1 * F_148 ( char * V_167 , char * V_15 )
{
struct V_3 * V_67 ;
struct V_1 * V_2 ;
V_2 = F_149 ( sizeof( struct V_3 ) , L_52 ,
F_147 ) ;
if ( ! V_2 )
return NULL ;
F_150 () ;
if ( F_151 ( V_2 , V_2 -> V_6 ) < 0 )
goto V_211;
V_67 = F_2 ( V_2 ) ;
V_67 -> V_46 = F_136 ( L_53 , V_212 ,
V_213 , V_214 , V_215 ,
V_216 , V_217 , V_126 ) ;
if ( ! V_67 -> V_46 )
goto V_211;
V_67 -> V_11 = F_133 ( V_2 , V_167 , V_15 ) ;
if ( ! V_67 -> V_11 ) {
F_37 ( V_57 , 2 , L_54 ) ;
goto V_218;
}
F_50 ( V_67 -> V_46 , V_138 ) ;
return V_2 ;
V_218:
F_144 ( V_67 -> V_46 ) ;
V_211:
F_152 () ;
F_146 ( V_2 ) ;
return NULL ;
}
static T_5 F_153 ( struct V_219 * V_220 ,
const char * V_14 , T_6 V_166 )
{
char V_167 [ 9 ] ;
char V_15 [ 17 ] ;
int V_53 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_10 * V_170 ;
F_37 ( V_83 , 3 , V_84 ) ;
V_53 = F_100 ( V_14 , V_166 , V_167 , V_15 ) ;
if ( V_53 )
return V_53 ;
F_22 ( & V_55 ) ;
F_23 (cp, &iucv_connection_list, list) {
if ( ! strncmp ( V_167 , V_170 -> V_17 , 9 ) &&
! strncmp ( V_15 , V_170 -> V_15 , 17 ) ) {
F_25 ( & V_55 ) ;
F_24 ( V_57 , 2 , L_55
L_44 , F_9 ( V_170 ) ) ;
return - V_174 ;
}
}
F_25 ( & V_55 ) ;
V_2 = F_148 ( V_167 , V_15 ) ;
if ( ! V_2 ) {
F_37 ( V_57 , 2 , L_56 ) ;
return - V_221 ;
}
V_53 = F_125 ( V_2 ) ;
if ( V_53 ) {
F_152 () ;
F_24 ( V_57 , 2 ,
L_57 , V_53 ) ;
goto V_222;
}
V_4 = F_2 ( V_2 ) ;
F_154 ( V_2 , V_4 -> V_2 ) ;
V_53 = F_155 ( V_2 ) ;
F_152 () ;
if ( V_53 )
goto V_223;
F_61 ( V_4 -> V_2 , L_58
L_59 ,
F_9 ( V_4 -> V_11 ) ) ;
return V_166 ;
V_223:
F_131 ( V_4 -> V_2 ) ;
V_222:
F_145 ( V_2 ) ;
return V_53 ;
}
static T_5 F_156 ( struct V_219 * V_220 ,
const char * V_14 , T_6 V_166 )
{
struct V_10 * V_170 ;
struct V_1 * V_151 ;
struct V_3 * V_4 ;
struct V_150 * V_2 ;
char V_6 [ V_224 ] ;
const char * V_9 ;
int V_168 ;
F_37 ( V_83 , 3 , V_84 ) ;
if ( V_166 >= V_224 )
V_166 = V_224 - 1 ;
for ( V_168 = 0 , V_9 = V_14 ; V_168 < V_166 && * V_9 ; V_168 ++ , V_9 ++ ) {
if ( * V_9 == '\n' || * V_9 == ' ' )
break;
V_6 [ V_168 ] = * V_9 ;
}
V_6 [ V_168 ] = '\0' ;
F_22 ( & V_55 ) ;
F_23 (cp, &iucv_connection_list, list) {
V_151 = V_170 -> V_66 ;
V_4 = F_2 ( V_151 ) ;
V_2 = V_4 -> V_2 ;
if ( strncmp ( V_6 , V_151 -> V_6 , V_166 ) )
continue;
F_25 ( & V_55 ) ;
if ( V_151 -> V_118 & ( V_171 | V_172 ) ) {
F_66 ( V_2 , L_60
L_61 ,
V_4 -> V_11 -> V_17 ) ;
F_37 ( V_45 , 2 , L_62 ) ;
return - V_173 ;
}
F_157 ( V_151 ) ;
F_131 ( V_2 ) ;
return V_166 ;
}
F_25 ( & V_55 ) ;
F_37 ( V_45 , 2 , L_63 ) ;
return - V_54 ;
}
static void F_158 ( void )
{
F_159 ( L_64 ) ;
}
static void T_7 F_160 ( void )
{
struct V_10 * V_170 ;
struct V_1 * V_151 ;
struct V_3 * V_4 ;
struct V_150 * V_2 ;
F_37 ( V_83 , 3 , V_84 ) ;
while ( ! F_161 ( & V_201 ) ) {
V_170 = F_162 ( V_201 . V_77 ,
struct V_10 , V_200 ) ;
V_151 = V_170 -> V_66 ;
V_4 = F_2 ( V_151 ) ;
V_2 = V_4 -> V_2 ;
F_157 ( V_151 ) ;
F_131 ( V_2 ) ;
}
F_132 ( V_225 ) ;
F_163 ( & V_188 ) ;
F_164 ( & V_119 , 1 ) ;
F_11 () ;
F_159 ( L_65 ) ;
return;
}
static int T_8 F_165 ( void )
{
int V_53 ;
V_53 = F_13 () ;
if ( V_53 )
goto V_152;
V_53 = F_166 ( & V_119 , 1 ) ;
if ( V_53 )
goto V_226;
F_37 ( V_83 , 3 , V_84 ) ;
V_188 . V_184 = V_227 ;
V_53 = F_167 ( & V_188 ) ;
if ( V_53 ) {
F_24 ( V_57 , 2 , L_66 , V_53 ) ;
goto V_228;
}
V_225 = F_126 ( sizeof( struct V_150 ) , V_126 ) ;
if ( ! V_225 ) {
V_53 = - V_33 ;
goto V_229;
}
F_127 ( V_225 , L_67 ) ;
V_225 -> V_180 = & V_181 ;
V_225 -> V_182 = V_183 ;
V_225 -> V_186 = ( void ( * ) ( struct V_150 * ) ) F_68 ;
V_225 -> V_187 = & V_188 ;
V_53 = F_128 ( V_225 ) ;
if ( V_53 ) {
F_129 ( V_225 ) ;
goto V_229;
}
F_158 () ;
return V_53 ;
V_229:
F_163 ( & V_188 ) ;
V_228:
F_164 ( & V_119 , 1 ) ;
V_226:
F_11 () ;
V_152:
return V_53 ;
}
