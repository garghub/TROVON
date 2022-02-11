static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
long V_12 ;
int V_13 ;
V_13 = F_3 ( V_5 , 10 , & V_12 ) ;
if ( V_13 )
goto V_14;
if ( V_12 > 100000 ) {
V_13 = - V_15 ;
goto V_14;
}
F_4 ( V_10 -> V_16 -> V_17 ) ;
if ( ! V_12 )
goto V_14;
V_12 = F_5 () / V_12 ;
if ( V_12 <= 4 ) {
V_13 = - V_15 ;
goto V_14;
}
F_6 ( V_10 -> V_16 -> V_18 , V_12 ) ;
F_7 ( V_10 -> V_16 -> V_18 , 1 ) ;
F_8 ( V_10 -> V_16 -> V_17 ) ;
V_14:
return V_13 ? V_13 : V_6 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
return sprintf ( V_5 , L_1 ,
F_5 () / F_10 ( V_10 -> V_16 -> V_18 ) ) ;
}
static T_3 F_11 ( int V_19 , void * V_20 )
{
struct V_9 * V_10 = V_20 ;
F_12 ( V_10 -> V_16 -> V_18 ) ;
F_13 ( V_10 -> V_8 , 0 ) ;
return V_21 ;
}
static int F_14 ( int V_19 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ )
if ( V_24 [ V_22 ] . V_19 == V_19 )
return V_22 ;
return - V_25 ;
}
static int T_4 F_15 ( struct V_26 * V_27 )
{
struct V_9 * V_10 ;
int V_13 ;
V_10 = F_16 ( sizeof( * V_10 ) , V_28 ) ;
if ( V_10 == NULL ) {
V_13 = - V_29 ;
goto V_30;
}
V_10 -> V_19 = F_17 ( V_27 , 0 ) ;
if ( ! V_10 -> V_19 ) {
F_18 ( & V_27 -> V_2 , L_2 ) ;
V_13 = - V_25 ;
goto V_31;
}
V_13 = F_14 ( V_10 -> V_19 ) ;
if ( V_13 < 0 )
goto V_31;
V_10 -> V_32 = V_13 ;
V_10 -> V_16 = & V_24 [ V_10 -> V_32 ] ;
V_10 -> V_8 = F_19 ( L_3 , V_10 -> V_32 ) ;
if ( ! V_10 -> V_8 ) {
V_13 = - V_29 ;
goto V_31;
}
V_10 -> V_8 -> V_11 = V_10 ;
V_10 -> V_8 -> V_33 = V_34 ;
V_10 -> V_8 -> V_2 . V_35 = V_36 ;
V_13 = F_20 ( V_10 -> V_8 ) ;
if ( V_13 )
goto V_37;
V_13 = F_21 ( V_10 -> V_19 , F_11 ,
0 , V_10 -> V_8 -> V_38 , V_10 ) ;
if ( V_13 ) {
F_18 ( & V_27 -> V_2 ,
L_4 , V_10 -> V_19 ) ;
goto V_39;
}
F_22 ( V_10 -> V_16 -> V_18 , V_40 | V_41 | V_42 | V_43 ) ;
F_23 ( & V_27 -> V_2 , L_5 ,
V_10 -> V_32 , V_10 -> V_19 ) ;
F_24 ( V_27 , V_10 ) ;
return 0 ;
V_39:
F_25 ( V_10 -> V_8 ) ;
V_37:
F_26 ( V_10 -> V_8 ) ;
V_31:
F_27 ( V_10 ) ;
V_30:
return V_13 ;
}
static int T_5 F_28 ( struct V_26 * V_27 )
{
struct V_9 * V_10 = F_29 ( V_27 ) ;
F_4 ( V_10 -> V_16 -> V_17 ) ;
F_30 ( V_10 -> V_19 , V_10 ) ;
F_25 ( V_10 -> V_8 ) ;
F_26 ( V_10 -> V_8 ) ;
F_27 ( V_10 ) ;
return 0 ;
}
static int T_6 F_31 ( void )
{
return F_32 ( & V_44 ) ;
}
static void T_7 F_33 ( void )
{
F_34 ( & V_44 ) ;
}
