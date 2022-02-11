int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 ;
T_2 V_6 [] = { ( V_3 >> 8 ) | 0x80 , V_3 & 0xff , V_4 } ;
struct V_7 V_8 = { . V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = 0 , . V_6 = V_6 , . V_13 = 3 } ;
V_5 = F_2 ( V_2 -> V_14 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_3 ( L_1
L_2 , V_15 , V_3 , V_4 , V_5 ) ;
return ( V_5 != 1 ) ? - 1 : 0 ;
}
T_2 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 ;
T_2 V_16 [] = { ( V_3 >> 8 ) | 0x40 , V_3 & 0xff } ;
T_2 V_17 [] = { 0 } ;
struct V_7 V_8 [] = {
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 ,
. V_6 = V_16 , . V_13 = 2 } ,
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = V_18 ,
. V_6 = V_17 , . V_13 = 1 } } ;
V_5 = F_2 ( V_2 -> V_14 , V_8 , 2 ) ;
if ( V_5 != 2 )
F_3 ( V_19 L_3 ,
V_15 , V_5 ) ;
return V_17 [ 0 ] ;
}
int F_5 ( struct V_20 * V_21 , int V_22 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
F_6 ( L_4 , V_15 , V_22 ) ;
if ( V_2 -> V_24 == V_25 ) {
return 0 ;
}
if ( V_22 )
return F_1 ( V_2 , 0x106 , 1 ) ;
else
return F_1 ( V_2 , 0x106 , 0 ) ;
}
int F_7 ( struct V_1 * * V_2 , struct V_26 * V_14 ,
T_2 V_27 )
{
int V_5 ;
F_8 ( & V_28 ) ;
V_5 = F_9 ( struct V_1 , ( * V_2 ) ,
V_29 ,
V_14 , V_27 , L_5 ) ;
F_10 ( & V_28 ) ;
return V_5 ;
}
void F_11 ( struct V_1 * V_2 )
{
F_8 ( & V_28 ) ;
if ( V_2 != NULL )
F_12 ( V_2 ) ;
F_10 ( & V_28 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_30 )
{
struct V_31 * V_32 = V_2 -> V_10 -> V_33 ;
T_2 V_34 ;
if ( ! V_32 || ! V_32 -> V_35 ||
! V_32 -> V_36 || ! V_32 -> V_37 )
return 0 ;
V_34 = F_4 ( V_2 , 0x4000 |
( V_32 -> V_35 & ~ 0xc000 ) ) ;
if ( V_30 ) {
V_34 &= ~ ( ( V_32 -> V_36 >> 8 ) & 0xff ) ;
V_34 |= ( V_32 -> V_36 & 0xff ) ;
} else {
V_34 &= ~ ( ( V_32 -> V_37 >> 8 ) & 0xff ) ;
V_34 |= ( V_32 -> V_37 & 0xff ) ;
}
return F_1 ( V_2 , 0x8000 |
( V_32 -> V_35 & ~ 0xc000 ) , V_34 ) ;
}
int F_14 ( struct V_1 * V_2 , int V_38 )
{
struct V_31 * V_32 = V_2 -> V_10 -> V_33 ;
int V_39 , V_5 = 0 ;
if ( ! V_32 || ! V_32 -> V_40 ||
! V_32 -> V_41 || ! V_32 -> V_42 )
return 0 ;
if ( V_38 < 0 ) {
if ( V_2 -> V_43 )
return 0 ;
else
V_38 *= - 1 ;
}
if ( V_2 -> V_43 != V_38 ) {
T_2 V_34 ;
F_6 ( L_6 , V_15 , V_38 ) ;
F_13 ( V_2 , 1 ) ;
V_34 = F_4 ( V_2 , 0x4000 |
( V_32 -> V_40 & ~ 0xc000 ) ) ;
for ( V_39 = 0 ; V_39 < V_32 -> V_41 ; V_39 ++ )
V_34 &= ~ V_32 -> V_42 [ V_39 ] ;
if ( V_38 < V_32 -> V_41 )
V_34 |= V_32 -> V_42 [ V_38 ] ;
else if ( V_32 -> V_41 )
V_34 |=
V_32 -> V_42 [ V_32 -> V_41 - 1 ] ;
V_5 = F_1 ( V_2 , 0x8000 |
( V_32 -> V_40 & ~ 0xc000 ) , V_34 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_43 = V_38 ;
if ( V_38 == 0 )
F_13 ( V_2 , 0 ) ;
}
return 0 ;
}
int F_15 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
F_6 ( L_7 , V_15 ) ;
V_2 -> V_24 = V_44 ;
V_2 -> V_45 = 0 ;
F_1 ( V_2 , 0xa4 , 1 << 5 ) ;
F_5 ( V_21 , 1 ) ;
return 0 ;
}
int F_16 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
F_6 ( L_7 , V_15 ) ;
if ( V_2 -> V_24 == V_25 ) {
return 0 ;
}
F_14 ( V_2 , 0 ) ;
F_1 ( V_2 , 0xa4 , 1 << 5 ) ;
V_2 -> V_45 = 0 ;
return 0 ;
}
