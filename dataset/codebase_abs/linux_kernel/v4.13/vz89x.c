static bool F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 [ V_4 ] == 0 )
return true ;
return ! ! ( V_2 -> V_3 [ V_2 -> V_5 -> V_6 - 1 ] > 0 ) ;
}
static bool F_2 ( struct V_1 * V_2 )
{
T_1 V_7 = 0 ;
int V_8 , V_9 = 0 ;
for ( V_8 = 0 ; V_8 < ( V_2 -> V_5 -> V_6 - 1 ) ; V_8 ++ ) {
V_9 = V_7 + V_2 -> V_3 [ V_8 ] ;
V_7 = V_9 ;
V_7 += V_9 / 256 ;
}
return ! ( ( 0xff - V_7 ) == V_2 -> V_3 [ V_2 -> V_5 -> V_6 - 1 ] ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_10 )
{
const struct V_11 * V_5 = V_2 -> V_5 ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_14 V_15 [ 2 ] ;
int V_16 ;
T_1 V_17 [ 6 ] = { V_10 , 0 , 0 , 0 , 0 , 0xf3 } ;
V_15 [ 0 ] . V_18 = V_13 -> V_18 ;
V_15 [ 0 ] . V_19 = V_13 -> V_19 ;
V_15 [ 0 ] . V_20 = V_5 -> V_21 ;
V_15 [ 0 ] . V_17 = ( char * ) & V_17 ;
V_15 [ 1 ] . V_18 = V_13 -> V_18 ;
V_15 [ 1 ] . V_19 = V_13 -> V_19 | V_22 ;
V_15 [ 1 ] . V_20 = V_5 -> V_6 ;
V_15 [ 1 ] . V_17 = ( char * ) & V_2 -> V_3 ;
V_16 = F_4 ( V_13 -> V_23 , V_15 , 2 ) ;
return ( V_16 == 2 ) ? 0 : V_16 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_10 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_16 ;
int V_8 ;
V_16 = F_6 ( V_13 , V_10 , 0 ) ;
if ( V_16 < 0 )
return V_16 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_5 -> V_6 ; V_8 ++ ) {
V_16 = F_7 ( V_13 ) ;
if ( V_16 < 0 )
return V_16 ;
V_2 -> V_3 [ V_8 ] = V_16 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
const struct V_11 * V_5 = V_2 -> V_5 ;
int V_16 ;
if ( ! F_9 ( V_24 , V_2 -> V_25 + V_26 ) )
return V_2 -> V_27 ? 0 : - V_28 ;
V_2 -> V_27 = false ;
V_2 -> V_25 = V_24 ;
V_16 = V_2 -> V_29 ( V_2 , V_5 -> V_10 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = V_5 -> V_30 ( V_2 ) ;
if ( V_16 )
return - V_28 ;
V_2 -> V_27 = true ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_31 const * V_32 ,
int * V_33 )
{
T_1 * V_34 = ( T_1 * ) & V_2 -> V_3 [ V_32 -> V_35 ] ;
switch ( V_32 -> V_36 . V_37 ) {
case V_38 :
* V_33 = F_11 ( ( V_39 * ) V_34 ) & F_12 ( 23 , 0 ) ;
break;
case V_40 :
* V_33 = F_13 ( ( V_41 * ) V_34 ) >> 8 ;
break;
default:
return - V_42 ;
}
return 0 ;
}
static int F_14 ( struct V_43 * V_44 ,
struct V_31 const * V_32 , int * V_33 ,
int * V_45 , long V_46 )
{
struct V_1 * V_2 = F_15 ( V_44 ) ;
int V_16 = - V_42 ;
switch ( V_46 ) {
case V_47 :
F_16 ( & V_2 -> V_48 ) ;
V_16 = F_8 ( V_2 ) ;
F_17 ( & V_2 -> V_48 ) ;
if ( V_16 )
return V_16 ;
switch ( V_32 -> type ) {
case V_49 :
* V_33 = V_2 -> V_3 [ V_32 -> V_35 ] ;
return V_50 ;
case V_51 :
V_16 = F_10 ( V_2 , V_32 , V_33 ) ;
if ( ! V_16 )
return V_50 ;
break;
default:
return - V_42 ;
}
break;
case V_52 :
switch ( V_32 -> type ) {
case V_51 :
* V_33 = 10 ;
return V_50 ;
default:
return - V_42 ;
}
break;
case V_53 :
switch ( V_32 -> V_54 ) {
case V_55 :
* V_33 = 44 ;
* V_45 = 250000 ;
return V_56 ;
case V_57 :
* V_33 = - 13 ;
return V_50 ;
default:
return - V_42 ;
}
}
return V_16 ;
}
static int F_18 ( struct V_12 * V_13 ,
const struct V_58 * V_59 )
{
struct V_43 * V_44 ;
struct V_1 * V_2 ;
const struct V_60 * V_61 ;
int V_62 ;
V_44 = F_19 ( & V_13 -> V_63 , sizeof( * V_2 ) ) ;
if ( ! V_44 )
return - V_64 ;
V_2 = F_15 ( V_44 ) ;
if ( F_20 ( V_13 -> V_23 , V_65 ) )
V_2 -> V_29 = F_3 ;
else if ( F_20 ( V_13 -> V_23 ,
V_66 | V_67 ) )
V_2 -> V_29 = F_5 ;
else
return - V_68 ;
V_61 = F_21 ( V_69 , & V_13 -> V_63 ) ;
if ( ! V_61 )
V_62 = V_59 -> V_70 ;
else
V_62 = ( unsigned long ) V_61 -> V_2 ;
F_22 ( V_13 , V_44 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_5 = & V_71 [ V_62 ] ;
V_2 -> V_25 = V_24 - V_26 ;
F_23 ( & V_2 -> V_48 ) ;
V_44 -> V_63 . V_72 = & V_13 -> V_63 ;
V_44 -> V_73 = & V_74 ;
V_44 -> V_75 = F_24 ( & V_13 -> V_63 ) ;
V_44 -> V_76 = V_77 ;
V_44 -> V_78 = V_2 -> V_5 -> V_78 ;
V_44 -> V_79 = V_2 -> V_5 -> V_79 ;
return F_25 ( & V_13 -> V_63 , V_44 ) ;
}
