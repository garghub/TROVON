static struct V_1 * F_1 ( struct V_2 * V_3 ,
int V_4 ,
int V_5 )
{
int V_6 ;
int V_7 ;
struct V_1 * V_8 ;
struct V_9 * V_10 ;
if ( ! V_4 || V_5 == - 1 )
goto V_11;
if ( ! F_2 ( V_4 , 0x10 , V_12 ) ) {
F_3 ( V_13 L_1 , V_12 ,
V_4 ) ;
goto V_11;
}
if ( ! F_4 ( V_4 , V_14 ) ) {
F_3 ( V_15 L_2 ,
V_12 ,
V_4 ) ;
goto V_16;
}
F_3 ( V_13 L_3
L_4 , V_12 , V_4 , V_5 ) ;
V_6 = F_5 ( V_4 , V_14 ) ;
V_7 = V_3 -> V_17 ;
if ( V_7 < 0 )
V_7 = 7 ;
F_6 ( V_4 , V_7 , V_14 ) ;
V_8 = F_7 ( V_3 , sizeof( struct V_9 ) ) ;
if ( ! V_8 )
goto V_16;
V_10 = F_8 ( V_8 ) ;
V_8 -> V_18 = V_4 ;
V_8 -> V_19 = 16 ;
V_8 -> V_20 = - 1 ;
if ( V_5 != - 1 )
V_8 -> V_21 = V_5 ;
V_10 -> V_4 = V_4 ;
V_10 -> V_5 = V_5 ;
V_10 -> V_7 = V_7 ;
V_10 -> V_22 = V_8 ;
V_10 -> V_23 = V_14 ;
sprintf ( V_10 -> V_24 ,
L_5 ,
V_6 , V_4 , V_5 , V_25 ) ;
V_3 -> V_26 = V_12 ;
if ( F_9 ( V_5 , V_27 , 0 , V_12 , V_8 ) )
goto V_28;
if ( F_10 ( V_8 , NULL ) )
goto V_29;
F_11 ( V_8 ) ;
return V_8 ;
V_29:
F_12 ( V_5 , V_8 ) ;
V_28:
F_13 ( V_8 ) ;
V_16:
F_14 ( V_4 , 0x10 ) ;
V_11:
return NULL ;
}
static int T_1 F_15 ( struct V_2 * V_30 )
{
struct V_1 * V_22 ;
struct V_9 * V_10 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
V_22 = F_1 ( V_30 , V_33 [ V_31 ] , V_21 [ V_31 ] ) ;
if ( V_22 == NULL ) {
break;
}
V_10 = F_8 ( V_22 ) ;
V_10 -> V_34 = V_35 ;
V_35 = V_10 ;
}
return V_31 ;
}
static int F_16 ( struct V_1 * V_22 )
{
struct V_9 * V_10 = F_8 ( V_22 ) ;
F_17 ( V_22 ) ;
if ( V_22 -> V_21 ) {
F_18 ( V_10 ) ;
F_12 ( V_22 -> V_21 , V_22 ) ;
}
if ( V_22 -> V_20 != 0xff )
F_19 ( V_22 -> V_20 ) ;
if ( V_22 -> V_18 && V_22 -> V_19 )
F_14 ( V_22 -> V_18 , V_22 -> V_19 ) ;
F_13 ( V_22 ) ;
return 0 ;
}
static T_2 int F_20 ( void )
{
if ( ! F_15 ( & V_36 ) ) {
F_3 ( V_13 L_6
L_7
L_8 , V_12 ) ;
return - V_37 ;
}
return 0 ;
}
static T_3 void F_21 ( void )
{
struct V_9 * V_10 ;
for ( V_10 = V_35 ; V_10 != NULL ; V_10 = V_10 -> V_34 )
F_16 ( V_10 -> V_22 ) ;
}
