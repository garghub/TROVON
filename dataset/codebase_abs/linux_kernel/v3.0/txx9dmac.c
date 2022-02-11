static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_4 T_1 * F_3 ( const struct V_1 * V_5 )
{
return V_5 -> V_6 ;
}
static struct V_7 T_1 * F_4 (
const struct V_1 * V_5 )
{
return V_5 -> V_6 ;
}
static T_2 F_5 ( const struct V_1 * V_5 )
{
if ( sizeof( F_3 ( V_5 ) -> CHAR ) == sizeof( V_8 ) )
return F_6 ( V_5 , CHAR ) ;
else
return F_7 ( V_5 , CHAR ) ;
}
static void F_8 ( const struct V_1 * V_5 , T_2 V_9 )
{
if ( sizeof( F_3 ( V_5 ) -> CHAR ) == sizeof( V_8 ) )
F_9 ( V_5 , CHAR , V_9 ) ;
else
F_10 ( V_5 , CHAR , V_9 ) ;
}
static void F_11 ( const struct V_1 * V_5 )
{
#if F_12 ( V_10 ) && ! F_12 ( V_11 )
F_10 ( V_5 , CHAR , 0 ) ;
F_10 ( V_5 , V_12 , 0 ) ;
#else
F_9 ( V_5 , CHAR , 0 ) ;
#endif
}
static T_2 F_13 ( const struct V_1 * V_5 )
{
if ( F_14 ( V_5 ) )
return F_5 ( V_5 ) ;
else
return F_15 ( V_5 , CHAR ) ;
}
static void F_16 ( const struct V_1 * V_5 , T_2 V_9 )
{
if ( F_14 ( V_5 ) )
F_8 ( V_5 , V_9 ) ;
else
F_17 ( V_5 , CHAR , V_9 ) ;
}
static struct V_13 T_1 * F_18 (
const struct V_14 * V_15 )
{
return V_15 -> V_16 ;
}
static struct V_17 T_1 * F_19 (
const struct V_14 * V_15 )
{
return V_15 -> V_16 ;
}
static struct V_18 * F_20 ( struct V_2 * V_3 )
{
return & V_3 -> V_19 -> V_18 ;
}
static struct V_18 * F_21 ( struct V_2 * V_3 )
{
return V_3 -> V_19 -> V_18 . V_20 ;
}
static struct V_21 *
F_22 ( struct V_22 * V_23 )
{
return F_2 ( V_23 , struct V_21 , V_23 ) ;
}
static T_2 F_23 ( const struct V_1 * V_5 ,
const struct V_21 * V_24 )
{
return F_14 ( V_5 ) ? V_24 -> V_25 . CHAR : V_24 -> V_26 . CHAR ;
}
static void F_24 ( const struct V_1 * V_5 ,
struct V_21 * V_24 , T_2 V_9 )
{
if ( F_14 ( V_5 ) )
V_24 -> V_25 . CHAR = V_9 ;
else
V_24 -> V_26 . CHAR = V_9 ;
}
static struct V_21 * F_25 ( struct V_1 * V_5 )
{
return F_26 ( V_5 -> V_27 . V_28 ,
struct V_21 , V_29 ) ;
}
static struct V_21 * F_27 ( struct V_1 * V_5 )
{
return F_26 ( V_5 -> V_27 . V_30 ,
struct V_21 , V_29 ) ;
}
static struct V_21 * F_28 ( struct V_1 * V_5 )
{
return F_26 ( V_5 -> V_31 . V_28 , struct V_21 , V_29 ) ;
}
static struct V_21 * F_29 ( struct V_21 * V_24 )
{
if ( ! F_30 ( & V_24 -> V_32 ) )
V_24 = F_26 ( V_24 -> V_32 . V_30 , F_31 ( * V_24 ) , V_29 ) ;
return V_24 ;
}
static struct V_21 * F_32 ( struct V_1 * V_5 ,
T_3 V_33 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_21 * V_24 ;
V_24 = F_33 ( sizeof( * V_24 ) , V_33 ) ;
if ( ! V_24 )
return NULL ;
F_34 ( & V_24 -> V_32 ) ;
F_35 ( & V_24 -> V_23 , & V_5 -> V_3 ) ;
V_24 -> V_23 . V_34 = V_35 ;
V_24 -> V_23 . V_33 = V_36 ;
V_24 -> V_23 . V_37 = F_36 ( F_21 ( & V_5 -> V_3 ) , & V_24 -> V_25 ,
V_15 -> V_38 , V_39 ) ;
return V_24 ;
}
static struct V_21 * F_37 ( struct V_1 * V_5 )
{
struct V_21 * V_24 , * V_40 ;
struct V_21 * V_41 = NULL ;
unsigned int V_42 = 0 ;
F_38 ( & V_5 -> V_43 ) ;
F_39 (desc, _desc, &dc->free_list, desc_node) {
if ( F_40 ( & V_24 -> V_23 ) ) {
F_41 ( & V_24 -> V_29 ) ;
V_41 = V_24 ;
break;
}
F_42 ( F_20 ( & V_5 -> V_3 ) , L_1 , V_24 ) ;
V_42 ++ ;
}
F_43 ( & V_5 -> V_43 ) ;
F_44 ( F_20 ( & V_5 -> V_3 ) , L_2 ,
V_42 ) ;
if ( ! V_41 ) {
V_41 = F_32 ( V_5 , V_44 ) ;
if ( V_41 ) {
F_38 ( & V_5 -> V_43 ) ;
V_5 -> V_45 ++ ;
F_43 ( & V_5 -> V_43 ) ;
} else
F_45 ( F_20 ( & V_5 -> V_3 ) ,
L_3 ) ;
}
return V_41 ;
}
static void F_46 ( struct V_1 * V_5 ,
struct V_21 * V_24 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_21 * V_46 ;
F_47 (child, &desc->tx_list, desc_node)
F_48 ( F_21 ( & V_5 -> V_3 ) ,
V_46 -> V_23 . V_37 , V_15 -> V_38 ,
V_39 ) ;
F_48 ( F_21 ( & V_5 -> V_3 ) ,
V_24 -> V_23 . V_37 , V_15 -> V_38 ,
V_39 ) ;
}
static void F_49 ( struct V_1 * V_5 ,
struct V_21 * V_24 )
{
if ( V_24 ) {
struct V_21 * V_46 ;
F_46 ( V_5 , V_24 ) ;
F_38 ( & V_5 -> V_43 ) ;
F_47 (child, &desc->tx_list, desc_node)
F_44 ( F_20 ( & V_5 -> V_3 ) ,
L_4 ,
V_46 ) ;
F_50 ( & V_24 -> V_32 , & V_5 -> V_47 ) ;
F_44 ( F_20 ( & V_5 -> V_3 ) , L_5 ,
V_24 ) ;
F_51 ( & V_24 -> V_29 , & V_5 -> V_47 ) ;
F_43 ( & V_5 -> V_43 ) ;
}
}
static T_4
F_52 ( struct V_1 * V_5 , struct V_21 * V_24 )
{
T_4 V_48 = V_5 -> V_3 . V_48 ;
if ( ++ V_48 < 0 )
V_48 = 1 ;
V_5 -> V_3 . V_48 = V_48 ;
V_24 -> V_23 . V_48 = V_48 ;
return V_48 ;
}
static void F_53 ( struct V_1 * V_5 )
{
if ( F_14 ( V_5 ) )
F_45 ( F_20 ( & V_5 -> V_3 ) ,
L_6
L_7 ,
( V_8 ) F_5 ( V_5 ) ,
F_6 ( V_5 , V_49 ) ,
F_6 ( V_5 , V_50 ) ,
F_7 ( V_5 , V_51 ) ,
F_7 ( V_5 , V_52 ) ,
F_7 ( V_5 , V_53 ) ,
F_7 ( V_5 , V_54 ) ,
F_7 ( V_5 , V_55 ) ) ;
else
F_45 ( F_20 ( & V_5 -> V_3 ) ,
L_8
L_7 ,
F_15 ( V_5 , CHAR ) ,
F_15 ( V_5 , V_49 ) ,
F_15 ( V_5 , V_50 ) ,
F_15 ( V_5 , V_51 ) ,
F_15 ( V_5 , V_52 ) ,
F_15 ( V_5 , V_53 ) ,
F_15 ( V_5 , V_54 ) ,
F_15 ( V_5 , V_55 ) ) ;
}
static void F_54 ( struct V_1 * V_5 )
{
F_55 ( V_5 , V_54 , V_56 ) ;
if ( F_14 ( V_5 ) ) {
F_11 ( V_5 ) ;
F_56 ( V_5 , V_49 , 0 ) ;
F_56 ( V_5 , V_50 , 0 ) ;
} else {
F_55 ( V_5 , CHAR , 0 ) ;
F_55 ( V_5 , V_49 , 0 ) ;
F_55 ( V_5 , V_50 , 0 ) ;
}
F_55 ( V_5 , V_51 , 0 ) ;
F_55 ( V_5 , V_52 , 0 ) ;
F_55 ( V_5 , V_53 , 0 ) ;
F_55 ( V_5 , V_54 , 0 ) ;
F_57 () ;
}
static void F_58 ( struct V_1 * V_5 ,
struct V_21 * V_57 )
{
struct V_58 * V_59 = V_5 -> V_3 . V_60 ;
T_5 V_61 , V_62 ;
F_44 ( F_20 ( & V_5 -> V_3 ) , L_9 ,
V_57 -> V_23 . V_48 , V_57 ) ;
if ( F_59 ( V_5 , V_55 ) & V_63 ) {
F_45 ( F_20 ( & V_5 -> V_3 ) ,
L_10 ) ;
F_53 ( V_5 ) ;
return;
}
if ( F_14 ( V_5 ) ) {
F_10 ( V_5 , V_51 , 0 ) ;
F_10 ( V_5 , V_55 , 0xffffffff ) ;
if ( V_59 ) {
if ( V_59 -> V_64 ) {
V_61 = V_59 -> V_65 ;
V_62 = 0 ;
} else {
V_61 = 0 ;
V_62 = V_59 -> V_65 ;
}
} else {
V_61 = 8 ;
V_62 = 8 ;
}
F_10 ( V_5 , V_52 , V_61 ) ;
F_10 ( V_5 , V_53 , V_62 ) ;
F_10 ( V_5 , V_54 , V_5 -> V_66 ) ;
F_8 ( V_5 , V_57 -> V_23 . V_37 ) ;
} else {
F_17 ( V_5 , V_51 , 0 ) ;
F_17 ( V_5 , V_55 , 0xffffffff ) ;
if ( V_59 ) {
if ( V_59 -> V_64 ) {
V_61 = V_59 -> V_65 ;
V_62 = 0 ;
} else {
V_61 = 0 ;
V_62 = V_59 -> V_65 ;
}
} else {
V_61 = 4 ;
V_62 = 4 ;
}
F_17 ( V_5 , V_52 , V_61 ) ;
F_17 ( V_5 , V_53 , V_62 ) ;
if ( F_60 () ) {
F_17 ( V_5 , V_54 , V_5 -> V_66 ) ;
F_17 ( V_5 , CHAR , V_57 -> V_23 . V_37 ) ;
} else {
F_17 ( V_5 , CHAR , V_57 -> V_23 . V_37 ) ;
F_17 ( V_5 , V_54 , V_5 -> V_66 ) ;
}
}
}
static void
F_61 ( struct V_1 * V_5 ,
struct V_21 * V_24 )
{
T_6 V_67 ;
void * V_68 ;
struct V_22 * V_23 = & V_24 -> V_23 ;
struct V_58 * V_59 = V_5 -> V_3 . V_60 ;
F_44 ( F_20 ( & V_5 -> V_3 ) , L_11 ,
V_23 -> V_48 , V_24 ) ;
V_5 -> V_69 = V_23 -> V_48 ;
V_67 = V_23 -> V_67 ;
V_68 = V_23 -> V_70 ;
F_46 ( V_5 , V_24 ) ;
F_50 ( & V_24 -> V_32 , & V_5 -> V_47 ) ;
F_62 ( & V_24 -> V_29 , & V_5 -> V_47 ) ;
if ( ! V_59 ) {
T_2 V_71 ;
if ( ! ( V_23 -> V_33 & V_72 ) ) {
V_71 = F_14 ( V_5 ) ?
V_24 -> V_25 . V_50 : V_24 -> V_26 . V_50 ;
if ( V_23 -> V_33 & V_73 )
F_63 ( F_21 ( & V_5 -> V_3 ) ,
V_71 , V_24 -> V_74 , V_75 ) ;
else
F_64 ( F_21 ( & V_5 -> V_3 ) ,
V_71 , V_24 -> V_74 , V_75 ) ;
}
if ( ! ( V_23 -> V_33 & V_76 ) ) {
V_71 = F_14 ( V_5 ) ?
V_24 -> V_25 . V_49 : V_24 -> V_26 . V_49 ;
if ( V_23 -> V_33 & V_77 )
F_63 ( F_21 ( & V_5 -> V_3 ) ,
V_71 , V_24 -> V_74 , V_39 ) ;
else
F_64 ( F_21 ( & V_5 -> V_3 ) ,
V_71 , V_24 -> V_74 , V_39 ) ;
}
}
if ( V_67 )
V_67 ( V_68 ) ;
F_65 ( V_23 ) ;
}
static void F_66 ( struct V_1 * V_5 , struct V_78 * V_79 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_21 * V_24 ;
struct V_21 * V_30 = NULL ;
F_67 ( ! F_30 ( V_79 ) ) ;
do {
V_24 = F_28 ( V_5 ) ;
if ( V_30 ) {
F_24 ( V_5 , V_30 , V_24 -> V_23 . V_37 ) ;
F_68 ( F_21 ( & V_5 -> V_3 ) ,
V_30 -> V_23 . V_37 , V_15 -> V_38 ,
V_39 ) ;
}
V_30 = F_29 ( V_24 ) ;
F_69 ( & V_24 -> V_29 , V_79 ) ;
if ( ( V_24 -> V_23 . V_33 & V_80 ) &&
! F_70 ( V_5 ) )
break;
} while ( ! F_30 ( & V_5 -> V_31 ) );
}
static void F_71 ( struct V_1 * V_5 )
{
struct V_21 * V_24 , * V_40 ;
F_72 ( V_79 ) ;
F_50 ( & V_5 -> V_27 , & V_79 ) ;
if ( ! F_30 ( & V_5 -> V_31 ) ) {
F_66 ( V_5 , & V_5 -> V_27 ) ;
F_58 ( V_5 , F_25 ( V_5 ) ) ;
}
F_39 (desc, _desc, &list, desc_node)
F_61 ( V_5 , V_24 ) ;
}
static void F_73 ( struct V_1 * V_5 ,
struct V_81 * V_24 )
{
if ( F_14 ( V_5 ) ) {
#ifdef F_74
F_75 ( F_20 ( & V_5 -> V_3 ) ,
L_12 ,
( V_8 ) V_24 -> CHAR , V_24 -> V_49 , V_24 -> V_50 , V_24 -> V_51 ) ;
#else
F_75 ( F_20 ( & V_5 -> V_3 ) ,
L_13
L_14 ,
( V_8 ) V_24 -> CHAR , V_24 -> V_49 , V_24 -> V_50 , V_24 -> V_51 ,
V_24 -> V_52 , V_24 -> V_53 , V_24 -> V_54 , V_24 -> V_55 ) ;
#endif
} else {
struct V_82 * V_83 = (struct V_82 * ) V_24 ;
#ifdef F_74
F_75 ( F_20 ( & V_5 -> V_3 ) ,
L_15 ,
V_83 -> CHAR , V_83 -> V_49 , V_83 -> V_50 , V_83 -> V_51 ) ;
#else
F_75 ( F_20 ( & V_5 -> V_3 ) ,
L_16
L_14 ,
V_83 -> CHAR , V_83 -> V_49 , V_83 -> V_50 , V_83 -> V_51 ,
V_83 -> V_52 , V_83 -> V_53 , V_83 -> V_54 , V_83 -> V_55 ) ;
#endif
}
}
static void F_76 ( struct V_1 * V_5 , T_5 V_84 )
{
struct V_21 * V_85 ;
struct V_21 * V_46 ;
T_5 V_86 ;
F_75 ( F_20 ( & V_5 -> V_3 ) , L_17 ) ;
F_53 ( V_5 ) ;
V_85 = F_25 ( V_5 ) ;
F_77 ( & V_85 -> V_29 ) ;
V_86 = V_84 & ( V_87 |
V_88 | V_89 |
V_90 | V_91 ) ;
F_55 ( V_5 , V_55 , V_86 ) ;
if ( F_30 ( & V_5 -> V_27 ) && ! F_30 ( & V_5 -> V_31 ) )
F_66 ( V_5 , & V_5 -> V_27 ) ;
if ( ! F_30 ( & V_5 -> V_27 ) )
F_58 ( V_5 , F_25 ( V_5 ) ) ;
F_75 ( F_20 ( & V_5 -> V_3 ) ,
L_18 ,
V_85 -> V_23 . V_48 ) ;
F_73 ( V_5 , & V_85 -> V_25 ) ;
F_47 (child, &bad_desc->tx_list, desc_node)
F_73 ( V_5 , & V_46 -> V_25 ) ;
F_61 ( V_5 , V_85 ) ;
}
static void F_78 ( struct V_1 * V_5 )
{
T_2 V_92 ;
struct V_21 * V_24 , * V_40 ;
struct V_21 * V_46 ;
T_5 V_84 ;
if ( F_14 ( V_5 ) ) {
V_92 = F_5 ( V_5 ) ;
V_84 = F_7 ( V_5 , V_55 ) ;
F_10 ( V_5 , V_55 , V_84 ) ;
} else {
V_92 = F_15 ( V_5 , CHAR ) ;
V_84 = F_15 ( V_5 , V_55 ) ;
F_17 ( V_5 , V_55 , V_84 ) ;
}
if ( ! ( V_84 & ( V_63 | V_87 ) ) ) {
F_71 ( V_5 ) ;
return;
}
if ( ! ( V_84 & V_93 ) )
V_92 = 0 ;
F_44 ( F_20 ( & V_5 -> V_3 ) , L_19 ,
( V_8 ) V_92 ) ;
F_39 (desc, _desc, &dc->active_list, desc_node) {
if ( F_23 ( V_5 , V_24 ) == V_92 ) {
if ( V_84 & V_87 )
goto V_94;
return;
}
F_47 (child, &desc->tx_list, desc_node)
if ( F_23 ( V_5 , V_46 ) == V_92 ) {
if ( V_84 & V_87 )
goto V_94;
return;
}
F_61 ( V_5 , V_24 ) ;
}
V_94:
if ( V_84 & V_87 ) {
F_76 ( V_5 , V_84 ) ;
return;
}
F_45 ( F_20 ( & V_5 -> V_3 ) ,
L_20 ) ;
F_54 ( V_5 ) ;
if ( ! F_30 ( & V_5 -> V_31 ) ) {
F_66 ( V_5 , & V_5 -> V_27 ) ;
F_58 ( V_5 , F_25 ( V_5 ) ) ;
}
}
static void F_79 ( unsigned long V_95 )
{
int V_96 ;
T_5 V_84 ;
struct V_1 * V_5 ;
V_5 = (struct V_1 * ) V_95 ;
V_84 = F_59 ( V_5 , V_55 ) ;
F_44 ( F_20 ( & V_5 -> V_3 ) , L_21 , V_84 ) ;
F_80 ( & V_5 -> V_43 ) ;
if ( V_84 & ( V_87 | V_97 |
V_98 ) )
F_78 ( V_5 ) ;
F_81 ( & V_5 -> V_43 ) ;
V_96 = V_5 -> V_96 ;
F_82 ( V_96 ) ;
}
static T_7 F_83 ( int V_96 , void * V_99 )
{
struct V_1 * V_5 = V_99 ;
F_44 ( F_20 ( & V_5 -> V_3 ) , L_22 ,
F_59 ( V_5 , V_55 ) ) ;
F_84 ( & V_5 -> V_100 ) ;
F_85 ( V_96 ) ;
return V_101 ;
}
static void F_86 ( unsigned long V_95 )
{
int V_96 ;
T_5 V_84 ;
struct V_1 * V_5 ;
struct V_14 * V_15 = (struct V_14 * ) V_95 ;
T_5 V_102 ;
int V_42 ;
V_102 = F_87 ( V_15 , V_103 ) ;
F_44 ( V_15 -> V_3 [ 0 ] -> V_104 . V_19 , L_23 , V_102 ) ;
for ( V_42 = 0 ; V_42 < V_105 ; V_42 ++ ) {
if ( ( V_102 >> ( 24 + V_42 ) ) & 0x11 ) {
V_5 = V_15 -> V_3 [ V_42 ] ;
V_84 = F_59 ( V_5 , V_55 ) ;
F_44 ( F_20 ( & V_5 -> V_3 ) , L_21 ,
V_84 ) ;
F_80 ( & V_5 -> V_43 ) ;
if ( V_84 & ( V_87 | V_97 |
V_98 ) )
F_78 ( V_5 ) ;
F_81 ( & V_5 -> V_43 ) ;
}
}
V_96 = V_15 -> V_96 ;
F_82 ( V_96 ) ;
}
static T_7 F_88 ( int V_96 , void * V_99 )
{
struct V_14 * V_15 = V_99 ;
F_44 ( V_15 -> V_3 [ 0 ] -> V_104 . V_19 , L_22 ,
F_87 ( V_15 , V_103 ) ) ;
F_84 ( & V_15 -> V_100 ) ;
F_85 ( V_96 ) ;
return V_101 ;
}
static T_4 V_35 ( struct V_22 * V_106 )
{
struct V_21 * V_24 = F_22 ( V_106 ) ;
struct V_1 * V_5 = F_1 ( V_106 -> V_3 ) ;
T_4 V_48 ;
F_38 ( & V_5 -> V_43 ) ;
V_48 = F_52 ( V_5 , V_24 ) ;
F_44 ( F_20 ( V_106 -> V_3 ) , L_24 ,
V_24 -> V_23 . V_48 , V_24 ) ;
F_89 ( & V_24 -> V_29 , & V_5 -> V_31 ) ;
F_43 ( & V_5 -> V_43 ) ;
return V_48 ;
}
static struct V_22 *
F_90 ( struct V_2 * V_3 , T_2 V_107 , T_2 V_108 ,
T_8 V_74 , unsigned long V_33 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_21 * V_24 ;
struct V_21 * V_57 ;
struct V_21 * V_30 ;
T_8 V_109 ;
T_8 V_110 ;
F_44 ( F_20 ( V_3 ) , L_25 ,
( V_8 ) V_107 , ( V_8 ) V_108 , V_74 , V_33 ) ;
if ( F_91 ( ! V_74 ) ) {
F_42 ( F_20 ( V_3 ) , L_26 ) ;
return NULL ;
}
V_30 = V_57 = NULL ;
for ( V_110 = 0 ; V_110 < V_74 ; V_110 += V_109 ) {
V_109 = F_92 ( T_8 , V_74 - V_110 , V_111 ) ;
if ( F_93 ( V_15 ) ) {
if ( V_109 > 0x100 &&
( V_109 & 0xff ) >= 0xfa &&
( V_109 & 0xff ) <= 0xff )
V_109 -= 0x20 ;
} else {
if ( V_109 > 0x80 &&
( V_109 & 0x7f ) >= 0x7e &&
( V_109 & 0x7f ) <= 0x7f )
V_109 -= 0x20 ;
}
V_24 = F_37 ( V_5 ) ;
if ( ! V_24 ) {
F_49 ( V_5 , V_57 ) ;
return NULL ;
}
if ( F_93 ( V_15 ) ) {
V_24 -> V_25 . V_49 = V_108 + V_110 ;
V_24 -> V_25 . V_50 = V_107 + V_110 ;
V_24 -> V_25 . V_51 = V_109 ;
F_94 ( V_15 , V_24 , 8 , 8 ,
V_5 -> V_66 | V_112 ) ;
} else {
V_24 -> V_26 . V_49 = V_108 + V_110 ;
V_24 -> V_26 . V_50 = V_107 + V_110 ;
V_24 -> V_26 . V_51 = V_109 ;
F_94 ( V_15 , V_24 , 4 , 4 ,
V_5 -> V_66 | V_112 ) ;
}
if ( ! V_57 ) {
V_57 = V_24 ;
} else {
F_24 ( V_5 , V_30 , V_24 -> V_23 . V_37 ) ;
F_68 ( F_21 ( & V_5 -> V_3 ) ,
V_30 -> V_23 . V_37 , V_15 -> V_38 ,
V_39 ) ;
F_89 ( & V_24 -> V_29 , & V_57 -> V_32 ) ;
}
V_30 = V_24 ;
}
if ( V_33 & V_80 )
F_95 ( V_15 , V_30 ) ;
F_24 ( V_5 , V_30 , 0 ) ;
F_68 ( F_21 ( & V_5 -> V_3 ) ,
V_30 -> V_23 . V_37 , V_15 -> V_38 ,
V_39 ) ;
V_57 -> V_23 . V_33 = V_33 ;
V_57 -> V_74 = V_74 ;
return & V_57 -> V_23 ;
}
static struct V_22 *
F_96 ( struct V_2 * V_3 , struct V_113 * V_114 ,
unsigned int V_115 , enum V_116 V_117 ,
unsigned long V_33 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_58 * V_59 = V_3 -> V_60 ;
struct V_21 * V_30 ;
struct V_21 * V_57 ;
unsigned int V_42 ;
struct V_113 * V_118 ;
F_44 ( F_20 ( V_3 ) , L_27 ) ;
F_67 ( ! V_59 || ! V_59 -> V_65 ) ;
if ( V_59 -> V_64 )
F_67 ( V_117 != V_39 ) ;
else
F_67 ( V_117 != V_75 ) ;
if ( F_91 ( ! V_115 ) )
return NULL ;
V_30 = V_57 = NULL ;
F_97 (sgl, sg, sg_len, i) {
struct V_21 * V_24 ;
T_2 V_119 ;
T_5 V_61 , V_62 ;
V_24 = F_37 ( V_5 ) ;
if ( ! V_24 ) {
F_49 ( V_5 , V_57 ) ;
return NULL ;
}
V_119 = F_98 ( V_118 ) ;
if ( F_93 ( V_15 ) ) {
if ( V_117 == V_39 ) {
V_24 -> V_25 . V_49 = V_119 ;
V_24 -> V_25 . V_50 = V_59 -> V_64 ;
} else {
V_24 -> V_25 . V_49 = V_59 -> V_120 ;
V_24 -> V_25 . V_50 = V_119 ;
}
V_24 -> V_25 . V_51 = F_99 ( V_118 ) ;
} else {
if ( V_117 == V_39 ) {
V_24 -> V_26 . V_49 = V_119 ;
V_24 -> V_26 . V_50 = V_59 -> V_64 ;
} else {
V_24 -> V_26 . V_49 = V_59 -> V_120 ;
V_24 -> V_26 . V_50 = V_119 ;
}
V_24 -> V_26 . V_51 = F_99 ( V_118 ) ;
}
if ( V_117 == V_39 ) {
V_61 = V_59 -> V_65 ;
V_62 = 0 ;
} else {
V_61 = 0 ;
V_62 = V_59 -> V_65 ;
}
F_94 ( V_15 , V_24 , V_61 , V_62 ,
V_5 -> V_66 | V_112 ) ;
if ( ! V_57 ) {
V_57 = V_24 ;
} else {
F_24 ( V_5 , V_30 , V_24 -> V_23 . V_37 ) ;
F_68 ( F_21 ( & V_5 -> V_3 ) ,
V_30 -> V_23 . V_37 ,
V_15 -> V_38 ,
V_39 ) ;
F_89 ( & V_24 -> V_29 , & V_57 -> V_32 ) ;
}
V_30 = V_24 ;
}
if ( V_33 & V_80 )
F_95 ( V_15 , V_30 ) ;
F_24 ( V_5 , V_30 , 0 ) ;
F_68 ( F_21 ( & V_5 -> V_3 ) ,
V_30 -> V_23 . V_37 , V_15 -> V_38 ,
V_39 ) ;
V_57 -> V_23 . V_33 = V_33 ;
V_57 -> V_74 = 0 ;
return & V_57 -> V_23 ;
}
static int F_100 ( struct V_2 * V_3 , enum V_121 V_122 ,
unsigned long V_123 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_21 * V_24 , * V_40 ;
F_72 ( V_79 ) ;
if ( V_122 != V_124 )
return - V_125 ;
F_44 ( F_20 ( V_3 ) , L_28 ) ;
F_38 ( & V_5 -> V_43 ) ;
F_54 ( V_5 ) ;
F_50 ( & V_5 -> V_31 , & V_79 ) ;
F_50 ( & V_5 -> V_27 , & V_79 ) ;
F_43 ( & V_5 -> V_43 ) ;
F_39 (desc, _desc, &list, desc_node)
F_61 ( V_5 , V_24 ) ;
return 0 ;
}
static enum V_126
F_101 ( struct V_2 * V_3 , T_4 V_48 ,
struct V_127 * V_128 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_4 V_129 ;
T_4 V_130 ;
int V_41 ;
V_130 = V_5 -> V_69 ;
V_129 = V_3 -> V_48 ;
V_41 = F_102 ( V_48 , V_130 , V_129 ) ;
if ( V_41 != V_131 ) {
F_38 ( & V_5 -> V_43 ) ;
F_78 ( V_5 ) ;
F_43 ( & V_5 -> V_43 ) ;
V_130 = V_5 -> V_69 ;
V_129 = V_3 -> V_48 ;
V_41 = F_102 ( V_48 , V_130 , V_129 ) ;
}
F_103 ( V_128 , V_130 , V_129 , 0 ) ;
return V_41 ;
}
static void F_104 ( struct V_1 * V_5 ,
struct V_21 * V_30 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_21 * V_24 ;
F_72 ( V_79 ) ;
V_30 = F_29 ( V_30 ) ;
F_66 ( V_5 , & V_79 ) ;
V_24 = F_26 ( V_79 . V_28 , struct V_21 , V_29 ) ;
F_24 ( V_5 , V_30 , V_24 -> V_23 . V_37 ) ;
F_68 ( F_21 ( & V_5 -> V_3 ) ,
V_30 -> V_23 . V_37 , V_15 -> V_38 ,
V_39 ) ;
F_57 () ;
if ( ! ( F_59 ( V_5 , V_55 ) & V_93 ) &&
F_13 ( V_5 ) == V_30 -> V_23 . V_37 )
F_16 ( V_5 , V_24 -> V_23 . V_37 ) ;
F_105 ( & V_79 , & V_5 -> V_27 ) ;
}
static void F_106 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_38 ( & V_5 -> V_43 ) ;
if ( ! F_30 ( & V_5 -> V_27 ) )
F_78 ( V_5 ) ;
if ( ! F_30 ( & V_5 -> V_31 ) ) {
if ( F_30 ( & V_5 -> V_27 ) ) {
F_66 ( V_5 , & V_5 -> V_27 ) ;
F_58 ( V_5 , F_25 ( V_5 ) ) ;
} else if ( F_60 () ) {
struct V_21 * V_30 = F_27 ( V_5 ) ;
if ( ! ( V_30 -> V_23 . V_33 & V_80 ) ||
F_70 ( V_5 ) )
F_104 ( V_5 , V_30 ) ;
}
}
F_43 ( & V_5 -> V_43 ) ;
}
static int F_107 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_58 * V_59 = V_3 -> V_60 ;
struct V_21 * V_24 ;
int V_42 ;
F_44 ( F_20 ( V_3 ) , L_29 ) ;
if ( F_59 ( V_5 , V_55 ) & V_63 ) {
F_42 ( F_20 ( V_3 ) , L_30 ) ;
return - V_132 ;
}
V_5 -> V_69 = V_3 -> V_48 = 1 ;
V_5 -> V_66 = V_133 | V_134 | V_135 ;
F_108 ( V_5 ) ;
if ( ! F_60 () || ( V_5 -> V_66 & V_136 ) )
V_5 -> V_66 |= V_137 ;
if ( V_3 -> V_18 -> V_138 ) {
if ( V_59 )
return - V_125 ;
V_5 -> V_66 |= V_139 ;
} else {
if ( ! V_59 ||
( V_59 -> V_64 && V_59 -> V_120 ) || ( ! V_59 -> V_64 && ! V_59 -> V_120 ) )
return - V_125 ;
V_5 -> V_66 |= V_140 |
F_109 ( F_110 ( V_59 -> V_65 ) ) ;
F_111 ( V_5 ) ;
}
F_38 ( & V_5 -> V_43 ) ;
V_42 = V_5 -> V_45 ;
while ( V_5 -> V_45 < V_141 ) {
F_43 ( & V_5 -> V_43 ) ;
V_24 = F_32 ( V_5 , V_142 ) ;
if ( ! V_24 ) {
F_112 ( F_20 ( V_3 ) ,
L_31 , V_42 ) ;
F_38 ( & V_5 -> V_43 ) ;
break;
}
F_49 ( V_5 , V_24 ) ;
F_38 ( & V_5 -> V_43 ) ;
V_42 = ++ V_5 -> V_45 ;
}
F_43 ( & V_5 -> V_43 ) ;
F_42 ( F_20 ( V_3 ) ,
L_32 , V_42 ) ;
return V_42 ;
}
static void F_113 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_21 * V_24 , * V_40 ;
F_72 ( V_79 ) ;
F_42 ( F_20 ( V_3 ) , L_33 ,
V_5 -> V_45 ) ;
F_67 ( ! F_30 ( & V_5 -> V_27 ) ) ;
F_67 ( ! F_30 ( & V_5 -> V_31 ) ) ;
F_67 ( F_59 ( V_5 , V_55 ) & V_63 ) ;
F_38 ( & V_5 -> V_43 ) ;
F_50 ( & V_5 -> V_47 , & V_79 ) ;
V_5 -> V_45 = 0 ;
F_43 ( & V_5 -> V_43 ) ;
F_39 (desc, _desc, &list, desc_node) {
F_44 ( F_20 ( V_3 ) , L_34 , V_24 ) ;
F_63 ( F_21 ( V_3 ) , V_24 -> V_23 . V_37 ,
V_15 -> V_38 , V_39 ) ;
F_114 ( V_24 ) ;
}
F_44 ( F_20 ( V_3 ) , L_35 ) ;
}
static void F_115 ( struct V_14 * V_15 )
{
F_116 ( V_15 , V_103 , 0 ) ;
F_57 () ;
}
static int T_9 F_117 ( struct V_143 * V_144 )
{
struct V_145 * V_146 = V_144 -> V_19 . V_147 ;
struct V_143 * V_148 = V_146 -> V_148 ;
struct V_149 * V_150 = V_148 -> V_19 . V_147 ;
struct V_1 * V_5 ;
int V_151 ;
int V_152 = V_144 -> V_153 % V_105 ;
int V_96 ;
V_5 = F_118 ( & V_144 -> V_19 , sizeof( * V_5 ) , V_142 ) ;
if ( ! V_5 )
return - V_154 ;
V_5 -> V_104 . V_19 = & V_144 -> V_19 ;
V_5 -> V_104 . V_155 = F_107 ;
V_5 -> V_104 . V_156 = F_113 ;
V_5 -> V_104 . V_157 = F_100 ;
V_5 -> V_104 . V_158 = F_101 ;
V_5 -> V_104 . V_159 = F_106 ;
if ( V_150 && V_150 -> V_160 == V_152 ) {
V_5 -> V_104 . V_138 = F_90 ;
F_119 ( V_161 , V_5 -> V_104 . V_162 ) ;
} else {
V_5 -> V_104 . V_163 = F_96 ;
F_119 ( V_164 , V_5 -> V_104 . V_162 ) ;
F_119 ( V_165 , V_5 -> V_104 . V_162 ) ;
}
F_34 ( & V_5 -> V_104 . V_166 ) ;
V_5 -> V_15 = F_120 ( V_148 ) ;
if ( V_5 -> V_15 -> V_96 < 0 ) {
V_96 = F_121 ( V_144 , 0 ) ;
if ( V_96 < 0 )
return V_96 ;
F_122 ( & V_5 -> V_100 , F_79 ,
( unsigned long ) V_5 ) ;
V_5 -> V_96 = V_96 ;
V_151 = F_123 ( & V_144 -> V_19 , V_5 -> V_96 ,
F_83 , 0 , F_124 ( & V_144 -> V_19 ) , V_5 ) ;
if ( V_151 )
return V_151 ;
} else
V_5 -> V_96 = - 1 ;
V_5 -> V_15 -> V_3 [ V_152 ] = V_5 ;
V_5 -> V_3 . V_18 = & V_5 -> V_104 ;
F_89 ( & V_5 -> V_3 . V_167 , & V_5 -> V_3 . V_18 -> V_166 ) ;
V_5 -> V_3 . V_48 = V_5 -> V_69 = 1 ;
if ( F_14 ( V_5 ) )
V_5 -> V_6 = & F_18 ( V_5 -> V_15 ) -> V_168 [ V_152 ] ;
else
V_5 -> V_6 = & F_19 ( V_5 -> V_15 ) -> V_168 [ V_152 ] ;
F_125 ( & V_5 -> V_43 ) ;
F_34 ( & V_5 -> V_27 ) ;
F_34 ( & V_5 -> V_31 ) ;
F_34 ( & V_5 -> V_47 ) ;
F_54 ( V_5 ) ;
F_126 ( V_144 , V_5 ) ;
V_151 = F_127 ( & V_5 -> V_104 ) ;
if ( V_151 )
return V_151 ;
F_42 ( & V_144 -> V_19 , L_36 ,
V_5 -> V_104 . V_99 ,
F_128 ( V_161 , V_5 -> V_104 . V_162 ) ? L_37 : L_38 ,
F_128 ( V_164 , V_5 -> V_104 . V_162 ) ? L_39 : L_38 ) ;
return 0 ;
}
static int T_10 F_129 ( struct V_143 * V_144 )
{
struct V_1 * V_5 = F_120 ( V_144 ) ;
F_130 ( & V_5 -> V_104 ) ;
if ( V_5 -> V_96 >= 0 )
F_131 ( & V_5 -> V_100 ) ;
V_5 -> V_15 -> V_3 [ V_144 -> V_153 % V_105 ] = NULL ;
return 0 ;
}
static int T_9 F_132 ( struct V_143 * V_144 )
{
struct V_149 * V_150 = V_144 -> V_19 . V_147 ;
struct V_169 * V_170 ;
struct V_14 * V_15 ;
T_5 V_102 ;
int V_151 ;
V_170 = F_133 ( V_144 , V_171 , 0 ) ;
if ( ! V_170 )
return - V_125 ;
V_15 = F_118 ( & V_144 -> V_19 , sizeof( * V_15 ) , V_142 ) ;
if ( ! V_15 )
return - V_154 ;
if ( ! F_134 ( & V_144 -> V_19 , V_170 -> V_172 , F_135 ( V_170 ) ,
F_124 ( & V_144 -> V_19 ) ) )
return - V_173 ;
V_15 -> V_16 = F_136 ( & V_144 -> V_19 , V_170 -> V_172 , F_135 ( V_170 ) ) ;
if ( ! V_15 -> V_16 )
return - V_154 ;
V_15 -> V_174 = V_150 -> V_174 ;
if ( F_93 ( V_15 ) )
V_15 -> V_38 = sizeof( struct V_81 ) ;
else
V_15 -> V_38 = sizeof( struct V_82 ) ;
F_115 ( V_15 ) ;
V_15 -> V_96 = F_121 ( V_144 , 0 ) ;
if ( V_15 -> V_96 >= 0 ) {
F_122 ( & V_15 -> V_100 , F_86 ,
( unsigned long ) V_15 ) ;
V_151 = F_123 ( & V_144 -> V_19 , V_15 -> V_96 ,
F_88 , 0 , F_124 ( & V_144 -> V_19 ) , V_15 ) ;
if ( V_151 )
return V_151 ;
}
V_102 = V_175 | V_176 ;
if ( V_150 && V_150 -> V_160 >= 0 )
V_102 |= F_137 ( V_150 -> V_160 ) ;
F_116 ( V_15 , V_103 , V_102 ) ;
F_126 ( V_144 , V_15 ) ;
return 0 ;
}
static int T_10 F_138 ( struct V_143 * V_144 )
{
struct V_14 * V_15 = F_120 ( V_144 ) ;
F_115 ( V_15 ) ;
if ( V_15 -> V_96 >= 0 )
F_131 ( & V_15 -> V_100 ) ;
return 0 ;
}
static void F_139 ( struct V_143 * V_144 )
{
struct V_14 * V_15 = F_120 ( V_144 ) ;
F_115 ( V_15 ) ;
}
static int F_140 ( struct V_18 * V_19 )
{
struct V_143 * V_144 = F_141 ( V_19 ) ;
struct V_14 * V_15 = F_120 ( V_144 ) ;
F_115 ( V_15 ) ;
return 0 ;
}
static int F_142 ( struct V_18 * V_19 )
{
struct V_143 * V_144 = F_141 ( V_19 ) ;
struct V_14 * V_15 = F_120 ( V_144 ) ;
struct V_149 * V_150 = V_144 -> V_19 . V_147 ;
T_5 V_102 ;
V_102 = V_175 | V_176 ;
if ( V_150 && V_150 -> V_160 >= 0 )
V_102 |= F_137 ( V_150 -> V_160 ) ;
F_116 ( V_15 , V_103 , V_102 ) ;
return 0 ;
}
static int T_9 F_143 ( void )
{
int V_177 ;
V_177 = F_144 ( & V_178 , F_132 ) ;
if ( ! V_177 ) {
V_177 = F_144 ( & V_179 ,
F_117 ) ;
if ( V_177 )
F_145 ( & V_178 ) ;
}
return V_177 ;
}
static void T_10 F_146 ( void )
{
F_145 ( & V_179 ) ;
F_145 ( & V_178 ) ;
}
