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
static F_21 ( V_60 ) ;
unsigned long V_61 ;
F_22 ( & V_60 , V_61 ) ;
if ( F_10 ( F_6 ( V_3 + V_54 ) == 0 ) ) {
F_14 ( 1 , V_3 + V_54 ) ;
F_3 ( V_2 , V_62 , V_59 ) ;
}
F_23 ( & V_60 , V_61 ) ;
}
void F_24 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
F_3 ( V_2 , V_62 , V_63 ) ;
while ( F_4 ( V_2 , V_64 ) != 0 )
;
V_2 -> V_56 = F_6 ( V_3 + V_57 ) ;
F_3 ( V_2 , V_45 ,
V_2 -> V_44 ) ;
F_3 ( V_2 , V_43 ,
V_2 -> V_42 ) ;
F_3 ( V_2 , V_47 ,
V_2 -> V_46 ) ;
F_25 ( & V_8 -> V_58 ) ;
if ( F_26 ( V_8 -> V_32 != NULL ) ) {
F_27 ( V_8 -> V_32 ) ;
V_8 -> V_32 = NULL ;
}
if ( F_26 ( V_8 -> V_34 != NULL ) ) {
F_27 ( V_8 -> V_34 ) ;
V_8 -> V_34 = NULL ;
}
}
static bool F_28 ( struct V_1 * V_2 , T_3 V_65 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_27 = F_6 ( V_3 + V_51 ) ;
T_3 V_66 = F_6 ( V_3 + V_52 ) ;
T_3 V_28 = F_6 ( V_3 + V_18 ) ;
T_3 V_67 = F_6 ( V_3 + V_53 ) ;
return ( ( V_27 - V_66 ) + ( V_67 - V_28 ) <= V_65 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
T_3 V_65 , bool V_68 ,
unsigned long V_69 )
{
int V_70 = 0 ;
unsigned long V_71 = V_72 + V_69 ;
F_30 ( V_73 ) ;
F_13 ( L_5 ) ;
for (; ; ) {
F_31 ( & V_2 -> V_74 , & V_73 ,
( V_68 ) ?
V_75 : V_76 ) ;
if ( ! F_28 ( V_2 , V_65 ) )
break;
if ( F_32 ( V_72 , V_71 ) ) {
V_70 = - V_77 ;
F_33 ( L_6 ) ;
break;
}
F_34 ( 1 ) ;
if ( V_68 && F_35 ( V_78 ) ) {
V_70 = - V_79 ;
break;
}
}
F_36 ( & V_2 -> V_74 , & V_73 ) ;
F_37 ( & V_2 -> V_74 ) ;
F_13 ( L_7 ) ;
return V_70 ;
}
static int F_38 ( struct V_1 * V_2 ,
T_3 V_65 , bool V_68 ,
unsigned long V_69 )
{
long V_70 = 1L ;
unsigned long V_61 ;
if ( F_26 ( ! F_28 ( V_2 , V_65 ) ) )
return 0 ;
F_20 ( V_2 , V_80 ) ;
if ( ! ( V_2 -> V_9 & V_81 ) )
return F_29 ( V_2 , V_65 ,
V_68 , V_69 ) ;
F_2 ( & V_2 -> V_82 ) ;
if ( F_39 ( 1 , & V_2 -> V_83 ) > 0 ) {
F_22 ( & V_2 -> V_84 , V_61 ) ;
F_40 ( V_85 ,
V_2 -> V_86 + V_87 ) ;
V_2 -> V_88 |= V_85 ;
F_3 ( V_2 , V_89 , V_2 -> V_88 ) ;
F_23 ( & V_2 -> V_84 , V_61 ) ;
}
F_5 ( & V_2 -> V_82 ) ;
if ( V_68 )
V_70 = F_41
( V_2 -> V_74 ,
! F_28 ( V_2 , V_65 ) , V_69 ) ;
else
V_70 = F_42
( V_2 -> V_74 ,
! F_28 ( V_2 , V_65 ) , V_69 ) ;
if ( F_10 ( V_70 == 0 ) )
V_70 = - V_77 ;
else if ( F_26 ( V_70 > 0 ) )
V_70 = 0 ;
F_2 ( & V_2 -> V_82 ) ;
if ( F_43 ( & V_2 -> V_83 ) ) {
F_22 ( & V_2 -> V_84 , V_61 ) ;
V_2 -> V_88 &= ~ V_85 ;
F_3 ( V_2 , V_89 , V_2 -> V_88 ) ;
F_23 ( & V_2 -> V_84 , V_61 ) ;
}
F_5 ( & V_2 -> V_82 ) ;
return V_70 ;
}
void * F_44 ( struct V_1 * V_2 , T_3 V_65 )
{
struct V_7 * V_90 = & V_2 -> V_8 ;
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_27 ;
T_3 V_28 ;
T_3 V_66 ;
T_3 V_91 = V_90 -> V_9 & V_92 ;
int V_70 ;
F_45 ( & V_90 -> V_37 ) ;
V_27 = F_6 ( V_3 + V_51 ) ;
V_28 = F_6 ( V_3 + V_18 ) ;
V_66 = F_6 ( V_3 + V_52 ) ;
if ( F_10 ( V_65 >= ( V_27 - V_28 ) ) )
goto V_93;
F_46 ( V_90 -> V_35 != 0 ) ;
F_46 ( V_90 -> V_34 != NULL ) ;
V_90 -> V_35 = V_65 ;
while ( 1 ) {
T_3 V_67 = F_6 ( V_3 + V_53 ) ;
bool V_94 = false ;
bool V_95 = false ;
if ( V_66 >= V_67 ) {
if ( F_26 ( ( V_66 + V_65 < V_27 ||
( V_66 + V_65 == V_27 && V_67 > V_28 ) ) ) )
V_95 = true ;
else if ( F_28 ( V_2 , V_65 ) ) {
V_70 = F_38 ( V_2 , V_65 ,
false , 3 * V_96 ) ;
if ( F_10 ( V_70 != 0 ) )
goto V_93;
} else
V_94 = true ;
} else {
if ( F_26 ( ( V_66 + V_65 < V_67 ) ) )
V_95 = true ;
else {
V_70 = F_38 ( V_2 , V_65 ,
false , 3 * V_96 ) ;
if ( F_10 ( V_70 != 0 ) )
goto V_93;
}
}
if ( V_95 ) {
if ( V_91 || V_65 <= sizeof( T_3 ) ) {
V_90 -> V_36 = false ;
if ( V_91 )
F_14 ( V_65 , V_3 +
V_97 ) ;
return V_3 + ( V_66 >> 2 ) ;
} else {
V_94 = true ;
}
}
if ( V_94 ) {
V_90 -> V_36 = true ;
if ( V_65 < V_90 -> V_30 )
return V_90 -> V_32 ;
else {
V_90 -> V_34 = F_9 ( V_65 ) ;
return V_90 -> V_34 ;
}
}
}
V_93:
V_90 -> V_35 = 0 ;
F_47 ( & V_90 -> V_37 ) ;
return NULL ;
}
static void F_48 ( struct V_7 * V_90 ,
T_1 T_2 * V_3 ,
T_3 V_66 ,
T_3 V_27 , T_3 V_28 , T_3 V_65 )
{
T_3 V_98 = V_27 - V_66 ;
T_3 V_99 ;
T_3 * V_100 = ( V_90 -> V_34 != NULL ) ?
V_90 -> V_34 : V_90 -> V_32 ;
if ( V_65 < V_98 )
V_98 = V_65 ;
F_14 ( V_65 , V_3 + V_97 ) ;
F_16 () ;
F_49 ( V_3 + ( V_66 >> 2 ) , V_100 , V_98 ) ;
V_99 = V_65 - V_98 ;
if ( V_99 )
F_49 ( V_3 + ( V_28 >> 2 ) , V_100 + ( V_98 >> 2 ) ,
V_99 ) ;
}
static void F_50 ( struct V_7 * V_90 ,
T_1 T_2 * V_3 ,
T_3 V_66 ,
T_3 V_27 , T_3 V_28 , T_3 V_65 )
{
T_3 * V_100 = ( V_90 -> V_34 != NULL ) ?
V_90 -> V_34 : V_90 -> V_32 ;
while ( V_65 > 0 ) {
F_14 ( * V_100 ++ , V_3 + ( V_66 >> 2 ) ) ;
V_66 += sizeof( T_3 ) ;
if ( F_10 ( V_66 == V_27 ) )
V_66 = V_28 ;
F_16 () ;
F_14 ( V_66 , V_3 + V_52 ) ;
F_16 () ;
V_65 -= sizeof( T_3 ) ;
}
}
void F_51 ( struct V_1 * V_2 , T_3 V_65 )
{
struct V_7 * V_90 = & V_2 -> V_8 ;
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_66 = F_6 ( V_3 + V_52 ) ;
T_3 V_27 = F_6 ( V_3 + V_51 ) ;
T_3 V_28 = F_6 ( V_3 + V_18 ) ;
bool V_91 = V_90 -> V_9 & V_92 ;
F_46 ( ( V_65 & 3 ) != 0 ) ;
F_46 ( V_65 > V_90 -> V_35 ) ;
V_90 -> V_35 = 0 ;
if ( V_90 -> V_36 ) {
if ( V_91 )
F_48 ( V_90 , V_3 ,
V_66 , V_27 , V_28 , V_65 ) ;
else
F_50 ( V_90 , V_3 ,
V_66 , V_27 , V_28 , V_65 ) ;
if ( V_90 -> V_34 ) {
F_27 ( V_90 -> V_34 ) ;
V_90 -> V_34 = NULL ;
}
}
F_52 ( & V_90 -> V_38 ) ;
if ( V_90 -> V_36 || V_91 ) {
V_66 += V_65 ;
if ( V_66 >= V_27 )
V_66 -= V_27 - V_28 ;
F_16 () ;
F_14 ( V_66 , V_3 + V_52 ) ;
}
if ( V_91 )
F_14 ( 0 , V_3 + V_97 ) ;
F_16 () ;
F_53 ( & V_90 -> V_38 ) ;
F_20 ( V_2 , V_63 ) ;
F_47 ( & V_90 -> V_37 ) ;
}
int F_19 ( struct V_1 * V_2 , T_3 * V_101 )
{
struct V_7 * V_90 = & V_2 -> V_8 ;
struct V_102 * V_103 ;
void * V_104 ;
int V_70 = 0 ;
T_3 V_65 = sizeof( T_1 ) + sizeof( * V_103 ) ;
V_104 = F_44 ( V_2 , V_65 ) ;
if ( F_10 ( V_104 == NULL ) ) {
* V_101 = F_54 ( & V_2 -> V_55 ) ;
V_70 = - V_33 ;
( void ) F_55 ( V_2 , false , true , * V_101 ,
false , 3 * V_96 ) ;
goto V_93;
}
do {
* V_101 = F_39 ( 1 , & V_2 -> V_55 ) ;
} while ( * V_101 == 0 );
if ( ! ( V_90 -> V_9 & V_105 ) ) {
F_51 ( V_2 , 0 ) ;
return 0 ;
}
* ( T_1 * ) V_104 = F_56 ( V_106 ) ;
V_103 = (struct V_102 * )
( ( unsigned long ) V_104 + sizeof( T_1 ) ) ;
F_14 ( * V_101 , & V_103 -> V_107 ) ;
F_51 ( V_2 , V_65 ) ;
( void ) F_57 ( & V_90 -> V_58 , * V_101 ) ;
F_58 ( V_2 , V_90 ) ;
V_93:
return V_70 ;
}
static int F_59 ( struct V_1 * V_2 ,
T_3 V_108 )
{
struct V_109 * V_110 = V_2 -> V_111 ;
struct {
T_4 V_112 ;
T_5 V_113 ;
} * V_114 ;
V_114 = F_44 ( V_2 , sizeof( * V_114 ) ) ;
if ( F_10 ( V_114 == NULL ) ) {
F_33 ( L_8 ) ;
return - V_33 ;
}
V_114 -> V_112 . V_115 = V_116 ;
V_114 -> V_112 . V_117 = sizeof( V_114 -> V_113 ) ;
V_114 -> V_113 . V_108 = V_108 ;
V_114 -> V_113 . type = V_118 ;
if ( V_110 -> V_119 . V_120 == V_121 ) {
V_114 -> V_113 . V_122 . V_123 = V_124 ;
V_114 -> V_113 . V_122 . V_125 = V_110 -> V_125 ;
} else {
V_114 -> V_113 . V_122 . V_123 = V_110 -> V_119 . V_126 ;
V_114 -> V_113 . V_122 . V_125 = 0 ;
}
F_51 ( V_2 , sizeof( * V_114 ) ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
T_3 V_108 )
{
struct V_109 * V_110 = V_2 -> V_111 ;
struct {
T_4 V_112 ;
T_6 V_113 ;
} * V_114 ;
V_114 = F_44 ( V_2 , sizeof( * V_114 ) ) ;
if ( F_10 ( V_114 == NULL ) ) {
F_33 ( L_8 ) ;
return - V_33 ;
}
V_114 -> V_112 . V_115 = V_127 ;
V_114 -> V_112 . V_117 = sizeof( V_114 -> V_113 ) ;
V_114 -> V_113 . V_108 = V_108 ;
V_114 -> V_113 . type = V_118 ;
F_46 ( V_110 -> V_119 . V_120 != V_128 ) ;
V_114 -> V_113 . V_129 = V_110 -> V_119 . V_126 ;
V_114 -> V_113 . V_125 = 0 ;
F_51 ( V_2 , sizeof( * V_114 ) ) ;
return 0 ;
}
int F_61 ( struct V_1 * V_2 ,
T_3 V_108 )
{
if ( V_2 -> V_13 )
return F_60 ( V_2 , V_108 ) ;
return F_59 ( V_2 , V_108 ) ;
}
