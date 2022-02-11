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
F_33 ( struct V_30 * V_31 , T_5 V_63 , T_5 V_64 , int V_65 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
struct V_29 * V_29 = V_31 -> V_66 . V_67 -> V_68 ;
unsigned long V_13 ;
int V_69 ;
F_22 ( & V_29 -> V_70 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
V_69 = ( F_18 ( F_19 ( & V_10 -> V_25 ) ) ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
if ( ! V_69 ) {
F_29 ( V_10 -> V_28 ,
( F_18 ( F_19 ( & V_10 -> V_27 ) ) ) ) ;
}
F_24 ( & V_29 -> V_70 ) ;
return 0 ;
}
static unsigned int
F_34 ( struct V_30 * V_31 , T_7 * V_71 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
unsigned long V_13 ;
int V_12 = 0 ;
F_22 ( & V_10 -> V_54 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
F_26 ( V_10 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_24 ( & V_10 -> V_54 ) ;
F_35 ( V_31 , & V_10 -> V_24 , V_71 ) ;
F_35 ( V_31 , & V_10 -> V_26 , V_71 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
if ( F_18 ( ! F_19 ( & V_10 -> V_25 ) ) )
V_12 |= V_72 | V_73 ;
if ( F_18 ( V_10 -> V_51 ) ||
F_18 ( ! F_19 ( & V_10 -> V_17 ) ) )
V_12 |= V_74 | V_75 ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
return V_12 ;
}
static long
F_36 ( struct V_30 * V_31 , unsigned int V_76 , unsigned long V_77 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
unsigned long V_13 ;
int V_12 = 0 ;
F_11 ( V_10 , L_13 , V_76 , V_77 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
switch ( V_76 ) {
case V_78 :
V_12 = ( int ) V_10 -> V_39 ;
break;
case V_79 :
V_10 -> V_39 = ( T_6 ) V_77 ;
break;
default:
F_11 ( V_10 , L_14 ,
V_76 ) ;
V_12 = - V_80 ;
}
F_15 ( & V_10 -> V_14 , V_13 ) ;
return V_12 ;
}
static int
F_37 ( struct V_9 * V_10 )
{
int V_81 = 0 ;
V_10 -> V_61 -> V_82 = F_38 ( V_10 -> V_83 , & V_84 , & V_85 ) ;
V_10 -> V_61 -> V_11 = V_10 ;
V_10 -> V_44 -> V_82 = F_38 ( V_10 -> V_83 , & V_86 ,
& V_87 ) ;
V_10 -> V_44 -> V_11 = V_10 ;
V_81 = F_39 ( V_10 -> V_61 ) ;
if ( V_81 != 0 ) {
F_11 ( V_10 , L_15 , V_10 -> V_61 -> V_22 , V_81 ) ;
goto V_88;
}
V_81 = F_39 ( V_10 -> V_44 ) ;
if ( V_81 != 0 ) {
F_11 ( V_10 , L_15 , V_10 -> V_61 -> V_22 , V_81 ) ;
goto V_88;
}
V_88:
if ( V_81 != 0 ) {
( void ) F_40 ( V_10 -> V_61 ) ;
( void ) F_40 ( V_10 -> V_44 ) ;
V_10 -> V_61 -> V_82 = NULL ;
V_10 -> V_44 -> V_82 = NULL ;
}
return V_81 ;
}
static void F_41 ( struct V_9 * V_10 )
{
if ( V_10 -> V_89 < 0 )
return;
F_11 ( V_10 , L_16 , V_90 ) ;
if ( V_10 -> V_61 -> V_82 )
F_40 ( V_10 -> V_61 ) ;
if ( V_10 -> V_44 -> V_82 )
F_40 ( V_10 -> V_44 ) ;
V_10 -> V_61 -> V_82 = NULL ;
V_10 -> V_44 -> V_82 = NULL ;
V_10 -> V_89 = - 1 ;
}
static int F_42 ( struct V_9 * V_10 , unsigned V_91 )
{
int V_81 = 0 ;
F_41 ( V_10 ) ;
V_81 = F_37 ( V_10 ) ;
if ( V_81 )
F_41 ( V_10 ) ;
else
V_10 -> V_89 = V_91 ;
if ( ! V_81 )
F_43 ( V_10 , L_17 , V_91 ) ;
return V_81 ;
}
static void F_44 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
F_43 ( V_10 , L_18 ) ;
if ( F_40 ( V_10 -> V_61 ) )
F_11 ( V_10 , L_19 ) ;
if ( F_40 ( V_10 -> V_44 ) )
F_11 ( V_10 , L_20 ) ;
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
if ( F_39 ( V_10 -> V_61 ) )
F_11 ( V_10 , L_21 ) ;
if ( F_39 ( V_10 -> V_44 ) )
F_11 ( V_10 , L_22 ) ;
F_14 ( & V_10 -> V_24 ) ;
F_14 ( & V_10 -> V_26 ) ;
F_14 ( & V_10 -> V_28 ) ;
}
static int F_45 ( struct V_92 * V_93 ,
const struct V_94 * V_95 )
{
struct V_9 * V_10 = F_23 ( V_93 , struct V_9 , V_96 ) ;
struct V_97 * V_98 = V_93 -> V_99 -> V_98 ;
struct V_1 * V_6 = V_98 -> V_6 ;
int V_100 = - V_101 ;
T_8 V_102 = F_46 ( V_95 -> V_102 ) ;
T_8 V_103 = F_46 ( V_95 -> V_103 ) ;
T_8 V_104 = F_46 ( V_95 -> V_104 ) ;
F_11 ( V_10 , L_23 ,
V_95 -> V_105 , V_95 -> V_106 , V_103 , V_102 , V_104 ) ;
switch ( V_95 -> V_105 & V_107 ) {
case V_108 :
switch ( V_95 -> V_106 ) {
case 0 :
if ( ( V_102 >> 8 ) != V_10 -> V_89 )
break;
V_100 = ( V_109 [ 0 ] << 8 ) | V_109 [ 1 ] ;
memcpy ( V_6 -> V_8 , V_109 , V_100 ) ;
F_11 ( V_10 , L_24 , V_100 ,
& V_109 [ 2 ] ) ;
break;
case 1 :
if ( V_102 != V_10 -> V_89 )
break;
* ( T_6 * ) V_6 -> V_8 = V_10 -> V_39 ;
V_100 = F_47 ( V_104 , ( T_8 ) 1 ) ;
break;
case 2 :
if ( V_102 != V_10 -> V_89 )
break;
F_44 ( V_10 ) ;
V_100 = 0 ;
break;
default:
goto V_110;
}
break;
default:
V_110:
F_13 ( V_10 ,
L_25 ,
V_95 -> V_105 , V_95 -> V_106 ,
V_103 , V_102 , V_104 ) ;
break;
}
return V_100 ;
}
static int T_9 F_48 ( struct V_111 * V_112 ,
struct V_92 * V_93 )
{
struct V_9 * V_10 = F_23 ( V_93 , struct V_9 , V_96 ) ;
struct V_97 * V_98 = V_112 -> V_98 ;
struct V_2 * V_61 ;
struct V_2 * V_44 = NULL ;
int V_113 ;
int V_32 ;
V_113 = F_49 ( V_112 , V_93 ) ;
if ( V_113 < 0 )
return V_113 ;
V_114 . V_115 = V_113 ;
V_61 = F_50 ( V_98 -> V_83 , & V_85 ) ;
if ( ! V_61 ) {
V_116:
F_51 ( & V_98 -> V_83 -> V_10 , L_26 ,
V_98 -> V_83 -> V_22 ) ;
return - V_117 ;
}
V_61 -> V_11 = V_61 ;
V_44 = F_50 ( V_98 -> V_83 , & V_87 ) ;
if ( ! V_44 )
goto V_116;
V_44 -> V_11 = V_44 ;
V_84 . V_118 = V_85 . V_118 ;
V_86 . V_118 = V_87 . V_118 ;
V_32 = F_52 ( V_93 , V_119 ,
V_120 , NULL ) ;
if ( V_32 )
return V_32 ;
V_10 -> V_61 = V_61 ;
V_10 -> V_44 = V_44 ;
return 0 ;
}
static void F_53 ( struct V_111 * V_112 ,
struct V_92 * V_93 )
{
F_54 ( V_93 ) ;
}
static int F_55 ( struct V_92 * V_93 ,
unsigned V_121 , unsigned V_122 )
{
struct V_9 * V_10 = F_23 ( V_93 , struct V_9 , V_96 ) ;
int V_32 = - V_123 ;
if ( ! V_122 )
V_32 = F_42 ( V_10 , V_121 ) ;
return V_32 ;
}
static void F_56 ( struct V_92 * V_93 )
{
struct V_9 * V_10 = F_23 ( V_93 , struct V_9 , V_96 ) ;
unsigned long V_13 ;
F_11 ( V_10 , L_16 , V_90 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
F_41 ( V_10 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
}
static void F_57 ( struct V_111 * V_112 )
{
struct V_9 * V_10 ;
struct V_1 * V_6 ;
V_10 = & V_124 ;
F_11 ( V_10 , L_16 , V_90 ) ;
F_58 ( V_125 , V_126 ) ;
F_59 ( & V_10 -> V_36 ) ;
F_60 ( ! F_19 ( & V_10 -> V_27 ) ) ;
F_60 ( ! F_19 ( & V_10 -> V_46 ) ) ;
while ( ! F_19 ( & V_10 -> V_25 ) ) {
V_6 = F_23 ( V_10 -> V_25 . V_41 , struct V_1 ,
V_15 ) ;
F_61 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_61 , V_6 ) ;
}
if ( V_10 -> V_50 != NULL )
F_5 ( V_10 -> V_44 , V_10 -> V_50 ) ;
while ( ! F_19 ( & V_10 -> V_18 ) ) {
V_6 = F_23 ( V_10 -> V_18 . V_41 ,
struct V_1 , V_15 ) ;
F_61 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_44 , V_6 ) ;
}
while ( ! F_19 ( & V_10 -> V_17 ) ) {
V_6 = F_23 ( V_10 -> V_17 . V_41 ,
struct V_1 , V_15 ) ;
F_61 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_44 , V_6 ) ;
}
}
static int T_9 F_62 ( struct V_111 * V_112 )
{
struct V_127 * V_83 = V_112 -> V_98 -> V_83 ;
struct V_9 * V_10 ;
int V_12 = - V_128 ;
T_4 V_4 ;
T_10 V_129 ;
struct V_1 * V_6 ;
F_63 ( V_83 ) ;
V_10 = & V_124 ;
V_10 -> V_96 . V_22 = V_130 ;
V_10 -> V_96 . V_131 = F_48 ;
V_10 -> V_96 . V_132 = F_45 ;
V_10 -> V_96 . V_133 = F_53 ;
V_10 -> V_96 . V_134 = F_55 ;
V_10 -> V_96 . V_135 = F_56 ;
V_12 = F_64 ( V_112 , & V_10 -> V_96 ) ;
if ( V_12 )
return V_12 ;
V_10 -> V_136 = F_65 ( V_125 , NULL , V_126 ,
NULL , L_27 ) ;
if ( F_66 ( V_10 -> V_136 ) ) {
ERROR ( V_10 , L_28 ) ;
goto V_137;
}
F_67 ( & V_10 -> V_36 , & V_138 ) ;
V_10 -> V_36 . V_139 = V_140 ;
V_12 = F_68 ( & V_10 -> V_36 , V_126 , 1 ) ;
if ( V_12 ) {
ERROR ( V_10 , L_29 ) ;
goto V_137;
}
if ( V_141 )
F_69 ( & V_109 [ 2 ] , V_141 , ( sizeof V_109 ) - 2 ) ;
V_4 = strlen ( V_109 ) ;
V_109 [ 0 ] = ( V_4 >> 8 ) & 0xFF ;
V_109 [ 1 ] = V_4 & 0xFF ;
F_70 ( V_83 ) ;
if ( V_83 -> V_142 ) {
V_143 . V_144 |= V_145 ;
V_146 . V_147 = V_148 ;
V_146 . V_144 |= V_149 ;
}
F_71 ( & V_10 -> V_14 ) ;
F_72 ( & V_10 -> V_54 ) ;
F_73 ( & V_10 -> V_25 ) ;
F_73 ( & V_10 -> V_27 ) ;
F_73 ( & V_10 -> V_18 ) ;
F_73 ( & V_10 -> V_46 ) ;
F_73 ( & V_10 -> V_17 ) ;
F_74 ( & V_10 -> V_24 ) ;
F_74 ( & V_10 -> V_26 ) ;
F_74 ( & V_10 -> V_28 ) ;
V_10 -> V_89 = - 1 ;
V_10 -> V_37 = 0 ;
V_10 -> V_39 = V_150 ;
V_10 -> V_50 = NULL ;
V_10 -> V_51 = 0 ;
V_10 -> V_52 = NULL ;
for ( V_129 = 0 ; V_129 < V_151 ; V_129 ++ ) {
V_6 = F_1 ( V_10 -> V_61 , V_42 , V_152 ) ;
if ( ! V_6 ) {
while ( ! F_19 ( & V_10 -> V_25 ) ) {
V_6 = F_23 ( V_10 -> V_25 . V_41 ,
struct V_1 , V_15 ) ;
F_61 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_61 , V_6 ) ;
}
return - V_128 ;
}
F_12 ( & V_6 -> V_15 , & V_10 -> V_25 ) ;
}
for ( V_129 = 0 ; V_129 < V_151 ; V_129 ++ ) {
V_6 = F_1 ( V_10 -> V_44 , V_42 , V_152 ) ;
if ( ! V_6 ) {
while ( ! F_19 ( & V_10 -> V_18 ) ) {
V_6 = F_23 ( V_10 -> V_18 . V_41 ,
struct V_1 , V_15 ) ;
F_61 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_44 , V_6 ) ;
}
return - V_128 ;
}
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
}
V_10 -> V_83 = V_83 ;
F_43 ( V_10 , L_30 V_153 L_31 , V_154 ) ;
return 0 ;
V_137:
F_57 ( V_112 ) ;
return V_12 ;
}
static int F_75 ( struct V_97 * V_98 )
{
return 0 ;
}
static int T_9 F_76 ( struct V_97 * V_98 )
{
int V_32 ;
V_32 = F_77 ( V_98 , V_155 ) ;
if ( V_32 < 0 )
return V_32 ;
V_156 . V_157 = V_155 [ V_158 ] . V_113 ;
V_156 . V_159 = V_155 [ V_160 ] . V_113 ;
V_156 . V_161 = V_155 [ V_162 ] . V_113 ;
V_32 = F_78 ( V_98 , & V_146 , F_62 ) ;
if ( V_32 )
return V_32 ;
F_79 ( V_98 , & V_163 ) ;
return V_32 ;
}
static int T_9
F_80 ( void )
{
int V_12 ;
V_125 = F_81 ( V_140 , L_32 ) ;
if ( F_66 ( V_125 ) ) {
V_12 = F_82 ( V_125 ) ;
F_83 ( L_33 , V_12 ) ;
return V_12 ;
}
V_12 = F_84 ( & V_126 , 0 , 1 ,
L_34 ) ;
if ( V_12 ) {
F_83 ( L_35 , V_12 ) ;
F_85 ( V_125 ) ;
return V_12 ;
}
V_12 = F_86 ( & V_164 ) ;
if ( V_12 ) {
F_85 ( V_125 ) ;
F_87 ( V_126 , 1 ) ;
F_83 ( L_36 , V_12 ) ;
}
return V_12 ;
}
static void T_11
F_88 ( void )
{
F_22 ( & V_124 . V_54 ) ;
F_89 ( & V_164 ) ;
F_87 ( V_126 , 1 ) ;
F_85 ( V_125 ) ;
F_24 ( & V_124 . V_54 ) ;
}
