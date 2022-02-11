static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 ;
T_1 V_5 ;
int V_6 ;
while ( ( V_4 - V_3 ) < V_7 ) {
V_5 = F_2 ( V_2 , 0x13 , & V_6 ) ;
if ( V_5 & 0x01 )
return 1 ;
F_3 () ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , char * V_8 )
{
int V_6 = 0 , V_9 , V_10 , V_11 ;
struct V_12 * V_13 = NULL ;
struct V_14 * V_14 = NULL ;
T_1 * V_15 = V_16 ;
T_2 V_17 = 0 ;
V_13 = F_5 ( V_8 , V_18 | V_19 , 0 ) ;
if ( F_6 ( V_13 ) ) {
F_7 ( V_20 L_1 , V_8 ) ;
return - V_21 ;
}
V_14 = V_13 -> V_22 -> V_23 ;
if ( ! F_8 ( V_14 -> V_24 ) ) {
F_7 ( V_20 L_2 , V_8 ) ;
V_6 = - V_25 ;
goto V_26;
}
V_10 = F_9 ( V_14 -> V_27 -> V_28 ) ;
if ( V_10 <= 0 ) {
F_7 ( V_20 L_3 , V_8 ) ;
V_6 = V_10 ;
goto V_26;
}
V_11 = 0 ;
while ( ( V_9 = V_13 -> V_29 -> V_30 ( V_13 , V_15 + V_31 ,
V_32 , & V_17 ) ) ) {
if ( V_9 < 0 ) {
V_6 = - 1 ;
goto V_26;
}
V_15 [ 0 ] = V_9 & 0xff ;
V_15 [ 1 ] = ( V_9 >> 8 ) & 0xff ;
V_15 [ 2 ] = ( V_9 >> 16 ) & 0xff ;
if ( V_17 >= V_10 )
V_15 [ 3 ] = 2 ;
else
V_15 [ 3 ] = 0 ;
V_6 = F_10 ( V_2 , 0 , V_15 , V_9 + V_31 ) ;
if ( V_6 < 0 ) {
F_7 ( V_20 L_4
L_5 , V_11 , V_6 ) ;
goto V_26;
}
if ( V_15 [ 3 ] == 2 )
break;
if ( ! F_1 ( V_2 ) ) {
V_6 = - V_33 ;
F_7 ( V_20 L_6 ) ;
goto V_26;
}
V_6 = F_11 ( V_2 , V_15 , 0 , V_34 ) ;
if ( V_6 < 0 ) {
F_7 ( V_20 L_7
L_5 , V_11 , V_6 ) ;
goto V_26;
}
F_12 ( V_2 , 0x01 , 0x13 , & V_6 ) ;
F_12 ( V_2 , 0x00 , 0x10 , & V_6 ) ;
V_11 ++ ;
}
V_26:
F_13 ( V_13 , NULL ) ;
return V_6 ;
}
int F_14 ( struct V_1 * V_2 )
{
static T_3 V_35 ;
int V_6 ;
V_16 = F_15 ( V_36 , V_37 ) ;
if ( V_16 == NULL ) {
F_7 ( V_20 L_8 , V_38 , __LINE__ ) ;
return - V_39 ;
}
V_35 = F_16 () ;
F_17 ( F_18 () ) ;
V_6 = F_4 ( V_2 , V_40 ) ;
if ( V_6 )
goto V_41;
F_7 ( V_42 L_9 ) ;
V_6 = F_4 ( V_2 , V_43 ) ;
if ( V_6 )
goto V_41;
F_7 ( V_42 L_10 ) ;
V_41:
F_17 ( V_35 ) ;
F_19 ( V_16 ) ;
return V_6 ;
}
