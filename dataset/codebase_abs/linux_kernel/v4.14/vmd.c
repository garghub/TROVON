static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 , struct V_1 , V_4 ) ;
}
static inline unsigned int F_3 ( struct V_1 * V_5 ,
struct V_6 * V_7 )
{
return V_7 - V_5 -> V_7 ;
}
static void F_4 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_6 * V_15 = V_13 -> V_15 ;
struct V_1 * V_5 = F_5 ( V_9 ) ;
V_11 -> V_16 = V_17 ;
V_11 -> V_18 = V_19 |
F_6 ( F_3 ( V_5 , V_15 ) ) ;
V_11 -> V_9 = 0 ;
}
static void F_7 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = V_9 -> V_14 ;
unsigned long V_20 ;
F_8 ( & V_21 , V_20 ) ;
F_9 ( V_13 -> V_22 ) ;
F_10 ( & V_13 -> V_23 , & V_13 -> V_15 -> V_24 ) ;
V_13 -> V_22 = true ;
F_11 ( & V_21 , V_20 ) ;
V_9 -> V_25 -> V_26 ( V_9 ) ;
}
static void F_12 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = V_9 -> V_14 ;
unsigned long V_20 ;
V_9 -> V_25 -> V_27 ( V_9 ) ;
F_8 ( & V_21 , V_20 ) ;
if ( V_13 -> V_22 ) {
F_13 ( & V_13 -> V_23 ) ;
V_13 -> V_22 = false ;
}
F_11 ( & V_21 , V_20 ) ;
}
static int F_14 ( struct V_8 * V_9 ,
const struct V_28 * V_29 , bool V_30 )
{
return - V_31 ;
}
static T_1 F_15 ( struct V_32 * V_33 ,
T_2 * V_34 )
{
return 0 ;
}
static struct V_6 * F_16 ( struct V_1 * V_5 , struct V_35 * V_36 )
{
int V_37 , V_38 = 1 ;
unsigned long V_20 ;
if ( F_17 ( F_18 ( V_36 ) ) || V_5 -> V_39 == 1 )
return & V_5 -> V_7 [ 0 ] ;
F_8 ( & V_21 , V_20 ) ;
for ( V_37 = 1 ; V_37 < V_5 -> V_39 ; V_37 ++ )
if ( V_5 -> V_7 [ V_37 ] . V_40 < V_5 -> V_7 [ V_38 ] . V_40 )
V_38 = V_37 ;
V_5 -> V_7 [ V_38 ] . V_40 ++ ;
F_11 ( & V_21 , V_20 ) ;
return & V_5 -> V_7 [ V_38 ] ;
}
static int F_19 ( struct V_41 * V_42 , struct V_32 * V_33 ,
unsigned int V_43 , T_1 V_44 ,
T_2 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_36 ;
struct V_1 * V_5 = F_1 ( F_18 ( V_36 ) -> V_3 ) ;
struct V_12 * V_13 = F_20 ( sizeof( * V_13 ) , V_45 ) ;
unsigned int V_46 , V_47 ;
if ( ! V_13 )
return - V_48 ;
F_21 ( & V_13 -> V_23 ) ;
V_13 -> V_15 = F_16 ( V_5 , V_36 ) ;
V_13 -> V_43 = V_43 ;
V_46 = F_3 ( V_5 , V_13 -> V_15 ) ;
V_47 = F_22 ( V_5 -> V_49 , V_46 ) ;
F_23 ( V_42 , V_43 , V_47 , V_33 -> V_25 , V_13 ,
V_50 , V_5 , NULL ) ;
return 0 ;
}
static void F_24 ( struct V_41 * V_42 ,
struct V_32 * V_33 , unsigned int V_43 )
{
struct V_12 * V_13 = F_25 ( V_43 ) ;
unsigned long V_20 ;
F_26 ( & V_13 -> V_15 -> V_51 ) ;
F_8 ( & V_21 , V_20 ) ;
V_13 -> V_15 -> V_40 -- ;
F_11 ( & V_21 , V_20 ) ;
F_27 ( V_13 ) ;
}
static int F_28 ( struct V_41 * V_42 , struct V_52 * V_49 ,
int V_53 , T_2 * V_34 )
{
struct V_54 * V_55 = F_29 ( V_49 ) ;
struct V_1 * V_5 = F_1 ( V_55 -> V_3 ) ;
if ( V_53 > V_5 -> V_39 )
return V_5 -> V_39 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
return 0 ;
}
static void F_30 ( T_2 * V_34 , struct V_35 * V_36 )
{
V_34 -> V_36 = V_36 ;
}
static struct V_52 * F_31 ( struct V_52 * V_49 )
{
struct V_54 * V_55 = F_29 ( V_49 ) ;
struct V_1 * V_5 = F_1 ( V_55 -> V_3 ) ;
return & V_5 -> V_49 -> V_49 ;
}
static const struct V_56 * F_32 ( struct V_52 * V_49 )
{
return F_33 ( F_31 ( V_49 ) ) ;
}
static void * F_34 ( struct V_52 * V_49 , T_3 V_57 , T_4 * V_58 ,
T_5 V_59 , unsigned long V_60 )
{
return F_32 ( V_49 ) -> F_35 ( F_31 ( V_49 ) , V_57 , V_58 , V_59 ,
V_60 ) ;
}
static void F_36 ( struct V_52 * V_49 , T_3 V_57 , void * V_61 ,
T_4 V_58 , unsigned long V_60 )
{
return F_32 ( V_49 ) -> free ( F_31 ( V_49 ) , V_57 , V_61 , V_58 ,
V_60 ) ;
}
static int F_37 ( struct V_52 * V_49 , struct V_62 * V_63 ,
void * V_64 , T_4 V_58 , T_3 V_57 ,
unsigned long V_60 )
{
return F_32 ( V_49 ) -> F_38 ( F_31 ( V_49 ) , V_63 , V_64 , V_58 ,
V_57 , V_60 ) ;
}
static int F_39 ( struct V_52 * V_49 , struct V_65 * V_66 ,
void * V_64 , T_4 V_58 , T_3 V_57 ,
unsigned long V_60 )
{
return F_32 ( V_49 ) -> F_40 ( F_31 ( V_49 ) , V_66 , V_64 ,
V_58 , V_57 , V_60 ) ;
}
static T_4 F_41 ( struct V_52 * V_49 , struct V_67 * V_67 ,
unsigned long V_68 , T_3 V_57 ,
enum V_69 V_70 ,
unsigned long V_60 )
{
return F_32 ( V_49 ) -> F_42 ( F_31 ( V_49 ) , V_67 , V_68 , V_57 ,
V_70 , V_60 ) ;
}
static void F_43 ( struct V_52 * V_49 , T_4 V_58 , T_3 V_57 ,
enum V_69 V_70 , unsigned long V_60 )
{
F_32 ( V_49 ) -> F_44 ( F_31 ( V_49 ) , V_58 , V_57 , V_70 , V_60 ) ;
}
static int F_45 ( struct V_52 * V_49 , struct V_71 * V_72 , int V_73 ,
enum V_69 V_70 , unsigned long V_60 )
{
return F_32 ( V_49 ) -> F_46 ( F_31 ( V_49 ) , V_72 , V_73 , V_70 , V_60 ) ;
}
static void F_47 ( struct V_52 * V_49 , struct V_71 * V_72 , int V_73 ,
enum V_69 V_70 , unsigned long V_60 )
{
F_32 ( V_49 ) -> F_48 ( F_31 ( V_49 ) , V_72 , V_73 , V_70 , V_60 ) ;
}
static void F_49 ( struct V_52 * V_49 , T_4 V_58 ,
T_3 V_57 , enum V_69 V_70 )
{
F_32 ( V_49 ) -> F_50 ( F_31 ( V_49 ) , V_58 , V_57 , V_70 ) ;
}
static void F_51 ( struct V_52 * V_49 , T_4 V_58 ,
T_3 V_57 , enum V_69 V_70 )
{
F_32 ( V_49 ) -> F_52 ( F_31 ( V_49 ) , V_58 , V_57 ,
V_70 ) ;
}
static void F_53 ( struct V_52 * V_49 , struct V_71 * V_72 ,
int V_73 , enum V_69 V_70 )
{
F_32 ( V_49 ) -> F_54 ( F_31 ( V_49 ) , V_72 , V_73 , V_70 ) ;
}
static void F_55 ( struct V_52 * V_49 , struct V_71 * V_72 ,
int V_73 , enum V_69 V_70 )
{
F_32 ( V_49 ) -> F_56 ( F_31 ( V_49 ) , V_72 , V_73 , V_70 ) ;
}
static int F_57 ( struct V_52 * V_49 , T_4 V_58 )
{
return F_32 ( V_49 ) -> F_58 ( F_31 ( V_49 ) , V_58 ) ;
}
static int F_59 ( struct V_52 * V_49 , T_6 V_74 )
{
return F_32 ( V_49 ) -> F_60 ( F_31 ( V_49 ) , V_74 ) ;
}
static T_6 F_61 ( struct V_52 * V_49 )
{
return F_32 ( V_49 ) -> F_62 ( F_31 ( V_49 ) ) ;
}
static void F_63 ( struct V_1 * V_5 )
{
struct V_75 * V_42 = & V_5 -> V_75 ;
if ( F_33 ( & V_5 -> V_49 -> V_49 ) )
F_64 ( V_42 ) ;
}
static void F_65 ( struct V_1 * V_5 )
{
const struct V_56 * V_76 = F_33 ( & V_5 -> V_49 -> V_49 ) ;
struct V_56 * V_29 = & V_5 -> V_77 ;
struct V_75 * V_42 = & V_5 -> V_75 ;
V_42 -> V_78 = V_5 -> V_4 . V_42 ;
V_42 -> V_77 = V_29 ;
if ( ! V_76 )
return;
F_66 ( V_76 , V_29 , F_35 ) ;
F_66 ( V_76 , V_29 , free ) ;
F_66 ( V_76 , V_29 , F_38 ) ;
F_66 ( V_76 , V_29 , F_40 ) ;
F_66 ( V_76 , V_29 , F_42 ) ;
F_66 ( V_76 , V_29 , F_44 ) ;
F_66 ( V_76 , V_29 , F_46 ) ;
F_66 ( V_76 , V_29 , F_48 ) ;
F_66 ( V_76 , V_29 , F_50 ) ;
F_66 ( V_76 , V_29 , F_52 ) ;
F_66 ( V_76 , V_29 , F_54 ) ;
F_66 ( V_76 , V_29 , F_56 ) ;
F_66 ( V_76 , V_29 , F_58 ) ;
F_66 ( V_76 , V_29 , F_60 ) ;
#ifdef F_67
F_66 ( V_76 , V_29 , F_62 ) ;
#endif
F_68 ( V_42 ) ;
}
static void F_63 ( struct V_1 * V_5 ) {}
static void F_65 ( struct V_1 * V_5 ) {}
static char T_7 * F_69 ( struct V_1 * V_5 , struct V_2 * V_3 ,
unsigned int V_79 , int V_80 , int V_81 )
{
char T_7 * V_58 = V_5 -> V_82 +
( V_3 -> V_83 << 20 ) + ( V_79 << 12 ) + V_80 ;
if ( ( V_58 - V_5 -> V_82 ) + V_81 >=
F_70 ( & V_5 -> V_49 -> V_84 [ V_85 ] ) )
return NULL ;
return V_58 ;
}
static int F_71 ( struct V_2 * V_3 , unsigned int V_79 , int V_80 ,
int V_81 , T_8 * V_86 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
char T_7 * V_58 = F_69 ( V_5 , V_3 , V_79 , V_80 , V_81 ) ;
unsigned long V_20 ;
int V_87 = 0 ;
if ( ! V_58 )
return - V_88 ;
F_72 ( & V_5 -> V_89 , V_20 ) ;
switch ( V_81 ) {
case 1 :
* V_86 = F_73 ( V_58 ) ;
break;
case 2 :
* V_86 = F_74 ( V_58 ) ;
break;
case 4 :
* V_86 = F_75 ( V_58 ) ;
break;
default:
V_87 = - V_31 ;
break;
}
F_76 ( & V_5 -> V_89 , V_20 ) ;
return V_87 ;
}
static int F_77 ( struct V_2 * V_3 , unsigned int V_79 , int V_80 ,
int V_81 , T_8 V_86 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
char T_7 * V_58 = F_69 ( V_5 , V_3 , V_79 , V_80 , V_81 ) ;
unsigned long V_20 ;
int V_87 = 0 ;
if ( ! V_58 )
return - V_88 ;
F_72 ( & V_5 -> V_89 , V_20 ) ;
switch ( V_81 ) {
case 1 :
F_78 ( V_86 , V_58 ) ;
F_73 ( V_58 ) ;
break;
case 2 :
F_79 ( V_86 , V_58 ) ;
F_74 ( V_58 ) ;
break;
case 4 :
F_80 ( V_86 , V_58 ) ;
F_75 ( V_58 ) ;
break;
default:
V_87 = - V_31 ;
break;
}
F_76 ( & V_5 -> V_89 , V_20 ) ;
return V_87 ;
}
static void F_81 ( struct V_1 * V_5 )
{
V_5 -> V_49 -> V_84 [ V_90 ] . V_91 = & V_5 -> V_92 [ 1 ] ;
V_5 -> V_49 -> V_84 [ V_93 ] . V_91 = & V_5 -> V_92 [ 2 ] ;
}
static void F_82 ( struct V_1 * V_5 )
{
V_5 -> V_49 -> V_84 [ V_90 ] . V_91 = NULL ;
V_5 -> V_49 -> V_84 [ V_93 ] . V_91 = NULL ;
}
static int F_83 ( void )
{
int V_42 = 0xffff ;
struct V_2 * V_3 = NULL ;
while ( ( V_3 = F_84 ( V_3 ) ) != NULL )
V_42 = F_85 ( int , V_42 , F_86 ( V_3 ) ) ;
return V_42 + 1 ;
}
static int F_87 ( struct V_1 * V_5 )
{
struct V_94 * V_95 = & V_5 -> V_4 ;
struct V_96 * V_97 ;
struct V_84 * V_98 ;
T_8 V_99 ;
unsigned long V_20 ;
F_88 ( V_92 ) ;
V_98 = & V_5 -> V_49 -> V_84 [ V_85 ] ;
V_5 -> V_92 [ 0 ] = (struct V_84 ) {
. V_100 = L_1 ,
. V_101 = 0 ,
. V_102 = ( F_70 ( V_98 ) >> 20 ) - 1 ,
. V_20 = V_103 | V_104 ,
} ;
V_98 = & V_5 -> V_49 -> V_84 [ V_90 ] ;
V_99 = F_89 ( V_98 -> V_102 ) ;
V_20 = V_98 -> V_20 & ~ V_105 ;
if ( ! V_99 )
V_20 &= ~ V_106 ;
V_5 -> V_92 [ 1 ] = (struct V_84 ) {
. V_100 = L_2 ,
. V_101 = V_98 -> V_101 ,
. V_102 = V_98 -> V_102 ,
. V_20 = V_20 ,
. V_107 = V_98 ,
} ;
V_98 = & V_5 -> V_49 -> V_84 [ V_93 ] ;
V_99 = F_89 ( V_98 -> V_102 ) ;
V_20 = V_98 -> V_20 & ~ V_105 ;
if ( ! V_99 )
V_20 &= ~ V_106 ;
V_5 -> V_92 [ 2 ] = (struct V_84 ) {
. V_100 = L_3 ,
. V_101 = V_98 -> V_101 + 0x2000 ,
. V_102 = V_98 -> V_102 ,
. V_20 = V_20 ,
. V_107 = V_98 ,
} ;
V_95 -> V_108 = true ;
V_95 -> V_42 = F_83 () ;
if ( V_95 -> V_42 < 0 )
return V_95 -> V_42 ;
V_95 -> V_23 = F_90 ( V_5 -> V_49 -> V_3 ) ;
V_97 = F_91 ( L_4 , V_5 -> V_4 . V_42 ) ;
if ( ! V_97 )
return - V_109 ;
V_5 -> V_41 = F_92 ( V_97 , & V_110 ,
V_111 ) ;
F_93 ( V_97 ) ;
if ( ! V_5 -> V_41 )
return - V_109 ;
F_94 ( & V_92 , & V_5 -> V_92 [ 0 ] ) ;
F_94 ( & V_92 , & V_5 -> V_92 [ 1 ] ) ;
F_94 ( & V_92 , & V_5 -> V_92 [ 2 ] ) ;
V_5 -> V_3 = F_95 ( & V_5 -> V_49 -> V_49 , 0 , & V_112 , V_95 ,
& V_92 ) ;
if ( ! V_5 -> V_3 ) {
F_96 ( & V_92 ) ;
F_97 ( V_5 -> V_41 ) ;
return - V_109 ;
}
F_81 ( V_5 ) ;
F_65 ( V_5 ) ;
F_98 ( & V_5 -> V_3 -> V_49 , V_5 -> V_41 ) ;
F_99 ( V_5 -> V_3 ) ;
F_100 ( F_101 ( & V_5 -> V_49 -> V_49 . V_113 , & V_5 -> V_3 -> V_49 . V_113 ,
L_5 ) , L_6 ) ;
return 0 ;
}
static T_9 V_12 ( int V_15 , void * V_9 )
{
struct V_6 * V_7 = V_9 ;
struct V_12 * V_13 ;
int V_114 ;
V_114 = F_102 ( & V_7 -> V_51 ) ;
F_103 (vmdirq, &irqs->irq_list, node)
F_104 ( V_13 -> V_43 ) ;
F_105 ( & V_7 -> V_51 , V_114 ) ;
return V_115 ;
}
static int F_106 ( struct V_54 * V_49 , const struct V_116 * V_117 )
{
struct V_1 * V_5 ;
int V_37 , V_118 ;
if ( F_70 ( & V_49 -> V_84 [ V_85 ] ) < ( 1 << 20 ) )
return - V_48 ;
V_5 = F_107 ( & V_49 -> V_49 , sizeof( * V_5 ) , V_45 ) ;
if ( ! V_5 )
return - V_48 ;
V_5 -> V_49 = V_49 ;
V_118 = F_108 ( V_49 ) ;
if ( V_118 < 0 )
return V_118 ;
V_5 -> V_82 = F_109 ( V_49 , V_85 , 0 ) ;
if ( ! V_5 -> V_82 )
return - V_48 ;
F_110 ( V_49 ) ;
if ( F_111 ( & V_49 -> V_49 , F_112 ( 64 ) ) &&
F_111 ( & V_49 -> V_49 , F_112 ( 32 ) ) )
return - V_109 ;
V_5 -> V_39 = F_113 ( V_49 ) ;
if ( V_5 -> V_39 < 0 )
return - V_109 ;
V_5 -> V_39 = F_114 ( V_49 , 1 , V_5 -> V_39 ,
V_119 ) ;
if ( V_5 -> V_39 < 0 )
return V_5 -> V_39 ;
V_5 -> V_7 = F_115 ( & V_49 -> V_49 , V_5 -> V_39 , sizeof( * V_5 -> V_7 ) ,
V_45 ) ;
if ( ! V_5 -> V_7 )
return - V_48 ;
for ( V_37 = 0 ; V_37 < V_5 -> V_39 ; V_37 ++ ) {
V_118 = F_116 ( & V_5 -> V_7 [ V_37 ] . V_51 ) ;
if ( V_118 )
return V_118 ;
F_21 ( & V_5 -> V_7 [ V_37 ] . V_24 ) ;
V_118 = F_117 ( & V_49 -> V_49 , F_22 ( V_49 , V_37 ) ,
V_12 , V_120 ,
L_7 , & V_5 -> V_7 [ V_37 ] ) ;
if ( V_118 )
return V_118 ;
}
F_118 ( & V_5 -> V_89 ) ;
F_119 ( V_49 , V_5 ) ;
V_118 = F_87 ( V_5 ) ;
if ( V_118 )
return V_118 ;
F_120 ( & V_5 -> V_49 -> V_49 , L_8 ,
V_5 -> V_4 . V_42 ) ;
return 0 ;
}
static void F_121 ( struct V_1 * V_5 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_5 -> V_39 ; V_37 ++ )
F_122 ( & V_5 -> V_7 [ V_37 ] . V_51 ) ;
}
static void F_123 ( struct V_54 * V_49 )
{
struct V_1 * V_5 = F_124 ( V_49 ) ;
F_82 ( V_5 ) ;
F_125 ( & V_5 -> V_49 -> V_49 . V_113 , L_5 ) ;
F_126 ( V_5 -> V_3 ) ;
F_127 ( V_5 -> V_3 ) ;
F_121 ( V_5 ) ;
F_63 ( V_5 ) ;
F_97 ( V_5 -> V_41 ) ;
}
static int F_128 ( struct V_52 * V_49 )
{
struct V_54 * V_55 = F_29 ( V_49 ) ;
struct V_1 * V_5 = F_124 ( V_55 ) ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_5 -> V_39 ; V_37 ++ )
F_129 ( V_49 , F_22 ( V_55 , V_37 ) , & V_5 -> V_7 [ V_37 ] ) ;
F_130 ( V_55 ) ;
return 0 ;
}
static int F_131 ( struct V_52 * V_49 )
{
struct V_54 * V_55 = F_29 ( V_49 ) ;
struct V_1 * V_5 = F_124 ( V_55 ) ;
int V_118 , V_37 ;
for ( V_37 = 0 ; V_37 < V_5 -> V_39 ; V_37 ++ ) {
V_118 = F_117 ( V_49 , F_22 ( V_55 , V_37 ) ,
V_12 , V_120 ,
L_7 , & V_5 -> V_7 [ V_37 ] ) ;
if ( V_118 )
return V_118 ;
}
F_132 ( V_55 ) ;
return 0 ;
}
