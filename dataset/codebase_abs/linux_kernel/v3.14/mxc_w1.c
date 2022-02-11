static T_1 F_1 ( void * V_1 )
{
T_1 V_2 ;
unsigned int V_3 = 0 ;
struct V_4 * V_5 = V_1 ;
F_2 ( 0x80 , ( V_5 -> V_6 + V_7 ) ) ;
while ( 1 ) {
V_2 = F_3 ( V_5 -> V_6 + V_7 ) ;
if ( ( ( V_2 >> 7 ) & 0x1 ) == 0 ||
V_3 > V_8 )
break;
else
V_3 ++ ;
F_4 ( 100 ) ;
}
return ( V_2 >> 7 ) & 0x1 ;
}
static T_1 F_5 ( void * V_1 , T_1 V_9 )
{
struct V_4 * V_10 = V_1 ;
void T_2 * V_11 = V_10 -> V_6 + V_7 ;
unsigned int V_3 = 400 ;
F_2 ( ( 1 << ( 5 - V_9 ) ) , V_11 ) ;
while ( V_3 -- ) {
if ( ! ( ( F_3 ( V_11 ) >> ( 5 - V_9 ) ) & 0x1 ) )
break;
F_4 ( 1 ) ;
}
return ( ( F_3 ( V_11 ) ) >> 3 ) & 0x1 ;
}
static int F_6 ( struct V_12 * V_13 )
{
struct V_4 * V_10 ;
unsigned long V_14 ;
struct V_15 * V_16 ;
unsigned int V_17 ;
int V_18 ;
V_10 = F_7 ( & V_13 -> V_5 , sizeof( struct V_4 ) ,
V_19 ) ;
if ( ! V_10 )
return - V_20 ;
V_10 -> V_21 = F_8 ( & V_13 -> V_5 , NULL ) ;
if ( F_9 ( V_10 -> V_21 ) )
return F_10 ( V_10 -> V_21 ) ;
V_14 = F_11 ( V_10 -> V_21 ) ;
if ( V_14 < 10000000 )
F_12 ( & V_13 -> V_5 ,
L_1 ) ;
V_17 = F_13 ( V_14 , 1000000 ) ;
V_14 /= V_17 ;
if ( ( V_14 < 980000 ) || ( V_14 > 1020000 ) )
F_12 ( & V_13 -> V_5 ,
L_2 , V_14 ) ;
V_16 = F_14 ( V_13 , V_22 , 0 ) ;
V_10 -> V_6 = F_15 ( & V_13 -> V_5 , V_16 ) ;
if ( F_9 ( V_10 -> V_6 ) )
return F_10 ( V_10 -> V_6 ) ;
V_18 = F_16 ( V_10 -> V_21 ) ;
if ( V_18 )
return V_18 ;
F_2 ( V_17 - 1 , V_10 -> V_6 + V_23 ) ;
V_10 -> V_24 . V_1 = V_10 ;
V_10 -> V_24 . V_25 = F_1 ;
V_10 -> V_24 . V_26 = F_5 ;
F_17 ( V_13 , V_10 ) ;
V_18 = F_18 ( & V_10 -> V_24 ) ;
if ( V_18 )
F_19 ( V_10 -> V_21 ) ;
return V_18 ;
}
static int F_20 ( struct V_12 * V_13 )
{
struct V_4 * V_10 = F_21 ( V_13 ) ;
F_22 ( & V_10 -> V_24 ) ;
F_19 ( V_10 -> V_21 ) ;
return 0 ;
}
