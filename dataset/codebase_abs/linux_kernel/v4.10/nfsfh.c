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
F_9 ( struct V_12 * V_13 , struct V_2 * V_2 ,
T_2 V_14 )
{
T_2 V_15 = F_6 ( V_2 ) -> V_16 & V_17 ;
if ( V_14 == 0 )
return V_18 ;
if ( V_15 == V_14 ) {
if ( V_15 == V_19 && ! F_10 ( V_2 ) ) {
F_11 ( 1 ) ;
return V_20 ;
}
return V_18 ;
}
if ( V_13 -> V_21 == 4 && V_15 == V_22 )
return V_23 ;
if ( V_14 == V_19 )
return V_20 ;
if ( V_15 == V_19 )
return V_24 ;
return V_25 ;
}
static T_1 F_12 ( struct V_12 * V_13 ,
struct V_3 * exp )
{
int V_26 = F_13 ( V_13 , exp ) ;
if ( ! F_14 ( V_27 , & V_13 -> V_28 ) && ! ( V_26 & V_29 ) ) {
F_15 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_2 ,
F_16 ( V_13 , V_30 , sizeof( V_30 ) ) ) ;
return V_31 ;
}
return F_17 ( F_18 ( V_13 , exp ) ) ;
}
static inline T_1 F_19 ( struct V_12 * V_13 ,
struct V_2 * V_2 , struct V_3 * exp )
{
if ( ! ( exp -> V_7 & V_32 ) )
return V_18 ;
if ( ! F_20 ( V_13 ) )
return V_33 ;
if ( F_21 ( ! F_22 ( V_2 ) &&
! F_23 ( V_2 ) ) )
return V_33 ;
if ( F_21 ( V_2 != exp -> V_9 . V_2 ) )
return V_33 ;
return V_18 ;
}
static T_1 F_24 ( struct V_12 * V_13 , struct V_34 * V_35 )
{
struct V_36 * V_37 = & V_35 -> V_38 ;
struct V_39 * V_39 = NULL , V_40 ;
struct V_3 * exp ;
struct V_2 * V_2 ;
int V_41 ;
int V_42 = V_37 -> V_43 / 4 ;
T_1 error ;
error = V_33 ;
if ( V_13 -> V_21 > 2 )
error = V_44 ;
if ( V_13 -> V_21 == 4 && V_37 -> V_43 == 0 )
return V_45 ;
if ( V_37 -> V_46 == 1 ) {
int V_47 ;
if ( -- V_42 < 0 )
return error ;
if ( V_37 -> V_48 != 0 )
return error ;
V_47 = F_25 ( V_37 -> V_49 ) / 4 ;
if ( V_47 == 0 )
return error ;
if ( V_37 -> V_49 == V_50 ) {
V_47 = F_25 ( V_51 ) / 4 ;
V_37 -> V_49 = V_51 ;
V_37 -> V_52 [ 0 ] = F_26 ( F_27 ( F_28 ( ( V_53 T_1 ) V_37 -> V_52 [ 0 ] ) ,
F_28 ( ( V_53 T_1 ) V_37 -> V_52 [ 1 ] ) ) ) ;
V_37 -> V_52 [ 1 ] = V_37 -> V_52 [ 2 ] ;
}
V_42 -= V_47 ;
if ( V_42 < 0 )
return error ;
exp = F_29 ( V_13 , V_37 -> V_49 , V_37 -> V_52 ) ;
V_39 = (struct V_39 * ) ( V_37 -> V_52 + V_47 ) ;
} else {
T_3 V_54 [ 2 ] ;
T_4 V_55 ;
T_5 V_56 ;
if ( V_37 -> V_43 != V_57 )
return error ;
V_55 = F_30 ( V_37 -> V_58 ) ;
V_56 = F_31 ( V_37 -> V_59 ) ;
F_32 ( V_60 , V_54 , V_55 , V_56 , 0 , NULL ) ;
exp = F_29 ( V_13 , V_60 , V_54 ) ;
}
error = V_33 ;
if ( F_33 ( exp ) == - V_61 )
return error ;
if ( F_34 ( exp ) )
return F_17 ( F_33 ( exp ) ) ;
if ( exp -> V_7 & V_8 ) {
struct V_62 * V_63 = F_35 () ;
if ( ! V_63 ) {
error = F_17 ( - V_64 ) ;
goto V_65;
}
V_63 -> V_66 =
F_36 ( V_63 -> V_66 ,
V_63 -> V_67 ) ;
F_37 ( F_38 ( V_63 ) ) ;
F_37 ( V_63 ) ;
} else {
error = F_12 ( V_13 , exp ) ;
if ( error )
goto V_65;
}
error = V_33 ;
if ( V_13 -> V_21 > 2 )
error = V_44 ;
if ( V_37 -> V_46 != 1 ) {
V_40 . V_68 . V_69 = V_37 -> V_70 ;
V_40 . V_68 . V_71 = V_37 -> V_72 ;
V_40 . V_68 . V_73 = V_37 -> V_74 ;
V_39 = & V_40 ;
V_42 = 3 ;
if ( V_37 -> V_74 == 0 )
V_41 = V_75 ;
else
V_41 = V_76 ;
} else
V_41 = V_37 -> V_77 ;
if ( V_41 == V_78 )
V_2 = F_2 ( exp -> V_9 . V_2 ) ;
else {
V_2 = F_39 ( exp -> V_9 . V_79 , V_39 ,
V_42 , V_41 ,
F_1 , exp ) ;
}
if ( V_2 == NULL )
goto V_65;
if ( F_34 ( V_2 ) ) {
if ( F_33 ( V_2 ) != - V_80 )
error = F_17 ( F_33 ( V_2 ) ) ;
goto V_65;
}
if ( F_22 ( V_2 ) &&
( V_2 -> V_81 & V_82 ) ) {
F_40 ( L_3 ,
V_2 ) ;
}
V_35 -> V_83 = V_2 ;
V_35 -> V_84 = exp ;
return 0 ;
V_65:
F_41 ( exp ) ;
return error ;
}
T_1
F_42 ( struct V_12 * V_13 , struct V_34 * V_35 , T_2 type , int V_85 )
{
struct V_3 * exp ;
struct V_2 * V_2 ;
T_1 error ;
F_8 ( L_4 , F_43 ( V_35 ) ) ;
if ( ! V_35 -> V_83 ) {
error = F_24 ( V_13 , V_35 ) ;
if ( error )
goto V_65;
}
V_2 = V_35 -> V_83 ;
exp = V_35 -> V_84 ;
error = F_19 ( V_13 , V_2 , exp ) ;
if ( error )
goto V_65;
error = F_12 ( V_13 , exp ) ;
if ( error )
goto V_65;
error = F_9 ( V_13 , V_2 , type ) ;
if ( error )
goto V_65;
if ( V_85 & V_86 || V_85 & V_87 )
goto V_88;
if ( V_85 & V_89
&& exp -> V_9 . V_2 == V_2 )
goto V_88;
error = F_44 ( exp , V_13 ) ;
if ( error )
goto V_65;
V_88:
error = F_45 ( V_13 , exp , V_2 , V_85 ) ;
if ( error ) {
F_8 ( L_5
L_6 ,
V_2 ,
V_85 , F_28 ( error ) ) ;
}
V_65:
if ( error == V_33 )
V_90 . V_91 ++ ;
return error ;
}
static void F_46 ( struct V_34 * V_35 , struct V_3 * exp ,
struct V_2 * V_2 )
{
if ( V_2 != exp -> V_9 . V_2 ) {
struct V_39 * V_39 = (struct V_39 * )
( V_35 -> V_38 . V_52 + V_35 -> V_38 . V_43 / 4 - 1 ) ;
int V_92 = ( V_35 -> V_93 - V_35 -> V_38 . V_43 ) / 4 ;
int V_94 = ! ( exp -> V_7 & V_8 ) ;
V_35 -> V_38 . V_77 =
F_47 ( V_2 , V_39 , & V_92 , V_94 ) ;
V_35 -> V_38 . V_43 += V_92 * 4 ;
} else {
V_35 -> V_38 . V_77 = V_78 ;
}
}
static inline void F_48 ( struct V_2 * V_2 ,
struct V_3 * exp ,
struct V_36 * V_37 )
{
V_37 -> V_70 = F_49 ( F_6 ( V_2 ) -> V_95 ) ;
V_37 -> V_72 = F_6 ( V_2 ) -> V_96 ;
if ( F_22 ( V_2 ) ||
( exp -> V_7 & V_8 ) )
V_37 -> V_74 = 0 ;
}
static bool F_50 ( struct V_3 * exp )
{
return exp -> V_9 . V_2 == exp -> V_9 . V_2 -> V_97 -> V_98 ;
}
static struct V_99 * F_51 ( struct V_3 * exp )
{
return exp -> V_9 . V_2 -> V_97 ;
}
static bool F_52 ( T_6 V_100 , struct V_3 * exp )
{
switch ( V_100 ) {
case V_60 :
if ( ! F_53 ( F_51 ( exp ) -> V_101 ) )
return 0 ;
case V_50 :
case V_51 :
return F_51 ( exp ) -> V_102 -> V_103 & V_104 ;
case V_105 :
return exp -> V_7 & V_106 ;
case V_107 :
case V_108 :
if ( ! F_50 ( exp ) )
return 0 ;
case V_109 :
case V_110 :
return exp -> V_111 != NULL ;
}
return 1 ;
}
static void F_54 ( struct V_34 * V_35 , struct V_3 * exp , struct V_34 * V_112 )
{
T_6 V_113 ;
T_6 V_100 ;
V_114:
V_113 = 1 ;
if ( V_112 && V_112 -> V_84 == exp ) {
V_113 = V_112 -> V_38 . V_46 ;
V_100 = V_112 -> V_38 . V_49 ;
V_112 = NULL ;
switch ( V_113 ) {
case 0xca :
V_100 = V_60 ;
break;
case 1 :
break;
default:
goto V_114;
}
if ( ! F_52 ( V_100 , exp ) )
goto V_114;
} else if ( exp -> V_7 & V_106 ) {
V_100 = V_105 ;
} else if ( exp -> V_111 ) {
if ( V_35 -> V_93 >= 64 ) {
if ( F_50 ( exp ) )
V_100 = V_108 ;
else
V_100 = V_110 ;
} else {
if ( F_50 ( exp ) )
V_100 = V_107 ;
else
V_100 = V_109 ;
}
} else if ( ! F_53 ( F_51 ( exp ) -> V_101 ) )
V_100 = V_51 ;
else
V_100 = V_60 ;
V_35 -> V_38 . V_46 = V_113 ;
if ( V_113 )
V_35 -> V_38 . V_49 = V_100 ;
}
T_1
F_55 ( struct V_34 * V_35 , struct V_3 * exp , struct V_2 * V_2 ,
struct V_34 * V_112 )
{
struct V_115 * V_115 = F_6 ( V_2 ) ;
T_4 V_116 = F_51 ( exp ) -> V_101 ;
F_8 ( L_7 ,
F_56 ( V_116 ) , F_57 ( V_116 ) ,
( long ) F_6 ( exp -> V_9 . V_2 ) -> V_95 ,
V_2 ,
( V_115 ? V_115 -> V_95 : 0 ) ) ;
F_54 ( V_35 , exp , V_112 ) ;
if ( V_112 == V_35 )
F_58 ( V_112 ) ;
if ( V_35 -> V_117 || V_35 -> V_83 ) {
F_40 ( V_118 L_8 ,
V_2 ) ;
}
if ( V_35 -> V_93 < V_57 )
F_40 ( V_118 L_9 ,
V_35 -> V_93 ,
V_2 ) ;
V_35 -> V_83 = F_2 ( V_2 ) ;
V_35 -> V_84 = F_59 ( exp ) ;
if ( V_35 -> V_38 . V_46 == 0xca ) {
memset ( & V_35 -> V_38 . V_119 , 0 , V_57 ) ;
V_35 -> V_38 . V_43 = V_57 ;
V_35 -> V_38 . V_120 = 0xfeebbaca ;
V_35 -> V_38 . V_121 = F_60 ( V_116 ) ;
V_35 -> V_38 . V_58 = V_35 -> V_38 . V_121 ;
V_35 -> V_38 . V_59 =
F_49 ( F_6 ( exp -> V_9 . V_2 ) -> V_95 ) ;
V_35 -> V_38 . V_74 = F_49 ( V_73 ( V_2 ) ) ;
if ( V_115 )
F_48 ( V_2 , exp , & V_35 -> V_38 ) ;
} else {
V_35 -> V_38 . V_43 =
F_25 ( V_35 -> V_38 . V_49 ) + 4 ;
V_35 -> V_38 . V_48 = 0 ;
F_32 ( V_35 -> V_38 . V_49 ,
V_35 -> V_38 . V_52 ,
V_116 ,
F_6 ( exp -> V_9 . V_2 ) -> V_95 ,
exp -> V_122 , exp -> V_111 ) ;
if ( V_115 )
F_46 ( V_35 , exp , V_2 ) ;
if ( V_35 -> V_38 . V_77 == V_123 ) {
F_58 ( V_35 ) ;
return V_124 ;
}
}
return 0 ;
}
T_1
F_61 ( struct V_34 * V_35 )
{
struct V_2 * V_2 ;
if ( ! V_35 -> V_83 )
goto V_125;
V_2 = V_35 -> V_83 ;
if ( F_62 ( V_2 ) )
goto V_126;
if ( V_35 -> V_38 . V_46 != 1 ) {
F_48 ( V_2 , V_35 -> V_84 , & V_35 -> V_38 ) ;
} else {
if ( V_35 -> V_38 . V_77 != V_78 )
return 0 ;
F_46 ( V_35 , V_35 -> V_84 , V_2 ) ;
if ( V_35 -> V_38 . V_77 == V_123 )
return V_124 ;
}
return 0 ;
V_125:
F_40 ( V_118 L_10 ) ;
return V_127 ;
V_126:
F_40 ( V_118 L_11 ,
V_2 ) ;
return V_127 ;
}
void
F_58 ( struct V_34 * V_35 )
{
struct V_2 * V_2 = V_35 -> V_83 ;
struct V_3 * exp = V_35 -> V_84 ;
if ( V_2 ) {
F_63 ( V_35 ) ;
V_35 -> V_83 = NULL ;
F_7 ( V_2 ) ;
F_64 ( V_35 ) ;
}
F_65 ( V_35 ) ;
if ( exp ) {
F_41 ( exp ) ;
V_35 -> V_84 = NULL ;
}
return;
}
char * F_43 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = & V_35 -> V_38 ;
static char V_30 [ 80 ] ;
sprintf ( V_30 , L_12 ,
V_37 -> V_43 ,
V_37 -> V_119 . V_128 [ 0 ] ,
V_37 -> V_119 . V_128 [ 1 ] ,
V_37 -> V_119 . V_128 [ 2 ] ,
V_37 -> V_119 . V_128 [ 3 ] ,
V_37 -> V_119 . V_128 [ 4 ] ,
V_37 -> V_119 . V_128 [ 5 ] ) ;
return V_30 ;
}
enum V_129 V_129 ( struct V_34 * V_35 )
{
if ( V_35 -> V_38 . V_46 != 1 )
return V_130 ;
switch( V_35 -> V_38 . V_49 ) {
case V_60 :
case V_51 :
case V_50 :
if ( F_51 ( V_35 -> V_84 ) -> V_102 -> V_103 & V_104 )
return V_130 ;
break;
case V_105 :
if ( V_35 -> V_84 -> V_7 & V_106 )
return V_131 ;
break;
default:
break;
}
if ( V_35 -> V_84 -> V_7 & V_106 )
return V_131 ;
if ( V_35 -> V_84 -> V_111 )
return V_132 ;
return V_130 ;
}
