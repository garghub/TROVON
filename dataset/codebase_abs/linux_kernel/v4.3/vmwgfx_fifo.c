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
if ( V_2 -> V_23 == V_24 )
return false ;
return true ;
}
bool F_7 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_25 ;
if ( ! ( V_2 -> V_9 & V_17 ) )
return false ;
V_25 = F_6 ( V_3 + V_26 ) ;
if ( V_25 & V_27 )
return true ;
return false ;
}
int F_8 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_28 ;
T_3 V_29 ;
V_8 -> V_30 = false ;
V_8 -> V_31 = V_32 ;
V_8 -> V_33 = F_9 ( V_8 -> V_31 ) ;
if ( F_10 ( V_8 -> V_33 == NULL ) )
return - V_34 ;
V_8 -> V_35 = NULL ;
V_8 -> V_36 = 0 ;
V_8 -> V_37 = false ;
F_11 ( & V_8 -> V_38 ) ;
F_12 ( & V_8 -> V_39 ) ;
F_13 ( L_1 , F_4 ( V_2 , V_40 ) ) ;
F_13 ( L_2 , F_4 ( V_2 , V_41 ) ) ;
F_13 ( L_3 , F_4 ( V_2 , V_42 ) ) ;
V_2 -> V_43 = F_4 ( V_2 , V_44 ) ;
V_2 -> V_45 = F_4 ( V_2 , V_46 ) ;
V_2 -> V_47 = F_4 ( V_2 , V_48 ) ;
F_3 ( V_2 , V_44 , V_49 |
V_50 ) ;
F_3 ( V_2 , V_48 , 0 ) ;
V_29 = 4 ;
if ( V_2 -> V_9 & V_17 )
V_29 = F_4 ( V_2 , V_51 ) ;
V_29 <<= 2 ;
if ( V_29 < V_52 )
V_29 = V_52 ;
F_14 ( V_29 , V_3 + V_18 ) ;
F_14 ( V_2 -> V_53 , V_3 + V_54 ) ;
F_15 () ;
F_14 ( V_29 , V_3 + V_55 ) ;
F_14 ( V_29 , V_3 + V_56 ) ;
F_14 ( 0 , V_3 + V_57 ) ;
F_16 () ;
F_3 ( V_2 , V_46 , 1 ) ;
V_28 = F_6 ( V_3 + V_54 ) ;
V_29 = F_6 ( V_3 + V_18 ) ;
V_8 -> V_9 = F_6 ( V_3 + V_26 ) ;
F_13 ( L_4 ,
( unsigned int ) V_28 ,
( unsigned int ) V_29 ,
( unsigned int ) V_8 -> V_9 ) ;
F_17 ( & V_2 -> V_58 , V_2 -> V_59 ) ;
F_14 ( V_2 -> V_59 , V_3 + V_60 ) ;
F_18 ( & V_8 -> V_61 ) ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 , T_3 V_62 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
static F_20 ( V_63 ) ;
unsigned long V_64 ;
F_21 ( & V_63 , V_64 ) ;
if ( F_10 ( F_6 ( V_3 + V_57 ) == 0 ) ) {
F_14 ( 1 , V_3 + V_57 ) ;
F_3 ( V_2 , V_65 , V_62 ) ;
}
F_22 ( & V_63 , V_64 ) ;
}
void F_23 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
F_3 ( V_2 , V_65 , V_66 ) ;
while ( F_4 ( V_2 , V_67 ) != 0 )
;
V_2 -> V_59 = F_6 ( V_3 + V_60 ) ;
F_3 ( V_2 , V_46 ,
V_2 -> V_45 ) ;
F_3 ( V_2 , V_44 ,
V_2 -> V_43 ) ;
F_3 ( V_2 , V_48 ,
V_2 -> V_47 ) ;
F_24 ( & V_8 -> V_61 ) ;
if ( F_25 ( V_8 -> V_33 != NULL ) ) {
F_26 ( V_8 -> V_33 ) ;
V_8 -> V_33 = NULL ;
}
if ( F_25 ( V_8 -> V_35 != NULL ) ) {
F_26 ( V_8 -> V_35 ) ;
V_8 -> V_35 = NULL ;
}
}
static bool F_27 ( struct V_1 * V_2 , T_3 V_68 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_28 = F_6 ( V_3 + V_54 ) ;
T_3 V_69 = F_6 ( V_3 + V_55 ) ;
T_3 V_29 = F_6 ( V_3 + V_18 ) ;
T_3 V_70 = F_6 ( V_3 + V_56 ) ;
return ( ( V_28 - V_69 ) + ( V_70 - V_29 ) <= V_68 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
T_3 V_68 , bool V_71 ,
unsigned long V_72 )
{
int V_73 = 0 ;
unsigned long V_74 = V_75 + V_72 ;
F_29 ( V_76 ) ;
F_13 ( L_5 ) ;
for (; ; ) {
F_30 ( & V_2 -> V_77 , & V_76 ,
( V_71 ) ?
V_78 : V_79 ) ;
if ( ! F_27 ( V_2 , V_68 ) )
break;
if ( F_31 ( V_75 , V_74 ) ) {
V_73 = - V_80 ;
F_32 ( L_6 ) ;
break;
}
F_33 ( 1 ) ;
if ( V_71 && F_34 ( V_81 ) ) {
V_73 = - V_82 ;
break;
}
}
F_35 ( & V_2 -> V_77 , & V_76 ) ;
F_36 ( & V_2 -> V_77 ) ;
F_13 ( L_7 ) ;
return V_73 ;
}
static int F_37 ( struct V_1 * V_2 ,
T_3 V_68 , bool V_71 ,
unsigned long V_72 )
{
long V_73 = 1L ;
unsigned long V_64 ;
if ( F_25 ( ! F_27 ( V_2 , V_68 ) ) )
return 0 ;
F_19 ( V_2 , V_83 ) ;
if ( ! ( V_2 -> V_9 & V_84 ) )
return F_28 ( V_2 , V_68 ,
V_71 , V_72 ) ;
F_2 ( & V_2 -> V_85 ) ;
if ( F_38 ( 1 , & V_2 -> V_86 ) > 0 ) {
F_21 ( & V_2 -> V_87 , V_64 ) ;
F_39 ( V_88 ,
V_2 -> V_89 + V_90 ) ;
V_2 -> V_91 |= V_88 ;
F_3 ( V_2 , V_92 , V_2 -> V_91 ) ;
F_22 ( & V_2 -> V_87 , V_64 ) ;
}
F_5 ( & V_2 -> V_85 ) ;
if ( V_71 )
V_73 = F_40
( V_2 -> V_77 ,
! F_27 ( V_2 , V_68 ) , V_72 ) ;
else
V_73 = F_41
( V_2 -> V_77 ,
! F_27 ( V_2 , V_68 ) , V_72 ) ;
if ( F_10 ( V_73 == 0 ) )
V_73 = - V_80 ;
else if ( F_25 ( V_73 > 0 ) )
V_73 = 0 ;
F_2 ( & V_2 -> V_85 ) ;
if ( F_42 ( & V_2 -> V_86 ) ) {
F_21 ( & V_2 -> V_87 , V_64 ) ;
V_2 -> V_91 &= ~ V_88 ;
F_3 ( V_2 , V_92 , V_2 -> V_91 ) ;
F_22 ( & V_2 -> V_87 , V_64 ) ;
}
F_5 ( & V_2 -> V_85 ) ;
return V_73 ;
}
static void * F_43 ( struct V_1 * V_2 ,
T_3 V_68 )
{
struct V_7 * V_93 = & V_2 -> V_8 ;
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_28 ;
T_3 V_29 ;
T_3 V_69 ;
T_3 V_94 = V_93 -> V_9 & V_95 ;
int V_73 ;
F_44 ( & V_93 -> V_38 ) ;
V_28 = F_6 ( V_3 + V_54 ) ;
V_29 = F_6 ( V_3 + V_18 ) ;
V_69 = F_6 ( V_3 + V_55 ) ;
if ( F_10 ( V_68 >= ( V_28 - V_29 ) ) )
goto V_96;
F_45 ( V_93 -> V_36 != 0 ) ;
F_45 ( V_93 -> V_35 != NULL ) ;
V_93 -> V_36 = V_68 ;
while ( 1 ) {
T_3 V_70 = F_6 ( V_3 + V_56 ) ;
bool V_97 = false ;
bool V_98 = false ;
if ( V_69 >= V_70 ) {
if ( F_25 ( ( V_69 + V_68 < V_28 ||
( V_69 + V_68 == V_28 && V_70 > V_29 ) ) ) )
V_98 = true ;
else if ( F_27 ( V_2 , V_68 ) ) {
V_73 = F_37 ( V_2 , V_68 ,
false , 3 * V_99 ) ;
if ( F_10 ( V_73 != 0 ) )
goto V_96;
} else
V_97 = true ;
} else {
if ( F_25 ( ( V_69 + V_68 < V_70 ) ) )
V_98 = true ;
else {
V_73 = F_37 ( V_2 , V_68 ,
false , 3 * V_99 ) ;
if ( F_10 ( V_73 != 0 ) )
goto V_96;
}
}
if ( V_98 ) {
if ( V_94 || V_68 <= sizeof( T_3 ) ) {
V_93 -> V_37 = false ;
if ( V_94 )
F_14 ( V_68 , V_3 +
V_100 ) ;
return ( void V_101 * ) ( V_3 +
( V_69 >> 2 ) ) ;
} else {
V_97 = true ;
}
}
if ( V_97 ) {
V_93 -> V_37 = true ;
if ( V_68 < V_93 -> V_31 )
return V_93 -> V_33 ;
else {
V_93 -> V_35 = F_9 ( V_68 ) ;
return V_93 -> V_35 ;
}
}
}
V_96:
V_93 -> V_36 = 0 ;
F_46 ( & V_93 -> V_38 ) ;
return NULL ;
}
void * F_47 ( struct V_1 * V_2 , T_3 V_68 ,
int V_102 )
{
void * V_73 ;
if ( V_2 -> V_103 )
V_73 = F_48 ( V_2 -> V_103 , V_68 ,
V_102 , false , NULL ) ;
else if ( V_102 == V_104 )
V_73 = F_43 ( V_2 , V_68 ) ;
else {
F_49 ( L_8 ) ;
V_73 = NULL ;
}
if ( F_50 ( V_73 ) ) {
F_32 ( L_9 ,
( unsigned ) V_68 ) ;
F_51 () ;
return NULL ;
}
return V_73 ;
}
static void F_52 ( struct V_7 * V_93 ,
T_1 T_2 * V_3 ,
T_3 V_69 ,
T_3 V_28 , T_3 V_29 , T_3 V_68 )
{
T_3 V_105 = V_28 - V_69 ;
T_3 V_106 ;
T_3 * V_107 = ( V_93 -> V_35 != NULL ) ?
V_93 -> V_35 : V_93 -> V_33 ;
if ( V_68 < V_105 )
V_105 = V_68 ;
F_14 ( V_68 , V_3 + V_100 ) ;
F_16 () ;
F_53 ( V_3 + ( V_69 >> 2 ) , V_107 , V_105 ) ;
V_106 = V_68 - V_105 ;
if ( V_106 )
F_53 ( V_3 + ( V_29 >> 2 ) , V_107 + ( V_105 >> 2 ) ,
V_106 ) ;
}
static void F_54 ( struct V_7 * V_93 ,
T_1 T_2 * V_3 ,
T_3 V_69 ,
T_3 V_28 , T_3 V_29 , T_3 V_68 )
{
T_3 * V_107 = ( V_93 -> V_35 != NULL ) ?
V_93 -> V_35 : V_93 -> V_33 ;
while ( V_68 > 0 ) {
F_14 ( * V_107 ++ , V_3 + ( V_69 >> 2 ) ) ;
V_69 += sizeof( T_3 ) ;
if ( F_10 ( V_69 == V_28 ) )
V_69 = V_29 ;
F_16 () ;
F_14 ( V_69 , V_3 + V_55 ) ;
F_16 () ;
V_68 -= sizeof( T_3 ) ;
}
}
static void F_55 ( struct V_1 * V_2 , T_3 V_68 )
{
struct V_7 * V_93 = & V_2 -> V_8 ;
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_69 = F_6 ( V_3 + V_55 ) ;
T_3 V_28 = F_6 ( V_3 + V_54 ) ;
T_3 V_29 = F_6 ( V_3 + V_18 ) ;
bool V_94 = V_93 -> V_9 & V_95 ;
if ( V_93 -> V_30 )
V_68 += sizeof( struct V_108 ) ;
V_93 -> V_30 = false ;
F_45 ( ( V_68 & 3 ) != 0 ) ;
F_45 ( V_68 > V_93 -> V_36 ) ;
V_93 -> V_36 = 0 ;
if ( V_93 -> V_37 ) {
if ( V_94 )
F_52 ( V_93 , V_3 ,
V_69 , V_28 , V_29 , V_68 ) ;
else
F_54 ( V_93 , V_3 ,
V_69 , V_28 , V_29 , V_68 ) ;
if ( V_93 -> V_35 ) {
F_26 ( V_93 -> V_35 ) ;
V_93 -> V_35 = NULL ;
}
}
F_56 ( & V_93 -> V_39 ) ;
if ( V_93 -> V_37 || V_94 ) {
V_69 += V_68 ;
if ( V_69 >= V_28 )
V_69 -= V_28 - V_29 ;
F_16 () ;
F_14 ( V_69 , V_3 + V_55 ) ;
}
if ( V_94 )
F_14 ( 0 , V_3 + V_100 ) ;
F_16 () ;
F_57 ( & V_93 -> V_39 ) ;
F_19 ( V_2 , V_66 ) ;
F_46 ( & V_93 -> V_38 ) ;
}
void F_58 ( struct V_1 * V_2 , T_3 V_68 )
{
if ( V_2 -> V_103 )
F_59 ( V_2 -> V_103 , V_68 , NULL , false ) ;
else
F_55 ( V_2 , V_68 ) ;
}
void F_60 ( struct V_1 * V_2 , T_3 V_68 )
{
if ( V_2 -> V_103 )
F_59 ( V_2 -> V_103 , V_68 , NULL , true ) ;
else
F_55 ( V_2 , V_68 ) ;
}
int F_61 ( struct V_1 * V_2 , bool V_71 )
{
F_62 () ;
if ( V_2 -> V_103 )
return F_63 ( V_2 -> V_103 , V_71 ) ;
else
return 0 ;
}
int F_64 ( struct V_1 * V_2 , T_3 * V_109 )
{
struct V_7 * V_93 = & V_2 -> V_8 ;
struct V_110 * V_111 ;
T_1 * V_112 ;
int V_73 = 0 ;
T_3 V_68 = sizeof( T_1 ) + sizeof( * V_111 ) ;
V_112 = F_65 ( V_2 , V_68 ) ;
if ( F_10 ( V_112 == NULL ) ) {
* V_109 = F_66 ( & V_2 -> V_58 ) ;
V_73 = - V_34 ;
( void ) F_67 ( V_2 , false , true , * V_109 ,
false , 3 * V_99 ) ;
goto V_96;
}
do {
* V_109 = F_38 ( 1 , & V_2 -> V_58 ) ;
} while ( * V_109 == 0 );
if ( ! ( V_93 -> V_9 & V_113 ) ) {
F_58 ( V_2 , 0 ) ;
return 0 ;
}
* V_112 ++ = V_114 ;
V_111 = (struct V_110 * ) V_112 ;
V_111 -> V_115 = * V_109 ;
F_60 ( V_2 , V_68 ) ;
( void ) F_68 ( & V_93 -> V_61 , * V_109 ) ;
F_69 ( V_2 , V_93 ) ;
V_96:
return V_73 ;
}
static int F_70 ( struct V_1 * V_2 ,
T_3 V_116 )
{
struct V_117 * V_118 = & V_2 -> V_119 -> V_120 ;
struct {
T_4 V_121 ;
T_5 V_122 ;
} * V_123 ;
V_123 = F_65 ( V_2 , sizeof( * V_123 ) ) ;
if ( F_10 ( V_123 == NULL ) ) {
F_32 ( L_10 ) ;
return - V_34 ;
}
V_123 -> V_121 . V_124 = V_125 ;
V_123 -> V_121 . V_126 = sizeof( V_123 -> V_122 ) ;
V_123 -> V_122 . V_116 = V_116 ;
V_123 -> V_122 . type = V_127 ;
if ( V_118 -> V_128 . V_129 == V_130 ) {
V_123 -> V_122 . V_131 . V_132 = V_133 ;
V_123 -> V_122 . V_131 . V_134 = V_118 -> V_134 ;
} else {
V_123 -> V_122 . V_131 . V_132 = V_118 -> V_128 . V_135 ;
V_123 -> V_122 . V_131 . V_134 = 0 ;
}
F_58 ( V_2 , sizeof( * V_123 ) ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
T_3 V_116 )
{
struct V_117 * V_118 = & V_2 -> V_119 -> V_120 ;
struct {
T_4 V_121 ;
T_6 V_122 ;
} * V_123 ;
V_123 = F_65 ( V_2 , sizeof( * V_123 ) ) ;
if ( F_10 ( V_123 == NULL ) ) {
F_32 ( L_10 ) ;
return - V_34 ;
}
V_123 -> V_121 . V_124 = V_136 ;
V_123 -> V_121 . V_126 = sizeof( V_123 -> V_122 ) ;
V_123 -> V_122 . V_116 = V_116 ;
V_123 -> V_122 . type = V_127 ;
F_45 ( V_118 -> V_128 . V_129 != V_137 ) ;
V_123 -> V_122 . V_138 = V_118 -> V_128 . V_135 ;
V_123 -> V_122 . V_134 = 0 ;
F_58 ( V_2 , sizeof( * V_123 ) ) ;
return 0 ;
}
int F_72 ( struct V_1 * V_2 ,
T_3 V_116 )
{
if ( V_2 -> V_13 )
return F_71 ( V_2 , V_116 ) ;
return F_70 ( V_2 , V_116 ) ;
}
void * F_65 ( struct V_1 * V_2 , T_3 V_68 )
{
return F_47 ( V_2 , V_68 , V_104 ) ;
}
