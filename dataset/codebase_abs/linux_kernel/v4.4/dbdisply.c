static void * F_1 ( void * V_1 )
{
void * V_2 ;
T_1 V_3 ;
V_3 = strtoul ( V_1 , NULL , 16 ) ;
V_2 = F_2 ( V_3 ) ;
return ( V_2 ) ;
}
static void F_3 ( union V_4 * V_5 )
{
const struct V_6 * V_7 ;
V_7 = F_4 ( V_5 -> V_8 . V_9 ) ;
F_5 ( L_1 ) ;
F_5 ( L_2 , L_3 , V_5 -> V_8 . V_9 ) ;
F_6 ( F_5 ( L_4 , L_5 ,
V_7 -> V_10 ) ) ;
F_5 ( L_6 , L_7 , V_5 -> V_8 . V_11 . V_12 ) ;
F_5 ( L_6 , L_8 , V_5 -> V_8 . V_13 ) ;
F_5 ( L_6 , L_9 , V_5 -> V_8 . V_14 ) ;
}
void F_7 ( char * V_1 , char * V_15 )
{
void * V_2 ;
struct V_16 * V_17 ;
union V_18 * V_19 ;
T_2 V_20 = V_21 ;
char V_22 [ 80 ] ;
struct V_23 V_24 ;
T_3 V_25 ;
T_2 V_26 ;
if ( ! V_1 ) {
return;
}
if ( V_15 ) {
F_8 ( V_15 ) ;
if ( V_15 [ 0 ] == 'W' ) {
V_20 = V_27 ;
} else if ( V_15 [ 0 ] == 'D' ) {
V_20 = V_28 ;
} else if ( V_15 [ 0 ] == 'Q' ) {
V_20 = V_29 ;
}
}
V_24 . V_30 = sizeof( V_22 ) ;
V_24 . V_31 = V_22 ;
if ( ( V_1 [ 0 ] >= 0x30 ) && ( V_1 [ 0 ] <= 0x39 ) ) {
V_2 = F_1 ( V_1 ) ;
if ( ! F_9 ( V_2 , 16 ) ) {
F_5
( L_10 ,
V_2 ) ;
return;
}
switch ( F_10 ( V_2 ) ) {
case V_32 :
if ( ! F_9
( V_2 , sizeof( struct V_16 ) ) ) {
F_5
( L_11 ,
V_2 ) ;
return;
}
V_17 = V_2 ;
goto V_33;
case V_34 :
if ( ! F_9
( V_2 , sizeof( union V_18 ) ) ) {
F_5
( L_12 ,
V_2 ) ;
return;
}
F_11 ( V_2 ,
sizeof( union
V_18 ) ,
V_20 , V_35 ) ;
F_12 ( V_2 , 1 ) ;
break;
case V_36 :
if ( ! F_9
( V_2 , sizeof( union V_4 ) ) ) {
F_5
( L_13 ,
V_2 ) ;
return;
}
F_11 ( V_2 ,
sizeof( union
V_4 ) ,
V_20 , V_35 ) ;
F_3 ( (union V_4
* ) V_2 ) ;
break;
default:
F_5
( L_14 ,
F_10 ( V_2 ) ) ;
V_26 = 16 ;
if ( F_9 ( V_2 , 64 ) ) {
V_26 = 64 ;
}
F_11 ( V_2 , V_26 , V_20 ,
V_35 ) ;
break;
}
return;
}
V_17 = F_13 ( V_1 ) ;
if ( ! V_17 ) {
return;
}
V_33:
V_25 = F_14 ( V_17 , V_37 , & V_24 ) ;
if ( F_15 ( V_25 ) ) {
F_5 ( L_15 ) ;
}
else {
F_5 ( L_16 ,
V_17 , ( char * ) V_24 . V_31 ) ;
}
if ( ! F_9 ( V_17 , sizeof( struct V_16 ) ) ) {
F_5 ( L_17 , V_17 ) ;
return;
}
F_11 ( ( void * ) V_17 ,
sizeof( struct V_16 ) , V_20 ,
V_35 ) ;
F_16 ( V_17 , 1 ) ;
V_19 = F_17 ( V_17 ) ;
if ( V_19 ) {
F_5 ( L_18 , V_19 ) ;
if ( ! F_9
( V_19 , sizeof( union V_18 ) ) ) {
F_5
( L_19 ,
V_19 ) ;
return;
}
F_11 ( ( void * ) V_19 ,
sizeof( union V_18 ) ,
V_20 , V_35 ) ;
F_12 ( V_19 , 1 ) ;
}
}
void F_18 ( union V_4 * V_38 )
{
struct V_39 * V_40 ;
union V_18 * V_19 ;
struct V_16 * V_17 ;
union V_4 * V_41 ;
union V_4 * V_5 ;
const struct V_6 * V_42 ;
T_2 V_43 = 0 ;
T_2 V_44 = 0 ;
T_2 V_45 = 0 ;
T_2 V_46 = 0 ;
T_2 V_47 = 0 ;
T_2 V_48 = 0 ;
T_4 V_49 = FALSE ;
V_40 = F_19 ( V_50 ) ;
if ( ! V_40 ) {
F_5 ( L_20 ) ;
return;
}
V_19 = V_40 -> V_51 ;
V_17 = V_40 -> V_52 ;
F_5 ( L_21 ,
F_20 ( V_17 ) ) ;
F_5 ( L_22 ,
( T_2 ) V_19 -> V_53 . V_54 ,
( T_2 ) V_19 -> V_53 . V_55 ) ;
V_41 = V_38 ;
while ( V_41 -> V_8 . V_13 ) {
V_41 = V_41 -> V_8 . V_13 ;
}
V_5 = V_41 ;
while ( V_5 ) {
if ( V_5 == V_38 ) {
V_49 = TRUE ;
}
V_43 ++ ;
if ( V_49 ) {
V_46 ++ ;
}
V_42 = F_4 ( V_5 -> V_8 . V_9 ) ;
switch ( V_42 -> V_56 ) {
case V_57 :
if ( V_49 ) {
V_47 ++ ;
}
V_44 ++ ;
break;
case V_58 :
continue;
default:
if ( V_49 ) {
V_48 ++ ;
}
V_45 ++ ;
break;
}
V_5 = F_21 ( V_38 , V_5 ) ;
}
F_5
( L_23 ,
V_43 , V_45 , V_44 ) ;
F_5
( L_24 ,
V_46 , V_48 ,
V_47 ) ;
}
void F_22 ( void )
{
struct V_39 * V_40 ;
V_40 = F_19 ( V_50 ) ;
if ( ! V_40 ) {
F_5 ( L_20 ) ;
return;
}
F_23 ( V_40 ) ;
}
void F_24 ( void )
{
struct V_39 * V_40 ;
V_40 = F_19 ( V_50 ) ;
if ( ! V_40 ) {
F_5 ( L_20 ) ;
return;
}
F_25 ( V_40 ) ;
}
void F_26 ( void )
{
T_2 V_59 ;
struct V_39 * V_40 ;
union V_18 * V_19 ;
T_2 V_60 = 0 ;
struct V_16 * V_17 ;
union V_61 * V_62 ;
T_2 V_63 ;
V_40 = F_19 ( V_50 ) ;
if ( ! V_40 ) {
F_5 ( L_20 ) ;
return;
}
V_19 = V_40 -> V_51 ;
V_17 = V_40 -> V_52 ;
if ( V_40 -> V_64 ) {
V_60 = V_40 -> V_60 ;
}
F_5 ( L_25 ,
F_20 ( V_17 ) , V_60 ) ;
V_62 = V_40 -> V_64 ;
V_63 = ( V_60 - 1 ) % V_65 ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
V_19 = V_62 -> V_64 . V_19 [ V_63 ] ;
F_5 ( L_26 , V_59 ) ;
F_27 ( V_19 , V_40 ) ;
if ( V_63 == 0 ) {
V_62 = V_62 -> V_64 . V_14 ;
V_63 = V_65 ;
}
V_63 -- ;
}
}
void F_28 ( void )
{
struct V_39 * V_40 ;
struct V_16 * V_17 ;
V_40 = F_19 ( V_50 ) ;
if ( ! V_40 ) {
F_5 ( L_20 ) ;
return;
}
V_17 = V_40 -> V_52 ;
F_5 ( L_27 ) ;
while ( V_40 ) {
V_17 = V_40 -> V_52 ;
F_5 ( L_28 , F_20 ( V_17 ) ) ;
V_40 = V_40 -> V_14 ;
}
}
void F_29 ( char * V_10 )
{
struct V_16 * V_17 ;
struct V_66 * V_7 ;
T_3 V_25 ;
T_2 V_59 ;
V_17 = F_30 ( V_10 ) ;
if ( ! V_17 ) {
return;
}
V_25 = F_31 ( F_32 ( V_67 , V_17 ) , & V_7 ) ;
if ( F_15 ( V_25 ) ) {
F_5 ( L_29 ,
F_33 ( V_25 ) ) ;
return;
}
if ( V_7 -> V_68 & V_69 ) {
F_5 ( L_30 ,
F_34 ( V_7 -> V_3 ) ,
V_7 -> V_70 , V_7 -> V_71 ) ;
}
if ( V_7 -> V_68 & V_72 ) {
F_5 ( L_31 ,
V_7 -> V_73 [ 0 ] ,
V_7 -> V_73 [ 1 ] ,
V_7 -> V_73 [ 2 ] ,
V_7 -> V_73 [ 3 ] ) ;
}
if ( V_7 -> V_68 & V_74 ) {
F_5
( L_32 ,
V_7 -> V_75 [ 0 ] , V_7 -> V_75 [ 1 ] ,
V_7 -> V_75 [ 2 ] , V_7 -> V_75 [ 3 ] ,
V_7 -> V_75 [ 4 ] ) ;
}
if ( V_7 -> V_68 & V_76 ) {
F_5 ( L_33 , V_7 -> V_77 . string ) ;
}
if ( V_7 -> V_68 & V_78 ) {
F_5 ( L_34 , V_7 -> V_79 . string ) ;
}
if ( V_7 -> V_68 & V_80 ) {
F_5 ( L_35 , V_7 -> V_81 . string ) ;
}
if ( V_7 -> V_68 & V_82 ) {
for ( V_59 = 0 ; V_59 < V_7 -> V_83 . V_84 ; V_59 ++ ) {
F_5 ( L_36 , V_59 ,
V_7 -> V_83 . V_85 [ V_59 ] . string ) ;
}
}
F_35 ( V_7 ) ;
}
void
F_36 ( union V_18 * V_19 ,
struct V_39 * V_40 )
{
if ( ! V_86 ) {
return;
}
F_5 ( L_37 ) ;
F_27 ( V_19 , V_40 ) ;
F_5 ( L_38 ) ;
}
void
F_37 ( union V_18 * V_19 ,
struct V_39 * V_40 )
{
if ( ! V_86 ) {
return;
}
F_5 ( L_39 ) ;
F_27 ( V_19 , V_40 ) ;
}
void F_38 ( void )
{
struct V_87 * V_88 ;
struct V_89 * V_90 ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
char * V_95 ;
struct V_96 * V_97 ;
T_2 V_98 ;
T_2 V_99 = 0 ;
T_2 V_59 ;
T_2 V_100 ;
T_2 V_84 ;
char V_22 [ 80 ] ;
struct V_23 V_24 ;
T_3 V_25 ;
V_24 . V_30 = sizeof( V_22 ) ;
V_24 . V_31 = V_22 ;
V_99 = 0 ;
V_90 = V_101 ;
while ( V_90 ) {
V_88 = V_90 -> V_102 ;
while ( V_88 ) {
V_25 = F_14 ( V_88 -> V_17 ,
V_37 ,
& V_24 ) ;
if ( F_15 ( V_25 ) ) {
F_5
( L_15 ) ;
}
if ( V_88 -> V_17 == V_103 ) {
V_95 = L_40 ;
} else {
V_95 = L_41 ;
}
F_5
( L_42 ,
V_99 , V_88 , V_88 -> V_17 , V_22 ,
V_95 ) ;
F_5 ( L_43 ,
V_88 -> V_104 ,
V_88 -> V_105 ) ;
F_5
( L_44 ,
V_88 -> V_106 ,
V_88 -> V_106 +
( V_88 -> V_105 - 1 ) ,
V_90 -> V_107 ) ;
F_5
( L_45 ,
V_88 -> V_108 ,
F_34 ( V_88 -> V_108 ->
V_109 . V_3 ) ,
F_34 ( V_88 -> V_108 ->
V_110 . V_3 ) ) ;
F_5 ( L_46 ,
V_88 -> V_111 ) ;
for ( V_59 = 0 ; V_59 < V_88 -> V_104 ; V_59 ++ ) {
V_94 =
& V_88 -> V_108 [ V_59 ] ;
F_5 ( L_47
L_48
L_49 ,
V_59 ,
V_94 ->
V_112 ,
V_94 ->
V_112 +
( V_113 - 1 ) ,
V_94 ->
V_114 ,
V_94 ->
V_115 ,
F_34
( V_94 ->
V_109 . V_3 ) ,
F_34
( V_94 ->
V_110 . V_3 ) ) ;
for ( V_100 = 0 ; V_100 < V_113 ; V_100 ++ ) {
V_98 =
( V_59 * V_113 ) + V_100 ;
V_92 =
& V_88 -> V_111 [ V_98 ] ;
if ( F_39
( V_92 -> V_71 ) ==
V_116 ) {
continue;
}
F_5
( L_50 ,
V_88 -> V_106 +
V_98 , V_92 ,
V_92 -> V_117 ,
V_92 -> V_71 ) ;
if ( V_92 ->
V_71 & V_118 ) {
F_5 ( L_51 ) ;
} else {
F_5 ( L_52 ) ;
}
if ( V_92 ->
V_71 & V_119 ) {
F_5 ( L_53 ) ;
} else {
F_5 ( L_54 ) ;
}
switch ( F_39
( V_92 -> V_71 ) ) {
case V_116 :
F_5 ( L_55 ) ;
break;
case V_120 :
F_5 ( L_56 ) ;
break;
case V_121 :
F_5 ( L_57 ) ;
break;
case V_122 :
V_84 = 0 ;
V_97 =
V_92 -> V_123 .
V_124 ;
while ( V_97 ) {
V_84 ++ ;
V_97 = V_97 -> V_14 ;
}
F_5
( L_58 ,
V_84 ) ;
break;
case V_125 :
F_5 ( L_59 ) ;
break;
default:
F_5 ( L_60 ,
F_39
( V_92 ->
V_71 ) ) ;
break;
}
F_5 ( L_61 ) ;
}
}
V_99 ++ ;
V_88 = V_88 -> V_14 ;
}
V_90 = V_90 -> V_14 ;
}
}
void F_40 ( void )
{
union V_18 * V_19 ;
union V_18 * V_126 ;
T_5 V_127 ;
T_2 V_59 ;
F_5 ( L_62 ) ;
V_19 = F_17 ( V_128 ) ;
if ( V_19 ) {
for ( V_59 = 0 ; V_59 < F_41 ( V_129 ) ; V_59 ++ ) {
V_127 = V_129 [ V_59 ] ;
V_126 = V_19 -> V_130 . V_131 ;
F_5 ( V_132 ,
F_42 ( ( T_4 ) V_127 ) ,
V_127 ) ;
while ( V_126 ) {
if ( V_129 [ V_59 ] ==
V_126 -> V_133 . V_127 ) {
F_5
( V_134 ,
( V_126 -> V_133 .
V_135 &
V_136 )
? L_63 : L_64 ,
V_126 -> V_133 .
V_131 ) ;
goto V_137;
}
V_126 = V_126 -> V_133 . V_14 ;
}
F_5 ( L_65 ) ;
V_137: ;
}
V_126 = V_19 -> V_130 . V_131 ;
while ( V_126 ) {
if ( V_126 -> V_133 . V_127 >=
V_138 ) {
F_5 ( V_132 ,
L_66 ,
V_126 -> V_133 .
V_127 ) ;
F_5 ( V_134 ,
( V_126 -> V_133 .
V_135 &
V_136 )
? L_63 : L_64 ,
V_126 -> V_133 .
V_131 ) ;
}
V_126 = V_126 -> V_133 . V_14 ;
}
}
#if ( ! V_139 )
F_5 ( L_67 ) ;
for ( V_59 = 0 ; V_59 < V_140 ; V_59 ++ ) {
F_5 ( V_132 ,
F_43 ( V_59 ) , V_59 ) ;
if ( V_141 [ V_59 ] . V_131 ) {
F_5 ( V_134 , L_64 ,
V_141 [ V_59 ] .
V_131 ) ;
} else {
F_5 ( V_142 , L_68 ) ;
}
}
#endif
F_5 ( L_69 ) ;
for ( V_59 = 0 ; V_59 < F_41 ( V_143 ) ; V_59 ++ ) {
F_5 ( V_144 ,
V_143 [ V_59 ] . V_10 ) ;
if ( V_143 [ V_59 ] . V_131 ) {
F_5 ( V_134 , L_64 ,
V_143 [ V_59 ] . V_131 ) ;
} else {
F_5 ( V_142 , L_68 ) ;
}
}
F_5 ( L_70 ) ;
( void ) F_44 ( V_145 , V_146 ,
V_35 ,
V_147 , NULL , NULL ,
NULL ) ;
}
static T_3
V_147 ( V_67 V_148 ,
T_2 V_149 ,
void * V_150 , void * * V_151 )
{
struct V_16 * V_17 =
F_32 ( struct V_16 , V_148 ) ;
union V_18 * V_19 ;
union V_18 * V_126 ;
char * V_152 ;
V_19 = F_17 ( V_17 ) ;
if ( ! V_19 ) {
return ( V_153 ) ;
}
V_152 = F_45 ( V_17 ) ;
if ( ! V_152 ) {
return ( V_153 ) ;
}
V_126 = V_19 -> V_130 . V_131 ;
while ( V_126 ) {
F_5 ( V_132 ,
F_42 ( ( T_4 ) V_126 ->
V_133 . V_127 ) ,
V_126 -> V_133 . V_127 ) ;
F_5 ( V_154 ,
( V_126 -> V_133 . V_135 &
V_136 ) ? L_63
: L_64 , V_126 -> V_133 . V_131 ) ;
F_5 ( L_71 , V_152 , V_17 ) ;
V_126 = V_126 -> V_133 . V_14 ;
}
F_35 ( V_152 ) ;
return ( V_153 ) ;
}
