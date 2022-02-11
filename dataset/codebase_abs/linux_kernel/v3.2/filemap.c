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
F_47 ( F_8 ( V_1 ) ) ;
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
V_20 = F_59 ( V_1 , V_3 , V_57 , V_53 ) ;
if ( V_20 == 0 )
F_60 ( V_1 ) ;
return V_20 ;
}
struct V_1 * F_61 ( T_3 V_61 )
{
int V_62 ;
struct V_1 * V_1 ;
if ( F_62 () ) {
F_63 () ;
V_62 = F_64 () ;
V_1 = F_65 ( V_62 , V_61 , 0 ) ;
F_66 () ;
return V_1 ;
}
return F_67 ( V_61 , 0 ) ;
}
static T_4 * F_68 ( struct V_1 * V_1 )
{
const struct V_63 * V_63 = F_69 ( V_1 ) ;
return & V_63 -> V_64 [ F_70 ( V_1 , V_63 -> V_65 ) ] ;
}
static inline void F_71 ( struct V_1 * V_1 , int V_66 )
{
F_72 ( F_68 ( V_1 ) , & V_1 -> V_42 , V_66 ) ;
}
void F_73 ( struct V_1 * V_1 , int V_67 )
{
F_74 ( V_68 , & V_1 -> V_42 , V_67 ) ;
if ( F_75 ( V_67 , & V_1 -> V_42 ) )
F_76 ( F_68 ( V_1 ) , & V_68 , F_22 ,
V_69 ) ;
}
int F_77 ( struct V_1 * V_1 , int V_67 )
{
F_74 ( V_68 , & V_1 -> V_42 , V_67 ) ;
if ( ! F_75 ( V_67 , & V_1 -> V_42 ) )
return 0 ;
return F_76 ( F_68 ( V_1 ) , & V_68 ,
F_24 , V_70 ) ;
}
void F_78 ( struct V_1 * V_1 , T_5 * V_71 )
{
T_4 * V_72 = F_68 ( V_1 ) ;
unsigned long V_42 ;
F_79 ( & V_72 -> V_73 , V_42 ) ;
F_80 ( V_72 , V_71 ) ;
F_81 ( & V_72 -> V_73 , V_42 ) ;
}
void F_82 ( struct V_1 * V_1 )
{
F_47 ( ! F_17 ( V_1 ) ) ;
F_83 ( V_74 , & V_1 -> V_42 ) ;
F_84 () ;
F_71 ( V_1 , V_74 ) ;
}
void F_85 ( struct V_1 * V_1 )
{
if ( F_86 ( V_1 ) )
F_87 ( V_1 ) ;
if ( ! F_88 ( V_1 ) )
F_89 () ;
F_84 () ;
F_71 ( V_1 , V_75 ) ;
}
void F_90 ( struct V_1 * V_1 )
{
F_74 ( V_68 , & V_1 -> V_42 , V_74 ) ;
F_91 ( F_68 ( V_1 ) , & V_68 , F_22 ,
V_69 ) ;
}
int F_92 ( struct V_1 * V_1 )
{
F_74 ( V_68 , & V_1 -> V_42 , V_74 ) ;
return F_91 ( F_68 ( V_1 ) , & V_68 ,
F_24 , V_70 ) ;
}
int F_93 ( struct V_1 * V_1 , struct V_76 * V_58 ,
unsigned int V_42 )
{
if ( V_42 & V_77 ) {
if ( V_42 & V_78 )
return 0 ;
F_94 ( & V_58 -> V_79 ) ;
if ( V_42 & V_80 )
F_95 ( V_1 ) ;
else
F_96 ( V_1 ) ;
return 0 ;
} else {
if ( V_42 & V_80 ) {
int V_20 ;
V_20 = F_92 ( V_1 ) ;
if ( V_20 ) {
F_94 ( & V_58 -> V_79 ) ;
return 0 ;
}
} else
F_90 ( V_1 ) ;
return 1 ;
}
}
struct V_1 * F_97 ( struct V_2 * V_3 , T_2 V_57 )
{
void * * V_81 ;
struct V_1 * V_1 ;
F_98 () ;
V_82:
V_1 = NULL ;
V_81 = F_99 ( & V_3 -> V_4 , V_57 ) ;
if ( V_81 ) {
V_1 = F_100 ( V_81 ) ;
if ( F_101 ( ! V_1 ) )
goto V_60;
if ( F_102 ( V_1 ) ) {
if ( F_103 ( V_1 ) )
goto V_82;
goto V_60;
}
if ( ! F_104 ( V_1 ) )
goto V_82;
if ( F_101 ( V_1 != * V_81 ) ) {
F_21 ( V_1 ) ;
goto V_82;
}
}
V_60:
F_105 () ;
return V_1 ;
}
struct V_1 * F_106 ( struct V_2 * V_3 , T_2 V_57 )
{
struct V_1 * V_1 ;
V_82:
V_1 = F_97 ( V_3 , V_57 ) ;
if ( V_1 && ! F_102 ( V_1 ) ) {
F_107 ( V_1 ) ;
if ( F_101 ( V_1 -> V_3 != V_3 ) ) {
F_82 ( V_1 ) ;
F_21 ( V_1 ) ;
goto V_82;
}
F_47 ( V_1 -> V_5 != V_57 ) ;
}
return V_1 ;
}
struct V_1 * F_108 ( struct V_2 * V_3 ,
T_2 V_5 , T_3 V_53 )
{
struct V_1 * V_1 ;
int V_47 ;
V_82:
V_1 = F_106 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
V_1 = F_61 ( V_53 ) ;
if ( ! V_1 )
return NULL ;
V_47 = F_58 ( V_1 , V_3 , V_5 ,
( V_53 & V_59 ) ) ;
if ( F_101 ( V_47 ) ) {
F_21 ( V_1 ) ;
V_1 = NULL ;
if ( V_47 == - V_83 )
goto V_82;
}
}
return V_1 ;
}
unsigned F_109 ( struct V_2 * V_3 , T_2 V_17 ,
unsigned int V_35 , struct V_1 * * V_39 )
{
unsigned int V_38 ;
unsigned int V_20 ;
unsigned int V_84 , V_85 ;
F_98 () ;
V_86:
V_84 = F_110 ( & V_3 -> V_4 ,
( void * * * ) V_39 , NULL , V_17 , V_35 ) ;
V_20 = 0 ;
V_85 = 0 ;
for ( V_38 = 0 ; V_38 < V_84 ; V_38 ++ ) {
struct V_1 * V_1 ;
V_82:
V_1 = F_100 ( ( void * * ) V_39 [ V_38 ] ) ;
if ( F_101 ( ! V_1 ) )
continue;
if ( F_102 ( V_1 ) ) {
if ( F_103 ( V_1 ) ) {
F_111 ( V_17 | V_38 ) ;
goto V_86;
}
V_85 ++ ;
continue;
}
if ( ! F_104 ( V_1 ) )
goto V_82;
if ( F_101 ( V_1 != * ( ( void * * ) V_39 [ V_38 ] ) ) ) {
F_21 ( V_1 ) ;
goto V_82;
}
V_39 [ V_20 ] = V_1 ;
V_20 ++ ;
}
if ( F_101 ( ! V_20 && V_84 > V_85 ) )
goto V_86;
F_105 () ;
return V_20 ;
}
unsigned F_112 ( struct V_2 * V_3 , T_2 V_5 ,
unsigned int V_35 , struct V_1 * * V_39 )
{
unsigned int V_38 ;
unsigned int V_20 ;
unsigned int V_84 ;
F_98 () ;
V_86:
V_84 = F_110 ( & V_3 -> V_4 ,
( void * * * ) V_39 , NULL , V_5 , V_35 ) ;
V_20 = 0 ;
for ( V_38 = 0 ; V_38 < V_84 ; V_38 ++ ) {
struct V_1 * V_1 ;
V_82:
V_1 = F_100 ( ( void * * ) V_39 [ V_38 ] ) ;
if ( F_101 ( ! V_1 ) )
continue;
if ( F_102 ( V_1 ) ) {
if ( F_103 ( V_1 ) ) {
goto V_86;
}
break;
}
if ( ! F_104 ( V_1 ) )
goto V_82;
if ( F_101 ( V_1 != * ( ( void * * ) V_39 [ V_38 ] ) ) ) {
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
F_105 () ;
return V_20 ;
}
unsigned F_113 ( struct V_2 * V_3 , T_2 * V_5 ,
int V_87 , unsigned int V_35 , struct V_1 * * V_39 )
{
unsigned int V_38 ;
unsigned int V_20 ;
unsigned int V_84 ;
F_98 () ;
V_86:
V_84 = F_114 ( & V_3 -> V_4 ,
( void * * * ) V_39 , * V_5 , V_35 , V_87 ) ;
V_20 = 0 ;
for ( V_38 = 0 ; V_38 < V_84 ; V_38 ++ ) {
struct V_1 * V_1 ;
V_82:
V_1 = F_100 ( ( void * * ) V_39 [ V_38 ] ) ;
if ( F_101 ( ! V_1 ) )
continue;
if ( F_102 ( V_1 ) ) {
if ( F_103 ( V_1 ) ) {
goto V_86;
}
F_89 () ;
}
if ( ! F_104 ( V_1 ) )
goto V_82;
if ( F_101 ( V_1 != * ( ( void * * ) V_39 [ V_38 ] ) ) ) {
F_21 ( V_1 ) ;
goto V_82;
}
V_39 [ V_20 ] = V_1 ;
V_20 ++ ;
}
if ( F_101 ( ! V_20 && V_84 ) )
goto V_86;
F_105 () ;
if ( V_20 )
* V_5 = V_39 [ V_20 - 1 ] -> V_5 + 1 ;
return V_20 ;
}
struct V_1 *
F_115 ( struct V_2 * V_3 , T_2 V_5 )
{
struct V_1 * V_1 = F_97 ( V_3 , V_5 ) ;
if ( V_1 ) {
if ( F_116 ( V_1 ) )
return V_1 ;
F_21 ( V_1 ) ;
return NULL ;
}
V_1 = F_61 ( F_117 ( V_3 ) & ~ V_88 ) ;
if ( V_1 && F_58 ( V_1 , V_3 , V_5 , V_89 ) ) {
F_21 ( V_1 ) ;
V_1 = NULL ;
}
return V_1 ;
}
static void F_118 ( struct V_90 * V_91 ,
struct V_92 * V_93 )
{
V_93 -> V_94 /= 4 ;
}
static void F_119 ( struct V_90 * V_91 , T_1 * V_95 ,
T_6 * V_96 , T_7 V_97 )
{
struct V_2 * V_3 = V_91 -> V_98 ;
struct V_99 * V_99 = V_3 -> V_46 ;
struct V_92 * V_93 = & V_91 -> V_100 ;
T_2 V_5 ;
T_2 V_101 ;
T_2 V_102 ;
unsigned long V_57 ;
unsigned int V_103 ;
int error ;
V_5 = * V_95 >> V_32 ;
V_102 = V_93 -> V_104 >> V_32 ;
V_103 = V_93 -> V_104 & ( V_105 - 1 ) ;
V_101 = ( * V_95 + V_96 -> V_106 + V_105 - 1 ) >> V_32 ;
V_57 = * V_95 & ~ V_107 ;
for (; ; ) {
struct V_1 * V_1 ;
T_2 V_108 ;
T_1 V_109 ;
unsigned long V_110 , V_20 ;
F_40 () ;
V_111:
V_1 = F_97 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
F_120 ( V_3 ,
V_93 , V_91 ,
V_5 , V_101 - V_5 ) ;
V_1 = F_97 ( V_3 , V_5 ) ;
if ( F_101 ( V_1 == NULL ) )
goto V_112;
}
if ( F_121 ( V_1 ) ) {
F_122 ( V_3 ,
V_93 , V_91 , V_1 ,
V_5 , V_101 - V_5 ) ;
}
if ( ! F_2 ( V_1 ) ) {
if ( V_99 -> V_113 == V_32 ||
! V_3 -> V_12 -> V_114 )
goto V_115;
if ( ! F_116 ( V_1 ) )
goto V_115;
if ( ! V_1 -> V_3 )
goto V_116;
if ( ! V_3 -> V_12 -> V_114 ( V_1 ,
V_96 , V_57 ) )
goto V_116;
F_82 ( V_1 ) ;
}
V_117:
V_109 = F_43 ( V_99 ) ;
V_108 = ( V_109 - 1 ) >> V_32 ;
if ( F_101 ( ! V_109 || V_5 > V_108 ) ) {
F_21 ( V_1 ) ;
goto V_60;
}
V_110 = V_105 ;
if ( V_5 == V_108 ) {
V_110 = ( ( V_109 - 1 ) & ~ V_107 ) + 1 ;
if ( V_110 <= V_57 ) {
F_21 ( V_1 ) ;
goto V_60;
}
}
V_110 = V_110 - V_57 ;
if ( F_123 ( V_3 ) )
F_124 ( V_1 ) ;
if ( V_102 != V_5 || V_57 != V_103 )
F_125 ( V_1 ) ;
V_102 = V_5 ;
V_20 = V_97 ( V_96 , V_1 , V_57 , V_110 ) ;
V_57 += V_20 ;
V_5 += V_57 >> V_32 ;
V_57 &= ~ V_107 ;
V_103 = V_57 ;
F_21 ( V_1 ) ;
if ( V_20 == V_110 && V_96 -> V_106 )
continue;
goto V_60;
V_115:
error = F_126 ( V_1 ) ;
if ( F_101 ( error ) )
goto V_118;
V_116:
if ( ! V_1 -> V_3 ) {
F_82 ( V_1 ) ;
F_21 ( V_1 ) ;
continue;
}
if ( F_2 ( V_1 ) ) {
F_82 ( V_1 ) ;
goto V_117;
}
V_119:
F_127 ( V_1 ) ;
error = V_3 -> V_12 -> V_119 ( V_91 , V_1 ) ;
if ( F_101 ( error ) ) {
if ( error == V_120 ) {
F_21 ( V_1 ) ;
goto V_111;
}
goto V_118;
}
if ( ! F_2 ( V_1 ) ) {
error = F_126 ( V_1 ) ;
if ( F_101 ( error ) )
goto V_118;
if ( ! F_2 ( V_1 ) ) {
if ( V_1 -> V_3 == NULL ) {
F_82 ( V_1 ) ;
F_21 ( V_1 ) ;
goto V_111;
}
F_82 ( V_1 ) ;
F_118 ( V_91 , V_93 ) ;
error = - V_40 ;
goto V_118;
}
F_82 ( V_1 ) ;
}
goto V_117;
V_118:
V_96 -> error = error ;
F_21 ( V_1 ) ;
goto V_60;
V_112:
V_1 = F_128 ( V_3 ) ;
if ( ! V_1 ) {
V_96 -> error = - V_121 ;
goto V_60;
}
error = F_58 ( V_1 , V_3 ,
V_5 , V_122 ) ;
if ( error ) {
F_21 ( V_1 ) ;
if ( error == - V_83 )
goto V_111;
V_96 -> error = error ;
goto V_60;
}
goto V_119;
}
V_60:
V_93 -> V_104 = V_102 ;
V_93 -> V_104 <<= V_32 ;
V_93 -> V_104 |= V_103 ;
* V_95 = ( ( T_1 ) V_5 << V_32 ) + V_57 ;
F_129 ( V_91 ) ;
}
int F_130 ( T_6 * V_96 , struct V_1 * V_1 ,
unsigned long V_57 , unsigned long V_123 )
{
char * V_124 ;
unsigned long V_125 , V_106 = V_96 -> V_106 ;
if ( V_123 > V_106 )
V_123 = V_106 ;
if ( ! F_131 ( V_96 -> V_126 . V_127 , V_123 ) ) {
V_124 = F_132 ( V_1 , V_128 ) ;
V_125 = F_133 ( V_96 -> V_126 . V_127 ,
V_124 + V_57 , V_123 ) ;
F_134 ( V_124 , V_128 ) ;
if ( V_125 == 0 )
goto V_129;
}
V_124 = F_135 ( V_1 ) ;
V_125 = F_136 ( V_96 -> V_126 . V_127 , V_124 + V_57 , V_123 ) ;
F_137 ( V_1 ) ;
if ( V_125 ) {
V_123 -= V_125 ;
V_96 -> error = - V_130 ;
}
V_129:
V_96 -> V_106 = V_106 - V_123 ;
V_96 -> V_131 += V_123 ;
V_96 -> V_126 . V_127 += V_123 ;
return V_123 ;
}
int F_138 ( const struct V_132 * V_133 ,
unsigned long * V_134 , T_8 * V_106 , int V_135 )
{
unsigned long V_136 ;
T_8 V_137 = 0 ;
for ( V_136 = 0 ; V_136 < * V_134 ; V_136 ++ ) {
const struct V_132 * V_138 = & V_133 [ V_136 ] ;
V_137 += V_138 -> V_139 ;
if ( F_101 ( ( V_140 ) ( V_137 | V_138 -> V_139 ) < 0 ) )
return - V_141 ;
if ( F_139 ( V_135 , V_138 -> V_142 , V_138 -> V_139 ) )
continue;
if ( V_136 == 0 )
return - V_130 ;
* V_134 = V_136 ;
V_137 -= V_138 -> V_139 ;
break;
}
* V_106 = V_137 ;
return 0 ;
}
V_140
F_140 ( struct V_143 * V_144 , const struct V_132 * V_133 ,
unsigned long V_134 , T_1 V_145 )
{
struct V_90 * V_91 = V_144 -> V_146 ;
V_140 V_147 ;
unsigned long V_136 = 0 ;
T_8 V_106 ;
T_1 * V_95 = & V_144 -> V_148 ;
struct V_149 V_150 ;
V_106 = 0 ;
V_147 = F_138 ( V_133 , & V_134 , & V_106 , V_151 ) ;
if ( V_147 )
return V_147 ;
F_141 ( & V_150 ) ;
if ( V_91 -> V_152 & V_153 ) {
T_1 V_123 ;
struct V_2 * V_3 ;
struct V_99 * V_99 ;
V_3 = V_91 -> V_98 ;
V_99 = V_3 -> V_46 ;
if ( ! V_106 )
goto V_60;
V_123 = F_43 ( V_99 ) ;
if ( V_145 < V_123 ) {
V_147 = F_45 ( V_3 , V_145 ,
V_145 + F_142 ( V_133 , V_134 ) - 1 ) ;
if ( ! V_147 ) {
V_147 = V_3 -> V_12 -> V_154 ( V_155 , V_144 ,
V_133 , V_145 , V_134 ) ;
}
if ( V_147 > 0 ) {
* V_95 = V_145 + V_147 ;
V_106 -= V_147 ;
}
if ( V_147 < 0 || ! V_106 || * V_95 >= V_123 ) {
F_129 ( V_91 ) ;
goto V_60;
}
}
}
V_106 = V_147 ;
for ( V_136 = 0 ; V_136 < V_134 ; V_136 ++ ) {
T_6 V_96 ;
T_1 V_57 = 0 ;
if ( V_106 ) {
if ( V_106 > V_133 [ V_136 ] . V_139 ) {
V_106 -= V_133 [ V_136 ] . V_139 ;
continue;
}
V_57 = V_106 ;
V_106 = 0 ;
}
V_96 . V_131 = 0 ;
V_96 . V_126 . V_127 = V_133 [ V_136 ] . V_142 + V_57 ;
V_96 . V_106 = V_133 [ V_136 ] . V_139 - V_57 ;
if ( V_96 . V_106 == 0 )
continue;
V_96 . error = 0 ;
F_119 ( V_91 , V_95 , & V_96 , F_130 ) ;
V_147 += V_96 . V_131 ;
if ( V_96 . error ) {
V_147 = V_147 ? : V_96 . error ;
break;
}
if ( V_96 . V_106 > 0 )
break;
}
V_60:
F_143 ( & V_150 ) ;
return V_147 ;
}
static V_140
F_144 ( struct V_2 * V_3 , struct V_90 * V_91 ,
T_2 V_5 , unsigned long V_110 )
{
if ( ! V_3 || ! V_3 -> V_12 || ! V_3 -> V_12 -> V_119 )
return - V_141 ;
F_145 ( V_3 , V_91 , V_5 , V_110 ) ;
return 0 ;
}
T_9 (F_146)( int V_156 , T_1 V_57 , T_8 V_106 )
{
V_140 V_20 ;
struct V_90 * V_90 ;
V_20 = - V_157 ;
V_90 = F_147 ( V_156 ) ;
if ( V_90 ) {
if ( V_90 -> V_158 & V_159 ) {
struct V_2 * V_3 = V_90 -> V_98 ;
T_2 V_17 = V_57 >> V_32 ;
T_2 V_18 = ( V_57 + V_106 - 1 ) >> V_32 ;
unsigned long V_160 = V_18 - V_17 + 1 ;
V_20 = F_144 ( V_3 , V_90 , V_17 , V_160 ) ;
}
F_148 ( V_90 ) ;
}
return V_20 ;
}
T_10 long F_149 ( long V_156 , T_1 V_57 , long V_106 )
{
return F_150 ( ( int ) V_156 , V_57 , ( T_8 ) V_106 ) ;
}
static int F_151 ( struct V_90 * V_90 , T_2 V_57 )
{
struct V_2 * V_3 = V_90 -> V_98 ;
struct V_1 * V_1 ;
int V_20 ;
do {
V_1 = F_128 ( V_3 ) ;
if ( ! V_1 )
return - V_121 ;
V_20 = F_58 ( V_1 , V_3 , V_57 , V_122 ) ;
if ( V_20 == 0 )
V_20 = V_3 -> V_12 -> V_119 ( V_90 , V_1 ) ;
else if ( V_20 == - V_83 )
V_20 = 0 ;
F_21 ( V_1 ) ;
} while ( V_20 == V_120 );
return V_20 ;
}
static void F_152 ( struct V_161 * V_162 ,
struct V_92 * V_93 ,
struct V_90 * V_90 ,
T_2 V_57 )
{
unsigned long V_94 ;
struct V_2 * V_3 = V_90 -> V_98 ;
if ( F_153 ( V_162 ) )
return;
if ( ! V_93 -> V_94 )
return;
if ( F_154 ( V_162 ) ) {
F_120 ( V_3 , V_93 , V_90 , V_57 ,
V_93 -> V_94 ) ;
return;
}
if ( V_93 -> V_163 < V_164 * 10 )
V_93 -> V_163 ++ ;
if ( V_93 -> V_163 > V_164 )
return;
V_94 = F_155 ( V_93 -> V_94 ) ;
V_93 -> V_17 = F_156 ( long , 0 , V_57 - V_94 / 2 ) ;
V_93 -> V_123 = V_94 ;
V_93 -> V_165 = V_94 / 4 ;
F_157 ( V_93 , V_3 , V_90 ) ;
}
static void F_158 ( struct V_161 * V_162 ,
struct V_92 * V_93 ,
struct V_90 * V_90 ,
struct V_1 * V_1 ,
T_2 V_57 )
{
struct V_2 * V_3 = V_90 -> V_98 ;
if ( F_153 ( V_162 ) )
return;
if ( V_93 -> V_163 > 0 )
V_93 -> V_163 -- ;
if ( F_121 ( V_1 ) )
F_122 ( V_3 , V_93 , V_90 ,
V_1 , V_57 , V_93 -> V_94 ) ;
}
int F_159 ( struct V_161 * V_162 , struct V_166 * V_167 )
{
int error ;
struct V_90 * V_90 = V_162 -> V_168 ;
struct V_2 * V_3 = V_90 -> V_98 ;
struct V_92 * V_93 = & V_90 -> V_100 ;
struct V_99 * V_99 = V_3 -> V_46 ;
T_2 V_57 = V_167 -> V_169 ;
struct V_1 * V_1 ;
T_2 V_123 ;
int V_20 = 0 ;
V_123 = ( F_43 ( V_99 ) + V_105 - 1 ) >> V_32 ;
if ( V_57 >= V_123 )
return V_170 ;
V_1 = F_97 ( V_3 , V_57 ) ;
if ( F_57 ( V_1 ) ) {
F_158 ( V_162 , V_93 , V_90 , V_1 , V_57 ) ;
} else {
F_152 ( V_162 , V_93 , V_90 , V_57 ) ;
F_160 ( V_171 ) ;
F_161 ( V_162 -> V_172 , V_171 ) ;
V_20 = V_173 ;
V_174:
V_1 = F_97 ( V_3 , V_57 ) ;
if ( ! V_1 )
goto V_112;
}
if ( ! F_162 ( V_1 , V_162 -> V_172 , V_167 -> V_42 ) ) {
F_21 ( V_1 ) ;
return V_20 | V_175 ;
}
if ( F_101 ( V_1 -> V_3 != V_3 ) ) {
F_82 ( V_1 ) ;
F_163 ( V_1 ) ;
goto V_174;
}
F_47 ( V_1 -> V_5 != V_57 ) ;
if ( F_101 ( ! F_2 ( V_1 ) ) )
goto V_176;
V_123 = ( F_43 ( V_99 ) + V_105 - 1 ) >> V_32 ;
if ( F_101 ( V_57 >= V_123 ) ) {
F_82 ( V_1 ) ;
F_21 ( V_1 ) ;
return V_170 ;
}
V_167 -> V_1 = V_1 ;
return V_20 | V_177 ;
V_112:
error = F_151 ( V_90 , V_57 ) ;
if ( error >= 0 )
goto V_174;
if ( error == - V_121 )
return V_178 ;
return V_170 ;
V_176:
F_127 ( V_1 ) ;
error = V_3 -> V_12 -> V_119 ( V_90 , V_1 ) ;
if ( ! error ) {
F_96 ( V_1 ) ;
if ( ! F_2 ( V_1 ) )
error = - V_40 ;
}
F_21 ( V_1 ) ;
if ( ! error || error == V_120 )
goto V_174;
F_118 ( V_90 , V_93 ) ;
return V_170 ;
}
int F_164 ( struct V_90 * V_90 , struct V_161 * V_162 )
{
struct V_2 * V_3 = V_90 -> V_98 ;
if ( ! V_3 -> V_12 -> V_119 )
return - V_179 ;
F_129 ( V_90 ) ;
V_162 -> V_180 = & V_181 ;
V_162 -> V_182 |= V_183 ;
return 0 ;
}
int F_165 ( struct V_90 * V_90 , struct V_161 * V_162 )
{
if ( ( V_162 -> V_182 & V_184 ) && ( V_162 -> V_182 & V_185 ) )
return - V_141 ;
return F_164 ( V_90 , V_162 ) ;
}
int F_164 ( struct V_90 * V_90 , struct V_161 * V_162 )
{
return - V_186 ;
}
int F_165 ( struct V_90 * V_90 , struct V_161 * V_162 )
{
return - V_186 ;
}
static struct V_1 * F_166 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_167)( void * , struct V_1 * ) ,
void * V_187 ,
T_3 V_61 )
{
struct V_1 * V_1 ;
int V_47 ;
V_82:
V_1 = F_97 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
V_1 = F_61 ( V_61 | V_188 ) ;
if ( ! V_1 )
return F_168 ( - V_121 ) ;
V_47 = F_58 ( V_1 , V_3 , V_5 , V_61 ) ;
if ( F_101 ( V_47 ) ) {
F_21 ( V_1 ) ;
if ( V_47 == - V_83 )
goto V_82;
return F_168 ( V_47 ) ;
}
V_47 = F_167 ( V_187 , V_1 ) ;
if ( V_47 < 0 ) {
F_21 ( V_1 ) ;
V_1 = F_168 ( V_47 ) ;
}
}
return V_1 ;
}
static struct V_1 * F_169 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_167)( void * , struct V_1 * ) ,
void * V_187 ,
T_3 V_61 )
{
struct V_1 * V_1 ;
int V_47 ;
V_189:
V_1 = F_166 ( V_3 , V_5 , F_167 , V_187 , V_61 ) ;
if ( F_170 ( V_1 ) )
return V_1 ;
if ( F_2 ( V_1 ) )
goto V_60;
F_107 ( V_1 ) ;
if ( ! V_1 -> V_3 ) {
F_82 ( V_1 ) ;
F_21 ( V_1 ) ;
goto V_189;
}
if ( F_2 ( V_1 ) ) {
F_82 ( V_1 ) ;
goto V_60;
}
V_47 = F_167 ( V_187 , V_1 ) ;
if ( V_47 < 0 ) {
F_21 ( V_1 ) ;
return F_168 ( V_47 ) ;
}
V_60:
F_125 ( V_1 ) ;
return V_1 ;
}
struct V_1 * F_171 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_167)( void * , struct V_1 * ) ,
void * V_187 )
{
return F_169 ( V_3 , V_5 , F_167 , V_187 , F_117 ( V_3 ) ) ;
}
static struct V_1 * F_172 ( struct V_1 * V_1 )
{
if ( ! F_170 ( V_1 ) ) {
F_96 ( V_1 ) ;
if ( ! F_2 ( V_1 ) ) {
F_21 ( V_1 ) ;
V_1 = F_168 ( - V_40 ) ;
}
}
return V_1 ;
}
struct V_1 * F_173 ( struct V_2 * V_3 ,
T_2 V_5 ,
T_3 V_61 )
{
T_11 * F_167 = ( T_11 * ) V_3 -> V_12 -> V_119 ;
return F_172 ( F_169 ( V_3 , V_5 , F_167 , NULL , V_61 ) ) ;
}
struct V_1 * F_174 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_167)( void * , struct V_1 * ) ,
void * V_187 )
{
return F_172 ( F_171 ( V_3 , V_5 , F_167 , V_187 ) ) ;
}
int F_175 ( struct V_190 * V_190 )
{
T_12 V_191 = V_190 -> V_192 -> V_193 ;
int V_194 = 0 ;
if ( F_101 ( V_191 & V_195 ) )
V_194 = V_196 ;
if ( F_101 ( ( V_191 & V_197 ) && ( V_191 & V_198 ) ) )
V_194 |= V_199 ;
if ( F_101 ( V_194 && ! F_176 ( V_200 ) && F_177 ( V_191 ) ) )
return V_194 ;
return 0 ;
}
static int F_178 ( struct V_190 * V_190 , int V_194 )
{
struct V_201 V_202 ;
V_202 . V_203 = V_204 | V_194 ;
return F_179 ( V_190 , & V_202 ) ;
}
int F_180 ( struct V_90 * V_90 )
{
struct V_190 * V_190 = V_90 -> V_205 . V_190 ;
struct V_99 * V_99 = V_190 -> V_192 ;
int V_206 ;
int V_207 ;
int error = 0 ;
if ( F_181 ( V_99 ) )
return 0 ;
V_206 = F_175 ( V_190 ) ;
V_207 = F_182 ( V_190 ) ;
if ( V_207 < 0 )
return V_207 ;
if ( V_207 )
error = F_183 ( V_190 ) ;
if ( ! error && V_206 )
error = F_178 ( V_190 , V_206 ) ;
if ( ! error && ( V_99 -> V_208 -> V_209 & V_210 ) )
V_99 -> V_211 |= V_212 ;
return error ;
}
static T_8 F_184 ( char * V_213 ,
const struct V_132 * V_133 , T_8 V_214 , T_8 V_215 )
{
T_8 V_216 = 0 , V_125 = 0 ;
while ( V_215 ) {
char T_13 * V_127 = V_133 -> V_142 + V_214 ;
int V_217 = F_36 ( V_215 , V_133 -> V_139 - V_214 ) ;
V_214 = 0 ;
V_125 = F_185 ( V_213 , V_127 , V_217 ) ;
V_216 += V_217 ;
V_215 -= V_217 ;
V_213 += V_217 ;
V_133 ++ ;
if ( F_101 ( V_125 ) )
break;
}
return V_216 - V_125 ;
}
T_8 F_186 ( struct V_1 * V_1 ,
struct V_218 * V_38 , unsigned long V_57 , T_8 V_215 )
{
char * V_124 ;
T_8 V_216 ;
F_9 ( ! F_187 () ) ;
V_124 = F_132 ( V_1 , V_128 ) ;
if ( F_57 ( V_38 -> V_134 == 1 ) ) {
int V_125 ;
char T_13 * V_127 = V_38 -> V_133 -> V_142 + V_38 -> V_219 ;
V_125 = F_185 ( V_124 + V_57 , V_127 , V_215 ) ;
V_216 = V_215 - V_125 ;
} else {
V_216 = F_184 ( V_124 + V_57 ,
V_38 -> V_133 , V_38 -> V_219 , V_215 ) ;
}
F_134 ( V_124 , V_128 ) ;
return V_216 ;
}
T_8 F_188 ( struct V_1 * V_1 ,
struct V_218 * V_38 , unsigned long V_57 , T_8 V_215 )
{
char * V_124 ;
T_8 V_216 ;
V_124 = F_135 ( V_1 ) ;
if ( F_57 ( V_38 -> V_134 == 1 ) ) {
int V_125 ;
char T_13 * V_127 = V_38 -> V_133 -> V_142 + V_38 -> V_219 ;
V_125 = F_189 ( V_124 + V_57 , V_127 , V_215 ) ;
V_216 = V_215 - V_125 ;
} else {
V_216 = F_184 ( V_124 + V_57 ,
V_38 -> V_133 , V_38 -> V_219 , V_215 ) ;
}
F_137 ( V_1 ) ;
return V_216 ;
}
void F_190 ( struct V_218 * V_38 , T_8 V_215 )
{
F_9 ( V_38 -> V_106 < V_215 ) ;
if ( F_57 ( V_38 -> V_134 == 1 ) ) {
V_38 -> V_219 += V_215 ;
V_38 -> V_106 -= V_215 ;
} else {
const struct V_132 * V_133 = V_38 -> V_133 ;
T_8 V_214 = V_38 -> V_219 ;
unsigned long V_134 = V_38 -> V_134 ;
while ( V_215 || F_101 ( V_38 -> V_106 && ! V_133 -> V_139 ) ) {
int V_217 ;
V_217 = F_36 ( V_215 , V_133 -> V_139 - V_214 ) ;
F_9 ( ! V_38 -> V_106 || V_38 -> V_106 < V_217 ) ;
V_38 -> V_106 -= V_217 ;
V_215 -= V_217 ;
V_214 += V_217 ;
if ( V_133 -> V_139 == V_214 ) {
V_133 ++ ;
V_134 -- ;
V_214 = 0 ;
}
}
V_38 -> V_133 = V_133 ;
V_38 -> V_219 = V_214 ;
V_38 -> V_134 = V_134 ;
}
}
int F_191 ( struct V_218 * V_38 , T_8 V_215 )
{
char T_13 * V_127 = V_38 -> V_133 -> V_142 + V_38 -> V_219 ;
V_215 = F_36 ( V_215 , V_38 -> V_133 -> V_139 - V_38 -> V_219 ) ;
return F_192 ( V_127 , V_215 ) ;
}
T_8 F_193 ( struct V_218 * V_38 )
{
const struct V_132 * V_133 = V_38 -> V_133 ;
if ( V_38 -> V_134 == 1 )
return V_38 -> V_106 ;
else
return F_36 ( V_38 -> V_106 , V_133 -> V_139 - V_38 -> V_219 ) ;
}
inline int F_194 ( struct V_90 * V_90 , T_1 * V_145 , T_8 * V_106 , int V_220 )
{
struct V_99 * V_99 = V_90 -> V_98 -> V_46 ;
unsigned long V_221 = F_195 ( V_222 ) ;
if ( F_101 ( * V_145 < 0 ) )
return - V_141 ;
if ( ! V_220 ) {
if ( V_90 -> V_152 & V_223 )
* V_145 = F_43 ( V_99 ) ;
if ( V_221 != V_224 ) {
if ( * V_145 >= V_221 ) {
F_196 ( V_225 , V_15 , 0 ) ;
return - V_226 ;
}
if ( * V_106 > V_221 - ( F_197 ( V_221 ) ) * V_145 ) {
* V_106 = V_221 - ( F_197 ( V_221 ) ) * V_145 ;
}
}
}
if ( F_101 ( * V_145 + * V_106 > V_227 &&
! ( V_90 -> V_152 & V_228 ) ) ) {
if ( * V_145 >= V_227 ) {
return - V_226 ;
}
if ( * V_106 > V_227 - ( unsigned long ) * V_145 ) {
* V_106 = V_227 - ( unsigned long ) * V_145 ;
}
}
if ( F_57 ( ! V_220 ) ) {
if ( F_101 ( * V_145 >= V_99 -> V_208 -> V_229 ) ) {
if ( * V_106 || * V_145 > V_99 -> V_208 -> V_229 ) {
return - V_226 ;
}
}
if ( F_101 ( * V_145 + * V_106 > V_99 -> V_208 -> V_229 ) )
* V_106 = V_99 -> V_208 -> V_229 - * V_145 ;
} else {
#ifdef F_198
T_1 V_109 ;
if ( F_199 ( F_200 ( V_99 ) ) )
return - V_230 ;
V_109 = F_43 ( V_99 ) ;
if ( * V_145 >= V_109 ) {
if ( * V_106 || * V_145 > V_109 )
return - V_43 ;
}
if ( * V_145 + * V_106 > V_109 )
* V_106 = V_109 - * V_145 ;
#else
return - V_230 ;
#endif
}
return 0 ;
}
int F_201 ( struct V_90 * V_90 , struct V_2 * V_3 ,
T_1 V_145 , unsigned V_160 , unsigned V_42 ,
struct V_1 * * V_81 , void * * V_231 )
{
const struct V_232 * V_233 = V_3 -> V_12 ;
return V_233 -> V_234 ( V_90 , V_3 , V_145 , V_160 , V_42 ,
V_81 , V_231 ) ;
}
int F_202 ( struct V_90 * V_90 , struct V_2 * V_3 ,
T_1 V_145 , unsigned V_160 , unsigned V_216 ,
struct V_1 * V_1 , void * V_231 )
{
const struct V_232 * V_233 = V_3 -> V_12 ;
F_125 ( V_1 ) ;
return V_233 -> V_235 ( V_90 , V_3 , V_145 , V_160 , V_216 , V_1 , V_231 ) ;
}
V_140
F_203 ( struct V_143 * V_144 , const struct V_132 * V_133 ,
unsigned long * V_134 , T_1 V_145 , T_1 * V_95 ,
T_8 V_106 , T_8 V_236 )
{
struct V_90 * V_90 = V_144 -> V_146 ;
struct V_2 * V_3 = V_90 -> V_98 ;
struct V_99 * V_99 = V_3 -> V_46 ;
V_140 V_131 ;
T_8 V_237 ;
T_2 V_18 ;
if ( V_106 != V_236 )
* V_134 = F_204 ( (struct V_132 * ) V_133 , * V_134 , V_106 ) ;
V_237 = F_142 ( V_133 , * V_134 ) ;
V_18 = ( V_145 + V_237 - 1 ) >> V_32 ;
V_131 = F_45 ( V_3 , V_145 , V_145 + V_237 - 1 ) ;
if ( V_131 )
goto V_60;
if ( V_3 -> V_6 ) {
V_131 = F_205 ( V_3 ,
V_145 >> V_32 , V_18 ) ;
if ( V_131 ) {
if ( V_131 == - V_238 )
return 0 ;
goto V_60;
}
}
V_131 = V_3 -> V_12 -> V_154 ( V_239 , V_144 , V_133 , V_145 , * V_134 ) ;
if ( V_3 -> V_6 ) {
F_205 ( V_3 ,
V_145 >> V_32 , V_18 ) ;
}
if ( V_131 > 0 ) {
V_145 += V_131 ;
if ( V_145 > F_43 ( V_99 ) && ! F_206 ( V_99 -> V_193 ) ) {
F_207 ( V_99 , V_145 ) ;
F_208 ( V_99 ) ;
}
* V_95 = V_145 ;
}
V_60:
return V_131 ;
}
struct V_1 * F_209 ( struct V_2 * V_3 ,
T_2 V_5 , unsigned V_42 )
{
int V_240 ;
struct V_1 * V_1 ;
T_3 V_241 = 0 ;
if ( V_42 & V_242 )
V_241 = V_88 ;
V_82:
V_1 = F_106 ( V_3 , V_5 ) ;
if ( V_1 )
goto V_243;
V_1 = F_61 ( F_117 ( V_3 ) & ~ V_241 ) ;
if ( ! V_1 )
return NULL ;
V_240 = F_58 ( V_1 , V_3 , V_5 ,
V_122 & ~ V_241 ) ;
if ( F_101 ( V_240 ) ) {
F_21 ( V_1 ) ;
if ( V_240 == - V_83 )
goto V_82;
return NULL ;
}
V_243:
F_37 ( V_1 ) ;
return V_1 ;
}
static V_140 F_210 ( struct V_90 * V_90 ,
struct V_218 * V_38 , T_1 V_145 )
{
struct V_2 * V_3 = V_90 -> V_98 ;
const struct V_232 * V_12 = V_3 -> V_12 ;
long V_240 = 0 ;
V_140 V_131 = 0 ;
unsigned int V_42 = 0 ;
if ( F_211 ( F_212 () , V_244 ) )
V_42 |= V_245 ;
do {
struct V_1 * V_1 ;
unsigned long V_57 ;
unsigned long V_215 ;
T_8 V_216 ;
void * V_231 ;
V_57 = ( V_145 & ( V_105 - 1 ) ) ;
V_215 = F_213 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_count(i)) ;
V_246:
if ( F_101 ( F_191 ( V_38 , V_215 ) ) ) {
V_240 = - V_130 ;
break;
}
V_240 = V_12 -> V_234 ( V_90 , V_3 , V_145 , V_215 , V_42 ,
& V_1 , & V_231 ) ;
if ( F_101 ( V_240 ) )
break;
if ( F_123 ( V_3 ) )
F_124 ( V_1 ) ;
F_214 () ;
V_216 = F_186 ( V_1 , V_38 , V_57 , V_215 ) ;
F_215 () ;
F_124 ( V_1 ) ;
F_125 ( V_1 ) ;
V_240 = V_12 -> V_235 ( V_90 , V_3 , V_145 , V_215 , V_216 ,
V_1 , V_231 ) ;
if ( F_101 ( V_240 < 0 ) )
break;
V_216 = V_240 ;
F_40 () ;
F_190 ( V_38 , V_216 ) ;
if ( F_101 ( V_216 == 0 ) ) {
V_215 = F_213 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_246;
}
V_145 += V_216 ;
V_131 += V_216 ;
F_216 ( V_3 ) ;
if ( F_25 ( V_15 ) ) {
V_240 = - V_16 ;
break;
}
} while ( F_217 ( V_38 ) );
return V_131 ? V_131 : V_240 ;
}
V_140
F_218 ( struct V_143 * V_144 , const struct V_132 * V_133 ,
unsigned long V_134 , T_1 V_145 , T_1 * V_95 ,
T_8 V_106 , V_140 V_131 )
{
struct V_90 * V_90 = V_144 -> V_146 ;
V_140 V_240 ;
struct V_218 V_38 ;
F_219 ( & V_38 , V_133 , V_134 , V_106 , V_131 ) ;
V_240 = F_210 ( V_90 , & V_38 , V_145 ) ;
if ( F_57 ( V_240 >= 0 ) ) {
V_131 += V_240 ;
* V_95 = V_145 + V_240 ;
}
return V_131 ? V_131 : V_240 ;
}
V_140 F_220 ( struct V_143 * V_144 , const struct V_132 * V_133 ,
unsigned long V_134 , T_1 * V_95 )
{
struct V_90 * V_90 = V_144 -> V_146 ;
struct V_2 * V_3 = V_90 -> V_98 ;
T_8 V_236 ;
T_8 V_106 ;
struct V_99 * V_99 = V_3 -> V_46 ;
T_1 V_145 ;
V_140 V_131 ;
V_140 V_47 ;
V_236 = 0 ;
V_47 = F_138 ( V_133 , & V_134 , & V_236 , V_247 ) ;
if ( V_47 )
return V_47 ;
V_106 = V_236 ;
V_145 = * V_95 ;
F_221 ( V_99 -> V_208 , V_248 ) ;
V_15 -> V_10 = V_3 -> V_10 ;
V_131 = 0 ;
V_47 = F_194 ( V_90 , & V_145 , & V_106 , F_206 ( V_99 -> V_193 ) ) ;
if ( V_47 )
goto V_60;
if ( V_106 == 0 )
goto V_60;
V_47 = F_180 ( V_90 ) ;
if ( V_47 )
goto V_60;
F_222 ( V_90 ) ;
if ( F_101 ( V_90 -> V_152 & V_153 ) ) {
T_1 V_249 ;
V_140 V_250 ;
V_131 = F_203 ( V_144 , V_133 , & V_134 , V_145 ,
V_95 , V_106 , V_236 ) ;
if ( V_131 < 0 || V_131 == V_106 )
goto V_60;
V_145 += V_131 ;
V_106 -= V_131 ;
V_250 = F_218 ( V_144 , V_133 ,
V_134 , V_145 , V_95 , V_106 ,
V_131 ) ;
if ( V_250 < 0 ) {
V_47 = V_250 ;
goto V_60;
}
V_249 = V_145 + V_250 - V_131 - 1 ;
V_47 = F_45 ( V_90 -> V_98 , V_145 , V_249 ) ;
if ( V_47 == 0 ) {
V_131 = V_250 ;
F_223 ( V_3 ,
V_145 >> V_32 ,
V_249 >> V_32 ) ;
} else {
}
} else {
V_131 = F_218 ( V_144 , V_133 , V_134 ,
V_145 , V_95 , V_106 , V_131 ) ;
}
V_60:
V_15 -> V_10 = NULL ;
return V_131 ? V_131 : V_47 ;
}
V_140 F_224 ( struct V_143 * V_144 , const struct V_132 * V_133 ,
unsigned long V_134 , T_1 V_145 )
{
struct V_90 * V_90 = V_144 -> V_146 ;
struct V_99 * V_99 = V_90 -> V_98 -> V_46 ;
struct V_149 V_150 ;
V_140 V_20 ;
F_9 ( V_144 -> V_148 != V_145 ) ;
F_225 ( & V_99 -> V_251 ) ;
F_141 ( & V_150 ) ;
V_20 = F_220 ( V_144 , V_133 , V_134 , & V_144 -> V_148 ) ;
F_226 ( & V_99 -> V_251 ) ;
if ( V_20 > 0 || V_20 == - V_252 ) {
V_140 V_47 ;
V_47 = F_227 ( V_90 , V_145 , V_20 ) ;
if ( V_47 < 0 && V_20 > 0 )
V_20 = V_47 ;
}
F_143 ( & V_150 ) ;
return V_20 ;
}
int F_228 ( struct V_1 * V_1 , T_3 V_53 )
{
struct V_2 * const V_3 = V_1 -> V_3 ;
F_9 ( ! F_17 ( V_1 ) ) ;
if ( F_229 ( V_1 ) )
return 0 ;
if ( V_3 && V_3 -> V_12 -> V_253 )
return V_3 -> V_12 -> V_253 ( V_1 , V_53 ) ;
return F_230 ( V_1 ) ;
}
