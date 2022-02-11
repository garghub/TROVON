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
static int F_11 ( struct V_16 * V_17 , struct V_3 * V_4 ,
struct V_18 * V_19 [] , struct V_18 * V_20 [] ,
struct V_21 * V_22 )
{
struct V_8 * V_9 = F_12 ( V_4 ) ;
int V_23 ;
F_13 ( & V_9 -> V_7 . V_24 ) ;
V_9 -> V_7 . V_25 = V_26 ;
V_9 -> V_7 . V_27 = F_4 ;
V_9 -> V_7 . V_28 = F_9 ;
V_9 -> V_7 . V_29 = F_7 ;
V_23 = F_14 ( V_4 , V_30 , & V_9 -> V_7 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_15 ( V_17 , V_4 , V_19 , V_20 , V_22 ) ;
if ( V_23 ) {
F_16 ( V_4 ) ;
return V_23 ;
}
V_9 -> V_7 . V_4 = V_9 -> V_11 . V_4 ;
return V_23 ;
}
static void F_17 ( struct V_3 * V_4 ,
struct V_31 * V_32 )
{
struct V_8 * V_11 = F_12 ( V_4 ) ;
F_16 ( V_4 ) ;
F_18 ( & V_11 -> V_7 ) ;
F_19 ( V_4 , V_32 ) ;
}
static void F_20 ( struct V_3 * V_4 )
{
F_21 ( V_4 ) ;
V_4 -> V_33 = V_34 ;
V_4 -> V_35 &= ~ V_36 ;
}
static int F_22 ( struct V_37 * V_38 ,
unsigned long V_39 , void * V_40 )
{
struct V_3 * V_4 = F_23 ( V_40 ) ;
struct V_8 * V_9 ;
struct V_1 * V_41 ;
T_2 V_42 ;
int V_23 ;
char V_43 [ V_44 ] ;
if ( V_4 -> V_45 != & V_46 )
return V_47 ;
snprintf ( V_43 , V_44 , L_1 , V_4 -> V_48 ) ;
V_9 = F_12 ( V_4 ) ;
switch ( V_39 ) {
case V_49 :
V_23 = F_24 ( V_50 , & V_9 -> V_7 ) ;
if ( V_23 )
return F_25 ( V_23 ) ;
V_42 = F_26 ( F_27 ( V_50 ) , V_9 -> V_7 . V_51 ) ;
V_41 = F_28 ( & V_52 , & V_4 -> V_4 , V_42 ,
V_4 , V_43 ) ;
if ( F_29 ( V_41 ) ) {
F_30 ( V_50 , & V_9 -> V_7 ) ;
return F_25 ( F_31 ( V_41 ) ) ;
}
V_23 = F_32 ( & V_4 -> V_4 . V_53 , & V_41 -> V_53 ,
V_43 ) ;
if ( V_23 )
return F_25 ( V_23 ) ;
break;
case V_54 :
if ( V_9 -> V_7 . V_51 == 0 )
break;
F_33 ( & V_4 -> V_4 . V_53 , V_43 ) ;
V_42 = F_26 ( F_27 ( V_50 ) , V_9 -> V_7 . V_51 ) ;
F_34 ( & V_52 , V_42 ) ;
F_30 ( V_50 , & V_9 -> V_7 ) ;
break;
case V_55 :
if ( F_35 ( & V_9 -> V_7 ) )
return V_56 ;
break;
}
return V_47 ;
}
static int F_36 ( void )
{
int V_23 ;
V_23 = F_37 ( & V_57 , & V_50 , L_2 ,
V_58 ) ;
if ( V_23 )
goto V_59;
V_23 = F_38 ( & V_52 ) ;
if ( V_23 )
goto V_60;
V_23 = F_39 ( & V_61 ) ;
if ( V_23 )
goto V_62;
V_23 = F_40 ( & V_46 ) ;
if ( V_23 )
goto V_63;
return 0 ;
V_63:
F_41 ( & V_61 ) ;
V_62:
F_42 ( & V_52 ) ;
V_60:
F_43 ( V_50 , & V_57 ) ;
V_59:
return V_23 ;
}
static void F_44 ( void )
{
F_45 ( & V_46 ) ;
F_41 ( & V_61 ) ;
F_42 ( & V_52 ) ;
F_43 ( V_50 , & V_57 ) ;
}
