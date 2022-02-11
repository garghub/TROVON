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
int V_10 ;
struct V_11 V_12 ;
do {
F_5 ( 50 ) ;
V_10 = F_2 ( V_6 , V_13 ,
& V_12 , sizeof( struct V_11 ) ) ;
if ( V_10 )
return V_10 ;
switch ( V_12 . V_14 ) {
case V_15 :
return 0 ;
case V_16 :
continue;
case V_17 :
case V_18 :
return - V_19 ;
default:
F_6 ( V_6 , L_1
L_2 ,
V_12 . V_14 ) ;
return - V_19 ;
}
} while ( 1 );
}
static int F_7 ( struct V_5 * V_6 , T_1 V_7 ,
void const * V_8 , T_1 V_9 )
{
int V_10 ;
V_10 = F_8 ( V_6 , V_7 , V_8 , V_9 ) ;
if ( V_10 )
return V_10 ;
return F_4 ( V_6 ) ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_20 V_8 ;
int V_10 ;
V_10 = F_2 ( V_6 , V_21 ,
& V_8 , sizeof( struct V_20 ) ) ;
return V_10 ? V_10 : V_8 . V_4 ;
}
static int F_10 ( struct V_5 * V_6 , int V_3 )
{
struct V_20 V_8 ;
V_8 . V_7 = V_21 ;
V_8 . V_9 = sizeof( struct V_20 ) ;
V_8 . V_4 = V_3 ;
return F_7 ( V_6 , V_21 , & V_8 ,
sizeof( struct V_20 ) ) ;
}
static T_2 F_11 ( struct V_22 * V_23 ,
struct V_24 * V_25 , char * V_8 )
{
struct V_1 * V_2 =
F_12 ( F_13 ( V_23 -> V_26 -> V_26 ) ) ;
return snprintf ( V_8 , V_27 , L_3 , V_2 -> V_4 ) ;
}
static T_2 F_14 ( struct V_22 * V_23 ,
struct V_24 * V_25 , char const * V_8 , T_3 V_9 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
unsigned long V_28 ;
int V_10 ;
struct V_29 V_30 ;
V_23 = V_23 -> V_26 -> V_26 ;
V_2 = F_12 ( F_13 ( V_23 ) ) ;
V_6 = F_15 ( F_16 ( V_23 ) ) ;
V_10 = F_17 ( V_8 , 10 , & V_28 ) ;
if ( V_10 )
return V_10 ;
if ( V_28 > 4 )
return - V_19 ;
F_18 ( & V_2 -> V_31 ) ;
V_10 = F_10 ( V_6 , V_28 ) ;
if ( V_10 ) {
F_19 ( & V_2 -> V_31 ) ;
return V_10 ;
}
F_1 ( V_2 , V_28 ) ;
V_30 . V_32 = V_33 ;
V_30 . V_34 = V_28 + 1 ;
V_30 . V_35 = 0 ;
V_30 . V_28 = V_28 + 1 ;
F_20 ( V_2 -> V_36 , ( V_37 const * ) & V_30 ) ;
F_19 ( & V_2 -> V_31 ) ;
return V_9 ;
}
static T_2 F_21 ( struct V_38 * V_39 , struct V_40 * V_41 ,
char * V_8 , T_4 V_42 , T_3 V_43 ,
T_3 V_44 , T_1 V_7 )
{
struct V_22 * V_23 =
F_22 ( V_41 , struct V_22 , V_41 ) -> V_26 -> V_26 ;
struct V_1 * V_2 = F_12 ( F_13 ( V_23 ) ) ;
struct V_5 * V_6 = F_15 ( F_16 ( V_23 ) ) ;
int V_10 ;
if ( V_42 >= V_44 )
return 0 ;
if ( V_42 != 0 || V_43 != V_44 )
return - V_19 ;
F_18 ( & V_2 -> V_31 ) ;
V_10 = F_2 ( V_6 , V_7 , V_8 , V_44 ) ;
F_19 ( & V_2 -> V_31 ) ;
return V_10 ? V_10 : V_44 ;
}
static T_2 F_23 ( struct V_38 * V_39 , struct V_40 * V_41 ,
void const * V_8 , T_4 V_42 , T_3 V_43 ,
T_3 V_44 , T_1 V_7 )
{
struct V_22 * V_23 =
F_22 ( V_41 , struct V_22 , V_41 ) -> V_26 -> V_26 ;
struct V_1 * V_2 = F_12 ( F_13 ( V_23 ) ) ;
struct V_5 * V_6 = F_15 ( F_16 ( V_23 ) ) ;
int V_10 ;
if ( V_42 != 0 || V_43 != V_44 )
return - V_19 ;
F_18 ( & V_2 -> V_31 ) ;
V_10 = F_7 ( V_6 , V_7 , ( void * ) V_8 , V_44 ) ;
F_19 ( & V_2 -> V_31 ) ;
return V_10 ? V_10 : V_44 ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
int V_10 ;
F_25 ( & V_2 -> V_31 ) ;
V_10 = F_9 ( V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
F_1 ( V_2 , V_10 ) ;
return 0 ;
}
static int F_26 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_16 ( V_46 -> V_23 . V_26 ) ;
struct V_5 * V_6 = F_15 ( V_48 ) ;
struct V_1 * V_2 ;
int V_10 ;
if ( V_48 -> V_49 -> V_50 . V_51
!= V_52 ) {
F_27 ( V_46 , NULL ) ;
return 0 ;
}
V_2 = F_28 ( sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 ) {
F_6 ( V_46 , L_4 ) ;
return - V_54 ;
}
F_27 ( V_46 , V_2 ) ;
V_10 = F_24 ( V_6 , V_2 ) ;
if ( V_10 ) {
F_6 ( V_46 , L_5 ) ;
goto V_55;
}
V_10 = F_29 ( V_56 , V_46 ,
sizeof( struct V_29 ) ) ;
if ( V_10 < 0 ) {
F_6 ( V_46 , L_6 ) ;
} else {
V_2 -> V_36 = V_10 ;
V_2 -> V_57 = 1 ;
}
return 0 ;
V_55:
F_30 ( V_2 ) ;
return V_10 ;
}
static void F_31 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_16 ( V_46 -> V_23 . V_26 ) ;
struct V_1 * V_2 ;
if ( V_48 -> V_49 -> V_50 . V_51
!= V_52 )
return;
V_2 = F_12 ( V_46 ) ;
if ( V_2 -> V_57 )
F_32 ( V_2 -> V_36 ) ;
F_30 ( V_2 ) ;
}
static int F_33 ( struct V_45 * V_46 ,
const struct V_58 * V_59 )
{
int V_10 ;
V_10 = F_34 ( V_46 ) ;
if ( V_10 ) {
F_6 ( V_46 , L_7 ) ;
goto exit;
}
V_10 = F_35 ( V_46 , V_60 ) ;
if ( V_10 ) {
F_6 ( V_46 , L_8 ) ;
goto exit;
}
V_10 = F_26 ( V_46 ) ;
if ( V_10 ) {
F_6 ( V_46 , L_9 ) ;
goto V_61;
}
return 0 ;
V_61:
F_36 ( V_46 ) ;
exit:
return V_10 ;
}
static void F_37 ( struct V_45 * V_46 )
{
F_31 ( V_46 ) ;
F_36 ( V_46 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
T_5 const * V_62 )
{
struct V_63 const * V_64 ;
switch ( V_62 [ 0 ] ) {
case V_65 :
V_64 = (struct V_63 const * ) V_62 ;
switch ( V_64 -> V_32 ) {
case V_33 :
F_1 ( V_2 , V_64 -> V_34 - 1 ) ;
break;
}
break;
}
}
static void F_39 ( struct V_1 const * V_2 ,
T_5 const * V_62 )
{
struct V_29 V_30 ;
struct V_63 const * V_64 ;
if ( V_62 [ 0 ] != V_65 )
return;
V_64 = (struct V_63 const * ) V_62 ;
V_30 . V_32 = V_64 -> V_32 ;
V_30 . V_34 = V_64 -> V_34 ;
V_30 . V_35 = V_64 -> V_35 ;
V_30 . V_28 = V_2 -> V_4 + 1 ;
F_20 ( V_2 -> V_36 ,
( V_37 const * ) & V_30 ) ;
}
static int F_40 ( struct V_45 * V_46 ,
struct V_66 * V_67 , T_5 * V_62 , int V_9 )
{
struct V_47 * V_48 = F_16 ( V_46 -> V_23 . V_26 ) ;
struct V_1 * V_2 = F_12 ( V_46 ) ;
if ( V_48 -> V_49 -> V_50 . V_51
!= V_52 )
return 0 ;
if ( V_2 == NULL )
return 0 ;
F_38 ( V_2 , V_62 ) ;
if ( V_2 -> V_57 )
F_39 ( V_2 , V_62 ) ;
return 0 ;
}
static int T_6 F_41 ( void )
{
int V_10 ;
V_56 = F_42 ( V_68 , L_10 ) ;
if ( F_43 ( V_56 ) )
return F_44 ( V_56 ) ;
V_56 -> V_69 = V_70 ;
V_56 -> V_71 = V_72 ;
V_10 = F_45 ( & V_73 ) ;
if ( V_10 )
F_46 ( V_56 ) ;
return V_10 ;
}
static void T_7 F_47 ( void )
{
F_48 ( & V_73 ) ;
F_46 ( V_56 ) ;
}
