int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 V_6 = { 0 } ;
int V_7 , V_8 = 0 ;
F_2 ( ! V_2 ) ;
V_6 . V_9 = V_10 ;
V_6 . V_11 = V_3 ;
V_6 . V_12 = V_13 | V_14 | V_15 ;
for ( V_7 = 100 ; V_7 ; V_7 -- ) {
V_8 = F_3 ( V_2 , & V_6 , V_16 ) ;
if ( V_8 )
break;
if ( V_3 == 0 )
break;
if ( F_4 ( V_2 ) ) {
if ( V_6 . V_17 [ 1 ] & V_18 )
break;
} else {
if ( V_6 . V_17 [ 0 ] & V_18 )
break;
}
V_8 = - V_19 ;
F_5 ( 10 ) ;
}
if ( V_4 )
* V_4 = V_6 . V_17 [ F_4 ( V_2 ) ? 1 : 0 ] ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 , int V_20 , unsigned V_21 ,
unsigned V_22 , T_2 V_23 , T_2 * V_24 )
{
struct V_5 V_6 = { 0 } ;
int V_8 ;
F_2 ( ! V_2 ) ;
F_2 ( V_21 > 7 ) ;
if ( V_22 & ~ 0x1FFFF )
return - V_25 ;
V_6 . V_9 = V_26 ;
V_6 . V_11 = V_20 ? 0x80000000 : 0x00000000 ;
V_6 . V_11 |= V_21 << 28 ;
V_6 . V_11 |= ( V_20 && V_24 ) ? 0x08000000 : 0x00000000 ;
V_6 . V_11 |= V_22 << 9 ;
V_6 . V_11 |= V_23 ;
V_6 . V_12 = V_27 | V_28 | V_29 ;
V_8 = F_3 ( V_2 , & V_6 , 0 ) ;
if ( V_8 )
return V_8 ;
if ( F_4 ( V_2 ) ) {
} else {
if ( V_6 . V_17 [ 0 ] & V_30 )
return - V_31 ;
if ( V_6 . V_17 [ 0 ] & V_32 )
return - V_25 ;
if ( V_6 . V_17 [ 0 ] & V_33 )
return - V_34 ;
}
if ( V_24 ) {
if ( F_4 ( V_2 ) )
* V_24 = ( V_6 . V_17 [ 0 ] >> 8 ) & 0xFF ;
else
* V_24 = V_6 . V_17 [ 0 ] & 0xFF ;
}
return 0 ;
}
int F_7 ( struct V_35 * V_36 , int V_20 , unsigned V_21 ,
unsigned V_22 , T_2 V_23 , T_2 * V_24 )
{
F_2 ( ! V_36 ) ;
return F_6 ( V_36 -> V_2 , V_20 , V_21 , V_22 , V_23 , V_24 ) ;
}
int F_8 ( struct V_35 * V_36 , int V_20 , unsigned V_21 ,
unsigned V_22 , int V_37 , T_2 * V_38 , unsigned V_39 , unsigned V_40 )
{
struct V_41 V_42 = { 0 } ;
struct V_5 V_6 = { 0 } ;
struct V_43 V_44 = { 0 } ;
struct V_45 V_46 ;
F_2 ( ! V_36 ) ;
F_2 ( V_21 > 7 ) ;
F_2 ( V_39 == 1 && V_40 > 512 ) ;
F_9 ( V_39 == 0 ) ;
F_9 ( V_40 == 0 ) ;
if ( V_22 & ~ 0x1FFFF )
return - V_25 ;
V_42 . V_6 = & V_6 ;
V_42 . V_44 = & V_44 ;
V_6 . V_9 = V_47 ;
V_6 . V_11 = V_20 ? 0x80000000 : 0x00000000 ;
V_6 . V_11 |= V_21 << 28 ;
V_6 . V_11 |= V_37 ? 0x04000000 : 0x00000000 ;
V_6 . V_11 |= V_22 << 9 ;
if ( V_39 == 1 && V_40 <= 512 )
V_6 . V_11 |= ( V_40 == 512 ) ? 0 : V_40 ;
else
V_6 . V_11 |= 0x08000000 | V_39 ;
V_6 . V_12 = V_27 | V_28 | V_48 ;
V_44 . V_40 = V_40 ;
V_44 . V_39 = V_39 ;
V_44 . V_12 = V_20 ? V_49 : V_50 ;
V_44 . V_46 = & V_46 ;
V_44 . V_51 = 1 ;
F_10 ( & V_46 , V_38 , V_40 * V_39 ) ;
F_11 ( & V_44 , V_36 ) ;
F_12 ( V_36 -> V_2 , & V_42 ) ;
if ( V_6 . error )
return V_6 . error ;
if ( V_44 . error )
return V_44 . error ;
if ( F_4 ( V_36 -> V_2 ) ) {
} else {
if ( V_6 . V_17 [ 0 ] & V_30 )
return - V_31 ;
if ( V_6 . V_17 [ 0 ] & V_32 )
return - V_25 ;
if ( V_6 . V_17 [ 0 ] & V_33 )
return - V_34 ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_52 ;
T_2 abort ;
V_52 = F_6 ( V_2 , 0 , 0 , V_53 , 0 , & abort ) ;
if ( V_52 )
abort = 0x08 ;
else
abort |= 0x08 ;
V_52 = F_6 ( V_2 , 1 , 0 , V_53 , abort , NULL ) ;
return V_52 ;
}
