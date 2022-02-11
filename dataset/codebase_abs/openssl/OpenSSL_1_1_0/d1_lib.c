long F_1 ( void )
{
return ( 60 * 60 * 2 ) ;
}
int F_2 ( T_1 * V_1 )
{
T_2 * V_2 ;
if ( ! F_3 ( & V_1 -> V_3 ) ) {
return 0 ;
}
if ( ! F_4 ( V_1 ) )
return ( 0 ) ;
if ( ( V_2 = F_5 ( sizeof( * V_2 ) ) ) == NULL ) {
F_6 ( V_1 ) ;
return ( 0 ) ;
}
V_2 -> V_4 = F_7 () ;
V_2 -> V_5 = F_7 () ;
if ( V_1 -> V_6 ) {
V_2 -> V_7 = sizeof( V_1 -> V_2 -> V_8 ) ;
}
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
if ( V_2 -> V_4 == NULL || V_2 -> V_5 == NULL ) {
F_8 ( V_2 -> V_4 ) ;
F_8 ( V_2 -> V_5 ) ;
F_9 ( V_2 ) ;
F_6 ( V_1 ) ;
return ( 0 ) ;
}
V_1 -> V_2 = V_2 ;
V_1 -> V_11 -> V_12 ( V_1 ) ;
return ( 1 ) ;
}
static void F_10 ( T_1 * V_1 )
{
F_11 ( V_1 ) ;
F_12 ( V_1 ) ;
}
void F_11 ( T_1 * V_1 )
{
T_3 * V_13 = NULL ;
T_4 * V_14 = NULL ;
while ( ( V_13 = F_13 ( V_1 -> V_2 -> V_4 ) ) != NULL ) {
V_14 = ( T_4 * ) V_13 -> V_15 ;
F_14 ( V_14 ) ;
F_15 ( V_13 ) ;
}
}
void F_12 ( T_1 * V_1 )
{
T_3 * V_13 = NULL ;
T_4 * V_14 = NULL ;
while ( ( V_13 = F_13 ( V_1 -> V_2 -> V_5 ) ) != NULL ) {
V_14 = ( T_4 * ) V_13 -> V_15 ;
F_14 ( V_14 ) ;
F_15 ( V_13 ) ;
}
}
void F_16 ( T_1 * V_1 )
{
F_17 ( & V_1 -> V_3 ) ;
F_6 ( V_1 ) ;
F_10 ( V_1 ) ;
F_8 ( V_1 -> V_2 -> V_4 ) ;
F_8 ( V_1 -> V_2 -> V_5 ) ;
F_9 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
}
void F_18 ( T_1 * V_1 )
{
T_5 * V_4 ;
T_5 * V_5 ;
unsigned int V_10 ;
unsigned int V_9 ;
F_19 ( & V_1 -> V_3 ) ;
if ( V_1 -> V_2 ) {
V_4 = V_1 -> V_2 -> V_4 ;
V_5 = V_1 -> V_2 -> V_5 ;
V_10 = V_1 -> V_2 -> V_10 ;
V_9 = V_1 -> V_2 -> V_9 ;
F_10 ( V_1 ) ;
memset ( V_1 -> V_2 , 0 , sizeof( * V_1 -> V_2 ) ) ;
if ( V_1 -> V_6 ) {
V_1 -> V_2 -> V_7 = sizeof( V_1 -> V_2 -> V_8 ) ;
}
if ( F_20 ( V_1 ) & V_16 ) {
V_1 -> V_2 -> V_10 = V_10 ;
V_1 -> V_2 -> V_9 = V_9 ;
}
V_1 -> V_2 -> V_4 = V_4 ;
V_1 -> V_2 -> V_5 = V_5 ;
}
F_21 ( V_1 ) ;
if ( V_1 -> V_11 -> V_17 == V_18 )
V_1 -> V_17 = V_19 ;
#ifndef F_22
else if ( V_1 -> V_20 & V_21 )
V_1 -> V_22 = V_1 -> V_17 = V_23 ;
#endif
else
V_1 -> V_17 = V_1 -> V_11 -> V_17 ;
}
long F_23 ( T_1 * V_1 , int V_24 , long V_25 , void * V_26 )
{
int V_27 = 0 ;
switch ( V_24 ) {
case V_28 :
if ( F_24 ( V_1 , (struct V_29 * ) V_26 ) != NULL ) {
V_27 = 1 ;
}
break;
case V_30 :
V_27 = F_25 ( V_1 ) ;
break;
case V_31 :
if ( V_25 < ( long ) F_26 () )
return 0 ;
V_1 -> V_2 -> V_9 = V_25 ;
return 1 ;
case V_32 :
return ( long ) F_26 () ;
case V_33 :
if ( V_25 < ( long ) F_26 () - V_34 )
return 0 ;
V_1 -> V_2 -> V_10 = V_25 ;
return V_25 ;
default:
V_27 = F_27 ( V_1 , V_24 , V_25 , V_26 ) ;
break;
}
return ( V_27 ) ;
}
void F_28 ( T_1 * V_1 )
{
#ifndef F_29
if ( F_30 ( F_31 ( V_1 ) ) ) {
memset ( & V_1 -> V_2 -> V_35 , 0 , sizeof( V_1 -> V_2 -> V_35 ) ) ;
return;
}
#endif
if ( V_1 -> V_2 -> V_35 . V_36 == 0 && V_1 -> V_2 -> V_35 . V_37 == 0 ) {
V_1 -> V_2 -> V_38 = 1 ;
}
F_32 ( & ( V_1 -> V_2 -> V_35 ) ) ;
V_1 -> V_2 -> V_35 . V_36 += V_1 -> V_2 -> V_38 ;
F_33 ( F_34 ( V_1 ) , V_39 , 0 ,
& ( V_1 -> V_2 -> V_35 ) ) ;
}
struct V_29 * F_24 ( T_1 * V_1 , struct V_29 * V_40 )
{
struct V_29 V_41 ;
if ( V_1 -> V_2 -> V_35 . V_36 == 0 && V_1 -> V_2 -> V_35 . V_37 == 0 ) {
return NULL ;
}
F_32 ( & V_41 ) ;
if ( V_1 -> V_2 -> V_35 . V_36 < V_41 . V_36 ||
( V_1 -> V_2 -> V_35 . V_36 == V_41 . V_36 &&
V_1 -> V_2 -> V_35 . V_37 <= V_41 . V_37 ) ) {
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
return V_40 ;
}
memcpy ( V_40 , & ( V_1 -> V_2 -> V_35 ) , sizeof( struct V_29 ) ) ;
V_40 -> V_36 -= V_41 . V_36 ;
V_40 -> V_37 -= V_41 . V_37 ;
if ( V_40 -> V_37 < 0 ) {
V_40 -> V_36 -- ;
V_40 -> V_37 += 1000000 ;
}
if ( V_40 -> V_36 == 0 && V_40 -> V_37 < 15000 ) {
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
}
return V_40 ;
}
int F_35 ( T_1 * V_1 )
{
struct V_29 V_40 ;
if ( F_24 ( V_1 , & V_40 ) == NULL ) {
return 0 ;
}
if ( V_40 . V_36 > 0 || V_40 . V_37 > 0 ) {
return 0 ;
}
return 1 ;
}
void F_36 ( T_1 * V_1 )
{
V_1 -> V_2 -> V_38 *= 2 ;
if ( V_1 -> V_2 -> V_38 > 60 )
V_1 -> V_2 -> V_38 = 60 ;
F_28 ( V_1 ) ;
}
void F_37 ( T_1 * V_1 )
{
memset ( & V_1 -> V_2 -> V_42 , 0 , sizeof( V_1 -> V_2 -> V_42 ) ) ;
memset ( & V_1 -> V_2 -> V_35 , 0 , sizeof( V_1 -> V_2 -> V_35 ) ) ;
V_1 -> V_2 -> V_38 = 1 ;
F_33 ( F_34 ( V_1 ) , V_39 , 0 ,
& ( V_1 -> V_2 -> V_35 ) ) ;
F_12 ( V_1 ) ;
}
int F_38 ( T_1 * V_1 )
{
unsigned int V_10 ;
V_1 -> V_2 -> V_42 . V_43 ++ ;
if ( V_1 -> V_2 -> V_42 . V_43 > 2
&& ! ( F_20 ( V_1 ) & V_16 ) ) {
V_10 =
F_33 ( F_31 ( V_1 ) , V_44 , 0 , NULL ) ;
if ( V_10 < V_1 -> V_2 -> V_10 )
V_1 -> V_2 -> V_10 = V_10 ;
}
if ( V_1 -> V_2 -> V_42 . V_43 > V_45 ) {
F_39 ( V_46 , V_47 ) ;
return - 1 ;
}
return 0 ;
}
int F_25 ( T_1 * V_1 )
{
if ( ! F_35 ( V_1 ) ) {
return 0 ;
}
F_36 ( V_1 ) ;
if ( F_38 ( V_1 ) < 0 )
return - 1 ;
V_1 -> V_2 -> V_42 . V_48 ++ ;
if ( V_1 -> V_2 -> V_42 . V_48 > V_49 ) {
V_1 -> V_2 -> V_42 . V_48 = 1 ;
}
#ifndef F_40
if ( V_1 -> V_50 ) {
V_1 -> V_50 = 0 ;
return F_41 ( V_1 ) ;
}
#endif
F_28 ( V_1 ) ;
return F_42 ( V_1 ) ;
}
static void F_32 ( struct V_29 * V_51 )
{
#if F_43 ( V_52 )
T_6 V_53 ;
union {
unsigned T_7 V_54 ;
T_8 V_55 ;
} V_56 ;
F_44 ( & V_53 ) ;
F_45 ( & V_53 , & V_56 . V_55 ) ;
# ifdef F_46
V_56 . V_54 -= 116444736000000000ULL ;
# else
V_56 . V_54 -= 116444736000000000UI64 ;
# endif
V_51 -> V_36 = ( long ) ( V_56 . V_54 / 10000000 ) ;
V_51 -> V_37 = ( ( int ) ( V_56 . V_54 % 10000000 ) ) / 10 ;
#elif F_43 ( V_57 )
struct V_58 V_59 ;
F_47 ( & V_59 ) ;
V_51 -> V_36 = ( long ) V_59 . time ;
V_51 -> V_37 = ( long ) V_59 . V_60 * 1000 ;
#else
F_48 ( V_51 , NULL ) ;
#endif
}
int F_49 ( T_1 * V_1 , T_9 * V_61 )
{
int V_62 , V_63 , V_27 = 0 , V_64 = 0 ;
unsigned char V_8 [ V_65 ] ;
unsigned char V_66 [ V_67 ] ;
const unsigned char * V_15 ;
unsigned char * V_68 , * V_69 ;
unsigned long V_70 , V_71 , V_72 , V_73 ;
unsigned int V_74 , V_75 , V_76 , V_77 , V_78 , V_79 ;
T_10 * V_80 , * V_81 ;
T_11 * V_82 ;
T_9 * V_83 = NULL ;
T_12 V_84 , V_85 , V_86 , V_87 , V_88 ;
if ( ! F_50 ( V_1 ) )
return - 1 ;
F_51 () ;
V_80 = F_34 ( V_1 ) ;
V_81 = F_31 ( V_1 ) ;
if ( ! V_80 || ! V_81 ) {
F_39 ( V_89 , V_90 ) ;
return - 1 ;
}
F_33 ( F_34 ( V_1 ) , V_91 , 1 , NULL ) ;
if ( ( V_1 -> V_17 & 0xff00 ) != ( V_92 & 0xff00 ) ) {
F_39 ( V_89 , V_93 ) ;
return - 1 ;
}
if ( V_1 -> V_94 == NULL ) {
if ( ( V_82 = F_52 () ) == NULL ) {
F_39 ( V_89 , V_95 ) ;
return - 1 ;
}
if ( ! F_53 ( V_82 , V_96 ) ) {
F_54 ( V_82 ) ;
F_39 ( V_89 , V_95 ) ;
return - 1 ;
}
V_1 -> V_94 = V_82 ;
}
V_69 = ( unsigned char * ) V_1 -> V_94 -> V_15 ;
do {
F_55 () ;
V_63 = F_56 ( V_80 , V_69 , V_96 ) ;
if ( V_63 <= 0 ) {
if ( F_57 ( V_80 ) ) {
goto V_97;
}
return - 1 ;
}
V_64 = 1 ;
if ( ! F_58 ( & V_84 , V_69 , V_63 ) ) {
F_39 ( V_89 , V_98 ) ;
return - 1 ;
}
if ( V_63 < V_99 ) {
F_39 ( V_89 , V_100 ) ;
goto V_97;
}
if ( V_1 -> V_101 )
V_1 -> V_101 ( 0 , 0 , V_102 , V_69 ,
V_99 , V_1 , V_1 -> V_103 ) ;
if ( ! F_59 ( & V_84 , & V_74 )
|| ! F_59 ( & V_84 , & V_75 ) ) {
F_39 ( V_89 , V_104 ) ;
goto V_97;
}
if ( V_74 != V_105 ) {
F_39 ( V_89 , V_106 ) ;
goto V_97;
}
if ( V_75 != V_107 ) {
F_39 ( V_89 , V_108 ) ;
goto V_97;
}
if ( ! F_60 ( & V_84 , 1 )
|| ! F_61 ( & V_84 , V_66 , V_67 )
|| ! F_62 ( & V_84 , & V_85 ) ) {
F_39 ( V_89 , V_104 ) ;
goto V_97;
}
if ( V_66 [ 0 ] != 0 || V_66 [ 1 ] != 0 ) {
F_39 ( V_89 , V_106 ) ;
goto V_97;
}
V_15 = F_63 ( & V_85 ) ;
if ( ! F_59 ( & V_85 , & V_77 )
|| ! F_64 ( & V_85 , & V_73 )
|| ! F_65 ( & V_85 , & V_76 )
|| ! F_64 ( & V_85 , & V_71 )
|| ! F_64 ( & V_85 , & V_72 )
|| ! F_66 ( & V_85 , & V_86 , V_72 )
|| F_67 ( & V_85 ) != 0 ) {
F_39 ( V_89 , V_104 ) ;
goto V_97;
}
if ( V_77 != V_109 ) {
F_39 ( V_89 , V_106 ) ;
goto V_97;
}
if ( V_76 > 2 ) {
F_39 ( V_89 , V_110 ) ;
goto V_97;
}
if ( V_71 != 0 || V_72 > V_73 ) {
F_39 ( V_89 , V_111 ) ;
goto V_97;
}
if ( V_1 -> V_101 )
V_1 -> V_101 ( 0 , V_1 -> V_17 , V_105 , V_15 ,
V_72 + V_112 , V_1 ,
V_1 -> V_103 ) ;
if ( ! F_65 ( & V_86 , & V_78 ) ) {
F_39 ( V_89 , V_104 ) ;
goto V_97;
}
if ( F_68 ( V_78 , ( unsigned int ) V_1 -> V_11 -> V_17 ) &&
V_1 -> V_11 -> V_17 != V_18 ) {
F_39 ( V_89 , V_113 ) ;
goto V_97;
}
if ( ! F_60 ( & V_86 , V_114 )
|| ! F_69 ( & V_86 , & V_87 )
|| ! F_69 ( & V_86 , & V_88 ) ) {
F_39 ( V_89 , V_104 ) ;
goto V_97;
}
if ( F_67 ( & V_88 ) == 0 ) {
V_62 = V_115 ;
} else {
if ( V_1 -> V_116 -> V_117 == NULL ) {
F_39 ( V_89 , V_118 ) ;
return - 1 ;
}
if ( V_1 -> V_116 -> V_117 ( V_1 , F_63 ( & V_88 ) ,
F_67 ( & V_88 ) ) ==
0 ) {
V_62 = V_115 ;
} else {
V_62 = V_119 ;
}
}
if ( V_62 == V_115 ) {
F_33 ( F_34 ( V_1 ) , V_91 , 0 , NULL ) ;
F_56 ( V_80 , V_69 , V_96 ) ;
F_33 ( F_34 ( V_1 ) , V_91 , 1 , NULL ) ;
if ( V_1 -> V_116 -> V_120 == NULL ||
V_1 -> V_116 -> V_120 ( V_1 , V_8 , & V_79 ) == 0 ||
V_79 > 255 ) {
F_39 ( V_89 , V_121 ) ;
return - 1 ;
}
V_68 = & V_69 [ V_99 ] ;
V_73 = F_70 ( V_68 + V_112 ,
V_8 , V_79 ) ;
* V_68 ++ = V_122 ;
F_71 ( V_73 , V_68 ) ;
F_72 ( 0 , V_68 ) ;
F_71 ( 0 , V_68 ) ;
F_71 ( V_73 , V_68 ) ;
V_70 = V_73 + V_112 ;
V_68 = V_69 ;
* ( V_68 ++ ) = V_105 ;
if ( V_1 -> V_11 -> V_17 == V_18 ) {
* ( V_68 ++ ) = V_92 >> 8 ;
* ( V_68 ++ ) = V_92 & 0xff ;
} else {
* ( V_68 ++ ) = V_1 -> V_17 >> 8 ;
* ( V_68 ++ ) = V_1 -> V_17 & 0xff ;
}
memcpy ( V_68 , V_66 , V_67 ) ;
V_68 += V_67 ;
F_72 ( V_70 , V_68 ) ;
V_70 += V_99 ;
if ( V_1 -> V_101 )
V_1 -> V_101 ( 1 , 0 , V_102 , V_69 ,
V_99 , V_1 , V_1 -> V_103 ) ;
if ( ( V_83 = F_73 () ) == NULL ) {
F_39 ( V_89 , V_95 ) ;
goto V_97;
}
if ( F_74 ( V_80 , V_83 ) > 0 ) {
( void ) F_75 ( V_81 , V_83 ) ;
}
F_76 ( V_83 ) ;
V_83 = NULL ;
if ( F_77 ( V_81 , V_69 , V_70 ) < ( int ) V_70 ) {
if ( F_57 ( V_81 ) ) {
goto V_97;
}
return - 1 ;
}
if ( F_78 ( V_81 ) <= 0 ) {
if ( F_57 ( V_81 ) ) {
goto V_97;
}
return - 1 ;
}
}
} while ( V_62 != V_119 );
V_1 -> V_2 -> V_123 = 1 ;
V_1 -> V_2 -> V_124 = 1 ;
V_1 -> V_2 -> V_125 = 1 ;
F_79 ( & V_1 -> V_3 , V_66 ) ;
F_80 ( V_1 , V_126 ) ;
F_81 ( V_1 ) ;
if ( F_74 ( V_80 , V_61 ) <= 0 )
F_82 ( V_61 ) ;
V_27 = 1 ;
V_64 = 0 ;
V_97:
F_76 ( V_83 ) ;
F_33 ( F_34 ( V_1 ) , V_91 , 0 , NULL ) ;
if ( V_64 ) {
F_56 ( V_80 , V_69 , V_96 ) ;
}
return V_27 ;
}
static int F_83 ( T_1 * V_1 , int V_127 , unsigned long V_128 )
{
F_84 ( V_1 , V_127 , V_128 , 0 , V_128 ) ;
V_1 -> V_129 = ( int ) V_128 + V_112 ;
V_1 -> V_130 = 0 ;
if ( ! F_85 ( V_1 , 0 ) )
return 0 ;
return 1 ;
}
static int F_86 ( T_1 * V_1 )
{
return F_87 ( V_1 , V_105 ) ;
}
int F_88 ( T_1 * V_1 , unsigned char * V_68 , unsigned int V_131 )
{
unsigned char * V_132 ;
unsigned short V_133 ;
unsigned int V_134 ;
unsigned int V_135 = 16 ;
if ( V_1 -> V_101 )
V_1 -> V_101 ( 0 , V_1 -> V_17 , V_136 ,
V_68 , V_131 , V_1 , V_1 -> V_103 ) ;
if ( F_89 ( 0 ) > V_131 )
return 0 ;
if ( V_131 > V_96 )
return 0 ;
V_133 = * V_68 ++ ;
F_90 ( V_68 , V_134 ) ;
if ( F_89 ( V_134 ) > V_131 )
return 0 ;
V_132 = V_68 ;
if ( V_133 == V_137 ) {
unsigned char * V_138 , * V_139 ;
unsigned int V_140 = F_91 ( V_134 , V_135 ) ;
int V_141 ;
if ( V_140 > V_96 )
return 0 ;
V_138 = F_92 ( V_140 ) ;
if ( V_138 == NULL )
return - 1 ;
V_139 = V_138 ;
* V_139 ++ = V_142 ;
F_72 ( V_134 , V_139 ) ;
memcpy ( V_139 , V_132 , V_134 ) ;
V_139 += V_134 ;
if ( F_93 ( V_139 , V_135 ) <= 0 ) {
F_9 ( V_138 ) ;
return - 1 ;
}
V_141 = F_94 ( V_1 , V_136 , V_138 , V_140 ) ;
if ( V_141 >= 0 && V_1 -> V_101 )
V_1 -> V_101 ( 1 , V_1 -> V_17 , V_136 ,
V_138 , V_140 , V_1 , V_1 -> V_103 ) ;
F_9 ( V_138 ) ;
if ( V_141 < 0 )
return V_141 ;
} else if ( V_133 == V_142 ) {
unsigned int V_66 ;
F_90 ( V_132 , V_66 ) ;
if ( V_134 == 18 && V_66 == V_1 -> V_143 ) {
F_37 ( V_1 ) ;
V_1 -> V_143 ++ ;
V_1 -> V_50 = 0 ;
}
}
return 0 ;
}
int F_41 ( T_1 * V_1 )
{
unsigned char * V_69 , * V_68 ;
int V_27 = - 1 ;
unsigned int V_134 = 18 ;
unsigned int V_135 = 16 ;
unsigned int V_144 ;
if ( ! ( V_1 -> V_145 & V_146 ) ||
V_1 -> V_145 & V_147 ) {
F_39 ( V_148 , V_149 ) ;
return - 1 ;
}
if ( V_1 -> V_50 ) {
F_39 ( V_148 , V_150 ) ;
return - 1 ;
}
if ( F_95 ( V_1 ) || F_96 ( V_1 ) ) {
F_39 ( V_148 , V_106 ) ;
return - 1 ;
}
V_144 = F_91 ( V_134 , V_135 ) ;
V_69 = F_92 ( V_144 ) ;
if ( V_69 == NULL ) {
F_39 ( V_148 , V_95 ) ;
return - 1 ;
}
V_68 = V_69 ;
* V_68 ++ = V_137 ;
F_72 ( V_134 , V_68 ) ;
F_72 ( V_1 -> V_143 , V_68 ) ;
if ( F_93 ( V_68 , 16 ) <= 0 ) {
F_39 ( V_148 , V_98 ) ;
goto V_151;
}
V_68 += 16 ;
if ( F_93 ( V_68 , V_135 ) <= 0 ) {
F_39 ( V_148 , V_98 ) ;
goto V_151;
}
V_27 = F_94 ( V_1 , V_136 , V_69 , V_144 ) ;
if ( V_27 >= 0 ) {
if ( V_1 -> V_101 )
V_1 -> V_101 ( 1 , V_1 -> V_17 , V_136 ,
V_69 , V_144 , V_1 , V_1 -> V_103 ) ;
F_28 ( V_1 ) ;
V_1 -> V_50 = 1 ;
}
V_151:
F_9 ( V_69 ) ;
return V_27 ;
}
int F_97 ( T_1 * V_1 )
{
int V_27 ;
#ifndef F_29
T_10 * V_81 ;
V_81 = F_31 ( V_1 ) ;
if ( V_81 != NULL && F_30 ( V_81 ) &&
! ( V_1 -> V_152 & V_153 ) ) {
V_27 = F_98 ( V_81 ) ;
if ( V_27 < 0 )
return - 1 ;
if ( V_27 == 0 )
F_33 ( F_31 ( V_1 ) , V_154 , 1 ,
NULL ) ;
}
#endif
V_27 = F_99 ( V_1 ) ;
#ifndef F_29
F_33 ( F_31 ( V_1 ) , V_154 , 0 , NULL ) ;
#endif
return V_27 ;
}
int F_100 ( T_1 * V_1 )
{
if ( V_1 -> V_2 -> V_9 ) {
V_1 -> V_2 -> V_10 =
V_1 -> V_2 -> V_9 - F_101 ( F_31 ( V_1 ) ) ;
V_1 -> V_2 -> V_9 = 0 ;
}
if ( V_1 -> V_2 -> V_10 < F_102 ( V_1 ) ) {
if ( ! ( F_20 ( V_1 ) & V_16 ) ) {
V_1 -> V_2 -> V_10 =
F_33 ( F_31 ( V_1 ) , V_155 , 0 , NULL ) ;
if ( V_1 -> V_2 -> V_10 < F_102 ( V_1 ) ) {
V_1 -> V_2 -> V_10 = F_102 ( V_1 ) ;
F_33 ( F_31 ( V_1 ) , V_156 ,
V_1 -> V_2 -> V_10 , NULL ) ;
}
} else
return 0 ;
}
return 1 ;
}
static unsigned int F_26 ( void )
{
return ( V_157 [ ( sizeof( V_157 ) /
sizeof( V_157 [ 0 ] ) ) - 1 ] ) ;
}
unsigned int F_102 ( T_1 * V_1 )
{
return F_26 () - F_101 ( F_31 ( V_1 ) ) ;
}
