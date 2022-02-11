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
unsigned int V_12 = F_27 ( V_40 -> V_44 . V_45 -> V_46 ) ;
struct V_8 * V_9 = V_14 [ V_12 ] . V_5 -> V_9 ;
char * V_47 = V_14 [ V_12 ] . V_48 ;
T_1 V_49 = 0 ;
T_1 V_50 ;
T_3 V_51 = V_42 ;
int V_36 = ( ( V_40 -> V_52 & V_53 ) ||
( F_17 ( V_12 ) & V_20 ) ) ;
#ifdef F_28
if ( F_29 ( V_54 , V_14 [ V_12 ] . V_55 + F_30 ( V_12 ) ) )
V_14 [ V_12 ] . V_56 = 0 ;
V_14 [ V_12 ] . V_55 = V_54 ;
#endif
if ( V_51 > V_57 )
V_51 = V_57 ;
if ( F_31 ( & V_14 [ V_12 ] . V_58 ) )
return - V_39 ;
if ( F_32 ( V_47 , V_41 , V_51 ) ) {
V_49 = - V_59 ;
goto V_60;
}
F_1 ( & V_14 [ V_12 ] ) ;
V_14 [ V_12 ] . V_37 = F_9 ( V_9 ,
V_14 [ V_12 ] . V_61 ) ;
F_33 ( V_14 [ V_12 ] . V_5 ,
( V_36 ? V_62
: V_14 [ V_12 ] . V_63 ) ) ;
if ( ( V_49 = F_24 ( V_12 , V_36 ) ) == 0 )
do {
V_50 = F_34 ( V_9 , V_47 , V_51 ) ;
if ( V_50 > 0 ) {
V_51 -= V_50 ;
V_42 -= V_50 ;
V_41 += V_50 ;
V_49 += V_50 ;
}
if ( F_25 ( V_38 ) ) {
if ( V_49 == 0 )
V_49 = - V_39 ;
break;
}
if ( V_51 > 0 ) {
int error ;
F_10 ( V_14 [ V_12 ] . V_5 -> V_9 ,
V_11 ) ;
V_14 [ V_12 ] . V_37 = V_11 ;
error = F_24 ( V_12 , V_36 ) ;
if ( error ) {
if ( V_49 == 0 )
V_49 = error ;
break;
} else if ( V_36 ) {
if ( V_49 == 0 )
V_49 = - V_64 ;
break;
}
F_21 ( V_14 [ V_12 ] . V_5 ) ;
V_14 [ V_12 ] . V_37
= F_9 ( V_9 ,
V_14 [ V_12 ] . V_61 ) ;
} else if ( F_35 () )
F_36 () ;
if ( V_42 ) {
V_51 = V_42 ;
if ( V_51 > V_57 )
V_51 = V_57 ;
if ( F_32 ( V_47 , V_41 , V_51 ) ) {
if ( V_49 == 0 )
V_49 = - V_59 ;
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
V_60:
F_37 ( & V_14 [ V_12 ] . V_58 ) ;
return V_49 ;
}
static T_1 F_38 ( struct V_40 * V_40 , char T_2 * V_41 ,
T_3 V_42 , T_4 * V_43 )
{
F_16 ( V_18 ) ;
unsigned int V_12 = F_27 ( V_40 -> V_44 . V_45 -> V_46 ) ;
struct V_8 * V_9 = V_14 [ V_12 ] . V_5 -> V_9 ;
T_1 V_13 = 0 ;
char * V_47 = V_14 [ V_12 ] . V_48 ;
int V_36 = ( ( V_40 -> V_52 & V_53 ) ||
( F_17 ( V_12 ) & V_20 ) ) ;
if ( V_42 > V_57 )
V_42 = V_57 ;
if ( F_31 ( & V_14 [ V_12 ] . V_58 ) )
return - V_39 ;
F_1 ( & V_14 [ V_12 ] ) ;
F_33 ( V_14 [ V_12 ] . V_5 ,
( V_36 ? V_62
: V_14 [ V_12 ] . V_63 ) ) ;
F_10 ( V_14 [ V_12 ] . V_5 -> V_9 , V_11 ) ;
if ( F_10 ( V_14 [ V_12 ] . V_5 -> V_9 ,
V_65 ) ) {
V_13 = - V_35 ;
goto V_66;
}
while ( V_13 == 0 ) {
V_13 = F_39 ( V_9 , V_47 , V_42 ) ;
if ( V_13 > 0 )
break;
if ( V_36 ) {
V_13 = - V_64 ;
break;
}
if ( V_14 [ V_12 ] . V_5 -> V_9 -> V_21 == V_22 ) {
F_10 ( V_14 [ V_12 ] . V_5 -> V_9 ,
V_11 ) ;
F_15 ( V_12 ) ;
if ( F_10 ( V_14 [ V_12 ] . V_5 -> V_9 ,
V_65 ) ) {
V_13 = - V_35 ;
goto V_66;
}
} else {
F_18 ( & V_14 [ V_12 ] . V_23 , & V_18 , V_24 ) ;
F_19 ( V_25 ) ;
F_20 ( & V_14 [ V_12 ] . V_23 , & V_18 ) ;
}
if ( F_25 ( V_38 ) ) {
V_13 = - V_67 ;
break;
}
F_40 () ;
}
F_10 ( V_14 [ V_12 ] . V_5 -> V_9 , V_11 ) ;
V_66:
F_4 ( & V_14 [ V_12 ] ) ;
if ( V_13 > 0 && F_41 ( V_41 , V_47 , V_13 ) )
V_13 = - V_59 ;
F_37 ( & V_14 [ V_12 ] . V_58 ) ;
return V_13 ;
}
static int F_42 ( struct V_68 * V_68 , struct V_40 * V_40 )
{
unsigned int V_12 = F_27 ( V_68 ) ;
int V_69 = 0 ;
F_43 ( & V_70 ) ;
if ( V_12 >= V_71 ) {
V_69 = - V_72 ;
goto V_66;
}
if ( ( F_17 ( V_12 ) & V_73 ) == 0 ) {
V_69 = - V_72 ;
goto V_66;
}
if ( F_2 ( V_74 , & F_17 ( V_12 ) ) ) {
V_69 = - V_75 ;
goto V_66;
}
if ( ( F_17 ( V_12 ) & V_76 ) && ! ( V_40 -> V_52 & V_53 ) ) {
int V_28 ;
F_1 ( & V_14 [ V_12 ] ) ;
V_28 = F_14 ( V_12 ) ;
F_4 ( & V_14 [ V_12 ] ) ;
if ( V_28 & V_31 ) {
F_23 ( V_32 L_1 , V_12 ) ;
F_17 ( V_12 ) &= ~ V_77 ;
V_69 = - V_33 ;
goto V_66;
} else if ( ! ( V_28 & V_34 ) ) {
F_23 ( V_32 L_2 , V_12 ) ;
F_17 ( V_12 ) &= ~ V_77 ;
V_69 = - V_35 ;
goto V_66;
} else if ( ! ( V_28 & V_29 ) ) {
F_23 ( V_78 L_5 , V_12 ) ;
F_17 ( V_12 ) &= ~ V_77 ;
V_69 = - V_35 ;
goto V_66;
}
}
V_14 [ V_12 ] . V_48 = F_44 ( V_57 , V_79 ) ;
if ( ! V_14 [ V_12 ] . V_48 ) {
F_17 ( V_12 ) &= ~ V_77 ;
V_69 = - V_80 ;
goto V_66;
}
F_1 ( & V_14 [ V_12 ] ) ;
if ( ( V_14 [ V_12 ] . V_5 -> V_9 -> V_81 & V_82 ) &&
! F_10 ( V_14 [ V_12 ] . V_5 -> V_9 ,
V_83 ) ) {
F_23 ( V_32 L_6 , V_12 ) ;
V_14 [ V_12 ] . V_61 = V_83 ;
} else {
V_14 [ V_12 ] . V_61 = V_11 ;
}
F_10 ( V_14 [ V_12 ] . V_5 -> V_9 , V_11 ) ;
F_4 ( & V_14 [ V_12 ] ) ;
V_14 [ V_12 ] . V_37 = V_11 ;
V_66:
F_37 ( & V_70 ) ;
return V_69 ;
}
static int F_45 ( struct V_68 * V_68 , struct V_40 * V_40 )
{
unsigned int V_12 = F_27 ( V_68 ) ;
F_1 ( & V_14 [ V_12 ] ) ;
F_10 ( V_14 [ V_12 ] . V_5 -> V_9 , V_11 ) ;
V_14 [ V_12 ] . V_37 = V_11 ;
F_4 ( & V_14 [ V_12 ] ) ;
F_46 ( V_14 [ V_12 ] . V_48 ) ;
V_14 [ V_12 ] . V_48 = NULL ;
F_17 ( V_12 ) &= ~ V_77 ;
return 0 ;
}
static int F_47 ( unsigned int V_12 , unsigned int V_84 ,
unsigned long V_85 , void T_2 * V_86 )
{
int V_28 ;
int V_13 = 0 ;
#ifdef F_48
F_23 ( V_87 L_7 , V_12 , V_84 , V_85 ) ;
#endif
if ( V_12 >= V_71 )
return - V_88 ;
if ( ( F_17 ( V_12 ) & V_73 ) == 0 )
return - V_88 ;
switch ( V_84 ) {
case V_89 :
F_30 ( V_12 ) = V_85 * V_90 / 100 ;
break;
case V_91 :
F_49 ( V_12 ) = V_85 ;
break;
case V_92 :
if ( V_85 )
F_17 ( V_12 ) |= V_20 ;
else
F_17 ( V_12 ) &= ~ V_20 ;
break;
case V_93 :
if ( V_85 )
F_17 ( V_12 ) |= V_76 ;
else
F_17 ( V_12 ) &= ~ V_76 ;
break;
case V_94 :
if ( V_85 )
F_17 ( V_12 ) |= V_30 ;
else
F_17 ( V_12 ) &= ~ V_30 ;
break;
case V_95 :
F_50 ( V_12 ) = V_85 ;
break;
case V_96 :
return - V_97 ;
break;
case V_98 :
if ( F_41 ( V_86 , & F_51 ( V_12 ) ,
sizeof( int ) ) )
return - V_59 ;
break;
case V_99 :
F_1 ( & V_14 [ V_12 ] ) ;
V_28 = F_14 ( V_12 ) ;
F_4 ( & V_14 [ V_12 ] ) ;
if ( F_41 ( V_86 , & V_28 , sizeof( int ) ) )
return - V_59 ;
break;
case V_100 :
F_11 ( V_12 ) ;
break;
#ifdef F_28
case V_101 :
if ( F_41 ( V_86 , & F_52 ( V_12 ) ,
sizeof( struct V_102 ) ) )
return - V_59 ;
if ( F_53 ( V_103 ) )
memset ( & F_52 ( V_12 ) , 0 ,
sizeof( struct V_102 ) ) ;
break;
#endif
case V_104 :
V_28 = F_17 ( V_12 ) ;
if ( F_41 ( V_86 , & V_28 , sizeof( int ) ) )
return - V_59 ;
break;
default:
V_13 = - V_97 ;
}
return V_13 ;
}
static int F_54 ( unsigned int V_12 , struct V_105 * V_106 )
{
long V_107 ;
if ( ( V_106 -> V_108 < 0 ) ||
( V_106 -> V_109 < 0 ) ) {
return - V_97 ;
}
V_107 = F_55 ( V_106 -> V_109 , 1000000 / V_90 ) ;
V_107 += V_106 -> V_108 * ( long ) V_90 ;
if ( V_107 <= 0 ) {
return - V_97 ;
}
V_14 [ V_12 ] . V_63 = V_107 ;
return 0 ;
}
static long F_56 ( struct V_40 * V_40 , unsigned int V_84 ,
unsigned long V_85 )
{
unsigned int V_12 ;
struct V_105 V_106 ;
int V_69 ;
V_12 = F_27 ( V_40 -> V_44 . V_45 -> V_46 ) ;
F_43 ( & V_70 ) ;
switch ( V_84 ) {
case V_110 :
if ( F_32 ( & V_106 , ( void T_2 * ) V_85 ,
sizeof ( struct V_105 ) ) ) {
V_69 = - V_59 ;
break;
}
V_69 = F_54 ( V_12 , & V_106 ) ;
break;
default:
V_69 = F_47 ( V_12 , V_84 , V_85 , ( void T_2 * ) V_85 ) ;
break;
}
F_37 ( & V_70 ) ;
return V_69 ;
}
static long F_57 ( struct V_40 * V_40 , unsigned int V_84 ,
unsigned long V_85 )
{
unsigned int V_12 ;
struct V_105 V_106 ;
int V_69 ;
V_12 = F_27 ( V_40 -> V_44 . V_45 -> V_46 ) ;
F_43 ( & V_70 ) ;
switch ( V_84 ) {
case V_110 :
if ( F_58 ( & V_106 , F_59 ( V_85 ) ) ) {
V_69 = - V_59 ;
break;
}
V_69 = F_54 ( V_12 , & V_106 ) ;
break;
#ifdef F_28
case V_101 :
V_69 = - V_97 ;
break;
#endif
default:
V_69 = F_47 ( V_12 , V_84 , V_85 , F_59 ( V_85 ) ) ;
break;
}
F_37 ( & V_70 ) ;
return V_69 ;
}
static void F_60 ( struct V_111 * V_112 , const char * V_113 ,
unsigned V_42 )
{
struct V_114 * V_5 = V_14 [ V_115 ] . V_5 ;
struct V_8 * V_9 = V_5 -> V_9 ;
T_1 V_50 ;
if ( F_61 ( V_5 ) )
return;
F_33 ( V_5 , 0 ) ;
F_10 ( V_9 , V_11 ) ;
do {
T_1 V_116 = V_42 ;
char * V_117 = memchr ( V_113 , '\n' , V_42 ) ;
if ( V_117 )
V_116 = V_117 - V_113 ;
if ( V_116 > 0 ) {
V_50 = F_34 ( V_9 , V_113 , V_116 ) ;
if ( V_50 <= 0 )
continue;
V_113 += V_50 ;
V_42 -= V_50 ;
V_116 -= V_50 ;
}
if ( V_117 && V_116 <= 0 ) {
const char * V_118 = L_8 ;
int V_119 = 2 ;
V_113 ++ ;
V_42 -- ;
do {
V_50 = F_34 ( V_9 , V_118 , V_119 ) ;
if ( V_50 > 0 )
V_119 -= V_50 , V_118 += V_50 ;
} while ( V_119 > 0 && ( V_120 || V_50 > 0 ) );
}
} while ( V_42 > 0 && ( V_120 || V_50 > 0 ) );
F_6 ( V_5 ) ;
}
static int T_5 F_62 ( char * V_121 )
{
static int V_122 ;
int V_123 ;
if ( F_63 ( & V_121 , & V_123 ) ) {
if ( V_123 == 0 ) {
V_124 [ 0 ] = V_125 ;
} else {
F_23 ( V_126 L_9 , V_123 ) ;
return 0 ;
}
} else if ( ! strncmp ( V_121 , L_10 , 7 ) ) {
int V_127 = F_64 ( V_121 + 7 , NULL , 10 ) ;
if ( V_122 < V_71 )
V_124 [ V_122 ++ ] = V_127 ;
else
F_23 ( V_32 L_11 ,
V_121 ) ;
} else if ( ! strcmp ( V_121 , L_12 ) ) {
V_124 [ 0 ] = V_128 ;
} else if ( ! strcmp ( V_121 , L_13 ) ) {
V_124 [ V_122 ++ ] = V_129 ;
} else if ( ! strcmp ( V_121 , L_14 ) ) {
V_130 = 1 ;
}
return 1 ;
}
static int F_65 ( int V_131 , struct V_8 * V_9 )
{
V_14 [ V_131 ] . V_5 = F_66 ( V_9 , L_15 ,
F_7 , NULL , NULL , 0 ,
( void * ) & V_14 [ V_131 ] ) ;
if ( V_14 [ V_131 ] . V_5 == NULL )
return 1 ;
V_14 [ V_131 ] . V_132 |= V_73 ;
if ( V_130 )
F_11 ( V_131 ) ;
F_67 ( V_133 , V_9 -> V_5 , F_68 ( V_134 , V_131 ) , NULL ,
L_16 , V_131 ) ;
F_23 ( V_32 L_17 , V_131 , V_9 -> V_135 ,
( V_9 -> V_21 == V_22 ) ? L_18 : L_19 ) ;
#ifdef F_69
if ( ! V_131 ) {
if ( V_9 -> V_81 & V_136 ) {
F_70 ( & V_137 ) ;
V_138 = V_9 ;
F_23 ( V_32 L_20 , V_115 ) ;
} else
F_23 ( V_78 L_21 ,
V_115 , V_9 -> V_135 ) ;
}
#endif
return 0 ;
}
static void F_71 ( struct V_8 * V_9 )
{
unsigned int V_119 ;
switch ( V_124 [ 0 ] ) {
case V_139 :
case V_128 :
if ( V_124 [ 0 ] == V_128 &&
V_9 -> V_140 [ 0 ] . V_141 != V_142 )
return;
if ( V_143 == V_71 ) {
F_23 ( V_32 L_22 , V_71 ) ;
return;
}
if ( ! F_65 ( V_143 , V_9 ) )
V_143 ++ ;
break;
default:
for ( V_119 = 0 ; V_119 < V_71 ; V_119 ++ ) {
if ( V_9 -> V_144 == V_124 [ V_119 ] ) {
if ( ! F_65 ( V_119 , V_9 ) )
V_143 ++ ;
break;
}
}
break;
}
}
static void F_72 ( struct V_8 * V_9 )
{
#ifdef F_69
if ( V_138 == V_9 ) {
F_73 ( & V_137 ) ;
V_138 = NULL ;
}
#endif
}
static int T_5 F_74 ( void )
{
int V_119 , V_145 = 0 ;
if ( V_124 [ 0 ] == V_125 )
return 0 ;
for ( V_119 = 0 ; V_119 < V_71 ; V_119 ++ ) {
V_14 [ V_119 ] . V_5 = NULL ;
V_14 [ V_119 ] . V_132 = 0 ;
V_14 [ V_119 ] . V_146 = V_147 ;
V_14 [ V_119 ] . time = V_148 ;
V_14 [ V_119 ] . V_18 = V_149 ;
V_14 [ V_119 ] . V_48 = NULL ;
#ifdef F_28
V_14 [ V_119 ] . V_55 = 0 ;
V_14 [ V_119 ] . V_56 = 0 ;
memset ( & V_14 [ V_119 ] . V_150 , 0 , sizeof ( struct V_102 ) ) ;
#endif
V_14 [ V_119 ] . V_27 = 0 ;
F_75 ( & V_14 [ V_119 ] . V_23 ) ;
F_75 ( & V_14 [ V_119 ] . V_151 ) ;
F_76 ( & V_14 [ V_119 ] . V_58 ) ;
V_14 [ V_119 ] . V_63 = 10 * V_90 ;
}
if ( F_77 ( V_134 , L_15 , & V_152 ) ) {
F_23 ( V_78 L_23 , V_134 ) ;
return - V_35 ;
}
V_133 = F_78 ( V_153 , L_24 ) ;
if ( F_79 ( V_133 ) ) {
V_145 = F_80 ( V_133 ) ;
goto V_154;
}
if ( F_81 ( & V_155 ) ) {
F_23 ( V_78 L_25 ) ;
V_145 = - V_35 ;
goto V_156;
}
if ( ! V_143 ) {
F_23 ( V_32 L_26 ) ;
#ifndef F_82
if ( V_124 [ 0 ] == V_128 )
F_23 ( V_32 L_27 ) ;
#endif
}
return 0 ;
V_156:
F_83 ( V_133 ) ;
V_154:
F_84 ( V_134 , L_15 ) ;
return V_145 ;
}
static int T_5 F_85 ( void )
{
if ( V_8 [ 0 ] ) {
if ( ! strncmp ( V_8 [ 0 ] , L_12 , 4 ) )
V_124 [ 0 ] = V_128 ;
else {
int V_127 ;
for ( V_127 = 0 ; V_127 < V_71 && V_8 [ V_127 ] ; V_127 ++ ) {
if ( ! strncmp ( V_8 [ V_127 ] , L_13 , 4 ) )
V_124 [ V_127 ] = V_129 ;
else {
char * V_157 ;
unsigned long V_158 = F_64 ( V_8 [ V_127 ] , & V_157 , 0 ) ;
if ( V_157 != V_8 [ V_127 ] )
V_124 [ V_127 ] = V_158 ;
else {
F_23 ( V_78 L_28 , V_8 [ V_127 ] ) ;
return - V_88 ;
}
}
}
}
}
return F_74 () ;
}
static void F_86 ( void )
{
unsigned int V_159 ;
F_87 ( & V_155 ) ;
#ifdef F_69
F_73 ( & V_137 ) ;
#endif
F_84 ( V_134 , L_15 ) ;
for ( V_159 = 0 ; V_159 < V_71 ; V_159 ++ ) {
if ( V_14 [ V_159 ] . V_5 == NULL )
continue;
F_88 ( V_14 [ V_159 ] . V_5 ) ;
F_89 ( V_133 , F_68 ( V_134 , V_159 ) ) ;
}
F_83 ( V_133 ) ;
}
