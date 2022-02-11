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
F_20 ( & V_10 -> V_14 ) ;
error = F_27 ( V_10 -> V_44 , V_6 , V_45 ) ;
F_17 ( & V_10 -> V_14 ) ;
if ( error ) {
F_11 ( V_10 , L_8 , error ) ;
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
break;
}
else if ( F_19 ( & V_6 -> V_15 ) ) {
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
struct V_29 * V_29 = F_34 ( V_31 ) ;
unsigned long V_13 ;
int V_66 ;
F_22 ( & V_29 -> V_67 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
V_66 = ( F_18 ( F_19 ( & V_10 -> V_25 ) ) ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
if ( ! V_66 ) {
F_29 ( V_10 -> V_28 ,
( F_18 ( F_19 ( & V_10 -> V_27 ) ) ) ) ;
}
F_24 ( & V_29 -> V_67 ) ;
return 0 ;
}
static unsigned int
F_35 ( struct V_30 * V_31 , T_7 * V_68 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
unsigned long V_13 ;
int V_12 = 0 ;
F_22 ( & V_10 -> V_54 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
F_26 ( V_10 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
F_24 ( & V_10 -> V_54 ) ;
F_36 ( V_31 , & V_10 -> V_24 , V_68 ) ;
F_36 ( V_31 , & V_10 -> V_26 , V_68 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
if ( F_18 ( ! F_19 ( & V_10 -> V_25 ) ) )
V_12 |= V_69 | V_70 ;
if ( F_18 ( V_10 -> V_51 ) ||
F_18 ( ! F_19 ( & V_10 -> V_17 ) ) )
V_12 |= V_71 | V_72 ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
return V_12 ;
}
static long
F_37 ( struct V_30 * V_31 , unsigned int V_73 , unsigned long V_74 )
{
struct V_9 * V_10 = V_31 -> V_38 ;
unsigned long V_13 ;
int V_12 = 0 ;
F_11 ( V_10 , L_13 , V_73 , V_74 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
switch ( V_73 ) {
case V_75 :
V_12 = ( int ) V_10 -> V_39 ;
break;
case V_76 :
V_10 -> V_39 = ( T_6 ) V_74 ;
break;
default:
F_11 ( V_10 , L_14 ,
V_73 ) ;
V_12 = - V_77 ;
}
F_15 ( & V_10 -> V_14 , V_13 ) ;
return V_12 ;
}
static int
F_38 ( struct V_9 * V_10 )
{
int V_78 = 0 ;
V_10 -> V_61 -> V_79 = F_39 ( V_10 -> V_80 , & V_81 , & V_82 ) ;
V_10 -> V_61 -> V_11 = V_10 ;
V_10 -> V_44 -> V_79 = F_39 ( V_10 -> V_80 , & V_83 ,
& V_84 ) ;
V_10 -> V_44 -> V_11 = V_10 ;
V_78 = F_40 ( V_10 -> V_61 ) ;
if ( V_78 != 0 ) {
F_11 ( V_10 , L_15 , V_10 -> V_61 -> V_22 , V_78 ) ;
goto V_85;
}
V_78 = F_40 ( V_10 -> V_44 ) ;
if ( V_78 != 0 ) {
F_11 ( V_10 , L_15 , V_10 -> V_61 -> V_22 , V_78 ) ;
goto V_85;
}
V_85:
if ( V_78 != 0 ) {
( void ) F_41 ( V_10 -> V_61 ) ;
( void ) F_41 ( V_10 -> V_44 ) ;
V_10 -> V_61 -> V_79 = NULL ;
V_10 -> V_44 -> V_79 = NULL ;
}
return V_78 ;
}
static void F_42 ( struct V_9 * V_10 )
{
if ( V_10 -> V_86 < 0 )
return;
F_11 ( V_10 , L_16 , V_87 ) ;
if ( V_10 -> V_61 -> V_79 )
F_41 ( V_10 -> V_61 ) ;
if ( V_10 -> V_44 -> V_79 )
F_41 ( V_10 -> V_44 ) ;
V_10 -> V_61 -> V_79 = NULL ;
V_10 -> V_44 -> V_79 = NULL ;
V_10 -> V_86 = - 1 ;
}
static int F_43 ( struct V_9 * V_10 , unsigned V_88 )
{
int V_78 = 0 ;
F_42 ( V_10 ) ;
V_78 = F_38 ( V_10 ) ;
if ( V_78 )
F_42 ( V_10 ) ;
else
V_10 -> V_86 = V_88 ;
if ( ! V_78 )
F_44 ( V_10 , L_17 , V_88 ) ;
return V_78 ;
}
static void F_45 ( struct V_9 * V_10 )
{
struct V_1 * V_6 ;
F_44 ( V_10 , L_18 ) ;
if ( F_41 ( V_10 -> V_61 ) )
F_11 ( V_10 , L_19 ) ;
if ( F_41 ( V_10 -> V_44 ) )
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
if ( F_40 ( V_10 -> V_61 ) )
F_11 ( V_10 , L_21 ) ;
if ( F_40 ( V_10 -> V_44 ) )
F_11 ( V_10 , L_22 ) ;
F_14 ( & V_10 -> V_24 ) ;
F_14 ( & V_10 -> V_26 ) ;
F_14 ( & V_10 -> V_28 ) ;
}
static int F_46 ( struct V_89 * V_90 ,
const struct V_91 * V_92 )
{
struct V_9 * V_10 = F_23 ( V_90 , struct V_9 , V_93 ) ;
struct V_94 * V_95 = V_90 -> V_96 -> V_95 ;
struct V_1 * V_6 = V_95 -> V_6 ;
int V_97 = - V_98 ;
T_8 V_99 = F_47 ( V_92 -> V_99 ) ;
T_8 V_100 = F_47 ( V_92 -> V_100 ) ;
T_8 V_101 = F_47 ( V_92 -> V_101 ) ;
F_11 ( V_10 , L_23 ,
V_92 -> V_102 , V_92 -> V_103 , V_100 , V_99 , V_101 ) ;
switch ( V_92 -> V_102 & V_104 ) {
case V_105 :
switch ( V_92 -> V_103 ) {
case 0 :
if ( ( V_99 >> 8 ) != V_10 -> V_86 )
break;
V_97 = ( V_106 [ 0 ] << 8 ) | V_106 [ 1 ] ;
memcpy ( V_6 -> V_8 , V_106 , V_97 ) ;
F_11 ( V_10 , L_24 , V_97 ,
& V_106 [ 2 ] ) ;
break;
case 1 :
if ( V_99 != V_10 -> V_86 )
break;
* ( T_6 * ) V_6 -> V_8 = V_10 -> V_39 ;
V_97 = F_48 ( V_101 , ( T_8 ) 1 ) ;
break;
case 2 :
if ( V_99 != V_10 -> V_86 )
break;
F_45 ( V_10 ) ;
V_97 = 0 ;
break;
default:
goto V_107;
}
break;
default:
V_107:
F_13 ( V_10 ,
L_25 ,
V_92 -> V_102 , V_92 -> V_103 ,
V_100 , V_99 , V_101 ) ;
break;
}
return V_97 ;
}
static int T_9 F_49 ( struct V_108 * V_109 ,
struct V_89 * V_90 )
{
struct V_9 * V_10 = F_23 ( V_90 , struct V_9 , V_93 ) ;
struct V_94 * V_95 = V_109 -> V_95 ;
struct V_2 * V_61 ;
struct V_2 * V_44 = NULL ;
int V_110 ;
int V_32 ;
V_110 = F_50 ( V_109 , V_90 ) ;
if ( V_110 < 0 )
return V_110 ;
V_111 . V_112 = V_110 ;
V_61 = F_51 ( V_95 -> V_80 , & V_82 ) ;
if ( ! V_61 ) {
V_113:
F_52 ( & V_95 -> V_80 -> V_10 , L_26 ,
V_95 -> V_80 -> V_22 ) ;
return - V_114 ;
}
V_61 -> V_11 = V_61 ;
V_44 = F_51 ( V_95 -> V_80 , & V_84 ) ;
if ( ! V_44 )
goto V_113;
V_44 -> V_11 = V_44 ;
V_81 . V_115 = V_82 . V_115 ;
V_83 . V_115 = V_84 . V_115 ;
V_32 = F_53 ( V_90 , V_116 ,
V_117 , NULL ) ;
if ( V_32 )
return V_32 ;
V_10 -> V_61 = V_61 ;
V_10 -> V_44 = V_44 ;
return 0 ;
}
static void F_54 ( struct V_108 * V_109 ,
struct V_89 * V_90 )
{
F_55 ( V_90 ) ;
}
static int F_56 ( struct V_89 * V_90 ,
unsigned V_118 , unsigned V_119 )
{
struct V_9 * V_10 = F_23 ( V_90 , struct V_9 , V_93 ) ;
int V_32 = - V_120 ;
if ( ! V_119 )
V_32 = F_43 ( V_10 , V_118 ) ;
return V_32 ;
}
static void F_57 ( struct V_89 * V_90 )
{
struct V_9 * V_10 = F_23 ( V_90 , struct V_9 , V_93 ) ;
unsigned long V_13 ;
F_11 ( V_10 , L_16 , V_87 ) ;
F_8 ( & V_10 -> V_14 , V_13 ) ;
F_42 ( V_10 ) ;
F_15 ( & V_10 -> V_14 , V_13 ) ;
}
static void F_58 ( struct V_108 * V_109 )
{
struct V_9 * V_10 ;
struct V_1 * V_6 ;
V_10 = & V_121 ;
F_11 ( V_10 , L_16 , V_87 ) ;
F_59 ( V_122 , V_123 ) ;
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
}
static int T_9 F_63 ( struct V_108 * V_109 )
{
struct V_124 * V_80 = V_109 -> V_95 -> V_80 ;
struct V_9 * V_10 ;
int V_12 = - V_125 ;
T_4 V_4 ;
T_10 V_126 ;
struct V_1 * V_6 ;
F_64 ( V_80 ) ;
V_10 = & V_121 ;
V_10 -> V_93 . V_22 = V_127 ;
V_10 -> V_93 . V_128 = F_49 ;
V_10 -> V_93 . V_129 = F_46 ;
V_10 -> V_93 . V_130 = F_54 ;
V_10 -> V_93 . V_131 = F_56 ;
V_10 -> V_93 . V_132 = F_57 ;
V_12 = F_65 ( V_109 , & V_10 -> V_93 ) ;
if ( V_12 )
return V_12 ;
V_10 -> V_133 = F_66 ( V_122 , NULL , V_123 ,
NULL , L_27 ) ;
if ( F_67 ( V_10 -> V_133 ) ) {
ERROR ( V_10 , L_28 ) ;
V_12 = F_68 ( V_10 -> V_133 ) ;
goto V_134;
}
F_69 ( & V_10 -> V_36 , & V_135 ) ;
V_10 -> V_36 . V_136 = V_137 ;
V_12 = F_70 ( & V_10 -> V_36 , V_123 , 1 ) ;
if ( V_12 ) {
ERROR ( V_10 , L_29 ) ;
goto V_134;
}
if ( V_138 )
F_71 ( & V_106 [ 2 ] , V_138 , ( sizeof V_106 ) - 2 ) ;
V_4 = strlen ( V_106 ) ;
V_106 [ 0 ] = ( V_4 >> 8 ) & 0xFF ;
V_106 [ 1 ] = V_4 & 0xFF ;
F_72 ( V_80 ) ;
if ( F_73 ( V_80 ) ) {
V_139 . V_140 |= V_141 ;
V_142 . V_143 = V_144 ;
V_142 . V_140 |= V_145 ;
}
F_74 ( & V_10 -> V_14 ) ;
F_75 ( & V_10 -> V_54 ) ;
F_76 ( & V_10 -> V_25 ) ;
F_76 ( & V_10 -> V_27 ) ;
F_76 ( & V_10 -> V_18 ) ;
F_76 ( & V_10 -> V_46 ) ;
F_76 ( & V_10 -> V_17 ) ;
F_77 ( & V_10 -> V_24 ) ;
F_77 ( & V_10 -> V_26 ) ;
F_77 ( & V_10 -> V_28 ) ;
V_10 -> V_86 = - 1 ;
V_10 -> V_37 = 0 ;
V_10 -> V_39 = V_146 ;
V_10 -> V_50 = NULL ;
V_10 -> V_51 = 0 ;
V_10 -> V_52 = NULL ;
for ( V_126 = 0 ; V_126 < V_147 ; V_126 ++ ) {
V_6 = F_1 ( V_10 -> V_61 , V_42 , V_148 ) ;
if ( ! V_6 ) {
while ( ! F_19 ( & V_10 -> V_25 ) ) {
V_6 = F_23 ( V_10 -> V_25 . V_41 ,
struct V_1 , V_15 ) ;
F_62 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_61 , V_6 ) ;
}
return - V_125 ;
}
F_12 ( & V_6 -> V_15 , & V_10 -> V_25 ) ;
}
for ( V_126 = 0 ; V_126 < V_147 ; V_126 ++ ) {
V_6 = F_1 ( V_10 -> V_44 , V_42 , V_148 ) ;
if ( ! V_6 ) {
while ( ! F_19 ( & V_10 -> V_18 ) ) {
V_6 = F_23 ( V_10 -> V_18 . V_41 ,
struct V_1 , V_15 ) ;
F_62 ( & V_6 -> V_15 ) ;
F_5 ( V_10 -> V_44 , V_6 ) ;
}
return - V_125 ;
}
F_12 ( & V_6 -> V_15 , & V_10 -> V_18 ) ;
}
V_10 -> V_80 = V_80 ;
F_44 ( V_10 , L_30 V_149 L_31 , V_150 ) ;
return 0 ;
V_134:
F_58 ( V_109 ) ;
return V_12 ;
}
static int F_78 ( struct V_94 * V_95 )
{
return 0 ;
}
static int T_9 F_79 ( struct V_94 * V_95 )
{
int V_32 ;
V_32 = F_80 ( V_95 , V_151 ) ;
if ( V_32 < 0 )
return V_32 ;
V_152 . V_153 = V_151 [ V_154 ] . V_110 ;
V_152 . V_155 = V_151 [ V_156 ] . V_110 ;
V_152 . V_157 = V_151 [ V_158 ] . V_110 ;
V_32 = F_81 ( V_95 , & V_142 , F_63 ) ;
if ( V_32 )
return V_32 ;
F_82 ( V_95 , & V_159 ) ;
return V_32 ;
}
static int T_9
F_83 ( void )
{
int V_12 ;
V_122 = F_84 ( V_137 , L_32 ) ;
if ( F_67 ( V_122 ) ) {
V_12 = F_68 ( V_122 ) ;
F_85 ( L_33 , V_12 ) ;
return V_12 ;
}
V_12 = F_86 ( & V_123 , 0 , 1 ,
L_34 ) ;
if ( V_12 ) {
F_85 ( L_35 , V_12 ) ;
F_87 ( V_122 ) ;
return V_12 ;
}
V_12 = F_88 ( & V_160 ) ;
if ( V_12 ) {
F_87 ( V_122 ) ;
F_89 ( V_123 , 1 ) ;
F_85 ( L_36 , V_12 ) ;
}
return V_12 ;
}
static void T_11
F_90 ( void )
{
F_22 ( & V_121 . V_54 ) ;
F_91 ( & V_160 ) ;
F_89 ( V_123 , 1 ) ;
F_87 ( V_122 ) ;
F_24 ( & V_121 . V_54 ) ;
}
