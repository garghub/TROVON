static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_4 , V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ( V_6 & 0xFF ) != 0x81 )
return - V_8 ;
V_2 -> V_9 [ V_10 ] = V_11 |
V_12 | V_13 ;
V_2 -> V_14 = V_15 ;
for ( V_5 = 0 ; V_5 < V_16 ; V_5 ++ ) {
V_6 = F_3 ( V_4 , V_17 [ V_5 ] ,
V_2 -> V_9 [ V_5 ] ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int * V_18 )
{
T_2 V_19 ;
int V_5 ;
V_19 = V_2 -> V_9 [ V_10 ] ;
V_19 &= V_20 ;
V_19 >>= V_21 ;
for ( V_5 = 0 ; V_5 < F_5 ( V_22 ) ; V_5 ++ ) {
if ( V_19 == V_22 [ V_5 ] ) {
* V_18 = V_23 [ V_5 ] ;
return V_24 ;
}
}
return - V_25 ;
}
static int F_6 ( struct V_1 * V_2 , int V_26 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_19 ;
int V_6 , V_5 , V_27 ;
V_27 = F_5 ( V_23 ) ;
for ( V_5 = 0 ; V_5 < V_27 ; V_5 ++ )
if ( V_26 <= V_23 [ V_5 ] )
break;
if ( V_5 >= V_27 )
V_5 = V_27 - 1 ;
V_19 = V_22 [ V_5 ] ;
V_19 <<= V_21 ;
F_7 ( & V_2 -> V_28 ) ;
V_2 -> V_9 [ V_10 ] &=
~ V_20 ;
V_2 -> V_9 [ V_10 ] |=
V_19 ;
V_6 = F_3 ( V_4 , V_10 ,
V_2 -> V_9 [ V_10 ] ) ;
F_8 ( & V_2 -> V_28 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_6 ;
int V_19 ;
unsigned long V_29 ;
V_6 = F_4 ( V_2 , & V_19 ) ;
if ( V_6 < 0 )
return - V_25 ;
V_29 = V_30 ;
V_29 *= V_31 ;
V_29 /= V_19 ;
V_6 = F_2 ( V_4 , V_32 ) ;
if ( V_6 < 0 )
return V_6 ;
V_29 *= V_6 ;
V_29 *= V_2 -> V_14 ;
V_29 /= V_33 ;
V_29 /= V_34 ;
if ( V_29 > 0xFFFF )
V_29 = 0xFFFF ;
return V_29 ;
}
static int F_10 ( struct V_35 * V_36 ,
struct V_37 const * V_38 ,
int * V_26 , int * V_18 , long V_39 )
{
struct V_1 * V_2 = F_11 ( V_36 ) ;
int V_6 ;
switch ( V_39 ) {
case V_40 :
V_6 = F_9 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_26 = V_6 ;
return V_41 ;
case V_42 :
* V_26 = V_2 -> V_14 ;
return V_41 ;
case V_43 :
V_6 = F_4 ( V_2 , V_18 ) ;
return V_6 ;
}
return - V_25 ;
}
static int F_12 ( struct V_35 * V_36 ,
struct V_37 const * V_38 ,
int V_26 , int V_18 , long V_39 )
{
struct V_1 * V_2 = F_11 ( V_36 ) ;
int V_6 ;
switch ( V_39 ) {
case V_42 :
V_2 -> V_14 = V_26 ;
return V_26 ;
case V_43 :
V_6 = F_6 ( V_2 , V_18 ) ;
return V_6 ;
}
return - V_25 ;
}
static T_3 F_13 ( struct V_44 * V_45 ,
struct V_46 * V_47 , char * V_48 )
{
int V_5 , V_27 , V_49 ;
V_27 = F_5 ( V_23 ) ;
for ( V_5 = 0 , V_49 = 0 ; V_5 < V_27 ; V_5 ++ )
V_49 += sprintf ( V_48 + V_49 , L_1 , V_23 [ V_5 ] ) ;
return V_49 + sprintf ( V_48 + V_49 , L_2 ) ;
}
static int F_14 ( struct V_3 * V_4 ,
const struct V_50 * V_51 )
{
struct V_1 * V_2 ;
struct V_35 * V_36 ;
int V_6 ;
V_36 = F_15 ( & V_4 -> V_45 , sizeof( * V_2 ) ) ;
if ( ! V_36 ) {
F_16 ( & V_4 -> V_45 , L_3 ) ;
return - V_52 ;
}
V_2 = F_11 ( V_36 ) ;
F_17 ( V_4 , V_36 ) ;
V_2 -> V_4 = V_4 ;
F_18 ( & V_2 -> V_28 ) ;
V_36 -> V_45 . V_53 = & V_4 -> V_45 ;
V_36 -> V_54 = V_55 ;
V_36 -> V_56 = F_5 ( V_55 ) ;
V_36 -> V_57 = & V_58 ;
V_36 -> V_59 = V_51 -> V_59 ;
V_36 -> V_60 = V_61 ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 ) {
F_16 ( & V_4 -> V_45 ,
L_4 ,
V_62 ) ;
return V_6 ;
}
V_6 = F_19 ( V_36 ) ;
if ( V_6 ) {
F_16 ( & V_4 -> V_45 ,
L_5 ,
V_62 ) ;
return V_6 ;
}
return 0 ;
}
static int F_20 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = F_21 ( V_4 ) ;
F_22 ( V_36 ) ;
return 0 ;
}
