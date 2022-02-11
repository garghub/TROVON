static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
struct V_12 * V_13 = V_10 -> V_13 ;
V_8 -> V_14 = V_15 ;
V_8 -> V_16 = V_17 | F_4 ( V_13 -> V_18 ) ;
V_8 -> V_6 = 0 ;
}
static void F_5 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
unsigned long V_19 ;
F_6 ( & V_20 , V_19 ) ;
F_7 ( V_10 -> V_21 ) ;
F_8 ( & V_10 -> V_22 , & V_10 -> V_13 -> V_23 ) ;
V_10 -> V_21 = true ;
F_9 ( & V_20 , V_19 ) ;
V_6 -> V_24 -> V_25 ( V_6 ) ;
}
static void F_10 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
unsigned long V_19 ;
V_6 -> V_24 -> V_26 ( V_6 ) ;
F_6 ( & V_20 , V_19 ) ;
if ( V_10 -> V_21 ) {
F_11 ( & V_10 -> V_22 ) ;
V_10 -> V_21 = false ;
}
F_9 ( & V_20 , V_19 ) ;
}
static int F_12 ( struct V_5 * V_6 ,
const struct V_27 * V_28 , bool V_29 )
{
return - V_30 ;
}
static T_1 F_13 ( struct V_31 * V_32 ,
T_2 * V_33 )
{
return 0 ;
}
static struct V_12 * F_14 ( struct V_1 * V_34 , struct V_35 * V_36 )
{
int V_37 , V_38 = 1 ;
unsigned long V_19 ;
if ( ! V_36 -> V_39 . V_40 || V_34 -> V_41 == 1 )
return & V_34 -> V_42 [ 0 ] ;
F_6 ( & V_20 , V_19 ) ;
for ( V_37 = 1 ; V_37 < V_34 -> V_41 ; V_37 ++ )
if ( V_34 -> V_42 [ V_37 ] . V_43 < V_34 -> V_42 [ V_38 ] . V_43 )
V_38 = V_37 ;
V_34 -> V_42 [ V_38 ] . V_43 ++ ;
F_9 ( & V_20 , V_19 ) ;
return & V_34 -> V_42 [ V_38 ] ;
}
static int F_15 ( struct V_44 * V_45 , struct V_31 * V_32 ,
unsigned int V_46 , T_1 V_47 ,
T_2 * V_33 )
{
struct V_35 * V_36 = V_33 -> V_36 ;
struct V_1 * V_34 = F_1 ( F_16 ( V_36 ) -> V_3 ) ;
struct V_9 * V_10 = F_17 ( sizeof( * V_10 ) , V_48 ) ;
if ( ! V_10 )
return - V_49 ;
F_18 ( & V_10 -> V_22 ) ;
V_10 -> V_13 = F_14 ( V_34 , V_36 ) ;
V_10 -> V_46 = V_46 ;
F_19 ( V_45 , V_46 , V_10 -> V_13 -> V_50 , V_32 -> V_24 ,
V_10 , V_51 , V_34 , NULL ) ;
return 0 ;
}
static void F_20 ( struct V_44 * V_45 ,
struct V_31 * V_32 , unsigned int V_46 )
{
struct V_9 * V_10 = F_21 ( V_46 ) ;
unsigned long V_19 ;
F_6 ( & V_20 , V_19 ) ;
V_10 -> V_13 -> V_43 -- ;
F_9 ( & V_20 , V_19 ) ;
F_22 ( V_10 , V_52 ) ;
}
static int F_23 ( struct V_44 * V_45 , struct V_53 * V_54 ,
int V_55 , T_2 * V_33 )
{
struct V_56 * V_57 = F_24 ( V_54 ) ;
struct V_1 * V_34 = F_1 ( V_57 -> V_3 ) ;
if ( V_55 > V_34 -> V_41 )
return V_34 -> V_41 ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
return 0 ;
}
static void F_25 ( T_2 * V_33 , struct V_35 * V_36 )
{
V_33 -> V_36 = V_36 ;
}
static struct V_53 * F_26 ( struct V_53 * V_54 )
{
struct V_56 * V_57 = F_24 ( V_54 ) ;
struct V_1 * V_34 = F_1 ( V_57 -> V_3 ) ;
return & V_34 -> V_54 -> V_54 ;
}
static struct V_58 * F_27 ( struct V_53 * V_54 )
{
return F_28 ( F_26 ( V_54 ) ) ;
}
static void * F_29 ( struct V_53 * V_54 , T_3 V_59 , T_4 * V_60 ,
T_5 V_61 , unsigned long V_62 )
{
return F_27 ( V_54 ) -> F_30 ( F_26 ( V_54 ) , V_59 , V_60 , V_61 ,
V_62 ) ;
}
static void F_31 ( struct V_53 * V_54 , T_3 V_59 , void * V_63 ,
T_4 V_60 , unsigned long V_62 )
{
return F_27 ( V_54 ) -> free ( F_26 ( V_54 ) , V_59 , V_63 , V_60 ,
V_62 ) ;
}
static int F_32 ( struct V_53 * V_54 , struct V_64 * V_65 ,
void * V_66 , T_4 V_60 , T_3 V_59 ,
unsigned long V_62 )
{
return F_27 ( V_54 ) -> F_33 ( F_26 ( V_54 ) , V_65 , V_66 , V_60 ,
V_59 , V_62 ) ;
}
static int F_34 ( struct V_53 * V_54 , struct V_67 * V_68 ,
void * V_66 , T_4 V_60 , T_3 V_59 ,
unsigned long V_62 )
{
return F_27 ( V_54 ) -> F_35 ( F_26 ( V_54 ) , V_68 , V_66 ,
V_60 , V_59 , V_62 ) ;
}
static T_4 F_36 ( struct V_53 * V_54 , struct V_69 * V_69 ,
unsigned long V_70 , T_3 V_59 ,
enum V_71 V_72 ,
unsigned long V_62 )
{
return F_27 ( V_54 ) -> F_37 ( F_26 ( V_54 ) , V_69 , V_70 , V_59 ,
V_72 , V_62 ) ;
}
static void F_38 ( struct V_53 * V_54 , T_4 V_60 , T_3 V_59 ,
enum V_71 V_72 , unsigned long V_62 )
{
F_27 ( V_54 ) -> F_39 ( F_26 ( V_54 ) , V_60 , V_59 , V_72 , V_62 ) ;
}
static int F_40 ( struct V_53 * V_54 , struct V_73 * V_74 , int V_75 ,
enum V_71 V_72 , unsigned long V_62 )
{
return F_27 ( V_54 ) -> F_41 ( F_26 ( V_54 ) , V_74 , V_75 , V_72 , V_62 ) ;
}
static void F_42 ( struct V_53 * V_54 , struct V_73 * V_74 , int V_75 ,
enum V_71 V_72 , unsigned long V_62 )
{
F_27 ( V_54 ) -> F_43 ( F_26 ( V_54 ) , V_74 , V_75 , V_72 , V_62 ) ;
}
static void F_44 ( struct V_53 * V_54 , T_4 V_60 ,
T_3 V_59 , enum V_71 V_72 )
{
F_27 ( V_54 ) -> F_45 ( F_26 ( V_54 ) , V_60 , V_59 , V_72 ) ;
}
static void F_46 ( struct V_53 * V_54 , T_4 V_60 ,
T_3 V_59 , enum V_71 V_72 )
{
F_27 ( V_54 ) -> F_47 ( F_26 ( V_54 ) , V_60 , V_59 ,
V_72 ) ;
}
static void F_48 ( struct V_53 * V_54 , struct V_73 * V_74 ,
int V_75 , enum V_71 V_72 )
{
F_27 ( V_54 ) -> F_49 ( F_26 ( V_54 ) , V_74 , V_75 , V_72 ) ;
}
static void F_50 ( struct V_53 * V_54 , struct V_73 * V_74 ,
int V_75 , enum V_71 V_72 )
{
F_27 ( V_54 ) -> F_51 ( F_26 ( V_54 ) , V_74 , V_75 , V_72 ) ;
}
static int F_52 ( struct V_53 * V_54 , T_4 V_60 )
{
return F_27 ( V_54 ) -> F_53 ( F_26 ( V_54 ) , V_60 ) ;
}
static int F_54 ( struct V_53 * V_54 , T_6 V_76 )
{
return F_27 ( V_54 ) -> F_55 ( F_26 ( V_54 ) , V_76 ) ;
}
static T_6 F_56 ( struct V_53 * V_54 )
{
return F_27 ( V_54 ) -> F_57 ( F_26 ( V_54 ) ) ;
}
static void F_58 ( struct V_1 * V_34 )
{
struct V_77 * V_45 = & V_34 -> V_77 ;
if ( F_28 ( & V_34 -> V_54 -> V_54 ) )
F_59 ( V_45 ) ;
}
static void F_60 ( struct V_1 * V_34 )
{
const struct V_58 * V_78 = F_28 ( & V_34 -> V_54 -> V_54 ) ;
struct V_58 * V_28 = & V_34 -> V_79 ;
struct V_77 * V_45 = & V_34 -> V_77 ;
V_45 -> V_80 = V_34 -> V_4 . V_45 ;
V_45 -> V_79 = V_28 ;
if ( ! V_78 )
return;
F_61 ( V_78 , V_28 , F_30 ) ;
F_61 ( V_78 , V_28 , free ) ;
F_61 ( V_78 , V_28 , F_33 ) ;
F_61 ( V_78 , V_28 , F_35 ) ;
F_61 ( V_78 , V_28 , F_37 ) ;
F_61 ( V_78 , V_28 , F_39 ) ;
F_61 ( V_78 , V_28 , F_41 ) ;
F_61 ( V_78 , V_28 , F_43 ) ;
F_61 ( V_78 , V_28 , F_45 ) ;
F_61 ( V_78 , V_28 , F_47 ) ;
F_61 ( V_78 , V_28 , F_49 ) ;
F_61 ( V_78 , V_28 , F_51 ) ;
F_61 ( V_78 , V_28 , F_53 ) ;
F_61 ( V_78 , V_28 , F_55 ) ;
#ifdef F_62
F_61 ( V_78 , V_28 , F_57 ) ;
#endif
F_63 ( V_45 ) ;
}
static void F_58 ( struct V_1 * V_34 ) {}
static void F_60 ( struct V_1 * V_34 ) {}
static char T_7 * F_64 ( struct V_1 * V_34 , struct V_2 * V_3 ,
unsigned int V_81 , int V_82 , int V_83 )
{
char T_7 * V_60 = V_34 -> V_84 +
( V_3 -> V_85 << 20 ) + ( V_81 << 12 ) + V_82 ;
if ( ( V_60 - V_34 -> V_84 ) + V_83 >=
F_65 ( & V_34 -> V_54 -> V_86 [ V_87 ] ) )
return NULL ;
return V_60 ;
}
static int F_66 ( struct V_2 * V_3 , unsigned int V_81 , int V_82 ,
int V_83 , T_8 * V_88 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
char T_7 * V_60 = F_64 ( V_34 , V_3 , V_81 , V_82 , V_83 ) ;
unsigned long V_19 ;
int V_89 = 0 ;
if ( ! V_60 )
return - V_90 ;
F_67 ( & V_34 -> V_91 , V_19 ) ;
switch ( V_83 ) {
case 1 :
* V_88 = F_68 ( V_60 ) ;
break;
case 2 :
* V_88 = F_69 ( V_60 ) ;
break;
case 4 :
* V_88 = F_70 ( V_60 ) ;
break;
default:
V_89 = - V_30 ;
break;
}
F_71 ( & V_34 -> V_91 , V_19 ) ;
return V_89 ;
}
static int F_72 ( struct V_2 * V_3 , unsigned int V_81 , int V_82 ,
int V_83 , T_8 V_88 )
{
struct V_1 * V_34 = F_1 ( V_3 ) ;
char T_7 * V_60 = F_64 ( V_34 , V_3 , V_81 , V_82 , V_83 ) ;
unsigned long V_19 ;
int V_89 = 0 ;
if ( ! V_60 )
return - V_90 ;
F_67 ( & V_34 -> V_91 , V_19 ) ;
switch ( V_83 ) {
case 1 :
F_73 ( V_88 , V_60 ) ;
F_68 ( V_60 ) ;
break;
case 2 :
F_74 ( V_88 , V_60 ) ;
F_69 ( V_60 ) ;
break;
case 4 :
F_75 ( V_88 , V_60 ) ;
F_70 ( V_60 ) ;
break;
default:
V_89 = - V_30 ;
break;
}
F_71 ( & V_34 -> V_91 , V_19 ) ;
return V_89 ;
}
static void F_76 ( struct V_1 * V_34 )
{
V_34 -> V_54 -> V_86 [ V_92 ] . V_93 = & V_34 -> V_94 [ 1 ] ;
V_34 -> V_54 -> V_86 [ V_95 ] . V_93 = & V_34 -> V_94 [ 2 ] ;
}
static void F_77 ( struct V_1 * V_34 )
{
V_34 -> V_54 -> V_86 [ V_92 ] . V_93 = NULL ;
V_34 -> V_54 -> V_86 [ V_95 ] . V_93 = NULL ;
}
static int F_78 ( void )
{
int V_45 = 0xffff ;
struct V_2 * V_3 = NULL ;
while ( ( V_3 = F_79 ( V_3 ) ) != NULL )
V_45 = F_80 ( int , V_45 , F_81 ( V_3 ) ) ;
return V_45 + 1 ;
}
static int F_82 ( struct V_1 * V_34 )
{
struct V_96 * V_97 = & V_34 -> V_4 ;
struct V_86 * V_98 ;
T_8 V_99 ;
unsigned long V_19 ;
F_83 ( V_94 ) ;
V_98 = & V_34 -> V_54 -> V_86 [ V_87 ] ;
V_34 -> V_94 [ 0 ] = (struct V_86 ) {
. V_100 = L_1 ,
. V_101 = 0 ,
. V_102 = ( F_65 ( V_98 ) >> 20 ) - 1 ,
. V_19 = V_103 | V_104 ,
} ;
V_98 = & V_34 -> V_54 -> V_86 [ V_92 ] ;
V_99 = F_84 ( V_98 -> V_102 ) ;
V_19 = V_98 -> V_19 & ~ V_105 ;
if ( ! V_99 )
V_19 &= ~ V_106 ;
V_34 -> V_94 [ 1 ] = (struct V_86 ) {
. V_100 = L_2 ,
. V_101 = V_98 -> V_101 ,
. V_102 = V_98 -> V_102 ,
. V_19 = V_19 ,
. V_107 = V_98 ,
} ;
V_98 = & V_34 -> V_54 -> V_86 [ V_95 ] ;
V_99 = F_84 ( V_98 -> V_102 ) ;
V_19 = V_98 -> V_19 & ~ V_105 ;
if ( ! V_99 )
V_19 &= ~ V_106 ;
V_34 -> V_94 [ 2 ] = (struct V_86 ) {
. V_100 = L_3 ,
. V_101 = V_98 -> V_101 + 0x2000 ,
. V_102 = V_98 -> V_102 ,
. V_19 = V_19 ,
. V_107 = V_98 ,
} ;
V_97 -> V_45 = F_78 () ;
if ( V_97 -> V_45 < 0 )
return V_97 -> V_45 ;
V_97 -> V_22 = F_85 ( V_34 -> V_54 -> V_3 ) ;
V_34 -> V_44 = F_86 ( NULL , & V_108 ,
V_109 ) ;
if ( ! V_34 -> V_44 )
return - V_110 ;
F_87 ( & V_94 , & V_34 -> V_94 [ 0 ] ) ;
F_87 ( & V_94 , & V_34 -> V_94 [ 1 ] ) ;
F_87 ( & V_94 , & V_34 -> V_94 [ 2 ] ) ;
V_34 -> V_3 = F_88 ( & V_34 -> V_54 -> V_54 , 0 , & V_111 , V_97 ,
& V_94 ) ;
if ( ! V_34 -> V_3 ) {
F_89 ( & V_94 ) ;
F_90 ( V_34 -> V_44 ) ;
return - V_110 ;
}
F_76 ( V_34 ) ;
F_60 ( V_34 ) ;
F_91 ( & V_34 -> V_3 -> V_54 , V_34 -> V_44 ) ;
F_92 ( V_34 -> V_3 ) ;
F_93 ( F_94 ( & V_34 -> V_54 -> V_54 . V_112 , & V_34 -> V_3 -> V_54 . V_112 ,
L_4 ) , L_5 ) ;
return 0 ;
}
static T_9 V_9 ( int V_13 , void * V_6 )
{
struct V_12 * V_42 = V_6 ;
struct V_9 * V_10 ;
F_95 () ;
F_96 (vmdirq, &irqs->irq_list, node)
F_97 ( V_10 -> V_46 ) ;
F_98 () ;
return V_113 ;
}
static int F_99 ( struct V_56 * V_54 , const struct V_114 * V_115 )
{
struct V_1 * V_34 ;
int V_37 , V_116 ;
if ( F_65 ( & V_54 -> V_86 [ V_87 ] ) < ( 1 << 20 ) )
return - V_49 ;
V_34 = F_100 ( & V_54 -> V_54 , sizeof( * V_34 ) , V_48 ) ;
if ( ! V_34 )
return - V_49 ;
V_34 -> V_54 = V_54 ;
V_116 = F_101 ( V_54 ) ;
if ( V_116 < 0 )
return V_116 ;
V_34 -> V_84 = F_102 ( V_54 , V_87 , 0 ) ;
if ( ! V_34 -> V_84 )
return - V_49 ;
F_103 ( V_54 ) ;
if ( F_104 ( & V_54 -> V_54 , F_105 ( 64 ) ) &&
F_104 ( & V_54 -> V_54 , F_105 ( 32 ) ) )
return - V_110 ;
V_34 -> V_41 = F_106 ( V_54 ) ;
if ( V_34 -> V_41 < 0 )
return - V_110 ;
V_34 -> V_42 = F_107 ( & V_54 -> V_54 , V_34 -> V_41 , sizeof( * V_34 -> V_42 ) ,
V_48 ) ;
if ( ! V_34 -> V_42 )
return - V_49 ;
V_34 -> V_117 = F_107 ( & V_54 -> V_54 , V_34 -> V_41 ,
sizeof( * V_34 -> V_117 ) ,
V_48 ) ;
if ( ! V_34 -> V_117 )
return - V_49 ;
for ( V_37 = 0 ; V_37 < V_34 -> V_41 ; V_37 ++ )
V_34 -> V_117 [ V_37 ] . V_118 = V_37 ;
V_34 -> V_41 = F_108 ( V_34 -> V_54 , V_34 -> V_117 , 1 ,
V_34 -> V_41 ) ;
if ( V_34 -> V_41 < 0 )
return V_34 -> V_41 ;
for ( V_37 = 0 ; V_37 < V_34 -> V_41 ; V_37 ++ ) {
F_18 ( & V_34 -> V_42 [ V_37 ] . V_23 ) ;
V_34 -> V_42 [ V_37 ] . V_50 = V_34 -> V_117 [ V_37 ] . V_119 ;
V_34 -> V_42 [ V_37 ] . V_18 = V_37 ;
V_116 = F_109 ( & V_54 -> V_54 , V_34 -> V_42 [ V_37 ] . V_50 ,
V_9 , 0 , L_6 , & V_34 -> V_42 [ V_37 ] ) ;
if ( V_116 )
return V_116 ;
}
F_110 ( & V_34 -> V_91 ) ;
F_111 ( V_54 , V_34 ) ;
V_116 = F_82 ( V_34 ) ;
if ( V_116 )
return V_116 ;
F_112 ( & V_34 -> V_54 -> V_54 , L_7 ,
V_34 -> V_4 . V_45 ) ;
return 0 ;
}
static void F_113 ( struct V_56 * V_54 )
{
struct V_1 * V_34 = F_114 ( V_54 ) ;
F_77 ( V_34 ) ;
F_111 ( V_54 , NULL ) ;
F_115 ( & V_34 -> V_54 -> V_54 . V_112 , L_4 ) ;
F_116 ( V_34 -> V_3 ) ;
F_117 ( V_34 -> V_3 ) ;
F_58 ( V_34 ) ;
F_90 ( V_34 -> V_44 ) ;
}
static int F_118 ( struct V_53 * V_54 )
{
struct V_56 * V_57 = F_24 ( V_54 ) ;
F_119 ( V_57 ) ;
return 0 ;
}
static int F_120 ( struct V_53 * V_54 )
{
struct V_56 * V_57 = F_24 ( V_54 ) ;
F_121 ( V_57 ) ;
return 0 ;
}
