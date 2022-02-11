void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
if ( F_2 ( V_1 ) && F_3 ( V_1 ) )
F_4 ( V_1 ) ;
else
F_5 ( V_3 , V_1 ) ;
F_6 ( & V_3 -> V_4 , V_1 -> V_5 ) ;
V_1 -> V_3 = NULL ;
V_3 -> V_6 -- ;
F_7 ( V_1 , V_7 ) ;
if ( F_8 ( V_1 ) )
F_7 ( V_1 , V_8 ) ;
F_9 ( F_10 ( V_1 ) ) ;
if ( F_11 ( V_1 ) && F_12 ( V_3 ) ) {
F_13 ( V_1 , V_9 ) ;
F_14 ( V_3 -> V_10 , V_11 ) ;
}
}
void F_15 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
void (* F_16)( struct V_1 * );
F_9 ( ! F_17 ( V_1 ) ) ;
F_16 = V_3 -> V_12 -> F_16 ;
F_18 ( & V_3 -> V_13 ) ;
F_1 ( V_1 ) ;
F_19 ( & V_3 -> V_13 ) ;
F_20 ( V_1 ) ;
if ( F_16 )
F_16 ( V_1 ) ;
F_21 ( V_1 ) ;
}
static int F_22 ( void * V_14 )
{
F_23 () ;
return 0 ;
}
static int F_24 ( void * V_14 )
{
F_22 ( V_14 ) ;
return F_25 ( V_15 ) ? - V_16 : 0 ;
}
int F_26 ( struct V_2 * V_3 , T_1 V_17 ,
T_1 V_18 , int V_19 )
{
int V_20 ;
struct V_21 V_22 = {
. V_19 = V_19 ,
. V_23 = V_24 ,
. V_25 = V_17 ,
. V_26 = V_18 ,
} ;
if ( ! F_27 ( V_3 ) )
return 0 ;
V_20 = F_28 ( V_3 , & V_22 ) ;
return V_20 ;
}
static inline int F_29 ( struct V_2 * V_3 ,
int V_19 )
{
return F_26 ( V_3 , 0 , V_27 , V_19 ) ;
}
int F_30 ( struct V_2 * V_3 )
{
return F_29 ( V_3 , V_28 ) ;
}
int F_31 ( struct V_2 * V_3 , T_1 V_17 ,
T_1 V_18 )
{
return F_26 ( V_3 , V_17 , V_18 , V_28 ) ;
}
int F_32 ( struct V_2 * V_3 )
{
return F_29 ( V_3 , V_29 ) ;
}
int F_33 ( struct V_2 * V_3 , T_1 V_30 ,
T_1 V_31 )
{
T_2 V_5 = V_30 >> V_32 ;
T_2 V_18 = V_31 >> V_32 ;
struct V_33 V_34 ;
int V_35 ;
int V_20 = 0 ;
if ( V_31 < V_30 )
return 0 ;
F_34 ( & V_34 , 0 ) ;
while ( ( V_5 <= V_18 ) &&
( V_35 = F_35 ( & V_34 , V_3 , & V_5 ,
V_36 ,
F_36 ( V_18 - V_5 , ( T_2 ) V_37 - 1 ) + 1 ) ) != 0 ) {
unsigned V_38 ;
for ( V_38 = 0 ; V_38 < V_35 ; V_38 ++ ) {
struct V_1 * V_1 = V_34 . V_39 [ V_38 ] ;
if ( V_1 -> V_5 > V_18 )
continue;
F_37 ( V_1 ) ;
if ( F_38 ( V_1 ) )
V_20 = - V_40 ;
}
F_39 ( & V_34 ) ;
F_40 () ;
}
if ( F_41 ( V_41 , & V_3 -> V_42 ) )
V_20 = - V_43 ;
if ( F_41 ( V_44 , & V_3 -> V_42 ) )
V_20 = - V_40 ;
return V_20 ;
}
int F_42 ( struct V_2 * V_3 )
{
T_1 V_45 = F_43 ( V_3 -> V_46 ) ;
if ( V_45 == 0 )
return 0 ;
return F_33 ( V_3 , 0 , V_45 - 1 ) ;
}
int F_44 ( struct V_2 * V_3 )
{
int V_47 = 0 ;
if ( V_3 -> V_6 ) {
V_47 = F_30 ( V_3 ) ;
if ( V_47 != - V_40 ) {
int V_48 = F_42 ( V_3 ) ;
if ( ! V_47 )
V_47 = V_48 ;
}
}
return V_47 ;
}
int F_45 ( struct V_2 * V_3 ,
T_1 V_49 , T_1 V_50 )
{
int V_47 = 0 ;
if ( V_3 -> V_6 ) {
V_47 = F_26 ( V_3 , V_49 , V_50 ,
V_28 ) ;
if ( V_47 != - V_40 ) {
int V_48 = F_33 ( V_3 ,
V_49 , V_50 ) ;
if ( ! V_47 )
V_47 = V_48 ;
}
}
return V_47 ;
}
int F_46 ( struct V_1 * V_51 , struct V_1 * V_52 , T_3 V_53 )
{
int error ;
struct V_54 * V_55 = NULL ;
F_47 ( ! F_17 ( V_51 ) ) ;
F_47 ( ! F_17 ( V_52 ) ) ;
F_47 ( V_52 -> V_3 ) ;
error = F_48 ( V_51 , V_52 , & V_55 , V_53 ) ;
if ( error )
return error ;
error = F_49 ( V_53 & ~ V_56 ) ;
if ( ! error ) {
struct V_2 * V_3 = V_51 -> V_3 ;
void (* F_16)( struct V_1 * );
T_2 V_57 = V_51 -> V_5 ;
F_16 = V_3 -> V_12 -> F_16 ;
F_50 ( V_52 ) ;
V_52 -> V_3 = V_3 ;
V_52 -> V_5 = V_57 ;
F_18 ( & V_3 -> V_13 ) ;
F_1 ( V_51 ) ;
error = F_51 ( & V_3 -> V_4 , V_57 , V_52 ) ;
F_9 ( error ) ;
V_3 -> V_6 ++ ;
F_52 ( V_52 , V_7 ) ;
if ( F_8 ( V_52 ) )
F_52 ( V_52 , V_8 ) ;
F_19 ( & V_3 -> V_13 ) ;
F_53 () ;
if ( F_16 )
F_16 ( V_51 ) ;
F_21 ( V_51 ) ;
F_54 ( V_55 , V_51 , V_52 , true ) ;
} else {
F_54 ( V_55 , V_51 , V_52 , false ) ;
}
return error ;
}
int F_55 ( struct V_1 * V_1 , struct V_2 * V_3 ,
T_2 V_57 , T_3 V_53 )
{
int error ;
F_47 ( ! F_17 ( V_1 ) ) ;
error = F_56 ( V_1 , V_15 -> V_58 ,
V_53 & V_59 ) ;
if ( error )
goto V_60;
error = F_49 ( V_53 & ~ V_56 ) ;
if ( error == 0 ) {
F_50 ( V_1 ) ;
V_1 -> V_3 = V_3 ;
V_1 -> V_5 = V_57 ;
F_18 ( & V_3 -> V_13 ) ;
error = F_51 ( & V_3 -> V_4 , V_57 , V_1 ) ;
if ( F_57 ( ! error ) ) {
V_3 -> V_6 ++ ;
F_52 ( V_1 , V_7 ) ;
if ( F_8 ( V_1 ) )
F_52 ( V_1 , V_8 ) ;
F_19 ( & V_3 -> V_13 ) ;
} else {
V_1 -> V_3 = NULL ;
F_19 ( & V_3 -> V_13 ) ;
F_20 ( V_1 ) ;
F_21 ( V_1 ) ;
}
F_53 () ;
} else
F_20 ( V_1 ) ;
V_60:
return error ;
}
int F_58 ( struct V_1 * V_1 , struct V_2 * V_3 ,
T_2 V_57 , T_3 V_53 )
{
int V_20 ;
if ( F_59 ( V_3 ) )
F_60 ( V_1 ) ;
V_20 = F_61 ( V_1 , V_3 , V_57 , V_53 ) ;
if ( V_20 == 0 ) {
if ( F_62 ( V_1 ) )
F_63 ( V_1 ) ;
else
F_64 ( V_1 ) ;
}
return V_20 ;
}
struct V_1 * F_65 ( T_3 V_61 )
{
int V_62 ;
struct V_1 * V_1 ;
if ( F_66 () ) {
F_67 () ;
V_62 = F_68 () ;
V_1 = F_69 ( V_62 , V_61 , 0 ) ;
F_70 () ;
return V_1 ;
}
return F_71 ( V_61 , 0 ) ;
}
static T_4 * F_72 ( struct V_1 * V_1 )
{
const struct V_63 * V_63 = F_73 ( V_1 ) ;
return & V_63 -> V_64 [ F_74 ( V_1 , V_63 -> V_65 ) ] ;
}
static inline void F_75 ( struct V_1 * V_1 , int V_66 )
{
F_76 ( F_72 ( V_1 ) , & V_1 -> V_42 , V_66 ) ;
}
void F_77 ( struct V_1 * V_1 , int V_67 )
{
F_78 ( V_68 , & V_1 -> V_42 , V_67 ) ;
if ( F_79 ( V_67 , & V_1 -> V_42 ) )
F_80 ( F_72 ( V_1 ) , & V_68 , F_22 ,
V_69 ) ;
}
int F_81 ( struct V_1 * V_1 , int V_67 )
{
F_78 ( V_68 , & V_1 -> V_42 , V_67 ) ;
if ( ! F_79 ( V_67 , & V_1 -> V_42 ) )
return 0 ;
return F_80 ( F_72 ( V_1 ) , & V_68 ,
F_24 , V_70 ) ;
}
void F_82 ( struct V_1 * V_1 , T_5 * V_71 )
{
T_4 * V_72 = F_72 ( V_1 ) ;
unsigned long V_42 ;
F_83 ( & V_72 -> V_73 , V_42 ) ;
F_84 ( V_72 , V_71 ) ;
F_85 ( & V_72 -> V_73 , V_42 ) ;
}
void F_86 ( struct V_1 * V_1 )
{
F_47 ( ! F_17 ( V_1 ) ) ;
F_87 ( V_74 , & V_1 -> V_42 ) ;
F_88 () ;
F_75 ( V_1 , V_74 ) ;
}
void F_89 ( struct V_1 * V_1 )
{
if ( F_90 ( V_1 ) )
F_91 ( V_1 ) ;
if ( ! F_92 ( V_1 ) )
F_93 () ;
F_88 () ;
F_75 ( V_1 , V_75 ) ;
}
void F_94 ( struct V_1 * V_1 )
{
F_78 ( V_68 , & V_1 -> V_42 , V_74 ) ;
F_95 ( F_72 ( V_1 ) , & V_68 , F_22 ,
V_69 ) ;
}
int F_96 ( struct V_1 * V_1 )
{
F_78 ( V_68 , & V_1 -> V_42 , V_74 ) ;
return F_95 ( F_72 ( V_1 ) , & V_68 ,
F_24 , V_70 ) ;
}
int F_97 ( struct V_1 * V_1 , struct V_76 * V_58 ,
unsigned int V_42 )
{
if ( V_42 & V_77 ) {
if ( V_42 & V_78 )
return 0 ;
F_98 ( & V_58 -> V_79 ) ;
if ( V_42 & V_80 )
F_99 ( V_1 ) ;
else
F_100 ( V_1 ) ;
return 0 ;
} else {
if ( V_42 & V_80 ) {
int V_20 ;
V_20 = F_96 ( V_1 ) ;
if ( V_20 ) {
F_98 ( & V_58 -> V_79 ) ;
return 0 ;
}
} else
F_94 ( V_1 ) ;
return 1 ;
}
}
struct V_1 * F_101 ( struct V_2 * V_3 , T_2 V_57 )
{
void * * V_81 ;
struct V_1 * V_1 ;
F_102 () ;
V_82:
V_1 = NULL ;
V_81 = F_103 ( & V_3 -> V_4 , V_57 ) ;
if ( V_81 ) {
V_1 = F_104 ( V_81 ) ;
if ( F_105 ( ! V_1 ) )
goto V_60;
if ( F_106 ( V_1 ) )
goto V_82;
if ( ! F_107 ( V_1 ) )
goto V_82;
if ( F_105 ( V_1 != * V_81 ) ) {
F_21 ( V_1 ) ;
goto V_82;
}
}
V_60:
F_108 () ;
return V_1 ;
}
struct V_1 * F_109 ( struct V_2 * V_3 , T_2 V_57 )
{
struct V_1 * V_1 ;
V_82:
V_1 = F_101 ( V_3 , V_57 ) ;
if ( V_1 ) {
F_110 ( V_1 ) ;
if ( F_105 ( V_1 -> V_3 != V_3 ) ) {
F_86 ( V_1 ) ;
F_21 ( V_1 ) ;
goto V_82;
}
F_47 ( V_1 -> V_5 != V_57 ) ;
}
return V_1 ;
}
struct V_1 * F_111 ( struct V_2 * V_3 ,
T_2 V_5 , T_3 V_53 )
{
struct V_1 * V_1 ;
int V_47 ;
V_82:
V_1 = F_109 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
V_1 = F_65 ( V_53 ) ;
if ( ! V_1 )
return NULL ;
V_47 = F_58 ( V_1 , V_3 , V_5 ,
( V_53 & V_59 ) ) ;
if ( F_105 ( V_47 ) ) {
F_21 ( V_1 ) ;
V_1 = NULL ;
if ( V_47 == - V_83 )
goto V_82;
}
}
return V_1 ;
}
unsigned F_112 ( struct V_2 * V_3 , T_2 V_17 ,
unsigned int V_35 , struct V_1 * * V_39 )
{
unsigned int V_38 ;
unsigned int V_20 ;
unsigned int V_84 ;
F_102 () ;
V_85:
V_84 = F_113 ( & V_3 -> V_4 ,
( void * * * ) V_39 , V_17 , V_35 ) ;
V_20 = 0 ;
for ( V_38 = 0 ; V_38 < V_84 ; V_38 ++ ) {
struct V_1 * V_1 ;
V_82:
V_1 = F_104 ( ( void * * ) V_39 [ V_38 ] ) ;
if ( F_105 ( ! V_1 ) )
continue;
if ( F_106 ( V_1 ) ) {
F_114 ( V_17 | V_38 ) ;
goto V_85;
}
if ( ! F_107 ( V_1 ) )
goto V_82;
if ( F_105 ( V_1 != * ( ( void * * ) V_39 [ V_38 ] ) ) ) {
F_21 ( V_1 ) ;
goto V_82;
}
V_39 [ V_20 ] = V_1 ;
V_20 ++ ;
}
if ( F_105 ( ! V_20 && V_84 ) )
goto V_85;
F_108 () ;
return V_20 ;
}
unsigned F_115 ( struct V_2 * V_3 , T_2 V_5 ,
unsigned int V_35 , struct V_1 * * V_39 )
{
unsigned int V_38 ;
unsigned int V_20 ;
unsigned int V_84 ;
F_102 () ;
V_85:
V_84 = F_113 ( & V_3 -> V_4 ,
( void * * * ) V_39 , V_5 , V_35 ) ;
V_20 = 0 ;
for ( V_38 = 0 ; V_38 < V_84 ; V_38 ++ ) {
struct V_1 * V_1 ;
V_82:
V_1 = F_104 ( ( void * * ) V_39 [ V_38 ] ) ;
if ( F_105 ( ! V_1 ) )
continue;
if ( F_106 ( V_1 ) )
goto V_85;
if ( ! F_107 ( V_1 ) )
goto V_82;
if ( F_105 ( V_1 != * ( ( void * * ) V_39 [ V_38 ] ) ) ) {
F_21 ( V_1 ) ;
goto V_82;
}
if ( V_1 -> V_3 == NULL || V_1 -> V_5 != V_5 ) {
F_21 ( V_1 ) ;
break;
}
V_39 [ V_20 ] = V_1 ;
V_20 ++ ;
V_5 ++ ;
}
F_108 () ;
return V_20 ;
}
unsigned F_116 ( struct V_2 * V_3 , T_2 * V_5 ,
int V_86 , unsigned int V_35 , struct V_1 * * V_39 )
{
unsigned int V_38 ;
unsigned int V_20 ;
unsigned int V_84 ;
F_102 () ;
V_85:
V_84 = F_117 ( & V_3 -> V_4 ,
( void * * * ) V_39 , * V_5 , V_35 , V_86 ) ;
V_20 = 0 ;
for ( V_38 = 0 ; V_38 < V_84 ; V_38 ++ ) {
struct V_1 * V_1 ;
V_82:
V_1 = F_104 ( ( void * * ) V_39 [ V_38 ] ) ;
if ( F_105 ( ! V_1 ) )
continue;
if ( F_106 ( V_1 ) )
goto V_85;
if ( ! F_107 ( V_1 ) )
goto V_82;
if ( F_105 ( V_1 != * ( ( void * * ) V_39 [ V_38 ] ) ) ) {
F_21 ( V_1 ) ;
goto V_82;
}
V_39 [ V_20 ] = V_1 ;
V_20 ++ ;
}
if ( F_105 ( ! V_20 && V_84 ) )
goto V_85;
F_108 () ;
if ( V_20 )
* V_5 = V_39 [ V_20 - 1 ] -> V_5 + 1 ;
return V_20 ;
}
struct V_1 *
F_118 ( struct V_2 * V_3 , T_2 V_5 )
{
struct V_1 * V_1 = F_101 ( V_3 , V_5 ) ;
if ( V_1 ) {
if ( F_119 ( V_1 ) )
return V_1 ;
F_21 ( V_1 ) ;
return NULL ;
}
V_1 = F_65 ( F_120 ( V_3 ) & ~ V_87 ) ;
if ( V_1 && F_58 ( V_1 , V_3 , V_5 , V_88 ) ) {
F_21 ( V_1 ) ;
V_1 = NULL ;
}
return V_1 ;
}
static void F_121 ( struct V_89 * V_90 ,
struct V_91 * V_92 )
{
V_92 -> V_93 /= 4 ;
}
static void F_122 ( struct V_89 * V_90 , T_1 * V_94 ,
T_6 * V_95 , T_7 V_96 )
{
struct V_2 * V_3 = V_90 -> V_97 ;
struct V_98 * V_98 = V_3 -> V_46 ;
struct V_91 * V_92 = & V_90 -> V_99 ;
T_2 V_5 ;
T_2 V_100 ;
T_2 V_101 ;
unsigned long V_57 ;
unsigned int V_102 ;
int error ;
V_5 = * V_94 >> V_32 ;
V_101 = V_92 -> V_103 >> V_32 ;
V_102 = V_92 -> V_103 & ( V_104 - 1 ) ;
V_100 = ( * V_94 + V_95 -> V_105 + V_104 - 1 ) >> V_32 ;
V_57 = * V_94 & ~ V_106 ;
for (; ; ) {
struct V_1 * V_1 ;
T_2 V_107 ;
T_1 V_108 ;
unsigned long V_109 , V_20 ;
F_40 () ;
V_110:
V_1 = F_101 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
F_123 ( V_3 ,
V_92 , V_90 ,
V_5 , V_100 - V_5 ) ;
V_1 = F_101 ( V_3 , V_5 ) ;
if ( F_105 ( V_1 == NULL ) )
goto V_111;
}
if ( F_124 ( V_1 ) ) {
F_125 ( V_3 ,
V_92 , V_90 , V_1 ,
V_5 , V_100 - V_5 ) ;
}
if ( ! F_2 ( V_1 ) ) {
if ( V_98 -> V_112 == V_32 ||
! V_3 -> V_12 -> V_113 )
goto V_114;
if ( ! F_119 ( V_1 ) )
goto V_114;
if ( ! V_1 -> V_3 )
goto V_115;
if ( ! V_3 -> V_12 -> V_113 ( V_1 ,
V_95 , V_57 ) )
goto V_115;
F_86 ( V_1 ) ;
}
V_116:
V_108 = F_43 ( V_98 ) ;
V_107 = ( V_108 - 1 ) >> V_32 ;
if ( F_105 ( ! V_108 || V_5 > V_107 ) ) {
F_21 ( V_1 ) ;
goto V_60;
}
V_109 = V_104 ;
if ( V_5 == V_107 ) {
V_109 = ( ( V_108 - 1 ) & ~ V_106 ) + 1 ;
if ( V_109 <= V_57 ) {
F_21 ( V_1 ) ;
goto V_60;
}
}
V_109 = V_109 - V_57 ;
if ( F_126 ( V_3 ) )
F_127 ( V_1 ) ;
if ( V_101 != V_5 || V_57 != V_102 )
F_128 ( V_1 ) ;
V_101 = V_5 ;
V_20 = V_96 ( V_95 , V_1 , V_57 , V_109 ) ;
V_57 += V_20 ;
V_5 += V_57 >> V_32 ;
V_57 &= ~ V_106 ;
V_102 = V_57 ;
F_21 ( V_1 ) ;
if ( V_20 == V_109 && V_95 -> V_105 )
continue;
goto V_60;
V_114:
error = F_129 ( V_1 ) ;
if ( F_105 ( error ) )
goto V_117;
V_115:
if ( ! V_1 -> V_3 ) {
F_86 ( V_1 ) ;
F_21 ( V_1 ) ;
continue;
}
if ( F_2 ( V_1 ) ) {
F_86 ( V_1 ) ;
goto V_116;
}
V_118:
F_130 ( V_1 ) ;
error = V_3 -> V_12 -> V_118 ( V_90 , V_1 ) ;
if ( F_105 ( error ) ) {
if ( error == V_119 ) {
F_21 ( V_1 ) ;
goto V_110;
}
goto V_117;
}
if ( ! F_2 ( V_1 ) ) {
error = F_129 ( V_1 ) ;
if ( F_105 ( error ) )
goto V_117;
if ( ! F_2 ( V_1 ) ) {
if ( V_1 -> V_3 == NULL ) {
F_86 ( V_1 ) ;
F_21 ( V_1 ) ;
goto V_110;
}
F_86 ( V_1 ) ;
F_121 ( V_90 , V_92 ) ;
error = - V_40 ;
goto V_117;
}
F_86 ( V_1 ) ;
}
goto V_116;
V_117:
V_95 -> error = error ;
F_21 ( V_1 ) ;
goto V_60;
V_111:
V_1 = F_131 ( V_3 ) ;
if ( ! V_1 ) {
V_95 -> error = - V_120 ;
goto V_60;
}
error = F_58 ( V_1 , V_3 ,
V_5 , V_121 ) ;
if ( error ) {
F_21 ( V_1 ) ;
if ( error == - V_83 )
goto V_110;
V_95 -> error = error ;
goto V_60;
}
goto V_118;
}
V_60:
V_92 -> V_103 = V_101 ;
V_92 -> V_103 <<= V_32 ;
V_92 -> V_103 |= V_102 ;
* V_94 = ( ( T_1 ) V_5 << V_32 ) + V_57 ;
F_132 ( V_90 ) ;
}
int F_133 ( T_6 * V_95 , struct V_1 * V_1 ,
unsigned long V_57 , unsigned long V_122 )
{
char * V_123 ;
unsigned long V_124 , V_105 = V_95 -> V_105 ;
if ( V_122 > V_105 )
V_122 = V_105 ;
if ( ! F_134 ( V_95 -> V_125 . V_126 , V_122 ) ) {
V_123 = F_135 ( V_1 , V_127 ) ;
V_124 = F_136 ( V_95 -> V_125 . V_126 ,
V_123 + V_57 , V_122 ) ;
F_137 ( V_123 , V_127 ) ;
if ( V_124 == 0 )
goto V_128;
}
V_123 = F_138 ( V_1 ) ;
V_124 = F_139 ( V_95 -> V_125 . V_126 , V_123 + V_57 , V_122 ) ;
F_140 ( V_1 ) ;
if ( V_124 ) {
V_122 -= V_124 ;
V_95 -> error = - V_129 ;
}
V_128:
V_95 -> V_105 = V_105 - V_122 ;
V_95 -> V_130 += V_122 ;
V_95 -> V_125 . V_126 += V_122 ;
return V_122 ;
}
int F_141 ( const struct V_131 * V_132 ,
unsigned long * V_133 , T_8 * V_105 , int V_134 )
{
unsigned long V_135 ;
T_8 V_136 = 0 ;
for ( V_135 = 0 ; V_135 < * V_133 ; V_135 ++ ) {
const struct V_131 * V_137 = & V_132 [ V_135 ] ;
V_136 += V_137 -> V_138 ;
if ( F_105 ( ( V_139 ) ( V_136 | V_137 -> V_138 ) < 0 ) )
return - V_140 ;
if ( F_142 ( V_134 , V_137 -> V_141 , V_137 -> V_138 ) )
continue;
if ( V_135 == 0 )
return - V_129 ;
* V_133 = V_135 ;
V_136 -= V_137 -> V_138 ;
break;
}
* V_105 = V_136 ;
return 0 ;
}
V_139
F_143 ( struct V_142 * V_143 , const struct V_131 * V_132 ,
unsigned long V_133 , T_1 V_144 )
{
struct V_89 * V_90 = V_143 -> V_145 ;
V_139 V_146 ;
unsigned long V_135 = 0 ;
T_8 V_105 ;
T_1 * V_94 = & V_143 -> V_147 ;
struct V_148 V_149 ;
V_105 = 0 ;
V_146 = F_141 ( V_132 , & V_133 , & V_105 , V_150 ) ;
if ( V_146 )
return V_146 ;
F_144 ( & V_149 ) ;
if ( V_90 -> V_151 & V_152 ) {
T_1 V_122 ;
struct V_2 * V_3 ;
struct V_98 * V_98 ;
V_3 = V_90 -> V_97 ;
V_98 = V_3 -> V_46 ;
if ( ! V_105 )
goto V_60;
V_122 = F_43 ( V_98 ) ;
if ( V_144 < V_122 ) {
V_146 = F_45 ( V_3 , V_144 ,
V_144 + F_145 ( V_132 , V_133 ) - 1 ) ;
if ( ! V_146 ) {
V_146 = V_3 -> V_12 -> V_153 ( V_154 , V_143 ,
V_132 , V_144 , V_133 ) ;
}
if ( V_146 > 0 ) {
* V_94 = V_144 + V_146 ;
V_105 -= V_146 ;
}
if ( V_146 < 0 || ! V_105 || * V_94 >= V_122 ) {
F_132 ( V_90 ) ;
goto V_60;
}
}
}
V_105 = V_146 ;
for ( V_135 = 0 ; V_135 < V_133 ; V_135 ++ ) {
T_6 V_95 ;
T_1 V_57 = 0 ;
if ( V_105 ) {
if ( V_105 > V_132 [ V_135 ] . V_138 ) {
V_105 -= V_132 [ V_135 ] . V_138 ;
continue;
}
V_57 = V_105 ;
V_105 = 0 ;
}
V_95 . V_130 = 0 ;
V_95 . V_125 . V_126 = V_132 [ V_135 ] . V_141 + V_57 ;
V_95 . V_105 = V_132 [ V_135 ] . V_138 - V_57 ;
if ( V_95 . V_105 == 0 )
continue;
V_95 . error = 0 ;
F_122 ( V_90 , V_94 , & V_95 , F_133 ) ;
V_146 += V_95 . V_130 ;
if ( V_95 . error ) {
V_146 = V_146 ? : V_95 . error ;
break;
}
if ( V_95 . V_105 > 0 )
break;
}
V_60:
F_146 ( & V_149 ) ;
return V_146 ;
}
static V_139
F_147 ( struct V_2 * V_3 , struct V_89 * V_90 ,
T_2 V_5 , unsigned long V_109 )
{
if ( ! V_3 || ! V_3 -> V_12 || ! V_3 -> V_12 -> V_118 )
return - V_140 ;
F_148 ( V_3 , V_90 , V_5 , V_109 ) ;
return 0 ;
}
T_9 (F_149)( int V_155 , T_1 V_57 , T_8 V_105 )
{
V_139 V_20 ;
struct V_89 * V_89 ;
V_20 = - V_156 ;
V_89 = F_150 ( V_155 ) ;
if ( V_89 ) {
if ( V_89 -> V_157 & V_158 ) {
struct V_2 * V_3 = V_89 -> V_97 ;
T_2 V_17 = V_57 >> V_32 ;
T_2 V_18 = ( V_57 + V_105 - 1 ) >> V_32 ;
unsigned long V_159 = V_18 - V_17 + 1 ;
V_20 = F_147 ( V_3 , V_89 , V_17 , V_159 ) ;
}
F_151 ( V_89 ) ;
}
return V_20 ;
}
T_10 long F_152 ( long V_155 , T_1 V_57 , long V_105 )
{
return F_153 ( ( int ) V_155 , V_57 , ( T_8 ) V_105 ) ;
}
static int F_154 ( struct V_89 * V_89 , T_2 V_57 )
{
struct V_2 * V_3 = V_89 -> V_97 ;
struct V_1 * V_1 ;
int V_20 ;
do {
V_1 = F_131 ( V_3 ) ;
if ( ! V_1 )
return - V_120 ;
V_20 = F_58 ( V_1 , V_3 , V_57 , V_121 ) ;
if ( V_20 == 0 )
V_20 = V_3 -> V_12 -> V_118 ( V_89 , V_1 ) ;
else if ( V_20 == - V_83 )
V_20 = 0 ;
F_21 ( V_1 ) ;
} while ( V_20 == V_119 );
return V_20 ;
}
static void F_155 ( struct V_160 * V_161 ,
struct V_91 * V_92 ,
struct V_89 * V_89 ,
T_2 V_57 )
{
unsigned long V_93 ;
struct V_2 * V_3 = V_89 -> V_97 ;
if ( F_156 ( V_161 ) )
return;
if ( ! V_92 -> V_93 )
return;
if ( F_157 ( V_161 ) ) {
F_123 ( V_3 , V_92 , V_89 , V_57 ,
V_92 -> V_93 ) ;
return;
}
if ( V_92 -> V_162 < V_163 * 10 )
V_92 -> V_162 ++ ;
if ( V_92 -> V_162 > V_163 )
return;
V_93 = F_158 ( V_92 -> V_93 ) ;
V_92 -> V_17 = F_159 ( long , 0 , V_57 - V_93 / 2 ) ;
V_92 -> V_122 = V_93 ;
V_92 -> V_164 = V_93 / 4 ;
F_160 ( V_92 , V_3 , V_89 ) ;
}
static void F_161 ( struct V_160 * V_161 ,
struct V_91 * V_92 ,
struct V_89 * V_89 ,
struct V_1 * V_1 ,
T_2 V_57 )
{
struct V_2 * V_3 = V_89 -> V_97 ;
if ( F_156 ( V_161 ) )
return;
if ( V_92 -> V_162 > 0 )
V_92 -> V_162 -- ;
if ( F_124 ( V_1 ) )
F_125 ( V_3 , V_92 , V_89 ,
V_1 , V_57 , V_92 -> V_93 ) ;
}
int F_162 ( struct V_160 * V_161 , struct V_165 * V_166 )
{
int error ;
struct V_89 * V_89 = V_161 -> V_167 ;
struct V_2 * V_3 = V_89 -> V_97 ;
struct V_91 * V_92 = & V_89 -> V_99 ;
struct V_98 * V_98 = V_3 -> V_46 ;
T_2 V_57 = V_166 -> V_168 ;
struct V_1 * V_1 ;
T_2 V_122 ;
int V_20 = 0 ;
V_122 = ( F_43 ( V_98 ) + V_104 - 1 ) >> V_32 ;
if ( V_57 >= V_122 )
return V_169 ;
V_1 = F_101 ( V_3 , V_57 ) ;
if ( F_57 ( V_1 ) ) {
F_161 ( V_161 , V_92 , V_89 , V_1 , V_57 ) ;
} else {
F_155 ( V_161 , V_92 , V_89 , V_57 ) ;
F_163 ( V_170 ) ;
F_164 ( V_161 -> V_171 , V_170 ) ;
V_20 = V_172 ;
V_173:
V_1 = F_101 ( V_3 , V_57 ) ;
if ( ! V_1 )
goto V_111;
}
if ( ! F_165 ( V_1 , V_161 -> V_171 , V_166 -> V_42 ) ) {
F_21 ( V_1 ) ;
return V_20 | V_174 ;
}
if ( F_105 ( V_1 -> V_3 != V_3 ) ) {
F_86 ( V_1 ) ;
F_166 ( V_1 ) ;
goto V_173;
}
F_47 ( V_1 -> V_5 != V_57 ) ;
if ( F_105 ( ! F_2 ( V_1 ) ) )
goto V_175;
V_122 = ( F_43 ( V_98 ) + V_104 - 1 ) >> V_32 ;
if ( F_105 ( V_57 >= V_122 ) ) {
F_86 ( V_1 ) ;
F_21 ( V_1 ) ;
return V_169 ;
}
V_166 -> V_1 = V_1 ;
return V_20 | V_176 ;
V_111:
error = F_154 ( V_89 , V_57 ) ;
if ( error >= 0 )
goto V_173;
if ( error == - V_120 )
return V_177 ;
return V_169 ;
V_175:
F_130 ( V_1 ) ;
error = V_3 -> V_12 -> V_118 ( V_89 , V_1 ) ;
if ( ! error ) {
F_100 ( V_1 ) ;
if ( ! F_2 ( V_1 ) )
error = - V_40 ;
}
F_21 ( V_1 ) ;
if ( ! error || error == V_119 )
goto V_173;
F_121 ( V_89 , V_92 ) ;
return V_169 ;
}
int F_167 ( struct V_89 * V_89 , struct V_160 * V_161 )
{
struct V_2 * V_3 = V_89 -> V_97 ;
if ( ! V_3 -> V_12 -> V_118 )
return - V_178 ;
F_132 ( V_89 ) ;
V_161 -> V_179 = & V_180 ;
V_161 -> V_181 |= V_182 ;
return 0 ;
}
int F_168 ( struct V_89 * V_89 , struct V_160 * V_161 )
{
if ( ( V_161 -> V_181 & V_183 ) && ( V_161 -> V_181 & V_184 ) )
return - V_140 ;
return F_167 ( V_89 , V_161 ) ;
}
int F_167 ( struct V_89 * V_89 , struct V_160 * V_161 )
{
return - V_185 ;
}
int F_168 ( struct V_89 * V_89 , struct V_160 * V_161 )
{
return - V_185 ;
}
static struct V_1 * F_169 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_170)( void * , struct V_1 * ) ,
void * V_186 ,
T_3 V_61 )
{
struct V_1 * V_1 ;
int V_47 ;
V_82:
V_1 = F_101 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
V_1 = F_65 ( V_61 | V_187 ) ;
if ( ! V_1 )
return F_171 ( - V_120 ) ;
V_47 = F_58 ( V_1 , V_3 , V_5 , V_121 ) ;
if ( F_105 ( V_47 ) ) {
F_21 ( V_1 ) ;
if ( V_47 == - V_83 )
goto V_82;
return F_171 ( V_47 ) ;
}
V_47 = F_170 ( V_186 , V_1 ) ;
if ( V_47 < 0 ) {
F_21 ( V_1 ) ;
V_1 = F_171 ( V_47 ) ;
}
}
return V_1 ;
}
static struct V_1 * F_172 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_170)( void * , struct V_1 * ) ,
void * V_186 ,
T_3 V_61 )
{
struct V_1 * V_1 ;
int V_47 ;
V_188:
V_1 = F_169 ( V_3 , V_5 , F_170 , V_186 , V_61 ) ;
if ( F_173 ( V_1 ) )
return V_1 ;
if ( F_2 ( V_1 ) )
goto V_60;
F_110 ( V_1 ) ;
if ( ! V_1 -> V_3 ) {
F_86 ( V_1 ) ;
F_21 ( V_1 ) ;
goto V_188;
}
if ( F_2 ( V_1 ) ) {
F_86 ( V_1 ) ;
goto V_60;
}
V_47 = F_170 ( V_186 , V_1 ) ;
if ( V_47 < 0 ) {
F_21 ( V_1 ) ;
return F_171 ( V_47 ) ;
}
V_60:
F_128 ( V_1 ) ;
return V_1 ;
}
struct V_1 * F_174 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_170)( void * , struct V_1 * ) ,
void * V_186 )
{
return F_172 ( V_3 , V_5 , F_170 , V_186 , F_120 ( V_3 ) ) ;
}
static struct V_1 * F_175 ( struct V_1 * V_1 )
{
if ( ! F_173 ( V_1 ) ) {
F_100 ( V_1 ) ;
if ( ! F_2 ( V_1 ) ) {
F_21 ( V_1 ) ;
V_1 = F_171 ( - V_40 ) ;
}
}
return V_1 ;
}
struct V_1 * F_176 ( struct V_2 * V_3 ,
T_2 V_5 ,
T_3 V_61 )
{
T_11 * F_170 = ( T_11 * ) V_3 -> V_12 -> V_118 ;
return F_175 ( F_172 ( V_3 , V_5 , F_170 , NULL , V_61 ) ) ;
}
struct V_1 * F_177 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_170)( void * , struct V_1 * ) ,
void * V_186 )
{
return F_175 ( F_174 ( V_3 , V_5 , F_170 , V_186 ) ) ;
}
int F_178 ( struct V_189 * V_189 )
{
T_12 V_190 = V_189 -> V_191 -> V_192 ;
int V_193 = 0 ;
if ( F_105 ( V_190 & V_194 ) )
V_193 = V_195 ;
if ( F_105 ( ( V_190 & V_196 ) && ( V_190 & V_197 ) ) )
V_193 |= V_198 ;
if ( F_105 ( V_193 && ! F_179 ( V_199 ) && F_180 ( V_190 ) ) )
return V_193 ;
return 0 ;
}
static int F_181 ( struct V_189 * V_189 , int V_193 )
{
struct V_200 V_201 ;
V_201 . V_202 = V_203 | V_193 ;
return F_182 ( V_189 , & V_201 ) ;
}
int F_183 ( struct V_89 * V_89 )
{
struct V_189 * V_189 = V_89 -> V_204 . V_189 ;
struct V_98 * V_98 = V_189 -> V_191 ;
int V_205 ;
int V_206 ;
int error = 0 ;
if ( F_184 ( V_98 ) )
return 0 ;
V_205 = F_178 ( V_189 ) ;
V_206 = F_185 ( V_189 ) ;
if ( V_206 < 0 )
return V_206 ;
if ( V_206 )
error = F_186 ( V_189 ) ;
if ( ! error && V_205 )
error = F_181 ( V_189 , V_205 ) ;
if ( ! error && ( V_98 -> V_207 -> V_208 & V_209 ) )
V_98 -> V_210 |= V_211 ;
return error ;
}
static T_8 F_187 ( char * V_212 ,
const struct V_131 * V_132 , T_8 V_213 , T_8 V_214 )
{
T_8 V_215 = 0 , V_124 = 0 ;
while ( V_214 ) {
char T_13 * V_126 = V_132 -> V_141 + V_213 ;
int V_216 = F_36 ( V_214 , V_132 -> V_138 - V_213 ) ;
V_213 = 0 ;
V_124 = F_188 ( V_212 , V_126 , V_216 ) ;
V_215 += V_216 ;
V_214 -= V_216 ;
V_212 += V_216 ;
V_132 ++ ;
if ( F_105 ( V_124 ) )
break;
}
return V_215 - V_124 ;
}
T_8 F_189 ( struct V_1 * V_1 ,
struct V_217 * V_38 , unsigned long V_57 , T_8 V_214 )
{
char * V_123 ;
T_8 V_215 ;
F_9 ( ! F_190 () ) ;
V_123 = F_135 ( V_1 , V_127 ) ;
if ( F_57 ( V_38 -> V_133 == 1 ) ) {
int V_124 ;
char T_13 * V_126 = V_38 -> V_132 -> V_141 + V_38 -> V_218 ;
V_124 = F_188 ( V_123 + V_57 , V_126 , V_214 ) ;
V_215 = V_214 - V_124 ;
} else {
V_215 = F_187 ( V_123 + V_57 ,
V_38 -> V_132 , V_38 -> V_218 , V_214 ) ;
}
F_137 ( V_123 , V_127 ) ;
return V_215 ;
}
T_8 F_191 ( struct V_1 * V_1 ,
struct V_217 * V_38 , unsigned long V_57 , T_8 V_214 )
{
char * V_123 ;
T_8 V_215 ;
V_123 = F_138 ( V_1 ) ;
if ( F_57 ( V_38 -> V_133 == 1 ) ) {
int V_124 ;
char T_13 * V_126 = V_38 -> V_132 -> V_141 + V_38 -> V_218 ;
V_124 = F_192 ( V_123 + V_57 , V_126 , V_214 ) ;
V_215 = V_214 - V_124 ;
} else {
V_215 = F_187 ( V_123 + V_57 ,
V_38 -> V_132 , V_38 -> V_218 , V_214 ) ;
}
F_140 ( V_1 ) ;
return V_215 ;
}
void F_193 ( struct V_217 * V_38 , T_8 V_214 )
{
F_9 ( V_38 -> V_105 < V_214 ) ;
if ( F_57 ( V_38 -> V_133 == 1 ) ) {
V_38 -> V_218 += V_214 ;
V_38 -> V_105 -= V_214 ;
} else {
const struct V_131 * V_132 = V_38 -> V_132 ;
T_8 V_213 = V_38 -> V_218 ;
while ( V_214 || F_105 ( V_38 -> V_105 && ! V_132 -> V_138 ) ) {
int V_216 ;
V_216 = F_36 ( V_214 , V_132 -> V_138 - V_213 ) ;
F_9 ( ! V_38 -> V_105 || V_38 -> V_105 < V_216 ) ;
V_38 -> V_105 -= V_216 ;
V_214 -= V_216 ;
V_213 += V_216 ;
if ( V_132 -> V_138 == V_213 ) {
V_132 ++ ;
V_213 = 0 ;
}
}
V_38 -> V_132 = V_132 ;
V_38 -> V_218 = V_213 ;
}
}
int F_194 ( struct V_217 * V_38 , T_8 V_214 )
{
char T_13 * V_126 = V_38 -> V_132 -> V_141 + V_38 -> V_218 ;
V_214 = F_36 ( V_214 , V_38 -> V_132 -> V_138 - V_38 -> V_218 ) ;
return F_195 ( V_126 , V_214 ) ;
}
T_8 F_196 ( struct V_217 * V_38 )
{
const struct V_131 * V_132 = V_38 -> V_132 ;
if ( V_38 -> V_133 == 1 )
return V_38 -> V_105 ;
else
return F_36 ( V_38 -> V_105 , V_132 -> V_138 - V_38 -> V_218 ) ;
}
inline int F_197 ( struct V_89 * V_89 , T_1 * V_144 , T_8 * V_105 , int V_219 )
{
struct V_98 * V_98 = V_89 -> V_97 -> V_46 ;
unsigned long V_220 = F_198 ( V_221 ) ;
if ( F_105 ( * V_144 < 0 ) )
return - V_140 ;
if ( ! V_219 ) {
if ( V_89 -> V_151 & V_222 )
* V_144 = F_43 ( V_98 ) ;
if ( V_220 != V_223 ) {
if ( * V_144 >= V_220 ) {
F_199 ( V_224 , V_15 , 0 ) ;
return - V_225 ;
}
if ( * V_105 > V_220 - ( F_200 ( V_220 ) ) * V_144 ) {
* V_105 = V_220 - ( F_200 ( V_220 ) ) * V_144 ;
}
}
}
if ( F_105 ( * V_144 + * V_105 > V_226 &&
! ( V_89 -> V_151 & V_227 ) ) ) {
if ( * V_144 >= V_226 ) {
return - V_225 ;
}
if ( * V_105 > V_226 - ( unsigned long ) * V_144 ) {
* V_105 = V_226 - ( unsigned long ) * V_144 ;
}
}
if ( F_57 ( ! V_219 ) ) {
if ( F_105 ( * V_144 >= V_98 -> V_207 -> V_228 ) ) {
if ( * V_105 || * V_144 > V_98 -> V_207 -> V_228 ) {
return - V_225 ;
}
}
if ( F_105 ( * V_144 + * V_105 > V_98 -> V_207 -> V_228 ) )
* V_105 = V_98 -> V_207 -> V_228 - * V_144 ;
} else {
#ifdef F_201
T_1 V_108 ;
if ( F_202 ( F_203 ( V_98 ) ) )
return - V_229 ;
V_108 = F_43 ( V_98 ) ;
if ( * V_144 >= V_108 ) {
if ( * V_105 || * V_144 > V_108 )
return - V_43 ;
}
if ( * V_144 + * V_105 > V_108 )
* V_105 = V_108 - * V_144 ;
#else
return - V_229 ;
#endif
}
return 0 ;
}
int F_204 ( struct V_89 * V_89 , struct V_2 * V_3 ,
T_1 V_144 , unsigned V_159 , unsigned V_42 ,
struct V_1 * * V_81 , void * * V_230 )
{
const struct V_231 * V_232 = V_3 -> V_12 ;
return V_232 -> V_233 ( V_89 , V_3 , V_144 , V_159 , V_42 ,
V_81 , V_230 ) ;
}
int F_205 ( struct V_89 * V_89 , struct V_2 * V_3 ,
T_1 V_144 , unsigned V_159 , unsigned V_215 ,
struct V_1 * V_1 , void * V_230 )
{
const struct V_231 * V_232 = V_3 -> V_12 ;
F_128 ( V_1 ) ;
return V_232 -> V_234 ( V_89 , V_3 , V_144 , V_159 , V_215 , V_1 , V_230 ) ;
}
V_139
F_206 ( struct V_142 * V_143 , const struct V_131 * V_132 ,
unsigned long * V_133 , T_1 V_144 , T_1 * V_94 ,
T_8 V_105 , T_8 V_235 )
{
struct V_89 * V_89 = V_143 -> V_145 ;
struct V_2 * V_3 = V_89 -> V_97 ;
struct V_98 * V_98 = V_3 -> V_46 ;
V_139 V_130 ;
T_8 V_236 ;
T_2 V_18 ;
if ( V_105 != V_235 )
* V_133 = F_207 ( (struct V_131 * ) V_132 , * V_133 , V_105 ) ;
V_236 = F_145 ( V_132 , * V_133 ) ;
V_18 = ( V_144 + V_236 - 1 ) >> V_32 ;
V_130 = F_45 ( V_3 , V_144 , V_144 + V_236 - 1 ) ;
if ( V_130 )
goto V_60;
if ( V_3 -> V_6 ) {
V_130 = F_208 ( V_3 ,
V_144 >> V_32 , V_18 ) ;
if ( V_130 ) {
if ( V_130 == - V_237 )
return 0 ;
goto V_60;
}
}
V_130 = V_3 -> V_12 -> V_153 ( V_238 , V_143 , V_132 , V_144 , * V_133 ) ;
if ( V_3 -> V_6 ) {
F_208 ( V_3 ,
V_144 >> V_32 , V_18 ) ;
}
if ( V_130 > 0 ) {
V_144 += V_130 ;
if ( V_144 > F_43 ( V_98 ) && ! F_209 ( V_98 -> V_192 ) ) {
F_210 ( V_98 , V_144 ) ;
F_211 ( V_98 ) ;
}
* V_94 = V_144 ;
}
V_60:
return V_130 ;
}
struct V_1 * F_212 ( struct V_2 * V_3 ,
T_2 V_5 , unsigned V_42 )
{
int V_239 ;
struct V_1 * V_1 ;
T_3 V_240 = 0 ;
if ( V_42 & V_241 )
V_240 = V_87 ;
V_82:
V_1 = F_109 ( V_3 , V_5 ) ;
if ( V_1 )
goto V_242;
V_1 = F_65 ( F_120 ( V_3 ) & ~ V_240 ) ;
if ( ! V_1 )
return NULL ;
V_239 = F_58 ( V_1 , V_3 , V_5 ,
V_121 & ~ V_240 ) ;
if ( F_105 ( V_239 ) ) {
F_21 ( V_1 ) ;
if ( V_239 == - V_83 )
goto V_82;
return NULL ;
}
V_242:
F_37 ( V_1 ) ;
return V_1 ;
}
static V_139 F_213 ( struct V_89 * V_89 ,
struct V_217 * V_38 , T_1 V_144 )
{
struct V_2 * V_3 = V_89 -> V_97 ;
const struct V_231 * V_12 = V_3 -> V_12 ;
long V_239 = 0 ;
V_139 V_130 = 0 ;
unsigned int V_42 = 0 ;
if ( F_214 ( F_215 () , V_243 ) )
V_42 |= V_244 ;
do {
struct V_1 * V_1 ;
unsigned long V_57 ;
unsigned long V_214 ;
T_8 V_215 ;
void * V_230 ;
V_57 = ( V_144 & ( V_104 - 1 ) ) ;
V_214 = F_216 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_count(i)) ;
V_245:
if ( F_105 ( F_194 ( V_38 , V_214 ) ) ) {
V_239 = - V_129 ;
break;
}
V_239 = V_12 -> V_233 ( V_89 , V_3 , V_144 , V_214 , V_42 ,
& V_1 , & V_230 ) ;
if ( F_105 ( V_239 ) )
break;
if ( F_126 ( V_3 ) )
F_127 ( V_1 ) ;
F_217 () ;
V_215 = F_189 ( V_1 , V_38 , V_57 , V_214 ) ;
F_218 () ;
F_127 ( V_1 ) ;
F_128 ( V_1 ) ;
V_239 = V_12 -> V_234 ( V_89 , V_3 , V_144 , V_214 , V_215 ,
V_1 , V_230 ) ;
if ( F_105 ( V_239 < 0 ) )
break;
V_215 = V_239 ;
F_40 () ;
F_193 ( V_38 , V_215 ) ;
if ( F_105 ( V_215 == 0 ) ) {
V_214 = F_216 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_245;
}
V_144 += V_215 ;
V_130 += V_215 ;
F_219 ( V_3 ) ;
} while ( F_220 ( V_38 ) );
return V_130 ? V_130 : V_239 ;
}
V_139
F_221 ( struct V_142 * V_143 , const struct V_131 * V_132 ,
unsigned long V_133 , T_1 V_144 , T_1 * V_94 ,
T_8 V_105 , V_139 V_130 )
{
struct V_89 * V_89 = V_143 -> V_145 ;
V_139 V_239 ;
struct V_217 V_38 ;
F_222 ( & V_38 , V_132 , V_133 , V_105 , V_130 ) ;
V_239 = F_213 ( V_89 , & V_38 , V_144 ) ;
if ( F_57 ( V_239 >= 0 ) ) {
V_130 += V_239 ;
* V_94 = V_144 + V_239 ;
}
return V_130 ? V_130 : V_239 ;
}
V_139 F_223 ( struct V_142 * V_143 , const struct V_131 * V_132 ,
unsigned long V_133 , T_1 * V_94 )
{
struct V_89 * V_89 = V_143 -> V_145 ;
struct V_2 * V_3 = V_89 -> V_97 ;
T_8 V_235 ;
T_8 V_105 ;
struct V_98 * V_98 = V_3 -> V_46 ;
T_1 V_144 ;
V_139 V_130 ;
V_139 V_47 ;
V_235 = 0 ;
V_47 = F_141 ( V_132 , & V_133 , & V_235 , V_246 ) ;
if ( V_47 )
return V_47 ;
V_105 = V_235 ;
V_144 = * V_94 ;
F_224 ( V_98 -> V_207 , V_247 ) ;
V_15 -> V_10 = V_3 -> V_10 ;
V_130 = 0 ;
V_47 = F_197 ( V_89 , & V_144 , & V_105 , F_209 ( V_98 -> V_192 ) ) ;
if ( V_47 )
goto V_60;
if ( V_105 == 0 )
goto V_60;
V_47 = F_183 ( V_89 ) ;
if ( V_47 )
goto V_60;
F_225 ( V_89 ) ;
if ( F_105 ( V_89 -> V_151 & V_152 ) ) {
T_1 V_248 ;
V_139 V_249 ;
V_130 = F_206 ( V_143 , V_132 , & V_133 , V_144 ,
V_94 , V_105 , V_235 ) ;
if ( V_130 < 0 || V_130 == V_105 )
goto V_60;
V_144 += V_130 ;
V_105 -= V_130 ;
V_249 = F_221 ( V_143 , V_132 ,
V_133 , V_144 , V_94 , V_105 ,
V_130 ) ;
if ( V_249 < 0 ) {
V_47 = V_249 ;
goto V_60;
}
V_248 = V_144 + V_249 - V_130 - 1 ;
V_47 = F_45 ( V_89 -> V_97 , V_144 , V_248 ) ;
if ( V_47 == 0 ) {
V_130 = V_249 ;
F_226 ( V_3 ,
V_144 >> V_32 ,
V_248 >> V_32 ) ;
} else {
}
} else {
V_130 = F_221 ( V_143 , V_132 , V_133 ,
V_144 , V_94 , V_105 , V_130 ) ;
}
V_60:
V_15 -> V_10 = NULL ;
return V_130 ? V_130 : V_47 ;
}
V_139 F_227 ( struct V_142 * V_143 , const struct V_131 * V_132 ,
unsigned long V_133 , T_1 V_144 )
{
struct V_89 * V_89 = V_143 -> V_145 ;
struct V_98 * V_98 = V_89 -> V_97 -> V_46 ;
struct V_148 V_149 ;
V_139 V_20 ;
F_9 ( V_143 -> V_147 != V_144 ) ;
F_228 ( & V_98 -> V_250 ) ;
F_144 ( & V_149 ) ;
V_20 = F_223 ( V_143 , V_132 , V_133 , & V_143 -> V_147 ) ;
F_229 ( & V_98 -> V_250 ) ;
if ( V_20 > 0 || V_20 == - V_251 ) {
V_139 V_47 ;
V_47 = F_230 ( V_89 , V_144 , V_20 ) ;
if ( V_47 < 0 && V_20 > 0 )
V_20 = V_47 ;
}
F_146 ( & V_149 ) ;
return V_20 ;
}
int F_231 ( struct V_1 * V_1 , T_3 V_53 )
{
struct V_2 * const V_3 = V_1 -> V_3 ;
F_9 ( ! F_17 ( V_1 ) ) ;
if ( F_232 ( V_1 ) )
return 0 ;
if ( V_3 && V_3 -> V_12 -> V_252 )
return V_3 -> V_12 -> V_252 ( V_1 , V_53 ) ;
return F_233 ( V_1 ) ;
}
