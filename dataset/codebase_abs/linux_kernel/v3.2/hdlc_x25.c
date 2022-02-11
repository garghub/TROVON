static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 ;
unsigned char * V_7 ;
if ( ( V_6 = F_2 ( 1 ) ) == NULL ) {
F_3 ( V_2 , L_1 ) ;
return;
}
V_7 = F_4 ( V_6 , 1 ) ;
* V_7 = V_4 ;
V_6 -> V_8 = F_5 ( V_6 , V_2 ) ;
F_6 ( V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 )
{
F_1 ( V_2 , V_3 , V_9 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_3 )
{
F_1 ( V_2 , V_3 , V_10 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
unsigned char * V_7 ;
F_10 ( V_6 , 1 ) ;
if ( F_11 ( V_6 , 1 ) )
return V_11 ;
V_7 = V_6 -> V_12 ;
* V_7 = V_13 ;
V_6 -> V_8 = F_5 ( V_6 , V_2 ) ;
return F_6 ( V_6 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
T_1 * V_14 = F_13 ( V_2 ) ;
V_14 -> V_15 ( V_6 , V_2 ) ;
}
static T_2 F_14 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
int V_16 ;
switch ( V_6 -> V_12 [ 0 ] ) {
case V_13 :
F_15 ( V_6 , 1 ) ;
if ( ( V_16 = F_16 ( V_2 , V_6 ) ) != V_17 )
F_17 ( V_6 ) ;
return V_18 ;
case V_9 :
if ( ( V_16 = F_18 ( V_2 ) ) != V_17 ) {
if ( V_16 == V_19 )
F_7 ( V_2 , 0 ) ;
else
F_3 ( V_2 , L_2 ,
V_16 ) ;
}
break;
case V_10 :
if ( ( V_16 = F_19 ( V_2 ) ) != V_17 ) {
if ( V_16 == V_20 )
F_8 ( V_2 , 0 ) ;
else
F_3 ( V_2 , L_3 ,
V_16 ) ;
}
break;
default:
break;
}
F_17 ( V_6 ) ;
return V_18 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_16 ;
static const struct V_21 V_22 = {
. V_23 = F_7 ,
. V_24 = F_7 ,
. V_25 = F_8 ,
. V_26 = F_8 ,
. V_27 = F_9 ,
. V_28 = F_12 ,
} ;
V_16 = F_21 ( V_2 , & V_22 ) ;
if ( V_16 != V_17 )
return V_16 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
}
static int F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
if ( ( V_6 = F_25 ( V_6 , V_29 ) ) == NULL ) {
V_2 -> V_30 . V_31 ++ ;
return V_11 ;
}
if ( F_26 ( V_2 , V_6 ) == V_17 )
return V_32 ;
V_2 -> V_30 . V_33 ++ ;
F_27 ( V_6 ) ;
return V_11 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
T_1 * V_14 = F_13 ( V_2 ) ;
int V_16 ;
switch ( V_35 -> V_36 . type ) {
case V_37 :
if ( F_13 ( V_2 ) -> V_38 != & V_38 )
return - V_39 ;
V_35 -> V_36 . type = V_40 ;
return 0 ;
case V_40 :
if ( ! F_29 ( V_41 ) )
return - V_42 ;
if ( V_2 -> V_43 & V_44 )
return - V_45 ;
V_16 = V_14 -> V_46 ( V_2 , V_47 , V_48 ) ;
if ( V_16 )
return V_16 ;
if ( ( V_16 = F_30 ( V_2 , & V_38 , 0 ) ) )
return V_16 ;
V_2 -> type = V_49 ;
F_31 ( V_2 ) ;
return 0 ;
}
return - V_39 ;
}
static int T_3 F_32 ( void )
{
F_33 ( & V_38 ) ;
return 0 ;
}
static void T_4 F_34 ( void )
{
F_35 ( & V_38 ) ;
}
