int F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_3 ;
V_2 -> V_2 . V_4 = & V_5 ;
return F_2 ( & V_2 -> V_2 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_2 ) ;
}
static void F_5 ( void )
{
F_6 ( V_6 , V_7 ) ;
F_6 ( 1 , V_8 ) ;
F_6 ( V_9 | F_7 ( 0xFFFF ) , V_10 ) ;
F_6 ( F_8 ( V_11 ) , V_12 ) ;
F_6 ( 1 , V_13 ) ;
}
void F_9 ( struct V_14 * V_15 ,
void (* F_10) ( struct V_16 * V_17 ) ,
unsigned long V_18 , unsigned long V_19 )
{
V_15 -> F_10 = F_10 ;
V_15 -> V_18 = V_18 ;
V_15 -> V_19 = F_11 ( V_19 ) ;
V_15 -> V_20 = V_21 ;
}
static int F_12 ( void )
{
return ( F_13 ( V_22 ) & 1 ) == 0 ;
}
static void F_14 ( struct V_23 * V_15 )
{
struct V_14 * V_24 ;
struct V_16 * V_17 ;
V_24 = F_15 ( V_15 ) ;
V_17 = V_24 -> V_17 ;
F_16 ( V_25 , V_17 -> V_26 ) ;
F_17 ( V_17 ) ;
F_17 ( V_24 ) ;
}
int F_18 ( struct V_14 * V_24 , T_1 V_19 , T_1 V_27 ,
T_2 V_28 , void * V_29 )
{
int V_30 = 0 ;
void * V_31 = NULL ;
if ( V_28 ) {
V_31 = F_19 ( V_28 * 4 , V_32 ) ;
if ( ! V_31 ) {
V_30 = - V_33 ;
goto V_34;
}
( ( V_35 * ) V_31 ) [ 0 ] = F_11 ( V_19 ) ;
}
V_24 -> V_17 -> V_27 = V_27 ;
V_24 -> V_17 -> V_28 = V_28 ;
if ( V_28 > 1 )
memcpy ( V_31 + 4 , V_29 , ( V_28 - 1 ) * 4 ) ;
V_24 -> V_17 -> V_31 = V_31 ;
F_20 ( & V_36 ) ;
F_21 ( & V_24 -> V_17 -> V_37 , & V_38 ) ;
F_22 ( & V_36 ) ;
V_34:
return V_30 ;
}
static struct V_16 * F_23 ( struct V_14 * V_24 )
{
struct V_16 * V_17 ;
V_17 = F_19 ( sizeof( * V_17 ) , V_32 ) ;
if ( ! V_17 )
goto V_39;
F_24 ( & V_17 -> V_37 ) ;
V_17 -> V_15 = V_24 ;
V_17 -> V_26 = F_25 ( V_25 , V_32 ) ;
if ( ! V_17 -> V_26 )
goto V_40;
V_17 -> V_26 -> V_41 = & ( ( V_17 -> V_26 -> V_42 ) [ 0 ] ) ;
return V_17 ;
V_40:
F_17 ( V_17 ) ;
V_39:
F_26 ( & V_24 -> V_15 , L_1 ,
V_24 -> V_43 , V_24 -> V_44 ) ;
return NULL ;
}
static struct V_14 * F_27 ( int V_43 , int V_44 )
{
struct V_14 * V_24 ;
V_24 = F_19 ( sizeof( * V_24 ) , V_32 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_43 = V_43 ;
V_24 -> V_44 = V_44 ;
V_24 -> V_17 = F_23 ( V_24 ) ;
if ( ! V_24 -> V_17 ) {
F_17 ( V_24 ) ;
return NULL ;
}
V_24 -> V_15 . V_4 = & V_5 ;
V_24 -> V_15 . V_45 = & V_46 ;
F_28 ( & V_24 -> V_47 ) ;
return V_24 ;
}
static void F_29 ( struct V_14 * V_24 )
{
F_16 ( V_25 , V_24 -> V_17 -> V_26 ) ;
F_17 ( V_24 -> V_17 ) ;
F_17 ( V_24 ) ;
}
static void F_30 ( struct V_16 * V_17 )
{
int V_43 , V_44 , V_48 , V_49 , V_50 ;
unsigned long * V_51 = V_17 -> V_31 ;
V_43 = V_17 -> V_15 -> V_43 & 3 ;
V_44 = V_17 -> V_15 -> V_44 ;
V_50 = V_17 -> V_28 ;
V_48 = V_43 << 6 ;
V_49 = ( V_43 << 6 ) | ( V_44 > 0 ? ( 1 << ( V_44 - 1 ) ) & 0x1f : 0x20 ) ;
* V_52 &= 0x7fffffff ;
V_52 = V_53 ;
* V_53 ++ = ( V_43 << 16 ) | V_50 | 0x80000000 ;
* V_53 ++ = F_8 ( V_17 -> V_26 -> V_41 ) ;
* V_53 ++ =
V_17 -> V_27 | ( V_49 << 8 ) | ( V_48 << 16 ) | ( V_50 << 24 ) ;
while ( V_50 -- > 0 )
* V_53 ++ = * V_51 ++ ;
}
static void F_31 ( void )
{
int V_54 , V_55 = 0 ;
struct V_16 * V_17 , * V_56 ;
if ( ! F_12 () )
return;
F_6 ( 0 , V_13 ) ;
if ( ! F_32 ( & V_57 ) )
goto V_58;
F_20 ( & V_36 ) ;
if ( F_32 ( & V_38 ) ) {
F_22 ( & V_36 ) ;
goto V_58;
}
V_52 = V_11 ;
V_53 = V_11 ;
F_33 (mq, nmq, &maple_waitq, list) {
F_30 ( V_17 ) ;
F_34 ( & V_17 -> V_37 ) ;
F_21 ( & V_17 -> V_37 , & V_57 ) ;
if ( V_55 ++ > V_59 )
break;
}
F_22 ( & V_36 ) ;
if ( V_55 > 0 ) {
for ( V_54 = 0 ; V_54 < ( 1 << V_60 ) ; V_54 ++ )
F_35 ( 0 , V_11 + V_54 * V_61 ,
V_61 , V_62 ) ;
}
V_58:
F_5 () ;
}
static int F_36 ( struct V_63 * V_64 ,
void * V_65 )
{
struct V_1 * V_66 ;
struct V_14 * V_24 ;
V_24 = V_65 ;
V_66 = F_37 ( V_64 ) ;
if ( V_24 -> V_67 . V_19 & F_11 ( V_66 -> V_19 ) )
return 1 ;
return 0 ;
}
static void F_38 ( struct V_14 * V_24 )
{
F_39 ( & V_24 -> V_15 ) ;
}
static void F_40 ( struct V_14 * V_24 )
{
char * V_68 , * V_26 ;
unsigned long V_19 ;
int V_69 , error ;
V_26 = V_24 -> V_17 -> V_26 -> V_41 ;
memcpy ( & V_24 -> V_67 . V_19 , V_26 + 4 , 4 ) ;
memcpy ( & V_24 -> V_67 . V_70 [ 0 ] , V_26 + 8 , 12 ) ;
memcpy ( & V_24 -> V_67 . V_71 , V_26 + 20 , 1 ) ;
memcpy ( & V_24 -> V_67 . V_72 , V_26 + 21 , 1 ) ;
memcpy ( & V_24 -> V_67 . V_73 [ 0 ] , V_26 + 22 , 30 ) ;
memcpy ( & V_24 -> V_67 . V_74 , V_26 + 112 , 2 ) ;
memcpy ( & V_24 -> V_67 . V_75 , V_26 + 114 , 2 ) ;
memcpy ( V_24 -> V_73 , V_24 -> V_67 . V_73 , 30 ) ;
V_24 -> V_73 [ 30 ] = '\0' ;
memcpy ( V_24 -> V_76 , V_24 -> V_67 . V_76 , 60 ) ;
V_24 -> V_76 [ 60 ] = '\0' ;
for ( V_68 = V_24 -> V_73 + 29 ; V_24 -> V_73 <= V_68 ; V_68 -- )
if ( * V_68 == ' ' )
* V_68 = '\0' ;
else
break;
for ( V_68 = V_24 -> V_76 + 59 ; V_24 -> V_76 <= V_68 ; V_68 -- )
if ( * V_68 == ' ' )
* V_68 = '\0' ;
else
break;
V_19 = F_41 ( V_24 -> V_67 . V_19 ) ;
F_42 ( & V_24 -> V_15 , L_2 ,
V_24 -> V_73 , V_19 , V_24 -> V_43 , V_24 -> V_44 ) ;
if ( V_19 > 0x200 ) {
V_19 = 0 ;
V_24 -> V_64 = & V_77 ;
F_43 ( & V_24 -> V_15 , L_3 , V_24 -> V_43 ) ;
} else {
V_69 =
F_44 ( & V_5 , NULL , V_24 ,
F_36 ) ;
if ( V_69 == 0 ) {
F_42 ( & V_24 -> V_15 , L_4 ) ;
V_24 -> V_64 = & V_77 ;
}
F_43 ( & V_24 -> V_15 , L_5 , V_24 -> V_43 ,
V_24 -> V_44 , V_19 ) ;
}
V_24 -> V_19 = V_19 ;
V_24 -> V_15 . V_78 = & F_14 ;
F_45 ( & V_24 -> V_79 , 0 ) ;
error = F_46 ( & V_24 -> V_15 ) ;
if ( error ) {
F_47 ( & V_24 -> V_15 , L_6
L_7 , V_24 -> V_44 ,
V_24 -> V_43 , error ) ;
F_29 ( V_24 ) ;
V_24 = NULL ;
return;
}
}
static int F_48 ( struct V_23 * V_23 , void * V_80 )
{
struct V_81 * V_82 ;
struct V_14 * V_24 ;
V_82 = V_80 ;
V_24 = F_15 ( V_23 ) ;
if ( V_24 -> V_43 == V_82 -> V_43 && V_24 -> V_44 == V_82 -> V_44 )
return 1 ;
return 0 ;
}
static int F_49 ( struct V_23 * V_23 , void * V_83 )
{
int V_84 ;
struct V_14 * V_24 = F_15 ( V_23 ) ;
if ( V_24 -> V_18 > 0 && F_50 ( & V_24 -> V_79 ) == 0 &&
F_51 ( V_21 , V_24 -> V_20 ) ) {
V_84 = F_18 ( V_24 ,
F_41 ( V_24 -> V_67 . V_19 ) ,
V_85 , 1 , NULL ) ;
if ( ! V_84 )
V_24 -> V_20 = V_21 + V_24 -> V_18 ;
} else {
if ( F_51 ( V_21 , V_86 ) )
if ( F_50 ( & V_24 -> V_79 ) == 0 ) {
F_45 ( & V_24 -> V_79 , 1 ) ;
F_18 ( V_24 , 0 ,
V_87 , 0 , NULL ) ;
}
}
return 0 ;
}
static void F_52 ( struct V_88 * V_89 )
{
int V_90 , V_91 ;
struct V_14 * V_24 ;
if ( ! F_12 () )
return;
F_6 ( 0 , V_13 ) ;
if ( ! F_32 ( & V_57 ) )
goto V_58;
F_53 ( & V_5 , NULL , NULL ,
F_49 ) ;
if ( F_51 ( V_21 , V_86 ) ) {
for ( V_90 = 0 ; V_90 < V_92 ; V_90 ++ ) {
if ( V_93 [ V_90 ] && V_94 [ V_90 ] ) {
V_24 = V_95 [ V_90 ] ;
if ( ! V_24 )
break;
F_45 ( & V_24 -> V_79 , 1 ) ;
V_91 = F_18 ( V_24 , 0 ,
V_87 , 0 , NULL ) ;
if ( ! V_91 )
break;
}
}
V_86 = V_21 + V_96 ;
}
V_58:
F_31 () ;
}
static void F_54 ( struct V_14 * V_24 , int V_97 )
{
int V_98 , V_99 , V_100 ;
struct V_14 * V_101 ;
struct V_81 V_82 ;
V_82 . V_43 = V_24 -> V_43 ;
for ( V_99 = 0 ; V_99 < 5 ; V_99 ++ ) {
V_82 . V_44 = V_99 + 1 ;
V_98 =
F_53 ( & V_5 , NULL , & V_82 ,
F_48 ) ;
if ( V_98 ) {
V_97 = V_97 >> 1 ;
continue;
}
V_100 = V_97 & 0x01 ;
if ( V_100 ) {
V_101 = F_27 ( V_24 -> V_43 , V_99 + 1 ) ;
if ( ! V_101 )
return;
F_45 ( & V_101 -> V_79 , 1 ) ;
F_18 ( V_101 , 0 , V_87 ,
0 , NULL ) ;
V_102 = 1 ;
}
V_97 = V_97 >> 1 ;
}
}
static void F_55 ( struct V_14 * V_24 )
{
int V_103 ;
V_103 = ( V_24 -> V_44 > 0 ? ( 1 << ( V_24 -> V_44 - 1 ) ) & 0x1f : 0x20 ) ;
V_103 = ~ V_103 ;
V_103 &= 0xFF ;
V_104 [ V_24 -> V_43 ] = V_104 [ V_24 -> V_43 ] & V_103 ;
}
static void F_56 ( struct V_14 * V_24 )
{
F_55 ( V_24 ) ;
if ( F_57 ( V_24 -> V_44 != 0 ) ) {
if ( V_24 -> V_105 ) {
if ( ! V_24 -> V_105 ( V_24 ) ) {
F_45 ( & V_24 -> V_79 , 2 ) ;
F_58 ( & V_24 -> V_47 ) ;
return;
}
}
F_42 ( & V_24 -> V_15 , L_8 ,
V_24 -> V_43 , V_24 -> V_44 ) ;
F_38 ( V_24 ) ;
return;
} else {
if ( ! V_106 || ! V_107 ) {
if ( V_93 [ V_24 -> V_43 ] == false ) {
V_93 [ V_24 -> V_43 ] = true ;
V_94 [ V_24 -> V_43 ] = true ;
F_42 ( & V_24 -> V_15 , L_9
L_10 , V_24 -> V_43 ) ;
}
return;
}
}
F_45 ( & V_24 -> V_79 , 0 ) ;
}
static void F_59 ( struct V_14 * V_24 ,
char * V_26 )
{
char V_97 ;
if ( ! V_106 || ( V_102 == 2 ) || ! V_107 ) {
if ( ( V_24 -> V_44 == 0 ) && ( V_93 [ V_24 -> V_43 ] == false ) ) {
V_93 [ V_24 -> V_43 ] = true ;
F_40 ( V_24 ) ;
} else {
if ( V_24 -> V_44 != 0 )
F_40 ( V_24 ) ;
if ( V_24 -> V_44 == 0 ) {
V_94 [ V_24 -> V_43 ] = false ;
F_40 ( V_24 ) ;
}
}
}
if ( V_24 -> V_44 == 0 ) {
V_97 = V_26 [ 2 ] & 0x1F ;
if ( V_97 ^ V_104 [ V_24 -> V_43 ] ) {
F_54 ( V_24 , V_97 ) ;
V_104 [ V_24 -> V_43 ] = V_97 ;
}
}
}
static void F_60 ( struct V_14 * V_24 , void * V_26 )
{
if ( V_24 -> V_108 ) {
V_24 -> V_108 ( V_24 , V_26 ) ;
return;
} else
F_47 ( & V_24 -> V_15 , L_11
L_12 , V_24 -> V_43 , V_24 -> V_44 ,
( ( int * ) V_26 ) [ 1 ] ) ;
}
static void F_61 ( void )
{
int V_54 ;
struct V_14 * V_24 ;
V_107 = 1 ;
for ( V_54 = 0 ; V_54 < V_92 ; V_54 ++ ) {
if ( V_93 [ V_54 ] == false ) {
V_107 = 0 ;
V_24 = V_95 [ V_54 ] ;
F_18 ( V_24 , 0 , V_87 ,
0 , NULL ) ;
}
}
}
static void F_62 ( struct V_88 * V_89 )
{
struct V_16 * V_17 , * V_56 ;
struct V_14 * V_24 ;
char * V_26 ;
enum V_109 V_110 ;
if ( ! F_12 () )
return;
F_6 ( 0 , V_13 ) ;
if ( ! F_32 ( & V_57 ) ) {
F_33 (mq, nmq, &maple_sentq, list) {
V_24 = V_17 -> V_15 ;
V_26 = V_17 -> V_26 -> V_41 ;
F_35 ( & V_24 -> V_15 , V_26 , 0x400 ,
V_111 ) ;
V_110 = V_26 [ 0 ] ;
F_17 ( V_17 -> V_31 ) ;
F_34 ( & V_17 -> V_37 ) ;
switch ( V_110 ) {
case V_112 :
F_56 ( V_24 ) ;
break;
case V_113 :
F_59 ( V_24 , V_26 ) ;
F_45 ( & V_24 -> V_79 , 0 ) ;
break;
case V_114 :
if ( V_24 -> F_10 )
V_24 -> F_10 ( V_17 ) ;
F_45 ( & V_24 -> V_79 , 0 ) ;
F_58 ( & V_24 -> V_47 ) ;
break;
case V_115 :
F_60 ( V_24 , V_26 ) ;
F_45 ( & V_24 -> V_79 , 0 ) ;
F_58 ( & V_24 -> V_47 ) ;
break;
case V_116 :
case V_117 :
case V_118 :
F_47 ( & V_24 -> V_15 , L_13
L_14 , V_110 ,
V_24 -> V_43 , V_24 -> V_44 ) ;
F_45 ( & V_24 -> V_79 , 0 ) ;
break;
case V_119 :
F_63 ( & V_24 -> V_15 , L_15
L_16
L_17 , V_24 -> V_43 ,
V_24 -> V_44 ) ;
F_45 ( & V_24 -> V_79 , 0 ) ;
break;
case V_120 :
F_45 ( & V_24 -> V_79 , 0 ) ;
F_58 ( & V_24 -> V_47 ) ;
break;
default:
break;
}
}
if ( V_102 == 1 ) {
F_31 () ;
V_102 = 2 ;
} else
V_102 = 0 ;
if ( ! V_107 )
F_61 () ;
V_106 = 1 ;
}
F_31 () ;
}
static T_3 F_64 ( int V_121 , void * V_122 )
{
F_65 ( & V_123 ) ;
return V_124 ;
}
static T_3 F_66 ( int V_121 , void * V_122 )
{
F_65 ( & V_125 ) ;
return V_124 ;
}
static int F_67 ( void )
{
return F_68 ( V_126 , F_64 ,
V_127 , L_18 , & V_77 ) ;
}
static int F_69 ( void )
{
return F_68 ( V_128 , F_66 ,
V_127 , L_19 , & V_77 ) ;
}
static int F_70 ( void )
{
V_11 =
( void * ) F_71 ( V_32 | V_129 ,
V_60 ) ;
if ( ! V_11 )
return - V_33 ;
return 0 ;
}
static int F_72 ( struct V_23 * V_65 ,
struct V_63 * V_130 )
{
struct V_1 * V_66 = F_37 ( V_130 ) ;
struct V_14 * V_131 = F_15 ( V_65 ) ;
if ( V_131 -> V_67 . V_19 == 0xFFFFFFFF )
return 0 ;
else if ( V_131 -> V_67 . V_19 &
F_11 ( V_66 -> V_19 ) )
return 1 ;
return 0 ;
}
static int F_73 ( struct V_23 * V_15 ,
struct V_132 * V_133 )
{
return 0 ;
}
static void F_74 ( struct V_23 * V_15 )
{
}
static int T_4 F_75 ( void )
{
int V_98 , V_54 ;
struct V_14 * V_24 [ V_92 ] ;
F_6 ( 0 , V_13 ) ;
V_98 = F_46 ( & V_46 ) ;
if ( V_98 )
goto V_134;
V_98 = F_76 ( & V_5 ) ;
if ( V_98 )
goto V_135;
V_98 = F_2 ( & V_77 . V_2 ) ;
if ( V_98 )
goto V_136;
V_98 = F_70 () ;
if ( V_98 ) {
F_26 ( & V_46 , L_20 ) ;
goto V_137;
}
V_98 = F_67 () ;
if ( V_98 ) {
F_26 ( & V_46 , L_21
L_22 ) ;
goto V_138;
}
V_98 = F_69 () ;
if ( V_98 ) {
F_26 ( & V_46 , L_23 ) ;
goto V_139;
}
V_25 = F_77 ( V_140 , V_141 ) ;
if ( ! V_25 )
goto V_142;
F_24 ( & V_38 ) ;
F_24 ( & V_57 ) ;
for ( V_54 = 0 ; V_54 < V_92 ; V_54 ++ ) {
V_93 [ V_54 ] = false ;
V_94 [ V_54 ] = false ;
V_24 [ V_54 ] = F_27 ( V_54 , 0 ) ;
if ( ! V_24 [ V_54 ] ) {
while ( V_54 -- > 0 )
F_29 ( V_24 [ V_54 ] ) ;
goto V_143;
}
V_95 [ V_54 ] = V_24 [ V_54 ] ;
F_45 ( & V_24 [ V_54 ] -> V_79 , 1 ) ;
F_18 ( V_24 [ V_54 ] , 0 , V_87 , 0 , NULL ) ;
V_104 [ V_54 ] = 0 ;
}
V_86 = V_21 + V_144 ;
F_31 () ;
F_42 ( & V_46 , L_24 ) ;
return 0 ;
V_143:
F_78 ( V_25 ) ;
V_142:
F_79 ( V_128 , 0 ) ;
V_139:
F_79 ( V_126 , 0 ) ;
V_138:
F_80 ( ( unsigned long ) V_11 , V_60 ) ;
V_137:
F_4 ( & V_77 . V_2 ) ;
V_136:
F_81 ( & V_5 ) ;
V_135:
F_39 ( & V_46 ) ;
V_134:
F_82 ( V_145 L_25 ) ;
return V_98 ;
}
