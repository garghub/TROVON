static const void * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
return F_3 ( V_4 ) ;
}
static void F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_7 , struct V_8 , V_7 ) ;
struct V_10 * V_11 = & V_9 -> V_11 ;
F_6 ( V_11 -> V_12 -> V_13 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_7 , struct V_8 , V_7 ) ;
struct V_10 * V_11 = & V_9 -> V_11 ;
F_8 ( V_11 , 0 , 0 , 0 ) ;
}
static void F_9 ( struct V_6 * V_7 ,
T_1 V_14 )
{
struct V_8 * V_9 = F_5 ( V_7 , struct V_8 , V_7 ) ;
struct V_10 * V_11 = & V_9 -> V_11 ;
V_11 -> V_15 = V_14 ;
F_10 ( V_11 -> V_4 ) ;
}
static int F_11 ( struct V_16 * V_17 ,
struct V_3 * V_4 ,
struct V_18 * V_19 [] ,
struct V_18 * V_20 [] )
{
struct V_8 * V_9 = F_12 ( V_4 ) ;
int V_21 ;
F_13 ( & V_9 -> V_7 . V_22 ) ;
V_9 -> V_7 . V_23 = V_24 ;
V_9 -> V_7 . V_25 = F_4 ;
V_9 -> V_7 . V_26 = F_9 ;
V_9 -> V_7 . V_27 = F_7 ;
V_21 = F_14 ( V_4 , V_28 , & V_9 -> V_7 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_15 ( V_17 , V_4 , V_19 , V_20 ) ;
if ( V_21 ) {
F_16 ( V_4 ) ;
return V_21 ;
}
V_9 -> V_7 . V_4 = V_9 -> V_11 . V_4 ;
return V_21 ;
}
static void F_17 ( struct V_3 * V_4 ,
struct V_29 * V_30 )
{
struct V_8 * V_11 = F_12 ( V_4 ) ;
F_16 ( V_4 ) ;
F_18 ( & V_11 -> V_7 ) ;
F_19 ( V_4 , V_30 ) ;
}
static void F_20 ( struct V_3 * V_4 )
{
F_21 ( V_4 ) ;
V_4 -> V_31 = V_32 ;
V_4 -> V_33 &= ~ V_34 ;
}
static int F_22 ( struct V_35 * V_36 ,
unsigned long V_37 , void * V_38 )
{
struct V_3 * V_4 = F_23 ( V_38 ) ;
struct V_8 * V_9 ;
struct V_1 * V_39 ;
T_2 V_40 ;
int V_21 ;
char V_41 [ V_42 ] ;
if ( V_4 -> V_43 != & V_44 )
return V_45 ;
snprintf ( V_41 , V_42 , L_1 , V_4 -> V_46 ) ;
V_9 = F_12 ( V_4 ) ;
switch ( V_37 ) {
case V_47 :
V_21 = F_24 ( V_48 , & V_9 -> V_7 ) ;
if ( V_21 )
return F_25 ( V_21 ) ;
V_40 = F_26 ( F_27 ( V_48 ) , V_9 -> V_7 . V_49 ) ;
V_39 = F_28 ( & V_50 , & V_4 -> V_4 , V_40 ,
V_4 , V_41 ) ;
if ( F_29 ( V_39 ) ) {
F_30 ( V_48 , & V_9 -> V_7 ) ;
return F_25 ( F_31 ( V_39 ) ) ;
}
V_21 = F_32 ( & V_4 -> V_4 . V_51 , & V_39 -> V_51 ,
V_41 ) ;
if ( V_21 )
return F_25 ( V_21 ) ;
break;
case V_52 :
if ( V_9 -> V_7 . V_49 == 0 )
break;
F_33 ( & V_4 -> V_4 . V_51 , V_41 ) ;
V_40 = F_26 ( F_27 ( V_48 ) , V_9 -> V_7 . V_49 ) ;
F_34 ( & V_50 , V_40 ) ;
F_30 ( V_48 , & V_9 -> V_7 ) ;
break;
case V_53 :
if ( F_35 ( & V_9 -> V_7 ) )
return V_54 ;
break;
}
return V_45 ;
}
static int F_36 ( void )
{
int V_21 ;
V_21 = F_37 ( & V_55 , & V_48 , L_2 ) ;
if ( V_21 )
goto V_56;
V_21 = F_38 ( & V_50 ) ;
if ( V_21 )
goto V_57;
V_21 = F_39 ( & V_58 ) ;
if ( V_21 )
goto V_59;
V_21 = F_40 ( & V_44 ) ;
if ( V_21 )
goto V_60;
return 0 ;
V_60:
F_41 ( & V_58 ) ;
V_59:
F_42 ( & V_50 ) ;
V_57:
F_43 ( V_48 , & V_55 ) ;
V_56:
return V_21 ;
}
static void F_44 ( void )
{
F_45 ( & V_44 ) ;
F_41 ( & V_58 ) ;
F_42 ( & V_50 ) ;
F_43 ( V_48 , & V_55 ) ;
}
