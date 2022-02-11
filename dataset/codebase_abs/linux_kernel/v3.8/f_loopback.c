static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int T_1
F_3 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_10 ;
int V_11 ;
V_10 = F_4 ( V_6 , V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_12 . V_13 = V_10 ;
V_9 -> V_14 = F_5 ( V_8 -> V_15 , & V_16 ) ;
if ( ! V_9 -> V_14 ) {
V_17:
ERROR ( V_8 , L_1 ,
V_3 -> V_18 , V_8 -> V_15 -> V_18 ) ;
return - V_19 ;
}
V_9 -> V_14 -> V_20 = V_8 ;
V_9 -> V_21 = F_5 ( V_8 -> V_15 , & V_22 ) ;
if ( ! V_9 -> V_21 )
goto V_17;
V_9 -> V_21 -> V_20 = V_8 ;
V_23 . V_24 =
V_16 . V_24 ;
V_25 . V_24 = V_22 . V_24 ;
V_26 . V_24 =
V_16 . V_24 ;
V_27 . V_24 = V_22 . V_24 ;
V_11 = F_6 ( V_3 , V_28 , V_29 ,
V_30 ) ;
if ( V_11 )
return V_11 ;
F_7 ( V_8 , L_2 ,
( F_8 ( V_6 -> V_8 -> V_15 ) ? L_3 :
( F_9 ( V_6 -> V_8 -> V_15 ) ? L_4 : L_5 ) ) ,
V_3 -> V_18 , V_9 -> V_14 -> V_18 , V_9 -> V_21 -> V_18 ) ;
return 0 ;
}
static void
F_10 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
F_11 ( V_3 ) ;
F_12 ( F_1 ( V_3 ) ) ;
}
static void F_13 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_1 * V_9 = V_32 -> V_20 ;
struct V_7 * V_8 = V_9 -> V_4 . V_35 -> V_8 ;
int V_36 = V_34 -> V_36 ;
switch ( V_36 ) {
case 0 :
if ( V_32 == V_9 -> V_21 ) {
V_34 -> V_37 = ( V_34 -> V_38 < V_34 -> V_39 ) ;
V_34 -> V_39 = V_34 -> V_38 ;
V_36 = F_14 ( V_9 -> V_14 , V_34 , V_40 ) ;
if ( V_36 == 0 )
return;
ERROR ( V_8 , L_6 ,
V_32 -> V_18 , V_9 -> V_14 -> V_18 ,
V_36 ) ;
}
V_34 -> V_39 = V_41 ;
V_36 = F_14 ( V_9 -> V_21 , V_34 , V_40 ) ;
if ( V_36 == 0 )
return;
default:
ERROR ( V_8 , L_7 , V_32 -> V_18 ,
V_36 , V_34 -> V_38 , V_34 -> V_39 ) ;
case - V_42 :
case - V_43 :
case - V_44 :
F_15 ( V_32 , V_34 ) ;
return;
}
}
static void F_16 ( struct V_1 * V_9 )
{
struct V_7 * V_8 ;
V_8 = V_9 -> V_4 . V_35 -> V_8 ;
F_17 ( V_8 , V_9 -> V_14 , V_9 -> V_21 , NULL , NULL ) ;
F_18 ( V_8 , L_8 , V_9 -> V_4 . V_18 ) ;
}
static int
F_19 ( struct V_7 * V_8 , struct V_1 * V_9 )
{
int V_45 = 0 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
unsigned V_46 ;
V_32 = V_9 -> V_14 ;
V_45 = F_20 ( V_8 -> V_15 , & ( V_9 -> V_4 ) , V_32 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_21 ( V_32 ) ;
if ( V_45 < 0 )
return V_45 ;
V_32 -> V_20 = V_9 ;
V_32 = V_9 -> V_21 ;
V_45 = F_20 ( V_8 -> V_15 , & ( V_9 -> V_4 ) , V_32 ) ;
if ( V_45 )
goto V_47;
V_45 = F_21 ( V_32 ) ;
if ( V_45 < 0 ) {
V_47:
V_32 = V_9 -> V_14 ;
F_22 ( V_32 ) ;
V_32 -> V_20 = NULL ;
return V_45 ;
}
V_32 -> V_20 = V_9 ;
for ( V_46 = 0 ; V_46 < V_48 && V_45 == 0 ; V_46 ++ ) {
V_34 = F_23 ( V_32 , 0 ) ;
if ( V_34 ) {
V_34 -> V_49 = F_13 ;
V_45 = F_14 ( V_32 , V_34 , V_40 ) ;
if ( V_45 )
ERROR ( V_8 , L_9 ,
V_32 -> V_18 , V_45 ) ;
} else {
F_22 ( V_32 ) ;
V_32 -> V_20 = NULL ;
V_45 = - V_50 ;
goto V_47;
}
}
F_7 ( V_8 , L_10 , V_9 -> V_4 . V_18 ) ;
return V_45 ;
}
static int F_24 ( struct V_2 * V_3 ,
unsigned V_51 , unsigned V_52 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_35 -> V_8 ;
if ( V_9 -> V_14 -> V_20 )
F_16 ( V_9 ) ;
return F_19 ( V_8 , V_9 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_16 ( V_9 ) ;
}
static int T_1 F_26 ( struct V_5 * V_6 )
{
struct V_1 * V_9 ;
int V_36 ;
V_9 = F_27 ( sizeof *V_9 , V_53 ) ;
if ( ! V_9 )
return - V_50 ;
V_9 -> V_4 . V_18 = L_11 ;
V_9 -> V_4 . V_54 = F_3 ;
V_9 -> V_4 . V_55 = F_10 ;
V_9 -> V_4 . V_56 = F_24 ;
V_9 -> V_4 . V_57 = F_25 ;
V_36 = F_28 ( V_6 , & V_9 -> V_4 ) ;
if ( V_36 )
F_12 ( V_9 ) ;
return V_36 ;
}
int T_1 F_29 ( struct V_7 * V_8 , bool V_58 )
{
int V_10 ;
V_10 = F_30 ( V_8 ) ;
if ( V_10 < 0 )
return V_10 ;
V_59 [ 0 ] . V_10 = V_10 ;
V_12 . V_60 = V_10 ;
V_61 . V_62 = V_10 ;
if ( V_58 )
V_61 . V_63 |= V_64 ;
if ( F_31 ( V_8 -> V_15 ) ) {
V_61 . V_65 = V_66 ;
V_61 . V_63 |= V_64 ;
}
return F_32 ( V_8 , & V_61 , F_26 ) ;
}
