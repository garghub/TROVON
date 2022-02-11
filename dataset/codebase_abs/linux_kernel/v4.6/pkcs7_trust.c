static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_4 -> V_8 ;
struct V_9 * V_10 , * V_11 = NULL , * V_12 ;
struct V_5 * V_5 ;
bool V_13 ;
int V_14 ;
F_2 ( L_1 , V_4 -> V_15 ) ;
if ( V_4 -> V_16 ) {
F_3 ( L_2 ) ;
return - V_17 ;
}
for ( V_10 = V_4 -> V_18 ; V_10 ; V_10 = V_10 -> V_18 ) {
if ( V_10 -> V_19 ) {
if ( V_10 -> V_20 ) {
V_13 = V_10 -> V_13 ;
goto V_20;
}
F_3 ( L_3 ) ;
return - V_21 ;
}
V_10 -> V_19 = true ;
V_5 = F_4 ( V_6 ,
V_10 -> V_22 , V_10 -> V_23 ,
false ) ;
if ( ! F_5 ( V_5 ) ) {
F_6 ( L_4 ,
V_4 -> V_15 , V_10 -> V_15 , F_7 ( V_5 ) ) ;
goto V_24;
}
if ( V_5 == F_8 ( - V_25 ) )
return - V_25 ;
if ( V_10 -> V_26 == V_10 ) {
F_3 ( L_5 ) ;
return - V_21 ;
}
F_9 () ;
V_11 = V_10 ;
V_8 = & V_11 -> V_8 ;
}
if ( V_11 && ( V_11 -> V_27 || V_11 -> V_28 ) ) {
V_5 = F_4 ( V_6 ,
V_11 -> V_27 ,
V_11 -> V_28 ,
false ) ;
if ( ! F_5 ( V_5 ) ) {
V_10 = V_11 ;
F_6 ( L_6 ,
V_4 -> V_15 , V_10 -> V_15 , F_7 ( V_5 ) ) ;
goto V_24;
}
if ( F_10 ( V_5 ) != - V_21 )
return F_10 ( V_5 ) ;
}
V_5 = F_4 ( V_6 ,
V_4 -> V_29 ,
NULL ,
false ) ;
if ( ! F_5 ( V_5 ) ) {
F_6 ( L_7 ,
V_4 -> V_15 , F_7 ( V_5 ) ) ;
V_10 = NULL ;
goto V_24;
}
if ( F_10 ( V_5 ) != - V_21 )
return F_10 ( V_5 ) ;
F_3 ( L_8 ) ;
return - V_21 ;
V_24:
V_14 = F_11 ( V_5 , V_8 ) ;
V_13 = F_12 ( V_30 , & V_5 -> V_31 ) ;
F_13 ( V_5 ) ;
if ( V_14 < 0 ) {
if ( V_14 == - V_25 )
return V_14 ;
F_3 ( L_9 , V_14 ) ;
return - V_32 ;
}
V_20:
if ( V_10 ) {
V_10 -> V_20 = true ;
for ( V_12 = V_4 -> V_18 ; V_12 != V_10 ; V_12 = V_12 -> V_18 ) {
V_12 -> V_20 = true ;
V_12 -> V_13 = V_13 ;
}
}
V_4 -> V_13 = V_13 ;
F_3 ( L_10 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
bool * V_33 )
{
struct V_3 * V_4 ;
struct V_9 * V_12 ;
int V_34 = - V_21 ;
int V_14 ;
* V_33 = false ;
for ( V_12 = V_2 -> V_35 ; V_12 ; V_12 = V_12 -> V_26 )
V_12 -> V_19 = false ;
for ( V_4 = V_2 -> V_36 ; V_4 ; V_4 = V_4 -> V_26 ) {
V_14 = F_1 ( V_2 , V_4 , V_6 ) ;
switch ( V_14 ) {
case - V_21 :
continue;
case - V_17 :
if ( V_34 == - V_21 )
V_34 = - V_17 ;
continue;
case 0 :
* V_33 |= V_4 -> V_13 ;
V_34 = 0 ;
continue;
default:
return V_14 ;
}
}
return V_34 ;
}
