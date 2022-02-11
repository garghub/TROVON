int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 , unsigned * V_5 )
{
struct V_6 * V_7 ;
unsigned long V_8 ;
int V_9 ;
if ( V_2 == NULL )
return - V_10 ;
if ( V_2 -> V_11 == NULL )
return - V_10 ;
F_2 ( & V_2 -> V_12 ) ;
V_9 = - V_10 ;
V_7 = F_3 ( V_2 , V_3 ) ;
if ( ! V_7 )
goto V_13;
if ( V_3 < V_7 -> V_14 ) {
if ( ! ( V_7 -> V_15 & V_16 ) )
goto V_13;
if ( F_4 ( V_7 , V_3 ) )
goto V_13;
}
V_8 = V_4 & V_17 ;
if ( V_8 ) {
if ( ! ( V_7 -> V_15 & V_18 ) )
goto V_13;
} else {
if ( ! ( V_7 -> V_15 & ( V_19 | V_20 ) ) )
goto V_13;
F_5 ( V_4 & V_21 ) ;
}
V_9 = 0 ;
* V_5 = F_6 ( V_7 , V_3 , V_8 ? V_22 : 0 ) ;
if ( F_7 ( * V_5 & V_23 ) ) {
if ( * V_5 & V_24 ) {
V_9 = - V_25 ;
goto V_13;
} else if ( * V_5 & ( V_26 | V_27 ) ) {
V_9 = - V_10 ;
goto V_13;
}
F_8 () ;
}
if ( * V_5 & V_28 )
V_29 -> V_30 ++ ;
else
V_29 -> V_31 ++ ;
V_13:
F_9 ( & V_2 -> V_12 ) ;
return V_9 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_3 , struct V_32 * V_33 )
{
T_1 V_34 , V_35 ;
int V_36 , V_37 ;
switch ( F_11 ( V_3 ) ) {
case V_38 :
F_12 ( L_1 , V_39 , V_3 ) ;
if ( V_2 == NULL )
return 1 ;
V_36 = F_13 ( V_2 , V_3 ) ;
V_37 = F_14 ( V_3 ) ;
V_34 = F_15 ( V_2 -> V_40 . V_41 , V_3 , V_37 ) ;
V_35 = V_42 ;
break;
case V_43 :
F_12 ( L_2 , V_39 , V_3 ) ;
if ( V_3 < V_44 )
V_36 = V_45 ;
else
V_36 = V_46 ;
V_37 = V_47 ;
V_34 = F_16 ( V_3 , V_47 ) ;
V_35 = V_48 ;
break;
case V_49 :
F_12 ( L_3 , V_39 , V_3 ) ;
V_36 = V_50 ;
V_37 = V_47 ;
V_34 = F_16 ( V_3 , V_47 ) ;
V_35 = V_48 ;
break;
default:
F_17 ( L_4 , V_39 , V_3 ) ;
return 1 ;
}
V_34 = ( V_34 << F_18 ( V_37 ) ) | V_35 ;
V_34 |= V_51 [ V_36 ] . V_52 |
( ( V_37 == V_53 ) ? V_54 : 0 ) ;
V_33 -> V_55 = ( V_3 & ( V_37 == V_53 ? V_56 : V_57 ) ) | V_58 ;
V_33 -> V_34 = V_34 ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
#ifdef F_20
F_21 ( V_2 ) ;
#endif
F_22 ( V_2 ) ;
}
