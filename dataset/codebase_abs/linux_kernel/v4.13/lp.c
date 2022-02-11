static void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_3 ( V_2 -> V_5 ) ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
if ( F_5 ( V_3 , & V_2 -> V_4 ) ) {
F_6 ( V_2 -> V_5 ) ;
}
}
static int F_7 ( void * V_6 )
{
struct V_1 * V_2 = (struct V_1 * ) V_6 ;
F_8 ( V_7 , & V_2 -> V_4 ) ;
return ( 1 ) ;
}
static int F_9 ( struct V_8 * V_9 , int V_10 )
{
if ( F_10 ( V_9 , V_10 ) != 0 ) {
V_10 = V_11 ;
F_10 ( V_9 , V_10 ) ;
}
return ( V_10 ) ;
}
static int F_11 ( int V_12 )
{
int V_13 ;
F_1 ( & V_14 [ V_12 ] ) ;
F_12 ( V_12 , V_15 ) ;
F_13 ( V_16 ) ;
F_12 ( V_12 , V_15 | V_17 ) ;
V_13 = F_14 ( V_12 ) ;
F_4 ( & V_14 [ V_12 ] ) ;
return V_13 ;
}
static void F_15 ( int V_12 )
{
F_16 ( V_18 ) ;
int V_19 ;
if ( F_17 ( V_12 ) & V_20 )
return;
V_19 = V_14 [ V_12 ] . V_5 -> V_9 -> V_21 == V_22 ;
if ( V_19 ) F_4 ( & V_14 [ V_12 ] ) ;
F_18 ( & V_14 [ V_12 ] . V_23 , & V_18 , V_24 ) ;
F_19 ( V_25 ) ;
F_20 ( & V_14 [ V_12 ] . V_23 , & V_18 ) ;
if ( V_19 ) F_1 ( & V_14 [ V_12 ] ) ;
else F_21 ( V_14 [ V_12 ] . V_5 ) ;
}
static int F_22 ( int V_12 )
{
int error = 0 ;
unsigned int V_26 = V_14 [ V_12 ] . V_27 ;
unsigned char V_28 = F_14 ( V_12 ) ;
if ( ( V_28 & V_29 ) && ! ( F_17 ( V_12 ) & V_30 ) )
V_26 = 0 ;
else if ( ( V_28 & V_31 ) ) {
if ( V_26 != V_31 ) {
V_26 = V_31 ;
F_23 ( V_32 L_1 , V_12 ) ;
}
error = - V_33 ;
} else if ( ! ( V_28 & V_34 ) ) {
if ( V_26 != V_34 ) {
V_26 = V_34 ;
F_23 ( V_32 L_2 , V_12 ) ;
}
error = - V_35 ;
} else if ( ! ( V_28 & V_29 ) ) {
if ( V_26 != V_29 ) {
V_26 = V_29 ;
F_23 ( V_32 L_3 , V_12 ) ;
}
error = - V_35 ;
} else {
V_26 = 0 ;
}
V_14 [ V_12 ] . V_27 = V_26 ;
if ( V_26 != 0 )
F_15 ( V_12 ) ;
return error ;
}
static int F_24 ( int V_12 , int V_36 )
{
int error = 0 ;
if ( V_14 [ V_12 ] . V_37 != V_11 ) {
return ( 0 ) ;
}
do {
error = F_22 ( V_12 ) ;
if ( error && ( V_36 || ( F_17 ( V_12 ) & V_20 ) ) )
break;
if ( F_25 ( V_38 ) ) {
error = - V_39 ;
break;
}
} while ( error );
return error ;
}
static T_1 F_26 ( struct V_40 * V_40 , const char T_2 * V_41 ,
T_3 V_42 , T_4 * V_43 )
{
unsigned int V_12 = F_27 ( F_28 ( V_40 ) ) ;
struct V_8 * V_9 = V_14 [ V_12 ] . V_5 -> V_9 ;
char * V_44 = V_14 [ V_12 ] . V_45 ;
T_1 V_46 = 0 ;
T_1 V_47 ;
T_3 V_48 = V_42 ;
int V_36 = ( ( V_40 -> V_49 & V_50 ) ||
( F_17 ( V_12 ) & V_20 ) ) ;
#ifdef F_29
if ( F_30 ( V_51 , V_14 [ V_12 ] . V_52 + F_31 ( V_12 ) ) )
V_14 [ V_12 ] . V_53 = 0 ;
V_14 [ V_12 ] . V_52 = V_51 ;
#endif
if ( V_48 > V_54 )
V_48 = V_54 ;
if ( F_32 ( & V_14 [ V_12 ] . V_55 ) )
return - V_39 ;
if ( F_33 ( V_44 , V_41 , V_48 ) ) {
V_46 = - V_56 ;
goto V_57;
}
F_1 ( & V_14 [ V_12 ] ) ;
V_14 [ V_12 ] . V_37 = F_9 ( V_9 ,
V_14 [ V_12 ] . V_58 ) ;
F_34 ( V_14 [ V_12 ] . V_5 ,
( V_36 ? V_59
: V_14 [ V_12 ] . V_60 ) ) ;
if ( ( V_46 = F_24 ( V_12 , V_36 ) ) == 0 )
do {
V_47 = F_35 ( V_9 , V_44 , V_48 ) ;
if ( V_47 > 0 ) {
V_48 -= V_47 ;
V_42 -= V_47 ;
V_41 += V_47 ;
V_46 += V_47 ;
}
if ( F_25 ( V_38 ) ) {
if ( V_46 == 0 )
V_46 = - V_39 ;
break;
}
if ( V_48 > 0 ) {
int error ;
F_10 ( V_14 [ V_12 ] . V_5 -> V_9 ,
V_11 ) ;
V_14 [ V_12 ] . V_37 = V_11 ;
error = F_24 ( V_12 , V_36 ) ;
if ( error ) {
if ( V_46 == 0 )
V_46 = error ;
break;
} else if ( V_36 ) {
if ( V_46 == 0 )
V_46 = - V_61 ;
break;
}
F_21 ( V_14 [ V_12 ] . V_5 ) ;
V_14 [ V_12 ] . V_37
= F_9 ( V_9 ,
V_14 [ V_12 ] . V_58 ) ;
} else if ( F_36 () )
F_37 () ;
if ( V_42 ) {
V_48 = V_42 ;
if ( V_48 > V_54 )
V_48 = V_54 ;
if ( F_33 ( V_44 , V_41 , V_48 ) ) {
if ( V_46 == 0 )
V_46 = - V_56 ;
break;
}
}
} while ( V_42 > 0 );
if ( F_5 ( V_7 ,
& V_14 [ V_12 ] . V_4 ) ) {
F_23 ( V_32 L_4 , V_12 ) ;
F_10 ( V_14 [ V_12 ] . V_5 -> V_9 ,
V_11 ) ;
V_14 [ V_12 ] . V_37 = V_11 ;
F_4 ( & V_14 [ V_12 ] ) ;
}
V_57:
F_38 ( & V_14 [ V_12 ] . V_55 ) ;
return V_46 ;
}
static T_1 F_39 ( struct V_40 * V_40 , char T_2 * V_41 ,
T_3 V_42 , T_4 * V_43 )
{
F_16 ( V_18 ) ;
unsigned int V_12 = F_27 ( F_28 ( V_40 ) ) ;
struct V_8 * V_9 = V_14 [ V_12 ] . V_5 -> V_9 ;
T_1 V_13 = 0 ;
char * V_44 = V_14 [ V_12 ] . V_45 ;
int V_36 = ( ( V_40 -> V_49 & V_50 ) ||
( F_17 ( V_12 ) & V_20 ) ) ;
if ( V_42 > V_54 )
V_42 = V_54 ;
if ( F_32 ( & V_14 [ V_12 ] . V_55 ) )
return - V_39 ;
F_1 ( & V_14 [ V_12 ] ) ;
F_34 ( V_14 [ V_12 ] . V_5 ,
( V_36 ? V_59
: V_14 [ V_12 ] . V_60 ) ) ;
F_10 ( V_14 [ V_12 ] . V_5 -> V_9 , V_11 ) ;
if ( F_10 ( V_14 [ V_12 ] . V_5 -> V_9 ,
V_62 ) ) {
V_13 = - V_35 ;
goto V_63;
}
while ( V_13 == 0 ) {
V_13 = F_40 ( V_9 , V_44 , V_42 ) ;
if ( V_13 > 0 )
break;
if ( V_36 ) {
V_13 = - V_61 ;
break;
}
if ( V_14 [ V_12 ] . V_5 -> V_9 -> V_21 == V_22 ) {
F_10 ( V_14 [ V_12 ] . V_5 -> V_9 ,
V_11 ) ;
F_15 ( V_12 ) ;
if ( F_10 ( V_14 [ V_12 ] . V_5 -> V_9 ,
V_62 ) ) {
V_13 = - V_35 ;
goto V_63;
}
} else {
F_18 ( & V_14 [ V_12 ] . V_23 , & V_18 , V_24 ) ;
F_19 ( V_25 ) ;
F_20 ( & V_14 [ V_12 ] . V_23 , & V_18 ) ;
}
if ( F_25 ( V_38 ) ) {
V_13 = - V_64 ;
break;
}
F_41 () ;
}
F_10 ( V_14 [ V_12 ] . V_5 -> V_9 , V_11 ) ;
V_63:
F_4 ( & V_14 [ V_12 ] ) ;
if ( V_13 > 0 && F_42 ( V_41 , V_44 , V_13 ) )
V_13 = - V_56 ;
F_38 ( & V_14 [ V_12 ] . V_55 ) ;
return V_13 ;
}
static int F_43 ( struct V_65 * V_65 , struct V_40 * V_40 )
{
unsigned int V_12 = F_27 ( V_65 ) ;
int V_66 = 0 ;
F_44 ( & V_67 ) ;
if ( V_12 >= V_68 ) {
V_66 = - V_69 ;
goto V_63;
}
if ( ( F_17 ( V_12 ) & V_70 ) == 0 ) {
V_66 = - V_69 ;
goto V_63;
}
if ( F_2 ( V_71 , & F_17 ( V_12 ) ) ) {
V_66 = - V_72 ;
goto V_63;
}
if ( ( F_17 ( V_12 ) & V_73 ) && ! ( V_40 -> V_49 & V_50 ) ) {
int V_28 ;
F_1 ( & V_14 [ V_12 ] ) ;
V_28 = F_14 ( V_12 ) ;
F_4 ( & V_14 [ V_12 ] ) ;
if ( V_28 & V_31 ) {
F_23 ( V_32 L_1 , V_12 ) ;
F_17 ( V_12 ) &= ~ V_74 ;
V_66 = - V_33 ;
goto V_63;
} else if ( ! ( V_28 & V_34 ) ) {
F_23 ( V_32 L_2 , V_12 ) ;
F_17 ( V_12 ) &= ~ V_74 ;
V_66 = - V_35 ;
goto V_63;
} else if ( ! ( V_28 & V_29 ) ) {
F_23 ( V_75 L_5 , V_12 ) ;
F_17 ( V_12 ) &= ~ V_74 ;
V_66 = - V_35 ;
goto V_63;
}
}
V_14 [ V_12 ] . V_45 = F_45 ( V_54 , V_76 ) ;
if ( ! V_14 [ V_12 ] . V_45 ) {
F_17 ( V_12 ) &= ~ V_74 ;
V_66 = - V_77 ;
goto V_63;
}
F_1 ( & V_14 [ V_12 ] ) ;
if ( ( V_14 [ V_12 ] . V_5 -> V_9 -> V_78 & V_79 ) &&
! F_10 ( V_14 [ V_12 ] . V_5 -> V_9 ,
V_80 ) ) {
F_23 ( V_32 L_6 , V_12 ) ;
V_14 [ V_12 ] . V_58 = V_80 ;
} else {
V_14 [ V_12 ] . V_58 = V_11 ;
}
F_10 ( V_14 [ V_12 ] . V_5 -> V_9 , V_11 ) ;
F_4 ( & V_14 [ V_12 ] ) ;
V_14 [ V_12 ] . V_37 = V_11 ;
V_63:
F_38 ( & V_67 ) ;
return V_66 ;
}
static int F_46 ( struct V_65 * V_65 , struct V_40 * V_40 )
{
unsigned int V_12 = F_27 ( V_65 ) ;
F_1 ( & V_14 [ V_12 ] ) ;
F_10 ( V_14 [ V_12 ] . V_5 -> V_9 , V_11 ) ;
V_14 [ V_12 ] . V_37 = V_11 ;
F_4 ( & V_14 [ V_12 ] ) ;
F_47 ( V_14 [ V_12 ] . V_45 ) ;
V_14 [ V_12 ] . V_45 = NULL ;
F_17 ( V_12 ) &= ~ V_74 ;
return 0 ;
}
static int F_48 ( unsigned int V_12 , unsigned int V_81 ,
unsigned long V_82 , void T_2 * V_83 )
{
int V_28 ;
int V_13 = 0 ;
#ifdef F_49
F_23 ( V_84 L_7 , V_12 , V_81 , V_82 ) ;
#endif
if ( V_12 >= V_68 )
return - V_85 ;
if ( ( F_17 ( V_12 ) & V_70 ) == 0 )
return - V_85 ;
switch ( V_81 ) {
case V_86 :
if ( V_82 > V_87 / V_88 )
return - V_89 ;
F_31 ( V_12 ) = V_82 * V_88 / 100 ;
break;
case V_90 :
F_50 ( V_12 ) = V_82 ;
break;
case V_91 :
if ( V_82 )
F_17 ( V_12 ) |= V_20 ;
else
F_17 ( V_12 ) &= ~ V_20 ;
break;
case V_92 :
if ( V_82 )
F_17 ( V_12 ) |= V_73 ;
else
F_17 ( V_12 ) &= ~ V_73 ;
break;
case V_93 :
if ( V_82 )
F_17 ( V_12 ) |= V_30 ;
else
F_17 ( V_12 ) &= ~ V_30 ;
break;
case V_94 :
F_51 ( V_12 ) = V_82 ;
break;
case V_95 :
return - V_89 ;
break;
case V_96 :
if ( F_42 ( V_83 , & F_52 ( V_12 ) ,
sizeof( int ) ) )
return - V_56 ;
break;
case V_97 :
if ( F_32 ( & V_14 [ V_12 ] . V_55 ) )
return - V_39 ;
F_1 ( & V_14 [ V_12 ] ) ;
V_28 = F_14 ( V_12 ) ;
F_4 ( & V_14 [ V_12 ] ) ;
F_38 ( & V_14 [ V_12 ] . V_55 ) ;
if ( F_42 ( V_83 , & V_28 , sizeof( int ) ) )
return - V_56 ;
break;
case V_98 :
F_11 ( V_12 ) ;
break;
#ifdef F_29
case V_99 :
if ( F_42 ( V_83 , & F_53 ( V_12 ) ,
sizeof( struct V_100 ) ) )
return - V_56 ;
if ( F_54 ( V_101 ) )
memset ( & F_53 ( V_12 ) , 0 ,
sizeof( struct V_100 ) ) ;
break;
#endif
case V_102 :
V_28 = F_17 ( V_12 ) ;
if ( F_42 ( V_83 , & V_28 , sizeof( int ) ) )
return - V_56 ;
break;
default:
V_13 = - V_89 ;
}
return V_13 ;
}
static int F_55 ( unsigned int V_12 , struct V_103 * V_104 )
{
long V_105 ;
if ( ( V_104 -> V_106 < 0 ) ||
( V_104 -> V_107 < 0 ) ) {
return - V_89 ;
}
V_105 = F_56 ( V_104 -> V_107 , 1000000 / V_88 ) ;
V_105 += V_104 -> V_106 * ( long ) V_88 ;
if ( V_105 <= 0 ) {
return - V_89 ;
}
V_14 [ V_12 ] . V_60 = V_105 ;
return 0 ;
}
static long F_57 ( struct V_40 * V_40 , unsigned int V_81 ,
unsigned long V_82 )
{
unsigned int V_12 ;
struct V_103 V_104 ;
int V_66 ;
V_12 = F_27 ( F_28 ( V_40 ) ) ;
F_44 ( & V_67 ) ;
switch ( V_81 ) {
case V_108 :
if ( F_33 ( & V_104 , ( void T_2 * ) V_82 ,
sizeof ( struct V_103 ) ) ) {
V_66 = - V_56 ;
break;
}
V_66 = F_55 ( V_12 , & V_104 ) ;
break;
default:
V_66 = F_48 ( V_12 , V_81 , V_82 , ( void T_2 * ) V_82 ) ;
break;
}
F_38 ( & V_67 ) ;
return V_66 ;
}
static long F_58 ( struct V_40 * V_40 , unsigned int V_81 ,
unsigned long V_82 )
{
unsigned int V_12 ;
struct V_103 V_104 ;
int V_66 ;
V_12 = F_27 ( F_28 ( V_40 ) ) ;
F_44 ( & V_67 ) ;
switch ( V_81 ) {
case V_108 :
if ( F_59 ( & V_104 , F_60 ( V_82 ) ) ) {
V_66 = - V_56 ;
break;
}
V_66 = F_55 ( V_12 , & V_104 ) ;
break;
#ifdef F_29
case V_99 :
V_66 = - V_89 ;
break;
#endif
default:
V_66 = F_48 ( V_12 , V_81 , V_82 , F_60 ( V_82 ) ) ;
break;
}
F_38 ( & V_67 ) ;
return V_66 ;
}
static void F_61 ( struct V_109 * V_110 , const char * V_111 ,
unsigned V_42 )
{
struct V_112 * V_5 = V_14 [ V_113 ] . V_5 ;
struct V_8 * V_9 = V_5 -> V_9 ;
T_1 V_47 ;
if ( F_62 ( V_5 ) )
return;
F_34 ( V_5 , 0 ) ;
F_10 ( V_9 , V_11 ) ;
do {
T_1 V_114 = V_42 ;
char * V_115 = memchr ( V_111 , '\n' , V_42 ) ;
if ( V_115 )
V_114 = V_115 - V_111 ;
if ( V_114 > 0 ) {
V_47 = F_35 ( V_9 , V_111 , V_114 ) ;
if ( V_47 <= 0 )
continue;
V_111 += V_47 ;
V_42 -= V_47 ;
V_114 -= V_47 ;
}
if ( V_115 && V_114 <= 0 ) {
const char * V_116 = L_8 ;
int V_117 = 2 ;
V_111 ++ ;
V_42 -- ;
do {
V_47 = F_35 ( V_9 , V_116 , V_117 ) ;
if ( V_47 > 0 )
V_117 -= V_47 , V_116 += V_47 ;
} while ( V_117 > 0 && ( V_118 || V_47 > 0 ) );
}
} while ( V_42 > 0 && ( V_118 || V_47 > 0 ) );
F_6 ( V_5 ) ;
}
static int T_5 F_63 ( char * V_119 )
{
static int V_120 ;
int V_121 ;
if ( F_64 ( & V_119 , & V_121 ) ) {
if ( V_121 == 0 ) {
V_122 [ 0 ] = V_123 ;
} else {
F_23 ( V_124 L_9 , V_121 ) ;
return 0 ;
}
} else if ( ! strncmp ( V_119 , L_10 , 7 ) ) {
int V_125 = F_65 ( V_119 + 7 , NULL , 10 ) ;
if ( V_120 < V_68 )
V_122 [ V_120 ++ ] = V_125 ;
else
F_23 ( V_32 L_11 ,
V_119 ) ;
} else if ( ! strcmp ( V_119 , L_12 ) ) {
V_122 [ 0 ] = V_126 ;
} else if ( ! strcmp ( V_119 , L_13 ) ) {
if ( V_120 < V_68 )
V_122 [ V_120 ++ ] = V_127 ;
else
F_23 ( V_32 L_11 ,
V_119 ) ;
} else if ( ! strcmp ( V_119 , L_14 ) ) {
V_128 = 1 ;
}
return 1 ;
}
static int F_66 ( int V_129 , struct V_8 * V_9 )
{
V_14 [ V_129 ] . V_5 = F_67 ( V_9 , L_15 ,
F_7 , NULL , NULL , 0 ,
( void * ) & V_14 [ V_129 ] ) ;
if ( V_14 [ V_129 ] . V_5 == NULL )
return 1 ;
V_14 [ V_129 ] . V_130 |= V_70 ;
if ( V_128 )
F_11 ( V_129 ) ;
F_68 ( V_131 , V_9 -> V_5 , F_69 ( V_132 , V_129 ) , NULL ,
L_16 , V_129 ) ;
F_23 ( V_32 L_17 , V_129 , V_9 -> V_133 ,
( V_9 -> V_21 == V_22 ) ? L_18 : L_19 ) ;
#ifdef F_70
if ( ! V_129 ) {
if ( V_9 -> V_78 & V_134 ) {
F_71 ( & V_135 ) ;
V_136 = V_9 ;
F_23 ( V_32 L_20 , V_113 ) ;
} else
F_23 ( V_75 L_21 ,
V_113 , V_9 -> V_133 ) ;
}
#endif
return 0 ;
}
static void F_72 ( struct V_8 * V_9 )
{
unsigned int V_117 ;
switch ( V_122 [ 0 ] ) {
case V_137 :
case V_126 :
if ( V_122 [ 0 ] == V_126 &&
V_9 -> V_138 [ 0 ] . V_139 != V_140 )
return;
if ( V_141 == V_68 ) {
F_23 ( V_32 L_22 , V_68 ) ;
return;
}
if ( ! F_66 ( V_141 , V_9 ) )
V_141 ++ ;
break;
default:
for ( V_117 = 0 ; V_117 < V_68 ; V_117 ++ ) {
if ( V_9 -> V_142 == V_122 [ V_117 ] ) {
if ( ! F_66 ( V_117 , V_9 ) )
V_141 ++ ;
break;
}
}
break;
}
}
static void F_73 ( struct V_8 * V_9 )
{
#ifdef F_70
if ( V_136 == V_9 ) {
F_74 ( & V_135 ) ;
V_136 = NULL ;
}
#endif
}
static int T_5 F_75 ( void )
{
int V_117 , V_143 = 0 ;
if ( V_122 [ 0 ] == V_123 )
return 0 ;
for ( V_117 = 0 ; V_117 < V_68 ; V_117 ++ ) {
V_14 [ V_117 ] . V_5 = NULL ;
V_14 [ V_117 ] . V_130 = 0 ;
V_14 [ V_117 ] . V_144 = V_145 ;
V_14 [ V_117 ] . time = V_146 ;
V_14 [ V_117 ] . V_18 = V_147 ;
V_14 [ V_117 ] . V_45 = NULL ;
#ifdef F_29
V_14 [ V_117 ] . V_52 = 0 ;
V_14 [ V_117 ] . V_53 = 0 ;
memset ( & V_14 [ V_117 ] . V_148 , 0 , sizeof ( struct V_100 ) ) ;
#endif
V_14 [ V_117 ] . V_27 = 0 ;
F_76 ( & V_14 [ V_117 ] . V_23 ) ;
F_76 ( & V_14 [ V_117 ] . V_149 ) ;
F_77 ( & V_14 [ V_117 ] . V_55 ) ;
V_14 [ V_117 ] . V_60 = 10 * V_88 ;
}
if ( F_78 ( V_132 , L_15 , & V_150 ) ) {
F_23 ( V_75 L_23 , V_132 ) ;
return - V_35 ;
}
V_131 = F_79 ( V_151 , L_24 ) ;
if ( F_80 ( V_131 ) ) {
V_143 = F_81 ( V_131 ) ;
goto V_152;
}
if ( F_82 ( & V_153 ) ) {
F_23 ( V_75 L_25 ) ;
V_143 = - V_35 ;
goto V_154;
}
if ( ! V_141 ) {
F_23 ( V_32 L_26 ) ;
#ifndef F_83
if ( V_122 [ 0 ] == V_126 )
F_23 ( V_32 L_27 ) ;
#endif
}
return 0 ;
V_154:
F_84 ( V_131 ) ;
V_152:
F_85 ( V_132 , L_15 ) ;
return V_143 ;
}
static int T_5 F_86 ( void )
{
if ( V_8 [ 0 ] ) {
if ( ! strncmp ( V_8 [ 0 ] , L_12 , 4 ) )
V_122 [ 0 ] = V_126 ;
else {
int V_125 ;
for ( V_125 = 0 ; V_125 < V_68 && V_8 [ V_125 ] ; V_125 ++ ) {
if ( ! strncmp ( V_8 [ V_125 ] , L_13 , 4 ) )
V_122 [ V_125 ] = V_127 ;
else {
char * V_155 ;
unsigned long V_156 = F_65 ( V_8 [ V_125 ] , & V_155 , 0 ) ;
if ( V_155 != V_8 [ V_125 ] )
V_122 [ V_125 ] = V_156 ;
else {
F_23 ( V_75 L_28 , V_8 [ V_125 ] ) ;
return - V_85 ;
}
}
}
}
}
return F_75 () ;
}
static void F_87 ( void )
{
unsigned int V_157 ;
F_88 ( & V_153 ) ;
#ifdef F_70
F_74 ( & V_135 ) ;
#endif
F_85 ( V_132 , L_15 ) ;
for ( V_157 = 0 ; V_157 < V_68 ; V_157 ++ ) {
if ( V_14 [ V_157 ] . V_5 == NULL )
continue;
F_89 ( V_14 [ V_157 ] . V_5 ) ;
F_90 ( V_131 , F_69 ( V_132 , V_157 ) ) ;
}
F_84 ( V_131 ) ;
}
