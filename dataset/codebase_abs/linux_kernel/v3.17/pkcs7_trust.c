int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_4 -> V_8 ;
struct V_9 * V_10 , * V_11 = NULL , * V_12 ;
struct V_5 * V_5 ;
bool V_13 ;
int V_14 ;
F_2 ( L_1 , V_4 -> V_15 ) ;
for ( V_10 = V_4 -> V_16 ; V_10 ; V_10 = V_10 -> V_16 ) {
if ( V_10 -> V_17 ) {
if ( V_10 -> V_18 ) {
V_13 = V_10 -> V_13 ;
goto V_18;
}
F_3 ( L_2 ) ;
return - V_19 ;
}
V_10 -> V_17 = true ;
V_5 = F_4 ( V_6 , V_10 -> V_20 ,
V_10 -> V_21 ) ;
if ( ! F_5 ( V_5 ) )
goto V_22;
if ( V_5 == F_6 ( - V_23 ) )
return - V_23 ;
if ( V_10 -> V_24 == V_10 ) {
F_3 ( L_3 ) ;
return - V_19 ;
}
F_7 () ;
V_11 = V_10 ;
V_8 = & V_11 -> V_8 ;
}
if ( ! V_11 || ! V_11 -> V_25 || ! V_11 -> V_26 ) {
F_3 ( L_4 ) ;
return - V_19 ;
}
V_5 = F_4 ( V_6 , V_11 -> V_25 ,
V_11 -> V_26 ) ;
if ( F_5 ( V_5 ) )
return F_8 ( V_5 ) == - V_23 ? - V_23 : - V_19 ;
V_10 = V_11 ;
V_22:
V_14 = F_9 ( V_5 , V_8 ) ;
V_13 = F_10 ( V_27 , & V_5 -> V_28 ) ;
F_11 ( V_5 ) ;
if ( V_14 < 0 ) {
if ( V_14 == - V_23 )
return V_14 ;
F_3 ( L_5 , V_14 ) ;
return - V_29 ;
}
V_18:
V_10 -> V_18 = true ;
for ( V_12 = V_4 -> V_16 ; V_12 != V_10 ; V_12 = V_12 -> V_16 ) {
V_12 -> V_18 = true ;
V_12 -> V_13 = V_13 ;
}
V_4 -> V_13 = V_13 ;
F_3 ( L_6 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
bool * V_30 )
{
struct V_3 * V_4 ;
struct V_9 * V_12 ;
int V_31 = 0 , V_14 ;
for ( V_12 = V_2 -> V_32 ; V_12 ; V_12 = V_12 -> V_24 )
V_12 -> V_17 = false ;
for ( V_4 = V_2 -> V_33 ; V_4 ; V_4 = V_4 -> V_24 ) {
V_14 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_14 < 0 ) {
if ( V_14 == - V_34 ) {
V_31 = - V_34 ;
} else if ( V_14 == - V_19 ) {
if ( V_31 == 0 )
V_31 = - V_19 ;
} else {
return V_14 ;
}
}
* V_30 |= V_4 -> V_13 ;
}
return V_31 ;
}
