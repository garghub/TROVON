static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_6 = V_4 -> V_6 ;
if ( ! V_4 -> V_7 ) {
F_3 ( V_6 , V_8 , V_4 -> V_9 , 1 ,
false ) ;
F_3 ( V_6 , V_8 , V_4 -> V_9 , 0 ,
false ) ;
} else
F_3 ( V_6 , V_10 ,
V_4 -> V_9 , 1 , false ) ;
}
static void
F_4 ( struct V_11 * V_12 )
{
struct V_13 * V_7 ;
struct V_6 * V_6 ;
struct V_3 * V_4 ;
int V_14 ;
V_7 = F_2 ( V_12 ,
struct V_13 , V_15 ) ;
V_6 = V_7 -> V_6 ;
F_3 ( V_6 , V_10 ,
V_7 -> V_15 . V_9 , 0 , false ) ;
V_14 = F_5 ( & V_6 -> V_16 ) ;
F_6 (irqfd, &resampler->list, resampler_link)
F_7 ( V_4 -> V_17 , 1 ) ;
F_8 ( & V_6 -> V_16 , V_14 ) ;
}
static void
F_9 ( struct V_3 * V_4 )
{
struct V_13 * V_7 = V_4 -> V_7 ;
struct V_6 * V_6 = V_7 -> V_6 ;
F_10 ( & V_6 -> V_18 . V_19 ) ;
F_11 ( & V_4 -> V_20 ) ;
F_12 ( & V_6 -> V_16 ) ;
if ( F_13 ( & V_7 -> V_21 ) ) {
F_14 ( & V_7 -> V_22 ) ;
F_15 ( V_6 , & V_7 -> V_15 ) ;
F_3 ( V_6 , V_10 ,
V_7 -> V_15 . V_9 , 0 , false ) ;
F_16 ( V_7 ) ;
}
F_17 ( & V_6 -> V_18 . V_19 ) ;
}
static void
F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_23 ) ;
T_1 V_24 ;
F_19 ( V_4 -> V_25 , & V_4 -> V_26 , & V_24 ) ;
F_20 ( & V_4 -> V_5 ) ;
if ( V_4 -> V_7 ) {
F_9 ( V_4 ) ;
F_21 ( V_4 -> V_17 ) ;
}
#ifdef F_22
F_23 ( & V_4 -> V_27 ) ;
#endif
F_21 ( V_4 -> V_25 ) ;
F_16 ( V_4 ) ;
}
static bool
F_24 ( struct V_3 * V_4 )
{
return F_13 ( & V_4 -> V_21 ) ? false : true ;
}
static void
F_25 ( struct V_3 * V_4 )
{
F_26 ( ! F_24 ( V_4 ) ) ;
F_27 ( & V_4 -> V_21 ) ;
F_28 ( V_28 , & V_4 -> V_23 ) ;
}
static int
F_29 ( T_2 * V_26 , unsigned V_29 , int V_30 , void * V_31 )
{
struct V_3 * V_4 =
F_2 ( V_26 , struct V_3 , V_26 ) ;
unsigned long V_32 = ( unsigned long ) V_31 ;
struct V_33 V_34 ;
struct V_6 * V_6 = V_4 -> V_6 ;
unsigned V_35 ;
int V_14 ;
if ( V_32 & V_36 ) {
V_14 = F_5 ( & V_6 -> V_16 ) ;
do {
V_35 = F_30 ( & V_4 -> V_37 ) ;
V_34 = V_4 -> V_38 ;
} while ( F_31 ( & V_4 -> V_37 , V_35 ) );
if ( F_32 ( & V_34 , V_6 ,
V_8 , 1 ,
false ) == - V_39 )
F_33 ( & V_4 -> V_5 ) ;
F_8 ( & V_6 -> V_16 , V_14 ) ;
}
if ( V_32 & V_40 ) {
unsigned long V_32 ;
F_34 ( & V_6 -> V_18 . V_41 , V_32 ) ;
if ( F_24 ( V_4 ) )
F_25 ( V_4 ) ;
F_35 ( & V_6 -> V_18 . V_41 , V_32 ) ;
}
return 0 ;
}
static void
F_36 ( struct V_42 * V_42 , T_3 * V_43 ,
T_4 * V_44 )
{
struct V_3 * V_4 =
F_2 ( V_44 , struct V_3 , V_44 ) ;
F_37 ( V_43 , & V_4 -> V_26 ) ;
}
static void F_38 ( struct V_6 * V_6 , struct V_3 * V_4 )
{
struct V_33 * V_45 ;
struct V_33 V_46 [ V_47 ] ;
int V_48 ;
V_48 = F_39 ( V_6 , V_46 , V_4 -> V_9 ) ;
F_40 ( & V_4 -> V_37 ) ;
V_45 = V_46 ;
if ( V_48 == 1 )
V_4 -> V_38 = * V_45 ;
else
V_4 -> V_38 . type = 0 ;
F_41 ( & V_4 -> V_37 ) ;
}
static int
F_42 ( struct V_6 * V_6 , struct V_49 * args )
{
struct V_3 * V_4 , * V_50 ;
struct V_51 V_52 ;
struct V_53 * V_25 = NULL , * V_17 = NULL ;
int V_54 ;
unsigned int V_55 ;
int V_14 ;
if ( ! F_43 ( V_6 ) )
return - V_56 ;
V_4 = F_44 ( sizeof( * V_4 ) , V_57 ) ;
if ( ! V_4 )
return - V_58 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_9 = args -> V_9 ;
F_45 ( & V_4 -> V_21 ) ;
F_46 ( & V_4 -> V_5 , F_1 ) ;
F_46 ( & V_4 -> V_23 , F_18 ) ;
F_47 ( & V_4 -> V_37 ) ;
V_52 = F_48 ( args -> V_51 ) ;
if ( ! V_52 . V_42 ) {
V_54 = - V_59 ;
goto V_60;
}
V_25 = F_49 ( V_52 . V_42 ) ;
if ( F_50 ( V_25 ) ) {
V_54 = F_51 ( V_25 ) ;
goto V_61;
}
V_4 -> V_25 = V_25 ;
if ( args -> V_32 & V_62 ) {
struct V_13 * V_7 ;
V_17 = F_52 ( args -> V_17 ) ;
if ( F_50 ( V_17 ) ) {
V_54 = F_51 ( V_17 ) ;
goto V_61;
}
V_4 -> V_17 = V_17 ;
F_45 ( & V_4 -> V_20 ) ;
F_10 ( & V_6 -> V_18 . V_19 ) ;
F_53 (resampler,
&kvm->irqfds.resampler_list, link) {
if ( V_7 -> V_15 . V_9 == V_4 -> V_9 ) {
V_4 -> V_7 = V_7 ;
break;
}
}
if ( ! V_4 -> V_7 ) {
V_7 = F_44 ( sizeof( * V_7 ) , V_57 ) ;
if ( ! V_7 ) {
V_54 = - V_58 ;
F_17 ( & V_6 -> V_18 . V_19 ) ;
goto V_61;
}
V_7 -> V_6 = V_6 ;
F_45 ( & V_7 -> V_21 ) ;
V_7 -> V_15 . V_9 = V_4 -> V_9 ;
V_7 -> V_15 . V_63 = F_4 ;
F_45 ( & V_7 -> V_22 ) ;
F_54 ( & V_7 -> V_22 , & V_6 -> V_18 . V_64 ) ;
F_55 ( V_6 ,
& V_7 -> V_15 ) ;
V_4 -> V_7 = V_7 ;
}
F_56 ( & V_4 -> V_20 , & V_4 -> V_7 -> V_21 ) ;
F_12 ( & V_6 -> V_16 ) ;
F_17 ( & V_6 -> V_18 . V_19 ) ;
}
F_57 ( & V_4 -> V_26 , F_29 ) ;
F_58 ( & V_4 -> V_44 , F_36 ) ;
F_59 ( & V_6 -> V_18 . V_41 ) ;
V_54 = 0 ;
F_53 (tmp, &kvm->irqfds.items, list) {
if ( V_4 -> V_25 != V_50 -> V_25 )
continue;
V_54 = - V_65 ;
F_60 ( & V_6 -> V_18 . V_41 ) ;
goto V_61;
}
V_14 = F_5 ( & V_6 -> V_16 ) ;
F_38 ( V_6 , V_4 ) ;
F_8 ( & V_6 -> V_16 , V_14 ) ;
F_61 ( & V_4 -> V_21 , & V_6 -> V_18 . V_66 ) ;
F_60 ( & V_6 -> V_18 . V_41 ) ;
V_55 = V_52 . V_42 -> V_67 -> V_68 ( V_52 . V_42 , & V_4 -> V_44 ) ;
if ( V_55 & V_36 )
F_33 ( & V_4 -> V_5 ) ;
F_62 ( V_52 ) ;
#ifdef F_22
if ( F_63 () ) {
V_4 -> V_27 . V_69 = ( void * ) V_4 -> V_25 ;
V_4 -> V_27 . V_70 = V_71 ;
V_4 -> V_27 . V_72 = V_73 ;
V_4 -> V_27 . V_74 = V_75 ;
V_4 -> V_27 . V_76 = V_77 ;
V_54 = F_64 ( & V_4 -> V_27 ) ;
if ( V_54 )
F_65 ( L_1 ,
V_4 -> V_27 . V_69 , V_54 ) ;
}
#endif
return 0 ;
V_61:
if ( V_4 -> V_7 )
F_9 ( V_4 ) ;
if ( V_17 && ! F_50 ( V_17 ) )
F_21 ( V_17 ) ;
if ( V_25 && ! F_50 ( V_25 ) )
F_21 ( V_25 ) ;
F_62 ( V_52 ) ;
V_60:
F_16 ( V_4 ) ;
return V_54 ;
}
bool F_66 ( struct V_6 * V_6 , unsigned V_78 , unsigned V_79 )
{
struct V_11 * V_12 ;
int V_9 , V_14 ;
V_14 = F_5 ( & V_6 -> V_16 ) ;
V_9 = F_67 ( V_6 , V_78 , V_79 ) ;
if ( V_9 != - 1 )
F_68 (kian, &kvm->irq_ack_notifier_list,
link)
if ( V_12 -> V_9 == V_9 ) {
F_8 ( & V_6 -> V_16 , V_14 ) ;
return true ;
}
F_8 ( & V_6 -> V_16 , V_14 ) ;
return false ;
}
void F_69 ( struct V_6 * V_6 , int V_9 )
{
struct V_11 * V_12 ;
F_68 (kian, &kvm->irq_ack_notifier_list,
link)
if ( V_12 -> V_9 == V_9 )
V_12 -> V_63 ( V_12 ) ;
}
void F_70 ( struct V_6 * V_6 , unsigned V_78 , unsigned V_79 )
{
int V_9 , V_14 ;
F_71 ( V_78 , V_79 ) ;
V_14 = F_5 ( & V_6 -> V_16 ) ;
V_9 = F_67 ( V_6 , V_78 , V_79 ) ;
if ( V_9 != - 1 )
F_69 ( V_6 , V_9 ) ;
F_8 ( & V_6 -> V_16 , V_14 ) ;
}
void F_55 ( struct V_6 * V_6 ,
struct V_11 * V_12 )
{
F_10 ( & V_6 -> V_80 ) ;
F_72 ( & V_12 -> V_22 , & V_6 -> V_81 ) ;
F_17 ( & V_6 -> V_80 ) ;
F_73 ( V_6 ) ;
}
void F_15 ( struct V_6 * V_6 ,
struct V_11 * V_12 )
{
F_10 ( & V_6 -> V_80 ) ;
F_74 ( & V_12 -> V_22 ) ;
F_17 ( & V_6 -> V_80 ) ;
F_12 ( & V_6 -> V_16 ) ;
F_73 ( V_6 ) ;
}
void
F_75 ( struct V_6 * V_6 )
{
#ifdef F_76
F_77 ( & V_6 -> V_18 . V_41 ) ;
F_45 ( & V_6 -> V_18 . V_66 ) ;
F_45 ( & V_6 -> V_18 . V_64 ) ;
F_78 ( & V_6 -> V_18 . V_19 ) ;
#endif
F_45 ( & V_6 -> V_82 ) ;
}
static int
F_79 ( struct V_6 * V_6 , struct V_49 * args )
{
struct V_3 * V_4 , * V_50 ;
struct V_53 * V_25 ;
V_25 = F_52 ( args -> V_51 ) ;
if ( F_50 ( V_25 ) )
return F_51 ( V_25 ) ;
F_59 ( & V_6 -> V_18 . V_41 ) ;
F_80 (irqfd, tmp, &kvm->irqfds.items, list) {
if ( V_4 -> V_25 == V_25 && V_4 -> V_9 == args -> V_9 ) {
F_40 ( & V_4 -> V_37 ) ;
V_4 -> V_38 . type = 0 ;
F_41 ( & V_4 -> V_37 ) ;
F_25 ( V_4 ) ;
}
}
F_60 ( & V_6 -> V_18 . V_41 ) ;
F_21 ( V_25 ) ;
F_81 ( V_28 ) ;
return 0 ;
}
int
V_49 ( struct V_6 * V_6 , struct V_49 * args )
{
if ( args -> V_32 & ~ ( V_83 | V_62 ) )
return - V_84 ;
if ( args -> V_32 & V_83 )
return F_79 ( V_6 , args ) ;
return F_42 ( V_6 , args ) ;
}
void
F_82 ( struct V_6 * V_6 )
{
struct V_3 * V_4 , * V_50 ;
F_59 ( & V_6 -> V_18 . V_41 ) ;
F_80 (irqfd, tmp, &kvm->irqfds.items, list)
F_25 ( V_4 ) ;
F_60 ( & V_6 -> V_18 . V_41 ) ;
F_81 ( V_28 ) ;
}
void F_83 ( struct V_6 * V_6 )
{
struct V_3 * V_4 ;
F_59 ( & V_6 -> V_18 . V_41 ) ;
F_53 (irqfd, &kvm->irqfds.items, list) {
F_38 ( V_6 , V_4 ) ;
#ifdef F_22
if ( V_4 -> V_85 ) {
int V_54 = F_84 (
V_4 -> V_6 , V_4 -> V_85 -> V_34 ,
V_4 -> V_9 , 1 ) ;
F_85 ( V_54 ) ;
}
#endif
}
F_60 ( & V_6 -> V_18 . V_41 ) ;
}
int F_86 ( void )
{
V_28 = F_87 ( L_2 , 0 , 0 ) ;
if ( ! V_28 )
return - V_58 ;
return 0 ;
}
void F_88 ( void )
{
F_89 ( V_28 ) ;
}
static inline struct V_86 *
F_90 ( struct V_87 * V_88 )
{
return F_2 ( V_88 , struct V_86 , V_88 ) ;
}
static void
F_91 ( struct V_86 * V_89 )
{
F_21 ( V_89 -> V_25 ) ;
F_14 ( & V_89 -> V_21 ) ;
F_16 ( V_89 ) ;
}
static bool
F_92 ( struct V_86 * V_89 , T_5 V_90 , int V_91 , const void * V_92 )
{
T_1 V_93 ;
if ( V_90 != V_89 -> V_90 )
return false ;
if ( ! V_89 -> V_94 )
return true ;
if ( V_91 != V_89 -> V_94 )
return false ;
if ( V_89 -> V_95 )
return true ;
F_26 ( ! F_93 ( ( unsigned long ) V_92 , V_91 ) ) ;
switch ( V_91 ) {
case 1 :
V_93 = * ( V_96 * ) V_92 ;
break;
case 2 :
V_93 = * ( V_97 * ) V_92 ;
break;
case 4 :
V_93 = * ( V_98 * ) V_92 ;
break;
case 8 :
V_93 = * ( T_1 * ) V_92 ;
break;
default:
return false ;
}
return V_93 == V_89 -> V_99 ? true : false ;
}
static int
F_94 ( struct V_100 * V_101 , struct V_87 * V_102 , T_5 V_90 ,
int V_91 , const void * V_92 )
{
struct V_86 * V_89 = F_90 ( V_102 ) ;
if ( ! F_92 ( V_89 , V_90 , V_91 , V_92 ) )
return - V_103 ;
F_7 ( V_89 -> V_25 , 1 ) ;
return 0 ;
}
static void
F_95 ( struct V_87 * V_102 )
{
struct V_86 * V_89 = F_90 ( V_102 ) ;
F_91 ( V_89 ) ;
}
static bool
F_96 ( struct V_6 * V_6 , struct V_86 * V_89 )
{
struct V_86 * V_104 ;
F_53 (_p, &kvm->ioeventfds, list)
if ( V_104 -> V_105 == V_89 -> V_105 &&
V_104 -> V_90 == V_89 -> V_90 &&
( ! V_104 -> V_94 || ! V_89 -> V_94 ||
( V_104 -> V_94 == V_89 -> V_94 &&
( V_104 -> V_95 || V_89 -> V_95 ||
V_104 -> V_99 == V_89 -> V_99 ) ) ) )
return true ;
return false ;
}
static enum V_106 F_97 ( T_6 V_32 )
{
if ( V_32 & V_107 )
return V_108 ;
if ( V_32 & V_109 )
return V_110 ;
return V_111 ;
}
static int F_98 ( struct V_6 * V_6 ,
enum V_106 V_105 ,
struct V_112 * args )
{
struct V_53 * V_25 ;
struct V_86 * V_89 ;
int V_54 ;
V_25 = F_52 ( args -> V_51 ) ;
if ( F_50 ( V_25 ) )
return F_51 ( V_25 ) ;
V_89 = F_44 ( sizeof( * V_89 ) , V_57 ) ;
if ( ! V_89 ) {
V_54 = - V_58 ;
goto V_61;
}
F_45 ( & V_89 -> V_21 ) ;
V_89 -> V_90 = args -> V_90 ;
V_89 -> V_105 = V_105 ;
V_89 -> V_94 = args -> V_91 ;
V_89 -> V_25 = V_25 ;
if ( args -> V_32 & V_113 )
V_89 -> V_99 = args -> V_99 ;
else
V_89 -> V_95 = true ;
F_10 ( & V_6 -> V_114 ) ;
if ( F_96 ( V_6 , V_89 ) ) {
V_54 = - V_115 ;
goto V_116;
}
F_99 ( & V_89 -> V_88 , & V_117 ) ;
V_54 = F_100 ( V_6 , V_105 , V_89 -> V_90 , V_89 -> V_94 ,
& V_89 -> V_88 ) ;
if ( V_54 < 0 )
goto V_116;
F_101 ( V_6 , V_105 ) -> V_118 ++ ;
F_61 ( & V_89 -> V_21 , & V_6 -> V_82 ) ;
F_17 ( & V_6 -> V_114 ) ;
return 0 ;
V_116:
F_17 ( & V_6 -> V_114 ) ;
V_61:
F_16 ( V_89 ) ;
F_21 ( V_25 ) ;
return V_54 ;
}
static int
F_102 ( struct V_6 * V_6 , enum V_106 V_105 ,
struct V_112 * args )
{
struct V_86 * V_89 , * V_50 ;
struct V_53 * V_25 ;
struct V_119 * V_120 ;
int V_54 = - V_121 ;
V_25 = F_52 ( args -> V_51 ) ;
if ( F_50 ( V_25 ) )
return F_51 ( V_25 ) ;
F_10 ( & V_6 -> V_114 ) ;
F_80 (p, tmp, &kvm->ioeventfds, list) {
bool V_95 = ! ( args -> V_32 & V_113 ) ;
if ( V_89 -> V_105 != V_105 ||
V_89 -> V_25 != V_25 ||
V_89 -> V_90 != args -> V_90 ||
V_89 -> V_94 != args -> V_91 ||
V_89 -> V_95 != V_95 )
continue;
if ( ! V_89 -> V_95 && V_89 -> V_99 != args -> V_99 )
continue;
F_103 ( V_6 , V_105 , & V_89 -> V_88 ) ;
V_120 = F_101 ( V_6 , V_105 ) ;
if ( V_120 )
V_120 -> V_118 -- ;
F_91 ( V_89 ) ;
V_54 = 0 ;
break;
}
F_17 ( & V_6 -> V_114 ) ;
F_21 ( V_25 ) ;
return V_54 ;
}
static int F_104 ( struct V_6 * V_6 , struct V_112 * args )
{
enum V_106 V_105 = F_97 ( args -> V_32 ) ;
int V_54 = F_102 ( V_6 , V_105 , args ) ;
if ( ! args -> V_91 && V_105 == V_111 )
F_102 ( V_6 , V_122 , args ) ;
return V_54 ;
}
static int
F_105 ( struct V_6 * V_6 , struct V_112 * args )
{
enum V_106 V_105 ;
int V_54 ;
V_105 = F_97 ( args -> V_32 ) ;
switch ( args -> V_91 ) {
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
return - V_84 ;
}
if ( args -> V_90 + args -> V_91 < args -> V_90 )
return - V_84 ;
if ( args -> V_32 & ~ V_123 )
return - V_84 ;
if ( ! args -> V_91 && ( args -> V_32 & V_113 ) )
return - V_84 ;
V_54 = F_98 ( V_6 , V_105 , args ) ;
if ( V_54 )
goto V_61;
if ( ! args -> V_91 && V_105 == V_111 ) {
V_54 = F_98 ( V_6 , V_122 , args ) ;
if ( V_54 < 0 )
goto V_124;
}
return 0 ;
V_124:
F_102 ( V_6 , V_105 , args ) ;
V_61:
return V_54 ;
}
int
V_112 ( struct V_6 * V_6 , struct V_112 * args )
{
if ( args -> V_32 & V_125 )
return F_104 ( V_6 , args ) ;
return F_105 ( V_6 , args ) ;
}
