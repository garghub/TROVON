static int F_1 ( T_1 * V_1 , T_2 V_2 , T_2 V_3 ,
T_2 V_4 , T_2 V_5 )
{
int V_6 = V_7 ;
T_2 V_8 ;
V_8 = F_2 ( V_1 , V_9 ) ;
while ( ( V_8 & V_10 ) && V_6 ) {
V_6 -- ;
F_3 ( 1 ) ;
V_8 = F_2 ( V_1 , V_9 ) ;
}
if ( V_8 & V_10 )
return - V_11 ;
F_4 ( V_1 , V_12 , V_5 ) ;
F_4 ( V_1 , V_13 , V_4 ) ;
F_4 ( V_1 , V_14 , V_3 ) ;
F_4 ( V_1 , V_9 , V_2 ) ;
return 0 ;
}
static int F_5 ( T_1 * V_1 , T_2 V_2 ,
T_2 V_15 , T_2 V_16 , T_2 V_17 ,
struct V_18 * V_19 )
{
int V_20 = 0 ;
int V_6 ;
T_2 V_21 , V_8 ;
V_20 = F_1 ( V_1 , V_2 , V_15 , V_16 , V_17 ) ;
if ( V_20 )
return V_20 ;
V_8 = F_2 ( V_1 , V_22 ) ;
V_6 = V_23 ;
while ( ( ! ( V_8 & V_24 ) ) && V_6 ) {
V_6 -- ;
F_3 ( 10 ) ;
V_8 = F_2 ( V_1 , V_22 ) ;
}
F_4 ( V_1 , V_25 , V_26 ) ;
if ( ! F_6 ( V_1 ) ) {
F_7 ( 0 , L_1 ,
V_1 -> V_27 ) ;
V_20 = - V_28 ;
goto V_29;
}
if ( ! ( V_8 & V_24 ) ) {
F_8 ( V_30 L_2
L_3 ,
V_1 -> V_27 , V_8 ) ;
V_20 = - V_31 ;
goto V_29;
}
V_21 = F_2 ( V_1 , V_32 ) ;
if ( V_19 ) {
V_19 -> V_21 = V_21 ;
V_19 -> V_33 = F_2 ( V_1 , V_34 ) ;
V_19 -> V_35 = F_2 ( V_1 , V_36 ) ;
V_19 -> V_37 = F_2 ( V_1 , V_38 ) ;
}
F_4 ( V_1 , V_39 , V_24 ) ;
if ( V_21 & V_40 )
V_20 = - V_41 ;
V_29:
return V_20 ;
}
void F_9 ( T_1 * V_1 , void T_3 * V_42 , int V_43 )
{
V_1 -> V_27 = V_42 ;
V_1 -> V_43 = V_43 ;
V_1 -> V_44 = 0x0 ;
V_1 -> V_45 = false ;
V_1 -> V_46 = & V_47 ;
}
static int F_10 ( T_1 * V_1 )
{
T_2 V_8 ;
int V_20 = 0 ;
int V_6 ;
V_1 -> V_44 = 0x0 ;
F_4 ( V_1 , V_48 , 0 ) ;
F_4 ( V_1 , V_39 , 0xffff ) ;
V_6 = V_7 ;
V_8 = F_2 ( V_1 , V_9 ) ;
while ( V_6 && ( V_8 & V_10 ) ) {
if ( V_8 == 0xffff )
return - V_28 ;
V_6 -- ;
F_3 ( 1 ) ;
V_8 = F_2 ( V_1 , V_9 ) ;
}
V_8 = F_2 ( V_1 , V_22 ) ;
F_4 ( V_1 , V_39 , V_8 ) ;
V_20 = F_5 ( V_1 , V_49 , 0 , 0 , 0 , NULL ) ;
return V_20 ;
}
static int F_11 ( T_1 * V_1 , T_2 V_2 , T_2 V_15 ,
struct V_18 * V_19 )
{
int V_20 ;
int V_6 ;
T_2 V_8 ;
T_2 V_21 ;
V_20 = F_1 ( V_1 , V_2 , V_15 , 0 , 0 ) ;
if ( V_20 ) {
if ( ! F_6 ( V_1 ) ) {
if ( F_12 () )
F_8 ( V_50 L_2
L_4
L_5 , V_1 -> V_27 , V_2 ) ;
V_20 = - V_28 ;
} else
if ( F_12 () )
F_8 ( V_30 L_2
L_6 ,
V_1 -> V_27 , V_20 , V_2 ) ;
goto V_29;
}
V_8 = F_2 ( V_1 , V_22 ) ;
V_6 = V_51 ;
while ( ( ! ( V_8 & V_24 ) ) && V_6 ) {
V_6 -- ;
F_3 ( 10 ) ;
V_8 = F_2 ( V_1 , V_22 ) ;
}
if ( ! F_6 ( V_1 ) ) {
F_8 ( V_50 L_7
L_8 ,
V_1 -> V_27 , V_2 ) ;
V_20 = - V_28 ;
goto V_29;
}
if ( ! ( V_8 & V_24 ) ) {
F_8 ( V_30 L_9
L_10 , V_1 -> V_27 , V_2 ) ;
V_20 = - V_31 ;
goto V_29;
}
V_21 = F_2 ( V_1 , V_32 ) ;
if ( V_19 ) {
V_19 -> V_21 = V_21 ;
V_19 -> V_33 = F_2 ( V_1 , V_34 ) ;
V_19 -> V_35 = F_2 ( V_1 , V_36 ) ;
V_19 -> V_37 = F_2 ( V_1 , V_38 ) ;
}
F_4 ( V_1 , V_39 , V_24 ) ;
if ( V_21 & V_40 )
V_20 = - V_41 ;
V_29:
return V_20 ;
}
static int F_13 ( T_1 * V_1 , T_2 V_52 , T_2 * V_53 )
{
int V_20 = 0 ;
int V_6 ;
T_2 V_8 ;
if ( ( V_52 < V_54 ) || ( V_52 > V_55 ) )
return - V_56 ;
V_20 = F_11 ( V_1 , V_57 , V_52 , NULL ) ;
if ( V_20 )
return V_20 ;
V_8 = F_2 ( V_1 , V_22 ) ;
V_6 = V_58 ;
while ( ( ! ( V_8 & V_59 ) ) && V_6 ) {
V_6 -- ;
F_3 ( 10 ) ;
V_8 = F_2 ( V_1 , V_22 ) ;
}
if ( ! F_6 ( V_1 ) ) {
F_8 ( V_50 L_2
L_11 ,
V_1 -> V_27 ) ;
return - V_28 ;
}
if ( ! ( V_8 & V_59 ) ) {
F_8 ( V_30 L_2
L_12 ,
V_1 -> V_27 ) ;
return - V_31 ;
}
* V_53 = F_2 ( V_1 , V_60 ) ;
F_4 ( V_1 , V_39 , V_59 ) ;
return 0 ;
}
static int F_14 ( T_1 * V_1 , int V_61 , T_2 V_62 , T_2 V_63 )
{
int V_64 = V_61 ? V_65 : V_66 ;
int V_67 = V_61 ? V_68 : V_69 ;
int V_6 ;
T_2 V_8 ;
if ( ( V_63 > V_70 ) || ( V_63 % 2 ) )
return - V_56 ;
V_6 = V_71 ;
V_8 = F_15 ( V_1 , V_67 ) ;
while ( ( V_8 & V_72 ) && V_6 ) {
V_6 -- ;
F_3 ( 1 ) ;
V_8 = F_15 ( V_1 , V_67 ) ;
}
if ( V_8 & V_72 )
return - V_31 ;
F_16 ( V_1 , V_64 , V_62 ) ;
F_16 ( V_1 , V_67 , V_63 ) ;
V_6 = V_71 ;
V_8 = F_15 ( V_1 , V_67 ) ;
while ( ( V_8 & ( V_72 | V_73 ) ) && V_6 ) {
V_6 -- ;
F_3 ( 1 ) ;
V_8 = F_15 ( V_1 , V_67 ) ;
}
if ( V_8 != V_63 ) {
F_8 ( V_30 L_13
L_14 , V_1 -> V_27 , V_61 ,
( V_8 & V_72 ) ? L_15 : L_16 ,
V_8 , V_62 , V_63 ) ;
if ( V_8 & V_72 )
return - V_31 ;
return - V_41 ;
}
return 0 ;
}
static int F_17 ( T_1 * V_1 , int V_61 , void * V_74 , int V_75 ,
T_2 V_62 , T_2 V_63 )
{
int V_76 = V_61 ? V_77 : V_78 ;
int V_20 = 0 ;
if ( ( V_75 < 0 ) || ( V_75 % 2 ) )
return - V_56 ;
V_20 = F_14 ( V_1 , V_61 , V_62 , V_63 ) ;
if ( V_20 )
goto V_29;
F_18 ( V_1 , V_76 , V_74 , V_75 / 2 ) ;
V_29:
return V_20 ;
}
static int F_19 ( T_1 * V_1 , int V_61 , const void * V_74 , int V_75 ,
T_2 V_62 , T_2 V_63 )
{
int V_76 = V_61 ? V_77 : V_78 ;
int V_20 = 0 ;
if ( V_75 < 0 )
return - V_56 ;
V_20 = F_14 ( V_1 , V_61 , V_62 , V_63 ) ;
if ( V_20 )
goto V_29;
F_20 ( V_1 , V_76 , V_74 , V_75 ) ;
V_29:
return V_20 ;
}
static int F_21 ( T_1 * V_1 , int V_61 , T_2 V_79 , unsigned V_80 ,
T_2 * V_81 , void * V_74 )
{
int V_20 = 0 ;
int V_76 = V_61 ? V_77 : V_78 ;
T_2 V_82 , V_83 ;
unsigned V_84 ;
if ( V_80 % 2 )
return - V_56 ;
V_20 = F_11 ( V_1 , V_85 , V_79 , NULL ) ;
if ( V_20 )
return V_20 ;
V_20 = F_14 ( V_1 , V_61 , V_79 , 0 ) ;
if ( V_20 )
return V_20 ;
V_82 = F_15 ( V_1 , V_76 ) ;
if ( ! V_82 )
return - V_86 ;
V_83 = F_15 ( V_1 , V_76 ) ;
if ( V_81 )
* V_81 = V_82 ;
if ( V_83 != V_79 )
F_8 ( V_50 L_17
L_18 ,
V_1 -> V_27 , V_87 , V_79 , V_83 ) ;
if ( F_22 ( V_82 ) > V_80 )
F_8 ( V_50 L_2
L_19
L_20 , V_1 -> V_27 ,
F_22 ( V_82 ) , V_80 , V_79 , V_82 ) ;
V_84 = F_23 ( ( unsigned ) V_82 - 1 , V_80 / 2 ) ;
F_18 ( V_1 , V_76 , V_74 , V_84 ) ;
return 0 ;
}
static int F_24 ( T_1 * V_1 , int V_61 , T_2 V_79 ,
T_2 V_81 , const void * V_88 )
{
int V_76 = V_61 ? V_77 : V_78 ;
int V_20 = 0 ;
unsigned V_89 ;
if ( V_81 == 0 )
return - V_56 ;
V_20 = F_14 ( V_1 , V_61 , V_79 , 0 ) ;
if ( V_20 )
return V_20 ;
F_16 ( V_1 , V_76 , V_81 ) ;
F_16 ( V_1 , V_76 , V_79 ) ;
V_89 = V_81 - 1 ;
F_20 ( V_1 , V_76 , V_88 , V_89 << 1 ) ;
V_20 = F_11 ( V_1 , V_85 | V_90 ,
V_79 , NULL ) ;
return V_20 ;
}
static inline void
F_25 ( T_1 * V_1 , T_4 V_91 )
{
F_16 ( V_1 , V_92 , ( T_2 ) ( V_91 >> 7 ) ) ;
F_16 ( V_1 , V_93 , ( T_2 ) ( V_91 & 0x7F ) ) ;
}
static inline int
F_26 ( T_1 * V_1 , int V_94 )
{
int V_95 = V_94 ? V_96 : V_97 ;
int V_98 = V_94 ? V_99 : V_100 ;
int V_101 ;
if ( F_15 ( V_1 , V_102 ) == V_95 )
return 0 ;
F_16 ( V_1 , V_103 , V_104 ) ;
F_16 ( V_1 , V_105 , V_106 ) ;
F_16 ( V_1 , V_107 , V_108 ) ;
F_16 ( V_1 , V_102 , V_98 ) ;
for ( V_101 = 0 ; V_101 < 20 ; V_101 ++ ) {
F_3 ( 10 ) ;
if ( F_15 ( V_1 , V_102 ) ==
V_95 )
return 0 ;
}
return - V_11 ;
}
static int F_27 ( T_1 * V_1 , T_4 V_63 )
{
int V_20 ;
F_4 ( V_1 , V_39 , 0xFFFF ) ;
V_20 = V_1 -> V_46 -> V_109 ( V_1 ,
0x0100 | V_49 ,
0 , 0 , 0 , NULL ) ;
if ( V_20 )
return V_20 ;
V_20 = V_1 -> V_46 -> V_109 ( V_1 ,
0x0000 | V_49 ,
0 , 0 , 0 , NULL ) ;
if ( V_20 )
return V_20 ;
V_20 = F_26 ( V_1 , 1 ) ;
F_28 ( L_21 , V_20 ) ;
if ( V_20 )
return V_20 ;
F_28 ( L_22 , V_63 ) ;
V_20 = V_1 -> V_46 -> V_109 ( V_1 ,
V_110 ,
V_63 & 0xFFFFu ,
V_63 >> 16 ,
0 ,
NULL ) ;
F_28 ( L_23 , V_20 ) ;
return V_20 ;
}
static int F_29 ( T_1 * V_1 )
{
struct V_18 V_19 ;
int V_111 = 0 ;
int V_20 ;
V_111 = V_1 -> V_46 -> V_112 ( V_1 , V_113 , 0 , & V_19 ) ;
F_28 ( L_24
L_25 ,
V_111 , V_19 . V_33 , V_19 . V_35 , V_19 . V_37 ) ;
if ( ( V_111 == 0 ) &&
( ( V_19 . V_21 & V_114 ) != V_115 ) )
V_111 = - V_41 ;
V_20 = F_26 ( V_1 , 0 ) ;
F_28 ( L_26 , V_20 ) ;
F_4 ( V_1 , V_39 , 0xFFFF ) ;
( void ) V_1 -> V_46 -> V_109 ( V_1 , 0x0000 | V_49 ,
0 , 0 , 0 , NULL ) ;
return V_111 ? V_111 : V_20 ;
}
static int F_30 ( struct V_116 * V_1 , const char * V_117 ,
T_4 V_91 , T_4 V_75 )
{
F_25 ( V_1 , V_91 ) ;
F_20 ( V_1 , V_118 , V_117 , V_75 ) ;
return 0 ;
}
static int F_31 ( T_1 * V_1 , T_5 * V_119 , T_4 V_120 , T_2 V_121 )
{
int V_122 ;
T_2 V_123 ;
T_2 V_124 = V_121 ;
T_5 * V_117 = V_119 ;
if ( V_1 -> V_45 ) {
V_122 = V_1 -> V_46 -> V_112 ( V_1 , V_125 , 0 , NULL ) ;
if ( V_122 )
return V_122 ;
} else {
V_119 [ 0 ] = F_32 ( V_121 - 2 ) ;
V_119 [ 1 ] = F_32 ( 0x0800 ) ;
V_124 = V_121 - 4 ;
V_117 = V_119 + 2 ;
}
V_122 = F_26 ( V_1 , 1 ) ;
F_28 ( L_21 , V_122 ) ;
if ( V_122 )
return V_122 ;
F_25 ( V_1 , V_120 ) ;
F_18 ( V_1 , V_118 , V_117 , V_124 / 2 ) ;
V_122 = F_26 ( V_1 , 0 ) ;
F_28 ( L_26 , V_122 ) ;
V_123 = F_33 ( V_119 [ 0 ] ) ;
F_28 ( L_27 ,
V_123 , V_121 ) ;
if ( V_123 > V_121 )
return - V_56 ;
return 0 ;
}
static void F_34 ( T_6 * V_126 ,
unsigned long * V_127 ) __acquires( V_126 )
{
F_35 ( V_126 , * V_127 ) ;
}
static void F_36 ( T_6 * V_126 ,
unsigned long * V_127 ) __releases( V_126 )
{
F_37 ( V_126 , * V_127 ) ;
}
static void F_38 ( T_6 * V_126 ) __acquires( V_126 )
{
F_39 ( V_126 ) ;
}
static void F_40 ( T_6 * V_126 ) __releases( V_126 )
{
F_41 ( V_126 ) ;
}
