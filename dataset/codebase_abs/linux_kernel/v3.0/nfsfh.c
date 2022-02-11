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
F_8 ( struct V_15 * V_16 , T_2 V_17 , int type )
{
if ( type > 0 && ( V_17 & V_18 ) != type ) {
if ( V_16 -> V_19 == 4 && ( V_17 & V_18 ) == V_20 )
return V_21 ;
else if ( type == V_22 )
return V_23 ;
else if ( ( V_17 & V_18 ) == V_22 )
return V_24 ;
else
return V_25 ;
}
if ( type < 0 && ( V_17 & V_18 ) == - type ) {
if ( V_16 -> V_19 == 4 && ( V_17 & V_18 ) == V_20 )
return V_21 ;
else if ( type == - V_22 )
return V_24 ;
else
return V_23 ;
}
return 0 ;
}
static T_1 F_9 ( struct V_15 * V_16 ,
struct V_3 * exp )
{
int V_26 = F_10 ( V_16 , exp ) ;
if ( ! V_16 -> V_27 && ! ( V_26 & V_28 ) ) {
F_11 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_7 ( V_29
L_2 ,
F_12 ( V_16 , V_30 , sizeof( V_30 ) ) ) ;
return V_31 ;
}
return F_13 ( F_14 ( V_16 , exp ) ) ;
}
static inline T_1 F_15 ( struct V_15 * V_16 ,
struct V_2 * V_2 , struct V_3 * exp )
{
if ( ! ( exp -> V_7 & V_32 ) )
return V_33 ;
if ( ! F_16 ( V_16 ) )
return V_34 ;
if ( F_17 ( ! F_18 ( V_2 -> V_11 -> V_35 ) &&
! F_19 ( V_2 -> V_11 -> V_35 ) ) )
return V_34 ;
if ( F_17 ( V_2 != exp -> V_9 . V_2 ) )
return V_34 ;
return V_33 ;
}
static T_1 F_20 ( struct V_15 * V_16 , struct V_36 * V_37 )
{
struct V_38 * V_39 = & V_37 -> V_40 ;
struct V_41 * V_41 = NULL , V_42 ;
struct V_3 * exp ;
struct V_2 * V_2 ;
int V_43 ;
int V_44 = V_39 -> V_45 / 4 ;
T_1 error ;
error = V_34 ;
if ( V_16 -> V_19 > 2 )
error = V_46 ;
if ( V_16 -> V_19 == 4 && V_39 -> V_45 == 0 )
return V_47 ;
if ( V_39 -> V_48 == 1 ) {
int V_49 ;
if ( -- V_44 < 0 )
return error ;
if ( V_39 -> V_50 != 0 )
return error ;
V_49 = F_21 ( V_39 -> V_51 ) / 4 ;
if ( V_49 == 0 )
return error ;
if ( V_39 -> V_51 == V_52 ) {
V_49 = F_21 ( V_53 ) / 4 ;
V_39 -> V_51 = V_53 ;
V_39 -> V_54 [ 0 ] = F_22 ( F_23 ( F_24 ( V_39 -> V_54 [ 0 ] ) , F_24 ( V_39 -> V_54 [ 1 ] ) ) ) ;
V_39 -> V_54 [ 1 ] = V_39 -> V_54 [ 2 ] ;
}
V_44 -= V_49 ;
if ( V_44 < 0 )
return error ;
exp = F_25 ( V_16 , V_39 -> V_51 , V_39 -> V_55 ) ;
V_41 = (struct V_41 * ) ( V_39 -> V_55 + V_49 ) ;
} else {
T_3 V_56 [ 2 ] ;
T_4 V_57 ;
T_5 V_58 ;
if ( V_39 -> V_45 != V_59 )
return error ;
V_57 = F_26 ( V_39 -> V_60 ) ;
V_58 = F_27 ( V_39 -> V_61 ) ;
F_28 ( V_62 , V_56 , V_57 , V_58 , 0 , NULL ) ;
exp = F_25 ( V_16 , V_62 , V_56 ) ;
}
error = V_34 ;
if ( F_29 ( exp ) == - V_63 )
return error ;
if ( F_30 ( exp ) )
return F_13 ( F_29 ( exp ) ) ;
if ( exp -> V_7 & V_8 ) {
struct V_64 * V_65 = F_31 () ;
if ( ! V_65 )
return F_13 ( - V_66 ) ;
V_65 -> V_67 =
F_32 ( V_65 -> V_67 ,
V_65 -> V_68 ) ;
F_33 ( F_34 ( V_65 ) ) ;
F_33 ( V_65 ) ;
} else {
error = F_9 ( V_16 , exp ) ;
if ( error )
goto V_69;
}
error = V_34 ;
if ( V_16 -> V_19 > 2 )
error = V_46 ;
if ( V_39 -> V_48 != 1 ) {
V_42 . V_70 . V_71 = V_39 -> V_72 ;
V_42 . V_70 . V_73 = V_39 -> V_74 ;
V_42 . V_70 . V_75 = V_39 -> V_76 ;
V_41 = & V_42 ;
V_44 = 3 ;
if ( V_39 -> V_76 == 0 )
V_43 = V_77 ;
else
V_43 = V_78 ;
} else
V_43 = V_39 -> V_79 ;
if ( V_43 == V_80 )
V_2 = F_2 ( exp -> V_9 . V_2 ) ;
else {
V_2 = F_35 ( exp -> V_9 . V_81 , V_41 ,
V_44 , V_43 ,
F_1 , exp ) ;
}
if ( V_2 == NULL )
goto V_69;
if ( F_30 ( V_2 ) ) {
if ( F_29 ( V_2 ) != - V_82 )
error = F_13 ( F_29 ( V_2 ) ) ;
goto V_69;
}
if ( F_18 ( V_2 -> V_11 -> V_35 ) &&
( V_2 -> V_83 & V_84 ) ) {
F_36 ( L_3 ,
V_2 -> V_85 -> V_13 . V_14 , V_2 -> V_13 . V_14 ) ;
}
V_37 -> V_86 = V_2 ;
V_37 -> V_87 = exp ;
return 0 ;
V_69:
F_37 ( exp ) ;
return error ;
}
T_1
F_38 ( struct V_15 * V_16 , struct V_36 * V_37 , int type , int V_88 )
{
struct V_3 * exp ;
struct V_2 * V_2 ;
T_1 error ;
F_7 ( L_4 , F_39 ( V_37 ) ) ;
if ( ! V_37 -> V_86 ) {
error = F_20 ( V_16 , V_37 ) ;
if ( error )
goto V_69;
}
V_2 = V_37 -> V_86 ;
exp = V_37 -> V_87 ;
error = F_15 ( V_16 , V_2 , exp ) ;
if ( error )
goto V_69;
error = F_9 ( V_16 , exp ) ;
if ( error )
goto V_69;
error = F_8 ( V_16 , V_2 -> V_11 -> V_35 , type ) ;
if ( error )
goto V_69;
if ( V_88 & V_89 || V_88 & V_90 )
goto V_91;
if ( V_88 & V_92
&& exp -> V_9 . V_2 == V_2 )
goto V_91;
error = F_40 ( exp , V_16 ) ;
if ( error )
goto V_69;
V_91:
error = F_41 ( V_16 , exp , V_2 , V_88 ) ;
if ( error ) {
F_7 ( L_5
L_6 ,
V_2 -> V_85 -> V_13 . V_14 ,
V_2 -> V_13 . V_14 ,
V_88 , F_24 ( error ) ) ;
}
V_69:
if ( error == V_34 )
V_93 . V_94 ++ ;
return error ;
}
static void F_42 ( struct V_36 * V_37 , struct V_3 * exp ,
struct V_2 * V_2 )
{
if ( V_2 != exp -> V_9 . V_2 ) {
struct V_41 * V_41 = (struct V_41 * )
( V_37 -> V_40 . V_55 + V_37 -> V_40 . V_45 / 4 - 1 ) ;
int V_95 = ( V_37 -> V_96 - V_37 -> V_40 . V_45 ) / 4 ;
int V_97 = ! ( exp -> V_7 & V_8 ) ;
V_37 -> V_40 . V_79 =
F_43 ( V_2 , V_41 , & V_95 , V_97 ) ;
V_37 -> V_40 . V_45 += V_95 * 4 ;
} else {
V_37 -> V_40 . V_79 = V_80 ;
}
}
static inline void F_44 ( struct V_2 * V_2 ,
struct V_3 * exp ,
struct V_38 * V_39 )
{
V_39 -> V_72 = F_45 ( V_2 -> V_11 -> V_98 ) ;
V_39 -> V_74 = V_2 -> V_11 -> V_99 ;
if ( F_18 ( V_2 -> V_11 -> V_35 ) ||
( exp -> V_7 & V_8 ) )
V_39 -> V_76 = 0 ;
}
static bool F_46 ( struct V_3 * exp )
{
return exp -> V_9 . V_2 == exp -> V_9 . V_2 -> V_100 -> V_101 ;
}
static struct V_102 * F_47 ( struct V_3 * exp )
{
return exp -> V_9 . V_2 -> V_11 -> V_103 ;
}
static bool F_48 ( T_6 V_104 , struct V_3 * exp )
{
switch ( V_104 ) {
case V_62 :
if ( ! F_49 ( F_47 ( exp ) -> V_105 ) )
return 0 ;
case V_52 :
case V_53 :
return F_47 ( exp ) -> V_106 -> V_107 & V_108 ;
case V_109 :
return exp -> V_7 & V_110 ;
case V_111 :
case V_112 :
if ( ! F_46 ( exp ) )
return 0 ;
case V_113 :
case V_114 :
return exp -> V_115 != NULL ;
}
return 1 ;
}
static void F_50 ( struct V_36 * V_37 , struct V_3 * exp , struct V_36 * V_116 )
{
T_6 V_117 ;
T_6 V_104 ;
V_118:
V_117 = 1 ;
if ( V_116 && V_116 -> V_87 == exp ) {
V_117 = V_116 -> V_40 . V_48 ;
V_104 = V_116 -> V_40 . V_51 ;
V_116 = NULL ;
switch ( V_117 ) {
case 0xca :
V_104 = V_62 ;
break;
case 1 :
break;
default:
goto V_118;
}
if ( ! F_48 ( V_104 , exp ) )
goto V_118;
} else if ( exp -> V_7 & V_110 ) {
V_104 = V_109 ;
} else if ( exp -> V_115 ) {
if ( V_37 -> V_96 >= 64 ) {
if ( F_46 ( exp ) )
V_104 = V_112 ;
else
V_104 = V_114 ;
} else {
if ( F_46 ( exp ) )
V_104 = V_111 ;
else
V_104 = V_113 ;
}
} else if ( ! F_49 ( F_47 ( exp ) -> V_105 ) )
V_104 = V_53 ;
else
V_104 = V_62 ;
V_37 -> V_40 . V_48 = V_117 ;
if ( V_117 )
V_37 -> V_40 . V_51 = V_104 ;
}
T_1
F_51 ( struct V_36 * V_37 , struct V_3 * exp , struct V_2 * V_2 ,
struct V_36 * V_116 )
{
struct V_119 * V_119 = V_2 -> V_11 ;
struct V_2 * V_6 = V_2 -> V_85 ;
T_3 * V_120 ;
T_4 V_121 = F_47 ( exp ) -> V_105 ;
F_7 ( L_7 ,
F_52 ( V_121 ) , F_53 ( V_121 ) ,
( long ) exp -> V_9 . V_2 -> V_11 -> V_98 ,
V_6 -> V_13 . V_14 , V_2 -> V_13 . V_14 ,
( V_119 ? V_119 -> V_98 : 0 ) ) ;
F_50 ( V_37 , exp , V_116 ) ;
if ( V_116 == V_37 )
F_54 ( V_116 ) ;
if ( V_37 -> V_122 || V_37 -> V_86 ) {
F_36 ( V_123 L_8 ,
V_6 -> V_13 . V_14 , V_2 -> V_13 . V_14 ) ;
}
if ( V_37 -> V_96 < V_59 )
F_36 ( V_123 L_9 ,
V_37 -> V_96 ,
V_6 -> V_13 . V_14 , V_2 -> V_13 . V_14 ) ;
V_37 -> V_86 = F_2 ( V_2 ) ;
V_37 -> V_87 = exp ;
F_55 ( & exp -> V_124 ) ;
if ( V_37 -> V_40 . V_48 == 0xca ) {
memset ( & V_37 -> V_40 . V_125 , 0 , V_59 ) ;
V_37 -> V_40 . V_45 = V_59 ;
V_37 -> V_40 . V_126 = 0xfeebbaca ;
V_37 -> V_40 . V_127 = F_56 ( V_121 ) ;
V_37 -> V_40 . V_60 = V_37 -> V_40 . V_127 ;
V_37 -> V_40 . V_61 =
F_45 ( exp -> V_9 . V_2 -> V_11 -> V_98 ) ;
V_37 -> V_40 . V_76 = F_45 ( V_75 ( V_2 ) ) ;
if ( V_119 )
F_44 ( V_2 , exp , & V_37 -> V_40 ) ;
} else {
int V_49 ;
V_37 -> V_40 . V_50 = 0 ;
V_120 = V_37 -> V_40 . V_55 + 0 ;
F_28 ( V_37 -> V_40 . V_51 , V_120 , V_121 ,
exp -> V_9 . V_2 -> V_11 -> V_98 ,
exp -> V_128 , exp -> V_115 ) ;
V_49 = F_21 ( V_37 -> V_40 . V_51 ) ;
V_120 += V_49 / 4 ;
V_37 -> V_40 . V_45 = 4 + V_49 ;
if ( V_119 )
F_42 ( V_37 , exp , V_2 ) ;
if ( V_37 -> V_40 . V_79 == 255 ) {
F_54 ( V_37 ) ;
return V_129 ;
}
}
return 0 ;
}
T_1
F_57 ( struct V_36 * V_37 )
{
struct V_2 * V_2 ;
if ( ! V_37 -> V_86 )
goto V_130;
V_2 = V_37 -> V_86 ;
if ( ! V_2 -> V_11 )
goto V_131;
if ( V_37 -> V_40 . V_48 != 1 ) {
F_44 ( V_2 , V_37 -> V_87 , & V_37 -> V_40 ) ;
} else {
if ( V_37 -> V_40 . V_79 != V_80 )
goto V_69;
F_42 ( V_37 , V_37 -> V_87 , V_2 ) ;
if ( V_37 -> V_40 . V_79 == 255 )
return V_129 ;
}
V_69:
return 0 ;
V_130:
F_36 ( V_123 L_10 ) ;
goto V_69;
V_131:
F_36 ( V_123 L_11 ,
V_2 -> V_85 -> V_13 . V_14 , V_2 -> V_13 . V_14 ) ;
goto V_69;
}
void
F_54 ( struct V_36 * V_37 )
{
struct V_2 * V_2 = V_37 -> V_86 ;
struct V_3 * exp = V_37 -> V_87 ;
if ( V_2 ) {
F_58 ( V_37 ) ;
V_37 -> V_86 = NULL ;
F_6 ( V_2 ) ;
#ifdef F_59
V_37 -> V_132 = 0 ;
V_37 -> V_133 = 0 ;
#endif
}
if ( exp ) {
F_60 ( & exp -> V_124 , & V_134 ) ;
V_37 -> V_87 = NULL ;
}
return;
}
char * F_39 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = & V_37 -> V_40 ;
static char V_30 [ 80 ] ;
sprintf ( V_30 , L_12 ,
V_39 -> V_45 ,
V_39 -> V_125 . V_135 [ 0 ] ,
V_39 -> V_125 . V_135 [ 1 ] ,
V_39 -> V_125 . V_135 [ 2 ] ,
V_39 -> V_125 . V_135 [ 3 ] ,
V_39 -> V_125 . V_135 [ 4 ] ,
V_39 -> V_125 . V_135 [ 5 ] ) ;
return V_30 ;
}
enum V_136 V_136 ( struct V_36 * V_37 )
{
if ( V_37 -> V_40 . V_48 != 1 )
return V_137 ;
switch( V_37 -> V_40 . V_51 ) {
case V_62 :
case V_53 :
case V_52 :
if ( F_47 ( V_37 -> V_87 ) -> V_106 -> V_107 & V_108 )
return V_137 ;
break;
case V_109 :
if ( V_37 -> V_87 -> V_7 & V_110 )
return V_138 ;
break;
default:
break;
}
if ( V_37 -> V_87 -> V_7 & V_110 )
return V_138 ;
if ( V_37 -> V_87 -> V_115 )
return V_139 ;
return V_137 ;
}
