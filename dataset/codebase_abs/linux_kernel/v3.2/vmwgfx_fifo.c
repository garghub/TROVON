bool F_1 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_5 , V_6 ;
const struct V_7 * V_8 = & V_2 -> V_8 ;
if ( ! ( V_2 -> V_9 & V_10 ) )
return false ;
V_5 = F_2 ( V_3 + V_11 ) ;
if ( V_5 <= V_12 * sizeof( unsigned int ) )
return false ;
V_6 = F_2 ( V_3 +
( ( V_8 -> V_9 &
V_13 ) ?
V_14 :
V_12 ) ) ;
if ( V_6 == 0 )
return false ;
if ( V_6 < V_15 )
return false ;
if ( ! V_2 -> V_16 )
return false ;
return true ;
}
bool F_3 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_17 ;
if ( ! ( V_2 -> V_9 & V_10 ) )
return false ;
V_17 = F_2 ( V_3 + V_18 ) ;
if ( V_17 & V_19 )
return true ;
return false ;
}
int F_4 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_20 ;
T_3 V_21 ;
T_3 V_22 ;
V_8 -> V_23 = V_24 ;
V_8 -> V_25 = F_5 ( V_8 -> V_23 ) ;
if ( F_6 ( V_8 -> V_25 == NULL ) )
return - V_26 ;
V_8 -> V_27 = NULL ;
V_8 -> V_28 = 0 ;
V_8 -> V_29 = false ;
F_7 ( & V_8 -> V_30 ) ;
F_8 ( & V_8 -> V_31 ) ;
F_9 ( L_1 , F_10 ( V_2 , V_32 ) ) ;
F_9 ( L_2 , F_10 ( V_2 , V_33 ) ) ;
F_9 ( L_3 , F_10 ( V_2 , V_34 ) ) ;
F_11 ( & V_2 -> V_35 ) ;
V_2 -> V_36 = F_10 ( V_2 , V_37 ) ;
V_2 -> V_38 = F_10 ( V_2 , V_39 ) ;
V_2 -> V_40 = F_10 ( V_2 , V_41 ) ;
F_12 ( V_2 , V_37 , 1 ) ;
V_21 = 4 ;
if ( V_2 -> V_9 & V_10 )
V_21 = F_10 ( V_2 , V_42 ) ;
V_21 <<= 2 ;
if ( V_21 < V_43 )
V_21 = V_43 ;
F_13 ( V_21 , V_3 + V_11 ) ;
F_13 ( V_2 -> V_44 , V_3 + V_45 ) ;
F_14 () ;
F_13 ( V_21 , V_3 + V_46 ) ;
F_13 ( V_21 , V_3 + V_47 ) ;
F_13 ( 0 , V_3 + V_48 ) ;
F_15 () ;
F_12 ( V_2 , V_39 , 1 ) ;
F_16 ( & V_2 -> V_35 ) ;
V_20 = F_2 ( V_3 + V_45 ) ;
V_21 = F_2 ( V_3 + V_11 ) ;
V_8 -> V_9 = F_2 ( V_3 + V_18 ) ;
F_9 ( L_4 ,
( unsigned int ) V_20 ,
( unsigned int ) V_21 ,
( unsigned int ) V_8 -> V_9 ) ;
F_17 ( & V_2 -> V_49 , V_2 -> V_50 ) ;
F_13 ( V_2 -> V_50 , V_3 + V_51 ) ;
F_18 ( & V_8 -> V_52 ) ;
return F_19 ( V_2 , & V_22 ) ;
}
void F_20 ( struct V_1 * V_2 , T_3 V_53 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
F_11 ( & V_2 -> V_35 ) ;
if ( F_6 ( F_2 ( V_3 + V_48 ) == 0 ) ) {
F_13 ( 1 , V_3 + V_48 ) ;
F_12 ( V_2 , V_54 , V_53 ) ;
}
F_16 ( & V_2 -> V_35 ) ;
}
void F_21 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
F_11 ( & V_2 -> V_35 ) ;
while ( F_10 ( V_2 , V_55 ) != 0 )
F_12 ( V_2 , V_54 , V_56 ) ;
V_2 -> V_50 = F_2 ( V_3 + V_51 ) ;
F_12 ( V_2 , V_39 ,
V_2 -> V_38 ) ;
F_12 ( V_2 , V_37 ,
V_2 -> V_36 ) ;
F_12 ( V_2 , V_41 ,
V_2 -> V_40 ) ;
F_16 ( & V_2 -> V_35 ) ;
F_22 ( & V_8 -> V_52 ) ;
if ( F_23 ( V_8 -> V_25 != NULL ) ) {
F_24 ( V_8 -> V_25 ) ;
V_8 -> V_25 = NULL ;
}
if ( F_23 ( V_8 -> V_27 != NULL ) ) {
F_24 ( V_8 -> V_27 ) ;
V_8 -> V_27 = NULL ;
}
}
static bool F_25 ( struct V_1 * V_2 , T_3 V_57 )
{
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_20 = F_2 ( V_3 + V_45 ) ;
T_3 V_58 = F_2 ( V_3 + V_46 ) ;
T_3 V_21 = F_2 ( V_3 + V_11 ) ;
T_3 V_59 = F_2 ( V_3 + V_47 ) ;
return ( ( V_20 - V_58 ) + ( V_59 - V_21 ) <= V_57 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
T_3 V_57 , bool V_60 ,
unsigned long V_61 )
{
int V_62 = 0 ;
unsigned long V_63 = V_64 + V_61 ;
F_27 ( V_65 ) ;
F_9 ( L_5 ) ;
for (; ; ) {
F_28 ( & V_2 -> V_66 , & V_65 ,
( V_60 ) ?
V_67 : V_68 ) ;
if ( ! F_25 ( V_2 , V_57 ) )
break;
if ( F_29 ( V_64 , V_63 ) ) {
V_62 = - V_69 ;
F_30 ( L_6 ) ;
break;
}
F_31 ( 1 ) ;
if ( V_60 && F_32 ( V_70 ) ) {
V_62 = - V_71 ;
break;
}
}
F_33 ( & V_2 -> V_66 , & V_65 ) ;
F_34 ( & V_2 -> V_66 ) ;
F_9 ( L_7 ) ;
return V_62 ;
}
static int F_35 ( struct V_1 * V_2 ,
T_3 V_57 , bool V_60 ,
unsigned long V_61 )
{
long V_62 = 1L ;
unsigned long V_72 ;
if ( F_23 ( ! F_25 ( V_2 , V_57 ) ) )
return 0 ;
F_20 ( V_2 , V_73 ) ;
if ( ! ( V_2 -> V_9 & V_74 ) )
return F_26 ( V_2 , V_57 ,
V_60 , V_61 ) ;
F_11 ( & V_2 -> V_35 ) ;
if ( F_36 ( 1 , & V_2 -> V_75 ) > 0 ) {
F_37 ( & V_2 -> V_76 , V_72 ) ;
F_38 ( V_77 ,
V_2 -> V_78 + V_79 ) ;
V_2 -> V_80 |= V_77 ;
F_12 ( V_2 , V_81 , V_2 -> V_80 ) ;
F_39 ( & V_2 -> V_76 , V_72 ) ;
}
F_16 ( & V_2 -> V_35 ) ;
if ( V_60 )
V_62 = F_40
( V_2 -> V_66 ,
! F_25 ( V_2 , V_57 ) , V_61 ) ;
else
V_62 = F_41
( V_2 -> V_66 ,
! F_25 ( V_2 , V_57 ) , V_61 ) ;
if ( F_6 ( V_62 == 0 ) )
V_62 = - V_69 ;
else if ( F_23 ( V_62 > 0 ) )
V_62 = 0 ;
F_11 ( & V_2 -> V_35 ) ;
if ( F_42 ( & V_2 -> V_75 ) ) {
F_37 ( & V_2 -> V_76 , V_72 ) ;
V_2 -> V_80 &= ~ V_77 ;
F_12 ( V_2 , V_81 , V_2 -> V_80 ) ;
F_39 ( & V_2 -> V_76 , V_72 ) ;
}
F_16 ( & V_2 -> V_35 ) ;
return V_62 ;
}
void * F_43 ( struct V_1 * V_2 , T_3 V_57 )
{
struct V_7 * V_82 = & V_2 -> V_8 ;
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_20 ;
T_3 V_21 ;
T_3 V_58 ;
T_3 V_83 = V_82 -> V_9 & V_84 ;
int V_62 ;
F_11 ( & V_82 -> V_30 ) ;
V_20 = F_2 ( V_3 + V_45 ) ;
V_21 = F_2 ( V_3 + V_11 ) ;
V_58 = F_2 ( V_3 + V_46 ) ;
if ( F_6 ( V_57 >= ( V_20 - V_21 ) ) )
goto V_85;
F_44 ( V_82 -> V_28 != 0 ) ;
F_44 ( V_82 -> V_27 != NULL ) ;
V_82 -> V_28 = V_57 ;
while ( 1 ) {
T_3 V_59 = F_2 ( V_3 + V_47 ) ;
bool V_86 = false ;
bool V_87 = false ;
if ( V_58 >= V_59 ) {
if ( F_23 ( ( V_58 + V_57 < V_20 ||
( V_58 + V_57 == V_20 && V_59 > V_21 ) ) ) )
V_87 = true ;
else if ( F_25 ( V_2 , V_57 ) ) {
V_62 = F_35 ( V_2 , V_57 ,
false , 3 * V_88 ) ;
if ( F_6 ( V_62 != 0 ) )
goto V_85;
} else
V_86 = true ;
} else {
if ( F_23 ( ( V_58 + V_57 < V_59 ) ) )
V_87 = true ;
else {
V_62 = F_35 ( V_2 , V_57 ,
false , 3 * V_88 ) ;
if ( F_6 ( V_62 != 0 ) )
goto V_85;
}
}
if ( V_87 ) {
if ( V_83 || V_57 <= sizeof( T_3 ) ) {
V_82 -> V_29 = false ;
if ( V_83 )
F_13 ( V_57 , V_3 +
V_89 ) ;
return V_3 + ( V_58 >> 2 ) ;
} else {
V_86 = true ;
}
}
if ( V_86 ) {
V_82 -> V_29 = true ;
if ( V_57 < V_82 -> V_23 )
return V_82 -> V_25 ;
else {
V_82 -> V_27 = F_5 ( V_57 ) ;
return V_82 -> V_27 ;
}
}
}
V_85:
V_82 -> V_28 = 0 ;
F_16 ( & V_82 -> V_30 ) ;
return NULL ;
}
static void F_45 ( struct V_7 * V_82 ,
T_1 T_2 * V_3 ,
T_3 V_58 ,
T_3 V_20 , T_3 V_21 , T_3 V_57 )
{
T_3 V_90 = V_20 - V_58 ;
T_3 V_91 ;
T_3 * V_92 = ( V_82 -> V_27 != NULL ) ?
V_82 -> V_27 : V_82 -> V_25 ;
if ( V_57 < V_90 )
V_90 = V_57 ;
F_13 ( V_57 , V_3 + V_89 ) ;
F_15 () ;
F_46 ( V_3 + ( V_58 >> 2 ) , V_92 , V_90 ) ;
V_91 = V_57 - V_90 ;
if ( V_91 )
F_46 ( V_3 + ( V_21 >> 2 ) , V_92 + ( V_90 >> 2 ) ,
V_91 ) ;
}
static void F_47 ( struct V_7 * V_82 ,
T_1 T_2 * V_3 ,
T_3 V_58 ,
T_3 V_20 , T_3 V_21 , T_3 V_57 )
{
T_3 * V_92 = ( V_82 -> V_27 != NULL ) ?
V_82 -> V_27 : V_82 -> V_25 ;
while ( V_57 > 0 ) {
F_13 ( * V_92 ++ , V_3 + ( V_58 >> 2 ) ) ;
V_58 += sizeof( T_3 ) ;
if ( F_6 ( V_58 == V_20 ) )
V_58 = V_21 ;
F_15 () ;
F_13 ( V_58 , V_3 + V_46 ) ;
F_15 () ;
V_57 -= sizeof( T_3 ) ;
}
}
void F_48 ( struct V_1 * V_2 , T_3 V_57 )
{
struct V_7 * V_82 = & V_2 -> V_8 ;
T_1 T_2 * V_3 = V_2 -> V_4 ;
T_3 V_58 = F_2 ( V_3 + V_46 ) ;
T_3 V_20 = F_2 ( V_3 + V_45 ) ;
T_3 V_21 = F_2 ( V_3 + V_11 ) ;
bool V_83 = V_82 -> V_9 & V_84 ;
F_44 ( ( V_57 & 3 ) != 0 ) ;
F_44 ( V_57 > V_82 -> V_28 ) ;
V_82 -> V_28 = 0 ;
if ( V_82 -> V_29 ) {
if ( V_83 )
F_45 ( V_82 , V_3 ,
V_58 , V_20 , V_21 , V_57 ) ;
else
F_47 ( V_82 , V_3 ,
V_58 , V_20 , V_21 , V_57 ) ;
if ( V_82 -> V_27 ) {
F_24 ( V_82 -> V_27 ) ;
V_82 -> V_27 = NULL ;
}
}
F_49 ( & V_82 -> V_31 ) ;
if ( V_82 -> V_29 || V_83 ) {
V_58 += V_57 ;
if ( V_58 >= V_20 )
V_58 -= V_20 - V_21 ;
F_15 () ;
F_13 ( V_58 , V_3 + V_46 ) ;
}
if ( V_83 )
F_13 ( 0 , V_3 + V_89 ) ;
F_15 () ;
F_50 ( & V_82 -> V_31 ) ;
F_20 ( V_2 , V_56 ) ;
F_16 ( & V_82 -> V_30 ) ;
}
int F_19 ( struct V_1 * V_2 , T_3 * V_93 )
{
struct V_7 * V_82 = & V_2 -> V_8 ;
struct V_94 * V_95 ;
void * V_96 ;
int V_62 = 0 ;
T_3 V_57 = sizeof( T_1 ) + sizeof( * V_95 ) ;
V_96 = F_43 ( V_2 , V_57 ) ;
if ( F_6 ( V_96 == NULL ) ) {
* V_93 = F_51 ( & V_2 -> V_49 ) ;
V_62 = - V_26 ;
( void ) F_52 ( V_2 , false , true , * V_93 ,
false , 3 * V_88 ) ;
goto V_85;
}
do {
* V_93 = F_36 ( 1 , & V_2 -> V_49 ) ;
} while ( * V_93 == 0 );
if ( ! ( V_82 -> V_9 & V_97 ) ) {
F_48 ( V_2 , 0 ) ;
return 0 ;
}
* ( T_1 * ) V_96 = F_53 ( V_98 ) ;
V_95 = (struct V_94 * )
( ( unsigned long ) V_96 + sizeof( T_1 ) ) ;
F_13 ( * V_93 , & V_95 -> V_99 ) ;
F_48 ( V_2 , V_57 ) ;
( void ) F_54 ( & V_82 -> V_52 , * V_93 ) ;
F_55 ( V_2 , V_82 ) ;
V_85:
return V_62 ;
}
int F_56 ( struct V_1 * V_2 ,
T_3 V_100 )
{
struct V_101 * V_102 = V_2 -> V_103 ;
struct {
T_4 V_104 ;
T_5 V_105 ;
} * V_106 ;
V_106 = F_43 ( V_2 , sizeof( * V_106 ) ) ;
if ( F_6 ( V_106 == NULL ) ) {
F_30 ( L_8 ) ;
return - V_26 ;
}
V_106 -> V_104 . V_107 = V_108 ;
V_106 -> V_104 . V_109 = sizeof( V_106 -> V_105 ) ;
V_106 -> V_105 . V_100 = V_100 ;
V_106 -> V_105 . type = V_110 ;
if ( V_102 -> V_111 . V_112 == V_113 ) {
V_106 -> V_105 . V_114 . V_115 = V_116 ;
V_106 -> V_105 . V_114 . V_117 = V_102 -> V_117 ;
} else {
V_106 -> V_105 . V_114 . V_115 = V_102 -> V_111 . V_118 ;
V_106 -> V_105 . V_114 . V_117 = 0 ;
}
F_48 ( V_2 , sizeof( * V_106 ) ) ;
return 0 ;
}
