static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static void F_2 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
V_9 -> V_10 = F_4 ( F_5 ( V_9 -> V_10 ) - V_7 ) ;
F_6 ( V_6 , V_7 ) ;
F_7 ( V_6 , F_8 ( V_6 ) , V_7 ) ;
F_9 ( V_6 ) ;
}
static int F_10 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 )
return 1 ;
F_2 ( V_6 , sizeof( struct V_11 ) ) ;
return - V_1 -> V_12 ;
}
static struct V_13 * F_11 ( struct V_5 * V_6 , struct V_13 * V_13 ,
void * V_14 , T_1 V_15 , T_2 V_16 )
{
T_3 * V_17 = V_14 ;
T_1 V_18 = F_5 ( V_17 [ 0 ] ) ;
T_1 V_19 = F_5 ( V_17 [ 1 ] ) ;
T_1 V_20 = V_15 + F_12 ( T_1 , V_19 + sizeof( V_21 ) , V_18 ) ;
T_4 V_22 ;
if ( V_6 -> V_23 ) {
V_6 -> V_23 = 0 ;
return V_13 ;
}
if ( ! F_13 ( V_6 , V_20 ) )
return NULL ;
V_13 = (struct V_13 * ) & F_8 ( V_6 ) [ 1 ] ;
if ( F_14 ( V_6 -> V_24 != V_25 ) )
F_15 ( V_6 ) ;
V_22 = F_16 ( ( void * ) V_13 + V_15 ,
V_6 -> V_26 , V_18 , V_19 ) ;
V_6 -> V_26 = F_17 ( V_6 -> V_26 , V_22 ) ;
return V_13 ;
}
static int F_18 ( struct V_5 * V_6 , struct V_13 * V_13 )
{
F_19 ( V_6 ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_7 , V_27 , V_15 ;
struct V_13 * V_13 ;
void * V_14 ;
V_21 V_28 = 0 ;
if ( ! V_1 )
return 1 ;
V_7 = sizeof( struct V_11 ) + sizeof( struct V_13 ) ;
if ( ! F_13 ( V_6 , V_7 ) )
goto V_29;
V_13 = (struct V_13 * ) & F_8 ( V_6 ) [ 1 ] ;
V_27 = V_13 -> V_30 << 2 ;
V_7 += V_27 ;
if ( ! F_13 ( V_6 , V_7 ) )
goto V_29;
V_13 = (struct V_13 * ) & F_8 ( V_6 ) [ 1 ] ;
V_15 = sizeof( struct V_13 ) + V_27 ;
if ( V_13 -> V_31 != 0 || F_21 ( V_13 , V_27 ) )
goto V_29;
V_15 = sizeof( struct V_13 ) + V_27 ;
F_3 ( V_6 ) -> V_10 = F_4 ( F_5 ( F_3 ( V_6 ) -> V_10 ) - V_7 ) ;
F_7 ( V_6 , F_8 ( V_6 ) , V_7 ) ;
V_14 = & V_13 [ 1 ] ;
if ( V_13 -> V_32 & V_33 ) {
T_5 V_32 = * ( T_5 * ) ( V_14 + V_28 ) ;
V_28 += V_34 ;
if ( V_32 & V_35 ) {
V_13 = F_11 ( V_6 , V_13 , V_14 + V_28 ,
V_15 , V_13 -> V_36 ) ;
if ( ! V_13 )
goto V_29;
V_14 = & V_13 [ 1 ] ;
V_28 += V_37 ;
}
}
if ( F_14 ( V_13 -> V_38 ) )
return F_18 ( V_6 , V_13 ) ;
F_6 ( V_6 , sizeof( struct V_11 ) + V_15 ) ;
F_9 ( V_6 ) ;
return - V_13 -> V_36 ;
V_29:
F_19 ( V_6 ) ;
return 0 ;
}
static struct V_5 * * F_22 ( struct V_5 * * V_39 ,
struct V_5 * V_6 )
{
const struct V_40 * V_41 ;
struct V_5 * * V_42 = NULL ;
T_2 V_43 = F_23 ( V_6 ) -> V_43 ;
const struct V_40 * * V_44 ;
F_24 () ;
V_44 = F_23 ( V_6 ) -> V_45 ? V_46 : V_47 ;
V_41 = F_25 ( V_44 [ V_43 ] ) ;
if ( ! V_41 || ! V_41 -> V_48 . V_49 )
goto V_50;
V_42 = V_41 -> V_48 . V_49 ( V_39 , V_6 ) ;
V_50:
F_26 () ;
return V_42 ;
}
static int F_27 ( struct V_5 * V_6 , int V_51 )
{
const struct V_40 * V_41 ;
T_2 V_43 = F_23 ( V_6 ) -> V_43 ;
int V_52 = - V_53 ;
const struct V_40 * * V_44 ;
F_28 ( V_6 , V_51 ) ;
F_24 () ;
V_44 = F_23 ( V_6 ) -> V_45 ? V_46 : V_47 ;
V_41 = F_25 ( V_44 [ V_43 ] ) ;
if ( F_29 ( ! V_41 || ! V_41 -> V_48 . V_54 ) )
goto V_50;
V_52 = V_41 -> V_48 . V_54 ( V_6 , V_51 ) ;
V_50:
F_26 () ;
return V_52 ;
}
static struct V_13 * F_30 ( struct V_5 * V_6 , unsigned int V_55 ,
struct V_13 * V_13 , void * V_14 ,
T_1 V_15 , T_2 V_16 )
{
T_3 * V_17 = V_14 ;
T_1 V_18 = F_5 ( V_17 [ 0 ] ) ;
T_1 V_19 = F_5 ( V_17 [ 1 ] ) ;
T_1 V_20 = V_15 + F_12 ( T_1 , V_19 + sizeof( V_21 ) , V_18 ) ;
T_4 V_22 ;
if ( V_6 -> V_23 )
return V_13 ;
if ( ! F_23 ( V_6 ) -> V_56 )
return NULL ;
if ( F_31 ( V_6 , V_55 + V_20 ) ) {
V_13 = F_32 ( V_6 , V_55 + V_20 , V_55 ) ;
if ( ! V_13 )
return NULL ;
}
V_22 = F_16 ( ( void * ) V_13 + V_15 ,
F_23 ( V_6 ) -> V_26 , V_18 , V_19 ) ;
V_6 -> V_26 = F_17 ( V_6 -> V_26 , V_22 ) ;
F_23 ( V_6 ) -> V_26 = F_17 ( F_23 ( V_6 ) -> V_26 , V_22 ) ;
V_6 -> V_23 = 1 ;
return V_13 ;
}
static struct V_5 * * F_33 ( struct V_5 * * V_39 ,
struct V_5 * V_6 )
{
const struct V_40 * * V_44 ;
const struct V_40 * V_41 ;
struct V_5 * * V_42 = NULL ;
struct V_5 * V_57 ;
struct V_13 * V_13 ;
T_1 V_7 , V_27 , V_15 , V_55 ;
void * V_14 ;
V_21 V_28 = 0 ;
int V_58 = 1 ;
V_55 = F_34 ( V_6 ) ;
V_7 = V_55 + sizeof( * V_13 ) ;
V_13 = F_35 ( V_6 , V_55 ) ;
if ( F_31 ( V_6 , V_7 ) ) {
V_13 = F_32 ( V_6 , V_7 , V_55 ) ;
if ( F_14 ( ! V_13 ) )
goto V_59;
}
V_27 = V_13 -> V_30 << 2 ;
V_7 += V_27 ;
if ( F_31 ( V_6 , V_7 ) ) {
V_13 = F_32 ( V_6 , V_7 , V_55 ) ;
if ( F_14 ( ! V_13 ) )
goto V_59;
}
if ( F_14 ( V_13 -> V_38 ) || V_13 -> V_31 != 0 ||
F_21 ( V_13 , V_27 ) )
goto V_59;
V_15 = sizeof( * V_13 ) + V_27 ;
F_36 ( V_6 , V_13 , V_15 ) ;
V_14 = & V_13 [ 1 ] ;
if ( V_13 -> V_32 & V_33 ) {
T_5 V_32 = * ( T_5 * ) ( V_14 + V_28 ) ;
V_28 += V_34 ;
if ( V_32 & V_35 ) {
V_13 = F_30 ( V_6 , V_55 , V_13 ,
V_14 + V_28 , V_15 ,
V_13 -> V_36 ) ;
if ( ! V_13 )
goto V_59;
V_14 = & V_13 [ 1 ] ;
V_28 += V_37 ;
}
}
F_37 ( V_6 , V_15 ) ;
V_58 = 0 ;
for ( V_57 = * V_39 ; V_57 ; V_57 = V_57 -> V_60 ) {
const struct V_13 * V_61 ;
if ( ! F_23 ( V_57 ) -> V_62 )
continue;
V_61 = (struct V_13 * ) ( V_57 -> V_14 + V_55 ) ;
if ( V_13 -> V_63 != V_61 -> V_63 ) {
F_23 ( V_57 ) -> V_62 = 0 ;
continue;
}
if ( V_13 -> V_30 && memcmp ( & V_13 [ 1 ] , & V_61 [ 1 ] ,
V_13 -> V_30 << 2 ) ) {
F_23 ( V_57 ) -> V_62 = 0 ;
continue;
}
}
F_24 () ;
V_44 = F_23 ( V_6 ) -> V_45 ? V_46 : V_47 ;
V_41 = F_25 ( V_44 [ V_13 -> V_36 ] ) ;
if ( F_29 ( ! V_41 || ! V_41 -> V_48 . V_49 ) )
goto V_50;
V_42 = V_41 -> V_48 . V_49 ( V_39 , V_6 ) ;
V_50:
F_26 () ;
V_59:
F_23 ( V_6 ) -> V_58 |= V_58 ;
return V_42 ;
}
static int F_38 ( struct V_5 * V_6 , int V_51 )
{
const struct V_40 * * V_44 ;
struct V_13 * V_13 = (struct V_13 * ) ( V_6 -> V_14 + V_51 ) ;
const struct V_40 * V_41 ;
unsigned int V_64 ;
T_2 V_43 ;
int V_52 = - V_65 ;
V_43 = V_13 -> V_36 ;
V_64 = sizeof( * V_13 ) + ( V_13 -> V_30 << 2 ) ;
F_24 () ;
V_44 = F_23 ( V_6 ) -> V_45 ? V_46 : V_47 ;
V_41 = F_25 ( V_44 [ V_43 ] ) ;
if ( F_29 ( ! V_41 || ! V_41 -> V_48 . V_54 ) )
goto V_50;
V_52 = V_41 -> V_48 . V_54 ( V_6 , V_51 + V_64 ) ;
V_50:
F_26 () ;
return V_52 ;
}
static int F_39 ( struct V_1 * V_1 )
{
struct V_1 * V_66 ;
F_40 ( & V_67 ) ;
F_41 (fout, &fou_list, list) {
if ( V_1 -> V_68 == V_66 -> V_68 ) {
F_42 ( & V_67 ) ;
return - V_69 ;
}
}
F_43 ( & V_1 -> V_70 , & V_71 ) ;
F_42 ( & V_67 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_1 )
{
struct V_72 * V_2 = V_1 -> V_2 ;
struct V_2 * V_3 = V_2 -> V_3 ;
F_45 ( & V_1 -> V_73 ) ;
F_46 ( & V_1 -> V_70 ) ;
V_3 -> V_4 = NULL ;
F_47 ( V_2 ) ;
F_48 ( V_1 ) ;
}
static int F_49 ( struct V_2 * V_3 , struct V_1 * V_1 , struct V_74 * V_75 )
{
F_50 ( V_3 ) -> V_76 = F_10 ;
V_1 -> V_12 = V_75 -> V_12 ;
V_1 -> V_73 . V_48 . V_49 = F_22 ;
V_1 -> V_73 . V_48 . V_54 = F_27 ;
V_1 -> V_73 . V_68 = V_75 -> V_77 . V_78 ;
V_1 -> V_73 . V_16 = V_75 -> V_12 ;
return 0 ;
}
static int F_51 ( struct V_2 * V_3 , struct V_1 * V_1 , struct V_74 * V_75 )
{
F_50 ( V_3 ) -> V_76 = F_20 ;
V_1 -> V_73 . V_48 . V_49 = F_33 ;
V_1 -> V_73 . V_48 . V_54 = F_38 ;
V_1 -> V_73 . V_68 = V_75 -> V_77 . V_78 ;
return 0 ;
}
static int F_52 ( struct V_79 * V_79 , struct V_74 * V_75 ,
struct V_72 * * V_80 )
{
struct V_1 * V_1 = NULL ;
int V_52 ;
struct V_72 * V_2 = NULL ;
struct V_2 * V_3 ;
V_52 = F_53 ( V_79 , & V_75 -> V_77 , & V_2 ) ;
if ( V_52 < 0 )
goto error;
V_1 = F_54 ( sizeof( * V_1 ) , V_81 ) ;
if ( ! V_1 ) {
V_52 = - V_82 ;
goto error;
}
V_3 = V_2 -> V_3 ;
V_1 -> V_68 = V_75 -> V_77 . V_78 ;
switch ( V_75 -> type ) {
case V_83 :
V_52 = F_49 ( V_3 , V_1 , V_75 ) ;
if ( V_52 )
goto error;
break;
case V_84 :
V_52 = F_51 ( V_3 , V_1 , V_75 ) ;
if ( V_52 )
goto error;
break;
default:
V_52 = - V_85 ;
goto error;
}
F_50 ( V_3 ) -> V_86 = 1 ;
F_55 () ;
V_3 -> V_4 = V_1 ;
V_1 -> V_2 = V_2 ;
F_56 ( V_3 , true ) ;
V_3 -> V_87 = V_88 ;
if ( V_75 -> V_77 . V_89 == V_90 ) {
V_52 = F_57 ( & V_1 -> V_73 ) ;
if ( V_52 )
goto error;
}
V_52 = F_39 ( V_1 ) ;
if ( V_52 )
goto error;
if ( V_80 )
* V_80 = V_2 ;
return 0 ;
error:
F_48 ( V_1 ) ;
if ( V_2 )
F_47 ( V_2 ) ;
return V_52 ;
}
static int F_58 ( struct V_79 * V_79 , struct V_74 * V_75 )
{
struct V_1 * V_1 ;
V_21 V_68 = V_75 -> V_77 . V_78 ;
int V_52 = - V_85 ;
F_40 ( & V_67 ) ;
F_41 (fou, &fou_list, list) {
if ( V_1 -> V_68 == V_68 ) {
F_45 ( & V_1 -> V_73 ) ;
F_44 ( V_1 ) ;
V_52 = 0 ;
break;
}
}
F_42 ( & V_67 ) ;
return V_52 ;
}
static int F_59 ( struct V_91 * V_92 ,
struct V_74 * V_75 )
{
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
V_75 -> V_77 . V_89 = V_90 ;
if ( V_92 -> V_93 [ V_94 ] ) {
T_2 V_89 = F_60 ( V_92 -> V_93 [ V_94 ] ) ;
if ( V_89 != V_90 && V_89 != V_95 )
return - V_85 ;
V_75 -> V_77 . V_89 = V_89 ;
}
if ( V_92 -> V_93 [ V_96 ] ) {
V_21 V_68 = F_61 ( V_92 -> V_93 [ V_96 ] ) ;
V_75 -> V_77 . V_78 = V_68 ;
}
if ( V_92 -> V_93 [ V_97 ] )
V_75 -> V_12 = F_60 ( V_92 -> V_93 [ V_97 ] ) ;
if ( V_92 -> V_93 [ V_98 ] )
V_75 -> type = F_60 ( V_92 -> V_93 [ V_98 ] ) ;
return 0 ;
}
static int F_62 ( struct V_5 * V_6 , struct V_91 * V_92 )
{
struct V_74 V_75 ;
int V_52 ;
V_52 = F_59 ( V_92 , & V_75 ) ;
if ( V_52 )
return V_52 ;
return F_52 ( & V_99 , & V_75 , NULL ) ;
}
static int F_63 ( struct V_5 * V_6 , struct V_91 * V_92 )
{
struct V_74 V_75 ;
F_59 ( V_92 , & V_75 ) ;
return F_58 ( & V_99 , & V_75 ) ;
}
T_1 F_64 ( struct V_100 * V_101 )
{
return sizeof( struct V_11 ) ;
}
T_1 F_65 ( struct V_100 * V_101 )
{
T_1 V_7 ;
bool V_102 = false ;
V_7 = sizeof( struct V_11 ) + sizeof( struct V_13 ) ;
if ( V_101 -> V_32 & V_103 ) {
V_7 += V_37 ;
V_102 = true ;
}
V_7 += V_102 ? V_34 : 0 ;
return V_7 ;
}
static void F_66 ( struct V_5 * V_6 , struct V_100 * V_101 ,
struct V_104 * V_105 , T_2 * V_12 , T_3 V_106 )
{
struct V_11 * V_107 ;
F_67 ( V_6 , sizeof( struct V_11 ) ) ;
F_9 ( V_6 ) ;
V_107 = F_8 ( V_6 ) ;
V_107 -> V_108 = V_101 -> V_109 ;
V_107 -> V_110 = V_106 ;
V_107 -> V_7 = F_4 ( V_6 -> V_7 ) ;
V_107 -> V_111 = 0 ;
F_68 ( ! ( V_101 -> V_32 & V_112 ) , V_6 ,
V_105 -> V_113 , V_105 -> V_114 , V_6 -> V_7 ) ;
* V_12 = V_115 ;
}
int F_69 ( struct V_5 * V_6 , struct V_100 * V_101 ,
T_2 * V_12 , struct V_104 * V_105 )
{
bool V_26 = ! ! ( V_101 -> V_32 & V_112 ) ;
int type = V_26 ? V_116 : V_117 ;
T_3 V_106 ;
V_6 = F_70 ( V_6 , V_26 , type ) ;
if ( F_71 ( V_6 ) )
return F_72 ( V_6 ) ;
V_106 = V_101 -> V_106 ? : F_73 ( F_74 ( V_6 -> V_118 ) ,
V_6 , 0 , 0 , false ) ;
F_66 ( V_6 , V_101 , V_105 , V_12 , V_106 ) ;
return 0 ;
}
int F_75 ( struct V_5 * V_6 , struct V_100 * V_101 ,
T_2 * V_12 , struct V_104 * V_105 )
{
bool V_26 = ! ! ( V_101 -> V_32 & V_112 ) ;
int type = V_26 ? V_116 : V_117 ;
struct V_13 * V_13 ;
T_1 V_15 , V_27 = 0 ;
T_3 V_106 ;
void * V_14 ;
bool V_102 = false ;
if ( ( V_101 -> V_32 & V_103 ) &&
V_6 -> V_24 == V_119 ) {
V_26 = false ;
V_27 += V_37 ;
type |= V_120 ;
V_102 = true ;
}
V_27 += V_102 ? V_34 : 0 ;
V_6 = F_70 ( V_6 , V_26 , type ) ;
if ( F_71 ( V_6 ) )
return F_72 ( V_6 ) ;
V_106 = V_101 -> V_106 ? : F_73 ( F_74 ( V_6 -> V_118 ) ,
V_6 , 0 , 0 , false ) ;
V_15 = sizeof( struct V_13 ) + V_27 ;
F_67 ( V_6 , V_15 ) ;
V_13 = (struct V_13 * ) V_6 -> V_14 ;
V_13 -> V_38 = 0 ;
V_13 -> V_31 = 0 ;
V_13 -> V_30 = V_27 >> 2 ;
V_13 -> V_32 = 0 ;
V_13 -> V_36 = * V_12 ;
V_14 = & V_13 [ 1 ] ;
if ( V_102 ) {
T_5 * V_32 = V_14 ;
V_13 -> V_32 |= V_33 ;
* V_32 = 0 ;
V_14 += V_34 ;
if ( type & V_120 ) {
V_21 V_121 = F_76 ( V_6 ) ;
T_3 * V_17 = V_14 ;
if ( V_121 < V_15 )
return - V_85 ;
V_121 -= V_15 ;
V_17 [ 0 ] = F_4 ( V_121 ) ;
V_17 [ 1 ] = F_4 ( V_121 + V_6 -> V_122 ) ;
if ( ! F_77 ( V_6 ) ) {
V_6 -> V_24 = V_123 ;
V_6 -> V_124 = 0 ;
}
* V_32 |= V_35 ;
V_14 += V_37 ;
}
}
F_66 ( V_6 , V_101 , V_105 , V_12 , V_106 ) ;
return 0 ;
}
static int F_78 ( void )
{
int V_125 ;
V_125 = F_79 ( & V_126 , V_127 ) ;
if ( V_125 < 0 ) {
F_80 ( L_1 ) ;
return V_125 ;
}
V_125 = F_79 ( & V_128 , V_129 ) ;
if ( V_125 < 0 ) {
F_80 ( L_2 ) ;
F_81 ( & V_126 , V_127 ) ;
return V_125 ;
}
return 0 ;
}
static void F_82 ( void )
{
F_81 ( & V_126 , V_127 ) ;
F_81 ( & V_128 , V_129 ) ;
}
static int F_78 ( void )
{
return 0 ;
}
static void F_82 ( void )
{
}
static int T_6 F_83 ( void )
{
int V_125 ;
V_125 = F_84 ( & V_130 ,
V_131 ) ;
if ( V_125 < 0 )
goto exit;
V_125 = F_78 () ;
if ( V_125 < 0 )
F_85 ( & V_130 ) ;
exit:
return V_125 ;
}
static void T_7 F_86 ( void )
{
struct V_1 * V_1 , * V_60 ;
F_82 () ;
F_85 ( & V_130 ) ;
F_40 ( & V_67 ) ;
F_87 (fou, next, &fou_list, list)
F_44 ( V_1 ) ;
F_42 ( & V_67 ) ;
}
