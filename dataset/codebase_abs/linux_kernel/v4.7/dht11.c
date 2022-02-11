static void F_1 ( struct V_1 * V_1 )
{
int V_2 ;
F_2 ( V_1 -> V_3 , L_1 , V_1 -> V_4 ) ;
for ( V_2 = 1 ; V_2 < V_1 -> V_4 ; ++ V_2 ) {
F_2 ( V_1 -> V_3 , L_2 , V_2 ,
V_1 -> V_5 [ V_2 ] . V_6 - V_1 -> V_5 [ V_2 - 1 ] . V_6 ,
V_1 -> V_5 [ V_2 - 1 ] . V_7 ? L_3 : L_4 ) ;
}
}
static unsigned char F_3 ( char * V_8 )
{
unsigned char V_9 = 0 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < 8 ; ++ V_2 ) {
V_9 <<= 1 ;
if ( V_8 [ V_2 ] )
++ V_9 ;
}
return V_9 ;
}
static int F_4 ( struct V_1 * V_1 , int V_10 )
{
int V_2 , V_11 ;
char V_8 [ V_12 ] ;
unsigned char V_13 , V_14 , V_15 , V_16 , V_17 ;
for ( V_2 = 0 ; V_2 < V_12 ; ++ V_2 ) {
V_11 = V_1 -> V_5 [ V_10 + 2 * V_2 + 2 ] . V_6 -
V_1 -> V_5 [ V_10 + 2 * V_2 + 1 ] . V_6 ;
if ( ! V_1 -> V_5 [ V_10 + 2 * V_2 + 1 ] . V_7 ) {
F_2 ( V_1 -> V_3 ,
L_5 ,
V_10 + 2 * V_2 + 1 ) ;
return - V_18 ;
}
V_8 [ V_2 ] = V_11 > V_19 ;
}
V_15 = F_3 ( V_8 ) ;
V_16 = F_3 ( & V_8 [ 8 ] ) ;
V_13 = F_3 ( & V_8 [ 16 ] ) ;
V_14 = F_3 ( & V_8 [ 24 ] ) ;
V_17 = F_3 ( & V_8 [ 32 ] ) ;
if ( ( ( V_15 + V_16 + V_13 + V_14 ) & 0xff ) != V_17 ) {
F_2 ( V_1 -> V_3 , L_6 ) ;
return - V_18 ;
}
V_1 -> V_20 = F_5 () ;
if ( V_15 < 20 ) {
V_1 -> V_21 = ( ( ( V_13 & 0x7f ) << 8 ) + V_14 ) *
( ( V_13 & 0x80 ) ? - 100 : 100 ) ;
V_1 -> V_22 = ( ( V_15 << 8 ) + V_16 ) * 100 ;
} else if ( V_14 == 0 && V_16 == 0 ) {
V_1 -> V_21 = V_13 * 1000 ;
V_1 -> V_22 = V_15 * 1000 ;
} else {
F_6 ( V_1 -> V_3 ,
L_7 ,
V_15 , V_16 , V_13 , V_14 ) ;
return - V_18 ;
}
return 0 ;
}
static T_1 F_7 ( int V_23 , void * V_24 )
{
struct V_25 * V_26 = V_24 ;
struct V_1 * V_1 = F_8 ( V_26 ) ;
if ( V_1 -> V_4 < V_27 && V_1 -> V_4 >= 0 ) {
V_1 -> V_5 [ V_1 -> V_4 ] . V_6 = F_5 () ;
V_1 -> V_5 [ V_1 -> V_4 ++ ] . V_7 =
F_9 ( V_1 -> V_28 ) ;
if ( V_1 -> V_4 >= V_27 )
F_10 ( & V_1 -> V_29 ) ;
}
return V_30 ;
}
static int F_11 ( struct V_25 * V_25 ,
const struct V_31 * V_32 ,
int * V_33 , int * V_34 , long V_35 )
{
struct V_1 * V_1 = F_8 ( V_25 ) ;
int V_9 , V_36 , V_10 ;
F_12 ( & V_1 -> V_37 ) ;
if ( V_1 -> V_20 + V_38 < F_5 () ) {
V_36 = F_13 () ;
F_2 ( V_1 -> V_3 , L_8 , V_36 ) ;
if ( V_36 > V_39 ) {
F_6 ( V_1 -> V_3 , L_9 ,
V_36 ) ;
V_9 = - V_40 ;
goto V_41;
}
if ( V_36 > V_42 && V_36 < V_43 )
F_14 ( V_1 -> V_3 ,
L_10 ,
V_36 ) ;
F_15 ( & V_1 -> V_29 ) ;
V_1 -> V_4 = 0 ;
V_9 = F_16 ( V_1 -> V_28 , 0 ) ;
if ( V_9 )
goto V_41;
F_17 ( V_44 ) ;
V_9 = F_18 ( V_1 -> V_28 ) ;
if ( V_9 )
goto V_41;
V_9 = F_19 ( V_1 -> V_23 , F_7 ,
V_45 | V_46 ,
V_25 -> V_47 , V_25 ) ;
if ( V_9 )
goto V_41;
V_9 = F_20 ( & V_1 -> V_29 ,
V_48 ) ;
F_21 ( V_1 -> V_23 , V_25 ) ;
#ifdef F_22
F_1 ( V_1 ) ;
#endif
if ( V_9 == 0 && V_1 -> V_4 < V_27 - 1 ) {
F_6 ( V_1 -> V_3 , L_11 ,
V_1 -> V_4 ) ;
V_9 = - V_49 ;
}
if ( V_9 < 0 )
goto V_41;
V_10 = V_50 +
V_1 -> V_4 - V_27 ;
for (; V_10 >= 0 ; -- V_10 ) {
V_9 = F_4 ( V_1 , V_10 ) ;
if ( ! V_9 )
break;
}
if ( V_9 )
goto V_41;
}
V_9 = V_51 ;
if ( V_32 -> type == V_52 )
* V_33 = V_1 -> V_21 ;
else if ( V_32 -> type == V_53 )
* V_33 = V_1 -> V_22 ;
else
V_9 = - V_54 ;
V_41:
V_1 -> V_4 = - 1 ;
F_23 ( & V_1 -> V_37 ) ;
return V_9 ;
}
static int F_24 ( struct V_55 * V_56 )
{
struct V_57 * V_3 = & V_56 -> V_3 ;
struct V_58 * V_59 = V_3 -> V_60 ;
struct V_1 * V_1 ;
struct V_25 * V_26 ;
int V_9 ;
V_26 = F_25 ( V_3 , sizeof( * V_1 ) ) ;
if ( ! V_26 ) {
F_6 ( V_3 , L_12 ) ;
return - V_61 ;
}
V_1 = F_8 ( V_26 ) ;
V_1 -> V_3 = V_3 ;
V_9 = F_26 ( V_59 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
V_1 -> V_28 = V_9 ;
V_9 = F_27 ( V_3 , V_1 -> V_28 , V_62 , V_56 -> V_47 ) ;
if ( V_9 )
return V_9 ;
V_1 -> V_23 = F_28 ( V_1 -> V_28 ) ;
if ( V_1 -> V_23 < 0 ) {
F_6 ( V_3 , L_13 , V_1 -> V_28 ) ;
return - V_54 ;
}
V_1 -> V_20 = F_5 () - V_38 - 1 ;
V_1 -> V_4 = - 1 ;
F_29 ( V_56 , V_26 ) ;
F_30 ( & V_1 -> V_29 ) ;
F_31 ( & V_1 -> V_37 ) ;
V_26 -> V_47 = V_56 -> V_47 ;
V_26 -> V_3 . V_63 = & V_56 -> V_3 ;
V_26 -> V_64 = & V_65 ;
V_26 -> V_66 = V_67 ;
V_26 -> V_68 = V_69 ;
V_26 -> V_70 = F_32 ( V_69 ) ;
return F_33 ( V_3 , V_26 ) ;
}
