static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
T_1 V_11 ;
int V_12 ;
V_11 = ( V_10 -> V_13 [ V_3 ] & ~ V_5 ) | ( V_4 << V_6 ) ;
V_12 = F_4 ( V_2 , V_3 , V_11 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_1 , V_12 ) ;
return V_12 ;
}
V_10 -> V_13 [ V_3 ] = V_11 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_15 , T_1 * V_16 )
{
int V_12 ;
struct V_17 V_18 [ 2 ] = {
{
. V_19 = V_2 -> V_19 ,
. V_20 = V_21 ,
. V_22 = 1 ,
. V_23 = & V_3 ,
} , {
. V_19 = V_2 -> V_19 ,
. V_20 = V_24 ,
. V_22 = V_15 ,
. V_23 = V_16 ,
}
} ;
V_12 = F_7 ( V_2 -> V_25 , V_18 , 2 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_2 ) ;
return V_12 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
T_1 V_26 ;
int V_12 ;
V_12 = F_6 ( V_2 , V_27 , 1 , & V_26 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_3 ) ;
return V_12 ;
}
if ( V_26 != V_28 ) {
F_5 ( & V_2 -> V_14 , L_4 ) ;
return - V_29 ;
}
V_12 = F_1 ( V_2 ,
V_30 ,
V_31 ,
V_32 ,
V_33 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_5 ) ;
return V_12 ;
}
V_12 = F_6 ( V_2 , V_34 , 3 , V_10 -> V_35 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_6 ) ;
return V_12 ;
}
V_12 = F_1 ( V_2 ,
V_30 ,
V_36 ,
V_32 ,
V_33 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_7 ) ;
return V_12 ;
}
V_10 -> V_37 [ 0 ] = ( ( V_10 -> V_35 [ 0 ] + 128 ) * 30 ) >> 8 ;
V_10 -> V_37 [ 1 ] = ( ( V_10 -> V_35 [ 1 ] + 128 ) * 30 ) >> 8 ;
V_10 -> V_37 [ 2 ] = ( ( V_10 -> V_35 [ 2 ] + 128 ) * 30 ) >> 8 ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_38 ;
T_2 V_39 = V_40 ;
int V_12 ;
while ( V_39 ) {
F_10 ( V_41 ) ;
if ( F_11 ( V_10 -> V_42 ) )
break;
V_39 -= V_41 ;
}
if ( ! V_39 ) {
F_5 ( & V_2 -> V_14 , L_8 ) ;
return - V_43 ;
}
V_12 = F_6 ( V_2 , V_44 , 1 , & V_38 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_9 ) ;
return V_12 ;
}
return V_38 ;
}
static int F_12 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_38 ;
T_2 V_39 = V_40 ;
int V_12 ;
while ( V_39 ) {
F_10 ( V_41 ) ;
V_12 = F_6 ( V_2 , V_44 , 1 , & V_38 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_9 ) ;
return V_12 ;
}
if ( V_38 )
break;
V_39 -= V_41 ;
}
if ( ! V_39 ) {
F_5 ( & V_2 -> V_14 , L_8 ) ;
return - V_43 ;
}
return V_38 ;
}
static int F_13 ( struct V_7 * V_8 , int V_45 , int * V_4 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_3 V_46 ;
T_4 V_47 ;
T_1 V_38 ;
int V_12 ;
F_14 ( & V_10 -> V_48 ) ;
V_12 = F_1 ( V_2 ,
V_30 ,
V_49 ,
V_32 ,
V_33 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_10 ) ;
goto exit;
}
if ( F_15 ( V_10 -> V_42 ) )
V_12 = F_9 ( V_10 ) ;
else
V_12 = F_12 ( V_10 ) ;
if ( V_12 < 0 )
goto exit;
V_38 = V_12 ;
if ( V_38 & V_50 ) {
V_12 = F_6 ( V_2 , V_51 , 1 , & V_38 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_11 ) ;
goto exit;
}
if ( V_38 & ( V_52 |
V_53 ) ) {
F_5 ( & V_2 -> V_14 , L_12 ,
V_38 ) ;
V_12 = - V_43 ;
goto exit;
}
}
V_12 = F_6 ( V_2 , V_54 [ V_45 ] ,
2 , ( T_1 * ) & V_46 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_13 ) ;
goto exit;
}
F_16 ( & V_10 -> V_48 ) ;
V_47 = ( T_4 ) ( F_17 ( V_46 ) ) ;
V_47 = F_18 ( T_4 , V_47 , - 4096 , 4095 ) ;
* V_4 = V_47 ;
return V_55 ;
exit:
F_16 ( & V_10 -> V_48 ) ;
return V_12 ;
}
static int F_19 ( struct V_7 * V_8 ,
struct V_56 const * V_57 ,
int * V_4 , int * V_58 ,
long V_5 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
switch ( V_5 ) {
case V_59 :
return F_13 ( V_8 , V_57 -> V_60 , V_4 ) ;
case V_61 :
* V_4 = V_10 -> V_37 [ V_57 -> V_60 ] ;
return V_55 ;
}
return - V_43 ;
}
static int T_5 F_20 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
struct V_9 * V_10 ;
struct V_7 * V_8 ;
int V_42 ;
int V_64 ;
if ( V_2 -> V_14 . V_65 == NULL )
V_42 = - 1 ;
else
V_42 = * ( int * ) ( V_2 -> V_14 . V_65 ) ;
if ( F_15 ( V_42 ) ) {
V_64 = F_21 ( V_42 , V_66 , L_14 ) ;
if ( V_64 < 0 ) {
F_5 ( & V_2 -> V_14 ,
L_15 ,
V_42 , V_64 ) ;
goto exit;
}
}
V_8 = F_22 ( sizeof( * V_10 ) ) ;
if ( V_8 == NULL ) {
V_64 = - V_67 ;
goto V_68;
}
V_10 = F_3 ( V_8 ) ;
F_23 ( V_2 , V_8 ) ;
V_64 = F_8 ( V_2 ) ;
if ( V_64 < 0 ) {
F_5 ( & V_2 -> V_14 , L_16 ) ;
goto V_69;
}
V_10 -> V_2 = V_2 ;
F_24 ( & V_10 -> V_48 ) ;
V_10 -> V_70 = V_2 -> V_71 ;
V_10 -> V_42 = V_42 ;
V_8 -> V_14 . V_72 = & V_2 -> V_14 ;
V_8 -> V_73 = V_74 ;
V_8 -> V_75 = F_25 ( V_74 ) ;
V_8 -> V_76 = & V_77 ;
V_8 -> V_78 = V_79 ;
V_64 = F_26 ( V_8 ) ;
if ( V_64 < 0 )
goto V_69;
return 0 ;
V_69:
F_27 ( V_8 ) ;
V_68:
if ( F_15 ( V_42 ) )
F_28 ( V_42 ) ;
exit:
return V_64 ;
}
static int T_6 F_29 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_30 ( V_8 ) ;
if ( F_15 ( V_10 -> V_42 ) )
F_28 ( V_10 -> V_42 ) ;
F_27 ( V_8 ) ;
return 0 ;
}
