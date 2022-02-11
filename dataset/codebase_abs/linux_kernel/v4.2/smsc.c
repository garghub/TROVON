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
int V_3 = F_4 ( V_2 , V_9 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_9 ,
V_3 | V_10 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_3 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 = F_4 ( V_2 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( ( V_3 & V_12 ) == V_13 ) {
int V_14 = 50000 ;
V_3 |= V_15 ;
F_2 ( V_2 , V_11 , V_3 ) ;
F_2 ( V_2 , V_16 , V_17 ) ;
do {
F_7 ( 10 ) ;
if ( V_14 -- == 0 )
return - 1 ;
V_3 = F_4 ( V_2 , V_16 ) ;
} while ( V_3 & V_17 );
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_18 = F_10 ( V_2 ) ;
int V_19 ;
if ( ! V_2 -> V_20 ) {
int V_3 = F_4 ( V_2 , V_9 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_9 ,
V_3 & ~ V_10 ) ;
if ( V_3 < 0 )
return V_3 ;
for ( V_19 = 0 ; V_19 < 64 ; V_19 ++ ) {
F_11 ( 10 ) ;
V_3 = F_4 ( V_2 , V_9 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 & V_21 )
break;
}
V_3 = F_4 ( V_2 , V_9 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_9 ,
V_3 | V_10 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return V_18 ;
}
