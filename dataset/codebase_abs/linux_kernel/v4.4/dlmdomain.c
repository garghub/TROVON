static inline void F_1 ( T_1 V_1 , T_1 V_2 [] )
{
V_2 [ V_1 >> 3 ] |= ( 1UL << ( V_1 & 7 ) ) ;
}
static inline int F_2 ( T_1 V_1 , T_1 V_2 [] )
{
return ( ( 1UL << ( V_1 & 7 ) ) & ( V_2 [ V_1 >> 3 ] ) ) != 0 ;
}
static inline void F_3 ( T_1 V_3 [] , unsigned long V_4 [] ,
unsigned int V_5 )
{
unsigned int V_6 ;
if ( ! V_5 )
return;
memset ( V_3 , 0 , ( ( V_5 + 7 ) >> 3 ) ) ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
if ( F_4 ( V_6 , V_4 ) )
F_1 ( V_6 , V_3 ) ;
}
static void F_5 ( void * * V_7 , int V_8 )
{
while ( V_8 -- )
F_6 ( ( unsigned long ) V_7 [ V_8 ] ) ;
F_7 ( V_7 ) ;
}
static void * * F_8 ( int V_8 )
{
void * * V_7 = F_9 ( V_8 * sizeof( void * ) , V_9 ) ;
int V_10 ;
if ( ! V_7 )
return NULL ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
if ( ! ( V_7 [ V_10 ] = ( void * ) F_10 ( V_9 ) ) )
goto V_11;
F_11 ( 0 , L_1 ,
V_8 , ( unsigned long ) V_12 ,
( unsigned long ) V_13 ) ;
return V_7 ;
V_11:
F_5 ( V_7 , V_10 ) ;
return NULL ;
}
void F_12 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
if ( F_13 ( & V_17 -> V_18 ) )
return;
F_11 ( 0 , L_2 , V_15 -> V_19 , V_17 -> V_20 . V_21 ,
V_17 -> V_20 . V_19 ) ;
F_14 ( & V_17 -> V_18 ) ;
F_15 ( V_17 ) ;
}
void F_16 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
F_17 ( & V_15 -> V_26 ) ;
V_25 = & V_17 -> V_20 ;
V_23 = F_18 ( V_15 , V_25 -> V_27 ) ;
F_19 ( V_17 ) ;
F_20 ( & V_17 -> V_18 , V_23 ) ;
F_11 ( 0 , L_3 , V_15 -> V_19 , V_17 -> V_20 . V_21 ,
V_17 -> V_20 . V_19 ) ;
}
struct V_16 * F_21 ( struct V_14 * V_15 ,
const char * V_19 ,
unsigned int V_21 ,
unsigned int V_27 )
{
struct V_22 * V_23 ;
struct V_16 * V_17 ;
F_11 ( 0 , L_4 , V_21 , V_19 ) ;
F_17 ( & V_15 -> V_26 ) ;
V_23 = F_18 ( V_15 , V_27 ) ;
F_22 (res, bucket, hash_node) {
if ( V_17 -> V_20 . V_19 [ 0 ] != V_19 [ 0 ] )
continue;
if ( F_23 ( V_17 -> V_20 . V_21 != V_21 ) )
continue;
if ( memcmp ( V_17 -> V_20 . V_19 + 1 , V_19 + 1 , V_21 - 1 ) )
continue;
F_19 ( V_17 ) ;
return V_17 ;
}
return NULL ;
}
struct V_16 * F_24 ( struct V_14 * V_15 ,
const char * V_19 ,
unsigned int V_21 ,
unsigned int V_27 )
{
struct V_16 * V_17 = NULL ;
F_11 ( 0 , L_4 , V_21 , V_19 ) ;
F_17 ( & V_15 -> V_26 ) ;
V_17 = F_21 ( V_15 , V_19 , V_21 , V_27 ) ;
if ( V_17 ) {
F_25 ( & V_17 -> V_26 ) ;
if ( V_17 -> V_28 & V_29 ) {
F_26 ( & V_17 -> V_26 ) ;
F_15 ( V_17 ) ;
return NULL ;
}
F_26 ( & V_17 -> V_26 ) ;
}
return V_17 ;
}
struct V_16 * F_27 ( struct V_14 * V_15 ,
const char * V_19 ,
unsigned int V_21 )
{
struct V_16 * V_17 ;
unsigned int V_27 = F_28 ( V_19 , V_21 ) ;
F_25 ( & V_15 -> V_26 ) ;
V_17 = F_24 ( V_15 , V_19 , V_21 , V_27 ) ;
F_26 ( & V_15 -> V_26 ) ;
return V_17 ;
}
static struct V_14 * F_29 ( const char * V_30 , int V_21 )
{
struct V_14 * V_31 ;
F_17 ( & V_32 ) ;
F_30 (tmp, &dlm_domains, list) {
if ( strlen ( V_31 -> V_19 ) == V_21 &&
memcmp ( V_31 -> V_19 , V_30 , V_21 ) == 0 )
return V_31 ;
}
return NULL ;
}
static struct V_14 * F_31 ( const char * V_30 )
{
F_17 ( & V_32 ) ;
return F_29 ( V_30 , strlen ( V_30 ) ) ;
}
static int F_32 ( const char * V_30 )
{
int V_33 = 0 ;
struct V_14 * V_31 = NULL ;
F_25 ( & V_32 ) ;
V_31 = F_31 ( V_30 ) ;
if ( ! V_31 )
V_33 = 1 ;
else if ( V_31 -> V_34 == V_35 )
V_33 = 1 ;
F_26 ( & V_32 ) ;
return V_33 ;
}
static void F_33 ( struct V_14 * V_15 )
{
F_34 ( V_15 ) ;
if ( V_15 -> V_36 )
F_5 ( ( void * * ) V_15 -> V_36 , V_12 ) ;
if ( V_15 -> V_37 )
F_5 ( ( void * * ) V_15 -> V_37 , V_12 ) ;
F_7 ( V_15 -> V_19 ) ;
F_7 ( V_15 ) ;
}
static void F_35 ( struct V_38 * V_38 )
{
struct V_14 * V_15 ;
V_15 = F_36 ( V_38 , struct V_14 , V_39 ) ;
F_37 ( V_15 -> V_40 ) ;
F_37 ( V_15 -> V_34 == V_35 ) ;
F_38 ( & V_15 -> V_41 ) ;
F_26 ( & V_32 ) ;
F_11 ( 0 , L_5 , V_15 -> V_19 ) ;
F_39 ( & V_42 ) ;
F_33 ( V_15 ) ;
F_25 ( & V_32 ) ;
}
void F_40 ( struct V_14 * V_15 )
{
F_25 ( & V_32 ) ;
F_41 ( & V_15 -> V_39 , F_35 ) ;
F_26 ( & V_32 ) ;
}
static void F_42 ( struct V_14 * V_15 )
{
F_43 ( & V_15 -> V_39 ) ;
}
struct V_14 * F_44 ( struct V_14 * V_15 )
{
struct V_14 * V_43 ;
struct V_14 * V_33 = NULL ;
F_25 ( & V_32 ) ;
F_30 (target, &dlm_domains, list) {
if ( V_43 == V_15 ) {
F_42 ( V_43 ) ;
V_33 = V_43 ;
break;
}
}
F_26 ( & V_32 ) ;
return V_33 ;
}
int F_45 ( struct V_14 * V_15 )
{
int V_33 ;
F_25 ( & V_32 ) ;
V_33 = ( V_15 -> V_34 == V_35 ) ||
( V_15 -> V_34 == V_44 ) ;
F_26 ( & V_32 ) ;
return V_33 ;
}
static void F_46 ( struct V_14 * V_15 )
{
if ( V_15 -> V_45 ) {
F_47 ( V_15 -> V_45 ) ;
F_48 ( V_15 -> V_45 ) ;
V_15 -> V_45 = NULL ;
}
}
static void F_49 ( struct V_14 * V_15 )
{
F_50 ( V_15 ) ;
F_51 ( V_15 ) ;
F_52 ( V_15 ) ;
F_53 ( V_15 ) ;
F_46 ( V_15 ) ;
F_25 ( & V_32 ) ;
F_38 ( & V_15 -> V_41 ) ;
F_26 ( & V_32 ) ;
F_39 ( & V_42 ) ;
}
static int F_54 ( struct V_14 * V_15 )
{
int V_10 , V_46 , V_47 , V_33 = 0 ;
struct V_16 * V_17 ;
struct V_48 * V_49 ;
struct V_22 * V_23 ;
int V_50 ;
F_11 ( 0 , L_6 , V_15 -> V_19 ) ;
V_46 = 0 ;
F_25 ( & V_15 -> V_26 ) ;
for ( V_10 = 0 ; V_10 < V_51 ; V_10 ++ ) {
V_52:
V_47 = 0 ;
V_23 = F_18 ( V_15 , V_10 ) ;
V_49 = V_23 -> V_53 ;
while ( V_49 ) {
V_47 ++ ;
V_17 = F_55 ( V_49 , struct V_16 ,
V_18 ) ;
F_19 ( V_17 ) ;
V_50 = F_56 ( V_15 , V_17 ) ;
F_25 ( & V_17 -> V_26 ) ;
if ( V_50 )
F_57 ( V_15 , V_17 ) ;
else
V_49 = V_17 -> V_18 . V_54 ;
F_26 ( & V_17 -> V_26 ) ;
F_15 ( V_17 ) ;
if ( V_50 ) {
F_58 ( & V_15 -> V_26 ) ;
goto V_52;
}
}
F_58 ( & V_15 -> V_26 ) ;
V_46 += V_47 ;
}
F_26 ( & V_15 -> V_26 ) ;
F_39 ( & V_15 -> V_55 ) ;
if ( V_46 ) {
F_11 ( 0 , L_7 ,
V_15 -> V_19 , V_46 ) ;
V_33 = - V_56 ;
}
F_11 ( 0 , L_8 , V_15 -> V_19 ) ;
return V_33 ;
}
static int F_59 ( struct V_14 * V_15 )
{
int V_33 ;
F_25 ( & V_15 -> V_26 ) ;
V_33 = V_15 -> V_57 == V_58 ;
F_26 ( & V_15 -> V_26 ) ;
return V_33 ;
}
static int F_60 ( struct V_59 * V_60 , T_2 V_21 ,
void * V_61 , void * * V_62 )
{
struct V_14 * V_15 = V_61 ;
unsigned int V_63 ;
struct V_64 * V_65 = (struct V_64 * ) V_60 -> V_66 ;
if ( ! F_44 ( V_15 ) )
return 0 ;
V_63 = V_65 -> V_67 ;
F_11 ( 0 , L_9 , V_15 -> V_19 , V_63 ) ;
F_25 ( & V_15 -> V_26 ) ;
F_61 ( V_63 , V_15 -> V_68 ) ;
F_26 ( & V_15 -> V_26 ) ;
F_40 ( V_15 ) ;
return 0 ;
}
static void F_62 ( struct V_14 * V_15 )
{
V_69:
F_25 ( & V_32 ) ;
F_25 ( & V_15 -> V_26 ) ;
if ( V_15 -> V_57 != V_58 ) {
F_11 ( 0 , L_10 ,
V_15 -> V_57 ) ;
F_26 ( & V_15 -> V_26 ) ;
F_26 ( & V_32 ) ;
F_63 ( V_15 -> V_70 , F_59 ( V_15 ) ) ;
goto V_69;
}
V_15 -> V_34 = V_71 ;
F_26 ( & V_15 -> V_26 ) ;
F_26 ( & V_32 ) ;
}
static void F_64 ( struct V_14 * V_15 )
{
int V_63 = - 1 , V_46 = 0 ;
F_17 ( & V_15 -> V_26 ) ;
F_65 ( L_11 ) ;
while ( ( V_63 = F_66 ( V_15 -> V_72 , V_73 ,
V_63 + 1 ) ) < V_73 ) {
F_65 ( L_12 , V_63 ) ;
++ V_46 ;
}
F_65 ( L_13 , V_46 ) ;
}
static int F_67 ( struct V_59 * V_60 , T_2 V_21 , void * V_61 ,
void * * V_62 )
{
struct V_14 * V_15 = V_61 ;
unsigned int V_63 ;
struct V_64 * V_65 = (struct V_64 * ) V_60 -> V_66 ;
F_11 ( 0 , L_14 , V_60 , V_21 , V_61 ) ;
if ( ! F_44 ( V_15 ) )
return 0 ;
V_63 = V_65 -> V_67 ;
F_25 ( & V_15 -> V_26 ) ;
F_68 ( V_63 , V_15 -> V_72 ) ;
F_68 ( V_63 , V_15 -> V_68 ) ;
F_65 ( V_74 L_15 , V_63 , V_15 -> V_19 ) ;
F_64 ( V_15 ) ;
F_69 ( V_15 , V_63 , 0 ) ;
F_26 ( & V_15 -> V_26 ) ;
F_40 ( V_15 ) ;
return 0 ;
}
static int F_70 ( struct V_14 * V_15 , T_2 V_75 ,
unsigned int V_63 )
{
int V_76 ;
struct V_64 V_77 ;
F_11 ( 0 , L_16 , V_15 -> V_19 ,
V_75 , V_63 ) ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
V_77 . V_67 = V_15 -> V_78 ;
V_76 = F_71 ( V_75 , V_15 -> V_79 , & V_77 ,
sizeof( V_77 ) , V_63 , NULL ) ;
if ( V_76 < 0 )
F_11 ( V_80 , L_17
L_18 , V_76 , V_75 , V_63 ,
V_15 -> V_19 ) ;
return V_76 ;
}
static void F_72 ( struct V_14 * V_15 )
{
int V_63 = - 1 ;
if ( V_15 -> V_81 . V_82 == 1 &&
V_15 -> V_81 . V_83 < 2 )
return;
F_25 ( & V_15 -> V_26 ) ;
while ( 1 ) {
V_63 = F_66 ( V_15 -> V_72 , V_73 , V_63 + 1 ) ;
if ( V_63 >= V_73 )
break;
if ( V_63 == V_15 -> V_78 )
continue;
F_26 ( & V_15 -> V_26 ) ;
F_70 ( V_15 , V_84 , V_63 ) ;
F_25 ( & V_15 -> V_26 ) ;
}
F_26 ( & V_15 -> V_26 ) ;
}
static void F_73 ( struct V_14 * V_15 )
{
int V_63 , V_85 , V_76 ;
F_25 ( & V_15 -> V_26 ) ;
F_68 ( V_15 -> V_78 , V_15 -> V_72 ) ;
while ( ( V_63 = F_66 ( V_15 -> V_72 , V_73 ,
0 ) ) < V_73 ) {
F_26 ( & V_15 -> V_26 ) ;
V_85 = 1 ;
V_76 = F_70 ( V_15 , V_86 ,
V_63 ) ;
if ( V_76 < 0 &&
V_76 != - V_87 &&
V_76 != - V_88 ) {
F_11 ( V_89 , L_19
L_20 , V_76 , V_63 ) ;
F_74 ( V_90 ) ;
V_85 = 0 ;
}
F_25 ( & V_15 -> V_26 ) ;
if ( V_85 )
F_68 ( V_63 , V_15 -> V_72 ) ;
}
F_26 ( & V_15 -> V_26 ) ;
}
int F_75 ( struct V_14 * V_15 )
{
int V_33 = 0 ;
F_25 ( & V_32 ) ;
if ( V_15 -> V_34 == V_44 )
V_33 = 1 ;
F_26 ( & V_32 ) ;
return V_33 ;
}
void F_76 ( struct V_14 * V_15 )
{
int V_91 = 0 ;
struct V_16 * V_17 ;
F_25 ( & V_32 ) ;
F_37 ( V_15 -> V_34 != V_35 ) ;
F_37 ( ! V_15 -> V_40 ) ;
V_15 -> V_40 -- ;
if ( ! V_15 -> V_40 ) {
V_15 -> V_34 = V_44 ;
V_91 = 1 ;
}
F_26 ( & V_32 ) ;
if ( V_91 ) {
F_11 ( 0 , L_21 , V_15 -> V_19 ) ;
F_72 ( V_15 ) ;
F_77 ( V_15 , NULL ) ;
while ( F_54 ( V_15 ) ) {
F_74 ( 500 ) ;
F_11 ( 0 , L_22 , V_15 -> V_19 ) ;
}
if ( ! F_78 ( & V_15 -> V_92 ) ) {
F_11 ( V_80 , L_23
L_24 ) ;
F_30 (res, &dlm->tracking_list, tracking)
F_79 ( V_17 ) ;
}
F_62 ( V_15 ) ;
F_73 ( V_15 ) ;
F_65 ( V_74 L_25 , V_15 -> V_19 ) ;
F_80 ( V_15 ) ;
F_49 ( V_15 ) ;
}
F_40 ( V_15 ) ;
}
static int F_81 ( char * V_93 , int V_63 ,
struct V_94 * V_95 ,
struct V_94 * V_96 )
{
int V_97 ;
struct V_94 V_98 = * V_96 ;
if ( ! F_82 ( V_95 , & V_98 ) ) {
F_11 ( 0 ,
L_26
L_27 ,
V_63 , V_93 ,
V_96 -> V_82 ,
V_96 -> V_83 ,
V_98 . V_82 , V_98 . V_83 ) ;
V_96 -> V_83 = V_98 . V_83 ;
V_97 = 0 ;
} else {
F_11 ( V_89 ,
L_28
L_29 ,
V_63 , V_93 ,
V_96 -> V_82 ,
V_96 -> V_83 ,
V_95 -> V_82 ,
V_95 -> V_83 ) ;
V_97 = 1 ;
}
return V_97 ;
}
static void F_83 ( struct V_99 * V_100 ,
T_2 * V_101 )
{
union V_102 V_103 ;
V_103 . V_100 = * V_100 ;
* V_101 = F_84 ( V_103 . V_104 ) ;
}
static void F_85 ( T_2 V_101 ,
struct V_99 * V_100 )
{
union V_102 V_103 ;
V_103 . V_104 = F_86 ( V_101 ) ;
* V_100 = V_103 . V_100 ;
}
static int F_87 ( struct V_59 * V_60 , T_2 V_21 , void * V_61 ,
void * * V_62 )
{
struct V_105 * V_106 ;
struct V_99 V_100 = {
. V_107 = V_108 ,
} ;
struct V_14 * V_15 = NULL ;
T_2 V_103 ;
T_1 V_109 ;
V_106 = (struct V_105 * ) V_60 -> V_66 ;
F_11 ( 0 , L_30 , V_106 -> V_67 ,
V_106 -> V_30 ) ;
if ( ! F_88 ( V_106 -> V_67 ) ) {
F_11 ( 0 , L_31 ,
V_106 -> V_67 ) ;
V_100 . V_107 = V_108 ;
goto V_110;
}
V_100 . V_107 = V_111 ;
F_25 ( & V_32 ) ;
V_15 = F_29 ( V_106 -> V_30 , V_106 -> V_112 ) ;
if ( ! V_15 )
goto V_113;
V_109 = 0 ;
while ( V_109 < V_73 ) {
if ( F_4 ( V_109 , V_15 -> V_72 ) ) {
if ( ! F_2 ( V_109 , V_106 -> V_114 ) ) {
F_11 ( 0 , L_32
L_33 ,
V_106 -> V_67 , V_109 ) ;
V_100 . V_107 = V_108 ;
goto V_113;
}
}
V_109 ++ ;
}
if ( V_15 -> V_34 != V_71 ) {
int V_115 = V_106 -> V_67 ;
F_25 ( & V_15 -> V_26 ) ;
if ( V_15 -> V_34 == V_116 &&
V_15 -> V_57 == V_58 ) {
V_100 . V_107 = V_111 ;
} else if ( V_15 -> V_57 != V_58 ) {
V_100 . V_107 = V_108 ;
} else if ( V_15 -> V_117 . V_28 & V_118 ) {
F_11 ( 0 , L_34
L_35 , V_115 ) ;
V_100 . V_107 = V_108 ;
} else if ( F_4 ( V_115 , V_15 -> V_119 ) ) {
F_11 ( 0 , L_36
L_37 , V_115 ) ;
V_100 . V_107 = V_108 ;
} else if ( F_4 ( V_115 , V_15 -> V_72 ) ) {
F_11 ( 0 , L_36
L_38 ,
V_115 ) ;
V_100 . V_107 = V_108 ;
} else {
if ( F_81 ( L_39 , V_115 ,
& V_15 -> V_81 ,
& V_106 -> V_120 ) ) {
V_100 . V_107 = V_121 ;
} else if ( F_81 ( L_40 , V_115 ,
& V_15 -> V_122 ,
& V_106 -> V_123 ) ) {
V_100 . V_107 = V_121 ;
} else {
V_100 . V_124 = V_106 -> V_120 . V_83 ;
V_100 . V_125 = V_106 -> V_123 . V_83 ;
V_100 . V_107 = V_126 ;
F_89 ( V_15 , V_106 -> V_67 ) ;
}
}
F_26 ( & V_15 -> V_26 ) ;
}
V_113:
F_26 ( & V_32 ) ;
V_110:
F_11 ( 0 , L_41 , V_100 . V_107 ) ;
F_83 ( & V_100 , & V_103 ) ;
return V_103 ;
}
static int F_90 ( struct V_59 * V_60 , T_2 V_21 , void * V_61 ,
void * * V_62 )
{
struct V_127 * assert ;
struct V_14 * V_15 = NULL ;
assert = (struct V_127 * ) V_60 -> V_66 ;
F_11 ( 0 , L_42 , assert -> V_67 ,
assert -> V_30 ) ;
F_25 ( & V_32 ) ;
V_15 = F_29 ( assert -> V_30 , assert -> V_112 ) ;
if ( V_15 ) {
F_25 ( & V_15 -> V_26 ) ;
F_37 ( V_15 -> V_57 != assert -> V_67 ) ;
if ( V_15 -> V_117 . V_28 & V_118 ) {
F_11 ( 0 , L_43 ) ;
F_26 ( & V_15 -> V_26 ) ;
F_26 ( & V_32 ) ;
return - V_56 ;
}
F_61 ( assert -> V_67 , V_15 -> V_72 ) ;
F_68 ( assert -> V_67 , V_15 -> V_68 ) ;
F_89 ( V_15 , V_58 ) ;
F_65 ( V_74 L_44 ,
assert -> V_67 , V_15 -> V_19 ) ;
F_64 ( V_15 ) ;
F_69 ( V_15 , assert -> V_67 , 1 ) ;
F_26 ( & V_15 -> V_26 ) ;
}
F_26 ( & V_32 ) ;
return 0 ;
}
static int F_91 ( struct V_14 * V_15 ,
struct V_128 * V_129 ,
char * V_130 , int V_131 )
{
char * V_132 = V_129 -> V_133 ;
char * V_134 , * V_135 ;
int V_136 , V_10 , V_137 , V_138 ;
int V_76 = 0 ;
if ( ! F_92 () ) {
if ( V_129 -> V_139 ) {
F_11 ( V_80 , L_45
L_46 ,
V_129 -> V_140 , V_129 -> V_141 , V_15 -> V_78 ) ;
V_76 = - V_142 ;
}
goto V_143;
}
if ( F_92 () && ! V_129 -> V_139 ) {
F_11 ( V_80 , L_47
L_48 ,
V_129 -> V_140 , V_15 -> V_78 , V_129 -> V_141 ) ;
V_76 = - V_142 ;
goto V_143;
}
V_135 = V_132 ;
for ( V_10 = 0 ; V_10 < V_129 -> V_139 ; ++ V_10 ) {
F_11 ( 0 , L_49 , V_144 , V_135 ) ;
V_135 += V_144 ;
}
V_136 = F_93 ( V_145 , V_131 / V_144 ) ;
V_136 = F_94 ( V_130 , ( T_1 ) V_136 ) ;
V_134 = V_130 ;
for ( V_10 = 0 ; V_10 < V_136 ; ++ V_10 ) {
V_138 = 0 ;
V_135 = V_132 ;
for ( V_137 = 0 ; V_137 <= V_129 -> V_139 ; ++ V_137 ) {
if ( ! memcmp ( V_134 , V_135 , V_144 ) ) {
V_138 = 1 ;
break;
}
V_135 += V_144 ;
}
if ( ! V_138 ) {
V_76 = - V_142 ;
F_11 ( V_80 , L_50
L_51 ,
V_129 -> V_140 , V_144 , V_134 ,
V_15 -> V_78 , V_129 -> V_141 ) ;
goto V_143;
}
V_134 += V_144 ;
}
V_135 = V_132 ;
for ( V_10 = 0 ; V_10 < V_129 -> V_139 ; ++ V_10 ) {
V_138 = 0 ;
V_134 = V_130 ;
for ( V_137 = 0 ; V_137 < V_136 ; ++ V_137 ) {
if ( ! memcmp ( V_135 , V_134 , V_144 ) ) {
V_138 = 1 ;
break;
}
V_134 += V_144 ;
}
if ( ! V_138 ) {
V_76 = - V_142 ;
F_11 ( V_80 , L_50
L_52 ,
V_129 -> V_140 , V_144 , V_135 ,
V_129 -> V_141 , V_15 -> V_78 ) ;
goto V_143;
}
V_135 += V_144 ;
}
V_143:
return V_76 ;
}
static int F_95 ( struct V_14 * V_15 , unsigned long * V_114 )
{
struct V_128 * V_129 = NULL ;
int V_76 , V_33 = 0 , V_10 ;
char * V_146 ;
if ( F_66 ( V_114 , V_73 , 0 ) >= V_73 )
goto V_143;
V_129 = F_96 ( sizeof( struct V_128 ) , V_9 ) ;
if ( ! V_129 ) {
V_33 = - V_147 ;
F_97 ( V_33 ) ;
goto V_143;
}
V_129 -> V_141 = V_15 -> V_78 ;
V_129 -> V_148 = strlen ( V_15 -> V_19 ) ;
memcpy ( V_129 -> V_140 , V_15 -> V_19 , V_129 -> V_148 ) ;
if ( F_92 () )
V_129 -> V_139 = F_94 ( V_129 -> V_133 ,
V_145 ) ;
V_146 = V_129 -> V_133 ;
for ( V_10 = 0 ; V_10 < V_129 -> V_139 ; ++ V_10 , V_146 += V_144 )
F_11 ( 0 , L_49 , V_144 , V_146 ) ;
V_10 = - 1 ;
while ( ( V_10 = F_66 ( V_114 , V_73 ,
V_10 + 1 ) ) < V_73 ) {
if ( V_10 == V_15 -> V_78 )
continue;
F_11 ( 0 , L_53 , V_10 ) ;
V_33 = F_71 ( V_149 , V_150 , V_129 ,
sizeof( struct V_128 ) ,
V_10 , & V_76 ) ;
if ( V_33 >= 0 )
V_33 = V_76 ;
if ( V_33 ) {
F_11 ( V_80 , L_54 ,
V_33 , V_10 ) ;
break;
}
}
V_143:
F_7 ( V_129 ) ;
return V_33 ;
}
static int F_98 ( struct V_59 * V_60 , T_2 V_21 ,
void * V_61 , void * * V_62 )
{
struct V_128 * V_129 ;
struct V_14 * V_15 = NULL ;
char * V_130 = NULL ;
int V_76 = 0 ;
V_129 = (struct V_128 * ) V_60 -> V_66 ;
F_11 ( 0 , L_55 , V_129 -> V_141 ,
V_129 -> V_140 ) ;
V_130 = F_9 ( sizeof( V_129 -> V_133 ) , V_9 ) ;
if ( ! V_130 )
return - V_147 ;
V_76 = - V_142 ;
F_25 ( & V_32 ) ;
V_15 = F_29 ( V_129 -> V_140 , V_129 -> V_148 ) ;
if ( ! V_15 ) {
F_11 ( V_80 , L_56
L_57 , V_129 -> V_141 , V_129 -> V_140 ) ;
goto V_151;
}
F_25 ( & V_15 -> V_26 ) ;
if ( V_15 -> V_57 != V_129 -> V_141 ) {
F_11 ( V_80 , L_56
L_58 , V_129 -> V_141 , V_129 -> V_140 ,
V_15 -> V_57 ) ;
goto V_152;
}
if ( V_15 -> V_81 . V_82 == 1 &&
V_15 -> V_81 . V_83 == 0 ) {
F_11 ( V_80 , L_56
L_59 , V_129 -> V_141 ,
V_129 -> V_140 , V_15 -> V_81 . V_82 ,
V_15 -> V_81 . V_83 ) ;
goto V_152;
}
V_76 = F_91 ( V_15 , V_129 , V_130 , sizeof( V_129 -> V_133 ) ) ;
V_152:
F_26 ( & V_15 -> V_26 ) ;
V_151:
F_26 ( & V_32 ) ;
F_7 ( V_130 ) ;
return V_76 ;
}
static int F_99 ( struct V_14 * V_15 , struct V_153 * V_154 )
{
struct V_155 * V_130 ;
struct V_156 * V_132 ;
int V_10 , V_137 ;
int V_76 = 0 ;
for ( V_137 = 0 ; V_137 < V_154 -> V_157 ; ++ V_137 )
F_11 ( 0 , L_60 , V_154 -> V_158 [ V_137 ] . V_159 ,
& ( V_154 -> V_158 [ V_137 ] . V_160 ) ,
F_100 ( V_154 -> V_158 [ V_137 ] . V_161 ) ) ;
for ( V_10 = 0 ; V_10 < V_73 && ! V_76 ; ++ V_10 ) {
V_130 = F_101 ( V_10 ) ;
V_132 = NULL ;
for ( V_137 = 0 ; V_137 < V_154 -> V_157 ; ++ V_137 ) {
if ( V_154 -> V_158 [ V_137 ] . V_159 == V_10 ) {
V_132 = & ( V_154 -> V_158 [ V_137 ] ) ;
break;
}
}
if ( ! V_130 && ! V_132 )
continue;
if ( ( V_130 && ! V_132 ) || ( ! V_130 && V_132 ) )
V_76 = - V_142 ;
if ( ! V_76 &&
( ( V_132 -> V_159 != V_130 -> V_162 ) ||
( V_132 -> V_161 != V_130 -> V_163 ) ||
( V_132 -> V_160 != V_130 -> V_164 ) ) )
V_76 = - V_142 ;
if ( V_76 ) {
if ( V_132 && ! V_130 )
F_11 ( V_80 , L_61
L_62
L_63 , V_154 -> V_165 ,
V_132 -> V_159 ,
& ( V_132 -> V_160 ) ,
F_100 ( V_132 -> V_161 ) ,
V_154 -> V_166 , V_15 -> V_78 ) ;
if ( V_130 && ! V_132 )
F_11 ( V_80 , L_61
L_64
L_65 , V_154 -> V_165 ,
V_130 -> V_162 , & ( V_130 -> V_164 ) ,
F_100 ( V_130 -> V_163 ) ,
V_15 -> V_78 , V_154 -> V_166 ) ;
F_37 ( ( ! V_130 && ! V_132 ) ) ;
}
if ( V_130 )
F_102 ( V_130 ) ;
}
return V_76 ;
}
static int F_103 ( struct V_14 * V_15 , unsigned long * V_114 )
{
struct V_153 * V_154 = NULL ;
struct V_155 * V_63 ;
int V_33 = 0 , V_76 , V_167 , V_10 ;
if ( F_66 ( V_114 , V_73 , 0 ) >= V_73 )
goto V_143;
V_154 = F_96 ( sizeof( struct V_153 ) , V_9 ) ;
if ( ! V_154 ) {
V_33 = - V_147 ;
F_97 ( V_33 ) ;
goto V_143;
}
for ( V_10 = 0 , V_167 = 0 ; V_10 < V_73 ; ++ V_10 ) {
V_63 = F_101 ( V_10 ) ;
if ( ! V_63 )
continue;
V_154 -> V_158 [ V_167 ] . V_159 = V_63 -> V_162 ;
V_154 -> V_158 [ V_167 ] . V_161 = V_63 -> V_163 ;
V_154 -> V_158 [ V_167 ] . V_160 = V_63 -> V_164 ;
F_11 ( 0 , L_60 , V_63 -> V_162 ,
& ( V_63 -> V_164 ) , F_100 ( V_63 -> V_163 ) ) ;
++ V_167 ;
F_102 ( V_63 ) ;
}
V_154 -> V_166 = V_15 -> V_78 ;
V_154 -> V_157 = V_167 ;
V_154 -> V_168 = strlen ( V_15 -> V_19 ) ;
memcpy ( V_154 -> V_165 , V_15 -> V_19 , V_154 -> V_168 ) ;
V_10 = - 1 ;
while ( ( V_10 = F_66 ( V_114 , V_73 ,
V_10 + 1 ) ) < V_73 ) {
if ( V_10 == V_15 -> V_78 )
continue;
F_11 ( 0 , L_66 , V_10 ) ;
V_33 = F_71 ( V_169 , V_150 ,
V_154 , sizeof( struct V_153 ) ,
V_10 , & V_76 ) ;
if ( V_33 >= 0 )
V_33 = V_76 ;
if ( V_33 ) {
F_11 ( V_80 , L_67 , V_33 , V_10 ) ;
break;
}
}
V_143:
F_7 ( V_154 ) ;
return V_33 ;
}
static int F_104 ( struct V_59 * V_60 , T_2 V_21 ,
void * V_61 , void * * V_62 )
{
struct V_153 * V_154 ;
struct V_14 * V_15 = NULL ;
int V_170 = 0 , V_76 = - V_142 ;
V_154 = (struct V_153 * ) V_60 -> V_66 ;
F_11 ( 0 , L_68 , V_154 -> V_166 ,
V_154 -> V_165 ) ;
F_25 ( & V_32 ) ;
V_15 = F_29 ( V_154 -> V_165 , V_154 -> V_168 ) ;
if ( ! V_15 ) {
F_11 ( V_80 , L_69
L_70 , V_154 -> V_166 , V_154 -> V_165 ) ;
goto V_143;
}
F_25 ( & V_15 -> V_26 ) ;
V_170 = 1 ;
if ( V_15 -> V_57 != V_154 -> V_166 ) {
F_11 ( V_80 , L_71
L_72 , V_154 -> V_166 , V_154 -> V_165 ,
V_15 -> V_57 ) ;
goto V_143;
}
if ( V_15 -> V_81 . V_82 == 1 &&
V_15 -> V_81 . V_83 == 0 ) {
F_11 ( V_80 , L_73
L_59 , V_154 -> V_166 ,
V_154 -> V_165 , V_15 -> V_81 . V_82 ,
V_15 -> V_81 . V_83 ) ;
goto V_143;
}
V_76 = F_99 ( V_15 , V_154 ) ;
V_143:
if ( V_170 )
F_26 ( & V_15 -> V_26 ) ;
F_26 ( & V_32 ) ;
return V_76 ;
}
static int F_105 ( struct V_59 * V_60 , T_2 V_21 , void * V_61 ,
void * * V_62 )
{
struct V_171 * V_172 ;
struct V_14 * V_15 = NULL ;
V_172 = (struct V_171 * ) V_60 -> V_66 ;
F_11 ( 0 , L_74 , V_172 -> V_67 ,
V_172 -> V_30 ) ;
F_25 ( & V_32 ) ;
V_15 = F_29 ( V_172 -> V_30 , V_172 -> V_112 ) ;
if ( V_15 ) {
F_25 ( & V_15 -> V_26 ) ;
F_37 ( V_15 -> V_57 != V_172 -> V_67 ) ;
F_89 ( V_15 , V_58 ) ;
F_26 ( & V_15 -> V_26 ) ;
}
F_26 ( & V_32 ) ;
return 0 ;
}
static int F_106 ( struct V_14 * V_15 ,
unsigned int V_63 )
{
int V_76 ;
struct V_171 V_173 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_173 . V_67 = V_15 -> V_78 ;
V_173 . V_112 = strlen ( V_15 -> V_19 ) ;
memcpy ( V_173 . V_30 , V_15 -> V_19 , V_173 . V_112 ) ;
V_76 = F_71 ( V_174 , V_150 ,
& V_173 , sizeof( V_173 ) , V_63 ,
NULL ) ;
if ( V_76 < 0 ) {
F_11 ( V_80 , L_75
L_76 , V_76 , V_174 , V_150 ,
V_63 ) ;
goto V_143;
}
V_143:
return V_76 ;
}
static int F_107 ( struct V_14 * V_15 ,
unsigned long * V_114 ,
unsigned int V_175 )
{
int V_76 , V_176 ;
unsigned int V_63 ;
if ( V_175 != ( F_108 ( V_73 ) *
sizeof( unsigned long ) ) ) {
F_11 ( V_80 ,
L_77 ,
V_175 , ( unsigned ) F_108 ( V_73 ) ) ;
return - V_142 ;
}
V_76 = 0 ;
V_63 = - 1 ;
while ( ( V_63 = F_66 ( V_114 , V_73 ,
V_63 + 1 ) ) < V_73 ) {
if ( V_63 == V_15 -> V_78 )
continue;
V_176 = F_106 ( V_15 , V_63 ) ;
if ( V_176 ) {
F_11 ( V_80 , L_78
L_79 , V_176 , V_63 ) ;
if ( ! V_76 )
V_76 = V_176 ;
}
}
if ( V_76 )
F_97 ( V_76 ) ;
return V_76 ;
}
static int F_109 ( struct V_14 * V_15 ,
int V_63 ,
enum V_177 * V_103 )
{
int V_76 ;
struct V_105 V_178 ;
struct V_99 V_100 ;
T_2 V_179 ;
F_11 ( 0 , L_80 , V_63 ) ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_67 = V_15 -> V_78 ;
V_178 . V_112 = strlen ( V_15 -> V_19 ) ;
memcpy ( V_178 . V_30 , V_15 -> V_19 , V_178 . V_112 ) ;
V_178 . V_120 = V_15 -> V_81 ;
V_178 . V_123 = V_15 -> V_122 ;
F_3 ( V_178 . V_114 , V_15 -> V_180 , V_73 ) ;
V_76 = F_71 ( V_181 , V_150 , & V_178 ,
sizeof( V_178 ) , V_63 , & V_179 ) ;
if ( V_76 < 0 && V_76 != - V_87 ) {
F_11 ( V_80 , L_75
L_76 , V_76 , V_181 , V_150 ,
V_63 ) ;
goto V_143;
}
F_85 ( V_179 , & V_100 ) ;
if ( V_76 == - V_87 ) {
V_76 = 0 ;
* V_103 = V_111 ;
} else {
* V_103 = V_100 . V_107 ;
switch ( V_100 . V_107 ) {
case V_108 :
case V_111 :
break;
case V_121 :
F_11 ( V_89 ,
L_81
L_82
L_83
L_84 ,
V_15 -> V_81 . V_82 ,
V_15 -> V_81 . V_83 ,
V_15 -> V_122 . V_82 ,
V_15 -> V_122 . V_83 ,
V_63 ) ;
V_76 = - V_182 ;
break;
case V_126 :
V_15 -> V_81 . V_83 = V_100 . V_124 ;
V_15 -> V_122 . V_83 = V_100 . V_125 ;
F_11 ( 0 ,
L_85
L_86 ,
V_63 ,
V_15 -> V_81 . V_82 ,
V_15 -> V_81 . V_83 ,
V_15 -> V_122 . V_82 ,
V_15 -> V_122 . V_83 ) ;
break;
default:
V_76 = - V_142 ;
F_11 ( V_80 , L_87 ,
V_100 . V_107 , V_63 ) ;
* V_103 = V_108 ;
break;
}
}
F_11 ( 0 , L_88 , V_76 , V_63 ,
* V_103 ) ;
V_143:
return V_76 ;
}
static int F_110 ( struct V_14 * V_15 ,
unsigned int V_63 )
{
int V_76 ;
int V_33 ;
struct V_127 V_183 ;
F_11 ( 0 , L_89 , V_63 ) ;
memset ( & V_183 , 0 , sizeof( V_183 ) ) ;
V_183 . V_67 = V_15 -> V_78 ;
V_183 . V_112 = strlen ( V_15 -> V_19 ) ;
memcpy ( V_183 . V_30 , V_15 -> V_19 , V_183 . V_112 ) ;
V_76 = F_71 ( V_184 , V_150 ,
& V_183 , sizeof( V_183 ) , V_63 ,
& V_33 ) ;
if ( V_76 < 0 )
F_11 ( V_80 , L_75
L_76 , V_76 , V_184 , V_150 ,
V_63 ) ;
else
V_76 = V_33 ;
return V_76 ;
}
static void F_111 ( struct V_14 * V_15 ,
unsigned long * V_114 )
{
int V_76 , V_63 , V_185 ;
V_76 = 0 ;
V_63 = - 1 ;
while ( ( V_63 = F_66 ( V_114 , V_73 ,
V_63 + 1 ) ) < V_73 ) {
if ( V_63 == V_15 -> V_78 )
continue;
do {
V_76 = F_110 ( V_15 , V_63 ) ;
F_25 ( & V_15 -> V_26 ) ;
V_185 = F_4 ( V_63 , V_15 -> V_180 ) ;
F_26 ( & V_15 -> V_26 ) ;
if ( V_76 ) {
F_11 ( V_80 , L_90
L_91 , V_76 , V_63 ) ;
if ( V_185 )
F_74 ( V_90 ) ;
}
} while ( V_76 && V_185 );
}
}
static int F_112 ( struct V_14 * V_15 ,
struct V_186 * V_187 ,
enum V_177 V_103 )
{
int V_33 ;
if ( V_103 == V_108 ) {
F_11 ( 0 , L_92 ) ;
return 1 ;
}
F_25 ( & V_15 -> V_26 ) ;
V_33 = memcmp ( V_187 -> V_188 , V_15 -> V_180 ,
sizeof( V_15 -> V_180 ) ) ;
F_26 ( & V_15 -> V_26 ) ;
if ( V_33 )
F_11 ( 0 , L_93 ) ;
return V_33 ;
}
static int F_113 ( struct V_14 * V_15 )
{
int V_76 = 0 , V_176 , V_63 ;
struct V_186 * V_187 ;
enum V_177 V_103 = V_108 ;
F_11 ( 0 , L_94 , V_15 ) ;
V_187 = F_96 ( sizeof( * V_187 ) , V_9 ) ;
if ( ! V_187 ) {
V_76 = - V_147 ;
F_97 ( V_76 ) ;
goto V_143;
}
F_114 ( V_15 -> V_180 , sizeof( V_15 -> V_180 ) ) ;
F_25 ( & V_15 -> V_26 ) ;
memcpy ( V_187 -> V_188 , V_15 -> V_180 , sizeof( V_187 -> V_188 ) ) ;
F_89 ( V_15 , V_15 -> V_78 ) ;
F_26 ( & V_15 -> V_26 ) ;
V_63 = - 1 ;
while ( ( V_63 = F_66 ( V_187 -> V_188 , V_73 ,
V_63 + 1 ) ) < V_73 ) {
if ( V_63 == V_15 -> V_78 )
continue;
V_76 = F_109 ( V_15 , V_63 , & V_103 ) ;
if ( V_76 < 0 ) {
F_97 ( V_76 ) ;
goto V_143;
}
if ( V_103 == V_126 )
F_61 ( V_63 , V_187 -> V_189 ) ;
if ( F_112 ( V_15 , V_187 , V_103 ) ) {
V_76 = - V_56 ;
goto V_143;
}
}
F_11 ( 0 , L_95 ) ;
F_25 ( & V_15 -> V_26 ) ;
memcpy ( V_15 -> V_72 , V_187 -> V_189 ,
sizeof( V_187 -> V_189 ) ) ;
F_61 ( V_15 -> V_78 , V_15 -> V_72 ) ;
F_26 ( & V_15 -> V_26 ) ;
if ( V_15 -> V_81 . V_82 > 1 ||
V_15 -> V_81 . V_83 > 0 ) {
V_76 = F_103 ( V_15 , V_187 -> V_189 ) ;
if ( V_76 ) {
F_97 ( V_76 ) ;
goto V_143;
}
V_76 = F_95 ( V_15 , V_187 -> V_189 ) ;
if ( V_76 ) {
F_97 ( V_76 ) ;
goto V_143;
}
}
F_111 ( V_15 , V_187 -> V_189 ) ;
F_25 ( & V_32 ) ;
V_15 -> V_34 = V_35 ;
V_15 -> V_40 ++ ;
F_26 ( & V_32 ) ;
V_143:
F_25 ( & V_15 -> V_26 ) ;
F_89 ( V_15 , V_58 ) ;
if ( ! V_76 ) {
F_65 ( V_74 L_96 , V_15 -> V_19 ) ;
F_64 ( V_15 ) ;
}
F_26 ( & V_15 -> V_26 ) ;
if ( V_187 ) {
if ( V_76 < 0 ) {
V_176 = F_107 ( V_15 ,
V_187 -> V_189 ,
sizeof( V_187 -> V_189 ) ) ;
if ( V_176 < 0 )
F_97 ( V_176 ) ;
}
F_7 ( V_187 ) ;
}
F_11 ( 0 , L_97 , V_76 ) ;
return V_76 ;
}
static void F_50 ( struct V_14 * V_15 )
{
F_115 ( V_15 -> V_19 , & V_15 -> V_190 ) ;
F_115 ( V_15 -> V_19 , & V_15 -> V_191 ) ;
F_116 ( & V_15 -> V_192 ) ;
}
static int F_117 ( struct V_14 * V_15 )
{
int V_76 ;
F_11 ( 0 , L_98 ) ;
F_118 ( & V_15 -> V_191 , V_193 ,
V_194 , V_15 , V_195 ) ;
F_118 ( & V_15 -> V_190 , V_196 ,
V_197 , V_15 , V_198 ) ;
V_76 = F_119 ( V_15 -> V_19 , & V_15 -> V_191 ) ;
if ( V_76 )
goto V_143;
V_76 = F_119 ( V_15 -> V_19 , & V_15 -> V_190 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_199 , V_15 -> V_79 ,
sizeof( struct V_200 ) ,
V_201 ,
V_15 , NULL , & V_15 -> V_192 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_202 , V_15 -> V_79 ,
sizeof( struct V_203 ) ,
V_204 ,
V_15 , V_205 ,
& V_15 -> V_192 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_206 , V_15 -> V_79 ,
sizeof( struct V_207 ) ,
V_208 ,
V_15 , NULL , & V_15 -> V_192 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_209 , V_15 -> V_79 ,
V_210 ,
V_211 ,
V_15 , NULL , & V_15 -> V_192 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_212 , V_15 -> V_79 ,
V_213 ,
V_214 ,
V_15 , NULL , & V_15 -> V_192 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_215 , V_15 -> V_79 ,
V_216 ,
V_217 ,
V_15 , NULL , & V_15 -> V_192 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_86 , V_15 -> V_79 ,
sizeof( struct V_64 ) ,
F_67 ,
V_15 , NULL , & V_15 -> V_192 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_218 , V_15 -> V_79 ,
sizeof( struct V_219 ) ,
V_220 ,
V_15 , NULL , & V_15 -> V_192 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_221 , V_15 -> V_79 ,
sizeof( struct V_222 ) ,
V_223 ,
V_15 , NULL , & V_15 -> V_192 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_224 , V_15 -> V_79 ,
V_225 ,
V_226 ,
V_15 , NULL , & V_15 -> V_192 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_227 , V_15 -> V_79 ,
sizeof( struct V_228 ) ,
V_229 ,
V_15 , NULL , & V_15 -> V_192 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_230 , V_15 -> V_79 ,
sizeof( struct V_231 ) ,
V_232 ,
V_15 , NULL , & V_15 -> V_192 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_233 , V_15 -> V_79 ,
sizeof( struct V_234 ) ,
V_235 ,
V_15 , NULL , & V_15 -> V_192 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_236 , V_15 -> V_79 ,
sizeof( struct V_237 ) ,
V_238 ,
V_15 , NULL , & V_15 -> V_192 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_239 , V_15 -> V_79 ,
sizeof( struct V_240 ) ,
V_241 ,
V_15 , NULL , & V_15 -> V_192 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_84 , V_15 -> V_79 ,
sizeof( struct V_64 ) ,
F_60 ,
V_15 , NULL , & V_15 -> V_192 ) ;
V_143:
if ( V_76 )
F_50 ( V_15 ) ;
return V_76 ;
}
static int F_121 ( struct V_14 * V_15 )
{
int V_76 ;
unsigned int V_242 ;
unsigned int V_243 = 0 ;
char V_244 [ V_245 ] ;
F_37 ( ! V_15 ) ;
F_11 ( 0 , L_99 , V_15 -> V_19 ) ;
V_76 = F_117 ( V_15 ) ;
if ( V_76 ) {
F_97 ( V_76 ) ;
goto V_143;
}
V_76 = F_122 ( V_15 ) ;
if ( V_76 < 0 ) {
F_97 ( V_76 ) ;
goto V_143;
}
V_76 = F_123 ( V_15 ) ;
if ( V_76 < 0 ) {
F_97 ( V_76 ) ;
goto V_143;
}
V_76 = F_124 ( V_15 ) ;
if ( V_76 < 0 ) {
F_97 ( V_76 ) ;
goto V_143;
}
snprintf ( V_244 , V_245 , L_100 , V_15 -> V_19 ) ;
V_15 -> V_45 = F_125 ( V_244 ) ;
if ( ! V_15 -> V_45 ) {
V_76 = - V_147 ;
F_97 ( V_76 ) ;
goto V_143;
}
do {
V_76 = F_113 ( V_15 ) ;
#define F_126 90000
if ( V_76 == - V_56 ) {
if ( F_127 ( V_246 ) ) {
V_76 = - V_247 ;
goto V_143;
}
if ( V_243 > F_126 ) {
V_76 = - V_247 ;
F_11 ( V_89 , L_101
L_102 , V_15 -> V_19 ,
V_243 ) ;
goto V_143;
}
V_242 = ( unsigned int ) ( V_248 & 0x3 ) ;
V_242 *= V_90 ;
V_243 += V_242 ;
F_11 ( 0 , L_103 , V_242 ) ;
F_74 ( V_242 ) ;
}
} while ( V_76 == - V_56 );
if ( V_76 < 0 ) {
F_97 ( V_76 ) ;
goto V_143;
}
V_76 = 0 ;
V_143:
F_39 ( & V_42 ) ;
if ( V_76 ) {
F_50 ( V_15 ) ;
F_51 ( V_15 ) ;
F_52 ( V_15 ) ;
F_53 ( V_15 ) ;
F_46 ( V_15 ) ;
}
return V_76 ;
}
static struct V_14 * F_128 ( const char * V_30 ,
T_2 V_79 )
{
int V_10 ;
int V_33 ;
struct V_14 * V_15 = NULL ;
V_15 = F_96 ( sizeof( * V_15 ) , V_9 ) ;
if ( ! V_15 ) {
V_33 = - V_147 ;
F_97 ( V_33 ) ;
goto V_91;
}
V_15 -> V_19 = F_129 ( V_30 , V_9 ) ;
if ( V_15 -> V_19 == NULL ) {
V_33 = - V_147 ;
F_97 ( V_33 ) ;
goto V_91;
}
V_15 -> V_36 = (struct V_22 * * ) F_8 ( V_12 ) ;
if ( ! V_15 -> V_36 ) {
V_33 = - V_147 ;
F_97 ( V_33 ) ;
goto V_91;
}
for ( V_10 = 0 ; V_10 < V_51 ; V_10 ++ )
F_130 ( F_18 ( V_15 , V_10 ) ) ;
V_15 -> V_37 = (struct V_22 * * )
F_8 ( V_12 ) ;
if ( ! V_15 -> V_37 ) {
V_33 = - V_147 ;
F_97 ( V_33 ) ;
goto V_91;
}
for ( V_10 = 0 ; V_10 < V_51 ; V_10 ++ )
F_130 ( F_131 ( V_15 , V_10 ) ) ;
V_15 -> V_79 = V_79 ;
V_15 -> V_78 = F_132 () ;
V_33 = F_133 ( V_15 ) ;
if ( V_33 < 0 )
goto V_91;
F_134 ( & V_15 -> V_26 ) ;
F_134 ( & V_15 -> V_249 ) ;
F_134 ( & V_15 -> V_250 ) ;
F_134 ( & V_15 -> V_251 ) ;
F_135 ( & V_15 -> V_41 ) ;
F_135 ( & V_15 -> V_252 ) ;
F_135 ( & V_15 -> V_117 . V_253 ) ;
F_135 ( & V_15 -> V_117 . V_254 ) ;
F_135 ( & V_15 -> V_255 ) ;
F_135 ( & V_15 -> V_192 ) ;
F_135 ( & V_15 -> V_92 ) ;
V_15 -> V_117 . V_28 = 0 ;
F_135 ( & V_15 -> V_256 ) ;
F_135 ( & V_15 -> V_257 ) ;
F_11 ( 0 , L_104 ,
V_15 -> V_119 , & ( V_15 -> V_119 [ 0 ] ) ) ;
memset ( V_15 -> V_119 , 0 , sizeof( V_15 -> V_119 ) ) ;
memset ( V_15 -> V_180 , 0 , sizeof( V_15 -> V_180 ) ) ;
memset ( V_15 -> V_72 , 0 , sizeof( V_15 -> V_72 ) ) ;
V_15 -> V_258 = NULL ;
V_15 -> V_259 = NULL ;
V_15 -> V_45 = NULL ;
F_136 ( & V_15 -> V_55 ) ;
F_136 ( & V_15 -> V_260 ) ;
F_136 ( & V_15 -> V_117 . V_261 ) ;
F_136 ( & V_15 -> V_262 ) ;
F_136 ( & V_15 -> V_263 ) ;
F_135 ( & V_15 -> V_264 ) ;
V_15 -> V_57 = V_58 ;
F_136 ( & V_15 -> V_70 ) ;
V_15 -> V_117 . V_265 = V_266 ;
V_15 -> V_117 . V_267 = V_266 ;
F_137 ( & V_15 -> V_268 , 0 ) ;
F_137 ( & V_15 -> V_269 , 0 ) ;
for ( V_10 = 0 ; V_10 < V_270 ; ++ V_10 ) {
F_137 ( & V_15 -> V_271 [ V_10 ] , 0 ) ;
F_137 ( & V_15 -> V_272 [ V_10 ] , 0 ) ;
}
F_134 ( & V_15 -> V_273 ) ;
F_135 ( & V_15 -> V_274 ) ;
F_138 ( & V_15 -> V_275 , V_276 ) ;
F_139 ( & V_15 -> V_39 ) ;
V_15 -> V_34 = V_116 ;
F_135 ( & V_15 -> V_277 ) ;
F_11 ( 0 , L_105 ,
F_140 ( & V_15 -> V_39 . V_278 ) ) ;
V_91:
if ( V_33 < 0 && V_15 ) {
if ( V_15 -> V_37 )
F_5 ( ( void * * ) V_15 -> V_37 ,
V_12 ) ;
if ( V_15 -> V_36 )
F_5 ( ( void * * ) V_15 -> V_36 ,
V_12 ) ;
F_7 ( V_15 -> V_19 ) ;
F_7 ( V_15 ) ;
V_15 = NULL ;
}
return V_15 ;
}
static int F_82 ( struct V_94 * V_279 ,
struct V_94 * V_96 )
{
if ( V_279 -> V_82 != V_96 -> V_82 )
return 1 ;
if ( V_279 -> V_83 > V_96 -> V_83 )
return 1 ;
if ( V_279 -> V_83 < V_96 -> V_83 )
V_96 -> V_83 = V_279 -> V_83 ;
return 0 ;
}
struct V_14 * F_141 ( const char * V_30 ,
T_2 V_79 ,
struct V_94 * V_123 )
{
int V_33 ;
struct V_14 * V_15 = NULL ;
struct V_14 * V_280 = NULL ;
if ( strlen ( V_30 ) >= V_245 ) {
V_33 = - V_281 ;
F_11 ( V_80 , L_106 ) ;
goto V_91;
}
F_11 ( 0 , L_107 , V_30 ) ;
V_282:
V_15 = NULL ;
if ( F_127 ( V_246 ) ) {
V_33 = - V_247 ;
F_97 ( V_33 ) ;
goto V_91;
}
F_25 ( & V_32 ) ;
V_15 = F_31 ( V_30 ) ;
if ( V_15 ) {
if ( V_15 -> V_34 != V_35 ) {
F_26 ( & V_32 ) ;
F_11 ( 0 , L_108 ) ;
F_142 ( V_42 ,
F_32 (
V_30 ) ) ;
goto V_282;
}
if ( F_82 ( & V_15 -> V_122 , V_123 ) ) {
F_26 ( & V_32 ) ;
F_11 ( V_80 ,
L_109
L_110
L_111 , V_30 ) ;
V_33 = - V_182 ;
goto V_91;
}
F_42 ( V_15 ) ;
V_15 -> V_40 ++ ;
F_26 ( & V_32 ) ;
V_33 = 0 ;
goto V_91;
}
if ( ! V_280 ) {
F_26 ( & V_32 ) ;
V_280 = F_128 ( V_30 , V_79 ) ;
if ( V_280 )
goto V_282;
V_33 = - V_147 ;
F_97 ( V_33 ) ;
goto V_91;
}
V_15 = V_280 ;
V_280 = NULL ;
F_143 ( & V_15 -> V_41 , & V_283 ) ;
F_26 ( & V_32 ) ;
V_15 -> V_81 = V_284 ;
V_15 -> V_122 = * V_123 ;
V_33 = F_121 ( V_15 ) ;
if ( V_33 ) {
F_97 ( V_33 ) ;
F_40 ( V_15 ) ;
goto V_91;
}
* V_123 = V_15 -> V_122 ;
V_33 = 0 ;
V_91:
if ( V_280 )
F_33 ( V_280 ) ;
if ( V_33 < 0 )
V_15 = F_144 ( V_33 ) ;
return V_15 ;
}
static void F_145 ( void )
{
F_116 ( & V_285 ) ;
}
static int F_146 ( void )
{
int V_76 = 0 ;
V_76 = F_120 ( V_181 , V_150 ,
sizeof( struct V_105 ) ,
F_87 ,
NULL , NULL , & V_285 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_184 , V_150 ,
sizeof( struct V_127 ) ,
F_90 ,
NULL , NULL , & V_285 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_174 , V_150 ,
sizeof( struct V_171 ) ,
F_105 ,
NULL , NULL , & V_285 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_149 , V_150 ,
sizeof( struct V_128 ) ,
F_98 ,
NULL , NULL , & V_285 ) ;
if ( V_76 )
goto V_143;
V_76 = F_120 ( V_169 , V_150 ,
sizeof( struct V_153 ) ,
F_104 ,
NULL , NULL , & V_285 ) ;
V_143:
if ( V_76 < 0 )
F_145 () ;
return V_76 ;
}
void F_147 ( struct V_14 * V_15 ,
int V_78 )
{
struct V_286 * V_287 ;
F_148 ( & V_288 ) ;
F_30 (cb, &dlm->dlm_eviction_callbacks, ec_item) {
V_287 -> V_289 ( V_78 , V_287 -> V_290 ) ;
}
F_149 ( & V_288 ) ;
}
void F_150 ( struct V_286 * V_287 ,
T_3 * V_291 ,
void * V_61 )
{
F_135 ( & V_287 -> V_292 ) ;
V_287 -> V_289 = V_291 ;
V_287 -> V_290 = V_61 ;
}
void F_151 ( struct V_14 * V_15 ,
struct V_286 * V_287 )
{
F_152 ( & V_288 ) ;
F_143 ( & V_287 -> V_292 , & V_15 -> V_277 ) ;
F_153 ( & V_288 ) ;
}
void F_154 ( struct V_286 * V_287 )
{
F_152 ( & V_288 ) ;
F_38 ( & V_287 -> V_292 ) ;
F_153 ( & V_288 ) ;
}
static int T_4 F_155 ( void )
{
int V_76 ;
V_76 = F_156 () ;
if ( V_76 ) {
F_11 ( V_80 , L_112 ) ;
goto error;
}
V_76 = F_157 () ;
if ( V_76 ) {
F_11 ( V_80 , L_113
L_114 ) ;
goto error;
}
V_76 = F_158 () ;
if ( V_76 ) {
F_11 ( V_80 , L_115 ) ;
goto error;
}
V_76 = F_146 () ;
if ( V_76 ) {
F_11 ( V_80 , L_116 ) ;
goto error;
}
V_76 = F_159 () ;
if ( V_76 )
goto error;
return 0 ;
error:
F_145 () ;
F_160 () ;
F_161 () ;
F_162 () ;
return - 1 ;
}
static void T_5 F_163 ( void )
{
F_164 () ;
F_145 () ;
F_160 () ;
F_161 () ;
F_162 () ;
}
