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
static int F_2 ( struct V_5 * V_5 , int V_6 , int V_7 )
{
int V_4 , V_8 , V_1 [ V_9 ] , V_2 ;
unsigned char V_10 , V_11 , V_12 , V_13 , V_14 ;
V_2 = V_15 / V_7 ;
if ( V_16 / V_7 + 1 >= V_2 )
F_3 ( L_1 ) ;
for ( V_4 = 0 ; V_4 < V_9 ; ++ V_4 ) {
V_8 = V_5 -> V_17 [ V_6 + 2 * V_4 + 2 ] . V_18 -
V_5 -> V_17 [ V_6 + 2 * V_4 + 1 ] . V_18 ;
if ( ! V_5 -> V_17 [ V_6 + 2 * V_4 + 1 ] . V_19 )
return - V_20 ;
V_1 [ V_4 ] = V_8 / V_7 ;
}
V_12 = F_1 ( V_1 , V_2 ) ;
V_13 = F_1 ( & V_1 [ 8 ] , V_2 ) ;
V_10 = F_1 ( & V_1 [ 16 ] , V_2 ) ;
V_11 = F_1 ( & V_1 [ 24 ] , V_2 ) ;
V_14 = F_1 ( & V_1 [ 32 ] , V_2 ) ;
if ( ( ( V_12 + V_13 + V_10 + V_11 ) & 0xff ) != V_14 )
return - V_20 ;
V_5 -> V_21 = F_4 () ;
if ( V_12 < 20 ) {
V_5 -> V_22 = ( ( ( V_10 & 0x7f ) << 8 ) + V_11 ) *
( ( V_10 & 0x80 ) ? - 100 : 100 ) ;
V_5 -> V_23 = ( ( V_12 << 8 ) + V_13 ) * 100 ;
} else if ( V_11 == 0 && V_13 == 0 ) {
V_5 -> V_22 = V_10 * 1000 ;
V_5 -> V_23 = V_12 * 1000 ;
} else {
F_5 ( V_5 -> V_24 ,
L_2 ,
V_12 , V_13 , V_10 , V_11 ) ;
return - V_20 ;
}
return 0 ;
}
static T_1 F_6 ( int V_25 , void * V_26 )
{
struct V_27 * V_28 = V_26 ;
struct V_5 * V_5 = F_7 ( V_28 ) ;
if ( V_5 -> V_29 < V_30 && V_5 -> V_29 >= 0 ) {
V_5 -> V_17 [ V_5 -> V_29 ] . V_18 = F_4 () ;
V_5 -> V_17 [ V_5 -> V_29 ++ ] . V_19 =
F_8 ( V_5 -> V_31 ) ;
if ( V_5 -> V_29 >= V_30 )
F_9 ( & V_5 -> V_32 ) ;
}
return V_33 ;
}
static int F_10 ( struct V_27 * V_27 ,
const struct V_34 * V_35 ,
int * V_36 , int * V_37 , long V_38 )
{
struct V_5 * V_5 = F_7 ( V_27 ) ;
int V_3 , V_7 ;
F_11 ( & V_5 -> V_39 ) ;
if ( V_5 -> V_21 + V_40 < F_4 () ) {
V_7 = F_12 () ;
if ( V_15 < 2 * V_7 ) {
F_5 ( V_5 -> V_24 , L_3 ,
V_7 ) ;
V_3 = - V_41 ;
goto V_42;
}
F_13 ( & V_5 -> V_32 ) ;
V_5 -> V_29 = 0 ;
V_3 = F_14 ( V_5 -> V_31 , 0 ) ;
if ( V_3 )
goto V_42;
F_15 ( V_43 ) ;
V_3 = F_16 ( V_5 -> V_31 ) ;
if ( V_3 )
goto V_42;
V_3 = F_17 ( V_5 -> V_25 , F_6 ,
V_44 | V_45 ,
V_27 -> V_46 , V_27 ) ;
if ( V_3 )
goto V_42;
V_3 = F_18 ( & V_5 -> V_32 ,
V_47 ) ;
F_19 ( V_5 -> V_25 , V_27 ) ;
if ( V_3 == 0 && V_5 -> V_29 < V_30 - 1 ) {
F_5 ( & V_27 -> V_24 ,
L_4 ,
V_5 -> V_29 ) ;
V_3 = - V_48 ;
}
if ( V_3 < 0 )
goto V_42;
V_3 = F_2 ( V_5 ,
V_5 -> V_29 == V_30 ?
V_49 :
V_49 - 2 ,
V_7 ) ;
if ( V_3 )
goto V_42;
}
V_3 = V_50 ;
if ( V_35 -> type == V_51 )
* V_36 = V_5 -> V_22 ;
else if ( V_35 -> type == V_52 )
* V_36 = V_5 -> V_23 ;
else
V_3 = - V_53 ;
V_42:
V_5 -> V_29 = - 1 ;
F_20 ( & V_5 -> V_39 ) ;
return V_3 ;
}
static int F_21 ( struct V_54 * V_55 )
{
struct V_56 * V_24 = & V_55 -> V_24 ;
struct V_57 * V_58 = V_24 -> V_59 ;
struct V_5 * V_5 ;
struct V_27 * V_28 ;
int V_3 ;
V_28 = F_22 ( V_24 , sizeof( * V_5 ) ) ;
if ( ! V_28 ) {
F_5 ( V_24 , L_5 ) ;
return - V_60 ;
}
V_5 = F_7 ( V_28 ) ;
V_5 -> V_24 = V_24 ;
V_3 = F_23 ( V_58 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_5 -> V_31 = V_3 ;
V_3 = F_24 ( V_24 , V_5 -> V_31 , V_61 , V_55 -> V_46 ) ;
if ( V_3 )
return V_3 ;
V_5 -> V_25 = F_25 ( V_5 -> V_31 ) ;
if ( V_5 -> V_25 < 0 ) {
F_5 ( V_24 , L_6 , V_5 -> V_31 ) ;
return - V_53 ;
}
V_5 -> V_21 = F_4 () - V_40 - 1 ;
V_5 -> V_29 = - 1 ;
F_26 ( V_55 , V_28 ) ;
F_27 ( & V_5 -> V_32 ) ;
F_28 ( & V_5 -> V_39 ) ;
V_28 -> V_46 = V_55 -> V_46 ;
V_28 -> V_24 . V_62 = & V_55 -> V_24 ;
V_28 -> V_63 = & V_64 ;
V_28 -> V_65 = V_66 ;
V_28 -> V_67 = V_68 ;
V_28 -> V_69 = F_29 ( V_68 ) ;
return F_30 ( V_24 , V_28 ) ;
}
