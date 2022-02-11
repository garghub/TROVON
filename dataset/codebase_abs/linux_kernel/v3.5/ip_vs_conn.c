static inline void F_1 ( unsigned int V_1 )
{
F_2 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static inline void F_3 ( unsigned int V_1 )
{
F_4 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static inline void F_5 ( unsigned int V_1 )
{
F_6 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static inline void F_7 ( unsigned int V_1 )
{
F_8 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static inline void F_9 ( unsigned int V_1 )
{
F_10 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static inline void F_11 ( unsigned int V_1 )
{
F_12 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static inline void F_13 ( unsigned int V_1 )
{
F_14 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static inline void F_15 ( unsigned int V_1 )
{
F_16 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static unsigned int F_17 ( struct V_5 * V_5 , int V_6 , unsigned int V_7 ,
const union V_8 * V_9 ,
T_1 V_10 )
{
#ifdef F_18
if ( V_6 == V_11 )
return ( F_19 ( F_20 ( V_9 , 16 , V_12 ) ,
( V_13 V_14 ) V_10 , V_7 , V_12 ) ^
( ( V_15 ) V_5 >> 8 ) ) & V_16 ;
#endif
return ( F_19 ( ( V_13 V_14 ) V_9 -> V_17 , ( V_13 V_14 ) V_10 , V_7 ,
V_12 ) ^
( ( V_15 ) V_5 >> 8 ) ) & V_16 ;
}
static unsigned int F_21 ( const struct V_18 * V_19 ,
bool V_20 )
{
const union V_8 * V_9 ;
T_1 V_10 ;
if ( V_19 -> V_21 && V_19 -> V_22 -> V_23 )
return V_19 -> V_22 -> V_23 ( V_19 , V_12 , V_20 ) &
V_16 ;
if ( F_22 ( ! V_20 ) ) {
V_9 = V_19 -> V_24 ;
V_10 = V_19 -> V_25 ;
} else {
V_9 = V_19 -> V_26 ;
V_10 = V_19 -> V_27 ;
}
return F_17 ( V_19 -> V_5 , V_19 -> V_6 , V_19 -> V_28 , V_9 , V_10 ) ;
}
static unsigned int F_23 ( const struct V_29 * V_30 )
{
struct V_18 V_19 ;
F_24 ( F_25 ( V_30 ) , V_30 -> V_6 , V_30 -> V_28 ,
& V_30 -> V_24 , V_30 -> V_25 , NULL , 0 , & V_19 ) ;
if ( V_30 -> V_22 ) {
V_19 . V_22 = V_30 -> V_22 ;
V_19 . V_21 = V_30 -> V_21 ;
V_19 . V_31 = V_30 -> V_31 ;
}
return F_21 ( & V_19 , false ) ;
}
static inline int F_26 ( struct V_29 * V_30 )
{
unsigned int V_32 ;
int V_33 ;
if ( V_30 -> V_34 & V_35 )
return 0 ;
V_32 = F_23 ( V_30 ) ;
F_5 ( V_32 ) ;
F_27 ( & V_30 -> V_36 ) ;
if ( ! ( V_30 -> V_34 & V_37 ) ) {
F_28 ( & V_30 -> V_38 , & V_39 [ V_32 ] ) ;
V_30 -> V_34 |= V_37 ;
F_29 ( & V_30 -> V_40 ) ;
V_33 = 1 ;
} else {
F_30 ( L_1 ,
V_41 , F_31 ( 0 ) ) ;
V_33 = 0 ;
}
F_32 ( & V_30 -> V_36 ) ;
F_7 ( V_32 ) ;
return V_33 ;
}
static inline int F_33 ( struct V_29 * V_30 )
{
unsigned int V_32 ;
int V_33 ;
V_32 = F_23 ( V_30 ) ;
F_5 ( V_32 ) ;
F_27 ( & V_30 -> V_36 ) ;
if ( V_30 -> V_34 & V_37 ) {
F_34 ( & V_30 -> V_38 ) ;
V_30 -> V_34 &= ~ V_37 ;
F_35 ( & V_30 -> V_40 ) ;
V_33 = 1 ;
} else
V_33 = 0 ;
F_32 ( & V_30 -> V_36 ) ;
F_7 ( V_32 ) ;
return V_33 ;
}
static inline struct V_29 *
F_36 ( const struct V_18 * V_19 )
{
unsigned int V_32 ;
struct V_29 * V_30 ;
struct V_42 * V_43 ;
V_32 = F_21 ( V_19 , false ) ;
F_1 ( V_32 ) ;
F_37 (cp, n, &ip_vs_conn_tab[hash], c_list) {
if ( V_30 -> V_6 == V_19 -> V_6 &&
V_19 -> V_25 == V_30 -> V_25 && V_19 -> V_27 == V_30 -> V_27 &&
F_38 ( V_19 -> V_6 , V_19 -> V_24 , & V_30 -> V_24 ) &&
F_38 ( V_19 -> V_6 , V_19 -> V_26 , & V_30 -> V_26 ) &&
( ( ! V_19 -> V_25 ) ^ ( ! ( V_30 -> V_34 & V_44 ) ) ) &&
V_19 -> V_28 == V_30 -> V_28 &&
F_39 ( V_30 , V_19 -> V_5 ) ) {
F_29 ( & V_30 -> V_40 ) ;
F_3 ( V_32 ) ;
return V_30 ;
}
}
F_3 ( V_32 ) ;
return NULL ;
}
struct V_29 * F_40 ( const struct V_18 * V_19 )
{
struct V_29 * V_30 ;
V_30 = F_36 ( V_19 ) ;
if ( ! V_30 && F_41 ( & V_45 ) ) {
struct V_18 V_46 = * V_19 ;
V_46 . V_25 = 0 ;
V_30 = F_36 ( & V_46 ) ;
}
F_42 ( 9 , L_2 ,
F_43 ( V_19 -> V_28 ) ,
F_44 ( V_19 -> V_6 , V_19 -> V_24 ) , F_45 ( V_19 -> V_25 ) ,
F_44 ( V_19 -> V_6 , V_19 -> V_26 ) , F_45 ( V_19 -> V_27 ) ,
V_30 ? L_3 : L_4 ) ;
return V_30 ;
}
static int
F_46 ( int V_6 , const struct V_47 * V_48 ,
const struct V_49 * V_50 ,
unsigned int V_51 , int V_20 ,
struct V_18 * V_19 )
{
T_1 V_52 [ 2 ] , * V_53 ;
struct V_5 * V_5 = F_47 ( V_48 ) ;
V_53 = F_48 ( V_48 , V_51 , sizeof( V_52 ) , V_52 ) ;
if ( V_53 == NULL )
return 1 ;
if ( F_22 ( ! V_20 ) )
F_24 ( V_5 , V_6 , V_50 -> V_28 , & V_50 -> V_54 ,
V_53 [ 0 ] , & V_50 -> V_55 , V_53 [ 1 ] , V_19 ) ;
else
F_24 ( V_5 , V_6 , V_50 -> V_28 , & V_50 -> V_55 ,
V_53 [ 1 ] , & V_50 -> V_54 , V_53 [ 0 ] , V_19 ) ;
return 0 ;
}
struct V_29 *
F_49 ( int V_6 , const struct V_47 * V_48 ,
const struct V_49 * V_50 ,
unsigned int V_51 , int V_20 )
{
struct V_18 V_19 ;
if ( F_46 ( V_6 , V_48 , V_50 , V_51 , V_20 , & V_19 ) )
return NULL ;
return F_40 ( & V_19 ) ;
}
struct V_29 * F_50 ( const struct V_18 * V_19 )
{
unsigned int V_32 ;
struct V_29 * V_30 ;
struct V_42 * V_43 ;
V_32 = F_21 ( V_19 , false ) ;
F_1 ( V_32 ) ;
F_37 (cp, n, &ip_vs_conn_tab[hash], c_list) {
if ( ! F_39 ( V_30 , V_19 -> V_5 ) )
continue;
if ( V_19 -> V_21 && V_19 -> V_22 -> V_56 ) {
if ( V_19 -> V_22 == V_30 -> V_22 && V_19 -> V_22 -> V_56 ( V_19 , V_30 ) )
goto V_57;
continue;
}
if ( V_30 -> V_6 == V_19 -> V_6 &&
F_38 ( V_19 -> V_6 , V_19 -> V_24 , & V_30 -> V_24 ) &&
F_38 ( V_19 -> V_28 == V_58 ? V_59 :
V_19 -> V_6 , V_19 -> V_26 , & V_30 -> V_26 ) &&
V_19 -> V_25 == V_30 -> V_25 && V_19 -> V_27 == V_30 -> V_27 &&
V_30 -> V_34 & V_60 &&
V_19 -> V_28 == V_30 -> V_28 )
goto V_57;
}
V_30 = NULL ;
V_57:
if ( V_30 )
F_29 ( & V_30 -> V_40 ) ;
F_3 ( V_32 ) ;
F_42 ( 9 , L_5 ,
F_43 ( V_19 -> V_28 ) ,
F_44 ( V_19 -> V_6 , V_19 -> V_24 ) , F_45 ( V_19 -> V_25 ) ,
F_44 ( V_19 -> V_6 , V_19 -> V_26 ) , F_45 ( V_19 -> V_27 ) ,
V_30 ? L_3 : L_4 ) ;
return V_30 ;
}
struct V_29 * F_51 ( const struct V_18 * V_19 )
{
unsigned int V_32 ;
struct V_29 * V_30 , * V_33 = NULL ;
struct V_42 * V_43 ;
V_32 = F_21 ( V_19 , true ) ;
F_1 ( V_32 ) ;
F_37 (cp, n, &ip_vs_conn_tab[hash], c_list) {
if ( V_30 -> V_6 == V_19 -> V_6 &&
V_19 -> V_27 == V_30 -> V_25 && V_19 -> V_25 == V_30 -> V_61 &&
F_38 ( V_19 -> V_6 , V_19 -> V_26 , & V_30 -> V_24 ) &&
F_38 ( V_19 -> V_6 , V_19 -> V_24 , & V_30 -> V_55 ) &&
V_19 -> V_28 == V_30 -> V_28 &&
F_39 ( V_30 , V_19 -> V_5 ) ) {
F_29 ( & V_30 -> V_40 ) ;
V_33 = V_30 ;
break;
}
}
F_3 ( V_32 ) ;
F_42 ( 9 , L_6 ,
F_43 ( V_19 -> V_28 ) ,
F_44 ( V_19 -> V_6 , V_19 -> V_24 ) , F_45 ( V_19 -> V_25 ) ,
F_44 ( V_19 -> V_6 , V_19 -> V_26 ) , F_45 ( V_19 -> V_27 ) ,
V_33 ? L_3 : L_4 ) ;
return V_33 ;
}
struct V_29 *
F_52 ( int V_6 , const struct V_47 * V_48 ,
const struct V_49 * V_50 ,
unsigned int V_51 , int V_20 )
{
struct V_18 V_19 ;
if ( F_46 ( V_6 , V_48 , V_50 , V_51 , V_20 , & V_19 ) )
return NULL ;
return F_51 ( & V_19 ) ;
}
void F_53 ( struct V_29 * V_30 )
{
unsigned long V_62 = ( V_30 -> V_34 & V_35 ) ?
0 : V_30 -> V_63 ;
F_54 ( & V_30 -> V_64 , V_65 + V_62 ) ;
F_55 ( V_30 ) ;
}
void F_56 ( struct V_29 * V_30 , T_1 V_25 )
{
if ( F_33 ( V_30 ) ) {
F_27 ( & V_30 -> V_36 ) ;
if ( V_30 -> V_34 & V_44 ) {
F_35 ( & V_45 ) ;
V_30 -> V_34 &= ~ V_44 ;
V_30 -> V_25 = V_25 ;
}
F_32 ( & V_30 -> V_36 ) ;
F_26 ( V_30 ) ;
}
}
static inline void F_57 ( struct V_29 * V_30 )
{
switch ( F_58 ( V_30 ) ) {
case V_66 :
V_30 -> V_67 = V_68 ;
break;
case V_69 :
V_30 -> V_67 = V_70 ;
break;
case V_71 :
V_30 -> V_67 = V_72 ;
break;
case V_73 :
V_30 -> V_67 = V_74 ;
break;
case V_75 :
V_30 -> V_67 = V_76 ;
break;
}
}
static inline void F_59 ( struct V_29 * V_30 )
{
switch ( F_58 ( V_30 ) ) {
case V_66 :
V_30 -> V_67 = V_77 ;
break;
case V_69 :
V_30 -> V_67 = V_78 ;
break;
case V_71 :
V_30 -> V_67 = V_79 ;
break;
case V_73 :
V_30 -> V_67 = V_74 ;
break;
case V_75 :
V_30 -> V_67 = V_80 ;
break;
}
}
static inline int F_60 ( struct V_81 * V_82 )
{
return F_41 ( & V_82 -> V_83 )
+ F_41 ( & V_82 -> V_84 ) ;
}
static inline void
F_61 ( struct V_29 * V_30 , struct V_81 * V_82 )
{
unsigned int V_85 ;
T_2 V_34 ;
if ( ! V_82 )
return;
F_29 ( & V_82 -> V_40 ) ;
V_85 = F_41 ( & V_82 -> V_85 ) ;
if ( V_30 -> V_28 != V_86 )
V_85 &= ~ V_35 ;
V_34 = V_30 -> V_34 ;
if ( V_34 & V_87 ) {
if ( ! ( V_34 & V_60 ) )
V_85 &= ~ V_88 ;
V_34 &= ~ ( V_89 | V_90 ) ;
}
V_34 |= V_85 ;
V_30 -> V_34 = V_34 ;
V_30 -> V_82 = V_82 ;
F_42 ( 7 , L_7
L_8
L_9 ,
F_43 ( V_30 -> V_28 ) ,
F_44 ( V_30 -> V_6 , & V_30 -> V_24 ) , F_45 ( V_30 -> V_25 ) ,
F_44 ( V_30 -> V_6 , & V_30 -> V_26 ) , F_45 ( V_30 -> V_27 ) ,
F_44 ( V_30 -> V_6 , & V_30 -> V_55 ) , F_45 ( V_30 -> V_61 ) ,
F_62 ( V_30 ) , V_30 -> V_91 ,
V_30 -> V_34 , F_41 ( & V_30 -> V_40 ) ,
F_41 ( & V_82 -> V_40 ) ) ;
if ( ! ( V_34 & V_60 ) ) {
if ( ! ( V_34 & V_88 ) )
F_29 ( & V_82 -> V_83 ) ;
else
F_29 ( & V_82 -> V_84 ) ;
} else {
F_29 ( & V_82 -> V_92 ) ;
}
if ( V_82 -> V_93 != 0 &&
F_60 ( V_82 ) >= V_82 -> V_93 )
V_82 -> V_34 |= V_94 ;
}
struct V_81 * F_63 ( struct V_29 * V_30 )
{
struct V_81 * V_82 ;
V_82 = F_64 ( F_25 ( V_30 ) , V_30 -> V_6 , & V_30 -> V_55 ,
V_30 -> V_61 , & V_30 -> V_26 , V_30 -> V_27 ,
V_30 -> V_28 , V_30 -> V_95 , V_30 -> V_34 ) ;
if ( V_82 ) {
struct V_96 * V_97 ;
F_27 ( & V_30 -> V_36 ) ;
if ( V_30 -> V_82 ) {
F_32 ( & V_30 -> V_36 ) ;
return V_82 ;
}
if ( V_30 -> V_98 )
F_65 ( V_30 ) ;
F_61 ( V_30 , V_82 ) ;
F_32 ( & V_30 -> V_36 ) ;
V_30 -> V_67 = NULL ;
#ifdef F_18
if ( V_30 -> V_6 == V_11 )
F_59 ( V_30 ) ;
else
#endif
F_57 ( V_30 ) ;
V_97 = F_66 ( F_25 ( V_30 ) , V_30 -> V_28 ) ;
if ( V_97 && F_41 ( & V_97 -> V_99 ) )
F_67 ( V_30 , V_97 -> V_100 ) ;
}
return V_82 ;
}
static inline void F_68 ( struct V_29 * V_30 )
{
struct V_81 * V_82 = V_30 -> V_82 ;
if ( ! V_82 )
return;
F_42 ( 7 , L_10
L_8
L_9 ,
F_43 ( V_30 -> V_28 ) ,
F_44 ( V_30 -> V_6 , & V_30 -> V_24 ) , F_45 ( V_30 -> V_25 ) ,
F_44 ( V_30 -> V_6 , & V_30 -> V_26 ) , F_45 ( V_30 -> V_27 ) ,
F_44 ( V_30 -> V_6 , & V_30 -> V_55 ) , F_45 ( V_30 -> V_61 ) ,
F_62 ( V_30 ) , V_30 -> V_91 ,
V_30 -> V_34 , F_41 ( & V_30 -> V_40 ) ,
F_41 ( & V_82 -> V_40 ) ) ;
if ( ! ( V_30 -> V_34 & V_60 ) ) {
if ( V_30 -> V_34 & V_88 ) {
F_35 ( & V_82 -> V_84 ) ;
} else {
F_35 ( & V_82 -> V_83 ) ;
}
} else {
F_35 ( & V_82 -> V_92 ) ;
}
if ( V_82 -> V_101 != 0 ) {
if ( F_60 ( V_82 ) < V_82 -> V_101 )
V_82 -> V_34 &= ~ V_94 ;
} else if ( V_82 -> V_93 != 0 ) {
if ( F_60 ( V_82 ) * 4 < V_82 -> V_93 * 3 )
V_82 -> V_34 &= ~ V_94 ;
} else {
if ( V_82 -> V_34 & V_94 )
V_82 -> V_34 &= ~ V_94 ;
}
F_35 ( & V_82 -> V_40 ) ;
}
static int F_69 ( struct V_102 * V_103 ,
struct V_81 * V_82 )
{
#ifdef F_70
return V_103 -> V_104 &&
( F_41 ( & V_82 -> V_105 ) == 0 ) ;
#else
return 0 ;
#endif
}
int F_71 ( struct V_29 * V_106 )
{
struct V_81 * V_82 = V_106 -> V_82 ;
struct V_102 * V_103 = F_72 ( F_25 ( V_106 ) ) ;
if ( ( V_82 == NULL ) ||
! ( V_82 -> V_34 & V_107 ) ||
F_69 ( V_103 , V_82 ) ) {
F_42 ( 9 , L_11
L_12
L_13 ,
F_43 ( V_106 -> V_28 ) ,
F_44 ( V_106 -> V_6 , & V_106 -> V_24 ) ,
F_45 ( V_106 -> V_25 ) ,
F_44 ( V_106 -> V_6 , & V_106 -> V_26 ) ,
F_45 ( V_106 -> V_27 ) ,
F_44 ( V_106 -> V_6 , & V_106 -> V_55 ) ,
F_45 ( V_106 -> V_61 ) ) ;
if ( V_106 -> V_27 != F_73 ( 0xffff ) ) {
if ( F_33 ( V_106 ) ) {
V_106 -> V_61 = F_73 ( 0xffff ) ;
V_106 -> V_27 = F_73 ( 0xffff ) ;
V_106 -> V_25 = 0 ;
F_26 ( V_106 ) ;
}
}
F_35 ( & V_106 -> V_40 ) ;
return 0 ;
}
return 1 ;
}
static void F_74 ( unsigned long V_108 )
{
struct V_29 * V_30 = (struct V_29 * ) V_108 ;
struct V_5 * V_5 = F_25 ( V_30 ) ;
struct V_102 * V_103 = F_72 ( V_5 ) ;
V_30 -> V_63 = 60 * V_109 ;
F_29 ( & V_30 -> V_40 ) ;
if ( F_41 ( & V_30 -> V_110 ) )
goto V_111;
if ( ! F_33 ( V_30 ) && ! ( V_30 -> V_34 & V_35 ) )
goto V_111;
if ( F_22 ( F_41 ( & V_30 -> V_40 ) == 1 ) ) {
if ( F_75 ( & V_30 -> V_64 ) )
F_76 ( & V_30 -> V_64 ) ;
if ( V_30 -> V_112 )
F_77 ( V_30 ) ;
if ( V_30 -> V_34 & V_113 ) {
F_78 ( V_30 ) ;
F_79 () ;
if ( V_103 -> V_114 )
F_78 ( V_30 ) ;
}
F_80 ( V_30 -> V_22 ) ;
F_81 ( V_30 -> V_21 ) ;
if ( F_82 ( V_30 -> V_98 != NULL ) )
F_65 ( V_30 ) ;
F_68 ( V_30 ) ;
if ( V_30 -> V_34 & V_44 )
F_35 ( & V_45 ) ;
F_35 ( & V_103 -> V_115 ) ;
F_83 ( V_116 , V_30 ) ;
return;
}
F_26 ( V_30 ) ;
V_111:
F_84 ( 7 , L_14 ,
F_41 ( & V_30 -> V_40 ) - 1 ,
F_41 ( & V_30 -> V_110 ) ) ;
if ( V_103 -> V_117 & V_118 )
F_85 ( V_5 , V_30 , F_86 ( V_103 ) ) ;
F_53 ( V_30 ) ;
}
void F_87 ( struct V_29 * V_30 )
{
if ( F_76 ( & V_30 -> V_64 ) )
F_54 ( & V_30 -> V_64 , V_65 ) ;
}
struct V_29 *
F_88 ( const struct V_18 * V_19 ,
const union V_8 * V_55 , T_1 V_61 , unsigned int V_34 ,
struct V_81 * V_82 , T_2 V_95 )
{
struct V_29 * V_30 ;
struct V_102 * V_103 = F_72 ( V_19 -> V_5 ) ;
struct V_96 * V_97 = F_66 ( V_19 -> V_5 ,
V_19 -> V_28 ) ;
V_30 = F_89 ( V_116 , V_119 ) ;
if ( V_30 == NULL ) {
F_90 ( L_15 , V_41 ) ;
return NULL ;
}
F_91 ( & V_30 -> V_38 ) ;
F_92 ( & V_30 -> V_64 , F_74 , ( unsigned long ) V_30 ) ;
F_93 ( V_30 , V_19 -> V_5 ) ;
V_30 -> V_6 = V_19 -> V_6 ;
V_30 -> V_28 = V_19 -> V_28 ;
F_94 ( V_19 -> V_6 , & V_30 -> V_24 , V_19 -> V_24 ) ;
V_30 -> V_25 = V_19 -> V_25 ;
F_94 ( V_19 -> V_6 , & V_30 -> V_26 , V_19 -> V_26 ) ;
V_30 -> V_27 = V_19 -> V_27 ;
F_94 ( V_19 -> V_28 == V_58 ? V_59 : V_19 -> V_6 ,
& V_30 -> V_55 , V_55 ) ;
V_30 -> V_61 = V_61 ;
V_30 -> V_34 = V_34 ;
V_30 -> V_95 = V_95 ;
if ( V_34 & V_60 && V_19 -> V_22 ) {
F_95 ( V_19 -> V_22 ) ;
V_30 -> V_22 = V_19 -> V_22 ;
V_30 -> V_21 = V_19 -> V_21 ;
V_30 -> V_31 = V_19 -> V_31 ;
}
F_96 ( & V_30 -> V_36 ) ;
F_97 ( & V_30 -> V_40 , 1 ) ;
F_97 ( & V_30 -> V_110 , 0 ) ;
F_97 ( & V_30 -> V_120 , 0 ) ;
F_29 ( & V_103 -> V_115 ) ;
if ( V_34 & V_44 )
F_29 ( & V_45 ) ;
F_61 ( V_30 , V_82 ) ;
V_30 -> V_91 = 0 ;
V_30 -> V_63 = 3 * V_109 ;
V_30 -> V_121 = V_65 & ~ 3UL ;
#ifdef F_18
if ( V_19 -> V_6 == V_11 )
F_59 ( V_30 ) ;
else
#endif
F_57 ( V_30 ) ;
if ( F_82 ( V_97 && F_41 ( & V_97 -> V_99 ) ) )
F_67 ( V_30 , V_97 -> V_100 ) ;
if ( F_98 ( V_103 ) )
V_30 -> V_34 |= V_113 ;
F_26 ( V_30 ) ;
return V_30 ;
}
static void * F_99 ( struct V_122 * V_123 , T_3 V_124 )
{
int V_125 ;
struct V_29 * V_30 ;
struct V_126 * V_127 = V_123 -> V_128 ;
struct V_42 * V_43 ;
for ( V_125 = 0 ; V_125 < V_129 ; V_125 ++ ) {
F_9 ( V_125 ) ;
F_37 (cp, n, &ip_vs_conn_tab[idx], c_list) {
if ( V_124 -- == 0 ) {
V_127 -> V_4 = & V_39 [ V_125 ] ;
return V_30 ;
}
}
F_11 ( V_125 ) ;
}
return NULL ;
}
static void * F_100 ( struct V_122 * V_123 , T_3 * V_124 )
{
struct V_126 * V_127 = V_123 -> V_128 ;
V_127 -> V_4 = NULL ;
return * V_124 ? F_99 ( V_123 , * V_124 - 1 ) : V_130 ;
}
static void * F_101 ( struct V_122 * V_123 , void * V_131 , T_3 * V_124 )
{
struct V_29 * V_30 = V_131 ;
struct V_126 * V_127 = V_123 -> V_128 ;
struct V_42 * V_132 ;
struct V_133 * V_4 = V_127 -> V_4 ;
int V_125 ;
++ * V_124 ;
if ( V_131 == V_130 )
return F_99 ( V_123 , 0 ) ;
if ( ( V_132 = V_30 -> V_38 . V_134 ) )
return F_102 ( V_132 , struct V_29 , V_38 ) ;
V_125 = V_4 - V_39 ;
F_11 ( V_125 ) ;
while ( ++ V_125 < V_129 ) {
F_9 ( V_125 ) ;
F_37 (cp, e, &ip_vs_conn_tab[idx], c_list) {
V_127 -> V_4 = & V_39 [ V_125 ] ;
return V_30 ;
}
F_11 ( V_125 ) ;
}
V_127 -> V_4 = NULL ;
return NULL ;
}
static void F_103 ( struct V_122 * V_123 , void * V_131 )
{
struct V_126 * V_127 = V_123 -> V_128 ;
struct V_133 * V_4 = V_127 -> V_4 ;
if ( V_4 )
F_11 ( V_4 - V_39 ) ;
}
static int F_104 ( struct V_122 * V_123 , void * V_131 )
{
if ( V_131 == V_130 )
F_105 ( V_123 ,
L_16 ) ;
else {
const struct V_29 * V_30 = V_131 ;
struct V_5 * V_5 = F_106 ( V_123 ) ;
char V_21 [ V_135 + V_136 + 3 ] ;
V_15 V_137 = 0 ;
if ( ! F_39 ( V_30 , V_5 ) )
return 0 ;
if ( V_30 -> V_21 ) {
V_21 [ 0 ] = ' ' ;
V_137 = strlen ( V_30 -> V_22 -> V_138 ) ;
memcpy ( V_21 + 1 , V_30 -> V_22 -> V_138 , V_137 ) ;
V_21 [ V_137 + 1 ] = ' ' ;
V_137 += 2 ;
V_137 += V_30 -> V_22 -> V_139 ( V_30 , V_21 + V_137 ) ;
}
V_21 [ V_137 ] = '\0' ;
#ifdef F_18
if ( V_30 -> V_6 == V_11 )
F_107 ( V_123 , L_17
L_18 ,
F_43 ( V_30 -> V_28 ) ,
& V_30 -> V_24 . V_140 , F_45 ( V_30 -> V_25 ) ,
& V_30 -> V_26 . V_140 , F_45 ( V_30 -> V_27 ) ,
& V_30 -> V_55 . V_140 , F_45 ( V_30 -> V_61 ) ,
F_108 ( V_30 -> V_28 , V_30 -> V_91 ) ,
( V_30 -> V_64 . V_141 - V_65 ) / V_109 , V_21 ) ;
else
#endif
F_107 ( V_123 ,
L_19
L_20 ,
F_43 ( V_30 -> V_28 ) ,
F_109 ( V_30 -> V_24 . V_17 ) , F_45 ( V_30 -> V_25 ) ,
F_109 ( V_30 -> V_26 . V_17 ) , F_45 ( V_30 -> V_27 ) ,
F_109 ( V_30 -> V_55 . V_17 ) , F_45 ( V_30 -> V_61 ) ,
F_108 ( V_30 -> V_28 , V_30 -> V_91 ) ,
( V_30 -> V_64 . V_141 - V_65 ) / V_109 , V_21 ) ;
}
return 0 ;
}
static int F_110 ( struct V_142 * V_142 , struct V_143 * V_143 )
{
return F_111 ( V_142 , V_143 , & V_144 ,
sizeof( struct V_126 ) ) ;
}
static const char * F_112 ( unsigned int V_34 )
{
if ( V_34 & V_87 )
return L_21 ;
else
return L_22 ;
}
static int F_113 ( struct V_122 * V_123 , void * V_131 )
{
if ( V_131 == V_130 )
F_105 ( V_123 ,
L_23 ) ;
else {
const struct V_29 * V_30 = V_131 ;
struct V_5 * V_5 = F_106 ( V_123 ) ;
if ( ! F_39 ( V_30 , V_5 ) )
return 0 ;
#ifdef F_18
if ( V_30 -> V_6 == V_11 )
F_107 ( V_123 , L_24 ,
F_43 ( V_30 -> V_28 ) ,
& V_30 -> V_24 . V_140 , F_45 ( V_30 -> V_25 ) ,
& V_30 -> V_26 . V_140 , F_45 ( V_30 -> V_27 ) ,
& V_30 -> V_55 . V_140 , F_45 ( V_30 -> V_61 ) ,
F_108 ( V_30 -> V_28 , V_30 -> V_91 ) ,
F_112 ( V_30 -> V_34 ) ,
( V_30 -> V_64 . V_141 - V_65 ) / V_109 ) ;
else
#endif
F_107 ( V_123 ,
L_25
L_26 ,
F_43 ( V_30 -> V_28 ) ,
F_109 ( V_30 -> V_24 . V_17 ) , F_45 ( V_30 -> V_25 ) ,
F_109 ( V_30 -> V_26 . V_17 ) , F_45 ( V_30 -> V_27 ) ,
F_109 ( V_30 -> V_55 . V_17 ) , F_45 ( V_30 -> V_61 ) ,
F_108 ( V_30 -> V_28 , V_30 -> V_91 ) ,
F_112 ( V_30 -> V_34 ) ,
( V_30 -> V_64 . V_141 - V_65 ) / V_109 ) ;
}
return 0 ;
}
static int F_114 ( struct V_142 * V_142 , struct V_143 * V_143 )
{
return F_111 ( V_142 , V_143 , & V_145 ,
sizeof( struct V_126 ) ) ;
}
static inline int F_115 ( struct V_29 * V_30 )
{
static const char V_146 [ 9 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 } ;
static char V_147 [ 9 ] = { 0 } ;
int V_148 ;
if ( F_116 ( V_30 -> V_63 + V_65 , V_30 -> V_64 . V_141 + 60 * V_109 ) )
return 0 ;
V_148 = F_41 ( & V_30 -> V_120 ) ;
if ( V_148 > 8 || V_148 < 0 ) return 0 ;
if ( ! V_146 [ V_148 ] ) return 0 ;
if ( -- V_147 [ V_148 ] > 0 ) return 0 ;
V_147 [ V_148 ] = V_146 [ V_148 ] ;
return 1 ;
}
void F_117 ( struct V_5 * V_5 )
{
int V_125 ;
struct V_29 * V_30 ;
for ( V_125 = 0 ; V_125 < ( V_129 >> 5 ) ; V_125 ++ ) {
unsigned int V_32 = F_118 () & V_16 ;
struct V_42 * V_43 ;
F_13 ( V_32 ) ;
F_37 (cp, n, &ip_vs_conn_tab[hash], c_list) {
if ( V_30 -> V_34 & V_60 )
continue;
if ( ! F_39 ( V_30 , V_5 ) )
continue;
if ( V_30 -> V_28 == V_149 ) {
switch( V_30 -> V_91 ) {
case V_150 :
case V_151 :
break;
case V_152 :
if ( F_115 ( V_30 ) )
break;
continue;
default:
continue;
}
} else {
if ( ! F_115 ( V_30 ) )
continue;
}
F_84 ( 4 , L_27 ) ;
F_87 ( V_30 ) ;
if ( V_30 -> V_112 ) {
F_84 ( 4 , L_28 ) ;
F_87 ( V_30 -> V_112 ) ;
}
}
F_15 ( V_32 ) ;
}
}
static void F_119 ( struct V_5 * V_5 )
{
int V_125 ;
struct V_29 * V_30 ;
struct V_102 * V_103 = F_72 ( V_5 ) ;
V_153:
for ( V_125 = 0 ; V_125 < V_129 ; V_125 ++ ) {
struct V_42 * V_43 ;
F_13 ( V_125 ) ;
F_37 (cp, n, &ip_vs_conn_tab[idx], c_list) {
if ( ! F_39 ( V_30 , V_5 ) )
continue;
F_84 ( 4 , L_27 ) ;
F_87 ( V_30 ) ;
if ( V_30 -> V_112 ) {
F_84 ( 4 , L_28 ) ;
F_87 ( V_30 -> V_112 ) ;
}
}
F_15 ( V_125 ) ;
}
if ( F_41 ( & V_103 -> V_115 ) != 0 ) {
F_120 () ;
goto V_153;
}
}
int T_4 F_121 ( struct V_5 * V_5 )
{
struct V_102 * V_103 = F_72 ( V_5 ) ;
F_97 ( & V_103 -> V_115 , 0 ) ;
F_122 ( V_5 , L_29 , 0 , & V_154 ) ;
F_122 ( V_5 , L_30 , 0 , & V_155 ) ;
return 0 ;
}
void T_5 F_123 ( struct V_5 * V_5 )
{
F_119 ( V_5 ) ;
F_124 ( V_5 , L_29 ) ;
F_124 ( V_5 , L_30 ) ;
}
int T_6 F_125 ( void )
{
int V_125 ;
V_129 = 1 << V_156 ;
V_16 = V_129 - 1 ;
V_39 = F_126 ( V_129 * sizeof( * V_39 ) ) ;
if ( ! V_39 )
return - V_157 ;
V_116 = F_127 ( L_29 ,
sizeof( struct V_29 ) , 0 ,
V_158 , NULL ) ;
if ( ! V_116 ) {
F_128 ( V_39 ) ;
return - V_157 ;
}
F_129 ( L_31
L_32 ,
V_129 ,
( long ) ( V_129 * sizeof( struct V_159 ) ) / 1024 ) ;
F_84 ( 0 , L_33 ,
sizeof( struct V_29 ) ) ;
for ( V_125 = 0 ; V_125 < V_129 ; V_125 ++ )
F_130 ( & V_39 [ V_125 ] ) ;
for ( V_125 = 0 ; V_125 < V_160 ; V_125 ++ ) {
F_131 ( & V_2 [ V_125 ] . V_4 ) ;
}
F_132 ( & V_12 , sizeof( V_12 ) ) ;
return 0 ;
}
void F_133 ( void )
{
F_134 ( V_116 ) ;
F_128 ( V_39 ) ;
}
