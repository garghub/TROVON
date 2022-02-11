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
F_8 ( L_1 ,
( long long ) V_15 -> V_12 ,
V_15 -> V_23 , F_9 ( V_24 ) ) ;
V_17 = F_10 () ;
}
V_15 -> V_23 ( V_15 -> V_25 , V_15 -> V_12 ) ;
if ( V_20 && V_21 == V_22 ) {
V_19 = F_10 () ;
V_18 = F_11 ( V_19 , V_17 ) ;
F_8 ( L_2 ,
( long long ) V_15 -> V_12 ,
V_15 -> V_23 ,
( long long ) F_12 ( V_18 ) >> 10 ) ;
}
F_2 ( & V_8 , V_7 ) ;
F_13 ( & V_15 -> V_11 ) ;
F_13 ( & V_15 -> V_26 ) ;
F_14 ( V_15 ) ;
F_15 ( & V_27 ) ;
F_5 ( & V_8 , V_7 ) ;
F_16 ( & V_28 ) ;
}
static T_1 F_17 ( T_3 V_23 , void * V_25 , struct V_1 * V_2 )
{
struct V_10 * V_15 ;
unsigned long V_7 ;
T_1 V_29 ;
V_15 = F_18 ( sizeof( struct V_10 ) , V_30 ) ;
if ( ! V_15 || F_19 ( & V_27 ) > V_31 ) {
F_14 ( V_15 ) ;
F_2 ( & V_8 , V_7 ) ;
V_29 = V_32 ++ ;
F_5 ( & V_8 , V_7 ) ;
V_23 ( V_25 , V_29 ) ;
return V_29 ;
}
F_20 ( & V_15 -> V_11 ) ;
F_20 ( & V_15 -> V_26 ) ;
F_21 ( & V_15 -> V_14 , F_6 ) ;
V_15 -> V_23 = V_23 ;
V_15 -> V_25 = V_25 ;
V_15 -> V_2 = V_2 ;
F_2 ( & V_8 , V_7 ) ;
V_29 = V_15 -> V_12 = V_32 ++ ;
F_22 ( & V_15 -> V_11 , & V_2 -> V_4 ) ;
if ( V_2 -> V_33 )
F_22 ( & V_15 -> V_26 , & V_9 ) ;
F_23 ( & V_27 ) ;
F_5 ( & V_8 , V_7 ) ;
V_24 -> V_7 |= V_34 ;
F_24 ( V_35 , & V_15 -> V_14 ) ;
return V_29 ;
}
T_1 F_25 ( T_3 V_23 , void * V_25 )
{
return F_17 ( V_23 , V_25 , & V_36 ) ;
}
T_1 F_26 ( T_3 V_23 , void * V_25 ,
struct V_1 * V_2 )
{
return F_17 ( V_23 , V_25 , V_2 ) ;
}
void F_27 ( void )
{
F_28 ( NULL ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_8 ) ;
F_31 ( ! V_2 -> V_33 || ! F_3 ( & V_2 -> V_4 ) ) ;
V_2 -> V_33 = 0 ;
F_32 ( & V_8 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_33 ( V_6 , V_2 ) ;
}
void F_33 ( T_1 V_12 , struct V_1 * V_2 )
{
T_2 V_16 ( V_37 ) , V_18 , V_38 ;
if ( V_20 && V_21 == V_22 ) {
F_8 ( L_3 , F_9 ( V_24 ) ) ;
V_37 = F_10 () ;
}
F_34 ( V_28 , F_1 ( V_2 ) >= V_12 ) ;
if ( V_20 && V_21 == V_22 ) {
V_38 = F_10 () ;
V_18 = F_11 ( V_38 , V_37 ) ;
F_8 ( L_4 ,
F_9 ( V_24 ) ,
( long long ) F_12 ( V_18 ) >> 10 ) ;
}
}
void F_35 ( T_1 V_12 )
{
F_33 ( V_12 , & V_36 ) ;
}
bool F_36 ( void )
{
struct V_39 * V_39 = F_37 () ;
return V_39 && V_39 -> V_40 == F_6 ;
}
