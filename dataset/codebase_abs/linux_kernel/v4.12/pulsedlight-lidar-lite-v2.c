static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 V_9 [ 2 ] ;
int V_10 ;
V_9 [ 0 ] . V_11 = V_7 -> V_11 ;
V_9 [ 0 ] . V_12 = V_7 -> V_12 | V_13 ;
V_9 [ 0 ] . V_5 = 1 ;
V_9 [ 0 ] . V_14 = ( char * ) & V_3 ;
V_9 [ 1 ] . V_11 = V_7 -> V_11 ;
V_9 [ 1 ] . V_12 = V_7 -> V_12 | V_15 ;
V_9 [ 1 ] . V_5 = V_5 ;
V_9 [ 1 ] . V_14 = ( char * ) V_4 ;
V_10 = F_2 ( V_7 -> V_16 , V_9 , 2 ) ;
return ( V_10 == 2 ) ? 0 : - V_17 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_10 ;
while ( V_5 -- ) {
V_10 = F_4 ( V_7 , V_3 ++ ) ;
if ( V_10 < 0 ) {
F_5 ( & V_7 -> V_18 , L_1 ) ;
return V_10 ;
}
V_10 = F_6 ( V_7 ) ;
if ( V_10 < 0 ) {
F_5 ( & V_7 -> V_18 , L_2 ) ;
return V_10 ;
}
* ( V_4 ++ ) = V_10 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_10 ;
T_1 V_4 ;
V_10 = V_2 -> V_19 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_4 ;
}
static inline int F_8 ( struct V_1 * V_2 , int V_4 )
{
return F_9 ( V_2 -> V_7 , V_20 , V_4 ) ;
}
static inline int F_10 ( struct V_1 * V_2 , int V_4 )
{
return F_9 ( V_2 -> V_7 ,
V_21 , V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_2 * V_3 )
{
int V_10 = V_2 -> V_19 ( V_2 , V_22 |
( V_2 -> V_23 ? V_24 : 0 ) ,
( T_1 * ) V_3 , 2 ) ;
if ( ! V_10 )
* V_3 = F_12 ( * V_3 ) ;
return V_10 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 * V_3 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_25 = 10 ;
int V_10 ;
F_14 ( & V_7 -> V_18 ) ;
V_10 = F_8 ( V_2 , V_26 ) ;
if ( V_10 < 0 ) {
F_5 ( & V_7 -> V_18 , L_3 ) ;
return V_10 ;
}
while ( V_25 -- ) {
F_15 ( 1000 , 2000 ) ;
V_10 = F_7 ( V_2 , V_27 ) ;
if ( V_10 < 0 )
break;
if ( V_10 & V_28 ) {
* V_3 = 0 ;
V_10 = - V_29 ;
break;
}
if ( ! ( V_10 & V_30 ) ) {
V_10 = F_11 ( V_2 , V_3 ) ;
break;
}
V_10 = - V_17 ;
}
F_16 ( & V_7 -> V_18 ) ;
F_17 ( & V_7 -> V_18 ) ;
return V_10 ;
}
static int F_18 ( struct V_31 * V_32 ,
struct V_33 const * V_34 ,
int * V_4 , int * V_35 , long V_36 )
{
struct V_1 * V_2 = F_19 ( V_32 ) ;
int V_10 = - V_29 ;
switch ( V_36 ) {
case V_37 : {
T_2 V_3 ;
if ( F_20 ( V_32 ) )
return - V_38 ;
V_10 = F_13 ( V_2 , & V_3 ) ;
if ( ! V_10 ) {
* V_4 = V_3 ;
V_10 = V_39 ;
}
F_21 ( V_32 ) ;
break;
}
case V_40 :
* V_4 = 0 ;
* V_35 = 10000 ;
V_10 = V_41 ;
break;
}
return V_10 ;
}
static T_3 F_22 ( int V_42 , void * V_43 )
{
struct V_44 * V_45 = V_43 ;
struct V_31 * V_32 = V_45 -> V_32 ;
struct V_1 * V_2 = F_19 ( V_32 ) ;
int V_10 ;
V_10 = F_13 ( V_2 , V_2 -> V_46 ) ;
if ( ! V_10 ) {
F_23 ( V_32 , V_2 -> V_46 ,
F_24 ( V_32 ) ) ;
} else if ( V_10 != - V_29 ) {
F_5 ( & V_2 -> V_7 -> V_18 , L_4 ) ;
}
F_25 ( V_32 -> V_47 ) ;
return V_48 ;
}
static int F_26 ( struct V_6 * V_7 ,
const struct V_49 * V_50 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
int V_10 ;
V_32 = F_27 ( & V_7 -> V_18 , sizeof( * V_2 ) ) ;
if ( ! V_32 )
return - V_51 ;
V_2 = F_19 ( V_32 ) ;
if ( F_28 ( V_7 -> V_16 , V_52 ) ) {
V_2 -> V_19 = F_1 ;
V_2 -> V_23 = 1 ;
} else if ( F_28 ( V_7 -> V_16 ,
V_53 | V_54 ) )
V_2 -> V_19 = F_3 ;
else
return - V_55 ;
V_32 -> V_56 = & V_57 ;
V_32 -> V_58 = V_59 ;
V_32 -> V_60 = V_61 ;
V_32 -> V_62 = F_29 ( V_61 ) ;
V_32 -> V_18 . V_63 = & V_7 -> V_18 ;
V_32 -> V_64 = V_65 ;
F_30 ( V_7 , V_32 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_32 = V_32 ;
V_10 = F_31 ( V_32 , NULL ,
F_22 , NULL ) ;
if ( V_10 )
return V_10 ;
V_10 = F_32 ( V_32 ) ;
if ( V_10 )
goto V_66;
F_33 ( & V_7 -> V_18 , 1000 ) ;
F_34 ( & V_7 -> V_18 ) ;
V_10 = F_35 ( & V_7 -> V_18 ) ;
if ( V_10 )
goto V_66;
F_36 ( & V_7 -> V_18 ) ;
F_37 ( & V_7 -> V_18 ) ;
return 0 ;
V_66:
F_38 ( V_32 ) ;
return V_10 ;
}
static int F_39 ( struct V_6 * V_7 )
{
struct V_31 * V_32 = F_40 ( V_7 ) ;
F_41 ( V_32 ) ;
F_38 ( V_32 ) ;
F_42 ( & V_7 -> V_18 ) ;
F_43 ( & V_7 -> V_18 ) ;
return 0 ;
}
static int F_44 ( struct V_67 * V_18 )
{
struct V_31 * V_32 = F_40 ( F_45 ( V_18 ) ) ;
struct V_1 * V_2 = F_19 ( V_32 ) ;
return F_10 ( V_2 , 0x0f ) ;
}
static int F_46 ( struct V_67 * V_18 )
{
struct V_31 * V_32 = F_40 ( F_45 ( V_18 ) ) ;
struct V_1 * V_2 = F_19 ( V_32 ) ;
int V_10 = F_10 ( V_2 , 0 ) ;
F_15 ( 15000 , 20000 ) ;
return V_10 ;
}
