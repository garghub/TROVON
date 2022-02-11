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
if ( ! V_41 || V_5 -> V_42 == V_43 )
F_18 ( V_4 ) ;
return 0 ;
}
int F_19 ( struct V_44 * V_45 , T_2 V_46 ,
unsigned int V_10 ,
void (* F_10)( struct V_3 * V_4 , void * V_24 ) ,
void * V_24 , ... )
{
struct V_3 * V_4 = & V_45 -> V_4 ;
T_3 V_47 ;
int V_48 ;
if ( V_10 > sizeof( V_45 -> V_49 ) )
return - V_40 ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_4 -> V_4 = V_46 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_11 = V_45 -> V_49 ;
V_4 -> V_31 = sizeof( V_45 -> V_49 ) ;
V_4 -> V_35 = V_45 -> V_49 ;
V_4 -> F_10 = F_10 ;
V_4 -> V_24 = V_24 ;
va_start ( V_47 , V_24 ) ;
for ( V_48 = 0 ; V_48 < V_10 ; ++ V_48 )
V_45 -> V_49 [ V_48 ] = ( T_2 ) va_arg ( V_47 , int ) ;
va_end ( V_47 ) ;
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
struct V_50 * V_51 = V_24 ;
F_22 ( V_51 ) ;
}
void F_18 ( struct V_3 * V_4 )
{
while( V_4 -> V_36 == 1 )
F_20 () ;
}
static inline int F_23 ( int V_52 )
{
return ( ( ( V_52 & 0xf0 ) >> 4 ) * 10 ) + ( V_52 & 0xf ) ;
}
static inline int F_24 ( int V_52 )
{
return ( ( V_52 / 10 ) << 4 ) + ( V_52 % 10 ) ;
}
static inline void F_25 ( struct V_53 * V_12 ,
struct V_54 * time )
{
V_12 -> V_4 = 0x8e ;
V_12 -> V_13 = 8 ;
V_12 -> V_14 [ 0 ] = 0x80 ;
V_12 -> V_14 [ 1 ] = F_24 ( time -> V_55 ) ;
V_12 -> V_14 [ 2 ] = F_24 ( time -> V_56 ) ;
V_12 -> V_14 [ 3 ] = F_24 ( time -> V_57 ) ;
V_12 -> V_14 [ 4 ] = time -> V_58 ;
V_12 -> V_14 [ 5 ] = F_24 ( time -> V_59 ) ;
V_12 -> V_14 [ 6 ] = F_24 ( time -> V_60 ) + 1 ;
V_12 -> V_14 [ 7 ] = F_24 ( time -> V_61 - 100 ) ;
}
int F_26 ( struct V_54 * time , int V_62 )
{
struct V_44 V_4 ;
int V_26 ;
if ( V_5 == NULL )
return - V_38 ;
memset ( time , 0 , sizeof( struct V_54 ) ) ;
V_26 = F_19 ( & V_4 , V_63 , 1 , NULL , NULL ,
V_64 ) ;
if ( V_26 )
return V_26 ;
F_27 ( & V_4 ) ;
time -> V_55 = F_23 ( V_4 . V_49 [ 0 ] ) ;
time -> V_56 = F_23 ( V_4 . V_49 [ 1 ] ) ;
time -> V_57 = F_23 ( V_4 . V_49 [ 2 ] ) ;
time -> V_58 = F_23 ( V_4 . V_49 [ 3 ] ) ;
time -> V_59 = F_23 ( V_4 . V_49 [ 4 ] ) ;
time -> V_60 = F_23 ( V_4 . V_49 [ 5 ] ) - 1 ;
time -> V_61 = F_23 ( V_4 . V_49 [ 6 ] ) + 100 ;
return 0 ;
}
int F_28 ( struct V_54 * time , int V_62 )
{
struct V_44 V_4 ;
int V_26 ;
if ( V_5 == NULL )
return - V_38 ;
V_26 = F_19 ( & V_4 , V_63 , 8 , NULL , NULL ,
V_65 ,
F_24 ( time -> V_55 ) ,
F_24 ( time -> V_56 ) ,
F_24 ( time -> V_57 ) ,
time -> V_58 ,
F_24 ( time -> V_59 ) ,
F_24 ( time -> V_60 ) + 1 ,
F_24 ( time -> V_61 - 100 ) ) ;
if ( V_26 )
return V_26 ;
F_27 ( & V_4 ) ;
return 0 ;
}
void F_29 ( void )
{
struct V_44 V_4 ;
if ( V_5 == NULL )
return;
if ( F_19 ( & V_4 , V_66 , 9 , NULL , NULL ,
'S' , 'H' , 'U' , 'T' , 'D' , 'O' , 'W' , 'N' , 0 ) )
return;
F_27 ( & V_4 ) ;
for (; ; )
;
}
void F_30 ( void )
{
struct V_44 V_4 ;
if ( V_5 == NULL )
return;
if ( F_19 ( & V_4 , V_66 , 8 , NULL , NULL ,
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
struct V_67 * V_68 ;
const T_5 * V_14 ;
int V_69 = 0 ;
V_68 = F_33 ( NULL , L_8 ) ;
if ( V_68 == NULL )
return - V_38 ;
F_13 ( V_37 L_9 , V_70 , V_71 ) ;
if ( V_72 == 0 ) {
F_13 ( V_73 L_10 ) ;
V_69 = - V_40 ;
goto V_74;
}
V_5 = F_34 ( sizeof( struct V_75 ) ) ;
F_35 ( & V_5 -> V_27 ) ;
F_36 ( & V_5 -> V_6 ) ;
F_36 ( & V_5 -> V_76 ) ;
V_5 -> V_77 = V_68 ;
V_5 -> V_42 = V_43 ;
V_5 -> V_78 = V_43 ;
V_5 -> V_17 = ( T_5 ) V_72 ;
V_5 -> V_12 = F_37 ( V_72 ) ;
V_5 -> V_79 = F_38 ( NULL , L_11 ) ;
if ( V_5 -> V_79 == NULL ) {
F_13 ( V_73 L_12 ) ;
V_69 = - V_80 ;
goto V_81;
}
V_14 = F_39 ( V_5 -> V_79 , L_13 , NULL ) ;
if ( V_14 == NULL ) {
F_13 ( V_73 L_14 ) ;
V_69 = - V_80 ;
goto V_82;
}
V_5 -> V_20 = * V_14 ;
if ( V_5 -> V_20 < 0x50 )
V_5 -> V_20 += 0x50 ;
do {
V_5 -> V_83 = F_38 ( NULL , L_15 ) ;
if ( V_5 -> V_83 == NULL )
break;
V_14 = F_39 ( V_5 -> V_83 , L_13 , NULL ) ;
if ( V_14 == NULL ) {
F_40 ( V_5 -> V_83 ) ;
V_5 -> V_83 = NULL ;
break;
}
V_5 -> V_84 = * V_14 ;
if ( V_5 -> V_84 < 0x50 )
V_5 -> V_84 += 0x50 ;
} while( 0 );
V_5 -> V_18 = F_41 ( 0x8000860c , 0x1000 ) ;
if ( V_5 -> V_18 == NULL ) {
F_13 ( V_73 L_16 ) ;
V_69 = - V_80 ;
goto V_85;
}
V_5 -> V_15 = F_42 () < 4 ;
if ( V_5 -> V_15 )
F_13 ( V_37 L_17 ) ;
V_86 = V_87 ;
return 0 ;
V_85:
if ( V_5 -> V_83 )
F_40 ( V_5 -> V_83 ) ;
V_82:
F_40 ( V_5 -> V_79 ) ;
V_81:
F_43 ( F_44 ( V_5 ) , sizeof( struct V_75 ) ) ;
V_5 = NULL ;
V_74:
F_40 ( V_68 ) ;
return V_69 ;
}
static int F_45 ( void )
{
if ( ! V_5 )
return 0 ;
F_46 ( & V_5 -> V_88 ) ;
V_5 -> V_88 . V_89 = V_90 ;
V_5 -> V_88 . V_14 = ( unsigned long ) V_5 ;
if ( V_5 -> V_79 ) {
V_5 -> V_42 = F_47 ( V_5 -> V_79 , 0 ) ;
if ( V_5 -> V_42 == V_43 )
F_13 ( V_73 L_18 ,
V_5 -> V_79 -> V_91 ) ;
}
if ( V_5 -> V_83 ) {
V_5 -> V_78 = F_47 ( V_5 -> V_83 , 0 ) ;
if ( V_5 -> V_78 == V_43 )
F_13 ( V_73 L_18 ,
V_5 -> V_83 -> V_91 ) ;
}
if ( V_5 -> V_42 != V_43 ) {
if ( F_48 ( V_5 -> V_42 , F_9 ,
V_92 , L_19 , V_5 ) < 0 ) {
F_13 ( V_34 L_20
L_21 ,
V_5 -> V_42 ) ;
V_5 -> V_42 = V_43 ;
}
}
if ( V_5 -> V_78 != V_43 ) {
if ( F_48 ( V_5 -> V_78 , F_15 ,
V_92 , L_22 , V_5 ) < 0 ) {
F_13 ( V_34 L_20
L_21 ,
V_5 -> V_78 ) ;
V_5 -> V_78 = V_43 ;
}
}
V_41 = 1 ;
return 0 ;
}
static void F_49 ( struct V_93 * V_94 )
{
struct V_67 * V_68 ;
for ( V_68 = NULL ; ( V_68 = F_50 ( V_5 -> V_77 , V_68 ) ) != NULL ; )
if ( F_51 ( V_68 , L_23 ) )
F_52 ( V_68 , L_23 ,
& V_5 -> V_95 -> V_96 ) ;
}
static int F_53 ( struct V_97 * V_96 )
{
if ( ! V_5 )
return - V_38 ;
V_5 -> V_95 = V_96 ;
F_54 ( & V_98 ) ;
return 0 ;
}
static int T_4 F_55 ( void )
{
F_56 ( & V_99 ) ;
return 0 ;
}
struct V_97 * F_57 ( void )
{
if ( ! V_5 )
return NULL ;
return V_5 -> V_95 ;
}
static void F_58 ( struct V_100 * V_4 , int V_101 )
{
void (* F_10)( struct V_100 * V_4 , void * V_24 ) = V_4 -> F_10 ;
void * V_24 = V_4 -> V_24 ;
unsigned long V_23 ;
if ( ! V_101 && V_4 -> V_102 ) {
if ( V_4 -> V_103 [ 0 ] < 1 )
V_101 = 1 ;
else
memcpy ( V_4 -> V_104 . V_14 , & V_4 -> V_103 [ 1 ] ,
V_4 -> V_104 . V_105 ) ;
}
F_5 ( L_24 , ! V_101 ) ;
F_11 ( & V_5 -> V_27 , V_23 ) ;
V_5 -> V_106 = NULL ;
F_59 () ;
V_4 -> V_36 = V_101 ? - V_33 : 0 ;
if ( ! F_2 ( & V_5 -> V_76 ) ) {
struct V_100 * V_107 ;
V_107 = F_3 ( V_5 -> V_76 . V_7 ,
struct V_100 , V_8 ) ;
V_5 -> V_106 = V_107 ;
F_4 ( & V_4 -> V_8 ) ;
F_17 ( & V_4 -> V_45 . V_8 , & V_5 -> V_6 ) ;
if ( V_5 -> V_9 == NULL )
F_1 () ;
}
F_12 ( & V_5 -> V_27 , V_23 ) ;
if ( F_10 )
F_10 ( V_4 , V_24 ) ;
}
static void V_90 ( unsigned long V_14 )
{
struct V_100 * V_4 = V_5 -> V_106 ;
F_5 ( L_25 ) ;
V_4 -> V_103 [ 0 ] = 0xff ;
V_4 -> V_45 . V_31 = sizeof( V_4 -> V_103 ) ;
F_16 ( & V_4 -> V_45 ) ;
}
static void F_60 ( struct V_3 * V_45 , void * V_24 )
{
struct V_100 * V_4 = V_24 ;
int V_101 = 0 ;
F_5 ( L_26 ,
V_4 -> V_108 , V_45 -> V_36 , V_4 -> V_103 [ 0 ] , V_45 -> V_31 ) ;
if ( V_45 -> V_36 < 0 )
V_101 = 1 ;
else if ( V_4 -> V_102 ) {
if ( V_4 -> V_108 == 0 )
V_101 = V_4 -> V_103 [ 0 ] != 0 ;
else
V_101 = V_4 -> V_103 [ 0 ] >= 0x80 ;
} else {
V_101 = V_4 -> V_103 [ 0 ] != 0 ;
}
if ( V_101 && -- V_4 -> V_109 > 0 ) {
F_5 ( L_27 ) ;
F_61 ( V_4 != V_5 -> V_106 ) ;
if ( ! V_41 ) {
F_62 ( 5 ) ;
V_90 ( 0 ) ;
return;
}
F_63 ( & V_5 -> V_88 , V_110 + F_64 ( 5 ) ) ;
return;
}
if ( V_101 || V_4 -> V_108 != 0 ) {
F_58 ( V_4 , V_101 ) ;
return;
}
F_5 ( L_28 ) ;
V_45 -> V_35 = V_4 -> V_103 ;
V_45 -> V_31 = sizeof( V_4 -> V_103 ) ;
V_45 -> V_11 = V_4 -> V_103 ;
V_45 -> V_10 = 1 ;
V_4 -> V_103 [ 0 ] = 0 ;
V_4 -> V_108 = 1 ;
V_4 -> V_109 = 20 ;
F_16 ( V_45 ) ;
}
int F_65 ( struct V_100 * V_4 )
{
unsigned long V_23 ;
if ( V_5 == NULL )
return - V_38 ;
V_4 -> V_45 . V_4 = V_111 ;
V_4 -> V_45 . F_10 = F_60 ;
V_4 -> V_45 . V_24 = V_4 ;
V_4 -> V_45 . V_35 = V_4 -> V_103 ;
V_4 -> V_45 . V_31 = sizeof( V_4 -> V_103 ) ;
V_4 -> V_45 . V_11 = ( T_2 * ) ( char * ) & V_4 -> V_104 ;
V_4 -> V_45 . V_36 = 1 ;
V_4 -> V_108 = 0 ;
V_4 -> V_103 [ 0 ] = 0xff ;
V_4 -> V_109 = 20 ;
V_4 -> V_36 = 1 ;
V_4 -> V_104 . V_112 = V_4 -> V_104 . V_113 ;
V_4 -> V_102 = V_4 -> V_104 . V_113 & 0x01 ;
switch( V_4 -> V_104 . type ) {
case V_114 :
memset ( & V_4 -> V_104 . V_115 , 0 , 4 ) ;
break;
case V_116 :
V_4 -> V_104 . V_113 &= 0xfe ;
case V_117 :
if ( V_4 -> V_104 . V_115 > 3 )
return - V_40 ;
break;
default:
return - V_40 ;
}
if ( V_4 -> V_102 ) {
if ( V_4 -> V_104 . V_105 > V_118 )
return - V_40 ;
memset ( V_4 -> V_104 . V_14 , 0xff , V_4 -> V_104 . V_105 ) ;
V_4 -> V_45 . V_10 = 9 ;
} else {
if ( V_4 -> V_104 . V_105 > V_119 )
return - V_40 ;
V_4 -> V_45 . V_10 = 9 + V_4 -> V_104 . V_105 ;
}
F_5 ( L_29 ) ;
F_5 ( L_30 ,
V_4 -> V_102 ? L_31 : L_32 , V_4 -> V_104 . V_105 ,
V_4 -> V_104 . V_120 , V_4 -> V_104 . V_112 ,
V_4 -> V_104 . V_121 [ 0 ] , V_4 -> V_104 . type ) ;
F_11 ( & V_5 -> V_27 , V_23 ) ;
if ( V_5 -> V_106 == NULL ) {
V_5 -> V_106 = V_4 ;
F_17 ( & V_4 -> V_45 . V_8 , & V_5 -> V_6 ) ;
if ( V_5 -> V_9 == NULL )
F_1 () ;
} else
F_17 ( & V_4 -> V_8 , & V_5 -> V_76 ) ;
F_12 ( & V_5 -> V_27 , V_23 ) ;
return 0 ;
}
static int F_66 ( T_2 * V_122 , unsigned int V_123 , unsigned int V_124 )
{
F_67 ( V_51 ) ;
unsigned int V_125 ;
struct V_3 V_4 ;
int V_26 ;
T_2 V_126 [ 8 ] ;
V_125 = 0xe ;
while ( V_124 ) {
unsigned int V_127 = F_68 ( V_124 , V_125 ) ;
V_4 . V_4 = V_128 ;
V_4 . V_10 = 7 ;
V_4 . V_11 = V_126 ;
V_4 . V_31 = V_125 ;
V_4 . V_35 = V_122 ;
V_4 . F_10 = F_21 ;
V_4 . V_24 = & V_51 ;
V_126 [ 0 ] = V_129 ;
V_126 [ 1 ] = 0x4 ;
* ( ( T_5 * ) & V_126 [ 2 ] ) = V_123 ;
V_126 [ 6 ] = V_127 ;
V_26 = F_16 ( & V_4 ) ;
if ( V_26 )
return V_26 ;
F_69 ( & V_51 ) ;
if ( V_4 . V_36 != 0 )
return V_26 ;
if ( V_4 . V_31 != V_127 ) {
F_13 ( V_130 L_33
L_34 ,
V_4 . V_31 , V_127 ) ;
return - V_33 ;
}
V_124 -= V_127 ;
V_123 += V_127 ;
V_122 += V_127 ;
}
return 0 ;
}
static struct V_131 * F_70 ( int V_132 )
{
F_67 ( V_51 ) ;
struct V_44 V_4 ;
unsigned int V_123 , V_124 , V_133 ;
struct V_131 * V_134 ;
struct V_135 * V_136 ;
F_5 ( L_35 , V_5 -> V_42 ) ;
F_19 ( & V_4 , V_137 , 2 ,
F_21 , & V_51 ,
V_138 , V_132 ) ;
F_69 ( & V_51 ) ;
F_5 ( L_36 ,
V_4 . V_4 . V_36 , V_4 . V_4 . V_31 ) ;
if ( V_4 . V_4 . V_36 != 0 || V_4 . V_4 . V_31 != 6 )
return NULL ;
V_123 = * ( ( V_139 * ) V_4 . V_49 ) ;
V_124 = V_4 . V_49 [ 3 ] << 2 ;
V_133 = sizeof( struct V_135 ) + V_124 + 18 ;
V_136 = F_71 ( V_133 , V_140 ) ;
if ( V_136 == NULL )
return NULL ;
V_134 = (struct V_131 * ) ( V_136 + 1 ) ;
V_136 -> V_141 = ( ( char * ) V_136 ) + V_133 - 18 ;
sprintf ( V_136 -> V_141 , L_37 , V_132 ) ;
V_136 -> V_13 = V_124 ;
V_136 -> V_142 = V_134 ;
V_136 -> V_7 = NULL ;
if ( F_66 ( ( T_2 * ) V_134 , V_123 , V_124 ) ) {
F_13 ( V_130 L_38
L_39 , V_132 ) ;
goto V_143;
}
if ( V_134 -> V_132 != V_132 ) {
F_13 ( V_130 L_40
L_41 , V_132 , V_134 -> V_132 ) ;
goto V_143;
}
if ( F_72 ( V_5 -> V_77 , V_136 ) ) {
F_13 ( V_130 L_42
L_43 , V_132 ) ;
goto V_143;
}
return V_134 ;
V_143:
F_73 ( V_136 ) ;
return NULL ;
}
const struct V_131 * F_74 ( int V_132 ,
unsigned int * V_144 , int V_145 )
{
char V_146 [ 32 ] ;
const struct V_131 * V_147 ;
if ( ! V_5 )
return NULL ;
sprintf ( V_146 , L_37 , V_132 ) ;
F_5 ( L_44 , V_132 ) ;
if ( V_145 ) {
int V_26 ;
V_26 = F_75 ( & V_148 ) ;
if ( V_26 )
return F_76 ( V_26 ) ;
} else
F_77 ( & V_148 ) ;
V_147 = F_39 ( V_5 -> V_77 , V_146 , V_144 ) ;
if ( V_147 == NULL ) {
F_5 ( L_45 ) ;
V_147 = F_70 ( V_132 ) ;
if ( V_147 != NULL && V_144 )
* V_144 = V_147 -> V_124 << 2 ;
}
F_78 ( & V_148 ) ;
return V_147 ;
}
const struct V_131 * F_79 ( int V_132 , unsigned int * V_144 )
{
return F_74 ( V_132 , V_144 , 0 ) ;
}
static int F_80 ( struct V_149 * V_149 , struct V_150 * V_150 )
{
struct V_151 * V_152 ;
unsigned long V_23 ;
V_152 = F_71 ( sizeof( struct V_151 ) , V_140 ) ;
if ( V_152 == 0 )
return - V_153 ;
F_35 ( & V_152 -> V_27 ) ;
V_152 -> V_154 = V_155 ;
F_81 ( & V_152 -> V_156 ) ;
F_77 ( & V_157 ) ;
F_11 ( & V_158 , V_23 ) ;
F_82 ( & V_152 -> V_47 , & V_159 ) ;
F_12 ( & V_158 , V_23 ) ;
V_150 -> V_160 = V_152 ;
F_78 ( & V_157 ) ;
return 0 ;
}
static void F_83 ( struct V_3 * V_4 , void * V_24 )
{
struct V_151 * V_152 = V_24 ;
F_84 ( & V_152 -> V_156 ) ;
}
static T_6 F_85 ( struct V_150 * V_150 , const char T_7 * V_161 ,
T_8 V_162 , T_9 * V_163 )
{
struct V_151 * V_152 = V_150 -> V_160 ;
unsigned long V_23 ;
struct V_164 V_134 ;
int V_26 = 0 ;
if ( V_152 -> V_165 )
return - V_166 ;
else if ( F_86 ( & V_134 , V_161 , sizeof( V_134 ) ) )
return - V_167 ;
else if ( V_134 . V_168 == V_169 ) {
V_152 -> V_154 = V_170 ;
return 0 ;
} else if ( V_134 . V_168 == V_171 ) {
const struct V_131 * V_147 ;
V_147 = F_74 ( V_134 . V_4 , NULL , 1 ) ;
if ( V_147 == NULL )
return - V_40 ;
else if ( F_87 ( V_147 ) )
return F_88 ( V_147 ) ;
return 0 ;
} else if ( V_134 . V_168 != V_172 )
return - V_40 ;
else if ( V_152 -> V_154 != V_155 )
return - V_173 ;
else if ( V_134 . V_10 > V_39 )
return - V_40 ;
F_11 ( & V_152 -> V_27 , V_23 ) ;
if ( V_152 -> V_165 ) {
F_12 ( & V_152 -> V_27 , V_23 ) ;
return - V_166 ;
}
V_152 -> V_165 = 1 ;
V_152 -> V_4 . V_36 = 1 ;
F_12 ( & V_152 -> V_27 , V_23 ) ;
if ( F_86 ( V_152 -> V_49 , V_161 + sizeof( V_134 ) , V_134 . V_10 ) ) {
V_152 -> V_165 = 0 ;
return - V_167 ;
}
V_152 -> V_4 . V_4 = V_134 . V_4 ;
V_152 -> V_4 . V_10 = V_134 . V_10 ;
V_152 -> V_4 . V_31 = V_39 ;
V_152 -> V_4 . V_11 = V_152 -> V_49 ;
V_152 -> V_4 . V_35 = V_152 -> V_49 ;
V_152 -> V_4 . F_10 = F_83 ;
V_152 -> V_4 . V_24 = V_152 ;
V_26 = F_16 ( & V_152 -> V_4 ) ;
if ( V_26 < 0 )
return V_26 ;
return V_162 ;
}
static T_6 F_89 ( struct V_150 * V_150 , struct V_151 * V_152 ,
char T_7 * V_161 , T_8 V_162 )
{
F_90 ( V_156 , V_174 ) ;
struct V_175 V_134 ;
unsigned long V_23 ;
int V_144 , V_26 = 0 ;
if ( ! V_152 -> V_165 )
return 0 ;
if ( V_162 < sizeof( struct V_175 ) )
return - V_176 ;
F_11 ( & V_152 -> V_27 , V_23 ) ;
if ( V_152 -> V_4 . V_36 == 1 ) {
if ( V_150 -> V_177 & V_178 ) {
F_12 ( & V_152 -> V_27 , V_23 ) ;
return - V_179 ;
}
F_91 ( & V_152 -> V_156 , & V_156 ) ;
for (; ; ) {
F_92 ( V_180 ) ;
V_26 = 0 ;
if ( V_152 -> V_4 . V_36 != 1 )
break;
V_26 = - V_181 ;
if ( F_93 ( V_174 ) )
break;
F_12 ( & V_152 -> V_27 , V_23 ) ;
F_94 () ;
F_11 ( & V_152 -> V_27 , V_23 ) ;
}
F_92 ( V_182 ) ;
F_95 ( & V_152 -> V_156 , & V_156 ) ;
}
F_12 ( & V_152 -> V_27 , V_23 ) ;
if ( V_26 )
return V_26 ;
if ( V_152 -> V_4 . V_36 != 0 )
V_152 -> V_4 . V_31 = 0 ;
V_144 = sizeof( V_134 ) + V_152 -> V_4 . V_31 ;
if ( V_162 < V_144 )
V_144 = V_162 ;
V_26 = V_144 ;
V_134 . V_36 = V_152 -> V_4 . V_36 ;
V_134 . V_31 = V_152 -> V_4 . V_31 ;
if ( F_96 ( V_161 , & V_134 , sizeof( V_134 ) ) )
return - V_167 ;
V_144 -= sizeof( V_134 ) ;
if ( V_144 && F_96 ( V_161 + sizeof( V_134 ) , V_152 -> V_49 , V_144 ) )
return - V_167 ;
V_152 -> V_165 = 0 ;
return V_26 ;
}
static T_6 F_97 ( struct V_150 * V_150 , struct V_151 * V_152 ,
char T_7 * V_161 , T_8 V_162 )
{
F_98 ( 1000 ) ;
return 0 ;
}
static T_6 F_99 ( struct V_150 * V_150 , char T_7 * V_161 ,
T_8 V_162 , T_9 * V_163 )
{
struct V_151 * V_152 = V_150 -> V_160 ;
if ( V_152 -> V_154 == V_155 )
return F_89 ( V_150 , V_152 , V_161 , V_162 ) ;
if ( V_152 -> V_154 == V_170 )
return F_97 ( V_150 , V_152 , V_161 , V_162 ) ;
return - V_173 ;
}
static unsigned int F_100 ( struct V_150 * V_150 , T_10 * V_156 )
{
struct V_151 * V_152 = V_150 -> V_160 ;
unsigned int V_183 = 0 ;
unsigned long V_23 ;
if ( V_152 == 0 )
return 0 ;
if ( V_152 -> V_154 == V_155 ) {
F_101 ( V_150 , & V_152 -> V_156 , V_156 ) ;
F_11 ( & V_152 -> V_27 , V_23 ) ;
if ( V_152 -> V_165 && V_152 -> V_4 . V_36 != 1 )
V_183 |= V_184 ;
F_12 ( & V_152 -> V_27 , V_23 ) ;
}
if ( V_152 -> V_154 == V_170 ) {
}
return V_183 ;
}
static int F_102 ( struct V_149 * V_149 , struct V_150 * V_150 )
{
struct V_151 * V_152 = V_150 -> V_160 ;
unsigned long V_23 ;
unsigned int V_165 ;
if ( V_152 == 0 )
return 0 ;
V_150 -> V_160 = NULL ;
F_11 ( & V_152 -> V_27 , V_23 ) ;
V_152 -> V_154 = V_185 ;
V_165 = V_152 -> V_165 ;
if ( V_165 && V_152 -> V_4 . V_36 == 1 ) {
F_90 ( V_156 , V_174 ) ;
F_91 ( & V_152 -> V_156 , & V_156 ) ;
for (; ; ) {
F_92 ( V_186 ) ;
if ( V_152 -> V_4 . V_36 != 1 )
break;
F_12 ( & V_152 -> V_27 , V_23 ) ;
F_94 () ;
F_11 ( & V_152 -> V_27 , V_23 ) ;
}
F_92 ( V_182 ) ;
F_95 ( & V_152 -> V_156 , & V_156 ) ;
}
F_12 ( & V_152 -> V_27 , V_23 ) ;
F_11 ( & V_158 , V_23 ) ;
F_4 ( & V_152 -> V_47 ) ;
F_12 ( & V_158 , V_23 ) ;
F_73 ( V_152 ) ;
return 0 ;
}
static int F_103 ( void )
{
if ( ! V_5 )
return - V_38 ;
if ( F_104 ( & V_187 ) < 0 )
F_13 ( V_73 L_46 ) ;
return 0 ;
}
