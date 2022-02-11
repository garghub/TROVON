static int F_1 ( void * V_1 , struct V_2 * V_2 )
{
struct V_3 * exp = V_1 ;
int V_4 ;
struct V_2 * V_5 ;
struct V_2 * V_6 ;
if ( exp -> V_7 & V_8 )
return 1 ;
V_5 = F_2 ( V_2 ) ;
while ( V_5 != exp -> V_9 . V_2 && ! F_3 ( V_5 ) ) {
int V_10 ;
V_6 = F_4 ( V_5 ) ;
V_10 = F_5 ( V_6 -> V_11 , V_12 ) ;
if ( V_10 < 0 ) {
F_6 ( V_6 ) ;
break;
}
F_6 ( V_5 ) ;
V_5 = V_6 ;
}
if ( V_5 != exp -> V_9 . V_2 )
F_7 ( L_1 , V_5 , V_5 -> V_13 . V_14 ) ;
V_4 = ( V_5 == exp -> V_9 . V_2 ) ;
F_6 ( V_5 ) ;
return V_4 ;
}
static inline T_1
F_8 ( struct V_15 * V_16 , T_2 V_17 , T_2 V_18 )
{
V_17 &= V_19 ;
if ( V_18 == 0 )
return V_20 ;
if ( V_17 == V_18 )
return V_20 ;
if ( V_16 -> V_21 == 4 && V_17 == V_22 )
return V_23 ;
if ( V_18 == V_24 )
return V_25 ;
if ( V_17 == V_24 )
return V_26 ;
return V_27 ;
}
static T_1 F_9 ( struct V_15 * V_16 ,
struct V_3 * exp )
{
int V_28 = F_10 ( V_16 , exp ) ;
if ( ! V_16 -> V_29 && ! ( V_28 & V_30 ) ) {
F_11 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_7 ( V_31
L_2 ,
F_12 ( V_16 , V_32 , sizeof( V_32 ) ) ) ;
return V_33 ;
}
return F_13 ( F_14 ( V_16 , exp ) ) ;
}
static inline T_1 F_15 ( struct V_15 * V_16 ,
struct V_2 * V_2 , struct V_3 * exp )
{
if ( ! ( exp -> V_7 & V_34 ) )
return V_20 ;
if ( ! F_16 ( V_16 ) )
return V_35 ;
if ( F_17 ( ! F_18 ( V_2 -> V_11 -> V_36 ) &&
! F_19 ( V_2 -> V_11 -> V_36 ) ) )
return V_35 ;
if ( F_17 ( V_2 != exp -> V_9 . V_2 ) )
return V_35 ;
return V_20 ;
}
static T_1 F_20 ( struct V_15 * V_16 , struct V_37 * V_38 )
{
struct V_39 * V_40 = & V_38 -> V_41 ;
struct V_42 * V_42 = NULL , V_43 ;
struct V_3 * exp ;
struct V_2 * V_2 ;
int V_44 ;
int V_45 = V_40 -> V_46 / 4 ;
T_1 error ;
error = V_35 ;
if ( V_16 -> V_21 > 2 )
error = V_47 ;
if ( V_16 -> V_21 == 4 && V_40 -> V_46 == 0 )
return V_48 ;
if ( V_40 -> V_49 == 1 ) {
int V_50 ;
if ( -- V_45 < 0 )
return error ;
if ( V_40 -> V_51 != 0 )
return error ;
V_50 = F_21 ( V_40 -> V_52 ) / 4 ;
if ( V_50 == 0 )
return error ;
if ( V_40 -> V_52 == V_53 ) {
V_50 = F_21 ( V_54 ) / 4 ;
V_40 -> V_52 = V_54 ;
V_40 -> V_55 [ 0 ] = F_22 ( F_23 ( F_24 ( V_40 -> V_55 [ 0 ] ) , F_24 ( V_40 -> V_55 [ 1 ] ) ) ) ;
V_40 -> V_55 [ 1 ] = V_40 -> V_55 [ 2 ] ;
}
V_45 -= V_50 ;
if ( V_45 < 0 )
return error ;
exp = F_25 ( V_16 , V_40 -> V_52 , V_40 -> V_56 ) ;
V_42 = (struct V_42 * ) ( V_40 -> V_56 + V_50 ) ;
} else {
T_3 V_57 [ 2 ] ;
T_4 V_58 ;
T_5 V_59 ;
if ( V_40 -> V_46 != V_60 )
return error ;
V_58 = F_26 ( V_40 -> V_61 ) ;
V_59 = F_27 ( V_40 -> V_62 ) ;
F_28 ( V_63 , V_57 , V_58 , V_59 , 0 , NULL ) ;
exp = F_25 ( V_16 , V_63 , V_57 ) ;
}
error = V_35 ;
if ( F_29 ( exp ) == - V_64 )
return error ;
if ( F_30 ( exp ) )
return F_13 ( F_29 ( exp ) ) ;
if ( exp -> V_7 & V_8 ) {
struct V_65 * V_66 = F_31 () ;
if ( ! V_66 )
return F_13 ( - V_67 ) ;
V_66 -> V_68 =
F_32 ( V_66 -> V_68 ,
V_66 -> V_69 ) ;
F_33 ( F_34 ( V_66 ) ) ;
F_33 ( V_66 ) ;
} else {
error = F_9 ( V_16 , exp ) ;
if ( error )
goto V_70;
}
error = V_35 ;
if ( V_16 -> V_21 > 2 )
error = V_47 ;
if ( V_40 -> V_49 != 1 ) {
V_43 . V_71 . V_72 = V_40 -> V_73 ;
V_43 . V_71 . V_74 = V_40 -> V_75 ;
V_43 . V_71 . V_76 = V_40 -> V_77 ;
V_42 = & V_43 ;
V_45 = 3 ;
if ( V_40 -> V_77 == 0 )
V_44 = V_78 ;
else
V_44 = V_79 ;
} else
V_44 = V_40 -> V_80 ;
if ( V_44 == V_81 )
V_2 = F_2 ( exp -> V_9 . V_2 ) ;
else {
V_2 = F_35 ( exp -> V_9 . V_82 , V_42 ,
V_45 , V_44 ,
F_1 , exp ) ;
}
if ( V_2 == NULL )
goto V_70;
if ( F_30 ( V_2 ) ) {
if ( F_29 ( V_2 ) != - V_83 )
error = F_13 ( F_29 ( V_2 ) ) ;
goto V_70;
}
if ( F_18 ( V_2 -> V_11 -> V_36 ) &&
( V_2 -> V_84 & V_85 ) ) {
F_36 ( L_3 ,
V_2 -> V_86 -> V_13 . V_14 , V_2 -> V_13 . V_14 ) ;
}
V_38 -> V_87 = V_2 ;
V_38 -> V_88 = exp ;
return 0 ;
V_70:
F_37 ( exp ) ;
return error ;
}
T_1
F_38 ( struct V_15 * V_16 , struct V_37 * V_38 , T_2 type , int V_89 )
{
struct V_3 * exp ;
struct V_2 * V_2 ;
T_1 error ;
F_7 ( L_4 , F_39 ( V_38 ) ) ;
if ( ! V_38 -> V_87 ) {
error = F_20 ( V_16 , V_38 ) ;
if ( error )
goto V_70;
}
V_2 = V_38 -> V_87 ;
exp = V_38 -> V_88 ;
error = F_15 ( V_16 , V_2 , exp ) ;
if ( error )
goto V_70;
error = F_9 ( V_16 , exp ) ;
if ( error )
goto V_70;
error = F_8 ( V_16 , V_2 -> V_11 -> V_36 , type ) ;
if ( error )
goto V_70;
if ( V_89 & V_90 || V_89 & V_91 )
goto V_92;
if ( V_89 & V_93
&& exp -> V_9 . V_2 == V_2 )
goto V_92;
error = F_40 ( exp , V_16 ) ;
if ( error )
goto V_70;
V_92:
error = F_41 ( V_16 , exp , V_2 , V_89 ) ;
if ( error ) {
F_7 ( L_5
L_6 ,
V_2 -> V_86 -> V_13 . V_14 ,
V_2 -> V_13 . V_14 ,
V_89 , F_24 ( error ) ) ;
}
V_70:
if ( error == V_35 )
V_94 . V_95 ++ ;
return error ;
}
static void F_42 ( struct V_37 * V_38 , struct V_3 * exp ,
struct V_2 * V_2 )
{
if ( V_2 != exp -> V_9 . V_2 ) {
struct V_42 * V_42 = (struct V_42 * )
( V_38 -> V_41 . V_56 + V_38 -> V_41 . V_46 / 4 - 1 ) ;
int V_96 = ( V_38 -> V_97 - V_38 -> V_41 . V_46 ) / 4 ;
int V_98 = ! ( exp -> V_7 & V_8 ) ;
V_38 -> V_41 . V_80 =
F_43 ( V_2 , V_42 , & V_96 , V_98 ) ;
V_38 -> V_41 . V_46 += V_96 * 4 ;
} else {
V_38 -> V_41 . V_80 = V_81 ;
}
}
static inline void F_44 ( struct V_2 * V_2 ,
struct V_3 * exp ,
struct V_39 * V_40 )
{
V_40 -> V_73 = F_45 ( V_2 -> V_11 -> V_99 ) ;
V_40 -> V_75 = V_2 -> V_11 -> V_100 ;
if ( F_18 ( V_2 -> V_11 -> V_36 ) ||
( exp -> V_7 & V_8 ) )
V_40 -> V_77 = 0 ;
}
static bool F_46 ( struct V_3 * exp )
{
return exp -> V_9 . V_2 == exp -> V_9 . V_2 -> V_101 -> V_102 ;
}
static struct V_103 * F_47 ( struct V_3 * exp )
{
return exp -> V_9 . V_2 -> V_11 -> V_104 ;
}
static bool F_48 ( T_6 V_105 , struct V_3 * exp )
{
switch ( V_105 ) {
case V_63 :
if ( ! F_49 ( F_47 ( exp ) -> V_106 ) )
return 0 ;
case V_53 :
case V_54 :
return F_47 ( exp ) -> V_107 -> V_108 & V_109 ;
case V_110 :
return exp -> V_7 & V_111 ;
case V_112 :
case V_113 :
if ( ! F_46 ( exp ) )
return 0 ;
case V_114 :
case V_115 :
return exp -> V_116 != NULL ;
}
return 1 ;
}
static void F_50 ( struct V_37 * V_38 , struct V_3 * exp , struct V_37 * V_117 )
{
T_6 V_118 ;
T_6 V_105 ;
V_119:
V_118 = 1 ;
if ( V_117 && V_117 -> V_88 == exp ) {
V_118 = V_117 -> V_41 . V_49 ;
V_105 = V_117 -> V_41 . V_52 ;
V_117 = NULL ;
switch ( V_118 ) {
case 0xca :
V_105 = V_63 ;
break;
case 1 :
break;
default:
goto V_119;
}
if ( ! F_48 ( V_105 , exp ) )
goto V_119;
} else if ( exp -> V_7 & V_111 ) {
V_105 = V_110 ;
} else if ( exp -> V_116 ) {
if ( V_38 -> V_97 >= 64 ) {
if ( F_46 ( exp ) )
V_105 = V_113 ;
else
V_105 = V_115 ;
} else {
if ( F_46 ( exp ) )
V_105 = V_112 ;
else
V_105 = V_114 ;
}
} else if ( ! F_49 ( F_47 ( exp ) -> V_106 ) )
V_105 = V_54 ;
else
V_105 = V_63 ;
V_38 -> V_41 . V_49 = V_118 ;
if ( V_118 )
V_38 -> V_41 . V_52 = V_105 ;
}
T_1
F_51 ( struct V_37 * V_38 , struct V_3 * exp , struct V_2 * V_2 ,
struct V_37 * V_117 )
{
struct V_120 * V_120 = V_2 -> V_11 ;
struct V_2 * V_6 = V_2 -> V_86 ;
T_3 * V_121 ;
T_4 V_122 = F_47 ( exp ) -> V_106 ;
F_7 ( L_7 ,
F_52 ( V_122 ) , F_53 ( V_122 ) ,
( long ) exp -> V_9 . V_2 -> V_11 -> V_99 ,
V_6 -> V_13 . V_14 , V_2 -> V_13 . V_14 ,
( V_120 ? V_120 -> V_99 : 0 ) ) ;
F_50 ( V_38 , exp , V_117 ) ;
if ( V_117 == V_38 )
F_54 ( V_117 ) ;
if ( V_38 -> V_123 || V_38 -> V_87 ) {
F_36 ( V_124 L_8 ,
V_6 -> V_13 . V_14 , V_2 -> V_13 . V_14 ) ;
}
if ( V_38 -> V_97 < V_60 )
F_36 ( V_124 L_9 ,
V_38 -> V_97 ,
V_6 -> V_13 . V_14 , V_2 -> V_13 . V_14 ) ;
V_38 -> V_87 = F_2 ( V_2 ) ;
V_38 -> V_88 = exp ;
F_55 ( & exp -> V_125 ) ;
if ( V_38 -> V_41 . V_49 == 0xca ) {
memset ( & V_38 -> V_41 . V_126 , 0 , V_60 ) ;
V_38 -> V_41 . V_46 = V_60 ;
V_38 -> V_41 . V_127 = 0xfeebbaca ;
V_38 -> V_41 . V_128 = F_56 ( V_122 ) ;
V_38 -> V_41 . V_61 = V_38 -> V_41 . V_128 ;
V_38 -> V_41 . V_62 =
F_45 ( exp -> V_9 . V_2 -> V_11 -> V_99 ) ;
V_38 -> V_41 . V_77 = F_45 ( V_76 ( V_2 ) ) ;
if ( V_120 )
F_44 ( V_2 , exp , & V_38 -> V_41 ) ;
} else {
int V_50 ;
V_38 -> V_41 . V_51 = 0 ;
V_121 = V_38 -> V_41 . V_56 + 0 ;
F_28 ( V_38 -> V_41 . V_52 , V_121 , V_122 ,
exp -> V_9 . V_2 -> V_11 -> V_99 ,
exp -> V_129 , exp -> V_116 ) ;
V_50 = F_21 ( V_38 -> V_41 . V_52 ) ;
V_121 += V_50 / 4 ;
V_38 -> V_41 . V_46 = 4 + V_50 ;
if ( V_120 )
F_42 ( V_38 , exp , V_2 ) ;
if ( V_38 -> V_41 . V_80 == 255 ) {
F_54 ( V_38 ) ;
return V_130 ;
}
}
return 0 ;
}
T_1
F_57 ( struct V_37 * V_38 )
{
struct V_2 * V_2 ;
if ( ! V_38 -> V_87 )
goto V_131;
V_2 = V_38 -> V_87 ;
if ( ! V_2 -> V_11 )
goto V_132;
if ( V_38 -> V_41 . V_49 != 1 ) {
F_44 ( V_2 , V_38 -> V_88 , & V_38 -> V_41 ) ;
} else {
if ( V_38 -> V_41 . V_80 != V_81 )
goto V_70;
F_42 ( V_38 , V_38 -> V_88 , V_2 ) ;
if ( V_38 -> V_41 . V_80 == 255 )
return V_130 ;
}
V_70:
return 0 ;
V_131:
F_36 ( V_124 L_10 ) ;
goto V_70;
V_132:
F_36 ( V_124 L_11 ,
V_2 -> V_86 -> V_13 . V_14 , V_2 -> V_13 . V_14 ) ;
goto V_70;
}
void
F_54 ( struct V_37 * V_38 )
{
struct V_2 * V_2 = V_38 -> V_87 ;
struct V_3 * exp = V_38 -> V_88 ;
if ( V_2 ) {
F_58 ( V_38 ) ;
V_38 -> V_87 = NULL ;
F_6 ( V_2 ) ;
#ifdef F_59
V_38 -> V_133 = 0 ;
V_38 -> V_134 = 0 ;
#endif
}
if ( exp ) {
F_37 ( exp ) ;
V_38 -> V_88 = NULL ;
}
return;
}
char * F_39 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = & V_38 -> V_41 ;
static char V_32 [ 80 ] ;
sprintf ( V_32 , L_12 ,
V_40 -> V_46 ,
V_40 -> V_126 . V_135 [ 0 ] ,
V_40 -> V_126 . V_135 [ 1 ] ,
V_40 -> V_126 . V_135 [ 2 ] ,
V_40 -> V_126 . V_135 [ 3 ] ,
V_40 -> V_126 . V_135 [ 4 ] ,
V_40 -> V_126 . V_135 [ 5 ] ) ;
return V_32 ;
}
enum V_136 V_136 ( struct V_37 * V_38 )
{
if ( V_38 -> V_41 . V_49 != 1 )
return V_137 ;
switch( V_38 -> V_41 . V_52 ) {
case V_63 :
case V_54 :
case V_53 :
if ( F_47 ( V_38 -> V_88 ) -> V_107 -> V_108 & V_109 )
return V_137 ;
break;
case V_110 :
if ( V_38 -> V_88 -> V_7 & V_111 )
return V_138 ;
break;
default:
break;
}
if ( V_38 -> V_88 -> V_7 & V_111 )
return V_138 ;
if ( V_38 -> V_88 -> V_116 )
return V_139 ;
return V_137 ;
}
