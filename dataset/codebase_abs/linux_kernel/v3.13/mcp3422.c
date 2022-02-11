static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_4 = F_3 ( V_2 -> V_6 , & V_3 , 1 ) ;
if ( V_4 > 0 ) {
V_2 -> V_7 = V_3 ;
V_4 = 0 ;
}
F_4 ( & V_2 -> V_5 ) ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 , int * V_8 , T_1 * V_7 )
{
int V_4 = 0 ;
T_1 V_9 = F_6 ( V_2 -> V_7 ) ;
T_1 V_10 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_2 V_11 ;
if ( V_9 == V_12 ) {
V_4 = F_7 ( V_2 -> V_6 , V_10 , 4 ) ;
V_11 = V_10 [ 0 ] << 16 | V_10 [ 1 ] << 8 | V_10 [ 2 ] ;
* V_7 = V_10 [ 3 ] ;
} else {
V_4 = F_7 ( V_2 -> V_6 , V_10 , 3 ) ;
V_11 = V_10 [ 0 ] << 8 | V_10 [ 1 ] ;
* V_7 = V_10 [ 2 ] ;
}
* V_8 = F_8 ( V_11 , V_13 [ V_9 ] ) ;
return V_4 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_14 const * V_15 , int * V_8 )
{
int V_4 ;
T_1 V_7 ;
T_1 V_16 = V_15 -> V_15 ;
if ( V_16 != F_10 ( V_2 -> V_7 ) ) {
V_7 = V_2 -> V_7 ;
V_7 &= ~ V_17 ;
V_7 |= F_11 ( V_16 ) ;
V_7 &= ~ V_18 ;
V_7 |= F_12 ( V_2 -> V_19 [ V_16 ] ) ;
V_4 = F_1 ( V_2 , V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
F_13 ( V_20 [ F_6 ( V_2 -> V_7 ) ] ) ;
}
return F_5 ( V_2 , V_8 , & V_7 ) ;
}
static int F_14 ( struct V_21 * V_22 ,
struct V_14 const * V_15 , int * V_23 ,
int * V_24 , long V_25 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
int V_26 ;
T_1 V_9 = F_6 ( V_2 -> V_7 ) ;
T_1 V_19 = F_16 ( V_2 -> V_7 ) ;
switch ( V_25 ) {
case V_27 :
V_26 = F_9 ( V_2 , V_15 , V_23 ) ;
if ( V_26 < 0 )
return - V_28 ;
return V_29 ;
case V_30 :
* V_23 = 0 ;
* V_24 = V_31 [ V_9 ] [ V_19 ] ;
return V_32 ;
case V_33 :
* V_23 = V_34 [ F_6 ( V_2 -> V_7 ) ] ;
return V_29 ;
default:
break;
}
return - V_28 ;
}
static int F_17 ( struct V_21 * V_22 ,
struct V_14 const * V_15 , int V_23 ,
int V_24 , long V_25 )
{
struct V_1 * V_2 = F_15 ( V_22 ) ;
T_1 V_11 ;
T_1 V_7 = V_2 -> V_7 ;
T_1 V_16 = V_15 -> V_15 ;
T_1 V_9 = F_6 ( V_7 ) ;
T_1 V_35 ;
switch ( V_25 ) {
case V_30 :
if ( V_23 != 0 )
return - V_28 ;
for ( V_35 = 0 ; V_35 < F_18 ( V_31 [ 0 ] ) ; V_35 ++ ) {
if ( V_24 == V_31 [ V_9 ] [ V_35 ] ) {
V_2 -> V_19 [ V_16 ] = V_35 ;
V_7 &= ~ V_17 ;
V_7 |= F_11 ( V_16 ) ;
V_7 &= ~ V_18 ;
V_7 |= F_12 ( V_2 -> V_19 [ V_16 ] ) ;
return F_1 ( V_2 , V_7 ) ;
}
}
return - V_28 ;
case V_33 :
switch ( V_23 ) {
case 240 :
V_11 = V_36 ;
break;
case 60 :
V_11 = V_37 ;
break;
case 15 :
V_11 = V_38 ;
break;
case 3 :
V_11 = V_12 ;
break;
default:
return - V_28 ;
}
V_7 &= ~ V_17 ;
V_7 |= F_11 ( V_16 ) ;
V_7 &= ~ V_39 ;
V_7 |= F_19 ( V_11 ) ;
return F_1 ( V_2 , V_7 ) ;
default:
break;
}
return - V_28 ;
}
static int F_20 ( struct V_21 * V_40 ,
struct V_14 const * V_41 , long V_25 )
{
switch ( V_25 ) {
case V_30 :
return V_32 ;
case V_33 :
return V_42 ;
default:
return - V_28 ;
}
}
static T_3 F_21 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_10 )
{
struct V_1 * V_2 = F_15 ( F_22 ( V_44 ) ) ;
T_1 V_9 = F_6 ( V_2 -> V_7 ) ;
return sprintf ( V_10 , L_1 ,
V_31 [ V_9 ] [ 0 ] ,
V_31 [ V_9 ] [ 1 ] ,
V_31 [ V_9 ] [ 2 ] ,
V_31 [ V_9 ] [ 3 ] ) ;
}
static int F_23 ( struct V_47 * V_48 ,
const struct V_49 * V_50 )
{
struct V_21 * V_40 ;
struct V_1 * V_2 ;
int V_26 ;
T_1 V_7 ;
if ( ! F_24 ( V_48 -> V_51 , V_52 ) )
return - V_53 ;
V_40 = F_25 ( & V_48 -> V_44 , sizeof( * V_2 ) ) ;
if ( ! V_40 )
return - V_54 ;
V_2 = F_15 ( V_40 ) ;
V_2 -> V_6 = V_48 ;
F_26 ( & V_2 -> V_5 ) ;
V_40 -> V_44 . V_55 = & V_48 -> V_44 ;
V_40 -> V_56 = F_27 ( & V_48 -> V_44 ) ;
V_40 -> V_57 = V_58 ;
V_40 -> V_59 = & V_60 ;
switch ( ( unsigned int ) ( V_50 -> V_61 ) ) {
case 2 :
case 3 :
V_40 -> V_62 = V_63 ;
V_40 -> V_64 = F_18 ( V_63 ) ;
break;
case 4 :
V_40 -> V_62 = V_65 ;
V_40 -> V_64 = F_18 ( V_65 ) ;
break;
}
V_7 = ( V_66
| F_11 ( 1 )
| F_12 ( V_67 )
| F_19 ( V_36 ) ) ;
F_1 ( V_2 , V_7 ) ;
V_26 = F_28 ( V_40 ) ;
if ( V_26 < 0 )
return V_26 ;
F_29 ( V_48 , V_40 ) ;
return 0 ;
}
static int F_30 ( struct V_47 * V_48 )
{
F_31 ( F_32 ( V_48 ) ) ;
return 0 ;
}
