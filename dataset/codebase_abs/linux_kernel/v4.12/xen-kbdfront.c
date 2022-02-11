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
int V_41 , V_42 ;
unsigned int abs ;
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
abs = F_17 ( V_15 -> V_51 , L_4 , 0 ) ;
V_52 [ V_53 ] = F_17 ( V_15 -> V_51 , L_5 ,
V_52 [ V_53 ] ) ;
V_52 [ V_54 ] = F_17 ( V_15 -> V_51 , L_6 ,
V_52 [ V_54 ] ) ;
if ( abs ) {
V_41 = F_18 ( V_55 , V_15 -> V_48 ,
L_7 , L_8 ) ;
if ( V_41 ) {
F_7 ( L_9 ) ;
abs = 0 ;
}
}
V_28 = F_19 () ;
if ( ! V_28 )
goto V_50;
V_28 -> V_56 = L_10 ;
V_28 -> V_47 = V_4 -> V_47 ;
V_28 -> V_40 . V_57 = V_58 ;
V_28 -> V_40 . V_59 = 0x5853 ;
V_28 -> V_40 . V_60 = 0xffff ;
F_20 ( V_61 , V_28 -> V_62 ) ;
for ( V_42 = V_63 ; V_42 < V_64 ; V_42 ++ )
F_20 ( V_42 , V_28 -> V_29 ) ;
for ( V_42 = V_65 ; V_42 < V_66 ; V_42 ++ )
F_20 ( V_42 , V_28 -> V_29 ) ;
V_41 = F_21 ( V_28 ) ;
if ( V_41 ) {
F_22 ( V_28 ) ;
F_14 ( V_15 , V_41 , L_11 ) ;
goto error;
}
V_4 -> V_28 = V_28 ;
V_16 = F_19 () ;
if ( ! V_16 )
goto V_50;
V_16 -> V_56 = L_12 ;
V_16 -> V_47 = V_4 -> V_47 ;
V_16 -> V_40 . V_57 = V_58 ;
V_16 -> V_40 . V_59 = 0x5853 ;
V_16 -> V_40 . V_60 = 0xfffe ;
if ( abs ) {
F_20 ( V_67 , V_16 -> V_62 ) ;
F_23 ( V_16 , V_32 , 0 , V_52 [ V_53 ] , 0 , 0 ) ;
F_23 ( V_16 , V_35 , 0 , V_52 [ V_54 ] , 0 , 0 ) ;
} else {
F_24 ( V_16 , V_68 , V_18 ) ;
F_24 ( V_16 , V_68 , V_21 ) ;
}
F_24 ( V_16 , V_68 , V_24 ) ;
F_20 ( V_61 , V_16 -> V_62 ) ;
for ( V_42 = V_69 ; V_42 <= V_70 ; V_42 ++ )
F_20 ( V_42 , V_16 -> V_29 ) ;
V_41 = F_21 ( V_16 ) ;
if ( V_41 ) {
F_22 ( V_16 ) ;
F_14 ( V_15 , V_41 , L_13 ) ;
goto error;
}
V_4 -> V_16 = V_16 ;
V_41 = F_25 ( V_15 , V_4 ) ;
if ( V_41 < 0 )
goto error;
return 0 ;
V_50:
V_41 = - V_44 ;
F_14 ( V_15 , V_41 , L_14 ) ;
error:
F_26 ( V_15 ) ;
return V_41 ;
}
static int F_27 ( struct V_38 * V_15 )
{
struct V_3 * V_4 = F_28 ( & V_15 -> V_15 ) ;
F_29 ( V_4 ) ;
memset ( V_4 -> V_6 , 0 , V_71 ) ;
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
int V_41 , V_72 ;
struct V_73 V_74 ;
V_41 = F_33 ( V_15 -> V_75 ,
F_34 ( V_4 -> V_6 ) , 0 ) ;
if ( V_41 < 0 )
return V_41 ;
V_4 -> V_46 = V_41 ;
V_41 = F_35 ( V_15 , & V_72 ) ;
if ( V_41 )
goto V_76;
V_41 = F_36 ( V_72 , F_1 ,
0 , V_15 -> V_77 , V_4 ) ;
if ( V_41 < 0 ) {
F_14 ( V_15 , V_41 , L_15 ) ;
goto V_78;
}
V_4 -> V_37 = V_41 ;
V_79:
V_41 = F_37 ( & V_74 ) ;
if ( V_41 ) {
F_14 ( V_15 , V_41 , L_16 ) ;
goto V_80;
}
V_41 = F_38 ( V_74 , V_15 -> V_48 , L_17 , L_18 ,
F_34 ( V_4 -> V_6 ) ) ;
if ( V_41 )
goto V_81;
V_41 = F_38 ( V_74 , V_15 -> V_48 , L_19 , L_20 , V_4 -> V_46 ) ;
if ( V_41 )
goto V_81;
V_41 = F_38 ( V_74 , V_15 -> V_48 , L_21 , L_20 ,
V_72 ) ;
if ( V_41 )
goto V_81;
V_41 = F_39 ( V_74 , 0 ) ;
if ( V_41 ) {
if ( V_41 == - V_82 )
goto V_79;
F_14 ( V_15 , V_41 , L_22 ) ;
goto V_80;
}
F_40 ( V_15 , V_83 ) ;
return 0 ;
V_81:
F_39 ( V_74 , 1 ) ;
F_14 ( V_15 , V_41 , L_23 ) ;
V_80:
F_41 ( V_4 -> V_37 , V_4 ) ;
V_4 -> V_37 = - 1 ;
V_78:
F_42 ( V_15 , V_72 ) ;
V_76:
F_43 ( V_4 -> V_46 , 0 , 0UL ) ;
V_4 -> V_46 = - 1 ;
return V_41 ;
}
static void F_29 ( struct V_3 * V_4 )
{
if ( V_4 -> V_37 >= 0 )
F_41 ( V_4 -> V_37 , V_4 ) ;
V_4 -> V_37 = - 1 ;
if ( V_4 -> V_46 >= 0 )
F_43 ( V_4 -> V_46 , 0 , 0UL ) ;
V_4 -> V_46 = - 1 ;
}
static void F_44 ( struct V_38 * V_15 ,
enum V_84 V_85 )
{
switch ( V_85 ) {
case V_86 :
case V_83 :
case V_87 :
case V_88 :
case V_89 :
break;
case V_90 :
F_40 ( V_15 , V_91 ) ;
break;
case V_91 :
if ( V_15 -> V_92 != V_91 )
F_40 ( V_15 , V_91 ) ;
break;
case V_93 :
if ( V_15 -> V_92 == V_93 )
break;
case V_94 :
F_45 ( V_15 ) ;
break;
}
}
static int T_3 F_46 ( void )
{
if ( ! F_47 () )
return - V_95 ;
if ( F_48 () )
return - V_95 ;
if ( ! F_49 () )
return - V_95 ;
return F_50 ( & V_96 ) ;
}
static void T_4 F_51 ( void )
{
F_52 ( & V_96 ) ;
}
