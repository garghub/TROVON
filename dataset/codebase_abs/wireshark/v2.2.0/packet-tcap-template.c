extern void F_1 ( T_1 V_1 , T_2 V_2 ) {
F_2 ( V_3 , F_3 ( V_1 ) , V_2 ) ;
F_4 ( L_1 , V_1 , V_4 ) ;
}
extern void F_5 ( T_1 V_1 , T_2 V_2 ) {
F_2 ( V_5 , F_3 ( V_1 ) , V_2 ) ;
F_4 ( L_1 , V_1 , V_4 ) ;
}
extern void F_6 ( T_1 V_1 , T_2 V_2 V_6 ) {
F_7 ( V_3 , F_3 ( V_1 ) ) ;
if ( ! F_8 ( V_1 ) )
F_9 ( L_1 , V_1 , V_4 ) ;
}
extern void F_10 ( T_1 V_1 , T_2 V_2 V_6 ) {
F_7 ( V_5 , F_3 ( V_1 ) ) ;
if ( ! F_11 ( V_1 ) )
F_9 ( L_1 , V_1 , V_4 ) ;
}
T_2 F_11 ( T_1 V_1 ) {
return ( T_2 ) F_12 ( V_3 , F_3 ( V_1 ) ) ;
}
T_2 F_8 ( T_1 V_1 ) {
return ( T_2 ) F_12 ( V_5 , F_3 ( V_1 ) ) ;
}
static void
F_13 ( T_3 V_7 , const char * V_8 , ... )
{
T_4 V_9 ;
if ( V_7 > V_10 ) return;
va_start ( V_9 , V_8 ) ;
vfprintf ( V_11 , V_8 , V_9 ) ;
va_end ( V_9 ) ;
}
static T_5
F_14 ( T_6 V_12 , T_6 V_13 )
{
const struct V_14 * V_15 = ( const struct V_14 * ) V_12 ;
const struct V_14 * V_16 = ( const struct V_14 * ) V_13 ;
return ( V_15 -> V_17 == V_16 -> V_17 ) ;
}
static T_3
F_15 ( T_6 V_18 )
{
const struct V_14 * V_19 = ( const struct V_14 * ) V_18 ;
return V_19 -> V_17 ;
}
static T_5
F_16 ( T_6 V_12 , T_6 V_13 )
{
const struct V_20 * V_15 = ( const struct V_20 * ) V_12 ;
const struct V_20 * V_16 = ( const struct V_20 * ) V_13 ;
if ( V_15 -> V_21 == V_16 -> V_21 ) {
if ( ( V_15 -> V_22 == V_16 -> V_22 ) && ( V_15 -> V_23 == V_16 -> V_23 ) )
return TRUE ;
}
return FALSE ;
}
static T_3
F_17 ( T_6 V_18 )
{
const struct V_20 * V_19 = ( const struct V_20 * ) V_18 ;
T_3 V_24 ;
V_24 = V_19 -> V_23 ;
return V_24 ;
}
static T_5
F_18 ( T_6 V_12 , T_6 V_13 )
{
const struct V_25 * V_15 = ( const struct V_25 * ) V_12 ;
const struct V_25 * V_16 = ( const struct V_25 * ) V_13 ;
if ( V_15 -> V_21 == V_16 -> V_21 ) {
if ( ( V_15 -> V_26 == V_16 -> V_26 ) &&
( V_15 -> V_27 == V_16 -> V_27 ) &&
( V_15 -> V_28 == V_16 -> V_28 ) &&
( V_15 -> V_29 == V_16 -> V_29 ) ) {
return TRUE ;
}
else if ( ( V_15 -> V_26 == V_16 -> V_27 ) &&
( V_15 -> V_27 == V_16 -> V_26 ) &&
( V_15 -> V_28 == V_16 -> V_29 ) &&
( V_15 -> V_29 == V_16 -> V_28 ) ) {
return TRUE ;
}
}
return FALSE ;
}
static T_3
F_19 ( T_6 V_18 )
{
const struct V_25 * V_19 = ( const struct V_25 * ) V_18 ;
T_3 V_24 ;
V_24 = V_19 -> V_28 + V_19 -> V_29 ;
return V_24 ;
}
static T_5
F_20 ( T_6 V_12 , T_6 V_13 )
{
const struct V_30 * V_15 = ( const struct V_30 * ) V_12 ;
const struct V_30 * V_16 = ( const struct V_30 * ) V_13 ;
if ( V_15 -> V_21 == V_16 -> V_21 ) {
if ( ( V_15 -> V_22 == V_16 -> V_22 ) && ( V_15 -> V_23 == V_16 -> V_23 ) )
return TRUE ;
}
return FALSE ;
}
static T_3
F_21 ( T_6 V_18 )
{
const struct V_30 * V_19 = ( const struct V_30 * ) V_18 ;
T_3 V_24 ;
V_24 = V_19 -> V_23 ;
return V_24 ;
}
static T_5
F_22 ( T_6 V_12 , T_6 V_13 )
{
const struct V_31 * V_15 = ( const struct V_31 * ) V_12 ;
const struct V_31 * V_16 = ( const struct V_31 * ) V_13 ;
if ( V_15 -> V_21 == V_16 -> V_21 ) {
if ( ( ( V_15 -> V_26 == V_16 -> V_26 ) &&
( V_15 -> V_27 == V_16 -> V_27 ) &&
( V_15 -> V_23 == V_16 -> V_23 ) )
||
( ( V_15 -> V_26 == V_16 -> V_27 ) &&
( V_15 -> V_27 == V_16 -> V_26 ) &&
( V_15 -> V_23 == V_16 -> V_23 ) )
)
return TRUE ;
}
return FALSE ;
}
static T_3
F_23 ( T_6 V_18 )
{
const struct V_31 * V_19 = ( const struct V_31 * ) V_18 ;
T_3 V_24 ;
V_24 = V_19 -> V_23 ;
return V_24 ;
}
static void
F_24 ( struct V_32 * V_33 ,
T_7 * V_34 )
{
V_33 -> V_35 -> V_36 = V_34 -> V_37 ;
V_33 -> V_35 -> V_38 = 0 ;
V_33 -> V_35 -> V_39 = FALSE ;
V_33 -> V_35 -> V_40 = V_34 -> V_41 ;
}
static struct V_32 *
F_25 ( struct V_32 * V_42 ,
struct V_43 * V_44 ,
T_7 * V_34 )
{
struct V_32 * V_45 = NULL ;
V_45 = F_26 ( F_27 () , struct V_32 ) ;
V_45 -> V_35 = V_44 ;
V_44 -> V_46 = V_45 ;
V_45 -> V_47 = V_42 -> V_47 ;
V_45 -> V_35 -> V_36 = V_34 -> V_37 ;
V_45 -> V_48 = NULL ;
V_45 -> V_49 = V_42 ;
V_45 -> V_50 = FALSE ;
#ifdef F_28
F_13 ( 10 , L_2 , V_45 -> V_35 -> V_17 ) ;
#endif
V_42 -> V_48 = V_45 ;
if ( V_42 -> V_35 -> V_38 == 0 ) {
#ifdef F_28
F_13 ( 10 , L_3 ) ;
#endif
V_42 -> V_35 -> V_38 = V_34 -> V_37 - 1 ;
}
return V_45 ;
}
static void
F_29 ( struct V_51 * V_52 ,
T_7 * V_34 )
{
V_52 -> V_35 -> V_36 = V_34 -> V_37 ;
V_52 -> V_35 -> V_38 = 0 ;
V_52 -> V_35 -> V_39 = FALSE ;
V_52 -> V_35 -> V_40 = V_34 -> V_41 ;
}
static struct V_51 *
F_30 ( struct V_51 * V_53 ,
struct V_43 * V_44 ,
T_7 * V_34 )
{
struct V_51 * V_54 = NULL ;
V_54 = F_26 ( F_27 () , struct V_51 ) ;
V_54 -> V_35 = V_44 ;
V_44 -> V_55 = V_54 ;
V_54 -> V_56 = V_53 -> V_56 ;
V_54 -> V_35 -> V_36 = V_34 -> V_37 ;
V_54 -> V_57 = NULL ;
V_54 -> V_58 = V_53 ;
V_54 -> V_50 = FALSE ;
#ifdef F_28
F_13 ( 10 , L_4 , V_54 -> V_35 -> V_17 ) ;
#endif
V_53 -> V_57 = V_54 ;
if ( V_53 -> V_35 -> V_38 == 0 ) {
#ifdef F_28
F_13 ( 10 , L_3 ) ;
#endif
V_53 -> V_35 -> V_38 = V_34 -> V_37 - 1 ;
}
return V_54 ;
}
static struct V_59 *
F_31 ( struct V_59 * V_60 ,
struct V_43 * V_44 )
{
struct V_59 * V_61 = NULL ;
V_61 = F_26 ( F_27 () , struct V_59 ) ;
V_61 -> V_35 = V_44 ;
V_44 -> V_62 = V_61 ;
V_61 -> V_63 = V_60 -> V_63 ;
V_61 -> V_64 = NULL ;
V_61 -> V_65 = V_60 ;
V_61 -> V_50 = FALSE ;
#ifdef F_28
F_13 ( 10 , L_5 , V_61 -> V_35 -> V_17 ) ;
#endif
V_60 -> V_64 = V_61 ;
return V_61 ;
}
static struct V_66 *
F_32 ( struct V_66 * V_67 ,
struct V_43 * V_44 )
{
struct V_66 * V_68 = NULL ;
V_68 = F_26 ( F_27 () , struct V_66 ) ;
V_68 -> V_35 = V_44 ;
V_44 -> V_69 = V_68 ;
V_68 -> V_70 = V_67 -> V_70 ;
V_68 -> V_71 = NULL ;
V_68 -> V_72 = V_67 ;
V_68 -> V_50 = FALSE ;
#ifdef F_28
F_13 ( 10 , L_6 , V_68 -> V_35 -> V_17 ) ;
#endif
V_67 -> V_71 = V_68 ;
return V_68 ;
}
static struct V_32 *
F_33 ( struct V_20 * V_73 ,
T_7 * V_34 , T_8 V_74 )
{
struct V_32 * V_33 = NULL ;
V_33 = (struct V_32 * ) F_12 ( V_75 , V_73 ) ;
if( V_33 ) {
do {
if ( V_33 -> V_35 ) {
if ( ( V_74 &&
V_34 -> V_37 == V_33 -> V_35 -> V_36 )
||
( ! V_74 &&
V_34 -> V_37 >= V_33 -> V_35 -> V_36 &&
( V_33 -> V_35 -> V_38 ? V_34 -> V_37 <= V_33 -> V_35 -> V_38 : 1 )
)
) {
#ifdef F_28
F_13 ( 10 , L_7 , V_33 -> V_35 -> V_17 ) ;
#endif
return V_33 ;
}
#ifdef F_28
F_13 ( 60 , L_8 , V_33 -> V_35 -> V_17 ) ;
#endif
}
if( V_33 -> V_48 == NULL ) {
#ifdef F_28
F_13 ( 23 , L_9 ) ;
#endif
break;
}
V_33 = V_33 -> V_48 ;
} while ( V_33 != NULL ) ;
} else {
#ifdef F_28
F_13 ( 23 , L_10 ) ;
#endif
}
return NULL ;
}
static struct V_59 *
F_34 ( struct V_25 * V_76 ,
T_7 * V_34 )
{
struct V_59 * V_77 = NULL ;
V_77 = (struct V_59 * ) F_12 ( V_78 , V_76 ) ;
if( V_77 ) {
do {
if ( V_77 -> V_35 ) {
if ( V_34 -> V_37 >= V_77 -> V_35 -> V_36 &&
( V_77 -> V_35 -> V_38 ? V_34 -> V_37 <= V_77 -> V_35 -> V_38 : 1 ) ) {
#ifdef F_28
F_13 ( 10 , L_11 , V_77 -> V_35 -> V_17 ) ;
#endif
return V_77 ;
}
#ifdef F_28
F_13 ( 60 , L_12 , V_77 -> V_35 -> V_17 ) ;
#endif
}
if( V_77 -> V_64 == NULL ) {
#ifdef F_28
F_13 ( 23 , L_13 ) ;
#endif
break;
}
V_77 = V_77 -> V_64 ;
} while ( V_77 != NULL ) ;
} else {
#ifdef F_28
F_13 ( 23 , L_14 ) ;
#endif
}
return NULL ;
}
static struct V_66 *
F_35 ( struct V_30 * V_79 ,
T_7 * V_34 , T_8 V_80 )
{
struct V_66 * V_81 = NULL ;
V_81 = (struct V_66 * ) F_12 ( V_82 , V_79 ) ;
if( V_81 ) {
do {
if ( V_81 -> V_35 ) {
if ( ( V_80 &&
( V_81 -> V_35 -> V_38 ? V_34 -> V_37 == V_81 -> V_35 -> V_38 : 1 )
)
||
( ! V_80 &&
V_34 -> V_37 >= V_81 -> V_35 -> V_36 &&
( V_81 -> V_35 -> V_38 ? V_34 -> V_37 <= V_81 -> V_35 -> V_38 : 1 )
)
) {
#ifdef F_28
F_13 ( 10 , L_15 , V_81 -> V_35 -> V_17 ) ;
#endif
return V_81 ;
}
#ifdef F_28
F_13 ( 60 , L_16 , V_81 -> V_35 -> V_17 ) ;
#endif
}
if( V_81 -> V_71 == NULL ) {
#ifdef F_28
F_13 ( 23 , L_17 ) ;
#endif
break;
}
V_81 = V_81 -> V_71 ;
} while ( V_81 != NULL ) ;
} else {
#ifdef F_28
F_13 ( 23 , L_18 ) ;
#endif
}
return NULL ;
}
static struct V_43 *
F_36 ( struct V_14 * V_83 ,
T_7 * V_34 )
{
struct V_14 * V_84 ;
struct V_43 * V_85 = NULL ;
V_84 = F_37 ( F_27 () , struct V_14 ) ;
V_84 -> V_17 = V_83 -> V_17 ;
V_85 = F_26 ( F_27 () , struct V_43 ) ;
V_85 -> V_19 = V_84 ;
V_85 -> V_17 = V_83 -> V_17 ;
V_85 -> V_36 = V_34 -> V_37 ;
#ifdef F_28
F_13 ( 10 , L_19 , V_85 -> V_17 ) ;
#endif
F_2 ( V_86 , V_84 , V_85 ) ;
return V_85 ;
}
static struct V_32 *
F_38 ( struct V_20 * V_73 ,
struct V_43 * V_44 )
{
struct V_20 * V_87 ;
struct V_32 * V_45 = NULL ;
V_87 = F_37 ( F_27 () , struct V_20 ) ;
V_87 -> V_21 = V_73 -> V_21 ;
V_87 -> V_23 = V_73 -> V_23 ;
V_87 -> V_22 = V_73 -> V_22 ;
V_45 = F_26 ( F_27 () , struct V_32 ) ;
V_45 -> V_47 = V_87 ;
V_45 -> V_35 = V_44 ;
V_44 -> V_46 = V_45 ;
V_45 -> V_50 = TRUE ;
V_45 -> V_48 = NULL ;
V_45 -> V_49 = NULL ;
#ifdef F_28
F_13 ( 10 , L_7 , V_45 -> V_35 -> V_17 ) ;
#endif
F_2 ( V_75 , V_87 , V_45 ) ;
return V_45 ;
}
static struct V_59 *
F_39 ( struct V_25 * V_76 ,
struct V_43 * V_44 )
{
struct V_25 * V_88 ;
struct V_59 * V_61 = NULL ;
V_88 = F_37 ( F_27 () , struct V_25 ) ;
V_88 -> V_21 = V_76 -> V_21 ;
V_88 -> V_28 = V_76 -> V_28 ;
V_88 -> V_29 = V_76 -> V_29 ;
V_88 -> V_26 = V_76 -> V_26 ;
V_88 -> V_27 = V_76 -> V_27 ;
V_61 = F_26 ( F_27 () , struct V_59 ) ;
V_61 -> V_63 = V_88 ;
V_61 -> V_35 = V_44 ;
V_44 -> V_62 = V_61 ;
V_61 -> V_50 = TRUE ;
V_61 -> V_64 = NULL ;
V_61 -> V_65 = NULL ;
#ifdef F_28
F_13 ( 10 , L_11 , V_61 -> V_35 -> V_17 ) ;
#endif
F_2 ( V_78 , V_88 , V_61 ) ;
return V_61 ;
}
static struct V_66 *
F_40 ( struct V_30 * V_79 ,
struct V_43 * V_44 )
{
struct V_30 * V_89 ;
struct V_66 * V_68 = NULL ;
V_89 = F_37 ( F_27 () , struct V_30 ) ;
V_89 -> V_21 = V_79 -> V_21 ;
V_89 -> V_23 = V_79 -> V_23 ;
V_89 -> V_22 = V_79 -> V_22 ;
V_68 = F_26 ( F_27 () , struct V_66 ) ;
V_68 -> V_70 = V_89 ;
V_68 -> V_35 = V_44 ;
V_44 -> V_69 = V_68 ;
V_68 -> V_50 = TRUE ;
V_68 -> V_71 = NULL ;
V_68 -> V_72 = NULL ;
#ifdef F_28
F_13 ( 10 , L_15 , V_68 -> V_35 -> V_17 ) ;
#endif
F_2 ( V_82 , V_89 , V_68 ) ;
return V_68 ;
}
static struct V_51 *
F_41 ( struct V_31 * V_90 ,
struct V_43 * V_44 )
{
struct V_31 * V_91 ;
struct V_51 * V_54 = NULL ;
V_91 = F_37 ( F_27 () , struct V_31 ) ;
V_91 -> V_21 = V_90 -> V_21 ;
V_91 -> V_23 = V_90 -> V_23 ;
V_91 -> V_26 = V_90 -> V_26 ;
V_91 -> V_27 = V_90 -> V_27 ;
V_54 = F_26 ( F_27 () , struct V_51 ) ;
V_54 -> V_56 = V_91 ;
V_54 -> V_35 = V_44 ;
V_44 -> V_55 = V_54 ;
V_54 -> V_50 = TRUE ;
V_54 -> V_57 = NULL ;
V_54 -> V_58 = NULL ;
#ifdef F_28
F_13 ( 10 , L_20 , V_54 -> V_35 -> V_17 ) ;
#endif
F_2 ( V_92 , V_91 , V_54 ) ;
return V_54 ;
}
static struct V_59 *
F_42 ( struct V_25 * V_76 ,
struct V_43 * V_44 )
{
struct V_59 * V_93 = NULL ;
struct V_59 * V_77 = NULL ;
V_93 = (struct V_59 * )
F_12 ( V_78 , V_76 ) ;
if ( V_93 ) {
do {
if ( ! V_93 -> V_64 ) {
V_77 = F_31 ( V_93 ,
V_44 ) ;
break;
}
V_93 = V_93 -> V_64 ;
} while ( V_93 != NULL );
} else {
V_77 = F_39 ( V_76 ,
V_44 ) ;
}
return V_77 ;
}
static struct V_66 *
F_43 ( struct V_30 * V_79 ,
struct V_43 * V_44 )
{
struct V_66 * V_94 = NULL ;
struct V_66 * V_81 = NULL ;
V_94 = (struct V_66 * )
F_12 ( V_82 , V_79 ) ;
if ( V_94 ) {
do {
if ( ! V_94 -> V_71 ) {
V_81 = F_32 ( V_94 ,
V_44 ) ;
break;
}
V_94 = V_94 -> V_71 ;
} while ( V_94 != NULL );
} else {
V_81 = F_40 ( V_79 ,
V_44 ) ;
}
return V_81 ;
}
void
F_44 ( void )
{
if ( V_86 != NULL ) {
#ifdef F_28
F_13 ( 16 , L_21 ) ;
#endif
F_45 ( V_86 ) ;
}
if ( V_75 != NULL ) {
#ifdef F_28
F_13 ( 16 , L_22 ) ;
#endif
F_45 ( V_75 ) ;
}
if ( V_78 != NULL ) {
#ifdef F_28
F_13 ( 16 , L_23 ) ;
#endif
F_45 ( V_78 ) ;
}
if ( V_82 != NULL ) {
#ifdef F_28
F_13 ( 16 , L_24 ) ;
#endif
F_45 ( V_82 ) ;
}
if ( V_92 != NULL ) {
#ifdef F_28
F_13 ( 16 , L_25 ) ;
#endif
F_45 ( V_92 ) ;
}
#ifdef F_28
F_13 ( 16 , L_26 ) ;
#endif
V_86 = F_46 ( F_15 , F_14 ) ;
V_75 = F_46 ( F_17 , F_16 ) ;
V_78 = F_46 ( F_19 , F_18 ) ;
V_82 = F_46 ( F_21 , F_20 ) ;
V_92 = F_46 ( F_23 , F_22 ) ;
V_95 = 1 ;
V_96 = V_97 || V_98 & V_99 ;
}
static struct V_43 *
F_47 ( T_9 * V_100 , T_7 * V_34 , T_10 * V_101 ,
struct V_102 * V_103 )
{
struct V_43 * V_44 = NULL ;
struct V_14 V_104 ;
struct V_32 * V_33 , * V_45 = NULL ;
struct V_20 V_105 ;
T_11 * V_106 ;
T_11 * V_107 = NULL ;
T_10 * V_108 = NULL ;
#ifdef F_28
F_13 ( 51 , L_27 , F_48 ( F_49 () , & V_34 -> V_109 ) , V_103 -> V_28 , F_48 ( F_49 () , & V_34 -> V_110 ) ) ;
#endif
V_105 . V_23 = V_103 -> V_28 ;
if ( V_34 -> V_109 . type == V_111 && V_34 -> V_110 . type == V_111 )
{
V_105 . V_22 = F_50 ( ( const V_112 * ) V_34 -> V_109 . V_113 ) ;
} else {
V_105 . V_22 = F_51 ( F_48 ( F_49 () , & V_34 -> V_109 ) ) ;
}
V_105 . V_21 = F_17 ( & V_105 ) ;
#ifdef F_28
F_13 ( 10 , L_28 , V_34 -> V_37 ) ;
F_13 ( 11 , L_29 , V_105 . V_21 ) ;
F_13 ( 51 , L_30 , F_48 ( F_49 () , & V_34 -> V_109 ) ) ;
F_13 ( 51 , L_31 , V_105 . V_23 ) ;
#endif
V_33 = (struct V_32 * )
F_12 ( V_75 , & V_105 ) ;
if ( V_33 ) {
do {
if ( V_34 -> V_37 == V_33 -> V_35 -> V_36 ) {
#ifdef F_28
F_13 ( 22 , L_32 ) ;
#endif
V_44 = V_33 -> V_35 ;
break;
}
if ( ! V_33 -> V_48 ) {
if ( ( V_33 -> V_35 -> V_38 != 0
&& V_34 -> V_37 > V_33 -> V_35 -> V_36
&& ( T_3 ) V_34 -> V_41 . V_114 > ( T_3 ) ( V_33 -> V_35 -> V_40 . V_114 + V_115 )
) ||
( V_33 -> V_35 -> V_38 == 0
&& V_34 -> V_37 > V_33 -> V_35 -> V_36
&& ( T_3 ) V_34 -> V_41 . V_114 > ( T_3 ) ( V_33 -> V_35 -> V_40 . V_114 + V_116 )
)
)
{
#ifdef F_28
F_13 ( 12 , L_33 , V_105 . V_21 ) ;
F_13 ( 12 , L_34 , V_34 -> V_37 , V_33 -> V_35 -> V_38 ) ;
#endif
V_104 . V_17 = V_95 ++ ;
V_44 = F_36 ( & V_104 , V_34 ) ;
V_45 = F_25 ( V_33 ,
V_44 ,
V_34 ) ;
#ifdef F_28
F_13 ( 12 , L_35 , V_105 . V_21 ) ;
#endif
F_24 ( V_45 , V_34 ) ;
} else {
if ( V_33 -> V_35 -> V_117 ) {
#ifdef F_28
F_13 ( 12 , L_36 , V_105 . V_21 ) ;
F_13 ( 12 , L_34 , V_34 -> V_37 , V_33 -> V_35 -> V_38 ) ;
#endif
V_104 . V_17 = V_95 ++ ;
V_44 = F_36 ( & V_104 , V_34 ) ;
V_45 = F_25 ( V_33 ,
V_44 ,
V_34 ) ;
#ifdef F_28
F_13 ( 12 , L_37 , V_105 . V_21 ) ;
#endif
F_24 ( V_45 , V_34 ) ;
} else {
#ifdef F_28
F_13 ( 21 , L_38 , V_33 -> V_35 -> V_36 ) ;
#endif
V_44 = V_33 -> V_35 ;
if ( V_96 && V_101 ) {
V_108 = F_52 ( V_101 , V_100 , 0 , - 1 , V_118 , & V_107 , L_39 ) ;
F_53 ( V_107 ) ;
V_106 = F_54 ( V_108 , V_119 , V_100 , 0 , 0 ,
V_44 -> V_36 ,
L_40 ,
V_44 -> V_17 , V_44 -> V_36 ) ;
F_53 ( V_106 ) ;
}
return V_44 ;
}
}
break;
}
V_33 = V_33 -> V_48 ;
} while ( V_33 != NULL );
} else {
#ifdef F_28
F_13 ( 10 , L_41 , V_105 . V_21 ) ;
#endif
V_104 . V_17 = V_95 ++ ;
V_44 = F_36 ( & V_104 , V_34 ) ;
V_33 = F_38 ( & V_105 , V_44 ) ;
#ifdef F_28
F_13 ( 11 , L_35 , V_105 . V_21 ) ;
F_13 ( 11 , L_42 , V_34 -> V_37 ) ;
#endif
F_24 ( V_33 , V_34 ) ;
}
if ( V_96 && V_101 &&
V_44 &&
V_44 -> V_17 ) {
V_108 = F_52 ( V_101 , V_100 , 0 , 0 , V_118 , & V_107 , L_39 ) ;
F_53 ( V_107 ) ;
V_106 = F_55 ( V_108 , V_120 , V_100 , 0 , 0 , V_44 -> V_17 ) ;
F_53 ( V_106 ) ;
if( V_44 -> V_38 != 0 ) {
#ifdef F_28
F_13 ( 20 , L_43 , V_44 -> V_38 ) ;
#endif
V_106 = F_54 ( V_108 , V_121 , V_100 , 0 , 0 ,
V_44 -> V_38 ,
L_44 ,
V_44 -> V_38 ) ;
F_53 ( V_106 ) ;
}
}
return V_44 ;
}
static struct V_43 *
F_56 ( T_9 * V_100 , T_7 * V_34 , T_10 * V_101 ,
struct V_102 * V_103 )
{
struct V_43 * V_44 = NULL ;
struct V_59 * V_77 ;
struct V_25 V_122 ;
struct V_20 V_105 ;
struct V_32 * V_33 ;
struct V_30 V_123 ;
T_11 * V_106 ;
T_11 * V_107 = NULL ;
T_10 * V_108 = NULL ;
#ifdef F_28
F_13 ( 51 , L_45 , F_48 ( F_49 () , & V_34 -> V_109 ) , V_103 -> V_28 , F_48 ( F_49 () , & V_34 -> V_110 ) , V_103 -> V_29 ) ;
F_13 ( 10 , L_46 , V_34 -> V_37 ) ;
#endif
V_122 . V_28 = V_103 -> V_28 ;
V_122 . V_29 = V_103 -> V_29 ;
if ( V_34 -> V_109 . type == V_111 && V_34 -> V_110 . type == V_111 )
{
V_122 . V_26 = F_50 ( ( const V_112 * ) V_34 -> V_109 . V_113 ) ;
V_122 . V_27 = F_50 ( ( const V_112 * ) V_34 -> V_110 . V_113 ) ;
} else {
V_122 . V_26 = F_51 ( F_48 ( F_49 () , & V_34 -> V_109 ) ) ;
V_122 . V_27 = F_51 ( F_48 ( F_49 () , & V_34 -> V_110 ) ) ;
}
V_122 . V_21 = F_19 ( & V_122 ) ;
#ifdef F_28
F_13 ( 11 , L_47 , V_122 . V_21 ) ;
F_13 ( 51 , L_48 , F_48 ( F_49 () , & V_34 -> V_109 ) , F_48 ( F_49 () , & V_34 -> V_110 ) ) ;
F_13 ( 51 , L_49 , V_122 . V_28 , V_122 . V_29 ) ;
#endif
V_77 = F_34 ( & V_122 , V_34 ) ;
if( V_77 ) {
#ifdef F_28
F_13 ( 12 , L_50 ) ;
#endif
V_44 = V_77 -> V_35 ;
} else {
#ifdef F_28
F_13 ( 12 , L_51 ) ;
#endif
V_105 . V_23 = V_103 -> V_29 ;
if ( V_34 -> V_109 . type == V_111 && V_34 -> V_110 . type == V_111 )
{
V_105 . V_22 = F_50 ( ( const V_112 * ) V_34 -> V_110 . V_113 ) ;
} else {
V_105 . V_22 = F_51 ( F_48 ( F_49 () , & V_34 -> V_110 ) ) ;
}
V_105 . V_21 = F_17 ( & V_105 ) ;
#ifdef F_28
F_13 ( 11 , L_52 , V_105 . V_21 ) ;
F_13 ( 51 , L_30 , F_48 ( F_49 () , & V_34 -> V_110 ) ) ;
F_13 ( 51 , L_31 , V_105 . V_23 ) ;
#endif
V_33 = F_33 ( & V_105 , V_34 , FALSE ) ;
if( ! V_33 ) {
#ifdef F_28
F_13 ( 12 , L_53 ) ;
#endif
V_105 . V_23 = V_103 -> V_28 ;
if ( V_34 -> V_109 . type == V_111 && V_34 -> V_110 . type == V_111 )
{
V_105 . V_22 = F_50 ( ( const V_112 * ) V_34 -> V_109 . V_113 ) ;
} else {
V_105 . V_22 = F_51 ( F_48 ( F_49 () , & V_34 -> V_109 ) ) ;
}
V_105 . V_21 = F_17 ( & V_105 ) ;
#ifdef F_28
F_13 ( 11 , L_52 , V_105 . V_21 ) ;
F_13 ( 51 , L_30 , F_48 ( F_49 () , & V_34 -> V_109 ) ) ;
F_13 ( 51 , L_31 , V_105 . V_23 ) ;
#endif
V_33 = F_33 ( & V_105 , V_34 , FALSE ) ;
}
if( V_33 &&
! V_33 -> V_35 -> V_62 ) {
#ifdef F_28
F_13 ( 12 , L_54 ) ;
#endif
V_44 = V_33 -> V_35 ;
V_44 -> V_39 = TRUE ;
#ifdef F_28
F_13 ( 10 , L_55 , V_122 . V_21 ) ;
F_13 ( 11 , L_56 , V_34 -> V_37 ) ;
#endif
F_42 ( & V_122 ,
V_33 -> V_35 ) ;
V_123 . V_23 = V_103 -> V_28 ;
if ( V_34 -> V_109 . type == V_111 && V_34 -> V_110 . type == V_111 )
{
V_123 . V_22 = F_50 ( ( const V_112 * ) V_34 -> V_109 . V_113 ) ;
} else {
V_123 . V_22 = F_51 ( F_48 ( F_49 () , & V_34 -> V_109 ) ) ;
}
V_123 . V_21 = F_21 ( & V_123 ) ;
#ifdef F_28
F_13 ( 10 , L_57 , V_123 . V_21 ) ;
F_13 ( 51 , L_30 , F_48 ( F_49 () , & V_34 -> V_109 ) ) ;
F_13 ( 51 , L_58 , V_123 . V_23 ) ;
F_13 ( 11 , L_42 , V_34 -> V_37 ) ;
#endif
F_43 ( & V_123 ,
V_33 -> V_35 ) ;
} else {
#ifdef F_28
F_13 ( 12 , L_59 ) ;
#endif
}
}
if ( V_96 && V_101 &&
V_44 &&
V_44 -> V_17 ) {
V_108 = F_52 ( V_101 , V_100 , 0 , - 1 , V_118 , & V_107 , L_39 ) ;
F_53 ( V_107 ) ;
V_106 = F_55 ( V_108 , V_120 , V_100 , 0 , 0 , V_44 -> V_17 ) ;
F_53 ( V_106 ) ;
}
return V_44 ;
}
static struct V_43 *
F_57 ( T_9 * V_100 , T_7 * V_34 , T_10 * V_101 ,
struct V_102 * V_103 )
{
struct V_43 * V_44 = NULL ;
struct V_30 V_123 ;
struct V_66 * V_81 = NULL ;
struct V_20 V_105 ;
struct V_32 * V_33 = NULL ;
T_11 * V_106 ;
T_12 V_124 ;
T_11 * V_107 = NULL ;
T_10 * V_108 = NULL ;
#ifdef F_28
F_13 ( 51 , L_60 , F_48 ( F_49 () , & V_34 -> V_109 ) , F_48 ( F_49 () , & V_34 -> V_110 ) , V_103 -> V_29 ) ;
F_13 ( 10 , L_61 , V_34 -> V_37 ) ;
#endif
V_123 . V_23 = V_103 -> V_29 ;
if ( V_34 -> V_109 . type == V_111 && V_34 -> V_110 . type == V_111 )
{
V_123 . V_22 = F_50 ( ( const V_112 * ) V_34 -> V_110 . V_113 ) ;
} else {
V_123 . V_22 = F_51 ( F_48 ( F_49 () , & V_34 -> V_110 ) ) ;
}
V_123 . V_21 = F_21 ( & V_123 ) ;
#ifdef F_28
F_13 ( 11 , L_62 , V_123 . V_21 ) ;
F_13 ( 11 , L_30 , F_48 ( F_49 () , & V_34 -> V_110 ) ) ;
F_13 ( 51 , L_58 , V_123 . V_23 ) ;
#endif
V_81 = F_35 ( & V_123 , V_34 , TRUE ) ;
if( ! V_81 ) {
#ifdef F_28
F_13 ( 12 , L_63 ) ;
#endif
V_105 . V_23 = V_103 -> V_29 ;
if ( V_34 -> V_109 . type == V_111 && V_34 -> V_110 . type == V_111 )
{
V_105 . V_22 = F_50 ( ( const V_112 * ) V_34 -> V_110 . V_113 ) ;
} else {
V_105 . V_22 = F_51 ( F_48 ( F_49 () , & V_34 -> V_110 ) ) ;
}
V_105 . V_21 = F_17 ( & V_105 ) ;
#ifdef F_28
F_13 ( 11 , L_52 , V_105 . V_21 ) ;
F_13 ( 51 , L_30 , F_48 ( F_49 () , & V_34 -> V_110 ) ) ;
F_13 ( 51 , L_58 , V_105 . V_23 ) ;
#endif
V_33 = F_33 ( & V_105 , V_34 , FALSE ) ;
if( ! V_33 ) {
#ifdef F_28
F_13 ( 12 , L_59 ) ;
#endif
}
}
if ( V_81 ) {
V_44 = V_81 -> V_35 ;
} else if ( V_33 ) {
V_44 = V_33 -> V_35 ;
}
if ( V_44 ) {
#ifdef F_28
F_13 ( 12 , L_64 , V_44 -> V_36 ) ;
#endif
if ( V_96 && V_101 ) {
V_108 = F_52 ( V_101 , V_100 , 0 , - 1 , V_118 , & V_107 , L_39 ) ;
F_53 ( V_107 ) ;
V_106 = F_55 ( V_108 , V_120 , V_100 , 0 , 0 , V_44 -> V_17 ) ;
F_53 ( V_106 ) ;
}
#ifdef F_28
F_13 ( 20 , L_65 , V_44 -> V_36 ) ;
#endif
if ( V_96 && V_108 ) {
V_106 = F_54 ( V_108 , V_125 , V_100 , 0 , 0 ,
V_44 -> V_36 ,
L_66 ,
V_44 -> V_36 ) ;
F_53 ( V_106 ) ;
F_58 ( & V_124 , & V_34 -> V_41 , & V_44 -> V_40 ) ;
V_106 = F_59 ( V_108 , V_126 , V_100 , 0 , 0 , & V_124 ) ;
F_53 ( V_106 ) ;
}
F_60 ( V_44 , V_34 ) ;
} else {
#ifdef F_28
F_13 ( 12 , L_67 ) ;
#endif
}
return V_44 ;
}
static struct V_43 *
F_61 ( T_9 * V_100 , T_7 * V_34 , T_10 * V_101 ,
struct V_102 * V_103 )
{
struct V_43 * V_44 = NULL ;
struct V_14 V_104 ;
struct V_51 * V_52 , * V_54 ;
struct V_31 V_127 ;
T_11 * V_106 ;
T_12 V_124 ;
T_8 V_128 = FALSE ;
T_10 * V_108 = NULL ;
T_11 * V_107 = NULL ;
V_127 . V_23 = V_103 -> V_28 ;
if ( V_34 -> V_109 . type == V_111 && V_34 -> V_110 . type == V_111 )
{
V_127 . V_26 = F_50 ( ( const V_112 * ) V_34 -> V_109 . V_113 ) ;
V_127 . V_27 = F_50 ( ( const V_112 * ) V_34 -> V_110 . V_113 ) ;
} else {
V_127 . V_26 = F_51 ( F_48 ( F_49 () , & V_34 -> V_109 ) ) ;
V_127 . V_27 = F_51 ( F_48 ( F_49 () , & V_34 -> V_110 ) ) ;
}
V_127 . V_21 = F_23 ( & V_127 ) ;
#ifdef F_28
F_13 ( 10 , L_68 , V_34 -> V_37 ) ;
F_13 ( 11 , L_29 , V_127 . V_21 ) ;
F_13 ( 51 , L_69 , F_48 ( F_49 () , & V_34 -> V_109 ) , F_48 ( F_49 () , & V_34 -> V_110 ) ) ;
F_13 ( 51 , L_58 , V_127 . V_23 ) ;
#endif
V_52 = (struct V_51 * )
F_12 ( V_92 , & V_127 ) ;
if ( V_52 ) {
do {
if ( V_34 -> V_37 == V_52 -> V_35 -> V_36 ) {
#ifdef F_28
F_13 ( 22 , L_70 ) ;
#endif
V_128 = FALSE ;
V_44 = V_52 -> V_35 ;
break;
}
if ( V_34 -> V_37 == V_52 -> V_35 -> V_38 ) {
#ifdef F_28
F_13 ( 22 , L_71 ) ;
#endif
V_128 = TRUE ;
V_44 = V_52 -> V_35 ;
break;
}
if ( V_34 -> V_37 > V_52 -> V_35 -> V_36 &&
V_52 -> V_35 -> V_38 == 0 ) {
#ifdef F_28
F_13 ( 12 , L_35 , V_127 . V_21 ) ;
#endif
V_52 -> V_35 -> V_38 = V_34 -> V_37 ;
V_52 -> V_35 -> V_39 = TRUE ;
V_52 -> V_35 -> V_117 = TRUE ;
V_44 = V_52 -> V_35 ;
V_128 = TRUE ;
if ( V_96 && V_101 ) {
V_108 = F_52 ( V_101 , V_100 , 0 , - 1 , V_118 , & V_107 , L_39 ) ;
F_53 ( V_107 ) ;
V_106 = F_55 ( V_108 , V_120 , V_100 , 0 , 0 , V_44 -> V_17 ) ;
F_53 ( V_106 ) ;
#ifdef F_28
F_13 ( 20 , L_65 , V_44 -> V_36 ) ;
#endif
V_106 = F_54 ( V_108 , V_125 , V_100 , 0 , 0 ,
V_44 -> V_36 ,
L_66 ,
V_44 -> V_36 ) ;
F_53 ( V_106 ) ;
F_58 ( & V_124 , & V_34 -> V_41 , & V_44 -> V_40 ) ;
V_106 = F_59 ( V_108 , V_126 , V_100 , 0 , 0 , & V_124 ) ;
F_53 ( V_106 ) ;
}
break;
}
if ( ! V_52 -> V_57 ) {
if ( ( V_52 -> V_35 -> V_38 != 0
&& V_34 -> V_37 > V_52 -> V_35 -> V_36
&& ( T_3 ) V_34 -> V_41 . V_114 > ( T_3 ) ( V_52 -> V_35 -> V_40 . V_114 + V_115 )
) ||
( V_52 -> V_35 -> V_38 == 0
&& V_34 -> V_37 > V_52 -> V_35 -> V_36
&& ( T_3 ) V_34 -> V_41 . V_114 > ( T_3 ) ( V_52 -> V_35 -> V_40 . V_114 + V_116 )
)
)
{
#ifdef F_28
F_13 ( 12 , L_33 , V_127 . V_21 ) ;
F_13 ( 12 , L_34 , V_34 -> V_37 , V_52 -> V_35 -> V_38 ) ;
#endif
V_104 . V_17 = V_95 ++ ;
V_44 = F_36 ( & V_104 , V_34 ) ;
V_54 = F_30 ( V_52 ,
V_44 ,
V_34 ) ;
#ifdef F_28
F_13 ( 12 , L_35 , V_127 . V_21 ) ;
#endif
F_29 ( V_54 , V_34 ) ;
V_52 = V_54 ;
} else {
if ( V_52 -> V_35 -> V_117 ) {
#ifdef F_28
F_13 ( 12 , L_36 , V_127 . V_21 ) ;
F_13 ( 12 , L_34 , V_34 -> V_37 , V_52 -> V_35 -> V_38 ) ;
#endif
V_104 . V_17 = V_95 ++ ;
V_44 = F_36 ( & V_104 , V_34 ) ;
V_54 = F_30 ( V_52 ,
V_44 ,
V_34 ) ;
#ifdef F_28
F_13 ( 12 , L_37 , V_127 . V_21 ) ;
#endif
F_29 ( V_54 , V_34 ) ;
V_52 = V_54 ;
} else {
V_44 = V_52 -> V_35 ;
#ifdef F_28
F_13 ( 12 , L_64 , V_44 -> V_36 ) ;
#endif
if ( V_96 && V_101 ) {
V_108 = F_52 ( V_101 , V_100 , 0 , - 1 , V_118 , & V_107 , L_39 ) ;
F_53 ( V_107 ) ;
V_106 = F_55 ( V_108 , V_120 , V_100 , 0 , 0 , V_44 -> V_17 ) ;
F_53 ( V_106 ) ;
#ifdef F_28
F_13 ( 20 , L_65 , V_44 -> V_36 ) ;
#endif
V_106 = F_54 ( V_108 , V_125 , V_100 , 0 , 0 ,
V_44 -> V_36 ,
L_66 ,
V_44 -> V_36 ) ;
F_53 ( V_106 ) ;
F_58 ( & V_124 , & V_34 -> V_41 , & V_44 -> V_40 ) ;
V_106 = F_59 ( V_108 , V_126 , V_100 , 0 , 0 , & V_124 ) ;
F_53 ( V_106 ) ;
}
V_44 = V_52 -> V_35 ;
}
}
break;
}
V_52 = V_52 -> V_57 ;
} while ( V_52 != NULL );
} else {
#ifdef F_28
F_13 ( 10 , L_41 , V_127 . V_21 ) ;
#endif
V_104 . V_17 = V_95 ++ ;
V_44 = F_36 ( & V_104 , V_34 ) ;
V_52 = F_41 ( & V_127 , V_44 ) ;
#ifdef F_28
F_13 ( 11 , L_35 , V_127 . V_21 ) ;
F_13 ( 11 , L_42 , V_34 -> V_37 ) ;
#endif
F_29 ( V_52 , V_34 ) ;
}
if ( V_96 && V_101 &&
V_44 &&
V_44 -> V_17 ) {
V_108 = F_52 ( V_101 , V_100 , 0 , - 1 , V_118 , & V_107 , L_39 ) ;
F_53 ( V_107 ) ;
V_106 = F_55 ( V_108 , V_120 , V_100 , 0 , 0 , V_44 -> V_17 ) ;
F_53 ( V_106 ) ;
}
if( V_96 && V_108 &&
V_52 -> V_35 -> V_38 != 0 ) {
if ( ! V_128 ) {
#ifdef F_28
F_13 ( 20 , L_43 , V_52 -> V_35 -> V_38 ) ;
#endif
V_106 = F_54 ( V_108 , V_121 , V_100 , 0 , 0 ,
V_52 -> V_35 -> V_38 ,
L_44 ,
V_52 -> V_35 -> V_38 ) ;
F_53 ( V_106 ) ;
} else {
#ifdef F_28
F_13 ( 20 , L_65 , V_44 -> V_36 ) ;
#endif
if ( V_96 ) {
V_106 = F_54 ( V_108 , V_125 , V_100 , 0 , 0 ,
V_44 -> V_36 ,
L_66 ,
V_44 -> V_36 ) ;
F_53 ( V_106 ) ;
F_58 ( & V_124 , & V_34 -> V_41 , & V_44 -> V_40 ) ;
V_106 = F_59 ( V_108 , V_126 , V_100 , 0 , 0 , & V_124 ) ;
F_53 ( V_106 ) ;
}
}
}
return V_44 ;
}
struct V_43 *
F_62 ( T_9 * V_100 , T_7 * V_34 , T_10 * V_101 ,
struct V_102 * V_103 )
{
struct V_43 * V_129 = NULL ;
if( V_34 == NULL || V_34 -> V_37 == 0 ) {
return NULL ;
}
switch ( V_103 -> V_130 ) {
case V_131 :
#ifdef F_28
F_13 ( 1 , L_72 ) ;
#endif
V_129 = F_47 ( V_100 , V_34 , V_101 , V_103 ) ;
break;
case V_132 :
#ifdef F_28
F_13 ( 1 , L_73 ) ;
#endif
V_129 = F_56 ( V_100 , V_34 , V_101 , V_103 ) ;
break;
case V_133 :
#ifdef F_28
F_13 ( 1 , L_74 ) ;
#endif
V_129 = F_57 ( V_100 , V_34 , V_101 , V_103 ) ;
break;
case V_134 :
#ifdef F_28
F_13 ( 1 , L_75 ) ;
#endif
V_129 = F_57 ( V_100 , V_34 , V_101 , V_103 ) ;
break;
case V_135 :
case V_136 :
#ifdef F_28
F_13 ( 1 , L_76 ) ;
#endif
V_129 = F_61 ( V_100 , V_34 , V_101 , V_103 ) ;
break;
default:
#ifdef F_28
F_13 ( 1 , L_77 , V_103 -> V_130 ) ;
#endif
break;
}
#ifdef F_28
if ( V_129 )
F_13 ( 1 , L_78 , V_129 -> V_17 ) ;
#endif
return V_129 ;
}
struct V_102 *
F_63 ( void )
{
struct V_102 * V_103 ;
V_137 ++ ;
if( V_137 == V_138 ) {
V_137 = 0 ;
}
V_103 = & V_139 [ V_137 ] ;
memset ( V_103 , 0 , sizeof( struct V_102 ) ) ;
return V_103 ;
}
void
F_60 ( struct V_43 * V_44 ,
T_7 * V_34 )
{
#ifdef F_28
F_13 ( 60 , L_79 ) ;
#endif
if ( V_44 ) {
V_44 -> V_39 = TRUE ;
V_44 -> V_38 = V_34 -> V_37 ;
V_44 -> V_140 = V_34 -> V_41 ;
V_44 -> V_117 = TRUE ;
if ( V_44 -> V_69
&& ! V_97 ) {
if ( V_44 -> V_69 -> V_71 ) {
if ( V_44 -> V_69 -> V_72 ) {
#ifdef F_28
F_13 ( 20 , L_80 ) ;
#endif
V_44 -> V_69 -> V_72 -> V_71
= V_44 -> V_69 -> V_71 ;
V_44 -> V_69 -> V_71 -> V_72
= V_44 -> V_69 -> V_72 ;
F_7 ( V_82 , V_44 -> V_69 -> V_70 ) ;
} else {
#ifdef F_28
F_13 ( 20 , L_81 ) ;
#endif
}
} else if ( ! V_97 ) {
#ifdef F_28
F_13 ( 20 , L_82 ) ;
#endif
F_7 ( V_82 , V_44 -> V_69 -> V_70 ) ;
}
}
if ( V_44 -> V_62
&& ! V_97 ) {
if ( V_44 -> V_62 -> V_64 ) {
if ( V_44 -> V_62 -> V_65 ) {
#ifdef F_28
F_13 ( 20 , L_83 ) ;
#endif
V_44 -> V_62 -> V_65 -> V_64
= V_44 -> V_62 -> V_64 ;
V_44 -> V_62 -> V_64 -> V_65
= V_44 -> V_62 -> V_65 ;
F_7 ( V_78 , V_44 -> V_62 -> V_63 ) ;
} else {
#ifdef F_28
F_13 ( 20 , L_84 ) ;
#endif
}
} else if ( ! V_97 ) {
#ifdef F_28
F_13 ( 20 , L_85 ) ;
#endif
F_7 ( V_78 , V_44 -> V_62 -> V_63 ) ;
}
}
if ( V_44 -> V_46
&& ! V_97 ) {
if ( V_44 -> V_46 -> V_48 ) {
if ( V_44 -> V_46 -> V_49 ) {
#ifdef F_28
F_13 ( 20 , L_86 ) ;
#endif
V_44 -> V_46 -> V_49 -> V_48
= V_44 -> V_46 -> V_48 ;
V_44 -> V_46 -> V_48 -> V_49
= V_44 -> V_46 -> V_49 ;
F_7 ( V_75 , V_44 -> V_46 -> V_47 ) ;
} else {
#ifdef F_28
F_13 ( 20 , L_87 ) ;
#endif
}
} else if ( ! V_97 ) {
#ifdef F_28
F_13 ( 20 , L_88 ) ;
#endif
F_7 ( V_75 , V_44 -> V_46 -> V_47 ) ;
}
}
if ( V_44 -> V_55
&& ! V_97 ) {
if ( V_44 -> V_55 -> V_57 ) {
if ( V_44 -> V_55 -> V_58 ) {
#ifdef F_28
F_13 ( 20 , L_89 ) ;
#endif
V_44 -> V_55 -> V_58 -> V_57
= V_44 -> V_55 -> V_57 ;
V_44 -> V_55 -> V_57 -> V_58
= V_44 -> V_55 -> V_58 ;
F_7 ( V_92 , V_44 -> V_55 -> V_56 ) ;
} else {
#ifdef F_28
F_13 ( 20 , L_90 ) ;
#endif
}
} else if ( ! V_97 ) {
#ifdef F_28
F_13 ( 20 , L_91 ) ;
#endif
F_7 ( V_92 , V_44 -> V_55 -> V_56 ) ;
}
}
if ( ! V_97 ) {
#ifdef F_28
F_13 ( 20 , L_92 ) ;
#endif
F_7 ( V_86 , V_44 -> V_19 ) ;
}
} else {
#ifdef F_28
F_13 ( 20 , L_93 ) ;
#endif
}
}
static int
F_64 ( T_9 * V_100 , T_7 * V_34 , T_10 * V_141 , void * V_113 V_6 )
{
T_11 * V_142 = NULL ;
T_10 * V_101 = NULL ;
struct V_43 * V_143 ;
T_2 V_144 ;
T_13 V_145 ;
T_14 V_146 ;
T_8 V_147 ;
T_5 V_148 ;
F_65 ( V_100 , 0 , & V_146 , & V_147 , & V_148 ) ;
if( V_146 == V_149 ) {
switch ( V_148 ) {
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
case 6 :
case 22 :
return F_66 ( V_150 , V_100 , V_34 , V_141 ) ;
default:
return F_67 ( V_100 ) ;
}
}
F_68 ( & V_145 , V_151 , TRUE , V_34 ) ;
V_152 = V_141 ;
V_153 = NULL ;
F_69 ( V_34 -> V_154 , V_155 , L_94 ) ;
if( V_141 ) {
V_142 = F_70 ( V_141 , V_156 , V_100 , 0 , - 1 , V_157 ) ;
V_101 = F_71 ( V_142 , V_158 ) ;
V_153 = V_101 ;
}
V_159 = NULL ;
V_160 = NULL ;
F_72 ( & V_161 ) ;
V_145 . V_162 = & V_161 ;
V_163 = F_63 () ;
V_164 = FALSE ;
V_165 = NULL ;
F_73 ( FALSE , V_100 , 0 , & V_145 , V_101 , - 1 ) ;
if ( V_98 && ! V_164 ) {
V_143 = F_62 ( V_100 , V_34 , V_153 , V_163 ) ;
V_161 . V_35 = V_143 ;
if ( V_143 && V_159 && ! V_143 -> V_166 ) {
F_74 ( V_143 -> V_167 , V_159 , sizeof( V_143 -> V_167 ) ) ;
V_143 -> V_166 = TRUE ;
if ( ( V_144 = F_75 ( V_168 , V_159 ) ) ) {
V_143 -> V_144 = V_144 ;
V_143 -> V_169 = TRUE ;
}
}
if ( V_98 && V_143 && V_143 -> V_170 ) {
( V_143 -> V_170 ) ( V_100 , V_34 , V_153 , V_143 ) ;
}
}
return F_67 ( V_100 ) ;
}
void
F_76 ( void )
{
V_171 = F_77 ( L_95 ) ;
V_150 = F_78 ( L_96 , V_156 ) ;
V_168 = F_79 ( L_97 ) ;
V_111 = F_80 ( L_98 ) ;
#include "packet-tcap-dis-tab.c"
}
void
F_81 ( void )
{
static T_15 V_172 [] = {
{ & V_173 ,
{ L_99 ,
L_100 ,
V_174 , V_175 , NULL , 0 ,
NULL , V_176 }
} ,
{ & V_177 ,
{ L_101 ,
L_102 ,
V_174 , V_178 , NULL , 0 ,
NULL , V_176 }
} ,
{ & V_179 ,
{ L_103 ,
L_104 ,
V_180 , V_181 , NULL , 0 ,
NULL , V_176 }
} ,
{ & V_182 ,
{ L_105 ,
L_106 ,
V_180 , V_181 , NULL , 0 ,
NULL , V_176 }
} ,
{ & V_183 ,
{ L_107 ,
L_108 ,
V_184 , V_175 , NULL , 0 ,
NULL , V_176 }
} ,
{ & V_120 ,
{ L_109 ,
L_110 ,
V_185 , V_178 , NULL , 0x0 ,
NULL , V_176 }
} ,
{ & V_121 ,
{ L_111 ,
L_112 ,
V_186 , V_181 , NULL , 0x0 ,
L_113 , V_176 }
} ,
{ & V_125 ,
{ L_114 ,
L_115 ,
V_186 , V_181 , NULL , 0x0 ,
L_116 , V_176 }
} ,
{ & V_126 ,
{ L_117 ,
L_118 ,
V_187 , V_181 , NULL , 0x0 ,
L_119 , V_176 }
} ,
{ & V_119 ,
{ L_120 ,
L_121 ,
V_186 , V_181 , NULL , 0x0 ,
L_122 , V_176 }
} ,
#include "packet-tcap-hfarr.c"
} ;
static T_5 * V_188 [] = {
& V_158 ,
& V_189 ,
& V_190 ,
& V_191 ,
& V_118 ,
#include "packet-tcap-ettarr.c"
} ;
T_16 * V_192 ;
V_156 = F_82 ( V_193 , V_194 , V_195 ) ;
F_83 ( V_156 , V_172 , F_84 ( V_172 ) ) ;
F_85 ( V_188 , F_84 ( V_188 ) ) ;
V_192 = F_86 ( V_156 , NULL ) ;
#if 0
prefs_register_enum_preference(tcap_module, "standard", "ITU TCAP standard",
"The SS7 standard used in ITU TCAP packets",
&tcap_standard, tcap_options, FALSE);
#else
F_87 ( V_192 , L_123 ) ;
#endif
#if 0
prefs_register_bool_preference(tcap_module, "lock_info_col", "Lock Info column",
"Always show TCAP in Info column",
&lock_info_col);
#else
F_87 ( V_192 , L_124 ) ;
#endif
F_88 ( & V_196 , L_125 , V_197 ) ;
F_89 ( V_192 , L_126 , L_127 ,
L_128 ,
& V_196 , V_197 ) ;
F_90 ( V_192 , L_129 ,
L_130 ,
L_131 ,
& V_98 ) ;
F_90 ( V_192 , L_132 ,
L_133 ,
L_134 ,
& V_97 ) ;
F_91 ( V_192 , L_135 ,
L_136 ,
L_137 ,
10 , & V_115 ) ;
F_91 ( V_192 , L_138 ,
L_139 ,
L_140 ,
10 , & V_116 ) ;
V_3 = F_46 ( V_198 , V_199 ) ;
V_5 = F_46 ( V_198 , V_199 ) ;
F_92 ( L_141 , F_64 , V_156 ) ;
V_4 = F_93 ( F_64 , V_156 ) ;
F_94 ( & V_200 ) ;
F_95 ( & V_201 ) ;
}
static void F_96 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_9 ( L_1 , V_1 , V_4 ) ;
}
}
static void F_97 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_4 ( L_1 , V_1 , V_4 ) ;
}
}
static void V_200 ( void )
{
V_202 = F_98 ( V_196 ) ;
F_99 ( V_202 , F_97 ) ;
F_44 () ;
}
static void V_201 ( void )
{
F_99 ( V_202 , F_96 ) ;
F_100 ( V_202 ) ;
}
static int
F_101 ( T_13 * V_203 , T_10 * V_101 , T_9 * V_100 , int V_204 )
{
T_5 V_205 , V_206 , V_207 ;
T_9 * V_208 ;
T_10 * V_209 ;
T_14 V_146 ;
T_8 V_147 ;
T_17 V_148 ;
T_1 V_210 ;
T_1 V_211 ;
T_1 V_212 ;
T_8 V_213 ;
while ( F_102 ( V_100 , V_204 ) > 0 )
{
V_206 = V_204 ;
V_204 = F_65 ( V_100 , V_204 , & V_146 , & V_147 , & V_148 ) ;
V_205 = V_204 ;
V_204 = F_103 ( V_100 , V_204 , & V_210 , & V_213 ) ;
V_207 = V_204 ;
V_211 = V_205 - V_206 ;
V_212 = V_207 - V_205 ;
if ( V_147 )
{
V_209 = F_52 ( V_101 , V_100 , V_206 ,
V_210 + ( V_207 - V_206 ) , V_189 , NULL ,
L_142 ) ;
F_54 ( V_209 , V_173 , V_100 ,
V_206 , V_211 , V_148 ,
L_143 ) ;
F_55 ( V_209 , V_173 , V_100 , V_206 ,
V_211 , V_146 ) ;
F_55 ( V_209 , V_177 , V_100 , V_205 ,
V_212 , V_210 ) ;
if ( V_210 - ( 2 * V_213 ) )
{
V_208 = F_104 ( V_100 , V_204 , V_210 - ( 2 * V_213 ) ) ;
F_101 ( V_203 , V_209 , V_208 , 0 ) ;
}
if ( V_213 )
F_70 ( V_209 , V_183 , V_100 , V_204 + V_210 - 2 , 2 , V_214 ) ;
V_204 += V_210 ;
}
else
{
V_209 = F_105 ( V_101 , V_100 , V_206 ,
V_210 + ( V_207 - V_206 ) , V_189 , NULL ,
L_144 , V_148 ) ;
F_55 ( V_209 , V_173 , V_100 , V_206 ,
V_211 , V_148 ) ;
F_55 ( V_209 , V_177 , V_100 ,
V_206 + V_211 , V_212 , V_210 ) ;
if ( V_210 )
{
V_208 = F_104 ( V_100 , V_204 , V_210 ) ;
F_106 ( TRUE , V_203 , V_101 , V_208 , 0 ,
V_179 , NULL ) ;
}
V_204 += V_210 ;
}
}
return V_204 ;
}
static void F_72 ( struct V_215 * V_216 )
{
memset ( V_216 , 0 , sizeof( struct V_215 ) ) ;
}
static int
F_107 ( T_8 T_18 V_6 , T_9 * V_100 , int V_204 , T_13 * V_203 V_6 , T_10 * V_101 , int T_19 V_6 )
{
T_2 V_144 = NULL ;
T_8 V_217 = FALSE ;
struct V_43 * V_143 = NULL ;
if ( V_98 ) {
if ( ! V_164 ) {
V_143 = F_62 ( V_100 , V_203 -> V_34 , V_153 , V_163 ) ;
V_164 = TRUE ;
V_165 = V_143 ;
V_161 . V_35 = V_143 ;
} else {
V_143 = V_165 ;
V_161 . V_35 = V_143 ;
}
}
if ( V_143 ) {
if ( V_159 ) {
if ( V_143 -> V_166 ) {
if ( strncmp ( V_143 -> V_167 , V_159 , sizeof( V_143 -> V_167 ) ) != 0 ) {
F_74 ( V_143 -> V_167 , V_159 , sizeof( V_143 -> V_167 ) ) ;
if ( ( V_144 = F_75 ( V_168 , V_159 ) ) ) {
V_143 -> V_144 = V_144 ;
V_143 -> V_169 = TRUE ;
}
}
} else {
F_74 ( V_143 -> V_167 , V_159 , sizeof( V_143 -> V_167 ) ) ;
V_143 -> V_166 = TRUE ;
if ( ( V_144
= F_75 ( V_168 , V_159 ) ) ) {
V_143 -> V_144 = V_144 ;
V_143 -> V_169 = TRUE ;
} else {
if ( ( V_144 = F_8 ( V_203 -> V_34 -> V_218 ) ) ) {
V_143 -> V_144 = V_144 ;
V_143 -> V_169 = TRUE ;
}
}
}
} else {
if ( V_143 -> V_166 ) {
V_161 . V_167 = ( void * ) V_143 -> V_167 ;
V_161 . V_219 = TRUE ;
}
}
}
if ( V_143
&& V_143 -> V_169 ) {
V_144 = V_143 -> V_144 ;
V_217 = TRUE ;
}
if ( ! V_217 && V_220 ) {
V_217 = TRUE ;
V_144 = V_220 ;
}
if ( ! V_217 ) {
if ( V_168 && V_159 ) {
if ( ( V_144
= F_75 ( V_168 , V_159 ) ) ) {
V_217 = TRUE ;
} else {
if ( ( V_144
= F_8 ( V_203 -> V_34 -> V_218 ) ) ) {
V_217 = TRUE ;
} else {
V_144 = V_171 ;
V_217 = TRUE ;
}
}
} else {
if ( ( V_144 = F_8 ( V_203 -> V_34 -> V_218 ) ) ) {
V_217 = TRUE ;
} else {
V_144 = V_171 ;
V_217 = TRUE ;
}
}
} else {
}
if ( V_217 ) {
F_108 ( V_144 , V_100 , V_203 -> V_34 , V_101 , V_203 -> V_162 ) ;
F_109 ( V_203 -> V_34 -> V_154 , V_221 ) ;
}
return V_204 ;
}
void
F_110 ( T_2 V_222 , T_9 * V_100 , T_7 * V_34 , T_10 * V_101 )
{
V_220 = V_222 ;
F_111 {
F_64 ( V_100 , V_34 , V_101 , NULL ) ;
} F_112 {
V_220 = NULL ;
V_223 ;
} V_224 ;
V_220 = NULL ;
}
