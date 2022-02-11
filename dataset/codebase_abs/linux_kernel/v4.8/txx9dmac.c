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
static void F_52 ( struct V_1 * V_5 )
{
if ( F_14 ( V_5 ) )
F_45 ( F_20 ( & V_5 -> V_3 ) ,
L_6
L_7 ,
( V_8 ) F_5 ( V_5 ) ,
F_6 ( V_5 , V_48 ) ,
F_6 ( V_5 , V_49 ) ,
F_7 ( V_5 , V_50 ) ,
F_7 ( V_5 , V_51 ) ,
F_7 ( V_5 , V_52 ) ,
F_7 ( V_5 , V_53 ) ,
F_7 ( V_5 , V_54 ) ) ;
else
F_45 ( F_20 ( & V_5 -> V_3 ) ,
L_8
L_7 ,
F_15 ( V_5 , CHAR ) ,
F_15 ( V_5 , V_48 ) ,
F_15 ( V_5 , V_49 ) ,
F_15 ( V_5 , V_50 ) ,
F_15 ( V_5 , V_51 ) ,
F_15 ( V_5 , V_52 ) ,
F_15 ( V_5 , V_53 ) ,
F_15 ( V_5 , V_54 ) ) ;
}
static void F_53 ( struct V_1 * V_5 )
{
F_54 ( V_5 , V_53 , V_55 ) ;
if ( F_14 ( V_5 ) ) {
F_11 ( V_5 ) ;
F_55 ( V_5 , V_48 , 0 ) ;
F_55 ( V_5 , V_49 , 0 ) ;
} else {
F_54 ( V_5 , CHAR , 0 ) ;
F_54 ( V_5 , V_48 , 0 ) ;
F_54 ( V_5 , V_49 , 0 ) ;
}
F_54 ( V_5 , V_50 , 0 ) ;
F_54 ( V_5 , V_51 , 0 ) ;
F_54 ( V_5 , V_52 , 0 ) ;
F_54 ( V_5 , V_53 , 0 ) ;
F_56 () ;
}
static void F_57 ( struct V_1 * V_5 ,
struct V_21 * V_56 )
{
struct V_57 * V_58 = V_5 -> V_3 . V_59 ;
T_4 V_60 , V_61 ;
F_44 ( F_20 ( & V_5 -> V_3 ) , L_9 ,
V_56 -> V_23 . V_62 , V_56 ) ;
if ( F_58 ( V_5 , V_54 ) & V_63 ) {
F_45 ( F_20 ( & V_5 -> V_3 ) ,
L_10 ) ;
F_52 ( V_5 ) ;
return;
}
if ( F_14 ( V_5 ) ) {
F_10 ( V_5 , V_50 , 0 ) ;
F_10 ( V_5 , V_54 , 0xffffffff ) ;
if ( V_58 ) {
if ( V_58 -> V_64 ) {
V_60 = V_58 -> V_65 ;
V_61 = 0 ;
} else {
V_60 = 0 ;
V_61 = V_58 -> V_65 ;
}
} else {
V_60 = 8 ;
V_61 = 8 ;
}
F_10 ( V_5 , V_51 , V_60 ) ;
F_10 ( V_5 , V_52 , V_61 ) ;
F_10 ( V_5 , V_53 , V_5 -> V_66 ) ;
F_8 ( V_5 , V_56 -> V_23 . V_37 ) ;
} else {
F_17 ( V_5 , V_50 , 0 ) ;
F_17 ( V_5 , V_54 , 0xffffffff ) ;
if ( V_58 ) {
if ( V_58 -> V_64 ) {
V_60 = V_58 -> V_65 ;
V_61 = 0 ;
} else {
V_60 = 0 ;
V_61 = V_58 -> V_65 ;
}
} else {
V_60 = 4 ;
V_61 = 4 ;
}
F_17 ( V_5 , V_51 , V_60 ) ;
F_17 ( V_5 , V_52 , V_61 ) ;
if ( F_59 () ) {
F_17 ( V_5 , V_53 , V_5 -> V_66 ) ;
F_17 ( V_5 , CHAR , V_56 -> V_23 . V_37 ) ;
} else {
F_17 ( V_5 , CHAR , V_56 -> V_23 . V_37 ) ;
F_17 ( V_5 , V_53 , V_5 -> V_66 ) ;
}
}
}
static void
F_60 ( struct V_1 * V_5 ,
struct V_21 * V_24 )
{
T_5 V_67 ;
void * V_68 ;
struct V_22 * V_23 = & V_24 -> V_23 ;
F_44 ( F_20 ( & V_5 -> V_3 ) , L_11 ,
V_23 -> V_62 , V_24 ) ;
F_61 ( V_23 ) ;
V_67 = V_23 -> V_67 ;
V_68 = V_23 -> V_69 ;
F_46 ( V_5 , V_24 ) ;
F_50 ( & V_24 -> V_32 , & V_5 -> V_47 ) ;
F_62 ( & V_24 -> V_29 , & V_5 -> V_47 ) ;
F_63 ( V_23 ) ;
if ( V_67 )
V_67 ( V_68 ) ;
F_64 ( V_23 ) ;
}
static void F_65 ( struct V_1 * V_5 , struct V_70 * V_71 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_21 * V_24 ;
struct V_21 * V_30 = NULL ;
F_66 ( ! F_30 ( V_71 ) ) ;
do {
V_24 = F_28 ( V_5 ) ;
if ( V_30 ) {
F_24 ( V_5 , V_30 , V_24 -> V_23 . V_37 ) ;
F_67 ( F_21 ( & V_5 -> V_3 ) ,
V_30 -> V_23 . V_37 , V_15 -> V_38 ,
V_39 ) ;
}
V_30 = F_29 ( V_24 ) ;
F_68 ( & V_24 -> V_29 , V_71 ) ;
if ( ( V_24 -> V_23 . V_33 & V_72 ) &&
! F_69 ( V_5 ) )
break;
} while ( ! F_30 ( & V_5 -> V_31 ) );
}
static void F_70 ( struct V_1 * V_5 )
{
struct V_21 * V_24 , * V_40 ;
F_71 ( V_71 ) ;
F_50 ( & V_5 -> V_27 , & V_71 ) ;
if ( ! F_30 ( & V_5 -> V_31 ) ) {
F_65 ( V_5 , & V_5 -> V_27 ) ;
F_57 ( V_5 , F_25 ( V_5 ) ) ;
}
F_39 (desc, _desc, &list, desc_node)
F_60 ( V_5 , V_24 ) ;
}
static void F_72 ( struct V_1 * V_5 ,
struct V_73 * V_24 )
{
if ( F_14 ( V_5 ) ) {
#ifdef F_73
F_74 ( F_20 ( & V_5 -> V_3 ) ,
L_12 ,
( V_8 ) V_24 -> CHAR , V_24 -> V_48 , V_24 -> V_49 , V_24 -> V_50 ) ;
#else
F_74 ( F_20 ( & V_5 -> V_3 ) ,
L_13
L_14 ,
( V_8 ) V_24 -> CHAR , V_24 -> V_48 , V_24 -> V_49 , V_24 -> V_50 ,
V_24 -> V_51 , V_24 -> V_52 , V_24 -> V_53 , V_24 -> V_54 ) ;
#endif
} else {
struct V_74 * V_75 = (struct V_74 * ) V_24 ;
#ifdef F_73
F_74 ( F_20 ( & V_5 -> V_3 ) ,
L_15 ,
V_75 -> CHAR , V_75 -> V_48 , V_75 -> V_49 , V_75 -> V_50 ) ;
#else
F_74 ( F_20 ( & V_5 -> V_3 ) ,
L_16
L_14 ,
V_75 -> CHAR , V_75 -> V_48 , V_75 -> V_49 , V_75 -> V_50 ,
V_75 -> V_51 , V_75 -> V_52 , V_75 -> V_53 , V_75 -> V_54 ) ;
#endif
}
}
static void F_75 ( struct V_1 * V_5 , T_4 V_76 )
{
struct V_21 * V_77 ;
struct V_21 * V_46 ;
T_4 V_78 ;
F_74 ( F_20 ( & V_5 -> V_3 ) , L_17 ) ;
F_52 ( V_5 ) ;
V_77 = F_25 ( V_5 ) ;
F_76 ( & V_77 -> V_29 ) ;
V_78 = V_76 & ( V_79 |
V_80 | V_81 |
V_82 | V_83 ) ;
F_54 ( V_5 , V_54 , V_78 ) ;
if ( F_30 ( & V_5 -> V_27 ) && ! F_30 ( & V_5 -> V_31 ) )
F_65 ( V_5 , & V_5 -> V_27 ) ;
if ( ! F_30 ( & V_5 -> V_27 ) )
F_57 ( V_5 , F_25 ( V_5 ) ) ;
F_74 ( F_20 ( & V_5 -> V_3 ) ,
L_18 ,
V_77 -> V_23 . V_62 ) ;
F_72 ( V_5 , & V_77 -> V_25 ) ;
F_47 (child, &bad_desc->tx_list, desc_node)
F_72 ( V_5 , & V_46 -> V_25 ) ;
F_60 ( V_5 , V_77 ) ;
}
static void F_77 ( struct V_1 * V_5 )
{
T_2 V_84 ;
struct V_21 * V_24 , * V_40 ;
struct V_21 * V_46 ;
T_4 V_76 ;
if ( F_14 ( V_5 ) ) {
V_84 = F_5 ( V_5 ) ;
V_76 = F_7 ( V_5 , V_54 ) ;
F_10 ( V_5 , V_54 , V_76 ) ;
} else {
V_84 = F_15 ( V_5 , CHAR ) ;
V_76 = F_15 ( V_5 , V_54 ) ;
F_17 ( V_5 , V_54 , V_76 ) ;
}
if ( ! ( V_76 & ( V_63 | V_79 ) ) ) {
F_70 ( V_5 ) ;
return;
}
if ( ! ( V_76 & V_85 ) )
V_84 = 0 ;
F_44 ( F_20 ( & V_5 -> V_3 ) , L_19 ,
( V_8 ) V_84 ) ;
F_39 (desc, _desc, &dc->active_list, desc_node) {
if ( F_23 ( V_5 , V_24 ) == V_84 ) {
if ( V_76 & V_79 )
goto V_86;
return;
}
F_47 (child, &desc->tx_list, desc_node)
if ( F_23 ( V_5 , V_46 ) == V_84 ) {
if ( V_76 & V_79 )
goto V_86;
return;
}
F_60 ( V_5 , V_24 ) ;
}
V_86:
if ( V_76 & V_79 ) {
F_75 ( V_5 , V_76 ) ;
return;
}
F_45 ( F_20 ( & V_5 -> V_3 ) ,
L_20 ) ;
F_53 ( V_5 ) ;
if ( ! F_30 ( & V_5 -> V_31 ) ) {
F_65 ( V_5 , & V_5 -> V_27 ) ;
F_57 ( V_5 , F_25 ( V_5 ) ) ;
}
}
static void F_78 ( unsigned long V_87 )
{
int V_88 ;
T_4 V_76 ;
struct V_1 * V_5 ;
V_5 = (struct V_1 * ) V_87 ;
V_76 = F_58 ( V_5 , V_54 ) ;
F_44 ( F_20 ( & V_5 -> V_3 ) , L_21 , V_76 ) ;
F_79 ( & V_5 -> V_43 ) ;
if ( V_76 & ( V_79 | V_89 |
V_90 ) )
F_77 ( V_5 ) ;
F_80 ( & V_5 -> V_43 ) ;
V_88 = V_5 -> V_88 ;
F_81 ( V_88 ) ;
}
static T_6 F_82 ( int V_88 , void * V_91 )
{
struct V_1 * V_5 = V_91 ;
F_44 ( F_20 ( & V_5 -> V_3 ) , L_22 ,
F_58 ( V_5 , V_54 ) ) ;
F_83 ( & V_5 -> V_92 ) ;
F_84 ( V_88 ) ;
return V_93 ;
}
static void F_85 ( unsigned long V_87 )
{
int V_88 ;
T_4 V_76 ;
struct V_1 * V_5 ;
struct V_14 * V_15 = (struct V_14 * ) V_87 ;
T_4 V_94 ;
int V_42 ;
V_94 = F_86 ( V_15 , V_95 ) ;
F_44 ( V_15 -> V_3 [ 0 ] -> V_96 . V_19 , L_23 , V_94 ) ;
for ( V_42 = 0 ; V_42 < V_97 ; V_42 ++ ) {
if ( ( V_94 >> ( 24 + V_42 ) ) & 0x11 ) {
V_5 = V_15 -> V_3 [ V_42 ] ;
V_76 = F_58 ( V_5 , V_54 ) ;
F_44 ( F_20 ( & V_5 -> V_3 ) , L_21 ,
V_76 ) ;
F_79 ( & V_5 -> V_43 ) ;
if ( V_76 & ( V_79 | V_89 |
V_90 ) )
F_77 ( V_5 ) ;
F_80 ( & V_5 -> V_43 ) ;
}
}
V_88 = V_15 -> V_88 ;
F_81 ( V_88 ) ;
}
static T_6 F_87 ( int V_88 , void * V_91 )
{
struct V_14 * V_15 = V_91 ;
F_44 ( V_15 -> V_3 [ 0 ] -> V_96 . V_19 , L_22 ,
F_86 ( V_15 , V_95 ) ) ;
F_83 ( & V_15 -> V_92 ) ;
F_84 ( V_88 ) ;
return V_93 ;
}
static T_7 V_35 ( struct V_22 * V_98 )
{
struct V_21 * V_24 = F_22 ( V_98 ) ;
struct V_1 * V_5 = F_1 ( V_98 -> V_3 ) ;
T_7 V_62 ;
F_38 ( & V_5 -> V_43 ) ;
V_62 = F_88 ( V_98 ) ;
F_44 ( F_20 ( V_98 -> V_3 ) , L_24 ,
V_24 -> V_23 . V_62 , V_24 ) ;
F_89 ( & V_24 -> V_29 , & V_5 -> V_31 ) ;
F_43 ( & V_5 -> V_43 ) ;
return V_62 ;
}
static struct V_22 *
F_90 ( struct V_2 * V_3 , T_2 V_99 , T_2 V_100 ,
T_8 V_101 , unsigned long V_33 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_21 * V_24 ;
struct V_21 * V_56 ;
struct V_21 * V_30 ;
T_8 V_102 ;
T_8 V_103 ;
F_44 ( F_20 ( V_3 ) , L_25 ,
( V_8 ) V_99 , ( V_8 ) V_100 , V_101 , V_33 ) ;
if ( F_91 ( ! V_101 ) ) {
F_42 ( F_20 ( V_3 ) , L_26 ) ;
return NULL ;
}
V_30 = V_56 = NULL ;
for ( V_103 = 0 ; V_103 < V_101 ; V_103 += V_102 ) {
V_102 = F_92 ( T_8 , V_101 - V_103 , V_104 ) ;
if ( F_93 ( V_15 ) ) {
if ( V_102 > 0x100 &&
( V_102 & 0xff ) >= 0xfa &&
( V_102 & 0xff ) <= 0xff )
V_102 -= 0x20 ;
} else {
if ( V_102 > 0x80 &&
( V_102 & 0x7f ) >= 0x7e &&
( V_102 & 0x7f ) <= 0x7f )
V_102 -= 0x20 ;
}
V_24 = F_37 ( V_5 ) ;
if ( ! V_24 ) {
F_49 ( V_5 , V_56 ) ;
return NULL ;
}
if ( F_93 ( V_15 ) ) {
V_24 -> V_25 . V_48 = V_100 + V_103 ;
V_24 -> V_25 . V_49 = V_99 + V_103 ;
V_24 -> V_25 . V_50 = V_102 ;
F_94 ( V_15 , V_24 , 8 , 8 ,
V_5 -> V_66 | V_105 ) ;
} else {
V_24 -> V_26 . V_48 = V_100 + V_103 ;
V_24 -> V_26 . V_49 = V_99 + V_103 ;
V_24 -> V_26 . V_50 = V_102 ;
F_94 ( V_15 , V_24 , 4 , 4 ,
V_5 -> V_66 | V_105 ) ;
}
if ( ! V_56 ) {
V_56 = V_24 ;
} else {
F_24 ( V_5 , V_30 , V_24 -> V_23 . V_37 ) ;
F_67 ( F_21 ( & V_5 -> V_3 ) ,
V_30 -> V_23 . V_37 , V_15 -> V_38 ,
V_39 ) ;
F_89 ( & V_24 -> V_29 , & V_56 -> V_32 ) ;
}
V_30 = V_24 ;
}
if ( V_33 & V_72 )
F_95 ( V_15 , V_30 ) ;
F_24 ( V_5 , V_30 , 0 ) ;
F_67 ( F_21 ( & V_5 -> V_3 ) ,
V_30 -> V_23 . V_37 , V_15 -> V_38 ,
V_39 ) ;
V_56 -> V_23 . V_33 = V_33 ;
V_56 -> V_101 = V_101 ;
return & V_56 -> V_23 ;
}
static struct V_22 *
F_96 ( struct V_2 * V_3 , struct V_106 * V_107 ,
unsigned int V_108 , enum V_109 V_110 ,
unsigned long V_33 , void * V_111 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_57 * V_58 = V_3 -> V_59 ;
struct V_21 * V_30 ;
struct V_21 * V_56 ;
unsigned int V_42 ;
struct V_106 * V_112 ;
F_44 ( F_20 ( V_3 ) , L_27 ) ;
F_66 ( ! V_58 || ! V_58 -> V_65 ) ;
if ( V_58 -> V_64 )
F_66 ( V_110 != V_113 ) ;
else
F_66 ( V_110 != V_114 ) ;
if ( F_91 ( ! V_108 ) )
return NULL ;
V_30 = V_56 = NULL ;
F_97 (sgl, sg, sg_len, i) {
struct V_21 * V_24 ;
T_2 V_115 ;
T_4 V_60 , V_61 ;
V_24 = F_37 ( V_5 ) ;
if ( ! V_24 ) {
F_49 ( V_5 , V_56 ) ;
return NULL ;
}
V_115 = F_98 ( V_112 ) ;
if ( F_93 ( V_15 ) ) {
if ( V_110 == V_113 ) {
V_24 -> V_25 . V_48 = V_115 ;
V_24 -> V_25 . V_49 = V_58 -> V_64 ;
} else {
V_24 -> V_25 . V_48 = V_58 -> V_116 ;
V_24 -> V_25 . V_49 = V_115 ;
}
V_24 -> V_25 . V_50 = F_99 ( V_112 ) ;
} else {
if ( V_110 == V_113 ) {
V_24 -> V_26 . V_48 = V_115 ;
V_24 -> V_26 . V_49 = V_58 -> V_64 ;
} else {
V_24 -> V_26 . V_48 = V_58 -> V_116 ;
V_24 -> V_26 . V_49 = V_115 ;
}
V_24 -> V_26 . V_50 = F_99 ( V_112 ) ;
}
if ( V_110 == V_113 ) {
V_60 = V_58 -> V_65 ;
V_61 = 0 ;
} else {
V_60 = 0 ;
V_61 = V_58 -> V_65 ;
}
F_94 ( V_15 , V_24 , V_60 , V_61 ,
V_5 -> V_66 | V_105 ) ;
if ( ! V_56 ) {
V_56 = V_24 ;
} else {
F_24 ( V_5 , V_30 , V_24 -> V_23 . V_37 ) ;
F_67 ( F_21 ( & V_5 -> V_3 ) ,
V_30 -> V_23 . V_37 ,
V_15 -> V_38 ,
V_39 ) ;
F_89 ( & V_24 -> V_29 , & V_56 -> V_32 ) ;
}
V_30 = V_24 ;
}
if ( V_33 & V_72 )
F_95 ( V_15 , V_30 ) ;
F_24 ( V_5 , V_30 , 0 ) ;
F_67 ( F_21 ( & V_5 -> V_3 ) ,
V_30 -> V_23 . V_37 , V_15 -> V_38 ,
V_39 ) ;
V_56 -> V_23 . V_33 = V_33 ;
V_56 -> V_101 = 0 ;
return & V_56 -> V_23 ;
}
static int F_100 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_21 * V_24 , * V_40 ;
F_71 ( V_71 ) ;
F_44 ( F_20 ( V_3 ) , L_28 ) ;
F_38 ( & V_5 -> V_43 ) ;
F_53 ( V_5 ) ;
F_50 ( & V_5 -> V_31 , & V_71 ) ;
F_50 ( & V_5 -> V_27 , & V_71 ) ;
F_43 ( & V_5 -> V_43 ) ;
F_39 (desc, _desc, &list, desc_node)
F_60 ( V_5 , V_24 ) ;
return 0 ;
}
static enum V_117
F_101 ( struct V_2 * V_3 , T_7 V_62 ,
struct V_118 * V_119 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
enum V_117 V_41 ;
V_41 = F_102 ( V_3 , V_62 , V_119 ) ;
if ( V_41 == V_120 )
return V_120 ;
F_38 ( & V_5 -> V_43 ) ;
F_77 ( V_5 ) ;
F_43 ( & V_5 -> V_43 ) ;
return F_102 ( V_3 , V_62 , V_119 ) ;
}
static void F_103 ( struct V_1 * V_5 ,
struct V_21 * V_30 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_21 * V_24 ;
F_71 ( V_71 ) ;
V_30 = F_29 ( V_30 ) ;
F_65 ( V_5 , & V_71 ) ;
V_24 = F_26 ( V_71 . V_28 , struct V_21 , V_29 ) ;
F_24 ( V_5 , V_30 , V_24 -> V_23 . V_37 ) ;
F_67 ( F_21 ( & V_5 -> V_3 ) ,
V_30 -> V_23 . V_37 , V_15 -> V_38 ,
V_39 ) ;
F_56 () ;
if ( ! ( F_58 ( V_5 , V_54 ) & V_85 ) &&
F_13 ( V_5 ) == V_30 -> V_23 . V_37 )
F_16 ( V_5 , V_24 -> V_23 . V_37 ) ;
F_104 ( & V_71 , & V_5 -> V_27 ) ;
}
static void F_105 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_38 ( & V_5 -> V_43 ) ;
if ( ! F_30 ( & V_5 -> V_27 ) )
F_77 ( V_5 ) ;
if ( ! F_30 ( & V_5 -> V_31 ) ) {
if ( F_30 ( & V_5 -> V_27 ) ) {
F_65 ( V_5 , & V_5 -> V_27 ) ;
F_57 ( V_5 , F_25 ( V_5 ) ) ;
} else if ( F_59 () ) {
struct V_21 * V_30 = F_27 ( V_5 ) ;
if ( ! ( V_30 -> V_23 . V_33 & V_72 ) ||
F_69 ( V_5 ) )
F_103 ( V_5 , V_30 ) ;
}
}
F_43 ( & V_5 -> V_43 ) ;
}
static int F_106 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_57 * V_58 = V_3 -> V_59 ;
struct V_21 * V_24 ;
int V_42 ;
F_44 ( F_20 ( V_3 ) , L_29 ) ;
if ( F_58 ( V_5 , V_54 ) & V_63 ) {
F_42 ( F_20 ( V_3 ) , L_30 ) ;
return - V_121 ;
}
F_107 ( V_3 ) ;
V_5 -> V_66 = V_122 | V_123 | V_124 ;
F_108 ( V_5 ) ;
if ( ! F_59 () || ( V_5 -> V_66 & V_125 ) )
V_5 -> V_66 |= V_126 ;
if ( V_3 -> V_18 -> V_127 ) {
if ( V_58 )
return - V_128 ;
V_5 -> V_66 |= V_129 ;
} else {
if ( ! V_58 ||
( V_58 -> V_64 && V_58 -> V_116 ) || ( ! V_58 -> V_64 && ! V_58 -> V_116 ) )
return - V_128 ;
V_5 -> V_66 |= V_130 |
F_109 ( F_110 ( V_58 -> V_65 ) ) ;
F_111 ( V_5 ) ;
}
F_38 ( & V_5 -> V_43 ) ;
V_42 = V_5 -> V_45 ;
while ( V_5 -> V_45 < V_131 ) {
F_43 ( & V_5 -> V_43 ) ;
V_24 = F_32 ( V_5 , V_132 ) ;
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
F_71 ( V_71 ) ;
F_42 ( F_20 ( V_3 ) , L_33 ,
V_5 -> V_45 ) ;
F_66 ( ! F_30 ( & V_5 -> V_27 ) ) ;
F_66 ( ! F_30 ( & V_5 -> V_31 ) ) ;
F_66 ( F_58 ( V_5 , V_54 ) & V_63 ) ;
F_38 ( & V_5 -> V_43 ) ;
F_50 ( & V_5 -> V_47 , & V_71 ) ;
V_5 -> V_45 = 0 ;
F_43 ( & V_5 -> V_43 ) ;
F_39 (desc, _desc, &list, desc_node) {
F_44 ( F_20 ( V_3 ) , L_34 , V_24 ) ;
F_114 ( F_21 ( V_3 ) , V_24 -> V_23 . V_37 ,
V_15 -> V_38 , V_39 ) ;
F_115 ( V_24 ) ;
}
F_44 ( F_20 ( V_3 ) , L_35 ) ;
}
static void F_116 ( struct V_14 * V_15 )
{
F_117 ( V_15 , V_95 , 0 ) ;
F_56 () ;
}
static int T_9 F_118 ( struct V_133 * V_134 )
{
struct V_135 * V_136 =
F_119 ( & V_134 -> V_19 ) ;
struct V_133 * V_137 = V_136 -> V_137 ;
struct V_138 * V_139 = F_119 ( & V_137 -> V_19 ) ;
struct V_1 * V_5 ;
int V_140 ;
int V_141 = V_134 -> V_142 % V_97 ;
int V_88 ;
V_5 = F_120 ( & V_134 -> V_19 , sizeof( * V_5 ) , V_132 ) ;
if ( ! V_5 )
return - V_143 ;
V_5 -> V_96 . V_19 = & V_134 -> V_19 ;
V_5 -> V_96 . V_144 = F_106 ;
V_5 -> V_96 . V_145 = F_113 ;
V_5 -> V_96 . V_146 = F_100 ;
V_5 -> V_96 . V_147 = F_101 ;
V_5 -> V_96 . V_148 = F_105 ;
if ( V_139 && V_139 -> V_149 == V_141 ) {
V_5 -> V_96 . V_127 = F_90 ;
F_121 ( V_150 , V_5 -> V_96 . V_151 ) ;
} else {
V_5 -> V_96 . V_152 = F_96 ;
F_121 ( V_153 , V_5 -> V_96 . V_151 ) ;
F_121 ( V_154 , V_5 -> V_96 . V_151 ) ;
}
F_34 ( & V_5 -> V_96 . V_155 ) ;
V_5 -> V_15 = F_122 ( V_137 ) ;
if ( V_5 -> V_15 -> V_88 < 0 ) {
V_88 = F_123 ( V_134 , 0 ) ;
if ( V_88 < 0 )
return V_88 ;
F_124 ( & V_5 -> V_92 , F_78 ,
( unsigned long ) V_5 ) ;
V_5 -> V_88 = V_88 ;
V_140 = F_125 ( & V_134 -> V_19 , V_5 -> V_88 ,
F_82 , 0 , F_126 ( & V_134 -> V_19 ) , V_5 ) ;
if ( V_140 )
return V_140 ;
} else
V_5 -> V_88 = - 1 ;
V_5 -> V_15 -> V_3 [ V_141 ] = V_5 ;
V_5 -> V_3 . V_18 = & V_5 -> V_96 ;
F_89 ( & V_5 -> V_3 . V_156 , & V_5 -> V_3 . V_18 -> V_155 ) ;
F_107 ( & V_5 -> V_3 ) ;
if ( F_14 ( V_5 ) )
V_5 -> V_6 = & F_18 ( V_5 -> V_15 ) -> V_157 [ V_141 ] ;
else
V_5 -> V_6 = & F_19 ( V_5 -> V_15 ) -> V_157 [ V_141 ] ;
F_127 ( & V_5 -> V_43 ) ;
F_34 ( & V_5 -> V_27 ) ;
F_34 ( & V_5 -> V_31 ) ;
F_34 ( & V_5 -> V_47 ) ;
F_53 ( V_5 ) ;
F_128 ( V_134 , V_5 ) ;
V_140 = F_129 ( & V_5 -> V_96 ) ;
if ( V_140 )
return V_140 ;
F_42 ( & V_134 -> V_19 , L_36 ,
V_5 -> V_96 . V_91 ,
F_130 ( V_150 , V_5 -> V_96 . V_151 ) ? L_37 : L_38 ,
F_130 ( V_153 , V_5 -> V_96 . V_151 ) ? L_39 : L_38 ) ;
return 0 ;
}
static int F_131 ( struct V_133 * V_134 )
{
struct V_1 * V_5 = F_122 ( V_134 ) ;
F_132 ( & V_5 -> V_96 ) ;
if ( V_5 -> V_88 >= 0 ) {
F_133 ( & V_134 -> V_19 , V_5 -> V_88 , V_5 ) ;
F_134 ( & V_5 -> V_92 ) ;
}
V_5 -> V_15 -> V_3 [ V_134 -> V_142 % V_97 ] = NULL ;
return 0 ;
}
static int T_9 F_135 ( struct V_133 * V_134 )
{
struct V_138 * V_139 = F_119 ( & V_134 -> V_19 ) ;
struct V_158 * V_159 ;
struct V_14 * V_15 ;
T_4 V_94 ;
int V_140 ;
V_159 = F_136 ( V_134 , V_160 , 0 ) ;
if ( ! V_159 )
return - V_128 ;
V_15 = F_120 ( & V_134 -> V_19 , sizeof( * V_15 ) , V_132 ) ;
if ( ! V_15 )
return - V_143 ;
if ( ! F_137 ( & V_134 -> V_19 , V_159 -> V_161 , F_138 ( V_159 ) ,
F_126 ( & V_134 -> V_19 ) ) )
return - V_162 ;
V_15 -> V_16 = F_139 ( & V_134 -> V_19 , V_159 -> V_161 , F_138 ( V_159 ) ) ;
if ( ! V_15 -> V_16 )
return - V_143 ;
V_15 -> V_163 = V_139 -> V_163 ;
if ( F_93 ( V_15 ) )
V_15 -> V_38 = sizeof( struct V_73 ) ;
else
V_15 -> V_38 = sizeof( struct V_74 ) ;
F_116 ( V_15 ) ;
V_15 -> V_88 = F_123 ( V_134 , 0 ) ;
if ( V_15 -> V_88 >= 0 ) {
F_124 ( & V_15 -> V_92 , F_85 ,
( unsigned long ) V_15 ) ;
V_140 = F_125 ( & V_134 -> V_19 , V_15 -> V_88 ,
F_87 , 0 , F_126 ( & V_134 -> V_19 ) , V_15 ) ;
if ( V_140 )
return V_140 ;
}
V_94 = V_164 | V_165 ;
if ( V_139 && V_139 -> V_149 >= 0 )
V_94 |= F_140 ( V_139 -> V_149 ) ;
F_117 ( V_15 , V_95 , V_94 ) ;
F_128 ( V_134 , V_15 ) ;
return 0 ;
}
static int F_141 ( struct V_133 * V_134 )
{
struct V_14 * V_15 = F_122 ( V_134 ) ;
F_116 ( V_15 ) ;
if ( V_15 -> V_88 >= 0 ) {
F_133 ( & V_134 -> V_19 , V_15 -> V_88 , V_15 ) ;
F_134 ( & V_15 -> V_92 ) ;
}
return 0 ;
}
static void F_142 ( struct V_133 * V_134 )
{
struct V_14 * V_15 = F_122 ( V_134 ) ;
F_116 ( V_15 ) ;
}
static int F_143 ( struct V_18 * V_19 )
{
struct V_133 * V_134 = F_144 ( V_19 ) ;
struct V_14 * V_15 = F_122 ( V_134 ) ;
F_116 ( V_15 ) ;
return 0 ;
}
static int F_145 ( struct V_18 * V_19 )
{
struct V_133 * V_134 = F_144 ( V_19 ) ;
struct V_14 * V_15 = F_122 ( V_134 ) ;
struct V_138 * V_139 = F_119 ( & V_134 -> V_19 ) ;
T_4 V_94 ;
V_94 = V_164 | V_165 ;
if ( V_139 && V_139 -> V_149 >= 0 )
V_94 |= F_140 ( V_139 -> V_149 ) ;
F_117 ( V_15 , V_95 , V_94 ) ;
return 0 ;
}
static int T_9 F_146 ( void )
{
int V_166 ;
V_166 = F_147 ( & V_167 , F_135 ) ;
if ( ! V_166 ) {
V_166 = F_147 ( & V_168 ,
F_118 ) ;
if ( V_166 )
F_148 ( & V_167 ) ;
}
return V_166 ;
}
static void T_10 F_149 ( void )
{
F_148 ( & V_168 ) ;
F_148 ( & V_167 ) ;
}
