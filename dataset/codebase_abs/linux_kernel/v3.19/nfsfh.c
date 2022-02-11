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
F_7 ( L_1 , V_5 , V_5 ) ;
V_4 = ( V_5 == exp -> V_9 . V_2 ) ;
F_6 ( V_5 ) ;
return V_4 ;
}
static inline T_1
F_8 ( struct V_13 * V_14 , T_2 V_15 , T_2 V_16 )
{
V_15 &= V_17 ;
if ( V_16 == 0 )
return V_18 ;
if ( V_15 == V_16 )
return V_18 ;
if ( V_14 -> V_19 == 4 && V_15 == V_20 )
return V_21 ;
if ( V_16 == V_22 )
return V_23 ;
if ( V_15 == V_22 )
return V_24 ;
return V_25 ;
}
static T_1 F_9 ( struct V_13 * V_14 ,
struct V_3 * exp )
{
int V_26 = F_10 ( V_14 , exp ) ;
if ( ! F_11 ( V_27 , & V_14 -> V_28 ) && ! ( V_26 & V_29 ) ) {
F_12 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_7 ( L_2 ,
F_13 ( V_14 , V_30 , sizeof( V_30 ) ) ) ;
return V_31 ;
}
return F_14 ( F_15 ( V_14 , exp ) ) ;
}
static inline T_1 F_16 ( struct V_13 * V_14 ,
struct V_2 * V_2 , struct V_3 * exp )
{
if ( ! ( exp -> V_7 & V_32 ) )
return V_18 ;
if ( ! F_17 ( V_14 ) )
return V_33 ;
if ( F_18 ( ! F_19 ( V_2 -> V_11 -> V_34 ) &&
! F_20 ( V_2 -> V_11 -> V_34 ) ) )
return V_33 ;
if ( F_18 ( V_2 != exp -> V_9 . V_2 ) )
return V_33 ;
return V_18 ;
}
static T_1 F_21 ( struct V_13 * V_14 , struct V_35 * V_36 )
{
struct V_37 * V_38 = & V_36 -> V_39 ;
struct V_40 * V_40 = NULL , V_41 ;
struct V_3 * exp ;
struct V_2 * V_2 ;
int V_42 ;
int V_43 = V_38 -> V_44 / 4 ;
T_1 error ;
error = V_33 ;
if ( V_14 -> V_19 > 2 )
error = V_45 ;
if ( V_14 -> V_19 == 4 && V_38 -> V_44 == 0 )
return V_46 ;
if ( V_38 -> V_47 == 1 ) {
int V_48 ;
if ( -- V_43 < 0 )
return error ;
if ( V_38 -> V_49 != 0 )
return error ;
V_48 = F_22 ( V_38 -> V_50 ) / 4 ;
if ( V_48 == 0 )
return error ;
if ( V_38 -> V_50 == V_51 ) {
V_48 = F_22 ( V_52 ) / 4 ;
V_38 -> V_50 = V_52 ;
V_38 -> V_53 [ 0 ] = F_23 ( F_24 ( F_25 ( ( V_54 T_1 ) V_38 -> V_53 [ 0 ] ) ,
F_25 ( ( V_54 T_1 ) V_38 -> V_53 [ 1 ] ) ) ) ;
V_38 -> V_53 [ 1 ] = V_38 -> V_53 [ 2 ] ;
}
V_43 -= V_48 ;
if ( V_43 < 0 )
return error ;
exp = F_26 ( V_14 , V_38 -> V_50 , V_38 -> V_53 ) ;
V_40 = (struct V_40 * ) ( V_38 -> V_53 + V_48 ) ;
} else {
T_3 V_55 [ 2 ] ;
T_4 V_56 ;
T_5 V_57 ;
if ( V_38 -> V_44 != V_58 )
return error ;
V_56 = F_27 ( V_38 -> V_59 ) ;
V_57 = F_28 ( V_38 -> V_60 ) ;
F_29 ( V_61 , V_55 , V_56 , V_57 , 0 , NULL ) ;
exp = F_26 ( V_14 , V_61 , V_55 ) ;
}
error = V_33 ;
if ( F_30 ( exp ) == - V_62 )
return error ;
if ( F_31 ( exp ) )
return F_14 ( F_30 ( exp ) ) ;
if ( exp -> V_7 & V_8 ) {
struct V_63 * V_64 = F_32 () ;
if ( ! V_64 ) {
error = F_14 ( - V_65 ) ;
goto V_66;
}
V_64 -> V_67 =
F_33 ( V_64 -> V_67 ,
V_64 -> V_68 ) ;
F_34 ( F_35 ( V_64 ) ) ;
F_34 ( V_64 ) ;
} else {
error = F_9 ( V_14 , exp ) ;
if ( error )
goto V_66;
}
error = V_33 ;
if ( V_14 -> V_19 > 2 )
error = V_45 ;
if ( V_38 -> V_47 != 1 ) {
V_41 . V_69 . V_70 = V_38 -> V_71 ;
V_41 . V_69 . V_72 = V_38 -> V_73 ;
V_41 . V_69 . V_74 = V_38 -> V_75 ;
V_40 = & V_41 ;
V_43 = 3 ;
if ( V_38 -> V_75 == 0 )
V_42 = V_76 ;
else
V_42 = V_77 ;
} else
V_42 = V_38 -> V_78 ;
if ( V_42 == V_79 )
V_2 = F_2 ( exp -> V_9 . V_2 ) ;
else {
V_2 = F_36 ( exp -> V_9 . V_80 , V_40 ,
V_43 , V_42 ,
F_1 , exp ) ;
}
if ( V_2 == NULL )
goto V_66;
if ( F_31 ( V_2 ) ) {
if ( F_30 ( V_2 ) != - V_81 )
error = F_14 ( F_30 ( V_2 ) ) ;
goto V_66;
}
if ( F_19 ( V_2 -> V_11 -> V_34 ) &&
( V_2 -> V_82 & V_83 ) ) {
F_37 ( L_3 ,
V_2 ) ;
}
V_36 -> V_84 = V_2 ;
V_36 -> V_85 = exp ;
return 0 ;
V_66:
F_38 ( exp ) ;
return error ;
}
T_1
F_39 ( struct V_13 * V_14 , struct V_35 * V_36 , T_2 type , int V_86 )
{
struct V_3 * exp ;
struct V_2 * V_2 ;
T_1 error ;
F_7 ( L_4 , F_40 ( V_36 ) ) ;
if ( ! V_36 -> V_84 ) {
error = F_21 ( V_14 , V_36 ) ;
if ( error )
goto V_66;
}
V_2 = V_36 -> V_84 ;
exp = V_36 -> V_85 ;
error = F_16 ( V_14 , V_2 , exp ) ;
if ( error )
goto V_66;
error = F_9 ( V_14 , exp ) ;
if ( error )
goto V_66;
error = F_8 ( V_14 , V_2 -> V_11 -> V_34 , type ) ;
if ( error )
goto V_66;
if ( V_86 & V_87 || V_86 & V_88 )
goto V_89;
if ( V_86 & V_90
&& exp -> V_9 . V_2 == V_2 )
goto V_89;
error = F_41 ( exp , V_14 ) ;
if ( error )
goto V_66;
V_89:
error = F_42 ( V_14 , exp , V_2 , V_86 ) ;
if ( error ) {
F_7 ( L_5
L_6 ,
V_2 ,
V_86 , F_25 ( error ) ) ;
}
V_66:
if ( error == V_33 )
V_91 . V_92 ++ ;
return error ;
}
static void F_43 ( struct V_35 * V_36 , struct V_3 * exp ,
struct V_2 * V_2 )
{
if ( V_2 != exp -> V_9 . V_2 ) {
struct V_40 * V_40 = (struct V_40 * )
( V_36 -> V_39 . V_53 + V_36 -> V_39 . V_44 / 4 - 1 ) ;
int V_93 = ( V_36 -> V_94 - V_36 -> V_39 . V_44 ) / 4 ;
int V_95 = ! ( exp -> V_7 & V_8 ) ;
V_36 -> V_39 . V_78 =
F_44 ( V_2 , V_40 , & V_93 , V_95 ) ;
V_36 -> V_39 . V_44 += V_93 * 4 ;
} else {
V_36 -> V_39 . V_78 = V_79 ;
}
}
static inline void F_45 ( struct V_2 * V_2 ,
struct V_3 * exp ,
struct V_37 * V_38 )
{
V_38 -> V_71 = F_46 ( V_2 -> V_11 -> V_96 ) ;
V_38 -> V_73 = V_2 -> V_11 -> V_97 ;
if ( F_19 ( V_2 -> V_11 -> V_34 ) ||
( exp -> V_7 & V_8 ) )
V_38 -> V_75 = 0 ;
}
static bool F_47 ( struct V_3 * exp )
{
return exp -> V_9 . V_2 == exp -> V_9 . V_2 -> V_98 -> V_99 ;
}
static struct V_100 * F_48 ( struct V_3 * exp )
{
return exp -> V_9 . V_2 -> V_11 -> V_101 ;
}
static bool F_49 ( T_6 V_102 , struct V_3 * exp )
{
switch ( V_102 ) {
case V_61 :
if ( ! F_50 ( F_48 ( exp ) -> V_103 ) )
return 0 ;
case V_51 :
case V_52 :
return F_48 ( exp ) -> V_104 -> V_105 & V_106 ;
case V_107 :
return exp -> V_7 & V_108 ;
case V_109 :
case V_110 :
if ( ! F_47 ( exp ) )
return 0 ;
case V_111 :
case V_112 :
return exp -> V_113 != NULL ;
}
return 1 ;
}
static void F_51 ( struct V_35 * V_36 , struct V_3 * exp , struct V_35 * V_114 )
{
T_6 V_115 ;
T_6 V_102 ;
V_116:
V_115 = 1 ;
if ( V_114 && V_114 -> V_85 == exp ) {
V_115 = V_114 -> V_39 . V_47 ;
V_102 = V_114 -> V_39 . V_50 ;
V_114 = NULL ;
switch ( V_115 ) {
case 0xca :
V_102 = V_61 ;
break;
case 1 :
break;
default:
goto V_116;
}
if ( ! F_49 ( V_102 , exp ) )
goto V_116;
} else if ( exp -> V_7 & V_108 ) {
V_102 = V_107 ;
} else if ( exp -> V_113 ) {
if ( V_36 -> V_94 >= 64 ) {
if ( F_47 ( exp ) )
V_102 = V_110 ;
else
V_102 = V_112 ;
} else {
if ( F_47 ( exp ) )
V_102 = V_109 ;
else
V_102 = V_111 ;
}
} else if ( ! F_50 ( F_48 ( exp ) -> V_103 ) )
V_102 = V_52 ;
else
V_102 = V_61 ;
V_36 -> V_39 . V_47 = V_115 ;
if ( V_115 )
V_36 -> V_39 . V_50 = V_102 ;
}
T_1
F_52 ( struct V_35 * V_36 , struct V_3 * exp , struct V_2 * V_2 ,
struct V_35 * V_114 )
{
struct V_117 * V_117 = V_2 -> V_11 ;
T_4 V_118 = F_48 ( exp ) -> V_103 ;
F_7 ( L_7 ,
F_53 ( V_118 ) , F_54 ( V_118 ) ,
( long ) exp -> V_9 . V_2 -> V_11 -> V_96 ,
V_2 ,
( V_117 ? V_117 -> V_96 : 0 ) ) ;
F_51 ( V_36 , exp , V_114 ) ;
if ( V_114 == V_36 )
F_55 ( V_114 ) ;
if ( V_36 -> V_119 || V_36 -> V_84 ) {
F_37 ( V_120 L_8 ,
V_2 ) ;
}
if ( V_36 -> V_94 < V_58 )
F_37 ( V_120 L_9 ,
V_36 -> V_94 ,
V_2 ) ;
V_36 -> V_84 = F_2 ( V_2 ) ;
V_36 -> V_85 = F_56 ( exp ) ;
if ( V_36 -> V_39 . V_47 == 0xca ) {
memset ( & V_36 -> V_39 . V_121 , 0 , V_58 ) ;
V_36 -> V_39 . V_44 = V_58 ;
V_36 -> V_39 . V_122 = 0xfeebbaca ;
V_36 -> V_39 . V_123 = F_57 ( V_118 ) ;
V_36 -> V_39 . V_59 = V_36 -> V_39 . V_123 ;
V_36 -> V_39 . V_60 =
F_46 ( exp -> V_9 . V_2 -> V_11 -> V_96 ) ;
V_36 -> V_39 . V_75 = F_46 ( V_74 ( V_2 ) ) ;
if ( V_117 )
F_45 ( V_2 , exp , & V_36 -> V_39 ) ;
} else {
V_36 -> V_39 . V_44 =
F_22 ( V_36 -> V_39 . V_50 ) + 4 ;
V_36 -> V_39 . V_49 = 0 ;
F_29 ( V_36 -> V_39 . V_50 ,
V_36 -> V_39 . V_53 ,
V_118 ,
exp -> V_9 . V_2 -> V_11 -> V_96 ,
exp -> V_124 , exp -> V_113 ) ;
if ( V_117 )
F_43 ( V_36 , exp , V_2 ) ;
if ( V_36 -> V_39 . V_78 == V_125 ) {
F_55 ( V_36 ) ;
return V_126 ;
}
}
return 0 ;
}
T_1
F_58 ( struct V_35 * V_36 )
{
struct V_2 * V_2 ;
if ( ! V_36 -> V_84 )
goto V_127;
V_2 = V_36 -> V_84 ;
if ( ! V_2 -> V_11 )
goto V_128;
if ( V_36 -> V_39 . V_47 != 1 ) {
F_45 ( V_2 , V_36 -> V_85 , & V_36 -> V_39 ) ;
} else {
if ( V_36 -> V_39 . V_78 != V_79 )
return 0 ;
F_43 ( V_36 , V_36 -> V_85 , V_2 ) ;
if ( V_36 -> V_39 . V_78 == V_125 )
return V_126 ;
}
return 0 ;
V_127:
F_37 ( V_120 L_10 ) ;
return V_129 ;
V_128:
F_37 ( V_120 L_11 ,
V_2 ) ;
return V_129 ;
}
void
F_55 ( struct V_35 * V_36 )
{
struct V_2 * V_2 = V_36 -> V_84 ;
struct V_3 * exp = V_36 -> V_85 ;
if ( V_2 ) {
F_59 ( V_36 ) ;
V_36 -> V_84 = NULL ;
F_6 ( V_2 ) ;
#ifdef F_60
V_36 -> V_130 = 0 ;
V_36 -> V_131 = 0 ;
#endif
}
F_61 ( V_36 ) ;
if ( exp ) {
F_38 ( exp ) ;
V_36 -> V_85 = NULL ;
}
return;
}
char * F_40 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = & V_36 -> V_39 ;
static char V_30 [ 80 ] ;
sprintf ( V_30 , L_12 ,
V_38 -> V_44 ,
V_38 -> V_121 . V_132 [ 0 ] ,
V_38 -> V_121 . V_132 [ 1 ] ,
V_38 -> V_121 . V_132 [ 2 ] ,
V_38 -> V_121 . V_132 [ 3 ] ,
V_38 -> V_121 . V_132 [ 4 ] ,
V_38 -> V_121 . V_132 [ 5 ] ) ;
return V_30 ;
}
enum V_133 V_133 ( struct V_35 * V_36 )
{
if ( V_36 -> V_39 . V_47 != 1 )
return V_134 ;
switch( V_36 -> V_39 . V_50 ) {
case V_61 :
case V_52 :
case V_51 :
if ( F_48 ( V_36 -> V_85 ) -> V_104 -> V_105 & V_106 )
return V_134 ;
break;
case V_107 :
if ( V_36 -> V_85 -> V_7 & V_108 )
return V_135 ;
break;
default:
break;
}
if ( V_36 -> V_85 -> V_7 & V_108 )
return V_135 ;
if ( V_36 -> V_85 -> V_113 )
return V_136 ;
return V_134 ;
}
