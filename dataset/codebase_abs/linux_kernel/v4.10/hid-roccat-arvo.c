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
V_12 . V_19 = V_15 ;
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
struct V_20 V_12 ;
int V_13 ;
F_6 ( & V_7 -> V_14 ) ;
V_13 = F_7 ( V_10 , V_21 ,
& V_12 , sizeof( struct V_20 ) ) ;
F_8 ( & V_7 -> V_14 ) ;
if ( V_13 )
return V_13 ;
return snprintf ( V_5 , V_16 , L_1 , V_12 . V_22 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char const * V_5 , T_2 V_18 )
{
struct V_6 * V_7 =
F_2 ( F_3 ( V_2 -> V_8 -> V_8 ) ) ;
struct V_9 * V_10 =
F_4 ( F_5 ( V_2 -> V_8 -> V_8 ) ) ;
struct V_20 V_12 ;
unsigned long V_22 ;
int V_13 ;
V_13 = F_10 ( V_5 , 10 , & V_22 ) ;
if ( V_13 )
return V_13 ;
V_12 . V_19 = V_21 ;
V_12 . V_22 = V_22 ;
F_6 ( & V_7 -> V_14 ) ;
V_13 = F_11 ( V_10 , V_21 ,
& V_12 , sizeof( struct V_20 ) ) ;
F_8 ( & V_7 -> V_14 ) ;
if ( V_13 )
return V_13 ;
return V_18 ;
}
static int F_14 ( struct V_9 * V_10 )
{
struct V_23 V_12 ;
int V_13 ;
V_13 = F_7 ( V_10 , V_24 ,
& V_12 , sizeof( struct V_23 ) ) ;
if ( V_13 )
return V_13 ;
return V_12 . V_25 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 =
F_2 ( F_3 ( V_2 -> V_8 -> V_8 ) ) ;
return snprintf ( V_5 , V_16 , L_1 , V_7 -> V_25 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char const * V_5 , T_2 V_18 )
{
struct V_6 * V_7 =
F_2 ( F_3 ( V_2 -> V_8 -> V_8 ) ) ;
struct V_9 * V_10 =
F_4 ( F_5 ( V_2 -> V_8 -> V_8 ) ) ;
struct V_23 V_12 ;
unsigned long V_26 ;
int V_13 ;
V_13 = F_10 ( V_5 , 10 , & V_26 ) ;
if ( V_13 )
return V_13 ;
if ( V_26 < 1 || V_26 > 5 )
return - V_27 ;
V_12 . V_19 = V_24 ;
V_12 . V_25 = V_26 ;
F_6 ( & V_7 -> V_14 ) ;
V_13 = F_11 ( V_10 , V_24 ,
& V_12 , sizeof( struct V_23 ) ) ;
if ( ! V_13 ) {
V_7 -> V_25 = V_26 ;
V_13 = V_18 ;
}
F_8 ( & V_7 -> V_14 ) ;
return V_13 ;
}
static T_1 F_17 ( struct V_28 * V_29 ,
struct V_30 * V_31 , void const * V_5 ,
T_3 V_32 , T_2 V_33 , T_2 V_34 , T_4 V_19 )
{
struct V_1 * V_2 = F_18 ( V_31 ) -> V_8 -> V_8 ;
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
struct V_9 * V_10 = F_4 ( F_5 ( V_2 ) ) ;
int V_13 ;
if ( V_32 != 0 || V_33 != V_34 )
return - V_27 ;
F_6 ( & V_7 -> V_14 ) ;
V_13 = F_11 ( V_10 , V_19 , V_5 , V_34 ) ;
F_8 ( & V_7 -> V_14 ) ;
return ( V_13 ? V_13 : V_34 ) ;
}
static T_1 F_19 ( struct V_28 * V_29 ,
struct V_30 * V_31 , void * V_5 , T_3 V_32 ,
T_2 V_33 , T_2 V_34 , T_4 V_19 )
{
struct V_1 * V_2 = F_18 ( V_31 ) -> V_8 -> V_8 ;
struct V_6 * V_7 = F_2 ( F_3 ( V_2 ) ) ;
struct V_9 * V_10 = F_4 ( F_5 ( V_2 ) ) ;
int V_13 ;
if ( V_32 >= V_34 )
return 0 ;
if ( V_32 != 0 || V_33 != V_34 )
return - V_27 ;
F_6 ( & V_7 -> V_14 ) ;
V_13 = F_7 ( V_10 , V_19 , V_5 , V_34 ) ;
F_8 ( & V_7 -> V_14 ) ;
return ( V_13 ? V_13 : V_34 ) ;
}
static T_1 F_20 ( struct V_28 * V_29 ,
struct V_30 * V_31 , struct V_35 * V_4 , char * V_5 ,
T_3 V_32 , T_2 V_33 )
{
return F_17 ( V_29 , V_31 , V_5 , V_32 , V_33 ,
sizeof( struct V_36 ) , V_37 ) ;
}
static T_1 F_21 ( struct V_28 * V_29 ,
struct V_30 * V_31 , struct V_35 * V_4 , char * V_5 ,
T_3 V_32 , T_2 V_33 )
{
return F_19 ( V_29 , V_31 , V_5 , V_32 , V_33 ,
sizeof( struct V_38 ) , V_39 ) ;
}
static int F_22 ( struct V_9 * V_10 ,
struct V_6 * V_7 )
{
int V_13 ;
F_23 ( & V_7 -> V_14 ) ;
V_13 = F_14 ( V_10 ) ;
if ( V_13 < 0 )
return V_13 ;
V_7 -> V_25 = V_13 ;
return 0 ;
}
static int F_24 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = F_5 ( V_41 -> V_2 . V_8 ) ;
struct V_9 * V_10 = F_4 ( V_43 ) ;
struct V_6 * V_7 ;
int V_13 ;
if ( V_43 -> V_44 -> V_45 . V_46
== V_47 ) {
F_25 ( V_41 , NULL ) ;
return 0 ;
}
V_7 = F_26 ( sizeof( * V_7 ) , V_48 ) ;
if ( ! V_7 ) {
F_27 ( V_41 , L_2 ) ;
return - V_49 ;
}
F_25 ( V_41 , V_7 ) ;
V_13 = F_22 ( V_10 , V_7 ) ;
if ( V_13 ) {
F_27 ( V_41 , L_3 ) ;
goto V_50;
}
V_13 = F_28 ( V_51 , V_41 ,
sizeof( struct V_52 ) ) ;
if ( V_13 < 0 ) {
F_27 ( V_41 , L_4 ) ;
} else {
V_7 -> V_53 = V_13 ;
V_7 -> V_54 = 1 ;
}
return 0 ;
V_50:
F_29 ( V_7 ) ;
return V_13 ;
}
static void F_30 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = F_5 ( V_41 -> V_2 . V_8 ) ;
struct V_6 * V_7 ;
if ( V_43 -> V_44 -> V_45 . V_46
== V_47 )
return;
V_7 = F_2 ( V_41 ) ;
if ( V_7 -> V_54 )
F_31 ( V_7 -> V_53 ) ;
F_29 ( V_7 ) ;
}
static int F_32 ( struct V_40 * V_41 ,
const struct V_55 * V_56 )
{
int V_13 ;
V_13 = F_33 ( V_41 ) ;
if ( V_13 ) {
F_27 ( V_41 , L_5 ) ;
goto exit;
}
V_13 = F_34 ( V_41 , V_57 ) ;
if ( V_13 ) {
F_27 ( V_41 , L_6 ) ;
goto exit;
}
V_13 = F_24 ( V_41 ) ;
if ( V_13 ) {
F_27 ( V_41 , L_7 ) ;
goto V_58;
}
return 0 ;
V_58:
F_35 ( V_41 ) ;
exit:
return V_13 ;
}
static void F_36 ( struct V_40 * V_41 )
{
F_30 ( V_41 ) ;
F_35 ( V_41 ) ;
}
static void F_37 ( struct V_6 const * V_7 ,
T_5 const * V_59 )
{
struct V_60 const * V_61 ;
struct V_52 V_62 ;
V_61 = (struct V_60 const * ) V_59 ;
V_62 . V_26 = V_7 -> V_25 ;
V_62 . V_63 = V_61 -> V_64 &
V_65 ;
if ( ( V_61 -> V_64 & V_66 ) ==
V_67 )
V_62 . V_68 = V_69 ;
else
V_62 . V_68 = V_70 ;
F_38 ( V_7 -> V_53 ,
( V_71 const * ) & V_62 ) ;
}
static int F_39 ( struct V_40 * V_41 ,
struct V_72 * V_73 , T_5 * V_59 , int V_18 )
{
struct V_6 * V_7 = F_2 ( V_41 ) ;
if ( V_18 != 3 )
return 0 ;
if ( V_7 && V_7 -> V_54 )
F_37 ( V_7 , V_59 ) ;
return 0 ;
}
static int T_6 F_40 ( void )
{
int V_13 ;
V_51 = F_41 ( V_74 , L_8 ) ;
if ( F_42 ( V_51 ) )
return F_43 ( V_51 ) ;
V_51 -> V_75 = V_76 ;
V_13 = F_44 ( & V_77 ) ;
if ( V_13 )
F_45 ( V_51 ) ;
return V_13 ;
}
static void T_7 F_46 ( void )
{
F_47 ( & V_77 ) ;
F_45 ( V_51 ) ;
}
