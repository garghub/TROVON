int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 V_6 = {} ;
int V_7 , V_8 = 0 ;
V_6 . V_9 = V_10 ;
V_6 . V_11 = V_3 ;
V_6 . V_12 = V_13 | V_14 | V_15 ;
for ( V_7 = 100 ; V_7 ; V_7 -- ) {
V_8 = F_2 ( V_2 , & V_6 , V_16 ) ;
if ( V_8 )
break;
if ( V_3 == 0 )
break;
if ( F_3 ( V_2 ) ) {
if ( V_6 . V_17 [ 1 ] & V_18 )
break;
} else {
if ( V_6 . V_17 [ 0 ] & V_18 )
break;
}
V_8 = - V_19 ;
F_4 ( 10 ) ;
}
if ( V_4 )
* V_4 = V_6 . V_17 [ F_3 ( V_2 ) ? 1 : 0 ] ;
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 , int V_20 , unsigned V_21 ,
unsigned V_22 , T_2 V_23 , T_2 * V_24 )
{
struct V_5 V_6 = {} ;
int V_8 ;
if ( V_21 > 7 )
return - V_25 ;
if ( V_22 & ~ 0x1FFFF )
return - V_25 ;
V_6 . V_9 = V_26 ;
V_6 . V_11 = V_20 ? 0x80000000 : 0x00000000 ;
V_6 . V_11 |= V_21 << 28 ;
V_6 . V_11 |= ( V_20 && V_24 ) ? 0x08000000 : 0x00000000 ;
V_6 . V_11 |= V_22 << 9 ;
V_6 . V_11 |= V_23 ;
V_6 . V_12 = V_27 | V_28 | V_29 ;
V_8 = F_2 ( V_2 , & V_6 , 0 ) ;
if ( V_8 )
return V_8 ;
if ( F_3 ( V_2 ) ) {
} else {
if ( V_6 . V_17 [ 0 ] & V_30 )
return - V_31 ;
if ( V_6 . V_17 [ 0 ] & V_32 )
return - V_25 ;
if ( V_6 . V_17 [ 0 ] & V_33 )
return - V_34 ;
}
if ( V_24 ) {
if ( F_3 ( V_2 ) )
* V_24 = ( V_6 . V_17 [ 0 ] >> 8 ) & 0xFF ;
else
* V_24 = V_6 . V_17 [ 0 ] & 0xFF ;
}
return 0 ;
}
int F_6 ( struct V_35 * V_36 , int V_20 , unsigned V_21 ,
unsigned V_22 , T_2 V_23 , T_2 * V_24 )
{
return F_5 ( V_36 -> V_2 , V_20 , V_21 , V_22 , V_23 , V_24 ) ;
}
int F_7 ( struct V_35 * V_36 , int V_20 , unsigned V_21 ,
unsigned V_22 , int V_37 , T_2 * V_38 , unsigned V_39 , unsigned V_40 )
{
struct V_41 V_42 = {} ;
struct V_5 V_6 = {} ;
struct V_43 V_44 = {} ;
struct V_45 V_46 , * V_47 ;
struct V_48 V_49 ;
unsigned int V_50 , V_51 , V_7 ;
unsigned int V_52 = V_36 -> V_2 -> V_53 ;
F_8 ( V_40 == 0 ) ;
if ( V_22 & ~ 0x1FFFF )
return - V_25 ;
V_42 . V_6 = & V_6 ;
V_42 . V_44 = & V_44 ;
V_6 . V_9 = V_54 ;
V_6 . V_11 = V_20 ? 0x80000000 : 0x00000000 ;
V_6 . V_11 |= V_21 << 28 ;
V_6 . V_11 |= V_37 ? 0x04000000 : 0x00000000 ;
V_6 . V_11 |= V_22 << 9 ;
if ( V_39 == 0 )
V_6 . V_11 |= ( V_40 == 512 ) ? 0 : V_40 ;
else
V_6 . V_11 |= 0x08000000 | V_39 ;
V_6 . V_12 = V_27 | V_28 | V_55 ;
V_44 . V_40 = V_40 ;
V_44 . V_39 = V_39 ? V_39 : 1 ;
V_44 . V_12 = V_20 ? V_56 : V_57 ;
V_51 = V_44 . V_40 * V_44 . V_39 ;
V_50 = ( V_51 - 1 ) / V_52 + 1 ;
if ( V_50 > 1 ) {
if ( F_9 ( & V_49 , V_50 , V_58 ) )
return - V_59 ;
V_44 . V_46 = V_49 . V_60 ;
V_44 . V_61 = V_50 ;
F_10 (data.sg, sg_ptr, data.sg_len, i) {
F_11 ( V_47 , F_12 ( V_38 + ( V_7 * V_52 ) ) ,
F_13 ( V_52 , V_51 ) ,
F_14 ( V_38 + ( V_7 * V_52 ) ) ) ;
V_51 = V_51 - V_52 ;
}
} else {
V_44 . V_46 = & V_46 ;
V_44 . V_61 = 1 ;
F_15 ( & V_46 , V_38 , V_51 ) ;
}
F_16 ( & V_44 , V_36 ) ;
F_17 ( V_36 -> V_2 , & V_42 ) ;
if ( V_50 > 1 )
F_18 ( & V_49 ) ;
if ( V_6 . error )
return V_6 . error ;
if ( V_44 . error )
return V_44 . error ;
if ( F_3 ( V_36 -> V_2 ) ) {
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
int F_19 ( struct V_1 * V_2 )
{
int V_62 ;
T_2 abort ;
V_62 = F_5 ( V_2 , 0 , 0 , V_63 , 0 , & abort ) ;
if ( V_62 )
abort = 0x08 ;
else
abort |= 0x08 ;
return F_5 ( V_2 , 1 , 0 , V_63 , abort , NULL ) ;
}
