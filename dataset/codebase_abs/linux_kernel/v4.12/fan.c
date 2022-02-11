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
if ( V_4 != V_16 ) {
T_1 V_25 = V_2 -> V_20 . V_25 ;
T_1 V_26 = V_2 -> V_20 . V_26 ;
T_2 V_27 ;
if ( V_16 > V_4 )
V_27 = V_26 ;
else if ( V_16 == V_4 )
V_27 = F_7 ( V_25 , V_26 ) ;
else
V_27 = V_25 ;
F_9 ( V_11 , V_27 * 1000 * 1000 , & V_2 -> V_28 ) ;
}
return V_15 ;
}
static void
F_10 ( struct V_29 * V_28 )
{
struct V_1 * V_2 = F_11 ( V_28 , struct V_1 , V_28 ) ;
F_1 ( V_2 , false , - 1 ) ;
}
int
F_12 ( struct V_5 * V_6 )
{
return V_6 -> V_2 -> V_23 ( V_6 ) ;
}
int
F_13 ( struct V_5 * V_6 , bool V_3 , int V_18 )
{
return F_1 ( V_6 -> V_2 , V_3 , V_18 ) ;
}
int
F_14 ( struct V_5 * V_6 )
{
struct V_30 * V_12 = V_6 -> V_9 . V_12 ;
struct V_10 * V_11 = V_12 -> V_13 ;
struct V_31 * V_32 = V_12 -> V_32 ;
T_3 V_33 , V_34 , V_35 ;
T_2 V_36 , V_37 , V_38 ;
if ( V_6 -> V_39 -> V_40 )
return V_6 -> V_39 -> V_40 ( V_6 ) ;
if ( V_6 -> V_2 -> V_38 . V_39 == V_41 )
return - V_42 ;
V_36 = F_15 ( V_11 ) ;
V_35 = F_16 ( V_32 , 0 , V_6 -> V_2 -> V_38 . V_39 ,
V_6 -> V_2 -> V_38 . line ) ;
V_33 = 0 ;
do {
F_17 ( 500 , 1000 ) ;
V_34 = F_16 ( V_32 , 0 , V_6 -> V_2 -> V_38 . V_39 ,
V_6 -> V_2 -> V_38 . line ) ;
if ( V_35 != V_34 ) {
if ( ! V_36 )
V_36 = F_15 ( V_11 ) ;
V_33 ++ ;
V_35 = V_34 ;
}
} while ( V_33 < 5 && F_15 ( V_11 ) - V_36 < 250000000 );
V_37 = F_15 ( V_11 ) ;
if ( V_33 == 5 ) {
V_38 = ( T_2 ) 60000000000ULL ;
F_18 ( V_38 , ( V_37 - V_36 ) ) ;
return V_38 ;
} else
return 0 ;
}
int
F_19 ( struct V_5 * V_6 )
{
return F_12 ( V_6 ) ;
}
int
F_20 ( struct V_5 * V_6 , int V_18 )
{
if ( V_6 -> V_43 != V_44 )
return - V_45 ;
return F_13 ( V_6 , true , V_18 ) ;
}
static void
F_21 ( struct V_5 * V_6 )
{
V_6 -> V_2 -> V_20 . V_46 = 0 ;
V_6 -> V_2 -> V_20 . V_21 = 0 ;
V_6 -> V_2 -> V_20 . V_22 = 100 ;
V_6 -> V_2 -> V_20 . V_25 = 500 ;
V_6 -> V_2 -> V_20 . V_26 = 2000 ;
V_6 -> V_2 -> V_20 . V_47 = 40 ;
V_6 -> V_2 -> V_20 . V_48 = 85 ;
}
static void
F_22 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 -> V_20 . V_21 > 100 )
V_6 -> V_2 -> V_20 . V_21 = 100 ;
if ( V_6 -> V_2 -> V_20 . V_22 > 100 )
V_6 -> V_2 -> V_20 . V_22 = 100 ;
if ( V_6 -> V_2 -> V_20 . V_21 > V_6 -> V_2 -> V_20 . V_22 )
V_6 -> V_2 -> V_20 . V_21 = V_6 -> V_2 -> V_20 . V_22 ;
}
int
F_23 ( struct V_5 * V_6 )
{
return 0 ;
}
int
F_24 ( struct V_5 * V_6 , bool V_49 )
{
struct V_10 * V_11 = V_6 -> V_9 . V_12 -> V_13 ;
if ( V_49 )
F_25 ( V_11 , & V_6 -> V_2 -> V_28 ) ;
return 0 ;
}
int
F_26 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = & V_6 -> V_9 ;
struct V_30 * V_12 = V_9 -> V_12 ;
struct V_31 * V_32 = V_12 -> V_32 ;
struct V_50 * V_20 = V_12 -> V_20 ;
struct V_51 V_39 ;
int V_15 ;
V_15 = F_27 ( V_32 , 0 , V_52 , 0xff , & V_39 ) ;
if ( V_15 == 0 ) {
if ( V_39 . line != 16 && V_39 . log [ 0 ] & V_53 ) {
F_5 ( V_9 , L_3 ) ;
V_15 = - V_45 ;
} else {
V_15 = F_28 ( V_6 , & V_39 ) ;
if ( V_15 != 0 )
V_15 = F_29 ( V_6 , & V_39 ) ;
}
}
if ( V_15 != 0 ) {
V_15 = F_30 ( V_6 ) ;
if ( V_15 )
return V_15 ;
}
F_5 ( V_9 , L_4 , V_6 -> V_2 -> type ) ;
V_6 -> V_2 -> V_18 = F_12 ( V_6 ) ;
V_15 = F_27 ( V_32 , 0 , V_54 , 0xff ,
& V_6 -> V_2 -> V_38 ) ;
if ( V_15 )
V_6 -> V_2 -> V_38 . V_39 = V_41 ;
V_6 -> V_2 -> V_7 = V_6 ;
F_31 ( & V_6 -> V_2 -> V_28 , F_10 ) ;
F_32 ( & V_6 -> V_2 -> V_17 ) ;
F_21 ( V_6 ) ;
F_33 ( V_20 , & V_6 -> V_2 -> V_55 ) ;
if ( ! F_34 ( V_20 , & V_6 -> V_2 -> V_20 ) ) {
F_5 ( V_9 , L_5 ) ;
if ( F_35 ( V_20 , & V_6 -> V_2 -> V_20 ) )
F_36 ( V_9 , L_6 ) ;
}
F_22 ( V_6 ) ;
return 0 ;
}
