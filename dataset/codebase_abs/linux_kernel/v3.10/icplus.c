static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
static int V_5 = 0 ;
if ( V_5 == 0 ) {
V_3 = F_2 ( V_2 -> V_6 , 30 , 0 , 0x175c ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_3 ( V_2 -> V_6 , 30 , 0 ) ;
F_4 ( 2 ) ;
V_3 = F_2 ( V_2 -> V_6 , 29 , 31 , 0x175c ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 -> V_6 , 29 , 22 , 0x420 ) ;
if ( V_3 < 0 )
return V_3 ;
for ( V_4 = 0 ; V_4 < 5 ; V_4 ++ ) {
V_3 = F_2 ( V_2 -> V_6 , V_4 ,
V_7 , V_8 ) ;
if ( V_3 < 0 )
return V_3 ;
}
for ( V_4 = 0 ; V_4 < 5 ; V_4 ++ )
V_3 = F_3 ( V_2 -> V_6 , V_4 , V_7 ) ;
F_4 ( 2 ) ;
V_5 = 1 ;
}
if ( V_2 -> V_9 != 4 ) {
V_2 -> V_10 = V_11 ;
V_2 -> V_12 = V_13 ;
V_2 -> V_14 = V_15 ;
V_2 -> V_16 = 1 ;
F_5 ( V_2 -> V_17 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_18 ;
V_18 = F_7 ( V_2 , V_7 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 |= V_8 ;
V_18 = F_8 ( V_2 , V_7 , V_18 ) ;
if ( V_18 < 0 )
return V_18 ;
do {
V_18 = F_7 ( V_2 , V_7 ) ;
if ( V_18 < 0 )
return V_18 ;
} while ( V_18 & V_8 );
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_6 ( V_2 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_7 ( V_2 , V_20 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 |= V_21 ;
V_19 = F_8 ( V_2 , V_20 , V_19 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ( V_2 -> V_22 == V_23 ) ||
( V_2 -> V_22 == V_24 ) ||
( V_2 -> V_22 == V_25 ) ||
( V_2 -> V_22 == V_26 ) ) {
V_19 = F_7 ( V_2 , V_27 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 &= ~ ( V_28 | V_29 ) ;
if ( V_2 -> V_22 == V_24 )
V_19 |= ( V_28 | V_29 ) ;
else if ( V_2 -> V_22 == V_25 )
V_19 |= V_28 ;
else if ( V_2 -> V_22 == V_26 )
V_19 |= V_29 ;
V_19 = F_8 ( V_2 , V_27 , V_19 ) ;
if ( V_19 < 0 )
return V_19 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_6 ( V_2 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_8 ( V_2 , V_30 , V_31 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_7 ( V_2 , V_27 ) ;
V_19 |= V_32 ;
return F_8 ( V_2 , V_27 , V_19 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 == 4 )
F_12 ( V_2 ) ;
else
V_2 -> V_33 = V_34 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 == 4 )
F_14 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_3 = F_7 ( V_2 , V_30 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int T_1 F_16 ( void )
{
return F_17 ( V_35 ,
F_18 ( V_35 ) ) ;
}
static void T_2 F_19 ( void )
{
F_20 ( V_35 ,
F_18 ( V_35 ) ) ;
}
