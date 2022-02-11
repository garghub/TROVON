static struct V_1 *
F_1 ( struct V_2 * V_3 , unsigned V_4 , T_1 V_5 )
{
struct V_1 * V_6 ;
V_6 = F_2 ( V_3 , V_5 ) ;
if ( V_6 != NULL ) {
V_6 -> V_7 = V_4 ;
V_6 -> V_8 = F_3 ( V_4 , V_5 ) ;
if ( V_6 -> V_8 == NULL ) {
F_4 ( V_3 , V_6 ) ;
return NULL ;
}
}
return V_6 ;
}
static void
F_5 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
if ( V_3 != NULL && V_6 != NULL ) {
F_6 ( V_6 -> V_8 ) ;
F_4 ( V_3 , V_6 ) ;
}
}
static void F_7 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_9 * V_10 = V_3 -> V_11 ;
int V_12 = V_6 -> V_12 ;
unsigned long V_13 ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
F_9 ( & V_6 -> V_15 ) ;
switch ( V_12 ) {
case 0 :
if ( V_6 -> V_16 > 0 ) {
F_10 ( & V_6 -> V_15 , & V_10 -> V_17 ) ;
F_11 ( V_10 , L_1 , V_6 -> V_16 ) ;
} else {
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
}
break;
case - V_19 :
case - V_20 :
F_13 ( V_10 , L_2 , V_12 ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
break;
case - V_21 :
F_11 ( V_10 , L_3 , V_3 -> V_22 ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
break;
case - V_23 :
default:
F_11 ( V_10 , L_4 , V_12 ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
break;
}
F_14 ( & V_10 -> V_24 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
}
static void F_16 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_9 * V_10 = V_3 -> V_11 ;
switch ( V_6 -> V_12 ) {
default:
F_13 ( V_10 , L_5 , V_6 -> V_12 ) ;
case - V_19 :
case - V_20 :
break;
case 0 :
break;
}
F_17 ( & V_10 -> V_14 ) ;
F_9 ( & V_6 -> V_15 ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_25 ) ;
F_14 ( & V_10 -> V_26 ) ;
if ( F_18 ( F_19 ( & V_10 -> V_27 ) ) )
F_14 ( & V_10 -> V_28 ) ;
F_20 ( & V_10 -> V_14 ) ;
}
static int
F_21 ( struct V_29 * V_29 , struct V_30 * V_31 )
{
struct V_9 * V_10 ;
unsigned long V_13 ;
int V_32 = - V_33 ;
F_22 ( & V_34 ) ;
V_10 = F_23 ( V_29 -> V_35 , struct V_9 , V_36 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
if ( ! V_10 -> V_37 ) {
V_10 -> V_37 = 1 ;
V_31 -> V_38 = V_10 ;
V_32 = 0 ;
V_10 -> V_39 |= V_40 ;
}
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_11 ( V_10 , L_6 , V_32 ) ;
F_24 ( & V_34 ) ;
return V_32 ;
}
static int
F_25 ( struct V_29 * V_29 , struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
unsigned long V_13 ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
V_10 -> V_37 = 0 ;
V_31 -> V_38 = NULL ;
V_10 -> V_39 &= ~ V_40 ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_11 ( V_10 , L_7 ) ;
return 0 ;
}
static void
F_26 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
while ( F_18 ( ! F_19 ( & V_10 -> V_18 ) ) ) {
int error ;
V_6 = F_23 ( V_10 -> V_18 . V_41 ,
struct V_1 , V_15 ) ;
F_9 ( & V_6 -> V_15 ) ;
V_6 -> V_7 = V_42 ;
V_6 -> V_43 = F_7 ;
error = F_27 ( V_10 -> V_44 , V_6 , V_45 ) ;
if ( error ) {
F_11 ( V_10 , L_8 , error ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
break;
} else {
F_12 ( & V_6 -> V_15 , & V_10 -> V_46 ) ;
}
}
}
static T_2
F_28 ( struct V_30 * V_31 , char T_3 * V_8 , T_4 V_4 , T_5 * V_47 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
unsigned long V_13 ;
T_4 V_48 ;
T_4 V_49 ;
struct V_1 * V_6 ;
struct V_1 * V_50 ;
T_4 V_51 ;
T_6 * V_52 ;
if ( V_4 == 0 )
return - V_53 ;
F_11 ( V_10 , L_9 , ( int ) V_4 ) ;
F_22 ( & V_10 -> V_54 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
V_10 -> V_55 = 0 ;
F_26 ( V_10 ) ;
V_49 = 0 ;
V_50 = V_10 -> V_50 ;
V_51 = V_10 -> V_51 ;
V_52 = V_10 -> V_52 ;
V_10 -> V_50 = NULL ;
V_10 -> V_51 = 0 ;
V_10 -> V_52 = NULL ;
if ( ( V_51 == 0 ) &&
( F_18 ( F_19 ( & V_10 -> V_17 ) ) ) ) {
F_15 ( & V_10 -> V_14 , V_13 ) ;
if ( V_31 -> V_56 & ( V_57 | V_58 ) ) {
F_24 ( & V_10 -> V_54 ) ;
return - V_59 ;
}
F_29 ( V_10 -> V_24 ,
( F_18 ( ! F_19 ( & V_10 -> V_17 ) ) ) ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
}
while ( ( V_51 || F_18 ( ! F_19 ( & V_10 -> V_17 ) ) )
&& V_4 ) {
if ( V_51 == 0 ) {
V_6 = F_23 ( V_10 -> V_17 . V_41 ,
struct V_1 , V_15 ) ;
F_9 ( & V_6 -> V_15 ) ;
if ( V_6 -> V_16 && V_6 -> V_8 ) {
V_50 = V_6 ;
V_51 = V_6 -> V_16 ;
V_52 = V_6 -> V_8 ;
} else {
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
continue;
}
}
F_15 ( & V_10 -> V_14 , V_13 ) ;
if ( V_4 > V_51 )
V_48 = V_51 ;
else
V_48 = V_4 ;
V_48 -= F_30 ( V_8 , V_52 , V_48 ) ;
V_49 += V_48 ;
V_4 -= V_48 ;
V_8 += V_48 ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
if ( V_10 -> V_55 ) {
F_12 ( & V_50 -> V_15 , & V_10 -> V_18 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_24 ( & V_10 -> V_54 ) ;
return - V_59 ;
}
if ( V_48 < V_51 ) {
V_51 -= V_48 ;
V_52 += V_48 ;
} else {
F_12 ( & V_50 -> V_15 , & V_10 -> V_18 ) ;
V_51 = 0 ;
V_52 = NULL ;
V_50 = NULL ;
}
}
V_10 -> V_50 = V_50 ;
V_10 -> V_51 = V_51 ;
V_10 -> V_52 = V_52 ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_24 ( & V_10 -> V_54 ) ;
F_11 ( V_10 , L_10 , ( int ) V_49 ) ;
if ( V_49 )
return V_49 ;
else
return - V_59 ;
}
static T_2
F_31 ( struct V_30 * V_31 , const char T_3 * V_8 , T_4 V_4 , T_5 * V_47 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
unsigned long V_13 ;
T_4 V_48 ;
T_4 V_49 = 0 ;
struct V_1 * V_6 ;
F_11 ( V_10 , L_11 , ( int ) V_4 ) ;
if ( V_4 == 0 )
return - V_53 ;
F_22 ( & V_10 -> V_54 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
V_10 -> V_55 = 0 ;
if ( F_18 ( F_19 ( & V_10 -> V_25 ) ) ) {
F_15 ( & V_10 -> V_14 , V_13 ) ;
if ( V_31 -> V_56 & ( V_57 | V_58 ) ) {
F_24 ( & V_10 -> V_54 ) ;
return - V_59 ;
}
F_29 ( V_10 -> V_26 ,
( F_18 ( ! F_19 ( & V_10 -> V_25 ) ) ) ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
}
while ( F_18 ( ! F_19 ( & V_10 -> V_25 ) ) && V_4 ) {
if ( V_4 > V_42 )
V_48 = V_42 ;
else
V_48 = V_4 ;
V_6 = F_23 ( V_10 -> V_25 . V_41 , struct V_1 ,
V_15 ) ;
F_9 ( & V_6 -> V_15 ) ;
V_6 -> V_43 = F_16 ;
V_6 -> V_7 = V_48 ;
if ( V_4 > V_48 )
V_6 -> V_60 = 0 ;
else
V_6 -> V_60 = ( ( V_4 % V_10 -> V_61 -> V_62 ) == 0 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
if ( F_32 ( V_6 -> V_8 , V_8 , V_48 ) ) {
F_12 ( & V_6 -> V_15 , & V_10 -> V_25 ) ;
F_24 ( & V_10 -> V_54 ) ;
return V_49 ;
}
V_49 += V_48 ;
V_4 -= V_48 ;
V_8 += V_48 ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
if ( V_10 -> V_55 ) {
F_12 ( & V_6 -> V_15 , & V_10 -> V_25 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_24 ( & V_10 -> V_54 ) ;
return - V_59 ;
}
if ( F_27 ( V_10 -> V_61 , V_6 , V_45 ) ) {
F_12 ( & V_6 -> V_15 , & V_10 -> V_25 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_24 ( & V_10 -> V_54 ) ;
return - V_59 ;
}
F_12 ( & V_6 -> V_15 , & V_10 -> V_27 ) ;
}
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_24 ( & V_10 -> V_54 ) ;
F_11 ( V_10 , L_12 , ( int ) V_49 ) ;
if ( V_49 ) {
return V_49 ;
} else {
return - V_59 ;
}
}
static int
F_33 ( struct V_30 * V_31 , int V_63 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
unsigned long V_13 ;
int V_64 ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
V_64 = ( F_18 ( F_19 ( & V_10 -> V_25 ) ) ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
if ( ! V_64 ) {
F_29 ( V_10 -> V_28 ,
( F_18 ( F_19 ( & V_10 -> V_27 ) ) ) ) ;
}
return 0 ;
}
static unsigned int
F_34 ( struct V_30 * V_31 , T_7 * V_65 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
unsigned long V_13 ;
int V_12 = 0 ;
F_22 ( & V_10 -> V_54 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
F_26 ( V_10 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_24 ( & V_10 -> V_54 ) ;
F_35 ( V_31 , & V_10 -> V_24 , V_65 ) ;
F_35 ( V_31 , & V_10 -> V_26 , V_65 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
if ( F_18 ( ! F_19 ( & V_10 -> V_25 ) ) )
V_12 |= V_66 | V_67 ;
if ( F_18 ( V_10 -> V_51 ) ||
F_18 ( ! F_19 ( & V_10 -> V_17 ) ) )
V_12 |= V_68 | V_69 ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
return V_12 ;
}
static long
F_36 ( struct V_30 * V_31 , unsigned int V_70 , unsigned long V_71 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
unsigned long V_13 ;
int V_12 = 0 ;
F_11 ( V_10 , L_13 , V_70 , V_71 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
switch ( V_70 ) {
case V_72 :
V_12 = ( int ) V_10 -> V_39 ;
break;
case V_73 :
V_10 -> V_39 = ( T_6 ) V_71 ;
break;
default:
F_11 ( V_10 , L_14 ,
V_70 ) ;
V_12 = - V_74 ;
}
F_15 ( & V_10 -> V_14 , V_13 ) ;
return V_12 ;
}
static int
F_37 ( struct V_9 * V_10 )
{
int V_75 = 0 ;
V_10 -> V_76 = F_38 ( V_10 -> V_77 , & V_78 , & V_79 ) ;
V_10 -> V_61 -> V_11 = V_10 ;
V_10 -> V_80 = F_38 ( V_10 -> V_77 , & V_81 , & V_82 ) ;
V_10 -> V_44 -> V_11 = V_10 ;
V_75 = F_39 ( V_10 -> V_61 , V_10 -> V_76 ) ;
if ( V_75 != 0 ) {
F_11 ( V_10 , L_15 , V_10 -> V_61 -> V_22 , V_75 ) ;
goto V_83;
}
V_75 = F_39 ( V_10 -> V_44 , V_10 -> V_80 ) ;
if ( V_75 != 0 ) {
F_11 ( V_10 , L_15 , V_10 -> V_61 -> V_22 , V_75 ) ;
goto V_83;
}
V_83:
if ( V_75 != 0 ) {
( void ) F_40 ( V_10 -> V_61 ) ;
( void ) F_40 ( V_10 -> V_44 ) ;
V_10 -> V_76 = NULL ;
V_10 -> V_80 = NULL ;
}
return V_75 ;
}
static void F_41 ( struct V_9 * V_10 )
{
if ( V_10 -> V_84 < 0 )
return;
F_11 ( V_10 , L_16 , V_85 ) ;
if ( V_10 -> V_76 )
F_40 ( V_10 -> V_61 ) ;
if ( V_10 -> V_80 )
F_40 ( V_10 -> V_44 ) ;
V_10 -> V_84 = - 1 ;
}
static int
F_42 ( struct V_9 * V_10 , unsigned V_86 )
{
int V_75 = 0 ;
struct V_87 * V_77 = V_10 -> V_77 ;
switch ( V_86 ) {
case V_88 :
V_75 = 0 ;
break;
default:
V_75 = - V_53 ;
case 0 :
break;
}
if ( V_75 ) {
F_43 ( V_10 -> V_77 ,
V_10 -> V_77 -> V_89 ? 8 : 100 ) ;
} else {
char * V_90 ;
unsigned V_91 ;
V_91 = 2 * V_92 . V_93 ;
F_43 ( V_10 -> V_77 , V_91 ) ;
switch ( V_77 -> V_90 ) {
case V_94 : V_90 = L_17 ; break;
#ifdef F_44
case V_95 : V_90 = L_18 ; break;
#endif
default: V_90 = L_19 ; break;
}
V_10 -> V_96 = V_86 ;
F_45 ( V_10 , L_20 ,
V_90 , V_86 , V_91 , V_97 ) ;
}
return V_75 ;
}
static int
F_46 ( enum V_98 V_90 , T_6 * V_8 , T_6 type , unsigned V_99 ,
int V_89 )
{
int V_4 ;
const struct V_100 * * V_101 ;
#ifdef F_44
int V_102 = ( V_90 == V_95 ) ;
if ( type == V_103 )
V_102 = ! V_102 ;
if ( V_102 ) {
V_101 = V_104 ;
} else {
V_101 = V_105 ;
}
#else
V_101 = V_105 ;
#endif
if ( V_99 >= V_106 . V_107 )
return - V_53 ;
if ( ! V_89 )
V_101 ++ ;
V_4 = F_47 ( & V_92 , V_8 , V_108 ,
V_101 ) ;
if ( V_4 < 0 )
return V_4 ;
( (struct V_109 * ) V_8 ) -> V_110 = type ;
return V_4 ;
}
static int
F_48 ( struct V_9 * V_10 , unsigned V_86 )
{
int V_75 = 0 ;
switch ( V_10 -> V_84 ) {
case V_111 :
F_41 ( V_10 ) ;
break;
}
switch ( V_86 ) {
case V_111 :
V_75 = F_37 ( V_10 ) ;
if ( V_75 ) {
F_41 ( V_10 ) ;
} else {
V_10 -> V_84 = V_111 ;
}
break;
default:
V_75 = - V_53 ;
}
if ( ! V_75 )
F_45 ( V_10 , L_21 , V_86 ) ;
return V_75 ;
}
static void F_49 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
if ( V_6 -> V_12 || V_6 -> V_16 != V_6 -> V_7 )
F_11 ( (struct V_9 * ) V_3 -> V_11 ,
L_22 ,
V_6 -> V_12 , V_6 -> V_16 , V_6 -> V_7 ) ;
}
static void F_50 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
F_45 ( V_10 , L_23 ) ;
if ( F_40 ( V_10 -> V_61 ) )
F_11 ( V_10 , L_24 ) ;
if ( F_40 ( V_10 -> V_44 ) )
F_11 ( V_10 , L_25 ) ;
if ( V_10 -> V_50 != NULL ) {
F_12 ( & V_10 -> V_50 -> V_15 , & V_10 -> V_18 ) ;
V_10 -> V_50 = NULL ;
}
V_10 -> V_51 = 0 ;
V_10 -> V_52 = NULL ;
V_10 -> V_55 = 1 ;
while ( F_18 ( ! ( F_19 ( & V_10 -> V_17 ) ) ) ) {
V_6 = F_23 ( V_10 -> V_17 . V_41 , struct V_1 ,
V_15 ) ;
F_9 ( & V_6 -> V_15 ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
}
while ( F_18 ( ! ( F_19 ( & V_10 -> V_46 ) ) ) ) {
V_6 = F_23 ( V_10 -> V_17 . V_41 , struct V_1 ,
V_15 ) ;
F_9 ( & V_6 -> V_15 ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
}
while ( F_18 ( ! ( F_19 ( & V_10 -> V_27 ) ) ) ) {
V_6 = F_23 ( V_10 -> V_27 . V_41 ,
struct V_1 , V_15 ) ;
F_9 ( & V_6 -> V_15 ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_25 ) ;
}
if ( F_39 ( V_10 -> V_61 , V_10 -> V_76 ) )
F_11 ( V_10 , L_26 ) ;
if ( F_39 ( V_10 -> V_44 , V_10 -> V_80 ) )
F_11 ( V_10 , L_27 ) ;
F_14 ( & V_10 -> V_24 ) ;
F_14 ( & V_10 -> V_26 ) ;
F_14 ( & V_10 -> V_28 ) ;
}
static int
F_51 ( struct V_87 * V_77 , const struct V_112 * V_113 )
{
struct V_9 * V_10 = F_52 ( V_77 ) ;
struct V_1 * V_6 = V_10 -> V_6 ;
int V_114 = - V_115 ;
T_8 V_116 = F_53 ( V_113 -> V_116 ) ;
T_8 V_117 = F_53 ( V_113 -> V_117 ) ;
T_8 V_118 = F_53 ( V_113 -> V_118 ) ;
F_11 ( V_10 , L_28 ,
V_113 -> V_119 , V_113 -> V_120 , V_117 , V_116 , V_118 ) ;
V_6 -> V_43 = F_49 ;
switch ( V_113 -> V_119 & V_121 ) {
case V_122 :
switch ( V_113 -> V_120 ) {
case V_123 :
if ( V_113 -> V_119 != V_124 )
break;
switch ( V_117 >> 8 ) {
case V_125 :
V_114 = F_54 ( V_118 , ( T_8 ) sizeof V_106 ) ;
memcpy ( V_6 -> V_8 , & V_106 , V_114 ) ;
break;
#ifdef F_44
case V_126 :
if ( ! V_77 -> V_127 )
break;
V_114 = F_54 ( V_118 ,
( T_8 ) sizeof F_55 ) ;
memcpy ( V_6 -> V_8 , & F_55 , V_114 ) ;
break;
case V_103 :
if ( ! V_77 -> V_127 )
break;
#endif
case V_128 :
V_114 = F_46 ( V_77 -> V_90 , V_6 -> V_8 ,
V_117 >> 8 ,
V_117 & 0xff ,
V_77 -> V_89 ) ;
if ( V_114 >= 0 )
V_114 = F_54 ( V_118 , ( T_8 ) V_114 ) ;
break;
case V_129 :
V_114 = F_56 ( & V_130 ,
V_117 & 0xff , V_6 -> V_8 ) ;
if ( V_114 >= 0 )
V_114 = F_54 ( V_118 , ( T_8 ) V_114 ) ;
break;
}
break;
case V_131 :
if ( V_113 -> V_119 != 0 )
break;
if ( V_77 -> V_132 )
F_11 ( V_10 , L_29 ) ;
else if ( V_77 -> V_133 )
F_11 ( V_10 , L_30 ) ;
V_114 = F_42 ( V_10 , V_117 ) ;
if ( ! V_114 )
V_114 = F_48 ( V_10 , V_111 ) ;
break;
case V_134 :
if ( V_113 -> V_119 != V_124 )
break;
* ( T_6 * ) V_6 -> V_8 = V_10 -> V_96 ;
V_114 = F_54 ( V_118 , ( T_8 ) 1 ) ;
break;
case V_135 :
if ( V_113 -> V_119 != V_136 ||
! V_10 -> V_96 )
break;
V_114 = F_48 ( V_10 , V_111 ) ;
break;
case V_137 :
if ( V_113 -> V_119 !=
( V_124 | V_136 )
|| ! V_10 -> V_96 )
break;
* ( T_6 * ) V_6 -> V_8 = V_10 -> V_84 ;
V_114 = F_54 ( V_118 , ( T_8 ) 1 ) ;
break;
default:
goto V_138;
}
break;
case V_139 :
switch ( V_113 -> V_120 ) {
case 0 :
if ( ( V_116 >> 8 ) != V_111 )
break;
V_114 = ( V_140 [ 0 ] << 8 ) | V_140 [ 1 ] ;
memcpy ( V_6 -> V_8 , V_140 , V_114 ) ;
F_11 ( V_10 , L_31 , V_114 ,
& V_140 [ 2 ] ) ;
break;
case 1 :
if ( V_116 != V_111 )
break;
* ( T_6 * ) V_6 -> V_8 = V_10 -> V_39 ;
V_114 = F_54 ( V_118 , ( T_8 ) 1 ) ;
break;
case 2 :
if ( V_116 != V_111 )
break;
F_50 ( V_10 ) ;
V_114 = 0 ;
break;
default:
goto V_138;
}
break;
default:
V_138:
F_13 ( V_10 ,
L_32 ,
V_113 -> V_119 , V_113 -> V_120 ,
V_117 , V_116 , V_118 ) ;
break;
}
if ( V_114 >= 0 ) {
V_6 -> V_7 = V_114 ;
V_6 -> V_60 = V_114 < V_118 ;
V_114 = F_27 ( V_77 -> V_141 , V_6 , V_45 ) ;
if ( V_114 < 0 ) {
F_11 ( V_10 , L_33 , V_114 ) ;
V_6 -> V_12 = 0 ;
F_49 ( V_77 -> V_141 , V_6 ) ;
}
}
return V_114 ;
}
static void
F_57 ( struct V_87 * V_77 )
{
struct V_9 * V_10 = F_52 ( V_77 ) ;
unsigned long V_13 ;
F_11 ( V_10 , L_16 , V_85 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
F_41 ( V_10 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
}
static void
F_58 ( struct V_87 * V_77 )
{
struct V_9 * V_10 = F_52 ( V_77 ) ;
struct V_1 * V_6 ;
F_11 ( V_10 , L_16 , V_85 ) ;
F_59 ( V_142 , V_143 ) ;
F_60 ( & V_10 -> V_36 ) ;
F_61 ( ! F_19 ( & V_10 -> V_27 ) ) ;
F_61 ( ! F_19 ( & V_10 -> V_46 ) ) ;
while ( ! F_19 ( & V_10 -> V_25 ) ) {
V_6 = F_23 ( V_10 -> V_25 . V_41 , struct V_1 ,
V_15 ) ;
F_62 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_61 , V_6 ) ;
}
if ( V_10 -> V_50 != NULL )
F_5 ( V_10 -> V_44 , V_10 -> V_50 ) ;
while ( ! F_19 ( & V_10 -> V_18 ) ) {
V_6 = F_23 ( V_10 -> V_18 . V_41 ,
struct V_1 , V_15 ) ;
F_62 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_44 , V_6 ) ;
}
while ( ! F_19 ( & V_10 -> V_17 ) ) {
V_6 = F_23 ( V_10 -> V_17 . V_41 ,
struct V_1 , V_15 ) ;
F_62 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_44 , V_6 ) ;
}
if ( V_10 -> V_6 ) {
F_5 ( V_77 -> V_141 , V_10 -> V_6 ) ;
V_10 -> V_6 = NULL ;
}
F_63 ( V_77 , NULL ) ;
}
static int T_9
F_64 ( struct V_87 * V_77 )
{
struct V_9 * V_10 ;
struct V_2 * V_61 , * V_44 ;
int V_12 = - V_144 ;
int V_145 ;
T_4 V_4 ;
T_10 V_146 ;
struct V_1 * V_6 ;
V_10 = & V_147 ;
V_10 -> V_148 = F_65 ( V_142 , NULL , V_143 ,
NULL , L_34 ) ;
if ( F_66 ( V_10 -> V_148 ) ) {
ERROR ( V_10 , L_35 ) ;
goto V_149;
}
F_67 ( & V_10 -> V_36 , & V_150 ) ;
V_10 -> V_36 . V_151 = V_152 ;
V_12 = F_68 ( & V_10 -> V_36 , V_143 , 1 ) ;
if ( V_12 ) {
ERROR ( V_10 , L_36 ) ;
goto V_149;
}
V_145 = F_69 ( V_77 ) ;
if ( V_145 >= 0 ) {
V_106 . V_153 = F_70 ( 0x0200 + V_145 ) ;
} else {
F_71 ( & V_77 -> V_10 , L_37 ,
V_77 -> V_22 ) ;
V_106 . V_153 =
F_70 ( 0xFFFF ) ;
}
snprintf ( V_154 , sizeof( V_154 ) , L_38 ,
F_72 () -> V_155 , F_72 () -> V_156 ,
V_77 -> V_22 ) ;
V_106 . V_157 =
F_70 ( V_158 ) ;
V_106 . V_159 =
F_70 ( V_160 ) ;
if ( V_157 ) {
if ( ! V_159 ) {
F_73 ( & V_77 -> V_10 , L_39 ) ;
return - V_161 ;
}
V_106 . V_157 = F_70 ( V_157 ) ;
V_106 . V_159 = F_70 ( V_159 ) ;
if ( V_153 )
V_106 . V_153 = F_70 ( V_153 ) ;
}
if ( V_162 )
F_74 ( V_154 , V_162 , sizeof V_154 ) ;
if ( V_163 )
F_74 ( V_164 , V_163 , sizeof V_164 ) ;
if ( V_165 )
F_74 ( V_166 , V_165 , sizeof V_166 ) ;
if ( V_167 )
F_74 ( & V_140 [ 2 ] , V_167 , ( sizeof V_140 ) - 2 ) ;
V_4 = strlen ( V_140 ) ;
V_140 [ 0 ] = ( V_4 >> 8 ) & 0xFF ;
V_140 [ 1 ] = V_4 & 0xFF ;
F_75 ( V_77 ) ;
V_61 = F_76 ( V_77 , & V_79 ) ;
if ( ! V_61 ) {
V_168:
F_73 ( & V_77 -> V_10 , L_40 ,
V_77 -> V_22 ) ;
return - V_161 ;
}
V_61 -> V_11 = V_61 ;
V_44 = F_76 ( V_77 , & V_82 ) ;
if ( ! V_44 )
goto V_168;
V_44 -> V_11 = V_44 ;
#ifdef F_44
F_55 . V_169 = V_106 . V_169 ;
V_78 . V_170 = V_79 . V_170 ;
V_81 . V_170 = V_82 . V_170 ;
#endif
V_106 . V_169 = V_77 -> V_141 -> V_62 ;
F_77 ( V_77 ) ;
if ( V_77 -> V_89 ) {
V_171 . V_172 |= V_173 ,
V_92 . V_172 |= V_174 ;
}
F_78 ( & V_10 -> V_14 ) ;
F_79 ( & V_10 -> V_54 ) ;
F_80 ( & V_10 -> V_25 ) ;
F_80 ( & V_10 -> V_27 ) ;
F_80 ( & V_10 -> V_18 ) ;
F_80 ( & V_10 -> V_46 ) ;
F_80 ( & V_10 -> V_17 ) ;
F_81 ( & V_10 -> V_24 ) ;
F_81 ( & V_10 -> V_26 ) ;
F_81 ( & V_10 -> V_28 ) ;
V_10 -> V_96 = 0 ;
V_10 -> V_84 = - 1 ;
V_10 -> V_37 = 0 ;
V_10 -> V_39 = V_175 ;
V_10 -> V_50 = NULL ;
V_10 -> V_51 = 0 ;
V_10 -> V_52 = NULL ;
V_10 -> V_61 = V_61 ;
V_10 -> V_44 = V_44 ;
V_10 -> V_6 = F_1 ( V_77 -> V_141 , V_108 ,
V_176 ) ;
if ( ! V_10 -> V_6 ) {
V_12 = - V_144 ;
goto V_149;
}
for ( V_146 = 0 ; V_146 < V_177 ; V_146 ++ ) {
V_6 = F_1 ( V_10 -> V_61 , V_42 , V_176 ) ;
if ( ! V_6 ) {
while ( ! F_19 ( & V_10 -> V_25 ) ) {
V_6 = F_23 ( V_10 -> V_25 . V_41 ,
struct V_1 , V_15 ) ;
F_62 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_61 , V_6 ) ;
}
return - V_144 ;
}
F_12 ( & V_6 -> V_15 , & V_10 -> V_25 ) ;
}
for ( V_146 = 0 ; V_146 < V_177 ; V_146 ++ ) {
V_6 = F_1 ( V_10 -> V_44 , V_42 , V_176 ) ;
if ( ! V_6 ) {
while ( ! F_19 ( & V_10 -> V_18 ) ) {
V_6 = F_23 ( V_10 -> V_18 . V_41 ,
struct V_1 , V_15 ) ;
F_62 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_44 , V_6 ) ;
}
return - V_144 ;
}
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
}
V_10 -> V_6 -> V_43 = F_49 ;
V_10 -> V_77 = V_77 ;
F_63 ( V_77 , V_10 ) ;
V_77 -> V_141 -> V_11 = V_10 ;
F_45 ( V_10 , L_41 V_178 L_42 , V_97 ) ;
F_45 ( V_10 , L_43 , V_77 -> V_22 , V_44 -> V_22 ,
V_61 -> V_22 ) ;
return 0 ;
V_149:
F_58 ( V_77 ) ;
return V_12 ;
}
static int T_9
F_82 ( void )
{
int V_12 ;
V_142 = F_83 ( V_152 , L_44 ) ;
if ( F_66 ( V_142 ) ) {
V_12 = F_84 ( V_142 ) ;
ERROR ( V_10 , L_45 , V_12 ) ;
return V_12 ;
}
V_12 = F_85 ( & V_143 , 0 , 1 ,
L_46 ) ;
if ( V_12 ) {
ERROR ( V_10 , L_47 , V_12 ) ;
F_86 ( V_142 ) ;
return V_12 ;
}
V_12 = F_87 ( & V_179 , F_64 ) ;
if ( V_12 ) {
F_86 ( V_142 ) ;
F_88 ( V_143 , 1 ) ;
F_11 ( V_10 , L_48 , V_12 ) ;
}
return V_12 ;
}
static void T_11
F_89 ( void )
{
int V_12 ;
F_22 ( & V_147 . V_54 ) ;
V_12 = F_90 ( & V_179 ) ;
if ( V_12 )
ERROR ( V_10 , L_49 , V_12 ) ;
F_88 ( V_143 , 2 ) ;
F_86 ( V_142 ) ;
F_24 ( & V_147 . V_54 ) ;
}
