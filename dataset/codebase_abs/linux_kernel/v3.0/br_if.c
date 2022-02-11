static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 && V_2 -> V_3 -> V_4 ) {
struct V_5 V_6 = { . V_7 = V_8 , } ;
if ( ! F_2 ( V_2 , & V_6 ) ) {
switch ( F_3 ( & V_6 ) ) {
case V_9 :
return 2 ;
case V_10 :
return 4 ;
case V_11 :
return 19 ;
case V_12 :
return 100 ;
}
}
}
if ( ! strncmp ( V_2 -> V_13 , L_1 , 3 ) )
return 7 ;
if ( ! strncmp ( V_2 -> V_13 , L_2 , 4 ) )
return 2500 ;
return 100 ;
}
void F_4 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_16 * V_17 = V_15 -> V_17 ;
if ( F_5 ( V_2 ) && F_6 ( V_2 ) )
V_15 -> V_18 = F_1 ( V_2 ) ;
if ( ! F_5 ( V_17 -> V_2 ) )
return;
F_7 ( & V_17 -> V_19 ) ;
if ( F_5 ( V_2 ) && F_6 ( V_2 ) ) {
if ( V_15 -> V_20 == V_21 )
F_8 ( V_15 ) ;
} else {
if ( V_15 -> V_20 != V_21 )
F_9 ( V_15 ) ;
}
F_10 ( & V_17 -> V_19 ) ;
}
static void F_11 ( struct V_22 * V_23 )
{
struct V_14 * V_15
= F_12 ( V_23 , struct V_14 , V_23 ) ;
F_13 ( V_15 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 ;
V_15 -> V_17 = NULL ;
V_15 -> V_2 = NULL ;
F_15 ( V_2 ) ;
F_16 ( & V_15 -> V_23 ) ;
}
static void F_17 ( struct V_24 * V_25 )
{
struct V_14 * V_15 =
F_12 ( V_25 , struct V_14 , V_26 ) ;
F_14 ( V_15 ) ;
}
static void F_18 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_19 ( V_17 -> V_27 , V_15 -> V_2 -> V_13 ) ;
F_20 ( V_2 , - 1 ) ;
F_7 ( & V_17 -> V_19 ) ;
F_9 ( V_15 ) ;
F_10 ( & V_17 -> V_19 ) ;
F_21 ( V_28 , V_15 ) ;
F_22 ( V_17 , V_15 , 1 ) ;
F_23 ( & V_15 -> V_29 ) ;
V_2 -> V_30 &= ~ V_31 ;
F_24 ( V_2 ) ;
F_25 () ;
F_26 ( V_2 , NULL ) ;
F_27 ( V_15 ) ;
F_28 ( & V_15 -> V_23 , V_32 ) ;
F_29 ( & V_15 -> V_23 ) ;
F_30 ( V_15 ) ;
F_31 ( & V_15 -> V_26 , F_17 ) ;
}
static void F_32 ( struct V_16 * V_17 , struct V_33 * V_25 )
{
struct V_14 * V_15 , * V_34 ;
F_33 (p, n, &br->port_list, list) {
F_18 ( V_15 ) ;
}
F_34 ( & V_17 -> V_35 ) ;
F_35 ( V_17 -> V_2 ) ;
F_36 ( V_17 -> V_2 , V_25 ) ;
}
static int F_37 ( struct V_16 * V_17 )
{
int V_36 ;
struct V_14 * V_15 ;
unsigned long * V_37 ;
V_37 = F_38 ( F_39 ( V_38 ) , sizeof( unsigned long ) ,
V_39 ) ;
if ( ! V_37 )
return - V_40 ;
F_40 ( 0 , V_37 ) ;
F_41 (p, &br->port_list, list) {
F_40 ( V_15 -> V_41 , V_37 ) ;
}
V_36 = F_42 ( V_37 , V_38 ) ;
F_13 ( V_37 ) ;
return ( V_36 >= V_38 ) ? - V_42 : V_36 ;
}
static struct V_14 * F_43 ( struct V_16 * V_17 ,
struct V_1 * V_2 )
{
int V_36 ;
struct V_14 * V_15 ;
V_36 = F_37 ( V_17 ) ;
if ( V_36 < 0 )
return F_44 ( V_36 ) ;
V_15 = F_45 ( sizeof( * V_15 ) , V_39 ) ;
if ( V_15 == NULL )
return F_44 ( - V_40 ) ;
V_15 -> V_17 = V_17 ;
F_46 ( V_2 ) ;
V_15 -> V_2 = V_2 ;
V_15 -> V_18 = F_1 ( V_2 ) ;
V_15 -> V_43 = 0x8000 >> V_44 ;
V_15 -> V_41 = V_36 ;
V_15 -> V_45 = 0 ;
F_47 ( V_15 ) ;
V_15 -> V_20 = V_21 ;
F_48 ( V_15 ) ;
F_49 ( V_15 ) ;
return V_15 ;
}
int F_50 ( struct V_46 * V_46 , const char * V_13 )
{
struct V_1 * V_2 ;
V_2 = F_51 ( sizeof( struct V_16 ) , V_13 ,
V_47 ) ;
if ( ! V_2 )
return - V_40 ;
F_52 ( V_2 , V_46 ) ;
return F_53 ( V_2 ) ;
}
int F_54 ( struct V_46 * V_46 , const char * V_13 )
{
struct V_1 * V_2 ;
int V_48 = 0 ;
F_55 () ;
V_2 = F_56 ( V_46 , V_13 ) ;
if ( V_2 == NULL )
V_48 = - V_49 ;
else if ( ! ( V_2 -> V_30 & V_50 ) ) {
V_48 = - V_51 ;
}
else if ( V_2 -> V_45 & V_52 ) {
V_48 = - V_53 ;
}
else
F_32 ( F_57 ( V_2 ) , NULL ) ;
F_58 () ;
return V_48 ;
}
int F_59 ( const struct V_16 * V_17 )
{
const struct V_14 * V_15 ;
int V_54 = 0 ;
F_60 () ;
if ( F_61 ( & V_17 -> V_55 ) )
V_54 = V_56 ;
else {
F_41 (p, &br->port_list, list) {
if ( ! V_54 || V_15 -> V_2 -> V_54 < V_54 )
V_54 = V_15 -> V_2 -> V_54 ;
}
}
return V_54 ;
}
T_1 F_62 ( struct V_16 * V_17 , T_1 V_57 )
{
struct V_14 * V_15 ;
T_1 V_58 ;
if ( F_61 ( & V_17 -> V_55 ) )
return V_57 ;
V_58 = V_57 ;
V_57 &= ~ V_59 ;
F_41 (p, &br->port_list, list) {
V_57 = F_63 ( V_57 ,
V_15 -> V_2 -> V_57 , V_58 ) ;
}
return V_57 ;
}
int F_64 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_60 = 0 ;
bool V_61 ;
if ( ( V_2 -> V_45 & V_62 ) ||
V_2 -> type != V_63 || V_2 -> V_64 != V_65 )
return - V_66 ;
if ( V_2 -> V_67 -> V_68 == V_69 )
return - V_70 ;
if ( F_65 ( V_2 ) )
return - V_53 ;
if ( V_2 -> V_30 & V_71 )
return - V_72 ;
V_15 = F_43 ( V_17 , V_2 ) ;
if ( F_66 ( V_15 ) )
return F_67 ( V_15 ) ;
F_68 ( V_73 , V_2 ) ;
V_60 = F_20 ( V_2 , 1 ) ;
if ( V_60 )
goto V_74;
V_60 = F_69 ( & V_15 -> V_23 , & V_75 , & ( V_2 -> V_2 . V_23 ) ,
V_76 ) ;
if ( V_60 )
goto V_77;
V_60 = F_70 ( V_17 , V_15 , V_2 -> V_78 ) ;
if ( V_60 )
goto V_79;
V_60 = F_71 ( V_15 ) ;
if ( V_60 )
goto V_80;
if ( F_72 ( V_17 ) && ( ( V_60 = F_73 ( V_15 ) ) ) )
goto V_81;
V_60 = F_26 ( V_2 , V_17 -> V_2 ) ;
if ( V_60 )
goto V_81;
V_60 = F_74 ( V_2 , V_82 , V_15 ) ;
if ( V_60 )
goto V_83;
V_2 -> V_30 |= V_31 ;
F_75 ( V_2 ) ;
F_76 ( & V_15 -> V_29 , & V_17 -> V_55 ) ;
F_77 ( V_17 -> V_2 ) ;
F_7 ( & V_17 -> V_19 ) ;
V_61 = F_78 ( V_17 ) ;
if ( ( V_2 -> V_45 & V_52 ) && F_6 ( V_2 ) &&
( V_17 -> V_2 -> V_45 & V_52 ) )
F_8 ( V_15 ) ;
F_10 ( & V_17 -> V_19 ) ;
F_21 ( V_84 , V_15 ) ;
if ( V_61 )
F_68 ( V_85 , V_2 ) ;
F_79 ( V_17 -> V_2 , F_59 ( V_17 ) ) ;
F_28 ( & V_15 -> V_23 , V_86 ) ;
return 0 ;
V_83:
F_26 ( V_2 , NULL ) ;
V_81:
F_19 ( V_17 -> V_27 , V_15 -> V_2 -> V_13 ) ;
V_80:
F_22 ( V_17 , V_15 , 1 ) ;
V_79:
F_16 ( & V_15 -> V_23 ) ;
V_15 = NULL ;
V_77:
F_20 ( V_2 , - 1 ) ;
V_74:
F_15 ( V_2 ) ;
F_13 ( V_15 ) ;
return V_60 ;
}
int F_80 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
struct V_14 * V_15 ;
V_15 = F_81 ( V_2 ) ;
if ( ! V_15 || V_15 -> V_17 != V_17 )
return - V_66 ;
F_18 ( V_15 ) ;
F_7 ( & V_17 -> V_19 ) ;
F_78 ( V_17 ) ;
F_10 ( & V_17 -> V_19 ) ;
F_77 ( V_17 -> V_2 ) ;
return 0 ;
}
void T_2 F_82 ( struct V_46 * V_46 )
{
struct V_1 * V_2 ;
F_83 ( V_29 ) ;
F_55 () ;
F_84 (net, dev)
if ( V_2 -> V_30 & V_50 )
F_32 ( F_57 ( V_2 ) , & V_29 ) ;
F_85 ( & V_29 ) ;
F_58 () ;
}
