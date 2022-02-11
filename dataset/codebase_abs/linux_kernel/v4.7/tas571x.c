static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
return V_2 -> V_7 -> V_8 ;
case V_9 :
case V_10 :
case V_11 :
return 4 ;
default:
return 1 ;
}
}
static int F_2 ( void * V_12 , unsigned int V_3 ,
unsigned int V_13 )
{
struct V_14 * V_15 = V_12 ;
struct V_1 * V_2 = F_3 ( V_15 ) ;
unsigned int V_16 , V_17 ;
T_1 V_18 [ 5 ] ;
int V_19 ;
V_17 = F_1 ( V_2 , V_3 ) ;
V_18 [ 0 ] = V_3 ;
for ( V_16 = V_17 ; V_16 >= 1 ; -- V_16 ) {
V_18 [ V_16 ] = V_13 ;
V_13 >>= 8 ;
}
V_19 = F_4 ( V_15 , V_18 , V_17 + 1 ) ;
if ( V_19 == V_17 + 1 )
return 0 ;
else if ( V_19 < 0 )
return V_19 ;
else
return - V_20 ;
}
static int F_5 ( void * V_12 , unsigned int V_3 ,
unsigned int * V_13 )
{
struct V_14 * V_15 = V_12 ;
struct V_1 * V_2 = F_3 ( V_15 ) ;
T_1 V_21 , V_22 [ 4 ] ;
struct V_23 V_24 [ 2 ] ;
unsigned int V_17 ;
unsigned int V_16 ;
int V_19 ;
V_17 = F_1 ( V_2 , V_3 ) ;
V_21 = V_3 ;
V_24 [ 0 ] . V_25 = V_15 -> V_25 ;
V_24 [ 0 ] . V_26 = sizeof( V_21 ) ;
V_24 [ 0 ] . V_18 = & V_21 ;
V_24 [ 0 ] . V_27 = 0 ;
V_24 [ 1 ] . V_25 = V_15 -> V_25 ;
V_24 [ 1 ] . V_26 = V_17 ;
V_24 [ 1 ] . V_18 = V_22 ;
V_24 [ 1 ] . V_27 = V_28 ;
V_19 = F_6 ( V_15 -> V_29 , V_24 , F_7 ( V_24 ) ) ;
if ( V_19 < 0 )
return V_19 ;
else if ( V_19 != F_7 ( V_24 ) )
return - V_20 ;
* V_13 = 0 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
* V_13 <<= 8 ;
* V_13 |= V_22 [ V_16 ] ;
}
return 0 ;
}
static int F_8 ( struct V_30 * V_31 , unsigned int V_32 )
{
struct V_1 * V_2 = F_9 ( V_31 -> V_33 ) ;
V_2 -> V_32 = V_32 ;
return 0 ;
}
static int F_10 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = F_9 ( V_31 -> V_33 ) ;
T_2 V_38 ;
switch ( V_2 -> V_32 & V_39 ) {
case V_40 :
V_38 = 0x00 ;
break;
case V_41 :
V_38 = 0x03 ;
break;
case V_42 :
V_38 = 0x06 ;
break;
default:
return - V_43 ;
}
if ( F_11 ( V_37 ) >= 24 )
V_38 += 2 ;
else if ( F_11 ( V_37 ) >= 20 )
V_38 += 1 ;
return F_12 ( V_2 -> V_44 , V_45 ,
V_46 , V_38 ) ;
}
static int F_13 ( struct V_30 * V_31 , int V_47 )
{
struct V_48 * V_33 = V_31 -> V_33 ;
T_3 V_49 ;
int V_19 ;
V_49 = V_47 ? V_50 : 0 ;
V_19 = F_14 ( V_33 ,
V_51 ,
V_50 ,
V_49 ) ;
F_15 ( 1000 , 2000 ) ;
return V_19 ;
}
static int F_16 ( struct V_48 * V_33 ,
enum V_52 V_53 )
{
struct V_1 * V_2 = F_9 ( V_33 ) ;
int V_19 ;
switch ( V_53 ) {
case V_54 :
break;
case V_55 :
break;
case V_56 :
if ( F_17 ( V_33 ) == V_57 ) {
if ( ! F_18 ( V_2 -> V_58 ) ) {
V_19 = F_19 ( V_2 -> V_58 ) ;
if ( V_19 ) {
F_20 ( V_33 -> V_59 ,
L_1 ,
V_19 ) ;
return V_19 ;
}
}
F_21 ( V_2 -> V_60 , 0 ) ;
F_15 ( 5000 , 6000 ) ;
F_22 ( V_2 -> V_44 , false ) ;
V_19 = F_23 ( V_2 -> V_44 ) ;
if ( V_19 )
return V_19 ;
}
break;
case V_57 :
F_22 ( V_2 -> V_44 , true ) ;
F_21 ( V_2 -> V_60 , 1 ) ;
if ( ! F_18 ( V_2 -> V_58 ) )
F_24 ( V_2 -> V_58 ) ;
break;
}
return 0 ;
}
static int F_25 ( struct V_14 * V_15 ,
const struct V_61 * V_62 )
{
struct V_1 * V_2 ;
struct V_63 * V_59 = & V_15 -> V_59 ;
const struct V_64 * V_65 ;
int V_16 , V_19 ;
V_2 = F_26 ( V_59 , sizeof( * V_2 ) , V_66 ) ;
if ( ! V_2 )
return - V_67 ;
F_27 ( V_15 , V_2 ) ;
V_65 = F_28 ( V_68 , V_59 ) ;
if ( V_65 )
V_2 -> V_7 = V_65 -> V_69 ;
else
V_2 -> V_7 = ( void * ) V_62 -> V_70 ;
V_2 -> V_58 = F_29 ( V_59 , L_2 ) ;
if ( F_18 ( V_2 -> V_58 ) && F_30 ( V_2 -> V_58 ) != - V_71 ) {
F_20 ( V_59 , L_3 ,
F_30 ( V_2 -> V_58 ) ) ;
return F_30 ( V_2 -> V_58 ) ;
}
F_31 ( V_2 -> V_7 -> V_72 > V_73 ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_7 -> V_72 ; V_16 ++ )
V_2 -> V_74 [ V_16 ] . V_75 = V_2 -> V_7 -> V_76 [ V_16 ] ;
V_19 = F_32 ( V_59 , V_2 -> V_7 -> V_72 ,
V_2 -> V_74 ) ;
if ( V_19 ) {
F_20 ( V_59 , L_4 , V_19 ) ;
return V_19 ;
}
V_19 = F_33 ( V_2 -> V_7 -> V_72 ,
V_2 -> V_74 ) ;
if ( V_19 ) {
F_20 ( V_59 , L_5 , V_19 ) ;
return V_19 ;
}
V_2 -> V_44 = F_34 ( V_59 , NULL , V_15 ,
V_2 -> V_7 -> V_77 ) ;
if ( F_18 ( V_2 -> V_44 ) )
return F_30 ( V_2 -> V_44 ) ;
V_2 -> V_60 = F_35 ( V_59 , L_6 , V_78 ) ;
if ( F_18 ( V_2 -> V_60 ) ) {
F_20 ( V_59 , L_7 ,
F_30 ( V_2 -> V_60 ) ) ;
return F_30 ( V_2 -> V_60 ) ;
}
V_2 -> V_79 = F_35 ( V_59 , L_8 ,
V_80 ) ;
if ( F_18 ( V_2 -> V_79 ) ) {
F_20 ( V_59 , L_9 ,
F_30 ( V_2 -> V_79 ) ) ;
return F_30 ( V_2 -> V_79 ) ;
} else if ( V_2 -> V_79 ) {
F_15 ( 100 , 200 ) ;
F_21 ( V_2 -> V_79 , 0 ) ;
F_15 ( 12000 , 20000 ) ;
}
V_19 = F_36 ( V_2 -> V_44 , V_81 , 0 ) ;
if ( V_19 )
return V_19 ;
memcpy ( & V_2 -> V_82 , & V_83 , sizeof( V_2 -> V_82 ) ) ;
V_2 -> V_82 . V_84 = V_2 -> V_7 -> V_84 ;
V_2 -> V_82 . V_85 = V_2 -> V_7 -> V_85 ;
if ( V_2 -> V_7 -> V_8 == 2 ) {
V_19 = F_12 ( V_2 -> V_44 , V_4 , 1 , 0 ) ;
if ( V_19 )
return V_19 ;
}
F_22 ( V_2 -> V_44 , true ) ;
F_21 ( V_2 -> V_60 , 1 ) ;
return F_37 ( & V_15 -> V_59 , & V_2 -> V_82 ,
& V_86 , 1 ) ;
}
static int F_38 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_3 ( V_15 ) ;
F_39 ( & V_15 -> V_59 ) ;
F_40 ( V_2 -> V_7 -> V_72 , V_2 -> V_74 ) ;
return 0 ;
}
