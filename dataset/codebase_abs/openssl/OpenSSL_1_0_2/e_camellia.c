static int F_1 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 , V_6 , V_7 ;
T_2 * V_8 = ( T_2 * ) V_1 -> V_9 ;
V_6 = V_1 -> V_10 -> V_11 & V_12 ;
V_7 = V_1 -> V_13 * 8 ;
F_2 ( V_2 , V_7 , & V_8 -> V_14 ) ;
if ( ( V_6 == V_15 || V_6 == V_16 )
&& ! V_4 ) {
V_5 = 0 ;
V_8 -> V_17 = ( V_18 ) V_19 ;
switch ( V_7 ) {
case 128 :
V_8 -> V_20 . V_21 = V_6 == V_16 ?
( V_22 ) V_23 : NULL ;
break;
case 192 :
case 256 :
V_8 -> V_20 . V_21 = V_6 == V_16 ?
( V_22 ) V_24 : NULL ;
break;
default:
V_5 = - 1 ;
}
} else {
V_5 = 0 ;
V_8 -> V_17 = ( V_18 ) V_25 ;
switch ( V_7 ) {
case 128 :
if ( V_6 == V_16 )
V_8 -> V_20 . V_21 = ( V_22 ) V_26 ;
else if ( V_6 == V_27 )
V_8 -> V_20 . V_28 = ( V_29 ) V_30 ;
else
V_8 -> V_20 . V_21 = NULL ;
break;
case 192 :
case 256 :
if ( V_6 == V_16 )
V_8 -> V_20 . V_21 = ( V_22 ) V_31 ;
else if ( V_6 == V_27 )
V_8 -> V_20 . V_28 = ( V_29 ) V_32 ;
else
V_8 -> V_20 . V_21 = NULL ;
break;
default:
V_5 = - 1 ;
}
}
if ( V_5 < 0 ) {
F_3 ( V_33 , V_34 ) ;
return 0 ;
}
return 1 ;
}
static int F_4 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 , V_6 ;
T_2 * V_8 = ( T_2 * ) V_1 -> V_9 ;
V_5 = F_5 ( V_2 , V_1 -> V_13 * 8 , & V_8 -> V_14 ) ;
if ( V_5 < 0 ) {
F_3 ( V_35 , V_34 ) ;
return 0 ;
}
V_6 = V_1 -> V_10 -> V_11 & V_12 ;
if ( ( V_6 == V_15 || V_6 == V_16 )
&& ! V_4 ) {
V_8 -> V_17 = ( V_18 ) V_36 ;
V_8 -> V_20 . V_21 = V_6 == V_16 ?
( V_22 ) V_37 : NULL ;
} else {
V_8 -> V_17 = ( V_18 ) V_38 ;
V_8 -> V_20 . V_21 = V_6 == V_16 ?
( V_22 ) V_37 : NULL ;
}
return 1 ;
}
static int F_6 ( T_1 * V_1 , unsigned char * V_39 ,
const unsigned char * V_40 , T_3 V_41 )
{
T_2 * V_8 = ( T_2 * ) V_1 -> V_9 ;
if ( V_8 -> V_20 . V_21 )
(* V_8 -> V_20 . V_21 ) ( V_40 , V_39 , V_41 , & V_8 -> V_14 , V_1 -> V_3 , V_1 -> V_42 ) ;
else if ( V_1 -> V_42 )
F_7 ( V_40 , V_39 , V_41 , & V_8 -> V_14 , V_1 -> V_3 , V_8 -> V_17 ) ;
else
F_8 ( V_40 , V_39 , V_41 , & V_8 -> V_14 , V_1 -> V_3 , V_8 -> V_17 ) ;
return 1 ;
}
static int F_9 ( T_1 * V_1 , unsigned char * V_39 ,
const unsigned char * V_40 , T_3 V_41 )
{
T_3 V_43 = V_1 -> V_10 -> V_44 ;
T_3 V_45 ;
T_2 * V_8 = ( T_2 * ) V_1 -> V_9 ;
if ( V_41 < V_43 )
return 1 ;
for ( V_45 = 0 , V_41 -= V_43 ; V_45 <= V_41 ; V_45 += V_43 )
(* V_8 -> V_17 ) ( V_40 + V_45 , V_39 + V_45 , & V_8 -> V_14 ) ;
return 1 ;
}
static int F_10 ( T_1 * V_1 , unsigned char * V_39 ,
const unsigned char * V_40 , T_3 V_41 )
{
T_2 * V_8 = ( T_2 * ) V_1 -> V_9 ;
F_11 ( V_40 , V_39 , V_41 , & V_8 -> V_14 ,
V_1 -> V_3 , & V_1 -> V_46 , V_8 -> V_17 ) ;
return 1 ;
}
static int F_12 ( T_1 * V_1 , unsigned char * V_39 ,
const unsigned char * V_40 , T_3 V_41 )
{
T_2 * V_8 = ( T_2 * ) V_1 -> V_9 ;
F_13 ( V_40 , V_39 , V_41 , & V_8 -> V_14 ,
V_1 -> V_3 , & V_1 -> V_46 , V_1 -> V_42 , V_8 -> V_17 ) ;
return 1 ;
}
static int F_14 ( T_1 * V_1 , unsigned char * V_39 ,
const unsigned char * V_40 , T_3 V_41 )
{
T_2 * V_8 = ( T_2 * ) V_1 -> V_9 ;
F_15 ( V_40 , V_39 , V_41 , & V_8 -> V_14 ,
V_1 -> V_3 , & V_1 -> V_46 , V_1 -> V_42 , V_8 -> V_17 ) ;
return 1 ;
}
static int F_16 ( T_1 * V_1 , unsigned char * V_39 ,
const unsigned char * V_40 , T_3 V_41 )
{
T_2 * V_8 = ( T_2 * ) V_1 -> V_9 ;
if ( V_1 -> V_11 & V_47 ) {
F_17 ( V_40 , V_39 , V_41 , & V_8 -> V_14 ,
V_1 -> V_3 , & V_1 -> V_46 , V_1 -> V_42 , V_8 -> V_17 ) ;
return 1 ;
}
while ( V_41 >= V_48 ) {
F_17 ( V_40 , V_39 , V_48 * 8 , & V_8 -> V_14 ,
V_1 -> V_3 , & V_1 -> V_46 , V_1 -> V_42 , V_8 -> V_17 ) ;
V_41 -= V_48 ;
}
if ( V_41 )
F_17 ( V_40 , V_39 , V_41 * 8 , & V_8 -> V_14 ,
V_1 -> V_3 , & V_1 -> V_46 , V_1 -> V_42 , V_8 -> V_17 ) ;
return 1 ;
}
