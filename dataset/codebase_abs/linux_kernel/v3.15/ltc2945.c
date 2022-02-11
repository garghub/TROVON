static inline bool F_1 ( T_1 V_1 )
{
return V_1 < V_2 ;
}
static long long F_2 ( struct V_3 * V_4 , T_1 V_1 )
{
struct V_5 * V_5 = F_3 ( V_4 ) ;
unsigned int V_6 ;
T_1 V_7 [ 3 ] ;
long long V_8 ;
int V_9 ;
V_9 = F_4 ( V_5 , V_1 , V_7 ,
F_1 ( V_1 ) ? 3 : 2 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( F_1 ( V_1 ) ) {
V_8 = ( V_7 [ 0 ] << 16 ) + ( V_7 [ 1 ] << 8 ) + V_7 [ 2 ] ;
} else {
V_8 = ( V_7 [ 0 ] << 4 ) + ( V_7 [ 1 ] >> 4 ) ;
}
switch ( V_1 ) {
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
V_9 = F_5 ( V_5 , V_15 , & V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_6 & V_16 ) {
V_8 *= 625LL ;
} else {
V_8 = ( V_8 * 25LL ) >> 1 ;
}
break;
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
V_8 *= 25 ;
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
V_8 = V_8 >> 1 ;
break;
case V_2 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
V_8 *= 25 ;
break;
default:
return - V_31 ;
}
return V_8 ;
}
static int F_6 ( struct V_3 * V_4 , T_1 V_1 ,
unsigned long V_8 )
{
struct V_5 * V_5 = F_3 ( V_4 ) ;
unsigned int V_6 ;
int V_9 ;
switch ( V_1 ) {
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
V_9 = F_5 ( V_5 , V_15 , & V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_6 & V_16 ) {
V_8 = F_7 ( V_8 , 625 ) ;
} else {
V_8 = F_7 ( V_8 , 25 ) * 2 ;
}
break;
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
V_8 /= 25 ;
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
V_8 *= 2 ;
break;
case V_2 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
V_8 = F_7 ( V_8 , 25 ) ;
break;
default:
return - V_31 ;
}
return V_8 ;
}
static T_2 F_8 ( struct V_3 * V_4 ,
struct V_32 * V_33 , char * V_7 )
{
struct V_34 * V_35 = F_9 ( V_33 ) ;
long long V_36 ;
V_36 = F_2 ( V_4 , V_35 -> V_37 ) ;
if ( V_36 < 0 )
return V_36 ;
return snprintf ( V_7 , V_38 , L_1 , V_36 ) ;
}
static T_2 F_10 ( struct V_3 * V_4 ,
struct V_32 * V_33 ,
const char * V_7 , T_3 V_39 )
{
struct V_34 * V_35 = F_9 ( V_33 ) ;
struct V_5 * V_5 = F_3 ( V_4 ) ;
T_1 V_1 = V_35 -> V_37 ;
unsigned long V_8 ;
T_1 V_40 [ 3 ] ;
int V_41 ;
int V_42 ;
int V_9 ;
V_9 = F_11 ( V_7 , 10 , & V_8 ) ;
if ( V_9 )
return V_9 ;
V_42 = F_6 ( V_4 , V_1 , V_8 ) ;
if ( F_1 ( V_1 ) ) {
V_42 = F_12 ( V_42 , 0 , 0xffffff ) ;
V_40 [ 0 ] = V_42 >> 16 ;
V_40 [ 1 ] = ( V_42 >> 8 ) & 0xff ;
V_40 [ 2 ] = V_42 ;
V_41 = 3 ;
} else {
V_42 = F_12 ( V_42 , 0 , 0xfff ) << 4 ;
V_40 [ 0 ] = V_42 >> 8 ;
V_40 [ 1 ] = V_42 & 0xff ;
V_41 = 2 ;
}
V_9 = F_13 ( V_5 , V_1 , V_40 , V_41 ) ;
return V_9 < 0 ? V_9 : V_39 ;
}
static T_2 F_14 ( struct V_3 * V_4 ,
struct V_32 * V_33 ,
const char * V_7 , T_3 V_39 )
{
struct V_34 * V_35 = F_9 ( V_33 ) ;
struct V_5 * V_5 = F_3 ( V_4 ) ;
T_1 V_1 = V_35 -> V_37 ;
int V_41 = F_1 ( V_1 ) ? 3 : 2 ;
T_1 V_43 [ 3 ] = { 0xff , 0xff , 0xff } ;
T_1 V_44 [ 3 ] = { 0 , 0 , 0 } ;
unsigned long V_8 ;
int V_9 ;
V_9 = F_11 ( V_7 , 10 , & V_8 ) ;
if ( V_9 )
return V_9 ;
if ( V_8 != 1 )
return - V_31 ;
V_9 = F_15 ( V_5 , V_15 , V_45 ,
V_45 ) ;
V_9 = F_13 ( V_5 , V_1 , V_43 , V_41 ) ;
if ( V_9 )
return V_9 ;
switch ( V_1 ) {
case V_12 :
V_1 = V_11 ;
break;
case V_28 :
V_1 = V_27 ;
break;
case V_19 :
V_1 = V_18 ;
break;
case V_26 :
V_1 = V_23 ;
break;
default:
F_16 ( 1 , L_2 , V_1 ) ;
return - V_31 ;
}
V_9 = F_13 ( V_5 , V_1 , V_44 , V_41 ) ;
F_15 ( V_5 , V_15 , V_45 , 0 ) ;
return V_9 ? : V_39 ;
}
static T_2 F_17 ( struct V_3 * V_4 ,
struct V_32 * V_33 , char * V_7 )
{
struct V_34 * V_35 = F_9 ( V_33 ) ;
struct V_5 * V_5 = F_3 ( V_4 ) ;
unsigned int V_46 ;
int V_9 ;
V_9 = F_5 ( V_5 , V_47 , & V_46 ) ;
if ( V_9 < 0 )
return V_9 ;
V_46 &= V_35 -> V_37 ;
if ( V_46 )
F_15 ( V_5 , V_47 , V_35 -> V_37 , 0 ) ;
return snprintf ( V_7 , V_38 , L_3 , ! ! V_46 ) ;
}
static int F_18 ( struct V_48 * V_49 ,
const struct V_50 * V_51 )
{
struct V_3 * V_4 = & V_49 -> V_4 ;
struct V_3 * V_52 ;
struct V_5 * V_5 ;
V_5 = F_19 ( V_49 , & V_53 ) ;
if ( F_20 ( V_5 ) ) {
F_21 ( V_4 , L_4 ) ;
return F_22 ( V_5 ) ;
}
F_23 ( V_5 , V_47 , 0x00 ) ;
V_52 = F_24 ( V_4 , V_49 -> V_54 ,
V_5 ,
V_55 ) ;
return F_25 ( V_52 ) ;
}
