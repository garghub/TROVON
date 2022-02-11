static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 = V_6 ;
unsigned long V_7 ;
F_2 ( & V_8 , V_7 ) ;
if ( V_2 )
V_4 = & V_2 -> V_4 ;
else
V_4 = & V_9 ;
if ( ! F_3 ( V_4 ) )
V_5 = F_4 ( V_4 , struct V_10 ,
V_11 ) -> V_12 ;
F_5 ( & V_8 , V_7 ) ;
return V_5 ;
}
static void F_6 ( struct V_13 * V_14 )
{
struct V_10 * V_15 =
F_7 ( V_14 , struct V_10 , V_14 ) ;
unsigned long V_7 ;
T_2 V_16 ( V_17 ) , V_18 , V_19 ;
if ( V_20 && V_21 == V_22 ) {
F_8 ( V_23 L_1 ,
( long long ) V_15 -> V_12 ,
V_15 -> V_24 , F_9 ( V_25 ) ) ;
V_17 = F_10 () ;
}
V_15 -> V_24 ( V_15 -> V_26 , V_15 -> V_12 ) ;
if ( V_20 && V_21 == V_22 ) {
V_19 = F_10 () ;
V_18 = F_11 ( V_19 , V_17 ) ;
F_8 ( V_23 L_2 ,
( long long ) V_15 -> V_12 ,
V_15 -> V_24 ,
( long long ) F_12 ( V_18 ) >> 10 ) ;
}
F_2 ( & V_8 , V_7 ) ;
F_13 ( & V_15 -> V_11 ) ;
F_13 ( & V_15 -> V_27 ) ;
F_14 ( V_15 ) ;
F_15 ( & V_28 ) ;
F_5 ( & V_8 , V_7 ) ;
F_16 ( & V_29 ) ;
}
static T_1 F_17 ( T_3 V_24 , void * V_26 , struct V_1 * V_2 )
{
struct V_10 * V_15 ;
unsigned long V_7 ;
T_1 V_30 ;
V_15 = F_18 ( sizeof( struct V_10 ) , V_31 ) ;
if ( ! V_15 || F_19 ( & V_28 ) > V_32 ) {
F_14 ( V_15 ) ;
F_2 ( & V_8 , V_7 ) ;
V_30 = V_33 ++ ;
F_5 ( & V_8 , V_7 ) ;
V_24 ( V_26 , V_30 ) ;
return V_30 ;
}
F_20 ( & V_15 -> V_11 ) ;
F_20 ( & V_15 -> V_27 ) ;
F_21 ( & V_15 -> V_14 , F_6 ) ;
V_15 -> V_24 = V_24 ;
V_15 -> V_26 = V_26 ;
V_15 -> V_2 = V_2 ;
F_2 ( & V_8 , V_7 ) ;
V_30 = V_15 -> V_12 = V_33 ++ ;
F_22 ( & V_15 -> V_11 , & V_2 -> V_4 ) ;
if ( V_2 -> V_34 )
F_22 ( & V_15 -> V_27 , & V_9 ) ;
F_23 ( & V_28 ) ;
F_5 ( & V_8 , V_7 ) ;
V_25 -> V_7 |= V_35 ;
F_24 ( V_36 , & V_15 -> V_14 ) ;
return V_30 ;
}
T_1 F_25 ( T_3 V_24 , void * V_26 )
{
return F_17 ( V_24 , V_26 , & V_37 ) ;
}
T_1 F_26 ( T_3 V_24 , void * V_26 ,
struct V_1 * V_2 )
{
return F_17 ( V_24 , V_26 , V_2 ) ;
}
void F_27 ( void )
{
F_28 ( NULL ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_8 ) ;
F_31 ( ! V_2 -> V_34 || ! F_3 ( & V_2 -> V_4 ) ) ;
V_2 -> V_34 = 0 ;
F_32 ( & V_8 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_33 ( V_6 , V_2 ) ;
}
void F_33 ( T_1 V_12 , struct V_1 * V_2 )
{
T_2 V_16 ( V_38 ) , V_18 , V_39 ;
if ( V_20 && V_21 == V_22 ) {
F_8 ( V_23 L_3 , F_9 ( V_25 ) ) ;
V_38 = F_10 () ;
}
F_34 ( V_29 , F_1 ( V_2 ) >= V_12 ) ;
if ( V_20 && V_21 == V_22 ) {
V_39 = F_10 () ;
V_18 = F_11 ( V_39 , V_38 ) ;
F_8 ( V_23 L_4 ,
F_9 ( V_25 ) ,
( long long ) F_12 ( V_18 ) >> 10 ) ;
}
}
void F_35 ( T_1 V_12 )
{
F_33 ( V_12 , & V_37 ) ;
}
bool F_36 ( void )
{
struct V_40 * V_40 = F_37 () ;
return V_40 && V_40 -> V_41 == F_6 ;
}
