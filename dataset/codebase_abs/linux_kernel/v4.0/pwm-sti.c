static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 , unsigned long V_5 ,
unsigned int * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
unsigned long V_9 ;
unsigned int V_10 ;
V_9 = V_11 / V_4 -> V_12 ;
V_9 *= V_8 -> V_13 + 1 ;
if ( V_5 % V_9 ) {
return - V_14 ;
} else {
V_10 = V_5 / V_9 - 1 ;
if ( V_10 > V_8 -> V_15 )
return - V_14 ;
}
* V_6 = V_10 ;
return 0 ;
}
static int F_4 ( struct V_2 * V_3 , struct V_16 * V_17 ,
int V_18 , int V_19 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_16 * V_20 = V_4 -> V_20 ;
struct V_21 * V_22 = V_4 -> V_22 ;
unsigned int V_6 = 0 , V_23 ;
int V_24 ;
unsigned int V_25 ;
bool V_26 = false ;
V_25 = F_5 ( V_4 -> V_27 ) ;
if ( V_25 )
V_26 = ( V_19 == F_6 ( V_20 ) ) ;
if ( ! V_25 ||
( ( V_25 == 1 ) && ( V_17 -> V_28 == V_20 -> V_28 ) ) ||
( ( V_25 == 1 ) && ( V_17 -> V_28 != V_20 -> V_28 ) && V_26 ) ||
( ( V_25 > 1 ) && V_26 ) ) {
V_24 = F_7 ( V_4 -> V_29 ) ;
if ( V_24 )
return V_24 ;
if ( ! V_26 ) {
V_24 = F_3 ( V_4 , V_19 , & V_6 ) ;
if ( V_24 )
goto V_30;
V_24 =
F_8 ( V_4 -> V_31 ,
V_6 & V_32 ) ;
if ( V_24 )
goto V_30;
V_24 =
F_8 ( V_4 -> V_33 ,
( V_6 & V_34 ) >> 4 ) ;
if ( V_24 )
goto V_30;
}
V_23 = V_8 -> V_13 * V_18 / V_19 ;
V_24 = F_9 ( V_4 -> V_35 , F_10 ( V_17 -> V_28 ) , V_23 ) ;
if ( V_24 )
goto V_30;
V_24 = F_8 ( V_4 -> V_36 , 0 ) ;
F_11 ( V_17 -> V_28 , & V_4 -> V_27 ) ;
V_4 -> V_20 = V_17 ;
F_12 ( V_22 , L_1 ,
V_6 , V_19 , V_18 , V_23 ) ;
} else {
return - V_14 ;
}
V_30:
F_13 ( V_4 -> V_29 ) ;
return V_24 ;
}
static int F_14 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_21 * V_22 = V_4 -> V_22 ;
int V_24 = 0 ;
F_15 ( & V_4 -> V_37 ) ;
if ( ! V_4 -> V_38 ) {
V_24 = F_7 ( V_4 -> V_29 ) ;
if ( V_24 )
goto V_39;
V_24 = F_8 ( V_4 -> V_40 , 1 ) ;
if ( V_24 ) {
F_16 ( V_22 , L_2 ,
V_17 -> V_28 ) ;
goto V_39;
}
}
V_4 -> V_38 ++ ;
V_39:
F_17 ( & V_4 -> V_37 ) ;
return V_24 ;
}
static void F_18 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_15 ( & V_4 -> V_37 ) ;
if ( -- V_4 -> V_38 ) {
F_17 ( & V_4 -> V_37 ) ;
return;
}
F_8 ( V_4 -> V_40 , 0 ) ;
F_13 ( V_4 -> V_29 ) ;
F_17 ( & V_4 -> V_37 ) ;
}
static void F_19 ( struct V_2 * V_3 , struct V_16 * V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_20 ( V_17 -> V_28 , & V_4 -> V_27 ) ;
}
static int F_21 ( struct V_1 * V_4 )
{
struct V_21 * V_22 = V_4 -> V_22 ;
const struct V_41 * V_42 ;
struct V_43 * V_44 = V_22 -> V_45 ;
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_46 ;
F_22 ( V_44 , L_3 , & V_46 ) ;
if ( V_46 )
V_8 -> V_46 = V_46 ;
V_42 = V_8 -> V_42 ;
V_4 -> V_31 = F_23 ( V_22 , V_4 -> V_35 ,
V_42 [ V_47 ] ) ;
if ( F_24 ( V_4 -> V_31 ) )
return F_25 ( V_4 -> V_31 ) ;
V_4 -> V_33 = F_23 ( V_22 , V_4 -> V_35 ,
V_42 [ V_48 ] ) ;
if ( F_24 ( V_4 -> V_33 ) )
return F_25 ( V_4 -> V_33 ) ;
V_4 -> V_40 = F_23 ( V_22 , V_4 -> V_35 ,
V_42 [ V_49 ] ) ;
if ( F_24 ( V_4 -> V_40 ) )
return F_25 ( V_4 -> V_40 ) ;
V_4 -> V_36 = F_23 ( V_22 , V_4 -> V_35 ,
V_42 [ V_50 ] ) ;
if ( F_24 ( V_4 -> V_36 ) )
return F_25 ( V_4 -> V_36 ) ;
return 0 ;
}
static int F_26 ( struct V_51 * V_52 )
{
struct V_21 * V_22 = & V_52 -> V_22 ;
struct V_7 * V_8 ;
struct V_1 * V_4 ;
struct V_53 * V_54 ;
int V_24 ;
V_4 = F_27 ( V_22 , sizeof( * V_4 ) , V_55 ) ;
if ( ! V_4 )
return - V_56 ;
V_8 = F_27 ( V_22 , sizeof( * V_8 ) , V_55 ) ;
if ( ! V_8 )
return - V_56 ;
V_54 = F_28 ( V_52 , V_57 , 0 ) ;
V_4 -> V_58 = F_29 ( V_22 , V_54 ) ;
if ( F_24 ( V_4 -> V_58 ) )
return F_25 ( V_4 -> V_58 ) ;
V_4 -> V_35 = F_30 ( V_22 , V_4 -> V_58 ,
& V_59 ) ;
if ( F_24 ( V_4 -> V_35 ) )
return F_25 ( V_4 -> V_35 ) ;
V_8 -> V_42 = & V_60 [ 0 ] ;
V_8 -> V_15 = 0xff ;
V_8 -> V_13 = 255 ;
V_8 -> V_46 = 1 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_22 = V_22 ;
V_4 -> V_38 = 0 ;
F_31 ( & V_4 -> V_37 ) ;
V_24 = F_21 ( V_4 ) ;
if ( V_24 )
return V_24 ;
V_4 -> V_29 = F_32 ( V_22 -> V_45 , L_4 ) ;
if ( F_24 ( V_4 -> V_29 ) ) {
F_16 ( V_22 , L_5 ) ;
return F_25 ( V_4 -> V_29 ) ;
}
V_4 -> V_12 = F_33 ( V_4 -> V_29 ) ;
if ( ! V_4 -> V_12 ) {
F_16 ( V_22 , L_6 ) ;
return - V_14 ;
}
V_24 = F_34 ( V_4 -> V_29 ) ;
if ( V_24 ) {
F_16 ( V_22 , L_7 ) ;
return V_24 ;
}
V_4 -> V_3 . V_22 = V_22 ;
V_4 -> V_3 . V_61 = & V_62 ;
V_4 -> V_3 . V_63 = - 1 ;
V_4 -> V_3 . V_64 = V_4 -> V_8 -> V_46 ;
V_4 -> V_3 . V_65 = true ;
V_24 = F_35 ( & V_4 -> V_3 ) ;
if ( V_24 < 0 ) {
F_36 ( V_4 -> V_29 ) ;
return V_24 ;
}
F_37 ( V_52 , V_4 ) ;
return 0 ;
}
static int F_38 ( struct V_51 * V_52 )
{
struct V_1 * V_4 = F_39 ( V_52 ) ;
unsigned int V_66 ;
for ( V_66 = 0 ; V_66 < V_4 -> V_8 -> V_46 ; V_66 ++ )
F_40 ( & V_4 -> V_3 . V_67 [ V_66 ] ) ;
F_36 ( V_4 -> V_29 ) ;
return F_41 ( & V_4 -> V_3 ) ;
}
