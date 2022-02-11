static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_7 ) ;
F_3 ( V_8 -> V_9 , V_10 , 0 ) ;
if ( ! V_8 -> V_11 )
F_3 ( V_8 -> V_9 , V_10 , 5 ) ;
return 0 ;
}
static int F_4 ( struct V_6 * V_7 ,
enum V_12 V_13 )
{
struct V_8 * V_8 = F_2 ( V_7 ) ;
switch ( V_13 ) {
case V_14 :
break;
case V_15 :
break;
case V_16 :
F_5 ( V_8 -> V_9 , V_17 ,
V_18 ,
V_18 ) ;
F_5 ( V_8 -> V_9 , V_19 , 0x8 , 0x8 ) ;
break;
case V_20 :
F_5 ( V_8 -> V_9 , V_19 , 0xc , 0x0 ) ;
F_5 ( V_8 -> V_9 , V_17 ,
V_18 , 0 ) ;
break;
}
V_7 -> V_21 . V_22 = V_13 ;
return 0 ;
}
static bool F_6 ( struct V_23 * V_24 , unsigned int V_25 )
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
case V_10 :
case V_36 :
case V_19 :
return true ;
default:
break;
}
return F_7 ( V_24 , V_25 ) ;
}
static int F_8 ( struct V_8 * V_8 , unsigned int V_25 ,
bool V_37 )
{
unsigned int V_38 ;
if ( V_37 )
V_38 = V_39 ;
else
V_38 = 0 ;
return F_5 ( V_8 -> V_9 , V_25 ,
V_39 , V_38 ) ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_40 * V_41 = F_10 ( V_7 -> V_24 ) ;
struct V_8 * V_8 = F_2 ( V_7 ) ;
const char * V_42 ;
int V_43 ;
V_43 = F_11 ( V_7 ) ;
if ( V_43 )
return V_43 ;
if ( V_41 ) {
V_43 = F_8 ( V_8 , V_27 ,
V_41 -> V_44 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_8 ( V_8 , V_28 ,
V_41 -> V_45 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_41 && V_41 -> V_46 ) {
V_43 = F_12 ( & V_7 -> V_21 ,
V_47 ,
F_13 ( V_47 ) ) ;
if ( V_43 )
return V_43 ;
V_43 = F_14 ( & V_7 -> V_21 ,
V_48 ,
F_13 ( V_48 ) ) ;
if ( V_43 )
return V_43 ;
} else {
V_43 = F_14 ( & V_7 -> V_21 ,
V_49 ,
F_13 ( V_49 ) ) ;
if ( V_43 )
return V_43 ;
}
switch ( V_8 -> type ) {
case V_50 :
V_42 = V_51 ;
break;
case V_52 :
V_42 = V_53 ;
break;
default:
return - V_54 ;
}
V_43 = F_15 ( V_7 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_16 ( V_8 , V_7 -> V_24 , V_42 ) ;
if ( V_43 )
F_17 ( V_7 -> V_24 , L_1 ) ;
return 0 ;
}
int F_18 ( struct V_23 * V_24 , struct V_9 * V_9 ,
enum V_55 type , void (* F_19)( struct V_23 * V_24 ) )
{
int V_43 ;
V_43 = F_20 ( V_24 , V_9 , type , F_19 ) ;
if ( V_43 )
return V_43 ;
return F_21 ( V_24 , & V_56 ,
& V_57 , 1 ) ;
}
