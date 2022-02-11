static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return V_4 & F_2 ( V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned V_3 , int V_5 )
{
if ( V_5 )
V_6 = F_2 ( V_3 ) ;
else
V_7 = F_2 ( V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
unsigned long V_8 ;
F_5 ( V_8 ) ;
V_9 &= ~ F_2 ( V_3 ) ;
F_6 ( V_8 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 , int V_5 )
{
unsigned long V_8 ;
F_5 ( V_8 ) ;
F_3 ( V_2 , V_3 , V_5 ) ;
V_9 |= F_2 ( V_3 ) ;
F_6 ( V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
return V_10 + V_3 ;
}
static int F_9 ( struct V_11 * V_12 , unsigned int type )
{
unsigned int V_13 ;
V_13 = F_10 ( V_12 -> V_14 ) ;
if ( type == V_15 ) {
if ( ( V_16 | V_17 ) & V_13 )
return 0 ;
type = V_18 | V_19 ;
}
if ( type & V_18 )
V_16 |= V_13 ;
else
V_16 &= ~ V_13 ;
if ( type & V_19 )
V_17 |= V_13 ;
else
V_17 &= ~ V_13 ;
V_20 = V_16 & V_21 ;
V_22 = V_17 & V_21 ;
return 0 ;
}
static void F_11 ( struct V_11 * V_12 )
{
V_23 = F_10 ( V_12 -> V_14 ) ;
}
static void F_12 ( struct V_11 * V_12 )
{
unsigned int V_13 = F_10 ( V_12 -> V_14 ) ;
V_21 &= ~ V_13 ;
V_20 &= ~ V_13 ;
V_22 &= ~ V_13 ;
}
static void F_13 ( struct V_11 * V_12 )
{
unsigned int V_13 = F_10 ( V_12 -> V_14 ) ;
V_21 |= V_13 ;
V_20 = V_16 & V_21 ;
V_22 = V_17 & V_21 ;
}
static int F_14 ( struct V_11 * V_12 , unsigned int V_24 )
{
if ( V_24 )
V_25 |= F_10 ( V_12 -> V_14 ) ;
else
V_25 &= ~ F_10 ( V_12 -> V_14 ) ;
return 0 ;
}
static int F_15 ( struct V_26 * V_12 ,
unsigned int V_27 , T_1 V_14 )
{
F_16 ( V_27 , & V_28 ,
V_29 ) ;
F_17 ( V_27 ) ;
return 0 ;
}
static void F_18 ( struct V_30 * V_31 )
{
unsigned int V_27 , V_13 ;
V_13 = V_23 ;
do {
V_23 = V_13 ;
V_27 = V_10 ;
do {
if ( V_13 & 1 )
F_19 ( V_27 ) ;
V_13 >>= 1 ;
V_27 ++ ;
} while ( V_13 );
V_13 = V_23 ;
} while ( V_13 );
}
static int F_20 ( void )
{
V_20 = V_25 & V_16 ;
V_22 = V_25 & V_17 ;
V_23 = V_23 ;
return 0 ;
}
static void F_21 ( void )
{
V_20 = V_16 & V_21 ;
V_22 = V_17 & V_21 ;
}
static int T_2 F_22 ( void )
{
F_23 ( & V_32 ) ;
return 0 ;
}
void T_2 F_24 ( void )
{
V_22 = 0 ;
V_20 = 0 ;
V_23 = - 1 ;
F_25 ( & V_33 ) ;
V_34 = F_26 ( NULL ,
28 , V_10 ,
& V_35 , NULL ) ;
F_27 ( V_36 , F_18 ) ;
F_27 ( V_37 , F_18 ) ;
F_27 ( V_38 , F_18 ) ;
F_27 ( V_39 , F_18 ) ;
F_27 ( V_40 , F_18 ) ;
F_27 ( V_41 , F_18 ) ;
F_27 ( V_42 , F_18 ) ;
F_27 ( V_43 , F_18 ) ;
F_27 ( V_44 , F_18 ) ;
F_27 ( V_45 , F_18 ) ;
F_27 ( V_46 , F_18 ) ;
F_27 ( V_47 , F_18 ) ;
}
