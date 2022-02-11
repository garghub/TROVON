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
static void F_4 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
unsigned char V_22 [ 3 ] ;
int V_23 , V_2 ;
V_19 = F_5 ( V_17 , struct V_18 , V_17 ) ;
V_21 = V_19 -> V_21 ;
F_6 ( & V_19 -> V_24 ) ;
if ( ( V_19 -> V_25 == 0 ) && V_19 -> V_26 ) {
if ( V_19 -> V_27 ) {
F_7 ( V_19 -> V_28 , F_1 ( V_19 -> V_1 ) ,
V_29 , V_19 -> V_27 ) ;
}
F_7 ( V_19 -> V_28 , F_2 ( V_19 -> V_1 ) ,
V_30 , V_31 ) ;
V_23 = F_3 ( V_19 -> V_1 ) ;
F_7 ( V_19 -> V_28 , V_32 , V_23 , V_23 ) ;
}
F_7 ( V_19 -> V_28 , F_1 ( V_19 -> V_1 ) , V_33 ,
V_19 -> V_26 ) ;
if ( V_19 -> V_26 == 0 ) {
F_8 ( V_19 -> V_28 , F_1 ( V_19 -> V_1 ) , 3 , V_22 ) ;
V_2 = V_22 [ 0 ] & V_33 ;
V_2 |= V_22 [ 1 ] & V_33 ;
V_2 |= V_22 [ 2 ] & V_33 ;
if ( V_2 == 0 ) {
F_7 ( V_19 -> V_28 , F_1 ( V_19 -> V_1 ) ,
V_29 , 0 ) ;
V_23 = F_3 ( V_19 -> V_1 ) ;
F_7 ( V_19 -> V_28 , V_32 , V_23 , 0 ) ;
}
}
V_19 -> V_25 = V_19 -> V_26 ;
F_9 ( V_21 -> V_34 , L_1 ,
F_1 ( V_19 -> V_1 ) , V_19 -> V_26 ) ;
F_10 ( & V_19 -> V_24 ) ;
}
static void F_11 ( struct V_35 * V_36 ,
enum V_37 V_38 )
{
struct V_18 * V_39 = F_5 ( V_36 , struct V_18 , V_36 ) ;
V_39 -> V_26 = V_38 >> 3 ;
F_12 ( & V_39 -> V_17 ) ;
}
static int F_13 ( struct V_40 * V_41 )
{
struct V_20 * V_21 = F_14 ( V_41 -> V_34 . V_42 ) ;
struct V_43 * V_44 ;
struct V_18 * V_39 ;
struct V_45 * V_46 ;
int V_2 ;
V_46 = F_15 ( V_41 , V_47 , 0 ) ;
if ( V_46 == NULL ) {
F_16 ( & V_41 -> V_34 , L_2 ) ;
return - V_3 ;
}
V_44 = V_41 -> V_34 . V_48 ;
if ( V_44 == NULL ) {
F_16 ( & V_41 -> V_34 , L_3 ) ;
return - V_3 ;
}
V_39 = F_17 ( sizeof( struct V_18 ) , V_49 ) ;
if ( V_39 == NULL )
return - V_50 ;
strncpy ( V_39 -> V_51 , V_46 -> V_51 , V_52 - 1 ) ;
F_18 ( & V_41 -> V_34 , V_39 ) ;
V_39 -> V_21 = V_21 ;
V_39 -> V_28 = ( V_21 -> V_53 == V_54 ) ? V_21 -> V_55 : V_21 -> V_56 ;
V_39 -> V_27 = V_44 -> V_27 ;
V_39 -> V_1 = V_44 -> V_57 ;
if ( V_39 -> V_1 < 0 ) {
F_16 ( & V_41 -> V_34 , L_4 ) ;
F_19 ( V_39 ) ;
return - V_3 ;
}
V_39 -> V_25 = 0 ;
V_39 -> V_36 . V_51 = V_39 -> V_51 ;
V_39 -> V_36 . V_58 = F_11 ;
F_20 ( & V_39 -> V_24 ) ;
F_21 ( & V_39 -> V_17 , F_4 ) ;
V_2 = F_22 ( V_21 -> V_34 , & V_39 -> V_36 ) ;
if ( V_2 < 0 ) {
F_16 ( & V_41 -> V_34 , L_5 , V_2 ) ;
goto V_59;
}
F_11 ( & V_39 -> V_36 , 0 ) ;
return 0 ;
V_59:
F_19 ( V_39 ) ;
return V_2 ;
}
static int F_23 ( struct V_40 * V_41 )
{
struct V_18 * V_39 = F_24 ( V_41 ) ;
F_25 ( & V_39 -> V_36 ) ;
F_19 ( V_39 ) ;
return 0 ;
}
static int T_1 F_26 ( void )
{
return F_27 ( & V_60 ) ;
}
static void T_2 F_28 ( void )
{
F_29 ( & V_60 ) ;
}
