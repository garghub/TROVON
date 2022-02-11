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
F_17 ( & V_15 -> V_24 ) ;
V_23 = F_18 ( V_15 , V_17 -> V_20 . V_25 ) ;
F_19 ( V_17 ) ;
F_20 ( & V_17 -> V_18 , V_23 ) ;
F_11 ( 0 , L_3 , V_15 -> V_19 , V_17 -> V_20 . V_21 ,
V_17 -> V_20 . V_19 ) ;
}
struct V_16 * F_21 ( struct V_14 * V_15 ,
const char * V_19 ,
unsigned int V_21 ,
unsigned int V_25 )
{
struct V_22 * V_23 ;
struct V_16 * V_17 ;
F_11 ( 0 , L_4 , V_21 , V_19 ) ;
F_17 ( & V_15 -> V_24 ) ;
V_23 = F_18 ( V_15 , V_25 ) ;
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
unsigned int V_25 )
{
struct V_16 * V_17 = NULL ;
F_11 ( 0 , L_4 , V_21 , V_19 ) ;
F_17 ( & V_15 -> V_24 ) ;
V_17 = F_21 ( V_15 , V_19 , V_21 , V_25 ) ;
if ( V_17 ) {
F_25 ( & V_17 -> V_24 ) ;
if ( V_17 -> V_26 & V_27 ) {
F_26 ( & V_17 -> V_24 ) ;
F_15 ( V_17 ) ;
return NULL ;
}
F_26 ( & V_17 -> V_24 ) ;
}
return V_17 ;
}
struct V_16 * F_27 ( struct V_14 * V_15 ,
const char * V_19 ,
unsigned int V_21 )
{
struct V_16 * V_17 ;
unsigned int V_25 = F_28 ( V_19 , V_21 ) ;
F_25 ( & V_15 -> V_24 ) ;
V_17 = F_24 ( V_15 , V_19 , V_21 , V_25 ) ;
F_26 ( & V_15 -> V_24 ) ;
return V_17 ;
}
static struct V_14 * F_29 ( const char * V_28 , int V_21 )
{
struct V_14 * V_29 ;
F_17 ( & V_30 ) ;
F_30 (tmp, &dlm_domains, list) {
if ( strlen ( V_29 -> V_19 ) == V_21 &&
memcmp ( V_29 -> V_19 , V_28 , V_21 ) == 0 )
return V_29 ;
}
return NULL ;
}
static struct V_14 * F_31 ( const char * V_28 )
{
F_17 ( & V_30 ) ;
return F_29 ( V_28 , strlen ( V_28 ) ) ;
}
static int F_32 ( const char * V_28 )
{
int V_31 = 0 ;
struct V_14 * V_29 = NULL ;
F_25 ( & V_30 ) ;
V_29 = F_31 ( V_28 ) ;
if ( ! V_29 )
V_31 = 1 ;
else if ( V_29 -> V_32 == V_33 )
V_31 = 1 ;
F_26 ( & V_30 ) ;
return V_31 ;
}
static void F_33 ( struct V_14 * V_15 )
{
F_34 ( V_15 ) ;
if ( V_15 -> V_34 )
F_5 ( ( void * * ) V_15 -> V_34 , V_12 ) ;
if ( V_15 -> V_35 )
F_5 ( ( void * * ) V_15 -> V_35 , V_12 ) ;
F_7 ( V_15 -> V_19 ) ;
F_7 ( V_15 ) ;
}
static void F_35 ( struct V_36 * V_36 )
{
struct V_14 * V_15 ;
V_15 = F_36 ( V_36 , struct V_14 , V_37 ) ;
F_37 ( V_15 -> V_38 ) ;
F_37 ( V_15 -> V_32 == V_33 ) ;
F_38 ( & V_15 -> V_39 ) ;
F_26 ( & V_30 ) ;
F_11 ( 0 , L_5 , V_15 -> V_19 ) ;
F_39 ( & V_40 ) ;
F_33 ( V_15 ) ;
F_25 ( & V_30 ) ;
}
void F_40 ( struct V_14 * V_15 )
{
F_25 ( & V_30 ) ;
F_41 ( & V_15 -> V_37 , F_35 ) ;
F_26 ( & V_30 ) ;
}
static void F_42 ( struct V_14 * V_15 )
{
F_43 ( & V_15 -> V_37 ) ;
}
struct V_14 * F_44 ( struct V_14 * V_15 )
{
struct V_14 * V_41 ;
struct V_14 * V_31 = NULL ;
F_25 ( & V_30 ) ;
F_30 (target, &dlm_domains, list) {
if ( V_41 == V_15 ) {
F_42 ( V_41 ) ;
V_31 = V_41 ;
break;
}
}
F_26 ( & V_30 ) ;
return V_31 ;
}
int F_45 ( struct V_14 * V_15 )
{
int V_31 ;
F_25 ( & V_30 ) ;
V_31 = ( V_15 -> V_32 == V_33 ) ||
( V_15 -> V_32 == V_42 ) ;
F_26 ( & V_30 ) ;
return V_31 ;
}
static void F_46 ( struct V_14 * V_15 )
{
if ( V_15 -> V_43 ) {
F_47 ( V_15 -> V_43 ) ;
F_48 ( V_15 -> V_43 ) ;
V_15 -> V_43 = NULL ;
}
}
static void F_49 ( struct V_14 * V_15 )
{
F_50 ( V_15 ) ;
F_51 ( V_15 ) ;
F_52 ( V_15 ) ;
F_53 ( V_15 ) ;
F_46 ( V_15 ) ;
F_25 ( & V_30 ) ;
F_38 ( & V_15 -> V_39 ) ;
F_26 ( & V_30 ) ;
F_39 ( & V_40 ) ;
}
static int F_54 ( struct V_14 * V_15 )
{
int V_10 , V_44 , V_45 , V_31 = 0 ;
struct V_16 * V_17 ;
struct V_46 * V_47 ;
struct V_22 * V_23 ;
int V_48 ;
F_11 ( 0 , L_6 , V_15 -> V_19 ) ;
V_44 = 0 ;
F_25 ( & V_15 -> V_24 ) ;
for ( V_10 = 0 ; V_10 < V_49 ; V_10 ++ ) {
V_50:
V_45 = 0 ;
V_23 = F_18 ( V_15 , V_10 ) ;
V_47 = V_23 -> V_51 ;
while ( V_47 ) {
V_45 ++ ;
V_17 = F_55 ( V_47 , struct V_16 ,
V_18 ) ;
F_19 ( V_17 ) ;
V_48 = F_56 ( V_15 , V_17 ) ;
F_25 ( & V_17 -> V_24 ) ;
if ( V_48 )
F_57 ( V_15 , V_17 ) ;
else
V_47 = V_17 -> V_18 . V_52 ;
F_26 ( & V_17 -> V_24 ) ;
F_15 ( V_17 ) ;
if ( V_48 ) {
F_58 ( & V_15 -> V_24 ) ;
goto V_50;
}
}
F_58 ( & V_15 -> V_24 ) ;
V_44 += V_45 ;
}
F_26 ( & V_15 -> V_24 ) ;
F_39 ( & V_15 -> V_53 ) ;
if ( V_44 ) {
F_11 ( 0 , L_7 ,
V_15 -> V_19 , V_44 ) ;
V_31 = - V_54 ;
}
F_11 ( 0 , L_8 , V_15 -> V_19 ) ;
return V_31 ;
}
static int F_59 ( struct V_14 * V_15 )
{
int V_31 ;
F_25 ( & V_15 -> V_24 ) ;
V_31 = V_15 -> V_55 == V_56 ;
F_26 ( & V_15 -> V_24 ) ;
return V_31 ;
}
static int F_60 ( struct V_57 * V_58 , T_2 V_21 ,
void * V_59 , void * * V_60 )
{
struct V_14 * V_15 = V_59 ;
unsigned int V_61 ;
struct V_62 * V_63 = (struct V_62 * ) V_58 -> V_64 ;
if ( ! F_44 ( V_15 ) )
return 0 ;
V_61 = V_63 -> V_65 ;
F_11 ( 0 , L_9 , V_15 -> V_19 , V_61 ) ;
F_25 ( & V_15 -> V_24 ) ;
F_61 ( V_61 , V_15 -> V_66 ) ;
F_26 ( & V_15 -> V_24 ) ;
F_40 ( V_15 ) ;
return 0 ;
}
static void F_62 ( struct V_14 * V_15 )
{
V_67:
F_25 ( & V_30 ) ;
F_25 ( & V_15 -> V_24 ) ;
if ( V_15 -> V_55 != V_56 ) {
F_11 ( 0 , L_10 ,
V_15 -> V_55 ) ;
F_26 ( & V_15 -> V_24 ) ;
F_26 ( & V_30 ) ;
F_63 ( V_15 -> V_68 , F_59 ( V_15 ) ) ;
goto V_67;
}
V_15 -> V_32 = V_69 ;
F_26 ( & V_15 -> V_24 ) ;
F_26 ( & V_30 ) ;
}
static void F_64 ( struct V_14 * V_15 )
{
int V_61 = - 1 , V_44 = 0 ;
F_17 ( & V_15 -> V_24 ) ;
F_65 ( L_11 ) ;
while ( ( V_61 = F_66 ( V_15 -> V_70 , V_71 ,
V_61 + 1 ) ) < V_71 ) {
F_65 ( L_12 , V_61 ) ;
++ V_44 ;
}
F_65 ( L_13 , V_44 ) ;
}
static int F_67 ( struct V_57 * V_58 , T_2 V_21 , void * V_59 ,
void * * V_60 )
{
struct V_14 * V_15 = V_59 ;
unsigned int V_61 ;
struct V_62 * V_63 = (struct V_62 * ) V_58 -> V_64 ;
F_11 ( 0 , L_14 , V_58 , V_21 , V_59 ) ;
if ( ! F_44 ( V_15 ) )
return 0 ;
V_61 = V_63 -> V_65 ;
F_25 ( & V_15 -> V_24 ) ;
F_68 ( V_61 , V_15 -> V_70 ) ;
F_68 ( V_61 , V_15 -> V_66 ) ;
F_65 ( V_72 L_15 , V_61 , V_15 -> V_19 ) ;
F_64 ( V_15 ) ;
F_69 ( V_15 , V_61 , 0 ) ;
F_26 ( & V_15 -> V_24 ) ;
F_40 ( V_15 ) ;
return 0 ;
}
static int F_70 ( struct V_14 * V_15 , T_2 V_73 ,
unsigned int V_61 )
{
int V_74 ;
struct V_62 V_75 ;
F_11 ( 0 , L_16 , V_15 -> V_19 ,
V_73 , V_61 ) ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_65 = V_15 -> V_76 ;
V_74 = F_71 ( V_73 , V_15 -> V_77 , & V_75 ,
sizeof( V_75 ) , V_61 , NULL ) ;
if ( V_74 < 0 )
F_11 ( V_78 , L_17
L_18 , V_74 , V_73 , V_61 ,
V_15 -> V_19 ) ;
return V_74 ;
}
static void F_72 ( struct V_14 * V_15 )
{
int V_61 = - 1 ;
if ( V_15 -> V_79 . V_80 == 1 &&
V_15 -> V_79 . V_81 < 2 )
return;
F_25 ( & V_15 -> V_24 ) ;
while ( 1 ) {
V_61 = F_66 ( V_15 -> V_70 , V_71 , V_61 + 1 ) ;
if ( V_61 >= V_71 )
break;
if ( V_61 == V_15 -> V_76 )
continue;
F_26 ( & V_15 -> V_24 ) ;
F_70 ( V_15 , V_82 , V_61 ) ;
F_25 ( & V_15 -> V_24 ) ;
}
F_26 ( & V_15 -> V_24 ) ;
}
static void F_73 ( struct V_14 * V_15 )
{
int V_61 , V_83 , V_74 ;
F_25 ( & V_15 -> V_24 ) ;
F_68 ( V_15 -> V_76 , V_15 -> V_70 ) ;
while ( ( V_61 = F_66 ( V_15 -> V_70 , V_71 ,
0 ) ) < V_71 ) {
F_26 ( & V_15 -> V_24 ) ;
V_83 = 1 ;
V_74 = F_70 ( V_15 , V_84 ,
V_61 ) ;
if ( V_74 < 0 &&
V_74 != - V_85 &&
V_74 != - V_86 ) {
F_11 ( V_87 , L_19
L_20 , V_74 , V_61 ) ;
F_74 ( V_88 ) ;
V_83 = 0 ;
}
F_25 ( & V_15 -> V_24 ) ;
if ( V_83 )
F_68 ( V_61 , V_15 -> V_70 ) ;
}
F_26 ( & V_15 -> V_24 ) ;
}
int F_75 ( struct V_14 * V_15 )
{
int V_31 = 0 ;
F_25 ( & V_30 ) ;
if ( V_15 -> V_32 == V_42 )
V_31 = 1 ;
F_26 ( & V_30 ) ;
return V_31 ;
}
void F_76 ( struct V_14 * V_15 )
{
int V_89 = 0 ;
struct V_16 * V_17 ;
F_25 ( & V_30 ) ;
F_37 ( V_15 -> V_32 != V_33 ) ;
F_37 ( ! V_15 -> V_38 ) ;
V_15 -> V_38 -- ;
if ( ! V_15 -> V_38 ) {
V_15 -> V_32 = V_42 ;
V_89 = 1 ;
}
F_26 ( & V_30 ) ;
if ( V_89 ) {
F_11 ( 0 , L_21 , V_15 -> V_19 ) ;
F_72 ( V_15 ) ;
F_77 ( V_15 , NULL ) ;
while ( F_54 ( V_15 ) ) {
F_74 ( 500 ) ;
F_11 ( 0 , L_22 , V_15 -> V_19 ) ;
}
if ( ! F_78 ( & V_15 -> V_90 ) ) {
F_11 ( V_78 , L_23
L_24 ) ;
F_30 (res, &dlm->tracking_list, tracking)
F_79 ( V_17 ) ;
}
F_62 ( V_15 ) ;
F_73 ( V_15 ) ;
F_65 ( V_72 L_25 , V_15 -> V_19 ) ;
F_80 ( V_15 ) ;
F_49 ( V_15 ) ;
}
F_40 ( V_15 ) ;
}
static int F_81 ( char * V_91 , int V_61 ,
struct V_92 * V_93 ,
struct V_92 * V_94 )
{
int V_95 ;
struct V_92 V_96 = * V_94 ;
if ( ! F_82 ( V_93 , & V_96 ) ) {
F_11 ( 0 ,
L_26
L_27 ,
V_61 , V_91 ,
V_94 -> V_80 ,
V_94 -> V_81 ,
V_96 . V_80 , V_96 . V_81 ) ;
V_94 -> V_81 = V_96 . V_81 ;
V_95 = 0 ;
} else {
F_11 ( V_87 ,
L_28
L_29 ,
V_61 , V_91 ,
V_94 -> V_80 ,
V_94 -> V_81 ,
V_93 -> V_80 ,
V_93 -> V_81 ) ;
V_95 = 1 ;
}
return V_95 ;
}
static void F_83 ( struct V_97 * V_98 ,
T_2 * V_99 )
{
union V_100 V_101 ;
V_101 . V_98 = * V_98 ;
* V_99 = F_84 ( V_101 . V_102 ) ;
}
static void F_85 ( T_2 V_99 ,
struct V_97 * V_98 )
{
union V_100 V_101 ;
V_101 . V_102 = F_86 ( V_99 ) ;
* V_98 = V_101 . V_98 ;
}
static int F_87 ( struct V_57 * V_58 , T_2 V_21 , void * V_59 ,
void * * V_60 )
{
struct V_103 * V_104 ;
struct V_97 V_98 = {
. V_105 = V_106 ,
} ;
struct V_14 * V_15 = NULL ;
T_2 V_101 ;
T_1 V_107 ;
V_104 = (struct V_103 * ) V_58 -> V_64 ;
F_11 ( 0 , L_30 , V_104 -> V_65 ,
V_104 -> V_28 ) ;
if ( ! F_88 ( V_104 -> V_65 ) ) {
F_11 ( 0 , L_31 ,
V_104 -> V_65 ) ;
V_98 . V_105 = V_106 ;
goto V_108;
}
V_98 . V_105 = V_109 ;
F_25 ( & V_30 ) ;
V_15 = F_29 ( V_104 -> V_28 , V_104 -> V_110 ) ;
if ( ! V_15 )
goto V_111;
V_107 = 0 ;
while ( V_107 < V_71 ) {
if ( F_4 ( V_107 , V_15 -> V_70 ) ) {
if ( ! F_2 ( V_107 , V_104 -> V_112 ) ) {
F_11 ( 0 , L_32
L_33 ,
V_104 -> V_65 , V_107 ) ;
V_98 . V_105 = V_106 ;
goto V_111;
}
}
V_107 ++ ;
}
if ( V_15 -> V_32 != V_69 ) {
int V_113 = V_104 -> V_65 ;
F_25 ( & V_15 -> V_24 ) ;
if ( V_15 -> V_32 == V_114 &&
V_15 -> V_55 == V_56 ) {
V_98 . V_105 = V_109 ;
} else if ( V_15 -> V_55 != V_56 ) {
V_98 . V_105 = V_106 ;
} else if ( V_15 -> V_115 . V_26 & V_116 ) {
F_11 ( 0 , L_34
L_35 , V_113 ) ;
V_98 . V_105 = V_106 ;
} else if ( F_4 ( V_113 , V_15 -> V_117 ) ) {
F_11 ( 0 , L_36
L_37 , V_113 ) ;
V_98 . V_105 = V_106 ;
} else if ( F_4 ( V_113 , V_15 -> V_70 ) ) {
F_11 ( 0 , L_36
L_38 ,
V_113 ) ;
V_98 . V_105 = V_106 ;
} else {
if ( F_81 ( L_39 , V_113 ,
& V_15 -> V_79 ,
& V_104 -> V_118 ) ) {
V_98 . V_105 = V_119 ;
} else if ( F_81 ( L_40 , V_113 ,
& V_15 -> V_120 ,
& V_104 -> V_121 ) ) {
V_98 . V_105 = V_119 ;
} else {
V_98 . V_122 = V_104 -> V_118 . V_81 ;
V_98 . V_123 = V_104 -> V_121 . V_81 ;
V_98 . V_105 = V_124 ;
F_89 ( V_15 , V_104 -> V_65 ) ;
}
}
F_26 ( & V_15 -> V_24 ) ;
}
V_111:
F_26 ( & V_30 ) ;
V_108:
F_11 ( 0 , L_41 , V_98 . V_105 ) ;
F_83 ( & V_98 , & V_101 ) ;
return V_101 ;
}
static int F_90 ( struct V_57 * V_58 , T_2 V_21 , void * V_59 ,
void * * V_60 )
{
struct V_125 * assert ;
struct V_14 * V_15 = NULL ;
assert = (struct V_125 * ) V_58 -> V_64 ;
F_11 ( 0 , L_42 , assert -> V_65 ,
assert -> V_28 ) ;
F_25 ( & V_30 ) ;
V_15 = F_29 ( assert -> V_28 , assert -> V_110 ) ;
if ( V_15 ) {
F_25 ( & V_15 -> V_24 ) ;
F_37 ( V_15 -> V_55 != assert -> V_65 ) ;
if ( V_15 -> V_115 . V_26 & V_116 ) {
F_11 ( 0 , L_43 ) ;
F_26 ( & V_15 -> V_24 ) ;
F_26 ( & V_30 ) ;
return - V_54 ;
}
F_61 ( assert -> V_65 , V_15 -> V_70 ) ;
F_68 ( assert -> V_65 , V_15 -> V_66 ) ;
F_89 ( V_15 , V_56 ) ;
F_65 ( V_72 L_44 ,
assert -> V_65 , V_15 -> V_19 ) ;
F_64 ( V_15 ) ;
F_69 ( V_15 , assert -> V_65 , 1 ) ;
F_26 ( & V_15 -> V_24 ) ;
}
F_26 ( & V_30 ) ;
return 0 ;
}
static int F_91 ( struct V_14 * V_15 ,
struct V_126 * V_127 ,
char * V_128 , int V_129 )
{
char * V_130 = V_127 -> V_131 ;
char * V_132 , * V_133 ;
int V_134 , V_10 , V_135 , V_136 ;
int V_74 = 0 ;
if ( ! F_92 () ) {
if ( V_127 -> V_137 ) {
F_11 ( V_78 , L_45
L_46 ,
V_127 -> V_138 , V_127 -> V_139 , V_15 -> V_76 ) ;
V_74 = - V_140 ;
}
goto V_141;
}
if ( F_92 () && ! V_127 -> V_137 ) {
F_11 ( V_78 , L_47
L_48 ,
V_127 -> V_138 , V_15 -> V_76 , V_127 -> V_139 ) ;
V_74 = - V_140 ;
goto V_141;
}
V_133 = V_130 ;
for ( V_10 = 0 ; V_10 < V_127 -> V_137 ; ++ V_10 ) {
F_11 ( 0 , L_49 , V_142 , V_133 ) ;
V_133 += V_142 ;
}
V_134 = F_93 ( V_143 , V_129 / V_142 ) ;
V_134 = F_94 ( V_128 , ( T_1 ) V_134 ) ;
V_132 = V_128 ;
for ( V_10 = 0 ; V_10 < V_134 ; ++ V_10 ) {
V_136 = 0 ;
V_133 = V_130 ;
for ( V_135 = 0 ; V_135 <= V_127 -> V_137 ; ++ V_135 ) {
if ( ! memcmp ( V_132 , V_133 , V_142 ) ) {
V_136 = 1 ;
break;
}
V_133 += V_142 ;
}
if ( ! V_136 ) {
V_74 = - V_140 ;
F_11 ( V_78 , L_50
L_51 ,
V_127 -> V_138 , V_142 , V_132 ,
V_15 -> V_76 , V_127 -> V_139 ) ;
goto V_141;
}
V_132 += V_142 ;
}
V_133 = V_130 ;
for ( V_10 = 0 ; V_10 < V_127 -> V_137 ; ++ V_10 ) {
V_136 = 0 ;
V_132 = V_128 ;
for ( V_135 = 0 ; V_135 < V_134 ; ++ V_135 ) {
if ( ! memcmp ( V_133 , V_132 , V_142 ) ) {
V_136 = 1 ;
break;
}
V_132 += V_142 ;
}
if ( ! V_136 ) {
V_74 = - V_140 ;
F_11 ( V_78 , L_50
L_52 ,
V_127 -> V_138 , V_142 , V_133 ,
V_127 -> V_139 , V_15 -> V_76 ) ;
goto V_141;
}
V_133 += V_142 ;
}
V_141:
return V_74 ;
}
static int F_95 ( struct V_14 * V_15 , unsigned long * V_112 )
{
struct V_126 * V_127 = NULL ;
int V_74 , V_31 = 0 , V_10 ;
char * V_144 ;
if ( F_66 ( V_112 , V_71 , 0 ) >= V_71 )
goto V_141;
V_127 = F_96 ( sizeof( struct V_126 ) , V_9 ) ;
if ( ! V_127 ) {
V_31 = - V_145 ;
F_97 ( V_31 ) ;
goto V_141;
}
V_127 -> V_139 = V_15 -> V_76 ;
V_127 -> V_146 = strlen ( V_15 -> V_19 ) ;
memcpy ( V_127 -> V_138 , V_15 -> V_19 , V_127 -> V_146 ) ;
if ( F_92 () )
V_127 -> V_137 = F_94 ( V_127 -> V_131 ,
V_143 ) ;
V_144 = V_127 -> V_131 ;
for ( V_10 = 0 ; V_10 < V_127 -> V_137 ; ++ V_10 , V_144 += V_142 )
F_11 ( 0 , L_49 , V_142 , V_144 ) ;
V_10 = - 1 ;
while ( ( V_10 = F_66 ( V_112 , V_71 ,
V_10 + 1 ) ) < V_71 ) {
if ( V_10 == V_15 -> V_76 )
continue;
F_11 ( 0 , L_53 , V_10 ) ;
V_31 = F_71 ( V_147 , V_148 , V_127 ,
sizeof( struct V_126 ) ,
V_10 , & V_74 ) ;
if ( V_31 >= 0 )
V_31 = V_74 ;
if ( V_31 ) {
F_11 ( V_78 , L_54 ,
V_31 , V_10 ) ;
break;
}
}
V_141:
F_7 ( V_127 ) ;
return V_31 ;
}
static int F_98 ( struct V_57 * V_58 , T_2 V_21 ,
void * V_59 , void * * V_60 )
{
struct V_126 * V_127 ;
struct V_14 * V_15 = NULL ;
char * V_128 = NULL ;
int V_74 = 0 ;
V_127 = (struct V_126 * ) V_58 -> V_64 ;
F_11 ( 0 , L_55 , V_127 -> V_139 ,
V_127 -> V_138 ) ;
V_128 = F_9 ( sizeof( V_127 -> V_131 ) , V_9 ) ;
if ( ! V_128 )
return - V_145 ;
V_74 = - V_140 ;
F_25 ( & V_30 ) ;
V_15 = F_29 ( V_127 -> V_138 , V_127 -> V_146 ) ;
if ( ! V_15 ) {
F_11 ( V_78 , L_56
L_57 , V_127 -> V_139 , V_127 -> V_138 ) ;
goto V_149;
}
F_25 ( & V_15 -> V_24 ) ;
if ( V_15 -> V_55 != V_127 -> V_139 ) {
F_11 ( V_78 , L_56
L_58 , V_127 -> V_139 , V_127 -> V_138 ,
V_15 -> V_55 ) ;
goto V_150;
}
if ( V_15 -> V_79 . V_80 == 1 &&
V_15 -> V_79 . V_81 == 0 ) {
F_11 ( V_78 , L_56
L_59 , V_127 -> V_139 ,
V_127 -> V_138 , V_15 -> V_79 . V_80 ,
V_15 -> V_79 . V_81 ) ;
goto V_150;
}
V_74 = F_91 ( V_15 , V_127 , V_128 , sizeof( V_127 -> V_131 ) ) ;
V_150:
F_26 ( & V_15 -> V_24 ) ;
V_149:
F_26 ( & V_30 ) ;
F_7 ( V_128 ) ;
return V_74 ;
}
static int F_99 ( struct V_14 * V_15 , struct V_151 * V_152 )
{
struct V_153 * V_128 ;
struct V_154 * V_130 ;
int V_10 , V_135 ;
int V_74 = 0 ;
for ( V_135 = 0 ; V_135 < V_152 -> V_155 ; ++ V_135 )
F_11 ( 0 , L_60 , V_152 -> V_156 [ V_135 ] . V_157 ,
& ( V_152 -> V_156 [ V_135 ] . V_158 ) ,
F_100 ( V_152 -> V_156 [ V_135 ] . V_159 ) ) ;
for ( V_10 = 0 ; V_10 < V_71 && ! V_74 ; ++ V_10 ) {
V_128 = F_101 ( V_10 ) ;
V_130 = NULL ;
for ( V_135 = 0 ; V_135 < V_152 -> V_155 ; ++ V_135 ) {
if ( V_152 -> V_156 [ V_135 ] . V_157 == V_10 ) {
V_130 = & ( V_152 -> V_156 [ V_135 ] ) ;
break;
}
}
if ( ! V_128 && ! V_130 )
continue;
if ( ( V_128 && ! V_130 ) || ( ! V_128 && V_130 ) )
V_74 = - V_140 ;
if ( ! V_74 &&
( ( V_130 -> V_157 != V_128 -> V_160 ) ||
( V_130 -> V_159 != V_128 -> V_161 ) ||
( V_130 -> V_158 != V_128 -> V_162 ) ) )
V_74 = - V_140 ;
if ( V_74 ) {
if ( V_130 && ! V_128 )
F_11 ( V_78 , L_61
L_62
L_63 , V_152 -> V_163 ,
V_130 -> V_157 ,
& ( V_130 -> V_158 ) ,
F_100 ( V_130 -> V_159 ) ,
V_152 -> V_164 , V_15 -> V_76 ) ;
if ( V_128 && ! V_130 )
F_11 ( V_78 , L_61
L_64
L_65 , V_152 -> V_163 ,
V_128 -> V_160 , & ( V_128 -> V_162 ) ,
F_100 ( V_128 -> V_161 ) ,
V_15 -> V_76 , V_152 -> V_164 ) ;
F_37 ( ( ! V_128 && ! V_130 ) ) ;
}
if ( V_128 )
F_102 ( V_128 ) ;
}
return V_74 ;
}
static int F_103 ( struct V_14 * V_15 , unsigned long * V_112 )
{
struct V_151 * V_152 = NULL ;
struct V_153 * V_61 ;
int V_31 = 0 , V_74 , V_165 , V_10 ;
if ( F_66 ( V_112 , V_71 , 0 ) >= V_71 )
goto V_141;
V_152 = F_96 ( sizeof( struct V_151 ) , V_9 ) ;
if ( ! V_152 ) {
V_31 = - V_145 ;
F_97 ( V_31 ) ;
goto V_141;
}
for ( V_10 = 0 , V_165 = 0 ; V_10 < V_71 ; ++ V_10 ) {
V_61 = F_101 ( V_10 ) ;
if ( ! V_61 )
continue;
V_152 -> V_156 [ V_165 ] . V_157 = V_61 -> V_160 ;
V_152 -> V_156 [ V_165 ] . V_159 = V_61 -> V_161 ;
V_152 -> V_156 [ V_165 ] . V_158 = V_61 -> V_162 ;
F_11 ( 0 , L_60 , V_61 -> V_160 ,
& ( V_61 -> V_162 ) , F_100 ( V_61 -> V_161 ) ) ;
++ V_165 ;
F_102 ( V_61 ) ;
}
V_152 -> V_164 = V_15 -> V_76 ;
V_152 -> V_155 = V_165 ;
V_152 -> V_166 = strlen ( V_15 -> V_19 ) ;
memcpy ( V_152 -> V_163 , V_15 -> V_19 , V_152 -> V_166 ) ;
V_10 = - 1 ;
while ( ( V_10 = F_66 ( V_112 , V_71 ,
V_10 + 1 ) ) < V_71 ) {
if ( V_10 == V_15 -> V_76 )
continue;
F_11 ( 0 , L_66 , V_10 ) ;
V_31 = F_71 ( V_167 , V_148 ,
V_152 , sizeof( struct V_151 ) ,
V_10 , & V_74 ) ;
if ( V_31 >= 0 )
V_31 = V_74 ;
if ( V_31 ) {
F_11 ( V_78 , L_67 , V_31 , V_10 ) ;
break;
}
}
V_141:
F_7 ( V_152 ) ;
return V_31 ;
}
static int F_104 ( struct V_57 * V_58 , T_2 V_21 ,
void * V_59 , void * * V_60 )
{
struct V_151 * V_152 ;
struct V_14 * V_15 = NULL ;
int V_168 = 0 , V_74 = - V_140 ;
V_152 = (struct V_151 * ) V_58 -> V_64 ;
F_11 ( 0 , L_68 , V_152 -> V_164 ,
V_152 -> V_163 ) ;
F_25 ( & V_30 ) ;
V_15 = F_29 ( V_152 -> V_163 , V_152 -> V_166 ) ;
if ( ! V_15 ) {
F_11 ( V_78 , L_69
L_70 , V_152 -> V_164 , V_152 -> V_163 ) ;
goto V_141;
}
F_25 ( & V_15 -> V_24 ) ;
V_168 = 1 ;
if ( V_15 -> V_55 != V_152 -> V_164 ) {
F_11 ( V_78 , L_71
L_72 , V_152 -> V_164 , V_152 -> V_163 ,
V_15 -> V_55 ) ;
goto V_141;
}
if ( V_15 -> V_79 . V_80 == 1 &&
V_15 -> V_79 . V_81 == 0 ) {
F_11 ( V_78 , L_73
L_59 , V_152 -> V_164 ,
V_152 -> V_163 , V_15 -> V_79 . V_80 ,
V_15 -> V_79 . V_81 ) ;
goto V_141;
}
V_74 = F_99 ( V_15 , V_152 ) ;
V_141:
if ( V_168 )
F_26 ( & V_15 -> V_24 ) ;
F_26 ( & V_30 ) ;
return V_74 ;
}
static int F_105 ( struct V_57 * V_58 , T_2 V_21 , void * V_59 ,
void * * V_60 )
{
struct V_169 * V_170 ;
struct V_14 * V_15 = NULL ;
V_170 = (struct V_169 * ) V_58 -> V_64 ;
F_11 ( 0 , L_74 , V_170 -> V_65 ,
V_170 -> V_28 ) ;
F_25 ( & V_30 ) ;
V_15 = F_29 ( V_170 -> V_28 , V_170 -> V_110 ) ;
if ( V_15 ) {
F_25 ( & V_15 -> V_24 ) ;
F_37 ( V_15 -> V_55 != V_170 -> V_65 ) ;
F_89 ( V_15 , V_56 ) ;
F_26 ( & V_15 -> V_24 ) ;
}
F_26 ( & V_30 ) ;
return 0 ;
}
static int F_106 ( struct V_14 * V_15 ,
unsigned int V_61 )
{
int V_74 ;
struct V_169 V_171 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_65 = V_15 -> V_76 ;
V_171 . V_110 = strlen ( V_15 -> V_19 ) ;
memcpy ( V_171 . V_28 , V_15 -> V_19 , V_171 . V_110 ) ;
V_74 = F_71 ( V_172 , V_148 ,
& V_171 , sizeof( V_171 ) , V_61 ,
NULL ) ;
if ( V_74 < 0 ) {
F_11 ( V_78 , L_75
L_76 , V_74 , V_172 , V_148 ,
V_61 ) ;
goto V_141;
}
V_141:
return V_74 ;
}
static int F_107 ( struct V_14 * V_15 ,
unsigned long * V_112 ,
unsigned int V_173 )
{
int V_74 , V_174 ;
int V_61 ;
if ( V_173 != ( F_108 ( V_71 ) *
sizeof( unsigned long ) ) ) {
F_11 ( V_78 ,
L_77 ,
V_173 , ( unsigned ) F_108 ( V_71 ) ) ;
return - V_140 ;
}
V_74 = 0 ;
V_61 = - 1 ;
while ( ( V_61 = F_66 ( V_112 , V_71 ,
V_61 + 1 ) ) < V_71 ) {
if ( V_61 == V_15 -> V_76 )
continue;
V_174 = F_106 ( V_15 , V_61 ) ;
if ( V_174 ) {
F_11 ( V_78 , L_78
L_79 , V_174 , V_61 ) ;
if ( ! V_74 )
V_74 = V_174 ;
}
}
if ( V_74 )
F_97 ( V_74 ) ;
return V_74 ;
}
static int F_109 ( struct V_14 * V_15 ,
int V_61 ,
enum V_175 * V_101 )
{
int V_74 ;
struct V_103 V_176 ;
struct V_97 V_98 ;
T_2 V_177 ;
F_11 ( 0 , L_80 , V_61 ) ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_65 = V_15 -> V_76 ;
V_176 . V_110 = strlen ( V_15 -> V_19 ) ;
memcpy ( V_176 . V_28 , V_15 -> V_19 , V_176 . V_110 ) ;
V_176 . V_118 = V_15 -> V_79 ;
V_176 . V_121 = V_15 -> V_120 ;
F_3 ( V_176 . V_112 , V_15 -> V_178 , V_71 ) ;
V_74 = F_71 ( V_179 , V_148 , & V_176 ,
sizeof( V_176 ) , V_61 , & V_177 ) ;
if ( V_74 < 0 && V_74 != - V_85 ) {
F_11 ( V_78 , L_75
L_76 , V_74 , V_179 , V_148 ,
V_61 ) ;
goto V_141;
}
F_85 ( V_177 , & V_98 ) ;
if ( V_74 == - V_85 ) {
V_74 = 0 ;
* V_101 = V_109 ;
} else {
* V_101 = V_98 . V_105 ;
switch ( V_98 . V_105 ) {
case V_106 :
case V_109 :
break;
case V_119 :
F_11 ( V_87 ,
L_81
L_82
L_83
L_84 ,
V_15 -> V_79 . V_80 ,
V_15 -> V_79 . V_81 ,
V_15 -> V_120 . V_80 ,
V_15 -> V_120 . V_81 ,
V_61 ) ;
V_74 = - V_180 ;
break;
case V_124 :
V_15 -> V_79 . V_81 = V_98 . V_122 ;
V_15 -> V_120 . V_81 = V_98 . V_123 ;
F_11 ( 0 ,
L_85
L_86 ,
V_61 ,
V_15 -> V_79 . V_80 ,
V_15 -> V_79 . V_81 ,
V_15 -> V_120 . V_80 ,
V_15 -> V_120 . V_81 ) ;
break;
default:
V_74 = - V_140 ;
F_11 ( V_78 , L_87 ,
V_98 . V_105 , V_61 ) ;
* V_101 = V_106 ;
break;
}
}
F_11 ( 0 , L_88 , V_74 , V_61 ,
* V_101 ) ;
V_141:
return V_74 ;
}
static int F_110 ( struct V_14 * V_15 ,
unsigned int V_61 )
{
int V_74 ;
int V_31 ;
struct V_125 V_181 ;
F_11 ( 0 , L_89 , V_61 ) ;
memset ( & V_181 , 0 , sizeof( V_181 ) ) ;
V_181 . V_65 = V_15 -> V_76 ;
V_181 . V_110 = strlen ( V_15 -> V_19 ) ;
memcpy ( V_181 . V_28 , V_15 -> V_19 , V_181 . V_110 ) ;
V_74 = F_71 ( V_182 , V_148 ,
& V_181 , sizeof( V_181 ) , V_61 ,
& V_31 ) ;
if ( V_74 < 0 )
F_11 ( V_78 , L_75
L_76 , V_74 , V_182 , V_148 ,
V_61 ) ;
else
V_74 = V_31 ;
return V_74 ;
}
static void F_111 ( struct V_14 * V_15 ,
unsigned long * V_112 )
{
int V_74 , V_61 , V_183 ;
V_74 = 0 ;
V_61 = - 1 ;
while ( ( V_61 = F_66 ( V_112 , V_71 ,
V_61 + 1 ) ) < V_71 ) {
if ( V_61 == V_15 -> V_76 )
continue;
do {
V_74 = F_110 ( V_15 , V_61 ) ;
F_25 ( & V_15 -> V_24 ) ;
V_183 = F_4 ( V_61 , V_15 -> V_178 ) ;
F_26 ( & V_15 -> V_24 ) ;
if ( V_74 ) {
F_11 ( V_78 , L_90
L_91 , V_74 , V_61 ) ;
if ( V_183 )
F_74 ( V_88 ) ;
}
} while ( V_74 && V_183 );
}
}
static int F_112 ( struct V_14 * V_15 ,
struct V_184 * V_185 ,
enum V_175 V_101 )
{
int V_31 ;
if ( V_101 == V_106 ) {
F_11 ( 0 , L_92 ) ;
return 1 ;
}
F_25 ( & V_15 -> V_24 ) ;
V_31 = memcmp ( V_185 -> V_186 , V_15 -> V_178 ,
sizeof( V_15 -> V_178 ) ) ;
F_26 ( & V_15 -> V_24 ) ;
if ( V_31 )
F_11 ( 0 , L_93 ) ;
return V_31 ;
}
static int F_113 ( struct V_14 * V_15 )
{
int V_74 = 0 , V_174 , V_61 ;
struct V_184 * V_185 ;
enum V_175 V_101 = V_106 ;
F_11 ( 0 , L_94 , V_15 ) ;
V_185 = F_96 ( sizeof( * V_185 ) , V_9 ) ;
if ( ! V_185 ) {
V_74 = - V_145 ;
F_97 ( V_74 ) ;
goto V_141;
}
F_114 ( V_15 -> V_178 , sizeof( V_15 -> V_178 ) ) ;
F_25 ( & V_15 -> V_24 ) ;
memcpy ( V_185 -> V_186 , V_15 -> V_178 , sizeof( V_185 -> V_186 ) ) ;
F_89 ( V_15 , V_15 -> V_76 ) ;
F_26 ( & V_15 -> V_24 ) ;
V_61 = - 1 ;
while ( ( V_61 = F_66 ( V_185 -> V_186 , V_71 ,
V_61 + 1 ) ) < V_71 ) {
if ( V_61 == V_15 -> V_76 )
continue;
V_74 = F_109 ( V_15 , V_61 , & V_101 ) ;
if ( V_74 < 0 ) {
F_97 ( V_74 ) ;
goto V_141;
}
if ( V_101 == V_124 )
F_61 ( V_61 , V_185 -> V_187 ) ;
if ( F_112 ( V_15 , V_185 , V_101 ) ) {
V_74 = - V_54 ;
goto V_141;
}
}
F_11 ( 0 , L_95 ) ;
F_25 ( & V_15 -> V_24 ) ;
memcpy ( V_15 -> V_70 , V_185 -> V_187 ,
sizeof( V_185 -> V_187 ) ) ;
F_61 ( V_15 -> V_76 , V_15 -> V_70 ) ;
F_26 ( & V_15 -> V_24 ) ;
if ( V_15 -> V_79 . V_80 > 1 ||
V_15 -> V_79 . V_81 > 0 ) {
V_74 = F_103 ( V_15 , V_185 -> V_187 ) ;
if ( V_74 ) {
F_97 ( V_74 ) ;
goto V_141;
}
V_74 = F_95 ( V_15 , V_185 -> V_187 ) ;
if ( V_74 ) {
F_97 ( V_74 ) ;
goto V_141;
}
}
F_111 ( V_15 , V_185 -> V_187 ) ;
F_25 ( & V_30 ) ;
V_15 -> V_32 = V_33 ;
V_15 -> V_38 ++ ;
F_26 ( & V_30 ) ;
V_141:
F_25 ( & V_15 -> V_24 ) ;
F_89 ( V_15 , V_56 ) ;
if ( ! V_74 ) {
F_65 ( V_72 L_96 , V_15 -> V_19 ) ;
F_64 ( V_15 ) ;
}
F_26 ( & V_15 -> V_24 ) ;
if ( V_185 ) {
if ( V_74 < 0 ) {
V_174 = F_107 ( V_15 ,
V_185 -> V_187 ,
sizeof( V_185 -> V_187 ) ) ;
if ( V_174 < 0 )
F_97 ( V_174 ) ;
}
F_7 ( V_185 ) ;
}
F_11 ( 0 , L_97 , V_74 ) ;
return V_74 ;
}
static void F_50 ( struct V_14 * V_15 )
{
F_115 ( V_15 -> V_19 , & V_15 -> V_188 ) ;
F_115 ( V_15 -> V_19 , & V_15 -> V_189 ) ;
F_116 ( & V_15 -> V_190 ) ;
}
static int F_117 ( struct V_14 * V_15 )
{
int V_74 ;
F_11 ( 0 , L_98 ) ;
F_118 ( & V_15 -> V_189 , V_191 ,
V_192 , V_15 , V_193 ) ;
F_118 ( & V_15 -> V_188 , V_194 ,
V_195 , V_15 , V_196 ) ;
V_74 = F_119 ( V_15 -> V_19 , & V_15 -> V_189 ) ;
if ( V_74 )
goto V_141;
V_74 = F_119 ( V_15 -> V_19 , & V_15 -> V_188 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_197 , V_15 -> V_77 ,
sizeof( struct V_198 ) ,
V_199 ,
V_15 , NULL , & V_15 -> V_190 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_200 , V_15 -> V_77 ,
sizeof( struct V_201 ) ,
V_202 ,
V_15 , V_203 ,
& V_15 -> V_190 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_204 , V_15 -> V_77 ,
sizeof( struct V_205 ) ,
V_206 ,
V_15 , NULL , & V_15 -> V_190 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_207 , V_15 -> V_77 ,
V_208 ,
V_209 ,
V_15 , NULL , & V_15 -> V_190 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_210 , V_15 -> V_77 ,
V_211 ,
V_212 ,
V_15 , NULL , & V_15 -> V_190 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_213 , V_15 -> V_77 ,
V_214 ,
V_215 ,
V_15 , NULL , & V_15 -> V_190 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_84 , V_15 -> V_77 ,
sizeof( struct V_62 ) ,
F_67 ,
V_15 , NULL , & V_15 -> V_190 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_216 , V_15 -> V_77 ,
sizeof( struct V_217 ) ,
V_218 ,
V_15 , NULL , & V_15 -> V_190 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_219 , V_15 -> V_77 ,
sizeof( struct V_220 ) ,
V_221 ,
V_15 , NULL , & V_15 -> V_190 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_222 , V_15 -> V_77 ,
V_223 ,
V_224 ,
V_15 , NULL , & V_15 -> V_190 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_225 , V_15 -> V_77 ,
sizeof( struct V_226 ) ,
V_227 ,
V_15 , NULL , & V_15 -> V_190 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_228 , V_15 -> V_77 ,
sizeof( struct V_229 ) ,
V_230 ,
V_15 , NULL , & V_15 -> V_190 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_231 , V_15 -> V_77 ,
sizeof( struct V_232 ) ,
V_233 ,
V_15 , NULL , & V_15 -> V_190 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_234 , V_15 -> V_77 ,
sizeof( struct V_235 ) ,
V_236 ,
V_15 , NULL , & V_15 -> V_190 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_237 , V_15 -> V_77 ,
sizeof( struct V_238 ) ,
V_239 ,
V_15 , NULL , & V_15 -> V_190 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_82 , V_15 -> V_77 ,
sizeof( struct V_62 ) ,
F_60 ,
V_15 , NULL , & V_15 -> V_190 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_240 , V_15 -> V_77 ,
sizeof( struct V_241 ) ,
V_242 ,
V_15 , NULL , & V_15 -> V_190 ) ;
V_141:
if ( V_74 )
F_50 ( V_15 ) ;
return V_74 ;
}
static int F_121 ( struct V_14 * V_15 )
{
int V_74 ;
unsigned int V_243 ;
unsigned int V_244 = 0 ;
char V_245 [ V_246 ] ;
F_37 ( ! V_15 ) ;
F_11 ( 0 , L_99 , V_15 -> V_19 ) ;
V_74 = F_117 ( V_15 ) ;
if ( V_74 ) {
F_97 ( V_74 ) ;
goto V_141;
}
V_74 = F_122 ( V_15 ) ;
if ( V_74 < 0 ) {
F_97 ( V_74 ) ;
goto V_141;
}
V_74 = F_123 ( V_15 ) ;
if ( V_74 < 0 ) {
F_97 ( V_74 ) ;
goto V_141;
}
V_74 = F_124 ( V_15 ) ;
if ( V_74 < 0 ) {
F_97 ( V_74 ) ;
goto V_141;
}
snprintf ( V_245 , V_246 , L_100 , V_15 -> V_19 ) ;
V_15 -> V_43 = F_125 ( V_245 , V_247 , 0 ) ;
if ( ! V_15 -> V_43 ) {
V_74 = - V_145 ;
F_97 ( V_74 ) ;
goto V_141;
}
do {
V_74 = F_113 ( V_15 ) ;
#define F_126 90000
if ( V_74 == - V_54 ) {
if ( F_127 ( V_248 ) ) {
V_74 = - V_249 ;
goto V_141;
}
if ( V_244 > F_126 ) {
V_74 = - V_249 ;
F_11 ( V_87 , L_101
L_102 , V_15 -> V_19 ,
V_244 ) ;
goto V_141;
}
V_243 = ( unsigned int ) ( V_250 & 0x3 ) ;
V_243 *= V_88 ;
V_244 += V_243 ;
F_11 ( 0 , L_103 , V_243 ) ;
F_74 ( V_243 ) ;
}
} while ( V_74 == - V_54 );
if ( V_74 < 0 ) {
F_97 ( V_74 ) ;
goto V_141;
}
V_74 = 0 ;
V_141:
F_39 ( & V_40 ) ;
if ( V_74 ) {
F_50 ( V_15 ) ;
F_51 ( V_15 ) ;
F_52 ( V_15 ) ;
F_53 ( V_15 ) ;
F_46 ( V_15 ) ;
}
return V_74 ;
}
static struct V_14 * F_128 ( const char * V_28 ,
T_2 V_77 )
{
int V_10 ;
int V_31 ;
struct V_14 * V_15 = NULL ;
V_15 = F_96 ( sizeof( * V_15 ) , V_9 ) ;
if ( ! V_15 ) {
V_31 = - V_145 ;
F_97 ( V_31 ) ;
goto V_89;
}
V_15 -> V_19 = F_129 ( V_28 , V_9 ) ;
if ( V_15 -> V_19 == NULL ) {
V_31 = - V_145 ;
F_97 ( V_31 ) ;
goto V_89;
}
V_15 -> V_34 = (struct V_22 * * ) F_8 ( V_12 ) ;
if ( ! V_15 -> V_34 ) {
V_31 = - V_145 ;
F_97 ( V_31 ) ;
goto V_89;
}
for ( V_10 = 0 ; V_10 < V_49 ; V_10 ++ )
F_130 ( F_18 ( V_15 , V_10 ) ) ;
V_15 -> V_35 = (struct V_22 * * )
F_8 ( V_12 ) ;
if ( ! V_15 -> V_35 ) {
V_31 = - V_145 ;
F_97 ( V_31 ) ;
goto V_89;
}
for ( V_10 = 0 ; V_10 < V_49 ; V_10 ++ )
F_130 ( F_131 ( V_15 , V_10 ) ) ;
V_15 -> V_77 = V_77 ;
V_15 -> V_76 = F_132 () ;
V_31 = F_133 ( V_15 ) ;
if ( V_31 < 0 )
goto V_89;
F_134 ( & V_15 -> V_24 ) ;
F_134 ( & V_15 -> V_251 ) ;
F_134 ( & V_15 -> V_252 ) ;
F_134 ( & V_15 -> V_253 ) ;
F_135 ( & V_15 -> V_39 ) ;
F_135 ( & V_15 -> V_254 ) ;
F_135 ( & V_15 -> V_115 . V_255 ) ;
F_135 ( & V_15 -> V_115 . V_256 ) ;
F_135 ( & V_15 -> V_257 ) ;
F_135 ( & V_15 -> V_190 ) ;
F_135 ( & V_15 -> V_90 ) ;
V_15 -> V_115 . V_26 = 0 ;
F_135 ( & V_15 -> V_258 ) ;
F_135 ( & V_15 -> V_259 ) ;
F_11 ( 0 , L_104 ,
V_15 -> V_117 , & ( V_15 -> V_117 [ 0 ] ) ) ;
memset ( V_15 -> V_117 , 0 , sizeof( V_15 -> V_117 ) ) ;
memset ( V_15 -> V_178 , 0 , sizeof( V_15 -> V_178 ) ) ;
memset ( V_15 -> V_70 , 0 , sizeof( V_15 -> V_70 ) ) ;
V_15 -> V_260 = NULL ;
V_15 -> V_261 = NULL ;
V_15 -> V_43 = NULL ;
F_136 ( & V_15 -> V_53 ) ;
F_136 ( & V_15 -> V_262 ) ;
F_136 ( & V_15 -> V_115 . V_263 ) ;
F_136 ( & V_15 -> V_264 ) ;
F_136 ( & V_15 -> V_265 ) ;
F_135 ( & V_15 -> V_266 ) ;
V_15 -> V_55 = V_56 ;
F_136 ( & V_15 -> V_68 ) ;
V_15 -> V_115 . V_267 = V_268 ;
V_15 -> V_115 . V_269 = V_268 ;
F_137 ( & V_15 -> V_270 , 0 ) ;
F_137 ( & V_15 -> V_271 , 0 ) ;
for ( V_10 = 0 ; V_10 < V_272 ; ++ V_10 ) {
F_137 ( & V_15 -> V_273 [ V_10 ] , 0 ) ;
F_137 ( & V_15 -> V_274 [ V_10 ] , 0 ) ;
}
F_134 ( & V_15 -> V_275 ) ;
F_135 ( & V_15 -> V_276 ) ;
F_138 ( & V_15 -> V_277 , V_278 ) ;
F_139 ( & V_15 -> V_37 ) ;
V_15 -> V_32 = V_114 ;
F_135 ( & V_15 -> V_279 ) ;
F_11 ( 0 , L_105 ,
F_140 ( & V_15 -> V_37 ) ) ;
V_89:
if ( V_31 < 0 && V_15 ) {
if ( V_15 -> V_35 )
F_5 ( ( void * * ) V_15 -> V_35 ,
V_12 ) ;
if ( V_15 -> V_34 )
F_5 ( ( void * * ) V_15 -> V_34 ,
V_12 ) ;
F_7 ( V_15 -> V_19 ) ;
F_7 ( V_15 ) ;
V_15 = NULL ;
}
return V_15 ;
}
static int F_82 ( struct V_92 * V_280 ,
struct V_92 * V_94 )
{
if ( V_280 -> V_80 != V_94 -> V_80 )
return 1 ;
if ( V_280 -> V_81 > V_94 -> V_81 )
return 1 ;
if ( V_280 -> V_81 < V_94 -> V_81 )
V_94 -> V_81 = V_280 -> V_81 ;
return 0 ;
}
struct V_14 * F_141 ( const char * V_28 ,
T_2 V_77 ,
struct V_92 * V_121 )
{
int V_31 ;
struct V_14 * V_15 = NULL ;
struct V_14 * V_281 = NULL ;
if ( strlen ( V_28 ) >= V_246 ) {
V_31 = - V_282 ;
F_11 ( V_78 , L_106 ) ;
goto V_89;
}
F_11 ( 0 , L_107 , V_28 ) ;
V_283:
V_15 = NULL ;
if ( F_127 ( V_248 ) ) {
V_31 = - V_249 ;
F_97 ( V_31 ) ;
goto V_89;
}
F_25 ( & V_30 ) ;
V_15 = F_31 ( V_28 ) ;
if ( V_15 ) {
if ( V_15 -> V_32 != V_33 ) {
F_26 ( & V_30 ) ;
F_11 ( 0 , L_108 ) ;
F_142 ( V_40 ,
F_32 (
V_28 ) ) ;
goto V_283;
}
if ( F_82 ( & V_15 -> V_120 , V_121 ) ) {
F_26 ( & V_30 ) ;
F_11 ( V_78 ,
L_109
L_110
L_111 , V_28 ) ;
V_31 = - V_180 ;
goto V_89;
}
F_42 ( V_15 ) ;
V_15 -> V_38 ++ ;
F_26 ( & V_30 ) ;
V_31 = 0 ;
goto V_89;
}
if ( ! V_281 ) {
F_26 ( & V_30 ) ;
V_281 = F_128 ( V_28 , V_77 ) ;
if ( V_281 )
goto V_283;
V_31 = - V_145 ;
F_97 ( V_31 ) ;
goto V_89;
}
V_15 = V_281 ;
V_281 = NULL ;
F_143 ( & V_15 -> V_39 , & V_284 ) ;
F_26 ( & V_30 ) ;
V_15 -> V_79 = V_285 ;
V_15 -> V_120 = * V_121 ;
V_31 = F_121 ( V_15 ) ;
if ( V_31 ) {
F_97 ( V_31 ) ;
F_40 ( V_15 ) ;
goto V_89;
}
* V_121 = V_15 -> V_120 ;
V_31 = 0 ;
V_89:
if ( V_281 )
F_33 ( V_281 ) ;
if ( V_31 < 0 )
V_15 = F_144 ( V_31 ) ;
return V_15 ;
}
static void F_145 ( void )
{
F_116 ( & V_286 ) ;
}
static int F_146 ( void )
{
int V_74 = 0 ;
V_74 = F_120 ( V_179 , V_148 ,
sizeof( struct V_103 ) ,
F_87 ,
NULL , NULL , & V_286 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_182 , V_148 ,
sizeof( struct V_125 ) ,
F_90 ,
NULL , NULL , & V_286 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_172 , V_148 ,
sizeof( struct V_169 ) ,
F_105 ,
NULL , NULL , & V_286 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_147 , V_148 ,
sizeof( struct V_126 ) ,
F_98 ,
NULL , NULL , & V_286 ) ;
if ( V_74 )
goto V_141;
V_74 = F_120 ( V_167 , V_148 ,
sizeof( struct V_151 ) ,
F_104 ,
NULL , NULL , & V_286 ) ;
V_141:
if ( V_74 < 0 )
F_145 () ;
return V_74 ;
}
void F_147 ( struct V_14 * V_15 ,
int V_76 )
{
struct V_287 * V_288 ;
F_148 ( & V_289 ) ;
F_30 (cb, &dlm->dlm_eviction_callbacks, ec_item) {
V_288 -> V_290 ( V_76 , V_288 -> V_291 ) ;
}
F_149 ( & V_289 ) ;
}
void F_150 ( struct V_287 * V_288 ,
T_3 * V_292 ,
void * V_59 )
{
F_135 ( & V_288 -> V_293 ) ;
V_288 -> V_290 = V_292 ;
V_288 -> V_291 = V_59 ;
}
void F_151 ( struct V_14 * V_15 ,
struct V_287 * V_288 )
{
F_152 ( & V_289 ) ;
F_143 ( & V_288 -> V_293 , & V_15 -> V_279 ) ;
F_153 ( & V_289 ) ;
}
void F_154 ( struct V_287 * V_288 )
{
F_152 ( & V_289 ) ;
F_38 ( & V_288 -> V_293 ) ;
F_153 ( & V_289 ) ;
}
static int T_4 F_155 ( void )
{
int V_74 ;
V_74 = F_156 () ;
if ( V_74 ) {
F_11 ( V_78 , L_112 ) ;
goto error;
}
V_74 = F_157 () ;
if ( V_74 ) {
F_11 ( V_78 , L_113
L_114 ) ;
goto error;
}
V_74 = F_158 () ;
if ( V_74 ) {
F_11 ( V_78 , L_115 ) ;
goto error;
}
V_74 = F_146 () ;
if ( V_74 ) {
F_11 ( V_78 , L_116 ) ;
goto error;
}
V_74 = F_159 () ;
if ( V_74 )
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
