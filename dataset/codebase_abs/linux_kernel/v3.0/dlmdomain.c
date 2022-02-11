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
void F_12 ( struct V_14 * V_15 )
{
if ( ! F_13 ( & V_15 -> V_16 ) ) {
F_14 ( & V_15 -> V_16 ) ;
F_15 ( V_15 ) ;
}
}
void F_16 ( struct V_17 * V_18 ,
struct V_14 * V_19 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
F_17 ( & V_18 -> V_24 ) ;
V_23 = & V_19 -> V_25 ;
V_21 = F_18 ( V_18 , V_23 -> V_26 ) ;
F_19 ( V_19 ) ;
F_20 ( & V_19 -> V_16 , V_21 ) ;
}
struct V_14 * F_21 ( struct V_17 * V_18 ,
const char * V_27 ,
unsigned int V_28 ,
unsigned int V_26 )
{
struct V_20 * V_21 ;
struct V_29 * V_30 ;
F_11 ( 0 , L_2 , V_28 , V_27 ) ;
F_17 ( & V_18 -> V_24 ) ;
V_21 = F_18 ( V_18 , V_26 ) ;
F_22 (list, bucket) {
struct V_14 * V_19 = F_23 ( V_30 ,
struct V_14 , V_16 ) ;
if ( V_19 -> V_25 . V_27 [ 0 ] != V_27 [ 0 ] )
continue;
if ( F_24 ( V_19 -> V_25 . V_28 != V_28 ) )
continue;
if ( memcmp ( V_19 -> V_25 . V_27 + 1 , V_27 + 1 , V_28 - 1 ) )
continue;
F_19 ( V_19 ) ;
return V_19 ;
}
return NULL ;
}
struct V_14 * F_25 ( struct V_17 * V_18 ,
const char * V_27 ,
unsigned int V_28 ,
unsigned int V_26 )
{
struct V_14 * V_19 = NULL ;
F_11 ( 0 , L_2 , V_28 , V_27 ) ;
F_17 ( & V_18 -> V_24 ) ;
V_19 = F_21 ( V_18 , V_27 , V_28 , V_26 ) ;
if ( V_19 ) {
F_26 ( & V_19 -> V_24 ) ;
if ( V_19 -> V_31 & V_32 ) {
F_27 ( & V_19 -> V_24 ) ;
F_15 ( V_19 ) ;
return NULL ;
}
F_27 ( & V_19 -> V_24 ) ;
}
return V_19 ;
}
struct V_14 * F_28 ( struct V_17 * V_18 ,
const char * V_27 ,
unsigned int V_28 )
{
struct V_14 * V_19 ;
unsigned int V_26 = F_29 ( V_27 , V_28 ) ;
F_26 ( & V_18 -> V_24 ) ;
V_19 = F_25 ( V_18 , V_27 , V_28 , V_26 ) ;
F_27 ( & V_18 -> V_24 ) ;
return V_19 ;
}
static struct V_17 * F_30 ( const char * V_33 , int V_28 )
{
struct V_17 * V_34 = NULL ;
struct V_35 * V_36 ;
F_17 ( & V_37 ) ;
F_31 (iter, &dlm_domains) {
V_34 = F_32 ( V_36 , struct V_17 , V_30 ) ;
if ( strlen ( V_34 -> V_27 ) == V_28 &&
memcmp ( V_34 -> V_27 , V_33 , V_28 ) == 0 )
break;
V_34 = NULL ;
}
return V_34 ;
}
static struct V_17 * F_33 ( const char * V_33 )
{
F_17 ( & V_37 ) ;
return F_30 ( V_33 , strlen ( V_33 ) ) ;
}
static int F_34 ( const char * V_33 )
{
int V_38 = 0 ;
struct V_17 * V_34 = NULL ;
F_26 ( & V_37 ) ;
V_34 = F_33 ( V_33 ) ;
if ( ! V_34 )
V_38 = 1 ;
else if ( V_34 -> V_39 == V_40 )
V_38 = 1 ;
F_27 ( & V_37 ) ;
return V_38 ;
}
static void F_35 ( struct V_17 * V_18 )
{
F_36 ( V_18 ) ;
if ( V_18 -> V_41 )
F_5 ( ( void * * ) V_18 -> V_41 , V_12 ) ;
if ( V_18 -> V_42 )
F_5 ( ( void * * ) V_18 -> V_42 , V_12 ) ;
if ( V_18 -> V_27 )
F_7 ( V_18 -> V_27 ) ;
F_7 ( V_18 ) ;
}
static void F_37 ( struct V_43 * V_43 )
{
struct V_17 * V_18 ;
V_18 = F_38 ( V_43 , struct V_17 , V_44 ) ;
F_39 ( V_18 -> V_45 ) ;
F_39 ( V_18 -> V_39 == V_40 ) ;
F_40 ( & V_18 -> V_30 ) ;
F_27 ( & V_37 ) ;
F_11 ( 0 , L_3 , V_18 -> V_27 ) ;
F_41 ( & V_46 ) ;
F_35 ( V_18 ) ;
F_26 ( & V_37 ) ;
}
void F_42 ( struct V_17 * V_18 )
{
F_26 ( & V_37 ) ;
F_43 ( & V_18 -> V_44 , F_37 ) ;
F_27 ( & V_37 ) ;
}
static void F_44 ( struct V_17 * V_18 )
{
F_45 ( & V_18 -> V_44 ) ;
}
struct V_17 * F_46 ( struct V_17 * V_18 )
{
struct V_35 * V_36 ;
struct V_17 * V_47 = NULL ;
F_26 ( & V_37 ) ;
F_31 (iter, &dlm_domains) {
V_47 = F_32 ( V_36 , struct V_17 , V_30 ) ;
if ( V_47 == V_18 ) {
F_44 ( V_47 ) ;
break;
}
V_47 = NULL ;
}
F_27 ( & V_37 ) ;
return V_47 ;
}
int F_47 ( struct V_17 * V_18 )
{
int V_38 ;
F_26 ( & V_37 ) ;
V_38 = ( V_18 -> V_39 == V_40 ) ||
( V_18 -> V_39 == V_48 ) ;
F_27 ( & V_37 ) ;
return V_38 ;
}
static void F_48 ( struct V_17 * V_18 )
{
if ( V_18 -> V_49 ) {
F_49 ( V_18 -> V_49 ) ;
F_50 ( V_18 -> V_49 ) ;
V_18 -> V_49 = NULL ;
}
}
static void F_51 ( struct V_17 * V_18 )
{
F_52 ( V_18 ) ;
F_53 ( V_18 ) ;
F_54 ( V_18 ) ;
F_55 ( V_18 ) ;
F_48 ( V_18 ) ;
F_26 ( & V_37 ) ;
F_40 ( & V_18 -> V_30 ) ;
F_27 ( & V_37 ) ;
F_41 ( & V_46 ) ;
}
static int F_56 ( struct V_17 * V_18 )
{
int V_10 , V_50 , V_51 , V_38 = 0 ;
struct V_14 * V_19 ;
struct V_29 * V_36 ;
struct V_20 * V_21 ;
int V_52 ;
F_11 ( 0 , L_4 , V_18 -> V_27 ) ;
V_50 = 0 ;
F_26 ( & V_18 -> V_24 ) ;
for ( V_10 = 0 ; V_10 < V_53 ; V_10 ++ ) {
V_54:
V_51 = 0 ;
V_21 = F_18 ( V_18 , V_10 ) ;
V_36 = V_21 -> V_55 ;
while ( V_36 ) {
V_51 ++ ;
V_19 = F_23 ( V_36 , struct V_14 ,
V_16 ) ;
F_19 ( V_19 ) ;
V_52 = F_57 ( V_18 , V_19 ) ;
F_26 ( & V_19 -> V_24 ) ;
if ( V_52 )
F_58 ( V_18 , V_19 ) ;
else
V_36 = V_19 -> V_16 . V_56 ;
F_27 ( & V_19 -> V_24 ) ;
F_15 ( V_19 ) ;
if ( V_52 ) {
F_59 ( & V_18 -> V_24 ) ;
goto V_54;
}
}
F_59 ( & V_18 -> V_24 ) ;
V_50 += V_51 ;
}
F_27 ( & V_18 -> V_24 ) ;
F_41 ( & V_18 -> V_57 ) ;
if ( V_50 ) {
F_11 ( 0 , L_5 ,
V_18 -> V_27 , V_50 ) ;
V_38 = - V_58 ;
}
F_11 ( 0 , L_6 , V_18 -> V_27 ) ;
return V_38 ;
}
static int F_60 ( struct V_17 * V_18 )
{
int V_38 ;
F_26 ( & V_18 -> V_24 ) ;
V_38 = V_18 -> V_59 == V_60 ;
F_27 ( & V_18 -> V_24 ) ;
return V_38 ;
}
static int F_61 ( struct V_61 * V_62 , T_2 V_28 ,
void * V_63 , void * * V_64 )
{
struct V_17 * V_18 = V_63 ;
unsigned int V_65 ;
struct V_66 * V_67 = (struct V_66 * ) V_62 -> V_68 ;
if ( ! F_46 ( V_18 ) )
return 0 ;
V_65 = V_67 -> V_69 ;
F_11 ( 0 , L_7 , V_18 -> V_27 , V_65 ) ;
F_26 ( & V_18 -> V_24 ) ;
F_62 ( V_65 , V_18 -> V_70 ) ;
F_27 ( & V_18 -> V_24 ) ;
F_42 ( V_18 ) ;
return 0 ;
}
static void F_63 ( struct V_17 * V_18 )
{
V_71:
F_26 ( & V_37 ) ;
F_26 ( & V_18 -> V_24 ) ;
if ( V_18 -> V_59 != V_60 ) {
F_11 ( 0 , L_8 ,
V_18 -> V_59 ) ;
F_27 ( & V_18 -> V_24 ) ;
F_27 ( & V_37 ) ;
F_64 ( V_18 -> V_72 , F_60 ( V_18 ) ) ;
goto V_71;
}
V_18 -> V_39 = V_73 ;
F_27 ( & V_18 -> V_24 ) ;
F_27 ( & V_37 ) ;
}
static void F_65 ( struct V_17 * V_18 )
{
int V_65 = - 1 ;
F_17 ( & V_18 -> V_24 ) ;
F_66 ( V_74 L_9 , V_18 -> V_27 ) ;
while ( ( V_65 = F_67 ( V_18 -> V_75 , V_76 ,
V_65 + 1 ) ) < V_76 ) {
F_66 ( L_10 , V_65 ) ;
}
F_66 ( L_11 ) ;
}
static int F_68 ( struct V_61 * V_62 , T_2 V_28 , void * V_63 ,
void * * V_64 )
{
struct V_17 * V_18 = V_63 ;
unsigned int V_65 ;
struct V_66 * V_67 = (struct V_66 * ) V_62 -> V_68 ;
F_11 ( 0 , L_12 , V_62 , V_28 , V_63 ) ;
if ( ! F_46 ( V_18 ) )
return 0 ;
V_65 = V_67 -> V_69 ;
F_66 ( V_74 L_13 , V_65 , V_18 -> V_27 ) ;
F_26 ( & V_18 -> V_24 ) ;
F_69 ( V_65 , V_18 -> V_75 ) ;
F_69 ( V_65 , V_18 -> V_70 ) ;
F_65 ( V_18 ) ;
F_70 ( V_18 , V_65 , 0 ) ;
F_27 ( & V_18 -> V_24 ) ;
F_42 ( V_18 ) ;
return 0 ;
}
static int F_71 ( struct V_17 * V_18 , T_2 V_77 ,
unsigned int V_65 )
{
int V_78 ;
struct V_66 V_79 ;
F_11 ( 0 , L_14 , V_18 -> V_27 ,
V_77 , V_65 ) ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_79 . V_69 = V_18 -> V_80 ;
V_78 = F_72 ( V_77 , V_18 -> V_81 , & V_79 ,
sizeof( V_79 ) , V_65 , NULL ) ;
if ( V_78 < 0 )
F_11 ( V_82 , L_15
L_16 , V_78 , V_77 , V_65 ,
V_18 -> V_27 ) ;
return V_78 ;
}
static void F_73 ( struct V_17 * V_18 )
{
int V_65 = - 1 ;
if ( V_18 -> V_83 . V_84 == 1 &&
V_18 -> V_83 . V_85 < 2 )
return;
F_26 ( & V_18 -> V_24 ) ;
while ( 1 ) {
V_65 = F_67 ( V_18 -> V_75 , V_76 , V_65 + 1 ) ;
if ( V_65 >= V_76 )
break;
if ( V_65 == V_18 -> V_80 )
continue;
F_27 ( & V_18 -> V_24 ) ;
F_71 ( V_18 , V_86 , V_65 ) ;
F_26 ( & V_18 -> V_24 ) ;
}
F_27 ( & V_18 -> V_24 ) ;
}
static void F_74 ( struct V_17 * V_18 )
{
int V_65 , V_87 , V_78 ;
F_26 ( & V_18 -> V_24 ) ;
F_69 ( V_18 -> V_80 , V_18 -> V_75 ) ;
while ( ( V_65 = F_67 ( V_18 -> V_75 , V_76 ,
0 ) ) < V_76 ) {
F_27 ( & V_18 -> V_24 ) ;
V_87 = 1 ;
V_78 = F_71 ( V_18 , V_88 ,
V_65 ) ;
if ( V_78 < 0 &&
V_78 != - V_89 &&
V_78 != - V_90 ) {
F_11 ( V_91 , L_17
L_18 , V_78 , V_65 ) ;
F_75 ( V_92 ) ;
V_87 = 0 ;
}
F_26 ( & V_18 -> V_24 ) ;
if ( V_87 )
F_69 ( V_65 , V_18 -> V_75 ) ;
}
F_27 ( & V_18 -> V_24 ) ;
}
int F_76 ( struct V_17 * V_18 )
{
int V_38 = 0 ;
F_26 ( & V_37 ) ;
if ( V_18 -> V_39 == V_40 )
V_38 = 1 ;
F_27 ( & V_37 ) ;
return V_38 ;
}
int F_77 ( struct V_17 * V_18 )
{
int V_38 = 0 ;
F_26 ( & V_37 ) ;
if ( V_18 -> V_39 == V_48 )
V_38 = 1 ;
F_27 ( & V_37 ) ;
return V_38 ;
}
void F_78 ( struct V_17 * V_18 )
{
int V_93 = 0 ;
struct V_14 * V_19 ;
F_26 ( & V_37 ) ;
F_39 ( V_18 -> V_39 != V_40 ) ;
F_39 ( ! V_18 -> V_45 ) ;
V_18 -> V_45 -- ;
if ( ! V_18 -> V_45 ) {
V_18 -> V_39 = V_48 ;
V_93 = 1 ;
}
F_27 ( & V_37 ) ;
if ( V_93 ) {
F_11 ( 0 , L_19 , V_18 -> V_27 ) ;
F_73 ( V_18 ) ;
F_79 ( V_18 , NULL ) ;
while ( F_56 ( V_18 ) ) {
F_75 ( 500 ) ;
F_11 ( 0 , L_20 , V_18 -> V_27 ) ;
}
if ( ! F_80 ( & V_18 -> V_94 ) ) {
F_11 ( V_82 , L_21
L_22 ) ;
F_81 (res, &dlm->tracking_list, tracking)
F_82 ( V_19 ) ;
}
F_63 ( V_18 ) ;
F_74 ( V_18 ) ;
F_83 ( V_18 ) ;
F_51 ( V_18 ) ;
}
F_42 ( V_18 ) ;
}
static int F_84 ( char * V_95 , int V_65 ,
struct V_96 * V_97 ,
struct V_96 * V_98 )
{
int V_99 ;
struct V_96 V_100 = * V_98 ;
if ( ! F_85 ( V_97 , & V_100 ) ) {
F_11 ( 0 ,
L_23
L_24 ,
V_65 , V_95 ,
V_98 -> V_84 ,
V_98 -> V_85 ,
V_100 . V_84 , V_100 . V_85 ) ;
V_98 -> V_85 = V_100 . V_85 ;
V_99 = 0 ;
} else {
F_11 ( V_91 ,
L_25
L_26 ,
V_65 , V_95 ,
V_98 -> V_84 ,
V_98 -> V_85 ,
V_97 -> V_84 ,
V_97 -> V_85 ) ;
V_99 = 1 ;
}
return V_99 ;
}
static void F_86 ( struct V_101 * V_102 ,
T_2 * V_103 )
{
union V_104 V_105 ;
V_105 . V_102 = * V_102 ;
* V_103 = F_87 ( V_105 . V_106 ) ;
}
static void F_88 ( T_2 V_103 ,
struct V_101 * V_102 )
{
union V_104 V_105 ;
V_105 . V_106 = F_87 ( V_103 ) ;
* V_102 = V_105 . V_102 ;
}
static int F_89 ( struct V_61 * V_62 , T_2 V_28 , void * V_63 ,
void * * V_64 )
{
struct V_107 * V_108 ;
struct V_101 V_102 = {
. V_109 = V_110 ,
} ;
struct V_17 * V_18 = NULL ;
T_2 V_105 ;
T_1 V_111 ;
V_108 = (struct V_107 * ) V_62 -> V_68 ;
F_11 ( 0 , L_27 , V_108 -> V_69 ,
V_108 -> V_33 ) ;
if ( ! F_90 ( V_108 -> V_69 ) ) {
F_11 ( 0 , L_28 ,
V_108 -> V_69 ) ;
V_102 . V_109 = V_110 ;
goto V_112;
}
V_102 . V_109 = V_113 ;
F_26 ( & V_37 ) ;
V_18 = F_30 ( V_108 -> V_33 , V_108 -> V_114 ) ;
if ( ! V_18 )
goto V_115;
V_111 = 0 ;
while ( V_111 < V_76 ) {
if ( F_4 ( V_111 , V_18 -> V_75 ) ) {
if ( ! F_2 ( V_111 , V_108 -> V_116 ) ) {
F_11 ( 0 , L_29
L_30 ,
V_108 -> V_69 , V_111 ) ;
V_102 . V_109 = V_110 ;
goto V_115;
}
}
V_111 ++ ;
}
if ( V_18 && V_18 -> V_39 != V_73 ) {
int V_117 = V_108 -> V_69 ;
F_26 ( & V_18 -> V_24 ) ;
if ( V_18 -> V_39 == V_118 &&
V_18 -> V_59 == V_60 ) {
V_102 . V_109 = V_113 ;
} else if ( V_18 -> V_59 != V_60 ) {
V_102 . V_109 = V_110 ;
} else if ( V_18 -> V_119 . V_31 & V_120 ) {
F_11 ( 0 , L_31
L_32 , V_117 ) ;
V_102 . V_109 = V_110 ;
} else if ( F_4 ( V_117 , V_18 -> V_121 ) ) {
F_11 ( 0 , L_33
L_34 , V_117 ) ;
V_102 . V_109 = V_110 ;
} else if ( F_4 ( V_117 , V_18 -> V_75 ) ) {
F_11 ( 0 , L_33
L_35 ,
V_117 ) ;
V_102 . V_109 = V_110 ;
} else {
if ( F_84 ( L_36 , V_117 ,
& V_18 -> V_83 ,
& V_108 -> V_122 ) ) {
V_102 . V_109 = V_123 ;
} else if ( F_84 ( L_37 , V_117 ,
& V_18 -> V_124 ,
& V_108 -> V_125 ) ) {
V_102 . V_109 = V_123 ;
} else {
V_102 . V_126 = V_108 -> V_122 . V_85 ;
V_102 . V_127 = V_108 -> V_125 . V_85 ;
V_102 . V_109 = V_128 ;
F_91 ( V_18 , V_108 -> V_69 ) ;
}
}
F_27 ( & V_18 -> V_24 ) ;
}
V_115:
F_27 ( & V_37 ) ;
V_112:
F_11 ( 0 , L_38 , V_102 . V_109 ) ;
F_86 ( & V_102 , & V_105 ) ;
return V_105 ;
}
static int F_92 ( struct V_61 * V_62 , T_2 V_28 , void * V_63 ,
void * * V_64 )
{
struct V_129 * assert ;
struct V_17 * V_18 = NULL ;
assert = (struct V_129 * ) V_62 -> V_68 ;
F_11 ( 0 , L_39 , assert -> V_69 ,
assert -> V_33 ) ;
F_26 ( & V_37 ) ;
V_18 = F_30 ( assert -> V_33 , assert -> V_114 ) ;
if ( V_18 ) {
F_26 ( & V_18 -> V_24 ) ;
F_39 ( V_18 -> V_59 != assert -> V_69 ) ;
F_62 ( assert -> V_69 , V_18 -> V_75 ) ;
F_69 ( assert -> V_69 , V_18 -> V_70 ) ;
F_91 ( V_18 , V_60 ) ;
F_66 ( V_74 L_40 ,
assert -> V_69 , V_18 -> V_27 ) ;
F_65 ( V_18 ) ;
F_70 ( V_18 , assert -> V_69 , 1 ) ;
F_27 ( & V_18 -> V_24 ) ;
}
F_27 ( & V_37 ) ;
return 0 ;
}
static int F_93 ( struct V_17 * V_18 ,
struct V_130 * V_131 ,
char * V_132 , int V_133 )
{
char * V_134 = V_131 -> V_135 ;
char * V_136 , * V_137 ;
int V_138 , V_10 , V_139 , V_140 ;
int V_78 = 0 ;
if ( ! F_94 () ) {
if ( V_131 -> V_141 ) {
F_11 ( V_82 , L_41
L_42 ,
V_131 -> V_142 , V_131 -> V_143 , V_18 -> V_80 ) ;
V_78 = - V_144 ;
}
goto V_145;
}
if ( F_94 () && ! V_131 -> V_141 ) {
F_11 ( V_82 , L_43
L_44 ,
V_131 -> V_142 , V_18 -> V_80 , V_131 -> V_143 ) ;
V_78 = - V_144 ;
goto V_145;
}
V_137 = V_134 ;
for ( V_10 = 0 ; V_10 < V_131 -> V_141 ; ++ V_10 ) {
F_11 ( 0 , L_45 , V_146 , V_137 ) ;
V_137 += V_146 ;
}
V_138 = F_95 ( V_147 , V_133 / V_146 ) ;
V_138 = F_96 ( V_132 , ( T_1 ) V_138 ) ;
V_136 = V_132 ;
for ( V_10 = 0 ; V_10 < V_138 ; ++ V_10 ) {
V_140 = 0 ;
V_137 = V_134 ;
for ( V_139 = 0 ; V_139 <= V_131 -> V_141 ; ++ V_139 ) {
if ( ! memcmp ( V_136 , V_137 , V_146 ) ) {
V_140 = 1 ;
break;
}
V_137 += V_146 ;
}
if ( ! V_140 ) {
V_78 = - V_144 ;
F_11 ( V_82 , L_46
L_47 ,
V_131 -> V_142 , V_146 , V_136 ,
V_18 -> V_80 , V_131 -> V_143 ) ;
goto V_145;
}
V_136 += V_146 ;
}
V_137 = V_134 ;
for ( V_10 = 0 ; V_10 < V_131 -> V_141 ; ++ V_10 ) {
V_140 = 0 ;
V_136 = V_132 ;
for ( V_139 = 0 ; V_139 < V_138 ; ++ V_139 ) {
if ( ! memcmp ( V_137 , V_136 , V_146 ) ) {
V_140 = 1 ;
break;
}
V_136 += V_146 ;
}
if ( ! V_140 ) {
V_78 = - V_144 ;
F_11 ( V_82 , L_46
L_48 ,
V_131 -> V_142 , V_146 , V_137 ,
V_131 -> V_143 , V_18 -> V_80 ) ;
goto V_145;
}
V_137 += V_146 ;
}
V_145:
return V_78 ;
}
static int F_97 ( struct V_17 * V_18 , unsigned long * V_116 )
{
struct V_130 * V_131 = NULL ;
int V_78 , V_38 = 0 , V_10 ;
char * V_148 ;
if ( F_67 ( V_116 , V_76 , 0 ) >= V_76 )
goto V_145;
V_131 = F_98 ( sizeof( struct V_130 ) , V_9 ) ;
if ( ! V_131 ) {
V_38 = - V_149 ;
F_99 ( V_38 ) ;
goto V_145;
}
V_131 -> V_143 = V_18 -> V_80 ;
V_131 -> V_150 = strlen ( V_18 -> V_27 ) ;
memcpy ( V_131 -> V_142 , V_18 -> V_27 , V_131 -> V_150 ) ;
if ( F_94 () )
V_131 -> V_141 = F_96 ( V_131 -> V_135 ,
V_147 ) ;
V_148 = V_131 -> V_135 ;
for ( V_10 = 0 ; V_10 < V_131 -> V_141 ; ++ V_10 , V_148 += V_146 )
F_11 ( 0 , L_45 , V_146 , V_148 ) ;
V_10 = - 1 ;
while ( ( V_10 = F_67 ( V_116 , V_76 ,
V_10 + 1 ) ) < V_76 ) {
if ( V_10 == V_18 -> V_80 )
continue;
F_11 ( 0 , L_49 , V_10 ) ;
V_38 = F_72 ( V_151 , V_152 , V_131 ,
sizeof( struct V_130 ) ,
V_10 , & V_78 ) ;
if ( V_38 >= 0 )
V_38 = V_78 ;
if ( V_38 ) {
F_11 ( V_82 , L_50 ,
V_38 , V_10 ) ;
break;
}
}
V_145:
F_7 ( V_131 ) ;
return V_38 ;
}
static int F_100 ( struct V_61 * V_62 , T_2 V_28 ,
void * V_63 , void * * V_64 )
{
struct V_130 * V_131 ;
struct V_17 * V_18 = NULL ;
char * V_132 = NULL ;
int V_78 = 0 ;
int V_153 = 0 ;
V_131 = (struct V_130 * ) V_62 -> V_68 ;
F_11 ( 0 , L_51 , V_131 -> V_143 ,
V_131 -> V_142 ) ;
V_132 = F_9 ( sizeof( V_131 -> V_135 ) , V_9 ) ;
if ( ! V_132 ) {
V_78 = - V_149 ;
goto V_145;
}
V_78 = - V_144 ;
F_26 ( & V_37 ) ;
V_18 = F_30 ( V_131 -> V_142 , V_131 -> V_150 ) ;
if ( ! V_18 ) {
F_11 ( V_82 , L_52
L_53 , V_131 -> V_143 , V_131 -> V_142 ) ;
goto V_145;
}
F_26 ( & V_18 -> V_24 ) ;
V_153 = 1 ;
if ( V_18 -> V_59 != V_131 -> V_143 ) {
F_11 ( V_82 , L_52
L_54 , V_131 -> V_143 , V_131 -> V_142 ,
V_18 -> V_59 ) ;
goto V_145;
}
if ( V_18 -> V_83 . V_84 == 1 &&
V_18 -> V_83 . V_85 == 0 ) {
F_11 ( V_82 , L_52
L_55 , V_131 -> V_143 ,
V_131 -> V_142 , V_18 -> V_83 . V_84 ,
V_18 -> V_83 . V_85 ) ;
goto V_145;
}
V_78 = F_93 ( V_18 , V_131 , V_132 , sizeof( V_131 -> V_135 ) ) ;
V_145:
if ( V_153 )
F_27 ( & V_18 -> V_24 ) ;
F_27 ( & V_37 ) ;
F_7 ( V_132 ) ;
return V_78 ;
}
static int F_101 ( struct V_17 * V_18 , struct V_154 * V_155 )
{
struct V_156 * V_132 ;
struct V_157 * V_134 ;
int V_10 , V_139 ;
int V_78 = 0 ;
for ( V_139 = 0 ; V_139 < V_155 -> V_158 ; ++ V_139 )
F_11 ( 0 , L_56 , V_155 -> V_159 [ V_139 ] . V_160 ,
& ( V_155 -> V_159 [ V_139 ] . V_161 ) ,
F_102 ( V_155 -> V_159 [ V_139 ] . V_162 ) ) ;
for ( V_10 = 0 ; V_10 < V_76 && ! V_78 ; ++ V_10 ) {
V_132 = F_103 ( V_10 ) ;
V_134 = NULL ;
for ( V_139 = 0 ; V_139 < V_155 -> V_158 ; ++ V_139 ) {
if ( V_155 -> V_159 [ V_139 ] . V_160 == V_10 ) {
V_134 = & ( V_155 -> V_159 [ V_139 ] ) ;
break;
}
}
if ( ! V_132 && ! V_134 )
continue;
if ( ( V_132 && ! V_134 ) || ( ! V_132 && V_134 ) )
V_78 = - V_144 ;
if ( ! V_78 &&
( ( V_134 -> V_160 != V_132 -> V_163 ) ||
( V_134 -> V_162 != V_132 -> V_164 ) ||
( V_134 -> V_161 != V_132 -> V_165 ) ) )
V_78 = - V_144 ;
if ( V_78 ) {
if ( V_134 && ! V_132 )
F_11 ( V_82 , L_57
L_58
L_59 , V_155 -> V_166 ,
V_134 -> V_160 ,
& ( V_134 -> V_161 ) ,
F_102 ( V_134 -> V_162 ) ,
V_155 -> V_167 , V_18 -> V_80 ) ;
if ( V_132 && ! V_134 )
F_11 ( V_82 , L_57
L_60
L_61 , V_155 -> V_166 ,
V_132 -> V_163 , & ( V_132 -> V_165 ) ,
F_102 ( V_132 -> V_164 ) ,
V_18 -> V_80 , V_155 -> V_167 ) ;
F_39 ( ( ! V_132 && ! V_134 ) ) ;
}
if ( V_132 )
F_104 ( V_132 ) ;
}
return V_78 ;
}
static int F_105 ( struct V_17 * V_18 , unsigned long * V_116 )
{
struct V_154 * V_155 = NULL ;
struct V_156 * V_65 ;
int V_38 = 0 , V_78 , V_168 , V_10 ;
if ( F_67 ( V_116 , V_76 , 0 ) >= V_76 )
goto V_145;
V_155 = F_98 ( sizeof( struct V_154 ) , V_9 ) ;
if ( ! V_155 ) {
V_38 = - V_149 ;
F_99 ( V_38 ) ;
goto V_145;
}
for ( V_10 = 0 , V_168 = 0 ; V_10 < V_76 ; ++ V_10 ) {
V_65 = F_103 ( V_10 ) ;
if ( ! V_65 )
continue;
V_155 -> V_159 [ V_168 ] . V_160 = V_65 -> V_163 ;
V_155 -> V_159 [ V_168 ] . V_162 = V_65 -> V_164 ;
V_155 -> V_159 [ V_168 ] . V_161 = V_65 -> V_165 ;
F_11 ( 0 , L_56 , V_65 -> V_163 ,
& ( V_65 -> V_165 ) , F_102 ( V_65 -> V_164 ) ) ;
++ V_168 ;
F_104 ( V_65 ) ;
}
V_155 -> V_167 = V_18 -> V_80 ;
V_155 -> V_158 = V_168 ;
V_155 -> V_169 = strlen ( V_18 -> V_27 ) ;
memcpy ( V_155 -> V_166 , V_18 -> V_27 , V_155 -> V_169 ) ;
V_10 = - 1 ;
while ( ( V_10 = F_67 ( V_116 , V_76 ,
V_10 + 1 ) ) < V_76 ) {
if ( V_10 == V_18 -> V_80 )
continue;
F_11 ( 0 , L_62 , V_10 ) ;
V_38 = F_72 ( V_170 , V_152 ,
V_155 , sizeof( struct V_154 ) ,
V_10 , & V_78 ) ;
if ( V_38 >= 0 )
V_38 = V_78 ;
if ( V_38 ) {
F_11 ( V_82 , L_63 , V_38 , V_10 ) ;
break;
}
}
V_145:
F_7 ( V_155 ) ;
return V_38 ;
}
static int F_106 ( struct V_61 * V_62 , T_2 V_28 ,
void * V_63 , void * * V_64 )
{
struct V_154 * V_155 ;
struct V_17 * V_18 = NULL ;
int V_153 = 0 , V_78 = - V_144 ;
V_155 = (struct V_154 * ) V_62 -> V_68 ;
F_11 ( 0 , L_64 , V_155 -> V_167 ,
V_155 -> V_166 ) ;
F_26 ( & V_37 ) ;
V_18 = F_30 ( V_155 -> V_166 , V_155 -> V_169 ) ;
if ( ! V_18 ) {
F_11 ( V_82 , L_65
L_66 , V_155 -> V_167 , V_155 -> V_166 ) ;
goto V_145;
}
F_26 ( & V_18 -> V_24 ) ;
V_153 = 1 ;
if ( V_18 -> V_59 != V_155 -> V_167 ) {
F_11 ( V_82 , L_67
L_68 , V_155 -> V_167 , V_155 -> V_166 ,
V_18 -> V_59 ) ;
goto V_145;
}
if ( V_18 -> V_83 . V_84 == 1 &&
V_18 -> V_83 . V_85 == 0 ) {
F_11 ( V_82 , L_69
L_55 , V_155 -> V_167 ,
V_155 -> V_166 , V_18 -> V_83 . V_84 ,
V_18 -> V_83 . V_85 ) ;
goto V_145;
}
V_78 = F_101 ( V_18 , V_155 ) ;
V_145:
if ( V_153 )
F_27 ( & V_18 -> V_24 ) ;
F_27 ( & V_37 ) ;
return V_78 ;
}
static int F_107 ( struct V_61 * V_62 , T_2 V_28 , void * V_63 ,
void * * V_64 )
{
struct V_171 * V_172 ;
struct V_17 * V_18 = NULL ;
V_172 = (struct V_171 * ) V_62 -> V_68 ;
F_11 ( 0 , L_70 , V_172 -> V_69 ,
V_172 -> V_33 ) ;
F_26 ( & V_37 ) ;
V_18 = F_30 ( V_172 -> V_33 , V_172 -> V_114 ) ;
if ( V_18 ) {
F_26 ( & V_18 -> V_24 ) ;
F_39 ( V_18 -> V_59 != V_172 -> V_69 ) ;
F_91 ( V_18 , V_60 ) ;
F_27 ( & V_18 -> V_24 ) ;
}
F_27 ( & V_37 ) ;
return 0 ;
}
static int F_108 ( struct V_17 * V_18 ,
unsigned int V_65 )
{
int V_78 ;
struct V_171 V_173 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_173 . V_69 = V_18 -> V_80 ;
V_173 . V_114 = strlen ( V_18 -> V_27 ) ;
memcpy ( V_173 . V_33 , V_18 -> V_27 , V_173 . V_114 ) ;
V_78 = F_72 ( V_174 , V_152 ,
& V_173 , sizeof( V_173 ) , V_65 ,
NULL ) ;
if ( V_78 < 0 ) {
F_11 ( V_82 , L_71
L_72 , V_78 , V_174 , V_152 ,
V_65 ) ;
goto V_145;
}
V_145:
return V_78 ;
}
static int F_109 ( struct V_17 * V_18 ,
unsigned long * V_116 ,
unsigned int V_175 )
{
int V_78 , V_176 ;
unsigned int V_65 ;
if ( V_175 != ( F_110 ( V_76 ) *
sizeof( unsigned long ) ) ) {
F_11 ( V_82 ,
L_73 ,
V_175 , ( unsigned ) F_110 ( V_76 ) ) ;
return - V_144 ;
}
V_78 = 0 ;
V_65 = - 1 ;
while ( ( V_65 = F_67 ( V_116 , V_76 ,
V_65 + 1 ) ) < V_76 ) {
if ( V_65 == V_18 -> V_80 )
continue;
V_176 = F_108 ( V_18 , V_65 ) ;
if ( V_176 ) {
F_11 ( V_82 , L_74
L_75 , V_176 , V_65 ) ;
if ( ! V_78 )
V_78 = V_176 ;
}
}
if ( V_78 )
F_99 ( V_78 ) ;
return V_78 ;
}
static int F_111 ( struct V_17 * V_18 ,
int V_65 ,
enum V_177 * V_105 )
{
int V_78 ;
struct V_107 V_178 ;
struct V_101 V_102 ;
T_2 V_179 ;
F_11 ( 0 , L_76 , V_65 ) ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_178 . V_69 = V_18 -> V_80 ;
V_178 . V_114 = strlen ( V_18 -> V_27 ) ;
memcpy ( V_178 . V_33 , V_18 -> V_27 , V_178 . V_114 ) ;
V_178 . V_122 = V_18 -> V_83 ;
V_178 . V_125 = V_18 -> V_124 ;
F_3 ( V_178 . V_116 , V_18 -> V_180 , V_76 ) ;
V_78 = F_72 ( V_181 , V_152 , & V_178 ,
sizeof( V_178 ) , V_65 , & V_179 ) ;
if ( V_78 < 0 && V_78 != - V_89 ) {
F_11 ( V_82 , L_71
L_72 , V_78 , V_181 , V_152 ,
V_65 ) ;
goto V_145;
}
F_88 ( V_179 , & V_102 ) ;
if ( V_78 == - V_89 ) {
V_78 = 0 ;
* V_105 = V_113 ;
} else if ( V_102 . V_109 == V_110 ||
V_102 . V_109 == V_113 ) {
* V_105 = V_102 . V_109 ;
} else if ( V_102 . V_109 == V_123 ) {
F_11 ( V_91 ,
L_77
L_78
L_79
L_80 ,
V_18 -> V_83 . V_84 ,
V_18 -> V_83 . V_85 ,
V_18 -> V_124 . V_84 ,
V_18 -> V_124 . V_85 ,
V_65 ) ;
V_78 = - V_182 ;
* V_105 = V_102 . V_109 ;
} else if ( V_102 . V_109 == V_128 ) {
* V_105 = V_102 . V_109 ;
V_18 -> V_83 . V_85 = V_102 . V_126 ;
V_18 -> V_124 . V_85 = V_102 . V_127 ;
F_11 ( 0 ,
L_81
L_82 ,
V_65 ,
V_18 -> V_83 . V_84 ,
V_18 -> V_83 . V_85 ,
V_18 -> V_124 . V_84 ,
V_18 -> V_124 . V_85 ) ;
} else {
V_78 = - V_144 ;
F_11 ( V_82 , L_83 ,
V_102 . V_109 , V_65 ) ;
}
F_11 ( 0 , L_84 , V_78 , V_65 ,
* V_105 ) ;
V_145:
return V_78 ;
}
static int F_112 ( struct V_17 * V_18 ,
unsigned int V_65 )
{
int V_78 ;
struct V_129 V_183 ;
F_11 ( 0 , L_85 , V_65 ) ;
memset ( & V_183 , 0 , sizeof( V_183 ) ) ;
V_183 . V_69 = V_18 -> V_80 ;
V_183 . V_114 = strlen ( V_18 -> V_27 ) ;
memcpy ( V_183 . V_33 , V_18 -> V_27 , V_183 . V_114 ) ;
V_78 = F_72 ( V_184 , V_152 ,
& V_183 , sizeof( V_183 ) , V_65 ,
NULL ) ;
if ( V_78 < 0 )
F_11 ( V_82 , L_71
L_72 , V_78 , V_184 , V_152 ,
V_65 ) ;
return V_78 ;
}
static void F_113 ( struct V_17 * V_18 ,
unsigned long * V_116 )
{
int V_78 , V_65 , V_185 ;
V_78 = 0 ;
V_65 = - 1 ;
while ( ( V_65 = F_67 ( V_116 , V_76 ,
V_65 + 1 ) ) < V_76 ) {
if ( V_65 == V_18 -> V_80 )
continue;
do {
V_78 = F_112 ( V_18 , V_65 ) ;
F_26 ( & V_18 -> V_24 ) ;
V_185 = F_4 ( V_65 , V_18 -> V_180 ) ;
F_27 ( & V_18 -> V_24 ) ;
if ( V_78 ) {
F_11 ( V_82 , L_86
L_87 , V_78 , V_65 ) ;
if ( V_185 )
F_75 ( V_92 ) ;
}
} while ( V_78 && V_185 );
}
}
static int F_114 ( struct V_17 * V_18 ,
struct V_186 * V_187 ,
enum V_177 V_105 )
{
int V_38 ;
if ( V_105 == V_110 ) {
F_11 ( 0 , L_88 ) ;
return 1 ;
}
F_26 ( & V_18 -> V_24 ) ;
V_38 = memcmp ( V_187 -> V_188 , V_18 -> V_180 ,
sizeof( V_18 -> V_180 ) ) ;
F_27 ( & V_18 -> V_24 ) ;
if ( V_38 )
F_11 ( 0 , L_89 ) ;
return V_38 ;
}
static int F_115 ( struct V_17 * V_18 )
{
int V_78 = 0 , V_176 , V_65 ;
struct V_186 * V_187 ;
enum V_177 V_105 = V_110 ;
F_11 ( 0 , L_90 , V_18 ) ;
V_187 = F_98 ( sizeof( * V_187 ) , V_9 ) ;
if ( ! V_187 ) {
V_78 = - V_149 ;
F_99 ( V_78 ) ;
goto V_145;
}
F_116 ( V_18 -> V_180 , sizeof( V_18 -> V_180 ) ) ;
F_26 ( & V_18 -> V_24 ) ;
memcpy ( V_187 -> V_188 , V_18 -> V_180 , sizeof( V_187 -> V_188 ) ) ;
F_91 ( V_18 , V_18 -> V_80 ) ;
F_27 ( & V_18 -> V_24 ) ;
V_65 = - 1 ;
while ( ( V_65 = F_67 ( V_187 -> V_188 , V_76 ,
V_65 + 1 ) ) < V_76 ) {
if ( V_65 == V_18 -> V_80 )
continue;
V_78 = F_111 ( V_18 , V_65 , & V_105 ) ;
if ( V_78 < 0 ) {
F_99 ( V_78 ) ;
goto V_145;
}
if ( V_105 == V_128 )
F_62 ( V_65 , V_187 -> V_189 ) ;
if ( F_114 ( V_18 , V_187 , V_105 ) ) {
V_78 = - V_58 ;
goto V_145;
}
}
F_11 ( 0 , L_91 ) ;
F_26 ( & V_18 -> V_24 ) ;
memcpy ( V_18 -> V_75 , V_187 -> V_189 ,
sizeof( V_187 -> V_189 ) ) ;
F_62 ( V_18 -> V_80 , V_18 -> V_75 ) ;
F_27 ( & V_18 -> V_24 ) ;
if ( V_18 -> V_83 . V_84 > 1 ||
V_18 -> V_83 . V_85 > 0 ) {
V_78 = F_105 ( V_18 , V_187 -> V_189 ) ;
if ( V_78 ) {
F_99 ( V_78 ) ;
goto V_145;
}
V_78 = F_97 ( V_18 , V_187 -> V_189 ) ;
if ( V_78 ) {
F_99 ( V_78 ) ;
goto V_145;
}
}
F_113 ( V_18 , V_187 -> V_189 ) ;
F_26 ( & V_37 ) ;
V_18 -> V_39 = V_40 ;
V_18 -> V_45 ++ ;
F_27 ( & V_37 ) ;
V_145:
F_26 ( & V_18 -> V_24 ) ;
F_91 ( V_18 , V_60 ) ;
if ( ! V_78 )
F_65 ( V_18 ) ;
F_27 ( & V_18 -> V_24 ) ;
if ( V_187 ) {
if ( V_78 < 0 ) {
V_176 = F_109 ( V_18 ,
V_187 -> V_189 ,
sizeof( V_187 -> V_189 ) ) ;
if ( V_176 < 0 )
F_99 ( V_176 ) ;
}
F_7 ( V_187 ) ;
}
F_11 ( 0 , L_92 , V_78 ) ;
return V_78 ;
}
static void F_52 ( struct V_17 * V_18 )
{
F_117 ( V_18 -> V_27 , & V_18 -> V_190 ) ;
F_117 ( V_18 -> V_27 , & V_18 -> V_191 ) ;
F_118 ( & V_18 -> V_192 ) ;
}
static int F_119 ( struct V_17 * V_18 )
{
int V_78 ;
F_11 ( 0 , L_93 ) ;
F_120 ( & V_18 -> V_191 , V_193 ,
V_194 , V_18 , V_195 ) ;
V_78 = F_121 ( V_18 -> V_27 , & V_18 -> V_191 ) ;
if ( V_78 )
goto V_145;
F_120 ( & V_18 -> V_190 , V_196 ,
V_197 , V_18 , V_198 ) ;
V_78 = F_121 ( V_18 -> V_27 , & V_18 -> V_190 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_199 , V_18 -> V_81 ,
sizeof( struct V_200 ) ,
V_201 ,
V_18 , NULL , & V_18 -> V_192 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_202 , V_18 -> V_81 ,
sizeof( struct V_203 ) ,
V_204 ,
V_18 , V_205 ,
& V_18 -> V_192 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_206 , V_18 -> V_81 ,
sizeof( struct V_207 ) ,
V_208 ,
V_18 , NULL , & V_18 -> V_192 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_209 , V_18 -> V_81 ,
V_210 ,
V_211 ,
V_18 , NULL , & V_18 -> V_192 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_212 , V_18 -> V_81 ,
V_213 ,
V_214 ,
V_18 , NULL , & V_18 -> V_192 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_215 , V_18 -> V_81 ,
V_216 ,
V_217 ,
V_18 , NULL , & V_18 -> V_192 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_88 , V_18 -> V_81 ,
sizeof( struct V_66 ) ,
F_68 ,
V_18 , NULL , & V_18 -> V_192 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_218 , V_18 -> V_81 ,
sizeof( struct V_219 ) ,
V_220 ,
V_18 , NULL , & V_18 -> V_192 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_221 , V_18 -> V_81 ,
sizeof( struct V_222 ) ,
V_223 ,
V_18 , NULL , & V_18 -> V_192 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_224 , V_18 -> V_81 ,
V_225 ,
V_226 ,
V_18 , NULL , & V_18 -> V_192 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_227 , V_18 -> V_81 ,
sizeof( struct V_228 ) ,
V_229 ,
V_18 , NULL , & V_18 -> V_192 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_230 , V_18 -> V_81 ,
sizeof( struct V_231 ) ,
V_232 ,
V_18 , NULL , & V_18 -> V_192 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_233 , V_18 -> V_81 ,
sizeof( struct V_234 ) ,
V_235 ,
V_18 , NULL , & V_18 -> V_192 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_236 , V_18 -> V_81 ,
sizeof( struct V_237 ) ,
V_238 ,
V_18 , NULL , & V_18 -> V_192 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_239 , V_18 -> V_81 ,
sizeof( struct V_240 ) ,
V_241 ,
V_18 , NULL , & V_18 -> V_192 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_86 , V_18 -> V_81 ,
sizeof( struct V_66 ) ,
F_61 ,
V_18 , NULL , & V_18 -> V_192 ) ;
if ( V_78 )
goto V_145;
V_145:
if ( V_78 )
F_52 ( V_18 ) ;
return V_78 ;
}
static int F_123 ( struct V_17 * V_18 )
{
int V_78 ;
unsigned int V_242 ;
unsigned int V_243 = 0 ;
F_39 ( ! V_18 ) ;
F_11 ( 0 , L_94 , V_18 -> V_27 ) ;
V_78 = F_119 ( V_18 ) ;
if ( V_78 ) {
F_99 ( V_78 ) ;
goto V_145;
}
V_78 = F_124 ( V_18 ) ;
if ( V_78 < 0 ) {
F_99 ( V_78 ) ;
goto V_145;
}
V_78 = F_125 ( V_18 ) ;
if ( V_78 < 0 ) {
F_99 ( V_78 ) ;
goto V_145;
}
V_78 = F_126 ( V_18 ) ;
if ( V_78 < 0 ) {
F_99 ( V_78 ) ;
goto V_145;
}
V_18 -> V_49 = F_127 ( L_95 ) ;
if ( ! V_18 -> V_49 ) {
V_78 = - V_149 ;
F_99 ( V_78 ) ;
goto V_145;
}
do {
V_78 = F_115 ( V_18 ) ;
#define F_128 90000
if ( V_78 == - V_58 ) {
if ( F_129 ( V_244 ) ) {
V_78 = - V_245 ;
goto V_145;
}
if ( V_243 >
F_130 ( F_128 ) ) {
V_78 = - V_245 ;
F_11 ( V_91 , L_96
L_97 , V_18 -> V_27 ,
F_131 ( V_243 ) ) ;
goto V_145;
}
V_242 = ( unsigned int ) ( V_246 & 0x3 ) ;
V_242 *= V_92 ;
V_243 += V_242 ;
F_11 ( 0 , L_98 , V_242 ) ;
F_75 ( V_242 ) ;
}
} while ( V_78 == - V_58 );
if ( V_78 < 0 ) {
F_99 ( V_78 ) ;
goto V_145;
}
V_78 = 0 ;
V_145:
F_41 ( & V_46 ) ;
if ( V_78 ) {
F_52 ( V_18 ) ;
F_53 ( V_18 ) ;
F_54 ( V_18 ) ;
F_55 ( V_18 ) ;
F_48 ( V_18 ) ;
}
return V_78 ;
}
static struct V_17 * F_132 ( const char * V_33 ,
T_2 V_81 )
{
int V_10 ;
int V_38 ;
struct V_17 * V_18 = NULL ;
V_18 = F_98 ( sizeof( * V_18 ) , V_9 ) ;
if ( ! V_18 ) {
F_99 ( - V_149 ) ;
goto V_93;
}
V_18 -> V_27 = F_133 ( V_33 , V_9 ) ;
if ( V_18 -> V_27 == NULL ) {
F_99 ( - V_149 ) ;
F_7 ( V_18 ) ;
V_18 = NULL ;
goto V_93;
}
V_18 -> V_41 = (struct V_20 * * ) F_8 ( V_12 ) ;
if ( ! V_18 -> V_41 ) {
F_99 ( - V_149 ) ;
F_7 ( V_18 -> V_27 ) ;
F_7 ( V_18 ) ;
V_18 = NULL ;
goto V_93;
}
for ( V_10 = 0 ; V_10 < V_53 ; V_10 ++ )
F_134 ( F_18 ( V_18 , V_10 ) ) ;
V_18 -> V_42 = (struct V_20 * * )
F_8 ( V_12 ) ;
if ( ! V_18 -> V_42 ) {
F_99 ( - V_149 ) ;
F_5 ( ( void * * ) V_18 -> V_41 , V_12 ) ;
F_7 ( V_18 -> V_27 ) ;
F_7 ( V_18 ) ;
V_18 = NULL ;
goto V_93;
}
for ( V_10 = 0 ; V_10 < V_53 ; V_10 ++ )
F_134 ( F_135 ( V_18 , V_10 ) ) ;
V_18 -> V_81 = V_81 ;
V_18 -> V_80 = F_136 () ;
V_38 = F_137 ( V_18 ) ;
if ( V_38 < 0 ) {
F_5 ( ( void * * ) V_18 -> V_42 , V_12 ) ;
F_5 ( ( void * * ) V_18 -> V_41 , V_12 ) ;
F_7 ( V_18 -> V_27 ) ;
F_7 ( V_18 ) ;
V_18 = NULL ;
goto V_93;
}
F_138 ( & V_18 -> V_24 ) ;
F_138 ( & V_18 -> V_247 ) ;
F_138 ( & V_18 -> V_248 ) ;
F_138 ( & V_18 -> V_249 ) ;
F_139 ( & V_18 -> V_30 ) ;
F_139 ( & V_18 -> V_250 ) ;
F_139 ( & V_18 -> V_119 . V_251 ) ;
F_139 ( & V_18 -> V_119 . V_252 ) ;
F_139 ( & V_18 -> V_119 . V_253 ) ;
F_139 ( & V_18 -> V_254 ) ;
F_139 ( & V_18 -> V_192 ) ;
F_139 ( & V_18 -> V_94 ) ;
V_18 -> V_119 . V_31 = 0 ;
F_139 ( & V_18 -> V_255 ) ;
F_139 ( & V_18 -> V_256 ) ;
F_11 ( 0 , L_99 ,
V_18 -> V_121 , & ( V_18 -> V_121 [ 0 ] ) ) ;
memset ( V_18 -> V_121 , 0 , sizeof( V_18 -> V_121 ) ) ;
memset ( V_18 -> V_180 , 0 , sizeof( V_18 -> V_180 ) ) ;
memset ( V_18 -> V_75 , 0 , sizeof( V_18 -> V_75 ) ) ;
V_18 -> V_257 = NULL ;
V_18 -> V_258 = NULL ;
V_18 -> V_49 = NULL ;
F_140 ( & V_18 -> V_57 ) ;
F_140 ( & V_18 -> V_259 ) ;
F_140 ( & V_18 -> V_119 . V_260 ) ;
F_140 ( & V_18 -> V_261 ) ;
F_140 ( & V_18 -> V_262 ) ;
F_139 ( & V_18 -> V_263 ) ;
V_18 -> V_59 = V_60 ;
F_140 ( & V_18 -> V_72 ) ;
V_18 -> V_119 . V_264 = V_265 ;
V_18 -> V_119 . V_266 = V_265 ;
F_141 ( & V_18 -> V_267 , 0 ) ;
F_141 ( & V_18 -> V_268 , 0 ) ;
for ( V_10 = 0 ; V_10 < V_269 ; ++ V_10 ) {
F_141 ( & V_18 -> V_270 [ V_10 ] , 0 ) ;
F_141 ( & V_18 -> V_271 [ V_10 ] , 0 ) ;
}
F_138 ( & V_18 -> V_272 ) ;
F_139 ( & V_18 -> V_273 ) ;
F_142 ( & V_18 -> V_274 , V_275 ) ;
F_143 ( & V_18 -> V_44 ) ;
V_18 -> V_39 = V_118 ;
F_139 ( & V_18 -> V_276 ) ;
F_11 ( 0 , L_100 ,
F_144 ( & V_18 -> V_44 . V_277 ) ) ;
V_93:
return V_18 ;
}
static int F_85 ( struct V_96 * V_278 ,
struct V_96 * V_98 )
{
if ( V_278 -> V_84 != V_98 -> V_84 )
return 1 ;
if ( V_278 -> V_85 > V_98 -> V_85 )
return 1 ;
if ( V_278 -> V_85 < V_98 -> V_85 )
V_98 -> V_85 = V_278 -> V_85 ;
return 0 ;
}
struct V_17 * F_145 ( const char * V_33 ,
T_2 V_81 ,
struct V_96 * V_125 )
{
int V_38 ;
struct V_17 * V_18 = NULL ;
struct V_17 * V_279 = NULL ;
if ( strlen ( V_33 ) >= V_280 ) {
V_38 = - V_281 ;
F_11 ( V_82 , L_101 ) ;
goto V_93;
}
if ( ! F_146 () ) {
F_11 ( V_82 , L_102
L_103 ) ;
V_38 = - V_182 ;
goto V_93;
}
F_11 ( 0 , L_104 , V_33 ) ;
V_282:
V_18 = NULL ;
if ( F_129 ( V_244 ) ) {
V_38 = - V_245 ;
F_99 ( V_38 ) ;
goto V_93;
}
F_26 ( & V_37 ) ;
V_18 = F_33 ( V_33 ) ;
if ( V_18 ) {
if ( V_18 -> V_39 != V_40 ) {
F_27 ( & V_37 ) ;
F_11 ( 0 , L_105 ) ;
F_147 ( V_46 ,
F_34 (
V_33 ) ) ;
goto V_282;
}
if ( F_85 ( & V_18 -> V_124 , V_125 ) ) {
F_27 ( & V_37 ) ;
F_11 ( V_82 ,
L_106
L_107
L_108 , V_33 ) ;
V_38 = - V_182 ;
goto V_93;
}
F_44 ( V_18 ) ;
V_18 -> V_45 ++ ;
F_27 ( & V_37 ) ;
V_38 = 0 ;
goto V_93;
}
if ( ! V_279 ) {
F_27 ( & V_37 ) ;
V_279 = F_132 ( V_33 , V_81 ) ;
if ( V_279 )
goto V_282;
V_38 = - V_149 ;
F_99 ( V_38 ) ;
goto V_93;
}
V_18 = V_279 ;
V_279 = NULL ;
F_148 ( & V_18 -> V_30 , & V_283 ) ;
F_27 ( & V_37 ) ;
V_18 -> V_83 = V_284 ;
V_18 -> V_124 = * V_125 ;
V_38 = F_123 ( V_18 ) ;
if ( V_38 ) {
F_99 ( V_38 ) ;
F_42 ( V_18 ) ;
goto V_93;
}
* V_125 = V_18 -> V_124 ;
V_38 = 0 ;
V_93:
if ( V_279 )
F_35 ( V_279 ) ;
if ( V_38 < 0 )
V_18 = F_149 ( V_38 ) ;
return V_18 ;
}
static void F_150 ( void )
{
F_118 ( & V_285 ) ;
}
static int F_151 ( void )
{
int V_78 = 0 ;
V_78 = F_122 ( V_181 , V_152 ,
sizeof( struct V_107 ) ,
F_89 ,
NULL , NULL , & V_285 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_184 , V_152 ,
sizeof( struct V_129 ) ,
F_92 ,
NULL , NULL , & V_285 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_174 , V_152 ,
sizeof( struct V_171 ) ,
F_107 ,
NULL , NULL , & V_285 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_151 , V_152 ,
sizeof( struct V_130 ) ,
F_100 ,
NULL , NULL , & V_285 ) ;
if ( V_78 )
goto V_145;
V_78 = F_122 ( V_170 , V_152 ,
sizeof( struct V_154 ) ,
F_106 ,
NULL , NULL , & V_285 ) ;
V_145:
if ( V_78 < 0 )
F_150 () ;
return V_78 ;
}
void F_152 ( struct V_17 * V_18 ,
int V_80 )
{
struct V_35 * V_36 ;
struct V_286 * V_287 ;
F_153 ( & V_288 ) ;
F_31 (iter, &dlm->dlm_eviction_callbacks) {
V_287 = F_32 ( V_36 , struct V_286 , V_289 ) ;
V_287 -> V_290 ( V_80 , V_287 -> V_291 ) ;
}
F_154 ( & V_288 ) ;
}
void F_155 ( struct V_286 * V_287 ,
T_3 * V_292 ,
void * V_63 )
{
F_139 ( & V_287 -> V_289 ) ;
V_287 -> V_290 = V_292 ;
V_287 -> V_291 = V_63 ;
}
void F_156 ( struct V_17 * V_18 ,
struct V_286 * V_287 )
{
F_157 ( & V_288 ) ;
F_148 ( & V_287 -> V_289 , & V_18 -> V_276 ) ;
F_158 ( & V_288 ) ;
}
void F_159 ( struct V_286 * V_287 )
{
F_157 ( & V_288 ) ;
F_40 ( & V_287 -> V_289 ) ;
F_158 ( & V_288 ) ;
}
static int T_4 F_160 ( void )
{
int V_78 ;
F_161 () ;
V_78 = F_162 () ;
if ( V_78 ) {
F_11 ( V_82 , L_109 ) ;
goto error;
}
V_78 = F_163 () ;
if ( V_78 ) {
F_11 ( V_82 , L_110
L_111 ) ;
goto error;
}
V_78 = F_164 () ;
if ( V_78 ) {
F_11 ( V_82 , L_112 ) ;
goto error;
}
V_78 = F_151 () ;
if ( V_78 ) {
F_11 ( V_82 , L_113 ) ;
goto error;
}
V_78 = F_165 () ;
if ( V_78 )
goto error;
return 0 ;
error:
F_150 () ;
F_166 () ;
F_167 () ;
F_168 () ;
return - 1 ;
}
static void T_5 F_169 ( void )
{
F_170 () ;
F_150 () ;
F_166 () ;
F_167 () ;
F_168 () ;
}
