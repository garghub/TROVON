int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_2 -> V_5 & V_6 )
return - V_7 ;
if ( V_2 -> V_8 == NULL )
return - V_7 ;
F_2 ( ( V_9 T_1 ) F_3 ( V_4 ) , V_2 -> V_8 + V_3 ) ;
return 0 ;
}
T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_5 & V_6 )
return 0xffffffffffffffffull ;
if ( ( V_2 -> V_5 & V_10 ) &&
( V_3 == V_11 ) )
return 0x000000000000ffffull ;
if ( ( V_2 -> V_5 & V_12 ) &&
( V_3 == V_11 ) )
return 0x00000000ffff0000ull ;
if ( V_2 -> V_8 == NULL )
return 0xffffffffffffffffull ;
return F_5 ( ( V_9 V_13 ) F_6 ( V_2 -> V_8 + V_3 ) ) ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
if ( V_2 -> V_5 & V_6 )
return - V_7 ;
if ( V_2 -> V_8 == NULL )
return - V_7 ;
F_8 ( ( V_9 T_2 ) F_9 ( V_4 ) , V_2 -> V_8 + V_3 ) ;
return 0 ;
}
T_2 F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_5 & V_6 )
return 0xffffffff ;
if ( V_2 -> V_8 == NULL )
return 0xffffffff ;
return F_11 ( ( V_9 V_14 ) F_12 ( V_2 -> V_8 + V_3 ) ) ;
}
int F_13 ( struct V_1 * V_2 , char * V_15 , int V_16 )
{
int V_17 , V_18 ;
T_2 V_19 = ( T_2 ) V_2 -> V_20 ;
memset ( V_15 , 0 , V_16 ) ;
for ( V_17 = 0 , V_18 = 0 ; V_18 < F_14 ( V_16 , 4 ) ; V_18 ++ ) {
char V_21 = ( char ) ( ( V_19 >> ( 24 - V_18 * 8 ) ) & 0xff ) ;
if ( V_21 == ' ' )
continue;
V_15 [ V_17 ++ ] = isprint ( V_21 ) ? V_21 : 'X' ;
}
return V_17 ;
}
void F_15 ( void )
{
int V_17 , V_18 ;
T_2 V_22 ;
for ( V_17 = 0 ; V_17 < 256 ; V_17 ++ ) {
V_22 = V_17 << 24 ;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ ) {
if ( V_22 & 0x80000000 )
V_22 = ( V_22 << 1 ) ^ V_23 ;
else
V_22 = ( V_22 << 1 ) ;
}
V_24 [ V_17 ] = V_22 ;
}
}
T_2 F_16 ( T_3 * V_25 , T_4 V_16 , T_2 V_26 )
{
int V_17 ;
T_2 V_22 ;
V_22 = V_26 ;
while ( V_16 -- ) {
V_17 = ( ( V_22 >> 24 ) ^ * V_25 ++ ) & 0xFF ;
V_22 = ( V_22 << 8 ) ^ V_24 [ V_17 ] ;
}
return V_22 ;
}
void * F_17 ( struct V_1 * V_2 , T_4 V_27 ,
T_5 * V_28 )
{
if ( F_18 ( V_27 ) > V_29 )
return NULL ;
return F_19 ( V_2 -> V_30 , V_27 , V_28 ) ;
}
void F_20 ( struct V_1 * V_2 , T_4 V_27 ,
void * V_31 , T_5 V_28 )
{
if ( V_31 == NULL )
return;
F_21 ( V_2 -> V_30 , V_27 , V_31 , V_28 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_5 * V_32 ,
int V_33 )
{
int V_17 ;
struct V_30 * V_30 = V_2 -> V_30 ;
for ( V_17 = 0 ; ( V_17 < V_33 ) && ( V_32 [ V_17 ] != 0x0 ) ; V_17 ++ ) {
F_23 ( V_30 , V_32 [ V_17 ] ,
V_34 , V_35 ) ;
V_32 [ V_17 ] = 0x0 ;
}
}
static int F_24 ( struct V_1 * V_2 ,
struct V_36 * * V_37 , int V_33 ,
T_5 * V_32 )
{
int V_17 ;
struct V_30 * V_30 = V_2 -> V_30 ;
for ( V_17 = 0 ; V_17 < V_33 ; V_17 ++ ) {
T_5 V_38 ;
V_32 [ V_17 ] = 0x0 ;
V_38 = F_25 ( V_30 , V_37 [ V_17 ] ,
0 ,
V_34 ,
V_35 ) ;
if ( F_26 ( V_30 , V_38 ) ) {
F_27 ( & V_30 -> V_39 ,
L_1 ,
V_40 , ( long long ) V_38 ) ;
goto V_41;
}
V_32 [ V_17 ] = V_38 ;
}
return 0 ;
V_41:
F_22 ( V_2 , V_32 , V_33 ) ;
return - V_7 ;
}
static int F_28 ( int V_33 )
{
int V_16 , V_42 = V_33 / 7 ;
V_16 = sizeof( struct V_43 ) * ( V_33 + V_42 + 1 ) ;
return F_29 ( V_16 , V_34 ) ;
}
int F_30 ( struct V_1 * V_2 , struct V_44 * V_45 ,
void T_6 * V_46 , T_4 V_47 )
{
int V_48 ;
struct V_30 * V_30 = V_2 -> V_30 ;
V_45 -> V_49 = F_31 ( ( unsigned long ) V_46 ) ;
V_45 -> V_50 = F_32 ( T_4 , V_34 - V_45 -> V_49 , V_47 ) ;
V_45 -> V_51 = F_33 ( V_45 -> V_49 + V_47 , V_34 ) ;
V_45 -> V_52 = ( V_47 - V_45 -> V_50 ) % V_34 ;
F_34 ( & V_30 -> V_39 , L_2
L_3 ,
V_40 , V_46 , V_47 , V_45 -> V_51 ,
V_45 -> V_49 , V_45 -> V_50 , V_45 -> V_52 ) ;
V_45 -> V_46 = V_46 ;
V_45 -> V_47 = V_47 ;
V_45 -> V_53 = F_28 ( V_45 -> V_51 ) ;
if ( F_18 ( V_45 -> V_53 ) > V_29 ) {
F_27 ( & V_30 -> V_39 ,
L_4 , V_40 ) ;
return - V_54 ;
}
V_45 -> V_45 = F_17 ( V_2 , V_45 -> V_53 ,
& V_45 -> V_55 ) ;
if ( V_45 -> V_45 == NULL ) {
F_27 ( & V_30 -> V_39 ,
L_5 , V_40 ) ;
return - V_54 ;
}
if ( ( V_45 -> V_50 != 0 ) && ( V_45 -> V_50 != V_34 ) ) {
V_45 -> V_56 = F_17 ( V_2 , V_34 ,
& V_45 -> V_57 ) ;
if ( V_45 -> V_56 == NULL )
goto V_58;
if ( F_35 ( V_45 -> V_56 + V_45 -> V_49 ,
V_46 , V_45 -> V_50 ) ) {
V_48 = - V_59 ;
goto V_58;
}
}
if ( V_45 -> V_52 != 0 ) {
V_45 -> V_60 = F_17 ( V_2 , V_34 ,
& V_45 -> V_61 ) ;
if ( V_45 -> V_60 == NULL )
goto V_62;
if ( F_35 ( V_45 -> V_60 , V_46 + V_47 -
V_45 -> V_52 , V_45 -> V_52 ) ) {
V_48 = - V_59 ;
goto V_62;
}
}
return 0 ;
V_62:
F_20 ( V_2 , V_34 , V_45 -> V_56 ,
V_45 -> V_57 ) ;
V_58:
F_20 ( V_2 , V_45 -> V_53 , V_45 -> V_45 ,
V_45 -> V_55 ) ;
return - V_54 ;
}
int F_36 ( struct V_1 * V_2 , struct V_44 * V_45 ,
T_5 * V_32 )
{
int V_17 = 0 , V_18 = 0 , V_63 ;
unsigned long V_64 , V_65 ;
T_5 V_66 = 0 ;
struct V_43 * V_67 , * V_68 = NULL ;
T_4 V_27 = V_45 -> V_47 ;
V_64 = 128 ;
V_65 = V_45 -> V_49 ;
V_67 = & V_45 -> V_45 [ 0 ] ;
V_63 = 0 ;
while ( V_63 < V_45 -> V_51 ) {
T_5 V_38 ;
unsigned int V_69 ;
V_18 = 0 ;
V_67 [ V_18 ] . V_70 = F_3 ( V_45 -> V_55 + V_64 ) ;
V_67 [ V_18 ] . V_16 = F_9 ( 128 ) ;
V_67 [ V_18 ] . V_71 = F_9 ( V_72 ) ;
V_18 ++ ;
while ( V_18 < 8 ) {
V_69 = F_14 ( V_27 , V_34 - V_65 ) ;
if ( ( V_63 == 0 ) && ( V_45 -> V_56 != NULL ) ) {
V_38 = V_45 -> V_57 + V_65 ;
} else if ( ( V_63 == V_45 -> V_51 - 1 ) &&
( V_45 -> V_60 != NULL ) ) {
V_38 = V_45 -> V_61 ;
} else {
V_38 = V_32 [ V_63 ] + V_65 ;
}
V_27 -= V_69 ;
V_65 = 0 ;
if ( V_66 == V_38 ) {
T_2 V_73 = F_11 ( V_68 -> V_16 ) ;
V_68 -> V_16 = F_9 ( V_73 +
V_69 ) ;
V_63 ++ ;
if ( V_63 == V_45 -> V_51 )
goto V_74;
V_66 = V_38 + V_69 ;
continue;
}
V_67 [ V_18 ] . V_70 = F_3 ( V_38 ) ;
V_67 [ V_18 ] . V_16 = F_9 ( V_69 ) ;
V_67 [ V_18 ] . V_71 = F_9 ( V_75 ) ;
V_66 = V_38 + V_69 ;
V_68 = & V_67 [ V_18 ] ;
V_18 ++ ;
V_63 ++ ;
if ( V_63 == V_45 -> V_51 )
goto V_74;
}
V_64 += 128 ;
V_67 += 8 ;
}
V_74:
if ( V_18 == 1 ) {
V_67 -= 8 ;
V_18 = 7 ;
}
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
V_67 [ V_17 ] = V_67 [ V_17 + 1 ] ;
V_67 [ V_17 ] . V_70 = F_3 ( 0 ) ;
V_67 [ V_17 ] . V_16 = F_9 ( 0 ) ;
V_67 [ V_17 ] . V_71 = F_9 ( V_76 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
int V_48 = 0 ;
struct V_30 * V_30 = V_2 -> V_30 ;
if ( V_45 -> V_56 ) {
if ( F_38 ( V_45 -> V_46 , V_45 -> V_56 + V_45 -> V_49 ,
V_45 -> V_50 ) ) {
F_27 ( & V_30 -> V_39 , L_6 ,
V_40 ) ;
V_48 = - V_59 ;
}
F_20 ( V_2 , V_34 , V_45 -> V_56 ,
V_45 -> V_57 ) ;
V_45 -> V_56 = NULL ;
V_45 -> V_57 = 0 ;
}
if ( V_45 -> V_60 ) {
if ( F_38 ( V_45 -> V_46 + V_45 -> V_47 -
V_45 -> V_52 , V_45 -> V_60 ,
V_45 -> V_52 ) ) {
F_27 ( & V_30 -> V_39 , L_7 ,
V_40 ) ;
V_48 = - V_59 ;
}
F_20 ( V_2 , V_34 , V_45 -> V_60 ,
V_45 -> V_61 ) ;
V_45 -> V_60 = NULL ;
V_45 -> V_61 = 0 ;
}
F_20 ( V_2 , V_45 -> V_53 , V_45 -> V_45 ,
V_45 -> V_55 ) ;
V_45 -> V_45 = NULL ;
V_45 -> V_55 = 0x0 ;
V_45 -> V_53 = 0 ;
return V_48 ;
}
static int F_39 ( struct V_36 * * V_37 , unsigned int V_51 ,
int V_77 )
{
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_51 ; V_17 ++ ) {
if ( V_37 [ V_17 ] != NULL ) {
if ( V_77 )
F_40 ( V_37 [ V_17 ] ) ;
F_41 ( V_37 [ V_17 ] ) ;
}
}
return 0 ;
}
int F_42 ( struct V_1 * V_2 , struct V_78 * V_79 , void * V_80 ,
unsigned long V_27 , struct V_81 * V_82 )
{
int V_48 = - V_83 ;
unsigned long V_84 , V_85 ;
struct V_30 * V_30 = V_2 -> V_30 ;
if ( ( V_80 == NULL ) || ( V_27 == 0 ) ) {
V_79 -> V_27 = 0 ;
return - V_83 ;
}
V_79 -> V_86 = V_80 ;
V_79 -> V_27 = V_27 ;
V_84 = ( unsigned long ) V_80 ;
V_85 = F_31 ( V_84 ) ;
V_79 -> V_51 = F_33 ( V_85 + V_27 , V_34 ) ;
V_79 -> V_37 = F_43 ( V_79 -> V_51 ,
sizeof( struct V_36 * ) + sizeof( T_5 ) ,
V_87 ) ;
if ( ! V_79 -> V_37 ) {
F_27 ( & V_30 -> V_39 , L_8 ) ;
V_79 -> V_51 = 0 ;
V_79 -> V_86 = NULL ;
V_79 -> V_27 = 0 ;
return - V_54 ;
}
V_79 -> V_32 = ( T_5 * ) ( V_79 -> V_37 + V_79 -> V_51 ) ;
V_48 = F_44 ( V_84 & V_88 ,
V_79 -> V_51 ,
1 ,
V_79 -> V_37 ) ;
if ( V_48 < V_79 -> V_51 ) {
F_39 ( V_79 -> V_37 , V_48 , 0 ) ;
V_48 = - V_59 ;
goto V_89;
}
V_48 = F_24 ( V_2 , V_79 -> V_37 , V_79 -> V_51 , V_79 -> V_32 ) ;
if ( V_48 != 0 )
goto V_90;
return 0 ;
V_90:
F_39 ( V_79 -> V_37 , V_79 -> V_51 , 0 ) ;
V_89:
F_45 ( V_79 -> V_37 ) ;
V_79 -> V_37 = NULL ;
V_79 -> V_32 = NULL ;
V_79 -> V_51 = 0 ;
V_79 -> V_86 = NULL ;
V_79 -> V_27 = 0 ;
return V_48 ;
}
int F_46 ( struct V_1 * V_2 , struct V_78 * V_79 ,
struct V_81 * V_82 )
{
struct V_30 * V_30 = V_2 -> V_30 ;
if ( ! F_47 ( V_79 ) ) {
F_27 ( & V_30 -> V_39 , L_9 ,
V_40 , V_79 ) ;
return - V_83 ;
}
if ( V_79 -> V_32 )
F_22 ( V_2 , V_79 -> V_32 , V_79 -> V_51 ) ;
if ( V_79 -> V_37 ) {
F_39 ( V_79 -> V_37 , V_79 -> V_51 , 1 ) ;
F_45 ( V_79 -> V_37 ) ;
V_79 -> V_37 = NULL ;
V_79 -> V_32 = NULL ;
V_79 -> V_51 = 0 ;
}
V_79 -> V_86 = NULL ;
V_79 -> V_27 = 0 ;
return 0 ;
}
T_3 F_48 ( struct V_1 * V_2 )
{
T_1 V_91 = V_2 -> V_92 ;
return ( T_3 ) ( ( V_91 & V_93 ) >> 20 ) ;
}
int F_49 ( struct V_1 * V_2 )
{
T_1 V_94 ;
struct V_30 * V_30 = V_2 -> V_30 ;
if ( ! F_50 ( V_2 ) )
return - V_95 ;
F_1 ( V_2 , V_96 , 0x1ull ) ;
F_51 ( 1000 ) ;
F_4 ( V_2 , V_97 ) ;
F_4 ( V_2 , V_98 ) ;
F_4 ( V_2 , V_99 ) ;
V_94 = F_4 ( V_2 , V_96 ) & 0x3cull ;
F_1 ( V_2 , V_96 , V_94 | 0x2ull ) ;
F_51 ( 50 ) ;
if ( F_52 ( V_2 ) ) {
F_53 ( & V_30 -> V_39 ,
L_10 , V_40 ) ;
F_1 ( V_2 , V_100 , 0x0aull ) ;
}
return 0 ;
}
int F_54 ( struct V_1 * V_2 )
{
T_1 V_101 ;
if ( ! F_50 ( V_2 ) )
return - V_95 ;
V_101 = F_4 ( V_2 , V_102 ) & 0x1 ;
V_2 -> V_103 = ( V_101 == 0 ) ? 0x8ull : 0xcull ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 , int V_104 )
{
int V_48 ;
struct V_30 * V_30 = V_2 -> V_30 ;
V_48 = F_56 ( V_30 , V_104 ) ;
if ( V_48 == 0 )
V_2 -> V_71 |= V_105 ;
return V_48 ;
}
void F_57 ( struct V_1 * V_2 )
{
struct V_30 * V_30 = V_2 -> V_30 ;
if ( V_2 -> V_71 & V_105 ) {
F_58 ( V_30 ) ;
V_2 -> V_71 &= ~ V_105 ;
}
}
static int F_59 ( struct V_1 * V_2 , struct V_106 * V_107 ,
unsigned int * V_17 , unsigned int V_79 , T_2 V_108 , T_2 V_109 ,
T_1 V_4 )
{
if ( F_60 ( * V_17 >= V_79 ) )
return - V_59 ;
V_107 [ * V_17 ] . V_108 = V_108 ;
V_107 [ * V_17 ] . V_109 = V_109 ;
V_107 [ * V_17 ] . V_4 = V_4 ;
++ * V_17 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_106 * V_107 ,
unsigned int * V_17 , unsigned int V_79 , T_2 V_108 , T_1 V_4 )
{
return F_59 ( V_2 , V_107 , V_17 , V_79 , V_108 , 0 , V_4 ) ;
}
int F_62 ( struct V_1 * V_2 , struct V_106 * V_110 ,
unsigned int V_111 , int V_112 )
{
unsigned int V_17 , V_18 , V_109 = 0 ;
T_2 V_113 , V_114 , V_115 , V_116 ;
T_1 V_117 , V_118 , V_119 , V_120 , V_121 , V_122 , V_123 ;
V_117 = F_4 ( V_2 , V_11 ) ;
F_61 ( V_2 , V_110 , & V_109 , V_111 , V_11 , V_117 ) ;
V_118 = F_4 ( V_2 , V_124 ) ;
F_61 ( V_2 , V_110 , & V_109 , V_111 , V_124 , V_118 ) ;
V_119 = F_4 ( V_2 , V_125 ) ;
F_61 ( V_2 , V_110 , & V_109 , V_111 , V_125 , V_119 ) ;
for ( V_17 = 0 ; V_17 < V_126 ; V_17 ++ ) {
V_113 = ( V_17 << 24 ) | 0x008 ;
V_120 = F_4 ( V_2 , V_113 ) ;
F_61 ( V_2 , V_110 , & V_109 , V_111 , V_113 , V_120 ) ;
V_114 = ( V_17 << 24 ) | 0x018 ;
V_121 = F_4 ( V_2 , V_114 ) ;
F_61 ( V_2 , V_110 , & V_109 , V_111 , V_114 , V_121 ) ;
for ( V_18 = 0 ; V_18 < 64 ; V_18 ++ ) {
if ( ! V_112 && ( ! ( V_120 & ( 1ull << V_18 ) ) ) )
continue;
V_115 = ( V_17 << 24 ) | ( 0x100 + 8 * V_18 ) ;
V_122 = F_4 ( V_2 , V_115 ) ;
F_61 ( V_2 , V_110 , & V_109 , V_111 , V_115 , V_122 ) ;
V_116 = ( V_17 << 24 ) | ( 0x300 + 8 * V_18 ) ;
V_123 = F_4 ( V_2 , V_116 ) ;
F_61 ( V_2 , V_110 , & V_109 , V_111 , V_116 , V_123 ) ;
}
}
for ( V_17 = V_109 ; V_17 < V_111 ; V_17 ++ ) {
V_110 [ V_17 ] . V_108 = 0xffffffff ;
V_110 [ V_17 ] . V_4 = 0xffffffffffffffffull ;
}
return V_109 ;
}
int F_63 ( struct V_1 * V_2 , int V_127 )
{
int V_128 = 0 , V_129 , V_130 , V_131 , V_132 ;
T_2 V_133 , V_134 , V_135 , V_136 ;
T_1 V_137 , V_4 , V_108 ;
V_133 = F_64 ( V_127 ) | V_138 ;
V_137 = F_4 ( V_2 , V_133 ) ;
if ( ( V_137 != 0x0 ) && ( V_137 != - 1ull ) ) {
V_134 = F_64 ( V_127 ) | V_137 ;
while ( 1 ) {
V_4 = F_4 ( V_2 , V_134 ) ;
if ( ( V_4 == 0x0 ) || ( V_4 == - 1ull ) )
break;
V_135 = ( V_4 & 0x0000007fff000000ull ) >> 24 ;
V_136 = ( V_4 & 0x0000008000000000ull ) >> 36 ;
if ( V_136 ) {
V_128 += V_135 ;
} else {
V_128 += V_135 >> 3 ;
}
V_134 += 8 ;
}
}
for ( V_129 = 0 ; V_129 < 8 ; V_129 ++ ) {
V_108 = F_64 ( V_127 ) | F_65 ( V_129 ) ;
V_4 = F_4 ( V_2 , V_108 ) ;
if ( ( V_4 == 0x0ull ) || ( V_4 == - 1ull ) )
continue;
V_130 = ( V_4 >> 24 ) & 0xff ;
V_131 = ( V_4 >> 16 ) & 0xff ;
V_132 = V_4 & 0xffff ;
V_128 += V_130 + ( V_131 * V_132 ) ;
}
return V_128 ;
}
int F_66 ( struct V_1 * V_2 , int V_127 ,
struct V_106 * V_110 , unsigned int V_111 )
{
int V_17 , V_130 , V_131 , V_139 , V_132 , V_140 , V_129 ;
unsigned int V_109 = 0 ;
T_2 V_133 , V_134 , V_141 , V_135 , V_136 ;
T_1 V_137 , V_142 , V_4 , V_108 ;
V_133 = F_64 ( V_127 ) | V_138 ;
V_137 = F_4 ( V_2 , V_133 ) ;
if ( ( V_137 != 0x0 ) && ( V_137 != 0xffffffffffffffffull ) ) {
V_134 = F_64 ( V_127 ) | V_137 ;
while ( 1 ) {
V_142 = F_4 ( V_2 , V_134 ) ;
if ( ( V_142 == 0x0 ) || ( V_142 == 0xffffffffffffffffull ) )
break;
V_141 = ( V_142 & 0x0000000000ffffffull ) ;
V_135 = ( V_142 & 0x0000007fff000000ull ) >> 24 ;
V_136 = ( V_142 & 0x0000008000000000ull ) >> 36 ;
V_141 |= F_64 ( V_127 ) ;
if ( V_136 ) {
for ( V_17 = 0 ; V_17 < ( int ) V_135 ; V_17 ++ ) {
V_4 = F_4 ( V_2 , V_141 ) ;
F_59 ( V_2 , V_110 , & V_109 , V_111 ,
V_141 , V_17 , V_4 ) ;
}
} else {
V_135 >>= 3 ;
for ( V_17 = 0 ; V_17 < ( int ) V_135 ; V_17 ++ , V_141 += 8 ) {
V_4 = F_4 ( V_2 , V_141 ) ;
F_59 ( V_2 , V_110 , & V_109 , V_111 ,
V_141 , 0 , V_4 ) ;
}
}
V_134 += 8 ;
}
}
for ( V_129 = 0 ; V_129 < 8 ; V_129 ++ ) {
V_108 = F_64 ( V_127 ) | F_65 ( V_129 ) ;
V_4 = F_4 ( V_2 , V_108 ) ;
if ( ( V_4 == 0x0ull ) || ( V_4 == - 1ull ) )
continue;
V_130 = ( V_4 >> 24 ) & 0xff ;
V_131 = ( V_4 >> 16 ) & 0xff ;
V_132 = V_4 & 0xffff ;
for ( V_139 = 0 ; V_139 <= V_131 ; V_139 ++ ) {
T_2 V_143 =
F_67 ( V_129 , V_139 ) ;
V_108 = ( F_64 ( V_127 ) |
V_144 ) ;
F_1 ( V_2 , V_108 , V_143 ) ;
for ( V_140 = 0 ;
V_140 < ( V_139 ? V_132 : V_130 ) ;
V_140 ++ ) {
V_108 = ( F_64 ( V_127 ) |
V_145 ) ;
V_4 = F_4 ( V_2 , V_108 ) ;
F_59 ( V_2 , V_110 , & V_109 , V_111 , V_108 ,
( V_143 << 16 ) | V_140 , V_4 ) ;
}
}
}
return 0 ;
}
int F_68 ( struct V_1 * V_2 , T_2 V_146 , T_1 V_4 , int V_147 )
{
F_1 ( V_2 , V_148 , V_147 & 0xf ) ;
F_1 ( V_2 , V_146 , V_4 ) ;
return 0 ;
}
T_1 F_69 ( struct V_1 * V_2 , T_2 V_146 , int V_147 )
{
F_1 ( V_2 , V_148 , V_147 & 0xf ) ;
return F_4 ( V_2 , V_146 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
T_7 V_149 ;
static const int V_150 [] = { 250 , 200 , 166 , 175 } ;
V_149 = ( T_7 ) ( ( V_2 -> V_92 >> 28 ) & 0x0full ) ;
if ( V_149 >= F_71 ( V_150 ) )
return 0 ;
return V_150 [ V_149 ] ;
}
void F_72 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_151 , 0xcull ) ;
}
void F_73 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_152 , 0xcull ) ;
if ( F_52 ( V_2 ) )
F_1 ( V_2 , V_100 , 0x0aull ) ;
}
