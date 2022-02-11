static T_1 T_2 F_1 ( void )
{
return ~ F_2 ( V_1 + V_2 ) ;
}
static int
F_3 ( unsigned long V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 ;
F_4 ( V_7 , V_8 + V_9 ) ;
F_4 ( V_3 , V_8 + V_2 ) ;
V_6 = F_2 ( V_8 + V_10 ) ;
V_6 = ( ( V_6 & ~ V_11 ) | V_12 |
F_5 ( V_13 ) ) ;
F_4 ( V_6 , V_8 + V_10 ) ;
return 0 ;
}
static void
F_6 ( enum V_14 V_15 ,
struct V_4 * V_5 )
{
T_1 V_6 ;
if ( V_15 == V_16 ) {
F_4 ( V_17 - 1 , V_8 + V_18 ) ;
F_4 ( V_17 - 1 , V_8 + V_2 ) ;
V_6 = F_2 ( V_8 + V_10 ) ;
F_4 ( ( V_6 | V_12 | V_11 |
F_5 ( V_13 ) ) ,
V_8 + V_10 ) ;
} else {
V_6 = F_2 ( V_8 + V_10 ) ;
F_4 ( V_6 & ~ V_12 , V_8 + V_10 ) ;
F_4 ( V_7 , V_8 + V_9 ) ;
}
}
static T_3 F_7 ( int V_19 , void * V_20 )
{
struct V_4 * V_21 = * (struct V_4 * * ) V_20 ;
F_4 ( V_7 , V_8 + V_9 ) ;
V_21 -> V_22 ( V_21 ) ;
return V_23 ;
}
static int T_4 F_8 ( struct V_4 * V_21 )
{
T_1 V_6 ;
int V_24 = F_9 () ;
if ( ! F_9 () )
return 0 ;
V_6 = F_2 ( V_8 + V_10 ) ;
if ( V_25 )
F_4 ( V_6 | V_26 , V_8 + V_10 ) ;
else
F_4 ( V_6 & ~ V_26 , V_8 + V_10 ) ;
V_21 -> V_27 = V_28 . V_27 ;
V_21 -> V_19 = V_28 . V_19 ;
V_21 -> V_29 = V_28 . V_29 ;
V_21 -> V_30 = V_28 . V_30 ;
V_21 -> V_31 = V_28 . V_31 ,
V_21 -> V_32 = F_3 ,
V_21 -> V_33 = F_6 ,
V_21 -> V_34 = F_10 ( V_24 ) ;
* F_11 ( V_35 ) = V_21 ;
F_12 ( V_21 , V_36 , 1 , 0xfffffffe ) ;
F_13 ( V_21 -> V_19 , 0 ) ;
return 0 ;
}
static void F_14 ( struct V_4 * V_21 )
{
V_21 -> V_33 ( V_37 , V_21 ) ;
F_15 ( V_21 -> V_19 ) ;
}
void T_5 F_16 ( void )
{
T_1 V_6 ;
struct V_38 * V_39 ;
int V_40 ;
V_39 = F_17 ( NULL , NULL , L_1 ) ;
V_1 = F_18 ( V_39 , 0 ) ;
F_19 ( ! V_1 ) ;
V_8 = F_18 ( V_39 , 1 ) ;
if ( F_20 ( V_39 , L_2 , NULL ) ) {
V_6 = F_2 ( V_8 + V_10 ) ;
F_4 ( V_6 | V_26 ,
V_8 + V_10 ) ;
V_6 = F_2 ( V_1 + V_10 ) ;
F_4 ( V_6 | V_26 ,
V_1 + V_10 ) ;
V_36 = 25000000 ;
} else {
unsigned long V_41 = 0 ;
struct V_42 * V_42 = F_21 ( V_39 , 0 ) ;
F_19 ( F_22 ( V_42 ) ) ;
V_41 = F_23 ( V_42 ) ;
V_6 = F_2 ( V_8 + V_10 ) ;
F_4 ( V_6 & ~ ( V_26 ) ,
V_8 + V_10 ) ;
V_6 = F_2 ( V_1 + V_10 ) ;
F_4 ( V_6 & ~ ( V_26 ) ,
V_1 + V_10 ) ;
V_36 = V_41 / V_43 ;
V_25 = false ;
}
V_28 . V_19 = F_24 ( V_39 , 4 ) ;
V_17 = ( V_36 + V_44 / 2 ) / V_44 ;
F_25 ( F_1 , 32 , V_36 ) ;
F_4 ( 0xffffffff , V_1 + V_2 ) ;
F_4 ( 0xffffffff , V_1 + V_18 ) ;
V_6 = F_2 ( V_1 + V_10 ) ;
F_4 ( ( V_6 | V_12 | V_11 |
F_5 ( V_13 ) ) , V_1 + V_10 ) ;
F_26 ( V_1 + V_2 ,
L_3 ,
V_36 , 300 , 32 , V_45 ) ;
V_28 . V_34 = F_10 ( 0 ) ;
F_12 ( & V_28 ,
V_36 , 1 , 0xfffffffe ) ;
V_35 = F_27 ( struct V_4 * ) ;
* F_11 ( V_35 ) = & V_28 ;
V_40 = F_28 ( V_28 . V_19 ,
F_7 ,
V_28 . V_27 ,
V_35 ) ;
if ( ! V_40 ) {
F_13 ( V_28 . V_19 , 0 ) ;
#ifdef F_29
F_30 ( & V_46 ) ;
#endif
}
}
