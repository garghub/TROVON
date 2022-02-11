static void F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
F_2 ( L_1 , V_2 -> V_9 , V_4 ) ;
F_3 ( & V_2 -> V_10 ) ;
for ( V_8 = F_4 ( & V_2 -> V_11 ) ; V_8 ; V_8 = F_5 ( V_8 ) ) {
V_6 = F_6 ( V_8 , struct V_5 , V_12 ) ;
F_7 ( & V_6 -> V_13 ) ;
if ( V_6 -> V_3 <= V_14 ) {
V_6 -> V_3 = V_3 ;
if ( V_3 == V_15 ) {
V_6 -> V_16 = V_2 -> V_16 ;
F_8 ( V_17 , & V_6 -> V_18 ) ;
} else {
V_6 -> V_19 = V_2 -> V_19 ;
F_8 ( V_20 , & V_6 -> V_18 ) ;
}
F_9 ( V_6 ) ;
}
F_10 ( & V_6 -> V_13 ) ;
}
F_11 ( & V_2 -> V_10 ) ;
F_12 ( L_2 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
T_1 error , T_1 V_4 )
{
struct V_21 V_22 ;
struct V_23 V_24 ;
struct V_25 V_26 [ 2 ] ;
T_2 V_27 ;
T_3 V_28 ;
T_1 V_29 ;
int V_30 ;
F_2 ( L_3 , V_2 -> V_9 , error , V_4 ) ;
F_14 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_3 < V_31 ) {
V_2 -> V_3 = V_32 ;
V_2 -> error = error ;
F_15 ( & V_2 -> V_13 ) ;
} else {
F_15 ( & V_2 -> V_13 ) ;
F_12 ( L_4 ) ;
return 0 ;
}
F_1 ( V_2 , V_15 , V_4 ) ;
V_24 . V_33 = & V_2 -> V_34 -> V_35 -> V_36 . V_37 ;
V_24 . V_38 = V_2 -> V_34 -> V_35 -> V_36 . V_39 ;
V_24 . V_40 = NULL ;
V_24 . V_41 = 0 ;
V_24 . V_42 = 0 ;
V_22 . V_43 = F_16 ( V_2 -> V_43 ) ;
V_22 . V_44 = F_16 ( V_2 -> V_44 ) ;
V_22 . V_45 = 0 ;
V_22 . V_46 = 0 ;
V_22 . type = V_47 ;
V_22 . V_48 = V_2 -> V_49 ;
V_22 . V_50 = 0 ;
V_22 . V_51 = V_2 -> V_52 ;
V_22 . V_53 = 0 ;
V_22 . V_54 = F_17 ( V_2 -> V_55 ) ;
V_27 = F_16 ( V_2 -> V_16 ) ;
V_26 [ 0 ] . V_56 = & V_22 ;
V_26 [ 0 ] . V_57 = sizeof( V_22 ) ;
V_26 [ 1 ] . V_56 = & V_27 ;
V_26 [ 1 ] . V_57 = sizeof( V_27 ) ;
V_28 = V_26 [ 0 ] . V_57 + V_26 [ 1 ] . V_57 ;
V_29 = F_18 ( & V_2 -> V_29 ) ;
V_22 . V_29 = F_16 ( V_29 ) ;
F_19 ( L_5 , V_29 , V_2 -> V_16 ) ;
V_30 = F_20 ( V_2 -> V_34 -> V_58 -> V_59 , & V_24 , V_26 , 2 , V_28 ) ;
if ( V_30 < 0 ) {
F_21 ( L_6 , V_30 ) ;
return - V_60 ;
}
F_12 ( L_7 ) ;
return 0 ;
}
static void F_22 ( struct V_5 * V_6 )
{
F_2 ( L_8 , V_6 ) ;
if ( V_6 ) {
F_23 ( & V_6 -> V_13 ) ;
if ( V_6 -> V_3 < V_14 &&
! F_24 ( V_61 , & V_6 -> V_18 ) )
F_9 ( V_6 ) ;
F_25 ( & V_6 -> V_13 ) ;
}
}
static int F_26 ( struct V_1 * V_2 ,
struct V_62 * V_63 ,
T_1 * V_64 )
{
struct V_65 * V_66 = F_27 ( V_63 ) ;
T_2 V_67 ;
T_1 V_4 ;
int V_68 , V_30 ;
if ( V_2 -> V_3 >= V_31 ) {
F_28 ( L_9 , V_2 -> V_3 ) ;
return - V_69 ;
}
F_2 ( L_10 , V_2 -> V_9 , V_66 -> V_70 . type , V_66 -> V_70 . V_29 ) ;
switch ( V_66 -> V_70 . type ) {
case V_47 :
if ( F_29 ( V_63 , 0 , & V_67 , sizeof( V_67 ) ) < 0 )
return - V_71 ;
V_4 = F_30 ( V_67 ) ;
F_19 ( L_11 , V_66 -> V_70 . V_29 , V_4 ) ;
V_2 -> V_3 = V_31 ;
F_1 ( V_2 , V_72 ,
V_4 ) ;
return - V_69 ;
case V_73 :
return V_2 -> V_74 -> V_75 ( V_2 , V_63 ,
V_64 ) ;
case V_76 :
V_30 = V_2 -> V_74 -> V_77 ( V_2 , V_63 , V_64 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = V_2 -> V_74 -> V_78 ( V_2 ) ;
if ( V_30 < 0 )
return V_30 ;
V_2 -> V_74 -> V_79 ( V_2 ) ;
F_3 ( & V_2 -> V_10 ) ;
F_31 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_3 == V_80 ) {
V_2 -> V_3 = V_81 ;
for ( V_68 = 0 ; V_68 < V_82 ; V_68 ++ )
F_22 ( V_2 -> V_83 [ V_68 ] ) ;
}
F_32 ( & V_2 -> V_13 ) ;
F_11 ( & V_2 -> V_10 ) ;
return 0 ;
default:
F_12 ( L_12 , V_66 -> V_70 . type ) ;
return - V_71 ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_30 ;
F_2 ( L_13 , V_2 -> V_9 ) ;
ASSERT ( V_2 -> V_52 != 0 ) ;
if ( ! V_2 -> V_84 ) {
F_21 ( L_14 ) ;
V_30 = F_34 ( V_2 ) ;
switch ( V_30 ) {
case 0 :
break;
case - V_85 :
V_4 = V_86 ;
goto abort;
default:
V_4 = V_87 ;
goto abort;
}
}
if ( V_2 -> V_74 -> V_88 ( V_2 ) < 0 ) {
V_4 = V_86 ;
V_30 = - V_89 ;
goto abort;
}
F_12 ( L_2 ) ;
return;
abort:
F_21 ( L_15 , V_30 , V_4 ) ;
F_13 ( V_2 , - V_30 , V_4 ) ;
F_12 ( L_16 ) ;
}
void F_35 ( struct V_90 * V_91 )
{
struct V_1 * V_2 =
F_36 ( V_91 , struct V_1 , V_92 ) ;
struct V_62 * V_63 ;
T_1 V_4 = V_93 ;
int V_30 ;
F_2 ( L_13 , V_2 -> V_9 ) ;
F_37 ( & V_2 -> V_94 ) ;
if ( F_38 ( V_95 , & V_2 -> V_18 ) ) {
F_33 ( V_2 ) ;
F_39 ( V_2 ) ;
}
while ( ( V_63 = F_40 ( & V_2 -> V_96 ) ) ) {
V_30 = F_26 ( V_2 , V_63 , & V_4 ) ;
switch ( V_30 ) {
case - V_71 :
case - V_97 :
case - V_98 :
goto V_99;
case - V_60 :
goto V_100;
case - V_69 :
default:
F_39 ( V_2 ) ;
F_41 ( V_63 ) ;
break;
}
}
V_101:
F_39 ( V_2 ) ;
F_12 ( L_2 ) ;
return;
V_100:
F_42 ( & V_2 -> V_96 , V_63 ) ;
goto V_101;
V_99:
if ( F_13 ( V_2 , - V_30 , V_4 ) < 0 )
goto V_100;
F_39 ( V_2 ) ;
F_41 ( V_63 ) ;
F_12 ( L_17 ) ;
goto V_101;
}
void F_43 ( struct V_102 * V_58 , struct V_62 * V_63 )
{
F_44 ( & V_58 -> V_94 ) ;
if ( ! F_45 ( & V_58 -> V_94 ) ) {
F_46 ( L_18 ) ;
F_47 () ;
}
F_48 ( & V_58 -> V_103 , V_63 ) ;
F_49 ( & V_58 -> V_104 ) ;
}
void F_50 ( struct V_90 * V_91 )
{
union {
struct V_105 V_106 ;
struct V_107 sin ;
} V_106 ;
struct V_65 * V_66 ;
struct V_21 V_22 ;
struct V_102 * V_58 ;
struct V_62 * V_63 ;
struct V_23 V_24 ;
struct V_25 V_26 [ 2 ] ;
T_3 V_108 ;
T_2 V_109 ;
V_58 = F_36 ( V_91 , struct V_102 , V_104 ) ;
F_51 ( V_58 ) ;
F_2 ( L_19 , V_58 -> V_9 ) ;
V_26 [ 0 ] . V_56 = & V_22 ;
V_26 [ 0 ] . V_57 = sizeof( V_22 ) ;
V_26 [ 1 ] . V_56 = & V_109 ;
V_26 [ 1 ] . V_57 = sizeof( V_109 ) ;
V_108 = sizeof( V_22 ) + sizeof( V_109 ) ;
V_24 . V_33 = & V_106 ;
V_24 . V_40 = NULL ;
V_24 . V_41 = 0 ;
V_24 . V_42 = 0 ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_106 . V_106 . V_110 = V_58 -> V_36 . V_37 . V_111 ;
switch ( V_106 . V_106 . V_110 ) {
case V_112 :
V_24 . V_38 = sizeof( V_106 . sin ) ;
break;
default:
V_24 . V_38 = 0 ;
break;
}
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . type = V_47 ;
while ( ( V_63 = F_40 ( & V_58 -> V_103 ) ) ) {
V_66 = F_27 ( V_63 ) ;
switch ( V_106 . V_106 . V_110 ) {
case V_112 :
V_106 . sin . V_113 = F_52 ( V_63 ) -> V_114 ;
V_106 . sin . V_115 . V_116 = F_53 ( V_63 ) -> V_117 ;
V_109 = F_16 ( V_63 -> V_118 ) ;
V_22 . V_43 = F_16 ( V_66 -> V_70 . V_43 ) ;
V_22 . V_44 = F_16 ( V_66 -> V_70 . V_44 ) ;
V_22 . V_45 = F_16 ( V_66 -> V_70 . V_45 ) ;
V_22 . V_54 = F_17 ( V_66 -> V_70 . V_54 ) ;
V_22 . V_48 = V_66 -> V_70 . V_48 ;
V_22 . V_48 ^= V_119 ;
V_22 . V_48 &= V_119 ;
F_20 ( V_58 -> V_59 , & V_24 , V_26 , 2 , V_108 ) ;
break;
default:
break;
}
F_41 ( V_63 ) ;
F_54 ( V_58 ) ;
}
F_54 ( V_58 ) ;
F_12 ( L_2 ) ;
}
