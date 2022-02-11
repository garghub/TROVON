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
static bool F_16 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_20 -> V_2 ) ;
F_3 ( V_20 -> V_21 , V_4 -> V_5 + V_22 ) ;
return true ;
}
static T_3 F_17 ( int V_23 , void * V_24 )
{
struct V_3 * V_4 = V_24 ;
struct V_25 * V_26 ;
unsigned long V_18 ;
unsigned long V_27 ;
T_3 V_28 = V_29 ;
V_18 = F_4 ( V_4 -> V_5 + V_30 ) ;
F_3 ( V_18 , V_4 -> V_5 + V_31 ) ;
if ( F_18 ( V_18 & V_32 ) ) {
F_19 ( & V_4 -> V_2 ) ;
V_28 = V_33 ;
}
if ( F_20 ( V_18 & V_34 ) ) {
F_21 ( & V_4 -> V_35 , V_27 ) ;
F_22 (info, &vm_dev->virtqueues, node)
V_28 |= F_23 ( V_23 , V_26 -> V_20 ) ;
F_24 ( & V_4 -> V_35 , V_27 ) ;
}
return V_28 ;
}
static void F_25 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_2 ( V_20 -> V_2 ) ;
struct V_25 * V_26 = V_20 -> V_36 ;
unsigned long V_27 , V_37 ;
unsigned int V_21 = V_20 -> V_21 ;
F_21 ( & V_4 -> V_35 , V_27 ) ;
F_26 ( & V_26 -> V_38 ) ;
F_24 ( & V_4 -> V_35 , V_27 ) ;
F_27 ( V_20 ) ;
F_3 ( V_21 , V_4 -> V_5 + V_39 ) ;
F_3 ( 0 , V_4 -> V_5 + V_40 ) ;
V_37 = F_28 ( F_29 ( V_26 -> V_41 , V_42 ) ) ;
F_30 ( V_26 -> V_43 , V_37 ) ;
F_31 ( V_26 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_19 * V_20 , * V_44 ;
F_33 (vq, n, &vdev->vqs, list)
F_25 ( V_20 ) ;
F_34 ( F_35 ( V_4 -> V_45 , 0 ) , V_4 ) ;
}
static struct V_19 * F_36 ( struct V_1 * V_2 , unsigned V_21 ,
void (* F_37)( struct V_19 * V_20 ) ,
const char * V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_25 * V_26 ;
struct V_19 * V_20 ;
unsigned long V_27 , V_37 ;
int V_47 ;
if ( ! V_46 )
return NULL ;
F_3 ( V_21 , V_4 -> V_5 + V_39 ) ;
if ( F_4 ( V_4 -> V_5 + V_40 ) ) {
V_47 = - V_48 ;
goto V_49;
}
V_26 = F_38 ( sizeof( * V_26 ) , V_50 ) ;
if ( ! V_26 ) {
V_47 = - V_51 ;
goto V_52;
}
V_26 -> V_41 = F_4 ( V_4 -> V_5 + V_53 ) ;
if ( V_26 -> V_41 == 0 ) {
V_47 = - V_48 ;
goto V_54;
}
while ( 1 ) {
V_37 = F_28 ( F_29 ( V_26 -> V_41 ,
V_42 ) ) ;
if ( V_37 < V_42 * 2 ) {
V_47 = - V_51 ;
goto V_54;
}
V_26 -> V_43 = F_39 ( V_37 , V_50 | V_55 ) ;
if ( V_26 -> V_43 )
break;
V_26 -> V_41 /= 2 ;
}
F_3 ( V_26 -> V_41 , V_4 -> V_5 + V_56 ) ;
F_3 ( V_42 ,
V_4 -> V_5 + V_57 ) ;
F_3 ( F_40 ( V_26 -> V_43 ) >> V_58 ,
V_4 -> V_5 + V_40 ) ;
V_20 = F_41 ( V_21 , V_26 -> V_41 , V_42 , V_2 ,
true , V_26 -> V_43 , F_16 , F_37 , V_46 ) ;
if ( ! V_20 ) {
V_47 = - V_51 ;
goto V_59;
}
V_20 -> V_36 = V_26 ;
V_26 -> V_20 = V_20 ;
F_21 ( & V_4 -> V_35 , V_27 ) ;
F_42 ( & V_26 -> V_38 , & V_4 -> V_60 ) ;
F_24 ( & V_4 -> V_35 , V_27 ) ;
return V_20 ;
V_59:
F_3 ( 0 , V_4 -> V_5 + V_40 ) ;
F_30 ( V_26 -> V_43 , V_37 ) ;
V_54:
F_31 ( V_26 ) ;
V_52:
V_49:
return F_43 ( V_47 ) ;
}
static int F_44 ( struct V_1 * V_2 , unsigned V_61 ,
struct V_19 * V_62 [] ,
T_4 * V_63 [] ,
const char * V_64 [] )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_23 = F_35 ( V_4 -> V_45 , 0 ) ;
int V_8 , V_47 ;
V_47 = F_45 ( V_23 , F_17 , V_65 ,
F_46 ( & V_2 -> V_66 ) , V_4 ) ;
if ( V_47 )
return V_47 ;
for ( V_8 = 0 ; V_8 < V_61 ; ++ V_8 ) {
V_62 [ V_8 ] = F_36 ( V_2 , V_8 , V_63 [ V_8 ] , V_64 [ V_8 ] ) ;
if ( F_47 ( V_62 [ V_8 ] ) ) {
F_32 ( V_2 ) ;
return F_48 ( V_62 [ V_8 ] ) ;
}
}
return 0 ;
}
static const char * F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_45 -> V_46 ;
}
static int F_50 ( struct V_67 * V_45 )
{
struct V_3 * V_4 ;
struct V_68 * V_69 ;
unsigned long V_70 ;
V_69 = F_51 ( V_45 , V_71 , 0 ) ;
if ( ! V_69 )
return - V_72 ;
if ( ! F_52 ( & V_45 -> V_66 , V_69 -> V_73 ,
F_53 ( V_69 ) , V_45 -> V_46 ) )
return - V_74 ;
V_4 = F_54 ( & V_45 -> V_66 , sizeof( * V_4 ) , V_50 ) ;
if ( ! V_4 )
return - V_51 ;
V_4 -> V_2 . V_66 . V_75 = & V_45 -> V_66 ;
V_4 -> V_2 . V_76 = & V_77 ;
V_4 -> V_45 = V_45 ;
F_55 ( & V_4 -> V_60 ) ;
F_56 ( & V_4 -> V_35 ) ;
V_4 -> V_5 = F_57 ( & V_45 -> V_66 , V_69 -> V_73 , F_53 ( V_69 ) ) ;
if ( V_4 -> V_5 == NULL )
return - V_78 ;
V_70 = F_4 ( V_4 -> V_5 + V_79 ) ;
if ( V_70 != ( 'v' | 'i' << 8 | 'r' << 16 | 't' << 24 ) ) {
F_58 ( & V_45 -> V_66 , L_1 , V_70 ) ;
return - V_80 ;
}
V_4 -> V_81 = F_4 ( V_4 -> V_5 + V_82 ) ;
if ( V_4 -> V_81 != 1 ) {
F_59 ( & V_45 -> V_66 , L_2 ,
V_4 -> V_81 ) ;
return - V_83 ;
}
V_4 -> V_2 . V_84 . V_85 = F_4 ( V_4 -> V_5 + V_86 ) ;
V_4 -> V_2 . V_84 . V_87 = F_4 ( V_4 -> V_5 + V_88 ) ;
F_3 ( V_89 , V_4 -> V_5 + V_90 ) ;
F_60 ( V_45 , V_4 ) ;
return F_61 ( & V_4 -> V_2 ) ;
}
static int F_62 ( struct V_67 * V_45 )
{
struct V_3 * V_4 = F_63 ( V_45 ) ;
F_64 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int F_65 ( const char * V_85 ,
const struct V_91 * V_92 )
{
int V_47 ;
struct V_68 V_93 [ 2 ] = {} ;
char * V_94 ;
long long int V_5 , V_37 ;
unsigned int V_23 ;
int V_95 , V_96 = 0 ;
struct V_67 * V_45 ;
V_37 = F_66 ( V_85 , & V_94 ) ;
V_95 = sscanf ( V_94 , L_3 ,
& V_5 , & V_23 , & V_96 ,
& V_97 , & V_96 ) ;
if ( V_95 < 2 || V_94 [ V_96 ] )
return - V_72 ;
V_93 [ 0 ] . V_27 = V_71 ;
V_93 [ 0 ] . V_73 = V_5 ;
V_93 [ 0 ] . V_98 = V_5 + V_37 - 1 ;
V_93 [ 1 ] . V_27 = V_99 ;
V_93 [ 1 ] . V_73 = V_93 [ 1 ] . V_98 = V_23 ;
if ( ! V_100 ) {
V_47 = F_67 ( & V_101 ) ;
if ( V_47 ) {
F_68 ( L_4 ) ;
return V_47 ;
}
V_100 = 1 ;
}
F_69 ( L_5 ,
V_97 ,
( unsigned long long ) V_93 [ 0 ] . V_73 ,
( unsigned long long ) V_93 [ 0 ] . V_98 ,
( int ) V_93 [ 1 ] . V_73 ) ;
V_45 = F_70 ( & V_101 ,
L_6 , V_97 ++ ,
V_93 , F_7 ( V_93 ) , NULL , 0 ) ;
if ( F_47 ( V_45 ) )
return F_48 ( V_45 ) ;
return 0 ;
}
static int F_71 ( struct V_85 * V_66 , void * V_102 )
{
char * V_103 = V_102 ;
unsigned int V_14 = strlen ( V_103 ) ;
struct V_67 * V_45 = F_72 ( V_66 ) ;
snprintf ( V_103 + V_14 , V_89 - V_14 , L_7 ,
V_45 -> V_68 [ 0 ] . V_98 - V_45 -> V_68 [ 0 ] . V_73 + 1ULL ,
( unsigned long long ) V_45 -> V_68 [ 0 ] . V_73 ,
( unsigned long long ) V_45 -> V_68 [ 1 ] . V_73 ,
V_45 -> V_84 ) ;
return 0 ;
}
static int F_73 ( char * V_103 , const struct V_91 * V_92 )
{
V_103 [ 0 ] = '\0' ;
F_74 ( & V_101 , V_103 ,
F_71 ) ;
return strlen ( V_103 ) + 1 ;
}
static int F_75 ( struct V_85 * V_66 ,
void * V_102 )
{
F_76 ( F_72 ( V_66 ) ) ;
return 0 ;
}
static void F_77 ( void )
{
if ( V_100 ) {
F_74 ( & V_101 , NULL ,
F_75 ) ;
F_78 ( & V_101 ) ;
V_100 = 0 ;
}
}
static void F_77 ( void )
{
}
static int T_5 F_79 ( void )
{
return F_80 ( & V_104 ) ;
}
static void T_6 F_81 ( void )
{
F_82 ( & V_104 ) ;
F_77 () ;
}
