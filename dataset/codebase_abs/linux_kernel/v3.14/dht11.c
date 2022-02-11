static unsigned char F_1 ( int * V_1 , int V_2 )
{
unsigned char V_3 = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < 8 ; ++ V_4 ) {
V_3 <<= 1 ;
if ( V_1 [ V_4 ] >= V_2 )
++ V_3 ;
}
return V_3 ;
}
static int F_2 ( struct V_5 * V_5 , int V_6 )
{
int V_4 , V_7 , V_1 [ V_8 ] , V_2 ,
V_9 = V_10 ;
unsigned char V_11 , V_12 , V_13 , V_14 , V_15 ;
for ( V_4 = 0 ; V_4 < V_5 -> V_16 ; ++ V_4 ) {
V_7 = V_5 -> V_17 [ V_4 ] . V_18 - V_5 -> V_17 [ V_4 - 1 ] . V_18 ;
if ( V_7 > 0 && V_7 < V_9 )
V_9 = V_7 ;
}
if ( 2 * V_9 > V_19 ) {
F_3 ( L_1 ,
V_9 ) ;
return - V_20 ;
}
V_2 = V_19 / V_9 ;
if ( V_21 / V_9 + 1 >= V_2 )
F_3 ( L_2 ) ;
for ( V_4 = 0 ; V_4 < V_8 ; ++ V_4 ) {
V_7 = V_5 -> V_17 [ V_6 + 2 * V_4 + 2 ] . V_18 -
V_5 -> V_17 [ V_6 + 2 * V_4 + 1 ] . V_18 ;
if ( ! V_5 -> V_17 [ V_6 + 2 * V_4 + 1 ] . V_22 )
return - V_20 ;
V_1 [ V_4 ] = V_7 / V_9 ;
}
V_13 = F_1 ( V_1 , V_2 ) ;
V_14 = F_1 ( & V_1 [ 8 ] , V_2 ) ;
V_11 = F_1 ( & V_1 [ 16 ] , V_2 ) ;
V_12 = F_1 ( & V_1 [ 24 ] , V_2 ) ;
V_15 = F_1 ( & V_1 [ 32 ] , V_2 ) ;
if ( ( ( V_13 + V_14 + V_11 + V_12 ) & 0xff ) != V_15 )
return - V_20 ;
V_5 -> V_23 = F_4 () ;
if ( V_13 < 20 ) {
V_5 -> V_24 = ( ( ( V_11 & 0x7f ) << 8 ) + V_12 ) *
( ( V_11 & 0x80 ) ? - 100 : 100 ) ;
V_5 -> V_25 = ( ( V_13 << 8 ) + V_14 ) * 100 ;
} else if ( V_12 == 0 && V_14 == 0 ) {
V_5 -> V_24 = V_11 * 1000 ;
V_5 -> V_25 = V_13 * 1000 ;
} else {
F_5 ( V_5 -> V_26 ,
L_3 ,
V_13 , V_14 , V_11 , V_12 ) ;
return - V_20 ;
}
return 0 ;
}
static int F_6 ( struct V_27 * V_27 ,
const struct V_28 * V_29 ,
int * V_30 , int * V_31 , long V_32 )
{
struct V_5 * V_5 = F_7 ( V_27 ) ;
int V_3 ;
if ( V_5 -> V_23 + V_33 < F_4 () ) {
F_8 ( & V_5 -> V_34 ) ;
V_5 -> V_16 = 0 ;
V_3 = F_9 ( V_5 -> V_35 , 0 ) ;
if ( V_3 )
goto V_36;
F_10 ( V_37 ) ;
V_3 = F_11 ( V_5 -> V_35 ) ;
if ( V_3 )
goto V_36;
V_3 = F_12 ( & V_5 -> V_34 ,
V_38 ) ;
if ( V_3 == 0 && V_5 -> V_16 < V_39 - 1 ) {
F_5 ( & V_27 -> V_26 ,
L_4 ,
V_5 -> V_16 ) ;
V_3 = - V_40 ;
}
if ( V_3 < 0 )
goto V_36;
V_3 = F_2 ( V_5 ,
V_5 -> V_16 == V_39 ?
V_41 :
V_41 - 2 ) ;
if ( V_3 )
goto V_36;
}
V_3 = V_42 ;
if ( V_29 -> type == V_43 )
* V_30 = V_5 -> V_24 ;
else if ( V_29 -> type == V_44 )
* V_30 = V_5 -> V_25 ;
else
V_3 = - V_45 ;
V_36:
V_5 -> V_16 = - 1 ;
return V_3 ;
}
static T_1 F_13 ( int V_46 , void * V_47 )
{
struct V_27 * V_48 = V_47 ;
struct V_5 * V_5 = F_7 ( V_48 ) ;
if ( V_5 -> V_16 < V_39 && V_5 -> V_16 >= 0 ) {
V_5 -> V_17 [ V_5 -> V_16 ] . V_18 = F_4 () ;
V_5 -> V_17 [ V_5 -> V_16 ++ ] . V_22 =
F_14 ( V_5 -> V_35 ) ;
if ( V_5 -> V_16 >= V_39 )
F_15 ( & V_5 -> V_34 ) ;
}
return V_49 ;
}
static int F_16 ( struct V_50 * V_51 )
{
struct V_52 * V_26 = & V_51 -> V_26 ;
struct V_53 * V_54 = V_26 -> V_55 ;
struct V_5 * V_5 ;
struct V_27 * V_48 ;
int V_3 ;
V_48 = F_17 ( V_26 , sizeof( * V_5 ) ) ;
if ( ! V_48 ) {
F_5 ( V_26 , L_5 ) ;
return - V_56 ;
}
V_5 = F_7 ( V_48 ) ;
V_5 -> V_26 = V_26 ;
V_5 -> V_35 = V_3 = F_18 ( V_54 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_19 ( V_26 , V_5 -> V_35 , V_57 , V_51 -> V_58 ) ;
if ( V_3 )
return V_3 ;
V_5 -> V_46 = F_20 ( V_5 -> V_35 ) ;
if ( V_5 -> V_46 < 0 ) {
F_5 ( V_26 , L_6 , V_5 -> V_35 ) ;
return - V_45 ;
}
V_3 = F_21 ( V_26 , V_5 -> V_46 , F_13 ,
V_59 | V_60 ,
V_51 -> V_58 , V_48 ) ;
if ( V_3 )
return V_3 ;
V_5 -> V_23 = F_4 () - V_33 - 1 ;
V_5 -> V_16 = - 1 ;
F_22 ( V_51 , V_48 ) ;
F_23 ( & V_5 -> V_34 ) ;
V_48 -> V_58 = V_51 -> V_58 ;
V_48 -> V_26 . V_61 = & V_51 -> V_26 ;
V_48 -> V_62 = & V_63 ;
V_48 -> V_64 = V_65 ;
V_48 -> V_66 = V_67 ;
V_48 -> V_68 = F_24 ( V_67 ) ;
return F_25 ( V_26 , V_48 ) ;
}
