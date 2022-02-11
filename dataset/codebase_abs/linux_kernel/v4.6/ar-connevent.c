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
V_6 -> V_4 = V_4 ;
if ( V_3 == V_15 )
F_8 ( V_16 , & V_6 -> V_17 ) ;
else
F_8 ( V_18 , & V_6 -> V_17 ) ;
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
struct V_19 V_20 ;
struct V_21 V_22 ;
struct V_23 V_24 [ 2 ] ;
T_2 V_25 ;
T_3 V_26 ;
T_1 V_27 ;
int V_28 ;
F_2 ( L_3 , V_2 -> V_9 , error , V_4 ) ;
F_14 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_3 < V_29 ) {
V_2 -> V_3 = V_30 ;
V_2 -> error = error ;
F_15 ( & V_2 -> V_13 ) ;
} else {
F_15 ( & V_2 -> V_13 ) ;
F_12 ( L_4 ) ;
return 0 ;
}
F_1 ( V_2 , V_15 , V_4 ) ;
V_22 . V_31 = & V_2 -> V_32 -> V_33 -> V_34 . V_35 . sin ;
V_22 . V_36 = sizeof( V_2 -> V_32 -> V_33 -> V_34 . V_35 . sin ) ;
V_22 . V_37 = NULL ;
V_22 . V_38 = 0 ;
V_22 . V_39 = 0 ;
V_20 . V_40 = F_16 ( V_2 -> V_40 ) ;
V_20 . V_41 = F_16 ( V_2 -> V_41 ) ;
V_20 . V_42 = 0 ;
V_20 . V_43 = 0 ;
V_20 . type = V_44 ;
V_20 . V_45 = V_2 -> V_46 ;
V_20 . V_47 = 0 ;
V_20 . V_48 = V_2 -> V_49 ;
V_20 . V_50 = 0 ;
V_20 . V_51 = F_17 ( V_2 -> V_52 ) ;
V_25 = F_16 ( V_4 ) ;
V_24 [ 0 ] . V_53 = & V_20 ;
V_24 [ 0 ] . V_54 = sizeof( V_20 ) ;
V_24 [ 1 ] . V_53 = & V_25 ;
V_24 [ 1 ] . V_54 = sizeof( V_25 ) ;
V_26 = V_24 [ 0 ] . V_54 + V_24 [ 1 ] . V_54 ;
V_27 = F_18 ( & V_2 -> V_27 ) ;
V_20 . V_27 = F_16 ( V_27 ) ;
F_19 ( L_5 , V_27 , V_4 ) ;
V_28 = F_20 ( V_2 -> V_32 -> V_55 -> V_56 , & V_22 , V_24 , 2 , V_26 ) ;
if ( V_28 < 0 ) {
F_21 ( L_6 , V_28 ) ;
return - V_57 ;
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
! F_24 ( V_58 , & V_6 -> V_17 ) )
F_9 ( V_6 ) ;
F_25 ( & V_6 -> V_13 ) ;
}
}
static int F_26 ( struct V_1 * V_2 ,
struct V_59 * V_60 ,
T_1 * V_61 )
{
struct V_62 * V_63 = F_27 ( V_60 ) ;
T_2 V_64 ;
T_1 V_4 ;
int V_65 , V_28 ;
if ( V_2 -> V_3 >= V_29 ) {
F_28 ( L_9 , V_2 -> V_3 ) ;
return - V_66 ;
}
F_2 ( L_10 , V_2 -> V_9 , V_63 -> V_67 . type , V_63 -> V_67 . V_27 ) ;
switch ( V_63 -> V_67 . type ) {
case V_44 :
if ( F_29 ( V_60 , 0 , & V_64 , sizeof( V_64 ) ) < 0 )
return - V_68 ;
V_4 = F_30 ( V_64 ) ;
F_19 ( L_11 , V_63 -> V_67 . V_27 , V_4 ) ;
V_2 -> V_3 = V_29 ;
F_1 ( V_2 , V_69 ,
V_4 ) ;
return - V_66 ;
case V_70 :
if ( V_2 -> V_71 )
return V_2 -> V_71 -> V_72 (
V_2 , V_60 , V_61 ) ;
return - V_68 ;
case V_73 :
if ( ! V_2 -> V_71 )
return - V_68 ;
V_28 = V_2 -> V_71 -> V_74 ( V_2 , V_60 , V_61 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = V_2 -> V_71 -> V_75 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
V_2 -> V_71 -> V_76 ( V_2 ) ;
F_3 ( & V_2 -> V_10 ) ;
F_31 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_3 == V_77 ) {
V_2 -> V_3 = V_78 ;
for ( V_65 = 0 ; V_65 < V_79 ; V_65 ++ )
F_22 ( V_2 -> V_80 [ V_65 ] ) ;
}
F_32 ( & V_2 -> V_13 ) ;
F_11 ( & V_2 -> V_10 ) ;
return 0 ;
default:
F_12 ( L_12 , V_63 -> V_67 . type ) ;
return - V_68 ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_28 ;
F_2 ( L_13 , V_2 -> V_9 ) ;
ASSERT ( V_2 -> V_49 != 0 ) ;
if ( ! V_2 -> V_81 ) {
F_21 ( L_14 ) ;
V_28 = F_34 ( V_2 ) ;
switch ( V_28 ) {
case 0 :
break;
case - V_82 :
V_4 = V_83 ;
goto abort;
default:
V_4 = V_84 ;
goto abort;
}
}
ASSERT ( V_2 -> V_71 != NULL ) ;
if ( V_2 -> V_71 -> V_85 ( V_2 ) < 0 ) {
V_4 = V_83 ;
V_28 = - V_86 ;
goto abort;
}
F_12 ( L_2 ) ;
return;
abort:
F_21 ( L_15 , V_28 , V_4 ) ;
F_13 ( V_2 , - V_28 , V_4 ) ;
F_12 ( L_16 ) ;
}
void F_35 ( struct V_87 * V_88 )
{
struct V_1 * V_2 =
F_36 ( V_88 , struct V_1 , V_89 ) ;
struct V_59 * V_60 ;
T_1 V_4 = V_90 ;
int V_28 ;
F_2 ( L_13 , V_2 -> V_9 ) ;
F_37 ( & V_2 -> V_91 ) ;
if ( F_38 ( V_92 , & V_2 -> V_17 ) ) {
F_33 ( V_2 ) ;
F_39 ( V_2 ) ;
}
while ( ( V_60 = F_40 ( & V_2 -> V_93 ) ) ) {
V_28 = F_26 ( V_2 , V_60 , & V_4 ) ;
switch ( V_28 ) {
case - V_68 :
case - V_94 :
case - V_95 :
goto V_96;
case - V_57 :
goto V_97;
case - V_66 :
default:
F_39 ( V_2 ) ;
F_41 ( V_60 ) ;
break;
}
}
V_98:
F_39 ( V_2 ) ;
F_12 ( L_2 ) ;
return;
V_97:
F_42 ( & V_2 -> V_93 , V_60 ) ;
goto V_98;
V_96:
if ( F_13 ( V_2 , - V_28 , V_4 ) < 0 )
goto V_97;
F_39 ( V_2 ) ;
F_41 ( V_60 ) ;
F_12 ( L_17 ) ;
goto V_98;
}
void F_43 ( struct V_99 * V_55 , struct V_59 * V_60 )
{
F_44 ( & V_55 -> V_91 ) ;
if ( ! F_45 ( & V_55 -> V_91 ) ) {
F_46 ( L_18 ) ;
F_47 () ;
}
F_48 ( & V_55 -> V_100 , V_60 ) ;
F_49 ( & V_55 -> V_101 ) ;
}
void F_50 ( struct V_87 * V_88 )
{
union {
struct V_102 V_103 ;
struct V_104 sin ;
} V_103 ;
struct V_62 * V_63 ;
struct V_19 V_20 ;
struct V_99 * V_55 ;
struct V_59 * V_60 ;
struct V_21 V_22 ;
struct V_23 V_24 [ 2 ] ;
T_3 V_105 ;
T_2 V_106 ;
V_55 = F_36 ( V_88 , struct V_99 , V_101 ) ;
F_51 ( V_55 ) ;
F_2 ( L_19 , V_55 -> V_9 ) ;
V_24 [ 0 ] . V_53 = & V_20 ;
V_24 [ 0 ] . V_54 = sizeof( V_20 ) ;
V_24 [ 1 ] . V_53 = & V_106 ;
V_24 [ 1 ] . V_54 = sizeof( V_106 ) ;
V_105 = sizeof( V_20 ) + sizeof( V_106 ) ;
V_22 . V_31 = & V_103 ;
V_22 . V_37 = NULL ;
V_22 . V_38 = 0 ;
V_22 . V_39 = 0 ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_103 . V_103 . V_107 = V_55 -> V_34 . V_35 . V_108 ;
switch ( V_103 . V_103 . V_107 ) {
case V_109 :
V_22 . V_36 = sizeof( V_103 . sin ) ;
break;
default:
V_22 . V_36 = 0 ;
break;
}
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . type = V_44 ;
while ( ( V_60 = F_40 ( & V_55 -> V_100 ) ) ) {
V_63 = F_27 ( V_60 ) ;
switch ( V_103 . V_103 . V_107 ) {
case V_109 :
V_103 . sin . V_110 = F_52 ( V_60 ) -> V_111 ;
V_103 . sin . V_112 . V_113 = F_53 ( V_60 ) -> V_114 ;
V_106 = F_16 ( V_60 -> V_115 ) ;
V_20 . V_40 = F_16 ( V_63 -> V_67 . V_40 ) ;
V_20 . V_41 = F_16 ( V_63 -> V_67 . V_41 ) ;
V_20 . V_42 = F_16 ( V_63 -> V_67 . V_42 ) ;
V_20 . V_51 = F_17 ( V_63 -> V_67 . V_51 ) ;
V_20 . V_45 = V_63 -> V_67 . V_45 ;
V_20 . V_45 ^= V_116 ;
V_20 . V_45 &= V_116 ;
F_20 ( V_55 -> V_56 , & V_22 , V_24 , 2 , V_105 ) ;
break;
default:
break;
}
F_41 ( V_60 ) ;
F_54 ( V_55 ) ;
}
F_54 ( V_55 ) ;
F_12 ( L_2 ) ;
}
