static inline int F_1 ( int V_1 )
{
int V_2 = - V_3 ;
switch ( V_1 ) {
case V_4 :
case V_5 :
case V_6 :
V_2 = V_1 - V_4 + V_7 ;
break;
case V_8 :
case V_9 :
case V_10 :
V_2 = V_1 - V_8 + V_11 ;
break;
}
return V_2 ;
}
static inline int F_2 ( int V_1 )
{
int V_2 = - V_3 ;
switch ( V_1 ) {
case V_4 :
case V_5 :
case V_6 :
V_2 = V_12 ;
break;
case V_8 :
case V_9 :
case V_10 :
V_2 = V_13 ;
break;
}
return V_2 ;
}
static inline int F_3 ( int V_1 )
{
int V_2 = - V_3 ;
switch ( V_1 ) {
case V_4 :
case V_5 :
case V_6 :
V_2 = V_14 ;
break;
case V_8 :
case V_9 :
case V_10 :
V_2 = V_15 ;
break;
}
return V_2 ;
}
static int F_4 ( struct V_16 * V_17 , int V_1 , int V_18 )
{
int V_2 = - V_3 ;
switch ( V_1 ) {
case V_4 :
case V_5 :
case V_6 :
V_2 = V_18 ? F_5 ( V_17 , V_19 ) :
F_6 ( V_17 , V_19 ) ;
break;
case V_8 :
case V_9 :
case V_10 :
V_2 = V_18 ? F_5 ( V_17 , V_20 ) :
F_6 ( V_17 , V_20 ) ;
break;
}
return V_2 ;
}
static void F_7 ( struct V_21 * V_22 )
{
struct V_23 * V_24 ;
struct V_16 * V_17 ;
unsigned char V_25 [ 3 ] ;
int V_26 , V_2 ;
V_24 = F_8 ( V_22 , struct V_23 , V_22 ) ;
V_17 = V_24 -> V_17 ;
F_9 ( & V_24 -> V_27 ) ;
if ( ( V_24 -> V_28 == 0 ) && V_24 -> V_29 ) {
F_4 ( V_17 , V_24 -> V_1 , 1 ) ;
if ( V_24 -> V_30 ) {
F_10 ( V_24 -> V_31 , F_1 ( V_24 -> V_1 ) ,
V_32 , V_24 -> V_30 ) ;
}
F_10 ( V_24 -> V_31 , F_2 ( V_24 -> V_1 ) ,
V_33 , V_34 ) ;
V_26 = F_3 ( V_24 -> V_1 ) ;
F_10 ( V_24 -> V_31 , V_35 , V_26 , V_26 ) ;
}
F_10 ( V_24 -> V_31 , F_1 ( V_24 -> V_1 ) , V_36 ,
V_24 -> V_29 ) ;
if ( V_24 -> V_29 == 0 ) {
F_11 ( V_24 -> V_31 , F_1 ( V_24 -> V_1 ) , 3 , V_25 ) ;
V_2 = V_25 [ 0 ] & V_36 ;
V_2 |= V_25 [ 1 ] & V_36 ;
V_2 |= V_25 [ 2 ] & V_36 ;
if ( V_2 == 0 ) {
F_10 ( V_24 -> V_31 , F_1 ( V_24 -> V_1 ) ,
V_32 , 0 ) ;
V_26 = F_3 ( V_24 -> V_1 ) ;
F_10 ( V_24 -> V_31 , V_35 , V_26 , 0 ) ;
F_4 ( V_17 , V_24 -> V_1 , 0 ) ;
}
}
V_24 -> V_28 = V_24 -> V_29 ;
F_12 ( V_17 -> V_37 , L_1 ,
F_1 ( V_24 -> V_1 ) , V_24 -> V_29 ) ;
F_13 ( & V_24 -> V_27 ) ;
}
static void F_14 ( struct V_38 * V_39 ,
enum V_40 V_41 )
{
struct V_23 * V_42 = F_8 ( V_39 , struct V_23 , V_39 ) ;
V_42 -> V_29 = V_41 >> 3 ;
F_15 ( & V_42 -> V_22 ) ;
}
static int F_16 ( struct V_43 * V_44 )
{
struct V_16 * V_17 = F_17 ( V_44 -> V_37 . V_45 ) ;
struct V_46 * V_47 ;
struct V_23 * V_42 ;
struct V_48 * V_49 ;
int V_2 ;
V_49 = F_18 ( V_44 , V_50 , 0 ) ;
if ( V_49 == NULL ) {
F_19 ( & V_44 -> V_37 , L_2 ) ;
return - V_3 ;
}
V_47 = V_44 -> V_37 . V_51 ;
if ( V_47 == NULL ) {
F_19 ( & V_44 -> V_37 , L_3 ) ;
return - V_3 ;
}
V_42 = F_20 ( & V_44 -> V_37 , sizeof( struct V_23 ) , V_52 ) ;
if ( V_42 == NULL )
return - V_53 ;
strncpy ( V_42 -> V_54 , V_49 -> V_54 , V_55 - 1 ) ;
F_21 ( & V_44 -> V_37 , V_42 ) ;
V_42 -> V_17 = V_17 ;
V_42 -> V_31 = ( V_17 -> V_56 == V_57 ) ? V_17 -> V_58 : V_17 -> V_59 ;
V_42 -> V_30 = V_47 -> V_30 ;
V_42 -> V_1 = V_47 -> V_60 ;
if ( V_42 -> V_1 < 0 ) {
F_19 ( & V_44 -> V_37 , L_4 ) ;
return - V_3 ;
}
V_42 -> V_28 = 0 ;
V_42 -> V_39 . V_54 = V_42 -> V_54 ;
V_42 -> V_39 . V_61 = F_14 ;
F_22 ( & V_42 -> V_27 ) ;
F_23 ( & V_42 -> V_22 , F_7 ) ;
V_2 = F_24 ( V_17 -> V_37 , & V_42 -> V_39 ) ;
if ( V_2 < 0 ) {
F_19 ( & V_44 -> V_37 , L_5 , V_2 ) ;
return V_2 ;
}
F_14 ( & V_42 -> V_39 , 0 ) ;
return 0 ;
}
static int F_25 ( struct V_43 * V_44 )
{
struct V_23 * V_42 = F_26 ( V_44 ) ;
F_27 ( & V_42 -> V_39 ) ;
return 0 ;
}
