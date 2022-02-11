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
struct V_28 * V_29 ;
F_11 ( 0 , L_4 , V_21 , V_19 ) ;
F_17 ( & V_15 -> V_26 ) ;
V_23 = F_18 ( V_15 , V_27 ) ;
F_22 (list, bucket) {
struct V_16 * V_17 = F_23 ( V_29 ,
struct V_16 , V_18 ) ;
if ( V_17 -> V_20 . V_19 [ 0 ] != V_19 [ 0 ] )
continue;
if ( F_24 ( V_17 -> V_20 . V_21 != V_21 ) )
continue;
if ( memcmp ( V_17 -> V_20 . V_19 + 1 , V_19 + 1 , V_21 - 1 ) )
continue;
F_19 ( V_17 ) ;
return V_17 ;
}
return NULL ;
}
struct V_16 * F_25 ( struct V_14 * V_15 ,
const char * V_19 ,
unsigned int V_21 ,
unsigned int V_27 )
{
struct V_16 * V_17 = NULL ;
F_11 ( 0 , L_4 , V_21 , V_19 ) ;
F_17 ( & V_15 -> V_26 ) ;
V_17 = F_21 ( V_15 , V_19 , V_21 , V_27 ) ;
if ( V_17 ) {
F_26 ( & V_17 -> V_26 ) ;
if ( V_17 -> V_30 & V_31 ) {
F_27 ( & V_17 -> V_26 ) ;
F_15 ( V_17 ) ;
return NULL ;
}
F_27 ( & V_17 -> V_26 ) ;
}
return V_17 ;
}
struct V_16 * F_28 ( struct V_14 * V_15 ,
const char * V_19 ,
unsigned int V_21 )
{
struct V_16 * V_17 ;
unsigned int V_27 = F_29 ( V_19 , V_21 ) ;
F_26 ( & V_15 -> V_26 ) ;
V_17 = F_25 ( V_15 , V_19 , V_21 , V_27 ) ;
F_27 ( & V_15 -> V_26 ) ;
return V_17 ;
}
static struct V_14 * F_30 ( const char * V_32 , int V_21 )
{
struct V_14 * V_33 = NULL ;
struct V_34 * V_35 ;
F_17 ( & V_36 ) ;
F_31 (iter, &dlm_domains) {
V_33 = F_32 ( V_35 , struct V_14 , V_29 ) ;
if ( strlen ( V_33 -> V_19 ) == V_21 &&
memcmp ( V_33 -> V_19 , V_32 , V_21 ) == 0 )
break;
V_33 = NULL ;
}
return V_33 ;
}
static struct V_14 * F_33 ( const char * V_32 )
{
F_17 ( & V_36 ) ;
return F_30 ( V_32 , strlen ( V_32 ) ) ;
}
static int F_34 ( const char * V_32 )
{
int V_37 = 0 ;
struct V_14 * V_33 = NULL ;
F_26 ( & V_36 ) ;
V_33 = F_33 ( V_32 ) ;
if ( ! V_33 )
V_37 = 1 ;
else if ( V_33 -> V_38 == V_39 )
V_37 = 1 ;
F_27 ( & V_36 ) ;
return V_37 ;
}
static void F_35 ( struct V_14 * V_15 )
{
F_36 ( V_15 ) ;
if ( V_15 -> V_40 )
F_5 ( ( void * * ) V_15 -> V_40 , V_12 ) ;
if ( V_15 -> V_41 )
F_5 ( ( void * * ) V_15 -> V_41 , V_12 ) ;
if ( V_15 -> V_19 )
F_7 ( V_15 -> V_19 ) ;
F_7 ( V_15 ) ;
}
static void F_37 ( struct V_42 * V_42 )
{
struct V_14 * V_15 ;
V_15 = F_38 ( V_42 , struct V_14 , V_43 ) ;
F_39 ( V_15 -> V_44 ) ;
F_39 ( V_15 -> V_38 == V_39 ) ;
F_40 ( & V_15 -> V_29 ) ;
F_27 ( & V_36 ) ;
F_11 ( 0 , L_5 , V_15 -> V_19 ) ;
F_41 ( & V_45 ) ;
F_35 ( V_15 ) ;
F_26 ( & V_36 ) ;
}
void F_42 ( struct V_14 * V_15 )
{
F_26 ( & V_36 ) ;
F_43 ( & V_15 -> V_43 , F_37 ) ;
F_27 ( & V_36 ) ;
}
static void F_44 ( struct V_14 * V_15 )
{
F_45 ( & V_15 -> V_43 ) ;
}
struct V_14 * F_46 ( struct V_14 * V_15 )
{
struct V_34 * V_35 ;
struct V_14 * V_46 = NULL ;
F_26 ( & V_36 ) ;
F_31 (iter, &dlm_domains) {
V_46 = F_32 ( V_35 , struct V_14 , V_29 ) ;
if ( V_46 == V_15 ) {
F_44 ( V_46 ) ;
break;
}
V_46 = NULL ;
}
F_27 ( & V_36 ) ;
return V_46 ;
}
int F_47 ( struct V_14 * V_15 )
{
int V_37 ;
F_26 ( & V_36 ) ;
V_37 = ( V_15 -> V_38 == V_39 ) ||
( V_15 -> V_38 == V_47 ) ;
F_27 ( & V_36 ) ;
return V_37 ;
}
static void F_48 ( struct V_14 * V_15 )
{
if ( V_15 -> V_48 ) {
F_49 ( V_15 -> V_48 ) ;
F_50 ( V_15 -> V_48 ) ;
V_15 -> V_48 = NULL ;
}
}
static void F_51 ( struct V_14 * V_15 )
{
F_52 ( V_15 ) ;
F_53 ( V_15 ) ;
F_54 ( V_15 ) ;
F_55 ( V_15 ) ;
F_48 ( V_15 ) ;
F_26 ( & V_36 ) ;
F_40 ( & V_15 -> V_29 ) ;
F_27 ( & V_36 ) ;
F_41 ( & V_45 ) ;
}
static int F_56 ( struct V_14 * V_15 )
{
int V_10 , V_49 , V_50 , V_37 = 0 ;
struct V_16 * V_17 ;
struct V_28 * V_35 ;
struct V_22 * V_23 ;
int V_51 ;
F_11 ( 0 , L_6 , V_15 -> V_19 ) ;
V_49 = 0 ;
F_26 ( & V_15 -> V_26 ) ;
for ( V_10 = 0 ; V_10 < V_52 ; V_10 ++ ) {
V_53:
V_50 = 0 ;
V_23 = F_18 ( V_15 , V_10 ) ;
V_35 = V_23 -> V_54 ;
while ( V_35 ) {
V_50 ++ ;
V_17 = F_23 ( V_35 , struct V_16 ,
V_18 ) ;
F_19 ( V_17 ) ;
V_51 = F_57 ( V_15 , V_17 ) ;
F_26 ( & V_17 -> V_26 ) ;
if ( V_51 )
F_58 ( V_15 , V_17 ) ;
else
V_35 = V_17 -> V_18 . V_55 ;
F_27 ( & V_17 -> V_26 ) ;
F_15 ( V_17 ) ;
if ( V_51 ) {
F_59 ( & V_15 -> V_26 ) ;
goto V_53;
}
}
F_59 ( & V_15 -> V_26 ) ;
V_49 += V_50 ;
}
F_27 ( & V_15 -> V_26 ) ;
F_41 ( & V_15 -> V_56 ) ;
if ( V_49 ) {
F_11 ( 0 , L_7 ,
V_15 -> V_19 , V_49 ) ;
V_37 = - V_57 ;
}
F_11 ( 0 , L_8 , V_15 -> V_19 ) ;
return V_37 ;
}
static int F_60 ( struct V_14 * V_15 )
{
int V_37 ;
F_26 ( & V_15 -> V_26 ) ;
V_37 = V_15 -> V_58 == V_59 ;
F_27 ( & V_15 -> V_26 ) ;
return V_37 ;
}
static int F_61 ( struct V_60 * V_61 , T_2 V_21 ,
void * V_62 , void * * V_63 )
{
struct V_14 * V_15 = V_62 ;
unsigned int V_64 ;
struct V_65 * V_66 = (struct V_65 * ) V_61 -> V_67 ;
if ( ! F_46 ( V_15 ) )
return 0 ;
V_64 = V_66 -> V_68 ;
F_11 ( 0 , L_9 , V_15 -> V_19 , V_64 ) ;
F_26 ( & V_15 -> V_26 ) ;
F_62 ( V_64 , V_15 -> V_69 ) ;
F_27 ( & V_15 -> V_26 ) ;
F_42 ( V_15 ) ;
return 0 ;
}
static void F_63 ( struct V_14 * V_15 )
{
V_70:
F_26 ( & V_36 ) ;
F_26 ( & V_15 -> V_26 ) ;
if ( V_15 -> V_58 != V_59 ) {
F_11 ( 0 , L_10 ,
V_15 -> V_58 ) ;
F_27 ( & V_15 -> V_26 ) ;
F_27 ( & V_36 ) ;
F_64 ( V_15 -> V_71 , F_60 ( V_15 ) ) ;
goto V_70;
}
V_15 -> V_38 = V_72 ;
F_27 ( & V_15 -> V_26 ) ;
F_27 ( & V_36 ) ;
}
static void F_65 ( struct V_14 * V_15 )
{
int V_64 = - 1 , V_49 = 0 ;
F_17 ( & V_15 -> V_26 ) ;
F_66 ( L_11 ) ;
while ( ( V_64 = F_67 ( V_15 -> V_73 , V_74 ,
V_64 + 1 ) ) < V_74 ) {
F_66 ( L_12 , V_64 ) ;
++ V_49 ;
}
F_66 ( L_13 , V_49 ) ;
}
static int F_68 ( struct V_60 * V_61 , T_2 V_21 , void * V_62 ,
void * * V_63 )
{
struct V_14 * V_15 = V_62 ;
unsigned int V_64 ;
struct V_65 * V_66 = (struct V_65 * ) V_61 -> V_67 ;
F_11 ( 0 , L_14 , V_61 , V_21 , V_62 ) ;
if ( ! F_46 ( V_15 ) )
return 0 ;
V_64 = V_66 -> V_68 ;
F_26 ( & V_15 -> V_26 ) ;
F_69 ( V_64 , V_15 -> V_73 ) ;
F_69 ( V_64 , V_15 -> V_69 ) ;
F_66 ( V_75 L_15 , V_64 , V_15 -> V_19 ) ;
F_65 ( V_15 ) ;
F_70 ( V_15 , V_64 , 0 ) ;
F_27 ( & V_15 -> V_26 ) ;
F_42 ( V_15 ) ;
return 0 ;
}
static int F_71 ( struct V_14 * V_15 , T_2 V_76 ,
unsigned int V_64 )
{
int V_77 ;
struct V_65 V_78 ;
F_11 ( 0 , L_16 , V_15 -> V_19 ,
V_76 , V_64 ) ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . V_68 = V_15 -> V_79 ;
V_77 = F_72 ( V_76 , V_15 -> V_80 , & V_78 ,
sizeof( V_78 ) , V_64 , NULL ) ;
if ( V_77 < 0 )
F_11 ( V_81 , L_17
L_18 , V_77 , V_76 , V_64 ,
V_15 -> V_19 ) ;
return V_77 ;
}
static void F_73 ( struct V_14 * V_15 )
{
int V_64 = - 1 ;
if ( V_15 -> V_82 . V_83 == 1 &&
V_15 -> V_82 . V_84 < 2 )
return;
F_26 ( & V_15 -> V_26 ) ;
while ( 1 ) {
V_64 = F_67 ( V_15 -> V_73 , V_74 , V_64 + 1 ) ;
if ( V_64 >= V_74 )
break;
if ( V_64 == V_15 -> V_79 )
continue;
F_27 ( & V_15 -> V_26 ) ;
F_71 ( V_15 , V_85 , V_64 ) ;
F_26 ( & V_15 -> V_26 ) ;
}
F_27 ( & V_15 -> V_26 ) ;
}
static void F_74 ( struct V_14 * V_15 )
{
int V_64 , V_86 , V_77 ;
F_26 ( & V_15 -> V_26 ) ;
F_69 ( V_15 -> V_79 , V_15 -> V_73 ) ;
while ( ( V_64 = F_67 ( V_15 -> V_73 , V_74 ,
0 ) ) < V_74 ) {
F_27 ( & V_15 -> V_26 ) ;
V_86 = 1 ;
V_77 = F_71 ( V_15 , V_87 ,
V_64 ) ;
if ( V_77 < 0 &&
V_77 != - V_88 &&
V_77 != - V_89 ) {
F_11 ( V_90 , L_19
L_20 , V_77 , V_64 ) ;
F_75 ( V_91 ) ;
V_86 = 0 ;
}
F_26 ( & V_15 -> V_26 ) ;
if ( V_86 )
F_69 ( V_64 , V_15 -> V_73 ) ;
}
F_27 ( & V_15 -> V_26 ) ;
}
int F_76 ( struct V_14 * V_15 )
{
int V_37 = 0 ;
F_26 ( & V_36 ) ;
if ( V_15 -> V_38 == V_39 )
V_37 = 1 ;
F_27 ( & V_36 ) ;
return V_37 ;
}
int F_77 ( struct V_14 * V_15 )
{
int V_37 = 0 ;
F_26 ( & V_36 ) ;
if ( V_15 -> V_38 == V_47 )
V_37 = 1 ;
F_27 ( & V_36 ) ;
return V_37 ;
}
void F_78 ( struct V_14 * V_15 )
{
int V_92 = 0 ;
struct V_16 * V_17 ;
F_26 ( & V_36 ) ;
F_39 ( V_15 -> V_38 != V_39 ) ;
F_39 ( ! V_15 -> V_44 ) ;
V_15 -> V_44 -- ;
if ( ! V_15 -> V_44 ) {
V_15 -> V_38 = V_47 ;
V_92 = 1 ;
}
F_27 ( & V_36 ) ;
if ( V_92 ) {
F_11 ( 0 , L_21 , V_15 -> V_19 ) ;
F_73 ( V_15 ) ;
F_79 ( V_15 , NULL ) ;
while ( F_56 ( V_15 ) ) {
F_75 ( 500 ) ;
F_11 ( 0 , L_22 , V_15 -> V_19 ) ;
}
if ( ! F_80 ( & V_15 -> V_93 ) ) {
F_11 ( V_81 , L_23
L_24 ) ;
F_81 (res, &dlm->tracking_list, tracking)
F_82 ( V_17 ) ;
}
F_63 ( V_15 ) ;
F_74 ( V_15 ) ;
F_66 ( V_75 L_25 , V_15 -> V_19 ) ;
F_83 ( V_15 ) ;
F_51 ( V_15 ) ;
}
F_42 ( V_15 ) ;
}
static int F_84 ( char * V_94 , int V_64 ,
struct V_95 * V_96 ,
struct V_95 * V_97 )
{
int V_98 ;
struct V_95 V_99 = * V_97 ;
if ( ! F_85 ( V_96 , & V_99 ) ) {
F_11 ( 0 ,
L_26
L_27 ,
V_64 , V_94 ,
V_97 -> V_83 ,
V_97 -> V_84 ,
V_99 . V_83 , V_99 . V_84 ) ;
V_97 -> V_84 = V_99 . V_84 ;
V_98 = 0 ;
} else {
F_11 ( V_90 ,
L_28
L_29 ,
V_64 , V_94 ,
V_97 -> V_83 ,
V_97 -> V_84 ,
V_96 -> V_83 ,
V_96 -> V_84 ) ;
V_98 = 1 ;
}
return V_98 ;
}
static void F_86 ( struct V_100 * V_101 ,
T_2 * V_102 )
{
union V_103 V_104 ;
V_104 . V_101 = * V_101 ;
* V_102 = F_87 ( V_104 . V_105 ) ;
}
static void F_88 ( T_2 V_102 ,
struct V_100 * V_101 )
{
union V_103 V_104 ;
V_104 . V_105 = F_87 ( V_102 ) ;
* V_101 = V_104 . V_101 ;
}
static int F_89 ( struct V_60 * V_61 , T_2 V_21 , void * V_62 ,
void * * V_63 )
{
struct V_106 * V_107 ;
struct V_100 V_101 = {
. V_108 = V_109 ,
} ;
struct V_14 * V_15 = NULL ;
T_2 V_104 ;
T_1 V_110 ;
V_107 = (struct V_106 * ) V_61 -> V_67 ;
F_11 ( 0 , L_30 , V_107 -> V_68 ,
V_107 -> V_32 ) ;
if ( ! F_90 ( V_107 -> V_68 ) ) {
F_11 ( 0 , L_31 ,
V_107 -> V_68 ) ;
V_101 . V_108 = V_109 ;
goto V_111;
}
V_101 . V_108 = V_112 ;
F_26 ( & V_36 ) ;
V_15 = F_30 ( V_107 -> V_32 , V_107 -> V_113 ) ;
if ( ! V_15 )
goto V_114;
V_110 = 0 ;
while ( V_110 < V_74 ) {
if ( F_4 ( V_110 , V_15 -> V_73 ) ) {
if ( ! F_2 ( V_110 , V_107 -> V_115 ) ) {
F_11 ( 0 , L_32
L_33 ,
V_107 -> V_68 , V_110 ) ;
V_101 . V_108 = V_109 ;
goto V_114;
}
}
V_110 ++ ;
}
if ( V_15 && V_15 -> V_38 != V_72 ) {
int V_116 = V_107 -> V_68 ;
F_26 ( & V_15 -> V_26 ) ;
if ( V_15 -> V_38 == V_117 &&
V_15 -> V_58 == V_59 ) {
V_101 . V_108 = V_112 ;
} else if ( V_15 -> V_58 != V_59 ) {
V_101 . V_108 = V_109 ;
} else if ( V_15 -> V_118 . V_30 & V_119 ) {
F_11 ( 0 , L_34
L_35 , V_116 ) ;
V_101 . V_108 = V_109 ;
} else if ( F_4 ( V_116 , V_15 -> V_120 ) ) {
F_11 ( 0 , L_36
L_37 , V_116 ) ;
V_101 . V_108 = V_109 ;
} else if ( F_4 ( V_116 , V_15 -> V_73 ) ) {
F_11 ( 0 , L_36
L_38 ,
V_116 ) ;
V_101 . V_108 = V_109 ;
} else {
if ( F_84 ( L_39 , V_116 ,
& V_15 -> V_82 ,
& V_107 -> V_121 ) ) {
V_101 . V_108 = V_122 ;
} else if ( F_84 ( L_40 , V_116 ,
& V_15 -> V_123 ,
& V_107 -> V_124 ) ) {
V_101 . V_108 = V_122 ;
} else {
V_101 . V_125 = V_107 -> V_121 . V_84 ;
V_101 . V_126 = V_107 -> V_124 . V_84 ;
V_101 . V_108 = V_127 ;
F_91 ( V_15 , V_107 -> V_68 ) ;
}
}
F_27 ( & V_15 -> V_26 ) ;
}
V_114:
F_27 ( & V_36 ) ;
V_111:
F_11 ( 0 , L_41 , V_101 . V_108 ) ;
F_86 ( & V_101 , & V_104 ) ;
return V_104 ;
}
static int F_92 ( struct V_60 * V_61 , T_2 V_21 , void * V_62 ,
void * * V_63 )
{
struct V_128 * assert ;
struct V_14 * V_15 = NULL ;
assert = (struct V_128 * ) V_61 -> V_67 ;
F_11 ( 0 , L_42 , assert -> V_68 ,
assert -> V_32 ) ;
F_26 ( & V_36 ) ;
V_15 = F_30 ( assert -> V_32 , assert -> V_113 ) ;
if ( V_15 ) {
F_26 ( & V_15 -> V_26 ) ;
F_39 ( V_15 -> V_58 != assert -> V_68 ) ;
F_62 ( assert -> V_68 , V_15 -> V_73 ) ;
F_69 ( assert -> V_68 , V_15 -> V_69 ) ;
F_91 ( V_15 , V_59 ) ;
F_66 ( V_75 L_43 ,
assert -> V_68 , V_15 -> V_19 ) ;
F_65 ( V_15 ) ;
F_70 ( V_15 , assert -> V_68 , 1 ) ;
F_27 ( & V_15 -> V_26 ) ;
}
F_27 ( & V_36 ) ;
return 0 ;
}
static int F_93 ( struct V_14 * V_15 ,
struct V_129 * V_130 ,
char * V_131 , int V_132 )
{
char * V_133 = V_130 -> V_134 ;
char * V_135 , * V_136 ;
int V_137 , V_10 , V_138 , V_139 ;
int V_77 = 0 ;
if ( ! F_94 () ) {
if ( V_130 -> V_140 ) {
F_11 ( V_81 , L_44
L_45 ,
V_130 -> V_141 , V_130 -> V_142 , V_15 -> V_79 ) ;
V_77 = - V_143 ;
}
goto V_144;
}
if ( F_94 () && ! V_130 -> V_140 ) {
F_11 ( V_81 , L_46
L_47 ,
V_130 -> V_141 , V_15 -> V_79 , V_130 -> V_142 ) ;
V_77 = - V_143 ;
goto V_144;
}
V_136 = V_133 ;
for ( V_10 = 0 ; V_10 < V_130 -> V_140 ; ++ V_10 ) {
F_11 ( 0 , L_48 , V_145 , V_136 ) ;
V_136 += V_145 ;
}
V_137 = F_95 ( V_146 , V_132 / V_145 ) ;
V_137 = F_96 ( V_131 , ( T_1 ) V_137 ) ;
V_135 = V_131 ;
for ( V_10 = 0 ; V_10 < V_137 ; ++ V_10 ) {
V_139 = 0 ;
V_136 = V_133 ;
for ( V_138 = 0 ; V_138 <= V_130 -> V_140 ; ++ V_138 ) {
if ( ! memcmp ( V_135 , V_136 , V_145 ) ) {
V_139 = 1 ;
break;
}
V_136 += V_145 ;
}
if ( ! V_139 ) {
V_77 = - V_143 ;
F_11 ( V_81 , L_49
L_50 ,
V_130 -> V_141 , V_145 , V_135 ,
V_15 -> V_79 , V_130 -> V_142 ) ;
goto V_144;
}
V_135 += V_145 ;
}
V_136 = V_133 ;
for ( V_10 = 0 ; V_10 < V_130 -> V_140 ; ++ V_10 ) {
V_139 = 0 ;
V_135 = V_131 ;
for ( V_138 = 0 ; V_138 < V_137 ; ++ V_138 ) {
if ( ! memcmp ( V_136 , V_135 , V_145 ) ) {
V_139 = 1 ;
break;
}
V_135 += V_145 ;
}
if ( ! V_139 ) {
V_77 = - V_143 ;
F_11 ( V_81 , L_49
L_51 ,
V_130 -> V_141 , V_145 , V_136 ,
V_130 -> V_142 , V_15 -> V_79 ) ;
goto V_144;
}
V_136 += V_145 ;
}
V_144:
return V_77 ;
}
static int F_97 ( struct V_14 * V_15 , unsigned long * V_115 )
{
struct V_129 * V_130 = NULL ;
int V_77 , V_37 = 0 , V_10 ;
char * V_147 ;
if ( F_67 ( V_115 , V_74 , 0 ) >= V_74 )
goto V_144;
V_130 = F_98 ( sizeof( struct V_129 ) , V_9 ) ;
if ( ! V_130 ) {
V_37 = - V_148 ;
F_99 ( V_37 ) ;
goto V_144;
}
V_130 -> V_142 = V_15 -> V_79 ;
V_130 -> V_149 = strlen ( V_15 -> V_19 ) ;
memcpy ( V_130 -> V_141 , V_15 -> V_19 , V_130 -> V_149 ) ;
if ( F_94 () )
V_130 -> V_140 = F_96 ( V_130 -> V_134 ,
V_146 ) ;
V_147 = V_130 -> V_134 ;
for ( V_10 = 0 ; V_10 < V_130 -> V_140 ; ++ V_10 , V_147 += V_145 )
F_11 ( 0 , L_48 , V_145 , V_147 ) ;
V_10 = - 1 ;
while ( ( V_10 = F_67 ( V_115 , V_74 ,
V_10 + 1 ) ) < V_74 ) {
if ( V_10 == V_15 -> V_79 )
continue;
F_11 ( 0 , L_52 , V_10 ) ;
V_37 = F_72 ( V_150 , V_151 , V_130 ,
sizeof( struct V_129 ) ,
V_10 , & V_77 ) ;
if ( V_37 >= 0 )
V_37 = V_77 ;
if ( V_37 ) {
F_11 ( V_81 , L_53 ,
V_37 , V_10 ) ;
break;
}
}
V_144:
F_7 ( V_130 ) ;
return V_37 ;
}
static int F_100 ( struct V_60 * V_61 , T_2 V_21 ,
void * V_62 , void * * V_63 )
{
struct V_129 * V_130 ;
struct V_14 * V_15 = NULL ;
char * V_131 = NULL ;
int V_77 = 0 ;
int V_152 = 0 ;
V_130 = (struct V_129 * ) V_61 -> V_67 ;
F_11 ( 0 , L_54 , V_130 -> V_142 ,
V_130 -> V_141 ) ;
V_131 = F_9 ( sizeof( V_130 -> V_134 ) , V_9 ) ;
if ( ! V_131 ) {
V_77 = - V_148 ;
goto V_144;
}
V_77 = - V_143 ;
F_26 ( & V_36 ) ;
V_15 = F_30 ( V_130 -> V_141 , V_130 -> V_149 ) ;
if ( ! V_15 ) {
F_11 ( V_81 , L_55
L_56 , V_130 -> V_142 , V_130 -> V_141 ) ;
goto V_144;
}
F_26 ( & V_15 -> V_26 ) ;
V_152 = 1 ;
if ( V_15 -> V_58 != V_130 -> V_142 ) {
F_11 ( V_81 , L_55
L_57 , V_130 -> V_142 , V_130 -> V_141 ,
V_15 -> V_58 ) ;
goto V_144;
}
if ( V_15 -> V_82 . V_83 == 1 &&
V_15 -> V_82 . V_84 == 0 ) {
F_11 ( V_81 , L_55
L_58 , V_130 -> V_142 ,
V_130 -> V_141 , V_15 -> V_82 . V_83 ,
V_15 -> V_82 . V_84 ) ;
goto V_144;
}
V_77 = F_93 ( V_15 , V_130 , V_131 , sizeof( V_130 -> V_134 ) ) ;
V_144:
if ( V_152 )
F_27 ( & V_15 -> V_26 ) ;
F_27 ( & V_36 ) ;
F_7 ( V_131 ) ;
return V_77 ;
}
static int F_101 ( struct V_14 * V_15 , struct V_153 * V_154 )
{
struct V_155 * V_131 ;
struct V_156 * V_133 ;
int V_10 , V_138 ;
int V_77 = 0 ;
for ( V_138 = 0 ; V_138 < V_154 -> V_157 ; ++ V_138 )
F_11 ( 0 , L_59 , V_154 -> V_158 [ V_138 ] . V_159 ,
& ( V_154 -> V_158 [ V_138 ] . V_160 ) ,
F_102 ( V_154 -> V_158 [ V_138 ] . V_161 ) ) ;
for ( V_10 = 0 ; V_10 < V_74 && ! V_77 ; ++ V_10 ) {
V_131 = F_103 ( V_10 ) ;
V_133 = NULL ;
for ( V_138 = 0 ; V_138 < V_154 -> V_157 ; ++ V_138 ) {
if ( V_154 -> V_158 [ V_138 ] . V_159 == V_10 ) {
V_133 = & ( V_154 -> V_158 [ V_138 ] ) ;
break;
}
}
if ( ! V_131 && ! V_133 )
continue;
if ( ( V_131 && ! V_133 ) || ( ! V_131 && V_133 ) )
V_77 = - V_143 ;
if ( ! V_77 &&
( ( V_133 -> V_159 != V_131 -> V_162 ) ||
( V_133 -> V_161 != V_131 -> V_163 ) ||
( V_133 -> V_160 != V_131 -> V_164 ) ) )
V_77 = - V_143 ;
if ( V_77 ) {
if ( V_133 && ! V_131 )
F_11 ( V_81 , L_60
L_61
L_62 , V_154 -> V_165 ,
V_133 -> V_159 ,
& ( V_133 -> V_160 ) ,
F_102 ( V_133 -> V_161 ) ,
V_154 -> V_166 , V_15 -> V_79 ) ;
if ( V_131 && ! V_133 )
F_11 ( V_81 , L_60
L_63
L_64 , V_154 -> V_165 ,
V_131 -> V_162 , & ( V_131 -> V_164 ) ,
F_102 ( V_131 -> V_163 ) ,
V_15 -> V_79 , V_154 -> V_166 ) ;
F_39 ( ( ! V_131 && ! V_133 ) ) ;
}
if ( V_131 )
F_104 ( V_131 ) ;
}
return V_77 ;
}
static int F_105 ( struct V_14 * V_15 , unsigned long * V_115 )
{
struct V_153 * V_154 = NULL ;
struct V_155 * V_64 ;
int V_37 = 0 , V_77 , V_167 , V_10 ;
if ( F_67 ( V_115 , V_74 , 0 ) >= V_74 )
goto V_144;
V_154 = F_98 ( sizeof( struct V_153 ) , V_9 ) ;
if ( ! V_154 ) {
V_37 = - V_148 ;
F_99 ( V_37 ) ;
goto V_144;
}
for ( V_10 = 0 , V_167 = 0 ; V_10 < V_74 ; ++ V_10 ) {
V_64 = F_103 ( V_10 ) ;
if ( ! V_64 )
continue;
V_154 -> V_158 [ V_167 ] . V_159 = V_64 -> V_162 ;
V_154 -> V_158 [ V_167 ] . V_161 = V_64 -> V_163 ;
V_154 -> V_158 [ V_167 ] . V_160 = V_64 -> V_164 ;
F_11 ( 0 , L_59 , V_64 -> V_162 ,
& ( V_64 -> V_164 ) , F_102 ( V_64 -> V_163 ) ) ;
++ V_167 ;
F_104 ( V_64 ) ;
}
V_154 -> V_166 = V_15 -> V_79 ;
V_154 -> V_157 = V_167 ;
V_154 -> V_168 = strlen ( V_15 -> V_19 ) ;
memcpy ( V_154 -> V_165 , V_15 -> V_19 , V_154 -> V_168 ) ;
V_10 = - 1 ;
while ( ( V_10 = F_67 ( V_115 , V_74 ,
V_10 + 1 ) ) < V_74 ) {
if ( V_10 == V_15 -> V_79 )
continue;
F_11 ( 0 , L_65 , V_10 ) ;
V_37 = F_72 ( V_169 , V_151 ,
V_154 , sizeof( struct V_153 ) ,
V_10 , & V_77 ) ;
if ( V_37 >= 0 )
V_37 = V_77 ;
if ( V_37 ) {
F_11 ( V_81 , L_66 , V_37 , V_10 ) ;
break;
}
}
V_144:
F_7 ( V_154 ) ;
return V_37 ;
}
static int F_106 ( struct V_60 * V_61 , T_2 V_21 ,
void * V_62 , void * * V_63 )
{
struct V_153 * V_154 ;
struct V_14 * V_15 = NULL ;
int V_152 = 0 , V_77 = - V_143 ;
V_154 = (struct V_153 * ) V_61 -> V_67 ;
F_11 ( 0 , L_67 , V_154 -> V_166 ,
V_154 -> V_165 ) ;
F_26 ( & V_36 ) ;
V_15 = F_30 ( V_154 -> V_165 , V_154 -> V_168 ) ;
if ( ! V_15 ) {
F_11 ( V_81 , L_68
L_69 , V_154 -> V_166 , V_154 -> V_165 ) ;
goto V_144;
}
F_26 ( & V_15 -> V_26 ) ;
V_152 = 1 ;
if ( V_15 -> V_58 != V_154 -> V_166 ) {
F_11 ( V_81 , L_70
L_71 , V_154 -> V_166 , V_154 -> V_165 ,
V_15 -> V_58 ) ;
goto V_144;
}
if ( V_15 -> V_82 . V_83 == 1 &&
V_15 -> V_82 . V_84 == 0 ) {
F_11 ( V_81 , L_72
L_58 , V_154 -> V_166 ,
V_154 -> V_165 , V_15 -> V_82 . V_83 ,
V_15 -> V_82 . V_84 ) ;
goto V_144;
}
V_77 = F_101 ( V_15 , V_154 ) ;
V_144:
if ( V_152 )
F_27 ( & V_15 -> V_26 ) ;
F_27 ( & V_36 ) ;
return V_77 ;
}
static int F_107 ( struct V_60 * V_61 , T_2 V_21 , void * V_62 ,
void * * V_63 )
{
struct V_170 * V_171 ;
struct V_14 * V_15 = NULL ;
V_171 = (struct V_170 * ) V_61 -> V_67 ;
F_11 ( 0 , L_73 , V_171 -> V_68 ,
V_171 -> V_32 ) ;
F_26 ( & V_36 ) ;
V_15 = F_30 ( V_171 -> V_32 , V_171 -> V_113 ) ;
if ( V_15 ) {
F_26 ( & V_15 -> V_26 ) ;
F_39 ( V_15 -> V_58 != V_171 -> V_68 ) ;
F_91 ( V_15 , V_59 ) ;
F_27 ( & V_15 -> V_26 ) ;
}
F_27 ( & V_36 ) ;
return 0 ;
}
static int F_108 ( struct V_14 * V_15 ,
unsigned int V_64 )
{
int V_77 ;
struct V_170 V_172 ;
memset ( & V_172 , 0 , sizeof( V_172 ) ) ;
V_172 . V_68 = V_15 -> V_79 ;
V_172 . V_113 = strlen ( V_15 -> V_19 ) ;
memcpy ( V_172 . V_32 , V_15 -> V_19 , V_172 . V_113 ) ;
V_77 = F_72 ( V_173 , V_151 ,
& V_172 , sizeof( V_172 ) , V_64 ,
NULL ) ;
if ( V_77 < 0 ) {
F_11 ( V_81 , L_74
L_75 , V_77 , V_173 , V_151 ,
V_64 ) ;
goto V_144;
}
V_144:
return V_77 ;
}
static int F_109 ( struct V_14 * V_15 ,
unsigned long * V_115 ,
unsigned int V_174 )
{
int V_77 , V_175 ;
unsigned int V_64 ;
if ( V_174 != ( F_110 ( V_74 ) *
sizeof( unsigned long ) ) ) {
F_11 ( V_81 ,
L_76 ,
V_174 , ( unsigned ) F_110 ( V_74 ) ) ;
return - V_143 ;
}
V_77 = 0 ;
V_64 = - 1 ;
while ( ( V_64 = F_67 ( V_115 , V_74 ,
V_64 + 1 ) ) < V_74 ) {
if ( V_64 == V_15 -> V_79 )
continue;
V_175 = F_108 ( V_15 , V_64 ) ;
if ( V_175 ) {
F_11 ( V_81 , L_77
L_78 , V_175 , V_64 ) ;
if ( ! V_77 )
V_77 = V_175 ;
}
}
if ( V_77 )
F_99 ( V_77 ) ;
return V_77 ;
}
static int F_111 ( struct V_14 * V_15 ,
int V_64 ,
enum V_176 * V_104 )
{
int V_77 ;
struct V_106 V_177 ;
struct V_100 V_101 ;
T_2 V_178 ;
F_11 ( 0 , L_79 , V_64 ) ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_177 . V_68 = V_15 -> V_79 ;
V_177 . V_113 = strlen ( V_15 -> V_19 ) ;
memcpy ( V_177 . V_32 , V_15 -> V_19 , V_177 . V_113 ) ;
V_177 . V_121 = V_15 -> V_82 ;
V_177 . V_124 = V_15 -> V_123 ;
F_3 ( V_177 . V_115 , V_15 -> V_179 , V_74 ) ;
V_77 = F_72 ( V_180 , V_151 , & V_177 ,
sizeof( V_177 ) , V_64 , & V_178 ) ;
if ( V_77 < 0 && V_77 != - V_88 ) {
F_11 ( V_81 , L_74
L_75 , V_77 , V_180 , V_151 ,
V_64 ) ;
goto V_144;
}
F_88 ( V_178 , & V_101 ) ;
if ( V_77 == - V_88 ) {
V_77 = 0 ;
* V_104 = V_112 ;
} else if ( V_101 . V_108 == V_109 ||
V_101 . V_108 == V_112 ) {
* V_104 = V_101 . V_108 ;
} else if ( V_101 . V_108 == V_122 ) {
F_11 ( V_90 ,
L_80
L_81
L_82
L_83 ,
V_15 -> V_82 . V_83 ,
V_15 -> V_82 . V_84 ,
V_15 -> V_123 . V_83 ,
V_15 -> V_123 . V_84 ,
V_64 ) ;
V_77 = - V_181 ;
* V_104 = V_101 . V_108 ;
} else if ( V_101 . V_108 == V_127 ) {
* V_104 = V_101 . V_108 ;
V_15 -> V_82 . V_84 = V_101 . V_125 ;
V_15 -> V_123 . V_84 = V_101 . V_126 ;
F_11 ( 0 ,
L_84
L_85 ,
V_64 ,
V_15 -> V_82 . V_83 ,
V_15 -> V_82 . V_84 ,
V_15 -> V_123 . V_83 ,
V_15 -> V_123 . V_84 ) ;
} else {
V_77 = - V_143 ;
F_11 ( V_81 , L_86 ,
V_101 . V_108 , V_64 ) ;
}
F_11 ( 0 , L_87 , V_77 , V_64 ,
* V_104 ) ;
V_144:
return V_77 ;
}
static int F_112 ( struct V_14 * V_15 ,
unsigned int V_64 )
{
int V_77 ;
struct V_128 V_182 ;
F_11 ( 0 , L_88 , V_64 ) ;
memset ( & V_182 , 0 , sizeof( V_182 ) ) ;
V_182 . V_68 = V_15 -> V_79 ;
V_182 . V_113 = strlen ( V_15 -> V_19 ) ;
memcpy ( V_182 . V_32 , V_15 -> V_19 , V_182 . V_113 ) ;
V_77 = F_72 ( V_183 , V_151 ,
& V_182 , sizeof( V_182 ) , V_64 ,
NULL ) ;
if ( V_77 < 0 )
F_11 ( V_81 , L_74
L_75 , V_77 , V_183 , V_151 ,
V_64 ) ;
return V_77 ;
}
static void F_113 ( struct V_14 * V_15 ,
unsigned long * V_115 )
{
int V_77 , V_64 , V_184 ;
V_77 = 0 ;
V_64 = - 1 ;
while ( ( V_64 = F_67 ( V_115 , V_74 ,
V_64 + 1 ) ) < V_74 ) {
if ( V_64 == V_15 -> V_79 )
continue;
do {
V_77 = F_112 ( V_15 , V_64 ) ;
F_26 ( & V_15 -> V_26 ) ;
V_184 = F_4 ( V_64 , V_15 -> V_179 ) ;
F_27 ( & V_15 -> V_26 ) ;
if ( V_77 ) {
F_11 ( V_81 , L_89
L_90 , V_77 , V_64 ) ;
if ( V_184 )
F_75 ( V_91 ) ;
}
} while ( V_77 && V_184 );
}
}
static int F_114 ( struct V_14 * V_15 ,
struct V_185 * V_186 ,
enum V_176 V_104 )
{
int V_37 ;
if ( V_104 == V_109 ) {
F_11 ( 0 , L_91 ) ;
return 1 ;
}
F_26 ( & V_15 -> V_26 ) ;
V_37 = memcmp ( V_186 -> V_187 , V_15 -> V_179 ,
sizeof( V_15 -> V_179 ) ) ;
F_27 ( & V_15 -> V_26 ) ;
if ( V_37 )
F_11 ( 0 , L_92 ) ;
return V_37 ;
}
static int F_115 ( struct V_14 * V_15 )
{
int V_77 = 0 , V_175 , V_64 ;
struct V_185 * V_186 ;
enum V_176 V_104 = V_109 ;
F_11 ( 0 , L_93 , V_15 ) ;
V_186 = F_98 ( sizeof( * V_186 ) , V_9 ) ;
if ( ! V_186 ) {
V_77 = - V_148 ;
F_99 ( V_77 ) ;
goto V_144;
}
F_116 ( V_15 -> V_179 , sizeof( V_15 -> V_179 ) ) ;
F_26 ( & V_15 -> V_26 ) ;
memcpy ( V_186 -> V_187 , V_15 -> V_179 , sizeof( V_186 -> V_187 ) ) ;
F_91 ( V_15 , V_15 -> V_79 ) ;
F_27 ( & V_15 -> V_26 ) ;
V_64 = - 1 ;
while ( ( V_64 = F_67 ( V_186 -> V_187 , V_74 ,
V_64 + 1 ) ) < V_74 ) {
if ( V_64 == V_15 -> V_79 )
continue;
V_77 = F_111 ( V_15 , V_64 , & V_104 ) ;
if ( V_77 < 0 ) {
F_99 ( V_77 ) ;
goto V_144;
}
if ( V_104 == V_127 )
F_62 ( V_64 , V_186 -> V_188 ) ;
if ( F_114 ( V_15 , V_186 , V_104 ) ) {
V_77 = - V_57 ;
goto V_144;
}
}
F_11 ( 0 , L_94 ) ;
F_26 ( & V_15 -> V_26 ) ;
memcpy ( V_15 -> V_73 , V_186 -> V_188 ,
sizeof( V_186 -> V_188 ) ) ;
F_62 ( V_15 -> V_79 , V_15 -> V_73 ) ;
F_27 ( & V_15 -> V_26 ) ;
if ( V_15 -> V_82 . V_83 > 1 ||
V_15 -> V_82 . V_84 > 0 ) {
V_77 = F_105 ( V_15 , V_186 -> V_188 ) ;
if ( V_77 ) {
F_99 ( V_77 ) ;
goto V_144;
}
V_77 = F_97 ( V_15 , V_186 -> V_188 ) ;
if ( V_77 ) {
F_99 ( V_77 ) ;
goto V_144;
}
}
F_113 ( V_15 , V_186 -> V_188 ) ;
F_26 ( & V_36 ) ;
V_15 -> V_38 = V_39 ;
V_15 -> V_44 ++ ;
F_27 ( & V_36 ) ;
V_144:
F_26 ( & V_15 -> V_26 ) ;
F_91 ( V_15 , V_59 ) ;
if ( ! V_77 ) {
F_66 ( V_75 L_95 , V_15 -> V_19 ) ;
F_65 ( V_15 ) ;
}
F_27 ( & V_15 -> V_26 ) ;
if ( V_186 ) {
if ( V_77 < 0 ) {
V_175 = F_109 ( V_15 ,
V_186 -> V_188 ,
sizeof( V_186 -> V_188 ) ) ;
if ( V_175 < 0 )
F_99 ( V_175 ) ;
}
F_7 ( V_186 ) ;
}
F_11 ( 0 , L_96 , V_77 ) ;
return V_77 ;
}
static void F_52 ( struct V_14 * V_15 )
{
F_117 ( V_15 -> V_19 , & V_15 -> V_189 ) ;
F_117 ( V_15 -> V_19 , & V_15 -> V_190 ) ;
F_118 ( & V_15 -> V_191 ) ;
}
static int F_119 ( struct V_14 * V_15 )
{
int V_77 ;
F_11 ( 0 , L_97 ) ;
F_120 ( & V_15 -> V_190 , V_192 ,
V_193 , V_15 , V_194 ) ;
V_77 = F_121 ( V_15 -> V_19 , & V_15 -> V_190 ) ;
if ( V_77 )
goto V_144;
F_120 ( & V_15 -> V_189 , V_195 ,
V_196 , V_15 , V_197 ) ;
V_77 = F_121 ( V_15 -> V_19 , & V_15 -> V_189 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_198 , V_15 -> V_80 ,
sizeof( struct V_199 ) ,
V_200 ,
V_15 , NULL , & V_15 -> V_191 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_201 , V_15 -> V_80 ,
sizeof( struct V_202 ) ,
V_203 ,
V_15 , V_204 ,
& V_15 -> V_191 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_205 , V_15 -> V_80 ,
sizeof( struct V_206 ) ,
V_207 ,
V_15 , NULL , & V_15 -> V_191 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_208 , V_15 -> V_80 ,
V_209 ,
V_210 ,
V_15 , NULL , & V_15 -> V_191 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_211 , V_15 -> V_80 ,
V_212 ,
V_213 ,
V_15 , NULL , & V_15 -> V_191 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_214 , V_15 -> V_80 ,
V_215 ,
V_216 ,
V_15 , NULL , & V_15 -> V_191 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_87 , V_15 -> V_80 ,
sizeof( struct V_65 ) ,
F_68 ,
V_15 , NULL , & V_15 -> V_191 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_217 , V_15 -> V_80 ,
sizeof( struct V_218 ) ,
V_219 ,
V_15 , NULL , & V_15 -> V_191 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_220 , V_15 -> V_80 ,
sizeof( struct V_221 ) ,
V_222 ,
V_15 , NULL , & V_15 -> V_191 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_223 , V_15 -> V_80 ,
V_224 ,
V_225 ,
V_15 , NULL , & V_15 -> V_191 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_226 , V_15 -> V_80 ,
sizeof( struct V_227 ) ,
V_228 ,
V_15 , NULL , & V_15 -> V_191 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_229 , V_15 -> V_80 ,
sizeof( struct V_230 ) ,
V_231 ,
V_15 , NULL , & V_15 -> V_191 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_232 , V_15 -> V_80 ,
sizeof( struct V_233 ) ,
V_234 ,
V_15 , NULL , & V_15 -> V_191 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_235 , V_15 -> V_80 ,
sizeof( struct V_236 ) ,
V_237 ,
V_15 , NULL , & V_15 -> V_191 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_238 , V_15 -> V_80 ,
sizeof( struct V_239 ) ,
V_240 ,
V_15 , NULL , & V_15 -> V_191 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_85 , V_15 -> V_80 ,
sizeof( struct V_65 ) ,
F_61 ,
V_15 , NULL , & V_15 -> V_191 ) ;
if ( V_77 )
goto V_144;
V_144:
if ( V_77 )
F_52 ( V_15 ) ;
return V_77 ;
}
static int F_123 ( struct V_14 * V_15 )
{
int V_77 ;
unsigned int V_241 ;
unsigned int V_242 = 0 ;
F_39 ( ! V_15 ) ;
F_11 ( 0 , L_98 , V_15 -> V_19 ) ;
V_77 = F_119 ( V_15 ) ;
if ( V_77 ) {
F_99 ( V_77 ) ;
goto V_144;
}
V_77 = F_124 ( V_15 ) ;
if ( V_77 < 0 ) {
F_99 ( V_77 ) ;
goto V_144;
}
V_77 = F_125 ( V_15 ) ;
if ( V_77 < 0 ) {
F_99 ( V_77 ) ;
goto V_144;
}
V_77 = F_126 ( V_15 ) ;
if ( V_77 < 0 ) {
F_99 ( V_77 ) ;
goto V_144;
}
V_15 -> V_48 = F_127 ( L_99 ) ;
if ( ! V_15 -> V_48 ) {
V_77 = - V_148 ;
F_99 ( V_77 ) ;
goto V_144;
}
do {
V_77 = F_115 ( V_15 ) ;
#define F_128 90000
if ( V_77 == - V_57 ) {
if ( F_129 ( V_243 ) ) {
V_77 = - V_244 ;
goto V_144;
}
if ( V_242 >
F_130 ( F_128 ) ) {
V_77 = - V_244 ;
F_11 ( V_90 , L_100
L_101 , V_15 -> V_19 ,
F_131 ( V_242 ) ) ;
goto V_144;
}
V_241 = ( unsigned int ) ( V_245 & 0x3 ) ;
V_241 *= V_91 ;
V_242 += V_241 ;
F_11 ( 0 , L_102 , V_241 ) ;
F_75 ( V_241 ) ;
}
} while ( V_77 == - V_57 );
if ( V_77 < 0 ) {
F_99 ( V_77 ) ;
goto V_144;
}
V_77 = 0 ;
V_144:
F_41 ( & V_45 ) ;
if ( V_77 ) {
F_52 ( V_15 ) ;
F_53 ( V_15 ) ;
F_54 ( V_15 ) ;
F_55 ( V_15 ) ;
F_48 ( V_15 ) ;
}
return V_77 ;
}
static struct V_14 * F_132 ( const char * V_32 ,
T_2 V_80 )
{
int V_10 ;
int V_37 ;
struct V_14 * V_15 = NULL ;
V_15 = F_98 ( sizeof( * V_15 ) , V_9 ) ;
if ( ! V_15 ) {
F_99 ( - V_148 ) ;
goto V_92;
}
V_15 -> V_19 = F_133 ( V_32 , V_9 ) ;
if ( V_15 -> V_19 == NULL ) {
F_99 ( - V_148 ) ;
F_7 ( V_15 ) ;
V_15 = NULL ;
goto V_92;
}
V_15 -> V_40 = (struct V_22 * * ) F_8 ( V_12 ) ;
if ( ! V_15 -> V_40 ) {
F_99 ( - V_148 ) ;
F_7 ( V_15 -> V_19 ) ;
F_7 ( V_15 ) ;
V_15 = NULL ;
goto V_92;
}
for ( V_10 = 0 ; V_10 < V_52 ; V_10 ++ )
F_134 ( F_18 ( V_15 , V_10 ) ) ;
V_15 -> V_41 = (struct V_22 * * )
F_8 ( V_12 ) ;
if ( ! V_15 -> V_41 ) {
F_99 ( - V_148 ) ;
F_5 ( ( void * * ) V_15 -> V_40 , V_12 ) ;
F_7 ( V_15 -> V_19 ) ;
F_7 ( V_15 ) ;
V_15 = NULL ;
goto V_92;
}
for ( V_10 = 0 ; V_10 < V_52 ; V_10 ++ )
F_134 ( F_135 ( V_15 , V_10 ) ) ;
V_15 -> V_80 = V_80 ;
V_15 -> V_79 = F_136 () ;
V_37 = F_137 ( V_15 ) ;
if ( V_37 < 0 ) {
F_5 ( ( void * * ) V_15 -> V_41 , V_12 ) ;
F_5 ( ( void * * ) V_15 -> V_40 , V_12 ) ;
F_7 ( V_15 -> V_19 ) ;
F_7 ( V_15 ) ;
V_15 = NULL ;
goto V_92;
}
F_138 ( & V_15 -> V_26 ) ;
F_138 ( & V_15 -> V_246 ) ;
F_138 ( & V_15 -> V_247 ) ;
F_138 ( & V_15 -> V_248 ) ;
F_139 ( & V_15 -> V_29 ) ;
F_139 ( & V_15 -> V_249 ) ;
F_139 ( & V_15 -> V_118 . V_250 ) ;
F_139 ( & V_15 -> V_118 . V_251 ) ;
F_139 ( & V_15 -> V_118 . V_252 ) ;
F_139 ( & V_15 -> V_253 ) ;
F_139 ( & V_15 -> V_191 ) ;
F_139 ( & V_15 -> V_93 ) ;
V_15 -> V_118 . V_30 = 0 ;
F_139 ( & V_15 -> V_254 ) ;
F_139 ( & V_15 -> V_255 ) ;
F_11 ( 0 , L_103 ,
V_15 -> V_120 , & ( V_15 -> V_120 [ 0 ] ) ) ;
memset ( V_15 -> V_120 , 0 , sizeof( V_15 -> V_120 ) ) ;
memset ( V_15 -> V_179 , 0 , sizeof( V_15 -> V_179 ) ) ;
memset ( V_15 -> V_73 , 0 , sizeof( V_15 -> V_73 ) ) ;
V_15 -> V_256 = NULL ;
V_15 -> V_257 = NULL ;
V_15 -> V_48 = NULL ;
F_140 ( & V_15 -> V_56 ) ;
F_140 ( & V_15 -> V_258 ) ;
F_140 ( & V_15 -> V_118 . V_259 ) ;
F_140 ( & V_15 -> V_260 ) ;
F_140 ( & V_15 -> V_261 ) ;
F_139 ( & V_15 -> V_262 ) ;
V_15 -> V_58 = V_59 ;
F_140 ( & V_15 -> V_71 ) ;
V_15 -> V_118 . V_263 = V_264 ;
V_15 -> V_118 . V_265 = V_264 ;
F_141 ( & V_15 -> V_266 , 0 ) ;
F_141 ( & V_15 -> V_267 , 0 ) ;
for ( V_10 = 0 ; V_10 < V_268 ; ++ V_10 ) {
F_141 ( & V_15 -> V_269 [ V_10 ] , 0 ) ;
F_141 ( & V_15 -> V_270 [ V_10 ] , 0 ) ;
}
F_138 ( & V_15 -> V_271 ) ;
F_139 ( & V_15 -> V_272 ) ;
F_142 ( & V_15 -> V_273 , V_274 ) ;
F_143 ( & V_15 -> V_43 ) ;
V_15 -> V_38 = V_117 ;
F_139 ( & V_15 -> V_275 ) ;
F_11 ( 0 , L_104 ,
F_144 ( & V_15 -> V_43 . V_276 ) ) ;
V_92:
return V_15 ;
}
static int F_85 ( struct V_95 * V_277 ,
struct V_95 * V_97 )
{
if ( V_277 -> V_83 != V_97 -> V_83 )
return 1 ;
if ( V_277 -> V_84 > V_97 -> V_84 )
return 1 ;
if ( V_277 -> V_84 < V_97 -> V_84 )
V_97 -> V_84 = V_277 -> V_84 ;
return 0 ;
}
struct V_14 * F_145 ( const char * V_32 ,
T_2 V_80 ,
struct V_95 * V_124 )
{
int V_37 ;
struct V_14 * V_15 = NULL ;
struct V_14 * V_278 = NULL ;
if ( strlen ( V_32 ) >= V_279 ) {
V_37 = - V_280 ;
F_11 ( V_81 , L_105 ) ;
goto V_92;
}
F_11 ( 0 , L_106 , V_32 ) ;
V_281:
V_15 = NULL ;
if ( F_129 ( V_243 ) ) {
V_37 = - V_244 ;
F_99 ( V_37 ) ;
goto V_92;
}
F_26 ( & V_36 ) ;
V_15 = F_33 ( V_32 ) ;
if ( V_15 ) {
if ( V_15 -> V_38 != V_39 ) {
F_27 ( & V_36 ) ;
F_11 ( 0 , L_107 ) ;
F_146 ( V_45 ,
F_34 (
V_32 ) ) ;
goto V_281;
}
if ( F_85 ( & V_15 -> V_123 , V_124 ) ) {
F_27 ( & V_36 ) ;
F_11 ( V_81 ,
L_108
L_109
L_110 , V_32 ) ;
V_37 = - V_181 ;
goto V_92;
}
F_44 ( V_15 ) ;
V_15 -> V_44 ++ ;
F_27 ( & V_36 ) ;
V_37 = 0 ;
goto V_92;
}
if ( ! V_278 ) {
F_27 ( & V_36 ) ;
V_278 = F_132 ( V_32 , V_80 ) ;
if ( V_278 )
goto V_281;
V_37 = - V_148 ;
F_99 ( V_37 ) ;
goto V_92;
}
V_15 = V_278 ;
V_278 = NULL ;
F_147 ( & V_15 -> V_29 , & V_282 ) ;
F_27 ( & V_36 ) ;
V_15 -> V_82 = V_283 ;
V_15 -> V_123 = * V_124 ;
V_37 = F_123 ( V_15 ) ;
if ( V_37 ) {
F_99 ( V_37 ) ;
F_42 ( V_15 ) ;
goto V_92;
}
* V_124 = V_15 -> V_123 ;
V_37 = 0 ;
V_92:
if ( V_278 )
F_35 ( V_278 ) ;
if ( V_37 < 0 )
V_15 = F_148 ( V_37 ) ;
return V_15 ;
}
static void F_149 ( void )
{
F_118 ( & V_284 ) ;
}
static int F_150 ( void )
{
int V_77 = 0 ;
V_77 = F_122 ( V_180 , V_151 ,
sizeof( struct V_106 ) ,
F_89 ,
NULL , NULL , & V_284 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_183 , V_151 ,
sizeof( struct V_128 ) ,
F_92 ,
NULL , NULL , & V_284 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_173 , V_151 ,
sizeof( struct V_170 ) ,
F_107 ,
NULL , NULL , & V_284 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_150 , V_151 ,
sizeof( struct V_129 ) ,
F_100 ,
NULL , NULL , & V_284 ) ;
if ( V_77 )
goto V_144;
V_77 = F_122 ( V_169 , V_151 ,
sizeof( struct V_153 ) ,
F_106 ,
NULL , NULL , & V_284 ) ;
V_144:
if ( V_77 < 0 )
F_149 () ;
return V_77 ;
}
void F_151 ( struct V_14 * V_15 ,
int V_79 )
{
struct V_34 * V_35 ;
struct V_285 * V_286 ;
F_152 ( & V_287 ) ;
F_31 (iter, &dlm->dlm_eviction_callbacks) {
V_286 = F_32 ( V_35 , struct V_285 , V_288 ) ;
V_286 -> V_289 ( V_79 , V_286 -> V_290 ) ;
}
F_153 ( & V_287 ) ;
}
void F_154 ( struct V_285 * V_286 ,
T_3 * V_291 ,
void * V_62 )
{
F_139 ( & V_286 -> V_288 ) ;
V_286 -> V_289 = V_291 ;
V_286 -> V_290 = V_62 ;
}
void F_155 ( struct V_14 * V_15 ,
struct V_285 * V_286 )
{
F_156 ( & V_287 ) ;
F_147 ( & V_286 -> V_288 , & V_15 -> V_275 ) ;
F_157 ( & V_287 ) ;
}
void F_158 ( struct V_285 * V_286 )
{
F_156 ( & V_287 ) ;
F_40 ( & V_286 -> V_288 ) ;
F_157 ( & V_287 ) ;
}
static int T_4 F_159 ( void )
{
int V_77 ;
F_160 () ;
V_77 = F_161 () ;
if ( V_77 ) {
F_11 ( V_81 , L_111 ) ;
goto error;
}
V_77 = F_162 () ;
if ( V_77 ) {
F_11 ( V_81 , L_112
L_113 ) ;
goto error;
}
V_77 = F_163 () ;
if ( V_77 ) {
F_11 ( V_81 , L_114 ) ;
goto error;
}
V_77 = F_150 () ;
if ( V_77 ) {
F_11 ( V_81 , L_115 ) ;
goto error;
}
V_77 = F_164 () ;
if ( V_77 )
goto error;
return 0 ;
error:
F_149 () ;
F_165 () ;
F_166 () ;
F_167 () ;
return - 1 ;
}
static void T_5 F_168 ( void )
{
F_169 () ;
F_149 () ;
F_165 () ;
F_166 () ;
F_167 () ;
}
