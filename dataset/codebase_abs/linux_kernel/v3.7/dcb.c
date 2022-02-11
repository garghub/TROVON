T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 = 0x0000 ;
if ( V_8 -> V_10 > V_11 )
V_9 = F_3 ( V_2 , 0x36 ) ;
if ( ! V_9 ) {
F_4 ( V_2 , L_1 ) ;
return V_9 ;
}
* V_3 = F_5 ( V_2 , V_9 ) ;
if ( * V_3 >= 0x41 ) {
F_4 ( V_2 , L_2 , * V_3 ) ;
return 0x0000 ;
} else
if ( * V_3 >= 0x30 ) {
if ( F_6 ( V_2 , V_9 + 6 ) == 0x4edcbdcb ) {
* V_4 = F_5 ( V_2 , V_9 + 1 ) ;
* V_5 = F_5 ( V_2 , V_9 + 2 ) ;
* V_6 = F_5 ( V_2 , V_9 + 3 ) ;
return V_9 ;
}
} else
if ( * V_3 >= 0x20 ) {
if ( F_6 ( V_2 , V_9 + 4 ) == 0x4edcbdcb ) {
T_1 V_12 = F_3 ( V_2 , V_9 + 2 ) ;
* V_4 = 8 ;
* V_5 = ( V_12 - V_9 ) / 8 ;
* V_6 = 8 ;
return V_9 ;
}
} else
if ( * V_3 >= 0x15 ) {
if ( ! F_7 ( V_2 , V_9 - 7 , L_3 , 7 ) ) {
T_1 V_12 = F_3 ( V_2 , V_9 + 2 ) ;
* V_4 = 4 ;
* V_5 = ( V_12 - V_9 ) / 10 ;
* V_6 = 10 ;
return V_9 ;
}
} else {
F_4 ( V_2 , L_4 ) ;
return 0x0000 ;
}
F_4 ( V_2 , L_5 ) ;
return 0x0000 ;
}
T_1
F_8 ( struct V_1 * V_2 , T_2 V_13 , T_2 * V_3 , T_2 * V_6 )
{
T_2 V_4 , V_5 ;
T_1 V_9 = F_1 ( V_2 , V_3 , & V_4 , & V_5 , V_6 ) ;
if ( V_9 && V_13 < V_5 )
return V_9 + V_4 + ( V_13 * * V_6 ) ;
return 0x0000 ;
}
int
F_9 ( struct V_1 * V_2 , void * V_14 ,
int (* F_10)( struct V_1 * , void * , int , T_1 ) )
{
int V_15 , V_13 = - 1 ;
T_2 V_3 , V_6 ;
T_1 V_16 ;
while ( ( V_16 = F_8 ( V_2 , ++ V_13 , & V_3 , & V_6 ) ) ) {
if ( F_6 ( V_2 , V_16 ) == 0x00000000 )
break;
if ( F_6 ( V_2 , V_16 ) == 0xffffffff )
break;
if ( F_5 ( V_2 , V_16 ) == V_17 )
continue;
if ( F_5 ( V_2 , V_16 ) == V_18 )
break;
V_15 = F_10 ( V_2 , V_14 , V_13 , V_16 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
