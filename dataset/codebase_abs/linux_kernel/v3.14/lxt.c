static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_6 == V_7 )
V_3 = F_4 ( V_2 , V_8 , V_9 ) ;
else
V_3 = F_4 ( V_2 , V_8 , 0 ) ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_10 , 0 ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_6 == V_7 )
V_3 = F_4 ( V_2 , V_12 , V_13 ) ;
else
V_3 = F_4 ( V_2 , V_12 , 0 ) ;
return V_3 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_14 ;
int V_15 ;
int V_16 = 8 ;
V_14 = F_2 ( V_2 , V_4 ) ;
if ( V_14 < 0 )
return V_14 ;
V_15 = F_2 ( V_2 , V_17 ) ;
if ( V_15 < 0 )
return V_15 ;
do {
V_14 = F_2 ( V_2 , V_4 ) ;
} while ( V_14 >= 0 && V_16 -- && V_14 == V_15 );
if ( V_14 < 0 )
return V_14 ;
if ( ( V_14 & V_18 ) == 0 )
V_2 -> V_19 = 0 ;
else
V_2 -> V_19 = 1 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_20 ;
int V_3 ;
int V_21 ;
int V_22 = 0 ;
V_3 = F_8 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_23 == V_2 -> V_24 ) {
int V_16 = 1 ;
V_20 = F_2 ( V_2 , V_25 ) ;
if ( V_20 < 0 )
return V_20 ;
do {
V_21 = F_2 ( V_2 , V_26 ) ;
if ( V_21 < 0 )
return V_21 ;
} while ( V_21 == V_20 && V_16 -- );
V_21 &= V_20 ;
V_2 -> V_27 = V_28 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 = V_2 -> V_32 = 0 ;
if ( V_22 & ( V_33 | V_34 ) ) {
V_2 -> V_27 = V_35 ;
if ( V_22 & V_33 )
V_2 -> V_29 = V_36 ;
} else if ( V_21 & ( V_37 | V_38 ) ) {
V_2 -> V_27 = V_39 ;
if ( V_21 & V_37 )
V_2 -> V_29 = V_36 ;
} else {
if ( V_21 & V_40 )
V_2 -> V_29 = V_36 ;
}
if ( V_2 -> V_29 == V_36 ) {
V_2 -> V_31 = V_21 & V_41 ? 1 : 0 ;
V_2 -> V_32 = V_21 & V_42 ? 1 : 0 ;
}
} else {
int V_43 = F_2 ( V_2 , V_17 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_43 & V_44 )
V_2 -> V_29 = V_36 ;
else
V_2 -> V_29 = V_30 ;
if ( V_43 & V_45 )
V_2 -> V_27 = V_35 ;
else if ( V_43 & V_46 )
V_2 -> V_27 = V_39 ;
else
V_2 -> V_27 = V_28 ;
V_2 -> V_31 = V_2 -> V_32 = 0 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_47 = F_2 ( V_2 , V_48 ) ;
if ( V_47 & V_49 ) {
V_47 = F_2 ( V_2 , V_17 ) ;
V_47 |= ( V_46 | V_44 ) ;
V_47 &= ~ V_50 ;
F_4 ( V_2 , V_17 , V_47 ) ;
V_2 -> V_51 = F_10 ;
} else {
V_2 -> V_51 = NULL ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
return V_2 -> V_51 ? 0 : F_12 ( V_2 ) ;
}
static int T_1 F_13 ( void )
{
return F_14 ( V_52 ,
F_15 ( V_52 ) ) ;
}
static void T_2 F_16 ( void )
{
F_17 ( V_52 ,
F_15 ( V_52 ) ) ;
}
