static int
F_1 ( struct V_1 * V_2 , bool V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = ( void * ) V_6 ;
struct V_10 * V_11 = V_10 ( V_9 ) ;
unsigned long V_12 ;
int V_13 = 0 ;
int V_14 ;
F_2 ( & V_2 -> V_15 , V_12 ) ;
if ( V_4 < 0 )
V_4 = V_2 -> V_16 ;
V_4 = F_3 ( V_17 , V_4 , V_2 -> V_18 . V_19 ) ;
V_4 = F_4 ( V_17 , V_4 , V_2 -> V_18 . V_20 ) ;
if ( V_2 -> V_16 != V_4 ) {
F_5 ( V_6 , L_1 , V_4 ) ;
V_2 -> V_16 = V_4 ;
}
V_14 = V_2 -> V_21 ( V_6 ) ;
if ( V_14 == V_4 ) {
F_6 ( & V_2 -> V_15 , V_12 ) ;
return 0 ;
}
if ( ! V_3 && V_14 >= 0 ) {
if ( V_14 < V_4 )
V_14 = F_7 ( V_14 + 3 , V_4 ) ;
else if ( V_14 > V_4 )
V_14 = F_8 ( V_14 - 3 , V_4 ) ;
} else {
V_14 = V_4 ;
}
F_5 ( V_6 , L_2 , V_14 ) ;
V_13 = V_2 -> V_22 ( V_6 , V_14 ) ;
if ( V_13 ) {
F_6 ( & V_2 -> V_15 , V_12 ) ;
return V_13 ;
}
F_6 ( & V_2 -> V_15 , V_12 ) ;
if ( F_9 ( & V_2 -> V_23 . V_24 ) && V_4 != V_14 ) {
T_1 V_25 = V_2 -> V_18 . V_25 ;
T_1 V_26 = V_2 -> V_18 . V_26 ;
T_2 V_27 ;
if ( V_14 > V_4 )
V_27 = V_26 ;
else if ( V_14 == V_4 )
V_27 = F_7 ( V_25 , V_26 ) ;
else
V_27 = V_25 ;
V_11 -> V_23 ( V_11 , V_27 * 1000 * 1000 , & V_2 -> V_23 ) ;
}
return V_13 ;
}
static void
F_10 ( struct V_28 * V_23 )
{
struct V_1 * V_2 = F_11 ( V_23 , struct V_1 , V_23 ) ;
F_1 ( V_2 , false , - 1 ) ;
}
int
F_12 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = ( void * ) V_6 ;
return V_9 -> V_2 -> V_21 ( V_6 ) ;
}
int
F_13 ( struct V_5 * V_6 , bool V_3 , int V_16 )
{
struct V_8 * V_9 = ( void * ) V_6 ;
return F_1 ( V_9 -> V_2 , V_3 , V_16 ) ;
}
int
F_14 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = ( void * ) V_6 ;
struct V_10 * V_11 = V_10 ( V_6 ) ;
struct V_29 * V_30 = V_29 ( V_6 ) ;
T_3 V_31 , V_32 , V_33 ;
T_2 V_34 , V_35 , V_36 ;
if ( V_9 -> V_2 -> V_36 . V_37 == V_38 )
return - V_39 ;
V_34 = V_11 -> V_40 ( V_11 ) ;
V_33 = V_30 -> V_21 ( V_30 , 0 , V_9 -> V_2 -> V_36 . V_37 , V_9 -> V_2 -> V_36 . line ) ;
V_31 = 0 ;
do {
F_15 ( 500 , 1000 ) ;
V_32 = V_30 -> V_21 ( V_30 , 0 , V_9 -> V_2 -> V_36 . V_37 , V_9 -> V_2 -> V_36 . line ) ;
if ( V_33 != V_32 ) {
if ( ! V_34 )
V_34 = V_11 -> V_40 ( V_11 ) ;
V_31 ++ ;
V_33 = V_32 ;
}
} while ( V_31 < 5 && V_11 -> V_40 ( V_11 ) - V_34 < 250000000 );
V_35 = V_11 -> V_40 ( V_11 ) ;
if ( V_31 == 5 ) {
V_36 = ( T_2 ) 60000000000ULL ;
F_16 ( V_36 , ( V_35 - V_34 ) ) ;
return V_36 ;
} else
return 0 ;
}
int
F_17 ( struct V_5 * V_6 )
{
return F_12 ( V_6 ) ;
}
int
F_18 ( struct V_5 * V_6 , int V_16 )
{
struct V_8 * V_9 = ( void * ) V_6 ;
if ( V_9 -> V_41 != V_42 )
return - V_43 ;
return F_13 ( V_6 , true , V_16 ) ;
}
static void
F_19 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = ( void * ) V_6 ;
V_9 -> V_2 -> V_18 . V_44 = 0 ;
V_9 -> V_2 -> V_18 . V_19 = 0 ;
V_9 -> V_2 -> V_18 . V_20 = 100 ;
V_9 -> V_2 -> V_18 . V_25 = 500 ;
V_9 -> V_2 -> V_18 . V_26 = 2000 ;
V_9 -> V_2 -> V_18 . V_45 = 40 ;
V_9 -> V_2 -> V_18 . V_46 = 85 ;
}
static void
F_20 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = ( void * ) V_6 ;
if ( V_9 -> V_2 -> V_18 . V_19 > 100 )
V_9 -> V_2 -> V_18 . V_19 = 100 ;
if ( V_9 -> V_2 -> V_18 . V_20 > 100 )
V_9 -> V_2 -> V_18 . V_20 = 100 ;
if ( V_9 -> V_2 -> V_18 . V_19 > V_9 -> V_2 -> V_18 . V_20 )
V_9 -> V_2 -> V_18 . V_19 = V_9 -> V_2 -> V_18 . V_20 ;
}
int
F_21 ( struct V_5 * V_6 )
{
return 0 ;
}
int
F_22 ( struct V_5 * V_6 , bool V_47 )
{
struct V_8 * V_9 = ( void * ) V_6 ;
struct V_10 * V_11 = V_10 ( V_6 ) ;
if ( V_47 )
V_11 -> V_48 ( V_11 , & V_9 -> V_2 -> V_23 ) ;
return 0 ;
}
int
F_23 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = ( void * ) V_6 ;
struct V_29 * V_30 = V_29 ( V_6 ) ;
struct V_49 * V_18 = V_49 ( V_6 ) ;
struct V_50 V_37 ;
int V_13 ;
V_13 = V_30 -> V_51 ( V_30 , 0 , V_52 , 0xff , & V_37 ) ;
if ( V_13 == 0 ) {
if ( V_37 . line != 16 && V_37 . log [ 0 ] & V_53 ) {
F_5 ( V_6 , L_3 ) ;
V_13 = - V_43 ;
} else {
V_13 = F_24 ( V_6 , & V_37 ) ;
if ( V_13 != 0 )
V_13 = F_25 ( V_6 , & V_37 ) ;
}
}
if ( V_13 != 0 ) {
V_13 = F_26 ( V_6 ) ;
if ( V_13 )
return V_13 ;
}
F_27 ( V_6 , L_4 , V_9 -> V_2 -> type ) ;
V_9 -> V_2 -> V_16 = F_12 ( V_6 ) ;
V_13 = V_30 -> V_51 ( V_30 , 0 , V_54 , 0xff , & V_9 -> V_2 -> V_36 ) ;
if ( V_13 )
V_9 -> V_2 -> V_36 . V_37 = V_38 ;
V_9 -> V_2 -> V_7 = V_6 ;
F_28 ( & V_9 -> V_2 -> V_23 , F_10 ) ;
F_29 ( & V_9 -> V_2 -> V_15 ) ;
F_19 ( V_6 ) ;
F_30 ( V_18 , & V_9 -> V_2 -> V_55 ) ;
if ( F_31 ( V_18 , & V_9 -> V_2 -> V_18 ) )
F_32 ( V_6 , L_5 ) ;
F_20 ( V_6 ) ;
return 0 ;
}
