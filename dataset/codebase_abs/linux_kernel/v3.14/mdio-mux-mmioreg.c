static int F_1 ( int V_1 , int V_2 ,
void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( V_1 ^ V_2 ) {
void T_1 * V_6 = F_2 ( V_5 -> V_7 , 1 ) ;
T_2 V_8 , V_9 ;
if ( ! V_6 )
return - V_10 ;
V_8 = F_3 ( V_6 ) ;
V_9 = ( V_8 & ~ V_5 -> V_11 ) | V_2 ;
if ( V_8 != V_9 ) {
F_4 ( ( V_8 & ~ V_5 -> V_11 ) | V_2 , V_6 ) ;
F_5 ( L_1 , V_12 , V_8 , V_9 ) ;
}
F_6 ( V_6 ) ;
}
return 0 ;
}
static int F_7 ( struct V_13 * V_14 )
{
struct V_15 * V_16 , * V_17 = V_14 -> V_18 . V_19 ;
struct V_4 * V_5 ;
struct V_20 V_21 ;
const T_3 * V_22 ;
int V_23 , V_24 ;
F_8 ( & V_14 -> V_18 , L_2 , V_17 -> V_25 ) ;
V_5 = F_9 ( & V_14 -> V_18 , sizeof( * V_5 ) , V_26 ) ;
if ( ! V_5 )
return - V_10 ;
V_24 = F_10 ( V_17 , 0 , & V_21 ) ;
if ( V_24 ) {
F_11 ( & V_14 -> V_18 , L_3 ,
V_17 -> V_25 ) ;
return V_24 ;
}
V_5 -> V_7 = V_21 . V_27 ;
if ( F_12 ( & V_21 ) != sizeof( T_2 ) ) {
F_11 ( & V_14 -> V_18 , L_4 ) ;
return - V_28 ;
}
V_22 = F_13 ( V_17 , L_5 , & V_23 ) ;
if ( ! V_22 || V_23 != sizeof( V_29 ) ) {
F_11 ( & V_14 -> V_18 , L_6 ) ;
return - V_30 ;
}
if ( F_14 ( V_22 ) > 255 ) {
F_11 ( & V_14 -> V_18 , L_4 ) ;
return - V_28 ;
}
V_5 -> V_11 = F_14 ( V_22 ) ;
F_15 (np, np2) {
V_22 = F_13 ( V_16 , L_7 , & V_23 ) ;
if ( ! V_22 || V_23 != sizeof( V_29 ) ) {
F_11 ( & V_14 -> V_18 , L_8
L_9 , V_16 -> V_25 ) ;
return - V_30 ;
}
if ( F_14 ( V_22 ) & ~ V_5 -> V_11 ) {
F_11 ( & V_14 -> V_18 , L_10
L_11 ,
V_16 -> V_25 ) ;
return - V_30 ;
}
}
V_24 = F_16 ( & V_14 -> V_18 , F_1 ,
& V_5 -> V_31 , V_5 ) ;
if ( V_24 ) {
F_11 ( & V_14 -> V_18 , L_12 ,
V_17 -> V_25 ) ;
return V_24 ;
}
V_14 -> V_18 . V_32 = V_5 ;
return 0 ;
}
static int F_17 ( struct V_13 * V_14 )
{
struct V_4 * V_5 = F_18 ( & V_14 -> V_18 ) ;
F_19 ( V_5 -> V_31 ) ;
return 0 ;
}
