static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ,
struct V_5 , V_4 ) ;
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
struct V_5 * V_6 = F_2 ( V_4 ,
struct V_5 , V_4 ) ;
struct V_10 * V_11 ;
V_11 = F_10 ( V_6 , V_12 , 0 ) ;
if ( V_11 && ( F_11 ( V_11 ) >= 0x800 ) )
return V_11 ;
return NULL ;
}
static int F_12 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = & V_6 -> V_4 ;
struct V_10 * V_11 ;
int V_7 ;
V_7 = - V_13 ;
V_2 = F_13 ( V_4 ) ;
if ( ! V_2 )
goto V_14;
V_2 -> V_15 = NULL ;
V_2 -> V_16 = F_6 ;
V_2 -> F_8 = F_7 ;
V_11 = F_9 ( V_2 ) ;
V_2 -> V_17 = F_14 ( V_4 , V_11 ) ;
if ( F_15 ( V_2 -> V_17 ) ) {
V_7 = F_16 ( V_2 -> V_17 ) ;
goto V_18;
}
V_2 -> V_19 = V_2 -> V_17 ;
if ( ! V_4 -> V_20 )
V_4 -> V_20 = & V_4 -> V_21 ;
* ( V_4 -> V_20 ) = F_17 ( 48 ) ;
V_4 -> V_21 = F_17 ( 48 ) ;
if ( F_18 ( V_4 -> V_22 , L_4 ) )
V_2 -> V_23 = V_24 ;
else
V_2 -> V_23 = V_25 ;
F_19 ( V_4 , V_2 ) ;
V_7 = F_20 ( V_2 ) ;
if ( V_7 )
goto V_18;
F_5 ( V_4 , L_5 ) ;
return 0 ;
V_18:
F_21 ( V_2 ) ;
V_14:
F_5 ( V_4 , L_6 ) ;
return V_7 ;
}
static int F_22 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = & V_6 -> V_4 ;
struct V_1 * V_2 = F_23 ( V_4 ) ;
F_24 ( V_2 ) ;
F_21 ( V_2 ) ;
F_5 ( V_4 , L_7 ) ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 ,
T_1 V_26 )
{
struct V_3 * V_4 = & V_6 -> V_4 ;
struct V_1 * V_2 = F_23 ( V_4 ) ;
unsigned long V_27 ;
unsigned int V_28 ;
F_26 ( & V_2 -> V_29 , V_27 ) ;
V_2 -> V_30 = 1 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_31 ; V_28 ++ )
F_27 ( V_2 -> V_32 [ V_28 ] . V_33 ) ;
F_28 ( & V_2 -> V_29 , V_27 ) ;
while ( ! F_29 ( V_2 ) )
F_30 ( V_2 -> V_34 ,
F_29 ( V_2 ) ) ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = & V_6 -> V_4 ;
struct V_1 * V_2 = F_23 ( V_4 ) ;
unsigned long V_27 ;
unsigned int V_28 ;
F_26 ( & V_2 -> V_29 , V_27 ) ;
V_2 -> V_30 = 0 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_31 ; V_28 ++ ) {
V_2 -> V_32 [ V_28 ] . V_35 = 0 ;
F_27 ( V_2 -> V_32 [ V_28 ] . V_33 ) ;
}
F_28 ( & V_2 -> V_29 , V_27 ) ;
return 0 ;
}
int F_32 ( void )
{
return F_33 ( & V_36 ) ;
}
void F_34 ( void )
{
F_35 ( & V_36 ) ;
}
