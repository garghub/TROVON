static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = 0 ;
if ( V_3 == 0 )
F_2 ( V_5 L_1 , V_2 -> V_6 ) ;
else
F_2 ( V_5 L_2 , V_2 -> V_6 , V_3 ) ;
F_3 () ;
V_4 = F_4 ( V_3 , V_2 -> V_7 ) ;
F_5 () ;
F_2 ( V_5 L_3 , V_2 -> V_6 , V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
T_2 V_10 )
{
char V_11 [ V_12 ] ;
struct V_13 * V_14 ;
T_1 V_4 ;
F_3 () ;
V_14 = F_7 ( V_9 , V_10 ) ;
if ( V_14 ) {
V_4 = V_2 -> V_7 ( V_14 , 0 ) ;
F_8 ( (struct V_15 * ) & V_14 -> V_16 , V_11 , sizeof( V_11 ) ) ;
F_2 ( V_5 L_4 , V_2 -> V_6 , V_11 , V_4 ) ;
}
F_5 () ;
}
static void F_9 ( struct V_1 * V_2 , T_1 * V_3 )
{
F_3 () ;
* V_3 = F_4 ( 0 , V_2 -> V_17 ) ;
F_5 () ;
}
static T_3 F_10 ( struct V_6 * V_6 , char T_4 * V_11 ,
T_2 V_18 , T_5 * V_19 )
{
static T_1 V_3 ;
char V_20 [ 25 ] ;
T_2 V_21 , V_22 ;
T_5 V_23 = * V_19 ;
if ( ! V_23 )
F_9 ( V_6 -> V_24 -> V_25 -> V_26 , & V_3 ) ;
V_21 = F_11 ( V_20 , sizeof( V_20 ) , L_5 , V_3 ) ;
if ( V_23 < 0 )
return - V_27 ;
if ( V_23 >= V_21 || ! V_18 )
return 0 ;
if ( V_18 > V_21 - V_23 )
V_18 = V_21 - V_23 ;
V_22 = F_12 ( V_11 , V_20 + V_23 , V_18 ) ;
if ( V_22 == V_18 )
return - V_28 ;
V_18 -= V_22 ;
* V_19 = V_23 + V_18 ;
return V_18 ;
}
static T_3 F_13 ( struct V_6 * V_6 , const char T_4 * V_11 ,
T_2 V_18 , T_5 * V_19 )
{
char V_29 [ V_12 ] ;
T_2 V_21 = F_14 ( sizeof( V_29 ) - 1 , V_18 ) ;
struct V_30 * V_30 = V_31 -> V_32 -> V_33 ;
struct V_8 V_34 ;
T_1 V_3 ;
if ( F_15 ( V_29 , V_11 , V_21 ) )
return - V_28 ;
V_29 [ V_21 ] = '\0' ;
V_21 = F_16 ( V_30 , V_29 , V_21 , (struct V_15 * ) & V_34 , sizeof( V_34 ) ) ;
if ( V_21 > 0 )
F_6 ( V_6 -> V_24 -> V_25 -> V_26 , & V_34 , V_21 ) ;
else {
V_3 = F_17 ( V_29 , NULL , 0 ) ;
F_1 ( V_6 -> V_24 -> V_25 -> V_26 , V_3 ) ;
}
return V_18 ;
}
void F_18 ( void )
{
F_19 ( V_35 ) ;
}
int F_20 ( void )
{
unsigned int V_36 ;
struct V_1 * V_2 ;
T_6 V_37 = V_38 | V_39 | V_40 ;
V_35 = F_21 ( L_6 , NULL ) ;
if ( ! V_35 )
goto V_41;
for ( V_36 = 0 ; V_36 < V_42 ; V_36 ++ ) {
V_2 = & V_43 [ V_36 ] ;
if ( ! F_22 ( V_2 -> V_6 , V_37 , V_35 , V_2 , & V_44 ) )
goto V_41;
}
return 0 ;
V_41:
F_18 () ;
return - V_45 ;
}
