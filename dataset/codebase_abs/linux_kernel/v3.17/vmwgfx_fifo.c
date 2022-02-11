bool F_1 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_5 , V_6 ;
const struct V_7 * V_8 = & V_2 -> V_8 ;
if ( ! ( V_2 -> V_9 & V_10 ) )
return false ;
if ( V_2 -> V_9 & V_11 ) {
T_3 V_12 ;
if ( ! V_2 -> V_13 )
return false ;
F_2 ( & V_2 -> V_14 ) ;
F_3 ( V_2 , V_15 , V_16 ) ;
V_12 = F_4 ( V_2 , V_15 ) ;
F_5 ( & V_2 -> V_14 ) ;
return ( V_12 != 0 ) ;
}
if ( ! ( V_2 -> V_9 & V_17 ) )
return false ;
V_5 = F_6 ( V_3 + V_18 ) ;
if ( V_5 <= V_19 * sizeof( unsigned int ) )
return false ;
V_6 = F_6 ( V_3 +
( ( V_8 -> V_9 &
V_20 ) ?
V_21 :
V_19 ) ) ;
if ( V_6 == 0 )
return false ;
if ( V_6 < V_22 )
return false ;
if ( ! V_2 -> V_23 )
return false ;
return true ;
}
bool F_7 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_24 ;
if ( ! ( V_2 -> V_9 & V_17 ) )
return false ;
V_24 = F_6 ( V_3 + V_25 ) ;
if ( V_24 & V_26 )
return true ;
return false ;
}
int F_8 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_27 ;
T_3 V_28 ;
T_3 V_29 ;
V_8 -> V_30 = V_31 ;
V_8 -> V_32 = F_9 ( V_8 -> V_30 ) ;
if ( F_10 ( V_8 -> V_32 == NULL ) )
return - V_33 ;
V_8 -> V_34 = NULL ;
V_8 -> V_35 = 0 ;
V_8 -> V_36 = false ;
F_11 ( & V_8 -> V_37 ) ;
F_12 ( & V_8 -> V_38 ) ;
F_13 ( L_1 , F_4 ( V_2 , V_39 ) ) ;
F_13 ( L_2 , F_4 ( V_2 , V_40 ) ) ;
F_13 ( L_3 , F_4 ( V_2 , V_41 ) ) ;
F_2 ( & V_2 -> V_14 ) ;
V_2 -> V_42 = F_4 ( V_2 , V_43 ) ;
V_2 -> V_44 = F_4 ( V_2 , V_45 ) ;
V_2 -> V_46 = F_4 ( V_2 , V_47 ) ;
F_3 ( V_2 , V_43 , 1 ) ;
V_28 = 4 ;
if ( V_2 -> V_9 & V_17 )
V_28 = F_4 ( V_2 , V_48 ) ;
V_28 <<= 2 ;
if ( V_28 < V_49 )
V_28 = V_49 ;
F_14 ( V_28 , V_3 + V_18 ) ;
F_14 ( V_2 -> V_50 , V_3 + V_51 ) ;
F_15 () ;
F_14 ( V_28 , V_3 + V_52 ) ;
F_14 ( V_28 , V_3 + V_53 ) ;
F_14 ( 0 , V_3 + V_54 ) ;
F_16 () ;
F_3 ( V_2 , V_45 , 1 ) ;
F_5 ( & V_2 -> V_14 ) ;
V_27 = F_6 ( V_3 + V_51 ) ;
V_28 = F_6 ( V_3 + V_18 ) ;
V_8 -> V_9 = F_6 ( V_3 + V_25 ) ;
F_13 ( L_4 ,
( unsigned int ) V_27 ,
( unsigned int ) V_28 ,
( unsigned int ) V_8 -> V_9 ) ;
F_17 ( & V_2 -> V_55 , V_2 -> V_56 ) ;
F_14 ( V_2 -> V_56 , V_3 + V_57 ) ;
F_18 ( & V_8 -> V_58 ) ;
return F_19 ( V_2 , & V_29 ) ;
}
void F_20 ( struct V_1 * V_2 , T_3 V_59 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
F_2 ( & V_2 -> V_14 ) ;
if ( F_10 ( F_6 ( V_3 + V_54 ) == 0 ) ) {
F_14 ( 1 , V_3 + V_54 ) ;
F_3 ( V_2 , V_60 , V_59 ) ;
}
F_5 ( & V_2 -> V_14 ) ;
}
void F_21 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
F_2 ( & V_2 -> V_14 ) ;
F_3 ( V_2 , V_60 , V_61 ) ;
while ( F_4 ( V_2 , V_62 ) != 0 )
;
V_2 -> V_56 = F_6 ( V_3 + V_57 ) ;
F_3 ( V_2 , V_45 ,
V_2 -> V_44 ) ;
F_3 ( V_2 , V_43 ,
V_2 -> V_42 ) ;
F_3 ( V_2 , V_47 ,
V_2 -> V_46 ) ;
F_5 ( & V_2 -> V_14 ) ;
F_22 ( & V_8 -> V_58 ) ;
if ( F_23 ( V_8 -> V_32 != NULL ) ) {
F_24 ( V_8 -> V_32 ) ;
V_8 -> V_32 = NULL ;
}
if ( F_23 ( V_8 -> V_34 != NULL ) ) {
F_24 ( V_8 -> V_34 ) ;
V_8 -> V_34 = NULL ;
}
}
static bool F_25 ( struct V_1 * V_2 , T_3 V_63 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_27 = F_6 ( V_3 + V_51 ) ;
T_3 V_64 = F_6 ( V_3 + V_52 ) ;
T_3 V_28 = F_6 ( V_3 + V_18 ) ;
T_3 V_65 = F_6 ( V_3 + V_53 ) ;
return ( ( V_27 - V_64 ) + ( V_65 - V_28 ) <= V_63 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
T_3 V_63 , bool V_66 ,
unsigned long V_67 )
{
int V_68 = 0 ;
unsigned long V_69 = V_70 + V_67 ;
F_27 ( V_71 ) ;
F_13 ( L_5 ) ;
for (; ; ) {
F_28 ( & V_2 -> V_72 , & V_71 ,
( V_66 ) ?
V_73 : V_74 ) ;
if ( ! F_25 ( V_2 , V_63 ) )
break;
if ( F_29 ( V_70 , V_69 ) ) {
V_68 = - V_75 ;
F_30 ( L_6 ) ;
break;
}
F_31 ( 1 ) ;
if ( V_66 && F_32 ( V_76 ) ) {
V_68 = - V_77 ;
break;
}
}
F_33 ( & V_2 -> V_72 , & V_71 ) ;
F_34 ( & V_2 -> V_72 ) ;
F_13 ( L_7 ) ;
return V_68 ;
}
static int F_35 ( struct V_1 * V_2 ,
T_3 V_63 , bool V_66 ,
unsigned long V_67 )
{
long V_68 = 1L ;
unsigned long V_78 ;
if ( F_23 ( ! F_25 ( V_2 , V_63 ) ) )
return 0 ;
F_20 ( V_2 , V_79 ) ;
if ( ! ( V_2 -> V_9 & V_80 ) )
return F_26 ( V_2 , V_63 ,
V_66 , V_67 ) ;
F_2 ( & V_2 -> V_14 ) ;
if ( F_36 ( 1 , & V_2 -> V_81 ) > 0 ) {
F_37 ( & V_2 -> V_82 , V_78 ) ;
F_38 ( V_83 ,
V_2 -> V_84 + V_85 ) ;
V_2 -> V_86 |= V_83 ;
F_3 ( V_2 , V_87 , V_2 -> V_86 ) ;
F_39 ( & V_2 -> V_82 , V_78 ) ;
}
F_5 ( & V_2 -> V_14 ) ;
if ( V_66 )
V_68 = F_40
( V_2 -> V_72 ,
! F_25 ( V_2 , V_63 ) , V_67 ) ;
else
V_68 = F_41
( V_2 -> V_72 ,
! F_25 ( V_2 , V_63 ) , V_67 ) ;
if ( F_10 ( V_68 == 0 ) )
V_68 = - V_75 ;
else if ( F_23 ( V_68 > 0 ) )
V_68 = 0 ;
F_2 ( & V_2 -> V_14 ) ;
if ( F_42 ( & V_2 -> V_81 ) ) {
F_37 ( & V_2 -> V_82 , V_78 ) ;
V_2 -> V_86 &= ~ V_83 ;
F_3 ( V_2 , V_87 , V_2 -> V_86 ) ;
F_39 ( & V_2 -> V_82 , V_78 ) ;
}
F_5 ( & V_2 -> V_14 ) ;
return V_68 ;
}
void * F_43 ( struct V_1 * V_2 , T_3 V_63 )
{
struct V_7 * V_88 = & V_2 -> V_8 ;
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_27 ;
T_3 V_28 ;
T_3 V_64 ;
T_3 V_89 = V_88 -> V_9 & V_90 ;
int V_68 ;
F_2 ( & V_88 -> V_37 ) ;
V_27 = F_6 ( V_3 + V_51 ) ;
V_28 = F_6 ( V_3 + V_18 ) ;
V_64 = F_6 ( V_3 + V_52 ) ;
if ( F_10 ( V_63 >= ( V_27 - V_28 ) ) )
goto V_91;
F_44 ( V_88 -> V_35 != 0 ) ;
F_44 ( V_88 -> V_34 != NULL ) ;
V_88 -> V_35 = V_63 ;
while ( 1 ) {
T_3 V_65 = F_6 ( V_3 + V_53 ) ;
bool V_92 = false ;
bool V_93 = false ;
if ( V_64 >= V_65 ) {
if ( F_23 ( ( V_64 + V_63 < V_27 ||
( V_64 + V_63 == V_27 && V_65 > V_28 ) ) ) )
V_93 = true ;
else if ( F_25 ( V_2 , V_63 ) ) {
V_68 = F_35 ( V_2 , V_63 ,
false , 3 * V_94 ) ;
if ( F_10 ( V_68 != 0 ) )
goto V_91;
} else
V_92 = true ;
} else {
if ( F_23 ( ( V_64 + V_63 < V_65 ) ) )
V_93 = true ;
else {
V_68 = F_35 ( V_2 , V_63 ,
false , 3 * V_94 ) ;
if ( F_10 ( V_68 != 0 ) )
goto V_91;
}
}
if ( V_93 ) {
if ( V_89 || V_63 <= sizeof( T_3 ) ) {
V_88 -> V_36 = false ;
if ( V_89 )
F_14 ( V_63 , V_3 +
V_95 ) ;
return V_3 + ( V_64 >> 2 ) ;
} else {
V_92 = true ;
}
}
if ( V_92 ) {
V_88 -> V_36 = true ;
if ( V_63 < V_88 -> V_30 )
return V_88 -> V_32 ;
else {
V_88 -> V_34 = F_9 ( V_63 ) ;
return V_88 -> V_34 ;
}
}
}
V_91:
V_88 -> V_35 = 0 ;
F_5 ( & V_88 -> V_37 ) ;
return NULL ;
}
static void F_45 ( struct V_7 * V_88 ,
T_1 T_2 * V_3 ,
T_3 V_64 ,
T_3 V_27 , T_3 V_28 , T_3 V_63 )
{
T_3 V_96 = V_27 - V_64 ;
T_3 V_97 ;
T_3 * V_98 = ( V_88 -> V_34 != NULL ) ?
V_88 -> V_34 : V_88 -> V_32 ;
if ( V_63 < V_96 )
V_96 = V_63 ;
F_14 ( V_63 , V_3 + V_95 ) ;
F_16 () ;
F_46 ( V_3 + ( V_64 >> 2 ) , V_98 , V_96 ) ;
V_97 = V_63 - V_96 ;
if ( V_97 )
F_46 ( V_3 + ( V_28 >> 2 ) , V_98 + ( V_96 >> 2 ) ,
V_97 ) ;
}
static void F_47 ( struct V_7 * V_88 ,
T_1 T_2 * V_3 ,
T_3 V_64 ,
T_3 V_27 , T_3 V_28 , T_3 V_63 )
{
T_3 * V_98 = ( V_88 -> V_34 != NULL ) ?
V_88 -> V_34 : V_88 -> V_32 ;
while ( V_63 > 0 ) {
F_14 ( * V_98 ++ , V_3 + ( V_64 >> 2 ) ) ;
V_64 += sizeof( T_3 ) ;
if ( F_10 ( V_64 == V_27 ) )
V_64 = V_28 ;
F_16 () ;
F_14 ( V_64 , V_3 + V_52 ) ;
F_16 () ;
V_63 -= sizeof( T_3 ) ;
}
}
void F_48 ( struct V_1 * V_2 , T_3 V_63 )
{
struct V_7 * V_88 = & V_2 -> V_8 ;
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_64 = F_6 ( V_3 + V_52 ) ;
T_3 V_27 = F_6 ( V_3 + V_51 ) ;
T_3 V_28 = F_6 ( V_3 + V_18 ) ;
bool V_89 = V_88 -> V_9 & V_90 ;
F_44 ( ( V_63 & 3 ) != 0 ) ;
F_44 ( V_63 > V_88 -> V_35 ) ;
V_88 -> V_35 = 0 ;
if ( V_88 -> V_36 ) {
if ( V_89 )
F_45 ( V_88 , V_3 ,
V_64 , V_27 , V_28 , V_63 ) ;
else
F_47 ( V_88 , V_3 ,
V_64 , V_27 , V_28 , V_63 ) ;
if ( V_88 -> V_34 ) {
F_24 ( V_88 -> V_34 ) ;
V_88 -> V_34 = NULL ;
}
}
F_49 ( & V_88 -> V_38 ) ;
if ( V_88 -> V_36 || V_89 ) {
V_64 += V_63 ;
if ( V_64 >= V_27 )
V_64 -= V_27 - V_28 ;
F_16 () ;
F_14 ( V_64 , V_3 + V_52 ) ;
}
if ( V_89 )
F_14 ( 0 , V_3 + V_95 ) ;
F_16 () ;
F_50 ( & V_88 -> V_38 ) ;
F_20 ( V_2 , V_61 ) ;
F_5 ( & V_88 -> V_37 ) ;
}
int F_19 ( struct V_1 * V_2 , T_3 * V_99 )
{
struct V_7 * V_88 = & V_2 -> V_8 ;
struct V_100 * V_101 ;
void * V_102 ;
int V_68 = 0 ;
T_3 V_63 = sizeof( T_1 ) + sizeof( * V_101 ) ;
V_102 = F_43 ( V_2 , V_63 ) ;
if ( F_10 ( V_102 == NULL ) ) {
* V_99 = F_51 ( & V_2 -> V_55 ) ;
V_68 = - V_33 ;
( void ) F_52 ( V_2 , false , true , * V_99 ,
false , 3 * V_94 ) ;
goto V_91;
}
do {
* V_99 = F_36 ( 1 , & V_2 -> V_55 ) ;
} while ( * V_99 == 0 );
if ( ! ( V_88 -> V_9 & V_103 ) ) {
F_48 ( V_2 , 0 ) ;
return 0 ;
}
* ( T_1 * ) V_102 = F_53 ( V_104 ) ;
V_101 = (struct V_100 * )
( ( unsigned long ) V_102 + sizeof( T_1 ) ) ;
F_14 ( * V_99 , & V_101 -> V_105 ) ;
F_48 ( V_2 , V_63 ) ;
( void ) F_54 ( & V_88 -> V_58 , * V_99 ) ;
F_55 ( V_2 , V_88 ) ;
V_91:
return V_68 ;
}
static int F_56 ( struct V_1 * V_2 ,
T_3 V_106 )
{
struct V_107 * V_108 = V_2 -> V_109 ;
struct {
T_4 V_110 ;
T_5 V_111 ;
} * V_112 ;
V_112 = F_43 ( V_2 , sizeof( * V_112 ) ) ;
if ( F_10 ( V_112 == NULL ) ) {
F_30 ( L_8 ) ;
return - V_33 ;
}
V_112 -> V_110 . V_113 = V_114 ;
V_112 -> V_110 . V_115 = sizeof( V_112 -> V_111 ) ;
V_112 -> V_111 . V_106 = V_106 ;
V_112 -> V_111 . type = V_116 ;
if ( V_108 -> V_117 . V_118 == V_119 ) {
V_112 -> V_111 . V_120 . V_121 = V_122 ;
V_112 -> V_111 . V_120 . V_123 = V_108 -> V_123 ;
} else {
V_112 -> V_111 . V_120 . V_121 = V_108 -> V_117 . V_124 ;
V_112 -> V_111 . V_120 . V_123 = 0 ;
}
F_48 ( V_2 , sizeof( * V_112 ) ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
T_3 V_106 )
{
struct V_107 * V_108 = V_2 -> V_109 ;
struct {
T_4 V_110 ;
T_6 V_111 ;
} * V_112 ;
V_112 = F_43 ( V_2 , sizeof( * V_112 ) ) ;
if ( F_10 ( V_112 == NULL ) ) {
F_30 ( L_8 ) ;
return - V_33 ;
}
V_112 -> V_110 . V_113 = V_125 ;
V_112 -> V_110 . V_115 = sizeof( V_112 -> V_111 ) ;
V_112 -> V_111 . V_106 = V_106 ;
V_112 -> V_111 . type = V_116 ;
F_44 ( V_108 -> V_117 . V_118 != V_126 ) ;
V_112 -> V_111 . V_127 = V_108 -> V_117 . V_124 ;
V_112 -> V_111 . V_123 = 0 ;
F_48 ( V_2 , sizeof( * V_112 ) ) ;
return 0 ;
}
int F_58 ( struct V_1 * V_2 ,
T_3 V_106 )
{
if ( V_2 -> V_13 )
return F_57 ( V_2 , V_106 ) ;
return F_56 ( V_2 , V_106 ) ;
}
