static inline void F_1 ( void * V_1 , const void T_1 * V_2 ,
int * V_3 , unsigned long V_4 )
{
if ( * V_3 )
return;
if ( F_2 ( ! V_2 ) ) {
* V_3 = - V_5 ;
return;
}
if ( F_2 ( F_3 ( V_1 , V_2 , V_4 ) ) )
* V_3 = - V_5 ;
}
static inline void F_4 ( void T_1 * V_1 , const void * V_2 ,
int * V_3 , unsigned long V_4 )
{
if ( * V_3 )
return;
if ( F_2 ( ! V_1 ) ) {
* V_3 = - V_5 ;
return;
}
if ( F_2 ( F_5 ( V_1 , V_2 , V_4 ) ) )
* V_3 = - V_5 ;
}
inline int F_6 ( T_2 V_6 , union V_7 * args ,
T_2 * V_8 , void * V_9 )
{
T_2 (* F_7) ( union V_7 * args , void * V_9 ) = NULL ;
int V_10 ;
if ( F_8 ( V_6 ) != V_11 ) {
F_9 ( L_1 , V_12 ) ;
goto V_3;
}
if ( F_10 ( V_6 ) > F_11 ( V_13 ) ) {
F_9 ( L_2 , V_12 ) ;
goto V_3;
}
V_10 = F_12 ( V_6 ) ;
if ( V_10 > V_13 [ F_10 ( V_6 ) ] ) {
F_9 ( L_3 ,
V_12 , V_10 , F_10 ( V_6 ) ) ;
goto V_3;
}
switch ( F_13 ( V_6 ) ) {
case V_14 :
F_7 = V_15 [ V_10 ] . V_16 ;
break;
case V_17 :
F_7 = V_18 [ V_10 ] . V_16 ;
break;
case V_19 :
F_7 = V_20 [ V_10 ] . V_16 ;
break;
case V_21 :
F_7 = V_22 [ V_10 ] . V_16 ;
break;
case V_23 :
F_7 = V_24 [ V_10 ] . V_16 ;
break;
}
if ( ! F_7 ) {
F_9 ( L_4 , V_12 ) ;
goto V_3;
} else {
* V_8 = (* F_7) ( args , V_9 ) ;
}
return 0 ;
V_3:
return - V_25 ;
}
void F_14 ( void )
{
F_15 ( V_26 > 0 ) ;
V_26 -- ;
if ( V_26 == 0 ) {
F_16 () ;
F_17 () ;
F_18 () ;
F_19 () ;
F_20 () ;
F_21 () ;
F_22 () ;
F_23 () ;
F_24 () ;
F_25 () ;
F_26 () ;
F_27 () ;
}
F_28 ( V_26 >= 0 ) ;
}
bool F_29 ( void )
{
bool V_27 = true ;
bool V_28 , V_29 , V_30 , V_31 , V_32 , V_33 ;
bool V_34 , V_35 , V_36 , V_37 , V_38 , V_39 ;
if ( V_26 == 0 ) {
V_28 = F_30 () ;
V_34 = F_31 () ;
V_35 = F_32 () ;
V_36 = F_33 () ;
V_37 = F_34 () ;
V_38 = F_35 () ;
V_39 = F_36 () ;
V_31 = F_37 () ;
V_32 = F_38 () ;
V_33 = F_39 () ;
V_29 = F_40 () ;
V_30 = F_41 () ;
V_27 = V_28 && V_29 && V_31 && V_30 && V_32 && V_33 ;
V_27 = V_27 && V_34 && V_35 && V_39 ;
if ( ! V_27 ) {
if ( V_28 )
F_27 () ;
if ( V_34 )
F_25 () ;
if ( V_38 )
F_21 () ;
if ( V_35 )
F_24 () ;
if ( V_36 )
F_23 () ;
if ( V_37 )
F_22 () ;
if ( V_31 )
F_18 () ;
if ( V_32 )
F_19 () ;
if ( V_33 )
F_20 () ;
if ( V_29 )
F_17 () ;
if ( V_30 )
F_16 () ;
if ( V_39 )
F_26 () ;
}
}
if ( V_27 )
V_26 ++ ;
return V_27 ;
}
int F_42 ( void )
{
int V_40 = 0 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
T_3 V_47 ;
F_15 ( V_26 > 0 ) ;
for ( V_44 = F_43 () ; V_44 != NULL ;
V_44 = F_44 ( V_44 ) ) {
if ( F_45 ( V_44 , & V_42 ) )
continue;
if ( F_46 ( V_44 , & V_47 ) )
continue;
if ( ( V_47 == V_48 ) || ( V_47 == V_49 ) ) {
V_46 = F_47 ( V_50 ) ;
if ( V_46 && V_46 -> V_51 )
F_48 ( V_42 , V_44 ) ;
}
}
return V_40 ;
}
T_2 F_49 ( union V_7 * args , void * V_9 )
{
T_3 * V_52 ;
T_2 V_53 ;
int V_40 = 0 ;
T_2 V_54 = args -> V_55 . V_56 ;
if ( V_54 < sizeof( struct V_57 ) )
return - V_25 ;
V_52 = F_50 ( V_54 , V_58 ) ;
if ( V_52 == NULL )
V_40 = - V_59 ;
if ( ! V_40 ) {
V_40 =
F_51 ( args -> V_55 . V_60 ,
(struct V_57 * ) V_52 , V_54 ,
& V_53 ) ;
}
F_52 ( args -> V_55 . V_61 , V_52 , V_40 ,
V_54 ) ;
F_52 ( args -> V_55 . V_53 , & V_53 , V_40 ,
1 ) ;
F_53 ( V_52 ) ;
return V_40 ;
}
T_2 F_54 ( union V_7 * args , void * V_9 )
{
T_3 * V_62 ;
T_3 V_63 ;
int V_40 = 0 ;
T_2 V_54 = args -> V_64 . V_65 ;
if ( V_54 < sizeof( struct V_66 ) )
return - V_25 ;
V_62 = F_50 ( V_54 , V_58 ) ;
if ( V_62 == NULL )
V_40 = - V_59 ;
if ( ! V_40 ) {
V_40 =
F_55 ( args -> V_64 .
V_67 ,
(struct V_66 * )
V_62 , V_54 , & V_63 ) ;
}
F_52 ( args -> V_64 . V_62 , V_62 ,
V_40 , V_54 ) ;
F_52 ( args -> V_64 . V_63 , & V_63 ,
V_40 , 1 ) ;
F_53 ( V_62 ) ;
return V_40 ;
}
T_2 F_56 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
struct V_68 V_69 ;
T_2 V_70 = 0 ;
char * V_71 = NULL ;
int V_40 = 0 ;
F_57 ( & V_69 , args -> V_72 . V_69 , V_40 , 1 ) ;
if ( V_40 )
goto V_73;
V_70 = F_58 ( ( char * )
args -> V_72 . V_74 ) +
1 ;
V_71 = F_50 ( V_70 , V_58 ) ;
if ( ! V_71 ) {
V_40 = - V_59 ;
goto V_73;
}
V_27 = F_59 ( V_71 ,
( char * ) args -> V_72 .
V_74 , V_70 ) ;
if ( ! V_27 ) {
V_40 = - V_5 ;
goto V_73;
}
if ( args -> V_72 . V_75 >= V_76 ) {
V_40 = - V_25 ;
goto V_73;
}
V_40 = F_60 ( & V_69 ,
args -> V_72 . V_75 ,
( char * ) V_71 ) ;
V_73:
F_53 ( V_71 ) ;
return V_40 ;
}
T_2 F_61 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_68 V_69 ;
F_57 ( & V_69 , args -> V_72 . V_69 , V_40 , 1 ) ;
if ( V_40 )
goto V_73;
V_40 = F_62 ( & V_69 ,
args -> V_77 .
V_75 ) ;
V_73:
return V_40 ;
}
T_2 F_63 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_78 * V_79 [ V_80 ] ;
struct V_78 V_81 [ V_80 ] ;
T_2 V_82 , V_10 ;
T_2 V_83 = args -> V_84 . V_83 ;
if ( V_83 > V_80 )
V_40 = - V_25 ;
F_57 ( V_79 , args -> V_84 . V_79 ,
V_40 , V_83 ) ;
for ( V_10 = 0 ; V_10 < V_83 ; V_10 ++ ) {
F_57 ( & V_81 [ V_10 ] , V_79 [ V_10 ] , V_40 , 1 ) ;
if ( V_40 || ! V_81 [ V_10 ] . V_85 ) {
V_40 = - V_25 ;
break;
}
V_79 [ V_10 ] = & V_81 [ V_10 ] ;
}
if ( ! V_40 ) {
V_40 = F_64 ( V_79 , V_83 ,
& V_82 ,
args -> V_84 .
V_86 ) ;
}
F_52 ( args -> V_84 . V_82 , & V_82 , V_40 , 1 ) ;
return V_40 ;
}
T_2 T_4 F_65 ( union V_7 * args ,
void * V_9 )
{
F_9 ( L_5 , V_12 ) ;
return 0 ;
}
T_2 F_66 ( union V_7 * args , void * V_9 )
{
void * V_87 ;
int V_40 = 0 ;
struct V_88 V_89 , * V_90 = NULL ;
if ( args -> V_91 . V_90 ) {
F_57 ( & V_89 , args -> V_91 . V_90 , V_40 ,
1 ) ;
if ( ! V_40 )
V_90 = & V_89 ;
else
goto V_73;
}
V_40 = F_67 ( args -> V_91 . V_67 , V_90 ,
& V_87 , V_9 ) ;
F_52 ( args -> V_91 . V_92 , & V_87 , V_40 , 1 ) ;
V_73:
return V_40 ;
}
T_2 F_68 ( union V_7 * args , void * V_9 )
{
T_2 V_93 , T_1 * V_94 = ( T_2 T_1 * )
args -> V_95 . args ;
T_3 * V_96 = NULL ;
int V_40 = 0 ;
void * V_97 = ( (struct V_98 * ) V_9 ) -> V_87 ;
if ( V_94 ) {
if ( F_69 ( V_93 , V_94 ) ) {
V_40 = - V_99 ;
goto V_73;
}
V_93 += sizeof( T_2 ) ;
V_96 = F_50 ( V_93 , V_58 ) ;
if ( V_96 == NULL ) {
V_40 = - V_59 ;
goto V_73;
}
F_57 ( V_96 , args -> V_95 . args , V_40 ,
V_93 ) ;
}
if ( ! V_40 ) {
V_40 = F_70 ( V_97 ,
args -> V_95 . V_6 ,
(struct V_100 * ) V_96 ) ;
}
F_53 ( V_96 ) ;
V_73:
return V_40 ;
}
T_2 T_4 F_71 ( union V_7 * args , void * V_9 )
{
F_9 ( L_5 , V_12 ) ;
return 0 ;
}
T_2 F_72 ( union V_7 * args , void * V_9 )
{
int V_40 ;
void * V_101 [ V_102 ] ;
T_2 V_53 ;
T_2 V_103 ;
void * V_97 = ( (struct V_98 * ) V_9 ) -> V_87 ;
if ( ! args -> V_104 . V_105 )
return - V_25 ;
V_40 = F_73 ( V_97 ,
V_101 ,
args -> V_104 . V_105 ,
& V_53 , & V_103 ) ;
F_52 ( args -> V_104 . V_101 , V_101 , V_40 ,
V_53 ) ;
F_52 ( args -> V_104 . V_53 , & V_53 ,
V_40 , 1 ) ;
F_52 ( args -> V_104 . V_106 , & V_103 ,
V_40 , 1 ) ;
return V_40 ;
}
T_2 F_74 ( union V_7 * args , void * V_9 )
{
int V_40 ;
if ( args -> V_107 . V_108 >= V_109 )
return - V_25 ;
V_40 = F_75 ( V_9 ,
args -> V_107 . V_110 ,
args -> V_107 . V_54 ,
args -> V_107 . V_108 ) ;
return V_40 ;
}
T_2 F_76 ( union V_7 * args , void * V_9 )
{
int V_40 ;
if ( args -> V_107 . V_108 >= V_109 )
return - V_25 ;
V_40 = F_77 ( V_9 ,
args -> V_107 . V_110 ,
args -> V_107 . V_54 ,
args -> V_107 . V_108 ) ;
return V_40 ;
}
T_2 F_78 ( union V_7 * args , void * V_9 )
{
int V_40 ;
if ( args -> V_111 . V_112 >
V_113 )
return - V_25 ;
V_40 = F_79 ( V_9 ,
args -> V_111 . V_110 ,
args -> V_111 . V_54 ,
args -> V_111 . V_112 ) ;
return V_40 ;
}
T_2 F_80 ( union V_7 * args , void * V_9 )
{
int V_40 ;
V_40 =
F_81 ( V_9 ,
args -> V_114 . V_110 ,
args -> V_114 . V_54 ) ;
return V_40 ;
}
T_2 F_82 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_115 V_116 ;
void * V_97 = ( (struct V_98 * ) V_9 ) -> V_87 ;
if ( args -> V_117 . V_118 <
sizeof( struct V_115 ) )
return - V_25 ;
V_40 =
F_83 ( V_97 ,
args -> V_117 . V_119 ,
& V_116 ,
args -> V_117 .
V_118 ) ;
F_52 ( args -> V_117 . V_116 , & V_116 ,
V_40 , 1 ) ;
return V_40 ;
}
T_2 F_84 ( union V_7 * args , void * V_9 )
{
int V_40 ;
struct V_120 V_121 ;
void * V_97 = ( (struct V_98 * ) V_9 ) -> V_87 ;
if ( args -> V_122 . V_123 <
sizeof( struct V_120 ) )
return - V_25 ;
V_40 = F_85 ( V_97 , & V_121 ,
args -> V_122 . V_123 ) ;
F_52 ( args -> V_122 . V_124 , & V_121 , V_40 ,
1 ) ;
return V_40 ;
}
T_2 F_86 ( union V_7 * args , void * V_9 )
{
int V_40 ;
T_3 * V_125 ;
void * V_97 = ( (struct V_98 * ) V_9 ) -> V_87 ;
if ( args -> V_126 . V_127 > V_128 )
return - V_25 ;
V_125 = F_87 ( args -> V_126 . V_127 , V_58 ) ;
if ( V_125 != NULL ) {
V_40 = F_88 ( V_97 , V_125 ,
args -> V_126 . V_127 ) ;
} else {
V_40 = - V_59 ;
}
F_52 ( args -> V_126 . V_129 , V_125 , V_40 ,
args -> V_126 . V_127 ) ;
F_53 ( V_125 ) ;
return V_40 ;
}
T_2 F_89 ( union V_7 * args , void * V_9 )
{
T_5 V_10 , V_130 ;
int V_40 = 0 ;
char * V_131 ;
T_5 V_83 = args -> V_132 . V_133 ;
T_3 * * V_134 = NULL , * * V_135 = NULL ;
void * V_97 = ( (struct V_98 * ) V_9 ) -> V_87 ;
if ( V_83 <= 0 || V_83 > V_136 ) {
V_40 = - V_25 ;
goto V_137;
}
V_134 = F_50 ( V_83 * sizeof( T_3 * ) , V_58 ) ;
if ( ! V_134 ) {
V_40 = - V_59 ;
goto V_137;
}
F_57 ( V_134 , args -> V_132 . V_138 , V_40 , V_83 ) ;
if ( V_40 ) {
F_53 ( V_134 ) ;
V_134 = NULL ;
goto V_137;
}
for ( V_10 = 0 ; V_10 < V_83 ; V_10 ++ ) {
if ( V_134 [ V_10 ] ) {
V_131 = ( char * ) V_134 [ V_10 ] ;
V_130 = F_58 ( ( char * ) V_131 ) + 1 ;
V_134 [ V_10 ] = F_50 ( V_130 , V_58 ) ;
if ( V_134 [ V_10 ] ) {
F_57 ( V_134 [ V_10 ] , V_131 , V_40 , V_130 ) ;
if ( V_40 ) {
F_53 ( V_134 [ V_10 ] ) ;
V_134 [ V_10 ] = NULL ;
goto V_137;
}
} else {
V_40 = - V_59 ;
goto V_137;
}
}
}
if ( args -> V_132 . V_139 ) {
V_83 = 0 ;
do {
if ( F_69 ( V_131 ,
args -> V_132 . V_139 + V_83 ) ) {
V_40 = - V_5 ;
goto V_137;
}
V_83 ++ ;
} while ( V_131 );
V_135 = F_50 ( V_83 * sizeof( T_3 * ) , V_58 ) ;
if ( ! V_135 ) {
V_40 = - V_59 ;
goto V_137;
}
F_57 ( V_135 , args -> V_132 . V_139 , V_40 , V_83 ) ;
if ( V_40 ) {
F_53 ( V_135 ) ;
V_135 = NULL ;
goto V_137;
}
for ( V_10 = 0 ; V_135 [ V_10 ] ; V_10 ++ ) {
V_131 = ( char * ) V_135 [ V_10 ] ;
V_130 = F_58 ( ( char * ) V_131 ) + 1 ;
V_135 [ V_10 ] = F_50 ( V_130 , V_58 ) ;
if ( V_135 [ V_10 ] ) {
F_57 ( V_135 [ V_10 ] , V_131 , V_40 , V_130 ) ;
if ( V_40 ) {
F_53 ( V_135 [ V_10 ] ) ;
V_135 [ V_10 ] = NULL ;
goto V_137;
}
} else {
V_40 = - V_59 ;
goto V_137;
}
}
}
if ( ! V_40 ) {
V_40 = F_90 ( V_97 ,
args -> V_132 . V_133 ,
( const char * * ) V_134 , ( const char * * ) V_135 ) ;
}
V_137:
if ( V_135 ) {
V_10 = 0 ;
while ( V_135 [ V_10 ] )
F_53 ( V_135 [ V_10 ++ ] ) ;
F_53 ( V_135 ) ;
}
if ( V_134 ) {
V_83 = args -> V_132 . V_133 ;
for ( V_10 = 0 ; ( V_10 < V_83 ) && V_134 [ V_10 ] ; V_10 ++ )
F_53 ( V_134 [ V_10 ] ) ;
F_53 ( V_134 ) ;
}
return V_40 ;
}
T_2 F_91 ( union V_7 * args , void * V_9 )
{
int V_40 ;
void * V_140 ;
void * V_97 = ( (struct V_98 * ) V_9 ) -> V_87 ;
if ( ! args -> V_141 . V_54 )
return - V_25 ;
V_40 = F_92 ( args -> V_141 . V_87 ,
args -> V_141 . V_110 ,
args -> V_141 . V_54 ,
args -> V_141 . V_142 , & V_140 ,
args -> V_141 . V_143 , V_9 ) ;
if ( ! V_40 ) {
if ( F_93 ( V_140 , args -> V_141 . V_140 ) ) {
V_40 = - V_25 ;
F_94 ( V_97 , V_140 , V_9 ) ;
}
}
return V_40 ;
}
T_2 F_95 ( union V_7 * args , void * V_9 )
{
int V_40 ;
struct V_78 V_144 ;
void * V_97 = ( (struct V_98 * ) V_9 ) -> V_87 ;
V_144 . V_145 = NULL ;
V_144 . V_85 = NULL ;
V_40 = F_96 ( V_97 ,
args -> V_146 . V_147 ,
args -> V_146 . V_148 ,
& V_144 ) ;
F_52 ( args -> V_146 . V_144 , & V_144 ,
V_40 , 1 ) ;
return V_40 ;
}
T_2 F_97 ( union V_7 * args , void * V_9 )
{
int V_40 ;
void * V_149 ;
void * V_97 = ( (struct V_98 * ) V_9 ) -> V_87 ;
if ( ( args -> V_150 . V_54 <= 0 ) ||
( args -> V_150 . V_54 & ( V_151 - 1 ) ) != 0 )
return - V_25 ;
V_40 = F_98 ( V_97 ,
args -> V_150 . V_54 , & V_149 ,
V_9 ) ;
if ( ! V_40 ) {
if ( F_93 ( V_149 , args -> V_150 . V_152 ) ) {
V_40 = - V_25 ;
F_99 ( args -> V_150 .
V_87 , V_149 , V_9 ) ;
}
}
return V_40 ;
}
T_2 F_100 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
V_27 = F_101 ( ( (struct V_98 * ) V_9 ) -> V_87 ) ;
return V_27 ;
}
T_2 F_102 ( union V_7 * args , void * V_9 )
{
int V_40 ;
V_40 = F_94 ( ( (struct V_98 * ) V_9 ) -> V_87 ,
args -> V_153 . V_140 , V_9 ) ;
return V_40 ;
}
T_2 F_103 ( union V_7 * args , void * V_9 )
{
int V_40 ;
void * V_97 = ( (struct V_98 * ) V_9 ) -> V_87 ;
V_40 = F_99 ( V_97 ,
args -> V_154 . V_152 ,
V_9 ) ;
return V_40 ;
}
T_2 F_104 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
V_27 = F_105 ( ( (struct V_98 * ) V_9 ) -> V_87 ) ;
return V_27 ;
}
inline void F_106 ( struct V_155 * * V_156 ,
void * V_9 , void * V_157 )
{
F_107 () ;
* V_156 = F_108 ( ( (struct V_98 * ) V_9 ) -> V_60 ,
( int ) V_157 - 1 ) ;
F_109 () ;
return;
}
T_2 F_110 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_68 V_158 ;
T_2 V_93 = 0 ;
T_2 T_1 * V_94 = ( T_2 T_1 * ) args -> V_159 . args ;
T_3 * V_96 = NULL ;
struct V_160 V_89 , * V_90 = NULL ;
struct V_155 * V_161 ;
int V_162 ;
void * V_97 = ( (struct V_98 * ) V_9 ) -> V_87 ;
if ( V_94 ) {
if ( F_69 ( V_93 , V_94 ) )
V_40 = - V_99 ;
V_93 += sizeof( T_2 ) ;
if ( ! V_40 ) {
V_96 = F_50 ( V_93 , V_58 ) ;
if ( V_96 == NULL )
V_40 = - V_59 ;
}
F_57 ( V_96 , args -> V_159 . args , V_40 ,
V_93 ) ;
}
F_57 ( & V_158 , args -> V_159 . V_163 , V_40 , 1 ) ;
if ( V_40 )
goto V_137;
if ( args -> V_159 . V_90 ) {
F_57 ( & V_89 , args -> V_159 . V_90 ,
V_40 , 1 ) ;
if ( ! V_40 )
V_90 = & V_89 ;
else
V_40 = - V_59 ;
}
if ( ! V_40 ) {
V_40 = F_111 ( V_97 ,
& V_158 , (struct V_100 * ) V_96 ,
V_90 , & V_161 , V_9 ) ;
}
if ( ! V_40 ) {
V_162 = V_161 -> V_164 + 1 ;
F_52 ( args -> V_159 . V_165 , & V_162 ,
V_40 , 1 ) ;
if ( V_40 ) {
V_40 = - V_5 ;
F_112 ( V_161 , V_9 ) ;
}
}
V_137:
F_53 ( V_96 ) ;
return V_40 ;
}
T_2 F_113 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_166 * V_167 = NULL ;
struct V_166 V_168 ;
T_3 * V_169 = NULL ;
struct V_155 * V_161 ;
F_106 ( & V_161 , V_9 ,
args -> V_170 . V_165 ) ;
if ( ! V_161 )
return - V_5 ;
if ( ! args -> V_170 . V_54 )
return - V_25 ;
if ( args -> V_170 . V_168 ) {
F_57 ( & V_168 , args -> V_170 . V_168 , V_40 , 1 ) ;
if ( ! V_40 )
V_167 = & V_168 ;
}
F_57 ( & V_169 , args -> V_170 . V_171 , V_40 , 1 ) ;
if ( ! V_40 ) {
V_40 = F_114 ( V_161 -> V_165 ,
args -> V_170 . V_54 ,
V_167 , & V_169 ) ;
}
F_52 ( args -> V_170 . V_171 , & V_169 , V_40 , 1 ) ;
return V_40 ;
}
T_2 F_115 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
struct V_155 * V_161 ;
F_106 ( & V_161 , V_9 ,
args -> V_172 . V_165 ) ;
if ( ! V_161 )
return - V_5 ;
V_27 = F_116 ( V_161 -> V_165 ,
args -> V_172 . V_173 ) ;
return V_27 ;
}
T_2 F_117 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_174 V_175 ;
struct V_174 * V_176 = NULL ;
T_2 V_93 ;
T_2 T_1 * V_94 = ( T_2 T_1 * ) args -> V_177 . V_178 ;
T_3 * V_96 = NULL ;
struct V_155 * V_179 , * V_180 ;
struct V_181 * V_182 = NULL , * V_183 = NULL ;
if ( ( int ) args -> V_177 . V_165 != V_184 ) {
F_106 ( & V_179 , V_9 ,
args -> V_177 . V_165 ) ;
if ( V_179 )
V_182 = V_179 -> V_165 ;
} else {
V_182 = args -> V_177 . V_165 ;
}
if ( ( int ) args -> V_177 . V_185 != V_184 ) {
F_106 ( & V_180 , V_9 ,
args -> V_177 . V_185 ) ;
if ( V_180 )
V_183 = V_180 -> V_165 ;
} else {
V_183 = args -> V_177 . V_185 ;
}
if ( ! V_182 || ! V_183 )
return - V_5 ;
if ( V_94 ) {
if ( F_69 ( V_93 , V_94 ) )
V_40 = - V_99 ;
V_93 += sizeof( T_2 ) ;
if ( ! V_40 ) {
V_96 = F_50 ( V_93 , V_58 ) ;
if ( V_96 == NULL ) {
V_40 = - V_59 ;
goto V_137;
}
}
F_57 ( V_96 , args -> V_177 . V_178 , V_40 ,
V_93 ) ;
if ( V_40 )
goto V_137;
}
if ( args -> V_177 . V_175 ) {
F_57 ( & V_175 , args -> V_177 . V_175 , V_40 , 1 ) ;
if ( ! V_40 )
V_176 = & V_175 ;
}
if ( ! V_40 ) {
V_40 = F_118 ( V_182 ,
args -> V_177 . V_186 ,
V_183 ,
args -> V_177 . V_187 ,
V_176 , (struct V_100 * ) V_96 ) ;
}
V_137:
F_53 ( V_96 ) ;
return V_40 ;
}
T_2 F_119 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
struct V_155 * V_161 ;
F_106 ( & V_161 , V_9 , args -> V_188 . V_165 ) ;
if ( ! V_161 )
return - V_5 ;
V_27 = F_120 ( V_161 -> V_165 ) ;
return V_27 ;
}
T_2 F_121 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
struct V_155 * V_161 ;
F_106 ( & V_161 , V_9 , args -> V_189 . V_165 ) ;
if ( ! V_161 )
return - V_5 ;
V_27 = F_112 ( V_161 , V_9 ) ;
return V_27 ;
}
T_2 F_122 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_166 * V_167 = NULL ;
struct V_166 V_168 ;
struct V_155 * V_161 ;
F_106 ( & V_161 , V_9 , args -> V_190 . V_165 ) ;
if ( ! V_161 )
return - V_5 ;
if ( args -> V_190 . V_168 ) {
F_57 ( & V_168 , args -> V_190 . V_168 , V_40 , 1 ) ;
if ( ! V_40 )
V_167 = & V_168 ;
}
if ( ! args -> V_190 . V_171 )
return - V_5 ;
if ( ! V_40 ) {
V_40 = F_123 ( V_161 -> V_165 ,
args -> V_190 . V_171 ,
V_167 ) ;
}
return V_40 ;
}
T_2 F_124 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_191 V_168 ;
struct V_155 * V_161 ;
F_106 ( & V_161 , V_9 , args -> V_192 . V_165 ) ;
if ( ! V_161 )
return - V_5 ;
V_40 = F_125 ( V_161 -> V_165 , & V_168 ,
args -> V_192 . V_193 ) ;
F_52 ( args -> V_192 . V_168 , & V_168 , V_40 , 1 ) ;
return V_40 ;
}
T_2 F_126 ( union V_7 * args , void * V_9 )
{
int V_40 ;
struct V_194 V_195 ;
struct V_155 * V_161 ;
F_106 ( & V_161 , V_9 , args -> V_196 . V_165 ) ;
if ( ! V_161 )
return - V_5 ;
V_40 = F_127 ( V_161 -> V_165 , & V_195 ,
args -> V_196 . V_86 ) ;
F_52 ( args -> V_196 . V_197 , & V_195 , V_40 , 1 ) ;
return V_40 ;
}
T_2 F_128 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
struct V_155 * V_161 ;
F_106 ( & V_161 , V_9 , args -> V_198 . V_165 ) ;
if ( ! V_161 )
return - V_5 ;
V_27 = F_129 ( V_161 -> V_165 ) ;
return V_27 ;
}
T_2 F_130 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_194 V_195 ;
struct V_155 * V_161 ;
F_106 ( & V_161 , V_9 , args -> V_199 . V_165 ) ;
if ( ! V_161 )
return - V_5 ;
F_57 ( & V_195 , args -> V_199 . V_197 , V_40 , 1 ) ;
if ( ! V_40 ) {
V_40 =
F_131 ( V_161 -> V_165 , & V_195 ,
args -> V_199 . V_86 ) ;
}
return V_40 ;
}
T_2 F_132 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_78 V_144 ;
struct V_155 * V_161 ;
F_106 ( & V_161 , V_9 ,
args -> V_200 . V_165 ) ;
if ( ! V_161 )
return - V_5 ;
V_144 . V_145 = NULL ;
V_144 . V_85 = NULL ;
if ( ! args -> V_146 . V_147 )
F_57 ( & V_144 ,
args -> V_146 . V_144 ,
V_40 , 1 ) ;
V_40 = F_133 ( V_161 -> V_165 ,
args -> V_200 . V_147 ,
args -> V_200 .
V_148 , & V_144 ) ;
F_52 ( args -> V_200 . V_144 , & V_144 ,
V_40 , 1 ) ;
return V_40 ;
}
T_2 F_134 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
struct V_155 * V_161 ;
F_106 ( & V_161 , V_9 , args -> V_201 . V_165 ) ;
if ( ! V_161 )
return - V_5 ;
V_27 = F_135 ( V_161 -> V_165 ) ;
return V_27 ;
}
T_2 F_136 ( union V_7 * args , void * V_9 )
{
int V_40 ;
int V_202 ;
struct V_155 * V_161 ;
F_106 ( & V_161 , V_9 , args -> V_203 . V_165 ) ;
if ( ! V_161 )
return - V_5 ;
V_40 = F_137 ( V_161 -> V_165 , & V_202 ) ;
F_52 ( args -> V_203 . V_40 , & V_202 , V_40 , 1 ) ;
return V_40 ;
}
T_2 F_138 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_68 V_158 ;
struct V_57 * V_204 = NULL ;
void * V_97 = ( (struct V_98 * ) V_9 ) -> V_87 ;
F_57 ( & V_158 , args -> V_205 . V_163 , V_40 ,
1 ) ;
if ( V_40 )
goto V_137;
V_204 = F_50 ( sizeof( struct V_57 ) , V_58 ) ;
if ( V_204 != NULL ) {
V_40 =
F_139 ( V_97 , & V_158 , V_204 ) ;
F_52 ( args -> V_205 . V_206 , V_204 ,
V_40 , 1 ) ;
} else
V_40 = - V_59 ;
V_137:
F_53 ( V_204 ) ;
return V_40 ;
}
inline void F_140 ( struct V_207 * * V_208 ,
void * V_9 , void * V_209 )
{
F_107 () ;
* V_208 = F_108 ( ( (struct V_98 * ) V_9 ) -> V_186 ,
( int ) V_209 - 1 ) ;
F_109 () ;
return;
}
T_2 F_141 ( union V_7 * args , void * V_9 )
{
int V_40 ;
T_3 * * V_210 = NULL ;
T_2 V_211 = args -> V_212 . V_211 ;
struct V_207 * V_213 ;
F_140 ( & V_213 , V_9 ,
args -> V_212 . V_214 ) ;
if ( ! V_213 )
return - V_5 ;
if ( V_211 > V_215 )
return - V_25 ;
V_210 = F_50 ( ( V_211 * sizeof( T_3 * ) ) , V_58 ) ;
if ( V_210 == NULL )
return - V_59 ;
V_40 = F_142 ( V_213 ,
args -> V_212 . V_54 ,
V_210 , V_211 , V_9 ) ;
if ( ! V_40 ) {
F_52 ( args -> V_212 . V_210 , V_210 ,
V_40 , V_211 ) ;
if ( V_40 ) {
V_40 = - V_5 ;
F_143 ( V_213 ,
V_210 , V_211 , V_9 ) ;
}
}
F_53 ( V_210 ) ;
return V_40 ;
}
T_2 F_144 ( union V_7 * args , void * V_9 )
{
struct V_207 * V_213 ;
F_140 ( & V_213 , V_9 , args -> V_216 . V_214 ) ;
if ( ! V_213 )
return - V_5 ;
return F_145 ( V_213 , V_9 ) ;
}
T_2 F_146 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
T_3 * * V_210 = NULL ;
T_2 V_211 = args -> V_217 . V_211 ;
struct V_207 * V_213 ;
F_140 ( & V_213 , V_9 ,
args -> V_217 . V_214 ) ;
if ( ! V_213 )
return - V_5 ;
if ( V_211 > V_215 )
return - V_25 ;
V_210 = F_50 ( ( V_211 * sizeof( T_3 * ) ) , V_58 ) ;
if ( V_210 == NULL )
return - V_59 ;
F_57 ( V_210 , args -> V_217 . V_210 , V_40 ,
V_211 ) ;
if ( ! V_40 )
V_40 = F_143 ( V_213 ,
V_210 , V_211 , V_9 ) ;
F_52 ( args -> V_217 . V_210 , V_210 , V_40 ,
V_211 ) ;
F_53 ( V_210 ) ;
return V_40 ;
}
T_2 T_4 F_147 ( union V_7 * args ,
void * V_9 )
{
F_9 ( L_5 , V_12 ) ;
return - V_218 ;
}
T_2 F_148 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_219 V_220 ;
struct V_221 V_222 ;
struct V_221 * V_131 ;
struct V_207 * V_213 ;
F_140 ( & V_213 , V_9 ,
args -> V_223 . V_214 ) ;
if ( ! V_213 )
return - V_5 ;
F_57 ( & V_220 , args -> V_223 . V_219 , V_40 , 1 ) ;
V_131 = V_220 . V_224 ;
V_220 . V_224 = & V_222 ;
if ( ! V_40 ) {
V_40 = F_149 ( V_213 -> V_214 ,
& V_220 ,
args -> V_223 .
V_225 ) ;
}
F_52 ( V_131 , V_220 . V_224 , V_40 , 1 ) ;
V_220 . V_224 = V_131 ;
F_52 ( args -> V_223 . V_219 , & V_220 , V_40 , 1 ) ;
return V_40 ;
}
T_2 F_150 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
struct V_207 * V_213 ;
F_140 ( & V_213 , V_9 , args -> V_226 . V_214 ) ;
if ( ! V_213 )
return - V_5 ;
V_27 = F_151 ( V_213 -> V_214 , args -> V_226 . V_227 ) ;
return V_27 ;
}
T_2 F_152 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_207 * V_213 ;
F_140 ( & V_213 , V_9 , args -> V_228 . V_214 ) ;
if ( ! V_213 )
return - V_5 ;
if ( ! args -> V_228 . V_171 )
return - V_5 ;
V_40 = F_153 ( V_213 -> V_214 ,
args -> V_228 . V_171 ,
args -> V_228 . V_4 ,
args -> V_228 . V_229 ,
args -> V_228 . V_230 ) ;
return V_40 ;
}
T_2 F_154 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_231 V_168 ;
struct V_207 * V_232 ;
struct V_233 V_234 ;
struct V_155 * V_161 ;
int V_235 ;
F_106 ( & V_161 , V_9 , args -> V_236 . V_165 ) ;
if ( ! V_161 )
return - V_5 ;
F_57 ( & V_168 , args -> V_236 . V_90 , V_40 , 1 ) ;
if ( V_168 . V_237 != NULL ) {
F_57 ( & V_234 , V_168 . V_237 , V_40 , 1 ) ;
if ( ! V_40 ) {
V_168 . V_237 = & V_234 ;
if ( V_168 . V_237 -> V_238 == V_239 )
return - V_218 ;
}
}
V_40 = F_155 ( V_161 -> V_165 ,
args -> V_236 . V_240 ,
args -> V_236 . V_82 , & V_168 , & V_232 ,
V_9 ) ;
if ( ! V_40 ) {
V_235 = V_232 -> V_164 + 1 ;
F_52 ( args -> V_236 . V_214 , & V_235 , V_40 , 1 ) ;
}
return V_40 ;
}
T_2 F_156 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
T_3 * V_241 ;
T_2 V_242 ;
T_2 V_243 ;
T_2 V_244 ;
struct V_207 * V_213 ;
F_140 ( & V_213 , V_9 , args -> V_245 . V_214 ) ;
if ( ! V_213 )
return - V_5 ;
V_40 = F_157 ( V_213 -> V_214 , & V_241 ,
& V_242 , & V_244 , & V_243 ) ;
F_52 ( args -> V_245 . V_241 , & V_241 , V_40 , 1 ) ;
F_52 ( args -> V_245 . V_4 , & V_242 , V_40 , 1 ) ;
F_52 ( args -> V_245 . V_230 , & V_243 , V_40 , 1 ) ;
if ( args -> V_245 . V_246 != NULL ) {
F_52 ( args -> V_245 . V_246 , & V_244 ,
V_40 , 1 ) ;
}
return V_40 ;
}
T_2 F_158 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_78 V_144 ;
struct V_207 * V_213 ;
F_140 ( & V_213 , V_9 ,
args -> V_247 . V_214 ) ;
if ( ! V_213 )
return - V_5 ;
V_144 . V_145 = NULL ;
V_144 . V_85 = NULL ;
V_40 = F_159 ( V_213 -> V_214 ,
args -> V_247 . V_147 ,
args -> V_247 .
V_148 , & V_144 ) ;
F_52 ( args -> V_247 . V_144 , & V_144 ,
V_40 , 1 ) ;
return V_40 ;
}
T_2 F_160 ( union V_7 * args , void * V_9 )
{
T_2 V_248 ;
struct V_249 * V_250 [ V_251 ] ;
int V_40 = 0 ;
struct V_207 * V_213 ;
int * V_252 [ V_251 ] ;
int V_10 ;
if ( args -> V_253 . V_254 > V_251 )
return - V_25 ;
F_57 ( V_252 , args -> V_253 . V_255 , V_40 ,
args -> V_253 . V_254 ) ;
if ( V_40 )
return V_40 ;
for ( V_10 = 0 ; V_10 < args -> V_253 . V_254 ; V_10 ++ ) {
F_140 ( & V_213 , V_9 , V_252 [ V_10 ] ) ;
if ( ! V_213 )
return - V_5 ;
V_250 [ V_10 ] = V_213 -> V_214 ;
}
if ( ! V_40 ) {
V_40 = F_161 ( V_250 , args -> V_253 . V_254 ,
& V_248 , args -> V_253 . V_86 ) ;
}
F_52 ( args -> V_253 . V_248 , & V_248 , V_40 , 1 ) ;
return V_40 ;
}
T_2 T_4 F_162 ( union V_7 * args , void * V_9 )
{
F_9 ( L_5 , V_12 ) ;
return - V_218 ;
}
T_2 T_4 F_163 ( union V_7 * args , void * V_9 )
{
F_9 ( L_5 , V_12 ) ;
return - V_218 ;
}
T_2 F_164 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_256 * V_257 ;
void * V_97 = ( (struct V_98 * ) V_9 ) -> V_87 ;
V_40 = F_165 ( V_97 , & V_257 ) ;
F_52 ( args -> V_258 . V_259 , & V_257 , V_40 , 1 ) ;
return V_40 ;
}
T_2 F_166 ( union V_7 * args , void * V_9 )
{
int V_40 = 0 ;
struct V_260 V_261 ;
V_40 = F_167 ( args -> V_262 . V_259 , & V_261 ) ;
F_52 ( args -> V_262 . V_261 , & V_261 , V_40 ,
1 ) ;
return V_40 ;
}
