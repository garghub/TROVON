static void F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned long V_4 ,
unsigned long V_5 )
{
unsigned long V_6 = V_3 ;
int V_7 ;
for ( V_7 = 0 ; V_7 <= 7 ; V_7 ++ )
V_2 -> V_8 [ V_7 ] = V_6 + V_7 * 4 ;
V_2 -> V_9 . V_10 = V_4 ;
V_2 -> V_9 . V_11 = V_5 ;
}
static int F_2 ( T_1 * V_12 )
{
unsigned long V_13 = V_12 -> V_9 . V_11 + V_14 * 4 ;
if ( F_3 ( ( void V_15 * ) V_13 ) & 0x03 )
return 1 ;
return 0 ;
}
static int F_4 ( T_2 * V_16 )
{
T_3 V_17 ;
T_1 * V_12 = V_16 -> V_12 ;
struct V_18 * V_9 = & V_12 -> V_9 ;
unsigned long V_19 = V_9 -> V_11 + ( V_14 << 2 ) ;
V_17 = F_3 ( ( void V_15 * ) V_19 ) ;
if ( V_17 & 0x03 ) {
T_4 V_20 = F_5 ( V_12 ) ;
int V_21 = 0 ;
V_20 = F_5 ( V_12 ) ;
while ( ( V_20 & V_22 ) && ( V_21 ++ < 100 ) ) {
F_6 ( 1 ) ;
V_20 = F_5 ( V_12 ) ;
}
if ( V_17 & 0x02 ) {
struct V_23 * V_24 = F_7 ( V_12 -> V_24 ) ;
T_3 V_25 , V_26 ,
V_27 ;
V_25 =
F_3 ( ( void V_15 * ) V_9 -> V_11 ) ;
V_26 =
F_3 ( ( void V_15 * ) ( V_9 -> V_11 + 4 ) ) ;
F_8 ( V_24 , V_28 ,
& V_27 ) ;
F_9 ( V_29 L_1
L_2 ,
V_30 , V_16 -> V_31 , V_27 ) ;
F_9 ( V_29 L_3 ,
V_30 , V_16 -> V_31 ,
V_26 , V_25 ) ;
F_10 ( V_24 , V_28 , 0x00000146 ) ;
}
F_11 ( 0x03 , ( void V_15 * ) V_19 ) ;
V_17 = F_3 ( ( void V_15 * ) V_19 ) ;
}
return V_17 & 3 ;
}
static void F_12 ( T_2 * V_16 )
{
T_1 * V_12 = V_16 -> V_12 ;
unsigned long V_32 = V_12 -> V_33 + V_34 * 4 ;
unsigned int V_6 = F_3 ( ( void V_15 * ) V_32 ) ;
unsigned int V_35 = V_6 | V_36 ;
F_11 ( V_35 , ( void V_15 * ) V_32 ) ;
}
static T_3 F_13 ( T_1 * V_12 , T_5 V_33 )
{
unsigned long V_32 = V_33 + V_34 * 4 ;
T_3 V_37 ;
int V_21 ;
V_21 = 0 ;
V_37 = F_3 ( ( void V_15 * ) V_32 ) ;
while ( ( V_37 & V_38 ) && ( V_21 ++ < 200 ) ) {
F_6 ( 1 ) ;
V_37 = F_3 ( ( void V_15 * ) V_32 ) ;
}
return V_37 ;
}
static int F_14 ( T_2 * V_16 )
{
T_3 V_37 , V_39 , V_40 , V_41 , V_42 = 0 , V_43 = 0 ;
T_1 * V_12 = V_16 -> V_12 ;
unsigned long V_33 = V_12 -> V_33 ;
int V_44 = 0 ;
unsigned long * V_45 = F_15 ( V_12 ) ;
F_11 ( V_38 , ( void V_15 * ) ( V_33 + V_34 * 4 ) ) ;
V_37 = F_13 ( V_12 , V_33 ) ;
if ( V_37 & V_38 ) {
F_9 ( V_29
L_4
L_5 ,
V_30 , V_16 -> V_31 , V_37 ) ;
V_44 = 1 ;
}
while ( ( V_43 ++ < 200 ) && ( ! V_42 ) ) {
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ ) {
if ( V_45 [ V_41 ] ) {
V_42 = 1 ;
break;
}
}
F_6 ( 1 ) ;
}
if ( ! V_42 ) {
F_9 ( V_29 L_6 , V_30 ,
V_16 -> V_31 ) ;
V_44 = 1 ;
}
V_39 = F_3 ( ( void V_15 * ) ( V_33 + V_46 * 4 ) ) ;
V_40 = F_3 ( ( void V_15 * ) ( V_33 + V_47 * 4 ) ) ;
if ( ( V_39 & 0x01FF ) || ( V_40 & 0x1FF ) ) {
if ( V_39 > V_40 + 8 ) {
F_9 ( V_29
L_7
L_8 ,
V_30 , V_16 -> V_31 , V_39 , V_40 ) ;
}
}
return V_44 ;
}
static void F_16 ( T_1 * V_12 , T_2 * V_16 )
{
}
static int F_17 ( T_2 * V_16 )
{
return F_2 ( V_16 -> V_12 ) ;
}
static void F_18 ( T_2 * V_16 , int V_48 )
{
if ( ! V_48 )
F_4 ( V_16 ) ;
}
static void F_19 ( T_2 * V_16 )
{
struct V_49 * V_50 = & V_16 -> V_12 -> V_50 ;
F_14 ( V_16 ) ;
F_20 ( V_16 , V_50 ) ;
F_4 ( V_16 ) ;
}
static void F_21 ( T_2 * V_16 )
{
F_19 ( V_16 ) ;
F_22 ( V_16 ) ;
}
static T_4 F_5 ( T_1 * V_12 )
{
unsigned long V_51 = V_12 -> V_9 . V_52 ;
T_4 V_6 = ( T_4 ) F_23 ( ( void V_15 * ) V_51 ) ;
if ( ! ( V_6 & V_22 ) ) {
unsigned long V_19 = V_51 - 0x110 ;
unsigned int V_17 = ( T_3 ) F_3 ( ( void V_15 * ) V_19 ) ;
if ( V_17 & 0x03 ) {
F_11 ( 0x03 , ( void V_15 * ) V_19 ) ;
V_17 = ( T_3 ) F_3 ( ( void V_15 * ) V_19 ) ;
}
}
return V_6 ;
}
static int F_24 ( T_1 * V_12 , const struct V_53 * V_54 )
{
struct V_23 * V_24 = F_7 ( V_12 -> V_24 ) ;
unsigned long V_33 = F_25 ( V_24 , 0 ) + V_55 ;
int V_56 = sizeof( struct V_57 ) ;
void * V_58 ;
F_9 ( V_59 L_9 , V_12 -> V_31 ) ;
if ( F_26 ( V_33 , V_56 , V_12 -> V_31 ) == NULL ) {
F_9 ( V_29 L_10
L_11 , V_30 , V_12 -> V_31 ,
V_33 , V_33 + V_56 - 1 ) ;
return - 1 ;
}
V_12 -> V_33 = ( unsigned long ) V_12 -> V_9 . V_11 +
V_55 ;
V_12 -> V_60 = V_61 ;
V_12 -> V_62 = V_61 ;
V_12 -> V_63 = V_64 ;
if ( F_27 ( V_12 ) )
goto V_65;
V_58 = F_28 ( & V_24 -> V_24 , V_66 ,
( V_67 * ) & V_12 -> V_68 , V_69 ) ;
if ( V_58 ) {
F_29 ( V_12 , V_58 ) ;
return 0 ;
}
F_30 ( V_12 ) ;
F_9 ( V_29 L_12 ,
V_30 , V_12 -> V_31 ) ;
F_9 ( V_59 L_13 , V_12 -> V_31 ) ;
V_65:
F_31 ( V_33 , V_56 ) ;
return - 1 ;
}
static void F_32 ( int V_70 , T_2 * V_16 )
{
T_3 V_37 ;
T_1 * V_12 = V_16 -> V_12 ;
unsigned long V_33 = V_12 -> V_33 ;
unsigned long V_32 = V_33 + V_34 * 4 ;
T_3 V_71 , V_72 ;
V_37 = F_3 ( ( void V_15 * ) V_32 ) ;
if ( V_37 & V_73 ) {
F_9 ( V_74 L_14
L_15 , V_30 , V_16 -> V_31 ) ;
F_11 ( V_38 , ( void V_15 * ) V_32 ) ;
V_37 = F_13 ( V_12 , V_33 ) ;
if ( V_37 & V_38 )
F_9 ( V_29 L_16
L_17 , V_30 , V_16 -> V_31 ) ;
}
V_37 = F_3 ( ( void V_15 * ) V_32 ) ;
if ( V_37 & V_75 ) {
F_9 ( V_74 L_18
L_19 ,
V_30 , V_16 -> V_31 , V_37 ) ;
F_11 ( V_38 , ( void V_15 * ) V_32 ) ;
V_37 = F_13 ( V_12 , V_33 ) ;
if ( V_37 & V_38 )
F_9 ( V_29 L_16
L_17 , V_30 , V_16 -> V_31 ) ;
}
V_71 = F_33 ( V_12 -> V_76 ) ;
F_11 ( V_71 , ( void V_15 * ) ( V_33 + V_77 * 4 ) ) ;
memset ( F_15 ( V_12 ) , 0 , V_66 ) ;
V_72 = F_33 ( V_12 -> V_68 ) ;
F_11 ( V_72 , ( void V_15 * ) ( V_33 +
V_78 * 4 ) ) ;
F_11 ( V_70 , ( void V_15 * ) V_32 ) ;
}
static int F_34 ( T_2 * V_16 , struct V_49 * V_50 )
{
T_1 * V_12 = V_16 -> V_12 ;
unsigned int * V_79 = V_12 -> V_80 ;
unsigned int V_21 = 0 , V_7 = V_50 -> V_81 ;
struct V_82 * V_83 = V_12 -> V_84 ;
while ( V_7 && F_35 ( V_83 ) ) {
V_67 V_85 ;
int V_86 ;
V_85 = F_36 ( V_83 ) ;
V_86 = F_35 ( V_83 ) ;
while ( V_86 ) {
if ( V_21 ++ >= V_61 ) {
F_9 ( V_74
L_20 ,
V_16 -> V_31 ) ;
return 0 ;
} else {
T_3 V_87 =
0x10000 - ( V_85 & 0xffff ) ;
if ( V_87 > V_86 )
V_87 = V_86 ;
* V_79 = 0x0 ;
V_79 ++ ;
* V_79 = F_37 ( V_85 ) ;
V_79 ++ ;
* V_79 = 0x0 ;
V_79 ++ ;
* V_79 = F_37 ( V_87 ) ;
V_79 ++ ;
V_85 += V_87 ;
V_86 -= V_87 ;
}
}
V_83 = F_38 ( V_83 ) ;
V_7 -- ;
}
if ( V_21 ) {
V_79 -- ;
* V_79 |= F_37 ( 0x80000000 ) ;
return V_21 ;
}
return 0 ;
}
static int F_39 ( T_2 * V_16 , struct V_49 * V_50 )
{
int V_88 ;
T_4 V_89 = ! ! ( V_50 -> V_90 & V_91 ) ;
if ( F_34 ( V_16 , V_50 ) == 0 )
return 1 ;
if ( V_89 )
V_88 = V_92 ;
else
V_88 = V_93 ;
F_32 ( V_88 , V_16 ) ;
return 0 ;
}
static int F_40 ( struct V_23 * V_24 )
{
unsigned long V_94 , V_95 ;
unsigned long V_96 , V_97 , V_98 ;
void V_15 * V_99 ;
struct V_1 V_2 , * V_100 [] = { & V_2 } ;
int V_101 ;
V_96 = F_25 ( V_24 , 0 ) ;
V_99 = F_41 ( V_24 , 0 ) ;
if ( V_99 == NULL ) {
F_9 ( V_29 L_21 ,
V_102 , V_96 ) ;
return - V_103 ;
}
V_94 = ( unsigned long ) V_99 + V_104 ;
V_98 = ( unsigned long ) V_99 + V_105 ;
V_95 = ( unsigned long ) V_99 + V_106 ;
V_97 = V_96 + V_104 ;
if ( F_26 ( V_97 , V_107 ,
V_102 ) == NULL ) {
F_9 ( V_29 L_22
L_11 , V_102 , F_42 ( V_24 ) ,
V_97 , V_97 + V_107 ) ;
V_101 = - V_108 ;
goto V_109;
}
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
F_1 ( & V_2 , V_94 , V_98 , V_95 ) ;
V_2 . V_110 = V_24 -> V_110 ;
V_2 . V_24 = & V_24 -> V_24 ;
F_11 ( 0x03 , ( void V_15 * ) ( V_95 + V_111 * 4 ) ) ;
V_101 = F_43 ( & V_112 , V_100 , 1 , NULL ) ;
if ( ! V_101 )
return 0 ;
F_31 ( V_97 , V_107 ) ;
V_109:
F_44 ( V_99 ) ;
return V_101 ;
}
static unsigned int F_45 ( struct V_23 * V_24 )
{
int V_113 ;
F_9 ( V_59 L_23 ,
V_102 , F_42 ( V_24 ) , V_24 -> V_114 ) ;
if ( V_24 -> V_114 < V_115 ) {
F_9 ( V_29 L_24
L_25
L_26 ,
V_102 , F_42 ( V_24 ) ) ;
V_113 = - V_116 ;
goto V_117;
}
V_113 = F_40 ( V_24 ) ;
V_117:
return V_113 ;
}
static int F_46 ( struct V_118 * V_119 )
{
if ( V_119 -> V_120 == V_121 )
return 0 ;
return F_45 ( V_119 -> V_122 ) ;
}
static int T_6 F_47 ( void )
{
return F_48 ( & V_123 ) ;
}
