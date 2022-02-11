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
for ( V_4 = 1 ; V_4 < V_5 -> V_16 ; ++ V_4 ) {
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
static T_1 F_6 ( int V_27 , void * V_28 )
{
struct V_29 * V_30 = V_28 ;
struct V_5 * V_5 = F_7 ( V_30 ) ;
if ( V_5 -> V_16 < V_31 && V_5 -> V_16 >= 0 ) {
V_5 -> V_17 [ V_5 -> V_16 ] . V_18 = F_4 () ;
V_5 -> V_17 [ V_5 -> V_16 ++ ] . V_22 =
F_8 ( V_5 -> V_32 ) ;
if ( V_5 -> V_16 >= V_31 )
F_9 ( & V_5 -> V_33 ) ;
}
return V_34 ;
}
static int F_10 ( struct V_29 * V_29 ,
const struct V_35 * V_36 ,
int * V_37 , int * V_38 , long V_39 )
{
struct V_5 * V_5 = F_7 ( V_29 ) ;
int V_3 ;
F_11 ( & V_5 -> V_40 ) ;
if ( V_5 -> V_23 + V_41 < F_4 () ) {
F_12 ( & V_5 -> V_33 ) ;
V_5 -> V_16 = 0 ;
V_3 = F_13 ( V_5 -> V_32 , 0 ) ;
if ( V_3 )
goto V_42;
F_14 ( V_43 ) ;
V_3 = F_15 ( V_5 -> V_32 ) ;
if ( V_3 )
goto V_42;
V_3 = F_16 ( V_5 -> V_27 , F_6 ,
V_44 | V_45 ,
V_29 -> V_46 , V_29 ) ;
if ( V_3 )
goto V_42;
V_3 = F_17 ( & V_5 -> V_33 ,
V_47 ) ;
F_18 ( V_5 -> V_27 , V_29 ) ;
if ( V_3 == 0 && V_5 -> V_16 < V_31 - 1 ) {
F_5 ( & V_29 -> V_26 ,
L_4 ,
V_5 -> V_16 ) ;
V_3 = - V_48 ;
}
if ( V_3 < 0 )
goto V_42;
V_3 = F_2 ( V_5 ,
V_5 -> V_16 == V_31 ?
V_49 :
V_49 - 2 ) ;
if ( V_3 )
goto V_42;
}
V_3 = V_50 ;
if ( V_36 -> type == V_51 )
* V_37 = V_5 -> V_24 ;
else if ( V_36 -> type == V_52 )
* V_37 = V_5 -> V_25 ;
else
V_3 = - V_53 ;
V_42:
V_5 -> V_16 = - 1 ;
F_19 ( & V_5 -> V_40 ) ;
return V_3 ;
}
static int F_20 ( struct V_54 * V_55 )
{
struct V_56 * V_26 = & V_55 -> V_26 ;
struct V_57 * V_58 = V_26 -> V_59 ;
struct V_5 * V_5 ;
struct V_29 * V_30 ;
int V_3 ;
V_30 = F_21 ( V_26 , sizeof( * V_5 ) ) ;
if ( ! V_30 ) {
F_5 ( V_26 , L_5 ) ;
return - V_60 ;
}
V_5 = F_7 ( V_30 ) ;
V_5 -> V_26 = V_26 ;
V_5 -> V_32 = V_3 = F_22 ( V_58 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_23 ( V_26 , V_5 -> V_32 , V_61 , V_55 -> V_46 ) ;
if ( V_3 )
return V_3 ;
V_5 -> V_27 = F_24 ( V_5 -> V_32 ) ;
if ( V_5 -> V_27 < 0 ) {
F_5 ( V_26 , L_6 , V_5 -> V_32 ) ;
return - V_53 ;
}
V_5 -> V_23 = F_4 () - V_41 - 1 ;
V_5 -> V_16 = - 1 ;
F_25 ( V_55 , V_30 ) ;
F_26 ( & V_5 -> V_33 ) ;
F_27 ( & V_5 -> V_40 ) ;
V_30 -> V_46 = V_55 -> V_46 ;
V_30 -> V_26 . V_62 = & V_55 -> V_26 ;
V_30 -> V_63 = & V_64 ;
V_30 -> V_65 = V_66 ;
V_30 -> V_67 = V_68 ;
V_30 -> V_69 = F_28 ( V_68 ) ;
return F_29 ( V_26 , V_30 ) ;
}
