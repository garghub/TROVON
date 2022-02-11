static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_10 , * V_11 = NULL , * V_12 ;
struct V_5 * V_5 ;
int V_13 ;
F_2 ( L_1 , V_4 -> V_14 ) ;
if ( V_4 -> V_15 ) {
F_3 ( L_2 ) ;
return - V_16 ;
}
for ( V_10 = V_4 -> V_17 ; V_10 ; V_10 = V_10 -> V_17 ) {
if ( V_10 -> V_18 ) {
if ( V_10 -> V_19 )
goto V_19;
F_3 ( L_3 ) ;
return - V_20 ;
}
V_10 -> V_18 = true ;
V_5 = F_4 ( V_6 ,
V_10 -> V_21 , V_10 -> V_22 , false ) ;
if ( ! F_5 ( V_5 ) ) {
F_6 ( L_4 ,
V_4 -> V_14 , V_10 -> V_14 , F_7 ( V_5 ) ) ;
goto V_23;
}
if ( V_5 == F_8 ( - V_24 ) )
return - V_24 ;
if ( V_10 -> V_25 == V_10 ) {
F_3 ( L_5 ) ;
return - V_20 ;
}
F_9 () ;
V_11 = V_10 ;
V_8 = V_11 -> V_8 ;
}
if ( V_11 && ( V_11 -> V_8 -> V_26 [ 0 ] || V_11 -> V_8 -> V_26 [ 1 ] ) ) {
V_5 = F_4 ( V_6 ,
V_11 -> V_8 -> V_26 [ 0 ] ,
V_11 -> V_8 -> V_26 [ 1 ] ,
false ) ;
if ( ! F_5 ( V_5 ) ) {
V_10 = V_11 ;
F_6 ( L_6 ,
V_4 -> V_14 , V_10 -> V_14 , F_7 ( V_5 ) ) ;
goto V_23;
}
if ( F_10 ( V_5 ) != - V_20 )
return F_10 ( V_5 ) ;
}
V_5 = F_4 ( V_6 ,
V_4 -> V_8 -> V_26 [ 0 ] , NULL , false ) ;
if ( ! F_5 ( V_5 ) ) {
F_6 ( L_7 ,
V_4 -> V_14 , F_7 ( V_5 ) ) ;
V_10 = NULL ;
goto V_23;
}
if ( F_10 ( V_5 ) != - V_20 )
return F_10 ( V_5 ) ;
F_3 ( L_8 ) ;
return - V_20 ;
V_23:
V_13 = F_11 ( V_5 , V_8 ) ;
F_12 ( V_5 ) ;
if ( V_13 < 0 ) {
if ( V_13 == - V_24 )
return V_13 ;
F_3 ( L_9 , V_13 ) ;
return - V_27 ;
}
V_19:
if ( V_10 ) {
V_10 -> V_19 = true ;
for ( V_12 = V_4 -> V_17 ; V_12 != V_10 ; V_12 = V_12 -> V_17 )
V_12 -> V_19 = true ;
}
F_3 ( L_10 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_3 * V_4 ;
struct V_9 * V_12 ;
int V_28 = - V_20 ;
int V_13 ;
for ( V_12 = V_2 -> V_29 ; V_12 ; V_12 = V_12 -> V_25 )
V_12 -> V_18 = false ;
for ( V_4 = V_2 -> V_30 ; V_4 ; V_4 = V_4 -> V_25 ) {
V_13 = F_1 ( V_2 , V_4 , V_6 ) ;
switch ( V_13 ) {
case - V_20 :
continue;
case - V_16 :
if ( V_28 == - V_20 )
V_28 = - V_16 ;
continue;
case 0 :
V_28 = 0 ;
continue;
default:
return V_13 ;
}
}
return V_28 ;
}
