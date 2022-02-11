static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_3 * V_7 = & V_6 -> V_4 ;
if ( ! V_7 )
return - V_8 ;
V_4 -> V_9 = V_10 ;
V_4 -> V_11 = V_7 -> V_11 ;
memcpy ( V_4 -> V_12 , V_7 -> V_12 , sizeof( V_4 -> V_12 ) ) ;
memcpy ( V_4 -> V_13 , V_7 -> V_13 , sizeof( V_4 -> V_13 ) ) ;
memcpy ( V_4 -> V_14 , V_7 -> V_14 , sizeof( V_4 -> V_14 ) ) ;
return 0 ;
}
static int F_3 ( struct V_5 * V_6 , struct V_3 * V_4 )
{
int V_15 ;
int V_16 = 0 ;
int V_17 = 0 ;
for ( V_15 = 0 ; V_15 < V_10 ; V_15 ++ ) {
if ( V_4 -> V_14 [ V_15 ] > V_18 ) {
F_4 ( V_6 , L_1 ,
V_15 , V_4 -> V_14 [ V_15 ] ) ;
return - V_8 ;
}
switch ( V_4 -> V_13 [ V_15 ] ) {
case V_19 :
break;
case V_20 :
V_17 = 1 ;
V_16 += V_4 -> V_12 [ V_15 ] ;
break;
default:
F_4 ( V_6 , L_2 ,
V_15 , V_4 -> V_13 [ V_15 ] ) ;
return - V_21 ;
}
}
if ( V_17 && V_16 != V_22 ) {
F_4 ( V_6 , L_3 ,
V_16 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_5 ( struct V_5 * V_6 ,
struct V_3 * V_4 , T_1 * V_23 )
{
struct V_24 * V_25 = V_6 -> V_25 ;
int V_26 = 0 ;
int V_15 ;
T_2 V_12 [ V_10 ] = { 0 } ;
T_2 V_27 [ V_10 ] = { 0 } ;
V_4 = V_4 ? : & V_6 -> V_4 ;
V_23 = V_23 ? : V_6 -> V_28 ;
for ( V_15 = V_10 - 1 ; V_15 >= 0 ; V_15 -- ) {
switch ( V_4 -> V_13 [ V_15 ] ) {
case V_19 :
V_27 [ V_15 ] = V_26 ++ ;
V_12 [ V_15 ] = V_22 ;
break;
case V_20 :
V_27 [ V_15 ] = V_29 ;
V_12 [ V_15 ] = V_4 -> V_12 [ V_15 ] ? : V_30 ;
break;
}
}
return F_6 ( V_25 -> V_2 , V_6 -> V_31 , V_12 , V_27 ,
V_23 ) ;
}
static int
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_24 * V_25 = V_6 -> V_25 ;
int V_32 ;
V_32 = F_3 ( V_6 , V_4 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_8 ( V_25 -> V_2 , V_6 -> V_31 , V_4 -> V_14 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_5 ( V_6 , V_4 , NULL ) ;
if ( V_32 )
return V_32 ;
memcpy ( & V_6 -> V_4 , V_4 , sizeof( V_6 -> V_4 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_34 -> V_35 = V_10 ;
V_34 -> V_36 = V_6 -> V_37 -> V_38 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_24 * V_25 = V_6 -> V_25 ;
int V_32 ;
F_11 ( V_39 , V_6 , L_4 ,
V_34 -> V_35 ,
V_34 -> V_36 ,
V_34 -> V_40 ,
V_34 -> V_41 ) ;
V_6 -> V_37 -> V_42 = V_6 -> V_37 -> V_43 = ! ! V_34 -> V_36 ;
V_6 -> V_37 -> V_44 = V_6 -> V_37 -> V_38 = V_34 -> V_36 ;
V_32 = F_12 ( V_25 -> V_2 , V_6 -> V_31 ,
V_6 -> V_45 + V_46 ,
V_6 -> V_37 -> V_43 ,
V_6 -> V_37 -> V_38 ,
V_6 -> V_37 -> V_42 ,
V_6 -> V_37 -> V_44 ) ;
if ( V_32 )
F_4 ( V_6 , L_5 ) ;
return V_32 ;
}
static T_3 F_13 ( struct V_1 * V_2 )
{
return V_47 | V_48 ;
}
static T_3 F_14 ( struct V_1 * V_2 , T_3 V_49 )
{
if ( ( V_49 & V_50 ) ||
( V_49 & V_51 ) ||
! ( V_49 & V_48 ) ||
! ( V_49 & V_47 ) )
return 1 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_52 * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_10 ; V_15 ++ )
V_28 -> V_53 [ V_15 ] =
V_6 -> V_28 [ V_15 ] * V_54 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_52 * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_55 [ V_10 ] ;
int V_15 , V_32 ;
for ( V_15 = 0 ; V_15 < V_10 ; V_15 ++ ) {
V_55 [ V_15 ] = F_17 ( V_28 -> V_53 [ V_15 ] +
V_54 - 1 ,
V_54 ) ;
}
V_32 = F_5 ( V_6 , NULL , V_55 ) ;
if ( V_32 )
return V_32 ;
memcpy ( V_6 -> V_28 , V_55 , sizeof( V_6 -> V_28 ) ) ;
return 0 ;
}
