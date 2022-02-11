static struct V_1 * F_1 ( struct V_2 * V_3 )
{
int V_4 ;
int V_5 ;
struct V_1 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 = V_6 ;
if ( F_3 ( V_8 , V_6 -> V_9 + V_10 )
|| ! V_6 -> V_11 ) {
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
V_5 = F_4 ( V_6 -> V_13 ,
F_5 ( V_4 ) ) ;
if ( V_5 < 0 ) {
V_7 = F_6 ( V_5 ) ;
goto abort;
}
V_6 -> V_14 [ V_4 ] = V_5 ;
}
V_6 -> V_9 = V_8 ;
V_6 -> V_11 = true ;
}
abort:
return V_7 ;
}
static int F_7 ( struct V_1 * V_6 )
{
int V_4 , V_5 ;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
V_5 = F_4 ( V_6 -> V_13 ,
F_8 ( V_4 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_6 -> V_15 [ V_4 ] = V_5 ;
V_5 = F_4 ( V_6 -> V_13 ,
F_9 ( V_4 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_6 -> V_16 [ V_4 ] = V_5 ;
}
return 0 ;
}
static T_1
F_10 ( struct V_2 * V_3 , struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_21 = F_11 ( V_18 ) ;
return sprintf ( V_19 , L_1 , V_22 [ V_21 -> V_23 ] ) ;
}
static T_1
F_12 ( struct V_2 * V_3 , struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_21 = F_11 ( V_18 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
if ( F_13 ( V_6 ) )
return F_14 ( V_6 ) ;
return sprintf ( V_19 , L_2 , V_6 -> V_14 [ V_21 -> V_23 ] ) ;
}
static T_1
F_15 ( struct V_2 * V_3 , struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_21 = F_11 ( V_18 ) ;
struct V_1 * V_6 = F_2 ( V_3 ) ;
return sprintf ( V_19 , L_2 , V_6 -> V_15 [ V_21 -> V_23 ] ) ;
}
static T_1
F_16 ( struct V_2 * V_3 , struct V_17 * V_18 , char * V_19 )
{
struct V_20 * V_21 = F_11 ( V_18 ) ;
struct V_1 * V_6 = F_2 ( V_3 ) ;
return sprintf ( V_19 , L_2 , V_6 -> V_16 [ V_21 -> V_23 ] ) ;
}
static int F_17 ( struct V_24 * V_25 )
{
int V_26 ;
struct V_1 * V_6 ;
struct V_13 * V_13 = F_18 ( V_25 -> V_3 . V_27 ) ;
struct V_2 * V_28 ;
V_6 = F_19 ( & V_25 -> V_3 , sizeof( struct V_1 ) ,
V_29 ) ;
if ( ! V_6 )
return - V_30 ;
V_6 -> V_13 = V_13 ;
V_26 = F_7 ( V_6 ) ;
if ( V_26 ) {
F_20 ( & V_25 -> V_3 , L_3 ) ;
return V_26 ;
}
V_28 = F_21 ( & V_25 -> V_3 ,
L_4 , V_6 ,
V_31 ) ;
if ( F_13 ( V_28 ) )
return F_14 ( V_28 ) ;
F_22 ( & V_25 -> V_3 , L_5 ) ;
return 0 ;
}
