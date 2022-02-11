static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 != NULL ) {
V_2 -> V_3 = V_4 ;
V_4 = V_2 ;
}
}
static int F_2 ( struct V_1 * V_2 )
{
int V_5 = 0 ;
unsigned long V_6 ;
int V_7 = 1 ;
struct V_1 * V_8 ;
T_1 V_9 ;
if ( V_2 != NULL ) {
V_2 -> V_3 = NULL ;
F_3 ( & V_10 , V_6 ) ;
if ( V_11 == NULL )
V_11 = V_2 ;
else {
V_7 = 0 ;
V_12 -> V_3 = V_2 ;
}
V_12 = V_2 ;
F_4 ( & V_10 , V_6 ) ;
}
while ( V_7 ) {
V_7 = 0 ;
if ( V_11 -> V_13 > 0 )
F_5 ( V_11 -> V_14 ,
V_11 -> V_15 ,
V_11 -> V_13 ,
V_16 ) ;
V_9 = F_6 (
& V_11 -> V_17 . V_18 ) ;
if ( V_9 != V_19 ) {
F_7 ( V_20 L_1
L_2 , ( int ) V_9 ) ;
F_3 ( & V_10 , V_6 ) ;
V_8 = V_11 ;
V_11 = V_11 -> V_3 ;
if ( V_11 != NULL )
V_7 = 1 ;
F_4 ( & V_10 , V_6 ) ;
if ( V_8 == V_2 )
V_5 = - V_21 ;
else if ( V_8 -> V_22 != NULL )
(* V_8 -> V_22 )( ( void * ) V_8 -> V_17 . V_18 . V_23 , - V_21 ) ;
F_3 ( & V_10 , V_6 ) ;
F_1 ( V_8 ) ;
F_4 ( & V_10 , V_6 ) ;
}
}
return V_5 ;
}
static struct V_1 * F_8 ( void )
{
struct V_1 * V_2 = NULL ;
T_2 V_24 = F_9 () ;
unsigned long V_6 ;
struct V_25 * V_26 ;
F_3 ( & V_10 , V_6 ) ;
if ( V_4 != NULL ) {
V_2 = V_4 ;
V_4 = V_4 -> V_3 ;
}
F_4 ( & V_10 , V_6 ) ;
if ( V_2 == NULL ) {
V_2 = F_10 ( sizeof( struct V_1 ) , V_27 ) ;
if ( V_2 == NULL ) {
F_7 ( V_20 L_3 ,
sizeof( struct V_1 ) ) ;
return NULL ;
}
}
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_26 = & V_2 -> V_17 . V_18 ;
V_26 -> V_6 = V_28 | V_29 | V_30 ;
V_26 -> V_31 = V_32 ;
V_26 -> V_33 = F_11 () ;
V_26 -> V_34 = V_24 ;
V_26 -> V_35 = sizeof( V_2 -> V_17 ) - 1 ;
V_26 -> V_36 = V_19 ;
V_26 -> V_37 = F_12 ( V_24 ,
V_32 ) ;
V_26 -> V_38 = F_13 ( V_24 ,
V_32 ) ;
return V_2 ;
}
static int T_3
F_14 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_8 () ;
int V_5 ;
struct V_41 V_42 ;
if ( V_2 == NULL )
return - V_43 ;
F_15 ( & V_42 . V_44 ) ;
V_42 . V_42 = V_40 ;
V_2 -> V_17 . V_18 . V_45 = 6 ;
V_2 -> V_17 . V_18 . V_46 . V_47 =
F_16 ( 'M' , 'F' , 'V' , 'I' ) ;
V_2 -> V_17 . V_48 . V_40 . V_49 = ( V_50 ) & V_42 ;
V_2 -> V_17 . V_48 . V_40 . V_51 = V_40 -> V_51 ;
V_2 -> V_17 . V_48 . V_40 . V_52 = F_11 () ;
V_2 -> V_17 . V_48 . V_40 . V_53 = 0xFF ;
V_2 -> V_17 . V_48 . V_40 . V_54 = 0 ;
memcpy ( & ( V_2 -> V_17 . V_48 . V_40 . V_55 ) ,
& ( V_40 -> V_55 ) , sizeof( V_40 -> V_55 ) ) ;
F_17 () ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 == 0 )
F_18 ( & V_42 . V_44 ) ;
return V_5 ;
}
static int F_19 ( char * V_56 , struct V_57 * V_58 )
{
struct V_1 * V_2 = F_8 () ;
if ( V_2 == NULL )
return - V_43 ;
V_2 -> V_17 . V_18 . V_45 = 0 ;
V_2 -> V_17 . V_18 . V_46 . V_47 =
F_16 ( 'M' , 'F' , 'C' , 'E' ) ;
memcpy ( V_2 -> V_17 . V_48 . V_56 . V_56 , V_56 , 12 ) ;
V_2 -> V_17 . V_48 . V_56 . V_58 = V_58 ;
return F_2 ( V_2 ) ;
}
static int F_20 ( T_4 V_59 , struct V_57 * V_58 )
{
T_4 V_56 [ 12 ] ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
V_56 [ 3 ] = V_59 ;
return F_19 ( V_56 , V_58 ) ;
}
static int F_21 ( char * V_56 ,
struct V_57 * V_58 , void * V_14 ,
unsigned V_13 , unsigned V_15 )
{
struct V_1 * V_2 = F_8 () ;
if ( V_2 == NULL )
return - V_43 ;
V_2 -> V_17 . V_18 . V_45 = 0 ;
V_2 -> V_17 . V_18 . V_46 . V_47 =
F_16 ( 'M' , 'F' , 'C' , 'E' ) ;
memcpy ( V_2 -> V_17 . V_48 . V_56 . V_56 , V_56 , 12 ) ;
V_2 -> V_17 . V_48 . V_56 . V_58 = V_58 ;
memcpy ( V_2 -> V_14 , V_14 , V_13 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_15 = V_15 ;
return F_2 ( V_2 ) ;
}
static int F_22 ( void )
{
int V_5 = F_23 ( V_60 , 1 ) ;
if ( V_5 ) {
F_7 ( V_61 L_4
L_5 , V_5 ) ;
F_24 () ;
} else
F_7 ( V_62 L_6
L_7 ) ;
return V_5 ;
}
static void F_25 ( struct V_63 * V_17 )
{
struct V_64 * V_64 ;
struct V_64 * V_65 ;
unsigned long V_6 ;
struct V_1 * V_66 ;
V_17 -> V_18 . V_36 = V_19 ;
F_26 ( & V_17 -> V_18 ) ;
switch ( V_17 -> V_18 . V_45 ) {
case 0 :
V_64 = & V_17 -> V_48 . V_56 ;
switch ( V_64 -> V_56 [ 3 ] ) {
case 0x5B :
if ( ( V_64 -> V_56 [ 5 ] & 0x20 ) != 0 ) {
F_7 ( V_62 L_8 ) ;
if ( F_22 () == 0 )
F_20 ( 0xDB , NULL ) ;
}
break;
case 0xC0 :
F_3 ( & V_10 , V_6 ) ;
V_66 = V_11 ;
if ( V_66 != NULL )
V_11 = V_11 -> V_3 ;
F_4 ( & V_10 , V_6 ) ;
if ( V_66 == NULL )
break;
V_65 = & V_66 -> V_17 . V_48 . V_56 ;
if ( V_65 -> V_56 [ 3 ] != 0x40 )
break;
if ( V_65 -> V_58 != NULL ) {
T_5 V_67 =
V_65 -> V_58 -> V_67 ;
void * V_49 = V_65 -> V_58 -> V_49 ;
if ( V_67 != NULL )
(* V_67)( V_49 , V_64 ) ;
}
F_3 ( & V_10 , V_6 ) ;
F_1 ( V_66 ) ;
F_4 ( & V_10 , V_6 ) ;
if ( V_11 != NULL )
F_2 ( NULL ) ;
break;
}
break;
case 1 :
F_7 ( V_62 L_9 ) ;
F_22 () ;
break;
}
}
static void F_27 ( struct V_63 * V_17 )
{
unsigned long V_6 ;
struct V_1 * V_68 = NULL ;
unsigned long V_69 = 0 ;
struct V_64 * V_64 ;
struct V_64 * V_65 ;
struct V_41 * V_70 ;
if ( V_11 == NULL ) {
F_7 ( V_20 L_10 ) ;
return;
}
switch ( V_17 -> V_18 . V_45 ) {
case 0 :
V_64 = & V_17 -> V_48 . V_56 ;
if ( V_64 -> V_56 [ 3 ] != 0x40 ) {
V_69 = 1 ;
break;
}
if ( V_64 -> V_56 [ 2 ] == 0 )
break;
V_69 = 1 ;
V_65 = & V_11 -> V_17 . V_48 . V_56 ;
if ( V_65 -> V_58 != NULL ) {
T_5 V_67 =
V_65 -> V_58 -> V_67 ;
void * V_49 = V_65 -> V_58 -> V_49 ;
if ( V_67 != NULL )
(* V_67)( V_49 , V_64 ) ;
}
break;
case 4 :
case 5 :
if ( V_11 -> V_22 != NULL )
(* V_11 -> V_22 )( ( void * ) V_17 -> V_18 . V_23 , V_17 -> V_48 . V_71 . V_72 ) ;
V_69 = 1 ;
break;
case 6 :
V_69 = 1 ;
V_70 = (struct V_41 * ) V_17 -> V_48 . V_40 . V_49 ;
if ( V_70 == NULL ) {
F_7 ( V_20 L_11 ) ;
break;
}
if ( V_70 -> V_42 != NULL )
memcpy ( V_70 -> V_42 , & V_17 -> V_48 . V_40 ,
sizeof( V_17 -> V_48 . V_40 ) ) ;
F_28 ( & V_70 -> V_44 ) ;
break;
}
F_3 ( & V_10 , V_6 ) ;
if ( ( V_11 != NULL ) && ( V_69 == 1 ) ) {
struct V_1 * V_73 = V_11 ;
V_11 = V_11 -> V_3 ;
V_68 = V_11 ;
F_1 ( V_73 ) ;
}
F_4 ( & V_10 , V_6 ) ;
if ( V_68 != NULL )
F_2 ( NULL ) ;
}
static void F_29 ( struct V_25 * V_17 )
{
if ( ( V_17 != NULL ) && ( V_17 -> V_31 == V_32 ) ) {
if ( F_30 ( V_17 ) )
F_27 ( (struct V_63 * ) V_17 ) ;
else
F_25 ( (struct V_63 * ) V_17 ) ;
} else
F_7 ( V_20 L_12 ) ;
}
void F_31 ( T_2 V_74 , T_6 type ,
unsigned V_75 , unsigned V_72 , T_7 V_22 ,
void * V_76 )
{
struct V_1 * V_2 = F_8 () ;
int V_5 ;
if ( V_2 == NULL ) {
V_5 = - V_43 ;
} else {
V_2 -> V_17 . V_18 . V_45 = 4 ;
V_2 -> V_17 . V_18 . V_23 = ( V_50 ) V_76 ;
V_2 -> V_17 . V_18 . V_46 . V_47 =
F_16 ( 'M' , 'F' , 'M' , 'A' ) ;
V_2 -> V_17 . V_48 . V_71 . V_74 = V_74 ;
V_2 -> V_17 . V_48 . V_71 . type = type ;
V_2 -> V_17 . V_48 . V_71 . V_75 = V_75 ;
V_2 -> V_17 . V_48 . V_71 . V_72 = V_72 ;
V_2 -> V_22 = V_22 ;
V_5 = F_2 ( V_2 ) ;
}
if ( ( V_5 != 0 ) && ( V_22 != NULL ) )
(* V_22)( V_76 , V_5 ) ;
}
void F_32 ( T_2 V_74 , T_6 type ,
unsigned V_72 , T_7 V_22 , void * V_76 )
{
struct V_1 * V_2 = F_8 () ;
int V_5 ;
if ( V_2 == NULL )
V_5 = - V_43 ;
else {
V_2 -> V_17 . V_18 . V_45 = 5 ;
V_2 -> V_17 . V_18 . V_23 = ( V_50 ) V_76 ;
V_2 -> V_17 . V_18 . V_46 . V_47 =
F_16 ( 'M' , 'F' , 'M' , 'D' ) ;
V_2 -> V_17 . V_48 . V_71 . V_74 = V_74 ;
V_2 -> V_17 . V_48 . V_71 . type = type ;
V_2 -> V_17 . V_48 . V_71 . V_72 = V_72 ;
V_2 -> V_22 = V_22 ;
V_5 = F_2 ( V_2 ) ;
}
if ( ( V_5 != 0 ) && ( V_22 != NULL ) )
(* V_22)( V_76 , V_5 ) ;
}
void F_24 ( void )
{
F_7 ( V_62 L_13 ) ;
F_20 ( 0x4d , NULL ) ;
for (; ; )
;
}
void F_33 ( char * V_51 )
{
F_7 ( V_62 L_14 ) ;
F_20 ( 0x4e , NULL ) ;
for (; ; )
;
}
void F_34 ( T_8 V_77 )
{
T_4 V_78 [ 12 ] ;
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
V_78 [ 3 ] = 0x4a ;
V_78 [ 7 ] = 0x01 ;
V_78 [ 8 ] = V_77 >> 24 ;
V_78 [ 9 ] = V_77 >> 16 ;
V_78 [ 10 ] = V_77 >> 8 ;
V_78 [ 11 ] = V_77 ;
F_19 ( V_78 , NULL ) ;
}
static T_9 void F_35 ( T_10 V_79 )
{
T_4 V_78 [ 12 ] ;
T_4 V_80 [ 72 ] ;
memcpy ( V_78 , L_15 , 12 ) ;
memcpy ( V_80 , L_16
L_17
L_17
L_18 ,
72 ) ;
V_80 [ 6 ] = V_79 >> 8 ;
V_80 [ 7 ] = V_79 & 255 ;
V_80 [ 44 ] = L_19 [ ( V_79 >> 12 ) & 15 ] ;
V_80 [ 45 ] = L_19 [ ( V_79 >> 8 ) & 15 ] ;
V_80 [ 46 ] = L_19 [ ( V_79 >> 4 ) & 15 ] ;
V_80 [ 47 ] = L_19 [ V_79 & 15 ] ;
F_21 ( V_78 , NULL , V_80 , sizeof( V_80 ) , 9 * 64 * 1024 ) ;
}
static void F_36 ( void )
{
F_20 ( 0x4b , NULL ) ;
}
void T_9 F_37 ( T_10 V_79 )
{
if ( ! V_81 )
return;
if ( 0xFFFF == V_79 )
F_36 () ;
else
F_35 ( V_79 ) ;
}
void T_9 F_38 ( void )
{
int V_82 ;
F_39 ( & V_10 ) ;
for ( V_82 = 0 ; V_82 < V_83 ; V_82 ++ )
F_1 ( & V_84 [ V_82 ] ) ;
F_40 ( V_32 , & F_29 ) ;
F_20 ( 0x57 , NULL ) ;
V_81 = 1 ;
F_17 () ;
F_7 ( V_85 L_20
L_21 ) ;
}
static void F_41 ( void * V_49 , struct V_64 * V_56 )
{
struct V_86 * V_87 = V_49 ;
memcpy ( & V_87 -> V_56 , V_56 , sizeof( V_87 -> V_56 ) ) ;
V_87 -> V_5 = 0 ;
F_28 ( & V_87 -> V_44 ) ;
}
static int F_42 ( struct V_88 * V_89 )
{
char V_90 [ 12 ] ;
T_4 V_91 , V_92 , V_93 , V_94 , V_95 , y1 , V_96 ;
unsigned V_97 ;
V_97 = 1900 + V_89 -> V_98 ;
y1 = V_97 / 100 ;
V_96 = V_97 % 100 ;
V_95 = V_89 -> V_99 ;
V_94 = V_89 -> V_100 ;
V_93 = V_89 -> V_101 ;
V_91 = V_89 -> V_102 ;
V_92 = V_89 -> V_103 + 1 ;
V_95 = F_43 ( V_95 ) ;
V_94 = F_43 ( V_94 ) ;
V_93 = F_43 ( V_93 ) ;
V_92 = F_43 ( V_92 ) ;
V_91 = F_43 ( V_91 ) ;
y1 = F_43 ( y1 ) ;
V_96 = F_43 ( V_96 ) ;
memset ( V_90 , 0 , sizeof( V_90 ) ) ;
V_90 [ 3 ] = 0x41 ;
V_90 [ 4 ] = y1 ;
V_90 [ 5 ] = V_96 ;
V_90 [ 6 ] = V_95 ;
V_90 [ 7 ] = V_94 ;
V_90 [ 8 ] = V_93 ;
V_90 [ 10 ] = V_91 ;
V_90 [ 11 ] = V_92 ;
return F_19 ( V_90 , NULL ) ;
}
static int F_44 ( int V_5 , T_4 * V_56 , struct V_88 * V_89 )
{
V_89 -> V_104 = 0 ;
V_89 -> V_105 = 0 ;
V_89 -> V_106 = 0 ;
if ( V_5 ) {
V_89 -> V_99 = 0 ;
V_89 -> V_100 = 0 ;
V_89 -> V_101 = 0 ;
V_89 -> V_102 = 15 ;
V_89 -> V_103 = 5 ;
V_89 -> V_98 = 52 ;
return V_5 ;
}
if ( ( V_56 [ 2 ] == 0xa9 ) ||
( V_56 [ 2 ] == 0xaf ) ) {
V_89 -> V_99 = 1 ;
V_89 -> V_100 = 1 ;
V_89 -> V_101 = 1 ;
V_89 -> V_102 = 10 ;
V_89 -> V_103 = 8 ;
V_89 -> V_98 = 71 ;
F_42 ( V_89 ) ;
}
{
T_4 V_97 = V_56 [ 5 ] ;
T_4 V_95 = V_56 [ 6 ] ;
T_4 V_94 = V_56 [ 7 ] ;
T_4 V_93 = V_56 [ 8 ] ;
T_4 V_91 = V_56 [ 10 ] ;
T_4 V_92 = V_56 [ 11 ] ;
V_95 = F_45 ( V_95 ) ;
V_94 = F_45 ( V_94 ) ;
V_93 = F_45 ( V_93 ) ;
V_91 = F_45 ( V_91 ) ;
V_92 = F_45 ( V_92 ) ;
V_97 = F_45 ( V_97 ) ;
if ( V_97 <= 69 )
V_97 += 100 ;
V_89 -> V_99 = V_95 ;
V_89 -> V_100 = V_94 ;
V_89 -> V_101 = V_93 ;
V_89 -> V_102 = V_91 ;
V_89 -> V_103 = V_92 ;
V_89 -> V_98 = V_97 ;
}
return 0 ;
}
static int F_46 ( struct V_88 * V_89 )
{
struct V_57 V_107 ;
struct V_86 V_108 ;
int V_5 ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
F_15 ( & V_108 . V_44 ) ;
V_107 . V_67 = & F_41 ;
V_107 . V_49 = & V_108 ;
V_5 = F_20 ( 0x40 , & V_107 ) ;
if ( V_5 )
return V_5 ;
F_18 ( & V_108 . V_44 ) ;
return F_44 ( V_108 . V_5 , V_108 . V_56 . V_56 , V_89 ) ;
}
static void F_47 ( void * V_49 , struct V_64 * V_56 )
{
struct V_109 * V_87 = V_49 ;
memcpy ( & V_87 -> V_56 , V_56 , sizeof( V_87 -> V_56 ) ) ;
V_87 -> V_5 = 0 ;
V_87 -> V_110 = 0 ;
}
static int F_48 ( struct V_88 * V_89 )
{
struct V_57 V_107 ;
struct V_109 V_108 ;
int V_5 ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_110 = 1 ;
V_107 . V_67 = & F_47 ;
V_107 . V_49 = & V_108 ;
V_5 = F_20 ( 0x40 , & V_107 ) ;
if ( V_5 )
return V_5 ;
while ( V_108 . V_110 ) {
if ( F_49 () )
F_50 () ;
}
return F_44 ( V_108 . V_5 , V_108 . V_56 . V_56 , V_89 ) ;
}
static int F_51 ( struct V_111 * V_112 , void * V_113 )
{
char * V_114 , * V_115 ;
struct V_39 V_40 ;
int V_5 ;
T_11 V_116 ;
V_114 = F_10 ( 256 , V_117 ) ;
if ( ! V_114 )
return - V_43 ;
V_116 = F_52 ( V_114 , 256 , V_118 ) ;
if ( V_116 == V_119 ) {
F_53 ( V_114 ) ;
return - V_43 ;
}
memset ( V_114 , 0 , 256 ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_51 = 33 ;
V_40 . V_55 . V_120 . V_49 = V_116 ;
V_40 . V_55 . V_120 . V_121 = V_122 ;
V_40 . V_55 . V_120 . V_123 = ( V_50 ) V_112 -> V_124 ;
V_40 . V_55 . V_120 . V_125 = 256 ;
F_17 () ;
V_5 = F_14 ( & V_40 ) ;
F_54 ( V_116 , 256 , V_118 ) ;
if ( V_5 ) {
F_53 ( V_114 ) ;
return V_5 ;
}
if ( V_40 . V_53 != 0 ) {
F_53 ( V_114 ) ;
return - V_43 ;
}
V_115 = V_114 ;
while ( V_115 - V_114 < 256 ) {
if ( * V_115 == '\0' || * V_115 == '\n' ) {
* V_115 = '\n' ;
break;
}
V_115 ++ ;
}
F_55 ( V_112 , V_114 , V_115 - V_114 ) ;
F_53 ( V_114 ) ;
return 0 ;
}
static int F_56 ( struct V_126 * V_126 , struct V_127 * V_127 )
{
return F_57 ( V_127 , F_51 , F_58 ( V_126 ) -> V_48 ) ;
}
static int F_59 ( struct V_111 * V_112 , void * V_113 )
{
char V_128 = ' ' ;
struct V_39 V_40 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_51 = 2 ;
V_40 . V_55 . V_129 = 0 ;
F_17 () ;
if ( F_14 ( & V_40 ) == 0 ) {
if ( V_40 . V_53 == 0 ) {
switch ( V_40 . V_55 . V_129 ) {
case 0 : V_128 = 'A' ;
break;
case 1 : V_128 = 'B' ;
break;
case 2 : V_128 = 'C' ;
break;
default: V_128 = 'D' ;
break;
}
}
}
F_60 ( V_112 , L_22 , V_128 ) ;
return 0 ;
}
static int F_61 ( struct V_126 * V_126 , struct V_127 * V_127 )
{
return F_57 ( V_127 , F_59 , NULL ) ;
}
static T_12 F_62 ( struct V_127 * V_127 , const char T_13 * V_130 ,
T_14 V_72 , T_15 * V_131 )
{
char V_123 ;
V_50 V_132 ;
struct V_39 V_40 ;
if ( ! F_63 ( V_133 ) )
return - V_134 ;
if ( V_72 == 0 )
return 0 ;
if ( F_64 ( V_123 , V_130 ) )
return - V_135 ;
switch ( V_123 ) {
case 'A' : V_132 = 0 ;
break;
case 'B' : V_132 = 1 ;
break;
case 'C' : V_132 = 2 ;
break;
case 'D' : V_132 = 3 ;
break;
default:
F_7 ( V_20 L_23 ) ;
return - V_136 ;
}
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_55 . V_129 = V_132 ;
V_40 . V_51 = 10 ;
( void ) F_14 ( & V_40 ) ;
return V_72 ;
}
static int F_65 ( struct V_111 * V_112 , void * V_113 )
{
return 0 ;
}
static int F_66 ( struct V_126 * V_126 , struct V_127 * V_127 )
{
return F_57 ( V_127 , F_65 , NULL ) ;
}
static T_12 F_67 ( struct V_127 * V_127 , const char T_13 * V_130 ,
T_14 V_72 , T_15 * V_131 )
{
char V_137 [ 10 ] ;
if ( ! F_63 ( V_133 ) )
return - V_134 ;
if ( ( V_72 < 4 ) && ( V_72 != 1 ) ) {
F_7 ( V_20 L_24 ) ;
return - V_136 ;
}
if ( V_72 > ( sizeof( V_137 ) - 1 ) )
V_72 = sizeof( V_137 ) - 1 ;
if ( F_68 ( V_137 , V_130 , V_72 ) )
return - V_135 ;
if ( ( V_72 == 1 ) && ( * V_137 == '\0' ) )
F_36 () ;
else
F_34 ( * ( T_8 * ) V_137 ) ;
return V_72 ;
}
static T_12 F_69 ( struct V_127 * V_127 , const char T_13 * V_130 ,
T_14 V_72 , T_15 * V_131 )
{
void * V_48 = F_58 ( V_127 -> V_138 . V_139 -> V_140 ) -> V_48 ;
struct V_39 V_40 ;
T_11 V_116 ;
char * V_114 ;
int V_141 = - V_134 ;
if ( ! F_63 ( V_133 ) )
goto V_142;
V_116 = 0 ;
V_114 = F_70 ( V_72 , & V_116 , V_27 ) ;
V_141 = - V_43 ;
if ( V_114 == NULL )
goto V_142;
V_141 = - V_135 ;
if ( F_68 ( V_114 , V_130 , V_72 ) )
goto V_143;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_51 = 31 ;
V_40 . V_55 . V_120 . V_49 = V_116 ;
V_40 . V_55 . V_120 . V_121 = V_122 ;
V_40 . V_55 . V_120 . V_123 = ( V_50 ) V_48 ;
V_40 . V_55 . V_120 . V_125 = V_72 ;
F_17 () ;
( void ) F_14 ( & V_40 ) ;
V_141 = V_72 ;
V_143:
F_71 ( V_72 , V_114 , V_116 ) ;
V_142:
return V_141 ;
}
static T_12 F_72 ( struct V_127 * V_127 ,
const char T_13 * V_144 ,
T_14 V_72 , T_15 * V_145 )
{
struct V_146 * V_147 = F_58 ( V_127 -> V_138 . V_139 -> V_140 ) ;
T_12 V_5 ;
T_11 V_116 ;
char * V_114 ;
struct V_39 V_40 ;
V_5 = - V_134 ;
if ( ! F_63 ( V_133 ) )
goto V_142;
V_116 = 0 ;
V_114 = F_70 ( V_72 , & V_116 , V_27 ) ;
V_5 = - V_43 ;
if ( V_114 == NULL ) {
F_7 ( V_20 L_25 ) ;
goto V_142;
}
V_5 = - V_135 ;
if ( F_68 ( V_114 , V_144 , V_72 ) )
goto V_143;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_51 = 30 ;
V_40 . V_55 . V_120 . V_49 = V_116 ;
V_40 . V_55 . V_120 . V_121 = V_122 ;
V_40 . V_55 . V_120 . V_123 = ( V_50 ) V_147 -> V_48 ;
V_40 . V_55 . V_120 . V_148 = * V_145 ;
V_40 . V_55 . V_120 . V_125 = V_72 ;
F_17 () ;
V_5 = F_14 ( & V_40 ) ;
if ( V_5 )
goto V_143;
V_5 = - V_43 ;
if ( V_40 . V_53 != 0 )
goto V_143;
* V_145 += V_72 ;
V_5 = V_72 ;
V_143:
F_71 ( V_72 , V_114 , V_116 ) ;
V_142:
return V_5 ;
}
static int T_9 F_73 ( void )
{
struct V_146 * V_149 ;
struct V_146 * V_150 ;
struct V_146 * V_151 ;
char V_152 [ 2 ] ;
int V_82 ;
if ( ! F_74 ( V_153 ) )
return 0 ;
V_149 = F_75 ( L_26 , NULL ) ;
if ( ! V_149 )
return 1 ;
V_152 [ 1 ] = '\0' ;
for ( V_82 = 0 ; V_82 < 4 ; V_82 ++ ) {
V_152 [ 0 ] = 'A' + V_82 ;
V_151 = F_75 ( V_152 , V_149 ) ;
if ( ! V_151 )
return 1 ;
V_150 = F_76 ( L_27 , V_154 | V_155 , V_151 ,
& V_156 , ( void * ) ( long ) V_82 ) ;
if ( ! V_150 )
return 1 ;
if ( V_82 == 3 )
continue;
V_150 = F_76 ( L_28 , V_157 | V_155 , V_151 ,
& V_158 ,
( void * ) ( long ) V_82 ) ;
if ( ! V_150 )
return 1 ;
}
V_150 = F_77 ( L_29 , V_157 | V_154 | V_155 , V_149 ,
& V_159 ) ;
if ( ! V_150 )
return 1 ;
V_150 = F_77 ( L_30 , V_157 | V_154 | V_155 , V_149 ,
& V_160 ) ;
if ( ! V_150 )
return 1 ;
return 0 ;
}
void F_78 ( struct V_88 * V_161 )
{
F_46 ( V_161 ) ;
V_161 -> V_103 -- ;
}
int F_79 ( struct V_88 * V_89 )
{
F_42 ( V_89 ) ;
return 0 ;
}
unsigned long F_80 ( void )
{
struct V_88 V_89 ;
F_48 ( & V_89 ) ;
return mktime ( V_89 . V_98 + 1900 , V_89 . V_103 , V_89 . V_102 ,
V_89 . V_101 , V_89 . V_100 , V_89 . V_99 ) ;
}
