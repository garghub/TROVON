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
return F_20 ( V_4 ) ;
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
static int F_27 ( struct V_23 * V_24 )
{
int V_31 ;
struct V_3 * V_25 ;
struct V_6 * V_7 ;
T_4 V_49 = F_28 ( V_24 -> V_50 -> V_51 ) >> V_52 ;
if ( V_49 > V_53 )
V_49 = V_53 ;
V_31 = F_29 ( V_24 -> V_43 ) ;
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
V_7 -> V_14 = F_5 ( V_16 ) ;
memset ( V_7 -> V_55 , 0 , sizeof( V_7 -> V_55 ) ) ;
memset ( V_7 -> V_56 , 0 , sizeof( V_7 -> V_56 ) ) ;
V_7 -> V_44 = 0 ;
F_26 ( V_24 , V_7 ) ;
V_7 -> V_57 = F_3 ( V_24 -> V_58 ) ;
V_7 -> V_59 = F_3 ( V_24 -> V_59 ) ;
V_7 -> V_60 = F_3 ( V_24 -> V_60 ) ;
V_7 -> V_61 = F_3 ( V_24 -> V_61 ) ;
V_7 -> V_62 = F_3 ( F_30 ( V_24 -> V_62 ) ) ;
V_7 -> V_63 = F_5 ( V_64 ) ;
V_7 -> V_65 = F_5 ( V_24 -> V_65 ) ;
V_7 -> V_66 = F_5 ( 0 ) ;
V_7 -> V_67 = F_5 ( 0 ) ;
V_7 -> V_68 = F_5 ( 0 ) ;
V_7 -> V_69 = F_5 ( 0 ) ;
V_7 -> V_70 = F_5 ( 0 ) ;
return F_31 ( V_24 -> V_43 , V_25 ) ;
}
static int F_32 ( struct V_23 * V_24 )
{
int V_31 ;
V_31 = F_33 ( V_24 -> V_26 , V_27 ,
& V_24 -> V_43 , & V_24 -> V_47 ) ;
if ( V_31 < 0 ) {
F_9 ( L_5 ) ;
return V_31 ;
}
F_21 ( V_24 ) ;
V_31 = F_34 ( & V_24 -> V_42 , & V_24 -> V_58 ) ;
if ( V_31 < 0 )
goto V_71;
F_35 ( V_24 -> V_43 , & V_24 -> V_72 ) ;
V_31 = F_36 ( & V_24 -> V_72 , & V_24 -> V_60 ) ;
if ( V_31 < 0 )
goto V_71;
V_24 -> V_61 = 0 ;
V_24 -> V_62 = 0 ;
V_31 = F_27 ( V_24 ) ;
if ( V_31 )
goto V_71;
V_24 -> V_73 = true ;
return 0 ;
V_71:
F_37 ( V_24 -> V_43 ) ;
F_38 ( V_24 -> V_47 ) ;
return V_31 ;
}
static int F_39 ( struct V_6 * V_7 ,
struct V_23 * V_24 )
{
T_2 V_74 ;
V_74 = F_8 ( V_7 -> V_75 ) & ~ V_76 ;
if ( V_74 ) {
F_9 ( L_6 ,
( unsigned long ) V_74 ) ;
return - V_17 ;
}
if ( F_40 ( V_24 -> V_50 -> V_77 ) )
return 0 ;
V_74 = F_8 ( V_7 -> V_78 ) & ~ V_79 ;
if ( V_74 ) {
F_9 ( L_7 ,
( unsigned long ) V_74 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_41 ( struct V_23 * V_24 )
{
int V_31 ;
struct V_3 * V_25 ;
struct V_6 * V_7 ;
unsigned long V_80 ;
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
goto V_71;
}
V_31 = F_39 ( V_7 , V_24 ) ;
if ( V_31 < 0 )
goto V_71;
V_31 = F_42 ( V_24 -> V_26 , V_27 ,
V_7 -> V_48 ,
sizeof( V_7 -> V_48 ) ,
& V_24 -> V_43 , & V_24 -> V_47 ) ;
if ( V_31 < 0 ) {
F_9 ( L_10 ) ;
goto V_71;
}
F_21 ( V_24 ) ;
F_35 ( V_24 -> V_43 , & V_24 -> V_72 ) ;
V_80 = F_8 ( V_7 -> V_10 ) ;
V_24 -> V_73 = F_43 ( V_81 , & V_80 ) ;
return F_20 ( V_25 ) ;
V_71:
F_20 ( V_25 ) ;
return V_31 ;
}
static int F_44 ( struct V_23 * V_24 ,
bool V_82 )
{
int V_31 ;
bool V_83 = false ;
V_31 = F_18 ( V_24 -> V_26 , & V_83 ) ;
if ( V_31 )
return V_31 ;
if ( V_83 )
return V_82 ? F_32 ( V_24 ) : - V_84 ;
return F_41 ( V_24 ) ;
}
static int F_45 ( struct V_23 * V_24 ,
bool V_85 )
{
int V_31 ;
V_24 -> V_26 = F_46 ( V_24 -> V_50 , V_64 << V_52 ,
V_86 ,
V_87 ) ;
if ( F_47 ( V_24 -> V_26 ) ) {
F_9 ( L_11 ) ;
return F_48 ( V_24 -> V_26 ) ;
}
V_31 = F_44 ( V_24 , V_85 ) ;
if ( V_31 )
F_49 ( V_24 -> V_26 ) ;
return V_31 ;
}
static void F_50 ( struct V_23 * V_24 )
{
F_38 ( V_24 -> V_47 ) ;
F_37 ( V_24 -> V_43 ) ;
F_49 ( V_24 -> V_26 ) ;
}
static void F_51 ( struct V_6 * V_7 ,
T_5 V_88 )
{
T_2 V_80 = V_88 ( F_8 ( V_7 -> V_10 ) ) ;
V_7 -> V_10 = F_5 ( V_80 ) ;
}
static unsigned long F_52 ( unsigned long V_10 )
{
F_53 ( V_81 , & V_10 ) ;
return V_10 ;
}
static unsigned long F_54 ( unsigned long V_10 )
{
F_55 ( V_81 , & V_10 ) ;
return V_10 ;
}
static void F_56 ( struct V_23 * V_24 ,
struct V_6 * V_7 )
{
V_24 -> V_10 = F_8 ( V_7 -> V_10 ) ;
V_24 -> V_58 = F_11 ( V_7 -> V_57 ) ;
V_24 -> V_59 = F_11 ( V_7 -> V_59 ) ;
V_24 -> V_60 = F_11 ( V_7 -> V_60 ) ;
V_24 -> V_61 = F_11 ( V_7 -> V_61 ) ;
V_24 -> V_62 = F_57 ( F_11 ( V_7 -> V_62 ) ) ;
V_24 -> V_65 = F_8 ( V_7 -> V_65 ) ;
V_24 -> V_66 = F_58 ( F_8 ( V_7 -> V_66 ) ) ;
strncpy ( V_24 -> V_55 , V_7 -> V_55 , sizeof( V_24 -> V_55 ) ) ;
V_24 -> V_56 [ 0 ] = F_8 ( V_7 -> V_56 [ 0 ] ) ;
V_24 -> V_56 [ 1 ] = F_8 ( V_7 -> V_56 [ 1 ] ) ;
V_24 -> V_56 [ 2 ] = F_8 ( V_7 -> V_56 [ 2 ] ) ;
V_24 -> V_44 = F_8 ( V_7 -> V_44 ) ;
V_24 -> V_89 . V_67 = F_8 ( V_7 -> V_67 ) ;
V_24 -> V_89 . V_68 = F_8 ( V_7 -> V_68 ) ;
V_24 -> V_89 . V_69 = F_8 ( V_7 -> V_69 ) ;
V_24 -> V_89 . V_70 = F_8 ( V_7 -> V_70 ) ;
V_24 -> V_90 = false ;
}
static int F_59 ( struct V_23 * V_24 ,
T_5 V_88 )
{
int V_31 ;
struct V_6 * V_7 ;
struct V_3 * V_25 ;
V_31 = F_16 ( V_24 , & V_25 ) ;
if ( V_31 )
return V_31 ;
V_7 = F_2 ( V_25 ) ;
F_51 ( V_7 , V_88 ) ;
F_56 ( V_24 , V_7 ) ;
F_20 ( V_25 ) ;
return F_60 ( V_24 -> V_26 ) ;
}
static int F_61 ( struct V_23 * V_24 )
{
int V_31 ;
struct V_6 * V_7 ;
struct V_3 * V_25 ;
V_31 = F_12 ( V_24 , & V_25 ) ;
if ( V_31 )
return V_31 ;
V_7 = F_2 ( V_25 ) ;
F_56 ( V_24 , V_7 ) ;
F_20 ( V_25 ) ;
return 0 ;
}
static int F_62 ( struct V_23 * V_24 ,
T_5 V_88 )
{
int V_31 ;
struct V_6 * V_7 ;
struct V_3 * V_25 ;
F_63 ( sizeof( struct V_6 ) > 512 ) ;
V_31 = F_64 ( & V_24 -> V_72 , V_24 -> V_60 ,
& V_24 -> V_60 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_29 ( V_24 -> V_43 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_23 ( V_24 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_16 ( V_24 , & V_25 ) ;
if ( V_31 )
return V_31 ;
V_7 = F_2 ( V_25 ) ;
if ( V_88 )
F_51 ( V_7 , V_88 ) ;
V_7 -> V_10 = F_5 ( V_24 -> V_10 ) ;
V_7 -> V_57 = F_3 ( V_24 -> V_58 ) ;
V_7 -> V_59 = F_3 ( V_24 -> V_59 ) ;
V_7 -> V_60 = F_3 ( V_24 -> V_60 ) ;
V_7 -> V_61 = F_3 ( V_24 -> V_61 ) ;
V_7 -> V_62 = F_3 ( F_30 ( V_24 -> V_62 ) ) ;
V_7 -> V_66 = F_5 ( F_65 ( V_24 -> V_66 ) ) ;
strncpy ( V_7 -> V_55 , V_24 -> V_55 , sizeof( V_7 -> V_55 ) ) ;
V_7 -> V_56 [ 0 ] = F_5 ( V_24 -> V_56 [ 0 ] ) ;
V_7 -> V_56 [ 1 ] = F_5 ( V_24 -> V_56 [ 1 ] ) ;
V_7 -> V_56 [ 2 ] = F_5 ( V_24 -> V_56 [ 2 ] ) ;
V_7 -> V_67 = F_5 ( V_24 -> V_89 . V_67 ) ;
V_7 -> V_68 = F_5 ( V_24 -> V_89 . V_68 ) ;
V_7 -> V_69 = F_5 ( V_24 -> V_89 . V_69 ) ;
V_7 -> V_70 = F_5 ( V_24 -> V_89 . V_70 ) ;
F_26 ( V_24 , V_7 ) ;
return F_31 ( V_24 -> V_43 , V_25 ) ;
}
static T_3 F_66 ( T_6 V_91 , unsigned V_10 )
{
T_7 V_92 = F_67 ( V_91 ) ;
V_92 <<= 16 ;
V_92 = V_92 | ( V_10 & V_93 ) ;
return F_3 ( V_92 ) ;
}
static void F_68 ( T_3 V_94 , T_6 * V_91 , unsigned * V_10 )
{
T_7 V_92 = F_11 ( V_94 ) ;
T_7 V_4 = V_92 >> 16 ;
* V_91 = F_69 ( V_4 ) ;
* V_10 = V_92 & V_93 ;
}
static struct V_23 * F_70 ( struct V_95 * V_50 ,
T_4 V_65 ,
bool V_85 ,
T_1 V_44 )
{
int V_31 ;
struct V_23 * V_24 ;
V_24 = F_71 ( sizeof( * V_24 ) , V_96 ) ;
if ( ! V_24 ) {
F_9 ( L_12 ) ;
return F_72 ( - V_97 ) ;
}
F_73 ( & V_24 -> V_98 , 1 ) ;
F_74 ( & V_24 -> V_99 ) ;
V_24 -> V_50 = V_50 ;
V_24 -> V_65 = V_65 ;
V_24 -> V_66 = 0 ;
V_24 -> V_44 = V_44 ;
V_24 -> V_90 = true ;
V_24 -> V_100 = false ;
V_31 = F_45 ( V_24 , V_85 ) ;
if ( V_31 ) {
F_75 ( V_24 ) ;
return F_72 ( V_31 ) ;
}
V_31 = F_59 ( V_24 , F_54 ) ;
if ( V_31 < 0 ) {
F_76 ( V_24 ) ;
return F_72 ( V_31 ) ;
}
return V_24 ;
}
static struct V_23 * F_77 ( struct V_95 * V_50 )
{
struct V_23 * V_24 ;
F_78 (cmd, &table, list)
if ( V_24 -> V_50 == V_50 ) {
F_79 ( & V_24 -> V_98 ) ;
return V_24 ;
}
return NULL ;
}
static struct V_23 * F_80 ( struct V_95 * V_50 ,
T_4 V_65 ,
bool V_85 ,
T_1 V_44 )
{
struct V_23 * V_24 , * V_101 ;
F_81 ( & V_102 ) ;
V_24 = F_77 ( V_50 ) ;
F_82 ( & V_102 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_70 ( V_50 , V_65 , V_85 , V_44 ) ;
if ( ! F_47 ( V_24 ) ) {
F_81 ( & V_102 ) ;
V_101 = F_77 ( V_50 ) ;
if ( V_101 ) {
F_82 ( & V_102 ) ;
F_50 ( V_24 ) ;
F_75 ( V_24 ) ;
return V_101 ;
}
F_83 ( & V_24 -> V_103 , & V_104 ) ;
F_82 ( & V_102 ) ;
}
return V_24 ;
}
static bool F_84 ( struct V_23 * V_24 , T_4 V_65 )
{
if ( V_24 -> V_65 != V_65 ) {
F_9 ( L_13 ,
( unsigned long long ) V_65 ,
( unsigned long long ) V_24 -> V_65 ) ;
return false ;
}
return true ;
}
struct V_23 * F_85 ( struct V_95 * V_50 ,
T_4 V_65 ,
bool V_85 ,
T_1 V_44 )
{
struct V_23 * V_24 = F_80 ( V_50 , V_65 ,
V_85 , V_44 ) ;
if ( ! F_47 ( V_24 ) && ! F_84 ( V_24 , V_65 ) ) {
F_76 ( V_24 ) ;
return F_72 ( - V_17 ) ;
}
return V_24 ;
}
void F_76 ( struct V_23 * V_24 )
{
if ( F_86 ( & V_24 -> V_98 ) ) {
F_81 ( & V_102 ) ;
F_87 ( & V_24 -> V_103 ) ;
F_82 ( & V_102 ) ;
if ( ! V_24 -> V_100 )
F_50 ( V_24 ) ;
F_75 ( V_24 ) ;
}
}
static int F_88 ( struct V_23 * V_24 , T_8 V_4 ,
bool * V_30 )
{
int V_31 ;
T_3 V_92 ;
T_6 V_105 ;
unsigned V_10 ;
V_31 = F_89 ( & V_24 -> V_42 , V_24 -> V_58 , F_65 ( V_4 ) , & V_92 ) ;
if ( V_31 ) {
F_9 ( L_14 ) ;
return V_31 ;
}
F_68 ( V_92 , & V_105 , & V_10 ) ;
* V_30 = ! ( ( V_10 & V_106 ) && ( V_10 & V_107 ) ) ;
return 0 ;
}
static int F_90 ( struct V_23 * V_24 ,
T_8 V_108 , T_8 V_109 ,
bool * V_30 )
{
int V_31 ;
* V_30 = true ;
while ( V_108 != V_109 ) {
V_31 = F_88 ( V_24 , V_108 , V_30 ) ;
if ( V_31 )
return V_31 ;
if ( ! * V_30 ) {
F_9 ( L_15 ,
( unsigned long long ) F_65 ( V_108 ) ) ;
return 0 ;
}
V_108 = F_58 ( F_65 ( V_108 ) + 1 ) ;
}
return 0 ;
}
int F_91 ( struct V_23 * V_24 , T_8 V_110 )
{
int V_31 ;
bool V_111 ;
T_3 V_112 = F_66 ( 0 , 0 ) ;
F_92 ( V_24 ) ;
F_93 ( & V_112 ) ;
if ( F_65 ( V_110 ) < F_65 ( V_24 -> V_66 ) ) {
V_31 = F_90 ( V_24 , V_110 , V_24 -> V_66 , & V_111 ) ;
if ( V_31 ) {
F_94 ( & V_112 ) ;
goto V_113;
}
if ( ! V_111 ) {
F_9 ( L_16 ) ;
V_31 = - V_17 ;
F_94 ( & V_112 ) ;
goto V_113;
}
}
V_31 = F_95 ( & V_24 -> V_42 , V_24 -> V_58 , F_65 ( V_24 -> V_66 ) ,
F_65 ( V_110 ) ,
& V_112 , & V_24 -> V_58 ) ;
if ( ! V_31 )
V_24 -> V_66 = V_110 ;
V_24 -> V_90 = true ;
V_113:
F_96 ( V_24 ) ;
return V_31 ;
}
int F_97 ( struct V_23 * V_24 ,
T_4 V_61 ,
T_9 V_114 )
{
int V_31 ;
F_92 ( V_24 ) ;
V_31 = F_98 ( & V_24 -> V_72 ,
V_24 -> V_60 ,
F_30 ( V_24 -> V_62 ) ,
F_30 ( V_114 ) ,
false , & V_24 -> V_60 ) ;
if ( ! V_31 ) {
V_24 -> V_61 = V_61 ;
V_24 -> V_62 = V_114 ;
}
V_24 -> V_90 = true ;
F_96 ( V_24 ) ;
return V_31 ;
}
static int F_99 ( struct V_23 * V_24 , T_9 V_4 )
{
return F_100 ( & V_24 -> V_72 , V_24 -> V_60 ,
F_30 ( V_4 ) , & V_24 -> V_60 ) ;
}
static int F_101 ( struct V_23 * V_24 , T_9 V_4 )
{
return F_102 ( & V_24 -> V_72 , V_24 -> V_60 ,
F_30 ( V_4 ) , & V_24 -> V_60 ) ;
}
static int F_103 ( struct V_23 * V_24 , T_9 V_4 ,
bool * V_115 )
{
return F_104 ( & V_24 -> V_72 , V_24 -> V_60 ,
F_30 ( V_4 ) , & V_24 -> V_60 ,
V_115 ) ;
}
static int F_105 ( struct V_23 * V_24 ,
T_9 V_116 , bool V_117 )
{
int V_31 ;
V_31 = ( V_117 ? F_99 : F_101 ) ( V_24 , V_116 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_90 = true ;
return 0 ;
}
int F_106 ( struct V_23 * V_24 ,
T_9 V_116 , bool V_117 )
{
int V_31 ;
F_92 ( V_24 ) ;
V_31 = F_105 ( V_24 , V_116 , V_117 ) ;
F_96 ( V_24 ) ;
return V_31 ;
}
static int F_107 ( struct V_23 * V_24 ,
T_10 V_118 , void * V_37 )
{
int V_31 = 0 ;
T_11 V_4 ;
bool V_117 ;
for ( V_4 = 0 ; V_4 < F_30 ( V_24 -> V_62 ) ; V_4 ++ ) {
T_9 V_116 = F_57 ( V_4 ) ;
if ( V_24 -> V_73 ) {
V_31 = F_103 ( V_24 , V_116 , & V_117 ) ;
if ( V_31 )
return V_31 ;
} else
V_117 = false ;
V_31 = V_118 ( V_37 , V_24 -> V_61 , V_116 , V_117 ) ;
if ( V_31 )
break;
}
return V_31 ;
}
int F_108 ( struct V_23 * V_24 ,
T_10 V_118 , void * V_37 )
{
int V_31 ;
F_109 ( & V_24 -> V_99 ) ;
V_31 = F_107 ( V_24 , V_118 , V_37 ) ;
F_110 ( & V_24 -> V_99 ) ;
return V_31 ;
}
T_8 F_111 ( struct V_23 * V_24 )
{
T_8 V_31 ;
F_109 ( & V_24 -> V_99 ) ;
V_31 = V_24 -> V_66 ;
F_110 ( & V_24 -> V_99 ) ;
return V_31 ;
}
static int F_112 ( struct V_23 * V_24 , T_8 V_119 )
{
int V_31 ;
T_3 V_92 = F_66 ( 0 , 0 ) ;
F_93 ( & V_92 ) ;
V_31 = F_113 ( & V_24 -> V_42 , V_24 -> V_58 , F_65 ( V_119 ) ,
& V_92 , & V_24 -> V_58 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_90 = true ;
return 0 ;
}
int F_114 ( struct V_23 * V_24 , T_8 V_119 )
{
int V_31 ;
F_92 ( V_24 ) ;
V_31 = F_112 ( V_24 , V_119 ) ;
F_96 ( V_24 ) ;
return V_31 ;
}
static int F_115 ( struct V_23 * V_24 ,
T_8 V_119 , T_6 V_120 )
{
int V_31 ;
T_3 V_92 = F_66 ( V_120 , V_106 ) ;
F_93 ( & V_92 ) ;
V_31 = F_113 ( & V_24 -> V_42 , V_24 -> V_58 , F_65 ( V_119 ) ,
& V_92 , & V_24 -> V_58 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_90 = true ;
return 0 ;
}
int F_116 ( struct V_23 * V_24 ,
T_8 V_119 , T_6 V_120 )
{
int V_31 ;
F_92 ( V_24 ) ;
V_31 = F_115 ( V_24 , V_119 , V_120 ) ;
F_96 ( V_24 ) ;
return V_31 ;
}
static bool F_117 ( struct V_23 * V_24 ,
struct V_121 * V_122 )
{
const char * V_55 = F_118 ( V_122 ) ;
const unsigned * V_56 = F_119 ( V_122 ) ;
T_1 V_44 = F_120 ( V_122 ) ;
if ( strncmp ( V_24 -> V_55 , V_55 , sizeof( V_24 -> V_55 ) ) )
return false ;
if ( V_24 -> V_56 [ 0 ] != V_56 [ 0 ] )
return false ;
if ( V_24 -> V_44 != V_44 )
return false ;
return true ;
}
static bool F_121 ( struct V_23 * V_24 )
{
return V_24 -> V_59 && V_24 -> V_44 ;
}
static bool F_122 ( struct V_23 * V_24 ,
struct V_121 * V_122 )
{
return V_24 -> V_73 && F_117 ( V_24 , V_122 ) &&
F_121 ( V_24 ) ;
}
static int F_123 ( void * V_37 , T_7 V_119 , void * V_123 )
{
int V_31 = 0 ;
bool V_124 ;
T_3 V_92 ;
V_11 V_125 = 0 ;
T_6 V_120 ;
unsigned V_10 ;
struct V_126 * V_126 = V_37 ;
struct V_23 * V_24 = V_126 -> V_24 ;
memcpy ( & V_92 , V_123 , sizeof( V_92 ) ) ;
F_68 ( V_92 , & V_120 , & V_10 ) ;
if ( V_10 & V_106 ) {
if ( V_126 -> V_127 ) {
V_31 = F_89 ( & V_24 -> V_45 , V_24 -> V_59 ,
V_119 , & V_125 ) ;
if ( V_31 && V_31 != - V_128 )
return V_31 ;
}
V_124 = V_126 -> V_129 ? ( V_10 & V_107 ) : true ;
V_31 = V_126 -> V_118 ( V_126 -> V_37 , V_120 , F_58 ( V_119 ) ,
V_124 , F_8 ( V_125 ) , V_126 -> V_127 ) ;
}
return V_31 ;
}
static int F_124 ( struct V_23 * V_24 ,
struct V_121 * V_122 ,
T_12 V_118 , void * V_37 )
{
struct V_126 V_126 ;
V_126 . V_118 = V_118 ;
V_126 . V_37 = V_37 ;
V_126 . V_24 = V_24 ;
V_126 . V_129 = V_24 -> V_73 ;
V_126 . V_127 = F_122 ( V_24 , V_122 ) ;
return F_125 ( & V_24 -> V_42 , V_24 -> V_58 , F_123 , & V_126 ) ;
}
int F_126 ( struct V_23 * V_24 ,
struct V_121 * V_122 ,
T_12 V_118 , void * V_37 )
{
int V_31 ;
F_109 ( & V_24 -> V_99 ) ;
V_31 = F_124 ( V_24 , V_122 , V_118 , V_37 ) ;
F_110 ( & V_24 -> V_99 ) ;
return V_31 ;
}
static int F_127 ( void * V_37 , T_7 V_119 , void * V_123 )
{
int V_31 = 0 ;
T_3 V_92 ;
T_6 V_120 ;
unsigned V_10 ;
memcpy ( & V_92 , V_123 , sizeof( V_92 ) ) ;
F_68 ( V_92 , & V_120 , & V_10 ) ;
return V_31 ;
}
static int F_128 ( struct V_23 * V_24 )
{
return F_125 ( & V_24 -> V_42 , V_24 -> V_58 , F_127 , NULL ) ;
}
void F_129 ( struct V_23 * V_24 )
{
F_109 ( & V_24 -> V_99 ) ;
F_128 ( V_24 ) ;
F_110 ( & V_24 -> V_99 ) ;
}
int F_130 ( struct V_23 * V_24 )
{
int V_31 ;
F_109 ( & V_24 -> V_99 ) ;
V_31 = V_24 -> V_90 ;
F_110 ( & V_24 -> V_99 ) ;
return V_31 ;
}
static int F_131 ( struct V_23 * V_24 , T_8 V_119 , bool V_124 )
{
int V_31 ;
unsigned V_10 ;
T_6 V_120 ;
T_3 V_92 ;
V_31 = F_89 ( & V_24 -> V_42 , V_24 -> V_58 , F_65 ( V_119 ) , & V_92 ) ;
if ( V_31 )
return V_31 ;
F_68 ( V_92 , & V_120 , & V_10 ) ;
if ( ( ( V_10 & V_107 ) && V_124 ) || ( ! ( V_10 & V_107 ) && ! V_124 ) )
return 0 ;
V_92 = F_66 ( V_120 , ( V_10 & ~ V_107 ) | ( V_124 ? V_107 : 0 ) ) ;
F_93 ( & V_92 ) ;
V_31 = F_113 ( & V_24 -> V_42 , V_24 -> V_58 , F_65 ( V_119 ) ,
& V_92 , & V_24 -> V_58 ) ;
if ( V_31 )
return V_31 ;
V_24 -> V_90 = true ;
return 0 ;
}
int F_132 ( struct V_23 * V_24 ,
T_8 V_119 , bool V_124 )
{
int V_31 ;
F_92 ( V_24 ) ;
V_31 = F_131 ( V_24 , V_119 , V_124 ) ;
F_96 ( V_24 ) ;
return V_31 ;
}
void F_133 ( struct V_23 * V_24 ,
struct V_130 * V_89 )
{
F_109 ( & V_24 -> V_99 ) ;
* V_89 = V_24 -> V_89 ;
F_110 ( & V_24 -> V_99 ) ;
}
void F_134 ( struct V_23 * V_24 ,
struct V_130 * V_89 )
{
F_135 ( V_24 ) ;
V_24 -> V_89 = * V_89 ;
F_96 ( V_24 ) ;
}
int F_136 ( struct V_23 * V_24 , bool V_131 )
{
int V_31 ;
T_5 V_88 = ( V_131 ? F_52 :
F_54 ) ;
F_92 ( V_24 ) ;
V_31 = F_62 ( V_24 , V_88 ) ;
if ( V_31 )
goto V_113;
V_31 = F_61 ( V_24 ) ;
V_113:
F_96 ( V_24 ) ;
return V_31 ;
}
int F_137 ( struct V_23 * V_24 ,
T_11 * V_30 )
{
int V_31 = - V_17 ;
F_109 ( & V_24 -> V_99 ) ;
V_31 = F_138 ( V_24 -> V_47 , V_30 ) ;
F_110 ( & V_24 -> V_99 ) ;
return V_31 ;
}
int F_139 ( struct V_23 * V_24 ,
T_11 * V_30 )
{
int V_31 = - V_17 ;
F_109 ( & V_24 -> V_99 ) ;
V_31 = F_140 ( V_24 -> V_47 , V_30 ) ;
F_110 ( & V_24 -> V_99 ) ;
return V_31 ;
}
static int F_141 ( struct V_23 * V_24 , struct V_121 * V_122 )
{
int V_31 ;
V_11 V_92 ;
T_1 V_132 ;
const char * V_55 = F_118 ( V_122 ) ;
const unsigned * V_56 = F_119 ( V_122 ) ;
if ( ! V_55 [ 0 ] ||
( strlen ( V_55 ) > sizeof( V_24 -> V_55 ) - 1 ) )
return - V_17 ;
if ( ! F_117 ( V_24 , V_122 ) ) {
strncpy ( V_24 -> V_55 , V_55 , sizeof( V_24 -> V_55 ) ) ;
memcpy ( V_24 -> V_56 , V_56 , sizeof( V_24 -> V_56 ) ) ;
V_132 = F_120 ( V_122 ) ;
if ( ! V_132 )
return 0 ;
V_24 -> V_44 = V_132 ;
if ( V_24 -> V_59 ) {
V_31 = F_142 ( & V_24 -> V_45 , V_24 -> V_59 ) ;
if ( V_31 )
return V_31 ;
}
V_31 = F_34 ( & V_24 -> V_45 , & V_24 -> V_59 ) ;
if ( V_31 )
return V_31 ;
V_92 = F_5 ( 0 ) ;
F_93 ( & V_92 ) ;
V_31 = F_95 ( & V_24 -> V_45 , V_24 -> V_59 , 0 ,
F_65 ( V_24 -> V_66 ) ,
& V_92 , & V_24 -> V_59 ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
static int F_143 ( void * V_37 , T_8 V_119 , T_6 V_120 , T_2 V_133 )
{
struct V_23 * V_24 = V_37 ;
V_11 V_92 = F_5 ( V_133 ) ;
int V_31 ;
F_93 ( & V_92 ) ;
V_31 = F_113 ( & V_24 -> V_45 , V_24 -> V_59 ,
F_65 ( V_119 ) , & V_92 , & V_24 -> V_59 ) ;
V_24 -> V_90 = true ;
return V_31 ;
}
static int F_144 ( struct V_23 * V_24 , struct V_121 * V_122 )
{
int V_31 ;
V_31 = F_141 ( V_24 , V_122 ) ;
if ( V_31 ) {
F_9 ( L_17 ) ;
return V_31 ;
}
return F_145 ( V_122 , F_143 , V_24 ) ;
}
int F_146 ( struct V_23 * V_24 , struct V_121 * V_122 )
{
int V_31 ;
F_92 ( V_24 ) ;
V_31 = F_144 ( V_24 , V_122 ) ;
F_96 ( V_24 ) ;
return V_31 ;
}
int F_147 ( struct V_23 * V_24 , bool * V_30 )
{
return F_90 ( V_24 , 0 , V_24 -> V_66 , V_30 ) ;
}
void F_148 ( struct V_23 * V_24 )
{
F_135 ( V_24 ) ;
F_149 ( V_24 -> V_26 ) ;
F_96 ( V_24 ) ;
}
void F_150 ( struct V_23 * V_24 )
{
F_135 ( V_24 ) ;
F_151 ( V_24 -> V_26 ) ;
F_96 ( V_24 ) ;
}
int F_152 ( struct V_23 * V_24 )
{
int V_31 ;
struct V_3 * V_25 ;
struct V_6 * V_7 ;
F_153 ( & V_24 -> V_99 ) ;
F_53 ( V_134 , & V_24 -> V_10 ) ;
V_31 = F_16 ( V_24 , & V_25 ) ;
if ( V_31 ) {
F_9 ( L_18 ) ;
goto V_113;
}
V_7 = F_2 ( V_25 ) ;
V_7 -> V_10 = F_5 ( V_24 -> V_10 ) ;
F_20 ( V_25 ) ;
V_113:
F_154 ( & V_24 -> V_99 ) ;
return V_31 ;
}
bool F_155 ( struct V_23 * V_24 )
{
bool V_135 ;
F_109 ( & V_24 -> V_99 ) ;
V_135 = ! ! F_43 ( V_134 , & V_24 -> V_10 ) ;
F_110 ( & V_24 -> V_99 ) ;
return V_135 ;
}
int F_156 ( struct V_23 * V_24 )
{
int V_31 ;
F_92 ( V_24 ) ;
F_50 ( V_24 ) ;
V_31 = F_45 ( V_24 , false ) ;
if ( V_31 )
V_24 -> V_100 = true ;
F_96 ( V_24 ) ;
return V_31 ;
}
