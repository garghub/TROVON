static bool F_1 ( struct V_1 * V_2 , const T_1 V_3 )
{
struct V_4 * V_5 = & F_2 ( V_2 ) -> V_6 ;
T_1 V_7 = V_5 -> V_8 ;
T_1 V_9 = V_5 -> V_10 ;
T_1 V_11 = V_5 -> V_12 ;
T_1 V_13 = V_3 ;
if ( V_3 == 0xCDCDCDCD )
return true ;
V_13 = V_3 & 0x000000FF ;
if ( ( V_7 == V_13 ) && V_13 != 0x00 )
return false ;
V_13 = V_3 & 0x0000FF00 ;
V_13 >>= 8 ;
if ( ( V_11 & V_13 ) == 0 && V_13 != 0x07 )
return false ;
V_13 = V_3 & 0x00FF0000 ;
V_13 >>= 16 ;
if ( ( V_9 & V_13 ) == 0 && V_13 != 0x0F )
return false ;
return true ;
}
static void F_3 ( struct V_1 * V_2 , enum V_14 V_15 , T_1 V_16 , T_1 V_17 , T_1 V_18 )
{
if ( V_16 == 0xfe ) {
F_4 ( 50 ) ;
} else if ( V_16 == 0xfd ) {
F_4 ( 5 ) ;
} else if ( V_16 == 0xfc ) {
F_4 ( 1 ) ;
} else if ( V_16 == 0xfb ) {
F_5 ( 50 ) ;
} else if ( V_16 == 0xfa ) {
F_5 ( 5 ) ;
} else if ( V_16 == 0xf9 ) {
F_5 ( 1 ) ;
} else {
F_6 ( V_2 , V_15 , V_16 , V_17 , V_18 ) ;
F_5 ( 1 ) ;
}
}
static void F_7 ( struct V_1 * V_2 ,
T_1 V_16 , T_1 V_18 )
{
T_1 V_19 = 0x1000 ;
T_1 V_20 = ( T_1 ) ( V_19 & 0xE000 ) ;
F_3 ( V_2 , V_21 , V_16 | V_20 ,
V_22 ,
V_18 ) ;
}
static bool F_8 ( struct V_1 * V_2 )
{
T_1 V_23 ;
T_1 V_24 = sizeof( V_25 ) / sizeof( T_1 ) ;
T_1 * V_26 = V_25 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 += 2 ) {
T_1 V_27 = V_26 [ V_23 ] ;
T_1 V_28 = V_26 [ V_23 + 1 ] ;
if ( V_27 < 0xCDCDCDCD ) {
F_7 ( V_2 , V_27 , V_28 ) ;
continue;
} else {
if ( ! F_1 ( V_2 , V_26 [ V_23 ] ) ) {
F_9 ( V_27 , V_28 , V_23 ) ;
while ( V_28 != 0xDEAD && V_28 != 0xCDEF &&
V_28 != 0xCDCD && V_23 < V_24 - 2 )
F_9 ( V_27 , V_28 , V_23 ) ;
V_23 -= 2 ;
} else {
F_9 ( V_27 , V_28 , V_23 ) ;
while ( V_28 != 0xDEAD && V_28 != 0xCDEF &&
V_28 != 0xCDCD && V_23 < V_24 - 2 ) {
F_7 ( V_2 , V_27 , V_28 ) ;
F_9 ( V_27 , V_28 , V_23 ) ;
}
while ( V_28 != 0xDEAD && V_23 < V_24 - 2 )
F_9 ( V_27 , V_28 , V_23 ) ;
}
}
}
return true ;
}
static bool F_10 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_2 ( V_2 ) ;
T_1 V_31 = 0 ;
T_2 V_15 ;
bool V_32 = true ;
struct V_33 * V_34 ;
for ( V_15 = 0 ; V_15 < V_30 -> V_35 ; V_15 ++ ) {
V_34 = & V_30 -> V_36 [ V_15 ] ;
switch ( V_15 ) {
case V_21 :
case V_37 :
V_31 = F_11 ( V_2 , V_34 -> V_38 ,
V_39 ) ;
break;
case V_40 :
case V_41 :
V_31 = F_11 ( V_2 , V_34 -> V_38 ,
V_39 << 16 ) ;
break;
}
F_12 ( V_2 , V_34 -> V_42 , V_39 << 16 , 0x1 ) ;
F_5 ( 1 ) ;
F_12 ( V_2 , V_34 -> V_43 , V_39 , 0x1 ) ;
F_5 ( 1 ) ;
F_12 ( V_2 , V_34 -> V_44 ,
V_45 , 0x0 ) ;
F_5 ( 1 ) ;
F_12 ( V_2 , V_34 -> V_44 ,
V_46 , 0x0 ) ;
F_5 ( 1 ) ;
switch ( V_15 ) {
case V_21 :
V_32 = F_8 ( V_2 ) ;
break;
case V_40 :
V_32 = F_8 ( V_2 ) ;
break;
case V_37 :
break;
case V_41 :
break;
}
switch ( V_15 ) {
case V_21 :
case V_37 :
F_12 ( V_2 , V_34 -> V_38 ,
V_39 , V_31 ) ;
break;
case V_40 :
case V_41 :
F_12 ( V_2 , V_34 -> V_38 ,
V_39 << 16 , V_31 ) ;
break;
}
if ( ! V_32 )
return false ;
}
return V_32 ;
}
static bool F_13 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_2 ( V_2 ) ;
if ( V_30 -> V_47 == V_48 )
V_30 -> V_35 = 1 ;
else
V_30 -> V_35 = 2 ;
return F_10 ( V_2 ) ;
}
bool F_14 ( struct V_1 * V_2 )
{
return F_13 ( V_2 ) ;
}
