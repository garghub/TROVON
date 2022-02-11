static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
const struct V_3 * V_8 ;
const char * V_9 ;
V_8 = F_2 ( V_4 , V_6 ) ;
if ( ! V_8 )
return - V_10 ;
V_2 -> V_11 = V_8 -> V_12 ;
V_2 -> V_13 = V_8 -> V_12 ;
V_7 = F_3 ( V_6 , L_1 ,
& V_2 -> V_14 ) ;
if ( V_7 ) {
T_1 V_15 , V_14 ;
V_7 = F_3 ( V_6 , L_2 ,
& V_15 ) ;
if ( V_7 ) {
F_4 ( L_3 ,
V_6 ) ;
return - V_16 ;
}
V_7 = F_3 ( V_6 , L_4 ,
& V_14 ) ;
if ( V_7 ) {
F_4 ( L_5 ,
V_6 ) ;
return - V_16 ;
}
V_2 -> V_14 = V_15 + V_14 ;
}
V_7 = F_3 ( V_6 , L_6 ,
& V_2 -> V_17 ) ;
if ( V_7 ) {
F_4 ( L_7 ,
V_6 ) ;
return - V_16 ;
}
V_7 = F_5 ( V_6 , L_8 , & V_9 ) ;
if ( V_7 )
V_9 = V_6 -> V_18 ;
V_2 -> V_19 = 0 ;
if ( F_6 ( V_6 , L_9 ) )
V_2 -> V_19 |= V_20 ;
strncpy ( V_2 -> V_18 , V_6 -> V_18 , V_21 - 1 ) ;
strncpy ( V_2 -> V_9 , V_9 , V_22 - 1 ) ;
return 0 ;
}
static bool F_7 ( struct V_5 * V_6 , unsigned int V_23 ,
const T_2 * V_24 )
{
int V_25 ;
struct V_5 * V_26 , * V_27 ;
bool V_28 = true ;
for ( V_25 = F_8 ( F_9 ( V_24 ) , V_24 ) ;
V_25 < V_29 ; V_25 = F_8 ( V_25 , V_24 ) ) {
V_26 = F_10 ( V_25 ) ;
V_27 = F_11 ( V_26 , L_10 ,
V_23 ) ;
if ( V_6 != V_27 )
V_28 = false ;
F_12 ( V_27 ) ;
F_12 ( V_26 ) ;
if ( ! V_28 )
break;
}
return V_28 ;
}
int F_13 ( struct V_30 * V_31 ,
const struct V_3 * V_4 ,
unsigned int V_32 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 , * V_26 ;
int V_33 , V_7 = 0 ;
const T_2 * V_24 ;
unsigned int V_34 = V_32 ;
if ( V_34 >= V_35 )
return - V_16 ;
V_24 = V_31 -> V_24 ? : V_36 ;
V_26 = F_10 ( F_9 ( V_24 ) ) ;
for ( V_33 = 0 ; ; V_33 ++ ) {
V_6 = F_11 ( V_26 , L_10 , V_33 ) ;
if ( ! V_6 )
break;
if ( ! F_14 ( V_6 ) ) {
F_12 ( V_6 ) ;
continue;
}
if ( ! F_7 ( V_6 , V_33 , V_24 ) ) {
F_15 ( L_11 ,
V_6 ) ;
V_7 = - V_16 ;
break;
}
if ( V_34 == V_35 ) {
F_15 ( L_12 ) ;
break;
}
V_2 = & V_31 -> V_37 [ V_34 ++ ] ;
V_7 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_7 ) {
F_16 ( L_13 ,
V_6 , V_7 ) ;
V_7 = - V_16 ;
break;
}
F_12 ( V_6 ) ;
}
F_12 ( V_6 ) ;
F_12 ( V_26 ) ;
if ( V_7 )
return V_7 ;
if ( V_33 )
V_31 -> V_38 = V_34 ;
return V_33 ;
}
