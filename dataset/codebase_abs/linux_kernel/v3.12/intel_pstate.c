static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( ( V_3 ) V_1 * ( V_3 ) V_2 ) >> V_4 ;
}
static inline T_1 F_2 ( T_1 V_1 , T_1 V_2 )
{
return F_3 ( ( V_3 ) V_1 << V_4 , ( V_3 ) V_2 ) ;
}
static inline void F_4 ( struct V_5 * V_6 , int V_7 , int V_8 ,
int V_9 , int V_10 ) {
V_6 -> V_7 = V_7 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_10 = F_5 ( V_10 ) ;
V_6 -> V_11 = V_7 - V_8 ;
}
static inline void F_6 ( struct V_5 * V_6 , int V_12 )
{
V_6 -> V_13 = F_2 ( F_5 ( V_12 ) , F_5 ( 100 ) ) ;
}
static inline void F_7 ( struct V_5 * V_6 , int V_12 )
{
V_6 -> V_14 = F_2 ( F_5 ( V_12 ) , F_5 ( 100 ) ) ;
}
static inline void F_8 ( struct V_5 * V_6 , int V_12 )
{
V_6 -> V_15 = F_2 ( F_5 ( V_12 ) , F_5 ( 100 ) ) ;
}
static signed int F_9 ( struct V_5 * V_6 , T_1 V_8 )
{
signed int V_16 ;
T_1 V_17 , V_18 , V_19 ;
T_1 V_20 ;
V_19 = F_5 ( V_6 -> V_7 ) - V_8 ;
if ( abs ( V_19 ) <= F_5 ( V_6 -> V_9 ) )
return 0 ;
V_17 = F_1 ( V_6 -> V_13 , V_19 ) ;
V_6 -> V_10 += V_19 ;
V_20 = F_5 ( 30 ) ;
if ( V_6 -> V_10 > V_20 )
V_6 -> V_10 = V_20 ;
if ( V_6 -> V_10 < - V_20 )
V_6 -> V_10 = - V_20 ;
V_18 = F_1 ( V_6 -> V_15 , V_19 - V_6 -> V_11 ) ;
V_6 -> V_11 = V_19 ;
V_16 = V_17 + F_1 ( V_6 -> V_10 , V_6 -> V_14 ) + V_18 ;
return ( signed int ) F_10 ( V_16 ) ;
}
static inline void F_11 ( struct V_21 * V_22 )
{
F_6 ( & V_22 -> V_6 , V_22 -> V_23 -> V_24 ) ;
F_8 ( & V_22 -> V_6 , V_22 -> V_23 -> V_25 ) ;
F_7 ( & V_22 -> V_6 , V_22 -> V_23 -> V_26 ) ;
F_4 ( & V_22 -> V_6 ,
V_22 -> V_23 -> V_7 ,
100 ,
V_22 -> V_23 -> V_9 ,
0 ) ;
}
static inline void F_12 ( void )
{
unsigned int V_22 ;
F_13 (cpu) {
if ( V_27 [ V_22 ] )
F_11 ( V_27 [ V_22 ] ) ;
}
}
static int F_14 ( void * V_28 , T_2 V_29 )
{
* ( V_30 * ) V_28 = V_29 ;
F_12 () ;
return 0 ;
}
static int F_15 ( void * V_28 , T_2 * V_29 )
{
* V_29 = * ( V_30 * ) V_28 ;
return 0 ;
}
static void F_16 ( void )
{
int V_31 = 0 ;
V_32 = F_17 ( L_1 , NULL ) ;
if ( F_18 ( V_32 ) )
return;
while ( V_33 [ V_31 ] . V_34 ) {
F_19 ( V_33 [ V_31 ] . V_34 , 0660 ,
V_32 , V_33 [ V_31 ] . V_35 ,
& V_36 ) ;
V_31 ++ ;
}
}
static T_3 F_20 ( struct V_37 * V_38 , struct V_39 * V_40 ,
const char * V_41 , T_4 V_42 )
{
unsigned int V_43 ;
int V_44 ;
V_44 = sscanf ( V_41 , L_2 , & V_43 ) ;
if ( V_44 != 1 )
return - V_45 ;
V_46 . V_47 = F_21 ( int , V_43 , 0 , 1 ) ;
return V_42 ;
}
static T_3 F_22 ( struct V_37 * V_38 , struct V_39 * V_40 ,
const char * V_41 , T_4 V_42 )
{
unsigned int V_43 ;
int V_44 ;
V_44 = sscanf ( V_41 , L_2 , & V_43 ) ;
if ( V_44 != 1 )
return - V_45 ;
V_46 . V_48 = F_21 ( int , V_43 , 0 , 100 ) ;
V_46 . V_49 = F_23 ( V_46 . V_50 , V_46 . V_48 ) ;
V_46 . V_51 = F_2 ( F_5 ( V_46 . V_49 ) , F_5 ( 100 ) ) ;
return V_42 ;
}
static T_3 F_24 ( struct V_37 * V_38 , struct V_39 * V_40 ,
const char * V_41 , T_4 V_42 )
{
unsigned int V_43 ;
int V_44 ;
V_44 = sscanf ( V_41 , L_2 , & V_43 ) ;
if ( V_44 != 1 )
return - V_45 ;
V_46 . V_52 = F_21 ( int , V_43 , 0 , 100 ) ;
V_46 . V_53 = F_2 ( F_5 ( V_46 . V_52 ) , F_5 ( 100 ) ) ;
return V_42 ;
}
static void F_25 ( void )
{
int V_54 ;
V_55 = F_26 ( L_3 ,
& V_56 . V_57 -> V_58 ) ;
F_27 ( ! V_55 ) ;
V_54 = F_28 ( V_55 ,
& V_59 ) ;
F_27 ( V_54 ) ;
}
static int F_29 ( void )
{
T_2 V_35 ;
F_30 ( V_60 , V_35 ) ;
return ( V_35 >> 40 ) & 0xFF ;
}
static int F_31 ( void )
{
T_2 V_35 ;
F_30 ( V_60 , V_35 ) ;
return ( V_35 >> 8 ) & 0xFF ;
}
static int F_32 ( void )
{
T_2 V_35 ;
int V_61 , V_44 ;
F_30 ( V_62 , V_35 ) ;
V_61 = F_31 () ;
V_44 = ( ( V_35 ) & 255 ) ;
if ( V_44 <= V_61 )
V_44 = V_61 ;
return V_44 ;
}
static void F_33 ( struct V_21 * V_22 , int * F_23 , int * V_63 )
{
int V_51 = V_22 -> V_64 . V_65 ;
int V_66 ;
int V_53 ;
if ( V_46 . V_47 )
V_51 = V_22 -> V_64 . V_67 ;
V_66 = F_10 ( F_1 ( F_5 ( V_51 ) , V_46 . V_51 ) ) ;
* V_63 = F_21 ( int , V_66 ,
V_22 -> V_64 . V_68 , V_22 -> V_64 . V_65 ) ;
V_53 = F_10 ( F_1 ( F_5 ( V_51 ) , V_46 . V_53 ) ) ;
* F_23 = F_21 ( int , V_53 ,
V_22 -> V_64 . V_68 , V_51 ) ;
}
static void F_34 ( struct V_21 * V_22 , int V_64 )
{
int V_51 , V_53 ;
T_2 V_29 ;
F_33 ( V_22 , & V_53 , & V_51 ) ;
V_64 = F_21 ( int , V_64 , V_53 , V_51 ) ;
if ( V_64 == V_22 -> V_64 . V_69 )
return;
F_35 ( V_64 * 100000 , V_22 -> V_22 ) ;
V_22 -> V_64 . V_69 = V_64 ;
V_29 = V_64 << 8 ;
if ( V_46 . V_47 )
V_29 |= ( T_2 ) 1 << 32 ;
F_36 ( V_70 , V_29 ) ;
}
static inline void F_37 ( struct V_21 * V_22 , int V_71 )
{
int V_72 ;
V_72 = V_22 -> V_64 . V_69 + V_71 ;
F_34 ( V_22 , V_72 ) ;
}
static inline void F_38 ( struct V_21 * V_22 , int V_71 )
{
int V_72 ;
V_72 = V_22 -> V_64 . V_69 - V_71 ;
F_34 ( V_22 , V_72 ) ;
}
static void F_39 ( struct V_21 * V_22 )
{
sprintf ( V_22 -> V_34 , L_4 ) ;
V_22 -> V_64 . V_68 = F_29 () ;
V_22 -> V_64 . V_67 = F_31 () ;
V_22 -> V_64 . V_65 = F_32 () ;
F_34 ( V_22 , V_22 -> V_64 . V_67 ) ;
}
static inline void F_40 ( struct V_21 * V_22 ,
struct V_73 * V_73 )
{
T_2 V_74 ;
V_74 = F_41 ( F_5 ( V_73 -> V_75 * 100 ) ,
V_73 -> V_76 ) ;
V_73 -> V_77 = F_10 ( V_22 -> V_64 . V_67 * V_74 * 1000 ) ;
V_73 -> V_78 = V_74 ;
}
static inline void F_42 ( struct V_21 * V_22 )
{
T_2 V_75 , V_76 ;
F_30 ( V_79 , V_75 ) ;
F_30 ( V_80 , V_76 ) ;
V_22 -> V_81 = ( V_22 -> V_81 + 1 ) % V_82 ;
V_22 -> V_83 [ V_22 -> V_81 ] . V_75 = V_75 ;
V_22 -> V_83 [ V_22 -> V_81 ] . V_76 = V_76 ;
V_22 -> V_83 [ V_22 -> V_81 ] . V_75 -= V_22 -> V_84 ;
V_22 -> V_83 [ V_22 -> V_81 ] . V_76 -= V_22 -> V_85 ;
F_40 ( V_22 , & V_22 -> V_83 [ V_22 -> V_81 ] ) ;
V_22 -> V_84 = V_75 ;
V_22 -> V_85 = V_76 ;
}
static inline void F_43 ( struct V_21 * V_22 )
{
int V_86 , V_87 ;
V_86 = V_22 -> V_23 -> V_88 ;
V_87 = F_44 ( V_86 ) ;
F_45 ( & V_22 -> V_89 , V_90 + V_87 ) ;
}
static inline T_1 F_46 ( struct V_21 * V_22 )
{
T_1 V_91 , V_67 , V_69 ;
V_91 = V_22 -> V_83 [ V_22 -> V_81 ] . V_78 ;
V_67 = F_5 ( V_22 -> V_64 . V_67 ) ;
V_69 = F_5 ( V_22 -> V_64 . V_69 ) ;
return F_1 ( V_91 , F_2 ( V_67 , V_69 ) ) ;
}
static inline void F_47 ( struct V_21 * V_22 )
{
T_1 V_92 ;
struct V_5 * V_6 ;
signed int V_93 = 0 ;
int V_71 ;
V_6 = & V_22 -> V_6 ;
V_92 = F_46 ( V_22 ) ;
V_93 = F_9 ( V_6 , V_92 ) ;
V_71 = abs ( V_93 ) ;
if ( V_93 < 0 )
F_37 ( V_22 , V_71 ) ;
else
F_38 ( V_22 , V_71 ) ;
}
static void F_48 ( unsigned long V_94 )
{
struct V_21 * V_22 = (struct V_21 * ) V_94 ;
F_42 ( V_22 ) ;
F_47 ( V_22 ) ;
if ( V_22 -> V_64 . V_69 == V_22 -> V_64 . V_68 ) {
V_22 -> V_95 ++ ;
if ( ! ( V_22 -> V_95 % 5 ) ) {
F_34 ( V_22 , V_22 -> V_64 . V_67 ) ;
}
} else
V_22 -> V_95 = 0 ;
F_43 ( V_22 ) ;
}
static int F_49 ( unsigned int V_96 )
{
const struct V_97 * V_98 ;
struct V_21 * V_22 ;
V_98 = F_50 ( V_99 ) ;
if ( ! V_98 )
return - V_100 ;
V_27 [ V_96 ] = F_51 ( sizeof( struct V_21 ) , V_101 ) ;
if ( ! V_27 [ V_96 ] )
return - V_102 ;
V_22 = V_27 [ V_96 ] ;
F_39 ( V_22 ) ;
V_22 -> V_22 = V_96 ;
V_22 -> V_23 =
(struct V_103 * ) V_98 -> V_104 ;
F_52 ( & V_22 -> V_89 ) ;
V_22 -> V_89 . V_105 = F_48 ;
V_22 -> V_89 . V_28 =
( unsigned long ) V_22 ;
V_22 -> V_89 . V_106 = V_90 + V_107 / 100 ;
F_11 ( V_22 ) ;
F_42 ( V_22 ) ;
F_34 ( V_22 , V_22 -> V_64 . V_67 ) ;
F_53 ( & V_22 -> V_89 , V_96 ) ;
F_54 ( L_5 , V_96 ) ;
return 0 ;
}
static unsigned int F_55 ( unsigned int V_108 )
{
struct V_73 * V_73 ;
struct V_21 * V_22 ;
V_22 = V_27 [ V_108 ] ;
if ( ! V_22 )
return 0 ;
V_73 = & V_22 -> V_83 [ V_22 -> V_81 ] ;
return V_73 -> V_77 ;
}
static int F_56 ( struct V_109 * V_110 )
{
struct V_21 * V_22 ;
V_22 = V_27 [ V_110 -> V_22 ] ;
if ( ! V_110 -> V_111 . V_112 )
return - V_100 ;
if ( V_110 -> V_110 == V_113 ) {
V_46 . V_52 = 100 ;
V_46 . V_53 = F_5 ( 1 ) ;
V_46 . V_49 = 100 ;
V_46 . V_51 = F_5 ( 1 ) ;
V_46 . V_47 = 0 ;
return 0 ;
}
V_46 . V_52 = ( V_110 -> F_23 * 100 ) / V_110 -> V_111 . V_112 ;
V_46 . V_52 = F_21 ( int , V_46 . V_52 , 0 , 100 ) ;
V_46 . V_53 = F_2 ( F_5 ( V_46 . V_52 ) , F_5 ( 100 ) ) ;
V_46 . V_50 = V_110 -> V_63 * 100 / V_110 -> V_111 . V_112 ;
V_46 . V_50 = F_21 ( int , V_46 . V_50 , 0 , 100 ) ;
V_46 . V_49 = F_23 ( V_46 . V_50 , V_46 . V_48 ) ;
V_46 . V_51 = F_2 ( F_5 ( V_46 . V_49 ) , F_5 ( 100 ) ) ;
return 0 ;
}
static int F_57 ( struct V_109 * V_110 )
{
F_58 ( V_110 ,
V_110 -> V_111 . V_114 ,
V_110 -> V_111 . V_112 ) ;
if ( ( V_110 -> V_110 != V_115 ) &&
( V_110 -> V_110 != V_113 ) )
return - V_45 ;
return 0 ;
}
static int F_59 ( struct V_109 * V_110 )
{
int V_22 = V_110 -> V_22 ;
F_60 ( & V_27 [ V_22 ] -> V_89 ) ;
F_61 ( V_27 [ V_22 ] ) ;
V_27 [ V_22 ] = NULL ;
return 0 ;
}
static int F_62 ( struct V_109 * V_110 )
{
struct V_21 * V_22 ;
int V_54 ;
V_54 = F_49 ( V_110 -> V_22 ) ;
if ( V_54 )
return V_54 ;
V_22 = V_27 [ V_110 -> V_22 ] ;
if ( ! V_46 . V_47 &&
V_46 . V_52 == 100 && V_46 . V_49 == 100 )
V_110 -> V_110 = V_113 ;
else
V_110 -> V_110 = V_115 ;
V_110 -> F_23 = V_22 -> V_64 . V_68 * 100000 ;
V_110 -> V_63 = V_22 -> V_64 . V_65 * 100000 ;
V_110 -> V_111 . V_114 = V_22 -> V_64 . V_68 * 100000 ;
V_110 -> V_111 . V_112 = V_22 -> V_64 . V_65 * 100000 ;
V_110 -> V_111 . V_116 = V_117 ;
F_63 ( V_110 -> V_22 , V_110 -> V_118 ) ;
return 0 ;
}
static int F_64 ( void )
{
T_2 V_75 , V_76 , V_119 ;
F_30 ( V_79 , V_75 ) ;
F_30 ( V_80 , V_76 ) ;
if ( ! F_29 () ||
! F_31 () ||
! F_32 () )
return - V_100 ;
F_30 ( V_79 , V_119 ) ;
if ( ! ( V_119 - V_75 ) )
return - V_100 ;
F_30 ( V_80 , V_119 ) ;
if ( ! ( V_119 - V_76 ) )
return - V_100 ;
return 0 ;
}
static int T_5 F_65 ( void )
{
int V_22 , V_54 = 0 ;
const struct V_97 * V_98 ;
if ( V_120 )
return - V_100 ;
V_98 = F_50 ( V_99 ) ;
if ( ! V_98 )
return - V_100 ;
if ( F_64 () )
return - V_100 ;
F_54 ( L_6 ) ;
V_27 = F_66 ( sizeof( void * ) * F_67 () ) ;
if ( ! V_27 )
return - V_102 ;
V_54 = F_68 ( & V_121 ) ;
if ( V_54 )
goto V_122;
F_16 () ;
F_25 () ;
return V_54 ;
V_122:
F_69 () ;
F_13 (cpu) {
if ( V_27 [ V_22 ] ) {
F_70 ( & V_27 [ V_22 ] -> V_89 ) ;
F_61 ( V_27 [ V_22 ] ) ;
}
}
F_71 () ;
F_72 ( V_27 ) ;
return - V_100 ;
}
static int T_5 F_73 ( char * V_123 )
{
if ( ! V_123 )
return - V_45 ;
if ( ! strcmp ( V_123 , L_7 ) )
V_120 = 1 ;
return 0 ;
}
