void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , bool V_5 )
{
unsigned long V_6 ;
T_3 V_7 = V_8 [ V_3 ] ;
F_2 ( V_7 , > , 0 ) ;
F_3 ( L_1 ,
V_2 -> V_9 , F_4 ( V_3 ) , V_4 , V_5 ) ;
if ( V_7 < V_8 [ V_2 -> V_10 ] ) {
if ( V_5 )
goto V_11;
return;
}
if ( V_7 == V_8 [ V_2 -> V_10 ] ) {
if ( V_7 <= 4 )
V_2 -> V_12 = V_4 ;
if ( V_5 )
goto V_11;
return;
}
V_2 -> V_10 = V_3 ;
V_2 -> V_12 = V_4 ;
switch ( V_3 ) {
case V_13 :
F_5 ( L_2 ) ;
V_6 = V_14 ;
goto V_15;
case V_16 :
if ( ! V_5 ) {
F_5 ( L_3 ) ;
V_6 = V_17 ;
goto V_15;
}
goto V_11;
case V_18 :
V_6 = V_19 ;
if ( ! V_6 )
goto V_11;
if ( ! V_5 || V_4 == 1 ) {
F_5 ( L_3 ) ;
goto V_15;
}
default:
F_5 ( L_4 ) ;
goto V_11;
}
V_15:
V_6 += V_20 ;
if ( ! F_6 ( & V_2 -> V_21 ) ||
F_7 ( V_2 -> V_21 . V_22 , V_6 ) )
F_8 ( & V_2 -> V_21 , V_6 ) ;
return;
V_11:
F_5 ( L_5 , V_4 ) ;
F_9 ( & V_2 -> V_21 ) ;
F_10 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_24 <= V_25 &&
! F_11 ( V_26 , & V_2 -> V_27 ) )
F_12 ( V_2 ) ;
F_13 ( & V_2 -> V_23 ) ;
}
void F_14 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , bool V_5 )
{
T_3 V_7 = V_8 [ V_3 ] ;
if ( V_7 > V_8 [ V_2 -> V_10 ] ) {
F_15 ( & V_2 -> V_28 ) ;
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
F_16 ( & V_2 -> V_28 ) ;
}
}
static void F_17 ( struct V_1 * V_2 , T_1 V_29 ,
unsigned long V_30 )
{
F_10 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_24 >= V_25 )
V_29 = 0 ;
if ( V_29 & 1 ) {
F_5 ( L_6 ) ;
F_18 ( V_31 , & V_2 -> V_27 ) ;
}
if ( V_29 & 2 ) {
F_5 ( L_7 ) ;
F_18 ( V_32 , & V_2 -> V_33 ) ;
F_8 ( & V_2 -> V_34 , V_30 ) ;
} else {
F_5 ( L_8 ) ;
F_19 ( & V_2 -> V_34 ) ;
F_20 ( V_35 , & V_2 -> V_27 ) ;
F_20 ( V_32 , & V_2 -> V_33 ) ;
}
F_13 ( & V_2 -> V_23 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
unsigned long * V_42 , V_30 ;
bool V_43 ;
int V_44 ;
T_1 V_29 ;
F_3 ( L_9 ,
V_2 -> V_45 , V_2 -> V_46 ,
F_22 ( & V_2 -> V_47 ) ,
F_23 ( V_2 -> V_48 , V_2 -> V_49 , V_2 -> V_50 ) ) ;
V_43 = false ;
V_29 = 0 ;
V_30 = 0 ;
for ( V_44 = V_2 -> V_49 ;
V_44 != V_2 -> V_48 || V_43 ;
V_44 = ( V_44 + 1 ) & ( V_2 -> V_50 - 1 )
) {
V_42 = V_2 -> V_51 + V_44 ;
F_24 () ;
if ( * V_42 & 1 )
continue;
V_41 = (struct V_40 * ) * V_42 ;
V_39 = F_25 ( V_41 ) ;
if ( V_39 -> V_52 ) {
V_39 -> V_52 = false ;
V_39 -> V_53 . V_4 = F_26 ( & V_2 -> V_54 -> V_4 ) ;
V_37 = (struct V_36 * ) V_41 -> V_55 ;
V_37 -> V_4 = F_27 ( V_39 -> V_53 . V_4 ) ;
F_28 ( L_10 ,
V_39 -> V_53 . V_4 , V_39 -> V_53 . V_56 ) ;
if ( F_29 ( V_2 -> V_54 , V_41 ) < 0 ) {
V_43 = true ;
V_39 -> V_30 = V_20 + 3 ;
} else {
V_39 -> V_30 =
V_20 + V_57 ;
}
}
if ( F_30 ( V_20 + 1 , V_39 -> V_30 ) ) {
V_39 -> V_52 = true ;
V_29 |= 1 ;
} else if ( V_29 & 2 ) {
if ( F_31 ( V_39 -> V_30 , V_30 ) )
V_30 = V_39 -> V_30 ;
} else {
V_30 = V_39 -> V_30 ;
V_29 |= 2 ;
}
}
F_17 ( V_2 , V_29 , V_30 ) ;
F_32 ( L_11 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
unsigned long * V_42 , V_30 ;
int V_44 ;
T_1 V_29 ;
F_3 ( L_12 ,
V_2 -> V_49 , V_2 -> V_46 , V_2 -> V_48 ) ;
if ( V_2 -> V_24 >= V_25 )
return;
V_29 = 0 ;
V_30 = 0 ;
for ( V_44 = V_2 -> V_46 ;
V_44 != V_2 -> V_48 ;
V_44 = ( V_44 + 1 ) & ( V_2 -> V_50 - 1 )
) {
V_42 = V_2 -> V_51 + V_44 ;
F_24 () ;
V_41 = (struct V_40 * ) ( * V_42 & ~ 1 ) ;
V_39 = F_25 ( V_41 ) ;
ASSERT ( ! ( * V_42 & 1 ) ) ;
if ( V_39 -> V_52 ) {
;
} else if ( F_30 ( V_20 + 1 , V_39 -> V_30 ) ) {
V_39 -> V_52 = true ;
V_29 |= 1 ;
} else if ( V_29 & 2 ) {
if ( F_31 ( V_39 -> V_30 , V_30 ) )
V_30 = V_39 -> V_30 ;
} else {
V_30 = V_39 -> V_30 ;
V_29 |= 2 ;
}
}
F_17 ( V_2 , V_29 , V_30 ) ;
F_32 ( L_11 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
struct V_40 * V_60 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
unsigned long * V_42 , V_30 ;
int V_44 ;
T_1 V_61 [ V_62 ] , V_29 ;
F_3 ( L_13 ,
V_2 -> V_45 ,
F_23 ( V_2 -> V_48 , V_2 -> V_49 , V_2 -> V_50 ) ,
V_59 -> V_63 ) ;
if ( F_35 ( V_60 , 0 , V_61 , V_59 -> V_63 ) < 0 )
goto V_64;
V_29 = 0 ;
V_30 = 0 ;
for ( V_44 = 0 ; V_44 < V_59 -> V_63 ; V_44 ++ ) {
V_42 = V_2 -> V_51 ;
V_42 += ( V_2 -> V_49 + V_44 ) & ( V_2 -> V_50 - 1 ) ;
F_24 () ;
V_41 = (struct V_40 * ) ( * V_42 & ~ 1 ) ;
V_39 = F_25 ( V_41 ) ;
switch ( V_61 [ V_44 ] ) {
case V_65 :
V_39 -> V_52 = false ;
* V_42 |= 1 ;
break;
case V_66 :
V_39 -> V_52 = true ;
* V_42 &= ~ 1 ;
V_29 = 1 ;
break;
default:
F_5 ( L_14 , V_61 [ V_44 ] ) ;
goto V_64;
}
}
F_36 () ;
V_2 -> V_46 = ( V_2 -> V_49 + V_44 ) & ( V_2 -> V_50 - 1 ) ;
for ( V_44 = V_2 -> V_46 ;
V_44 != V_2 -> V_48 ;
V_44 = ( V_44 + 1 ) & ( V_2 -> V_50 - 1 )
) {
V_42 = V_2 -> V_51 + V_44 ;
F_24 () ;
V_41 = (struct V_40 * ) ( * V_42 & ~ 1 ) ;
V_39 = F_25 ( V_41 ) ;
if ( * V_42 & 1 ) {
V_39 -> V_52 = true ;
* V_42 &= ~ 1 ;
V_29 |= 1 ;
} else if ( V_39 -> V_52 ) {
;
} else if ( F_30 ( V_20 + 1 , V_39 -> V_30 ) ) {
V_39 -> V_52 = true ;
V_29 |= 1 ;
} else if ( V_29 & 2 ) {
if ( F_31 ( V_39 -> V_30 , V_30 ) )
V_30 = V_39 -> V_30 ;
} else {
V_30 = V_39 -> V_30 ;
V_29 |= 2 ;
}
}
F_17 ( V_2 , V_29 , V_30 ) ;
F_32 ( L_15 ) ;
return 0 ;
V_64:
F_32 ( L_16 ) ;
return - V_67 ;
}
static void F_37 ( struct V_1 * V_2 , T_2 V_68 )
{
unsigned long V_69 ;
int V_70 = V_2 -> V_49 , V_71 ;
int V_72 = F_23 ( V_2 -> V_48 , V_70 , V_2 -> V_50 ) ;
F_3 ( L_17 , V_2 -> V_45 , V_72 , V_68 ) ;
F_2 ( V_68 - V_2 -> V_45 , <= , V_72 ) ;
while ( V_2 -> V_45 < V_68 ) {
F_24 () ;
V_69 = V_2 -> V_51 [ V_70 ] & ~ 1 ;
F_38 ( (struct V_40 * ) V_69 ) ;
V_71 = V_70 ;
V_70 = ( V_70 + 1 ) & ( V_2 -> V_50 - 1 ) ;
V_2 -> V_49 = V_70 ;
if ( V_2 -> V_46 == V_71 )
V_2 -> V_46 = V_70 ;
V_2 -> V_45 ++ ;
}
F_39 ( & V_2 -> V_73 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_37 ( V_2 , F_22 ( & V_2 -> V_47 ) ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
struct V_40 * V_60 ;
bool V_74 ;
int V_75 ;
F_3 ( L_18 , V_2 -> V_76 , V_2 -> V_77 ) ;
F_15 ( & V_2 -> V_28 ) ;
V_75 = - V_78 ;
if ( F_42 ( V_79 , & V_2 -> V_33 ) )
goto V_80;
V_60 = F_43 ( & V_2 -> V_81 ) ;
if ( V_60 ) {
V_39 = F_25 ( V_60 ) ;
F_5 ( L_19 ,
V_39 -> V_53 . V_56 , V_2 -> V_77 ) ;
if ( V_39 -> V_53 . V_56 != V_2 -> V_77 ) {
F_44 ( & V_2 -> V_81 , V_60 ) ;
V_2 -> V_77 = F_25 ( V_60 ) -> V_53 . V_56 ;
F_5 ( L_20 , V_60 , V_2 -> V_77 ) ;
} else {
V_60 -> V_82 = V_83 ;
V_74 = ( ( V_39 -> V_53 . V_33 & V_84 ) &&
! ( V_39 -> V_53 . V_33 & V_85 ) ) ;
V_75 = F_45 ( V_2 , V_60 , true , V_74 ) ;
F_46 ( V_75 < 0 ) ;
F_5 ( L_21 , V_2 -> V_76 ) ;
V_2 -> V_76 ++ ;
V_60 = F_47 ( & V_2 -> V_81 ) ;
if ( V_60 )
V_2 -> V_77 = F_25 ( V_60 ) -> V_53 . V_56 ;
else
V_2 -> V_77 = 0 ;
F_5 ( L_22 , V_60 , V_2 -> V_77 ) ;
}
}
V_75 = 0 ;
V_80:
F_16 ( & V_2 -> V_28 ) ;
F_32 ( L_23 , V_75 ) ;
return V_75 ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_40 * V_60 )
{
struct V_38 * V_39 , * V_86 ;
struct V_40 * V_87 ;
T_2 V_56 ;
V_39 = F_25 ( V_60 ) ;
V_56 = V_39 -> V_53 . V_56 ;
F_3 ( L_24 , V_56 ) ;
V_60 -> V_88 = V_89 ;
F_2 ( V_39 -> V_2 , == , NULL ) ;
V_39 -> V_2 = V_2 ;
F_49 ( V_2 ) ;
F_50 ( & V_2 -> V_90 ) ;
F_15 ( & V_2 -> V_28 ) ;
F_51 (&call->rx_oos_queue, p) {
V_86 = F_25 ( V_87 ) ;
if ( V_86 -> V_53 . V_56 > V_56 ) {
F_5 ( L_25 , V_56 , V_86 -> V_53 . V_56 ) ;
F_52 ( V_87 , V_60 , & V_2 -> V_81 ) ;
goto V_91;
}
}
F_5 ( L_26 , V_56 ) ;
F_53 ( & V_2 -> V_81 , V_60 ) ;
V_91:
if ( V_2 -> V_77 == 0 || V_56 < V_2 -> V_77 )
V_2 -> V_77 = V_56 ;
F_54 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_24 < V_25 &&
V_2 -> V_76 == V_2 -> V_77 ) {
F_5 ( L_27 ) ;
F_18 ( V_92 , & V_2 -> V_27 ) ;
}
F_55 ( & V_2 -> V_23 ) ;
F_16 ( & V_2 -> V_28 ) ;
F_32 ( L_28 , V_2 -> V_77 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
struct V_40 * V_60 ;
unsigned long V_69 , * V_51 ;
T_1 V_93 = V_2 -> V_50 ;
int V_70 ;
V_51 = V_2 -> V_51 ;
V_2 -> V_51 = NULL ;
while ( F_23 ( V_2 -> V_48 , V_2 -> V_49 , V_93 ) > 0 ) {
V_70 = V_2 -> V_49 ;
F_24 () ;
V_69 = V_51 [ V_70 ] & ~ 1 ;
F_36 () ;
V_2 -> V_49 = ( V_2 -> V_49 + 1 ) & ( V_93 - 1 ) ;
V_60 = (struct V_40 * ) V_69 ;
V_39 = F_25 ( V_60 ) ;
F_5 ( L_29 , V_39 -> V_53 . V_56 ) ;
F_38 ( V_60 ) ;
}
F_57 ( V_51 ) ;
}
static void F_58 ( struct V_1 * V_2 , struct V_40 * V_60 ,
unsigned int V_94 , int V_63 )
{
struct V_95 V_96 ;
struct V_97 * V_98 ;
unsigned int V_99 ;
if ( F_35 ( V_60 , V_63 + 3 , & V_96 , sizeof( V_96 ) ) < 0 ) {
F_32 ( L_30 ) ;
return;
}
F_28 ( L_31 ,
V_94 ,
F_59 ( V_96 . V_100 ) , F_59 ( V_96 . V_101 ) ,
F_59 ( V_96 . V_102 ) , F_59 ( V_96 . V_103 ) ) ;
V_99 = F_60 ( F_59 ( V_96 . V_100 ) , F_59 ( V_96 . V_101 ) ) ;
V_98 = V_2 -> V_54 -> V_104 . V_98 ;
if ( V_99 < V_98 -> V_105 ) {
F_15 ( & V_98 -> V_28 ) ;
V_98 -> V_105 = V_99 ;
V_98 -> V_99 = V_99 + V_98 -> V_106 ;
F_16 ( & V_98 -> V_28 ) ;
F_61 ( L_32 , V_98 -> V_99 , V_98 -> V_105 ) ;
}
}
static int F_62 ( struct V_1 * V_2 ,
T_2 * V_107 )
{
struct V_58 V_59 ;
struct V_38 * V_39 ;
struct V_40 * V_60 ;
bool V_108 ;
int V_94 ;
T_2 V_68 , V_109 ;
F_3 ( L_11 ) ;
V_110:
V_60 = F_43 ( & V_2 -> V_111 ) ;
if ( ! V_60 )
return - V_112 ;
F_61 ( L_33 , V_60 ) ;
V_39 = F_25 ( V_60 ) ;
F_5 ( L_34 , V_113 [ V_39 -> V_53 . type ] , V_2 -> V_24 ) ;
V_108 = false ;
switch ( V_39 -> V_53 . type ) {
case V_114 :
F_28 ( L_35 , V_39 -> V_53 . V_4 , V_39 -> V_53 . V_56 ) ;
if ( V_2 -> V_54 -> V_115 -> V_116 ( V_2 , V_60 ,
V_107 ) < 0 )
goto V_64;
F_48 ( V_2 , V_60 ) ;
goto V_110;
case V_117 :
if ( F_35 ( V_60 , 0 , & V_59 , sizeof( V_59 ) ) < 0 ) {
F_5 ( L_36 ) ;
goto V_64;
}
if ( ! F_63 ( V_60 , sizeof( V_59 ) ) )
F_64 () ;
V_94 = V_39 -> V_53 . V_4 ;
V_68 = F_59 ( V_59 . V_118 ) ;
V_109 = F_22 ( & V_2 -> V_47 ) ;
F_28 ( L_37 ,
V_94 ,
F_65 ( V_59 . V_119 ) ,
V_68 ,
F_59 ( V_59 . V_120 ) ,
F_59 ( V_59 . V_4 ) ,
F_4 ( V_59 . V_121 ) ,
V_59 . V_63 ) ;
F_58 ( V_2 , V_60 , V_94 , V_59 . V_63 ) ;
if ( V_59 . V_121 == V_122 ) {
F_28 ( L_38 , V_94 ) ;
F_14 ( V_2 , V_123 ,
V_39 -> V_53 . V_4 , true ) ;
}
if ( V_94 - V_2 -> V_124 <= 0 ) {
F_5 ( L_39 ,
V_94 , V_2 -> V_124 ) ;
goto V_125;
}
V_2 -> V_124 = V_94 ;
if ( V_2 -> V_24 != V_126 &&
V_2 -> V_24 != V_127 &&
V_2 -> V_24 != V_128 &&
V_2 -> V_24 != V_129 )
goto V_125;
F_5 ( L_40 , V_109 , V_2 -> V_45 , V_2 -> V_24 ) ;
if ( V_68 > 0 ) {
if ( V_68 - 1 > V_109 ) {
F_5 ( L_41
L_42 ,
V_68 - 1 , V_109 ) ;
goto V_64;
}
if ( ( V_2 -> V_24 == V_127 ||
V_2 -> V_24 == V_129 ) &&
V_68 > V_109 ) {
V_2 -> V_45 = V_109 ;
goto V_130;
}
F_66 () ;
F_37 ( V_2 , V_68 - 1 ) ;
}
if ( V_59 . V_63 > 0 ) {
if ( V_68 - 1 + V_59 . V_63 > V_109 ) {
F_5 ( L_43
L_44 ,
V_68 - 1 , V_59 . V_63 , V_109 ) ;
goto V_64;
}
if ( F_34 ( V_2 , & V_59 , V_60 ) < 0 )
goto V_64;
}
goto V_125;
case V_131 :
goto V_130;
case V_132 :
case V_133 :
F_64 () ;
case V_134 :
case V_135 :
case V_136 :
F_64 () ;
}
V_130:
F_67 ( & V_2 -> V_23 ) ;
F_5 ( L_45 , V_2 -> V_24 ) ;
switch ( V_2 -> V_24 ) {
case V_127 :
V_2 -> V_24 = V_137 ;
break;
case V_129 :
F_5 ( L_46 ) ;
V_2 -> V_24 = V_25 ;
V_108 = true ;
break;
case V_126 :
case V_138 :
goto V_139;
default:
F_68 ( & V_2 -> V_23 ) ;
goto V_125;
}
F_68 ( & V_2 -> V_23 ) ;
F_5 ( L_47 ,
F_23 ( V_2 -> V_48 , V_2 -> V_49 , V_2 -> V_50 ) ) ;
F_19 ( & V_2 -> V_34 ) ;
F_20 ( V_32 , & V_2 -> V_33 ) ;
F_20 ( V_35 , & V_2 -> V_27 ) ;
if ( V_2 -> V_51 )
F_56 ( V_2 ) ;
if ( V_108 ) {
F_5 ( L_48 ) ;
V_60 -> V_82 = V_140 ;
V_39 -> V_2 = V_2 ;
F_49 ( V_2 ) ;
F_50 ( & V_2 -> V_90 ) ;
F_15 ( & V_2 -> V_28 ) ;
if ( F_45 ( V_2 , V_60 , true , true ) < 0 )
F_64 () ;
F_16 ( & V_2 -> V_28 ) ;
goto V_110;
}
V_125:
F_38 ( V_60 ) ;
goto V_110;
V_139:
F_68 ( & V_2 -> V_23 ) ;
V_64:
F_38 ( V_60 ) ;
F_32 ( L_16 ) ;
return - V_67 ;
}
static int F_69 ( struct V_1 * V_2 , T_2 V_82 , T_2 error ,
bool V_141 )
{
struct V_38 * V_39 ;
struct V_40 * V_60 ;
int V_75 ;
F_3 ( L_49 ,
V_2 -> V_9 , V_2 -> V_33 , V_82 , error , V_141 ) ;
if ( V_141 ) {
F_19 ( & V_2 -> V_34 ) ;
F_19 ( & V_2 -> V_21 ) ;
F_20 ( V_32 , & V_2 -> V_33 ) ;
}
if ( V_82 != V_142 &&
! F_42 ( V_143 , & V_2 -> V_33 ) ) {
F_32 ( L_50 ) ;
return 0 ;
}
if ( ! F_42 ( V_144 , & V_2 -> V_33 ) ) {
V_60 = F_70 ( 0 , V_145 ) ;
if ( ! V_60 )
return - V_146 ;
F_71 ( V_60 ) ;
V_60 -> V_82 = V_82 ;
V_39 = F_25 ( V_60 ) ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> error = error ;
V_39 -> V_2 = V_2 ;
F_49 ( V_2 ) ;
F_50 ( & V_2 -> V_90 ) ;
F_15 ( & V_2 -> V_28 ) ;
V_75 = F_45 ( V_2 , V_60 , true , V_141 ) ;
F_16 ( & V_2 -> V_28 ) ;
F_46 ( V_75 < 0 ) ;
}
return 0 ;
}
void F_72 ( struct V_147 * V_148 )
{
struct V_1 * V_2 =
F_73 ( V_148 , struct V_1 , V_149 ) ;
struct V_36 V_37 ;
struct V_58 V_59 ;
struct V_95 V_96 ;
struct V_150 V_151 ;
struct V_152 V_153 [ 5 ] ;
enum V_154 V_155 ;
unsigned long V_156 ;
T_4 V_157 , V_158 ;
T_5 V_159 ;
int V_44 , V_160 , V_161 , V_75 , V_99 ;
T_2 V_4 , V_162 = V_163 ;
T_1 * V_164 = NULL ;
F_3 ( L_51 ,
V_2 -> V_9 , V_165 [ V_2 -> V_24 ] , V_2 -> V_27 ,
( V_20 - V_2 -> V_166 ) / ( V_167 / 10 ) ) ;
if ( F_11 ( V_168 , & V_2 -> V_33 ) ) {
F_5 ( L_52 ) ;
return;
}
if ( ! V_2 -> V_54 )
goto V_169;
V_151 . V_170 = & V_2 -> V_54 -> V_104 . V_98 -> V_171 . V_172 ;
V_151 . V_173 = V_2 -> V_54 -> V_104 . V_98 -> V_171 . V_174 ;
V_151 . V_175 = NULL ;
V_151 . V_176 = 0 ;
V_151 . V_177 = 0 ;
V_37 . V_178 = F_27 ( V_2 -> V_54 -> V_179 . V_178 ) ;
V_37 . V_180 = F_27 ( V_2 -> V_180 ) ;
V_37 . V_181 = F_27 ( V_2 -> V_182 ) ;
V_37 . V_56 = 0 ;
V_37 . type = V_117 ;
V_37 . V_33 = V_2 -> V_54 -> V_183 ;
V_37 . V_184 = 0 ;
V_37 . V_185 = V_2 -> V_54 -> V_186 ;
V_37 . V_187 = 0 ;
V_37 . V_188 = F_74 ( V_2 -> V_189 ) ;
memset ( V_153 , 0 , sizeof( V_153 ) ) ;
V_153 [ 0 ] . V_190 = & V_37 ;
V_153 [ 0 ] . V_191 = sizeof( V_37 ) ;
V_169:
if ( F_42 ( V_192 , & V_2 -> V_27 ) ) {
enum V_193 V_82 ;
int error ;
F_20 ( V_194 , & V_2 -> V_27 ) ;
F_20 ( V_195 , & V_2 -> V_27 ) ;
F_20 ( V_196 , & V_2 -> V_27 ) ;
error = V_2 -> V_197 ;
if ( error < V_198 ) {
V_82 = V_199 ;
F_5 ( L_53 , error ) ;
} else {
V_82 = V_200 ;
error -= V_198 ;
F_5 ( L_54 , error ) ;
}
if ( F_69 ( V_2 , V_82 , error , true ) < 0 )
goto V_201;
F_20 ( V_192 , & V_2 -> V_27 ) ;
goto V_202;
}
if ( F_42 ( V_194 , & V_2 -> V_27 ) ) {
F_2 ( V_2 -> V_24 , > , V_25 ) ;
F_20 ( V_195 , & V_2 -> V_27 ) ;
F_20 ( V_196 , & V_2 -> V_27 ) ;
F_5 ( L_55 ) ;
if ( F_69 ( V_2 , V_200 ,
V_2 -> V_54 -> error , true ) < 0 )
goto V_201;
F_20 ( V_194 , & V_2 -> V_27 ) ;
goto V_202;
}
if ( F_42 ( V_195 , & V_2 -> V_27 ) ) {
V_37 . type = V_132 ;
V_155 = V_195 ;
goto V_203;
}
if ( F_42 ( V_196 , & V_2 -> V_27 ) ) {
F_2 ( V_2 -> V_24 , > , V_25 ) ;
if ( F_69 ( V_2 , V_200 ,
V_204 , true ) < 0 )
goto V_201;
V_37 . type = V_133 ;
V_157 = F_27 ( V_2 -> V_205 ) ;
V_153 [ 1 ] . V_190 = & V_157 ;
V_153 [ 1 ] . V_191 = sizeof( V_157 ) ;
V_155 = V_196 ;
goto V_203;
}
if ( F_42 ( V_206 , & V_2 -> V_27 ) ) {
V_155 = V_206 ;
V_59 . V_207 = F_74 ( 8 ) ;
V_59 . V_119 = 0 ;
V_59 . V_4 = 0 ;
V_59 . V_121 = V_16 ;
V_59 . V_63 = 0 ;
V_2 -> V_10 = 0 ;
F_15 ( & V_2 -> V_28 ) ;
V_59 . V_4 = F_27 ( V_2 -> V_12 ) ;
V_59 . V_120 = F_27 ( V_2 -> V_208 ) ;
V_59 . V_118 = F_27 ( V_2 -> V_209 + 1 ) ;
F_16 ( & V_2 -> V_28 ) ;
V_158 = 0 ;
V_153 [ 1 ] . V_190 = & V_59 ;
V_153 [ 1 ] . V_191 = sizeof( V_59 ) ;
V_153 [ 2 ] . V_190 = & V_158 ;
V_153 [ 2 ] . V_191 = 3 ;
V_153 [ 3 ] . V_190 = & V_96 ;
V_153 [ 3 ] . V_191 = sizeof( V_96 ) ;
goto V_210;
}
if ( V_2 -> V_27 & ( ( 1 << V_211 ) |
( 1 << V_212 ) )
) {
T_2 V_82 ;
if ( F_42 ( V_212 , & V_2 -> V_27 ) )
V_82 = V_213 ;
else
V_82 = V_214 ;
F_5 ( L_56 ) ;
F_40 ( V_2 ) ;
if ( F_69 ( V_2 , V_82 , V_204 , true ) < 0 )
goto V_201;
F_20 ( V_211 , & V_2 -> V_27 ) ;
F_20 ( V_212 , & V_2 -> V_27 ) ;
goto V_202;
}
if ( F_75 ( V_215 , & V_2 -> V_27 ) ) {
F_5 ( L_57 ) ;
F_40 ( V_2 ) ;
}
if ( F_42 ( V_216 , & V_2 -> V_27 ) ) {
F_67 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_24 <= V_25 ) {
V_2 -> V_24 = V_217 ;
V_2 -> V_205 = V_218 ;
F_18 ( V_196 , & V_2 -> V_27 ) ;
}
F_68 ( & V_2 -> V_23 ) ;
F_5 ( L_58 ) ;
if ( F_69 ( V_2 , V_200 ,
V_219 , true ) < 0 )
goto V_201;
F_20 ( V_216 , & V_2 -> V_27 ) ;
goto V_202;
}
if ( ! F_76 ( & V_2 -> V_111 ) ) {
switch ( F_62 ( V_2 , & V_162 ) ) {
case 0 :
case - V_112 :
break;
case - V_146 :
goto V_201;
case - V_220 :
case - V_221 :
case - V_67 :
F_77 ( V_2 , V_162 ) ;
goto V_202;
}
}
if ( F_75 ( V_35 , & V_2 -> V_27 ) )
F_33 ( V_2 ) ;
if ( F_75 ( V_31 , & V_2 -> V_27 ) )
F_21 ( V_2 ) ;
if ( F_42 ( V_26 , & V_2 -> V_27 ) ) {
F_5 ( L_59 ,
V_2 -> V_209 , V_2 -> V_222 ,
V_2 -> V_223 [ 0 ] ) ;
if ( V_2 -> V_24 > V_224 &&
V_2 -> V_10 != V_123 ) {
F_20 ( V_26 , & V_2 -> V_27 ) ;
goto V_225;
}
V_155 = V_26 ;
V_164 = F_78 ( V_2 -> V_222 - V_2 -> V_209 ,
V_145 ) ;
if ( ! V_164 )
goto V_201;
V_59 . V_207 = F_74 ( 8 ) ;
V_59 . V_119 = 0 ;
F_15 ( & V_2 -> V_28 ) ;
V_59 . V_121 = V_2 -> V_10 ;
V_59 . V_4 = F_27 ( V_2 -> V_12 ) ;
V_59 . V_120 = F_27 ( V_2 -> V_208 ) ;
V_59 . V_118 = F_27 ( V_2 -> V_209 + 1 ) ;
V_59 . V_63 = 0 ;
for ( V_44 = 0 ; V_44 < V_226 ; V_44 ++ ) {
V_160 = V_44 * V_227 ;
for ( V_156 = V_2 -> V_223 [ V_44 ] ; V_156 ; V_156 >>= 1
) {
F_5 ( L_60 , V_44 , V_160 , V_156 ) ;
if ( V_156 & 1 ) {
V_164 [ V_160 ] = V_65 ;
V_59 . V_63 = V_160 + 1 ;
}
V_160 ++ ;
}
}
V_2 -> V_10 = 0 ;
F_16 ( & V_2 -> V_28 ) ;
V_158 = 0 ;
V_153 [ 1 ] . V_190 = & V_59 ;
V_153 [ 1 ] . V_191 = sizeof( V_59 ) ;
V_153 [ 2 ] . V_190 = V_164 ;
V_153 [ 2 ] . V_191 = V_59 . V_63 ;
V_153 [ 3 ] . V_190 = & V_158 ;
V_153 [ 3 ] . V_191 = 3 ;
V_153 [ 4 ] . V_190 = & V_96 ;
V_153 [ 4 ] . V_191 = sizeof( V_96 ) ;
switch ( V_59 . V_121 ) {
case V_18 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_122 :
case V_123 :
goto V_232;
case V_13 :
case V_16 :
goto V_210;
}
}
if ( F_75 ( V_233 , & V_2 -> V_27 ) ) {
F_5 ( L_61 ) ;
F_15 ( & V_2 -> V_28 ) ;
if ( V_2 -> V_24 == V_234 ) {
F_5 ( L_62 ) ;
F_79 ( & V_2 -> V_235 -> V_236 ) ;
if ( ! F_42 ( V_79 , & V_2 -> V_33 ) &&
! F_42 ( V_237 , & V_2 -> V_27 ) ) {
F_5 ( L_63 ) ;
V_2 -> V_24 = V_238 ;
F_80 ( & V_2 -> V_239 ,
& V_2 -> V_235 -> V_240 ) ;
}
F_81 ( & V_2 -> V_235 -> V_236 ) ;
F_54 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_24 < V_25 )
F_18 ( V_241 , & V_2 -> V_27 ) ;
F_55 ( & V_2 -> V_23 ) ;
}
F_16 ( & V_2 -> V_28 ) ;
if ( ! F_42 ( V_241 , & V_2 -> V_27 ) )
goto V_225;
}
if ( F_42 ( V_241 , & V_2 -> V_27 ) ) {
F_5 ( L_64 ) ;
if ( F_69 ( V_2 , V_142 ,
0 , false ) < 0 )
goto V_201;
F_20 ( V_241 , & V_2 -> V_27 ) ;
goto V_225;
}
if ( F_75 ( V_242 , & V_2 -> V_27 ) ) {
F_5 ( L_65 ) ;
F_2 ( V_2 -> V_76 , == , 0 ) ;
V_2 -> V_76 = 1 ;
F_10 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_24 < V_25 )
F_18 ( V_92 , & V_2 -> V_27 ) ;
F_13 ( & V_2 -> V_23 ) ;
}
if ( F_75 ( V_92 , & V_2 -> V_27 ) ) {
while ( V_2 -> V_76 == V_2 -> V_77 )
if ( F_41 ( V_2 ) < 0 )
break;
goto V_225;
}
if ( F_42 ( V_237 , & V_2 -> V_27 ) ) {
F_82 ( V_2 ) ;
F_20 ( V_237 , & V_2 -> V_27 ) ;
}
goto V_225;
V_232:
V_59 . V_119 = F_74 ( F_22 ( & V_2 -> V_54 -> V_243 ) -
F_59 ( V_59 . V_4 ) ) ;
V_210:
V_99 = V_2 -> V_54 -> V_104 . V_98 -> V_244 ;
V_99 -= V_2 -> V_54 -> V_104 . V_98 -> V_106 ;
V_96 . V_101 = F_27 ( V_99 ) ;
V_96 . V_102 = F_27 ( V_245 ) ;
V_96 . V_100 = F_27 ( V_246 ) ;
V_96 . V_103 = F_27 ( V_247 ) ;
V_4 = F_26 ( & V_2 -> V_54 -> V_4 ) ;
V_37 . V_4 = F_27 ( V_4 ) ;
F_28 ( L_66 ,
V_4 ,
F_65 ( V_59 . V_119 ) ,
F_59 ( V_59 . V_118 ) ,
F_59 ( V_59 . V_120 ) ,
F_59 ( V_59 . V_4 ) ,
F_4 ( V_59 . V_121 ) ,
V_59 . V_63 ) ;
F_19 ( & V_2 -> V_21 ) ;
if ( V_59 . V_63 > 0 )
F_18 ( V_248 , & V_2 -> V_33 ) ;
goto V_249;
V_203:
F_5 ( L_67 ) ;
V_4 = F_26 ( & V_2 -> V_54 -> V_4 ) ;
V_37 . V_4 = F_27 ( V_4 ) ;
F_28 ( L_68 , V_113 [ V_37 . type ] , V_4 ) ;
V_249:
V_159 = V_153 [ 0 ] . V_191 ;
V_161 = 1 ;
if ( V_153 [ 4 ] . V_191 ) {
V_161 = 5 ;
V_159 += V_153 [ 4 ] . V_191 ;
V_159 += V_153 [ 3 ] . V_191 ;
V_159 += V_153 [ 2 ] . V_191 ;
V_159 += V_153 [ 1 ] . V_191 ;
} else if ( V_153 [ 3 ] . V_191 ) {
V_161 = 4 ;
V_159 += V_153 [ 3 ] . V_191 ;
V_159 += V_153 [ 2 ] . V_191 ;
V_159 += V_153 [ 1 ] . V_191 ;
} else if ( V_153 [ 2 ] . V_191 ) {
V_161 = 3 ;
V_159 += V_153 [ 2 ] . V_191 ;
V_159 += V_153 [ 1 ] . V_191 ;
} else if ( V_153 [ 1 ] . V_191 ) {
V_161 = 2 ;
V_159 += V_153 [ 1 ] . V_191 ;
}
V_75 = F_83 ( V_2 -> V_54 -> V_104 . V_250 -> V_235 ,
& V_151 , V_153 , V_161 , V_159 ) ;
if ( V_75 < 0 ) {
F_5 ( L_69 , V_75 ) ;
F_10 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_24 < V_251 )
F_12 ( V_2 ) ;
F_13 ( & V_2 -> V_23 ) ;
goto error;
}
switch ( V_155 ) {
case V_196 :
F_20 ( V_155 , & V_2 -> V_27 ) ;
F_20 ( V_212 , & V_2 -> V_27 ) ;
goto V_202;
case V_206 :
F_67 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_24 == V_252 )
V_2 -> V_24 = V_25 ;
F_68 ( & V_2 -> V_23 ) ;
goto V_202;
default:
F_20 ( V_155 , & V_2 -> V_27 ) ;
switch ( V_2 -> V_24 ) {
case V_127 :
case V_137 :
case V_138 :
case V_224 :
F_5 ( L_70 ) ;
F_14 ( V_2 , V_13 ,
V_2 -> V_12 , false ) ;
default:
break;
}
goto V_225;
}
V_202:
F_19 ( & V_2 -> V_21 ) ;
if ( F_75 ( V_206 , & V_2 -> V_27 ) )
F_84 ( V_2 ) ;
F_20 ( V_26 , & V_2 -> V_27 ) ;
V_225:
if ( V_2 -> V_27 || ! F_76 ( & V_2 -> V_111 ) ) {
F_10 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_24 < V_251 )
F_12 ( V_2 ) ;
F_13 ( & V_2 -> V_23 ) ;
}
if ( V_2 -> V_24 >= V_25 &&
! F_85 ( & V_2 -> V_239 ) ) {
F_5 ( L_71 ,
V_2 , V_2 -> V_27 , V_2 -> V_33 , V_2 -> V_54 -> V_179 . V_180 ) ;
F_10 ( & V_2 -> V_23 ) ;
if ( ! F_42 ( V_79 , & V_2 -> V_33 ) &&
! F_11 ( V_237 , & V_2 -> V_27 ) )
F_12 ( V_2 ) ;
F_13 ( & V_2 -> V_23 ) ;
}
error:
F_20 ( V_168 , & V_2 -> V_33 ) ;
F_57 ( V_164 ) ;
if ( V_2 -> V_27 && ! F_86 ( & V_2 -> V_149 ) ) {
F_5 ( L_72 , V_2 -> V_54 -> V_179 . V_180 ) ;
F_12 ( V_2 ) ;
}
F_32 ( L_11 ) ;
return;
V_201:
F_5 ( L_73 ) ;
goto V_225;
}
