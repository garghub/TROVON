static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
const struct V_3 * V_8 ;
V_8 = F_2 ( V_4 , V_6 ) ;
if ( ! V_8 )
return - V_9 ;
V_2 -> V_10 = V_8 -> V_11 ;
V_7 = F_3 ( V_6 , L_1 ,
& V_2 -> V_12 ) ;
if ( V_7 ) {
T_1 V_13 , V_12 ;
V_7 = F_3 ( V_6 , L_2 ,
& V_13 ) ;
if ( V_7 ) {
F_4 ( L_3 ,
V_6 -> V_14 ) ;
return - V_15 ;
}
V_7 = F_3 ( V_6 , L_4 ,
& V_12 ) ;
if ( V_7 ) {
F_4 ( L_5 ,
V_6 -> V_14 ) ;
return - V_15 ;
}
V_2 -> V_12 = V_13 + V_12 ;
}
V_7 = F_3 ( V_6 , L_6 ,
& V_2 -> V_16 ) ;
if ( V_7 ) {
F_4 ( L_7 ,
V_6 -> V_14 ) ;
return - V_15 ;
}
V_2 -> V_17 = V_18 ;
if ( F_5 ( V_6 , L_8 ) )
V_2 -> V_17 |= V_19 ;
strncpy ( V_2 -> V_20 , V_6 -> V_20 , V_21 - 1 ) ;
strncpy ( V_2 -> V_22 , V_6 -> V_20 , V_23 - 1 ) ;
return 0 ;
}
static bool F_6 ( struct V_5 * V_6 , unsigned int V_24 ,
const T_2 * V_25 )
{
int V_26 ;
struct V_5 * V_27 , * V_28 ;
bool V_29 = true ;
for ( V_26 = F_7 ( F_8 ( V_25 ) , V_25 ) ;
V_26 < V_30 ; V_26 = F_7 ( V_26 , V_25 ) ) {
V_27 = F_9 ( V_26 ) ;
V_28 = F_10 ( V_27 , L_9 ,
V_24 ) ;
if ( V_6 != V_28 )
V_29 = false ;
F_11 ( V_28 ) ;
F_11 ( V_27 ) ;
if ( ! V_29 )
break;
}
return V_29 ;
}
int F_12 ( struct V_31 * V_32 ,
const struct V_3 * V_4 ,
unsigned int V_33 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 , * V_27 ;
int V_34 , V_7 = 0 ;
const T_2 * V_25 ;
unsigned int V_35 = V_33 ;
if ( V_35 >= V_36 )
return - V_15 ;
V_25 = V_32 -> V_25 ? : V_37 ;
V_27 = F_9 ( F_8 ( V_25 ) ) ;
for ( V_34 = 0 ; ; V_34 ++ ) {
V_6 = F_10 ( V_27 , L_9 , V_34 ) ;
if ( ! V_6 )
break;
if ( ! F_6 ( V_6 , V_34 , V_25 ) ) {
F_13 ( L_10 ,
V_6 -> V_14 ) ;
V_7 = - V_15 ;
break;
}
if ( V_35 == V_36 ) {
F_13 ( L_11 ) ;
break;
}
V_2 = & V_32 -> V_38 [ V_35 ++ ] ;
V_7 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_7 ) {
F_14 ( L_12 ,
V_6 -> V_14 , V_7 ) ;
V_7 = - V_15 ;
break;
}
F_11 ( V_6 ) ;
}
F_11 ( V_6 ) ;
F_11 ( V_27 ) ;
if ( V_7 )
return V_7 ;
if ( V_34 )
V_32 -> V_39 = V_35 ;
return V_34 ;
}
