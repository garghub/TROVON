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
F_20 ( & V_32 -> V_37 ) ;
if ( F_21 ( V_32 ) && V_36 == V_38 ) {
V_10 = - V_39 ;
goto V_40;
}
switch ( V_36 ) {
case V_38 : {
T_2 V_3 ;
V_10 = F_13 ( V_2 , & V_3 ) ;
if ( ! V_10 ) {
* V_4 = V_3 ;
V_10 = V_41 ;
}
break;
}
case V_42 :
* V_4 = 0 ;
* V_35 = 10000 ;
V_10 = V_43 ;
break;
}
V_40:
F_22 ( & V_32 -> V_37 ) ;
return V_10 ;
}
static T_3 F_23 ( int V_44 , void * V_45 )
{
struct V_46 * V_47 = V_45 ;
struct V_31 * V_32 = V_47 -> V_32 ;
struct V_1 * V_2 = F_19 ( V_32 ) ;
int V_10 ;
V_10 = F_13 ( V_2 , V_2 -> V_48 ) ;
if ( ! V_10 ) {
F_24 ( V_32 , V_2 -> V_48 ,
F_25 () ) ;
} else if ( V_10 != - V_29 ) {
F_5 ( & V_2 -> V_7 -> V_18 , L_4 ) ;
}
F_26 ( V_32 -> V_49 ) ;
return V_50 ;
}
static int F_27 ( struct V_6 * V_7 ,
const struct V_51 * V_52 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
int V_10 ;
V_32 = F_28 ( & V_7 -> V_18 , sizeof( * V_2 ) ) ;
if ( ! V_32 )
return - V_53 ;
V_2 = F_19 ( V_32 ) ;
if ( F_29 ( V_7 -> V_16 , V_54 ) ) {
V_2 -> V_19 = F_1 ;
V_2 -> V_23 = 1 ;
} else if ( F_29 ( V_7 -> V_16 ,
V_55 | V_56 ) )
V_2 -> V_19 = F_3 ;
else
return - V_57 ;
V_32 -> V_58 = & V_59 ;
V_32 -> V_60 = V_61 ;
V_32 -> V_62 = V_63 ;
V_32 -> V_64 = F_30 ( V_63 ) ;
V_32 -> V_65 = V_66 ;
F_31 ( V_7 , V_32 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_32 = V_32 ;
V_10 = F_32 ( V_32 , NULL ,
F_23 , NULL ) ;
if ( V_10 )
return V_10 ;
V_10 = F_33 ( V_32 ) ;
if ( V_10 )
goto V_67;
F_34 ( & V_7 -> V_18 , 1000 ) ;
F_35 ( & V_7 -> V_18 ) ;
V_10 = F_36 ( & V_7 -> V_18 ) ;
if ( V_10 )
goto V_67;
F_37 ( & V_7 -> V_18 ) ;
F_16 ( & V_7 -> V_18 ) ;
F_38 ( & V_7 -> V_18 ) ;
return 0 ;
V_67:
F_39 ( V_32 ) ;
return V_10 ;
}
static int F_40 ( struct V_6 * V_7 )
{
struct V_31 * V_32 = F_41 ( V_7 ) ;
F_42 ( V_32 ) ;
F_39 ( V_32 ) ;
F_43 ( & V_7 -> V_18 ) ;
F_44 ( & V_7 -> V_18 ) ;
return 0 ;
}
static int F_45 ( struct V_68 * V_18 )
{
struct V_31 * V_32 = F_41 ( F_46 ( V_18 ) ) ;
struct V_1 * V_2 = F_19 ( V_32 ) ;
return F_10 ( V_2 , 0x0f ) ;
}
static int F_47 ( struct V_68 * V_18 )
{
struct V_31 * V_32 = F_41 ( F_46 ( V_18 ) ) ;
struct V_1 * V_2 = F_19 ( V_32 ) ;
int V_10 = F_10 ( V_2 , 0 ) ;
F_15 ( 15000 , 20000 ) ;
return V_10 ;
}
