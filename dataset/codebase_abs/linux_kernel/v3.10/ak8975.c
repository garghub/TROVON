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
static int F_6 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
T_1 V_15 ;
int V_12 ;
V_12 = F_7 ( V_2 , V_16 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_2 ) ;
return V_12 ;
}
V_15 = V_12 ;
if ( V_15 != V_17 ) {
F_5 ( & V_2 -> V_14 , L_3 ) ;
return - V_18 ;
}
V_12 = F_1 ( V_2 ,
V_19 ,
V_20 ,
V_21 ,
V_22 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_4 ) ;
return V_12 ;
}
V_12 = F_8 ( V_2 , V_23 ,
3 , V_10 -> V_24 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_5 ) ;
return V_12 ;
}
V_12 = F_1 ( V_2 ,
V_19 ,
V_25 ,
V_21 ,
V_22 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_6 ) ;
return V_12 ;
}
V_10 -> V_26 [ 0 ] = ( ( V_10 -> V_24 [ 0 ] + 128 ) * 30 ) >> 8 ;
V_10 -> V_26 [ 1 ] = ( ( V_10 -> V_24 [ 1 ] + 128 ) * 30 ) >> 8 ;
V_10 -> V_26 [ 2 ] = ( ( V_10 -> V_24 [ 2 ] + 128 ) * 30 ) >> 8 ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_2 V_27 = V_28 ;
int V_12 ;
while ( V_27 ) {
F_10 ( V_29 ) ;
if ( F_11 ( V_10 -> V_30 ) )
break;
V_27 -= V_29 ;
}
if ( ! V_27 ) {
F_5 ( & V_2 -> V_14 , L_7 ) ;
return - V_31 ;
}
V_12 = F_7 ( V_2 , V_32 ) ;
if ( V_12 < 0 )
F_5 ( & V_2 -> V_14 , L_8 ) ;
return V_12 ;
}
static int F_12 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_33 ;
T_2 V_27 = V_28 ;
int V_12 ;
while ( V_27 ) {
F_10 ( V_29 ) ;
V_12 = F_7 ( V_2 , V_32 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_8 ) ;
return V_12 ;
}
V_33 = V_12 ;
if ( V_33 )
break;
V_27 -= V_29 ;
}
if ( ! V_27 ) {
F_5 ( & V_2 -> V_14 , L_7 ) ;
return - V_31 ;
}
return V_33 ;
}
static int F_13 ( struct V_7 * V_8 , int V_34 , int * V_4 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_3 V_35 ;
T_4 V_36 ;
int V_12 ;
F_14 ( & V_10 -> V_37 ) ;
V_12 = F_1 ( V_2 ,
V_19 ,
V_38 ,
V_21 ,
V_22 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_9 ) ;
goto exit;
}
if ( F_15 ( V_10 -> V_30 ) )
V_12 = F_9 ( V_10 ) ;
else
V_12 = F_12 ( V_10 ) ;
if ( V_12 < 0 )
goto exit;
if ( V_12 & V_39 ) {
V_12 = F_7 ( V_2 , V_40 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_10 ) ;
goto exit;
}
if ( V_12 & ( V_41 |
V_42 ) ) {
F_5 ( & V_2 -> V_14 , L_11 , V_12 ) ;
V_12 = - V_31 ;
goto exit;
}
}
V_12 = F_16 ( V_2 , V_43 [ V_34 ] ) ;
if ( V_12 < 0 ) {
F_5 ( & V_2 -> V_14 , L_12 ) ;
goto exit;
}
V_35 = V_12 ;
F_17 ( & V_10 -> V_37 ) ;
V_36 = ( T_4 ) ( F_18 ( V_35 ) ) ;
V_36 = F_19 ( T_4 , V_36 , - 4096 , 4095 ) ;
* V_4 = V_36 ;
return V_44 ;
exit:
F_17 ( & V_10 -> V_37 ) ;
return V_12 ;
}
static int F_20 ( struct V_7 * V_8 ,
struct V_45 const * V_46 ,
int * V_4 , int * V_47 ,
long V_5 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
switch ( V_5 ) {
case V_48 :
return F_13 ( V_8 , V_46 -> V_49 , V_4 ) ;
case V_50 :
* V_4 = V_10 -> V_26 [ V_46 -> V_49 ] ;
return V_44 ;
}
return - V_31 ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_51 * V_52 )
{
struct V_9 * V_10 ;
struct V_7 * V_8 ;
int V_30 ;
int V_53 ;
if ( V_2 -> V_14 . V_54 == NULL )
V_30 = - 1 ;
else
V_30 = * ( int * ) ( V_2 -> V_14 . V_54 ) ;
if ( F_15 ( V_30 ) ) {
V_53 = F_22 ( V_30 , V_55 , L_13 ) ;
if ( V_53 < 0 ) {
F_5 ( & V_2 -> V_14 ,
L_14 ,
V_30 , V_53 ) ;
goto exit;
}
}
V_8 = F_23 ( sizeof( * V_10 ) ) ;
if ( V_8 == NULL ) {
V_53 = - V_56 ;
goto V_57;
}
V_10 = F_3 ( V_8 ) ;
F_24 ( V_2 , V_8 ) ;
V_53 = F_6 ( V_2 ) ;
if ( V_53 < 0 ) {
F_5 ( & V_2 -> V_14 , L_15 ) ;
goto V_58;
}
V_10 -> V_2 = V_2 ;
F_25 ( & V_10 -> V_37 ) ;
V_10 -> V_30 = V_30 ;
V_8 -> V_14 . V_59 = & V_2 -> V_14 ;
V_8 -> V_60 = V_61 ;
V_8 -> V_62 = F_26 ( V_61 ) ;
V_8 -> V_63 = & V_64 ;
V_8 -> V_65 = V_66 ;
V_53 = F_27 ( V_8 ) ;
if ( V_53 < 0 )
goto V_58;
return 0 ;
V_58:
F_28 ( V_8 ) ;
V_57:
if ( F_15 ( V_30 ) )
F_29 ( V_30 ) ;
exit:
return V_53 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_31 ( V_8 ) ;
if ( F_15 ( V_10 -> V_30 ) )
F_29 ( V_10 -> V_30 ) ;
F_28 ( V_8 ) ;
return 0 ;
}
