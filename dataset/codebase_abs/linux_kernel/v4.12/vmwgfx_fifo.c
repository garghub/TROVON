bool F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_4 ;
T_2 V_5 , V_6 ;
const struct V_7 * V_8 = & V_2 -> V_8 ;
if ( ! ( V_2 -> V_9 & V_10 ) )
return false ;
if ( V_2 -> V_9 & V_11 ) {
T_2 V_12 ;
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
T_1 * V_3 = V_2 -> V_4 ;
T_2 V_25 ;
if ( ! ( V_2 -> V_9 & V_17 ) )
return false ;
V_25 = F_6 ( V_3 + V_26 ) ;
if ( V_25 & V_27 )
return true ;
return false ;
}
int F_8 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 * V_3 = V_2 -> V_4 ;
T_2 V_28 ;
T_2 V_29 ;
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
void F_19 ( struct V_1 * V_2 , T_2 V_62 )
{
T_1 * V_3 = V_2 -> V_4 ;
F_20 () ;
if ( F_21 ( V_3 + V_57 , 0 , 1 ) == 0 )
F_3 ( V_2 , V_63 , V_62 ) ;
F_22 () ;
}
void F_23 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 * V_3 = V_2 -> V_4 ;
F_3 ( V_2 , V_63 , V_64 ) ;
while ( F_4 ( V_2 , V_65 ) != 0 )
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
static bool F_27 ( struct V_1 * V_2 , T_2 V_66 )
{
T_1 * V_3 = V_2 -> V_4 ;
T_2 V_28 = F_6 ( V_3 + V_54 ) ;
T_2 V_67 = F_6 ( V_3 + V_55 ) ;
T_2 V_29 = F_6 ( V_3 + V_18 ) ;
T_2 V_68 = F_6 ( V_3 + V_56 ) ;
return ( ( V_28 - V_67 ) + ( V_68 - V_29 ) <= V_66 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
T_2 V_66 , bool V_69 ,
unsigned long V_70 )
{
int V_71 = 0 ;
unsigned long V_72 = V_73 + V_70 ;
F_29 ( V_74 ) ;
F_13 ( L_5 ) ;
for (; ; ) {
F_30 ( & V_2 -> V_75 , & V_74 ,
( V_69 ) ?
V_76 : V_77 ) ;
if ( ! F_27 ( V_2 , V_66 ) )
break;
if ( F_31 ( V_73 , V_72 ) ) {
V_71 = - V_78 ;
F_32 ( L_6 ) ;
break;
}
F_33 ( 1 ) ;
if ( V_69 && F_34 ( V_79 ) ) {
V_71 = - V_80 ;
break;
}
}
F_35 ( & V_2 -> V_75 , & V_74 ) ;
F_36 ( & V_2 -> V_75 ) ;
F_13 ( L_7 ) ;
return V_71 ;
}
static int F_37 ( struct V_1 * V_2 ,
T_2 V_66 , bool V_69 ,
unsigned long V_70 )
{
long V_71 = 1L ;
if ( F_25 ( ! F_27 ( V_2 , V_66 ) ) )
return 0 ;
F_19 ( V_2 , V_81 ) ;
if ( ! ( V_2 -> V_9 & V_82 ) )
return F_28 ( V_2 , V_66 ,
V_69 , V_70 ) ;
F_38 ( V_2 , V_83 ,
& V_2 -> V_84 ) ;
if ( V_69 )
V_71 = F_39
( V_2 -> V_75 ,
! F_27 ( V_2 , V_66 ) , V_70 ) ;
else
V_71 = F_40
( V_2 -> V_75 ,
! F_27 ( V_2 , V_66 ) , V_70 ) ;
if ( F_10 ( V_71 == 0 ) )
V_71 = - V_78 ;
else if ( F_25 ( V_71 > 0 ) )
V_71 = 0 ;
F_41 ( V_2 , V_83 ,
& V_2 -> V_84 ) ;
return V_71 ;
}
static void * F_42 ( struct V_1 * V_2 ,
T_2 V_66 )
{
struct V_7 * V_85 = & V_2 -> V_8 ;
T_1 * V_3 = V_2 -> V_4 ;
T_2 V_28 ;
T_2 V_29 ;
T_2 V_67 ;
T_2 V_86 = V_85 -> V_9 & V_87 ;
int V_71 ;
F_43 ( & V_85 -> V_38 ) ;
V_28 = F_6 ( V_3 + V_54 ) ;
V_29 = F_6 ( V_3 + V_18 ) ;
V_67 = F_6 ( V_3 + V_55 ) ;
if ( F_10 ( V_66 >= ( V_28 - V_29 ) ) )
goto V_88;
F_44 ( V_85 -> V_36 != 0 ) ;
F_44 ( V_85 -> V_35 != NULL ) ;
V_85 -> V_36 = V_66 ;
while ( 1 ) {
T_2 V_68 = F_6 ( V_3 + V_56 ) ;
bool V_89 = false ;
bool V_90 = false ;
if ( V_67 >= V_68 ) {
if ( F_25 ( ( V_67 + V_66 < V_28 ||
( V_67 + V_66 == V_28 && V_68 > V_29 ) ) ) )
V_90 = true ;
else if ( F_27 ( V_2 , V_66 ) ) {
V_71 = F_37 ( V_2 , V_66 ,
false , 3 * V_91 ) ;
if ( F_10 ( V_71 != 0 ) )
goto V_88;
} else
V_89 = true ;
} else {
if ( F_25 ( ( V_67 + V_66 < V_68 ) ) )
V_90 = true ;
else {
V_71 = F_37 ( V_2 , V_66 ,
false , 3 * V_91 ) ;
if ( F_10 ( V_71 != 0 ) )
goto V_88;
}
}
if ( V_90 ) {
if ( V_86 || V_66 <= sizeof( T_2 ) ) {
V_85 -> V_37 = false ;
if ( V_86 )
F_14 ( V_66 , V_3 +
V_92 ) ;
return ( void V_93 * ) ( V_3 +
( V_67 >> 2 ) ) ;
} else {
V_89 = true ;
}
}
if ( V_89 ) {
V_85 -> V_37 = true ;
if ( V_66 < V_85 -> V_31 )
return V_85 -> V_33 ;
else {
V_85 -> V_35 = F_9 ( V_66 ) ;
if ( ! V_85 -> V_35 )
goto V_88;
return V_85 -> V_35 ;
}
}
}
V_88:
V_85 -> V_36 = 0 ;
F_45 ( & V_85 -> V_38 ) ;
return NULL ;
}
void * F_46 ( struct V_1 * V_2 , T_2 V_66 ,
int V_94 )
{
void * V_71 ;
if ( V_2 -> V_95 )
V_71 = F_47 ( V_2 -> V_95 , V_66 ,
V_94 , false , NULL ) ;
else if ( V_94 == V_96 )
V_71 = F_42 ( V_2 , V_66 ) ;
else {
F_48 ( 1 , L_8 ) ;
V_71 = NULL ;
}
if ( F_49 ( V_71 ) ) {
F_32 ( L_9 ,
( unsigned ) V_66 ) ;
F_50 () ;
return NULL ;
}
return V_71 ;
}
static void F_51 ( struct V_7 * V_85 ,
T_1 * V_3 ,
T_2 V_67 ,
T_2 V_28 , T_2 V_29 , T_2 V_66 )
{
T_2 V_97 = V_28 - V_67 ;
T_2 V_98 ;
T_2 * V_99 = ( V_85 -> V_35 != NULL ) ?
V_85 -> V_35 : V_85 -> V_33 ;
if ( V_66 < V_97 )
V_97 = V_66 ;
F_14 ( V_66 , V_3 + V_92 ) ;
F_16 () ;
memcpy ( V_3 + ( V_67 >> 2 ) , V_99 , V_97 ) ;
V_98 = V_66 - V_97 ;
if ( V_98 )
memcpy ( V_3 + ( V_29 >> 2 ) , V_99 + ( V_97 >> 2 ) , V_98 ) ;
}
static void F_52 ( struct V_7 * V_85 ,
T_1 * V_3 ,
T_2 V_67 ,
T_2 V_28 , T_2 V_29 , T_2 V_66 )
{
T_2 * V_99 = ( V_85 -> V_35 != NULL ) ?
V_85 -> V_35 : V_85 -> V_33 ;
while ( V_66 > 0 ) {
F_14 ( * V_99 ++ , V_3 + ( V_67 >> 2 ) ) ;
V_67 += sizeof( T_2 ) ;
if ( F_10 ( V_67 == V_28 ) )
V_67 = V_29 ;
F_16 () ;
F_14 ( V_67 , V_3 + V_55 ) ;
F_16 () ;
V_66 -= sizeof( T_2 ) ;
}
}
static void F_53 ( struct V_1 * V_2 , T_2 V_66 )
{
struct V_7 * V_85 = & V_2 -> V_8 ;
T_1 * V_3 = V_2 -> V_4 ;
T_2 V_67 = F_6 ( V_3 + V_55 ) ;
T_2 V_28 = F_6 ( V_3 + V_54 ) ;
T_2 V_29 = F_6 ( V_3 + V_18 ) ;
bool V_86 = V_85 -> V_9 & V_87 ;
if ( V_85 -> V_30 )
V_66 += sizeof( struct V_100 ) ;
V_85 -> V_30 = false ;
F_44 ( ( V_66 & 3 ) != 0 ) ;
F_44 ( V_66 > V_85 -> V_36 ) ;
V_85 -> V_36 = 0 ;
if ( V_85 -> V_37 ) {
if ( V_86 )
F_51 ( V_85 , V_3 ,
V_67 , V_28 , V_29 , V_66 ) ;
else
F_52 ( V_85 , V_3 ,
V_67 , V_28 , V_29 , V_66 ) ;
if ( V_85 -> V_35 ) {
F_26 ( V_85 -> V_35 ) ;
V_85 -> V_35 = NULL ;
}
}
F_54 ( & V_85 -> V_39 ) ;
if ( V_85 -> V_37 || V_86 ) {
V_67 += V_66 ;
if ( V_67 >= V_28 )
V_67 -= V_28 - V_29 ;
F_16 () ;
F_14 ( V_67 , V_3 + V_55 ) ;
}
if ( V_86 )
F_14 ( 0 , V_3 + V_92 ) ;
F_16 () ;
F_55 ( & V_85 -> V_39 ) ;
F_19 ( V_2 , V_64 ) ;
F_45 ( & V_85 -> V_38 ) ;
}
void F_56 ( struct V_1 * V_2 , T_2 V_66 )
{
if ( V_2 -> V_95 )
F_57 ( V_2 -> V_95 , V_66 , NULL , false ) ;
else
F_53 ( V_2 , V_66 ) ;
}
void F_58 ( struct V_1 * V_2 , T_2 V_66 )
{
if ( V_2 -> V_95 )
F_57 ( V_2 -> V_95 , V_66 , NULL , true ) ;
else
F_53 ( V_2 , V_66 ) ;
}
int F_59 ( struct V_1 * V_2 , bool V_69 )
{
F_60 () ;
if ( V_2 -> V_95 )
return F_61 ( V_2 -> V_95 , V_69 ) ;
else
return 0 ;
}
int F_62 ( struct V_1 * V_2 , T_2 * V_101 )
{
struct V_7 * V_85 = & V_2 -> V_8 ;
struct V_102 * V_103 ;
T_1 * V_104 ;
int V_71 = 0 ;
T_2 V_66 = sizeof( T_1 ) + sizeof( * V_103 ) ;
V_104 = F_63 ( V_2 , V_66 ) ;
if ( F_10 ( V_104 == NULL ) ) {
* V_101 = F_64 ( & V_2 -> V_58 ) ;
V_71 = - V_34 ;
( void ) F_65 ( V_2 , false , true , * V_101 ,
false , 3 * V_91 ) ;
goto V_88;
}
do {
* V_101 = F_66 ( 1 , & V_2 -> V_58 ) ;
} while ( * V_101 == 0 );
if ( ! ( V_85 -> V_9 & V_105 ) ) {
F_56 ( V_2 , 0 ) ;
return 0 ;
}
* V_104 ++ = V_106 ;
V_103 = (struct V_102 * ) V_104 ;
V_103 -> V_107 = * V_101 ;
F_58 ( V_2 , V_66 ) ;
( void ) F_67 ( & V_85 -> V_61 , * V_101 ) ;
F_68 ( V_2 , V_85 ) ;
V_88:
return V_71 ;
}
static int F_69 ( struct V_1 * V_2 ,
T_2 V_108 )
{
struct V_109 * V_110 = & V_2 -> V_111 -> V_112 ;
struct {
T_3 V_113 ;
T_4 V_114 ;
} * V_115 ;
V_115 = F_63 ( V_2 , sizeof( * V_115 ) ) ;
if ( F_10 ( V_115 == NULL ) ) {
F_32 ( L_10 ) ;
return - V_34 ;
}
V_115 -> V_113 . V_116 = V_117 ;
V_115 -> V_113 . V_118 = sizeof( V_115 -> V_114 ) ;
V_115 -> V_114 . V_108 = V_108 ;
V_115 -> V_114 . type = V_119 ;
if ( V_110 -> V_120 . V_121 == V_122 ) {
V_115 -> V_114 . V_123 . V_124 = V_125 ;
V_115 -> V_114 . V_123 . V_126 = V_110 -> V_126 ;
} else {
V_115 -> V_114 . V_123 . V_124 = V_110 -> V_120 . V_127 ;
V_115 -> V_114 . V_123 . V_126 = 0 ;
}
F_56 ( V_2 , sizeof( * V_115 ) ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
T_2 V_108 )
{
struct V_109 * V_110 = & V_2 -> V_111 -> V_112 ;
struct {
T_3 V_113 ;
T_5 V_114 ;
} * V_115 ;
V_115 = F_63 ( V_2 , sizeof( * V_115 ) ) ;
if ( F_10 ( V_115 == NULL ) ) {
F_32 ( L_10 ) ;
return - V_34 ;
}
V_115 -> V_113 . V_116 = V_128 ;
V_115 -> V_113 . V_118 = sizeof( V_115 -> V_114 ) ;
V_115 -> V_114 . V_108 = V_108 ;
V_115 -> V_114 . type = V_119 ;
F_44 ( V_110 -> V_120 . V_121 != V_129 ) ;
V_115 -> V_114 . V_130 = V_110 -> V_120 . V_127 ;
V_115 -> V_114 . V_126 = 0 ;
F_56 ( V_2 , sizeof( * V_115 ) ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 ,
T_2 V_108 )
{
if ( V_2 -> V_13 )
return F_70 ( V_2 , V_108 ) ;
return F_69 ( V_2 , V_108 ) ;
}
void * F_63 ( struct V_1 * V_2 , T_2 V_66 )
{
return F_46 ( V_2 , V_66 , V_96 ) ;
}
