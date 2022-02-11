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
V_9 -> V_7 . V_26 = F_7 ;
V_9 -> V_7 . V_27 = F_9 ;
V_21 = F_14 ( V_4 , V_28 , & V_9 -> V_7 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_15 ( V_17 , V_4 , V_19 , V_20 ) ;
if ( V_21 ) {
F_16 ( V_4 ) ;
return V_21 ;
}
V_9 -> V_7 . V_4 = V_9 -> V_11 . V_4 ;
return 0 ;
}
static void F_17 ( struct V_3 * V_4 ,
struct V_29 * V_30 )
{
struct V_8 * V_9 = F_12 ( V_4 ) ;
F_16 ( V_4 ) ;
F_18 ( & V_9 -> V_7 ) ;
F_19 ( V_4 , V_30 ) ;
}
static void F_20 ( struct V_3 * V_4 )
{
F_21 ( V_4 ) ;
V_4 -> V_31 = V_32 ;
}
static int F_22 ( struct V_33 * V_34 ,
unsigned long V_35 , void * V_36 )
{
struct V_3 * V_4 = F_23 ( V_36 ) ;
struct V_8 * V_9 ;
struct V_1 * V_37 ;
T_2 V_38 ;
int V_21 ;
char V_39 [ V_40 ] ;
if ( V_4 -> V_41 != & V_42 )
return V_43 ;
snprintf ( V_39 , V_40 , L_1 , V_4 -> V_44 ) ;
V_9 = F_12 ( V_4 ) ;
switch ( V_35 ) {
case V_45 :
V_21 = F_24 ( V_46 , & V_9 -> V_7 ) ;
if ( V_21 )
return F_25 ( V_21 ) ;
V_38 = F_26 ( F_27 ( V_46 ) , V_9 -> V_7 . V_47 ) ;
V_37 = F_28 ( & V_48 , & V_4 -> V_4 , V_38 ,
V_4 , V_39 ) ;
if ( F_29 ( V_37 ) ) {
F_30 ( V_46 , & V_9 -> V_7 ) ;
return F_25 ( F_31 ( V_37 ) ) ;
}
V_21 = F_32 ( & V_4 -> V_4 . V_49 , & V_37 -> V_49 ,
V_39 ) ;
if ( V_21 )
return F_25 ( V_21 ) ;
break;
case V_50 :
if ( V_9 -> V_7 . V_47 == 0 )
break;
F_33 ( & V_4 -> V_4 . V_49 , V_39 ) ;
V_38 = F_26 ( F_27 ( V_46 ) , V_9 -> V_7 . V_47 ) ;
F_34 ( & V_48 , V_38 ) ;
F_30 ( V_46 , & V_9 -> V_7 ) ;
break;
case V_51 :
if ( F_35 ( & V_9 -> V_7 ) )
return V_52 ;
break;
}
return V_43 ;
}
static int F_36 ( void )
{
int V_21 ;
V_21 = F_37 ( & V_53 , & V_46 , L_2 ) ;
if ( V_21 )
goto V_54;
V_21 = F_38 ( & V_48 ) ;
if ( V_21 )
goto V_55;
V_21 = F_39 ( & V_56 ) ;
if ( V_21 )
goto V_57;
V_21 = F_40 ( & V_42 ) ;
if ( V_21 )
goto V_58;
return 0 ;
V_58:
F_41 ( & V_56 ) ;
V_57:
F_42 ( & V_48 ) ;
V_55:
F_43 ( V_46 , & V_53 ) ;
V_54:
return V_21 ;
}
static void F_44 ( void )
{
F_45 ( & V_42 ) ;
F_41 ( & V_56 ) ;
F_42 ( & V_48 ) ;
F_43 ( V_46 , & V_53 ) ;
}
