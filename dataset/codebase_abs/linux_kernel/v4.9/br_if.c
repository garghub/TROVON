static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( ! F_2 ( V_2 , & V_4 ) ) {
switch ( V_4 . V_5 . V_6 ) {
case V_7 :
return 2 ;
case V_8 :
return 4 ;
case V_9 :
return 19 ;
case V_10 :
return 100 ;
}
}
if ( ! strncmp ( V_2 -> V_11 , L_1 , 3 ) )
return 7 ;
if ( ! strncmp ( V_2 -> V_11 , L_2 , 4 ) )
return 2500 ;
return 100 ;
}
void F_3 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_14 * V_15 = V_13 -> V_15 ;
if ( ! ( V_13 -> V_16 & V_17 ) &&
F_4 ( V_2 ) && F_5 ( V_2 ) )
V_13 -> V_18 = F_1 ( V_2 ) ;
if ( ! F_4 ( V_15 -> V_2 ) )
return;
F_6 ( & V_15 -> V_19 ) ;
if ( F_4 ( V_2 ) && F_5 ( V_2 ) ) {
if ( V_13 -> V_20 == V_21 )
F_7 ( V_13 ) ;
} else {
if ( V_13 -> V_20 != V_21 )
F_8 ( V_13 ) ;
}
F_9 ( & V_15 -> V_19 ) ;
}
static void F_10 ( struct V_12 * V_13 )
{
int V_22 = 0 ;
if ( F_11 ( V_13 ) )
return;
V_22 = F_12 ( V_13 -> V_2 , 1 ) ;
if ( V_22 )
return;
F_13 ( V_13 -> V_15 , V_13 ) ;
V_13 -> V_16 |= V_23 ;
}
static void F_14 ( struct V_12 * V_13 )
{
int V_22 ;
if ( ! F_11 ( V_13 ) || ! ( V_13 -> V_2 -> V_24 & V_25 ) )
return;
V_22 = F_15 ( V_13 -> V_15 , V_13 ) ;
if ( V_22 )
return;
F_12 ( V_13 -> V_2 , - 1 ) ;
V_13 -> V_16 &= ~ V_23 ;
}
void F_16 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
bool V_26 = false ;
if ( ( V_15 -> V_2 -> V_16 & V_27 ) || ! F_17 ( V_15 ) )
V_26 = true ;
F_18 (p, &br->port_list, list) {
if ( V_26 ) {
F_10 ( V_13 ) ;
} else {
if ( V_15 -> V_28 == 0 ||
( V_15 -> V_28 == 1 && F_19 ( V_13 ) ) )
F_14 ( V_13 ) ;
else
F_10 ( V_13 ) ;
}
}
}
static void F_20 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
T_1 V_29 = 0 ;
F_18 (p, &br->port_list, list) {
if ( F_19 ( V_13 ) )
V_29 ++ ;
}
if ( V_15 -> V_28 != V_29 ) {
V_15 -> V_28 = V_29 ;
F_16 ( V_15 ) ;
}
}
static void F_21 ( struct V_12 * V_13 )
{
F_22 ( V_13 -> V_2 , - 1 ) ;
if ( F_11 ( V_13 ) )
F_12 ( V_13 -> V_2 , - 1 ) ;
else
F_13 ( V_13 -> V_15 , V_13 ) ;
}
static void F_23 ( struct V_30 * V_31 )
{
struct V_12 * V_13
= F_24 ( V_31 , struct V_12 , V_31 ) ;
F_25 ( V_13 ) ;
}
static void F_26 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
V_13 -> V_15 = NULL ;
V_13 -> V_2 = NULL ;
F_27 ( V_2 ) ;
F_28 ( & V_13 -> V_31 ) ;
}
static void F_29 ( struct V_32 * V_33 )
{
struct V_12 * V_13 =
F_24 ( V_33 , struct V_12 , V_34 ) ;
F_26 ( V_13 ) ;
}
static unsigned F_30 ( struct V_14 * V_15 )
{
unsigned V_35 = 0 ;
struct V_12 * V_13 ;
F_18 (p, &br->port_list, list) {
unsigned V_36 = F_31 ( V_13 -> V_2 ) ;
if ( V_36 > V_35 )
V_35 = V_36 ;
}
return V_35 ;
}
static void F_32 ( struct V_14 * V_15 , int V_37 )
{
struct V_12 * V_13 ;
F_18 (p, &br->port_list, list)
F_33 ( V_13 -> V_2 , V_37 ) ;
V_15 -> V_2 -> V_38 = V_37 ;
}
static void F_34 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_1 * V_2 = V_13 -> V_2 ;
F_35 ( V_15 -> V_39 , V_13 -> V_2 -> V_11 ) ;
F_21 ( V_13 ) ;
F_6 ( & V_15 -> V_19 ) ;
F_8 ( V_13 ) ;
F_9 ( & V_15 -> V_19 ) ;
F_36 ( V_40 , V_13 ) ;
F_37 ( & V_13 -> V_41 ) ;
if ( F_31 ( V_2 ) == V_15 -> V_2 -> V_38 )
F_32 ( V_15 , F_30 ( V_15 ) ) ;
F_38 ( V_2 ) ;
F_39 ( V_13 ) ;
F_40 ( V_15 , V_13 , 0 , 1 ) ;
F_41 () ;
F_20 ( V_15 ) ;
F_42 ( V_2 , V_15 -> V_2 ) ;
V_2 -> V_24 &= ~ V_42 ;
F_43 ( V_2 ) ;
F_44 ( V_13 ) ;
F_45 ( & V_13 -> V_31 , V_43 ) ;
F_46 ( & V_13 -> V_31 ) ;
F_47 ( V_13 ) ;
F_48 ( & V_13 -> V_34 , F_29 ) ;
}
void F_49 ( struct V_1 * V_2 , struct V_44 * V_33 )
{
struct V_14 * V_15 = F_50 ( V_2 ) ;
struct V_12 * V_13 , * V_45 ;
F_51 (p, n, &br->port_list, list) {
F_34 ( V_13 ) ;
}
F_40 ( V_15 , NULL , 0 , 1 ) ;
F_52 ( V_15 ) ;
F_53 ( V_15 ) ;
F_54 ( & V_15 -> V_46 ) ;
F_55 ( V_15 -> V_2 ) ;
F_56 ( V_15 -> V_2 , V_33 ) ;
}
static int F_57 ( struct V_14 * V_15 )
{
int V_47 ;
struct V_12 * V_13 ;
unsigned long * V_48 ;
V_48 = F_58 ( F_59 ( V_49 ) , sizeof( unsigned long ) ,
V_50 ) ;
if ( ! V_48 )
return - V_51 ;
F_60 ( 0 , V_48 ) ;
F_18 (p, &br->port_list, list) {
F_60 ( V_13 -> V_52 , V_48 ) ;
}
V_47 = F_61 ( V_48 , V_49 ) ;
F_25 ( V_48 ) ;
return ( V_47 >= V_49 ) ? - V_53 : V_47 ;
}
static struct V_12 * F_62 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_47 , V_22 ;
V_47 = F_57 ( V_15 ) ;
if ( V_47 < 0 )
return F_63 ( V_47 ) ;
V_13 = F_64 ( sizeof( * V_13 ) , V_50 ) ;
if ( V_13 == NULL )
return F_63 ( - V_51 ) ;
V_13 -> V_15 = V_15 ;
F_65 ( V_2 ) ;
V_13 -> V_2 = V_2 ;
V_13 -> V_18 = F_1 ( V_2 ) ;
V_13 -> V_54 = 0x8000 >> V_55 ;
V_13 -> V_52 = V_47 ;
V_13 -> V_16 = V_56 | V_57 | V_58 ;
F_66 ( V_13 ) ;
F_67 ( V_13 , V_21 ) ;
F_68 ( V_13 ) ;
V_22 = F_69 ( V_13 ) ;
if ( V_22 ) {
F_27 ( V_2 ) ;
F_25 ( V_13 ) ;
V_13 = F_63 ( V_22 ) ;
}
return V_13 ;
}
int F_70 ( struct V_59 * V_59 , const char * V_11 )
{
struct V_1 * V_2 ;
int V_60 ;
V_2 = F_71 ( sizeof( struct V_14 ) , V_11 , V_61 ,
V_62 ) ;
if ( ! V_2 )
return - V_51 ;
F_72 ( V_2 , V_59 ) ;
V_2 -> V_63 = & V_64 ;
V_60 = F_73 ( V_2 ) ;
if ( V_60 )
F_74 ( V_2 ) ;
return V_60 ;
}
int F_75 ( struct V_59 * V_59 , const char * V_11 )
{
struct V_1 * V_2 ;
int V_65 = 0 ;
F_76 () ;
V_2 = F_77 ( V_59 , V_11 ) ;
if ( V_2 == NULL )
V_65 = - V_66 ;
else if ( ! ( V_2 -> V_24 & V_67 ) ) {
V_65 = - V_68 ;
}
else if ( V_2 -> V_16 & V_69 ) {
V_65 = - V_70 ;
}
else
F_49 ( V_2 , NULL ) ;
F_78 () ;
return V_65 ;
}
int F_79 ( const struct V_14 * V_15 )
{
const struct V_12 * V_13 ;
int V_71 = 0 ;
F_80 () ;
if ( F_81 ( & V_15 -> V_72 ) )
V_71 = V_73 ;
else {
F_18 (p, &br->port_list, list) {
if ( ! V_71 || V_13 -> V_2 -> V_71 < V_71 )
V_71 = V_13 -> V_2 -> V_71 ;
}
}
return V_71 ;
}
static void F_82 ( struct V_14 * V_15 )
{
unsigned int V_74 = V_75 ;
T_2 V_76 = V_77 ;
const struct V_12 * V_13 ;
F_18 (p, &br->port_list, list) {
V_74 = F_83 ( V_74 , V_13 -> V_2 -> V_74 ) ;
V_76 = F_83 ( V_76 , V_13 -> V_2 -> V_76 ) ;
}
V_15 -> V_2 -> V_74 = V_74 ;
V_15 -> V_2 -> V_76 = V_76 ;
}
T_3 F_84 ( struct V_14 * V_15 ,
T_3 V_78 )
{
struct V_12 * V_13 ;
T_3 V_79 ;
if ( F_81 ( & V_15 -> V_72 ) )
return V_78 ;
V_79 = V_78 ;
V_78 &= ~ V_80 ;
F_18 (p, &br->port_list, list) {
V_78 = F_85 ( V_78 ,
V_13 -> V_2 -> V_78 , V_79 ) ;
}
V_78 = F_86 ( V_78 , V_79 ) ;
return V_78 ;
}
int F_87 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_22 = 0 ;
unsigned V_81 , V_82 ;
bool V_83 ;
if ( ( V_2 -> V_16 & V_84 ) ||
V_2 -> type != V_85 || V_2 -> V_86 != V_87 ||
! F_88 ( V_2 -> V_88 ) ||
F_89 ( V_2 ) )
return - V_89 ;
if ( V_2 -> V_90 -> V_91 == V_92 )
return - V_93 ;
if ( F_90 ( V_2 ) )
return - V_70 ;
if ( V_2 -> V_24 & V_94 )
return - V_95 ;
V_13 = F_62 ( V_15 , V_2 ) ;
if ( F_91 ( V_13 ) )
return F_92 ( V_13 ) ;
F_93 ( V_96 , V_2 ) ;
V_22 = F_22 ( V_2 , 1 ) ;
if ( V_22 )
goto V_97;
V_22 = F_94 ( & V_13 -> V_31 , & V_98 , & ( V_2 -> V_2 . V_31 ) ,
V_99 ) ;
if ( V_22 )
goto V_100;
V_22 = F_95 ( V_13 ) ;
if ( V_22 )
goto V_101;
V_22 = F_96 ( V_13 ) ;
if ( V_22 )
goto V_102;
V_22 = F_97 ( V_2 , V_103 , V_13 ) ;
if ( V_22 )
goto V_104;
V_2 -> V_24 |= V_42 ;
V_22 = F_98 ( V_2 , V_15 -> V_2 , NULL , NULL ) ;
if ( V_22 )
goto V_105;
V_22 = F_99 ( V_13 ) ;
if ( V_22 )
goto V_106;
F_100 ( V_2 ) ;
F_101 ( & V_13 -> V_41 , & V_15 -> V_72 ) ;
F_20 ( V_15 ) ;
F_102 ( V_15 -> V_2 ) ;
V_81 = V_15 -> V_2 -> V_38 ;
V_82 = F_31 ( V_2 ) ;
if ( V_81 < V_82 )
F_32 ( V_15 , V_82 ) ;
else
F_33 ( V_2 , V_81 ) ;
if ( F_103 ( V_15 , V_13 , V_2 -> V_88 , 0 ) )
F_104 ( V_2 , L_3 ) ;
V_22 = F_105 ( V_13 ) ;
if ( V_22 ) {
F_104 ( V_2 , L_4 ) ;
goto V_107;
}
F_6 ( & V_15 -> V_19 ) ;
V_83 = F_106 ( V_15 ) ;
if ( F_4 ( V_2 ) && F_5 ( V_2 ) &&
( V_15 -> V_2 -> V_16 & V_69 ) )
F_7 ( V_13 ) ;
F_9 ( & V_15 -> V_19 ) ;
F_36 ( V_108 , V_13 ) ;
if ( V_83 )
F_93 ( V_109 , V_15 -> V_2 ) ;
F_107 ( V_15 -> V_2 , F_79 ( V_15 ) ) ;
F_82 ( V_15 ) ;
F_45 ( & V_13 -> V_31 , V_110 ) ;
return 0 ;
V_107:
F_37 ( & V_13 -> V_41 ) ;
F_40 ( V_15 , V_13 , 0 , 1 ) ;
F_20 ( V_15 ) ;
V_106:
F_42 ( V_2 , V_15 -> V_2 ) ;
V_105:
V_2 -> V_24 &= ~ V_42 ;
F_43 ( V_2 ) ;
V_104:
F_47 ( V_13 ) ;
V_102:
F_35 ( V_15 -> V_39 , V_13 -> V_2 -> V_11 ) ;
V_101:
F_28 ( & V_13 -> V_31 ) ;
V_13 = NULL ;
V_100:
F_22 ( V_2 , - 1 ) ;
V_97:
F_27 ( V_2 ) ;
F_25 ( V_13 ) ;
return V_22 ;
}
int F_108 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_12 * V_13 ;
bool V_83 ;
V_13 = F_109 ( V_2 ) ;
if ( ! V_13 || V_13 -> V_15 != V_15 )
return - V_89 ;
F_34 ( V_13 ) ;
F_107 ( V_15 -> V_2 , F_79 ( V_15 ) ) ;
F_82 ( V_15 ) ;
F_6 ( & V_15 -> V_19 ) ;
V_83 = F_106 ( V_15 ) ;
F_9 ( & V_15 -> V_19 ) ;
if ( V_83 )
F_93 ( V_109 , V_15 -> V_2 ) ;
F_102 ( V_15 -> V_2 ) ;
return 0 ;
}
void F_110 ( struct V_12 * V_13 , unsigned long V_79 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
if ( V_79 & V_111 )
F_20 ( V_15 ) ;
}
