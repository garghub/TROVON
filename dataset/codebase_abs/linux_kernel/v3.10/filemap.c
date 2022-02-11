void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
F_2 ( V_1 ) ;
if ( F_3 ( V_1 ) && F_4 ( V_1 ) )
F_5 ( V_1 ) ;
else
F_6 ( V_3 , V_1 ) ;
F_7 ( & V_3 -> V_4 , V_1 -> V_5 ) ;
V_1 -> V_3 = NULL ;
V_3 -> V_6 -- ;
F_8 ( V_1 , V_7 ) ;
if ( F_9 ( V_1 ) )
F_8 ( V_1 , V_8 ) ;
F_10 ( F_11 ( V_1 ) ) ;
if ( F_12 ( V_1 ) && F_13 ( V_3 ) ) {
F_14 ( V_1 , V_9 ) ;
F_15 ( V_3 -> V_10 , V_11 ) ;
}
}
void F_16 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
void (* F_17)( struct V_1 * );
F_10 ( ! F_18 ( V_1 ) ) ;
F_17 = V_3 -> V_12 -> F_17 ;
F_19 ( & V_3 -> V_13 ) ;
F_1 ( V_1 ) ;
F_20 ( & V_3 -> V_13 ) ;
F_21 ( V_1 ) ;
if ( F_17 )
F_17 ( V_1 ) ;
F_22 ( V_1 ) ;
}
static int F_23 ( void * V_14 )
{
F_24 () ;
return 0 ;
}
static int F_25 ( void * V_14 )
{
F_23 ( V_14 ) ;
return F_26 ( V_15 ) ? - V_16 : 0 ;
}
static int F_27 ( struct V_2 * V_3 )
{
int V_17 = 0 ;
if ( F_28 ( V_18 , & V_3 -> V_19 ) )
V_17 = - V_20 ;
if ( F_28 ( V_21 , & V_3 -> V_19 ) )
V_17 = - V_22 ;
return V_17 ;
}
int F_29 ( struct V_2 * V_3 , T_1 V_23 ,
T_1 V_24 , int V_25 )
{
int V_17 ;
struct V_26 V_27 = {
. V_25 = V_25 ,
. V_28 = V_29 ,
. V_30 = V_23 ,
. V_31 = V_24 ,
} ;
if ( ! F_30 ( V_3 ) )
return 0 ;
V_17 = F_31 ( V_3 , & V_27 ) ;
return V_17 ;
}
static inline int F_32 ( struct V_2 * V_3 ,
int V_25 )
{
return F_29 ( V_3 , 0 , V_32 , V_25 ) ;
}
int F_33 ( struct V_2 * V_3 )
{
return F_32 ( V_3 , V_33 ) ;
}
int F_34 ( struct V_2 * V_3 , T_1 V_23 ,
T_1 V_24 )
{
return F_29 ( V_3 , V_23 , V_24 , V_33 ) ;
}
int F_35 ( struct V_2 * V_3 )
{
return F_32 ( V_3 , V_34 ) ;
}
int F_36 ( struct V_2 * V_3 , T_1 V_35 ,
T_1 V_36 )
{
T_2 V_5 = V_35 >> V_37 ;
T_2 V_24 = V_36 >> V_37 ;
struct V_38 V_39 ;
int V_40 ;
int V_41 , V_17 = 0 ;
if ( V_36 < V_35 )
goto V_42;
F_37 ( & V_39 , 0 ) ;
while ( ( V_5 <= V_24 ) &&
( V_40 = F_38 ( & V_39 , V_3 , & V_5 ,
V_43 ,
F_39 ( V_24 - V_5 , ( T_2 ) V_44 - 1 ) + 1 ) ) != 0 ) {
unsigned V_45 ;
for ( V_45 = 0 ; V_45 < V_40 ; V_45 ++ ) {
struct V_1 * V_1 = V_39 . V_46 [ V_45 ] ;
if ( V_1 -> V_5 > V_24 )
continue;
F_40 ( V_1 ) ;
if ( F_41 ( V_1 ) )
V_17 = - V_22 ;
}
F_42 ( & V_39 ) ;
F_43 () ;
}
V_42:
V_41 = F_27 ( V_3 ) ;
if ( ! V_17 )
V_17 = V_41 ;
return V_17 ;
}
int F_44 ( struct V_2 * V_3 )
{
T_1 V_47 = F_45 ( V_3 -> V_48 ) ;
if ( V_47 == 0 )
return 0 ;
return F_36 ( V_3 , 0 , V_47 - 1 ) ;
}
int F_46 ( struct V_2 * V_3 )
{
int V_49 = 0 ;
if ( V_3 -> V_6 ) {
V_49 = F_33 ( V_3 ) ;
if ( V_49 != - V_22 ) {
int V_50 = F_44 ( V_3 ) ;
if ( ! V_49 )
V_49 = V_50 ;
}
} else {
V_49 = F_27 ( V_3 ) ;
}
return V_49 ;
}
int F_47 ( struct V_2 * V_3 ,
T_1 V_51 , T_1 V_52 )
{
int V_49 = 0 ;
if ( V_3 -> V_6 ) {
V_49 = F_29 ( V_3 , V_51 , V_52 ,
V_33 ) ;
if ( V_49 != - V_22 ) {
int V_50 = F_36 ( V_3 ,
V_51 , V_52 ) ;
if ( ! V_49 )
V_49 = V_50 ;
}
} else {
V_49 = F_27 ( V_3 ) ;
}
return V_49 ;
}
int F_48 ( struct V_1 * V_53 , struct V_1 * V_54 , T_3 V_55 )
{
int error ;
F_49 ( ! F_18 ( V_53 ) ) ;
F_49 ( ! F_18 ( V_54 ) ) ;
F_49 ( V_54 -> V_3 ) ;
error = F_50 ( V_55 & ~ V_56 ) ;
if ( ! error ) {
struct V_2 * V_3 = V_53 -> V_3 ;
void (* F_17)( struct V_1 * );
T_2 V_57 = V_53 -> V_5 ;
F_17 = V_3 -> V_12 -> F_17 ;
F_51 ( V_54 ) ;
V_54 -> V_3 = V_3 ;
V_54 -> V_5 = V_57 ;
F_19 ( & V_3 -> V_13 ) ;
F_1 ( V_53 ) ;
error = F_52 ( & V_3 -> V_4 , V_57 , V_54 ) ;
F_10 ( error ) ;
V_3 -> V_6 ++ ;
F_53 ( V_54 , V_7 ) ;
if ( F_9 ( V_54 ) )
F_53 ( V_54 , V_8 ) ;
F_20 ( & V_3 -> V_13 ) ;
F_54 ( V_53 , V_54 ) ;
F_55 () ;
if ( F_17 )
F_17 ( V_53 ) ;
F_22 ( V_53 ) ;
}
return error ;
}
int F_56 ( struct V_1 * V_1 , struct V_2 * V_3 ,
T_2 V_57 , T_3 V_55 )
{
int error ;
F_49 ( ! F_18 ( V_1 ) ) ;
F_49 ( F_9 ( V_1 ) ) ;
error = F_57 ( V_1 , V_15 -> V_58 ,
V_55 & V_59 ) ;
if ( error )
goto V_42;
error = F_50 ( V_55 & ~ V_56 ) ;
if ( error == 0 ) {
F_51 ( V_1 ) ;
V_1 -> V_3 = V_3 ;
V_1 -> V_5 = V_57 ;
F_19 ( & V_3 -> V_13 ) ;
error = F_52 ( & V_3 -> V_4 , V_57 , V_1 ) ;
if ( F_58 ( ! error ) ) {
V_3 -> V_6 ++ ;
F_53 ( V_1 , V_7 ) ;
F_20 ( & V_3 -> V_13 ) ;
F_59 ( V_1 ) ;
} else {
V_1 -> V_3 = NULL ;
F_20 ( & V_3 -> V_13 ) ;
F_21 ( V_1 ) ;
F_22 ( V_1 ) ;
}
F_55 () ;
} else
F_21 ( V_1 ) ;
V_42:
return error ;
}
int F_60 ( struct V_1 * V_1 , struct V_2 * V_3 ,
T_2 V_57 , T_3 V_55 )
{
int V_17 ;
V_17 = F_61 ( V_1 , V_3 , V_57 , V_55 ) ;
if ( V_17 == 0 )
F_62 ( V_1 ) ;
return V_17 ;
}
struct V_1 * F_63 ( T_3 V_60 )
{
int V_61 ;
struct V_1 * V_1 ;
if ( F_64 () ) {
unsigned int V_62 ;
do {
V_62 = F_65 () ;
V_61 = F_66 () ;
V_1 = F_67 ( V_61 , V_60 , 0 ) ;
} while ( ! F_68 ( V_62 ) && ! V_1 );
return V_1 ;
}
return F_69 ( V_60 , 0 ) ;
}
static T_4 * F_70 ( struct V_1 * V_1 )
{
const struct V_63 * V_63 = F_71 ( V_1 ) ;
return & V_63 -> V_64 [ F_72 ( V_1 , V_63 -> V_65 ) ] ;
}
static inline void F_73 ( struct V_1 * V_1 , int V_66 )
{
F_74 ( F_70 ( V_1 ) , & V_1 -> V_19 , V_66 ) ;
}
void F_75 ( struct V_1 * V_1 , int V_67 )
{
F_76 ( V_68 , & V_1 -> V_19 , V_67 ) ;
if ( F_77 ( V_67 , & V_1 -> V_19 ) )
F_78 ( F_70 ( V_1 ) , & V_68 , F_23 ,
V_69 ) ;
}
int F_79 ( struct V_1 * V_1 , int V_67 )
{
F_76 ( V_68 , & V_1 -> V_19 , V_67 ) ;
if ( ! F_77 ( V_67 , & V_1 -> V_19 ) )
return 0 ;
return F_78 ( F_70 ( V_1 ) , & V_68 ,
F_25 , V_70 ) ;
}
void F_80 ( struct V_1 * V_1 , T_5 * V_71 )
{
T_4 * V_72 = F_70 ( V_1 ) ;
unsigned long V_19 ;
F_81 ( & V_72 -> V_73 , V_19 ) ;
F_82 ( V_72 , V_71 ) ;
F_83 ( & V_72 -> V_73 , V_19 ) ;
}
void F_84 ( struct V_1 * V_1 )
{
F_49 ( ! F_18 ( V_1 ) ) ;
F_85 ( V_74 , & V_1 -> V_19 ) ;
F_86 () ;
F_73 ( V_1 , V_74 ) ;
}
void F_87 ( struct V_1 * V_1 )
{
if ( F_88 ( V_1 ) )
F_89 ( V_1 ) ;
if ( ! F_90 ( V_1 ) )
F_91 () ;
F_86 () ;
F_73 ( V_1 , V_75 ) ;
}
void F_92 ( struct V_1 * V_1 )
{
F_76 ( V_68 , & V_1 -> V_19 , V_74 ) ;
F_93 ( F_70 ( V_1 ) , & V_68 , F_23 ,
V_69 ) ;
}
int F_94 ( struct V_1 * V_1 )
{
F_76 ( V_68 , & V_1 -> V_19 , V_74 ) ;
return F_93 ( F_70 ( V_1 ) , & V_68 ,
F_25 , V_70 ) ;
}
int F_95 ( struct V_1 * V_1 , struct V_76 * V_58 ,
unsigned int V_19 )
{
if ( V_19 & V_77 ) {
if ( V_19 & V_78 )
return 0 ;
F_96 ( & V_58 -> V_79 ) ;
if ( V_19 & V_80 )
F_97 ( V_1 ) ;
else
F_98 ( V_1 ) ;
return 0 ;
} else {
if ( V_19 & V_80 ) {
int V_17 ;
V_17 = F_94 ( V_1 ) ;
if ( V_17 ) {
F_96 ( & V_58 -> V_79 ) ;
return 0 ;
}
} else
F_92 ( V_1 ) ;
return 1 ;
}
}
struct V_1 * F_99 ( struct V_2 * V_3 , T_2 V_57 )
{
void * * V_81 ;
struct V_1 * V_1 ;
F_100 () ;
V_82:
V_1 = NULL ;
V_81 = F_101 ( & V_3 -> V_4 , V_57 ) ;
if ( V_81 ) {
V_1 = F_102 ( V_81 ) ;
if ( F_103 ( ! V_1 ) )
goto V_42;
if ( F_104 ( V_1 ) ) {
if ( F_105 ( V_1 ) )
goto V_82;
goto V_42;
}
if ( ! F_106 ( V_1 ) )
goto V_82;
if ( F_103 ( V_1 != * V_81 ) ) {
F_22 ( V_1 ) ;
goto V_82;
}
}
V_42:
F_107 () ;
return V_1 ;
}
struct V_1 * F_108 ( struct V_2 * V_3 , T_2 V_57 )
{
struct V_1 * V_1 ;
V_82:
V_1 = F_99 ( V_3 , V_57 ) ;
if ( V_1 && ! F_104 ( V_1 ) ) {
F_109 ( V_1 ) ;
if ( F_103 ( V_1 -> V_3 != V_3 ) ) {
F_84 ( V_1 ) ;
F_22 ( V_1 ) ;
goto V_82;
}
F_49 ( V_1 -> V_5 != V_57 ) ;
}
return V_1 ;
}
struct V_1 * F_110 ( struct V_2 * V_3 ,
T_2 V_5 , T_3 V_55 )
{
struct V_1 * V_1 ;
int V_49 ;
V_82:
V_1 = F_108 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
V_1 = F_63 ( V_55 ) ;
if ( ! V_1 )
return NULL ;
V_49 = F_60 ( V_1 , V_3 , V_5 ,
( V_55 & V_59 ) ) ;
if ( F_103 ( V_49 ) ) {
F_22 ( V_1 ) ;
V_1 = NULL ;
if ( V_49 == - V_83 )
goto V_82;
}
}
return V_1 ;
}
unsigned F_111 ( struct V_2 * V_3 , T_2 V_23 ,
unsigned int V_40 , struct V_1 * * V_46 )
{
struct V_84 V_85 ;
void * * V_86 ;
unsigned V_17 = 0 ;
if ( F_103 ( ! V_40 ) )
return 0 ;
F_100 () ;
V_87:
F_112 (slot, &mapping->page_tree, &iter, start) {
struct V_1 * V_1 ;
V_82:
V_1 = F_102 ( V_86 ) ;
if ( F_103 ( ! V_1 ) )
continue;
if ( F_104 ( V_1 ) ) {
if ( F_105 ( V_1 ) ) {
F_113 ( V_85 . V_5 ) ;
goto V_87;
}
continue;
}
if ( ! F_106 ( V_1 ) )
goto V_82;
if ( F_103 ( V_1 != * V_86 ) ) {
F_22 ( V_1 ) ;
goto V_82;
}
V_46 [ V_17 ] = V_1 ;
if ( ++ V_17 == V_40 )
break;
}
F_107 () ;
return V_17 ;
}
unsigned F_114 ( struct V_2 * V_3 , T_2 V_5 ,
unsigned int V_40 , struct V_1 * * V_46 )
{
struct V_84 V_85 ;
void * * V_86 ;
unsigned int V_17 = 0 ;
if ( F_103 ( ! V_40 ) )
return 0 ;
F_100 () ;
V_87:
F_115 (slot, &mapping->page_tree, &iter, index) {
struct V_1 * V_1 ;
V_82:
V_1 = F_102 ( V_86 ) ;
if ( F_103 ( ! V_1 ) )
break;
if ( F_104 ( V_1 ) ) {
if ( F_105 ( V_1 ) ) {
goto V_87;
}
break;
}
if ( ! F_106 ( V_1 ) )
goto V_82;
if ( F_103 ( V_1 != * V_86 ) ) {
F_22 ( V_1 ) ;
goto V_82;
}
if ( V_1 -> V_3 == NULL || V_1 -> V_5 != V_85 . V_5 ) {
F_22 ( V_1 ) ;
break;
}
V_46 [ V_17 ] = V_1 ;
if ( ++ V_17 == V_40 )
break;
}
F_107 () ;
return V_17 ;
}
unsigned F_116 ( struct V_2 * V_3 , T_2 * V_5 ,
int V_88 , unsigned int V_40 , struct V_1 * * V_46 )
{
struct V_84 V_85 ;
void * * V_86 ;
unsigned V_17 = 0 ;
if ( F_103 ( ! V_40 ) )
return 0 ;
F_100 () ;
V_87:
F_117 (slot, &mapping->page_tree,
&iter, *index, tag) {
struct V_1 * V_1 ;
V_82:
V_1 = F_102 ( V_86 ) ;
if ( F_103 ( ! V_1 ) )
continue;
if ( F_104 ( V_1 ) ) {
if ( F_105 ( V_1 ) ) {
goto V_87;
}
F_91 () ;
}
if ( ! F_106 ( V_1 ) )
goto V_82;
if ( F_103 ( V_1 != * V_86 ) ) {
F_22 ( V_1 ) ;
goto V_82;
}
V_46 [ V_17 ] = V_1 ;
if ( ++ V_17 == V_40 )
break;
}
F_107 () ;
if ( V_17 )
* V_5 = V_46 [ V_17 - 1 ] -> V_5 + 1 ;
return V_17 ;
}
struct V_1 *
F_118 ( struct V_2 * V_3 , T_2 V_5 )
{
struct V_1 * V_1 = F_99 ( V_3 , V_5 ) ;
if ( V_1 ) {
if ( F_119 ( V_1 ) )
return V_1 ;
F_22 ( V_1 ) ;
return NULL ;
}
V_1 = F_63 ( F_120 ( V_3 ) & ~ V_89 ) ;
if ( V_1 && F_60 ( V_1 , V_3 , V_5 , V_90 ) ) {
F_22 ( V_1 ) ;
V_1 = NULL ;
}
return V_1 ;
}
static void F_121 ( struct V_91 * V_92 ,
struct V_93 * V_94 )
{
V_94 -> V_95 /= 4 ;
}
static void F_122 ( struct V_91 * V_92 , T_1 * V_96 ,
T_6 * V_97 , T_7 V_98 )
{
struct V_2 * V_3 = V_92 -> V_99 ;
struct V_100 * V_100 = V_3 -> V_48 ;
struct V_93 * V_94 = & V_92 -> V_101 ;
T_2 V_5 ;
T_2 V_102 ;
T_2 V_103 ;
unsigned long V_57 ;
unsigned int V_104 ;
int error ;
V_5 = * V_96 >> V_37 ;
V_103 = V_94 -> V_105 >> V_37 ;
V_104 = V_94 -> V_105 & ( V_106 - 1 ) ;
V_102 = ( * V_96 + V_97 -> V_107 + V_106 - 1 ) >> V_37 ;
V_57 = * V_96 & ~ V_108 ;
for (; ; ) {
struct V_1 * V_1 ;
T_2 V_109 ;
T_1 V_110 ;
unsigned long V_111 , V_17 ;
F_43 () ;
V_112:
V_1 = F_99 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
F_123 ( V_3 ,
V_94 , V_92 ,
V_5 , V_102 - V_5 ) ;
V_1 = F_99 ( V_3 , V_5 ) ;
if ( F_103 ( V_1 == NULL ) )
goto V_113;
}
if ( F_124 ( V_1 ) ) {
F_125 ( V_3 ,
V_94 , V_92 , V_1 ,
V_5 , V_102 - V_5 ) ;
}
if ( ! F_3 ( V_1 ) ) {
if ( V_100 -> V_114 == V_37 ||
! V_3 -> V_12 -> V_115 )
goto V_116;
if ( ! F_119 ( V_1 ) )
goto V_116;
if ( ! V_1 -> V_3 )
goto V_117;
if ( ! V_3 -> V_12 -> V_115 ( V_1 ,
V_97 , V_57 ) )
goto V_117;
F_84 ( V_1 ) ;
}
V_118:
V_110 = F_45 ( V_100 ) ;
V_109 = ( V_110 - 1 ) >> V_37 ;
if ( F_103 ( ! V_110 || V_5 > V_109 ) ) {
F_22 ( V_1 ) ;
goto V_42;
}
V_111 = V_106 ;
if ( V_5 == V_109 ) {
V_111 = ( ( V_110 - 1 ) & ~ V_108 ) + 1 ;
if ( V_111 <= V_57 ) {
F_22 ( V_1 ) ;
goto V_42;
}
}
V_111 = V_111 - V_57 ;
if ( F_126 ( V_3 ) )
F_127 ( V_1 ) ;
if ( V_103 != V_5 || V_57 != V_104 )
F_128 ( V_1 ) ;
V_103 = V_5 ;
V_17 = V_98 ( V_97 , V_1 , V_57 , V_111 ) ;
V_57 += V_17 ;
V_5 += V_57 >> V_37 ;
V_57 &= ~ V_108 ;
V_104 = V_57 ;
F_22 ( V_1 ) ;
if ( V_17 == V_111 && V_97 -> V_107 )
continue;
goto V_42;
V_116:
error = F_129 ( V_1 ) ;
if ( F_103 ( error ) )
goto V_119;
V_117:
if ( ! V_1 -> V_3 ) {
F_84 ( V_1 ) ;
F_22 ( V_1 ) ;
continue;
}
if ( F_3 ( V_1 ) ) {
F_84 ( V_1 ) ;
goto V_118;
}
V_120:
F_130 ( V_1 ) ;
error = V_3 -> V_12 -> V_120 ( V_92 , V_1 ) ;
if ( F_103 ( error ) ) {
if ( error == V_121 ) {
F_22 ( V_1 ) ;
goto V_112;
}
goto V_119;
}
if ( ! F_3 ( V_1 ) ) {
error = F_129 ( V_1 ) ;
if ( F_103 ( error ) )
goto V_119;
if ( ! F_3 ( V_1 ) ) {
if ( V_1 -> V_3 == NULL ) {
F_84 ( V_1 ) ;
F_22 ( V_1 ) ;
goto V_112;
}
F_84 ( V_1 ) ;
F_121 ( V_92 , V_94 ) ;
error = - V_22 ;
goto V_119;
}
F_84 ( V_1 ) ;
}
goto V_118;
V_119:
V_97 -> error = error ;
F_22 ( V_1 ) ;
goto V_42;
V_113:
V_1 = F_131 ( V_3 ) ;
if ( ! V_1 ) {
V_97 -> error = - V_122 ;
goto V_42;
}
error = F_60 ( V_1 , V_3 ,
V_5 , V_123 ) ;
if ( error ) {
F_22 ( V_1 ) ;
if ( error == - V_83 )
goto V_112;
V_97 -> error = error ;
goto V_42;
}
goto V_120;
}
V_42:
V_94 -> V_105 = V_103 ;
V_94 -> V_105 <<= V_37 ;
V_94 -> V_105 |= V_104 ;
* V_96 = ( ( T_1 ) V_5 << V_37 ) + V_57 ;
F_132 ( V_92 ) ;
}
int F_133 ( T_6 * V_97 , struct V_1 * V_1 ,
unsigned long V_57 , unsigned long V_124 )
{
char * V_125 ;
unsigned long V_126 , V_107 = V_97 -> V_107 ;
if ( V_124 > V_107 )
V_124 = V_107 ;
if ( ! F_134 ( V_97 -> V_127 . V_128 , V_124 ) ) {
V_125 = F_135 ( V_1 ) ;
V_126 = F_136 ( V_97 -> V_127 . V_128 ,
V_125 + V_57 , V_124 ) ;
F_137 ( V_125 ) ;
if ( V_126 == 0 )
goto V_129;
}
V_125 = F_138 ( V_1 ) ;
V_126 = F_139 ( V_97 -> V_127 . V_128 , V_125 + V_57 , V_124 ) ;
F_140 ( V_1 ) ;
if ( V_126 ) {
V_124 -= V_126 ;
V_97 -> error = - V_130 ;
}
V_129:
V_97 -> V_107 = V_107 - V_124 ;
V_97 -> V_131 += V_124 ;
V_97 -> V_127 . V_128 += V_124 ;
return V_124 ;
}
int F_141 ( const struct V_132 * V_133 ,
unsigned long * V_134 , T_8 * V_107 , int V_135 )
{
unsigned long V_136 ;
T_8 V_137 = 0 ;
for ( V_136 = 0 ; V_136 < * V_134 ; V_136 ++ ) {
const struct V_132 * V_138 = & V_133 [ V_136 ] ;
V_137 += V_138 -> V_139 ;
if ( F_103 ( ( V_140 ) ( V_137 | V_138 -> V_139 ) < 0 ) )
return - V_141 ;
if ( F_142 ( V_135 , V_138 -> V_142 , V_138 -> V_139 ) )
continue;
if ( V_136 == 0 )
return - V_130 ;
* V_134 = V_136 ;
V_137 -= V_138 -> V_139 ;
break;
}
* V_107 = V_137 ;
return 0 ;
}
V_140
F_143 ( struct V_143 * V_144 , const struct V_132 * V_133 ,
unsigned long V_134 , T_1 V_145 )
{
struct V_91 * V_92 = V_144 -> V_146 ;
V_140 V_147 ;
unsigned long V_136 = 0 ;
T_8 V_107 ;
T_1 * V_96 = & V_144 -> V_148 ;
V_107 = 0 ;
V_147 = F_141 ( V_133 , & V_134 , & V_107 , V_149 ) ;
if ( V_147 )
return V_147 ;
if ( V_92 -> V_150 & V_151 ) {
T_1 V_124 ;
struct V_2 * V_3 ;
struct V_100 * V_100 ;
V_3 = V_92 -> V_99 ;
V_100 = V_3 -> V_48 ;
if ( ! V_107 )
goto V_42;
V_124 = F_45 ( V_100 ) ;
if ( V_145 < V_124 ) {
V_147 = F_47 ( V_3 , V_145 ,
V_145 + F_144 ( V_133 , V_134 ) - 1 ) ;
if ( ! V_147 ) {
V_147 = V_3 -> V_12 -> V_152 ( V_153 , V_144 ,
V_133 , V_145 , V_134 ) ;
}
if ( V_147 > 0 ) {
* V_96 = V_145 + V_147 ;
V_107 -= V_147 ;
}
if ( V_147 < 0 || ! V_107 || * V_96 >= V_124 ) {
F_132 ( V_92 ) ;
goto V_42;
}
}
}
V_107 = V_147 ;
for ( V_136 = 0 ; V_136 < V_134 ; V_136 ++ ) {
T_6 V_97 ;
T_1 V_57 = 0 ;
if ( V_107 ) {
if ( V_107 > V_133 [ V_136 ] . V_139 ) {
V_107 -= V_133 [ V_136 ] . V_139 ;
continue;
}
V_57 = V_107 ;
V_107 = 0 ;
}
V_97 . V_131 = 0 ;
V_97 . V_127 . V_128 = V_133 [ V_136 ] . V_142 + V_57 ;
V_97 . V_107 = V_133 [ V_136 ] . V_139 - V_57 ;
if ( V_97 . V_107 == 0 )
continue;
V_97 . error = 0 ;
F_122 ( V_92 , V_96 , & V_97 , F_133 ) ;
V_147 += V_97 . V_131 ;
if ( V_97 . error ) {
V_147 = V_147 ? : V_97 . error ;
break;
}
if ( V_97 . V_107 > 0 )
break;
}
V_42:
return V_147 ;
}
static int F_145 ( struct V_91 * V_91 , T_2 V_57 )
{
struct V_2 * V_3 = V_91 -> V_99 ;
struct V_1 * V_1 ;
int V_17 ;
do {
V_1 = F_131 ( V_3 ) ;
if ( ! V_1 )
return - V_122 ;
V_17 = F_60 ( V_1 , V_3 , V_57 , V_123 ) ;
if ( V_17 == 0 )
V_17 = V_3 -> V_12 -> V_120 ( V_91 , V_1 ) ;
else if ( V_17 == - V_83 )
V_17 = 0 ;
F_22 ( V_1 ) ;
} while ( V_17 == V_121 );
return V_17 ;
}
static void F_146 ( struct V_154 * V_155 ,
struct V_93 * V_94 ,
struct V_91 * V_91 ,
T_2 V_57 )
{
unsigned long V_95 ;
struct V_2 * V_3 = V_91 -> V_99 ;
if ( F_147 ( V_155 ) )
return;
if ( ! V_94 -> V_95 )
return;
if ( F_148 ( V_155 ) ) {
F_123 ( V_3 , V_94 , V_91 , V_57 ,
V_94 -> V_95 ) ;
return;
}
if ( V_94 -> V_156 < V_157 * 10 )
V_94 -> V_156 ++ ;
if ( V_94 -> V_156 > V_157 )
return;
V_95 = F_149 ( V_94 -> V_95 ) ;
V_94 -> V_23 = F_150 ( long , 0 , V_57 - V_95 / 2 ) ;
V_94 -> V_124 = V_95 ;
V_94 -> V_158 = V_95 / 4 ;
F_151 ( V_94 , V_3 , V_91 ) ;
}
static void F_152 ( struct V_154 * V_155 ,
struct V_93 * V_94 ,
struct V_91 * V_91 ,
struct V_1 * V_1 ,
T_2 V_57 )
{
struct V_2 * V_3 = V_91 -> V_99 ;
if ( F_147 ( V_155 ) )
return;
if ( V_94 -> V_156 > 0 )
V_94 -> V_156 -- ;
if ( F_124 ( V_1 ) )
F_125 ( V_3 , V_94 , V_91 ,
V_1 , V_57 , V_94 -> V_95 ) ;
}
int F_153 ( struct V_154 * V_155 , struct V_159 * V_160 )
{
int error ;
struct V_91 * V_91 = V_155 -> V_161 ;
struct V_2 * V_3 = V_91 -> V_99 ;
struct V_93 * V_94 = & V_91 -> V_101 ;
struct V_100 * V_100 = V_3 -> V_48 ;
T_2 V_57 = V_160 -> V_162 ;
struct V_1 * V_1 ;
T_2 V_124 ;
int V_17 = 0 ;
V_124 = ( F_45 ( V_100 ) + V_106 - 1 ) >> V_37 ;
if ( V_57 >= V_124 )
return V_163 ;
V_1 = F_99 ( V_3 , V_57 ) ;
if ( F_58 ( V_1 ) && ! ( V_160 -> V_19 & V_164 ) ) {
F_152 ( V_155 , V_94 , V_91 , V_1 , V_57 ) ;
} else if ( ! V_1 ) {
F_146 ( V_155 , V_94 , V_91 , V_57 ) ;
F_154 ( V_165 ) ;
F_155 ( V_155 -> V_166 , V_165 ) ;
V_17 = V_167 ;
V_168:
V_1 = F_99 ( V_3 , V_57 ) ;
if ( ! V_1 )
goto V_113;
}
if ( ! F_156 ( V_1 , V_155 -> V_166 , V_160 -> V_19 ) ) {
F_22 ( V_1 ) ;
return V_17 | V_169 ;
}
if ( F_103 ( V_1 -> V_3 != V_3 ) ) {
F_84 ( V_1 ) ;
F_157 ( V_1 ) ;
goto V_168;
}
F_49 ( V_1 -> V_5 != V_57 ) ;
if ( F_103 ( ! F_3 ( V_1 ) ) )
goto V_170;
V_124 = ( F_45 ( V_100 ) + V_106 - 1 ) >> V_37 ;
if ( F_103 ( V_57 >= V_124 ) ) {
F_84 ( V_1 ) ;
F_22 ( V_1 ) ;
return V_163 ;
}
V_160 -> V_1 = V_1 ;
return V_17 | V_171 ;
V_113:
error = F_145 ( V_91 , V_57 ) ;
if ( error >= 0 )
goto V_168;
if ( error == - V_122 )
return V_172 ;
return V_163 ;
V_170:
F_130 ( V_1 ) ;
error = V_3 -> V_12 -> V_120 ( V_91 , V_1 ) ;
if ( ! error ) {
F_98 ( V_1 ) ;
if ( ! F_3 ( V_1 ) )
error = - V_22 ;
}
F_22 ( V_1 ) ;
if ( ! error || error == V_121 )
goto V_168;
F_121 ( V_91 , V_94 ) ;
return V_163 ;
}
int F_158 ( struct V_154 * V_155 , struct V_159 * V_160 )
{
struct V_1 * V_1 = V_160 -> V_1 ;
struct V_100 * V_100 = F_159 ( V_155 -> V_161 ) ;
int V_17 = V_171 ;
F_160 ( V_100 -> V_173 ) ;
F_161 ( V_155 -> V_161 ) ;
F_109 ( V_1 ) ;
if ( V_1 -> V_3 != V_100 -> V_174 ) {
F_84 ( V_1 ) ;
V_17 = V_175 ;
goto V_42;
}
F_162 ( V_1 ) ;
F_163 ( V_1 ) ;
V_42:
F_164 ( V_100 -> V_173 ) ;
return V_17 ;
}
int F_165 ( struct V_91 * V_91 , struct V_154 * V_155 )
{
struct V_2 * V_3 = V_91 -> V_99 ;
if ( ! V_3 -> V_12 -> V_120 )
return - V_176 ;
F_132 ( V_91 ) ;
V_155 -> V_177 = & V_178 ;
return 0 ;
}
int F_166 ( struct V_91 * V_91 , struct V_154 * V_155 )
{
if ( ( V_155 -> V_179 & V_180 ) && ( V_155 -> V_179 & V_181 ) )
return - V_141 ;
return F_165 ( V_91 , V_155 ) ;
}
int F_165 ( struct V_91 * V_91 , struct V_154 * V_155 )
{
return - V_182 ;
}
int F_166 ( struct V_91 * V_91 , struct V_154 * V_155 )
{
return - V_182 ;
}
static struct V_1 * F_167 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_168)( void * , struct V_1 * ) ,
void * V_183 ,
T_3 V_60 )
{
struct V_1 * V_1 ;
int V_49 ;
V_82:
V_1 = F_99 ( V_3 , V_5 ) ;
if ( ! V_1 ) {
V_1 = F_63 ( V_60 | V_184 ) ;
if ( ! V_1 )
return F_169 ( - V_122 ) ;
V_49 = F_60 ( V_1 , V_3 , V_5 , V_60 ) ;
if ( F_103 ( V_49 ) ) {
F_22 ( V_1 ) ;
if ( V_49 == - V_83 )
goto V_82;
return F_169 ( V_49 ) ;
}
V_49 = F_168 ( V_183 , V_1 ) ;
if ( V_49 < 0 ) {
F_22 ( V_1 ) ;
V_1 = F_169 ( V_49 ) ;
}
}
return V_1 ;
}
static struct V_1 * F_170 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_168)( void * , struct V_1 * ) ,
void * V_183 ,
T_3 V_60 )
{
struct V_1 * V_1 ;
int V_49 ;
V_185:
V_1 = F_167 ( V_3 , V_5 , F_168 , V_183 , V_60 ) ;
if ( F_171 ( V_1 ) )
return V_1 ;
if ( F_3 ( V_1 ) )
goto V_42;
F_109 ( V_1 ) ;
if ( ! V_1 -> V_3 ) {
F_84 ( V_1 ) ;
F_22 ( V_1 ) ;
goto V_185;
}
if ( F_3 ( V_1 ) ) {
F_84 ( V_1 ) ;
goto V_42;
}
V_49 = F_168 ( V_183 , V_1 ) ;
if ( V_49 < 0 ) {
F_22 ( V_1 ) ;
return F_169 ( V_49 ) ;
}
V_42:
F_128 ( V_1 ) ;
return V_1 ;
}
struct V_1 * F_172 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_168)( void * , struct V_1 * ) ,
void * V_183 )
{
return F_170 ( V_3 , V_5 , F_168 , V_183 , F_120 ( V_3 ) ) ;
}
static struct V_1 * F_173 ( struct V_1 * V_1 )
{
if ( ! F_171 ( V_1 ) ) {
F_98 ( V_1 ) ;
if ( ! F_3 ( V_1 ) ) {
F_22 ( V_1 ) ;
V_1 = F_169 ( - V_22 ) ;
}
}
return V_1 ;
}
struct V_1 * F_174 ( struct V_2 * V_3 ,
T_2 V_5 ,
T_3 V_60 )
{
T_9 * F_168 = ( T_9 * ) V_3 -> V_12 -> V_120 ;
return F_173 ( F_170 ( V_3 , V_5 , F_168 , NULL , V_60 ) ) ;
}
struct V_1 * F_175 ( struct V_2 * V_3 ,
T_2 V_5 ,
int (* F_168)( void * , struct V_1 * ) ,
void * V_183 )
{
return F_173 ( F_172 ( V_3 , V_5 , F_168 , V_183 ) ) ;
}
static T_8 F_176 ( char * V_186 ,
const struct V_132 * V_133 , T_8 V_187 , T_8 V_188 )
{
T_8 V_189 = 0 , V_126 = 0 ;
while ( V_188 ) {
char T_10 * V_128 = V_133 -> V_142 + V_187 ;
int V_190 = F_39 ( V_188 , V_133 -> V_139 - V_187 ) ;
V_187 = 0 ;
V_126 = F_177 ( V_186 , V_128 , V_190 ) ;
V_189 += V_190 ;
V_188 -= V_190 ;
V_186 += V_190 ;
V_133 ++ ;
if ( F_103 ( V_126 ) )
break;
}
return V_189 - V_126 ;
}
T_8 F_178 ( struct V_1 * V_1 ,
struct V_191 * V_45 , unsigned long V_57 , T_8 V_188 )
{
char * V_125 ;
T_8 V_189 ;
F_10 ( ! F_179 () ) ;
V_125 = F_135 ( V_1 ) ;
if ( F_58 ( V_45 -> V_134 == 1 ) ) {
int V_126 ;
char T_10 * V_128 = V_45 -> V_133 -> V_142 + V_45 -> V_192 ;
V_126 = F_177 ( V_125 + V_57 , V_128 , V_188 ) ;
V_189 = V_188 - V_126 ;
} else {
V_189 = F_176 ( V_125 + V_57 ,
V_45 -> V_133 , V_45 -> V_192 , V_188 ) ;
}
F_137 ( V_125 ) ;
return V_189 ;
}
T_8 F_180 ( struct V_1 * V_1 ,
struct V_191 * V_45 , unsigned long V_57 , T_8 V_188 )
{
char * V_125 ;
T_8 V_189 ;
V_125 = F_138 ( V_1 ) ;
if ( F_58 ( V_45 -> V_134 == 1 ) ) {
int V_126 ;
char T_10 * V_128 = V_45 -> V_133 -> V_142 + V_45 -> V_192 ;
V_126 = F_181 ( V_125 + V_57 , V_128 , V_188 ) ;
V_189 = V_188 - V_126 ;
} else {
V_189 = F_176 ( V_125 + V_57 ,
V_45 -> V_133 , V_45 -> V_192 , V_188 ) ;
}
F_140 ( V_1 ) ;
return V_189 ;
}
void F_182 ( struct V_191 * V_45 , T_8 V_188 )
{
F_10 ( V_45 -> V_107 < V_188 ) ;
if ( F_58 ( V_45 -> V_134 == 1 ) ) {
V_45 -> V_192 += V_188 ;
V_45 -> V_107 -= V_188 ;
} else {
const struct V_132 * V_133 = V_45 -> V_133 ;
T_8 V_187 = V_45 -> V_192 ;
unsigned long V_134 = V_45 -> V_134 ;
while ( V_188 || F_103 ( V_45 -> V_107 && ! V_133 -> V_139 ) ) {
int V_190 ;
V_190 = F_39 ( V_188 , V_133 -> V_139 - V_187 ) ;
F_10 ( ! V_45 -> V_107 || V_45 -> V_107 < V_190 ) ;
V_45 -> V_107 -= V_190 ;
V_188 -= V_190 ;
V_187 += V_190 ;
if ( V_133 -> V_139 == V_187 ) {
V_133 ++ ;
V_134 -- ;
V_187 = 0 ;
}
}
V_45 -> V_133 = V_133 ;
V_45 -> V_192 = V_187 ;
V_45 -> V_134 = V_134 ;
}
}
int F_183 ( struct V_191 * V_45 , T_8 V_188 )
{
char T_10 * V_128 = V_45 -> V_133 -> V_142 + V_45 -> V_192 ;
V_188 = F_39 ( V_188 , V_45 -> V_133 -> V_139 - V_45 -> V_192 ) ;
return F_184 ( V_128 , V_188 ) ;
}
T_8 F_185 ( const struct V_191 * V_45 )
{
const struct V_132 * V_133 = V_45 -> V_133 ;
if ( V_45 -> V_134 == 1 )
return V_45 -> V_107 ;
else
return F_39 ( V_45 -> V_107 , V_133 -> V_139 - V_45 -> V_192 ) ;
}
inline int F_186 ( struct V_91 * V_91 , T_1 * V_145 , T_8 * V_107 , int V_193 )
{
struct V_100 * V_100 = V_91 -> V_99 -> V_48 ;
unsigned long V_194 = F_187 ( V_195 ) ;
if ( F_103 ( * V_145 < 0 ) )
return - V_141 ;
if ( ! V_193 ) {
if ( V_91 -> V_150 & V_196 )
* V_145 = F_45 ( V_100 ) ;
if ( V_194 != V_197 ) {
if ( * V_145 >= V_194 ) {
F_188 ( V_198 , V_15 , 0 ) ;
return - V_199 ;
}
if ( * V_107 > V_194 - ( F_189 ( V_194 ) ) * V_145 ) {
* V_107 = V_194 - ( F_189 ( V_194 ) ) * V_145 ;
}
}
}
if ( F_103 ( * V_145 + * V_107 > V_200 &&
! ( V_91 -> V_150 & V_201 ) ) ) {
if ( * V_145 >= V_200 ) {
return - V_199 ;
}
if ( * V_107 > V_200 - ( unsigned long ) * V_145 ) {
* V_107 = V_200 - ( unsigned long ) * V_145 ;
}
}
if ( F_58 ( ! V_193 ) ) {
if ( F_103 ( * V_145 >= V_100 -> V_173 -> V_202 ) ) {
if ( * V_107 || * V_145 > V_100 -> V_173 -> V_202 ) {
return - V_199 ;
}
}
if ( F_103 ( * V_145 + * V_107 > V_100 -> V_173 -> V_202 ) )
* V_107 = V_100 -> V_173 -> V_202 - * V_145 ;
} else {
#ifdef F_190
T_1 V_110 ;
if ( F_191 ( F_192 ( V_100 ) ) )
return - V_203 ;
V_110 = F_45 ( V_100 ) ;
if ( * V_145 >= V_110 ) {
if ( * V_107 || * V_145 > V_110 )
return - V_20 ;
}
if ( * V_145 + * V_107 > V_110 )
* V_107 = V_110 - * V_145 ;
#else
return - V_203 ;
#endif
}
return 0 ;
}
int F_193 ( struct V_91 * V_91 , struct V_2 * V_3 ,
T_1 V_145 , unsigned V_204 , unsigned V_19 ,
struct V_1 * * V_81 , void * * V_205 )
{
const struct V_206 * V_207 = V_3 -> V_12 ;
return V_207 -> V_208 ( V_91 , V_3 , V_145 , V_204 , V_19 ,
V_81 , V_205 ) ;
}
int F_194 ( struct V_91 * V_91 , struct V_2 * V_3 ,
T_1 V_145 , unsigned V_204 , unsigned V_189 ,
struct V_1 * V_1 , void * V_205 )
{
const struct V_206 * V_207 = V_3 -> V_12 ;
F_128 ( V_1 ) ;
return V_207 -> V_209 ( V_91 , V_3 , V_145 , V_204 , V_189 , V_1 , V_205 ) ;
}
V_140
F_195 ( struct V_143 * V_144 , const struct V_132 * V_133 ,
unsigned long * V_134 , T_1 V_145 , T_1 * V_96 ,
T_8 V_107 , T_8 V_210 )
{
struct V_91 * V_91 = V_144 -> V_146 ;
struct V_2 * V_3 = V_91 -> V_99 ;
struct V_100 * V_100 = V_3 -> V_48 ;
V_140 V_131 ;
T_8 V_211 ;
T_2 V_24 ;
if ( V_107 != V_210 )
* V_134 = F_196 ( (struct V_132 * ) V_133 , * V_134 , V_107 ) ;
V_211 = F_144 ( V_133 , * V_134 ) ;
V_24 = ( V_145 + V_211 - 1 ) >> V_37 ;
V_131 = F_47 ( V_3 , V_145 , V_145 + V_211 - 1 ) ;
if ( V_131 )
goto V_42;
if ( V_3 -> V_6 ) {
V_131 = F_197 ( V_3 ,
V_145 >> V_37 , V_24 ) ;
if ( V_131 ) {
if ( V_131 == - V_212 )
return 0 ;
goto V_42;
}
}
V_131 = V_3 -> V_12 -> V_152 ( V_213 , V_144 , V_133 , V_145 , * V_134 ) ;
if ( V_3 -> V_6 ) {
F_197 ( V_3 ,
V_145 >> V_37 , V_24 ) ;
}
if ( V_131 > 0 ) {
V_145 += V_131 ;
if ( V_145 > F_45 ( V_100 ) && ! F_198 ( V_100 -> V_214 ) ) {
F_199 ( V_100 , V_145 ) ;
F_200 ( V_100 ) ;
}
* V_96 = V_145 ;
}
V_42:
return V_131 ;
}
struct V_1 * F_201 ( struct V_2 * V_3 ,
T_2 V_5 , unsigned V_19 )
{
int V_215 ;
T_3 V_55 ;
struct V_1 * V_1 ;
T_3 V_216 = 0 ;
V_55 = F_120 ( V_3 ) ;
if ( F_13 ( V_3 ) )
V_55 |= V_217 ;
if ( V_19 & V_218 )
V_216 = V_89 ;
V_82:
V_1 = F_108 ( V_3 , V_5 ) ;
if ( V_1 )
goto V_219;
V_1 = F_63 ( V_55 & ~ V_216 ) ;
if ( ! V_1 )
return NULL ;
V_215 = F_60 ( V_1 , V_3 , V_5 ,
V_123 & ~ V_216 ) ;
if ( F_103 ( V_215 ) ) {
F_22 ( V_1 ) ;
if ( V_215 == - V_83 )
goto V_82;
return NULL ;
}
V_219:
F_163 ( V_1 ) ;
return V_1 ;
}
static V_140 F_202 ( struct V_91 * V_91 ,
struct V_191 * V_45 , T_1 V_145 )
{
struct V_2 * V_3 = V_91 -> V_99 ;
const struct V_206 * V_12 = V_3 -> V_12 ;
long V_215 = 0 ;
V_140 V_131 = 0 ;
unsigned int V_19 = 0 ;
if ( F_203 ( F_204 () , V_220 ) )
V_19 |= V_221 ;
do {
struct V_1 * V_1 ;
unsigned long V_57 ;
unsigned long V_188 ;
T_8 V_189 ;
void * V_205 ;
V_57 = ( V_145 & ( V_106 - 1 ) ) ;
V_188 = F_205 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_count(i)) ;
V_222:
if ( F_103 ( F_183 ( V_45 , V_188 ) ) ) {
V_215 = - V_130 ;
break;
}
V_215 = V_12 -> V_208 ( V_91 , V_3 , V_145 , V_188 , V_19 ,
& V_1 , & V_205 ) ;
if ( F_103 ( V_215 ) )
break;
if ( F_126 ( V_3 ) )
F_127 ( V_1 ) ;
F_206 () ;
V_189 = F_178 ( V_1 , V_45 , V_57 , V_188 ) ;
F_207 () ;
F_127 ( V_1 ) ;
F_128 ( V_1 ) ;
V_215 = V_12 -> V_209 ( V_91 , V_3 , V_145 , V_188 , V_189 ,
V_1 , V_205 ) ;
if ( F_103 ( V_215 < 0 ) )
break;
V_189 = V_215 ;
F_43 () ;
F_182 ( V_45 , V_189 ) ;
if ( F_103 ( V_189 == 0 ) ) {
V_188 = F_205 (unsigned long, PAGE_CACHE_SIZE - offset,
iov_iter_single_seg_count(i)) ;
goto V_222;
}
V_145 += V_189 ;
V_131 += V_189 ;
F_208 ( V_3 ) ;
if ( F_26 ( V_15 ) ) {
V_215 = - V_16 ;
break;
}
} while ( F_209 ( V_45 ) );
return V_131 ? V_131 : V_215 ;
}
V_140
F_210 ( struct V_143 * V_144 , const struct V_132 * V_133 ,
unsigned long V_134 , T_1 V_145 , T_1 * V_96 ,
T_8 V_107 , V_140 V_131 )
{
struct V_91 * V_91 = V_144 -> V_146 ;
V_140 V_215 ;
struct V_191 V_45 ;
F_211 ( & V_45 , V_133 , V_134 , V_107 , V_131 ) ;
V_215 = F_202 ( V_91 , & V_45 , V_145 ) ;
if ( F_58 ( V_215 >= 0 ) ) {
V_131 += V_215 ;
* V_96 = V_145 + V_215 ;
}
return V_131 ? V_131 : V_215 ;
}
V_140 F_212 ( struct V_143 * V_144 , const struct V_132 * V_133 ,
unsigned long V_134 , T_1 * V_96 )
{
struct V_91 * V_91 = V_144 -> V_146 ;
struct V_2 * V_3 = V_91 -> V_99 ;
T_8 V_210 ;
T_8 V_107 ;
struct V_100 * V_100 = V_3 -> V_48 ;
T_1 V_145 ;
V_140 V_131 ;
V_140 V_49 ;
V_210 = 0 ;
V_49 = F_141 ( V_133 , & V_134 , & V_210 , V_223 ) ;
if ( V_49 )
return V_49 ;
V_107 = V_210 ;
V_145 = * V_96 ;
V_15 -> V_10 = V_3 -> V_10 ;
V_131 = 0 ;
V_49 = F_186 ( V_91 , & V_145 , & V_107 , F_198 ( V_100 -> V_214 ) ) ;
if ( V_49 )
goto V_42;
if ( V_107 == 0 )
goto V_42;
V_49 = F_213 ( V_91 ) ;
if ( V_49 )
goto V_42;
V_49 = F_161 ( V_91 ) ;
if ( V_49 )
goto V_42;
if ( F_103 ( V_91 -> V_150 & V_151 ) ) {
T_1 V_224 ;
V_140 V_225 ;
V_131 = F_195 ( V_144 , V_133 , & V_134 , V_145 ,
V_96 , V_107 , V_210 ) ;
if ( V_131 < 0 || V_131 == V_107 )
goto V_42;
V_145 += V_131 ;
V_107 -= V_131 ;
V_225 = F_210 ( V_144 , V_133 ,
V_134 , V_145 , V_96 , V_107 ,
V_131 ) ;
if ( V_225 < 0 ) {
V_49 = V_225 ;
goto V_42;
}
V_224 = V_145 + V_225 - V_131 - 1 ;
V_49 = F_47 ( V_91 -> V_99 , V_145 , V_224 ) ;
if ( V_49 == 0 ) {
V_131 = V_225 ;
F_214 ( V_3 ,
V_145 >> V_37 ,
V_224 >> V_37 ) ;
} else {
}
} else {
V_131 = F_210 ( V_144 , V_133 , V_134 ,
V_145 , V_96 , V_107 , V_131 ) ;
}
V_42:
V_15 -> V_10 = NULL ;
return V_131 ? V_131 : V_49 ;
}
V_140 F_215 ( struct V_143 * V_144 , const struct V_132 * V_133 ,
unsigned long V_134 , T_1 V_145 )
{
struct V_91 * V_91 = V_144 -> V_146 ;
struct V_100 * V_100 = V_91 -> V_99 -> V_48 ;
V_140 V_17 ;
F_10 ( V_144 -> V_148 != V_145 ) ;
F_216 ( & V_100 -> V_226 ) ;
V_17 = F_212 ( V_144 , V_133 , V_134 , & V_144 -> V_148 ) ;
F_217 ( & V_100 -> V_226 ) ;
if ( V_17 > 0 || V_17 == - V_227 ) {
V_140 V_49 ;
V_49 = F_218 ( V_91 , V_145 , V_17 ) ;
if ( V_49 < 0 && V_17 > 0 )
V_17 = V_49 ;
}
return V_17 ;
}
int F_219 ( struct V_1 * V_1 , T_3 V_55 )
{
struct V_2 * const V_3 = V_1 -> V_3 ;
F_10 ( ! F_18 ( V_1 ) ) ;
if ( F_220 ( V_1 ) )
return 0 ;
if ( V_3 && V_3 -> V_12 -> V_228 )
return V_3 -> V_12 -> V_228 ( V_1 , V_55 ) ;
return F_221 ( V_1 ) ;
}
