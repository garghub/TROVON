static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
unsigned long V_4 , V_5 ;
unsigned int V_6 ;
int V_7 ;
V_7 = F_3 ( V_3 -> V_8 ) ;
if ( V_7 < 0 ) {
F_4 ( V_3 -> V_9 , L_1 , V_7 ) ;
return V_7 ;
}
F_5 ( V_3 -> V_10 , V_11 ,
V_12 <<
V_13 ,
V_3 -> V_14 << V_13 ) ;
V_5 = F_6 ( V_3 -> V_8 ) ;
if ( V_3 -> V_14 == V_15 && V_5 != 12000000 ) {
F_4 ( V_3 -> V_9 , L_2 ,
V_5 ) ;
V_7 = - V_16 ;
goto V_17;
}
for ( V_6 = 0 ; V_6 < F_7 ( V_18 ) ; V_6 ++ ) {
if ( V_5 == V_18 [ V_6 ] )
break;
}
if ( V_6 == F_7 ( V_18 ) ) {
F_4 ( V_3 -> V_9 , L_3 , V_5 ) ;
V_7 = - V_16 ;
goto V_17;
}
F_5 ( V_3 -> V_10 , V_19 ,
V_20 <<
V_21 ,
V_6 << V_21 ) ;
V_4 = V_22 + F_8 ( 200 ) ;
while ( F_9 ( V_22 , V_4 ) ) {
unsigned int V_23 ;
F_10 ( V_3 -> V_10 , V_24 , & V_23 ) ;
if ( V_23 & V_25 ) {
F_4 ( V_3 -> V_9 , L_4 ) ;
V_7 = - V_26 ;
goto V_17;
}
if ( ( V_23 & V_27 ) &&
( V_23 & V_28 ) )
return 0 ;
F_11 ( 1000 , 1500 ) ;
}
F_4 ( V_3 -> V_9 , L_5 ) ;
V_7 = - V_29 ;
V_17:
F_12 ( V_3 -> V_8 ) ;
return V_7 ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_12 ( V_3 -> V_8 ) ;
return 0 ;
}
static int F_14 ( struct V_30 * V_31 )
{
struct V_2 * V_3 ;
struct V_32 * V_33 ;
struct V_1 * V_1 ;
int V_7 ;
V_3 = F_15 ( & V_31 -> V_9 , sizeof( * V_3 ) , V_34 ) ;
if ( ! V_3 )
return - V_35 ;
V_3 -> V_9 = & V_31 -> V_9 ;
F_16 ( V_31 , V_3 ) ;
V_3 -> V_10 = F_17 ( V_3 -> V_9 -> V_36 ,
L_6 ) ;
if ( F_18 ( V_3 -> V_10 ) ) {
F_4 ( V_3 -> V_9 , L_7 ,
F_19 ( V_3 -> V_10 ) ) ;
return F_19 ( V_3 -> V_10 ) ;
}
V_3 -> V_8 = F_20 ( V_3 -> V_9 , L_8 ) ;
if ( F_18 ( V_3 -> V_8 ) ) {
F_4 ( V_3 -> V_9 , L_9 ,
F_19 ( V_3 -> V_8 ) ) ;
return F_19 ( V_3 -> V_8 ) ;
}
V_7 = F_21 ( V_3 -> V_9 -> V_36 , L_10 ,
& V_3 -> V_14 ) ;
if ( V_7 < 0 ) {
F_4 ( V_3 -> V_9 , L_11 ) ;
return V_7 ;
}
V_1 = F_22 ( V_3 -> V_9 , NULL , & V_37 ) ;
if ( F_18 ( V_1 ) ) {
F_4 ( V_3 -> V_9 , L_12 ,
F_19 ( V_1 ) ) ;
return F_19 ( V_1 ) ;
}
F_23 ( V_1 , V_3 ) ;
V_33 = F_24 ( V_3 -> V_9 ,
V_38 ) ;
if ( F_18 ( V_33 ) ) {
F_4 ( V_3 -> V_9 , L_13 ,
F_19 ( V_33 ) ) ;
return F_19 ( V_33 ) ;
}
return 0 ;
}
