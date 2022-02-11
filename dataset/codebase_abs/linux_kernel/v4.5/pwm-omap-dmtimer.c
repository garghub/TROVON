static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( unsigned long V_4 , int V_5 )
{
T_1 V_6 = ( T_1 ) V_4 * V_5 ;
F_4 ( V_6 , V_7 ) ;
return V_8 - V_6 ;
}
static void F_5 ( struct V_1 * V_9 )
{
V_9 -> V_10 -> V_11 ( V_9 -> V_12 ) ;
V_9 -> V_10 -> V_13 ( V_9 -> V_12 , V_8 ) ;
V_9 -> V_10 -> V_14 ( V_9 -> V_12 ) ;
V_9 -> V_10 -> V_15 ( V_9 -> V_12 ) ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_7 ( & V_9 -> V_18 ) ;
F_5 ( V_9 ) ;
F_8 ( & V_9 -> V_18 ) ;
return 0 ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_7 ( & V_9 -> V_18 ) ;
V_9 -> V_10 -> V_19 ( V_9 -> V_12 ) ;
F_8 ( & V_9 -> V_18 ) ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_16 * V_17 ,
int V_20 , int V_21 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_22 , V_23 ;
struct V_24 * V_25 ;
unsigned long V_4 ;
bool V_26 ;
F_11 ( V_3 -> V_27 , L_1 , V_20 , V_21 ) ;
F_7 ( & V_9 -> V_18 ) ;
if ( V_20 == F_12 ( V_17 ) &&
V_21 == F_13 ( V_17 ) ) {
F_8 ( & V_9 -> V_18 ) ;
return 0 ;
}
V_25 = V_9 -> V_10 -> V_28 ( V_9 -> V_12 ) ;
if ( ! V_25 ) {
F_14 ( V_3 -> V_27 , L_2 ) ;
F_8 ( & V_9 -> V_18 ) ;
return - V_29 ;
}
V_4 = F_15 ( V_25 ) ;
if ( ! V_4 ) {
F_14 ( V_3 -> V_27 , L_3 ) ;
F_8 ( & V_9 -> V_18 ) ;
return - V_29 ;
}
F_11 ( V_3 -> V_27 , L_4 , V_4 ) ;
V_22 = F_3 ( V_4 , V_21 ) ;
V_23 = F_3 ( V_4 ,
V_21 - V_20 ) ;
V_26 = F_16 ( & V_9 -> V_30 -> V_27 ) ;
if ( V_26 )
V_9 -> V_10 -> V_19 ( V_9 -> V_12 ) ;
V_9 -> V_10 -> V_31 ( V_9 -> V_12 , true , V_22 ) ;
V_9 -> V_10 -> V_32 ( V_9 -> V_12 , true , V_23 ) ;
F_11 ( V_3 -> V_27 , L_5 ,
V_22 , V_22 , V_23 , V_23 ) ;
V_9 -> V_10 -> V_33 ( V_9 -> V_12 ,
V_17 -> V_34 == V_35 ,
true ,
V_36 ) ;
if ( V_26 )
F_5 ( V_9 ) ;
F_8 ( & V_9 -> V_18 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_16 * V_17 ,
enum V_37 V_34 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_7 ( & V_9 -> V_18 ) ;
V_9 -> V_10 -> V_33 ( V_9 -> V_12 ,
V_34 == V_35 ,
true ,
V_36 ) ;
F_8 ( & V_9 -> V_18 ) ;
return 0 ;
}
static int F_18 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = V_39 -> V_27 . V_42 ;
struct V_40 * V_43 ;
struct V_1 * V_9 ;
struct V_44 * V_10 ;
T_2 * V_12 ;
T_3 V_45 ;
int V_46 ;
V_10 = F_19 ( & V_39 -> V_27 ) ;
if ( ! V_10 ) {
F_14 ( & V_39 -> V_27 , L_6 ) ;
return - V_29 ;
}
if ( ! V_10 -> V_47 ||
! V_10 -> free ||
! V_10 -> V_11 ||
! V_10 -> V_14 ||
! V_10 -> V_28 ||
! V_10 -> V_15 ||
! V_10 -> V_19 ||
! V_10 -> V_31 ||
! V_10 -> V_32 ||
! V_10 -> V_33 ||
! V_10 -> V_48 ||
! V_10 -> V_13 ) {
F_14 ( & V_39 -> V_27 , L_7 ) ;
return - V_29 ;
}
V_43 = F_20 ( V_41 , L_8 , 0 ) ;
if ( ! V_43 )
return - V_49 ;
if ( ! F_21 ( V_43 , L_9 , NULL ) ) {
F_14 ( & V_39 -> V_27 , L_10 ) ;
return - V_49 ;
}
V_12 = V_10 -> V_47 ( V_43 ) ;
if ( ! V_12 )
return - V_50 ;
V_9 = F_22 ( & V_39 -> V_27 , sizeof( * V_9 ) , V_51 ) ;
if ( ! V_9 ) {
V_10 -> free ( V_12 ) ;
return - V_52 ;
}
V_9 -> V_10 = V_10 ;
V_9 -> V_12 = V_12 ;
V_9 -> V_30 = F_23 ( V_43 ) ;
if ( ! V_9 -> V_30 ) {
F_14 ( & V_39 -> V_27 , L_11 ) ;
V_9 -> V_10 -> free ( V_12 ) ;
return - V_29 ;
}
if ( F_16 ( & V_9 -> V_30 -> V_27 ) )
V_9 -> V_10 -> V_19 ( V_9 -> V_12 ) ;
if ( ! F_24 ( V_39 -> V_27 . V_42 , L_12 ,
& V_45 ) )
V_9 -> V_10 -> V_48 ( V_9 -> V_12 , V_45 ) ;
V_9 -> V_3 . V_27 = & V_39 -> V_27 ;
V_9 -> V_3 . V_53 = & V_54 ;
V_9 -> V_3 . V_55 = - 1 ;
V_9 -> V_3 . V_56 = 1 ;
V_9 -> V_3 . V_57 = V_58 ;
V_9 -> V_3 . V_59 = 3 ;
F_25 ( & V_9 -> V_18 ) ;
V_46 = F_26 ( & V_9 -> V_3 ) ;
if ( V_46 < 0 ) {
F_14 ( & V_39 -> V_27 , L_13 ) ;
V_9 -> V_10 -> free ( V_9 -> V_12 ) ;
return V_46 ;
}
F_27 ( V_39 , V_9 ) ;
return 0 ;
}
static int F_28 ( struct V_38 * V_39 )
{
struct V_1 * V_9 = F_29 ( V_39 ) ;
if ( F_16 ( & V_9 -> V_30 -> V_27 ) )
V_9 -> V_10 -> V_19 ( V_9 -> V_12 ) ;
V_9 -> V_10 -> free ( V_9 -> V_12 ) ;
F_30 ( & V_9 -> V_18 ) ;
return F_31 ( & V_9 -> V_3 ) ;
}
