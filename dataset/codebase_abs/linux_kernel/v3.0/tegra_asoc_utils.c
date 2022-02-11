int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
int V_5 ;
bool V_6 ;
int V_7 ;
switch ( V_3 ) {
case 11025 :
case 22050 :
case 44100 :
case 88200 :
V_5 = 56448000 ;
break;
case 8000 :
case 16000 :
case 32000 :
case 48000 :
case 64000 :
case 96000 :
V_5 = 73728000 ;
break;
default:
return - V_8 ;
}
V_6 = ( ( V_5 != V_2 -> V_9 ) ||
( V_4 != V_2 -> V_10 ) ) ;
if ( ! V_6 )
return 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
F_2 ( V_2 -> V_11 ) ;
F_2 ( V_2 -> V_12 ) ;
F_2 ( V_2 -> V_13 ) ;
V_7 = F_3 ( V_2 -> V_13 , V_5 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_14 , L_1 , V_7 ) ;
return V_7 ;
}
V_7 = F_3 ( V_2 -> V_12 , V_4 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_14 , L_2 , V_7 ) ;
return V_7 ;
}
V_7 = F_5 ( V_2 -> V_13 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_14 , L_3 , V_7 ) ;
return V_7 ;
}
V_7 = F_5 ( V_2 -> V_12 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_14 , L_4 , V_7 ) ;
return V_7 ;
}
V_7 = F_5 ( V_2 -> V_11 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_14 , L_5 , V_7 ) ;
return V_7 ;
}
V_2 -> V_9 = V_5 ;
V_2 -> V_10 = V_4 ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_15 * V_14 )
{
int V_16 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_13 = F_7 ( NULL , L_6 ) ;
if ( F_8 ( V_2 -> V_13 ) ) {
F_4 ( V_2 -> V_14 , L_7 ) ;
V_16 = F_9 ( V_2 -> V_13 ) ;
goto V_7;
}
V_2 -> V_12 = F_7 ( NULL , L_8 ) ;
if ( F_8 ( V_2 -> V_12 ) ) {
F_4 ( V_2 -> V_14 , L_9 ) ;
V_16 = F_9 ( V_2 -> V_12 ) ;
goto V_17;
}
V_2 -> V_11 = F_7 ( NULL , L_10 ) ;
if ( F_8 ( V_2 -> V_11 ) ) {
F_4 ( V_2 -> V_14 , L_11 ) ;
V_16 = F_9 ( V_2 -> V_11 ) ;
goto V_18;
}
return 0 ;
V_18:
F_10 ( V_2 -> V_12 ) ;
V_17:
F_10 ( V_2 -> V_13 ) ;
V_7:
return V_16 ;
}
void F_11 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_11 ) ;
F_10 ( V_2 -> V_12 ) ;
F_10 ( V_2 -> V_13 ) ;
}
