static int F_1 ( void * V_1 )
{
struct V_2 V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
int V_8 ;
while ( ! F_2 () ) {
F_3 ( & V_7 -> V_9 ) ;
V_8 = F_4 ( & V_7 -> V_10 ) ;
if ( V_8 < sizeof( V_3 ) ) {
F_5 ( V_11 ) ;
if ( F_2 () )
F_5 ( V_12 ) ;
F_6 ( & V_7 -> V_9 ) ;
F_7 () ;
continue;
}
V_8 = F_8 ( & V_7 -> V_10 , & V_3 , sizeof( V_3 ) ) ;
F_6 ( & V_7 -> V_9 ) ;
F_9 ( & V_13 ) ;
F_10 (handler, &ir_raw_handler_list, list)
if ( V_7 -> V_14 -> V_15 & V_5 -> V_16 ||
! V_5 -> V_16 )
V_5 -> V_17 ( V_7 -> V_14 , V_3 ) ;
V_7 -> V_18 = V_3 ;
F_11 ( & V_13 ) ;
}
return 0 ;
}
int F_12 ( struct V_19 * V_14 , struct V_2 * V_3 )
{
if ( ! V_14 -> V_7 )
return - V_20 ;
F_13 ( 2 , L_1 ,
F_14 ( V_3 -> V_21 ) , F_15 ( V_3 -> V_22 ) ) ;
if ( F_16 ( & V_14 -> V_7 -> V_10 , V_3 , sizeof( * V_3 ) ) != sizeof( * V_3 ) )
return - V_23 ;
return 0 ;
}
int F_17 ( struct V_19 * V_14 , enum V_24 type )
{
T_1 V_25 ;
T_2 V_26 ;
F_18 ( V_3 ) ;
int V_27 = 0 ;
int V_28 ;
if ( ! V_14 -> V_7 )
return - V_20 ;
V_25 = F_19 () ;
V_26 = F_20 ( F_21 ( V_25 , V_14 -> V_7 -> V_29 ) ) ;
V_28 = F_22 ( V_14 -> V_30 -> V_31 [ V_32 ] ) ;
if ( V_26 > V_28 || ! V_14 -> V_7 -> V_33 )
type |= V_34 ;
else
V_3 . V_21 = V_26 ;
if ( type & V_34 )
F_23 ( V_14 ) ;
else if ( V_14 -> V_7 -> V_33 & V_35 ) {
V_3 . V_22 = false ;
V_27 = F_12 ( V_14 , & V_3 ) ;
} else if ( V_14 -> V_7 -> V_33 & V_36 ) {
V_3 . V_22 = true ;
V_27 = F_12 ( V_14 , & V_3 ) ;
} else
return 0 ;
V_14 -> V_7 -> V_29 = V_25 ;
V_14 -> V_7 -> V_33 = type ;
return V_27 ;
}
int F_24 ( struct V_19 * V_14 , struct V_2 * V_3 )
{
if ( ! V_14 -> V_7 )
return - V_20 ;
if ( V_14 -> V_37 && ! V_3 -> V_22 )
return 0 ;
else if ( V_14 -> V_37 )
F_25 ( V_14 , false ) ;
if ( ! V_14 -> V_7 -> V_38 . V_21 )
V_14 -> V_7 -> V_38 = * V_3 ;
else if ( V_3 -> V_22 == V_14 -> V_7 -> V_38 . V_22 )
V_14 -> V_7 -> V_38 . V_21 += V_3 -> V_21 ;
else {
F_12 ( V_14 , & V_14 -> V_7 -> V_38 ) ;
V_14 -> V_7 -> V_38 = * V_3 ;
}
if ( ! V_3 -> V_22 && V_14 -> V_39 &&
V_14 -> V_7 -> V_38 . V_21 >= V_14 -> V_39 )
F_25 ( V_14 , true ) ;
return 1 ;
}
void F_25 ( struct V_19 * V_14 , bool V_37 )
{
if ( ! V_14 -> V_7 )
return;
F_13 ( 2 , L_2 , V_37 ? L_3 : L_4 ) ;
if ( V_37 ) {
V_14 -> V_7 -> V_38 . V_39 = true ;
F_12 ( V_14 , & V_14 -> V_7 -> V_38 ) ;
F_26 ( & V_14 -> V_7 -> V_38 ) ;
}
if ( V_14 -> V_40 )
V_14 -> V_40 ( V_14 , V_37 ) ;
V_14 -> V_37 = V_37 ;
}
void F_27 ( struct V_19 * V_14 )
{
unsigned long V_41 ;
if ( ! V_14 -> V_7 )
return;
F_28 ( & V_14 -> V_7 -> V_9 , V_41 ) ;
F_29 ( V_14 -> V_7 -> V_42 ) ;
F_30 ( & V_14 -> V_7 -> V_9 , V_41 ) ;
}
T_3
F_31 ( void )
{
T_3 V_16 ;
F_9 ( & V_13 ) ;
V_16 = V_43 ;
F_11 ( & V_13 ) ;
return V_16 ;
}
static int F_32 ( struct V_19 * V_14 , T_3 * V_44 )
{
return 0 ;
}
static void F_33 ( struct V_19 * V_14 , T_3 V_16 )
{
F_9 ( & V_14 -> V_9 ) ;
V_14 -> V_15 &= ~ V_16 ;
V_14 -> V_45 &= ~ V_16 ;
F_11 ( & V_14 -> V_9 ) ;
}
int F_34 ( struct V_19 * V_14 )
{
int V_27 ;
struct V_4 * V_5 ;
if ( ! V_14 )
return - V_20 ;
V_14 -> V_7 = F_35 ( sizeof( * V_14 -> V_7 ) , V_46 ) ;
if ( ! V_14 -> V_7 )
return - V_23 ;
V_14 -> V_7 -> V_14 = V_14 ;
V_14 -> F_32 = F_32 ;
V_27 = F_36 ( & V_14 -> V_7 -> V_10 ,
sizeof( struct V_2 ) * V_47 ,
V_46 ) ;
if ( V_27 < 0 )
goto V_48;
F_37 ( & V_14 -> V_7 -> V_9 ) ;
V_14 -> V_7 -> V_42 = F_38 ( F_1 , V_14 -> V_7 ,
L_5 , V_14 -> V_49 ) ;
if ( F_39 ( V_14 -> V_7 -> V_42 ) ) {
V_27 = F_40 ( V_14 -> V_7 -> V_42 ) ;
goto V_48;
}
F_9 ( & V_13 ) ;
F_41 ( & V_14 -> V_7 -> V_50 , & V_51 ) ;
F_10 (handler, &ir_raw_handler_list, list)
if ( V_5 -> V_52 )
V_5 -> V_52 ( V_14 ) ;
F_11 ( & V_13 ) ;
return 0 ;
V_48:
F_42 ( V_14 -> V_7 ) ;
V_14 -> V_7 = NULL ;
return V_27 ;
}
void F_43 ( struct V_19 * V_14 )
{
struct V_4 * V_5 ;
if ( ! V_14 || ! V_14 -> V_7 )
return;
F_44 ( V_14 -> V_7 -> V_42 ) ;
F_9 ( & V_13 ) ;
F_45 ( & V_14 -> V_7 -> V_50 ) ;
F_10 (handler, &ir_raw_handler_list, list)
if ( V_5 -> V_53 )
V_5 -> V_53 ( V_14 ) ;
F_11 ( & V_13 ) ;
F_46 ( & V_14 -> V_7 -> V_10 ) ;
F_42 ( V_14 -> V_7 ) ;
V_14 -> V_7 = NULL ;
}
int F_47 ( struct V_4 * V_4 )
{
struct V_6 * V_7 ;
F_9 ( & V_13 ) ;
F_41 ( & V_4 -> V_50 , & V_54 ) ;
if ( V_4 -> V_52 )
F_10 (raw, &ir_raw_client_list, list)
V_4 -> V_52 ( V_7 -> V_14 ) ;
V_43 |= V_4 -> V_16 ;
F_11 ( & V_13 ) ;
return 0 ;
}
void F_48 ( struct V_4 * V_4 )
{
struct V_6 * V_7 ;
T_3 V_16 = V_4 -> V_16 ;
F_9 ( & V_13 ) ;
F_45 ( & V_4 -> V_50 ) ;
F_10 (raw, &ir_raw_client_list, list) {
F_33 ( V_7 -> V_14 , V_16 ) ;
if ( V_4 -> V_53 )
V_4 -> V_53 ( V_7 -> V_14 ) ;
}
V_43 &= ~ V_16 ;
F_11 ( & V_13 ) ;
}
