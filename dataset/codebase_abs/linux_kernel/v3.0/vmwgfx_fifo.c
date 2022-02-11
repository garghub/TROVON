bool F_1 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_5 , V_6 ;
if ( ! ( V_2 -> V_7 & V_8 ) )
return false ;
V_5 = F_2 ( V_3 + V_9 ) ;
if ( V_5 <= V_10 * sizeof( unsigned int ) )
return false ;
V_6 = F_2 ( V_3 + V_10 ) ;
if ( V_6 == 0 )
return false ;
if ( V_6 < V_11 )
return false ;
return true ;
}
bool F_3 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_12 ;
if ( ! ( V_2 -> V_7 & V_8 ) )
return false ;
V_12 = F_2 ( V_3 + V_13 ) ;
if ( V_12 & V_14 )
return true ;
return false ;
}
int F_4 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_17 ;
T_3 V_18 ;
T_3 V_19 ;
int V_20 ;
V_16 -> V_21 = V_22 ;
V_16 -> V_23 = F_5 ( V_16 -> V_21 ) ;
if ( F_6 ( V_16 -> V_23 == NULL ) )
return - V_24 ;
V_16 -> V_25 = V_22 ;
V_16 -> V_26 = 0 ;
V_16 -> V_27 = false ;
V_16 -> V_28 = F_5 ( V_16 -> V_25 ) ;
if ( F_6 ( V_16 -> V_28 == NULL ) ) {
V_20 = - V_24 ;
goto V_29;
}
V_16 -> V_30 = NULL ;
V_16 -> V_31 = 0 ;
V_16 -> V_32 = false ;
F_7 ( & V_16 -> V_33 ) ;
F_8 ( & V_16 -> V_34 ) ;
F_9 ( L_1 , F_10 ( V_2 , V_35 ) ) ;
F_9 ( L_2 , F_10 ( V_2 , V_36 ) ) ;
F_9 ( L_3 , F_10 ( V_2 , V_37 ) ) ;
F_11 ( & V_2 -> V_38 ) ;
V_2 -> V_39 = F_10 ( V_2 , V_40 ) ;
V_2 -> V_41 = F_10 ( V_2 , V_42 ) ;
V_2 -> V_43 = F_10 ( V_2 , V_44 ) ;
F_12 ( V_2 , V_40 , 1 ) ;
V_18 = 4 ;
if ( V_2 -> V_7 & V_8 )
V_18 = F_10 ( V_2 , V_45 ) ;
V_18 <<= 2 ;
if ( V_18 < V_46 )
V_18 = V_46 ;
F_13 ( V_18 , V_3 + V_9 ) ;
F_13 ( V_2 -> V_47 , V_3 + V_48 ) ;
F_14 () ;
F_13 ( V_18 , V_3 + V_49 ) ;
F_13 ( V_18 , V_3 + V_50 ) ;
F_13 ( 0 , V_3 + V_51 ) ;
F_15 () ;
F_12 ( V_2 , V_42 , 1 ) ;
F_16 ( & V_2 -> V_38 ) ;
V_17 = F_2 ( V_3 + V_48 ) ;
V_18 = F_2 ( V_3 + V_9 ) ;
V_16 -> V_7 = F_2 ( V_3 + V_13 ) ;
F_9 ( L_4 ,
( unsigned int ) V_17 ,
( unsigned int ) V_18 ,
( unsigned int ) V_16 -> V_7 ) ;
F_17 ( & V_2 -> V_52 , V_2 -> V_53 ) ;
F_13 ( V_2 -> V_53 , V_3 + V_54 ) ;
F_18 ( & V_16 -> V_55 ) ;
return F_19 ( V_2 , & V_19 ) ;
V_29:
F_20 ( V_16 -> V_23 ) ;
V_16 -> V_23 = NULL ;
return V_20 ;
}
void F_21 ( struct V_1 * V_2 , T_3 V_56 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
F_11 ( & V_2 -> V_38 ) ;
if ( F_6 ( F_2 ( V_3 + V_51 ) == 0 ) ) {
F_13 ( 1 , V_3 + V_51 ) ;
F_12 ( V_2 , V_57 , V_56 ) ;
}
F_16 ( & V_2 -> V_38 ) ;
}
void F_22 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
F_11 ( & V_2 -> V_38 ) ;
while ( F_10 ( V_2 , V_58 ) != 0 )
F_12 ( V_2 , V_57 , V_59 ) ;
V_2 -> V_53 = F_2 ( V_3 + V_54 ) ;
F_12 ( V_2 , V_42 ,
V_2 -> V_41 ) ;
F_12 ( V_2 , V_40 ,
V_2 -> V_39 ) ;
F_12 ( V_2 , V_44 ,
V_2 -> V_43 ) ;
F_16 ( & V_2 -> V_38 ) ;
F_23 ( & V_16 -> V_55 ) ;
if ( F_24 ( V_16 -> V_28 != NULL ) ) {
F_20 ( V_16 -> V_28 ) ;
V_16 -> V_28 = NULL ;
}
if ( F_24 ( V_16 -> V_23 != NULL ) ) {
F_20 ( V_16 -> V_23 ) ;
V_16 -> V_23 = NULL ;
}
if ( F_24 ( V_16 -> V_30 != NULL ) ) {
F_20 ( V_16 -> V_30 ) ;
V_16 -> V_30 = NULL ;
}
}
static bool F_25 ( struct V_1 * V_2 , T_3 V_60 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_17 = F_2 ( V_3 + V_48 ) ;
T_3 V_61 = F_2 ( V_3 + V_49 ) ;
T_3 V_18 = F_2 ( V_3 + V_9 ) ;
T_3 V_62 = F_2 ( V_3 + V_50 ) ;
return ( ( V_17 - V_61 ) + ( V_62 - V_18 ) <= V_60 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
T_3 V_60 , bool V_63 ,
unsigned long V_64 )
{
int V_20 = 0 ;
unsigned long V_65 = V_66 + V_64 ;
F_27 ( V_67 ) ;
F_9 ( L_5 ) ;
for (; ; ) {
F_28 ( & V_2 -> V_68 , & V_67 ,
( V_63 ) ?
V_69 : V_70 ) ;
if ( ! F_25 ( V_2 , V_60 ) )
break;
if ( F_29 ( V_66 , V_65 ) ) {
V_20 = - V_71 ;
F_30 ( L_6 ) ;
break;
}
F_31 ( 1 ) ;
if ( V_63 && F_32 ( V_72 ) ) {
V_20 = - V_73 ;
break;
}
}
F_33 ( & V_2 -> V_68 , & V_67 ) ;
F_34 ( & V_2 -> V_68 ) ;
F_9 ( L_7 ) ;
return V_20 ;
}
static int F_35 ( struct V_1 * V_2 ,
T_3 V_60 , bool V_63 ,
unsigned long V_64 )
{
long V_20 = 1L ;
unsigned long V_74 ;
if ( F_24 ( ! F_25 ( V_2 , V_60 ) ) )
return 0 ;
F_21 ( V_2 , V_75 ) ;
if ( ! ( V_2 -> V_7 & V_76 ) )
return F_26 ( V_2 , V_60 ,
V_63 , V_64 ) ;
F_11 ( & V_2 -> V_38 ) ;
if ( F_36 ( 1 , & V_2 -> V_77 ) > 0 ) {
F_37 ( & V_2 -> V_78 , V_74 ) ;
F_38 ( V_79 ,
V_2 -> V_80 + V_81 ) ;
F_12 ( V_2 , V_82 ,
F_10 ( V_2 , V_82 ) |
V_79 ) ;
F_39 ( & V_2 -> V_78 , V_74 ) ;
}
F_16 ( & V_2 -> V_38 ) ;
if ( V_63 )
V_20 = F_40
( V_2 -> V_68 ,
! F_25 ( V_2 , V_60 ) , V_64 ) ;
else
V_20 = F_41
( V_2 -> V_68 ,
! F_25 ( V_2 , V_60 ) , V_64 ) ;
if ( F_6 ( V_20 == 0 ) )
V_20 = - V_71 ;
else if ( F_24 ( V_20 > 0 ) )
V_20 = 0 ;
F_11 ( & V_2 -> V_38 ) ;
if ( F_42 ( & V_2 -> V_77 ) ) {
F_37 ( & V_2 -> V_78 , V_74 ) ;
F_12 ( V_2 , V_82 ,
F_10 ( V_2 , V_82 ) &
~ V_79 ) ;
F_39 ( & V_2 -> V_78 , V_74 ) ;
}
F_16 ( & V_2 -> V_38 ) ;
return V_20 ;
}
void * F_43 ( struct V_1 * V_2 , T_3 V_60 )
{
struct V_15 * V_83 = & V_2 -> V_16 ;
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_17 ;
T_3 V_18 ;
T_3 V_61 ;
T_3 V_84 = V_83 -> V_7 & V_85 ;
int V_20 ;
F_11 ( & V_83 -> V_33 ) ;
V_17 = F_2 ( V_3 + V_48 ) ;
V_18 = F_2 ( V_3 + V_9 ) ;
V_61 = F_2 ( V_3 + V_49 ) ;
if ( F_6 ( V_60 >= ( V_17 - V_18 ) ) )
goto V_29;
F_44 ( V_83 -> V_31 != 0 ) ;
F_44 ( V_83 -> V_30 != NULL ) ;
V_83 -> V_31 = V_60 ;
while ( 1 ) {
T_3 V_62 = F_2 ( V_3 + V_50 ) ;
bool V_86 = false ;
bool V_87 = false ;
if ( V_61 >= V_62 ) {
if ( F_24 ( ( V_61 + V_60 < V_17 ||
( V_61 + V_60 == V_17 && V_62 > V_18 ) ) ) )
V_87 = true ;
else if ( F_25 ( V_2 , V_60 ) ) {
V_20 = F_35 ( V_2 , V_60 ,
false , 3 * V_88 ) ;
if ( F_6 ( V_20 != 0 ) )
goto V_29;
} else
V_86 = true ;
} else {
if ( F_24 ( ( V_61 + V_60 < V_62 ) ) )
V_87 = true ;
else {
V_20 = F_35 ( V_2 , V_60 ,
false , 3 * V_88 ) ;
if ( F_6 ( V_20 != 0 ) )
goto V_29;
}
}
if ( V_87 ) {
if ( V_84 || V_60 <= sizeof( T_3 ) ) {
V_83 -> V_32 = false ;
if ( V_84 )
F_13 ( V_60 , V_3 +
V_89 ) ;
return V_3 + ( V_61 >> 2 ) ;
} else {
V_86 = true ;
}
}
if ( V_86 ) {
V_83 -> V_32 = true ;
if ( V_60 < V_83 -> V_21 )
return V_83 -> V_23 ;
else {
V_83 -> V_30 = F_5 ( V_60 ) ;
return V_83 -> V_30 ;
}
}
}
V_29:
V_83 -> V_31 = 0 ;
F_16 ( & V_83 -> V_33 ) ;
return NULL ;
}
static void F_45 ( struct V_15 * V_83 ,
T_1 T_2 * V_3 ,
T_3 V_61 ,
T_3 V_17 , T_3 V_18 , T_3 V_60 )
{
T_3 V_90 = V_17 - V_61 ;
T_3 V_91 ;
T_3 * V_92 = ( V_83 -> V_30 != NULL ) ?
V_83 -> V_30 : V_83 -> V_23 ;
if ( V_60 < V_90 )
V_90 = V_60 ;
F_13 ( V_60 , V_3 + V_89 ) ;
F_15 () ;
F_46 ( V_3 + ( V_61 >> 2 ) , V_92 , V_90 ) ;
V_91 = V_60 - V_90 ;
if ( V_91 )
F_46 ( V_3 + ( V_18 >> 2 ) , V_92 + ( V_90 >> 2 ) ,
V_91 ) ;
}
static void F_47 ( struct V_15 * V_83 ,
T_1 T_2 * V_3 ,
T_3 V_61 ,
T_3 V_17 , T_3 V_18 , T_3 V_60 )
{
T_3 * V_92 = ( V_83 -> V_30 != NULL ) ?
V_83 -> V_30 : V_83 -> V_23 ;
while ( V_60 > 0 ) {
F_13 ( * V_92 ++ , V_3 + ( V_61 >> 2 ) ) ;
V_61 += sizeof( T_3 ) ;
if ( F_6 ( V_61 == V_17 ) )
V_61 = V_18 ;
F_15 () ;
F_13 ( V_61 , V_3 + V_49 ) ;
F_15 () ;
V_60 -= sizeof( T_3 ) ;
}
}
void F_48 ( struct V_1 * V_2 , T_3 V_60 )
{
struct V_15 * V_83 = & V_2 -> V_16 ;
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_61 = F_2 ( V_3 + V_49 ) ;
T_3 V_17 = F_2 ( V_3 + V_48 ) ;
T_3 V_18 = F_2 ( V_3 + V_9 ) ;
bool V_84 = V_83 -> V_7 & V_85 ;
F_44 ( ( V_60 & 3 ) != 0 ) ;
F_44 ( V_60 > V_83 -> V_31 ) ;
V_83 -> V_31 = 0 ;
if ( V_83 -> V_32 ) {
if ( V_84 )
F_45 ( V_83 , V_3 ,
V_61 , V_17 , V_18 , V_60 ) ;
else
F_47 ( V_83 , V_3 ,
V_61 , V_17 , V_18 , V_60 ) ;
if ( V_83 -> V_30 ) {
F_20 ( V_83 -> V_30 ) ;
V_83 -> V_30 = NULL ;
}
}
F_49 ( & V_83 -> V_34 ) ;
if ( V_83 -> V_32 || V_84 ) {
V_61 += V_60 ;
if ( V_61 >= V_17 )
V_61 -= V_17 - V_18 ;
F_15 () ;
F_13 ( V_61 , V_3 + V_49 ) ;
}
if ( V_84 )
F_13 ( 0 , V_3 + V_89 ) ;
F_15 () ;
F_50 ( & V_83 -> V_34 ) ;
F_21 ( V_2 , V_59 ) ;
F_16 ( & V_83 -> V_33 ) ;
}
int F_19 ( struct V_1 * V_2 , T_3 * V_93 )
{
struct V_15 * V_83 = & V_2 -> V_16 ;
struct V_94 * V_95 ;
void * V_96 ;
int V_20 = 0 ;
T_3 V_60 = sizeof( T_1 ) + sizeof( * V_95 ) ;
V_96 = F_43 ( V_2 , V_60 ) ;
if ( F_6 ( V_96 == NULL ) ) {
* V_93 = F_51 ( & V_2 -> V_52 ) ;
V_20 = - V_24 ;
( void ) F_52 ( V_2 , false , true , * V_93 ,
false , 3 * V_88 ) ;
goto V_29;
}
do {
* V_93 = F_36 ( 1 , & V_2 -> V_52 ) ;
} while ( * V_93 == 0 );
if ( ! ( V_83 -> V_7 & V_97 ) ) {
F_48 ( V_2 , 0 ) ;
return 0 ;
}
* ( T_1 * ) V_96 = F_53 ( V_98 ) ;
V_95 = (struct V_94 * )
( ( unsigned long ) V_96 + sizeof( T_1 ) ) ;
F_13 ( * V_93 , & V_95 -> V_99 ) ;
V_83 -> V_27 = true ;
F_48 ( V_2 , V_60 ) ;
V_83 -> V_27 = false ;
( void ) F_54 ( & V_83 -> V_55 , * V_93 ) ;
F_55 ( V_2 , V_83 ) ;
V_29:
return V_20 ;
}
static int F_56 ( struct V_100 * V_101 , struct V_102 * V_103 )
{
int V_20 ;
unsigned long V_104 = ( unsigned long ) V_103 -> V_105 ;
if ( V_104 != V_101 -> V_106 )
return V_107 ;
V_20 = F_57 ( V_101 , V_104 , V_101 -> V_108 ) ;
if ( F_24 ( V_20 == - V_71 || V_20 == 0 ) )
return V_109 ;
else if ( V_20 == - V_24 )
return V_110 ;
return V_107 ;
}
int F_58 ( struct V_111 * V_112 , struct V_100 * V_101 )
{
struct V_113 * V_114 ;
struct V_1 * V_2 ;
V_114 = V_112 -> V_115 ;
V_2 = F_59 ( V_114 -> V_116 -> V_117 ) ;
if ( V_101 -> V_108 != ( V_2 -> V_118 >> V_119 ) ||
( V_101 -> V_120 - V_101 -> V_106 ) != V_46 )
return - V_121 ;
V_101 -> V_122 &= ~ ( V_123 | V_124 ) ;
V_101 -> V_122 |= V_125 | V_126 | V_127 | V_128 ;
V_101 -> V_129 = F_60 ( V_101 -> V_122 ) ;
V_101 -> V_129 = F_61 ( V_130 ,
V_101 -> V_129 ) ;
V_101 -> V_131 = & V_132 ;
return 0 ;
}
