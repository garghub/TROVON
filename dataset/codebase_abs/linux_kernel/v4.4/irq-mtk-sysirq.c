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
unsigned long * V_3 ,
unsigned int * type )
{
if ( F_7 ( V_23 -> V_24 ) ) {
if ( V_23 -> V_25 != 3 )
return - V_26 ;
if ( V_23 -> V_27 [ 0 ] != 0 )
return - V_26 ;
* V_3 = V_23 -> V_27 [ 1 ] ;
* type = V_23 -> V_27 [ 2 ] & V_28 ;
return 0 ;
}
return - V_26 ;
}
static int F_8 ( struct V_20 * V_29 , unsigned int V_30 ,
unsigned int V_31 , void * V_32 )
{
int V_33 ;
T_1 V_3 ;
struct V_22 * V_23 = V_32 ;
struct V_22 V_34 = * V_23 ;
if ( V_23 -> V_25 != 3 )
return - V_26 ;
if ( V_23 -> V_27 [ 0 ] )
return - V_26 ;
V_3 = V_23 -> V_27 [ 1 ] ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ )
F_9 ( V_29 , V_30 + V_33 , V_3 + V_33 ,
& V_35 ,
V_29 -> V_36 ) ;
V_34 . V_24 = V_29 -> V_37 -> V_24 ;
return F_10 ( V_29 , V_30 , V_31 , & V_34 ) ;
}
static int T_3 F_11 ( struct V_38 * V_39 ,
struct V_38 * V_37 )
{
struct V_20 * V_29 , * V_40 ;
struct V_4 * V_5 ;
int V_10 , V_41 , V_42 ;
struct V_43 V_44 ;
V_40 = F_12 ( V_37 ) ;
if ( ! V_40 ) {
F_13 ( L_1 ) ;
return - V_26 ;
}
V_10 = F_14 ( V_39 , 0 , & V_44 ) ;
if ( V_10 )
return V_10 ;
V_5 = F_15 ( sizeof( * V_5 ) , V_45 ) ;
if ( ! V_5 )
return - V_46 ;
V_41 = F_16 ( & V_44 ) ;
V_42 = V_41 * 8 ;
V_5 -> V_12 = F_17 ( V_44 . V_47 , V_41 ) ;
if ( ! V_5 -> V_12 ) {
F_13 ( L_2 ) ;
V_10 = - V_48 ;
goto V_49;
}
V_29 = F_18 ( V_40 , 0 , V_42 , V_39 ,
& V_50 , V_5 ) ;
if ( ! V_29 ) {
V_10 = - V_46 ;
goto V_51;
}
F_19 ( & V_5 -> V_11 ) ;
return 0 ;
V_51:
F_20 ( V_5 -> V_12 ) ;
V_49:
F_21 ( V_5 ) ;
return V_10 ;
}
