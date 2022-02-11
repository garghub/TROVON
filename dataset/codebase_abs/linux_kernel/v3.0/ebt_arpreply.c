static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const T_1 * V_8 , * V_9 ;
T_1 V_10 , V_11 ;
const struct V_12 * V_13 ;
struct V_12 V_14 ;
const unsigned char * V_15 ;
unsigned char V_16 [ V_17 ] ;
V_13 = F_2 ( V_2 , 0 , sizeof( V_14 ) , & V_14 ) ;
if ( V_13 == NULL )
return V_18 ;
if ( V_13 -> V_19 != F_3 ( V_20 ) ||
V_13 -> V_21 != V_17 ||
V_13 -> V_22 != F_3 ( V_23 ) ||
V_13 -> V_24 != 4 )
return V_25 ;
V_15 = F_2 ( V_2 , sizeof( V_14 ) , V_17 , & V_16 ) ;
if ( V_15 == NULL )
return V_18 ;
V_8 = F_2 ( V_2 , sizeof( V_14 ) + V_17 ,
sizeof( V_10 ) , & V_10 ) ;
if ( V_8 == NULL )
return V_18 ;
V_9 = F_2 ( V_2 ,
sizeof( V_14 ) + 2 * V_17 + sizeof( V_10 ) ,
sizeof( V_11 ) , & V_11 ) ;
if ( V_9 == NULL )
return V_18 ;
F_4 ( V_26 , V_27 , * V_8 , (struct V_28 * ) V_4 -> V_29 ,
* V_9 , V_15 , V_6 -> V_30 , V_15 ) ;
return V_6 -> V_31 ;
}
static int F_5 ( const struct V_32 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_33 * V_34 = V_4 -> V_35 ;
if ( V_36 && V_6 -> V_31 == V_37 )
return - V_38 ;
if ( V_34 -> V_39 != F_3 ( V_27 ) ||
V_34 -> V_40 & V_41 )
return - V_38 ;
return 0 ;
}
static int T_2 F_6 ( void )
{
return F_7 ( & V_42 ) ;
}
static void T_3 F_8 ( void )
{
F_9 ( & V_42 ) ;
}
