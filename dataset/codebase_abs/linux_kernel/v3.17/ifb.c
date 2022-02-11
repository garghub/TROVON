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
V_9 -> V_1 = F_14 ( F_15 ( V_3 ) , V_9 -> V_19 ) ;
if ( ! V_9 -> V_1 ) {
F_16 () ;
F_17 ( V_9 ) ;
V_3 -> V_20 . V_21 ++ ;
if ( F_18 ( & V_5 -> V_10 ) != 0 )
goto V_12;
break;
}
F_16 () ;
V_9 -> V_19 = V_3 -> V_22 ;
if ( V_13 & V_23 ) {
F_19 ( V_9 ) ;
} else if ( V_13 & V_24 ) {
F_20 ( V_9 , V_9 -> V_1 -> V_25 ) ;
F_21 ( V_9 ) ;
} else
F_22 () ;
}
if ( F_5 ( V_7 ) ) {
if ( ( V_9 = F_4 ( & V_5 -> V_11 ) ) == NULL ) {
V_5 -> V_26 = 0 ;
if ( F_23 ( V_3 ) )
F_24 ( V_3 ) ;
} else {
F_7 ( V_7 ) ;
goto V_12;
}
F_7 ( V_7 ) ;
} else {
V_12:
V_5 -> V_26 = 1 ;
F_25 ( & V_5 -> V_27 ) ;
}
}
static struct V_28 * F_26 ( struct V_2 * V_1 ,
struct V_28 * V_20 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
unsigned int V_29 ;
do {
V_29 = F_27 ( & V_5 -> V_30 ) ;
V_20 -> V_31 = V_5 -> V_31 ;
V_20 -> V_32 = V_5 -> V_32 ;
} while ( F_28 ( & V_5 -> V_30 , V_29 ) );
do {
V_29 = F_27 ( & V_5 -> V_15 ) ;
V_20 -> V_16 = V_5 -> V_16 ;
V_20 -> V_17 = V_5 -> V_17 ;
} while ( F_28 ( & V_5 -> V_15 , V_29 ) );
V_20 -> V_33 = V_1 -> V_20 . V_33 ;
V_20 -> V_21 = V_1 -> V_20 . V_21 ;
return V_20 ;
}
static void F_29 ( struct V_2 * V_1 )
{
V_1 -> V_34 = V_35 ;
V_1 -> V_36 = & V_37 ;
F_30 ( V_1 ) ;
V_1 -> V_38 = V_39 ;
V_1 -> V_40 |= V_41 ;
V_1 -> V_42 |= V_41 & ~ ( V_43 |
V_44 ) ;
V_1 -> V_45 |= V_46 ;
V_1 -> V_45 &= ~ V_47 ;
V_1 -> V_48 &= ~ ( V_49 | V_50 ) ;
F_31 ( V_1 ) ;
}
static T_2 F_32 ( struct V_8 * V_9 , struct V_2 * V_1 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
T_1 V_13 = F_9 ( V_9 -> V_14 ) ;
F_11 ( & V_5 -> V_30 ) ;
V_5 -> V_31 ++ ;
V_5 -> V_32 += V_9 -> V_18 ;
F_12 ( & V_5 -> V_30 ) ;
if ( ! ( V_13 & ( V_24 | V_23 ) ) || ! V_9 -> V_19 ) {
F_17 ( V_9 ) ;
V_1 -> V_20 . V_33 ++ ;
return V_51 ;
}
if ( F_18 ( & V_5 -> V_11 ) >= V_1 -> V_38 ) {
F_33 ( V_1 ) ;
}
F_34 ( & V_5 -> V_11 , V_9 ) ;
if ( ! V_5 -> V_26 ) {
V_5 -> V_26 = 1 ;
F_25 ( & V_5 -> V_27 ) ;
}
return V_51 ;
}
static int F_35 ( struct V_2 * V_1 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
F_36 ( & V_5 -> V_27 ) ;
F_33 ( V_1 ) ;
F_37 ( & V_5 -> V_11 ) ;
F_37 ( & V_5 -> V_10 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_1 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
F_39 ( & V_5 -> V_27 , F_1 , ( unsigned long ) V_1 ) ;
F_40 ( & V_5 -> V_11 ) ;
F_40 ( & V_5 -> V_10 ) ;
F_41 ( V_1 ) ;
return 0 ;
}
static int F_42 ( struct V_52 * V_53 [] , struct V_52 * V_54 [] )
{
if ( V_53 [ V_55 ] ) {
if ( F_43 ( V_53 [ V_55 ] ) != V_56 )
return - V_57 ;
if ( ! F_44 ( F_45 ( V_53 [ V_55 ] ) ) )
return - V_58 ;
}
return 0 ;
}
static int T_3 F_46 ( int V_59 )
{
struct V_2 * V_60 ;
struct V_4 * V_5 ;
int V_61 ;
V_60 = F_47 ( sizeof( struct V_4 ) , L_1 ,
V_62 , F_29 ) ;
if ( ! V_60 )
return - V_63 ;
V_5 = F_2 ( V_60 ) ;
F_48 ( & V_5 -> V_30 ) ;
F_48 ( & V_5 -> V_15 ) ;
V_60 -> V_64 = & V_65 ;
V_61 = F_49 ( V_60 ) ;
if ( V_61 < 0 )
goto V_61;
return 0 ;
V_61:
V_35 ( V_60 ) ;
return V_61 ;
}
static int T_3 F_50 ( void )
{
int V_66 , V_61 ;
F_51 () ;
V_61 = F_52 ( & V_65 ) ;
if ( V_61 < 0 )
goto V_67;
for ( V_66 = 0 ; V_66 < V_68 && ! V_61 ; V_66 ++ ) {
V_61 = F_46 ( V_66 ) ;
F_53 () ;
}
if ( V_61 )
F_54 ( & V_65 ) ;
V_67:
F_55 () ;
return V_61 ;
}
static void T_4 F_56 ( void )
{
F_57 ( & V_65 ) ;
}
