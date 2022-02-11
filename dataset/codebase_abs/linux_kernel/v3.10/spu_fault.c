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
if ( V_4 & V_19 )
goto V_13;
if ( ! ( V_7 -> V_15 & ( V_20 | V_21 ) ) )
goto V_13;
}
V_9 = 0 ;
* V_5 = F_5 ( V_2 , V_7 , V_3 , V_8 ? V_22 : 0 ) ;
if ( F_6 ( * V_5 & V_23 ) ) {
if ( * V_5 & V_24 ) {
V_9 = - V_25 ;
goto V_13;
} else if ( * V_5 & V_26 ) {
V_9 = - V_10 ;
goto V_13;
}
F_7 () ;
}
if ( * V_5 & V_27 )
V_28 -> V_29 ++ ;
else
V_28 -> V_30 ++ ;
V_13:
F_8 ( & V_2 -> V_12 ) ;
return V_9 ;
}
