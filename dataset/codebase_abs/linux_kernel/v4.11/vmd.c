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
if ( ! V_36 -> V_39 . V_40 || V_5 -> V_41 == 1 )
return & V_5 -> V_7 [ 0 ] ;
F_8 ( & V_21 , V_20 ) ;
for ( V_37 = 1 ; V_37 < V_5 -> V_41 ; V_37 ++ )
if ( V_5 -> V_7 [ V_37 ] . V_42 < V_5 -> V_7 [ V_38 ] . V_42 )
V_38 = V_37 ;
V_5 -> V_7 [ V_38 ] . V_42 ++ ;
F_11 ( & V_21 , V_20 ) ;
return & V_5 -> V_7 [ V_38 ] ;
}
static int F_17 ( struct V_43 * V_44 , struct V_32 * V_33 ,
unsigned int V_45 , T_1 V_46 ,
T_2 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_36 ;
struct V_1 * V_5 = F_1 ( F_18 ( V_36 ) -> V_3 ) ;
struct V_12 * V_13 = F_19 ( sizeof( * V_13 ) , V_47 ) ;
unsigned int V_48 , V_49 ;
if ( ! V_13 )
return - V_50 ;
F_20 ( & V_13 -> V_23 ) ;
V_13 -> V_15 = F_16 ( V_5 , V_36 ) ;
V_13 -> V_45 = V_45 ;
V_48 = F_3 ( V_5 , V_13 -> V_15 ) ;
V_49 = F_21 ( V_5 -> V_51 , V_48 ) ;
F_22 ( V_44 , V_45 , V_49 , V_33 -> V_25 , V_13 ,
V_52 , V_5 , NULL ) ;
return 0 ;
}
static void F_23 ( struct V_43 * V_44 ,
struct V_32 * V_33 , unsigned int V_45 )
{
struct V_12 * V_13 = F_24 ( V_45 ) ;
unsigned long V_20 ;
F_25 ( & V_13 -> V_15 -> V_53 ) ;
F_8 ( & V_21 , V_20 ) ;
V_13 -> V_15 -> V_42 -- ;
F_11 ( & V_21 , V_20 ) ;
F_26 ( V_13 ) ;
}
static int F_27 ( struct V_43 * V_44 , struct V_54 * V_51 ,
int V_55 , T_2 * V_34 )
{
struct V_56 * V_57 = F_28 ( V_51 ) ;
struct V_1 * V_5 = F_1 ( V_57 -> V_3 ) ;
if ( V_55 > V_5 -> V_41 )
return V_5 -> V_41 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
return 0 ;
}
static void F_29 ( T_2 * V_34 , struct V_35 * V_36 )
{
V_34 -> V_36 = V_36 ;
}
static struct V_54 * F_30 ( struct V_54 * V_51 )
{
struct V_56 * V_57 = F_28 ( V_51 ) ;
struct V_1 * V_5 = F_1 ( V_57 -> V_3 ) ;
return & V_5 -> V_51 -> V_51 ;
}
static const struct V_58 * F_31 ( struct V_54 * V_51 )
{
return F_32 ( F_30 ( V_51 ) ) ;
}
static void * F_33 ( struct V_54 * V_51 , T_3 V_59 , T_4 * V_60 ,
T_5 V_61 , unsigned long V_62 )
{
return F_31 ( V_51 ) -> F_34 ( F_30 ( V_51 ) , V_59 , V_60 , V_61 ,
V_62 ) ;
}
static void F_35 ( struct V_54 * V_51 , T_3 V_59 , void * V_63 ,
T_4 V_60 , unsigned long V_62 )
{
return F_31 ( V_51 ) -> free ( F_30 ( V_51 ) , V_59 , V_63 , V_60 ,
V_62 ) ;
}
static int F_36 ( struct V_54 * V_51 , struct V_64 * V_65 ,
void * V_66 , T_4 V_60 , T_3 V_59 ,
unsigned long V_62 )
{
return F_31 ( V_51 ) -> F_37 ( F_30 ( V_51 ) , V_65 , V_66 , V_60 ,
V_59 , V_62 ) ;
}
static int F_38 ( struct V_54 * V_51 , struct V_67 * V_68 ,
void * V_66 , T_4 V_60 , T_3 V_59 ,
unsigned long V_62 )
{
return F_31 ( V_51 ) -> F_39 ( F_30 ( V_51 ) , V_68 , V_66 ,
V_60 , V_59 , V_62 ) ;
}
static T_4 F_40 ( struct V_54 * V_51 , struct V_69 * V_69 ,
unsigned long V_70 , T_3 V_59 ,
enum V_71 V_72 ,
unsigned long V_62 )
{
return F_31 ( V_51 ) -> F_41 ( F_30 ( V_51 ) , V_69 , V_70 , V_59 ,
V_72 , V_62 ) ;
}
static void F_42 ( struct V_54 * V_51 , T_4 V_60 , T_3 V_59 ,
enum V_71 V_72 , unsigned long V_62 )
{
F_31 ( V_51 ) -> F_43 ( F_30 ( V_51 ) , V_60 , V_59 , V_72 , V_62 ) ;
}
static int F_44 ( struct V_54 * V_51 , struct V_73 * V_74 , int V_75 ,
enum V_71 V_72 , unsigned long V_62 )
{
return F_31 ( V_51 ) -> F_45 ( F_30 ( V_51 ) , V_74 , V_75 , V_72 , V_62 ) ;
}
static void F_46 ( struct V_54 * V_51 , struct V_73 * V_74 , int V_75 ,
enum V_71 V_72 , unsigned long V_62 )
{
F_31 ( V_51 ) -> F_47 ( F_30 ( V_51 ) , V_74 , V_75 , V_72 , V_62 ) ;
}
static void F_48 ( struct V_54 * V_51 , T_4 V_60 ,
T_3 V_59 , enum V_71 V_72 )
{
F_31 ( V_51 ) -> F_49 ( F_30 ( V_51 ) , V_60 , V_59 , V_72 ) ;
}
static void F_50 ( struct V_54 * V_51 , T_4 V_60 ,
T_3 V_59 , enum V_71 V_72 )
{
F_31 ( V_51 ) -> F_51 ( F_30 ( V_51 ) , V_60 , V_59 ,
V_72 ) ;
}
static void F_52 ( struct V_54 * V_51 , struct V_73 * V_74 ,
int V_75 , enum V_71 V_72 )
{
F_31 ( V_51 ) -> F_53 ( F_30 ( V_51 ) , V_74 , V_75 , V_72 ) ;
}
static void F_54 ( struct V_54 * V_51 , struct V_73 * V_74 ,
int V_75 , enum V_71 V_72 )
{
F_31 ( V_51 ) -> F_55 ( F_30 ( V_51 ) , V_74 , V_75 , V_72 ) ;
}
static int F_56 ( struct V_54 * V_51 , T_4 V_60 )
{
return F_31 ( V_51 ) -> F_57 ( F_30 ( V_51 ) , V_60 ) ;
}
static int F_58 ( struct V_54 * V_51 , T_6 V_76 )
{
return F_31 ( V_51 ) -> F_59 ( F_30 ( V_51 ) , V_76 ) ;
}
static T_6 F_60 ( struct V_54 * V_51 )
{
return F_31 ( V_51 ) -> F_61 ( F_30 ( V_51 ) ) ;
}
static void F_62 ( struct V_1 * V_5 )
{
struct V_77 * V_44 = & V_5 -> V_77 ;
if ( F_32 ( & V_5 -> V_51 -> V_51 ) )
F_63 ( V_44 ) ;
}
static void F_64 ( struct V_1 * V_5 )
{
const struct V_58 * V_78 = F_32 ( & V_5 -> V_51 -> V_51 ) ;
struct V_58 * V_29 = & V_5 -> V_79 ;
struct V_77 * V_44 = & V_5 -> V_77 ;
V_44 -> V_80 = V_5 -> V_4 . V_44 ;
V_44 -> V_79 = V_29 ;
if ( ! V_78 )
return;
F_65 ( V_78 , V_29 , F_34 ) ;
F_65 ( V_78 , V_29 , free ) ;
F_65 ( V_78 , V_29 , F_37 ) ;
F_65 ( V_78 , V_29 , F_39 ) ;
F_65 ( V_78 , V_29 , F_41 ) ;
F_65 ( V_78 , V_29 , F_43 ) ;
F_65 ( V_78 , V_29 , F_45 ) ;
F_65 ( V_78 , V_29 , F_47 ) ;
F_65 ( V_78 , V_29 , F_49 ) ;
F_65 ( V_78 , V_29 , F_51 ) ;
F_65 ( V_78 , V_29 , F_53 ) ;
F_65 ( V_78 , V_29 , F_55 ) ;
F_65 ( V_78 , V_29 , F_57 ) ;
F_65 ( V_78 , V_29 , F_59 ) ;
#ifdef F_66
F_65 ( V_78 , V_29 , F_61 ) ;
#endif
F_67 ( V_44 ) ;
}
static void F_62 ( struct V_1 * V_5 ) {}
static void F_64 ( struct V_1 * V_5 ) {}
static char T_7 * F_68 ( struct V_1 * V_5 , struct V_2 * V_3 ,
unsigned int V_81 , int V_82 , int V_83 )
{
char T_7 * V_60 = V_5 -> V_84 +
( V_3 -> V_85 << 20 ) + ( V_81 << 12 ) + V_82 ;
if ( ( V_60 - V_5 -> V_84 ) + V_83 >=
F_69 ( & V_5 -> V_51 -> V_86 [ V_87 ] ) )
return NULL ;
return V_60 ;
}
static int F_70 ( struct V_2 * V_3 , unsigned int V_81 , int V_82 ,
int V_83 , T_8 * V_88 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
char T_7 * V_60 = F_68 ( V_5 , V_3 , V_81 , V_82 , V_83 ) ;
unsigned long V_20 ;
int V_89 = 0 ;
if ( ! V_60 )
return - V_90 ;
F_71 ( & V_5 -> V_91 , V_20 ) ;
switch ( V_83 ) {
case 1 :
* V_88 = F_72 ( V_60 ) ;
break;
case 2 :
* V_88 = F_73 ( V_60 ) ;
break;
case 4 :
* V_88 = F_74 ( V_60 ) ;
break;
default:
V_89 = - V_31 ;
break;
}
F_75 ( & V_5 -> V_91 , V_20 ) ;
return V_89 ;
}
static int F_76 ( struct V_2 * V_3 , unsigned int V_81 , int V_82 ,
int V_83 , T_8 V_88 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
char T_7 * V_60 = F_68 ( V_5 , V_3 , V_81 , V_82 , V_83 ) ;
unsigned long V_20 ;
int V_89 = 0 ;
if ( ! V_60 )
return - V_90 ;
F_71 ( & V_5 -> V_91 , V_20 ) ;
switch ( V_83 ) {
case 1 :
F_77 ( V_88 , V_60 ) ;
F_72 ( V_60 ) ;
break;
case 2 :
F_78 ( V_88 , V_60 ) ;
F_73 ( V_60 ) ;
break;
case 4 :
F_79 ( V_88 , V_60 ) ;
F_74 ( V_60 ) ;
break;
default:
V_89 = - V_31 ;
break;
}
F_75 ( & V_5 -> V_91 , V_20 ) ;
return V_89 ;
}
static void F_80 ( struct V_1 * V_5 )
{
V_5 -> V_51 -> V_86 [ V_92 ] . V_93 = & V_5 -> V_94 [ 1 ] ;
V_5 -> V_51 -> V_86 [ V_95 ] . V_93 = & V_5 -> V_94 [ 2 ] ;
}
static void F_81 ( struct V_1 * V_5 )
{
V_5 -> V_51 -> V_86 [ V_92 ] . V_93 = NULL ;
V_5 -> V_51 -> V_86 [ V_95 ] . V_93 = NULL ;
}
static int F_82 ( void )
{
int V_44 = 0xffff ;
struct V_2 * V_3 = NULL ;
while ( ( V_3 = F_83 ( V_3 ) ) != NULL )
V_44 = F_84 ( int , V_44 , F_85 ( V_3 ) ) ;
return V_44 + 1 ;
}
static int F_86 ( struct V_1 * V_5 )
{
struct V_96 * V_97 = & V_5 -> V_4 ;
struct V_86 * V_98 ;
T_8 V_99 ;
unsigned long V_20 ;
F_87 ( V_94 ) ;
V_98 = & V_5 -> V_51 -> V_86 [ V_87 ] ;
V_5 -> V_94 [ 0 ] = (struct V_86 ) {
. V_100 = L_1 ,
. V_101 = 0 ,
. V_102 = ( F_69 ( V_98 ) >> 20 ) - 1 ,
. V_20 = V_103 | V_104 ,
} ;
V_98 = & V_5 -> V_51 -> V_86 [ V_92 ] ;
V_99 = F_88 ( V_98 -> V_102 ) ;
V_20 = V_98 -> V_20 & ~ V_105 ;
if ( ! V_99 )
V_20 &= ~ V_106 ;
V_5 -> V_94 [ 1 ] = (struct V_86 ) {
. V_100 = L_2 ,
. V_101 = V_98 -> V_101 ,
. V_102 = V_98 -> V_102 ,
. V_20 = V_20 ,
. V_107 = V_98 ,
} ;
V_98 = & V_5 -> V_51 -> V_86 [ V_95 ] ;
V_99 = F_88 ( V_98 -> V_102 ) ;
V_20 = V_98 -> V_20 & ~ V_105 ;
if ( ! V_99 )
V_20 &= ~ V_106 ;
V_5 -> V_94 [ 2 ] = (struct V_86 ) {
. V_100 = L_3 ,
. V_101 = V_98 -> V_101 + 0x2000 ,
. V_102 = V_98 -> V_102 ,
. V_20 = V_20 ,
. V_107 = V_98 ,
} ;
V_97 -> V_108 = true ;
V_97 -> V_44 = F_82 () ;
if ( V_97 -> V_44 < 0 )
return V_97 -> V_44 ;
V_97 -> V_23 = F_89 ( V_5 -> V_51 -> V_3 ) ;
V_5 -> V_43 = F_90 ( NULL , & V_109 ,
V_110 ) ;
if ( ! V_5 -> V_43 )
return - V_111 ;
F_91 ( & V_94 , & V_5 -> V_94 [ 0 ] ) ;
F_91 ( & V_94 , & V_5 -> V_94 [ 1 ] ) ;
F_91 ( & V_94 , & V_5 -> V_94 [ 2 ] ) ;
V_5 -> V_3 = F_92 ( & V_5 -> V_51 -> V_51 , 0 , & V_112 , V_97 ,
& V_94 ) ;
if ( ! V_5 -> V_3 ) {
F_93 ( & V_94 ) ;
F_94 ( V_5 -> V_43 ) ;
return - V_111 ;
}
F_80 ( V_5 ) ;
F_64 ( V_5 ) ;
F_95 ( & V_5 -> V_3 -> V_51 , V_5 -> V_43 ) ;
F_96 ( V_5 -> V_3 ) ;
F_97 ( F_98 ( & V_5 -> V_51 -> V_51 . V_113 , & V_5 -> V_3 -> V_51 . V_113 ,
L_4 ) , L_5 ) ;
return 0 ;
}
static T_9 V_12 ( int V_15 , void * V_9 )
{
struct V_6 * V_7 = V_9 ;
struct V_12 * V_13 ;
int V_114 ;
V_114 = F_99 ( & V_7 -> V_53 ) ;
F_100 (vmdirq, &irqs->irq_list, node)
F_101 ( V_13 -> V_45 ) ;
F_102 ( & V_7 -> V_53 , V_114 ) ;
return V_115 ;
}
static int F_103 ( struct V_56 * V_51 , const struct V_116 * V_117 )
{
struct V_1 * V_5 ;
int V_37 , V_118 ;
if ( F_69 ( & V_51 -> V_86 [ V_87 ] ) < ( 1 << 20 ) )
return - V_50 ;
V_5 = F_104 ( & V_51 -> V_51 , sizeof( * V_5 ) , V_47 ) ;
if ( ! V_5 )
return - V_50 ;
V_5 -> V_51 = V_51 ;
V_118 = F_105 ( V_51 ) ;
if ( V_118 < 0 )
return V_118 ;
V_5 -> V_84 = F_106 ( V_51 , V_87 , 0 ) ;
if ( ! V_5 -> V_84 )
return - V_50 ;
F_107 ( V_51 ) ;
if ( F_108 ( & V_51 -> V_51 , F_109 ( 64 ) ) &&
F_108 ( & V_51 -> V_51 , F_109 ( 32 ) ) )
return - V_111 ;
V_5 -> V_41 = F_110 ( V_51 ) ;
if ( V_5 -> V_41 < 0 )
return - V_111 ;
V_5 -> V_41 = F_111 ( V_51 , 1 , V_5 -> V_41 ,
V_119 | V_120 ) ;
if ( V_5 -> V_41 < 0 )
return V_5 -> V_41 ;
V_5 -> V_7 = F_112 ( & V_51 -> V_51 , V_5 -> V_41 , sizeof( * V_5 -> V_7 ) ,
V_47 ) ;
if ( ! V_5 -> V_7 )
return - V_50 ;
for ( V_37 = 0 ; V_37 < V_5 -> V_41 ; V_37 ++ ) {
V_118 = F_113 ( & V_5 -> V_7 [ V_37 ] . V_53 ) ;
if ( V_118 )
return V_118 ;
F_20 ( & V_5 -> V_7 [ V_37 ] . V_24 ) ;
V_118 = F_114 ( & V_51 -> V_51 , F_21 ( V_51 , V_37 ) ,
V_12 , 0 , L_6 , & V_5 -> V_7 [ V_37 ] ) ;
if ( V_118 )
return V_118 ;
}
F_115 ( & V_5 -> V_91 ) ;
F_116 ( V_51 , V_5 ) ;
V_118 = F_86 ( V_5 ) ;
if ( V_118 )
return V_118 ;
F_117 ( & V_5 -> V_51 -> V_51 , L_7 ,
V_5 -> V_4 . V_44 ) ;
return 0 ;
}
static void F_118 ( struct V_1 * V_5 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_5 -> V_41 ; V_37 ++ )
F_119 ( & V_5 -> V_7 [ V_37 ] . V_53 ) ;
}
static void F_120 ( struct V_56 * V_51 )
{
struct V_1 * V_5 = F_121 ( V_51 ) ;
F_81 ( V_5 ) ;
F_118 ( V_5 ) ;
F_122 ( & V_5 -> V_51 -> V_51 . V_113 , L_4 ) ;
F_123 ( V_5 -> V_3 ) ;
F_124 ( V_5 -> V_3 ) ;
F_62 ( V_5 ) ;
F_94 ( V_5 -> V_43 ) ;
}
static int F_125 ( struct V_54 * V_51 )
{
struct V_56 * V_57 = F_28 ( V_51 ) ;
F_126 ( V_57 ) ;
return 0 ;
}
static int F_127 ( struct V_54 * V_51 )
{
struct V_56 * V_57 = F_28 ( V_51 ) ;
F_128 ( V_57 ) ;
return 0 ;
}
