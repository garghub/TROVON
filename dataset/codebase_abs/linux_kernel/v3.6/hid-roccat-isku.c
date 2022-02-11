static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 = V_3 ;
}
static int F_2 ( struct V_5 * V_6 , T_1 V_7 ,
void * V_8 , T_1 V_9 )
{
return F_3 ( V_6 , V_7 , V_8 , V_9 ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_10 V_8 ;
int V_11 ;
V_11 = F_2 ( V_6 , V_12 ,
& V_8 , sizeof( struct V_10 ) ) ;
return V_11 ? V_11 : V_8 . V_4 ;
}
static int F_5 ( struct V_5 * V_6 , int V_3 )
{
struct V_10 V_8 ;
V_8 . V_7 = V_12 ;
V_8 . V_9 = sizeof( struct V_10 ) ;
V_8 . V_4 = V_3 ;
return F_6 ( V_6 ,
V_12 , & V_8 ,
sizeof( struct V_10 ) ) ;
}
static T_2 F_7 ( struct V_13 * V_14 ,
struct V_15 * V_16 , char * V_8 )
{
struct V_1 * V_2 =
F_8 ( F_9 ( V_14 -> V_17 -> V_17 ) ) ;
return snprintf ( V_8 , V_18 , L_1 , V_2 -> V_4 ) ;
}
static T_2 F_10 ( struct V_13 * V_14 ,
struct V_15 * V_16 , char const * V_8 , T_3 V_9 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
unsigned long V_19 ;
int V_11 ;
struct V_20 V_21 ;
V_14 = V_14 -> V_17 -> V_17 ;
V_2 = F_8 ( F_9 ( V_14 ) ) ;
V_6 = F_11 ( F_12 ( V_14 ) ) ;
V_11 = F_13 ( V_8 , 10 , & V_19 ) ;
if ( V_11 )
return V_11 ;
if ( V_19 > 4 )
return - V_22 ;
F_14 ( & V_2 -> V_23 ) ;
V_11 = F_5 ( V_6 , V_19 ) ;
if ( V_11 ) {
F_15 ( & V_2 -> V_23 ) ;
return V_11 ;
}
F_1 ( V_2 , V_19 ) ;
V_21 . V_24 = V_25 ;
V_21 . V_26 = V_19 + 1 ;
V_21 . V_27 = 0 ;
V_21 . V_19 = V_19 + 1 ;
F_16 ( V_2 -> V_28 , ( V_29 const * ) & V_21 ) ;
F_15 ( & V_2 -> V_23 ) ;
return V_9 ;
}
static T_2 F_17 ( struct V_30 * V_31 , struct V_32 * V_33 ,
char * V_8 , T_4 V_34 , T_3 V_35 ,
T_3 V_36 , T_1 V_7 )
{
struct V_13 * V_14 =
F_18 ( V_33 , struct V_13 , V_33 ) -> V_17 -> V_17 ;
struct V_1 * V_2 = F_8 ( F_9 ( V_14 ) ) ;
struct V_5 * V_6 = F_11 ( F_12 ( V_14 ) ) ;
int V_11 ;
if ( V_34 >= V_36 )
return 0 ;
if ( V_34 != 0 || V_35 != V_36 )
return - V_22 ;
F_14 ( & V_2 -> V_23 ) ;
V_11 = F_2 ( V_6 , V_7 , V_8 , V_36 ) ;
F_15 ( & V_2 -> V_23 ) ;
return V_11 ? V_11 : V_36 ;
}
static T_2 F_19 ( struct V_30 * V_31 , struct V_32 * V_33 ,
void const * V_8 , T_4 V_34 , T_3 V_35 ,
T_3 V_36 , T_1 V_7 )
{
struct V_13 * V_14 =
F_18 ( V_33 , struct V_13 , V_33 ) -> V_17 -> V_17 ;
struct V_1 * V_2 = F_8 ( F_9 ( V_14 ) ) ;
struct V_5 * V_6 = F_11 ( F_12 ( V_14 ) ) ;
int V_11 ;
if ( V_34 != 0 || V_35 != V_36 )
return - V_22 ;
F_14 ( & V_2 -> V_23 ) ;
V_11 = F_6 ( V_6 , V_7 ,
( void * ) V_8 , V_36 ) ;
F_15 ( & V_2 -> V_23 ) ;
return V_11 ? V_11 : V_36 ;
}
static int F_20 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
int V_11 ;
F_21 ( & V_2 -> V_23 ) ;
V_11 = F_4 ( V_6 ) ;
if ( V_11 < 0 )
return V_11 ;
F_1 ( V_2 , V_11 ) ;
return 0 ;
}
static int F_22 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_12 ( V_38 -> V_14 . V_17 ) ;
struct V_5 * V_6 = F_11 ( V_40 ) ;
struct V_1 * V_2 ;
int V_11 ;
if ( V_40 -> V_41 -> V_42 . V_43
!= V_44 ) {
F_23 ( V_38 , NULL ) ;
return 0 ;
}
V_2 = F_24 ( sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 ) {
F_25 ( V_38 , L_2 ) ;
return - V_46 ;
}
F_23 ( V_38 , V_2 ) ;
V_11 = F_20 ( V_6 , V_2 ) ;
if ( V_11 ) {
F_25 ( V_38 , L_3 ) ;
goto V_47;
}
V_11 = F_26 ( V_48 , V_38 ,
sizeof( struct V_20 ) ) ;
if ( V_11 < 0 ) {
F_25 ( V_38 , L_4 ) ;
} else {
V_2 -> V_28 = V_11 ;
V_2 -> V_49 = 1 ;
}
return 0 ;
V_47:
F_27 ( V_2 ) ;
return V_11 ;
}
static void F_28 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_12 ( V_38 -> V_14 . V_17 ) ;
struct V_1 * V_2 ;
if ( V_40 -> V_41 -> V_42 . V_43
!= V_44 )
return;
V_2 = F_8 ( V_38 ) ;
if ( V_2 -> V_49 )
F_29 ( V_2 -> V_28 ) ;
F_27 ( V_2 ) ;
}
static int F_30 ( struct V_37 * V_38 ,
const struct V_50 * V_51 )
{
int V_11 ;
V_11 = F_31 ( V_38 ) ;
if ( V_11 ) {
F_25 ( V_38 , L_5 ) ;
goto exit;
}
V_11 = F_32 ( V_38 , V_52 ) ;
if ( V_11 ) {
F_25 ( V_38 , L_6 ) ;
goto exit;
}
V_11 = F_22 ( V_38 ) ;
if ( V_11 ) {
F_25 ( V_38 , L_7 ) ;
goto V_53;
}
return 0 ;
V_53:
F_33 ( V_38 ) ;
exit:
return V_11 ;
}
static void F_34 ( struct V_37 * V_38 )
{
F_28 ( V_38 ) ;
F_33 ( V_38 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
T_5 const * V_54 )
{
struct V_55 const * V_56 ;
switch ( V_54 [ 0 ] ) {
case V_57 :
V_56 = (struct V_55 const * ) V_54 ;
switch ( V_56 -> V_24 ) {
case V_25 :
F_1 ( V_2 , V_56 -> V_26 - 1 ) ;
break;
}
break;
}
}
static void F_36 ( struct V_1 const * V_2 ,
T_5 const * V_54 )
{
struct V_20 V_21 ;
struct V_55 const * V_56 ;
if ( V_54 [ 0 ] != V_57 )
return;
V_56 = (struct V_55 const * ) V_54 ;
V_21 . V_24 = V_56 -> V_24 ;
V_21 . V_26 = V_56 -> V_26 ;
V_21 . V_27 = V_56 -> V_27 ;
V_21 . V_19 = V_2 -> V_4 + 1 ;
F_16 ( V_2 -> V_28 ,
( V_29 const * ) & V_21 ) ;
}
static int F_37 ( struct V_37 * V_38 ,
struct V_58 * V_59 , T_5 * V_54 , int V_9 )
{
struct V_39 * V_40 = F_12 ( V_38 -> V_14 . V_17 ) ;
struct V_1 * V_2 = F_8 ( V_38 ) ;
if ( V_40 -> V_41 -> V_42 . V_43
!= V_44 )
return 0 ;
if ( V_2 == NULL )
return 0 ;
F_35 ( V_2 , V_54 ) ;
if ( V_2 -> V_49 )
F_36 ( V_2 , V_54 ) ;
return 0 ;
}
static int T_6 F_38 ( void )
{
int V_11 ;
V_48 = F_39 ( V_60 , L_8 ) ;
if ( F_40 ( V_48 ) )
return F_41 ( V_48 ) ;
V_48 -> V_61 = V_62 ;
V_48 -> V_63 = V_64 ;
V_11 = F_42 ( & V_65 ) ;
if ( V_11 )
F_43 ( V_48 ) ;
return V_11 ;
}
static void T_7 F_44 ( void )
{
F_45 ( & V_65 ) ;
F_43 ( V_48 ) ;
}
