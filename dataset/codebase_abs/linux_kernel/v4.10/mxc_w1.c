static T_1 F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
unsigned long V_4 ;
F_2 ( V_5 , V_3 -> V_6 + V_7 ) ;
V_4 = V_8 + F_3 ( 1500 ) ;
F_4 ( 511 + 512 ) ;
do {
T_1 V_9 = F_5 ( V_3 -> V_6 + V_7 ) ;
if ( ! ( V_9 & V_5 ) )
return ! ( V_9 & V_10 ) ;
} while ( F_6 ( V_4 ) );
return 1 ;
}
static T_1 F_7 ( void * V_1 , T_1 V_11 )
{
struct V_2 * V_3 = V_1 ;
unsigned long V_4 ;
F_2 ( F_8 ( V_11 ) , V_3 -> V_6 + V_7 ) ;
V_4 = V_8 + F_3 ( 200 ) ;
F_4 ( 60 ) ;
do {
T_1 V_9 = F_5 ( V_3 -> V_6 + V_7 ) ;
if ( ! ( V_9 & F_8 ( V_11 ) ) )
return ! ! ( V_9 & V_12 ) ;
} while ( F_6 ( V_4 ) );
return 0 ;
}
static int F_9 ( struct V_13 * V_14 )
{
struct V_2 * V_15 ;
unsigned long V_16 ;
struct V_17 * V_18 ;
unsigned int V_19 ;
int V_20 ;
V_15 = F_10 ( & V_14 -> V_3 , sizeof( struct V_2 ) ,
V_21 ) ;
if ( ! V_15 )
return - V_22 ;
V_15 -> V_23 = F_11 ( & V_14 -> V_3 , NULL ) ;
if ( F_12 ( V_15 -> V_23 ) )
return F_13 ( V_15 -> V_23 ) ;
V_16 = F_14 ( V_15 -> V_23 ) ;
if ( V_16 < 10000000 )
F_15 ( & V_14 -> V_3 ,
L_1 ) ;
V_19 = F_16 ( V_16 , 1000000 ) ;
V_16 /= V_19 ;
if ( ( V_16 < 980000 ) || ( V_16 > 1020000 ) )
F_15 ( & V_14 -> V_3 ,
L_2 , V_16 ) ;
V_18 = F_17 ( V_14 , V_24 , 0 ) ;
V_15 -> V_6 = F_18 ( & V_14 -> V_3 , V_18 ) ;
if ( F_12 ( V_15 -> V_6 ) )
return F_13 ( V_15 -> V_6 ) ;
V_20 = F_19 ( V_15 -> V_23 ) ;
if ( V_20 )
return V_20 ;
F_2 ( V_25 , V_15 -> V_6 + V_26 ) ;
F_2 ( 0 , V_15 -> V_6 + V_26 ) ;
F_2 ( V_19 - 1 , V_15 -> V_6 + V_27 ) ;
V_15 -> V_28 . V_1 = V_15 ;
V_15 -> V_28 . V_29 = F_1 ;
V_15 -> V_28 . V_30 = F_7 ;
F_20 ( V_14 , V_15 ) ;
V_20 = F_21 ( & V_15 -> V_28 ) ;
if ( V_20 )
F_22 ( V_15 -> V_23 ) ;
return V_20 ;
}
static int F_23 ( struct V_13 * V_14 )
{
struct V_2 * V_15 = F_24 ( V_14 ) ;
F_25 ( & V_15 -> V_28 ) ;
F_22 ( V_15 -> V_23 ) ;
return 0 ;
}
