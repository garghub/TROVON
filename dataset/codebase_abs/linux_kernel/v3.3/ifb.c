static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_3 ( V_3 , 0 ) ;
if ( ( V_9 = F_4 ( & V_5 -> V_10 ) ) == NULL ) {
if ( F_5 ( V_7 ) ) {
F_6 ( & V_5 -> V_11 , & V_5 -> V_10 ) ;
F_7 ( V_7 ) ;
} else {
goto V_12;
}
}
while ( ( V_9 = F_8 ( & V_5 -> V_10 ) ) != NULL ) {
T_1 V_13 = F_9 ( V_9 -> V_14 ) ;
V_9 -> V_14 = 0 ;
V_9 -> V_14 = F_10 ( V_9 -> V_14 ) ;
F_11 ( & V_5 -> V_15 ) ;
V_5 -> V_16 ++ ;
V_5 -> V_17 += V_9 -> V_18 ;
F_12 ( & V_5 -> V_15 ) ;
F_13 () ;
V_9 -> V_1 = F_14 ( & V_19 , V_9 -> V_20 ) ;
if ( ! V_9 -> V_1 ) {
F_15 () ;
F_16 ( V_9 ) ;
V_3 -> V_21 . V_22 ++ ;
if ( F_17 ( & V_5 -> V_10 ) != 0 )
goto V_12;
break;
}
F_15 () ;
V_9 -> V_20 = V_3 -> V_23 ;
if ( V_13 & V_24 ) {
F_18 ( V_9 ) ;
} else if ( V_13 & V_25 ) {
F_19 ( V_9 , V_9 -> V_1 -> V_26 ) ;
F_20 ( V_9 ) ;
} else
F_21 () ;
}
if ( F_5 ( V_7 ) ) {
if ( ( V_9 = F_4 ( & V_5 -> V_11 ) ) == NULL ) {
V_5 -> V_27 = 0 ;
if ( F_22 ( V_3 ) )
F_23 ( V_3 ) ;
} else {
F_7 ( V_7 ) ;
goto V_12;
}
F_7 ( V_7 ) ;
} else {
V_12:
V_5 -> V_27 = 1 ;
F_24 ( & V_5 -> V_28 ) ;
}
}
static struct V_29 * F_25 ( struct V_2 * V_1 ,
struct V_29 * V_21 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
unsigned int V_30 ;
do {
V_30 = F_26 ( & V_5 -> V_31 ) ;
V_21 -> V_32 = V_5 -> V_32 ;
V_21 -> V_33 = V_5 -> V_33 ;
} while ( F_27 ( & V_5 -> V_31 , V_30 ) );
do {
V_30 = F_26 ( & V_5 -> V_15 ) ;
V_21 -> V_16 = V_5 -> V_16 ;
V_21 -> V_17 = V_5 -> V_17 ;
} while ( F_27 ( & V_5 -> V_15 , V_30 ) );
V_21 -> V_34 = V_1 -> V_21 . V_34 ;
V_21 -> V_22 = V_1 -> V_21 . V_22 ;
return V_21 ;
}
static void F_28 ( struct V_2 * V_1 )
{
V_1 -> V_35 = V_36 ;
V_1 -> V_37 = & V_38 ;
F_29 ( V_1 ) ;
V_1 -> V_39 = V_40 ;
V_1 -> V_41 |= V_42 ;
V_1 -> V_43 |= V_42 ;
V_1 -> V_44 |= V_45 ;
V_1 -> V_44 &= ~ V_46 ;
V_1 -> V_47 &= ~ ( V_48 | V_49 ) ;
F_30 ( V_1 -> V_50 ) ;
}
static T_2 F_31 ( struct V_8 * V_9 , struct V_2 * V_1 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
T_1 V_13 = F_9 ( V_9 -> V_14 ) ;
F_11 ( & V_5 -> V_31 ) ;
V_5 -> V_32 ++ ;
V_5 -> V_33 += V_9 -> V_18 ;
F_12 ( & V_5 -> V_31 ) ;
if ( ! ( V_13 & ( V_25 | V_24 ) ) || ! V_9 -> V_20 ) {
F_16 ( V_9 ) ;
V_1 -> V_21 . V_34 ++ ;
return V_51 ;
}
if ( F_17 ( & V_5 -> V_11 ) >= V_1 -> V_39 ) {
F_32 ( V_1 ) ;
}
F_33 ( & V_5 -> V_11 , V_9 ) ;
if ( ! V_5 -> V_27 ) {
V_5 -> V_27 = 1 ;
F_24 ( & V_5 -> V_28 ) ;
}
return V_51 ;
}
static int F_34 ( struct V_2 * V_1 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
F_35 ( & V_5 -> V_28 ) ;
F_32 ( V_1 ) ;
F_36 ( & V_5 -> V_11 ) ;
F_36 ( & V_5 -> V_10 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_1 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
F_38 ( & V_5 -> V_28 , F_1 , ( unsigned long ) V_1 ) ;
F_39 ( & V_5 -> V_11 ) ;
F_39 ( & V_5 -> V_10 ) ;
F_40 ( V_1 ) ;
return 0 ;
}
static int F_41 ( struct V_52 * V_53 [] , struct V_52 * V_54 [] )
{
if ( V_53 [ V_55 ] ) {
if ( F_42 ( V_53 [ V_55 ] ) != V_56 )
return - V_57 ;
if ( ! F_43 ( F_44 ( V_53 [ V_55 ] ) ) )
return - V_58 ;
}
return 0 ;
}
static int T_3 F_45 ( int V_59 )
{
struct V_2 * V_60 ;
int V_61 ;
V_60 = F_46 ( sizeof( struct V_4 ) ,
L_1 , F_28 ) ;
if ( ! V_60 )
return - V_62 ;
V_60 -> V_63 = & V_64 ;
V_61 = F_47 ( V_60 ) ;
if ( V_61 < 0 )
goto V_61;
return 0 ;
V_61:
V_36 ( V_60 ) ;
return V_61 ;
}
static int T_3 F_48 ( void )
{
int V_65 , V_61 ;
F_49 () ;
V_61 = F_50 ( & V_64 ) ;
for ( V_65 = 0 ; V_65 < V_66 && ! V_61 ; V_65 ++ )
V_61 = F_45 ( V_65 ) ;
if ( V_61 )
F_51 ( & V_64 ) ;
F_52 () ;
return V_61 ;
}
static void T_4 F_53 ( void )
{
F_54 ( & V_64 ) ;
}
