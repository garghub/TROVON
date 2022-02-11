static int F_1 ( int V_1 , int V_2 ,
void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( V_1 ^ V_2 ) {
void T_1 * V_6 = F_2 ( V_5 -> V_7 , V_5 -> V_8 ) ;
if ( ! V_6 )
return - V_9 ;
switch ( V_5 -> V_8 ) {
case sizeof( V_10 ) : {
V_10 V_11 , V_12 ;
V_11 = F_3 ( V_6 ) ;
V_12 = ( V_11 & ~ V_5 -> V_13 ) | V_2 ;
if ( V_11 != V_12 ) {
F_4 ( ( V_11 & ~ V_5 -> V_13 ) | V_2 , V_6 ) ;
F_5 ( L_1 , V_14 , V_11 , V_12 ) ;
}
break;
}
case sizeof( V_15 ) : {
V_15 V_11 , V_12 ;
V_11 = F_6 ( V_6 ) ;
V_12 = ( V_11 & ~ V_5 -> V_13 ) | V_2 ;
if ( V_11 != V_12 ) {
F_7 ( ( V_11 & ~ V_5 -> V_13 ) | V_2 , V_6 ) ;
F_5 ( L_2 , V_14 , V_11 , V_12 ) ;
}
break;
}
case sizeof( V_16 ) : {
V_16 V_11 , V_12 ;
V_11 = F_8 ( V_6 ) ;
V_12 = ( V_11 & ~ V_5 -> V_13 ) | V_2 ;
if ( V_11 != V_12 ) {
F_9 ( ( V_11 & ~ V_5 -> V_13 ) | V_2 , V_6 ) ;
F_5 ( L_3 , V_14 , V_11 , V_12 ) ;
}
break;
}
}
F_10 ( V_6 ) ;
}
return 0 ;
}
static int F_11 ( struct V_17 * V_18 )
{
struct V_19 * V_20 , * V_21 = V_18 -> V_22 . V_23 ;
struct V_4 * V_5 ;
struct V_24 V_25 ;
const T_2 * V_26 ;
int V_27 , V_28 ;
F_12 ( & V_18 -> V_22 , L_4 , V_21 ) ;
V_5 = F_13 ( & V_18 -> V_22 , sizeof( * V_5 ) , V_29 ) ;
if ( ! V_5 )
return - V_9 ;
V_28 = F_14 ( V_21 , 0 , & V_25 ) ;
if ( V_28 ) {
F_15 ( & V_18 -> V_22 , L_5 ,
V_21 ) ;
return V_28 ;
}
V_5 -> V_7 = V_25 . V_30 ;
V_5 -> V_8 = F_16 ( & V_25 ) ;
if ( V_5 -> V_8 != sizeof( V_10 ) &&
V_5 -> V_8 != sizeof( V_15 ) &&
V_5 -> V_8 != sizeof( V_16 ) ) {
F_15 ( & V_18 -> V_22 , L_6 ) ;
return - V_31 ;
}
V_26 = F_17 ( V_21 , L_7 , & V_27 ) ;
if ( ! V_26 || V_27 != sizeof( V_16 ) ) {
F_15 ( & V_18 -> V_22 , L_8 ) ;
return - V_32 ;
}
if ( F_18 ( V_26 ) >= F_19 ( V_5 -> V_8 * 8 ) ) {
F_15 ( & V_18 -> V_22 , L_6 ) ;
return - V_31 ;
}
V_5 -> V_13 = F_18 ( V_26 ) ;
F_20 (np, np2) {
V_26 = F_17 ( V_20 , L_9 , & V_27 ) ;
if ( ! V_26 || V_27 != sizeof( V_16 ) ) {
F_15 ( & V_18 -> V_22 , L_10
L_11 , V_20 ) ;
F_21 ( V_20 ) ;
return - V_32 ;
}
if ( F_18 ( V_26 ) & ~ V_5 -> V_13 ) {
F_15 ( & V_18 -> V_22 , L_12
L_13 ,
V_20 ) ;
F_21 ( V_20 ) ;
return - V_32 ;
}
}
V_28 = F_22 ( & V_18 -> V_22 , V_18 -> V_22 . V_23 ,
F_1 ,
& V_5 -> V_33 , V_5 , NULL ) ;
if ( V_28 ) {
F_15 ( & V_18 -> V_22 , L_14 ,
V_21 ) ;
return V_28 ;
}
V_18 -> V_22 . V_34 = V_5 ;
return 0 ;
}
static int F_23 ( struct V_17 * V_18 )
{
struct V_4 * V_5 = F_24 ( & V_18 -> V_22 ) ;
F_25 ( V_5 -> V_33 ) ;
return 0 ;
}
