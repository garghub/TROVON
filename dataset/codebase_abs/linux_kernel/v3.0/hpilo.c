static inline int F_1 ( int V_1 )
{
return ( V_1 & V_2 ) >> V_3 ;
}
static inline int F_2 ( int V_1 )
{
return ( ( V_1 & V_4 ) >> V_5 ) << 3 ;
}
static inline int F_3 ( int V_6 , int V_7 )
{
int V_8 = V_7 & 7 ? ( V_7 >> 3 ) + 1 : V_7 >> 3 ;
return V_6 << V_3 | V_8 << V_5 ;
}
static inline int F_4 ( int V_9 )
{
return V_9 << V_10 ;
}
static int F_5 ( struct V_11 * V_12 , char * V_13 , int V_1 )
{
struct V_14 * V_15 = F_6 ( V_13 ) ;
unsigned long V_16 ;
int V_17 = 0 ;
F_7 ( & V_12 -> V_18 , V_16 ) ;
if ( ! ( V_15 -> V_13 [ ( V_15 -> V_19 + 1 ) & V_15 -> V_20 ]
& V_21 ) ) {
V_15 -> V_13 [ V_15 -> V_19 & V_15 -> V_20 ] |=
( V_1 & V_22 ) | V_15 -> V_23 ;
V_15 -> V_19 += 1 ;
V_17 = 1 ;
}
F_8 ( & V_12 -> V_18 , V_16 ) ;
return V_17 ;
}
static int F_9 ( struct V_11 * V_12 , char * V_13 , int * V_1 )
{
struct V_14 * V_15 = F_6 ( V_13 ) ;
unsigned long V_16 ;
int V_17 = 0 ;
T_1 V_24 ;
F_7 ( & V_12 -> V_18 , V_16 ) ;
V_24 = V_15 -> V_13 [ V_15 -> V_25 & V_15 -> V_20 ] ;
if ( V_24 & V_26 ) {
if ( V_1 )
* V_1 = V_24 & V_22 ;
V_15 -> V_13 [ V_15 -> V_25 & V_15 -> V_20 ] =
( V_24 | V_27 ) + 1 ;
V_15 -> V_25 += 1 ;
V_17 = 1 ;
}
F_8 ( & V_12 -> V_18 , V_16 ) ;
return V_17 ;
}
static int F_10 ( struct V_11 * V_12 , char * V_13 )
{
struct V_14 * V_15 = F_6 ( V_13 ) ;
unsigned long V_16 ;
int V_17 = 0 ;
T_1 V_24 ;
F_7 ( & V_12 -> V_18 , V_16 ) ;
V_24 = V_15 -> V_13 [ V_15 -> V_25 & V_15 -> V_20 ] ;
if ( V_24 & V_26 )
V_17 = 1 ;
F_8 ( & V_12 -> V_18 , V_16 ) ;
return V_17 ;
}
static int F_11 ( struct V_11 * V_12 , struct V_28 * V_28 ,
int V_29 , int V_6 , int V_7 )
{
char * V_13 ;
int V_1 ;
if ( V_29 == V_30 )
V_13 = V_28 -> V_31 . V_32 ;
else
V_13 = V_28 -> V_33 . V_34 ;
V_1 = F_3 ( V_6 , V_7 ) ;
return F_5 ( V_12 , V_13 , V_1 ) ;
}
static int F_12 ( struct V_11 * V_12 , struct V_28 * V_28 ,
int V_29 , int * V_6 , int * V_7 , void * * V_35 )
{
char * V_13 , * V_36 ;
int V_1 = 0 , V_37 = 0 ;
int V_17 ;
if ( V_29 == V_30 ) {
V_13 = V_28 -> V_31 . V_32 ;
V_36 = V_28 -> V_38 . V_39 ;
} else {
V_13 = V_28 -> V_33 . V_34 ;
V_36 = V_28 -> V_40 . V_41 ;
}
V_17 = F_9 ( V_12 , V_13 , & V_1 ) ;
if ( V_17 ) {
V_37 = F_1 ( V_1 ) ;
if ( V_6 )
* V_6 = V_37 ;
if ( V_7 )
* V_7 = F_2 ( V_1 ) ;
if ( V_35 )
* V_35 = ( void * ) ( V_36 + F_4 ( V_37 ) ) ;
}
return V_17 ;
}
static int F_13 ( struct V_11 * V_12 , struct V_28 * V_28 )
{
char * V_13 = V_28 -> V_33 . V_34 ;
return F_10 ( V_12 , V_13 ) ;
}
static inline void F_14 ( struct V_28 * V_28 )
{
F_15 ( 1 , V_28 -> V_42 . V_43 ) ;
}
static inline void F_16 ( struct V_28 * V_28 )
{
F_15 ( 2 , V_28 -> V_42 . V_43 ) ;
}
static inline int F_17 ( int V_44 , int V_45 , int V_46 )
{
int V_47 = 0 , V_48 = 1 ;
return V_44 << V_49 |
V_45 << V_50 |
V_46 << V_51 |
V_47 << V_52 |
V_48 << V_53 ;
}
static void F_18 ( struct V_28 * V_28 , int V_54 , int V_55 )
{
V_28 -> V_56 = F_17 ( V_55 , V_54 - 1 , V_54 - 1 ) ;
V_28 -> V_57 = F_17 ( V_55 , V_54 - 1 , V_54 - 1 ) ;
}
static inline int F_19 ( int V_9 )
{
return ( V_9 * sizeof( T_1 ) ) + V_58 ;
}
static void F_20 ( void * V_59 , int V_9 )
{
struct V_14 * V_15 = V_59 ;
int V_60 ;
V_15 -> V_25 = 0 ;
V_15 -> V_19 = 0 ;
V_15 -> V_61 = 0 ;
V_15 -> V_62 = V_9 ;
V_15 -> V_20 = V_9 - 1 ;
V_15 -> V_23 = V_21 ;
for ( V_60 = 0 ; V_60 < V_9 ; V_60 ++ )
V_15 -> V_13 [ V_60 ] = 0 ;
}
static void F_21 ( struct V_63 * V_64 , struct V_65 * V_66 )
{
struct V_28 * V_67 = & V_66 -> V_67 ;
struct V_28 T_2 * V_68 = V_66 -> V_69 ;
int V_70 ;
F_16 ( V_67 ) ;
F_22 ( F_23 ( & V_68 -> V_56 ) & ~ ( 1 << V_53 ) ,
& V_68 -> V_56 ) ;
F_22 ( F_23 ( & V_68 -> V_57 ) & ~ ( 1 << V_53 ) ,
& V_68 -> V_57 ) ;
for ( V_70 = V_71 ; V_70 > 0 ; V_70 -- ) {
F_14 ( V_67 ) ;
F_24 ( V_72 ) ;
if ( ! ( F_23 ( & V_68 -> V_56 ) & ( 1 << V_52 ) )
&&
! ( F_23 ( & V_68 -> V_57 ) & ( 1 << V_52 ) ) )
break;
}
if ( V_70 == 0 )
F_25 ( & V_64 -> V_73 , L_1 ) ;
F_26 ( V_68 , 0 , sizeof( struct V_28 ) ) ;
F_27 ( V_64 , V_66 -> V_74 , V_66 -> V_75 , V_66 -> V_76 ) ;
}
static int F_28 ( struct V_11 * V_12 , struct V_65 * V_66 , int V_77 )
{
char * V_75 ;
T_3 V_76 ;
struct V_28 * V_67 , * V_78 ;
V_67 = & V_66 -> V_67 ;
V_78 = & V_66 -> V_78 ;
V_66 -> V_74 = 2 * F_19 ( V_79 ) +
2 * F_4 ( V_79 ) +
V_80 + V_81 ;
V_66 -> V_75 = F_29 ( V_12 -> V_82 , V_66 -> V_74 ,
& V_66 -> V_76 ) ;
if ( ! V_66 -> V_75 )
return - V_83 ;
V_75 = ( char * ) V_66 -> V_75 ;
V_76 = V_66 -> V_76 ;
memset ( V_75 , 0 , V_66 -> V_74 ) ;
V_75 = ( char * ) F_30 ( ( unsigned long ) V_75 , V_80 ) ;
V_76 = F_30 ( V_76 , V_80 ) ;
F_18 ( V_67 , V_79 , V_10 ) ;
F_18 ( V_78 , V_79 , V_10 ) ;
F_20 ( V_75 , V_79 ) ;
V_67 -> V_31 . V_32 = V_75 + V_58 ;
V_78 -> V_31 . V_84 = V_76 + V_58 ;
V_75 += F_19 ( V_79 ) ;
V_76 += F_19 ( V_79 ) ;
V_75 = ( char * ) F_30 ( ( unsigned long ) V_75 , V_81 ) ;
V_76 = F_30 ( V_76 , V_81 ) ;
F_20 ( V_75 , V_79 ) ;
V_67 -> V_33 . V_34 = V_75 + V_58 ;
V_78 -> V_33 . V_85 = V_76 + V_58 ;
V_75 += F_19 ( V_79 ) ;
V_76 += F_19 ( V_79 ) ;
V_67 -> V_38 . V_39 = V_75 ;
V_78 -> V_38 . V_86 = V_76 ;
V_76 += F_4 ( V_79 ) ;
V_75 += F_4 ( V_79 ) ;
V_67 -> V_40 . V_41 = V_75 ;
V_78 -> V_40 . V_87 = V_76 ;
V_67 -> V_88 = V_77 ;
V_78 -> V_88 = V_77 ;
V_67 -> V_42 . V_43 = V_12 -> V_89 + ( V_77 << V_90 ) ;
V_78 -> V_42 . V_43 = NULL ;
return 0 ;
}
static void F_31 ( struct V_11 * V_12 , struct V_65 * V_66 , int V_77 )
{
int V_37 , V_91 ;
struct V_28 * V_67 = & V_66 -> V_67 ;
V_66 -> V_69 = (struct V_28 T_2 * )
( V_12 -> V_92 + ( V_77 * V_93 ) ) ;
F_32 ( V_66 -> V_69 , & V_66 -> V_78 , sizeof( struct V_28 ) ) ;
V_91 = 0 ;
for ( V_37 = 0 ; V_37 < V_79 ; V_37 ++ ) {
F_11 ( V_12 , V_67 , V_30 , V_37 , V_91 ) ;
F_14 ( V_67 ) ;
}
V_91 = F_4 ( 1 ) ;
for ( V_37 = 0 ; V_37 < V_79 ; V_37 ++ )
F_11 ( V_12 , V_67 , V_94 , V_37 , V_91 ) ;
F_16 ( V_67 ) ;
}
static int F_33 ( struct V_11 * V_12 , struct V_65 * V_66 )
{
int V_37 , V_60 ;
struct V_28 * V_67 = & V_66 -> V_67 ;
for ( V_60 = V_71 ; V_60 > 0 ; V_60 -- ) {
if ( F_12 ( V_12 , V_67 , V_30 , & V_37 , NULL , NULL ) )
break;
F_24 ( V_72 ) ;
}
if ( V_60 == 0 ) {
F_25 ( & V_12 -> V_82 -> V_73 , L_2 ) ;
return - V_95 ;
}
F_11 ( V_12 , V_67 , V_30 , V_37 , 0 ) ;
F_14 ( V_67 ) ;
return 0 ;
}
static inline int F_34 ( struct V_28 * V_28 )
{
return F_6 ( V_28 -> V_31 . V_32 ) -> V_61 ;
}
static inline void F_35 ( struct V_28 * V_28 )
{
F_6 ( V_28 -> V_31 . V_32 ) -> V_61 = 1 ;
}
static inline int F_36 ( struct V_11 * V_12 )
{
return F_23 ( & V_12 -> V_96 [ V_97 ] ) ;
}
static inline int F_37 ( int V_98 )
{
return V_98 & ( 1 << V_99 ) ;
}
static inline int F_38 ( struct V_11 * V_12 )
{
return F_37 ( F_36 ( V_12 ) ) ;
}
static inline void F_39 ( struct V_11 * V_12 , int V_100 )
{
F_22 ( V_100 , & V_12 -> V_96 [ V_97 ] ) ;
}
static inline void F_40 ( struct V_11 * V_12 )
{
F_39 ( V_12 , - 1 ) ;
}
static inline void F_41 ( struct V_11 * V_12 )
{
F_15 ( F_42 ( & V_12 -> V_96 [ V_101 ] ) | 1 , & V_12 -> V_96 [ V_101 ] ) ;
}
static inline void F_43 ( struct V_11 * V_12 )
{
F_15 ( F_42 ( & V_12 -> V_96 [ V_101 ] ) & ~ 1 ,
& V_12 -> V_96 [ V_101 ] ) ;
}
static void F_44 ( struct V_11 * V_12 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_102 ; V_77 ++ ) {
if ( ! V_12 -> V_103 [ V_77 ] )
continue;
F_35 ( & V_12 -> V_103 [ V_77 ] -> V_67 ) ;
}
}
static T_4 F_45 ( struct V_104 * V_105 , char T_5 * V_106 ,
T_6 V_7 , T_7 * V_107 )
{
int V_108 , V_109 , V_110 , V_37 , V_111 ;
struct V_65 * V_66 = V_105 -> V_112 ;
struct V_28 * V_67 = & V_66 -> V_67 ;
struct V_11 * V_12 = V_66 -> V_113 ;
void * V_35 ;
if ( F_34 ( V_67 ) ) {
return - V_114 ;
}
V_110 = 20 ;
do {
V_109 = F_12 ( V_12 , V_67 , V_94 , & V_37 ,
& V_111 , & V_35 ) ;
if ( V_109 )
break;
V_110 -- ;
F_46 ( 100 ) ;
} while ( ! V_109 && V_110 );
if ( ! V_109 )
return - V_115 ;
if ( V_111 < V_7 )
V_7 = V_111 ;
V_108 = F_47 ( V_106 , V_35 , V_7 ) ;
F_11 ( V_12 , V_67 , V_94 , V_37 , F_4 ( 1 ) ) ;
return V_108 ? - V_116 : V_7 ;
}
static T_4 F_48 ( struct V_104 * V_105 , const char T_5 * V_106 ,
T_6 V_7 , T_7 * V_107 )
{
int V_108 , V_37 , V_111 ;
struct V_65 * V_66 = V_105 -> V_112 ;
struct V_28 * V_67 = & V_66 -> V_67 ;
struct V_11 * V_12 = V_66 -> V_113 ;
void * V_35 ;
if ( F_34 ( V_67 ) )
return - V_114 ;
if ( ! F_12 ( V_12 , V_67 , V_30 , & V_37 , & V_111 , & V_35 ) )
return - V_95 ;
if ( V_111 < V_7 )
V_7 = V_111 ;
V_108 = F_49 ( V_35 , V_106 , V_7 ) ;
if ( V_108 )
V_7 = 0 ;
F_11 ( V_12 , V_67 , V_30 , V_37 , V_7 ) ;
F_14 ( V_67 ) ;
return V_108 ? - V_116 : V_7 ;
}
static unsigned int F_50 ( struct V_104 * V_105 , T_8 * V_117 )
{
struct V_65 * V_66 = V_105 -> V_112 ;
struct V_28 * V_67 = & V_66 -> V_67 ;
F_51 ( V_105 , & V_66 -> V_118 , V_117 ) ;
if ( F_34 ( V_67 ) )
return V_119 ;
else if ( F_13 ( V_66 -> V_113 , V_67 ) )
return V_120 | V_121 ;
return 0 ;
}
static int F_52 ( struct V_122 * V_123 , struct V_104 * V_105 )
{
int V_77 ;
struct V_65 * V_66 ;
struct V_11 * V_12 ;
unsigned long V_16 ;
V_77 = F_53 ( V_123 ) % V_102 ;
V_12 = F_54 ( V_123 -> V_124 , struct V_11 , V_125 ) ;
F_55 ( & V_12 -> V_126 ) ;
if ( V_12 -> V_103 [ V_77 ] -> V_127 == 1 ) {
V_66 = V_105 -> V_112 ;
F_7 ( & V_12 -> V_128 , V_16 ) ;
V_12 -> V_103 [ V_77 ] = NULL ;
F_8 ( & V_12 -> V_128 , V_16 ) ;
F_21 ( V_12 -> V_82 , V_66 ) ;
F_56 ( V_66 ) ;
} else
V_12 -> V_103 [ V_77 ] -> V_127 -- ;
F_57 ( & V_12 -> V_126 ) ;
return 0 ;
}
static int F_58 ( struct V_122 * V_123 , struct V_104 * V_105 )
{
int V_77 , error ;
struct V_65 * V_66 ;
struct V_11 * V_12 ;
unsigned long V_16 ;
V_77 = F_53 ( V_123 ) % V_102 ;
V_12 = F_54 ( V_123 -> V_124 , struct V_11 , V_125 ) ;
V_66 = F_59 ( sizeof( * V_66 ) , V_129 ) ;
if ( ! V_66 )
return - V_83 ;
F_55 ( & V_12 -> V_126 ) ;
if ( V_12 -> V_103 [ V_77 ] == NULL ) {
error = F_28 ( V_12 , V_66 , V_77 ) ;
if ( error ) {
F_56 ( V_66 ) ;
goto V_130;
}
V_66 -> V_127 = 1 ;
V_66 -> V_131 = V_105 -> V_132 & V_133 ;
V_66 -> V_113 = V_12 ;
F_60 ( & V_66 -> V_118 ) ;
F_7 ( & V_12 -> V_128 , V_16 ) ;
F_31 ( V_12 , V_66 , V_77 ) ;
V_12 -> V_103 [ V_77 ] = V_66 ;
F_8 ( & V_12 -> V_128 , V_16 ) ;
error = F_33 ( V_12 , V_66 ) ;
if ( error ) {
F_7 ( & V_12 -> V_128 , V_16 ) ;
V_12 -> V_103 [ V_77 ] = NULL ;
F_8 ( & V_12 -> V_128 , V_16 ) ;
F_21 ( V_12 -> V_82 , V_66 ) ;
F_56 ( V_66 ) ;
goto V_130;
}
} else {
F_56 ( V_66 ) ;
if ( V_105 -> V_132 & V_133 || V_12 -> V_103 [ V_77 ] -> V_131 ) {
error = - V_95 ;
} else {
V_12 -> V_103 [ V_77 ] -> V_127 ++ ;
error = 0 ;
}
}
V_130:
F_57 ( & V_12 -> V_126 ) ;
if ( ! error )
V_105 -> V_112 = V_12 -> V_103 [ V_77 ] ;
return error ;
}
static T_9 F_61 ( int V_134 , void * V_66 )
{
struct V_11 * V_12 = V_66 ;
int V_135 , V_60 ;
F_55 ( & V_12 -> V_128 ) ;
V_135 = F_36 ( V_12 ) ;
if ( ! V_135 ) {
F_57 ( & V_12 -> V_128 ) ;
return V_136 ;
}
if ( F_37 ( V_135 ) ) {
V_135 = - 1 ;
F_44 ( V_12 ) ;
}
for ( V_60 = 0 ; V_60 < V_102 ; V_60 ++ ) {
if ( ! V_12 -> V_103 [ V_60 ] )
continue;
if ( V_135 & ( 1 << V_60 ) )
F_62 ( & V_12 -> V_103 [ V_60 ] -> V_118 ) ;
}
F_39 ( V_12 , V_135 ) ;
F_57 ( & V_12 -> V_128 ) ;
return V_137 ;
}
static void F_63 ( struct V_63 * V_64 , struct V_11 * V_12 )
{
F_64 ( V_64 , V_12 -> V_89 ) ;
F_64 ( V_64 , V_12 -> V_92 ) ;
F_64 ( V_64 , V_12 -> V_96 ) ;
}
static int T_10 F_65 ( struct V_63 * V_64 , struct V_11 * V_12 )
{
int error = - V_83 ;
V_12 -> V_96 = F_66 ( V_64 , 1 , 0 ) ;
if ( V_12 -> V_96 == NULL ) {
F_25 ( & V_64 -> V_73 , L_3 ) ;
goto V_130;
}
V_12 -> V_92 = F_66 ( V_64 , 2 , V_102 * V_93 ) ;
if ( V_12 -> V_92 == NULL ) {
F_25 ( & V_64 -> V_73 , L_4 ) ;
goto V_138;
}
V_12 -> V_89 = F_66 ( V_64 , 3 , V_102 * V_139 ) ;
if ( V_12 -> V_89 == NULL ) {
F_25 ( & V_64 -> V_73 , L_5 ) ;
goto V_140;
}
return 0 ;
V_140:
F_64 ( V_64 , V_12 -> V_92 ) ;
V_138:
F_64 ( V_64 , V_12 -> V_96 ) ;
V_130:
return error ;
}
static void F_67 ( struct V_63 * V_64 )
{
int V_60 , V_141 ;
struct V_11 * V_113 = F_68 ( V_64 ) ;
F_40 ( V_113 ) ;
V_141 = F_69 ( V_113 -> V_125 . V_73 ) ;
for ( V_60 = V_141 ; V_60 < V_141 + V_102 ; V_60 ++ )
F_70 ( V_142 , F_71 ( V_143 , V_60 ) ) ;
F_72 ( & V_113 -> V_125 ) ;
F_43 ( V_113 ) ;
F_73 ( V_64 -> V_134 , V_113 ) ;
F_63 ( V_64 , V_113 ) ;
F_74 ( V_64 ) ;
F_75 ( V_64 ) ;
F_56 ( V_113 ) ;
V_144 [ ( V_141 / V_102 ) ] = 0 ;
}
static int T_10 F_76 ( struct V_63 * V_64 ,
const struct V_145 * V_146 )
{
int V_147 , V_141 , V_148 , error ;
struct V_11 * V_113 ;
for ( V_147 = 0 ; V_147 < V_149 ; V_147 ++ ) {
if ( V_144 [ V_147 ] == 0 ) {
V_144 [ V_147 ] = 1 ;
break;
}
}
if ( V_147 == V_149 ) {
F_25 ( & V_64 -> V_73 , L_6 ) ;
return - V_114 ;
}
error = - V_83 ;
V_113 = F_59 ( sizeof( * V_113 ) , V_129 ) ;
if ( ! V_113 )
goto V_130;
V_113 -> V_82 = V_64 ;
F_77 ( & V_113 -> V_128 ) ;
F_77 ( & V_113 -> V_18 ) ;
F_77 ( & V_113 -> V_126 ) ;
error = F_78 ( V_64 ) ;
if ( error )
goto free;
F_79 ( V_64 ) ;
error = F_80 ( V_64 , V_150 ) ;
if ( error )
goto V_151;
error = F_65 ( V_64 , V_113 ) ;
if ( error )
goto V_152;
F_81 ( V_64 , V_113 ) ;
F_40 ( V_113 ) ;
error = F_82 ( V_64 -> V_134 , F_61 , V_153 , L_7 , V_113 ) ;
if ( error )
goto V_154;
F_41 ( V_113 ) ;
F_83 ( & V_113 -> V_125 , & V_155 ) ;
V_113 -> V_125 . V_156 = V_157 ;
V_148 = V_147 * V_102 ;
error = F_84 ( & V_113 -> V_125 , F_71 ( V_143 , V_148 ) , V_102 ) ;
if ( error ) {
F_25 ( & V_64 -> V_73 , L_8 ) ;
goto V_158;
}
for ( V_141 = 0 ; V_141 < V_102 ; V_141 ++ ) {
struct V_159 * V_73 ;
V_73 = F_85 ( V_142 , & V_64 -> V_73 ,
F_71 ( V_143 , V_141 ) , NULL ,
L_9 , V_147 , V_141 ) ;
if ( F_86 ( V_73 ) )
F_25 ( & V_64 -> V_73 , L_10 ) ;
}
return 0 ;
V_158:
F_43 ( V_113 ) ;
F_73 ( V_64 -> V_134 , V_113 ) ;
V_154:
F_63 ( V_64 , V_113 ) ;
V_152:
F_74 ( V_64 ) ;
V_151:
F_75 ( V_64 ) ;
free:
F_56 ( V_113 ) ;
V_130:
V_144 [ V_147 ] = 0 ;
return error ;
}
static int T_11 F_87 ( void )
{
int error ;
T_12 V_73 ;
V_142 = F_88 ( V_157 , L_11 ) ;
if ( F_86 ( V_142 ) ) {
error = F_89 ( V_142 ) ;
goto V_130;
}
error = F_90 ( & V_73 , 0 , V_160 , V_150 ) ;
if ( error )
goto V_161;
V_143 = F_91 ( V_73 ) ;
error = F_92 ( & V_162 ) ;
if ( error )
goto V_163;
return 0 ;
V_163:
F_93 ( V_73 , V_160 ) ;
V_161:
V_161 ( V_142 ) ;
V_130:
return error ;
}
static void T_13 F_94 ( void )
{
F_95 ( & V_162 ) ;
F_93 ( F_71 ( V_143 , 0 ) , V_160 ) ;
V_161 ( V_142 ) ;
}
