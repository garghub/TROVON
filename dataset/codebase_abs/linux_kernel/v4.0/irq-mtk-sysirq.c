static int F_1 ( struct V_1 * V_2 , unsigned int type )
{
T_1 V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_6 , V_7 , V_8 ;
unsigned long V_9 ;
int V_10 ;
V_6 = V_3 & 0x1f ;
V_7 = V_3 >> 5 ;
F_2 ( & V_5 -> V_11 , V_9 ) ;
V_8 = F_3 ( V_5 -> V_12 + V_7 * 4 ) ;
if ( type == V_13 || type == V_14 ) {
if ( type == V_13 )
type = V_15 ;
else
type = V_16 ;
V_8 |= ( 1 << V_6 ) ;
} else {
V_8 &= ~ ( 1 << V_6 ) ;
}
F_4 ( V_8 , V_5 -> V_12 + V_7 * 4 ) ;
V_2 = V_2 -> V_17 ;
V_10 = V_2 -> V_18 -> V_19 ( V_2 , type ) ;
F_5 ( & V_5 -> V_11 , V_9 ) ;
return V_10 ;
}
static int F_6 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
const T_2 * V_24 , unsigned int V_25 ,
unsigned long * V_26 ,
unsigned int * V_27 )
{
if ( V_25 != 3 )
return - V_28 ;
if ( V_24 [ 0 ] )
return - V_28 ;
* V_26 = V_24 [ 1 ] ;
* V_27 = V_24 [ 2 ] & V_29 ;
return 0 ;
}
static int F_7 ( struct V_20 * V_30 , unsigned int V_31 ,
unsigned int V_32 , void * V_33 )
{
int V_34 ;
T_1 V_3 ;
struct V_35 * V_1 = V_33 ;
struct V_35 V_36 = * V_1 ;
if ( V_1 -> V_37 != 3 )
return - V_28 ;
if ( V_1 -> args [ 0 ] )
return - V_28 ;
V_3 = V_1 -> args [ 1 ] ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ )
F_8 ( V_30 , V_31 + V_34 , V_3 + V_34 ,
& V_38 ,
V_30 -> V_39 ) ;
V_36 . V_40 = V_30 -> V_41 -> V_42 ;
return F_9 ( V_30 , V_31 , V_32 , & V_36 ) ;
}
static int T_3 F_10 ( struct V_22 * V_43 ,
struct V_22 * V_41 )
{
struct V_20 * V_30 , * V_44 ;
struct V_4 * V_5 ;
int V_10 , V_45 , V_46 ;
struct V_47 V_48 ;
V_44 = F_11 ( V_41 ) ;
if ( ! V_44 ) {
F_12 ( L_1 ) ;
return - V_28 ;
}
V_10 = F_13 ( V_43 , 0 , & V_48 ) ;
if ( V_10 )
return V_10 ;
V_5 = F_14 ( sizeof( * V_5 ) , V_49 ) ;
if ( ! V_5 )
return - V_50 ;
V_45 = F_15 ( & V_48 ) ;
V_46 = V_45 * 8 ;
V_5 -> V_12 = F_16 ( V_48 . V_51 , V_45 ) ;
if ( ! V_5 -> V_12 ) {
F_12 ( L_2 ) ;
V_10 = F_17 ( V_5 -> V_12 ) ;
goto V_52;
}
V_30 = F_18 ( V_44 , 0 , V_46 , V_43 ,
& V_53 , V_5 ) ;
if ( ! V_30 ) {
V_10 = - V_50 ;
goto V_54;
}
F_19 ( & V_5 -> V_11 ) ;
return 0 ;
V_54:
F_20 ( V_5 -> V_12 ) ;
V_52:
F_21 ( V_5 ) ;
return V_10 ;
}
