static void F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
F_2 ( L_1 , V_2 -> V_8 , V_4 ) ;
F_3 ( & V_2 -> V_9 ) ;
for ( V_7 = 0 ; V_7 < V_10 ; V_7 ++ ) {
V_6 = F_4 (
V_2 -> V_11 [ V_7 ] . V_6 ,
F_5 ( & V_2 -> V_9 ) ) ;
F_6 ( & V_6 -> V_12 ) ;
if ( V_6 -> V_3 <= V_13 ) {
V_6 -> V_3 = V_3 ;
if ( V_3 == V_14 ) {
V_6 -> V_15 = V_2 -> V_15 ;
F_7 ( V_16 , & V_6 -> V_17 ) ;
} else {
V_6 -> V_18 = V_2 -> V_18 ;
F_7 ( V_19 , & V_6 -> V_17 ) ;
}
F_8 ( V_6 ) ;
}
F_9 ( & V_6 -> V_12 ) ;
}
F_10 ( & V_2 -> V_9 ) ;
F_11 ( L_2 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 error , T_1 V_4 )
{
struct V_20 V_21 ;
struct V_22 V_23 ;
struct V_24 V_25 [ 2 ] ;
T_2 V_26 ;
T_3 V_27 ;
T_1 V_28 ;
int V_29 ;
F_2 ( L_3 , V_2 -> V_8 , error , V_4 ) ;
F_13 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_3 < V_30 ) {
V_2 -> V_3 = V_31 ;
V_2 -> error = error ;
F_14 ( & V_2 -> V_12 ) ;
} else {
F_14 ( & V_2 -> V_12 ) ;
F_11 ( L_4 ) ;
return 0 ;
}
F_1 ( V_2 , V_14 , V_4 ) ;
V_23 . V_32 = & V_2 -> V_33 . V_34 -> V_35 . V_36 ;
V_23 . V_37 = V_2 -> V_33 . V_34 -> V_35 . V_38 ;
V_23 . V_39 = NULL ;
V_23 . V_40 = 0 ;
V_23 . V_41 = 0 ;
V_21 . V_42 = F_15 ( V_2 -> V_43 . V_42 ) ;
V_21 . V_44 = F_15 ( V_2 -> V_43 . V_44 ) ;
V_21 . V_45 = 0 ;
V_21 . V_46 = 0 ;
V_21 . type = V_47 ;
V_21 . V_48 = V_2 -> V_49 ;
V_21 . V_50 = 0 ;
V_21 . V_51 = V_2 -> V_52 ;
V_21 . V_53 = 0 ;
V_21 . V_54 = F_16 ( V_2 -> V_33 . V_55 ) ;
V_26 = F_15 ( V_2 -> V_15 ) ;
V_25 [ 0 ] . V_56 = & V_21 ;
V_25 [ 0 ] . V_57 = sizeof( V_21 ) ;
V_25 [ 1 ] . V_56 = & V_26 ;
V_25 [ 1 ] . V_57 = sizeof( V_26 ) ;
V_27 = V_25 [ 0 ] . V_57 + V_25 [ 1 ] . V_57 ;
V_28 = F_17 ( & V_2 -> V_28 ) ;
V_21 . V_28 = F_15 ( V_28 ) ;
F_18 ( L_5 , V_28 , V_2 -> V_15 ) ;
V_29 = F_19 ( V_2 -> V_33 . V_58 -> V_59 , & V_23 , V_25 , 2 , V_27 ) ;
if ( V_29 < 0 ) {
F_20 ( L_6 , V_29 ) ;
return - V_60 ;
}
F_11 ( L_7 ) ;
return 0 ;
}
static void F_21 ( struct V_5 * V_6 )
{
F_2 ( L_8 , V_6 ) ;
if ( V_6 ) {
F_22 ( & V_6 -> V_12 ) ;
if ( V_6 -> V_3 < V_13 &&
! F_23 ( V_61 , & V_6 -> V_17 ) )
F_8 ( V_6 ) ;
F_24 ( & V_6 -> V_12 ) ;
}
}
static int F_25 ( struct V_1 * V_2 ,
struct V_62 * V_63 ,
T_1 * V_64 )
{
struct V_65 * V_66 = F_26 ( V_63 ) ;
T_2 V_67 ;
T_1 V_4 ;
int V_68 , V_29 ;
if ( V_2 -> V_3 >= V_30 ) {
F_27 ( L_9 , V_2 -> V_3 ) ;
return - V_69 ;
}
F_2 ( L_10 , V_2 -> V_8 , V_66 -> V_70 . type , V_66 -> V_70 . V_28 ) ;
switch ( V_66 -> V_70 . type ) {
case V_47 :
if ( F_28 ( V_63 , 0 , & V_67 , sizeof( V_67 ) ) < 0 )
return - V_71 ;
V_4 = F_29 ( V_67 ) ;
F_18 ( L_11 , V_66 -> V_70 . V_28 , V_4 ) ;
V_2 -> V_3 = V_30 ;
F_1 ( V_2 , V_72 ,
V_4 ) ;
return - V_69 ;
case V_73 :
return V_2 -> V_74 -> V_75 ( V_2 , V_63 ,
V_64 ) ;
case V_76 :
V_29 = V_2 -> V_74 -> V_77 ( V_2 , V_63 , V_64 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = V_2 -> V_74 -> V_78 ( V_2 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = V_2 -> V_74 -> V_79 ( V_2 ) ;
if ( V_29 < 0 )
return V_29 ;
F_3 ( & V_2 -> V_9 ) ;
F_3 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_3 == V_80 ) {
V_2 -> V_3 = V_81 ;
for ( V_68 = 0 ; V_68 < V_10 ; V_68 ++ )
F_21 (
F_4 (
V_2 -> V_11 [ V_68 ] . V_6 ,
F_5 ( & V_2 -> V_9 ) ) ) ;
}
F_10 ( & V_2 -> V_12 ) ;
F_10 ( & V_2 -> V_9 ) ;
return 0 ;
default:
F_11 ( L_12 , V_66 -> V_70 . type ) ;
return - V_71 ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_29 ;
F_2 ( L_13 , V_2 -> V_8 ) ;
ASSERT ( V_2 -> V_52 != 0 ) ;
if ( ! V_2 -> V_33 . V_82 ) {
F_20 ( L_14 ) ;
V_29 = F_31 ( V_2 ) ;
switch ( V_29 ) {
case 0 :
break;
case - V_83 :
V_4 = V_84 ;
goto abort;
default:
V_4 = V_85 ;
goto abort;
}
}
if ( V_2 -> V_74 -> V_86 ( V_2 ) < 0 ) {
V_4 = V_84 ;
V_29 = - V_87 ;
goto abort;
}
F_11 ( L_2 ) ;
return;
abort:
F_20 ( L_15 , V_29 , V_4 ) ;
F_12 ( V_2 , - V_29 , V_4 ) ;
F_11 ( L_16 ) ;
}
void F_32 ( struct V_88 * V_89 )
{
struct V_1 * V_2 =
F_33 ( V_89 , struct V_1 , V_90 ) ;
struct V_62 * V_63 ;
T_1 V_4 = V_91 ;
int V_29 ;
F_2 ( L_13 , V_2 -> V_8 ) ;
if ( F_34 ( V_92 , & V_2 -> V_17 ) )
F_30 ( V_2 ) ;
while ( ( V_63 = F_35 ( & V_2 -> V_93 ) ) ) {
V_29 = F_25 ( V_2 , V_63 , & V_4 ) ;
switch ( V_29 ) {
case - V_71 :
case - V_94 :
case - V_95 :
goto V_96;
case - V_60 :
goto V_97;
case - V_69 :
default:
F_36 ( V_63 ) ;
break;
}
}
V_98:
F_37 ( V_2 ) ;
F_11 ( L_2 ) ;
return;
V_97:
F_38 ( & V_2 -> V_93 , V_63 ) ;
goto V_98;
V_96:
if ( F_12 ( V_2 , - V_29 , V_4 ) < 0 )
goto V_97;
F_36 ( V_63 ) ;
F_11 ( L_17 ) ;
goto V_98;
}
void F_39 ( struct V_99 * V_58 , struct V_62 * V_63 )
{
F_40 ( & V_58 -> V_100 ) ;
F_41 ( & V_58 -> V_101 , V_63 ) ;
F_42 ( V_58 ) ;
}
void F_43 ( struct V_99 * V_58 )
{
union {
struct V_102 V_103 ;
struct V_104 sin ;
} V_103 ;
struct V_65 * V_66 ;
struct V_20 V_21 ;
struct V_62 * V_63 ;
struct V_22 V_23 ;
struct V_24 V_25 [ 2 ] ;
T_3 V_105 ;
T_2 V_106 ;
F_2 ( L_18 , V_58 -> V_8 ) ;
V_25 [ 0 ] . V_56 = & V_21 ;
V_25 [ 0 ] . V_57 = sizeof( V_21 ) ;
V_25 [ 1 ] . V_56 = & V_106 ;
V_25 [ 1 ] . V_57 = sizeof( V_106 ) ;
V_105 = sizeof( V_21 ) + sizeof( V_106 ) ;
V_23 . V_32 = & V_103 ;
V_23 . V_39 = NULL ;
V_23 . V_40 = 0 ;
V_23 . V_41 = 0 ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_103 . V_103 . V_107 = V_58 -> V_35 . V_36 . V_108 ;
switch ( V_103 . V_103 . V_107 ) {
case V_109 :
V_23 . V_37 = sizeof( V_103 . sin ) ;
break;
default:
V_23 . V_37 = 0 ;
break;
}
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . type = V_47 ;
while ( ( V_63 = F_35 ( & V_58 -> V_101 ) ) ) {
V_66 = F_26 ( V_63 ) ;
switch ( V_103 . V_103 . V_107 ) {
case V_109 :
V_103 . sin . V_110 = F_44 ( V_63 ) -> V_111 ;
V_103 . sin . V_112 . V_113 = F_45 ( V_63 ) -> V_114 ;
V_106 = F_15 ( V_63 -> V_115 ) ;
V_21 . V_42 = F_15 ( V_66 -> V_70 . V_42 ) ;
V_21 . V_44 = F_15 ( V_66 -> V_70 . V_44 ) ;
V_21 . V_45 = F_15 ( V_66 -> V_70 . V_45 ) ;
V_21 . V_54 = F_16 ( V_66 -> V_70 . V_54 ) ;
V_21 . V_48 = V_66 -> V_70 . V_48 ;
V_21 . V_48 ^= V_116 ;
V_21 . V_48 &= V_116 ;
F_19 ( V_58 -> V_59 , & V_23 , V_25 , 2 , V_105 ) ;
break;
default:
break;
}
F_36 ( V_63 ) ;
}
F_11 ( L_2 ) ;
}
