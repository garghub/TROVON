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
F_6 ( & V_19 ) ;
F_7 ( & V_10 -> V_20 , & V_10 -> V_13 -> V_21 ) ;
F_8 ( & V_19 ) ;
V_6 -> V_22 -> V_23 ( V_6 ) ;
}
static void F_9 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
V_6 -> V_22 -> V_24 ( V_6 ) ;
F_6 ( & V_19 ) ;
F_10 ( & V_10 -> V_20 ) ;
F_8 ( & V_19 ) ;
}
static int F_11 ( struct V_5 * V_6 ,
const struct V_25 * V_26 , bool V_27 )
{
return - V_28 ;
}
static T_1 F_12 ( struct V_29 * V_30 ,
T_2 * V_31 )
{
return 0 ;
}
static struct V_12 * F_13 ( struct V_1 * V_32 )
{
int V_33 , V_34 = 0 ;
F_6 ( & V_19 ) ;
for ( V_33 = 1 ; V_33 < V_32 -> V_35 ; V_33 ++ )
if ( V_32 -> V_36 [ V_33 ] . V_37 < V_32 -> V_36 [ V_34 ] . V_37 )
V_34 = V_33 ;
V_32 -> V_36 [ V_34 ] . V_37 ++ ;
F_8 ( & V_19 ) ;
return & V_32 -> V_36 [ V_34 ] ;
}
static int F_14 ( struct V_38 * V_39 , struct V_29 * V_30 ,
unsigned int V_40 , T_1 V_41 ,
T_2 * V_31 )
{
struct V_1 * V_32 = F_1 ( F_15 ( V_31 -> V_42 ) -> V_3 ) ;
struct V_9 * V_10 = F_16 ( sizeof( * V_10 ) , V_43 ) ;
if ( ! V_10 )
return - V_44 ;
F_17 ( & V_10 -> V_20 ) ;
V_10 -> V_13 = F_13 ( V_32 ) ;
V_10 -> V_40 = V_40 ;
F_18 ( V_39 , V_40 , V_10 -> V_13 -> V_45 , V_30 -> V_22 ,
V_10 , V_46 , V_32 , NULL ) ;
return 0 ;
}
static void F_19 ( struct V_38 * V_39 ,
struct V_29 * V_30 , unsigned int V_40 )
{
struct V_9 * V_10 = F_20 ( V_40 ) ;
F_6 ( & V_19 ) ;
V_10 -> V_13 -> V_37 -- ;
F_8 ( & V_19 ) ;
F_21 ( V_10 , V_47 ) ;
}
static int F_22 ( struct V_38 * V_39 , struct V_48 * V_49 ,
int V_50 , T_2 * V_31 )
{
struct V_51 * V_52 = F_23 ( V_49 ) ;
struct V_1 * V_32 = F_1 ( V_52 -> V_3 ) ;
if ( V_50 > V_32 -> V_35 )
return V_32 -> V_35 ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
return 0 ;
}
static void F_24 ( T_2 * V_31 , struct V_53 * V_42 )
{
V_31 -> V_42 = V_42 ;
}
static struct V_48 * F_25 ( struct V_48 * V_49 )
{
struct V_51 * V_52 = F_23 ( V_49 ) ;
struct V_1 * V_32 = F_1 ( V_52 -> V_3 ) ;
return & V_32 -> V_49 -> V_49 ;
}
static struct V_54 * F_26 ( struct V_48 * V_49 )
{
return F_25 ( V_49 ) -> V_55 . V_56 ;
}
static void * F_27 ( struct V_48 * V_49 , T_3 V_57 , T_4 * V_58 ,
T_5 V_59 , struct V_60 * V_61 )
{
return F_26 ( V_49 ) -> F_28 ( F_25 ( V_49 ) , V_57 , V_58 , V_59 ,
V_61 ) ;
}
static void F_29 ( struct V_48 * V_49 , T_3 V_57 , void * V_62 ,
T_4 V_58 , struct V_60 * V_61 )
{
return F_26 ( V_49 ) -> free ( F_25 ( V_49 ) , V_57 , V_62 , V_58 ,
V_61 ) ;
}
static int F_30 ( struct V_48 * V_49 , struct V_63 * V_64 ,
void * V_65 , T_4 V_58 , T_3 V_57 ,
struct V_60 * V_61 )
{
return F_26 ( V_49 ) -> F_31 ( F_25 ( V_49 ) , V_64 , V_65 , V_58 ,
V_57 , V_61 ) ;
}
static int F_32 ( struct V_48 * V_49 , struct V_66 * V_67 ,
void * V_65 , T_4 V_58 , T_3 V_57 ,
struct V_60 * V_61 )
{
return F_26 ( V_49 ) -> F_33 ( F_25 ( V_49 ) , V_67 , V_65 ,
V_58 , V_57 , V_61 ) ;
}
static T_4 F_34 ( struct V_48 * V_49 , struct V_68 * V_68 ,
unsigned long V_69 , T_3 V_57 ,
enum V_70 V_71 ,
struct V_60 * V_61 )
{
return F_26 ( V_49 ) -> F_35 ( F_25 ( V_49 ) , V_68 , V_69 , V_57 ,
V_71 , V_61 ) ;
}
static void F_36 ( struct V_48 * V_49 , T_4 V_58 , T_3 V_57 ,
enum V_70 V_71 , struct V_60 * V_61 )
{
F_26 ( V_49 ) -> F_37 ( F_25 ( V_49 ) , V_58 , V_57 , V_71 , V_61 ) ;
}
static int F_38 ( struct V_48 * V_49 , struct V_72 * V_73 , int V_74 ,
enum V_70 V_71 , struct V_60 * V_61 )
{
return F_26 ( V_49 ) -> F_39 ( F_25 ( V_49 ) , V_73 , V_74 , V_71 , V_61 ) ;
}
static void F_40 ( struct V_48 * V_49 , struct V_72 * V_73 , int V_74 ,
enum V_70 V_71 , struct V_60 * V_61 )
{
F_26 ( V_49 ) -> F_41 ( F_25 ( V_49 ) , V_73 , V_74 , V_71 , V_61 ) ;
}
static void F_42 ( struct V_48 * V_49 , T_4 V_58 ,
T_3 V_57 , enum V_70 V_71 )
{
F_26 ( V_49 ) -> F_43 ( F_25 ( V_49 ) , V_58 , V_57 , V_71 ) ;
}
static void F_44 ( struct V_48 * V_49 , T_4 V_58 ,
T_3 V_57 , enum V_70 V_71 )
{
F_26 ( V_49 ) -> F_45 ( F_25 ( V_49 ) , V_58 , V_57 ,
V_71 ) ;
}
static void F_46 ( struct V_48 * V_49 , struct V_72 * V_73 ,
int V_74 , enum V_70 V_71 )
{
F_26 ( V_49 ) -> F_47 ( F_25 ( V_49 ) , V_73 , V_74 , V_71 ) ;
}
static void F_48 ( struct V_48 * V_49 , struct V_72 * V_73 ,
int V_74 , enum V_70 V_71 )
{
F_26 ( V_49 ) -> F_49 ( F_25 ( V_49 ) , V_73 , V_74 , V_71 ) ;
}
static int F_50 ( struct V_48 * V_49 , T_4 V_58 )
{
return F_26 ( V_49 ) -> F_51 ( F_25 ( V_49 ) , V_58 ) ;
}
static int F_52 ( struct V_48 * V_49 , T_6 V_75 )
{
return F_26 ( V_49 ) -> F_53 ( F_25 ( V_49 ) , V_75 ) ;
}
static T_6 F_54 ( struct V_48 * V_49 )
{
return F_26 ( V_49 ) -> F_55 ( F_25 ( V_49 ) ) ;
}
static void F_56 ( struct V_1 * V_32 )
{
struct V_76 * V_39 = & V_32 -> V_76 ;
if ( V_32 -> V_49 -> V_49 . V_55 . V_56 )
F_57 ( V_39 ) ;
}
static void F_58 ( struct V_1 * V_32 )
{
const struct V_54 * V_77 = V_32 -> V_49 -> V_49 . V_55 . V_56 ;
struct V_54 * V_26 = & V_32 -> V_56 ;
struct V_76 * V_39 = & V_32 -> V_76 ;
V_39 -> V_78 = V_32 -> V_4 . V_39 ;
V_39 -> V_56 = V_26 ;
if ( ! V_77 )
return;
F_59 ( V_77 , V_26 , F_28 ) ;
F_59 ( V_77 , V_26 , free ) ;
F_59 ( V_77 , V_26 , F_31 ) ;
F_59 ( V_77 , V_26 , F_33 ) ;
F_59 ( V_77 , V_26 , F_35 ) ;
F_59 ( V_77 , V_26 , F_37 ) ;
F_59 ( V_77 , V_26 , F_39 ) ;
F_59 ( V_77 , V_26 , F_41 ) ;
F_59 ( V_77 , V_26 , F_43 ) ;
F_59 ( V_77 , V_26 , F_45 ) ;
F_59 ( V_77 , V_26 , F_47 ) ;
F_59 ( V_77 , V_26 , F_49 ) ;
F_59 ( V_77 , V_26 , F_51 ) ;
F_59 ( V_77 , V_26 , F_53 ) ;
#ifdef F_60
F_59 ( V_77 , V_26 , F_55 ) ;
#endif
F_61 ( V_39 ) ;
}
static void F_56 ( struct V_1 * V_32 ) {}
static void F_58 ( struct V_1 * V_32 ) {}
static char T_7 * F_62 ( struct V_1 * V_32 , struct V_2 * V_3 ,
unsigned int V_79 , int V_80 , int V_81 )
{
char T_7 * V_58 = V_32 -> V_82 +
( V_3 -> V_83 << 20 ) + ( V_79 << 12 ) + V_80 ;
if ( ( V_58 - V_32 -> V_82 ) + V_81 >=
F_63 ( & V_32 -> V_49 -> V_84 [ V_85 ] ) )
return NULL ;
return V_58 ;
}
static int F_64 ( struct V_2 * V_3 , unsigned int V_79 , int V_80 ,
int V_81 , T_8 * V_86 )
{
struct V_1 * V_32 = F_1 ( V_3 ) ;
char T_7 * V_58 = F_62 ( V_32 , V_3 , V_79 , V_80 , V_81 ) ;
unsigned long V_87 ;
int V_88 = 0 ;
if ( ! V_58 )
return - V_89 ;
F_65 ( & V_32 -> V_90 , V_87 ) ;
switch ( V_81 ) {
case 1 :
* V_86 = F_66 ( V_58 ) ;
break;
case 2 :
* V_86 = F_67 ( V_58 ) ;
break;
case 4 :
* V_86 = F_68 ( V_58 ) ;
break;
default:
V_88 = - V_28 ;
break;
}
F_69 ( & V_32 -> V_90 , V_87 ) ;
return V_88 ;
}
static int F_70 ( struct V_2 * V_3 , unsigned int V_79 , int V_80 ,
int V_81 , T_8 V_86 )
{
struct V_1 * V_32 = F_1 ( V_3 ) ;
char T_7 * V_58 = F_62 ( V_32 , V_3 , V_79 , V_80 , V_81 ) ;
unsigned long V_87 ;
int V_88 = 0 ;
if ( ! V_58 )
return - V_89 ;
F_65 ( & V_32 -> V_90 , V_87 ) ;
switch ( V_81 ) {
case 1 :
F_71 ( V_86 , V_58 ) ;
F_66 ( V_58 ) ;
break;
case 2 :
F_72 ( V_86 , V_58 ) ;
F_67 ( V_58 ) ;
break;
case 4 :
F_73 ( V_86 , V_58 ) ;
F_68 ( V_58 ) ;
break;
default:
V_88 = - V_28 ;
break;
}
F_69 ( & V_32 -> V_90 , V_87 ) ;
return V_88 ;
}
static int F_74 ( void )
{
int V_39 = 0xffff ;
struct V_2 * V_3 = NULL ;
while ( ( V_3 = F_75 ( V_3 ) ) != NULL )
V_39 = F_76 ( int , V_39 , F_77 ( V_3 ) ) ;
return V_39 + 1 ;
}
static int F_78 ( struct V_1 * V_32 )
{
struct V_91 * V_92 = & V_32 -> V_4 ;
struct V_84 * V_93 ;
T_8 V_94 ;
unsigned long V_87 ;
F_79 ( V_95 ) ;
V_93 = & V_32 -> V_49 -> V_84 [ V_85 ] ;
V_32 -> V_95 [ 0 ] = (struct V_84 ) {
. V_96 = L_1 ,
. V_97 = V_93 -> V_97 ,
. V_98 = ( F_63 ( V_93 ) >> 20 ) - 1 ,
. V_87 = V_99 | V_100 ,
} ;
V_93 = & V_32 -> V_49 -> V_84 [ V_101 ] ;
V_94 = F_80 ( V_93 -> V_98 ) ;
V_87 = V_93 -> V_87 & ~ V_102 ;
if ( ! V_94 )
V_87 &= ~ V_103 ;
V_32 -> V_95 [ 1 ] = (struct V_84 ) {
. V_96 = L_2 ,
. V_97 = V_93 -> V_97 ,
. V_98 = V_93 -> V_98 ,
. V_87 = V_87 ,
} ;
V_93 = & V_32 -> V_49 -> V_84 [ V_104 ] ;
V_94 = F_80 ( V_93 -> V_98 ) ;
V_87 = V_93 -> V_87 & ~ V_102 ;
if ( ! V_94 )
V_87 &= ~ V_103 ;
V_32 -> V_95 [ 2 ] = (struct V_84 ) {
. V_96 = L_3 ,
. V_97 = V_93 -> V_97 + 0x2000 ,
. V_98 = V_93 -> V_98 ,
. V_87 = V_87 ,
} ;
V_92 -> V_39 = F_74 () ;
if ( V_92 -> V_39 < 0 )
return V_92 -> V_39 ;
V_92 -> V_20 = F_81 ( V_32 -> V_49 -> V_3 ) ;
V_32 -> V_38 = F_82 ( NULL , & V_105 ,
NULL ) ;
if ( ! V_32 -> V_38 )
return - V_106 ;
F_83 ( & V_95 , & V_32 -> V_95 [ 0 ] ) ;
F_83 ( & V_95 , & V_32 -> V_95 [ 1 ] ) ;
F_83 ( & V_95 , & V_32 -> V_95 [ 2 ] ) ;
V_32 -> V_3 = F_84 ( & V_32 -> V_49 -> V_49 , 0 , & V_107 , V_92 ,
& V_95 ) ;
if ( ! V_32 -> V_3 ) {
F_85 ( & V_95 ) ;
F_86 ( V_32 -> V_38 ) ;
return - V_106 ;
}
F_58 ( V_32 ) ;
F_87 ( & V_32 -> V_3 -> V_49 , V_32 -> V_38 ) ;
F_88 ( V_32 -> V_3 ) ;
F_89 ( F_90 ( & V_32 -> V_49 -> V_49 . V_108 , & V_32 -> V_3 -> V_49 . V_108 ,
L_4 ) , L_5 ) ;
return 0 ;
}
static T_9 V_9 ( int V_13 , void * V_6 )
{
struct V_12 * V_36 = V_6 ;
struct V_9 * V_10 ;
F_91 () ;
F_92 (vmdirq, &irqs->irq_list, node)
F_93 ( V_10 -> V_40 ) ;
F_94 () ;
return V_109 ;
}
static int F_95 ( struct V_51 * V_49 , const struct V_110 * V_111 )
{
struct V_1 * V_32 ;
int V_33 , V_112 ;
if ( F_63 ( & V_49 -> V_84 [ V_85 ] ) < ( 1 << 20 ) )
return - V_44 ;
V_32 = F_96 ( & V_49 -> V_49 , sizeof( * V_32 ) , V_43 ) ;
if ( ! V_32 )
return - V_44 ;
V_32 -> V_49 = V_49 ;
V_112 = F_97 ( V_49 ) ;
if ( V_112 < 0 )
return V_112 ;
V_32 -> V_82 = F_98 ( V_49 , V_85 , 0 ) ;
if ( ! V_32 -> V_82 )
return - V_44 ;
F_99 ( V_49 ) ;
if ( F_100 ( & V_49 -> V_49 , F_101 ( 64 ) ) &&
F_100 ( & V_49 -> V_49 , F_101 ( 32 ) ) )
return - V_106 ;
V_32 -> V_35 = F_102 ( V_49 ) ;
if ( V_32 -> V_35 < 0 )
return - V_106 ;
V_32 -> V_36 = F_103 ( & V_49 -> V_49 , V_32 -> V_35 , sizeof( * V_32 -> V_36 ) ,
V_43 ) ;
if ( ! V_32 -> V_36 )
return - V_44 ;
V_32 -> V_113 = F_103 ( & V_49 -> V_49 , V_32 -> V_35 ,
sizeof( * V_32 -> V_113 ) ,
V_43 ) ;
if ( ! V_32 -> V_113 )
return - V_44 ;
for ( V_33 = 0 ; V_33 < V_32 -> V_35 ; V_33 ++ )
V_32 -> V_113 [ V_33 ] . V_114 = V_33 ;
V_32 -> V_35 = F_104 ( V_32 -> V_49 , V_32 -> V_113 , 1 ,
V_32 -> V_35 ) ;
if ( V_32 -> V_35 < 0 )
return V_32 -> V_35 ;
for ( V_33 = 0 ; V_33 < V_32 -> V_35 ; V_33 ++ ) {
F_17 ( & V_32 -> V_36 [ V_33 ] . V_21 ) ;
V_32 -> V_36 [ V_33 ] . V_45 = V_32 -> V_113 [ V_33 ] . V_115 ;
V_32 -> V_36 [ V_33 ] . V_18 = V_33 ;
V_112 = F_105 ( & V_49 -> V_49 , V_32 -> V_36 [ V_33 ] . V_45 ,
V_9 , 0 , L_6 , & V_32 -> V_36 [ V_33 ] ) ;
if ( V_112 )
return V_112 ;
}
F_106 ( & V_32 -> V_90 ) ;
F_107 ( V_49 , V_32 ) ;
V_112 = F_78 ( V_32 ) ;
if ( V_112 )
return V_112 ;
F_108 ( & V_32 -> V_49 -> V_49 , L_7 ,
V_32 -> V_4 . V_39 ) ;
return 0 ;
}
static void F_109 ( struct V_51 * V_49 )
{
struct V_1 * V_32 = F_110 ( V_49 ) ;
F_107 ( V_49 , NULL ) ;
F_111 ( & V_32 -> V_49 -> V_49 . V_108 , L_4 ) ;
F_112 ( V_32 -> V_3 ) ;
F_113 ( V_32 -> V_3 ) ;
F_56 ( V_32 ) ;
F_86 ( V_32 -> V_38 ) ;
}
static int F_114 ( struct V_48 * V_49 )
{
struct V_51 * V_52 = F_23 ( V_49 ) ;
F_115 ( V_52 ) ;
return 0 ;
}
static int F_116 ( struct V_48 * V_49 )
{
struct V_51 * V_52 = F_23 ( V_49 ) ;
F_117 ( V_52 ) ;
return 0 ;
}
