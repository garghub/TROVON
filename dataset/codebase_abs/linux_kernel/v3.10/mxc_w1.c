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
struct V_14 * V_15 ;
int V_16 = 0 ;
V_10 = F_7 ( & V_13 -> V_5 , sizeof( struct V_4 ) ,
V_17 ) ;
if ( ! V_10 )
return - V_18 ;
V_10 -> V_19 = F_8 ( & V_13 -> V_5 , NULL ) ;
if ( F_9 ( V_10 -> V_19 ) )
return F_10 ( V_10 -> V_19 ) ;
V_10 -> V_20 = ( F_11 ( V_10 -> V_19 ) / 1000000 ) - 1 ;
V_15 = F_12 ( V_13 , V_21 , 0 ) ;
V_10 -> V_6 = F_13 ( & V_13 -> V_5 , V_15 ) ;
if ( F_9 ( V_10 -> V_6 ) )
return F_10 ( V_10 -> V_6 ) ;
F_14 ( V_10 -> V_19 ) ;
F_2 ( V_10 -> V_20 , V_10 -> V_6 + V_22 ) ;
V_10 -> V_23 . V_1 = V_10 ;
V_10 -> V_23 . V_24 = F_1 ;
V_10 -> V_23 . V_25 = F_5 ;
V_16 = F_15 ( & V_10 -> V_23 ) ;
if ( V_16 )
return V_16 ;
F_16 ( V_13 , V_10 ) ;
return 0 ;
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_4 * V_10 = F_18 ( V_13 ) ;
F_19 ( & V_10 -> V_23 ) ;
F_20 ( V_10 -> V_19 ) ;
F_16 ( V_13 , NULL ) ;
return 0 ;
}
