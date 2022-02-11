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
F_47 ( ! F_17 ( V_51 ) ) ;
F_47 ( ! F_17 ( V_52 ) ) ;
F_47 ( V_52 -> V_3 ) ;
error = F_48 ( V_53 & ~ V_54 ) ;
if ( ! error ) {
struct V_2 * V_3 = V_51 -> V_3 ;
void (* F_16)( struct V_1 * );
T_2 V_55 = V_51 -> V_5 ;
F_16 = V_3 -> V_12 -> F_16 ;
F_49 ( V_52 ) ;
V_52 -> V_3 = V_3 ;
V_52 -> V_5 = V_55 ;
F_18 ( & V_3 -> V_13 ) ;
F_1 ( V_51 ) ;
error = F_50 ( & V_3 -> V_4 , V_55 , V_52 ) ;
F_9 ( error ) ;
V_3 -> V_6 ++ ;
F_51 ( V_52 , V_7 ) ;
if ( F_8 ( V_52 ) )
F_51 ( V_52 , V_8 ) ;
F_19 ( & V_3 -> V_13 ) ;
F_52 ( V_51 , V_52 ) ;
F_53 () ;
if ( F_16 )
F_16 ( V_51 ) ;
F_21 ( V_51 ) ;
}
return error ;
}
int F_54 ( struct V_1 * V_1 , struct V_2 * V_3 ,
T_2 V_55 , T_3 V_53 )
{
int error ;
F_47 ( ! F_17 ( V_1 ) ) ;
F_47 ( F_8 ( V_1 ) ) ;
error = F_55 ( V_1 , V_15 -> V_56 ,
V_53 & V_57 ) ;
if ( error )
goto V_58;
error = F_48 ( V_53 & ~ V_54 ) ;
if ( error == 0 ) {
F_49 ( V_1 ) ;
V_1 -> V_3 = V_3 ;
V_1 -> V_5 = V_55 ;
F_18 ( & V_3 -> V_13 ) ;
error = F_50 ( & V_3 -> V_4 , V_55 , V_1 ) ;
if ( F_56 ( ! error ) ) {
V_3 -> V_6 ++ ;
F_51 ( V_1 , V_7 ) ;
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
V_58:
return error ;
}
int F_57 ( struct V_1 * V_1 , struct V_2 * V_3 ,
T_2 V_55 , T_3 V_53 )
{
int V_20 ;
V_20 = F_58 ( V_1 , V_3 , V_55 , V_53 ) ;
if ( V_20 == 0 )
F_59 ( V_1 ) ;
return V_20 ;
}
struct V_1 * F_60 ( T_3 V_59 )
{
int V_60 ;
struct V_1 * V_1 ;
if ( F_61 () ) {
F_62 () ;
V_60 = F_63 () ;
V_1 = F_64 ( V_60 , V_59 , 0 ) ;
F_65 () ;
return V_1 ;
}
return F_66 ( V_59 , 0 ) ;
}
static T_4 * F_67 ( struct V_1 * V_1 )
{
const struct V_61 * V_61 = F_68 ( V_1 ) ;
return & V_61 -> V_62 [ F_69 ( V_1 , V_61 -> V_63 ) ] ;
}
static inline void F_70 ( struct V_1 * V_1 , int V_64 )
{
F_71 ( F_67 ( V_1 ) , & V_1 -> V_42 , V_64 ) ;
}
void F_72 ( struct V_1 * V_1 , int V_65 )
{
F_73 ( V_66 , & V_1 -> V_42 , V_65 ) ;
if ( F_74 ( V_65 , & V_1 -> V_42 ) )
F_75 ( F_67 ( V_1 ) , & V_66 , F_22 ,
V_67 ) ;
}
int F_76 ( struct V_1 * V_1 , int V_65 )
{
F_73 ( V_66 , & V_1 -> V_42 , V_65 ) ;
if ( ! F_74 ( V_65 , & V_1 -> V_42 ) )
return 0 ;
return F_75 ( F_67 ( V_1 ) , & V_66 ,
F_24 , V_68 ) ;
}
void F_77 ( struct V_1 * V_1 , T_5 * V_69 )
{
T_4 * V_70 = F_67 ( V_1 ) ;
unsigned long V_42 ;
F_78 ( & V_70 -> V_71 , V_42 ) ;
F_79 ( V_70 , V_69 ) ;
F_80 ( & V_70 -> V_71 , V_42 ) ;
}
void F_81 ( struct V_1 * V_1 )
{
F_47 ( ! F_17 ( V_1 ) ) ;
F_82 ( V_72 , & V_1 -> V_42 ) ;
F_83 () ;
F_70 ( V_1 , V_72 ) ;
}
void F_84 ( struct V_1 * V_1 )
{
if ( F_85 ( V_1 ) )
F_86 ( V_1 ) ;
if ( ! F_87 ( V_1 ) )
F_88 () ;
F_83 () ;
F_70 ( V_1 , V_73 ) ;
}
void F_89 ( struct V_1 * V_1 )
{
F_73 ( V_66 , & V_1 -> V_42 , V_72 ) ;
F_90 ( F_67 ( V_1 ) , & V_66 , F_22 ,
V_67 ) ;
}
int F_91 ( struct V_1 * V_1 )
{
F_73 ( V_66 , & V_1 -> V_42 , V_72 ) ;
return F_90 ( F_67 ( V_1 ) , & V_66 ,
F_24 , V_68 ) ;
}
int F_92 ( struct V_1 * V_1 , struct V_74 * V_56 ,
unsigned int V_42 )
{
if ( V_42 & V_75 ) {
if ( V_42 & V_76 )
return 0 ;
F_93 ( & V_56 -> V_77 ) ;
if ( V_42 & V_78 )
F_94 ( V_1 ) ;
else
F_95 ( V_1 ) ;
return 0 ;
} else {
if ( V_42 & V_78 ) {
int V_20 ;
V_20 = F_91 ( V_1 ) ;
if ( V_20 ) {
F_93 ( & V_56 -> V_77 ) ;
return 0 ;
}
} else
F_89 ( V_1 ) ;
return 1 ;
}
}
struct V_1 * F_96 ( struct V_2 * V_3 , T_2 V_55 )
{
void * * V_79 ;
struct V_1 * V_1 ;
F_97 () ;
V_80:
V_1 = NULL ;
V_79 = F_98 ( & V_3 -> V_4 , V_55 ) ;
if ( V_79 ) {
V_1 = F_99 ( V_79 ) ;
if ( F_100 ( ! V_1 ) )
goto V_58;
if ( F_101 ( V_1 ) ) {
if ( F_102 ( V_1 ) )
goto V_80;
goto V_58;
}
if ( ! F_103 ( V_1 ) )
goto V_80;
if ( F_100 ( V_1 != * V_79 ) ) {
F_21 ( V_1 ) ;
goto V_80;
}
}
V_58:
F_104 () ;
return V_1 ;
}
struct V_1 * F_105 ( struct V_2 * V_3 , T_2 V_55 )
{
struct V_1 * V_1 ;
V_80:
V_1 = F_96 ( V_3 , V_55 ) ;
if ( V_1 && ! F_101 ( V_1 ) ) {
F_106 ( V_1 ) ;
if ( F_100 ( V_1 -> V_3 != V_3 ) ) {
F_81 ( V_1 ) ;
F_21 ( V_1 ) ;
goto V_80;
}
F_47 ( V_1 -> V_5 != V_55 ) ;
}
return V_1 ;
}
struct V_1 * F_107 ( struct V_2 * V_3 ,
T_2 V_5 , T_3 V_53 )
{
struct V_1 * V_1 ;
int V_47 ;
V_80:
V_1 = F_105 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
V_1 = F_60 ( V_53 ) ;
if ( ! V_1 )
return NULL ;
V_47 = F_57 ( V_1 , V_3 , V_5 ,
( V_53 & V_57 ) ) ;
if ( F_100 ( V_47 ) ) {
F_21 ( V_1 ) ;
V_1 = NULL ;
if ( V_47 == - V_81 )
goto V_80;
}
}
return V_1 ;
}
unsigned F_108 ( struct V_2 * V_3 , T_2 V_17 ,
unsigned int V_35 , struct V_1 * * V_39 )
{
unsigned int V_38 ;
unsigned int V_20 ;
unsigned int V_82 , V_83 ;
F_97 () ;
V_84:
V_82 = F_109 ( & V_3 -> V_4 ,
( void * * * ) V_39 , NULL , V_17 , V_35 ) ;
V_20 = 0 ;
V_83 = 0 ;
for ( V_38 = 0 ; V_38 < V_82 ; V_38 ++ ) {
struct V_1 * V_1 ;
V_80:
V_1 = F_99 ( ( void * * ) V_39 [ V_38 ] ) ;
if ( F_100 ( ! V_1 ) )
continue;
if ( F_101 ( V_1 ) ) {
if ( F_102 ( V_1 ) ) {
F_110 ( V_17 | V_38 ) ;
goto V_84;
}
V_83 ++ ;
continue;
}
if ( ! F_103 ( V_1 ) )
goto V_80;
if ( F_100 ( V_1 != * ( ( void * * ) V_39 [ V_38 ] ) ) ) {
F_21 ( V_1 ) ;
goto V_80;
}
V_39 [ V_20 ] = V_1 ;
V_20 ++ ;
}
if ( F_100 ( ! V_20 && V_82 > V_83 ) )
goto V_84;
F_104 () ;
return V_20 ;
}
unsigned F_111 ( struct V_2 * V_3 , T_2 V_5 ,
unsigned int V_35 , struct V_1 * * V_39 )
{
unsigned int V_38 ;
unsigned int V_20 ;
unsigned int V_82 ;
F_97 () ;
V_84:
V_82 = F_109 ( & V_3 -> V_4 ,
( void * * * ) V_39 , NULL , V_5 , V_35 ) ;
V_20 = 0 ;
for ( V_38 = 0 ; V_38 < V_82 ; V_38 ++ ) {
struct V_1 * V_1 ;
V_80:
V_1 = F_99 ( ( void * * ) V_39 [ V_38 ] ) ;
if ( F_100 ( ! V_1 ) )
continue;
if ( F_101 ( V_1 ) ) {
if ( F_102 ( V_1 ) ) {
goto V_84;
}
break;
}
if ( ! F_103 ( V_1 ) )
goto V_80;
if ( F_100 ( V_1 != * ( ( void * * ) V_39 [ V_38 ] ) ) ) {
F_21 ( V_1 ) ;
goto V_80;
}
if ( V_1 -> V_3 == NULL || V_1 -> V_5 != V_5 ) {
F_21 ( V_1 ) ;
break;
}
V_39 [ V_20 ] = V_1 ;
V_20 ++ ;
V_5 ++ ;
}
F_104 () ;
return V_20 ;
}
unsigned F_112 ( struct V_2 * V_3 , T_2 * V_5 ,
int V_85 , unsigned int V_35 , struct V_1 * * V_39 )
{
unsigned int V_38 ;
unsigned int V_20 ;
unsigned int V_82 ;
F_97 () ;
V_84:
V_82 = F_113 ( & V_3 -> V_4 ,
( void * * * ) V_39 , * V_5 , V_35 , V_85 ) ;
V_20 = 0 ;
for ( V_38 = 0 ; V_38 < V_82 ; V_38 ++ ) {
struct V_1 * V_1 ;
V_80:
V_1 = F_99 ( ( void * * ) V_39 [ V_38 ] ) ;
if ( F_100 ( ! V_1 ) )
continue;
if ( F_101 ( V_1 ) ) {
if ( F_102 ( V_1 ) ) {
goto V_84;
}
F_88 () ;
}
if ( ! F_103 ( V_1 ) )
goto V_80;
if ( F_100 ( V_1 != * ( ( void * * ) V_39 [ V_38 ] ) ) ) {
F_21 ( V_1 ) ;
goto V_80;
}
V_39 [ V_20 ] = V_1 ;
V_20 ++ ;
}
if ( F_100 ( ! V_20 && V_82 ) )
goto V_84;
F_104 () ;
if ( V_20 )
* V_5 = V_39 [ V_20 - 1 ] -> V_5 + 1 ;
return V_20 ;
}
struct V_1 *
F_114 ( struct V_2 * V_3 , T_2 V_5 )
{
struct V_1 * V_1 = F_96 ( V_3 , V_5 ) ;
if ( V_1 ) {
if ( F_115 ( V_1 ) )
return V_1 ;
F_21 ( V_1 ) ;
return NULL ;
}
V_1 = F_60 ( F_116 ( V_3 ) & ~ V_86 ) ;
if ( V_1 && F_57 ( V_1 , V_3 , V_5 , V_87 ) ) {
F_21 ( V_1 ) ;
V_1 = NULL ;
}
return V_1 ;
}
static void F_117 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
V_91 -> V_92 /= 4 ;
}
static void F_118 ( struct V_88 * V_89 , T_1 * V_93 ,
T_6 * V_94 , T_7 V_95 )
{
struct V_2 * V_3 = V_89 -> V_96 ;
struct V_97 * V_97 = V_3 -> V_46 ;
struct V_90 * V_91 = & V_89 -> V_98 ;
T_2 V_5 ;
T_2 V_99 ;
T_2 V_100 ;
unsigned long V_55 ;
unsigned int V_101 ;
int error ;
V_5 = * V_93 >> V_32 ;
V_100 = V_91 -> V_102 >> V_32 ;
V_101 = V_91 -> V_102 & ( V_103 - 1 ) ;
V_99 = ( * V_93 + V_94 -> V_104 + V_103 - 1 ) >> V_32 ;
V_55 = * V_93 & ~ V_105 ;
for (; ; ) {
struct V_1 * V_1 ;
T_2 V_106 ;
T_1 V_107 ;
unsigned long V_108 , V_20 ;
F_40 () ;
V_109:
V_1 = F_96 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
F_119 ( V_3 ,
V_91 , V_89 ,
V_5 , V_99 - V_5 ) ;
V_1 = F_96 ( V_3 , V_5 ) ;
if ( F_100 ( V_1 == NULL ) )
goto V_110;
}
if ( F_120 ( V_1 ) ) {
F_121 ( V_3 ,
V_91 , V_89 , V_1 ,
V_5 , V_99 - V_5 ) ;
}
if ( ! F_2 ( V_1 ) ) {
if ( V_97 -> V_111 == V_32 ||
! V_3 -> V_12 -> V_112 )
goto V_113;
if ( ! F_115 ( V_1 ) )
goto V_113;
if ( ! V_1 -> V_3 )
goto V_114;
if ( ! V_3 -> V_12 -> V_112 ( V_1 ,
V_94 , V_55 ) )
goto V_114;
F_81 ( V_1 ) ;
}
V_115:
V_107 = F_43 ( V_97 ) ;
V_106 = ( V_107 - 1 ) >> V_32 ;
if ( F_100 ( ! V_107 || V_5 > V_106 ) ) {
F_21 ( V_1 ) ;
goto V_58;
}
V_108 = V_103 ;
if ( V_5 == V_106 ) {
V_108 = ( ( V_107 - 1 ) & ~ V_105 ) + 1 ;
if ( V_108 <= V_55 ) {
F_21 ( V_1 ) ;
goto V_58;
}
}
V_108 = V_108 - V_55 ;
if ( F_122 ( V_3 ) )
F_123 ( V_1 ) ;
if ( V_100 != V_5 || V_55 != V_101 )
F_124 ( V_1 ) ;
V_100 = V_5 ;
V_20 = V_95 ( V_94 , V_1 , V_55 , V_108 ) ;
V_55 += V_20 ;
V_5 += V_55 >> V_32 ;
V_55 &= ~ V_105 ;
V_101 = V_55 ;
F_21 ( V_1 ) ;
if ( V_20 == V_108 && V_94 -> V_104 )
continue;
goto V_58;
V_113:
error = F_125 ( V_1 ) ;
if ( F_100 ( error ) )
goto V_116;
V_114:
if ( ! V_1 -> V_3 ) {
F_81 ( V_1 ) ;
F_21 ( V_1 ) ;
continue;
}
if ( F_2 ( V_1 ) ) {
F_81 ( V_1 ) ;
goto V_115;
}
V_117:
F_126 ( V_1 ) ;
error = V_3 -> V_12 -> V_117 ( V_89 , V_1 ) ;
if ( F_100 ( error ) ) {
if ( error == V_118 ) {
F_21 ( V_1 ) ;
goto V_109;
}
goto V_116;
}
if ( ! F_2 ( V_1 ) ) {
error = F_125 ( V_1 ) ;
if ( F_100 ( error ) )
goto V_116;
if ( ! F_2 ( V_1 ) ) {
if ( V_1 -> V_3 == NULL ) {
F_81 ( V_1 ) ;
F_21 ( V_1 ) ;
goto V_109;
}
F_81 ( V_1 ) ;
F_117 ( V_89 , V_91 ) ;
error = - V_40 ;
goto V_116;
}
F_81 ( V_1 ) ;
}
goto V_115;
V_116:
V_94 -> error = error ;
F_21 ( V_1 ) ;
goto V_58;
V_110:
V_1 = F_127 ( V_3 ) ;
if ( ! V_1 ) {
V_94 -> error = - V_119 ;
goto V_58;
}
error = F_57 ( V_1 , V_3 ,
V_5 , V_120 ) ;
if ( error ) {
F_21 ( V_1 ) ;
if ( error == - V_81 )
goto V_109;
V_94 -> error = error ;
goto V_58;
}
goto V_117;
}
V_58:
V_91 -> V_102 = V_100 ;
V_91 -> V_102 <<= V_32 ;
V_91 -> V_102 |= V_101 ;
* V_93 = ( ( T_1 ) V_5 << V_32 ) + V_55 ;
F_128 ( V_89 ) ;
}
int F_129 ( T_6 * V_94 , struct V_1 * V_1 ,
unsigned long V_55 , unsigned long V_121 )
{
char * V_122 ;
unsigned long V_123 , V_104 = V_94 -> V_104 ;
if ( V_121 > V_104 )
V_121 = V_104 ;
if ( ! F_130 ( V_94 -> V_124 . V_125 , V_121 ) ) {
V_122 = F_131 ( V_1 , V_126 ) ;
V_123 = F_132 ( V_94 -> V_124 . V_125 ,
V_122 + V_55 , V_121 ) ;
F_133 ( V_122 , V_126 ) ;
if ( V_123 == 0 )
goto V_127;
}
V_122 = F_134 ( V_1 ) ;
V_123 = F_135 ( V_94 -> V_124 . V_125 , V_122 + V_55 , V_121 ) ;
F_136 ( V_1 ) ;
if ( V_123 ) {
V_121 -= V_123 ;
V_94 -> error = - V_128 ;
}
V_127:
V_94 -> V_104 = V_104 - V_121 ;
V_94 -> V_129 += V_121 ;
V_94 -> V_124 . V_125 += V_121 ;
return V_121 ;
}
int F_137 ( const struct V_130 * V_131 ,
unsigned long * V_132 , T_8 * V_104 , int V_133 )
{
unsigned long V_134 ;
T_8 V_135 = 0 ;
for ( V_134 = 0 ; V_134 < * V_132 ; V_134 ++ ) {
const struct V_130 * V_136 = & V_131 [ V_134 ] ;
V_135 += V_136 -> V_137 ;
if ( F_100 ( ( V_138 ) ( V_135 | V_136 -> V_137 ) < 0 ) )
return - V_139 ;
if ( F_138 ( V_133 , V_136 -> V_140 , V_136 -> V_137 ) )
continue;
if ( V_134 == 0 )
return - V_128 ;
* V_132 = V_134 ;
V_135 -= V_136 -> V_137 ;
break;
}
* V_104 = V_135 ;
return 0 ;
}
V_138
F_139 ( struct V_141 * V_142 , const struct V_130 * V_131 ,
unsigned long V_132 , T_1 V_143 )
{
struct V_88 * V_89 = V_142 -> V_144 ;
V_138 V_145 ;
unsigned long V_134 = 0 ;
T_8 V_104 ;
T_1 * V_93 = & V_142 -> V_146 ;
V_104 = 0 ;
V_145 = F_137 ( V_131 , & V_132 , & V_104 , V_147 ) ;
if ( V_145 )
return V_145 ;
if ( V_89 -> V_148 & V_149 ) {
T_1 V_121 ;
struct V_2 * V_3 ;
struct V_97 * V_97 ;
V_3 = V_89 -> V_96 ;
V_97 = V_3 -> V_46 ;
if ( ! V_104 )
goto V_58;
V_121 = F_43 ( V_97 ) ;
if ( V_143 < V_121 ) {
V_145 = F_45 ( V_3 , V_143 ,
V_143 + F_140 ( V_131 , V_132 ) - 1 ) ;
if ( ! V_145 ) {
struct V_150 V_151 ;
F_141 ( & V_151 ) ;
V_145 = V_3 -> V_12 -> V_152 ( V_153 , V_142 ,
V_131 , V_143 , V_132 ) ;
F_142 ( & V_151 ) ;
}
if ( V_145 > 0 ) {
* V_93 = V_143 + V_145 ;
V_104 -= V_145 ;
}
if ( V_145 < 0 || ! V_104 || * V_93 >= V_121 ) {
F_128 ( V_89 ) ;
goto V_58;
}
}
}
V_104 = V_145 ;
for ( V_134 = 0 ; V_134 < V_132 ; V_134 ++ ) {
T_6 V_94 ;
T_1 V_55 = 0 ;
if ( V_104 ) {
if ( V_104 > V_131 [ V_134 ] . V_137 ) {
V_104 -= V_131 [ V_134 ] . V_137 ;
continue;
}
V_55 = V_104 ;
V_104 = 0 ;
}
V_94 . V_129 = 0 ;
V_94 . V_124 . V_125 = V_131 [ V_134 ] . V_140 + V_55 ;
V_94 . V_104 = V_131 [ V_134 ] . V_137 - V_55 ;
if ( V_94 . V_104 == 0 )
continue;
V_94 . error = 0 ;
F_118 ( V_89 , V_93 , & V_94 , F_129 ) ;
V_145 += V_94 . V_129 ;
if ( V_94 . error ) {
V_145 = V_145 ? : V_94 . error ;
break;
}
if ( V_94 . V_104 > 0 )
break;
}
V_58:
return V_145 ;
}
static V_138
F_143 ( struct V_2 * V_3 , struct V_88 * V_89 ,
T_2 V_5 , unsigned long V_108 )
{
if ( ! V_3 || ! V_3 -> V_12 || ! V_3 -> V_12 -> V_117 )
return - V_139 ;
F_144 ( V_3 , V_89 , V_5 , V_108 ) ;
return 0 ;
}
T_9 (F_145)( int V_154 , T_1 V_55 , T_8 V_104 )
{
V_138 V_20 ;
struct V_88 * V_88 ;
V_20 = - V_155 ;
V_88 = F_146 ( V_154 ) ;
if ( V_88 ) {
if ( V_88 -> V_156 & V_157 ) {
struct V_2 * V_3 = V_88 -> V_96 ;
T_2 V_17 = V_55 >> V_32 ;
T_2 V_18 = ( V_55 + V_104 - 1 ) >> V_32 ;
unsigned long V_158 = V_18 - V_17 + 1 ;
V_20 = F_143 ( V_3 , V_88 , V_17 , V_158 ) ;
}
F_147 ( V_88 ) ;
}
return V_20 ;
}
T_10 long F_148 ( long V_154 , T_1 V_55 , long V_104 )
{
return F_149 ( ( int ) V_154 , V_55 , ( T_8 ) V_104 ) ;
}
static int F_150 ( struct V_88 * V_88 , T_2 V_55 )
{
struct V_2 * V_3 = V_88 -> V_96 ;
struct V_1 * V_1 ;
int V_20 ;
do {
V_1 = F_127 ( V_3 ) ;
if ( ! V_1 )
return - V_119 ;
V_20 = F_57 ( V_1 , V_3 , V_55 , V_120 ) ;
if ( V_20 == 0 )
V_20 = V_3 -> V_12 -> V_117 ( V_88 , V_1 ) ;
else if ( V_20 == - V_81 )
V_20 = 0 ;
F_21 ( V_1 ) ;
} while ( V_20 == V_118 );
return V_20 ;
}
static void F_151 ( struct V_159 * V_160 ,
struct V_90 * V_91 ,
struct V_88 * V_88 ,
T_2 V_55 )
{
unsigned long V_92 ;
struct V_2 * V_3 = V_88 -> V_96 ;
if ( F_152 ( V_160 ) )
return;
if ( ! V_91 -> V_92 )
return;
if ( F_153 ( V_160 ) ) {
F_119 ( V_3 , V_91 , V_88 , V_55 ,
V_91 -> V_92 ) ;
return;
}
if ( V_91 -> V_161 < V_162 * 10 )
V_91 -> V_161 ++ ;
if ( V_91 -> V_161 > V_162 )
return;
V_92 = F_154 ( V_91 -> V_92 ) ;
V_91 -> V_17 = F_155 ( long , 0 , V_55 - V_92 / 2 ) ;
V_91 -> V_121 = V_92 ;
V_91 -> V_163 = V_92 / 4 ;
F_156 ( V_91 , V_3 , V_88 ) ;
}
static void F_157 ( struct V_159 * V_160 ,
struct V_90 * V_91 ,
struct V_88 * V_88 ,
struct V_1 * V_1 ,
T_2 V_55 )
{
struct V_2 * V_3 = V_88 -> V_96 ;
if ( F_152 ( V_160 ) )
return;
if ( V_91 -> V_161 > 0 )
V_91 -> V_161 -- ;
if ( F_120 ( V_1 ) )
F_121 ( V_3 , V_91 , V_88 ,
V_1 , V_55 , V_91 -> V_92 ) ;
}
int F_158 ( struct V_159 * V_160 , struct V_164 * V_165 )
{
int error ;
struct V_88 * V_88 = V_160 -> V_166 ;
struct V_2 * V_3 = V_88 -> V_96 ;
struct V_90 * V_91 = & V_88 -> V_98 ;
struct V_97 * V_97 = V_3 -> V_46 ;
T_2 V_55 = V_165 -> V_167 ;
struct V_1 * V_1 ;
T_2 V_121 ;
int V_20 = 0 ;
V_121 = ( F_43 ( V_97 ) + V_103 - 1 ) >> V_32 ;
if ( V_55 >= V_121 )
return V_168 ;
V_1 = F_96 ( V_3 , V_55 ) ;
if ( F_56 ( V_1 ) ) {
F_157 ( V_160 , V_91 , V_88 , V_1 , V_55 ) ;
} else {
F_151 ( V_160 , V_91 , V_88 , V_55 ) ;
F_159 ( V_169 ) ;
F_160 ( V_160 -> V_170 , V_169 ) ;
V_20 = V_171 ;
V_172:
V_1 = F_96 ( V_3 , V_55 ) ;
if ( ! V_1 )
goto V_110;
}
if ( ! F_161 ( V_1 , V_160 -> V_170 , V_165 -> V_42 ) ) {
F_21 ( V_1 ) ;
return V_20 | V_173 ;
}
if ( F_100 ( V_1 -> V_3 != V_3 ) ) {
F_81 ( V_1 ) ;
F_162 ( V_1 ) ;
goto V_172;
}
F_47 ( V_1 -> V_5 != V_55 ) ;
if ( F_100 ( ! F_2 ( V_1 ) ) )
goto V_174;
V_121 = ( F_43 ( V_97 ) + V_103 - 1 ) >> V_32 ;
if ( F_100 ( V_55 >= V_121 ) ) {
F_81 ( V_1 ) ;
F_21 ( V_1 ) ;
return V_168 ;
}
V_165 -> V_1 = V_1 ;
return V_20 | V_175 ;
V_110:
error = F_150 ( V_88 , V_55 ) ;
if ( error >= 0 )
goto V_172;
if ( error == - V_119 )
return V_176 ;
return V_168 ;
V_174:
F_126 ( V_1 ) ;
error = V_3 -> V_12 -> V_117 ( V_88 , V_1 ) ;
if ( ! error ) {
F_95 ( V_1 ) ;
if ( ! F_2 ( V_1 ) )
error = - V_40 ;
}
F_21 ( V_1 ) ;
if ( ! error || error == V_118 )
goto V_172;
F_117 ( V_88 , V_91 ) ;
return V_168 ;
}
int F_163 ( struct V_88 * V_88 , struct V_159 * V_160 )
{
struct V_2 * V_3 = V_88 -> V_96 ;
if ( ! V_3 -> V_12 -> V_117 )
return - V_177 ;
F_128 ( V_88 ) ;
V_160 -> V_178 = & V_179 ;
V_160 -> V_180 |= V_181 ;
return 0 ;
}
int F_164 ( struct V_88 * V_88 , struct V_159 * V_160 )
{
if ( ( V_160 -> V_180 & V_182 ) && ( V_160 -> V_180 & V_183 ) )
return - V_139 ;
return F_163 ( V_88 , V_160 ) ;
}
int F_163 ( struct V_88 * V_88 , struct V_159 * V_160 )
{
return - V_184 ;
}
int F_164 ( struct V_88 * V_88 , struct V_159 * V_160 )
{
return - V_184 ;
}
static struct V_1 * F_165 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_166)( void * , struct V_1 * ) ,
void * V_185 ,
T_3 V_59 )
{
struct V_1 * V_1 ;
int V_47 ;
V_80:
V_1 = F_96 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
V_1 = F_60 ( V_59 | V_186 ) ;
if ( ! V_1 )
return F_167 ( - V_119 ) ;
V_47 = F_57 ( V_1 , V_3 , V_5 , V_59 ) ;
if ( F_100 ( V_47 ) ) {
F_21 ( V_1 ) ;
if ( V_47 == - V_81 )
goto V_80;
return F_167 ( V_47 ) ;
}
V_47 = F_166 ( V_185 , V_1 ) ;
if ( V_47 < 0 ) {
F_21 ( V_1 ) ;
V_1 = F_167 ( V_47 ) ;
}
}
return V_1 ;
}
static struct V_1 * F_168 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_166)( void * , struct V_1 * ) ,
void * V_185 ,
T_3 V_59 )
{
struct V_1 * V_1 ;
int V_47 ;
V_187:
V_1 = F_165 ( V_3 , V_5 , F_166 , V_185 , V_59 ) ;
if ( F_169 ( V_1 ) )
return V_1 ;
if ( F_2 ( V_1 ) )
goto V_58;
F_106 ( V_1 ) ;
if ( ! V_1 -> V_3 ) {
F_81 ( V_1 ) ;
F_21 ( V_1 ) ;
goto V_187;
}
if ( F_2 ( V_1 ) ) {
F_81 ( V_1 ) ;
goto V_58;
}
V_47 = F_166 ( V_185 , V_1 ) ;
if ( V_47 < 0 ) {
F_21 ( V_1 ) ;
return F_167 ( V_47 ) ;
}
V_58:
F_124 ( V_1 ) ;
return V_1 ;
}
struct V_1 * F_170 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_166)( void * , struct V_1 * ) ,
void * V_185 )
{
return F_168 ( V_3 , V_5 , F_166 , V_185 , F_116 ( V_3 ) ) ;
}
static struct V_1 * F_171 ( struct V_1 * V_1 )
{
if ( ! F_169 ( V_1 ) ) {
F_95 ( V_1 ) ;
if ( ! F_2 ( V_1 ) ) {
F_21 ( V_1 ) ;
V_1 = F_167 ( - V_40 ) ;
}
}
return V_1 ;
}
struct V_1 * F_172 ( struct V_2 * V_3 ,
T_2 V_5 ,
T_3 V_59 )
{
T_11 * F_166 = ( T_11 * ) V_3 -> V_12 -> V_117 ;
return F_171 ( F_168 ( V_3 , V_5 , F_166 , NULL , V_59 ) ) ;
}
struct V_1 * F_173 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_166)( void * , struct V_1 * ) ,
void * V_185 )
{
return F_171 ( F_170 ( V_3 , V_5 , F_166 , V_185 ) ) ;
}
int F_174 ( struct V_188 * V_188 )
{
T_12 V_189 = V_188 -> V_190 -> V_191 ;
int V_192 = 0 ;
if ( F_100 ( V_189 & V_193 ) )
V_192 = V_194 ;
if ( F_100 ( ( V_189 & V_195 ) && ( V_189 & V_196 ) ) )
V_192 |= V_197 ;
if ( F_100 ( V_192 && ! F_175 ( V_198 ) && F_176 ( V_189 ) ) )
return V_192 ;
return 0 ;
}
static int F_177 ( struct V_188 * V_188 , int V_192 )
{
struct V_199 V_200 ;
V_200 . V_201 = V_202 | V_192 ;
return F_178 ( V_188 , & V_200 ) ;
}
int F_179 ( struct V_88 * V_88 )
{
struct V_188 * V_188 = V_88 -> V_203 . V_188 ;
struct V_97 * V_97 = V_188 -> V_190 ;
int V_204 ;
int V_205 ;
int error = 0 ;
if ( F_180 ( V_97 ) )
return 0 ;
V_204 = F_174 ( V_188 ) ;
V_205 = F_181 ( V_188 ) ;
if ( V_205 < 0 )
return V_205 ;
if ( V_205 )
error = F_182 ( V_188 ) ;
if ( ! error && V_204 )
error = F_177 ( V_188 , V_204 ) ;
if ( ! error && ( V_97 -> V_206 -> V_207 & V_208 ) )
V_97 -> V_209 |= V_210 ;
return error ;
}
static T_8 F_183 ( char * V_211 ,
const struct V_130 * V_131 , T_8 V_212 , T_8 V_213 )
{
T_8 V_214 = 0 , V_123 = 0 ;
while ( V_213 ) {
char T_13 * V_125 = V_131 -> V_140 + V_212 ;
int V_215 = F_36 ( V_213 , V_131 -> V_137 - V_212 ) ;
V_212 = 0 ;
V_123 = F_184 ( V_211 , V_125 , V_215 ) ;
V_214 += V_215 ;
V_213 -= V_215 ;
V_211 += V_215 ;
V_131 ++ ;
if ( F_100 ( V_123 ) )
break;
}
return V_214 - V_123 ;
}
T_8 F_185 ( struct V_1 * V_1 ,
struct V_216 * V_38 , unsigned long V_55 , T_8 V_213 )
{
char * V_122 ;
T_8 V_214 ;
F_9 ( ! F_186 () ) ;
V_122 = F_131 ( V_1 , V_126 ) ;
if ( F_56 ( V_38 -> V_132 == 1 ) ) {
int V_123 ;
char T_13 * V_125 = V_38 -> V_131 -> V_140 + V_38 -> V_217 ;
V_123 = F_184 ( V_122 + V_55 , V_125 , V_213 ) ;
V_214 = V_213 - V_123 ;
} else {
V_214 = F_183 ( V_122 + V_55 ,
V_38 -> V_131 , V_38 -> V_217 , V_213 ) ;
}
F_133 ( V_122 , V_126 ) ;
return V_214 ;
}
T_8 F_187 ( struct V_1 * V_1 ,
struct V_216 * V_38 , unsigned long V_55 , T_8 V_213 )
{
char * V_122 ;
T_8 V_214 ;
V_122 = F_134 ( V_1 ) ;
if ( F_56 ( V_38 -> V_132 == 1 ) ) {
int V_123 ;
char T_13 * V_125 = V_38 -> V_131 -> V_140 + V_38 -> V_217 ;
V_123 = F_188 ( V_122 + V_55 , V_125 , V_213 ) ;
V_214 = V_213 - V_123 ;
} else {
V_214 = F_183 ( V_122 + V_55 ,
V_38 -> V_131 , V_38 -> V_217 , V_213 ) ;
}
F_136 ( V_1 ) ;
return V_214 ;
}
void F_189 ( struct V_216 * V_38 , T_8 V_213 )
{
F_9 ( V_38 -> V_104 < V_213 ) ;
if ( F_56 ( V_38 -> V_132 == 1 ) ) {
V_38 -> V_217 += V_213 ;
V_38 -> V_104 -= V_213 ;
} else {
const struct V_130 * V_131 = V_38 -> V_131 ;
T_8 V_212 = V_38 -> V_217 ;
unsigned long V_132 = V_38 -> V_132 ;
while ( V_213 || F_100 ( V_38 -> V_104 && ! V_131 -> V_137 ) ) {
int V_215 ;
V_215 = F_36 ( V_213 , V_131 -> V_137 - V_212 ) ;
F_9 ( ! V_38 -> V_104 || V_38 -> V_104 < V_215 ) ;
V_38 -> V_104 -= V_215 ;
V_213 -= V_215 ;
V_212 += V_215 ;
if ( V_131 -> V_137 == V_212 ) {
V_131 ++ ;
V_132 -- ;
V_212 = 0 ;
}
}
V_38 -> V_131 = V_131 ;
V_38 -> V_217 = V_212 ;
V_38 -> V_132 = V_132 ;
}
}
int F_190 ( struct V_216 * V_38 , T_8 V_213 )
{
char T_13 * V_125 = V_38 -> V_131 -> V_140 + V_38 -> V_217 ;
V_213 = F_36 ( V_213 , V_38 -> V_131 -> V_137 - V_38 -> V_217 ) ;
return F_191 ( V_125 , V_213 ) ;
}
T_8 F_192 ( struct V_216 * V_38 )
{
const struct V_130 * V_131 = V_38 -> V_131 ;
if ( V_38 -> V_132 == 1 )
return V_38 -> V_104 ;
else
return F_36 ( V_38 -> V_104 , V_131 -> V_137 - V_38 -> V_217 ) ;
}
inline int F_193 ( struct V_88 * V_88 , T_1 * V_143 , T_8 * V_104 , int V_218 )
{
struct V_97 * V_97 = V_88 -> V_96 -> V_46 ;
unsigned long V_219 = F_194 ( V_220 ) ;
if ( F_100 ( * V_143 < 0 ) )
return - V_139 ;
if ( ! V_218 ) {
if ( V_88 -> V_148 & V_221 )
* V_143 = F_43 ( V_97 ) ;
if ( V_219 != V_222 ) {
if ( * V_143 >= V_219 ) {
F_195 ( V_223 , V_15 , 0 ) ;
return - V_224 ;
}
if ( * V_104 > V_219 - ( F_196 ( V_219 ) ) * V_143 ) {
* V_104 = V_219 - ( F_196 ( V_219 ) ) * V_143 ;
}
}
}
if ( F_100 ( * V_143 + * V_104 > V_225 &&
! ( V_88 -> V_148 & V_226 ) ) ) {
if ( * V_143 >= V_225 ) {
return - V_224 ;
}
if ( * V_104 > V_225 - ( unsigned long ) * V_143 ) {
* V_104 = V_225 - ( unsigned long ) * V_143 ;
}
}
if ( F_56 ( ! V_218 ) ) {
if ( F_100 ( * V_143 >= V_97 -> V_206 -> V_227 ) ) {
if ( * V_104 || * V_143 > V_97 -> V_206 -> V_227 ) {
return - V_224 ;
}
}
if ( F_100 ( * V_143 + * V_104 > V_97 -> V_206 -> V_227 ) )
* V_104 = V_97 -> V_206 -> V_227 - * V_143 ;
} else {
#ifdef F_197
T_1 V_107 ;
if ( F_198 ( F_199 ( V_97 ) ) )
return - V_228 ;
V_107 = F_43 ( V_97 ) ;
if ( * V_143 >= V_107 ) {
if ( * V_104 || * V_143 > V_107 )
return - V_43 ;
}
if ( * V_143 + * V_104 > V_107 )
* V_104 = V_107 - * V_143 ;
#else
return - V_228 ;
#endif
}
return 0 ;
}
int F_200 ( struct V_88 * V_88 , struct V_2 * V_3 ,
T_1 V_143 , unsigned V_158 , unsigned V_42 ,
struct V_1 * * V_79 , void * * V_229 )
{
const struct V_230 * V_231 = V_3 -> V_12 ;
return V_231 -> V_232 ( V_88 , V_3 , V_143 , V_158 , V_42 ,
V_79 , V_229 ) ;
}
int F_201 ( struct V_88 * V_88 , struct V_2 * V_3 ,
T_1 V_143 , unsigned V_158 , unsigned V_214 ,
struct V_1 * V_1 , void * V_229 )
{
const struct V_230 * V_231 = V_3 -> V_12 ;
F_124 ( V_1 ) ;
return V_231 -> V_233 ( V_88 , V_3 , V_143 , V_158 , V_214 , V_1 , V_229 ) ;
}
V_138
F_202 ( struct V_141 * V_142 , const struct V_130 * V_131 ,
unsigned long * V_132 , T_1 V_143 , T_1 * V_93 ,
T_8 V_104 , T_8 V_234 )
{
struct V_88 * V_88 = V_142 -> V_144 ;
struct V_2 * V_3 = V_88 -> V_96 ;
struct V_97 * V_97 = V_3 -> V_46 ;
V_138 V_129 ;
T_8 V_235 ;
T_2 V_18 ;
if ( V_104 != V_234 )
* V_132 = F_203 ( (struct V_130 * ) V_131 , * V_132 , V_104 ) ;
V_235 = F_140 ( V_131 , * V_132 ) ;
V_18 = ( V_143 + V_235 - 1 ) >> V_32 ;
V_129 = F_45 ( V_3 , V_143 , V_143 + V_235 - 1 ) ;
if ( V_129 )
goto V_58;
if ( V_3 -> V_6 ) {
V_129 = F_204 ( V_3 ,
V_143 >> V_32 , V_18 ) ;
if ( V_129 ) {
if ( V_129 == - V_236 )
return 0 ;
goto V_58;
}
}
V_129 = V_3 -> V_12 -> V_152 ( V_237 , V_142 , V_131 , V_143 , * V_132 ) ;
if ( V_3 -> V_6 ) {
F_204 ( V_3 ,
V_143 >> V_32 , V_18 ) ;
}
if ( V_129 > 0 ) {
V_143 += V_129 ;
if ( V_143 > F_43 ( V_97 ) && ! F_205 ( V_97 -> V_191 ) ) {
F_206 ( V_97 , V_143 ) ;
F_207 ( V_97 ) ;
}
* V_93 = V_143 ;
}
V_58:
return V_129 ;
}
struct V_1 * F_208 ( struct V_2 * V_3 ,
T_2 V_5 , unsigned V_42 )
{
int V_238 ;
T_3 V_53 ;
struct V_1 * V_1 ;
T_3 V_239 = 0 ;
V_53 = F_116 ( V_3 ) | V_240 ;
if ( V_42 & V_241 )
V_239 = V_86 ;
V_80:
V_1 = F_105 ( V_3 , V_5 ) ;
if ( V_1 )
goto V_242;
V_1 = F_60 ( V_53 & ~ V_239 ) ;
if ( ! V_1 )
return NULL ;
V_238 = F_57 ( V_1 , V_3 , V_5 ,
V_120 & ~ V_239 ) ;
if ( F_100 ( V_238 ) ) {
F_21 ( V_1 ) ;
if ( V_238 == - V_81 )
goto V_80;
return NULL ;
}
V_242:
F_37 ( V_1 ) ;
return V_1 ;
}
static V_138 F_209 ( struct V_88 * V_88 ,
struct V_216 * V_38 , T_1 V_143 )
{
struct V_2 * V_3 = V_88 -> V_96 ;
const struct V_230 * V_12 = V_3 -> V_12 ;
long V_238 = 0 ;
V_138 V_129 = 0 ;
unsigned int V_42 = 0 ;
if ( F_210 ( F_211 () , V_243 ) )
V_42 |= V_244 ;
do {
struct V_1 * V_1 ;
unsigned long V_55 ;
unsigned long V_213 ;
T_8 V_214 ;
void * V_229 ;
V_55 = ( V_143 & ( V_103 - 1 ) ) ;
V_213 = F_212 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_count(i)) ;
V_245:
if ( F_100 ( F_190 ( V_38 , V_213 ) ) ) {
V_238 = - V_128 ;
break;
}
V_238 = V_12 -> V_232 ( V_88 , V_3 , V_143 , V_213 , V_42 ,
& V_1 , & V_229 ) ;
if ( F_100 ( V_238 ) )
break;
if ( F_122 ( V_3 ) )
F_123 ( V_1 ) ;
F_213 () ;
V_214 = F_185 ( V_1 , V_38 , V_55 , V_213 ) ;
F_214 () ;
F_123 ( V_1 ) ;
F_124 ( V_1 ) ;
V_238 = V_12 -> V_233 ( V_88 , V_3 , V_143 , V_213 , V_214 ,
V_1 , V_229 ) ;
if ( F_100 ( V_238 < 0 ) )
break;
V_214 = V_238 ;
F_40 () ;
F_189 ( V_38 , V_214 ) ;
if ( F_100 ( V_214 == 0 ) ) {
V_213 = F_212 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_245;
}
V_143 += V_214 ;
V_129 += V_214 ;
F_215 ( V_3 ) ;
if ( F_25 ( V_15 ) ) {
V_238 = - V_16 ;
break;
}
} while ( F_216 ( V_38 ) );
return V_129 ? V_129 : V_238 ;
}
V_138
F_217 ( struct V_141 * V_142 , const struct V_130 * V_131 ,
unsigned long V_132 , T_1 V_143 , T_1 * V_93 ,
T_8 V_104 , V_138 V_129 )
{
struct V_88 * V_88 = V_142 -> V_144 ;
V_138 V_238 ;
struct V_216 V_38 ;
F_218 ( & V_38 , V_131 , V_132 , V_104 , V_129 ) ;
V_238 = F_209 ( V_88 , & V_38 , V_143 ) ;
if ( F_56 ( V_238 >= 0 ) ) {
V_129 += V_238 ;
* V_93 = V_143 + V_238 ;
}
return V_129 ? V_129 : V_238 ;
}
V_138 F_219 ( struct V_141 * V_142 , const struct V_130 * V_131 ,
unsigned long V_132 , T_1 * V_93 )
{
struct V_88 * V_88 = V_142 -> V_144 ;
struct V_2 * V_3 = V_88 -> V_96 ;
T_8 V_234 ;
T_8 V_104 ;
struct V_97 * V_97 = V_3 -> V_46 ;
T_1 V_143 ;
V_138 V_129 ;
V_138 V_47 ;
V_234 = 0 ;
V_47 = F_137 ( V_131 , & V_132 , & V_234 , V_246 ) ;
if ( V_47 )
return V_47 ;
V_104 = V_234 ;
V_143 = * V_93 ;
F_220 ( V_97 -> V_206 , V_247 ) ;
V_15 -> V_10 = V_3 -> V_10 ;
V_129 = 0 ;
V_47 = F_193 ( V_88 , & V_143 , & V_104 , F_205 ( V_97 -> V_191 ) ) ;
if ( V_47 )
goto V_58;
if ( V_104 == 0 )
goto V_58;
V_47 = F_179 ( V_88 ) ;
if ( V_47 )
goto V_58;
F_221 ( V_88 ) ;
if ( F_100 ( V_88 -> V_148 & V_149 ) ) {
T_1 V_248 ;
V_138 V_249 ;
V_129 = F_202 ( V_142 , V_131 , & V_132 , V_143 ,
V_93 , V_104 , V_234 ) ;
if ( V_129 < 0 || V_129 == V_104 )
goto V_58;
V_143 += V_129 ;
V_104 -= V_129 ;
V_249 = F_217 ( V_142 , V_131 ,
V_132 , V_143 , V_93 , V_104 ,
V_129 ) ;
if ( V_249 < 0 ) {
V_47 = V_249 ;
goto V_58;
}
V_248 = V_143 + V_249 - V_129 - 1 ;
V_47 = F_45 ( V_88 -> V_96 , V_143 , V_248 ) ;
if ( V_47 == 0 ) {
V_129 = V_249 ;
F_222 ( V_3 ,
V_143 >> V_32 ,
V_248 >> V_32 ) ;
} else {
}
} else {
V_129 = F_217 ( V_142 , V_131 , V_132 ,
V_143 , V_93 , V_104 , V_129 ) ;
}
V_58:
V_15 -> V_10 = NULL ;
return V_129 ? V_129 : V_47 ;
}
V_138 F_223 ( struct V_141 * V_142 , const struct V_130 * V_131 ,
unsigned long V_132 , T_1 V_143 )
{
struct V_88 * V_88 = V_142 -> V_144 ;
struct V_97 * V_97 = V_88 -> V_96 -> V_46 ;
struct V_150 V_151 ;
V_138 V_20 ;
F_9 ( V_142 -> V_146 != V_143 ) ;
F_224 ( & V_97 -> V_250 ) ;
F_141 ( & V_151 ) ;
V_20 = F_219 ( V_142 , V_131 , V_132 , & V_142 -> V_146 ) ;
F_225 ( & V_97 -> V_250 ) ;
if ( V_20 > 0 || V_20 == - V_251 ) {
V_138 V_47 ;
V_47 = F_226 ( V_88 , V_143 , V_20 ) ;
if ( V_47 < 0 && V_20 > 0 )
V_20 = V_47 ;
}
F_142 ( & V_151 ) ;
return V_20 ;
}
int F_227 ( struct V_1 * V_1 , T_3 V_53 )
{
struct V_2 * const V_3 = V_1 -> V_3 ;
F_9 ( ! F_17 ( V_1 ) ) ;
if ( F_228 ( V_1 ) )
return 0 ;
if ( V_3 && V_3 -> V_12 -> V_252 )
return V_3 -> V_12 -> V_252 ( V_1 , V_53 ) ;
return F_229 ( V_1 ) ;
}
