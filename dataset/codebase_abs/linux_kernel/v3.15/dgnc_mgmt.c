int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
unsigned long V_3 ;
unsigned int V_4 = F_2 ( V_1 ) ;
F_3 ( ( L_1 ) ) ;
F_4 ( V_5 , V_3 ) ;
if ( V_4 < V_6 ) {
if ( V_7 [ V_4 ] ) {
F_5 ( V_5 , V_3 ) ;
return - V_8 ;
}
V_7 [ V_4 ] ++ ;
} else {
F_5 ( V_5 , V_3 ) ;
return - V_9 ;
}
F_5 ( V_5 , V_3 ) ;
F_3 ( ( L_2 ) ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
unsigned long V_3 ;
unsigned int V_4 = F_2 ( V_1 ) ;
F_3 ( ( L_3 ) ) ;
F_4 ( V_5 , V_3 ) ;
if ( V_4 < V_6 ) {
if ( V_7 [ V_4 ] )
V_7 [ V_4 ] = 0 ;
}
F_5 ( V_5 , V_3 ) ;
F_3 ( ( L_4 ) ) ;
return 0 ;
}
long F_7 ( struct V_2 * V_2 , unsigned int V_10 , unsigned long V_11 )
{
unsigned long V_3 ;
void T_1 * V_12 = ( void T_1 * ) V_11 ;
F_3 ( ( L_5 ) ) ;
switch ( V_10 ) {
case V_13 :
{
struct V_14 V_15 ;
F_4 ( V_5 , V_3 ) ;
V_15 . V_16 = V_17 ;
sprintf ( V_15 . V_18 , L_6 , V_19 ) ;
F_5 ( V_5 , V_3 ) ;
F_3 ( ( L_7 ,
V_15 . V_16 , V_15 . V_18 ) ) ;
if ( F_8 ( V_12 , & V_15 , sizeof( V_15 ) ) )
return - V_20 ;
break;
}
case V_21 :
{
int V_22 ;
struct V_23 V_24 ;
if ( F_9 ( & V_22 , V_12 , sizeof( int ) ) )
return - V_20 ;
F_3 ( ( L_8 , V_22 ) ) ;
if ( ( V_22 < 0 ) || ( V_22 > V_17 ) ||
( V_17 == 0 ) )
return - V_25 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_26 = V_22 ;
F_4 ( V_27 [ V_22 ] -> V_28 , V_3 ) ;
V_24 . V_29 = V_27 [ V_22 ] -> V_30 ;
V_24 . V_31 = V_27 [ V_22 ] -> V_32 ;
V_24 . V_33 = 0 ;
V_24 . V_34 = ( V_35 ) V_27 [ V_22 ] -> V_36 ;
V_24 . V_37 = ( V_35 ) V_27 [ V_22 ] -> V_36 - V_27 [ V_22 ] -> V_38 ;
if ( V_27 [ V_22 ] -> V_39 != V_40 )
V_24 . V_41 = V_27 [ V_22 ] -> V_42 ;
else
V_24 . V_41 = 0 ;
F_5 ( V_27 [ V_22 ] -> V_28 , V_3 ) ;
F_3 ( ( L_9 ,
V_24 . V_29 , V_24 . V_31 , V_24 . V_41 , V_24 . V_37 ) ) ;
if ( F_8 ( V_12 , & V_24 , sizeof( V_24 ) ) )
return - V_20 ;
break;
}
case V_43 :
{
struct V_44 * V_45 ;
struct V_46 V_47 ;
T_2 V_48 = 0 ;
T_3 V_49 = 0 ;
T_3 V_50 = 0 ;
if ( F_9 ( & V_47 , V_12 , sizeof( V_47 ) ) )
return - V_20 ;
F_3 ( ( L_10 ,
V_47 . V_49 , V_47 . V_50 ) ) ;
V_49 = V_47 . V_49 ;
V_50 = V_47 . V_50 ;
if ( ( V_49 > V_17 ) || ( V_17 == 0 ) )
return - V_25 ;
if ( ( V_50 < 0 ) || ( V_50 > V_27 [ V_49 ] -> V_42 ) )
return - V_25 ;
V_45 = V_27 [ V_49 ] -> V_51 [ V_50 ] ;
if ( ! V_45 || V_45 -> V_52 != V_53 )
return - V_25 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_49 = V_49 ;
V_47 . V_50 = V_50 ;
F_4 ( V_45 -> V_54 , V_3 ) ;
V_48 = ( V_45 -> V_55 | V_45 -> V_56 ) ;
if ( V_48 & V_57 ) {
V_47 . V_48 |= V_58 ;
V_47 . V_59 = V_58 ;
}
if ( V_48 & V_60 ) {
V_47 . V_48 |= V_61 ;
V_47 . V_62 = V_61 ;
}
if ( V_48 & V_63 ) {
V_47 . V_48 |= V_64 ;
V_47 . V_65 = V_64 ;
}
if ( V_48 & V_66 ) {
V_47 . V_48 |= V_67 ;
V_47 . V_68 = V_67 ;
}
if ( V_48 & V_69 ) {
V_47 . V_48 |= V_70 ;
V_47 . V_71 = V_70 ;
}
if ( V_48 & V_72 )
V_47 . V_48 |= V_73 ;
V_47 . V_74 = V_45 -> V_75 ;
V_47 . V_76 = V_45 -> V_77 ;
V_47 . V_78 = V_45 -> V_79 ;
V_47 . V_80 = V_45 -> V_81 ;
if ( V_45 -> V_82 . V_83 & V_84 ||
V_45 -> V_79 & V_85 )
V_47 . V_86 = 1 ;
else
V_47 . V_86 = 0 ;
if ( ( V_45 -> V_87 & V_88 ) ||
( V_45 -> V_87 & V_89 ) )
V_47 . V_90 = 1 ;
else
V_47 . V_90 = 0 ;
if ( ( V_45 -> V_87 & V_91 ) || ( V_45 -> V_87 & V_92 ) )
V_47 . V_93 = 1 ;
else
V_47 . V_93 = 0 ;
V_47 . V_94 = V_45 -> V_95 ;
V_47 . V_96 = V_45 -> V_97 ;
V_47 . V_98 = V_45 -> V_99 ;
F_5 ( V_45 -> V_54 , V_3 ) ;
if ( F_8 ( V_12 , & V_47 , sizeof( V_47 ) ) )
return - V_20 ;
break;
}
}
F_3 ( ( L_11 ) ) ;
return 0 ;
}
