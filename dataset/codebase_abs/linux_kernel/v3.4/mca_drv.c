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
F_15 () , V_21 -> V_22 , F_16 () ,
V_18 , V_19 , V_7 , V_21 -> V_23 ) ;
F_17 ( & V_24 ) ;
switch ( F_4 ( V_7 ) ) {
case V_15 :
F_14 ( V_25 L_4 , V_7 ) ;
break;
case V_17 :
F_14 ( V_26 L_5 , V_7 ) ;
break;
default:
break;
}
F_18 ( & V_24 ) ;
F_19 ( V_27 ) ;
}
static void
F_20 ( T_3 * V_28 , T_4 * V_29 )
{
T_5 V_30 = V_28 -> V_31 . V_32
+ V_28 -> V_31 . V_33
+ V_28 -> V_31 . V_34
+ V_28 -> V_31 . V_35
+ V_28 -> V_31 . V_36 ;
T_5 V_37 = sizeof( V_38 ) * V_30
+ sizeof( T_3 ) ;
T_5 V_39 = V_28 -> V_31 . V_40 * sizeof( struct V_41 ) ;
F_21 ( V_29 ) = V_28 ;
F_22 ( V_29 ) = (struct V_41 * )
( V_28 -> V_31 . V_40 ? ( ( char * ) V_28 + V_37 ) : NULL ) ;
F_23 ( V_29 ) = ( V_42 * )
( V_28 -> V_31 . V_43 ?
( ( char * ) V_28 + V_37 + V_39 ) : NULL ) ;
}
static int
F_24 ( void * V_44 , T_6 * V_45 )
{
int V_46 = 0 ;
int V_47 = ( ( V_48 * ) V_44 ) -> V_49 ;
T_7 V_50 ;
int V_51 ;
T_8 * V_52 ;
F_25 ( & ( V_45 -> V_53 ) ) ;
F_25 ( & ( V_45 -> V_54 ) ) ;
F_25 ( & ( V_45 -> V_55 ) ) ;
F_25 ( & ( V_45 -> V_56 ) ) ;
F_25 ( & ( V_45 -> V_57 ) ) ;
F_25 ( & ( V_45 -> V_58 ) ) ;
F_25 ( & ( V_45 -> V_59 ) ) ;
F_25 ( & ( V_45 -> V_60 ) ) ;
F_25 ( & ( V_45 -> V_61 ) ) ;
F_25 ( & ( V_45 -> V_62 ) ) ;
V_45 -> V_63 = V_44 ;
for ( V_50 = sizeof( V_48 ) , V_51 = 0 ;
V_50 < V_47 ; V_50 += V_52 -> V_49 , V_51 ++ ) {
V_52 = ( T_8 * ) ( ( char * ) V_44 + V_50 ) ;
if ( ! F_26 ( V_52 -> V_64 , V_65 ) ) {
F_27 ( V_45 -> V_53 , V_52 ) ;
} else if ( ! F_26 ( V_52 -> V_64 ,
V_66 ) ) {
V_46 = 1 ;
F_27 ( V_45 -> V_54 , V_52 ) ;
} else if ( ! F_26 ( V_52 -> V_64 ,
V_67 ) ) {
V_46 = 1 ;
F_27 ( V_45 -> V_55 , V_52 ) ;
} else if ( ! F_26 ( V_52 -> V_64 ,
V_68 ) ) {
V_46 = 1 ;
F_27 ( V_45 -> V_56 , V_52 ) ;
} else if ( ! F_26 ( V_52 -> V_64 ,
V_69 ) ) {
V_46 = 1 ;
F_27 ( V_45 -> V_57 , V_52 ) ;
} else if ( ! F_26 ( V_52 -> V_64 ,
V_70 ) ) {
V_46 = 1 ;
F_27 ( V_45 -> V_58 , V_52 ) ;
} else if ( ! F_26 ( V_52 -> V_64 ,
V_71 ) ) {
V_46 = 1 ;
F_27 ( V_45 -> V_59 , V_52 ) ;
} else if ( ! F_26 ( V_52 -> V_64 ,
V_72 ) ) {
V_46 = 1 ;
F_27 ( V_45 -> V_60 , V_52 ) ;
} else if ( ! F_26 ( V_52 -> V_64 ,
V_73 ) ) {
V_46 = 1 ;
F_27 ( V_45 -> V_61 , V_52 ) ;
} else {
F_27 ( V_45 -> V_62 , V_52 ) ;
}
}
V_45 -> V_74 = V_51 ;
return V_46 ;
}
static int
F_28 ( void )
{
int V_8 ;
int V_75 ;
int V_76 ;
static int V_77 [] = {
sizeof( T_3 )
+ sizeof( V_42 ) ,
sizeof( V_78 ) ,
sizeof( V_79 ) ,
sizeof( V_80 ) ,
sizeof( V_81 ) ,
sizeof( V_82 ) ,
sizeof( V_83 ) ,
sizeof( V_84 ) ,
sizeof( V_85 ) ,
} ;
V_75 = V_86 ;
V_76 = V_77 [ 0 ] ;
for ( V_8 = 1 ; V_8 < sizeof V_77 / sizeof( V_87 ) ; V_8 ++ )
if ( V_76 > V_77 [ V_8 ] )
V_76 = V_77 [ V_8 ] ;
V_88 . V_89 = ( V_75 / V_76 ) * 2 + 1 ;
V_88 . V_44 = ( V_90 * )
F_29 ( V_88 . V_89 * sizeof( V_90 ) , V_91 ) ;
return V_88 . V_44 ? 0 : - V_92 ;
}
static T_9
F_30 ( T_4 * V_29 , T_10 * V_93 ,
struct V_94 * V_95 )
{
T_11 * V_96 =
( T_11 * ) F_31 ( V_29 ) ;
switch ( V_95 -> V_97 ) {
case - 1 :
return V_98 ;
case 0 :
return V_99 ;
case 1 :
case 2 :
default:
break;
}
if ( V_96 -> V_100 || V_96 -> V_101 || V_96 -> V_102 || V_96 -> V_103 )
return V_99 ;
if ( ! V_93 || V_93 -> V_104 )
return V_98 ;
if ( V_93 -> V_105 )
switch ( V_93 -> V_106 ) {
case 0 :
return V_99 ;
case 1 :
case 2 :
case 3 :
return V_98 ;
}
return V_98 ;
}
static T_5
F_32 ( T_4 * V_29 )
{
T_5 V_107 = 0 ;
V_38 * V_108 ;
T_12 * V_109 ;
int V_8 , V_110 = 9 ;
for ( V_8 = 0 ; V_8 < F_33 ( V_29 ) ; V_8 ++ ) {
V_108 = ( V_38 * ) F_34 ( V_29 , V_8 ) ;
if ( V_108 -> V_31 . V_111 && V_108 -> V_111 ) {
V_109 = ( T_12 * ) & ( V_108 -> V_112 ) ;
if ( ! V_107 || ( V_109 -> V_110 < V_110 ) ) {
V_107 = V_108 -> V_111 ;
V_110 = V_109 -> V_110 ;
continue;
}
}
}
if ( V_107 )
return V_107 ;
V_108 = F_35 ( V_29 , 0 ) ;
if ( V_108 && V_108 -> V_31 . V_111 )
return V_108 -> V_111 ;
return 0 ;
}
static int
F_36 ( T_6 * V_45 ,
T_4 * V_29 , T_10 * V_93 ,
struct V_94 * V_95 )
{
T_5 V_111 ;
T_13 * V_113 ;
struct V_114 * V_115 , * V_116 ;
T_14 * V_117 = ( T_14 * ) V_118 ;
V_111 = F_32 ( V_29 ) ;
if ( ! V_111 )
return F_1 ( L_6 ) ;
if ( ! F_23 ( V_29 ) || ! ( F_23 ( V_29 ) -> V_31 . V_119 ) )
return F_1 ( L_7 ) ;
V_115 = (struct V_114 * ) & ( F_37 ( V_29 ) -> V_120 ) ;
V_116 = (struct V_114 * ) & ( F_37 ( V_29 ) -> V_121 ) ;
V_113 = V_95 -> V_122 ;
if ( V_115 -> V_123 != 0 ||
( ( V_116 -> V_123 != 0 ) && F_38 ( V_113 -> V_124 ) ) ) {
V_113 -> V_125 [ 8 - 1 ] = V_111 ;
V_113 -> V_125 [ 9 - 1 ] = V_113 -> V_124 ;
V_113 -> V_125 [ 10 - 1 ] = V_113 -> V_120 ;
V_113 -> V_126 = V_113 -> V_124 ;
V_113 -> V_124 = V_117 -> V_127 ;
V_113 -> V_125 [ 1 - 1 ] = V_117 -> V_128 ;
V_116 = (struct V_114 * ) & V_113 -> V_120 ;
V_116 -> V_123 = 0 ;
V_116 -> V_129 = 0 ;
V_116 -> V_130 = 1 ;
V_116 -> V_8 = 0 ;
return F_3 ( L_8
L_9 ) ;
}
return F_1 ( L_10 ,
V_113 -> V_124 ) ;
}
static int
F_39 ( T_6 * V_45 , T_4 * V_29 ,
T_10 * V_93 ,
struct V_94 * V_95 )
{
int V_131 = 0 ;
T_11 * V_96 =
( T_11 * ) F_31 ( V_29 ) ;
if ( V_96 -> V_132 && V_93 -> V_105 && V_93 -> V_106 == 0 ) {
switch( V_93 -> type ) {
case 1 :
case 3 :
case 9 :
V_131 = F_36 ( V_45 , V_29 , V_93 ,
V_95 ) ;
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
} else if ( V_96 -> V_101 && ! V_96 -> V_132 ) {
V_131 = F_36 ( V_45 , V_29 , V_93 , V_95 ) ;
}
return V_131 ;
}
static int
F_40 ( T_4 * V_29 )
{
V_38 * V_108 ;
T_15 * V_133 ;
V_108 = ( V_38 * ) F_41 ( V_29 , 0 ) ;
V_133 = ( T_15 * ) & ( V_108 -> V_112 ) ;
if ( V_133 -> V_134 == V_135
&& ! ( V_133 -> V_136 || V_133 -> V_137 || V_133 -> V_138 ) )
return F_1 ( L_11 ) ;
return F_3 ( L_12 ) ;
}
static int
F_42 ( int V_139 , T_6 * V_45 ,
T_4 * V_29 , T_10 * V_93 ,
struct V_94 * V_95 )
{
T_11 * V_96 =
( T_11 * ) F_31 ( V_29 ) ;
if ( V_96 -> V_140 == 1 )
return F_3 ( L_13 ) ;
if ( V_96 -> V_141 || V_96 -> V_142 == 0 )
return F_1 ( L_14 ) ;
if ( V_96 -> V_100 && ! ( V_96 -> V_101 || V_96 -> V_132 || V_96 -> V_102 || V_96 -> V_103 ) )
return F_40 ( V_29 ) ;
if ( V_96 -> V_101 == 0 && ( V_96 -> V_132 == 0 || V_93 == NULL ) )
return F_1 ( L_15 ) ;
if ( F_43 ( V_29 ) > 1 )
return F_1 ( L_16 ) ;
if ( V_93 -> V_104 )
return F_1 ( L_17 ) ;
if ( V_93 -> V_105 && V_93 -> V_106 > 0 )
return F_1 ( L_18 ) ;
if ( V_139 )
return F_39 ( V_45 , V_29 , V_93 , V_95 ) ;
return F_1 ( L_19 ) ;
}
static int
F_44 ( void * V_143 , struct V_94 * V_95 )
{
int V_46 ;
int V_144 ;
T_6 V_45 ;
T_4 V_29 ;
T_10 V_93 ;
V_46 = F_24 ( V_143 , & V_45 ) ;
V_144 = F_45 ( & V_45 , V_53 ) ;
if ( V_144 > 1 )
return F_1 ( L_20 ) ;
else if ( V_144 == 0 )
return F_1 ( L_21 ) ;
F_20 ( ( T_3 * )
F_46 ( & V_45 . V_53 ) -> V_145 , & V_29 ) ;
* ( ( T_5 * ) & V_93 ) = F_47 ( & V_29 , V_146 , 0 ) ;
if ( F_30 ( & V_29 , & V_93 , V_95 ) )
return F_1 ( L_22 ) ;
return F_42 ( V_46 , & V_45 , & V_29 ,
& V_93 , V_95 ) ;
}
int T_16 F_48 ( void )
{
if ( F_28 () )
return - V_92 ;
if ( F_49 ( F_44 ) ) {
F_14 ( V_20 L_23 ) ;
F_50 ( V_88 . V_44 ) ;
return - V_147 ;
}
return 0 ;
}
void T_17 F_51 ( void )
{
F_52 () ;
F_50 ( V_88 . V_44 ) ;
}
