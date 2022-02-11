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
V_26 -- ;
if ( V_26 == 0 )
F_15 () ;
}
bool F_16 ( void )
{
bool V_27 = true ;
if ( V_26 == 0 )
V_27 = F_17 () ;
if ( V_27 )
V_26 ++ ;
return V_27 ;
}
int F_18 ( void )
{
int V_28 = 0 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
T_3 V_35 ;
for ( V_32 = F_19 () ; V_32 != NULL ;
V_32 = F_20 ( V_32 ) ) {
if ( F_21 ( V_32 , & V_30 ) )
continue;
if ( F_22 ( V_32 , & V_35 ) )
continue;
if ( ( V_35 == V_36 ) || ( V_35 == V_37 ) ) {
V_34 = F_23 ( V_38 ) ;
if ( V_34 && V_34 -> V_39 )
F_24 ( V_30 , V_32 ) ;
}
}
return V_28 ;
}
T_2 F_25 ( union V_7 * args , void * V_9 )
{
T_3 * V_40 ;
T_2 V_41 ;
int V_28 = 0 ;
T_2 V_42 = args -> V_43 . V_44 ;
if ( V_42 < sizeof( struct V_45 ) )
return - V_25 ;
V_40 = F_26 ( V_42 , V_46 ) ;
if ( V_40 == NULL )
V_28 = - V_47 ;
if ( ! V_28 ) {
V_28 =
F_27 ( args -> V_43 . V_48 ,
(struct V_45 * ) V_40 , V_42 ,
& V_41 ) ;
}
F_28 ( args -> V_43 . V_49 , V_40 , V_28 ,
V_42 ) ;
F_28 ( args -> V_43 . V_41 , & V_41 , V_28 ,
1 ) ;
F_29 ( V_40 ) ;
return V_28 ;
}
T_2 F_30 ( union V_7 * args , void * V_9 )
{
T_3 * V_50 ;
T_3 V_51 ;
int V_28 = 0 ;
T_2 V_42 = args -> V_52 . V_53 ;
if ( V_42 < sizeof( struct V_54 ) )
return - V_25 ;
V_50 = F_26 ( V_42 , V_46 ) ;
if ( V_50 == NULL )
V_28 = - V_47 ;
if ( ! V_28 ) {
V_28 =
F_31 ( args -> V_52 .
V_55 ,
(struct V_54 * )
V_50 , V_42 , & V_51 ) ;
}
F_28 ( args -> V_52 . V_50 , V_50 ,
V_28 , V_42 ) ;
F_28 ( args -> V_52 . V_51 , & V_51 ,
V_28 , 1 ) ;
F_29 ( V_50 ) ;
return V_28 ;
}
T_2 F_32 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
struct V_56 V_57 ;
T_2 V_58 = 0 ;
char * V_59 = NULL ;
int V_28 = 0 ;
F_33 ( & V_57 , args -> V_60 . V_57 , V_28 , 1 ) ;
if ( V_28 )
goto V_61;
V_58 = F_34 ( ( char * )
args -> V_60 . V_62 ) ;
if ( ! V_58 ) {
V_28 = - V_25 ;
goto V_61;
}
V_59 = F_26 ( V_58 , V_46 ) ;
if ( ! V_59 ) {
V_28 = - V_47 ;
goto V_61;
}
V_27 = F_35 ( V_59 ,
( char * ) args -> V_60 .
V_62 , V_58 ) ;
if ( ! V_27 ) {
V_28 = - V_5 ;
goto V_61;
}
if ( args -> V_60 . V_63 >= V_64 ) {
V_28 = - V_25 ;
goto V_61;
}
V_28 = F_36 ( & V_57 ,
args -> V_60 . V_63 ,
( char * ) V_59 ) ;
V_61:
F_29 ( V_59 ) ;
return V_28 ;
}
T_2 F_37 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_56 V_57 ;
F_33 ( & V_57 , args -> V_60 . V_57 , V_28 , 1 ) ;
if ( V_28 )
goto V_61;
V_28 = F_38 ( & V_57 ,
args -> V_65 .
V_63 ) ;
V_61:
return V_28 ;
}
T_2 F_39 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_66 * V_67 [ V_68 ] ;
struct V_66 V_69 [ V_68 ] ;
T_2 V_70 , V_10 ;
T_2 V_71 = args -> V_72 . V_71 ;
if ( V_71 > V_68 )
V_28 = - V_25 ;
F_33 ( V_67 , args -> V_72 . V_67 ,
V_28 , V_71 ) ;
for ( V_10 = 0 ; V_10 < V_71 ; V_10 ++ ) {
F_33 ( & V_69 [ V_10 ] , V_67 [ V_10 ] , V_28 , 1 ) ;
if ( V_28 || ! V_69 [ V_10 ] . V_73 ) {
V_28 = - V_25 ;
break;
}
V_67 [ V_10 ] = & V_69 [ V_10 ] ;
}
if ( ! V_28 ) {
V_28 = F_40 ( V_67 , V_71 ,
& V_70 ,
args -> V_72 .
V_74 ) ;
}
F_28 ( args -> V_72 . V_70 , & V_70 , V_28 , 1 ) ;
return V_28 ;
}
T_2 T_4 F_41 ( union V_7 * args ,
void * V_9 )
{
F_9 ( L_5 , V_12 ) ;
return 0 ;
}
T_2 F_42 ( union V_7 * args , void * V_9 )
{
void * V_75 ;
int V_28 = 0 ;
struct V_76 V_77 , * V_78 = NULL ;
if ( args -> V_79 . V_78 ) {
F_33 ( & V_77 , args -> V_79 . V_78 , V_28 ,
1 ) ;
if ( ! V_28 )
V_78 = & V_77 ;
else
goto V_61;
}
V_28 = F_43 ( args -> V_79 . V_55 , V_78 ,
& V_75 , V_9 ) ;
F_28 ( args -> V_79 . V_80 , & V_75 , V_28 , 1 ) ;
V_61:
return V_28 ;
}
T_2 F_44 ( union V_7 * args , void * V_9 )
{
T_2 V_81 , T_1 * V_82 = ( T_2 T_1 * )
args -> V_83 . args ;
T_3 * V_84 = NULL ;
int V_28 = 0 ;
void * V_85 = ( (struct V_86 * ) V_9 ) -> V_75 ;
if ( V_82 ) {
if ( F_45 ( V_81 , V_82 ) ) {
V_28 = - V_87 ;
goto V_61;
}
V_81 += sizeof( T_2 ) ;
V_84 = F_26 ( V_81 , V_46 ) ;
if ( V_84 == NULL ) {
V_28 = - V_47 ;
goto V_61;
}
F_33 ( V_84 , args -> V_83 . args , V_28 ,
V_81 ) ;
}
if ( ! V_28 ) {
V_28 = F_46 ( V_85 ,
args -> V_83 . V_6 ,
(struct V_88 * ) V_84 ) ;
}
F_29 ( V_84 ) ;
V_61:
return V_28 ;
}
T_2 T_4 F_47 ( union V_7 * args , void * V_9 )
{
F_9 ( L_5 , V_12 ) ;
return 0 ;
}
T_2 F_48 ( union V_7 * args , void * V_9 )
{
int V_28 ;
void * V_89 [ V_90 ] ;
T_2 V_41 ;
T_2 V_91 ;
void * V_85 = ( (struct V_86 * ) V_9 ) -> V_75 ;
if ( ! args -> V_92 . V_93 )
return - V_25 ;
V_28 = F_49 ( V_85 ,
V_89 ,
args -> V_92 . V_93 ,
& V_41 , & V_91 ) ;
F_28 ( args -> V_92 . V_89 , V_89 , V_28 ,
V_41 ) ;
F_28 ( args -> V_92 . V_41 , & V_41 ,
V_28 , 1 ) ;
F_28 ( args -> V_92 . V_94 , & V_91 ,
V_28 , 1 ) ;
return V_28 ;
}
T_2 F_50 ( union V_7 * args , void * V_9 )
{
int V_28 ;
if ( args -> V_95 . V_96 >= V_97 )
return - V_25 ;
V_28 = F_51 ( V_9 ,
args -> V_95 . V_98 ,
args -> V_95 . V_42 ,
args -> V_95 . V_96 ) ;
return V_28 ;
}
T_2 F_52 ( union V_7 * args , void * V_9 )
{
int V_28 ;
if ( args -> V_95 . V_96 >= V_97 )
return - V_25 ;
V_28 = F_53 ( V_9 ,
args -> V_95 . V_98 ,
args -> V_95 . V_42 ,
args -> V_95 . V_96 ) ;
return V_28 ;
}
T_2 F_54 ( union V_7 * args , void * V_9 )
{
int V_28 ;
if ( args -> V_99 . V_100 >
V_101 )
return - V_25 ;
V_28 = F_55 ( V_9 ,
args -> V_99 . V_98 ,
args -> V_99 . V_42 ,
args -> V_99 . V_100 ) ;
return V_28 ;
}
T_2 F_56 ( union V_7 * args , void * V_9 )
{
int V_28 ;
V_28 =
F_57 ( V_9 ,
args -> V_102 . V_98 ,
args -> V_102 . V_42 ) ;
return V_28 ;
}
T_2 F_58 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_103 V_104 ;
void * V_85 = ( (struct V_86 * ) V_9 ) -> V_75 ;
if ( args -> V_105 . V_106 <
sizeof( struct V_103 ) )
return - V_25 ;
V_28 =
F_59 ( V_85 ,
args -> V_105 . V_107 ,
& V_104 ,
args -> V_105 .
V_106 ) ;
F_28 ( args -> V_105 . V_104 , & V_104 ,
V_28 , 1 ) ;
return V_28 ;
}
T_2 F_60 ( union V_7 * args , void * V_9 )
{
int V_28 ;
struct V_108 V_109 ;
void * V_85 = ( (struct V_86 * ) V_9 ) -> V_75 ;
if ( args -> V_110 . V_111 <
sizeof( struct V_108 ) )
return - V_25 ;
V_28 = F_61 ( V_85 , & V_109 ,
args -> V_110 . V_111 ) ;
F_28 ( args -> V_110 . V_112 , & V_109 , V_28 ,
1 ) ;
return V_28 ;
}
T_2 F_62 ( union V_7 * args , void * V_9 )
{
int V_28 ;
T_3 * V_113 ;
void * V_85 = ( (struct V_86 * ) V_9 ) -> V_75 ;
if ( args -> V_114 . V_115 > V_116 )
return - V_25 ;
V_113 = F_63 ( args -> V_114 . V_115 , V_46 ) ;
if ( V_113 != NULL ) {
V_28 = F_64 ( V_85 , V_113 ,
args -> V_114 . V_115 ) ;
} else {
V_28 = - V_47 ;
}
F_28 ( args -> V_114 . V_117 , V_113 , V_28 ,
args -> V_114 . V_115 ) ;
F_29 ( V_113 ) ;
return V_28 ;
}
T_2 F_65 ( union V_7 * args , void * V_9 )
{
T_5 V_10 , V_118 ;
int V_28 = 0 ;
char * V_119 ;
T_5 V_71 = args -> V_120 . V_121 ;
T_3 * * V_122 = NULL , * * V_123 = NULL ;
void * V_85 = ( (struct V_86 * ) V_9 ) -> V_75 ;
if ( V_71 <= 0 || V_71 > V_124 ) {
V_28 = - V_25 ;
goto V_125;
}
V_122 = F_26 ( V_71 * sizeof( T_3 * ) , V_46 ) ;
if ( ! V_122 ) {
V_28 = - V_47 ;
goto V_125;
}
F_33 ( V_122 , args -> V_120 . V_126 , V_28 , V_71 ) ;
if ( V_28 ) {
F_29 ( V_122 ) ;
V_122 = NULL ;
goto V_125;
}
for ( V_10 = 0 ; V_10 < V_71 ; V_10 ++ ) {
if ( V_122 [ V_10 ] ) {
V_119 = ( char * ) V_122 [ V_10 ] ;
V_118 = F_34 ( ( char * ) V_119 ) + 1 ;
V_122 [ V_10 ] = F_26 ( V_118 , V_46 ) ;
if ( V_122 [ V_10 ] ) {
F_33 ( V_122 [ V_10 ] , V_119 , V_28 , V_118 ) ;
if ( V_28 ) {
F_29 ( V_122 [ V_10 ] ) ;
V_122 [ V_10 ] = NULL ;
goto V_125;
}
} else {
V_28 = - V_47 ;
goto V_125;
}
}
}
if ( args -> V_120 . V_127 ) {
V_71 = 0 ;
do {
if ( F_45 ( V_119 ,
args -> V_120 . V_127 + V_71 ) ) {
V_28 = - V_5 ;
goto V_125;
}
V_71 ++ ;
} while ( V_119 );
V_123 = F_26 ( V_71 * sizeof( T_3 * ) , V_46 ) ;
if ( ! V_123 ) {
V_28 = - V_47 ;
goto V_125;
}
F_33 ( V_123 , args -> V_120 . V_127 , V_28 , V_71 ) ;
if ( V_28 ) {
F_29 ( V_123 ) ;
V_123 = NULL ;
goto V_125;
}
for ( V_10 = 0 ; V_123 [ V_10 ] ; V_10 ++ ) {
V_119 = ( char * ) V_123 [ V_10 ] ;
V_118 = F_34 ( ( char * ) V_119 ) + 1 ;
V_123 [ V_10 ] = F_26 ( V_118 , V_46 ) ;
if ( V_123 [ V_10 ] ) {
F_33 ( V_123 [ V_10 ] , V_119 , V_28 , V_118 ) ;
if ( V_28 ) {
F_29 ( V_123 [ V_10 ] ) ;
V_123 [ V_10 ] = NULL ;
goto V_125;
}
} else {
V_28 = - V_47 ;
goto V_125;
}
}
}
if ( ! V_28 ) {
V_28 = F_66 ( V_85 ,
args -> V_120 . V_121 ,
( const char * * ) V_122 , ( const char * * ) V_123 ) ;
}
V_125:
if ( V_123 ) {
V_10 = 0 ;
while ( V_123 [ V_10 ] )
F_29 ( V_123 [ V_10 ++ ] ) ;
F_29 ( V_123 ) ;
}
if ( V_122 ) {
V_71 = args -> V_120 . V_121 ;
for ( V_10 = 0 ; ( V_10 < V_71 ) && V_122 [ V_10 ] ; V_10 ++ )
F_29 ( V_122 [ V_10 ] ) ;
F_29 ( V_122 ) ;
}
return V_28 ;
}
T_2 F_67 ( union V_7 * args , void * V_9 )
{
int V_28 ;
void * V_128 ;
void * V_85 = ( (struct V_86 * ) V_9 ) -> V_75 ;
if ( ! args -> V_129 . V_42 )
return - V_25 ;
V_28 = F_68 ( args -> V_129 . V_75 ,
args -> V_129 . V_98 ,
args -> V_129 . V_42 ,
args -> V_129 . V_130 , & V_128 ,
args -> V_129 . V_131 , V_9 ) ;
if ( ! V_28 ) {
if ( F_69 ( V_128 , args -> V_129 . V_128 ) ) {
V_28 = - V_25 ;
F_70 ( V_85 , V_128 , V_9 ) ;
}
}
return V_28 ;
}
T_2 F_71 ( union V_7 * args , void * V_9 )
{
int V_28 ;
struct V_66 V_132 ;
void * V_85 = ( (struct V_86 * ) V_9 ) -> V_75 ;
V_132 . V_133 = NULL ;
V_132 . V_73 = NULL ;
V_28 = F_72 ( V_85 ,
args -> V_134 . V_135 ,
args -> V_134 . V_136 ,
& V_132 ) ;
F_28 ( args -> V_134 . V_132 , & V_132 ,
V_28 , 1 ) ;
return V_28 ;
}
T_2 F_73 ( union V_7 * args , void * V_9 )
{
int V_28 ;
void * V_137 ;
void * V_85 = ( (struct V_86 * ) V_9 ) -> V_75 ;
if ( ( args -> V_138 . V_42 <= 0 ) ||
( args -> V_138 . V_42 & ( V_139 - 1 ) ) != 0 )
return - V_25 ;
V_28 = F_74 ( V_85 ,
args -> V_138 . V_42 , & V_137 ,
V_9 ) ;
if ( ! V_28 ) {
if ( F_69 ( V_137 , args -> V_138 . V_140 ) ) {
V_28 = - V_25 ;
F_75 ( args -> V_138 .
V_75 , V_137 , V_9 ) ;
}
}
return V_28 ;
}
T_2 F_76 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
V_27 = F_77 ( ( (struct V_86 * ) V_9 ) -> V_75 ) ;
return V_27 ;
}
T_2 F_78 ( union V_7 * args , void * V_9 )
{
int V_28 ;
V_28 = F_70 ( ( (struct V_86 * ) V_9 ) -> V_75 ,
args -> V_141 . V_128 , V_9 ) ;
return V_28 ;
}
T_2 F_79 ( union V_7 * args , void * V_9 )
{
int V_28 ;
void * V_85 = ( (struct V_86 * ) V_9 ) -> V_75 ;
V_28 = F_75 ( V_85 ,
args -> V_142 . V_140 ,
V_9 ) ;
return V_28 ;
}
T_2 F_80 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
V_27 = F_81 ( ( (struct V_86 * ) V_9 ) -> V_75 ) ;
return V_27 ;
}
inline void F_82 ( struct V_143 * * V_144 ,
void * V_9 , void * V_145 )
{
F_83 () ;
* V_144 = F_84 ( ( (struct V_86 * ) V_9 ) -> V_48 ,
( int ) V_145 - 1 ) ;
F_85 () ;
return;
}
T_2 F_86 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_56 V_146 ;
T_2 V_81 = 0 ;
T_2 T_1 * V_82 = ( T_2 T_1 * ) args -> V_147 . args ;
T_3 * V_84 = NULL ;
struct V_148 V_77 , * V_78 = NULL ;
struct V_143 * V_149 ;
int V_150 ;
void * V_85 = ( (struct V_86 * ) V_9 ) -> V_75 ;
if ( V_82 ) {
if ( F_45 ( V_81 , V_82 ) )
V_28 = - V_87 ;
V_81 += sizeof( T_2 ) ;
if ( ! V_28 ) {
V_84 = F_26 ( V_81 , V_46 ) ;
if ( V_84 == NULL )
V_28 = - V_47 ;
}
F_33 ( V_84 , args -> V_147 . args , V_28 ,
V_81 ) ;
}
F_33 ( & V_146 , args -> V_147 . V_151 , V_28 , 1 ) ;
if ( V_28 )
goto V_125;
if ( args -> V_147 . V_78 ) {
F_33 ( & V_77 , args -> V_147 . V_78 ,
V_28 , 1 ) ;
if ( ! V_28 )
V_78 = & V_77 ;
else
V_28 = - V_47 ;
}
if ( ! V_28 ) {
V_28 = F_87 ( V_85 ,
& V_146 , (struct V_88 * ) V_84 ,
V_78 , & V_149 , V_9 ) ;
}
if ( ! V_28 ) {
V_150 = V_149 -> V_152 + 1 ;
F_28 ( args -> V_147 . V_153 , & V_150 ,
V_28 , 1 ) ;
if ( V_28 ) {
V_28 = - V_5 ;
F_88 ( V_149 , V_9 ) ;
}
}
V_125:
F_29 ( V_84 ) ;
return V_28 ;
}
T_2 F_89 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_154 * V_155 = NULL ;
struct V_154 V_156 ;
T_3 * V_157 = NULL ;
struct V_143 * V_149 ;
F_82 ( & V_149 , V_9 ,
args -> V_158 . V_153 ) ;
if ( ! V_149 )
return - V_5 ;
if ( ! args -> V_158 . V_42 )
return - V_25 ;
if ( args -> V_158 . V_156 ) {
F_33 ( & V_156 , args -> V_158 . V_156 , V_28 , 1 ) ;
if ( ! V_28 )
V_155 = & V_156 ;
}
F_33 ( & V_157 , args -> V_158 . V_159 , V_28 , 1 ) ;
if ( ! V_28 ) {
V_28 = F_90 ( V_149 -> V_153 ,
args -> V_158 . V_42 ,
V_155 , & V_157 ) ;
}
F_28 ( args -> V_158 . V_159 , & V_157 , V_28 , 1 ) ;
return V_28 ;
}
T_2 F_91 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
struct V_143 * V_149 ;
F_82 ( & V_149 , V_9 ,
args -> V_160 . V_153 ) ;
if ( ! V_149 )
return - V_5 ;
V_27 = F_92 ( V_149 -> V_153 ,
args -> V_160 . V_161 ) ;
return V_27 ;
}
T_2 F_93 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_162 V_163 ;
struct V_162 * V_164 = NULL ;
T_2 V_81 ;
T_2 T_1 * V_82 = ( T_2 T_1 * ) args -> V_165 . V_166 ;
T_3 * V_84 = NULL ;
struct V_143 * V_167 , * V_168 ;
struct V_169 * V_170 = NULL , * V_171 = NULL ;
if ( ( int ) args -> V_165 . V_153 != V_172 ) {
F_82 ( & V_167 , V_9 ,
args -> V_165 . V_153 ) ;
if ( V_167 )
V_170 = V_167 -> V_153 ;
} else {
V_170 = args -> V_165 . V_153 ;
}
if ( ( int ) args -> V_165 . V_173 != V_172 ) {
F_82 ( & V_168 , V_9 ,
args -> V_165 . V_173 ) ;
if ( V_168 )
V_171 = V_168 -> V_153 ;
} else {
V_171 = args -> V_165 . V_173 ;
}
if ( ! V_170 || ! V_171 )
return - V_5 ;
if ( V_82 ) {
if ( F_45 ( V_81 , V_82 ) )
V_28 = - V_87 ;
V_81 += sizeof( T_2 ) ;
if ( ! V_28 ) {
V_84 = F_26 ( V_81 , V_46 ) ;
if ( V_84 == NULL ) {
V_28 = - V_47 ;
goto V_125;
}
}
F_33 ( V_84 , args -> V_165 . V_166 , V_28 ,
V_81 ) ;
if ( V_28 )
goto V_125;
}
if ( args -> V_165 . V_163 ) {
F_33 ( & V_163 , args -> V_165 . V_163 , V_28 , 1 ) ;
if ( ! V_28 )
V_164 = & V_163 ;
}
if ( ! V_28 ) {
V_28 = F_94 ( V_170 ,
args -> V_165 . V_174 ,
V_171 ,
args -> V_165 . V_175 ,
V_164 , (struct V_88 * ) V_84 ) ;
}
V_125:
F_29 ( V_84 ) ;
return V_28 ;
}
T_2 F_95 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
struct V_143 * V_149 ;
F_82 ( & V_149 , V_9 , args -> V_176 . V_153 ) ;
if ( ! V_149 )
return - V_5 ;
V_27 = F_96 ( V_149 -> V_153 ) ;
return V_27 ;
}
T_2 F_97 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
struct V_143 * V_149 ;
F_82 ( & V_149 , V_9 , args -> V_177 . V_153 ) ;
if ( ! V_149 )
return - V_5 ;
V_27 = F_88 ( V_149 , V_9 ) ;
return V_27 ;
}
T_2 F_98 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_154 * V_155 = NULL ;
struct V_154 V_156 ;
struct V_143 * V_149 ;
F_82 ( & V_149 , V_9 , args -> V_178 . V_153 ) ;
if ( ! V_149 )
return - V_5 ;
if ( args -> V_178 . V_156 ) {
F_33 ( & V_156 , args -> V_178 . V_156 , V_28 , 1 ) ;
if ( ! V_28 )
V_155 = & V_156 ;
}
if ( ! args -> V_178 . V_159 )
return - V_5 ;
if ( ! V_28 ) {
V_28 = F_99 ( V_149 -> V_153 ,
args -> V_178 . V_159 ,
V_155 ) ;
}
return V_28 ;
}
T_2 F_100 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_179 V_156 ;
struct V_143 * V_149 ;
F_82 ( & V_149 , V_9 , args -> V_180 . V_153 ) ;
if ( ! V_149 )
return - V_5 ;
V_28 = F_101 ( V_149 -> V_153 , & V_156 ,
args -> V_180 . V_181 ) ;
F_28 ( args -> V_180 . V_156 , & V_156 , V_28 , 1 ) ;
return V_28 ;
}
T_2 F_102 ( union V_7 * args , void * V_9 )
{
int V_28 ;
struct V_182 V_183 ;
struct V_143 * V_149 ;
F_82 ( & V_149 , V_9 , args -> V_184 . V_153 ) ;
if ( ! V_149 )
return - V_5 ;
V_28 = F_103 ( V_149 -> V_153 , & V_183 ,
args -> V_184 . V_74 ) ;
F_28 ( args -> V_184 . V_185 , & V_183 , V_28 , 1 ) ;
return V_28 ;
}
T_2 F_104 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
struct V_143 * V_149 ;
F_82 ( & V_149 , V_9 , args -> V_186 . V_153 ) ;
if ( ! V_149 )
return - V_5 ;
V_27 = F_105 ( V_149 -> V_153 ) ;
return V_27 ;
}
T_2 F_106 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_182 V_183 ;
struct V_143 * V_149 ;
F_82 ( & V_149 , V_9 , args -> V_187 . V_153 ) ;
if ( ! V_149 )
return - V_5 ;
F_33 ( & V_183 , args -> V_187 . V_185 , V_28 , 1 ) ;
if ( ! V_28 ) {
V_28 =
F_107 ( V_149 -> V_153 , & V_183 ,
args -> V_187 . V_74 ) ;
}
return V_28 ;
}
T_2 F_108 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_66 V_132 ;
struct V_143 * V_149 ;
F_82 ( & V_149 , V_9 ,
args -> V_188 . V_153 ) ;
if ( ! V_149 )
return - V_5 ;
V_132 . V_133 = NULL ;
V_132 . V_73 = NULL ;
if ( ! args -> V_134 . V_135 )
F_33 ( & V_132 ,
args -> V_134 . V_132 ,
V_28 , 1 ) ;
V_28 = F_109 ( V_149 -> V_153 ,
args -> V_188 . V_135 ,
args -> V_188 .
V_136 , & V_132 ) ;
F_28 ( args -> V_188 . V_132 , & V_132 ,
V_28 , 1 ) ;
return V_28 ;
}
T_2 F_110 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
struct V_143 * V_149 ;
F_82 ( & V_149 , V_9 , args -> V_189 . V_153 ) ;
if ( ! V_149 )
return - V_5 ;
V_27 = F_111 ( V_149 -> V_153 ) ;
return V_27 ;
}
T_2 F_112 ( union V_7 * args , void * V_9 )
{
int V_28 ;
int V_190 ;
struct V_143 * V_149 ;
F_82 ( & V_149 , V_9 , args -> V_191 . V_153 ) ;
if ( ! V_149 )
return - V_5 ;
V_28 = F_113 ( V_149 -> V_153 , & V_190 ) ;
F_28 ( args -> V_191 . V_28 , & V_190 , V_28 , 1 ) ;
return V_28 ;
}
T_2 F_114 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_56 V_146 ;
struct V_45 * V_192 = NULL ;
void * V_85 = ( (struct V_86 * ) V_9 ) -> V_75 ;
F_33 ( & V_146 , args -> V_193 . V_151 , V_28 ,
1 ) ;
if ( V_28 )
goto V_125;
V_192 = F_26 ( sizeof( struct V_45 ) , V_46 ) ;
if ( V_192 != NULL ) {
V_28 =
F_115 ( V_85 , & V_146 , V_192 ) ;
F_28 ( args -> V_193 . V_194 , V_192 ,
V_28 , 1 ) ;
} else
V_28 = - V_47 ;
V_125:
F_29 ( V_192 ) ;
return V_28 ;
}
inline void F_116 ( struct V_195 * * V_196 ,
void * V_9 , void * V_197 )
{
F_83 () ;
* V_196 = F_84 ( ( (struct V_86 * ) V_9 ) -> V_174 ,
( int ) V_197 - 1 ) ;
F_85 () ;
return;
}
T_2 F_117 ( union V_7 * args , void * V_9 )
{
int V_28 ;
T_3 * * V_198 = NULL ;
T_2 V_199 = args -> V_200 . V_199 ;
struct V_195 * V_201 ;
F_116 ( & V_201 , V_9 ,
args -> V_200 . V_202 ) ;
if ( ! V_201 )
return - V_5 ;
if ( V_199 > V_203 )
return - V_25 ;
V_198 = F_26 ( ( V_199 * sizeof( T_3 * ) ) , V_46 ) ;
if ( V_198 == NULL )
return - V_47 ;
V_28 = F_118 ( V_201 ,
args -> V_200 . V_42 ,
V_198 , V_199 , V_9 ) ;
if ( ! V_28 ) {
F_28 ( args -> V_200 . V_198 , V_198 ,
V_28 , V_199 ) ;
if ( V_28 ) {
V_28 = - V_5 ;
F_119 ( V_201 ,
V_198 , V_199 , V_9 ) ;
}
}
F_29 ( V_198 ) ;
return V_28 ;
}
T_2 F_120 ( union V_7 * args , void * V_9 )
{
struct V_195 * V_201 ;
F_116 ( & V_201 , V_9 , args -> V_204 . V_202 ) ;
if ( ! V_201 )
return - V_5 ;
return F_121 ( V_201 , V_9 ) ;
}
T_2 F_122 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
T_3 * * V_198 = NULL ;
T_2 V_199 = args -> V_205 . V_199 ;
struct V_195 * V_201 ;
F_116 ( & V_201 , V_9 ,
args -> V_205 . V_202 ) ;
if ( ! V_201 )
return - V_5 ;
if ( V_199 > V_203 )
return - V_25 ;
V_198 = F_123 ( V_199 , sizeof( T_3 * ) , V_46 ) ;
if ( V_198 == NULL )
return - V_47 ;
F_33 ( V_198 , args -> V_205 . V_198 , V_28 ,
V_199 ) ;
if ( ! V_28 )
V_28 = F_119 ( V_201 ,
V_198 , V_199 , V_9 ) ;
F_28 ( args -> V_205 . V_198 , V_198 , V_28 ,
V_199 ) ;
F_29 ( V_198 ) ;
return V_28 ;
}
T_2 T_4 F_124 ( union V_7 * args ,
void * V_9 )
{
F_9 ( L_5 , V_12 ) ;
return - V_206 ;
}
T_2 F_125 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_207 V_208 ;
struct V_209 V_210 ;
struct V_209 * V_119 ;
struct V_195 * V_201 ;
F_116 ( & V_201 , V_9 ,
args -> V_211 . V_202 ) ;
if ( ! V_201 )
return - V_5 ;
F_33 ( & V_208 , args -> V_211 . V_207 , V_28 , 1 ) ;
V_119 = V_208 . V_212 ;
V_208 . V_212 = & V_210 ;
if ( ! V_28 ) {
V_28 = F_126 ( V_201 -> V_202 ,
& V_208 ,
args -> V_211 .
V_213 ) ;
}
F_28 ( V_119 , V_208 . V_212 , V_28 , 1 ) ;
V_208 . V_212 = V_119 ;
F_28 ( args -> V_211 . V_207 , & V_208 , V_28 , 1 ) ;
return V_28 ;
}
T_2 F_127 ( union V_7 * args , void * V_9 )
{
T_2 V_27 ;
struct V_195 * V_201 ;
F_116 ( & V_201 , V_9 , args -> V_214 . V_202 ) ;
if ( ! V_201 )
return - V_5 ;
V_27 = F_128 ( V_201 -> V_202 , args -> V_214 . V_215 ) ;
return V_27 ;
}
T_2 F_129 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_195 * V_201 ;
F_116 ( & V_201 , V_9 , args -> V_216 . V_202 ) ;
if ( ! V_201 )
return - V_5 ;
if ( ! args -> V_216 . V_159 )
return - V_5 ;
V_28 = F_130 ( V_201 -> V_202 ,
args -> V_216 . V_159 ,
args -> V_216 . V_4 ,
args -> V_216 . V_217 ,
args -> V_216 . V_218 ) ;
return V_28 ;
}
T_2 F_131 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_219 V_156 ;
struct V_195 * V_220 ;
struct V_221 V_222 ;
struct V_143 * V_149 ;
int V_223 ;
F_82 ( & V_149 , V_9 , args -> V_224 . V_153 ) ;
if ( ! V_149 )
return - V_5 ;
F_33 ( & V_156 , args -> V_224 . V_78 , V_28 , 1 ) ;
if ( V_156 . V_225 != NULL ) {
F_33 ( & V_222 , V_156 . V_225 , V_28 , 1 ) ;
if ( ! V_28 ) {
V_156 . V_225 = & V_222 ;
if ( V_156 . V_225 -> V_226 == V_227 )
return - V_206 ;
}
}
V_28 = F_132 ( V_149 -> V_153 ,
args -> V_224 . V_228 ,
args -> V_224 . V_70 , & V_156 , & V_220 ,
V_9 ) ;
if ( ! V_28 ) {
V_223 = V_220 -> V_152 + 1 ;
F_28 ( args -> V_224 . V_202 , & V_223 , V_28 , 1 ) ;
}
return V_28 ;
}
T_2 F_133 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
T_3 * V_229 ;
T_2 V_230 ;
T_2 V_231 ;
T_2 V_232 ;
struct V_195 * V_201 ;
F_116 ( & V_201 , V_9 , args -> V_233 . V_202 ) ;
if ( ! V_201 )
return - V_5 ;
V_28 = F_134 ( V_201 -> V_202 , & V_229 ,
& V_230 , & V_232 , & V_231 ) ;
F_28 ( args -> V_233 . V_229 , & V_229 , V_28 , 1 ) ;
F_28 ( args -> V_233 . V_4 , & V_230 , V_28 , 1 ) ;
F_28 ( args -> V_233 . V_218 , & V_231 , V_28 , 1 ) ;
if ( args -> V_233 . V_234 != NULL ) {
F_28 ( args -> V_233 . V_234 , & V_232 ,
V_28 , 1 ) ;
}
return V_28 ;
}
T_2 F_135 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_66 V_132 ;
struct V_195 * V_201 ;
F_116 ( & V_201 , V_9 ,
args -> V_235 . V_202 ) ;
if ( ! V_201 )
return - V_5 ;
V_132 . V_133 = NULL ;
V_132 . V_73 = NULL ;
V_28 = F_136 ( V_201 -> V_202 ,
args -> V_235 . V_135 ,
args -> V_235 .
V_136 , & V_132 ) ;
F_28 ( args -> V_235 . V_132 , & V_132 ,
V_28 , 1 ) ;
return V_28 ;
}
T_2 F_137 ( union V_7 * args , void * V_9 )
{
T_2 V_236 ;
struct V_237 * V_238 [ V_239 ] ;
int V_28 = 0 ;
struct V_195 * V_201 ;
int * V_240 [ V_239 ] ;
int V_10 ;
if ( args -> V_241 . V_242 > V_239 )
return - V_25 ;
F_33 ( V_240 , args -> V_241 . V_243 , V_28 ,
args -> V_241 . V_242 ) ;
if ( V_28 )
return V_28 ;
for ( V_10 = 0 ; V_10 < args -> V_241 . V_242 ; V_10 ++ ) {
F_116 ( & V_201 , V_9 , V_240 [ V_10 ] ) ;
if ( ! V_201 )
return - V_5 ;
V_238 [ V_10 ] = V_201 -> V_202 ;
}
if ( ! V_28 ) {
V_28 = F_138 ( V_238 , args -> V_241 . V_242 ,
& V_236 , args -> V_241 . V_74 ) ;
}
F_28 ( args -> V_241 . V_236 , & V_236 , V_28 , 1 ) ;
return V_28 ;
}
T_2 T_4 F_139 ( union V_7 * args , void * V_9 )
{
F_9 ( L_5 , V_12 ) ;
return - V_206 ;
}
T_2 T_4 F_140 ( union V_7 * args , void * V_9 )
{
F_9 ( L_5 , V_12 ) ;
return - V_206 ;
}
T_2 F_141 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_244 * V_245 ;
void * V_85 = ( (struct V_86 * ) V_9 ) -> V_75 ;
V_28 = F_142 ( V_85 , & V_245 ) ;
F_28 ( args -> V_246 . V_247 , & V_245 , V_28 , 1 ) ;
return V_28 ;
}
T_2 F_143 ( union V_7 * args , void * V_9 )
{
int V_28 = 0 ;
struct V_248 V_249 ;
V_28 = F_144 ( args -> V_250 . V_247 , & V_249 ) ;
F_28 ( args -> V_250 . V_249 , & V_249 , V_28 ,
1 ) ;
return V_28 ;
}
