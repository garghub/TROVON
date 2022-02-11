static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
static int V_5 = 0 ;
if ( V_5 == 0 ) {
V_3 = V_2 -> V_6 -> V_7 ( V_2 -> V_6 , 30 , 0 , 0x175c ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = V_2 -> V_6 -> V_8 ( V_2 -> V_6 , 30 , 0 ) ;
F_2 ( 2 ) ;
V_3 = V_2 -> V_6 -> V_7 ( V_2 -> V_6 , 29 , 31 , 0x175c ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = V_2 -> V_6 -> V_7 ( V_2 -> V_6 , 29 , 22 , 0x420 ) ;
if ( V_3 < 0 )
return V_3 ;
for ( V_4 = 0 ; V_4 < 5 ; V_4 ++ ) {
V_3 = V_2 -> V_6 -> V_7 ( V_2 -> V_6 , V_4 ,
V_9 , V_10 ) ;
if ( V_3 < 0 )
return V_3 ;
}
for ( V_4 = 0 ; V_4 < 5 ; V_4 ++ )
V_3 = V_2 -> V_6 -> V_8 ( V_2 -> V_6 , V_4 , V_9 ) ;
F_2 ( 2 ) ;
V_5 = 1 ;
}
if ( V_2 -> V_11 != 4 ) {
V_2 -> V_12 = V_13 ;
V_2 -> V_14 = V_15 ;
V_2 -> V_16 = V_17 ;
V_2 -> V_18 = 1 ;
F_3 ( V_2 -> V_19 ) ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 , V_20 ;
V_20 = F_5 ( V_2 , V_9 ) ;
V_20 |= V_10 ;
V_3 = F_6 ( V_2 , V_9 , V_20 ) ;
if ( V_3 < 0 )
return V_3 ;
do {
V_20 = F_5 ( V_2 , V_9 ) ;
} while ( V_20 & V_10 );
V_20 = F_5 ( V_2 , 16 ) ;
V_20 |= 0x3 ;
V_3 = F_6 ( V_2 , 16 , V_20 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_3 ;
}
static int F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == 4 )
F_8 ( V_2 ) ;
else
V_2 -> V_21 = V_22 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == 4 )
F_10 ( V_2 ) ;
return 0 ;
}
static int T_1 F_11 ( void )
{
int V_23 = 0 ;
V_23 = F_12 ( & V_24 ) ;
if ( V_23 < 0 )
return - V_25 ;
return F_12 ( & V_26 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_24 ) ;
F_14 ( & V_26 ) ;
}
