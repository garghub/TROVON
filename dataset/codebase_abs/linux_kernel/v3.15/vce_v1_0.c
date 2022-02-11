T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_5 == V_6 )
return F_2 ( V_7 ) ;
else
return F_2 ( V_8 ) ;
}
T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_5 == V_6 )
return F_2 ( V_9 ) ;
else
return F_2 ( V_10 ) ;
}
void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_5 == V_6 )
F_5 ( V_9 , V_4 -> V_11 ) ;
else
F_5 ( V_10 , V_4 -> V_11 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_12 , V_13 , V_14 ;
F_7 ( V_15 , 1 , ~ 1 ) ;
V_4 = & V_2 -> V_4 [ V_6 ] ;
F_5 ( V_7 , V_4 -> V_11 ) ;
F_5 ( V_9 , V_4 -> V_11 ) ;
F_5 ( V_16 , V_4 -> V_17 ) ;
F_5 ( V_18 , F_8 ( V_4 -> V_17 ) ) ;
F_5 ( V_19 , V_4 -> V_20 / 4 ) ;
V_4 = & V_2 -> V_4 [ V_21 ] ;
F_5 ( V_8 , V_4 -> V_11 ) ;
F_5 ( V_10 , V_4 -> V_11 ) ;
F_5 ( V_22 , V_4 -> V_17 ) ;
F_5 ( V_23 , F_8 ( V_4 -> V_17 ) ) ;
F_5 ( V_24 , V_4 -> V_20 / 4 ) ;
F_7 ( V_25 , V_26 , ~ V_26 ) ;
F_7 ( V_27 ,
V_28 |
V_29 , ~ (
V_28 |
V_29 ) ) ;
F_9 ( 100 ) ;
F_7 ( V_27 , 0 , ~ (
V_28 |
V_29 ) ) ;
for ( V_12 = 0 ; V_12 < 10 ; ++ V_12 ) {
T_1 V_30 ;
for ( V_13 = 0 ; V_13 < 100 ; ++ V_13 ) {
V_30 = F_2 ( V_15 ) ;
if ( V_30 & 2 )
break;
F_9 ( 10 ) ;
}
V_14 = 0 ;
if ( V_30 & 2 )
break;
F_10 ( L_1 ) ;
F_7 ( V_27 , V_28 , ~ V_28 ) ;
F_9 ( 10 ) ;
F_7 ( V_27 , 0 , ~ V_28 ) ;
F_9 ( 10 ) ;
V_14 = - 1 ;
}
F_7 ( V_15 , 0 , ~ 1 ) ;
if ( V_14 ) {
F_10 ( L_2 ) ;
return V_14 ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_14 ;
V_14 = F_6 ( V_2 ) ;
if ( V_14 )
return V_14 ;
V_4 = & V_2 -> V_4 [ V_6 ] ;
V_4 -> V_31 = true ;
V_14 = F_12 ( V_2 , V_6 , V_4 ) ;
if ( V_14 ) {
V_4 -> V_31 = false ;
return V_14 ;
}
V_4 = & V_2 -> V_4 [ V_21 ] ;
V_4 -> V_31 = true ;
V_14 = F_12 ( V_2 , V_21 , V_4 ) ;
if ( V_14 ) {
V_4 -> V_31 = false ;
return V_14 ;
}
F_13 ( L_3 ) ;
return 0 ;
}
