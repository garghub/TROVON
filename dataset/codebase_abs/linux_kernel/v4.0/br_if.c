static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( ! F_2 ( V_2 , & V_4 ) ) {
switch ( F_3 ( & V_4 ) ) {
case V_5 :
return 2 ;
case V_6 :
return 4 ;
case V_7 :
return 19 ;
case V_8 :
return 100 ;
}
}
if ( ! strncmp ( V_2 -> V_9 , L_1 , 3 ) )
return 7 ;
if ( ! strncmp ( V_2 -> V_9 , L_2 , 4 ) )
return 2500 ;
return 100 ;
}
void F_4 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_12 * V_13 = V_11 -> V_13 ;
if ( ! ( V_11 -> V_14 & V_15 ) &&
F_5 ( V_2 ) && F_6 ( V_2 ) )
V_11 -> V_16 = F_1 ( V_2 ) ;
if ( ! F_5 ( V_13 -> V_2 ) )
return;
F_7 ( & V_13 -> V_17 ) ;
if ( F_5 ( V_2 ) && F_6 ( V_2 ) ) {
if ( V_11 -> V_18 == V_19 )
F_8 ( V_11 ) ;
} else {
if ( V_11 -> V_18 != V_19 )
F_9 ( V_11 ) ;
}
F_10 ( & V_13 -> V_17 ) ;
}
static void F_11 ( struct V_10 * V_11 )
{
int V_20 = 0 ;
if ( F_12 ( V_11 ) )
return;
V_20 = F_13 ( V_11 -> V_2 , 1 ) ;
if ( V_20 )
return;
F_14 ( V_11 -> V_13 , V_11 ) ;
V_11 -> V_14 |= V_21 ;
}
static void F_15 ( struct V_10 * V_11 )
{
int V_20 ;
if ( ! F_12 ( V_11 ) || ! ( V_11 -> V_2 -> V_22 & V_23 ) )
return;
V_20 = F_16 ( V_11 -> V_13 , V_11 ) ;
if ( V_20 )
return;
F_13 ( V_11 -> V_2 , - 1 ) ;
V_11 -> V_14 &= ~ V_21 ;
}
void F_17 ( struct V_12 * V_13 )
{
struct V_10 * V_11 ;
bool V_24 = false ;
if ( ( V_13 -> V_2 -> V_14 & V_25 ) || ! F_18 ( V_13 ) )
V_24 = true ;
F_19 (p, &br->port_list, list) {
if ( V_24 ) {
F_11 ( V_11 ) ;
} else {
if ( V_13 -> V_26 == 0 ||
( V_13 -> V_26 == 1 && F_20 ( V_11 ) ) )
F_15 ( V_11 ) ;
else
F_11 ( V_11 ) ;
}
}
}
static void F_21 ( struct V_12 * V_13 )
{
struct V_10 * V_11 ;
T_1 V_27 = 0 ;
F_19 (p, &br->port_list, list) {
if ( F_20 ( V_11 ) )
V_27 ++ ;
}
if ( V_13 -> V_26 != V_27 ) {
V_13 -> V_26 = V_27 ;
F_17 ( V_13 ) ;
}
}
static void F_22 ( struct V_10 * V_11 )
{
F_23 ( V_11 -> V_2 , - 1 ) ;
if ( F_12 ( V_11 ) )
F_13 ( V_11 -> V_2 , - 1 ) ;
else
F_14 ( V_11 -> V_13 , V_11 ) ;
}
static void F_24 ( struct V_28 * V_29 )
{
struct V_10 * V_11
= F_25 ( V_29 , struct V_10 , V_29 ) ;
F_26 ( V_11 ) ;
}
static void F_27 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
V_11 -> V_13 = NULL ;
V_11 -> V_2 = NULL ;
F_28 ( V_2 ) ;
F_29 ( & V_11 -> V_29 ) ;
}
static void F_30 ( struct V_30 * V_31 )
{
struct V_10 * V_11 =
F_25 ( V_31 , struct V_10 , V_32 ) ;
F_27 ( V_11 ) ;
}
static void F_31 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_32 ( V_13 -> V_33 , V_11 -> V_2 -> V_9 ) ;
F_22 ( V_11 ) ;
F_7 ( & V_13 -> V_17 ) ;
F_9 ( V_11 ) ;
F_10 ( & V_13 -> V_17 ) ;
F_33 ( V_34 , V_11 ) ;
F_34 ( & V_11 -> V_35 ) ;
F_35 ( V_11 ) ;
F_36 ( V_13 , V_11 , 1 ) ;
F_21 ( V_13 ) ;
F_37 ( V_2 , V_13 -> V_2 ) ;
V_2 -> V_22 &= ~ V_36 ;
F_38 ( V_2 ) ;
F_39 ( V_11 ) ;
F_40 ( & V_11 -> V_29 , V_37 ) ;
F_41 ( & V_11 -> V_29 ) ;
F_42 ( V_11 ) ;
F_43 ( & V_11 -> V_32 , F_30 ) ;
}
void F_44 ( struct V_1 * V_2 , struct V_38 * V_31 )
{
struct V_12 * V_13 = F_45 ( V_2 ) ;
struct V_10 * V_11 , * V_39 ;
F_46 (p, n, &br->port_list, list) {
F_31 ( V_11 ) ;
}
F_36 ( V_13 , NULL , 1 ) ;
F_47 ( V_13 ) ;
F_48 ( & V_13 -> V_40 ) ;
F_49 ( V_13 -> V_2 ) ;
F_50 ( V_13 -> V_2 , V_31 ) ;
}
static int F_51 ( struct V_12 * V_13 )
{
int V_41 ;
struct V_10 * V_11 ;
unsigned long * V_42 ;
V_42 = F_52 ( F_53 ( V_43 ) , sizeof( unsigned long ) ,
V_44 ) ;
if ( ! V_42 )
return - V_45 ;
F_54 ( 0 , V_42 ) ;
F_19 (p, &br->port_list, list) {
F_54 ( V_11 -> V_46 , V_42 ) ;
}
V_41 = F_55 ( V_42 , V_43 ) ;
F_26 ( V_42 ) ;
return ( V_41 >= V_43 ) ? - V_47 : V_41 ;
}
static struct V_10 * F_56 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
int V_41 ;
struct V_10 * V_11 ;
V_41 = F_51 ( V_13 ) ;
if ( V_41 < 0 )
return F_57 ( V_41 ) ;
V_11 = F_58 ( sizeof( * V_11 ) , V_44 ) ;
if ( V_11 == NULL )
return F_57 ( - V_45 ) ;
V_11 -> V_13 = V_13 ;
F_59 ( V_2 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_16 = F_1 ( V_2 ) ;
V_11 -> V_48 = 0x8000 >> V_49 ;
V_11 -> V_46 = V_41 ;
V_11 -> V_14 = V_50 | V_51 ;
F_60 ( V_11 ) ;
F_61 ( V_11 , V_19 ) ;
F_62 ( V_11 ) ;
F_63 ( V_11 ) ;
return V_11 ;
}
int F_64 ( struct V_52 * V_52 , const char * V_9 )
{
struct V_1 * V_2 ;
int V_53 ;
V_2 = F_65 ( sizeof( struct V_12 ) , V_9 , V_54 ,
V_55 ) ;
if ( ! V_2 )
return - V_45 ;
F_66 ( V_2 , V_52 ) ;
V_2 -> V_56 = & V_57 ;
V_53 = F_67 ( V_2 ) ;
if ( V_53 )
F_68 ( V_2 ) ;
return V_53 ;
}
int F_69 ( struct V_52 * V_52 , const char * V_9 )
{
struct V_1 * V_2 ;
int V_58 = 0 ;
F_70 () ;
V_2 = F_71 ( V_52 , V_9 ) ;
if ( V_2 == NULL )
V_58 = - V_59 ;
else if ( ! ( V_2 -> V_22 & V_60 ) ) {
V_58 = - V_61 ;
}
else if ( V_2 -> V_14 & V_62 ) {
V_58 = - V_63 ;
}
else
F_44 ( V_2 , NULL ) ;
F_72 () ;
return V_58 ;
}
int F_73 ( const struct V_12 * V_13 )
{
const struct V_10 * V_11 ;
int V_64 = 0 ;
F_74 () ;
if ( F_75 ( & V_13 -> V_65 ) )
V_64 = V_66 ;
else {
F_19 (p, &br->port_list, list) {
if ( ! V_64 || V_11 -> V_2 -> V_64 < V_64 )
V_64 = V_11 -> V_2 -> V_64 ;
}
}
return V_64 ;
}
T_2 F_76 ( struct V_12 * V_13 ,
T_2 V_67 )
{
struct V_10 * V_11 ;
T_2 V_68 ;
if ( F_75 ( & V_13 -> V_65 ) )
return V_67 ;
V_68 = V_67 ;
V_67 &= ~ V_69 ;
F_19 (p, &br->port_list, list) {
V_67 = F_77 ( V_67 ,
V_11 -> V_2 -> V_67 , V_68 ) ;
}
V_67 = F_78 ( V_67 , V_68 ) ;
return V_67 ;
}
int F_79 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_20 = 0 ;
bool V_70 ;
if ( ( V_2 -> V_14 & V_71 ) ||
V_2 -> type != V_72 || V_2 -> V_73 != V_74 ||
! F_80 ( V_2 -> V_75 ) ||
F_81 ( V_2 ) )
return - V_76 ;
if ( V_2 -> V_77 -> V_78 == V_79 )
return - V_80 ;
if ( F_82 ( V_2 ) )
return - V_63 ;
if ( V_2 -> V_22 & V_81 )
return - V_82 ;
V_11 = F_56 ( V_13 , V_2 ) ;
if ( F_83 ( V_11 ) )
return F_84 ( V_11 ) ;
F_85 ( V_83 , V_2 ) ;
V_20 = F_23 ( V_2 , 1 ) ;
if ( V_20 )
goto V_84;
V_20 = F_86 ( & V_11 -> V_29 , & V_85 , & ( V_2 -> V_2 . V_29 ) ,
V_86 ) ;
if ( V_20 )
goto V_87;
V_20 = F_87 ( V_11 ) ;
if ( V_20 )
goto V_88;
V_20 = F_88 ( V_11 ) ;
if ( V_20 )
goto V_89;
V_20 = F_89 ( V_2 , V_90 , V_11 ) ;
if ( V_20 )
goto V_91;
V_2 -> V_22 |= V_36 ;
V_20 = F_90 ( V_2 , V_13 -> V_2 ) ;
if ( V_20 )
goto V_92;
F_91 ( V_2 ) ;
F_92 ( & V_11 -> V_35 , & V_13 -> V_65 ) ;
F_21 ( V_13 ) ;
F_93 ( V_13 -> V_2 ) ;
if ( V_13 -> V_2 -> V_93 < V_2 -> V_93 )
V_13 -> V_2 -> V_93 = V_2 -> V_93 ;
if ( F_94 ( V_13 , V_11 , V_2 -> V_75 , 0 ) )
F_95 ( V_2 , L_3 ) ;
if ( F_96 ( V_11 ) )
F_95 ( V_2 , L_4 ) ;
F_7 ( & V_13 -> V_17 ) ;
V_70 = F_97 ( V_13 ) ;
if ( F_5 ( V_2 ) && F_6 ( V_2 ) &&
( V_13 -> V_2 -> V_14 & V_62 ) )
F_8 ( V_11 ) ;
F_10 ( & V_13 -> V_17 ) ;
F_33 ( V_94 , V_11 ) ;
if ( V_70 )
F_85 ( V_95 , V_13 -> V_2 ) ;
F_98 ( V_13 -> V_2 , F_73 ( V_13 ) ) ;
F_40 ( & V_11 -> V_29 , V_96 ) ;
return 0 ;
V_92:
V_2 -> V_22 &= ~ V_36 ;
F_38 ( V_2 ) ;
V_91:
F_42 ( V_11 ) ;
V_89:
F_32 ( V_13 -> V_33 , V_11 -> V_2 -> V_9 ) ;
V_88:
F_29 ( & V_11 -> V_29 ) ;
V_11 = NULL ;
V_87:
F_23 ( V_2 , - 1 ) ;
V_84:
F_28 ( V_2 ) ;
F_26 ( V_11 ) ;
return V_20 ;
}
int F_99 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_10 * V_11 ;
bool V_70 ;
V_11 = F_100 ( V_2 ) ;
if ( ! V_11 || V_11 -> V_13 != V_13 )
return - V_76 ;
F_31 ( V_11 ) ;
F_98 ( V_13 -> V_2 , F_73 ( V_13 ) ) ;
F_7 ( & V_13 -> V_17 ) ;
V_70 = F_97 ( V_13 ) ;
F_10 ( & V_13 -> V_17 ) ;
if ( V_70 )
F_85 ( V_95 , V_13 -> V_2 ) ;
F_93 ( V_13 -> V_2 ) ;
return 0 ;
}
void F_101 ( struct V_10 * V_11 , unsigned long V_68 )
{
struct V_12 * V_13 = V_11 -> V_13 ;
if ( V_68 & V_97 )
F_21 ( V_13 ) ;
}
