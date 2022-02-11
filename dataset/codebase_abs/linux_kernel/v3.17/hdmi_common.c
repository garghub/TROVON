int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_9 , V_10 ;
V_8 = F_2 ( V_4 , L_1 , & V_10 ) ;
if ( V_8 ) {
T_1 V_11 [ 8 ] ;
if ( V_10 / sizeof( T_1 ) != F_3 ( V_11 ) ) {
F_4 ( & V_2 -> V_12 , L_2 ) ;
return - V_13 ;
}
V_9 = F_5 ( V_4 , L_1 , V_11 ,
F_3 ( V_11 ) ) ;
if ( V_9 ) {
F_4 ( & V_2 -> V_12 , L_3 ) ;
return V_9 ;
}
V_9 = F_6 ( V_6 , V_11 ) ;
if ( V_9 ) {
F_4 ( & V_2 -> V_12 , L_4 ) ;
return V_9 ;
}
} else {
static const T_1 V_14 [] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 } ;
V_9 = F_6 ( V_6 , V_14 ) ;
if ( F_7 ( V_9 ) ) {
F_4 ( & V_2 -> V_12 , L_4 ) ;
return V_9 ;
}
}
return 0 ;
}
int F_8 ( T_1 V_15 , T_1 V_16 , T_1 * V_17 , T_1 * V_18 )
{
T_1 V_19 ;
bool V_20 = false ;
if ( V_17 == NULL || V_18 == NULL )
return - V_13 ;
V_19 = 100 ;
switch ( V_16 ) {
case 32000 :
case 48000 :
case 96000 :
case 192000 :
if ( V_19 == 125 )
if ( V_15 == 27027000 || V_15 == 74250000 )
V_20 = true ;
if ( V_19 == 150 )
if ( V_15 == 27027000 )
V_20 = true ;
break;
case 44100 :
case 88200 :
case 176400 :
if ( V_19 == 125 )
if ( V_15 == 27027000 )
V_20 = true ;
break;
default:
return - V_13 ;
}
if ( V_20 ) {
switch ( V_16 ) {
case 32000 :
* V_17 = 8192 ;
break;
case 44100 :
* V_17 = 12544 ;
break;
case 48000 :
* V_17 = 8192 ;
break;
case 88200 :
* V_17 = 25088 ;
break;
case 96000 :
* V_17 = 16384 ;
break;
case 176400 :
* V_17 = 50176 ;
break;
case 192000 :
* V_17 = 32768 ;
break;
default:
return - V_13 ;
}
} else {
switch ( V_16 ) {
case 32000 :
* V_17 = 4096 ;
break;
case 44100 :
* V_17 = 6272 ;
break;
case 48000 :
* V_17 = 6144 ;
break;
case 88200 :
* V_17 = 12544 ;
break;
case 96000 :
* V_17 = 12288 ;
break;
case 176400 :
* V_17 = 25088 ;
break;
case 192000 :
* V_17 = 24576 ;
break;
default:
return - V_13 ;
}
}
* V_18 = ( V_15 / 1000 ) * ( * V_17 / 128 ) * V_19 / ( V_16 / 10 ) ;
return 0 ;
}
