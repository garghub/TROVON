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
static T_2 F_6 ( int V_15 , void * V_10 )
{
struct V_9 * V_16 = V_10 ;
F_7 ( 0 , & V_16 -> V_17 ) ;
F_8 ( & V_16 -> V_18 ) ;
return V_19 ;
}
static int F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_20 ;
int V_15 ;
if ( V_2 -> V_15 )
V_15 = V_2 -> V_15 ;
else
V_15 = F_10 ( V_10 -> V_21 ) ;
V_20 = F_11 ( V_15 , F_6 ,
V_22 | V_23 ,
F_12 ( & V_2 -> V_14 ) , V_10 ) ;
if ( V_20 < 0 ) {
F_5 ( & V_2 -> V_14 ,
L_2 ,
V_15 , V_10 -> V_21 , V_20 ) ;
return V_20 ;
}
F_13 ( & V_10 -> V_18 ) ;
F_14 ( 0 , & V_10 -> V_17 ) ;
V_10 -> V_24 = V_15 ;
return V_20 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
T_1 V_25 ;
int V_12 ;
V_12 = F_16 ( V_2 , V_26 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_3 ) ;
return V_12 ;
}
V_25 = V_12 ;
if ( V_25 != V_27 ) {
F_5 ( & V_2 -> V_14 , L_4 ) ;
return - V_28 ;
}
V_12 = F_1 ( V_2 ,
V_29 ,
V_30 ,
V_31 ,
V_32 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_5 ) ;
return V_12 ;
}
V_12 = F_17 ( V_2 , V_33 ,
3 , V_10 -> V_34 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_6 ) ;
return V_12 ;
}
V_12 = F_1 ( V_2 ,
V_29 ,
V_35 ,
V_31 ,
V_32 ) ;
if ( V_10 -> V_21 > 0 || V_2 -> V_15 ) {
V_12 = F_9 ( V_10 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 ,
L_7 ) ;
return V_12 ;
}
}
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_8 ) ;
return V_12 ;
}
V_10 -> V_36 [ 0 ] = ( ( V_10 -> V_34 [ 0 ] + 128 ) * 30 ) >> 8 ;
V_10 -> V_36 [ 1 ] = ( ( V_10 -> V_34 [ 1 ] + 128 ) * 30 ) >> 8 ;
V_10 -> V_36 [ 2 ] = ( ( V_10 -> V_34 [ 2 ] + 128 ) * 30 ) >> 8 ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_3 V_37 = V_38 ;
int V_12 ;
while ( V_37 ) {
F_19 ( V_39 ) ;
if ( F_20 ( V_10 -> V_21 ) )
break;
V_37 -= V_39 ;
}
if ( ! V_37 ) {
F_5 ( & V_2 -> V_14 , L_9 ) ;
return - V_40 ;
}
V_12 = F_16 ( V_2 , V_41 ) ;
if ( V_12 < 0 )
F_5 ( & V_2 -> V_14 , L_10 ) ;
return V_12 ;
}
static int F_21 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_42 ;
T_3 V_37 = V_38 ;
int V_12 ;
while ( V_37 ) {
F_19 ( V_39 ) ;
V_12 = F_16 ( V_2 , V_41 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_10 ) ;
return V_12 ;
}
V_42 = V_12 ;
if ( V_42 )
break;
V_37 -= V_39 ;
}
if ( ! V_37 ) {
F_5 ( & V_2 -> V_14 , L_9 ) ;
return - V_40 ;
}
return V_42 ;
}
static int F_22 ( struct V_9 * V_10 )
{
int V_12 ;
V_12 = F_23 ( V_10 -> V_18 ,
F_24 ( 0 , & V_10 -> V_17 ) ,
V_43 ) ;
F_14 ( 0 , & V_10 -> V_17 ) ;
return V_12 > 0 ? 0 : - V_44 ;
}
static int F_25 ( struct V_7 * V_8 , int V_45 , int * V_4 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_4 V_46 ;
T_5 V_47 ;
int V_12 ;
F_26 ( & V_10 -> V_48 ) ;
V_12 = F_1 ( V_2 ,
V_29 ,
V_49 ,
V_31 ,
V_32 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_11 ) ;
goto exit;
}
if ( V_10 -> V_24 )
V_12 = F_22 ( V_10 ) ;
else if ( F_27 ( V_10 -> V_21 ) )
V_12 = F_18 ( V_10 ) ;
else
V_12 = F_21 ( V_10 ) ;
if ( V_12 < 0 )
goto exit;
if ( V_12 & V_50 ) {
V_12 = F_16 ( V_2 , V_51 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_12 ) ;
goto exit;
}
if ( V_12 & ( V_52 |
V_53 ) ) {
F_5 ( & V_2 -> V_14 , L_13 , V_12 ) ;
V_12 = - V_40 ;
goto exit;
}
}
V_12 = F_28 ( V_2 , V_54 [ V_45 ] ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_14 ) ;
goto exit;
}
V_46 = V_12 ;
F_29 ( & V_10 -> V_48 ) ;
V_47 = ( T_5 ) ( F_30 ( V_46 ) ) ;
V_47 = F_31 ( T_5 , V_47 , - 4096 , 4095 ) ;
* V_4 = V_47 ;
return V_55 ;
exit:
F_29 ( & V_10 -> V_48 ) ;
return V_12 ;
}
static int F_32 ( struct V_7 * V_8 ,
struct V_56 const * V_57 ,
int * V_4 , int * V_58 ,
long V_5 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
switch ( V_5 ) {
case V_59 :
return F_25 ( V_8 , V_57 -> V_60 , V_4 ) ;
case V_61 :
* V_4 = V_10 -> V_36 [ V_57 -> V_60 ] ;
return V_55 ;
}
return - V_40 ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
struct V_9 * V_10 ;
struct V_7 * V_8 ;
int V_21 ;
int V_64 ;
if ( V_2 -> V_14 . V_65 )
V_21 = * ( int * ) ( V_2 -> V_14 . V_65 ) ;
else if ( V_2 -> V_14 . V_66 )
V_21 = F_34 ( V_2 -> V_14 . V_66 , 0 ) ;
else
V_21 = - 1 ;
if ( V_21 == - V_67 )
return - V_67 ;
if ( F_27 ( V_21 ) ) {
V_64 = F_35 ( V_21 , V_68 , L_15 ) ;
if ( V_64 < 0 ) {
F_5 ( & V_2 -> V_14 ,
L_16 ,
V_21 , V_64 ) ;
goto exit;
}
}
V_8 = F_36 ( sizeof( * V_10 ) ) ;
if ( V_8 == NULL ) {
V_64 = - V_69 ;
goto V_70;
}
V_10 = F_3 ( V_8 ) ;
F_37 ( V_2 , V_8 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_21 = V_21 ;
V_10 -> V_24 = 0 ;
V_64 = F_15 ( V_2 ) ;
if ( V_64 < 0 ) {
F_5 ( & V_2 -> V_14 , L_17 ) ;
goto V_71;
}
V_10 -> V_2 = V_2 ;
F_38 ( & V_10 -> V_48 ) ;
V_10 -> V_21 = V_21 ;
V_8 -> V_14 . V_72 = & V_2 -> V_14 ;
V_8 -> V_73 = V_74 ;
V_8 -> V_75 = F_39 ( V_74 ) ;
V_8 -> V_76 = & V_77 ;
V_8 -> V_78 = V_79 ;
V_64 = F_40 ( V_8 ) ;
if ( V_64 < 0 )
goto V_71;
return 0 ;
V_71:
F_41 ( V_8 ) ;
if ( V_10 -> V_24 )
F_42 ( V_10 -> V_24 , V_10 ) ;
V_70:
if ( F_27 ( V_21 ) )
F_43 ( V_21 ) ;
exit:
return V_64 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_45 ( V_8 ) ;
if ( V_10 -> V_24 )
F_42 ( V_10 -> V_24 , V_10 ) ;
if ( F_27 ( V_10 -> V_21 ) )
F_43 ( V_10 -> V_21 ) ;
F_41 ( V_8 ) ;
return 0 ;
}
