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
return F_20 ( V_2 -> V_5 , V_28 , V_29 ) ;
}
void F_21 ( struct V_1 * V_2 , T_4 V_28 ,
void * V_31 , T_5 V_29 )
{
if ( V_31 == NULL )
return;
F_22 ( V_2 -> V_5 , V_28 , V_31 , V_29 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_5 * V_32 ,
int V_33 )
{
int V_18 ;
struct V_5 * V_5 = V_2 -> V_5 ;
for ( V_18 = 0 ; ( V_18 < V_33 ) && ( V_32 [ V_18 ] != 0x0 ) ; V_18 ++ ) {
F_24 ( V_5 , V_32 [ V_18 ] ,
V_34 , V_35 ) ;
V_32 [ V_18 ] = 0x0 ;
}
}
static int F_25 ( struct V_1 * V_2 ,
struct V_36 * * V_37 , int V_33 ,
T_5 * V_32 )
{
int V_18 ;
struct V_5 * V_5 = V_2 -> V_5 ;
for ( V_18 = 0 ; V_18 < V_33 ; V_18 ++ ) {
T_5 V_38 ;
V_32 [ V_18 ] = 0x0 ;
V_38 = F_26 ( V_5 , V_37 [ V_18 ] ,
0 ,
V_34 ,
V_35 ) ;
if ( F_27 ( V_5 , V_38 ) ) {
F_28 ( & V_5 -> V_39 ,
L_1 ,
V_40 , ( long long ) V_38 ) ;
goto V_41;
}
V_32 [ V_18 ] = V_38 ;
}
return 0 ;
V_41:
F_23 ( V_2 , V_32 , V_33 ) ;
return - V_8 ;
}
static int F_29 ( int V_33 )
{
int V_17 , V_42 = V_33 / 7 ;
V_17 = sizeof( struct V_43 ) * ( V_33 + V_42 + 1 ) ;
return F_30 ( V_17 , V_34 ) ;
}
int F_31 ( struct V_1 * V_2 , struct V_44 * V_45 ,
void T_6 * V_46 , T_4 V_47 )
{
int V_48 ;
struct V_5 * V_5 = V_2 -> V_5 ;
V_45 -> V_49 = F_32 ( ( unsigned long ) V_46 ) ;
V_45 -> V_50 = F_33 ( T_4 , V_34 - V_45 -> V_49 , V_47 ) ;
V_45 -> V_51 = F_34 ( V_45 -> V_49 + V_47 , V_34 ) ;
V_45 -> V_52 = ( V_47 - V_45 -> V_50 ) % V_34 ;
F_35 ( & V_5 -> V_39 , L_2 ,
V_40 , V_46 , V_47 , V_45 -> V_51 ,
V_45 -> V_49 , V_45 -> V_50 , V_45 -> V_52 ) ;
V_45 -> V_46 = V_46 ;
V_45 -> V_47 = V_47 ;
V_45 -> V_53 = F_29 ( V_45 -> V_51 ) ;
if ( F_19 ( V_45 -> V_53 ) > V_30 ) {
F_28 ( & V_5 -> V_39 ,
L_3 , V_40 ) ;
return - V_54 ;
}
V_45 -> V_45 = F_18 ( V_2 , V_45 -> V_53 ,
& V_45 -> V_55 ) ;
if ( V_45 -> V_45 == NULL ) {
F_28 ( & V_5 -> V_39 ,
L_4 , V_40 ) ;
return - V_54 ;
}
if ( ( V_45 -> V_50 != 0 ) && ( V_45 -> V_50 != V_34 ) ) {
V_45 -> V_56 = F_18 ( V_2 , V_34 ,
& V_45 -> V_57 ) ;
if ( V_45 -> V_56 == NULL )
goto V_58;
if ( F_36 ( V_45 -> V_56 + V_45 -> V_49 ,
V_46 , V_45 -> V_50 ) ) {
V_48 = - V_59 ;
goto V_58;
}
}
if ( V_45 -> V_52 != 0 ) {
V_45 -> V_60 = F_18 ( V_2 , V_34 ,
& V_45 -> V_61 ) ;
if ( V_45 -> V_60 == NULL )
goto V_62;
if ( F_36 ( V_45 -> V_60 , V_46 + V_47 -
V_45 -> V_52 , V_45 -> V_52 ) ) {
V_48 = - V_59 ;
goto V_62;
}
}
return 0 ;
V_62:
F_21 ( V_2 , V_34 , V_45 -> V_56 ,
V_45 -> V_57 ) ;
V_58:
F_21 ( V_2 , V_45 -> V_53 , V_45 -> V_45 ,
V_45 -> V_55 ) ;
return - V_54 ;
}
int F_37 ( struct V_1 * V_2 , struct V_44 * V_45 ,
T_5 * V_32 )
{
int V_18 = 0 , V_19 = 0 , V_63 ;
unsigned long V_64 , V_65 ;
T_5 V_66 = 0 ;
struct V_43 * V_67 , * V_68 = NULL ;
T_4 V_28 = V_45 -> V_47 ;
V_64 = 128 ;
V_65 = V_45 -> V_49 ;
V_67 = & V_45 -> V_45 [ 0 ] ;
V_63 = 0 ;
while ( V_63 < V_45 -> V_51 ) {
T_5 V_38 ;
unsigned int V_69 ;
V_19 = 0 ;
V_67 [ V_19 ] . V_70 = F_4 ( V_45 -> V_55 + V_64 ) ;
V_67 [ V_19 ] . V_17 = F_10 ( 128 ) ;
V_67 [ V_19 ] . V_71 = F_10 ( V_72 ) ;
V_19 ++ ;
while ( V_19 < 8 ) {
V_69 = F_15 ( V_28 , V_34 - V_65 ) ;
if ( ( V_63 == 0 ) && ( V_45 -> V_56 != NULL ) ) {
V_38 = V_45 -> V_57 + V_65 ;
} else if ( ( V_63 == V_45 -> V_51 - 1 ) &&
( V_45 -> V_60 != NULL ) ) {
V_38 = V_45 -> V_61 ;
} else {
V_38 = V_32 [ V_63 ] + V_65 ;
}
V_28 -= V_69 ;
V_65 = 0 ;
if ( V_66 == V_38 ) {
T_2 V_73 = F_12 ( V_68 -> V_17 ) ;
V_68 -> V_17 = F_10 ( V_73 +
V_69 ) ;
V_63 ++ ;
if ( V_63 == V_45 -> V_51 )
goto V_74;
V_66 = V_38 + V_69 ;
continue;
}
V_67 [ V_19 ] . V_70 = F_4 ( V_38 ) ;
V_67 [ V_19 ] . V_17 = F_10 ( V_69 ) ;
V_67 [ V_19 ] . V_71 = F_10 ( V_75 ) ;
V_66 = V_38 + V_69 ;
V_68 = & V_67 [ V_19 ] ;
V_19 ++ ;
V_63 ++ ;
if ( V_63 == V_45 -> V_51 )
goto V_74;
}
V_64 += 128 ;
V_67 += 8 ;
}
V_74:
if ( V_19 == 1 ) {
V_67 -= 8 ;
V_19 = 7 ;
}
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
V_67 [ V_18 ] = V_67 [ V_18 + 1 ] ;
V_67 [ V_18 ] . V_70 = F_4 ( 0 ) ;
V_67 [ V_18 ] . V_17 = F_10 ( 0 ) ;
V_67 [ V_18 ] . V_71 = F_10 ( V_76 ) ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
int V_48 = 0 ;
struct V_5 * V_5 = V_2 -> V_5 ;
if ( V_45 -> V_56 ) {
if ( F_39 ( V_45 -> V_46 , V_45 -> V_56 + V_45 -> V_49 ,
V_45 -> V_50 ) ) {
F_28 ( & V_5 -> V_39 , L_5 ,
V_40 ) ;
V_48 = - V_59 ;
}
F_21 ( V_2 , V_34 , V_45 -> V_56 ,
V_45 -> V_57 ) ;
V_45 -> V_56 = NULL ;
V_45 -> V_57 = 0 ;
}
if ( V_45 -> V_60 ) {
if ( F_39 ( V_45 -> V_46 + V_45 -> V_47 -
V_45 -> V_52 , V_45 -> V_60 ,
V_45 -> V_52 ) ) {
F_28 ( & V_5 -> V_39 , L_6 ,
V_40 ) ;
V_48 = - V_59 ;
}
F_21 ( V_2 , V_34 , V_45 -> V_60 ,
V_45 -> V_61 ) ;
V_45 -> V_60 = NULL ;
V_45 -> V_61 = 0 ;
}
F_21 ( V_2 , V_45 -> V_53 , V_45 -> V_45 ,
V_45 -> V_55 ) ;
V_45 -> V_45 = NULL ;
V_45 -> V_55 = 0x0 ;
V_45 -> V_53 = 0 ;
return V_48 ;
}
static int F_40 ( struct V_36 * * V_37 , unsigned int V_51 ,
int V_77 )
{
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_51 ; V_18 ++ ) {
if ( V_37 [ V_18 ] != NULL ) {
if ( V_77 )
F_41 ( V_37 [ V_18 ] ) ;
F_42 ( V_37 [ V_18 ] ) ;
}
}
return 0 ;
}
int F_43 ( struct V_1 * V_2 , struct V_78 * V_79 , void * V_80 ,
unsigned long V_28 , struct V_81 * V_82 )
{
int V_48 = - V_83 ;
unsigned long V_84 , V_85 ;
struct V_5 * V_5 = V_2 -> V_5 ;
if ( ( V_80 == NULL ) || ( V_28 == 0 ) ) {
V_79 -> V_28 = 0 ;
return - V_83 ;
}
V_79 -> V_86 = V_80 ;
V_79 -> V_28 = V_28 ;
V_84 = ( unsigned long ) V_80 ;
V_85 = F_32 ( V_84 ) ;
V_79 -> V_51 = F_34 ( V_85 + V_28 , V_34 ) ;
V_79 -> V_37 = F_44 ( V_79 -> V_51 ,
sizeof( struct V_36 * ) + sizeof( T_5 ) ,
V_87 ) ;
if ( ! V_79 -> V_37 ) {
F_28 ( & V_5 -> V_39 , L_7 ) ;
V_79 -> V_51 = 0 ;
V_79 -> V_86 = NULL ;
V_79 -> V_28 = 0 ;
return - V_54 ;
}
V_79 -> V_32 = ( T_5 * ) ( V_79 -> V_37 + V_79 -> V_51 ) ;
V_48 = F_45 ( V_84 & V_88 ,
V_79 -> V_51 ,
1 ,
V_79 -> V_37 ) ;
if ( V_48 < 0 )
goto V_89;
if ( V_48 < V_79 -> V_51 ) {
F_40 ( V_79 -> V_37 , V_48 , 0 ) ;
V_48 = - V_59 ;
goto V_89;
}
V_48 = F_25 ( V_2 , V_79 -> V_37 , V_79 -> V_51 , V_79 -> V_32 ) ;
if ( V_48 != 0 )
goto V_90;
return 0 ;
V_90:
F_40 ( V_79 -> V_37 , V_79 -> V_51 , 0 ) ;
V_89:
F_46 ( V_79 -> V_37 ) ;
V_79 -> V_37 = NULL ;
V_79 -> V_32 = NULL ;
V_79 -> V_51 = 0 ;
V_79 -> V_86 = NULL ;
V_79 -> V_28 = 0 ;
return V_48 ;
}
int F_47 ( struct V_1 * V_2 , struct V_78 * V_79 ,
struct V_81 * V_82 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
if ( ! F_48 ( V_79 ) ) {
F_28 ( & V_5 -> V_39 , L_8 ,
V_40 , V_79 ) ;
return - V_83 ;
}
if ( V_79 -> V_32 )
F_23 ( V_2 , V_79 -> V_32 , V_79 -> V_51 ) ;
if ( V_79 -> V_37 ) {
F_40 ( V_79 -> V_37 , V_79 -> V_51 , 1 ) ;
F_46 ( V_79 -> V_37 ) ;
V_79 -> V_37 = NULL ;
V_79 -> V_32 = NULL ;
V_79 -> V_51 = 0 ;
}
V_79 -> V_86 = NULL ;
V_79 -> V_28 = 0 ;
return 0 ;
}
T_3 F_49 ( struct V_1 * V_2 )
{
T_1 V_91 = V_2 -> V_92 ;
return ( T_3 ) ( ( V_91 & V_93 ) >> 20 ) ;
}
int F_50 ( struct V_1 * V_2 )
{
T_1 V_94 ;
struct V_5 * V_5 = V_2 -> V_5 ;
if ( ! F_51 ( V_2 ) )
return - V_95 ;
F_1 ( V_2 , V_96 , 0x1ull ) ;
F_52 ( 1000 ) ;
F_5 ( V_2 , V_97 ) ;
F_5 ( V_2 , V_98 ) ;
F_5 ( V_2 , V_99 ) ;
V_94 = F_5 ( V_2 , V_96 ) & 0x3cull ;
F_1 ( V_2 , V_96 , V_94 | 0x2ull ) ;
F_52 ( 50 ) ;
if ( F_53 ( V_2 ) ) {
F_54 ( & V_5 -> V_39 ,
L_9 , V_40 ) ;
F_1 ( V_2 , V_100 , 0x0aull ) ;
}
return 0 ;
}
int F_55 ( struct V_1 * V_2 )
{
T_1 V_101 ;
if ( ! F_51 ( V_2 ) )
return - V_95 ;
V_101 = F_5 ( V_2 , V_102 ) & 0x1 ;
V_2 -> V_103 = ( V_101 == 0 ) ? 0x8ull : 0xcull ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 , int V_104 )
{
int V_48 ;
struct V_5 * V_5 = V_2 -> V_5 ;
V_48 = F_57 ( V_5 , 1 , V_104 ) ;
if ( V_48 < 0 )
return V_48 ;
V_2 -> V_71 |= V_105 ;
return 0 ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_71 & V_105 ) {
F_59 ( V_5 ) ;
V_2 -> V_71 &= ~ V_105 ;
}
}
static int F_60 ( struct V_1 * V_2 , struct V_106 * V_107 ,
unsigned int * V_18 , unsigned int V_79 , T_2 V_108 , T_2 V_109 ,
T_1 V_4 )
{
if ( F_61 ( * V_18 >= V_79 ) )
return - V_59 ;
V_107 [ * V_18 ] . V_108 = V_108 ;
V_107 [ * V_18 ] . V_109 = V_109 ;
V_107 [ * V_18 ] . V_4 = V_4 ;
++ * V_18 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_106 * V_107 ,
unsigned int * V_18 , unsigned int V_79 , T_2 V_108 , T_1 V_4 )
{
return F_60 ( V_2 , V_107 , V_18 , V_79 , V_108 , 0 , V_4 ) ;
}
int F_63 ( struct V_1 * V_2 , struct V_106 * V_110 ,
unsigned int V_111 , int V_112 )
{
unsigned int V_18 , V_19 , V_109 = 0 ;
T_2 V_113 , V_114 , V_115 , V_116 ;
T_1 V_117 , V_118 , V_119 , V_120 , V_121 , V_122 , V_123 ;
V_117 = F_5 ( V_2 , V_12 ) ;
F_62 ( V_2 , V_110 , & V_109 , V_111 , V_12 , V_117 ) ;
V_118 = F_5 ( V_2 , V_124 ) ;
F_62 ( V_2 , V_110 , & V_109 , V_111 , V_124 , V_118 ) ;
V_119 = F_5 ( V_2 , V_125 ) ;
F_62 ( V_2 , V_110 , & V_109 , V_111 , V_125 , V_119 ) ;
for ( V_18 = 0 ; V_18 < V_126 ; V_18 ++ ) {
V_113 = ( V_18 << 24 ) | 0x008 ;
V_120 = F_5 ( V_2 , V_113 ) ;
F_62 ( V_2 , V_110 , & V_109 , V_111 , V_113 , V_120 ) ;
V_114 = ( V_18 << 24 ) | 0x018 ;
V_121 = F_5 ( V_2 , V_114 ) ;
F_62 ( V_2 , V_110 , & V_109 , V_111 , V_114 , V_121 ) ;
for ( V_19 = 0 ; V_19 < 64 ; V_19 ++ ) {
if ( ! V_112 && ( ! ( V_120 & ( 1ull << V_19 ) ) ) )
continue;
V_115 = ( V_18 << 24 ) | ( 0x100 + 8 * V_19 ) ;
V_122 = F_5 ( V_2 , V_115 ) ;
F_62 ( V_2 , V_110 , & V_109 , V_111 , V_115 , V_122 ) ;
V_116 = ( V_18 << 24 ) | ( 0x300 + 8 * V_19 ) ;
V_123 = F_5 ( V_2 , V_116 ) ;
F_62 ( V_2 , V_110 , & V_109 , V_111 , V_116 , V_123 ) ;
}
}
for ( V_18 = V_109 ; V_18 < V_111 ; V_18 ++ ) {
V_110 [ V_18 ] . V_108 = 0xffffffff ;
V_110 [ V_18 ] . V_4 = 0xffffffffffffffffull ;
}
return V_109 ;
}
int F_64 ( struct V_1 * V_2 , int V_127 )
{
int V_128 = 0 , V_129 , V_130 , V_131 , V_132 ;
T_2 V_133 , V_134 , V_135 , V_136 ;
T_1 V_137 , V_4 , V_108 ;
V_133 = F_65 ( V_127 ) | V_138 ;
V_137 = F_5 ( V_2 , V_133 ) ;
if ( ( V_137 != 0x0 ) && ( V_137 != - 1ull ) ) {
V_134 = F_65 ( V_127 ) | V_137 ;
while ( 1 ) {
V_4 = F_5 ( V_2 , V_134 ) ;
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
V_108 = F_65 ( V_127 ) | F_66 ( V_129 ) ;
V_4 = F_5 ( V_2 , V_108 ) ;
if ( ( V_4 == 0x0ull ) || ( V_4 == - 1ull ) )
continue;
V_130 = ( V_4 >> 24 ) & 0xff ;
V_131 = ( V_4 >> 16 ) & 0xff ;
V_132 = V_4 & 0xffff ;
V_128 += V_130 + ( V_131 * V_132 ) ;
}
return V_128 ;
}
int F_67 ( struct V_1 * V_2 , int V_127 ,
struct V_106 * V_110 , unsigned int V_111 )
{
int V_18 , V_130 , V_131 , V_139 , V_132 , V_140 , V_129 ;
unsigned int V_109 = 0 ;
T_2 V_133 , V_134 , V_141 , V_135 , V_136 ;
T_1 V_137 , V_142 , V_4 , V_108 ;
V_133 = F_65 ( V_127 ) | V_138 ;
V_137 = F_5 ( V_2 , V_133 ) ;
if ( ( V_137 != 0x0 ) && ( V_137 != 0xffffffffffffffffull ) ) {
V_134 = F_65 ( V_127 ) | V_137 ;
while ( 1 ) {
V_142 = F_5 ( V_2 , V_134 ) ;
if ( ( V_142 == 0x0 ) || ( V_142 == 0xffffffffffffffffull ) )
break;
V_141 = ( V_142 & 0x0000000000ffffffull ) ;
V_135 = ( V_142 & 0x0000007fff000000ull ) >> 24 ;
V_136 = ( V_142 & 0x0000008000000000ull ) >> 36 ;
V_141 |= F_65 ( V_127 ) ;
if ( V_136 ) {
for ( V_18 = 0 ; V_18 < ( int ) V_135 ; V_18 ++ ) {
V_4 = F_5 ( V_2 , V_141 ) ;
F_60 ( V_2 , V_110 , & V_109 , V_111 ,
V_141 , V_18 , V_4 ) ;
}
} else {
V_135 >>= 3 ;
for ( V_18 = 0 ; V_18 < ( int ) V_135 ; V_18 ++ , V_141 += 8 ) {
V_4 = F_5 ( V_2 , V_141 ) ;
F_60 ( V_2 , V_110 , & V_109 , V_111 ,
V_141 , 0 , V_4 ) ;
}
}
V_134 += 8 ;
}
}
for ( V_129 = 0 ; V_129 < 8 ; V_129 ++ ) {
V_108 = F_65 ( V_127 ) | F_66 ( V_129 ) ;
V_4 = F_5 ( V_2 , V_108 ) ;
if ( ( V_4 == 0x0ull ) || ( V_4 == - 1ull ) )
continue;
V_130 = ( V_4 >> 24 ) & 0xff ;
V_131 = ( V_4 >> 16 ) & 0xff ;
V_132 = V_4 & 0xffff ;
for ( V_139 = 0 ; V_139 <= V_131 ; V_139 ++ ) {
T_2 V_143 =
F_68 ( V_129 , V_139 ) ;
V_108 = ( F_65 ( V_127 ) |
V_144 ) ;
F_1 ( V_2 , V_108 , V_143 ) ;
for ( V_140 = 0 ;
V_140 < ( V_139 ? V_132 : V_130 ) ;
V_140 ++ ) {
V_108 = ( F_65 ( V_127 ) |
V_145 ) ;
V_4 = F_5 ( V_2 , V_108 ) ;
F_60 ( V_2 , V_110 , & V_109 , V_111 , V_108 ,
( V_143 << 16 ) | V_140 , V_4 ) ;
}
}
}
return 0 ;
}
int F_69 ( struct V_1 * V_2 , T_2 V_146 , T_1 V_4 , int V_147 )
{
F_1 ( V_2 , V_148 , V_147 & 0xf ) ;
F_1 ( V_2 , V_146 , V_4 ) ;
return 0 ;
}
T_1 F_70 ( struct V_1 * V_2 , T_2 V_146 , int V_147 )
{
F_1 ( V_2 , V_148 , V_147 & 0xf ) ;
return F_5 ( V_2 , V_146 ) ;
}
int F_71 ( struct V_1 * V_2 )
{
T_7 V_149 ;
static const int V_150 [] = { 250 , 200 , 166 , 175 } ;
V_149 = ( T_7 ) ( ( V_2 -> V_92 >> 28 ) & 0x0full ) ;
if ( V_149 >= F_72 ( V_150 ) )
return 0 ;
return V_150 [ V_149 ] ;
}
void F_73 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_151 , 0xcull ) ;
}
void F_74 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_152 , 0xcull ) ;
if ( F_53 ( V_2 ) )
F_1 ( V_2 , V_100 , 0x0aull ) ;
}
