static void F_1 ( void )
{
unsigned long V_1 , V_2 ;
struct V_3 * V_4 ;
if ( F_2 ( & V_5 -> V_6 ) )
return;
V_4 = F_3 ( V_5 -> V_6 . V_7 , struct V_3 , V_8 ) ;
V_5 -> V_9 = V_4 ;
F_4 ( & V_4 -> V_8 ) ;
F_5 ( L_1 , V_4 -> V_4 ,
V_4 -> V_10 ) ;
F_5 ( L_2 , V_4 -> V_11 ) ;
V_5 -> V_12 -> V_4 = V_4 -> V_4 ;
V_5 -> V_12 -> V_13 = V_4 -> V_10 ;
memcpy ( V_5 -> V_12 -> V_14 , V_4 -> V_11 , V_4 -> V_10 ) ;
V_1 = ( unsigned long ) V_5 -> V_12 ;
V_2 = V_1 + V_5 -> V_12 -> V_13 + 2 ;
F_6 ( V_1 , V_2 ) ;
if ( V_5 -> V_15 )
V_16 = 0 ;
F_7 ( V_5 -> V_17 , V_5 -> V_18 ) ;
F_8 ( V_19 , NULL , V_5 -> V_20 , 4 ) ;
}
static T_1 F_9 ( int V_21 , void * V_22 )
{
unsigned long V_23 ;
struct V_3 * V_4 ;
void (* F_10)( struct V_3 * V_4 , void * V_24 ) = NULL ;
void * V_24 = NULL ;
T_2 V_25 ;
int V_26 = 0 ;
F_11 ( & V_5 -> V_27 , V_23 ) ;
V_25 = F_8 ( V_28 , NULL , V_5 -> V_20 ) ;
if ( ( V_25 & 7 ) != 7 ) {
F_12 ( & V_5 -> V_27 , V_23 ) ;
return V_29 ;
}
V_4 = V_5 -> V_9 ;
V_5 -> V_9 = NULL ;
if ( V_4 == NULL )
goto V_30;
if ( V_26 == 0 ) {
unsigned long V_1 ;
int V_31 ;
T_2 V_32 ;
V_1 = ( unsigned long ) V_5 -> V_12 ;
F_6 ( V_1 , V_1 + 256 ) ;
V_32 = ( ~ V_4 -> V_4 ) & 0xff ;
if ( V_32 != V_5 -> V_12 -> V_4 ) {
F_5 ( L_3 ,
V_32 , V_5 -> V_12 -> V_4 ) ;
V_26 = - V_33 ;
}
V_31 = V_26 == 0 ? V_5 -> V_12 -> V_13 : 0 ;
F_5 ( L_4 , V_31 ) ;
if ( V_31 > V_4 -> V_31 ) {
F_13 ( V_34 L_5
L_6 ,
V_31 , V_4 -> V_31 ) ;
V_31 = V_4 -> V_31 ;
}
V_4 -> V_31 = V_31 ;
if ( V_4 -> V_35 && V_31 )
memcpy ( V_4 -> V_35 , V_5 -> V_12 -> V_14 , V_31 ) ;
}
F_10 = V_4 -> F_10 ;
V_24 = V_4 -> V_24 ;
F_14 () ;
V_4 -> V_36 = V_26 ;
if ( V_5 -> V_15 )
V_16 = 1 ;
V_30:
F_1 () ;
F_12 ( & V_5 -> V_27 , V_23 ) ;
if ( F_10 )
F_10 ( V_4 , V_24 ) ;
return V_29 ;
}
static T_1 F_15 ( int V_21 , void * V_22 )
{
F_13 ( V_37 L_7 ) ;
return V_29 ;
}
int F_16 ( struct V_3 * V_4 )
{
unsigned long V_23 ;
if ( V_5 == NULL )
return - V_38 ;
if ( V_4 -> V_10 > V_39 ||
V_4 -> V_31 > V_39 )
return - V_40 ;
V_4 -> V_36 = 1 ;
F_11 ( & V_5 -> V_27 , V_23 ) ;
F_17 ( & V_4 -> V_8 , & V_5 -> V_6 ) ;
if ( V_5 -> V_9 == NULL )
F_1 () ;
F_12 ( & V_5 -> V_27 , V_23 ) ;
if ( ! V_41 || ! V_5 -> V_42 )
F_18 ( V_4 ) ;
return 0 ;
}
int F_19 ( struct V_43 * V_44 , T_2 V_45 ,
unsigned int V_10 ,
void (* F_10)( struct V_3 * V_4 , void * V_24 ) ,
void * V_24 , ... )
{
struct V_3 * V_4 = & V_44 -> V_4 ;
T_3 V_46 ;
int V_47 ;
if ( V_10 > sizeof( V_44 -> V_48 ) )
return - V_40 ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_4 -> V_4 = V_45 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_11 = V_44 -> V_48 ;
V_4 -> V_31 = sizeof( V_44 -> V_48 ) ;
V_4 -> V_35 = V_44 -> V_48 ;
V_4 -> F_10 = F_10 ;
V_4 -> V_24 = V_24 ;
va_start ( V_46 , V_24 ) ;
for ( V_47 = 0 ; V_47 < V_10 ; ++ V_47 )
V_44 -> V_48 [ V_47 ] = ( T_2 ) va_arg ( V_46 , int ) ;
va_end ( V_46 ) ;
return F_16 ( V_4 ) ;
}
void F_20 ( void )
{
T_2 V_25 ;
if ( V_5 == NULL )
return;
V_25 = F_8 ( V_28 , NULL , V_5 -> V_20 ) ;
if ( ( V_25 & 7 ) == 7 )
F_9 ( V_5 -> V_42 , V_5 ) ;
}
void F_21 ( struct V_3 * V_4 , void * V_24 )
{
struct V_49 * V_50 = V_24 ;
F_22 ( V_50 ) ;
}
void F_18 ( struct V_3 * V_4 )
{
while( V_4 -> V_36 == 1 )
F_20 () ;
}
static inline int F_23 ( int V_51 )
{
return ( ( ( V_51 & 0xf0 ) >> 4 ) * 10 ) + ( V_51 & 0xf ) ;
}
static inline int F_24 ( int V_51 )
{
return ( ( V_51 / 10 ) << 4 ) + ( V_51 % 10 ) ;
}
static inline void F_25 ( struct V_52 * V_12 ,
struct V_53 * time )
{
V_12 -> V_4 = 0x8e ;
V_12 -> V_13 = 8 ;
V_12 -> V_14 [ 0 ] = 0x80 ;
V_12 -> V_14 [ 1 ] = F_24 ( time -> V_54 ) ;
V_12 -> V_14 [ 2 ] = F_24 ( time -> V_55 ) ;
V_12 -> V_14 [ 3 ] = F_24 ( time -> V_56 ) ;
V_12 -> V_14 [ 4 ] = time -> V_57 ;
V_12 -> V_14 [ 5 ] = F_24 ( time -> V_58 ) ;
V_12 -> V_14 [ 6 ] = F_24 ( time -> V_59 ) + 1 ;
V_12 -> V_14 [ 7 ] = F_24 ( time -> V_60 - 100 ) ;
}
int F_26 ( struct V_53 * time , int V_61 )
{
struct V_43 V_4 ;
int V_26 ;
if ( V_5 == NULL )
return - V_38 ;
memset ( time , 0 , sizeof( struct V_53 ) ) ;
V_26 = F_19 ( & V_4 , V_62 , 1 , NULL , NULL ,
V_63 ) ;
if ( V_26 )
return V_26 ;
F_27 ( & V_4 ) ;
time -> V_54 = F_23 ( V_4 . V_48 [ 0 ] ) ;
time -> V_55 = F_23 ( V_4 . V_48 [ 1 ] ) ;
time -> V_56 = F_23 ( V_4 . V_48 [ 2 ] ) ;
time -> V_57 = F_23 ( V_4 . V_48 [ 3 ] ) ;
time -> V_58 = F_23 ( V_4 . V_48 [ 4 ] ) ;
time -> V_59 = F_23 ( V_4 . V_48 [ 5 ] ) - 1 ;
time -> V_60 = F_23 ( V_4 . V_48 [ 6 ] ) + 100 ;
return 0 ;
}
int F_28 ( struct V_53 * time , int V_61 )
{
struct V_43 V_4 ;
int V_26 ;
if ( V_5 == NULL )
return - V_38 ;
V_26 = F_19 ( & V_4 , V_62 , 8 , NULL , NULL ,
V_64 ,
F_24 ( time -> V_54 ) ,
F_24 ( time -> V_55 ) ,
F_24 ( time -> V_56 ) ,
time -> V_57 ,
F_24 ( time -> V_58 ) ,
F_24 ( time -> V_59 ) + 1 ,
F_24 ( time -> V_60 - 100 ) ) ;
if ( V_26 )
return V_26 ;
F_27 ( & V_4 ) ;
return 0 ;
}
void F_29 ( void )
{
struct V_43 V_4 ;
if ( V_5 == NULL )
return;
if ( F_19 ( & V_4 , V_65 , 9 , NULL , NULL ,
'S' , 'H' , 'U' , 'T' , 'D' , 'O' , 'W' , 'N' , 0 ) )
return;
F_27 ( & V_4 ) ;
for (; ; )
;
}
void F_30 ( void )
{
struct V_43 V_4 ;
if ( V_5 == NULL )
return;
if ( F_19 ( & V_4 , V_65 , 8 , NULL , NULL ,
'R' , 'E' , 'S' , 'T' , 'A' , 'R' , 'T' , 0 ) )
return;
F_27 ( & V_4 ) ;
for (; ; )
;
}
int F_31 ( void )
{
return V_5 != NULL ;
}
int T_4 F_32 ( void )
{
struct V_66 * V_67 ;
const T_5 * V_14 ;
int V_68 = 0 ;
V_67 = F_33 ( NULL , L_8 ) ;
if ( V_67 == NULL )
return - V_38 ;
F_13 ( V_37 L_9 , V_69 , V_70 ) ;
V_71 = F_34 ( 4096 , 4096 , 0x80000000UL ) ;
if ( V_71 == 0 ) {
F_13 ( V_72 L_10 ) ;
V_68 = - V_40 ;
goto V_73;
}
V_5 = F_35 ( sizeof( struct V_74 ) ) ;
F_36 ( & V_5 -> V_27 ) ;
F_37 ( & V_5 -> V_6 ) ;
F_37 ( & V_5 -> V_75 ) ;
V_5 -> V_76 = V_67 ;
V_5 -> V_42 = 0 ;
V_5 -> V_77 = 0 ;
V_5 -> V_17 = ( T_5 ) V_71 ;
V_5 -> V_12 = F_38 ( V_71 ) ;
V_5 -> V_78 = F_39 ( NULL , L_11 ) ;
if ( V_5 -> V_78 == NULL ) {
F_13 ( V_72 L_12 ) ;
V_68 = - V_79 ;
goto V_80;
}
V_14 = F_40 ( V_5 -> V_78 , L_13 , NULL ) ;
if ( V_14 == NULL ) {
F_13 ( V_72 L_14 ) ;
V_68 = - V_79 ;
goto V_81;
}
V_5 -> V_20 = * V_14 ;
if ( V_5 -> V_20 < 0x50 )
V_5 -> V_20 += 0x50 ;
do {
V_5 -> V_82 = F_39 ( NULL , L_15 ) ;
if ( V_5 -> V_82 == NULL )
break;
V_14 = F_40 ( V_5 -> V_82 , L_13 , NULL ) ;
if ( V_14 == NULL ) {
F_41 ( V_5 -> V_82 ) ;
V_5 -> V_82 = NULL ;
break;
}
V_5 -> V_83 = * V_14 ;
if ( V_5 -> V_83 < 0x50 )
V_5 -> V_83 += 0x50 ;
} while( 0 );
V_5 -> V_18 = F_42 ( 0x8000860c , 0x1000 ) ;
if ( V_5 -> V_18 == NULL ) {
F_13 ( V_72 L_16 ) ;
V_68 = - V_79 ;
goto V_84;
}
V_5 -> V_15 = F_43 () < 4 ;
if ( V_5 -> V_15 )
F_13 ( V_37 L_17 ) ;
V_85 = V_86 ;
return 0 ;
V_84:
F_41 ( V_5 -> V_82 ) ;
V_81:
F_41 ( V_5 -> V_78 ) ;
V_80:
F_44 ( F_45 ( V_5 ) , sizeof( struct V_74 ) ) ;
V_5 = NULL ;
V_73:
F_41 ( V_67 ) ;
return V_68 ;
}
static int F_46 ( void )
{
if ( ! V_5 )
return 0 ;
F_47 ( & V_5 -> V_87 ) ;
V_5 -> V_87 . V_88 = V_89 ;
V_5 -> V_87 . V_14 = ( unsigned long ) V_5 ;
if ( V_5 -> V_78 ) {
V_5 -> V_42 = F_48 ( V_5 -> V_78 , 0 ) ;
if ( ! V_5 -> V_42 )
F_13 ( V_72 L_18 ,
V_5 -> V_78 -> V_90 ) ;
}
if ( V_5 -> V_82 ) {
V_5 -> V_77 = F_48 ( V_5 -> V_82 , 0 ) ;
if ( ! V_5 -> V_77 )
F_13 ( V_72 L_18 ,
V_5 -> V_82 -> V_90 ) ;
}
if ( V_5 -> V_42 ) {
if ( F_49 ( V_5 -> V_42 , F_9 ,
V_91 , L_19 , V_5 ) < 0 ) {
F_13 ( V_34 L_20
L_21 ,
V_5 -> V_42 ) ;
V_5 -> V_42 = 0 ;
}
}
if ( V_5 -> V_77 ) {
if ( F_49 ( V_5 -> V_77 , F_15 ,
V_91 , L_22 , V_5 ) < 0 ) {
F_13 ( V_34 L_20
L_21 ,
V_5 -> V_77 ) ;
V_5 -> V_77 = 0 ;
}
}
V_41 = 1 ;
return 0 ;
}
static void F_50 ( struct V_92 * V_93 )
{
struct V_66 * V_67 ;
for ( V_67 = NULL ; ( V_67 = F_51 ( V_5 -> V_76 , V_67 ) ) != NULL ; )
if ( F_52 ( V_67 , L_23 ) )
F_53 ( V_67 , L_23 ,
& V_5 -> V_94 -> V_95 ) ;
}
static int F_54 ( struct V_96 * V_95 )
{
if ( ! V_5 )
return - V_38 ;
V_5 -> V_94 = V_95 ;
F_55 ( & V_97 ) ;
return 0 ;
}
static int T_4 F_56 ( void )
{
F_57 ( & V_98 ) ;
return 0 ;
}
struct V_96 * F_58 ( void )
{
if ( ! V_5 )
return NULL ;
return V_5 -> V_94 ;
}
static void F_59 ( struct V_99 * V_4 , int V_100 )
{
void (* F_10)( struct V_99 * V_4 , void * V_24 ) = V_4 -> F_10 ;
void * V_24 = V_4 -> V_24 ;
unsigned long V_23 ;
if ( ! V_100 && V_4 -> V_101 ) {
if ( V_4 -> V_102 [ 0 ] < 1 )
V_100 = 1 ;
else
memcpy ( V_4 -> V_103 . V_14 , & V_4 -> V_102 [ 1 ] ,
V_4 -> V_103 . V_104 ) ;
}
F_5 ( L_24 , ! V_100 ) ;
F_11 ( & V_5 -> V_27 , V_23 ) ;
V_5 -> V_105 = NULL ;
F_60 () ;
V_4 -> V_36 = V_100 ? - V_33 : 0 ;
if ( ! F_2 ( & V_5 -> V_75 ) ) {
struct V_99 * V_106 ;
V_106 = F_3 ( V_5 -> V_75 . V_7 ,
struct V_99 , V_8 ) ;
V_5 -> V_105 = V_106 ;
F_4 ( & V_4 -> V_8 ) ;
F_17 ( & V_4 -> V_44 . V_8 , & V_5 -> V_6 ) ;
if ( V_5 -> V_9 == NULL )
F_1 () ;
}
F_12 ( & V_5 -> V_27 , V_23 ) ;
if ( F_10 )
F_10 ( V_4 , V_24 ) ;
}
static void V_89 ( unsigned long V_14 )
{
struct V_99 * V_4 = V_5 -> V_105 ;
F_5 ( L_25 ) ;
V_4 -> V_102 [ 0 ] = 0xff ;
V_4 -> V_44 . V_31 = sizeof( V_4 -> V_102 ) ;
F_16 ( & V_4 -> V_44 ) ;
}
static void F_61 ( struct V_3 * V_44 , void * V_24 )
{
struct V_99 * V_4 = V_24 ;
int V_100 = 0 ;
F_5 ( L_26 ,
V_4 -> V_107 , V_44 -> V_36 , V_4 -> V_102 [ 0 ] , V_44 -> V_31 ) ;
if ( V_44 -> V_36 < 0 )
V_100 = 1 ;
else if ( V_4 -> V_101 ) {
if ( V_4 -> V_107 == 0 )
V_100 = V_4 -> V_102 [ 0 ] != 0 ;
else
V_100 = V_4 -> V_102 [ 0 ] >= 0x80 ;
} else {
V_100 = V_4 -> V_102 [ 0 ] != 0 ;
}
if ( V_100 && -- V_4 -> V_108 > 0 ) {
F_5 ( L_27 ) ;
F_62 ( V_4 != V_5 -> V_105 ) ;
if ( ! V_41 ) {
F_63 ( 5 ) ;
V_89 ( 0 ) ;
return;
}
F_64 ( & V_5 -> V_87 , V_109 + F_65 ( 5 ) ) ;
return;
}
if ( V_100 || V_4 -> V_107 != 0 ) {
F_59 ( V_4 , V_100 ) ;
return;
}
F_5 ( L_28 ) ;
V_44 -> V_35 = V_4 -> V_102 ;
V_44 -> V_31 = sizeof( V_4 -> V_102 ) ;
V_44 -> V_11 = V_4 -> V_102 ;
V_44 -> V_10 = 1 ;
V_4 -> V_102 [ 0 ] = 0 ;
V_4 -> V_107 = 1 ;
V_4 -> V_108 = 20 ;
F_16 ( V_44 ) ;
}
int F_66 ( struct V_99 * V_4 )
{
unsigned long V_23 ;
if ( V_5 == NULL )
return - V_38 ;
V_4 -> V_44 . V_4 = V_110 ;
V_4 -> V_44 . F_10 = F_61 ;
V_4 -> V_44 . V_24 = V_4 ;
V_4 -> V_44 . V_35 = V_4 -> V_102 ;
V_4 -> V_44 . V_31 = sizeof( V_4 -> V_102 ) ;
V_4 -> V_44 . V_11 = ( T_2 * ) ( char * ) & V_4 -> V_103 ;
V_4 -> V_44 . V_36 = 1 ;
V_4 -> V_107 = 0 ;
V_4 -> V_102 [ 0 ] = 0xff ;
V_4 -> V_108 = 20 ;
V_4 -> V_36 = 1 ;
V_4 -> V_103 . V_111 = V_4 -> V_103 . V_112 ;
V_4 -> V_101 = V_4 -> V_103 . V_112 & 0x01 ;
switch( V_4 -> V_103 . type ) {
case V_113 :
memset ( & V_4 -> V_103 . V_114 , 0 , 4 ) ;
break;
case V_115 :
V_4 -> V_103 . V_112 &= 0xfe ;
case V_116 :
if ( V_4 -> V_103 . V_114 > 3 )
return - V_40 ;
break;
default:
return - V_40 ;
}
if ( V_4 -> V_101 ) {
if ( V_4 -> V_103 . V_104 > V_117 )
return - V_40 ;
memset ( V_4 -> V_103 . V_14 , 0xff , V_4 -> V_103 . V_104 ) ;
V_4 -> V_44 . V_10 = 9 ;
} else {
if ( V_4 -> V_103 . V_104 > V_118 )
return - V_40 ;
V_4 -> V_44 . V_10 = 9 + V_4 -> V_103 . V_104 ;
}
F_5 ( L_29 ) ;
F_5 ( L_30 ,
V_4 -> V_101 ? L_31 : L_32 , V_4 -> V_103 . V_104 ,
V_4 -> V_103 . V_119 , V_4 -> V_103 . V_111 ,
V_4 -> V_103 . V_120 [ 0 ] , V_4 -> V_103 . type ) ;
F_11 ( & V_5 -> V_27 , V_23 ) ;
if ( V_5 -> V_105 == NULL ) {
V_5 -> V_105 = V_4 ;
F_17 ( & V_4 -> V_44 . V_8 , & V_5 -> V_6 ) ;
if ( V_5 -> V_9 == NULL )
F_1 () ;
} else
F_17 ( & V_4 -> V_8 , & V_5 -> V_75 ) ;
F_12 ( & V_5 -> V_27 , V_23 ) ;
return 0 ;
}
static int F_67 ( T_2 * V_121 , unsigned int V_122 , unsigned int V_123 )
{
F_68 ( V_50 ) ;
unsigned int V_124 ;
struct V_3 V_4 ;
int V_26 ;
T_2 V_125 [ 8 ] ;
V_124 = 0xe ;
while ( V_123 ) {
unsigned int V_126 = F_69 ( V_123 , V_124 ) ;
V_4 . V_4 = V_127 ;
V_4 . V_10 = 7 ;
V_4 . V_11 = V_125 ;
V_4 . V_31 = V_124 ;
V_4 . V_35 = V_121 ;
V_4 . F_10 = F_21 ;
V_4 . V_24 = & V_50 ;
V_125 [ 0 ] = V_128 ;
V_125 [ 1 ] = 0x4 ;
* ( ( T_5 * ) & V_125 [ 2 ] ) = V_122 ;
V_125 [ 6 ] = V_126 ;
V_26 = F_16 ( & V_4 ) ;
if ( V_26 )
return V_26 ;
F_70 ( & V_50 ) ;
if ( V_4 . V_36 != 0 )
return V_26 ;
if ( V_4 . V_31 != V_126 ) {
F_13 ( V_129 L_33
L_34 ,
V_4 . V_31 , V_126 ) ;
return - V_33 ;
}
V_123 -= V_126 ;
V_122 += V_126 ;
V_121 += V_126 ;
}
return 0 ;
}
static struct V_130 * F_71 ( int V_131 )
{
F_68 ( V_50 ) ;
struct V_43 V_4 ;
unsigned int V_122 , V_123 , V_132 ;
struct V_130 * V_133 ;
struct V_134 * V_135 ;
F_5 ( L_35 , V_5 -> V_42 ) ;
F_19 ( & V_4 , V_136 , 2 ,
F_21 , & V_50 ,
V_137 , V_131 ) ;
F_70 ( & V_50 ) ;
F_5 ( L_36 ,
V_4 . V_4 . V_36 , V_4 . V_4 . V_31 ) ;
if ( V_4 . V_4 . V_36 != 0 || V_4 . V_4 . V_31 != 6 )
return NULL ;
V_122 = * ( ( V_138 * ) V_4 . V_48 ) ;
V_123 = V_4 . V_48 [ 3 ] << 2 ;
V_132 = sizeof( struct V_134 ) + V_123 + 18 ;
V_135 = F_72 ( V_132 , V_139 ) ;
if ( V_135 == NULL )
return NULL ;
V_133 = (struct V_130 * ) ( V_135 + 1 ) ;
V_135 -> V_140 = ( ( char * ) V_135 ) + V_132 - 18 ;
sprintf ( V_135 -> V_140 , L_37 , V_131 ) ;
V_135 -> V_13 = V_123 ;
V_135 -> V_141 = V_133 ;
V_135 -> V_7 = NULL ;
if ( F_67 ( ( T_2 * ) V_133 , V_122 , V_123 ) ) {
F_13 ( V_129 L_38
L_39 , V_131 ) ;
goto V_142;
}
if ( V_133 -> V_131 != V_131 ) {
F_13 ( V_129 L_40
L_41 , V_131 , V_133 -> V_131 ) ;
goto V_142;
}
if ( F_73 ( V_5 -> V_76 , V_135 ) ) {
F_13 ( V_129 L_42
L_43 , V_131 ) ;
goto V_142;
}
return V_133 ;
V_142:
F_74 ( V_135 ) ;
return NULL ;
}
const struct V_130 * F_75 ( int V_131 ,
unsigned int * V_143 , int V_144 )
{
char V_145 [ 32 ] ;
const struct V_130 * V_146 ;
if ( ! V_5 )
return NULL ;
sprintf ( V_145 , L_37 , V_131 ) ;
F_5 ( L_44 , V_131 ) ;
if ( V_144 ) {
int V_26 ;
V_26 = F_76 ( & V_147 ) ;
if ( V_26 )
return F_77 ( V_26 ) ;
} else
F_78 ( & V_147 ) ;
V_146 = F_40 ( V_5 -> V_76 , V_145 , V_143 ) ;
if ( V_146 == NULL ) {
F_5 ( L_45 ) ;
V_146 = F_71 ( V_131 ) ;
if ( V_146 != NULL && V_143 )
* V_143 = V_146 -> V_123 << 2 ;
}
F_79 ( & V_147 ) ;
return V_146 ;
}
const struct V_130 * F_80 ( int V_131 , unsigned int * V_143 )
{
return F_75 ( V_131 , V_143 , 0 ) ;
}
static int F_81 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_150 * V_151 ;
unsigned long V_23 ;
V_151 = F_72 ( sizeof( struct V_150 ) , V_139 ) ;
if ( V_151 == 0 )
return - V_152 ;
F_36 ( & V_151 -> V_27 ) ;
V_151 -> V_153 = V_154 ;
F_82 ( & V_151 -> V_155 ) ;
F_78 ( & V_156 ) ;
F_11 ( & V_157 , V_23 ) ;
F_83 ( & V_151 -> V_46 , & V_158 ) ;
F_12 ( & V_157 , V_23 ) ;
V_149 -> V_159 = V_151 ;
F_79 ( & V_156 ) ;
return 0 ;
}
static void F_84 ( struct V_3 * V_4 , void * V_24 )
{
struct V_150 * V_151 = V_24 ;
F_85 ( & V_151 -> V_155 ) ;
}
static T_6 F_86 ( struct V_149 * V_149 , const char T_7 * V_160 ,
T_8 V_161 , T_9 * V_162 )
{
struct V_150 * V_151 = V_149 -> V_159 ;
unsigned long V_23 ;
struct V_163 V_133 ;
int V_26 = 0 ;
if ( V_151 -> V_164 )
return - V_165 ;
else if ( F_87 ( & V_133 , V_160 , sizeof( V_133 ) ) )
return - V_166 ;
else if ( V_133 . V_167 == V_168 ) {
V_151 -> V_153 = V_169 ;
return 0 ;
} else if ( V_133 . V_167 == V_170 ) {
const struct V_130 * V_146 ;
V_146 = F_75 ( V_133 . V_4 , NULL , 1 ) ;
if ( V_146 == NULL )
return - V_40 ;
else if ( F_88 ( V_146 ) )
return F_89 ( V_146 ) ;
return 0 ;
} else if ( V_133 . V_167 != V_171 )
return - V_40 ;
else if ( V_151 -> V_153 != V_154 )
return - V_172 ;
else if ( V_133 . V_10 > V_39 )
return - V_40 ;
F_11 ( & V_151 -> V_27 , V_23 ) ;
if ( V_151 -> V_164 ) {
F_12 ( & V_151 -> V_27 , V_23 ) ;
return - V_165 ;
}
V_151 -> V_164 = 1 ;
V_151 -> V_4 . V_36 = 1 ;
F_12 ( & V_151 -> V_27 , V_23 ) ;
if ( F_87 ( V_151 -> V_48 , V_160 + sizeof( V_133 ) , V_133 . V_10 ) ) {
V_151 -> V_164 = 0 ;
return - V_166 ;
}
V_151 -> V_4 . V_4 = V_133 . V_4 ;
V_151 -> V_4 . V_10 = V_133 . V_10 ;
V_151 -> V_4 . V_31 = V_39 ;
V_151 -> V_4 . V_11 = V_151 -> V_48 ;
V_151 -> V_4 . V_35 = V_151 -> V_48 ;
V_151 -> V_4 . F_10 = F_84 ;
V_151 -> V_4 . V_24 = V_151 ;
V_26 = F_16 ( & V_151 -> V_4 ) ;
if ( V_26 < 0 )
return V_26 ;
return V_161 ;
}
static T_6 F_90 ( struct V_149 * V_149 , struct V_150 * V_151 ,
char T_7 * V_160 , T_8 V_161 )
{
F_91 ( V_155 , V_173 ) ;
struct V_174 V_133 ;
unsigned long V_23 ;
int V_143 , V_26 = 0 ;
if ( ! V_151 -> V_164 )
return 0 ;
if ( V_161 < sizeof( struct V_174 ) )
return - V_175 ;
F_11 ( & V_151 -> V_27 , V_23 ) ;
if ( V_151 -> V_4 . V_36 == 1 ) {
if ( V_149 -> V_176 & V_177 ) {
F_12 ( & V_151 -> V_27 , V_23 ) ;
return - V_178 ;
}
F_92 ( & V_151 -> V_155 , & V_155 ) ;
for (; ; ) {
F_93 ( V_179 ) ;
V_26 = 0 ;
if ( V_151 -> V_4 . V_36 != 1 )
break;
V_26 = - V_180 ;
if ( F_94 ( V_173 ) )
break;
F_12 ( & V_151 -> V_27 , V_23 ) ;
F_95 () ;
F_11 ( & V_151 -> V_27 , V_23 ) ;
}
F_93 ( V_181 ) ;
F_96 ( & V_151 -> V_155 , & V_155 ) ;
}
F_12 ( & V_151 -> V_27 , V_23 ) ;
if ( V_26 )
return V_26 ;
if ( V_151 -> V_4 . V_36 != 0 )
V_151 -> V_4 . V_31 = 0 ;
V_143 = sizeof( V_133 ) + V_151 -> V_4 . V_31 ;
if ( V_161 < V_143 )
V_143 = V_161 ;
V_26 = V_143 ;
V_133 . V_36 = V_151 -> V_4 . V_36 ;
V_133 . V_31 = V_151 -> V_4 . V_31 ;
if ( F_97 ( V_160 , & V_133 , sizeof( V_133 ) ) )
return - V_166 ;
V_143 -= sizeof( V_133 ) ;
if ( V_143 && F_97 ( V_160 + sizeof( V_133 ) , V_151 -> V_48 , V_143 ) )
return - V_166 ;
V_151 -> V_164 = 0 ;
return V_26 ;
}
static T_6 F_98 ( struct V_149 * V_149 , struct V_150 * V_151 ,
char T_7 * V_160 , T_8 V_161 )
{
F_99 ( 1000 ) ;
return 0 ;
}
static T_6 F_100 ( struct V_149 * V_149 , char T_7 * V_160 ,
T_8 V_161 , T_9 * V_162 )
{
struct V_150 * V_151 = V_149 -> V_159 ;
if ( V_151 -> V_153 == V_154 )
return F_90 ( V_149 , V_151 , V_160 , V_161 ) ;
if ( V_151 -> V_153 == V_169 )
return F_98 ( V_149 , V_151 , V_160 , V_161 ) ;
return - V_172 ;
}
static unsigned int F_101 ( struct V_149 * V_149 , T_10 * V_155 )
{
struct V_150 * V_151 = V_149 -> V_159 ;
unsigned int V_182 = 0 ;
unsigned long V_23 ;
if ( V_151 == 0 )
return 0 ;
if ( V_151 -> V_153 == V_154 ) {
F_102 ( V_149 , & V_151 -> V_155 , V_155 ) ;
F_11 ( & V_151 -> V_27 , V_23 ) ;
if ( V_151 -> V_164 && V_151 -> V_4 . V_36 != 1 )
V_182 |= V_183 ;
F_12 ( & V_151 -> V_27 , V_23 ) ;
}
if ( V_151 -> V_153 == V_169 ) {
}
return V_182 ;
}
static int F_103 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_150 * V_151 = V_149 -> V_159 ;
unsigned long V_23 ;
unsigned int V_164 ;
if ( V_151 == 0 )
return 0 ;
V_149 -> V_159 = NULL ;
F_11 ( & V_151 -> V_27 , V_23 ) ;
V_151 -> V_153 = V_184 ;
V_164 = V_151 -> V_164 ;
if ( V_164 && V_151 -> V_4 . V_36 == 1 ) {
F_91 ( V_155 , V_173 ) ;
F_92 ( & V_151 -> V_155 , & V_155 ) ;
for (; ; ) {
F_93 ( V_185 ) ;
if ( V_151 -> V_4 . V_36 != 1 )
break;
F_12 ( & V_151 -> V_27 , V_23 ) ;
F_95 () ;
F_11 ( & V_151 -> V_27 , V_23 ) ;
}
F_93 ( V_181 ) ;
F_96 ( & V_151 -> V_155 , & V_155 ) ;
}
F_12 ( & V_151 -> V_27 , V_23 ) ;
F_11 ( & V_157 , V_23 ) ;
F_4 ( & V_151 -> V_46 ) ;
F_12 ( & V_157 , V_23 ) ;
F_74 ( V_151 ) ;
return 0 ;
}
static int F_104 ( void )
{
if ( ! V_5 )
return - V_38 ;
if ( F_105 ( & V_186 ) < 0 )
F_13 ( V_72 L_46 ) ;
return 0 ;
}
