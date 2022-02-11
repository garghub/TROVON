static int
F_1 ( struct V_1 * V_2 , bool V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 -> V_13 ;
unsigned long V_14 ;
int V_15 = 0 ;
int V_16 ;
F_2 ( & V_2 -> V_17 , V_14 ) ;
if ( V_4 < 0 )
V_4 = V_2 -> V_18 ;
V_4 = F_3 ( V_19 , V_4 , V_2 -> V_20 . V_21 ) ;
V_4 = F_4 ( V_19 , V_4 , V_2 -> V_20 . V_22 ) ;
if ( V_2 -> V_18 != V_4 ) {
F_5 ( V_9 , L_1 , V_4 ) ;
V_2 -> V_18 = V_4 ;
}
V_16 = V_2 -> V_23 ( V_6 ) ;
if ( V_16 == V_4 ) {
F_6 ( & V_2 -> V_17 , V_14 ) ;
return 0 ;
}
if ( ! V_3 && V_16 >= 0 ) {
if ( V_16 < V_4 )
V_16 = F_7 ( V_16 + 3 , V_4 ) ;
else if ( V_16 > V_4 )
V_16 = F_8 ( V_16 - 3 , V_4 ) ;
} else {
V_16 = V_4 ;
}
F_5 ( V_9 , L_2 , V_16 ) ;
V_15 = V_2 -> V_24 ( V_6 , V_16 ) ;
if ( V_15 ) {
F_6 ( & V_2 -> V_17 , V_14 ) ;
return V_15 ;
}
F_6 ( & V_2 -> V_17 , V_14 ) ;
if ( F_9 ( & V_2 -> V_25 . V_26 ) && V_4 != V_16 ) {
T_1 V_27 = V_2 -> V_20 . V_27 ;
T_1 V_28 = V_2 -> V_20 . V_28 ;
T_2 V_29 ;
if ( V_16 > V_4 )
V_29 = V_28 ;
else if ( V_16 == V_4 )
V_29 = F_7 ( V_27 , V_28 ) ;
else
V_29 = V_27 ;
F_10 ( V_11 , V_29 * 1000 * 1000 , & V_2 -> V_25 ) ;
}
return V_15 ;
}
static void
F_11 ( struct V_30 * V_25 )
{
struct V_1 * V_2 = F_12 ( V_25 , struct V_1 , V_25 ) ;
F_1 ( V_2 , false , - 1 ) ;
}
int
F_13 ( struct V_5 * V_6 )
{
return V_6 -> V_2 -> V_23 ( V_6 ) ;
}
int
F_14 ( struct V_5 * V_6 , bool V_3 , int V_18 )
{
return F_1 ( V_6 -> V_2 , V_3 , V_18 ) ;
}
int
F_15 ( struct V_5 * V_6 )
{
struct V_31 * V_12 = V_6 -> V_9 . V_12 ;
struct V_10 * V_11 = V_12 -> V_13 ;
struct V_32 * V_33 = V_12 -> V_33 ;
T_3 V_34 , V_35 , V_36 ;
T_2 V_37 , V_38 , V_39 ;
if ( V_6 -> V_40 -> V_41 )
return V_6 -> V_40 -> V_41 ( V_6 ) ;
if ( V_6 -> V_2 -> V_39 . V_40 == V_42 )
return - V_43 ;
V_37 = F_16 ( V_11 ) ;
V_36 = F_17 ( V_33 , 0 , V_6 -> V_2 -> V_39 . V_40 ,
V_6 -> V_2 -> V_39 . line ) ;
V_34 = 0 ;
do {
F_18 ( 500 , 1000 ) ;
V_35 = F_17 ( V_33 , 0 , V_6 -> V_2 -> V_39 . V_40 ,
V_6 -> V_2 -> V_39 . line ) ;
if ( V_36 != V_35 ) {
if ( ! V_37 )
V_37 = F_16 ( V_11 ) ;
V_34 ++ ;
V_36 = V_35 ;
}
} while ( V_34 < 5 && F_16 ( V_11 ) - V_37 < 250000000 );
V_38 = F_16 ( V_11 ) ;
if ( V_34 == 5 ) {
V_39 = ( T_2 ) 60000000000ULL ;
F_19 ( V_39 , ( V_38 - V_37 ) ) ;
return V_39 ;
} else
return 0 ;
}
int
F_20 ( struct V_5 * V_6 )
{
return F_13 ( V_6 ) ;
}
int
F_21 ( struct V_5 * V_6 , int V_18 )
{
if ( V_6 -> V_44 != V_45 )
return - V_46 ;
return F_14 ( V_6 , true , V_18 ) ;
}
static void
F_22 ( struct V_5 * V_6 )
{
V_6 -> V_2 -> V_20 . V_47 = 0 ;
V_6 -> V_2 -> V_20 . V_21 = 0 ;
V_6 -> V_2 -> V_20 . V_22 = 100 ;
V_6 -> V_2 -> V_20 . V_27 = 500 ;
V_6 -> V_2 -> V_20 . V_28 = 2000 ;
V_6 -> V_2 -> V_20 . V_48 = 40 ;
V_6 -> V_2 -> V_20 . V_49 = 85 ;
}
static void
F_23 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 -> V_20 . V_21 > 100 )
V_6 -> V_2 -> V_20 . V_21 = 100 ;
if ( V_6 -> V_2 -> V_20 . V_22 > 100 )
V_6 -> V_2 -> V_20 . V_22 = 100 ;
if ( V_6 -> V_2 -> V_20 . V_21 > V_6 -> V_2 -> V_20 . V_22 )
V_6 -> V_2 -> V_20 . V_21 = V_6 -> V_2 -> V_20 . V_22 ;
}
int
F_24 ( struct V_5 * V_6 )
{
return 0 ;
}
int
F_25 ( struct V_5 * V_6 , bool V_50 )
{
struct V_10 * V_11 = V_6 -> V_9 . V_12 -> V_13 ;
if ( V_50 )
F_26 ( V_11 , & V_6 -> V_2 -> V_25 ) ;
return 0 ;
}
int
F_27 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = & V_6 -> V_9 ;
struct V_31 * V_12 = V_9 -> V_12 ;
struct V_32 * V_33 = V_12 -> V_33 ;
struct V_51 * V_20 = V_12 -> V_20 ;
struct V_52 V_40 ;
int V_15 ;
V_15 = F_28 ( V_33 , 0 , V_53 , 0xff , & V_40 ) ;
if ( V_15 == 0 ) {
if ( V_40 . line != 16 && V_40 . log [ 0 ] & V_54 ) {
F_5 ( V_9 , L_3 ) ;
V_15 = - V_46 ;
} else {
V_15 = F_29 ( V_6 , & V_40 ) ;
if ( V_15 != 0 )
V_15 = F_30 ( V_6 , & V_40 ) ;
}
}
if ( V_15 != 0 ) {
V_15 = F_31 ( V_6 ) ;
if ( V_15 )
return V_15 ;
}
F_5 ( V_9 , L_4 , V_6 -> V_2 -> type ) ;
V_6 -> V_2 -> V_18 = F_13 ( V_6 ) ;
V_15 = F_28 ( V_33 , 0 , V_55 , 0xff ,
& V_6 -> V_2 -> V_39 ) ;
if ( V_15 )
V_6 -> V_2 -> V_39 . V_40 = V_42 ;
V_6 -> V_2 -> V_7 = V_6 ;
F_32 ( & V_6 -> V_2 -> V_25 , F_11 ) ;
F_33 ( & V_6 -> V_2 -> V_17 ) ;
F_22 ( V_6 ) ;
F_34 ( V_20 , & V_6 -> V_2 -> V_56 ) ;
if ( ! F_35 ( V_20 , & V_6 -> V_2 -> V_20 ) ) {
F_5 ( V_9 , L_5 ) ;
if ( F_36 ( V_20 , & V_6 -> V_2 -> V_20 ) )
F_37 ( V_9 , L_6 ) ;
}
F_23 ( V_6 ) ;
return 0 ;
}
