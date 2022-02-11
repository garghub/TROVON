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
V_5 -> V_14 ( V_7 -> V_15 , V_3 ) ;
V_7 -> V_16 = V_3 ;
F_11 ( & V_13 ) ;
}
return 0 ;
}
int F_12 ( struct V_17 * V_15 , struct V_2 * V_3 )
{
if ( ! V_15 -> V_7 )
return - V_18 ;
F_13 ( 2 , L_1 ,
F_14 ( V_3 -> V_19 ) , F_15 ( V_3 -> V_20 ) ) ;
if ( F_16 ( & V_15 -> V_7 -> V_10 , V_3 , sizeof( * V_3 ) ) != sizeof( * V_3 ) )
return - V_21 ;
return 0 ;
}
int F_17 ( struct V_17 * V_15 , enum V_22 type )
{
T_1 V_23 ;
T_2 V_24 ;
F_18 ( V_3 ) ;
int V_25 = 0 ;
int V_26 ;
if ( ! V_15 -> V_7 )
return - V_18 ;
V_23 = F_19 () ;
V_24 = F_20 ( F_21 ( V_23 , V_15 -> V_7 -> V_27 ) ) ;
V_26 = F_22 ( V_15 -> V_28 -> V_29 [ V_30 ] ) ;
if ( V_24 > V_26 || ! V_15 -> V_7 -> V_31 )
type |= V_32 ;
else
V_3 . V_19 = V_24 ;
if ( type & V_32 )
F_23 ( V_15 ) ;
else if ( V_15 -> V_7 -> V_31 & V_33 ) {
V_3 . V_20 = false ;
V_25 = F_12 ( V_15 , & V_3 ) ;
} else if ( V_15 -> V_7 -> V_31 & V_34 ) {
V_3 . V_20 = true ;
V_25 = F_12 ( V_15 , & V_3 ) ;
} else
return 0 ;
V_15 -> V_7 -> V_27 = V_23 ;
V_15 -> V_7 -> V_31 = type ;
return V_25 ;
}
int F_24 ( struct V_17 * V_15 , struct V_2 * V_3 )
{
if ( ! V_15 -> V_7 )
return - V_18 ;
if ( V_15 -> V_35 && ! V_3 -> V_20 )
return 0 ;
else if ( V_15 -> V_35 )
F_25 ( V_15 , false ) ;
if ( ! V_15 -> V_7 -> V_36 . V_19 )
V_15 -> V_7 -> V_36 = * V_3 ;
else if ( V_3 -> V_20 == V_15 -> V_7 -> V_36 . V_20 )
V_15 -> V_7 -> V_36 . V_19 += V_3 -> V_19 ;
else {
F_12 ( V_15 , & V_15 -> V_7 -> V_36 ) ;
V_15 -> V_7 -> V_36 = * V_3 ;
}
if ( ! V_3 -> V_20 && V_15 -> V_37 &&
V_15 -> V_7 -> V_36 . V_19 >= V_15 -> V_37 )
F_25 ( V_15 , true ) ;
return 1 ;
}
void F_25 ( struct V_17 * V_15 , bool V_35 )
{
if ( ! V_15 -> V_7 )
return;
F_13 ( 2 , L_2 , V_35 ? L_3 : L_4 ) ;
if ( V_35 ) {
V_15 -> V_7 -> V_36 . V_37 = true ;
F_12 ( V_15 , & V_15 -> V_7 -> V_36 ) ;
F_26 ( & V_15 -> V_7 -> V_36 ) ;
}
if ( V_15 -> V_38 )
V_15 -> V_38 ( V_15 , V_35 ) ;
V_15 -> V_35 = V_35 ;
}
void F_27 ( struct V_17 * V_15 )
{
unsigned long V_39 ;
if ( ! V_15 -> V_7 )
return;
F_28 ( & V_15 -> V_7 -> V_9 , V_39 ) ;
F_29 ( V_15 -> V_7 -> V_40 ) ;
F_30 ( & V_15 -> V_7 -> V_9 , V_39 ) ;
}
T_3
F_31 ( void )
{
T_3 V_41 ;
F_9 ( & V_13 ) ;
V_41 = V_42 ;
F_11 ( & V_13 ) ;
return V_41 ;
}
int F_32 ( struct V_17 * V_15 )
{
int V_25 ;
struct V_4 * V_5 ;
if ( ! V_15 )
return - V_18 ;
V_15 -> V_7 = F_33 ( sizeof( * V_15 -> V_7 ) , V_43 ) ;
if ( ! V_15 -> V_7 )
return - V_21 ;
V_15 -> V_7 -> V_15 = V_15 ;
F_34 ( V_15 , ~ 0 ) ;
V_25 = F_35 ( & V_15 -> V_7 -> V_10 ,
sizeof( struct V_2 ) * V_44 ,
V_43 ) ;
if ( V_25 < 0 )
goto V_45;
F_36 ( & V_15 -> V_7 -> V_9 ) ;
V_15 -> V_7 -> V_40 = F_37 ( F_1 , V_15 -> V_7 ,
L_5 , V_15 -> V_46 ) ;
if ( F_38 ( V_15 -> V_7 -> V_40 ) ) {
V_25 = F_39 ( V_15 -> V_7 -> V_40 ) ;
goto V_45;
}
F_9 ( & V_13 ) ;
F_40 ( & V_15 -> V_7 -> V_47 , & V_48 ) ;
F_10 (handler, &ir_raw_handler_list, list)
if ( V_5 -> V_49 )
V_5 -> V_49 ( V_15 ) ;
F_11 ( & V_13 ) ;
return 0 ;
V_45:
F_41 ( V_15 -> V_7 ) ;
V_15 -> V_7 = NULL ;
return V_25 ;
}
void F_42 ( struct V_17 * V_15 )
{
struct V_4 * V_5 ;
if ( ! V_15 || ! V_15 -> V_7 )
return;
F_43 ( V_15 -> V_7 -> V_40 ) ;
F_9 ( & V_13 ) ;
F_44 ( & V_15 -> V_7 -> V_47 ) ;
F_10 (handler, &ir_raw_handler_list, list)
if ( V_5 -> V_50 )
V_5 -> V_50 ( V_15 ) ;
F_11 ( & V_13 ) ;
F_45 ( & V_15 -> V_7 -> V_10 ) ;
F_41 ( V_15 -> V_7 ) ;
V_15 -> V_7 = NULL ;
}
int F_46 ( struct V_4 * V_4 )
{
struct V_6 * V_7 ;
F_9 ( & V_13 ) ;
F_40 ( & V_4 -> V_47 , & V_51 ) ;
if ( V_4 -> V_49 )
F_10 (raw, &ir_raw_client_list, list)
V_4 -> V_49 ( V_7 -> V_15 ) ;
V_42 |= V_4 -> V_41 ;
F_11 ( & V_13 ) ;
return 0 ;
}
void F_47 ( struct V_4 * V_4 )
{
struct V_6 * V_7 ;
F_9 ( & V_13 ) ;
F_44 ( & V_4 -> V_47 ) ;
if ( V_4 -> V_50 )
F_10 (raw, &ir_raw_client_list, list)
V_4 -> V_50 ( V_7 -> V_15 ) ;
V_42 &= ~ V_4 -> V_41 ;
F_11 ( & V_13 ) ;
}
void F_48 ( void )
{
F_49 () ;
F_50 () ;
F_51 () ;
F_52 () ;
F_53 () ;
F_54 () ;
F_55 () ;
F_56 () ;
F_57 () ;
}
