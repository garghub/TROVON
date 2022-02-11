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
static void F_11 ( struct V_20 * V_21 )
{
struct V_10 * V_11
= F_12 ( V_21 , struct V_10 , V_21 ) ;
F_13 ( V_11 ) ;
}
static void F_14 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
V_11 -> V_13 = NULL ;
V_11 -> V_2 = NULL ;
F_15 ( V_2 ) ;
F_16 ( & V_11 -> V_21 ) ;
}
static void F_17 ( struct V_22 * V_23 )
{
struct V_10 * V_11 =
F_12 ( V_23 , struct V_10 , V_24 ) ;
F_14 ( V_11 ) ;
}
static void F_18 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_19 ( V_13 -> V_25 , V_11 -> V_2 -> V_9 ) ;
F_20 ( V_2 , - 1 ) ;
F_7 ( & V_13 -> V_17 ) ;
F_9 ( V_11 ) ;
F_10 ( & V_13 -> V_17 ) ;
F_21 ( V_26 , V_11 ) ;
F_22 ( V_11 ) ;
F_23 ( V_13 , V_11 , 1 ) ;
F_24 ( & V_11 -> V_27 ) ;
V_2 -> V_28 &= ~ V_29 ;
F_25 ( V_2 ) ;
F_26 () ;
F_27 ( V_2 , V_13 -> V_2 ) ;
F_28 ( V_11 ) ;
F_29 ( & V_11 -> V_21 , V_30 ) ;
F_30 ( & V_11 -> V_21 ) ;
F_31 ( V_11 ) ;
F_32 ( & V_11 -> V_24 , F_17 ) ;
}
void F_33 ( struct V_1 * V_2 , struct V_31 * V_23 )
{
struct V_12 * V_13 = F_34 ( V_2 ) ;
struct V_10 * V_11 , * V_32 ;
F_35 (p, n, &br->port_list, list) {
F_18 ( V_11 ) ;
}
F_36 ( & V_13 -> V_33 ) ;
F_37 ( V_13 -> V_2 ) ;
F_38 ( V_13 -> V_2 , V_23 ) ;
}
static int F_39 ( struct V_12 * V_13 )
{
int V_34 ;
struct V_10 * V_11 ;
unsigned long * V_35 ;
V_35 = F_40 ( F_41 ( V_36 ) , sizeof( unsigned long ) ,
V_37 ) ;
if ( ! V_35 )
return - V_38 ;
F_42 ( 0 , V_35 ) ;
F_43 (p, &br->port_list, list) {
F_42 ( V_11 -> V_39 , V_35 ) ;
}
V_34 = F_44 ( V_35 , V_36 ) ;
F_13 ( V_35 ) ;
return ( V_34 >= V_36 ) ? - V_40 : V_34 ;
}
static struct V_10 * F_45 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
int V_34 ;
struct V_10 * V_11 ;
V_34 = F_39 ( V_13 ) ;
if ( V_34 < 0 )
return F_46 ( V_34 ) ;
V_11 = F_47 ( sizeof( * V_11 ) , V_37 ) ;
if ( V_11 == NULL )
return F_46 ( - V_38 ) ;
V_11 -> V_13 = V_13 ;
F_48 ( V_2 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_16 = F_1 ( V_2 ) ;
V_11 -> V_41 = 0x8000 >> V_42 ;
V_11 -> V_39 = V_34 ;
V_11 -> V_14 = 0 ;
F_49 ( V_11 ) ;
V_11 -> V_18 = V_19 ;
F_50 ( V_11 ) ;
F_51 ( V_11 ) ;
return V_11 ;
}
int F_52 ( struct V_43 * V_43 , const char * V_9 )
{
struct V_1 * V_2 ;
int V_44 ;
V_2 = F_53 ( sizeof( struct V_12 ) , V_9 ,
V_45 ) ;
if ( ! V_2 )
return - V_38 ;
F_54 ( V_2 , V_43 ) ;
V_2 -> V_46 = & V_47 ;
V_44 = F_55 ( V_2 ) ;
if ( V_44 )
F_56 ( V_2 ) ;
return V_44 ;
}
int F_57 ( struct V_43 * V_43 , const char * V_9 )
{
struct V_1 * V_2 ;
int V_48 = 0 ;
F_58 () ;
V_2 = F_59 ( V_43 , V_9 ) ;
if ( V_2 == NULL )
V_48 = - V_49 ;
else if ( ! ( V_2 -> V_28 & V_50 ) ) {
V_48 = - V_51 ;
}
else if ( V_2 -> V_14 & V_52 ) {
V_48 = - V_53 ;
}
else
F_33 ( V_2 , NULL ) ;
F_60 () ;
return V_48 ;
}
int F_61 ( const struct V_12 * V_13 )
{
const struct V_10 * V_11 ;
int V_54 = 0 ;
F_62 () ;
if ( F_63 ( & V_13 -> V_55 ) )
V_54 = V_56 ;
else {
F_43 (p, &br->port_list, list) {
if ( ! V_54 || V_11 -> V_2 -> V_54 < V_54 )
V_54 = V_11 -> V_2 -> V_54 ;
}
}
return V_54 ;
}
T_1 F_64 ( struct V_12 * V_13 ,
T_1 V_57 )
{
struct V_10 * V_11 ;
T_1 V_58 ;
if ( F_63 ( & V_13 -> V_55 ) )
return V_57 ;
V_58 = V_57 ;
V_57 &= ~ V_59 ;
F_43 (p, &br->port_list, list) {
V_57 = F_65 ( V_57 ,
V_11 -> V_2 -> V_57 , V_58 ) ;
}
return V_57 ;
}
int F_66 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_60 = 0 ;
bool V_61 ;
if ( ( V_2 -> V_14 & V_62 ) ||
V_2 -> type != V_63 || V_2 -> V_64 != V_65 ||
! F_67 ( V_2 -> V_66 ) )
return - V_67 ;
if ( V_2 -> V_68 -> V_69 == V_70 )
return - V_71 ;
if ( F_68 ( V_2 ) )
return - V_53 ;
if ( V_2 -> V_28 & V_72 )
return - V_73 ;
V_11 = F_45 ( V_13 , V_2 ) ;
if ( F_69 ( V_11 ) )
return F_70 ( V_11 ) ;
F_71 ( V_74 , V_2 ) ;
V_60 = F_20 ( V_2 , 1 ) ;
if ( V_60 )
goto V_75;
V_60 = F_72 ( & V_11 -> V_21 , & V_76 , & ( V_2 -> V_2 . V_21 ) ,
V_77 ) ;
if ( V_60 )
goto V_78;
V_60 = F_73 ( V_11 ) ;
if ( V_60 )
goto V_79;
if ( F_74 ( V_13 ) && ( ( V_60 = F_75 ( V_11 , V_37 ) ) ) )
goto V_80;
V_60 = F_76 ( V_2 , V_13 -> V_2 ) ;
if ( V_60 )
goto V_81;
V_60 = F_77 ( V_2 , V_82 , V_11 ) ;
if ( V_60 )
goto V_83;
V_2 -> V_28 |= V_29 ;
F_78 ( V_2 ) ;
F_79 ( & V_11 -> V_27 , & V_13 -> V_55 ) ;
F_80 ( V_13 -> V_2 ) ;
F_7 ( & V_13 -> V_17 ) ;
V_61 = F_81 ( V_13 ) ;
if ( F_5 ( V_2 ) && F_6 ( V_2 ) &&
( V_13 -> V_2 -> V_14 & V_52 ) )
F_8 ( V_11 ) ;
F_10 ( & V_13 -> V_17 ) ;
F_21 ( V_84 , V_11 ) ;
if ( V_61 )
F_71 ( V_85 , V_13 -> V_2 ) ;
F_82 ( V_13 -> V_2 , F_61 ( V_13 ) ) ;
if ( F_83 ( V_13 , V_11 , V_2 -> V_66 , 0 ) )
F_84 ( V_2 , L_3 ) ;
F_29 ( & V_11 -> V_21 , V_86 ) ;
return 0 ;
V_83:
F_27 ( V_2 , V_13 -> V_2 ) ;
V_81:
F_31 ( V_11 ) ;
V_80:
F_19 ( V_13 -> V_25 , V_11 -> V_2 -> V_9 ) ;
V_79:
F_16 ( & V_11 -> V_21 ) ;
V_11 = NULL ;
V_78:
F_20 ( V_2 , - 1 ) ;
V_75:
F_15 ( V_2 ) ;
F_13 ( V_11 ) ;
return V_60 ;
}
int F_85 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_10 * V_11 ;
bool V_61 ;
V_11 = F_86 ( V_2 ) ;
if ( ! V_11 || V_11 -> V_13 != V_13 )
return - V_67 ;
F_18 ( V_11 ) ;
F_7 ( & V_13 -> V_17 ) ;
V_61 = F_81 ( V_13 ) ;
F_10 ( & V_13 -> V_17 ) ;
if ( V_61 )
F_71 ( V_85 , V_13 -> V_2 ) ;
F_80 ( V_13 -> V_2 ) ;
return 0 ;
}
void T_2 F_87 ( struct V_43 * V_43 )
{
struct V_1 * V_2 ;
F_88 ( V_27 ) ;
F_58 () ;
F_89 (net, dev)
if ( V_2 -> V_28 & V_50 )
F_33 ( V_2 , & V_27 ) ;
F_90 ( & V_27 ) ;
F_60 () ;
}
