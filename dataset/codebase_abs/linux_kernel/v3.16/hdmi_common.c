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
int F_9 ( struct V_32 * V_33 , struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 ;
int V_40 , V_5 ;
V_39 = F_10 ( V_35 , L_4 , & V_5 ) ;
if ( V_39 ) {
T_1 V_41 [ 8 ] ;
if ( V_5 / sizeof( T_1 ) != F_4 ( V_41 ) ) {
F_11 ( & V_33 -> V_42 , L_5 ) ;
return - V_43 ;
}
V_40 = F_12 ( V_35 , L_4 , V_41 ,
F_4 ( V_41 ) ) ;
if ( V_40 ) {
F_11 ( & V_33 -> V_42 , L_6 ) ;
return V_40 ;
}
V_40 = F_13 ( V_37 , V_41 ) ;
if ( V_40 ) {
F_11 ( & V_33 -> V_42 , L_7 ) ;
return V_40 ;
}
} else {
static const T_1 V_44 [] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 } ;
V_40 = F_13 ( V_37 , V_44 ) ;
if ( F_14 ( V_40 ) ) {
F_11 ( & V_33 -> V_42 , L_7 ) ;
return V_40 ;
}
}
return 0 ;
}
int F_15 ( T_1 V_45 , T_1 V_46 , T_1 * V_47 , T_1 * V_48 )
{
T_1 V_49 ;
bool V_50 = false ;
if ( V_47 == NULL || V_48 == NULL )
return - V_43 ;
V_49 = 100 ;
switch ( V_46 ) {
case 32000 :
case 48000 :
case 96000 :
case 192000 :
if ( V_49 == 125 )
if ( V_45 == 27027000 || V_45 == 74250000 )
V_50 = true ;
if ( V_49 == 150 )
if ( V_45 == 27027000 )
V_50 = true ;
break;
case 44100 :
case 88200 :
case 176400 :
if ( V_49 == 125 )
if ( V_45 == 27027000 )
V_50 = true ;
break;
default:
return - V_43 ;
}
if ( V_50 ) {
switch ( V_46 ) {
case 32000 :
* V_47 = 8192 ;
break;
case 44100 :
* V_47 = 12544 ;
break;
case 48000 :
* V_47 = 8192 ;
break;
case 88200 :
* V_47 = 25088 ;
break;
case 96000 :
* V_47 = 16384 ;
break;
case 176400 :
* V_47 = 50176 ;
break;
case 192000 :
* V_47 = 32768 ;
break;
default:
return - V_43 ;
}
} else {
switch ( V_46 ) {
case 32000 :
* V_47 = 4096 ;
break;
case 44100 :
* V_47 = 6272 ;
break;
case 48000 :
* V_47 = 6144 ;
break;
case 88200 :
* V_47 = 12544 ;
break;
case 96000 :
* V_47 = 12288 ;
break;
case 176400 :
* V_47 = 25088 ;
break;
case 192000 :
* V_47 = 24576 ;
break;
default:
return - V_43 ;
}
}
* V_48 = ( V_45 / 1000 ) * ( * V_47 / 128 ) * V_49 / ( V_46 / 10 ) ;
return 0 ;
}
