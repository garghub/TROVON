static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_1 , T_1 V_4 , unsigned int V_5 )
{
F_4 ( V_4 , V_1 -> V_6 + V_5 ) ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_6 ( V_8 ) ;
return F_7 ( V_1 -> V_9 ) ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_6 ( V_8 ) ;
F_9 ( V_1 -> V_9 ) ;
V_1 -> V_10 = false ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 )
{
T_1 V_11 , V_12 ;
void * V_13 ;
int V_14 = 0 ;
if ( V_1 -> V_10 )
return 0 ;
F_3 ( V_1 , F_11 ( 4 ) |
V_15 |
F_12 ( 4 ) ,
V_16 ) ;
V_14 = F_13 ( & V_1 -> V_17 ) ;
if ( V_14 < 0 )
return V_14 ;
V_13 = V_1 -> V_17 . V_18 . V_19 ;
V_12 = * ( T_1 * ) ( V_13 + V_20 ) ;
V_13 = V_1 -> V_17 . V_18 . V_19 +
* ( T_1 * ) ( V_13 + V_21 ) ;
V_11 = * ( T_1 * ) ( V_13 + V_22 ) ;
F_14 ( & V_1 -> V_17 , V_23 , 1 ) ;
F_14 ( & V_1 -> V_17 , V_24 ,
V_11 ) ;
F_14 ( & V_1 -> V_17 , V_25 ,
( V_1 -> V_17 . V_18 . V_26 + V_12 )
>> 8 ) ;
V_14 = F_15 ( & V_1 -> V_17 ) ;
if ( V_14 < 0 ) {
F_16 ( V_1 -> V_8 ,
L_1 ) ;
return V_14 ;
}
V_1 -> V_10 = true ;
return 0 ;
}
static void * F_17 ( struct V_17 * V_17 , T_2 V_27 ,
T_3 * V_28 )
{
struct V_29 * V_30 = V_17 -> V_31 ;
return F_18 ( V_30 , V_27 , V_28 ) ;
}
static void F_19 ( struct V_17 * V_17 , T_2 V_27 ,
T_3 V_28 , void * V_32 )
{
struct V_29 * V_30 = V_17 -> V_31 ;
return F_20 ( V_30 , V_27 , V_32 , V_28 ) ;
}
static int F_21 ( struct V_33 * V_3 )
{
struct V_2 * V_34 = F_22 ( V_3 ) ;
struct V_35 * V_8 = F_6 ( V_3 -> V_36 ) ;
struct V_29 * V_30 = V_8 -> V_37 ;
struct V_1 * V_1 = F_1 ( V_34 ) ;
int V_14 ;
if ( V_30 -> V_38 ) {
V_14 = F_23 ( V_30 -> V_38 , V_1 -> V_8 ) ;
if ( V_14 < 0 ) {
F_16 ( V_1 -> V_8 , L_2 ,
V_14 ) ;
return V_14 ;
}
V_1 -> V_38 = V_30 -> V_38 ;
}
if ( ! V_1 -> V_17 . V_31 ) {
V_1 -> V_17 . V_31 = V_30 ;
V_14 = F_24 ( & V_1 -> V_17 ) ;
if ( V_14 < 0 )
goto V_39;
}
V_1 -> V_40 = F_25 ( V_3 -> V_8 ) ;
if ( ! V_1 -> V_40 ) {
V_14 = - V_41 ;
goto V_39;
}
V_3 -> V_42 [ 0 ] = F_26 ( V_3 -> V_8 , 0 ) ;
if ( ! V_3 -> V_42 [ 0 ] ) {
V_14 = - V_41 ;
goto V_43;
}
V_14 = F_27 ( V_30 , V_34 ) ;
if ( V_14 < 0 )
goto V_44;
return 0 ;
V_44:
F_28 ( V_3 -> V_42 [ 0 ] ) ;
V_43:
F_29 ( V_1 -> V_40 ) ;
V_39:
if ( V_30 -> V_38 )
F_30 ( V_30 -> V_38 , V_1 -> V_8 ) ;
return V_14 ;
}
static int F_31 ( struct V_33 * V_3 )
{
struct V_2 * V_34 = F_22 ( V_3 ) ;
struct V_35 * V_8 = F_6 ( V_3 -> V_36 ) ;
struct V_29 * V_30 = V_8 -> V_37 ;
struct V_1 * V_1 = F_1 ( V_34 ) ;
int V_14 ;
V_14 = F_32 ( V_30 , V_34 ) ;
if ( V_14 < 0 )
return V_14 ;
F_28 ( V_3 -> V_42 [ 0 ] ) ;
F_29 ( V_1 -> V_40 ) ;
if ( V_1 -> V_38 ) {
F_30 ( V_1 -> V_38 , V_1 -> V_8 ) ;
V_1 -> V_38 = NULL ;
}
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_45 * V_46 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_14 ;
V_14 = F_34 ( V_1 -> V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_10 ( V_1 ) ;
if ( V_14 < 0 ) {
F_35 ( V_1 -> V_8 ) ;
return V_14 ;
}
V_46 -> V_40 = F_36 ( V_1 -> V_40 ) ;
if ( ! V_46 -> V_40 ) {
F_35 ( V_1 -> V_8 ) ;
return - V_41 ;
}
return 0 ;
}
static void F_37 ( struct V_45 * V_46 )
{
struct V_1 * V_1 = F_1 ( V_46 -> V_3 ) ;
F_29 ( V_46 -> V_40 ) ;
F_35 ( V_1 -> V_8 ) ;
}
static int F_38 ( struct V_47 * V_48 )
{
struct V_49 * V_49 = NULL ;
struct V_7 * V_8 = & V_48 -> V_8 ;
struct V_50 * * V_42 ;
struct V_51 * V_6 ;
const struct V_52 * V_53 ;
struct V_1 * V_1 ;
int V_14 ;
V_53 = F_39 ( V_54 , V_8 ) ;
V_49 = (struct V_49 * ) V_53 -> V_31 ;
V_1 = F_40 ( V_8 , sizeof( * V_1 ) , V_55 ) ;
if ( ! V_1 )
return - V_41 ;
V_42 = F_40 ( V_8 , sizeof( * V_42 ) , V_55 ) ;
if ( ! V_42 )
return - V_41 ;
V_6 = F_41 ( V_48 , V_56 , 0 ) ;
if ( ! V_6 ) {
F_16 ( & V_48 -> V_8 , L_3 ) ;
return - V_57 ;
}
V_1 -> V_6 = F_42 ( V_8 , V_6 ) ;
if ( F_43 ( V_1 -> V_6 ) )
return F_44 ( V_1 -> V_6 ) ;
V_1 -> V_9 = F_45 ( V_8 , NULL ) ;
if ( F_43 ( V_1 -> V_9 ) ) {
F_16 ( & V_48 -> V_8 , L_4 ) ;
return F_44 ( V_1 -> V_9 ) ;
}
V_1 -> V_17 . V_8 = V_8 ;
V_1 -> V_17 . V_6 = V_1 -> V_6 ;
V_1 -> V_17 . V_58 = & V_59 ;
V_14 = F_46 ( & V_1 -> V_17 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_47 ( & V_1 -> V_17 , V_49 -> V_18 ) ;
if ( V_14 < 0 )
goto V_60;
F_48 ( V_48 , V_1 ) ;
F_49 ( & V_1 -> V_3 . V_61 . V_62 ) ;
V_1 -> V_3 . V_61 . V_58 = & V_63 ;
V_1 -> V_3 . V_61 . V_8 = V_8 ;
V_1 -> V_3 . V_61 . V_64 = V_65 ;
V_1 -> V_3 . V_61 . V_42 = V_42 ;
V_1 -> V_3 . V_61 . V_66 = 1 ;
V_1 -> V_8 = V_8 ;
V_1 -> V_67 = V_49 ;
F_49 ( & V_1 -> V_3 . V_62 ) ;
V_1 -> V_3 . V_58 = & V_68 ;
V_14 = F_50 ( & V_1 -> V_3 . V_61 ) ;
if ( V_14 < 0 ) {
F_16 ( V_8 , L_5 , V_14 ) ;
F_48 ( V_48 , NULL ) ;
goto V_60;
}
F_51 ( & V_48 -> V_8 ) ;
if ( ! F_52 ( & V_48 -> V_8 ) ) {
V_14 = F_5 ( & V_48 -> V_8 ) ;
if ( V_14 < 0 )
goto V_69;
}
return 0 ;
V_69:
F_53 ( & V_1 -> V_3 . V_61 ) ;
V_60:
F_54 ( & V_1 -> V_17 ) ;
return V_14 ;
}
static int F_55 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = F_56 ( V_48 ) ;
int V_14 ;
V_14 = F_53 ( & V_1 -> V_3 . V_61 ) ;
if ( V_14 < 0 ) {
F_16 ( & V_48 -> V_8 , L_6 ,
V_14 ) ;
return V_14 ;
}
if ( F_52 ( & V_48 -> V_8 ) )
F_57 ( & V_48 -> V_8 ) ;
else
F_8 ( & V_48 -> V_8 ) ;
F_54 ( & V_1 -> V_17 ) ;
return 0 ;
}
