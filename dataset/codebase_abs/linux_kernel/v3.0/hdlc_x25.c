static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 ;
unsigned char * V_7 ;
if ( ( V_6 = F_2 ( 1 ) ) == NULL ) {
F_3 ( V_8 L_1 , V_2 -> V_9 ) ;
return;
}
V_7 = F_4 ( V_6 , 1 ) ;
* V_7 = V_4 ;
V_6 -> V_10 = F_5 ( V_6 , V_2 ) ;
F_6 ( V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 )
{
F_1 ( V_2 , V_3 , V_11 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_3 )
{
F_1 ( V_2 , V_3 , V_12 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
unsigned char * V_7 ;
F_10 ( V_6 , 1 ) ;
if ( F_11 ( V_6 , 1 ) )
return V_13 ;
V_7 = V_6 -> V_14 ;
* V_7 = V_15 ;
V_6 -> V_10 = F_5 ( V_6 , V_2 ) ;
return F_6 ( V_6 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 * V_16 = F_13 ( V_2 ) ;
V_16 -> V_17 ( V_6 , V_2 ) ;
}
static T_2 F_14 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
int V_18 ;
switch ( V_6 -> V_14 [ 0 ] ) {
case V_15 :
F_15 ( V_6 , 1 ) ;
if ( ( V_18 = F_16 ( V_2 , V_6 ) ) != V_19 )
F_17 ( V_6 ) ;
return V_20 ;
case V_11 :
if ( ( V_18 = F_18 ( V_2 ) ) != V_19 ) {
if ( V_18 == V_21 )
F_7 ( V_2 , 0 ) ;
else
F_3 ( V_8 L_2
L_3 ,
V_2 -> V_9 , V_18 ) ;
}
break;
case V_12 :
if ( ( V_18 = F_19 ( V_2 ) ) != V_19 ) {
if ( V_18 == V_22 )
F_8 ( V_2 , 0 ) ;
else
F_3 ( V_8 L_4
L_3 ,
V_2 -> V_9 , V_18 ) ;
}
break;
default:
break;
}
F_17 ( V_6 ) ;
return V_20 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_23 V_24 ;
int V_18 ;
V_24 . V_25 = F_7 ;
V_24 . V_26 = F_7 ;
V_24 . V_27 = F_8 ;
V_24 . V_28 = F_8 ;
V_24 . V_29 = F_9 ;
V_24 . V_30 = F_12 ;
V_18 = F_21 ( V_2 , & V_24 ) ;
if ( V_18 != V_19 )
return V_18 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
}
static int F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
if ( ( V_6 = F_25 ( V_6 , V_31 ) ) == NULL ) {
V_2 -> V_32 . V_33 ++ ;
return V_13 ;
}
if ( F_26 ( V_2 , V_6 ) == V_19 )
return V_34 ;
V_2 -> V_32 . V_35 ++ ;
F_27 ( V_6 ) ;
return V_13 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
T_1 * V_16 = F_13 ( V_2 ) ;
int V_18 ;
switch ( V_37 -> V_38 . type ) {
case V_39 :
if ( F_13 ( V_2 ) -> V_40 != & V_40 )
return - V_41 ;
V_37 -> V_38 . type = V_42 ;
return 0 ;
case V_42 :
if ( ! F_29 ( V_43 ) )
return - V_44 ;
if ( V_2 -> V_45 & V_46 )
return - V_47 ;
V_18 = V_16 -> V_48 ( V_2 , V_49 , V_50 ) ;
if ( V_18 )
return V_18 ;
if ( ( V_18 = F_30 ( V_2 , & V_40 , 0 ) ) )
return V_18 ;
V_2 -> type = V_51 ;
F_31 ( V_2 ) ;
return 0 ;
}
return - V_41 ;
}
static int T_3 F_32 ( void )
{
F_33 ( & V_40 ) ;
return 0 ;
}
static void T_4 F_34 ( void )
{
F_35 ( & V_40 ) ;
}
