int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
void * V_4 , unsigned int V_5 )
{
if ( F_2 ( V_5 > 4 ) )
return - V_6 ;
if ( F_2 ( V_3 + V_5 > V_7 ) )
return - V_6 ;
memcpy ( V_4 , F_3 ( V_2 ) + V_3 , V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , bool V_8 )
{
T_1 V_9 , V_10 ;
T_1 V_11 ;
int V_12 ;
if ( V_8 == V_2 -> V_13 . V_14 [ V_15 ] . V_16 )
return 0 ;
V_11 = F_3 ( V_2 ) [ V_17 ] ;
if ( V_11 & V_18 )
V_11 = * ( T_1 * ) ( F_3 ( V_2 ) + V_17 ) ;
else
V_11 = * ( V_19 * ) ( F_3 ( V_2 ) + V_17 ) ;
V_9 = ( V_11 + F_5 ( V_2 ) ) >> V_20 ;
V_10 = F_6 ( V_2 ) >> V_20 ;
V_12 = F_7 ( V_2 , V_9 ,
V_10 ,
F_8 ( V_2 ) >>
V_20 , V_8 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_13 . V_14 [ V_15 ] . V_16 = V_8 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , bool V_21 )
{
T_1 V_22 , V_23 ;
T_1 V_11 ;
int V_12 ;
if ( V_21 == V_2 -> V_13 . V_14 [ V_24 ] . V_16 )
return 0 ;
V_11 = F_3 ( V_2 ) [ V_25 ] ;
if ( V_11 & V_18 )
V_22 = * ( T_1 * ) ( F_3 ( V_2 ) + V_25 ) ;
else
V_22 = * ( V_19 * ) ( F_3 ( V_2 ) + V_25 ) ;
V_22 &= ~ F_10 ( 3 , 0 ) ;
V_23 = V_22 + V_2 -> V_13 . V_14 [ V_24 ] . V_26 - 1 ;
V_12 = F_11 ( V_2 , V_22 , V_23 , V_21 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_13 . V_14 [ V_24 ] . V_16 = V_21 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_3 , void * V_4 , unsigned int V_5 )
{
T_2 V_27 = F_3 ( V_2 ) [ V_3 ] ;
T_2 V_28 = * ( T_2 * ) V_4 ;
T_2 V_29 = V_27 ^ V_28 ;
int V_12 ;
memcpy ( F_3 ( V_2 ) + V_3 , V_4 , V_5 ) ;
if ( ! ( V_29 & V_30 ) )
return 0 ;
if ( V_27 & V_30 ) {
V_12 = F_9 ( V_2 , false ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_2 , false ) ;
if ( V_12 )
return V_12 ;
} else {
V_12 = F_9 ( V_2 , true ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_2 , true ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_3 ,
void * V_4 , unsigned int V_5 )
{
unsigned int V_31 =
( F_14 ( V_3 , 8 ) % V_25 ) / 8 ;
V_19 V_28 = * ( V_19 * ) ( V_4 ) ;
bool V_32 = F_15 ( V_3 , 8 ) ;
T_1 V_26 ;
int V_12 = 0 ;
bool V_33 =
F_3 ( V_2 ) [ V_34 ] & V_30 ;
if ( F_2 ( V_31 >= V_35 ) )
return - V_6 ;
if ( V_28 == 0xffffffff ) {
V_26 = V_2 -> V_13 . V_14 [ V_31 ] . V_26 ;
if ( V_32 ) {
V_28 = F_14 ( V_28 , V_26 ) ;
} else {
V_19 V_11 = F_3 ( V_2 ) [ F_14 ( V_3 , 8 ) ] ;
if ( V_11 & V_18 )
V_28 &= ( ~ ( V_26 - 1 ) ) >> 32 ;
else
V_28 = 0 ;
}
switch ( V_31 ) {
case V_24 :
V_12 = F_9 ( V_2 , false ) ;
break;
case V_15 :
V_12 = F_4 ( V_2 , false ) ;
break;
}
F_16 ( V_2 , V_3 , V_28 , V_32 ) ;
} else {
switch ( V_31 ) {
case V_24 :
V_12 = F_9 ( V_2 , false ) ;
break;
case V_15 :
V_12 = F_4 ( V_2 , false ) ;
break;
}
F_16 ( V_2 , V_3 , V_28 , V_32 ) ;
if ( V_33 ) {
switch ( V_31 ) {
case V_24 :
V_12 = F_9 ( V_2 , true ) ;
break;
case V_15 :
V_12 = F_4 ( V_2 , true ) ;
break;
}
}
}
return V_12 ;
}
int F_17 ( struct V_1 * V_2 , unsigned int V_3 ,
void * V_4 , unsigned int V_5 )
{
int V_12 ;
if ( F_2 ( V_5 > 4 ) )
return - V_6 ;
if ( F_2 ( V_3 + V_5 > V_7 ) )
return - V_6 ;
if ( F_15 ( V_3 , 2 ) && V_3 == V_34 ) {
if ( F_2 ( V_5 > 2 ) )
return - V_6 ;
return F_12 ( V_2 , V_3 , V_4 , V_5 ) ;
}
switch ( F_14 ( V_3 , 4 ) ) {
case V_25 :
case V_36 :
case V_17 :
case V_37 :
if ( F_2 ( ! F_15 ( V_3 , 4 ) ) )
return - V_6 ;
return F_13 ( V_2 , V_3 , V_4 , V_5 ) ;
case V_38 :
if ( F_2 ( ! F_15 ( V_3 , 4 ) ) )
return - V_6 ;
V_12 = F_18 ( V_2 , * ( V_19 * ) V_4 ) ;
if ( V_12 )
return V_12 ;
break;
case V_39 :
if ( F_2 ( ! F_15 ( V_3 , 4 ) ) )
return - V_6 ;
V_12 = F_19 ( V_2 , * ( V_19 * ) V_4 ) ;
if ( V_12 )
return V_12 ;
memcpy ( F_3 ( V_2 ) + V_3 , V_4 , V_5 ) ;
break;
default:
memcpy ( F_3 ( V_2 ) + V_3 , V_4 , V_5 ) ;
break;
}
return 0 ;
}
void F_20 ( struct V_1 * V_2 ,
bool V_40 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
const struct V_43 * V_44 = & V_42 -> V_45 ;
T_3 * V_46 ;
int V_47 ;
memcpy ( F_3 ( V_2 ) , V_42 -> V_48 . V_13 ,
V_44 -> V_49 ) ;
if ( ! V_40 ) {
F_3 ( V_2 ) [ V_50 ] =
V_51 ;
F_3 ( V_2 ) [ V_52 ] =
V_51 ;
}
V_46 = ( T_3 * ) ( F_3 ( V_2 ) + V_53 ) ;
* V_46 &= ~ ( V_54 << V_55 ) ;
F_16 ( V_2 , V_17 ,
F_21 ( V_42 ) , true ) ;
F_3 ( V_2 ) [ V_34 ] &= ~ ( V_56
| V_30
| V_57 ) ;
memset ( F_3 ( V_2 ) + V_36 , 0 , 4 ) ;
memset ( F_3 ( V_2 ) + V_37 , 0 , 4 ) ;
memset ( F_3 ( V_2 ) + V_39 , 0 , 4 ) ;
for ( V_47 = 0 ; V_47 < V_58 ; V_47 ++ ) {
V_2 -> V_13 . V_14 [ V_47 ] . V_26 = F_22 (
V_42 -> V_59 -> V_60 . V_61 , V_47 * 2 ) ;
V_2 -> V_13 . V_14 [ V_47 ] . V_16 = false ;
}
}
void F_23 ( struct V_1 * V_2 )
{
T_2 V_62 = F_3 ( V_2 ) [ V_34 ] ;
bool V_40 = F_3 ( V_2 ) [ V_50 ] !=
V_51 ;
if ( V_62 & V_30 ) {
F_9 ( V_2 , false ) ;
F_4 ( V_2 , false ) ;
}
F_20 ( V_2 , V_40 ) ;
}
