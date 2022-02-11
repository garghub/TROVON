static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
F_3 ( 1 , V_4 -> V_6 + V_7 ) ;
V_5 = F_4 ( V_4 -> V_6 + V_8 ) ;
V_5 <<= 32 ;
F_3 ( 0 , V_4 -> V_6 + V_7 ) ;
V_5 |= F_4 ( V_4 -> V_6 + V_8 ) ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_6 ( V_2 ) ;
if ( V_4 -> V_9 == 2 &&
! F_7 ( V_2 , V_10 ) ) {
F_8 ( & V_2 -> V_11 , L_1 ) ;
return - V_12 ;
}
F_3 ( 1 , V_4 -> V_6 + V_13 ) ;
F_3 ( ( V_14 ) ( V_2 -> V_5 >> 32 ) ,
V_4 -> V_6 + V_15 ) ;
F_3 ( 0 , V_4 -> V_6 + V_13 ) ;
F_3 ( ( V_14 ) V_2 -> V_5 ,
V_4 -> V_6 + V_15 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , unsigned V_16 ,
void * V_17 , unsigned V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_2 * V_6 = V_4 -> V_6 + V_19 ;
T_3 V_20 ;
T_4 V_21 ;
T_5 V_22 ;
if ( V_4 -> V_9 == 1 ) {
T_3 * V_23 = V_17 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_18 ; V_24 ++ )
V_23 [ V_24 ] = F_10 ( V_6 + V_16 + V_24 ) ;
return;
}
switch ( V_18 ) {
case 1 :
V_20 = F_10 ( V_6 + V_16 ) ;
memcpy ( V_17 , & V_20 , sizeof V_20 ) ;
break;
case 2 :
V_21 = F_11 ( F_12 ( V_6 + V_16 ) ) ;
memcpy ( V_17 , & V_21 , sizeof V_21 ) ;
break;
case 4 :
V_22 = F_13 ( F_4 ( V_6 + V_16 ) ) ;
memcpy ( V_17 , & V_22 , sizeof V_22 ) ;
break;
case 8 :
V_22 = F_13 ( F_4 ( V_6 + V_16 ) ) ;
memcpy ( V_17 , & V_22 , sizeof V_22 ) ;
V_22 = F_13 ( F_14 ( V_6 + V_16 + sizeof V_22 ) ) ;
memcpy ( V_17 + sizeof V_22 , & V_22 , sizeof V_22 ) ;
break;
default:
F_15 () ;
}
}
static void F_16 ( struct V_1 * V_2 , unsigned V_16 ,
const void * V_17 , unsigned V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_2 * V_6 = V_4 -> V_6 + V_19 ;
T_3 V_20 ;
T_4 V_21 ;
T_5 V_22 ;
if ( V_4 -> V_9 == 1 ) {
const T_3 * V_23 = V_17 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_18 ; V_24 ++ )
F_17 ( V_23 [ V_24 ] , V_6 + V_16 + V_24 ) ;
return;
}
switch ( V_18 ) {
case 1 :
memcpy ( & V_20 , V_17 , sizeof V_20 ) ;
F_17 ( V_20 , V_6 + V_16 ) ;
break;
case 2 :
memcpy ( & V_21 , V_17 , sizeof V_21 ) ;
F_18 ( F_19 ( V_21 ) , V_6 + V_16 ) ;
break;
case 4 :
memcpy ( & V_22 , V_17 , sizeof V_22 ) ;
F_3 ( F_20 ( V_22 ) , V_6 + V_16 ) ;
break;
case 8 :
memcpy ( & V_22 , V_17 , sizeof V_22 ) ;
F_3 ( F_20 ( V_22 ) , V_6 + V_16 ) ;
memcpy ( & V_22 , V_17 + sizeof V_22 , sizeof V_22 ) ;
F_3 ( F_20 ( V_22 ) , V_6 + V_16 + sizeof V_22 ) ;
break;
default:
F_15 () ;
}
}
static V_14 F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_9 == 1 )
return 0 ;
else
return F_4 ( V_4 -> V_6 + V_25 ) ;
}
static T_3 F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_4 ( V_4 -> V_6 + V_26 ) & 0xff ;
}
static void F_23 ( struct V_1 * V_2 , T_3 V_27 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_24 ( V_27 == 0 ) ;
F_3 ( V_27 , V_4 -> V_6 + V_26 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0 , V_4 -> V_6 + V_26 ) ;
}
static bool F_26 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_2 ( V_29 -> V_2 ) ;
F_3 ( V_29 -> V_30 , V_4 -> V_6 + V_31 ) ;
return true ;
}
static T_6 F_27 ( int V_32 , void * V_33 )
{
struct V_3 * V_4 = V_33 ;
struct V_34 * V_35 ;
unsigned long V_27 ;
unsigned long V_36 ;
T_6 V_37 = V_38 ;
V_27 = F_4 ( V_4 -> V_6 + V_39 ) ;
F_3 ( V_27 , V_4 -> V_6 + V_40 ) ;
if ( F_28 ( V_27 & V_41 ) ) {
F_29 ( & V_4 -> V_2 ) ;
V_37 = V_42 ;
}
if ( F_30 ( V_27 & V_43 ) ) {
F_31 ( & V_4 -> V_44 , V_36 ) ;
F_32 (info, &vm_dev->virtqueues, node)
V_37 |= F_33 ( V_32 , V_35 -> V_29 ) ;
F_34 ( & V_4 -> V_44 , V_36 ) ;
}
return V_37 ;
}
static void F_35 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_2 ( V_29 -> V_2 ) ;
struct V_34 * V_35 = V_29 -> V_45 ;
unsigned long V_36 ;
unsigned int V_30 = V_29 -> V_30 ;
F_31 ( & V_4 -> V_44 , V_36 ) ;
F_36 ( & V_35 -> V_46 ) ;
F_34 ( & V_4 -> V_44 , V_36 ) ;
F_3 ( V_30 , V_4 -> V_6 + V_47 ) ;
if ( V_4 -> V_9 == 1 ) {
F_3 ( 0 , V_4 -> V_6 + V_48 ) ;
} else {
F_3 ( 0 , V_4 -> V_6 + V_49 ) ;
F_37 ( F_4 ( V_4 -> V_6 + V_49 ) ) ;
}
F_38 ( V_29 ) ;
F_39 ( V_35 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_28 * V_29 , * V_50 ;
F_41 (vq, n, &vdev->vqs, list)
F_35 ( V_29 ) ;
F_42 ( F_43 ( V_4 -> V_51 , 0 ) , V_4 ) ;
}
static struct V_28 * F_44 ( struct V_1 * V_2 , unsigned V_30 ,
void (* F_45)( struct V_28 * V_29 ) ,
const char * V_52 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_34 * V_35 ;
struct V_28 * V_29 ;
unsigned long V_36 ;
unsigned int V_53 ;
int V_54 ;
if ( ! V_52 )
return NULL ;
F_3 ( V_30 , V_4 -> V_6 + V_47 ) ;
if ( F_4 ( V_4 -> V_6 + ( V_4 -> V_9 == 1 ?
V_48 : V_49 ) ) ) {
V_54 = - V_55 ;
goto V_56;
}
V_35 = F_46 ( sizeof( * V_35 ) , V_57 ) ;
if ( ! V_35 ) {
V_54 = - V_58 ;
goto V_59;
}
V_53 = F_4 ( V_4 -> V_6 + V_60 ) ;
if ( V_53 == 0 ) {
V_54 = - V_55 ;
goto V_61;
}
V_29 = F_47 ( V_30 , V_53 , V_62 , V_2 ,
true , true , F_26 , F_45 , V_52 ) ;
if ( ! V_29 ) {
V_54 = - V_58 ;
goto V_61;
}
F_3 ( F_48 ( V_29 ) , V_4 -> V_6 + V_63 ) ;
if ( V_4 -> V_9 == 1 ) {
F_3 ( V_64 , V_4 -> V_6 + V_65 ) ;
F_3 ( F_49 ( V_29 ) >> V_66 ,
V_4 -> V_6 + V_48 ) ;
} else {
T_1 V_67 ;
V_67 = F_49 ( V_29 ) ;
F_3 ( ( V_14 ) V_67 , V_4 -> V_6 + V_68 ) ;
F_3 ( ( V_14 ) ( V_67 >> 32 ) ,
V_4 -> V_6 + V_69 ) ;
V_67 = F_50 ( V_29 ) ;
F_3 ( ( V_14 ) V_67 , V_4 -> V_6 + V_70 ) ;
F_3 ( ( V_14 ) ( V_67 >> 32 ) ,
V_4 -> V_6 + V_71 ) ;
V_67 = F_51 ( V_29 ) ;
F_3 ( ( V_14 ) V_67 , V_4 -> V_6 + V_72 ) ;
F_3 ( ( V_14 ) ( V_67 >> 32 ) ,
V_4 -> V_6 + V_73 ) ;
F_3 ( 1 , V_4 -> V_6 + V_49 ) ;
}
V_29 -> V_45 = V_35 ;
V_35 -> V_29 = V_29 ;
F_31 ( & V_4 -> V_44 , V_36 ) ;
F_52 ( & V_35 -> V_46 , & V_4 -> V_74 ) ;
F_34 ( & V_4 -> V_44 , V_36 ) ;
return V_29 ;
V_61:
if ( V_4 -> V_9 == 1 ) {
F_3 ( 0 , V_4 -> V_6 + V_48 ) ;
} else {
F_3 ( 0 , V_4 -> V_6 + V_49 ) ;
F_37 ( F_4 ( V_4 -> V_6 + V_49 ) ) ;
}
F_39 ( V_35 ) ;
V_59:
V_56:
return F_53 ( V_54 ) ;
}
static int F_54 ( struct V_1 * V_2 , unsigned V_75 ,
struct V_28 * V_76 [] ,
T_7 * V_77 [] ,
const char * const V_78 [] ,
struct V_79 * V_80 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_32 = F_43 ( V_4 -> V_51 , 0 ) ;
int V_24 , V_54 ;
V_54 = F_55 ( V_32 , F_27 , V_81 ,
F_56 ( & V_2 -> V_11 ) , V_4 ) ;
if ( V_54 )
return V_54 ;
for ( V_24 = 0 ; V_24 < V_75 ; ++ V_24 ) {
V_76 [ V_24 ] = F_44 ( V_2 , V_24 , V_77 [ V_24 ] , V_78 [ V_24 ] ) ;
if ( F_57 ( V_76 [ V_24 ] ) ) {
F_40 ( V_2 ) ;
return F_58 ( V_76 [ V_24 ] ) ;
}
}
return 0 ;
}
static const char * F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_51 -> V_52 ;
}
static void F_60 ( struct V_82 * V_83 ) {}
static int F_61 ( struct V_84 * V_51 )
{
struct V_3 * V_4 ;
struct V_85 * V_86 ;
unsigned long V_87 ;
int V_88 ;
V_86 = F_62 ( V_51 , V_89 , 0 ) ;
if ( ! V_86 )
return - V_12 ;
if ( ! F_63 ( & V_51 -> V_11 , V_86 -> V_90 ,
F_64 ( V_86 ) , V_51 -> V_52 ) )
return - V_91 ;
V_4 = F_65 ( & V_51 -> V_11 , sizeof( * V_4 ) , V_57 ) ;
if ( ! V_4 )
return - V_58 ;
V_4 -> V_2 . V_11 . V_92 = & V_51 -> V_11 ;
V_4 -> V_2 . V_11 . V_93 = F_60 ;
V_4 -> V_2 . V_94 = & V_95 ;
V_4 -> V_51 = V_51 ;
F_66 ( & V_4 -> V_74 ) ;
F_67 ( & V_4 -> V_44 ) ;
V_4 -> V_6 = F_68 ( & V_51 -> V_11 , V_86 -> V_90 , F_64 ( V_86 ) ) ;
if ( V_4 -> V_6 == NULL )
return - V_96 ;
V_87 = F_4 ( V_4 -> V_6 + V_97 ) ;
if ( V_87 != ( 'v' | 'i' << 8 | 'r' << 16 | 't' << 24 ) ) {
F_69 ( & V_51 -> V_11 , L_2 , V_87 ) ;
return - V_98 ;
}
V_4 -> V_9 = F_4 ( V_4 -> V_6 + V_99 ) ;
if ( V_4 -> V_9 < 1 || V_4 -> V_9 > 2 ) {
F_8 ( & V_51 -> V_11 , L_3 ,
V_4 -> V_9 ) ;
return - V_100 ;
}
V_4 -> V_2 . V_101 . V_82 = F_4 ( V_4 -> V_6 + V_102 ) ;
if ( V_4 -> V_2 . V_101 . V_82 == 0 ) {
return - V_98 ;
}
V_4 -> V_2 . V_101 . V_103 = F_4 ( V_4 -> V_6 + V_104 ) ;
if ( V_4 -> V_9 == 1 ) {
F_3 ( V_64 , V_4 -> V_6 + V_105 ) ;
V_88 = F_70 ( & V_51 -> V_11 , F_71 ( 64 ) ) ;
if ( ! V_88 )
F_72 ( & V_51 -> V_11 ,
F_71 ( 32 + V_66 ) ) ;
} else {
V_88 = F_73 ( & V_51 -> V_11 , F_71 ( 64 ) ) ;
}
if ( V_88 )
V_88 = F_73 ( & V_51 -> V_11 , F_71 ( 32 ) ) ;
if ( V_88 )
F_69 ( & V_51 -> V_11 , L_4 ) ;
F_74 ( V_51 , V_4 ) ;
return F_75 ( & V_4 -> V_2 ) ;
}
static int F_76 ( struct V_84 * V_51 )
{
struct V_3 * V_4 = F_77 ( V_51 ) ;
F_78 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int F_79 ( const char * V_82 ,
const struct V_106 * V_107 )
{
int V_54 ;
struct V_85 V_108 [ 2 ] = {} ;
char * V_109 ;
long long int V_6 , V_110 ;
unsigned int V_32 ;
int V_111 , V_112 = 0 ;
struct V_84 * V_51 ;
V_110 = F_80 ( V_82 , & V_109 ) ;
V_111 = sscanf ( V_109 , L_5 ,
& V_6 , & V_32 , & V_112 ,
& V_113 , & V_112 ) ;
if ( V_111 < 2 || V_109 [ V_112 ] )
return - V_12 ;
V_108 [ 0 ] . V_36 = V_89 ;
V_108 [ 0 ] . V_90 = V_6 ;
V_108 [ 0 ] . V_114 = V_6 + V_110 - 1 ;
V_108 [ 1 ] . V_36 = V_115 ;
V_108 [ 1 ] . V_90 = V_108 [ 1 ] . V_114 = V_32 ;
if ( ! V_116 ) {
V_54 = F_81 ( & V_117 ) ;
if ( V_54 ) {
F_82 ( L_6 ) ;
return V_54 ;
}
V_116 = 1 ;
}
F_83 ( L_7 ,
V_113 ,
( unsigned long long ) V_108 [ 0 ] . V_90 ,
( unsigned long long ) V_108 [ 0 ] . V_114 ,
( int ) V_108 [ 1 ] . V_90 ) ;
V_51 = F_84 ( & V_117 ,
L_8 , V_113 ++ ,
V_108 , F_85 ( V_108 ) , NULL , 0 ) ;
if ( F_57 ( V_51 ) )
return F_58 ( V_51 ) ;
return 0 ;
}
static int F_86 ( struct V_82 * V_11 , void * V_118 )
{
char * V_119 = V_118 ;
unsigned int V_18 = strlen ( V_119 ) ;
struct V_84 * V_51 = F_87 ( V_11 ) ;
snprintf ( V_119 + V_18 , V_64 - V_18 , L_9 ,
V_51 -> V_85 [ 0 ] . V_114 - V_51 -> V_85 [ 0 ] . V_90 + 1ULL ,
( unsigned long long ) V_51 -> V_85 [ 0 ] . V_90 ,
( unsigned long long ) V_51 -> V_85 [ 1 ] . V_90 ,
V_51 -> V_101 ) ;
return 0 ;
}
static int F_88 ( char * V_119 , const struct V_106 * V_107 )
{
V_119 [ 0 ] = '\0' ;
F_89 ( & V_117 , V_119 ,
F_86 ) ;
return strlen ( V_119 ) + 1 ;
}
static int F_90 ( struct V_82 * V_11 ,
void * V_118 )
{
F_91 ( F_87 ( V_11 ) ) ;
return 0 ;
}
static void F_92 ( void )
{
if ( V_116 ) {
F_89 ( & V_117 , NULL ,
F_90 ) ;
F_93 ( & V_117 ) ;
V_116 = 0 ;
}
}
static void F_92 ( void )
{
}
static int T_8 F_94 ( void )
{
return F_95 ( & V_120 ) ;
}
static void T_9 F_96 ( void )
{
F_97 ( & V_120 ) ;
F_92 () ;
}
