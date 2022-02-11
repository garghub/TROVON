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
struct V_9 * V_10 = V_2 -> V_10 ;
int V_3 = F_4 ( V_2 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_10 -> V_12 ) {
V_3 = F_2 ( V_2 , V_11 ,
V_3 | V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return F_3 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 = F_4 ( V_2 , V_14 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ( V_3 & V_15 ) == V_16 ) {
int V_17 = 50000 ;
V_3 |= V_18 ;
F_2 ( V_2 , V_14 , V_3 ) ;
F_2 ( V_2 , V_19 , V_20 ) ;
do {
F_7 ( 10 ) ;
if ( V_17 -- == 0 )
return - 1 ;
V_3 = F_4 ( V_2 , V_19 ) ;
} while ( V_3 & V_20 );
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
int V_21 = F_10 ( V_2 ) ;
if ( ! V_2 -> V_22 && V_10 -> V_12 ) {
int V_23 ;
int V_3 = F_4 ( V_2 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_11 ,
V_3 & ~ V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
for ( V_23 = 0 ; V_23 < 64 ; V_23 ++ ) {
F_11 ( 10 ) ;
V_3 = F_4 ( V_2 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 & V_24 )
break;
}
V_3 = F_4 ( V_2 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_11 ,
V_3 | V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return V_21 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_27 . V_26 ;
struct V_28 * V_29 = V_26 -> V_29 ;
struct V_9 * V_10 ;
V_10 = F_13 ( V_26 , sizeof( * V_10 ) , V_30 ) ;
if ( ! V_10 )
return - V_31 ;
V_10 -> V_12 = true ;
if ( F_14 ( V_29 , L_1 ) )
V_10 -> V_12 = false ;
V_2 -> V_10 = V_10 ;
return 0 ;
}
