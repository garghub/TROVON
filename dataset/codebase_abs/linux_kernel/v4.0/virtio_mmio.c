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
unsigned long V_36 , V_46 ;
unsigned int V_30 = V_29 -> V_30 ;
F_31 ( & V_4 -> V_44 , V_36 ) ;
F_36 ( & V_35 -> V_47 ) ;
F_34 ( & V_4 -> V_44 , V_36 ) ;
F_37 ( V_29 ) ;
F_3 ( V_30 , V_4 -> V_6 + V_48 ) ;
if ( V_4 -> V_9 == 1 ) {
F_3 ( 0 , V_4 -> V_6 + V_49 ) ;
} else {
F_3 ( 0 , V_4 -> V_6 + V_50 ) ;
F_38 ( F_4 ( V_4 -> V_6 + V_50 ) ) ;
}
V_46 = F_39 ( F_40 ( V_35 -> V_51 , V_52 ) ) ;
F_41 ( V_35 -> V_53 , V_46 ) ;
F_42 ( V_35 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_28 * V_29 , * V_54 ;
F_44 (vq, n, &vdev->vqs, list)
F_35 ( V_29 ) ;
F_45 ( F_46 ( V_4 -> V_55 , 0 ) , V_4 ) ;
}
static struct V_28 * F_47 ( struct V_1 * V_2 , unsigned V_30 ,
void (* F_48)( struct V_28 * V_29 ) ,
const char * V_56 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_34 * V_35 ;
struct V_28 * V_29 ;
unsigned long V_36 , V_46 ;
int V_57 ;
if ( ! V_56 )
return NULL ;
F_3 ( V_30 , V_4 -> V_6 + V_48 ) ;
if ( F_4 ( V_4 -> V_6 + ( V_4 -> V_9 == 1 ?
V_49 : V_50 ) ) ) {
V_57 = - V_58 ;
goto V_59;
}
V_35 = F_49 ( sizeof( * V_35 ) , V_60 ) ;
if ( ! V_35 ) {
V_57 = - V_61 ;
goto V_62;
}
V_35 -> V_51 = F_4 ( V_4 -> V_6 + V_63 ) ;
if ( V_35 -> V_51 == 0 ) {
V_57 = - V_58 ;
goto V_64;
}
while ( 1 ) {
V_46 = F_39 ( F_40 ( V_35 -> V_51 ,
V_52 ) ) ;
if ( V_46 < V_52 * 2 ) {
V_57 = - V_61 ;
goto V_64;
}
V_35 -> V_53 = F_50 ( V_46 , V_60 | V_65 ) ;
if ( V_35 -> V_53 )
break;
V_35 -> V_51 /= 2 ;
}
V_29 = F_51 ( V_30 , V_35 -> V_51 , V_52 , V_2 ,
true , V_35 -> V_53 , F_26 , F_48 , V_56 ) ;
if ( ! V_29 ) {
V_57 = - V_61 ;
goto V_66;
}
F_3 ( V_35 -> V_51 , V_4 -> V_6 + V_67 ) ;
if ( V_4 -> V_9 == 1 ) {
F_3 ( V_68 , V_4 -> V_6 + V_69 ) ;
F_3 ( F_52 ( V_35 -> V_53 ) >> V_70 ,
V_4 -> V_6 + V_49 ) ;
} else {
T_1 V_71 ;
V_71 = F_52 ( V_35 -> V_53 ) ;
F_3 ( ( V_14 ) V_71 , V_4 -> V_6 + V_72 ) ;
F_3 ( ( V_14 ) ( V_71 >> 32 ) ,
V_4 -> V_6 + V_73 ) ;
V_71 = F_52 ( F_53 ( V_29 ) ) ;
F_3 ( ( V_14 ) V_71 , V_4 -> V_6 + V_74 ) ;
F_3 ( ( V_14 ) ( V_71 >> 32 ) ,
V_4 -> V_6 + V_75 ) ;
V_71 = F_52 ( F_54 ( V_29 ) ) ;
F_3 ( ( V_14 ) V_71 , V_4 -> V_6 + V_76 ) ;
F_3 ( ( V_14 ) ( V_71 >> 32 ) ,
V_4 -> V_6 + V_77 ) ;
F_3 ( 1 , V_4 -> V_6 + V_50 ) ;
}
V_29 -> V_45 = V_35 ;
V_35 -> V_29 = V_29 ;
F_31 ( & V_4 -> V_44 , V_36 ) ;
F_55 ( & V_35 -> V_47 , & V_4 -> V_78 ) ;
F_34 ( & V_4 -> V_44 , V_36 ) ;
return V_29 ;
V_66:
if ( V_4 -> V_9 == 1 ) {
F_3 ( 0 , V_4 -> V_6 + V_49 ) ;
} else {
F_3 ( 0 , V_4 -> V_6 + V_50 ) ;
F_38 ( F_4 ( V_4 -> V_6 + V_50 ) ) ;
}
F_41 ( V_35 -> V_53 , V_46 ) ;
V_64:
F_42 ( V_35 ) ;
V_62:
V_59:
return F_56 ( V_57 ) ;
}
static int F_57 ( struct V_1 * V_2 , unsigned V_79 ,
struct V_28 * V_80 [] ,
T_7 * V_81 [] ,
const char * V_82 [] )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_32 = F_46 ( V_4 -> V_55 , 0 ) ;
int V_24 , V_57 ;
V_57 = F_58 ( V_32 , F_27 , V_83 ,
F_59 ( & V_2 -> V_11 ) , V_4 ) ;
if ( V_57 )
return V_57 ;
for ( V_24 = 0 ; V_24 < V_79 ; ++ V_24 ) {
V_80 [ V_24 ] = F_47 ( V_2 , V_24 , V_81 [ V_24 ] , V_82 [ V_24 ] ) ;
if ( F_60 ( V_80 [ V_24 ] ) ) {
F_43 ( V_2 ) ;
return F_61 ( V_80 [ V_24 ] ) ;
}
}
return 0 ;
}
static const char * F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_55 -> V_56 ;
}
static int F_63 ( struct V_84 * V_55 )
{
struct V_3 * V_4 ;
struct V_85 * V_86 ;
unsigned long V_87 ;
V_86 = F_64 ( V_55 , V_88 , 0 ) ;
if ( ! V_86 )
return - V_12 ;
if ( ! F_65 ( & V_55 -> V_11 , V_86 -> V_89 ,
F_66 ( V_86 ) , V_55 -> V_56 ) )
return - V_90 ;
V_4 = F_67 ( & V_55 -> V_11 , sizeof( * V_4 ) , V_60 ) ;
if ( ! V_4 )
return - V_61 ;
V_4 -> V_2 . V_11 . V_91 = & V_55 -> V_11 ;
V_4 -> V_2 . V_92 = & V_93 ;
V_4 -> V_55 = V_55 ;
F_68 ( & V_4 -> V_78 ) ;
F_69 ( & V_4 -> V_44 ) ;
V_4 -> V_6 = F_70 ( & V_55 -> V_11 , V_86 -> V_89 , F_66 ( V_86 ) ) ;
if ( V_4 -> V_6 == NULL )
return - V_94 ;
V_87 = F_4 ( V_4 -> V_6 + V_95 ) ;
if ( V_87 != ( 'v' | 'i' << 8 | 'r' << 16 | 't' << 24 ) ) {
F_71 ( & V_55 -> V_11 , L_2 , V_87 ) ;
return - V_96 ;
}
V_4 -> V_9 = F_4 ( V_4 -> V_6 + V_97 ) ;
if ( V_4 -> V_9 < 1 || V_4 -> V_9 > 2 ) {
F_8 ( & V_55 -> V_11 , L_3 ,
V_4 -> V_9 ) ;
return - V_98 ;
}
V_4 -> V_2 . V_99 . V_100 = F_4 ( V_4 -> V_6 + V_101 ) ;
if ( V_4 -> V_2 . V_99 . V_100 == 0 ) {
return - V_96 ;
}
V_4 -> V_2 . V_99 . V_102 = F_4 ( V_4 -> V_6 + V_103 ) ;
if ( V_4 -> V_9 == 2 &&
F_72 ( V_4 -> V_2 . V_99 ) ) {
F_8 ( & V_55 -> V_11 , L_4 ,
V_4 -> V_2 . V_99 . V_100 ) ;
return - V_96 ;
}
if ( V_4 -> V_9 == 1 )
F_3 ( V_68 , V_4 -> V_6 + V_104 ) ;
F_73 ( V_55 , V_4 ) ;
return F_74 ( & V_4 -> V_2 ) ;
}
static int F_75 ( struct V_84 * V_55 )
{
struct V_3 * V_4 = F_76 ( V_55 ) ;
F_77 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int F_78 ( const char * V_100 ,
const struct V_105 * V_106 )
{
int V_57 ;
struct V_85 V_107 [ 2 ] = {} ;
char * V_108 ;
long long int V_6 , V_46 ;
unsigned int V_32 ;
int V_109 , V_110 = 0 ;
struct V_84 * V_55 ;
V_46 = F_79 ( V_100 , & V_108 ) ;
V_109 = sscanf ( V_108 , L_5 ,
& V_6 , & V_32 , & V_110 ,
& V_111 , & V_110 ) ;
if ( V_109 < 2 || V_108 [ V_110 ] )
return - V_12 ;
V_107 [ 0 ] . V_36 = V_88 ;
V_107 [ 0 ] . V_89 = V_6 ;
V_107 [ 0 ] . V_112 = V_6 + V_46 - 1 ;
V_107 [ 1 ] . V_36 = V_113 ;
V_107 [ 1 ] . V_89 = V_107 [ 1 ] . V_112 = V_32 ;
if ( ! V_114 ) {
V_57 = F_80 ( & V_115 ) ;
if ( V_57 ) {
F_81 ( L_6 ) ;
return V_57 ;
}
V_114 = 1 ;
}
F_82 ( L_7 ,
V_111 ,
( unsigned long long ) V_107 [ 0 ] . V_89 ,
( unsigned long long ) V_107 [ 0 ] . V_112 ,
( int ) V_107 [ 1 ] . V_89 ) ;
V_55 = F_83 ( & V_115 ,
L_8 , V_111 ++ ,
V_107 , F_84 ( V_107 ) , NULL , 0 ) ;
if ( F_60 ( V_55 ) )
return F_61 ( V_55 ) ;
return 0 ;
}
static int F_85 ( struct V_100 * V_11 , void * V_116 )
{
char * V_117 = V_116 ;
unsigned int V_18 = strlen ( V_117 ) ;
struct V_84 * V_55 = F_86 ( V_11 ) ;
snprintf ( V_117 + V_18 , V_68 - V_18 , L_9 ,
V_55 -> V_85 [ 0 ] . V_112 - V_55 -> V_85 [ 0 ] . V_89 + 1ULL ,
( unsigned long long ) V_55 -> V_85 [ 0 ] . V_89 ,
( unsigned long long ) V_55 -> V_85 [ 1 ] . V_89 ,
V_55 -> V_99 ) ;
return 0 ;
}
static int F_87 ( char * V_117 , const struct V_105 * V_106 )
{
V_117 [ 0 ] = '\0' ;
F_88 ( & V_115 , V_117 ,
F_85 ) ;
return strlen ( V_117 ) + 1 ;
}
static int F_89 ( struct V_100 * V_11 ,
void * V_116 )
{
F_90 ( F_86 ( V_11 ) ) ;
return 0 ;
}
static void F_91 ( void )
{
if ( V_114 ) {
F_88 ( & V_115 , NULL ,
F_89 ) ;
F_92 ( & V_115 ) ;
V_114 = 0 ;
}
}
static void F_91 ( void )
{
}
static int T_8 F_93 ( void )
{
return F_94 ( & V_118 ) ;
}
static void T_9 F_95 ( void )
{
F_96 ( & V_118 ) ;
F_91 () ;
}
