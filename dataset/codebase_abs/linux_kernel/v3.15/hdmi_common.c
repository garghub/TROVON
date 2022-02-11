const struct V_1 * F_1 ( void )
{
return & V_2 [ 0 ] ;
}
static const struct V_1 * F_2 ( int V_3 ,
const struct V_1 * V_4 , int V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ ) {
if ( V_4 [ V_6 ] . V_7 . V_3 == V_3 )
return & V_4 [ V_6 ] ;
}
return NULL ;
}
const struct V_1 * F_3 ( int V_8 , int V_3 )
{
const struct V_1 * V_9 ;
int V_5 ;
if ( V_8 == V_10 ) {
V_9 = V_2 ;
V_5 = F_4 ( V_2 ) ;
} else {
V_9 = V_11 ;
V_5 = F_4 ( V_11 ) ;
}
return F_2 ( V_3 , V_9 , V_5 ) ;
}
static bool F_5 ( struct V_12 * V_13 ,
const struct V_12 * V_14 )
{
int V_15 , V_16 , V_17 , V_18 ;
if ( ( F_6 ( V_14 -> V_19 , 1000000 ) ==
F_6 ( V_13 -> V_19 , 1000000 ) ) &&
( V_14 -> V_20 == V_13 -> V_20 ) &&
( V_14 -> V_21 == V_13 -> V_21 ) ) {
V_18 = V_14 -> V_22 + V_14 -> V_23 + V_14 -> V_24 ;
V_16 = V_13 -> V_22 + V_13 -> V_23 + V_13 -> V_24 ;
V_17 = V_14 -> V_25 + V_14 -> V_26 + V_14 -> V_27 ;
V_15 = V_13 -> V_25 + V_13 -> V_26 + V_13 -> V_27 ;
F_7 ( L_1\
L_2 ,
V_16 , V_15 ,
V_18 , V_17 ) ;
if ( ( V_16 == V_18 ) &&
( V_15 == V_17 ) ) {
return true ;
}
}
return false ;
}
struct V_28 F_8 ( struct V_12 * V_29 )
{
int V_6 ;
struct V_28 V_7 = { - 1 } ;
F_7 ( L_3 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_11 ) ; V_6 ++ ) {
if ( F_5 ( V_29 , & V_11 [ V_6 ] . V_30 ) ) {
V_7 = V_11 [ V_6 ] . V_7 ;
goto V_31;
}
}
for ( V_6 = 0 ; V_6 < F_4 ( V_2 ) ; V_6 ++ ) {
if ( F_5 ( V_29 , & V_2 [ V_6 ] . V_30 ) ) {
V_7 = V_2 [ V_6 ] . V_7 ;
goto V_31;
}
}
V_31:
return V_7 ;
}
int F_9 ( T_1 V_32 , T_1 V_33 , T_1 * V_34 , T_1 * V_35 )
{
T_1 V_36 ;
bool V_37 = false ;
if ( V_34 == NULL || V_35 == NULL )
return - V_38 ;
V_36 = 100 ;
switch ( V_33 ) {
case 32000 :
case 48000 :
case 96000 :
case 192000 :
if ( V_36 == 125 )
if ( V_32 == 27027000 || V_32 == 74250000 )
V_37 = true ;
if ( V_36 == 150 )
if ( V_32 == 27027000 )
V_37 = true ;
break;
case 44100 :
case 88200 :
case 176400 :
if ( V_36 == 125 )
if ( V_32 == 27027000 )
V_37 = true ;
break;
default:
return - V_38 ;
}
if ( V_37 ) {
switch ( V_33 ) {
case 32000 :
* V_34 = 8192 ;
break;
case 44100 :
* V_34 = 12544 ;
break;
case 48000 :
* V_34 = 8192 ;
break;
case 88200 :
* V_34 = 25088 ;
break;
case 96000 :
* V_34 = 16384 ;
break;
case 176400 :
* V_34 = 50176 ;
break;
case 192000 :
* V_34 = 32768 ;
break;
default:
return - V_38 ;
}
} else {
switch ( V_33 ) {
case 32000 :
* V_34 = 4096 ;
break;
case 44100 :
* V_34 = 6272 ;
break;
case 48000 :
* V_34 = 6144 ;
break;
case 88200 :
* V_34 = 12544 ;
break;
case 96000 :
* V_34 = 12288 ;
break;
case 176400 :
* V_34 = 25088 ;
break;
case 192000 :
* V_34 = 24576 ;
break;
default:
return - V_38 ;
}
}
* V_35 = ( V_32 / 1000 ) * ( * V_34 / 128 ) * V_36 / ( V_33 / 10 ) ;
return 0 ;
}
