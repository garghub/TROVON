static int F_1 ( void * V_1 )
{
struct V_2 V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
while ( ! F_2 () ) {
F_3 ( & V_7 -> V_8 ) ;
if ( ! F_4 ( & V_7 -> V_9 ) ) {
F_5 ( V_10 ) ;
if ( F_2 () )
F_5 ( V_11 ) ;
F_6 ( & V_7 -> V_8 ) ;
F_7 () ;
continue;
}
if( ! F_8 ( & V_7 -> V_9 , & V_3 , 1 ) )
F_9 ( & V_7 -> V_12 -> V_12 , L_1 ) ;
F_6 ( & V_7 -> V_8 ) ;
F_10 ( & V_13 ) ;
F_11 (handler, &ir_raw_handler_list, list)
if ( V_7 -> V_12 -> V_14 & V_5 -> V_15 ||
! V_5 -> V_15 )
V_5 -> V_16 ( V_7 -> V_12 , V_3 ) ;
V_7 -> V_17 = V_3 ;
F_12 ( & V_13 ) ;
}
return 0 ;
}
int F_13 ( struct V_18 * V_12 , struct V_2 * V_3 )
{
if ( ! V_12 -> V_7 )
return - V_19 ;
F_14 ( 2 , L_2 ,
F_15 ( V_3 -> V_20 ) , F_16 ( V_3 -> V_21 ) ) ;
if ( ! F_17 ( & V_12 -> V_7 -> V_9 , * V_3 ) ) {
F_9 ( & V_12 -> V_12 , L_3 ) ;
return - V_22 ;
}
return 0 ;
}
int F_18 ( struct V_18 * V_12 , enum V_23 type )
{
T_1 V_24 ;
T_2 V_25 ;
F_19 ( V_3 ) ;
int V_26 = 0 ;
int V_27 ;
if ( ! V_12 -> V_7 )
return - V_19 ;
V_24 = F_20 () ;
V_25 = F_21 ( F_22 ( V_24 , V_12 -> V_7 -> V_28 ) ) ;
V_27 = F_23 ( V_12 -> V_29 -> V_30 [ V_31 ] ) ;
if ( V_25 > V_27 || ! V_12 -> V_7 -> V_32 )
type |= V_33 ;
else
V_3 . V_20 = V_25 ;
if ( type & V_33 )
F_24 ( V_12 ) ;
else if ( V_12 -> V_7 -> V_32 & V_34 ) {
V_3 . V_21 = false ;
V_26 = F_13 ( V_12 , & V_3 ) ;
} else if ( V_12 -> V_7 -> V_32 & V_35 ) {
V_3 . V_21 = true ;
V_26 = F_13 ( V_12 , & V_3 ) ;
} else
return 0 ;
V_12 -> V_7 -> V_28 = V_24 ;
V_12 -> V_7 -> V_32 = type ;
return V_26 ;
}
int F_25 ( struct V_18 * V_12 , struct V_2 * V_3 )
{
if ( ! V_12 -> V_7 )
return - V_19 ;
if ( V_12 -> V_36 && ! V_3 -> V_21 )
return 0 ;
else if ( V_12 -> V_36 )
F_26 ( V_12 , false ) ;
if ( ! V_12 -> V_7 -> V_37 . V_20 )
V_12 -> V_7 -> V_37 = * V_3 ;
else if ( V_3 -> V_21 == V_12 -> V_7 -> V_37 . V_21 )
V_12 -> V_7 -> V_37 . V_20 += V_3 -> V_20 ;
else {
F_13 ( V_12 , & V_12 -> V_7 -> V_37 ) ;
V_12 -> V_7 -> V_37 = * V_3 ;
}
if ( ! V_3 -> V_21 && V_12 -> V_38 &&
V_12 -> V_7 -> V_37 . V_20 >= V_12 -> V_38 )
F_26 ( V_12 , true ) ;
return 1 ;
}
void F_26 ( struct V_18 * V_12 , bool V_36 )
{
if ( ! V_12 -> V_7 )
return;
F_14 ( 2 , L_4 , V_36 ? L_5 : L_6 ) ;
if ( V_36 ) {
V_12 -> V_7 -> V_37 . V_38 = true ;
F_13 ( V_12 , & V_12 -> V_7 -> V_37 ) ;
F_27 ( & V_12 -> V_7 -> V_37 ) ;
}
if ( V_12 -> V_39 )
V_12 -> V_39 ( V_12 , V_36 ) ;
V_12 -> V_36 = V_36 ;
}
void F_28 ( struct V_18 * V_12 )
{
unsigned long V_40 ;
if ( ! V_12 -> V_7 )
return;
F_29 ( & V_12 -> V_7 -> V_8 , V_40 ) ;
F_30 ( V_12 -> V_7 -> V_41 ) ;
F_31 ( & V_12 -> V_7 -> V_8 , V_40 ) ;
}
T_3
F_32 ( void )
{
T_3 V_15 ;
F_10 ( & V_42 ) ;
V_15 = V_43 ;
F_12 ( & V_42 ) ;
return V_15 ;
}
static int F_33 ( struct V_18 * V_12 , T_3 * V_44 )
{
return 0 ;
}
static void F_34 ( struct V_18 * V_12 , T_3 V_15 )
{
F_10 ( & V_12 -> V_8 ) ;
V_12 -> V_14 &= ~ V_15 ;
V_12 -> V_45 &= ~ V_15 ;
F_12 ( & V_12 -> V_8 ) ;
}
int F_35 ( struct V_18 * V_12 )
{
int V_26 ;
struct V_4 * V_5 ;
if ( ! V_12 )
return - V_19 ;
V_12 -> V_7 = F_36 ( sizeof( * V_12 -> V_7 ) , V_46 ) ;
if ( ! V_12 -> V_7 )
return - V_47 ;
V_12 -> V_7 -> V_12 = V_12 ;
V_12 -> F_33 = F_33 ;
F_37 ( V_12 -> V_7 -> V_9 ) ;
F_38 ( & V_12 -> V_7 -> V_8 ) ;
V_12 -> V_7 -> V_41 = F_39 ( F_1 , V_12 -> V_7 ,
L_7 , V_12 -> V_48 ) ;
if ( F_40 ( V_12 -> V_7 -> V_41 ) ) {
V_26 = F_41 ( V_12 -> V_7 -> V_41 ) ;
goto V_49;
}
F_10 ( & V_13 ) ;
F_42 ( & V_12 -> V_7 -> V_50 , & V_51 ) ;
F_11 (handler, &ir_raw_handler_list, list)
if ( V_5 -> V_52 )
V_5 -> V_52 ( V_12 ) ;
F_12 ( & V_13 ) ;
return 0 ;
V_49:
F_43 ( V_12 -> V_7 ) ;
V_12 -> V_7 = NULL ;
return V_26 ;
}
void F_44 ( struct V_18 * V_12 )
{
struct V_4 * V_5 ;
if ( ! V_12 || ! V_12 -> V_7 )
return;
F_45 ( V_12 -> V_7 -> V_41 ) ;
F_10 ( & V_13 ) ;
F_46 ( & V_12 -> V_7 -> V_50 ) ;
F_11 (handler, &ir_raw_handler_list, list)
if ( V_5 -> V_53 )
V_5 -> V_53 ( V_12 ) ;
F_12 ( & V_13 ) ;
F_43 ( V_12 -> V_7 ) ;
V_12 -> V_7 = NULL ;
}
int F_47 ( struct V_4 * V_4 )
{
struct V_6 * V_7 ;
F_10 ( & V_13 ) ;
F_42 ( & V_4 -> V_50 , & V_54 ) ;
if ( V_4 -> V_52 )
F_11 (raw, &ir_raw_client_list, list)
V_4 -> V_52 ( V_7 -> V_12 ) ;
F_10 ( & V_42 ) ;
V_43 |= V_4 -> V_15 ;
F_12 ( & V_42 ) ;
F_12 ( & V_13 ) ;
return 0 ;
}
void F_48 ( struct V_4 * V_4 )
{
struct V_6 * V_7 ;
T_3 V_15 = V_4 -> V_15 ;
F_10 ( & V_13 ) ;
F_46 ( & V_4 -> V_50 ) ;
F_11 (raw, &ir_raw_client_list, list) {
F_34 ( V_7 -> V_12 , V_15 ) ;
if ( V_4 -> V_53 )
V_4 -> V_53 ( V_7 -> V_12 ) ;
}
F_10 ( & V_42 ) ;
V_43 &= ~ V_15 ;
F_12 ( & V_42 ) ;
F_12 ( & V_13 ) ;
}
