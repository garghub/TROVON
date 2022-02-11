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
V_23 -> V_54 ++ ;
F_28 ( & V_10 -> V_45 , & V_23 -> V_55 ) ;
V_10 -> V_32 = V_42 ;
V_42 -> V_56 = V_57 ;
V_42 -> V_58 = V_10 ;
return V_10 ;
V_46:
F_29 ( V_10 ) ;
V_44:
F_30 ( V_42 ) ;
return NULL ;
}
static int F_31 ( struct V_9 * V_10 )
{
int V_59 ;
F_3 ( L_9 , V_10 ) ;
V_59 = F_32 ( & V_10 -> V_32 -> V_33 . V_25 . V_27 ) ;
F_14 ( V_10 ) ;
return V_59 ;
}
static void F_33 ( struct V_60 * V_60 )
{
struct V_9 * V_10 = F_34 ( V_60 , struct V_9 , V_16 ) ;
struct V_22 * V_23 = V_10 -> V_34 ;
F_3 ( L_10 , V_10 ) ;
F_6 ( & V_10 -> V_45 ) ;
F_35 ( & V_23 -> V_61 ) ;
F_36 ( V_10 -> V_32 ) ;
F_30 ( V_10 -> V_32 ) ;
F_37 ( V_10 -> V_34 ) ;
F_29 ( V_10 ) ;
}
static void F_15 ( struct V_9 * V_10 )
{
if ( V_10 != NULL )
F_38 ( & V_10 -> V_16 , F_33 , & V_10 -> V_34 -> V_61 ) ;
}
void F_39 ( struct V_39 * V_40 ,
struct V_22 * V_23 ,
T_1 V_62 )
{
struct V_9 * V_10 , * V_63 ;
V_64:
F_40 ( & V_23 -> V_61 ) ;
F_41 (block, next, &file->f_blocks, b_flist) {
if ( ! V_62 ( V_10 -> V_53 , V_40 ) )
continue;
if ( F_4 ( & V_10 -> V_15 ) )
continue;
F_5 ( & V_10 -> V_16 ) ;
F_35 ( & V_23 -> V_61 ) ;
F_31 ( V_10 ) ;
F_15 ( V_10 ) ;
goto V_64;
}
F_35 ( & V_23 -> V_61 ) ;
}
static int F_26 ( struct V_41 * V_42 , struct V_24 * V_25 )
{
F_42 ( & V_42 -> V_33 . V_25 . V_27 , & V_25 -> V_27 ) ;
memcpy ( & V_42 -> V_33 . V_25 . V_65 , & V_25 -> V_65 , sizeof( V_42 -> V_33 . V_25 . V_65 ) ) ;
V_42 -> V_33 . V_25 . V_66 = F_43 () -> V_67 ;
V_42 -> V_33 . V_25 . V_68 . V_6 = V_25 -> V_68 . V_6 ;
V_42 -> V_33 . V_25 . V_68 . V_8 = V_42 -> V_69 ;
V_42 -> V_33 . V_25 . V_70 = V_25 -> V_27 . V_28 ;
if ( V_25 -> V_68 . V_6 > V_71 ) {
void * V_8 = F_44 ( V_25 -> V_68 . V_6 , V_43 ) ;
if ( ! V_8 )
return 0 ;
V_42 -> V_33 . V_25 . V_68 . V_8 = ( V_72 * ) V_8 ;
}
memcpy ( V_42 -> V_33 . V_25 . V_68 . V_8 , V_25 -> V_68 . V_8 , V_25 -> V_68 . V_6 ) ;
return 1 ;
}
static void F_36 ( struct V_41 * V_42 )
{
if ( V_42 -> V_33 . V_25 . V_68 . V_8 != V_42 -> V_69 )
F_29 ( V_42 -> V_33 . V_25 . V_68 . V_8 ) ;
F_45 ( & V_42 -> V_33 . V_25 . V_27 ) ;
}
static T_2
F_46 ( struct V_37 * V_38 , struct V_9 * V_10 )
{
T_2 V_59 = V_73 ;
V_10 -> V_74 |= V_75 ;
F_11 ( V_10 , V_76 ) ;
V_10 -> V_77 = & V_38 -> V_78 ;
if ( V_38 -> V_78 . V_79 ) {
V_10 -> V_80 =
V_38 -> V_78 . V_79 ( V_10 -> V_77 ) ;
if ( V_10 -> V_80 != NULL )
V_59 = V_81 ;
}
F_3 ( L_11 ,
V_10 , V_10 -> V_74 , F_47 ( V_59 ) ) ;
return V_59 ;
}
T_2
F_48 ( struct V_37 * V_38 , struct V_22 * V_23 ,
struct V_39 * V_40 , struct V_24 * V_25 , int V_82 ,
struct V_1 * V_2 , int V_83 )
{
struct V_9 * V_10 = NULL ;
int error ;
T_2 V_84 ;
F_3 ( L_12 ,
F_49 ( V_23 -> V_85 ) -> V_86 -> V_87 ,
F_49 ( V_23 -> V_85 ) -> V_88 ,
V_25 -> V_27 . V_31 , V_25 -> V_27 . V_28 ,
( long long ) V_25 -> V_27 . V_29 ,
( long long ) V_25 -> V_27 . V_30 ,
V_82 ) ;
F_40 ( & V_23 -> V_61 ) ;
V_10 = F_16 ( V_23 , V_25 ) ;
if ( V_10 == NULL ) {
V_10 = F_21 ( V_38 , V_40 , V_23 , V_25 , V_2 ) ;
V_84 = V_73 ;
if ( V_10 == NULL )
goto V_89;
V_25 = & V_10 -> V_32 -> V_33 . V_25 ;
} else
V_25 -> V_27 . V_47 &= ~ V_48 ;
if ( V_10 -> V_74 & V_75 ) {
F_3 ( L_13 ,
V_10 , V_10 -> V_74 ) ;
if ( V_10 -> V_90 ) {
F_31 ( V_10 ) ;
V_84 = V_91 ;
goto V_89;
}
if ( V_10 -> V_74 & V_92 ) {
F_31 ( V_10 ) ;
V_84 = V_93 ;
goto V_89;
}
V_84 = V_81 ;
goto V_89;
}
if ( F_50 ( F_51 ( V_38 ) ) && ! V_83 ) {
V_84 = V_94 ;
goto V_89;
}
if ( V_83 && ! F_50 ( F_51 ( V_38 ) ) ) {
V_84 = V_94 ;
goto V_89;
}
if ( ! V_82 )
V_25 -> V_27 . V_47 &= ~ V_48 ;
error = F_52 ( V_23 -> V_85 , V_95 , & V_25 -> V_27 , NULL ) ;
V_25 -> V_27 . V_47 &= ~ V_48 ;
F_3 ( L_14 , error ) ;
switch ( error ) {
case 0 :
V_84 = V_91 ;
goto V_89;
case - V_96 :
if ( V_82 )
break;
V_84 = V_93 ;
goto V_89;
case V_97 :
if ( V_82 )
break;
V_84 = F_46 ( V_38 , V_10 ) ;
goto V_89;
case - V_98 :
V_84 = V_99 ;
goto V_89;
default:
V_84 = V_73 ;
goto V_89;
}
V_84 = V_100 ;
F_11 ( V_10 , V_18 ) ;
V_89:
F_35 ( & V_23 -> V_61 ) ;
F_15 ( V_10 ) ;
F_3 ( L_15 , V_84 ) ;
return V_84 ;
}
T_2
F_53 ( struct V_37 * V_38 , struct V_22 * V_23 ,
struct V_39 * V_40 , struct V_24 * V_25 ,
struct V_24 * V_101 , struct V_1 * V_2 )
{
int error ;
T_2 V_84 ;
F_3 ( L_16 ,
F_49 ( V_23 -> V_85 ) -> V_86 -> V_87 ,
F_49 ( V_23 -> V_85 ) -> V_88 ,
V_25 -> V_27 . V_31 ,
( long long ) V_25 -> V_27 . V_29 ,
( long long ) V_25 -> V_27 . V_30 ) ;
if ( F_50 ( F_51 ( V_38 ) ) ) {
V_84 = V_94 ;
goto V_89;
}
error = F_54 ( V_23 -> V_85 , & V_25 -> V_27 ) ;
if ( error ) {
if ( error == V_97 )
F_55 ( 1 ) ;
V_84 = V_73 ;
goto V_89;
}
if ( V_25 -> V_27 . V_31 == V_102 ) {
V_84 = V_91 ;
goto V_89;
}
F_3 ( L_17 ,
V_25 -> V_27 . V_31 , ( long long ) V_25 -> V_27 . V_29 ,
( long long ) V_25 -> V_27 . V_30 ) ;
V_101 -> V_66 = L_18 ;
V_101 -> V_6 = strlen ( V_101 -> V_66 ) ;
V_101 -> V_68 . V_6 = 0 ;
V_101 -> V_70 = V_25 -> V_27 . V_28 ;
V_101 -> V_27 . V_31 = V_25 -> V_27 . V_31 ;
V_101 -> V_27 . V_29 = V_25 -> V_27 . V_29 ;
V_101 -> V_27 . V_30 = V_25 -> V_27 . V_30 ;
F_45 ( & V_25 -> V_27 ) ;
V_84 = V_93 ;
V_89:
return V_84 ;
}
T_2
F_56 ( struct V_103 * V_103 , struct V_22 * V_23 , struct V_24 * V_25 )
{
int error ;
F_3 ( L_19 ,
F_49 ( V_23 -> V_85 ) -> V_86 -> V_87 ,
F_49 ( V_23 -> V_85 ) -> V_88 ,
V_25 -> V_27 . V_28 ,
( long long ) V_25 -> V_27 . V_29 ,
( long long ) V_25 -> V_27 . V_30 ) ;
F_57 ( V_103 , V_23 , V_25 ) ;
V_25 -> V_27 . V_31 = V_102 ;
error = F_52 ( V_23 -> V_85 , V_95 , & V_25 -> V_27 , NULL ) ;
return ( error < 0 ) ? V_73 : V_91 ;
}
T_2
F_57 ( struct V_103 * V_103 , struct V_22 * V_23 , struct V_24 * V_25 )
{
struct V_9 * V_10 ;
int V_59 = 0 ;
F_3 ( L_20 ,
F_49 ( V_23 -> V_85 ) -> V_86 -> V_87 ,
F_49 ( V_23 -> V_85 ) -> V_88 ,
V_25 -> V_27 . V_28 ,
( long long ) V_25 -> V_27 . V_29 ,
( long long ) V_25 -> V_27 . V_30 ) ;
if ( F_50 ( V_103 ) )
return V_94 ;
F_40 ( & V_23 -> V_61 ) ;
V_10 = F_16 ( V_23 , V_25 ) ;
F_35 ( & V_23 -> V_61 ) ;
if ( V_10 != NULL ) {
F_58 ( V_10 -> V_34 -> V_85 ,
& V_10 -> V_32 -> V_33 . V_25 . V_27 ) ;
V_59 = F_31 ( V_10 ) ;
F_15 ( V_10 ) ;
}
return V_59 ? V_93 : V_91 ;
}
static void
F_59 ( struct V_9 * V_10 , int V_104 )
{
V_10 -> V_74 |= V_105 ;
if ( V_104 == 0 )
V_10 -> V_90 = 1 ;
else
V_10 -> V_74 |= V_92 ;
}
static int F_60 ( struct V_26 * V_27 , int V_104 )
{
struct V_9 * V_10 ;
int V_106 = - V_107 ;
F_12 ( & V_21 ) ;
F_17 (block, &nlm_blocked, b_list) {
if ( F_18 ( & V_10 -> V_32 -> V_33 . V_25 . V_27 , V_27 ) ) {
F_3 ( L_21 ,
V_10 , V_10 -> V_74 ) ;
if ( V_10 -> V_74 & V_75 ) {
if ( V_10 -> V_74 & V_92 ) {
V_106 = - V_108 ;
break;
}
F_59 ( V_10 , V_104 ) ;
} else if ( V_104 == 0 )
V_10 -> V_90 = 1 ;
F_2 ( V_10 , 0 ) ;
F_61 ( V_10 -> V_51 ) ;
V_106 = 0 ;
break;
}
}
F_13 ( & V_21 ) ;
if ( V_106 == - V_107 )
F_62 ( V_109 L_22 ) ;
return V_106 ;
}
static void
F_63 ( struct V_26 * V_27 )
{
struct V_9 * V_10 ;
F_3 ( L_23 , V_27 ) ;
F_12 ( & V_21 ) ;
F_17 (block, &nlm_blocked, b_list) {
if ( F_18 ( & V_10 -> V_32 -> V_33 . V_25 . V_27 , V_27 ) ) {
F_2 ( V_10 , 0 ) ;
F_13 ( & V_21 ) ;
F_61 ( V_10 -> V_51 ) ;
return;
}
}
F_13 ( & V_21 ) ;
F_62 ( V_109 L_24 ) ;
}
static int F_64 ( struct V_26 * V_110 , struct V_26 * V_111 )
{
return V_110 -> V_112 == V_111 -> V_112 && V_110 -> V_28 == V_111 -> V_28 ;
}
static unsigned long
F_65 ( struct V_26 * V_27 )
{
return ( unsigned long ) V_27 -> V_112 ^ ( unsigned long ) V_27 -> V_28 ;
}
static void
F_66 ( struct V_9 * V_10 )
{
struct V_22 * V_23 = V_10 -> V_34 ;
struct V_24 * V_25 = & V_10 -> V_32 -> V_33 . V_25 ;
int error ;
T_3 V_29 , V_30 ;
F_3 ( L_25 , V_10 ) ;
F_5 ( & V_10 -> V_16 ) ;
F_31 ( V_10 ) ;
if ( V_10 -> V_90 ) {
F_67 ( V_10 -> V_53 ) ;
goto V_113;
}
V_25 -> V_27 . V_47 |= V_48 ;
V_29 = V_25 -> V_27 . V_29 ;
V_30 = V_25 -> V_27 . V_30 ;
error = F_52 ( V_23 -> V_85 , V_95 , & V_25 -> V_27 , NULL ) ;
V_25 -> V_27 . V_47 &= ~ V_48 ;
V_25 -> V_27 . V_29 = V_29 ;
V_25 -> V_27 . V_30 = V_30 ;
switch ( error ) {
case 0 :
break;
case V_97 :
F_3 ( L_26 , error ) ;
F_11 ( V_10 , V_18 ) ;
F_15 ( V_10 ) ;
return;
default:
F_62 ( V_109 L_27 ,
- error , V_114 ) ;
F_11 ( V_10 , 10 * V_115 ) ;
F_15 ( V_10 ) ;
return;
}
V_113:
F_3 ( L_28 ) ;
V_10 -> V_90 = 1 ;
F_11 ( V_10 , V_18 ) ;
error = F_68 ( V_10 -> V_32 , V_116 ,
& V_117 ) ;
if ( error < 0 )
F_11 ( V_10 , 10 * V_115 ) ;
}
static void F_69 ( struct V_118 * V_119 , void * V_8 )
{
struct V_41 * V_42 = V_8 ;
struct V_9 * V_10 = V_42 -> V_58 ;
unsigned long V_120 ;
F_3 ( L_29 ) ;
F_12 ( & V_21 ) ;
if ( F_4 ( & V_10 -> V_15 ) )
goto V_89;
if ( V_119 -> V_121 < 0 ) {
V_120 = 10 * V_115 ;
} else {
V_120 = 60 * V_115 ;
}
F_2 ( V_10 , V_120 ) ;
F_61 ( V_10 -> V_51 ) ;
V_89:
F_13 ( & V_21 ) ;
}
static void F_70 ( void * V_8 )
{
struct V_41 * V_42 = V_8 ;
F_15 ( V_42 -> V_58 ) ;
}
void
F_71 ( struct V_1 * V_2 , T_2 V_59 )
{
struct V_9 * V_10 ;
F_3 ( L_30 ,
* ( unsigned int * ) ( V_2 -> V_8 ) , V_59 ) ;
if ( ! ( V_10 = F_20 ( V_2 ) ) )
return;
if ( V_59 == V_94 ) {
F_11 ( V_10 , 10 * V_115 ) ;
} else {
F_31 ( V_10 ) ;
}
F_15 ( V_10 ) ;
}
static void
F_72 ( struct V_9 * V_10 )
{
if ( ! ( V_10 -> V_74 & V_105 ) )
V_10 -> V_74 |= V_92 ;
F_11 ( V_10 , V_76 ) ;
F_3 ( L_31 , V_10 , V_10 -> V_74 ) ;
if ( V_10 -> V_80 ) {
V_10 -> V_80 -> V_122 ( V_10 -> V_80 , 0 ) ;
V_10 -> V_80 = NULL ;
}
}
unsigned long
F_73 ( void )
{
unsigned long V_120 = V_123 ;
struct V_9 * V_10 ;
F_12 ( & V_21 ) ;
while ( ! F_4 ( & V_17 ) && ! F_74 () ) {
V_10 = F_8 ( V_17 . V_63 , struct V_9 , V_15 ) ;
if ( V_10 -> V_20 == V_18 )
break;
if ( F_9 ( V_10 -> V_20 , V_19 ) ) {
V_120 = V_10 -> V_20 - V_19 ;
break;
}
F_13 ( & V_21 ) ;
F_3 ( L_32 ,
V_10 , V_10 -> V_20 ) ;
if ( V_10 -> V_74 & V_75 ) {
F_3 ( L_33 ,
V_10 , V_10 -> V_90 , V_10 -> V_74 ) ;
F_72 ( V_10 ) ;
} else
F_66 ( V_10 ) ;
F_12 ( & V_21 ) ;
}
F_13 ( & V_21 ) ;
return V_120 ;
}
