static int F_1 ( void )
{
F_2 ( 0 , V_1 ) ;
F_3 ( 200 ) ;
F_2 ( 0 , V_2 ) ;
return 0 ;
}
static int F_4 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_5 ( unsigned long V_5 )
{
struct V_6 * V_7 = ( void * ) V_5 ;
unsigned short V_8 = F_6 ( V_7 -> V_9 ) ;
if ( V_8 != V_7 -> V_8 ) {
V_7 -> V_8 = V_8 ;
F_7 ( & V_7 -> V_10 -> V_11 , L_1 ,
V_8 ? L_2 : L_3 ) ;
F_8 ( & V_7 -> V_12 , V_13 ) ;
}
if ( V_7 -> V_14 )
F_9 ( & V_7 -> V_15 , V_16 + V_17 ) ;
}
static int F_10 ( struct V_3 * V_4 , T_1 * V_18 )
{
struct V_6 * V_7 ;
if ( ! V_18 )
return - V_19 ;
V_7 = F_11 ( V_4 , struct V_6 , V_12 ) ;
if ( F_6 ( V_7 -> V_9 ) ) {
* V_18 = V_20 | V_13 | V_21 | V_22 ;
V_4 -> V_23 = 0 ;
V_4 -> V_24 = V_7 -> V_25 ;
} else
* V_18 = 0 ;
return 0 ;
}
static int
F_12 ( struct V_3 * V_26 , struct V_27 * V_4 )
{
struct V_6 * V_7 ;
V_7 = F_11 ( V_26 , struct V_6 , V_12 ) ;
switch ( V_4 -> V_28 ) {
case 0 :
case 33 :
break;
case 50 :
break;
default:
return - V_19 ;
}
if ( V_4 -> V_29 & V_30 ) {
F_13 ( V_7 -> V_25 ) ;
F_1 () ;
F_14 ( V_7 -> V_25 ) ;
}
F_7 ( & V_7 -> V_10 -> V_11 , L_4 ,
V_4 -> V_28 , V_4 -> V_31 , V_4 -> V_29 , V_4 -> V_32 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 )
{
return F_12 ( V_4 , & V_33 ) ;
}
static int F_16 ( struct V_3 * V_4 , struct V_34 * V_35 )
{
struct V_6 * V_7 ;
V_7 = F_11 ( V_4 , struct V_6 , V_12 ) ;
V_35 -> V_29 &= V_36 | V_37 | V_38 ;
V_35 -> V_39 = V_7 -> V_40 ;
V_35 -> V_41 = V_35 -> V_39 + V_42 - 1 ;
return 0 ;
}
static int
F_17 ( struct V_3 * V_4 , struct V_43 * V_44 )
{
struct V_6 * V_7 ;
if ( V_44 -> V_45 )
return - V_19 ;
V_7 = F_11 ( V_4 , struct V_6 , V_12 ) ;
V_44 -> V_46 = V_7 -> V_40 ;
V_44 -> V_29 &= V_36 | V_37 | V_38 ;
if ( V_44 -> V_29 & V_37 )
V_44 -> V_46 = V_7 -> V_47 ;
return 0 ;
}
static int T_2 F_18 ( struct V_48 * V_10 )
{
struct V_6 * V_7 ;
struct V_49 * V_50 , * V_51 ;
int V_25 ;
unsigned short V_9 ;
int V_52 = 0 ;
F_19 ( & V_10 -> V_11 , L_5 ) ;
V_25 = F_20 ( V_10 , 0 ) ;
if ( V_25 <= 0 )
return - V_19 ;
V_9 = F_20 ( V_10 , 1 ) ;
if ( F_21 ( V_9 , L_6 ) ) {
F_22 ( & V_10 -> V_11 ,
L_7 ,
V_9 ) ;
return - V_53 ;
}
F_23 ( V_9 ) ;
V_7 = F_24 ( sizeof *V_7 , V_54 ) ;
if ( ! V_7 ) {
F_25 ( V_9 ) ;
return - V_55 ;
}
V_7 -> V_9 = V_9 ;
F_26 ( & V_7 -> V_15 , F_5 , ( unsigned long ) V_7 ) ;
V_7 -> V_10 = V_10 ;
F_27 ( V_10 , V_7 ) ;
V_7 -> V_25 = V_25 ;
V_7 -> V_12 . V_24 = V_25 ;
F_28 ( V_25 , V_56 ) ;
V_50 = F_29 ( V_10 , V_57 , 0 ) ;
V_51 = F_29 ( V_10 , V_57 , 1 ) ;
if ( ! V_50 || ! V_51 )
goto V_58;
V_7 -> V_40 = V_50 -> V_39 ;
V_7 -> V_47 = V_51 -> V_39 ;
V_7 -> V_12 . V_59 = ( unsigned long )
F_30 ( V_7 -> V_40 , V_42 ) ;
if ( ! V_7 -> V_12 . V_59 )
goto V_58;
F_22 ( & V_10 -> V_11 , L_8 , V_25 ) ;
F_7 ( & V_10 -> V_11 , L_9 ,
F_6 ( V_7 -> V_9 ) ? L_2 : L_10 ) ;
V_7 -> V_12 . V_60 = V_61 ;
V_7 -> V_12 . V_11 . V_62 = & V_10 -> V_11 ;
V_7 -> V_12 . V_63 = & V_64 ;
V_7 -> V_12 . V_65 = & V_66 ;
V_7 -> V_12 . V_67 = V_68 | V_69
| V_70 ;
V_7 -> V_12 . V_71 = V_42 ;
V_52 = F_31 ( & V_7 -> V_12 ) ;
if ( V_52 < 0 )
goto V_72;
V_7 -> V_14 = 1 ;
F_9 ( & V_7 -> V_15 , V_16 + V_17 ) ;
return 0 ;
V_72:
F_32 ( ( void V_73 * ) V_7 -> V_12 . V_59 ) ;
F_33 ( V_7 -> V_40 , V_74 ) ;
V_58:
F_25 ( V_7 -> V_9 ) ;
F_34 ( V_7 ) ;
F_27 ( V_10 , NULL ) ;
return V_52 ;
}
static int T_3 F_35 ( struct V_48 * V_10 )
{
struct V_6 * V_7 = F_36 ( V_10 ) ;
F_25 ( V_7 -> V_9 ) ;
V_7 -> V_14 = 0 ;
F_37 ( & V_7 -> V_12 ) ;
F_38 ( & V_7 -> V_15 ) ;
F_32 ( ( void V_73 * ) V_7 -> V_12 . V_59 ) ;
F_33 ( V_7 -> V_40 , V_74 ) ;
F_27 ( V_10 , NULL ) ;
F_34 ( V_7 ) ;
return 0 ;
}
static int T_4 F_39 ( void )
{
return F_40 ( & V_75 ) ;
}
static void T_5 F_41 ( void )
{
F_42 ( & V_75 ) ;
}
