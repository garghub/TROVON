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
return 0 ;
}
static bool F_7 ( struct V_22 * V_23 , unsigned int V_24 )
{
switch ( V_24 ) {
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_11 :
case V_35 :
case V_20 :
return true ;
default:
break;
}
return F_8 ( V_23 , V_24 ) ;
}
static int F_9 ( struct V_9 * V_9 , unsigned int V_24 ,
bool V_36 )
{
unsigned int V_37 ;
if ( V_36 )
V_37 = V_38 ;
else
V_37 = 0 ;
return F_6 ( V_9 -> V_10 , V_24 ,
V_38 , V_37 ) ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_39 * V_8 = F_11 ( V_7 ) ;
struct V_40 * V_41 = F_12 ( V_7 -> V_23 ) ;
struct V_9 * V_9 = F_3 ( V_7 ) ;
int V_42 ;
V_42 = F_13 ( V_7 ) ;
if ( V_42 )
return V_42 ;
if ( V_41 ) {
V_42 = F_9 ( V_9 , V_26 ,
V_41 -> V_43 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_9 ( V_9 , V_27 ,
V_41 -> V_44 ) ;
if ( V_42 )
return V_42 ;
}
if ( V_41 && V_41 -> V_45 ) {
V_42 = F_14 ( V_8 ,
V_46 ,
F_15 ( V_46 ) ) ;
if ( V_42 )
return V_42 ;
V_42 = F_16 ( V_8 , V_47 ,
F_15 ( V_47 ) ) ;
if ( V_42 )
return V_42 ;
} else {
V_42 = F_16 ( V_8 , V_48 ,
F_15 ( V_48 ) ) ;
if ( V_42 )
return V_42 ;
}
V_42 = F_17 ( V_7 ) ;
if ( V_42 < 0 )
return V_42 ;
return 0 ;
}
int F_18 ( struct V_22 * V_23 , struct V_10 * V_10 ,
enum V_49 type , void (* F_19)( struct V_22 * V_23 ) )
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
V_42 = F_20 ( V_23 , V_10 , type , F_19 , V_50 ) ;
if ( V_42 )
return V_42 ;
return F_21 ( V_23 , & V_56 ,
& V_57 , 1 ) ;
}
