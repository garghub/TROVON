static struct V_1 * F_1 ( struct V_2 * V_3 )
{
#ifdef F_2
const struct V_4 * V_5 ;
V_5 = F_3 ( V_6 , V_3 -> V_7 . V_8 ) ;
if ( V_5 && V_5 -> V_9 )
return (struct V_1 * ) V_5 -> V_9 ;
#endif
return 0 ;
}
static struct V_1 * F_4 ( struct V_2 * V_3 )
{
#ifdef F_5
const struct V_10 * V_5 ;
V_5 = F_6 ( V_11 , & V_3 -> V_7 ) ;
if ( V_5 && V_5 -> V_12 )
return (struct V_1 * ) V_5 -> V_12 ;
#endif
return 0 ;
}
static int F_7 ( struct V_13 * V_14 )
{
struct V_15 * V_7 = V_14 -> V_7 ;
struct V_2 * V_3 = F_8 ( V_7 ) ;
int V_16 ;
V_16 = F_9 ( V_3 , 0 ) ;
if ( V_16 < 0 )
return V_16 ;
V_14 -> V_17 = V_16 ;
V_16 = F_10 ( V_14 -> V_17 , V_14 -> V_18 -> V_19 -> V_20 , 0 ,
V_14 -> V_21 , V_7 ) ;
if ( V_16 ) {
F_11 ( V_7 , L_1 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_12 ( struct V_13 * V_14 )
{
struct V_15 * V_7 = V_14 -> V_7 ;
int V_16 ;
V_16 = F_7 ( V_14 ) ;
if ( ! V_16 )
return 0 ;
F_11 ( V_7 , L_2 , V_16 ) ;
return V_16 ;
}
static void F_13 ( struct V_13 * V_14 )
{
struct V_15 * V_7 = V_14 -> V_7 ;
F_14 ( V_14 -> V_17 , V_7 ) ;
}
static struct V_22 * F_15 ( struct V_13 * V_14 )
{
struct V_15 * V_7 = V_14 -> V_7 ;
struct V_2 * V_3 = F_8 ( V_7 ) ;
struct V_22 * V_23 ;
V_23 = F_16 ( V_3 , V_24 , 0 ) ;
if ( V_23 && ( F_17 ( V_23 ) >= 0x800 ) )
return V_23 ;
return NULL ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_13 * V_14 ;
struct V_25 * V_25 ;
struct V_15 * V_7 = & V_3 -> V_7 ;
enum V_26 V_27 ;
struct V_22 * V_23 ;
int V_16 ;
V_16 = - V_28 ;
V_14 = F_19 ( V_7 ) ;
if ( ! V_14 )
goto V_29;
V_25 = F_20 ( V_7 , sizeof( * V_25 ) , V_30 ) ;
if ( ! V_25 )
goto V_29;
V_14 -> V_31 = V_25 ;
V_14 -> V_18 = V_3 -> V_7 . V_8 ? F_1 ( V_3 )
: F_4 ( V_3 ) ;
if ( ! V_14 -> V_18 || ! V_14 -> V_18 -> V_32 ) {
V_16 = - V_33 ;
F_21 ( V_7 , L_3 ) ;
goto V_29;
}
V_14 -> V_34 = F_12 ;
V_14 -> F_14 = F_13 ;
V_23 = F_15 ( V_14 ) ;
V_14 -> V_35 = F_22 ( V_7 , V_23 ) ;
if ( F_23 ( V_14 -> V_35 ) ) {
V_16 = F_24 ( V_14 -> V_35 ) ;
goto V_29;
}
V_14 -> V_36 = V_14 -> V_35 ;
V_27 = F_25 ( V_7 ) ;
if ( V_27 == V_37 ) {
F_21 ( V_7 , L_4 ) ;
goto V_29;
}
V_25 -> V_38 = ( V_27 == V_39 ) ;
if ( V_25 -> V_38 )
V_14 -> V_40 = V_41 ;
else
V_14 -> V_40 = V_42 ;
V_16 = F_26 ( V_7 , F_27 ( 48 ) ) ;
if ( V_16 ) {
F_21 ( V_7 , L_5 , V_16 ) ;
goto V_29;
}
F_28 ( V_7 , V_14 ) ;
V_16 = V_14 -> V_18 -> V_19 -> V_43 ( V_14 ) ;
if ( V_16 )
goto V_29;
F_11 ( V_7 , L_6 ) ;
return 0 ;
V_29:
F_11 ( V_7 , L_7 ) ;
return V_16 ;
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_15 * V_7 = & V_3 -> V_7 ;
struct V_13 * V_14 = F_30 ( V_7 ) ;
V_14 -> V_18 -> V_19 -> V_44 ( V_14 ) ;
F_11 ( V_7 , L_8 ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 ,
T_1 V_45 )
{
struct V_15 * V_7 = & V_3 -> V_7 ;
struct V_13 * V_14 = F_30 ( V_7 ) ;
unsigned long V_46 ;
unsigned int V_47 ;
F_32 ( & V_14 -> V_48 , V_46 ) ;
V_14 -> V_49 = 1 ;
for ( V_47 = 0 ; V_47 < V_14 -> V_50 ; V_47 ++ )
F_33 ( V_14 -> V_51 [ V_47 ] . V_52 ) ;
F_34 ( & V_14 -> V_48 , V_46 ) ;
while ( ! F_35 ( V_14 ) )
F_36 ( V_14 -> V_53 ,
F_35 ( V_14 ) ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 )
{
struct V_15 * V_7 = & V_3 -> V_7 ;
struct V_13 * V_14 = F_30 ( V_7 ) ;
unsigned long V_46 ;
unsigned int V_47 ;
F_32 ( & V_14 -> V_48 , V_46 ) ;
V_14 -> V_49 = 0 ;
for ( V_47 = 0 ; V_47 < V_14 -> V_50 ; V_47 ++ ) {
V_14 -> V_51 [ V_47 ] . V_54 = 0 ;
F_33 ( V_14 -> V_51 [ V_47 ] . V_52 ) ;
}
F_34 ( & V_14 -> V_48 , V_46 ) ;
return 0 ;
}
int F_38 ( void )
{
return F_39 ( & V_55 ) ;
}
void F_40 ( void )
{
F_41 ( & V_55 ) ;
}
