static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
F_4 ( V_9 -> V_10 , V_11 , 0 ) ;
if ( ! V_9 -> V_12 )
F_4 ( V_9 -> V_10 , V_11 , 5 ) ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 ,
enum V_13 V_14 )
{
struct V_9 * V_9 = F_3 ( V_7 ) ;
switch ( V_14 ) {
case V_15 :
break;
case V_16 :
break;
case V_17 :
F_6 ( V_9 -> V_10 , V_18 ,
V_19 ,
V_19 ) ;
F_6 ( V_9 -> V_10 , V_20 , 0x8 , 0x8 ) ;
break;
case V_21 :
F_6 ( V_9 -> V_10 , V_20 , 0xc , 0x0 ) ;
F_6 ( V_9 -> V_10 , V_18 ,
V_19 , 0 ) ;
break;
}
V_7 -> V_8 . V_22 = V_14 ;
return 0 ;
}
static bool F_7 ( struct V_23 * V_24 , unsigned int V_25 )
{
switch ( V_25 ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_11 :
case V_36 :
case V_20 :
return true ;
default:
break;
}
return F_8 ( V_24 , V_25 ) ;
}
static int F_9 ( struct V_9 * V_9 , unsigned int V_25 ,
bool V_37 )
{
unsigned int V_38 ;
if ( V_37 )
V_38 = V_39 ;
else
V_38 = 0 ;
return F_6 ( V_9 -> V_10 , V_25 ,
V_39 , V_38 ) ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_40 * V_41 = F_11 ( V_7 -> V_24 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
int V_42 ;
V_42 = F_12 ( V_7 ) ;
if ( V_42 )
return V_42 ;
if ( V_41 ) {
V_42 = F_9 ( V_9 , V_27 ,
V_41 -> V_43 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_9 ( V_9 , V_28 ,
V_41 -> V_44 ) ;
if ( V_42 )
return V_42 ;
}
if ( V_41 && V_41 -> V_45 ) {
V_42 = F_13 ( & V_7 -> V_8 ,
V_46 ,
F_14 ( V_46 ) ) ;
if ( V_42 )
return V_42 ;
V_42 = F_15 ( & V_7 -> V_8 ,
V_47 ,
F_14 ( V_47 ) ) ;
if ( V_42 )
return V_42 ;
} else {
V_42 = F_15 ( & V_7 -> V_8 ,
V_48 ,
F_14 ( V_48 ) ) ;
if ( V_42 )
return V_42 ;
}
V_42 = F_16 ( V_7 ) ;
if ( V_42 < 0 )
return V_42 ;
return 0 ;
}
int F_17 ( struct V_23 * V_24 , struct V_10 * V_10 ,
enum V_49 type , void (* F_18)( struct V_23 * V_24 ) )
{
const char * V_50 ;
int V_42 ;
switch ( type ) {
case V_51 :
V_50 = V_52 ;
break;
case V_53 :
V_50 = V_54 ;
break;
default:
return - V_55 ;
}
V_42 = F_19 ( V_24 , V_10 , type , F_18 , V_50 ) ;
if ( V_42 )
return V_42 ;
return F_20 ( V_24 , & V_56 ,
& V_57 , 1 ) ;
}
