int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
unsigned long V_3 ;
unsigned int V_4 = F_2 ( V_1 ) ;
int V_5 = 0 ;
F_3 ( & V_6 , V_3 ) ;
if ( V_4 >= V_7 ) {
V_5 = - V_8 ;
goto V_9;
}
if ( V_10 [ V_4 ] ) {
V_5 = - V_11 ;
goto V_9;
}
V_10 [ V_4 ] ++ ;
V_9:
F_4 ( & V_6 , V_3 ) ;
return V_5 ;
}
int F_5 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
unsigned long V_3 ;
unsigned int V_4 = F_2 ( V_1 ) ;
int V_5 = 0 ;
F_3 ( & V_6 , V_3 ) ;
if ( V_4 >= V_7 ) {
V_5 = - V_8 ;
goto V_9;
}
V_10 [ V_4 ] = 0 ;
V_9:
F_4 ( & V_6 , V_3 ) ;
return V_5 ;
}
long F_6 ( struct V_2 * V_2 , unsigned int V_12 , unsigned long V_13 )
{
unsigned long V_3 ;
void T_1 * V_14 = ( void T_1 * ) V_13 ;
switch ( V_12 ) {
case V_15 :
{
struct V_16 V_17 ;
F_3 ( & V_6 , V_3 ) ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_18 = V_19 ;
sprintf ( V_17 . V_20 , L_1 , V_21 ) ;
F_4 ( & V_6 , V_3 ) ;
if ( F_7 ( V_14 , & V_17 , sizeof( V_17 ) ) )
return - V_22 ;
break;
}
case V_23 :
{
int V_24 ;
struct V_25 V_26 ;
if ( F_8 ( & V_24 , V_14 , sizeof( int ) ) )
return - V_22 ;
if ( V_24 < 0 || V_24 >= V_19 )
return - V_27 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_28 = V_24 ;
F_3 ( & V_29 [ V_24 ] -> V_30 , V_3 ) ;
V_26 . V_31 = V_29 [ V_24 ] -> V_32 ;
V_26 . V_33 = V_29 [ V_24 ] -> V_34 ;
V_26 . V_35 = 0 ;
V_26 . V_36 = ( V_37 ) V_29 [ V_24 ] -> V_38 ;
V_26 . V_39 = ( V_37 ) V_29 [ V_24 ] -> V_38
- V_29 [ V_24 ] -> V_40 ;
if ( V_29 [ V_24 ] -> V_41 != V_42 )
V_26 . V_43 = V_29 [ V_24 ] -> V_44 ;
else
V_26 . V_43 = 0 ;
F_4 ( & V_29 [ V_24 ] -> V_30 , V_3 ) ;
if ( F_7 ( V_14 , & V_26 , sizeof( V_26 ) ) )
return - V_22 ;
break;
}
case V_45 :
{
struct V_46 * V_47 ;
struct V_48 V_49 ;
unsigned char V_50 = 0 ;
T_2 V_51 = 0 ;
T_2 V_52 = 0 ;
if ( F_8 ( & V_49 , V_14 , sizeof( V_49 ) ) )
return - V_22 ;
V_51 = V_49 . V_51 ;
V_52 = V_49 . V_52 ;
if ( V_51 >= V_19 )
return - V_27 ;
if ( V_52 >= V_29 [ V_51 ] -> V_44 )
return - V_27 ;
V_47 = V_29 [ V_51 ] -> V_53 [ V_52 ] ;
if ( ! V_47 )
return - V_27 ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_51 = V_51 ;
V_49 . V_52 = V_52 ;
F_3 ( & V_47 -> V_54 , V_3 ) ;
V_50 = V_47 -> V_55 | V_47 -> V_56 ;
if ( V_50 & V_57 ) {
V_49 . V_50 |= V_58 ;
V_49 . V_59 = V_58 ;
}
if ( V_50 & V_60 ) {
V_49 . V_50 |= V_61 ;
V_49 . V_62 = V_61 ;
}
if ( V_50 & V_63 ) {
V_49 . V_50 |= V_64 ;
V_49 . V_65 = V_64 ;
}
if ( V_50 & V_66 ) {
V_49 . V_50 |= V_67 ;
V_49 . V_68 = V_67 ;
}
if ( V_50 & V_69 ) {
V_49 . V_50 |= V_70 ;
V_49 . V_71 = V_70 ;
}
if ( V_50 & V_72 )
V_49 . V_50 |= V_73 ;
V_49 . V_74 = V_47 -> V_75 ;
V_49 . V_76 = V_47 -> V_77 ;
V_49 . V_78 = V_47 -> V_79 ;
V_49 . V_80 = V_47 -> V_81 ;
if ( V_47 -> V_82 . V_83 & V_84 ||
V_47 -> V_79 & V_85 )
V_49 . V_86 = 1 ;
else
V_49 . V_86 = 0 ;
if ( ( V_47 -> V_87 & V_88 ) ||
( V_47 -> V_87 & V_89 ) )
V_49 . V_90 = 1 ;
else
V_49 . V_90 = 0 ;
if ( ( V_47 -> V_87 & V_91 ) || ( V_47 -> V_87 & V_92 ) )
V_49 . V_93 = 1 ;
else
V_49 . V_93 = 0 ;
V_49 . V_94 = V_47 -> V_95 ;
V_49 . V_96 = V_47 -> V_97 ;
V_49 . V_98 = V_47 -> V_99 ;
F_4 ( & V_47 -> V_54 , V_3 ) ;
if ( F_7 ( V_14 , & V_49 , sizeof( V_49 ) ) )
return - V_22 ;
break;
}
}
return 0 ;
}
