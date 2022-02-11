static bool F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 & V_4 ) )
return false ;
if ( F_2 ( ! V_2 -> V_5 ) )
return false ;
F_3 ( V_2 -> V_5 , 0 ) ;
return true ;
}
static T_1 F_4 ( int V_6 , void * V_7 )
{
struct V_8 * V_9 = V_7 ;
V_9 -> V_10 . V_11 = 1 ;
F_5 () ;
if ( V_9 -> V_10 . V_12 )
F_6 ( V_9 ) ;
return V_13 ;
}
static int F_7 ( struct V_8 * V_9 , T_2 V_14 )
{
struct V_15 * V_16 = V_9 -> V_10 . V_17 ;
struct V_18 * V_19 = & V_16 -> V_20 [ V_14 ] ;
char * V_21 = NULL ;
int V_22 ;
if ( V_16 -> V_23 [ V_14 ] )
return 0 ;
V_16 -> V_23 [ V_14 ] = F_8 ( NULL , V_19 -> V_24 ) ;
if ( ! V_16 -> V_23 [ V_14 ] ) {
F_9 ( L_1 ,
V_14 , V_16 -> V_25 ) ;
return - V_26 ;
}
V_21 = F_10 ( V_27 , L_2 ,
V_9 -> V_28 -> V_10 . V_29 , V_16 -> V_25 , V_14 ) ;
if ( ! V_21 ) {
F_9 ( L_3 ,
V_14 , V_16 -> V_25 ) ;
V_22 = - V_30 ;
goto error;
}
V_22 = F_11 ( V_16 -> V_23 [ V_14 ] , F_4 ,
V_31 , V_21 , V_9 ) ;
if ( V_22 ) {
F_9 ( L_4 ,
V_14 , V_16 -> V_25 ) ;
goto error;
}
V_16 -> V_32 [ V_14 ] = V_21 ;
return 0 ;
error:
F_12 ( V_16 -> V_23 [ V_14 ] ) ;
V_16 -> V_23 [ V_14 ] = 0 ;
F_13 ( V_21 ) ;
return V_22 ;
}
static int F_14 ( struct V_8 * V_9 , T_2 V_14 )
{
struct V_15 * V_16 = V_9 -> V_10 . V_17 ;
struct V_33 * V_34 = V_16 -> V_34 ;
struct V_18 * V_19 = & V_16 -> V_20 [ V_14 ] ;
void * V_35 ;
int V_22 ;
if ( F_2 ( V_19 -> V_35 ) )
return 0 ;
V_35 = ( V_36 * ) F_15 ( V_27 , V_34 -> V_37 ) ;
if ( ! V_35 ) {
F_9 ( L_5 ,
V_14 , V_16 -> V_25 ) ;
return - V_30 ; ;
}
memset ( V_35 , 0 , 1 << V_34 -> V_38 ) ;
V_22 = F_16 ( V_16 -> V_39 , V_19 , V_14 , V_35 ,
V_34 -> V_38 , true ) ;
if ( V_22 )
F_9 ( L_6 ,
V_14 , V_16 -> V_25 ) ;
return V_22 ;
}
static int F_17 ( struct V_28 * V_28 , T_2 V_14 )
{
struct V_33 * V_34 = V_28 -> V_10 . V_34 ;
struct V_8 * V_9 ;
int V_40 , V_22 ;
F_18 ( & V_28 -> V_41 ) ;
if ( V_34 -> V_42 & ( 1 << V_14 ) )
return 0 ;
F_19 ( L_7 , V_14 ) ;
F_20 (i, vcpu, kvm) {
if ( ! V_9 -> V_10 . V_17 )
continue;
V_22 = F_14 ( V_9 , V_14 ) ;
if ( V_22 == 0 )
F_7 ( V_9 , V_14 ) ;
if ( V_22 )
return V_22 ;
}
F_21 () ;
V_34 -> V_42 |= ( 1 << V_14 ) ;
return 0 ;
}
static void F_22 ( struct V_28 * V_28 , T_3 V_43 , T_2 V_14 )
{
struct V_8 * V_9 ;
struct V_15 * V_16 ;
struct V_18 * V_19 ;
V_9 = F_23 ( V_28 , V_43 ) ;
if ( ! V_9 ) {
F_24 ( L_8 , V_44 , V_43 ) ;
return;
}
V_16 = V_9 -> V_10 . V_17 ;
if ( F_2 ( ! V_16 ) )
return;
V_19 = & V_16 -> V_20 [ V_14 ] ;
F_25 ( & V_19 -> V_45 ) ;
}
static int F_26 ( struct V_8 * V_9 , T_2 V_14 )
{
struct V_15 * V_16 = V_9 -> V_10 . V_17 ;
struct V_18 * V_19 ;
T_3 V_46 ;
if ( F_2 ( ! V_16 ) )
return - V_47 ;
if ( ! V_16 -> V_48 )
return - V_47 ;
V_19 = & V_16 -> V_20 [ V_14 ] ;
if ( F_2 ( ! V_19 -> V_35 ) )
return - V_47 ;
V_46 = ( V_19 -> V_49 + 1 ) - V_50 ;
return F_27 ( & V_19 -> V_51 , 1 , V_46 ) ? 0 : - V_52 ;
}
static int F_28 ( struct V_28 * V_28 , T_3 * V_43 , T_2 V_14 )
{
struct V_8 * V_9 ;
int V_40 , V_22 ;
V_9 = F_23 ( V_28 , * V_43 ) ;
if ( ! V_9 ) {
F_19 ( L_9 , * V_43 ) ;
return - V_53 ;
}
F_19 ( L_10 , * V_43 , V_14 ) ;
V_22 = F_26 ( V_9 , V_14 ) ;
if ( V_22 == 0 )
return V_22 ;
F_19 ( L_11 ) ;
F_20 (i, vcpu, kvm) {
if ( ! V_9 -> V_10 . V_17 )
continue;
V_22 = F_26 ( V_9 , V_14 ) ;
if ( V_22 == 0 ) {
* V_43 = V_9 -> V_10 . V_17 -> V_25 ;
F_19 ( L_12 , * V_43 , V_14 ) ;
return V_22 ;
}
}
F_19 ( L_13 ) ;
return - V_52 ;
}
static T_2 F_29 ( struct V_33 * V_34 ,
struct V_54 * V_55 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 ;
T_3 V_58 ;
T_2 V_59 ;
T_4 V_60 ;
for (; ; ) {
F_30 ( & V_55 -> V_41 ) ;
V_59 = V_57 -> V_61 ;
V_57 -> V_61 = V_62 ;
F_21 () ;
if ( ! V_57 -> V_63 )
break;
V_57 -> V_61 = V_59 ;
F_31 ( & V_55 -> V_41 ) ;
}
if ( V_59 == V_62 )
return V_59 ;
F_32 ( V_57 , & V_58 , & V_2 ) ;
if ( V_2 -> V_3 & V_64 ) {
F_33 ( V_58 ,
V_34 -> V_65 + V_57 -> V_66 ,
V_62 , V_57 -> V_67 ) ;
V_57 -> V_68 = true ;
V_57 -> V_69 = false ;
} else {
V_60 = F_34 ( V_2 , V_70 ) ;
V_57 -> V_68 = ! ! ( V_60 & 2 ) ;
V_57 -> V_69 = ! ! ( V_60 & 1 ) ;
F_35 ( V_58 ) ;
}
return V_59 ;
}
static void F_36 ( struct V_54 * V_55 ,
struct V_56 * V_57 )
{
for (; ; ) {
F_30 ( & V_55 -> V_41 ) ;
if ( ! V_57 -> V_63 )
break;
F_31 ( & V_55 -> V_41 ) ;
}
}
static void F_37 ( struct V_33 * V_34 ,
struct V_54 * V_55 ,
struct V_56 * V_57 ,
T_2 V_14 )
{
struct V_1 * V_2 ;
T_3 V_58 ;
if ( V_57 -> V_61 != V_62 )
goto V_71;
F_32 ( V_57 , & V_58 , & V_2 ) ;
if ( V_2 -> V_3 & V_64 ) {
F_33 ( V_58 ,
V_34 -> V_65 + V_57 -> V_66 ,
V_57 -> V_72 , V_57 -> V_67 ) ;
if ( ! V_57 -> V_68 )
F_38 ( V_58 , V_2 ) ;
if ( ! ( V_2 -> V_3 & V_73 ) )
F_1 ( V_2 ) ;
goto V_71;
}
if ( V_57 -> V_69 )
F_34 ( V_2 , V_74 ) ;
if ( ! V_57 -> V_68 )
F_38 ( V_58 , V_2 ) ;
F_21 () ;
V_71:
V_57 -> V_61 = V_14 ;
}
static int F_39 ( struct V_28 * V_28 ,
struct V_56 * V_57 ,
T_3 V_43 , T_2 V_14 )
{
struct V_33 * V_34 = V_28 -> V_10 . V_34 ;
T_3 V_58 ;
int V_22 ;
V_22 = F_28 ( V_28 , & V_43 , V_14 ) ;
if ( V_22 )
return V_22 ;
if ( V_57 -> V_72 != V_62 )
F_22 ( V_28 ,
V_57 -> V_66 ,
V_57 -> V_72 ) ;
V_57 -> V_72 = V_14 ;
V_57 -> V_66 = V_43 ;
F_32 ( V_57 , & V_58 , NULL ) ;
return F_33 ( V_58 ,
V_34 -> V_65 + V_43 ,
V_14 , V_57 -> V_67 ) ;
}
int F_40 ( struct V_28 * V_28 , T_3 V_6 , T_3 V_43 ,
T_3 V_75 )
{
struct V_33 * V_34 = V_28 -> V_10 . V_34 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_2 V_76 ;
int V_22 = 0 ;
T_5 V_77 ;
if ( ! V_34 )
return - V_78 ;
F_19 ( L_14 ,
V_6 , V_43 , V_75 ) ;
if ( V_75 != V_62 )
V_22 = F_17 ( V_34 -> V_28 ,
F_41 ( V_75 ) ) ;
if ( V_22 ) {
F_19 ( L_15 , V_22 ) ;
return V_22 ;
}
V_55 = F_42 ( V_34 , V_6 , & V_77 ) ;
if ( ! V_55 )
return - V_53 ;
V_57 = & V_55 -> V_79 [ V_77 ] ;
if ( V_75 == V_62 )
F_29 ( V_34 , V_55 , V_57 ) ;
else
F_36 ( V_55 , V_57 ) ;
V_76 = V_57 -> V_72 ;
if ( V_75 != V_62 )
V_76 = F_41 ( V_75 ) ;
F_19 ( L_16 ,
V_76 , V_57 -> V_66 , V_57 -> V_72 ) ;
if ( V_76 != V_62 &&
( V_57 -> V_66 != V_43 ||
V_57 -> V_72 != V_76 ) )
V_22 = F_39 ( V_28 , V_57 , V_43 , V_76 ) ;
if ( V_75 != V_62 )
F_37 ( V_34 , V_55 , V_57 , V_75 ) ;
V_57 -> V_80 = V_75 ;
F_31 ( & V_55 -> V_41 ) ;
return V_22 ;
}
int F_43 ( struct V_28 * V_28 , T_3 V_6 , T_3 * V_43 ,
T_3 * V_75 )
{
struct V_33 * V_34 = V_28 -> V_10 . V_34 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_5 V_77 ;
if ( ! V_34 )
return - V_78 ;
V_55 = F_42 ( V_34 , V_6 , & V_77 ) ;
if ( ! V_55 )
return - V_53 ;
V_57 = & V_55 -> V_79 [ V_77 ] ;
F_30 ( & V_55 -> V_41 ) ;
* V_43 = V_57 -> V_66 ;
* V_75 = V_57 -> V_61 ;
F_31 ( & V_55 -> V_41 ) ;
return 0 ;
}
int F_44 ( struct V_28 * V_28 , T_3 V_6 )
{
struct V_33 * V_34 = V_28 -> V_10 . V_34 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_5 V_77 ;
if ( ! V_34 )
return - V_78 ;
V_55 = F_42 ( V_34 , V_6 , & V_77 ) ;
if ( ! V_55 )
return - V_53 ;
V_57 = & V_55 -> V_79 [ V_77 ] ;
F_19 ( L_17 , V_6 ) ;
if ( V_57 -> V_72 == V_62 ) {
F_19 ( L_18 ) ;
return - V_53 ;
}
if ( V_57 -> V_80 == V_62 )
return 0 ;
F_36 ( V_55 , V_57 ) ;
F_37 ( V_34 , V_55 , V_57 , V_57 -> V_80 ) ;
F_31 ( & V_55 -> V_41 ) ;
return 0 ;
}
int F_45 ( struct V_28 * V_28 , T_3 V_6 )
{
struct V_33 * V_34 = V_28 -> V_10 . V_34 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_5 V_77 ;
if ( ! V_34 )
return - V_78 ;
V_55 = F_42 ( V_34 , V_6 , & V_77 ) ;
if ( ! V_55 )
return - V_53 ;
V_57 = & V_55 -> V_79 [ V_77 ] ;
F_19 ( L_19 , V_6 ) ;
V_57 -> V_80 = F_29 ( V_34 , V_55 , V_57 ) ;
F_31 ( & V_55 -> V_41 ) ;
return 0 ;
}
static bool F_46 ( struct V_33 * V_34 , T_3 V_6 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_5 V_77 ;
V_55 = F_42 ( V_34 , V_6 , & V_77 ) ;
if ( ! V_55 )
return false ;
V_57 = & V_55 -> V_79 [ V_77 ] ;
if ( ! V_57 -> V_48 )
return false ;
F_1 ( & V_57 -> V_81 ) ;
return true ;
}
T_4 F_47 ( struct V_8 * V_9 )
{
struct V_15 * V_16 = V_9 -> V_10 . V_17 ;
if ( ! V_16 )
return 0 ;
return ( T_4 ) V_16 -> V_82 << V_83 |
( T_4 ) V_16 -> V_84 << V_85 ;
}
int F_48 ( struct V_8 * V_9 , T_4 V_86 )
{
struct V_15 * V_16 = V_9 -> V_10 . V_17 ;
struct V_33 * V_34 = V_9 -> V_28 -> V_10 . V_34 ;
T_2 V_82 , V_84 ;
T_3 V_87 ;
if ( ! V_16 || ! V_34 )
return - V_88 ;
V_82 = V_86 >> V_83 ;
V_87 = ( V_86 >> V_89 ) &
V_90 ;
V_84 = V_86 >> V_85 ;
F_19 ( L_20 ,
V_16 -> V_25 , V_82 , V_84 , V_87 ) ;
if ( F_2 ( V_9 -> V_10 . V_91 ) )
return - V_26 ;
V_9 -> V_10 . V_92 . V_82 = V_82 ;
V_16 -> V_93 = V_16 -> V_82 = V_82 ;
V_16 -> V_84 = V_84 ;
if ( V_84 < V_82 )
F_1 ( & V_16 -> V_94 ) ;
if ( V_87 > V_95 && ! F_46 ( V_34 , V_87 ) ) {
V_16 -> V_96 = V_87 ;
V_34 -> V_97 ++ ;
F_19 ( L_21 ) ;
}
return 0 ;
}
int F_49 ( struct V_28 * V_28 , unsigned long V_98 ,
struct V_99 * V_100 )
{
struct V_33 * V_34 = V_28 -> V_10 . V_34 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
struct V_101 * V_102 = F_50 ( V_100 ) ;
unsigned int V_103 = F_51 ( V_100 ) ;
unsigned int V_104 = ( unsigned int ) F_52 ( V_102 ) ;
T_5 V_77 ;
T_2 V_14 ;
int V_22 ;
if ( ! V_34 )
return - V_78 ;
F_19 ( L_22 , V_98 , V_104 ) ;
V_55 = F_42 ( V_34 , V_98 , & V_77 ) ;
if ( ! V_55 )
return - V_53 ;
V_57 = & V_55 -> V_79 [ V_77 ] ;
V_22 = F_53 ( V_103 , V_57 ) ;
if ( V_22 ) {
F_9 ( L_23 , V_103 ) ;
return V_22 ;
}
V_14 = F_29 ( V_34 , V_55 , V_57 ) ;
F_19 ( L_24 , V_14 ,
V_57 -> V_68 , V_57 -> V_69 ) ;
F_34 ( & V_57 -> V_81 , V_105 ) ;
V_57 -> V_106 = V_104 ;
V_57 -> V_107 = F_54 ( V_102 ) ;
F_33 ( V_104 ,
V_34 -> V_65 + V_57 -> V_66 ,
V_57 -> V_72 , V_57 -> V_67 ) ;
if ( V_14 != V_62 && ! V_57 -> V_68 )
F_38 ( V_104 , V_57 -> V_107 ) ;
V_57 -> V_68 = V_57 -> V_69 = false ;
F_21 () ;
V_57 -> V_61 = V_14 ;
F_31 ( & V_55 -> V_41 ) ;
return 0 ;
}
int F_55 ( struct V_28 * V_28 , unsigned long V_98 ,
struct V_99 * V_100 )
{
struct V_33 * V_34 = V_28 -> V_10 . V_34 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
unsigned int V_103 = F_51 ( V_100 ) ;
T_5 V_77 ;
T_2 V_14 ;
int V_22 ;
if ( ! V_34 )
return - V_78 ;
F_19 ( L_25 , V_98 ) ;
V_55 = F_42 ( V_34 , V_98 , & V_77 ) ;
if ( ! V_55 )
return - V_53 ;
V_57 = & V_55 -> V_79 [ V_77 ] ;
V_14 = F_29 ( V_34 , V_55 , V_57 ) ;
F_19 ( L_26 , V_14 ,
V_57 -> V_68 , V_57 -> V_69 ) ;
if ( V_57 -> V_68 )
F_34 ( V_57 -> V_107 , V_74 ) ;
V_22 = F_53 ( V_103 , NULL ) ;
if ( V_22 ) {
F_9 ( L_27 , V_103 ) ;
return V_22 ;
}
V_57 -> V_106 = 0 ;
V_57 -> V_107 = NULL ;
F_33 ( V_57 -> V_108 ,
V_34 -> V_65 + V_57 -> V_66 ,
V_57 -> V_72 , V_57 -> V_67 ) ;
if ( V_14 == V_62 || V_57 -> V_68 )
F_34 ( & V_57 -> V_81 , V_70 ) ;
else
F_34 ( & V_57 -> V_81 , V_109 ) ;
F_21 () ;
V_57 -> V_61 = V_14 ;
F_31 ( & V_55 -> V_41 ) ;
return 0 ;
}
static void F_56 ( struct V_8 * V_9 )
{
struct V_15 * V_16 = V_9 -> V_10 . V_17 ;
struct V_28 * V_28 = V_9 -> V_28 ;
struct V_33 * V_34 = V_28 -> V_10 . V_34 ;
int V_40 , V_110 ;
for ( V_40 = 0 ; V_40 <= V_34 -> V_111 ; V_40 ++ ) {
struct V_54 * V_55 = V_34 -> V_112 [ V_40 ] ;
if ( ! V_55 )
continue;
for ( V_110 = 0 ; V_110 < V_113 ; V_110 ++ ) {
struct V_56 * V_57 = & V_55 -> V_79 [ V_110 ] ;
if ( ! V_57 -> V_48 )
continue;
if ( V_57 -> V_72 == V_62 )
continue;
if ( V_57 -> V_66 != V_16 -> V_25 )
continue;
F_30 ( & V_55 -> V_41 ) ;
V_57 -> V_72 = V_62 ;
F_34 ( & V_57 -> V_81 , V_105 ) ;
F_33 ( V_57 -> V_108 , 0 , V_62 , 0 ) ;
if ( V_57 -> V_106 ) {
F_34 ( V_57 -> V_107 , V_105 ) ;
F_33 ( V_57 -> V_106 , 0 , V_62 , 0 ) ;
}
F_31 ( & V_55 -> V_41 ) ;
}
}
}
void F_57 ( struct V_8 * V_9 )
{
struct V_15 * V_16 = V_9 -> V_10 . V_17 ;
struct V_33 * V_34 = V_16 -> V_34 ;
int V_40 ;
F_19 ( L_28 , V_16 -> V_25 ) ;
V_16 -> V_48 = false ;
F_56 ( V_9 ) ;
F_34 ( & V_16 -> V_94 , V_105 ) ;
F_58 ( V_16 -> V_39 ) ;
for ( V_40 = 0 ; V_40 < V_114 ; V_40 ++ ) {
struct V_18 * V_19 = & V_16 -> V_20 [ V_40 ] ;
if ( V_16 -> V_23 [ V_40 ] ) {
F_59 ( V_16 -> V_23 [ V_40 ] , V_9 ) ;
F_12 ( V_16 -> V_23 [ V_40 ] ) ;
F_13 ( V_16 -> V_32 [ V_40 ] ) ;
}
F_60 ( V_16 -> V_39 , V_19 , V_40 ) ;
if ( V_19 -> V_35 ) {
F_61 ( ( unsigned long ) V_19 -> V_35 ,
V_34 -> V_37 ) ;
V_19 -> V_35 = NULL ;
}
}
if ( V_16 -> V_115 ) {
F_62 ( & V_16 -> V_94 ) ;
F_63 ( V_16 -> V_115 ) ;
}
F_13 ( V_16 ) ;
}
int F_64 ( struct V_116 * V_117 ,
struct V_8 * V_9 , T_3 V_118 )
{
struct V_33 * V_34 = V_117 -> V_119 ;
struct V_15 * V_16 ;
int V_40 , V_120 = - V_52 ;
F_19 ( L_29 , V_118 ) ;
if ( V_117 -> V_121 != & V_122 ) {
F_19 ( L_30 ) ;
return - V_123 ;
}
if ( V_34 -> V_28 != V_9 -> V_28 )
return - V_123 ;
if ( V_9 -> V_10 . V_124 )
return - V_52 ;
if ( F_23 ( V_9 -> V_28 , V_118 ) ) {
F_19 ( L_31 ) ;
return - V_125 ;
}
if ( V_118 >= V_126 ) {
F_19 ( L_32 ) ;
return - V_53 ;
}
V_16 = F_65 ( sizeof( * V_16 ) , V_27 ) ;
if ( ! V_16 )
return - V_30 ;
F_66 ( & V_9 -> V_28 -> V_41 ) ;
V_9 -> V_10 . V_17 = V_16 ;
V_16 -> V_34 = V_34 ;
V_16 -> V_9 = V_9 ;
V_16 -> V_25 = V_118 ;
V_16 -> V_39 = V_34 -> V_65 + V_118 ;
V_16 -> V_84 = 0xff ;
V_16 -> V_48 = true ;
V_120 = F_67 ( V_16 -> V_39 , & V_16 -> V_127 , & V_16 -> V_128 ) ;
if ( V_120 )
goto V_71;
V_9 -> V_10 . V_92 . V_129 = F_68 ( 0xff000000 ) ;
V_9 -> V_10 . V_130 = F_69 ( V_16 -> V_127 | V_131 ) ;
V_16 -> V_115 = F_70 () ;
if ( ! V_16 -> V_115 ) {
V_120 = - V_26 ;
goto V_71;
}
F_19 ( L_33 , V_16 -> V_115 ) ;
V_120 = F_71 ( V_16 -> V_115 , & V_16 -> V_94 ) ;
if ( V_120 )
goto V_71;
for ( V_40 = 0 ; V_40 < V_114 ; V_40 ++ ) {
struct V_18 * V_19 = & V_16 -> V_20 [ V_40 ] ;
if ( V_34 -> V_42 & ( 1 << V_40 ) ) {
V_120 = F_14 ( V_9 , V_40 ) ;
if ( V_120 == 0 )
F_7 ( V_9 , V_40 ) ;
if ( V_120 )
goto V_71;
} else {
V_120 = F_16 ( V_16 -> V_39 ,
V_19 , V_40 , NULL , 0 , true ) ;
if ( V_120 ) {
F_9 ( L_6 ,
V_40 , V_118 ) ;
goto V_71;
}
}
}
V_120 = F_7 ( V_9 , 0 ) ;
if ( V_120 )
goto V_71;
V_120 = F_72 ( V_16 -> V_39 ) ;
if ( V_120 )
goto V_71;
V_120 = F_33 ( V_16 -> V_115 , V_16 -> V_39 , 0 , V_95 ) ;
if ( ! V_120 )
F_34 ( & V_16 -> V_94 , V_109 ) ;
V_71:
F_73 ( & V_9 -> V_28 -> V_41 ) ;
if ( V_120 ) {
F_57 ( V_9 ) ;
return V_120 ;
}
V_9 -> V_10 . V_124 = V_132 ;
return 0 ;
}
static void F_74 ( struct V_33 * V_34 , T_3 V_6 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_5 V_77 ;
V_55 = F_42 ( V_34 , V_6 , & V_77 ) ;
if ( ! V_55 )
return;
V_57 = & V_55 -> V_79 [ V_77 ] ;
if ( ! V_57 -> V_48 ) {
F_9 ( L_34 , V_6 ) ;
return;
}
if ( ! V_57 -> V_133 )
F_9 ( L_35 , V_6 ) ;
V_57 -> V_134 = true ;
}
static void F_75 ( struct V_33 * V_34 ,
struct V_54 * V_55 ,
T_3 V_6 )
{
struct V_56 * V_57 = & V_55 -> V_79 [ V_6 ] ;
if ( ! V_57 -> V_48 )
return;
V_57 -> V_135 = F_29 ( V_34 , V_55 , V_57 ) ;
V_57 -> V_133 = V_57 -> V_68 ;
V_57 -> V_136 = V_57 -> V_69 ;
F_31 ( & V_55 -> V_41 ) ;
}
static void F_76 ( struct V_33 * V_34 ,
struct V_54 * V_55 ,
T_3 V_6 )
{
struct V_56 * V_57 = & V_55 -> V_79 [ V_6 ] ;
if ( ! V_57 -> V_48 )
return;
F_36 ( V_55 , V_57 ) ;
if ( V_57 -> V_135 != V_62 )
F_37 ( V_34 , V_55 , V_57 , V_57 -> V_135 ) ;
F_31 ( & V_55 -> V_41 ) ;
}
static void F_77 ( struct V_33 * V_34 , struct V_18 * V_19 )
{
T_3 V_77 = V_19 -> V_77 ;
T_3 V_137 = V_19 -> V_137 ;
T_3 V_6 ;
do {
V_6 = F_78 ( V_19 -> V_35 , V_19 -> V_49 , & V_77 , & V_137 ) ;
if ( V_6 > V_95 )
F_74 ( V_34 , V_6 ) ;
} while( V_6 );
}
static void F_79 ( struct V_33 * V_34 )
{
struct V_8 * V_9 = NULL ;
int V_40 , V_110 ;
for ( V_40 = 0 ; V_40 <= V_34 -> V_111 ; V_40 ++ ) {
struct V_54 * V_55 = V_34 -> V_112 [ V_40 ] ;
if ( ! V_55 )
continue;
for ( V_110 = 0 ; V_110 < V_113 ; V_110 ++ )
F_75 ( V_34 , V_55 , V_110 ) ;
}
F_20 (i, vcpu, xive->kvm) {
struct V_15 * V_16 = V_9 -> V_10 . V_17 ;
if ( ! V_16 )
continue;
for ( V_110 = 0 ; V_110 < V_114 ; V_110 ++ ) {
if ( V_16 -> V_20 [ V_110 ] . V_35 )
F_77 ( V_34 , & V_16 -> V_20 [ V_110 ] ) ;
}
}
for ( V_40 = 0 ; V_40 <= V_34 -> V_111 ; V_40 ++ ) {
struct V_54 * V_55 = V_34 -> V_112 [ V_40 ] ;
if ( ! V_55 )
continue;
for ( V_110 = 0 ; V_110 < V_113 ; V_110 ++ )
F_76 ( V_34 , V_55 , V_110 ) ;
}
}
static void F_80 ( struct V_33 * V_34 )
{
T_3 V_40 , V_110 ;
for ( V_40 = 0 ; V_40 <= V_34 -> V_111 ; V_40 ++ ) {
struct V_54 * V_55 = V_34 -> V_112 [ V_40 ] ;
if ( ! V_55 )
continue;
for ( V_110 = 0 ; V_110 < V_113 ; V_110 ++ )
V_55 -> V_79 [ V_110 ] . V_134 = false ;
}
V_34 -> V_138 = 0 ;
}
static int F_81 ( struct V_33 * V_34 , long V_6 , T_4 V_139 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_4 T_6 * V_140 = ( T_4 T_6 * ) V_139 ;
T_4 V_60 , V_14 ;
T_5 V_77 ;
V_55 = F_42 ( V_34 , V_6 , & V_77 ) ;
if ( ! V_55 )
return - V_88 ;
V_57 = & V_55 -> V_79 [ V_77 ] ;
if ( ! V_57 -> V_48 )
return - V_88 ;
F_19 ( L_36 , V_6 ) ;
if ( V_34 -> V_138 == 0 )
F_79 ( V_34 ) ;
V_34 -> V_138 ++ ;
V_60 = V_57 -> V_66 ;
V_14 = V_57 -> V_135 ;
if ( V_14 == V_62 ) {
V_60 |= V_141 ;
V_14 = V_57 -> V_80 ;
}
V_60 |= V_14 << V_142 ;
if ( V_57 -> V_143 ) {
V_60 |= V_144 ;
if ( V_57 -> V_133 )
V_60 |= V_145 ;
} else {
if ( V_57 -> V_133 )
V_60 |= V_146 ;
if ( V_57 -> V_136 )
V_60 |= V_147 ;
if ( V_57 -> V_134 || ( V_14 == V_62 && V_57 -> V_136 ) )
V_60 |= V_145 ;
}
if ( V_34 -> V_138 == V_34 -> V_148 )
F_80 ( V_34 ) ;
if ( F_82 ( V_60 , V_140 ) )
return - V_149 ;
return 0 ;
}
static struct V_54 * F_83 ( struct V_33 * V_34 ,
int V_6 )
{
struct V_28 * V_28 = V_34 -> V_28 ;
struct V_54 * V_55 ;
int V_40 , V_150 ;
V_150 = V_6 >> V_151 ;
F_66 ( & V_28 -> V_41 ) ;
if ( V_34 -> V_112 [ V_150 ] )
goto V_152;
V_55 = F_65 ( sizeof( * V_55 ) , V_27 ) ;
if ( ! V_55 )
goto V_152;
V_55 -> V_153 = V_150 ;
for ( V_40 = 0 ; V_40 < V_113 ; V_40 ++ ) {
V_55 -> V_79 [ V_40 ] . V_67 = ( V_150 << V_151 ) | V_40 ;
V_55 -> V_79 [ V_40 ] . V_61 = V_62 ;
V_55 -> V_79 [ V_40 ] . V_80 = V_62 ;
V_55 -> V_79 [ V_40 ] . V_72 = V_62 ;
}
F_84 () ;
V_34 -> V_112 [ V_150 ] = V_55 ;
if ( V_150 > V_34 -> V_111 )
V_34 -> V_111 = V_150 ;
V_152:
F_73 ( & V_28 -> V_41 ) ;
return V_34 -> V_112 [ V_150 ] ;
}
static bool F_85 ( struct V_33 * V_34 , T_3 V_6 )
{
struct V_28 * V_28 = V_34 -> V_28 ;
struct V_8 * V_9 = NULL ;
int V_40 ;
F_20 (i, vcpu, kvm) {
struct V_15 * V_16 = V_9 -> V_10 . V_17 ;
if ( ! V_16 )
continue;
if ( V_16 -> V_96 == V_6 ) {
V_16 -> V_96 = 0 ;
V_34 -> V_97 -- ;
return true ;
}
}
return false ;
}
static int F_86 ( struct V_33 * V_34 , long V_6 , T_4 V_139 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_4 T_6 * V_140 = ( T_4 T_6 * ) V_139 ;
T_5 V_77 ;
T_4 V_60 ;
T_2 V_154 , V_155 ;
T_3 V_43 ;
int V_22 = 0 ;
if ( V_6 < V_156 || V_6 >= V_157 )
return - V_88 ;
F_19 ( L_37 , V_6 ) ;
V_55 = F_42 ( V_34 , V_6 , & V_77 ) ;
if ( ! V_55 ) {
F_19 ( L_38 ) ;
V_55 = F_83 ( V_34 , V_6 ) ;
if ( ! V_55 ) {
F_19 ( L_39 ) ;
return - V_30 ;
}
}
V_57 = & V_55 -> V_79 [ V_77 ] ;
if ( F_87 ( V_60 , V_140 ) ) {
F_19 ( L_40 ) ;
return - V_149 ;
}
V_43 = V_60 & V_158 ;
V_155 = V_60 >> V_142 ;
F_19 ( L_41 ,
V_60 , V_43 , V_155 ) ;
if ( ! V_57 -> V_108 ) {
V_57 -> V_108 = F_70 () ;
if ( V_57 -> V_108 == 0 ) {
F_19 ( L_42 ) ;
return - V_30 ;
}
F_71 ( V_57 -> V_108 , & V_57 -> V_81 ) ;
F_19 ( L_43 , V_57 -> V_108 ) ;
}
V_57 -> V_61 = 0 ;
F_29 ( V_34 , V_55 , V_57 ) ;
V_154 = F_41 ( V_155 ) ;
V_57 -> V_72 = V_62 ;
F_31 ( & V_55 -> V_41 ) ;
if ( V_154 != V_62 ) {
F_66 ( & V_34 -> V_28 -> V_41 ) ;
V_22 = F_17 ( V_34 -> V_28 , V_154 ) ;
F_73 ( & V_34 -> V_28 -> V_41 ) ;
if ( V_22 == 0 )
V_22 = F_39 ( V_34 -> V_28 , V_57 ,
V_43 , V_154 ) ;
}
if ( V_34 -> V_97 && F_85 ( V_34 , V_6 ) ) {
V_60 |= V_145 ;
F_19 ( L_44 ) ;
}
V_57 -> V_68 = false ;
V_57 -> V_69 = false ;
V_57 -> V_143 = false ;
V_57 -> V_159 = false ;
if ( V_60 & V_144 ) {
V_57 -> V_143 = true ;
if ( V_60 & V_145 )
V_57 -> V_159 = true ;
F_19 ( L_45 , V_57 -> V_159 ) ;
}
if ( V_60 & V_146 || V_60 & V_145 )
V_57 -> V_68 = true ;
if ( V_60 & V_147 || V_60 & V_145 )
V_57 -> V_69 = true ;
F_19 ( L_46 , V_57 -> V_68 , V_57 -> V_69 ) ;
if ( V_60 & V_141 ) {
F_19 ( L_47 ) ;
V_57 -> V_61 = V_62 ;
V_57 -> V_80 = V_155 ;
} else {
F_19 ( L_48 , V_155 ) ;
F_37 ( V_34 , V_55 , V_57 , V_155 ) ;
V_57 -> V_80 = V_155 ;
}
if ( ! V_57 -> V_48 )
V_34 -> V_148 ++ ;
V_57 -> V_48 = true ;
return 0 ;
}
int F_88 ( struct V_28 * V_28 , int V_160 , T_3 V_6 , int V_161 ,
bool V_162 )
{
struct V_33 * V_34 = V_28 -> V_10 . V_34 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_5 V_77 ;
if ( ! V_34 )
return - V_78 ;
V_55 = F_42 ( V_34 , V_6 , & V_77 ) ;
if ( ! V_55 )
return - V_53 ;
V_57 = & V_55 -> V_79 [ V_77 ] ;
if ( ! V_57 -> V_48 )
return - V_53 ;
if ( V_57 -> V_106 )
return - V_53 ;
if ( ( V_161 == 1 && V_57 -> V_143 ) || V_161 == V_163 )
V_57 -> V_159 = 1 ;
else if ( V_161 == 0 || V_161 == V_164 ) {
V_57 -> V_159 = 0 ;
return 0 ;
}
F_1 ( & V_57 -> V_81 ) ;
return 0 ;
}
static int F_89 ( struct V_116 * V_117 , struct V_165 * V_166 )
{
struct V_33 * V_34 = V_117 -> V_119 ;
switch ( V_166 -> V_167 ) {
case V_168 :
return F_86 ( V_34 , V_166 -> V_166 , V_166 -> V_139 ) ;
}
return - V_47 ;
}
static int F_90 ( struct V_116 * V_117 , struct V_165 * V_166 )
{
struct V_33 * V_34 = V_117 -> V_119 ;
switch ( V_166 -> V_167 ) {
case V_168 :
return F_81 ( V_34 , V_166 -> V_166 , V_166 -> V_139 ) ;
}
return - V_47 ;
}
static int F_91 ( struct V_116 * V_117 , struct V_165 * V_166 )
{
switch ( V_166 -> V_167 ) {
case V_168 :
if ( V_166 -> V_166 >= V_156 &&
V_166 -> V_166 < V_157 )
return 0 ;
break;
}
return - V_47 ;
}
static void F_92 ( T_3 V_58 , struct V_1 * V_2 )
{
F_34 ( V_2 , V_105 ) ;
F_33 ( V_58 , 0 , V_62 , 0 ) ;
F_62 ( V_2 ) ;
}
static void F_93 ( struct V_54 * V_55 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_113 ; V_40 ++ ) {
struct V_56 * V_57 = & V_55 -> V_79 [ V_40 ] ;
if ( ! V_57 -> V_48 )
continue;
F_92 ( V_57 -> V_108 , & V_57 -> V_81 ) ;
F_63 ( V_57 -> V_108 ) ;
if ( V_57 -> V_106 )
F_92 ( V_57 -> V_106 , V_57 -> V_107 ) ;
V_57 -> V_48 = false ;
}
}
static void F_94 ( struct V_116 * V_117 )
{
struct V_33 * V_34 = V_117 -> V_119 ;
struct V_28 * V_28 = V_34 -> V_28 ;
int V_40 ;
F_95 ( V_34 -> V_169 ) ;
if ( V_28 )
V_28 -> V_10 . V_34 = NULL ;
for ( V_40 = 0 ; V_40 <= V_34 -> V_111 ; V_40 ++ ) {
if ( V_34 -> V_112 [ V_40 ] )
F_93 ( V_34 -> V_112 [ V_40 ] ) ;
F_13 ( V_34 -> V_112 [ V_40 ] ) ;
V_34 -> V_112 [ V_40 ] = NULL ;
}
if ( V_34 -> V_65 != V_170 )
F_96 ( V_34 -> V_65 ) ;
F_13 ( V_34 ) ;
F_13 ( V_117 ) ;
}
static int F_97 ( struct V_116 * V_117 , T_3 type )
{
struct V_33 * V_34 ;
struct V_28 * V_28 = V_117 -> V_28 ;
int V_171 = 0 ;
F_19 ( L_49 ) ;
V_34 = F_65 ( sizeof( * V_34 ) , V_27 ) ;
if ( ! V_34 )
return - V_30 ;
V_117 -> V_119 = V_34 ;
V_34 -> V_117 = V_117 ;
V_34 -> V_28 = V_28 ;
if ( V_28 -> V_10 . V_34 )
V_171 = - V_125 ;
else
V_28 -> V_10 . V_34 = V_34 ;
V_34 -> V_38 = F_98 () ;
if ( V_34 -> V_38 < V_172 )
V_34 -> V_37 = 0 ;
else
V_34 -> V_37 = V_34 -> V_38 - V_172 ;
V_34 -> V_65 = F_99 ( V_126 ) ;
F_19 ( L_50 , V_34 -> V_65 ) ;
if ( V_34 -> V_65 == V_170 )
V_171 = - V_30 ;
if ( V_171 ) {
F_13 ( V_34 ) ;
return V_171 ;
}
return 0 ;
}
static int F_100 ( struct V_173 * V_174 , void * V_119 )
{
struct V_33 * V_34 = V_174 -> V_119 ;
struct V_28 * V_28 = V_34 -> V_28 ;
struct V_8 * V_9 ;
T_4 V_175 = 0 ;
T_4 V_176 = 0 ;
T_4 V_177 = 0 ;
T_4 V_178 = 0 ;
T_4 V_179 = 0 ;
T_4 V_180 = 0 ;
T_4 V_181 = 0 ;
T_4 V_182 = 0 ;
T_4 V_183 = 0 ;
T_4 V_184 = 0 ;
unsigned int V_40 ;
if ( ! V_28 )
return 0 ;
F_101 ( V_174 , L_51 ) ;
F_20 (i, vcpu, kvm) {
struct V_15 * V_16 = V_9 -> V_10 . V_17 ;
if ( ! V_16 )
continue;
F_101 ( V_174 , L_52
L_53 ,
V_16 -> V_25 , V_16 -> V_82 , V_16 -> V_93 ,
V_16 -> V_84 , V_16 -> V_185 ,
V_16 -> V_186 , V_16 -> V_187 ) ;
V_175 += V_16 -> V_186 ;
V_176 += V_16 -> V_188 ;
V_177 += V_16 -> V_189 ;
V_178 += V_16 -> V_190 ;
V_179 += V_16 -> V_191 ;
V_180 += V_16 -> V_187 ;
V_181 += V_16 -> V_192 ;
V_182 += V_16 -> V_193 ;
V_183 += V_16 -> V_194 ;
V_184 += V_16 -> V_195 ;
}
F_101 ( V_174 , L_54 ) ;
F_101 ( V_174 , L_55 , V_175 , V_180 ) ;
F_101 ( V_174 , L_56 , V_176 , V_181 ) ;
F_101 ( V_174 , L_57 , V_177 , V_182 ) ;
F_101 ( V_174 , L_58 , V_178 , V_183 ) ;
F_101 ( V_174 , L_59 , V_179 , V_184 ) ;
return 0 ;
}
static int F_102 ( struct V_196 * V_196 , struct V_197 * V_197 )
{
return F_103 ( V_197 , F_100 , V_196 -> V_198 ) ;
}
static void F_104 ( struct V_33 * V_34 )
{
char * V_21 ;
V_21 = F_10 ( V_27 , L_60 , V_34 ) ;
if ( ! V_21 ) {
F_9 ( L_61 , V_44 ) ;
return;
}
V_34 -> V_169 = F_105 ( V_21 , V_199 , V_200 ,
V_34 , & V_201 ) ;
F_106 ( L_62 , V_44 , V_21 ) ;
F_13 ( V_21 ) ;
}
static void F_107 ( struct V_116 * V_117 )
{
struct V_33 * V_34 = (struct V_33 * ) V_117 -> V_119 ;
F_104 ( V_34 ) ;
}
void F_108 ( void )
{
V_202 = V_203 ;
V_204 = V_205 ;
V_206 = V_207 ;
V_208 = V_209 ;
V_210 = V_211 ;
}
void F_109 ( void )
{
V_202 = NULL ;
V_204 = NULL ;
V_206 = NULL ;
V_208 = NULL ;
V_210 = NULL ;
}
