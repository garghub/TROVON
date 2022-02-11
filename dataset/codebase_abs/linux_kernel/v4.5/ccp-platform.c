static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_7 ;
V_7 = F_3 ( V_6 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_8 = V_7 ;
V_7 = F_4 ( V_2 -> V_8 , V_9 , 0 , L_1 , V_4 ) ;
if ( V_7 ) {
F_5 ( V_4 , L_2 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_7 ;
V_7 = F_1 ( V_2 ) ;
if ( ! V_7 )
return 0 ;
F_5 ( V_4 , L_3 , V_7 ) ;
return V_7 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_8 ( V_2 -> V_8 , V_4 ) ;
}
static struct V_10 * F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_10 * V_11 ;
V_11 = F_10 ( V_6 , V_12 , 0 ) ;
if ( V_11 && ( F_11 ( V_11 ) >= 0x800 ) )
return V_11 ;
return NULL ;
}
static int F_12 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_13 * V_13 ;
struct V_3 * V_4 = & V_6 -> V_4 ;
enum V_14 V_15 ;
struct V_10 * V_11 ;
int V_7 ;
V_7 = - V_16 ;
V_2 = F_13 ( V_4 ) ;
if ( ! V_2 )
goto V_17;
V_13 = F_14 ( V_4 , sizeof( * V_13 ) , V_18 ) ;
if ( ! V_13 )
goto V_17;
V_2 -> V_19 = V_13 ;
V_2 -> V_20 = F_6 ;
V_2 -> F_8 = F_7 ;
V_11 = F_9 ( V_2 ) ;
V_2 -> V_21 = F_15 ( V_4 , V_11 ) ;
if ( F_16 ( V_2 -> V_21 ) ) {
V_7 = F_17 ( V_2 -> V_21 ) ;
goto V_17;
}
V_2 -> V_22 = V_2 -> V_21 ;
V_15 = F_18 ( V_4 ) ;
if ( V_15 == V_23 ) {
F_19 ( V_4 , L_4 ) ;
goto V_17;
}
V_13 -> V_24 = ( V_15 == V_25 ) ;
if ( V_13 -> V_24 )
V_2 -> V_26 = V_27 ;
else
V_2 -> V_26 = V_28 ;
V_7 = F_20 ( V_4 , F_21 ( 48 ) ) ;
if ( V_7 ) {
F_19 ( V_4 , L_5 , V_7 ) ;
goto V_17;
}
F_22 ( V_4 , V_2 ) ;
V_7 = F_23 ( V_2 ) ;
if ( V_7 )
goto V_17;
F_5 ( V_4 , L_6 ) ;
return 0 ;
V_17:
F_5 ( V_4 , L_7 ) ;
return V_7 ;
}
static int F_24 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = & V_6 -> V_4 ;
struct V_1 * V_2 = F_25 ( V_4 ) ;
F_26 ( V_2 ) ;
F_5 ( V_4 , L_8 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 ,
T_1 V_29 )
{
struct V_3 * V_4 = & V_6 -> V_4 ;
struct V_1 * V_2 = F_25 ( V_4 ) ;
unsigned long V_30 ;
unsigned int V_31 ;
F_28 ( & V_2 -> V_32 , V_30 ) ;
V_2 -> V_33 = 1 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_34 ; V_31 ++ )
F_29 ( V_2 -> V_35 [ V_31 ] . V_36 ) ;
F_30 ( & V_2 -> V_32 , V_30 ) ;
while ( ! F_31 ( V_2 ) )
F_32 ( V_2 -> V_37 ,
F_31 ( V_2 ) ) ;
return 0 ;
}
static int F_33 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = & V_6 -> V_4 ;
struct V_1 * V_2 = F_25 ( V_4 ) ;
unsigned long V_30 ;
unsigned int V_31 ;
F_28 ( & V_2 -> V_32 , V_30 ) ;
V_2 -> V_33 = 0 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_34 ; V_31 ++ ) {
V_2 -> V_35 [ V_31 ] . V_38 = 0 ;
F_29 ( V_2 -> V_35 [ V_31 ] . V_36 ) ;
}
F_30 ( & V_2 -> V_32 , V_30 ) ;
return 0 ;
}
int F_34 ( void )
{
return F_35 ( & V_39 ) ;
}
void F_36 ( void )
{
F_37 ( & V_39 ) ;
}
