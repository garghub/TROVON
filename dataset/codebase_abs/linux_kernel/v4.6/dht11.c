static unsigned char F_1 ( char * V_1 )
{
unsigned char V_2 = 0 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 8 ; ++ V_3 ) {
V_2 <<= 1 ;
if ( V_1 [ V_3 ] )
++ V_2 ;
}
return V_2 ;
}
static int F_2 ( struct V_4 * V_4 , int V_5 )
{
int V_3 , V_6 ;
char V_1 [ V_7 ] ;
unsigned char V_8 , V_9 , V_10 , V_11 , V_12 ;
for ( V_3 = 0 ; V_3 < V_7 ; ++ V_3 ) {
V_6 = V_4 -> V_13 [ V_5 + 2 * V_3 + 2 ] . V_14 -
V_4 -> V_13 [ V_5 + 2 * V_3 + 1 ] . V_14 ;
if ( ! V_4 -> V_13 [ V_5 + 2 * V_3 + 1 ] . V_15 )
return - V_16 ;
V_1 [ V_3 ] = V_6 > V_17 ;
}
V_10 = F_1 ( V_1 ) ;
V_11 = F_1 ( & V_1 [ 8 ] ) ;
V_8 = F_1 ( & V_1 [ 16 ] ) ;
V_9 = F_1 ( & V_1 [ 24 ] ) ;
V_12 = F_1 ( & V_1 [ 32 ] ) ;
if ( ( ( V_10 + V_11 + V_8 + V_9 ) & 0xff ) != V_12 )
return - V_16 ;
V_4 -> V_18 = F_3 () ;
if ( V_10 < 20 ) {
V_4 -> V_19 = ( ( ( V_8 & 0x7f ) << 8 ) + V_9 ) *
( ( V_8 & 0x80 ) ? - 100 : 100 ) ;
V_4 -> V_20 = ( ( V_10 << 8 ) + V_11 ) * 100 ;
} else if ( V_9 == 0 && V_11 == 0 ) {
V_4 -> V_19 = V_8 * 1000 ;
V_4 -> V_20 = V_10 * 1000 ;
} else {
F_4 ( V_4 -> V_21 ,
L_1 ,
V_10 , V_11 , V_8 , V_9 ) ;
return - V_16 ;
}
return 0 ;
}
static T_1 F_5 ( int V_22 , void * V_23 )
{
struct V_24 * V_25 = V_23 ;
struct V_4 * V_4 = F_6 ( V_25 ) ;
if ( V_4 -> V_26 < V_27 && V_4 -> V_26 >= 0 ) {
V_4 -> V_13 [ V_4 -> V_26 ] . V_14 = F_3 () ;
V_4 -> V_13 [ V_4 -> V_26 ++ ] . V_15 =
F_7 ( V_4 -> V_28 ) ;
if ( V_4 -> V_26 >= V_27 )
F_8 ( & V_4 -> V_29 ) ;
}
return V_30 ;
}
static int F_9 ( struct V_24 * V_24 ,
const struct V_31 * V_32 ,
int * V_33 , int * V_34 , long V_35 )
{
struct V_4 * V_4 = F_6 ( V_24 ) ;
int V_2 , V_36 , V_5 ;
F_10 ( & V_4 -> V_37 ) ;
if ( V_4 -> V_18 + V_38 < F_3 () ) {
V_36 = F_11 () ;
if ( V_36 > V_39 ) {
F_4 ( V_4 -> V_21 , L_2 ,
V_36 ) ;
V_2 = - V_40 ;
goto V_41;
}
if ( V_36 > V_42 && V_36 < V_43 )
F_12 ( V_4 -> V_21 ,
L_3 ,
V_36 ) ;
F_13 ( & V_4 -> V_29 ) ;
V_4 -> V_26 = 0 ;
V_2 = F_14 ( V_4 -> V_28 , 0 ) ;
if ( V_2 )
goto V_41;
F_15 ( V_44 ) ;
V_2 = F_16 ( V_4 -> V_28 ) ;
if ( V_2 )
goto V_41;
V_2 = F_17 ( V_4 -> V_22 , F_5 ,
V_45 | V_46 ,
V_24 -> V_47 , V_24 ) ;
if ( V_2 )
goto V_41;
V_2 = F_18 ( & V_4 -> V_29 ,
V_48 ) ;
F_19 ( V_4 -> V_22 , V_24 ) ;
if ( V_2 == 0 && V_4 -> V_26 < V_27 - 1 ) {
F_4 ( & V_24 -> V_21 ,
L_4 ,
V_4 -> V_26 ) ;
V_2 = - V_49 ;
}
if ( V_2 < 0 )
goto V_41;
V_5 = V_50 +
V_4 -> V_26 - V_27 ;
for (; V_5 >= 0 ; -- V_5 ) {
V_2 = F_2 ( V_4 , V_5 ) ;
if ( ! V_2 )
break;
}
if ( V_2 )
goto V_41;
}
V_2 = V_51 ;
if ( V_32 -> type == V_52 )
* V_33 = V_4 -> V_19 ;
else if ( V_32 -> type == V_53 )
* V_33 = V_4 -> V_20 ;
else
V_2 = - V_54 ;
V_41:
V_4 -> V_26 = - 1 ;
F_20 ( & V_4 -> V_37 ) ;
return V_2 ;
}
static int F_21 ( struct V_55 * V_56 )
{
struct V_57 * V_21 = & V_56 -> V_21 ;
struct V_58 * V_59 = V_21 -> V_60 ;
struct V_4 * V_4 ;
struct V_24 * V_25 ;
int V_2 ;
V_25 = F_22 ( V_21 , sizeof( * V_4 ) ) ;
if ( ! V_25 ) {
F_4 ( V_21 , L_5 ) ;
return - V_61 ;
}
V_4 = F_6 ( V_25 ) ;
V_4 -> V_21 = V_21 ;
V_2 = F_23 ( V_59 , 0 ) ;
if ( V_2 < 0 )
return V_2 ;
V_4 -> V_28 = V_2 ;
V_2 = F_24 ( V_21 , V_4 -> V_28 , V_62 , V_56 -> V_47 ) ;
if ( V_2 )
return V_2 ;
V_4 -> V_22 = F_25 ( V_4 -> V_28 ) ;
if ( V_4 -> V_22 < 0 ) {
F_4 ( V_21 , L_6 , V_4 -> V_28 ) ;
return - V_54 ;
}
V_4 -> V_18 = F_3 () - V_38 - 1 ;
V_4 -> V_26 = - 1 ;
F_26 ( V_56 , V_25 ) ;
F_27 ( & V_4 -> V_29 ) ;
F_28 ( & V_4 -> V_37 ) ;
V_25 -> V_47 = V_56 -> V_47 ;
V_25 -> V_21 . V_63 = & V_56 -> V_21 ;
V_25 -> V_64 = & V_65 ;
V_25 -> V_66 = V_67 ;
V_25 -> V_68 = V_69 ;
V_25 -> V_70 = F_29 ( V_69 ) ;
return F_30 ( V_21 , V_25 ) ;
}
