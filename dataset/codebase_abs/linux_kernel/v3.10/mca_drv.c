static int
F_1 ( const char * V_1 , ... )
{
T_1 args ;
char V_2 [ 256 ] ;
va_start ( args , V_1 ) ;
vsnprintf ( V_2 , sizeof( V_2 ) , V_1 , args ) ;
va_end ( args ) ;
F_2 ( V_3 L_1 , V_2 ) ;
return V_4 ;
}
static int
F_3 ( const char * V_1 , ... )
{
T_1 args ;
char V_2 [ 256 ] ;
va_start ( args , V_1 ) ;
vsnprintf ( V_2 , sizeof( V_2 ) , V_1 , args ) ;
va_end ( args ) ;
F_2 ( V_5 L_1 , V_2 ) ;
return V_6 ;
}
static T_2
F_4 ( unsigned long V_7 )
{
int V_8 ;
struct V_9 * V_10 ;
if ( ! F_5 ( V_7 ) )
return V_11 ;
if ( ! F_6 ( V_7 >> V_12 ) )
return V_11 ;
V_10 = F_7 ( V_7 >> V_12 ) ;
for ( V_8 = 0 ; V_8 < V_13 ; V_8 ++ )
if ( V_14 [ V_8 ] == V_10 )
return V_15 ;
if ( V_13 == V_16 )
return V_17 ;
if ( F_8 ( V_10 ) || F_9 ( V_10 ) )
return V_17 ;
F_10 ( V_10 ) ;
F_11 ( V_10 ) ;
V_14 [ V_13 ++ ] = V_10 ;
return V_15 ;
}
void
F_12 ( unsigned long V_7 , void * V_18 , unsigned long V_19 )
{
F_13 () ;
F_14 ( V_20 L_2
L_3 ,
F_15 () , V_21 -> V_22 ,
F_16 ( & V_23 , F_17 () ) ,
V_18 , V_19 , V_7 , V_21 -> V_24 ) ;
F_18 ( & V_25 ) ;
switch ( F_4 ( V_7 ) ) {
case V_15 :
F_14 ( V_26 L_4 , V_7 ) ;
break;
case V_17 :
F_14 ( V_27 L_5 , V_7 ) ;
break;
default:
break;
}
F_19 ( & V_25 ) ;
F_20 ( V_28 ) ;
}
static void
F_21 ( T_3 * V_29 , T_4 * V_30 )
{
T_5 V_31 = V_29 -> V_32 . V_33
+ V_29 -> V_32 . V_34
+ V_29 -> V_32 . V_35
+ V_29 -> V_32 . V_36
+ V_29 -> V_32 . V_37 ;
T_5 V_38 = sizeof( V_39 ) * V_31
+ sizeof( T_3 ) ;
T_5 V_40 = V_29 -> V_32 . V_41 * sizeof( struct V_42 ) ;
F_22 ( V_30 ) = V_29 ;
F_23 ( V_30 ) = (struct V_42 * )
( V_29 -> V_32 . V_41 ? ( ( char * ) V_29 + V_38 ) : NULL ) ;
F_24 ( V_30 ) = ( V_43 * )
( V_29 -> V_32 . V_44 ?
( ( char * ) V_29 + V_38 + V_40 ) : NULL ) ;
}
static int
F_25 ( void * V_45 , T_6 * V_46 )
{
int V_47 = 0 ;
int V_48 = ( ( V_49 * ) V_45 ) -> V_50 ;
T_7 V_51 ;
int V_52 ;
T_8 * V_53 ;
F_26 ( & ( V_46 -> V_54 ) ) ;
F_26 ( & ( V_46 -> V_55 ) ) ;
F_26 ( & ( V_46 -> V_56 ) ) ;
F_26 ( & ( V_46 -> V_57 ) ) ;
F_26 ( & ( V_46 -> V_58 ) ) ;
F_26 ( & ( V_46 -> V_59 ) ) ;
F_26 ( & ( V_46 -> V_60 ) ) ;
F_26 ( & ( V_46 -> V_61 ) ) ;
F_26 ( & ( V_46 -> V_62 ) ) ;
F_26 ( & ( V_46 -> V_63 ) ) ;
V_46 -> V_64 = V_45 ;
for ( V_51 = sizeof( V_49 ) , V_52 = 0 ;
V_51 < V_48 ; V_51 += V_53 -> V_50 , V_52 ++ ) {
V_53 = ( T_8 * ) ( ( char * ) V_45 + V_51 ) ;
if ( ! F_27 ( V_53 -> V_65 , V_66 ) ) {
F_28 ( V_46 -> V_54 , V_53 ) ;
} else if ( ! F_27 ( V_53 -> V_65 ,
V_67 ) ) {
V_47 = 1 ;
F_28 ( V_46 -> V_55 , V_53 ) ;
} else if ( ! F_27 ( V_53 -> V_65 ,
V_68 ) ) {
V_47 = 1 ;
F_28 ( V_46 -> V_56 , V_53 ) ;
} else if ( ! F_27 ( V_53 -> V_65 ,
V_69 ) ) {
V_47 = 1 ;
F_28 ( V_46 -> V_57 , V_53 ) ;
} else if ( ! F_27 ( V_53 -> V_65 ,
V_70 ) ) {
V_47 = 1 ;
F_28 ( V_46 -> V_58 , V_53 ) ;
} else if ( ! F_27 ( V_53 -> V_65 ,
V_71 ) ) {
V_47 = 1 ;
F_28 ( V_46 -> V_59 , V_53 ) ;
} else if ( ! F_27 ( V_53 -> V_65 ,
V_72 ) ) {
V_47 = 1 ;
F_28 ( V_46 -> V_60 , V_53 ) ;
} else if ( ! F_27 ( V_53 -> V_65 ,
V_73 ) ) {
V_47 = 1 ;
F_28 ( V_46 -> V_61 , V_53 ) ;
} else if ( ! F_27 ( V_53 -> V_65 ,
V_74 ) ) {
V_47 = 1 ;
F_28 ( V_46 -> V_62 , V_53 ) ;
} else {
F_28 ( V_46 -> V_63 , V_53 ) ;
}
}
V_46 -> V_75 = V_52 ;
return V_47 ;
}
static int
F_29 ( void )
{
int V_8 ;
int V_76 ;
int V_77 ;
static int V_78 [] = {
sizeof( T_3 )
+ sizeof( V_43 ) ,
sizeof( V_79 ) ,
sizeof( V_80 ) ,
sizeof( V_81 ) ,
sizeof( V_82 ) ,
sizeof( V_83 ) ,
sizeof( V_84 ) ,
sizeof( V_85 ) ,
sizeof( V_86 ) ,
} ;
V_76 = V_87 ;
V_77 = V_78 [ 0 ] ;
for ( V_8 = 1 ; V_8 < sizeof V_78 / sizeof( V_88 ) ; V_8 ++ )
if ( V_77 > V_78 [ V_8 ] )
V_77 = V_78 [ V_8 ] ;
V_89 . V_90 = ( V_76 / V_77 ) * 2 + 1 ;
V_89 . V_45 =
F_30 ( V_89 . V_90 * sizeof( V_91 ) , V_92 ) ;
return V_89 . V_45 ? 0 : - V_93 ;
}
static T_9
F_31 ( T_4 * V_30 , T_10 * V_94 ,
struct V_95 * V_96 )
{
T_11 * V_97 =
( T_11 * ) F_32 ( V_30 ) ;
switch ( V_96 -> V_98 ) {
case - 1 :
return V_99 ;
case 0 :
return V_100 ;
case 1 :
case 2 :
default:
break;
}
if ( V_97 -> V_101 || V_97 -> V_102 || V_97 -> V_103 || V_97 -> V_104 )
return V_100 ;
if ( ! V_94 || V_94 -> V_105 )
return V_99 ;
if ( V_94 -> V_106 )
switch ( V_94 -> V_107 ) {
case 0 :
return V_100 ;
case 1 :
case 2 :
case 3 :
return V_99 ;
}
return V_99 ;
}
static T_5
F_33 ( T_4 * V_30 )
{
T_5 V_108 = 0 ;
V_39 * V_109 ;
T_12 * V_110 ;
int V_8 , V_111 = 9 ;
for ( V_8 = 0 ; V_8 < F_34 ( V_30 ) ; V_8 ++ ) {
V_109 = ( V_39 * ) F_35 ( V_30 , V_8 ) ;
if ( V_109 -> V_32 . V_112 && V_109 -> V_112 ) {
V_110 = ( T_12 * ) & ( V_109 -> V_113 ) ;
if ( ! V_108 || ( V_110 -> V_111 < V_111 ) ) {
V_108 = V_109 -> V_112 ;
V_111 = V_110 -> V_111 ;
continue;
}
}
}
if ( V_108 )
return V_108 ;
V_109 = F_36 ( V_30 , 0 ) ;
if ( V_109 && V_109 -> V_32 . V_112 )
return V_109 -> V_112 ;
return 0 ;
}
static int
F_37 ( T_6 * V_46 ,
T_4 * V_30 , T_10 * V_94 ,
struct V_95 * V_96 )
{
T_5 V_112 ;
T_13 * V_114 ;
struct V_115 * V_116 , * V_117 ;
T_14 * V_118 = ( T_14 * ) V_119 ;
V_112 = F_33 ( V_30 ) ;
if ( ! V_112 )
return F_1 ( L_6 ) ;
if ( ! F_24 ( V_30 ) || ! ( F_24 ( V_30 ) -> V_32 . V_120 ) )
return F_1 ( L_7 ) ;
V_116 = (struct V_115 * ) & ( F_38 ( V_30 ) -> V_121 ) ;
V_117 = (struct V_115 * ) & ( F_38 ( V_30 ) -> V_122 ) ;
V_114 = V_96 -> V_123 ;
if ( V_116 -> V_124 != 0 ||
( ( V_117 -> V_124 != 0 ) && F_39 ( V_114 -> V_125 ) ) ) {
V_114 -> V_126 [ 8 - 1 ] = V_112 ;
V_114 -> V_126 [ 9 - 1 ] = V_114 -> V_125 ;
V_114 -> V_126 [ 10 - 1 ] = V_114 -> V_121 ;
V_114 -> V_127 = V_114 -> V_125 ;
V_114 -> V_125 = V_118 -> V_128 ;
V_114 -> V_126 [ 1 - 1 ] = V_118 -> V_129 ;
V_117 = (struct V_115 * ) & V_114 -> V_121 ;
V_117 -> V_124 = 0 ;
V_117 -> V_130 = 0 ;
V_117 -> V_131 = 1 ;
V_117 -> V_8 = 0 ;
return F_3 ( L_8
L_9 ) ;
}
return F_1 ( L_10 ,
V_114 -> V_125 ) ;
}
static int
F_40 ( T_6 * V_46 , T_4 * V_30 ,
T_10 * V_94 ,
struct V_95 * V_96 )
{
int V_132 = 0 ;
T_11 * V_97 =
( T_11 * ) F_32 ( V_30 ) ;
if ( V_97 -> V_133 && V_94 -> V_106 && V_94 -> V_107 == 0 ) {
switch( V_94 -> type ) {
case 1 :
case 3 :
case 9 :
V_132 = F_37 ( V_46 , V_30 , V_94 ,
V_96 ) ;
break;
case 0 :
case 2 :
case 4 :
case 5 :
case 6 :
case 7 :
case 8 :
case 10 :
case 11 :
case 12 :
default:
break;
}
} else if ( V_97 -> V_102 && ! V_97 -> V_133 ) {
V_132 = F_37 ( V_46 , V_30 , V_94 , V_96 ) ;
}
return V_132 ;
}
static int
F_41 ( T_4 * V_30 )
{
V_39 * V_109 ;
T_15 * V_134 ;
V_109 = ( V_39 * ) F_42 ( V_30 , 0 ) ;
V_134 = ( T_15 * ) & ( V_109 -> V_113 ) ;
if ( V_134 -> V_135 == V_136
&& ! ( V_134 -> V_137 || V_134 -> V_138 || V_134 -> V_139 ) )
return F_1 ( L_11 ) ;
return F_3 ( L_12 ) ;
}
static int
F_43 ( int V_140 , T_6 * V_46 ,
T_4 * V_30 , T_10 * V_94 ,
struct V_95 * V_96 )
{
T_11 * V_97 =
( T_11 * ) F_32 ( V_30 ) ;
if ( V_97 -> V_141 == 1 )
return F_3 ( L_13 ) ;
if ( V_97 -> V_142 || V_97 -> V_143 == 0 )
return F_1 ( L_14 ) ;
if ( V_97 -> V_101 && ! ( V_97 -> V_102 || V_97 -> V_133 || V_97 -> V_103 || V_97 -> V_104 ) )
return F_41 ( V_30 ) ;
if ( V_97 -> V_102 == 0 && ( V_97 -> V_133 == 0 || V_94 == NULL ) )
return F_1 ( L_15 ) ;
if ( F_44 ( V_30 ) > 1 )
return F_1 ( L_16 ) ;
if ( V_94 -> V_105 )
return F_1 ( L_17 ) ;
if ( V_94 -> V_106 && V_94 -> V_107 > 0 )
return F_1 ( L_18 ) ;
if ( V_140 )
return F_40 ( V_46 , V_30 , V_94 , V_96 ) ;
return F_1 ( L_19 ) ;
}
static int
F_45 ( void * V_144 , struct V_95 * V_96 )
{
int V_47 ;
int V_145 ;
T_6 V_46 ;
T_4 V_30 ;
T_10 V_94 ;
V_47 = F_25 ( V_144 , & V_46 ) ;
V_145 = F_46 ( & V_46 , V_54 ) ;
if ( V_145 > 1 )
return F_1 ( L_20 ) ;
else if ( V_145 == 0 )
return F_1 ( L_21 ) ;
F_21 ( ( T_3 * )
F_47 ( & V_46 . V_54 ) -> V_146 , & V_30 ) ;
* ( ( T_5 * ) & V_94 ) = F_48 ( & V_30 , V_147 , 0 ) ;
if ( F_31 ( & V_30 , & V_94 , V_96 ) )
return F_1 ( L_22 ) ;
return F_43 ( V_47 , & V_46 , & V_30 ,
& V_94 , V_96 ) ;
}
int T_16 F_49 ( void )
{
if ( F_29 () )
return - V_93 ;
if ( F_50 ( F_45 ) ) {
F_14 ( V_20 L_23 ) ;
F_51 ( V_89 . V_45 ) ;
return - V_148 ;
}
return 0 ;
}
void T_17 F_52 ( void )
{
F_53 () ;
F_51 ( V_89 . V_45 ) ;
}
