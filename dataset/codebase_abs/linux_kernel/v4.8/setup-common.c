void F_1 ( void )
{
#ifdef F_2
F_3 () ;
#endif
if ( V_1 . F_1 )
V_1 . F_1 () ;
}
void F_4 ( char * V_2 )
{
F_1 () ;
if ( V_1 . V_3 )
V_1 . V_3 ( V_2 ) ;
F_5 () ;
F_6 ( V_4 L_1 ) ;
F_7 () ;
while ( 1 ) ;
}
void F_8 ( void )
{
F_1 () ;
if ( V_5 )
V_5 () ;
F_5 () ;
F_6 ( V_4 L_1 ) ;
F_7 () ;
while ( 1 ) ;
}
void F_9 ( void )
{
F_1 () ;
if ( V_1 . V_6 )
V_1 . V_6 () ;
F_5 () ;
F_6 ( V_4 L_1 ) ;
F_7 () ;
while ( 1 ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
const char * V_11 = NULL ;
#if F_11 ( V_12 ) && F_11 ( V_13 )
unsigned long V_14 = 0 ;
int V_15 ;
F_12 (i)
V_14 += V_16 ;
F_13 ( V_8 , L_2 ,
V_14 / ( 500000 / V_17 ) , V_14 / ( 5000 / V_17 ) % 100 ) ;
#endif
F_13 ( V_8 , L_3 , V_18 ) ;
if ( V_1 . V_19 )
F_13 ( V_8 , L_4 , V_1 . V_19 ) ;
V_10 = F_14 ( L_5 ) ;
if ( V_10 )
V_11 = F_15 ( V_10 , L_6 , NULL ) ;
if ( V_11 )
F_13 ( V_8 , L_7 , V_11 ) ;
F_16 ( V_10 ) ;
if ( V_1 . V_20 != NULL )
V_1 . V_20 ( V_8 ) ;
#ifdef V_13
F_13 ( V_8 , L_8 ,
( unsigned int ) ( V_21 / ( 1024 * 1024 ) ) ) ;
#endif
}
static int V_20 ( struct V_7 * V_8 , void * V_22 )
{
unsigned long V_23 = ( unsigned long ) V_22 - 1 ;
unsigned int V_24 ;
unsigned long V_25 ;
unsigned short V_26 ;
unsigned short V_27 ;
F_17 () ;
if ( ! F_18 ( V_23 ) ) {
F_19 () ;
return 0 ;
}
#ifdef V_12
V_24 = F_20 ( V_28 , V_23 ) ;
#else
V_24 = F_21 ( V_29 ) ;
#endif
V_26 = ( V_24 >> 8 ) & 0xFF ;
V_27 = V_24 & 0xFF ;
F_13 ( V_8 , L_9 , V_23 ) ;
F_13 ( V_8 , L_10 ) ;
if ( V_30 -> V_31 )
F_13 ( V_8 , L_11 , V_30 -> V_32 ) ;
else
F_13 ( V_8 , L_12 , V_24 ) ;
#ifdef F_22
if ( F_23 ( V_33 ) )
F_13 ( V_8 , L_13 ) ;
#endif
F_13 ( V_8 , L_14 ) ;
#ifdef F_24
if ( V_30 -> V_34 & V_35 ) {
#ifdef F_25
F_13 ( V_8 , L_15 ,
F_26 ( V_23 ) ) ;
#else
T_1 V_36 ;
V_36 = F_27 ( V_23 ) ;
F_13 ( V_8 , L_16 ,
V_36 & 0xff , V_36 >> 16 ) ;
#endif
}
#endif
if ( V_1 . V_37 )
V_25 = V_1 . V_37 ( V_23 ) ;
else
V_25 = V_38 ;
if ( V_25 )
F_13 ( V_8 , L_17 ,
V_25 / 1000000 , V_25 % 1000000 ) ;
if ( V_1 . V_39 != NULL )
V_1 . V_39 ( V_8 , V_23 ) ;
if ( F_28 ( V_24 ) & 0x8000 ) {
switch ( F_28 ( V_24 ) ) {
case 0x8000 :
case 0x8001 :
case 0x8002 :
case 0x8003 :
case 0x8004 :
case 0x800c :
V_26 = ( ( V_24 >> 8 ) & 0xF ) ;
V_27 = F_29 ( V_24 ) ;
break;
default:
V_26 = F_30 ( V_24 ) ;
V_27 = F_29 ( V_24 ) ;
break;
}
} else {
switch ( F_28 ( V_24 ) ) {
case 0x0020 :
V_26 = F_30 ( V_24 ) + 1 ;
V_27 = F_29 ( V_24 ) ;
break;
case 0x1008 :
V_26 = ( ( V_24 >> 8 ) & 0xFF ) - 1 ;
V_27 = V_24 & 0xFF ;
break;
default:
V_26 = ( V_24 >> 8 ) & 0xFF ;
V_27 = V_24 & 0xFF ;
break;
}
}
F_13 ( V_8 , L_18 ,
V_26 , V_27 , F_28 ( V_24 ) , F_31 ( V_24 ) ) ;
#ifdef V_13
F_13 ( V_8 , L_19 ,
V_16 / ( 500000 / V_17 ) ,
( V_16 / ( 5000 / V_17 ) ) % 100 ) ;
#endif
#ifdef V_12
F_13 ( V_8 , L_14 ) ;
#endif
F_19 () ;
if ( F_32 ( V_23 , V_40 ) >= V_41 )
F_10 ( V_8 ) ;
return 0 ;
}
static void * F_33 ( struct V_7 * V_8 , T_2 * V_42 )
{
if ( * V_42 == 0 )
* V_42 = F_34 ( V_40 ) ;
else
* V_42 = F_32 ( * V_42 - 1 , V_40 ) ;
if ( ( * V_42 ) < V_41 )
return ( void * ) ( unsigned long ) ( * V_42 + 1 ) ;
return NULL ;
}
static void * F_35 ( struct V_7 * V_8 , void * V_22 , T_2 * V_42 )
{
( * V_42 ) ++ ;
return F_33 ( V_8 , V_42 ) ;
}
static void F_36 ( struct V_7 * V_8 , void * V_22 )
{
}
void T_3 F_37 ( void )
{
#ifdef F_38
F_39 ( L_20 ,
V_43 , V_44 ) ;
if ( F_40 ( V_43 ) && F_40 ( V_44 ) &&
V_44 > V_43 )
V_45 = V_46 ;
else
V_43 = V_44 = 0 ;
if ( V_43 )
F_41 ( L_21 , V_43 , V_44 ) ;
F_39 ( L_22 ) ;
#endif
}
static void T_3 F_42 ( int V_47 )
{
int V_15 ;
V_48 = V_47 ;
V_49 = V_47 ;
F_43 ( & V_50 ) ;
V_51 = F_44 ( V_47 ) ;
F_45 ( V_47 != ( 1 << V_51 ) ) ;
for ( V_15 = 0 ; V_15 < V_47 ; V_15 ++ )
F_46 ( V_15 , & V_50 ) ;
F_6 ( V_52 L_23 ,
V_47 , V_47 > 1 ? L_24 : L_25 ) ;
F_6 ( V_53 L_26 , V_51 ) ;
}
void T_3 F_47 ( void )
{
struct V_9 * V_54 = NULL ;
int V_55 = 0 ;
int V_56 = 1 ;
F_39 ( L_27 ) ;
while ( ( V_54 = F_48 ( V_54 , L_28 ) ) && V_55 < V_41 ) {
const T_4 * V_57 ;
T_4 V_58 ;
int V_59 , V_60 ;
F_39 ( L_29 , V_54 -> V_61 ) ;
V_57 = F_15 ( V_54 , L_30 ,
& V_60 ) ;
if ( V_57 ) {
F_39 ( L_31 ,
V_56 ) ;
} else {
F_39 ( L_32 ) ;
V_57 = F_15 ( V_54 , L_33 , & V_60 ) ;
if ( ! V_57 ) {
V_58 = F_49 ( V_55 ) ;
V_57 = & V_58 ;
V_60 = 4 ;
}
}
V_56 = V_60 / sizeof( int ) ;
for ( V_59 = 0 ; V_59 < V_56 && V_55 < V_41 ; V_59 ++ ) {
bool V_62 ;
F_39 ( L_34 ,
V_59 , V_55 , F_50 ( V_57 [ V_59 ] ) ) ;
V_62 = F_51 ( V_54 ) ;
if ( ! V_62 )
V_62 = ! F_52 ( V_54 ,
L_35 , L_36 ) ;
F_53 ( V_55 , V_62 ) ;
F_54 ( V_55 , F_50 ( V_57 [ V_59 ] ) ) ;
F_55 ( V_55 , true ) ;
V_55 ++ ;
}
}
if ( ! F_23 ( V_63 ) ) {
F_39 ( L_37 ) ;
V_56 = 1 ;
}
#ifdef F_56
if ( F_57 ( V_64 ) &&
( V_54 = F_14 ( L_38 ) ) ) {
int V_65 , V_66 , V_67 ;
const T_4 * V_68 ;
V_65 = F_58 ( V_54 ) ;
V_66 = F_59 ( V_54 ) ;
V_68 = F_15 ( V_54 , L_39 , NULL ) ;
if ( ! V_68 )
goto V_69;
V_67 = F_60 ( V_68 + V_65 + V_66 ) ;
if ( F_23 ( V_63 ) )
V_67 *= V_56 ;
if ( V_67 > V_41 ) {
F_6 ( V_70
L_40
L_41 ,
V_67 , V_41 ) ;
V_67 = V_41 ;
} else
F_6 ( V_52 L_42 ,
V_67 ) ;
for ( V_55 = 0 ; V_55 < V_67 ; V_55 ++ )
F_55 ( V_55 , true ) ;
V_69:
F_16 ( V_54 ) ;
}
V_71 -> V_72 = F_61 () ;
#endif
F_42 ( V_56 ) ;
F_62 () ;
F_63 () ;
}
static T_3 int F_64 ( void )
{
struct V_9 * V_73 ;
struct V_74 * V_75 ;
int V_76 ;
V_73 = F_65 ( NULL , NULL , L_43 ) ;
F_16 ( V_73 ) ;
if ( ! V_73 )
return - V_77 ;
V_75 = F_66 ( L_44 , - 1 ) ;
if ( ! V_75 )
return - V_78 ;
V_76 = F_67 ( V_75 ) ;
if ( V_76 )
F_68 ( V_75 ) ;
return V_76 ;
}
void F_69 ( void )
{
extern struct V_79 V_80 ;
extern struct V_79 V_81 ;
unsigned int V_15 ;
F_39 ( L_45 ) ;
for ( V_15 = 0 ; V_15 < ( sizeof( V_1 ) / sizeof( void * ) ) ; V_15 ++ ) {
if ( ( ( void * * ) & V_1 ) [ V_15 ] ) {
F_6 ( V_82 L_46
L_47 , V_15 ) ;
}
}
for ( V_83 = & V_80 ;
V_83 < & V_81 ;
V_83 ++ ) {
F_39 ( L_48 , V_83 -> V_19 ) ;
memcpy ( & V_1 , V_83 , sizeof( struct V_79 ) ) ;
if ( V_1 . V_84 () ) {
F_39 ( L_49 ) ;
break;
}
F_39 ( L_14 ) ;
}
if ( V_83 >= & V_81 ) {
F_39 ( L_50 ) ;
for (; ; ) ;
}
F_6 ( V_52 L_51 , V_1 . V_19 ) ;
}
int F_70 ( unsigned long V_85 )
{
struct V_9 * V_86 , * V_73 = NULL ;
int V_76 = - V_77 ;
switch( V_85 ) {
case V_87 :
if ( ! ( V_73 = F_65 ( NULL , NULL , L_52 ) ) )
V_73 = F_65 ( NULL , NULL , L_53 ) ;
if ( V_73 ) {
V_86 = F_71 ( V_73 ) ;
V_88 = F_72 ( V_86 , 0 ) ;
if ( ! V_88 )
V_88 = 1 ;
V_89 = F_72 ( V_86 , 1 ) ;
if ( ! V_89 )
V_89 = 12 ;
F_16 ( V_73 ) ;
V_73 = V_86 ;
break;
}
V_73 = F_48 ( NULL , L_54 ) ;
if ( ! V_73 )
V_73 = F_73 ( NULL , L_54 ) ;
if ( V_73 ) {
V_88 = 1 ;
V_89 = 12 ;
}
break;
case V_90 :
V_73 = F_48 ( NULL , L_55 ) ;
break;
default:
break;
}
if ( ! V_73 )
return V_76 ;
V_86 = F_71 ( V_73 ) ;
if ( V_86 ) {
if ( strcmp ( V_86 -> type , L_56 ) == 0 )
V_76 = 0 ;
F_16 ( V_86 ) ;
}
F_16 ( V_73 ) ;
return V_76 ;
}
static int F_74 ( struct V_91 * V_92 ,
unsigned long V_93 , void * V_94 )
{
F_75 ( NULL , V_94 ) ;
V_1 . V_95 ( V_94 ) ;
return V_96 ;
}
void T_3 F_76 ( void )
{
if ( ! V_1 . V_95 )
return;
F_77 ( & V_97 , & V_98 ) ;
}
static int T_3 F_78 ( void )
{
struct V_9 * V_73 ;
const void * V_99 ;
int V_100 ;
V_73 = F_14 ( L_5 ) ;
V_99 = F_15 ( V_73 , L_57 , NULL ) ;
F_16 ( V_73 ) ;
V_100 = V_99 ? 0 : 1 ;
if ( V_100 != V_101 ) {
F_6 ( V_82
L_58 ,
V_101 ? L_59 : L_60 ,
V_100 ? L_59 : L_60 ) ;
F_79 () ;
}
return 0 ;
}
static int F_80 ( void )
{
V_102 = F_81 ( L_61 , NULL ) ;
return V_102 == NULL ;
}
void F_82 ( char * V_103 , unsigned short V_104 )
{
F_41 ( L_62 , V_103 ) ;
}
void F_83 ( struct V_74 * V_105 )
{
V_105 -> V_106 . V_107 = F_84 ( 32 ) ;
V_105 -> V_108 . V_107 = & V_105 -> V_106 . V_107 ;
F_85 ( & V_105 -> V_108 , & V_109 ) ;
}
static T_3 void F_86 ( void )
{
F_41 ( L_63 ) ;
#ifdef F_87
F_41 ( L_64 , V_110 ) ;
#endif
#ifdef F_88
F_41 ( L_65 , V_111 ) ;
#endif
F_41 ( L_66 ,
( unsigned long long ) F_89 () ) ;
F_41 ( L_67 , V_112 ) ;
F_41 ( L_68 , V_113 ) ;
if ( V_114 != 0 )
F_41 ( L_69 , V_114 ) ;
F_41 ( L_70 , V_30 -> V_34 ) ;
F_41 ( L_71 ,
( unsigned long ) V_115 ) ;
F_41 ( L_72 ,
( unsigned long ) V_116 ) ;
F_41 ( L_73 ,
V_30 -> V_117 ,
V_30 -> V_118 ) ;
F_41 ( L_74 , V_30 -> V_119 ) ;
#ifdef F_56
F_41 ( L_75 , V_120 ) ;
#endif
#ifdef F_87
if ( V_121 )
F_41 ( L_76 , V_121 ) ;
if ( V_122 )
F_41 ( L_77 , V_122 ) ;
#endif
#ifdef F_88
if ( V_123 )
F_41 ( L_78 , V_123 ) ;
if ( V_124 )
F_41 ( L_79 , V_124 ) ;
#endif
if ( V_125 > 0 )
F_41 ( L_80 ,
( unsigned long long ) V_125 ) ;
F_41 ( L_63 ) ;
}
void T_3 F_90 ( char * * V_126 )
{
* V_126 = V_127 ;
V_16 = 500000000 / V_17 ;
F_91 () ;
F_92 () ;
F_93 () ;
F_37 () ;
F_69 () ;
F_76 () ;
F_94 () ;
F_95 () ;
F_96 () ;
F_47 () ;
F_97 () ;
F_98 () ;
F_99 () ;
#ifdef V_12
F_100 () ;
#endif
F_86 () ;
F_101 () ;
F_102 () ;
F_103 ( & V_128 ) ;
V_129 . V_130 = ( unsigned long ) V_131 ;
V_129 . V_132 = ( unsigned long ) V_133 ;
V_129 . V_134 = ( unsigned long ) V_135 ;
V_129 . V_136 = V_137 ;
#ifdef F_104
V_129 . V_138 . V_139 = NULL ;
#endif
#ifdef F_105
F_106 ( & V_129 . V_138 ) ;
#endif
F_107 () ;
F_108 () ;
F_109 () ;
F_110 () ;
#ifdef F_111
V_140 = & V_141 ;
#endif
if ( V_1 . F_90 )
V_1 . F_90 () ;
F_112 () ;
F_113 () ;
#ifdef F_56
if ( ( unsigned long ) V_131 & 0xffff )
V_95 ( L_81 ,
( unsigned long ) V_131 ) ;
#endif
}
