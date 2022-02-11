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
void F_32 ( struct V_1 * V_2 , struct V_33 * V_25 )
{
struct V_16 * V_17 = F_33 ( V_2 ) ;
struct V_14 * V_15 , * V_34 ;
F_34 (p, n, &br->port_list, list) {
F_18 ( V_15 ) ;
}
F_35 ( & V_17 -> V_35 ) ;
F_36 ( V_17 -> V_2 ) ;
F_37 ( V_17 -> V_2 , V_25 ) ;
}
static int F_38 ( struct V_16 * V_17 )
{
int V_36 ;
struct V_14 * V_15 ;
unsigned long * V_37 ;
V_37 = F_39 ( F_40 ( V_38 ) , sizeof( unsigned long ) ,
V_39 ) ;
if ( ! V_37 )
return - V_40 ;
F_41 ( 0 , V_37 ) ;
F_42 (p, &br->port_list, list) {
F_41 ( V_15 -> V_41 , V_37 ) ;
}
V_36 = F_43 ( V_37 , V_38 ) ;
F_13 ( V_37 ) ;
return ( V_36 >= V_38 ) ? - V_42 : V_36 ;
}
static struct V_14 * F_44 ( struct V_16 * V_17 ,
struct V_1 * V_2 )
{
int V_36 ;
struct V_14 * V_15 ;
V_36 = F_38 ( V_17 ) ;
if ( V_36 < 0 )
return F_45 ( V_36 ) ;
V_15 = F_46 ( sizeof( * V_15 ) , V_39 ) ;
if ( V_15 == NULL )
return F_45 ( - V_40 ) ;
V_15 -> V_17 = V_17 ;
F_47 ( V_2 ) ;
V_15 -> V_2 = V_2 ;
V_15 -> V_18 = F_1 ( V_2 ) ;
V_15 -> V_43 = 0x8000 >> V_44 ;
V_15 -> V_41 = V_36 ;
V_15 -> V_45 = 0 ;
F_48 ( V_15 ) ;
V_15 -> V_20 = V_21 ;
F_49 ( V_15 ) ;
F_50 ( V_15 ) ;
return V_15 ;
}
int F_51 ( struct V_46 * V_46 , const char * V_13 )
{
struct V_1 * V_2 ;
int V_47 ;
V_2 = F_52 ( sizeof( struct V_16 ) , V_13 ,
V_48 ) ;
if ( ! V_2 )
return - V_40 ;
F_53 ( V_2 , V_46 ) ;
V_47 = F_54 ( V_2 ) ;
if ( V_47 )
F_55 ( V_2 ) ;
return V_47 ;
}
int F_56 ( struct V_46 * V_46 , const char * V_13 )
{
struct V_1 * V_2 ;
int V_49 = 0 ;
F_57 () ;
V_2 = F_58 ( V_46 , V_13 ) ;
if ( V_2 == NULL )
V_49 = - V_50 ;
else if ( ! ( V_2 -> V_30 & V_51 ) ) {
V_49 = - V_52 ;
}
else if ( V_2 -> V_45 & V_53 ) {
V_49 = - V_54 ;
}
else
F_32 ( V_2 , NULL ) ;
F_59 () ;
return V_49 ;
}
int F_60 ( const struct V_16 * V_17 )
{
const struct V_14 * V_15 ;
int V_55 = 0 ;
F_61 () ;
if ( F_62 ( & V_17 -> V_56 ) )
V_55 = V_57 ;
else {
F_42 (p, &br->port_list, list) {
if ( ! V_55 || V_15 -> V_2 -> V_55 < V_55 )
V_55 = V_15 -> V_2 -> V_55 ;
}
}
return V_55 ;
}
T_1 F_63 ( struct V_16 * V_17 , T_1 V_58 )
{
struct V_14 * V_15 ;
T_1 V_59 ;
if ( F_62 ( & V_17 -> V_56 ) )
return V_58 ;
V_59 = V_58 ;
V_58 &= ~ V_60 ;
F_42 (p, &br->port_list, list) {
V_58 = F_64 ( V_58 ,
V_15 -> V_2 -> V_58 , V_59 ) ;
}
return V_58 ;
}
int F_65 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
struct V_14 * V_15 ;
int V_61 = 0 ;
bool V_62 ;
if ( ( V_2 -> V_45 & V_63 ) ||
V_2 -> type != V_64 || V_2 -> V_65 != V_66 )
return - V_67 ;
if ( V_2 -> V_68 -> V_69 == V_70 )
return - V_71 ;
if ( F_66 ( V_2 ) )
return - V_54 ;
if ( V_2 -> V_30 & V_72 )
return - V_73 ;
V_15 = F_44 ( V_17 , V_2 ) ;
if ( F_67 ( V_15 ) )
return F_68 ( V_15 ) ;
F_69 ( V_74 , V_2 ) ;
V_61 = F_20 ( V_2 , 1 ) ;
if ( V_61 )
goto V_75;
V_61 = F_70 ( & V_15 -> V_23 , & V_76 , & ( V_2 -> V_2 . V_23 ) ,
V_77 ) ;
if ( V_61 )
goto V_78;
V_61 = F_71 ( V_17 , V_15 , V_2 -> V_79 ) ;
if ( V_61 )
goto V_80;
V_61 = F_72 ( V_15 ) ;
if ( V_61 )
goto V_81;
if ( F_73 ( V_17 ) && ( ( V_61 = F_74 ( V_15 ) ) ) )
goto V_82;
V_61 = F_26 ( V_2 , V_17 -> V_2 ) ;
if ( V_61 )
goto V_82;
V_61 = F_75 ( V_2 , V_83 , V_15 ) ;
if ( V_61 )
goto V_84;
V_2 -> V_30 |= V_31 ;
F_76 ( V_2 ) ;
F_77 ( & V_15 -> V_29 , & V_17 -> V_56 ) ;
F_78 ( V_17 -> V_2 ) ;
F_7 ( & V_17 -> V_19 ) ;
V_62 = F_79 ( V_17 ) ;
if ( ( V_2 -> V_45 & V_53 ) && F_6 ( V_2 ) &&
( V_17 -> V_2 -> V_45 & V_53 ) )
F_8 ( V_15 ) ;
F_10 ( & V_17 -> V_19 ) ;
F_21 ( V_85 , V_15 ) ;
if ( V_62 )
F_69 ( V_86 , V_17 -> V_2 ) ;
F_80 ( V_17 -> V_2 , F_60 ( V_17 ) ) ;
F_28 ( & V_15 -> V_23 , V_87 ) ;
return 0 ;
V_84:
F_26 ( V_2 , NULL ) ;
V_82:
F_19 ( V_17 -> V_27 , V_15 -> V_2 -> V_13 ) ;
V_81:
F_22 ( V_17 , V_15 , 1 ) ;
V_80:
F_16 ( & V_15 -> V_23 ) ;
V_15 = NULL ;
V_78:
F_20 ( V_2 , - 1 ) ;
V_75:
F_15 ( V_2 ) ;
F_13 ( V_15 ) ;
return V_61 ;
}
int F_81 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
struct V_14 * V_15 ;
bool V_62 ;
V_15 = F_82 ( V_2 ) ;
if ( ! V_15 || V_15 -> V_17 != V_17 )
return - V_67 ;
F_18 ( V_15 ) ;
F_7 ( & V_17 -> V_19 ) ;
V_62 = F_79 ( V_17 ) ;
F_10 ( & V_17 -> V_19 ) ;
if ( V_62 )
F_69 ( V_86 , V_17 -> V_2 ) ;
F_78 ( V_17 -> V_2 ) ;
return 0 ;
}
void T_2 F_83 ( struct V_46 * V_46 )
{
struct V_1 * V_2 ;
F_84 ( V_29 ) ;
F_57 () ;
F_85 (net, dev)
if ( V_2 -> V_30 & V_51 )
F_32 ( V_2 , & V_29 ) ;
F_86 ( & V_29 ) ;
F_59 () ;
}
