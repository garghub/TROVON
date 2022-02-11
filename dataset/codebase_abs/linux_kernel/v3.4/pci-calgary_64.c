static inline int F_1 ( struct V_1 * V_2 )
{
return ( V_2 != NULL ) ;
}
static void F_2 ( struct V_1 * V_2 ,
unsigned long V_3 , unsigned int V_4 )
{
unsigned long V_5 ;
unsigned long V_6 ;
unsigned long V_7 ;
V_5 = V_3 >> V_8 ;
if ( V_5 >= V_2 -> V_9 )
return;
V_6 = V_5 + V_4 ;
if ( V_6 > V_2 -> V_9 )
V_6 = V_2 -> V_9 ;
F_3 ( & V_2 -> V_10 , V_7 ) ;
F_4 ( V_2 -> V_11 , V_5 , V_4 ) ;
F_5 ( & V_2 -> V_10 , V_7 ) ;
}
static unsigned long F_6 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
unsigned int V_4 )
{
unsigned long V_7 ;
unsigned long V_14 ;
unsigned long V_15 ;
V_15 = F_7 ( F_8 ( V_13 ) + 1 ,
V_16 ) >> V_8 ;
F_9 ( V_4 == 0 ) ;
F_3 ( & V_2 -> V_10 , V_7 ) ;
V_14 = F_10 ( V_2 -> V_11 , V_2 -> V_9 , V_2 -> V_17 ,
V_4 , 0 , V_15 , 0 ) ;
if ( V_14 == ~ 0UL ) {
V_2 -> V_18 -> V_19 ( V_2 ) ;
V_14 = F_10 ( V_2 -> V_11 , V_2 -> V_9 , 0 ,
V_4 , 0 , V_15 , 0 ) ;
if ( V_14 == ~ 0UL ) {
F_11 ( V_20 L_1 ) ;
F_5 ( & V_2 -> V_10 , V_7 ) ;
if ( V_21 )
F_12 ( L_2 ) ;
else
return V_22 ;
}
}
V_2 -> V_17 = V_14 + V_4 ;
F_9 ( V_2 -> V_17 > V_2 -> V_9 ) ;
F_5 ( & V_2 -> V_10 , V_7 ) ;
return V_14 ;
}
static T_1 F_13 ( struct V_12 * V_13 , struct V_1 * V_2 ,
void * V_23 , unsigned int V_4 , int V_24 )
{
unsigned long V_25 ;
T_1 V_26 ;
V_25 = F_6 ( V_13 , V_2 , V_4 ) ;
if ( F_14 ( V_25 == V_22 ) ) {
F_11 ( V_20 L_3
L_4 , V_4 , V_2 ) ;
return V_22 ;
}
V_26 = ( V_25 << V_8 ) | ( ( unsigned long ) V_23 & ~ V_27 ) ;
F_15 ( V_2 , V_25 , V_4 , ( unsigned long ) V_23 & V_27 ,
V_24 ) ;
return V_26 ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_28 ,
unsigned int V_4 )
{
unsigned long V_25 ;
unsigned long V_29 ;
unsigned long V_7 ;
V_29 = V_22 + ( V_30 * V_16 ) ;
if ( F_14 ( ( V_28 >= V_22 ) && ( V_28 < V_29 ) ) ) {
F_17 ( 1 , V_31 L_5
L_6 , V_28 ) ;
return;
}
V_25 = V_28 >> V_8 ;
F_9 ( V_25 + V_4 > V_2 -> V_9 ) ;
F_18 ( V_2 , V_25 , V_4 ) ;
F_3 ( & V_2 -> V_10 , V_7 ) ;
F_19 ( V_2 -> V_11 , V_25 , V_4 ) ;
F_5 ( & V_2 -> V_10 , V_7 ) ;
}
static inline struct V_1 * F_20 ( struct V_12 * V_13 )
{
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_1 * V_2 ;
V_33 = F_21 ( V_13 ) ;
V_35 = V_33 -> V_36 ;
do {
V_2 = F_22 ( V_35 ) ;
if ( V_2 && V_2 -> V_37 == V_35 -> V_38 )
break;
V_2 = NULL ;
V_35 = V_35 -> V_39 ;
} while ( V_35 );
F_9 ( V_2 && ( V_2 -> V_37 != V_35 -> V_38 ) ) ;
return V_2 ;
}
static void F_23 ( struct V_12 * V_13 , struct V_40 * V_41 ,
int V_42 , enum V_43 V_44 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 = F_20 ( V_13 ) ;
struct V_40 * V_47 ;
int V_48 ;
if ( ! F_1 ( V_2 ) )
return;
F_24 (sglist, s, nelems, i) {
unsigned int V_4 ;
T_1 V_49 = V_47 -> V_50 ;
unsigned int V_51 = V_47 -> V_52 ;
if ( V_51 == 0 )
break;
V_4 = F_25 ( V_49 , V_51 , V_16 ) ;
F_16 ( V_2 , V_49 , V_4 ) ;
}
}
static int F_26 ( struct V_12 * V_13 , struct V_40 * V_53 ,
int V_42 , enum V_43 V_44 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 = F_20 ( V_13 ) ;
struct V_40 * V_47 ;
unsigned long V_23 ;
unsigned int V_4 ;
unsigned long V_25 ;
int V_48 ;
F_24 (sg, s, nelems, i) {
F_9 ( ! F_27 ( V_47 ) ) ;
V_23 = ( unsigned long ) F_28 ( V_47 ) ;
V_4 = F_25 ( V_23 , V_47 -> V_54 , V_16 ) ;
V_25 = F_6 ( V_13 , V_2 , V_4 ) ;
if ( V_25 == V_22 ) {
V_47 -> V_52 = 0 ;
goto error;
}
V_47 -> V_50 = ( V_25 << V_8 ) | V_47 -> V_14 ;
F_15 ( V_2 , V_25 , V_4 , V_23 & V_27 , V_44 ) ;
V_47 -> V_52 = V_47 -> V_54 ;
}
return V_42 ;
error:
F_23 ( V_13 , V_53 , V_42 , V_44 , NULL ) ;
F_24 (sg, s, nelems, i) {
V_53 -> V_50 = V_22 ;
V_53 -> V_52 = 0 ;
}
return 0 ;
}
static T_1 F_29 ( struct V_12 * V_13 , struct V_55 * V_55 ,
unsigned long V_14 , T_2 V_56 ,
enum V_43 V_44 ,
struct V_45 * V_46 )
{
void * V_23 = F_30 ( V_55 ) + V_14 ;
unsigned long V_57 ;
unsigned int V_4 ;
struct V_1 * V_2 = F_20 ( V_13 ) ;
V_57 = ( unsigned long ) V_23 ;
V_4 = F_25 ( V_57 , V_56 , V_16 ) ;
return F_13 ( V_13 , V_2 , V_23 , V_4 , V_44 ) ;
}
static void F_31 ( struct V_12 * V_13 , T_1 V_28 ,
T_2 V_56 , enum V_43 V_44 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 = F_20 ( V_13 ) ;
unsigned int V_4 ;
V_4 = F_25 ( V_28 , V_56 , V_16 ) ;
F_16 ( V_2 , V_28 , V_4 ) ;
}
static void * F_32 ( struct V_12 * V_13 , T_2 V_56 ,
T_1 * V_58 , T_3 V_59 , struct V_45 * V_46 )
{
void * V_26 = NULL ;
T_1 V_60 ;
unsigned int V_4 , V_61 ;
struct V_1 * V_2 = F_20 ( V_13 ) ;
V_56 = F_33 ( V_56 ) ;
V_4 = V_56 >> V_8 ;
V_61 = F_34 ( V_56 ) ;
V_59 &= ~ ( V_62 | V_63 | V_64 ) ;
V_26 = ( void * ) F_35 ( V_59 , V_61 ) ;
if ( ! V_26 )
goto error;
memset ( V_26 , 0 , V_56 ) ;
V_60 = F_13 ( V_13 , V_2 , V_26 , V_4 , V_65 ) ;
if ( V_60 == V_22 )
goto free;
* V_58 = V_60 ;
return V_26 ;
free:
F_36 ( ( unsigned long ) V_26 , F_34 ( V_56 ) ) ;
V_26 = NULL ;
error:
return V_26 ;
}
static void F_37 ( struct V_12 * V_13 , T_2 V_56 ,
void * V_23 , T_1 V_58 ,
struct V_45 * V_46 )
{
unsigned int V_4 ;
struct V_1 * V_2 = F_20 ( V_13 ) ;
V_56 = F_33 ( V_56 ) ;
V_4 = V_56 >> V_8 ;
F_16 ( V_2 , V_58 , V_4 ) ;
F_36 ( ( unsigned long ) V_23 , F_34 ( V_56 ) ) ;
}
static inline void T_4 * F_38 ( unsigned char V_66 )
{
return V_67 [ V_66 ] . V_68 ;
}
static inline int F_39 ( unsigned char V_66 )
{
return V_67 [ V_66 ] . V_69 ;
}
static inline unsigned long F_40 ( unsigned char V_66 )
{
T_2 V_70 = F_39 ( V_66 ) ;
return V_71 [ V_70 ] ;
}
static inline unsigned long F_41 ( unsigned char V_66 )
{
T_2 V_70 = F_39 ( V_66 ) ;
return V_72 [ V_70 ] ;
}
static inline unsigned long F_42 ( unsigned char V_66 )
{
T_2 V_70 = F_39 ( V_66 ) ;
return V_73 [ V_70 ] ;
}
static inline void T_4 * F_43 ( void T_4 * V_74 , unsigned long V_14 )
{
unsigned long V_75 = ( ( unsigned long ) V_74 ) | V_14 ;
return ( void T_4 * ) V_75 ;
}
static inline int F_44 ( unsigned short V_12 )
{
return ( V_12 == V_76 ) ;
}
static inline int F_45 ( unsigned short V_12 )
{
return ( V_12 == V_77 ) ;
}
static inline int F_46 ( unsigned short V_12 )
{
return ( F_45 ( V_12 ) || F_44 ( V_12 ) ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
T_5 V_78 ;
T_6 V_79 ;
int V_48 = 0 ;
void T_4 * V_68 = V_2 -> V_68 ;
void T_4 * V_75 ;
V_75 = F_43 ( V_68 , F_42 ( V_2 -> V_37 ) | V_80 ) ;
V_79 = F_48 ( V_75 ) ;
F_49 ( 0 , V_75 ) ;
V_75 = F_43 ( V_68 , F_42 ( V_2 -> V_37 ) | V_81 ) ;
V_78 = F_48 ( V_75 ) ;
V_75 = F_43 ( V_68 , F_40 ( V_2 -> V_37 ) ) ;
do {
V_78 = F_50 ( V_75 ) ;
V_48 ++ ;
} while ( ( V_78 & 0xff ) != 0xff && V_48 < 100 );
if ( V_48 == 100 )
F_11 ( V_20 L_7
L_8 ) ;
V_75 = F_43 ( V_68 , F_41 ( V_2 -> V_37 ) ) ;
F_51 ( V_2 -> V_82 , V_75 ) ;
V_75 = F_43 ( V_68 , F_42 ( V_2 -> V_37 ) | V_80 ) ;
F_49 ( V_79 , V_75 ) ;
( void ) F_48 ( V_75 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
void T_4 * V_68 = V_2 -> V_68 ;
void T_4 * V_75 ;
T_5 V_83 ;
T_6 V_78 ;
int V_48 = 0 ;
int V_84 = 1 ;
unsigned char V_36 = V_2 -> V_37 ;
V_85:
F_11 ( V_86 L_9
L_10 , V_36 , V_84 ) ;
V_75 = F_43 ( V_68 , F_42 ( V_36 ) | V_87 ) ;
V_78 = F_53 ( F_48 ( V_75 ) ) ;
F_11 ( V_86 L_11 , V_78 , V_75 ) ;
V_78 |= V_88 ;
F_11 ( V_86 L_12 , V_78 , V_75 ) ;
F_49 ( F_54 ( V_78 ) , V_75 ) ;
F_11 ( V_86 L_13 ) ;
V_75 = F_43 ( V_68 , F_40 ( V_36 ) ) ;
do {
V_83 = F_50 ( V_75 ) ;
V_48 ++ ;
} while ( ( V_83 & 0xff ) != 0xff && V_48 < 100 );
if ( V_48 == 100 )
F_11 ( V_20 L_14
L_8 ) ;
V_75 = F_43 ( V_68 , F_42 ( V_36 ) | V_89 ) ;
V_78 = F_53 ( F_48 ( V_75 ) ) ;
F_11 ( V_86 L_15 , V_78 , V_75 ) ;
if ( V_78 & V_90 ) {
if ( ++ V_84 < 100 )
goto V_85;
else {
F_11 ( V_20 L_16
L_17 ) ;
return;
}
}
V_75 = F_43 ( V_68 , F_42 ( V_36 ) | V_87 ) ;
F_11 ( V_86 L_18 , V_75 ) ;
V_78 = F_53 ( F_48 ( V_75 ) ) ;
F_11 ( V_86 L_19 , V_78 , V_75 ) ;
V_75 = F_43 ( V_68 , F_42 ( V_36 ) | V_89 ) ;
V_78 = F_53 ( F_48 ( V_75 ) ) ;
F_11 ( V_86 L_20 , V_78 , V_75 ) ;
F_11 ( V_86 L_21 ) ;
V_75 = F_43 ( V_68 , F_41 ( V_36 ) ) ;
F_51 ( V_2 -> V_82 , V_75 ) ;
F_11 ( V_86 L_22 ) ;
V_75 = F_43 ( V_68 , F_42 ( V_36 ) | V_87 ) ;
V_78 = F_53 ( F_48 ( V_75 ) ) ;
F_11 ( V_86 L_23 , V_78 , V_75 ) ;
F_11 ( V_86 L_24 ) ;
V_75 = F_43 ( V_68 , F_42 ( V_36 ) | V_87 ) ;
V_78 = 0 ;
F_11 ( V_86 L_25 , V_78 , V_75 ) ;
F_49 ( F_54 ( V_78 ) , V_75 ) ;
V_78 = F_53 ( F_48 ( V_75 ) ) ;
F_11 ( V_86 L_26 , V_78 , V_75 ) ;
}
static void T_7 F_55 ( struct V_32 * V_13 , T_5 V_91 ,
T_5 V_92 )
{
unsigned int V_93 ;
V_92 = V_92 | 0xfffff ;
V_92 ++ ;
V_93 = ( ( V_92 - V_91 ) >> V_8 ) ;
F_2 ( F_22 ( V_13 -> V_36 ) , V_91 , V_93 ) ;
}
static void T_7 F_56 ( struct V_32 * V_13 )
{
void T_4 * V_75 ;
T_5 V_94 , V_95 , V_96 ;
T_5 V_91 , V_92 ;
struct V_1 * V_2 = F_22 ( V_13 -> V_36 ) ;
unsigned char V_97 = V_13 -> V_36 -> V_38 ;
void T_4 * V_68 = V_2 -> V_68 ;
V_75 = F_43 ( V_68 , F_42 ( V_97 ) | V_98 ) ;
V_94 = F_53 ( F_48 ( V_75 ) ) ;
V_75 = F_43 ( V_68 , F_42 ( V_97 ) | V_99 ) ;
V_95 = F_53 ( F_48 ( V_75 ) ) ;
V_75 = F_43 ( V_68 , F_42 ( V_97 ) | V_100 ) ;
V_96 = F_53 ( F_48 ( V_75 ) ) ;
V_91 = ( V_95 << 32 ) | V_94 ;
V_92 = V_96 ;
F_55 ( V_13 , V_91 , V_92 ) ;
}
static void T_7 F_57 ( struct V_32 * V_13 )
{
void T_4 * V_75 ;
T_6 V_101 ;
T_5 V_94 , V_95 , V_96 , V_102 ;
T_5 V_91 , V_92 ;
struct V_1 * V_2 = F_22 ( V_13 -> V_36 ) ;
unsigned char V_97 = V_13 -> V_36 -> V_38 ;
void T_4 * V_68 = V_2 -> V_68 ;
V_75 = F_43 ( V_68 , F_42 ( V_97 ) | V_103 ) ;
V_101 = F_53 ( F_48 ( V_75 ) ) ;
if ( ! ( V_101 & V_104 ) )
return;
V_75 = F_43 ( V_68 , F_42 ( V_97 ) | V_105 ) ;
V_94 = F_53 ( F_48 ( V_75 ) ) ;
V_75 = F_43 ( V_68 , F_42 ( V_97 ) | V_106 ) ;
V_95 = F_53 ( F_48 ( V_75 ) ) ;
V_75 = F_43 ( V_68 , F_42 ( V_97 ) | V_107 ) ;
V_96 = F_53 ( F_48 ( V_75 ) ) ;
V_75 = F_43 ( V_68 , F_42 ( V_97 ) | V_108 ) ;
V_102 = F_53 ( F_48 ( V_75 ) ) ;
V_91 = ( V_95 << 32 ) | V_94 ;
V_92 = ( V_102 << 32 ) | V_96 ;
F_55 ( V_13 , V_91 , V_92 ) ;
}
static void T_7 F_58 ( struct V_32 * V_13 )
{
unsigned int V_4 ;
T_5 V_91 ;
struct V_1 * V_2 = F_22 ( V_13 -> V_36 ) ;
F_2 ( V_2 , V_22 , V_30 ) ;
if ( F_45 ( V_13 -> V_12 ) ) {
V_91 = ( 640 * 1024 ) ;
V_4 = ( ( 1024 - 640 ) * 1024 ) >> V_8 ;
} else {
V_91 = 0 ;
V_4 = ( 1 * 1024 * 1024 ) >> V_8 ;
}
F_2 ( V_2 , V_91 , V_4 ) ;
F_56 ( V_13 ) ;
F_57 ( V_13 ) ;
}
static int T_7 F_59 ( struct V_32 * V_13 , void T_4 * V_68 )
{
T_5 V_83 ;
T_5 V_109 ;
void T_4 * V_75 ;
int V_26 ;
struct V_1 * V_2 ;
V_26 = F_60 ( V_13 , V_68 ) ;
if ( V_26 )
return V_26 ;
V_2 = F_22 ( V_13 -> V_36 ) ;
V_2 -> V_110 = ( unsigned long ) V_67 [ V_13 -> V_36 -> V_38 ] . V_111 ;
if ( F_61 () )
F_62 ( V_2 ) ;
else
F_18 ( V_2 , 0 , V_2 -> V_9 ) ;
if ( F_45 ( V_13 -> V_12 ) )
V_2 -> V_18 = & V_112 ;
else if ( F_44 ( V_13 -> V_12 ) )
V_2 -> V_18 = & V_113 ;
else
F_63 () ;
F_58 ( V_13 ) ;
V_75 = F_43 ( V_68 , F_41 ( V_13 -> V_36 -> V_38 ) ) ;
V_83 = F_64 ( F_50 ( V_75 ) ) ;
V_83 &= ~ V_114 ;
V_109 = ( T_5 ) F_65 ( V_2 -> V_110 ) ;
V_83 |= V_109 ;
F_9 ( V_115 > V_116 ) ;
V_83 |= ( T_5 ) V_115 ;
V_2 -> V_82 = F_66 ( V_83 ) ;
F_51 ( V_2 -> V_82 , V_75 ) ;
F_50 ( V_75 ) ;
return 0 ;
}
static void T_7 F_67 ( struct V_32 * V_13 )
{
T_5 V_83 ;
struct V_1 * V_2 = F_22 ( V_13 -> V_36 ) ;
void T_4 * V_75 ;
unsigned int V_117 ;
V_75 = F_43 ( V_2 -> V_68 , F_41 ( V_13 -> V_36 -> V_38 ) ) ;
V_83 = F_64 ( F_50 ( V_75 ) ) ;
V_83 &= ~ V_114 ;
F_51 ( F_66 ( V_83 ) , V_75 ) ;
F_50 ( V_75 ) ;
V_117 = V_2 -> V_9 / V_118 ;
F_36 ( ( unsigned long ) V_2 -> V_11 , F_34 ( V_117 ) ) ;
V_2 -> V_11 = NULL ;
F_68 ( V_2 ) ;
F_69 ( V_13 -> V_36 , NULL ) ;
V_67 [ V_13 -> V_36 -> V_38 ] . V_111 = NULL ;
}
static void F_70 ( struct V_1 * V_2 )
{
void T_4 * V_68 = V_2 -> V_68 ;
void T_4 * V_75 ;
T_6 V_119 , V_120 ;
V_75 = F_43 ( V_68 , F_42 ( V_2 -> V_37 ) | V_121 ) ;
V_119 = F_53 ( F_48 ( V_75 ) ) ;
V_75 = F_43 ( V_68 , F_42 ( V_2 -> V_37 ) | V_81 ) ;
V_120 = F_53 ( F_48 ( V_75 ) ) ;
F_11 ( V_122 L_27
L_28 , V_2 -> V_37 , V_119 , V_120 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
void T_4 * V_68 = V_2 -> V_68 ;
T_6 V_119 , V_123 , V_120 , V_124 , V_125 ;
void T_4 * V_75 ;
unsigned long V_126 = F_42 ( V_2 -> V_37 ) ;
unsigned long V_127 ;
T_6 V_128 [ 7 ] ;
int V_48 ;
V_75 = F_43 ( V_68 , V_126 | V_121 ) ;
V_119 = F_53 ( F_48 ( V_75 ) ) ;
V_75 = F_43 ( V_68 , V_126 | V_81 ) ;
V_120 = F_53 ( F_48 ( V_75 ) ) ;
V_75 = F_43 ( V_68 , V_126 | 0x290 ) ;
V_123 = F_53 ( F_48 ( V_75 ) ) ;
V_75 = F_43 ( V_68 , V_126 | 0x800 ) ;
V_124 = F_53 ( F_48 ( V_75 ) ) ;
F_11 ( V_122 L_29 ,
V_2 -> V_37 ) ;
F_11 ( V_122 L_30 ,
V_119 , V_120 , V_123 , V_124 ) ;
F_11 ( V_122 L_31 ) ;
for ( V_48 = 0 ; V_48 < F_72 ( V_128 ) ; V_48 ++ ) {
V_127 = ( 0x810 + ( V_48 * 0x10 ) ) ;
V_75 = F_43 ( V_68 , V_126 | V_127 ) ;
V_128 [ V_48 ] = F_53 ( F_48 ( V_75 ) ) ;
F_11 ( L_32 , V_128 [ V_48 ] , V_127 ) ;
}
F_11 ( L_33 ) ;
V_75 = F_43 ( V_68 , V_126 | V_129 ) ;
V_125 = F_53 ( F_48 ( V_75 ) ) ;
F_11 ( V_122 L_34 , V_125 ,
V_129 ) ;
}
static void F_73 ( unsigned long V_130 )
{
struct V_32 * V_13 = (struct V_32 * ) V_130 ;
struct V_1 * V_2 = F_22 ( V_13 -> V_36 ) ;
void T_4 * V_68 = V_2 -> V_68 ;
T_6 V_101 ;
void T_4 * V_75 ;
V_75 = F_43 ( V_68 , F_42 ( V_2 -> V_37 ) | V_121 ) ;
V_101 = F_53 ( F_48 ( V_75 ) ) ;
if ( V_101 & V_131 ) {
V_2 -> V_18 -> V_132 ( V_2 ) ;
F_49 ( 0 , V_75 ) ;
V_75 = F_43 ( V_68 , F_42 ( V_2 -> V_37 ) |
V_103 ) ;
V_101 = F_53 ( F_48 ( V_75 ) ) ;
V_101 |= V_133 ;
F_49 ( F_54 ( V_101 ) , V_75 ) ;
F_48 ( V_75 ) ;
} else {
F_74 ( & V_2 -> V_134 , V_135 + 2 * V_136 ) ;
}
}
static void T_7 F_75 ( void T_4 * V_68 ,
unsigned char V_97 , unsigned long V_137 )
{
T_5 V_83 ;
void T_4 * V_75 ;
unsigned int V_138 = ~ 0 ;
T_5 V_139 ;
switch ( F_39 ( V_97 ) ) {
case 0 : V_138 = ( 63 - 19 ) ;
break;
case 1 : V_138 = ( 63 - 23 ) ;
break;
case 2 : V_138 = ( 63 - 27 ) ;
break;
case 3 : V_138 = ( 63 - 35 ) ;
break;
default:
F_9 ( F_39 ( V_97 ) ) ;
}
V_75 = F_43 ( V_68 , V_140 ) ;
V_83 = F_64 ( F_50 ( V_75 ) ) ;
V_139 = ~ ( 0xFUL << V_138 ) ;
V_83 &= V_139 ;
V_83 |= ( V_137 << V_138 ) ;
F_51 ( F_66 ( V_83 ) , V_75 ) ;
F_50 ( V_75 ) ;
}
static void T_7 F_76 ( struct V_1 * V_2 , struct V_32 * V_13 )
{
unsigned char V_97 = V_13 -> V_36 -> V_38 ;
void T_4 * V_68 = V_2 -> V_68 ;
void T_4 * V_75 ;
T_6 V_78 ;
V_75 = F_43 ( V_68 , F_42 ( V_97 ) | V_141 ) ;
V_78 = F_54 ( F_48 ( V_75 ) ) ;
V_78 |= 0x00800000 ;
F_49 ( F_54 ( V_78 ) , V_75 ) ;
}
static void T_7 F_77 ( struct V_1 * V_2 , struct V_32 * V_13 )
{
unsigned char V_97 = V_13 -> V_36 -> V_38 ;
if ( F_45 ( V_13 -> V_12 ) && ( V_97 == 1 ) )
F_75 ( V_2 -> V_68 , V_97 ,
V_142 ) ;
}
static void T_7 F_78 ( struct V_32 * V_13 )
{
T_6 V_101 ;
unsigned char V_97 ;
void T_4 * V_75 ;
void T_4 * V_68 ;
struct V_1 * V_2 ;
V_97 = V_13 -> V_36 -> V_38 ;
V_2 = F_22 ( V_13 -> V_36 ) ;
V_68 = V_2 -> V_68 ;
V_75 = F_43 ( V_68 , F_42 ( V_97 ) | V_103 ) ;
V_101 = F_53 ( F_48 ( V_75 ) ) ;
V_101 |= V_143 | V_144 | V_145 ;
F_11 ( V_146 L_35 ,
( V_13 -> V_12 == V_77 ) ?
L_36 : L_37 , V_97 ) ;
F_11 ( V_146 L_38
L_39 ) ;
F_49 ( F_54 ( V_101 ) , V_75 ) ;
F_48 ( V_75 ) ;
F_79 ( & V_2 -> V_134 ) ;
V_2 -> V_134 . V_147 = & F_73 ;
V_2 -> V_134 . V_130 = ( unsigned long ) V_13 ;
F_74 ( & V_2 -> V_134 , V_135 ) ;
}
static void T_7 F_80 ( struct V_32 * V_13 )
{
T_6 V_101 ;
unsigned char V_97 ;
void T_4 * V_75 ;
void T_4 * V_68 ;
struct V_1 * V_2 ;
V_97 = V_13 -> V_36 -> V_38 ;
V_2 = F_22 ( V_13 -> V_36 ) ;
V_68 = V_2 -> V_68 ;
V_75 = F_43 ( V_68 , F_42 ( V_97 ) | V_103 ) ;
V_101 = F_53 ( F_48 ( V_75 ) ) ;
V_101 &= ~ ( V_143 | V_144 | V_145 ) ;
F_11 ( V_146 L_40 , V_97 ) ;
F_49 ( F_54 ( V_101 ) , V_75 ) ;
F_48 ( V_75 ) ;
F_81 ( & V_2 -> V_134 ) ;
}
static void T_7 F_82 ( struct V_32 * V_13 )
{
F_83 ( V_13 ) ;
F_69 ( V_13 -> V_36 , NULL ) ;
if ( V_13 -> V_36 -> V_39 )
V_13 -> V_36 -> V_39 -> V_148 = V_13 ;
else
V_13 -> V_36 -> V_148 = V_13 ;
}
static int T_7 F_84 ( struct V_32 * V_13 )
{
void T_4 * V_68 ;
struct V_1 * V_2 ;
int V_26 ;
V_68 = F_38 ( V_13 -> V_36 -> V_38 ) ;
V_26 = F_59 ( V_13 , V_68 ) ;
if ( V_26 )
goto V_149;
F_83 ( V_13 ) ;
if ( V_13 -> V_36 -> V_39 ) {
if ( V_13 -> V_36 -> V_39 -> V_148 )
F_11 ( V_20 L_41
L_42 , V_13 ) ;
V_13 -> V_36 -> V_39 -> V_148 = V_13 ;
} else
V_13 -> V_36 -> V_148 = V_13 ;
V_2 = F_22 ( V_13 -> V_36 ) ;
V_2 -> V_18 -> V_150 ( V_2 , V_13 ) ;
F_78 ( V_13 ) ;
return 0 ;
V_149:
return V_26 ;
}
static int T_7 F_85 ( void )
{
int V_26 ;
int V_151 , V_152 , V_36 ;
void T_4 * V_68 ;
void T_4 * V_75 ;
unsigned long V_14 ;
T_8 V_153 , V_154 ;
T_6 V_78 ;
V_26 = - V_155 ;
for ( V_151 = 0 ; V_151 < V_156 -> V_157 ; V_151 ++ ) {
struct V_158 * V_159 = V_160 [ V_151 ] ;
if ( ( V_159 -> type != V_161 ) && ( V_159 -> type != V_162 ) )
continue;
V_68 = F_86 ( V_159 -> V_163 , 1024 * 1024 ) ;
if ( ! V_68 )
goto error;
for ( V_152 = 0 ; V_152 < V_164 ; V_152 ++ ) {
V_14 = V_165 [ V_152 ] | V_166 ;
V_75 = F_43 ( V_68 , V_14 ) ;
V_78 = F_53 ( F_48 ( V_75 ) ) ;
V_153 = ( T_8 ) ( ( V_78 & 0x00FF0000 ) >> 16 ) ;
V_154 = ( T_8 ) ( ( V_78 & 0x0000FF00 ) >> 8 ) ;
if ( V_154 ) {
for ( V_36 = V_153 ; V_36 <= V_154 ; V_36 ++ ) {
V_67 [ V_36 ] . V_68 = V_68 ;
V_67 [ V_36 ] . V_69 = V_152 ;
}
} else {
V_67 [ V_153 ] . V_68 = V_68 ;
V_67 [ V_153 ] . V_69 = V_152 ;
}
}
}
return 0 ;
error:
for ( V_36 = 0 ; V_36 < F_72 ( V_67 ) ; V_36 ++ )
if ( V_67 [ V_36 ] . V_68 )
F_87 ( V_67 [ V_36 ] . V_68 ) ;
return V_26 ;
}
static int T_7 F_88 ( void )
{
int V_26 ;
struct V_32 * V_13 = NULL ;
struct V_167 * V_168 ;
V_26 = F_85 () ;
if ( V_26 )
return V_26 ;
if ( F_61 () )
F_89 () ;
do {
V_13 = F_90 ( V_169 , V_170 , V_13 ) ;
if ( ! V_13 )
break;
if ( ! F_46 ( V_13 -> V_12 ) )
continue;
V_168 = & V_67 [ V_13 -> V_36 -> V_38 ] ;
if ( V_168 -> V_171 ) {
F_82 ( V_13 ) ;
continue;
}
if ( ! V_168 -> V_111 && ! V_172 )
continue;
V_26 = F_84 ( V_13 ) ;
if ( V_26 )
goto error;
} while ( 1 );
V_13 = NULL ;
F_91 (dev) {
struct V_1 * V_2 ;
V_2 = F_20 ( & V_13 -> V_13 ) ;
if ( F_1 ( V_2 ) )
V_13 -> V_13 . V_173 . V_174 = & V_175 ;
}
return V_26 ;
error:
do {
V_13 = F_90 ( V_169 , V_170 , V_13 ) ;
if ( ! V_13 )
break;
if ( ! F_46 ( V_13 -> V_12 ) )
continue;
V_168 = & V_67 [ V_13 -> V_36 -> V_38 ] ;
if ( V_168 -> V_171 ) {
F_92 ( V_13 ) ;
continue;
}
if ( ! V_168 -> V_111 && ! V_172 )
continue;
F_80 ( V_13 ) ;
F_67 ( V_13 ) ;
F_92 ( V_13 ) ;
V_13 -> V_13 . V_173 . V_174 = NULL ;
} while ( 1 );
return V_26 ;
}
static inline int T_7 F_93 ( T_5 V_176 )
{
int V_26 ;
if ( V_115 != V_177 )
return V_115 ;
V_26 = F_34 ( V_176 >> 13 ) ;
if ( V_26 > V_116 )
V_26 = V_116 ;
return V_26 ;
}
static int T_7 F_94 ( void )
{
unsigned long V_178 ;
unsigned V_179 , V_48 ;
int V_180 , V_181 ;
V_179 = V_156 -> V_182 ;
if ( V_179 > V_183 ) {
F_11 ( V_20
L_43
L_44 ,
V_183 , V_179 ) ;
return - V_184 ;
}
switch ( V_156 -> V_185 ) {
case 2 :
V_180 = 11 ;
V_181 = 13 ;
break;
case 3 :
V_180 = 12 ;
V_181 = 15 ;
break;
default:
F_11 ( V_20
L_45 ,
V_156 -> V_185 ) ;
return - V_186 ;
}
V_178 = ( ( unsigned long ) V_156 ) + 3 ;
for ( V_48 = 0 ; V_48 < V_179 ; V_48 ++ , V_178 += V_180 )
V_187 [ V_48 ] = (struct V_188 * ) V_178 ;
for ( V_48 = 0 ; V_48 < V_156 -> V_157 ;
V_48 ++ , V_178 += V_181 )
V_160 [ V_48 ] = (struct V_158 * ) V_178 ;
return 0 ;
}
static int T_7 F_95 ( int V_36 , unsigned short V_32 )
{
int V_13 ;
T_6 V_78 ;
if ( V_32 == V_76 ) {
return 1 ;
}
for ( V_13 = 1 ; V_13 < 8 ; V_13 ++ ) {
V_78 = F_96 ( V_36 , V_13 , 0 , 0 ) ;
if ( V_78 != 0xffffffff )
break;
}
return ( V_78 != 0xffffffff ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
T_5 * V_189 ;
unsigned int V_5 ;
V_189 = ( ( T_5 * ) V_2 -> V_110 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_9 ; V_5 ++ ) {
if ( * V_189 != 0x0 )
F_97 ( V_5 , V_2 -> V_11 ) ;
V_189 ++ ;
}
}
static void T_7 F_89 ( void )
{
int V_36 ;
void T_4 * V_75 ;
unsigned long V_111 ;
for ( V_36 = 0 ; V_36 < V_190 ; V_36 ++ ) {
struct V_167 * V_168 = & V_67 [ V_36 ] ;
unsigned short V_191 ;
T_6 V_78 ;
V_78 = F_96 ( V_36 , 0 , 0 , 0 ) ;
V_191 = ( V_78 & 0xFFFF0000 ) >> 16 ;
if ( ! F_46 ( V_191 ) )
continue;
if ( V_168 -> V_171 )
continue;
if ( F_95 ( V_36 , V_191 ) ||
V_172 ) {
V_75 = F_43 ( V_67 [ V_36 ] . V_68 ,
F_41 ( V_36 ) ) ;
V_111 = F_64 ( F_50 ( V_75 ) ) ;
V_111 = V_111 & V_114 ;
V_111 = V_111 & ( ~ V_115 ) ;
V_168 -> V_111 = ( T_5 * ) F_98 ( V_111 ) ;
}
}
return;
}
static int T_7 F_99 ( void )
{
int V_26 ;
F_11 ( V_146 L_46 ) ;
V_26 = F_88 () ;
if ( V_26 ) {
F_11 ( V_31 L_47
L_48 , V_26 ) ;
return V_26 ;
}
return 0 ;
}
int T_7 F_100 ( void )
{
int V_36 ;
void * V_2 ;
int V_192 = 0 ;
unsigned long V_178 ;
unsigned int V_14 , V_193 ;
int V_26 ;
if ( V_194 || V_195 )
return - V_184 ;
if ( ! V_196 )
return - V_184 ;
if ( ! F_101 () )
return - V_184 ;
F_11 ( V_86 L_49 ) ;
V_178 = ( unsigned long ) F_102 ( F_103 () ) ;
V_156 = NULL ;
V_193 = 0 ;
V_14 = 0x180 ;
while ( V_14 > V_193 ) {
if ( * ( ( unsigned short * ) ( V_178 + V_14 + 2 ) ) == 0x4752 ) {
V_156 = (struct V_156 * ) ( V_178 + V_14 + 4 ) ;
break;
}
V_193 = V_14 ;
V_14 = * ( ( unsigned short * ) ( V_178 + V_14 ) ) ;
}
if ( ! V_156 ) {
F_11 ( V_86 L_50
L_51 ) ;
return - V_184 ;
}
V_26 = F_94 () ;
if ( V_26 ) {
F_11 ( V_86 L_52 , V_26 ) ;
return - V_197 ;
}
V_115 = F_93 ( ( F_61 () ?
V_198 : V_199 ) * V_16 ) ;
for ( V_36 = 0 ; V_36 < V_190 ; V_36 ++ ) {
struct V_167 * V_168 = & V_67 [ V_36 ] ;
unsigned short V_191 ;
T_6 V_78 ;
V_78 = F_96 ( V_36 , 0 , 0 , 0 ) ;
V_191 = ( V_78 & 0xFFFF0000 ) >> 16 ;
if ( ! F_46 ( V_191 ) )
continue;
if ( V_168 -> V_171 )
continue;
if ( F_95 ( V_36 , V_191 ) ||
V_172 ) {
if ( ! F_61 () ) {
V_2 = F_104 () ;
if ( ! V_2 )
goto V_200;
V_168 -> V_111 = V_2 ;
}
V_192 = 1 ;
}
}
F_11 ( V_86 L_53 ,
V_192 ? L_54 : L_55 ) ;
if ( V_192 ) {
V_195 = 1 ;
V_201 = 1 ;
F_11 ( V_146 L_56 ) ;
F_11 ( V_146 L_57 ,
V_115 ) ;
V_202 . V_203 . V_204 = F_99 ;
}
return V_192 ;
V_200:
for ( -- V_36 ; V_36 >= 0 ; -- V_36 ) {
struct V_167 * V_168 = & V_67 [ V_36 ] ;
if ( V_168 -> V_111 )
F_105 ( V_168 -> V_111 ) ;
}
return - V_197 ;
}
static int T_7 F_106 ( char * V_205 )
{
unsigned int V_206 ;
T_2 V_207 ;
char * V_208 ;
while ( * V_205 ) {
if ( ! strncmp ( V_205 , L_58 , 3 ) )
V_115 = V_209 ;
else if ( ! strncmp ( V_205 , L_59 , 4 ) )
V_115 = V_210 ;
else if ( ! strncmp ( V_205 , L_60 , 4 ) )
V_115 = V_211 ;
else if ( ! strncmp ( V_205 , L_61 , 4 ) )
V_115 = V_212 ;
else if ( ! strncmp ( V_205 , L_62 , 2 ) )
V_115 = V_213 ;
else if ( ! strncmp ( V_205 , L_63 , 2 ) )
V_115 = V_214 ;
else if ( ! strncmp ( V_205 , L_64 , 2 ) )
V_115 = V_215 ;
else if ( ! strncmp ( V_205 , L_65 , 2 ) )
V_115 = V_116 ;
V_207 = strlen ( L_66 ) ;
if ( ! strncmp ( V_205 , L_66 , V_207 ) )
V_172 = 1 ;
V_207 = strlen ( L_67 ) ;
if ( ! strncmp ( V_205 , L_67 , V_207 ) ) {
V_205 += V_207 ;
if ( * V_205 == '=' )
++ V_205 ;
if ( * V_205 == '\0' )
break;
V_206 = F_107 ( V_205 , & V_208 , 0 ) ;
if ( V_205 == V_208 )
break;
if ( V_206 < V_190 ) {
F_11 ( V_146 L_68
L_69 , V_206 ) ;
V_67 [ V_206 ] . V_171 = 1 ;
}
}
V_205 = strpbrk ( V_205 , L_70 ) ;
if ( ! V_205 )
break;
V_205 ++ ;
}
return 1 ;
}
static void T_7 F_108 ( struct V_32 * V_13 )
{
struct V_1 * V_2 ;
unsigned int V_4 ;
int V_48 ;
V_2 = F_22 ( V_13 -> V_36 ) ;
for ( V_48 = 0 ; V_48 < 4 ; V_48 ++ ) {
struct V_216 * V_217 = & V_13 -> V_216 [ V_218 + V_48 ] ;
if ( ! ( V_217 -> V_7 & V_219 ) )
continue;
if ( ! V_217 -> V_91 )
continue;
V_4 = F_109 ( V_217 ) >> V_8 ;
V_4 ++ ;
F_2 ( V_2 , V_217 -> V_91 , V_4 ) ;
}
}
static int T_7 F_110 ( void )
{
struct V_32 * V_13 = NULL ;
struct V_167 * V_168 ;
if ( V_194 || V_220 || ! V_201 )
return - V_184 ;
F_11 ( V_86 L_71 ) ;
do {
V_13 = F_90 ( V_169 , V_170 , V_13 ) ;
if ( ! V_13 )
break;
if ( ! F_46 ( V_13 -> V_12 ) )
continue;
V_168 = & V_67 [ V_13 -> V_36 -> V_38 ] ;
if ( V_168 -> V_171 )
continue;
if ( ! V_168 -> V_111 )
continue;
F_108 ( V_13 ) ;
} while ( 1 );
return 0 ;
}
