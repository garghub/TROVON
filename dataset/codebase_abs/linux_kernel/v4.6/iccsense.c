static T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 ,
T_2 * V_6 )
{
struct V_7 V_8 ;
T_1 V_9 ;
if ( V_7 ( V_2 , 'P' , & V_8 ) || V_8 . V_10 != 2 ||
V_8 . V_11 < 0x2c )
return 0 ;
V_9 = F_2 ( V_2 , V_8 . V_12 + 0x28 ) ;
if ( ! V_9 )
return 0 ;
* V_3 = F_3 ( V_2 , V_9 + 0 ) ;
switch ( * V_3 ) {
case 0x10 :
case 0x20 :
* V_4 = F_3 ( V_2 , V_9 + 1 ) ;
* V_6 = F_3 ( V_2 , V_9 + 2 ) ;
* V_5 = F_3 ( V_2 , V_9 + 3 ) ;
return V_9 ;
default:
break;
}
return 0 ;
}
int
F_4 ( struct V_1 * V_2 , struct V_13 * V_9 )
{
struct V_14 * V_15 = & V_2 -> V_15 ;
T_2 V_3 , V_4 , V_5 , V_6 , V_16 ;
T_1 V_17 , V_18 ;
V_17 = F_1 ( V_2 , & V_3 , & V_4 , & V_5 , & V_6 ) ;
if ( ! V_17 || ! V_5 )
return - V_19 ;
if ( V_3 != 0x10 && V_3 != 0x20 ) {
F_5 ( V_15 , L_1 , V_3 ) ;
return - V_19 ;
}
V_9 -> V_20 = V_5 ;
V_9 -> V_21 = F_6 ( sizeof( struct V_22 ) * V_5 , V_23 ) ;
if ( ! V_9 -> V_21 )
return - V_24 ;
for ( V_16 = 0 ; V_16 < V_5 ; ++ V_16 ) {
struct V_22 * V_21 = & V_9 -> V_21 [ V_16 ] ;
V_18 = V_17 + V_4 + V_16 * V_6 ;
switch( V_3 ) {
case 0x10 :
V_21 -> V_25 = F_3 ( V_2 , V_18 + 0x1 ) ;
V_21 -> V_26 = F_3 ( V_2 , V_18 + 0x2 ) ;
V_21 -> V_27 = F_3 ( V_2 , V_18 + 0x3 ) ;
V_21 -> V_21 = F_3 ( V_2 , V_18 + 0x4 ) ;
break;
case 0x20 :
V_21 -> V_25 = F_3 ( V_2 , V_18 ) ;
V_21 -> V_26 = F_3 ( V_2 , V_18 + 0x1 ) ;
V_21 -> V_27 = F_3 ( V_2 , V_18 + 0x5 ) ;
V_21 -> V_21 = F_3 ( V_2 , V_18 + 0x6 ) ;
break;
} ;
}
return 0 ;
}
