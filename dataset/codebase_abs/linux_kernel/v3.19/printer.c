static inline struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_1 * V_5 ,
struct V_1 * V_6 )
{
switch ( V_3 -> V_7 ) {
case V_8 :
return V_6 ;
case V_9 :
return V_5 ;
default:
return V_4 ;
}
}
static struct V_10 *
F_2 ( struct V_11 * V_12 , unsigned V_13 , T_1 V_14 )
{
struct V_10 * V_15 ;
V_15 = F_3 ( V_12 , V_14 ) ;
if ( V_15 != NULL ) {
V_15 -> V_16 = V_13 ;
V_15 -> V_17 = F_4 ( V_13 , V_14 ) ;
if ( V_15 -> V_17 == NULL ) {
F_5 ( V_12 , V_15 ) ;
return NULL ;
}
}
return V_15 ;
}
static void
F_6 ( struct V_11 * V_12 , struct V_10 * V_15 )
{
if ( V_12 != NULL && V_15 != NULL ) {
F_7 ( V_15 -> V_17 ) ;
F_5 ( V_12 , V_15 ) ;
}
}
static void F_8 ( struct V_11 * V_12 , struct V_10 * V_15 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
int V_21 = V_15 -> V_21 ;
unsigned long V_22 ;
F_9 ( & V_19 -> V_23 , V_22 ) ;
F_10 ( & V_15 -> V_24 ) ;
switch ( V_21 ) {
case 0 :
if ( V_15 -> V_25 > 0 ) {
F_11 ( & V_15 -> V_24 , & V_19 -> V_26 ) ;
F_12 ( V_19 , L_1 , V_15 -> V_25 ) ;
} else {
F_13 ( & V_15 -> V_24 , & V_19 -> V_27 ) ;
}
break;
case - V_28 :
case - V_29 :
F_14 ( V_19 , L_2 , V_21 ) ;
F_13 ( & V_15 -> V_24 , & V_19 -> V_27 ) ;
break;
case - V_30 :
F_12 ( V_19 , L_3 , V_12 -> V_31 ) ;
F_13 ( & V_15 -> V_24 , & V_19 -> V_27 ) ;
break;
case - V_32 :
default:
F_12 ( V_19 , L_4 , V_21 ) ;
F_13 ( & V_15 -> V_24 , & V_19 -> V_27 ) ;
break;
}
F_15 ( & V_19 -> V_33 ) ;
F_16 ( & V_19 -> V_23 , V_22 ) ;
}
static void F_17 ( struct V_11 * V_12 , struct V_10 * V_15 )
{
struct V_18 * V_19 = V_12 -> V_20 ;
switch ( V_15 -> V_21 ) {
default:
F_14 ( V_19 , L_5 , V_15 -> V_21 ) ;
case - V_28 :
case - V_29 :
break;
case 0 :
break;
}
F_18 ( & V_19 -> V_23 ) ;
F_10 ( & V_15 -> V_24 ) ;
F_13 ( & V_15 -> V_24 , & V_19 -> V_34 ) ;
F_15 ( & V_19 -> V_35 ) ;
if ( F_19 ( F_20 ( & V_19 -> V_36 ) ) )
F_15 ( & V_19 -> V_37 ) ;
F_21 ( & V_19 -> V_23 ) ;
}
static int
F_22 ( struct V_38 * V_38 , struct V_39 * V_40 )
{
struct V_18 * V_19 ;
unsigned long V_22 ;
int V_41 = - V_42 ;
F_23 ( & V_43 ) ;
V_19 = F_24 ( V_38 -> V_44 , struct V_18 , V_45 ) ;
F_9 ( & V_19 -> V_23 , V_22 ) ;
if ( ! V_19 -> V_46 ) {
V_19 -> V_46 = 1 ;
V_40 -> V_47 = V_19 ;
V_41 = 0 ;
V_19 -> V_48 |= V_49 ;
}
F_16 ( & V_19 -> V_23 , V_22 ) ;
F_12 ( V_19 , L_6 , V_41 ) ;
F_25 ( & V_43 ) ;
return V_41 ;
}
static int
F_26 ( struct V_38 * V_38 , struct V_39 * V_40 )
{
struct V_18 * V_19 = V_40 -> V_47 ;
unsigned long V_22 ;
F_9 ( & V_19 -> V_23 , V_22 ) ;
V_19 -> V_46 = 0 ;
V_40 -> V_47 = NULL ;
V_19 -> V_48 &= ~ V_49 ;
F_16 ( & V_19 -> V_23 , V_22 ) ;
F_12 ( V_19 , L_7 ) ;
return 0 ;
}
static void
F_27 ( struct V_18 * V_19 )
{
struct V_10 * V_15 ;
while ( F_19 ( ! F_20 ( & V_19 -> V_27 ) ) ) {
int error ;
V_15 = F_24 ( V_19 -> V_27 . V_50 ,
struct V_10 , V_24 ) ;
F_10 ( & V_15 -> V_24 ) ;
V_15 -> V_16 = V_51 ;
V_15 -> V_52 = F_8 ;
F_21 ( & V_19 -> V_23 ) ;
error = F_28 ( V_19 -> V_53 , V_15 , V_54 ) ;
F_18 ( & V_19 -> V_23 ) ;
if ( error ) {
F_12 ( V_19 , L_8 , error ) ;
F_13 ( & V_15 -> V_24 , & V_19 -> V_27 ) ;
break;
}
else if ( F_20 ( & V_15 -> V_24 ) ) {
F_13 ( & V_15 -> V_24 , & V_19 -> V_55 ) ;
}
}
}
static T_2
F_29 ( struct V_39 * V_40 , char T_3 * V_17 , T_4 V_13 , T_5 * V_56 )
{
struct V_18 * V_19 = V_40 -> V_47 ;
unsigned long V_22 ;
T_4 V_57 ;
T_4 V_58 ;
struct V_10 * V_15 ;
struct V_10 * V_59 ;
T_4 V_60 ;
T_6 * V_61 ;
if ( V_13 == 0 )
return - V_62 ;
F_12 ( V_19 , L_9 , ( int ) V_13 ) ;
F_23 ( & V_19 -> V_63 ) ;
F_9 ( & V_19 -> V_23 , V_22 ) ;
V_19 -> V_64 = 0 ;
F_27 ( V_19 ) ;
V_58 = 0 ;
V_59 = V_19 -> V_59 ;
V_60 = V_19 -> V_60 ;
V_61 = V_19 -> V_61 ;
V_19 -> V_59 = NULL ;
V_19 -> V_60 = 0 ;
V_19 -> V_61 = NULL ;
if ( ( V_60 == 0 ) &&
( F_19 ( F_20 ( & V_19 -> V_26 ) ) ) ) {
F_16 ( & V_19 -> V_23 , V_22 ) ;
if ( V_40 -> V_65 & ( V_66 | V_67 ) ) {
F_25 ( & V_19 -> V_63 ) ;
return - V_68 ;
}
F_30 ( V_19 -> V_33 ,
( F_19 ( ! F_20 ( & V_19 -> V_26 ) ) ) ) ;
F_9 ( & V_19 -> V_23 , V_22 ) ;
}
while ( ( V_60 || F_19 ( ! F_20 ( & V_19 -> V_26 ) ) )
&& V_13 ) {
if ( V_60 == 0 ) {
V_15 = F_24 ( V_19 -> V_26 . V_50 ,
struct V_10 , V_24 ) ;
F_10 ( & V_15 -> V_24 ) ;
if ( V_15 -> V_25 && V_15 -> V_17 ) {
V_59 = V_15 ;
V_60 = V_15 -> V_25 ;
V_61 = V_15 -> V_17 ;
} else {
F_13 ( & V_15 -> V_24 , & V_19 -> V_27 ) ;
continue;
}
}
F_16 ( & V_19 -> V_23 , V_22 ) ;
if ( V_13 > V_60 )
V_57 = V_60 ;
else
V_57 = V_13 ;
V_57 -= F_31 ( V_17 , V_61 , V_57 ) ;
V_58 += V_57 ;
V_13 -= V_57 ;
V_17 += V_57 ;
F_9 ( & V_19 -> V_23 , V_22 ) ;
if ( V_19 -> V_64 ) {
F_13 ( & V_59 -> V_24 , & V_19 -> V_27 ) ;
F_16 ( & V_19 -> V_23 , V_22 ) ;
F_25 ( & V_19 -> V_63 ) ;
return - V_68 ;
}
if ( V_57 < V_60 ) {
V_60 -= V_57 ;
V_61 += V_57 ;
} else {
F_13 ( & V_59 -> V_24 , & V_19 -> V_27 ) ;
V_60 = 0 ;
V_61 = NULL ;
V_59 = NULL ;
}
}
V_19 -> V_59 = V_59 ;
V_19 -> V_60 = V_60 ;
V_19 -> V_61 = V_61 ;
F_16 ( & V_19 -> V_23 , V_22 ) ;
F_25 ( & V_19 -> V_63 ) ;
F_12 ( V_19 , L_10 , ( int ) V_58 ) ;
if ( V_58 )
return V_58 ;
else
return - V_68 ;
}
static T_2
F_32 ( struct V_39 * V_40 , const char T_3 * V_17 , T_4 V_13 , T_5 * V_56 )
{
struct V_18 * V_19 = V_40 -> V_47 ;
unsigned long V_22 ;
T_4 V_57 ;
T_4 V_58 = 0 ;
struct V_10 * V_15 ;
F_12 ( V_19 , L_11 , ( int ) V_13 ) ;
if ( V_13 == 0 )
return - V_62 ;
F_23 ( & V_19 -> V_63 ) ;
F_9 ( & V_19 -> V_23 , V_22 ) ;
V_19 -> V_64 = 0 ;
if ( F_19 ( F_20 ( & V_19 -> V_34 ) ) ) {
F_16 ( & V_19 -> V_23 , V_22 ) ;
if ( V_40 -> V_65 & ( V_66 | V_67 ) ) {
F_25 ( & V_19 -> V_63 ) ;
return - V_68 ;
}
F_30 ( V_19 -> V_35 ,
( F_19 ( ! F_20 ( & V_19 -> V_34 ) ) ) ) ;
F_9 ( & V_19 -> V_23 , V_22 ) ;
}
while ( F_19 ( ! F_20 ( & V_19 -> V_34 ) ) && V_13 ) {
if ( V_13 > V_51 )
V_57 = V_51 ;
else
V_57 = V_13 ;
V_15 = F_24 ( V_19 -> V_34 . V_50 , struct V_10 ,
V_24 ) ;
F_10 ( & V_15 -> V_24 ) ;
V_15 -> V_52 = F_17 ;
V_15 -> V_16 = V_57 ;
if ( V_13 > V_57 )
V_15 -> V_69 = 0 ;
else
V_15 -> V_69 = ( ( V_13 % V_19 -> V_70 -> V_71 ) == 0 ) ;
F_16 ( & V_19 -> V_23 , V_22 ) ;
if ( F_33 ( V_15 -> V_17 , V_17 , V_57 ) ) {
F_13 ( & V_15 -> V_24 , & V_19 -> V_34 ) ;
F_25 ( & V_19 -> V_63 ) ;
return V_58 ;
}
V_58 += V_57 ;
V_13 -= V_57 ;
V_17 += V_57 ;
F_9 ( & V_19 -> V_23 , V_22 ) ;
if ( V_19 -> V_64 ) {
F_13 ( & V_15 -> V_24 , & V_19 -> V_34 ) ;
F_16 ( & V_19 -> V_23 , V_22 ) ;
F_25 ( & V_19 -> V_63 ) ;
return - V_68 ;
}
if ( F_28 ( V_19 -> V_70 , V_15 , V_54 ) ) {
F_13 ( & V_15 -> V_24 , & V_19 -> V_34 ) ;
F_16 ( & V_19 -> V_23 , V_22 ) ;
F_25 ( & V_19 -> V_63 ) ;
return - V_68 ;
}
F_13 ( & V_15 -> V_24 , & V_19 -> V_36 ) ;
}
F_16 ( & V_19 -> V_23 , V_22 ) ;
F_25 ( & V_19 -> V_63 ) ;
F_12 ( V_19 , L_12 , ( int ) V_58 ) ;
if ( V_58 ) {
return V_58 ;
} else {
return - V_68 ;
}
}
static int
F_34 ( struct V_39 * V_40 , T_5 V_72 , T_5 V_73 , int V_74 )
{
struct V_18 * V_19 = V_40 -> V_47 ;
struct V_38 * V_38 = F_35 ( V_40 ) ;
unsigned long V_22 ;
int V_75 ;
F_23 ( & V_38 -> V_76 ) ;
F_9 ( & V_19 -> V_23 , V_22 ) ;
V_75 = ( F_19 ( F_20 ( & V_19 -> V_34 ) ) ) ;
F_16 ( & V_19 -> V_23 , V_22 ) ;
if ( ! V_75 ) {
F_30 ( V_19 -> V_37 ,
( F_19 ( F_20 ( & V_19 -> V_36 ) ) ) ) ;
}
F_25 ( & V_38 -> V_76 ) ;
return 0 ;
}
static unsigned int
F_36 ( struct V_39 * V_40 , T_7 * V_77 )
{
struct V_18 * V_19 = V_40 -> V_47 ;
unsigned long V_22 ;
int V_21 = 0 ;
F_23 ( & V_19 -> V_63 ) ;
F_9 ( & V_19 -> V_23 , V_22 ) ;
F_27 ( V_19 ) ;
F_16 ( & V_19 -> V_23 , V_22 ) ;
F_25 ( & V_19 -> V_63 ) ;
F_37 ( V_40 , & V_19 -> V_33 , V_77 ) ;
F_37 ( V_40 , & V_19 -> V_35 , V_77 ) ;
F_9 ( & V_19 -> V_23 , V_22 ) ;
if ( F_19 ( ! F_20 ( & V_19 -> V_34 ) ) )
V_21 |= V_78 | V_79 ;
if ( F_19 ( V_19 -> V_60 ) ||
F_19 ( ! F_20 ( & V_19 -> V_26 ) ) )
V_21 |= V_80 | V_81 ;
F_16 ( & V_19 -> V_23 , V_22 ) ;
return V_21 ;
}
static long
F_38 ( struct V_39 * V_40 , unsigned int V_82 , unsigned long V_83 )
{
struct V_18 * V_19 = V_40 -> V_47 ;
unsigned long V_22 ;
int V_21 = 0 ;
F_12 ( V_19 , L_13 , V_82 , V_83 ) ;
F_9 ( & V_19 -> V_23 , V_22 ) ;
switch ( V_82 ) {
case V_84 :
V_21 = ( int ) V_19 -> V_48 ;
break;
case V_85 :
V_19 -> V_48 = ( T_6 ) V_83 ;
break;
default:
F_12 ( V_19 , L_14 ,
V_82 ) ;
V_21 = - V_86 ;
}
F_16 ( & V_19 -> V_23 , V_22 ) ;
return V_21 ;
}
static int
F_39 ( struct V_18 * V_19 )
{
int V_87 = 0 ;
V_19 -> V_70 -> V_88 = F_1 ( V_19 -> V_3 , & V_89 , & V_90 ,
& V_91 ) ;
V_19 -> V_70 -> V_20 = V_19 ;
V_19 -> V_53 -> V_88 = F_1 ( V_19 -> V_3 , & V_92 ,
& V_93 , & V_94 ) ;
V_19 -> V_53 -> V_20 = V_19 ;
V_87 = F_40 ( V_19 -> V_70 ) ;
if ( V_87 != 0 ) {
F_12 ( V_19 , L_15 , V_19 -> V_70 -> V_31 , V_87 ) ;
goto V_95;
}
V_87 = F_40 ( V_19 -> V_53 ) ;
if ( V_87 != 0 ) {
F_12 ( V_19 , L_15 , V_19 -> V_70 -> V_31 , V_87 ) ;
goto V_95;
}
V_95:
if ( V_87 != 0 ) {
( void ) F_41 ( V_19 -> V_70 ) ;
( void ) F_41 ( V_19 -> V_53 ) ;
V_19 -> V_70 -> V_88 = NULL ;
V_19 -> V_53 -> V_88 = NULL ;
}
return V_87 ;
}
static void F_42 ( struct V_18 * V_19 )
{
if ( V_19 -> V_96 < 0 )
return;
F_12 ( V_19 , L_16 , V_97 ) ;
if ( V_19 -> V_70 -> V_88 )
F_41 ( V_19 -> V_70 ) ;
if ( V_19 -> V_53 -> V_88 )
F_41 ( V_19 -> V_53 ) ;
V_19 -> V_70 -> V_88 = NULL ;
V_19 -> V_53 -> V_88 = NULL ;
V_19 -> V_96 = - 1 ;
}
static int F_43 ( struct V_18 * V_19 , unsigned V_98 )
{
int V_87 = 0 ;
F_42 ( V_19 ) ;
V_87 = F_39 ( V_19 ) ;
if ( V_87 )
F_42 ( V_19 ) ;
else
V_19 -> V_96 = V_98 ;
if ( ! V_87 )
F_44 ( V_19 , L_17 , V_98 ) ;
return V_87 ;
}
static void F_45 ( struct V_18 * V_19 )
{
struct V_10 * V_15 ;
F_44 ( V_19 , L_18 ) ;
if ( F_41 ( V_19 -> V_70 ) )
F_12 ( V_19 , L_19 ) ;
if ( F_41 ( V_19 -> V_53 ) )
F_12 ( V_19 , L_20 ) ;
if ( V_19 -> V_59 != NULL ) {
F_13 ( & V_19 -> V_59 -> V_24 , & V_19 -> V_27 ) ;
V_19 -> V_59 = NULL ;
}
V_19 -> V_60 = 0 ;
V_19 -> V_61 = NULL ;
V_19 -> V_64 = 1 ;
while ( F_19 ( ! ( F_20 ( & V_19 -> V_26 ) ) ) ) {
V_15 = F_24 ( V_19 -> V_26 . V_50 , struct V_10 ,
V_24 ) ;
F_10 ( & V_15 -> V_24 ) ;
F_13 ( & V_15 -> V_24 , & V_19 -> V_27 ) ;
}
while ( F_19 ( ! ( F_20 ( & V_19 -> V_55 ) ) ) ) {
V_15 = F_24 ( V_19 -> V_26 . V_50 , struct V_10 ,
V_24 ) ;
F_10 ( & V_15 -> V_24 ) ;
F_13 ( & V_15 -> V_24 , & V_19 -> V_27 ) ;
}
while ( F_19 ( ! ( F_20 ( & V_19 -> V_36 ) ) ) ) {
V_15 = F_24 ( V_19 -> V_36 . V_50 ,
struct V_10 , V_24 ) ;
F_10 ( & V_15 -> V_24 ) ;
F_13 ( & V_15 -> V_24 , & V_19 -> V_34 ) ;
}
if ( F_40 ( V_19 -> V_70 ) )
F_12 ( V_19 , L_21 ) ;
if ( F_40 ( V_19 -> V_53 ) )
F_12 ( V_19 , L_22 ) ;
F_15 ( & V_19 -> V_33 ) ;
F_15 ( & V_19 -> V_35 ) ;
F_15 ( & V_19 -> V_37 ) ;
}
static int F_46 ( struct V_99 * V_100 ,
const struct V_101 * V_102 )
{
struct V_18 * V_19 = F_24 ( V_100 , struct V_18 , V_103 ) ;
struct V_104 * V_105 = V_100 -> V_106 -> V_105 ;
struct V_10 * V_15 = V_105 -> V_15 ;
int V_107 = - V_108 ;
T_8 V_109 = F_47 ( V_102 -> V_109 ) ;
T_8 V_110 = F_47 ( V_102 -> V_110 ) ;
T_8 V_111 = F_47 ( V_102 -> V_111 ) ;
F_12 ( V_19 , L_23 ,
V_102 -> V_112 , V_102 -> V_113 , V_110 , V_109 , V_111 ) ;
switch ( V_102 -> V_112 & V_114 ) {
case V_115 :
switch ( V_102 -> V_113 ) {
case 0 :
if ( ( V_109 >> 8 ) != V_19 -> V_96 )
break;
V_107 = ( V_116 [ 0 ] << 8 ) | V_116 [ 1 ] ;
memcpy ( V_15 -> V_17 , V_116 , V_107 ) ;
F_12 ( V_19 , L_24 , V_107 ,
& V_116 [ 2 ] ) ;
break;
case 1 :
if ( V_109 != V_19 -> V_96 )
break;
* ( T_6 * ) V_15 -> V_17 = V_19 -> V_48 ;
V_107 = F_48 ( V_111 , ( T_8 ) 1 ) ;
break;
case 2 :
if ( V_109 != V_19 -> V_96 )
break;
F_45 ( V_19 ) ;
V_107 = 0 ;
break;
default:
goto V_117;
}
break;
default:
V_117:
F_14 ( V_19 ,
L_25 ,
V_102 -> V_112 , V_102 -> V_113 ,
V_110 , V_109 , V_111 ) ;
break;
}
return V_107 ;
}
static int T_9 F_49 ( struct V_118 * V_119 ,
struct V_99 * V_100 )
{
struct V_18 * V_19 = F_24 ( V_100 , struct V_18 , V_103 ) ;
struct V_104 * V_105 = V_119 -> V_105 ;
struct V_11 * V_70 ;
struct V_11 * V_53 = NULL ;
int V_120 ;
int V_41 ;
V_120 = F_50 ( V_119 , V_100 ) ;
if ( V_120 < 0 )
return V_120 ;
V_121 . V_122 = V_120 ;
V_70 = F_51 ( V_105 -> V_3 , & V_89 ) ;
if ( ! V_70 ) {
V_123:
F_52 ( & V_105 -> V_3 -> V_19 , L_26 ,
V_105 -> V_3 -> V_31 ) ;
return - V_124 ;
}
V_70 -> V_20 = V_70 ;
V_53 = F_51 ( V_105 -> V_3 , & V_92 ) ;
if ( ! V_53 )
goto V_123;
V_53 -> V_20 = V_53 ;
V_90 . V_125 = V_89 . V_125 ;
V_93 . V_125 = V_92 . V_125 ;
V_91 . V_125 = V_89 . V_125 ;
V_94 . V_125 = V_92 . V_125 ;
V_41 = F_53 ( V_100 , V_126 ,
V_127 , V_128 ) ;
if ( V_41 )
return V_41 ;
V_19 -> V_70 = V_70 ;
V_19 -> V_53 = V_53 ;
return 0 ;
}
static void F_54 ( struct V_118 * V_119 ,
struct V_99 * V_100 )
{
F_55 ( V_100 ) ;
}
static int F_56 ( struct V_99 * V_100 ,
unsigned V_129 , unsigned V_130 )
{
struct V_18 * V_19 = F_24 ( V_100 , struct V_18 , V_103 ) ;
int V_41 = - V_131 ;
if ( ! V_130 )
V_41 = F_43 ( V_19 , V_129 ) ;
return V_41 ;
}
static void F_57 ( struct V_99 * V_100 )
{
struct V_18 * V_19 = F_24 ( V_100 , struct V_18 , V_103 ) ;
unsigned long V_22 ;
F_12 ( V_19 , L_16 , V_97 ) ;
F_9 ( & V_19 -> V_23 , V_22 ) ;
F_42 ( V_19 ) ;
F_16 ( & V_19 -> V_23 , V_22 ) ;
}
static void F_58 ( struct V_118 * V_119 )
{
struct V_18 * V_19 ;
struct V_10 * V_15 ;
V_19 = & V_132 ;
F_12 ( V_19 , L_16 , V_97 ) ;
F_59 ( V_133 , V_134 ) ;
F_60 ( & V_19 -> V_45 ) ;
F_61 ( ! F_20 ( & V_19 -> V_36 ) ) ;
F_61 ( ! F_20 ( & V_19 -> V_55 ) ) ;
while ( ! F_20 ( & V_19 -> V_34 ) ) {
V_15 = F_24 ( V_19 -> V_34 . V_50 , struct V_10 ,
V_24 ) ;
F_62 ( & V_15 -> V_24 ) ;
F_6 ( V_19 -> V_70 , V_15 ) ;
}
if ( V_19 -> V_59 != NULL )
F_6 ( V_19 -> V_53 , V_19 -> V_59 ) ;
while ( ! F_20 ( & V_19 -> V_27 ) ) {
V_15 = F_24 ( V_19 -> V_27 . V_50 ,
struct V_10 , V_24 ) ;
F_62 ( & V_15 -> V_24 ) ;
F_6 ( V_19 -> V_53 , V_15 ) ;
}
while ( ! F_20 ( & V_19 -> V_26 ) ) {
V_15 = F_24 ( V_19 -> V_26 . V_50 ,
struct V_10 , V_24 ) ;
F_62 ( & V_15 -> V_24 ) ;
F_6 ( V_19 -> V_53 , V_15 ) ;
}
}
static int T_9 F_63 ( struct V_118 * V_119 )
{
struct V_2 * V_3 = V_119 -> V_105 -> V_3 ;
struct V_18 * V_19 ;
int V_21 = - V_135 ;
T_4 V_13 ;
T_10 V_136 ;
struct V_10 * V_15 ;
F_64 ( V_3 ) ;
V_19 = & V_132 ;
V_19 -> V_103 . V_31 = V_137 ;
V_19 -> V_103 . V_138 = F_49 ;
V_19 -> V_103 . V_139 = F_46 ;
V_19 -> V_103 . V_140 = F_54 ;
V_19 -> V_103 . V_141 = F_56 ;
V_19 -> V_103 . V_142 = F_57 ;
V_21 = F_65 ( V_119 , & V_19 -> V_103 ) ;
if ( V_21 )
return V_21 ;
V_19 -> V_143 = F_66 ( V_133 , NULL , V_134 ,
NULL , L_27 ) ;
if ( F_67 ( V_19 -> V_143 ) ) {
ERROR ( V_19 , L_28 ) ;
V_21 = F_68 ( V_19 -> V_143 ) ;
goto V_144;
}
F_69 ( & V_19 -> V_45 , & V_145 ) ;
V_19 -> V_45 . V_146 = V_147 ;
V_21 = F_70 ( & V_19 -> V_45 , V_134 , 1 ) ;
if ( V_21 ) {
ERROR ( V_19 , L_29 ) ;
goto V_144;
}
if ( V_148 )
F_71 ( & V_116 [ 2 ] , V_148 , ( sizeof V_116 ) - 2 ) ;
V_13 = strlen ( V_116 ) ;
V_116 [ 0 ] = ( V_13 >> 8 ) & 0xFF ;
V_116 [ 1 ] = V_13 & 0xFF ;
F_72 ( V_3 ) ;
if ( F_73 ( V_3 ) ) {
V_149 . V_150 |= V_151 ;
V_152 . V_153 = V_154 ;
V_152 . V_150 |= V_155 ;
}
F_74 ( & V_19 -> V_23 ) ;
F_75 ( & V_19 -> V_63 ) ;
F_76 ( & V_19 -> V_34 ) ;
F_76 ( & V_19 -> V_36 ) ;
F_76 ( & V_19 -> V_27 ) ;
F_76 ( & V_19 -> V_55 ) ;
F_76 ( & V_19 -> V_26 ) ;
F_77 ( & V_19 -> V_33 ) ;
F_77 ( & V_19 -> V_35 ) ;
F_77 ( & V_19 -> V_37 ) ;
V_19 -> V_96 = - 1 ;
V_19 -> V_46 = 0 ;
V_19 -> V_48 = V_156 ;
V_19 -> V_59 = NULL ;
V_19 -> V_60 = 0 ;
V_19 -> V_61 = NULL ;
for ( V_136 = 0 ; V_136 < V_157 ; V_136 ++ ) {
V_15 = F_2 ( V_19 -> V_70 , V_51 , V_158 ) ;
if ( ! V_15 ) {
while ( ! F_20 ( & V_19 -> V_34 ) ) {
V_15 = F_24 ( V_19 -> V_34 . V_50 ,
struct V_10 , V_24 ) ;
F_62 ( & V_15 -> V_24 ) ;
F_6 ( V_19 -> V_70 , V_15 ) ;
}
return - V_135 ;
}
F_13 ( & V_15 -> V_24 , & V_19 -> V_34 ) ;
}
for ( V_136 = 0 ; V_136 < V_157 ; V_136 ++ ) {
V_15 = F_2 ( V_19 -> V_53 , V_51 , V_158 ) ;
if ( ! V_15 ) {
while ( ! F_20 ( & V_19 -> V_27 ) ) {
V_15 = F_24 ( V_19 -> V_27 . V_50 ,
struct V_10 , V_24 ) ;
F_62 ( & V_15 -> V_24 ) ;
F_6 ( V_19 -> V_53 , V_15 ) ;
}
return - V_135 ;
}
F_13 ( & V_15 -> V_24 , & V_19 -> V_27 ) ;
}
V_19 -> V_3 = V_3 ;
F_44 ( V_19 , L_30 V_159 L_31 , V_160 ) ;
return 0 ;
V_144:
F_58 ( V_119 ) ;
return V_21 ;
}
static int F_78 ( struct V_104 * V_105 )
{
return 0 ;
}
static int T_9 F_79 ( struct V_104 * V_105 )
{
int V_41 ;
V_41 = F_80 ( V_105 , V_161 ) ;
if ( V_41 < 0 )
return V_41 ;
V_162 . V_163 = V_161 [ V_164 ] . V_120 ;
V_162 . V_165 = V_161 [ V_166 ] . V_120 ;
V_162 . V_167 = V_161 [ V_168 ] . V_120 ;
V_41 = F_81 ( V_105 , & V_152 , F_63 ) ;
if ( V_41 )
return V_41 ;
F_82 ( V_105 , & V_169 ) ;
return V_41 ;
}
static int T_9
F_83 ( void )
{
int V_21 ;
V_133 = F_84 ( V_147 , L_32 ) ;
if ( F_67 ( V_133 ) ) {
V_21 = F_68 ( V_133 ) ;
F_85 ( L_33 , V_21 ) ;
return V_21 ;
}
V_21 = F_86 ( & V_134 , 0 , 1 ,
L_34 ) ;
if ( V_21 ) {
F_85 ( L_35 , V_21 ) ;
F_87 ( V_133 ) ;
return V_21 ;
}
V_21 = F_88 ( & V_170 ) ;
if ( V_21 ) {
F_87 ( V_133 ) ;
F_89 ( V_134 , 1 ) ;
F_85 ( L_36 , V_21 ) ;
}
return V_21 ;
}
static void T_11
F_90 ( void )
{
F_23 ( & V_132 . V_63 ) ;
F_91 ( & V_170 ) ;
F_89 ( V_134 , 1 ) ;
F_87 ( V_133 ) ;
F_25 ( & V_132 . V_63 ) ;
}
