static T_1 void T_2 F_1 ( struct V_1 * V_2 )
{
T_3 V_3 , V_4 ;
do {
V_4 = F_2 ( V_5 -> V_6 [ 0 ] ) &
F_2 ( V_5 -> V_7 [ 0 ] ) ;
if ( V_4 ) {
V_3 = F_3 ( V_5 -> V_8 ,
F_4 ( V_4 ) - 1 ) ;
F_5 ( V_3 , V_2 ) ;
}
V_4 = F_2 ( V_5 -> V_6 [ 1 ] ) &
F_2 ( V_5 -> V_7 [ 1 ] ) ;
if ( V_4 ) {
V_3 = F_3 ( V_5 -> V_8 ,
F_4 ( V_4 ) - 1 + 16 ) ;
F_5 ( V_3 , V_2 ) ;
}
} while ( V_4 );
}
static void F_6 ( struct V_9 * V_10 )
{
T_4 V_11 = F_7 ( V_10 ) ;
F_8 ( 0 , V_5 -> V_12 + V_13 [ V_11 ] . V_14 ) ;
}
static void F_9 ( struct V_9 * V_10 )
{
T_4 V_11 = F_7 ( V_10 ) ;
void T_5 * V_6 = V_5 -> V_6 [ V_11 / 16 ] ;
T_3 V_15 ;
V_15 = F_10 ( V_6 ) ;
V_15 &= ~ ( 1 << ( V_11 % 16 ) ) ;
F_8 ( V_15 , V_6 ) ;
}
static void F_11 ( struct V_9 * V_10 )
{
T_4 V_11 = F_7 ( V_10 ) ;
void T_5 * V_6 = V_5 -> V_6 [ V_11 / 16 ] ;
T_3 V_15 ;
V_15 = F_10 ( V_6 ) ;
V_15 |= 1 << ( V_11 % 16 ) ;
F_8 ( V_15 , V_6 ) ;
}
static int T_6 F_12 ( struct V_16 * V_17 , unsigned int V_18 ,
T_4 V_19 )
{
T_7 V_20 = V_21 ;
unsigned int V_22 = V_23 | V_24 ;
if ( ! V_13 [ V_19 ] . V_22 )
return 0 ;
if ( V_13 [ V_19 ] . V_22 & V_25 ) {
V_20 = V_26 ;
V_22 |= V_27 ;
} else if ( V_13 [ V_19 ] . V_14 ) {
V_20 = V_28 ;
}
if ( V_13 [ V_19 ] . V_14 )
F_8 ( 0 , V_5 -> V_12 + V_13 [ V_19 ] . V_14 ) ;
F_13 ( V_18 , & V_29 , V_20 ) ;
F_14 ( V_18 , V_22 ) ;
return 0 ;
}
static int T_6 F_15 ( struct V_30 * V_31 ,
T_8 V_12 , T_9 V_32 )
{
int V_33 ;
V_5 = F_16 ( sizeof( * V_5 ) , V_34 ) ;
if ( ! V_5 )
return - V_35 ;
V_5 -> V_12 = F_17 ( V_12 , V_32 ) ;
if ( ! V_5 -> V_12 ) {
V_33 = - V_35 ;
goto V_36;
}
V_5 -> V_7 [ 0 ] = V_5 -> V_12 + V_37 ;
V_5 -> V_6 [ 0 ] = V_5 -> V_12 + V_38 ;
V_5 -> V_7 [ 1 ] = V_5 -> V_12 + V_39 ;
V_5 -> V_6 [ 1 ] = V_5 -> V_12 + V_40 ;
V_5 -> V_7 [ 2 ] = V_5 -> V_12 + V_41 ;
V_5 -> V_6 [ 2 ] = V_5 -> V_12 + V_42 ;
F_8 ( 0 , V_5 -> V_6 [ 0 ] ) ;
F_8 ( 0 , V_5 -> V_6 [ 1 ] ) ;
F_8 ( 0 , V_5 -> V_6 [ 2 ] ) ;
V_33 = F_18 ( - 1 , 0 , F_19 ( V_13 ) , F_20 () ) ;
if ( F_21 ( V_33 ) )
goto V_43;
V_5 -> V_44 . V_45 = F_12 ;
V_5 -> V_44 . V_46 = V_47 ;
V_5 -> V_8 =
F_22 ( V_31 , F_19 ( V_13 ) ,
0 , 0 , & V_5 -> V_44 , NULL ) ;
if ( ! V_5 -> V_8 ) {
V_33 = - V_35 ;
goto V_48;
}
F_23 ( V_5 -> V_8 ) ;
F_24 ( F_1 ) ;
#ifdef F_25
F_26 ( 0 ) ;
#endif
return 0 ;
V_48:
F_27 ( 0 , F_19 ( V_13 ) ) ;
V_43:
F_28 ( V_5 -> V_12 ) ;
V_36:
F_29 ( V_5 ) ;
return V_33 ;
}
void T_6 F_30 ( T_8 V_12 , T_9 V_32 )
{
F_31 ( F_15 ( NULL , V_12 , V_32 ) ) ;
}
static int T_6 F_32 ( struct V_30 * V_31 ,
struct V_30 * V_49 )
{
struct V_50 V_51 ;
int V_33 ;
V_33 = F_33 ( V_31 , 0 , & V_51 ) ;
if ( V_33 )
return V_33 ;
return F_15 ( V_31 , V_51 . V_52 , F_34 ( & V_51 ) ) ;
}
