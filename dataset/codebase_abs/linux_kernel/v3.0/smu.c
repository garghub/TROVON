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
F_5 ( L_2 ,
( ( V_11 * ) V_4 -> V_12 ) [ 0 ] , ( ( V_11 * ) V_4 -> V_12 ) [ 1 ] ,
( ( V_11 * ) V_4 -> V_12 ) [ 2 ] , ( ( V_11 * ) V_4 -> V_12 ) [ 3 ] ,
( ( V_11 * ) V_4 -> V_12 ) [ 4 ] , ( ( V_11 * ) V_4 -> V_12 ) [ 5 ] ,
( ( V_11 * ) V_4 -> V_12 ) [ 6 ] , ( ( V_11 * ) V_4 -> V_12 ) [ 7 ] ) ;
V_5 -> V_13 -> V_4 = V_4 -> V_4 ;
V_5 -> V_13 -> V_14 = V_4 -> V_10 ;
memcpy ( V_5 -> V_13 -> V_15 , V_4 -> V_12 , V_4 -> V_10 ) ;
V_1 = ( unsigned long ) V_5 -> V_13 ;
V_2 = V_1 + V_5 -> V_13 -> V_14 + 2 ;
F_6 ( V_1 , V_2 ) ;
if ( V_5 -> V_16 )
V_17 = 0 ;
F_7 ( V_5 -> V_18 , V_5 -> V_19 ) ;
F_8 ( V_20 , NULL , V_5 -> V_21 , 4 ) ;
}
static T_1 F_9 ( int V_22 , void * V_23 )
{
unsigned long V_24 ;
struct V_3 * V_4 ;
void (* F_10)( struct V_3 * V_4 , void * V_25 ) = NULL ;
void * V_25 = NULL ;
V_11 V_26 ;
int V_27 = 0 ;
F_11 ( & V_5 -> V_28 , V_24 ) ;
V_26 = F_8 ( V_29 , NULL , V_5 -> V_21 ) ;
if ( ( V_26 & 7 ) != 7 ) {
F_12 ( & V_5 -> V_28 , V_24 ) ;
return V_30 ;
}
V_4 = V_5 -> V_9 ;
V_5 -> V_9 = NULL ;
if ( V_4 == NULL )
goto V_31;
if ( V_27 == 0 ) {
unsigned long V_1 ;
int V_32 ;
V_11 V_33 ;
V_1 = ( unsigned long ) V_5 -> V_13 ;
F_6 ( V_1 , V_1 + 256 ) ;
V_33 = ( ~ V_4 -> V_4 ) & 0xff ;
if ( V_33 != V_5 -> V_13 -> V_4 ) {
F_5 ( L_3 ,
V_33 , V_5 -> V_13 -> V_4 ) ;
V_27 = - V_34 ;
}
V_32 = V_27 == 0 ? V_5 -> V_13 -> V_14 : 0 ;
F_5 ( L_4 , V_32 ) ;
if ( V_32 > V_4 -> V_32 ) {
F_13 ( V_35 L_5
L_6 ,
V_32 , V_4 -> V_32 ) ;
V_32 = V_4 -> V_32 ;
}
V_4 -> V_32 = V_32 ;
if ( V_4 -> V_36 && V_32 )
memcpy ( V_4 -> V_36 , V_5 -> V_13 -> V_15 , V_32 ) ;
}
F_10 = V_4 -> F_10 ;
V_25 = V_4 -> V_25 ;
F_14 () ;
V_4 -> V_37 = V_27 ;
if ( V_5 -> V_16 )
V_17 = 1 ;
V_31:
F_1 () ;
F_12 ( & V_5 -> V_28 , V_24 ) ;
if ( F_10 )
F_10 ( V_4 , V_25 ) ;
return V_30 ;
}
static T_1 F_15 ( int V_22 , void * V_23 )
{
F_13 ( V_38 L_7 ) ;
return V_30 ;
}
int F_16 ( struct V_3 * V_4 )
{
unsigned long V_24 ;
if ( V_5 == NULL )
return - V_39 ;
if ( V_4 -> V_10 > V_40 ||
V_4 -> V_32 > V_40 )
return - V_41 ;
V_4 -> V_37 = 1 ;
F_11 ( & V_5 -> V_28 , V_24 ) ;
F_17 ( & V_4 -> V_8 , & V_5 -> V_6 ) ;
if ( V_5 -> V_9 == NULL )
F_1 () ;
F_12 ( & V_5 -> V_28 , V_24 ) ;
if ( ! V_42 || V_5 -> V_43 == V_44 )
F_18 ( V_4 ) ;
return 0 ;
}
int F_19 ( struct V_45 * V_46 , V_11 V_47 ,
unsigned int V_10 ,
void (* F_10)( struct V_3 * V_4 , void * V_25 ) ,
void * V_25 , ... )
{
struct V_3 * V_4 = & V_46 -> V_4 ;
T_2 V_48 ;
int V_49 ;
if ( V_10 > sizeof( V_46 -> V_50 ) )
return - V_41 ;
memset ( V_46 , 0 , sizeof( * V_46 ) ) ;
V_4 -> V_4 = V_47 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_12 = V_46 -> V_50 ;
V_4 -> V_32 = sizeof( V_46 -> V_50 ) ;
V_4 -> V_36 = V_46 -> V_50 ;
V_4 -> F_10 = F_10 ;
V_4 -> V_25 = V_25 ;
va_start ( V_48 , V_25 ) ;
for ( V_49 = 0 ; V_49 < V_10 ; ++ V_49 )
V_46 -> V_50 [ V_49 ] = ( V_11 ) va_arg ( V_48 , int ) ;
va_end ( V_48 ) ;
return F_16 ( V_4 ) ;
}
void F_20 ( void )
{
V_11 V_26 ;
if ( V_5 == NULL )
return;
V_26 = F_8 ( V_29 , NULL , V_5 -> V_21 ) ;
if ( ( V_26 & 7 ) == 7 )
F_9 ( V_5 -> V_43 , V_5 ) ;
}
void F_21 ( struct V_3 * V_4 , void * V_25 )
{
struct V_51 * V_52 = V_25 ;
F_22 ( V_52 ) ;
}
void F_18 ( struct V_3 * V_4 )
{
while( V_4 -> V_37 == 1 )
F_20 () ;
}
static inline int F_23 ( int V_53 )
{
return ( ( ( V_53 & 0xf0 ) >> 4 ) * 10 ) + ( V_53 & 0xf ) ;
}
static inline int F_24 ( int V_53 )
{
return ( ( V_53 / 10 ) << 4 ) + ( V_53 % 10 ) ;
}
static inline void F_25 ( struct V_54 * V_13 ,
struct V_55 * time )
{
V_13 -> V_4 = 0x8e ;
V_13 -> V_14 = 8 ;
V_13 -> V_15 [ 0 ] = 0x80 ;
V_13 -> V_15 [ 1 ] = F_24 ( time -> V_56 ) ;
V_13 -> V_15 [ 2 ] = F_24 ( time -> V_57 ) ;
V_13 -> V_15 [ 3 ] = F_24 ( time -> V_58 ) ;
V_13 -> V_15 [ 4 ] = time -> V_59 ;
V_13 -> V_15 [ 5 ] = F_24 ( time -> V_60 ) ;
V_13 -> V_15 [ 6 ] = F_24 ( time -> V_61 ) + 1 ;
V_13 -> V_15 [ 7 ] = F_24 ( time -> V_62 - 100 ) ;
}
int F_26 ( struct V_55 * time , int V_63 )
{
struct V_45 V_4 ;
int V_27 ;
if ( V_5 == NULL )
return - V_39 ;
memset ( time , 0 , sizeof( struct V_55 ) ) ;
V_27 = F_19 ( & V_4 , V_64 , 1 , NULL , NULL ,
V_65 ) ;
if ( V_27 )
return V_27 ;
F_27 ( & V_4 ) ;
time -> V_56 = F_23 ( V_4 . V_50 [ 0 ] ) ;
time -> V_57 = F_23 ( V_4 . V_50 [ 1 ] ) ;
time -> V_58 = F_23 ( V_4 . V_50 [ 2 ] ) ;
time -> V_59 = F_23 ( V_4 . V_50 [ 3 ] ) ;
time -> V_60 = F_23 ( V_4 . V_50 [ 4 ] ) ;
time -> V_61 = F_23 ( V_4 . V_50 [ 5 ] ) - 1 ;
time -> V_62 = F_23 ( V_4 . V_50 [ 6 ] ) + 100 ;
return 0 ;
}
int F_28 ( struct V_55 * time , int V_63 )
{
struct V_45 V_4 ;
int V_27 ;
if ( V_5 == NULL )
return - V_39 ;
V_27 = F_19 ( & V_4 , V_64 , 8 , NULL , NULL ,
V_66 ,
F_24 ( time -> V_56 ) ,
F_24 ( time -> V_57 ) ,
F_24 ( time -> V_58 ) ,
time -> V_59 ,
F_24 ( time -> V_60 ) ,
F_24 ( time -> V_61 ) + 1 ,
F_24 ( time -> V_62 - 100 ) ) ;
if ( V_27 )
return V_27 ;
F_27 ( & V_4 ) ;
return 0 ;
}
void F_29 ( void )
{
struct V_45 V_4 ;
if ( V_5 == NULL )
return;
if ( F_19 ( & V_4 , V_67 , 9 , NULL , NULL ,
'S' , 'H' , 'U' , 'T' , 'D' , 'O' , 'W' , 'N' , 0 ) )
return;
F_27 ( & V_4 ) ;
for (; ; )
;
}
void F_30 ( void )
{
struct V_45 V_4 ;
if ( V_5 == NULL )
return;
if ( F_19 ( & V_4 , V_67 , 8 , NULL , NULL ,
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
int T_3 F_32 ( void )
{
struct V_68 * V_69 ;
const T_4 * V_15 ;
int V_70 = 0 ;
V_69 = F_33 ( NULL , L_8 ) ;
if ( V_69 == NULL )
return - V_39 ;
F_13 ( V_38 L_9 , V_71 , V_72 ) ;
if ( V_73 == 0 ) {
F_13 ( V_74 L_10 ) ;
V_70 = - V_41 ;
goto V_75;
}
V_5 = F_34 ( sizeof( struct V_76 ) ) ;
F_35 ( & V_5 -> V_28 ) ;
F_36 ( & V_5 -> V_6 ) ;
F_36 ( & V_5 -> V_77 ) ;
V_5 -> V_78 = V_69 ;
V_5 -> V_43 = V_44 ;
V_5 -> V_79 = V_44 ;
V_5 -> V_18 = ( T_4 ) V_73 ;
V_5 -> V_13 = (struct V_54 * ) F_37 ( V_73 ) ;
V_5 -> V_80 = F_38 ( NULL , L_11 ) ;
if ( V_5 -> V_80 == NULL ) {
F_13 ( V_74 L_12 ) ;
V_70 = - V_81 ;
goto V_82;
}
V_15 = F_39 ( V_5 -> V_80 , L_13 , NULL ) ;
if ( V_15 == NULL ) {
F_13 ( V_74 L_14 ) ;
V_70 = - V_81 ;
goto V_83;
}
V_5 -> V_21 = * V_15 ;
if ( V_5 -> V_21 < 0x50 )
V_5 -> V_21 += 0x50 ;
do {
V_5 -> V_84 = F_38 ( NULL , L_15 ) ;
if ( V_5 -> V_84 == NULL )
break;
V_15 = F_39 ( V_5 -> V_84 , L_13 , NULL ) ;
if ( V_15 == NULL ) {
F_40 ( V_5 -> V_84 ) ;
V_5 -> V_84 = NULL ;
break;
}
V_5 -> V_85 = * V_15 ;
if ( V_5 -> V_85 < 0x50 )
V_5 -> V_85 += 0x50 ;
} while( 0 );
V_5 -> V_19 = F_41 ( 0x8000860c , 0x1000 ) ;
if ( V_5 -> V_19 == NULL ) {
F_13 ( V_74 L_16 ) ;
V_70 = - V_81 ;
goto V_86;
}
V_5 -> V_16 = F_42 () < 4 ;
if ( V_5 -> V_16 )
F_13 ( V_38 L_17 ) ;
V_87 = V_88 ;
return 0 ;
V_86:
if ( V_5 -> V_84 )
F_40 ( V_5 -> V_84 ) ;
V_83:
F_40 ( V_5 -> V_80 ) ;
V_82:
F_43 ( ( unsigned long ) V_5 , sizeof( struct V_76 ) ) ;
V_5 = NULL ;
V_75:
F_40 ( V_69 ) ;
return V_70 ;
}
static int F_44 ( void )
{
if ( ! V_5 )
return 0 ;
F_45 ( & V_5 -> V_89 ) ;
V_5 -> V_89 . V_90 = V_91 ;
V_5 -> V_89 . V_15 = ( unsigned long ) V_5 ;
if ( V_5 -> V_80 ) {
V_5 -> V_43 = F_46 ( V_5 -> V_80 , 0 ) ;
if ( V_5 -> V_43 == V_44 )
F_13 ( V_74 L_18 ,
V_5 -> V_80 -> V_92 ) ;
}
if ( V_5 -> V_84 ) {
V_5 -> V_79 = F_46 ( V_5 -> V_84 , 0 ) ;
if ( V_5 -> V_79 == V_44 )
F_13 ( V_74 L_18 ,
V_5 -> V_84 -> V_92 ) ;
}
if ( V_5 -> V_43 != V_44 ) {
if ( F_47 ( V_5 -> V_43 , F_9 ,
V_93 , L_19 , V_5 ) < 0 ) {
F_13 ( V_35 L_20
L_21 ,
V_5 -> V_43 ) ;
V_5 -> V_43 = V_44 ;
}
}
if ( V_5 -> V_79 != V_44 ) {
if ( F_47 ( V_5 -> V_79 , F_15 ,
V_93 , L_22 , V_5 ) < 0 ) {
F_13 ( V_35 L_20
L_21 ,
V_5 -> V_79 ) ;
V_5 -> V_79 = V_44 ;
}
}
V_42 = 1 ;
return 0 ;
}
static void F_48 ( struct V_94 * V_95 )
{
struct V_68 * V_69 ;
for ( V_69 = NULL ; ( V_69 = F_49 ( V_5 -> V_78 , V_69 ) ) != NULL ; )
if ( F_50 ( V_69 , L_23 ) )
F_51 ( V_69 , L_23 ,
& V_5 -> V_96 -> V_97 ) ;
}
static int F_52 ( struct V_98 * V_97 )
{
if ( ! V_5 )
return - V_39 ;
V_5 -> V_96 = V_97 ;
F_53 ( & V_99 ) ;
return 0 ;
}
static int T_3 F_54 ( void )
{
F_55 ( & V_100 ) ;
return 0 ;
}
struct V_98 * F_56 ( void )
{
if ( ! V_5 )
return NULL ;
return V_5 -> V_96 ;
}
static void F_57 ( struct V_101 * V_4 , int V_102 )
{
void (* F_10)( struct V_101 * V_4 , void * V_25 ) = V_4 -> F_10 ;
void * V_25 = V_4 -> V_25 ;
unsigned long V_24 ;
if ( ! V_102 && V_4 -> V_103 ) {
if ( V_4 -> V_104 [ 0 ] < 1 )
V_102 = 1 ;
else
memcpy ( V_4 -> V_105 . V_15 , & V_4 -> V_104 [ 1 ] ,
V_4 -> V_105 . V_106 ) ;
}
F_5 ( L_24 , ! V_102 ) ;
F_11 ( & V_5 -> V_28 , V_24 ) ;
V_5 -> V_107 = NULL ;
F_58 () ;
V_4 -> V_37 = V_102 ? - V_34 : 0 ;
if ( ! F_2 ( & V_5 -> V_77 ) ) {
struct V_101 * V_108 ;
V_108 = F_3 ( V_5 -> V_77 . V_7 ,
struct V_101 , V_8 ) ;
V_5 -> V_107 = V_108 ;
F_4 ( & V_4 -> V_8 ) ;
F_17 ( & V_4 -> V_46 . V_8 , & V_5 -> V_6 ) ;
if ( V_5 -> V_9 == NULL )
F_1 () ;
}
F_12 ( & V_5 -> V_28 , V_24 ) ;
if ( F_10 )
F_10 ( V_4 , V_25 ) ;
}
static void V_91 ( unsigned long V_15 )
{
struct V_101 * V_4 = V_5 -> V_107 ;
F_5 ( L_25 ) ;
V_4 -> V_104 [ 0 ] = 0xff ;
V_4 -> V_46 . V_32 = sizeof( V_4 -> V_104 ) ;
F_16 ( & V_4 -> V_46 ) ;
}
static void F_59 ( struct V_3 * V_46 , void * V_25 )
{
struct V_101 * V_4 = V_25 ;
int V_102 = 0 ;
F_5 ( L_26 ,
V_4 -> V_109 , V_46 -> V_37 , V_4 -> V_104 [ 0 ] , V_46 -> V_32 ) ;
if ( V_46 -> V_37 < 0 )
V_102 = 1 ;
else if ( V_4 -> V_103 ) {
if ( V_4 -> V_109 == 0 )
V_102 = V_4 -> V_104 [ 0 ] != 0 ;
else
V_102 = V_4 -> V_104 [ 0 ] >= 0x80 ;
} else {
V_102 = V_4 -> V_104 [ 0 ] != 0 ;
}
if ( V_102 && -- V_4 -> V_110 > 0 ) {
F_5 ( L_27 ) ;
F_60 ( V_4 != V_5 -> V_107 ) ;
if ( ! V_42 ) {
F_61 ( 5 ) ;
V_91 ( 0 ) ;
return;
}
F_62 ( & V_5 -> V_89 , V_111 + F_63 ( 5 ) ) ;
return;
}
if ( V_102 || V_4 -> V_109 != 0 ) {
F_57 ( V_4 , V_102 ) ;
return;
}
F_5 ( L_28 ) ;
V_46 -> V_36 = V_4 -> V_104 ;
V_46 -> V_32 = sizeof( V_4 -> V_104 ) ;
V_46 -> V_12 = V_4 -> V_104 ;
V_46 -> V_10 = 1 ;
V_4 -> V_104 [ 0 ] = 0 ;
V_4 -> V_109 = 1 ;
V_4 -> V_110 = 20 ;
F_16 ( V_46 ) ;
}
int F_64 ( struct V_101 * V_4 )
{
unsigned long V_24 ;
if ( V_5 == NULL )
return - V_39 ;
V_4 -> V_46 . V_4 = V_112 ;
V_4 -> V_46 . F_10 = F_59 ;
V_4 -> V_46 . V_25 = V_4 ;
V_4 -> V_46 . V_36 = V_4 -> V_104 ;
V_4 -> V_46 . V_32 = sizeof( V_4 -> V_104 ) ;
V_4 -> V_46 . V_12 = ( V_11 * ) ( char * ) & V_4 -> V_105 ;
V_4 -> V_46 . V_37 = 1 ;
V_4 -> V_109 = 0 ;
V_4 -> V_104 [ 0 ] = 0xff ;
V_4 -> V_110 = 20 ;
V_4 -> V_37 = 1 ;
V_4 -> V_105 . V_113 = V_4 -> V_105 . V_114 ;
V_4 -> V_103 = V_4 -> V_105 . V_114 & 0x01 ;
switch( V_4 -> V_105 . type ) {
case V_115 :
memset ( & V_4 -> V_105 . V_116 , 0 , 4 ) ;
break;
case V_117 :
V_4 -> V_105 . V_114 &= 0xfe ;
case V_118 :
if ( V_4 -> V_105 . V_116 > 3 )
return - V_41 ;
break;
default:
return - V_41 ;
}
if ( V_4 -> V_103 ) {
if ( V_4 -> V_105 . V_106 > V_119 )
return - V_41 ;
memset ( V_4 -> V_105 . V_15 , 0xff , V_4 -> V_105 . V_106 ) ;
V_4 -> V_46 . V_10 = 9 ;
} else {
if ( V_4 -> V_105 . V_106 > V_120 )
return - V_41 ;
V_4 -> V_46 . V_10 = 9 + V_4 -> V_105 . V_106 ;
}
F_5 ( L_29 ) ;
F_5 ( L_30 ,
V_4 -> V_103 ? L_31 : L_32 , V_4 -> V_105 . V_106 ,
V_4 -> V_105 . V_121 , V_4 -> V_105 . V_113 ,
V_4 -> V_105 . V_122 [ 0 ] , V_4 -> V_105 . type ) ;
F_11 ( & V_5 -> V_28 , V_24 ) ;
if ( V_5 -> V_107 == NULL ) {
V_5 -> V_107 = V_4 ;
F_17 ( & V_4 -> V_46 . V_8 , & V_5 -> V_6 ) ;
if ( V_5 -> V_9 == NULL )
F_1 () ;
} else
F_17 ( & V_4 -> V_8 , & V_5 -> V_77 ) ;
F_12 ( & V_5 -> V_28 , V_24 ) ;
return 0 ;
}
static int F_65 ( V_11 * V_123 , unsigned int V_124 , unsigned int V_125 )
{
F_66 ( V_52 ) ;
unsigned int V_126 ;
struct V_3 V_4 ;
int V_27 ;
V_11 V_127 [ 8 ] ;
V_126 = 0xe ;
while ( V_125 ) {
unsigned int V_128 = F_67 ( V_125 , V_126 ) ;
V_4 . V_4 = V_129 ;
V_4 . V_10 = 7 ;
V_4 . V_12 = V_127 ;
V_4 . V_32 = V_126 ;
V_4 . V_36 = V_123 ;
V_4 . F_10 = F_21 ;
V_4 . V_25 = & V_52 ;
V_127 [ 0 ] = V_130 ;
V_127 [ 1 ] = 0x4 ;
* ( ( T_4 * ) & V_127 [ 2 ] ) = V_124 ;
V_127 [ 6 ] = V_128 ;
V_27 = F_16 ( & V_4 ) ;
if ( V_27 )
return V_27 ;
F_68 ( & V_52 ) ;
if ( V_4 . V_37 != 0 )
return V_27 ;
if ( V_4 . V_32 != V_128 ) {
F_13 ( V_131 L_33
L_34 ,
V_4 . V_32 , V_128 ) ;
return - V_34 ;
}
V_125 -= V_128 ;
V_124 += V_128 ;
V_123 += V_128 ;
}
return 0 ;
}
static struct V_132 * F_69 ( int V_133 )
{
F_66 ( V_52 ) ;
struct V_45 V_4 ;
unsigned int V_124 , V_125 , V_134 ;
struct V_132 * V_135 ;
struct V_136 * V_137 ;
F_5 ( L_35 , V_5 -> V_43 ) ;
F_19 ( & V_4 , V_138 , 2 ,
F_21 , & V_52 ,
V_139 , V_133 ) ;
F_68 ( & V_52 ) ;
F_5 ( L_36 ,
V_4 . V_4 . V_37 , V_4 . V_4 . V_32 ) ;
if ( V_4 . V_4 . V_37 != 0 || V_4 . V_4 . V_32 != 6 )
return NULL ;
V_124 = * ( ( V_140 * ) V_4 . V_50 ) ;
V_125 = V_4 . V_50 [ 3 ] << 2 ;
V_134 = sizeof( struct V_136 ) + V_125 + 18 ;
V_137 = F_70 ( V_134 , V_141 ) ;
if ( V_137 == NULL )
return NULL ;
V_135 = (struct V_132 * ) ( V_137 + 1 ) ;
V_137 -> V_142 = ( ( char * ) V_137 ) + V_134 - 18 ;
sprintf ( V_137 -> V_142 , L_37 , V_133 ) ;
V_137 -> V_14 = V_125 ;
V_137 -> V_143 = V_135 ;
V_137 -> V_7 = NULL ;
if ( F_65 ( ( V_11 * ) V_135 , V_124 , V_125 ) ) {
F_13 ( V_131 L_38
L_39 , V_133 ) ;
goto V_144;
}
if ( V_135 -> V_133 != V_133 ) {
F_13 ( V_131 L_40
L_41 , V_133 , V_135 -> V_133 ) ;
goto V_144;
}
if ( F_71 ( V_5 -> V_78 , V_137 ) ) {
F_13 ( V_131 L_42
L_43 , V_133 ) ;
goto V_144;
}
return V_135 ;
V_144:
F_72 ( V_137 ) ;
return NULL ;
}
const struct V_132 * F_73 ( int V_133 ,
unsigned int * V_145 , int V_146 )
{
char V_147 [ 32 ] ;
const struct V_132 * V_148 ;
if ( ! V_5 )
return NULL ;
sprintf ( V_147 , L_37 , V_133 ) ;
F_5 ( L_44 , V_133 ) ;
if ( V_146 ) {
int V_27 ;
V_27 = F_74 ( & V_149 ) ;
if ( V_27 )
return F_75 ( V_27 ) ;
} else
F_76 ( & V_149 ) ;
V_148 = F_39 ( V_5 -> V_78 , V_147 , V_145 ) ;
if ( V_148 == NULL ) {
F_5 ( L_45 ) ;
V_148 = F_69 ( V_133 ) ;
if ( V_148 != NULL && V_145 )
* V_145 = V_148 -> V_125 << 2 ;
}
F_77 ( & V_149 ) ;
return V_148 ;
}
const struct V_132 * F_78 ( int V_133 , unsigned int * V_145 )
{
return F_73 ( V_133 , V_145 , 0 ) ;
}
static int F_79 ( struct V_150 * V_150 , struct V_151 * V_151 )
{
struct V_152 * V_153 ;
unsigned long V_24 ;
V_153 = F_70 ( sizeof( struct V_152 ) , V_141 ) ;
if ( V_153 == 0 )
return - V_154 ;
F_35 ( & V_153 -> V_28 ) ;
V_153 -> V_155 = V_156 ;
F_80 ( & V_153 -> V_157 ) ;
F_76 ( & V_158 ) ;
F_11 ( & V_159 , V_24 ) ;
F_81 ( & V_153 -> V_48 , & V_160 ) ;
F_12 ( & V_159 , V_24 ) ;
V_151 -> V_161 = V_153 ;
F_77 ( & V_158 ) ;
return 0 ;
}
static void F_82 ( struct V_3 * V_4 , void * V_25 )
{
struct V_152 * V_153 = V_25 ;
F_83 ( & V_153 -> V_157 ) ;
}
static T_5 F_84 ( struct V_151 * V_151 , const char T_6 * V_162 ,
T_7 V_163 , T_8 * V_164 )
{
struct V_152 * V_153 = V_151 -> V_161 ;
unsigned long V_24 ;
struct V_165 V_135 ;
int V_27 = 0 ;
if ( V_153 -> V_166 )
return - V_167 ;
else if ( F_85 ( & V_135 , V_162 , sizeof( V_135 ) ) )
return - V_168 ;
else if ( V_135 . V_169 == V_170 ) {
V_153 -> V_155 = V_171 ;
return 0 ;
} else if ( V_135 . V_169 == V_172 ) {
const struct V_132 * V_148 ;
V_148 = F_73 ( V_135 . V_4 , NULL , 1 ) ;
if ( V_148 == NULL )
return - V_41 ;
else if ( F_86 ( V_148 ) )
return F_87 ( V_148 ) ;
return 0 ;
} else if ( V_135 . V_169 != V_173 )
return - V_41 ;
else if ( V_153 -> V_155 != V_156 )
return - V_174 ;
else if ( V_135 . V_10 > V_40 )
return - V_41 ;
F_11 ( & V_153 -> V_28 , V_24 ) ;
if ( V_153 -> V_166 ) {
F_12 ( & V_153 -> V_28 , V_24 ) ;
return - V_167 ;
}
V_153 -> V_166 = 1 ;
V_153 -> V_4 . V_37 = 1 ;
F_12 ( & V_153 -> V_28 , V_24 ) ;
if ( F_85 ( V_153 -> V_50 , V_162 + sizeof( V_135 ) , V_135 . V_10 ) ) {
V_153 -> V_166 = 0 ;
return - V_168 ;
}
V_153 -> V_4 . V_4 = V_135 . V_4 ;
V_153 -> V_4 . V_10 = V_135 . V_10 ;
V_153 -> V_4 . V_32 = V_40 ;
V_153 -> V_4 . V_12 = V_153 -> V_50 ;
V_153 -> V_4 . V_36 = V_153 -> V_50 ;
V_153 -> V_4 . F_10 = F_82 ;
V_153 -> V_4 . V_25 = V_153 ;
V_27 = F_16 ( & V_153 -> V_4 ) ;
if ( V_27 < 0 )
return V_27 ;
return V_163 ;
}
static T_5 F_88 ( struct V_151 * V_151 , struct V_152 * V_153 ,
char T_6 * V_162 , T_7 V_163 )
{
F_89 ( V_157 , V_175 ) ;
struct V_176 V_135 ;
unsigned long V_24 ;
int V_145 , V_27 = 0 ;
if ( ! V_153 -> V_166 )
return 0 ;
if ( V_163 < sizeof( struct V_176 ) )
return - V_177 ;
F_11 ( & V_153 -> V_28 , V_24 ) ;
if ( V_153 -> V_4 . V_37 == 1 ) {
if ( V_151 -> V_178 & V_179 ) {
F_12 ( & V_153 -> V_28 , V_24 ) ;
return - V_180 ;
}
F_90 ( & V_153 -> V_157 , & V_157 ) ;
for (; ; ) {
F_91 ( V_181 ) ;
V_27 = 0 ;
if ( V_153 -> V_4 . V_37 != 1 )
break;
V_27 = - V_182 ;
if ( F_92 ( V_175 ) )
break;
F_12 ( & V_153 -> V_28 , V_24 ) ;
F_93 () ;
F_11 ( & V_153 -> V_28 , V_24 ) ;
}
F_91 ( V_183 ) ;
F_94 ( & V_153 -> V_157 , & V_157 ) ;
}
F_12 ( & V_153 -> V_28 , V_24 ) ;
if ( V_27 )
return V_27 ;
if ( V_153 -> V_4 . V_37 != 0 )
V_153 -> V_4 . V_32 = 0 ;
V_145 = sizeof( V_135 ) + V_153 -> V_4 . V_32 ;
if ( V_163 < V_145 )
V_145 = V_163 ;
V_27 = V_145 ;
V_135 . V_37 = V_153 -> V_4 . V_37 ;
V_135 . V_32 = V_153 -> V_4 . V_32 ;
if ( F_95 ( V_162 , & V_135 , sizeof( V_135 ) ) )
return - V_168 ;
V_145 -= sizeof( V_135 ) ;
if ( V_145 && F_95 ( V_162 + sizeof( V_135 ) , V_153 -> V_50 , V_145 ) )
return - V_168 ;
V_153 -> V_166 = 0 ;
return V_27 ;
}
static T_5 F_96 ( struct V_151 * V_151 , struct V_152 * V_153 ,
char T_6 * V_162 , T_7 V_163 )
{
F_97 ( 1000 ) ;
return 0 ;
}
static T_5 F_98 ( struct V_151 * V_151 , char T_6 * V_162 ,
T_7 V_163 , T_8 * V_164 )
{
struct V_152 * V_153 = V_151 -> V_161 ;
if ( V_153 -> V_155 == V_156 )
return F_88 ( V_151 , V_153 , V_162 , V_163 ) ;
if ( V_153 -> V_155 == V_171 )
return F_96 ( V_151 , V_153 , V_162 , V_163 ) ;
return - V_174 ;
}
static unsigned int F_99 ( struct V_151 * V_151 , T_9 * V_157 )
{
struct V_152 * V_153 = V_151 -> V_161 ;
unsigned int V_184 = 0 ;
unsigned long V_24 ;
if ( V_153 == 0 )
return 0 ;
if ( V_153 -> V_155 == V_156 ) {
F_100 ( V_151 , & V_153 -> V_157 , V_157 ) ;
F_11 ( & V_153 -> V_28 , V_24 ) ;
if ( V_153 -> V_166 && V_153 -> V_4 . V_37 != 1 )
V_184 |= V_185 ;
F_12 ( & V_153 -> V_28 , V_24 ) ;
} if ( V_153 -> V_155 == V_171 ) {
}
return V_184 ;
}
static int F_101 ( struct V_150 * V_150 , struct V_151 * V_151 )
{
struct V_152 * V_153 = V_151 -> V_161 ;
unsigned long V_24 ;
unsigned int V_166 ;
if ( V_153 == 0 )
return 0 ;
V_151 -> V_161 = NULL ;
F_11 ( & V_153 -> V_28 , V_24 ) ;
V_153 -> V_155 = V_186 ;
V_166 = V_153 -> V_166 ;
if ( V_166 && V_153 -> V_4 . V_37 == 1 ) {
F_89 ( V_157 , V_175 ) ;
F_90 ( & V_153 -> V_157 , & V_157 ) ;
for (; ; ) {
F_91 ( V_187 ) ;
if ( V_153 -> V_4 . V_37 != 1 )
break;
F_12 ( & V_153 -> V_28 , V_24 ) ;
F_93 () ;
F_11 ( & V_153 -> V_28 , V_24 ) ;
}
F_91 ( V_183 ) ;
F_94 ( & V_153 -> V_157 , & V_157 ) ;
}
F_12 ( & V_153 -> V_28 , V_24 ) ;
F_11 ( & V_159 , V_24 ) ;
F_4 ( & V_153 -> V_48 ) ;
F_12 ( & V_159 , V_24 ) ;
F_72 ( V_153 ) ;
return 0 ;
}
static int F_102 ( void )
{
if ( ! V_5 )
return - V_39 ;
if ( F_103 ( & V_188 ) < 0 )
F_13 ( V_74 L_46 ) ;
return 0 ;
}
