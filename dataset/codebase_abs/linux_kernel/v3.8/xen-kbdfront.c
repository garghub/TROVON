static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_2 V_7 , V_8 ;
V_8 = V_6 -> V_9 ;
if ( V_8 == V_6 -> V_10 )
return V_11 ;
F_2 () ;
for ( V_7 = V_6 -> V_10 ; V_7 != V_8 ; V_7 ++ ) {
union V_12 * V_13 ;
struct V_14 * V_15 ;
V_13 = & F_3 ( V_6 , V_7 ) ;
V_15 = V_4 -> V_16 ;
switch ( V_13 -> type ) {
case V_17 :
F_4 ( V_15 , V_18 , V_13 -> V_19 . V_20 ) ;
F_4 ( V_15 , V_21 , V_13 -> V_19 . V_22 ) ;
if ( V_13 -> V_19 . V_23 )
F_4 ( V_15 , V_24 ,
- V_13 -> V_19 . V_23 ) ;
break;
case V_25 :
V_15 = NULL ;
if ( F_5 ( V_13 -> V_26 . V_27 , V_4 -> V_28 -> V_29 ) )
V_15 = V_4 -> V_28 ;
if ( F_5 ( V_13 -> V_26 . V_27 , V_4 -> V_16 -> V_29 ) )
V_15 = V_4 -> V_16 ;
if ( V_15 )
F_6 ( V_15 , V_13 -> V_26 . V_27 ,
V_13 -> V_26 . V_30 ) ;
else
F_7 ( L_1 ,
V_13 -> V_26 . V_27 ) ;
break;
case V_31 :
F_8 ( V_15 , V_32 , V_13 -> V_33 . V_34 ) ;
F_8 ( V_15 , V_35 , V_13 -> V_33 . V_36 ) ;
if ( V_13 -> V_33 . V_23 )
F_4 ( V_15 , V_24 ,
- V_13 -> V_33 . V_23 ) ;
break;
}
if ( V_15 )
F_9 ( V_15 ) ;
}
F_10 () ;
V_6 -> V_10 = V_7 ;
F_11 ( V_4 -> V_37 ) ;
return V_11 ;
}
static int F_12 ( struct V_38 * V_15 ,
const struct V_39 * V_40 )
{
int V_41 , V_42 , abs ;
struct V_3 * V_4 ;
struct V_14 * V_28 , * V_16 ;
V_4 = F_13 ( sizeof( * V_4 ) , V_43 ) ;
if ( ! V_4 ) {
F_14 ( V_15 , - V_44 , L_2 ) ;
return - V_44 ;
}
F_15 ( & V_15 -> V_15 , V_4 ) ;
V_4 -> V_45 = V_15 ;
V_4 -> V_37 = - 1 ;
V_4 -> V_46 = - 1 ;
snprintf ( V_4 -> V_47 , sizeof( V_4 -> V_47 ) , L_3 , V_15 -> V_48 ) ;
V_4 -> V_6 = ( void * ) F_16 ( V_43 | V_49 ) ;
if ( ! V_4 -> V_6 )
goto V_50;
if ( F_17 ( V_51 , V_15 -> V_52 , L_4 , L_5 , & abs ) < 0 )
abs = 0 ;
if ( abs )
F_18 ( V_51 , V_15 -> V_48 , L_6 , L_7 ) ;
V_28 = F_19 () ;
if ( ! V_28 )
goto V_50;
V_28 -> V_53 = L_8 ;
V_28 -> V_47 = V_4 -> V_47 ;
V_28 -> V_40 . V_54 = V_55 ;
V_28 -> V_40 . V_56 = 0x5853 ;
V_28 -> V_40 . V_57 = 0xffff ;
F_20 ( V_58 , V_28 -> V_59 ) ;
for ( V_42 = V_60 ; V_42 < V_61 ; V_42 ++ )
F_20 ( V_42 , V_28 -> V_29 ) ;
for ( V_42 = V_62 ; V_42 < V_63 ; V_42 ++ )
F_20 ( V_42 , V_28 -> V_29 ) ;
V_41 = F_21 ( V_28 ) ;
if ( V_41 ) {
F_22 ( V_28 ) ;
F_14 ( V_15 , V_41 , L_9 ) ;
goto error;
}
V_4 -> V_28 = V_28 ;
V_16 = F_19 () ;
if ( ! V_16 )
goto V_50;
V_16 -> V_53 = L_10 ;
V_16 -> V_47 = V_4 -> V_47 ;
V_16 -> V_40 . V_54 = V_55 ;
V_16 -> V_40 . V_56 = 0x5853 ;
V_16 -> V_40 . V_57 = 0xfffe ;
if ( abs ) {
F_20 ( V_64 , V_16 -> V_59 ) ;
F_23 ( V_16 , V_32 , 0 , V_65 , 0 , 0 ) ;
F_23 ( V_16 , V_35 , 0 , V_66 , 0 , 0 ) ;
} else {
F_24 ( V_16 , V_67 , V_18 ) ;
F_24 ( V_16 , V_67 , V_21 ) ;
}
F_24 ( V_16 , V_67 , V_24 ) ;
F_20 ( V_58 , V_16 -> V_59 ) ;
for ( V_42 = V_68 ; V_42 <= V_69 ; V_42 ++ )
F_20 ( V_42 , V_16 -> V_29 ) ;
V_41 = F_21 ( V_16 ) ;
if ( V_41 ) {
F_22 ( V_16 ) ;
F_14 ( V_15 , V_41 , L_11 ) ;
goto error;
}
V_4 -> V_16 = V_16 ;
V_41 = F_25 ( V_15 , V_4 ) ;
if ( V_41 < 0 )
goto error;
return 0 ;
V_50:
V_41 = - V_44 ;
F_14 ( V_15 , V_41 , L_12 ) ;
error:
F_26 ( V_15 ) ;
return V_41 ;
}
static int F_27 ( struct V_38 * V_15 )
{
struct V_3 * V_4 = F_28 ( & V_15 -> V_15 ) ;
F_29 ( V_4 ) ;
memset ( V_4 -> V_6 , 0 , V_70 ) ;
return F_25 ( V_15 , V_4 ) ;
}
static int F_26 ( struct V_38 * V_15 )
{
struct V_3 * V_4 = F_28 ( & V_15 -> V_15 ) ;
F_29 ( V_4 ) ;
if ( V_4 -> V_28 )
F_30 ( V_4 -> V_28 ) ;
if ( V_4 -> V_16 )
F_30 ( V_4 -> V_16 ) ;
F_31 ( ( unsigned long ) V_4 -> V_6 ) ;
F_32 ( V_4 ) ;
return 0 ;
}
static int F_25 ( struct V_38 * V_15 ,
struct V_3 * V_4 )
{
int V_41 , V_71 ;
struct V_72 V_73 ;
V_41 = F_33 ( V_15 -> V_74 ,
F_34 ( V_4 -> V_6 ) , 0 ) ;
if ( V_41 < 0 )
return V_41 ;
V_4 -> V_46 = V_41 ;
V_41 = F_35 ( V_15 , & V_71 ) ;
if ( V_41 )
goto V_75;
V_41 = F_36 ( V_71 , F_1 ,
0 , V_15 -> V_76 , V_4 ) ;
if ( V_41 < 0 ) {
F_14 ( V_15 , V_41 , L_13 ) ;
goto V_77;
}
V_4 -> V_37 = V_41 ;
V_78:
V_41 = F_37 ( & V_73 ) ;
if ( V_41 ) {
F_14 ( V_15 , V_41 , L_14 ) ;
goto V_79;
}
V_41 = F_18 ( V_73 , V_15 -> V_48 , L_15 , L_16 ,
F_34 ( V_4 -> V_6 ) ) ;
if ( V_41 )
goto V_80;
V_41 = F_18 ( V_73 , V_15 -> V_48 , L_17 , L_18 , V_4 -> V_46 ) ;
if ( V_41 )
goto V_80;
V_41 = F_18 ( V_73 , V_15 -> V_48 , L_19 , L_18 ,
V_71 ) ;
if ( V_41 )
goto V_80;
V_41 = F_38 ( V_73 , 0 ) ;
if ( V_41 ) {
if ( V_41 == - V_81 )
goto V_78;
F_14 ( V_15 , V_41 , L_20 ) ;
goto V_79;
}
F_39 ( V_15 , V_82 ) ;
return 0 ;
V_80:
F_38 ( V_73 , 1 ) ;
F_14 ( V_15 , V_41 , L_21 ) ;
V_79:
F_40 ( V_4 -> V_37 , V_4 ) ;
V_4 -> V_37 = - 1 ;
V_77:
F_41 ( V_15 , V_71 ) ;
V_75:
F_42 ( V_4 -> V_46 , 0 ) ;
V_4 -> V_46 = - 1 ;
return V_41 ;
}
static void F_29 ( struct V_3 * V_4 )
{
if ( V_4 -> V_37 >= 0 )
F_40 ( V_4 -> V_37 , V_4 ) ;
V_4 -> V_37 = - 1 ;
if ( V_4 -> V_46 >= 0 )
F_42 ( V_4 -> V_46 , 0 ) ;
V_4 -> V_46 = - 1 ;
}
static void F_43 ( struct V_38 * V_15 ,
enum V_83 V_84 )
{
struct V_3 * V_4 = F_28 ( & V_15 -> V_15 ) ;
int V_41 , V_85 ;
switch ( V_84 ) {
case V_86 :
case V_82 :
case V_87 :
case V_88 :
case V_89 :
break;
case V_90 :
V_91:
V_41 = F_17 ( V_51 , V_4 -> V_45 -> V_52 ,
L_4 , L_5 , & V_85 ) ;
if ( V_41 < 0 )
V_85 = 0 ;
if ( V_85 ) {
V_41 = F_18 ( V_51 , V_4 -> V_45 -> V_48 ,
L_6 , L_7 ) ;
if ( V_41 )
F_7 ( L_22 ) ;
}
F_39 ( V_15 , V_92 ) ;
break;
case V_92 :
if ( V_15 -> V_93 != V_92 )
goto V_91;
if ( F_17 ( V_51 , V_4 -> V_45 -> V_52 ,
L_23 , L_5 , & V_85 ) > 0 )
F_23 ( V_4 -> V_16 , V_32 , 0 , V_85 , 0 , 0 ) ;
if ( F_17 ( V_51 , V_4 -> V_45 -> V_52 ,
L_24 , L_5 , & V_85 ) > 0 )
F_23 ( V_4 -> V_16 , V_35 , 0 , V_85 , 0 , 0 ) ;
break;
case V_94 :
if ( V_15 -> V_93 == V_94 )
break;
case V_95 :
F_44 ( V_15 ) ;
break;
}
}
static int T_3 F_45 ( void )
{
if ( ! F_46 () )
return - V_96 ;
if ( F_47 () )
return - V_96 ;
return F_48 ( & V_97 ) ;
}
static void T_4 F_49 ( void )
{
F_50 ( & V_97 ) ;
}
