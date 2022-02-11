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
if ( V_20 -> V_21 + F_11 ( V_20 ) >
V_4 -> V_22 >> V_23 )
return - V_5 ;
return V_4 -> V_11 -> V_24 ( V_4 , V_20 ) ;
}
static T_1 F_12 ( struct V_2 * V_2 , T_1 V_25 , int V_26 )
{
struct V_3 * V_4 ;
T_1 V_27 ;
if ( ! F_2 ( V_2 ) )
return - V_28 ;
V_4 = V_2 -> V_6 ;
if ( V_26 == V_29 )
V_27 = V_4 -> V_22 ;
else if ( V_26 == V_30 )
V_27 = 0 ;
else
return - V_5 ;
if ( V_25 != 0 )
return - V_5 ;
return V_27 + V_25 ;
}
static void F_13 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_35 * V_36 = (struct V_35 * ) V_34 ;
unsigned long V_37 ;
F_14 ( & V_36 -> V_38 -> V_14 , V_37 ) ;
F_15 ( V_36 -> V_38 , V_36 -> V_9 ) ;
V_36 -> V_9 = 0 ;
F_16 ( & V_36 -> V_38 -> V_14 , V_37 ) ;
}
static unsigned int F_17 ( struct V_2 * V_2 , T_2 * V_38 )
{
struct V_3 * V_4 ;
struct V_17 * V_16 ;
struct V_39 * V_40 ;
struct V_31 * V_41 ;
unsigned long V_42 ;
unsigned V_43 , V_44 ;
V_4 = V_2 -> V_6 ;
if ( ! V_4 || ! V_4 -> V_16 )
return V_45 ;
V_16 = V_4 -> V_16 ;
F_18 ( V_2 , & V_4 -> V_38 , V_38 ) ;
V_42 = F_19 ( V_38 ) & ( V_46 | V_47 ) ;
if ( ! V_42 )
return 0 ;
V_48:
V_44 = F_20 ( & V_16 -> V_44 ) ;
F_21 () ;
V_40 = F_22 ( V_16 -> V_32 ) ;
if ( V_40 )
V_43 = V_40 -> V_43 ;
else
V_43 = 0 ;
V_41 = F_22 ( V_16 -> V_41 ) ;
if ( F_23 ( & V_16 -> V_44 , V_44 ) ) {
F_24 () ;
goto V_48;
}
if ( V_41 && ( ! ( V_42 & V_47 ) || V_43 == 0 ) ) {
struct V_35 * V_36 = & V_4 -> V_10 ;
unsigned long V_49 = V_46 ;
if ( V_43 == 0 )
V_49 |= V_47 ;
F_25 ( & V_4 -> V_38 . V_14 ) ;
if ( V_36 -> V_9 ) {
V_36 -> V_9 |= V_49 ;
V_42 &= ~ V_49 ;
} else
V_36 -> V_9 = V_49 ;
F_26 ( & V_4 -> V_38 . V_14 ) ;
if ( V_42 & V_49 ) {
if ( ! F_27 ( V_41 ) ) {
V_42 &= ~ V_49 ;
F_13 ( NULL , & V_36 -> V_34 ) ;
} else if ( ! F_28 ( V_41 , & V_36 -> V_34 ,
F_13 ) ) {
V_42 &= ~ V_49 ;
F_29 ( V_41 ) ;
} else {
F_29 ( V_41 ) ;
F_13 ( NULL , & V_36 -> V_34 ) ;
}
}
}
if ( ( V_42 & V_47 ) && V_43 > 0 ) {
struct V_35 * V_36 = & V_4 -> V_8 ;
int V_50 ;
F_25 ( & V_4 -> V_38 . V_14 ) ;
if ( V_36 -> V_9 )
V_42 &= ~ V_47 ;
else
V_36 -> V_9 = V_47 ;
F_26 ( & V_4 -> V_38 . V_14 ) ;
if ( ! ( V_42 & V_47 ) )
goto V_51;
for ( V_50 = 0 ; V_50 < V_43 ; ++ V_50 ) {
struct V_31 * V_32 = F_22 ( V_40 -> V_52 [ V_50 ] ) ;
if ( ! F_27 ( V_32 ) ) {
V_42 &= ~ V_47 ;
F_13 ( NULL , & V_36 -> V_34 ) ;
break;
}
if ( ! F_28 ( V_32 , & V_36 -> V_34 ,
F_13 ) ) {
F_29 ( V_32 ) ;
V_42 &= ~ V_47 ;
break;
}
F_29 ( V_32 ) ;
}
if ( V_50 == V_43 )
F_13 ( NULL , & V_36 -> V_34 ) ;
}
V_51:
F_24 () ;
return V_42 ;
}
static long F_30 ( struct V_2 * V_2 ,
unsigned int V_53 , unsigned long V_54 )
{
struct V_3 * V_4 ;
struct V_55 V_56 ;
enum V_57 V_58 ;
int V_59 ;
V_4 = V_2 -> V_6 ;
switch ( V_53 ) {
case V_60 :
if ( F_31 ( & V_56 , ( void V_61 * ) V_54 , sizeof( V_56 ) ) )
return - V_62 ;
if ( V_56 . V_37 & ~ V_63 )
return - V_5 ;
switch ( V_56 . V_37 & V_64 ) {
case V_65 :
V_58 = V_66 ;
break;
case V_67 :
V_58 = V_68 ;
break;
case V_64 :
V_58 = V_69 ;
break;
default:
return - V_5 ;
}
if ( V_56 . V_37 & V_70 )
V_59 = F_32 ( V_4 , V_58 ) ;
else
V_59 = F_33 ( V_4 , V_58 ) ;
return V_59 ;
default:
return - V_71 ;
}
}
static inline int F_2 ( struct V_2 * V_2 )
{
return V_2 -> V_72 == & V_73 ;
}
struct V_3 * F_34 ( const struct V_74 * V_75 )
{
struct V_3 * V_4 ;
struct V_17 * V_16 = V_75 -> V_16 ;
struct V_2 * V_2 ;
T_3 V_76 = sizeof( struct V_3 ) ;
int V_59 ;
if ( ! V_75 -> V_16 )
V_76 += sizeof( struct V_17 ) ;
else
V_76 += 1 ;
if ( F_35 ( ! V_75 -> V_77
|| ! V_75 -> V_11
|| ! V_75 -> V_11 -> V_78
|| ! V_75 -> V_11 -> V_79
|| ! V_75 -> V_11 -> V_12
|| ! V_75 -> V_11 -> V_80
|| ! V_75 -> V_11 -> V_81
|| ! V_75 -> V_11 -> V_24 ) ) {
return F_36 ( - V_5 ) ;
}
if ( ! F_37 ( V_75 -> V_18 ) )
return F_36 ( - V_82 ) ;
V_4 = F_38 ( V_76 , V_83 ) ;
if ( ! V_4 ) {
V_59 = - V_84 ;
goto V_85;
}
V_4 -> V_77 = V_75 -> V_77 ;
V_4 -> V_11 = V_75 -> V_11 ;
V_4 -> V_22 = V_75 -> V_22 ;
V_4 -> V_86 = V_75 -> V_86 ;
V_4 -> V_18 = V_75 -> V_18 ;
F_39 ( & V_4 -> V_38 ) ;
V_4 -> V_10 . V_38 = V_4 -> V_8 . V_38 = & V_4 -> V_38 ;
V_4 -> V_10 . V_9 = V_4 -> V_8 . V_9 = 0 ;
if ( ! V_16 ) {
V_16 = (struct V_17 * ) & V_4 [ 1 ] ;
F_40 ( V_16 ) ;
}
V_4 -> V_16 = V_16 ;
V_2 = F_41 ( L_1 , & V_73 , V_4 ,
V_75 -> V_37 ) ;
if ( F_42 ( V_2 ) ) {
V_59 = F_43 ( V_2 ) ;
goto V_87;
}
V_2 -> V_88 |= V_89 ;
V_4 -> V_2 = V_2 ;
F_44 ( & V_4 -> V_14 ) ;
F_45 ( & V_4 -> V_90 ) ;
F_4 ( & V_13 . V_14 ) ;
F_46 ( & V_4 -> V_15 , & V_13 . V_91 ) ;
F_6 ( & V_13 . V_14 ) ;
return V_4 ;
V_87:
F_9 ( V_4 ) ;
V_85:
F_8 ( V_75 -> V_18 ) ;
return F_36 ( V_59 ) ;
}
int F_47 ( struct V_3 * V_4 , int V_37 )
{
int V_92 ;
if ( ! V_4 || ! V_4 -> V_2 )
return - V_5 ;
V_92 = F_48 ( V_37 ) ;
if ( V_92 < 0 )
return V_92 ;
F_49 ( V_92 , V_4 -> V_2 ) ;
return V_92 ;
}
struct V_3 * F_50 ( int V_92 )
{
struct V_2 * V_2 ;
V_2 = F_51 ( V_92 ) ;
if ( ! V_2 )
return F_36 ( - V_28 ) ;
if ( ! F_2 ( V_2 ) ) {
F_52 ( V_2 ) ;
return F_36 ( - V_5 ) ;
}
return V_2 -> V_6 ;
}
void F_53 ( struct V_3 * V_4 )
{
if ( F_35 ( ! V_4 || ! V_4 -> V_2 ) )
return;
F_52 ( V_4 -> V_2 ) ;
}
struct V_93 * F_54 ( struct V_3 * V_4 ,
struct V_94 * V_95 )
{
struct V_93 * V_96 ;
int V_59 ;
if ( F_35 ( ! V_4 || ! V_95 ) )
return F_36 ( - V_5 ) ;
V_96 = F_38 ( sizeof( struct V_93 ) , V_83 ) ;
if ( V_96 == NULL )
return F_36 ( - V_84 ) ;
V_96 -> V_95 = V_95 ;
V_96 -> V_4 = V_4 ;
F_4 ( & V_4 -> V_14 ) ;
if ( V_4 -> V_11 -> V_96 ) {
V_59 = V_4 -> V_11 -> V_96 ( V_4 , V_95 , V_96 ) ;
if ( V_59 )
goto V_97;
}
F_46 ( & V_96 -> V_98 , & V_4 -> V_90 ) ;
F_6 ( & V_4 -> V_14 ) ;
return V_96 ;
V_97:
F_9 ( V_96 ) ;
F_6 ( & V_4 -> V_14 ) ;
return F_36 ( V_59 ) ;
}
void F_55 ( struct V_3 * V_4 , struct V_93 * V_96 )
{
if ( F_35 ( ! V_4 || ! V_96 ) )
return;
F_4 ( & V_4 -> V_14 ) ;
F_5 ( & V_96 -> V_98 ) ;
if ( V_4 -> V_11 -> V_99 )
V_4 -> V_11 -> V_99 ( V_4 , V_96 ) ;
F_6 ( & V_4 -> V_14 ) ;
F_9 ( V_96 ) ;
}
struct V_100 * F_56 ( struct V_93 * V_96 ,
enum V_57 V_58 )
{
struct V_100 * V_100 = F_36 ( - V_5 ) ;
F_57 () ;
if ( F_35 ( ! V_96 || ! V_96 -> V_4 ) )
return F_36 ( - V_5 ) ;
V_100 = V_96 -> V_4 -> V_11 -> V_78 ( V_96 , V_58 ) ;
if ( ! V_100 )
V_100 = F_36 ( - V_84 ) ;
return V_100 ;
}
void F_58 ( struct V_93 * V_96 ,
struct V_100 * V_100 ,
enum V_57 V_58 )
{
F_57 () ;
if ( F_35 ( ! V_96 || ! V_96 -> V_4 || ! V_100 ) )
return;
V_96 -> V_4 -> V_11 -> V_79 ( V_96 , V_100 ,
V_58 ) ;
}
static int F_59 ( struct V_3 * V_4 ,
enum V_57 V_58 )
{
bool V_101 = ( V_58 == V_69 ||
V_58 == V_68 ) ;
struct V_17 * V_16 = V_4 -> V_16 ;
long V_59 ;
V_59 = F_60 ( V_16 , V_101 , true ,
V_102 ) ;
if ( V_59 < 0 )
return V_59 ;
return 0 ;
}
int F_33 ( struct V_3 * V_4 ,
enum V_57 V_58 )
{
int V_59 = 0 ;
if ( F_35 ( ! V_4 ) )
return - V_5 ;
if ( V_4 -> V_11 -> V_103 )
V_59 = V_4 -> V_11 -> V_103 ( V_4 , V_58 ) ;
if ( V_59 == 0 )
V_59 = F_59 ( V_4 , V_58 ) ;
return V_59 ;
}
int F_32 ( struct V_3 * V_4 ,
enum V_57 V_58 )
{
int V_59 = 0 ;
F_35 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_104 )
V_59 = V_4 -> V_11 -> V_104 ( V_4 , V_58 ) ;
return V_59 ;
}
void * F_61 ( struct V_3 * V_4 , unsigned long V_105 )
{
F_35 ( ! V_4 ) ;
return V_4 -> V_11 -> V_80 ( V_4 , V_105 ) ;
}
void F_62 ( struct V_3 * V_4 , unsigned long V_105 ,
void * V_106 )
{
F_35 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_107 )
V_4 -> V_11 -> V_107 ( V_4 , V_105 , V_106 ) ;
}
void * F_63 ( struct V_3 * V_4 , unsigned long V_105 )
{
F_35 ( ! V_4 ) ;
return V_4 -> V_11 -> V_81 ( V_4 , V_105 ) ;
}
void F_64 ( struct V_3 * V_4 , unsigned long V_105 ,
void * V_106 )
{
F_35 ( ! V_4 ) ;
if ( V_4 -> V_11 -> V_108 )
V_4 -> V_11 -> V_108 ( V_4 , V_105 , V_106 ) ;
}
int F_65 ( struct V_3 * V_4 , struct V_19 * V_20 ,
unsigned long V_109 )
{
struct V_2 * V_110 ;
int V_59 ;
if ( F_35 ( ! V_4 || ! V_20 ) )
return - V_5 ;
if ( V_109 + F_11 ( V_20 ) < V_109 )
return - V_111 ;
if ( V_109 + F_11 ( V_20 ) >
V_4 -> V_22 >> V_23 )
return - V_5 ;
F_66 ( V_4 -> V_2 ) ;
V_110 = V_20 -> V_112 ;
V_20 -> V_112 = V_4 -> V_2 ;
V_20 -> V_21 = V_109 ;
V_59 = V_4 -> V_11 -> V_24 ( V_4 , V_20 ) ;
if ( V_59 ) {
V_20 -> V_112 = V_110 ;
F_52 ( V_4 -> V_2 ) ;
} else {
if ( V_110 )
F_52 ( V_110 ) ;
}
return V_59 ;
}
void * F_67 ( struct V_3 * V_4 )
{
void * V_113 ;
if ( F_35 ( ! V_4 ) )
return NULL ;
if ( ! V_4 -> V_11 -> V_114 )
return NULL ;
F_4 ( & V_4 -> V_14 ) ;
if ( V_4 -> V_7 ) {
V_4 -> V_7 ++ ;
F_3 ( ! V_4 -> V_115 ) ;
V_113 = V_4 -> V_115 ;
goto V_116;
}
F_3 ( V_4 -> V_115 ) ;
V_113 = V_4 -> V_11 -> V_114 ( V_4 ) ;
if ( F_68 ( F_42 ( V_113 ) ) )
V_113 = NULL ;
if ( ! V_113 )
goto V_116;
V_4 -> V_115 = V_113 ;
V_4 -> V_7 = 1 ;
V_116:
F_6 ( & V_4 -> V_14 ) ;
return V_113 ;
}
void F_69 ( struct V_3 * V_4 , void * V_106 )
{
if ( F_35 ( ! V_4 ) )
return;
F_3 ( ! V_4 -> V_115 ) ;
F_3 ( V_4 -> V_7 == 0 ) ;
F_3 ( V_4 -> V_115 != V_106 ) ;
F_4 ( & V_4 -> V_14 ) ;
if ( -- V_4 -> V_7 == 0 ) {
if ( V_4 -> V_11 -> V_117 )
V_4 -> V_11 -> V_117 ( V_4 , V_106 ) ;
V_4 -> V_115 = NULL ;
}
F_6 ( & V_4 -> V_14 ) ;
}
static int F_70 ( struct V_118 * V_119 , void * V_120 )
{
int V_59 ;
struct V_3 * V_121 ;
struct V_93 * V_122 ;
int V_123 = 0 , V_124 ;
T_3 V_22 = 0 ;
V_59 = F_71 ( & V_13 . V_14 ) ;
if ( V_59 )
return V_59 ;
F_72 ( V_119 , L_2 ) ;
F_72 ( V_119 , L_3 ) ;
F_73 (buf_obj, &db_list.head, list_node) {
V_59 = F_71 ( & V_121 -> V_14 ) ;
if ( V_59 ) {
F_72 ( V_119 ,
L_4 ) ;
continue;
}
F_74 ( V_119 , L_5 ,
V_121 -> V_22 ,
V_121 -> V_2 -> V_125 , V_121 -> V_2 -> V_88 ,
F_75 ( V_121 -> V_2 ) ,
V_121 -> V_86 ) ;
F_72 ( V_119 , L_6 ) ;
V_124 = 0 ;
F_73 (attach_obj, &buf_obj->attachments, node) {
F_72 ( V_119 , L_7 ) ;
F_74 ( V_119 , L_8 , F_76 ( V_122 -> V_95 ) ) ;
V_124 ++ ;
}
F_74 ( V_119 , L_9 ,
V_124 ) ;
V_123 ++ ;
V_22 += V_121 -> V_22 ;
F_6 ( & V_121 -> V_14 ) ;
}
F_74 ( V_119 , L_10 , V_123 , V_22 ) ;
F_6 ( & V_13 . V_14 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_78 ( V_2 , F_70 , NULL ) ;
}
static int F_79 ( void )
{
struct V_126 * V_127 ;
int V_128 = 0 ;
V_127 = F_80 ( L_11 , NULL ) ;
if ( F_42 ( V_127 ) )
return F_43 ( V_127 ) ;
V_129 = V_127 ;
V_127 = F_81 ( L_12 , V_130 , V_129 ,
NULL , & V_131 ) ;
if ( F_42 ( V_127 ) ) {
F_82 ( L_13 ) ;
F_83 ( V_129 ) ;
V_129 = NULL ;
V_128 = F_43 ( V_127 ) ;
}
return V_128 ;
}
static void F_84 ( void )
{
if ( V_129 )
F_83 ( V_129 ) ;
}
static inline int F_79 ( void )
{
return 0 ;
}
static inline void F_84 ( void )
{
}
static int T_4 F_85 ( void )
{
F_44 ( & V_13 . V_14 ) ;
F_45 ( & V_13 . V_91 ) ;
F_79 () ;
return 0 ;
}
static void T_5 F_86 ( void )
{
F_84 () ;
}
