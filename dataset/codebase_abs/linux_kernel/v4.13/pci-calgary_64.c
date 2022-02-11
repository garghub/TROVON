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
if ( F_14 ( V_27 < V_28 ) ) {
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
unsigned long V_44 )
{
struct V_1 * V_2 = F_20 ( V_13 ) ;
struct V_39 * V_45 ;
int V_46 ;
if ( ! F_1 ( V_2 ) )
return;
F_24 (sglist, s, nelems, i) {
unsigned int V_4 ;
T_1 V_47 = V_45 -> V_48 ;
unsigned int V_49 = V_45 -> V_50 ;
if ( V_49 == 0 )
break;
V_4 = F_25 ( V_47 , V_49 , V_16 ) ;
F_16 ( V_2 , V_47 , V_4 ) ;
}
}
static int F_26 ( struct V_12 * V_13 , struct V_39 * V_51 ,
int V_41 , enum V_42 V_43 ,
unsigned long V_44 )
{
struct V_1 * V_2 = F_20 ( V_13 ) ;
struct V_39 * V_45 ;
unsigned long V_22 ;
unsigned int V_4 ;
unsigned long V_24 ;
int V_46 ;
F_24 (sg, s, nelems, i) {
F_9 ( ! F_27 ( V_45 ) ) ;
V_22 = ( unsigned long ) F_28 ( V_45 ) ;
V_4 = F_25 ( V_22 , V_45 -> V_52 , V_16 ) ;
V_24 = F_6 ( V_13 , V_2 , V_4 ) ;
if ( V_24 == V_21 ) {
V_45 -> V_50 = 0 ;
goto error;
}
V_45 -> V_48 = ( V_24 << V_8 ) | V_45 -> V_14 ;
F_15 ( V_2 , V_24 , V_4 , V_22 & V_26 , V_43 ) ;
V_45 -> V_50 = V_45 -> V_52 ;
}
return V_41 ;
error:
F_23 ( V_13 , V_51 , V_41 , V_43 , 0 ) ;
F_24 (sg, s, nelems, i) {
V_51 -> V_48 = V_21 ;
V_51 -> V_50 = 0 ;
}
return 0 ;
}
static T_1 F_29 ( struct V_12 * V_13 , struct V_53 * V_53 ,
unsigned long V_14 , T_2 V_54 ,
enum V_42 V_43 ,
unsigned long V_44 )
{
void * V_22 = F_30 ( V_53 ) + V_14 ;
unsigned long V_55 ;
unsigned int V_4 ;
struct V_1 * V_2 = F_20 ( V_13 ) ;
V_55 = ( unsigned long ) V_22 ;
V_4 = F_25 ( V_55 , V_54 , V_16 ) ;
return F_13 ( V_13 , V_2 , V_22 , V_4 , V_43 ) ;
}
static void F_31 ( struct V_12 * V_13 , T_1 V_27 ,
T_2 V_54 , enum V_42 V_43 ,
unsigned long V_44 )
{
struct V_1 * V_2 = F_20 ( V_13 ) ;
unsigned int V_4 ;
V_4 = F_25 ( V_27 , V_54 , V_16 ) ;
F_16 ( V_2 , V_27 , V_4 ) ;
}
static void * F_32 ( struct V_12 * V_13 , T_2 V_54 ,
T_1 * V_56 , T_3 V_57 , unsigned long V_44 )
{
void * V_25 = NULL ;
T_1 V_58 ;
unsigned int V_4 , V_59 ;
struct V_1 * V_2 = F_20 ( V_13 ) ;
V_54 = F_33 ( V_54 ) ;
V_4 = V_54 >> V_8 ;
V_59 = F_34 ( V_54 ) ;
V_57 &= ~ ( V_60 | V_61 | V_62 ) ;
V_25 = ( void * ) F_35 ( V_57 , V_59 ) ;
if ( ! V_25 )
goto error;
memset ( V_25 , 0 , V_54 ) ;
V_58 = F_13 ( V_13 , V_2 , V_25 , V_4 , V_63 ) ;
if ( V_58 == V_21 )
goto free;
* V_56 = V_58 ;
return V_25 ;
free:
F_36 ( ( unsigned long ) V_25 , F_34 ( V_54 ) ) ;
V_25 = NULL ;
error:
return V_25 ;
}
static void F_37 ( struct V_12 * V_13 , T_2 V_54 ,
void * V_22 , T_1 V_56 ,
unsigned long V_44 )
{
unsigned int V_4 ;
struct V_1 * V_2 = F_20 ( V_13 ) ;
V_54 = F_33 ( V_54 ) ;
V_4 = V_54 >> V_8 ;
F_16 ( V_2 , V_56 , V_4 ) ;
F_36 ( ( unsigned long ) V_22 , F_34 ( V_54 ) ) ;
}
static int F_38 ( struct V_12 * V_13 , T_1 V_27 )
{
return V_27 == V_21 ;
}
static inline void T_4 * F_39 ( unsigned char V_64 )
{
return V_65 [ V_64 ] . V_66 ;
}
static inline int F_40 ( unsigned char V_64 )
{
return V_65 [ V_64 ] . V_67 ;
}
static inline unsigned long F_41 ( unsigned char V_64 )
{
T_2 V_68 = F_40 ( V_64 ) ;
return V_69 [ V_68 ] ;
}
static inline unsigned long F_42 ( unsigned char V_64 )
{
T_2 V_68 = F_40 ( V_64 ) ;
return V_70 [ V_68 ] ;
}
static inline unsigned long F_43 ( unsigned char V_64 )
{
T_2 V_68 = F_40 ( V_64 ) ;
return V_71 [ V_68 ] ;
}
static inline void T_4 * F_44 ( void T_4 * V_72 , unsigned long V_14 )
{
unsigned long V_73 = ( ( unsigned long ) V_72 ) | V_14 ;
return ( void T_4 * ) V_73 ;
}
static inline int F_45 ( unsigned short V_12 )
{
return ( V_12 == V_74 ) ;
}
static inline int F_46 ( unsigned short V_12 )
{
return ( V_12 == V_75 ) ;
}
static inline int F_47 ( unsigned short V_12 )
{
return ( F_46 ( V_12 ) || F_45 ( V_12 ) ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
T_5 V_76 ;
T_6 V_77 ;
int V_46 = 0 ;
void T_4 * V_66 = V_2 -> V_66 ;
void T_4 * V_73 ;
V_73 = F_44 ( V_66 , F_43 ( V_2 -> V_36 ) | V_78 ) ;
V_77 = F_49 ( V_73 ) ;
F_50 ( 0 , V_73 ) ;
V_73 = F_44 ( V_66 , F_43 ( V_2 -> V_36 ) | V_79 ) ;
V_76 = F_49 ( V_73 ) ;
V_73 = F_44 ( V_66 , F_41 ( V_2 -> V_36 ) ) ;
do {
V_76 = F_51 ( V_73 ) ;
V_46 ++ ;
} while ( ( V_76 & 0xff ) != 0xff && V_46 < 100 );
if ( V_46 == 100 )
F_11 ( L_6 ) ;
V_73 = F_44 ( V_66 , F_42 ( V_2 -> V_36 ) ) ;
F_52 ( V_2 -> V_80 , V_73 ) ;
V_73 = F_44 ( V_66 , F_43 ( V_2 -> V_36 ) | V_78 ) ;
F_50 ( V_77 , V_73 ) ;
( void ) F_49 ( V_73 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
void T_4 * V_66 = V_2 -> V_66 ;
void T_4 * V_73 ;
T_5 V_81 ;
T_6 V_76 ;
int V_46 = 0 ;
int V_82 = 1 ;
unsigned char V_35 = V_2 -> V_36 ;
V_83:
F_54 ( V_84 L_7
L_8 , V_35 , V_82 ) ;
V_73 = F_44 ( V_66 , F_43 ( V_35 ) | V_85 ) ;
V_76 = F_55 ( F_49 ( V_73 ) ) ;
F_54 ( V_84 L_9 , V_76 , V_73 ) ;
V_76 |= V_86 ;
F_54 ( V_84 L_10 , V_76 , V_73 ) ;
F_50 ( F_56 ( V_76 ) , V_73 ) ;
F_54 ( V_84 L_11 ) ;
V_73 = F_44 ( V_66 , F_41 ( V_35 ) ) ;
do {
V_81 = F_51 ( V_73 ) ;
V_46 ++ ;
} while ( ( V_81 & 0xff ) != 0xff && V_46 < 100 );
if ( V_46 == 100 )
F_11 ( L_12 ) ;
V_73 = F_44 ( V_66 , F_43 ( V_35 ) | V_87 ) ;
V_76 = F_55 ( F_49 ( V_73 ) ) ;
F_54 ( V_84 L_13 , V_76 , V_73 ) ;
if ( V_76 & V_88 ) {
if ( ++ V_82 < 100 )
goto V_83;
else {
F_11 ( L_14 ) ;
return;
}
}
V_73 = F_44 ( V_66 , F_43 ( V_35 ) | V_85 ) ;
F_54 ( V_84 L_15 , V_73 ) ;
V_76 = F_55 ( F_49 ( V_73 ) ) ;
F_54 ( V_84 L_16 , V_76 , V_73 ) ;
V_73 = F_44 ( V_66 , F_43 ( V_35 ) | V_87 ) ;
V_76 = F_55 ( F_49 ( V_73 ) ) ;
F_54 ( V_84 L_17 , V_76 , V_73 ) ;
F_54 ( V_84 L_18 ) ;
V_73 = F_44 ( V_66 , F_42 ( V_35 ) ) ;
F_52 ( V_2 -> V_80 , V_73 ) ;
F_54 ( V_84 L_19 ) ;
V_73 = F_44 ( V_66 , F_43 ( V_35 ) | V_85 ) ;
V_76 = F_55 ( F_49 ( V_73 ) ) ;
F_54 ( V_84 L_20 , V_76 , V_73 ) ;
F_54 ( V_84 L_21 ) ;
V_73 = F_44 ( V_66 , F_43 ( V_35 ) | V_85 ) ;
V_76 = 0 ;
F_54 ( V_84 L_22 , V_76 , V_73 ) ;
F_50 ( F_56 ( V_76 ) , V_73 ) ;
V_76 = F_55 ( F_49 ( V_73 ) ) ;
F_54 ( V_84 L_23 , V_76 , V_73 ) ;
}
static void T_7 F_57 ( struct V_31 * V_13 , T_5 V_89 ,
T_5 V_90 )
{
unsigned int V_91 ;
V_90 = V_90 | 0xfffff ;
V_90 ++ ;
V_91 = ( ( V_90 - V_89 ) >> V_8 ) ;
F_2 ( F_22 ( V_13 -> V_35 ) , V_89 , V_91 ) ;
}
static void T_7 F_58 ( struct V_31 * V_13 )
{
void T_4 * V_73 ;
T_5 V_92 , V_93 , V_94 ;
T_5 V_89 , V_90 ;
struct V_1 * V_2 = F_22 ( V_13 -> V_35 ) ;
unsigned char V_95 = V_13 -> V_35 -> V_37 ;
void T_4 * V_66 = V_2 -> V_66 ;
V_73 = F_44 ( V_66 , F_43 ( V_95 ) | V_96 ) ;
V_92 = F_55 ( F_49 ( V_73 ) ) ;
V_73 = F_44 ( V_66 , F_43 ( V_95 ) | V_97 ) ;
V_93 = F_55 ( F_49 ( V_73 ) ) ;
V_73 = F_44 ( V_66 , F_43 ( V_95 ) | V_98 ) ;
V_94 = F_55 ( F_49 ( V_73 ) ) ;
V_89 = ( V_93 << 32 ) | V_92 ;
V_90 = V_94 ;
F_57 ( V_13 , V_89 , V_90 ) ;
}
static void T_7 F_59 ( struct V_31 * V_13 )
{
void T_4 * V_73 ;
T_6 V_99 ;
T_5 V_92 , V_93 , V_94 , V_100 ;
T_5 V_89 , V_90 ;
struct V_1 * V_2 = F_22 ( V_13 -> V_35 ) ;
unsigned char V_95 = V_13 -> V_35 -> V_37 ;
void T_4 * V_66 = V_2 -> V_66 ;
V_73 = F_44 ( V_66 , F_43 ( V_95 ) | V_101 ) ;
V_99 = F_55 ( F_49 ( V_73 ) ) ;
if ( ! ( V_99 & V_102 ) )
return;
V_73 = F_44 ( V_66 , F_43 ( V_95 ) | V_103 ) ;
V_92 = F_55 ( F_49 ( V_73 ) ) ;
V_73 = F_44 ( V_66 , F_43 ( V_95 ) | V_104 ) ;
V_93 = F_55 ( F_49 ( V_73 ) ) ;
V_73 = F_44 ( V_66 , F_43 ( V_95 ) | V_105 ) ;
V_94 = F_55 ( F_49 ( V_73 ) ) ;
V_73 = F_44 ( V_66 , F_43 ( V_95 ) | V_106 ) ;
V_100 = F_55 ( F_49 ( V_73 ) ) ;
V_89 = ( V_93 << 32 ) | V_92 ;
V_90 = ( V_100 << 32 ) | V_94 ;
F_57 ( V_13 , V_89 , V_90 ) ;
}
static void T_7 F_60 ( struct V_31 * V_13 )
{
unsigned int V_4 ;
T_5 V_89 ;
struct V_1 * V_2 = F_22 ( V_13 -> V_35 ) ;
F_2 ( V_2 , V_21 , V_29 ) ;
if ( F_46 ( V_13 -> V_12 ) ) {
V_89 = ( 640 * 1024 ) ;
V_4 = ( ( 1024 - 640 ) * 1024 ) >> V_8 ;
} else {
V_89 = 0 ;
V_4 = ( 1 * 1024 * 1024 ) >> V_8 ;
}
F_2 ( V_2 , V_89 , V_4 ) ;
F_58 ( V_13 ) ;
F_59 ( V_13 ) ;
}
static int T_7 F_61 ( struct V_31 * V_13 , void T_4 * V_66 )
{
T_5 V_81 ;
T_5 V_107 ;
void T_4 * V_73 ;
int V_25 ;
struct V_1 * V_2 ;
V_25 = F_62 ( V_13 , V_66 ) ;
if ( V_25 )
return V_25 ;
V_2 = F_22 ( V_13 -> V_35 ) ;
V_2 -> V_108 = ( unsigned long ) V_65 [ V_13 -> V_35 -> V_37 ] . V_109 ;
if ( F_63 () )
F_64 ( V_2 ) ;
else
F_18 ( V_2 , 0 , V_2 -> V_9 ) ;
if ( F_46 ( V_13 -> V_12 ) )
V_2 -> V_18 = & V_110 ;
else if ( F_45 ( V_13 -> V_12 ) )
V_2 -> V_18 = & V_111 ;
else
F_65 () ;
F_60 ( V_13 ) ;
V_73 = F_44 ( V_66 , F_42 ( V_13 -> V_35 -> V_37 ) ) ;
V_81 = F_66 ( F_51 ( V_73 ) ) ;
V_81 &= ~ V_112 ;
V_107 = ( T_5 ) F_67 ( V_2 -> V_108 ) ;
V_81 |= V_107 ;
F_9 ( V_113 > V_114 ) ;
V_81 |= ( T_5 ) V_113 ;
V_2 -> V_80 = F_68 ( V_81 ) ;
F_52 ( V_2 -> V_80 , V_73 ) ;
F_51 ( V_73 ) ;
return 0 ;
}
static void T_7 F_69 ( struct V_31 * V_13 )
{
T_5 V_81 ;
struct V_1 * V_2 = F_22 ( V_13 -> V_35 ) ;
void T_4 * V_73 ;
unsigned int V_115 ;
V_73 = F_44 ( V_2 -> V_66 , F_42 ( V_13 -> V_35 -> V_37 ) ) ;
V_81 = F_66 ( F_51 ( V_73 ) ) ;
V_81 &= ~ V_112 ;
F_52 ( F_68 ( V_81 ) , V_73 ) ;
F_51 ( V_73 ) ;
V_115 = V_2 -> V_9 / V_116 ;
F_36 ( ( unsigned long ) V_2 -> V_11 , F_34 ( V_115 ) ) ;
V_2 -> V_11 = NULL ;
F_70 ( V_2 ) ;
F_71 ( V_13 -> V_35 , NULL ) ;
V_65 [ V_13 -> V_35 -> V_37 ] . V_109 = NULL ;
}
static void F_72 ( struct V_1 * V_2 )
{
void T_4 * V_66 = V_2 -> V_66 ;
void T_4 * V_73 ;
T_6 V_117 , V_118 ;
V_73 = F_44 ( V_66 , F_43 ( V_2 -> V_36 ) | V_119 ) ;
V_117 = F_55 ( F_49 ( V_73 ) ) ;
V_73 = F_44 ( V_66 , F_43 ( V_2 -> V_36 ) | V_79 ) ;
V_118 = F_55 ( F_49 ( V_73 ) ) ;
F_73 ( L_24 ,
V_2 -> V_36 , V_117 , V_118 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
void T_4 * V_66 = V_2 -> V_66 ;
T_6 V_117 , V_120 , V_118 , V_121 , V_122 ;
void T_4 * V_73 ;
unsigned long V_123 = F_43 ( V_2 -> V_36 ) ;
unsigned long V_124 ;
T_6 V_125 [ 7 ] ;
int V_46 ;
V_73 = F_44 ( V_66 , V_123 | V_119 ) ;
V_117 = F_55 ( F_49 ( V_73 ) ) ;
V_73 = F_44 ( V_66 , V_123 | V_79 ) ;
V_118 = F_55 ( F_49 ( V_73 ) ) ;
V_73 = F_44 ( V_66 , V_123 | 0x290 ) ;
V_120 = F_55 ( F_49 ( V_73 ) ) ;
V_73 = F_44 ( V_66 , V_123 | 0x800 ) ;
V_121 = F_55 ( F_49 ( V_73 ) ) ;
F_73 ( L_25 , V_2 -> V_36 ) ;
F_73 ( L_26 ,
V_117 , V_118 , V_120 , V_121 ) ;
F_73 ( L_27 ) ;
for ( V_46 = 0 ; V_46 < F_75 ( V_125 ) ; V_46 ++ ) {
V_124 = ( 0x810 + ( V_46 * 0x10 ) ) ;
V_73 = F_44 ( V_66 , V_123 | V_124 ) ;
V_125 [ V_46 ] = F_55 ( F_49 ( V_73 ) ) ;
F_76 ( L_28 , V_125 [ V_46 ] , V_124 ) ;
}
F_76 ( L_29 ) ;
V_73 = F_44 ( V_66 , V_123 | V_126 ) ;
V_122 = F_55 ( F_49 ( V_73 ) ) ;
F_54 ( V_127 L_30 , V_122 ,
V_126 ) ;
}
static void F_77 ( unsigned long V_128 )
{
struct V_31 * V_13 = (struct V_31 * ) V_128 ;
struct V_1 * V_2 = F_22 ( V_13 -> V_35 ) ;
void T_4 * V_66 = V_2 -> V_66 ;
T_6 V_99 ;
void T_4 * V_73 ;
V_73 = F_44 ( V_66 , F_43 ( V_2 -> V_36 ) | V_119 ) ;
V_99 = F_55 ( F_49 ( V_73 ) ) ;
if ( V_99 & V_129 ) {
V_2 -> V_18 -> V_130 ( V_2 ) ;
F_50 ( 0 , V_73 ) ;
V_73 = F_44 ( V_66 , F_43 ( V_2 -> V_36 ) |
V_101 ) ;
V_99 = F_55 ( F_49 ( V_73 ) ) ;
V_99 |= V_131 ;
F_50 ( F_56 ( V_99 ) , V_73 ) ;
F_49 ( V_73 ) ;
} else {
F_78 ( & V_2 -> V_132 , V_133 + 2 * V_134 ) ;
}
}
static void T_7 F_79 ( void T_4 * V_66 ,
unsigned char V_95 , unsigned long V_135 )
{
T_5 V_81 ;
void T_4 * V_73 ;
unsigned int V_136 = ~ 0 ;
T_5 V_137 ;
switch ( F_40 ( V_95 ) ) {
case 0 : V_136 = ( 63 - 19 ) ;
break;
case 1 : V_136 = ( 63 - 23 ) ;
break;
case 2 : V_136 = ( 63 - 27 ) ;
break;
case 3 : V_136 = ( 63 - 35 ) ;
break;
default:
F_9 ( F_40 ( V_95 ) ) ;
}
V_73 = F_44 ( V_66 , V_138 ) ;
V_81 = F_66 ( F_51 ( V_73 ) ) ;
V_137 = ~ ( 0xFUL << V_136 ) ;
V_81 &= V_137 ;
V_81 |= ( V_135 << V_136 ) ;
F_52 ( F_68 ( V_81 ) , V_73 ) ;
F_51 ( V_73 ) ;
}
static void T_7 F_80 ( struct V_1 * V_2 , struct V_31 * V_13 )
{
unsigned char V_95 = V_13 -> V_35 -> V_37 ;
void T_4 * V_66 = V_2 -> V_66 ;
void T_4 * V_73 ;
T_6 V_76 ;
V_73 = F_44 ( V_66 , F_43 ( V_95 ) | V_139 ) ;
V_76 = F_56 ( F_49 ( V_73 ) ) ;
V_76 |= 0x00800000 ;
F_50 ( F_56 ( V_76 ) , V_73 ) ;
}
static void T_7 F_81 ( struct V_1 * V_2 , struct V_31 * V_13 )
{
unsigned char V_95 = V_13 -> V_35 -> V_37 ;
if ( F_46 ( V_13 -> V_12 ) && ( V_95 == 1 ) )
F_79 ( V_2 -> V_66 , V_95 ,
V_140 ) ;
}
static void T_7 F_82 ( struct V_31 * V_13 )
{
T_6 V_99 ;
unsigned char V_95 ;
void T_4 * V_73 ;
void T_4 * V_66 ;
struct V_1 * V_2 ;
V_95 = V_13 -> V_35 -> V_37 ;
V_2 = F_22 ( V_13 -> V_35 ) ;
V_66 = V_2 -> V_66 ;
V_73 = F_44 ( V_66 , F_43 ( V_95 ) | V_101 ) ;
V_99 = F_55 ( F_49 ( V_73 ) ) ;
V_99 |= V_141 | V_142 | V_143 ;
F_54 ( V_144 L_31 ,
( V_13 -> V_12 == V_75 ) ?
L_32 : L_33 , V_95 ) ;
F_54 ( V_144 L_34
L_35 ) ;
F_50 ( F_56 ( V_99 ) , V_73 ) ;
F_49 ( V_73 ) ;
F_83 ( & V_2 -> V_132 , & F_77 ,
( unsigned long ) V_13 ) ;
F_78 ( & V_2 -> V_132 , V_133 ) ;
}
static void T_7 F_84 ( struct V_31 * V_13 )
{
T_6 V_99 ;
unsigned char V_95 ;
void T_4 * V_73 ;
void T_4 * V_66 ;
struct V_1 * V_2 ;
V_95 = V_13 -> V_35 -> V_37 ;
V_2 = F_22 ( V_13 -> V_35 ) ;
V_66 = V_2 -> V_66 ;
V_73 = F_44 ( V_66 , F_43 ( V_95 ) | V_101 ) ;
V_99 = F_55 ( F_49 ( V_73 ) ) ;
V_99 &= ~ ( V_141 | V_142 | V_143 ) ;
F_54 ( V_144 L_36 , V_95 ) ;
F_50 ( F_56 ( V_99 ) , V_73 ) ;
F_49 ( V_73 ) ;
F_85 ( & V_2 -> V_132 ) ;
}
static void T_7 F_86 ( struct V_31 * V_13 )
{
F_87 ( V_13 ) ;
F_71 ( V_13 -> V_35 , NULL ) ;
if ( V_13 -> V_35 -> V_38 )
V_13 -> V_35 -> V_38 -> V_145 = V_13 ;
else
V_13 -> V_35 -> V_145 = V_13 ;
}
static int T_7 F_88 ( struct V_31 * V_13 )
{
void T_4 * V_66 ;
struct V_1 * V_2 ;
int V_25 ;
V_66 = F_39 ( V_13 -> V_35 -> V_37 ) ;
V_25 = F_61 ( V_13 , V_66 ) ;
if ( V_25 )
goto V_146;
F_87 ( V_13 ) ;
if ( V_13 -> V_35 -> V_38 ) {
if ( V_13 -> V_35 -> V_38 -> V_145 )
F_54 ( V_147 L_37
L_38 , V_13 ) ;
V_13 -> V_35 -> V_38 -> V_145 = V_13 ;
} else
V_13 -> V_35 -> V_145 = V_13 ;
V_2 = F_22 ( V_13 -> V_35 ) ;
V_2 -> V_18 -> V_148 ( V_2 , V_13 ) ;
F_82 ( V_13 ) ;
return 0 ;
V_146:
return V_25 ;
}
static int T_7 F_89 ( void )
{
int V_25 ;
int V_149 , V_150 , V_35 ;
void T_4 * V_66 ;
void T_4 * V_73 ;
unsigned long V_14 ;
T_8 V_151 , V_152 ;
T_6 V_76 ;
V_25 = - V_153 ;
for ( V_149 = 0 ; V_149 < V_154 -> V_155 ; V_149 ++ ) {
struct V_156 * V_157 = V_158 [ V_149 ] ;
if ( ( V_157 -> type != V_159 ) && ( V_157 -> type != V_160 ) )
continue;
V_66 = F_90 ( V_157 -> V_161 , 1024 * 1024 ) ;
if ( ! V_66 )
goto error;
for ( V_150 = 0 ; V_150 < V_162 ; V_150 ++ ) {
V_14 = V_163 [ V_150 ] | V_164 ;
V_73 = F_44 ( V_66 , V_14 ) ;
V_76 = F_55 ( F_49 ( V_73 ) ) ;
V_151 = ( T_8 ) ( ( V_76 & 0x00FF0000 ) >> 16 ) ;
V_152 = ( T_8 ) ( ( V_76 & 0x0000FF00 ) >> 8 ) ;
if ( V_152 ) {
for ( V_35 = V_151 ; V_35 <= V_152 ; V_35 ++ ) {
V_65 [ V_35 ] . V_66 = V_66 ;
V_65 [ V_35 ] . V_67 = V_150 ;
}
} else {
V_65 [ V_151 ] . V_66 = V_66 ;
V_65 [ V_151 ] . V_67 = V_150 ;
}
}
}
return 0 ;
error:
for ( V_35 = 0 ; V_35 < F_75 ( V_65 ) ; V_35 ++ )
if ( V_65 [ V_35 ] . V_66 )
F_91 ( V_65 [ V_35 ] . V_66 ) ;
return V_25 ;
}
static int T_7 F_92 ( void )
{
int V_25 ;
struct V_31 * V_13 = NULL ;
struct V_165 * V_166 ;
V_25 = F_89 () ;
if ( V_25 )
return V_25 ;
if ( F_63 () )
F_93 () ;
do {
V_13 = F_94 ( V_167 , V_168 , V_13 ) ;
if ( ! V_13 )
break;
if ( ! F_47 ( V_13 -> V_12 ) )
continue;
V_166 = & V_65 [ V_13 -> V_35 -> V_37 ] ;
if ( V_166 -> V_169 ) {
F_86 ( V_13 ) ;
continue;
}
if ( ! V_166 -> V_109 && ! V_170 )
continue;
V_25 = F_88 ( V_13 ) ;
if ( V_25 )
goto error;
} while ( 1 );
V_13 = NULL ;
F_95 (dev) {
struct V_1 * V_2 ;
V_2 = F_20 ( & V_13 -> V_13 ) ;
if ( F_1 ( V_2 ) )
V_13 -> V_13 . V_171 = & V_172 ;
}
return V_25 ;
error:
do {
V_13 = F_94 ( V_167 , V_168 , V_13 ) ;
if ( ! V_13 )
break;
if ( ! F_47 ( V_13 -> V_12 ) )
continue;
V_166 = & V_65 [ V_13 -> V_35 -> V_37 ] ;
if ( V_166 -> V_169 ) {
F_96 ( V_13 ) ;
continue;
}
if ( ! V_166 -> V_109 && ! V_170 )
continue;
F_84 ( V_13 ) ;
F_69 ( V_13 ) ;
F_96 ( V_13 ) ;
V_13 -> V_13 . V_171 = NULL ;
} while ( 1 );
return V_25 ;
}
static inline int T_7 F_97 ( void )
{
int V_25 ;
if ( V_113 != V_173 )
return V_113 ;
if ( F_63 () && V_174 ) {
V_25 = F_34 ( ( V_174 * V_16 ) >> 13 ) ;
if ( V_25 > V_114 )
V_25 = V_114 ;
} else {
V_25 = V_114 ;
}
return V_25 ;
}
static int T_7 F_98 ( void )
{
unsigned long V_175 ;
unsigned V_176 , V_46 ;
int V_177 , V_178 ;
V_176 = V_154 -> V_179 ;
if ( V_176 > V_180 ) {
F_54 ( V_147
L_39
L_40 ,
V_180 , V_176 ) ;
return - V_181 ;
}
switch ( V_154 -> V_182 ) {
case 2 :
V_177 = 11 ;
V_178 = 13 ;
break;
case 3 :
V_177 = 12 ;
V_178 = 15 ;
break;
default:
F_54 ( V_147
L_41 ,
V_154 -> V_182 ) ;
return - V_183 ;
}
V_175 = ( ( unsigned long ) V_154 ) + 3 ;
for ( V_46 = 0 ; V_46 < V_176 ; V_46 ++ , V_175 += V_177 )
V_184 [ V_46 ] = (struct V_185 * ) V_175 ;
for ( V_46 = 0 ; V_46 < V_154 -> V_155 ;
V_46 ++ , V_175 += V_178 )
V_158 [ V_46 ] = (struct V_156 * ) V_175 ;
return 0 ;
}
static int T_7 F_99 ( int V_35 , unsigned short V_31 )
{
int V_13 ;
T_6 V_76 ;
if ( V_31 == V_74 ) {
return 1 ;
}
for ( V_13 = 1 ; V_13 < 8 ; V_13 ++ ) {
V_76 = F_100 ( V_35 , V_13 , 0 , 0 ) ;
if ( V_76 != 0xffffffff )
break;
}
return ( V_76 != 0xffffffff ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
T_5 * V_186 ;
unsigned int V_5 ;
V_186 = ( ( T_5 * ) V_2 -> V_108 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_9 ; V_5 ++ ) {
if ( * V_186 != 0x0 )
F_101 ( V_5 , V_2 -> V_11 ) ;
V_186 ++ ;
}
}
static void T_7 F_93 ( void )
{
int V_35 ;
void T_4 * V_73 ;
unsigned long V_109 ;
for ( V_35 = 0 ; V_35 < V_187 ; V_35 ++ ) {
struct V_165 * V_166 = & V_65 [ V_35 ] ;
unsigned short V_188 ;
T_6 V_76 ;
V_76 = F_100 ( V_35 , 0 , 0 , 0 ) ;
V_188 = ( V_76 & 0xFFFF0000 ) >> 16 ;
if ( ! F_47 ( V_188 ) )
continue;
if ( V_166 -> V_169 )
continue;
if ( F_99 ( V_35 , V_188 ) ||
V_170 ) {
V_73 = F_44 ( V_65 [ V_35 ] . V_66 ,
F_42 ( V_35 ) ) ;
V_109 = F_66 ( F_51 ( V_73 ) ) ;
V_109 = V_109 & V_112 ;
V_109 = V_109 & ( ~ V_113 ) ;
V_166 -> V_109 = ( T_5 * ) F_102 ( V_109 ) ;
}
}
return;
}
static int T_7 F_103 ( void )
{
int V_25 ;
F_54 ( V_144 L_42 ) ;
V_25 = F_92 () ;
if ( V_25 ) {
F_54 ( V_30 L_43
L_44 , V_25 ) ;
return V_25 ;
}
return 0 ;
}
int T_7 F_104 ( void )
{
int V_35 ;
void * V_2 ;
int V_189 = 0 ;
unsigned long V_175 ;
unsigned int V_14 , V_190 ;
int V_25 ;
if ( V_191 || V_192 )
return - V_181 ;
if ( ! V_193 )
return - V_181 ;
if ( ! F_105 () )
return - V_181 ;
F_54 ( V_84 L_45 ) ;
V_175 = ( unsigned long ) F_106 ( F_107 () ) ;
V_154 = NULL ;
V_190 = 0 ;
V_14 = 0x180 ;
while ( V_14 > V_190 ) {
if ( * ( ( unsigned short * ) ( V_175 + V_14 + 2 ) ) == 0x4752 ) {
V_154 = (struct V_154 * ) ( V_175 + V_14 + 4 ) ;
break;
}
V_190 = V_14 ;
V_14 = * ( ( unsigned short * ) ( V_175 + V_14 ) ) ;
}
if ( ! V_154 ) {
F_54 ( V_84 L_46
L_47 ) ;
return - V_181 ;
}
V_25 = F_98 () ;
if ( V_25 ) {
F_54 ( V_84 L_48 , V_25 ) ;
return - V_194 ;
}
V_113 = F_97 () ;
for ( V_35 = 0 ; V_35 < V_187 ; V_35 ++ ) {
struct V_165 * V_166 = & V_65 [ V_35 ] ;
unsigned short V_188 ;
T_6 V_76 ;
V_76 = F_100 ( V_35 , 0 , 0 , 0 ) ;
V_188 = ( V_76 & 0xFFFF0000 ) >> 16 ;
if ( ! F_47 ( V_188 ) )
continue;
if ( V_166 -> V_169 )
continue;
if ( F_99 ( V_35 , V_188 ) ||
V_170 ) {
if ( ! F_63 () ) {
V_2 = F_108 () ;
if ( ! V_2 )
goto V_195;
V_166 -> V_109 = V_2 ;
}
V_189 = 1 ;
}
}
F_54 ( V_84 L_49 ,
V_189 ? L_50 : L_51 ) ;
if ( V_189 ) {
V_192 = 1 ;
V_196 = 1 ;
F_54 ( V_144 L_52 ) ;
F_54 ( V_144 L_53 ,
V_113 ) ;
V_197 . V_198 . V_199 = F_103 ;
}
return V_189 ;
V_195:
for ( -- V_35 ; V_35 >= 0 ; -- V_35 ) {
struct V_165 * V_166 = & V_65 [ V_35 ] ;
if ( V_166 -> V_109 )
F_109 ( V_166 -> V_109 ) ;
}
return - V_194 ;
}
static int T_7 F_110 ( char * V_200 )
{
unsigned int V_201 ;
unsigned long V_76 ;
T_2 V_202 ;
T_9 V_25 ;
while ( * V_200 ) {
if ( ! strncmp ( V_200 , L_54 , 3 ) )
V_113 = V_203 ;
else if ( ! strncmp ( V_200 , L_55 , 4 ) )
V_113 = V_204 ;
else if ( ! strncmp ( V_200 , L_56 , 4 ) )
V_113 = V_205 ;
else if ( ! strncmp ( V_200 , L_57 , 4 ) )
V_113 = V_206 ;
else if ( ! strncmp ( V_200 , L_58 , 2 ) )
V_113 = V_207 ;
else if ( ! strncmp ( V_200 , L_59 , 2 ) )
V_113 = V_208 ;
else if ( ! strncmp ( V_200 , L_60 , 2 ) )
V_113 = V_209 ;
else if ( ! strncmp ( V_200 , L_61 , 2 ) )
V_113 = V_114 ;
V_202 = strlen ( L_62 ) ;
if ( ! strncmp ( V_200 , L_62 , V_202 ) )
V_170 = 1 ;
V_202 = strlen ( L_63 ) ;
if ( ! strncmp ( V_200 , L_63 , V_202 ) ) {
V_200 += V_202 ;
if ( * V_200 == '=' )
++ V_200 ;
if ( * V_200 == '\0' )
break;
V_25 = F_111 ( V_200 , 0 , & V_76 ) ;
if ( V_25 )
break;
V_201 = V_76 ;
if ( V_201 < V_187 ) {
F_54 ( V_144 L_64
L_65 , V_201 ) ;
V_65 [ V_201 ] . V_169 = 1 ;
}
}
V_200 = strpbrk ( V_200 , L_66 ) ;
if ( ! V_200 )
break;
V_200 ++ ;
}
return 1 ;
}
static void T_7 F_112 ( struct V_31 * V_13 )
{
struct V_1 * V_2 ;
unsigned int V_4 ;
int V_46 ;
V_2 = F_22 ( V_13 -> V_35 ) ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
struct V_210 * V_211 = & V_13 -> V_210 [ V_212 + V_46 ] ;
if ( ! ( V_211 -> V_7 & V_213 ) )
continue;
if ( ! V_211 -> V_89 )
continue;
V_4 = F_113 ( V_211 ) >> V_8 ;
V_4 ++ ;
F_2 ( V_2 , V_211 -> V_89 , V_4 ) ;
}
}
static int T_7 F_114 ( void )
{
struct V_31 * V_13 = NULL ;
struct V_165 * V_166 ;
if ( V_191 || V_214 || ! V_196 )
return - V_181 ;
F_54 ( V_84 L_67 ) ;
do {
V_13 = F_94 ( V_167 , V_168 , V_13 ) ;
if ( ! V_13 )
break;
if ( ! F_47 ( V_13 -> V_12 ) )
continue;
V_166 = & V_65 [ V_13 -> V_35 -> V_37 ] ;
if ( V_166 -> V_169 )
continue;
if ( ! V_166 -> V_109 )
continue;
F_112 ( V_13 ) ;
} while ( 1 );
return 0 ;
}
