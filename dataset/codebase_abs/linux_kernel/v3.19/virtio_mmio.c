static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0 , V_4 -> V_5 + V_6 ) ;
return F_4 ( V_4 -> V_5 + V_7 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_6 ( V_2 ) ;
F_7 ( ( V_8 ) V_2 -> V_9 != V_2 -> V_9 ) ;
F_3 ( 0 , V_4 -> V_5 + V_10 ) ;
F_3 ( V_2 -> V_9 , V_4 -> V_5 + V_11 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , unsigned V_12 ,
void * V_13 , unsigned V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 * V_15 = V_13 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ )
V_15 [ V_16 ] = F_9 ( V_4 -> V_5 + V_17 + V_12 + V_16 ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned V_12 ,
const void * V_13 , unsigned V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const T_2 * V_15 = V_13 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ )
F_11 ( V_15 [ V_16 ] , V_4 -> V_5 + V_17 + V_12 + V_16 ) ;
}
static T_2 F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_4 ( V_4 -> V_5 + V_18 ) & 0xff ;
}
static void F_13 ( struct V_1 * V_2 , T_2 V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_7 ( V_19 == 0 ) ;
F_3 ( V_19 , V_4 -> V_5 + V_18 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0 , V_4 -> V_5 + V_18 ) ;
}
static bool F_15 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = F_2 ( V_21 -> V_2 ) ;
F_3 ( V_21 -> V_22 , V_4 -> V_5 + V_23 ) ;
return true ;
}
static T_3 F_16 ( int V_24 , void * V_25 )
{
struct V_3 * V_4 = V_25 ;
struct V_26 * V_27 ;
unsigned long V_19 ;
unsigned long V_28 ;
T_3 V_29 = V_30 ;
V_19 = F_4 ( V_4 -> V_5 + V_31 ) ;
F_3 ( V_19 , V_4 -> V_5 + V_32 ) ;
if ( F_17 ( V_19 & V_33 ) ) {
F_18 ( & V_4 -> V_2 ) ;
V_29 = V_34 ;
}
if ( F_19 ( V_19 & V_35 ) ) {
F_20 ( & V_4 -> V_36 , V_28 ) ;
F_21 (info, &vm_dev->virtqueues, node)
V_29 |= F_22 ( V_24 , V_27 -> V_21 ) ;
F_23 ( & V_4 -> V_36 , V_28 ) ;
}
return V_29 ;
}
static void F_24 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = F_2 ( V_21 -> V_2 ) ;
struct V_26 * V_27 = V_21 -> V_37 ;
unsigned long V_28 , V_38 ;
unsigned int V_22 = V_21 -> V_22 ;
F_20 ( & V_4 -> V_36 , V_28 ) ;
F_25 ( & V_27 -> V_39 ) ;
F_23 ( & V_4 -> V_36 , V_28 ) ;
F_26 ( V_21 ) ;
F_3 ( V_22 , V_4 -> V_5 + V_40 ) ;
F_3 ( 0 , V_4 -> V_5 + V_41 ) ;
V_38 = F_27 ( F_28 ( V_27 -> V_42 , V_43 ) ) ;
F_29 ( V_27 -> V_44 , V_38 ) ;
F_30 ( V_27 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_20 * V_21 , * V_45 ;
F_32 (vq, n, &vdev->vqs, list)
F_24 ( V_21 ) ;
F_33 ( F_34 ( V_4 -> V_46 , 0 ) , V_4 ) ;
}
static struct V_20 * F_35 ( struct V_1 * V_2 , unsigned V_22 ,
void (* F_36)( struct V_20 * V_21 ) ,
const char * V_47 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_26 * V_27 ;
struct V_20 * V_21 ;
unsigned long V_28 , V_38 ;
int V_48 ;
if ( ! V_47 )
return NULL ;
F_3 ( V_22 , V_4 -> V_5 + V_40 ) ;
if ( F_4 ( V_4 -> V_5 + V_41 ) ) {
V_48 = - V_49 ;
goto V_50;
}
V_27 = F_37 ( sizeof( * V_27 ) , V_51 ) ;
if ( ! V_27 ) {
V_48 = - V_52 ;
goto V_53;
}
V_27 -> V_42 = F_4 ( V_4 -> V_5 + V_54 ) ;
if ( V_27 -> V_42 == 0 ) {
V_48 = - V_49 ;
goto V_55;
}
while ( 1 ) {
V_38 = F_27 ( F_28 ( V_27 -> V_42 ,
V_43 ) ) ;
if ( V_38 < V_43 * 2 ) {
V_48 = - V_52 ;
goto V_55;
}
V_27 -> V_44 = F_38 ( V_38 , V_51 | V_56 ) ;
if ( V_27 -> V_44 )
break;
V_27 -> V_42 /= 2 ;
}
F_3 ( V_27 -> V_42 , V_4 -> V_5 + V_57 ) ;
F_3 ( V_43 ,
V_4 -> V_5 + V_58 ) ;
F_3 ( F_39 ( V_27 -> V_44 ) >> V_59 ,
V_4 -> V_5 + V_41 ) ;
V_21 = F_40 ( V_22 , V_27 -> V_42 , V_43 , V_2 ,
true , V_27 -> V_44 , F_15 , F_36 , V_47 ) ;
if ( ! V_21 ) {
V_48 = - V_52 ;
goto V_60;
}
V_21 -> V_37 = V_27 ;
V_27 -> V_21 = V_21 ;
F_20 ( & V_4 -> V_36 , V_28 ) ;
F_41 ( & V_27 -> V_39 , & V_4 -> V_61 ) ;
F_23 ( & V_4 -> V_36 , V_28 ) ;
return V_21 ;
V_60:
F_3 ( 0 , V_4 -> V_5 + V_41 ) ;
F_29 ( V_27 -> V_44 , V_38 ) ;
V_55:
F_30 ( V_27 ) ;
V_53:
V_50:
return F_42 ( V_48 ) ;
}
static int F_43 ( struct V_1 * V_2 , unsigned V_62 ,
struct V_20 * V_63 [] ,
T_4 * V_64 [] ,
const char * V_65 [] )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_24 = F_34 ( V_4 -> V_46 , 0 ) ;
int V_16 , V_48 ;
V_48 = F_44 ( V_24 , F_16 , V_66 ,
F_45 ( & V_2 -> V_67 ) , V_4 ) ;
if ( V_48 )
return V_48 ;
for ( V_16 = 0 ; V_16 < V_62 ; ++ V_16 ) {
V_63 [ V_16 ] = F_35 ( V_2 , V_16 , V_64 [ V_16 ] , V_65 [ V_16 ] ) ;
if ( F_46 ( V_63 [ V_16 ] ) ) {
F_31 ( V_2 ) ;
return F_47 ( V_63 [ V_16 ] ) ;
}
}
return 0 ;
}
static const char * F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_46 -> V_47 ;
}
static int F_49 ( struct V_68 * V_46 )
{
struct V_3 * V_4 ;
struct V_69 * V_70 ;
unsigned long V_71 ;
V_70 = F_50 ( V_46 , V_72 , 0 ) ;
if ( ! V_70 )
return - V_73 ;
if ( ! F_51 ( & V_46 -> V_67 , V_70 -> V_74 ,
F_52 ( V_70 ) , V_46 -> V_47 ) )
return - V_75 ;
V_4 = F_53 ( & V_46 -> V_67 , sizeof( * V_4 ) , V_51 ) ;
if ( ! V_4 )
return - V_52 ;
V_4 -> V_2 . V_67 . V_76 = & V_46 -> V_67 ;
V_4 -> V_2 . V_77 = & V_78 ;
V_4 -> V_46 = V_46 ;
F_54 ( & V_4 -> V_61 ) ;
F_55 ( & V_4 -> V_36 ) ;
V_4 -> V_5 = F_56 ( & V_46 -> V_67 , V_70 -> V_74 , F_52 ( V_70 ) ) ;
if ( V_4 -> V_5 == NULL )
return - V_79 ;
V_71 = F_4 ( V_4 -> V_5 + V_80 ) ;
if ( V_71 != ( 'v' | 'i' << 8 | 'r' << 16 | 't' << 24 ) ) {
F_57 ( & V_46 -> V_67 , L_1 , V_71 ) ;
return - V_81 ;
}
V_4 -> V_82 = F_4 ( V_4 -> V_5 + V_83 ) ;
if ( V_4 -> V_82 != 1 ) {
F_58 ( & V_46 -> V_67 , L_2 ,
V_4 -> V_82 ) ;
return - V_84 ;
}
V_4 -> V_2 . V_85 . V_86 = F_4 ( V_4 -> V_5 + V_87 ) ;
V_4 -> V_2 . V_85 . V_88 = F_4 ( V_4 -> V_5 + V_89 ) ;
F_3 ( V_90 , V_4 -> V_5 + V_91 ) ;
F_59 ( V_46 , V_4 ) ;
return F_60 ( & V_4 -> V_2 ) ;
}
static int F_61 ( struct V_68 * V_46 )
{
struct V_3 * V_4 = F_62 ( V_46 ) ;
F_63 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int F_64 ( const char * V_86 ,
const struct V_92 * V_93 )
{
int V_48 ;
struct V_69 V_94 [ 2 ] = {} ;
char * V_95 ;
long long int V_5 , V_38 ;
unsigned int V_24 ;
int V_96 , V_97 = 0 ;
struct V_68 * V_46 ;
V_38 = F_65 ( V_86 , & V_95 ) ;
V_96 = sscanf ( V_95 , L_3 ,
& V_5 , & V_24 , & V_97 ,
& V_98 , & V_97 ) ;
if ( V_96 < 2 || V_95 [ V_97 ] )
return - V_73 ;
V_94 [ 0 ] . V_28 = V_72 ;
V_94 [ 0 ] . V_74 = V_5 ;
V_94 [ 0 ] . V_99 = V_5 + V_38 - 1 ;
V_94 [ 1 ] . V_28 = V_100 ;
V_94 [ 1 ] . V_74 = V_94 [ 1 ] . V_99 = V_24 ;
if ( ! V_101 ) {
V_48 = F_66 ( & V_102 ) ;
if ( V_48 ) {
F_67 ( L_4 ) ;
return V_48 ;
}
V_101 = 1 ;
}
F_68 ( L_5 ,
V_98 ,
( unsigned long long ) V_94 [ 0 ] . V_74 ,
( unsigned long long ) V_94 [ 0 ] . V_99 ,
( int ) V_94 [ 1 ] . V_74 ) ;
V_46 = F_69 ( & V_102 ,
L_6 , V_98 ++ ,
V_94 , F_70 ( V_94 ) , NULL , 0 ) ;
if ( F_46 ( V_46 ) )
return F_47 ( V_46 ) ;
return 0 ;
}
static int F_71 ( struct V_86 * V_67 , void * V_103 )
{
char * V_104 = V_103 ;
unsigned int V_14 = strlen ( V_104 ) ;
struct V_68 * V_46 = F_72 ( V_67 ) ;
snprintf ( V_104 + V_14 , V_90 - V_14 , L_7 ,
V_46 -> V_69 [ 0 ] . V_99 - V_46 -> V_69 [ 0 ] . V_74 + 1ULL ,
( unsigned long long ) V_46 -> V_69 [ 0 ] . V_74 ,
( unsigned long long ) V_46 -> V_69 [ 1 ] . V_74 ,
V_46 -> V_85 ) ;
return 0 ;
}
static int F_73 ( char * V_104 , const struct V_92 * V_93 )
{
V_104 [ 0 ] = '\0' ;
F_74 ( & V_102 , V_104 ,
F_71 ) ;
return strlen ( V_104 ) + 1 ;
}
static int F_75 ( struct V_86 * V_67 ,
void * V_103 )
{
F_76 ( F_72 ( V_67 ) ) ;
return 0 ;
}
static void F_77 ( void )
{
if ( V_101 ) {
F_74 ( & V_102 , NULL ,
F_75 ) ;
F_78 ( & V_102 ) ;
V_101 = 0 ;
}
}
static void F_77 ( void )
{
}
static int T_5 F_79 ( void )
{
return F_80 ( & V_105 ) ;
}
static void T_6 F_81 ( void )
{
F_82 ( & V_105 ) ;
F_77 () ;
}
