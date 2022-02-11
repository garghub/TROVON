static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
T_1 V_5 = ( T_1 ) V_4 ;
if ( ( V_5 & V_6 ) &&
( V_3 & V_6 ) &&
F_2 () )
F_3 ( NULL ) ;
return 0 ;
}
static int F_4 ( void * V_7 , int V_8 , T_2 V_9 )
{
struct V_10 * V_11 = V_7 ;
struct V_12 * V_13 = V_11 -> V_14 ;
F_5 ( V_13 -> V_15 + V_8 , V_9 ) ;
return 0 ;
}
static int F_6 ( void * V_7 , int V_8 , T_2 * V_9 )
{
struct V_10 * V_11 = V_7 ;
struct V_12 * V_13 = V_11 -> V_14 ;
* V_9 = F_7 ( V_13 -> V_15 + V_8 ) ;
return 0 ;
}
static int F_8 ( void * V_7 , T_2 V_9 )
{
return F_4 ( V_7 , 0xD10 , V_9 ) ;
}
static int F_9 ( void * V_7 , T_2 * V_9 )
{
return F_6 ( V_7 , 0xD10 , V_9 ) ;
}
static int F_10 ( void * V_7 , T_2 V_9 )
{
return F_4 ( V_7 , 0xD90 , V_9 ) ;
}
static int F_11 ( void * V_7 , T_2 * V_9 )
{
return F_6 ( V_7 , 0xD90 , V_9 ) ;
}
static int F_12 ( void * V_7 , T_2 V_9 )
{
return F_4 ( V_7 , 0xE10 , V_9 ) ;
}
static int F_13 ( void * V_7 , T_2 * V_9 )
{
return F_6 ( V_7 , 0xE10 , V_9 ) ;
}
static int F_14 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
int V_16 ;
if ( ! V_17 ) {
V_16 = F_15 ( & V_18 ) ;
if ( V_16 ) {
F_16 ( L_1 ,
V_19 , V_16 ) ;
return V_16 ;
}
V_17 = 1 ;
}
#ifdef F_17
if ( V_13 -> V_20 ) {
F_18 ( L_2 , 0600 ,
V_13 -> V_20 , V_11 ,
& V_21 ) ;
F_18 ( L_3 , 0600 ,
V_13 -> V_20 , V_11 ,
& V_22 ) ;
F_18 ( L_4 , 0600 ,
V_13 -> V_20 , V_11 ,
& V_23 ) ;
}
#endif
V_13 -> V_24 |= V_25 ;
return 0 ;
}
static int F_19 ( struct V_26 * V_27 , int V_28 )
{
T_3 V_16 ;
T_4 V_29 ;
struct V_10 * V_11 = V_27 -> V_13 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_27 -> V_30 < 0 || V_27 -> V_30 >= V_13 -> V_31 . V_32 ) {
F_16 ( L_5
L_6 ,
V_19 , V_27 -> V_30 , V_13 -> V_31 . V_32 ,
V_11 -> V_33 ) ;
return - V_34 ;
}
V_29 = V_27 -> V_30 ;
switch ( V_28 ) {
case V_35 :
V_16 = - V_36 ;
break;
case V_37 :
V_16 = 0 ;
break;
case V_38 :
V_16 = F_20 ( V_13 -> V_39 , V_29 ,
V_40 ) ;
if ( V_16 ) {
F_21 ( L_7
L_8 ,
V_19 , V_11 -> V_33 , V_29 , V_16 ) ;
return - V_41 ;
}
break;
case V_42 :
V_16 = F_20 ( V_13 -> V_39 , V_29 ,
V_43 ) ;
if ( V_16 ) {
F_21 ( L_9
L_8 ,
V_19 , V_11 -> V_33 , V_29 , V_16 ) ;
return - V_41 ;
}
break;
default:
F_21 ( L_10 , V_19 , V_28 ) ;
return - V_34 ;
}
return V_16 ;
}
static void F_22 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
long V_44 ;
V_44 = F_23 ( V_13 -> V_39 , V_13 -> V_45 . V_46 ,
V_47 ) ;
if ( V_44 != V_48 ) {
F_21 ( L_11 ,
V_19 , V_11 -> V_33 , V_44 ) ;
return;
}
F_24 ( V_11 , V_13 -> V_45 . V_46 ) ;
}
static int F_25 ( struct V_26 * V_27 )
{
T_3 V_16 = 0 ;
T_5 V_49 ;
T_6 V_50 ;
T_4 V_29 ;
int V_51 ;
struct V_10 * V_11 = V_27 -> V_13 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_27 -> V_30 < 0 || V_27 -> V_30 >= V_13 -> V_31 . V_32 ) {
F_16 ( L_5
L_6 ,
V_19 , V_27 -> V_30 , V_13 -> V_31 . V_32 ,
V_11 -> V_33 ) ;
return V_52 ;
}
V_29 = V_27 -> V_30 ;
V_16 = F_26 ( V_13 -> V_39 , V_29 ,
& V_49 , & V_50 , NULL ) ;
if ( V_16 ) {
F_16 ( L_12
L_13 ,
V_19 , V_11 -> V_33 , V_29 , V_16 ) ;
return V_52 ;
}
if ( V_27 -> type & V_53 ) {
V_51 = 0 ;
V_51 &= ~ V_54 ;
if ( V_50 != V_55 ) {
V_51 |= V_56 ;
V_51 |= V_57 ;
V_51 |= V_58 ;
V_51 |= V_59 ;
} else if ( ! ( V_27 -> V_60 & V_61 ) ) {
F_27 ( V_27 , V_61 ) ;
F_22 ( V_11 ) ;
}
return V_51 ;
}
V_51 = 0 ;
switch ( V_49 ) {
case V_62 :
V_51 &= ~ V_54 ;
V_51 |= V_56 ;
V_51 |= V_57 ;
V_51 |= V_58 ;
V_51 |= V_59 ;
break;
case V_63 :
V_51 &= ~ V_54 ;
V_51 |= V_57 ;
V_51 |= V_59 ;
break;
case V_64 :
V_51 &= ~ V_54 ;
V_51 |= V_56 ;
V_51 |= V_58 ;
break;
case V_65 :
V_51 &= ~ V_54 ;
break;
case V_66 :
V_51 |= V_54 ;
break;
case V_67 :
V_51 |= V_68 ;
break;
case V_69 :
V_51 |= V_52 ;
break;
default:
F_21 ( L_14
L_15 ,
V_19 , V_49 , V_11 -> V_33 , V_29 ) ;
}
if ( V_51 != V_52 &&
( V_51 & ( V_56 | V_57 ) ) !=
( V_56 | V_57 ) &&
! ( V_27 -> V_60 & V_61 ) ) {
F_27 ( V_27 , V_61 ) ;
F_22 ( V_11 ) ;
}
return V_51 ;
}
static int F_28 ( struct V_26 * V_27 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
T_4 V_29 ;
T_5 V_49 ;
T_6 V_50 ;
T_3 V_16 ;
V_29 = V_27 -> V_30 ;
V_11 = V_27 -> V_13 ;
V_13 = V_27 -> V_13 -> V_14 ;
V_16 = F_20 ( V_13 -> V_39 ,
V_29 , V_70 ) ;
if ( V_16 ) {
F_16 ( L_16
L_8 ,
V_19 , V_11 -> V_33 , V_29 , V_16 ) ;
return - V_41 ;
}
V_16 = F_26 ( V_13 -> V_39 , V_29 ,
& V_49 , & V_50 , NULL ) ;
if ( V_16 ) {
F_16 ( L_12
L_13 ,
V_19 , V_11 -> V_33 , V_29 , V_16 ) ;
return - V_41 ;
}
if ( V_49 != V_62 ) {
F_16 ( L_17
L_18 ,
V_19 , V_11 -> V_33 , V_29 , V_49 ) ;
return - V_41 ;
}
return 0 ;
}
static T_3 F_29 ( struct V_12 * V_13 )
{
T_3 V_44 = V_71 ;
while ( 1 ) {
V_44 = F_30 ( V_13 -> V_39 ) ;
if ( V_44 <= 0 )
break;
F_31 ( V_44 ) ;
}
return V_44 ;
}
static int F_32 ( struct V_10 * V_11 , int V_28 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
T_3 V_44 = V_71 ;
F_33 ( L_19 ,
V_19 , V_11 -> V_33 , V_28 ) ;
if ( V_28 == V_72 ||
V_28 == V_73 )
V_44 = F_34 ( V_13 -> V_39 ,
V_74 ,
V_75 ) ;
else if ( V_28 == V_76 )
V_44 = F_34 ( V_13 -> V_39 ,
V_74 ,
V_77 ) ;
if ( V_44 < 0 )
goto V_78;
V_44 = F_29 ( V_13 ) ;
V_78:
if ( V_44 != V_48 )
return - V_41 ;
return 0 ;
}
static int F_35 ( struct V_10 * V_11 , int V_28 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
T_3 V_44 = V_48 ;
F_33 ( L_19 ,
V_19 , V_11 -> V_33 , V_28 ) ;
if ( V_28 == V_72 )
V_44 = F_34 ( V_13 -> V_39 ,
V_79 ,
V_75 ) ;
else if ( V_28 == V_73 )
V_44 = F_34 ( V_13 -> V_39 ,
V_80 ,
V_75 ) ;
else if ( V_28 == V_76 )
V_44 = F_34 ( V_13 -> V_39 ,
V_80 ,
V_77 ) ;
if ( V_44 < 0 )
goto V_78;
V_44 = F_29 ( V_13 ) ;
V_78:
if ( V_44 != V_48 )
return - V_41 ;
return 0 ;
}
static int F_36 ( struct V_10 * V_11 ,
struct V_81 * V_82 , int V_28 )
{
T_6 V_83 ;
F_33 ( L_20 ,
V_19 , V_11 -> V_33 , V_82 -> V_84 -> V_85 ,
F_37 ( V_82 -> V_86 ) , F_38 ( V_82 -> V_86 ) , V_28 ) ;
switch ( V_28 ) {
case V_72 :
case V_73 :
F_39 ( V_82 , V_87 , & V_83 ) ;
V_83 |= V_88 ;
F_40 ( V_82 , V_87 , V_83 ) ;
break;
case V_76 :
F_39 ( V_82 , V_87 , & V_83 ) ;
V_83 &= ~ V_88 ;
F_40 ( V_82 , V_87 , V_83 ) ;
break;
}
return 0 ;
}
static int F_41 ( struct V_26 * V_27 , int V_28 )
{
struct V_10 * V_11 = V_27 -> V_13 ;
struct V_89 * V_84 ;
int V_16 ;
if ( ! ( V_27 -> type & V_53 ) &&
( V_28 == V_73 ||
V_28 == V_72 ) ) {
V_16 = F_28 ( V_27 ) ;
if ( V_16 )
return - V_41 ;
}
if ( V_27 -> type & V_53 ) {
V_16 = F_32 ( V_11 , V_28 ) ;
} else {
V_84 = F_42 ( V_27 ) ;
if ( F_43 ( V_84 ) ||
F_43 ( V_84 -> V_90 ) )
V_16 = F_35 ( V_11 , V_28 ) ;
else
V_16 = F_36 ( V_11 , V_84 -> V_91 , V_28 ) ;
}
return V_16 ;
}
static int F_44 ( struct V_26 * V_27 )
{
return 0 ;
}
static void F_45 ( struct V_92 * V_7 )
{
F_46 ( L_21 , V_7 -> V_93 ) ;
F_46 ( L_22 , V_7 -> V_94 ) ;
F_46 ( L_23 , V_7 -> V_95 ) ;
F_46 ( L_24 , V_7 -> V_96 ) ;
F_46 ( L_25 , V_7 -> V_97 ) ;
F_46 ( L_26 , V_7 -> V_98 ) ;
F_46 ( L_27 , V_7 -> V_99 ) ;
F_46 ( L_28 , V_7 -> V_100 ) ;
F_46 ( L_29 , V_7 -> V_101 ) ;
F_46 ( L_30 , V_7 -> V_102 ) ;
}
static void F_47 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_92 * V_7 = & V_13 -> V_45 . V_103 ;
long V_44 ;
V_44 = F_48 ( V_13 -> V_104 , V_7 , sizeof( * V_7 ) ) ;
if ( V_44 != V_48 ) {
F_21 ( L_31 ,
V_19 , V_13 -> V_104 , V_44 ) ;
return;
}
switch ( V_7 -> type ) {
case V_105 :
F_46 ( L_32 ) ;
F_45 ( V_7 ) ;
F_46 ( L_33 , V_7 -> V_106 . V_107 ) ;
F_46 ( L_34 , V_7 -> V_106 . V_108 ) ;
break;
case V_109 :
F_46 ( L_35 ,
V_7 -> V_110 . V_111 ? L_36 : L_37 ) ;
F_45 ( V_7 ) ;
F_46 ( L_38 , V_7 -> V_110 . V_112 ) ;
F_46 ( L_39 , V_7 -> V_110 . V_113 ) ;
F_46 ( L_40 , V_7 -> V_110 . V_114 ) ;
F_46 ( L_41 , V_7 -> V_110 . V_115 ) ;
break;
case V_116 :
F_46 ( L_42 ,
V_7 -> V_117 . V_118 ) ;
F_45 ( V_7 ) ;
F_46 ( L_43 , V_7 -> V_117 . V_119 ) ;
F_46 ( L_44 , V_7 -> V_117 . V_120 ) ;
break;
case V_121 :
F_46 ( L_45 ) ;
F_45 ( V_7 ) ;
break;
case V_122 :
F_46 ( L_46 ) ;
F_45 ( V_7 ) ;
break;
default:
F_21 ( L_47 ,
V_19 , V_13 -> V_104 , V_7 -> type ) ;
}
}
static int F_49 ( struct V_10 * V_11 ,
struct V_26 * * V_27 )
{
struct V_26 * V_123 ;
V_123 = F_50 ( V_11 ) ;
if ( ! V_123 ) {
F_21 ( L_48 ,
V_19 , V_11 -> V_33 ) ;
return - V_36 ;
}
* V_27 = V_123 ;
return 0 ;
}
static int F_51 ( struct V_10 * V_11 ,
T_6 V_29 , struct V_26 * * V_27 )
{
struct V_26 * V_123 , * V_124 ;
struct V_125 V_82 ;
if ( F_49 ( V_11 , & V_123 ) )
return - V_36 ;
memset ( & V_82 , 0 , sizeof( struct V_125 ) ) ;
V_82 . V_13 = V_11 ;
V_82 . V_126 = V_29 ;
V_124 = F_52 ( & V_82 ) ;
if ( ! V_124 ) return - V_36 ;
* V_27 = V_124 ;
return 0 ;
}
static int F_53 ( struct V_26 * * V_27 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
T_2 V_127 ;
T_6 V_128 , V_129 ;
long V_44 ;
int V_16 = V_130 ;
F_54 ( NULL ) ;
F_55 ( V_6 , 0x0ul ) ;
F_56 (hose, &hose_list, list_node) {
V_13 = V_11 -> V_14 ;
if ( V_13 -> V_24 & V_131 )
continue;
V_44 = F_57 ( V_13 -> V_39 ,
& V_127 , & V_128 , & V_129 ) ;
if ( V_44 != V_48 ) {
F_58 ( L_49
L_50 ,
V_19 , V_11 -> V_33 , V_44 ) ;
continue;
}
if ( V_128 == V_132 ||
V_129 == V_133 ) {
F_58 ( L_51 ,
V_19 , V_11 -> V_33 ) ;
continue;
}
F_58 ( L_52 ,
V_19 , V_128 , V_129 ,
V_127 , V_11 -> V_33 ) ;
switch ( V_128 ) {
case V_134 :
if ( V_129 == V_135 ) {
F_56 (hose, &hose_list,
list_node) {
V_13 = V_11 -> V_14 ;
V_13 -> V_24 |= V_131 ;
}
F_16 ( L_53 ) ;
V_16 = V_136 ;
} else if ( V_129 == V_137 ) {
F_46 ( L_54
L_55 ) ;
F_47 ( V_11 ) ;
V_16 = V_130 ;
}
break;
case V_55 :
if ( V_129 == V_138 ) {
if ( F_49 ( V_11 , V_27 ) )
break;
F_16 ( L_56 ,
V_11 -> V_33 ) ;
V_13 -> V_24 |= V_131 ;
V_16 = V_139 ;
} else if ( V_129 == V_140 ) {
if ( F_49 ( V_11 , V_27 ) )
break;
F_16 ( L_57 ,
V_11 -> V_33 ) ;
V_16 = V_141 ;
} else if ( V_129 == V_137 ) {
F_46 ( L_58
L_55 ,
V_11 -> V_33 ) ;
F_22 ( V_11 ) ;
V_16 = V_130 ;
}
break;
case V_142 :
if ( F_51 ( V_11 , V_127 , V_27 ) ) {
if ( ! F_49 ( V_11 , V_27 ) ) {
F_16 ( L_59
L_60 ,
V_11 -> V_33 ,
V_127 ) ;
V_16 = V_141 ;
} else {
V_16 = V_130 ;
}
} else {
F_16 ( L_61 ,
( * V_27 ) -> V_30 , ( * V_27 ) -> V_13 -> V_33 ) ;
V_16 = V_143 ;
}
break;
default:
F_59 ( L_62 ,
V_19 , V_128 ) ;
}
if ( ( V_16 == V_143 ||
V_16 == V_141 ) &&
! ( ( * V_27 ) -> V_60 & V_61 ) ) {
F_27 ( * V_27 , V_61 ) ;
F_22 ( V_11 ) ;
}
if ( V_16 > V_144 )
break;
}
return V_16 ;
}
