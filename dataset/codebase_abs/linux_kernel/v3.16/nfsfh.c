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
if ( ! V_14 -> V_27 && ! ( V_26 & V_28 ) ) {
F_11 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_7 ( L_2 ,
F_12 ( V_14 , V_29 , sizeof( V_29 ) ) ) ;
return V_30 ;
}
return F_13 ( F_14 ( V_14 , exp ) ) ;
}
static inline T_1 F_15 ( struct V_13 * V_14 ,
struct V_2 * V_2 , struct V_3 * exp )
{
if ( ! ( exp -> V_7 & V_31 ) )
return V_18 ;
if ( ! F_16 ( V_14 ) )
return V_32 ;
if ( F_17 ( ! F_18 ( V_2 -> V_11 -> V_33 ) &&
! F_19 ( V_2 -> V_11 -> V_33 ) ) )
return V_32 ;
if ( F_17 ( V_2 != exp -> V_9 . V_2 ) )
return V_32 ;
return V_18 ;
}
static T_1 F_20 ( struct V_13 * V_14 , struct V_34 * V_35 )
{
struct V_36 * V_37 = & V_35 -> V_38 ;
struct V_39 * V_39 = NULL , V_40 ;
struct V_3 * exp ;
struct V_2 * V_2 ;
int V_41 ;
int V_42 = V_37 -> V_43 / 4 ;
T_1 error ;
error = V_32 ;
if ( V_14 -> V_19 > 2 )
error = V_44 ;
if ( V_14 -> V_19 == 4 && V_37 -> V_43 == 0 )
return V_45 ;
if ( V_37 -> V_46 == 1 ) {
int V_47 ;
if ( -- V_42 < 0 )
return error ;
if ( V_37 -> V_48 != 0 )
return error ;
V_47 = F_21 ( V_37 -> V_49 ) / 4 ;
if ( V_47 == 0 )
return error ;
if ( V_37 -> V_49 == V_50 ) {
V_47 = F_21 ( V_51 ) / 4 ;
V_37 -> V_49 = V_51 ;
V_37 -> V_52 [ 0 ] = F_22 ( F_23 ( F_24 ( V_37 -> V_52 [ 0 ] ) , F_24 ( V_37 -> V_52 [ 1 ] ) ) ) ;
V_37 -> V_52 [ 1 ] = V_37 -> V_52 [ 2 ] ;
}
V_42 -= V_47 ;
if ( V_42 < 0 )
return error ;
exp = F_25 ( V_14 , V_37 -> V_49 , V_37 -> V_52 ) ;
V_39 = (struct V_39 * ) ( V_37 -> V_52 + V_47 ) ;
} else {
T_3 V_53 [ 2 ] ;
T_4 V_54 ;
T_5 V_55 ;
if ( V_37 -> V_43 != V_56 )
return error ;
V_54 = F_26 ( V_37 -> V_57 ) ;
V_55 = F_27 ( V_37 -> V_58 ) ;
F_28 ( V_59 , V_53 , V_54 , V_55 , 0 , NULL ) ;
exp = F_25 ( V_14 , V_59 , V_53 ) ;
}
error = V_32 ;
if ( F_29 ( exp ) == - V_60 )
return error ;
if ( F_30 ( exp ) )
return F_13 ( F_29 ( exp ) ) ;
if ( exp -> V_7 & V_8 ) {
struct V_61 * V_62 = F_31 () ;
if ( ! V_62 )
return F_13 ( - V_63 ) ;
V_62 -> V_64 =
F_32 ( V_62 -> V_64 ,
V_62 -> V_65 ) ;
F_33 ( F_34 ( V_62 ) ) ;
F_33 ( V_62 ) ;
} else {
error = F_9 ( V_14 , exp ) ;
if ( error )
goto V_66;
}
error = V_32 ;
if ( V_14 -> V_19 > 2 )
error = V_44 ;
if ( V_37 -> V_46 != 1 ) {
V_40 . V_67 . V_68 = V_37 -> V_69 ;
V_40 . V_67 . V_70 = V_37 -> V_71 ;
V_40 . V_67 . V_72 = V_37 -> V_73 ;
V_39 = & V_40 ;
V_42 = 3 ;
if ( V_37 -> V_73 == 0 )
V_41 = V_74 ;
else
V_41 = V_75 ;
} else
V_41 = V_37 -> V_76 ;
if ( V_41 == V_77 )
V_2 = F_2 ( exp -> V_9 . V_2 ) ;
else {
V_2 = F_35 ( exp -> V_9 . V_78 , V_39 ,
V_42 , V_41 ,
F_1 , exp ) ;
}
if ( V_2 == NULL )
goto V_66;
if ( F_30 ( V_2 ) ) {
if ( F_29 ( V_2 ) != - V_79 )
error = F_13 ( F_29 ( V_2 ) ) ;
goto V_66;
}
if ( F_18 ( V_2 -> V_11 -> V_33 ) &&
( V_2 -> V_80 & V_81 ) ) {
F_36 ( L_3 ,
V_2 ) ;
}
V_35 -> V_82 = V_2 ;
V_35 -> V_83 = exp ;
return 0 ;
V_66:
F_37 ( exp ) ;
return error ;
}
T_1
F_38 ( struct V_13 * V_14 , struct V_34 * V_35 , T_2 type , int V_84 )
{
struct V_3 * exp ;
struct V_2 * V_2 ;
T_1 error ;
F_7 ( L_4 , F_39 ( V_35 ) ) ;
if ( ! V_35 -> V_82 ) {
error = F_20 ( V_14 , V_35 ) ;
if ( error )
goto V_66;
}
V_2 = V_35 -> V_82 ;
exp = V_35 -> V_83 ;
error = F_15 ( V_14 , V_2 , exp ) ;
if ( error )
goto V_66;
error = F_9 ( V_14 , exp ) ;
if ( error )
goto V_66;
error = F_8 ( V_14 , V_2 -> V_11 -> V_33 , type ) ;
if ( error )
goto V_66;
if ( V_84 & V_85 || V_84 & V_86 )
goto V_87;
if ( V_84 & V_88
&& exp -> V_9 . V_2 == V_2 )
goto V_87;
error = F_40 ( exp , V_14 ) ;
if ( error )
goto V_66;
V_87:
error = F_41 ( V_14 , exp , V_2 , V_84 ) ;
if ( error ) {
F_7 ( L_5
L_6 ,
V_2 ,
V_84 , F_24 ( error ) ) ;
}
V_66:
if ( error == V_32 )
V_89 . V_90 ++ ;
return error ;
}
static void F_42 ( struct V_34 * V_35 , struct V_3 * exp ,
struct V_2 * V_2 )
{
if ( V_2 != exp -> V_9 . V_2 ) {
struct V_39 * V_39 = (struct V_39 * )
( V_35 -> V_38 . V_52 + V_35 -> V_38 . V_43 / 4 - 1 ) ;
int V_91 = ( V_35 -> V_92 - V_35 -> V_38 . V_43 ) / 4 ;
int V_93 = ! ( exp -> V_7 & V_8 ) ;
V_35 -> V_38 . V_76 =
F_43 ( V_2 , V_39 , & V_91 , V_93 ) ;
V_35 -> V_38 . V_43 += V_91 * 4 ;
} else {
V_35 -> V_38 . V_76 = V_77 ;
}
}
static inline void F_44 ( struct V_2 * V_2 ,
struct V_3 * exp ,
struct V_36 * V_37 )
{
V_37 -> V_69 = F_45 ( V_2 -> V_11 -> V_94 ) ;
V_37 -> V_71 = V_2 -> V_11 -> V_95 ;
if ( F_18 ( V_2 -> V_11 -> V_33 ) ||
( exp -> V_7 & V_8 ) )
V_37 -> V_73 = 0 ;
}
static bool F_46 ( struct V_3 * exp )
{
return exp -> V_9 . V_2 == exp -> V_9 . V_2 -> V_96 -> V_97 ;
}
static struct V_98 * F_47 ( struct V_3 * exp )
{
return exp -> V_9 . V_2 -> V_11 -> V_99 ;
}
static bool F_48 ( T_6 V_100 , struct V_3 * exp )
{
switch ( V_100 ) {
case V_59 :
if ( ! F_49 ( F_47 ( exp ) -> V_101 ) )
return 0 ;
case V_50 :
case V_51 :
return F_47 ( exp ) -> V_102 -> V_103 & V_104 ;
case V_105 :
return exp -> V_7 & V_106 ;
case V_107 :
case V_108 :
if ( ! F_46 ( exp ) )
return 0 ;
case V_109 :
case V_110 :
return exp -> V_111 != NULL ;
}
return 1 ;
}
static void F_50 ( struct V_34 * V_35 , struct V_3 * exp , struct V_34 * V_112 )
{
T_6 V_113 ;
T_6 V_100 ;
V_114:
V_113 = 1 ;
if ( V_112 && V_112 -> V_83 == exp ) {
V_113 = V_112 -> V_38 . V_46 ;
V_100 = V_112 -> V_38 . V_49 ;
V_112 = NULL ;
switch ( V_113 ) {
case 0xca :
V_100 = V_59 ;
break;
case 1 :
break;
default:
goto V_114;
}
if ( ! F_48 ( V_100 , exp ) )
goto V_114;
} else if ( exp -> V_7 & V_106 ) {
V_100 = V_105 ;
} else if ( exp -> V_111 ) {
if ( V_35 -> V_92 >= 64 ) {
if ( F_46 ( exp ) )
V_100 = V_108 ;
else
V_100 = V_110 ;
} else {
if ( F_46 ( exp ) )
V_100 = V_107 ;
else
V_100 = V_109 ;
}
} else if ( ! F_49 ( F_47 ( exp ) -> V_101 ) )
V_100 = V_51 ;
else
V_100 = V_59 ;
V_35 -> V_38 . V_46 = V_113 ;
if ( V_113 )
V_35 -> V_38 . V_49 = V_100 ;
}
T_1
F_51 ( struct V_34 * V_35 , struct V_3 * exp , struct V_2 * V_2 ,
struct V_34 * V_112 )
{
struct V_115 * V_115 = V_2 -> V_11 ;
T_4 V_116 = F_47 ( exp ) -> V_101 ;
F_7 ( L_7 ,
F_52 ( V_116 ) , F_53 ( V_116 ) ,
( long ) exp -> V_9 . V_2 -> V_11 -> V_94 ,
V_2 ,
( V_115 ? V_115 -> V_94 : 0 ) ) ;
F_50 ( V_35 , exp , V_112 ) ;
if ( V_112 == V_35 )
F_54 ( V_112 ) ;
if ( V_35 -> V_117 || V_35 -> V_82 ) {
F_36 ( V_118 L_8 ,
V_2 ) ;
}
if ( V_35 -> V_92 < V_56 )
F_36 ( V_118 L_9 ,
V_35 -> V_92 ,
V_2 ) ;
V_35 -> V_82 = F_2 ( V_2 ) ;
V_35 -> V_83 = exp ;
F_55 ( & exp -> V_119 ) ;
if ( V_35 -> V_38 . V_46 == 0xca ) {
memset ( & V_35 -> V_38 . V_120 , 0 , V_56 ) ;
V_35 -> V_38 . V_43 = V_56 ;
V_35 -> V_38 . V_121 = 0xfeebbaca ;
V_35 -> V_38 . V_122 = F_56 ( V_116 ) ;
V_35 -> V_38 . V_57 = V_35 -> V_38 . V_122 ;
V_35 -> V_38 . V_58 =
F_45 ( exp -> V_9 . V_2 -> V_11 -> V_94 ) ;
V_35 -> V_38 . V_73 = F_45 ( V_72 ( V_2 ) ) ;
if ( V_115 )
F_44 ( V_2 , exp , & V_35 -> V_38 ) ;
} else {
V_35 -> V_38 . V_43 =
F_21 ( V_35 -> V_38 . V_49 ) + 4 ;
V_35 -> V_38 . V_48 = 0 ;
F_28 ( V_35 -> V_38 . V_49 ,
V_35 -> V_38 . V_52 ,
V_116 ,
exp -> V_9 . V_2 -> V_11 -> V_94 ,
exp -> V_123 , exp -> V_111 ) ;
if ( V_115 )
F_42 ( V_35 , exp , V_2 ) ;
if ( V_35 -> V_38 . V_76 == V_124 ) {
F_54 ( V_35 ) ;
return V_125 ;
}
}
return 0 ;
}
T_1
F_57 ( struct V_34 * V_35 )
{
struct V_2 * V_2 ;
if ( ! V_35 -> V_82 )
goto V_126;
V_2 = V_35 -> V_82 ;
if ( ! V_2 -> V_11 )
goto V_127;
if ( V_35 -> V_38 . V_46 != 1 ) {
F_44 ( V_2 , V_35 -> V_83 , & V_35 -> V_38 ) ;
} else {
if ( V_35 -> V_38 . V_76 != V_77 )
return 0 ;
F_42 ( V_35 , V_35 -> V_83 , V_2 ) ;
if ( V_35 -> V_38 . V_76 == V_124 )
return V_125 ;
}
return 0 ;
V_126:
F_36 ( V_118 L_10 ) ;
return V_128 ;
V_127:
F_36 ( V_118 L_11 ,
V_2 ) ;
return V_128 ;
}
void
F_54 ( struct V_34 * V_35 )
{
struct V_2 * V_2 = V_35 -> V_82 ;
struct V_3 * exp = V_35 -> V_83 ;
if ( V_2 ) {
F_58 ( V_35 ) ;
V_35 -> V_82 = NULL ;
F_6 ( V_2 ) ;
#ifdef F_59
V_35 -> V_129 = 0 ;
V_35 -> V_130 = 0 ;
#endif
}
F_60 ( V_35 ) ;
if ( exp ) {
F_37 ( exp ) ;
V_35 -> V_83 = NULL ;
}
return;
}
char * F_39 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = & V_35 -> V_38 ;
static char V_29 [ 80 ] ;
sprintf ( V_29 , L_12 ,
V_37 -> V_43 ,
V_37 -> V_120 . V_131 [ 0 ] ,
V_37 -> V_120 . V_131 [ 1 ] ,
V_37 -> V_120 . V_131 [ 2 ] ,
V_37 -> V_120 . V_131 [ 3 ] ,
V_37 -> V_120 . V_131 [ 4 ] ,
V_37 -> V_120 . V_131 [ 5 ] ) ;
return V_29 ;
}
enum V_132 V_132 ( struct V_34 * V_35 )
{
if ( V_35 -> V_38 . V_46 != 1 )
return V_133 ;
switch( V_35 -> V_38 . V_49 ) {
case V_59 :
case V_51 :
case V_50 :
if ( F_47 ( V_35 -> V_83 ) -> V_102 -> V_103 & V_104 )
return V_133 ;
break;
case V_105 :
if ( V_35 -> V_83 -> V_7 & V_106 )
return V_134 ;
break;
default:
break;
}
if ( V_35 -> V_83 -> V_7 & V_106 )
return V_134 ;
if ( V_35 -> V_83 -> V_111 )
return V_135 ;
return V_133 ;
}
