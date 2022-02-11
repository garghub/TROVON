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
if ( ! F_19 ( V_26 ) ) {
F_20 ( V_26 ) ;
F_21 ( V_26 ) ;
}
F_22 ( V_26 ) ;
V_36 += V_41 ;
V_37 -= V_41 ;
V_39 = 0 ;
V_27 ++ ;
} while ( V_37 );
return 0 ;
}
static void F_23 ( struct V_19 * V_20 )
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
if ( ! F_19 ( V_26 ) ) {
F_20 ( V_26 ) ;
F_21 ( V_26 ) ;
}
F_22 ( V_26 ) ;
}
}
static void F_24 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_24 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
V_16 V_22 = F_7 ( V_2 , V_20 -> V_25 , V_20 -> V_23 ) ;
T_1 V_37 = V_5 -> V_18 - V_20 -> V_23 ;
T_5 V_27 = F_25 ( V_22 ) >> V_43 ;
T_5 V_44 = V_37 >> V_43 ;
struct V_26 * V_26 ;
while ( V_44 ) {
V_26 = F_8 ( V_2 , V_27 , 0 ) ;
F_6 ( ! V_26 ) ;
F_17 ( V_26 ) ;
memset ( F_18 ( V_26 ) , 0xff , V_45 ) ;
if ( ! F_19 ( V_26 ) ) {
F_20 ( V_26 ) ;
F_21 ( V_26 ) ;
}
F_22 ( V_26 ) ;
V_27 ++ ;
V_44 -- ;
}
}
static void F_26 ( struct V_19 * V_20 , int V_46 )
{
F_23 ( V_20 ) ;
if ( V_46 )
F_24 ( V_20 ) ;
}
static void * F_27 ( struct V_1 * V_2 , V_16 V_47 , V_16 V_48 ,
T_7 V_49 )
{
struct V_50 * V_7 = & V_4 ( V_2 ) -> V_51 ;
T_5 V_27 = F_28 ( V_48 , V_49 ) ;
return F_29 ( V_7 , V_47 , V_27 ) ;
}
static int F_30 ( struct V_1 * V_2 , V_16 V_47 , V_16 V_48 ,
T_7 V_49 , void * V_52 )
{
struct V_50 * V_7 = & V_4 ( V_2 ) -> V_51 ;
T_5 V_27 = F_28 ( V_48 , V_49 ) ;
return F_31 ( V_7 , V_47 , V_27 , V_52 , V_10 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_53 * V_54 ,
T_8 * V_55 )
{
struct V_56 * V_57 ;
int V_9 ;
F_33 (item, &block->item_list, list) {
V_9 = F_34 ( V_2 , V_54 -> V_47 , V_54 -> V_48 ,
V_54 -> V_49 , V_57 -> V_58 , V_57 -> V_52 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
int F_35 ( struct V_1 * V_2 ,
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
V_57 = F_36 ( V_5 -> V_65 , V_10 ) ;
if ( ! V_57 )
return - V_66 ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_5 -> V_67 ++ ;
V_57 -> V_52 = V_60 [ V_62 ] . V_52 ;
V_57 -> V_58 = F_37 ( V_60 [ V_62 ] . V_58 ) ;
V_47 = F_38 ( V_60 [ V_62 ] . V_47 ) ;
V_48 = F_38 ( V_60 [ V_62 ] . V_48 ) ;
V_49 = F_39 ( V_60 [ V_62 ] . V_49 ) ;
F_40 ( L_1 ,
V_47 , V_48 , V_49 , V_57 -> V_58 ,
F_38 ( V_57 -> V_52 ) ) ;
V_54 = F_27 ( V_2 , V_47 , V_48 , V_49 ) ;
if ( ! V_54 ) {
V_54 = F_41 ( V_2 , V_47 , V_48 , V_49 ) ;
V_54 -> V_68 = & V_69 ;
V_9 = F_30 ( V_2 , V_47 , V_48 , V_49 , V_54 ) ;
F_6 ( V_9 ) ;
}
if ( F_42 ( V_57 -> V_58 , V_54 -> V_70 ) ) {
F_43 ( V_71 L_2 ) ;
return - V_72 ;
}
F_44 ( & V_54 -> V_73 , & V_5 -> V_74 ) ;
F_45 ( & V_57 -> V_75 , & V_54 -> V_76 ) ;
}
return 0 ;
}
static void F_46 ( void * V_77 , unsigned long V_78 ,
V_16 V_79 , V_16 V_80 , T_3 V_81 )
{
struct V_53 * V_54 = V_77 ;
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_56 * V_57 ;
while ( ! F_47 ( & V_54 -> V_76 ) ) {
V_57 = F_48 ( V_54 -> V_76 . V_82 , F_49 ( * V_57 ) , V_75 ) ;
F_50 ( & V_57 -> V_75 ) ;
F_51 ( V_57 , V_5 -> V_65 ) ;
}
V_54 -> V_68 -> V_83 ( V_2 , V_54 ) ;
}
static int F_52 ( struct V_84 * V_84 , T_7 V_49 )
{
if ( V_49 == 0 ) {
if ( F_53 ( V_84 -> V_85 ) )
return V_86 ;
if ( V_84 -> V_87 == V_88 )
return V_89 ;
}
return V_90 ;
}
static int F_54 ( struct V_1 * V_2 , int F_52 )
{
switch ( F_52 ) {
case V_86 :
return sizeof( struct V_91 ) ;
case V_89 :
return sizeof( struct V_92 ) ;
case V_90 :
return V_2 -> V_93 ;
default:
F_55 () ;
}
}
static int F_56 ( struct V_84 * V_84 , void * V_36 ,
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
V_100 = F_54 ( V_2 , type ) ;
V_20 = F_57 ( V_2 , V_95 -> V_101 ) ;
V_22 = F_4 ( V_20 , V_37 + V_102 ) ;
F_58 ( V_22 <= 0 , V_2 ) ;
V_99 . V_37 = F_59 ( V_37 ) ;
V_99 . type = type ;
V_99 . V_96 = V_96 ;
V_99 . V_47 = F_60 ( V_84 -> V_87 ) ;
V_99 . V_48 = F_60 ( V_95 -> V_48 ) ;
V_99 . V_103 = F_61 ( & V_99 , sizeof( V_99 ) - 4 , 4 ) ;
V_99 . V_104 = F_61 ( V_36 , V_37 , 0 ) ;
F_62 ( V_20 , V_22 , & V_99 , sizeof( V_99 ) ) ;
F_62 ( V_20 , V_22 + V_102 , V_36 , V_37 ) ;
V_95 -> V_105 = V_22 ;
V_95 -> V_106 = V_100 + V_102 ;
return 0 ;
}
static T_2 F_63 ( struct V_84 * V_84 , void * V_36 ,
struct V_94 * V_95 , int type , int V_37 )
{
struct V_1 * V_2 = V_84 -> V_97 ;
void * V_107 = V_4 ( V_2 ) -> V_108 ;
T_9 V_109 ;
int V_110 ;
F_64 ( & V_4 ( V_2 ) -> V_111 ) ;
V_109 = F_65 ( V_36 , V_107 , V_37 , V_37 ) ;
if ( V_109 >= 0 ) {
V_110 = F_56 ( V_84 , V_107 , V_95 ,
type , V_109 , V_112 ) ;
} else {
V_110 = F_56 ( V_84 , V_36 , V_95 , type , V_37 ,
V_113 ) ;
}
F_66 ( & V_4 ( V_2 ) -> V_111 ) ;
return V_110 ;
}
int F_67 ( struct V_84 * V_84 , struct V_26 * V_26 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = V_84 -> V_97 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
int V_114 , type , V_37 ;
int V_110 ;
void * V_36 ;
V_5 -> V_63 |= V_115 ;
F_6 ( V_5 -> V_63 & V_116 ) ;
V_114 = F_68 ( V_84 ) -> V_117 & V_118 ;
if ( V_95 -> V_101 != 0 ) {
V_114 = 0 ;
}
type = F_52 ( V_84 , F_69 ( V_95 -> V_101 ) ) ;
V_37 = F_54 ( V_2 , type ) ;
V_36 = F_70 ( V_26 ) ;
if ( V_114 )
V_110 = F_63 ( V_84 , V_36 , V_95 , type ,
V_37 ) ;
else
V_110 = F_56 ( V_84 , V_36 , V_95 , type , V_37 ,
V_113 ) ;
F_71 ( V_26 ) ;
F_72 ( L_3 ,
V_95 -> V_47 , V_95 -> V_48 , V_95 -> V_101 ,
V_95 -> V_119 , V_95 -> V_105 ,
V_95 -> V_120 , V_95 -> V_106 ) ;
F_6 ( ! ( V_95 -> V_105 & ( V_5 -> V_18 - 1 ) ) ) ;
return V_110 ;
}
int F_73 ( struct V_1 * V_2 , V_16 V_22 , T_3 V_37 , void * V_36 )
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
F_22 ( V_26 ) ;
V_36 += V_41 ;
V_37 -= V_41 ;
V_39 = 0 ;
V_27 ++ ;
}
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , V_16 V_121 , V_16 V_122 , T_7 V_49 )
{
return ( V_121 & F_75 ( V_2 , V_49 ) ) !=
( V_122 & F_75 ( V_2 , V_49 ) ) ;
}
static int F_76 ( struct V_1 * V_2 , V_16 V_22 ,
struct V_98 * V_123 )
{
T_10 V_103 ;
int V_9 ;
V_9 = F_73 ( V_2 , V_22 , sizeof( * V_123 ) , V_123 ) ;
if ( V_9 )
return V_9 ;
V_103 = F_61 ( V_123 , sizeof( * V_123 ) - 4 , 4 ) ;
if ( V_103 != V_123 -> V_103 ) {
F_43 ( V_71 L_4
L_5 , V_22 , F_77 ( V_123 -> V_103 ) ,
F_77 ( V_103 ) ) ;
return - V_72 ;
}
return 0 ;
}
static void F_78 ( struct V_84 * V_84 , struct V_26 * V_26 ,
T_11 * V_124 )
{
struct V_1 * V_2 = V_84 -> V_97 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_50 * V_7 = & V_5 -> V_51 ;
struct V_53 * V_54 ;
struct V_56 * V_57 , * V_82 ;
if ( ! ( V_5 -> V_63 & V_64 ) )
return;
V_54 = F_79 ( V_7 , V_84 -> V_87 , V_26 -> V_27 ) ;
if ( ! V_54 )
return;
F_80 ( L_6 ,
V_54 -> V_47 , V_54 -> V_48 , V_54 -> V_49 ) ;
F_81 (item, next, &block->item_list, list) {
V_124 [ V_57 -> V_58 ] = V_57 -> V_52 ;
F_50 ( & V_57 -> V_75 ) ;
F_51 ( V_57 , V_5 -> V_65 ) ;
}
V_54 -> V_26 = V_26 ;
if ( ! F_19 ( V_26 ) ) {
F_20 ( V_26 ) ;
F_21 ( V_26 ) ;
F_82 ( V_26 , ( unsigned long ) V_54 ) ;
}
V_54 -> V_68 = & V_125 ;
F_83 ( V_26 , V_54 , V_124 , 0 ) ;
}
static unsigned long F_84 ( const unsigned long * V_126 ,
unsigned long V_127 , unsigned long V_39 )
{
return F_85 ( V_126 , V_127 , V_39 ) ;
}
void F_86 ( struct V_26 * V_26 )
{
struct V_53 * V_54 = V_53 ( V_26 ) ;
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_56 * V_57 ;
unsigned long V_128 ;
T_11 * V_129 ;
int V_9 ;
if ( V_5 -> V_63 & V_116 ) {
V_54 -> V_68 -> V_83 ( V_2 , V_54 ) ;
return;
}
F_80 ( L_7 ,
V_54 -> V_47 , V_54 -> V_48 , V_54 -> V_49 ) ;
V_5 -> V_63 |= V_64 ;
for ( V_128 = 0 ; ; V_128 ++ ) {
V_128 = F_84 ( V_54 -> V_70 , V_130 , V_128 ) ;
if ( V_128 >= V_130 )
break;
V_57 = F_36 ( V_5 -> V_65 , V_10 ) ;
F_6 ( ! V_57 ) ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_129 = F_87 ( V_26 , V_131 ) ;
V_57 -> V_52 = V_129 [ V_128 ] ;
F_88 ( V_129 , V_131 ) ;
V_57 -> V_58 = V_128 ;
F_45 ( & V_57 -> V_75 , & V_54 -> V_76 ) ;
}
V_54 -> V_26 = NULL ;
if ( F_19 ( V_26 ) ) {
F_89 ( V_26 ) ;
F_22 ( V_26 ) ;
F_82 ( V_26 , 0 ) ;
}
V_54 -> V_68 = & V_69 ;
V_9 = F_30 ( V_54 -> V_2 , V_54 -> V_47 , V_54 -> V_48 , V_54 -> V_49 ,
V_54 ) ;
F_6 ( V_9 ) ;
F_90 ( V_26 ) ;
}
static int F_91 ( struct V_84 * V_84 , void * V_36 ,
V_16 V_22 , V_16 V_48 , T_7 V_49 )
{
struct V_1 * V_2 = V_84 -> V_97 ;
void * V_107 = V_4 ( V_2 ) -> V_108 ;
struct V_98 V_123 ;
T_10 V_103 ;
T_12 V_37 ;
int V_9 , V_132 ;
V_132 = F_54 ( V_2 , F_52 ( V_84 , V_49 ) ) ;
V_9 = F_76 ( V_2 , V_22 , & V_123 ) ;
if ( V_9 )
goto V_133;
V_9 = - V_72 ;
if ( F_38 ( V_123 . V_47 ) != V_84 -> V_87
|| F_74 ( V_2 , F_38 ( V_123 . V_48 ) , V_48 , V_49 ) ) {
F_43 ( V_71 L_8
L_9 ,
V_22 , V_84 -> V_87 , V_48 ,
F_38 ( V_123 . V_47 ) , F_38 ( V_123 . V_48 ) ) ;
goto V_133;
}
V_37 = F_37 ( V_123 . V_37 ) ;
switch ( V_123 . V_96 ) {
case V_113 :
V_9 = F_73 ( V_2 , V_22 + V_102 , V_37 , V_36 ) ;
if ( V_9 )
goto V_133;
V_103 = F_61 ( V_36 , V_37 , 0 ) ;
if ( V_103 != V_123 . V_104 ) {
F_43 ( V_71 L_10
L_11 , V_22 ,
F_77 ( V_123 . V_104 ) ,
F_77 ( V_103 ) ) ;
goto V_133;
}
break;
case V_112 :
F_64 ( & V_4 ( V_2 ) -> V_111 ) ;
V_9 = F_73 ( V_2 , V_22 + V_102 , V_37 ,
V_107 ) ;
if ( V_9 ) {
F_66 ( & V_4 ( V_2 ) -> V_111 ) ;
goto V_133;
}
V_103 = F_61 ( V_107 , V_37 , 0 ) ;
if ( V_103 != V_123 . V_104 ) {
F_43 ( V_71 L_12
L_11 , V_22 ,
F_77 ( V_123 . V_104 ) ,
F_77 ( V_103 ) ) ;
F_66 ( & V_4 ( V_2 ) -> V_111 ) ;
goto V_133;
}
V_9 = F_92 ( V_107 , V_36 , V_37 , V_132 ) ;
F_66 ( & V_4 ( V_2 ) -> V_111 ) ;
if ( V_9 ) {
F_43 ( V_71 L_13 , V_22 ) ;
goto V_133;
}
break;
default:
F_93 ( V_2 ) ;
V_9 = - V_72 ;
goto V_133;
}
return 0 ;
V_133:
F_94 ( V_2 ) ;
F_43 ( V_71 L_14 ) ;
F_93 ( V_2 ) ;
return V_9 ;
}
int F_95 ( struct V_84 * V_84 , struct V_26 * V_26 ,
V_16 V_22 , V_16 V_48 , T_7 V_49 )
{
int V_9 ;
void * V_36 ;
if ( F_96 ( V_26 ) )
return 0 ;
V_22 &= ~ V_134 ;
V_36 = F_70 ( V_26 ) ;
V_9 = F_91 ( V_84 , V_36 , V_22 , V_48 , V_49 ) ;
if ( ! V_9 ) {
F_78 ( V_84 , V_26 , V_36 ) ;
F_17 ( V_26 ) ;
}
F_71 ( V_26 ) ;
F_72 ( L_15 ,
V_84 -> V_87 , V_48 , V_49 , V_22 , V_9 ) ;
return V_9 ;
}
int F_97 ( struct V_84 * V_84 , struct V_94 * V_95 )
{
struct V_1 * V_2 = V_84 -> V_97 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_98 V_99 ;
T_12 V_37 ;
int V_9 ;
V_5 -> V_63 |= V_115 ;
F_6 ( V_5 -> V_63 & V_116 ) ;
F_6 ( V_95 -> V_119 & V_134 ) ;
if ( ! V_95 -> V_119 )
return 0 ;
F_72 ( L_16 ,
V_95 -> V_47 , V_95 -> V_48 , V_95 -> V_101 ,
V_95 -> V_119 , V_95 -> V_105 ,
V_95 -> V_120 , V_95 -> V_106 ) ;
V_9 = F_76 ( V_2 , V_95 -> V_119 , & V_99 ) ;
F_58 ( V_9 , V_2 ) ;
F_58 ( F_38 ( V_99 . V_47 ) != V_84 -> V_87 , V_2 ) ;
F_58 ( F_74 ( V_2 , V_95 -> V_48 , F_38 ( V_99 . V_48 ) ,
F_69 ( V_95 -> V_101 ) ) , V_2 ) ;
if ( V_95 -> V_101 == 0 )
V_37 = F_37 ( V_99 . V_37 ) ;
else
V_37 = F_54 ( V_2 , V_99 . type ) ;
V_95 -> V_120 = V_37 + sizeof( V_99 ) ;
return 0 ;
}
void F_98 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_29 * V_30 = V_5 -> V_31 -> V_32 ;
struct V_26 * V_26 ;
V_16 V_22 , V_135 , V_136 ;
V_135 = F_7 ( V_2 , V_3 , 0 ) ;
V_136 = F_7 ( V_2 , V_3 + 1 , 0 ) ;
for ( V_22 = V_135 ; V_22 < V_136 ; V_22 += V_40 ) {
V_26 = F_99 ( V_30 , V_22 >> V_38 ) ;
if ( ! V_26 )
continue;
if ( F_19 ( V_26 ) ) {
F_89 ( V_26 ) ;
F_22 ( V_26 ) ;
}
F_22 ( V_26 ) ;
}
}
int F_5 ( struct V_19 * V_20 , T_3 V_21 )
{
struct V_1 * V_2 = V_20 -> V_24 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
int V_9 , V_137 = 0 ;
if ( V_20 -> V_138 && V_20 -> V_23 + V_21 <= V_5 -> V_18 )
return 0 ;
if ( V_20 -> V_138 ) {
V_16 V_22 = F_7 ( V_2 , V_20 -> V_25 , V_20 -> V_139 ) ;
T_1 V_37 = V_5 -> V_18 - V_20 -> V_139 ;
F_100 ( L_17 , V_20 -> V_25 ) ;
F_26 ( V_20 , 1 ) ;
V_5 -> V_14 -> V_140 ( V_20 -> V_24 , V_22 , V_37 ) ;
F_98 ( V_2 , V_20 -> V_25 ) ;
V_137 = 1 ;
}
V_20 -> V_23 = 0 ;
V_20 -> V_139 = 0 ;
V_141:
V_20 -> V_142 -> V_143 ( V_20 ) ;
V_20 -> V_142 -> V_144 ( V_20 ) ;
F_100 ( L_18 , V_20 -> V_25 , V_20 -> V_145 ) ;
V_9 = V_20 -> V_142 -> V_146 ( V_20 ) ;
if ( V_9 ) {
F_43 ( V_147 L_19 ,
V_20 -> V_25 ) ;
F_1 ( V_2 , V_20 -> V_25 ) ;
goto V_141;
}
V_20 -> V_138 = 1 ;
return V_137 ;
}
void F_101 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_24 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
V_16 V_22 = F_7 ( V_2 , V_20 -> V_25 , V_20 -> V_139 ) ;
T_1 V_37 = ( V_20 -> V_23 - V_20 -> V_139 ) ;
if ( V_5 -> V_148 )
V_37 &= ~ ( V_5 -> V_148 - 1 ) ;
if ( V_37 == 0 )
return;
F_26 ( V_20 , 0 ) ;
V_5 -> V_14 -> V_140 ( V_2 , V_22 , V_37 ) ;
V_20 -> V_139 += V_37 ;
}
void F_102 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
int V_62 ;
F_103 (i)
F_101 ( V_5 -> V_149 [ V_62 ] ) ;
}
static void F_104 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_24 ;
struct V_4 * V_5 = V_4 ( V_2 ) ;
if ( V_5 -> V_150 . V_61 == 0 ) {
F_43 ( V_71 L_20 ) ;
F_93 ( V_2 ) ;
}
V_20 -> V_25 = F_105 ( V_2 , & V_5 -> V_150 , NULL ) ;
}
static void F_106 ( struct V_19 * V_20 )
{
struct V_151 V_152 ;
T_1 V_153 ;
F_107 ( V_20 -> V_24 , V_20 -> V_25 , & V_152 ) ;
F_6 ( V_152 . V_153 == F_108 ( V_154 ) ||
V_152 . V_155 == F_108 ( V_156 ) ) ;
V_153 = F_77 ( V_152 . V_153 ) ;
V_20 -> V_157 = ( V_153 >> 4 ) + 1 ;
}
static int F_109 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_24 ;
struct V_158 V_159 ;
V_16 V_22 ;
int V_9 ;
V_9 = F_3 ( V_2 , V_20 -> V_25 , 0 ) ;
if ( V_9 )
return V_9 ;
V_159 . V_160 = 0 ;
V_159 . type = V_161 ;
V_159 . V_49 = ( V_162 V_163 ) V_20 -> V_145 ;
V_159 . V_3 = F_108 ( V_20 -> V_25 ) ;
V_159 . V_164 = F_108 ( V_20 -> V_157 ) ;
V_159 . V_165 = F_60 ( V_4 ( V_2 ) -> V_13 ) ;
V_159 . V_103 = F_61 ( & V_159 , sizeof( V_159 ) , 4 ) ;
F_110 ( V_2 , V_20 -> V_25 , V_20 -> V_157 ,
V_20 -> V_145 ) ;
V_22 = F_7 ( V_2 , V_20 -> V_25 , 0 ) ;
V_20 -> V_23 = sizeof( V_159 ) ;
F_62 ( V_20 , V_22 , & V_159 , sizeof( V_159 ) ) ;
return 0 ;
}
static void F_111 ( struct V_19 * V_20 )
{
if ( V_20 )
F_98 ( V_20 -> V_24 , V_20 -> V_25 ) ;
F_112 ( V_20 ) ;
}
void F_113 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
int V_62 ;
F_103 (i)
F_111 ( V_5 -> V_149 [ V_62 ] ) ;
F_111 ( V_5 -> V_166 ) ;
}
static struct V_19 * F_114 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
V_20 = F_115 ( sizeof( * V_20 ) , V_167 ) ;
if ( ! V_20 )
return NULL ;
V_20 -> V_24 = V_2 ;
return V_20 ;
}
static void F_116 ( struct V_26 * V_26 , unsigned long V_168 )
{
F_55 () ;
}
static int F_117 ( struct V_26 * V_26 , T_13 V_169 )
{
return 0 ;
}
int F_118 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_29 * V_30 ;
struct V_84 * V_84 ;
V_84 = F_119 ( V_2 , V_170 ) ;
if ( F_15 ( V_84 ) )
return F_16 ( V_84 ) ;
V_5 -> V_31 = V_84 ;
V_30 = V_84 -> V_32 ;
V_30 -> V_142 = & V_171 ;
F_120 ( V_30 , V_10 ) ;
return 0 ;
}
int F_121 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
int V_62 = - 1 ;
V_5 -> V_65 = F_122 ( 600 ,
sizeof( struct V_56 ) ) ;
if ( ! V_5 -> V_65 )
return - V_66 ;
V_5 -> V_166 = F_114 ( V_2 ) ;
if ( ! V_5 -> V_166 )
goto V_9;
F_103 (i) {
V_5 -> V_149 [ V_62 ] = F_114 ( V_2 ) ;
if ( ! V_5 -> V_149 [ V_62 ] )
goto V_9;
V_5 -> V_149 [ V_62 ] -> V_145 = F_123 ( V_62 ) ;
V_5 -> V_149 [ V_62 ] -> V_142 = & V_172 ;
}
F_124 ( & V_5 -> V_51 ,
V_5 -> V_173 ) ;
return 0 ;
V_9:
for ( V_62 -- ; V_62 >= 0 ; V_62 -- )
F_111 ( V_5 -> V_149 [ V_62 ] ) ;
F_111 ( V_5 -> V_166 ) ;
F_125 ( V_5 -> V_65 ) ;
return - V_66 ;
}
void F_126 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
F_127 ( & V_5 -> V_51 , 0 , F_46 ) ;
}
