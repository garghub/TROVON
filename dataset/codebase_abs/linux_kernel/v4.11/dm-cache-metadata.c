static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_7 -> V_8 = F_3 ( F_4 ( V_4 ) ) ;
V_7 -> V_9 = F_5 ( F_6 ( & V_7 -> V_10 ,
V_5 - sizeof( V_11 ) ,
V_12 ) ) ;
}
static int F_7 ( struct V_6 * V_7 )
{
T_2 V_13 = F_8 ( V_7 -> V_14 ) ;
if ( V_13 < V_15 || V_13 > V_16 ) {
F_9 ( L_1 ,
V_13 , V_15 , V_16 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_11 V_18 ;
if ( F_4 ( V_4 ) != F_11 ( V_7 -> V_8 ) ) {
F_9 ( L_2 ,
F_11 ( V_7 -> V_8 ) ,
( unsigned long long ) F_4 ( V_4 ) ) ;
return - V_19 ;
}
if ( F_11 ( V_7 -> V_20 ) != V_21 ) {
F_9 ( L_3 ,
F_11 ( V_7 -> V_20 ) ,
( unsigned long long ) V_21 ) ;
return - V_22 ;
}
V_18 = F_5 ( F_6 ( & V_7 -> V_10 ,
V_5 - sizeof( V_11 ) ,
V_12 ) ) ;
if ( V_18 != V_7 -> V_9 ) {
F_9 ( L_4 ,
F_8 ( V_18 ) , F_8 ( V_7 -> V_9 ) ) ;
return - V_22 ;
}
return F_7 ( V_7 ) ;
}
static int F_12 ( struct V_23 * V_24 ,
struct V_3 * * V_25 )
{
return F_13 ( V_24 -> V_26 , V_27 ,
& V_28 , V_25 ) ;
}
static int F_14 ( struct V_23 * V_24 ,
struct V_3 * * V_25 )
{
return F_15 ( V_24 -> V_26 , V_27 ,
& V_28 , V_25 ) ;
}
static int F_16 ( struct V_23 * V_24 ,
struct V_3 * * V_25 )
{
return F_17 ( V_24 -> V_26 , V_27 ,
& V_28 , V_25 ) ;
}
static int F_18 ( struct V_29 * V_26 , bool * V_30 )
{
int V_31 ;
unsigned V_32 ;
struct V_3 * V_4 ;
T_3 * V_33 , V_34 = F_3 ( 0 ) ;
unsigned V_5 = F_19 ( V_26 ) / sizeof( T_3 ) ;
V_31 = F_13 ( V_26 , V_27 , NULL , & V_4 ) ;
if ( V_31 )
return V_31 ;
V_33 = F_2 ( V_4 ) ;
* V_30 = true ;
for ( V_32 = 0 ; V_32 < V_5 ; V_32 ++ ) {
if ( V_33 [ V_32 ] != V_34 ) {
* V_30 = false ;
break;
}
}
F_20 ( V_4 ) ;
return 0 ;
}
static void F_21 ( struct V_23 * V_24 )
{
struct V_35 V_36 ;
V_36 . V_37 = NULL ;
V_36 . V_38 = sizeof( T_3 ) ;
V_36 . V_39 = NULL ;
V_36 . V_40 = NULL ;
V_36 . V_41 = NULL ;
F_22 ( & V_24 -> V_42 , V_24 -> V_43 , & V_36 ) ;
if ( V_24 -> V_44 ) {
V_36 . V_38 = sizeof( V_11 ) ;
F_22 ( & V_24 -> V_45 , V_24 -> V_43 , & V_36 ) ;
}
}
static int F_23 ( struct V_23 * V_24 )
{
int V_31 ;
T_1 V_46 ;
V_31 = F_24 ( V_24 -> V_47 , & V_46 ) ;
if ( V_31 < 0 )
return V_31 ;
return F_25 ( V_24 -> V_47 , & V_24 -> V_48 ,
V_46 ) ;
}
static void F_26 ( struct V_23 * V_24 ,
struct V_6 * V_7 )
{
memcpy ( & V_7 -> V_48 ,
& V_24 -> V_48 ,
sizeof( V_24 -> V_48 ) ) ;
}
static bool F_27 ( struct V_23 * V_24 )
{
return V_24 -> V_14 >= 2 ;
}
static int F_28 ( struct V_23 * V_24 )
{
int V_31 ;
struct V_3 * V_25 ;
struct V_6 * V_7 ;
T_4 V_49 = F_29 ( V_24 -> V_50 -> V_51 ) >> V_52 ;
if ( V_49 > V_53 )
V_49 = V_53 ;
V_31 = F_30 ( V_24 -> V_43 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_23 ( V_24 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_14 ( V_24 , & V_25 ) ;
if ( V_31 )
return V_31 ;
V_7 = F_2 ( V_25 ) ;
V_7 -> V_10 = 0 ;
memset ( V_7 -> V_54 , 0 , sizeof( V_7 -> V_54 ) ) ;
V_7 -> V_20 = F_3 ( V_21 ) ;
V_7 -> V_14 = F_5 ( V_24 -> V_14 ) ;
memset ( V_7 -> V_55 , 0 , sizeof( V_7 -> V_55 ) ) ;
memset ( V_7 -> V_56 , 0 , sizeof( V_7 -> V_56 ) ) ;
V_7 -> V_44 = 0 ;
F_26 ( V_24 , V_7 ) ;
V_7 -> V_57 = F_3 ( V_24 -> V_58 ) ;
V_7 -> V_59 = F_3 ( V_24 -> V_59 ) ;
V_7 -> V_60 = F_3 ( V_24 -> V_60 ) ;
V_7 -> V_61 = F_3 ( V_24 -> V_61 ) ;
V_7 -> V_62 = F_3 ( F_31 ( V_24 -> V_62 ) ) ;
V_7 -> V_63 = F_5 ( V_64 ) ;
V_7 -> V_65 = F_5 ( V_24 -> V_65 ) ;
V_7 -> V_66 = F_5 ( 0 ) ;
V_7 -> V_67 = F_5 ( 0 ) ;
V_7 -> V_68 = F_5 ( 0 ) ;
V_7 -> V_69 = F_5 ( 0 ) ;
V_7 -> V_70 = F_5 ( 0 ) ;
if ( F_27 ( V_24 ) )
V_7 -> V_71 = F_3 ( V_24 -> V_71 ) ;
return F_32 ( V_24 -> V_43 , V_25 ) ;
}
static int F_33 ( struct V_23 * V_24 )
{
int V_31 ;
V_31 = F_34 ( V_24 -> V_26 , V_27 ,
& V_24 -> V_43 , & V_24 -> V_47 ) ;
if ( V_31 < 0 ) {
F_9 ( L_5 ) ;
return V_31 ;
}
F_21 ( V_24 ) ;
V_31 = F_35 ( & V_24 -> V_42 , & V_24 -> V_58 ) ;
if ( V_31 < 0 )
goto V_72;
if ( F_27 ( V_24 ) ) {
F_36 ( V_24 -> V_43 , & V_24 -> V_73 ) ;
V_31 = F_37 ( & V_24 -> V_73 , & V_24 -> V_71 ) ;
if ( V_31 < 0 )
goto V_72;
}
F_36 ( V_24 -> V_43 , & V_24 -> V_74 ) ;
V_31 = F_37 ( & V_24 -> V_74 , & V_24 -> V_60 ) ;
if ( V_31 < 0 )
goto V_72;
V_24 -> V_61 = 0 ;
V_24 -> V_62 = 0 ;
V_31 = F_28 ( V_24 ) ;
if ( V_31 )
goto V_72;
V_24 -> V_75 = true ;
return 0 ;
V_72:
F_38 ( V_24 -> V_43 ) ;
F_39 ( V_24 -> V_47 ) ;
return V_31 ;
}
static int F_40 ( struct V_6 * V_7 ,
struct V_23 * V_24 )
{
T_2 V_76 , V_77 ;
V_76 = F_8 ( V_7 -> V_76 ) ;
V_77 = V_76 & ~ V_78 ;
if ( V_77 ) {
F_9 ( L_6 ,
( unsigned long ) V_77 ) ;
return - V_17 ;
}
if ( F_41 ( V_24 -> V_50 -> V_79 ) )
return 0 ;
V_77 = F_8 ( V_7 -> V_80 ) & ~ V_81 ;
if ( V_77 ) {
F_9 ( L_7 ,
( unsigned long ) V_77 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_42 ( struct V_23 * V_24 )
{
int V_31 ;
struct V_3 * V_25 ;
struct V_6 * V_7 ;
unsigned long V_82 ;
V_31 = F_12 ( V_24 , & V_25 ) ;
if ( V_31 < 0 ) {
F_9 ( L_8 ) ;
return V_31 ;
}
V_7 = F_2 ( V_25 ) ;
if ( F_8 ( V_7 -> V_65 ) != V_24 -> V_65 ) {
F_9 ( L_9 ,
F_8 ( V_7 -> V_65 ) ,
( unsigned long long ) V_24 -> V_65 ) ;
V_31 = - V_17 ;
goto V_72;
}
V_31 = F_40 ( V_7 , V_24 ) ;
if ( V_31 < 0 )
goto V_72;
V_31 = F_43 ( V_24 -> V_26 , V_27 ,
V_7 -> V_48 ,
sizeof( V_7 -> V_48 ) ,
& V_24 -> V_43 , & V_24 -> V_47 ) ;
if ( V_31 < 0 ) {
F_9 ( L_10 ) ;
goto V_72;
}
F_21 ( V_24 ) ;
F_36 ( V_24 -> V_43 , & V_24 -> V_73 ) ;
F_36 ( V_24 -> V_43 , & V_24 -> V_74 ) ;
V_82 = F_8 ( V_7 -> V_10 ) ;
V_24 -> V_75 = F_44 ( V_83 , & V_82 ) ;
F_20 ( V_25 ) ;
return 0 ;
V_72:
F_20 ( V_25 ) ;
return V_31 ;
}
static int F_45 ( struct V_23 * V_24 ,
bool V_84 )
{
int V_31 ;
bool V_85 = false ;
V_31 = F_18 ( V_24 -> V_26 , & V_85 ) ;
if ( V_31 )
return V_31 ;
if ( V_85 )
return V_84 ? F_33 ( V_24 ) : - V_86 ;
return F_42 ( V_24 ) ;
}
static int F_46 ( struct V_23 * V_24 ,
bool V_87 )
{
int V_31 ;
V_24 -> V_26 = F_47 ( V_24 -> V_50 , V_64 << V_52 ,
V_88 ,
V_89 ) ;
if ( F_48 ( V_24 -> V_26 ) ) {
F_9 ( L_11 ) ;
return F_49 ( V_24 -> V_26 ) ;
}
V_31 = F_45 ( V_24 , V_87 ) ;
if ( V_31 )
F_50 ( V_24 -> V_26 ) ;
return V_31 ;
}
static void F_51 ( struct V_23 * V_24 )
{
F_39 ( V_24 -> V_47 ) ;
F_38 ( V_24 -> V_43 ) ;
F_50 ( V_24 -> V_26 ) ;
}
static void F_52 ( struct V_6 * V_7 ,
T_5 V_90 )
{
T_2 V_82 = V_90 ( F_8 ( V_7 -> V_10 ) ) ;
V_7 -> V_10 = F_5 ( V_82 ) ;
}
static unsigned long F_53 ( unsigned long V_10 )
{
F_54 ( V_83 , & V_10 ) ;
return V_10 ;
}
static unsigned long F_55 ( unsigned long V_10 )
{
F_56 ( V_83 , & V_10 ) ;
return V_10 ;
}
static void F_57 ( struct V_23 * V_24 ,
struct V_6 * V_7 )
{
V_24 -> V_14 = F_8 ( V_7 -> V_14 ) ;
V_24 -> V_10 = F_8 ( V_7 -> V_10 ) ;
V_24 -> V_58 = F_11 ( V_7 -> V_57 ) ;
V_24 -> V_59 = F_11 ( V_7 -> V_59 ) ;
V_24 -> V_60 = F_11 ( V_7 -> V_60 ) ;
V_24 -> V_61 = F_11 ( V_7 -> V_61 ) ;
V_24 -> V_62 = F_58 ( F_11 ( V_7 -> V_62 ) ) ;
V_24 -> V_65 = F_8 ( V_7 -> V_65 ) ;
V_24 -> V_66 = F_59 ( F_8 ( V_7 -> V_66 ) ) ;
strncpy ( V_24 -> V_55 , V_7 -> V_55 , sizeof( V_24 -> V_55 ) ) ;
V_24 -> V_56 [ 0 ] = F_8 ( V_7 -> V_56 [ 0 ] ) ;
V_24 -> V_56 [ 1 ] = F_8 ( V_7 -> V_56 [ 1 ] ) ;
V_24 -> V_56 [ 2 ] = F_8 ( V_7 -> V_56 [ 2 ] ) ;
V_24 -> V_44 = F_8 ( V_7 -> V_44 ) ;
V_24 -> V_91 . V_67 = F_8 ( V_7 -> V_67 ) ;
V_24 -> V_91 . V_68 = F_8 ( V_7 -> V_68 ) ;
V_24 -> V_91 . V_69 = F_8 ( V_7 -> V_69 ) ;
V_24 -> V_91 . V_70 = F_8 ( V_7 -> V_70 ) ;
if ( F_27 ( V_24 ) )
V_24 -> V_71 = F_11 ( V_7 -> V_71 ) ;
V_24 -> V_92 = false ;
}
static int F_60 ( struct V_23 * V_24 ,
T_5 V_90 )
{
int V_31 ;
struct V_6 * V_7 ;
struct V_3 * V_25 ;
V_31 = F_16 ( V_24 , & V_25 ) ;
if ( V_31 )
return V_31 ;
V_7 = F_2 ( V_25 ) ;
F_52 ( V_7 , V_90 ) ;
F_57 ( V_24 , V_7 ) ;
F_20 ( V_25 ) ;
return F_61 ( V_24 -> V_26 ) ;
}
static int F_62 ( struct V_23 * V_24 )
{
int V_31 ;
struct V_6 * V_7 ;
struct V_3 * V_25 ;
V_31 = F_12 ( V_24 , & V_25 ) ;
if ( V_31 )
return V_31 ;
V_7 = F_2 ( V_25 ) ;
F_57 ( V_24 , V_7 ) ;
F_20 ( V_25 ) ;
return 0 ;
}
static int F_63 ( struct V_23 * V_24 ,
T_5 V_90 )
{
int V_31 ;
struct V_6 * V_7 ;
struct V_3 * V_25 ;
F_64 ( sizeof( struct V_6 ) > 512 ) ;
if ( F_27 ( V_24 ) ) {
V_31 = F_65 ( & V_24 -> V_73 , V_24 -> V_71 ,
& V_24 -> V_71 ) ;
if ( V_31 )
return V_31 ;
}
V_31 = F_65 ( & V_24 -> V_74 , V_24 -> V_60 ,
& V_24 -> V_60 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_30 ( V_24 -> V_43 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_23 ( V_24 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_16 ( V_24 , & V_25 ) ;
if ( V_31 )
return V_31 ;
V_7 = F_2 ( V_25 ) ;
V_7 -> V_10 = F_5 ( V_24 -> V_10 ) ;
if ( V_90 )
F_52 ( V_7 , V_90 ) ;
V_7 -> V_57 = F_3 ( V_24 -> V_58 ) ;
if ( F_27 ( V_24 ) )
V_7 -> V_71 = F_3 ( V_24 -> V_71 ) ;
V_7 -> V_59 = F_3 ( V_24 -> V_59 ) ;
V_7 -> V_60 = F_3 ( V_24 -> V_60 ) ;
V_7 -> V_61 = F_3 ( V_24 -> V_61 ) ;
V_7 -> V_62 = F_3 ( F_31 ( V_24 -> V_62 ) ) ;
V_7 -> V_66 = F_5 ( F_66 ( V_24 -> V_66 ) ) ;
strncpy ( V_7 -> V_55 , V_24 -> V_55 , sizeof( V_7 -> V_55 ) ) ;
V_7 -> V_56 [ 0 ] = F_5 ( V_24 -> V_56 [ 0 ] ) ;
V_7 -> V_56 [ 1 ] = F_5 ( V_24 -> V_56 [ 1 ] ) ;
V_7 -> V_56 [ 2 ] = F_5 ( V_24 -> V_56 [ 2 ] ) ;
V_7 -> V_67 = F_5 ( V_24 -> V_91 . V_67 ) ;
V_7 -> V_68 = F_5 ( V_24 -> V_91 . V_68 ) ;
V_7 -> V_69 = F_5 ( V_24 -> V_91 . V_69 ) ;
V_7 -> V_70 = F_5 ( V_24 -> V_91 . V_70 ) ;
F_26 ( V_24 , V_7 ) ;
return F_32 ( V_24 -> V_43 , V_25 ) ;
}
static T_3 F_67 ( T_6 V_93 , unsigned V_10 )
{
T_7 V_94 = F_68 ( V_93 ) ;
V_94 <<= 16 ;
V_94 = V_94 | ( V_10 & V_95 ) ;
return F_3 ( V_94 ) ;
}
static void F_69 ( T_3 V_96 , T_6 * V_93 , unsigned * V_10 )
{
T_7 V_94 = F_11 ( V_96 ) ;
T_7 V_4 = V_94 >> 16 ;
* V_93 = F_70 ( V_4 ) ;
* V_10 = V_94 & V_95 ;
}
static struct V_23 * F_71 ( struct V_97 * V_50 ,
T_4 V_65 ,
bool V_87 ,
T_1 V_44 ,
unsigned V_13 )
{
int V_31 ;
struct V_23 * V_24 ;
V_24 = F_72 ( sizeof( * V_24 ) , V_98 ) ;
if ( ! V_24 ) {
F_9 ( L_12 ) ;
return F_73 ( - V_99 ) ;
}
V_24 -> V_14 = V_13 ;
F_74 ( & V_24 -> V_100 , 1 ) ;
F_75 ( & V_24 -> V_101 ) ;
V_24 -> V_50 = V_50 ;
V_24 -> V_65 = V_65 ;
V_24 -> V_66 = 0 ;
V_24 -> V_44 = V_44 ;
V_24 -> V_92 = true ;
V_24 -> V_102 = false ;
V_31 = F_46 ( V_24 , V_87 ) ;
if ( V_31 ) {
F_76 ( V_24 ) ;
return F_73 ( V_31 ) ;
}
V_31 = F_60 ( V_24 , F_55 ) ;
if ( V_31 < 0 ) {
F_77 ( V_24 ) ;
return F_73 ( V_31 ) ;
}
return V_24 ;
}
static struct V_23 * F_78 ( struct V_97 * V_50 )
{
struct V_23 * V_24 ;
F_79 (cmd, &table, list)
if ( V_24 -> V_50 == V_50 ) {
F_80 ( & V_24 -> V_100 ) ;
return V_24 ;
}
return NULL ;
}
static struct V_23 * F_81 ( struct V_97 * V_50 ,
T_4 V_65 ,
bool V_87 ,
T_1 V_44 ,
unsigned V_13 )
{
struct V_23 * V_24 , * V_103 ;
F_82 ( & V_104 ) ;
V_24 = F_78 ( V_50 ) ;
F_83 ( & V_104 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_71 ( V_50 , V_65 , V_87 ,
V_44 , V_13 ) ;
if ( ! F_48 ( V_24 ) ) {
F_82 ( & V_104 ) ;
V_103 = F_78 ( V_50 ) ;
if ( V_103 ) {
F_83 ( & V_104 ) ;
F_51 ( V_24 ) ;
F_76 ( V_24 ) ;
return V_103 ;
}
F_84 ( & V_24 -> V_105 , & V_106 ) ;
F_83 ( & V_104 ) ;
}
return V_24 ;
}
static bool F_85 ( struct V_23 * V_24 , T_4 V_65 )
{
if ( V_24 -> V_65 != V_65 ) {
F_9 ( L_13 ,
( unsigned long long ) V_65 ,
( unsigned long long ) V_24 -> V_65 ) ;
return false ;
}
return true ;
}
struct V_23 * F_86 ( struct V_97 * V_50 ,
T_4 V_65 ,
bool V_87 ,
T_1 V_44 ,
unsigned V_13 )
{
struct V_23 * V_24 = F_81 ( V_50 , V_65 , V_87 ,
V_44 , V_13 ) ;
if ( ! F_48 ( V_24 ) && ! F_85 ( V_24 , V_65 ) ) {
F_77 ( V_24 ) ;
return F_73 ( - V_17 ) ;
}
return V_24 ;
}
void F_77 ( struct V_23 * V_24 )
{
if ( F_87 ( & V_24 -> V_100 ) ) {
F_82 ( & V_104 ) ;
F_88 ( & V_24 -> V_105 ) ;
F_83 ( & V_104 ) ;
if ( ! V_24 -> V_102 )
F_51 ( V_24 ) ;
F_76 ( V_24 ) ;
}
}
static int F_89 ( struct V_23 * V_24 , T_8 V_4 ,
bool * V_30 )
{
int V_31 ;
T_3 V_94 ;
T_6 V_107 ;
unsigned V_10 ;
V_31 = F_90 ( & V_24 -> V_42 , V_24 -> V_58 , F_66 ( V_4 ) , & V_94 ) ;
if ( V_31 )
return V_31 ;
F_69 ( V_94 , & V_107 , & V_10 ) ;
* V_30 = ! ( ( V_10 & V_108 ) && ( V_10 & V_109 ) ) ;
return 0 ;
}
static int F_91 ( struct V_23 * V_24 ,
T_8 V_110 , T_8 V_111 ,
bool * V_30 )
{
int V_31 ;
* V_30 = true ;
while ( V_110 != V_111 ) {
V_31 = F_89 ( V_24 , V_110 , V_30 ) ;
if ( V_31 ) {
F_9 ( L_14 ) ;
return V_31 ;
}
if ( ! * V_30 ) {
F_9 ( L_15 ,
( unsigned long long ) F_66 ( V_110 ) ) ;
return 0 ;
}
V_110 = F_59 ( F_66 ( V_110 ) + 1 ) ;
}
return 0 ;
}
static int F_92 ( struct V_23 * V_24 ,
T_8 V_110 , T_8 V_111 ,
bool * V_30 )
{
int V_31 ;
bool V_112 ;
* V_30 = true ;
V_31 = F_93 ( & V_24 -> V_73 , V_24 -> V_71 ,
F_66 ( V_24 -> V_66 ) , & V_24 -> V_113 ) ;
if ( V_31 ) {
F_9 ( L_16 , V_114 ) ;
return V_31 ;
}
V_31 = F_94 ( & V_24 -> V_113 , F_66 ( V_110 ) ) ;
if ( V_31 ) {
F_9 ( L_17 , V_114 ) ;
F_95 ( & V_24 -> V_113 ) ;
return V_31 ;
}
while ( V_110 != V_111 ) {
V_112 = F_96 ( & V_24 -> V_113 ) ;
if ( V_112 ) {
F_9 ( L_18 , V_114 ,
( unsigned long long ) F_66 ( V_110 ) ) ;
F_95 ( & V_24 -> V_113 ) ;
* V_30 = false ;
return 0 ;
}
V_110 = F_59 ( F_66 ( V_110 ) + 1 ) ;
if ( V_110 == V_111 )
break;
V_31 = F_97 ( & V_24 -> V_113 ) ;
if ( V_31 ) {
F_9 ( L_19 , V_114 ) ;
F_95 ( & V_24 -> V_113 ) ;
return V_31 ;
}
}
F_95 ( & V_24 -> V_113 ) ;
return 0 ;
}
static int F_98 ( struct V_23 * V_24 ,
T_8 V_110 , T_8 V_111 ,
bool * V_30 )
{
if ( F_27 ( V_24 ) )
return F_92 ( V_24 , V_110 , V_111 , V_30 ) ;
else
return F_91 ( V_24 , V_110 , V_111 , V_30 ) ;
}
static bool F_99 ( struct V_23 * V_24 )
{
F_100 ( & V_24 -> V_101 ) ;
if ( V_24 -> V_102 || F_101 ( V_24 -> V_26 ) ) {
F_102 ( & V_24 -> V_101 ) ;
return false ;
}
return true ;
}
static bool F_103 ( struct V_23 * V_24 )
{
F_104 ( & V_24 -> V_101 ) ;
if ( V_24 -> V_102 ) {
F_105 ( & V_24 -> V_101 ) ;
return false ;
}
return true ;
}
int F_106 ( struct V_23 * V_24 , T_8 V_115 )
{
int V_31 ;
bool V_116 ;
T_3 V_117 = F_67 ( 0 , 0 ) ;
F_107 ( V_24 ) ;
F_108 ( & V_117 ) ;
if ( F_66 ( V_115 ) < F_66 ( V_24 -> V_66 ) ) {
V_31 = F_98 ( V_24 , V_115 , V_24 -> V_66 , & V_116 ) ;
if ( V_31 ) {
F_109 ( & V_117 ) ;
goto V_118;
}
if ( ! V_116 ) {
F_9 ( L_20 ) ;
V_31 = - V_17 ;
F_109 ( & V_117 ) ;
goto V_118;
}
}
V_31 = F_110 ( & V_24 -> V_42 , V_24 -> V_58 , F_66 ( V_24 -> V_66 ) ,
F_66 ( V_115 ) ,
& V_117 , & V_24 -> V_58 ) ;
if ( V_31 )
goto V_118;
if ( F_27 ( V_24 ) ) {
V_31 = F_111 ( & V_24 -> V_73 , V_24 -> V_71 ,
F_66 ( V_24 -> V_66 ) , F_66 ( V_115 ) ,
false , & V_24 -> V_71 ) ;
if ( V_31 )
goto V_118;
}
V_24 -> V_66 = V_115 ;
V_24 -> V_92 = true ;
V_118:
F_112 ( V_24 ) ;
return V_31 ;
}
int F_113 ( struct V_23 * V_24 ,
T_4 V_61 ,
T_9 V_119 )
{
int V_31 ;
F_107 ( V_24 ) ;
V_31 = F_111 ( & V_24 -> V_74 ,
V_24 -> V_60 ,
F_31 ( V_24 -> V_62 ) ,
F_31 ( V_119 ) ,
false , & V_24 -> V_60 ) ;
if ( ! V_31 ) {
V_24 -> V_61 = V_61 ;
V_24 -> V_62 = V_119 ;
}
V_24 -> V_92 = true ;
F_112 ( V_24 ) ;
return V_31 ;
}
static int F_114 ( struct V_23 * V_24 , T_9 V_4 )
{
return F_115 ( & V_24 -> V_74 , V_24 -> V_60 ,
F_31 ( V_4 ) , & V_24 -> V_60 ) ;
}
static int F_116 ( struct V_23 * V_24 , T_9 V_4 )
{
return F_117 ( & V_24 -> V_74 , V_24 -> V_60 ,
F_31 ( V_4 ) , & V_24 -> V_60 ) ;
}
static int F_118 ( struct V_23 * V_24 ,
T_9 V_120 , bool V_121 )
{
int V_31 ;
V_31 = ( V_121 ? F_114 : F_116 ) ( V_24 , V_120 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_92 = true ;
return 0 ;
}
int F_119 ( struct V_23 * V_24 ,
T_9 V_120 , bool V_121 )
{
int V_31 ;
F_107 ( V_24 ) ;
V_31 = F_118 ( V_24 , V_120 , V_121 ) ;
F_112 ( V_24 ) ;
return V_31 ;
}
static int F_120 ( struct V_23 * V_24 ,
T_10 V_122 , void * V_37 )
{
int V_31 = 0 ;
T_2 V_4 ;
struct V_123 V_124 ;
if ( F_31 ( V_24 -> V_62 ) == 0 )
return 0 ;
if ( V_24 -> V_75 ) {
V_31 = F_65 ( & V_24 -> V_74 , V_24 -> V_60 , & V_24 -> V_60 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_93 ( & V_24 -> V_74 , V_24 -> V_60 ,
F_31 ( V_24 -> V_62 ) , & V_124 ) ;
if ( V_31 )
return V_31 ;
for ( V_4 = 0 ; V_4 < F_31 ( V_24 -> V_62 ) ; V_4 ++ ) {
V_31 = V_122 ( V_37 , V_24 -> V_61 , F_58 ( V_4 ) ,
F_96 ( & V_124 ) ) ;
if ( V_31 )
break;
}
F_95 ( & V_124 ) ;
} else {
for ( V_4 = 0 ; V_4 < F_31 ( V_24 -> V_62 ) ; V_4 ++ ) {
V_31 = V_122 ( V_37 , V_24 -> V_61 , F_58 ( V_4 ) , false ) ;
if ( V_31 )
return V_31 ;
}
}
return V_31 ;
}
int F_121 ( struct V_23 * V_24 ,
T_10 V_122 , void * V_37 )
{
int V_31 ;
F_122 ( V_24 ) ;
V_31 = F_120 ( V_24 , V_122 , V_37 ) ;
F_123 ( V_24 ) ;
return V_31 ;
}
int F_124 ( struct V_23 * V_24 , T_8 * V_30 )
{
F_122 ( V_24 ) ;
* V_30 = V_24 -> V_66 ;
F_123 ( V_24 ) ;
return 0 ;
}
static int F_125 ( struct V_23 * V_24 , T_8 V_125 )
{
int V_31 ;
T_3 V_94 = F_67 ( 0 , 0 ) ;
F_108 ( & V_94 ) ;
V_31 = F_126 ( & V_24 -> V_42 , V_24 -> V_58 , F_66 ( V_125 ) ,
& V_94 , & V_24 -> V_58 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_92 = true ;
return 0 ;
}
int F_127 ( struct V_23 * V_24 , T_8 V_125 )
{
int V_31 ;
F_107 ( V_24 ) ;
V_31 = F_125 ( V_24 , V_125 ) ;
F_112 ( V_24 ) ;
return V_31 ;
}
static int F_128 ( struct V_23 * V_24 ,
T_8 V_125 , T_6 V_126 )
{
int V_31 ;
T_3 V_94 = F_67 ( V_126 , V_108 ) ;
F_108 ( & V_94 ) ;
V_31 = F_126 ( & V_24 -> V_42 , V_24 -> V_58 , F_66 ( V_125 ) ,
& V_94 , & V_24 -> V_58 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_92 = true ;
return 0 ;
}
int F_129 ( struct V_23 * V_24 ,
T_8 V_125 , T_6 V_126 )
{
int V_31 ;
F_107 ( V_24 ) ;
V_31 = F_128 ( V_24 , V_125 , V_126 ) ;
F_112 ( V_24 ) ;
return V_31 ;
}
static bool F_130 ( struct V_23 * V_24 ,
struct V_127 * V_128 )
{
const char * V_55 = F_131 ( V_128 ) ;
const unsigned * V_56 = F_132 ( V_128 ) ;
T_1 V_44 = F_133 ( V_128 ) ;
if ( strncmp ( V_24 -> V_55 , V_55 , sizeof( V_24 -> V_55 ) ) )
return false ;
if ( V_24 -> V_56 [ 0 ] != V_56 [ 0 ] )
return false ;
if ( V_24 -> V_44 != V_44 )
return false ;
return true ;
}
static bool F_134 ( struct V_23 * V_24 )
{
return V_24 -> V_59 && V_24 -> V_44 ;
}
static bool F_135 ( struct V_23 * V_24 ,
struct V_127 * V_128 )
{
return V_24 -> V_75 && F_130 ( V_24 , V_128 ) &&
F_134 ( V_24 ) ;
}
static int F_136 ( struct V_23 * V_24 ,
T_7 V_129 , bool V_130 ,
struct V_131 * V_132 ,
struct V_131 * V_133 ,
T_11 V_122 , void * V_37 )
{
int V_31 = 0 ;
T_3 V_134 ;
V_11 V_135 = 0 ;
T_3 * V_136 ;
V_11 * V_137 ;
T_6 V_126 ;
unsigned V_10 ;
F_137 ( V_132 , ( void * * ) & V_136 ) ;
memcpy ( & V_134 , V_136 , sizeof( V_134 ) ) ;
F_69 ( V_134 , & V_126 , & V_10 ) ;
if ( V_10 & V_108 ) {
if ( V_130 ) {
F_137 ( V_133 , ( void * * ) & V_137 ) ;
memcpy ( & V_135 , V_137 , sizeof( V_135 ) ) ;
}
V_31 = V_122 ( V_37 , V_126 , F_59 ( V_129 ) , V_10 & V_109 ,
F_8 ( V_135 ) , V_130 ) ;
if ( V_31 ) {
F_9 ( L_21 ,
( unsigned long long ) F_66 ( F_59 ( V_129 ) ) ) ;
}
}
return V_31 ;
}
static int F_138 ( struct V_23 * V_24 ,
T_7 V_129 , bool V_130 ,
struct V_131 * V_132 ,
struct V_131 * V_133 ,
struct V_123 * V_113 ,
T_11 V_122 , void * V_37 )
{
int V_31 = 0 ;
T_3 V_134 ;
V_11 V_135 = 0 ;
T_3 * V_136 ;
V_11 * V_137 ;
T_6 V_126 ;
unsigned V_10 ;
bool V_138 ;
F_137 ( V_132 , ( void * * ) & V_136 ) ;
memcpy ( & V_134 , V_136 , sizeof( V_134 ) ) ;
F_69 ( V_134 , & V_126 , & V_10 ) ;
if ( V_10 & V_108 ) {
if ( V_130 ) {
F_137 ( V_133 , ( void * * ) & V_137 ) ;
memcpy ( & V_135 , V_137 , sizeof( V_135 ) ) ;
}
V_138 = F_96 ( V_113 ) ;
V_31 = V_122 ( V_37 , V_126 , F_59 ( V_129 ) , V_138 ,
F_8 ( V_135 ) , V_130 ) ;
if ( V_31 ) {
F_9 ( L_21 ,
( unsigned long long ) F_66 ( F_59 ( V_129 ) ) ) ;
}
}
return V_31 ;
}
static int F_139 ( struct V_23 * V_24 ,
struct V_127 * V_128 ,
T_11 V_122 , void * V_37 )
{
int V_31 ;
T_7 V_129 ;
bool V_130 = F_135 ( V_24 , V_128 ) ;
if ( F_66 ( V_24 -> V_66 ) == 0 )
return 0 ;
V_31 = F_140 ( & V_24 -> V_42 , V_24 -> V_58 , & V_24 -> V_132 ) ;
if ( V_31 )
return V_31 ;
if ( V_130 ) {
V_31 = F_140 ( & V_24 -> V_45 , V_24 -> V_59 , & V_24 -> V_133 ) ;
if ( V_31 ) {
F_141 ( & V_24 -> V_132 ) ;
return V_31 ;
}
}
if ( F_27 ( V_24 ) ) {
V_31 = F_93 ( & V_24 -> V_73 , V_24 -> V_71 ,
F_66 ( V_24 -> V_66 ) ,
& V_24 -> V_113 ) ;
if ( V_31 ) {
F_141 ( & V_24 -> V_133 ) ;
F_141 ( & V_24 -> V_132 ) ;
return V_31 ;
}
}
for ( V_129 = 0 ; ; V_129 ++ ) {
if ( F_27 ( V_24 ) )
V_31 = F_138 ( V_24 , V_129 , V_130 ,
& V_24 -> V_132 ,
& V_24 -> V_133 ,
& V_24 -> V_113 ,
V_122 , V_37 ) ;
else
V_31 = F_136 ( V_24 , V_129 , V_130 ,
& V_24 -> V_132 , & V_24 -> V_133 ,
V_122 , V_37 ) ;
if ( V_31 )
goto V_118;
if ( V_129 >= ( F_66 ( V_24 -> V_66 ) - 1 ) )
break;
V_31 = F_142 ( & V_24 -> V_132 ) ;
if ( V_31 ) {
F_9 ( L_22 ) ;
goto V_118;
}
if ( V_130 ) {
V_31 = F_142 ( & V_24 -> V_133 ) ;
if ( V_31 ) {
F_9 ( L_23 ) ;
goto V_118;
}
}
if ( F_27 ( V_24 ) ) {
V_31 = F_97 ( & V_24 -> V_113 ) ;
if ( V_31 ) {
F_9 ( L_24 ) ;
goto V_118;
}
}
}
V_118:
F_141 ( & V_24 -> V_132 ) ;
if ( V_130 )
F_141 ( & V_24 -> V_133 ) ;
if ( F_27 ( V_24 ) )
F_95 ( & V_24 -> V_113 ) ;
return V_31 ;
}
int F_143 ( struct V_23 * V_24 ,
struct V_127 * V_128 ,
T_11 V_122 , void * V_37 )
{
int V_31 ;
F_122 ( V_24 ) ;
V_31 = F_139 ( V_24 , V_128 , V_122 , V_37 ) ;
F_123 ( V_24 ) ;
return V_31 ;
}
static int F_144 ( void * V_37 , T_7 V_125 , void * V_139 )
{
int V_31 = 0 ;
T_3 V_94 ;
T_6 V_126 ;
unsigned V_10 ;
memcpy ( & V_94 , V_139 , sizeof( V_94 ) ) ;
F_69 ( V_94 , & V_126 , & V_10 ) ;
return V_31 ;
}
static int F_145 ( struct V_23 * V_24 )
{
return F_146 ( & V_24 -> V_42 , V_24 -> V_58 , F_144 , NULL ) ;
}
void F_147 ( struct V_23 * V_24 )
{
F_148 ( V_24 ) ;
F_145 ( V_24 ) ;
F_123 ( V_24 ) ;
}
int F_149 ( struct V_23 * V_24 )
{
int V_31 ;
F_122 ( V_24 ) ;
V_31 = V_24 -> V_92 ;
F_123 ( V_24 ) ;
return V_31 ;
}
static int F_150 ( struct V_23 * V_24 , T_8 V_125 , bool V_138 )
{
int V_31 ;
unsigned V_10 ;
T_6 V_126 ;
T_3 V_94 ;
V_31 = F_90 ( & V_24 -> V_42 , V_24 -> V_58 , F_66 ( V_125 ) , & V_94 ) ;
if ( V_31 )
return V_31 ;
F_69 ( V_94 , & V_126 , & V_10 ) ;
if ( ( ( V_10 & V_109 ) && V_138 ) || ( ! ( V_10 & V_109 ) && ! V_138 ) )
return 0 ;
V_94 = F_67 ( V_126 , ( V_10 & ~ V_109 ) | ( V_138 ? V_109 : 0 ) ) ;
F_108 ( & V_94 ) ;
V_31 = F_126 ( & V_24 -> V_42 , V_24 -> V_58 , F_66 ( V_125 ) ,
& V_94 , & V_24 -> V_58 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_92 = true ;
return 0 ;
}
static int F_151 ( struct V_23 * V_24 , unsigned V_140 , unsigned long * V_141 )
{
int V_31 ;
unsigned V_32 ;
for ( V_32 = 0 ; V_32 < V_140 ; V_32 ++ ) {
V_31 = F_150 ( V_24 , F_59 ( V_32 ) , F_44 ( V_32 , V_141 ) ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
static int F_152 ( T_2 V_142 , bool * V_94 , void * V_37 )
{
unsigned long * V_141 = V_37 ;
* V_94 = F_44 ( V_142 , V_141 ) ;
return 0 ;
}
static int F_153 ( struct V_23 * V_24 , unsigned V_140 , unsigned long * V_141 )
{
int V_31 = 0 ;
if ( V_140 != F_66 ( V_24 -> V_66 ) ) {
F_9 ( L_25 ) ;
return - V_17 ;
}
V_31 = F_154 ( & V_24 -> V_73 , V_24 -> V_71 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_92 = true ;
return F_155 ( & V_24 -> V_73 , & V_24 -> V_71 , V_140 , F_152 , V_141 ) ;
}
int F_156 ( struct V_23 * V_24 ,
unsigned V_140 ,
unsigned long * V_141 )
{
int V_31 ;
F_107 ( V_24 ) ;
if ( F_27 ( V_24 ) )
V_31 = F_153 ( V_24 , V_140 , V_141 ) ;
else
V_31 = F_151 ( V_24 , V_140 , V_141 ) ;
F_112 ( V_24 ) ;
return V_31 ;
}
void F_157 ( struct V_23 * V_24 ,
struct V_143 * V_91 )
{
F_148 ( V_24 ) ;
* V_91 = V_24 -> V_91 ;
F_123 ( V_24 ) ;
}
void F_158 ( struct V_23 * V_24 ,
struct V_143 * V_91 )
{
F_159 ( V_24 ) ;
V_24 -> V_91 = * V_91 ;
F_112 ( V_24 ) ;
}
int F_160 ( struct V_23 * V_24 , bool V_144 )
{
int V_31 ;
T_5 V_90 = ( V_144 ? F_53 :
F_55 ) ;
F_107 ( V_24 ) ;
V_31 = F_63 ( V_24 , V_90 ) ;
if ( V_31 )
goto V_118;
V_31 = F_62 ( V_24 ) ;
V_118:
F_112 ( V_24 ) ;
return V_31 ;
}
int F_161 ( struct V_23 * V_24 ,
T_12 * V_30 )
{
int V_31 = - V_17 ;
F_122 ( V_24 ) ;
V_31 = F_162 ( V_24 -> V_47 , V_30 ) ;
F_123 ( V_24 ) ;
return V_31 ;
}
int F_163 ( struct V_23 * V_24 ,
T_12 * V_30 )
{
int V_31 = - V_17 ;
F_122 ( V_24 ) ;
V_31 = F_164 ( V_24 -> V_47 , V_30 ) ;
F_123 ( V_24 ) ;
return V_31 ;
}
static int F_165 ( T_2 V_142 , void * V_96 , void * V_37 )
{
T_2 V_94 ;
struct V_127 * V_128 = V_37 ;
V_94 = F_166 ( V_128 , F_59 ( V_142 ) ) ;
* ( ( V_11 * ) V_96 ) = F_5 ( V_94 ) ;
return 0 ;
}
static int F_167 ( struct V_23 * V_24 , struct V_127 * V_128 )
{
int V_31 ;
T_1 V_145 ;
const char * V_55 = F_131 ( V_128 ) ;
const unsigned * V_56 = F_132 ( V_128 ) ;
if ( ! V_55 [ 0 ] ||
( strlen ( V_55 ) > sizeof( V_24 -> V_55 ) - 1 ) )
return - V_17 ;
strncpy ( V_24 -> V_55 , V_55 , sizeof( V_24 -> V_55 ) ) ;
memcpy ( V_24 -> V_56 , V_56 , sizeof( V_24 -> V_56 ) ) ;
V_145 = F_133 ( V_128 ) ;
if ( ! V_145 )
return 0 ;
V_24 -> V_44 = V_145 ;
if ( V_24 -> V_59 ) {
V_31 = F_168 ( & V_24 -> V_45 , V_24 -> V_59 ) ;
if ( V_31 )
return V_31 ;
}
return F_169 ( & V_24 -> V_45 , & V_24 -> V_59 ,
F_66 ( V_24 -> V_66 ) ,
F_165 , V_128 ) ;
}
int F_170 ( struct V_23 * V_24 , struct V_127 * V_128 )
{
int V_31 ;
F_107 ( V_24 ) ;
V_31 = F_167 ( V_24 , V_128 ) ;
F_112 ( V_24 ) ;
return V_31 ;
}
int F_171 ( struct V_23 * V_24 , bool * V_30 )
{
int V_31 ;
F_122 ( V_24 ) ;
V_31 = F_98 ( V_24 , 0 , V_24 -> V_66 , V_30 ) ;
F_123 ( V_24 ) ;
return V_31 ;
}
void F_172 ( struct V_23 * V_24 )
{
F_159 ( V_24 ) ;
F_173 ( V_24 -> V_26 ) ;
F_112 ( V_24 ) ;
}
void F_174 ( struct V_23 * V_24 )
{
F_159 ( V_24 ) ;
F_175 ( V_24 -> V_26 ) ;
F_112 ( V_24 ) ;
}
int F_176 ( struct V_23 * V_24 )
{
int V_31 ;
struct V_3 * V_25 ;
struct V_6 * V_7 ;
F_107 ( V_24 ) ;
F_54 ( V_146 , & V_24 -> V_10 ) ;
V_31 = F_16 ( V_24 , & V_25 ) ;
if ( V_31 ) {
F_9 ( L_26 ) ;
goto V_118;
}
V_7 = F_2 ( V_25 ) ;
V_7 -> V_10 = F_5 ( V_24 -> V_10 ) ;
F_20 ( V_25 ) ;
V_118:
F_112 ( V_24 ) ;
return V_31 ;
}
int F_177 ( struct V_23 * V_24 , bool * V_30 )
{
F_122 ( V_24 ) ;
* V_30 = ! ! F_44 ( V_146 , & V_24 -> V_10 ) ;
F_123 ( V_24 ) ;
return 0 ;
}
int F_178 ( struct V_23 * V_24 )
{
int V_31 ;
F_107 ( V_24 ) ;
F_51 ( V_24 ) ;
V_31 = F_46 ( V_24 , false ) ;
if ( V_31 )
V_24 -> V_102 = true ;
F_112 ( V_24 ) ;
return V_31 ;
}
