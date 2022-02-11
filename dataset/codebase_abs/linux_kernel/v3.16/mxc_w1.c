static T_1 F_1 ( void * V_1 )
{
T_1 V_2 ;
unsigned int V_3 = 0 ;
struct V_4 * V_5 = V_1 ;
F_2 ( V_6 , ( V_5 -> V_7 + V_8 ) ) ;
while ( 1 ) {
V_2 = F_3 ( V_5 -> V_7 + V_8 ) ;
if ( ! ( V_2 & V_6 ) ||
V_3 > V_9 )
break;
else
V_3 ++ ;
F_4 ( 100 ) ;
}
return ! ( V_2 & V_10 ) ;
}
static T_1 F_5 ( void * V_1 , T_1 V_11 )
{
struct V_4 * V_12 = V_1 ;
void T_2 * V_13 = V_12 -> V_7 + V_8 ;
unsigned int V_3 = 400 ;
F_2 ( F_6 ( V_11 ) , V_13 ) ;
while ( V_3 -- ) {
if ( ! ( F_3 ( V_13 ) & F_6 ( V_11 ) ) )
break;
F_4 ( 1 ) ;
}
return ! ! ( F_3 ( V_13 ) & V_14 ) ;
}
static int F_7 ( struct V_15 * V_16 )
{
struct V_4 * V_12 ;
unsigned long V_17 ;
struct V_18 * V_19 ;
unsigned int V_20 ;
int V_21 ;
V_12 = F_8 ( & V_16 -> V_5 , sizeof( struct V_4 ) ,
V_22 ) ;
if ( ! V_12 )
return - V_23 ;
V_12 -> V_24 = F_9 ( & V_16 -> V_5 , NULL ) ;
if ( F_10 ( V_12 -> V_24 ) )
return F_11 ( V_12 -> V_24 ) ;
V_17 = F_12 ( V_12 -> V_24 ) ;
if ( V_17 < 10000000 )
F_13 ( & V_16 -> V_5 ,
L_1 ) ;
V_20 = F_14 ( V_17 , 1000000 ) ;
V_17 /= V_20 ;
if ( ( V_17 < 980000 ) || ( V_17 > 1020000 ) )
F_13 ( & V_16 -> V_5 ,
L_2 , V_17 ) ;
V_19 = F_15 ( V_16 , V_25 , 0 ) ;
V_12 -> V_7 = F_16 ( & V_16 -> V_5 , V_19 ) ;
if ( F_10 ( V_12 -> V_7 ) )
return F_11 ( V_12 -> V_7 ) ;
V_21 = F_17 ( V_12 -> V_24 ) ;
if ( V_21 )
return V_21 ;
F_2 ( V_20 - 1 , V_12 -> V_7 + V_26 ) ;
V_12 -> V_27 . V_1 = V_12 ;
V_12 -> V_27 . V_28 = F_1 ;
V_12 -> V_27 . V_29 = F_5 ;
F_18 ( V_16 , V_12 ) ;
V_21 = F_19 ( & V_12 -> V_27 ) ;
if ( V_21 )
F_20 ( V_12 -> V_24 ) ;
return V_21 ;
}
static int F_21 ( struct V_15 * V_16 )
{
struct V_4 * V_12 = F_22 ( V_16 ) ;
F_23 ( & V_12 -> V_27 ) ;
F_20 ( V_12 -> V_24 ) ;
return 0 ;
}
