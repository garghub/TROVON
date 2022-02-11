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
if ( V_2 -> V_8 == V_9 )
V_5 = 56448000 ;
else if ( V_2 -> V_8 == V_10 )
V_5 = 564480000 ;
else
V_5 = 282240000 ;
break;
case 8000 :
case 16000 :
case 32000 :
case 48000 :
case 64000 :
case 96000 :
if ( V_2 -> V_8 == V_9 )
V_5 = 73728000 ;
else if ( V_2 -> V_8 == V_10 )
V_5 = 552960000 ;
else
V_5 = 368640000 ;
break;
default:
return - V_11 ;
}
V_6 = ( ( V_5 != V_2 -> V_12 ) ||
( V_4 != V_2 -> V_13 ) ) ;
if ( ! V_6 )
return 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
F_2 ( V_2 -> V_14 ) ;
F_2 ( V_2 -> V_15 ) ;
F_2 ( V_2 -> V_16 ) ;
V_7 = F_3 ( V_2 -> V_16 , V_5 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_17 , L_1 , V_7 ) ;
return V_7 ;
}
V_7 = F_3 ( V_2 -> V_15 , V_4 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_17 , L_2 , V_7 ) ;
return V_7 ;
}
V_7 = F_5 ( V_2 -> V_16 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_17 , L_3 , V_7 ) ;
return V_7 ;
}
V_7 = F_5 ( V_2 -> V_15 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_17 , L_4 , V_7 ) ;
return V_7 ;
}
V_7 = F_5 ( V_2 -> V_14 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_17 , L_5 , V_7 ) ;
return V_7 ;
}
V_2 -> V_12 = V_5 ;
V_2 -> V_13 = V_4 ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
const int V_18 = 73728000 ;
const int V_19 = 24576000 ;
int V_7 ;
F_2 ( V_2 -> V_14 ) ;
F_2 ( V_2 -> V_15 ) ;
F_2 ( V_2 -> V_16 ) ;
V_7 = F_3 ( V_2 -> V_16 , V_18 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_17 , L_1 , V_7 ) ;
return V_7 ;
}
V_7 = F_3 ( V_2 -> V_15 , V_19 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_17 , L_2 , V_7 ) ;
return V_7 ;
}
V_7 = F_5 ( V_2 -> V_16 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_17 , L_3 , V_7 ) ;
return V_7 ;
}
V_7 = F_5 ( V_2 -> V_15 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_17 , L_4 , V_7 ) ;
return V_7 ;
}
V_7 = F_5 ( V_2 -> V_14 ) ;
if ( V_7 ) {
F_4 ( V_2 -> V_17 , L_5 , V_7 ) ;
return V_7 ;
}
V_2 -> V_12 = V_18 ;
V_2 -> V_13 = V_19 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_20 * V_17 )
{
int V_21 ;
V_2 -> V_17 = V_17 ;
if ( F_8 ( L_6 ) )
V_2 -> V_8 = V_9 ;
else if ( F_8 ( L_7 ) )
V_2 -> V_8 = V_10 ;
else if ( F_8 ( L_8 ) )
V_2 -> V_8 = V_22 ;
else {
F_4 ( V_2 -> V_17 , L_9 ) ;
return - V_11 ;
}
V_2 -> V_16 = F_9 ( V_17 , L_10 ) ;
if ( F_10 ( V_2 -> V_16 ) ) {
F_4 ( V_2 -> V_17 , L_11 ) ;
V_21 = F_11 ( V_2 -> V_16 ) ;
goto V_7;
}
V_2 -> V_15 = F_9 ( V_17 , L_12 ) ;
if ( F_10 ( V_2 -> V_15 ) ) {
F_4 ( V_2 -> V_17 , L_13 ) ;
V_21 = F_11 ( V_2 -> V_15 ) ;
goto V_23;
}
V_2 -> V_14 = F_9 ( V_17 , L_14 ) ;
if ( F_10 ( V_2 -> V_14 ) ) {
F_4 ( V_2 -> V_17 , L_15 ) ;
V_21 = F_11 ( V_2 -> V_14 ) ;
goto V_24;
}
V_21 = F_1 ( V_2 , 44100 , 256 * 44100 ) ;
if ( V_21 )
goto V_25;
return 0 ;
V_25:
F_12 ( V_2 -> V_14 ) ;
V_24:
F_12 ( V_2 -> V_15 ) ;
V_23:
F_12 ( V_2 -> V_16 ) ;
V_7:
return V_21 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_14 ) ;
F_12 ( V_2 -> V_15 ) ;
F_12 ( V_2 -> V_16 ) ;
}
