void F_1 ( T_1 * V_1 )
{
F_2 ( & V_1 -> V_2 -> V_3 , L_1 , V_4 ,
V_1 -> V_5 ) ;
if ( V_1 -> V_5 == V_6 )
return;
F_3 ( & V_1 -> V_7 ) ;
V_1 -> V_8 = 0 ;
V_1 -> V_9 = 0 ;
V_1 -> V_10 = 0 ;
F_4 ( & V_1 -> V_7 ) ;
}
void F_5 ( T_1 * V_1 )
{
F_2 ( & V_1 -> V_2 -> V_3 , L_1 , V_4 ,
V_1 -> V_5 ) ;
if ( V_1 -> V_5 == V_6 )
return;
F_3 ( & V_1 -> V_11 ) ;
V_1 -> V_12 = 0 ;
V_1 -> V_13 = 0 ;
V_1 -> V_14 = 0 ;
F_4 ( & V_1 -> V_11 ) ;
}
static int F_6 ( T_1 * V_1 , const char * V_15 ,
unsigned int V_16 )
{
int V_17 ;
F_3 ( & V_1 -> V_7 ) ;
if ( ( V_18 - V_1 -> V_8 ) >= V_16 ) {
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ ) {
V_1 -> V_20 [ V_1 -> V_10 ++ ] = V_15 [ V_19 ] ;
if ( V_1 -> V_10 >= V_18 )
V_1 -> V_10 = 0 ;
}
V_1 -> V_8 += V_16 ;
F_4 ( & V_1 -> V_7 ) ;
V_17 = F_7 ( V_1 ) ;
} else {
V_17 = V_21 ;
F_4 ( & V_1 -> V_7 ) ;
}
return V_17 ;
}
int F_8 ( T_1 * V_1 , const char T_2 * V_22 ,
unsigned int V_23 )
{
int V_17 = V_24 ;
char V_25 [ V_18 + 1 ] ;
if ( V_23 > V_18 )
return V_21 ;
if ( F_9 ( V_25 , V_22 , V_23 ) )
return - V_26 ;
V_25 [ V_23 ] = 0 ;
F_10 ( & V_1 -> V_27 ) ;
if ( V_23 > 0 )
{
F_2 ( & V_1 -> V_2 -> V_3 , L_2 , V_4 , V_23 ,
V_25 ) ;
V_17 = F_6 ( V_1 , V_25 , V_23 ) ;
}
F_11 ( V_1 , false ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_13 ( T_1 * V_1 , char V_28 )
{
int V_17 ;
F_10 ( & V_1 -> V_27 ) ;
V_17 = F_6 ( V_1 , & V_28 , 1 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_3 , V_28 , V_28 ) ;
F_11 ( V_1 , false ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_14 ( T_1 * V_1 , T_3 * V_29 , T_3 * error )
{
int V_30 ;
F_2 ( & V_1 -> V_2 -> V_3 , L_4 ) ;
* V_29 = 0xFFFFFFFF ;
V_30 = F_15 ( V_1 -> V_31 , F_16 ( V_1 -> V_31 , 0 ) ,
V_32 , ( V_33 | V_34 | V_35 ) , 0 , 0 ,
V_1 -> V_36 , sizeof( V_1 -> V_36 ) , V_37 ) ;
if ( V_30 != sizeof( V_1 -> V_36 ) ) {
F_17 ( & V_1 -> V_2 -> V_3 ,
L_5 , V_30 ) ;
V_1 -> V_5 = V_6 ;
* V_29 = 0 ;
* error = 0 ;
} else {
int V_38 ;
F_2 ( & V_1 -> V_2 -> V_3 ,
L_6 ,
V_1 -> V_36 [ 0 ] , V_1 -> V_36 [ 1 ] ) ;
* V_29 = V_1 -> V_36 [ 0 ] ;
* error = V_1 -> V_36 [ 1 ] ;
V_38 = V_1 -> V_31 -> V_39 . V_40 >> 8 ;
switch ( V_38 )
{
case 0 :
V_1 -> V_5 = V_41 ;
break;
default:
if ( ( V_38 >= 1 ) && ( V_38 <= 23 ) )
V_1 -> V_5 = ( short ) ( V_38 + 6 ) ;
else
V_1 -> V_5 = V_42 ;
break;
}
}
return V_1 -> V_5 >= 0 ? V_24 : V_1 -> V_5 ;
}
int F_18 ( T_1 * V_1 )
{
F_2 ( & V_1 -> V_2 -> V_3 , L_7 ,
V_1 -> V_43 ) ;
#ifdef F_19
int V_44 = V_45 ;
bool V_46 = false ;
unsigned int V_47 ;
F_3 ( & V_1 -> V_48 ) ;
if ( V_1 -> V_43 )
{
F_20 ( & V_1 -> V_2 - V_3 ,
L_8 ) ;
F_21 ( V_1 -> V_49 != NULL ) ;
F_4 ( & V_1 -> V_48 ) ;
V_46 = F_22 ( V_1 -> V_49 ) ;
if ( V_46 ) {
T_4 V_50 ;
V_50 . V_51 = - 10000000 ;
F_20 ( & V_1 -> V_2 - V_3 ,
L_9 ) ;
V_44 =
F_23 ( & V_1 -> V_52 ,
V_53 , V_54 , FALSE ,
& V_50 ) ;
} else {
F_20 ( & V_1 -> V_2 - V_3 ,
L_10 ) ;
V_44 = V_55 ;
}
F_24 ( V_56 ,
( L_11 ,
V_44 , V_44 ) ) ;
} else
F_4 ( & V_1 -> V_48 ) ;
F_20 ( & V_1 -> V_2 - V_3 , L_12 ) ;
return V_44 ;
#else
return V_24 ;
#endif
}
static int F_25 ( T_1 * V_1 , unsigned int * V_57 )
{
unsigned int V_29 , error ;
int V_17 = F_14 ( V_1 , & V_29 , & error ) ;
if ( V_17 == V_24 )
V_17 = ( V_29 == ( unsigned int ) - 1 ) ||
( ( V_29 & 0xff ) == 0x80 ) ;
* V_57 = V_29 ;
return V_17 ;
}
bool F_26 ( T_1 * V_1 )
{
int V_17 ;
F_2 ( & V_1 -> V_2 -> V_3 , L_13 , V_4 ) ;
F_27 ( V_1 ) ;
F_5 ( V_1 ) ;
F_1 ( V_1 ) ;
V_17 = F_28 ( V_1 -> V_31 , V_1 -> V_2 ) ;
F_12 ( & V_1 -> V_27 ) ;
if ( V_17 >= 0 )
{
V_17 = F_29 ( V_1 -> V_31 ) ;
F_30 ( V_1 -> V_31 ) ;
}
F_10 ( & V_1 -> V_27 ) ;
V_1 -> V_58 = V_59 ;
if ( V_17 == 0 )
{
unsigned int V_29 ;
V_17 = F_25 ( V_1 , & V_29 ) ;
if ( V_17 > 0 )
{
unsigned long V_60 = V_61 + 30 * V_37 ;
while ( ( V_17 > 0 ) && F_31 ( V_61 , V_60 ) ) {
F_32 () ;
V_17 = F_25 ( V_1 , & V_29 ) ;
}
}
if ( V_17 == 0 )
V_17 = V_29 == 0 ;
} else
V_17 = 0 ;
V_1 -> V_62 = false ;
return V_17 > 0 ;
}
bool F_33 ( T_1 * V_1 , bool V_63 , bool V_64 )
{
bool V_65 = false ;
bool V_66 ;
V_66 = ( ( V_1 -> V_58 == V_59 ) &&
( ! V_1 -> V_62 ) &&
( V_1 -> V_5 >= V_67 ) ) ;
F_2 ( & V_1 -> V_2 -> V_3 ,
L_14 ,
V_4 , V_1 -> V_58 , V_1 -> V_5 , V_1 -> V_62 ,
V_63 , V_66 ) ;
if ( ( V_63 ) &&
( V_1 -> V_12 || V_1 -> V_8 ) )
{
V_66 = false ;
F_2 ( & V_1 -> V_2 -> V_3 ,
L_15 , V_4 ) ;
}
if ( V_66 || ! V_64 )
{
unsigned int V_29 , error ;
F_2 ( & V_1 -> V_2 -> V_3 , L_16 , V_4 ) ;
if ( F_14 ( V_1 , & V_29 , & error ) == V_24 )
{
if ( ( V_29 & 0xFF ) == 0 )
V_65 = true ;
}
}
if ( ! V_65 && V_64 )
{
F_20 ( & V_1 -> V_2 -> V_3 , L_17 ,
V_4 , V_66 , V_1 -> V_5 , V_63 ,
V_1 -> V_62 ) ;
V_65 = F_26 ( V_1 ) ;
}
return V_65 ;
}
int F_34 ( T_1 * V_1 )
{
F_10 ( & V_1 -> V_27 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_18 ) ;
F_33 ( V_1 , true , true ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_24 ;
}
int GetChar ( T_1 * V_1 )
{
int V_17 = V_68 ;
F_10 ( & V_1 -> V_27 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_19 ) ;
F_11 ( V_1 , false ) ;
F_7 ( V_1 ) ;
F_3 ( & V_1 -> V_11 ) ;
if ( V_1 -> V_12 > 0 )
{
V_17 = V_1 -> V_69 [ V_1 -> V_13 ++ ] ;
if ( V_1 -> V_13 >= V_70 )
V_1 -> V_13 = 0 ;
V_1 -> V_12 -- ;
} else
V_17 = V_68 ;
F_4 ( & V_1 -> V_11 ) ;
F_11 ( V_1 , false ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_35 ( T_1 * V_1 , char T_2 * V_71 , int V_23 )
{
int V_72 ;
int V_17 = V_68 ;
if ( V_23 <= 0 )
return - V_73 ;
F_10 ( & V_1 -> V_27 ) ;
F_11 ( V_1 , false ) ;
F_7 ( V_1 ) ;
F_3 ( & V_1 -> V_11 ) ;
V_72 = V_1 -> V_12 ;
if ( V_72 > V_23 )
V_72 = V_23 ;
if ( V_72 > 0 )
{
char V_25 [ V_70 + 1 ] ;
int V_30 = 0 ;
int V_74 ;
char V_75 ;
do {
V_75 = V_1 -> V_69 [ V_1 -> V_13 ++ ] ;
if ( V_75 == V_76 )
V_75 = ( char ) 0 ;
if ( V_1 -> V_13 >= V_70 )
V_1 -> V_13 = 0 ;
V_25 [ V_30 ++ ] = V_75 ;
}
while ( ( V_30 < V_72 ) && V_75 );
V_74 = V_30 ;
if ( V_75 )
{
V_25 [ V_30 ] = ( char ) 0 ;
if ( V_30 < V_23 )
++ V_74 ;
}
V_1 -> V_12 -= V_30 ;
F_4 ( & V_1 -> V_11 ) ;
F_2 ( & V_1 -> V_2 -> V_3 ,
L_20 , V_30 , V_25 ) ;
if ( F_36 ( V_71 , V_25 , V_74 ) )
V_17 = - V_26 ;
else
V_17 = V_30 ;
} else
F_4 ( & V_1 -> V_11 ) ;
F_11 ( V_1 , false ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_37 ( T_1 * V_1 )
{
int V_17 ;
F_10 ( & V_1 -> V_27 ) ;
F_11 ( V_1 , false ) ;
F_7 ( V_1 ) ;
V_17 = V_1 -> V_12 ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_38 ( T_1 * V_1 )
{
int V_17 = 0 ;
F_10 ( & V_1 -> V_27 ) ;
F_11 ( V_1 , false ) ;
F_7 ( V_1 ) ;
F_3 ( & V_1 -> V_11 ) ;
if ( V_1 -> V_12 > 0 )
{
unsigned int V_77 = V_1 -> V_13 ;
unsigned int V_78 = V_1 -> V_14 ;
do {
if ( V_1 -> V_69 [ V_77 ++ ] == V_76 )
++ V_17 ;
if ( V_77 >= V_70 )
V_77 = 0 ;
}
while ( V_77 != V_78 );
}
F_4 ( & V_1 -> V_11 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_21 , V_17 ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_39 ( T_1 * V_1 )
{
int V_17 ;
F_10 ( & V_1 -> V_27 ) ;
F_7 ( V_1 ) ;
V_17 = ( int ) ( V_18 - V_1 -> V_8 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_22 , V_17 ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_40 ( T_1 * V_1 , int V_79 )
{
int V_17 = V_24 ;
if ( ( V_79 < 0 ) || ( V_79 >= V_80 ) ) {
V_17 = V_81 ;
F_17 ( & V_1 -> V_2 -> V_3 , L_23 ,
V_4 , V_79 ) ;
} else {
T_5 * V_82 = & V_1 -> V_83 [ V_79 ] ;
if ( ! V_82 -> V_84 )
V_17 = V_85 ;
else {
struct V_86 * * V_87 = 0 ;
int V_88 = 0 ;
int V_89 ;
F_2 ( & V_1 -> V_2 -> V_3 , L_24 , V_4 ,
V_79 ) ;
F_3 ( & V_1 -> V_48 ) ;
if ( ( V_1 -> V_90 == V_79 )
&& ( V_1 -> V_58 > V_59 ) ) {
V_17 = V_91 ;
F_17 ( & V_1 -> V_2 -> V_3 ,
L_25 ,
V_4 , V_79 ) ;
} else {
V_87 = V_82 -> V_87 ;
V_88 = V_82 -> V_88 ;
if ( V_82 -> V_92 )
F_41 ( & V_82 -> V_93 ) ;
if ( V_1 -> V_94
&& ( V_1 -> V_95 . V_96 == V_79 ) )
V_1 -> V_94 = false ;
memset ( V_82 , 0 ,
sizeof( T_5 ) -
sizeof( V_97 ) ) ;
}
F_4 ( & V_1 -> V_48 ) ;
if ( V_87 )
{
F_2 ( & V_1 -> V_2 -> V_3 , L_26 ,
V_4 , V_88 ) ;
for ( V_89 = 0 ; V_89 < V_88 ; ++ V_89 ) {
if ( V_87 [ V_89 ] ) {
F_42 ( V_87 [ V_89 ] ) ;
F_43 ( V_87 [ V_89 ] ) ;
}
}
F_44 ( V_87 ) ;
F_2 ( & V_1 -> V_2 -> V_3 ,
L_27 , V_4 ) ;
}
}
}
return V_17 ;
}
static int F_45 ( T_1 * V_1 , int V_79 , char T_2 * V_98 ,
unsigned int V_99 , bool V_100 , bool V_101 )
{
unsigned long V_102 = ( ( unsigned long ) V_98 ) & V_103 ;
unsigned int V_104 = ( ( unsigned long ) V_98 ) & ( V_105 - 1 ) ;
int V_106 = ( V_99 + V_104 + V_105 - 1 ) >> V_107 ;
T_5 * V_82 = & V_1 -> V_83 [ V_79 ] ;
struct V_86 * * V_87 = 0 ;
int V_88 = 0 ;
int V_17 = F_40 ( V_1 , V_79 ) ;
if ( ( V_17 != V_85 ) &&
( V_17 != V_24 ) )
return V_17 ;
if ( ! F_46 ( V_108 , V_98 , V_99 ) )
return - V_26 ;
V_87 =
(struct V_86 * * ) F_47 ( V_106 * sizeof( struct V_86 * ) , V_109 ) ;
if ( ! V_87 ) {
V_17 = V_110 ;
goto error;
}
F_2 ( & V_1 -> V_2 -> V_3 , L_28 ,
V_4 , V_98 , V_99 , V_100 ) ;
F_48 ( & V_111 -> V_112 -> V_113 ) ;
V_88 =
F_49 ( V_111 , V_111 -> V_112 , V_102 , V_106 , 1 , 0 , V_87 , 0 ) ;
F_50 ( & V_111 -> V_112 -> V_113 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_29 , V_4 , V_88 ) ;
if ( V_88 > 0 )
{
F_3 ( & V_1 -> V_48 ) ;
V_82 -> V_114 = V_98 ;
V_82 -> V_115 = V_104 ;
V_82 -> V_99 = V_99 ;
V_82 -> V_87 = V_87 ;
V_82 -> V_88 = V_88 ;
V_82 -> V_100 = V_100 ;
V_82 -> V_101 = V_101 ;
V_82 -> V_116 [ 0 ] . V_117 = 0 ;
V_82 -> V_116 [ 0 ] . V_118 = 0 ;
V_82 -> V_116 [ 1 ] . V_117 = 0 ;
V_82 -> V_116 [ 1 ] . V_118 = 0 ;
V_82 -> V_84 = true ;
F_4 ( & V_1 -> V_48 ) ;
V_17 = V_24 ;
} else {
V_17 = V_119 ;
goto error;
}
return V_17 ;
error:
F_44 ( V_87 ) ;
return V_17 ;
}
int F_51 ( T_1 * V_1 , T_6 T_2 * V_120 )
{
int V_17 ;
T_6 V_121 ;
if ( F_9 ( & V_121 , V_120 , sizeof( V_121 ) ) )
return - V_26 ;
F_10 ( & V_1 -> V_27 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_30 , V_4 ,
V_121 . V_122 , V_121 . V_99 ) ;
V_17 =
F_45 ( V_1 , V_121 . V_122 ,
( char T_2 * ) ( ( unsigned long ) V_121 . V_114 ) , V_121 . V_99 ,
false , false ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_52 ( T_1 * V_1 , int V_79 )
{
int V_17 ;
F_10 ( & V_1 -> V_27 ) ;
V_17 = F_40 ( V_1 , V_79 ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_53 ( T_1 * V_1 , T_7 T_2 * V_123 )
{
int V_17 = V_24 ;
T_7 V_124 ;
if ( F_9 ( & V_124 , V_123 , sizeof( V_124 ) ) )
return - V_26 ;
if ( V_124 . V_122 >= V_80 )
return V_81 ;
else {
T_5 * V_82 = & V_1 -> V_83 [ V_124 . V_122 ] ;
F_10 ( & V_1 -> V_27 ) ;
F_3 ( & V_1 -> V_48 ) ;
if ( V_82 -> V_84 )
{
V_82 -> V_125 = V_124 . V_126 ;
V_82 -> V_92 = V_124 . V_99 ;
V_82 -> V_127 = V_124 . V_128 & 1 ;
V_82 -> V_129 = 0 ;
} else
V_17 = V_85 ;
F_4 ( & V_1 -> V_48 ) ;
F_12 ( & V_1 -> V_27 ) ;
}
return V_17 ==
V_24 ? ( V_124 . V_130 ? 1 : V_24 ) : V_17 ;
}
int F_54 ( T_1 * V_1 , int V_79 , int V_131 )
{
int V_17 ;
if ( ( unsigned ) V_79 >= V_80 )
return V_81 ;
else {
int V_132 ;
T_5 * V_82 = & V_1 -> V_83 [ V_79 ] ;
V_131 = ( V_131 * V_37 + 999 ) / 1000 ;
F_10 ( & V_1 -> V_27 ) ;
if ( ! V_82 -> V_84 || ! V_82 -> V_92 )
return V_85 ;
F_12 ( & V_1 -> V_27 ) ;
if ( V_131 )
V_132 =
F_55 ( V_82 -> V_93 ,
V_82 -> V_129
|| ! V_82 -> V_84 ,
V_131 ) ;
else
V_132 =
F_56 ( V_82 -> V_93 , V_82 -> V_129
|| ! V_82 -> V_84 ) ;
if ( V_132 )
V_17 = - V_133 ;
else
V_17 = V_82 -> V_129 ;
F_3 ( & V_1 -> V_48 ) ;
V_82 -> V_129 = 0 ;
F_4 ( & V_1 -> V_48 ) ;
}
return V_17 ;
}
int F_57 ( T_1 * V_1 , int V_79 )
{
int V_17 ;
if ( ( unsigned ) V_79 >= V_80 )
V_17 = V_81 ;
else {
T_5 * V_82 = & V_1 -> V_83 [ V_79 ] ;
F_10 ( & V_1 -> V_27 ) ;
F_3 ( & V_1 -> V_48 ) ;
V_17 = V_82 -> V_129 ;
V_82 -> V_129 = 0 ;
F_4 ( & V_1 -> V_48 ) ;
F_12 ( & V_1 -> V_27 ) ;
}
return V_17 ;
}
int F_58 ( T_1 * V_1 , T_8 T_2 * V_134 )
{
int V_17 = V_24 ;
unsigned int V_135 ;
F_10 ( & V_1 -> V_27 ) ;
V_135 = V_1 -> V_90 ;
if ( V_135 >= V_80 )
V_17 = V_81 ;
else {
T_8 V_136 ;
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_137 = V_1 -> V_83 [ V_135 ] . V_99 ;
V_136 . V_138 = ( long long ) ( ( long ) V_1 -> V_83 [ V_135 ] . V_114 ) ;
V_136 . V_139 = V_140 ;
V_136 . V_141 = 1 ;
V_136 . V_142 [ 0 ] . V_143 =
( long long ) ( V_136 . V_138 + V_1 -> V_144 ) ;
V_136 . V_142 [ 0 ] . V_137 = V_136 . V_137 ;
if ( F_36 ( V_134 , & V_136 , sizeof( V_136 ) ) )
V_17 = - V_26 ;
}
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_59 ( T_1 * V_1 )
{
F_2 ( & V_1 -> V_2 -> V_3 , L_13 , V_4 ) ;
F_10 ( & V_1 -> V_27 ) ;
F_1 ( V_1 ) ;
F_5 ( V_1 ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_24 ;
}
int F_60 ( T_1 * V_1 )
{
int V_17 = V_1 -> V_58 != V_59 ;
F_2 ( & V_1 -> V_2 -> V_3 , L_31 , V_4 , V_17 ) ;
return V_17 ;
}
int F_61 ( T_1 * V_1 )
{
int V_17 ;
F_10 ( & V_1 -> V_27 ) ;
F_33 ( V_1 , false , false ) ;
V_17 = V_1 -> V_5 ;
F_12 ( & V_1 -> V_27 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_31 , V_4 , V_17 ) ;
return V_17 ;
}
int F_62 ( T_1 * V_1 )
{
int V_30 ;
F_10 ( & V_1 -> V_27 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_13 , V_4 ) ;
F_27 ( V_1 ) ;
F_5 ( V_1 ) ;
F_1 ( V_1 ) ;
V_1 -> V_58 = V_59 ;
V_30 = F_15 ( V_1 -> V_31 , F_16 ( V_1 -> V_31 , 0 ) , V_145 , ( V_146 | V_34 | V_35 ) , 0 , 0 , 0 , 0 , V_37 ) ;
V_1 -> V_147 = V_61 + V_37 * 30 ;
F_12 ( & V_1 -> V_27 ) ;
if ( V_30 < 0 )
F_17 ( & V_1 -> V_2 -> V_3 , L_32 , V_4 , V_30 ) ;
return V_30 < 0 ? V_55 : V_24 ;
}
int F_63 ( T_1 * V_1 , T_9 T_2 * V_148 )
{
unsigned int V_29 , error ;
int V_17 ;
T_9 V_149 ;
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
F_10 ( & V_1 -> V_27 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_13 , V_4 ) ;
V_17 = F_14 ( V_1 , & V_29 , & error ) ;
if ( V_17 == V_24 )
V_17 = F_14 ( V_1 , & V_29 , & error ) ;
if ( V_17 != V_24 )
{
F_17 ( & V_1 -> V_2 -> V_3 ,
L_33 , V_4 ,
V_17 ) ;
V_29 = 0x80 ;
error = 0 ;
V_17 = V_24 ;
}
if ( ( V_29 == - 1 ) && ( error == - 1 ) )
{
F_17 ( & V_1 -> V_2 -> V_3 ,
L_34 ,
V_4 ) ;
V_29 = 0x80 ;
error = 0 ;
}
if ( ( V_29 & 0xFF ) == 0x80 )
{
if ( V_29 & 0x00FF0000 )
{
V_149 . V_150 = ( V_29 & 0x00FF0000 ) >> 16 ;
V_149 . V_151 = error & 0x0000FFFF ;
V_149 . V_152 = ( error & 0xFFFF0000 ) >> 16 ;
F_2 ( & V_1 -> V_2 -> V_3 , L_35 ,
V_149 . V_150 ) ;
} else
{
unsigned long V_153 = V_61 ;
if ( F_64 ( V_153 , V_1 -> V_147 ) ) {
V_149 . V_150 = - 2 ;
F_2 ( & V_1 -> V_2 -> V_3 ,
L_36 ) ;
} else
F_2 ( & V_1 -> V_2 -> V_3 ,
L_37 ) ;
}
} else {
V_149 . V_150 = - 1 ;
F_2 ( & V_1 -> V_2 -> V_3 , L_38 ) ;
}
if ( V_149 . V_150 < 0 )
{
if ( ( V_1 -> V_154 == 4 ) && ( V_1 -> V_155 <= V_156 ) )
F_26 ( V_1 ) ;
else
F_33 ( V_1 , true , true ) ;
}
F_12 ( & V_1 -> V_27 ) ;
if ( F_36 ( V_148 , & V_149 , sizeof( V_149 ) ) )
return - V_26 ;
return V_17 ;
}
int F_65 ( T_1 * V_1 )
{
int V_17 = V_157 ;
F_10 ( & V_1 -> V_27 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_13 , V_4 ) ;
switch ( V_1 -> V_155 ) {
case V_158 :
V_17 = V_67 ;
break;
case V_159 :
V_17 = V_160 ;
break;
case V_161 :
V_17 = V_41 ;
break;
default:
if ( ( V_1 -> V_155 >= V_156 ) && ( V_1 -> V_155 <= 25 ) )
V_17 = V_1 -> V_155 + 4 ;
else
V_17 = V_157 ;
}
F_2 ( & V_1 -> V_2 -> V_3 , L_39 , V_4 , V_17 ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_66 ( T_1 * V_1 )
{
int V_17 = V_162 | V_163 |
V_164 | V_165 ;
F_2 ( & V_1 -> V_2 -> V_3 , L_13 , V_4 ) ;
F_10 ( & V_1 -> V_27 ) ;
if ( V_1 -> V_166 )
V_17 |= V_167 ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
static int F_67 ( T_1 * V_1 , unsigned char V_168 ,
unsigned int V_169 )
{
int V_17 ;
F_2 ( & V_1 -> V_2 -> V_3 , L_40 , V_4 ) ;
V_17 = F_15 ( V_1 -> V_31 , F_68 ( V_1 -> V_31 , 0 ) , V_168 , ( V_146 | V_34 | V_35 ) , ( unsigned short ) V_169 , ( unsigned short ) ( V_169 >> 16 ) , 0 , 0 , V_37 ) ;
if ( V_17 < 0 )
F_17 ( & V_1 -> V_2 -> V_3 , L_41 , V_4 ,
V_17 ) ;
return V_17 ;
}
int F_69 ( T_1 * V_1 , T_10 T_2 * V_170 )
{
int V_17 ;
T_10 V_171 ;
if ( F_9 ( & V_171 , V_170 , sizeof( V_171 ) ) )
return - V_26 ;
F_10 ( & V_1 -> V_27 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_42 , V_4 , V_171 . V_172 ) ;
V_17 = F_67 ( V_1 , V_173 , V_171 . V_172 ) ;
if ( V_17 == V_24 )
V_17 = F_67 ( V_1 , V_174 , V_171 . V_175 ) ;
if ( V_17 == V_24 )
V_17 = F_67 ( V_1 , V_176 , V_171 . V_177 ) ;
if ( V_17 == V_24 )
V_17 = F_67 ( V_1 , V_178 , 0 ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_70 ( T_1 * V_1 , T_10 T_2 * V_170 )
{
int V_17 ;
T_10 V_171 ;
if ( F_9 ( & V_171 , V_170 , sizeof( V_171 ) ) )
return - V_26 ;
F_10 ( & V_1 -> V_27 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_42 , V_4 , V_171 . V_172 ) ;
V_17 = F_67 ( V_1 , V_173 , V_171 . V_172 ) ;
if ( V_17 == V_24 )
V_17 = F_67 ( V_1 , V_174 , V_171 . V_175 ) ;
if ( V_17 == V_24 )
V_17 = F_67 ( V_1 , V_176 , V_171 . V_177 ) ;
if ( V_17 == V_24 )
V_17 = F_67 ( V_1 , V_179 , V_171 . V_180 ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_71 ( T_1 * V_1 , T_10 T_2 * V_170 )
{
int V_17 ;
T_10 V_171 ;
if ( F_9 ( & V_171 , V_170 , sizeof( V_171 ) ) )
return - V_26 ;
F_10 ( & V_1 -> V_27 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_42 , V_4 , V_171 . V_172 ) ;
V_17 = F_67 ( V_1 , V_173 , V_171 . V_172 ) ;
if ( V_17 == V_24 )
V_17 = F_67 ( V_1 , V_181 , V_171 . V_182 ) ;
if ( V_17 == V_24 )
V_17 = F_67 ( V_1 , V_183 , V_171 . V_184 ) ;
if ( V_17 == V_24 )
V_17 = F_67 ( V_1 , V_174 , V_171 . V_175 ) ;
if ( V_17 == V_24 )
V_17 = F_67 ( V_1 , V_176 , V_171 . V_177 ) ;
if ( V_17 == V_24 )
V_17 = F_67 ( V_1 , V_185 , 0 ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_72 ( T_1 * V_1 , T_10 T_2 * V_170 )
{
int V_17 ;
T_10 V_171 ;
if ( F_9 ( & V_171 , V_170 , sizeof( V_171 ) ) )
return - V_26 ;
F_10 ( & V_1 -> V_27 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_13 , V_4 ) ;
V_17 = F_67 ( V_1 , V_181 , V_171 . V_182 ) ;
if ( V_17 == V_24 )
V_17 = F_67 ( V_1 , V_183 , V_171 . V_184 ) ;
if ( V_17 == V_24 )
V_17 = F_67 ( V_1 , V_174 , V_171 . V_175 ) ;
if ( V_17 == V_24 )
V_17 = F_67 ( V_1 , V_176 , V_171 . V_177 ) ;
if ( V_17 == V_24 )
V_17 = F_67 ( V_1 , V_186 , 0 ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_73 ( T_1 * V_1 , T_10 T_2 * V_170 )
{
int V_17 ;
T_10 V_171 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
F_10 ( & V_1 -> V_27 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_13 , V_4 ) ;
V_17 = F_15 ( V_1 -> V_31 , F_16 ( V_1 -> V_31 , 0 ) ,
V_187 , ( V_33 | V_34 | V_35 ) , 0 , 0 ,
& V_171 . V_180 , sizeof( V_171 . V_180 ) , V_37 ) ;
if ( V_17 == sizeof( V_171 . V_180 ) ) {
if ( F_36 ( V_170 , & V_171 , sizeof( V_171 ) ) )
V_17 = - V_26 ;
else
V_17 = V_24 ;
} else
F_17 ( & V_1 -> V_2 -> V_3 , L_43 , V_4 ,
V_17 ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_74 ( T_1 * V_1 )
{
int V_17 ;
unsigned int V_188 , V_189 ;
F_10 ( & V_1 -> V_27 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_13 , V_4 ) ;
V_17 = F_14 ( V_1 , & V_188 , & V_189 ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_75 ( T_1 * V_1 , T_6 T_2 * V_120 )
{
int V_17 ;
bool V_190 ;
T_6 V_121 ;
if ( F_9 ( & V_121 , V_120 , sizeof( V_121 ) ) )
return - V_26 ;
F_10 ( & V_1 -> V_27 ) ;
F_2 ( & V_1 -> V_2 -> V_3 , L_30 , V_4 ,
V_121 . V_122 , V_121 . V_99 ) ;
V_190 = V_121 . V_191 != 0 ;
V_17 =
F_45 ( V_1 , V_121 . V_122 ,
( char T_2 * ) ( ( unsigned long ) V_121 . V_114 ) , V_121 . V_99 ,
true , V_190 ) ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_76 ( T_1 * V_1 , T_11 T_2 * V_192 )
{
int V_17 = V_24 ;
unsigned int V_79 ;
T_11 V_193 ;
F_2 ( & V_1 -> V_2 -> V_3 , L_13 , V_4 ) ;
if ( F_9 ( & V_193 , V_192 , sizeof( V_193 ) ) )
return - V_26 ;
F_10 ( & V_1 -> V_27 ) ;
V_79 = V_193 . V_79 ;
V_193 . V_117 = 0 ;
V_193 . V_118 = 0 ;
if ( V_79 < V_80 )
{
T_5 * V_194 = & V_1 -> V_83 [ V_79 ] ;
F_3 ( & V_1 -> V_48 ) ;
if ( ( V_194 -> V_84 ) && ( V_194 -> V_100 ) &&
( V_194 -> V_101 ) )
{
if ( V_194 -> V_116 [ 0 ] . V_118 > 0 )
{
V_193 . V_117 = V_194 -> V_116 [ 0 ] . V_117 ;
V_193 . V_118 = V_194 -> V_116 [ 0 ] . V_118 ;
F_2 ( & V_1 -> V_2 -> V_3 ,
L_44 ,
V_4 , V_193 . V_118 , V_193 . V_117 ) ;
}
} else
V_17 = V_85 ;
F_4 ( & V_1 -> V_48 ) ;
} else
V_17 = V_81 ;
if ( F_36 ( V_192 , & V_193 , sizeof( V_193 ) ) )
V_17 = - V_26 ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
int F_77 ( T_1 * V_1 , T_11 T_2 * V_192 )
{
int V_17 = V_24 ;
unsigned int V_79 , V_195 , V_196 ;
T_11 V_193 ;
F_2 ( & V_1 -> V_2 -> V_3 , L_13 , V_4 ) ;
if ( F_9 ( & V_193 , V_192 , sizeof( V_193 ) ) )
return - V_26 ;
F_10 ( & V_1 -> V_27 ) ;
V_79 = V_193 . V_79 ;
V_195 = V_193 . V_117 ;
V_196 = V_193 . V_118 ;
V_193 . V_117 = 0 ;
V_193 . V_118 = 0 ;
if ( V_79 < V_80 )
{
T_5 * V_194 = & V_1 -> V_83 [ V_79 ] ;
F_3 ( & V_1 -> V_48 ) ;
if ( ( V_194 -> V_84 ) && ( V_194 -> V_100 ) &&
( V_194 -> V_101 ) )
{
bool V_197 = false ;
if ( ( V_194 -> V_116 [ 0 ] . V_118 >= V_196 ) &&
( V_194 -> V_116 [ 0 ] . V_117 == V_195 ) )
{
V_194 -> V_116 [ 0 ] . V_118 -= V_196 ;
V_194 -> V_116 [ 0 ] . V_117 += V_196 ;
if ( V_194 -> V_116 [ 0 ] . V_118 == 0 )
{
if ( V_194 -> V_116 [ 1 ] . V_118 )
{
V_194 -> V_116 [ 0 ] = V_194 -> V_116 [ 1 ] ;
V_194 -> V_116 [ 1 ] . V_118 = 0 ;
V_194 -> V_116 [ 1 ] . V_117 = 0 ;
} else
V_194 -> V_116 [ 0 ] . V_117 = 0 ;
}
F_2 ( & V_1 -> V_2 -> V_3 ,
L_45 ,
V_4 , V_196 , V_195 ,
V_194 -> V_116 [ 0 ] . V_118 ,
V_194 -> V_116 [ 0 ] . V_117 ,
V_1 -> V_94 ) ;
if ( V_194 -> V_116 [ 0 ] . V_118 > 0 )
{
V_193 . V_117 =
V_194 -> V_116 [ 0 ] . V_117 ;
V_193 . V_118 = V_194 -> V_116 [ 0 ] . V_118 ;
}
V_197 = V_1 -> V_94 ;
if ( V_197 && V_1 -> V_43 ) {
F_17 ( & V_1 -> V_2 -> V_3 ,
L_46 ,
V_4 ) ;
V_197 = false ;
}
} else {
F_17 ( & V_1 -> V_2 -> V_3 ,
L_47 ,
V_4 , V_196 , V_195 ,
V_194 -> V_116 [ 0 ] . V_118 ,
V_194 -> V_116 [ 0 ] . V_117 ) ;
V_17 = V_110 ;
}
if ( V_197 )
{
int V_198 =
F_78 ( V_1 , ! V_1 -> V_95 . V_199 ,
V_1 -> V_95 . V_96 ,
V_1 -> V_95 . V_117 ,
V_1 -> V_95 . V_118 ) ;
if ( V_198 != V_24 )
F_17 ( & V_1 -> V_2 -> V_3 ,
L_48 ,
V_4 , V_198 ) ;
}
} else
V_17 = V_85 ;
F_4 ( & V_1 -> V_48 ) ;
} else
V_17 = V_81 ;
if ( F_36 ( V_192 , & V_193 , sizeof( V_193 ) ) )
return - V_26 ;
F_12 ( & V_1 -> V_27 ) ;
return V_17 ;
}
