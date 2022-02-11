static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 V_8 ;
struct V_9 V_10 [ 1 ] ;
T_1 V_11 ;
int V_12 ;
F_2 ( L_1 , V_2 -> V_13 ) ;
V_8 . V_14 = & V_4 -> V_15 . sin ;
V_8 . V_16 = sizeof( V_4 -> V_15 . sin ) ;
V_8 . V_17 = NULL ;
V_8 . V_18 = 0 ;
V_8 . V_19 = 0 ;
V_6 -> V_20 = 0 ;
V_6 -> type = V_21 ;
V_6 -> V_22 = 0 ;
V_6 -> V_23 = 0 ;
V_6 -> V_24 = 0 ;
V_10 [ 0 ] . V_25 = V_6 ;
V_10 [ 0 ] . V_26 = sizeof( * V_6 ) ;
V_11 = V_10 [ 0 ] . V_26 ;
V_6 -> V_27 = F_3 ( 1 ) ;
F_4 ( L_2 , F_5 ( V_6 -> V_27 ) ) ;
V_12 = F_6 ( V_2 -> V_28 , & V_8 , V_10 , 1 , V_11 ) ;
if ( V_12 < 0 ) {
F_7 ( L_3 , V_12 ) ;
return - V_29 ;
}
F_7 ( L_4 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
struct V_3 * V_4 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 , * V_40 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_32 * V_45 ;
int V_12 ;
F_2 ( L_5 ) ;
V_39 = F_9 ( V_33 ) ;
V_45 = F_10 ( 0 , V_46 ) ;
if ( ! V_45 ) {
F_11 ( L_6 ) ;
V_12 = - V_47 ;
goto V_48;
}
F_12 ( V_45 ) ;
V_45 -> V_49 = V_50 ;
V_42 = F_13 ( V_4 , V_51 ) ;
if ( F_14 ( V_42 ) ) {
F_11 ( L_7 ) ;
V_12 = - V_52 ;
goto error;
}
V_37 = F_15 ( V_2 , V_42 , V_51 ) ;
F_16 ( V_42 ) ;
if ( F_14 ( V_37 ) ) {
F_11 ( L_8 ) ;
V_12 = - V_52 ;
goto error;
}
V_35 = F_17 ( V_37 , & V_39 -> V_6 , V_51 ) ;
F_18 ( V_37 ) ;
if ( F_14 ( V_35 ) ) {
F_11 ( L_9 ) ;
V_12 = F_19 ( V_35 ) ;
goto error;
}
V_44 = F_20 ( V_31 , V_35 , & V_39 -> V_6 , V_51 ) ;
F_21 ( V_35 ) ;
if ( F_14 ( V_44 ) ) {
F_11 ( L_10 ) ;
V_12 = F_19 ( V_44 ) ;
goto error;
}
F_22 ( & V_2 -> V_53 ) ;
if ( V_31 -> V_54 . V_55 == V_56 )
goto V_57;
F_23 ( & V_31 -> V_58 ) ;
if ( ! F_24 ( V_59 , & V_44 -> V_22 ) ) {
F_25 ( V_44 ) ;
F_26 ( & V_44 -> V_35 -> V_60 ) ;
if ( V_39 -> V_6 . V_61 > 0 &&
V_44 -> V_35 -> V_62 == V_63 ) {
F_11 ( L_11 ) ;
F_27 ( & V_44 -> V_64 , & V_31 -> V_65 ) ;
V_44 -> V_35 -> V_62 = V_66 ;
F_28 ( & V_44 -> V_35 -> V_67 ) ;
F_29 ( V_68 , & V_44 -> V_35 -> V_69 ) ;
F_30 ( V_44 -> V_35 ) ;
} else {
F_11 ( L_12 ) ;
V_44 -> V_62 = V_70 ;
F_27 ( & V_44 -> V_64 , & V_31 -> V_71 ) ;
F_25 ( V_44 ) ;
V_40 = F_9 ( V_45 ) ;
V_40 -> V_44 = V_44 ;
F_31 ( F_32 ( & V_44 -> V_67 ) , >= , 3 ) ;
F_11 ( L_13 ) ;
F_26 ( & V_44 -> V_72 ) ;
V_12 = F_33 ( V_44 , V_45 , true ,
false ) ;
F_34 ( & V_44 -> V_72 ) ;
V_45 = NULL ;
F_35 ( V_12 < 0 ) ;
}
F_34 ( & V_44 -> V_35 -> V_60 ) ;
F_11 ( L_14 ) ;
}
F_36 ( & V_31 -> V_58 ) ;
F_11 ( L_15 ) ;
F_37 ( V_44 , V_33 ) ;
F_11 ( L_16 ) ;
F_38 ( & V_2 -> V_53 ) ;
F_39 ( V_45 ) ;
F_40 ( V_44 ) ;
F_7 ( L_4 ) ;
return 0 ;
V_57:
F_11 ( L_17 ) ;
F_38 ( & V_2 -> V_53 ) ;
F_22 ( & V_44 -> V_60 ) ;
if ( ! F_41 ( V_73 , & V_44 -> V_22 ) &&
! F_24 ( V_73 , & V_44 -> V_69 ) ) {
F_25 ( V_44 ) ;
F_42 ( V_44 ) ;
}
F_38 ( & V_44 -> V_60 ) ;
F_40 ( V_44 ) ;
V_12 = - V_74 ;
error:
F_39 ( V_45 ) ;
V_48:
F_7 ( L_18 , V_12 ) ;
return V_12 ;
}
void F_43 ( struct V_75 * V_76 )
{
struct V_1 * V_2 =
F_44 ( V_76 , struct V_1 , V_77 ) ;
struct V_38 * V_39 ;
struct V_3 V_4 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
T_2 V_78 ;
int V_12 ;
F_2 ( L_19 , V_2 -> V_13 ) ;
F_22 ( & V_79 ) ;
if ( F_32 ( & V_2 -> V_67 ) > 0 )
F_45 ( V_2 ) ;
else
V_2 = NULL ;
F_38 ( & V_79 ) ;
if ( ! V_2 ) {
F_7 ( L_20 ) ;
return;
}
V_80:
V_33 = F_46 ( & V_2 -> V_81 ) ;
if ( ! V_33 ) {
F_47 ( V_2 ) ;
F_7 ( L_21 ) ;
return;
}
F_48 ( L_22 , V_33 ) ;
V_39 = F_9 ( V_33 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_82 = V_83 ;
V_4 . V_15 . V_84 = V_2 -> V_4 . V_15 . V_84 ;
V_4 . V_85 = V_2 -> V_4 . V_85 ;
switch ( V_4 . V_15 . V_84 ) {
case V_86 :
V_4 . V_87 = sizeof( struct V_88 ) ;
V_4 . V_15 . sin . V_89 = F_49 ( V_33 ) -> V_90 ;
V_4 . V_15 . sin . V_91 . V_92 = F_50 ( V_33 ) -> V_93 ;
break;
default:
goto V_94;
}
V_78 = V_39 -> V_6 . V_95 ;
F_22 ( & V_2 -> V_53 ) ;
F_51 (rx, &local->services, listen_link) {
if ( V_31 -> V_78 == V_78 &&
V_31 -> V_54 . V_55 != V_56 )
goto V_96;
}
F_38 ( & V_2 -> V_53 ) ;
goto V_57;
V_96:
F_11 ( L_23 , F_52 ( V_31 -> V_78 ) ) ;
if ( F_53 ( & V_31 -> V_54 ) )
goto V_97;
F_54 ( & V_31 -> V_54 ) ;
F_55 ( & V_31 -> V_54 ) ;
F_38 ( & V_2 -> V_53 ) ;
V_12 = F_8 ( V_2 , V_31 , V_33 , & V_4 ) ;
if ( V_12 < 0 )
F_56 ( & V_31 -> V_54 ) ;
F_57 ( & V_31 -> V_54 ) ;
switch ( V_12 ) {
case - V_98 :
case - V_99 :
case 0 :
goto V_80;
case - V_74 :
goto V_57;
case - V_52 :
goto V_94;
case - V_100 :
goto V_101;
default:
F_58 () ;
}
V_97:
F_38 ( & V_2 -> V_53 ) ;
V_94:
F_1 ( V_2 , & V_4 , & V_39 -> V_6 ) ;
F_39 ( V_33 ) ;
goto V_80;
V_57:
V_33 -> V_102 = V_103 ;
F_59 ( V_2 , V_33 ) ;
goto V_80;
V_101:
V_33 -> V_102 = V_104 ;
F_59 ( V_2 , V_33 ) ;
goto V_80;
}
struct V_43 * F_60 ( struct V_30 * V_31 ,
unsigned long V_105 )
{
struct V_43 * V_44 ;
struct V_106 * V_107 , * * V_108 ;
int V_12 ;
F_2 ( L_24 , V_105 ) ;
ASSERT ( ! F_61 () ) ;
F_23 ( & V_31 -> V_58 ) ;
V_12 = - V_109 ;
if ( F_62 ( & V_31 -> V_71 ) )
goto V_110;
V_12 = - V_111 ;
V_108 = & V_31 -> V_112 . V_106 ;
V_107 = NULL ;
while ( * V_108 ) {
V_107 = * V_108 ;
V_44 = F_63 ( V_107 , struct V_43 , V_113 ) ;
if ( V_105 < V_44 -> V_105 )
V_108 = & ( * V_108 ) -> V_114 ;
else if ( V_105 > V_44 -> V_105 )
V_108 = & ( * V_108 ) -> V_115 ;
else
goto V_110;
}
V_44 = F_64 ( V_31 -> V_71 . V_116 , struct V_43 , V_64 ) ;
F_65 ( & V_44 -> V_64 ) ;
F_56 ( & V_31 -> V_54 ) ;
F_66 ( & V_44 -> V_60 ) ;
switch ( V_44 -> V_62 ) {
case V_70 :
V_44 -> V_62 = V_117 ;
break;
case V_118 :
case V_119 :
V_12 = - V_99 ;
goto V_120;
case V_121 :
V_12 = V_44 -> V_35 -> error ;
goto V_120;
case V_122 :
V_12 = - V_123 ;
goto V_124;
default:
F_58 () ;
}
V_44 -> V_105 = V_105 ;
F_67 ( & V_44 -> V_113 , V_107 , V_108 ) ;
F_68 ( & V_44 -> V_113 , & V_31 -> V_112 ) ;
if ( F_24 ( V_125 , & V_44 -> V_22 ) )
F_58 () ;
if ( F_24 ( V_126 , & V_44 -> V_69 ) )
F_58 () ;
F_42 ( V_44 ) ;
F_25 ( V_44 ) ;
F_69 ( & V_44 -> V_60 ) ;
F_36 ( & V_31 -> V_58 ) ;
F_7 ( L_25 , V_44 , V_44 -> V_13 ) ;
return V_44 ;
V_120:
F_11 ( L_26 , V_44 ) ;
if ( ! F_41 ( V_127 , & V_44 -> V_22 ) &&
! F_24 ( V_73 , & V_44 -> V_69 ) )
F_42 ( V_44 ) ;
V_124:
F_69 ( & V_44 -> V_60 ) ;
F_11 ( L_27 , V_44 ) ;
V_110:
F_36 ( & V_31 -> V_58 ) ;
F_7 ( L_18 , V_12 ) ;
return F_70 ( V_12 ) ;
}
int F_71 ( struct V_30 * V_31 )
{
struct V_43 * V_44 ;
int V_12 ;
F_2 ( L_5 ) ;
ASSERT ( ! F_61 () ) ;
F_23 ( & V_31 -> V_58 ) ;
V_12 = - V_109 ;
if ( F_62 ( & V_31 -> V_71 ) )
goto V_110;
V_44 = F_64 ( V_31 -> V_71 . V_116 , struct V_43 , V_64 ) ;
F_65 ( & V_44 -> V_64 ) ;
F_56 ( & V_31 -> V_54 ) ;
F_66 ( & V_44 -> V_60 ) ;
switch ( V_44 -> V_62 ) {
case V_70 :
V_44 -> V_62 = V_128 ;
if ( F_24 ( V_129 , & V_44 -> V_69 ) )
F_42 ( V_44 ) ;
V_12 = 0 ;
goto V_120;
case V_118 :
case V_119 :
V_12 = - V_99 ;
goto V_120;
case V_121 :
V_12 = V_44 -> V_35 -> error ;
goto V_120;
case V_122 :
V_12 = - V_123 ;
goto V_124;
default:
F_58 () ;
}
V_120:
F_11 ( L_26 , V_44 ) ;
if ( ! F_41 ( V_127 , & V_44 -> V_22 ) &&
! F_24 ( V_73 , & V_44 -> V_69 ) )
F_42 ( V_44 ) ;
V_124:
F_69 ( & V_44 -> V_60 ) ;
F_11 ( L_27 , V_44 ) ;
V_110:
F_36 ( & V_31 -> V_58 ) ;
F_7 ( L_18 , V_12 ) ;
return V_12 ;
}
struct V_43 * F_72 ( struct V_28 * V_130 ,
unsigned long V_105 )
{
struct V_43 * V_44 ;
F_2 ( L_24 , V_105 ) ;
V_44 = F_60 ( F_73 ( V_130 -> V_54 ) , V_105 ) ;
F_7 ( L_28 , V_44 ) ;
return V_44 ;
}
int F_74 ( struct V_28 * V_130 )
{
int V_12 ;
F_2 ( L_5 ) ;
V_12 = F_71 ( F_73 ( V_130 -> V_54 ) ) ;
F_7 ( L_18 , V_12 ) ;
return V_12 ;
}
