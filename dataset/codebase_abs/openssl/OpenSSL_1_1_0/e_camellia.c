static int F_1 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 , V_6 , V_7 ;
T_2 * V_8 =
( T_2 * ) F_2 ( V_1 ) ;
V_6 = F_3 ( V_1 ) ;
V_7 = F_4 ( V_1 ) * 8 ;
F_5 ( V_2 , V_7 , & V_8 -> V_9 ) ;
if ( ( V_6 == V_10 || V_6 == V_11 )
&& ! V_4 ) {
V_5 = 0 ;
V_8 -> V_12 = ( V_13 ) V_14 ;
switch ( V_7 ) {
case 128 :
V_8 -> V_15 . V_16 = V_6 == V_11 ?
( V_17 ) V_18 : NULL ;
break;
case 192 :
case 256 :
V_8 -> V_15 . V_16 = V_6 == V_11 ?
( V_17 ) V_19 : NULL ;
break;
default:
V_5 = - 1 ;
}
} else {
V_5 = 0 ;
V_8 -> V_12 = ( V_13 ) V_20 ;
switch ( V_7 ) {
case 128 :
if ( V_6 == V_11 )
V_8 -> V_15 . V_16 = ( V_17 ) V_21 ;
else if ( V_6 == V_22 )
V_8 -> V_15 . V_23 = ( V_24 ) V_25 ;
else
V_8 -> V_15 . V_16 = NULL ;
break;
case 192 :
case 256 :
if ( V_6 == V_11 )
V_8 -> V_15 . V_16 = ( V_17 ) V_26 ;
else if ( V_6 == V_22 )
V_8 -> V_15 . V_23 = ( V_24 ) V_27 ;
else
V_8 -> V_15 . V_16 = NULL ;
break;
default:
V_5 = - 1 ;
}
}
if ( V_5 < 0 ) {
F_6 ( V_28 , V_29 ) ;
return 0 ;
}
return 1 ;
}
static int F_7 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 )
{
int V_5 , V_6 ;
T_2 * V_8 = F_8 ( T_2 , V_1 ) ;
V_5 = F_9 ( V_2 , F_4 ( V_1 ) * 8 , & V_8 -> V_9 ) ;
if ( V_5 < 0 ) {
F_6 ( V_30 , V_29 ) ;
return 0 ;
}
V_6 = F_3 ( V_1 ) ;
if ( ( V_6 == V_10 || V_6 == V_11 )
&& ! V_4 ) {
V_8 -> V_12 = ( V_13 ) V_31 ;
V_8 -> V_15 . V_16 = V_6 == V_11 ?
( V_17 ) V_32 : NULL ;
} else {
V_8 -> V_12 = ( V_13 ) V_33 ;
V_8 -> V_15 . V_16 = V_6 == V_11 ?
( V_17 ) V_32 : NULL ;
}
return 1 ;
}
static int F_10 ( T_1 * V_1 , unsigned char * V_34 ,
const unsigned char * V_35 , T_3 V_36 )
{
T_2 * V_8 = F_8 ( T_2 , V_1 ) ;
if ( V_8 -> V_15 . V_16 )
(* V_8 -> V_15 . V_16 ) ( V_35 , V_34 , V_36 , & V_8 -> V_9 ,
F_11 ( V_1 ) ,
F_12 ( V_1 ) ) ;
else if ( F_12 ( V_1 ) )
F_13 ( V_35 , V_34 , V_36 , & V_8 -> V_9 ,
F_11 ( V_1 ) , V_8 -> V_12 ) ;
else
F_14 ( V_35 , V_34 , V_36 , & V_8 -> V_9 ,
F_11 ( V_1 ) , V_8 -> V_12 ) ;
return 1 ;
}
static int F_15 ( T_1 * V_1 , unsigned char * V_34 ,
const unsigned char * V_35 , T_3 V_36 )
{
T_3 V_37 = F_16 ( V_1 ) ;
T_3 V_38 ;
T_2 * V_8 = F_8 ( T_2 , V_1 ) ;
if ( V_36 < V_37 )
return 1 ;
for ( V_38 = 0 , V_36 -= V_37 ; V_38 <= V_36 ; V_38 += V_37 )
(* V_8 -> V_12 ) ( V_35 + V_38 , V_34 + V_38 , & V_8 -> V_9 ) ;
return 1 ;
}
static int F_17 ( T_1 * V_1 , unsigned char * V_34 ,
const unsigned char * V_35 , T_3 V_36 )
{
T_2 * V_8 = F_8 ( T_2 , V_1 ) ;
int V_39 = F_18 ( V_1 ) ;
F_19 ( V_35 , V_34 , V_36 , & V_8 -> V_9 ,
F_11 ( V_1 ) , & V_39 , V_8 -> V_12 ) ;
F_20 ( V_1 , V_39 ) ;
return 1 ;
}
static int F_21 ( T_1 * V_1 , unsigned char * V_34 ,
const unsigned char * V_35 , T_3 V_36 )
{
T_2 * V_8 = F_8 ( T_2 , V_1 ) ;
int V_39 = F_18 ( V_1 ) ;
F_22 ( V_35 , V_34 , V_36 , & V_8 -> V_9 ,
F_11 ( V_1 ) , & V_39 , F_12 ( V_1 ) , V_8 -> V_12 ) ;
F_20 ( V_1 , V_39 ) ;
return 1 ;
}
static int F_23 ( T_1 * V_1 , unsigned char * V_34 ,
const unsigned char * V_35 , T_3 V_36 )
{
T_2 * V_8 = F_8 ( T_2 , V_1 ) ;
int V_39 = F_18 ( V_1 ) ;
F_24 ( V_35 , V_34 , V_36 , & V_8 -> V_9 ,
F_11 ( V_1 ) , & V_39 , F_12 ( V_1 ) , V_8 -> V_12 ) ;
F_20 ( V_1 , V_39 ) ;
return 1 ;
}
static int F_25 ( T_1 * V_1 , unsigned char * V_34 ,
const unsigned char * V_35 , T_3 V_36 )
{
T_2 * V_8 = F_8 ( T_2 , V_1 ) ;
if ( F_26 ( V_1 , V_40 ) ) {
int V_39 = F_18 ( V_1 ) ;
F_27 ( V_35 , V_34 , V_36 , & V_8 -> V_9 ,
F_11 ( V_1 ) , & V_39 , F_12 ( V_1 ) , V_8 -> V_12 ) ;
F_20 ( V_1 , V_39 ) ;
return 1 ;
}
while ( V_36 >= V_41 ) {
int V_39 = F_18 ( V_1 ) ;
F_27 ( V_35 , V_34 , V_41 * 8 , & V_8 -> V_9 ,
F_11 ( V_1 ) , & V_39 , F_12 ( V_1 ) , V_8 -> V_12 ) ;
V_36 -= V_41 ;
F_20 ( V_1 , V_39 ) ;
}
if ( V_36 ) {
int V_39 = F_18 ( V_1 ) ;
F_27 ( V_35 , V_34 , V_36 * 8 , & V_8 -> V_9 ,
F_11 ( V_1 ) , & V_39 , F_12 ( V_1 ) , V_8 -> V_12 ) ;
F_20 ( V_1 , V_39 ) ;
}
return 1 ;
}
static int F_28 ( T_1 * V_1 , unsigned char * V_34 ,
const unsigned char * V_35 , T_3 V_36 )
{
unsigned int V_39 = F_18 ( V_1 ) ;
T_2 * V_8 = F_8 ( T_2 , V_1 ) ;
if ( V_8 -> V_15 . V_23 )
F_29 ( V_35 , V_34 , V_36 , & V_8 -> V_9 ,
F_11 ( V_1 ) ,
F_30 ( V_1 ) , & V_39 ,
V_8 -> V_15 . V_23 ) ;
else
F_31 ( V_35 , V_34 , V_36 , & V_8 -> V_9 ,
F_11 ( V_1 ) ,
F_30 ( V_1 ) , & V_39 ,
V_8 -> V_12 ) ;
F_20 ( V_1 , V_39 ) ;
return 1 ;
}
