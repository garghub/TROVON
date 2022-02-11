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
V_10 = F_5 ( F_6 ( V_6 ) , V_11 ) ;
if ( V_10 < 0 ) {
F_7 ( V_6 ) ;
break;
}
F_7 ( V_5 ) ;
V_5 = V_6 ;
}
if ( V_5 != exp -> V_9 . V_2 )
F_8 ( L_1 , V_5 , V_5 ) ;
V_4 = ( V_5 == exp -> V_9 . V_2 ) ;
F_7 ( V_5 ) ;
return V_4 ;
}
static inline T_1
F_9 ( struct V_12 * V_13 , T_2 V_14 , T_2 V_15 )
{
V_14 &= V_16 ;
if ( V_15 == 0 )
return V_17 ;
if ( V_14 == V_15 )
return V_17 ;
if ( V_13 -> V_18 == 4 && V_14 == V_19 )
return V_20 ;
if ( V_15 == V_21 )
return V_22 ;
if ( V_14 == V_21 )
return V_23 ;
return V_24 ;
}
static T_1 F_10 ( struct V_12 * V_13 ,
struct V_3 * exp )
{
int V_25 = F_11 ( V_13 , exp ) ;
if ( ! F_12 ( V_26 , & V_13 -> V_27 ) && ! ( V_25 & V_28 ) ) {
F_13 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_2 ,
F_14 ( V_13 , V_29 , sizeof( V_29 ) ) ) ;
return V_30 ;
}
return F_15 ( F_16 ( V_13 , exp ) ) ;
}
static inline T_1 F_17 ( struct V_12 * V_13 ,
struct V_2 * V_2 , struct V_3 * exp )
{
if ( ! ( exp -> V_7 & V_31 ) )
return V_17 ;
if ( ! F_18 ( V_13 ) )
return V_32 ;
if ( F_19 ( ! F_20 ( V_2 ) &&
! F_21 ( V_2 ) ) )
return V_32 ;
if ( F_19 ( V_2 != exp -> V_9 . V_2 ) )
return V_32 ;
return V_17 ;
}
static T_1 F_22 ( struct V_12 * V_13 , struct V_33 * V_34 )
{
struct V_35 * V_36 = & V_34 -> V_37 ;
struct V_38 * V_38 = NULL , V_39 ;
struct V_3 * exp ;
struct V_2 * V_2 ;
int V_40 ;
int V_41 = V_36 -> V_42 / 4 ;
T_1 error ;
error = V_32 ;
if ( V_13 -> V_18 > 2 )
error = V_43 ;
if ( V_13 -> V_18 == 4 && V_36 -> V_42 == 0 )
return V_44 ;
if ( V_36 -> V_45 == 1 ) {
int V_46 ;
if ( -- V_41 < 0 )
return error ;
if ( V_36 -> V_47 != 0 )
return error ;
V_46 = F_23 ( V_36 -> V_48 ) / 4 ;
if ( V_46 == 0 )
return error ;
if ( V_36 -> V_48 == V_49 ) {
V_46 = F_23 ( V_50 ) / 4 ;
V_36 -> V_48 = V_50 ;
V_36 -> V_51 [ 0 ] = F_24 ( F_25 ( F_26 ( ( V_52 T_1 ) V_36 -> V_51 [ 0 ] ) ,
F_26 ( ( V_52 T_1 ) V_36 -> V_51 [ 1 ] ) ) ) ;
V_36 -> V_51 [ 1 ] = V_36 -> V_51 [ 2 ] ;
}
V_41 -= V_46 ;
if ( V_41 < 0 )
return error ;
exp = F_27 ( V_13 , V_36 -> V_48 , V_36 -> V_51 ) ;
V_38 = (struct V_38 * ) ( V_36 -> V_51 + V_46 ) ;
} else {
T_3 V_53 [ 2 ] ;
T_4 V_54 ;
T_5 V_55 ;
if ( V_36 -> V_42 != V_56 )
return error ;
V_54 = F_28 ( V_36 -> V_57 ) ;
V_55 = F_29 ( V_36 -> V_58 ) ;
F_30 ( V_59 , V_53 , V_54 , V_55 , 0 , NULL ) ;
exp = F_27 ( V_13 , V_59 , V_53 ) ;
}
error = V_32 ;
if ( F_31 ( exp ) == - V_60 )
return error ;
if ( F_32 ( exp ) )
return F_15 ( F_31 ( exp ) ) ;
if ( exp -> V_7 & V_8 ) {
struct V_61 * V_62 = F_33 () ;
if ( ! V_62 ) {
error = F_15 ( - V_63 ) ;
goto V_64;
}
V_62 -> V_65 =
F_34 ( V_62 -> V_65 ,
V_62 -> V_66 ) ;
F_35 ( F_36 ( V_62 ) ) ;
F_35 ( V_62 ) ;
} else {
error = F_10 ( V_13 , exp ) ;
if ( error )
goto V_64;
}
error = V_32 ;
if ( V_13 -> V_18 > 2 )
error = V_43 ;
if ( V_36 -> V_45 != 1 ) {
V_39 . V_67 . V_68 = V_36 -> V_69 ;
V_39 . V_67 . V_70 = V_36 -> V_71 ;
V_39 . V_67 . V_72 = V_36 -> V_73 ;
V_38 = & V_39 ;
V_41 = 3 ;
if ( V_36 -> V_73 == 0 )
V_40 = V_74 ;
else
V_40 = V_75 ;
} else
V_40 = V_36 -> V_76 ;
if ( V_40 == V_77 )
V_2 = F_2 ( exp -> V_9 . V_2 ) ;
else {
V_2 = F_37 ( exp -> V_9 . V_78 , V_38 ,
V_41 , V_40 ,
F_1 , exp ) ;
}
if ( V_2 == NULL )
goto V_64;
if ( F_32 ( V_2 ) ) {
if ( F_31 ( V_2 ) != - V_79 )
error = F_15 ( F_31 ( V_2 ) ) ;
goto V_64;
}
if ( F_20 ( V_2 ) &&
( V_2 -> V_80 & V_81 ) ) {
F_38 ( L_3 ,
V_2 ) ;
}
V_34 -> V_82 = V_2 ;
V_34 -> V_83 = exp ;
return 0 ;
V_64:
F_39 ( exp ) ;
return error ;
}
T_1
F_40 ( struct V_12 * V_13 , struct V_33 * V_34 , T_2 type , int V_84 )
{
struct V_3 * exp ;
struct V_2 * V_2 ;
T_1 error ;
F_8 ( L_4 , F_41 ( V_34 ) ) ;
if ( ! V_34 -> V_82 ) {
error = F_22 ( V_13 , V_34 ) ;
if ( error )
goto V_64;
}
V_2 = V_34 -> V_82 ;
exp = V_34 -> V_83 ;
error = F_17 ( V_13 , V_2 , exp ) ;
if ( error )
goto V_64;
error = F_10 ( V_13 , exp ) ;
if ( error )
goto V_64;
error = F_9 ( V_13 , F_6 ( V_2 ) -> V_85 , type ) ;
if ( error )
goto V_64;
if ( V_84 & V_86 || V_84 & V_87 )
goto V_88;
if ( V_84 & V_89
&& exp -> V_9 . V_2 == V_2 )
goto V_88;
error = F_42 ( exp , V_13 ) ;
if ( error )
goto V_64;
V_88:
error = F_43 ( V_13 , exp , V_2 , V_84 ) ;
if ( error ) {
F_8 ( L_5
L_6 ,
V_2 ,
V_84 , F_26 ( error ) ) ;
}
V_64:
if ( error == V_32 )
V_90 . V_91 ++ ;
return error ;
}
static void F_44 ( struct V_33 * V_34 , struct V_3 * exp ,
struct V_2 * V_2 )
{
if ( V_2 != exp -> V_9 . V_2 ) {
struct V_38 * V_38 = (struct V_38 * )
( V_34 -> V_37 . V_51 + V_34 -> V_37 . V_42 / 4 - 1 ) ;
int V_92 = ( V_34 -> V_93 - V_34 -> V_37 . V_42 ) / 4 ;
int V_94 = ! ( exp -> V_7 & V_8 ) ;
V_34 -> V_37 . V_76 =
F_45 ( V_2 , V_38 , & V_92 , V_94 ) ;
V_34 -> V_37 . V_42 += V_92 * 4 ;
} else {
V_34 -> V_37 . V_76 = V_77 ;
}
}
static inline void F_46 ( struct V_2 * V_2 ,
struct V_3 * exp ,
struct V_35 * V_36 )
{
V_36 -> V_69 = F_47 ( F_6 ( V_2 ) -> V_95 ) ;
V_36 -> V_71 = F_6 ( V_2 ) -> V_96 ;
if ( F_20 ( V_2 ) ||
( exp -> V_7 & V_8 ) )
V_36 -> V_73 = 0 ;
}
static bool F_48 ( struct V_3 * exp )
{
return exp -> V_9 . V_2 == exp -> V_9 . V_2 -> V_97 -> V_98 ;
}
static struct V_99 * F_49 ( struct V_3 * exp )
{
return F_6 ( exp -> V_9 . V_2 ) -> V_100 ;
}
static bool F_50 ( T_6 V_101 , struct V_3 * exp )
{
switch ( V_101 ) {
case V_59 :
if ( ! F_51 ( F_49 ( exp ) -> V_102 ) )
return 0 ;
case V_49 :
case V_50 :
return F_49 ( exp ) -> V_103 -> V_104 & V_105 ;
case V_106 :
return exp -> V_7 & V_107 ;
case V_108 :
case V_109 :
if ( ! F_48 ( exp ) )
return 0 ;
case V_110 :
case V_111 :
return exp -> V_112 != NULL ;
}
return 1 ;
}
static void F_52 ( struct V_33 * V_34 , struct V_3 * exp , struct V_33 * V_113 )
{
T_6 V_114 ;
T_6 V_101 ;
V_115:
V_114 = 1 ;
if ( V_113 && V_113 -> V_83 == exp ) {
V_114 = V_113 -> V_37 . V_45 ;
V_101 = V_113 -> V_37 . V_48 ;
V_113 = NULL ;
switch ( V_114 ) {
case 0xca :
V_101 = V_59 ;
break;
case 1 :
break;
default:
goto V_115;
}
if ( ! F_50 ( V_101 , exp ) )
goto V_115;
} else if ( exp -> V_7 & V_107 ) {
V_101 = V_106 ;
} else if ( exp -> V_112 ) {
if ( V_34 -> V_93 >= 64 ) {
if ( F_48 ( exp ) )
V_101 = V_109 ;
else
V_101 = V_111 ;
} else {
if ( F_48 ( exp ) )
V_101 = V_108 ;
else
V_101 = V_110 ;
}
} else if ( ! F_51 ( F_49 ( exp ) -> V_102 ) )
V_101 = V_50 ;
else
V_101 = V_59 ;
V_34 -> V_37 . V_45 = V_114 ;
if ( V_114 )
V_34 -> V_37 . V_48 = V_101 ;
}
T_1
F_53 ( struct V_33 * V_34 , struct V_3 * exp , struct V_2 * V_2 ,
struct V_33 * V_113 )
{
struct V_116 * V_116 = F_6 ( V_2 ) ;
T_4 V_117 = F_49 ( exp ) -> V_102 ;
F_8 ( L_7 ,
F_54 ( V_117 ) , F_55 ( V_117 ) ,
( long ) F_6 ( exp -> V_9 . V_2 ) -> V_95 ,
V_2 ,
( V_116 ? V_116 -> V_95 : 0 ) ) ;
F_52 ( V_34 , exp , V_113 ) ;
if ( V_113 == V_34 )
F_56 ( V_113 ) ;
if ( V_34 -> V_118 || V_34 -> V_82 ) {
F_38 ( V_119 L_8 ,
V_2 ) ;
}
if ( V_34 -> V_93 < V_56 )
F_38 ( V_119 L_9 ,
V_34 -> V_93 ,
V_2 ) ;
V_34 -> V_82 = F_2 ( V_2 ) ;
V_34 -> V_83 = F_57 ( exp ) ;
if ( V_34 -> V_37 . V_45 == 0xca ) {
memset ( & V_34 -> V_37 . V_120 , 0 , V_56 ) ;
V_34 -> V_37 . V_42 = V_56 ;
V_34 -> V_37 . V_121 = 0xfeebbaca ;
V_34 -> V_37 . V_122 = F_58 ( V_117 ) ;
V_34 -> V_37 . V_57 = V_34 -> V_37 . V_122 ;
V_34 -> V_37 . V_58 =
F_47 ( F_6 ( exp -> V_9 . V_2 ) -> V_95 ) ;
V_34 -> V_37 . V_73 = F_47 ( V_72 ( V_2 ) ) ;
if ( V_116 )
F_46 ( V_2 , exp , & V_34 -> V_37 ) ;
} else {
V_34 -> V_37 . V_42 =
F_23 ( V_34 -> V_37 . V_48 ) + 4 ;
V_34 -> V_37 . V_47 = 0 ;
F_30 ( V_34 -> V_37 . V_48 ,
V_34 -> V_37 . V_51 ,
V_117 ,
F_6 ( exp -> V_9 . V_2 ) -> V_95 ,
exp -> V_123 , exp -> V_112 ) ;
if ( V_116 )
F_44 ( V_34 , exp , V_2 ) ;
if ( V_34 -> V_37 . V_76 == V_124 ) {
F_56 ( V_34 ) ;
return V_125 ;
}
}
return 0 ;
}
T_1
F_59 ( struct V_33 * V_34 )
{
struct V_2 * V_2 ;
if ( ! V_34 -> V_82 )
goto V_126;
V_2 = V_34 -> V_82 ;
if ( F_60 ( V_2 ) )
goto V_127;
if ( V_34 -> V_37 . V_45 != 1 ) {
F_46 ( V_2 , V_34 -> V_83 , & V_34 -> V_37 ) ;
} else {
if ( V_34 -> V_37 . V_76 != V_77 )
return 0 ;
F_44 ( V_34 , V_34 -> V_83 , V_2 ) ;
if ( V_34 -> V_37 . V_76 == V_124 )
return V_125 ;
}
return 0 ;
V_126:
F_38 ( V_119 L_10 ) ;
return V_128 ;
V_127:
F_38 ( V_119 L_11 ,
V_2 ) ;
return V_128 ;
}
void
F_56 ( struct V_33 * V_34 )
{
struct V_2 * V_2 = V_34 -> V_82 ;
struct V_3 * exp = V_34 -> V_83 ;
if ( V_2 ) {
F_61 ( V_34 ) ;
V_34 -> V_82 = NULL ;
F_7 ( V_2 ) ;
#ifdef F_62
V_34 -> V_129 = 0 ;
V_34 -> V_130 = 0 ;
#endif
}
F_63 ( V_34 ) ;
if ( exp ) {
F_39 ( exp ) ;
V_34 -> V_83 = NULL ;
}
return;
}
char * F_41 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = & V_34 -> V_37 ;
static char V_29 [ 80 ] ;
sprintf ( V_29 , L_12 ,
V_36 -> V_42 ,
V_36 -> V_120 . V_131 [ 0 ] ,
V_36 -> V_120 . V_131 [ 1 ] ,
V_36 -> V_120 . V_131 [ 2 ] ,
V_36 -> V_120 . V_131 [ 3 ] ,
V_36 -> V_120 . V_131 [ 4 ] ,
V_36 -> V_120 . V_131 [ 5 ] ) ;
return V_29 ;
}
enum V_132 V_132 ( struct V_33 * V_34 )
{
if ( V_34 -> V_37 . V_45 != 1 )
return V_133 ;
switch( V_34 -> V_37 . V_48 ) {
case V_59 :
case V_50 :
case V_49 :
if ( F_49 ( V_34 -> V_83 ) -> V_103 -> V_104 & V_105 )
return V_133 ;
break;
case V_106 :
if ( V_34 -> V_83 -> V_7 & V_107 )
return V_134 ;
break;
default:
break;
}
if ( V_34 -> V_83 -> V_7 & V_107 )
return V_134 ;
if ( V_34 -> V_83 -> V_112 )
return V_135 ;
return V_133 ;
}
