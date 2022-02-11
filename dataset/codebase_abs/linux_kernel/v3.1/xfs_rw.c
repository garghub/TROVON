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
void
F_8 (
char * V_18 ,
struct V_19 * V_1 ,
T_2 * V_20 ,
T_3 V_21 )
{
F_7 ( V_1 ,
L_7
L_8 ,
F_9 ( V_20 -> V_22 ) ,
( V_23 ) V_21 , V_18 ,
V_20 -> V_24 , F_10 ( V_20 ) ) ;
}
int
F_11 (
struct V_19 * V_1 ,
T_4 * V_25 ,
T_3 V_21 ,
int V_26 ,
T_5 V_2 ,
T_2 * * V_27 )
{
T_2 * V_20 ;
int error ;
if ( ! V_2 )
V_2 = V_28 | V_29 ;
V_20 = F_12 ( V_25 , V_21 , V_26 , V_2 ) ;
if ( ! V_20 )
return F_13 ( V_30 ) ;
error = V_20 -> V_24 ;
if ( ! error && ! F_3 ( V_1 ) ) {
* V_27 = V_20 ;
} else {
* V_27 = NULL ;
if ( error ) {
F_8 ( L_9 , V_1 , V_20 , F_14 ( V_20 ) ) ;
} else {
error = F_13 ( V_30 ) ;
}
if ( V_20 ) {
F_15 ( V_20 ) ;
F_16 ( V_20 ) ;
F_17 ( V_20 ) ;
F_18 ( V_20 ) ;
}
}
return ( error ) ;
}
T_6
F_19 (
struct V_31 * V_32 )
{
if ( ( V_32 -> V_33 . V_34 & V_35 ) && V_32 -> V_33 . V_36 )
return V_32 -> V_33 . V_36 ;
if ( F_20 ( V_32 ) )
return V_32 -> V_37 -> V_38 . V_39 ;
return 0 ;
}
