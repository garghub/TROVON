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
static signed int F_9 ( struct V_5 * V_6 , int V_8 )
{
signed int V_16 , V_17 ;
T_1 V_18 , V_19 , V_20 ;
T_1 V_21 ;
V_16 = V_6 -> V_7 - V_8 ;
V_20 = F_5 ( V_16 ) ;
if ( abs ( V_16 ) <= V_6 -> V_9 )
return 0 ;
V_18 = F_1 ( V_6 -> V_13 , V_20 ) ;
V_6 -> V_10 += V_20 ;
V_21 = F_5 ( 30 ) ;
if ( V_6 -> V_10 > V_21 )
V_6 -> V_10 = V_21 ;
if ( V_6 -> V_10 < - V_21 )
V_6 -> V_10 = - V_21 ;
V_19 = F_1 ( V_6 -> V_15 , ( V_16 - V_6 -> V_11 ) ) ;
V_6 -> V_11 = V_16 ;
V_17 = V_18 + F_1 ( V_6 -> V_10 , V_6 -> V_14 ) + V_19 ;
return ( signed int ) F_10 ( V_17 ) ;
}
static inline void F_11 ( struct V_22 * V_23 )
{
F_6 ( & V_23 -> V_6 , V_23 -> V_24 -> V_25 ) ;
F_8 ( & V_23 -> V_6 , V_23 -> V_24 -> V_26 ) ;
F_7 ( & V_23 -> V_6 , V_23 -> V_24 -> V_27 ) ;
F_4 ( & V_23 -> V_6 ,
V_23 -> V_24 -> V_7 ,
100 ,
V_23 -> V_24 -> V_9 ,
0 ) ;
}
static inline void F_12 ( struct V_22 * V_23 )
{
F_6 ( & V_23 -> V_28 , V_23 -> V_24 -> V_25 ) ;
F_8 ( & V_23 -> V_28 , V_23 -> V_24 -> V_26 ) ;
F_7 ( & V_23 -> V_28 , V_23 -> V_24 -> V_27 ) ;
F_4 ( & V_23 -> V_28 ,
75 ,
50 ,
V_23 -> V_24 -> V_9 ,
0 ) ;
}
static inline void F_13 ( void )
{
unsigned int V_23 ;
F_14 (cpu) {
if ( V_29 [ V_23 ] )
F_11 ( V_29 [ V_23 ] ) ;
}
}
static int F_15 ( void * V_30 , T_2 V_31 )
{
* ( V_32 * ) V_30 = V_31 ;
F_13 () ;
return 0 ;
}
static int F_16 ( void * V_30 , T_2 * V_31 )
{
* V_31 = * ( V_32 * ) V_30 ;
return 0 ;
}
static void F_17 ( void )
{
int V_33 = 0 ;
V_34 = F_18 ( L_1 , NULL ) ;
if ( F_19 ( V_34 ) )
return;
while ( V_35 [ V_33 ] . V_36 ) {
F_20 ( V_35 [ V_33 ] . V_36 , 0660 ,
V_34 , V_35 [ V_33 ] . V_37 ,
& V_38 ) ;
V_33 ++ ;
}
}
static T_3 F_21 ( struct V_39 * V_40 , struct V_41 * V_42 ,
const char * V_43 , T_4 V_44 )
{
unsigned int V_45 ;
int V_46 ;
V_46 = sscanf ( V_43 , L_2 , & V_45 ) ;
if ( V_46 != 1 )
return - V_47 ;
V_48 . V_49 = F_22 ( int , V_45 , 0 , 1 ) ;
return V_44 ;
}
static T_3 F_23 ( struct V_39 * V_40 , struct V_41 * V_42 ,
const char * V_43 , T_4 V_44 )
{
unsigned int V_45 ;
int V_46 ;
V_46 = sscanf ( V_43 , L_2 , & V_45 ) ;
if ( V_46 != 1 )
return - V_47 ;
V_48 . V_50 = F_22 ( int , V_45 , 0 , 100 ) ;
V_48 . V_51 = F_2 ( F_5 ( V_48 . V_50 ) , F_5 ( 100 ) ) ;
return V_44 ;
}
static T_3 F_24 ( struct V_39 * V_40 , struct V_41 * V_42 ,
const char * V_43 , T_4 V_44 )
{
unsigned int V_45 ;
int V_46 ;
V_46 = sscanf ( V_43 , L_2 , & V_45 ) ;
if ( V_46 != 1 )
return - V_47 ;
V_48 . V_52 = F_22 ( int , V_45 , 0 , 100 ) ;
V_48 . V_53 = F_2 ( F_5 ( V_48 . V_52 ) , F_5 ( 100 ) ) ;
return V_44 ;
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
T_2 V_37 ;
F_30 ( V_60 , V_37 ) ;
return ( V_37 >> 40 ) & 0xFF ;
}
static int F_31 ( void )
{
T_2 V_37 ;
F_30 ( V_60 , V_37 ) ;
return ( V_37 >> 8 ) & 0xFF ;
}
static int F_32 ( void )
{
T_2 V_37 ;
int V_61 , V_46 ;
F_30 ( V_62 , V_37 ) ;
V_61 = F_31 () ;
V_46 = ( ( V_37 ) & 255 ) ;
if ( V_46 <= V_61 )
V_46 = V_61 ;
return V_46 ;
}
static void F_33 ( struct V_22 * V_23 , int * V_63 , int * V_64 )
{
int V_51 = V_23 -> V_65 . V_66 ;
int V_53 ;
if ( V_48 . V_49 )
V_51 = V_23 -> V_65 . V_67 ;
V_51 = F_10 ( F_1 ( F_5 ( V_51 ) , V_48 . V_51 ) ) ;
* V_64 = F_22 ( int , V_51 ,
V_23 -> V_65 . V_68 , V_23 -> V_65 . V_66 ) ;
V_53 = F_10 ( F_1 ( F_5 ( V_51 ) , V_48 . V_53 ) ) ;
* V_63 = F_22 ( int , V_53 ,
V_23 -> V_65 . V_68 , V_51 ) ;
}
static void F_34 ( struct V_22 * V_23 , int V_65 )
{
int V_51 , V_53 ;
F_33 ( V_23 , & V_53 , & V_51 ) ;
V_65 = F_22 ( int , V_65 , V_53 , V_51 ) ;
if ( V_65 == V_23 -> V_65 . V_69 )
return;
#ifndef F_35
F_36 ( V_65 * 100000 , V_23 -> V_23 ) ;
#endif
V_23 -> V_65 . V_69 = V_65 ;
F_37 ( V_70 , V_65 << 8 ) ;
}
static inline void F_38 ( struct V_22 * V_23 , int V_71 )
{
int V_72 ;
V_72 = V_23 -> V_65 . V_69 + V_71 ;
F_34 ( V_23 , V_72 ) ;
}
static inline void F_39 ( struct V_22 * V_23 , int V_71 )
{
int V_72 ;
V_72 = V_23 -> V_65 . V_69 - V_71 ;
F_34 ( V_23 , V_72 ) ;
}
static void F_40 ( struct V_22 * V_23 )
{
sprintf ( V_23 -> V_36 , L_4 ) ;
V_23 -> V_65 . V_68 = F_29 () ;
V_23 -> V_65 . V_67 = F_31 () ;
V_23 -> V_65 . V_66 = F_32 () ;
F_34 ( V_23 , V_23 -> V_65 . V_67 ) ;
}
static inline void F_41 ( struct V_22 * V_23 ,
struct V_73 * V_73 )
{
T_2 V_74 ;
V_73 -> V_75 = 100 - F_42 (
V_73 -> V_76 * 100 ,
V_73 -> V_77 ) ;
V_74 = F_42 ( V_73 -> V_78 * 100 , V_73 -> V_79 ) ;
V_73 -> V_80 = V_23 -> V_65 . V_67 * V_74 * 1000 ;
V_73 -> V_81 = F_3 ( ( V_73 -> V_75 * V_74 ) ,
100 ) ;
}
static inline void F_43 ( struct V_22 * V_23 )
{
T_5 V_82 ;
T_2 V_83 ;
T_2 V_78 , V_79 ;
V_82 = F_44 () ;
V_83 = F_45 ( V_23 -> V_23 , NULL ) ;
F_30 ( V_84 , V_78 ) ;
F_30 ( V_85 , V_79 ) ;
if ( V_23 -> V_86 > 0 ) {
V_23 -> V_87 = ( V_23 -> V_87 + 1 ) % V_88 ;
V_23 -> V_89 [ V_23 -> V_87 ] . V_90 = V_23 -> V_91 ;
V_23 -> V_89 [ V_23 -> V_87 ] . V_92 = V_82 ;
V_23 -> V_89 [ V_23 -> V_87 ] . V_77 =
F_46 ( V_82 , V_23 -> V_91 ) ;
V_23 -> V_89 [ V_23 -> V_87 ] . V_76 =
V_83 - V_23 -> V_86 ;
V_23 -> V_89 [ V_23 -> V_87 ] . V_78 = V_78 ;
V_23 -> V_89 [ V_23 -> V_87 ] . V_79 = V_79 ;
V_23 -> V_89 [ V_23 -> V_87 ] . V_78 -= V_23 -> V_93 ;
V_23 -> V_89 [ V_23 -> V_87 ] . V_79 -= V_23 -> V_94 ;
F_41 ( V_23 , & V_23 -> V_89 [ V_23 -> V_87 ] ) ;
}
V_23 -> V_91 = V_82 ;
V_23 -> V_86 = V_83 ;
V_23 -> V_93 = V_78 ;
V_23 -> V_94 = V_79 ;
}
static inline void F_47 ( struct V_22 * V_23 )
{
int V_95 , V_96 ;
V_95 = V_23 -> V_24 -> V_97 ;
V_96 = F_48 ( V_95 ) ;
F_49 ( & V_23 -> V_98 , V_99 + V_96 ) ;
}
static inline void F_50 ( struct V_22 * V_23 )
{
V_23 -> V_100 = 1 ;
}
static inline void F_51 ( struct V_22 * V_23 )
{
V_23 -> V_100 = 0 ;
}
static inline int F_52 ( struct V_22 * V_23 )
{
T_1 V_101 ;
T_1 V_102 , V_66 , V_69 ;
V_102 = F_5 ( V_23 -> V_89 [ V_23 -> V_87 ] . V_81 ) ;
V_66 = F_5 ( V_23 -> V_65 . V_66 ) ;
V_69 = F_5 ( V_23 -> V_65 . V_69 ) ;
V_101 = F_1 ( V_102 , F_2 ( V_66 , V_69 ) ) ;
return F_10 ( V_101 ) ;
}
static inline void F_53 ( struct V_22 * V_23 )
{
int V_101 ;
struct V_5 * V_6 ;
signed int V_103 = 0 ;
int V_71 ;
V_6 = & V_23 -> V_6 ;
V_101 = F_52 ( V_23 ) ;
V_103 = F_9 ( V_6 , V_101 ) ;
V_71 = abs ( V_103 ) ;
if ( V_103 < 0 )
F_38 ( V_23 , V_71 ) ;
else
F_39 ( V_23 , V_71 ) ;
}
static inline void F_54 ( struct V_22 * V_23 )
{
int V_101 ;
struct V_5 * V_6 ;
int V_103 = 0 ;
int V_71 ;
V_6 = & V_23 -> V_28 ;
V_101 = F_52 ( V_23 ) ;
V_103 = F_9 ( V_6 , 100 - V_101 ) ;
V_71 = abs ( V_103 ) ;
if ( V_103 < 0 )
F_39 ( V_23 , V_71 ) ;
else
F_38 ( V_23 , V_71 ) ;
if ( V_23 -> V_65 . V_69 == V_23 -> V_65 . V_68 )
F_51 ( V_23 ) ;
}
static void F_55 ( unsigned long V_104 )
{
struct V_22 * V_23 = (struct V_22 * ) V_104 ;
F_43 ( V_23 ) ;
if ( ! V_23 -> V_100 )
F_53 ( V_23 ) ;
else
F_54 ( V_23 ) ;
#if F_56 ( V_105 )
if ( V_23 -> V_65 . V_69 == V_23 -> V_65 . V_68 ) {
V_23 -> V_106 ++ ;
if ( ! ( V_23 -> V_106 % 5 ) ) {
F_34 ( V_23 , V_23 -> V_65 . V_67 ) ;
F_50 ( V_23 ) ;
}
} else
V_23 -> V_106 = 0 ;
#endif
F_47 ( V_23 ) ;
}
static int F_57 ( unsigned int V_107 )
{
const struct V_108 * V_109 ;
struct V_22 * V_23 ;
V_109 = F_58 ( V_110 ) ;
if ( ! V_109 )
return - V_111 ;
V_29 [ V_107 ] = F_59 ( sizeof( struct V_22 ) , V_112 ) ;
if ( ! V_29 [ V_107 ] )
return - V_113 ;
V_23 = V_29 [ V_107 ] ;
F_40 ( V_23 ) ;
V_23 -> V_23 = V_107 ;
V_23 -> V_24 =
(struct V_114 * ) V_109 -> V_115 ;
F_60 ( & V_23 -> V_98 ) ;
V_23 -> V_98 . V_116 = F_55 ;
V_23 -> V_98 . V_30 =
( unsigned long ) V_23 ;
V_23 -> V_98 . V_117 = V_99 + V_118 / 100 ;
F_11 ( V_23 ) ;
F_12 ( V_23 ) ;
F_43 ( V_23 ) ;
F_34 ( V_23 , V_23 -> V_65 . V_67 ) ;
F_61 ( & V_23 -> V_98 , V_107 ) ;
F_62 ( L_5 , V_107 ) ;
return 0 ;
}
static unsigned int F_63 ( unsigned int V_119 )
{
struct V_73 * V_73 ;
struct V_22 * V_23 ;
V_23 = V_29 [ V_119 ] ;
if ( ! V_23 )
return 0 ;
V_73 = & V_23 -> V_89 [ V_23 -> V_87 ] ;
return V_73 -> V_80 ;
}
static int F_64 ( struct V_120 * V_121 )
{
struct V_22 * V_23 ;
int V_63 , V_64 ;
V_23 = V_29 [ V_121 -> V_23 ] ;
if ( ! V_121 -> V_122 . V_123 )
return - V_111 ;
F_33 ( V_23 , & V_63 , & V_64 ) ;
V_48 . V_52 = ( V_121 -> V_63 * 100 ) / V_121 -> V_122 . V_123 ;
V_48 . V_52 = F_22 ( int , V_48 . V_52 , 0 , 100 ) ;
V_48 . V_53 = F_2 ( F_5 ( V_48 . V_52 ) , F_5 ( 100 ) ) ;
V_48 . V_50 = V_121 -> V_64 * 100 / V_121 -> V_122 . V_123 ;
V_48 . V_50 = F_22 ( int , V_48 . V_50 , 0 , 100 ) ;
V_48 . V_51 = F_2 ( F_5 ( V_48 . V_50 ) , F_5 ( 100 ) ) ;
if ( V_121 -> V_121 == V_124 ) {
V_48 . V_52 = 100 ;
V_48 . V_53 = F_5 ( 1 ) ;
V_48 . V_50 = 100 ;
V_48 . V_51 = F_5 ( 1 ) ;
V_48 . V_49 = 0 ;
}
return 0 ;
}
static int F_65 ( struct V_120 * V_121 )
{
F_66 ( V_121 ,
V_121 -> V_122 . V_125 ,
V_121 -> V_122 . V_123 ) ;
if ( ( V_121 -> V_121 != V_126 ) &&
( V_121 -> V_121 != V_124 ) )
return - V_47 ;
return 0 ;
}
static int T_6 F_67 ( struct V_120 * V_121 )
{
int V_23 = V_121 -> V_23 ;
F_68 ( & V_29 [ V_23 ] -> V_98 ) ;
F_69 ( V_29 [ V_23 ] ) ;
V_29 [ V_23 ] = NULL ;
return 0 ;
}
static int T_6 F_70 ( struct V_120 * V_121 )
{
int V_54 , V_68 , V_67 ;
struct V_22 * V_23 ;
V_54 = F_57 ( V_121 -> V_23 ) ;
if ( V_54 )
return V_54 ;
V_23 = V_29 [ V_121 -> V_23 ] ;
if ( ! V_48 . V_49 &&
V_48 . V_52 == 100 && V_48 . V_50 == 100 )
V_121 -> V_121 = V_124 ;
else
V_121 -> V_121 = V_126 ;
F_33 ( V_23 , & V_68 , & V_67 ) ;
V_121 -> V_63 = V_68 * 100000 ;
V_121 -> V_64 = V_67 * 100000 ;
V_121 -> V_122 . V_125 = V_23 -> V_65 . V_68 * 100000 ;
V_121 -> V_122 . V_123 = V_23 -> V_65 . V_66 * 100000 ;
V_121 -> V_122 . V_127 = V_128 ;
F_71 ( V_121 -> V_23 , V_121 -> V_129 ) ;
return 0 ;
}
static int F_72 ( void )
{
T_2 V_78 , V_79 , V_130 ;
F_30 ( V_84 , V_78 ) ;
F_30 ( V_85 , V_79 ) ;
if ( ! F_29 () ||
! F_31 () ||
! F_32 () )
return - V_111 ;
F_30 ( V_84 , V_130 ) ;
if ( ! ( V_130 - V_78 ) )
return - V_111 ;
F_30 ( V_85 , V_130 ) ;
if ( ! ( V_130 - V_79 ) )
return - V_111 ;
return 0 ;
}
static int T_7 F_73 ( void )
{
int V_23 , V_54 = 0 ;
const struct V_108 * V_109 ;
if ( V_131 )
return - V_111 ;
V_109 = F_58 ( V_110 ) ;
if ( ! V_109 )
return - V_111 ;
if ( F_72 () )
return - V_111 ;
F_62 ( L_6 ) ;
V_29 = F_74 ( sizeof( void * ) * F_75 () ) ;
if ( ! V_29 )
return - V_113 ;
memset ( V_29 , 0 , sizeof( void * ) * F_75 () ) ;
V_54 = F_76 ( & V_132 ) ;
if ( V_54 )
goto V_133;
F_17 () ;
F_25 () ;
return V_54 ;
V_133:
F_77 () ;
F_14 (cpu) {
if ( V_29 [ V_23 ] ) {
F_78 ( & V_29 [ V_23 ] -> V_98 ) ;
F_69 ( V_29 [ V_23 ] ) ;
}
}
F_79 () ;
F_80 ( V_29 ) ;
return - V_111 ;
}
static int T_7 F_81 ( char * V_134 )
{
if ( ! V_134 )
return - V_47 ;
if ( ! strcmp ( V_134 , L_7 ) )
V_131 = 1 ;
return 0 ;
}
