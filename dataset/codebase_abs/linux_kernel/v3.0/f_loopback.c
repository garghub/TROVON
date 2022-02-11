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
V_10 = F_4 ( V_6 , V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_11 . V_12 = V_10 ;
V_9 -> V_13 = F_5 ( V_8 -> V_14 , & V_15 ) ;
if ( ! V_9 -> V_13 ) {
V_16:
ERROR ( V_8 , L_1 ,
V_3 -> V_17 , V_8 -> V_14 -> V_17 ) ;
return - V_18 ;
}
V_9 -> V_13 -> V_19 = V_8 ;
V_9 -> V_20 = F_5 ( V_8 -> V_14 , & V_21 ) ;
if ( ! V_9 -> V_20 )
goto V_16;
V_9 -> V_20 -> V_19 = V_8 ;
if ( F_6 ( V_6 -> V_8 -> V_14 ) ) {
V_22 . V_23 =
V_15 . V_23 ;
V_24 . V_23 =
V_21 . V_23 ;
V_3 -> V_25 = V_26 ;
}
F_7 ( V_8 , L_2 ,
F_6 ( V_6 -> V_8 -> V_14 ) ? L_3 : L_4 ,
V_3 -> V_17 , V_9 -> V_13 -> V_17 , V_9 -> V_20 -> V_17 ) ;
return 0 ;
}
static void
F_8 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
F_9 ( F_1 ( V_3 ) ) ;
}
static void F_10 ( struct V_27 * V_28 , struct V_29 * V_30 )
{
struct V_1 * V_9 = V_28 -> V_19 ;
struct V_7 * V_8 = V_9 -> V_4 . V_31 -> V_8 ;
int V_32 = V_30 -> V_32 ;
switch ( V_32 ) {
case 0 :
if ( V_28 == V_9 -> V_20 ) {
V_30 -> V_33 = ( V_30 -> V_34 < V_30 -> V_35 ) ;
V_30 -> V_35 = V_30 -> V_34 ;
V_32 = F_11 ( V_9 -> V_13 , V_30 , V_36 ) ;
if ( V_32 == 0 )
return;
ERROR ( V_8 , L_5 ,
V_28 -> V_17 , V_9 -> V_13 -> V_17 ,
V_32 ) ;
}
V_30 -> V_35 = V_37 ;
V_32 = F_11 ( V_9 -> V_20 , V_30 , V_36 ) ;
if ( V_32 == 0 )
return;
default:
ERROR ( V_8 , L_6 , V_28 -> V_17 ,
V_32 , V_30 -> V_34 , V_30 -> V_35 ) ;
case - V_38 :
case - V_39 :
case - V_40 :
F_12 ( V_28 , V_30 ) ;
return;
}
}
static void F_13 ( struct V_1 * V_9 )
{
struct V_7 * V_8 ;
V_8 = V_9 -> V_4 . V_31 -> V_8 ;
F_14 ( V_8 , V_9 -> V_13 , V_9 -> V_20 ) ;
F_15 ( V_8 , L_7 , V_9 -> V_4 . V_17 ) ;
}
static int
F_16 ( struct V_7 * V_8 , struct V_1 * V_9 )
{
int V_41 = 0 ;
const struct V_42 * V_43 , * V_44 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
unsigned V_45 ;
V_43 = F_17 ( V_8 -> V_14 ,
& V_22 , & V_15 ) ;
V_44 = F_17 ( V_8 -> V_14 ,
& V_24 , & V_21 ) ;
V_28 = V_9 -> V_13 ;
V_41 = F_18 ( V_28 , V_43 ) ;
if ( V_41 < 0 )
return V_41 ;
V_28 -> V_19 = V_9 ;
V_28 = V_9 -> V_20 ;
V_41 = F_18 ( V_28 , V_44 ) ;
if ( V_41 < 0 ) {
V_46:
V_28 = V_9 -> V_13 ;
F_19 ( V_28 ) ;
V_28 -> V_19 = NULL ;
return V_41 ;
}
V_28 -> V_19 = V_9 ;
for ( V_45 = 0 ; V_45 < V_47 && V_41 == 0 ; V_45 ++ ) {
V_30 = F_20 ( V_28 ) ;
if ( V_30 ) {
V_30 -> V_48 = F_10 ;
V_41 = F_11 ( V_28 , V_30 , V_36 ) ;
if ( V_41 )
ERROR ( V_8 , L_8 ,
V_28 -> V_17 , V_41 ) ;
} else {
F_19 ( V_28 ) ;
V_28 -> V_19 = NULL ;
V_41 = - V_49 ;
goto V_46;
}
}
F_7 ( V_8 , L_9 , V_9 -> V_4 . V_17 ) ;
return V_41 ;
}
static int F_21 ( struct V_2 * V_3 ,
unsigned V_50 , unsigned V_51 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_31 -> V_8 ;
if ( V_9 -> V_13 -> V_19 )
F_13 ( V_9 ) ;
return F_16 ( V_8 , V_9 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_13 ( V_9 ) ;
}
static int T_1 F_23 ( struct V_5 * V_6 )
{
struct V_1 * V_9 ;
int V_32 ;
V_9 = F_24 ( sizeof *V_9 , V_52 ) ;
if ( ! V_9 )
return - V_49 ;
V_9 -> V_4 . V_17 = L_10 ;
V_9 -> V_4 . V_53 = V_54 ;
V_9 -> V_4 . V_55 = F_3 ;
V_9 -> V_4 . V_56 = F_8 ;
V_9 -> V_4 . V_57 = F_21 ;
V_9 -> V_4 . V_58 = F_22 ;
V_32 = F_25 ( V_6 , & V_9 -> V_4 ) ;
if ( V_32 )
F_9 ( V_9 ) ;
return V_32 ;
}
int T_1 F_26 ( struct V_7 * V_8 , bool V_59 )
{
int V_10 ;
V_10 = F_27 ( V_8 ) ;
if ( V_10 < 0 )
return V_10 ;
V_60 [ 0 ] . V_10 = V_10 ;
V_11 . V_61 = V_10 ;
V_62 . V_63 = V_10 ;
if ( V_59 )
V_64 . V_65 |= V_66 ;
if ( F_28 ( V_8 -> V_14 ) ) {
V_62 . V_53 = V_67 ;
V_62 . V_65 |= V_66 ;
}
return F_29 ( V_8 , & V_62 , F_23 ) ;
}
