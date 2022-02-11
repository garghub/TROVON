static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_6 :
case V_7 ... V_8 :
case V_9 ... V_5 :
case V_10 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_11 :
case V_12 ... V_13 :
case V_10 :
return true ;
default:
return false ;
}
}
static int F_4 ( struct V_14 * V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_22 = F_5 ( V_21 ) ;
unsigned int V_23 = F_6 ( V_17 ) ;
unsigned int V_24 ;
if ( V_23 >= 8000 && V_23 <= 12000 )
V_24 = V_25 ;
else if ( V_23 >= 16000 && V_23 <= 24000 )
V_24 = V_26 ;
else if ( V_23 >= 32000 && V_23 <= 48000 )
V_24 = V_27 ;
else if ( V_23 >= 64000 && V_23 <= 96000 )
V_24 = V_28 ;
else if ( V_23 >= 128000 && V_23 <= 192000 )
V_24 = V_29 ;
else
return - V_30 ;
return F_7 ( V_22 -> V_31 , V_32 ,
V_33 , V_24 ) ;
}
static int F_8 ( struct V_18 * V_19 , int V_34 )
{
struct V_22 * V_22 = F_5 ( V_19 -> V_21 ) ;
unsigned int V_35 ;
V_35 = V_34 ? V_36 : 0 ;
return F_7 ( V_22 -> V_31 , V_32 ,
V_36 , V_35 ) ;
}
static int F_9 ( struct V_22 * V_22 , bool V_37 )
{
int V_38 = 0 ;
if ( ! V_37 ) {
V_38 = F_7 ( V_22 -> V_31 ,
V_4 ,
V_39 , V_39 ) ;
F_10 ( V_22 -> V_31 ) ;
}
F_11 ( V_22 -> V_31 , ! V_37 ) ;
if ( V_37 ) {
V_38 = F_7 ( V_22 -> V_31 ,
V_4 ,
V_39 , 0x00 ) ;
F_12 ( V_22 -> V_31 ) ;
}
return V_38 ;
}
static int F_13 ( struct V_20 * V_21 ,
enum V_40 V_41 )
{
struct V_22 * V_22 = F_5 ( V_21 ) ;
int V_38 = 0 ;
switch ( V_41 ) {
case V_42 :
break;
case V_43 :
break;
case V_44 :
if ( V_21 -> V_45 . V_46 == V_47 )
V_38 = F_9 ( V_22 , true ) ;
break;
case V_47 :
V_38 = F_9 ( V_22 , false ) ;
break;
}
if ( V_38 )
return V_38 ;
V_21 -> V_45 . V_46 = V_41 ;
return 0 ;
}
static int F_14 ( struct V_48 * V_49 ,
const struct V_50 * V_51 )
{
struct V_22 * V_22 ;
int V_38 ;
V_22 = F_15 ( & V_49 -> V_2 , sizeof( * V_22 ) , V_52 ) ;
if ( V_22 == NULL )
return - V_53 ;
F_16 ( V_49 , V_22 ) ;
V_22 -> V_31 = F_17 ( V_49 , & V_54 ) ;
if ( F_18 ( V_22 -> V_31 ) )
return F_19 ( V_22 -> V_31 ) ;
V_38 = F_20 ( V_22 -> V_31 , V_10 , 0x00 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_9 ( V_22 , false ) ;
if ( V_38 )
return V_38 ;
return F_21 ( & V_49 -> V_2 , & V_55 ,
& V_56 , 1 ) ;
}
static int F_22 ( struct V_48 * V_57 )
{
F_23 ( & V_57 -> V_2 ) ;
return 0 ;
}
