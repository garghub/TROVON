void
F_1 (
T_1 * V_1 ,
int V_2 ,
char * V_3 ,
int V_4 )
{
int V_5 ;
V_5 = V_2 & V_6 ;
if ( ! ( V_2 & V_7 ) ) {
F_2 ( V_1 ,
L_1 ,
V_8 , V_2 , V_4 , V_3 , V_9 ) ;
}
if ( F_3 ( V_1 ) && ! V_5 )
return;
if ( F_4 ( V_1 , V_5 ) )
return;
if ( V_2 & V_10 ) {
F_5 ( V_1 , V_11 ,
L_2 ) ;
if ( V_12 <= V_13 )
F_6 () ;
} else if ( ! ( V_2 & V_7 ) ) {
if ( V_5 ) {
F_5 ( V_1 , V_14 ,
L_3 ) ;
} else if ( V_2 & V_15 ) {
F_5 ( V_1 , V_16 ,
L_4 ) ;
} else if ( ! ( V_2 & V_17 ) ) {
F_5 ( V_1 , V_16 ,
L_5 ) ;
}
}
if ( ! ( V_2 & V_7 ) ) {
F_7 ( V_1 ,
L_6 ) ;
}
}
int
F_8 (
struct V_18 * V_1 ,
T_2 * V_19 ,
T_3 V_20 ,
int V_21 ,
T_4 V_2 ,
T_5 * * V_22 )
{
T_5 * V_23 ;
int error ;
if ( ! V_2 )
V_2 = V_24 | V_25 ;
V_23 = F_9 ( V_19 , V_20 , V_21 , V_2 ) ;
if ( ! V_23 )
return F_10 ( V_26 ) ;
error = V_23 -> V_27 ;
if ( ! error && ! F_3 ( V_1 ) ) {
* V_22 = V_23 ;
} else {
* V_22 = NULL ;
if ( error ) {
F_11 ( V_23 , V_8 ) ;
} else {
error = F_10 ( V_26 ) ;
}
if ( V_23 ) {
F_12 ( V_23 ) ;
F_13 ( V_23 ) ;
F_14 ( V_23 ) ;
}
}
return ( error ) ;
}
T_6
F_15 (
struct V_28 * V_29 )
{
if ( ( V_29 -> V_30 . V_31 & V_32 ) && V_29 -> V_30 . V_33 )
return V_29 -> V_30 . V_33 ;
if ( F_16 ( V_29 ) )
return V_29 -> V_34 -> V_35 . V_36 ;
return 0 ;
}
