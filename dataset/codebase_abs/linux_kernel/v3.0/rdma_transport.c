static char * F_1 ( enum V_1 type )
{
return F_2 ( V_2 ,
F_3 ( V_2 ) , type ) ;
}
int F_4 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
int V_12 = 0 ;
F_5 ( L_1 , V_8 , V_4 ,
V_6 -> V_6 , F_1 ( V_6 -> V_6 ) ) ;
if ( V_4 -> V_13 -> V_14 == V_15 )
V_11 = & V_16 ;
else
V_11 = & V_17 ;
if ( V_8 ) {
F_6 ( & V_8 -> V_18 ) ;
if ( F_7 ( V_8 ) == V_19 ) {
if ( V_6 -> V_6 == V_20 )
V_12 = 1 ;
goto V_21;
}
}
switch ( V_6 -> V_6 ) {
case V_20 :
V_12 = V_11 -> V_22 ( V_4 , V_6 ) ;
break;
case V_23 :
V_12 = F_8 ( V_4 ,
V_24 ) ;
break;
case V_25 :
V_12 = V_11 -> V_26 ( V_4 ) ;
break;
case V_27 :
V_11 -> V_28 ( V_8 , V_6 ) ;
break;
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
if ( V_8 )
F_9 ( V_8 ) ;
break;
case V_36 :
F_5 ( L_2
L_3 , & V_8 -> V_37 ,
& V_8 -> V_38 ) ;
F_9 ( V_8 ) ;
break;
default:
F_10 ( V_39 L_4 ,
V_6 -> V_6 , F_1 ( V_6 -> V_6 ) ) ;
break;
}
V_21:
if ( V_8 )
F_11 ( & V_8 -> V_18 ) ;
F_5 ( L_5 , V_4 , V_6 -> V_6 ,
F_1 ( V_6 -> V_6 ) , V_12 ) ;
return V_12 ;
}
static int F_12 ( void )
{
struct V_40 sin ;
struct V_3 * V_4 ;
int V_12 ;
V_4 = F_13 ( F_4 , NULL , V_41 ,
V_42 ) ;
if ( F_14 ( V_4 ) ) {
V_12 = F_15 ( V_4 ) ;
F_10 ( V_39 L_6
L_7 , V_12 ) ;
return V_12 ;
}
sin . V_43 = V_44 ,
sin . V_45 . V_46 = ( V_47 V_48 ) F_16 ( V_49 ) ;
sin . V_50 = ( V_47 V_51 ) F_17 ( V_52 ) ;
V_12 = F_18 ( V_4 , (struct V_53 * ) & sin ) ;
if ( V_12 ) {
F_10 ( V_39 L_6
L_8 , V_12 ) ;
goto V_21;
}
V_12 = F_19 ( V_4 , 128 ) ;
if ( V_12 ) {
F_10 ( V_39 L_6
L_9 , V_12 ) ;
goto V_21;
}
F_5 ( L_10 , V_4 , V_52 ) ;
V_54 = V_4 ;
V_4 = NULL ;
V_21:
if ( V_4 )
F_20 ( V_4 ) ;
return V_12 ;
}
static void F_21 ( void )
{
if ( V_54 ) {
F_5 ( L_11 , V_54 ) ;
F_20 ( V_54 ) ;
V_54 = NULL ;
}
}
static int F_22 ( void )
{
int V_12 ;
V_12 = F_12 () ;
if ( V_12 )
goto V_21;
V_12 = F_23 () ;
if ( V_12 )
goto V_55;
V_12 = F_24 () ;
if ( V_12 )
goto V_56;
goto V_21;
V_56:
F_25 () ;
V_55:
F_21 () ;
V_21:
return V_12 ;
}
static void F_26 ( void )
{
F_21 () ;
F_27 () ;
F_25 () ;
}
