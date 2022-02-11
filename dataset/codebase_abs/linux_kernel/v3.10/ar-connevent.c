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
int V_27 ;
F_2 ( L_3 , V_2 -> V_9 , error , V_4 ) ;
F_14 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_3 < V_28 ) {
V_2 -> V_3 = V_29 ;
V_2 -> error = error ;
F_15 ( & V_2 -> V_13 ) ;
} else {
F_15 ( & V_2 -> V_13 ) ;
F_12 ( L_4 ) ;
return 0 ;
}
F_1 ( V_2 , V_15 , V_4 ) ;
V_22 . V_30 = & V_2 -> V_31 -> V_32 -> V_33 . V_34 . sin ;
V_22 . V_35 = sizeof( V_2 -> V_31 -> V_32 -> V_33 . V_34 . sin ) ;
V_22 . V_36 = NULL ;
V_22 . V_37 = 0 ;
V_22 . V_38 = 0 ;
V_20 . V_39 = V_2 -> V_39 ;
V_20 . V_40 = V_2 -> V_40 ;
V_20 . V_41 = 0 ;
V_20 . V_42 = 0 ;
V_20 . type = V_43 ;
V_20 . V_44 = V_2 -> V_45 ;
V_20 . V_46 = 0 ;
V_20 . V_47 = V_2 -> V_48 ;
V_20 . V_49 = 0 ;
V_20 . V_50 = V_2 -> V_51 ;
V_25 = F_16 ( V_4 ) ;
V_24 [ 0 ] . V_52 = & V_20 ;
V_24 [ 0 ] . V_53 = sizeof( V_20 ) ;
V_24 [ 1 ] . V_52 = & V_25 ;
V_24 [ 1 ] . V_53 = sizeof( V_25 ) ;
V_26 = V_24 [ 0 ] . V_53 + V_24 [ 1 ] . V_53 ;
V_20 . V_54 = F_16 ( F_17 ( & V_2 -> V_54 ) ) ;
F_18 ( L_5 , F_19 ( V_20 . V_54 ) , V_4 ) ;
V_27 = F_20 ( V_2 -> V_31 -> V_55 -> V_56 , & V_22 , V_24 , 2 , V_26 ) ;
if ( V_27 < 0 ) {
F_21 ( L_6 , V_27 ) ;
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
T_1 V_54 ;
int V_65 , V_27 ;
if ( V_2 -> V_3 >= V_28 ) {
F_28 ( L_9 , V_2 -> V_3 ) ;
return - V_66 ;
}
V_54 = F_19 ( V_63 -> V_20 . V_54 ) ;
F_2 ( L_10 , V_2 -> V_9 , V_63 -> V_20 . type , V_54 ) ;
switch ( V_63 -> V_20 . type ) {
case V_43 :
if ( F_29 ( V_60 , 0 , & V_64 , sizeof( V_64 ) ) < 0 )
return - V_67 ;
F_18 ( L_11 , V_54 , F_19 ( V_64 ) ) ;
V_2 -> V_3 = V_28 ;
F_1 ( V_2 , V_68 ,
F_19 ( V_64 ) ) ;
return - V_66 ;
case V_69 :
if ( V_2 -> V_70 )
return V_2 -> V_70 -> V_71 (
V_2 , V_60 , V_61 ) ;
return - V_67 ;
case V_72 :
if ( ! V_2 -> V_70 )
return - V_67 ;
V_27 = V_2 -> V_70 -> V_73 ( V_2 , V_60 , V_61 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = V_2 -> V_70 -> V_74 ( V_2 ) ;
if ( V_27 < 0 )
return V_27 ;
V_2 -> V_70 -> V_75 ( V_2 ) ;
F_3 ( & V_2 -> V_10 ) ;
F_30 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_3 == V_76 ) {
V_2 -> V_3 = V_77 ;
for ( V_65 = 0 ; V_65 < V_78 ; V_65 ++ )
F_22 ( V_2 -> V_79 [ V_65 ] ) ;
}
F_31 ( & V_2 -> V_13 ) ;
F_11 ( & V_2 -> V_10 ) ;
return 0 ;
default:
F_12 ( L_12 , V_63 -> V_20 . type ) ;
return - V_67 ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_27 ;
F_2 ( L_13 , V_2 -> V_9 ) ;
ASSERT ( V_2 -> V_48 != 0 ) ;
if ( ! V_2 -> V_80 ) {
F_21 ( L_14 ) ;
V_27 = F_33 ( V_2 ) ;
switch ( V_27 ) {
case 0 :
break;
case - V_81 :
V_4 = V_82 ;
goto abort;
default:
V_4 = V_83 ;
goto abort;
}
}
ASSERT ( V_2 -> V_70 != NULL ) ;
if ( V_2 -> V_70 -> V_84 ( V_2 ) < 0 ) {
V_4 = V_82 ;
V_27 = - V_85 ;
goto abort;
}
F_12 ( L_2 ) ;
return;
abort:
F_21 ( L_15 , V_27 , V_4 ) ;
F_13 ( V_2 , - V_27 , V_4 ) ;
F_12 ( L_16 ) ;
}
void F_34 ( struct V_86 * V_87 )
{
struct V_1 * V_2 =
F_35 ( V_87 , struct V_1 , V_88 ) ;
struct V_59 * V_60 ;
T_1 V_4 = V_89 ;
int V_27 ;
F_2 ( L_13 , V_2 -> V_9 ) ;
F_36 ( & V_2 -> V_90 ) ;
if ( F_37 ( V_91 , & V_2 -> V_17 ) ) {
F_32 ( V_2 ) ;
F_38 ( V_2 ) ;
}
while ( ( V_60 = F_39 ( & V_2 -> V_92 ) ) ) {
V_27 = F_26 ( V_2 , V_60 , & V_4 ) ;
switch ( V_27 ) {
case - V_67 :
case - V_93 :
case - V_94 :
goto V_95;
case - V_57 :
goto V_96;
case - V_66 :
default:
F_38 ( V_2 ) ;
F_40 ( V_60 ) ;
break;
}
}
V_97:
F_38 ( V_2 ) ;
F_12 ( L_2 ) ;
return;
V_96:
F_41 ( & V_2 -> V_92 , V_60 ) ;
goto V_97;
V_95:
if ( F_13 ( V_2 , - V_27 , V_4 ) < 0 )
goto V_96;
F_38 ( V_2 ) ;
F_40 ( V_60 ) ;
F_12 ( L_17 ) ;
goto V_97;
}
void F_42 ( struct V_98 * V_55 , struct V_59 * V_60 )
{
F_43 ( & V_55 -> V_90 ) ;
if ( ! F_44 ( & V_55 -> V_90 ) ) {
F_45 ( L_18 ) ;
F_46 () ;
}
F_47 ( & V_55 -> V_99 , V_60 ) ;
F_48 ( & V_55 -> V_100 ) ;
}
void F_49 ( struct V_86 * V_87 )
{
union {
struct V_101 V_102 ;
struct V_103 sin ;
} V_102 ;
struct V_62 * V_63 ;
struct V_19 V_20 ;
struct V_98 * V_55 ;
struct V_59 * V_60 ;
struct V_21 V_22 ;
struct V_23 V_24 [ 2 ] ;
T_3 V_104 ;
T_2 V_105 ;
V_55 = F_35 ( V_87 , struct V_98 , V_100 ) ;
F_50 ( V_55 ) ;
F_2 ( L_19 , V_55 -> V_9 ) ;
V_24 [ 0 ] . V_52 = & V_20 ;
V_24 [ 0 ] . V_53 = sizeof( V_20 ) ;
V_24 [ 1 ] . V_52 = & V_105 ;
V_24 [ 1 ] . V_53 = sizeof( V_105 ) ;
V_104 = sizeof( V_20 ) + sizeof( V_105 ) ;
V_22 . V_30 = & V_102 ;
V_22 . V_36 = NULL ;
V_22 . V_37 = 0 ;
V_22 . V_38 = 0 ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_102 . V_106 = V_55 -> V_33 . V_34 . V_107 ;
switch ( V_102 . V_102 . V_106 ) {
case V_108 :
V_22 . V_35 = sizeof( V_102 . sin ) ;
break;
default:
V_22 . V_35 = 0 ;
break;
}
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . type = V_43 ;
while ( ( V_60 = F_39 ( & V_55 -> V_99 ) ) ) {
V_63 = F_27 ( V_60 ) ;
switch ( V_102 . V_102 . V_106 ) {
case V_108 :
V_102 . sin . V_109 = F_51 ( V_60 ) -> V_110 ;
V_102 . sin . V_111 . V_112 = F_52 ( V_60 ) -> V_113 ;
V_105 = F_16 ( V_60 -> V_114 ) ;
V_20 . V_39 = V_63 -> V_20 . V_39 ;
V_20 . V_40 = V_63 -> V_20 . V_40 ;
V_20 . V_41 = V_63 -> V_20 . V_41 ;
V_20 . V_50 = V_63 -> V_20 . V_50 ;
V_20 . V_44 = V_63 -> V_20 . V_44 ;
V_20 . V_44 ^= V_115 ;
V_20 . V_44 &= V_115 ;
F_20 ( V_55 -> V_56 , & V_22 , V_24 , 2 , V_104 ) ;
break;
default:
break;
}
F_40 ( V_60 ) ;
F_53 ( V_55 ) ;
}
F_53 ( V_55 ) ;
F_12 ( L_2 ) ;
}
