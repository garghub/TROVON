static void
F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 L_1 , V_2 -> V_4 >> V_5 ) ;
F_2 ( L_2 , V_2 -> V_4 & V_6 ) ;
F_2 ( L_3 , V_2 -> V_7 ) ;
F_2 ( L_4 , V_2 -> V_8 ) ;
}
static T_1
F_3 ( struct V_9 * V_10 , long V_11 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_15 * V_16 = F_4 ( V_10 ) ;
struct V_17 * V_18 = F_5 ( V_13 ) ;
unsigned long V_19 = V_13 -> V_20 ;
T_2 V_21 = F_6 ( V_18 , V_16 -> V_22 . V_23 ) ;
int V_24 ;
if ( V_21 > V_13 -> V_20 )
goto V_25;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) {
struct V_27 * V_28 = V_16 -> V_22 . V_29 + V_24 ;
if ( V_11 >= 0 && V_11 < F_6 ( V_18 , V_28 -> V_30 ) )
return ( V_11 + F_6 ( V_18 , V_28 -> V_31 ) ) ;
V_11 -= F_6 ( V_18 , V_28 -> V_30 ) ;
}
if ( ( V_11 / ( V_21 * V_21 * V_19 / 4 ) ) == 0 ) {
struct V_32 * V_33 ;
T_1 V_34 ;
T_3 * V_35 ;
V_33 = F_7 ( V_13 ,
F_6 ( V_18 , V_16 -> V_22 . V_36 [ 0 ] ) ) ;
if ( ! V_33 || ! F_8 ( V_33 ) )
goto V_37;
V_35 = ( T_3 * ) V_33 -> V_38 ;
V_34 = F_6 ( V_18 , V_35 [ ( V_11 / V_21 ) % ( V_21 * V_11 ) ] ) +
( V_11 % V_21 ) ;
F_9 ( V_33 ) ;
return V_34 ;
} else
F_2 ( V_39 L_5 ) ;
return 0 ;
V_25:
F_2 ( L_6 ) ;
V_37:
return 0 ;
}
static T_1
F_10 ( struct V_9 * V_10 , long V_35 , int V_30 , long V_40 )
{
struct V_17 * V_18 = F_5 ( V_10 -> V_14 ) ;
struct V_32 * V_41 = NULL ;
T_1 V_42 = 0 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_30 * F_11 ( V_10 -> V_14 ) ; V_24 ++ ) {
struct V_1 * V_2 ;
T_4 V_43 ;
V_41 = F_7 ( V_10 -> V_14 ,
V_35 + ( V_24 / F_11 ( V_10 -> V_14 ) ) ) ;
if ( ! V_41 || ! F_8 ( V_41 ) )
return 0 ;
V_2 = ( (struct V_1 * ) V_41 -> V_38 ) +
( V_24 % F_11 ( V_10 -> V_14 ) ) ;
V_43 = F_12 ( V_18 , V_2 -> V_4 ) & V_6 ;
if ( V_40 < V_43 ) {
F_9 ( V_41 ) ;
continue;
}
switch ( ( V_44 ) ( F_12 ( V_18 , V_2 -> V_4 ) >>
V_5 ) ) {
case V_45 :
V_42 = F_10 ( V_10 ,
F_6 ( V_18 , V_2 -> V_7 ) ,
F_6 ( V_18 , V_2 -> V_8 ) ,
V_40 - V_43 ) ;
if ( V_42 == - 2 )
break;
goto V_46;
case V_47 :
if ( ( V_40 - V_43 ) >= F_6 ( V_18 , V_2 -> V_8 ) )
break;
V_42 = F_6 ( V_18 , V_2 -> V_7 ) + V_40 - V_43 ;
goto V_46;
case V_48 :
case V_49 : {
struct V_50 * V_51 =
(struct V_50 * ) V_2 ;
F_2 ( V_52 L_7 ) ;
F_2 ( V_52 L_8 ,
F_12 ( V_18 , V_51 -> V_53 ) ,
F_12 ( V_18 , V_51 -> V_54 ) ,
F_6 ( V_18 , V_51 -> V_55 ) ) ;
goto V_56;
}
default:
F_2 ( V_57 L_9 , V_58 ,
__LINE__ , F_12 ( V_18 , V_2 -> V_4 ) ) ;
F_13 () ;
}
F_9 ( V_41 ) ;
}
V_56:
V_42 = 0 ;
V_46:
F_9 ( V_41 ) ;
return ( V_42 ) ;
}
static T_1
F_14 ( struct V_9 * V_10 , long V_59 )
{
struct V_15 * V_16 = F_4 ( V_10 ) ;
struct V_17 * V_18 = F_5 ( V_10 -> V_14 ) ;
T_1 V_42 = 0 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_60 ; V_24 ++ ) {
struct V_1 * V_2 = V_16 -> V_61 . V_62 + V_24 ;
T_5 V_63 = F_12 ( V_18 , V_2 -> V_4 ) ;
T_4 V_43 = ( V_63 & V_6 ) ;
#ifdef F_15
F_1 ( V_2 ) ;
#endif
if ( V_59 < V_43 )
continue;
switch ( ( T_2 ) ( V_63 >> V_5 ) ) {
case V_45 :
V_42 = F_10 ( V_10 ,
F_6 ( V_18 , V_2 -> V_7 ) ,
F_6 ( V_18 , V_2 -> V_8 ) ,
V_59 - V_43 ) ;
if ( V_42 == - 2 )
break;
return ( V_42 ) ;
case V_47 :
if ( ( V_59 - V_43 ) < F_6 ( V_18 , V_2 -> V_8 ) )
return ( F_6 ( V_18 , V_2 -> V_7 ) +
V_59 - V_43 ) ;
break;
case V_48 :
case V_49 : {
struct V_50 * V_51 =
(struct V_50 * ) V_2 ;
F_2 ( V_52 L_7 ) ;
F_2 ( V_52 L_8 ,
F_12 ( V_18 , V_51 -> V_53 ) ,
F_12 ( V_18 , V_51 -> V_54 ) ,
F_6 ( V_18 , V_51 -> V_55 ) ) ;
return 0 ;
}
default:
F_13 () ;
}
}
return 0 ;
}
T_1
F_16 ( struct V_9 * V_10 , long V_59 )
{
struct V_15 * V_16 = F_4 ( V_10 ) ;
if ( F_17 ( V_16 ) )
return F_3 ( V_10 , V_59 ) ;
if ( F_18 ( V_16 ) )
return F_14 ( V_10 , V_59 ) ;
if ( F_19 ( V_16 ) )
goto V_64;
if ( F_20 ( V_16 ) )
goto V_64;
F_2 ( V_39 L_10 ,
V_10 -> V_65 , V_16 -> V_66 ) ;
F_13 () ;
V_64:
F_2 ( V_39 L_11 ,
V_10 -> V_65 , V_16 -> V_66 ) ;
return 0 ;
}
