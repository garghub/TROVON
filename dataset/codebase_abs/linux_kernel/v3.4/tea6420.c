static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 = ( V_4 >> 4 ) & 0xf ;
T_2 V_9 ;
int V_10 ;
V_4 &= 0xf ;
F_3 ( 1 , V_11 , V_2 , L_1 , V_3 , V_4 , V_8 ) ;
if ( V_3 < 1 || V_3 > 6 || V_4 < 1 || V_4 > 4 || V_8 < 0 || V_8 > 6 || V_8 % 2 != 0 )
return - V_12 ;
V_9 = ( ( V_4 - 1 ) << 5 ) ;
V_9 |= ( V_3 - 1 ) ;
switch ( V_8 ) {
case 0 :
V_9 |= ( 3 << 3 ) ;
break;
case 2 :
V_9 |= ( 2 << 3 ) ;
break;
case 4 :
V_9 |= ( 1 << 3 ) ;
break;
case 6 :
break;
}
V_10 = F_4 ( V_7 , V_9 ) ;
if ( V_10 ) {
F_3 ( 1 , V_11 , V_2 ,
L_2 , V_10 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_6 ( V_7 , V_15 , V_16 , 0 ) ;
}
static int F_7 ( struct V_6 * V_7 ,
const struct V_17 * V_18 )
{
struct V_1 * V_2 ;
int V_19 , V_3 ;
if ( ! F_8 ( V_7 -> V_20 , V_21 ) )
return - V_13 ;
F_9 ( V_7 , L_3 ,
V_7 -> V_22 << 1 , V_7 -> V_20 -> V_23 ) ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_24 ) ;
if ( V_2 == NULL )
return - V_25 ;
F_11 ( V_2 , V_7 , & V_26 ) ;
V_19 = 0 ;
for ( V_3 = 1 ; V_3 < 5 ; V_3 ++ )
V_19 += F_1 ( V_2 , 6 , V_3 , 0 ) ;
if ( V_19 ) {
F_12 ( 1 , V_11 , V_7 , L_4 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_14 ( V_7 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
