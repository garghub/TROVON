static void F_1 ( struct V_1 * V_2 )
{
char V_3 [ 8 ] ;
switch ( V_2 -> V_4 ) {
case 0 :
snprintf ( V_3 , sizeof( V_3 ) , L_1 ) ;
break;
case 255 :
snprintf ( V_3 , sizeof( V_3 ) , L_2 ) ;
break;
default:
snprintf ( V_3 , sizeof( V_3 ) , L_3 ,
V_2 -> V_4 ) ;
break;
}
F_2 ( & V_2 -> V_2 , L_4 ,
V_2 -> V_5 ? L_5 : L_6 , V_3 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
int V_6 ;
T_1 V_7 , V_8 ;
T_2 V_9 ;
struct V_1 * V_10 ;
if ( ! F_4 ( V_2 ) )
return;
V_6 = F_5 ( V_2 , V_11 ) ;
if ( ! V_6 )
return;
if ( ( F_6 ( V_2 ) == V_12 ||
F_6 ( V_2 ) == V_13 ) )
return;
F_7 ( V_2 , V_6 + V_14 , & V_7 ) ;
V_9 = ( V_7 & V_15 ) >> 8 ;
V_10 = F_8 ( V_2 ) ;
if ( V_10 && V_10 -> V_16 ) {
V_8 = V_17 ;
if ( V_10 -> V_4 == 0 )
V_2 -> V_4 = 0 ;
else if ( V_10 -> V_4 > V_9 )
V_2 -> V_4 = V_10 -> V_4 ;
} else {
if ( V_7 & V_18 ) {
V_8 = V_17 | V_19 ;
V_2 -> V_5 = 1 ;
V_2 -> V_4 = V_9 ;
} else
return;
}
V_8 |= V_2 -> V_4 << 8 ;
F_9 ( V_2 , V_6 + V_20 , V_8 ) ;
V_2 -> V_16 = 1 ;
F_1 ( V_2 ) ;
}
int F_10 ( struct V_1 * V_2 , T_2 * V_21 )
{
int V_6 ;
T_1 V_7 , V_8 ;
struct V_1 * V_10 ;
if ( ! F_4 ( V_2 ) )
return - V_22 ;
V_6 = F_5 ( V_2 , V_11 ) ;
if ( ! V_6 )
return - V_22 ;
F_7 ( V_2 , V_6 + V_14 , & V_7 ) ;
if ( ! ( V_7 & V_23 ) )
return - V_22 ;
if ( F_6 ( V_2 ) == V_12 ) {
V_10 = F_8 ( V_2 ) ;
if ( ! V_10 || ! V_10 -> V_16 )
return - V_22 ;
V_2 -> V_4 = V_10 -> V_4 ;
} else if ( F_6 ( V_2 ) == V_13 ) {
V_2 -> V_4 = 0 ;
} else
return - V_22 ;
V_8 = V_17 ;
V_8 |= V_2 -> V_4 << 8 ;
F_9 ( V_2 , V_6 + V_20 , V_8 ) ;
V_2 -> V_16 = 1 ;
F_1 ( V_2 ) ;
if ( V_21 )
* V_21 = V_2 -> V_4 ;
return 0 ;
}
