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
else
V_9 = & V_15 ;
if ( V_6 ) {
F_4 ( & V_6 -> V_16 ) ;
if ( F_5 ( V_6 ) == V_17 ) {
if ( V_4 -> V_4 == V_18 )
V_10 = 1 ;
goto V_19;
}
}
switch ( V_4 -> V_4 ) {
case V_18 :
V_10 = V_9 -> V_20 ( V_2 , V_4 ) ;
break;
case V_21 :
V_10 = F_6 ( V_2 ,
V_22 ) ;
break;
case V_23 :
if ( V_6 ) {
struct V_24 * V_25 ;
V_25 = V_6 -> V_26 ;
if ( V_25 && V_25 -> V_27 == V_2 )
V_10 = V_9 -> V_28 ( V_2 ) ;
else
F_7 ( V_6 ) ;
}
break;
case V_29 :
V_9 -> V_30 ( V_6 , V_4 ) ;
break;
case V_31 :
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
F_2 ( L_2
L_3 , & V_6 -> V_39 ,
& V_6 -> V_40 ) ;
F_7 ( V_6 ) ;
break;
default:
F_8 ( V_41 L_4 ,
V_4 -> V_4 , F_3 ( V_4 -> V_4 ) ) ;
break;
}
V_19:
if ( V_6 )
F_9 ( & V_6 -> V_16 ) ;
F_2 ( L_5 , V_2 , V_4 -> V_4 ,
F_3 ( V_4 -> V_4 ) , V_10 ) ;
return V_10 ;
}
static int F_10 ( void )
{
struct V_42 sin ;
struct V_1 * V_2 ;
int V_10 ;
V_2 = F_11 ( & V_43 , F_1 , NULL ,
V_44 , V_45 ) ;
if ( F_12 ( V_2 ) ) {
V_10 = F_13 ( V_2 ) ;
F_8 ( V_41 L_6
L_7 , V_10 ) ;
return V_10 ;
}
sin . V_46 = V_47 ;
sin . V_48 . V_49 = ( V_50 V_51 ) F_14 ( V_52 ) ;
sin . V_53 = ( V_50 V_54 ) F_15 ( V_55 ) ;
V_10 = F_16 ( V_2 , (struct V_56 * ) & sin ) ;
if ( V_10 ) {
F_8 ( V_41 L_6
L_8 , V_10 ) ;
goto V_19;
}
V_10 = F_17 ( V_2 , 128 ) ;
if ( V_10 ) {
F_8 ( V_41 L_6
L_9 , V_10 ) ;
goto V_19;
}
F_2 ( L_10 , V_2 , V_55 ) ;
V_57 = V_2 ;
V_2 = NULL ;
V_19:
if ( V_2 )
F_18 ( V_2 ) ;
return V_10 ;
}
static void F_19 ( void )
{
if ( V_57 ) {
F_2 ( L_11 , V_57 ) ;
F_18 ( V_57 ) ;
V_57 = NULL ;
}
}
static int F_20 ( void )
{
int V_10 ;
V_10 = F_10 () ;
if ( V_10 )
goto V_19;
V_10 = F_21 () ;
if ( V_10 )
goto V_58;
V_10 = F_22 () ;
if ( V_10 )
goto V_59;
goto V_19;
V_59:
F_23 () ;
V_58:
F_19 () ;
V_19:
return V_10 ;
}
static void F_24 ( void )
{
F_19 () ;
F_25 () ;
F_23 () ;
}
