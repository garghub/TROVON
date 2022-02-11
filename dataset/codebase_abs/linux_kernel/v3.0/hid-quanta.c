static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 ,
unsigned long * * V_9 , int * V_10 )
{
switch ( V_8 -> V_11 & V_12 ) {
case V_13 :
switch ( V_8 -> V_11 ) {
case V_14 :
F_2 ( V_4 , V_8 , V_9 , V_10 ,
V_15 , V_16 ) ;
F_3 ( V_4 -> V_17 , V_18 ,
V_6 -> V_19 ,
V_6 -> V_20 , 0 , 0 ) ;
return 1 ;
case V_21 :
F_2 ( V_4 , V_8 , V_9 , V_10 ,
V_15 , V_22 ) ;
F_3 ( V_4 -> V_17 , V_23 ,
V_6 -> V_19 ,
V_6 -> V_20 , 0 , 0 ) ;
return 1 ;
}
return 0 ;
case V_24 :
switch ( V_8 -> V_11 ) {
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
return - 1 ;
case V_34 :
F_2 ( V_4 , V_8 , V_9 , V_10 , V_35 , V_36 ) ;
return 1 ;
case V_37 :
F_2 ( V_4 , V_8 , V_9 , V_10 ,
V_15 , V_38 ) ;
return 1 ;
}
return 0 ;
case 0xff000000 :
return - 1 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 ,
unsigned long * * V_9 , int * V_10 )
{
if ( V_8 -> type == V_35 || V_8 -> type == V_15 )
F_5 ( V_8 -> V_39 , * V_9 ) ;
return 0 ;
}
static void F_6 ( struct V_40 * V_41 , struct V_42 * V_17 )
{
V_41 -> V_43 = ! V_41 -> V_43 ;
if ( ! V_41 -> V_44 ) {
if ( ! V_41 -> V_43 && ! V_41 -> V_45 && V_41 -> V_46 ) {
F_7 ( V_17 , V_35 , V_36 , 0 ) ;
V_41 -> V_46 = false ;
}
return;
}
F_7 ( V_17 , V_15 , V_38 , V_41 -> V_47 ) ;
F_7 ( V_17 , V_15 , V_16 , V_41 -> V_48 ) ;
F_7 ( V_17 , V_15 , V_22 , V_41 -> V_49 ) ;
F_8 ( V_17 ) ;
V_41 -> V_44 = false ;
if ( ! V_41 -> V_45 ) {
if ( ! V_41 -> V_46 ) {
F_7 ( V_17 , V_35 , V_36 , 1 ) ;
V_41 -> V_46 = true ;
}
V_41 -> V_45 = true ;
F_7 ( V_17 , V_15 , V_18 , V_41 -> V_48 ) ;
F_7 ( V_17 , V_15 , V_23 , V_41 -> V_49 ) ;
}
}
static int F_9 ( struct V_1 * V_11 , struct V_5 * V_6 ,
struct V_7 * V_8 , T_1 V_50 )
{
struct V_40 * V_41 = F_10 ( V_11 ) ;
if ( V_11 -> V_51 & V_52 ) {
struct V_42 * V_17 = V_6 -> V_53 -> V_17 ;
switch ( V_8 -> V_11 ) {
case V_34 :
V_41 -> V_44 = ! ! V_50 ;
break;
case V_14 :
V_41 -> V_48 = V_50 ;
break;
case V_21 :
V_41 -> V_49 = V_50 ;
F_6 ( V_41 , V_17 ) ;
break;
case V_37 :
V_41 -> V_47 = V_50 ;
break;
case V_29 :
V_41 -> V_43 = false ;
V_41 -> V_45 = false ;
break;
case V_25 :
case V_26 :
break;
default:
return 0 ;
}
}
if ( V_11 -> V_51 & V_54 && V_11 -> V_55 )
V_11 -> V_55 ( V_11 , V_6 , V_8 , V_50 ) ;
return 1 ;
}
static int F_11 ( struct V_1 * V_2 , const struct V_56 * V_47 )
{
int V_57 ;
struct V_40 * V_41 ;
V_41 = F_12 ( sizeof( struct V_40 ) , V_58 ) ;
if ( ! V_41 ) {
F_13 ( V_2 , L_1 ) ;
return - V_59 ;
}
V_41 -> V_44 = false ;
V_41 -> V_46 = false ;
V_41 -> V_45 = false ;
V_41 -> V_43 = false ;
F_14 ( V_2 , V_41 ) ;
V_57 = F_15 ( V_2 ) ;
if ( ! V_57 )
V_57 = F_16 ( V_2 , V_60 ) ;
if ( V_57 )
F_17 ( V_41 ) ;
return V_57 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
F_17 ( F_10 ( V_2 ) ) ;
F_14 ( V_2 , NULL ) ;
}
static int T_2 F_20 ( void )
{
return F_21 ( & V_61 ) ;
}
static void T_3 F_22 ( void )
{
F_23 ( & V_61 ) ;
}
