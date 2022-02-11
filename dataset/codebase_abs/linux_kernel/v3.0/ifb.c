static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = & V_3 -> V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_9 = F_3 ( V_3 , 0 ) ;
if ( ( V_11 = F_4 ( & V_5 -> V_12 ) ) == NULL ) {
if ( F_5 ( V_9 ) ) {
F_6 ( & V_5 -> V_13 , & V_5 -> V_12 ) ;
F_7 ( V_9 ) ;
} else {
goto V_14;
}
}
while ( ( V_11 = F_8 ( & V_5 -> V_12 ) ) != NULL ) {
T_1 V_15 = F_9 ( V_11 -> V_16 ) ;
V_11 -> V_16 = 0 ;
V_11 -> V_16 = F_10 ( V_11 -> V_16 ) ;
V_7 -> V_17 ++ ;
V_7 -> V_18 += V_11 -> V_19 ;
F_11 () ;
V_11 -> V_1 = F_12 ( & V_20 , V_11 -> V_21 ) ;
if ( ! V_11 -> V_1 ) {
F_13 () ;
F_14 ( V_11 ) ;
V_7 -> V_22 ++ ;
if ( F_15 ( & V_5 -> V_12 ) != 0 )
goto V_14;
break;
}
F_13 () ;
V_11 -> V_21 = V_3 -> V_23 ;
if ( V_15 & V_24 ) {
F_16 ( V_11 ) ;
} else if ( V_15 & V_25 ) {
F_17 ( V_11 , V_11 -> V_1 -> V_26 ) ;
F_18 ( V_11 ) ;
} else
F_19 () ;
}
if ( F_5 ( V_9 ) ) {
if ( ( V_11 = F_4 ( & V_5 -> V_13 ) ) == NULL ) {
V_5 -> V_27 = 0 ;
if ( F_20 ( V_3 ) )
F_21 ( V_3 ) ;
} else {
F_7 ( V_9 ) ;
goto V_14;
}
F_7 ( V_9 ) ;
} else {
V_14:
V_5 -> V_27 = 1 ;
F_22 ( & V_5 -> V_28 ) ;
}
}
static void F_23 ( struct V_2 * V_1 )
{
V_1 -> V_29 = V_30 ;
V_1 -> V_31 = & V_32 ;
F_24 ( V_1 ) ;
V_1 -> V_33 = V_34 ;
V_1 -> V_35 |= V_36 ;
V_1 -> V_37 |= V_36 ;
V_1 -> V_38 |= V_39 ;
V_1 -> V_38 &= ~ V_40 ;
V_1 -> V_41 &= ~ V_42 ;
F_25 ( V_1 -> V_43 ) ;
}
static T_2 F_26 ( struct V_10 * V_11 , struct V_2 * V_1 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
struct V_6 * V_7 = & V_1 -> V_7 ;
T_1 V_15 = F_9 ( V_11 -> V_16 ) ;
V_7 -> V_44 ++ ;
V_7 -> V_45 += V_11 -> V_19 ;
if ( ! ( V_15 & ( V_25 | V_24 ) ) || ! V_11 -> V_21 ) {
F_14 ( V_11 ) ;
V_7 -> V_46 ++ ;
return V_47 ;
}
if ( F_15 ( & V_5 -> V_13 ) >= V_1 -> V_33 ) {
F_27 ( V_1 ) ;
}
F_28 ( & V_5 -> V_13 , V_11 ) ;
if ( ! V_5 -> V_27 ) {
V_5 -> V_27 = 1 ;
F_22 ( & V_5 -> V_28 ) ;
}
return V_47 ;
}
static int F_29 ( struct V_2 * V_1 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
F_30 ( & V_5 -> V_28 ) ;
F_27 ( V_1 ) ;
F_31 ( & V_5 -> V_13 ) ;
F_31 ( & V_5 -> V_12 ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_1 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
F_33 ( & V_5 -> V_28 , F_1 , ( unsigned long ) V_1 ) ;
F_34 ( & V_5 -> V_13 ) ;
F_34 ( & V_5 -> V_12 ) ;
F_35 ( V_1 ) ;
return 0 ;
}
static int F_36 ( struct V_48 * V_49 [] , struct V_48 * V_50 [] )
{
if ( V_49 [ V_51 ] ) {
if ( F_37 ( V_49 [ V_51 ] ) != V_52 )
return - V_53 ;
if ( ! F_38 ( F_39 ( V_49 [ V_51 ] ) ) )
return - V_54 ;
}
return 0 ;
}
static int T_3 F_40 ( int V_55 )
{
struct V_2 * V_56 ;
int V_57 ;
V_56 = F_41 ( sizeof( struct V_4 ) ,
L_1 , F_23 ) ;
if ( ! V_56 )
return - V_58 ;
V_56 -> V_59 = & V_60 ;
V_57 = F_42 ( V_56 ) ;
if ( V_57 < 0 )
goto V_57;
return 0 ;
V_57:
V_30 ( V_56 ) ;
return V_57 ;
}
static int T_3 F_43 ( void )
{
int V_61 , V_57 ;
F_44 () ;
V_57 = F_45 ( & V_60 ) ;
for ( V_61 = 0 ; V_61 < V_62 && ! V_57 ; V_61 ++ )
V_57 = F_40 ( V_61 ) ;
if ( V_57 )
F_46 ( & V_60 ) ;
F_47 () ;
return V_57 ;
}
static void T_4 F_48 ( void )
{
F_49 ( & V_60 ) ;
}
