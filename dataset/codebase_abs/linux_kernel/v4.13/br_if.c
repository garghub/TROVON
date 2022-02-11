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
if ( ( V_15 -> V_2 -> V_16 & V_27 ) || ! F_17 ( V_15 -> V_2 ) )
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
F_52 ( & V_15 -> V_46 ) ;
F_53 ( V_15 -> V_2 ) ;
F_54 ( V_15 -> V_2 , V_33 ) ;
}
static int F_55 ( struct V_14 * V_15 )
{
int V_47 ;
struct V_12 * V_13 ;
unsigned long * V_48 ;
V_48 = F_56 ( F_57 ( V_49 ) , sizeof( unsigned long ) ,
V_50 ) ;
if ( ! V_48 )
return - V_51 ;
F_58 ( 0 , V_48 ) ;
F_18 (p, &br->port_list, list) {
F_58 ( V_13 -> V_52 , V_48 ) ;
}
V_47 = F_59 ( V_48 , V_49 ) ;
F_25 ( V_48 ) ;
return ( V_47 >= V_49 ) ? - V_53 : V_47 ;
}
static struct V_12 * F_60 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_47 , V_22 ;
V_47 = F_55 ( V_15 ) ;
if ( V_47 < 0 )
return F_61 ( V_47 ) ;
V_13 = F_62 ( sizeof( * V_13 ) , V_50 ) ;
if ( V_13 == NULL )
return F_61 ( - V_51 ) ;
V_13 -> V_15 = V_15 ;
F_63 ( V_2 ) ;
V_13 -> V_2 = V_2 ;
V_13 -> V_18 = F_1 ( V_2 ) ;
V_13 -> V_54 = 0x8000 >> V_55 ;
V_13 -> V_52 = V_47 ;
V_13 -> V_16 = V_56 | V_57 | V_58 | V_59 ;
F_64 ( V_13 ) ;
F_65 ( V_13 , V_21 ) ;
F_66 ( V_13 ) ;
V_22 = F_67 ( V_13 ) ;
if ( V_22 ) {
F_27 ( V_2 ) ;
F_25 ( V_13 ) ;
V_13 = F_61 ( V_22 ) ;
}
return V_13 ;
}
int F_68 ( struct V_60 * V_60 , const char * V_11 )
{
struct V_1 * V_2 ;
int V_61 ;
V_2 = F_69 ( sizeof( struct V_14 ) , V_11 , V_62 ,
V_63 ) ;
if ( ! V_2 )
return - V_51 ;
F_70 ( V_2 , V_60 ) ;
V_2 -> V_64 = & V_65 ;
V_61 = F_71 ( V_2 ) ;
if ( V_61 )
F_72 ( V_2 ) ;
return V_61 ;
}
int F_73 ( struct V_60 * V_60 , const char * V_11 )
{
struct V_1 * V_2 ;
int V_66 = 0 ;
F_74 () ;
V_2 = F_75 ( V_60 , V_11 ) ;
if ( V_2 == NULL )
V_66 = - V_67 ;
else if ( ! ( V_2 -> V_24 & V_68 ) ) {
V_66 = - V_69 ;
}
else if ( V_2 -> V_16 & V_70 ) {
V_66 = - V_71 ;
}
else
F_49 ( V_2 , NULL ) ;
F_76 () ;
return V_66 ;
}
int F_77 ( const struct V_14 * V_15 )
{
const struct V_12 * V_13 ;
int V_72 = 0 ;
F_78 () ;
if ( F_79 ( & V_15 -> V_73 ) )
V_72 = V_74 ;
else {
F_18 (p, &br->port_list, list) {
if ( ! V_72 || V_13 -> V_2 -> V_72 < V_72 )
V_72 = V_13 -> V_2 -> V_72 ;
}
}
return V_72 ;
}
static void F_80 ( struct V_14 * V_15 )
{
unsigned int V_75 = V_76 ;
T_2 V_77 = V_78 ;
const struct V_12 * V_13 ;
F_18 (p, &br->port_list, list) {
V_75 = F_81 ( V_75 , V_13 -> V_2 -> V_75 ) ;
V_77 = F_81 ( V_77 , V_13 -> V_2 -> V_77 ) ;
}
V_15 -> V_2 -> V_75 = V_75 ;
V_15 -> V_2 -> V_77 = V_77 ;
}
T_3 F_82 ( struct V_14 * V_15 ,
T_3 V_79 )
{
struct V_12 * V_13 ;
T_3 V_80 ;
if ( F_79 ( & V_15 -> V_73 ) )
return V_79 ;
V_80 = V_79 ;
V_79 &= ~ V_81 ;
F_18 (p, &br->port_list, list) {
V_79 = F_83 ( V_79 ,
V_13 -> V_2 -> V_79 , V_80 ) ;
}
V_79 = F_84 ( V_79 , V_80 ) ;
return V_79 ;
}
int F_85 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_12 * V_13 ;
int V_22 = 0 ;
unsigned V_82 , V_83 ;
bool V_84 ;
if ( ( V_2 -> V_16 & V_85 ) ||
V_2 -> type != V_86 || V_2 -> V_87 != V_88 ||
! F_86 ( V_2 -> V_89 ) ||
F_87 ( V_2 ) )
return - V_90 ;
if ( V_2 -> V_91 -> V_92 == V_93 )
return - V_94 ;
if ( F_88 ( V_2 ) )
return - V_71 ;
if ( V_2 -> V_24 & V_95 )
return - V_96 ;
V_13 = F_60 ( V_15 , V_2 ) ;
if ( F_89 ( V_13 ) )
return F_90 ( V_13 ) ;
F_91 ( V_97 , V_2 ) ;
V_22 = F_22 ( V_2 , 1 ) ;
if ( V_22 )
goto V_98;
V_22 = F_92 ( & V_13 -> V_31 , & V_99 , & ( V_2 -> V_2 . V_31 ) ,
V_100 ) ;
if ( V_22 )
goto V_101;
V_22 = F_93 ( V_13 ) ;
if ( V_22 )
goto V_102;
V_22 = F_94 ( V_13 ) ;
if ( V_22 )
goto V_103;
V_22 = F_95 ( V_2 , V_104 , V_13 ) ;
if ( V_22 )
goto V_105;
V_2 -> V_24 |= V_42 ;
V_22 = F_96 ( V_2 , V_15 -> V_2 , NULL , NULL ) ;
if ( V_22 )
goto V_106;
V_22 = F_97 ( V_13 ) ;
if ( V_22 )
goto V_107;
F_98 ( V_2 ) ;
F_99 ( & V_13 -> V_41 , & V_15 -> V_73 ) ;
F_20 ( V_15 ) ;
F_100 ( V_15 -> V_2 ) ;
V_82 = V_15 -> V_2 -> V_38 ;
V_83 = F_31 ( V_2 ) ;
if ( V_82 < V_83 )
F_32 ( V_15 , V_83 ) ;
else
F_33 ( V_2 , V_82 ) ;
if ( F_101 ( V_15 , V_13 , V_2 -> V_89 , 0 ) )
F_102 ( V_2 , L_3 ) ;
V_22 = F_103 ( V_13 ) ;
if ( V_22 ) {
F_102 ( V_2 , L_4 ) ;
goto V_108;
}
F_6 ( & V_15 -> V_19 ) ;
V_84 = F_104 ( V_15 ) ;
if ( F_4 ( V_2 ) && F_5 ( V_2 ) &&
( V_15 -> V_2 -> V_16 & V_70 ) )
F_7 ( V_13 ) ;
F_9 ( & V_15 -> V_19 ) ;
F_36 ( V_109 , V_13 ) ;
if ( V_84 )
F_91 ( V_110 , V_15 -> V_2 ) ;
F_105 ( V_15 -> V_2 , F_77 ( V_15 ) ) ;
F_80 ( V_15 ) ;
F_45 ( & V_13 -> V_31 , V_111 ) ;
return 0 ;
V_108:
F_37 ( & V_13 -> V_41 ) ;
F_40 ( V_15 , V_13 , 0 , 1 ) ;
F_20 ( V_15 ) ;
V_107:
F_42 ( V_2 , V_15 -> V_2 ) ;
V_106:
V_2 -> V_24 &= ~ V_42 ;
F_43 ( V_2 ) ;
V_105:
F_47 ( V_13 ) ;
V_103:
F_35 ( V_15 -> V_39 , V_13 -> V_2 -> V_11 ) ;
V_102:
F_28 ( & V_13 -> V_31 ) ;
V_13 = NULL ;
V_101:
F_22 ( V_2 , - 1 ) ;
V_98:
F_27 ( V_2 ) ;
F_25 ( V_13 ) ;
return V_22 ;
}
int F_106 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_12 * V_13 ;
bool V_84 ;
V_13 = F_107 ( V_2 ) ;
if ( ! V_13 || V_13 -> V_15 != V_15 )
return - V_90 ;
F_34 ( V_13 ) ;
F_105 ( V_15 -> V_2 , F_77 ( V_15 ) ) ;
F_80 ( V_15 ) ;
F_6 ( & V_15 -> V_19 ) ;
V_84 = F_104 ( V_15 ) ;
F_9 ( & V_15 -> V_19 ) ;
if ( V_84 )
F_91 ( V_110 , V_15 -> V_2 ) ;
F_100 ( V_15 -> V_2 ) ;
return 0 ;
}
void F_108 ( struct V_12 * V_13 , unsigned long V_80 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
if ( V_80 & V_112 )
F_20 ( V_15 ) ;
}
