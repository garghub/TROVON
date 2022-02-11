int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 ;
int V_10 = 0 ;
F_2 ( L_1 , V_6 , V_2 ,
V_4 -> V_4 , F_3 ( V_4 -> V_4 ) ) ;
if ( V_2 -> V_11 -> V_12 == V_13 )
V_9 = & V_14 ;
if ( V_6 ) {
F_4 ( & V_6 -> V_15 ) ;
if ( F_5 ( V_6 ) == V_16 ) {
if ( V_4 -> V_4 == V_17 )
V_10 = 1 ;
goto V_18;
}
}
switch ( V_4 -> V_4 ) {
case V_17 :
V_10 = V_9 -> V_19 ( V_2 , V_4 ) ;
break;
case V_20 :
V_10 = F_6 ( V_2 ,
V_21 ) ;
break;
case V_22 :
if ( V_6 ) {
struct V_23 * V_24 ;
V_24 = V_6 -> V_25 ;
if ( V_24 && V_24 -> V_26 == V_2 )
V_10 = V_9 -> V_27 ( V_2 ) ;
else
F_7 ( V_6 ) ;
}
break;
case V_28 :
V_9 -> V_29 ( V_6 , V_4 ) ;
break;
case V_30 :
F_2 ( L_2 ,
F_8 ( V_2 , V_4 -> V_31 ) ) ;
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
if ( V_6 )
F_7 ( V_6 ) ;
break;
case V_38 :
F_2 ( L_3
L_4 , & V_6 -> V_39 ,
& V_6 -> V_40 ) ;
F_7 ( V_6 ) ;
break;
case V_41 :
if ( V_6 ) {
F_9 ( L_5 ,
& V_6 -> V_39 , & V_6 -> V_40 ) ;
F_7 ( V_6 ) ;
}
break;
default:
F_10 ( V_42 L_6 ,
V_4 -> V_4 , F_3 ( V_4 -> V_4 ) ) ;
break;
}
V_18:
if ( V_6 )
F_11 ( & V_6 -> V_15 ) ;
F_2 ( L_7 , V_2 , V_4 -> V_4 ,
F_3 ( V_4 -> V_4 ) , V_10 ) ;
return V_10 ;
}
static int F_12 ( void )
{
struct V_43 sin ;
struct V_1 * V_2 ;
int V_10 ;
V_2 = F_13 ( & V_44 , F_1 , NULL ,
V_45 , V_46 ) ;
if ( F_14 ( V_2 ) ) {
V_10 = F_15 ( V_2 ) ;
F_10 ( V_42 L_8
L_9 , V_10 ) ;
return V_10 ;
}
sin . V_47 = V_48 ;
sin . V_49 . V_50 = ( V_51 V_52 ) F_16 ( V_53 ) ;
sin . V_54 = ( V_51 V_55 ) F_17 ( V_56 ) ;
V_10 = F_18 ( V_2 , (struct V_57 * ) & sin ) ;
if ( V_10 ) {
F_10 ( V_42 L_8
L_10 , V_10 ) ;
goto V_18;
}
V_10 = F_19 ( V_2 , 128 ) ;
if ( V_10 ) {
F_10 ( V_42 L_8
L_11 , V_10 ) ;
goto V_18;
}
F_2 ( L_12 , V_2 , V_56 ) ;
V_58 = V_2 ;
V_2 = NULL ;
V_18:
if ( V_2 )
F_20 ( V_2 ) ;
return V_10 ;
}
static void F_21 ( void )
{
if ( V_58 ) {
F_2 ( L_13 , V_58 ) ;
F_20 ( V_58 ) ;
V_58 = NULL ;
}
}
static int F_22 ( void )
{
int V_10 ;
V_10 = F_23 () ;
if ( V_10 )
goto V_18;
V_10 = F_12 () ;
if ( V_10 )
F_24 () ;
V_18:
return V_10 ;
}
static void F_25 ( void )
{
F_21 () ;
F_24 () ;
}
