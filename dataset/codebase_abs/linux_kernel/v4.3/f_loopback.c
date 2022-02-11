static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_10 ;
int V_11 ;
V_10 = F_4 ( V_6 , V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_12 . V_13 = V_10 ;
V_10 = F_5 ( V_8 ) ;
if ( V_10 < 0 )
return V_10 ;
V_14 [ 0 ] . V_10 = V_10 ;
V_12 . V_15 = V_10 ;
V_9 -> V_16 = F_6 ( V_8 -> V_17 , & V_18 ) ;
if ( ! V_9 -> V_16 ) {
V_19:
ERROR ( V_8 , L_1 ,
V_3 -> V_20 , V_8 -> V_17 -> V_20 ) ;
return - V_21 ;
}
V_9 -> V_16 -> V_22 = V_8 ;
V_9 -> V_23 = F_6 ( V_8 -> V_17 , & V_24 ) ;
if ( ! V_9 -> V_23 )
goto V_19;
V_9 -> V_23 -> V_22 = V_8 ;
V_25 . V_26 =
V_18 . V_26 ;
V_27 . V_26 = V_24 . V_26 ;
V_28 . V_26 =
V_18 . V_26 ;
V_29 . V_26 = V_24 . V_26 ;
V_11 = F_7 ( V_3 , V_30 , V_31 ,
V_32 ) ;
if ( V_11 )
return V_11 ;
F_8 ( V_8 , L_2 ,
( F_9 ( V_6 -> V_8 -> V_17 ) ? L_3 :
( F_10 ( V_6 -> V_8 -> V_17 ) ? L_4 : L_5 ) ) ,
V_3 -> V_20 , V_9 -> V_16 -> V_20 , V_9 -> V_23 -> V_20 ) ;
return 0 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_33 * V_34 ;
V_34 = F_2 ( V_3 -> V_35 , struct V_33 , V_36 ) ;
F_12 ( & V_34 -> V_37 ) ;
V_34 -> V_38 -- ;
F_13 ( & V_34 -> V_37 ) ;
F_14 ( V_3 ) ;
F_15 ( F_1 ( V_3 ) ) ;
}
static void F_16 ( struct V_39 * V_40 , struct V_41 * V_42 )
{
struct V_1 * V_9 = V_40 -> V_22 ;
struct V_7 * V_8 = V_9 -> V_4 . V_43 -> V_8 ;
int V_44 = V_42 -> V_44 ;
switch ( V_44 ) {
case 0 :
if ( V_40 == V_9 -> V_23 ) {
V_42 -> V_45 = ( V_42 -> V_46 < V_42 -> V_47 ) ;
V_42 -> V_47 = V_42 -> V_46 ;
}
V_42 -> V_47 = V_48 ;
V_44 = F_17 ( V_40 , V_42 , V_49 ) ;
if ( V_44 == 0 )
return;
default:
ERROR ( V_8 , L_6 , V_40 -> V_20 ,
V_44 , V_42 -> V_46 , V_42 -> V_47 ) ;
case - V_50 :
case - V_51 :
case - V_52 :
F_18 ( V_40 , V_42 ) ;
return;
}
}
static void F_19 ( struct V_1 * V_9 )
{
struct V_7 * V_8 ;
V_8 = V_9 -> V_4 . V_43 -> V_8 ;
F_20 ( V_8 , V_9 -> V_16 , V_9 -> V_23 , NULL , NULL ) ;
F_21 ( V_8 , L_7 , V_9 -> V_4 . V_20 ) ;
}
static inline struct V_41 * F_22 ( struct V_39 * V_40 , int V_53 )
{
return F_23 ( V_40 , V_53 , V_48 ) ;
}
static int F_24 ( struct V_7 * V_8 , struct V_1 * V_9 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 ;
unsigned V_54 ;
int V_55 ;
V_55 = F_25 ( V_8 -> V_17 , & ( V_9 -> V_4 ) , V_40 ) ;
if ( V_55 )
goto V_56;
V_55 = F_26 ( V_40 ) ;
if ( V_55 < 0 )
goto V_56;
V_40 -> V_22 = V_9 ;
for ( V_54 = 0 ; V_54 < V_57 && V_55 == 0 ; V_54 ++ ) {
V_42 = F_22 ( V_40 , 0 ) ;
if ( ! V_42 )
goto V_58;
V_42 -> V_59 = F_16 ;
V_55 = F_17 ( V_40 , V_42 , V_49 ) ;
if ( V_55 ) {
ERROR ( V_8 , L_8 ,
V_40 -> V_20 , V_55 ) ;
goto V_58;
}
}
return 0 ;
V_58:
F_27 ( V_40 ) ;
V_56:
return V_55 ;
}
static int
F_28 ( struct V_7 * V_8 , struct V_1 * V_9 )
{
int V_55 = 0 ;
V_55 = F_24 ( V_8 , V_9 , V_9 -> V_16 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_24 ( V_8 , V_9 , V_9 -> V_23 ) ;
if ( V_55 )
return V_55 ;
F_8 ( V_8 , L_9 , V_9 -> V_4 . V_20 ) ;
return V_55 ;
}
static int F_29 ( struct V_2 * V_3 ,
unsigned V_60 , unsigned V_61 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_43 -> V_8 ;
if ( V_9 -> V_16 -> V_22 )
F_19 ( V_9 ) ;
return F_28 ( V_8 , V_9 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_19 ( V_9 ) ;
}
static struct V_2 * F_31 ( struct V_62 * V_35 )
{
struct V_1 * V_9 ;
struct V_33 * V_63 ;
V_9 = F_32 ( sizeof *V_9 , V_64 ) ;
if ( ! V_9 )
return F_33 ( - V_65 ) ;
V_63 = F_2 ( V_35 , struct V_33 , V_36 ) ;
F_12 ( & V_63 -> V_37 ) ;
V_63 -> V_38 ++ ;
F_13 ( & V_63 -> V_37 ) ;
V_48 = V_63 -> V_66 ;
V_57 = V_63 -> V_57 ;
if ( ! V_57 )
V_57 = 32 ;
V_9 -> V_4 . V_20 = L_10 ;
V_9 -> V_4 . V_67 = F_3 ;
V_9 -> V_4 . V_68 = F_29 ;
V_9 -> V_4 . V_69 = F_30 ;
V_9 -> V_4 . V_70 = V_71 ;
V_9 -> V_4 . V_72 = F_11 ;
return & V_9 -> V_4 ;
}
static inline struct V_33 * F_34 ( struct V_73 * V_74 )
{
return F_2 ( F_35 ( V_74 ) , struct V_33 ,
V_36 . V_75 ) ;
}
static void F_36 ( struct V_73 * V_74 )
{
struct V_33 * V_63 = F_34 ( V_74 ) ;
F_37 ( & V_63 -> V_36 ) ;
}
static T_1 F_38 ( struct V_33 * V_34 , char * V_76 )
{
int V_55 ;
F_12 ( & V_34 -> V_37 ) ;
V_55 = sprintf ( V_76 , L_11 , V_34 -> V_57 ) ;
F_13 ( & V_34 -> V_37 ) ;
return V_55 ;
}
static T_1 F_39 ( struct V_33 * V_34 ,
const char * V_76 , T_2 V_53 )
{
int V_11 ;
T_3 V_77 ;
F_12 ( & V_34 -> V_37 ) ;
if ( V_34 -> V_38 ) {
V_11 = - V_78 ;
goto V_79;
}
V_11 = F_40 ( V_76 , 0 , & V_77 ) ;
if ( V_11 )
goto V_79;
V_34 -> V_57 = V_77 ;
V_11 = V_53 ;
V_79:
F_13 ( & V_34 -> V_37 ) ;
return V_11 ;
}
static T_1 F_41 ( struct V_33 * V_34 , char * V_76 )
{
int V_55 ;
F_12 ( & V_34 -> V_37 ) ;
V_55 = sprintf ( V_76 , L_11 , V_34 -> V_66 ) ;
F_13 ( & V_34 -> V_37 ) ;
return V_55 ;
}
static T_1 F_42 ( struct V_33 * V_34 ,
const char * V_76 , T_2 V_53 )
{
int V_11 ;
T_3 V_77 ;
F_12 ( & V_34 -> V_37 ) ;
if ( V_34 -> V_38 ) {
V_11 = - V_78 ;
goto V_79;
}
V_11 = F_40 ( V_76 , 0 , & V_77 ) ;
if ( V_11 )
goto V_79;
V_34 -> V_66 = V_77 ;
V_11 = V_53 ;
V_79:
F_13 ( & V_34 -> V_37 ) ;
return V_11 ;
}
static void F_43 ( struct V_62 * V_35 )
{
struct V_33 * V_63 ;
V_63 = F_2 ( V_35 , struct V_33 , V_36 ) ;
F_15 ( V_63 ) ;
}
static struct V_62 * F_44 ( void )
{
struct V_33 * V_63 ;
V_63 = F_32 ( sizeof( * V_63 ) , V_64 ) ;
if ( ! V_63 )
return F_33 ( - V_65 ) ;
F_45 ( & V_63 -> V_37 ) ;
V_63 -> V_36 . V_80 = F_43 ;
V_63 -> V_66 = V_81 ;
V_63 -> V_57 = V_82 ;
F_46 ( & V_63 -> V_36 . V_75 , L_12 ,
& V_83 ) ;
return & V_63 -> V_36 ;
}
int T_4 F_47 ( void )
{
int V_11 ;
V_11 = F_48 ( & V_84 ) ;
if ( V_11 )
return V_11 ;
return V_11 ;
}
void T_5 F_49 ( void )
{
F_50 ( & V_84 ) ;
}
