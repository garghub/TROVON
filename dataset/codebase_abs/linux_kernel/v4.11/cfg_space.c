static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 * V_4 , unsigned int V_5 )
{
T_1 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 , V_8 , V_9 ;
int V_10 = 0 ;
for (; V_10 < V_5 && ( V_3 + V_10 < sizeof( V_11 ) ) ; V_10 ++ ) {
V_7 = V_11 [ V_3 + V_10 ] ;
V_9 = V_6 [ V_3 + V_10 ] ;
V_8 = V_4 [ V_10 ] & V_7 ;
if ( V_3 + V_10 == V_12 + 1 )
V_8 = ( ~ V_8 & V_9 ) & V_7 ;
V_6 [ V_3 + V_10 ] = ( V_9 & ~ V_7 ) | V_8 ;
}
if ( V_10 < V_5 )
memcpy ( V_6 + V_3 + V_10 , V_4 + V_10 , V_5 - V_10 ) ;
}
int F_3 ( struct V_1 * V_2 , unsigned int V_13 ,
void * V_14 , unsigned int V_5 )
{
if ( F_4 ( V_5 > 4 ) )
return - V_15 ;
if ( F_4 ( V_13 + V_5 > V_16 ) )
return - V_15 ;
memcpy ( V_14 , F_2 ( V_2 ) + V_13 , V_5 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , bool V_17 )
{
T_2 V_18 , V_19 ;
T_2 V_20 ;
int V_21 ;
if ( V_17 == V_2 -> V_22 . V_23 [ V_24 ] . V_25 )
return 0 ;
V_20 = F_2 ( V_2 ) [ V_26 ] ;
if ( V_20 & V_27 )
V_20 = * ( T_2 * ) ( F_2 ( V_2 ) + V_26 ) ;
else
V_20 = * ( V_28 * ) ( F_2 ( V_2 ) + V_26 ) ;
V_18 = ( V_20 + F_6 ( V_2 ) ) >> V_29 ;
V_19 = F_7 ( V_2 ) >> V_29 ;
V_21 = F_8 ( V_2 , V_18 ,
V_19 ,
F_9 ( V_2 ) >>
V_29 , V_17 ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_22 . V_23 [ V_24 ] . V_25 = V_17 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , bool V_30 )
{
T_2 V_31 , V_32 ;
T_2 V_20 ;
int V_21 ;
if ( V_30 == V_2 -> V_22 . V_23 [ V_33 ] . V_25 )
return 0 ;
V_20 = F_2 ( V_2 ) [ V_34 ] ;
if ( V_20 & V_27 )
V_31 = * ( T_2 * ) ( F_2 ( V_2 ) + V_34 ) ;
else
V_31 = * ( V_28 * ) ( F_2 ( V_2 ) + V_34 ) ;
V_31 &= ~ F_11 ( 3 , 0 ) ;
V_32 = V_31 + V_2 -> V_22 . V_23 [ V_33 ] . V_35 - 1 ;
V_21 = F_12 ( V_2 , V_31 , V_32 , V_30 ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_22 . V_23 [ V_33 ] . V_25 = V_30 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned int V_13 , void * V_14 , unsigned int V_5 )
{
T_1 V_9 = F_2 ( V_2 ) [ V_13 ] ;
T_1 V_8 = * ( T_1 * ) V_14 ;
T_1 V_36 = V_9 ^ V_8 ;
int V_21 ;
F_1 ( V_2 , V_13 , V_14 , V_5 ) ;
if ( ! ( V_36 & V_37 ) )
return 0 ;
if ( V_9 & V_37 ) {
V_21 = F_10 ( V_2 , false ) ;
if ( V_21 )
return V_21 ;
V_21 = F_5 ( V_2 , false ) ;
if ( V_21 )
return V_21 ;
} else {
V_21 = F_10 ( V_2 , true ) ;
if ( V_21 )
return V_21 ;
V_21 = F_5 ( V_2 , true ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_13 ,
void * V_14 , unsigned int V_5 )
{
unsigned int V_38 =
( F_15 ( V_13 , 8 ) % V_34 ) / 8 ;
V_28 V_8 = * ( V_28 * ) ( V_14 ) ;
bool V_39 = F_16 ( V_13 , 8 ) ;
T_2 V_35 ;
int V_21 = 0 ;
bool V_40 =
F_2 ( V_2 ) [ V_41 ] & V_37 ;
if ( F_4 ( V_38 >= V_42 ) )
return - V_15 ;
if ( V_8 == 0xffffffff ) {
V_35 = V_2 -> V_22 . V_23 [ V_38 ] . V_35 ;
if ( V_39 ) {
V_8 = F_15 ( V_8 , V_35 ) ;
} else {
V_28 V_20 = F_2 ( V_2 ) [ F_15 ( V_13 , 8 ) ] ;
if ( V_20 & V_27 )
V_8 &= ( ~ ( V_35 - 1 ) ) >> 32 ;
else
V_8 = 0 ;
}
switch ( V_38 ) {
case V_33 :
V_21 = F_10 ( V_2 , false ) ;
break;
case V_24 :
V_21 = F_5 ( V_2 , false ) ;
break;
}
F_17 ( V_2 , V_13 , V_8 , V_39 ) ;
} else {
switch ( V_38 ) {
case V_33 :
V_21 = F_10 ( V_2 , false ) ;
break;
case V_24 :
V_21 = F_5 ( V_2 , false ) ;
break;
}
F_17 ( V_2 , V_13 , V_8 , V_39 ) ;
if ( V_40 ) {
switch ( V_38 ) {
case V_33 :
V_21 = F_10 ( V_2 , true ) ;
break;
case V_24 :
V_21 = F_5 ( V_2 , true ) ;
break;
}
}
}
return V_21 ;
}
int F_18 ( struct V_1 * V_2 , unsigned int V_13 ,
void * V_14 , unsigned int V_5 )
{
int V_21 ;
if ( F_4 ( V_5 > 4 ) )
return - V_15 ;
if ( F_4 ( V_13 + V_5 > V_16 ) )
return - V_15 ;
if ( F_16 ( V_13 , 2 ) && V_13 == V_41 ) {
if ( F_4 ( V_5 > 2 ) )
return - V_15 ;
return F_13 ( V_2 , V_13 , V_14 , V_5 ) ;
}
switch ( F_15 ( V_13 , 4 ) ) {
case V_34 :
case V_43 :
case V_26 :
case V_44 :
if ( F_4 ( ! F_16 ( V_13 , 4 ) ) )
return - V_15 ;
return F_14 ( V_2 , V_13 , V_14 , V_5 ) ;
case V_45 :
if ( F_4 ( ! F_16 ( V_13 , 4 ) ) )
return - V_15 ;
V_21 = F_19 ( V_2 , * ( V_28 * ) V_14 ) ;
if ( V_21 )
return V_21 ;
break;
case V_46 :
if ( F_4 ( ! F_16 ( V_13 , 4 ) ) )
return - V_15 ;
V_21 = F_20 ( V_2 , * ( V_28 * ) V_14 ) ;
if ( V_21 )
return V_21 ;
F_1 ( V_2 , V_13 , V_14 , V_5 ) ;
break;
default:
F_1 ( V_2 , V_13 , V_14 , V_5 ) ;
break;
}
return 0 ;
}
void F_21 ( struct V_1 * V_2 ,
bool V_47 )
{
struct V_48 * V_49 = V_2 -> V_49 ;
const struct V_50 * V_51 = & V_49 -> V_52 ;
T_3 * V_53 ;
int V_10 ;
memcpy ( F_2 ( V_2 ) , V_49 -> V_54 . V_22 ,
V_51 -> V_55 ) ;
if ( ! V_47 ) {
F_2 ( V_2 ) [ V_56 ] =
V_57 ;
F_2 ( V_2 ) [ V_58 ] =
V_57 ;
}
V_53 = ( T_3 * ) ( F_2 ( V_2 ) + V_59 ) ;
* V_53 &= ~ ( V_60 << V_61 ) ;
F_17 ( V_2 , V_26 ,
F_22 ( V_49 ) , true ) ;
F_2 ( V_2 ) [ V_41 ] &= ~ ( V_62
| V_37
| V_63 ) ;
memset ( F_2 ( V_2 ) + V_43 , 0 , 4 ) ;
memset ( F_2 ( V_2 ) + V_44 , 0 , 4 ) ;
memset ( F_2 ( V_2 ) + V_46 , 0 , 4 ) ;
for ( V_10 = 0 ; V_10 < V_64 ; V_10 ++ ) {
V_2 -> V_22 . V_23 [ V_10 ] . V_35 = F_23 (
V_49 -> V_65 -> V_66 . V_67 , V_10 * 2 ) ;
V_2 -> V_22 . V_23 [ V_10 ] . V_25 = false ;
}
}
void F_24 ( struct V_1 * V_2 )
{
T_1 V_68 = F_2 ( V_2 ) [ V_41 ] ;
bool V_47 = F_2 ( V_2 ) [ V_56 ] !=
V_57 ;
if ( V_68 & V_37 ) {
F_10 ( V_2 , false ) ;
F_5 ( V_2 , false ) ;
}
F_21 ( V_2 , V_47 ) ;
}
