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
V_10 -> V_36 [ 0 ] = ( ( V_10 -> V_35 [ 0 ] + 128 ) * 30 ) >> 8 ;
V_10 -> V_36 [ 1 ] = ( ( V_10 -> V_35 [ 1 ] + 128 ) * 30 ) >> 8 ;
V_10 -> V_36 [ 2 ] = ( ( V_10 -> V_35 [ 2 ] + 128 ) * 30 ) >> 8 ;
return 0 ;
}
static T_2 F_9 ( struct V_37 * V_14 , struct V_38 * V_39 ,
char * V_23 )
{
struct V_7 * V_8 = F_10 ( V_14 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
return sprintf ( V_23 , L_7 , V_10 -> V_40 ) ;
}
static T_2 F_11 ( struct V_37 * V_14 , struct V_38 * V_39 ,
const char * V_23 , T_3 V_41 )
{
struct V_7 * V_8 = F_10 ( V_14 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
bool V_42 ;
int V_12 ;
V_12 = F_12 ( V_23 , & V_42 ) ;
if ( V_12 < 0 )
return V_12 ;
F_13 ( & V_10 -> V_43 ) ;
if ( V_10 -> V_40 != V_42 ) {
V_12 = F_1 ( V_2 ,
V_30 ,
( T_1 ) V_42 ,
V_32 ,
V_33 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_8 ) ;
F_14 ( & V_10 -> V_43 ) ;
return V_12 ;
}
V_10 -> V_40 = V_42 ;
}
F_14 ( & V_10 -> V_43 ) ;
return V_41 ;
}
static int F_15 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_44 ;
T_4 V_45 = V_46 ;
int V_12 ;
while ( V_45 ) {
F_16 ( V_47 ) ;
if ( F_17 ( V_10 -> V_48 ) )
break;
V_45 -= V_47 ;
}
if ( ! V_45 ) {
F_5 ( & V_2 -> V_14 , L_9 ) ;
return - V_49 ;
}
V_12 = F_6 ( V_2 , V_50 , 1 , & V_44 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_10 ) ;
return V_12 ;
}
return V_44 ;
}
static int F_18 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_44 ;
T_4 V_45 = V_46 ;
int V_12 ;
while ( V_45 ) {
F_16 ( V_47 ) ;
V_12 = F_6 ( V_2 , V_50 , 1 , & V_44 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_10 ) ;
return V_12 ;
}
if ( V_44 )
break;
V_45 -= V_47 ;
}
if ( ! V_45 ) {
F_5 ( & V_2 -> V_14 , L_9 ) ;
return - V_49 ;
}
return V_44 ;
}
static int F_19 ( struct V_7 * V_8 , int V_51 , int * V_4 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_5 V_52 ;
T_6 V_53 ;
T_1 V_44 ;
int V_12 ;
F_13 ( & V_10 -> V_43 ) ;
if ( V_10 -> V_40 == 0 ) {
F_5 ( & V_2 -> V_14 , L_11 ) ;
V_12 = - V_54 ;
goto exit;
}
V_12 = F_1 ( V_2 ,
V_30 ,
V_55 ,
V_32 ,
V_33 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_12 ) ;
goto exit;
}
if ( F_20 ( V_10 -> V_48 ) )
V_12 = F_15 ( V_10 ) ;
else
V_12 = F_18 ( V_10 ) ;
if ( V_12 < 0 )
goto exit;
V_44 = V_12 ;
if ( V_44 & V_56 ) {
V_12 = F_6 ( V_2 , V_57 , 1 , & V_44 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_13 ) ;
goto exit;
}
if ( V_44 & ( V_58 |
V_59 ) ) {
F_5 ( & V_2 -> V_14 , L_14 ,
V_44 ) ;
V_12 = - V_49 ;
goto exit;
}
}
V_12 = F_6 ( V_2 , V_60 [ V_51 ] ,
2 , ( T_1 * ) & V_52 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_15 ) ;
goto exit;
}
F_14 ( & V_10 -> V_43 ) ;
V_53 = ( T_6 ) ( F_21 ( V_52 ) ) ;
V_53 = F_22 ( T_6 , V_53 , - 4096 , 4095 ) ;
* V_4 = V_53 ;
return V_61 ;
exit:
F_14 ( & V_10 -> V_43 ) ;
return V_12 ;
}
static int F_23 ( struct V_7 * V_8 ,
struct V_62 const * V_63 ,
int * V_4 , int * V_64 ,
long V_5 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
switch ( V_5 ) {
case V_65 :
return F_19 ( V_8 , V_63 -> V_66 , V_4 ) ;
case V_67 :
* V_4 = V_10 -> V_36 [ V_63 -> V_66 ] ;
return V_61 ;
}
return - V_49 ;
}
static int F_24 ( struct V_1 * V_2 ,
const struct V_68 * V_69 )
{
struct V_9 * V_10 ;
struct V_7 * V_8 ;
int V_48 ;
int V_70 ;
if ( V_2 -> V_14 . V_71 == NULL )
V_48 = - 1 ;
else
V_48 = * ( int * ) ( V_2 -> V_14 . V_71 ) ;
if ( F_20 ( V_48 ) ) {
V_70 = F_25 ( V_48 , L_16 ) ;
if ( V_70 < 0 ) {
F_5 ( & V_2 -> V_14 ,
L_17 ,
V_48 , V_70 ) ;
goto exit;
}
V_70 = F_26 ( V_48 ) ;
if ( V_70 < 0 ) {
F_5 ( & V_2 -> V_14 ,
L_18 ,
V_48 , V_70 ) ;
goto V_72;
}
}
V_8 = F_27 ( sizeof( * V_10 ) ) ;
if ( V_8 == NULL ) {
V_70 = - V_73 ;
goto V_72;
}
V_10 = F_3 ( V_8 ) ;
F_28 ( V_2 , V_8 ) ;
V_70 = F_8 ( V_2 ) ;
if ( V_70 < 0 ) {
F_5 ( & V_2 -> V_14 , L_19 ) ;
goto V_74;
}
V_10 -> V_2 = V_2 ;
F_29 ( & V_10 -> V_43 ) ;
V_10 -> V_75 = V_2 -> V_76 ;
V_10 -> V_48 = V_48 ;
V_8 -> V_14 . V_77 = & V_2 -> V_14 ;
V_8 -> V_78 = V_79 ;
V_8 -> V_80 = F_30 ( V_79 ) ;
V_8 -> V_81 = & V_82 ;
V_8 -> V_83 = V_84 ;
V_70 = F_31 ( V_8 ) ;
if ( V_70 < 0 )
goto V_74;
return 0 ;
V_74:
F_32 ( V_8 ) ;
V_72:
if ( F_20 ( V_48 ) )
F_33 ( V_48 ) ;
exit:
return V_70 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_35 ( V_8 ) ;
if ( F_20 ( V_10 -> V_48 ) )
F_33 ( V_10 -> V_48 ) ;
F_32 ( V_8 ) ;
return 0 ;
}
