static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 , T_1 V_6 )
{
int V_7 = V_8 ;
T_1 V_9 ;
V_9 = F_2 ( V_2 , V_10 ) ;
while ( ( V_9 & V_11 ) && V_7 ) {
V_7 -- ;
F_3 ( 1 ) ;
V_9 = F_2 ( V_2 , V_10 ) ;
}
if ( V_9 & V_11 )
return - V_12 ;
F_4 ( V_2 , V_13 , V_6 ) ;
F_4 ( V_2 , V_14 , V_5 ) ;
F_4 ( V_2 , V_15 , V_4 ) ;
F_4 ( V_2 , V_10 , V_3 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_16 , T_1 V_17 , T_1 V_18 ,
struct V_19 * V_20 )
{
int V_21 = 0 ;
int V_7 ;
T_1 V_22 , V_9 ;
V_21 = F_1 ( V_2 , V_3 , V_16 , V_17 , V_18 ) ;
if ( V_21 )
return V_21 ;
V_9 = F_2 ( V_2 , V_23 ) ;
V_7 = V_24 ;
while ( ( ! ( V_9 & V_25 ) ) && V_7 ) {
V_7 -- ;
F_3 ( 10 ) ;
V_9 = F_2 ( V_2 , V_23 ) ;
}
F_4 ( V_2 , V_26 , V_27 ) ;
if ( ! F_6 ( V_2 ) ) {
F_7 ( 0 , L_1 ,
V_2 -> V_28 ) ;
V_21 = - V_29 ;
goto V_30;
}
if ( ! ( V_9 & V_25 ) ) {
F_8 ( V_31 L_2
L_3 ,
V_2 -> V_28 , V_9 ) ;
V_21 = - V_32 ;
goto V_30;
}
V_22 = F_2 ( V_2 , V_33 ) ;
if ( V_20 ) {
V_20 -> V_22 = V_22 ;
V_20 -> V_34 = F_2 ( V_2 , V_35 ) ;
V_20 -> V_36 = F_2 ( V_2 , V_37 ) ;
V_20 -> V_38 = F_2 ( V_2 , V_39 ) ;
}
F_4 ( V_2 , V_40 , V_25 ) ;
if ( V_22 & V_41 )
V_21 = - V_42 ;
V_30:
return V_21 ;
}
void F_9 ( struct V_1 * V_2 , void T_2 * V_43 ,
int V_44 )
{
V_2 -> V_28 = V_43 ;
V_2 -> V_44 = V_44 ;
V_2 -> V_45 = 0x0 ;
V_2 -> V_46 = false ;
V_2 -> V_47 = & V_48 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_9 ;
int V_21 = 0 ;
int V_7 ;
V_2 -> V_45 = 0x0 ;
F_4 ( V_2 , V_49 , 0 ) ;
F_4 ( V_2 , V_40 , 0xffff ) ;
V_7 = V_8 ;
V_9 = F_2 ( V_2 , V_10 ) ;
while ( V_7 && ( V_9 & V_11 ) ) {
if ( V_9 == 0xffff )
return - V_29 ;
V_7 -- ;
F_3 ( 1 ) ;
V_9 = F_2 ( V_2 , V_10 ) ;
}
V_9 = F_2 ( V_2 , V_23 ) ;
F_4 ( V_2 , V_40 , V_9 ) ;
V_21 = F_5 ( V_2 , V_50 , 0 , 0 , 0 , NULL ) ;
return V_21 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_16 ,
struct V_19 * V_20 )
{
int V_21 ;
int V_7 ;
T_1 V_9 ;
T_1 V_22 ;
V_21 = F_1 ( V_2 , V_3 , V_16 , 0 , 0 ) ;
if ( V_21 ) {
if ( ! F_6 ( V_2 ) ) {
if ( F_12 () )
F_8 ( V_51 L_2
L_4
L_5 , V_2 -> V_28 , V_3 ) ;
V_21 = - V_29 ;
} else
if ( F_12 () )
F_8 ( V_31 L_2
L_6 ,
V_2 -> V_28 , V_21 , V_3 ) ;
goto V_30;
}
V_9 = F_2 ( V_2 , V_23 ) ;
V_7 = V_52 ;
while ( ( ! ( V_9 & V_25 ) ) && V_7 ) {
V_7 -- ;
F_3 ( 10 ) ;
V_9 = F_2 ( V_2 , V_23 ) ;
}
if ( ! F_6 ( V_2 ) ) {
F_8 ( V_51 L_7
L_8 ,
V_2 -> V_28 , V_3 ) ;
V_21 = - V_29 ;
goto V_30;
}
if ( ! ( V_9 & V_25 ) ) {
F_8 ( V_31 L_9
L_10 , V_2 -> V_28 , V_3 ) ;
V_21 = - V_32 ;
goto V_30;
}
V_22 = F_2 ( V_2 , V_33 ) ;
if ( V_20 ) {
V_20 -> V_22 = V_22 ;
V_20 -> V_34 = F_2 ( V_2 , V_35 ) ;
V_20 -> V_36 = F_2 ( V_2 , V_37 ) ;
V_20 -> V_38 = F_2 ( V_2 , V_39 ) ;
}
F_4 ( V_2 , V_40 , V_25 ) ;
if ( V_22 & V_41 )
V_21 = - V_42 ;
V_30:
return V_21 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_53 , T_1 * V_54 )
{
int V_21 = 0 ;
int V_7 ;
T_1 V_9 ;
if ( ( V_53 < V_55 ) || ( V_53 > V_56 ) )
return - V_57 ;
V_21 = F_11 ( V_2 , V_58 , V_53 , NULL ) ;
if ( V_21 )
return V_21 ;
V_9 = F_2 ( V_2 , V_23 ) ;
V_7 = V_59 ;
while ( ( ! ( V_9 & V_60 ) ) && V_7 ) {
V_7 -- ;
F_3 ( 10 ) ;
V_9 = F_2 ( V_2 , V_23 ) ;
}
if ( ! F_6 ( V_2 ) ) {
F_8 ( V_51 L_2
L_11 ,
V_2 -> V_28 ) ;
return - V_29 ;
}
if ( ! ( V_9 & V_60 ) ) {
F_8 ( V_31 L_2
L_12 ,
V_2 -> V_28 ) ;
return - V_32 ;
}
* V_54 = F_2 ( V_2 , V_61 ) ;
F_4 ( V_2 , V_40 , V_60 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_62 , T_1 V_63 , T_1 V_64 )
{
int V_65 = V_62 ? V_66 : V_67 ;
int V_68 = V_62 ? V_69 : V_70 ;
int V_7 ;
T_1 V_9 ;
if ( ( V_64 > V_71 ) || ( V_64 % 2 ) )
return - V_57 ;
V_7 = V_72 ;
V_9 = F_15 ( V_2 , V_68 ) ;
while ( ( V_9 & V_73 ) && V_7 ) {
V_7 -- ;
F_3 ( 1 ) ;
V_9 = F_15 ( V_2 , V_68 ) ;
}
if ( V_9 & V_73 )
return - V_32 ;
F_16 ( V_2 , V_65 , V_63 ) ;
F_16 ( V_2 , V_68 , V_64 ) ;
V_7 = V_72 ;
V_9 = F_15 ( V_2 , V_68 ) ;
while ( ( V_9 & ( V_73 | V_74 ) ) && V_7 ) {
V_7 -- ;
F_3 ( 1 ) ;
V_9 = F_15 ( V_2 , V_68 ) ;
}
if ( V_9 != V_64 ) {
F_8 ( V_31 L_13
L_14 , V_2 -> V_28 , V_62 ,
( V_9 & V_73 ) ? L_15 : L_16 ,
V_9 , V_63 , V_64 ) ;
if ( V_9 & V_73 )
return - V_32 ;
return - V_42 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_62 , void * V_75 , int V_76 ,
T_1 V_63 , T_1 V_64 )
{
int V_77 = V_62 ? V_78 : V_79 ;
int V_21 = 0 ;
if ( ( V_76 < 0 ) || ( V_76 % 2 ) )
return - V_57 ;
V_21 = F_14 ( V_2 , V_62 , V_63 , V_64 ) ;
if ( V_21 )
goto V_30;
F_18 ( V_2 , V_77 , V_75 , V_76 / 2 ) ;
V_30:
return V_21 ;
}
static int F_19 ( struct V_1 * V_2 , int V_62 , const void * V_75 ,
int V_76 , T_1 V_63 , T_1 V_64 )
{
int V_77 = V_62 ? V_78 : V_79 ;
int V_21 = 0 ;
if ( V_76 < 0 )
return - V_57 ;
V_21 = F_14 ( V_2 , V_62 , V_63 , V_64 ) ;
if ( V_21 )
goto V_30;
F_20 ( V_2 , V_77 , V_75 , V_76 ) ;
V_30:
return V_21 ;
}
static int F_21 ( struct V_1 * V_2 , int V_62 , T_1 V_80 ,
unsigned V_81 , T_1 * V_82 , void * V_75 )
{
int V_21 = 0 ;
int V_77 = V_62 ? V_78 : V_79 ;
T_1 V_83 , V_84 ;
unsigned V_85 ;
if ( V_81 % 2 )
return - V_57 ;
V_21 = F_11 ( V_2 , V_86 , V_80 , NULL ) ;
if ( V_21 )
return V_21 ;
V_21 = F_14 ( V_2 , V_62 , V_80 , 0 ) ;
if ( V_21 )
return V_21 ;
V_83 = F_15 ( V_2 , V_77 ) ;
if ( ! V_83 )
return - V_87 ;
V_84 = F_15 ( V_2 , V_77 ) ;
if ( V_82 )
* V_82 = V_83 ;
if ( V_84 != V_80 )
F_8 ( V_51 L_17
L_18 ,
V_2 -> V_28 , V_88 , V_80 , V_84 ) ;
if ( F_22 ( V_83 ) > V_81 )
F_8 ( V_51 L_2
L_19
L_20 , V_2 -> V_28 ,
F_22 ( V_83 ) , V_81 , V_80 , V_83 ) ;
V_85 = F_23 ( ( unsigned ) V_83 - 1 , V_81 / 2 ) ;
F_18 ( V_2 , V_77 , V_75 , V_85 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_62 , T_1 V_80 ,
T_1 V_82 , const void * V_89 )
{
int V_77 = V_62 ? V_78 : V_79 ;
int V_21 = 0 ;
unsigned V_90 ;
if ( V_82 == 0 )
return - V_57 ;
V_21 = F_14 ( V_2 , V_62 , V_80 , 0 ) ;
if ( V_21 )
return V_21 ;
F_16 ( V_2 , V_77 , V_82 ) ;
F_16 ( V_2 , V_77 , V_80 ) ;
V_90 = V_82 - 1 ;
F_20 ( V_2 , V_77 , V_89 , V_90 << 1 ) ;
V_21 = F_11 ( V_2 , V_86 | V_91 ,
V_80 , NULL ) ;
return V_21 ;
}
static inline void
F_25 ( struct V_1 * V_2 , T_3 V_92 )
{
F_16 ( V_2 , V_93 , ( T_1 ) ( V_92 >> 7 ) ) ;
F_16 ( V_2 , V_94 , ( T_1 ) ( V_92 & 0x7F ) ) ;
}
static inline int
F_26 ( struct V_1 * V_2 , int V_95 )
{
int V_96 = V_95 ? V_97 : V_98 ;
int V_99 = V_95 ? V_100 : V_101 ;
int V_102 ;
if ( F_15 ( V_2 , V_103 ) == V_96 )
return 0 ;
F_16 ( V_2 , V_104 , V_105 ) ;
F_16 ( V_2 , V_106 , V_107 ) ;
F_16 ( V_2 , V_108 , V_109 ) ;
F_16 ( V_2 , V_103 , V_99 ) ;
for ( V_102 = 0 ; V_102 < 20 ; V_102 ++ ) {
F_3 ( 10 ) ;
if ( F_15 ( V_2 , V_103 ) ==
V_96 )
return 0 ;
}
return - V_12 ;
}
static int F_27 ( struct V_1 * V_2 , T_3 V_64 )
{
int V_21 ;
F_4 ( V_2 , V_40 , 0xFFFF ) ;
V_21 = V_2 -> V_47 -> V_110 ( V_2 ,
0x0100 | V_50 ,
0 , 0 , 0 , NULL ) ;
if ( V_21 )
return V_21 ;
V_21 = V_2 -> V_47 -> V_110 ( V_2 ,
0x0000 | V_50 ,
0 , 0 , 0 , NULL ) ;
if ( V_21 )
return V_21 ;
V_21 = F_26 ( V_2 , 1 ) ;
F_28 ( L_21 , V_21 ) ;
if ( V_21 )
return V_21 ;
F_28 ( L_22 , V_64 ) ;
V_21 = V_2 -> V_47 -> V_110 ( V_2 ,
V_111 ,
V_64 & 0xFFFFu ,
V_64 >> 16 ,
0 ,
NULL ) ;
F_28 ( L_23 , V_21 ) ;
return V_21 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_19 V_20 ;
int V_112 = 0 ;
int V_21 ;
V_112 = V_2 -> V_47 -> V_113 ( V_2 , V_114 , 0 , & V_20 ) ;
F_28 ( L_24
L_25 ,
V_112 , V_20 . V_34 , V_20 . V_36 , V_20 . V_38 ) ;
if ( ( V_112 == 0 ) &&
( ( V_20 . V_22 & V_115 ) != V_116 ) )
V_112 = - V_42 ;
V_21 = F_26 ( V_2 , 0 ) ;
F_28 ( L_26 , V_21 ) ;
F_4 ( V_2 , V_40 , 0xFFFF ) ;
( void ) V_2 -> V_47 -> V_110 ( V_2 , 0x0000 | V_50 ,
0 , 0 , 0 , NULL ) ;
return V_112 ? V_112 : V_21 ;
}
static int F_30 ( struct V_1 * V_2 , const char * V_117 ,
T_3 V_92 , T_3 V_76 )
{
F_25 ( V_2 , V_92 ) ;
F_20 ( V_2 , V_118 , V_117 , V_76 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , T_4 * V_119 , T_3 V_120 ,
T_1 V_121 )
{
int V_122 ;
T_1 V_123 ;
T_1 V_124 = V_121 ;
T_4 * V_117 = V_119 ;
if ( V_2 -> V_46 ) {
V_122 = V_2 -> V_47 -> V_113 ( V_2 , V_125 , 0 , NULL ) ;
if ( V_122 )
return V_122 ;
} else {
V_119 [ 0 ] = F_32 ( V_121 - 2 ) ;
V_119 [ 1 ] = F_32 ( 0x0800 ) ;
V_124 = V_121 - 4 ;
V_117 = V_119 + 2 ;
}
V_122 = F_26 ( V_2 , 1 ) ;
F_28 ( L_21 , V_122 ) ;
if ( V_122 )
return V_122 ;
F_25 ( V_2 , V_120 ) ;
F_18 ( V_2 , V_118 , V_117 , V_124 / 2 ) ;
V_122 = F_26 ( V_2 , 0 ) ;
F_28 ( L_26 , V_122 ) ;
V_123 = F_33 ( V_119 [ 0 ] ) ;
F_28 ( L_27 ,
V_123 , V_121 ) ;
if ( V_123 > V_121 )
return - V_57 ;
return 0 ;
}
static void F_34 ( T_5 * V_126 ,
unsigned long * V_127 ) __acquires( V_126 )
{
F_35 ( V_126 , * V_127 ) ;
}
static void F_36 ( T_5 * V_126 ,
unsigned long * V_127 ) __releases( V_126 )
{
F_37 ( V_126 , * V_127 ) ;
}
static void F_38 ( T_5 * V_126 ) __acquires( V_126 )
{
F_39 ( V_126 ) ;
}
static void F_40 ( T_5 * V_126 ) __releases( V_126 )
{
F_41 ( V_126 ) ;
}
