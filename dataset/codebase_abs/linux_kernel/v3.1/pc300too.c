static void F_1 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_2 ;
T_3 T_4 * V_3 = & V_2 -> V_4 -> V_3 ;
T_5 V_5 = F_2 ( V_1 ) ;
T_6 V_6 = V_1 -> V_6 & V_7 ;
T_6 V_8 = V_1 -> V_8 & V_7 ;
F_3 ( V_9 , ( V_1 -> V_10 ? V_11 : V_12 ) + V_13 ,
V_1 -> V_2 ) ;
switch( V_1 -> V_14 . V_15 ) {
case V_16 :
V_6 |= V_17 ;
V_8 |= V_18 | V_19 ;
break;
case V_20 :
V_6 |= V_21 ;
V_8 |= V_18 | V_17 ;
break;
case V_22 :
V_6 |= V_21 ;
V_8 |= V_18 | V_19 ;
break;
default:
V_6 |= V_21 ;
V_8 |= V_18 | V_21 ;
break;
}
V_1 -> V_6 = V_6 ;
V_1 -> V_8 = V_8 ;
F_3 ( V_6 , V_5 + V_23 , V_2 ) ;
F_3 ( V_8 , V_5 + V_24 , V_2 ) ;
F_4 ( V_1 ) ;
if ( V_1 -> V_2 -> type == V_25 ) {
if ( V_1 -> V_26 == V_27 )
F_5 ( V_2 -> V_28 |
F_6 ( V_1 -> V_10 ) , V_3 ) ;
else
F_5 ( V_2 -> V_28 &
~ F_6 ( V_1 -> V_10 ) , V_3 ) ;
}
}
static int F_7 ( struct V_29 * V_30 )
{
T_1 * V_1 = F_8 ( V_30 ) ;
int V_31 = F_9 ( V_30 ) ;
if ( V_31 )
return V_31 ;
F_10 ( V_30 ) ;
F_1 ( V_1 ) ;
return 0 ;
}
static int F_11 ( struct V_29 * V_30 )
{
F_12 ( V_30 ) ;
F_13 ( V_30 ) ;
return 0 ;
}
static int F_14 ( struct V_29 * V_30 , struct V_32 * V_33 , int V_34 )
{
const T_7 V_35 = sizeof( V_36 ) ;
V_36 V_37 ;
V_36 T_8 * line = V_33 -> V_38 . V_39 . V_40 ;
int V_41 ;
T_1 * V_1 = F_8 ( V_30 ) ;
#ifdef F_15
if ( V_34 == V_42 ) {
F_16 ( V_30 ) ;
return 0 ;
}
#endif
if ( V_34 != V_43 )
return F_17 ( V_30 , V_33 , V_34 ) ;
if ( V_33 -> V_38 . type == V_44 ) {
V_33 -> V_38 . type = V_1 -> V_26 ;
if ( V_33 -> V_38 . V_35 < V_35 ) {
V_33 -> V_38 . V_35 = V_35 ;
return - V_45 ;
}
if ( F_18 ( line , & V_1 -> V_14 , V_35 ) )
return - V_46 ;
return 0 ;
}
if ( V_1 -> V_2 -> type == V_47 &&
( V_33 -> V_38 . type == V_48 ||
V_33 -> V_38 . type == V_49 ) )
V_41 = V_49 ;
else if ( V_1 -> V_2 -> type == V_25 &&
( V_33 -> V_38 . type == V_48 ||
V_33 -> V_38 . type == V_27 ) )
V_41 = V_27 ;
else if ( V_1 -> V_2 -> type == V_25 &&
V_33 -> V_38 . type == V_50 )
V_41 = V_50 ;
else
return F_17 ( V_30 , V_33 , V_34 ) ;
if ( ! F_19 ( V_51 ) )
return - V_52 ;
if ( F_20 ( & V_37 , line , V_35 ) )
return - V_46 ;
if ( V_37 . V_15 != V_53 &&
V_37 . V_15 != V_22 &&
V_37 . V_15 != V_16 &&
V_37 . V_15 != V_20 )
return - V_54 ;
if ( V_37 . V_55 != 0 && V_37 . V_55 != 1 )
return - V_54 ;
memcpy ( & V_1 -> V_14 , & V_37 , V_35 ) ;
V_1 -> V_26 = V_41 ;
F_1 ( V_1 ) ;
return 0 ;
}
static void F_21 ( struct V_56 * V_57 )
{
int V_58 ;
T_2 * V_2 = F_22 ( V_57 ) ;
for ( V_58 = 0 ; V_58 < 2 ; V_58 ++ )
if ( V_2 -> V_59 [ V_58 ] . V_2 )
F_23 ( V_2 -> V_59 [ V_58 ] . V_60 ) ;
if ( V_2 -> V_61 )
F_24 ( V_2 -> V_61 , V_2 ) ;
if ( V_2 -> V_62 )
F_25 ( V_2 -> V_62 ) ;
if ( V_2 -> V_63 )
F_25 ( V_2 -> V_63 ) ;
if ( V_2 -> V_4 )
F_25 ( V_2 -> V_4 ) ;
F_26 ( V_57 ) ;
F_27 ( V_57 ) ;
F_28 ( V_57 , NULL ) ;
if ( V_2 -> V_59 [ 0 ] . V_60 )
F_29 ( V_2 -> V_59 [ 0 ] . V_60 ) ;
if ( V_2 -> V_59 [ 1 ] . V_60 )
F_29 ( V_2 -> V_59 [ 1 ] . V_60 ) ;
F_30 ( V_2 ) ;
}
static int T_9 F_31 ( struct V_56 * V_57 ,
const struct V_64 * V_65 )
{
T_2 * V_2 ;
T_3 T_4 * V_66 ;
int V_58 ;
T_3 V_67 ;
T_3 V_68 ;
T_3 V_69 ;
T_3 V_70 ;
V_58 = F_32 ( V_57 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_33 ( V_57 , L_1 ) ;
if ( V_58 ) {
F_27 ( V_57 ) ;
return V_58 ;
}
V_2 = F_34 ( sizeof( T_2 ) , V_71 ) ;
if ( V_2 == NULL ) {
F_35 ( L_2 ) ;
F_26 ( V_57 ) ;
F_27 ( V_57 ) ;
return - V_45 ;
}
F_28 ( V_57 , V_2 ) ;
if ( F_36 ( V_57 , 0 ) != V_72 ||
F_36 ( V_57 , 2 ) != V_73 ||
F_36 ( V_57 , 3 ) < 16384 ) {
F_35 ( L_3 ) ;
F_21 ( V_57 ) ;
return - V_46 ;
}
V_70 = F_37 ( V_57 , 0 ) & V_74 ;
V_2 -> V_4 = F_38 ( V_70 , V_72 ) ;
V_69 = F_37 ( V_57 , 2 ) & V_74 ;
V_2 -> V_63 = F_38 ( V_69 , V_73 ) ;
V_68 = F_37 ( V_57 , 3 ) & V_74 ;
V_2 -> V_62 = F_39 ( V_57 , 3 ) ;
if ( V_2 -> V_4 == NULL ||
V_2 -> V_63 == NULL ||
V_2 -> V_62 == NULL ) {
F_35 ( L_4 ) ;
F_21 ( V_57 ) ;
}
F_40 ( V_57 , V_75 , V_69 ) ;
V_2 -> V_28 = F_41 ( & ( ( V_76 T_4 * ) V_2 -> V_63 ) -> V_3 ) ;
F_40 ( V_57 , V_75 , V_70 ) ;
if ( V_57 -> V_77 == V_78 ||
V_57 -> V_77 == V_79 )
V_2 -> type = V_80 ;
else if ( V_2 -> V_28 & V_81 )
V_2 -> type = V_47 ;
else
V_2 -> type = V_25 ;
if ( V_57 -> V_77 == V_82 ||
V_57 -> V_77 == V_78 )
V_2 -> V_83 = 1 ;
else
V_2 -> V_83 = 2 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_83 ; V_58 ++ )
if ( ! ( V_2 -> V_59 [ V_58 ] . V_60 = F_42 ( & V_2 -> V_59 [ V_58 ] ) ) ) {
F_35 ( L_2 ) ;
F_21 ( V_57 ) ;
return - V_84 ;
}
V_66 = & V_2 -> V_4 -> V_3 ;
F_5 ( V_2 -> V_28 | 0x40000000 , V_66 ) ;
F_41 ( V_66 ) ;
F_43 ( 1 ) ;
F_5 ( V_2 -> V_28 , V_66 ) ;
F_41 ( V_66 ) ;
F_43 ( 1 ) ;
F_5 ( V_2 -> V_28 | 0x20000000 , V_66 ) ;
F_41 ( V_66 ) ;
F_43 ( 1 ) ;
F_5 ( V_2 -> V_28 , V_66 ) ;
F_41 ( V_66 ) ;
F_43 ( 1 ) ;
V_67 = F_44 ( V_2 , V_2 -> V_62 ,
F_36 ( V_57 , 3 ) ) ;
if ( V_85 )
V_2 -> V_28 &= ~ V_86 ;
else
V_2 -> V_28 |= V_86 ;
F_5 ( V_2 -> V_28 , & V_2 -> V_4 -> V_3 ) ;
V_58 = V_67 / ( V_2 -> V_83 * ( sizeof( V_87 ) + V_88 ) ) ;
V_2 -> V_89 = F_45 ( V_58 / 2 , V_90 ) ;
V_2 -> V_91 = V_58 - V_2 -> V_89 ;
V_2 -> V_92 = V_2 -> V_83 * sizeof( V_87 ) *
( V_2 -> V_89 + V_2 -> V_91 ) ;
F_46 ( L_5 ,
V_2 -> type == V_47 ? L_6 :
V_2 -> type == V_80 ? L_7 : L_8 ,
V_67 / 1024 , V_68 , V_57 -> V_61 ,
V_2 -> V_89 , V_2 -> V_91 ) ;
if ( V_2 -> V_89 < 1 ) {
F_35 ( L_9 ) ;
F_21 ( V_57 ) ;
return - V_46 ;
}
F_47 ( 0x0041 , & V_2 -> V_4 -> V_93 ) ;
if ( F_48 ( V_57 -> V_61 , V_94 , V_95 , L_10 , V_2 ) ) {
F_49 ( L_11 , V_57 -> V_61 ) ;
F_21 ( V_57 ) ;
return - V_96 ;
}
V_2 -> V_61 = V_57 -> V_61 ;
F_50 ( V_2 , 0 ) ;
F_3 ( 0x10 , V_97 , V_2 ) ;
for ( V_58 = 0 ; V_58 < V_2 -> V_83 ; V_58 ++ ) {
T_1 * V_1 = & V_2 -> V_59 [ V_58 ] ;
struct V_29 * V_30 = V_1 -> V_60 ;
T_10 * V_98 = F_51 ( V_30 ) ;
V_1 -> V_10 = V_58 ;
F_52 ( & V_1 -> V_99 ) ;
V_30 -> V_61 = V_2 -> V_61 ;
V_30 -> V_100 = V_68 ;
V_30 -> V_101 = V_68 + V_67 - 1 ;
V_30 -> V_102 = 50 ;
V_30 -> V_103 = & V_104 ;
V_98 -> V_105 = V_106 ;
V_98 -> V_107 = V_108 ;
V_1 -> V_14 . V_15 = V_53 ;
V_1 -> V_2 = V_2 ;
if ( V_2 -> type == V_47 )
V_1 -> V_26 = V_49 ;
else
V_1 -> V_26 = V_27 ;
F_53 ( V_1 ) ;
if ( F_54 ( V_30 ) ) {
F_35 ( L_12 ) ;
V_1 -> V_2 = NULL ;
F_21 ( V_57 ) ;
return - V_45 ;
}
F_55 ( V_30 , L_13 , V_1 -> V_10 ) ;
}
return 0 ;
}
static int T_11 F_56 ( void )
{
if ( V_109 < 1000000 || V_109 > 80000000 ) {
F_35 ( L_14 ) ;
return - V_54 ;
}
if ( V_85 != 0 && V_85 != 1 ) {
F_35 ( L_15 ) ;
return - V_54 ;
}
V_110 = V_85 ? 24576000 : V_109 ;
return F_57 ( & V_111 ) ;
}
static void T_12 F_58 ( void )
{
F_59 ( & V_111 ) ;
}
