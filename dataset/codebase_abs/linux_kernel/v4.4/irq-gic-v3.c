static inline unsigned int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) < 32 ;
}
static inline void T_1 * F_3 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return F_4 () ;
if ( V_2 -> V_3 <= 1023 )
return V_4 . V_5 ;
return NULL ;
}
static void F_5 ( void T_1 * V_6 )
{
T_2 V_7 = 1000000 ;
while ( F_6 ( V_6 + V_8 ) & V_9 ) {
V_7 -- ;
if ( ! V_7 ) {
F_7 ( L_1 ) ;
return;
}
F_8 () ;
F_9 ( 1 ) ;
} ;
}
static void F_10 ( void )
{
F_5 ( V_4 . V_5 ) ;
}
static void F_11 ( void )
{
F_5 ( F_12 () ) ;
}
static T_3 T_4 F_13 ( void )
{
if ( F_14 ( & V_10 ) )
return F_15 () ;
else
return F_16 () ;
}
static void F_17 ( bool V_11 )
{
void T_1 * V_12 ;
T_2 V_7 = 1000000 ;
T_2 V_13 ;
V_12 = F_12 () ;
V_13 = F_6 ( V_12 + V_14 ) ;
if ( V_11 )
V_13 &= ~ V_15 ;
else
V_13 |= V_15 ;
F_18 ( V_13 , V_12 + V_14 ) ;
if ( ! V_11 ) {
V_13 = F_6 ( V_12 + V_14 ) ;
if ( ! ( V_13 & V_15 ) )
return;
}
while ( V_7 -- ) {
V_13 = F_6 ( V_12 + V_14 ) ;
if ( V_11 ^ ( V_13 & V_16 ) )
break;
F_8 () ;
F_9 ( 1 ) ;
} ;
if ( ! V_7 )
F_7 ( L_2 ,
V_11 ? L_3 : L_4 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_17 )
{
T_2 V_18 = 1 << ( F_1 ( V_2 ) % 32 ) ;
void T_1 * V_6 ;
if ( F_2 ( V_2 ) )
V_6 = F_4 () ;
else
V_6 = V_4 . V_5 ;
return ! ! ( F_6 ( V_6 + V_17 + ( F_1 ( V_2 ) / 32 ) * 4 ) & V_18 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_2 V_17 )
{
T_2 V_18 = 1 << ( F_1 ( V_2 ) % 32 ) ;
void (* F_21)( void );
void T_1 * V_6 ;
if ( F_2 ( V_2 ) ) {
V_6 = F_4 () ;
F_21 = F_11 ;
} else {
V_6 = V_4 . V_5 ;
F_21 = F_10 ;
}
F_18 ( V_18 , V_6 + V_17 + ( F_1 ( V_2 ) / 32 ) * 4 ) ;
F_21 () ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_19 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
if ( F_24 ( V_2 ) )
F_20 ( V_2 , V_20 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_21 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
enum V_22 V_23 , bool V_13 )
{
T_2 V_24 ;
if ( V_2 -> V_3 >= V_4 . V_25 )
return - V_26 ;
switch ( V_23 ) {
case V_27 :
V_24 = V_13 ? V_28 : V_29 ;
break;
case V_30 :
V_24 = V_13 ? V_31 : V_20 ;
break;
case V_32 :
V_24 = V_13 ? V_19 : V_21 ;
break;
default:
return - V_26 ;
}
F_20 ( V_2 , V_24 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
enum V_22 V_23 , bool * V_13 )
{
if ( V_2 -> V_3 >= V_4 . V_25 )
return - V_26 ;
switch ( V_23 ) {
case V_27 :
* V_13 = F_19 ( V_2 , V_28 ) ;
break;
case V_30 :
* V_13 = F_19 ( V_2 , V_31 ) ;
break;
case V_32 :
* V_13 = ! F_19 ( V_2 , V_21 ) ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( F_1 ( V_2 ) ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) >= 8192 || F_24 ( V_2 ) )
return;
F_31 ( F_1 ( V_2 ) ) ;
}
static int F_32 ( struct V_1 * V_2 , unsigned int type )
{
unsigned int V_33 = F_1 ( V_2 ) ;
void (* F_21)( void );
void T_1 * V_6 ;
if ( V_33 < 16 )
return - V_26 ;
if ( V_33 >= 32 && type != V_34 &&
type != V_35 )
return - V_26 ;
if ( F_2 ( V_2 ) ) {
V_6 = F_4 () ;
F_21 = F_11 ;
} else {
V_6 = V_4 . V_5 ;
F_21 = F_10 ;
}
return F_33 ( V_33 , type , V_6 , F_21 ) ;
}
static int F_34 ( struct V_1 * V_2 , void * V_36 )
{
if ( V_36 )
F_35 ( V_2 ) ;
else
F_36 ( V_2 ) ;
return 0 ;
}
static T_3 F_37 ( unsigned long V_37 )
{
T_3 V_38 ;
V_38 = ( ( T_3 ) F_38 ( V_37 , 3 ) << 32 |
F_38 ( V_37 , 2 ) << 16 |
F_38 ( V_37 , 1 ) << 8 |
F_38 ( V_37 , 0 ) ) ;
return V_38 ;
}
static T_5 void T_6 F_39 ( struct V_39 * V_40 )
{
T_2 V_41 ;
do {
V_41 = F_13 () ;
if ( F_40 ( V_41 > 15 && V_41 < 1020 ) || V_41 >= 8192 ) {
int V_42 ;
if ( F_41 ( & V_43 ) )
F_29 ( V_41 ) ;
V_42 = F_42 ( V_4 . V_44 , V_41 , V_40 ) ;
if ( V_42 ) {
F_43 ( true , L_5 ) ;
if ( F_41 ( & V_43 ) ) {
if ( V_41 < 8192 )
F_31 ( V_41 ) ;
} else {
F_29 ( V_41 ) ;
}
}
continue;
}
if ( V_41 < 16 ) {
F_29 ( V_41 ) ;
if ( F_41 ( & V_43 ) )
F_31 ( V_41 ) ;
#ifdef F_44
F_45 ( V_41 , V_40 ) ;
#else
F_43 ( true , L_6 ) ;
#endif
continue;
}
} while ( V_41 != V_45 );
}
static void T_7 F_46 ( void )
{
unsigned int V_46 ;
T_3 V_47 ;
void T_1 * V_6 = V_4 . V_5 ;
F_18 ( 0 , V_6 + V_8 ) ;
F_10 () ;
F_47 ( V_6 , V_4 . V_25 , F_10 ) ;
F_18 ( V_48 | V_49 | V_50 ,
V_6 + V_8 ) ;
V_47 = F_37 ( F_48 ( F_49 () ) ) ;
for ( V_46 = 32 ; V_46 < V_4 . V_25 ; V_46 ++ )
F_50 ( V_47 , V_6 + V_51 + V_46 * 8 ) ;
}
static int F_51 ( void )
{
unsigned long V_37 = F_48 ( F_49 () ) ;
T_3 V_52 ;
T_2 V_38 ;
int V_46 ;
V_38 = ( F_38 ( V_37 , 3 ) << 24 |
F_38 ( V_37 , 2 ) << 16 |
F_38 ( V_37 , 1 ) << 8 |
F_38 ( V_37 , 0 ) ) ;
for ( V_46 = 0 ; V_46 < V_4 . V_53 ; V_46 ++ ) {
void T_1 * V_54 = V_4 . V_55 [ V_46 ] . V_56 ;
T_2 V_24 ;
V_24 = F_6 ( V_54 + V_57 ) & V_58 ;
if ( V_24 != V_59 &&
V_24 != V_60 ) {
F_52 ( L_7 , V_54 ) ;
break;
}
do {
V_52 = F_53 ( V_54 + V_61 ) ;
if ( ( V_52 >> 32 ) == V_38 ) {
T_3 V_17 = V_54 - V_4 . V_55 [ V_46 ] . V_56 ;
F_12 () = V_54 ;
F_54 () -> V_62 = V_4 . V_55 [ V_46 ] . V_62 + V_17 ;
F_55 ( L_8 ,
F_49 () , V_37 , V_46 ,
& F_54 () -> V_62 ) ;
return 0 ;
}
if ( V_4 . V_63 ) {
V_54 += V_4 . V_63 ;
} else {
V_54 += V_64 * 2 ;
if ( V_52 & V_65 )
V_54 += V_64 * 2 ;
}
} while ( ! ( V_52 & V_66 ) );
}
F_56 ( true , L_9 ,
F_49 () , V_37 ) ;
return - V_67 ;
}
static void F_57 ( void )
{
if ( ! F_58 () )
F_59 ( L_10 ) ;
F_60 ( V_68 ) ;
if ( F_41 ( & V_43 ) ) {
F_61 ( V_69 ) ;
} else {
F_61 ( V_70 ) ;
}
F_62 ( 1 ) ;
}
static int F_63 ( void )
{
return ! ! ( F_6 ( V_4 . V_5 + V_71 ) & V_72 ) ;
}
static void F_64 ( void )
{
void T_1 * V_12 ;
if ( F_51 () )
return;
F_17 ( true ) ;
V_12 = F_4 () ;
F_65 ( V_12 , F_11 ) ;
if ( F_66 ( V_73 ) && F_63 () )
F_67 () ;
F_57 () ;
}
static int F_68 ( struct V_74 * V_75 ,
unsigned long V_76 , void * V_77 )
{
if ( V_76 == V_78 || V_76 == V_79 )
F_64 () ;
return V_80 ;
}
static T_8 F_69 ( int * V_81 , const struct V_82 * V_18 ,
unsigned long V_83 )
{
int V_84 = * V_81 ;
unsigned long V_37 = F_48 ( V_84 ) ;
T_8 V_85 = 0 ;
while ( V_84 < V_86 ) {
if ( F_70 ( ( V_37 & 0xff ) >= 16 ) )
goto V_87;
V_85 |= 1 << ( V_37 & 0xf ) ;
V_84 = F_71 ( V_84 , V_18 ) ;
if ( V_84 >= V_86 )
goto V_87;
V_37 = F_48 ( V_84 ) ;
if ( V_83 != ( V_37 & ~ 0xffUL ) ) {
V_84 -- ;
goto V_87;
}
}
V_87:
* V_81 = V_84 ;
return V_85 ;
}
static void F_72 ( T_3 V_83 , T_8 V_85 , unsigned int V_33 )
{
T_3 V_13 ;
V_13 = ( F_73 ( V_83 , 3 ) |
F_73 ( V_83 , 2 ) |
V_33 << V_88 |
F_73 ( V_83 , 1 ) |
V_85 << V_89 ) ;
F_74 ( L_11 , F_49 () , V_13 ) ;
F_75 ( V_13 ) ;
}
static void F_76 ( const struct V_82 * V_18 , unsigned int V_33 )
{
int V_84 ;
if ( F_70 ( V_33 >= 16 ) )
return;
F_77 () ;
F_78 (cpu, mask) {
unsigned long V_83 = F_48 ( V_84 ) & ~ 0xffUL ;
T_8 V_85 ;
V_85 = F_69 ( & V_84 , V_18 , V_83 ) ;
F_72 ( V_83 , V_85 , V_33 ) ;
}
F_79 () ;
}
static void F_80 ( void )
{
F_81 ( F_76 ) ;
F_82 ( & V_90 ) ;
}
static int F_83 ( struct V_1 * V_2 , const struct V_82 * V_91 ,
bool V_92 )
{
unsigned int V_84 = F_84 ( V_91 , V_93 ) ;
void T_1 * V_24 ;
int V_94 ;
T_3 V_13 ;
if ( F_2 ( V_2 ) )
return - V_26 ;
V_94 = F_19 ( V_2 , V_21 ) ;
if ( V_94 )
F_22 ( V_2 ) ;
V_24 = F_3 ( V_2 ) + V_51 + ( F_1 ( V_2 ) * 8 ) ;
V_13 = F_37 ( F_48 ( V_84 ) ) ;
F_50 ( V_13 , V_24 ) ;
if ( V_94 )
F_25 ( V_2 ) ;
else
F_10 () ;
return V_95 ;
}
static int F_85 ( struct V_74 * V_96 ,
unsigned long V_97 , void * V_98 )
{
if ( V_97 == V_99 ) {
F_17 ( true ) ;
F_57 () ;
} else if ( V_97 == V_100 ) {
F_62 ( 0 ) ;
F_17 ( false ) ;
}
return V_80 ;
}
static void F_86 ( void )
{
F_87 ( & V_101 ) ;
}
static inline void F_86 ( void ) { }
static int F_88 ( struct V_102 * V_2 , unsigned int V_33 ,
T_9 V_103 )
{
struct V_104 * V_105 = & V_106 ;
if ( F_41 ( & V_43 ) )
V_105 = & V_107 ;
if ( V_103 < 16 )
return - V_108 ;
if ( V_103 >= V_4 . V_25 && V_103 < 8192 )
return - V_108 ;
if ( V_103 >= V_109 )
return - V_108 ;
if ( V_103 < 32 ) {
F_89 ( V_33 ) ;
F_90 ( V_2 , V_33 , V_103 , V_105 , V_2 -> V_110 ,
V_111 , NULL , NULL ) ;
F_91 ( V_33 , V_112 ) ;
}
if ( V_103 >= 32 && V_103 < V_4 . V_25 ) {
F_90 ( V_2 , V_33 , V_103 , V_105 , V_2 -> V_110 ,
V_113 , NULL , NULL ) ;
F_92 ( V_33 ) ;
}
if ( V_103 >= 8192 && V_103 < V_109 ) {
if ( ! F_63 () )
return - V_108 ;
F_90 ( V_2 , V_33 , V_103 , V_105 , V_2 -> V_110 ,
V_113 , NULL , NULL ) ;
}
return 0 ;
}
static int F_93 ( struct V_102 * V_2 ,
struct V_114 * V_115 ,
unsigned long * V_3 ,
unsigned int * type )
{
if ( F_94 ( V_115 -> V_116 ) ) {
if ( V_115 -> V_117 < 3 )
return - V_26 ;
switch ( V_115 -> V_118 [ 0 ] ) {
case 0 :
* V_3 = V_115 -> V_118 [ 1 ] + 32 ;
break;
case 1 :
* V_3 = V_115 -> V_118 [ 1 ] + 16 ;
break;
case V_119 :
* V_3 = V_115 -> V_118 [ 1 ] ;
break;
default:
return - V_26 ;
}
* type = V_115 -> V_118 [ 2 ] & V_120 ;
return 0 ;
}
return - V_26 ;
}
static int F_95 ( struct V_102 * V_44 , unsigned int V_121 ,
unsigned int V_122 , void * V_123 )
{
int V_46 , V_124 ;
T_9 V_3 ;
unsigned int type = V_125 ;
struct V_114 * V_115 = V_123 ;
V_124 = F_93 ( V_44 , V_115 , & V_3 , & type ) ;
if ( V_124 )
return V_124 ;
for ( V_46 = 0 ; V_46 < V_122 ; V_46 ++ )
F_88 ( V_44 , V_121 + V_46 , V_3 + V_46 ) ;
return 0 ;
}
static void F_96 ( struct V_102 * V_44 , unsigned int V_121 ,
unsigned int V_122 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_122 ; V_46 ++ ) {
struct V_1 * V_2 = F_97 ( V_44 , V_121 + V_46 ) ;
F_98 ( V_121 + V_46 , NULL ) ;
F_99 ( V_2 ) ;
}
}
static void F_100 ( void )
{
#ifdef F_101
if ( F_102 ( V_126 ) )
F_103 ( & V_10 ) ;
#endif
}
static int T_7 F_104 ( struct V_127 * V_128 , struct V_127 * V_129 )
{
void T_1 * V_5 ;
struct V_130 * V_131 ;
T_3 V_63 ;
T_2 V_53 ;
T_2 V_52 ;
T_2 V_24 ;
int V_132 ;
int V_42 ;
int V_46 ;
V_5 = F_105 ( V_128 , 0 ) ;
if ( ! V_5 ) {
F_59 ( L_12 ,
V_128 -> V_133 ) ;
return - V_134 ;
}
V_24 = F_6 ( V_5 + V_135 ) & V_58 ;
if ( V_24 != V_59 && V_24 != V_60 ) {
F_59 ( L_13 ,
V_128 -> V_133 ) ;
V_42 = - V_67 ;
goto V_136;
}
if ( F_106 ( V_128 , L_14 , & V_53 ) )
V_53 = 1 ;
V_131 = F_107 ( sizeof( * V_131 ) * V_53 , V_137 ) ;
if ( ! V_131 ) {
V_42 = - V_138 ;
goto V_136;
}
for ( V_46 = 0 ; V_46 < V_53 ; V_46 ++ ) {
struct V_139 V_140 ;
int V_124 ;
V_124 = F_108 ( V_128 , 1 + V_46 , & V_140 ) ;
V_131 [ V_46 ] . V_56 = F_105 ( V_128 , 1 + V_46 ) ;
if ( V_124 || ! V_131 [ V_46 ] . V_56 ) {
F_59 ( L_15 ,
V_128 -> V_133 , V_46 ) ;
V_42 = - V_67 ;
goto V_141;
}
V_131 [ V_46 ] . V_62 = V_140 . V_142 ;
}
if ( F_109 ( V_128 , L_16 , & V_63 ) )
V_63 = 0 ;
if ( ! F_110 () )
F_111 ( & V_43 ) ;
if ( F_41 ( & V_43 ) )
F_55 ( L_17 ) ;
V_4 . V_5 = V_5 ;
V_4 . V_55 = V_131 ;
V_4 . V_53 = V_53 ;
V_4 . V_63 = V_63 ;
F_100 () ;
V_52 = F_6 ( V_4 . V_5 + V_71 ) ;
V_4 . V_143 . V_144 = F_112 ( V_52 ) ;
V_132 = F_113 ( V_52 ) ;
if ( V_132 > 1020 )
V_132 = 1020 ;
V_4 . V_25 = V_132 ;
V_4 . V_44 = F_114 ( V_128 , & V_145 ,
& V_4 ) ;
V_4 . V_143 . V_146 = F_115 ( F_116 ( * V_4 . V_143 . V_146 ) ) ;
if ( F_70 ( ! V_4 . V_44 ) || F_70 ( ! V_4 . V_143 . V_146 ) ) {
V_42 = - V_138 ;
goto V_147;
}
F_117 ( F_39 ) ;
if ( F_66 ( V_73 ) && F_63 () )
F_118 ( V_128 , & V_4 . V_143 , V_4 . V_44 ) ;
F_80 () ;
F_46 () ;
F_64 () ;
F_86 () ;
return 0 ;
V_147:
if ( V_4 . V_44 )
F_119 ( V_4 . V_44 ) ;
F_120 ( V_4 . V_143 . V_146 ) ;
V_141:
for ( V_46 = 0 ; V_46 < V_53 ; V_46 ++ )
if ( V_131 [ V_46 ] . V_56 )
F_121 ( V_131 [ V_46 ] . V_56 ) ;
F_122 ( V_131 ) ;
V_136:
F_121 ( V_5 ) ;
return V_42 ;
}
