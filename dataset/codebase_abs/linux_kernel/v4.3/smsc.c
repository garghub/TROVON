static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 , V_4 ,
( ( V_5 == V_2 -> V_6 )
? V_7
: 0 ) ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 = F_4 ( V_2 , V_8 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int T_1 V_9 ;
struct V_10 * T_2 T_1 = & V_2 -> T_2 ;
struct V_11 * T_3 T_1 = T_2 -> T_3 ;
int V_3 = F_4 ( V_2 , V_12 ) ;
int V_13 = 1 ;
if ( V_3 < 0 )
return V_3 ;
if ( F_6 ( T_3 , L_1 , & V_9 ) )
V_13 = 0 ;
if ( V_13 ) {
V_3 = F_2 ( V_2 , V_12 ,
V_3 | V_14 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return F_3 ( V_2 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 = F_4 ( V_2 , V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ( V_3 & V_16 ) == V_17 ) {
int V_18 = 50000 ;
V_3 |= V_19 ;
F_2 ( V_2 , V_15 , V_3 ) ;
F_2 ( V_2 , V_20 , V_21 ) ;
do {
F_8 ( 10 ) ;
if ( V_18 -- == 0 )
return - 1 ;
V_3 = F_4 ( V_2 , V_20 ) ;
} while ( V_3 & V_21 );
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_22 = F_11 ( V_2 ) ;
int V_23 ;
if ( ! V_2 -> V_24 ) {
int V_3 = F_4 ( V_2 , V_12 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_12 ,
V_3 & ~ V_14 ) ;
if ( V_3 < 0 )
return V_3 ;
for ( V_23 = 0 ; V_23 < 64 ; V_23 ++ ) {
F_12 ( 10 ) ;
V_3 = F_4 ( V_2 , V_12 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 & V_25 )
break;
}
V_3 = F_4 ( V_2 , V_12 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_12 ,
V_3 | V_14 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return V_22 ;
}
