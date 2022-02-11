static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 ;
int V_10 ;
V_9 = ( V_8 -> V_11 [ V_3 ] & ~ V_5 ) | ( V_4 << V_6 ) ;
V_10 = F_3 ( V_2 , V_3 , V_9 ) ;
if ( V_10 < 0 ) {
F_4 ( & V_2 -> V_12 , L_1 , V_10 ) ;
return V_10 ;
}
V_8 -> V_11 [ V_3 ] = V_9 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_13 , T_1 * V_14 )
{
int V_10 ;
struct V_15 V_16 [ 2 ] = {
{
. V_17 = V_2 -> V_17 ,
. V_18 = V_19 ,
. V_20 = 1 ,
. V_21 = & V_3 ,
} , {
. V_17 = V_2 -> V_17 ,
. V_18 = V_22 ,
. V_20 = V_13 ,
. V_21 = V_14 ,
}
} ;
V_10 = F_6 ( V_2 -> V_23 , V_16 , 2 ) ;
if ( V_10 < 0 ) {
F_4 ( & V_2 -> V_12 , L_2 ) ;
return V_10 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_24 ;
int V_10 ;
V_10 = F_5 ( V_2 , V_25 , 1 , & V_24 ) ;
if ( V_10 < 0 ) {
F_4 ( & V_2 -> V_12 , L_3 ) ;
return V_10 ;
}
if ( V_24 != V_26 ) {
F_4 ( & V_2 -> V_12 , L_4 ) ;
return - V_27 ;
}
V_10 = F_1 ( V_2 ,
V_28 ,
V_29 ,
V_30 ,
V_31 ) ;
if ( V_10 < 0 ) {
F_4 ( & V_2 -> V_12 , L_5 ) ;
return V_10 ;
}
V_10 = F_5 ( V_2 , V_32 , 3 , V_8 -> V_33 ) ;
if ( V_10 < 0 ) {
F_4 ( & V_2 -> V_12 , L_6 ) ;
return V_10 ;
}
V_8 -> V_34 [ 0 ] = ( ( V_8 -> V_33 [ 0 ] + 128 ) * 30 ) >> 8 ;
V_8 -> V_34 [ 1 ] = ( ( V_8 -> V_33 [ 1 ] + 128 ) * 30 ) >> 8 ;
V_8 -> V_34 [ 2 ] = ( ( V_8 -> V_33 [ 2 ] + 128 ) * 30 ) >> 8 ;
return 0 ;
}
static T_2 F_8 ( struct V_35 * V_12 , struct V_36 * V_37 ,
char * V_21 )
{
struct V_38 * V_39 = F_9 ( V_12 ) ;
struct V_7 * V_8 = F_10 ( V_39 ) ;
return sprintf ( V_21 , L_7 , V_8 -> V_40 ) ;
}
static T_2 F_11 ( struct V_35 * V_12 , struct V_36 * V_37 ,
const char * V_21 , T_3 V_41 )
{
struct V_38 * V_39 = F_9 ( V_12 ) ;
struct V_7 * V_8 = F_10 ( V_39 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
bool V_42 ;
int V_10 ;
V_10 = F_12 ( V_21 , & V_42 ) ;
if ( V_10 < 0 )
return V_10 ;
F_13 ( & V_8 -> V_43 ) ;
if ( V_8 -> V_40 != V_42 ) {
V_10 = F_1 ( V_2 ,
V_28 ,
( T_1 ) V_42 ,
V_30 ,
V_31 ) ;
if ( V_10 < 0 ) {
F_4 ( & V_2 -> V_12 , L_8 ) ;
F_14 ( & V_8 -> V_43 ) ;
return V_10 ;
}
V_8 -> V_40 = V_42 ;
}
F_14 ( & V_8 -> V_43 ) ;
return V_41 ;
}
static int F_15 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_44 ;
T_4 V_45 = V_46 ;
int V_10 ;
while ( V_45 ) {
F_16 ( V_47 ) ;
if ( F_17 ( V_8 -> V_48 ) )
break;
V_45 -= V_47 ;
}
if ( ! V_45 ) {
F_4 ( & V_2 -> V_12 , L_9 ) ;
return - V_49 ;
}
V_10 = F_5 ( V_2 , V_50 , 1 , & V_44 ) ;
if ( V_10 < 0 ) {
F_4 ( & V_2 -> V_12 , L_10 ) ;
return V_10 ;
}
return V_44 ;
}
static int F_18 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_44 ;
T_4 V_45 = V_46 ;
int V_10 ;
while ( V_45 ) {
F_16 ( V_47 ) ;
V_10 = F_5 ( V_2 , V_50 , 1 , & V_44 ) ;
if ( V_10 < 0 ) {
F_4 ( & V_2 -> V_12 , L_10 ) ;
return V_10 ;
}
if ( V_44 )
break;
V_45 -= V_47 ;
}
if ( ! V_45 ) {
F_4 ( & V_2 -> V_12 , L_9 ) ;
return - V_49 ;
}
return V_44 ;
}
static int F_19 ( struct V_38 * V_39 , int V_51 , int * V_4 )
{
struct V_7 * V_8 = F_10 ( V_39 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
T_5 V_52 ;
T_6 V_53 ;
T_1 V_44 ;
int V_10 ;
F_13 ( & V_8 -> V_43 ) ;
if ( V_8 -> V_40 == 0 ) {
F_4 ( & V_2 -> V_12 , L_11 ) ;
V_10 = - V_54 ;
goto exit;
}
V_10 = F_1 ( V_2 ,
V_28 ,
V_55 ,
V_30 ,
V_31 ) ;
if ( V_10 < 0 ) {
F_4 ( & V_2 -> V_12 , L_12 ) ;
goto exit;
}
if ( F_20 ( V_8 -> V_48 ) )
V_10 = F_15 ( V_8 ) ;
else
V_10 = F_18 ( V_8 ) ;
if ( V_10 < 0 )
goto exit;
V_44 = V_10 ;
if ( V_44 & V_56 ) {
V_10 = F_5 ( V_2 , V_57 , 1 , & V_44 ) ;
if ( V_10 < 0 ) {
F_4 ( & V_2 -> V_12 , L_13 ) ;
goto exit;
}
if ( V_44 & ( V_58 |
V_59 ) ) {
F_4 ( & V_2 -> V_12 , L_14 ,
V_44 ) ;
V_10 = - V_49 ;
goto exit;
}
}
V_10 = F_5 ( V_2 , V_60 [ V_51 ] ,
2 , ( T_1 * ) & V_52 ) ;
if ( V_10 < 0 ) {
F_4 ( & V_2 -> V_12 , L_15 ) ;
goto exit;
}
F_14 ( & V_8 -> V_43 ) ;
V_53 = ( T_6 ) ( F_21 ( V_52 ) ) ;
V_53 = F_22 ( T_6 , V_53 , - 4096 , 4095 ) ;
* V_4 = V_53 ;
return V_61 ;
exit:
F_14 ( & V_8 -> V_43 ) ;
return V_10 ;
}
static int F_23 ( struct V_38 * V_39 ,
struct V_62 const * V_63 ,
int * V_4 , int * V_64 ,
long V_5 )
{
struct V_7 * V_8 = F_10 ( V_39 ) ;
switch ( V_5 ) {
case 0 :
return F_19 ( V_39 , V_63 -> V_65 , V_4 ) ;
case V_66 :
* V_4 = V_8 -> V_34 [ V_63 -> V_65 ] ;
return V_61 ;
}
return - V_49 ;
}
static int F_24 ( struct V_1 * V_2 ,
const struct V_67 * V_68 )
{
struct V_7 * V_8 ;
struct V_38 * V_39 ;
int V_48 ;
int V_69 ;
if ( V_2 -> V_12 . V_70 == NULL )
V_48 = - 1 ;
else
V_48 = * ( int * ) ( V_2 -> V_12 . V_70 ) ;
if ( F_20 ( V_48 ) ) {
V_69 = F_25 ( V_48 , L_16 ) ;
if ( V_69 < 0 ) {
F_4 ( & V_2 -> V_12 ,
L_17 ,
V_48 , V_69 ) ;
goto exit;
}
V_69 = F_26 ( V_48 ) ;
if ( V_69 < 0 ) {
F_4 ( & V_2 -> V_12 ,
L_18 ,
V_48 , V_69 ) ;
goto V_71;
}
}
V_39 = F_27 ( sizeof( * V_8 ) ) ;
if ( V_39 == NULL ) {
V_69 = - V_72 ;
goto V_71;
}
V_8 = F_10 ( V_39 ) ;
V_69 = F_7 ( V_2 ) ;
if ( V_69 < 0 ) {
F_4 ( & V_2 -> V_12 , L_19 ) ;
goto V_73;
}
F_28 ( V_2 , V_39 ) ;
V_8 -> V_2 = V_2 ;
F_29 ( & V_8 -> V_43 ) ;
V_8 -> V_74 = V_2 -> V_75 ;
V_8 -> V_48 = V_48 ;
V_39 -> V_12 . V_76 = & V_2 -> V_12 ;
V_39 -> V_77 = V_78 ;
V_39 -> V_79 = F_30 ( V_78 ) ;
V_39 -> V_80 = & V_81 ;
V_39 -> V_82 = V_83 ;
V_69 = F_31 ( V_39 ) ;
if ( V_69 < 0 )
goto V_73;
return 0 ;
V_73:
F_32 ( V_39 ) ;
V_71:
if ( F_20 ( V_48 ) )
F_33 ( V_48 ) ;
exit:
return V_69 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_10 ( V_39 ) ;
F_35 ( V_39 ) ;
if ( F_20 ( V_8 -> V_48 ) )
F_33 ( V_8 -> V_48 ) ;
F_32 ( V_39 ) ;
return 0 ;
}
