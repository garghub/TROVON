void F_1 ( void )
{
#ifdef F_2
F_3 () ;
#endif
if ( V_1 . F_1 )
V_1 . F_1 () ;
}
static void F_4 ( void )
{
F_5 ( L_1 ) ;
F_6 () ;
while ( 1 )
;
}
void F_7 ( char * V_2 )
{
F_1 () ;
if ( V_1 . V_3 )
V_1 . V_3 ( V_2 ) ;
F_8 () ;
F_9 ( V_2 ) ;
F_10 ( 1000 ) ;
F_4 () ;
}
void F_11 ( void )
{
F_1 () ;
if ( V_4 )
V_4 () ;
F_8 () ;
F_4 () ;
}
void F_12 ( void )
{
F_1 () ;
if ( V_1 . V_5 )
V_1 . V_5 () ;
F_8 () ;
F_4 () ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
const char * V_10 = NULL ;
#if F_14 ( V_11 ) && F_14 ( V_12 )
unsigned long V_13 = 0 ;
int V_14 ;
F_15 (i)
V_13 += V_15 ;
F_16 ( V_7 , L_2 ,
V_13 / ( 500000 / V_16 ) , V_13 / ( 5000 / V_16 ) % 100 ) ;
#endif
F_16 ( V_7 , L_3 , V_17 ) ;
if ( V_1 . V_18 )
F_16 ( V_7 , L_4 , V_1 . V_18 ) ;
V_9 = F_17 ( L_5 ) ;
if ( V_9 )
V_10 = F_18 ( V_9 , L_6 , NULL ) ;
if ( V_10 )
F_16 ( V_7 , L_7 , V_10 ) ;
F_19 ( V_9 ) ;
if ( V_1 . V_19 != NULL )
V_1 . V_19 ( V_7 ) ;
#ifdef V_12
F_16 ( V_7 , L_8 ,
( unsigned int ) ( V_20 / ( 1024 * 1024 ) ) ) ;
#endif
}
static int V_19 ( struct V_6 * V_7 , void * V_21 )
{
unsigned long V_22 = ( unsigned long ) V_21 - 1 ;
unsigned int V_23 ;
unsigned long V_24 ;
unsigned short V_25 ;
unsigned short V_26 ;
F_20 () ;
if ( ! F_21 ( V_22 ) ) {
F_22 () ;
return 0 ;
}
#ifdef V_11
V_23 = F_23 ( V_27 , V_22 ) ;
#else
V_23 = F_24 ( V_28 ) ;
#endif
V_25 = ( V_23 >> 8 ) & 0xFF ;
V_26 = V_23 & 0xFF ;
F_16 ( V_7 , L_9 , V_22 ) ;
F_16 ( V_7 , L_10 ) ;
if ( V_29 -> V_30 )
F_16 ( V_7 , L_11 , V_29 -> V_31 ) ;
else
F_16 ( V_7 , L_12 , V_23 ) ;
#ifdef F_25
if ( F_26 ( V_32 ) )
F_16 ( V_7 , L_13 ) ;
#endif
F_16 ( V_7 , L_14 ) ;
#ifdef F_27
if ( V_29 -> V_33 & V_34 ) {
#ifdef F_28
F_16 ( V_7 , L_15 ,
F_29 ( V_22 ) ) ;
#else
T_1 V_35 ;
V_35 = F_30 ( V_22 ) ;
F_16 ( V_7 , L_16 ,
V_35 & 0xff , V_35 >> 16 ) ;
#endif
}
#endif
if ( V_1 . V_36 )
V_24 = V_1 . V_36 ( V_22 ) ;
else
V_24 = V_37 ;
if ( V_24 )
F_16 ( V_7 , L_17 ,
V_24 / 1000000 , V_24 % 1000000 ) ;
if ( V_1 . V_38 != NULL )
V_1 . V_38 ( V_7 , V_22 ) ;
if ( F_31 ( V_23 ) & 0x8000 ) {
switch ( F_31 ( V_23 ) ) {
case 0x8000 :
case 0x8001 :
case 0x8002 :
case 0x8003 :
case 0x8004 :
case 0x800c :
V_25 = ( ( V_23 >> 8 ) & 0xF ) ;
V_26 = F_32 ( V_23 ) ;
break;
default:
V_25 = F_33 ( V_23 ) ;
V_26 = F_32 ( V_23 ) ;
break;
}
} else {
switch ( F_31 ( V_23 ) ) {
case 0x0020 :
V_25 = F_33 ( V_23 ) + 1 ;
V_26 = F_32 ( V_23 ) ;
break;
case 0x1008 :
V_25 = ( ( V_23 >> 8 ) & 0xFF ) - 1 ;
V_26 = V_23 & 0xFF ;
break;
default:
V_25 = ( V_23 >> 8 ) & 0xFF ;
V_26 = V_23 & 0xFF ;
break;
}
}
F_16 ( V_7 , L_18 ,
V_25 , V_26 , F_31 ( V_23 ) , F_34 ( V_23 ) ) ;
#ifdef V_12
F_16 ( V_7 , L_19 ,
V_15 / ( 500000 / V_16 ) ,
( V_15 / ( 5000 / V_16 ) ) % 100 ) ;
#endif
#ifdef V_11
F_16 ( V_7 , L_14 ) ;
#endif
F_22 () ;
if ( F_35 ( V_22 , V_39 ) >= V_40 )
F_13 ( V_7 ) ;
return 0 ;
}
static void * F_36 ( struct V_6 * V_7 , T_2 * V_41 )
{
if ( * V_41 == 0 )
* V_41 = F_37 ( V_39 ) ;
else
* V_41 = F_35 ( * V_41 - 1 , V_39 ) ;
if ( ( * V_41 ) < V_40 )
return ( void * ) ( unsigned long ) ( * V_41 + 1 ) ;
return NULL ;
}
static void * F_38 ( struct V_6 * V_7 , void * V_21 , T_2 * V_41 )
{
( * V_41 ) ++ ;
return F_36 ( V_7 , V_41 ) ;
}
static void F_39 ( struct V_6 * V_7 , void * V_21 )
{
}
void T_3 F_40 ( void )
{
#ifdef F_41
F_42 ( L_20 ,
V_42 , V_43 ) ;
if ( F_43 ( V_42 ) && F_43 ( V_43 ) &&
V_43 > V_42 )
V_44 = V_45 ;
else
V_42 = V_43 = 0 ;
if ( V_42 )
F_44 ( L_21 , V_42 , V_43 ) ;
F_42 ( L_22 ) ;
#endif
}
static void T_3 F_45 ( int V_46 )
{
int V_14 ;
V_47 = V_46 ;
V_48 = V_46 ;
F_46 ( & V_49 ) ;
V_50 = F_47 ( V_46 ) ;
F_48 ( V_46 != ( 1 << V_50 ) ) ;
for ( V_14 = 0 ; V_14 < V_46 ; V_14 ++ )
F_49 ( V_14 , & V_49 ) ;
F_50 ( V_51 L_23 ,
V_46 , V_46 > 1 ? L_24 : L_25 ) ;
F_50 ( V_52 L_26 , V_50 ) ;
}
void T_3 F_51 ( void )
{
struct V_8 * V_53 = NULL ;
int V_54 = 0 ;
int V_55 = 1 ;
F_42 ( L_27 ) ;
while ( ( V_53 = F_52 ( V_53 , L_28 ) ) && V_54 < V_40 ) {
const T_4 * V_56 ;
T_4 V_57 ;
int V_58 , V_59 ;
F_42 ( L_29 , V_53 -> V_60 ) ;
V_56 = F_18 ( V_53 , L_30 ,
& V_59 ) ;
if ( V_56 ) {
F_42 ( L_31 ,
V_55 ) ;
} else {
F_42 ( L_32 ) ;
V_56 = F_18 ( V_53 , L_33 , & V_59 ) ;
if ( ! V_56 ) {
V_57 = F_53 ( V_54 ) ;
V_56 = & V_57 ;
V_59 = 4 ;
}
}
V_55 = V_59 / sizeof( int ) ;
for ( V_58 = 0 ; V_58 < V_55 && V_54 < V_40 ; V_58 ++ ) {
bool V_61 ;
F_42 ( L_34 ,
V_58 , V_54 , F_54 ( V_56 [ V_58 ] ) ) ;
V_61 = F_55 ( V_53 ) ;
if ( ! V_61 )
V_61 = ! F_56 ( V_53 ,
L_35 , L_36 ) ;
F_57 ( V_54 , V_61 ) ;
F_58 ( V_54 , F_54 ( V_56 [ V_58 ] ) ) ;
F_59 ( V_54 , true ) ;
V_54 ++ ;
}
}
if ( ! F_26 ( V_62 ) ) {
F_42 ( L_37 ) ;
V_55 = 1 ;
}
#ifdef F_60
if ( F_61 ( V_63 ) &&
( V_53 = F_17 ( L_38 ) ) ) {
int V_64 , V_65 , V_66 ;
const T_4 * V_67 ;
V_64 = F_62 ( V_53 ) ;
V_65 = F_63 ( V_53 ) ;
V_67 = F_18 ( V_53 , L_39 , NULL ) ;
if ( ! V_67 )
goto V_68;
V_66 = F_64 ( V_67 + V_64 + V_65 ) ;
if ( F_26 ( V_62 ) )
V_66 *= V_55 ;
if ( V_66 > V_40 ) {
F_50 ( V_69
L_40
L_41 ,
V_66 , V_40 ) ;
V_66 = V_40 ;
} else
F_50 ( V_51 L_42 ,
V_66 ) ;
for ( V_54 = 0 ; V_54 < V_66 ; V_54 ++ )
F_59 ( V_54 , true ) ;
V_68:
F_19 ( V_53 ) ;
}
V_70 -> V_71 = F_65 () ;
#endif
F_45 ( V_55 ) ;
F_66 () ;
F_67 () ;
}
static T_3 int F_68 ( void )
{
struct V_8 * V_72 ;
struct V_73 * V_74 ;
int V_75 ;
V_72 = F_69 ( NULL , NULL , L_43 ) ;
F_19 ( V_72 ) ;
if ( ! V_72 )
return - V_76 ;
V_74 = F_70 ( L_44 , - 1 ) ;
if ( ! V_74 )
return - V_77 ;
V_75 = F_71 ( V_74 ) ;
if ( V_75 )
F_72 ( V_74 ) ;
return V_75 ;
}
void F_73 ( void )
{
extern struct V_78 V_79 ;
extern struct V_78 V_80 ;
unsigned int V_14 ;
F_42 ( L_45 ) ;
for ( V_14 = 0 ; V_14 < ( sizeof( V_1 ) / sizeof( void * ) ) ; V_14 ++ ) {
if ( ( ( void * * ) & V_1 ) [ V_14 ] ) {
F_50 ( V_81 L_46
L_47 , V_14 ) ;
}
}
for ( V_82 = & V_79 ;
V_82 < & V_80 ;
V_82 ++ ) {
F_42 ( L_48 , V_82 -> V_18 ) ;
memcpy ( & V_1 , V_82 , sizeof( struct V_78 ) ) ;
if ( V_1 . V_83 () ) {
F_42 ( L_49 ) ;
break;
}
F_42 ( L_14 ) ;
}
if ( V_82 >= & V_80 ) {
F_42 ( L_50 ) ;
for (; ; ) ;
}
F_50 ( V_51 L_51 , V_1 . V_18 ) ;
}
int F_74 ( unsigned long V_84 )
{
struct V_8 * V_85 , * V_72 = NULL ;
int V_75 = - V_76 ;
switch( V_84 ) {
case V_86 :
if ( ! ( V_72 = F_69 ( NULL , NULL , L_52 ) ) )
V_72 = F_69 ( NULL , NULL , L_53 ) ;
if ( V_72 ) {
V_85 = F_75 ( V_72 ) ;
V_87 = F_76 ( V_85 , 0 ) ;
if ( ! V_87 )
V_87 = 1 ;
V_88 = F_76 ( V_85 , 1 ) ;
if ( ! V_88 )
V_88 = 12 ;
F_19 ( V_72 ) ;
V_72 = V_85 ;
break;
}
V_72 = F_52 ( NULL , L_54 ) ;
if ( ! V_72 )
V_72 = F_77 ( NULL , L_54 ) ;
if ( V_72 ) {
V_87 = 1 ;
V_88 = 12 ;
}
break;
case V_89 :
V_72 = F_52 ( NULL , L_55 ) ;
break;
default:
break;
}
if ( ! V_72 )
return V_75 ;
V_85 = F_75 ( V_72 ) ;
if ( V_85 ) {
if ( strcmp ( V_85 -> type , L_56 ) == 0 )
V_75 = 0 ;
F_19 ( V_85 ) ;
}
F_19 ( V_72 ) ;
return V_75 ;
}
static int F_78 ( struct V_90 * V_91 ,
unsigned long V_92 , void * V_93 )
{
F_79 ( NULL , V_93 ) ;
V_1 . V_94 ( V_93 ) ;
return V_95 ;
}
void T_3 F_80 ( void )
{
if ( ! V_1 . V_94 )
return;
F_81 ( & V_96 , & V_97 ) ;
}
static int T_3 F_82 ( void )
{
struct V_8 * V_72 ;
const void * V_98 ;
int V_99 ;
V_72 = F_17 ( L_5 ) ;
V_98 = F_18 ( V_72 , L_57 , NULL ) ;
F_19 ( V_72 ) ;
V_99 = V_98 ? 0 : 1 ;
if ( V_99 != V_100 ) {
F_50 ( V_81
L_58 ,
V_100 ? L_59 : L_60 ,
V_99 ? L_59 : L_60 ) ;
F_83 () ;
}
return 0 ;
}
static int F_84 ( void )
{
V_101 = F_85 ( L_61 , NULL ) ;
return V_101 == NULL ;
}
void F_86 ( char * V_102 , unsigned short V_103 )
{
F_44 ( L_62 , V_102 ) ;
}
void F_87 ( struct V_73 * V_104 )
{
V_104 -> V_105 . V_106 = F_88 ( 32 ) ;
V_104 -> V_107 . V_106 = & V_104 -> V_105 . V_106 ;
F_89 ( & V_104 -> V_107 , & V_108 ) ;
}
static T_3 void F_90 ( void )
{
F_44 ( L_63 ) ;
#ifdef F_91
F_44 ( L_64 , V_109 ) ;
#endif
#ifdef F_92
F_44 ( L_65 , V_110 ) ;
#endif
F_44 ( L_66 ,
( unsigned long long ) F_93 () ) ;
F_44 ( L_67 , V_111 ) ;
F_44 ( L_68 , V_112 ) ;
if ( V_113 != 0 )
F_44 ( L_69 , V_113 ) ;
F_44 ( L_70 , V_29 -> V_33 ) ;
F_44 ( L_71 ,
( unsigned long ) V_114 ) ;
F_44 ( L_72 ,
( unsigned long ) V_115 ) ;
F_44 ( L_73 ,
V_29 -> V_116 ,
V_29 -> V_117 ) ;
F_44 ( L_74 , V_29 -> V_118 ) ;
#ifdef F_60
F_44 ( L_75 , V_119 ) ;
#endif
#ifdef F_91
if ( V_120 )
F_44 ( L_76 , V_120 ) ;
if ( V_121 )
F_44 ( L_77 , V_121 ) ;
#endif
#ifdef F_92
if ( V_122 )
F_44 ( L_78 , V_122 ) ;
if ( V_123 )
F_44 ( L_79 , V_123 ) ;
#endif
if ( V_124 > 0 )
F_44 ( L_80 ,
( unsigned long long ) V_124 ) ;
F_44 ( L_63 ) ;
}
void T_3 F_94 ( char * * V_125 )
{
* V_125 = V_126 ;
V_15 = 500000000 / V_16 ;
F_95 () ;
F_96 () ;
F_97 () ;
F_40 () ;
F_73 () ;
F_80 () ;
F_98 () ;
F_99 () ;
F_100 () ;
F_51 () ;
F_101 () ;
F_102 () ;
F_103 () ;
#ifdef V_11
F_104 () ;
#endif
F_90 () ;
F_105 () ;
F_106 () ;
F_107 ( & V_127 ) ;
V_128 . V_129 = ( unsigned long ) V_130 ;
V_128 . V_131 = ( unsigned long ) V_132 ;
V_128 . V_133 = ( unsigned long ) V_134 ;
V_128 . V_135 = V_136 ;
#ifdef F_108
V_128 . V_137 . V_138 = NULL ;
#endif
#ifdef F_109
F_110 ( & V_128 ) ;
#endif
F_111 () ;
F_112 () ;
F_113 () ;
F_114 () ;
#ifdef F_115
V_139 = & V_140 ;
#endif
if ( V_1 . F_94 )
V_1 . F_94 () ;
F_116 () ;
F_117 () ;
#ifdef F_60
if ( ( unsigned long ) V_130 & 0xffff )
V_94 ( L_81 ,
( unsigned long ) V_130 ) ;
#endif
}
