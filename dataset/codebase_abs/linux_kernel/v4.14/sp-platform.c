static struct V_1 * F_1 ( struct V_2 * V_3 )
{
#ifdef F_2
const struct V_4 * V_5 ;
V_5 = F_3 ( V_6 , V_3 -> V_7 . V_8 ) ;
if ( V_5 && V_5 -> V_9 )
return (struct V_1 * ) V_5 -> V_9 ;
#endif
return NULL ;
}
static struct V_1 * F_4 ( struct V_2 * V_3 )
{
#ifdef F_5
const struct V_10 * V_5 ;
V_5 = F_6 ( V_11 , & V_3 -> V_7 ) ;
if ( V_5 && V_5 -> V_12 )
return (struct V_1 * ) V_5 -> V_12 ;
#endif
return NULL ;
}
static int F_7 ( struct V_13 * V_14 )
{
struct V_15 * V_15 = V_14 -> V_16 ;
struct V_17 * V_7 = V_14 -> V_7 ;
struct V_2 * V_3 = F_8 ( V_7 ) ;
unsigned int V_18 , V_19 ;
int V_20 ;
for ( V_18 = 0 , V_19 = 0 ; V_18 < V_3 -> V_21 ; V_18 ++ ) {
struct V_22 * V_23 = & V_3 -> V_22 [ V_18 ] ;
if ( F_9 ( V_23 ) == V_24 )
V_19 ++ ;
}
V_15 -> V_25 = V_19 ;
V_20 = F_10 ( V_3 , 0 ) ;
if ( V_20 < 0 ) {
F_11 ( V_7 , L_1 , V_20 ) ;
return V_20 ;
}
V_14 -> V_26 = V_20 ;
if ( V_19 == 1 ) {
V_14 -> V_27 = V_20 ;
} else {
V_20 = F_10 ( V_3 , 1 ) ;
if ( V_20 < 0 ) {
F_11 ( V_7 , L_1 , V_20 ) ;
return V_20 ;
}
V_14 -> V_27 = V_20 ;
}
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_13 * V_14 ;
struct V_15 * V_15 ;
struct V_17 * V_7 = & V_3 -> V_7 ;
enum V_28 V_29 ;
struct V_22 * V_30 ;
int V_20 ;
V_20 = - V_31 ;
V_14 = F_13 ( V_7 ) ;
if ( ! V_14 )
goto V_32;
V_15 = F_14 ( V_7 , sizeof( * V_15 ) , V_33 ) ;
if ( ! V_15 )
goto V_32;
V_14 -> V_16 = V_15 ;
V_14 -> V_34 = V_3 -> V_7 . V_8 ? F_1 ( V_3 )
: F_4 ( V_3 ) ;
if ( ! V_14 -> V_34 ) {
V_20 = - V_35 ;
F_15 ( V_7 , L_2 ) ;
goto V_32;
}
V_30 = F_16 ( V_3 , V_36 , 0 ) ;
V_14 -> V_37 = F_17 ( V_7 , V_30 ) ;
if ( F_18 ( V_14 -> V_37 ) ) {
V_20 = F_19 ( V_14 -> V_37 ) ;
goto V_32;
}
V_29 = F_20 ( V_7 ) ;
if ( V_29 == V_38 ) {
F_15 ( V_7 , L_3 ) ;
goto V_32;
}
V_15 -> V_39 = ( V_29 == V_40 ) ;
if ( V_15 -> V_39 )
V_14 -> V_41 = V_42 ;
else
V_14 -> V_41 = V_43 ;
V_20 = F_21 ( V_7 , F_22 ( 48 ) ) ;
if ( V_20 ) {
F_15 ( V_7 , L_4 , V_20 ) ;
goto V_32;
}
V_20 = F_7 ( V_14 ) ;
if ( V_20 )
goto V_32;
F_23 ( V_7 , V_14 ) ;
V_20 = F_24 ( V_14 ) ;
if ( V_20 )
goto V_32;
F_11 ( V_7 , L_5 ) ;
return 0 ;
V_32:
F_11 ( V_7 , L_6 ) ;
return V_20 ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_17 * V_7 = & V_3 -> V_7 ;
struct V_13 * V_14 = F_26 ( V_7 ) ;
F_27 ( V_14 ) ;
F_11 ( V_7 , L_7 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 ,
T_1 V_44 )
{
struct V_17 * V_7 = & V_3 -> V_7 ;
struct V_13 * V_14 = F_26 ( V_7 ) ;
return F_29 ( V_14 , V_44 ) ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_17 * V_7 = & V_3 -> V_7 ;
struct V_13 * V_14 = F_26 ( V_7 ) ;
return F_31 ( V_14 ) ;
}
int F_32 ( void )
{
return F_33 ( & V_45 ) ;
}
void F_34 ( void )
{
F_35 ( & V_45 ) ;
}
