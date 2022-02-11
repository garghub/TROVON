int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_6 & V_7 )
return - V_8 ;
if ( V_2 -> V_9 == NULL )
return - V_8 ;
if ( F_2 ( V_5 ) )
return - V_8 ;
F_3 ( ( V_10 T_1 ) F_4 ( V_4 ) , V_2 -> V_9 + V_3 ) ;
return 0 ;
}
T_1 F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_6 & V_7 )
return 0xffffffffffffffffull ;
if ( ( V_2 -> V_6 & V_11 ) &&
( V_3 == V_12 ) )
return 0x000000000000ffffull ;
if ( ( V_2 -> V_6 & V_13 ) &&
( V_3 == V_12 ) )
return 0x00000000ffff0000ull ;
if ( V_2 -> V_9 == NULL )
return 0xffffffffffffffffull ;
return F_6 ( ( V_10 V_14 ) F_7 ( V_2 -> V_9 + V_3 ) ) ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_6 & V_7 )
return - V_8 ;
if ( V_2 -> V_9 == NULL )
return - V_8 ;
if ( F_2 ( V_5 ) )
return - V_8 ;
F_9 ( ( V_10 T_2 ) F_10 ( V_4 ) , V_2 -> V_9 + V_3 ) ;
return 0 ;
}
T_2 F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_6 & V_7 )
return 0xffffffff ;
if ( V_2 -> V_9 == NULL )
return 0xffffffff ;
return F_12 ( ( V_10 V_15 ) F_13 ( V_2 -> V_9 + V_3 ) ) ;
}
int F_14 ( struct V_1 * V_2 , char * V_16 , int V_17 )
{
int V_18 , V_19 ;
T_2 V_20 = ( T_2 ) V_2 -> V_21 ;
memset ( V_16 , 0 , V_17 ) ;
for ( V_18 = 0 , V_19 = 0 ; V_19 < F_15 ( V_17 , 4 ) ; V_19 ++ ) {
char V_22 = ( char ) ( ( V_20 >> ( 24 - V_19 * 8 ) ) & 0xff ) ;
if ( V_22 == ' ' )
continue;
V_16 [ V_18 ++ ] = isprint ( V_22 ) ? V_22 : 'X' ;
}
return V_18 ;
}
void F_16 ( void )
{
int V_18 , V_19 ;
T_2 V_23 ;
for ( V_18 = 0 ; V_18 < 256 ; V_18 ++ ) {
V_23 = V_18 << 24 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
if ( V_23 & 0x80000000 )
V_23 = ( V_23 << 1 ) ^ V_24 ;
else
V_23 = ( V_23 << 1 ) ;
}
V_25 [ V_18 ] = V_23 ;
}
}
T_2 F_17 ( T_3 * V_26 , T_4 V_17 , T_2 V_27 )
{
int V_18 ;
T_2 V_23 ;
V_23 = V_27 ;
while ( V_17 -- ) {
V_18 = ( ( V_23 >> 24 ) ^ * V_26 ++ ) & 0xFF ;
V_23 = ( V_23 << 8 ) ^ V_25 [ V_18 ] ;
}
return V_23 ;
}
void * F_18 ( struct V_1 * V_2 , T_4 V_28 ,
T_5 * V_29 )
{
if ( F_19 ( V_28 ) > V_30 )
return NULL ;
return F_20 ( & V_2 -> V_5 -> V_31 , V_28 , V_29 ,
V_32 ) ;
}
void F_21 ( struct V_1 * V_2 , T_4 V_28 ,
void * V_33 , T_5 V_29 )
{
if ( V_33 == NULL )
return;
F_22 ( & V_2 -> V_5 -> V_31 , V_28 , V_33 , V_29 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_5 * V_34 ,
int V_35 )
{
int V_18 ;
struct V_5 * V_5 = V_2 -> V_5 ;
for ( V_18 = 0 ; ( V_18 < V_35 ) && ( V_34 [ V_18 ] != 0x0 ) ; V_18 ++ ) {
F_24 ( V_5 , V_34 [ V_18 ] ,
V_36 , V_37 ) ;
V_34 [ V_18 ] = 0x0 ;
}
}
static int F_25 ( struct V_1 * V_2 ,
struct V_38 * * V_39 , int V_35 ,
T_5 * V_34 )
{
int V_18 ;
struct V_5 * V_5 = V_2 -> V_5 ;
for ( V_18 = 0 ; V_18 < V_35 ; V_18 ++ ) {
T_5 V_40 ;
V_34 [ V_18 ] = 0x0 ;
V_40 = F_26 ( V_5 , V_39 [ V_18 ] ,
0 ,
V_36 ,
V_37 ) ;
if ( F_27 ( V_5 , V_40 ) ) {
F_28 ( & V_5 -> V_31 ,
L_1 ,
V_41 , ( long long ) V_40 ) ;
goto V_42;
}
V_34 [ V_18 ] = V_40 ;
}
return 0 ;
V_42:
F_23 ( V_2 , V_34 , V_35 ) ;
return - V_8 ;
}
static int F_29 ( int V_35 )
{
int V_17 , V_43 = V_35 / 7 ;
V_17 = sizeof( struct V_44 ) * ( V_35 + V_43 + 1 ) ;
return F_30 ( V_17 , V_36 ) ;
}
int F_31 ( struct V_1 * V_2 , struct V_45 * V_46 ,
void T_6 * V_47 , T_4 V_48 )
{
int V_49 ;
struct V_5 * V_5 = V_2 -> V_5 ;
V_46 -> V_50 = F_32 ( ( unsigned long ) V_47 ) ;
V_46 -> V_51 = F_33 ( T_4 , V_36 - V_46 -> V_50 , V_48 ) ;
V_46 -> V_52 = F_34 ( V_46 -> V_50 + V_48 , V_36 ) ;
V_46 -> V_53 = ( V_48 - V_46 -> V_51 ) % V_36 ;
F_35 ( & V_5 -> V_31 , L_2 ,
V_41 , V_47 , V_48 , V_46 -> V_52 ,
V_46 -> V_50 , V_46 -> V_51 , V_46 -> V_53 ) ;
V_46 -> V_47 = V_47 ;
V_46 -> V_48 = V_48 ;
V_46 -> V_54 = F_29 ( V_46 -> V_52 ) ;
if ( F_19 ( V_46 -> V_54 ) > V_30 ) {
F_28 ( & V_5 -> V_31 ,
L_3 , V_41 ) ;
return - V_55 ;
}
V_46 -> V_46 = F_18 ( V_2 , V_46 -> V_54 ,
& V_46 -> V_56 ) ;
if ( V_46 -> V_46 == NULL ) {
F_28 ( & V_5 -> V_31 ,
L_4 , V_41 ) ;
return - V_55 ;
}
if ( ( V_46 -> V_51 != 0 ) && ( V_46 -> V_51 != V_36 ) ) {
V_46 -> V_57 = F_18 ( V_2 , V_36 ,
& V_46 -> V_58 ) ;
if ( V_46 -> V_57 == NULL )
goto V_59;
if ( F_36 ( V_46 -> V_57 + V_46 -> V_50 ,
V_47 , V_46 -> V_51 ) ) {
V_49 = - V_60 ;
goto V_59;
}
}
if ( V_46 -> V_53 != 0 ) {
V_46 -> V_61 = F_18 ( V_2 , V_36 ,
& V_46 -> V_62 ) ;
if ( V_46 -> V_61 == NULL )
goto V_63;
if ( F_36 ( V_46 -> V_61 , V_47 + V_48 -
V_46 -> V_53 , V_46 -> V_53 ) ) {
V_49 = - V_60 ;
goto V_64;
}
}
return 0 ;
V_64:
F_21 ( V_2 , V_36 , V_46 -> V_61 ,
V_46 -> V_62 ) ;
V_46 -> V_61 = NULL ;
V_46 -> V_62 = 0 ;
V_63:
F_21 ( V_2 , V_36 , V_46 -> V_57 ,
V_46 -> V_58 ) ;
V_46 -> V_57 = NULL ;
V_46 -> V_58 = 0 ;
V_59:
F_21 ( V_2 , V_46 -> V_54 , V_46 -> V_46 ,
V_46 -> V_56 ) ;
V_46 -> V_46 = NULL ;
V_46 -> V_56 = 0 ;
V_46 -> V_54 = 0 ;
return - V_55 ;
}
int F_37 ( struct V_1 * V_2 , struct V_45 * V_46 ,
T_5 * V_34 )
{
int V_18 = 0 , V_19 = 0 , V_65 ;
unsigned long V_66 , V_67 ;
T_5 V_68 = 0 ;
struct V_44 * V_69 , * V_70 = NULL ;
T_4 V_28 = V_46 -> V_48 ;
V_66 = 128 ;
V_67 = V_46 -> V_50 ;
V_69 = & V_46 -> V_46 [ 0 ] ;
V_65 = 0 ;
while ( V_65 < V_46 -> V_52 ) {
T_5 V_40 ;
unsigned int V_71 ;
V_19 = 0 ;
V_69 [ V_19 ] . V_72 = F_4 ( V_46 -> V_56 + V_66 ) ;
V_69 [ V_19 ] . V_17 = F_10 ( 128 ) ;
V_69 [ V_19 ] . V_73 = F_10 ( V_74 ) ;
V_19 ++ ;
while ( V_19 < 8 ) {
V_71 = F_15 ( V_28 , V_36 - V_67 ) ;
if ( ( V_65 == 0 ) && ( V_46 -> V_57 != NULL ) ) {
V_40 = V_46 -> V_58 + V_67 ;
} else if ( ( V_65 == V_46 -> V_52 - 1 ) &&
( V_46 -> V_61 != NULL ) ) {
V_40 = V_46 -> V_62 ;
} else {
V_40 = V_34 [ V_65 ] + V_67 ;
}
V_28 -= V_71 ;
V_67 = 0 ;
if ( V_68 == V_40 ) {
T_2 V_75 = F_12 ( V_70 -> V_17 ) ;
V_70 -> V_17 = F_10 ( V_75 +
V_71 ) ;
V_65 ++ ;
if ( V_65 == V_46 -> V_52 )
goto V_76;
V_68 = V_40 + V_71 ;
continue;
}
V_69 [ V_19 ] . V_72 = F_4 ( V_40 ) ;
V_69 [ V_19 ] . V_17 = F_10 ( V_71 ) ;
V_69 [ V_19 ] . V_73 = F_10 ( V_77 ) ;
V_68 = V_40 + V_71 ;
V_70 = & V_69 [ V_19 ] ;
V_19 ++ ;
V_65 ++ ;
if ( V_65 == V_46 -> V_52 )
goto V_76;
}
V_66 += 128 ;
V_69 += 8 ;
}
V_76:
if ( V_19 == 1 ) {
V_69 -= 8 ;
V_19 = 7 ;
}
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
V_69 [ V_18 ] = V_69 [ V_18 + 1 ] ;
V_69 [ V_18 ] . V_72 = F_4 ( 0 ) ;
V_69 [ V_18 ] . V_17 = F_10 ( 0 ) ;
V_69 [ V_18 ] . V_73 = F_10 ( V_78 ) ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
int V_49 = 0 ;
struct V_5 * V_5 = V_2 -> V_5 ;
if ( V_46 -> V_57 ) {
if ( F_39 ( V_46 -> V_47 , V_46 -> V_57 + V_46 -> V_50 ,
V_46 -> V_51 ) ) {
F_28 ( & V_5 -> V_31 , L_5 ,
V_41 ) ;
V_49 = - V_60 ;
}
F_21 ( V_2 , V_36 , V_46 -> V_57 ,
V_46 -> V_58 ) ;
V_46 -> V_57 = NULL ;
V_46 -> V_58 = 0 ;
}
if ( V_46 -> V_61 ) {
if ( F_39 ( V_46 -> V_47 + V_46 -> V_48 -
V_46 -> V_53 , V_46 -> V_61 ,
V_46 -> V_53 ) ) {
F_28 ( & V_5 -> V_31 , L_6 ,
V_41 ) ;
V_49 = - V_60 ;
}
F_21 ( V_2 , V_36 , V_46 -> V_61 ,
V_46 -> V_62 ) ;
V_46 -> V_61 = NULL ;
V_46 -> V_62 = 0 ;
}
F_21 ( V_2 , V_46 -> V_54 , V_46 -> V_46 ,
V_46 -> V_56 ) ;
V_46 -> V_46 = NULL ;
V_46 -> V_56 = 0x0 ;
V_46 -> V_54 = 0 ;
return V_49 ;
}
static int F_40 ( struct V_38 * * V_39 , unsigned int V_52 ,
int V_79 )
{
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_52 ; V_18 ++ ) {
if ( V_39 [ V_18 ] != NULL ) {
if ( V_79 )
F_41 ( V_39 [ V_18 ] ) ;
F_42 ( V_39 [ V_18 ] ) ;
}
}
return 0 ;
}
int F_43 ( struct V_1 * V_2 , struct V_80 * V_81 , void * V_82 ,
unsigned long V_28 , struct V_83 * V_84 )
{
int V_49 = - V_85 ;
unsigned long V_86 , V_87 ;
struct V_5 * V_5 = V_2 -> V_5 ;
if ( ( V_82 == NULL ) || ( V_28 == 0 ) ) {
V_81 -> V_28 = 0 ;
return - V_85 ;
}
V_81 -> V_88 = V_82 ;
V_81 -> V_28 = V_28 ;
V_86 = ( unsigned long ) V_82 ;
V_87 = F_32 ( V_86 ) ;
V_81 -> V_52 = F_34 ( V_87 + V_28 , V_36 ) ;
V_81 -> V_39 = F_44 ( V_81 -> V_52 ,
sizeof( struct V_38 * ) + sizeof( T_5 ) ,
V_32 ) ;
if ( ! V_81 -> V_39 ) {
F_28 ( & V_5 -> V_31 , L_7 ) ;
V_81 -> V_52 = 0 ;
V_81 -> V_88 = NULL ;
V_81 -> V_28 = 0 ;
return - V_55 ;
}
V_81 -> V_34 = ( T_5 * ) ( V_81 -> V_39 + V_81 -> V_52 ) ;
V_49 = F_45 ( V_86 & V_89 ,
V_81 -> V_52 ,
1 ,
V_81 -> V_39 ) ;
if ( V_49 < 0 )
goto V_90;
if ( V_49 < V_81 -> V_52 ) {
F_40 ( V_81 -> V_39 , V_49 , 0 ) ;
V_49 = - V_60 ;
goto V_90;
}
V_49 = F_25 ( V_2 , V_81 -> V_39 , V_81 -> V_52 , V_81 -> V_34 ) ;
if ( V_49 != 0 )
goto V_91;
return 0 ;
V_91:
F_40 ( V_81 -> V_39 , V_81 -> V_52 , 0 ) ;
V_90:
F_46 ( V_81 -> V_39 ) ;
V_81 -> V_39 = NULL ;
V_81 -> V_34 = NULL ;
V_81 -> V_52 = 0 ;
V_81 -> V_88 = NULL ;
V_81 -> V_28 = 0 ;
return V_49 ;
}
int F_47 ( struct V_1 * V_2 , struct V_80 * V_81 ,
struct V_83 * V_84 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
if ( ! F_48 ( V_81 ) ) {
F_28 ( & V_5 -> V_31 , L_8 ,
V_41 , V_81 ) ;
return - V_85 ;
}
if ( V_81 -> V_34 )
F_23 ( V_2 , V_81 -> V_34 , V_81 -> V_52 ) ;
if ( V_81 -> V_39 ) {
F_40 ( V_81 -> V_39 , V_81 -> V_52 , 1 ) ;
F_46 ( V_81 -> V_39 ) ;
V_81 -> V_39 = NULL ;
V_81 -> V_34 = NULL ;
V_81 -> V_52 = 0 ;
}
V_81 -> V_88 = NULL ;
V_81 -> V_28 = 0 ;
return 0 ;
}
T_3 F_49 ( struct V_1 * V_2 )
{
T_1 V_92 = V_2 -> V_93 ;
return ( T_3 ) ( ( V_92 & V_94 ) >> 20 ) ;
}
int F_50 ( struct V_1 * V_2 )
{
T_1 V_95 ;
struct V_5 * V_5 = V_2 -> V_5 ;
if ( ! F_51 ( V_2 ) )
return - V_96 ;
F_1 ( V_2 , V_97 , 0x1ull ) ;
F_52 ( 1000 ) ;
F_5 ( V_2 , V_98 ) ;
F_5 ( V_2 , V_99 ) ;
F_5 ( V_2 , V_100 ) ;
V_95 = F_5 ( V_2 , V_97 ) & 0x3cull ;
F_1 ( V_2 , V_97 , V_95 | 0x2ull ) ;
F_52 ( 50 ) ;
if ( F_53 ( V_2 ) ) {
F_54 ( & V_5 -> V_31 ,
L_9 , V_41 ) ;
F_1 ( V_2 , V_101 , 0x0aull ) ;
}
return 0 ;
}
int F_55 ( struct V_1 * V_2 )
{
T_1 V_102 ;
if ( ! F_51 ( V_2 ) )
return - V_96 ;
V_102 = F_5 ( V_2 , V_103 ) & 0x1 ;
V_2 -> V_104 = ( V_102 == 0 ) ? 0x8ull : 0xcull ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 , int V_105 )
{
int V_49 ;
V_49 = F_57 ( V_2 -> V_5 , 1 , V_105 , V_106 ) ;
if ( V_49 < 0 )
return V_49 ;
return 0 ;
}
void F_58 ( struct V_1 * V_2 )
{
F_59 ( V_2 -> V_5 ) ;
}
static int F_60 ( struct V_1 * V_2 , struct V_107 * V_108 ,
unsigned int * V_18 , unsigned int V_81 , T_2 V_109 , T_2 V_110 ,
T_1 V_4 )
{
if ( F_61 ( * V_18 >= V_81 ) )
return - V_60 ;
V_108 [ * V_18 ] . V_109 = V_109 ;
V_108 [ * V_18 ] . V_110 = V_110 ;
V_108 [ * V_18 ] . V_4 = V_4 ;
++ * V_18 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_107 * V_108 ,
unsigned int * V_18 , unsigned int V_81 , T_2 V_109 , T_1 V_4 )
{
return F_60 ( V_2 , V_108 , V_18 , V_81 , V_109 , 0 , V_4 ) ;
}
int F_63 ( struct V_1 * V_2 , struct V_107 * V_111 ,
unsigned int V_112 , int V_113 )
{
unsigned int V_18 , V_19 , V_110 = 0 ;
T_2 V_114 , V_115 , V_116 , V_117 ;
T_1 V_118 , V_119 , V_120 , V_121 , V_122 , V_123 , V_124 ;
V_118 = F_5 ( V_2 , V_12 ) ;
F_62 ( V_2 , V_111 , & V_110 , V_112 , V_12 , V_118 ) ;
V_119 = F_5 ( V_2 , V_125 ) ;
F_62 ( V_2 , V_111 , & V_110 , V_112 , V_125 , V_119 ) ;
V_120 = F_5 ( V_2 , V_126 ) ;
F_62 ( V_2 , V_111 , & V_110 , V_112 , V_126 , V_120 ) ;
for ( V_18 = 0 ; V_18 < V_127 ; V_18 ++ ) {
V_114 = ( V_18 << 24 ) | 0x008 ;
V_121 = F_5 ( V_2 , V_114 ) ;
F_62 ( V_2 , V_111 , & V_110 , V_112 , V_114 , V_121 ) ;
V_115 = ( V_18 << 24 ) | 0x018 ;
V_122 = F_5 ( V_2 , V_115 ) ;
F_62 ( V_2 , V_111 , & V_110 , V_112 , V_115 , V_122 ) ;
for ( V_19 = 0 ; V_19 < 64 ; V_19 ++ ) {
if ( ! V_113 && ( ! ( V_121 & ( 1ull << V_19 ) ) ) )
continue;
V_116 = ( V_18 << 24 ) | ( 0x100 + 8 * V_19 ) ;
V_123 = F_5 ( V_2 , V_116 ) ;
F_62 ( V_2 , V_111 , & V_110 , V_112 , V_116 , V_123 ) ;
V_117 = ( V_18 << 24 ) | ( 0x300 + 8 * V_19 ) ;
V_124 = F_5 ( V_2 , V_117 ) ;
F_62 ( V_2 , V_111 , & V_110 , V_112 , V_117 , V_124 ) ;
}
}
for ( V_18 = V_110 ; V_18 < V_112 ; V_18 ++ ) {
V_111 [ V_18 ] . V_109 = 0xffffffff ;
V_111 [ V_18 ] . V_4 = 0xffffffffffffffffull ;
}
return V_110 ;
}
int F_64 ( struct V_1 * V_2 , int V_128 )
{
int V_129 = 0 , V_130 , V_131 , V_132 , V_133 ;
T_2 V_134 , V_135 , V_136 , V_137 ;
T_1 V_138 , V_4 , V_109 ;
V_134 = F_65 ( V_128 ) | V_139 ;
V_138 = F_5 ( V_2 , V_134 ) ;
if ( ( V_138 != 0x0 ) && ( V_138 != - 1ull ) ) {
V_135 = F_65 ( V_128 ) | V_138 ;
while ( 1 ) {
V_4 = F_5 ( V_2 , V_135 ) ;
if ( ( V_4 == 0x0 ) || ( V_4 == - 1ull ) )
break;
V_136 = ( V_4 & 0x0000007fff000000ull ) >> 24 ;
V_137 = ( V_4 & 0x0000008000000000ull ) >> 36 ;
if ( V_137 ) {
V_129 += V_136 ;
} else {
V_129 += V_136 >> 3 ;
}
V_135 += 8 ;
}
}
for ( V_130 = 0 ; V_130 < 8 ; V_130 ++ ) {
V_109 = F_65 ( V_128 ) | F_66 ( V_130 ) ;
V_4 = F_5 ( V_2 , V_109 ) ;
if ( ( V_4 == 0x0ull ) || ( V_4 == - 1ull ) )
continue;
V_131 = ( V_4 >> 24 ) & 0xff ;
V_132 = ( V_4 >> 16 ) & 0xff ;
V_133 = V_4 & 0xffff ;
V_129 += V_131 + ( V_132 * V_133 ) ;
}
return V_129 ;
}
int F_67 ( struct V_1 * V_2 , int V_128 ,
struct V_107 * V_111 , unsigned int V_112 )
{
int V_18 , V_131 , V_132 , V_140 , V_133 , V_141 , V_130 ;
unsigned int V_110 = 0 ;
T_2 V_134 , V_135 , V_142 , V_136 , V_137 ;
T_1 V_138 , V_143 , V_4 , V_109 ;
V_134 = F_65 ( V_128 ) | V_139 ;
V_138 = F_5 ( V_2 , V_134 ) ;
if ( ( V_138 != 0x0 ) && ( V_138 != 0xffffffffffffffffull ) ) {
V_135 = F_65 ( V_128 ) | V_138 ;
while ( 1 ) {
V_143 = F_5 ( V_2 , V_135 ) ;
if ( ( V_143 == 0x0 ) || ( V_143 == 0xffffffffffffffffull ) )
break;
V_142 = ( V_143 & 0x0000000000ffffffull ) ;
V_136 = ( V_143 & 0x0000007fff000000ull ) >> 24 ;
V_137 = ( V_143 & 0x0000008000000000ull ) >> 36 ;
V_142 |= F_65 ( V_128 ) ;
if ( V_137 ) {
for ( V_18 = 0 ; V_18 < ( int ) V_136 ; V_18 ++ ) {
V_4 = F_5 ( V_2 , V_142 ) ;
F_60 ( V_2 , V_111 , & V_110 , V_112 ,
V_142 , V_18 , V_4 ) ;
}
} else {
V_136 >>= 3 ;
for ( V_18 = 0 ; V_18 < ( int ) V_136 ; V_18 ++ , V_142 += 8 ) {
V_4 = F_5 ( V_2 , V_142 ) ;
F_60 ( V_2 , V_111 , & V_110 , V_112 ,
V_142 , 0 , V_4 ) ;
}
}
V_135 += 8 ;
}
}
for ( V_130 = 0 ; V_130 < 8 ; V_130 ++ ) {
V_109 = F_65 ( V_128 ) | F_66 ( V_130 ) ;
V_4 = F_5 ( V_2 , V_109 ) ;
if ( ( V_4 == 0x0ull ) || ( V_4 == - 1ull ) )
continue;
V_131 = ( V_4 >> 24 ) & 0xff ;
V_132 = ( V_4 >> 16 ) & 0xff ;
V_133 = V_4 & 0xffff ;
for ( V_140 = 0 ; V_140 <= V_132 ; V_140 ++ ) {
T_2 V_144 =
F_68 ( V_130 , V_140 ) ;
V_109 = ( F_65 ( V_128 ) |
V_145 ) ;
F_1 ( V_2 , V_109 , V_144 ) ;
for ( V_141 = 0 ;
V_141 < ( V_140 ? V_133 : V_131 ) ;
V_141 ++ ) {
V_109 = ( F_65 ( V_128 ) |
V_146 ) ;
V_4 = F_5 ( V_2 , V_109 ) ;
F_60 ( V_2 , V_111 , & V_110 , V_112 , V_109 ,
( V_144 << 16 ) | V_141 , V_4 ) ;
}
}
}
return 0 ;
}
int F_69 ( struct V_1 * V_2 , T_2 V_147 , T_1 V_4 , int V_148 )
{
F_1 ( V_2 , V_149 , V_148 & 0xf ) ;
F_1 ( V_2 , V_147 , V_4 ) ;
return 0 ;
}
T_1 F_70 ( struct V_1 * V_2 , T_2 V_147 , int V_148 )
{
F_1 ( V_2 , V_149 , V_148 & 0xf ) ;
return F_5 ( V_2 , V_147 ) ;
}
int F_71 ( struct V_1 * V_2 )
{
T_7 V_150 ;
static const int V_151 [] = { 250 , 200 , 166 , 175 } ;
V_150 = ( T_7 ) ( ( V_2 -> V_93 >> 28 ) & 0x0full ) ;
if ( V_150 >= F_72 ( V_151 ) )
return 0 ;
return V_151 [ V_150 ] ;
}
void F_73 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_152 , 0xcull ) ;
}
void F_74 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_153 , 0xcull ) ;
if ( F_53 ( V_2 ) )
F_1 ( V_2 , V_101 , 0x0aull ) ;
}
