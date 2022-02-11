static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
int V_5 )
{
int V_6 ;
T_2 V_7 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
V_7 = F_2 ( V_2 , V_3 ) ;
if ( ( V_7 & V_4 ) == V_4 )
return 0 ;
F_3 ( 10 ) ;
}
return - V_8 ;
}
static void T_3 F_4 ( struct V_1 * V_2 )
{
#ifdef F_5
if ( V_2 -> V_9 -> V_10 . V_11 == 0x4716 ) {
T_2 V_12 ;
V_12 = F_6 ( & V_2 -> V_9 -> V_13 ) ;
if ( V_12 >= 480000000 )
V_12 = 0x1846b ;
else if ( V_12 == 453000000 )
V_12 = 0x1046b ;
else
V_12 = 0 ;
if ( V_12 ) {
F_7 ( V_2 , 0x524 , 0x1 ) ;
F_3 ( 500 ) ;
F_7 ( V_2 , 0x524 , V_12 ) ;
F_3 ( 500 ) ;
F_7 ( V_2 , 0x524 , 0x4ab ) ;
F_3 ( 500 ) ;
F_2 ( V_2 , 0x528 ) ;
F_7 ( V_2 , 0x528 , 0x80000000 ) ;
}
}
#endif
}
static void T_3 F_8 ( struct V_1 * V_2 )
{
T_2 V_12 ;
if ( ! F_9 ( V_2 ) ) {
F_10 ( V_2 , 0 ) ;
F_11 ( 10 ) ;
if ( V_2 -> V_11 . V_14 >= 5 ) {
V_12 = F_2 ( V_2 , 0x1e0 ) ;
V_12 |= 0x100 ;
F_7 ( V_2 , 0x1e0 , V_12 ) ;
if ( F_1 ( V_2 , 0x1e0 , 1 << 24 , 100 ) )
F_12 ( V_15 L_1 ) ;
F_7 ( V_2 , 0x200 , 0x4ff ) ;
F_3 ( 25 ) ;
F_7 ( V_2 , 0x200 , 0x6ff ) ;
F_3 ( 25 ) ;
F_7 ( V_2 , 0x524 , 0x6b ) ;
F_3 ( 50 ) ;
V_12 = F_2 ( V_2 , 0x524 ) ;
F_3 ( 50 ) ;
F_7 ( V_2 , 0x524 , 0xab ) ;
F_3 ( 50 ) ;
V_12 = F_2 ( V_2 , 0x524 ) ;
F_3 ( 50 ) ;
F_7 ( V_2 , 0x524 , 0x2b ) ;
F_3 ( 50 ) ;
V_12 = F_2 ( V_2 , 0x524 ) ;
F_3 ( 50 ) ;
F_7 ( V_2 , 0x524 , 0x10ab ) ;
F_3 ( 50 ) ;
V_12 = F_2 ( V_2 , 0x524 ) ;
if ( F_1 ( V_2 , 0x528 , 0xc000 , 10000 ) ) {
V_12 = F_2 ( V_2 , 0x528 ) ;
F_12 ( V_15
L_2 , V_12 ) ;
}
F_7 ( V_2 , 0x528 , 0x80000000 ) ;
V_12 = F_2 ( V_2 , 0x314 ) ;
F_3 ( 265 ) ;
F_7 ( V_2 , 0x200 , 0x7ff ) ;
F_3 ( 10 ) ;
F_7 ( V_2 , 0x510 , 0 ) ;
} else {
F_7 ( V_2 , 0x200 , 0x7ff ) ;
F_3 ( 1 ) ;
}
F_4 ( V_2 ) ;
}
}
static struct V_16 * T_3
F_13 ( struct V_1 * V_2 , bool V_17 , T_2 V_18 )
{
struct V_16 * V_19 ;
struct V_20 V_21 [ 2 ] ;
int V_22 = - V_23 ;
memset ( V_21 , 0 , sizeof( V_21 ) ) ;
V_21 [ 0 ] . V_24 = V_18 ;
V_21 [ 0 ] . V_25 = V_21 [ 0 ] . V_24 + 0x1000 - 1 ;
V_21 [ 0 ] . V_26 = V_27 ;
V_21 [ 1 ] . V_24 = V_2 -> V_28 ;
V_21 [ 1 ] . V_26 = V_29 ;
V_19 = F_14 ( V_17 ? L_3 :
L_4 , 0 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_2 . V_30 = & V_2 -> V_2 ;
V_19 -> V_2 . V_31 = & V_19 -> V_2 . V_32 ;
V_22 = F_15 ( V_19 , V_21 ,
F_16 ( V_21 ) ) ;
if ( V_22 )
goto V_33;
if ( V_17 )
V_22 = F_17 ( V_19 , & V_34 ,
sizeof( V_34 ) ) ;
else
V_22 = F_17 ( V_19 , & V_35 ,
sizeof( V_35 ) ) ;
if ( V_22 )
goto V_33;
V_22 = F_18 ( V_19 ) ;
if ( V_22 )
goto V_33;
return V_19 ;
V_33:
F_19 ( V_19 ) ;
return F_20 ( V_22 ) ;
}
static int T_3 F_21 ( struct V_1 * V_2 )
{
int V_36 ;
T_1 V_37 ;
T_2 V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_10 ;
V_10 = & V_2 -> V_9 -> V_10 ;
V_37 = ( V_10 -> V_11 & 0xFF00 ) ;
if ( V_37 != 0x4700 && V_37 != 0x5300 )
return - V_42 ;
if ( F_22 ( V_2 -> V_43 , F_23 ( 32 ) ) ||
F_24 ( V_2 -> V_43 , F_23 ( 32 ) ) )
return - V_44 ;
V_40 = F_25 ( sizeof( struct V_39 ) , V_45 ) ;
if ( ! V_40 )
return - V_23 ;
F_8 ( V_2 ) ;
V_38 = V_2 -> V_46 ;
if ( ( V_10 -> V_11 == 0x5357 || V_10 -> V_11 == 0x4749 )
&& V_10 -> V_14 == 0 )
V_38 = 0x18009000 ;
V_40 -> V_47 = F_13 ( V_2 , true , V_38 ) ;
if ( F_26 ( V_40 -> V_47 ) ) {
V_36 = F_27 ( V_40 -> V_47 ) ;
goto V_48;
}
V_40 -> V_49 = F_13 ( V_2 , false , V_2 -> V_18 ) ;
if ( F_26 ( V_40 -> V_49 ) ) {
V_36 = F_27 ( V_40 -> V_49 ) ;
goto V_50;
}
F_28 ( V_2 , V_40 ) ;
return 0 ;
V_50:
F_29 ( V_40 -> V_47 ) ;
V_48:
F_30 ( V_40 ) ;
return V_36 ;
}
static void T_4 F_31 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_32 ( V_2 ) ;
struct V_16 * V_47 = V_40 -> V_47 ;
struct V_16 * V_49 = V_40 -> V_49 ;
if ( V_47 )
F_29 ( V_47 ) ;
if ( V_49 )
F_29 ( V_49 ) ;
F_33 ( V_2 , 0 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_33 ( V_2 , 0 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
F_33 ( V_2 , 0 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
F_10 ( V_2 , 0 ) ;
return 0 ;
}
static int T_5 F_37 ( void )
{
return F_38 ( & V_51 ) ;
}
static void T_6 F_39 ( void )
{
F_40 ( & V_51 ) ;
}
