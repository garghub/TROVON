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
if ( F_5 ( V_2 ) && F_6 ( V_2 ) )
V_11 -> V_14 = F_1 ( V_2 ) ;
if ( ! F_5 ( V_13 -> V_2 ) )
return;
F_7 ( & V_13 -> V_15 ) ;
if ( F_5 ( V_2 ) && F_6 ( V_2 ) ) {
if ( V_11 -> V_16 == V_17 )
F_8 ( V_11 ) ;
} else {
if ( V_11 -> V_16 != V_17 )
F_9 ( V_11 ) ;
}
F_10 ( & V_13 -> V_15 ) ;
}
static void F_11 ( struct V_18 * V_19 )
{
struct V_10 * V_11
= F_12 ( V_19 , struct V_10 , V_19 ) ;
F_13 ( V_11 ) ;
}
static void F_14 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
V_11 -> V_13 = NULL ;
V_11 -> V_2 = NULL ;
F_15 ( V_2 ) ;
F_16 ( & V_11 -> V_19 ) ;
}
static void F_17 ( struct V_20 * V_21 )
{
struct V_10 * V_11 =
F_12 ( V_21 , struct V_10 , V_22 ) ;
F_14 ( V_11 ) ;
}
static void F_18 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_19 ( V_13 -> V_23 , V_11 -> V_2 -> V_9 ) ;
F_20 ( V_2 , - 1 ) ;
F_7 ( & V_13 -> V_15 ) ;
F_9 ( V_11 ) ;
F_10 ( & V_13 -> V_15 ) ;
F_21 ( V_24 , V_11 ) ;
F_22 ( V_13 , V_11 , 1 ) ;
F_23 ( & V_11 -> V_25 ) ;
V_2 -> V_26 &= ~ V_27 ;
F_24 ( V_2 ) ;
F_25 () ;
F_26 ( V_2 , NULL ) ;
F_27 ( V_11 ) ;
F_28 ( & V_11 -> V_19 , V_28 ) ;
F_29 ( & V_11 -> V_19 ) ;
F_30 ( V_11 ) ;
F_31 ( & V_11 -> V_22 , F_17 ) ;
}
void F_32 ( struct V_1 * V_2 , struct V_29 * V_21 )
{
struct V_12 * V_13 = F_33 ( V_2 ) ;
struct V_10 * V_11 , * V_30 ;
F_34 (p, n, &br->port_list, list) {
F_18 ( V_11 ) ;
}
F_35 ( & V_13 -> V_31 ) ;
F_36 ( V_13 -> V_2 ) ;
F_37 ( V_13 -> V_2 , V_21 ) ;
}
static int F_38 ( struct V_12 * V_13 )
{
int V_32 ;
struct V_10 * V_11 ;
unsigned long * V_33 ;
V_33 = F_39 ( F_40 ( V_34 ) , sizeof( unsigned long ) ,
V_35 ) ;
if ( ! V_33 )
return - V_36 ;
F_41 ( 0 , V_33 ) ;
F_42 (p, &br->port_list, list) {
F_41 ( V_11 -> V_37 , V_33 ) ;
}
V_32 = F_43 ( V_33 , V_34 ) ;
F_13 ( V_33 ) ;
return ( V_32 >= V_34 ) ? - V_38 : V_32 ;
}
static struct V_10 * F_44 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
int V_32 ;
struct V_10 * V_11 ;
V_32 = F_38 ( V_13 ) ;
if ( V_32 < 0 )
return F_45 ( V_32 ) ;
V_11 = F_46 ( sizeof( * V_11 ) , V_35 ) ;
if ( V_11 == NULL )
return F_45 ( - V_36 ) ;
V_11 -> V_13 = V_13 ;
F_47 ( V_2 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_14 = F_1 ( V_2 ) ;
V_11 -> V_39 = 0x8000 >> V_40 ;
V_11 -> V_37 = V_32 ;
V_11 -> V_41 = 0 ;
F_48 ( V_11 ) ;
V_11 -> V_16 = V_17 ;
F_49 ( V_11 ) ;
F_50 ( V_11 ) ;
return V_11 ;
}
int F_51 ( struct V_42 * V_42 , const char * V_9 )
{
struct V_1 * V_2 ;
int V_43 ;
V_2 = F_52 ( sizeof( struct V_12 ) , V_9 ,
V_44 ) ;
if ( ! V_2 )
return - V_36 ;
F_53 ( V_2 , V_42 ) ;
V_43 = F_54 ( V_2 ) ;
if ( V_43 )
F_55 ( V_2 ) ;
return V_43 ;
}
int F_56 ( struct V_42 * V_42 , const char * V_9 )
{
struct V_1 * V_2 ;
int V_45 = 0 ;
F_57 () ;
V_2 = F_58 ( V_42 , V_9 ) ;
if ( V_2 == NULL )
V_45 = - V_46 ;
else if ( ! ( V_2 -> V_26 & V_47 ) ) {
V_45 = - V_48 ;
}
else if ( V_2 -> V_41 & V_49 ) {
V_45 = - V_50 ;
}
else
F_32 ( V_2 , NULL ) ;
F_59 () ;
return V_45 ;
}
int F_60 ( const struct V_12 * V_13 )
{
const struct V_10 * V_11 ;
int V_51 = 0 ;
F_61 () ;
if ( F_62 ( & V_13 -> V_52 ) )
V_51 = V_53 ;
else {
F_42 (p, &br->port_list, list) {
if ( ! V_51 || V_11 -> V_2 -> V_51 < V_51 )
V_51 = V_11 -> V_2 -> V_51 ;
}
}
return V_51 ;
}
T_1 F_63 ( struct V_12 * V_13 ,
T_1 V_54 )
{
struct V_10 * V_11 ;
T_1 V_55 ;
if ( F_62 ( & V_13 -> V_52 ) )
return V_54 ;
V_55 = V_54 ;
V_54 &= ~ V_56 ;
F_42 (p, &br->port_list, list) {
V_54 = F_64 ( V_54 ,
V_11 -> V_2 -> V_54 , V_55 ) ;
}
return V_54 ;
}
int F_65 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_57 = 0 ;
bool V_58 ;
if ( ( V_2 -> V_41 & V_59 ) ||
V_2 -> type != V_60 || V_2 -> V_61 != V_62 ||
! F_66 ( V_2 -> V_63 ) )
return - V_64 ;
if ( V_2 -> V_65 -> V_66 == V_67 )
return - V_68 ;
if ( F_67 ( V_2 ) )
return - V_50 ;
if ( V_2 -> V_26 & V_69 )
return - V_70 ;
V_11 = F_44 ( V_13 , V_2 ) ;
if ( F_68 ( V_11 ) )
return F_69 ( V_11 ) ;
F_70 ( V_71 , V_2 ) ;
V_57 = F_20 ( V_2 , 1 ) ;
if ( V_57 )
goto V_72;
V_57 = F_71 ( & V_11 -> V_19 , & V_73 , & ( V_2 -> V_2 . V_19 ) ,
V_74 ) ;
if ( V_57 )
goto V_75;
V_57 = F_72 ( V_11 ) ;
if ( V_57 )
goto V_76;
if ( F_73 ( V_13 ) && ( ( V_57 = F_74 ( V_11 ) ) ) )
goto V_77;
V_57 = F_26 ( V_2 , V_13 -> V_2 ) ;
if ( V_57 )
goto V_77;
V_57 = F_75 ( V_2 , V_78 , V_11 ) ;
if ( V_57 )
goto V_79;
V_2 -> V_26 |= V_27 ;
F_76 ( V_2 ) ;
F_77 ( & V_11 -> V_25 , & V_13 -> V_52 ) ;
F_78 ( V_13 -> V_2 ) ;
F_7 ( & V_13 -> V_15 ) ;
V_58 = F_79 ( V_13 ) ;
if ( ( V_2 -> V_41 & V_49 ) && F_6 ( V_2 ) &&
( V_13 -> V_2 -> V_41 & V_49 ) )
F_8 ( V_11 ) ;
F_10 ( & V_13 -> V_15 ) ;
F_21 ( V_80 , V_11 ) ;
if ( V_58 )
F_70 ( V_81 , V_13 -> V_2 ) ;
F_80 ( V_13 -> V_2 , F_60 ( V_13 ) ) ;
if ( F_81 ( V_13 , V_11 , V_2 -> V_63 ) )
F_82 ( V_2 , L_3 ) ;
F_28 ( & V_11 -> V_19 , V_82 ) ;
return 0 ;
V_79:
F_26 ( V_2 , NULL ) ;
V_77:
F_19 ( V_13 -> V_23 , V_11 -> V_2 -> V_9 ) ;
V_76:
F_16 ( & V_11 -> V_19 ) ;
V_11 = NULL ;
V_75:
F_20 ( V_2 , - 1 ) ;
V_72:
F_15 ( V_2 ) ;
F_13 ( V_11 ) ;
return V_57 ;
}
int F_83 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_10 * V_11 ;
bool V_58 ;
V_11 = F_84 ( V_2 ) ;
if ( ! V_11 || V_11 -> V_13 != V_13 )
return - V_64 ;
F_18 ( V_11 ) ;
F_7 ( & V_13 -> V_15 ) ;
V_58 = F_79 ( V_13 ) ;
F_10 ( & V_13 -> V_15 ) ;
if ( V_58 )
F_70 ( V_81 , V_13 -> V_2 ) ;
F_78 ( V_13 -> V_2 ) ;
return 0 ;
}
void T_2 F_85 ( struct V_42 * V_42 )
{
struct V_1 * V_2 ;
F_86 ( V_25 ) ;
F_57 () ;
F_87 (net, dev)
if ( V_2 -> V_26 & V_47 )
F_32 ( V_2 , & V_25 ) ;
F_88 ( & V_25 ) ;
F_59 () ;
}
