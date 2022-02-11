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
V_33 -> V_35 -> V_36 = V_34 -> V_37 -> V_38 ;
V_33 -> V_35 -> V_39 = 0 ;
V_33 -> V_35 -> V_40 = FALSE ;
V_33 -> V_35 -> V_41 = V_34 -> V_37 -> V_42 ;
}
static struct V_32 *
F_25 ( struct V_32 * V_43 ,
struct V_44 * V_45 ,
T_7 * V_34 )
{
struct V_32 * V_46 = NULL ;
#ifdef F_26
V_46 = (struct V_32 * ) F_27 ( sizeof( struct V_32 ) ) ;
#else
V_46 = F_28 ( F_29 () , struct V_32 ) ;
#endif
V_46 -> V_35 = V_45 ;
V_45 -> V_47 = V_46 ;
V_46 -> V_48 = V_43 -> V_48 ;
V_46 -> V_35 -> V_36 = V_34 -> V_37 -> V_38 ;
V_46 -> V_49 = NULL ;
V_46 -> V_50 = V_43 ;
V_46 -> V_51 = FALSE ;
#ifdef F_30
F_13 ( 10 , L_2 , V_46 -> V_35 -> V_17 ) ;
#endif
V_43 -> V_49 = V_46 ;
if ( V_43 -> V_35 -> V_39 == 0 ) {
#ifdef F_30
F_13 ( 10 , L_3 ) ;
#endif
V_43 -> V_35 -> V_39 = V_34 -> V_37 -> V_38 - 1 ;
}
return V_46 ;
}
static void
F_31 ( struct V_52 * V_53 ,
T_7 * V_34 )
{
V_53 -> V_35 -> V_36 = V_34 -> V_37 -> V_38 ;
V_53 -> V_35 -> V_39 = 0 ;
V_53 -> V_35 -> V_40 = FALSE ;
V_53 -> V_35 -> V_41 = V_34 -> V_37 -> V_42 ;
}
static struct V_52 *
F_32 ( struct V_52 * V_54 ,
struct V_44 * V_45 ,
T_7 * V_34 )
{
struct V_52 * V_55 = NULL ;
#ifdef F_26
V_55 = (struct V_52 * ) F_27 ( sizeof( struct V_52 ) ) ;
#else
V_55 = F_28 ( F_29 () , struct V_52 ) ;
#endif
V_55 -> V_35 = V_45 ;
V_45 -> V_56 = V_55 ;
V_55 -> V_57 = V_54 -> V_57 ;
V_55 -> V_35 -> V_36 = V_34 -> V_37 -> V_38 ;
V_55 -> V_58 = NULL ;
V_55 -> V_59 = V_54 ;
V_55 -> V_51 = FALSE ;
#ifdef F_30
F_13 ( 10 , L_4 , V_55 -> V_35 -> V_17 ) ;
#endif
V_54 -> V_58 = V_55 ;
if ( V_54 -> V_35 -> V_39 == 0 ) {
#ifdef F_30
F_13 ( 10 , L_3 ) ;
#endif
V_54 -> V_35 -> V_39 = V_34 -> V_37 -> V_38 - 1 ;
}
return V_55 ;
}
static struct V_60 *
F_33 ( struct V_60 * V_61 ,
struct V_44 * V_45 )
{
struct V_60 * V_62 = NULL ;
#ifdef F_26
V_62 = (struct V_60 * ) F_27 ( sizeof( struct V_60 ) ) ;
#else
V_62 = F_28 ( F_29 () , struct V_60 ) ;
#endif
V_62 -> V_35 = V_45 ;
V_45 -> V_63 = V_62 ;
V_62 -> V_64 = V_61 -> V_64 ;
V_62 -> V_65 = NULL ;
V_62 -> V_66 = V_61 ;
V_62 -> V_51 = FALSE ;
#ifdef F_30
F_13 ( 10 , L_5 , V_62 -> V_35 -> V_17 ) ;
#endif
V_61 -> V_65 = V_62 ;
return V_62 ;
}
static struct V_67 *
F_34 ( struct V_67 * V_68 ,
struct V_44 * V_45 )
{
struct V_67 * V_69 = NULL ;
#ifdef F_26
V_69 = (struct V_70 * ) F_27 ( sizeof( struct V_67 ) ) ;
#else
V_69 = F_28 ( F_29 () , struct V_67 ) ;
#endif
V_69 -> V_35 = V_45 ;
V_45 -> V_71 = V_69 ;
V_69 -> V_72 = V_68 -> V_72 ;
V_69 -> V_73 = NULL ;
V_69 -> V_74 = V_68 ;
V_69 -> V_51 = FALSE ;
#ifdef F_30
F_13 ( 10 , L_6 , V_69 -> V_35 -> V_17 ) ;
#endif
V_68 -> V_73 = V_69 ;
return V_69 ;
}
static struct V_32 *
F_35 ( struct V_20 * V_75 ,
T_7 * V_34 , T_8 V_76 )
{
struct V_32 * V_33 = NULL ;
V_33 = (struct V_32 * ) F_12 ( V_77 , V_75 ) ;
if( V_33 ) {
do {
if ( V_33 -> V_35 ) {
if ( ( V_76 &&
V_34 -> V_37 -> V_38 == V_33 -> V_35 -> V_36 )
||
( ! V_76 &&
V_34 -> V_37 -> V_38 >= V_33 -> V_35 -> V_36 &&
( V_33 -> V_35 -> V_39 ? V_34 -> V_37 -> V_38 <= V_33 -> V_35 -> V_39 : 1 )
)
) {
#ifdef F_30
F_13 ( 10 , L_7 , V_33 -> V_35 -> V_17 ) ;
#endif
return V_33 ;
}
#ifdef F_30
F_13 ( 60 , L_8 , V_33 -> V_35 -> V_17 ) ;
#endif
}
if( V_33 -> V_49 == NULL ) {
#ifdef F_30
F_13 ( 23 , L_9 ) ;
#endif
break;
}
V_33 = V_33 -> V_49 ;
} while ( V_33 != NULL ) ;
} else {
#ifdef F_30
F_13 ( 23 , L_10 ) ;
#endif
}
return NULL ;
}
static struct V_60 *
F_36 ( struct V_25 * V_78 ,
T_7 * V_34 )
{
struct V_60 * V_79 = NULL ;
V_79 = (struct V_60 * ) F_12 ( V_80 , V_78 ) ;
if( V_79 ) {
do {
if ( V_79 -> V_35 ) {
if ( V_34 -> V_37 -> V_38 >= V_79 -> V_35 -> V_36 &&
( V_79 -> V_35 -> V_39 ? V_34 -> V_37 -> V_38 <= V_79 -> V_35 -> V_39 : 1 ) ) {
#ifdef F_30
F_13 ( 10 , L_11 , V_79 -> V_35 -> V_17 ) ;
#endif
return V_79 ;
}
#ifdef F_30
F_13 ( 60 , L_12 , V_79 -> V_35 -> V_17 ) ;
#endif
}
if( V_79 -> V_65 == NULL ) {
#ifdef F_30
F_13 ( 23 , L_13 ) ;
#endif
break;
}
V_79 = V_79 -> V_65 ;
} while ( V_79 != NULL ) ;
} else {
#ifdef F_30
F_13 ( 23 , L_14 ) ;
#endif
}
return NULL ;
}
static struct V_67 *
F_37 ( struct V_30 * V_81 ,
T_7 * V_34 , T_8 V_82 )
{
struct V_67 * V_83 = NULL ;
V_83 = (struct V_67 * ) F_12 ( V_84 , V_81 ) ;
if( V_83 ) {
do {
if ( V_83 -> V_35 ) {
if ( ( V_82 &&
( V_83 -> V_35 -> V_39 ? V_34 -> V_37 -> V_38 == V_83 -> V_35 -> V_39 : 1 )
)
||
( ! V_82 &&
V_34 -> V_37 -> V_38 >= V_83 -> V_35 -> V_36 &&
( V_83 -> V_35 -> V_39 ? V_34 -> V_37 -> V_38 <= V_83 -> V_35 -> V_39 : 1 )
)
) {
#ifdef F_30
F_13 ( 10 , L_15 , V_83 -> V_35 -> V_17 ) ;
#endif
return V_83 ;
}
#ifdef F_30
F_13 ( 60 , L_16 , V_83 -> V_35 -> V_17 ) ;
#endif
}
if( V_83 -> V_73 == NULL ) {
#ifdef F_30
F_13 ( 23 , L_17 ) ;
#endif
break;
}
V_83 = V_83 -> V_73 ;
} while ( V_83 != NULL ) ;
} else {
#ifdef F_30
F_13 ( 23 , L_18 ) ;
#endif
}
return NULL ;
}
static struct V_44 *
F_38 ( struct V_14 * V_85 ,
T_7 * V_34 )
{
struct V_14 * V_86 ;
struct V_44 * V_87 = NULL ;
#ifdef F_26
V_86 = (struct V_14 * ) F_39 ( sizeof( struct V_14 ) ) ;
#else
V_86 = F_40 ( F_29 () , struct V_14 ) ;
#endif
V_86 -> V_17 = V_85 -> V_17 ;
#ifdef F_26
V_87 = (struct V_44 * ) F_27 ( sizeof( struct V_44 ) ) ;
#else
V_87 = F_28 ( F_29 () , struct V_44 ) ;
#endif
V_87 -> V_19 = V_86 ;
V_87 -> V_17 = V_85 -> V_17 ;
V_87 -> V_36 = V_34 -> V_37 -> V_38 ;
#ifdef F_30
F_13 ( 10 , L_19 , V_87 -> V_17 ) ;
#endif
F_2 ( V_88 , V_86 , V_87 ) ;
return V_87 ;
}
static struct V_32 *
F_41 ( struct V_20 * V_75 ,
struct V_44 * V_45 )
{
struct V_20 * V_89 ;
struct V_32 * V_46 = NULL ;
#ifdef F_26
V_89 = (struct V_20 * ) F_39 ( sizeof( struct V_20 ) ) ;
#else
V_89 = F_40 ( F_29 () , struct V_20 ) ;
#endif
V_89 -> V_21 = V_75 -> V_21 ;
V_89 -> V_23 = V_75 -> V_23 ;
V_89 -> V_22 = V_75 -> V_22 ;
#ifdef F_26
V_46 = (struct V_32 * ) F_27 ( sizeof( struct V_32 ) ) ;
#else
V_46 = F_28 ( F_29 () , struct V_32 ) ;
#endif
V_46 -> V_48 = V_89 ;
V_46 -> V_35 = V_45 ;
V_45 -> V_47 = V_46 ;
V_46 -> V_51 = TRUE ;
V_46 -> V_49 = NULL ;
V_46 -> V_50 = NULL ;
#ifdef F_30
F_13 ( 10 , L_7 , V_46 -> V_35 -> V_17 ) ;
#endif
F_2 ( V_77 , V_89 , V_46 ) ;
return V_46 ;
}
static struct V_60 *
F_42 ( struct V_25 * V_78 ,
struct V_44 * V_45 )
{
struct V_25 * V_90 ;
struct V_60 * V_62 = NULL ;
#ifdef F_26
V_90 = (struct V_25 * ) F_39 ( sizeof( struct V_25 ) ) ;
#else
V_90 = F_40 ( F_29 () , struct V_25 ) ;
#endif
V_90 -> V_21 = V_78 -> V_21 ;
V_90 -> V_28 = V_78 -> V_28 ;
V_90 -> V_29 = V_78 -> V_29 ;
V_90 -> V_26 = V_78 -> V_26 ;
V_90 -> V_27 = V_78 -> V_27 ;
#ifdef F_26
V_62 = (struct V_60 * ) F_27 ( sizeof( struct V_60 ) ) ;
#else
V_62 = F_28 ( F_29 () , struct V_60 ) ;
#endif
V_62 -> V_64 = V_90 ;
V_62 -> V_35 = V_45 ;
V_45 -> V_63 = V_62 ;
V_62 -> V_51 = TRUE ;
V_62 -> V_65 = NULL ;
V_62 -> V_66 = NULL ;
#ifdef F_30
F_13 ( 10 , L_11 , V_62 -> V_35 -> V_17 ) ;
#endif
F_2 ( V_80 , V_90 , V_62 ) ;
return V_62 ;
}
static struct V_67 *
F_43 ( struct V_30 * V_81 ,
struct V_44 * V_45 )
{
struct V_30 * V_91 ;
struct V_67 * V_69 = NULL ;
#ifdef F_26
V_91 = (struct V_30 * ) F_39 ( sizeof( struct V_30 ) ) ;
#else
V_91 = F_40 ( F_29 () , struct V_30 ) ;
#endif
V_91 -> V_21 = V_81 -> V_21 ;
V_91 -> V_23 = V_81 -> V_23 ;
V_91 -> V_22 = V_81 -> V_22 ;
#ifdef F_26
V_69 = (struct V_67 * ) F_27 ( sizeof( struct V_67 ) ) ;
#else
V_69 = F_28 ( F_29 () , struct V_67 ) ;
#endif
V_69 -> V_72 = V_91 ;
V_69 -> V_35 = V_45 ;
V_45 -> V_71 = V_69 ;
V_69 -> V_51 = TRUE ;
V_69 -> V_73 = NULL ;
V_69 -> V_74 = NULL ;
#ifdef F_30
F_13 ( 10 , L_15 , V_69 -> V_35 -> V_17 ) ;
#endif
F_2 ( V_84 , V_91 , V_69 ) ;
return V_69 ;
}
static struct V_52 *
F_44 ( struct V_31 * V_92 ,
struct V_44 * V_45 )
{
struct V_31 * V_93 ;
struct V_52 * V_55 = NULL ;
#ifdef F_26
V_93 = (struct V_31 * ) F_39 ( sizeof( struct V_31 ) ) ;
#else
V_93 = F_40 ( F_29 () , struct V_31 ) ;
#endif
V_93 -> V_21 = V_92 -> V_21 ;
V_93 -> V_23 = V_92 -> V_23 ;
V_93 -> V_26 = V_92 -> V_26 ;
V_93 -> V_27 = V_92 -> V_27 ;
#ifdef F_26
V_55 = (struct V_52 * ) F_27 ( sizeof( struct V_52 ) ) ;
#else
V_55 = F_28 ( F_29 () , struct V_52 ) ;
#endif
V_55 -> V_57 = V_93 ;
V_55 -> V_35 = V_45 ;
V_45 -> V_56 = V_55 ;
V_55 -> V_51 = TRUE ;
V_55 -> V_58 = NULL ;
V_55 -> V_59 = NULL ;
#ifdef F_30
F_13 ( 10 , L_20 , V_55 -> V_35 -> V_17 ) ;
#endif
F_2 ( V_94 , V_93 , V_55 ) ;
return V_55 ;
}
static struct V_60 *
F_45 ( struct V_25 * V_78 ,
struct V_44 * V_45 )
{
struct V_60 * V_95 = NULL ;
struct V_60 * V_79 = NULL ;
V_95 = (struct V_60 * )
F_12 ( V_80 , V_78 ) ;
if ( V_95 ) {
do {
if ( ! V_95 -> V_65 ) {
V_79 = F_33 ( V_95 ,
V_45 ) ;
break;
}
V_95 = V_95 -> V_65 ;
} while ( V_95 != NULL );
} else {
V_79 = F_42 ( V_78 ,
V_45 ) ;
}
return V_79 ;
}
static struct V_67 *
F_46 ( struct V_30 * V_81 ,
struct V_44 * V_45 )
{
struct V_67 * V_96 = NULL ;
struct V_67 * V_83 = NULL ;
V_96 = (struct V_67 * )
F_12 ( V_84 , V_81 ) ;
if ( V_96 ) {
do {
if ( ! V_96 -> V_73 ) {
V_83 = F_34 ( V_96 ,
V_45 ) ;
break;
}
V_96 = V_96 -> V_73 ;
} while ( V_96 != NULL );
} else {
V_83 = F_43 ( V_81 ,
V_45 ) ;
}
return V_83 ;
}
void
F_47 ( void )
{
if ( V_88 != NULL ) {
#ifdef F_30
F_13 ( 16 , L_21 ) ;
#endif
F_48 ( V_88 ) ;
}
if ( V_77 != NULL ) {
#ifdef F_30
F_13 ( 16 , L_22 ) ;
#endif
F_48 ( V_77 ) ;
}
if ( V_80 != NULL ) {
#ifdef F_30
F_13 ( 16 , L_23 ) ;
#endif
F_48 ( V_80 ) ;
}
if ( V_84 != NULL ) {
#ifdef F_30
F_13 ( 16 , L_24 ) ;
#endif
F_48 ( V_84 ) ;
}
if ( V_94 != NULL ) {
#ifdef F_30
F_13 ( 16 , L_25 ) ;
#endif
F_48 ( V_94 ) ;
}
#ifdef F_30
F_13 ( 16 , L_26 ) ;
#endif
V_88 = F_49 ( F_15 , F_14 ) ;
V_77 = F_49 ( F_17 , F_16 ) ;
V_80 = F_49 ( F_19 , F_18 ) ;
V_84 = F_49 ( F_21 , F_20 ) ;
V_94 = F_49 ( F_23 , F_22 ) ;
V_97 = 1 ;
V_98 = V_99 || V_100 & V_101 ;
}
static struct V_44 *
F_50 ( T_9 * V_102 , T_7 * V_34 , T_10 * V_103 ,
struct V_104 * V_105 )
{
struct V_44 * V_45 = NULL ;
struct V_14 V_106 ;
struct V_32 * V_33 , * V_46 = NULL ;
struct V_20 V_107 ;
T_11 * V_108 ;
T_11 * V_109 = NULL ;
T_10 * V_110 = NULL ;
#ifdef F_30
F_13 ( 51 , L_27 , F_51 ( F_52 () , & V_34 -> V_111 ) , V_105 -> V_28 , F_51 ( F_52 () , & V_34 -> V_112 ) ) ;
#endif
V_107 . V_23 = V_105 -> V_28 ;
if ( V_34 -> V_111 . type == V_113 && V_34 -> V_112 . type == V_113 )
{
V_107 . V_22 = F_53 ( ( const V_114 * ) V_34 -> V_111 . V_115 ) ;
} else {
V_107 . V_22 = F_54 ( F_51 ( F_52 () , & V_34 -> V_111 ) ) ;
}
V_107 . V_21 = F_17 ( & V_107 ) ;
#ifdef F_30
F_13 ( 10 , L_28 , V_34 -> V_37 -> V_38 ) ;
F_13 ( 11 , L_29 , V_107 . V_21 ) ;
F_13 ( 51 , L_30 , F_51 ( F_52 () , & V_34 -> V_111 ) ) ;
F_13 ( 51 , L_31 , V_107 . V_23 ) ;
#endif
V_33 = (struct V_32 * )
F_12 ( V_77 , & V_107 ) ;
if ( V_33 ) {
do {
if ( V_34 -> V_37 -> V_38 == V_33 -> V_35 -> V_36 ) {
#ifdef F_30
F_13 ( 22 , L_32 ) ;
#endif
V_45 = V_33 -> V_35 ;
break;
}
if ( ! V_33 -> V_49 ) {
if ( ( V_33 -> V_35 -> V_39 != 0
&& V_34 -> V_37 -> V_38 > V_33 -> V_35 -> V_36
&& ( T_3 ) V_34 -> V_37 -> V_42 . V_116 > ( T_3 ) ( V_33 -> V_35 -> V_41 . V_116 + V_117 )
) ||
( V_33 -> V_35 -> V_39 == 0
&& V_34 -> V_37 -> V_38 > V_33 -> V_35 -> V_36
&& ( T_3 ) V_34 -> V_37 -> V_42 . V_116 > ( T_3 ) ( V_33 -> V_35 -> V_41 . V_116 + V_118 )
)
)
{
#ifdef F_30
F_13 ( 12 , L_33 , V_107 . V_21 ) ;
F_13 ( 12 , L_34 , V_34 -> V_37 -> V_38 , V_33 -> V_35 -> V_39 ) ;
#endif
V_106 . V_17 = V_97 ++ ;
V_45 = F_38 ( & V_106 , V_34 ) ;
V_46 = F_25 ( V_33 ,
V_45 ,
V_34 ) ;
#ifdef F_30
F_13 ( 12 , L_35 , V_107 . V_21 ) ;
#endif
F_24 ( V_46 , V_34 ) ;
} else {
if ( V_33 -> V_35 -> V_119 ) {
#ifdef F_30
F_13 ( 12 , L_36 , V_107 . V_21 ) ;
F_13 ( 12 , L_34 , V_34 -> V_37 -> V_38 , V_33 -> V_35 -> V_39 ) ;
#endif
V_106 . V_17 = V_97 ++ ;
V_45 = F_38 ( & V_106 , V_34 ) ;
V_46 = F_25 ( V_33 ,
V_45 ,
V_34 ) ;
#ifdef F_30
F_13 ( 12 , L_37 , V_107 . V_21 ) ;
#endif
F_24 ( V_46 , V_34 ) ;
} else {
#ifdef F_30
F_13 ( 21 , L_38 , V_33 -> V_35 -> V_36 ) ;
#endif
V_45 = V_33 -> V_35 ;
if ( V_98 && V_103 ) {
V_110 = F_55 ( V_103 , V_102 , 0 , - 1 , V_120 , & V_109 , L_39 ) ;
F_56 ( V_109 ) ;
V_108 = F_57 ( V_110 , V_121 , V_102 , 0 , 0 ,
V_45 -> V_36 ,
L_40 ,
V_45 -> V_17 , V_45 -> V_36 ) ;
F_56 ( V_108 ) ;
}
return V_45 ;
}
}
break;
}
V_33 = V_33 -> V_49 ;
} while ( V_33 != NULL );
} else {
#ifdef F_30
F_13 ( 10 , L_41 , V_107 . V_21 ) ;
#endif
V_106 . V_17 = V_97 ++ ;
V_45 = F_38 ( & V_106 , V_34 ) ;
V_33 = F_41 ( & V_107 , V_45 ) ;
#ifdef F_30
F_13 ( 11 , L_35 , V_107 . V_21 ) ;
F_13 ( 11 , L_42 , V_34 -> V_37 -> V_38 ) ;
#endif
F_24 ( V_33 , V_34 ) ;
}
if ( V_98 && V_103 &&
V_45 &&
V_45 -> V_17 ) {
V_110 = F_55 ( V_103 , V_102 , 0 , 0 , V_120 , & V_109 , L_39 ) ;
F_56 ( V_109 ) ;
V_108 = F_58 ( V_110 , V_122 , V_102 , 0 , 0 , V_45 -> V_17 ) ;
F_56 ( V_108 ) ;
if( V_45 -> V_39 != 0 ) {
#ifdef F_30
F_13 ( 20 , L_43 , V_45 -> V_39 ) ;
#endif
V_108 = F_57 ( V_110 , V_123 , V_102 , 0 , 0 ,
V_45 -> V_39 ,
L_44 ,
V_45 -> V_39 ) ;
F_56 ( V_108 ) ;
}
}
return V_45 ;
}
static struct V_44 *
F_59 ( T_9 * V_102 , T_7 * V_34 , T_10 * V_103 ,
struct V_104 * V_105 )
{
struct V_44 * V_45 = NULL ;
struct V_60 * V_79 ;
struct V_25 V_124 ;
struct V_20 V_107 ;
struct V_32 * V_33 ;
struct V_30 V_125 ;
T_11 * V_108 ;
T_11 * V_109 = NULL ;
T_10 * V_110 = NULL ;
#ifdef F_30
F_13 ( 51 , L_45 , F_51 ( F_52 () , & V_34 -> V_111 ) , V_105 -> V_28 , F_51 ( F_52 () , & V_34 -> V_112 ) , V_105 -> V_29 ) ;
F_13 ( 10 , L_46 , V_34 -> V_37 -> V_38 ) ;
#endif
V_124 . V_28 = V_105 -> V_28 ;
V_124 . V_29 = V_105 -> V_29 ;
if ( V_34 -> V_111 . type == V_113 && V_34 -> V_112 . type == V_113 )
{
V_124 . V_26 = F_53 ( ( const V_114 * ) V_34 -> V_111 . V_115 ) ;
V_124 . V_27 = F_53 ( ( const V_114 * ) V_34 -> V_112 . V_115 ) ;
} else {
V_124 . V_26 = F_54 ( F_51 ( F_52 () , & V_34 -> V_111 ) ) ;
V_124 . V_27 = F_54 ( F_51 ( F_52 () , & V_34 -> V_112 ) ) ;
}
V_124 . V_21 = F_19 ( & V_124 ) ;
#ifdef F_30
F_13 ( 11 , L_47 , V_124 . V_21 ) ;
F_13 ( 51 , L_48 , F_51 ( F_52 () , & V_34 -> V_111 ) , F_51 ( F_52 () , & V_34 -> V_112 ) ) ;
F_13 ( 51 , L_49 , V_124 . V_28 , V_124 . V_29 ) ;
#endif
V_79 = F_36 ( & V_124 , V_34 ) ;
if( V_79 ) {
#ifdef F_30
F_13 ( 12 , L_50 ) ;
#endif
V_45 = V_79 -> V_35 ;
} else {
#ifdef F_30
F_13 ( 12 , L_51 ) ;
#endif
V_107 . V_23 = V_105 -> V_29 ;
if ( V_34 -> V_111 . type == V_113 && V_34 -> V_112 . type == V_113 )
{
V_107 . V_22 = F_53 ( ( const V_114 * ) V_34 -> V_112 . V_115 ) ;
} else {
V_107 . V_22 = F_54 ( F_51 ( F_52 () , & V_34 -> V_112 ) ) ;
}
V_107 . V_21 = F_17 ( & V_107 ) ;
#ifdef F_30
F_13 ( 11 , L_52 , V_107 . V_21 ) ;
F_13 ( 51 , L_30 , F_51 ( F_52 () , & V_34 -> V_112 ) ) ;
F_13 ( 51 , L_31 , V_107 . V_23 ) ;
#endif
V_33 = F_35 ( & V_107 , V_34 , FALSE ) ;
if( ! V_33 ) {
#ifdef F_30
F_13 ( 12 , L_53 ) ;
#endif
V_107 . V_23 = V_105 -> V_28 ;
if ( V_34 -> V_111 . type == V_113 && V_34 -> V_112 . type == V_113 )
{
V_107 . V_22 = F_53 ( ( const V_114 * ) V_34 -> V_111 . V_115 ) ;
} else {
V_107 . V_22 = F_54 ( F_51 ( F_52 () , & V_34 -> V_111 ) ) ;
}
V_107 . V_21 = F_17 ( & V_107 ) ;
#ifdef F_30
F_13 ( 11 , L_52 , V_107 . V_21 ) ;
F_13 ( 51 , L_30 , F_51 ( F_52 () , & V_34 -> V_111 ) ) ;
F_13 ( 51 , L_31 , V_107 . V_23 ) ;
#endif
V_33 = F_35 ( & V_107 , V_34 , FALSE ) ;
}
if( V_33 &&
! V_33 -> V_35 -> V_63 ) {
#ifdef F_30
F_13 ( 12 , L_54 ) ;
#endif
V_45 = V_33 -> V_35 ;
V_45 -> V_40 = TRUE ;
#ifdef F_30
F_13 ( 10 , L_55 , V_124 . V_21 ) ;
F_13 ( 11 , L_56 , V_34 -> V_37 -> V_38 ) ;
#endif
F_45 ( & V_124 ,
V_33 -> V_35 ) ;
V_125 . V_23 = V_105 -> V_28 ;
if ( V_34 -> V_111 . type == V_113 && V_34 -> V_112 . type == V_113 )
{
V_125 . V_22 = F_53 ( ( const V_114 * ) V_34 -> V_111 . V_115 ) ;
} else {
V_125 . V_22 = F_54 ( F_51 ( F_52 () , & V_34 -> V_111 ) ) ;
}
V_125 . V_21 = F_21 ( & V_125 ) ;
#ifdef F_30
F_13 ( 10 , L_57 , V_125 . V_21 ) ;
F_13 ( 51 , L_30 , F_51 ( F_52 () , & V_34 -> V_111 ) ) ;
F_13 ( 51 , L_58 , V_125 . V_23 ) ;
F_13 ( 11 , L_42 , V_34 -> V_37 -> V_38 ) ;
#endif
F_46 ( & V_125 ,
V_33 -> V_35 ) ;
} else {
#ifdef F_30
F_13 ( 12 , L_59 ) ;
#endif
}
}
if ( V_98 && V_103 &&
V_45 &&
V_45 -> V_17 ) {
V_110 = F_55 ( V_103 , V_102 , 0 , - 1 , V_120 , & V_109 , L_39 ) ;
F_56 ( V_109 ) ;
V_108 = F_58 ( V_110 , V_122 , V_102 , 0 , 0 , V_45 -> V_17 ) ;
F_56 ( V_108 ) ;
}
return V_45 ;
}
static struct V_44 *
F_60 ( T_9 * V_102 , T_7 * V_34 , T_10 * V_103 ,
struct V_104 * V_105 )
{
struct V_44 * V_45 = NULL ;
struct V_30 V_125 ;
struct V_67 * V_83 = NULL ;
struct V_20 V_107 ;
struct V_32 * V_33 = NULL ;
T_11 * V_108 ;
T_12 V_126 ;
T_11 * V_109 = NULL ;
T_10 * V_110 = NULL ;
#ifdef F_30
F_13 ( 51 , L_60 , F_51 ( F_52 () , & V_34 -> V_111 ) , F_51 ( F_52 () , & V_34 -> V_112 ) , V_105 -> V_29 ) ;
F_13 ( 10 , L_61 , V_34 -> V_37 -> V_38 ) ;
#endif
V_125 . V_23 = V_105 -> V_29 ;
if ( V_34 -> V_111 . type == V_113 && V_34 -> V_112 . type == V_113 )
{
V_125 . V_22 = F_53 ( ( const V_114 * ) V_34 -> V_112 . V_115 ) ;
} else {
V_125 . V_22 = F_54 ( F_51 ( F_52 () , & V_34 -> V_112 ) ) ;
}
V_125 . V_21 = F_21 ( & V_125 ) ;
#ifdef F_30
F_13 ( 11 , L_62 , V_125 . V_21 ) ;
F_13 ( 11 , L_30 , F_51 ( F_52 () , & V_34 -> V_112 ) ) ;
F_13 ( 51 , L_58 , V_125 . V_23 ) ;
#endif
V_83 = F_37 ( & V_125 , V_34 , TRUE ) ;
if( ! V_83 ) {
#ifdef F_30
F_13 ( 12 , L_63 ) ;
#endif
V_107 . V_23 = V_105 -> V_29 ;
if ( V_34 -> V_111 . type == V_113 && V_34 -> V_112 . type == V_113 )
{
V_107 . V_22 = F_53 ( ( const V_114 * ) V_34 -> V_112 . V_115 ) ;
} else {
V_107 . V_22 = F_54 ( F_51 ( F_52 () , & V_34 -> V_112 ) ) ;
}
V_107 . V_21 = F_17 ( & V_107 ) ;
#ifdef F_30
F_13 ( 11 , L_52 , V_107 . V_21 ) ;
F_13 ( 51 , L_30 , F_51 ( F_52 () , & V_34 -> V_112 ) ) ;
F_13 ( 51 , L_58 , V_107 . V_23 ) ;
#endif
V_33 = F_35 ( & V_107 , V_34 , FALSE ) ;
if( ! V_33 ) {
#ifdef F_30
F_13 ( 12 , L_59 ) ;
#endif
}
}
if ( V_83 ) {
V_45 = V_83 -> V_35 ;
} else if ( V_33 ) {
V_45 = V_33 -> V_35 ;
}
if ( V_45 ) {
#ifdef F_30
F_13 ( 12 , L_64 , V_45 -> V_36 ) ;
#endif
if ( V_98 && V_103 ) {
V_110 = F_55 ( V_103 , V_102 , 0 , - 1 , V_120 , & V_109 , L_39 ) ;
F_56 ( V_109 ) ;
V_108 = F_58 ( V_110 , V_122 , V_102 , 0 , 0 , V_45 -> V_17 ) ;
F_56 ( V_108 ) ;
}
#ifdef F_30
F_13 ( 20 , L_65 , V_45 -> V_36 ) ;
#endif
if ( V_98 && V_110 ) {
V_108 = F_57 ( V_110 , V_127 , V_102 , 0 , 0 ,
V_45 -> V_36 ,
L_66 ,
V_45 -> V_36 ) ;
F_56 ( V_108 ) ;
F_61 ( & V_126 , & V_34 -> V_37 -> V_42 , & V_45 -> V_41 ) ;
V_108 = F_62 ( V_110 , V_128 , V_102 , 0 , 0 , & V_126 ) ;
F_56 ( V_108 ) ;
}
F_63 ( V_45 , V_34 ) ;
} else {
#ifdef F_30
F_13 ( 12 , L_67 ) ;
#endif
}
return V_45 ;
}
static struct V_44 *
F_64 ( T_9 * V_102 , T_7 * V_34 , T_10 * V_103 ,
struct V_104 * V_105 )
{
struct V_44 * V_45 = NULL ;
struct V_14 V_106 ;
struct V_52 * V_53 , * V_55 ;
struct V_31 V_129 ;
T_11 * V_108 ;
T_12 V_126 ;
T_8 V_130 = FALSE ;
T_10 * V_110 = NULL ;
T_11 * V_109 = NULL ;
V_129 . V_23 = V_105 -> V_28 ;
if ( V_34 -> V_111 . type == V_113 && V_34 -> V_112 . type == V_113 )
{
V_129 . V_26 = F_53 ( ( const V_114 * ) V_34 -> V_111 . V_115 ) ;
V_129 . V_27 = F_53 ( ( const V_114 * ) V_34 -> V_112 . V_115 ) ;
} else {
V_129 . V_26 = F_54 ( F_51 ( F_52 () , & V_34 -> V_111 ) ) ;
V_129 . V_27 = F_54 ( F_51 ( F_52 () , & V_34 -> V_112 ) ) ;
}
V_129 . V_21 = F_23 ( & V_129 ) ;
#ifdef F_30
F_13 ( 10 , L_68 , V_34 -> V_37 -> V_38 ) ;
F_13 ( 11 , L_29 , V_129 . V_21 ) ;
F_13 ( 51 , L_69 , F_51 ( F_52 () , & V_34 -> V_111 ) , F_51 ( F_52 () , & V_34 -> V_112 ) ) ;
F_13 ( 51 , L_58 , V_129 . V_23 ) ;
#endif
V_53 = (struct V_52 * )
F_12 ( V_94 , & V_129 ) ;
if ( V_53 ) {
do {
if ( V_34 -> V_37 -> V_38 == V_53 -> V_35 -> V_36 ) {
#ifdef F_30
F_13 ( 22 , L_70 ) ;
#endif
V_130 = FALSE ;
V_45 = V_53 -> V_35 ;
break;
}
if ( V_34 -> V_37 -> V_38 == V_53 -> V_35 -> V_39 ) {
#ifdef F_30
F_13 ( 22 , L_71 ) ;
#endif
V_130 = TRUE ;
V_45 = V_53 -> V_35 ;
break;
}
if ( V_34 -> V_37 -> V_38 > V_53 -> V_35 -> V_36 &&
V_53 -> V_35 -> V_39 == 0 ) {
#ifdef F_30
F_13 ( 12 , L_35 , V_129 . V_21 ) ;
#endif
V_53 -> V_35 -> V_39 = V_34 -> V_37 -> V_38 ;
V_53 -> V_35 -> V_40 = TRUE ;
V_53 -> V_35 -> V_119 = TRUE ;
V_45 = V_53 -> V_35 ;
V_130 = TRUE ;
if ( V_98 && V_103 ) {
V_110 = F_55 ( V_103 , V_102 , 0 , - 1 , V_120 , & V_109 , L_39 ) ;
F_56 ( V_109 ) ;
V_108 = F_58 ( V_110 , V_122 , V_102 , 0 , 0 , V_45 -> V_17 ) ;
F_56 ( V_108 ) ;
#ifdef F_30
F_13 ( 20 , L_65 , V_45 -> V_36 ) ;
#endif
V_108 = F_57 ( V_110 , V_127 , V_102 , 0 , 0 ,
V_45 -> V_36 ,
L_66 ,
V_45 -> V_36 ) ;
F_56 ( V_108 ) ;
F_61 ( & V_126 , & V_34 -> V_37 -> V_42 , & V_45 -> V_41 ) ;
V_108 = F_62 ( V_110 , V_128 , V_102 , 0 , 0 , & V_126 ) ;
F_56 ( V_108 ) ;
}
break;
}
if ( ! V_53 -> V_58 ) {
if ( ( V_53 -> V_35 -> V_39 != 0
&& V_34 -> V_37 -> V_38 > V_53 -> V_35 -> V_36
&& ( T_3 ) V_34 -> V_37 -> V_42 . V_116 > ( T_3 ) ( V_53 -> V_35 -> V_41 . V_116 + V_117 )
) ||
( V_53 -> V_35 -> V_39 == 0
&& V_34 -> V_37 -> V_38 > V_53 -> V_35 -> V_36
&& ( T_3 ) V_34 -> V_37 -> V_42 . V_116 > ( T_3 ) ( V_53 -> V_35 -> V_41 . V_116 + V_118 )
)
)
{
#ifdef F_30
F_13 ( 12 , L_33 , V_129 . V_21 ) ;
F_13 ( 12 , L_34 , V_34 -> V_37 -> V_38 , V_53 -> V_35 -> V_39 ) ;
#endif
V_106 . V_17 = V_97 ++ ;
V_45 = F_38 ( & V_106 , V_34 ) ;
V_55 = F_32 ( V_53 ,
V_45 ,
V_34 ) ;
#ifdef F_30
F_13 ( 12 , L_35 , V_129 . V_21 ) ;
#endif
F_31 ( V_55 , V_34 ) ;
V_53 = V_55 ;
} else {
if ( V_53 -> V_35 -> V_119 ) {
#ifdef F_30
F_13 ( 12 , L_36 , V_129 . V_21 ) ;
F_13 ( 12 , L_34 , V_34 -> V_37 -> V_38 , V_53 -> V_35 -> V_39 ) ;
#endif
V_106 . V_17 = V_97 ++ ;
V_45 = F_38 ( & V_106 , V_34 ) ;
V_55 = F_32 ( V_53 ,
V_45 ,
V_34 ) ;
#ifdef F_30
F_13 ( 12 , L_37 , V_129 . V_21 ) ;
#endif
F_31 ( V_55 , V_34 ) ;
V_53 = V_55 ;
} else {
V_45 = V_53 -> V_35 ;
#ifdef F_30
F_13 ( 12 , L_64 , V_45 -> V_36 ) ;
#endif
if ( V_98 && V_103 ) {
V_110 = F_55 ( V_103 , V_102 , 0 , - 1 , V_120 , & V_109 , L_39 ) ;
F_56 ( V_109 ) ;
V_108 = F_58 ( V_110 , V_122 , V_102 , 0 , 0 , V_45 -> V_17 ) ;
F_56 ( V_108 ) ;
#ifdef F_30
F_13 ( 20 , L_65 , V_45 -> V_36 ) ;
#endif
V_108 = F_57 ( V_110 , V_127 , V_102 , 0 , 0 ,
V_45 -> V_36 ,
L_66 ,
V_45 -> V_36 ) ;
F_56 ( V_108 ) ;
F_61 ( & V_126 , & V_34 -> V_37 -> V_42 , & V_45 -> V_41 ) ;
V_108 = F_62 ( V_110 , V_128 , V_102 , 0 , 0 , & V_126 ) ;
F_56 ( V_108 ) ;
}
V_45 = V_53 -> V_35 ;
}
}
break;
}
V_53 = V_53 -> V_58 ;
} while ( V_53 != NULL );
} else {
#ifdef F_30
F_13 ( 10 , L_41 , V_129 . V_21 ) ;
#endif
V_106 . V_17 = V_97 ++ ;
V_45 = F_38 ( & V_106 , V_34 ) ;
V_53 = F_44 ( & V_129 , V_45 ) ;
#ifdef F_30
F_13 ( 11 , L_35 , V_129 . V_21 ) ;
F_13 ( 11 , L_42 , V_34 -> V_37 -> V_38 ) ;
#endif
F_31 ( V_53 , V_34 ) ;
}
if ( V_98 && V_103 &&
V_45 &&
V_45 -> V_17 ) {
V_110 = F_55 ( V_103 , V_102 , 0 , - 1 , V_120 , & V_109 , L_39 ) ;
F_56 ( V_109 ) ;
V_108 = F_58 ( V_110 , V_122 , V_102 , 0 , 0 , V_45 -> V_17 ) ;
F_56 ( V_108 ) ;
}
if( V_98 && V_110 &&
V_53 -> V_35 -> V_39 != 0 ) {
if ( ! V_130 ) {
#ifdef F_30
F_13 ( 20 , L_43 , V_53 -> V_35 -> V_39 ) ;
#endif
V_108 = F_57 ( V_110 , V_123 , V_102 , 0 , 0 ,
V_53 -> V_35 -> V_39 ,
L_44 ,
V_53 -> V_35 -> V_39 ) ;
F_56 ( V_108 ) ;
} else {
#ifdef F_30
F_13 ( 20 , L_65 , V_45 -> V_36 ) ;
#endif
if ( V_98 ) {
V_108 = F_57 ( V_110 , V_127 , V_102 , 0 , 0 ,
V_45 -> V_36 ,
L_66 ,
V_45 -> V_36 ) ;
F_56 ( V_108 ) ;
F_61 ( & V_126 , & V_34 -> V_37 -> V_42 , & V_45 -> V_41 ) ;
V_108 = F_62 ( V_110 , V_128 , V_102 , 0 , 0 , & V_126 ) ;
F_56 ( V_108 ) ;
}
}
}
return V_45 ;
}
struct V_44 *
F_65 ( T_9 * V_102 , T_7 * V_34 , T_10 * V_103 ,
struct V_104 * V_105 )
{
struct V_44 * V_131 = NULL ;
if( V_34 == NULL || V_34 -> V_37 -> V_38 == 0 ) {
return NULL ;
}
switch ( V_105 -> V_132 ) {
case V_133 :
#ifdef F_30
F_13 ( 1 , L_72 ) ;
#endif
V_131 = F_50 ( V_102 , V_34 , V_103 , V_105 ) ;
break;
case V_134 :
#ifdef F_30
F_13 ( 1 , L_73 ) ;
#endif
V_131 = F_59 ( V_102 , V_34 , V_103 , V_105 ) ;
break;
case V_135 :
#ifdef F_30
F_13 ( 1 , L_74 ) ;
#endif
V_131 = F_60 ( V_102 , V_34 , V_103 , V_105 ) ;
break;
case V_136 :
#ifdef F_30
F_13 ( 1 , L_75 ) ;
#endif
V_131 = F_60 ( V_102 , V_34 , V_103 , V_105 ) ;
break;
case V_137 :
case V_138 :
#ifdef F_30
F_13 ( 1 , L_76 ) ;
#endif
V_131 = F_64 ( V_102 , V_34 , V_103 , V_105 ) ;
break;
default:
#ifdef F_30
F_13 ( 1 , L_77 , V_105 -> V_132 ) ;
#endif
break;
}
#ifdef F_30
if ( V_131 )
F_13 ( 1 , L_78 , V_131 -> V_17 ) ;
#endif
return V_131 ;
}
struct V_104 *
F_66 ( void )
{
struct V_104 * V_105 ;
V_139 ++ ;
if( V_139 == V_140 ) {
V_139 = 0 ;
}
V_105 = & V_141 [ V_139 ] ;
memset ( V_105 , 0 , sizeof( struct V_104 ) ) ;
return V_105 ;
}
void
F_63 ( struct V_44 * V_45 ,
T_7 * V_34 )
{
#ifdef F_30
F_13 ( 60 , L_79 ) ;
#endif
if ( V_45 ) {
V_45 -> V_40 = TRUE ;
V_45 -> V_39 = V_34 -> V_37 -> V_38 ;
V_45 -> V_142 = V_34 -> V_37 -> V_42 ;
V_45 -> V_119 = TRUE ;
if ( V_45 -> V_71
&& ! V_99 ) {
if ( V_45 -> V_71 -> V_73 ) {
if ( V_45 -> V_71 -> V_74 ) {
#ifdef F_30
F_13 ( 20 , L_80 ) ;
#endif
V_45 -> V_71 -> V_74 -> V_73
= V_45 -> V_71 -> V_73 ;
V_45 -> V_71 -> V_73 -> V_74
= V_45 -> V_71 -> V_74 ;
F_7 ( V_84 , V_45 -> V_71 -> V_72 ) ;
#ifdef F_26
F_67 ( V_45 -> V_71 ) ;
#endif
} else {
#ifdef F_30
F_13 ( 20 , L_81 ) ;
#endif
}
} else if ( ! V_99 ) {
#ifdef F_30
F_13 ( 20 , L_82 ) ;
#endif
F_7 ( V_84 , V_45 -> V_71 -> V_72 ) ;
#ifdef F_26
F_67 ( V_45 -> V_71 -> V_72 ) ;
F_67 ( V_45 -> V_71 ) ;
#endif
}
}
if ( V_45 -> V_63
&& ! V_99 ) {
if ( V_45 -> V_63 -> V_65 ) {
if ( V_45 -> V_63 -> V_66 ) {
#ifdef F_30
F_13 ( 20 , L_83 ) ;
#endif
V_45 -> V_63 -> V_66 -> V_65
= V_45 -> V_63 -> V_65 ;
V_45 -> V_63 -> V_65 -> V_66
= V_45 -> V_63 -> V_66 ;
F_7 ( V_80 , V_45 -> V_63 -> V_64 ) ;
#ifdef F_26
F_67 ( V_45 -> V_63 ) ;
#endif
} else {
#ifdef F_30
F_13 ( 20 , L_84 ) ;
#endif
}
} else if ( ! V_99 ) {
#ifdef F_30
F_13 ( 20 , L_85 ) ;
#endif
F_7 ( V_80 , V_45 -> V_63 -> V_64 ) ;
#ifdef F_26
F_67 ( V_45 -> V_63 -> V_64 ) ;
F_67 ( V_45 -> V_63 ) ;
#endif
}
}
if ( V_45 -> V_47
&& ! V_99 ) {
if ( V_45 -> V_47 -> V_49 ) {
if ( V_45 -> V_47 -> V_50 ) {
#ifdef F_30
F_13 ( 20 , L_86 ) ;
#endif
V_45 -> V_47 -> V_50 -> V_49
= V_45 -> V_47 -> V_49 ;
V_45 -> V_47 -> V_49 -> V_50
= V_45 -> V_47 -> V_50 ;
F_7 ( V_77 , V_45 -> V_47 -> V_48 ) ;
#ifdef F_26
F_67 ( V_45 -> V_47 ) ;
#endif
} else {
#ifdef F_30
F_13 ( 20 , L_87 ) ;
#endif
}
} else if ( ! V_99 ) {
#ifdef F_30
F_13 ( 20 , L_88 ) ;
#endif
F_7 ( V_77 , V_45 -> V_47 -> V_48 ) ;
#ifdef F_26
F_67 ( V_45 -> V_47 -> V_48 ) ;
F_67 ( V_45 -> V_47 ) ;
#endif
}
}
if ( V_45 -> V_56
&& ! V_99 ) {
if ( V_45 -> V_56 -> V_58 ) {
if ( V_45 -> V_56 -> V_59 ) {
#ifdef F_30
F_13 ( 20 , L_89 ) ;
#endif
V_45 -> V_56 -> V_59 -> V_58
= V_45 -> V_56 -> V_58 ;
V_45 -> V_56 -> V_58 -> V_59
= V_45 -> V_56 -> V_59 ;
F_7 ( V_94 , V_45 -> V_56 -> V_57 ) ;
#ifdef F_26
F_67 ( V_45 -> V_56 ) ;
#endif
} else {
#ifdef F_30
F_13 ( 20 , L_90 ) ;
#endif
}
} else if ( ! V_99 ) {
#ifdef F_30
F_13 ( 20 , L_91 ) ;
#endif
F_7 ( V_94 , V_45 -> V_56 -> V_57 ) ;
#ifdef F_26
F_67 ( V_45 -> V_56 -> V_57 ) ;
F_67 ( V_45 -> V_56 ) ;
#endif
}
}
if ( ! V_99 ) {
#ifdef F_30
F_13 ( 20 , L_92 ) ;
#endif
F_7 ( V_88 , V_45 -> V_19 ) ;
#ifdef F_26
F_67 ( V_45 -> V_19 ) ;
F_67 ( V_45 ) ;
#endif
}
} else {
#ifdef F_30
F_13 ( 20 , L_93 ) ;
#endif
}
}
static void
F_68 ( T_9 * V_102 , T_7 * V_34 , T_10 * V_143 )
{
T_11 * V_144 = NULL ;
T_10 * V_103 = NULL ;
struct V_44 * V_145 ;
T_2 V_146 ;
T_13 V_147 ;
T_14 V_148 ;
T_8 V_149 ;
T_5 V_150 ;
F_69 ( V_102 , 0 , & V_148 , & V_149 , & V_150 ) ;
if( V_148 == V_151 ) {
switch ( V_150 ) {
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
case 6 :
case 22 :
F_70 ( V_152 , V_102 , V_34 , V_143 ) ;
return;
break;
default:
return;
}
}
F_71 ( & V_147 , V_153 , TRUE , V_34 ) ;
V_154 = V_143 ;
V_155 = NULL ;
F_72 ( V_34 -> V_156 , V_157 , L_94 ) ;
if( V_143 ) {
V_144 = F_73 ( V_143 , V_158 , V_102 , 0 , - 1 , V_159 ) ;
V_103 = F_74 ( V_144 , V_160 ) ;
V_155 = V_103 ;
}
V_161 = NULL ;
V_162 = NULL ;
F_75 ( & V_163 ) ;
V_147 . V_164 = & V_163 ;
V_165 = F_66 () ;
V_166 = FALSE ;
V_167 = NULL ;
F_76 ( FALSE , V_102 , 0 , & V_147 , V_103 , - 1 ) ;
if ( V_100 && ! V_166 ) {
V_145 = F_65 ( V_102 , V_34 , V_155 , V_165 ) ;
V_163 . V_35 = V_145 ;
if ( V_145 && V_161 && ! V_145 -> V_168 ) {
F_77 ( V_145 -> V_169 , V_161 , sizeof( V_145 -> V_169 ) ) ;
V_145 -> V_168 = TRUE ;
if ( ( V_146 = F_78 ( V_170 , V_161 ) ) ) {
V_145 -> V_146 = V_146 ;
V_145 -> V_171 = TRUE ;
}
}
if ( V_100 && V_145 && V_145 -> V_172 ) {
( V_145 -> V_172 ) ( V_102 , V_34 , V_155 , V_145 ) ;
}
}
}
void
F_79 ( void )
{
V_173 = F_80 ( L_95 ) ;
V_152 = F_80 ( L_96 ) ;
V_170 = F_81 ( L_97 ) ;
#include "packet-tcap-dis-tab.c"
}
void
F_82 ( void )
{
static T_15 V_174 [] = {
{ & V_175 ,
{ L_98 ,
L_99 ,
V_176 , V_177 , NULL , 0 ,
NULL , V_178 }
} ,
{ & V_179 ,
{ L_100 ,
L_101 ,
V_176 , V_180 , NULL , 0 ,
NULL , V_178 }
} ,
{ & V_181 ,
{ L_102 ,
L_103 ,
V_182 , V_183 , NULL , 0 ,
NULL , V_178 }
} ,
{ & V_184 ,
{ L_104 ,
L_105 ,
V_182 , V_183 , NULL , 0 ,
NULL , V_178 }
} ,
{ & V_185 ,
{ L_106 ,
L_107 ,
V_186 , V_177 , NULL , 0 ,
NULL , V_178 }
} ,
{ & V_122 ,
{ L_108 ,
L_109 ,
V_187 , V_180 , NULL , 0x0 ,
NULL , V_178 }
} ,
{ & V_123 ,
{ L_110 ,
L_111 ,
V_188 , V_183 , NULL , 0x0 ,
L_112 , V_178 }
} ,
{ & V_127 ,
{ L_113 ,
L_114 ,
V_188 , V_183 , NULL , 0x0 ,
L_115 , V_178 }
} ,
{ & V_128 ,
{ L_116 ,
L_117 ,
V_189 , V_183 , NULL , 0x0 ,
L_118 , V_178 }
} ,
{ & V_121 ,
{ L_119 ,
L_120 ,
V_188 , V_183 , NULL , 0x0 ,
L_121 , V_178 }
} ,
#include "packet-tcap-hfarr.c"
} ;
static T_5 * V_190 [] = {
& V_160 ,
& V_191 ,
& V_192 ,
& V_193 ,
& V_120 ,
#include "packet-tcap-ettarr.c"
} ;
T_16 * V_194 ;
V_158 = F_83 ( V_195 , V_196 , V_197 ) ;
F_84 ( V_158 , V_174 , F_85 ( V_174 ) ) ;
F_86 ( V_190 , F_85 ( V_190 ) ) ;
V_194 = F_87 ( V_158 , NULL ) ;
#if 0
prefs_register_enum_preference(tcap_module, "standard", "ITU TCAP standard",
"The SS7 standard used in ITU TCAP packets",
&tcap_standard, tcap_options, FALSE);
#else
F_88 ( V_194 , L_122 ) ;
#endif
#if 0
prefs_register_bool_preference(tcap_module, "lock_info_col", "Lock Info column",
"Always show TCAP in Info column",
&lock_info_col);
#else
F_88 ( V_194 , L_123 ) ;
#endif
F_89 ( & V_198 , L_124 , V_199 ) ;
F_90 ( V_194 , L_125 , L_126 ,
L_127 ,
& V_198 , V_199 ) ;
F_91 ( V_194 , L_128 ,
L_129 ,
L_130 ,
& V_100 ) ;
F_91 ( V_194 , L_131 ,
L_132 ,
L_133 ,
& V_99 ) ;
F_92 ( V_194 , L_134 ,
L_135 ,
L_136 ,
10 , & V_117 ) ;
F_92 ( V_194 , L_137 ,
L_138 ,
L_139 ,
10 , & V_118 ) ;
V_3 = F_49 ( V_200 , V_201 ) ;
V_5 = F_49 ( V_200 , V_201 ) ;
F_93 ( L_140 , F_68 , V_158 ) ;
V_4 = F_94 ( F_68 , V_158 ) ;
F_95 ( & V_202 ) ;
F_96 ( & V_203 ) ;
}
static void F_97 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_9 ( L_1 , V_1 , V_4 ) ;
}
}
static void F_98 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_4 ( L_1 , V_1 , V_4 ) ;
}
}
static void V_202 ( void )
{
V_204 = F_99 ( V_198 ) ;
F_100 ( V_204 , F_98 ) ;
F_47 () ;
}
static void V_203 ( void )
{
F_100 ( V_204 , F_97 ) ;
F_67 ( V_204 ) ;
}
static int
F_101 ( T_13 * V_205 , T_10 * V_103 , T_9 * V_102 , int V_206 )
{
T_5 V_207 , V_208 , V_209 ;
T_9 * V_210 ;
T_10 * V_211 ;
T_14 V_148 ;
T_8 V_149 ;
T_17 V_150 ;
T_1 V_212 ;
T_1 V_213 ;
T_1 V_214 ;
T_8 V_215 ;
while ( F_102 ( V_102 , V_206 ) > 0 )
{
V_208 = V_206 ;
V_206 = F_69 ( V_102 , V_206 , & V_148 , & V_149 , & V_150 ) ;
V_207 = V_206 ;
V_206 = F_103 ( V_102 , V_206 , & V_212 , & V_215 ) ;
V_209 = V_206 ;
V_213 = V_207 - V_208 ;
V_214 = V_209 - V_207 ;
if ( V_149 )
{
V_211 = F_55 ( V_103 , V_102 , V_208 ,
V_212 + ( V_209 - V_208 ) , V_191 , NULL ,
L_141 ) ;
F_57 ( V_211 , V_175 , V_102 ,
V_208 , V_213 , V_150 ,
L_142 ) ;
F_58 ( V_211 , V_175 , V_102 , V_208 ,
V_213 , V_148 ) ;
F_58 ( V_211 , V_179 , V_102 , V_207 ,
V_214 , V_212 ) ;
if ( V_212 - ( 2 * V_215 ) )
{
V_210 = F_104 ( V_102 , V_206 , V_212 - ( 2 * V_215 ) ) ;
F_101 ( V_205 , V_211 , V_210 , 0 ) ;
}
if ( V_215 )
F_73 ( V_211 , V_185 , V_102 , V_206 + V_212 - 2 , 2 , V_216 ) ;
V_206 += V_212 ;
}
else
{
V_211 = F_105 ( V_103 , V_102 , V_208 ,
V_212 + ( V_209 - V_208 ) , V_191 , NULL ,
L_143 , V_150 ) ;
F_58 ( V_211 , V_175 , V_102 , V_208 ,
V_213 , V_150 ) ;
F_58 ( V_211 , V_179 , V_102 ,
V_208 + V_213 , V_214 , V_212 ) ;
if ( V_212 )
{
V_210 = F_104 ( V_102 , V_206 , V_212 ) ;
F_106 ( TRUE , V_205 , V_103 , V_210 , 0 ,
V_181 , NULL ) ;
}
V_206 += V_212 ;
}
}
return V_206 ;
}
static void F_75 ( struct V_217 * V_218 )
{
memset ( V_218 , 0 , sizeof( struct V_217 ) ) ;
}
static int
F_107 ( T_8 T_18 V_6 , T_9 * V_102 , int V_206 , T_13 * V_205 V_6 , T_10 * V_103 , int T_19 V_6 )
{
T_2 V_146 = NULL ;
T_8 V_219 = FALSE ;
struct V_44 * V_145 = NULL ;
if ( V_100 ) {
if ( ! V_166 ) {
V_145 = F_65 ( V_102 , V_205 -> V_34 , V_155 , V_165 ) ;
V_166 = TRUE ;
V_167 = V_145 ;
V_163 . V_35 = V_145 ;
} else {
V_145 = V_167 ;
V_163 . V_35 = V_145 ;
}
}
if ( V_145 ) {
if ( V_161 ) {
if ( V_145 -> V_168 ) {
if ( strncmp ( V_145 -> V_169 , V_161 , sizeof( V_145 -> V_169 ) ) != 0 ) {
F_77 ( V_145 -> V_169 , V_161 , sizeof( V_145 -> V_169 ) ) ;
if ( ( V_146 = F_78 ( V_170 , V_161 ) ) ) {
V_145 -> V_146 = V_146 ;
V_145 -> V_171 = TRUE ;
}
}
} else {
F_77 ( V_145 -> V_169 , V_161 , sizeof( V_145 -> V_169 ) ) ;
V_145 -> V_168 = TRUE ;
if ( ( V_146
= F_78 ( V_170 , V_161 ) ) ) {
V_145 -> V_146 = V_146 ;
V_145 -> V_171 = TRUE ;
} else {
if ( ( V_146 = F_8 ( V_205 -> V_34 -> V_220 ) ) ) {
V_145 -> V_146 = V_146 ;
V_145 -> V_171 = TRUE ;
}
}
}
} else {
if ( V_145 -> V_168 ) {
V_163 . V_169 = ( void * ) V_145 -> V_169 ;
V_163 . V_221 = TRUE ;
}
}
}
if ( V_145
&& V_145 -> V_171 ) {
V_146 = V_145 -> V_146 ;
V_219 = TRUE ;
}
if ( ! V_219 && V_222 ) {
V_219 = TRUE ;
V_146 = V_222 ;
}
if ( ! V_219 ) {
if ( V_170 && V_161 ) {
if ( ( V_146
= F_78 ( V_170 , V_161 ) ) ) {
V_219 = TRUE ;
} else {
if ( ( V_146
= F_8 ( V_205 -> V_34 -> V_220 ) ) ) {
V_219 = TRUE ;
} else {
V_146 = V_173 ;
V_219 = TRUE ;
}
}
} else {
if ( ( V_146 = F_8 ( V_205 -> V_34 -> V_220 ) ) ) {
V_219 = TRUE ;
} else {
V_146 = V_173 ;
V_219 = TRUE ;
}
}
} else {
}
if ( V_219 ) {
F_108 ( V_146 , V_102 , V_205 -> V_34 , V_103 , V_205 -> V_164 ) ;
F_109 ( V_205 -> V_34 -> V_156 , V_223 ) ;
}
return V_206 ;
}
void
F_110 ( T_2 V_224 , T_9 * V_102 , T_7 * V_34 , T_10 * V_103 )
{
V_222 = V_224 ;
F_111 {
F_68 ( V_102 , V_34 , V_103 ) ;
} F_112 {
V_222 = NULL ;
V_225 ;
} V_226 ;
V_222 = NULL ;
}
