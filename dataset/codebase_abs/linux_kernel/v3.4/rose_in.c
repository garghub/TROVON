static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
switch ( V_5 ) {
case V_8 :
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
V_7 -> V_9 = 0x00 ;
V_7 -> V_10 = 0 ;
V_7 -> V_11 = 0 ;
V_7 -> V_12 = 0 ;
V_7 -> V_13 = 0 ;
V_7 -> V_14 = V_15 ;
V_2 -> V_16 = V_17 ;
if ( ! F_5 ( V_2 , V_18 ) )
V_2 -> V_19 ( V_2 ) ;
break;
case V_20 :
F_6 ( V_2 , V_21 ) ;
F_7 ( V_2 , V_22 , V_4 -> V_23 [ 3 ] , V_4 -> V_23 [ 4 ] ) ;
V_7 -> V_24 -> V_25 -- ;
break;
default:
break;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
switch ( V_5 ) {
case V_20 :
F_6 ( V_2 , V_21 ) ;
F_7 ( V_2 , 0 , V_4 -> V_23 [ 3 ] , V_4 -> V_23 [ 4 ] ) ;
V_7 -> V_24 -> V_25 -- ;
break;
case V_21 :
F_7 ( V_2 , 0 , - 1 , - 1 ) ;
V_7 -> V_24 -> V_25 -- ;
break;
default:
break;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 , int V_26 , int V_27 , int V_28 , int V_29 , int V_30 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_31 = 0 ;
switch ( V_5 ) {
case V_32 :
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
F_6 ( V_2 , V_33 ) ;
V_7 -> V_9 = 0x00 ;
V_7 -> V_10 = 0 ;
V_7 -> V_12 = 0 ;
V_7 -> V_11 = 0 ;
V_7 -> V_13 = 0 ;
F_10 ( V_2 ) ;
break;
case V_20 :
F_6 ( V_2 , V_21 ) ;
F_7 ( V_2 , 0 , V_4 -> V_23 [ 3 ] , V_4 -> V_23 [ 4 ] ) ;
V_7 -> V_24 -> V_25 -- ;
break;
case V_34 :
case V_35 :
if ( ! F_11 ( V_2 , V_27 ) ) {
F_6 ( V_2 , V_32 ) ;
V_7 -> V_9 = 0x00 ;
V_7 -> V_10 = 0 ;
V_7 -> V_12 = 0 ;
V_7 -> V_11 = 0 ;
V_7 -> V_13 = 0 ;
V_7 -> V_14 = V_36 ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
} else {
F_14 ( V_2 , V_27 ) ;
if ( V_5 == V_35 ) {
V_7 -> V_9 |= V_37 ;
} else {
V_7 -> V_9 &= ~ V_37 ;
}
}
break;
case V_38 :
V_7 -> V_9 &= ~ V_37 ;
if ( ! F_11 ( V_2 , V_27 ) ) {
F_6 ( V_2 , V_32 ) ;
V_7 -> V_9 = 0x00 ;
V_7 -> V_10 = 0 ;
V_7 -> V_12 = 0 ;
V_7 -> V_11 = 0 ;
V_7 -> V_13 = 0 ;
V_7 -> V_14 = V_36 ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
break;
}
F_14 ( V_2 , V_27 ) ;
if ( V_26 == V_7 -> V_12 ) {
F_4 ( V_2 ) ;
if ( F_15 ( V_2 , V_4 ) == 0 ) {
V_7 -> V_12 = ( V_7 -> V_12 + 1 ) % V_39 ;
V_31 = 1 ;
} else {
F_6 ( V_2 , V_32 ) ;
V_7 -> V_9 = 0x00 ;
V_7 -> V_10 = 0 ;
V_7 -> V_12 = 0 ;
V_7 -> V_11 = 0 ;
V_7 -> V_13 = 0 ;
V_7 -> V_14 = V_36 ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
break;
}
if ( F_16 ( & V_2 -> V_40 ) >
( V_2 -> V_41 >> 1 ) )
V_7 -> V_9 |= V_42 ;
}
if ( ( ( V_7 -> V_13 + V_43 ) % V_39 ) == V_7 -> V_12 ) {
V_7 -> V_9 &= ~ V_44 ;
F_3 ( V_2 ) ;
F_17 ( V_2 ) ;
} else {
V_7 -> V_9 |= V_44 ;
F_18 ( V_2 ) ;
}
break;
default:
F_19 ( V_45 L_1 , V_5 ) ;
break;
}
return V_31 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
switch ( V_5 ) {
case V_32 :
F_6 ( V_2 , V_33 ) ;
case V_33 :
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
V_7 -> V_9 = 0x00 ;
V_7 -> V_11 = 0 ;
V_7 -> V_12 = 0 ;
V_7 -> V_10 = 0 ;
V_7 -> V_13 = 0 ;
V_7 -> V_14 = V_15 ;
F_10 ( V_2 ) ;
break;
case V_20 :
F_6 ( V_2 , V_21 ) ;
F_7 ( V_2 , 0 , V_4 -> V_23 [ 3 ] , V_4 -> V_23 [ 4 ] ) ;
V_7 -> V_24 -> V_25 -- ;
break;
default:
break;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
if ( V_5 == V_20 ) {
F_6 ( V_2 , V_21 ) ;
F_7 ( V_2 , 0 , V_4 -> V_23 [ 3 ] , V_4 -> V_23 [ 4 ] ) ;
F_2 ( V_2 ) -> V_24 -> V_25 -- ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_31 = 0 , V_5 , V_26 , V_27 , V_28 , V_29 , V_30 ;
if ( V_7 -> V_14 == V_46 )
return 0 ;
V_5 = F_23 ( V_4 , & V_26 , & V_27 , & V_28 , & V_29 , & V_30 ) ;
switch ( V_7 -> V_14 ) {
case V_47 :
V_31 = F_1 ( V_2 , V_4 , V_5 ) ;
break;
case V_48 :
V_31 = F_8 ( V_2 , V_4 , V_5 ) ;
break;
case V_15 :
V_31 = F_9 ( V_2 , V_4 , V_5 , V_26 , V_27 , V_28 , V_29 , V_30 ) ;
break;
case V_36 :
V_31 = F_20 ( V_2 , V_4 , V_5 ) ;
break;
case V_49 :
V_31 = F_21 ( V_2 , V_4 , V_5 ) ;
break;
}
F_24 ( V_2 ) ;
return V_31 ;
}
