static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 )
F_2 ( V_2 -> V_5 ) ;
F_3 ( V_2 -> V_6 , V_4 , V_2 -> V_7 , V_2 -> V_8 ) ;
if ( V_2 -> V_5 )
F_4 ( V_2 -> V_5 ) ;
}
static void F_5 ( unsigned long V_9 )
{
struct V_1 * V_10 = (struct V_1 * ) V_9 ;
struct V_3 V_4 ;
T_1 V_11 , V_12 ;
F_1 ( V_10 , & V_4 ) ;
V_12 = ( V_4 . V_13 - V_10 -> V_14 ) << ( 8 - V_10 -> V_15 ) ;
V_12 -= ( V_10 -> V_16 >> V_10 -> V_15 ) ;
V_11 = ( T_1 ) ( V_4 . V_17 - V_10 -> V_18 ) << ( 8 - V_10 -> V_15 ) ;
V_11 -= ( V_10 -> V_19 >> V_10 -> V_15 ) ;
F_6 ( & V_10 -> V_20 ) ;
V_10 -> V_16 += V_12 ;
V_10 -> V_19 += V_11 ;
F_7 ( & V_10 -> V_20 ) ;
V_10 -> V_14 = V_4 . V_13 ;
V_10 -> V_18 = V_4 . V_17 ;
V_10 -> V_21 += ( ( V_22 / 4 ) << V_10 -> V_23 ) ;
if ( F_8 ( F_9 ( V_24 , V_10 -> V_21 ) ) ) {
V_10 -> V_21 = V_24 + 1 ;
}
F_10 ( & V_10 -> V_25 , V_10 -> V_21 ) ;
}
int F_11 ( struct V_3 * V_8 ,
struct V_26 T_2 * V_7 ,
struct V_1 T_3 * * V_27 ,
T_4 * V_5 ,
T_5 * V_6 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = F_12 ( V_29 ) ;
struct V_1 * V_32 , * V_10 ;
struct V_3 V_4 ;
int V_23 ;
if ( F_13 ( V_29 ) < sizeof( * V_31 ) )
return - V_33 ;
if ( V_31 -> V_34 < - 2 || V_31 -> V_34 > 3 )
return - V_33 ;
V_10 = F_14 ( sizeof( * V_10 ) , V_35 ) ;
if ( ! V_10 )
return - V_36 ;
F_15 ( & V_10 -> V_20 ) ;
V_23 = V_31 -> V_34 + 2 ;
V_10 -> V_8 = V_8 ;
V_10 -> V_5 = V_5 ;
V_10 -> V_6 = V_6 ;
V_10 -> V_15 = V_31 -> V_15 ;
V_10 -> V_23 = V_23 ;
V_10 -> V_7 = V_7 ;
F_1 ( V_10 , & V_4 ) ;
V_10 -> V_14 = V_4 . V_13 ;
V_10 -> V_18 = V_4 . V_17 ;
V_32 = F_16 ( * V_27 , 1 ) ;
if ( V_32 ) {
F_17 ( & V_32 -> V_25 ) ;
V_10 -> V_16 = V_32 -> V_16 ;
V_10 -> V_19 = V_32 -> V_19 ;
}
V_10 -> V_21 = V_24 + ( ( V_22 / 4 ) << V_23 ) ;
F_18 ( & V_10 -> V_25 , F_5 , ( unsigned long ) V_10 ) ;
F_10 ( & V_10 -> V_25 , V_10 -> V_21 ) ;
F_19 ( * V_27 , V_10 ) ;
if ( V_32 )
F_20 ( V_32 , V_37 ) ;
return 0 ;
}
void F_21 ( struct V_1 T_3 * * V_27 )
{
struct V_1 * V_10 ;
V_10 = F_22 ( ( V_38 struct V_1 * * ) V_27 , NULL ) ;
if ( V_10 ) {
F_17 ( & V_10 -> V_25 ) ;
F_20 ( V_10 , V_37 ) ;
}
}
int F_23 ( struct V_3 * V_8 ,
struct V_26 T_2 * V_7 ,
struct V_1 T_3 * * V_27 ,
T_4 * V_5 ,
T_5 * V_6 , struct V_28 * V_29 )
{
return F_11 ( V_8 , V_7 , V_27 ,
V_5 , V_6 , V_29 ) ;
}
bool F_24 ( struct V_1 T_3 * * V_27 )
{
return ! ! F_25 ( * V_27 ) ;
}
bool F_26 ( struct V_1 T_3 * * V_27 ,
struct V_39 * V_40 )
{
struct V_1 * V_10 ;
unsigned V_20 ;
F_27 () ;
V_10 = F_28 ( * V_27 ) ;
if ( ! V_10 ) {
F_29 () ;
return false ;
}
do {
V_20 = F_30 ( & V_10 -> V_20 ) ;
V_40 -> V_41 = V_10 -> V_16 >> 8 ;
V_40 -> V_42 = V_10 -> V_19 >> 8 ;
} while ( F_31 ( & V_10 -> V_20 , V_20 ) );
F_29 () ;
return true ;
}
