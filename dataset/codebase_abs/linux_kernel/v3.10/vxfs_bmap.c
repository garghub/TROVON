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
unsigned long V_17 = V_13 -> V_18 ;
T_2 V_19 = V_16 -> V_20 . V_21 ;
int V_22 ;
if ( V_19 > V_13 -> V_18 )
goto V_23;
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ ) {
struct V_25 * V_26 = V_16 -> V_20 . V_27 + V_22 ;
if ( V_11 >= 0 && V_11 < V_26 -> V_28 )
return ( V_11 + V_26 -> V_29 ) ;
V_11 -= V_26 -> V_28 ;
}
if ( ( V_11 / ( V_19 * V_19 * V_17 / 4 ) ) == 0 ) {
struct V_30 * V_31 ;
T_1 V_32 ;
T_2 * V_33 ;
V_31 = F_5 ( V_13 , V_16 -> V_20 . V_34 [ 0 ] ) ;
if ( ! V_31 || ! F_6 ( V_31 ) )
goto V_35;
V_33 = ( T_2 * ) V_31 -> V_36 ;
V_32 = V_33 [ ( V_11 / V_19 ) % ( V_19 * V_11 ) ] + ( V_11 % V_19 ) ;
F_7 ( V_31 ) ;
return V_32 ;
} else
F_2 ( V_37 L_5 ) ;
return 0 ;
V_23:
F_2 ( L_6 ) ;
V_35:
return 0 ;
}
static T_1
F_8 ( struct V_9 * V_10 , long V_33 , int V_28 , long V_38 )
{
struct V_30 * V_39 = NULL ;
T_1 V_40 = 0 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_28 * F_9 ( V_10 -> V_14 ) ; V_22 ++ ) {
struct V_1 * V_2 ;
T_3 V_41 ;
V_39 = F_5 ( V_10 -> V_14 ,
V_33 + ( V_22 / F_9 ( V_10 -> V_14 ) ) ) ;
if ( ! V_39 || ! F_6 ( V_39 ) )
return 0 ;
V_2 = ( (struct V_1 * ) V_39 -> V_36 ) +
( V_22 % F_9 ( V_10 -> V_14 ) ) ;
V_41 = ( V_2 -> V_4 & V_6 ) ;
if ( V_38 < V_41 ) {
F_7 ( V_39 ) ;
continue;
}
switch ( ( V_42 ) ( V_2 -> V_4 >> V_5 ) ) {
case V_43 :
V_40 = F_8 ( V_10 , V_2 -> V_7 ,
V_2 -> V_8 , V_38 - V_41 ) ;
if ( V_40 == - 2 )
break;
goto V_44;
case V_45 :
if ( ( V_38 - V_41 ) >= V_2 -> V_8 )
break;
V_40 = ( V_2 -> V_7 + V_38 - V_41 ) ;
goto V_44;
case V_46 :
case V_47 : {
struct V_48 * V_49 =
(struct V_48 * ) V_2 ;
F_2 ( V_50 L_7 ) ;
F_2 ( V_50 L_8 ,
( unsigned long long ) V_49 -> V_51 ,
( unsigned long long ) V_49 -> V_52 ,
V_49 -> V_53 ) ;
goto V_54;
}
default:
F_10 () ;
}
F_7 ( V_39 ) ;
}
V_54:
V_40 = 0 ;
V_44:
F_7 ( V_39 ) ;
return ( V_40 ) ;
}
static T_1
F_11 ( struct V_9 * V_10 , long V_55 )
{
struct V_15 * V_16 = F_4 ( V_10 ) ;
T_1 V_40 = 0 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_56 ; V_22 ++ ) {
struct V_1 * V_2 = V_16 -> V_57 . V_58 + V_22 ;
T_3 V_41 = ( V_2 -> V_4 & V_6 ) ;
#ifdef F_12
F_1 ( V_2 ) ;
#endif
if ( V_55 < V_41 )
continue;
switch ( ( V_42 ) ( V_2 -> V_4 >> V_5 ) ) {
case V_43 :
V_40 = F_8 ( V_10 , V_2 -> V_7 ,
V_2 -> V_8 , V_55 - V_41 ) ;
if ( V_40 == - 2 )
break;
return ( V_40 ) ;
case V_45 :
if ( ( V_55 - V_41 ) < V_2 -> V_8 )
return ( V_2 -> V_7 + V_55 - V_41 ) ;
break;
case V_46 :
case V_47 : {
struct V_48 * V_49 =
(struct V_48 * ) V_2 ;
F_2 ( V_50 L_7 ) ;
F_2 ( V_50 L_8 ,
( unsigned long long ) V_49 -> V_51 ,
( unsigned long long ) V_49 -> V_52 ,
V_49 -> V_53 ) ;
return 0 ;
}
default:
F_10 () ;
}
}
return 0 ;
}
T_1
F_13 ( struct V_9 * V_10 , long V_55 )
{
struct V_15 * V_16 = F_4 ( V_10 ) ;
if ( F_14 ( V_16 ) )
return F_3 ( V_10 , V_55 ) ;
if ( F_15 ( V_16 ) )
return F_11 ( V_10 , V_55 ) ;
if ( F_16 ( V_16 ) )
goto V_59;
if ( F_17 ( V_16 ) )
goto V_59;
F_2 ( V_37 L_9 ,
V_10 -> V_60 , V_16 -> V_61 ) ;
F_10 () ;
V_59:
F_2 ( V_37 L_10 ,
V_10 -> V_60 , V_16 -> V_61 ) ;
return 0 ;
}
