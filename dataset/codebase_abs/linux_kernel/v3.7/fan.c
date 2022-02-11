int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
struct V_5 * V_6 = V_5 ( V_2 ) ;
struct V_7 V_8 ;
int V_9 = F_2 ( V_2 ) -> V_9 ;
T_1 V_10 , V_11 ;
int V_12 ;
if ( ! V_4 -> V_13 . V_14 )
return - V_15 ;
V_12 = V_6 -> V_16 ( V_6 , 0 , V_17 , 0xff , & V_8 ) ;
if ( V_12 == 0 ) {
V_12 = V_4 -> V_13 . V_14 ( V_2 , V_8 . line , & V_10 , & V_11 ) ;
if ( V_12 == 0 && V_10 ) {
V_10 = F_3 ( V_10 , V_11 ) ;
if ( V_9 <= V_18 || ( V_8 . log [ 0 ] & 1 ) )
V_11 = V_10 - V_11 ;
return ( V_11 * 100 ) / V_10 ;
}
return V_6 -> V_19 ( V_6 , 0 , V_8 . V_8 , V_8 . line ) * 100 ;
}
return - V_15 ;
}
int
F_4 ( struct V_1 * V_2 , int V_20 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
struct V_5 * V_6 = V_5 ( V_2 ) ;
struct V_7 V_8 ;
int V_9 = F_2 ( V_2 ) -> V_9 ;
T_1 V_10 , V_11 ;
int V_12 ;
if ( V_4 -> V_13 . V_21 == V_22 )
return - V_23 ;
if ( ! V_4 -> V_13 . V_24 )
return - V_15 ;
if ( V_20 < V_4 -> V_25 . V_26 )
V_20 = V_4 -> V_25 . V_26 ;
if ( V_20 > V_4 -> V_25 . V_27 )
V_20 = V_4 -> V_25 . V_27 ;
V_12 = V_6 -> V_16 ( V_6 , 0 , V_17 , 0xff , & V_8 ) ;
if ( V_12 == 0 ) {
V_10 = V_4 -> V_28 . V_29 ;
if ( V_4 -> V_25 . V_30 ) {
V_10 = 1 ;
if ( V_4 -> V_13 . V_31 )
V_10 = V_4 -> V_13 . V_31 ( V_2 ) ;
V_10 /= V_4 -> V_25 . V_30 ;
}
V_11 = ( ( V_10 * V_20 ) + 99 ) / 100 ;
if ( V_9 <= V_18 || ( V_8 . log [ 0 ] & 1 ) )
V_11 = V_10 - V_11 ;
V_12 = V_4 -> V_13 . V_24 ( V_2 , V_8 . line , V_10 , V_11 ) ;
return V_12 ;
}
return - V_15 ;
}
int
F_5 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_32 ( V_2 ) ;
struct V_5 * V_6 = V_5 ( V_2 ) ;
struct V_7 V_8 ;
T_1 V_34 , V_35 , V_36 ;
T_2 V_37 , V_38 , V_39 ;
if ( V_6 -> V_16 ( V_6 , 0 , V_40 , 0xff , & V_8 ) )
return - V_15 ;
V_37 = V_33 -> V_41 ( V_33 ) ;
V_36 = V_6 -> V_19 ( V_6 , 0 , V_8 . V_8 , V_8 . line ) ;
V_34 = 0 ;
do {
F_6 ( 500 , 1000 ) ;
V_35 = V_6 -> V_19 ( V_6 , 0 , V_8 . V_8 , V_8 . line ) ;
if ( V_36 != V_35 ) {
if ( ! V_37 )
V_37 = V_33 -> V_41 ( V_33 ) ;
V_34 ++ ;
V_36 = V_35 ;
}
} while ( V_34 < 5 && V_33 -> V_41 ( V_33 ) - V_37 < 250000000 );
V_38 = V_33 -> V_41 ( V_33 ) ;
if ( V_34 == 5 ) {
V_39 = ( T_2 ) 60000000000ULL ;
F_7 ( V_39 , ( V_38 - V_37 ) ) ;
return V_39 ;
} else
return 0 ;
}
int
F_8 ( struct V_1 * V_2 ,
enum V_42 V_21 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
if ( V_4 -> V_13 . V_21 == V_21 )
return 0 ;
if ( V_21 < V_22 || V_21 >= V_43 )
return - V_23 ;
switch ( V_21 )
{
case V_22 :
F_9 ( V_2 , L_1 ) ;
break;
case V_44 :
F_9 ( V_2 , L_2 ) ;
break;
case V_43 :
break;
}
V_4 -> V_13 . V_21 = V_21 ;
return 0 ;
}
int
F_10 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
int
F_11 ( struct V_1 * V_2 , int V_20 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
if ( V_4 -> V_13 . V_21 != V_44 )
return - V_23 ;
return F_4 ( V_2 , V_20 ) ;
}
void
F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
V_4 -> V_25 . V_30 = 0 ;
V_4 -> V_25 . V_26 = 0 ;
V_4 -> V_25 . V_27 = 100 ;
}
static void
F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
if ( V_4 -> V_25 . V_26 > 100 )
V_4 -> V_25 . V_26 = 100 ;
if ( V_4 -> V_25 . V_27 > 100 )
V_4 -> V_25 . V_27 = 100 ;
if ( V_4 -> V_25 . V_26 > V_4 -> V_25 . V_27 )
V_4 -> V_25 . V_26 = V_4 -> V_25 . V_27 ;
}
int F_14 ( struct V_1 * V_2 )
{
return 1 ;
}
int
F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
struct V_45 * V_46 = V_45 ( V_2 ) ;
F_12 ( V_2 ) ;
F_16 ( V_46 , & V_4 -> V_28 ) ;
if ( F_17 ( V_46 , & V_4 -> V_25 ) )
F_18 ( V_2 , L_3 ) ;
F_13 ( V_2 ) ;
F_8 ( V_2 , V_22 ) ;
return 0 ;
}
