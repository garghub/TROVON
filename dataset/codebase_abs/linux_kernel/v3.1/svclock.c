static void
F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 ;
F_2 ( L_1 , V_2 , V_3 ) ;
if ( F_3 ( & V_2 -> V_7 ) ) {
F_4 ( & V_2 -> V_8 ) ;
} else {
F_5 ( & V_2 -> V_7 ) ;
}
V_6 = & V_9 ;
if ( V_3 != V_10 ) {
if ( ( V_3 += V_11 ) == V_10 )
V_3 ++ ;
F_6 (pos, &nlm_blocked) {
V_4 = F_7 ( V_6 , struct V_1 , V_7 ) ;
if ( F_8 ( V_4 -> V_12 , V_3 ) || V_4 -> V_12 == V_10 )
break;
}
}
F_9 ( & V_2 -> V_7 , V_6 ) ;
V_2 -> V_12 = V_3 ;
}
static void F_10 ( struct V_1 * V_2 , unsigned long V_3 )
{
F_11 ( & V_13 ) ;
F_1 ( V_2 , V_3 ) ;
F_12 ( & V_13 ) ;
}
static inline void
F_13 ( struct V_1 * V_2 )
{
if ( ! F_3 ( & V_2 -> V_7 ) ) {
F_11 ( & V_13 ) ;
F_5 ( & V_2 -> V_7 ) ;
F_12 ( & V_13 ) ;
F_14 ( V_2 ) ;
}
}
static struct V_1 *
F_15 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_18 * V_19 ;
F_2 ( L_2 ,
V_15 , V_17 -> V_19 . V_20 ,
( long long ) V_17 -> V_19 . V_21 ,
( long long ) V_17 -> V_19 . V_22 , V_17 -> V_19 . V_23 ) ;
F_16 (block, &nlm_blocked, b_list) {
V_19 = & V_2 -> V_24 -> V_25 . V_17 . V_19 ;
F_2 ( L_3 ,
V_2 -> V_26 , V_19 -> V_20 ,
( long long ) V_19 -> V_21 ,
( long long ) V_19 -> V_22 , V_19 -> V_23 ,
F_17 ( & V_2 -> V_24 -> V_25 . V_27 ) ) ;
if ( V_2 -> V_26 == V_15 && F_18 ( V_19 , & V_17 -> V_19 ) ) {
F_4 ( & V_2 -> V_8 ) ;
return V_2 ;
}
}
return NULL ;
}
static inline int F_19 ( struct V_28 * V_29 , struct V_28 * V_4 )
{
if ( V_29 -> V_30 != V_4 -> V_30 )
return 0 ;
if ( memcmp ( V_29 -> V_31 , V_4 -> V_31 , V_29 -> V_30 ) )
return 0 ;
return 1 ;
}
static inline struct V_1 *
F_20 ( struct V_28 * V_27 )
{
struct V_1 * V_2 ;
F_16 (block, &nlm_blocked, b_list) {
if ( F_19 ( & V_2 -> V_24 -> V_25 . V_27 , V_27 ) )
goto V_32;
}
return NULL ;
V_32:
F_2 ( L_4 , F_17 ( V_27 ) , V_2 ) ;
F_4 ( & V_2 -> V_8 ) ;
return V_2 ;
}
static struct V_1 *
F_21 ( struct V_33 * V_34 , struct V_35 * V_36 ,
struct V_14 * V_15 , struct V_16 * V_17 ,
struct V_28 * V_27 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 = NULL ;
F_22 ( V_36 ) ;
V_38 = F_23 ( V_36 ) ;
if ( V_38 == NULL )
return NULL ;
V_2 = F_24 ( sizeof( * V_2 ) , V_39 ) ;
if ( V_2 == NULL )
goto V_40;
F_25 ( & V_2 -> V_8 ) ;
F_26 ( & V_2 -> V_7 ) ;
F_26 ( & V_2 -> V_41 ) ;
if ( ! F_27 ( V_38 , V_17 ) )
goto V_42;
V_38 -> V_25 . V_17 . V_19 . V_43 |= V_44 ;
V_38 -> V_25 . V_17 . V_19 . V_45 = & V_46 ;
F_28 ( & V_38 -> V_25 . V_27 ) ;
F_2 ( L_5 , V_2 ) ;
V_2 -> V_47 = V_34 -> V_48 ;
V_2 -> V_49 = V_36 ;
V_2 -> V_26 = V_15 ;
V_2 -> V_50 = NULL ;
V_15 -> V_51 ++ ;
F_29 ( & V_2 -> V_41 , & V_15 -> V_52 ) ;
V_2 -> V_24 = V_38 ;
V_38 -> V_53 = V_54 ;
V_38 -> V_55 = V_2 ;
return V_2 ;
V_42:
F_30 ( V_2 ) ;
V_40:
F_31 ( V_38 ) ;
return NULL ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_56 ;
F_2 ( L_6 , V_2 ) ;
V_56 = F_33 ( V_2 -> V_26 -> V_57 , & V_2 -> V_24 -> V_25 . V_17 . V_19 ) ;
F_13 ( V_2 ) ;
return V_56 ;
}
static void F_34 ( struct V_58 * V_58 )
{
struct V_1 * V_2 = F_35 ( V_58 , struct V_1 , V_8 ) ;
struct V_14 * V_15 = V_2 -> V_26 ;
F_2 ( L_7 , V_2 ) ;
F_36 ( & V_15 -> V_59 ) ;
F_5 ( & V_2 -> V_41 ) ;
F_37 ( & V_15 -> V_59 ) ;
F_38 ( V_2 -> V_24 ) ;
F_31 ( V_2 -> V_24 ) ;
F_39 ( V_2 -> V_26 ) ;
F_30 ( V_2 -> V_50 ) ;
F_30 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 != NULL )
F_40 ( & V_2 -> V_8 , F_34 ) ;
}
void F_41 ( struct V_35 * V_36 ,
struct V_14 * V_15 ,
T_1 V_60 )
{
struct V_1 * V_2 , * V_61 ;
V_62:
F_36 ( & V_15 -> V_59 ) ;
F_42 (block, next, &file->f_blocks, b_flist) {
if ( ! V_60 ( V_2 -> V_49 , V_36 ) )
continue;
if ( F_3 ( & V_2 -> V_7 ) )
continue;
F_4 ( & V_2 -> V_8 ) ;
F_37 ( & V_15 -> V_59 ) ;
F_32 ( V_2 ) ;
F_14 ( V_2 ) ;
goto V_62;
}
F_37 ( & V_15 -> V_59 ) ;
}
static int F_27 ( struct V_37 * V_38 , struct V_16 * V_17 )
{
F_43 ( & V_38 -> V_25 . V_17 . V_19 , & V_17 -> V_19 ) ;
memcpy ( & V_38 -> V_25 . V_17 . V_63 , & V_17 -> V_63 , sizeof( V_38 -> V_25 . V_17 . V_63 ) ) ;
V_38 -> V_25 . V_17 . V_64 = F_44 () -> V_65 ;
V_38 -> V_25 . V_17 . V_66 . V_30 = V_17 -> V_66 . V_30 ;
V_38 -> V_25 . V_17 . V_66 . V_31 = V_38 -> V_67 ;
V_38 -> V_25 . V_17 . V_68 = V_17 -> V_19 . V_20 ;
if ( V_17 -> V_66 . V_30 > V_69 ) {
void * V_31 = F_45 ( V_17 -> V_66 . V_30 , V_39 ) ;
if ( ! V_31 )
return 0 ;
V_38 -> V_25 . V_17 . V_66 . V_31 = ( V_70 * ) V_31 ;
}
memcpy ( V_38 -> V_25 . V_17 . V_66 . V_31 , V_17 -> V_66 . V_31 , V_17 -> V_66 . V_30 ) ;
return 1 ;
}
static void F_38 ( struct V_37 * V_38 )
{
if ( V_38 -> V_25 . V_17 . V_66 . V_31 != V_38 -> V_67 )
F_30 ( V_38 -> V_25 . V_17 . V_66 . V_31 ) ;
F_46 ( & V_38 -> V_25 . V_17 . V_19 ) ;
}
static T_2
F_47 ( struct V_33 * V_34 , struct V_1 * V_2 )
{
T_2 V_56 = V_71 ;
V_2 -> V_72 |= V_73 ;
F_10 ( V_2 , V_74 ) ;
V_2 -> V_75 = & V_34 -> V_76 ;
if ( V_34 -> V_76 . V_77 ) {
V_2 -> V_78 =
V_34 -> V_76 . V_77 ( V_2 -> V_75 ) ;
if ( V_2 -> V_78 != NULL )
V_56 = V_79 ;
}
F_2 ( L_8 ,
V_2 , V_2 -> V_72 , F_48 ( V_56 ) ) ;
return V_56 ;
}
T_2
F_49 ( struct V_33 * V_34 , struct V_14 * V_15 ,
struct V_35 * V_36 , struct V_16 * V_17 , int V_80 ,
struct V_28 * V_27 , int V_81 )
{
struct V_1 * V_2 = NULL ;
int error ;
T_2 V_82 ;
F_2 ( L_9 ,
V_15 -> V_57 -> V_83 . V_84 -> V_85 -> V_86 -> V_87 ,
V_15 -> V_57 -> V_83 . V_84 -> V_85 -> V_88 ,
V_17 -> V_19 . V_23 , V_17 -> V_19 . V_20 ,
( long long ) V_17 -> V_19 . V_21 ,
( long long ) V_17 -> V_19 . V_22 ,
V_80 ) ;
F_36 ( & V_15 -> V_59 ) ;
V_2 = F_15 ( V_15 , V_17 ) ;
if ( V_2 == NULL ) {
V_2 = F_21 ( V_34 , V_36 , V_15 , V_17 , V_27 ) ;
V_82 = V_71 ;
if ( V_2 == NULL )
goto V_89;
V_17 = & V_2 -> V_24 -> V_25 . V_17 ;
} else
V_17 -> V_19 . V_43 &= ~ V_44 ;
if ( V_2 -> V_72 & V_73 ) {
F_2 ( L_10 ,
V_2 , V_2 -> V_72 ) ;
if ( V_2 -> V_90 ) {
F_32 ( V_2 ) ;
V_82 = V_91 ;
goto V_89;
}
if ( V_2 -> V_72 & V_92 ) {
F_32 ( V_2 ) ;
V_82 = V_93 ;
goto V_89;
}
V_82 = V_79 ;
goto V_89;
}
if ( F_50 () && ! V_81 ) {
V_82 = V_94 ;
goto V_89;
}
if ( V_81 && ! F_50 () ) {
V_82 = V_94 ;
goto V_89;
}
if ( ! V_80 )
V_17 -> V_19 . V_43 &= ~ V_44 ;
error = F_51 ( V_15 -> V_57 , V_95 , & V_17 -> V_19 , NULL ) ;
V_17 -> V_19 . V_43 &= ~ V_44 ;
F_2 ( L_11 , error ) ;
switch ( error ) {
case 0 :
V_82 = V_91 ;
goto V_89;
case - V_96 :
if ( V_80 )
break;
V_82 = V_93 ;
goto V_89;
case V_97 :
if ( V_80 )
break;
V_82 = F_47 ( V_34 , V_2 ) ;
goto V_89;
case - V_98 :
V_82 = V_99 ;
goto V_89;
default:
V_82 = V_71 ;
goto V_89;
}
V_82 = V_100 ;
F_10 ( V_2 , V_10 ) ;
V_89:
F_37 ( & V_15 -> V_59 ) ;
F_14 ( V_2 ) ;
F_2 ( L_12 , V_82 ) ;
return V_82 ;
}
T_2
F_52 ( struct V_33 * V_34 , struct V_14 * V_15 ,
struct V_35 * V_36 , struct V_16 * V_17 ,
struct V_16 * V_101 , struct V_28 * V_27 )
{
struct V_1 * V_2 = NULL ;
int error ;
T_2 V_82 ;
F_2 ( L_13 ,
V_15 -> V_57 -> V_83 . V_84 -> V_85 -> V_86 -> V_87 ,
V_15 -> V_57 -> V_83 . V_84 -> V_85 -> V_88 ,
V_17 -> V_19 . V_23 ,
( long long ) V_17 -> V_19 . V_21 ,
( long long ) V_17 -> V_19 . V_22 ) ;
V_2 = F_15 ( V_15 , V_17 ) ;
if ( V_2 == NULL ) {
struct V_18 * V_102 = F_24 ( sizeof( * V_102 ) , V_39 ) ;
if ( V_102 == NULL )
return V_91 ;
V_2 = F_21 ( V_34 , V_36 , V_15 , V_17 , V_27 ) ;
if ( V_2 == NULL ) {
F_30 ( V_102 ) ;
return V_91 ;
}
V_2 -> V_50 = V_102 ;
}
if ( V_2 -> V_72 & V_73 ) {
F_2 ( L_14 ,
V_2 , V_2 -> V_72 , V_2 -> V_50 ) ;
if ( V_2 -> V_72 & V_92 ) {
F_32 ( V_2 ) ;
V_82 = V_93 ;
goto V_89;
}
if ( V_2 -> V_72 & V_103 ) {
F_32 ( V_2 ) ;
if ( V_2 -> V_50 != NULL
&& V_2 -> V_50 -> V_23 != V_104 ) {
V_17 -> V_19 = * V_2 -> V_50 ;
goto V_105;
} else {
V_82 = V_91 ;
goto V_89;
}
}
V_82 = V_79 ;
goto V_89;
}
if ( F_50 () ) {
V_82 = V_94 ;
goto V_89;
}
error = F_53 ( V_15 -> V_57 , & V_17 -> V_19 ) ;
if ( error == V_97 ) {
V_82 = F_47 ( V_34 , V_2 ) ;
goto V_89;
}
if ( error ) {
V_82 = V_71 ;
goto V_89;
}
if ( V_17 -> V_19 . V_23 == V_104 ) {
V_82 = V_91 ;
goto V_89;
}
V_105:
F_2 ( L_15 ,
V_17 -> V_19 . V_23 , ( long long ) V_17 -> V_19 . V_21 ,
( long long ) V_17 -> V_19 . V_22 ) ;
V_101 -> V_64 = L_16 ;
V_101 -> V_30 = strlen ( V_101 -> V_64 ) ;
V_101 -> V_66 . V_30 = 0 ;
V_101 -> V_68 = V_17 -> V_19 . V_20 ;
V_101 -> V_19 . V_23 = V_17 -> V_19 . V_23 ;
V_101 -> V_19 . V_21 = V_17 -> V_19 . V_21 ;
V_101 -> V_19 . V_22 = V_17 -> V_19 . V_22 ;
V_82 = V_93 ;
V_89:
if ( V_2 )
F_14 ( V_2 ) ;
return V_82 ;
}
T_2
F_54 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
int error ;
F_2 ( L_17 ,
V_15 -> V_57 -> V_83 . V_84 -> V_85 -> V_86 -> V_87 ,
V_15 -> V_57 -> V_83 . V_84 -> V_85 -> V_88 ,
V_17 -> V_19 . V_20 ,
( long long ) V_17 -> V_19 . V_21 ,
( long long ) V_17 -> V_19 . V_22 ) ;
F_55 ( V_15 , V_17 ) ;
V_17 -> V_19 . V_23 = V_104 ;
error = F_51 ( V_15 -> V_57 , V_95 , & V_17 -> V_19 , NULL ) ;
return ( error < 0 ) ? V_71 : V_91 ;
}
T_2
F_55 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
struct V_1 * V_2 ;
int V_56 = 0 ;
F_2 ( L_18 ,
V_15 -> V_57 -> V_83 . V_84 -> V_85 -> V_86 -> V_87 ,
V_15 -> V_57 -> V_83 . V_84 -> V_85 -> V_88 ,
V_17 -> V_19 . V_20 ,
( long long ) V_17 -> V_19 . V_21 ,
( long long ) V_17 -> V_19 . V_22 ) ;
if ( F_50 () )
return V_94 ;
F_36 ( & V_15 -> V_59 ) ;
V_2 = F_15 ( V_15 , V_17 ) ;
F_37 ( & V_15 -> V_59 ) ;
if ( V_2 != NULL ) {
F_56 ( V_2 -> V_26 -> V_57 ,
& V_2 -> V_24 -> V_25 . V_17 . V_19 ) ;
V_56 = F_32 ( V_2 ) ;
F_14 ( V_2 ) ;
}
return V_56 ? V_93 : V_91 ;
}
static void
F_57 ( struct V_1 * V_2 , struct V_18 * V_102 ,
int V_106 )
{
V_2 -> V_72 |= V_103 ;
if ( V_106 == 0 )
V_2 -> V_90 = 1 ;
else
V_2 -> V_72 |= V_92 ;
if ( V_102 ) {
if ( V_2 -> V_50 )
F_58 ( V_2 -> V_50 , V_102 ) ;
}
}
static int F_59 ( struct V_18 * V_19 , struct V_18 * V_102 ,
int V_106 )
{
struct V_1 * V_2 ;
int V_107 = - V_108 ;
F_11 ( & V_13 ) ;
F_16 (block, &nlm_blocked, b_list) {
if ( F_18 ( & V_2 -> V_24 -> V_25 . V_17 . V_19 , V_19 ) ) {
F_2 ( L_19 ,
V_2 , V_2 -> V_72 ) ;
if ( V_2 -> V_72 & V_73 ) {
if ( V_2 -> V_72 & V_92 ) {
V_107 = - V_109 ;
break;
}
F_57 ( V_2 , V_102 , V_106 ) ;
} else if ( V_106 == 0 )
V_2 -> V_90 = 1 ;
F_1 ( V_2 , 0 ) ;
F_60 ( V_2 -> V_47 ) ;
V_107 = 0 ;
break;
}
}
F_12 ( & V_13 ) ;
if ( V_107 == - V_108 )
F_61 ( V_110 L_20 ) ;
return V_107 ;
}
static void
F_62 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
F_2 ( L_21 , V_19 ) ;
F_11 ( & V_13 ) ;
F_16 (block, &nlm_blocked, b_list) {
if ( F_18 ( & V_2 -> V_24 -> V_25 . V_17 . V_19 , V_19 ) ) {
F_1 ( V_2 , 0 ) ;
F_12 ( & V_13 ) ;
F_60 ( V_2 -> V_47 ) ;
return;
}
}
F_12 ( & V_13 ) ;
F_61 ( V_110 L_22 ) ;
}
static int F_63 ( struct V_18 * V_111 , struct V_18 * V_112 )
{
return V_111 -> V_113 == V_112 -> V_113 && V_111 -> V_20 == V_112 -> V_20 ;
}
static void
F_64 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_26 ;
struct V_16 * V_17 = & V_2 -> V_24 -> V_25 . V_17 ;
int error ;
F_2 ( L_23 , V_2 ) ;
F_4 ( & V_2 -> V_8 ) ;
F_32 ( V_2 ) ;
if ( V_2 -> V_90 ) {
F_65 ( V_2 -> V_49 ) ;
goto V_114;
}
V_17 -> V_19 . V_43 |= V_44 ;
error = F_51 ( V_15 -> V_57 , V_95 , & V_17 -> V_19 , NULL ) ;
V_17 -> V_19 . V_43 &= ~ V_44 ;
switch ( error ) {
case 0 :
break;
case V_97 :
F_2 ( L_24 , error ) ;
F_10 ( V_2 , V_10 ) ;
F_14 ( V_2 ) ;
return;
default:
F_61 ( V_110 L_25 ,
- error , V_115 ) ;
F_10 ( V_2 , 10 * V_116 ) ;
F_14 ( V_2 ) ;
return;
}
V_114:
F_2 ( L_26 ) ;
V_2 -> V_90 = 1 ;
F_10 ( V_2 , V_10 ) ;
error = F_66 ( V_2 -> V_24 , V_117 ,
& V_118 ) ;
if ( error < 0 )
F_10 ( V_2 , 10 * V_116 ) ;
}
static void F_67 ( struct V_119 * V_120 , void * V_31 )
{
struct V_37 * V_38 = V_31 ;
struct V_1 * V_2 = V_38 -> V_55 ;
unsigned long V_121 ;
F_2 ( L_27 ) ;
F_11 ( & V_13 ) ;
if ( F_3 ( & V_2 -> V_7 ) )
goto V_89;
if ( V_120 -> V_122 < 0 ) {
V_121 = 10 * V_116 ;
} else {
V_121 = 60 * V_116 ;
}
F_1 ( V_2 , V_121 ) ;
F_60 ( V_2 -> V_47 ) ;
V_89:
F_12 ( & V_13 ) ;
}
static void F_68 ( void * V_31 )
{
struct V_37 * V_38 = V_31 ;
F_14 ( V_38 -> V_55 ) ;
}
void
F_69 ( struct V_28 * V_27 , T_2 V_56 )
{
struct V_1 * V_2 ;
F_2 ( L_28 ,
* ( unsigned int * ) ( V_27 -> V_31 ) , V_56 ) ;
if ( ! ( V_2 = F_20 ( V_27 ) ) )
return;
if ( V_2 ) {
if ( V_56 == V_94 ) {
F_10 ( V_2 , 10 * V_116 ) ;
} else {
F_32 ( V_2 ) ;
}
}
F_14 ( V_2 ) ;
}
static void
F_70 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_72 & V_103 ) )
V_2 -> V_72 |= V_92 ;
F_10 ( V_2 , V_74 ) ;
F_2 ( L_29 , V_2 , V_2 -> V_72 ) ;
if ( V_2 -> V_78 ) {
V_2 -> V_78 -> V_123 ( V_2 -> V_78 , 0 ) ;
V_2 -> V_78 = NULL ;
}
}
unsigned long
F_71 ( void )
{
unsigned long V_121 = V_124 ;
struct V_1 * V_2 ;
while ( ! F_3 ( & V_9 ) && ! F_72 () ) {
V_2 = F_7 ( V_9 . V_61 , struct V_1 , V_7 ) ;
if ( V_2 -> V_12 == V_10 )
break;
if ( F_8 ( V_2 -> V_12 , V_11 ) ) {
V_121 = V_2 -> V_12 - V_11 ;
break;
}
F_2 ( L_30 ,
V_2 , V_2 -> V_12 ) ;
if ( V_2 -> V_72 & V_73 ) {
F_2 ( L_31 ,
V_2 , V_2 -> V_90 , V_2 -> V_72 ) ;
F_70 ( V_2 ) ;
} else
F_64 ( V_2 ) ;
}
return V_121 ;
}
static const char * F_17 ( const struct V_28 * V_27 )
{
static char V_125 [ 2 * V_126 + 1 ] ;
unsigned int V_127 , V_30 = sizeof( V_125 ) ;
char * V_128 = V_125 ;
V_30 -- ;
if ( V_30 < 3 )
return L_32 ;
for ( V_127 = 0 ; V_127 < V_27 -> V_30 ; V_127 ++ ) {
if ( V_30 < 2 ) {
strcpy ( V_128 - 3 , L_33 ) ;
break;
}
sprintf ( V_128 , L_34 , V_27 -> V_31 [ V_127 ] ) ;
V_128 += 2 ;
V_30 -= 2 ;
}
* V_128 = '\0' ;
return V_125 ;
}
