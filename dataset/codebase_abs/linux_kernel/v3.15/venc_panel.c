static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const char * V_8 ;
switch ( V_7 -> V_9 . V_10 . type ) {
case V_11 :
V_8 = L_1 ;
break;
case V_12 :
V_8 = L_2 ;
break;
default:
return - V_13 ;
}
return snprintf ( V_5 , V_14 , L_3 , V_8 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
enum V_16 V_17 ;
if ( F_4 ( L_1 , V_5 ) )
V_17 = V_11 ;
else if ( F_4 ( L_2 , V_5 ) )
V_17 = V_12 ;
else
return - V_13 ;
F_5 ( & V_18 . V_19 ) ;
if ( V_7 -> V_9 . V_10 . type != V_17 ) {
V_7 -> V_9 . V_10 . type = V_17 ;
F_6 ( V_7 , V_17 ) ;
if ( V_7 -> V_20 == V_21 ) {
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
}
}
F_9 ( & V_18 . V_19 ) ;
return V_15 ;
}
static int F_10 ( struct V_6 * V_7 )
{
const struct V_22 V_23 = {
. V_24 = 720 ,
. V_25 = 574 ,
. V_26 = 13500000 ,
. V_27 = 64 ,
. V_28 = 12 ,
. V_29 = 68 ,
. V_30 = 5 ,
. V_31 = 5 ,
. V_32 = 41 ,
. V_33 = V_34 ,
. V_35 = V_34 ,
. V_36 = true ,
} ;
F_11 ( & V_18 . V_19 ) ;
V_7 -> V_37 . V_38 = V_23 ;
return F_12 ( V_7 -> V_2 , & V_39 ) ;
}
static void F_13 ( struct V_6 * V_7 )
{
F_14 ( V_7 -> V_2 , & V_39 ) ;
}
static int F_15 ( struct V_6 * V_7 )
{
int V_40 ;
F_16 ( V_7 -> V_2 , L_4 ) ;
F_5 ( & V_18 . V_19 ) ;
if ( V_7 -> V_20 != V_41 ) {
V_40 = - V_13 ;
goto V_42;
}
F_17 ( V_7 , & V_7 -> V_37 . V_38 ) ;
F_6 ( V_7 , V_7 -> V_9 . V_10 . type ) ;
F_18 ( V_7 ,
V_7 -> V_9 . V_10 . V_43 ) ;
V_40 = F_8 ( V_7 ) ;
if ( V_40 )
goto V_42;
V_7 -> V_20 = V_21 ;
F_9 ( & V_18 . V_19 ) ;
return 0 ;
V_42:
F_9 ( & V_18 . V_19 ) ;
return V_40 ;
}
static void F_19 ( struct V_6 * V_7 )
{
F_16 ( V_7 -> V_2 , L_5 ) ;
F_5 ( & V_18 . V_19 ) ;
if ( V_7 -> V_20 == V_41 )
goto V_44;
F_7 ( V_7 ) ;
V_7 -> V_20 = V_41 ;
V_44:
F_9 ( & V_18 . V_19 ) ;
}
static void F_20 ( struct V_6 * V_7 ,
struct V_22 * V_38 )
{
F_16 ( V_7 -> V_2 , L_6 ) ;
F_5 ( & V_18 . V_19 ) ;
F_17 ( V_7 , V_38 ) ;
V_7 -> V_37 . V_38 = * V_38 ;
F_9 ( & V_18 . V_19 ) ;
}
static int F_21 ( struct V_6 * V_7 ,
struct V_22 * V_38 )
{
F_16 ( V_7 -> V_2 , L_7 ) ;
return F_22 ( V_7 , V_38 ) ;
}
static T_3 F_23 ( struct V_6 * V_7 )
{
F_16 ( V_7 -> V_2 , L_8 ) ;
return F_24 ( V_7 ) ;
}
static int F_25 ( struct V_6 * V_7 , T_3 V_45 )
{
F_16 ( V_7 -> V_2 , L_9 ) ;
return F_26 ( V_7 , V_45 ) ;
}
int F_27 ( void )
{
return F_28 ( & V_46 ) ;
}
void F_29 ( void )
{
F_30 ( & V_46 ) ;
}
