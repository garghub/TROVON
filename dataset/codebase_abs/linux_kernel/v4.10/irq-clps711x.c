static T_1 void T_2 F_1 ( struct V_1 * V_2 )
{
T_3 V_3 ;
do {
V_3 = F_2 ( V_4 -> V_5 [ 0 ] ) &
F_2 ( V_4 -> V_6 [ 0 ] ) ;
if ( V_3 )
F_3 ( V_4 -> V_7 ,
F_4 ( V_3 ) - 1 , V_2 ) ;
V_3 = F_2 ( V_4 -> V_5 [ 1 ] ) &
F_2 ( V_4 -> V_6 [ 1 ] ) ;
if ( V_3 )
F_3 ( V_4 -> V_7 ,
F_4 ( V_3 ) - 1 + 16 , V_2 ) ;
} while ( V_3 );
}
static void F_5 ( struct V_8 * V_9 )
{
T_4 V_10 = F_6 ( V_9 ) ;
F_7 ( 0 , V_4 -> V_11 + V_12 [ V_10 ] . V_13 ) ;
}
static void F_8 ( struct V_8 * V_9 )
{
T_4 V_10 = F_6 ( V_9 ) ;
void T_5 * V_5 = V_4 -> V_5 [ V_10 / 16 ] ;
T_3 V_14 ;
V_14 = F_9 ( V_5 ) ;
V_14 &= ~ ( 1 << ( V_10 % 16 ) ) ;
F_7 ( V_14 , V_5 ) ;
}
static void F_10 ( struct V_8 * V_9 )
{
T_4 V_10 = F_6 ( V_9 ) ;
void T_5 * V_5 = V_4 -> V_5 [ V_10 / 16 ] ;
T_3 V_14 ;
V_14 = F_9 ( V_5 ) ;
V_14 |= 1 << ( V_10 % 16 ) ;
F_7 ( V_14 , V_5 ) ;
}
static int T_6 F_11 ( struct V_15 * V_16 , unsigned int V_17 ,
T_4 V_18 )
{
T_7 V_19 = V_20 ;
unsigned int V_21 = 0 ;
if ( ! V_12 [ V_18 ] . V_21 )
return 0 ;
if ( V_12 [ V_18 ] . V_21 & V_22 ) {
V_19 = V_23 ;
V_21 |= V_24 ;
} else if ( V_12 [ V_18 ] . V_13 ) {
V_19 = V_25 ;
}
if ( V_12 [ V_18 ] . V_13 )
F_7 ( 0 , V_4 -> V_11 + V_12 [ V_18 ] . V_13 ) ;
F_12 ( V_17 , & V_26 , V_19 ) ;
F_13 ( V_17 , V_27 , V_21 ) ;
return 0 ;
}
static int T_6 F_14 ( struct V_28 * V_29 ,
T_8 V_11 , T_9 V_30 )
{
int V_31 ;
V_4 = F_15 ( sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 )
return - V_33 ;
V_4 -> V_11 = F_16 ( V_11 , V_30 ) ;
if ( ! V_4 -> V_11 ) {
V_31 = - V_33 ;
goto V_34;
}
V_4 -> V_6 [ 0 ] = V_4 -> V_11 + V_35 ;
V_4 -> V_5 [ 0 ] = V_4 -> V_11 + V_36 ;
V_4 -> V_6 [ 1 ] = V_4 -> V_11 + V_37 ;
V_4 -> V_5 [ 1 ] = V_4 -> V_11 + V_38 ;
V_4 -> V_6 [ 2 ] = V_4 -> V_11 + V_39 ;
V_4 -> V_5 [ 2 ] = V_4 -> V_11 + V_40 ;
F_7 ( 0 , V_4 -> V_5 [ 0 ] ) ;
F_7 ( 0 , V_4 -> V_5 [ 1 ] ) ;
F_7 ( 0 , V_4 -> V_5 [ 2 ] ) ;
V_31 = F_17 ( - 1 , 0 , F_18 ( V_12 ) , F_19 () ) ;
if ( V_31 < 0 )
goto V_41;
V_4 -> V_42 . V_43 = F_11 ;
V_4 -> V_42 . V_44 = V_45 ;
V_4 -> V_7 =
F_20 ( V_29 , F_18 ( V_12 ) ,
0 , 0 , & V_4 -> V_42 , NULL ) ;
if ( ! V_4 -> V_7 ) {
V_31 = - V_33 ;
goto V_46;
}
F_21 ( V_4 -> V_7 ) ;
F_22 ( F_1 ) ;
#ifdef F_23
F_24 ( 0 ) ;
#endif
return 0 ;
V_46:
F_25 ( 0 , F_18 ( V_12 ) ) ;
V_41:
F_26 ( V_4 -> V_11 ) ;
V_34:
F_27 ( V_4 ) ;
return V_31 ;
}
void T_6 F_28 ( T_8 V_11 , T_9 V_30 )
{
F_29 ( F_14 ( NULL , V_11 , V_30 ) ) ;
}
static int T_6 F_30 ( struct V_28 * V_29 ,
struct V_28 * V_47 )
{
struct V_48 V_49 ;
int V_31 ;
V_31 = F_31 ( V_29 , 0 , & V_49 ) ;
if ( V_31 )
return V_31 ;
return F_14 ( V_29 , V_49 . V_50 , F_32 ( & V_49 ) ) ;
}
