int F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 >= V_4 )
goto V_5;
F_2 ( & V_6 ) ;
if ( V_7 [ V_3 ] )
goto V_8;
F_3 ( V_7 [ V_3 ] , V_2 ) ;
F_4 ( & V_6 ) ;
return 0 ;
V_8:
F_4 ( & V_6 ) ;
V_5:
return - 1 ;
}
int F_5 ( const struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 >= V_4 )
goto V_5;
F_2 ( & V_6 ) ;
if ( F_6 ( V_7 [ V_3 ] ,
F_7 ( & V_6 ) ) != V_2 )
goto V_8;
F_3 ( V_7 [ V_3 ] , NULL ) ;
F_4 ( & V_6 ) ;
F_8 () ;
return 0 ;
V_8:
F_4 ( & V_6 ) ;
V_5:
return - 1 ;
}
static int F_9 ( struct V_9 * V_10 )
{
const struct V_1 * V_2 ;
T_1 V_11 ;
int V_12 ;
if ( ! F_10 ( V_10 , 12 ) )
goto V_13;
V_11 = V_10 -> V_14 [ 1 ] & 0x7f ;
if ( V_11 >= V_4 )
goto V_13;
F_11 () ;
V_2 = F_12 ( V_7 [ V_11 ] ) ;
if ( ! V_2 || ! V_2 -> V_15 )
goto V_16;
V_12 = V_2 -> V_15 ( V_10 ) ;
F_13 () ;
return V_12 ;
V_16:
F_13 () ;
V_13:
F_14 ( V_10 ) ;
return V_17 ;
}
static void F_15 ( struct V_9 * V_10 , T_2 V_18 )
{
const struct V_1 * V_2 ;
const struct V_19 * V_20 = ( const struct V_19 * ) V_10 -> V_14 ;
T_1 V_11 = V_10 -> V_14 [ ( V_20 -> V_21 << 2 ) + 1 ] & 0x7f ;
if ( V_11 >= V_4 )
return;
F_11 () ;
V_2 = F_12 ( V_7 [ V_11 ] ) ;
if ( V_2 && V_2 -> V_22 )
V_2 -> V_22 ( V_10 , V_18 ) ;
F_13 () ;
}
static struct V_9 * F_16 ( struct V_9 * V_10 ,
T_3 V_23 )
{
struct V_9 * V_24 = F_17 ( - V_25 ) ;
T_3 V_26 ;
int V_27 = V_28 ;
struct V_29 * V_30 ;
int V_31 = V_10 -> V_31 ;
T_4 V_32 = V_10 -> V_32 ;
int V_33 ;
bool V_34 ;
if ( F_18 ( F_19 ( V_10 ) -> V_35 &
~ ( V_36 |
V_37 |
V_38 |
V_39 |
V_40 |
V_41 ) ) )
goto V_42;
if ( F_18 ( ! F_10 ( V_10 , sizeof( * V_30 ) ) ) )
goto V_42;
V_30 = (struct V_29 * ) F_20 ( V_10 ) ;
if ( V_30 -> V_43 & V_44 )
V_27 += V_28 ;
if ( V_30 -> V_43 & V_45 )
V_27 += V_28 ;
if ( V_30 -> V_43 & V_46 ) {
V_27 += V_28 ;
V_34 = true ;
} else
V_34 = false ;
V_10 -> V_32 = V_30 -> V_32 ;
V_10 -> V_47 = 0 ;
if ( F_18 ( ! F_10 ( V_10 , V_27 ) ) )
goto V_42;
F_21 ( V_10 , V_27 ) ;
F_22 ( V_10 ) ;
F_23 ( V_10 , F_24 ( V_10 ) ) ;
V_10 -> V_31 = F_24 ( V_10 ) ;
V_26 = V_10 -> V_48 -> V_49 & F_25 ( V_10 ) ;
V_24 = F_26 ( V_10 , V_26 ) ;
if ( ! V_24 || F_27 ( V_24 ) )
goto V_42;
V_10 = V_24 ;
V_33 = F_28 ( V_10 ) ;
do {
F_29 ( V_10 , V_27 ) ;
if ( V_34 ) {
T_5 * V_50 ;
if ( F_30 ( V_10 ) ) {
int V_51 ;
V_51 = F_31 ( V_10 ) ;
if ( V_51 ) {
F_32 ( V_24 ) ;
V_24 = F_17 ( V_51 ) ;
goto V_42;
}
}
V_30 = (struct V_29 * ) ( V_10 -> V_14 ) ;
V_50 = ( T_5 * ) ( V_30 + 1 ) ;
* V_50 = 0 ;
* ( V_52 * ) V_50 = F_33 ( F_34 ( V_10 , 0 , V_10 -> V_53 , 0 ) ) ;
}
F_29 ( V_10 , V_33 - V_27 ) ;
F_22 ( V_10 ) ;
F_23 ( V_10 , V_31 ) ;
V_10 -> V_31 = V_31 ;
V_10 -> V_32 = V_32 ;
} while ( ( V_10 = V_10 -> V_54 ) );
V_42:
return V_24 ;
}
static int F_35 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_47 )
return - V_25 ;
return 0 ;
}
static int T_6 F_36 ( void )
{
F_37 ( L_1 ) ;
if ( F_38 ( & V_55 , V_56 ) < 0 ) {
F_39 ( L_2 ) ;
return - V_57 ;
}
if ( F_40 ( & V_58 , V_56 ) ) {
F_39 ( L_3 ) ;
F_41 ( & V_55 , V_56 ) ;
return - V_57 ;
}
return 0 ;
}
static void T_7 F_42 ( void )
{
F_43 ( & V_58 , V_56 ) ;
F_41 ( & V_55 , V_56 ) ;
}
