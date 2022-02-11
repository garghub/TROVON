static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_2 -> V_4 + 0x40 ) ;
return ! ( V_3 & ( 1 << V_2 -> V_5 ) ) ;
}
static int F_3 ( struct V_6 * V_7 )
{
return 0 ;
}
static void F_4 ( unsigned long V_8 )
{
struct V_1 * V_2 = ( void * ) V_8 ;
int V_9 = F_1 ( V_2 ) ;
if ( V_9 != V_2 -> V_9 ) {
V_2 -> V_9 = V_9 ;
F_5 ( & V_2 -> V_10 , V_11 ) ;
}
if ( V_2 -> V_12 )
F_6 ( & V_2 -> V_13 , V_14 + V_15 ) ;
}
static T_1 F_7 ( int V_16 , void * V_8 )
{
F_4 ( ( unsigned long ) V_8 ) ;
return V_17 ;
}
static int F_8 ( struct V_6 * V_7 , T_2 * V_18 )
{
struct V_1 * V_2 ;
if ( ! V_18 )
return - V_19 ;
V_2 = F_9 ( V_7 , struct V_1 , V_10 ) ;
if ( F_1 ( V_2 ) ) {
* V_18 = V_20 | V_11 | V_21 | V_22 ;
V_7 -> V_23 = V_2 -> V_16 ;
} else
* V_18 = 0 ;
return 0 ;
}
static int F_10 ( struct V_6 * V_24 ,
struct V_25 * V_7 )
{
unsigned int V_3 ;
unsigned int V_26 ;
struct V_1 * V_2 ;
V_2 = F_9 ( V_24 , struct V_1 , V_10 ) ;
V_26 = ( V_7 -> V_27 & V_28 ) ? 0 : V_7 -> V_29 ;
switch ( V_26 ) {
case 0 :
V_3 = 0 ;
break;
case 33 :
V_3 = ( 1 << V_2 -> V_30 ) ;
break;
case 5 :
V_3 = ( 1 << V_2 -> V_31 ) ;
break;
default:
return - V_19 ;
}
V_3 |= 1 << ( V_2 -> V_30 + 16 ) ;
V_3 |= 1 << ( V_2 -> V_31 + 16 ) ;
F_11 ( V_2 -> V_4 + 0x90 , V_3 ) ;
F_12 ( L_1 ,
V_32 , V_7 -> V_29 , V_7 -> V_33 , V_7 -> V_27 , V_7 -> V_34 ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_35 * V_36 )
{
return 0 ;
}
static int F_14 ( struct V_6 * V_7 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 ;
if ( V_38 -> V_39 )
return - V_19 ;
V_2 = F_9 ( V_7 , struct V_1 , V_10 ) ;
V_38 -> V_40 = V_2 -> V_41 ;
V_38 -> V_27 &= V_42 | V_43 ;
if ( ! ( V_38 -> V_27 & V_43 ) )
V_38 -> V_40 += 0x800 ;
return 0 ;
}
static int F_15 ( struct V_44 * V_45 )
{
struct V_46 * V_46 = & V_45 -> V_47 ;
struct V_48 * V_49 = V_45 -> V_47 . V_50 ;
struct V_1 * V_2 ;
struct V_51 V_52 , V_36 ;
int V_53 ;
const unsigned int * V_54 ;
int V_55 ;
struct V_56 * V_57 ;
V_55 = F_16 ( V_49 , 0 , & V_52 ) ;
if ( V_55 )
return - V_19 ;
V_55 = F_16 ( V_49 , 1 , & V_36 ) ;
if ( V_55 )
return - V_19 ;
V_2 = F_17 ( sizeof( * V_2 ) , V_58 ) ;
if ( ! V_2 )
return - V_59 ;
F_18 ( & V_2 -> V_13 , F_4 , ( unsigned long ) V_2 ) ;
V_2 -> V_16 = 0 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_41 = V_52 . V_60 ;
V_2 -> V_61 = F_19 ( F_20 ( & V_52 ) ) ;
V_2 -> V_62 = F_21 ( V_2 -> V_41 , V_2 -> V_61 ) ;
V_2 -> V_63 = F_19 ( F_20 ( & V_36 ) ) ;
V_57 = F_22 ( V_2 -> V_63 , 0 , V_64 , V_65 ) ;
if ( V_57 == NULL ) {
V_53 = - V_59 ;
goto V_66;
}
V_2 -> V_67 = ( void V_68 * ) ( V_57 -> V_69 ) ;
V_2 -> V_4 = F_21 ( 0xfc103000 , 0x1000 ) ;
F_23 ( V_46 , V_2 ) ;
if ( ! V_2 -> V_62 || ! V_2 -> V_67 || ! V_2 -> V_4 ||
( F_24 ( V_36 . V_60 , V_2 -> V_67 , V_2 -> V_63 ,
F_25 ( F_26 ( F_27 ( 0 ) ) ) ) == NULL ) ) {
F_28 ( V_46 , L_2 ) ;
V_53 = - V_59 ;
goto V_66;
}
V_2 -> V_70 = ( unsigned long ) V_2 -> V_67 - V_71 ;
V_2 -> V_72 . V_60 = ( unsigned long ) V_2 -> V_62 ;
V_2 -> V_72 . V_73 = ( unsigned long ) V_2 -> V_62 + ( V_52 . V_73 - V_52 . V_60 ) ;
V_2 -> V_72 . V_27 = V_74 ;
V_2 -> V_16 = F_29 ( V_49 , 0 ) ;
V_53 = F_30 ( V_2 -> V_16 , F_7 , V_75 ,
V_32 , V_2 ) ;
if ( V_53 < 0 ) {
F_28 ( V_46 , L_3 ) ;
goto V_66;
}
V_2 -> V_10 . V_23 = V_2 -> V_16 ;
V_54 = F_31 ( V_49 , L_4 , NULL ) ;
if ( ! V_54 )
goto V_66;
V_2 -> V_5 = * V_54 ;
V_54 = F_31 ( V_49 , L_5 , NULL ) ;
if ( ! V_54 )
goto V_66;
V_2 -> V_76 = * V_54 ;
V_54 = F_31 ( V_49 , L_6 , NULL ) ;
if ( ! V_54 )
goto V_66;
V_2 -> V_30 = * V_54 ;
V_54 = F_31 ( V_49 , L_7 , NULL ) ;
if ( ! V_54 )
goto V_66;
V_2 -> V_31 = * V_54 ;
V_2 -> V_10 . V_77 = V_2 -> V_70 ;
if ( ! F_32 ( V_2 -> V_41 , V_2 -> V_61 , V_32 ) ) {
V_53 = - V_78 ;
F_28 ( V_46 , L_8 ) ;
goto V_66;
}
if ( ! F_33 ( V_2 -> V_70 , V_2 -> V_63 , V_32 ) ) {
V_53 = - V_78 ;
F_28 ( V_46 , L_9 ) ;
goto V_79;
}
V_2 -> V_10 . V_80 = V_81 ;
V_2 -> V_10 . V_47 . V_82 = & V_45 -> V_47 ;
V_2 -> V_10 . V_83 = & V_84 ;
V_2 -> V_10 . V_85 = & V_86 ;
V_2 -> V_10 . V_87 = V_88 | V_89 |
V_90 ;
V_2 -> V_10 . V_91 = 0x800 ;
V_53 = F_34 ( & V_2 -> V_10 ) ;
if ( V_53 < 0 ) {
F_28 ( V_46 , L_10 ) ;
goto V_92;
}
F_35 ( V_46 , L_11 ,
V_2 -> V_41 , V_36 . V_60 , V_2 -> V_16 ) ;
V_2 -> V_12 = 1 ;
F_4 ( ( unsigned long ) V_2 ) ;
return 0 ;
V_92:
F_36 ( V_2 -> V_70 , V_2 -> V_63 ) ;
V_79:
F_37 ( V_2 -> V_41 , V_2 -> V_61 ) ;
V_66:
if ( V_2 -> V_16 )
F_38 ( V_2 -> V_16 , V_2 ) ;
if ( V_2 -> V_67 )
F_39 ( V_2 -> V_67 , V_2 -> V_63 ) ;
if ( V_2 -> V_62 )
F_40 ( V_2 -> V_62 ) ;
if ( V_2 -> V_4 )
F_40 ( V_2 -> V_4 ) ;
if ( V_57 )
F_41 ( & V_45 -> V_47 , 0 ) ;
F_42 ( V_2 ) ;
return V_53 ;
}
static int F_43 ( struct V_44 * V_45 )
{
struct V_46 * V_46 = & V_45 -> V_47 ;
struct V_1 * V_2 ;
V_2 = F_44 ( V_46 ) ;
V_2 -> V_12 = 0 ;
F_45 ( & V_2 -> V_10 ) ;
F_38 ( V_2 -> V_16 , V_2 ) ;
F_46 ( & V_2 -> V_13 ) ;
F_39 ( V_2 -> V_67 , V_2 -> V_63 ) ;
F_40 ( V_2 -> V_62 ) ;
F_40 ( V_2 -> V_4 ) ;
F_37 ( V_2 -> V_41 , V_2 -> V_61 ) ;
F_36 ( V_2 -> V_70 , V_2 -> V_63 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
