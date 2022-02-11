static T_1
F_1 ( T_2 V_1 , T_3 V_2 ,
T_4 * V_3 , T_5 * V_4 ,
void * V_5 )
{
T_6 * V_6 ;
int V_7 ;
F_2 (g_state.local)
V_7 = V_1 -> V_8 ;
while ( ( V_7 - V_1 -> V_9 ) >= V_10 ) {
F_3 ( V_11 ) ;
F_4 ( V_12 ,
L_1 ) ;
F_5 ( V_13 ) ;
if ( F_6 ( & V_1 -> V_14 ) != 0 ) {
F_7 ( V_12 ,
L_2 ) ;
return V_15 ;
} else if ( V_1 -> V_16 ) {
F_7 ( V_12 ,
L_3 ) ;
return V_17 ;
}
F_3 ( V_11 ) ;
}
V_6 = & V_1 -> V_18 [ V_7 & ( V_10 - 1 ) ] ;
V_6 -> V_3 = V_3 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_19 = V_4 -> V_20 ;
V_6 -> V_5 = V_5 ;
if ( V_2 == V_21 ) {
F_8 ( V_4 -> V_20 ) ;
if ( V_1 -> V_22 )
V_4 -> V_23 = 1 ;
}
F_9 () ;
if ( V_2 == V_24 )
V_4 -> V_25 = V_7 ;
V_7 ++ ;
V_1 -> V_8 = V_7 ;
F_10 ( & V_1 -> V_26 ) ;
return V_17 ;
}
static T_1
F_11 ( T_3 V_2 , T_4 * V_3 ,
T_7 V_27 , void * V_5 )
{
T_5 * V_4 ;
T_8 * V_20 ;
T_2 V_1 ;
bool V_28 = false ;
F_2 (g_state.local)
F_3 ( V_11 ) ;
V_20 = F_12 ( V_27 ) ;
F_13 ( ! V_20 ) ;
V_4 = ( T_5 * ) V_20 -> V_29 . V_30 ;
V_1 = V_4 -> V_1 ;
if ( ! V_1 || V_1 -> V_16 )
return V_17 ;
F_4 ( V_12 ,
L_4
L_5 ,
( unsigned long ) V_4 ,
V_20 -> V_31 , V_4 -> V_30 ,
V_2 , ( unsigned long ) V_3 ,
( unsigned long ) V_1 , ( unsigned long ) V_5 ) ;
if ( V_3 && V_4 -> V_32 ) {
F_14 ( & V_33 ) ;
while ( V_4 -> V_34 ==
( V_4 -> V_35 + V_36 ) ) {
F_15 ( & V_33 ) ;
F_3 ( V_11 ) ;
F_5 ( V_37 ) ;
F_4 ( V_12 ,
L_6 ) ;
if ( ( V_4 -> V_25 -
V_1 -> V_9 ) < 0 ) {
T_1 V_38 ;
F_7 ( V_12 ,
L_7 ) ;
F_3 ( V_11 ) ;
V_38 = F_1 ( V_1 , V_2 ,
NULL , V_4 , V_5 ) ;
if ( V_38 != V_17 ) {
F_3 ( V_11 ) ;
return V_38 ;
}
}
F_3 ( V_11 ) ;
if ( F_6 ( & V_4 -> V_14 )
!= 0 ) {
F_7 ( V_12 ,
L_2 ) ;
F_3 ( V_11 ) ;
return V_15 ;
} else if ( V_1 -> V_16 ) {
F_7 ( V_12 ,
L_3 ) ;
F_3 ( V_11 ) ;
return V_39 ;
}
F_3 ( V_11 ) ;
F_14 ( & V_33 ) ;
}
V_4 -> V_40 [ V_4 -> V_34 &
( V_36 - 1 ) ] = V_3 ;
V_4 -> V_34 ++ ;
if ( ( ( V_4 -> V_25 -
V_1 -> V_9 ) >= 0 ) ||
V_4 -> V_41 ) {
V_4 -> V_41 = 0 ;
V_28 = true ;
}
F_15 ( & V_33 ) ;
F_10 ( & V_4 -> V_26 ) ;
V_3 = NULL ;
}
F_3 ( V_11 ) ;
if ( V_28 )
return V_17 ;
return F_1 ( V_1 , V_2 , V_3 , V_4 ,
V_5 ) ;
}
static void
F_16 ( void * V_30 )
{
F_17 ( V_30 ) ;
}
static void F_18 ( T_5 * V_4 )
{
F_7 ( V_12 ,
L_8 ,
V_4 -> V_20 -> V_27 ) ;
if ( V_4 -> V_23 ) {
F_19 ( V_4 -> V_20 ) ;
F_10 ( & V_4 -> V_42 ) ;
V_4 -> V_23 = 0 ;
}
}
static T_9
F_20 (
void * V_43 ,
void * V_44 ,
T_10 V_45 ,
T_10 V_46 )
{
long V_47 ;
T_10 V_48 ;
struct V_49 * V_50 =
(struct V_49 * ) V_43 ;
if ( V_45 != V_50 -> V_51 )
return 0 ;
if ( ! V_50 -> V_52 )
return 0 ;
while ( 1 ) {
V_48 = F_21 ( V_50 -> V_53 -> V_54 -
V_50 -> V_55 ,
V_46 ) ;
if ( V_48 )
break;
V_50 -> V_52 -- ;
V_50 -> V_53 ++ ;
V_50 -> V_55 = 0 ;
if ( ! V_50 -> V_52 )
return 0 ;
}
V_47 = F_22 ( V_44 ,
V_50 -> V_53 -> V_56 +
V_50 -> V_55 ,
V_48 ) ;
if ( V_47 != 0 )
return - V_57 ;
V_50 -> V_55 += V_48 ;
V_50 -> V_51 += V_48 ;
if ( V_50 -> V_55 ==
V_50 -> V_53 -> V_54 ) {
V_50 -> V_52 -- ;
V_50 -> V_53 ++ ;
V_50 -> V_55 = 0 ;
}
return V_48 ;
}
static T_1
F_23 ( T_7 V_27 ,
struct V_58 * V_59 ,
unsigned long V_60 )
{
struct V_49 V_43 ;
unsigned long V_61 ;
T_10 V_62 = 0 ;
V_43 . V_53 = V_59 ;
V_43 . V_55 = 0 ;
V_43 . V_52 = V_60 ;
V_43 . V_51 = 0 ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
if ( ! V_59 [ V_61 ] . V_56 && V_59 [ V_61 ] . V_54 != 0 )
return - V_57 ;
V_62 += V_59 [ V_61 ] . V_54 ;
}
return F_24 ( V_27 , F_20 ,
& V_43 , V_62 ) ;
}
static long
F_25 ( struct V_63 * V_63 , unsigned int V_64 , unsigned long V_65 )
{
T_2 V_1 = V_63 -> V_66 ;
T_1 V_38 = V_17 ;
T_8 * V_20 = NULL ;
long V_67 = 0 ;
int V_61 , V_68 ;
F_2 (g_state.local)
F_4 ( V_12 ,
L_9 ,
V_1 ,
( ( F_26 ( V_64 ) == V_69 ) &&
( F_27 ( V_64 ) <= V_70 ) ) ?
V_71 [ F_27 ( V_64 ) ] : L_10 , V_65 ) ;
switch ( V_64 ) {
case V_72 :
if ( ! V_1 -> V_73 )
break;
V_61 = 0 ;
while ( ( V_20 = F_28 ( V_1 -> V_74 ,
V_1 , & V_61 ) ) != NULL ) {
V_38 = F_29 ( V_20 -> V_27 ) ;
F_19 ( V_20 ) ;
if ( V_38 != V_17 )
break;
}
V_20 = NULL ;
if ( V_38 == V_17 ) {
V_1 -> V_16 = 1 ;
F_10 ( & V_1 -> V_26 ) ;
}
break;
case V_75 :
if ( V_1 -> V_73 ) {
V_67 = - V_76 ;
break;
}
V_68 = F_30 ( & V_1 -> V_74 -> V_77 ) ;
if ( V_68 != 0 ) {
F_31 ( V_12 ,
L_11
L_12 ,
V_1 -> V_74 -> V_78 , V_68 ) ;
V_67 = - V_79 ;
break;
}
V_38 = F_32 ( V_1 -> V_74 , V_1 ) ;
F_33 ( & V_1 -> V_74 -> V_77 ) ;
if ( V_38 == V_17 )
V_1 -> V_73 = 1 ;
else
F_31 ( V_12 ,
L_13 , V_38 ) ;
break;
case V_80 : {
T_11 args ;
T_5 * V_4 = NULL ;
void * V_30 ;
int V_81 ;
if ( F_22
( & args , ( const void V_82 * ) V_65 ,
sizeof( args ) ) != 0 ) {
V_67 = - V_57 ;
break;
}
V_4 = F_34 ( sizeof( T_5 ) , V_83 ) ;
if ( ! V_4 ) {
V_67 = - V_84 ;
break;
}
if ( args . V_85 ) {
if ( ! V_1 -> V_73 ) {
V_67 = - V_86 ;
F_17 ( V_4 ) ;
break;
}
V_81 = V_87 ;
} else {
V_81 =
V_1 -> V_73 ?
V_88 :
V_89 ;
}
V_30 = args . V_90 . V_30 ;
args . V_90 . V_91 = F_11 ;
args . V_90 . V_30 = V_4 ;
V_20 = F_35 (
V_1 -> V_74 ,
& args . V_90 , V_81 ,
V_1 , F_16 ) ;
if ( V_20 != NULL ) {
V_4 -> V_20 = V_20 ;
V_4 -> V_30 = V_30 ;
V_4 -> V_1 = V_1 ;
V_4 -> V_32 = ( args . V_32 != 0 ) ;
V_4 -> V_41 = 0 ;
V_4 -> V_23 = 0 ;
V_4 -> V_25 =
V_1 -> V_9 - 1 ;
V_4 -> V_34 = 0 ;
V_4 -> V_35 = 0 ;
F_36 ( & V_4 -> V_26 , 0 ) ;
F_36 ( & V_4 -> V_14 , 0 ) ;
F_36 ( & V_4 -> V_42 , 0 ) ;
if ( args . V_85 ) {
V_38 = F_37
( V_20 , V_1 -> V_92 ) ;
if ( V_38 != V_17 ) {
F_29 ( V_20 -> V_27 ) ;
V_20 = NULL ;
V_67 = ( V_38 == V_15 ) ?
- V_79 : - V_93 ;
break;
}
}
if ( F_38 ( ( void V_82 * )
& ( ( ( T_11 V_82 * )
V_65 ) -> V_27 ) ,
( const void * ) & V_20 -> V_27 ,
sizeof( V_20 -> V_27 ) ) != 0 ) {
V_67 = - V_57 ;
F_29 ( V_20 -> V_27 ) ;
}
V_20 = NULL ;
} else {
V_67 = - V_94 ;
F_17 ( V_4 ) ;
}
} break;
case V_95 : {
T_7 V_27 = ( T_7 ) V_65 ;
V_20 = F_39 ( V_1 , V_27 ) ;
if ( V_20 != NULL ) {
T_5 * V_4 =
( T_5 * ) V_20 -> V_29 . V_30 ;
if ( ! V_4 -> V_23 ) {
V_38 = F_40 ( V_20 -> V_27 ) ;
if ( V_38 != V_17 )
break;
}
if ( V_4 -> V_23 &&
F_6 ( & V_4 -> V_42 ) )
V_38 = V_15 ;
}
else
V_67 = - V_76 ;
} break;
case V_96 : {
T_7 V_27 = ( T_7 ) V_65 ;
V_20 = F_39 ( V_1 , V_27 ) ;
if ( V_20 != NULL ) {
T_5 * V_4 =
( T_5 * ) V_20 -> V_29 . V_30 ;
if ( ! V_4 -> V_23 ) {
V_38 = F_29 ( V_20 -> V_27 ) ;
if ( V_38 != V_17 )
break;
}
if ( V_4 -> V_23 &&
F_6 ( & V_4 -> V_42 ) )
V_38 = V_15 ;
}
else
V_67 = - V_76 ;
} break;
case V_97 :
case V_98 : {
T_7 V_27 = ( T_7 ) V_65 ;
V_20 = F_39 ( V_1 , V_27 ) ;
if ( V_20 != NULL ) {
V_38 = ( V_64 == V_97 ) ?
F_41 ( V_20 ) :
F_42 ( V_20 ) ;
if ( V_38 != V_17 ) {
F_31 ( V_99 ,
L_14
L_15 ,
V_100 ,
( V_64 == V_97 ) ?
L_16 :
L_17 ,
V_38 ,
F_43 (
V_20 -> V_29 . V_101 ) ,
V_20 -> V_102 ) ;
V_67 = - V_76 ;
}
} else
V_67 = - V_76 ;
} break;
case V_103 : {
T_12 args ;
if ( F_22
( & args , ( const void V_82 * ) V_65 ,
sizeof( args ) ) != 0 ) {
V_67 = - V_57 ;
break;
}
V_20 = F_39 ( V_1 , args . V_27 ) ;
if ( ( V_20 != NULL ) && ( args . V_60 <= V_104 ) ) {
struct V_58 V_59 [ V_104 ] ;
if ( F_22 ( V_59 , args . V_59 ,
args . V_60 * sizeof( struct V_58 ) ) == 0 )
V_38 = F_23
( args . V_27 ,
V_59 , args . V_60 ) ;
else
V_67 = - V_57 ;
} else {
V_67 = - V_76 ;
}
} break;
case V_105 :
case V_106 : {
T_13 args ;
struct V_107 * V_108 = NULL ;
T_14 V_109 =
( V_64 == V_105 ) ?
V_110 : V_111 ;
if ( F_22
( & args , ( const void V_82 * ) V_65 ,
sizeof( args ) ) != 0 ) {
V_67 = - V_57 ;
break;
}
V_20 = F_39 ( V_1 , args . V_27 ) ;
if ( ! V_20 ) {
V_67 = - V_76 ;
break;
}
if ( args . V_112 == V_113 ) {
V_108 = F_44 ( sizeof( struct V_107 ) ,
V_83 ) ;
if ( ! V_108 ) {
V_67 = - V_84 ;
break;
}
args . V_30 = & V_108 -> V_114 ;
} else if ( args . V_112 == V_115 ) {
struct V_116 * V_117 ;
F_45 ( & V_1 -> V_118 ) ;
F_46 (pos, &instance->bulk_waiter_list) {
if ( F_47 ( V_117 , struct V_107 ,
V_119 ) -> V_92 == V_120 -> V_92 ) {
V_108 = F_47 ( V_117 ,
struct V_107 ,
V_119 ) ;
F_48 ( V_117 ) ;
break;
}
}
F_33 ( & V_1 -> V_118 ) ;
if ( ! V_108 ) {
F_31 ( V_12 ,
L_18 ,
V_120 -> V_92 ) ;
V_67 = - V_121 ;
break;
}
F_7 ( V_12 ,
L_19 , V_108 ,
V_120 -> V_92 ) ;
args . V_30 = & V_108 -> V_114 ;
}
V_38 = F_49
( args . V_27 ,
V_122 ,
args . V_56 , args . V_54 ,
args . V_30 , args . V_112 ,
V_109 ) ;
if ( ! V_108 )
break;
if ( ( V_38 != V_15 ) || F_50 ( V_120 ) ||
! V_108 -> V_114 . V_123 ) {
if ( V_108 -> V_114 . V_123 ) {
F_14 ( & V_124 ) ;
V_108 -> V_114 . V_123 -> V_30 = NULL ;
F_15 ( & V_124 ) ;
}
F_17 ( V_108 ) ;
} else {
const T_15 V_125 =
V_115 ;
V_108 -> V_92 = V_120 -> V_92 ;
F_45 ( & V_1 -> V_118 ) ;
F_51 ( & V_108 -> V_119 , & V_1 -> V_126 ) ;
F_33 ( & V_1 -> V_118 ) ;
F_7 ( V_12 ,
L_20 ,
V_108 , V_120 -> V_92 ) ;
if ( F_38 ( ( void V_82 * )
& ( ( ( T_13 V_82 * )
V_65 ) -> V_112 ) ,
( const void * ) & V_125 ,
sizeof( V_125 ) ) != 0 )
V_67 = - V_57 ;
}
} break;
case V_127 : {
T_16 args ;
F_3 ( V_128 ) ;
if ( ! V_1 -> V_73 ) {
V_67 = - V_86 ;
break;
}
if ( F_22 ( & args , ( const void V_82 * ) V_65 ,
sizeof( args ) ) != 0 ) {
V_67 = - V_57 ;
break;
}
F_45 ( & V_1 -> V_129 ) ;
F_3 ( V_128 ) ;
while ( ( V_1 -> V_9 ==
V_1 -> V_8 )
&& ! V_1 -> V_16 ) {
int V_68 ;
F_3 ( V_128 ) ;
F_33 ( & V_1 -> V_129 ) ;
V_68 = F_6 ( & V_1 -> V_26 ) ;
F_45 ( & V_1 -> V_129 ) ;
if ( V_68 != 0 ) {
F_3 ( V_128 ) ;
F_7 ( V_12 ,
L_21 ) ;
V_67 = - V_79 ;
break;
}
}
F_3 ( V_128 ) ;
if ( V_67 == 0 ) {
int V_130 = args . V_130 ;
int remove = V_1 -> V_9 ;
for ( V_67 = 0 ; V_67 < args . V_60 ; V_67 ++ ) {
T_6 * V_6 ;
T_8 * V_20 ;
T_5 * V_4 ;
T_4 * V_3 ;
if ( remove == V_1 -> V_8 )
break;
V_6 = & V_1 -> V_18 [
remove & ( V_10 - 1 ) ] ;
F_52 () ;
V_20 = V_6 -> V_19 ;
V_4 = V_20 -> V_29 . V_30 ;
V_6 -> V_19 =
V_4 -> V_30 ;
V_3 = V_6 -> V_3 ;
if ( V_3 ) {
void V_82 * V_131 ;
int V_132 ;
V_132 = V_3 -> V_54 +
sizeof( T_4 ) ;
if ( args . V_133 < V_132 ) {
F_31 (
V_12 ,
L_22 ,
V_3 , args . V_133 ,
V_132 ) ;
F_53 ( 1 , L_23
L_24 ) ;
if ( V_67 == 0 )
V_67 = - V_134 ;
break;
}
if ( V_130 <= 0 )
break;
V_130 -- ;
if ( F_22 ( & V_131 ,
( const void V_82 * )
& args . V_135 [ V_130 ] ,
sizeof( V_131 ) ) != 0 ) {
if ( V_67 == 0 )
V_67 = - V_57 ;
break;
}
if ( F_38 ( V_131 , V_3 ,
V_132 ) != 0 ) {
if ( V_67 == 0 )
V_67 = - V_57 ;
break;
}
F_54 ( V_20 -> V_27 ,
V_3 ) ;
V_6 -> V_3 = V_131 ;
}
if ( ( V_6 -> V_2 ==
V_21 ) &&
! V_1 -> V_22 )
F_19 ( V_20 ) ;
if ( F_38 ( ( void V_82 * ) (
( T_10 ) args . V_136 +
V_67 * sizeof( T_6 ) ) ,
V_6 ,
sizeof( T_6 ) ) != 0 ) {
if ( V_67 == 0 )
V_67 = - V_57 ;
break;
}
F_55 () ;
remove ++ ;
V_1 -> V_9 = remove ;
}
if ( V_130 != args . V_130 ) {
if ( F_38 ( ( void V_82 * )
& ( ( T_16 * ) V_65 ) ->
V_130 ,
& V_130 ,
sizeof( V_130 ) ) != 0 ) {
V_67 = - V_57 ;
}
}
}
if ( V_67 != 0 )
F_10 ( & V_1 -> V_14 ) ;
F_33 ( & V_1 -> V_129 ) ;
F_3 ( V_128 ) ;
} break;
case V_137 : {
T_17 args ;
T_5 * V_4 ;
T_4 * V_3 ;
F_3 ( V_138 ) ;
if ( F_22
( & args , ( const void V_82 * ) V_65 ,
sizeof( args ) ) != 0 ) {
V_67 = - V_57 ;
break;
}
V_20 = F_39 ( V_1 , args . V_27 ) ;
if ( ! V_20 ) {
V_67 = - V_76 ;
break;
}
V_4 = ( T_5 * ) V_20 -> V_29 . V_30 ;
if ( V_4 -> V_32 == 0 ) {
V_67 = - V_76 ;
break;
}
F_14 ( & V_33 ) ;
if ( V_4 -> V_35 == V_4 -> V_34 ) {
if ( ! args . V_139 ) {
F_15 ( & V_33 ) ;
F_3 ( V_138 ) ;
V_67 = - V_140 ;
break;
}
V_4 -> V_41 = 1 ;
do {
F_15 ( & V_33 ) ;
F_3 ( V_138 ) ;
if ( F_6 (
& V_4 -> V_26 ) != 0 ) {
F_7 ( V_12 ,
L_25 ) ;
V_67 = - V_79 ;
break;
}
F_14 ( & V_33 ) ;
} while ( V_4 -> V_35 ==
V_4 -> V_34 );
if ( V_67 )
break;
}
F_13 ( ( int ) ( V_4 -> V_34 -
V_4 -> V_35 ) < 0 ) ;
V_3 = V_4 -> V_40 [ V_4 -> V_35 &
( V_36 - 1 ) ] ;
V_4 -> V_35 ++ ;
F_15 ( & V_33 ) ;
F_10 ( & V_4 -> V_14 ) ;
if ( V_3 == NULL )
V_67 = - V_86 ;
else if ( V_3 -> V_54 <= args . V_141 ) {
if ( ( args . V_136 == NULL ) ||
( F_38 ( ( void V_82 * ) args . V_136 ,
V_3 -> V_56 ,
V_3 -> V_54 ) == 0 ) ) {
V_67 = V_3 -> V_54 ;
F_54 (
V_20 -> V_27 ,
V_3 ) ;
} else
V_67 = - V_57 ;
} else {
F_31 ( V_12 ,
L_26 ,
V_3 , args . V_141 , V_3 -> V_54 ) ;
F_53 ( 1 , L_27 ) ;
V_67 = - V_134 ;
}
F_3 ( V_138 ) ;
} break;
case V_142 : {
T_7 V_27 = ( T_7 ) V_65 ;
V_67 = F_56 ( V_27 ) ;
} break;
case V_143 : {
T_18 args ;
T_19 V_144 ;
if ( F_22 ( & args , ( const void V_82 * ) V_65 ,
sizeof( args ) ) != 0 ) {
V_67 = - V_57 ;
break;
}
if ( args . V_145 > sizeof( V_144 ) ) {
V_67 = - V_76 ;
break;
}
V_38 = F_57 ( V_1 , args . V_145 , & V_144 ) ;
if ( V_38 == V_17 ) {
if ( F_38 ( ( void V_82 * ) args . V_146 ,
& V_144 , args . V_145 ) != 0 ) {
V_67 = - V_57 ;
break;
}
}
} break;
case V_147 : {
T_20 args ;
if ( F_22 (
& args , ( const void V_82 * ) V_65 ,
sizeof( args ) ) != 0 ) {
V_67 = - V_57 ;
break;
}
V_20 = F_39 ( V_1 , args . V_27 ) ;
if ( ! V_20 ) {
V_67 = - V_76 ;
break;
}
V_38 = F_58 (
args . V_27 , args . V_148 , args . V_149 ) ;
} break;
#if F_59 ( V_150 )
case V_151 : {
T_21 args ;
if ( F_22
( & args , ( const void V_82 * ) V_65 ,
sizeof( args ) ) != 0 ) {
V_67 = - V_57 ;
break;
}
F_60 ( args . V_152 , args . V_153 ) ;
} break;
#endif
case V_154 : {
unsigned int V_155 = ( unsigned int ) V_65 ;
if ( V_155 < V_156 )
V_67 = - V_76 ;
else if ( V_155 >= V_157 )
V_1 -> V_22 = 1 ;
} break;
case V_158 : {
T_7 V_27 = ( T_7 ) V_65 ;
V_20 = F_61 ( V_1 , V_27 ) ;
if ( V_20 != NULL ) {
T_5 * V_4 =
( T_5 * ) V_20 -> V_29 . V_30 ;
F_18 ( V_4 ) ;
}
else
V_67 = - V_76 ;
} break;
default:
V_67 = - V_159 ;
break;
}
if ( V_20 )
F_19 ( V_20 ) ;
if ( V_67 == 0 ) {
if ( V_38 == V_39 )
V_67 = - V_93 ;
else if ( V_38 == V_15 )
V_67 = - V_79 ;
}
if ( ( V_38 == V_17 ) && ( V_67 < 0 ) && ( V_67 != - V_79 ) &&
( V_67 != - V_140 ) )
F_7 ( V_12 ,
L_28 ,
( unsigned long ) V_1 ,
( F_27 ( V_64 ) <= V_70 ) ?
V_71 [ F_27 ( V_64 ) ] :
L_10 ,
V_38 , V_67 ) ;
else
F_4 ( V_12 ,
L_28 ,
( unsigned long ) V_1 ,
( F_27 ( V_64 ) <= V_70 ) ?
V_71 [ F_27 ( V_64 ) ] :
L_10 ,
V_38 , V_67 ) ;
return V_67 ;
}
static long
F_62 (
struct V_63 * V_63 ,
unsigned int V_64 ,
unsigned long V_65 )
{
T_11 V_82 * args ;
struct V_160 V_82 * V_161 =
(struct V_160 V_82 * ) V_65 ;
struct V_160 V_162 ;
long V_67 ;
args = F_63 ( sizeof( * args ) ) ;
if ( ! args )
return - V_57 ;
if ( F_22 ( & V_162 ,
(struct V_160 V_82 * ) V_65 ,
sizeof( V_162 ) ) )
return - V_57 ;
if ( F_64 ( V_162 . V_90 . V_101 , & args -> V_90 . V_101 ) ||
F_64 ( F_65 ( V_162 . V_90 . V_91 ) ,
& args -> V_90 . V_91 ) ||
F_64 ( F_65 ( V_162 . V_90 . V_30 ) ,
& args -> V_90 . V_30 ) ||
F_64 ( V_162 . V_90 . V_163 , & args -> V_90 . V_163 ) ||
F_64 ( V_162 . V_90 . V_164 ,
& args -> V_90 . V_164 ) ||
F_64 ( V_162 . V_85 , & args -> V_85 ) ||
F_64 ( V_162 . V_32 , & args -> V_32 ) ||
F_64 ( V_162 . V_27 , & args -> V_27 ) )
return - V_57 ;
V_67 = F_25 ( V_63 , V_80 , ( unsigned long ) args ) ;
if ( V_67 < 0 )
return V_67 ;
if ( F_66 ( V_162 . V_27 , & args -> V_27 ) )
return - V_57 ;
if ( F_38 ( & V_161 -> V_27 ,
& V_162 . V_27 ,
sizeof( V_162 . V_27 ) ) )
return - V_57 ;
return 0 ;
}
static long
F_67 ( struct V_63 * V_63 ,
unsigned int V_64 ,
unsigned long V_65 )
{
T_12 * args ;
struct V_58 * V_59 ;
struct V_165 V_162 ;
unsigned int V_60 ;
if ( F_22 ( & V_162 ,
(struct V_165 V_82 * ) V_65 ,
sizeof( V_162 ) ) )
return - V_57 ;
args = F_63 ( sizeof( * args ) +
( sizeof( * V_59 ) * V_104 ) ) ;
if ( ! args )
return - V_57 ;
if ( F_64 ( V_162 . V_27 , & args -> V_27 ) ||
F_64 ( V_162 . V_60 , & args -> V_60 ) ||
F_64 ( F_65 ( V_162 . V_59 ) , & args -> V_59 ) )
return - V_57 ;
if ( V_162 . V_60 > V_104 )
return - V_76 ;
if ( V_162 . V_59 && V_162 . V_60 ) {
struct V_166 V_167 [ V_104 ] ;
V_59 = (struct V_58 V_82 * ) ( args + 1 ) ;
if ( F_22 ( & V_167 ,
F_65 ( V_162 . V_59 ) ,
sizeof( V_167 ) ) )
return - V_57 ;
for ( V_60 = 0 ; V_60 < V_162 . V_60 ; V_60 ++ ) {
if ( F_64 ( F_65 ( V_167 [ V_60 ] . V_56 ) ,
& V_59 [ V_60 ] . V_56 ) ||
F_64 ( V_167 [ V_60 ] . V_54 ,
& V_59 [ V_60 ] . V_54 ) )
return - V_57 ;
}
if ( F_64 ( V_59 , & args -> V_59 ) )
return - V_57 ;
}
return F_25 ( V_63 , V_103 , ( unsigned long ) args ) ;
}
static long
F_68 ( struct V_63 * V_63 ,
unsigned int V_64 ,
unsigned long V_65 )
{
T_13 * args ;
struct V_168 V_162 ;
struct V_168 * V_161 =
(struct V_168 * ) V_65 ;
long V_67 ;
args = F_63 ( sizeof( * args ) ) ;
if ( ! args )
return - V_57 ;
if ( F_22 ( & V_162 ,
(struct V_168 V_82 * ) V_65 ,
sizeof( V_162 ) ) )
return - V_57 ;
if ( F_64 ( V_162 . V_27 , & args -> V_27 ) ||
F_64 ( F_65 ( V_162 . V_56 ) , & args -> V_56 ) ||
F_64 ( V_162 . V_54 , & args -> V_54 ) ||
F_64 ( F_65 ( V_162 . V_30 ) , & args -> V_30 ) ||
F_64 ( V_162 . V_112 , & args -> V_112 ) )
return - V_57 ;
if ( V_64 == V_169 )
V_64 = V_105 ;
else
V_64 = V_106 ;
V_67 = F_25 ( V_63 , V_64 , ( unsigned long ) args ) ;
if ( V_67 < 0 )
return V_67 ;
if ( F_66 ( V_162 . V_112 , & args -> V_112 ) )
return - V_57 ;
if ( F_38 ( & V_161 -> V_112 ,
& V_162 . V_112 ,
sizeof( V_162 . V_112 ) ) )
return - V_57 ;
return 0 ;
}
static long
F_69 ( struct V_63 * V_63 ,
unsigned int V_64 ,
unsigned long V_65 )
{
T_16 * args ;
T_6 * V_6 ;
T_6 V_170 ;
struct V_171 V_162 ;
struct V_172 V_173 ;
unsigned int * V_174 ;
T_22 V_175 ;
void * V_131 ;
void * * V_176 ;
long V_67 ;
args = F_63 ( sizeof( * args ) +
sizeof( * V_6 ) +
sizeof( * V_176 ) ) ;
if ( ! args )
return - V_57 ;
V_6 = ( T_6 * ) ( args + 1 ) ;
V_176 = ( void V_82 * * ) ( V_6 + 1 ) ;
if ( F_22 ( & V_162 ,
(struct V_172 * ) V_65 ,
sizeof( V_162 ) ) )
return - V_57 ;
if ( F_64 ( V_162 . V_60 , & args -> V_60 ) ||
F_64 ( F_65 ( V_162 . V_136 ) , & args -> V_136 ) ||
F_64 ( V_162 . V_133 , & args -> V_133 ) ||
F_64 ( V_162 . V_130 , & args -> V_130 ) ||
F_64 ( F_65 ( V_162 . V_135 ) , & args -> V_135 ) )
return - V_57 ;
if ( ! V_162 . V_60 || ! V_162 . V_136 || ! V_162 . V_130 )
return F_25 ( V_63 ,
V_127 ,
( unsigned long ) args ) ;
if ( F_22 ( & V_175 ,
F_65 ( V_162 . V_135 ) +
( sizeof( T_22 ) *
( V_162 . V_130 - 1 ) ) ,
sizeof( V_175 ) ) )
return - V_57 ;
V_131 = F_65 ( V_175 ) ;
if ( F_38 ( V_176 ,
& V_131 ,
sizeof( V_131 ) ) )
return - V_57 ;
if ( F_38 ( & args -> V_135 ,
& V_176 ,
sizeof( V_176 ) ) )
return - V_57 ;
if ( F_64 ( 1U , & args -> V_60 ) ||
F_64 ( V_6 , & args -> V_136 ) ||
F_64 ( 1U , & args -> V_130 ) )
return - V_57 ;
V_67 = F_25 ( V_63 ,
V_127 ,
( unsigned long ) args ) ;
if ( V_67 <= 0 )
return V_67 ;
if ( F_22 ( & V_170 , V_6 , sizeof( * V_6 ) ) )
return - V_57 ;
V_173 . V_2 = V_170 . V_2 ;
V_173 . V_3 = F_70 ( V_170 . V_3 ) ;
V_173 . V_19 =
F_70 ( V_170 . V_19 ) ;
V_173 . V_5 =
F_70 ( V_170 . V_5 ) ;
if ( F_38 ( F_65 ( V_162 . V_136 ) ,
& V_173 ,
sizeof( V_173 ) ) )
return - V_57 ;
V_162 . V_130 -- ;
V_174 =
& ( (struct V_171 V_82 * ) V_65 ) -> V_130 ;
if ( F_38 ( V_174 ,
& V_162 . V_130 ,
sizeof( V_162 . V_130 ) ) )
return - V_57 ;
return 1 ;
}
static long
F_71 ( struct V_63 * V_63 ,
unsigned int V_64 ,
unsigned long V_65 )
{
T_17 * args ;
struct V_177 V_162 ;
args = F_63 ( sizeof( * args ) ) ;
if ( ! args )
return - V_57 ;
if ( F_22 ( & V_162 ,
(struct V_177 * ) V_65 ,
sizeof( V_162 ) ) )
return - V_57 ;
if ( F_64 ( V_162 . V_27 , & args -> V_27 ) ||
F_64 ( V_162 . V_139 , & args -> V_139 ) ||
F_64 ( V_162 . V_141 , & args -> V_141 ) ||
F_64 ( F_65 ( V_162 . V_136 ) , & args -> V_136 ) )
return - V_57 ;
return F_25 ( V_63 , V_137 ,
( unsigned long ) args ) ;
}
static long
F_72 ( struct V_63 * V_63 ,
unsigned int V_64 ,
unsigned long V_65 )
{
T_18 * args ;
struct V_178 V_162 ;
args = F_63 ( sizeof( * args ) ) ;
if ( ! args )
return - V_57 ;
if ( F_22 ( & V_162 ,
(struct V_178 * ) V_65 ,
sizeof( V_162 ) ) )
return - V_57 ;
if ( F_64 ( V_162 . V_145 , & args -> V_145 ) ||
F_64 ( F_65 ( V_162 . V_146 ) , & args -> V_146 ) )
return - V_57 ;
return F_25 ( V_63 , V_143 , ( unsigned long ) args ) ;
}
static long
F_73 ( struct V_63 * V_63 ,
unsigned int V_64 ,
unsigned long V_65 )
{
T_21 * args ;
struct V_179 V_162 ;
args = F_63 ( sizeof( * args ) ) ;
if ( ! args )
return - V_57 ;
if ( F_22 ( & V_162 ,
(struct V_179 * ) V_65 ,
sizeof( V_162 ) ) )
return - V_57 ;
if ( F_64 ( F_65 ( V_162 . V_152 ) , & args -> V_152 ) ||
F_64 ( V_162 . V_153 , & args -> V_153 ) )
return - V_57 ;
return F_25 ( V_63 , V_151 , ( unsigned long ) args ) ;
}
static long
F_74 ( struct V_63 * V_63 , unsigned int V_64 , unsigned long V_65 )
{
switch ( V_64 ) {
case V_180 :
return F_62 ( V_63 , V_64 , V_65 ) ;
case V_181 :
return F_67 ( V_63 , V_64 , V_65 ) ;
case V_169 :
case V_182 :
return F_68 ( V_63 , V_64 , V_65 ) ;
case V_183 :
return F_69 ( V_63 , V_64 , V_65 ) ;
case V_184 :
return F_71 ( V_63 , V_64 , V_65 ) ;
case V_185 :
return F_72 ( V_63 , V_64 , V_65 ) ;
#if F_59 ( V_150 )
case V_186 :
return F_73 ( V_63 , V_64 , V_65 ) ;
#endif
default:
return F_25 ( V_63 , V_64 , V_65 ) ;
}
}
static int
F_75 ( struct V_187 * V_187 , struct V_63 * V_63 )
{
int V_188 = F_76 ( V_187 ) & 0x0f ;
F_7 ( V_12 , L_29 ) ;
switch ( V_188 ) {
case V_189 : {
int V_67 ;
T_23 * V_74 = F_77 () ;
T_2 V_1 ;
if ( ! V_74 ) {
F_31 ( V_12 ,
L_30 ) ;
return - V_86 ;
}
V_1 = F_44 ( sizeof( * V_1 ) , V_83 ) ;
if ( ! V_1 )
return - V_84 ;
V_1 -> V_74 = V_74 ;
V_1 -> V_92 = V_120 -> V_190 ;
V_67 = F_78 ( V_1 ) ;
if ( V_67 != 0 ) {
F_17 ( V_1 ) ;
return V_67 ;
}
F_36 ( & V_1 -> V_26 , 0 ) ;
F_36 ( & V_1 -> V_14 , 0 ) ;
F_79 ( & V_1 -> V_129 ) ;
F_79 ( & V_1 -> V_118 ) ;
F_80 ( & V_1 -> V_126 ) ;
V_63 -> V_66 = V_1 ;
} break;
default:
F_31 ( V_12 ,
L_31 , V_188 ) ;
return - V_191 ;
}
return 0 ;
}
static int
F_81 ( struct V_187 * V_187 , struct V_63 * V_63 )
{
int V_188 = F_76 ( V_187 ) & 0x0f ;
int V_67 = 0 ;
switch ( V_188 ) {
case V_189 : {
T_2 V_1 = V_63 -> V_66 ;
T_23 * V_74 = F_77 () ;
T_8 * V_20 ;
int V_61 ;
F_7 ( V_12 ,
L_32 ,
( unsigned long ) V_1 ) ;
if ( ! V_74 ) {
V_67 = - V_192 ;
goto V_193;
}
F_82 ( V_1 -> V_74 , NULL ,
V_194 ) ;
F_45 ( & V_1 -> V_129 ) ;
V_1 -> V_16 = 1 ;
F_10 ( & V_1 -> V_26 ) ;
F_33 ( & V_1 -> V_129 ) ;
F_10 ( & V_1 -> V_14 ) ;
V_61 = 0 ;
while ( ( V_20 = F_28 ( V_74 , V_1 ,
& V_61 ) ) != NULL ) {
T_5 * V_4 = V_20 -> V_29 . V_30 ;
F_10 ( & V_4 -> V_14 ) ;
F_83 ( V_20 ) ;
F_19 ( V_20 ) ;
}
V_61 = 0 ;
while ( ( V_20 = F_28 ( V_74 , V_1 , & V_61 ) )
!= NULL ) {
T_5 * V_4 = V_20 -> V_29 . V_30 ;
F_84 ( & V_20 -> V_14 ) ;
F_13 ( V_20 -> V_81 != V_195 ) ;
F_14 ( & V_33 ) ;
while ( V_4 -> V_35 !=
V_4 -> V_34 ) {
T_4 * V_3 = V_4 ->
V_40 [ V_4 -> V_35 &
( V_36 - 1 ) ] ;
V_4 -> V_35 ++ ;
F_15 ( & V_33 ) ;
if ( V_3 )
F_54 (
V_20 -> V_27 ,
V_3 ) ;
F_14 ( & V_33 ) ;
}
F_15 ( & V_33 ) ;
F_19 ( V_20 ) ;
}
while ( V_1 -> V_9 !=
V_1 -> V_8 ) {
T_6 * V_6 ;
T_8 * V_20 ;
V_6 = & V_1 -> V_18 [
V_1 -> V_9 &
( V_10 - 1 ) ] ;
V_20 = V_6 -> V_19 ;
if ( V_6 -> V_2 == V_21 )
{
T_5 * V_4 =
V_20 -> V_29 . V_30 ;
if ( V_1 -> V_22 )
F_10 ( & V_4 -> V_42 ) ;
F_19 ( V_20 ) ;
}
V_1 -> V_9 ++ ;
}
F_85 ( V_1 -> V_74 , NULL ) ;
{
struct V_116 * V_117 , * V_196 ;
F_86 (pos, next,
&instance->bulk_waiter_list) {
struct V_107 * V_108 ;
V_108 = F_47 ( V_117 ,
struct V_107 ,
V_119 ) ;
F_48 ( V_117 ) ;
F_7 ( V_12 ,
L_33 ,
V_108 , V_108 -> V_92 ) ;
F_17 ( V_108 ) ;
}
}
F_87 ( V_1 ) ;
F_17 ( V_1 ) ;
V_63 -> V_66 = NULL ;
} break;
default:
F_31 ( V_12 ,
L_31 , V_188 ) ;
V_67 = - V_191 ;
}
V_193:
return V_67 ;
}
void
F_88 ( void * V_197 , const char * V_198 , int V_199 )
{
T_24 * V_43 = ( T_24 * ) V_197 ;
if ( V_43 -> V_200 < V_43 -> V_201 ) {
int V_202 ;
if ( V_43 -> V_45 > 0 ) {
int V_203 = F_21 ( V_199 , ( int ) V_43 -> V_45 ) ;
V_198 += V_203 ;
V_199 -= V_203 ;
V_43 -> V_45 -= V_203 ;
if ( V_43 -> V_45 > 0 )
return;
}
V_202 = F_21 ( V_199 , ( int ) ( V_43 -> V_201 - V_43 -> V_200 ) ) ;
if ( V_202 == 0 )
return;
if ( F_38 ( V_43 -> V_136 + V_43 -> V_200 , V_198 ,
V_202 ) )
V_43 -> V_200 = - V_57 ;
V_43 -> V_200 += V_202 ;
V_199 -= V_202 ;
if ( ( V_199 == 0 ) && ( V_198 [ V_202 - 1 ] == '\0' ) ) {
char V_204 = '\n' ;
if ( F_38 ( V_43 -> V_136 + V_43 -> V_200 - 1 ,
& V_204 , 1 ) )
V_43 -> V_200 = - V_57 ;
}
}
}
void
F_89 ( void * V_197 )
{
T_23 * V_74 = F_77 () ;
char V_136 [ 80 ] ;
int V_199 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_74 -> V_205 ; V_61 ++ ) {
T_8 * V_20 = V_74 -> V_206 [ V_61 ] ;
T_2 V_1 ;
if ( V_20 && ( V_20 -> V_29 . V_91 == F_11 ) ) {
V_1 = V_20 -> V_1 ;
if ( V_1 )
V_1 -> V_207 = 0 ;
}
}
for ( V_61 = 0 ; V_61 < V_74 -> V_205 ; V_61 ++ ) {
T_8 * V_20 = V_74 -> V_206 [ V_61 ] ;
T_2 V_1 ;
if ( V_20 && ( V_20 -> V_29 . V_91 == F_11 ) ) {
V_1 = V_20 -> V_1 ;
if ( V_1 && ! V_1 -> V_207 ) {
V_199 = snprintf ( V_136 , sizeof( V_136 ) ,
L_34 ,
V_1 , V_1 -> V_92 ,
V_1 -> V_73 ? L_35 :
L_36 ,
V_1 -> V_8 -
V_1 -> V_9 ,
V_10 ) ;
F_88 ( V_197 , V_136 , V_199 + 1 ) ;
V_1 -> V_207 = 1 ;
}
}
}
}
void
F_90 ( void * V_197 , T_8 * V_20 )
{
T_5 * V_4 = ( T_5 * ) V_20 -> V_29 . V_30 ;
char V_136 [ 80 ] ;
int V_199 ;
V_199 = snprintf ( V_136 , sizeof( V_136 ) , L_37 , V_20 -> V_1 ) ;
if ( ( V_20 -> V_29 . V_91 == F_11 ) &&
V_4 -> V_32 ) {
V_199 += snprintf ( V_136 + V_199 , sizeof( V_136 ) - V_199 ,
L_38 ,
V_4 -> V_34 - V_4 -> V_35 ,
V_36 ) ;
if ( V_4 -> V_41 )
V_199 += snprintf ( V_136 + V_199 , sizeof( V_136 ) - V_199 ,
L_39 ) ;
}
F_88 ( V_197 , V_136 , V_199 + 1 ) ;
}
static void
F_60 ( void * V_152 , T_25 V_153 )
{
int V_68 ;
T_26 * V_208 = V_152 + V_153 ;
int V_209 ;
int V_45 ;
int V_210 ;
int V_211 ;
int V_212 ;
struct V_213 * V_213 ;
struct V_213 * * V_214 ;
T_26 * V_215 ;
V_152 = ( void * ) ( ( unsigned long ) V_152 & ~ 0x0fuL ) ;
V_208 = ( void * ) ( ( ( unsigned long ) V_208 + 15uL ) &
~ 0x0fuL ) ;
V_45 = ( int ) ( long ) V_152 & ( V_216 - 1 ) ;
V_210 = ( int ) ( long ) V_208 & ( V_216 - 1 ) ;
V_209 = F_91 ( V_45 + V_153 , V_216 ) ;
V_214 = F_34 ( sizeof( struct V_213 * ) * V_209 , V_83 ) ;
if ( ! V_214 ) {
F_31 ( V_12 ,
L_40 ,
V_209 ) ;
return;
}
F_92 ( & V_120 -> V_217 -> V_218 ) ;
V_68 = F_93 (
( unsigned long ) V_152 ,
V_209 ,
0 ,
V_214 ,
NULL ) ;
F_94 ( & V_120 -> V_217 -> V_218 ) ;
V_212 = - 1 ;
V_213 = NULL ;
if ( V_68 < 0 ) {
F_31 ( V_12 ,
L_41 , V_68 ) ;
goto V_193;
}
while ( V_45 < V_210 ) {
int V_219 = V_45 % V_216 ;
V_211 = V_45 / V_216 ;
if ( V_211 != V_212 ) {
if ( V_213 != NULL )
F_95 ( V_213 ) ;
V_213 = V_214 [ V_211 ] ;
V_215 = F_96 ( V_213 ) ;
V_212 = V_211 ;
}
if ( V_12 >= V_220 )
F_97 ( L_42 ,
( T_25 ) ( unsigned long ) & V_215 [
V_219 ] ,
& V_215 [ V_219 ] , 16 ) ;
V_45 += 16 ;
}
V_193:
if ( V_213 != NULL )
F_95 ( V_213 ) ;
for ( V_211 = 0 ; V_211 < V_209 ; V_211 ++ )
F_98 ( V_214 [ V_211 ] ) ;
F_17 ( V_214 ) ;
}
static T_9
F_99 ( struct V_63 * V_63 , char V_82 * V_136 ,
T_10 V_60 , T_27 * V_221 )
{
T_24 V_43 ;
V_43 . V_136 = V_136 ;
V_43 . V_200 = 0 ;
V_43 . V_201 = V_60 ;
V_43 . V_45 = * V_221 ;
F_100 ( & V_43 , & V_222 ) ;
* V_221 += V_43 . V_200 ;
return V_43 . V_200 ;
}
T_23 *
F_77 ( void )
{
if ( V_222 . V_223 == NULL )
F_101 ( V_224 L_43 , V_100 ) ;
else if ( V_222 . V_223 -> V_225 != 1 )
F_101 ( V_226 L_44 ,
V_100 , V_222 . V_223 -> V_225 ) ;
return ( ( V_222 . V_223 != NULL ) &&
( V_222 . V_223 -> V_225 == 1 ) ) ? & V_222 : NULL ;
}
int
F_102 ( T_23 * V_74 )
{
T_28 * V_227 = F_103 ( V_74 ) ;
if ( ! V_227 )
return 1 ;
else if ( V_227 -> V_228 )
return 1 ;
else if ( ! V_227 -> V_229 )
if ( V_227 -> V_230 )
return 0 ;
else
return F_104 ( V_74 ) ;
else
return 1 ;
}
static T_1
F_105 ( T_3 V_2 ,
T_4 * V_3 ,
T_7 V_231 ,
void * V_232 )
{
F_31 ( V_99 ,
L_45 , V_100 , V_2 ) ;
return 0 ;
}
static int
F_106 ( void * V_233 )
{
T_23 * V_74 = ( T_23 * ) V_233 ;
T_28 * V_227 = F_103 ( V_74 ) ;
T_1 V_38 ;
T_2 V_1 ;
T_7 V_234 ;
T_29 V_90 = {
. V_101 = F_107 ( 'K' , 'E' , 'E' , 'P' ) ,
. V_91 = F_105 ,
. V_163 = V_235 ,
. V_164 = V_236
} ;
V_38 = F_108 ( & V_1 ) ;
if ( V_38 != V_17 ) {
F_31 ( V_99 ,
L_46 , V_100 , V_38 ) ;
goto exit;
}
V_38 = F_109 ( V_1 ) ;
if ( V_38 != V_17 ) {
F_31 ( V_99 ,
L_47 , V_100 , V_38 ) ;
goto V_237;
}
V_38 = F_110 ( V_1 , & V_90 , & V_234 ) ;
if ( V_38 != V_17 ) {
F_31 ( V_99 ,
L_48 , V_100 , V_38 ) ;
goto V_237;
}
while ( 1 ) {
long V_68 = 0 , V_238 = 0 ;
if ( F_111 ( & V_227 -> V_239 )
!= 0 ) {
F_31 ( V_99 ,
L_49 , V_100 ) ;
F_112 ( V_120 ) ;
continue;
}
V_68 = F_113 ( & V_227 -> V_240 , 0 ) ;
V_238 = F_113 ( & V_227 -> V_241 , 0 ) ;
while ( V_238 -- ) {
F_114 ( & V_227 -> V_242 ) ;
V_38 = F_115 ( V_234 ) ;
if ( V_38 != V_17 ) {
F_31 ( V_99 ,
L_50 ,
V_100 , V_38 ) ;
}
}
while ( V_68 -- ) {
V_38 = F_116 ( V_234 ) ;
if ( V_38 != V_17 ) {
F_31 ( V_99 ,
L_51 ,
V_100 , V_38 ) ;
}
}
}
V_237:
F_117 ( V_1 ) ;
exit:
return 0 ;
}
T_1
F_118 ( T_23 * V_74 , T_28 * V_227 )
{
if ( V_227 ) {
F_119 ( & V_227 -> V_243 ) ;
F_120 ( & V_227 -> V_239 ) ;
F_121 ( & V_227 -> V_241 , 0 ) ;
F_121 ( & V_227 -> V_242 , 0 ) ;
F_121 ( & V_227 -> V_240 , 0 ) ;
F_120 ( & V_227 -> V_244 ) ;
F_120 ( & V_227 -> V_245 ) ;
F_122 ( V_227 , V_246 ) ;
F_120 ( & V_227 -> V_247 ) ;
F_123 ( & V_227 -> V_247 ) ;
F_120 ( & V_227 -> V_248 ) ;
F_123 ( & V_227 -> V_248 ) ;
V_227 -> V_249 = V_250 ;
V_227 -> V_251 = 0 ;
F_124 ( & V_227 -> V_252 , V_253 ,
( unsigned long ) ( V_74 ) ) ;
V_227 -> V_254 = 0 ;
}
return V_17 ;
}
void
F_125 ( T_28 * V_227 ,
enum V_255 V_256 )
{
V_227 -> V_257 = V_256 ;
switch ( V_256 ) {
case V_258 :
F_123 ( & V_227 -> V_244 ) ;
break;
case V_259 :
F_123 ( & V_227 -> V_244 ) ;
break;
case V_260 :
F_123 ( & V_227 -> V_244 ) ;
V_227 -> V_261 = V_246 ;
F_123 ( & V_227 -> V_245 ) ;
break;
case V_262 :
F_126 ( & V_227 -> V_244 ) ;
break;
case V_263 :
break;
case V_264 :
F_122 ( V_227 , V_265 ) ;
break;
case V_266 :
F_123 ( & V_227 -> V_244 ) ;
break;
default:
F_127 () ;
break;
}
}
void
F_122 ( T_28 * V_227 ,
enum V_267 V_256 )
{
V_227 -> V_261 = V_256 ;
switch ( V_256 ) {
case V_268 :
break;
case V_265 :
F_126 ( & V_227 -> V_245 ) ;
break;
case V_269 :
break;
case V_270 :
break;
case V_246 :
F_123 ( & V_227 -> V_245 ) ;
F_125 ( V_227 , V_262 ) ;
break;
default:
F_127 () ;
break;
}
}
inline void
F_128 ( T_28 * V_227 )
{
F_129 ( & V_227 -> V_252 ) ;
V_227 -> V_252 . V_271 = V_272 +
F_130 ( V_227 ->
V_249 ) ;
F_131 ( & V_227 -> V_252 ) ;
V_227 -> V_251 = 1 ;
}
static inline void
F_132 ( T_28 * V_227 )
{
if ( V_227 -> V_251 ) {
F_129 ( & V_227 -> V_252 ) ;
V_227 -> V_251 = 0 ;
}
}
static inline int
F_133 ( T_23 * V_74 )
{
T_28 * V_227 = F_103 ( V_74 ) ;
return ( V_227 -> V_257 > V_262 ) &&
( V_227 -> V_261 < V_269 ) &&
F_102 ( V_74 ) ;
}
static int
F_134 ( T_28 * V_227 )
{
int V_38 = V_17 ;
const unsigned long V_273 =
F_130 ( V_274 ) ;
int V_275 = 0 ;
if ( V_227 -> V_228 ) {
F_126 ( & V_227 -> V_248 ) ;
F_135 ( & V_227 -> V_243 ) ;
F_7 ( V_99 , L_52
L_53 , V_100 ) ;
if ( F_136 (
& V_227 -> V_248 , V_273 )
<= 0 ) {
F_31 ( V_99 , L_54
L_55 , V_100 ) ;
V_38 = V_39 ;
F_137 ( & V_227 -> V_243 ) ;
goto V_193;
}
F_7 ( V_99 , L_56
L_57 , V_100 ) ;
F_137 ( & V_227 -> V_243 ) ;
}
while ( V_227 -> V_261 != V_246 &&
V_227 -> V_261 > V_265 ) {
if ( V_275 > 1 ) {
V_38 = V_39 ;
F_31 ( V_99 , L_58
L_59 , V_100 ) ;
goto V_193;
}
F_135 ( & V_227 -> V_243 ) ;
F_7 ( V_99 , L_60 ,
V_100 ) ;
if ( F_136 (
& V_227 -> V_245 , V_273 )
<= 0 ) {
F_31 ( V_99 , L_54
L_61 , V_100 ,
V_276 [ V_227 -> V_261 +
V_277 ] ) ;
V_38 = V_39 ;
F_137 ( & V_227 -> V_243 ) ;
goto V_193;
}
F_7 ( V_99 , L_62 , V_100 ) ;
F_137 ( & V_227 -> V_243 ) ;
V_275 ++ ;
}
F_126 ( & V_227 -> V_247 ) ;
V_227 -> V_230 = 1 ;
V_193:
return V_38 ;
}
static inline void
F_138 ( T_28 * V_227 )
{
F_123 ( & V_227 -> V_247 ) ;
V_227 -> V_230 = 0 ;
}
T_1
F_139 ( T_23 * V_74 )
{
T_1 V_38 = V_39 ;
T_28 * V_227 = F_103 ( V_74 ) ;
if ( ! V_227 )
goto V_193;
F_4 ( V_99 , L_63 , V_100 ) ;
V_38 = V_17 ;
switch ( V_227 -> V_257 ) {
case V_263 :
F_7 ( V_99 , L_64
L_65 , V_100 ) ;
break;
case V_264 :
F_7 ( V_99 , L_66
L_67 , V_100 ) ;
break;
default:
F_31 ( V_99 ,
L_68 , V_100 ,
V_278 [ V_227 -> V_257 +
V_279 ] ) ;
case V_259 :
case V_260 :
F_125 ( V_227 , V_262 ) ;
case V_262 :
F_7 ( V_99 ,
L_69 , V_100 ) ;
F_125 ( V_227 , V_263 ) ;
F_140 ( V_74 , NULL , 0 ) ;
break;
}
V_193:
F_4 ( V_99 , L_70 , V_100 , V_38 ) ;
return V_38 ;
}
void
F_141 ( T_23 * V_74 )
{
T_28 * V_227 = F_103 ( V_74 ) ;
int V_280 = 0 ;
if ( ! V_227 )
goto V_193;
F_4 ( V_99 , L_63 , V_100 ) ;
F_137 ( & V_227 -> V_243 ) ;
if ( V_227 -> V_257 == V_263 &&
V_227 -> V_261 == V_246 ) {
F_125 ( V_227 , V_264 ) ;
V_280 = 1 ;
}
F_135 ( & V_227 -> V_243 ) ;
if ( V_280 )
F_142 ( V_74 ) ;
V_193:
F_4 ( V_99 , L_71 , V_100 ) ;
return;
}
static void
F_143 ( T_23 * V_74 )
{
T_28 * V_227 = F_103 ( V_74 ) ;
char V_281 [ 50 ] = L_36 ;
int V_282 = V_227 -> V_229 ;
int V_283 = V_74 -> V_205 ;
int V_61 ;
if ( ! V_227 -> V_229 ) {
snprintf ( V_281 , sizeof( V_281 ) , L_72 ) ;
goto V_284;
}
for ( V_61 = 0 ; V_61 < V_283 ; V_61 ++ ) {
T_8 * V_285 = V_74 -> V_206 [ V_61 ] ;
if ( V_285 && V_285 -> V_286 &&
( V_285 -> V_81 != V_195 ) ) {
snprintf ( V_281 , sizeof( V_281 ) , L_73
L_74 , F_43 (
V_285 -> V_29 . V_101 ) ,
V_285 -> V_102 ,
V_285 -> V_286 ,
V_285 -> V_286 ==
V_282 ? L_36 : L_75 ) ;
break;
}
}
V_284:
F_31 ( V_99 ,
L_76 ,
V_227 -> V_287 , V_281 ) ;
}
T_1
F_144 ( T_23 * V_74 )
{
T_28 * V_227 = F_103 ( V_74 ) ;
T_1 V_38 = V_39 ;
long V_68 = 0 ;
int V_288 = - 1 ;
if ( ! V_227 )
goto V_193;
F_4 ( V_99 , L_63 , V_100 ) ;
F_137 ( & V_227 -> V_243 ) ;
V_38 = F_134 ( V_227 ) ;
if ( V_38 != V_17 )
goto V_289;
if ( V_227 -> V_257 == V_266 ) {
F_7 ( V_99 , L_77 ,
V_100 ) ;
V_38 = V_17 ;
goto V_289;
} else if ( V_227 -> V_257 <= V_262 ) {
F_132 ( V_227 ) ;
if ( ! F_102 ( V_74 ) ) {
F_7 ( V_99 , L_78
L_79 , V_100 ) ;
V_38 = F_139 ( V_74 ) ;
} else if ( V_227 -> V_287 <
V_290 ) {
F_7 ( V_99 , L_80
L_81 , V_100 ) ;
V_38 = V_17 ;
} else {
F_145 ( V_99 , L_82
L_83 , V_100 ) ;
V_38 = F_139 ( V_74 ) ;
}
} else {
F_7 ( V_99 , L_84
L_85 , V_100 ) ;
V_38 = V_17 ;
}
if ( V_38 != V_17 )
goto F_138;
do {
F_135 ( & V_227 -> V_243 ) ;
V_68 = F_136 (
& V_227 -> V_244 ,
F_130 ( V_274 ) ) ;
F_137 ( & V_227 -> V_243 ) ;
if ( V_68 < 0 ) {
F_145 ( V_99 , L_86
L_87 , V_100 ) ;
V_38 = V_39 ;
goto F_138;
} else if ( V_68 == 0 ) {
if ( V_227 -> V_257 > V_262 ) {
if ( V_288 < 0 ) {
V_288 = 1 ;
continue;
}
}
V_227 -> V_287 ++ ;
F_143 ( V_74 ) ;
V_38 = V_15 ;
goto F_138;
}
} while ( 0 < ( V_288 -- ) );
if ( V_227 -> V_257 != V_266 ) {
V_38 = V_15 ;
F_31 ( V_99 ,
L_88 , V_100 ,
V_278 [ V_227 -> V_257 +
V_279 ] ) ;
if ( V_227 -> V_257 < V_262 )
F_125 ( V_227 , V_262 ) ;
goto F_138;
}
goto V_289;
F_138:
F_138 ( V_227 ) ;
V_289:
F_135 ( & V_227 -> V_243 ) ;
V_193:
F_4 ( V_99 , L_70 , V_100 , V_38 ) ;
return V_38 ;
}
void
F_146 ( T_23 * V_74 )
{
T_28 * V_227 = F_103 ( V_74 ) ;
if ( ! V_227 )
goto V_193;
F_4 ( V_99 , L_63 , V_100 ) ;
F_137 ( & V_227 -> V_243 ) ;
if ( V_227 -> V_257 != V_266 &&
V_227 -> V_254 &&
! F_102 ( V_74 ) ) {
F_139 ( V_74 ) ;
}
F_135 ( & V_227 -> V_243 ) ;
V_193:
F_4 ( V_99 , L_71 , V_100 ) ;
return;
}
int
F_147 ( T_23 * V_74 )
{
T_28 * V_227 = F_103 ( V_74 ) ;
int V_291 = 0 ;
int V_67 = - 1 ;
if ( ! V_227 )
goto V_193;
F_4 ( V_99 , L_63 , V_100 ) ;
F_137 ( & V_227 -> V_243 ) ;
F_138 ( V_227 ) ;
V_291 = F_148 ( V_74 ) ;
F_135 ( & V_227 -> V_243 ) ;
if ( V_291 ) {
if ( F_111 (
& V_227 -> V_245 ) < 0 ) {
F_31 ( V_99 ,
L_49 , V_100 ) ;
goto V_193;
}
}
F_149 ( & V_227 -> V_243 ) ;
if ( V_227 -> V_257 == V_266 ) {
F_7 ( V_99 ,
L_89 , V_100 ) ;
} else {
F_7 ( V_99 ,
L_90 , V_100 ) ;
V_67 = 0 ;
}
F_150 ( & V_227 -> V_243 ) ;
V_193:
F_4 ( V_99 , L_70 , V_100 , V_67 ) ;
return V_67 ;
}
int
F_148 ( T_23 * V_74 )
{
T_28 * V_227 = F_103 ( V_74 ) ;
int V_291 = 0 ;
if ( ! V_227 )
goto V_193;
F_4 ( V_99 , L_63 , V_100 ) ;
if ( F_133 ( V_74 ) ) {
F_122 ( V_227 , V_269 ) ;
F_140 ( V_74 , NULL , 0 ) ;
V_291 = 1 ;
}
V_193:
F_4 ( V_99 , L_71 , V_100 ) ;
return V_291 ;
}
T_1
F_82 ( T_23 * V_74 , T_8 * V_20 ,
enum V_292 V_293 )
{
T_28 * V_227 = F_103 ( V_74 ) ;
T_1 V_67 = V_17 ;
char V_294 [ 16 ] ;
int * V_295 ;
int V_296 , V_297 ;
if ( ! V_227 )
goto V_193;
F_4 ( V_99 , L_63 , V_100 ) ;
if ( V_293 == V_194 ) {
sprintf ( V_294 , L_91 ) ;
V_295 = & V_227 -> V_298 ;
} else if ( V_20 ) {
sprintf ( V_294 , L_92 ,
F_43 ( V_20 -> V_29 . V_101 ) ,
V_20 -> V_102 ) ;
V_295 = & V_20 -> V_286 ;
} else {
F_31 ( V_99 , L_93
L_94 , V_100 ) ;
V_67 = V_39 ;
goto V_193;
}
F_137 ( & V_227 -> V_243 ) ;
while ( V_227 -> V_230 ) {
if ( V_227 -> V_230 && V_227 -> V_257 ==
V_262 ) {
F_125 ( V_227 , V_258 ) ;
break;
}
if ( ! F_151 ( & V_227 -> V_247 ) ) {
V_227 -> V_228 ++ ;
F_135 ( & V_227 -> V_243 ) ;
F_7 ( V_99 , L_95
L_96 , V_100 , V_294 ) ;
if ( F_152 (
& V_227 -> V_247 ) != 0 ) {
F_31 ( V_99 , L_97
L_98 ,
V_100 , V_294 ) ;
V_67 = V_39 ;
F_137 ( & V_227 -> V_243 ) ;
V_227 -> V_228 -- ;
F_135 ( & V_227 -> V_243 ) ;
goto V_193;
}
F_7 ( V_99 , L_95
L_99 , V_100 , V_294 ) ;
F_137 ( & V_227 -> V_243 ) ;
if ( -- V_227 -> V_228 == 0 )
F_123 ( & V_227 -> V_248 ) ;
}
}
F_132 ( V_227 ) ;
V_296 = ++ V_227 -> V_229 ;
V_297 = ++ ( * V_295 ) ;
if ( V_227 -> V_257 <= V_263 )
F_125 ( V_227 , V_262 ) ;
if ( ( V_293 != V_299 ) && F_133 ( V_74 ) ) {
F_122 ( V_227 , V_269 ) ;
F_7 ( V_99 ,
L_100 ,
V_100 , V_294 , V_297 , V_296 ) ;
F_140 ( V_74 , NULL , 0 ) ;
} else
F_4 ( V_99 ,
L_100 ,
V_100 , V_294 , * V_295 , V_296 ) ;
F_135 ( & V_227 -> V_243 ) ;
if ( ! F_151 ( & V_227 -> V_245 ) ) {
F_7 ( V_99 , L_101 ,
V_100 , V_294 ) ;
if ( F_152 (
& V_227 -> V_245 ) != 0 ) {
F_31 ( V_99 , L_102
L_103 , V_100 , V_294 ) ;
V_67 = V_39 ;
goto V_193;
}
F_7 ( V_99 , L_104 , V_100 ,
V_294 ) ;
}
if ( V_67 == V_17 ) {
T_1 V_38 = V_17 ;
long V_300 = F_113 ( & V_227 -> V_242 , 0 ) ;
while ( V_300 && ( V_38 == V_17 ) ) {
V_38 = F_153 ( V_74 ) ;
if ( V_38 == V_17 )
V_300 -- ;
else
F_154 ( V_300 ,
& V_227 -> V_242 ) ;
}
}
V_193:
F_4 ( V_99 , L_70 , V_100 , V_67 ) ;
return V_67 ;
}
T_1
F_85 ( T_23 * V_74 , T_8 * V_20 )
{
T_28 * V_227 = F_103 ( V_74 ) ;
T_1 V_67 = V_17 ;
char V_294 [ 16 ] ;
int * V_295 ;
int V_296 , V_297 ;
if ( ! V_227 )
goto V_193;
F_4 ( V_99 , L_63 , V_100 ) ;
if ( V_20 ) {
sprintf ( V_294 , L_92 ,
F_43 ( V_20 -> V_29 . V_101 ) ,
V_20 -> V_102 ) ;
V_295 = & V_20 -> V_286 ;
} else {
sprintf ( V_294 , L_105 ) ;
V_295 = & V_227 -> V_298 ;
}
F_137 ( & V_227 -> V_243 ) ;
if ( ! V_227 -> V_229 || ! ( * V_295 ) ) {
F_155 ( ! V_227 -> V_229 ) ;
F_155 ( ! ( * V_295 ) ) ;
V_67 = V_39 ;
goto V_289;
}
V_296 = -- V_227 -> V_229 ;
V_297 = -- ( * V_295 ) ;
if ( ! F_102 ( V_74 ) ) {
if ( F_156 () &&
! V_227 -> V_230 ) {
F_128 ( V_227 ) ;
} else {
F_7 ( V_99 ,
L_106 ,
V_100 , V_294 , * V_295 ,
V_227 -> V_229 ) ;
F_139 ( V_74 ) ;
}
} else
F_4 ( V_99 ,
L_100 ,
V_100 , V_294 , * V_295 ,
V_227 -> V_229 ) ;
V_289:
F_135 ( & V_227 -> V_243 ) ;
V_193:
F_4 ( V_99 , L_70 , V_100 , V_67 ) ;
return V_67 ;
}
void
F_157 ( T_23 * V_74 )
{
T_28 * V_227 = F_103 ( V_74 ) ;
F_4 ( V_99 , L_63 , V_100 ) ;
F_114 ( & V_227 -> V_241 ) ;
F_158 ( & V_227 -> V_239 ) ;
}
void
F_159 ( T_23 * V_74 )
{
T_28 * V_227 = F_103 ( V_74 ) ;
F_4 ( V_99 , L_63 , V_100 ) ;
F_114 ( & V_227 -> V_240 ) ;
F_158 ( & V_227 -> V_239 ) ;
}
T_1
F_41 ( T_8 * V_20 )
{
return F_82 ( V_20 -> V_74 , V_20 , V_301 ) ;
}
T_1
F_42 ( T_8 * V_20 )
{
return F_85 ( V_20 -> V_74 , V_20 ) ;
}
T_30 *
F_160 ( T_2 V_1 )
{
return & V_1 -> V_302 ;
}
int
F_161 ( T_2 V_1 )
{
T_8 * V_20 ;
int V_303 = 0 , V_61 ;
V_61 = 0 ;
while ( ( V_20 = F_28 ( V_1 -> V_74 ,
V_1 , & V_61 ) ) != NULL ) {
V_303 += V_20 -> V_286 ;
F_19 ( V_20 ) ;
}
return V_303 ;
}
int
F_162 ( T_2 V_1 )
{
return V_1 -> V_92 ;
}
int
F_163 ( T_2 V_1 )
{
return V_1 -> V_304 ;
}
void
F_164 ( T_2 V_1 , int V_304 )
{
T_8 * V_20 ;
int V_61 ;
V_61 = 0 ;
while ( ( V_20 = F_28 ( V_1 -> V_74 ,
V_1 , & V_61 ) ) != NULL ) {
V_20 -> V_304 = V_304 ;
F_19 ( V_20 ) ;
}
V_1 -> V_304 = ( V_304 != 0 ) ;
}
static void V_253 ( unsigned long V_43 )
{
T_23 * V_74 = ( T_23 * ) V_43 ;
T_28 * V_227 = F_103 ( V_74 ) ;
if ( ! V_227 )
goto V_193;
F_7 ( V_99 ,
L_107 , V_100 ) ;
F_146 ( V_74 ) ;
V_193:
return;
}
T_1
F_165 ( T_7 V_27 )
{
T_1 V_67 = V_39 ;
T_8 * V_20 = F_166 ( V_27 ) ;
if ( V_20 ) {
V_67 = F_82 ( V_20 -> V_74 , V_20 ,
V_299 ) ;
F_19 ( V_20 ) ;
}
return V_67 ;
}
T_1
F_115 ( T_7 V_27 )
{
T_1 V_67 = V_39 ;
T_8 * V_20 = F_166 ( V_27 ) ;
if ( V_20 ) {
V_67 = F_82 ( V_20 -> V_74 , V_20 ,
V_301 ) ;
F_19 ( V_20 ) ;
}
return V_67 ;
}
T_1
F_116 ( T_7 V_27 )
{
T_1 V_67 = V_39 ;
T_8 * V_20 = F_166 ( V_27 ) ;
if ( V_20 ) {
V_67 = F_85 ( V_20 -> V_74 , V_20 ) ;
F_19 ( V_20 ) ;
}
return V_67 ;
}
void
F_167 ( T_23 * V_74 )
{
T_28 * V_227 = F_103 ( V_74 ) ;
int V_61 , V_305 = 0 ;
static const int V_306 = 64 ;
int V_307 = 0 ;
static const char * V_308 = L_108 ;
enum V_255 V_257 ;
enum V_267 V_261 ;
int V_309 ;
int V_282 ;
int V_283 ;
struct V_310 {
int V_101 ;
int V_311 ;
int V_303 ;
} V_312 [ V_306 ] ;
if ( ! V_227 )
return;
F_149 ( & V_227 -> V_243 ) ;
V_257 = V_227 -> V_257 ;
V_261 = V_227 -> V_261 ;
V_309 = V_227 -> V_298 ;
V_282 = V_227 -> V_229 ;
V_283 = V_74 -> V_205 ;
if ( V_283 > V_306 )
V_307 = 1 ;
for ( V_61 = 0 ; ( V_61 < V_283 ) && ( V_305 < V_306 ) ; V_61 ++ ) {
T_8 * V_285 = V_74 -> V_206 [ V_61 ] ;
if ( ! V_285 )
continue;
if ( V_307 && ! V_285 -> V_286 )
continue;
if ( V_285 -> V_81 != V_195 ) {
V_312 [ V_305 ] . V_101 = V_285 -> V_29 . V_101 ;
V_312 [ V_305 ] . V_311 = V_285 -> V_102 ;
V_312 [ V_305 ++ ] . V_303 = V_285 ->
V_286 ;
}
}
F_150 ( & V_227 -> V_243 ) ;
F_145 ( V_99 ,
L_109 ,
V_278 [ V_257 + V_279 ] ) ;
F_145 ( V_99 ,
L_110 ,
V_276 [ V_261 + V_277 ] ) ;
if ( V_307 )
F_145 ( V_99 , L_111
L_112
L_113 , V_283 ,
V_306 ) ;
for ( V_61 = 0 ; V_61 < V_305 ; V_61 ++ ) {
F_145 ( V_99 ,
L_114 ,
F_43 ( V_312 [ V_61 ] . V_101 ) ,
V_312 [ V_61 ] . V_311 ,
V_312 [ V_61 ] . V_303 ,
V_312 [ V_61 ] . V_303 ? V_308 : L_36 ) ;
}
F_145 ( V_99 ,
L_115 , V_309 ) ;
F_145 ( V_99 ,
L_116 , V_282 ) ;
F_168 ( V_74 ) ;
}
T_1
F_169 ( T_8 * V_20 )
{
T_28 * V_227 ;
T_1 V_67 = V_39 ;
if ( ! V_20 || ! V_20 -> V_74 )
goto V_193;
F_4 ( V_99 , L_63 , V_100 ) ;
V_227 = F_103 ( V_20 -> V_74 ) ;
F_149 ( & V_227 -> V_243 ) ;
if ( V_20 -> V_286 )
V_67 = V_17 ;
F_150 ( & V_227 -> V_243 ) ;
if ( V_67 == V_39 ) {
F_31 ( V_99 ,
L_117
L_118 , V_100 ,
F_43 ( V_20 -> V_29 . V_101 ) ,
V_20 -> V_102 , V_20 -> V_286 ,
V_227 -> V_229 ,
V_278 [ V_227 -> V_257 +
V_279 ] ) ;
F_167 ( V_20 -> V_74 ) ;
}
V_193:
return V_67 ;
}
void F_170 ( T_23 * V_74 )
{
( void ) V_74 ;
}
void F_171 ( T_23 * V_74 ,
T_31 V_313 , T_31 V_314 )
{
T_28 * V_227 = F_103 ( V_74 ) ;
F_7 ( V_99 , L_119 , V_74 -> V_78 ,
F_172 ( V_313 ) , F_172 ( V_314 ) ) ;
if ( V_74 -> V_315 == V_316 ) {
F_137 ( & V_227 -> V_243 ) ;
if ( ! V_227 -> V_254 ) {
char V_317 [ 16 ] ;
V_227 -> V_254 = 1 ;
F_135 ( & V_227 -> V_243 ) ;
snprintf ( V_317 , sizeof( V_317 ) , L_120 ,
V_74 -> V_78 ) ;
V_227 -> V_318 = F_173 (
& F_106 ,
( void * ) V_74 ,
V_317 ) ;
if ( F_174 ( V_227 -> V_318 ) ) {
F_31 ( V_99 ,
L_121 ,
V_317 ) ;
} else {
F_175 ( V_227 -> V_318 ) ;
}
} else
F_135 ( & V_227 -> V_243 ) ;
}
}
static int F_176 ( struct V_319 * V_320 )
{
struct V_321 * V_322 ;
struct V_323 * V_324 ;
int V_281 ;
void * V_325 ;
V_322 = F_177 ( V_320 -> V_188 . V_326 , L_122 , 0 ) ;
if ( ! V_322 ) {
F_178 ( & V_320 -> V_188 , L_123 ) ;
return - V_327 ;
}
V_324 = F_179 ( V_322 ) ;
F_180 ( V_322 ) ;
if ( ! V_324 )
return - V_328 ;
F_181 ( V_320 , V_324 ) ;
V_281 = F_182 ( V_320 , & V_222 ) ;
if ( V_281 != 0 )
goto V_329;
V_281 = F_183 ( & V_330 , V_189 , 1 , V_331 ) ;
if ( V_281 != 0 ) {
F_31 ( V_12 ,
L_124 ) ;
goto V_329;
}
F_184 ( & V_332 , & V_333 ) ;
V_332 . V_334 = V_335 ;
V_281 = F_185 ( & V_332 , V_330 , 1 ) ;
if ( V_281 != 0 ) {
F_31 ( V_12 ,
L_125 ) ;
goto V_336;
}
V_337 = F_186 ( V_335 , V_331 ) ;
V_325 = V_337 ;
if ( F_174 ( V_325 ) )
goto V_338;
V_339 = F_187 ( V_337 , NULL ,
V_330 , NULL , L_126 ) ;
V_325 = V_339 ;
if ( F_174 ( V_325 ) )
goto V_340;
V_281 = F_188 () ;
if ( V_281 != 0 )
goto V_341;
F_7 ( V_12 ,
L_127 ,
V_342 , V_156 ,
F_189 ( V_330 ) , F_190 ( V_330 ) ) ;
return 0 ;
V_341:
F_191 ( V_337 , V_330 ) ;
V_340:
F_192 ( V_337 ) ;
V_338:
F_193 ( & V_332 ) ;
V_281 = F_194 ( V_325 ) ;
V_336:
F_195 ( V_330 , 1 ) ;
V_329:
F_145 ( V_12 , L_128 ) ;
return V_281 ;
}
static int F_196 ( struct V_319 * V_320 )
{
F_197 () ;
F_191 ( V_337 , V_330 ) ;
F_192 ( V_337 ) ;
F_193 ( & V_332 ) ;
F_195 ( V_330 , 1 ) ;
return 0 ;
}
