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
F_11 ( L_1 ) ;
F_5 ( & V_2 -> V_10 , V_7 ) ;
if ( V_20 )
F_12 ( L_2 ) ;
else
return V_21 ;
}
}
V_2 -> V_17 = V_14 + V_4 ;
F_9 ( V_2 -> V_17 > V_2 -> V_9 ) ;
F_5 ( & V_2 -> V_10 , V_7 ) ;
return V_14 ;
}
static T_1 F_13 ( struct V_12 * V_13 , struct V_1 * V_2 ,
void * V_22 , unsigned int V_4 , int V_23 )
{
unsigned long V_24 ;
T_1 V_25 ;
V_24 = F_6 ( V_13 , V_2 , V_4 ) ;
if ( F_14 ( V_24 == V_21 ) ) {
F_11 ( L_3 ,
V_4 , V_2 ) ;
return V_21 ;
}
V_25 = ( V_24 << V_8 ) | ( ( unsigned long ) V_22 & ~ V_26 ) ;
F_15 ( V_2 , V_24 , V_4 , ( unsigned long ) V_22 & V_26 ,
V_23 ) ;
return V_25 ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_27 ,
unsigned int V_4 )
{
unsigned long V_24 ;
unsigned long V_28 ;
unsigned long V_7 ;
V_28 = V_21 + ( V_29 * V_16 ) ;
if ( F_14 ( ( V_27 >= V_21 ) && ( V_27 < V_28 ) ) ) {
F_17 ( 1 , V_30 L_4
L_5 , V_27 ) ;
return;
}
V_24 = V_27 >> V_8 ;
F_9 ( V_24 + V_4 > V_2 -> V_9 ) ;
F_18 ( V_2 , V_24 , V_4 ) ;
F_3 ( & V_2 -> V_10 , V_7 ) ;
F_19 ( V_2 -> V_11 , V_24 , V_4 ) ;
F_5 ( & V_2 -> V_10 , V_7 ) ;
}
static inline struct V_1 * F_20 ( struct V_12 * V_13 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_1 * V_2 ;
V_32 = F_21 ( V_13 ) ;
V_34 = V_32 -> V_35 ;
do {
V_2 = F_22 ( V_34 ) ;
if ( V_2 && V_2 -> V_36 == V_34 -> V_37 )
break;
V_2 = NULL ;
V_34 = V_34 -> V_38 ;
} while ( V_34 );
F_9 ( V_2 && ( V_2 -> V_36 != V_34 -> V_37 ) ) ;
return V_2 ;
}
static void F_23 ( struct V_12 * V_13 , struct V_39 * V_40 ,
int V_41 , enum V_42 V_43 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = F_20 ( V_13 ) ;
struct V_39 * V_46 ;
int V_47 ;
if ( ! F_1 ( V_2 ) )
return;
F_24 (sglist, s, nelems, i) {
unsigned int V_4 ;
T_1 V_48 = V_46 -> V_49 ;
unsigned int V_50 = V_46 -> V_51 ;
if ( V_50 == 0 )
break;
V_4 = F_25 ( V_48 , V_50 , V_16 ) ;
F_16 ( V_2 , V_48 , V_4 ) ;
}
}
static int F_26 ( struct V_12 * V_13 , struct V_39 * V_52 ,
int V_41 , enum V_42 V_43 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = F_20 ( V_13 ) ;
struct V_39 * V_46 ;
unsigned long V_22 ;
unsigned int V_4 ;
unsigned long V_24 ;
int V_47 ;
F_24 (sg, s, nelems, i) {
F_9 ( ! F_27 ( V_46 ) ) ;
V_22 = ( unsigned long ) F_28 ( V_46 ) ;
V_4 = F_25 ( V_22 , V_46 -> V_53 , V_16 ) ;
V_24 = F_6 ( V_13 , V_2 , V_4 ) ;
if ( V_24 == V_21 ) {
V_46 -> V_51 = 0 ;
goto error;
}
V_46 -> V_49 = ( V_24 << V_8 ) | V_46 -> V_14 ;
F_15 ( V_2 , V_24 , V_4 , V_22 & V_26 , V_43 ) ;
V_46 -> V_51 = V_46 -> V_53 ;
}
return V_41 ;
error:
F_23 ( V_13 , V_52 , V_41 , V_43 , NULL ) ;
F_24 (sg, s, nelems, i) {
V_52 -> V_49 = V_21 ;
V_52 -> V_51 = 0 ;
}
return 0 ;
}
static T_1 F_29 ( struct V_12 * V_13 , struct V_54 * V_54 ,
unsigned long V_14 , T_2 V_55 ,
enum V_42 V_43 ,
struct V_44 * V_45 )
{
void * V_22 = F_30 ( V_54 ) + V_14 ;
unsigned long V_56 ;
unsigned int V_4 ;
struct V_1 * V_2 = F_20 ( V_13 ) ;
V_56 = ( unsigned long ) V_22 ;
V_4 = F_25 ( V_56 , V_55 , V_16 ) ;
return F_13 ( V_13 , V_2 , V_22 , V_4 , V_43 ) ;
}
static void F_31 ( struct V_12 * V_13 , T_1 V_27 ,
T_2 V_55 , enum V_42 V_43 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = F_20 ( V_13 ) ;
unsigned int V_4 ;
V_4 = F_25 ( V_27 , V_55 , V_16 ) ;
F_16 ( V_2 , V_27 , V_4 ) ;
}
static void * F_32 ( struct V_12 * V_13 , T_2 V_55 ,
T_1 * V_57 , T_3 V_58 , struct V_44 * V_45 )
{
void * V_25 = NULL ;
T_1 V_59 ;
unsigned int V_4 , V_60 ;
struct V_1 * V_2 = F_20 ( V_13 ) ;
V_55 = F_33 ( V_55 ) ;
V_4 = V_55 >> V_8 ;
V_60 = F_34 ( V_55 ) ;
V_58 &= ~ ( V_61 | V_62 | V_63 ) ;
V_25 = ( void * ) F_35 ( V_58 , V_60 ) ;
if ( ! V_25 )
goto error;
memset ( V_25 , 0 , V_55 ) ;
V_59 = F_13 ( V_13 , V_2 , V_25 , V_4 , V_64 ) ;
if ( V_59 == V_21 )
goto free;
* V_57 = V_59 ;
return V_25 ;
free:
F_36 ( ( unsigned long ) V_25 , F_34 ( V_55 ) ) ;
V_25 = NULL ;
error:
return V_25 ;
}
static void F_37 ( struct V_12 * V_13 , T_2 V_55 ,
void * V_22 , T_1 V_57 ,
struct V_44 * V_45 )
{
unsigned int V_4 ;
struct V_1 * V_2 = F_20 ( V_13 ) ;
V_55 = F_33 ( V_55 ) ;
V_4 = V_55 >> V_8 ;
F_16 ( V_2 , V_57 , V_4 ) ;
F_36 ( ( unsigned long ) V_22 , F_34 ( V_55 ) ) ;
}
static inline void T_4 * F_38 ( unsigned char V_65 )
{
return V_66 [ V_65 ] . V_67 ;
}
static inline int F_39 ( unsigned char V_65 )
{
return V_66 [ V_65 ] . V_68 ;
}
static inline unsigned long F_40 ( unsigned char V_65 )
{
T_2 V_69 = F_39 ( V_65 ) ;
return V_70 [ V_69 ] ;
}
static inline unsigned long F_41 ( unsigned char V_65 )
{
T_2 V_69 = F_39 ( V_65 ) ;
return V_71 [ V_69 ] ;
}
static inline unsigned long F_42 ( unsigned char V_65 )
{
T_2 V_69 = F_39 ( V_65 ) ;
return V_72 [ V_69 ] ;
}
static inline void T_4 * F_43 ( void T_4 * V_73 , unsigned long V_14 )
{
unsigned long V_74 = ( ( unsigned long ) V_73 ) | V_14 ;
return ( void T_4 * ) V_74 ;
}
static inline int F_44 ( unsigned short V_12 )
{
return ( V_12 == V_75 ) ;
}
static inline int F_45 ( unsigned short V_12 )
{
return ( V_12 == V_76 ) ;
}
static inline int F_46 ( unsigned short V_12 )
{
return ( F_45 ( V_12 ) || F_44 ( V_12 ) ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
T_5 V_77 ;
T_6 V_78 ;
int V_47 = 0 ;
void T_4 * V_67 = V_2 -> V_67 ;
void T_4 * V_74 ;
V_74 = F_43 ( V_67 , F_42 ( V_2 -> V_36 ) | V_79 ) ;
V_78 = F_48 ( V_74 ) ;
F_49 ( 0 , V_74 ) ;
V_74 = F_43 ( V_67 , F_42 ( V_2 -> V_36 ) | V_80 ) ;
V_77 = F_48 ( V_74 ) ;
V_74 = F_43 ( V_67 , F_40 ( V_2 -> V_36 ) ) ;
do {
V_77 = F_50 ( V_74 ) ;
V_47 ++ ;
} while ( ( V_77 & 0xff ) != 0xff && V_47 < 100 );
if ( V_47 == 100 )
F_11 ( L_6 ) ;
V_74 = F_43 ( V_67 , F_41 ( V_2 -> V_36 ) ) ;
F_51 ( V_2 -> V_81 , V_74 ) ;
V_74 = F_43 ( V_67 , F_42 ( V_2 -> V_36 ) | V_79 ) ;
F_49 ( V_78 , V_74 ) ;
( void ) F_48 ( V_74 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
void T_4 * V_67 = V_2 -> V_67 ;
void T_4 * V_74 ;
T_5 V_82 ;
T_6 V_77 ;
int V_47 = 0 ;
int V_83 = 1 ;
unsigned char V_35 = V_2 -> V_36 ;
V_84:
F_53 ( V_85 L_7
L_8 , V_35 , V_83 ) ;
V_74 = F_43 ( V_67 , F_42 ( V_35 ) | V_86 ) ;
V_77 = F_54 ( F_48 ( V_74 ) ) ;
F_53 ( V_85 L_9 , V_77 , V_74 ) ;
V_77 |= V_87 ;
F_53 ( V_85 L_10 , V_77 , V_74 ) ;
F_49 ( F_55 ( V_77 ) , V_74 ) ;
F_53 ( V_85 L_11 ) ;
V_74 = F_43 ( V_67 , F_40 ( V_35 ) ) ;
do {
V_82 = F_50 ( V_74 ) ;
V_47 ++ ;
} while ( ( V_82 & 0xff ) != 0xff && V_47 < 100 );
if ( V_47 == 100 )
F_11 ( L_12 ) ;
V_74 = F_43 ( V_67 , F_42 ( V_35 ) | V_88 ) ;
V_77 = F_54 ( F_48 ( V_74 ) ) ;
F_53 ( V_85 L_13 , V_77 , V_74 ) ;
if ( V_77 & V_89 ) {
if ( ++ V_83 < 100 )
goto V_84;
else {
F_11 ( L_14 ) ;
return;
}
}
V_74 = F_43 ( V_67 , F_42 ( V_35 ) | V_86 ) ;
F_53 ( V_85 L_15 , V_74 ) ;
V_77 = F_54 ( F_48 ( V_74 ) ) ;
F_53 ( V_85 L_16 , V_77 , V_74 ) ;
V_74 = F_43 ( V_67 , F_42 ( V_35 ) | V_88 ) ;
V_77 = F_54 ( F_48 ( V_74 ) ) ;
F_53 ( V_85 L_17 , V_77 , V_74 ) ;
F_53 ( V_85 L_18 ) ;
V_74 = F_43 ( V_67 , F_41 ( V_35 ) ) ;
F_51 ( V_2 -> V_81 , V_74 ) ;
F_53 ( V_85 L_19 ) ;
V_74 = F_43 ( V_67 , F_42 ( V_35 ) | V_86 ) ;
V_77 = F_54 ( F_48 ( V_74 ) ) ;
F_53 ( V_85 L_20 , V_77 , V_74 ) ;
F_53 ( V_85 L_21 ) ;
V_74 = F_43 ( V_67 , F_42 ( V_35 ) | V_86 ) ;
V_77 = 0 ;
F_53 ( V_85 L_22 , V_77 , V_74 ) ;
F_49 ( F_55 ( V_77 ) , V_74 ) ;
V_77 = F_54 ( F_48 ( V_74 ) ) ;
F_53 ( V_85 L_23 , V_77 , V_74 ) ;
}
static void T_7 F_56 ( struct V_31 * V_13 , T_5 V_90 ,
T_5 V_91 )
{
unsigned int V_92 ;
V_91 = V_91 | 0xfffff ;
V_91 ++ ;
V_92 = ( ( V_91 - V_90 ) >> V_8 ) ;
F_2 ( F_22 ( V_13 -> V_35 ) , V_90 , V_92 ) ;
}
static void T_7 F_57 ( struct V_31 * V_13 )
{
void T_4 * V_74 ;
T_5 V_93 , V_94 , V_95 ;
T_5 V_90 , V_91 ;
struct V_1 * V_2 = F_22 ( V_13 -> V_35 ) ;
unsigned char V_96 = V_13 -> V_35 -> V_37 ;
void T_4 * V_67 = V_2 -> V_67 ;
V_74 = F_43 ( V_67 , F_42 ( V_96 ) | V_97 ) ;
V_93 = F_54 ( F_48 ( V_74 ) ) ;
V_74 = F_43 ( V_67 , F_42 ( V_96 ) | V_98 ) ;
V_94 = F_54 ( F_48 ( V_74 ) ) ;
V_74 = F_43 ( V_67 , F_42 ( V_96 ) | V_99 ) ;
V_95 = F_54 ( F_48 ( V_74 ) ) ;
V_90 = ( V_94 << 32 ) | V_93 ;
V_91 = V_95 ;
F_56 ( V_13 , V_90 , V_91 ) ;
}
static void T_7 F_58 ( struct V_31 * V_13 )
{
void T_4 * V_74 ;
T_6 V_100 ;
T_5 V_93 , V_94 , V_95 , V_101 ;
T_5 V_90 , V_91 ;
struct V_1 * V_2 = F_22 ( V_13 -> V_35 ) ;
unsigned char V_96 = V_13 -> V_35 -> V_37 ;
void T_4 * V_67 = V_2 -> V_67 ;
V_74 = F_43 ( V_67 , F_42 ( V_96 ) | V_102 ) ;
V_100 = F_54 ( F_48 ( V_74 ) ) ;
if ( ! ( V_100 & V_103 ) )
return;
V_74 = F_43 ( V_67 , F_42 ( V_96 ) | V_104 ) ;
V_93 = F_54 ( F_48 ( V_74 ) ) ;
V_74 = F_43 ( V_67 , F_42 ( V_96 ) | V_105 ) ;
V_94 = F_54 ( F_48 ( V_74 ) ) ;
V_74 = F_43 ( V_67 , F_42 ( V_96 ) | V_106 ) ;
V_95 = F_54 ( F_48 ( V_74 ) ) ;
V_74 = F_43 ( V_67 , F_42 ( V_96 ) | V_107 ) ;
V_101 = F_54 ( F_48 ( V_74 ) ) ;
V_90 = ( V_94 << 32 ) | V_93 ;
V_91 = ( V_101 << 32 ) | V_95 ;
F_56 ( V_13 , V_90 , V_91 ) ;
}
static void T_7 F_59 ( struct V_31 * V_13 )
{
unsigned int V_4 ;
T_5 V_90 ;
struct V_1 * V_2 = F_22 ( V_13 -> V_35 ) ;
F_2 ( V_2 , V_21 , V_29 ) ;
if ( F_45 ( V_13 -> V_12 ) ) {
V_90 = ( 640 * 1024 ) ;
V_4 = ( ( 1024 - 640 ) * 1024 ) >> V_8 ;
} else {
V_90 = 0 ;
V_4 = ( 1 * 1024 * 1024 ) >> V_8 ;
}
F_2 ( V_2 , V_90 , V_4 ) ;
F_57 ( V_13 ) ;
F_58 ( V_13 ) ;
}
static int T_7 F_60 ( struct V_31 * V_13 , void T_4 * V_67 )
{
T_5 V_82 ;
T_5 V_108 ;
void T_4 * V_74 ;
int V_25 ;
struct V_1 * V_2 ;
V_25 = F_61 ( V_13 , V_67 ) ;
if ( V_25 )
return V_25 ;
V_2 = F_22 ( V_13 -> V_35 ) ;
V_2 -> V_109 = ( unsigned long ) V_66 [ V_13 -> V_35 -> V_37 ] . V_110 ;
if ( F_62 () )
F_63 ( V_2 ) ;
else
F_18 ( V_2 , 0 , V_2 -> V_9 ) ;
if ( F_45 ( V_13 -> V_12 ) )
V_2 -> V_18 = & V_111 ;
else if ( F_44 ( V_13 -> V_12 ) )
V_2 -> V_18 = & V_112 ;
else
F_64 () ;
F_59 ( V_13 ) ;
V_74 = F_43 ( V_67 , F_41 ( V_13 -> V_35 -> V_37 ) ) ;
V_82 = F_65 ( F_50 ( V_74 ) ) ;
V_82 &= ~ V_113 ;
V_108 = ( T_5 ) F_66 ( V_2 -> V_109 ) ;
V_82 |= V_108 ;
F_9 ( V_114 > V_115 ) ;
V_82 |= ( T_5 ) V_114 ;
V_2 -> V_81 = F_67 ( V_82 ) ;
F_51 ( V_2 -> V_81 , V_74 ) ;
F_50 ( V_74 ) ;
return 0 ;
}
static void T_7 F_68 ( struct V_31 * V_13 )
{
T_5 V_82 ;
struct V_1 * V_2 = F_22 ( V_13 -> V_35 ) ;
void T_4 * V_74 ;
unsigned int V_116 ;
V_74 = F_43 ( V_2 -> V_67 , F_41 ( V_13 -> V_35 -> V_37 ) ) ;
V_82 = F_65 ( F_50 ( V_74 ) ) ;
V_82 &= ~ V_113 ;
F_51 ( F_67 ( V_82 ) , V_74 ) ;
F_50 ( V_74 ) ;
V_116 = V_2 -> V_9 / V_117 ;
F_36 ( ( unsigned long ) V_2 -> V_11 , F_34 ( V_116 ) ) ;
V_2 -> V_11 = NULL ;
F_69 ( V_2 ) ;
F_70 ( V_13 -> V_35 , NULL ) ;
V_66 [ V_13 -> V_35 -> V_37 ] . V_110 = NULL ;
}
static void F_71 ( struct V_1 * V_2 )
{
void T_4 * V_67 = V_2 -> V_67 ;
void T_4 * V_74 ;
T_6 V_118 , V_119 ;
V_74 = F_43 ( V_67 , F_42 ( V_2 -> V_36 ) | V_120 ) ;
V_118 = F_54 ( F_48 ( V_74 ) ) ;
V_74 = F_43 ( V_67 , F_42 ( V_2 -> V_36 ) | V_80 ) ;
V_119 = F_54 ( F_48 ( V_74 ) ) ;
F_72 ( L_24 ,
V_2 -> V_36 , V_118 , V_119 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
void T_4 * V_67 = V_2 -> V_67 ;
T_6 V_118 , V_121 , V_119 , V_122 , V_123 ;
void T_4 * V_74 ;
unsigned long V_124 = F_42 ( V_2 -> V_36 ) ;
unsigned long V_125 ;
T_6 V_126 [ 7 ] ;
int V_47 ;
V_74 = F_43 ( V_67 , V_124 | V_120 ) ;
V_118 = F_54 ( F_48 ( V_74 ) ) ;
V_74 = F_43 ( V_67 , V_124 | V_80 ) ;
V_119 = F_54 ( F_48 ( V_74 ) ) ;
V_74 = F_43 ( V_67 , V_124 | 0x290 ) ;
V_121 = F_54 ( F_48 ( V_74 ) ) ;
V_74 = F_43 ( V_67 , V_124 | 0x800 ) ;
V_122 = F_54 ( F_48 ( V_74 ) ) ;
F_72 ( L_25 , V_2 -> V_36 ) ;
F_72 ( L_26 ,
V_118 , V_119 , V_121 , V_122 ) ;
F_72 ( L_27 ) ;
for ( V_47 = 0 ; V_47 < F_74 ( V_126 ) ; V_47 ++ ) {
V_125 = ( 0x810 + ( V_47 * 0x10 ) ) ;
V_74 = F_43 ( V_67 , V_124 | V_125 ) ;
V_126 [ V_47 ] = F_54 ( F_48 ( V_74 ) ) ;
F_75 ( L_28 , V_126 [ V_47 ] , V_125 ) ;
}
F_75 ( L_29 ) ;
V_74 = F_43 ( V_67 , V_124 | V_127 ) ;
V_123 = F_54 ( F_48 ( V_74 ) ) ;
F_53 ( V_128 L_30 , V_123 ,
V_127 ) ;
}
static void F_76 ( unsigned long V_129 )
{
struct V_31 * V_13 = (struct V_31 * ) V_129 ;
struct V_1 * V_2 = F_22 ( V_13 -> V_35 ) ;
void T_4 * V_67 = V_2 -> V_67 ;
T_6 V_100 ;
void T_4 * V_74 ;
V_74 = F_43 ( V_67 , F_42 ( V_2 -> V_36 ) | V_120 ) ;
V_100 = F_54 ( F_48 ( V_74 ) ) ;
if ( V_100 & V_130 ) {
V_2 -> V_18 -> V_131 ( V_2 ) ;
F_49 ( 0 , V_74 ) ;
V_74 = F_43 ( V_67 , F_42 ( V_2 -> V_36 ) |
V_102 ) ;
V_100 = F_54 ( F_48 ( V_74 ) ) ;
V_100 |= V_132 ;
F_49 ( F_55 ( V_100 ) , V_74 ) ;
F_48 ( V_74 ) ;
} else {
F_77 ( & V_2 -> V_133 , V_134 + 2 * V_135 ) ;
}
}
static void T_7 F_78 ( void T_4 * V_67 ,
unsigned char V_96 , unsigned long V_136 )
{
T_5 V_82 ;
void T_4 * V_74 ;
unsigned int V_137 = ~ 0 ;
T_5 V_138 ;
switch ( F_39 ( V_96 ) ) {
case 0 : V_137 = ( 63 - 19 ) ;
break;
case 1 : V_137 = ( 63 - 23 ) ;
break;
case 2 : V_137 = ( 63 - 27 ) ;
break;
case 3 : V_137 = ( 63 - 35 ) ;
break;
default:
F_9 ( F_39 ( V_96 ) ) ;
}
V_74 = F_43 ( V_67 , V_139 ) ;
V_82 = F_65 ( F_50 ( V_74 ) ) ;
V_138 = ~ ( 0xFUL << V_137 ) ;
V_82 &= V_138 ;
V_82 |= ( V_136 << V_137 ) ;
F_51 ( F_67 ( V_82 ) , V_74 ) ;
F_50 ( V_74 ) ;
}
static void T_7 F_79 ( struct V_1 * V_2 , struct V_31 * V_13 )
{
unsigned char V_96 = V_13 -> V_35 -> V_37 ;
void T_4 * V_67 = V_2 -> V_67 ;
void T_4 * V_74 ;
T_6 V_77 ;
V_74 = F_43 ( V_67 , F_42 ( V_96 ) | V_140 ) ;
V_77 = F_55 ( F_48 ( V_74 ) ) ;
V_77 |= 0x00800000 ;
F_49 ( F_55 ( V_77 ) , V_74 ) ;
}
static void T_7 F_80 ( struct V_1 * V_2 , struct V_31 * V_13 )
{
unsigned char V_96 = V_13 -> V_35 -> V_37 ;
if ( F_45 ( V_13 -> V_12 ) && ( V_96 == 1 ) )
F_78 ( V_2 -> V_67 , V_96 ,
V_141 ) ;
}
static void T_7 F_81 ( struct V_31 * V_13 )
{
T_6 V_100 ;
unsigned char V_96 ;
void T_4 * V_74 ;
void T_4 * V_67 ;
struct V_1 * V_2 ;
V_96 = V_13 -> V_35 -> V_37 ;
V_2 = F_22 ( V_13 -> V_35 ) ;
V_67 = V_2 -> V_67 ;
V_74 = F_43 ( V_67 , F_42 ( V_96 ) | V_102 ) ;
V_100 = F_54 ( F_48 ( V_74 ) ) ;
V_100 |= V_142 | V_143 | V_144 ;
F_53 ( V_145 L_31 ,
( V_13 -> V_12 == V_76 ) ?
L_32 : L_33 , V_96 ) ;
F_53 ( V_145 L_34
L_35 ) ;
F_49 ( F_55 ( V_100 ) , V_74 ) ;
F_48 ( V_74 ) ;
F_82 ( & V_2 -> V_133 ) ;
V_2 -> V_133 . V_146 = & F_76 ;
V_2 -> V_133 . V_129 = ( unsigned long ) V_13 ;
F_77 ( & V_2 -> V_133 , V_134 ) ;
}
static void T_7 F_83 ( struct V_31 * V_13 )
{
T_6 V_100 ;
unsigned char V_96 ;
void T_4 * V_74 ;
void T_4 * V_67 ;
struct V_1 * V_2 ;
V_96 = V_13 -> V_35 -> V_37 ;
V_2 = F_22 ( V_13 -> V_35 ) ;
V_67 = V_2 -> V_67 ;
V_74 = F_43 ( V_67 , F_42 ( V_96 ) | V_102 ) ;
V_100 = F_54 ( F_48 ( V_74 ) ) ;
V_100 &= ~ ( V_142 | V_143 | V_144 ) ;
F_53 ( V_145 L_36 , V_96 ) ;
F_49 ( F_55 ( V_100 ) , V_74 ) ;
F_48 ( V_74 ) ;
F_84 ( & V_2 -> V_133 ) ;
}
static void T_7 F_85 ( struct V_31 * V_13 )
{
F_86 ( V_13 ) ;
F_70 ( V_13 -> V_35 , NULL ) ;
if ( V_13 -> V_35 -> V_38 )
V_13 -> V_35 -> V_38 -> V_147 = V_13 ;
else
V_13 -> V_35 -> V_147 = V_13 ;
}
static int T_7 F_87 ( struct V_31 * V_13 )
{
void T_4 * V_67 ;
struct V_1 * V_2 ;
int V_25 ;
V_67 = F_38 ( V_13 -> V_35 -> V_37 ) ;
V_25 = F_60 ( V_13 , V_67 ) ;
if ( V_25 )
goto V_148;
F_86 ( V_13 ) ;
if ( V_13 -> V_35 -> V_38 ) {
if ( V_13 -> V_35 -> V_38 -> V_147 )
F_53 ( V_149 L_37
L_38 , V_13 ) ;
V_13 -> V_35 -> V_38 -> V_147 = V_13 ;
} else
V_13 -> V_35 -> V_147 = V_13 ;
V_2 = F_22 ( V_13 -> V_35 ) ;
V_2 -> V_18 -> V_150 ( V_2 , V_13 ) ;
F_81 ( V_13 ) ;
return 0 ;
V_148:
return V_25 ;
}
static int T_7 F_88 ( void )
{
int V_25 ;
int V_151 , V_152 , V_35 ;
void T_4 * V_67 ;
void T_4 * V_74 ;
unsigned long V_14 ;
T_8 V_153 , V_154 ;
T_6 V_77 ;
V_25 = - V_155 ;
for ( V_151 = 0 ; V_151 < V_156 -> V_157 ; V_151 ++ ) {
struct V_158 * V_159 = V_160 [ V_151 ] ;
if ( ( V_159 -> type != V_161 ) && ( V_159 -> type != V_162 ) )
continue;
V_67 = F_89 ( V_159 -> V_163 , 1024 * 1024 ) ;
if ( ! V_67 )
goto error;
for ( V_152 = 0 ; V_152 < V_164 ; V_152 ++ ) {
V_14 = V_165 [ V_152 ] | V_166 ;
V_74 = F_43 ( V_67 , V_14 ) ;
V_77 = F_54 ( F_48 ( V_74 ) ) ;
V_153 = ( T_8 ) ( ( V_77 & 0x00FF0000 ) >> 16 ) ;
V_154 = ( T_8 ) ( ( V_77 & 0x0000FF00 ) >> 8 ) ;
if ( V_154 ) {
for ( V_35 = V_153 ; V_35 <= V_154 ; V_35 ++ ) {
V_66 [ V_35 ] . V_67 = V_67 ;
V_66 [ V_35 ] . V_68 = V_152 ;
}
} else {
V_66 [ V_153 ] . V_67 = V_67 ;
V_66 [ V_153 ] . V_68 = V_152 ;
}
}
}
return 0 ;
error:
for ( V_35 = 0 ; V_35 < F_74 ( V_66 ) ; V_35 ++ )
if ( V_66 [ V_35 ] . V_67 )
F_90 ( V_66 [ V_35 ] . V_67 ) ;
return V_25 ;
}
static int T_7 F_91 ( void )
{
int V_25 ;
struct V_31 * V_13 = NULL ;
struct V_167 * V_168 ;
V_25 = F_88 () ;
if ( V_25 )
return V_25 ;
if ( F_62 () )
F_92 () ;
do {
V_13 = F_93 ( V_169 , V_170 , V_13 ) ;
if ( ! V_13 )
break;
if ( ! F_46 ( V_13 -> V_12 ) )
continue;
V_168 = & V_66 [ V_13 -> V_35 -> V_37 ] ;
if ( V_168 -> V_171 ) {
F_85 ( V_13 ) ;
continue;
}
if ( ! V_168 -> V_110 && ! V_172 )
continue;
V_25 = F_87 ( V_13 ) ;
if ( V_25 )
goto error;
} while ( 1 );
V_13 = NULL ;
F_94 (dev) {
struct V_1 * V_2 ;
V_2 = F_20 ( & V_13 -> V_13 ) ;
if ( F_1 ( V_2 ) )
V_13 -> V_13 . V_173 . V_174 = & V_175 ;
}
return V_25 ;
error:
do {
V_13 = F_93 ( V_169 , V_170 , V_13 ) ;
if ( ! V_13 )
break;
if ( ! F_46 ( V_13 -> V_12 ) )
continue;
V_168 = & V_66 [ V_13 -> V_35 -> V_37 ] ;
if ( V_168 -> V_171 ) {
F_95 ( V_13 ) ;
continue;
}
if ( ! V_168 -> V_110 && ! V_172 )
continue;
F_83 ( V_13 ) ;
F_68 ( V_13 ) ;
F_95 ( V_13 ) ;
V_13 -> V_13 . V_173 . V_174 = NULL ;
} while ( 1 );
return V_25 ;
}
static inline int T_7 F_96 ( T_5 V_176 )
{
int V_25 ;
if ( V_114 != V_177 )
return V_114 ;
V_25 = F_34 ( V_176 >> 13 ) ;
if ( V_25 > V_115 )
V_25 = V_115 ;
return V_25 ;
}
static int T_7 F_97 ( void )
{
unsigned long V_178 ;
unsigned V_179 , V_47 ;
int V_180 , V_181 ;
V_179 = V_156 -> V_182 ;
if ( V_179 > V_183 ) {
F_53 ( V_149
L_39
L_40 ,
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
F_53 ( V_149
L_41 ,
V_156 -> V_185 ) ;
return - V_186 ;
}
V_178 = ( ( unsigned long ) V_156 ) + 3 ;
for ( V_47 = 0 ; V_47 < V_179 ; V_47 ++ , V_178 += V_180 )
V_187 [ V_47 ] = (struct V_188 * ) V_178 ;
for ( V_47 = 0 ; V_47 < V_156 -> V_157 ;
V_47 ++ , V_178 += V_181 )
V_160 [ V_47 ] = (struct V_158 * ) V_178 ;
return 0 ;
}
static int T_7 F_98 ( int V_35 , unsigned short V_31 )
{
int V_13 ;
T_6 V_77 ;
if ( V_31 == V_75 ) {
return 1 ;
}
for ( V_13 = 1 ; V_13 < 8 ; V_13 ++ ) {
V_77 = F_99 ( V_35 , V_13 , 0 , 0 ) ;
if ( V_77 != 0xffffffff )
break;
}
return ( V_77 != 0xffffffff ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
T_5 * V_189 ;
unsigned int V_5 ;
V_189 = ( ( T_5 * ) V_2 -> V_109 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_9 ; V_5 ++ ) {
if ( * V_189 != 0x0 )
F_100 ( V_5 , V_2 -> V_11 ) ;
V_189 ++ ;
}
}
static void T_7 F_92 ( void )
{
int V_35 ;
void T_4 * V_74 ;
unsigned long V_110 ;
for ( V_35 = 0 ; V_35 < V_190 ; V_35 ++ ) {
struct V_167 * V_168 = & V_66 [ V_35 ] ;
unsigned short V_191 ;
T_6 V_77 ;
V_77 = F_99 ( V_35 , 0 , 0 , 0 ) ;
V_191 = ( V_77 & 0xFFFF0000 ) >> 16 ;
if ( ! F_46 ( V_191 ) )
continue;
if ( V_168 -> V_171 )
continue;
if ( F_98 ( V_35 , V_191 ) ||
V_172 ) {
V_74 = F_43 ( V_66 [ V_35 ] . V_67 ,
F_41 ( V_35 ) ) ;
V_110 = F_65 ( F_50 ( V_74 ) ) ;
V_110 = V_110 & V_113 ;
V_110 = V_110 & ( ~ V_114 ) ;
V_168 -> V_110 = ( T_5 * ) F_101 ( V_110 ) ;
}
}
return;
}
static int T_7 F_102 ( void )
{
int V_25 ;
F_53 ( V_145 L_42 ) ;
V_25 = F_91 () ;
if ( V_25 ) {
F_53 ( V_30 L_43
L_44 , V_25 ) ;
return V_25 ;
}
return 0 ;
}
int T_7 F_103 ( void )
{
int V_35 ;
void * V_2 ;
int V_192 = 0 ;
unsigned long V_178 ;
unsigned int V_14 , V_193 ;
int V_25 ;
if ( V_194 || V_195 )
return - V_184 ;
if ( ! V_196 )
return - V_184 ;
if ( ! F_104 () )
return - V_184 ;
F_53 ( V_85 L_45 ) ;
V_178 = ( unsigned long ) F_105 ( F_106 () ) ;
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
F_53 ( V_85 L_46
L_47 ) ;
return - V_184 ;
}
V_25 = F_97 () ;
if ( V_25 ) {
F_53 ( V_85 L_48 , V_25 ) ;
return - V_197 ;
}
V_114 = F_96 ( ( F_62 () ?
V_198 : V_199 ) * V_16 ) ;
for ( V_35 = 0 ; V_35 < V_190 ; V_35 ++ ) {
struct V_167 * V_168 = & V_66 [ V_35 ] ;
unsigned short V_191 ;
T_6 V_77 ;
V_77 = F_99 ( V_35 , 0 , 0 , 0 ) ;
V_191 = ( V_77 & 0xFFFF0000 ) >> 16 ;
if ( ! F_46 ( V_191 ) )
continue;
if ( V_168 -> V_171 )
continue;
if ( F_98 ( V_35 , V_191 ) ||
V_172 ) {
if ( ! F_62 () ) {
V_2 = F_107 () ;
if ( ! V_2 )
goto V_200;
V_168 -> V_110 = V_2 ;
}
V_192 = 1 ;
}
}
F_53 ( V_85 L_49 ,
V_192 ? L_50 : L_51 ) ;
if ( V_192 ) {
V_195 = 1 ;
V_201 = 1 ;
F_53 ( V_145 L_52 ) ;
F_53 ( V_145 L_53 ,
V_114 ) ;
V_202 . V_203 . V_204 = F_102 ;
}
return V_192 ;
V_200:
for ( -- V_35 ; V_35 >= 0 ; -- V_35 ) {
struct V_167 * V_168 = & V_66 [ V_35 ] ;
if ( V_168 -> V_110 )
F_108 ( V_168 -> V_110 ) ;
}
return - V_197 ;
}
static int T_7 F_109 ( char * V_205 )
{
unsigned int V_206 ;
unsigned long V_77 ;
T_2 V_207 ;
T_9 V_25 ;
while ( * V_205 ) {
if ( ! strncmp ( V_205 , L_54 , 3 ) )
V_114 = V_208 ;
else if ( ! strncmp ( V_205 , L_55 , 4 ) )
V_114 = V_209 ;
else if ( ! strncmp ( V_205 , L_56 , 4 ) )
V_114 = V_210 ;
else if ( ! strncmp ( V_205 , L_57 , 4 ) )
V_114 = V_211 ;
else if ( ! strncmp ( V_205 , L_58 , 2 ) )
V_114 = V_212 ;
else if ( ! strncmp ( V_205 , L_59 , 2 ) )
V_114 = V_213 ;
else if ( ! strncmp ( V_205 , L_60 , 2 ) )
V_114 = V_214 ;
else if ( ! strncmp ( V_205 , L_61 , 2 ) )
V_114 = V_115 ;
V_207 = strlen ( L_62 ) ;
if ( ! strncmp ( V_205 , L_62 , V_207 ) )
V_172 = 1 ;
V_207 = strlen ( L_63 ) ;
if ( ! strncmp ( V_205 , L_63 , V_207 ) ) {
V_205 += V_207 ;
if ( * V_205 == '=' )
++ V_205 ;
if ( * V_205 == '\0' )
break;
V_25 = F_110 ( V_205 , 0 , & V_77 ) ;
if ( V_25 )
break;
V_206 = V_77 ;
if ( V_206 < V_190 ) {
F_53 ( V_145 L_64
L_65 , V_206 ) ;
V_66 [ V_206 ] . V_171 = 1 ;
}
}
V_205 = strpbrk ( V_205 , L_66 ) ;
if ( ! V_205 )
break;
V_205 ++ ;
}
return 1 ;
}
static void T_7 F_111 ( struct V_31 * V_13 )
{
struct V_1 * V_2 ;
unsigned int V_4 ;
int V_47 ;
V_2 = F_22 ( V_13 -> V_35 ) ;
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ ) {
struct V_215 * V_216 = & V_13 -> V_215 [ V_217 + V_47 ] ;
if ( ! ( V_216 -> V_7 & V_218 ) )
continue;
if ( ! V_216 -> V_90 )
continue;
V_4 = F_112 ( V_216 ) >> V_8 ;
V_4 ++ ;
F_2 ( V_2 , V_216 -> V_90 , V_4 ) ;
}
}
static int T_7 F_113 ( void )
{
struct V_31 * V_13 = NULL ;
struct V_167 * V_168 ;
if ( V_194 || V_219 || ! V_201 )
return - V_184 ;
F_53 ( V_85 L_67 ) ;
do {
V_13 = F_93 ( V_169 , V_170 , V_13 ) ;
if ( ! V_13 )
break;
if ( ! F_46 ( V_13 -> V_12 ) )
continue;
V_168 = & V_66 [ V_13 -> V_35 -> V_37 ] ;
if ( V_168 -> V_171 )
continue;
if ( ! V_168 -> V_110 )
continue;
F_111 ( V_13 ) ;
} while ( 1 );
return 0 ;
}
