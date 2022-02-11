static int F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_7 ;
do {
V_7 = F_2 ( V_5 -> V_8 + V_9 ) ;
F_3 () ;
} while ( ! ( V_7 & V_10 ) );
F_4 ( V_3 , V_5 -> V_8 + V_11 ) ;
return 0 ;
}
static T_1 F_5 ( int V_12 , void * V_13 )
{
struct V_4 * V_5 = V_13 ;
unsigned char V_14 , V_15 ;
int V_16 = 0 ;
do {
unsigned int V_17 ;
V_14 = F_2 ( V_5 -> V_8 + V_9 ) ;
if ( ! ( V_14 & V_18 ) )
break;
V_16 = 1 ;
V_15 = F_2 ( V_5 -> V_8 + V_11 ) ;
if ( V_14 == 0xff && V_15 == 0xff )
break;
V_17 = ( V_14 & V_19 ) ? 0 : V_20 ;
if ( F_6 ( V_15 ) & 1 )
V_17 ^= V_20 ;
F_7 ( V_5 -> V_2 , V_15 , V_17 ) ;
} while ( 1 );
return F_8 ( V_16 ) ;
}
static void F_9 ( struct V_4 * V_5 )
{
unsigned char V_14 , V_15 ;
do {
V_14 = F_2 ( V_5 -> V_8 + V_9 ) ;
if ( ! ( V_14 & V_18 ) )
break;
V_15 = F_2 ( V_5 -> V_8 + V_11 ) ;
if ( V_14 == 0xff && V_15 == 0xff )
break;
} while ( 1 );
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_21 , V_3 = 0 ;
F_4 ( V_22 , V_5 -> V_8 ) ;
F_9 ( V_5 ) ;
V_21 = F_11 ( V_5 -> V_23 -> V_12 , F_5 , V_24 ,
L_1 , V_5 ) ;
if ( V_21 == 0 )
V_3 = V_22 | V_25 ;
F_4 ( V_3 , V_5 -> V_8 ) ;
return V_21 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_4 ( 0 , V_5 -> V_8 ) ;
F_13 ( V_5 -> V_23 -> V_12 , V_5 ) ;
}
static int T_2 F_14 ( struct V_26 * V_23 , const struct V_27 * V_28 )
{
struct V_4 * V_5 ;
struct V_1 * V_1 ;
int V_21 ;
V_21 = F_15 ( V_23 ) ;
if ( V_21 )
goto V_29;
V_21 = F_16 ( V_23 , L_1 ) ;
if ( V_21 )
goto V_30;
V_5 = F_17 ( sizeof( struct V_4 ) , V_31 ) ;
V_1 = F_17 ( sizeof( struct V_1 ) , V_31 ) ;
if ( ! V_5 || ! V_1 ) {
V_21 = - V_32 ;
goto V_33;
}
V_1 -> V_28 . type = V_34 ;
V_1 -> V_35 = F_1 ;
V_1 -> V_36 = F_10 ;
V_1 -> V_37 = F_12 ;
F_18 ( V_1 -> V_38 , F_19 ( V_23 ) , sizeof( V_1 -> V_38 ) ) ;
F_18 ( V_1 -> V_39 , F_20 ( & V_23 -> V_23 ) , sizeof( V_1 -> V_39 ) ) ;
V_1 -> V_6 = V_5 ;
V_1 -> V_23 . V_40 = & V_23 -> V_23 ;
V_5 -> V_2 = V_1 ;
V_5 -> V_23 = V_23 ;
V_5 -> V_8 = F_21 ( V_23 , 0 ) ;
F_22 ( V_23 , V_5 ) ;
F_23 ( V_5 -> V_2 ) ;
return 0 ;
V_33:
F_24 ( V_5 ) ;
F_24 ( V_1 ) ;
F_25 ( V_23 ) ;
V_30:
F_26 ( V_23 ) ;
V_29:
return V_21 ;
}
static void T_3 F_27 ( struct V_26 * V_23 )
{
struct V_4 * V_5 = F_28 ( V_23 ) ;
F_29 ( V_5 -> V_2 ) ;
F_22 ( V_23 , NULL ) ;
F_24 ( V_5 ) ;
F_25 ( V_23 ) ;
F_26 ( V_23 ) ;
}
