static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
if ( ! F_2 ( V_2 ) )
return - V_5 ;
V_4 = V_2 -> V_6 ;
F_3 ( V_4 -> V_7 ) ;
F_3 ( V_4 -> V_8 . V_9 || V_4 -> V_10 . V_9 ) ;
V_4 -> V_11 -> V_12 ( V_4 ) ;
F_4 ( & V_13 . V_14 ) ;
F_5 ( & V_4 -> V_15 ) ;
F_6 ( & V_13 . V_14 ) ;
if ( V_4 -> V_16 == (struct V_17 * ) & V_4 [ 1 ] )
F_7 ( V_4 -> V_16 ) ;
F_8 ( V_4 -> V_18 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_2 , struct V_19 * V_20 )
{
struct V_3 * V_4 ;
if ( ! F_2 ( V_2 ) )
return - V_5 ;
V_4 = V_2 -> V_6 ;
if ( V_20 -> V_21 + ( ( V_20 -> V_22 - V_20 -> V_23 ) >> V_24 ) >
V_4 -> V_25 >> V_24 )
return - V_5 ;
return V_4 -> V_11 -> V_26 ( V_4 , V_20 ) ;
}
static T_1 F_11 ( struct V_2 * V_2 , T_1 V_27 , int V_28 )
{
struct V_3 * V_4 ;
T_1 V_29 ;
if ( ! F_2 ( V_2 ) )
return - V_30 ;
V_4 = V_2 -> V_6 ;
if ( V_28 == V_31 )
V_29 = V_4 -> V_25 ;
else if ( V_28 == V_32 )
V_29 = 0 ;
else
return - V_5 ;
if ( V_27 != 0 )
return - V_5 ;
return V_29 + V_27 ;
}
static void F_12 ( struct V_33 * V_33 , struct V_34 * V_35 )
{
struct V_36 * V_37 = (struct V_36 * ) V_35 ;
unsigned long V_38 ;
F_13 ( & V_37 -> V_39 -> V_14 , V_38 ) ;
F_14 ( V_37 -> V_39 , V_37 -> V_9 ) ;
V_37 -> V_9 = 0 ;
F_15 ( & V_37 -> V_39 -> V_14 , V_38 ) ;
}
static unsigned int F_16 ( struct V_2 * V_2 , T_2 * V_39 )
{
struct V_3 * V_4 ;
struct V_17 * V_16 ;
struct V_40 * V_41 ;
struct V_33 * V_42 ;
unsigned long V_43 ;
unsigned V_44 , V_45 ;
V_4 = V_2 -> V_6 ;
if ( ! V_4 || ! V_4 -> V_16 )
return V_46 ;
V_16 = V_4 -> V_16 ;
F_17 ( V_2 , & V_4 -> V_39 , V_39 ) ;
V_43 = F_18 ( V_39 ) & ( V_47 | V_48 ) ;
if ( ! V_43 )
return 0 ;
V_49:
V_45 = F_19 ( & V_16 -> V_45 ) ;
F_20 () ;
V_41 = F_21 ( V_16 -> V_33 ) ;
if ( V_41 )
V_44 = V_41 -> V_44 ;
else
V_44 = 0 ;
V_42 = F_21 ( V_16 -> V_42 ) ;
if ( F_22 ( & V_16 -> V_45 , V_45 ) ) {
F_23 () ;
goto V_49;
}
if ( V_42 && ( ! ( V_43 & V_48 ) || V_44 == 0 ) ) {
struct V_36 * V_37 = & V_4 -> V_10 ;
unsigned long V_50 = V_47 ;
if ( V_44 == 0 )
V_50 |= V_48 ;
F_24 ( & V_4 -> V_39 . V_14 ) ;
if ( V_37 -> V_9 ) {
V_37 -> V_9 |= V_50 ;
V_43 &= ~ V_50 ;
} else
V_37 -> V_9 = V_50 ;
F_25 ( & V_4 -> V_39 . V_14 ) ;
if ( V_43 & V_50 ) {
if ( ! F_26 ( V_42 ) ) {
V_43 &= ~ V_50 ;
F_12 ( NULL , & V_37 -> V_35 ) ;
} else if ( ! F_27 ( V_42 , & V_37 -> V_35 ,
F_12 ) ) {
V_43 &= ~ V_50 ;
F_28 ( V_42 ) ;
} else {
F_28 ( V_42 ) ;
F_12 ( NULL , & V_37 -> V_35 ) ;
}
}
}
if ( ( V_43 & V_48 ) && V_44 > 0 ) {
struct V_36 * V_37 = & V_4 -> V_8 ;
int V_51 ;
F_24 ( & V_4 -> V_39 . V_14 ) ;
if ( V_37 -> V_9 )
V_43 &= ~ V_48 ;
else
V_37 -> V_9 = V_48 ;
F_25 ( & V_4 -> V_39 . V_14 ) ;
if ( ! ( V_43 & V_48 ) )
goto V_52;
for ( V_51 = 0 ; V_51 < V_44 ; ++ V_51 ) {
struct V_33 * V_33 = F_21 ( V_41 -> V_53 [ V_51 ] ) ;
if ( ! F_26 ( V_33 ) ) {
V_43 &= ~ V_48 ;
F_12 ( NULL , & V_37 -> V_35 ) ;
break;
}
if ( ! F_27 ( V_33 , & V_37 -> V_35 ,
F_12 ) ) {
F_28 ( V_33 ) ;
V_43 &= ~ V_48 ;
break;
}
F_28 ( V_33 ) ;
}
if ( V_51 == V_44 )
F_12 ( NULL , & V_37 -> V_35 ) ;
}
V_52:
F_23 () ;
return V_43 ;
}
static long F_29 ( struct V_2 * V_2 ,
unsigned int V_54 , unsigned long V_55 )
{
struct V_3 * V_4 ;
struct V_56 V_57 ;
enum V_58 V_59 ;
int V_60 ;
V_4 = V_2 -> V_6 ;
switch ( V_54 ) {
case V_61 :
if ( F_30 ( & V_57 , ( void V_62 * ) V_55 , sizeof( V_57 ) ) )
return - V_63 ;
if ( V_57 . V_38 & ~ V_64 )
return - V_5 ;
switch ( V_57 . V_38 & V_65 ) {
case V_66 :
V_59 = V_67 ;
break;
case V_68 :
V_59 = V_69 ;
break;
case V_65 :
V_59 = V_70 ;
break;
default:
return - V_5 ;
}
if ( V_57 . V_38 & V_71 )
V_60 = F_31 ( V_4 , V_59 ) ;
else
V_60 = F_32 ( V_4 , V_59 ) ;
return V_60 ;
default:
return - V_72 ;
}
}
static inline int F_2 ( struct V_2 * V_2 )
{
return V_2 -> V_73 == & V_74 ;
}
struct V_3 * F_33 ( const struct V_75 * V_76 )
{
struct V_3 * V_4 ;
struct V_17 * V_16 = V_76 -> V_16 ;
struct V_2 * V_2 ;
T_3 V_77 = sizeof( struct V_3 ) ;
if ( ! V_76 -> V_16 )
V_77 += sizeof( struct V_17 ) ;
else
V_77 += 1 ;
if ( F_34 ( ! V_76 -> V_78
|| ! V_76 -> V_11
|| ! V_76 -> V_11 -> V_79
|| ! V_76 -> V_11 -> V_80
|| ! V_76 -> V_11 -> V_12
|| ! V_76 -> V_11 -> V_81
|| ! V_76 -> V_11 -> V_82
|| ! V_76 -> V_11 -> V_26 ) ) {
return F_35 ( - V_5 ) ;
}
if ( ! F_36 ( V_76 -> V_18 ) )
return F_35 ( - V_83 ) ;
V_4 = F_37 ( V_77 , V_84 ) ;
if ( ! V_4 ) {
F_8 ( V_76 -> V_18 ) ;
return F_35 ( - V_85 ) ;
}
V_4 -> V_78 = V_76 -> V_78 ;
V_4 -> V_11 = V_76 -> V_11 ;
V_4 -> V_25 = V_76 -> V_25 ;
V_4 -> V_86 = V_76 -> V_86 ;
V_4 -> V_18 = V_76 -> V_18 ;
F_38 ( & V_4 -> V_39 ) ;
V_4 -> V_10 . V_39 = V_4 -> V_8 . V_39 = & V_4 -> V_39 ;
V_4 -> V_10 . V_9 = V_4 -> V_8 . V_9 = 0 ;
if ( ! V_16 ) {
V_16 = (struct V_17 * ) & V_4 [ 1 ] ;
F_39 ( V_16 ) ;
}
V_4 -> V_16 = V_16 ;
V_2 = F_40 ( L_1 , & V_74 , V_4 ,
V_76 -> V_38 ) ;
if ( F_41 ( V_2 ) ) {
F_9 ( V_4 ) ;
return F_42 ( V_2 ) ;
}
V_2 -> V_87 |= V_88 ;
V_4 -> V_2 = V_2 ;
F_43 ( & V_4 -> V_14 ) ;
F_44 ( & V_4 -> V_89 ) ;
F_4 ( & V_13 . V_14 ) ;
F_45 ( & V_4 -> V_15 , & V_13 . V_90 ) ;
F_6 ( & V_13 . V_14 ) ;
return V_4 ;
}
int F_46 ( struct V_3 * V_4 , int V_38 )
{
int V_91 ;
if ( ! V_4 || ! V_4 -> V_2 )
return - V_5 ;
V_91 = F_47 ( V_38 ) ;
if ( V_91 < 0 )
return V_91 ;
F_48 ( V_91 , V_4 -> V_2 ) ;
return V_91 ;
}
struct V_3 * F_49 ( int V_91 )
{
struct V_2 * V_2 ;
V_2 = F_50 ( V_91 ) ;
if ( ! V_2 )
return F_35 ( - V_30 ) ;
if ( ! F_2 ( V_2 ) ) {
F_51 ( V_2 ) ;
return F_35 ( - V_5 ) ;
}
return V_2 -> V_6 ;
}
void F_52 ( struct V_3 * V_4 )
{
if ( F_34 ( ! V_4 || ! V_4 -> V_2 ) )
return;
F_51 ( V_4 -> V_2 ) ;
}
struct V_92 * F_53 ( struct V_3 * V_4 ,
struct V_93 * V_94 )
{
struct V_92 * V_95 ;
int V_60 ;
if ( F_34 ( ! V_4 || ! V_94 ) )
return F_35 ( - V_5 ) ;
V_95 = F_37 ( sizeof( struct V_92 ) , V_84 ) ;
if ( V_95 == NULL )
return F_35 ( - V_85 ) ;
V_95 -> V_94 = V_94 ;
V_95 -> V_4 = V_4 ;
F_4 ( & V_4 -> V_14 ) ;
if ( V_4 -> V_11 -> V_95 ) {
V_60 = V_4 -> V_11 -> V_95 ( V_4 , V_94 , V_95 ) ;
if ( V_60 )
goto V_96;
}
F_45 ( & V_95 -> V_97 , & V_4 -> V_89 ) ;
F_6 ( & V_4 -> V_14 ) ;
return V_95 ;
V_96:
F_9 ( V_95 ) ;
F_6 ( & V_4 -> V_14 ) ;
return F_35 ( V_60 ) ;
}
void F_54 ( struct V_3 * V_4 , struct V_92 * V_95 )
{
if ( F_34 ( ! V_4 || ! V_95 ) )
return;
F_4 ( & V_4 -> V_14 ) ;
F_5 ( & V_95 -> V_97 ) ;
if ( V_4 -> V_11 -> V_98 )
V_4 -> V_11 -> V_98 ( V_4 , V_95 ) ;
F_6 ( & V_4 -> V_14 ) ;
F_9 ( V_95 ) ;
}
struct V_99 * F_55 ( struct V_92 * V_95 ,
enum V_58 V_59 )
{
struct V_99 * V_99 = F_35 ( - V_5 ) ;
F_56 () ;
if ( F_34 ( ! V_95 || ! V_95 -> V_4 ) )
return F_35 ( - V_5 ) ;
V_99 = V_95 -> V_4 -> V_11 -> V_79 ( V_95 , V_59 ) ;
if ( ! V_99 )
V_99 = F_35 ( - V_85 ) ;
return V_99 ;
}
void F_57 ( struct V_92 * V_95 ,
struct V_99 * V_99 ,
enum V_58 V_59 )
{
F_56 () ;
if ( F_34 ( ! V_95 || ! V_95 -> V_4 || ! V_99 ) )
return;
V_95 -> V_4 -> V_11 -> V_80 ( V_95 , V_99 ,
V_59 ) ;
}
int F_32 ( struct V_3 * V_4 ,
enum V_58 V_59 )
{
int V_60 = 0 ;
if ( F_34 ( ! V_4 ) )
return - V_5 ;
if ( V_4 -> V_11 -> V_100 )
V_60 = V_4 -> V_11 -> V_100 ( V_4 , V_59 ) ;
return V_60 ;
}
int F_31 ( struct V_3 * V_4 ,
enum V_58 V_59 )
{
int V_60 = 0 ;
F_34 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_101 )
V_60 = V_4 -> V_11 -> V_101 ( V_4 , V_59 ) ;
return V_60 ;
}
void * F_58 ( struct V_3 * V_4 , unsigned long V_102 )
{
F_34 ( ! V_4 ) ;
return V_4 -> V_11 -> V_81 ( V_4 , V_102 ) ;
}
void F_59 ( struct V_3 * V_4 , unsigned long V_102 ,
void * V_103 )
{
F_34 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_104 )
V_4 -> V_11 -> V_104 ( V_4 , V_102 , V_103 ) ;
}
void * F_60 ( struct V_3 * V_4 , unsigned long V_102 )
{
F_34 ( ! V_4 ) ;
return V_4 -> V_11 -> V_82 ( V_4 , V_102 ) ;
}
void F_61 ( struct V_3 * V_4 , unsigned long V_102 ,
void * V_103 )
{
F_34 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_105 )
V_4 -> V_11 -> V_105 ( V_4 , V_102 , V_103 ) ;
}
int F_62 ( struct V_3 * V_4 , struct V_19 * V_20 ,
unsigned long V_106 )
{
struct V_2 * V_107 ;
int V_60 ;
if ( F_34 ( ! V_4 || ! V_20 ) )
return - V_5 ;
if ( V_106 + ( ( V_20 -> V_22 - V_20 -> V_23 ) >> V_24 ) < V_106 )
return - V_108 ;
if ( V_106 + ( ( V_20 -> V_22 - V_20 -> V_23 ) >> V_24 ) >
V_4 -> V_25 >> V_24 )
return - V_5 ;
F_63 ( V_4 -> V_2 ) ;
V_107 = V_20 -> V_109 ;
V_20 -> V_109 = V_4 -> V_2 ;
V_20 -> V_21 = V_106 ;
V_60 = V_4 -> V_11 -> V_26 ( V_4 , V_20 ) ;
if ( V_60 ) {
V_20 -> V_109 = V_107 ;
F_51 ( V_4 -> V_2 ) ;
} else {
if ( V_107 )
F_51 ( V_107 ) ;
}
return V_60 ;
}
void * F_64 ( struct V_3 * V_4 )
{
void * V_110 ;
if ( F_34 ( ! V_4 ) )
return NULL ;
if ( ! V_4 -> V_11 -> V_111 )
return NULL ;
F_4 ( & V_4 -> V_14 ) ;
if ( V_4 -> V_7 ) {
V_4 -> V_7 ++ ;
F_3 ( ! V_4 -> V_112 ) ;
V_110 = V_4 -> V_112 ;
goto V_113;
}
F_3 ( V_4 -> V_112 ) ;
V_110 = V_4 -> V_11 -> V_111 ( V_4 ) ;
if ( F_65 ( F_41 ( V_110 ) ) )
V_110 = NULL ;
if ( ! V_110 )
goto V_113;
V_4 -> V_112 = V_110 ;
V_4 -> V_7 = 1 ;
V_113:
F_6 ( & V_4 -> V_14 ) ;
return V_110 ;
}
void F_66 ( struct V_3 * V_4 , void * V_103 )
{
if ( F_34 ( ! V_4 ) )
return;
F_3 ( ! V_4 -> V_112 ) ;
F_3 ( V_4 -> V_7 == 0 ) ;
F_3 ( V_4 -> V_112 != V_103 ) ;
F_4 ( & V_4 -> V_14 ) ;
if ( -- V_4 -> V_7 == 0 ) {
if ( V_4 -> V_11 -> V_114 )
V_4 -> V_11 -> V_114 ( V_4 , V_103 ) ;
V_4 -> V_112 = NULL ;
}
F_6 ( & V_4 -> V_14 ) ;
}
static int F_67 ( struct V_115 * V_116 )
{
int V_60 ;
struct V_3 * V_117 ;
struct V_92 * V_118 ;
int V_119 = 0 , V_120 ;
T_3 V_25 = 0 ;
V_60 = F_68 ( & V_13 . V_14 ) ;
if ( V_60 )
return V_60 ;
F_69 ( V_116 , L_2 ) ;
F_69 ( V_116 , L_3 ) ;
F_70 (buf_obj, &db_list.head, list_node) {
V_60 = F_68 ( & V_117 -> V_14 ) ;
if ( V_60 ) {
F_69 ( V_116 ,
L_4 ) ;
continue;
}
F_71 ( V_116 , L_5 ,
V_117 -> V_25 ,
V_117 -> V_2 -> V_121 , V_117 -> V_2 -> V_87 ,
F_72 ( V_117 -> V_2 ) ,
V_117 -> V_86 ) ;
F_69 ( V_116 , L_6 ) ;
V_120 = 0 ;
F_70 (attach_obj, &buf_obj->attachments, node) {
F_69 ( V_116 , L_7 ) ;
F_71 ( V_116 , L_8 , F_73 ( V_118 -> V_94 ) ) ;
V_120 ++ ;
}
F_71 ( V_116 , L_9 ,
V_120 ) ;
V_119 ++ ;
V_25 += V_117 -> V_25 ;
F_6 ( & V_117 -> V_14 ) ;
}
F_71 ( V_116 , L_10 , V_119 , V_25 ) ;
F_6 ( & V_13 . V_14 ) ;
return 0 ;
}
static int F_74 ( struct V_115 * V_116 , void * V_122 )
{
void (* F_75)( struct V_115 * ) = V_116 -> V_123 ;
F_75 ( V_116 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_77 ( V_2 , F_74 , V_1 -> V_124 ) ;
}
static int F_78 ( void )
{
int V_125 = 0 ;
V_126 = F_79 ( L_11 , NULL ) ;
if ( F_41 ( V_126 ) ) {
V_125 = F_80 ( V_126 ) ;
V_126 = NULL ;
return V_125 ;
}
V_125 = F_81 ( L_12 , F_67 ) ;
if ( V_125 )
F_82 ( L_13 ) ;
return V_125 ;
}
static void F_83 ( void )
{
if ( V_126 )
F_84 ( V_126 ) ;
}
int F_81 ( const char * V_127 ,
int (* F_85)( struct V_115 * ) )
{
struct V_128 * V_129 ;
V_129 = F_86 ( V_127 , V_130 , V_126 ,
F_85 , & V_131 ) ;
return F_87 ( V_129 ) ;
}
static inline int F_78 ( void )
{
return 0 ;
}
static inline void F_83 ( void )
{
}
static int T_4 F_88 ( void )
{
F_43 ( & V_13 . V_14 ) ;
F_44 ( & V_13 . V_90 ) ;
F_78 () ;
return 0 ;
}
static void T_5 F_89 ( void )
{
F_83 () ;
}
