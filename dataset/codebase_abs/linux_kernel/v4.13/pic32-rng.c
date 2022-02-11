static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 ,
bool V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
T_2 * V_8 = V_3 ;
T_3 V_9 ;
unsigned int V_10 = V_11 ;
do {
V_9 = F_3 ( V_7 -> V_12 + V_13 ) & V_14 ;
if ( V_9 == 64 ) {
* V_8 = ( ( T_2 ) F_3 ( V_7 -> V_12 + V_15 ) << 32 ) +
F_3 ( V_7 -> V_12 + V_16 ) ;
return 8 ;
}
} while ( V_5 && -- V_10 );
return - V_17 ;
}
static int F_4 ( struct V_18 * V_19 )
{
struct V_6 * V_7 ;
struct V_20 * V_21 ;
T_3 V_22 ;
int V_23 ;
V_7 = F_5 ( & V_19 -> V_24 , sizeof( * V_7 ) , V_25 ) ;
if ( ! V_7 )
return - V_26 ;
V_21 = F_6 ( V_19 , V_27 , 0 ) ;
V_7 -> V_12 = F_7 ( & V_19 -> V_24 , V_21 ) ;
if ( F_8 ( V_7 -> V_12 ) )
return F_9 ( V_7 -> V_12 ) ;
V_7 -> V_28 = F_10 ( & V_19 -> V_24 , NULL ) ;
if ( F_8 ( V_7 -> V_28 ) )
return F_9 ( V_7 -> V_28 ) ;
V_23 = F_11 ( V_7 -> V_28 ) ;
if ( V_23 )
return V_23 ;
V_22 = V_29 | V_30 ;
F_12 ( V_22 , V_7 -> V_12 + V_31 ) ;
V_7 -> V_2 . V_32 = V_19 -> V_32 ;
V_7 -> V_2 . V_33 = F_1 ;
V_23 = F_13 ( & V_7 -> V_2 ) ;
if ( V_23 )
goto V_34;
F_14 ( V_19 , V_7 ) ;
return 0 ;
V_34:
F_15 ( V_7 -> V_28 ) ;
return V_23 ;
}
static int F_16 ( struct V_18 * V_19 )
{
struct V_6 * V_2 = F_17 ( V_19 ) ;
F_18 ( & V_2 -> V_2 ) ;
F_12 ( 0 , V_2 -> V_12 + V_31 ) ;
F_15 ( V_2 -> V_28 ) ;
return 0 ;
}
