static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
T_1 V_5 = V_6 ;
unsigned long V_7 ;
F_2 ( & V_8 , V_7 ) ;
if ( V_2 ) {
if ( ! F_3 ( & V_2 -> V_9 ) )
V_4 = F_4 ( & V_2 -> V_9 ,
struct V_3 , V_10 ) ;
} else {
if ( ! F_3 ( & V_11 ) )
V_4 = F_4 ( & V_11 ,
struct V_3 , V_12 ) ;
}
if ( V_4 )
V_5 = V_4 -> V_13 ;
F_5 ( & V_8 , V_7 ) ;
return V_5 ;
}
static void F_6 ( struct V_14 * V_15 )
{
struct V_3 * V_16 =
F_7 ( V_15 , struct V_3 , V_15 ) ;
unsigned long V_7 ;
T_2 V_17 ( V_18 ) , V_19 , V_20 ;
if ( V_21 && V_22 == V_23 ) {
F_8 ( V_24 L_1 ,
( long long ) V_16 -> V_13 ,
V_16 -> V_25 , F_9 ( V_26 ) ) ;
V_18 = F_10 () ;
}
V_16 -> V_25 ( V_16 -> V_27 , V_16 -> V_13 ) ;
if ( V_21 && V_22 == V_23 ) {
V_20 = F_10 () ;
V_19 = F_11 ( V_20 , V_18 ) ;
F_8 ( V_24 L_2 ,
( long long ) V_16 -> V_13 ,
V_16 -> V_25 ,
( long long ) F_12 ( V_19 ) >> 10 ) ;
}
F_2 ( & V_8 , V_7 ) ;
F_13 ( & V_16 -> V_10 ) ;
F_13 ( & V_16 -> V_12 ) ;
F_14 ( V_16 ) ;
F_15 ( & V_28 ) ;
F_5 ( & V_8 , V_7 ) ;
F_16 ( & V_29 ) ;
}
static T_1 F_17 ( T_3 * V_30 , void * V_27 , struct V_1 * V_2 )
{
struct V_3 * V_16 ;
unsigned long V_7 ;
T_1 V_31 ;
V_16 = F_18 ( sizeof( struct V_3 ) , V_32 ) ;
if ( ! V_16 || F_19 ( & V_28 ) > V_33 ) {
F_14 ( V_16 ) ;
F_2 ( & V_8 , V_7 ) ;
V_31 = V_34 ++ ;
F_5 ( & V_8 , V_7 ) ;
V_30 ( V_27 , V_31 ) ;
return V_31 ;
}
F_20 ( & V_16 -> V_10 ) ;
F_20 ( & V_16 -> V_12 ) ;
F_21 ( & V_16 -> V_15 , F_6 ) ;
V_16 -> V_25 = V_30 ;
V_16 -> V_27 = V_27 ;
V_16 -> V_2 = V_2 ;
F_2 ( & V_8 , V_7 ) ;
V_31 = V_16 -> V_13 = V_34 ++ ;
F_22 ( & V_16 -> V_10 , & V_2 -> V_9 ) ;
if ( V_2 -> V_35 )
F_22 ( & V_16 -> V_12 , & V_11 ) ;
F_23 ( & V_28 ) ;
F_5 ( & V_8 , V_7 ) ;
V_26 -> V_7 |= V_36 ;
F_24 ( V_37 , & V_16 -> V_15 ) ;
return V_31 ;
}
T_1 F_25 ( T_3 * V_30 , void * V_27 )
{
return F_17 ( V_30 , V_27 , & V_38 ) ;
}
T_1 F_26 ( T_3 * V_30 , void * V_27 ,
struct V_1 * V_2 )
{
return F_17 ( V_30 , V_27 , V_2 ) ;
}
void F_27 ( void )
{
F_28 ( NULL ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_8 ) ;
F_31 ( ! V_2 -> V_35 || ! F_3 ( & V_2 -> V_9 ) ) ;
V_2 -> V_35 = 0 ;
F_32 ( & V_8 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_33 ( V_6 , V_2 ) ;
}
void F_33 ( T_1 V_13 , struct V_1 * V_2 )
{
T_2 V_17 ( V_39 ) , V_19 , V_40 ;
if ( V_21 && V_22 == V_23 ) {
F_8 ( V_24 L_3 , F_9 ( V_26 ) ) ;
V_39 = F_10 () ;
}
F_34 ( V_29 , F_1 ( V_2 ) >= V_13 ) ;
if ( V_21 && V_22 == V_23 ) {
V_40 = F_10 () ;
V_19 = F_11 ( V_40 , V_39 ) ;
F_8 ( V_24 L_4 ,
F_9 ( V_26 ) ,
( long long ) F_12 ( V_19 ) >> 10 ) ;
}
}
void F_35 ( T_1 V_13 )
{
F_33 ( V_13 , & V_38 ) ;
}
bool F_36 ( void )
{
struct V_41 * V_41 = F_37 () ;
return V_41 && V_41 -> V_42 == F_6 ;
}
