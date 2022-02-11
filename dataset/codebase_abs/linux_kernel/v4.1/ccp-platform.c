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
static int F_12 ( struct V_1 * V_2 )
{
struct V_13 * V_13 = V_2 -> V_14 ;
struct V_15 * V_16 = F_13 ( V_2 -> V_4 ) ;
T_1 V_17 ;
T_2 V_18 ;
unsigned long long V_19 ;
int V_20 ;
V_17 = V_16 -> V_17 ;
do {
V_18 = F_14 ( V_17 , L_4 , NULL , & V_19 ) ;
if ( ! F_15 ( V_18 ) ) {
V_20 = V_19 ;
break;
}
} while ( ! F_15 ( V_18 ) );
if ( F_15 ( V_18 ) ) {
F_16 ( V_2 -> V_4 , L_5 ) ;
return - V_21 ;
}
V_13 -> V_22 = ! ! V_20 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return - V_21 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_13 * V_13 = V_2 -> V_14 ;
V_13 -> V_22 = F_18 ( V_2 -> V_4 -> V_23 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return - V_21 ;
}
static int F_19 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_13 * V_13 ;
struct V_3 * V_4 = & V_6 -> V_4 ;
struct V_15 * V_16 = F_13 ( V_4 ) ;
struct V_10 * V_11 ;
int V_7 ;
V_7 = - V_24 ;
V_2 = F_20 ( V_4 ) ;
if ( ! V_2 )
goto V_25;
V_13 = F_21 ( V_4 , sizeof( * V_13 ) , V_26 ) ;
if ( ! V_13 )
goto V_25;
V_2 -> V_14 = V_13 ;
V_2 -> V_27 = F_6 ;
V_2 -> F_8 = F_7 ;
V_13 -> V_28 = ( ! V_16 || V_29 ) ? 0 : 1 ;
V_11 = F_9 ( V_2 ) ;
V_2 -> V_30 = F_22 ( V_4 , V_11 ) ;
if ( F_23 ( V_2 -> V_30 ) ) {
V_7 = F_24 ( V_2 -> V_30 ) ;
goto V_25;
}
V_2 -> V_31 = V_2 -> V_30 ;
if ( ! V_4 -> V_32 )
V_4 -> V_32 = & V_4 -> V_33 ;
V_7 = F_25 ( V_4 , F_26 ( 48 ) ) ;
if ( V_7 ) {
F_16 ( V_4 , L_6 , V_7 ) ;
goto V_25;
}
if ( V_13 -> V_28 )
V_7 = F_12 ( V_2 ) ;
else
V_7 = F_17 ( V_2 ) ;
if ( V_7 )
goto V_25;
if ( V_13 -> V_22 )
V_2 -> V_34 = V_35 ;
else
V_2 -> V_34 = V_36 ;
F_27 ( V_4 , V_2 ) ;
V_7 = F_28 ( V_2 ) ;
if ( V_7 )
goto V_25;
F_5 ( V_4 , L_7 ) ;
return 0 ;
V_25:
F_5 ( V_4 , L_8 ) ;
return V_7 ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = & V_6 -> V_4 ;
struct V_1 * V_2 = F_30 ( V_4 ) ;
F_31 ( V_2 ) ;
F_5 ( V_4 , L_9 ) ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 ,
T_3 V_37 )
{
struct V_3 * V_4 = & V_6 -> V_4 ;
struct V_1 * V_2 = F_30 ( V_4 ) ;
unsigned long V_38 ;
unsigned int V_39 ;
F_33 ( & V_2 -> V_40 , V_38 ) ;
V_2 -> V_41 = 1 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_42 ; V_39 ++ )
F_34 ( V_2 -> V_43 [ V_39 ] . V_44 ) ;
F_35 ( & V_2 -> V_40 , V_38 ) ;
while ( ! F_36 ( V_2 ) )
F_37 ( V_2 -> V_45 ,
F_36 ( V_2 ) ) ;
return 0 ;
}
static int F_38 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = & V_6 -> V_4 ;
struct V_1 * V_2 = F_30 ( V_4 ) ;
unsigned long V_38 ;
unsigned int V_39 ;
F_33 ( & V_2 -> V_40 , V_38 ) ;
V_2 -> V_41 = 0 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_42 ; V_39 ++ ) {
V_2 -> V_43 [ V_39 ] . V_46 = 0 ;
F_34 ( V_2 -> V_43 [ V_39 ] . V_44 ) ;
}
F_35 ( & V_2 -> V_40 , V_38 ) ;
return 0 ;
}
int F_39 ( void )
{
return F_40 ( & V_47 ) ;
}
void F_41 ( void )
{
F_42 ( & V_47 ) ;
}
