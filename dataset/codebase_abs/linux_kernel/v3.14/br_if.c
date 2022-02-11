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
F_26 ( V_2 , V_13 -> V_2 ) ;
F_27 ( V_11 ) ;
F_28 ( & V_11 -> V_21 , V_30 ) ;
F_29 ( & V_11 -> V_21 ) ;
F_30 ( V_11 ) ;
F_31 ( & V_11 -> V_24 , F_17 ) ;
}
void F_32 ( struct V_1 * V_2 , struct V_31 * V_23 )
{
struct V_12 * V_13 = F_33 ( V_2 ) ;
struct V_10 * V_11 , * V_32 ;
F_34 (p, n, &br->port_list, list) {
F_18 ( V_11 ) ;
}
F_23 ( V_13 , NULL , 1 ) ;
F_35 ( V_13 ) ;
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
V_11 -> V_14 = V_43 | V_44 ;
F_49 ( V_11 ) ;
V_11 -> V_18 = V_19 ;
F_50 ( V_11 ) ;
F_51 ( V_11 ) ;
return V_11 ;
}
int F_52 ( struct V_45 * V_45 , const char * V_9 )
{
struct V_1 * V_2 ;
int V_46 ;
V_2 = F_53 ( sizeof( struct V_12 ) , V_9 ,
V_47 ) ;
if ( ! V_2 )
return - V_38 ;
F_54 ( V_2 , V_45 ) ;
V_2 -> V_48 = & V_49 ;
V_46 = F_55 ( V_2 ) ;
if ( V_46 )
F_56 ( V_2 ) ;
return V_46 ;
}
int F_57 ( struct V_45 * V_45 , const char * V_9 )
{
struct V_1 * V_2 ;
int V_50 = 0 ;
F_58 () ;
V_2 = F_59 ( V_45 , V_9 ) ;
if ( V_2 == NULL )
V_50 = - V_51 ;
else if ( ! ( V_2 -> V_28 & V_52 ) ) {
V_50 = - V_53 ;
}
else if ( V_2 -> V_14 & V_54 ) {
V_50 = - V_55 ;
}
else
F_32 ( V_2 , NULL ) ;
F_60 () ;
return V_50 ;
}
int F_61 ( const struct V_12 * V_13 )
{
const struct V_10 * V_11 ;
int V_56 = 0 ;
F_62 () ;
if ( F_63 ( & V_13 -> V_57 ) )
V_56 = V_58 ;
else {
F_43 (p, &br->port_list, list) {
if ( ! V_56 || V_11 -> V_2 -> V_56 < V_56 )
V_56 = V_11 -> V_2 -> V_56 ;
}
}
return V_56 ;
}
T_1 F_64 ( struct V_12 * V_13 ,
T_1 V_59 )
{
struct V_10 * V_11 ;
T_1 V_60 ;
if ( F_63 ( & V_13 -> V_57 ) )
return V_59 ;
V_60 = V_59 ;
V_59 &= ~ V_61 ;
F_43 (p, &br->port_list, list) {
V_59 = F_65 ( V_59 ,
V_11 -> V_2 -> V_59 , V_60 ) ;
}
return V_59 ;
}
int F_66 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_62 = 0 ;
bool V_63 ;
if ( ( V_2 -> V_14 & V_64 ) ||
V_2 -> type != V_65 || V_2 -> V_66 != V_67 ||
! F_67 ( V_2 -> V_68 ) )
return - V_69 ;
if ( V_2 -> V_70 -> V_71 == V_72 )
return - V_73 ;
if ( F_68 ( V_2 ) )
return - V_55 ;
if ( V_2 -> V_28 & V_74 )
return - V_75 ;
V_11 = F_45 ( V_13 , V_2 ) ;
if ( F_69 ( V_11 ) )
return F_70 ( V_11 ) ;
F_71 ( V_76 , V_2 ) ;
V_62 = F_20 ( V_2 , 1 ) ;
if ( V_62 )
goto V_77;
V_62 = F_72 ( & V_11 -> V_21 , & V_78 , & ( V_2 -> V_2 . V_21 ) ,
V_79 ) ;
if ( V_62 )
goto V_80;
V_62 = F_73 ( V_11 ) ;
if ( V_62 )
goto V_81;
V_62 = F_74 ( V_11 , V_37 ) ;
if ( V_62 )
goto V_82;
V_62 = F_75 ( V_2 , V_13 -> V_2 ) ;
if ( V_62 )
goto V_83;
V_62 = F_76 ( V_2 , V_84 , V_11 ) ;
if ( V_62 )
goto V_85;
V_2 -> V_28 |= V_29 ;
F_77 ( V_2 ) ;
F_78 ( & V_11 -> V_27 , & V_13 -> V_57 ) ;
F_79 ( V_13 -> V_2 ) ;
if ( V_13 -> V_2 -> V_86 < V_2 -> V_86 )
V_13 -> V_2 -> V_86 = V_2 -> V_86 ;
if ( F_80 ( V_13 , V_11 , V_2 -> V_68 , 0 ) )
F_81 ( V_2 , L_3 ) ;
F_7 ( & V_13 -> V_17 ) ;
V_63 = F_82 ( V_13 ) ;
if ( F_5 ( V_2 ) && F_6 ( V_2 ) &&
( V_13 -> V_2 -> V_14 & V_54 ) )
F_8 ( V_11 ) ;
F_10 ( & V_13 -> V_17 ) ;
F_21 ( V_87 , V_11 ) ;
if ( V_63 )
F_71 ( V_88 , V_13 -> V_2 ) ;
F_83 ( V_13 -> V_2 , F_61 ( V_13 ) ) ;
F_28 ( & V_11 -> V_21 , V_89 ) ;
return 0 ;
V_85:
F_26 ( V_2 , V_13 -> V_2 ) ;
V_83:
F_30 ( V_11 ) ;
V_82:
F_19 ( V_13 -> V_25 , V_11 -> V_2 -> V_9 ) ;
V_81:
F_16 ( & V_11 -> V_21 ) ;
V_11 = NULL ;
V_80:
F_20 ( V_2 , - 1 ) ;
V_77:
F_15 ( V_2 ) ;
F_13 ( V_11 ) ;
return V_62 ;
}
int F_84 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_10 * V_11 ;
bool V_63 ;
V_11 = F_85 ( V_2 ) ;
if ( ! V_11 || V_11 -> V_13 != V_13 )
return - V_69 ;
F_18 ( V_11 ) ;
F_7 ( & V_13 -> V_17 ) ;
V_63 = F_82 ( V_13 ) ;
F_10 ( & V_13 -> V_17 ) ;
if ( V_63 )
F_71 ( V_88 , V_13 -> V_2 ) ;
F_79 ( V_13 -> V_2 ) ;
return 0 ;
}
