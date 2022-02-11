static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 =
F_2 ( F_3 ( V_2 -> V_8 -> V_8 ) ) ;
struct V_9 * V_10 =
F_4 ( F_5 ( V_2 -> V_8 -> V_8 ) ) ;
struct V_11 V_12 ;
int V_13 ;
F_6 ( & V_7 -> V_14 ) ;
V_13 = F_7 ( V_10 , V_15 ,
& V_12 , sizeof( struct V_11 ) ) ;
F_8 ( & V_7 -> V_14 ) ;
if ( V_13 )
return V_13 ;
return snprintf ( V_5 , V_16 , L_1 , V_12 . V_17 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char const * V_5 , T_2 V_18 )
{
struct V_6 * V_7 =
F_2 ( F_3 ( V_2 -> V_8 -> V_8 ) ) ;
struct V_9 * V_10 =
F_4 ( F_5 ( V_2 -> V_8 -> V_8 ) ) ;
struct V_11 V_12 ;
unsigned long V_17 ;
int V_13 ;
V_13 = F_10 ( V_5 , 10 , & V_17 ) ;
if ( V_13 )
return V_13 ;
V_12 . V_19 = V_20 ;
V_12 . V_17 = V_17 ;
F_6 ( & V_7 -> V_14 ) ;
V_13 = F_11 ( V_10 , V_15 ,
& V_12 , sizeof( struct V_11 ) ) ;
F_8 ( & V_7 -> V_14 ) ;
if ( V_13 )
return V_13 ;
return V_18 ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 =
F_2 ( F_3 ( V_2 -> V_8 -> V_8 ) ) ;
struct V_9 * V_10 =
F_4 ( F_5 ( V_2 -> V_8 -> V_8 ) ) ;
struct V_21 V_12 ;
int V_13 ;
F_6 ( & V_7 -> V_14 ) ;
V_13 = F_7 ( V_10 , V_22 ,
& V_12 , sizeof( struct V_21 ) ) ;
F_8 ( & V_7 -> V_14 ) ;
if ( V_13 )
return V_13 ;
return snprintf ( V_5 , V_16 , L_1 , V_12 . V_23 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char const * V_5 , T_2 V_18 )
{
struct V_6 * V_7 =
F_2 ( F_3 ( V_2 -> V_8 -> V_8 ) ) ;
struct V_9 * V_10 =
F_4 ( F_5 ( V_2 -> V_8 -> V_8 ) ) ;
struct V_21 V_12 ;
unsigned long V_23 ;
int V_13 ;
V_13 = F_10 ( V_5 , 10 , & V_23 ) ;
if ( V_13 )
return V_13 ;
V_12 . V_19 = V_24 ;
V_12 . V_23 = V_23 ;
F_6 ( & V_7 -> V_14 ) ;
V_13 = F_11 ( V_10 , V_22 ,
& V_12 , sizeof( struct V_21 ) ) ;
F_8 ( & V_7 -> V_14 ) ;
if ( V_13 )
return V_13 ;
return V_18 ;
}
static int F_14 ( struct V_9 * V_10 )
{
struct V_25 V_12 ;
int V_13 ;
V_13 = F_7 ( V_10 , V_26 ,
& V_12 , sizeof( struct V_25 ) ) ;
if ( V_13 )
return V_13 ;
return V_12 . V_27 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 =
F_2 ( F_3 ( V_2 -> V_8 -> V_8 ) ) ;
return snprintf ( V_5 , V_16 , L_1 , V_7 -> V_27 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char const * V_5 , T_2 V_18 )
{
struct V_6 * V_7 =
F_2 ( F_3 ( V_2 -> V_8 -> V_8 ) ) ;
struct V_9 * V_10 =
F_4 ( F_5 ( V_2 -> V_8 -> V_8 ) ) ;
struct V_25 V_12 ;
unsigned long V_28 ;
int V_13 ;
V_13 = F_10 ( V_5 , 10 , & V_28 ) ;
if ( V_13 )
return V_13 ;
V_12 . V_19 = V_29 ;
V_12 . V_27 = V_28 ;
F_6 ( & V_7 -> V_14 ) ;
V_13 = F_11 ( V_10 , V_26 ,
& V_12 , sizeof( struct V_25 ) ) ;
if ( ! V_13 ) {
V_7 -> V_27 = V_28 ;
V_13 = V_18 ;
}
F_8 ( & V_7 -> V_14 ) ;
return V_13 ;
}
static T_1 F_17 ( struct V_30 * V_31 ,
struct V_32 * V_33 , void const * V_5 ,
T_3 V_34 , T_2 V_35 , T_2 V_36 , T_4 V_19 )
{
struct V_1 * V_2 =
F_18 ( V_33 , struct V_1 , V_33 ) -> V_8 -> V_8 ;
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
struct V_9 * V_10 = F_4 ( F_5 ( V_2 ) ) ;
int V_13 ;
if ( V_34 != 0 || V_35 != V_36 )
return - V_37 ;
F_6 ( & V_7 -> V_14 ) ;
V_13 = F_11 ( V_10 , V_19 , V_5 , V_36 ) ;
F_8 ( & V_7 -> V_14 ) ;
return ( V_13 ? V_13 : V_36 ) ;
}
static T_1 F_19 ( struct V_30 * V_31 ,
struct V_32 * V_33 , void * V_5 , T_3 V_34 ,
T_2 V_35 , T_2 V_36 , T_4 V_19 )
{
struct V_1 * V_2 =
F_18 ( V_33 , struct V_1 , V_33 ) -> V_8 -> V_8 ;
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
struct V_9 * V_10 = F_4 ( F_5 ( V_2 ) ) ;
int V_13 ;
if ( V_34 >= V_36 )
return 0 ;
if ( V_34 != 0 || V_35 != V_36 )
return - V_37 ;
F_6 ( & V_7 -> V_14 ) ;
V_13 = F_7 ( V_10 , V_19 , V_5 , V_36 ) ;
F_8 ( & V_7 -> V_14 ) ;
return ( V_13 ? V_13 : V_36 ) ;
}
static T_1 F_20 ( struct V_30 * V_31 ,
struct V_32 * V_33 , struct V_38 * V_4 , char * V_5 ,
T_3 V_34 , T_2 V_35 )
{
return F_17 ( V_31 , V_33 , V_5 , V_34 , V_35 ,
sizeof( struct V_39 ) , V_40 ) ;
}
static T_1 F_21 ( struct V_30 * V_31 ,
struct V_32 * V_33 , struct V_38 * V_4 , char * V_5 ,
T_3 V_34 , T_2 V_35 )
{
return F_19 ( V_31 , V_33 , V_5 , V_34 , V_35 ,
sizeof( struct V_41 ) , V_42 ) ;
}
static int F_22 ( struct V_9 * V_10 ,
struct V_6 * V_7 )
{
int V_13 ;
F_23 ( & V_7 -> V_14 ) ;
V_13 = F_14 ( V_10 ) ;
if ( V_13 < 0 )
return V_13 ;
V_7 -> V_27 = V_13 ;
return 0 ;
}
static int F_24 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = F_5 ( V_44 -> V_2 . V_8 ) ;
struct V_9 * V_10 = F_4 ( V_46 ) ;
struct V_6 * V_7 ;
int V_13 ;
if ( V_46 -> V_47 -> V_48 . V_49
== V_50 ) {
F_25 ( V_44 , NULL ) ;
return 0 ;
}
V_7 = F_26 ( sizeof( * V_7 ) , V_51 ) ;
if ( ! V_7 ) {
F_27 ( V_44 , L_2 ) ;
return - V_52 ;
}
F_25 ( V_44 , V_7 ) ;
V_13 = F_22 ( V_10 , V_7 ) ;
if ( V_13 ) {
F_27 ( V_44 , L_3 ) ;
goto V_53;
}
V_13 = F_28 ( V_54 , V_44 ,
sizeof( struct V_55 ) ) ;
if ( V_13 < 0 ) {
F_27 ( V_44 , L_4 ) ;
} else {
V_7 -> V_56 = V_13 ;
V_7 -> V_57 = 1 ;
}
return 0 ;
V_53:
F_29 ( V_7 ) ;
return V_13 ;
}
static void F_30 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = F_5 ( V_44 -> V_2 . V_8 ) ;
struct V_6 * V_7 ;
if ( V_46 -> V_47 -> V_48 . V_49
== V_50 )
return;
V_7 = F_2 ( V_44 ) ;
if ( V_7 -> V_57 )
F_31 ( V_7 -> V_56 ) ;
F_29 ( V_7 ) ;
}
static int F_32 ( struct V_43 * V_44 ,
const struct V_58 * V_59 )
{
int V_13 ;
V_13 = F_33 ( V_44 ) ;
if ( V_13 ) {
F_27 ( V_44 , L_5 ) ;
goto exit;
}
V_13 = F_34 ( V_44 , V_60 ) ;
if ( V_13 ) {
F_27 ( V_44 , L_6 ) ;
goto exit;
}
V_13 = F_24 ( V_44 ) ;
if ( V_13 ) {
F_27 ( V_44 , L_7 ) ;
goto V_61;
}
return 0 ;
V_61:
F_35 ( V_44 ) ;
exit:
return V_13 ;
}
static void F_36 ( struct V_43 * V_44 )
{
F_30 ( V_44 ) ;
F_35 ( V_44 ) ;
}
static void F_37 ( struct V_6 const * V_7 ,
T_5 const * V_62 )
{
struct V_63 const * V_64 ;
struct V_55 V_65 ;
V_64 = (struct V_63 const * ) V_62 ;
V_65 . V_28 = V_7 -> V_27 ;
V_65 . V_66 = V_64 -> V_67 &
V_68 ;
if ( ( V_64 -> V_67 & V_69 ) ==
V_70 )
V_65 . V_71 = V_72 ;
else
V_65 . V_71 = V_73 ;
F_38 ( V_7 -> V_56 ,
( V_74 const * ) & V_65 ) ;
}
static int F_39 ( struct V_43 * V_44 ,
struct V_75 * V_76 , T_5 * V_62 , int V_18 )
{
struct V_6 * V_7 = F_2 ( V_44 ) ;
if ( V_18 != 3 )
return 0 ;
if ( V_7 -> V_57 )
F_37 ( V_7 , V_62 ) ;
return 0 ;
}
static int T_6 F_40 ( void )
{
int V_13 ;
V_54 = F_41 ( V_77 , L_8 ) ;
if ( F_42 ( V_54 ) )
return F_43 ( V_54 ) ;
V_54 -> V_78 = V_79 ;
V_54 -> V_80 = V_81 ;
V_13 = F_44 ( & V_82 ) ;
if ( V_13 )
F_45 ( V_54 ) ;
return V_13 ;
}
static void T_7 F_46 ( void )
{
F_47 ( & V_82 ) ;
F_45 ( V_54 ) ;
}
