static const char * F_1 ( const struct V_1 * V_2 )
{
static char V_3 [ 2 * V_4 + 1 ] ;
unsigned int V_5 , V_6 = sizeof( V_3 ) ;
char * V_7 = V_3 ;
V_6 -- ;
if ( V_6 < 3 )
return L_1 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( V_6 < 2 ) {
strcpy ( V_7 - 3 , L_2 ) ;
break;
}
sprintf ( V_7 , L_3 , V_2 -> V_8 [ V_5 ] ) ;
V_7 += 2 ;
V_6 -= 2 ;
}
* V_7 = '\0' ;
return V_3 ;
}
static void
F_2 ( struct V_9 * V_10 , unsigned long V_11 )
{
struct V_9 * V_12 ;
struct V_13 * V_14 ;
F_3 ( L_4 , V_10 , V_11 ) ;
if ( F_4 ( & V_10 -> V_15 ) ) {
F_5 ( & V_10 -> V_16 ) ;
} else {
F_6 ( & V_10 -> V_15 ) ;
}
V_14 = & V_17 ;
if ( V_11 != V_18 ) {
if ( ( V_11 += V_19 ) == V_18 )
V_11 ++ ;
F_7 (pos, &nlm_blocked) {
V_12 = F_8 ( V_14 , struct V_9 , V_15 ) ;
if ( F_9 ( V_12 -> V_20 , V_11 ) || V_12 -> V_20 == V_18 )
break;
}
}
F_10 ( & V_10 -> V_15 , V_14 ) ;
V_10 -> V_20 = V_11 ;
}
static void F_11 ( struct V_9 * V_10 , unsigned long V_11 )
{
F_12 ( & V_21 ) ;
F_2 ( V_10 , V_11 ) ;
F_13 ( & V_21 ) ;
}
static inline void
F_14 ( struct V_9 * V_10 )
{
if ( ! F_4 ( & V_10 -> V_15 ) ) {
F_12 ( & V_21 ) ;
F_6 ( & V_10 -> V_15 ) ;
F_13 ( & V_21 ) ;
F_15 ( V_10 ) ;
}
}
static struct V_9 *
F_16 ( struct V_22 * V_23 , struct V_24 * V_25 )
{
struct V_9 * V_10 ;
struct V_26 * V_27 ;
F_3 ( L_5 ,
V_23 , V_25 -> V_27 . V_28 ,
( long long ) V_25 -> V_27 . V_29 ,
( long long ) V_25 -> V_27 . V_30 , V_25 -> V_27 . V_31 ) ;
F_17 (block, &nlm_blocked, b_list) {
V_27 = & V_10 -> V_32 -> V_33 . V_25 . V_27 ;
F_3 ( L_6 ,
V_10 -> V_34 , V_27 -> V_28 ,
( long long ) V_27 -> V_29 ,
( long long ) V_27 -> V_30 , V_27 -> V_31 ,
F_1 ( & V_10 -> V_32 -> V_33 . V_2 ) ) ;
if ( V_10 -> V_34 == V_23 && F_18 ( V_27 , & V_25 -> V_27 ) ) {
F_5 ( & V_10 -> V_16 ) ;
return V_10 ;
}
}
return NULL ;
}
static inline int F_19 ( struct V_1 * V_35 , struct V_1 * V_12 )
{
if ( V_35 -> V_6 != V_12 -> V_6 )
return 0 ;
if ( memcmp ( V_35 -> V_8 , V_12 -> V_8 , V_35 -> V_6 ) )
return 0 ;
return 1 ;
}
static inline struct V_9 *
F_20 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
F_17 (block, &nlm_blocked, b_list) {
if ( F_19 ( & V_10 -> V_32 -> V_33 . V_2 , V_2 ) )
goto V_36;
}
return NULL ;
V_36:
F_3 ( L_7 , F_1 ( V_2 ) , V_10 ) ;
F_5 ( & V_10 -> V_16 ) ;
return V_10 ;
}
static struct V_9 *
F_21 ( struct V_37 * V_38 , struct V_39 * V_40 ,
struct V_22 * V_23 , struct V_24 * V_25 ,
struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_41 * V_42 = NULL ;
V_42 = F_22 ( V_40 ) ;
if ( V_42 == NULL )
return NULL ;
V_10 = F_23 ( sizeof( * V_10 ) , V_43 ) ;
if ( V_10 == NULL )
goto V_44;
F_24 ( & V_10 -> V_16 ) ;
F_25 ( & V_10 -> V_15 ) ;
F_25 ( & V_10 -> V_45 ) ;
if ( ! F_26 ( V_42 , V_25 ) )
goto V_46;
V_42 -> V_33 . V_25 . V_27 . V_47 |= V_48 ;
V_42 -> V_33 . V_25 . V_27 . V_49 = & V_50 ;
F_27 ( & V_42 -> V_33 . V_2 ) ;
F_3 ( L_8 , V_10 ) ;
V_10 -> V_51 = V_38 -> V_52 ;
V_10 -> V_53 = V_40 ;
V_10 -> V_34 = V_23 ;
V_10 -> V_54 = NULL ;
V_23 -> V_55 ++ ;
F_28 ( & V_10 -> V_45 , & V_23 -> V_56 ) ;
V_10 -> V_32 = V_42 ;
V_42 -> V_57 = V_58 ;
V_42 -> V_59 = V_10 ;
return V_10 ;
V_46:
F_29 ( V_10 ) ;
V_44:
F_30 ( V_42 ) ;
return NULL ;
}
static int F_31 ( struct V_9 * V_10 )
{
int V_60 ;
F_3 ( L_9 , V_10 ) ;
V_60 = F_32 ( V_10 -> V_34 -> V_61 , & V_10 -> V_32 -> V_33 . V_25 . V_27 ) ;
F_14 ( V_10 ) ;
return V_60 ;
}
static void F_33 ( struct V_62 * V_62 )
{
struct V_9 * V_10 = F_34 ( V_62 , struct V_9 , V_16 ) ;
struct V_22 * V_23 = V_10 -> V_34 ;
F_3 ( L_10 , V_10 ) ;
F_6 ( & V_10 -> V_45 ) ;
F_35 ( & V_23 -> V_63 ) ;
F_36 ( V_10 -> V_32 ) ;
F_30 ( V_10 -> V_32 ) ;
F_37 ( V_10 -> V_34 ) ;
F_29 ( V_10 -> V_54 ) ;
F_29 ( V_10 ) ;
}
static void F_15 ( struct V_9 * V_10 )
{
if ( V_10 != NULL )
F_38 ( & V_10 -> V_16 , F_33 , & V_10 -> V_34 -> V_63 ) ;
}
void F_39 ( struct V_39 * V_40 ,
struct V_22 * V_23 ,
T_1 V_64 )
{
struct V_9 * V_10 , * V_65 ;
V_66:
F_40 ( & V_23 -> V_63 ) ;
F_41 (block, next, &file->f_blocks, b_flist) {
if ( ! V_64 ( V_10 -> V_53 , V_40 ) )
continue;
if ( F_4 ( & V_10 -> V_15 ) )
continue;
F_5 ( & V_10 -> V_16 ) ;
F_35 ( & V_23 -> V_63 ) ;
F_31 ( V_10 ) ;
F_15 ( V_10 ) ;
goto V_66;
}
F_35 ( & V_23 -> V_63 ) ;
}
static int F_26 ( struct V_41 * V_42 , struct V_24 * V_25 )
{
F_42 ( & V_42 -> V_33 . V_25 . V_27 , & V_25 -> V_27 ) ;
memcpy ( & V_42 -> V_33 . V_25 . V_67 , & V_25 -> V_67 , sizeof( V_42 -> V_33 . V_25 . V_67 ) ) ;
V_42 -> V_33 . V_25 . V_68 = F_43 () -> V_69 ;
V_42 -> V_33 . V_25 . V_70 . V_6 = V_25 -> V_70 . V_6 ;
V_42 -> V_33 . V_25 . V_70 . V_8 = V_42 -> V_71 ;
V_42 -> V_33 . V_25 . V_72 = V_25 -> V_27 . V_28 ;
if ( V_25 -> V_70 . V_6 > V_73 ) {
void * V_8 = F_44 ( V_25 -> V_70 . V_6 , V_43 ) ;
if ( ! V_8 )
return 0 ;
V_42 -> V_33 . V_25 . V_70 . V_8 = ( V_74 * ) V_8 ;
}
memcpy ( V_42 -> V_33 . V_25 . V_70 . V_8 , V_25 -> V_70 . V_8 , V_25 -> V_70 . V_6 ) ;
return 1 ;
}
static void F_36 ( struct V_41 * V_42 )
{
if ( V_42 -> V_33 . V_25 . V_70 . V_8 != V_42 -> V_71 )
F_29 ( V_42 -> V_33 . V_25 . V_70 . V_8 ) ;
F_45 ( & V_42 -> V_33 . V_25 . V_27 ) ;
}
static T_2
F_46 ( struct V_37 * V_38 , struct V_9 * V_10 )
{
T_2 V_60 = V_75 ;
V_10 -> V_76 |= V_77 ;
F_11 ( V_10 , V_78 ) ;
V_10 -> V_79 = & V_38 -> V_80 ;
if ( V_38 -> V_80 . V_81 ) {
V_10 -> V_82 =
V_38 -> V_80 . V_81 ( V_10 -> V_79 ) ;
if ( V_10 -> V_82 != NULL )
V_60 = V_83 ;
}
F_3 ( L_11 ,
V_10 , V_10 -> V_76 , F_47 ( V_60 ) ) ;
return V_60 ;
}
T_2
F_48 ( struct V_37 * V_38 , struct V_22 * V_23 ,
struct V_39 * V_40 , struct V_24 * V_25 , int V_84 ,
struct V_1 * V_2 , int V_85 )
{
struct V_9 * V_10 = NULL ;
int error ;
T_2 V_86 ;
F_3 ( L_12 ,
V_23 -> V_61 -> V_87 . V_88 -> V_89 -> V_90 -> V_91 ,
V_23 -> V_61 -> V_87 . V_88 -> V_89 -> V_92 ,
V_25 -> V_27 . V_31 , V_25 -> V_27 . V_28 ,
( long long ) V_25 -> V_27 . V_29 ,
( long long ) V_25 -> V_27 . V_30 ,
V_84 ) ;
F_40 ( & V_23 -> V_63 ) ;
V_10 = F_16 ( V_23 , V_25 ) ;
if ( V_10 == NULL ) {
V_10 = F_21 ( V_38 , V_40 , V_23 , V_25 , V_2 ) ;
V_86 = V_75 ;
if ( V_10 == NULL )
goto V_93;
V_25 = & V_10 -> V_32 -> V_33 . V_25 ;
} else
V_25 -> V_27 . V_47 &= ~ V_48 ;
if ( V_10 -> V_76 & V_77 ) {
F_3 ( L_13 ,
V_10 , V_10 -> V_76 ) ;
if ( V_10 -> V_94 ) {
F_31 ( V_10 ) ;
V_86 = V_95 ;
goto V_93;
}
if ( V_10 -> V_76 & V_96 ) {
F_31 ( V_10 ) ;
V_86 = V_97 ;
goto V_93;
}
V_86 = V_83 ;
goto V_93;
}
if ( F_49 ( F_50 ( V_38 ) ) && ! V_85 ) {
V_86 = V_98 ;
goto V_93;
}
if ( V_85 && ! F_49 ( F_50 ( V_38 ) ) ) {
V_86 = V_98 ;
goto V_93;
}
if ( ! V_84 )
V_25 -> V_27 . V_47 &= ~ V_48 ;
error = F_51 ( V_23 -> V_61 , V_99 , & V_25 -> V_27 , NULL ) ;
V_25 -> V_27 . V_47 &= ~ V_48 ;
F_3 ( L_14 , error ) ;
switch ( error ) {
case 0 :
V_86 = V_95 ;
goto V_93;
case - V_100 :
if ( V_84 )
break;
V_86 = V_97 ;
goto V_93;
case V_101 :
if ( V_84 )
break;
V_86 = F_46 ( V_38 , V_10 ) ;
goto V_93;
case - V_102 :
V_86 = V_103 ;
goto V_93;
default:
V_86 = V_75 ;
goto V_93;
}
V_86 = V_104 ;
F_11 ( V_10 , V_18 ) ;
V_93:
F_35 ( & V_23 -> V_63 ) ;
F_15 ( V_10 ) ;
F_3 ( L_15 , V_86 ) ;
return V_86 ;
}
T_2
F_52 ( struct V_37 * V_38 , struct V_22 * V_23 ,
struct V_39 * V_40 , struct V_24 * V_25 ,
struct V_24 * V_105 , struct V_1 * V_2 )
{
struct V_9 * V_10 = NULL ;
int error ;
T_2 V_86 ;
F_3 ( L_16 ,
V_23 -> V_61 -> V_87 . V_88 -> V_89 -> V_90 -> V_91 ,
V_23 -> V_61 -> V_87 . V_88 -> V_89 -> V_92 ,
V_25 -> V_27 . V_31 ,
( long long ) V_25 -> V_27 . V_29 ,
( long long ) V_25 -> V_27 . V_30 ) ;
V_10 = F_16 ( V_23 , V_25 ) ;
if ( V_10 == NULL ) {
struct V_26 * V_106 = F_23 ( sizeof( * V_106 ) , V_43 ) ;
if ( V_106 == NULL )
return V_95 ;
V_10 = F_21 ( V_38 , V_40 , V_23 , V_25 , V_2 ) ;
if ( V_10 == NULL ) {
F_29 ( V_106 ) ;
return V_95 ;
}
V_10 -> V_54 = V_106 ;
}
if ( V_10 -> V_76 & V_77 ) {
F_3 ( L_17 ,
V_10 , V_10 -> V_76 , V_10 -> V_54 ) ;
if ( V_10 -> V_76 & V_96 ) {
F_31 ( V_10 ) ;
V_86 = V_97 ;
goto V_93;
}
if ( V_10 -> V_76 & V_107 ) {
F_31 ( V_10 ) ;
if ( V_10 -> V_54 != NULL
&& V_10 -> V_54 -> V_31 != V_108 ) {
V_25 -> V_27 = * V_10 -> V_54 ;
goto V_109;
} else {
V_86 = V_95 ;
goto V_93;
}
}
V_86 = V_83 ;
goto V_93;
}
if ( F_49 ( F_50 ( V_38 ) ) ) {
V_86 = V_98 ;
goto V_93;
}
error = F_53 ( V_23 -> V_61 , & V_25 -> V_27 ) ;
if ( error == V_101 ) {
V_86 = F_46 ( V_38 , V_10 ) ;
goto V_93;
}
if ( error ) {
V_86 = V_75 ;
goto V_93;
}
if ( V_25 -> V_27 . V_31 == V_108 ) {
V_86 = V_95 ;
goto V_93;
}
V_109:
F_3 ( L_18 ,
V_25 -> V_27 . V_31 , ( long long ) V_25 -> V_27 . V_29 ,
( long long ) V_25 -> V_27 . V_30 ) ;
V_105 -> V_68 = L_19 ;
V_105 -> V_6 = strlen ( V_105 -> V_68 ) ;
V_105 -> V_70 . V_6 = 0 ;
V_105 -> V_72 = V_25 -> V_27 . V_28 ;
V_105 -> V_27 . V_31 = V_25 -> V_27 . V_31 ;
V_105 -> V_27 . V_29 = V_25 -> V_27 . V_29 ;
V_105 -> V_27 . V_30 = V_25 -> V_27 . V_30 ;
V_86 = V_97 ;
V_93:
if ( V_10 )
F_15 ( V_10 ) ;
return V_86 ;
}
T_2
F_54 ( struct V_110 * V_110 , struct V_22 * V_23 , struct V_24 * V_25 )
{
int error ;
F_3 ( L_20 ,
V_23 -> V_61 -> V_87 . V_88 -> V_89 -> V_90 -> V_91 ,
V_23 -> V_61 -> V_87 . V_88 -> V_89 -> V_92 ,
V_25 -> V_27 . V_28 ,
( long long ) V_25 -> V_27 . V_29 ,
( long long ) V_25 -> V_27 . V_30 ) ;
F_55 ( V_110 , V_23 , V_25 ) ;
V_25 -> V_27 . V_31 = V_108 ;
error = F_51 ( V_23 -> V_61 , V_99 , & V_25 -> V_27 , NULL ) ;
return ( error < 0 ) ? V_75 : V_95 ;
}
T_2
F_55 ( struct V_110 * V_110 , struct V_22 * V_23 , struct V_24 * V_25 )
{
struct V_9 * V_10 ;
int V_60 = 0 ;
F_3 ( L_21 ,
V_23 -> V_61 -> V_87 . V_88 -> V_89 -> V_90 -> V_91 ,
V_23 -> V_61 -> V_87 . V_88 -> V_89 -> V_92 ,
V_25 -> V_27 . V_28 ,
( long long ) V_25 -> V_27 . V_29 ,
( long long ) V_25 -> V_27 . V_30 ) ;
if ( F_49 ( V_110 ) )
return V_98 ;
F_40 ( & V_23 -> V_63 ) ;
V_10 = F_16 ( V_23 , V_25 ) ;
F_35 ( & V_23 -> V_63 ) ;
if ( V_10 != NULL ) {
F_56 ( V_10 -> V_34 -> V_61 ,
& V_10 -> V_32 -> V_33 . V_25 . V_27 ) ;
V_60 = F_31 ( V_10 ) ;
F_15 ( V_10 ) ;
}
return V_60 ? V_97 : V_95 ;
}
static void
F_57 ( struct V_9 * V_10 , struct V_26 * V_106 ,
int V_111 )
{
V_10 -> V_76 |= V_107 ;
if ( V_111 == 0 )
V_10 -> V_94 = 1 ;
else
V_10 -> V_76 |= V_96 ;
if ( V_106 ) {
if ( V_10 -> V_54 )
F_58 ( V_10 -> V_54 , V_106 ) ;
}
}
static int F_59 ( struct V_26 * V_27 , struct V_26 * V_106 ,
int V_111 )
{
struct V_9 * V_10 ;
int V_112 = - V_113 ;
F_12 ( & V_21 ) ;
F_17 (block, &nlm_blocked, b_list) {
if ( F_18 ( & V_10 -> V_32 -> V_33 . V_25 . V_27 , V_27 ) ) {
F_3 ( L_22 ,
V_10 , V_10 -> V_76 ) ;
if ( V_10 -> V_76 & V_77 ) {
if ( V_10 -> V_76 & V_96 ) {
V_112 = - V_114 ;
break;
}
F_57 ( V_10 , V_106 , V_111 ) ;
} else if ( V_111 == 0 )
V_10 -> V_94 = 1 ;
F_2 ( V_10 , 0 ) ;
F_60 ( V_10 -> V_51 ) ;
V_112 = 0 ;
break;
}
}
F_13 ( & V_21 ) ;
if ( V_112 == - V_113 )
F_61 ( V_115 L_23 ) ;
return V_112 ;
}
static void
F_62 ( struct V_26 * V_27 )
{
struct V_9 * V_10 ;
F_3 ( L_24 , V_27 ) ;
F_12 ( & V_21 ) ;
F_17 (block, &nlm_blocked, b_list) {
if ( F_18 ( & V_10 -> V_32 -> V_33 . V_25 . V_27 , V_27 ) ) {
F_2 ( V_10 , 0 ) ;
F_13 ( & V_21 ) ;
F_60 ( V_10 -> V_51 ) ;
return;
}
}
F_13 ( & V_21 ) ;
F_61 ( V_115 L_25 ) ;
}
static int F_63 ( struct V_26 * V_116 , struct V_26 * V_117 )
{
return V_116 -> V_118 == V_117 -> V_118 && V_116 -> V_28 == V_117 -> V_28 ;
}
static void
F_64 ( struct V_9 * V_10 )
{
struct V_22 * V_23 = V_10 -> V_34 ;
struct V_24 * V_25 = & V_10 -> V_32 -> V_33 . V_25 ;
int error ;
F_3 ( L_26 , V_10 ) ;
F_5 ( & V_10 -> V_16 ) ;
F_31 ( V_10 ) ;
if ( V_10 -> V_94 ) {
F_65 ( V_10 -> V_53 ) ;
goto V_119;
}
V_25 -> V_27 . V_47 |= V_48 ;
error = F_51 ( V_23 -> V_61 , V_99 , & V_25 -> V_27 , NULL ) ;
V_25 -> V_27 . V_47 &= ~ V_48 ;
switch ( error ) {
case 0 :
break;
case V_101 :
F_3 ( L_27 , error ) ;
F_11 ( V_10 , V_18 ) ;
F_15 ( V_10 ) ;
return;
default:
F_61 ( V_115 L_28 ,
- error , V_120 ) ;
F_11 ( V_10 , 10 * V_121 ) ;
F_15 ( V_10 ) ;
return;
}
V_119:
F_3 ( L_29 ) ;
V_10 -> V_94 = 1 ;
F_11 ( V_10 , V_18 ) ;
error = F_66 ( V_10 -> V_32 , V_122 ,
& V_123 ) ;
if ( error < 0 )
F_11 ( V_10 , 10 * V_121 ) ;
}
static void F_67 ( struct V_124 * V_125 , void * V_8 )
{
struct V_41 * V_42 = V_8 ;
struct V_9 * V_10 = V_42 -> V_59 ;
unsigned long V_126 ;
F_3 ( L_30 ) ;
F_12 ( & V_21 ) ;
if ( F_4 ( & V_10 -> V_15 ) )
goto V_93;
if ( V_125 -> V_127 < 0 ) {
V_126 = 10 * V_121 ;
} else {
V_126 = 60 * V_121 ;
}
F_2 ( V_10 , V_126 ) ;
F_60 ( V_10 -> V_51 ) ;
V_93:
F_13 ( & V_21 ) ;
}
static void F_68 ( void * V_8 )
{
struct V_41 * V_42 = V_8 ;
F_15 ( V_42 -> V_59 ) ;
}
void
F_69 ( struct V_1 * V_2 , T_2 V_60 )
{
struct V_9 * V_10 ;
F_3 ( L_31 ,
* ( unsigned int * ) ( V_2 -> V_8 ) , V_60 ) ;
if ( ! ( V_10 = F_20 ( V_2 ) ) )
return;
if ( V_10 ) {
if ( V_60 == V_98 ) {
F_11 ( V_10 , 10 * V_121 ) ;
} else {
F_31 ( V_10 ) ;
}
}
F_15 ( V_10 ) ;
}
static void
F_70 ( struct V_9 * V_10 )
{
if ( ! ( V_10 -> V_76 & V_107 ) )
V_10 -> V_76 |= V_96 ;
F_11 ( V_10 , V_78 ) ;
F_3 ( L_32 , V_10 , V_10 -> V_76 ) ;
if ( V_10 -> V_82 ) {
V_10 -> V_82 -> V_128 ( V_10 -> V_82 , 0 ) ;
V_10 -> V_82 = NULL ;
}
}
unsigned long
F_71 ( void )
{
unsigned long V_126 = V_129 ;
struct V_9 * V_10 ;
while ( ! F_4 ( & V_17 ) && ! F_72 () ) {
V_10 = F_8 ( V_17 . V_65 , struct V_9 , V_15 ) ;
if ( V_10 -> V_20 == V_18 )
break;
if ( F_9 ( V_10 -> V_20 , V_19 ) ) {
V_126 = V_10 -> V_20 - V_19 ;
break;
}
F_3 ( L_33 ,
V_10 , V_10 -> V_20 ) ;
if ( V_10 -> V_76 & V_77 ) {
F_3 ( L_34 ,
V_10 , V_10 -> V_94 , V_10 -> V_76 ) ;
F_70 ( V_10 ) ;
} else
F_64 ( V_10 ) ;
}
return V_126 ;
}
