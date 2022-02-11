static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_8 ;
int V_9 ;
V_9 = F_2 ( V_7 , V_3 , ( void * ) 1 , V_10 ) ;
if ( V_9 )
return V_9 ;
V_4 ( V_2 ) -> V_11 ++ ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_3 , int V_12 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
V_5 -> V_13 ++ ;
return V_5 -> V_14 -> V_15 ( V_2 , ( V_16 ) V_3 << V_5 -> V_17 ,
V_5 -> V_18 , V_12 ) ;
}
static T_2 F_4 ( struct V_19 * V_20 , T_3 V_21 )
{
T_4 V_22 ;
F_5 ( V_20 , V_21 ) ;
V_22 = V_20 -> V_23 ;
V_20 -> V_23 += V_21 ;
F_6 ( V_20 -> V_23 >= V_4 ( V_20 -> V_24 ) -> V_18 ) ;
return F_7 ( V_20 -> V_24 , V_20 -> V_25 , V_22 ) ;
}
static struct V_26 * F_8 ( struct V_1 * V_2 , T_5 V_27 ,
int V_28 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_29 * V_30 = V_5 -> V_31 -> V_32 ;
T_6 * V_33 = V_5 -> V_14 -> V_34 ;
struct V_26 * V_26 ;
F_6 ( F_9 ( V_30 ) & V_35 ) ;
if ( V_28 )
V_26 = F_10 ( V_30 , V_27 , V_33 , V_2 ) ;
else {
V_26 = F_11 ( V_30 , V_27 , V_10 ) ;
F_12 ( V_26 ) ;
}
return V_26 ;
}
int F_13 ( struct V_19 * V_20 , V_16 V_22 , void * V_36 , T_3 V_37 ,
int V_28 )
{
T_5 V_27 = V_22 >> V_38 ;
struct V_26 * V_26 ;
long V_39 = V_22 & ( V_40 - 1 ) ;
long V_41 ;
F_6 ( ! V_37 && ! V_28 ) ;
do {
V_41 = F_14 ( ( V_42 ) V_37 , V_40 - V_39 ) ;
V_26 = F_8 ( V_20 -> V_24 , V_27 , V_28 ) ;
if ( F_15 ( V_26 ) )
return F_16 ( V_26 ) ;
F_6 ( ! V_26 ) ;
F_17 ( V_26 ) ;
memcpy ( F_18 ( V_26 ) + V_39 , V_36 , V_41 ) ;
F_19 ( V_26 ) ;
F_20 ( V_26 ) ;
V_36 += V_41 ;
V_37 -= V_41 ;
V_39 = 0 ;
V_27 ++ ;
} while ( V_37 );
return 0 ;
}
static void F_21 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_24 ;
struct V_26 * V_26 ;
V_16 V_22 = F_7 ( V_2 , V_20 -> V_25 , V_20 -> V_23 ) ;
T_5 V_27 = V_22 >> V_38 ;
long V_39 = V_22 & ( V_40 - 1 ) ;
T_1 V_37 = V_40 - V_39 ;
if ( V_37 % V_40 ) {
V_26 = F_8 ( V_2 , V_27 , 0 ) ;
F_6 ( ! V_26 ) ;
memset ( F_18 ( V_26 ) + V_39 , 0xff , V_37 ) ;
F_19 ( V_26 ) ;
F_20 ( V_26 ) ;
}
}
static void F_22 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_24 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
V_16 V_22 = F_7 ( V_2 , V_20 -> V_25 , V_20 -> V_23 ) ;
T_1 V_37 = V_5 -> V_18 - V_20 -> V_23 ;
T_5 V_27 = F_23 ( V_22 ) >> V_43 ;
T_5 V_44 = V_37 >> V_43 ;
struct V_26 * V_26 ;
while ( V_44 ) {
V_26 = F_8 ( V_2 , V_27 , 0 ) ;
F_6 ( ! V_26 ) ;
F_17 ( V_26 ) ;
memset ( F_18 ( V_26 ) , 0xff , V_45 ) ;
F_19 ( V_26 ) ;
F_20 ( V_26 ) ;
V_27 ++ ;
V_44 -- ;
}
}
static void F_24 ( struct V_19 * V_20 , int V_46 )
{
F_21 ( V_20 ) ;
if ( V_46 )
F_22 ( V_20 ) ;
}
static void * F_25 ( struct V_1 * V_2 , V_16 V_47 , V_16 V_48 ,
T_7 V_49 )
{
struct V_50 * V_7 = & V_4 ( V_2 ) -> V_51 ;
T_5 V_27 = F_26 ( V_48 , V_49 ) ;
return F_27 ( V_7 , V_47 , V_27 ) ;
}
static int F_28 ( struct V_1 * V_2 , V_16 V_47 , V_16 V_48 ,
T_7 V_49 , void * V_52 )
{
struct V_50 * V_7 = & V_4 ( V_2 ) -> V_51 ;
T_5 V_27 = F_26 ( V_48 , V_49 ) ;
return F_29 ( V_7 , V_47 , V_27 , V_52 , V_10 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_53 * V_54 ,
T_8 * V_55 )
{
struct V_56 * V_57 ;
int V_9 ;
F_31 (item, &block->item_list, list) {
V_9 = F_32 ( V_2 , V_54 -> V_47 , V_54 -> V_48 ,
V_54 -> V_49 , V_57 -> V_58 , V_57 -> V_52 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_59 * V_60 , int V_61 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_53 * V_54 ;
struct V_56 * V_57 ;
V_16 V_47 , V_48 ;
T_7 V_49 ;
int V_62 , V_9 ;
V_5 -> V_63 |= V_64 ;
V_61 /= sizeof( * V_60 ) ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
V_57 = F_34 ( V_5 -> V_65 , V_10 ) ;
if ( ! V_57 )
return - V_66 ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_5 -> V_67 ++ ;
V_57 -> V_52 = V_60 [ V_62 ] . V_52 ;
V_57 -> V_58 = F_35 ( V_60 [ V_62 ] . V_58 ) ;
V_47 = F_36 ( V_60 [ V_62 ] . V_47 ) ;
V_48 = F_36 ( V_60 [ V_62 ] . V_48 ) ;
V_49 = F_37 ( V_60 [ V_62 ] . V_49 ) ;
F_38 ( L_1 ,
V_47 , V_48 , V_49 , V_57 -> V_58 ,
F_36 ( V_57 -> V_52 ) ) ;
V_54 = F_25 ( V_2 , V_47 , V_48 , V_49 ) ;
if ( ! V_54 ) {
V_54 = F_39 ( V_2 , V_47 , V_48 , V_49 ) ;
V_54 -> V_68 = & V_69 ;
V_9 = F_28 ( V_2 , V_47 , V_48 , V_49 , V_54 ) ;
F_6 ( V_9 ) ;
}
if ( F_40 ( V_57 -> V_58 , V_54 -> V_70 ) ) {
F_41 ( V_71 L_2 ) ;
return - V_72 ;
}
F_42 ( & V_54 -> V_73 , & V_5 -> V_74 ) ;
F_43 ( & V_57 -> V_75 , & V_54 -> V_76 ) ;
}
return 0 ;
}
static void F_44 ( void * V_77 , unsigned long V_78 ,
V_16 V_79 , V_16 V_80 , T_3 V_81 )
{
struct V_53 * V_54 = V_77 ;
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_56 * V_57 ;
while ( ! F_45 ( & V_54 -> V_76 ) ) {
V_57 = F_46 ( V_54 -> V_76 . V_82 , F_47 ( * V_57 ) , V_75 ) ;
F_48 ( & V_57 -> V_75 ) ;
F_49 ( V_57 , V_5 -> V_65 ) ;
}
V_54 -> V_68 -> V_83 ( V_2 , V_54 ) ;
}
static int F_50 ( struct V_84 * V_84 , T_7 V_49 )
{
if ( V_49 == 0 ) {
if ( F_51 ( V_84 -> V_85 ) )
return V_86 ;
if ( V_84 -> V_87 == V_88 )
return V_89 ;
}
return V_90 ;
}
static int F_52 ( struct V_1 * V_2 , int F_50 )
{
switch ( F_50 ) {
case V_86 :
return sizeof( struct V_91 ) ;
case V_89 :
return sizeof( struct V_92 ) ;
case V_90 :
return V_2 -> V_93 ;
default:
F_53 () ;
}
}
static int F_54 ( struct V_84 * V_84 , void * V_36 ,
struct V_94 * V_95 , int type , int V_37 , int V_96 )
{
struct V_19 * V_20 ;
struct V_1 * V_2 = V_84 -> V_97 ;
T_2 V_22 ;
struct V_98 V_99 ;
int V_100 ;
if ( V_95 -> V_101 == 0 )
V_100 = V_37 ;
else
V_100 = F_52 ( V_2 , type ) ;
V_20 = F_55 ( V_2 , V_95 -> V_101 ) ;
V_22 = F_4 ( V_20 , V_37 + V_102 ) ;
F_56 ( V_22 <= 0 , V_2 ) ;
V_99 . V_37 = F_57 ( V_37 ) ;
V_99 . type = type ;
V_99 . V_96 = V_96 ;
V_99 . V_47 = F_58 ( V_84 -> V_87 ) ;
V_99 . V_48 = F_58 ( V_95 -> V_48 ) ;
V_99 . V_103 = F_59 ( & V_99 , sizeof( V_99 ) - 4 , 4 ) ;
V_99 . V_104 = F_59 ( V_36 , V_37 , 0 ) ;
F_60 ( V_20 , V_22 , & V_99 , sizeof( V_99 ) ) ;
F_60 ( V_20 , V_22 + V_102 , V_36 , V_37 ) ;
V_95 -> V_105 = V_22 ;
V_95 -> V_106 = V_100 + V_102 ;
return 0 ;
}
static T_2 F_61 ( struct V_84 * V_84 , void * V_36 ,
struct V_94 * V_95 , int type , int V_37 )
{
struct V_1 * V_2 = V_84 -> V_97 ;
void * V_107 = V_4 ( V_2 ) -> V_108 ;
T_9 V_109 ;
int V_110 ;
F_62 ( & V_4 ( V_2 ) -> V_111 ) ;
V_109 = F_63 ( V_36 , V_107 , V_37 , V_37 ) ;
if ( V_109 >= 0 ) {
V_110 = F_54 ( V_84 , V_107 , V_95 ,
type , V_109 , V_112 ) ;
} else {
V_110 = F_54 ( V_84 , V_36 , V_95 , type , V_37 ,
V_113 ) ;
}
F_64 ( & V_4 ( V_2 ) -> V_111 ) ;
return V_110 ;
}
int F_65 ( struct V_84 * V_84 , struct V_26 * V_26 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = V_84 -> V_97 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
int V_114 , type , V_37 ;
int V_110 ;
void * V_36 ;
V_5 -> V_63 |= V_115 ;
F_6 ( V_5 -> V_63 & V_116 ) ;
V_114 = F_66 ( V_84 ) -> V_117 & V_118 ;
if ( V_95 -> V_101 != 0 ) {
V_114 = 0 ;
}
type = F_50 ( V_84 , F_67 ( V_95 -> V_101 ) ) ;
V_37 = F_52 ( V_2 , type ) ;
V_36 = F_68 ( V_26 ) ;
if ( V_114 )
V_110 = F_61 ( V_84 , V_36 , V_95 , type ,
V_37 ) ;
else
V_110 = F_54 ( V_84 , V_36 , V_95 , type , V_37 ,
V_113 ) ;
F_69 ( V_26 ) ;
F_70 ( L_3 ,
V_95 -> V_47 , V_95 -> V_48 , V_95 -> V_101 ,
V_95 -> V_119 , V_95 -> V_105 ,
V_95 -> V_120 , V_95 -> V_106 ) ;
F_6 ( ! ( V_95 -> V_105 & ( V_5 -> V_18 - 1 ) ) ) ;
return V_110 ;
}
int F_71 ( struct V_1 * V_2 , V_16 V_22 , T_3 V_37 , void * V_36 )
{
T_5 V_27 = V_22 >> V_38 ;
struct V_26 * V_26 ;
long V_39 = V_22 & ( V_40 - 1 ) ;
long V_41 ;
while ( V_37 ) {
V_41 = F_14 ( ( V_42 ) V_37 , V_40 - V_39 ) ;
V_26 = F_8 ( V_2 , V_27 , 1 ) ;
if ( F_15 ( V_26 ) )
return F_16 ( V_26 ) ;
memcpy ( V_36 , F_18 ( V_26 ) + V_39 , V_41 ) ;
F_20 ( V_26 ) ;
V_36 += V_41 ;
V_37 -= V_41 ;
V_39 = 0 ;
V_27 ++ ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , V_16 V_121 , V_16 V_122 , T_7 V_49 )
{
return ( V_121 & F_73 ( V_2 , V_49 ) ) !=
( V_122 & F_73 ( V_2 , V_49 ) ) ;
}
static int F_74 ( struct V_1 * V_2 , V_16 V_22 ,
struct V_98 * V_123 )
{
T_10 V_103 ;
int V_9 ;
V_9 = F_71 ( V_2 , V_22 , sizeof( * V_123 ) , V_123 ) ;
if ( V_9 )
return V_9 ;
V_103 = F_59 ( V_123 , sizeof( * V_123 ) - 4 , 4 ) ;
if ( V_103 != V_123 -> V_103 ) {
F_41 ( V_71 L_4
L_5 , V_22 , F_75 ( V_123 -> V_103 ) ,
F_75 ( V_103 ) ) ;
return - V_72 ;
}
return 0 ;
}
static void F_76 ( struct V_84 * V_84 , struct V_26 * V_26 ,
T_11 * V_124 )
{
struct V_1 * V_2 = V_84 -> V_97 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_50 * V_7 = & V_5 -> V_51 ;
struct V_53 * V_54 ;
struct V_56 * V_57 , * V_82 ;
if ( ! ( V_5 -> V_63 & V_64 ) )
return;
V_54 = F_77 ( V_7 , V_84 -> V_87 , V_26 -> V_27 ) ;
if ( ! V_54 )
return;
F_78 ( L_6 ,
V_54 -> V_47 , V_54 -> V_48 , V_54 -> V_49 ) ;
F_79 (item, next, &block->item_list, list) {
V_124 [ V_57 -> V_58 ] = V_57 -> V_52 ;
F_48 ( & V_57 -> V_75 ) ;
F_49 ( V_57 , V_5 -> V_65 ) ;
}
V_54 -> V_26 = V_26 ;
F_19 ( V_26 ) ;
V_26 -> V_125 = ( unsigned long ) V_54 ;
V_54 -> V_68 = & V_126 ;
F_80 ( V_26 , V_54 , V_124 , 0 ) ;
}
static unsigned long F_81 ( const unsigned long * V_127 ,
unsigned long V_128 , unsigned long V_39 )
{
return F_82 ( V_127 , V_128 , V_39 ) ;
}
void F_83 ( struct V_26 * V_26 )
{
struct V_53 * V_54 = V_53 ( V_26 ) ;
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_56 * V_57 ;
unsigned long V_129 ;
T_11 * V_130 ;
int V_9 ;
if ( V_5 -> V_63 & V_116 ) {
V_54 -> V_68 -> V_83 ( V_2 , V_54 ) ;
return;
}
F_78 ( L_7 ,
V_54 -> V_47 , V_54 -> V_48 , V_54 -> V_49 ) ;
V_5 -> V_63 |= V_64 ;
for ( V_129 = 0 ; ; V_129 ++ ) {
V_129 = F_81 ( V_54 -> V_70 , V_131 , V_129 ) ;
if ( V_129 >= V_131 )
break;
V_57 = F_34 ( V_5 -> V_65 , V_10 ) ;
F_6 ( ! V_57 ) ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_130 = F_84 ( V_26 , V_132 ) ;
V_57 -> V_52 = V_130 [ V_129 ] ;
F_85 ( V_130 , V_132 ) ;
V_57 -> V_58 = V_129 ;
F_43 ( & V_57 -> V_75 , & V_54 -> V_76 ) ;
}
V_54 -> V_26 = NULL ;
F_86 ( V_26 ) ;
V_26 -> V_125 = 0 ;
V_54 -> V_68 = & V_69 ;
V_9 = F_28 ( V_54 -> V_2 , V_54 -> V_47 , V_54 -> V_48 , V_54 -> V_49 ,
V_54 ) ;
F_6 ( V_9 ) ;
F_87 ( V_26 ) ;
}
static int F_88 ( struct V_84 * V_84 , void * V_36 ,
V_16 V_22 , V_16 V_48 , T_7 V_49 )
{
struct V_1 * V_2 = V_84 -> V_97 ;
void * V_107 = V_4 ( V_2 ) -> V_108 ;
struct V_98 V_123 ;
T_10 V_103 ;
T_12 V_37 ;
int V_9 , V_133 ;
V_133 = F_52 ( V_2 , F_50 ( V_84 , V_49 ) ) ;
V_9 = F_74 ( V_2 , V_22 , & V_123 ) ;
if ( V_9 )
goto V_134;
V_9 = - V_72 ;
if ( F_36 ( V_123 . V_47 ) != V_84 -> V_87
|| F_72 ( V_2 , F_36 ( V_123 . V_48 ) , V_48 , V_49 ) ) {
F_41 ( V_71 L_8
L_9 ,
V_22 , V_84 -> V_87 , V_48 ,
F_36 ( V_123 . V_47 ) , F_36 ( V_123 . V_48 ) ) ;
goto V_134;
}
V_37 = F_35 ( V_123 . V_37 ) ;
switch ( V_123 . V_96 ) {
case V_113 :
V_9 = F_71 ( V_2 , V_22 + V_102 , V_37 , V_36 ) ;
if ( V_9 )
goto V_134;
V_103 = F_59 ( V_36 , V_37 , 0 ) ;
if ( V_103 != V_123 . V_104 ) {
F_41 ( V_71 L_10
L_11 , V_22 ,
F_75 ( V_123 . V_104 ) ,
F_75 ( V_103 ) ) ;
goto V_134;
}
break;
case V_112 :
F_62 ( & V_4 ( V_2 ) -> V_111 ) ;
V_9 = F_71 ( V_2 , V_22 + V_102 , V_37 ,
V_107 ) ;
if ( V_9 ) {
F_64 ( & V_4 ( V_2 ) -> V_111 ) ;
goto V_134;
}
V_103 = F_59 ( V_107 , V_37 , 0 ) ;
if ( V_103 != V_123 . V_104 ) {
F_41 ( V_71 L_12
L_11 , V_22 ,
F_75 ( V_123 . V_104 ) ,
F_75 ( V_103 ) ) ;
F_64 ( & V_4 ( V_2 ) -> V_111 ) ;
goto V_134;
}
V_9 = F_89 ( V_107 , V_36 , V_37 , V_133 ) ;
F_64 ( & V_4 ( V_2 ) -> V_111 ) ;
if ( V_9 ) {
F_41 ( V_71 L_13 , V_22 ) ;
goto V_134;
}
break;
default:
F_90 ( V_2 ) ;
V_9 = - V_72 ;
goto V_134;
}
return 0 ;
V_134:
F_91 ( V_2 ) ;
F_41 ( V_71 L_14 ) ;
F_90 ( V_2 ) ;
return V_9 ;
}
int F_92 ( struct V_84 * V_84 , struct V_26 * V_26 ,
V_16 V_22 , V_16 V_48 , T_7 V_49 )
{
int V_9 ;
void * V_36 ;
if ( F_93 ( V_26 ) )
return 0 ;
V_22 &= ~ V_135 ;
V_36 = F_68 ( V_26 ) ;
V_9 = F_88 ( V_84 , V_36 , V_22 , V_48 , V_49 ) ;
if ( ! V_9 ) {
F_76 ( V_84 , V_26 , V_36 ) ;
F_17 ( V_26 ) ;
}
F_69 ( V_26 ) ;
F_70 ( L_15 ,
V_84 -> V_87 , V_48 , V_49 , V_22 , V_9 ) ;
return V_9 ;
}
int F_94 ( struct V_84 * V_84 , struct V_94 * V_95 )
{
struct V_1 * V_2 = V_84 -> V_97 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_98 V_99 ;
T_12 V_37 ;
int V_9 ;
V_5 -> V_63 |= V_115 ;
F_6 ( V_5 -> V_63 & V_116 ) ;
F_6 ( V_95 -> V_119 & V_135 ) ;
if ( ! V_95 -> V_119 )
return 0 ;
F_70 ( L_16 ,
V_95 -> V_47 , V_95 -> V_48 , V_95 -> V_101 ,
V_95 -> V_119 , V_95 -> V_105 ,
V_95 -> V_120 , V_95 -> V_106 ) ;
V_9 = F_74 ( V_2 , V_95 -> V_119 , & V_99 ) ;
F_56 ( V_9 , V_2 ) ;
F_56 ( F_36 ( V_99 . V_47 ) != V_84 -> V_87 , V_2 ) ;
F_56 ( F_72 ( V_2 , V_95 -> V_48 , F_36 ( V_99 . V_48 ) ,
F_67 ( V_95 -> V_101 ) ) , V_2 ) ;
if ( V_95 -> V_101 == 0 )
V_37 = F_35 ( V_99 . V_37 ) ;
else
V_37 = F_52 ( V_2 , V_99 . type ) ;
V_95 -> V_120 = V_37 + sizeof( V_99 ) ;
return 0 ;
}
void F_95 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_29 * V_30 = V_5 -> V_31 -> V_32 ;
struct V_26 * V_26 ;
V_16 V_22 , V_136 , V_137 ;
V_136 = F_7 ( V_2 , V_3 , 0 ) ;
V_137 = F_7 ( V_2 , V_3 + 1 , 0 ) ;
for ( V_22 = V_136 ; V_22 < V_137 ; V_22 += V_40 ) {
V_26 = F_96 ( V_30 , V_22 >> V_38 ) ;
if ( ! V_26 )
continue;
F_86 ( V_26 ) ;
F_20 ( V_26 ) ;
}
}
int F_5 ( struct V_19 * V_20 , T_3 V_21 )
{
struct V_1 * V_2 = V_20 -> V_24 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
int V_9 , V_138 = 0 ;
if ( V_20 -> V_139 && V_20 -> V_23 + V_21 <= V_5 -> V_18 )
return 0 ;
if ( V_20 -> V_139 ) {
V_16 V_22 = F_7 ( V_2 , V_20 -> V_25 , V_20 -> V_140 ) ;
T_1 V_37 = V_5 -> V_18 - V_20 -> V_140 ;
F_97 ( L_17 , V_20 -> V_25 ) ;
F_24 ( V_20 , 1 ) ;
V_5 -> V_14 -> V_141 ( V_20 -> V_24 , V_22 , V_37 ) ;
F_95 ( V_2 , V_20 -> V_25 ) ;
V_138 = 1 ;
}
V_20 -> V_23 = 0 ;
V_20 -> V_140 = 0 ;
V_142:
V_20 -> V_143 -> V_144 ( V_20 ) ;
V_20 -> V_143 -> V_145 ( V_20 ) ;
F_97 ( L_18 , V_20 -> V_25 , V_20 -> V_146 ) ;
V_9 = V_20 -> V_143 -> V_147 ( V_20 ) ;
if ( V_9 ) {
F_41 ( V_148 L_19 ,
V_20 -> V_25 ) ;
F_1 ( V_2 , V_20 -> V_25 ) ;
goto V_142;
}
V_20 -> V_139 = 1 ;
return V_138 ;
}
void F_98 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_24 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
V_16 V_22 = F_7 ( V_2 , V_20 -> V_25 , V_20 -> V_140 ) ;
T_1 V_37 = ( V_20 -> V_23 - V_20 -> V_140 ) ;
if ( V_5 -> V_149 )
V_37 &= ~ ( V_5 -> V_149 - 1 ) ;
if ( V_37 == 0 )
return;
F_24 ( V_20 , 0 ) ;
V_5 -> V_14 -> V_141 ( V_2 , V_22 , V_37 ) ;
V_20 -> V_140 += V_37 ;
}
void F_99 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
int V_62 ;
F_100 (i)
F_98 ( V_5 -> V_150 [ V_62 ] ) ;
}
static void F_101 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_24 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
if ( V_5 -> V_151 . V_61 == 0 ) {
F_41 ( V_71 L_20 ) ;
F_90 ( V_2 ) ;
}
V_20 -> V_25 = F_102 ( V_2 , & V_5 -> V_151 , NULL ) ;
}
static void F_103 ( struct V_19 * V_20 )
{
struct V_152 V_153 ;
T_1 V_154 ;
F_104 ( V_20 -> V_24 , V_20 -> V_25 , & V_153 ) ;
F_6 ( V_153 . V_154 == F_105 ( V_155 ) ||
V_153 . V_156 == F_105 ( V_157 ) ) ;
V_154 = F_75 ( V_153 . V_154 ) ;
V_20 -> V_158 = ( V_154 >> 4 ) + 1 ;
}
static int F_106 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_24 ;
struct V_159 V_160 ;
V_16 V_22 ;
int V_9 ;
V_9 = F_3 ( V_2 , V_20 -> V_25 , 0 ) ;
if ( V_9 )
return V_9 ;
V_160 . V_161 = 0 ;
V_160 . type = V_162 ;
V_160 . V_49 = ( V_163 V_164 ) V_20 -> V_146 ;
V_160 . V_3 = F_105 ( V_20 -> V_25 ) ;
V_160 . V_165 = F_105 ( V_20 -> V_158 ) ;
V_160 . V_166 = F_58 ( V_4 ( V_2 ) -> V_13 ) ;
V_160 . V_103 = F_59 ( & V_160 , sizeof( V_160 ) , 4 ) ;
F_107 ( V_2 , V_20 -> V_25 , V_20 -> V_158 ,
V_20 -> V_146 ) ;
V_22 = F_7 ( V_2 , V_20 -> V_25 , 0 ) ;
V_20 -> V_23 = sizeof( V_160 ) ;
F_60 ( V_20 , V_22 , & V_160 , sizeof( V_160 ) ) ;
return 0 ;
}
static void F_108 ( struct V_19 * V_20 )
{
if ( V_20 )
F_95 ( V_20 -> V_24 , V_20 -> V_25 ) ;
F_109 ( V_20 ) ;
}
static struct V_19 * F_110 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
V_20 = F_111 ( sizeof( * V_20 ) , V_167 ) ;
if ( ! V_20 )
return NULL ;
V_20 -> V_24 = V_2 ;
return V_20 ;
}
static void F_112 ( struct V_26 * V_26 , unsigned long V_168 )
{
F_53 () ;
}
static int F_113 ( struct V_26 * V_26 , T_13 V_169 )
{
return 0 ;
}
int F_114 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_29 * V_30 ;
struct V_84 * V_84 ;
V_84 = F_115 ( V_2 , V_170 ) ;
if ( F_15 ( V_84 ) )
return F_16 ( V_84 ) ;
V_5 -> V_31 = V_84 ;
V_30 = V_84 -> V_32 ;
V_30 -> V_143 = & V_171 ;
F_116 ( V_30 , V_10 ) ;
return 0 ;
}
int F_117 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
int V_62 = - 1 ;
V_5 -> V_65 = F_118 ( 600 ,
sizeof( struct V_56 ) ) ;
if ( ! V_5 -> V_65 )
return - V_66 ;
V_5 -> V_172 = F_110 ( V_2 ) ;
if ( ! V_5 -> V_172 )
goto V_9;
F_100 (i) {
V_5 -> V_150 [ V_62 ] = F_110 ( V_2 ) ;
if ( ! V_5 -> V_150 [ V_62 ] )
goto V_9;
V_5 -> V_150 [ V_62 ] -> V_146 = F_119 ( V_62 ) ;
V_5 -> V_150 [ V_62 ] -> V_143 = & V_173 ;
}
F_120 ( & V_5 -> V_51 ,
V_5 -> V_174 ) ;
return 0 ;
V_9:
for ( V_62 -- ; V_62 >= 0 ; V_62 -- )
F_108 ( V_5 -> V_150 [ V_62 ] ) ;
F_108 ( V_5 -> V_172 ) ;
F_121 ( V_5 -> V_65 ) ;
return - V_66 ;
}
void F_122 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
int V_62 ;
F_123 ( & V_5 -> V_51 , 0 , F_44 ) ;
F_100 (i)
F_108 ( V_5 -> V_150 [ V_62 ] ) ;
F_108 ( V_5 -> V_172 ) ;
}
