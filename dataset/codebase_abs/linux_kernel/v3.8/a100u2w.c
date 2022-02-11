static T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 10 ; V_3 ++ ) {
if ( F_2 ( V_2 -> V_4 + V_5 ) & V_6 )
return 1 ;
F_3 ( 100 ) ;
}
return 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 10 ; V_3 ++ ) {
if ( F_2 ( V_2 -> V_4 + V_7 ) & V_8 )
return 1 ;
F_3 ( 100 ) ;
}
return 0 ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 10 ; V_3 ++ ) {
if ( ! ( F_2 ( V_2 -> V_4 + V_5 ) & V_9 ) )
return 1 ;
F_3 ( 100 ) ;
}
return 0 ;
}
static T_1 F_6 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 10 ; V_3 ++ ) {
if ( ! ( F_2 ( V_2 -> V_4 + V_5 ) & V_10 ) )
return 1 ;
F_3 ( 100 ) ;
}
return 0 ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 * V_11 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 10 ; V_3 ++ ) {
if ( ( * V_11 = F_2 ( V_2 -> V_4 + V_7 ) ) & V_12 )
return 1 ;
F_3 ( 100 ) ;
}
return 0 ;
}
static unsigned short F_8 ( struct V_1 * V_2 )
{
T_2 V_13 ;
T_1 V_11 ;
F_9 ( V_14 , V_2 -> V_4 + V_15 ) ;
F_9 ( V_10 , V_2 -> V_4 + V_5 ) ;
if ( F_6 ( V_2 ) == 0 )
return 0 ;
if ( F_7 ( V_2 , & V_11 ) == 0 )
return 0 ;
V_13 = F_2 ( V_2 -> V_4 + V_15 ) ;
F_9 ( V_11 , V_2 -> V_4 + V_7 ) ;
if ( F_7 ( V_2 , & V_11 ) == 0 )
return 0 ;
V_13 |= F_2 ( V_2 -> V_4 + V_15 ) << 8 ;
F_9 ( V_11 , V_2 -> V_4 + V_7 ) ;
return V_13 ;
}
static T_1 F_10 ( struct V_1 * V_2 , unsigned char V_16 , unsigned char V_17 )
{
F_9 ( V_18 , V_2 -> V_4 + V_15 ) ;
F_9 ( V_10 , V_2 -> V_4 + V_5 ) ;
if ( F_6 ( V_2 ) == 0 )
return 0 ;
F_9 ( V_16 , V_2 -> V_4 + V_15 ) ;
F_9 ( V_10 , V_2 -> V_4 + V_5 ) ;
if ( F_6 ( V_2 ) == 0 )
return 0 ;
F_9 ( V_17 , V_2 -> V_4 + V_15 ) ;
F_9 ( V_10 , V_2 -> V_4 + V_5 ) ;
if ( F_6 ( V_2 ) == 0 )
return 0 ;
return 1 ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_1 V_16 , T_1 * V_19 )
{
unsigned char V_11 ;
F_9 ( V_20 , V_2 -> V_4 + V_15 ) ;
F_9 ( V_10 , V_2 -> V_4 + V_5 ) ;
if ( F_6 ( V_2 ) == 0 )
return 0 ;
F_9 ( V_16 , V_2 -> V_4 + V_15 ) ;
F_9 ( V_10 , V_2 -> V_4 + V_5 ) ;
if ( F_6 ( V_2 ) == 0 )
return 0 ;
if ( F_7 ( V_2 , & V_11 ) == 0 )
return 0 ;
* V_19 = F_2 ( V_2 -> V_4 + V_15 ) ;
F_9 ( V_11 , V_2 -> V_4 + V_7 ) ;
return 1 ;
}
static void F_12 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
V_22 -> V_23 = V_24 ;
F_9 ( V_22 -> V_25 , V_2 -> V_4 + V_26 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 * V_27 , V_28 = 0 ;
V_27 = ( T_1 * ) V_29 ;
for ( V_3 = 0 ; V_3 < 64 ; V_3 ++ , V_27 ++ ) {
if ( F_11 ( V_2 , ( T_1 ) V_3 , V_27 ) == 0 )
return - 1 ;
}
V_27 = ( T_1 * ) V_29 ;
for ( V_3 = 0 ; V_3 < 63 ; V_3 ++ )
V_28 += * V_27 ++ ;
if ( V_29 -> V_30 != ( T_1 ) V_28 )
return - 1 ;
return 1 ;
}
static void F_14 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 * V_27 , * V_31 , V_28 = 0 ;
V_27 = ( T_1 * ) V_32 ;
for ( V_3 = 0 ; V_3 < 63 ; V_3 ++ )
V_28 += * V_27 ++ ;
* V_27 = V_28 ;
V_27 = ( T_1 * ) V_32 ;
V_31 = ( T_1 * ) V_29 ;
for ( V_3 = 0 ; V_3 < 64 ; V_3 ++ , V_27 ++ , V_31 ++ ) {
if ( * V_27 != * V_31 )
F_10 ( V_2 , ( T_1 ) V_3 , * V_27 ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 ) != 1 ) {
F_14 ( V_2 ) ;
F_13 ( V_2 ) ;
}
}
static T_1 F_16 ( struct V_1 * V_2 )
{
T_3 V_33 ;
T_2 V_34 ;
T_2 V_3 ;
T_1 * V_35 , V_11 ;
V_11 = F_2 ( V_2 -> V_4 + V_36 ) ;
F_9 ( V_11 | V_37 , V_2 -> V_4 + V_36 ) ;
F_9 ( 0x00 , V_2 -> V_4 + V_38 ) ;
F_17 ( 0x0000 , V_2 -> V_4 + V_39 ) ;
if ( F_2 ( V_2 -> V_4 + V_40 ) != 0x55 ) {
F_9 ( V_11 , V_2 -> V_4 + V_36 ) ;
return 0 ;
}
F_17 ( 0x0001 , V_2 -> V_4 + V_39 ) ;
if ( F_2 ( V_2 -> V_4 + V_40 ) != 0xAA ) {
F_9 ( V_11 , V_2 -> V_4 + V_36 ) ;
return 0 ;
}
F_9 ( V_41 | V_42 , V_2 -> V_4 + V_43 ) ;
V_35 = ( T_1 * ) & V_33 ;
V_33 = F_18 ( 0 ) ;
F_17 ( 0x0010 , V_2 -> V_4 + V_39 ) ;
* V_35 = F_2 ( V_2 -> V_4 + V_40 ) ;
F_17 ( 0x0011 , V_2 -> V_4 + V_39 ) ;
* ( V_35 + 1 ) = F_2 ( V_2 -> V_4 + V_40 ) ;
F_17 ( 0x0012 , V_2 -> V_4 + V_39 ) ;
* ( V_35 + 2 ) = F_2 ( V_2 -> V_4 + V_40 ) ;
F_17 ( * ( V_35 + 2 ) , V_2 -> V_4 + V_38 ) ;
F_19 ( F_20 ( V_33 ) , V_2 -> V_4 + V_44 ) ;
F_21 ( 500 ) ;
V_34 = ( T_2 ) F_20 ( V_33 ) ;
for ( V_3 = 0 , V_35 = ( T_1 * ) & V_33 ;
V_3 < 0x1000 ;
V_3 ++ , V_34 ++ ) {
F_17 ( V_34 , V_2 -> V_4 + V_39 ) ;
* V_35 ++ = F_2 ( V_2 -> V_4 + V_40 ) ;
if ( ( V_3 % 4 ) == 3 ) {
F_19 ( F_20 ( V_33 ) , V_2 -> V_4 + V_45 ) ;
V_35 = ( T_1 * ) & V_33 ;
}
}
F_9 ( V_41 | V_42 , V_2 -> V_4 + V_43 ) ;
V_34 -= 0x1000 ;
for ( V_3 = 0 , V_35 = ( T_1 * ) & V_33 ;
V_3 < 0x1000 ;
V_3 ++ , V_34 ++ ) {
F_17 ( V_34 , V_2 -> V_4 + V_39 ) ;
* V_35 ++ = F_2 ( V_2 -> V_4 + V_40 ) ;
if ( ( V_3 % 4 ) == 3 ) {
if ( F_22 ( V_2 -> V_4 + V_45 ) != F_20 ( V_33 ) ) {
F_9 ( V_41 , V_2 -> V_4 + V_43 ) ;
F_9 ( V_11 , V_2 -> V_4 + V_36 ) ;
return 0 ;
}
V_35 = ( T_1 * ) & V_33 ;
}
}
F_9 ( V_41 , V_2 -> V_4 + V_43 ) ;
F_9 ( V_11 , V_2 -> V_4 + V_36 ) ;
return 1 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
int V_3 ;
struct V_46 * V_47 ;
T_4 V_48 ;
F_9 ( V_49 , V_2 -> V_4 + V_50 ) ;
F_19 ( V_2 -> V_51 , V_2 -> V_4 + V_52 ) ;
F_19 ( V_2 -> V_51 , V_2 -> V_4 + V_53 ) ;
V_22 = V_2 -> V_54 ;
V_47 = V_2 -> V_55 ;
for ( V_3 = 0 ; V_3 < V_49 ; V_3 ++ ) {
V_48 = ( V_2 -> V_48 + ( sizeof( struct V_46 ) * V_3 ) ) ;
V_22 -> V_56 = F_18 ( ( T_3 ) V_48 ) ;
V_22 -> V_57 = F_18 ( ( T_3 ) V_48 ) ;
V_22 -> V_47 = V_47 ;
V_22 -> V_25 = V_3 ;
V_22 ++ ;
V_47 ++ ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_3 , V_58 ;
for ( V_3 = 0 ; V_3 < V_59 ; V_3 ++ ) {
for ( V_58 = 0 ; V_58 < 8 ; V_58 ++ ) {
V_2 -> V_60 [ V_3 ] [ V_58 ] = 0xffffffff ;
}
}
}
static int F_25 ( struct V_1 * V_2 )
{
T_1 * V_19 ;
T_2 V_61 ;
T_1 V_3 ;
F_24 ( V_2 ) ;
F_9 ( 0xFF , V_2 -> V_4 + V_62 ) ;
if ( F_2 ( V_2 -> V_4 + V_7 ) & V_8 ) {
V_61 = F_8 ( V_2 ) ;
if ( V_61 == 0xFFFF ) {
F_9 ( V_63 , V_2 -> V_4 + V_5 ) ;
if ( F_1 ( V_2 ) == 0 )
return - 1 ;
F_16 ( V_2 ) ;
F_23 ( V_2 ) ;
F_9 ( 0x00 , V_2 -> V_4 + V_5 ) ;
if ( F_4 ( V_2 ) == 0 )
return - 1 ;
} else {
F_23 ( V_2 ) ;
}
} else {
F_9 ( V_63 , V_2 -> V_4 + V_5 ) ;
if ( F_1 ( V_2 ) == 0 )
return - 1 ;
F_16 ( V_2 ) ;
F_23 ( V_2 ) ;
F_9 ( V_10 , V_2 -> V_4 + V_5 ) ;
if ( F_4 ( V_2 ) == 0 )
return - 1 ;
}
F_15 ( V_2 ) ;
if ( V_29 -> V_61 != 1 )
return - 1 ;
V_2 -> V_64 = V_29 -> V_64 ;
V_2 -> V_65 = V_29 -> V_66 ;
V_2 -> V_67 = V_68 ;
V_19 = ( T_1 * ) & ( V_29 -> V_69 ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_19 ++ , V_3 ++ ) {
V_2 -> V_70 [ V_3 ] = * V_19 ;
V_2 -> V_71 [ V_3 ] = V_72 ;
}
if ( V_29 -> V_73 & V_74 )
V_2 -> V_75 |= V_76 ;
F_9 ( 0xFB , V_2 -> V_4 + V_62 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
unsigned long V_75 ;
F_27 ( & V_2 -> V_77 , V_75 ) ;
F_24 ( V_2 ) ;
F_9 ( V_9 , V_2 -> V_4 + V_5 ) ;
if ( F_5 ( V_2 ) == 0 ) {
F_28 ( & V_2 -> V_77 , V_75 ) ;
return V_78 ;
} else {
F_28 ( & V_2 -> V_77 , V_75 ) ;
return V_79 ;
}
}
static int F_29 ( struct V_1 * V_2 , struct V_80 * V_81 , unsigned int V_82 )
{
struct V_21 * V_22 ;
struct V_46 * V_47 ;
struct V_21 * V_83 ;
T_1 V_3 ;
unsigned long V_75 ;
F_27 ( & ( V_2 -> V_77 ) , V_75 ) ;
V_22 = (struct V_21 * ) NULL ;
V_47 = (struct V_46 * ) NULL ;
V_83 = V_2 -> V_54 ;
F_24 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_49 ; V_3 ++ ) {
V_47 = V_83 -> V_47 ;
if ( V_83 -> V_23 && V_47 -> V_84 == V_81 )
break;
V_83 ++ ;
}
if ( V_3 == V_49 ) {
F_30 ( V_85 L_1 ) ;
F_28 ( & ( V_2 -> V_77 ) , V_75 ) ;
return V_78 ;
}
if ( ( V_22 = F_31 ( V_2 ) ) == NULL ) {
F_28 ( & ( V_2 -> V_77 ) , V_75 ) ;
return V_78 ;
}
V_22 -> V_86 = V_87 ;
V_22 -> V_82 = V_82 ;
V_22 -> V_88 = 0 ;
V_22 -> V_89 = 0 ;
V_22 -> V_23 = 0x0 ;
V_22 -> V_90 = 0xFF ;
V_22 -> V_91 = 0 ;
V_22 -> V_92 = 0 ;
V_22 -> V_93 = F_18 ( 0 ) ;
V_22 -> V_94 = F_18 ( 0 ) ;
V_47 -> V_84 = NULL ;
V_47 -> V_84 = V_81 ;
F_12 ( V_2 , V_22 ) ;
F_28 ( & V_2 -> V_77 , V_75 ) ;
return V_79 ;
}
static struct V_21 * F_31 ( struct V_1 * V_2 )
{
T_1 V_95 ;
unsigned long V_96 ;
T_1 V_97 ;
T_1 V_3 ;
V_95 = V_2 -> V_97 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
for ( V_97 = 0 ; V_97 < 32 ; V_97 ++ ) {
if ( ( V_2 -> V_60 [ V_95 ] [ V_3 ] >> V_97 ) & 0x01 ) {
V_2 -> V_60 [ V_95 ] [ V_3 ] &= ~ ( 1 << V_97 ) ;
V_96 = V_97 + 32 * V_3 ;
return V_2 -> V_54 + V_96 ;
}
}
}
return NULL ;
}
static struct V_21 * F_32 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
unsigned long V_75 ;
F_27 ( & V_2 -> V_77 , V_75 ) ;
V_22 = F_31 ( V_2 ) ;
F_28 ( & V_2 -> V_77 , V_75 ) ;
return V_22 ;
}
static void F_33 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
unsigned long V_75 ;
T_1 V_97 , V_3 , V_95 ;
F_27 ( & ( V_2 -> V_77 ) , V_75 ) ;
V_95 = V_2 -> V_97 ;
V_97 = V_22 -> V_25 ;
V_3 = V_97 / 32 ;
V_97 %= 32 ;
V_2 -> V_60 [ V_95 ] [ V_3 ] |= ( 1 << V_97 ) ;
F_28 ( & ( V_2 -> V_77 ) , V_75 ) ;
}
static int F_34 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
unsigned char V_11 , V_23 ;
F_9 ( V_98 , V_2 -> V_4 + V_15 ) ;
F_9 ( V_10 , V_2 -> V_4 + V_5 ) ;
if ( F_6 ( V_2 ) == 0 )
return 0 ;
F_9 ( V_22 -> V_25 , V_2 -> V_4 + V_15 ) ;
F_9 ( V_10 , V_2 -> V_4 + V_5 ) ;
if ( F_6 ( V_2 ) == 0 )
return 0 ;
if ( F_7 ( V_2 , & V_11 ) == 0 )
return 0 ;
V_23 = F_2 ( V_2 -> V_4 + V_15 ) ;
F_9 ( V_11 , V_2 -> V_4 + V_7 ) ;
if ( V_23 == 1 )
return 0 ;
return 1 ;
}
static int F_35 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
struct V_46 * V_47 ;
struct V_21 * V_22 ;
T_1 V_3 ;
unsigned long V_75 ;
F_27 ( & ( V_2 -> V_77 ) , V_75 ) ;
V_22 = V_2 -> V_54 ;
for ( V_3 = 0 ; V_3 < V_49 ; V_3 ++ , V_22 ++ ) {
V_47 = V_22 -> V_47 ;
if ( V_22 -> V_23 && V_47 -> V_84 == V_81 ) {
if ( V_22 -> V_99 == 0 ) {
goto V_100;
} else {
if ( F_34 ( V_2 , V_22 ) ) {
V_47 -> V_84 = NULL ;
F_28 ( & V_2 -> V_77 , V_75 ) ;
return V_79 ;
} else
goto V_100;
}
}
}
V_100:
F_28 ( & V_2 -> V_77 , V_75 ) ;
return V_78 ;
}
static T_5 F_36 ( struct V_1 * V_2 )
{
T_1 V_101 ;
struct V_21 * V_22 ;
if ( F_2 ( V_2 -> V_4 + V_102 ) == 0 )
return V_103 ;
do {
V_101 = F_2 ( V_2 -> V_4 + V_104 ) ;
V_22 = (struct V_21 * ) ( ( unsigned long ) V_2 -> V_54 + ( unsigned long ) ( sizeof( struct V_21 ) * V_101 ) ) ;
V_22 -> V_23 = 0x0 ;
F_37 ( V_2 , V_22 ) ;
} while ( F_2 ( V_2 -> V_4 + V_102 ) );
return V_105 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_21 * V_22 , struct V_80 * V_81 )
{
struct V_106 * V_107 ;
struct V_108 * V_109 ;
int V_3 , V_110 ;
struct V_46 * V_47 ;
V_47 = V_22 -> V_47 ;
V_47 -> V_84 = V_81 ;
V_109 = NULL ;
V_22 -> V_86 = V_111 ;
V_22 -> V_75 = V_112 ;
V_22 -> V_82 = V_81 -> V_113 -> V_114 ;
V_22 -> V_115 = V_81 -> V_113 -> V_115 ;
V_22 -> V_91 = 0 ;
V_22 -> V_92 = 0 ;
V_22 -> V_94 = F_18 ( 0 ) ;
V_22 -> V_93 = F_18 ( ( T_3 ) F_39 ( V_81 ) ) ;
V_109 = (struct V_108 * ) & V_47 -> V_116 [ 0 ] ;
V_110 = F_40 ( V_81 ) ;
if ( V_110 < 0 )
return V_110 ;
F_41 ( V_110 > V_117 ) ;
if ( V_110 ) {
V_22 -> V_94 = F_18 ( ( T_3 ) ( V_110 * 8 ) ) ;
F_42 (cmd, sg, count_sg, i) {
V_109 -> V_4 = F_18 ( ( T_3 ) F_43 ( V_107 ) ) ;
V_109 -> V_118 = F_18 ( ( T_3 ) F_44 ( V_107 ) ) ;
V_109 ++ ;
}
} else {
V_22 -> V_94 = F_18 ( 0 ) ;
V_109 -> V_4 = F_18 ( 0 ) ;
V_109 -> V_118 = F_18 ( 0 ) ;
}
V_22 -> V_56 = ( T_3 ) V_22 -> V_57 ;
V_22 -> V_88 = 0 ;
V_22 -> V_89 = 0 ;
V_22 -> V_90 = 0xFF ;
V_22 -> V_119 = V_120 ;
V_22 -> V_121 = V_81 -> V_122 ;
if ( V_22 -> V_121 >= V_123 ) {
F_30 ( L_2 , V_81 -> V_122 ) ;
V_22 -> V_121 = V_123 ;
}
V_22 -> V_124 = V_81 -> V_113 -> V_115 | V_125 ;
if ( V_81 -> V_113 -> V_126 ) {
V_22 -> V_99 = V_127 ;
} else {
V_22 -> V_99 = 0 ;
}
memcpy ( V_22 -> V_128 , V_81 -> V_129 , V_22 -> V_121 ) ;
return 0 ;
}
static int F_45 ( struct V_80 * V_81 , void (* F_46) ( struct V_80 * ) )
{
struct V_21 * V_22 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_81 -> V_113 -> V_2 -> V_130 ;
V_81 -> V_131 = F_46 ;
if ( ( V_22 = F_32 ( V_2 ) ) == NULL )
return V_132 ;
if ( F_38 ( V_2 , V_22 , V_81 ) ) {
F_33 ( V_2 , V_22 ) ;
return V_132 ;
}
F_12 ( V_2 , V_22 ) ;
return 0 ;
}
static int F_47 ( struct V_80 * V_81 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_81 -> V_113 -> V_2 -> V_130 ;
return F_26 ( V_2 ) ;
}
static int F_48 ( struct V_80 * V_81 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_81 -> V_113 -> V_2 -> V_130 ;
return F_29 ( V_2 , V_81 , F_49 ( V_81 ) ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_80 * V_81 ;
struct V_46 * V_47 ;
V_47 = V_22 -> V_47 ;
if ( ( V_81 = (struct V_80 * ) V_47 -> V_84 ) == NULL ) {
F_30 ( V_85 L_3 ) ;
F_33 ( V_2 , V_22 ) ;
return;
}
V_47 -> V_84 = NULL ;
switch ( V_22 -> V_88 ) {
case 0x0 :
case 0xa :
case 0xb :
V_22 -> V_88 = 0 ;
break;
case 0x11 :
V_22 -> V_88 = V_133 ;
break;
case 0x14 :
V_22 -> V_88 = V_134 ;
break;
case 0x1a :
V_22 -> V_88 = V_135 ;
break;
case 0x12 :
case 0x13 :
case 0x16 :
default:
F_30 ( V_136 L_4 , V_22 -> V_88 , V_22 -> V_89 ) ;
V_22 -> V_88 = V_137 ;
break;
}
if ( V_22 -> V_89 == 2 ) {
memcpy ( ( unsigned char * ) & V_81 -> V_138 [ 0 ] ,
( unsigned char * ) & V_47 -> V_116 [ 0 ] , V_120 ) ;
}
V_81 -> V_139 = V_22 -> V_89 | ( V_22 -> V_88 << 16 ) ;
F_50 ( V_81 ) ;
V_81 -> V_131 ( V_81 ) ;
F_33 ( V_2 , V_22 ) ;
}
static T_5 F_51 ( int V_140 , void * V_141 )
{
struct V_142 * V_143 = (struct V_142 * ) V_141 ;
struct V_1 * V_2 = (struct V_1 * ) V_143 -> V_130 ;
unsigned long V_75 ;
T_5 V_144 ;
F_27 ( V_143 -> V_145 , V_75 ) ;
V_144 = F_36 ( V_2 ) ;
F_28 ( V_143 -> V_145 , V_75 ) ;
return V_144 ;
}
static int F_52 ( struct V_146 * V_147 ,
const struct V_148 * V_114 )
{
struct V_142 * V_143 ;
struct V_1 * V_2 ;
unsigned long V_149 , V_150 ;
int error = - V_151 ;
T_3 V_152 ;
unsigned long V_153 ;
char * V_154 ;
if ( F_53 ( V_147 ) )
goto V_100;
if ( F_54 ( V_147 , F_55 ( 32 ) ) ) {
F_30 ( V_155 L_5
L_6 ) ;
goto V_156;
}
F_56 ( V_147 ) ;
V_149 = F_57 ( V_147 , 0 ) ;
if ( ! F_58 ( V_149 , 256 , L_7 ) ) {
F_30 ( V_155 L_8 , V_149 ) ;
goto V_156;
}
V_150 = F_59 ( V_149 + 0x50 ) ;
V_143 = F_60 ( & V_157 , sizeof( struct V_1 ) ) ;
if ( ! V_143 )
goto V_158;
V_2 = (struct V_1 * ) V_143 -> V_130 ;
V_2 -> V_147 = V_147 ;
V_2 -> V_4 = V_149 ;
V_2 -> V_65 = V_150 ;
F_61 ( & V_2 -> V_77 ) ;
V_152 = V_49 * sizeof( struct V_21 ) ;
V_2 -> V_54 = F_62 ( V_147 , V_152 ,
& V_2 -> V_51 ) ;
if ( ! V_2 -> V_54 ) {
F_30 ( L_9 ) ;
goto V_159;
}
memset ( V_2 -> V_54 , 0 , V_152 ) ;
V_152 = V_49 * sizeof( struct V_46 ) ;
V_2 -> V_55 = F_62 ( V_147 , V_152 ,
& V_2 -> V_48 ) ;
if ( ! V_2 -> V_55 ) {
F_30 ( L_10 ) ;
goto V_160;
}
memset ( V_2 -> V_55 , 0 , V_152 ) ;
V_153 = V_2 -> V_65 ;
V_153 = ( V_153 << 4 ) ;
V_154 = F_63 ( V_153 ) ;
if ( F_25 ( V_2 ) ) {
F_30 ( L_11 ) ;
goto V_161;
}
V_143 -> V_162 = V_2 -> V_4 ;
V_143 -> V_163 = 0xff ;
V_143 -> V_164 = V_49 ;
V_143 -> V_165 = V_143 -> V_162 ;
V_143 -> V_166 = V_2 -> V_67 ;
V_143 -> V_167 = 16 ;
V_143 -> V_168 = V_147 -> V_168 ;
V_143 -> V_169 = V_2 -> V_64 ;
V_143 -> V_170 = V_117 ;
error = F_64 ( V_147 -> V_168 , F_51 , V_171 ,
L_7 , V_143 ) ;
if ( error < 0 ) {
F_30 ( V_155 L_12 ,
V_147 -> V_168 ) ;
goto V_161;
}
F_65 ( V_147 , V_143 ) ;
error = F_66 ( V_143 , & V_147 -> V_172 ) ;
if ( error )
goto V_173;
F_67 ( V_143 ) ;
return 0 ;
V_173:
F_68 ( V_143 -> V_168 , V_143 ) ;
V_161:
F_69 ( V_147 , V_49 * sizeof( struct V_46 ) ,
V_2 -> V_55 , V_2 -> V_48 ) ;
V_160:
F_69 ( V_147 , V_49 * sizeof( struct V_21 ) ,
V_2 -> V_54 , V_2 -> V_51 ) ;
V_159:
F_70 ( V_143 ) ;
V_158:
F_71 ( V_149 , 256 ) ;
V_156:
F_72 ( V_147 ) ;
V_100:
return error ;
}
static void F_73 ( struct V_146 * V_147 )
{
struct V_142 * V_143 = F_74 ( V_147 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_143 -> V_130 ;
F_75 ( V_143 ) ;
F_68 ( V_143 -> V_168 , V_143 ) ;
F_69 ( V_147 , V_49 * sizeof( struct V_46 ) ,
V_2 -> V_55 , V_2 -> V_48 ) ;
F_69 ( V_147 , V_49 * sizeof( struct V_21 ) ,
V_2 -> V_54 , V_2 -> V_51 ) ;
F_71 ( V_143 -> V_162 , 256 ) ;
F_70 ( V_143 ) ;
}
static int T_6 F_76 ( void )
{
return F_77 ( & V_174 ) ;
}
static void T_7 F_78 ( void )
{
F_79 ( & V_174 ) ;
}
