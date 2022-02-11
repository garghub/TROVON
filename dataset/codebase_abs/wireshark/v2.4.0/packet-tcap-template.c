extern void F_1 ( T_1 V_1 , T_2 V_2 ) {
F_2 ( L_1 , V_1 , V_2 ) ;
F_2 ( L_2 , V_1 , V_3 ) ;
}
extern void F_3 ( T_1 V_1 , T_2 V_2 ) {
F_2 ( L_3 , V_1 , V_2 ) ;
F_2 ( L_2 , V_1 , V_3 ) ;
}
extern void F_4 ( T_1 V_1 , T_2 V_2 ) {
F_5 ( L_1 , V_1 , V_2 ) ;
if ( ! F_6 ( V_1 ) )
F_5 ( L_2 , V_1 , V_3 ) ;
}
extern void F_7 ( T_1 V_1 , T_2 V_2 V_4 ) {
F_5 ( L_3 , V_1 , V_2 ) ;
if ( ! F_8 ( V_1 ) )
F_5 ( L_2 , V_1 , V_3 ) ;
}
T_2 F_8 ( T_1 V_1 ) {
return F_9 ( V_5 , V_1 ) ;
}
T_2 F_6 ( T_1 V_1 ) {
return F_9 ( V_6 , V_1 ) ;
}
static void
F_10 ( T_3 V_7 , const char * V_8 , ... )
{
T_4 V_9 ;
if ( V_7 > V_10 ) return;
va_start ( V_9 , V_8 ) ;
vfprintf ( V_11 , V_8 , V_9 ) ;
va_end ( V_9 ) ;
}
static T_5
F_11 ( T_6 V_12 , T_6 V_13 )
{
const struct V_14 * V_15 = ( const struct V_14 * ) V_12 ;
const struct V_14 * V_16 = ( const struct V_14 * ) V_13 ;
return ( V_15 -> V_17 == V_16 -> V_17 ) ;
}
static T_3
F_12 ( T_6 V_18 )
{
const struct V_14 * V_19 = ( const struct V_14 * ) V_18 ;
return V_19 -> V_17 ;
}
static T_5
F_13 ( T_6 V_12 , T_6 V_13 )
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
F_14 ( T_6 V_18 )
{
const struct V_20 * V_19 = ( const struct V_20 * ) V_18 ;
T_3 V_24 ;
V_24 = V_19 -> V_23 ;
return V_24 ;
}
static T_5
F_15 ( T_6 V_12 , T_6 V_13 )
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
F_16 ( T_6 V_18 )
{
const struct V_25 * V_19 = ( const struct V_25 * ) V_18 ;
T_3 V_24 ;
V_24 = V_19 -> V_28 + V_19 -> V_29 ;
return V_24 ;
}
static T_5
F_17 ( T_6 V_12 , T_6 V_13 )
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
F_18 ( T_6 V_18 )
{
const struct V_30 * V_19 = ( const struct V_30 * ) V_18 ;
T_3 V_24 ;
V_24 = V_19 -> V_23 ;
return V_24 ;
}
static T_5
F_19 ( T_6 V_12 , T_6 V_13 )
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
F_20 ( T_6 V_18 )
{
const struct V_31 * V_19 = ( const struct V_31 * ) V_18 ;
T_3 V_24 ;
V_24 = V_19 -> V_23 ;
return V_24 ;
}
static void
F_21 ( struct V_32 * V_33 ,
T_7 * V_34 )
{
V_33 -> V_35 -> V_36 = V_34 -> V_37 ;
V_33 -> V_35 -> V_38 = 0 ;
V_33 -> V_35 -> V_39 = FALSE ;
V_33 -> V_35 -> V_40 = V_34 -> V_41 ;
}
static struct V_32 *
F_22 ( struct V_32 * V_42 ,
struct V_43 * V_44 ,
T_7 * V_34 )
{
struct V_32 * V_45 = NULL ;
V_45 = F_23 ( F_24 () , struct V_32 ) ;
V_45 -> V_35 = V_44 ;
V_44 -> V_46 = V_45 ;
V_45 -> V_47 = V_42 -> V_47 ;
V_45 -> V_35 -> V_36 = V_34 -> V_37 ;
V_45 -> V_48 = NULL ;
V_45 -> V_49 = V_42 ;
V_45 -> V_50 = FALSE ;
#ifdef F_25
F_10 ( 10 , L_4 , V_45 -> V_35 -> V_17 ) ;
#endif
V_42 -> V_48 = V_45 ;
if ( V_42 -> V_35 -> V_38 == 0 ) {
#ifdef F_25
F_10 ( 10 , L_5 ) ;
#endif
V_42 -> V_35 -> V_38 = V_34 -> V_37 - 1 ;
}
return V_45 ;
}
static void
F_26 ( struct V_51 * V_52 ,
T_7 * V_34 )
{
V_52 -> V_35 -> V_36 = V_34 -> V_37 ;
V_52 -> V_35 -> V_38 = 0 ;
V_52 -> V_35 -> V_39 = FALSE ;
V_52 -> V_35 -> V_40 = V_34 -> V_41 ;
}
static struct V_51 *
F_27 ( struct V_51 * V_53 ,
struct V_43 * V_44 ,
T_7 * V_34 )
{
struct V_51 * V_54 = NULL ;
V_54 = F_23 ( F_24 () , struct V_51 ) ;
V_54 -> V_35 = V_44 ;
V_44 -> V_55 = V_54 ;
V_54 -> V_56 = V_53 -> V_56 ;
V_54 -> V_35 -> V_36 = V_34 -> V_37 ;
V_54 -> V_57 = NULL ;
V_54 -> V_58 = V_53 ;
V_54 -> V_50 = FALSE ;
#ifdef F_25
F_10 ( 10 , L_6 , V_54 -> V_35 -> V_17 ) ;
#endif
V_53 -> V_57 = V_54 ;
if ( V_53 -> V_35 -> V_38 == 0 ) {
#ifdef F_25
F_10 ( 10 , L_5 ) ;
#endif
V_53 -> V_35 -> V_38 = V_34 -> V_37 - 1 ;
}
return V_54 ;
}
static struct V_59 *
F_28 ( struct V_59 * V_60 ,
struct V_43 * V_44 )
{
struct V_59 * V_61 = NULL ;
V_61 = F_23 ( F_24 () , struct V_59 ) ;
V_61 -> V_35 = V_44 ;
V_44 -> V_62 = V_61 ;
V_61 -> V_63 = V_60 -> V_63 ;
V_61 -> V_64 = NULL ;
V_61 -> V_65 = V_60 ;
V_61 -> V_50 = FALSE ;
#ifdef F_25
F_10 ( 10 , L_7 , V_61 -> V_35 -> V_17 ) ;
#endif
V_60 -> V_64 = V_61 ;
return V_61 ;
}
static struct V_66 *
F_29 ( struct V_66 * V_67 ,
struct V_43 * V_44 )
{
struct V_66 * V_68 = NULL ;
V_68 = F_23 ( F_24 () , struct V_66 ) ;
V_68 -> V_35 = V_44 ;
V_44 -> V_69 = V_68 ;
V_68 -> V_70 = V_67 -> V_70 ;
V_68 -> V_71 = NULL ;
V_68 -> V_72 = V_67 ;
V_68 -> V_50 = FALSE ;
#ifdef F_25
F_10 ( 10 , L_8 , V_68 -> V_35 -> V_17 ) ;
#endif
V_67 -> V_71 = V_68 ;
return V_68 ;
}
static struct V_32 *
F_30 ( struct V_20 * V_73 ,
T_7 * V_34 , T_8 V_74 )
{
struct V_32 * V_33 = NULL ;
V_33 = (struct V_32 * ) F_31 ( V_75 , V_73 ) ;
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
#ifdef F_25
F_10 ( 10 , L_9 , V_33 -> V_35 -> V_17 ) ;
#endif
return V_33 ;
}
#ifdef F_25
F_10 ( 60 , L_10 , V_33 -> V_35 -> V_17 ) ;
#endif
}
if( V_33 -> V_48 == NULL ) {
#ifdef F_25
F_10 ( 23 , L_11 ) ;
#endif
break;
}
V_33 = V_33 -> V_48 ;
} while ( V_33 != NULL ) ;
} else {
#ifdef F_25
F_10 ( 23 , L_12 ) ;
#endif
}
return NULL ;
}
static struct V_59 *
F_32 ( struct V_25 * V_76 ,
T_7 * V_34 )
{
struct V_59 * V_77 = NULL ;
V_77 = (struct V_59 * ) F_31 ( V_78 , V_76 ) ;
if( V_77 ) {
do {
if ( V_77 -> V_35 ) {
if ( V_34 -> V_37 >= V_77 -> V_35 -> V_36 &&
( V_77 -> V_35 -> V_38 ? V_34 -> V_37 <= V_77 -> V_35 -> V_38 : 1 ) ) {
#ifdef F_25
F_10 ( 10 , L_13 , V_77 -> V_35 -> V_17 ) ;
#endif
return V_77 ;
}
#ifdef F_25
F_10 ( 60 , L_14 , V_77 -> V_35 -> V_17 ) ;
#endif
}
if( V_77 -> V_64 == NULL ) {
#ifdef F_25
F_10 ( 23 , L_15 ) ;
#endif
break;
}
V_77 = V_77 -> V_64 ;
} while ( V_77 != NULL ) ;
} else {
#ifdef F_25
F_10 ( 23 , L_16 ) ;
#endif
}
return NULL ;
}
static struct V_66 *
F_33 ( struct V_30 * V_79 ,
T_7 * V_34 , T_8 V_80 )
{
struct V_66 * V_81 = NULL ;
V_81 = (struct V_66 * ) F_31 ( V_82 , V_79 ) ;
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
#ifdef F_25
F_10 ( 10 , L_17 , V_81 -> V_35 -> V_17 ) ;
#endif
return V_81 ;
}
#ifdef F_25
F_10 ( 60 , L_18 , V_81 -> V_35 -> V_17 ) ;
#endif
}
if( V_81 -> V_71 == NULL ) {
#ifdef F_25
F_10 ( 23 , L_19 ) ;
#endif
break;
}
V_81 = V_81 -> V_71 ;
} while ( V_81 != NULL ) ;
} else {
#ifdef F_25
F_10 ( 23 , L_20 ) ;
#endif
}
return NULL ;
}
static struct V_43 *
F_34 ( struct V_14 * V_83 ,
T_7 * V_34 )
{
struct V_14 * V_84 ;
struct V_43 * V_85 = NULL ;
V_84 = F_35 ( F_24 () , struct V_14 ) ;
V_84 -> V_17 = V_83 -> V_17 ;
V_85 = F_23 ( F_24 () , struct V_43 ) ;
V_85 -> V_19 = V_84 ;
V_85 -> V_17 = V_83 -> V_17 ;
V_85 -> V_36 = V_34 -> V_37 ;
#ifdef F_25
F_10 ( 10 , L_21 , V_85 -> V_17 ) ;
#endif
F_36 ( V_86 , V_84 , V_85 ) ;
return V_85 ;
}
static struct V_32 *
F_37 ( struct V_20 * V_73 ,
struct V_43 * V_44 )
{
struct V_20 * V_87 ;
struct V_32 * V_45 = NULL ;
V_87 = F_35 ( F_24 () , struct V_20 ) ;
V_87 -> V_21 = V_73 -> V_21 ;
V_87 -> V_23 = V_73 -> V_23 ;
V_87 -> V_22 = V_73 -> V_22 ;
V_45 = F_23 ( F_24 () , struct V_32 ) ;
V_45 -> V_47 = V_87 ;
V_45 -> V_35 = V_44 ;
V_44 -> V_46 = V_45 ;
V_45 -> V_50 = TRUE ;
V_45 -> V_48 = NULL ;
V_45 -> V_49 = NULL ;
#ifdef F_25
F_10 ( 10 , L_9 , V_45 -> V_35 -> V_17 ) ;
#endif
F_36 ( V_75 , V_87 , V_45 ) ;
return V_45 ;
}
static struct V_59 *
F_38 ( struct V_25 * V_76 ,
struct V_43 * V_44 )
{
struct V_25 * V_88 ;
struct V_59 * V_61 = NULL ;
V_88 = F_35 ( F_24 () , struct V_25 ) ;
V_88 -> V_21 = V_76 -> V_21 ;
V_88 -> V_28 = V_76 -> V_28 ;
V_88 -> V_29 = V_76 -> V_29 ;
V_88 -> V_26 = V_76 -> V_26 ;
V_88 -> V_27 = V_76 -> V_27 ;
V_61 = F_23 ( F_24 () , struct V_59 ) ;
V_61 -> V_63 = V_88 ;
V_61 -> V_35 = V_44 ;
V_44 -> V_62 = V_61 ;
V_61 -> V_50 = TRUE ;
V_61 -> V_64 = NULL ;
V_61 -> V_65 = NULL ;
#ifdef F_25
F_10 ( 10 , L_13 , V_61 -> V_35 -> V_17 ) ;
#endif
F_36 ( V_78 , V_88 , V_61 ) ;
return V_61 ;
}
static struct V_66 *
F_39 ( struct V_30 * V_79 ,
struct V_43 * V_44 )
{
struct V_30 * V_89 ;
struct V_66 * V_68 = NULL ;
V_89 = F_35 ( F_24 () , struct V_30 ) ;
V_89 -> V_21 = V_79 -> V_21 ;
V_89 -> V_23 = V_79 -> V_23 ;
V_89 -> V_22 = V_79 -> V_22 ;
V_68 = F_23 ( F_24 () , struct V_66 ) ;
V_68 -> V_70 = V_89 ;
V_68 -> V_35 = V_44 ;
V_44 -> V_69 = V_68 ;
V_68 -> V_50 = TRUE ;
V_68 -> V_71 = NULL ;
V_68 -> V_72 = NULL ;
#ifdef F_25
F_10 ( 10 , L_17 , V_68 -> V_35 -> V_17 ) ;
#endif
F_36 ( V_82 , V_89 , V_68 ) ;
return V_68 ;
}
static struct V_51 *
F_40 ( struct V_31 * V_90 ,
struct V_43 * V_44 )
{
struct V_31 * V_91 ;
struct V_51 * V_54 = NULL ;
V_91 = F_35 ( F_24 () , struct V_31 ) ;
V_91 -> V_21 = V_90 -> V_21 ;
V_91 -> V_23 = V_90 -> V_23 ;
V_91 -> V_26 = V_90 -> V_26 ;
V_91 -> V_27 = V_90 -> V_27 ;
V_54 = F_23 ( F_24 () , struct V_51 ) ;
V_54 -> V_56 = V_91 ;
V_54 -> V_35 = V_44 ;
V_44 -> V_55 = V_54 ;
V_54 -> V_50 = TRUE ;
V_54 -> V_57 = NULL ;
V_54 -> V_58 = NULL ;
#ifdef F_25
F_10 ( 10 , L_22 , V_54 -> V_35 -> V_17 ) ;
#endif
F_36 ( V_92 , V_91 , V_54 ) ;
return V_54 ;
}
static struct V_59 *
F_41 ( struct V_25 * V_76 ,
struct V_43 * V_44 )
{
struct V_59 * V_93 = NULL ;
struct V_59 * V_77 = NULL ;
V_93 = (struct V_59 * )
F_31 ( V_78 , V_76 ) ;
if ( V_93 ) {
do {
if ( ! V_93 -> V_64 ) {
V_77 = F_28 ( V_93 ,
V_44 ) ;
break;
}
V_93 = V_93 -> V_64 ;
} while ( V_93 != NULL );
} else {
V_77 = F_38 ( V_76 ,
V_44 ) ;
}
return V_77 ;
}
static struct V_66 *
F_42 ( struct V_30 * V_79 ,
struct V_43 * V_44 )
{
struct V_66 * V_94 = NULL ;
struct V_66 * V_81 = NULL ;
V_94 = (struct V_66 * )
F_31 ( V_82 , V_79 ) ;
if ( V_94 ) {
do {
if ( ! V_94 -> V_71 ) {
V_81 = F_29 ( V_94 ,
V_44 ) ;
break;
}
V_94 = V_94 -> V_71 ;
} while ( V_94 != NULL );
} else {
V_81 = F_39 ( V_79 ,
V_44 ) ;
}
return V_81 ;
}
static struct V_43 *
F_43 ( T_9 * V_95 , T_7 * V_34 , T_10 * V_96 ,
struct V_97 * V_98 )
{
struct V_43 * V_44 = NULL ;
struct V_14 V_99 ;
struct V_32 * V_33 , * V_45 = NULL ;
struct V_20 V_100 ;
T_11 * V_101 ;
T_11 * V_102 = NULL ;
T_10 * V_103 = NULL ;
#ifdef F_25
F_10 ( 51 , L_23 , F_44 ( F_45 () , & V_34 -> V_104 ) , V_98 -> V_28 , F_44 ( F_45 () , & V_34 -> V_105 ) ) ;
#endif
V_100 . V_23 = V_98 -> V_28 ;
if ( V_34 -> V_104 . type == V_106 && V_34 -> V_105 . type == V_106 )
{
V_100 . V_22 = F_46 ( ( const V_107 * ) V_34 -> V_104 . V_108 ) ;
} else {
V_100 . V_22 = F_47 ( F_44 ( F_45 () , & V_34 -> V_104 ) ) ;
}
V_100 . V_21 = F_14 ( & V_100 ) ;
#ifdef F_25
F_10 ( 10 , L_24 , V_34 -> V_37 ) ;
F_10 ( 11 , L_25 , V_100 . V_21 ) ;
F_10 ( 51 , L_26 , F_44 ( F_45 () , & V_34 -> V_104 ) ) ;
F_10 ( 51 , L_27 , V_100 . V_23 ) ;
#endif
V_33 = (struct V_32 * )
F_31 ( V_75 , & V_100 ) ;
if ( V_33 ) {
do {
if ( V_34 -> V_37 == V_33 -> V_35 -> V_36 ) {
#ifdef F_25
F_10 ( 22 , L_28 ) ;
#endif
V_44 = V_33 -> V_35 ;
break;
}
if ( ! V_33 -> V_48 ) {
if ( ( V_33 -> V_35 -> V_38 != 0
&& V_34 -> V_37 > V_33 -> V_35 -> V_36
&& ( T_3 ) V_34 -> V_41 . V_109 > ( T_3 ) ( V_33 -> V_35 -> V_40 . V_109 + V_110 )
) ||
( V_33 -> V_35 -> V_38 == 0
&& V_34 -> V_37 > V_33 -> V_35 -> V_36
&& ( T_3 ) V_34 -> V_41 . V_109 > ( T_3 ) ( V_33 -> V_35 -> V_40 . V_109 + V_111 )
)
)
{
#ifdef F_25
F_10 ( 12 , L_29 , V_100 . V_21 ) ;
F_10 ( 12 , L_30 , V_34 -> V_37 , V_33 -> V_35 -> V_38 ) ;
#endif
V_99 . V_17 = V_112 ++ ;
V_44 = F_34 ( & V_99 , V_34 ) ;
V_45 = F_22 ( V_33 ,
V_44 ,
V_34 ) ;
#ifdef F_25
F_10 ( 12 , L_31 , V_100 . V_21 ) ;
#endif
F_21 ( V_45 , V_34 ) ;
} else {
if ( V_33 -> V_35 -> V_113 ) {
#ifdef F_25
F_10 ( 12 , L_32 , V_100 . V_21 ) ;
F_10 ( 12 , L_30 , V_34 -> V_37 , V_33 -> V_35 -> V_38 ) ;
#endif
V_99 . V_17 = V_112 ++ ;
V_44 = F_34 ( & V_99 , V_34 ) ;
V_45 = F_22 ( V_33 ,
V_44 ,
V_34 ) ;
#ifdef F_25
F_10 ( 12 , L_33 , V_100 . V_21 ) ;
#endif
F_21 ( V_45 , V_34 ) ;
} else {
#ifdef F_25
F_10 ( 21 , L_34 , V_33 -> V_35 -> V_36 ) ;
#endif
V_44 = V_33 -> V_35 ;
if ( V_114 && V_96 ) {
V_103 = F_48 ( V_96 , V_95 , 0 , - 1 , V_115 , & V_102 , L_35 ) ;
F_49 ( V_102 ) ;
V_101 = F_50 ( V_103 , V_116 , V_95 , 0 , 0 ,
V_44 -> V_36 ,
L_36 ,
V_44 -> V_17 , V_44 -> V_36 ) ;
F_49 ( V_101 ) ;
}
return V_44 ;
}
}
break;
}
V_33 = V_33 -> V_48 ;
} while ( V_33 != NULL );
} else {
#ifdef F_25
F_10 ( 10 , L_37 , V_100 . V_21 ) ;
#endif
V_99 . V_17 = V_112 ++ ;
V_44 = F_34 ( & V_99 , V_34 ) ;
V_33 = F_37 ( & V_100 , V_44 ) ;
#ifdef F_25
F_10 ( 11 , L_31 , V_100 . V_21 ) ;
F_10 ( 11 , L_38 , V_34 -> V_37 ) ;
#endif
F_21 ( V_33 , V_34 ) ;
}
if ( V_114 && V_96 &&
V_44 &&
V_44 -> V_17 ) {
V_103 = F_48 ( V_96 , V_95 , 0 , 0 , V_115 , & V_102 , L_35 ) ;
F_49 ( V_102 ) ;
V_101 = F_51 ( V_103 , V_117 , V_95 , 0 , 0 , V_44 -> V_17 ) ;
F_49 ( V_101 ) ;
if( V_44 -> V_38 != 0 ) {
#ifdef F_25
F_10 ( 20 , L_39 , V_44 -> V_38 ) ;
#endif
V_101 = F_50 ( V_103 , V_118 , V_95 , 0 , 0 ,
V_44 -> V_38 ,
L_40 ,
V_44 -> V_38 ) ;
F_49 ( V_101 ) ;
}
}
return V_44 ;
}
static struct V_43 *
F_52 ( T_9 * V_95 , T_7 * V_34 , T_10 * V_96 ,
struct V_97 * V_98 )
{
struct V_43 * V_44 = NULL ;
struct V_59 * V_77 ;
struct V_25 V_119 ;
struct V_20 V_100 ;
struct V_32 * V_33 ;
struct V_30 V_120 ;
T_11 * V_101 ;
T_11 * V_102 = NULL ;
T_10 * V_103 = NULL ;
T_8 V_121 = TRUE ;
#ifdef F_25
F_10 ( 51 , L_41 , F_44 ( F_45 () , & V_34 -> V_104 ) , V_98 -> V_28 , F_44 ( F_45 () , & V_34 -> V_105 ) , V_98 -> V_29 ) ;
F_10 ( 10 , L_42 , V_34 -> V_37 ) ;
#endif
V_119 . V_28 = V_98 -> V_28 ;
V_119 . V_29 = V_98 -> V_29 ;
if ( V_34 -> V_104 . type == V_106 && V_34 -> V_105 . type == V_106 )
{
V_119 . V_26 = F_46 ( ( const V_107 * ) V_34 -> V_104 . V_108 ) ;
V_119 . V_27 = F_46 ( ( const V_107 * ) V_34 -> V_105 . V_108 ) ;
} else {
V_119 . V_26 = F_47 ( F_44 ( F_45 () , & V_34 -> V_104 ) ) ;
V_119 . V_27 = F_47 ( F_44 ( F_45 () , & V_34 -> V_105 ) ) ;
}
V_119 . V_21 = F_16 ( & V_119 ) ;
#ifdef F_25
F_10 ( 11 , L_43 , V_119 . V_21 ) ;
F_10 ( 51 , L_44 , F_44 ( F_45 () , & V_34 -> V_104 ) , F_44 ( F_45 () , & V_34 -> V_105 ) ) ;
F_10 ( 51 , L_45 , V_119 . V_28 , V_119 . V_29 ) ;
#endif
V_77 = F_32 ( & V_119 , V_34 ) ;
if( V_77 ) {
#ifdef F_25
F_10 ( 12 , L_46 ) ;
#endif
V_44 = V_77 -> V_35 ;
} else {
#ifdef F_25
F_10 ( 12 , L_47 ) ;
#endif
V_100 . V_23 = V_98 -> V_29 ;
if ( V_34 -> V_104 . type == V_106 && V_34 -> V_105 . type == V_106 )
{
V_100 . V_22 = F_46 ( ( const V_107 * ) V_34 -> V_105 . V_108 ) ;
} else {
V_100 . V_22 = F_47 ( F_44 ( F_45 () , & V_34 -> V_105 ) ) ;
}
V_100 . V_21 = F_14 ( & V_100 ) ;
#ifdef F_25
F_10 ( 11 , L_48 , V_100 . V_21 ) ;
F_10 ( 51 , L_26 , F_44 ( F_45 () , & V_34 -> V_105 ) ) ;
F_10 ( 51 , L_27 , V_100 . V_23 ) ;
#endif
V_33 = F_30 ( & V_100 , V_34 , FALSE ) ;
if( ! V_33 ) {
V_122:
#ifdef F_25
F_10 ( 12 , L_49 ) ;
#endif
V_121 = FALSE ;
V_100 . V_23 = V_98 -> V_28 ;
if ( V_34 -> V_104 . type == V_106 && V_34 -> V_105 . type == V_106 )
{
V_100 . V_22 = F_46 ( ( const V_107 * ) V_34 -> V_104 . V_108 ) ;
} else {
V_100 . V_22 = F_47 ( F_44 ( F_45 () , & V_34 -> V_104 ) ) ;
}
V_100 . V_21 = F_14 ( & V_100 ) ;
#ifdef F_25
F_10 ( 11 , L_48 , V_100 . V_21 ) ;
F_10 ( 51 , L_26 , F_44 ( F_45 () , & V_34 -> V_104 ) ) ;
F_10 ( 51 , L_27 , V_100 . V_23 ) ;
#endif
V_33 = F_30 ( & V_100 , V_34 , FALSE ) ;
}
if( V_33 &&
! V_33 -> V_35 -> V_62 ) {
#ifdef F_25
F_10 ( 12 , L_50 ) ;
#endif
V_44 = V_33 -> V_35 ;
V_44 -> V_39 = TRUE ;
#ifdef F_25
F_10 ( 10 , L_51 , V_119 . V_21 ) ;
F_10 ( 11 , L_52 , V_34 -> V_37 ) ;
#endif
F_41 ( & V_119 ,
V_33 -> V_35 ) ;
V_120 . V_23 = V_121 ? V_98 -> V_29 : V_98 -> V_28 ;
if ( V_34 -> V_104 . type == V_106 && V_34 -> V_105 . type == V_106 )
{
V_120 . V_22 = F_46 ( ( const V_107 * ) ( V_121 ? V_34 -> V_105 . V_108 : V_34 -> V_104 . V_108 ) ) ;
} else {
V_120 . V_22 = F_47 ( F_44 ( F_45 () , V_121 ? & V_34 -> V_105 : & V_34 -> V_104 ) ) ;
}
V_120 . V_21 = F_18 ( & V_120 ) ;
#ifdef F_25
F_10 ( 10 , L_53 , V_120 . V_21 ) ;
F_10 ( 51 , L_26 , F_44 ( F_45 () , V_121 ? & V_34 -> V_105 : & V_34 -> V_104 ) ) ;
F_10 ( 51 , L_54 , V_120 . V_23 ) ;
F_10 ( 11 , L_38 , V_34 -> V_37 ) ;
#endif
F_42 ( & V_120 ,
V_33 -> V_35 ) ;
} else {
#ifdef F_25
F_10 ( 12 , L_55 ) ;
#endif
if ( V_121 ) {
goto V_122;
}
}
}
if ( V_114 && V_96 &&
V_44 &&
V_44 -> V_17 ) {
V_103 = F_48 ( V_96 , V_95 , 0 , - 1 , V_115 , & V_102 , L_35 ) ;
F_49 ( V_102 ) ;
V_101 = F_51 ( V_103 , V_117 , V_95 , 0 , 0 , V_44 -> V_17 ) ;
F_49 ( V_101 ) ;
}
return V_44 ;
}
static struct V_43 *
F_53 ( T_9 * V_95 , T_7 * V_34 , T_10 * V_96 ,
struct V_97 * V_98 )
{
struct V_43 * V_44 = NULL ;
struct V_30 V_120 ;
struct V_66 * V_81 = NULL ;
struct V_20 V_100 ;
struct V_32 * V_33 = NULL ;
T_11 * V_101 ;
T_12 V_123 ;
T_11 * V_102 = NULL ;
T_10 * V_103 = NULL ;
#ifdef F_25
F_10 ( 51 , L_56 , F_44 ( F_45 () , & V_34 -> V_104 ) , F_44 ( F_45 () , & V_34 -> V_105 ) , V_98 -> V_29 ) ;
F_10 ( 10 , L_57 , V_34 -> V_37 ) ;
#endif
V_120 . V_23 = V_98 -> V_29 ;
if ( V_34 -> V_104 . type == V_106 && V_34 -> V_105 . type == V_106 )
{
V_120 . V_22 = F_46 ( ( const V_107 * ) V_34 -> V_105 . V_108 ) ;
} else {
V_120 . V_22 = F_47 ( F_44 ( F_45 () , & V_34 -> V_105 ) ) ;
}
V_120 . V_21 = F_18 ( & V_120 ) ;
#ifdef F_25
F_10 ( 11 , L_58 , V_120 . V_21 ) ;
F_10 ( 11 , L_26 , F_44 ( F_45 () , & V_34 -> V_105 ) ) ;
F_10 ( 51 , L_54 , V_120 . V_23 ) ;
#endif
V_81 = F_33 ( & V_120 , V_34 , TRUE ) ;
if( ! V_81 ) {
#ifdef F_25
F_10 ( 12 , L_59 ) ;
#endif
V_100 . V_23 = V_98 -> V_29 ;
if ( V_34 -> V_104 . type == V_106 && V_34 -> V_105 . type == V_106 )
{
V_100 . V_22 = F_46 ( ( const V_107 * ) V_34 -> V_105 . V_108 ) ;
} else {
V_100 . V_22 = F_47 ( F_44 ( F_45 () , & V_34 -> V_105 ) ) ;
}
V_100 . V_21 = F_14 ( & V_100 ) ;
#ifdef F_25
F_10 ( 11 , L_48 , V_100 . V_21 ) ;
F_10 ( 51 , L_26 , F_44 ( F_45 () , & V_34 -> V_105 ) ) ;
F_10 ( 51 , L_54 , V_100 . V_23 ) ;
#endif
V_33 = F_30 ( & V_100 , V_34 , FALSE ) ;
if( ! V_33 ) {
#ifdef F_25
F_10 ( 12 , L_55 ) ;
#endif
}
}
if ( V_81 ) {
V_44 = V_81 -> V_35 ;
} else if ( V_33 ) {
V_44 = V_33 -> V_35 ;
}
if ( V_44 ) {
#ifdef F_25
F_10 ( 12 , L_60 , V_44 -> V_36 ) ;
#endif
if ( V_114 && V_96 ) {
V_103 = F_48 ( V_96 , V_95 , 0 , - 1 , V_115 , & V_102 , L_35 ) ;
F_49 ( V_102 ) ;
V_101 = F_51 ( V_103 , V_117 , V_95 , 0 , 0 , V_44 -> V_17 ) ;
F_49 ( V_101 ) ;
}
#ifdef F_25
F_10 ( 20 , L_61 , V_44 -> V_36 ) ;
#endif
if ( V_114 && V_103 ) {
V_101 = F_50 ( V_103 , V_124 , V_95 , 0 , 0 ,
V_44 -> V_36 ,
L_62 ,
V_44 -> V_36 ) ;
F_49 ( V_101 ) ;
F_54 ( & V_123 , & V_34 -> V_41 , & V_44 -> V_40 ) ;
V_101 = F_55 ( V_103 , V_125 , V_95 , 0 , 0 , & V_123 ) ;
F_49 ( V_101 ) ;
}
F_56 ( V_44 , V_34 ) ;
} else {
#ifdef F_25
F_10 ( 12 , L_63 ) ;
#endif
}
return V_44 ;
}
static struct V_43 *
F_57 ( T_9 * V_95 , T_7 * V_34 , T_10 * V_96 ,
struct V_97 * V_98 )
{
struct V_43 * V_44 = NULL ;
struct V_14 V_99 ;
struct V_51 * V_52 , * V_54 ;
struct V_31 V_126 ;
T_11 * V_101 ;
T_12 V_123 ;
T_8 V_127 = FALSE ;
T_10 * V_103 = NULL ;
T_11 * V_102 = NULL ;
V_126 . V_23 = V_98 -> V_28 ;
if ( V_34 -> V_104 . type == V_106 && V_34 -> V_105 . type == V_106 )
{
V_126 . V_26 = F_46 ( ( const V_107 * ) V_34 -> V_104 . V_108 ) ;
V_126 . V_27 = F_46 ( ( const V_107 * ) V_34 -> V_105 . V_108 ) ;
} else {
V_126 . V_26 = F_47 ( F_44 ( F_45 () , & V_34 -> V_104 ) ) ;
V_126 . V_27 = F_47 ( F_44 ( F_45 () , & V_34 -> V_105 ) ) ;
}
V_126 . V_21 = F_20 ( & V_126 ) ;
#ifdef F_25
F_10 ( 10 , L_64 , V_34 -> V_37 ) ;
F_10 ( 11 , L_25 , V_126 . V_21 ) ;
F_10 ( 51 , L_65 , F_44 ( F_45 () , & V_34 -> V_104 ) , F_44 ( F_45 () , & V_34 -> V_105 ) ) ;
F_10 ( 51 , L_54 , V_126 . V_23 ) ;
#endif
V_52 = (struct V_51 * )
F_31 ( V_92 , & V_126 ) ;
if ( V_52 ) {
do {
if ( V_34 -> V_37 == V_52 -> V_35 -> V_36 ) {
#ifdef F_25
F_10 ( 22 , L_66 ) ;
#endif
V_127 = FALSE ;
V_44 = V_52 -> V_35 ;
break;
}
if ( V_34 -> V_37 == V_52 -> V_35 -> V_38 ) {
#ifdef F_25
F_10 ( 22 , L_67 ) ;
#endif
V_127 = TRUE ;
V_44 = V_52 -> V_35 ;
break;
}
if ( V_34 -> V_37 > V_52 -> V_35 -> V_36 &&
V_52 -> V_35 -> V_38 == 0 ) {
#ifdef F_25
F_10 ( 12 , L_31 , V_126 . V_21 ) ;
#endif
V_52 -> V_35 -> V_38 = V_34 -> V_37 ;
V_52 -> V_35 -> V_39 = TRUE ;
V_52 -> V_35 -> V_113 = TRUE ;
V_44 = V_52 -> V_35 ;
V_127 = TRUE ;
if ( V_114 && V_96 ) {
V_103 = F_48 ( V_96 , V_95 , 0 , - 1 , V_115 , & V_102 , L_35 ) ;
F_49 ( V_102 ) ;
V_101 = F_51 ( V_103 , V_117 , V_95 , 0 , 0 , V_44 -> V_17 ) ;
F_49 ( V_101 ) ;
#ifdef F_25
F_10 ( 20 , L_61 , V_44 -> V_36 ) ;
#endif
V_101 = F_50 ( V_103 , V_124 , V_95 , 0 , 0 ,
V_44 -> V_36 ,
L_62 ,
V_44 -> V_36 ) ;
F_49 ( V_101 ) ;
F_54 ( & V_123 , & V_34 -> V_41 , & V_44 -> V_40 ) ;
V_101 = F_55 ( V_103 , V_125 , V_95 , 0 , 0 , & V_123 ) ;
F_49 ( V_101 ) ;
}
break;
}
if ( ! V_52 -> V_57 ) {
if ( ( V_52 -> V_35 -> V_38 != 0
&& V_34 -> V_37 > V_52 -> V_35 -> V_36
&& ( T_3 ) V_34 -> V_41 . V_109 > ( T_3 ) ( V_52 -> V_35 -> V_40 . V_109 + V_110 )
) ||
( V_52 -> V_35 -> V_38 == 0
&& V_34 -> V_37 > V_52 -> V_35 -> V_36
&& ( T_3 ) V_34 -> V_41 . V_109 > ( T_3 ) ( V_52 -> V_35 -> V_40 . V_109 + V_111 )
)
)
{
#ifdef F_25
F_10 ( 12 , L_29 , V_126 . V_21 ) ;
F_10 ( 12 , L_30 , V_34 -> V_37 , V_52 -> V_35 -> V_38 ) ;
#endif
V_99 . V_17 = V_112 ++ ;
V_44 = F_34 ( & V_99 , V_34 ) ;
V_54 = F_27 ( V_52 ,
V_44 ,
V_34 ) ;
#ifdef F_25
F_10 ( 12 , L_31 , V_126 . V_21 ) ;
#endif
F_26 ( V_54 , V_34 ) ;
V_52 = V_54 ;
} else {
if ( V_52 -> V_35 -> V_113 ) {
#ifdef F_25
F_10 ( 12 , L_32 , V_126 . V_21 ) ;
F_10 ( 12 , L_30 , V_34 -> V_37 , V_52 -> V_35 -> V_38 ) ;
#endif
V_99 . V_17 = V_112 ++ ;
V_44 = F_34 ( & V_99 , V_34 ) ;
V_54 = F_27 ( V_52 ,
V_44 ,
V_34 ) ;
#ifdef F_25
F_10 ( 12 , L_33 , V_126 . V_21 ) ;
#endif
F_26 ( V_54 , V_34 ) ;
V_52 = V_54 ;
} else {
V_44 = V_52 -> V_35 ;
#ifdef F_25
F_10 ( 12 , L_60 , V_44 -> V_36 ) ;
#endif
if ( V_114 && V_96 ) {
V_103 = F_48 ( V_96 , V_95 , 0 , - 1 , V_115 , & V_102 , L_35 ) ;
F_49 ( V_102 ) ;
V_101 = F_51 ( V_103 , V_117 , V_95 , 0 , 0 , V_44 -> V_17 ) ;
F_49 ( V_101 ) ;
#ifdef F_25
F_10 ( 20 , L_61 , V_44 -> V_36 ) ;
#endif
V_101 = F_50 ( V_103 , V_124 , V_95 , 0 , 0 ,
V_44 -> V_36 ,
L_62 ,
V_44 -> V_36 ) ;
F_49 ( V_101 ) ;
F_54 ( & V_123 , & V_34 -> V_41 , & V_44 -> V_40 ) ;
V_101 = F_55 ( V_103 , V_125 , V_95 , 0 , 0 , & V_123 ) ;
F_49 ( V_101 ) ;
}
V_44 = V_52 -> V_35 ;
}
}
break;
}
V_52 = V_52 -> V_57 ;
} while ( V_52 != NULL );
} else {
#ifdef F_25
F_10 ( 10 , L_37 , V_126 . V_21 ) ;
#endif
V_99 . V_17 = V_112 ++ ;
V_44 = F_34 ( & V_99 , V_34 ) ;
V_52 = F_40 ( & V_126 , V_44 ) ;
#ifdef F_25
F_10 ( 11 , L_31 , V_126 . V_21 ) ;
F_10 ( 11 , L_38 , V_34 -> V_37 ) ;
#endif
F_26 ( V_52 , V_34 ) ;
}
if ( V_114 && V_96 &&
V_44 &&
V_44 -> V_17 ) {
V_103 = F_48 ( V_96 , V_95 , 0 , - 1 , V_115 , & V_102 , L_35 ) ;
F_49 ( V_102 ) ;
V_101 = F_51 ( V_103 , V_117 , V_95 , 0 , 0 , V_44 -> V_17 ) ;
F_49 ( V_101 ) ;
}
if( V_114 && V_103 &&
V_52 -> V_35 -> V_38 != 0 ) {
if ( ! V_127 ) {
#ifdef F_25
F_10 ( 20 , L_39 , V_52 -> V_35 -> V_38 ) ;
#endif
V_101 = F_50 ( V_103 , V_118 , V_95 , 0 , 0 ,
V_52 -> V_35 -> V_38 ,
L_40 ,
V_52 -> V_35 -> V_38 ) ;
F_49 ( V_101 ) ;
} else {
#ifdef F_25
F_10 ( 20 , L_61 , V_44 -> V_36 ) ;
#endif
if ( V_114 ) {
V_101 = F_50 ( V_103 , V_124 , V_95 , 0 , 0 ,
V_44 -> V_36 ,
L_62 ,
V_44 -> V_36 ) ;
F_49 ( V_101 ) ;
F_54 ( & V_123 , & V_34 -> V_41 , & V_44 -> V_40 ) ;
V_101 = F_55 ( V_103 , V_125 , V_95 , 0 , 0 , & V_123 ) ;
F_49 ( V_101 ) ;
}
}
}
return V_44 ;
}
struct V_43 *
F_58 ( T_9 * V_95 , T_7 * V_34 , T_10 * V_96 ,
struct V_97 * V_98 )
{
struct V_43 * V_128 = NULL ;
if( V_34 == NULL || V_34 -> V_37 == 0 ) {
return NULL ;
}
switch ( V_98 -> V_129 ) {
case V_130 :
#ifdef F_25
F_10 ( 1 , L_68 ) ;
#endif
V_128 = F_43 ( V_95 , V_34 , V_96 , V_98 ) ;
break;
case V_131 :
#ifdef F_25
F_10 ( 1 , L_69 ) ;
#endif
V_128 = F_52 ( V_95 , V_34 , V_96 , V_98 ) ;
break;
case V_132 :
#ifdef F_25
F_10 ( 1 , L_70 ) ;
#endif
V_128 = F_53 ( V_95 , V_34 , V_96 , V_98 ) ;
break;
case V_133 :
#ifdef F_25
F_10 ( 1 , L_71 ) ;
#endif
V_128 = F_53 ( V_95 , V_34 , V_96 , V_98 ) ;
break;
case V_134 :
case V_135 :
#ifdef F_25
F_10 ( 1 , L_72 ) ;
#endif
V_128 = F_57 ( V_95 , V_34 , V_96 , V_98 ) ;
break;
default:
#ifdef F_25
F_10 ( 1 , L_73 , V_98 -> V_129 ) ;
#endif
break;
}
#ifdef F_25
if ( V_128 )
F_10 ( 1 , L_74 , V_128 -> V_17 ) ;
#endif
return V_128 ;
}
struct V_97 *
F_59 ( void )
{
struct V_97 * V_98 ;
V_136 ++ ;
if( V_136 == V_137 ) {
V_136 = 0 ;
}
V_98 = & V_138 [ V_136 ] ;
memset ( V_98 , 0 , sizeof( struct V_97 ) ) ;
return V_98 ;
}
void
F_56 ( struct V_43 * V_44 ,
T_7 * V_34 )
{
#ifdef F_25
F_10 ( 60 , L_75 ) ;
#endif
if ( V_44 ) {
V_44 -> V_39 = TRUE ;
V_44 -> V_38 = V_34 -> V_37 ;
V_44 -> V_139 = V_34 -> V_41 ;
V_44 -> V_113 = TRUE ;
if ( V_44 -> V_69
&& ! V_140 ) {
if ( V_44 -> V_69 -> V_71 ) {
if ( V_44 -> V_69 -> V_72 ) {
#ifdef F_25
F_10 ( 20 , L_76 ) ;
#endif
V_44 -> V_69 -> V_72 -> V_71
= V_44 -> V_69 -> V_71 ;
V_44 -> V_69 -> V_71 -> V_72
= V_44 -> V_69 -> V_72 ;
F_60 ( V_82 , V_44 -> V_69 -> V_70 ) ;
} else {
#ifdef F_25
F_10 ( 20 , L_77 ) ;
#endif
}
} else if ( ! V_140 ) {
#ifdef F_25
F_10 ( 20 , L_78 ) ;
#endif
F_60 ( V_82 , V_44 -> V_69 -> V_70 ) ;
}
}
if ( V_44 -> V_62
&& ! V_140 ) {
if ( V_44 -> V_62 -> V_64 ) {
if ( V_44 -> V_62 -> V_65 ) {
#ifdef F_25
F_10 ( 20 , L_79 ) ;
#endif
V_44 -> V_62 -> V_65 -> V_64
= V_44 -> V_62 -> V_64 ;
V_44 -> V_62 -> V_64 -> V_65
= V_44 -> V_62 -> V_65 ;
F_60 ( V_78 , V_44 -> V_62 -> V_63 ) ;
} else {
#ifdef F_25
F_10 ( 20 , L_80 ) ;
#endif
}
} else if ( ! V_140 ) {
#ifdef F_25
F_10 ( 20 , L_81 ) ;
#endif
F_60 ( V_78 , V_44 -> V_62 -> V_63 ) ;
}
}
if ( V_44 -> V_46
&& ! V_140 ) {
if ( V_44 -> V_46 -> V_48 ) {
if ( V_44 -> V_46 -> V_49 ) {
#ifdef F_25
F_10 ( 20 , L_82 ) ;
#endif
V_44 -> V_46 -> V_49 -> V_48
= V_44 -> V_46 -> V_48 ;
V_44 -> V_46 -> V_48 -> V_49
= V_44 -> V_46 -> V_49 ;
F_60 ( V_75 , V_44 -> V_46 -> V_47 ) ;
} else {
#ifdef F_25
F_10 ( 20 , L_83 ) ;
#endif
}
} else if ( ! V_140 ) {
#ifdef F_25
F_10 ( 20 , L_84 ) ;
#endif
F_60 ( V_75 , V_44 -> V_46 -> V_47 ) ;
}
}
if ( V_44 -> V_55
&& ! V_140 ) {
if ( V_44 -> V_55 -> V_57 ) {
if ( V_44 -> V_55 -> V_58 ) {
#ifdef F_25
F_10 ( 20 , L_85 ) ;
#endif
V_44 -> V_55 -> V_58 -> V_57
= V_44 -> V_55 -> V_57 ;
V_44 -> V_55 -> V_57 -> V_58
= V_44 -> V_55 -> V_58 ;
F_60 ( V_92 , V_44 -> V_55 -> V_56 ) ;
} else {
#ifdef F_25
F_10 ( 20 , L_86 ) ;
#endif
}
} else if ( ! V_140 ) {
#ifdef F_25
F_10 ( 20 , L_87 ) ;
#endif
F_60 ( V_92 , V_44 -> V_55 -> V_56 ) ;
}
}
if ( ! V_140 ) {
#ifdef F_25
F_10 ( 20 , L_88 ) ;
#endif
F_60 ( V_86 , V_44 -> V_19 ) ;
}
} else {
#ifdef F_25
F_10 ( 20 , L_89 ) ;
#endif
}
}
static int
F_61 ( T_9 * V_95 , T_7 * V_34 , T_10 * V_141 , void * V_108 V_4 )
{
T_11 * V_142 = NULL ;
T_10 * V_96 = NULL ;
struct V_43 * V_143 ;
T_2 V_144 ;
T_13 V_145 ;
T_14 V_146 ;
T_8 V_147 ;
T_5 V_148 ;
struct V_149 * V_150 ;
F_62 ( V_95 , 0 , & V_146 , & V_147 , & V_148 ) ;
if( V_146 == V_151 ) {
switch ( V_148 ) {
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
case 6 :
case 22 :
return F_63 ( V_152 , V_95 , V_34 , V_141 ) ;
default:
return F_64 ( V_95 ) ;
}
}
F_65 ( & V_145 , V_153 , TRUE , V_34 ) ;
V_154 = V_141 ;
V_155 = NULL ;
F_66 ( V_34 -> V_156 , V_157 , L_90 ) ;
if( V_141 ) {
V_142 = F_67 ( V_141 , V_158 , V_95 , 0 , - 1 , V_159 ) ;
V_96 = F_68 ( V_142 , V_160 ) ;
V_155 = V_96 ;
}
V_161 = NULL ;
V_162 = NULL ;
V_150 = F_23 ( F_45 () , struct V_149 ) ;
V_145 . V_163 = V_150 ;
V_164 = F_59 () ;
V_165 = FALSE ;
V_166 = NULL ;
F_69 ( FALSE , V_95 , 0 , & V_145 , V_96 , - 1 ) ;
if ( V_167 && ! V_165 ) {
V_143 = F_58 ( V_95 , V_34 , V_155 , V_164 ) ;
V_150 -> V_35 = V_143 ;
if ( V_143 && V_161 && ! V_143 -> V_168 ) {
F_70 ( V_143 -> V_169 , V_161 , sizeof( V_143 -> V_169 ) ) ;
V_143 -> V_168 = TRUE ;
if ( ( V_144 = F_71 ( V_170 , V_161 ) ) ) {
V_143 -> V_144 = V_144 ;
V_143 -> V_171 = TRUE ;
}
}
if ( V_167 && V_143 && V_143 -> V_172 ) {
( V_143 -> V_172 ) ( V_95 , V_34 , V_155 , V_143 ) ;
}
}
return F_64 ( V_95 ) ;
}
void
F_72 ( void )
{
V_173 = F_73 ( L_91 ) ;
V_152 = F_74 ( L_92 , V_158 ) ;
V_170 = F_75 ( L_93 ) ;
V_106 = F_76 ( L_94 ) ;
#include "packet-tcap-dis-tab.c"
}
void
F_77 ( void )
{
static T_15 V_174 [] = {
{ & V_175 ,
{ L_95 ,
L_96 ,
V_176 , V_177 , NULL , 0 ,
NULL , V_178 }
} ,
{ & V_179 ,
{ L_97 ,
L_98 ,
V_176 , V_180 , NULL , 0 ,
NULL , V_178 }
} ,
{ & V_181 ,
{ L_99 ,
L_100 ,
V_182 , V_183 , NULL , 0 ,
NULL , V_178 }
} ,
{ & V_184 ,
{ L_101 ,
L_102 ,
V_182 , V_183 , NULL , 0 ,
NULL , V_178 }
} ,
{ & V_185 ,
{ L_103 ,
L_104 ,
V_186 , V_177 , NULL , 0 ,
NULL , V_178 }
} ,
{ & V_117 ,
{ L_105 ,
L_106 ,
V_187 , V_180 , NULL , 0x0 ,
NULL , V_178 }
} ,
{ & V_118 ,
{ L_107 ,
L_108 ,
V_188 , V_183 , NULL , 0x0 ,
L_109 , V_178 }
} ,
{ & V_124 ,
{ L_110 ,
L_111 ,
V_188 , V_183 , NULL , 0x0 ,
L_112 , V_178 }
} ,
{ & V_125 ,
{ L_113 ,
L_114 ,
V_189 , V_183 , NULL , 0x0 ,
L_115 , V_178 }
} ,
{ & V_116 ,
{ L_116 ,
L_117 ,
V_188 , V_183 , NULL , 0x0 ,
L_118 , V_178 }
} ,
#include "packet-tcap-hfarr.c"
} ;
static T_5 * V_190 [] = {
& V_160 ,
& V_191 ,
& V_192 ,
& V_193 ,
& V_115 ,
#include "packet-tcap-ettarr.c"
} ;
T_16 * V_194 ;
V_158 = F_78 ( V_195 , V_196 , V_197 ) ;
F_79 ( V_158 , V_174 , F_80 ( V_174 ) ) ;
F_81 ( V_190 , F_80 ( V_190 ) ) ;
V_5 = F_82 ( L_1 , L_119 , V_158 , V_176 , V_180 ) ;
V_6 = F_82 ( L_3 , L_120 , V_158 , V_176 , V_180 ) ;
V_194 = F_83 ( V_158 , NULL ) ;
#if 0
prefs_register_enum_preference(tcap_module, "standard", "ITU TCAP standard",
"The SS7 standard used in ITU TCAP packets",
&tcap_standard, tcap_options, FALSE);
#else
F_84 ( V_194 , L_121 ) ;
#endif
#if 0
prefs_register_bool_preference(tcap_module, "lock_info_col", "Lock Info column",
"Always show TCAP in Info column",
&lock_info_col);
#else
F_84 ( V_194 , L_122 ) ;
#endif
F_85 ( F_86 () , & V_198 , L_123 , V_199 ) ;
F_87 ( V_194 , L_124 , L_125 ,
L_126 ,
& V_198 , V_199 ) ;
F_88 ( V_194 , L_127 ,
L_128 ,
L_129 ,
& V_167 ) ;
F_88 ( V_194 , L_130 ,
L_131 ,
L_132 ,
& V_140 ) ;
F_89 ( V_194 , L_133 ,
L_134 ,
L_135 ,
10 , & V_110 ) ;
F_89 ( V_194 , L_136 ,
L_137 ,
L_138 ,
10 , & V_111 ) ;
F_90 ( L_139 , F_61 , V_158 ) ;
V_3 = F_91 ( F_61 , V_158 ) ;
V_86 = F_92 ( F_86 () , F_24 () , F_12 , F_11 ) ;
V_75 = F_92 ( F_86 () , F_24 () , F_14 , F_13 ) ;
V_78 = F_92 ( F_86 () , F_24 () , F_16 , F_15 ) ;
V_82 = F_92 ( F_86 () , F_24 () , F_18 , F_17 ) ;
V_92 = F_92 ( F_86 () , F_24 () , F_20 , F_19 ) ;
F_93 ( & V_200 ) ;
F_94 ( & V_201 ) ;
}
static void F_95 ( T_1 V_1 )
{
if ( V_1 && ! F_8 ( V_1 ) && ! F_6 ( V_1 ) ) {
F_5 ( L_2 , V_1 , V_3 ) ;
}
}
static void F_96 ( T_1 V_1 )
{
if ( V_1 && ! F_8 ( V_1 ) && ! F_6 ( V_1 ) ) {
F_2 ( L_2 , V_1 , V_3 ) ;
}
}
static void V_200 ( void )
{
V_202 = F_97 ( F_86 () , V_198 ) ;
F_98 ( V_202 , F_96 ) ;
V_112 = 1 ;
V_114 = V_140 || V_167 & V_203 ;
}
static void V_201 ( void )
{
F_98 ( V_202 , F_95 ) ;
F_99 ( F_86 () , V_202 ) ;
}
static int
F_100 ( T_13 * V_204 , T_10 * V_96 , T_9 * V_95 , int V_205 )
{
T_5 V_206 , V_207 , V_208 ;
T_9 * V_209 ;
T_10 * V_210 ;
T_14 V_146 ;
T_8 V_147 ;
T_17 V_148 ;
T_1 V_211 ;
T_1 V_212 ;
T_1 V_213 ;
T_8 V_214 ;
while ( F_101 ( V_95 , V_205 ) > 0 )
{
V_207 = V_205 ;
V_205 = F_62 ( V_95 , V_205 , & V_146 , & V_147 , & V_148 ) ;
V_206 = V_205 ;
V_205 = F_102 ( V_95 , V_205 , & V_211 , & V_214 ) ;
V_208 = V_205 ;
V_212 = V_206 - V_207 ;
V_213 = V_208 - V_206 ;
if ( V_147 )
{
V_210 = F_48 ( V_96 , V_95 , V_207 ,
V_211 + ( V_208 - V_207 ) , V_191 , NULL ,
L_140 ) ;
F_50 ( V_210 , V_175 , V_95 ,
V_207 , V_212 , V_148 ,
L_141 ) ;
F_51 ( V_210 , V_175 , V_95 , V_207 ,
V_212 , V_146 ) ;
F_51 ( V_210 , V_179 , V_95 , V_206 ,
V_213 , V_211 ) ;
if ( V_211 - ( 2 * V_214 ) )
{
V_209 = F_103 ( V_95 , V_205 , V_211 - ( 2 * V_214 ) ) ;
F_100 ( V_204 , V_210 , V_209 , 0 ) ;
}
if ( V_214 )
F_67 ( V_210 , V_185 , V_95 , V_205 + V_211 - 2 , 2 , V_215 ) ;
V_205 += V_211 ;
}
else
{
V_210 = F_104 ( V_96 , V_95 , V_207 ,
V_211 + ( V_208 - V_207 ) , V_191 , NULL ,
L_142 , V_148 ) ;
F_51 ( V_210 , V_175 , V_95 , V_207 ,
V_212 , V_148 ) ;
F_51 ( V_210 , V_179 , V_95 ,
V_207 + V_212 , V_213 , V_211 ) ;
if ( V_211 )
{
V_209 = F_103 ( V_95 , V_205 , V_211 ) ;
F_105 ( TRUE , V_204 , V_96 , V_209 , 0 ,
V_181 , NULL ) ;
}
V_205 += V_211 ;
}
}
return V_205 ;
}
static int
F_106 ( T_8 T_18 V_4 , T_9 * V_95 , int V_205 , T_13 * V_204 , T_10 * V_96 , int T_19 V_4 )
{
T_2 V_144 = NULL ;
T_8 V_216 = FALSE ;
struct V_43 * V_143 = NULL ;
struct V_149 * V_150 = (struct V_149 * ) V_204 -> V_163 ;
if ( V_167 ) {
if ( ! V_165 ) {
V_143 = F_58 ( V_95 , V_204 -> V_34 , V_155 , V_164 ) ;
V_165 = TRUE ;
V_166 = V_143 ;
V_150 -> V_35 = V_143 ;
} else {
V_143 = V_166 ;
V_150 -> V_35 = V_143 ;
}
}
if ( V_143 ) {
if ( V_161 ) {
if ( V_143 -> V_168 ) {
if ( strncmp ( V_143 -> V_169 , V_161 , sizeof( V_143 -> V_169 ) ) != 0 ) {
F_70 ( V_143 -> V_169 , V_161 , sizeof( V_143 -> V_169 ) ) ;
if ( ( V_144 = F_71 ( V_170 , V_161 ) ) ) {
V_143 -> V_144 = V_144 ;
V_143 -> V_171 = TRUE ;
}
}
} else {
F_70 ( V_143 -> V_169 , V_161 , sizeof( V_143 -> V_169 ) ) ;
V_143 -> V_168 = TRUE ;
if ( ( V_144
= F_71 ( V_170 , V_161 ) ) ) {
V_143 -> V_144 = V_144 ;
V_143 -> V_171 = TRUE ;
} else {
if ( ( V_144 = F_6 ( V_204 -> V_34 -> V_217 ) ) ) {
V_143 -> V_144 = V_144 ;
V_143 -> V_171 = TRUE ;
}
}
}
} else {
if ( V_143 -> V_168 ) {
V_150 -> V_169 = ( void * ) V_143 -> V_169 ;
V_150 -> V_218 = TRUE ;
}
}
}
if ( V_143
&& V_143 -> V_171 ) {
V_144 = V_143 -> V_144 ;
V_216 = TRUE ;
}
if ( ! V_216 && V_219 ) {
V_216 = TRUE ;
V_144 = V_219 ;
}
if ( ! V_216 ) {
if ( V_170 && V_161 ) {
if ( ( V_144
= F_71 ( V_170 , V_161 ) ) ) {
V_216 = TRUE ;
} else {
if ( ( V_144
= F_6 ( V_204 -> V_34 -> V_217 ) ) ) {
V_216 = TRUE ;
} else {
V_144 = V_173 ;
V_216 = TRUE ;
}
}
} else {
if ( ( V_144 = F_6 ( V_204 -> V_34 -> V_217 ) ) ) {
V_216 = TRUE ;
} else {
V_144 = V_173 ;
V_216 = TRUE ;
}
}
} else {
}
if ( V_216 ) {
F_107 ( V_144 , V_95 , V_204 -> V_34 , V_96 , V_204 -> V_163 ) ;
F_108 ( V_204 -> V_34 -> V_156 , V_220 ) ;
}
return V_205 ;
}
void
F_109 ( T_2 V_221 , T_9 * V_95 , T_7 * V_34 , T_10 * V_96 )
{
V_219 = V_221 ;
F_110 {
F_61 ( V_95 , V_34 , V_96 , NULL ) ;
} F_111 {
V_219 = NULL ;
V_222 ;
} V_223 ;
V_219 = NULL ;
}
