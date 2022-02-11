static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_5 = F_2 ( V_3 -> V_8 , V_3 -> V_9 ) ;
V_7 = F_3 ( & V_3 -> V_10 ) ;
if ( ! V_7 ) {
if ( ! F_4 ( V_5 ) )
goto V_11;
F_5 ( & V_3 -> V_12 , & V_3 -> V_10 ) ;
F_6 ( V_5 ) ;
}
while ( ( V_7 = F_7 ( & V_3 -> V_10 ) ) != NULL ) {
T_1 V_13 = F_8 ( V_7 -> V_14 ) ;
V_7 -> V_14 = 0 ;
V_7 -> V_14 = F_9 ( V_7 -> V_14 ) ;
F_10 ( & V_3 -> V_15 ) ;
V_3 -> V_16 ++ ;
V_3 -> V_17 += V_7 -> V_18 ;
F_11 ( & V_3 -> V_15 ) ;
F_12 () ;
V_7 -> V_8 = F_13 ( F_14 ( V_3 -> V_8 ) , V_7 -> V_19 ) ;
if ( ! V_7 -> V_8 ) {
F_15 () ;
F_16 ( V_7 ) ;
V_3 -> V_8 -> V_20 . V_21 ++ ;
if ( F_17 ( & V_3 -> V_10 ) != 0 )
goto V_11;
break;
}
F_15 () ;
V_7 -> V_19 = V_3 -> V_8 -> V_22 ;
if ( V_13 & V_23 ) {
F_18 ( V_7 ) ;
} else if ( V_13 & V_24 ) {
F_19 ( V_7 , V_7 -> V_25 ) ;
F_20 ( V_7 ) ;
} else
F_21 () ;
}
if ( F_4 ( V_5 ) ) {
V_7 = F_3 ( & V_3 -> V_12 ) ;
if ( ! V_7 ) {
V_3 -> V_26 = 0 ;
if ( F_22 ( V_5 ) )
F_23 ( V_5 ) ;
} else {
F_6 ( V_5 ) ;
goto V_11;
}
F_6 ( V_5 ) ;
} else {
V_11:
V_3 -> V_26 = 1 ;
F_24 ( & V_3 -> V_27 ) ;
}
}
static struct V_28 * F_25 ( struct V_29 * V_8 ,
struct V_28 * V_20 )
{
struct V_30 * V_31 = F_26 ( V_8 ) ;
struct V_2 * V_3 = V_31 -> V_32 ;
unsigned int V_33 ;
T_2 V_34 , V_35 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_37 ; V_36 ++ , V_3 ++ ) {
do {
V_33 = F_27 ( & V_3 -> V_38 ) ;
V_34 = V_3 -> V_39 ;
V_35 = V_3 -> V_40 ;
} while ( F_28 ( & V_3 -> V_38 , V_33 ) );
V_20 -> V_39 += V_34 ;
V_20 -> V_40 += V_35 ;
do {
V_33 = F_27 ( & V_3 -> V_15 ) ;
V_34 = V_3 -> V_16 ;
V_35 = V_3 -> V_17 ;
} while ( F_28 ( & V_3 -> V_15 , V_33 ) );
V_20 -> V_16 += V_34 ;
V_20 -> V_17 += V_35 ;
}
V_20 -> V_41 = V_8 -> V_20 . V_41 ;
V_20 -> V_21 = V_8 -> V_20 . V_21 ;
return V_20 ;
}
static int F_29 ( struct V_29 * V_8 )
{
struct V_30 * V_31 = F_26 ( V_8 ) ;
struct V_2 * V_3 ;
int V_36 ;
V_3 = F_30 ( V_8 -> V_37 , sizeof( * V_3 ) , V_42 ) ;
if ( ! V_3 )
return - V_43 ;
V_31 -> V_32 = V_3 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_37 ; V_36 ++ , V_3 ++ ) {
V_3 -> V_9 = V_36 ;
V_3 -> V_8 = V_8 ;
F_31 ( & V_3 -> V_12 ) ;
F_31 ( & V_3 -> V_10 ) ;
F_32 ( & V_3 -> V_38 ) ;
F_32 ( & V_3 -> V_15 ) ;
F_33 ( & V_3 -> V_27 , F_1 ,
( unsigned long ) V_3 ) ;
F_34 ( F_2 ( V_8 , V_36 ) ) ;
}
return 0 ;
}
static void F_35 ( struct V_29 * V_8 )
{
struct V_30 * V_31 = F_26 ( V_8 ) ;
struct V_2 * V_3 = V_31 -> V_32 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_37 ; V_36 ++ , V_3 ++ ) {
F_36 ( & V_3 -> V_27 ) ;
F_37 ( & V_3 -> V_12 ) ;
F_37 ( & V_3 -> V_10 ) ;
}
F_38 ( V_31 -> V_32 ) ;
F_39 ( V_8 ) ;
}
static void F_40 ( struct V_29 * V_8 )
{
V_8 -> V_44 = & V_45 ;
F_41 ( V_8 ) ;
V_8 -> V_46 = V_47 ;
V_8 -> V_48 |= V_49 ;
V_8 -> V_50 |= V_8 -> V_48 ;
V_8 -> V_51 |= V_8 -> V_48 ;
V_8 -> V_52 |= V_49 & ~ ( V_53 |
V_54 ) ;
V_8 -> V_55 |= V_56 ;
V_8 -> V_55 &= ~ V_57 ;
V_8 -> V_58 &= ~ V_59 ;
F_42 ( V_8 ) ;
F_43 ( V_8 ) ;
V_8 -> V_60 = F_35 ;
}
static T_3 F_44 ( struct V_6 * V_7 , struct V_29 * V_8 )
{
struct V_30 * V_31 = F_26 ( V_8 ) ;
T_1 V_13 = F_8 ( V_7 -> V_14 ) ;
struct V_2 * V_3 = V_31 -> V_32 + F_45 ( V_7 ) ;
F_10 ( & V_3 -> V_38 ) ;
V_3 -> V_39 ++ ;
V_3 -> V_40 += V_7 -> V_18 ;
F_11 ( & V_3 -> V_38 ) ;
if ( ! ( V_13 & ( V_24 | V_23 ) ) || ! V_7 -> V_19 ) {
F_16 ( V_7 ) ;
V_8 -> V_20 . V_41 ++ ;
return V_61 ;
}
if ( F_17 ( & V_3 -> V_12 ) >= V_8 -> V_46 )
F_46 ( F_2 ( V_8 , V_3 -> V_9 ) ) ;
F_47 ( & V_3 -> V_12 , V_7 ) ;
if ( ! V_3 -> V_26 ) {
V_3 -> V_26 = 1 ;
F_24 ( & V_3 -> V_27 ) ;
}
return V_61 ;
}
static int F_48 ( struct V_29 * V_8 )
{
F_49 ( V_8 ) ;
return 0 ;
}
static int F_50 ( struct V_29 * V_8 )
{
F_51 ( V_8 ) ;
return 0 ;
}
static int F_52 ( struct V_62 * V_63 [] , struct V_62 * V_64 [] )
{
if ( V_63 [ V_65 ] ) {
if ( F_53 ( V_63 [ V_65 ] ) != V_66 )
return - V_67 ;
if ( ! F_54 ( F_55 ( V_63 [ V_65 ] ) ) )
return - V_68 ;
}
return 0 ;
}
static int T_4 F_56 ( int V_69 )
{
struct V_29 * V_70 ;
int V_71 ;
V_70 = F_57 ( sizeof( struct V_30 ) , L_1 ,
V_72 , F_40 ) ;
if ( ! V_70 )
return - V_43 ;
V_70 -> V_73 = & V_74 ;
V_71 = F_58 ( V_70 ) ;
if ( V_71 < 0 )
goto V_71;
return 0 ;
V_71:
F_39 ( V_70 ) ;
return V_71 ;
}
static int T_4 F_59 ( void )
{
int V_36 , V_71 ;
F_60 () ;
V_71 = F_61 ( & V_74 ) ;
if ( V_71 < 0 )
goto V_75;
for ( V_36 = 0 ; V_36 < V_76 && ! V_71 ; V_36 ++ ) {
V_71 = F_56 ( V_36 ) ;
F_62 () ;
}
if ( V_71 )
F_63 ( & V_74 ) ;
V_75:
F_64 () ;
return V_71 ;
}
static void T_5 F_65 ( void )
{
F_66 ( & V_74 ) ;
}
