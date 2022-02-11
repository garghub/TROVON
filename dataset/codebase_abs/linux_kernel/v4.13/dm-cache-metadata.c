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
V_88 ) ;
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
T_5 V_89 )
{
T_2 V_82 = V_89 ( F_8 ( V_7 -> V_10 ) ) ;
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
V_24 -> V_90 . V_67 = F_8 ( V_7 -> V_67 ) ;
V_24 -> V_90 . V_68 = F_8 ( V_7 -> V_68 ) ;
V_24 -> V_90 . V_69 = F_8 ( V_7 -> V_69 ) ;
V_24 -> V_90 . V_70 = F_8 ( V_7 -> V_70 ) ;
if ( F_27 ( V_24 ) )
V_24 -> V_71 = F_11 ( V_7 -> V_71 ) ;
V_24 -> V_91 = false ;
}
static int F_60 ( struct V_23 * V_24 ,
T_5 V_89 )
{
int V_31 ;
struct V_6 * V_7 ;
struct V_3 * V_25 ;
V_31 = F_16 ( V_24 , & V_25 ) ;
if ( V_31 )
return V_31 ;
V_7 = F_2 ( V_25 ) ;
F_52 ( V_7 , V_89 ) ;
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
T_5 V_89 )
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
if ( V_89 )
F_52 ( V_7 , V_89 ) ;
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
V_7 -> V_67 = F_5 ( V_24 -> V_90 . V_67 ) ;
V_7 -> V_68 = F_5 ( V_24 -> V_90 . V_68 ) ;
V_7 -> V_69 = F_5 ( V_24 -> V_90 . V_69 ) ;
V_7 -> V_70 = F_5 ( V_24 -> V_90 . V_70 ) ;
F_26 ( V_24 , V_7 ) ;
return F_32 ( V_24 -> V_43 , V_25 ) ;
}
static T_3 F_67 ( T_6 V_92 , unsigned V_10 )
{
T_7 V_93 = F_68 ( V_92 ) ;
V_93 <<= 16 ;
V_93 = V_93 | ( V_10 & V_94 ) ;
return F_3 ( V_93 ) ;
}
static void F_69 ( T_3 V_95 , T_6 * V_92 , unsigned * V_10 )
{
T_7 V_93 = F_11 ( V_95 ) ;
T_7 V_4 = V_93 >> 16 ;
* V_92 = F_70 ( V_4 ) ;
* V_10 = V_93 & V_94 ;
}
static struct V_23 * F_71 ( struct V_96 * V_50 ,
T_4 V_65 ,
bool V_87 ,
T_1 V_44 ,
unsigned V_13 )
{
int V_31 ;
struct V_23 * V_24 ;
V_24 = F_72 ( sizeof( * V_24 ) , V_97 ) ;
if ( ! V_24 ) {
F_9 ( L_12 ) ;
return F_73 ( - V_98 ) ;
}
V_24 -> V_14 = V_13 ;
F_74 ( & V_24 -> V_99 , 1 ) ;
F_75 ( & V_24 -> V_100 ) ;
V_24 -> V_50 = V_50 ;
V_24 -> V_65 = V_65 ;
V_24 -> V_66 = 0 ;
V_24 -> V_44 = V_44 ;
V_24 -> V_91 = true ;
V_24 -> V_101 = false ;
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
static struct V_23 * F_78 ( struct V_96 * V_50 )
{
struct V_23 * V_24 ;
F_79 (cmd, &table, list)
if ( V_24 -> V_50 == V_50 ) {
F_80 ( & V_24 -> V_99 ) ;
return V_24 ;
}
return NULL ;
}
static struct V_23 * F_81 ( struct V_96 * V_50 ,
T_4 V_65 ,
bool V_87 ,
T_1 V_44 ,
unsigned V_13 )
{
struct V_23 * V_24 , * V_102 ;
F_82 ( & V_103 ) ;
V_24 = F_78 ( V_50 ) ;
F_83 ( & V_103 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_71 ( V_50 , V_65 , V_87 ,
V_44 , V_13 ) ;
if ( ! F_48 ( V_24 ) ) {
F_82 ( & V_103 ) ;
V_102 = F_78 ( V_50 ) ;
if ( V_102 ) {
F_83 ( & V_103 ) ;
F_51 ( V_24 ) ;
F_76 ( V_24 ) ;
return V_102 ;
}
F_84 ( & V_24 -> V_104 , & V_105 ) ;
F_83 ( & V_103 ) ;
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
struct V_23 * F_86 ( struct V_96 * V_50 ,
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
if ( F_87 ( & V_24 -> V_99 ) ) {
F_82 ( & V_103 ) ;
F_88 ( & V_24 -> V_104 ) ;
F_83 ( & V_103 ) ;
if ( ! V_24 -> V_101 )
F_51 ( V_24 ) ;
F_76 ( V_24 ) ;
}
}
static int F_89 ( struct V_23 * V_24 , T_8 V_4 ,
bool * V_30 )
{
int V_31 ;
T_3 V_93 ;
T_6 V_106 ;
unsigned V_10 ;
V_31 = F_90 ( & V_24 -> V_42 , V_24 -> V_58 , F_66 ( V_4 ) , & V_93 ) ;
if ( V_31 )
return V_31 ;
F_69 ( V_93 , & V_106 , & V_10 ) ;
* V_30 = ! ( ( V_10 & V_107 ) && ( V_10 & V_108 ) ) ;
return 0 ;
}
static int F_91 ( struct V_23 * V_24 ,
T_8 V_109 , T_8 V_110 ,
bool * V_30 )
{
int V_31 ;
* V_30 = true ;
while ( V_109 != V_110 ) {
V_31 = F_89 ( V_24 , V_109 , V_30 ) ;
if ( V_31 ) {
F_9 ( L_14 ) ;
return V_31 ;
}
if ( ! * V_30 ) {
F_9 ( L_15 ,
( unsigned long long ) F_66 ( V_109 ) ) ;
return 0 ;
}
V_109 = F_59 ( F_66 ( V_109 ) + 1 ) ;
}
return 0 ;
}
static int F_92 ( struct V_23 * V_24 ,
T_8 V_109 , T_8 V_110 ,
bool * V_30 )
{
int V_31 ;
bool V_111 ;
* V_30 = true ;
V_31 = F_93 ( & V_24 -> V_73 , V_24 -> V_71 ,
F_66 ( V_24 -> V_66 ) , & V_24 -> V_112 ) ;
if ( V_31 ) {
F_9 ( L_16 , V_113 ) ;
return V_31 ;
}
V_31 = F_94 ( & V_24 -> V_112 , F_66 ( V_109 ) ) ;
if ( V_31 ) {
F_9 ( L_17 , V_113 ) ;
F_95 ( & V_24 -> V_112 ) ;
return V_31 ;
}
while ( V_109 != V_110 ) {
V_111 = F_96 ( & V_24 -> V_112 ) ;
if ( V_111 ) {
F_9 ( L_18 , V_113 ,
( unsigned long long ) F_66 ( V_109 ) ) ;
F_95 ( & V_24 -> V_112 ) ;
* V_30 = false ;
return 0 ;
}
V_109 = F_59 ( F_66 ( V_109 ) + 1 ) ;
if ( V_109 == V_110 )
break;
V_31 = F_97 ( & V_24 -> V_112 ) ;
if ( V_31 ) {
F_9 ( L_19 , V_113 ) ;
F_95 ( & V_24 -> V_112 ) ;
return V_31 ;
}
}
F_95 ( & V_24 -> V_112 ) ;
return 0 ;
}
static int F_98 ( struct V_23 * V_24 ,
T_8 V_109 , T_8 V_110 ,
bool * V_30 )
{
if ( F_27 ( V_24 ) )
return F_92 ( V_24 , V_109 , V_110 , V_30 ) ;
else
return F_91 ( V_24 , V_109 , V_110 , V_30 ) ;
}
static bool F_99 ( struct V_23 * V_24 )
{
F_100 ( & V_24 -> V_100 ) ;
if ( V_24 -> V_101 || F_101 ( V_24 -> V_26 ) ) {
F_102 ( & V_24 -> V_100 ) ;
return false ;
}
return true ;
}
static bool F_103 ( struct V_23 * V_24 )
{
F_104 ( & V_24 -> V_100 ) ;
if ( V_24 -> V_101 ) {
F_105 ( & V_24 -> V_100 ) ;
return false ;
}
return true ;
}
int F_106 ( struct V_23 * V_24 , T_8 V_114 )
{
int V_31 ;
bool V_115 ;
T_3 V_116 = F_67 ( 0 , 0 ) ;
F_107 ( V_24 ) ;
F_108 ( & V_116 ) ;
if ( F_66 ( V_114 ) < F_66 ( V_24 -> V_66 ) ) {
V_31 = F_98 ( V_24 , V_114 , V_24 -> V_66 , & V_115 ) ;
if ( V_31 ) {
F_109 ( & V_116 ) ;
goto V_117;
}
if ( ! V_115 ) {
F_9 ( L_20 ) ;
V_31 = - V_17 ;
F_109 ( & V_116 ) ;
goto V_117;
}
}
V_31 = F_110 ( & V_24 -> V_42 , V_24 -> V_58 , F_66 ( V_24 -> V_66 ) ,
F_66 ( V_114 ) ,
& V_116 , & V_24 -> V_58 ) ;
if ( V_31 )
goto V_117;
if ( F_27 ( V_24 ) ) {
V_31 = F_111 ( & V_24 -> V_73 , V_24 -> V_71 ,
F_66 ( V_24 -> V_66 ) , F_66 ( V_114 ) ,
false , & V_24 -> V_71 ) ;
if ( V_31 )
goto V_117;
}
V_24 -> V_66 = V_114 ;
V_24 -> V_91 = true ;
V_117:
F_112 ( V_24 ) ;
return V_31 ;
}
int F_113 ( struct V_23 * V_24 ,
T_4 V_61 ,
T_9 V_118 )
{
int V_31 ;
F_107 ( V_24 ) ;
V_31 = F_111 ( & V_24 -> V_74 ,
V_24 -> V_60 ,
F_31 ( V_24 -> V_62 ) ,
F_31 ( V_118 ) ,
false , & V_24 -> V_60 ) ;
if ( ! V_31 ) {
V_24 -> V_61 = V_61 ;
V_24 -> V_62 = V_118 ;
}
V_24 -> V_91 = true ;
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
T_9 V_119 , bool V_120 )
{
int V_31 ;
V_31 = ( V_120 ? F_114 : F_116 ) ( V_24 , V_119 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_91 = true ;
return 0 ;
}
int F_119 ( struct V_23 * V_24 ,
T_9 V_119 , bool V_120 )
{
int V_31 ;
F_107 ( V_24 ) ;
V_31 = F_118 ( V_24 , V_119 , V_120 ) ;
F_112 ( V_24 ) ;
return V_31 ;
}
static int F_120 ( struct V_23 * V_24 ,
T_10 V_121 , void * V_37 )
{
int V_31 = 0 ;
T_2 V_4 ;
struct V_122 V_123 ;
if ( F_31 ( V_24 -> V_62 ) == 0 )
return 0 ;
if ( V_24 -> V_75 ) {
V_31 = F_65 ( & V_24 -> V_74 , V_24 -> V_60 , & V_24 -> V_60 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_93 ( & V_24 -> V_74 , V_24 -> V_60 ,
F_31 ( V_24 -> V_62 ) , & V_123 ) ;
if ( V_31 )
return V_31 ;
for ( V_4 = 0 ; V_4 < F_31 ( V_24 -> V_62 ) ; V_4 ++ ) {
V_31 = V_121 ( V_37 , V_24 -> V_61 , F_58 ( V_4 ) ,
F_96 ( & V_123 ) ) ;
if ( V_31 )
break;
}
F_95 ( & V_123 ) ;
} else {
for ( V_4 = 0 ; V_4 < F_31 ( V_24 -> V_62 ) ; V_4 ++ ) {
V_31 = V_121 ( V_37 , V_24 -> V_61 , F_58 ( V_4 ) , false ) ;
if ( V_31 )
return V_31 ;
}
}
return V_31 ;
}
int F_121 ( struct V_23 * V_24 ,
T_10 V_121 , void * V_37 )
{
int V_31 ;
F_122 ( V_24 ) ;
V_31 = F_120 ( V_24 , V_121 , V_37 ) ;
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
static int F_125 ( struct V_23 * V_24 , T_8 V_124 )
{
int V_31 ;
T_3 V_93 = F_67 ( 0 , 0 ) ;
F_108 ( & V_93 ) ;
V_31 = F_126 ( & V_24 -> V_42 , V_24 -> V_58 , F_66 ( V_124 ) ,
& V_93 , & V_24 -> V_58 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_91 = true ;
return 0 ;
}
int F_127 ( struct V_23 * V_24 , T_8 V_124 )
{
int V_31 ;
F_107 ( V_24 ) ;
V_31 = F_125 ( V_24 , V_124 ) ;
F_112 ( V_24 ) ;
return V_31 ;
}
static int F_128 ( struct V_23 * V_24 ,
T_8 V_124 , T_6 V_125 )
{
int V_31 ;
T_3 V_93 = F_67 ( V_125 , V_107 ) ;
F_108 ( & V_93 ) ;
V_31 = F_126 ( & V_24 -> V_42 , V_24 -> V_58 , F_66 ( V_124 ) ,
& V_93 , & V_24 -> V_58 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_91 = true ;
return 0 ;
}
int F_129 ( struct V_23 * V_24 ,
T_8 V_124 , T_6 V_125 )
{
int V_31 ;
F_107 ( V_24 ) ;
V_31 = F_128 ( V_24 , V_124 , V_125 ) ;
F_112 ( V_24 ) ;
return V_31 ;
}
static bool F_130 ( struct V_23 * V_24 ,
struct V_126 * V_127 )
{
const char * V_55 = F_131 ( V_127 ) ;
const unsigned * V_56 = F_132 ( V_127 ) ;
T_1 V_44 = F_133 ( V_127 ) ;
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
struct V_126 * V_127 )
{
return V_24 -> V_75 && F_130 ( V_24 , V_127 ) &&
F_134 ( V_24 ) ;
}
static int F_136 ( struct V_23 * V_24 ,
T_7 V_128 , bool V_129 ,
struct V_130 * V_131 ,
struct V_130 * V_132 ,
T_11 V_121 , void * V_37 )
{
int V_31 = 0 ;
T_3 V_133 ;
V_11 V_134 = 0 ;
T_3 * V_135 ;
V_11 * V_136 ;
T_6 V_125 ;
unsigned V_10 ;
F_137 ( V_131 , ( void * * ) & V_135 ) ;
memcpy ( & V_133 , V_135 , sizeof( V_133 ) ) ;
F_69 ( V_133 , & V_125 , & V_10 ) ;
if ( V_10 & V_107 ) {
if ( V_129 ) {
F_137 ( V_132 , ( void * * ) & V_136 ) ;
memcpy ( & V_134 , V_136 , sizeof( V_134 ) ) ;
}
V_31 = V_121 ( V_37 , V_125 , F_59 ( V_128 ) , V_10 & V_108 ,
F_8 ( V_134 ) , V_129 ) ;
if ( V_31 ) {
F_9 ( L_21 ,
( unsigned long long ) F_66 ( F_59 ( V_128 ) ) ) ;
}
}
return V_31 ;
}
static int F_138 ( struct V_23 * V_24 ,
T_7 V_128 , bool V_129 ,
struct V_130 * V_131 ,
struct V_130 * V_132 ,
struct V_122 * V_112 ,
T_11 V_121 , void * V_37 )
{
int V_31 = 0 ;
T_3 V_133 ;
V_11 V_134 = 0 ;
T_3 * V_135 ;
V_11 * V_136 ;
T_6 V_125 ;
unsigned V_10 ;
bool V_137 ;
F_137 ( V_131 , ( void * * ) & V_135 ) ;
memcpy ( & V_133 , V_135 , sizeof( V_133 ) ) ;
F_69 ( V_133 , & V_125 , & V_10 ) ;
if ( V_10 & V_107 ) {
if ( V_129 ) {
F_137 ( V_132 , ( void * * ) & V_136 ) ;
memcpy ( & V_134 , V_136 , sizeof( V_134 ) ) ;
}
V_137 = F_96 ( V_112 ) ;
V_31 = V_121 ( V_37 , V_125 , F_59 ( V_128 ) , V_137 ,
F_8 ( V_134 ) , V_129 ) ;
if ( V_31 ) {
F_9 ( L_21 ,
( unsigned long long ) F_66 ( F_59 ( V_128 ) ) ) ;
}
}
return V_31 ;
}
static int F_139 ( struct V_23 * V_24 ,
struct V_126 * V_127 ,
T_11 V_121 , void * V_37 )
{
int V_31 ;
T_7 V_128 ;
bool V_129 = F_135 ( V_24 , V_127 ) ;
if ( F_66 ( V_24 -> V_66 ) == 0 )
return 0 ;
V_31 = F_140 ( & V_24 -> V_42 , V_24 -> V_58 , & V_24 -> V_131 ) ;
if ( V_31 )
return V_31 ;
if ( V_129 ) {
V_31 = F_140 ( & V_24 -> V_45 , V_24 -> V_59 , & V_24 -> V_132 ) ;
if ( V_31 ) {
F_141 ( & V_24 -> V_131 ) ;
return V_31 ;
}
}
if ( F_27 ( V_24 ) ) {
V_31 = F_93 ( & V_24 -> V_73 , V_24 -> V_71 ,
F_66 ( V_24 -> V_66 ) ,
& V_24 -> V_112 ) ;
if ( V_31 ) {
F_141 ( & V_24 -> V_132 ) ;
F_141 ( & V_24 -> V_131 ) ;
return V_31 ;
}
}
for ( V_128 = 0 ; ; V_128 ++ ) {
if ( F_27 ( V_24 ) )
V_31 = F_138 ( V_24 , V_128 , V_129 ,
& V_24 -> V_131 ,
& V_24 -> V_132 ,
& V_24 -> V_112 ,
V_121 , V_37 ) ;
else
V_31 = F_136 ( V_24 , V_128 , V_129 ,
& V_24 -> V_131 , & V_24 -> V_132 ,
V_121 , V_37 ) ;
if ( V_31 )
goto V_117;
if ( V_128 >= ( F_66 ( V_24 -> V_66 ) - 1 ) )
break;
V_31 = F_142 ( & V_24 -> V_131 ) ;
if ( V_31 ) {
F_9 ( L_22 ) ;
goto V_117;
}
if ( V_129 ) {
V_31 = F_142 ( & V_24 -> V_132 ) ;
if ( V_31 ) {
F_9 ( L_23 ) ;
goto V_117;
}
}
if ( F_27 ( V_24 ) ) {
V_31 = F_97 ( & V_24 -> V_112 ) ;
if ( V_31 ) {
F_9 ( L_24 ) ;
goto V_117;
}
}
}
V_117:
F_141 ( & V_24 -> V_131 ) ;
if ( V_129 )
F_141 ( & V_24 -> V_132 ) ;
if ( F_27 ( V_24 ) )
F_95 ( & V_24 -> V_112 ) ;
return V_31 ;
}
int F_143 ( struct V_23 * V_24 ,
struct V_126 * V_127 ,
T_11 V_121 , void * V_37 )
{
int V_31 ;
F_122 ( V_24 ) ;
V_31 = F_139 ( V_24 , V_127 , V_121 , V_37 ) ;
F_123 ( V_24 ) ;
return V_31 ;
}
static int F_144 ( void * V_37 , T_7 V_124 , void * V_138 )
{
int V_31 = 0 ;
T_3 V_93 ;
T_6 V_125 ;
unsigned V_10 ;
memcpy ( & V_93 , V_138 , sizeof( V_93 ) ) ;
F_69 ( V_93 , & V_125 , & V_10 ) ;
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
V_31 = V_24 -> V_91 ;
F_123 ( V_24 ) ;
return V_31 ;
}
static int F_150 ( struct V_23 * V_24 , T_8 V_124 , bool V_137 )
{
int V_31 ;
unsigned V_10 ;
T_6 V_125 ;
T_3 V_93 ;
V_31 = F_90 ( & V_24 -> V_42 , V_24 -> V_58 , F_66 ( V_124 ) , & V_93 ) ;
if ( V_31 )
return V_31 ;
F_69 ( V_93 , & V_125 , & V_10 ) ;
if ( ( ( V_10 & V_108 ) && V_137 ) || ( ! ( V_10 & V_108 ) && ! V_137 ) )
return 0 ;
V_93 = F_67 ( V_125 , ( V_10 & ~ V_108 ) | ( V_137 ? V_108 : 0 ) ) ;
F_108 ( & V_93 ) ;
V_31 = F_126 ( & V_24 -> V_42 , V_24 -> V_58 , F_66 ( V_124 ) ,
& V_93 , & V_24 -> V_58 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_91 = true ;
return 0 ;
}
static int F_151 ( struct V_23 * V_24 , unsigned V_139 , unsigned long * V_140 )
{
int V_31 ;
unsigned V_32 ;
for ( V_32 = 0 ; V_32 < V_139 ; V_32 ++ ) {
V_31 = F_150 ( V_24 , F_59 ( V_32 ) , F_44 ( V_32 , V_140 ) ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
static int F_152 ( T_2 V_141 , bool * V_93 , void * V_37 )
{
unsigned long * V_140 = V_37 ;
* V_93 = F_44 ( V_141 , V_140 ) ;
return 0 ;
}
static int F_153 ( struct V_23 * V_24 , unsigned V_139 , unsigned long * V_140 )
{
int V_31 = 0 ;
if ( V_139 != F_66 ( V_24 -> V_66 ) ) {
F_9 ( L_25 ) ;
return - V_17 ;
}
V_31 = F_154 ( & V_24 -> V_73 , V_24 -> V_71 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_91 = true ;
return F_155 ( & V_24 -> V_73 , & V_24 -> V_71 , V_139 , F_152 , V_140 ) ;
}
int F_156 ( struct V_23 * V_24 ,
unsigned V_139 ,
unsigned long * V_140 )
{
int V_31 ;
F_107 ( V_24 ) ;
if ( F_27 ( V_24 ) )
V_31 = F_153 ( V_24 , V_139 , V_140 ) ;
else
V_31 = F_151 ( V_24 , V_139 , V_140 ) ;
F_112 ( V_24 ) ;
return V_31 ;
}
void F_157 ( struct V_23 * V_24 ,
struct V_142 * V_90 )
{
F_148 ( V_24 ) ;
* V_90 = V_24 -> V_90 ;
F_123 ( V_24 ) ;
}
void F_158 ( struct V_23 * V_24 ,
struct V_142 * V_90 )
{
F_159 ( V_24 ) ;
V_24 -> V_90 = * V_90 ;
F_112 ( V_24 ) ;
}
int F_160 ( struct V_23 * V_24 , bool V_143 )
{
int V_31 = - V_17 ;
T_5 V_89 = ( V_143 ? F_53 :
F_55 ) ;
F_107 ( V_24 ) ;
if ( V_24 -> V_101 )
goto V_117;
V_31 = F_63 ( V_24 , V_89 ) ;
if ( V_31 )
goto V_117;
V_31 = F_62 ( V_24 ) ;
V_117:
F_112 ( V_24 ) ;
return V_31 ;
}
int F_161 ( struct V_23 * V_24 ,
T_12 * V_30 )
{
int V_31 = - V_17 ;
F_122 ( V_24 ) ;
if ( ! V_24 -> V_101 )
V_31 = F_162 ( V_24 -> V_47 , V_30 ) ;
F_123 ( V_24 ) ;
return V_31 ;
}
int F_163 ( struct V_23 * V_24 ,
T_12 * V_30 )
{
int V_31 = - V_17 ;
F_122 ( V_24 ) ;
if ( ! V_24 -> V_101 )
V_31 = F_164 ( V_24 -> V_47 , V_30 ) ;
F_123 ( V_24 ) ;
return V_31 ;
}
static int F_165 ( T_2 V_141 , void * V_95 , void * V_37 )
{
T_2 V_93 ;
struct V_126 * V_127 = V_37 ;
V_93 = F_166 ( V_127 , F_59 ( V_141 ) ) ;
* ( ( V_11 * ) V_95 ) = F_5 ( V_93 ) ;
return 0 ;
}
static int F_167 ( struct V_23 * V_24 , struct V_126 * V_127 )
{
int V_31 ;
T_1 V_144 ;
const char * V_55 = F_131 ( V_127 ) ;
const unsigned * V_56 = F_132 ( V_127 ) ;
if ( ! V_55 [ 0 ] ||
( strlen ( V_55 ) > sizeof( V_24 -> V_55 ) - 1 ) )
return - V_17 ;
strncpy ( V_24 -> V_55 , V_55 , sizeof( V_24 -> V_55 ) ) ;
memcpy ( V_24 -> V_56 , V_56 , sizeof( V_24 -> V_56 ) ) ;
V_144 = F_133 ( V_127 ) ;
if ( ! V_144 )
return 0 ;
V_24 -> V_44 = V_144 ;
if ( V_24 -> V_59 ) {
V_31 = F_168 ( & V_24 -> V_45 , V_24 -> V_59 ) ;
if ( V_31 )
return V_31 ;
}
return F_169 ( & V_24 -> V_45 , & V_24 -> V_59 ,
F_66 ( V_24 -> V_66 ) ,
F_165 , V_127 ) ;
}
int F_170 ( struct V_23 * V_24 , struct V_126 * V_127 )
{
int V_31 ;
F_107 ( V_24 ) ;
V_31 = F_167 ( V_24 , V_127 ) ;
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
F_54 ( V_145 , & V_24 -> V_10 ) ;
V_31 = F_16 ( V_24 , & V_25 ) ;
if ( V_31 ) {
F_9 ( L_26 ) ;
goto V_117;
}
V_7 = F_2 ( V_25 ) ;
V_7 -> V_10 = F_5 ( V_24 -> V_10 ) ;
F_20 ( V_25 ) ;
V_117:
F_112 ( V_24 ) ;
return V_31 ;
}
int F_177 ( struct V_23 * V_24 , bool * V_30 )
{
F_122 ( V_24 ) ;
* V_30 = ! ! F_44 ( V_145 , & V_24 -> V_10 ) ;
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
V_24 -> V_101 = true ;
F_112 ( V_24 ) ;
return V_31 ;
}
