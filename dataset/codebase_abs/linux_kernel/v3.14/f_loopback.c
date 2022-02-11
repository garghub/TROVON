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
V_44 = F_17 ( V_9 -> V_16 , V_42 , V_48 ) ;
if ( V_44 == 0 )
return;
ERROR ( V_8 , L_6 ,
V_40 -> V_20 , V_9 -> V_16 -> V_20 ,
V_44 ) ;
}
V_42 -> V_47 = V_49 ;
V_44 = F_17 ( V_9 -> V_23 , V_42 , V_48 ) ;
if ( V_44 == 0 )
return;
default:
ERROR ( V_8 , L_7 , V_40 -> V_20 ,
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
F_21 ( V_8 , L_8 , V_9 -> V_4 . V_20 ) ;
}
static inline struct V_41 * F_22 ( struct V_39 * V_40 , int V_53 )
{
return F_23 ( V_40 , V_53 , V_49 ) ;
}
static int
F_24 ( struct V_7 * V_8 , struct V_1 * V_9 )
{
int V_54 = 0 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
unsigned V_55 ;
V_40 = V_9 -> V_16 ;
V_54 = F_25 ( V_8 -> V_17 , & ( V_9 -> V_4 ) , V_40 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_26 ( V_40 ) ;
if ( V_54 < 0 )
return V_54 ;
V_40 -> V_22 = V_9 ;
V_40 = V_9 -> V_23 ;
V_54 = F_25 ( V_8 -> V_17 , & ( V_9 -> V_4 ) , V_40 ) ;
if ( V_54 )
goto V_56;
V_54 = F_26 ( V_40 ) ;
if ( V_54 < 0 ) {
V_56:
V_40 = V_9 -> V_16 ;
F_27 ( V_40 ) ;
V_40 -> V_22 = NULL ;
return V_54 ;
}
V_40 -> V_22 = V_9 ;
for ( V_55 = 0 ; V_55 < V_57 && V_54 == 0 ; V_55 ++ ) {
V_42 = F_22 ( V_40 , 0 ) ;
if ( V_42 ) {
V_42 -> V_58 = F_16 ;
V_54 = F_17 ( V_40 , V_42 , V_48 ) ;
if ( V_54 )
ERROR ( V_8 , L_9 ,
V_40 -> V_20 , V_54 ) ;
} else {
F_27 ( V_40 ) ;
V_40 -> V_22 = NULL ;
V_54 = - V_59 ;
goto V_56;
}
}
F_8 ( V_8 , L_10 , V_9 -> V_4 . V_20 ) ;
return V_54 ;
}
static int F_28 ( struct V_2 * V_3 ,
unsigned V_60 , unsigned V_61 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_43 -> V_8 ;
if ( V_9 -> V_16 -> V_22 )
F_19 ( V_9 ) ;
return F_24 ( V_8 , V_9 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_19 ( V_9 ) ;
}
static struct V_2 * F_30 ( struct V_62 * V_35 )
{
struct V_1 * V_9 ;
struct V_33 * V_63 ;
V_9 = F_31 ( sizeof *V_9 , V_64 ) ;
if ( ! V_9 )
return F_32 ( - V_59 ) ;
V_63 = F_2 ( V_35 , struct V_33 , V_36 ) ;
F_12 ( & V_63 -> V_37 ) ;
V_63 -> V_38 ++ ;
F_13 ( & V_63 -> V_37 ) ;
V_49 = V_63 -> V_65 ;
V_57 = V_63 -> V_57 ;
if ( ! V_57 )
V_57 = 32 ;
V_9 -> V_4 . V_20 = L_11 ;
V_9 -> V_4 . V_66 = F_3 ;
V_9 -> V_4 . V_67 = F_28 ;
V_9 -> V_4 . V_68 = F_29 ;
V_9 -> V_4 . V_69 = V_70 ;
V_9 -> V_4 . V_71 = F_11 ;
return & V_9 -> V_4 ;
}
static inline struct V_33 * F_33 ( struct V_72 * V_73 )
{
return F_2 ( F_34 ( V_73 ) , struct V_33 ,
V_36 . V_74 ) ;
}
static void F_35 ( struct V_72 * V_73 )
{
struct V_33 * V_63 = F_33 ( V_73 ) ;
F_36 ( & V_63 -> V_36 ) ;
}
static T_1 F_37 ( struct V_33 * V_34 , char * V_75 )
{
int V_54 ;
F_12 ( & V_34 -> V_37 ) ;
V_54 = sprintf ( V_75 , L_12 , V_34 -> V_57 ) ;
F_13 ( & V_34 -> V_37 ) ;
return V_54 ;
}
static T_1 F_38 ( struct V_33 * V_34 ,
const char * V_75 , T_2 V_53 )
{
int V_11 ;
T_3 V_76 ;
F_12 ( & V_34 -> V_37 ) ;
if ( V_34 -> V_38 ) {
V_11 = - V_77 ;
goto V_78;
}
V_11 = F_39 ( V_75 , 0 , & V_76 ) ;
if ( V_11 )
goto V_78;
V_34 -> V_57 = V_76 ;
V_11 = V_53 ;
V_78:
F_13 ( & V_34 -> V_37 ) ;
return V_11 ;
}
static T_1 F_40 ( struct V_33 * V_34 , char * V_75 )
{
int V_54 ;
F_12 ( & V_34 -> V_37 ) ;
V_54 = sprintf ( V_75 , L_12 , V_34 -> V_65 ) ;
F_13 ( & V_34 -> V_37 ) ;
return V_54 ;
}
static T_1 F_41 ( struct V_33 * V_34 ,
const char * V_75 , T_2 V_53 )
{
int V_11 ;
T_3 V_76 ;
F_12 ( & V_34 -> V_37 ) ;
if ( V_34 -> V_38 ) {
V_11 = - V_77 ;
goto V_78;
}
V_11 = F_39 ( V_75 , 0 , & V_76 ) ;
if ( V_11 )
goto V_78;
V_34 -> V_65 = V_76 ;
V_11 = V_53 ;
V_78:
F_13 ( & V_34 -> V_37 ) ;
return V_11 ;
}
static void F_42 ( struct V_62 * V_35 )
{
struct V_33 * V_63 ;
V_63 = F_2 ( V_35 , struct V_33 , V_36 ) ;
F_15 ( V_63 ) ;
}
static struct V_62 * F_43 ( void )
{
struct V_33 * V_63 ;
V_63 = F_31 ( sizeof( * V_63 ) , V_64 ) ;
if ( ! V_63 )
return F_32 ( - V_59 ) ;
F_44 ( & V_63 -> V_37 ) ;
V_63 -> V_36 . V_79 = F_42 ;
V_63 -> V_65 = V_80 ;
V_63 -> V_57 = V_81 ;
F_45 ( & V_63 -> V_36 . V_74 , L_13 ,
& V_82 ) ;
return & V_63 -> V_36 ;
}
int T_4 F_46 ( void )
{
int V_11 ;
V_11 = F_47 ( & V_83 ) ;
if ( V_11 )
return V_11 ;
return V_11 ;
}
void T_5 F_48 ( void )
{
F_49 ( & V_83 ) ;
}
