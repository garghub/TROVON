static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
return V_2 -> V_7 -> V_8 ;
default:
return 1 ;
}
}
static int F_2 ( void * V_9 , unsigned int V_3 ,
unsigned int V_10 )
{
struct V_11 * V_12 = V_9 ;
struct V_1 * V_2 = F_3 ( V_12 ) ;
unsigned int V_13 , V_14 ;
T_1 V_15 [ 5 ] ;
int V_16 ;
V_14 = F_1 ( V_2 , V_3 ) ;
V_15 [ 0 ] = V_3 ;
for ( V_13 = V_14 ; V_13 >= 1 ; -- V_13 ) {
V_15 [ V_13 ] = V_10 ;
V_10 >>= 8 ;
}
V_16 = F_4 ( V_12 , V_15 , V_14 + 1 ) ;
if ( V_16 == V_14 + 1 )
return 0 ;
else if ( V_16 < 0 )
return V_16 ;
else
return - V_17 ;
}
static int F_5 ( void * V_9 , unsigned int V_3 ,
unsigned int * V_10 )
{
struct V_11 * V_12 = V_9 ;
struct V_1 * V_2 = F_3 ( V_12 ) ;
T_1 V_18 , V_19 [ 4 ] ;
struct V_20 V_21 [ 2 ] ;
unsigned int V_14 ;
unsigned int V_13 ;
int V_16 ;
V_14 = F_1 ( V_2 , V_3 ) ;
V_18 = V_3 ;
V_21 [ 0 ] . V_22 = V_12 -> V_22 ;
V_21 [ 0 ] . V_23 = sizeof( V_18 ) ;
V_21 [ 0 ] . V_15 = & V_18 ;
V_21 [ 0 ] . V_24 = 0 ;
V_21 [ 1 ] . V_22 = V_12 -> V_22 ;
V_21 [ 1 ] . V_23 = V_14 ;
V_21 [ 1 ] . V_15 = V_19 ;
V_21 [ 1 ] . V_24 = V_25 ;
V_16 = F_6 ( V_12 -> V_26 , V_21 , F_7 ( V_21 ) ) ;
if ( V_16 < 0 )
return V_16 ;
else if ( V_16 != F_7 ( V_21 ) )
return - V_17 ;
* V_10 = 0 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
* V_10 <<= 8 ;
* V_10 |= V_19 [ V_13 ] ;
}
return 0 ;
}
static int F_8 ( struct V_27 * V_28 , unsigned int V_29 )
{
struct V_1 * V_2 = F_9 ( V_28 -> V_30 ) ;
V_2 -> V_29 = V_29 ;
return 0 ;
}
static int F_10 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = F_9 ( V_28 -> V_30 ) ;
T_2 V_35 ;
switch ( V_2 -> V_29 & V_36 ) {
case V_37 :
V_35 = 0x00 ;
break;
case V_38 :
V_35 = 0x03 ;
break;
case V_39 :
V_35 = 0x06 ;
break;
default:
return - V_40 ;
}
if ( F_11 ( V_34 ) >= 24 )
V_35 += 2 ;
else if ( F_11 ( V_34 ) >= 20 )
V_35 += 1 ;
return F_12 ( V_2 -> V_41 , V_42 ,
V_43 , V_35 ) ;
}
static int F_13 ( struct V_44 * V_30 ,
enum V_45 V_46 )
{
struct V_1 * V_2 = F_9 ( V_30 ) ;
int V_16 ;
switch ( V_46 ) {
case V_47 :
break;
case V_48 :
break;
case V_49 :
if ( F_14 ( V_30 ) == V_50 ) {
if ( ! F_15 ( V_2 -> V_51 ) ) {
V_16 = F_16 ( V_2 -> V_51 ) ;
if ( V_16 ) {
F_17 ( V_30 -> V_52 ,
L_1 ,
V_16 ) ;
return V_16 ;
}
}
F_18 ( V_2 -> V_53 , 0 ) ;
F_19 ( 5000 , 6000 ) ;
F_20 ( V_2 -> V_41 , false ) ;
V_16 = F_21 ( V_2 -> V_41 ) ;
if ( V_16 )
return V_16 ;
}
break;
case V_50 :
F_20 ( V_2 -> V_41 , true ) ;
F_18 ( V_2 -> V_53 , 1 ) ;
if ( ! F_15 ( V_2 -> V_51 ) )
F_22 ( V_2 -> V_51 ) ;
break;
}
return 0 ;
}
static int F_23 ( struct V_11 * V_12 ,
const struct V_54 * V_55 )
{
struct V_1 * V_2 ;
struct V_56 * V_52 = & V_12 -> V_52 ;
const struct V_57 * V_58 ;
int V_13 , V_16 ;
V_2 = F_24 ( V_52 , sizeof( * V_2 ) , V_59 ) ;
if ( ! V_2 )
return - V_60 ;
F_25 ( V_12 , V_2 ) ;
V_58 = F_26 ( V_61 , V_52 ) ;
if ( ! V_58 ) {
F_17 ( V_52 , L_2 ) ;
return - V_40 ;
}
V_2 -> V_7 = V_58 -> V_62 ;
V_2 -> V_51 = F_27 ( V_52 , L_3 ) ;
if ( F_15 ( V_2 -> V_51 ) && F_28 ( V_2 -> V_51 ) != - V_63 ) {
F_17 ( V_52 , L_4 ,
F_28 ( V_2 -> V_51 ) ) ;
return F_28 ( V_2 -> V_51 ) ;
}
F_29 ( V_2 -> V_7 -> V_64 > V_65 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_7 -> V_64 ; V_13 ++ )
V_2 -> V_66 [ V_13 ] . V_67 = V_2 -> V_7 -> V_68 [ V_13 ] ;
V_16 = F_30 ( V_52 , V_2 -> V_7 -> V_64 ,
V_2 -> V_66 ) ;
if ( V_16 ) {
F_17 ( V_52 , L_5 , V_16 ) ;
return V_16 ;
}
V_16 = F_31 ( V_2 -> V_7 -> V_64 ,
V_2 -> V_66 ) ;
if ( V_16 ) {
F_17 ( V_52 , L_6 , V_16 ) ;
return V_16 ;
}
V_2 -> V_41 = F_32 ( V_52 , NULL , V_12 ,
V_2 -> V_7 -> V_69 ) ;
if ( F_15 ( V_2 -> V_41 ) )
return F_28 ( V_2 -> V_41 ) ;
V_2 -> V_53 = F_33 ( V_52 , L_7 , V_70 ) ;
if ( F_15 ( V_2 -> V_53 ) ) {
F_17 ( V_52 , L_8 ,
F_28 ( V_2 -> V_53 ) ) ;
return F_28 ( V_2 -> V_53 ) ;
}
V_2 -> V_71 = F_33 ( V_52 , L_9 ,
V_72 ) ;
if ( F_15 ( V_2 -> V_71 ) ) {
F_17 ( V_52 , L_10 ,
F_28 ( V_2 -> V_71 ) ) ;
return F_28 ( V_2 -> V_71 ) ;
} else if ( V_2 -> V_71 ) {
F_19 ( 100 , 200 ) ;
F_18 ( V_2 -> V_71 , 0 ) ;
F_19 ( 12000 , 20000 ) ;
}
V_16 = F_34 ( V_2 -> V_41 , V_73 , 0 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_12 ( V_2 -> V_41 , V_74 ,
V_75 , 0 ) ;
if ( V_16 )
return V_16 ;
memcpy ( & V_2 -> V_76 , & V_77 , sizeof( V_2 -> V_76 ) ) ;
V_2 -> V_76 . V_78 = V_2 -> V_7 -> V_78 ;
V_2 -> V_76 . V_79 = V_2 -> V_7 -> V_79 ;
if ( V_2 -> V_7 -> V_8 == 2 ) {
V_16 = F_12 ( V_2 -> V_41 , V_4 , 1 , 0 ) ;
if ( V_16 )
return V_16 ;
}
F_20 ( V_2 -> V_41 , true ) ;
F_18 ( V_2 -> V_53 , 1 ) ;
return F_35 ( & V_12 -> V_52 , & V_2 -> V_76 ,
& V_80 , 1 ) ;
}
static int F_36 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_3 ( V_12 ) ;
F_37 ( & V_12 -> V_52 ) ;
F_38 ( V_2 -> V_7 -> V_64 , V_2 -> V_66 ) ;
return 0 ;
}
