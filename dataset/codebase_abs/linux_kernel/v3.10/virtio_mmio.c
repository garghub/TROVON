static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0 , V_4 -> V_5 + V_6 ) ;
return F_4 ( V_4 -> V_5 + V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_8 ;
F_6 ( V_2 ) ;
for ( V_8 = 0 ; V_8 < F_7 ( V_2 -> V_9 ) ; V_8 ++ ) {
F_3 ( V_8 , V_4 -> V_5 + V_10 ) ;
F_3 ( V_2 -> V_9 [ V_8 ] ,
V_4 -> V_5 + V_11 ) ;
}
}
static void F_8 ( struct V_1 * V_2 , unsigned V_12 ,
void * V_13 , unsigned V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 * V_15 = V_13 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_14 ; V_8 ++ )
V_15 [ V_8 ] = F_9 ( V_4 -> V_5 + V_16 + V_12 + V_8 ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned V_12 ,
const void * V_13 , unsigned V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const T_2 * V_15 = V_13 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_14 ; V_8 ++ )
F_11 ( V_15 [ V_8 ] , V_4 -> V_5 + V_16 + V_12 + V_8 ) ;
}
static T_2 F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_4 ( V_4 -> V_5 + V_17 ) & 0xff ;
}
static void F_13 ( struct V_1 * V_2 , T_2 V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_14 ( V_18 == 0 ) ;
F_3 ( V_18 , V_4 -> V_5 + V_17 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0 , V_4 -> V_5 + V_17 ) ;
}
static void F_16 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_20 -> V_2 ) ;
F_3 ( V_20 -> V_21 , V_4 -> V_5 + V_22 ) ;
}
static T_3 F_17 ( int V_23 , void * V_24 )
{
struct V_3 * V_4 = V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 = F_18 ( V_4 -> V_2 . V_29 . V_30 ,
struct V_27 , V_30 ) ;
unsigned long V_18 ;
unsigned long V_31 ;
T_3 V_32 = V_33 ;
V_18 = F_4 ( V_4 -> V_5 + V_34 ) ;
F_3 ( V_18 , V_4 -> V_5 + V_35 ) ;
if ( F_19 ( V_18 & V_36 )
&& V_28 && V_28 -> V_37 ) {
V_28 -> V_37 ( & V_4 -> V_2 ) ;
V_32 = V_38 ;
}
if ( F_20 ( V_18 & V_39 ) ) {
F_21 ( & V_4 -> V_40 , V_31 ) ;
F_22 (info, &vm_dev->virtqueues, node)
V_32 |= F_23 ( V_23 , V_26 -> V_20 ) ;
F_24 ( & V_4 -> V_40 , V_31 ) ;
}
return V_32 ;
}
static void F_25 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_20 -> V_2 ) ;
struct V_25 * V_26 = V_20 -> V_41 ;
unsigned long V_31 , V_42 ;
unsigned int V_21 = V_20 -> V_21 ;
F_21 ( & V_4 -> V_40 , V_31 ) ;
F_26 ( & V_26 -> V_43 ) ;
F_24 ( & V_4 -> V_40 , V_31 ) ;
F_27 ( V_20 ) ;
F_3 ( V_21 , V_4 -> V_5 + V_44 ) ;
F_3 ( 0 , V_4 -> V_5 + V_45 ) ;
V_42 = F_28 ( F_29 ( V_26 -> V_46 , V_47 ) ) ;
F_30 ( V_26 -> V_48 , V_42 ) ;
F_31 ( V_26 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_19 * V_20 , * V_49 ;
F_33 (vq, n, &vdev->vqs, list)
F_25 ( V_20 ) ;
F_34 ( F_35 ( V_4 -> V_50 , 0 ) , V_4 ) ;
}
static struct V_19 * F_36 ( struct V_1 * V_2 , unsigned V_21 ,
void (* F_37)( struct V_19 * V_20 ) ,
const char * V_51 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_25 * V_26 ;
struct V_19 * V_20 ;
unsigned long V_31 , V_42 ;
int V_52 ;
if ( ! V_51 )
return NULL ;
F_3 ( V_21 , V_4 -> V_5 + V_44 ) ;
if ( F_4 ( V_4 -> V_5 + V_45 ) ) {
V_52 = - V_53 ;
goto V_54;
}
V_26 = F_38 ( sizeof( * V_26 ) , V_55 ) ;
if ( ! V_26 ) {
V_52 = - V_56 ;
goto V_57;
}
V_26 -> V_46 = F_4 ( V_4 -> V_5 + V_58 ) ;
if ( V_26 -> V_46 == 0 ) {
V_52 = - V_53 ;
goto V_59;
}
while ( 1 ) {
V_42 = F_28 ( F_29 ( V_26 -> V_46 ,
V_47 ) ) ;
if ( V_42 < V_47 * 2 ) {
V_52 = - V_56 ;
goto V_59;
}
V_26 -> V_48 = F_39 ( V_42 , V_55 | V_60 ) ;
if ( V_26 -> V_48 )
break;
V_26 -> V_46 /= 2 ;
}
F_3 ( V_26 -> V_46 , V_4 -> V_5 + V_61 ) ;
F_3 ( V_47 ,
V_4 -> V_5 + V_62 ) ;
F_3 ( F_40 ( V_26 -> V_48 ) >> V_63 ,
V_4 -> V_5 + V_45 ) ;
V_20 = F_41 ( V_21 , V_26 -> V_46 , V_47 , V_2 ,
true , V_26 -> V_48 , F_16 , F_37 , V_51 ) ;
if ( ! V_20 ) {
V_52 = - V_56 ;
goto V_64;
}
V_20 -> V_41 = V_26 ;
V_26 -> V_20 = V_20 ;
F_21 ( & V_4 -> V_40 , V_31 ) ;
F_42 ( & V_26 -> V_43 , & V_4 -> V_65 ) ;
F_24 ( & V_4 -> V_40 , V_31 ) ;
return V_20 ;
V_64:
F_3 ( 0 , V_4 -> V_5 + V_45 ) ;
F_30 ( V_26 -> V_48 , V_42 ) ;
V_59:
F_31 ( V_26 ) ;
V_57:
V_54:
return F_43 ( V_52 ) ;
}
static int F_44 ( struct V_1 * V_2 , unsigned V_66 ,
struct V_19 * V_67 [] ,
T_4 * V_68 [] ,
const char * V_69 [] )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_23 = F_35 ( V_4 -> V_50 , 0 ) ;
int V_8 , V_52 ;
V_52 = F_45 ( V_23 , F_17 , V_70 ,
F_46 ( & V_2 -> V_29 ) , V_4 ) ;
if ( V_52 )
return V_52 ;
for ( V_8 = 0 ; V_8 < V_66 ; ++ V_8 ) {
V_67 [ V_8 ] = F_36 ( V_2 , V_8 , V_68 [ V_8 ] , V_69 [ V_8 ] ) ;
if ( F_47 ( V_67 [ V_8 ] ) ) {
F_32 ( V_2 ) ;
return F_48 ( V_67 [ V_8 ] ) ;
}
}
return 0 ;
}
static const char * F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_50 -> V_51 ;
}
static int F_50 ( struct V_71 * V_50 )
{
struct V_3 * V_4 ;
struct V_72 * V_73 ;
unsigned long V_74 ;
V_73 = F_51 ( V_50 , V_75 , 0 ) ;
if ( ! V_73 )
return - V_76 ;
if ( ! F_52 ( & V_50 -> V_29 , V_73 -> V_77 ,
F_53 ( V_73 ) , V_50 -> V_51 ) )
return - V_78 ;
V_4 = F_54 ( & V_50 -> V_29 , sizeof( * V_4 ) , V_55 ) ;
if ( ! V_4 )
return - V_56 ;
V_4 -> V_2 . V_29 . V_79 = & V_50 -> V_29 ;
V_4 -> V_2 . V_80 = & V_81 ;
V_4 -> V_50 = V_50 ;
F_55 ( & V_4 -> V_65 ) ;
F_56 ( & V_4 -> V_40 ) ;
V_4 -> V_5 = F_57 ( & V_50 -> V_29 , V_73 -> V_77 , F_53 ( V_73 ) ) ;
if ( V_4 -> V_5 == NULL )
return - V_82 ;
V_74 = F_4 ( V_4 -> V_5 + V_83 ) ;
if ( memcmp ( & V_74 , L_1 , 4 ) != 0 ) {
F_58 ( & V_50 -> V_29 , L_2 , V_74 ) ;
return - V_84 ;
}
V_4 -> V_85 = F_4 ( V_4 -> V_5 + V_86 ) ;
if ( V_4 -> V_85 != 1 ) {
F_59 ( & V_50 -> V_29 , L_3 ,
V_4 -> V_85 ) ;
return - V_87 ;
}
V_4 -> V_2 . V_88 . V_89 = F_4 ( V_4 -> V_5 + V_90 ) ;
V_4 -> V_2 . V_88 . V_91 = F_4 ( V_4 -> V_5 + V_92 ) ;
F_3 ( V_93 , V_4 -> V_5 + V_94 ) ;
F_60 ( V_50 , V_4 ) ;
return F_61 ( & V_4 -> V_2 ) ;
}
static int F_62 ( struct V_71 * V_50 )
{
struct V_3 * V_4 = F_63 ( V_50 ) ;
F_64 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int F_65 ( const char * V_89 ,
const struct V_95 * V_96 )
{
int V_52 ;
struct V_72 V_97 [ 2 ] = {} ;
char * V_98 ;
long long int V_5 , V_42 ;
unsigned int V_23 ;
int V_99 , V_100 = 0 ;
struct V_71 * V_50 ;
V_42 = F_66 ( V_89 , & V_98 ) ;
V_99 = sscanf ( V_98 , L_4 ,
& V_5 , & V_23 , & V_100 ,
& V_101 , & V_100 ) ;
if ( V_99 < 2 || V_98 [ V_100 ] )
return - V_76 ;
V_97 [ 0 ] . V_31 = V_75 ;
V_97 [ 0 ] . V_77 = V_5 ;
V_97 [ 0 ] . V_102 = V_5 + V_42 - 1 ;
V_97 [ 1 ] . V_31 = V_103 ;
V_97 [ 1 ] . V_77 = V_97 [ 1 ] . V_102 = V_23 ;
if ( ! V_104 ) {
V_52 = F_67 ( & V_105 ) ;
if ( V_52 ) {
F_68 ( L_5 ) ;
return V_52 ;
}
V_104 = 1 ;
}
F_69 ( L_6 ,
V_101 ,
( unsigned long long ) V_97 [ 0 ] . V_77 ,
( unsigned long long ) V_97 [ 0 ] . V_102 ,
( int ) V_97 [ 1 ] . V_77 ) ;
V_50 = F_70 ( & V_105 ,
L_7 , V_101 ++ ,
V_97 , F_7 ( V_97 ) , NULL , 0 ) ;
if ( F_47 ( V_50 ) )
return F_48 ( V_50 ) ;
return 0 ;
}
static int F_71 ( struct V_89 * V_29 , void * V_106 )
{
char * V_107 = V_106 ;
unsigned int V_14 = strlen ( V_107 ) ;
struct V_71 * V_50 = F_72 ( V_29 ) ;
snprintf ( V_107 + V_14 , V_93 - V_14 , L_8 ,
V_50 -> V_72 [ 0 ] . V_102 - V_50 -> V_72 [ 0 ] . V_77 + 1ULL ,
( unsigned long long ) V_50 -> V_72 [ 0 ] . V_77 ,
( unsigned long long ) V_50 -> V_72 [ 1 ] . V_77 ,
V_50 -> V_88 ) ;
return 0 ;
}
static int F_73 ( char * V_107 , const struct V_95 * V_96 )
{
V_107 [ 0 ] = '\0' ;
F_74 ( & V_105 , V_107 ,
F_71 ) ;
return strlen ( V_107 ) + 1 ;
}
static int F_75 ( struct V_89 * V_29 ,
void * V_106 )
{
F_76 ( F_72 ( V_29 ) ) ;
return 0 ;
}
static void F_77 ( void )
{
if ( V_104 ) {
F_74 ( & V_105 , NULL ,
F_75 ) ;
F_78 ( & V_105 ) ;
V_104 = 0 ;
}
}
static void F_77 ( void )
{
}
static int T_5 F_79 ( void )
{
return F_80 ( & V_108 ) ;
}
static void T_6 F_81 ( void )
{
F_82 ( & V_108 ) ;
F_77 () ;
}
