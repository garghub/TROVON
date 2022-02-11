static int F_1 ( unsigned long * V_1 , void * * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 ;
struct V_6 V_7 ;
struct V_8 V_9 ;
int V_10 = 0 ;
V_7 . V_11 = F_2 ( V_3 ) ;
if ( ! V_7 . V_11 ) {
V_10 = - V_12 ;
goto V_13;
}
V_7 . V_14 = V_3 ;
V_7 . V_15 = 0 ;
V_7 . V_16 = sizeof( V_9 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_17 = 1 ;
F_3 (qe, &ima_measurements, later) {
if ( V_7 . V_16 < V_7 . V_14 ) {
V_9 . V_16 ++ ;
F_4 ( & V_7 , V_5 ) ;
} else {
V_10 = - V_18 ;
break;
}
}
if ( V_10 < 0 )
goto V_13;
V_9 . V_1 = V_7 . V_16 ;
if ( V_19 ) {
V_9 . V_17 = F_5 ( V_9 . V_17 ) ;
V_9 . V_16 = F_6 ( V_9 . V_16 ) ;
V_9 . V_1 = F_6 ( V_9 . V_1 ) ;
}
memcpy ( V_7 . V_11 , & V_9 , sizeof( V_9 ) ) ;
F_7 ( V_20 , L_1 , V_21 ,
16 , 1 , V_7 . V_11 ,
V_7 . V_16 < 100 ? V_7 . V_16 : 100 , true ) ;
* V_1 = V_7 . V_16 ;
* V_2 = V_7 . V_11 ;
V_13:
if ( V_10 == - V_18 )
F_8 ( V_7 . V_11 ) ;
return V_10 ;
}
void F_9 ( struct V_22 * V_23 )
{
struct V_24 V_25 = { . V_23 = V_23 , . V_26 = V_27 ,
. V_28 = 0 , . V_29 = V_30 ,
. V_31 = true } ;
unsigned long V_32 ;
void * V_33 = NULL ;
T_1 V_34 ;
T_1 V_35 ;
int V_10 ;
V_32 = F_10 () ;
if ( V_32 >= V_30 - V_27 )
V_35 = V_30 ;
else
V_35 = F_11 ( F_10 () +
V_27 / 2 , V_27 ) ;
if ( ( V_35 == V_30 ) ||
( ( V_35 >> V_36 ) > V_37 / 2 ) ) {
F_12 ( L_2 ) ;
return;
}
F_1 ( & V_34 , & V_33 ,
V_35 ) ;
if ( ! V_33 ) {
F_12 ( L_3 ) ;
return;
}
V_25 . V_2 = V_33 ;
V_25 . V_38 = V_34 ;
V_25 . V_39 = V_35 ;
V_10 = F_13 ( & V_25 ) ;
if ( V_10 ) {
F_12 ( L_4 ) ;
return;
}
V_10 = F_14 ( V_23 , V_25 . V_40 , V_35 ) ;
if ( V_10 ) {
F_12 ( L_4 ) ;
return;
}
F_15 ( L_5 ,
V_25 . V_40 ) ;
}
void F_16 ( void )
{
void * V_33 = NULL ;
T_1 V_34 = 0 ;
int V_41 ;
V_41 = F_17 ( & V_33 , & V_34 ) ;
switch ( V_41 ) {
case 0 :
V_41 = F_18 ( V_34 ,
V_33 ) ;
if ( V_41 != 0 )
F_12 ( L_6 ,
V_41 ) ;
F_19 () ;
break;
case - V_42 :
F_15 ( L_7 ) ;
break;
case - V_43 :
F_15 ( L_8 ) ;
break;
default:
F_15 ( L_9 , V_41 ) ;
}
}
