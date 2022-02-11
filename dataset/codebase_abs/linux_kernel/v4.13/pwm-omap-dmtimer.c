static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static T_1 F_3 ( unsigned long V_4 , int V_5 )
{
return F_4 ( ( V_6 ) V_4 * V_5 , V_7 ) ;
}
static void F_5 ( struct V_1 * V_8 )
{
V_8 -> V_9 -> V_10 ( V_8 -> V_11 ) ;
V_8 -> V_9 -> V_12 ( V_8 -> V_11 , V_13 ) ;
V_8 -> V_9 -> V_14 ( V_8 -> V_11 ) ;
V_8 -> V_9 -> V_15 ( V_8 -> V_11 ) ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_7 ( & V_8 -> V_18 ) ;
F_5 ( V_8 ) ;
F_8 ( & V_8 -> V_18 ) ;
return 0 ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_7 ( & V_8 -> V_18 ) ;
V_8 -> V_9 -> V_19 ( V_8 -> V_11 ) ;
F_8 ( & V_8 -> V_18 ) ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_16 * V_17 ,
int V_20 , int V_21 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
T_1 V_22 , V_23 ;
T_1 V_24 , V_25 ;
struct V_26 * V_27 ;
unsigned long V_4 ;
bool V_28 ;
F_11 ( V_3 -> V_29 , L_1 ,
V_20 , V_21 ) ;
F_7 ( & V_8 -> V_18 ) ;
if ( V_20 == F_12 ( V_17 ) &&
V_21 == F_13 ( V_17 ) ) {
F_8 ( & V_8 -> V_18 ) ;
return 0 ;
}
V_27 = V_8 -> V_9 -> V_30 ( V_8 -> V_11 ) ;
if ( ! V_27 ) {
F_14 ( V_3 -> V_29 , L_2 ) ;
goto V_31;
}
V_4 = F_15 ( V_27 ) ;
if ( ! V_4 ) {
F_14 ( V_3 -> V_29 , L_3 ) ;
goto V_31;
}
F_11 ( V_3 -> V_29 , L_4 , V_4 ) ;
V_22 = F_3 ( V_4 , V_21 ) ;
V_23 = F_3 ( V_4 , V_20 ) ;
if ( V_22 < 2 ) {
F_16 ( V_3 -> V_29 ,
L_5 ,
V_21 , V_4 ) ;
goto V_31;
}
if ( V_23 < 1 ) {
F_11 ( V_3 -> V_29 ,
L_6 ,
V_20 , V_4 ) ;
F_11 ( V_3 -> V_29 , L_7 ) ;
V_23 = 1 ;
} else if ( V_23 >= V_22 ) {
F_11 ( V_3 -> V_29 ,
L_8 ,
V_20 , V_21 , V_4 ) ;
F_11 ( V_3 -> V_29 , L_9 ) ;
V_23 = V_22 - 1 ;
}
F_11 ( V_3 -> V_29 , L_10 ,
F_4 ( ( V_6 ) V_7 * V_23 ,
V_4 ) ,
F_4 ( ( V_6 ) V_7 * V_22 ,
V_4 ) ) ;
V_24 = ( V_32 - V_22 ) + 1 ;
V_25 = V_24 + V_23 - 1 ;
V_28 = F_17 ( & V_8 -> V_33 -> V_29 ) ;
if ( V_28 )
V_8 -> V_9 -> V_19 ( V_8 -> V_11 ) ;
V_8 -> V_9 -> V_34 ( V_8 -> V_11 , true , V_24 ) ;
V_8 -> V_9 -> V_35 ( V_8 -> V_11 , true , V_25 ) ;
F_11 ( V_3 -> V_29 , L_11 ,
V_24 , V_24 , V_25 , V_25 ) ;
V_8 -> V_9 -> V_36 ( V_8 -> V_11 ,
F_18 ( V_17 ) == V_37 ,
true ,
V_38 ) ;
if ( V_28 )
F_5 ( V_8 ) ;
F_8 ( & V_8 -> V_18 ) ;
return 0 ;
V_31:
F_8 ( & V_8 -> V_18 ) ;
return - V_39 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_16 * V_17 ,
enum V_40 V_41 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_7 ( & V_8 -> V_18 ) ;
V_8 -> V_9 -> V_36 ( V_8 -> V_11 ,
V_41 == V_37 ,
true ,
V_38 ) ;
F_8 ( & V_8 -> V_18 ) ;
return 0 ;
}
static int F_20 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_29 . V_46 ;
struct V_44 * V_47 ;
struct V_1 * V_8 ;
struct V_48 * V_9 ;
T_2 * V_11 ;
T_1 V_49 ;
int V_50 ;
V_9 = F_21 ( & V_43 -> V_29 ) ;
if ( ! V_9 ) {
F_14 ( & V_43 -> V_29 , L_12 ) ;
return - V_39 ;
}
if ( ! V_9 -> V_51 ||
! V_9 -> free ||
! V_9 -> V_10 ||
! V_9 -> V_14 ||
! V_9 -> V_30 ||
! V_9 -> V_15 ||
! V_9 -> V_19 ||
! V_9 -> V_34 ||
! V_9 -> V_35 ||
! V_9 -> V_36 ||
! V_9 -> V_52 ||
! V_9 -> V_12 ) {
F_14 ( & V_43 -> V_29 , L_13 ) ;
return - V_39 ;
}
V_47 = F_22 ( V_45 , L_14 , 0 ) ;
if ( ! V_47 )
return - V_53 ;
if ( ! F_23 ( V_47 , L_15 , NULL ) ) {
F_14 ( & V_43 -> V_29 , L_16 ) ;
return - V_53 ;
}
V_11 = V_9 -> V_51 ( V_47 ) ;
if ( ! V_11 )
return - V_54 ;
V_8 = F_24 ( & V_43 -> V_29 , sizeof( * V_8 ) , V_55 ) ;
if ( ! V_8 ) {
V_9 -> free ( V_11 ) ;
return - V_56 ;
}
V_8 -> V_9 = V_9 ;
V_8 -> V_11 = V_11 ;
V_8 -> V_33 = F_25 ( V_47 ) ;
if ( ! V_8 -> V_33 ) {
F_14 ( & V_43 -> V_29 , L_17 ) ;
V_8 -> V_9 -> free ( V_11 ) ;
return - V_39 ;
}
if ( F_17 ( & V_8 -> V_33 -> V_29 ) )
V_8 -> V_9 -> V_19 ( V_8 -> V_11 ) ;
if ( ! F_26 ( V_43 -> V_29 . V_46 , L_18 , & V_49 ) )
V_8 -> V_9 -> V_52 ( V_8 -> V_11 , V_49 ) ;
if ( ! F_26 ( V_43 -> V_29 . V_46 , L_19 , & V_49 ) )
V_8 -> V_9 -> V_57 ( V_8 -> V_11 , V_49 ) ;
V_8 -> V_3 . V_29 = & V_43 -> V_29 ;
V_8 -> V_3 . V_58 = & V_59 ;
V_8 -> V_3 . V_60 = - 1 ;
V_8 -> V_3 . V_61 = 1 ;
V_8 -> V_3 . V_62 = V_63 ;
V_8 -> V_3 . V_64 = 3 ;
F_27 ( & V_8 -> V_18 ) ;
V_50 = F_28 ( & V_8 -> V_3 ) ;
if ( V_50 < 0 ) {
F_14 ( & V_43 -> V_29 , L_20 ) ;
V_8 -> V_9 -> free ( V_8 -> V_11 ) ;
return V_50 ;
}
F_29 ( V_43 , V_8 ) ;
return 0 ;
}
static int F_30 ( struct V_42 * V_43 )
{
struct V_1 * V_8 = F_31 ( V_43 ) ;
if ( F_17 ( & V_8 -> V_33 -> V_29 ) )
V_8 -> V_9 -> V_19 ( V_8 -> V_11 ) ;
V_8 -> V_9 -> free ( V_8 -> V_11 ) ;
F_32 ( & V_8 -> V_18 ) ;
return F_33 ( & V_8 -> V_3 ) ;
}
