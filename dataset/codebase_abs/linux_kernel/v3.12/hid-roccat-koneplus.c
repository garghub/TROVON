static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
V_2 -> V_4 = V_3 ;
}
static int F_2 ( struct V_5 * V_6 , T_1 V_7 ,
enum V_8 V_9 )
{
struct V_10 V_11 ;
if ( ( V_9 == V_12 ||
V_9 == V_13 ) &&
V_7 > 4 )
return - V_14 ;
V_11 . V_15 = V_16 ;
V_11 . V_7 = V_7 ;
V_11 . V_9 = V_9 ;
return F_3 ( V_6 ,
V_16 ,
& V_11 , sizeof( struct V_10 ) ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_17 V_18 ;
int V_19 ;
V_19 = F_5 ( V_6 , V_20 ,
& V_18 , V_21 ) ;
return V_19 ? V_19 : V_18 . V_4 ;
}
static int F_6 ( struct V_5 * V_6 ,
int V_3 )
{
struct V_17 V_18 ;
V_18 . V_15 = V_20 ;
V_18 . V_22 = V_21 ;
V_18 . V_4 = V_3 ;
return F_3 ( V_6 ,
V_20 ,
& V_18 , V_21 ) ;
}
static T_2 F_7 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_18 , T_3 V_27 , T_4 V_28 ,
T_4 V_29 , T_1 V_15 )
{
struct V_30 * V_31 =
F_8 ( V_26 , struct V_30 , V_26 ) -> V_32 -> V_32 ;
struct V_1 * V_2 = F_9 ( F_10 ( V_31 ) ) ;
struct V_5 * V_6 = F_11 ( F_12 ( V_31 ) ) ;
int V_19 ;
if ( V_27 >= V_29 )
return 0 ;
if ( V_27 != 0 || V_28 != V_29 )
return - V_14 ;
F_13 ( & V_2 -> V_33 ) ;
V_19 = F_5 ( V_6 , V_15 , V_18 , V_29 ) ;
F_14 ( & V_2 -> V_33 ) ;
if ( V_19 )
return V_19 ;
return V_29 ;
}
static T_2 F_15 ( struct V_23 * V_24 , struct V_25 * V_26 ,
void const * V_18 , T_3 V_27 , T_4 V_28 ,
T_4 V_29 , T_1 V_15 )
{
struct V_30 * V_31 =
F_8 ( V_26 , struct V_30 , V_26 ) -> V_32 -> V_32 ;
struct V_1 * V_2 = F_9 ( F_10 ( V_31 ) ) ;
struct V_5 * V_6 = F_11 ( F_12 ( V_31 ) ) ;
int V_19 ;
if ( V_27 != 0 || V_28 != V_29 )
return - V_14 ;
F_13 ( & V_2 -> V_33 ) ;
V_19 = F_3 ( V_6 , V_15 ,
V_18 , V_29 ) ;
F_14 ( & V_2 -> V_33 ) ;
if ( V_19 )
return V_19 ;
return V_29 ;
}
static T_2 F_16 ( struct V_23 * V_24 ,
struct V_25 * V_26 , struct V_34 * V_35 , char * V_18 ,
T_3 V_27 , T_4 V_28 )
{
struct V_30 * V_31 =
F_8 ( V_26 , struct V_30 , V_26 ) -> V_32 -> V_32 ;
struct V_5 * V_6 = F_11 ( F_12 ( V_31 ) ) ;
T_2 V_19 ;
V_19 = F_2 ( V_6 , * ( T_1 * ) ( V_35 -> V_36 ) ,
V_12 ) ;
if ( V_19 )
return V_19 ;
return F_7 ( V_24 , V_26 , V_18 , V_27 , V_28 ,
V_37 ,
V_38 ) ;
}
static T_2 F_17 ( struct V_23 * V_24 ,
struct V_25 * V_26 , struct V_34 * V_35 , char * V_18 ,
T_3 V_27 , T_4 V_28 )
{
struct V_30 * V_31 =
F_8 ( V_26 , struct V_30 , V_26 ) -> V_32 -> V_32 ;
struct V_5 * V_6 = F_11 ( F_12 ( V_31 ) ) ;
T_2 V_19 ;
V_19 = F_2 ( V_6 , * ( T_1 * ) ( V_35 -> V_36 ) ,
V_13 ) ;
if ( V_19 )
return V_19 ;
return F_7 ( V_24 , V_26 , V_18 , V_27 , V_28 ,
V_39 ,
V_40 ) ;
}
static T_2 F_18 ( struct V_30 * V_31 ,
struct V_41 * V_35 , char * V_18 )
{
struct V_1 * V_2 =
F_9 ( F_10 ( V_31 -> V_32 -> V_32 ) ) ;
return snprintf ( V_18 , V_42 , L_1 , V_2 -> V_4 ) ;
}
static T_2 F_19 ( struct V_30 * V_31 ,
struct V_41 * V_35 , char const * V_18 , T_4 V_22 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
unsigned long V_43 ;
int V_19 ;
struct V_44 V_45 ;
V_31 = V_31 -> V_32 -> V_32 ;
V_2 = F_9 ( F_10 ( V_31 ) ) ;
V_6 = F_11 ( F_12 ( V_31 ) ) ;
V_19 = F_20 ( V_18 , 10 , & V_43 ) ;
if ( V_19 )
return V_19 ;
if ( V_43 > 4 )
return - V_14 ;
F_13 ( & V_2 -> V_33 ) ;
V_19 = F_6 ( V_6 , V_43 ) ;
if ( V_19 ) {
F_14 ( & V_2 -> V_33 ) ;
return V_19 ;
}
F_1 ( V_2 , V_43 ) ;
V_45 . type = V_46 ;
V_45 . V_47 = V_43 + 1 ;
V_45 . V_48 = 0 ;
V_45 . V_43 = V_43 + 1 ;
F_21 ( V_2 -> V_49 ,
( V_50 const * ) & V_45 ) ;
F_14 ( & V_2 -> V_33 ) ;
return V_22 ;
}
static T_2 F_22 ( struct V_30 * V_31 ,
struct V_41 * V_35 , char * V_18 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_51 V_52 ;
V_31 = V_31 -> V_32 -> V_32 ;
V_2 = F_9 ( F_10 ( V_31 ) ) ;
V_6 = F_11 ( F_12 ( V_31 ) ) ;
F_13 ( & V_2 -> V_33 ) ;
F_5 ( V_6 , V_53 ,
& V_52 , V_54 ) ;
F_14 ( & V_2 -> V_33 ) ;
return snprintf ( V_18 , V_42 , L_1 , V_52 . V_55 ) ;
}
static int F_23 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
int V_19 ;
F_24 ( & V_2 -> V_33 ) ;
V_19 = F_4 ( V_6 ) ;
if ( V_19 < 0 )
return V_19 ;
F_1 ( V_2 , V_19 ) ;
return 0 ;
}
static int F_25 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_12 ( V_57 -> V_31 . V_32 ) ;
struct V_5 * V_6 = F_11 ( V_59 ) ;
struct V_1 * V_2 ;
int V_19 ;
if ( V_59 -> V_60 -> V_61 . V_62
== V_63 ) {
V_2 = F_26 ( sizeof( * V_2 ) , V_64 ) ;
if ( ! V_2 ) {
F_27 ( V_57 , L_2 ) ;
return - V_65 ;
}
F_28 ( V_57 , V_2 ) ;
V_19 = F_23 ( V_6 , V_2 ) ;
if ( V_19 ) {
F_27 ( V_57 , L_3 ) ;
goto V_66;
}
V_19 = F_29 ( V_67 , V_57 ,
sizeof( struct V_44 ) ) ;
if ( V_19 < 0 ) {
F_27 ( V_57 , L_4 ) ;
} else {
V_2 -> V_49 = V_19 ;
V_2 -> V_68 = 1 ;
}
} else {
F_28 ( V_57 , NULL ) ;
}
return 0 ;
V_66:
F_30 ( V_2 ) ;
return V_19 ;
}
static void F_31 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_12 ( V_57 -> V_31 . V_32 ) ;
struct V_1 * V_2 ;
if ( V_59 -> V_60 -> V_61 . V_62
== V_63 ) {
V_2 = F_9 ( V_57 ) ;
if ( V_2 -> V_68 )
F_32 ( V_2 -> V_49 ) ;
F_30 ( V_2 ) ;
}
}
static int F_33 ( struct V_56 * V_57 ,
const struct V_69 * V_70 )
{
int V_19 ;
V_19 = F_34 ( V_57 ) ;
if ( V_19 ) {
F_27 ( V_57 , L_5 ) ;
goto exit;
}
V_19 = F_35 ( V_57 , V_71 ) ;
if ( V_19 ) {
F_27 ( V_57 , L_6 ) ;
goto exit;
}
V_19 = F_25 ( V_57 ) ;
if ( V_19 ) {
F_27 ( V_57 , L_7 ) ;
goto V_72;
}
return 0 ;
V_72:
F_36 ( V_57 ) ;
exit:
return V_19 ;
}
static void F_37 ( struct V_56 * V_57 )
{
F_31 ( V_57 ) ;
F_36 ( V_57 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
T_5 const * V_73 )
{
struct V_74 const * V_75 ;
switch ( V_73 [ 0 ] ) {
case V_76 :
V_75 = (struct V_74 const * ) V_73 ;
switch ( V_75 -> type ) {
case V_46 :
F_1 ( V_2 , V_75 -> V_47 - 1 ) ;
break;
}
break;
}
}
static void F_39 ( struct V_1 const * V_2 ,
T_5 const * V_73 )
{
struct V_44 V_45 ;
struct V_74 const * V_75 ;
if ( V_73 [ 0 ] != V_76 )
return;
V_75 = (struct V_74 const * ) V_73 ;
if ( ( V_75 -> type == V_77 ||
V_75 -> type == V_78 ) &&
V_75 -> V_48 != V_79 )
return;
V_45 . type = V_75 -> type ;
V_45 . V_47 = V_75 -> V_47 ;
V_45 . V_48 = V_75 -> V_48 ;
V_45 . V_43 = V_2 -> V_4 + 1 ;
F_21 ( V_2 -> V_49 ,
( V_50 const * ) & V_45 ) ;
}
static int F_40 ( struct V_56 * V_57 ,
struct V_80 * V_81 , T_5 * V_73 , int V_22 )
{
struct V_58 * V_59 = F_12 ( V_57 -> V_31 . V_32 ) ;
struct V_1 * V_2 = F_9 ( V_57 ) ;
if ( V_59 -> V_60 -> V_61 . V_62
!= V_63 )
return 0 ;
if ( V_2 == NULL )
return 0 ;
F_38 ( V_2 , V_73 ) ;
if ( V_2 -> V_68 )
F_39 ( V_2 , V_73 ) ;
return 0 ;
}
static int T_6 F_41 ( void )
{
int V_19 ;
V_67 = F_42 ( V_82 , L_8 ) ;
if ( F_43 ( V_67 ) )
return F_44 ( V_67 ) ;
V_67 -> V_83 = V_84 ;
V_19 = F_45 ( & V_85 ) ;
if ( V_19 )
F_46 ( V_67 ) ;
return V_19 ;
}
static void T_7 F_47 ( void )
{
F_48 ( & V_85 ) ;
F_46 ( V_67 ) ;
}
