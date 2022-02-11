static inline void F_1 ( unsigned int V_1 )
{
F_2 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static inline void F_3 ( unsigned int V_1 )
{
F_4 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static unsigned int F_5 ( struct V_5 * V_6 , int V_7 , unsigned int V_8 ,
const union V_9 * V_10 ,
T_1 V_11 )
{
#ifdef F_6
if ( V_7 == V_12 )
return ( F_7 ( F_8 ( V_10 , 16 , V_13 ) ,
( V_14 V_15 ) V_11 , V_8 , V_13 ) ^
( ( V_16 ) V_6 >> 8 ) ) & V_17 ;
#endif
return ( F_7 ( ( V_14 V_15 ) V_10 -> V_18 , ( V_14 V_15 ) V_11 , V_8 ,
V_13 ) ^
( ( V_16 ) V_6 >> 8 ) ) & V_17 ;
}
static unsigned int F_9 ( const struct V_19 * V_20 ,
bool V_21 )
{
const union V_9 * V_10 ;
T_1 V_11 ;
if ( V_20 -> V_22 && V_20 -> V_23 -> V_24 )
return V_20 -> V_23 -> V_24 ( V_20 , V_13 , V_21 ) &
V_17 ;
if ( F_10 ( ! V_21 ) ) {
V_10 = V_20 -> V_25 ;
V_11 = V_20 -> V_26 ;
} else {
V_10 = V_20 -> V_27 ;
V_11 = V_20 -> V_28 ;
}
return F_5 ( V_20 -> V_6 , V_20 -> V_7 , V_20 -> V_29 , V_10 , V_11 ) ;
}
static unsigned int F_11 ( const struct V_30 * V_31 )
{
struct V_19 V_20 ;
F_12 ( V_31 -> V_6 , V_31 -> V_7 , V_31 -> V_29 ,
& V_31 -> V_25 , V_31 -> V_26 , NULL , 0 , & V_20 ) ;
if ( V_31 -> V_23 ) {
V_20 . V_23 = V_31 -> V_23 ;
V_20 . V_22 = V_31 -> V_22 ;
V_20 . V_32 = V_31 -> V_32 ;
}
return F_9 ( & V_20 , false ) ;
}
static inline int F_13 ( struct V_30 * V_31 )
{
unsigned int V_33 ;
int V_34 ;
if ( V_31 -> V_35 & V_36 )
return 0 ;
V_33 = F_11 ( V_31 ) ;
F_1 ( V_33 ) ;
F_14 ( & V_31 -> V_37 ) ;
if ( ! ( V_31 -> V_35 & V_38 ) ) {
V_31 -> V_35 |= V_38 ;
F_15 ( & V_31 -> V_39 ) ;
F_16 ( & V_31 -> V_40 , & V_41 [ V_33 ] ) ;
V_34 = 1 ;
} else {
F_17 ( L_1 ,
V_42 , F_18 ( 0 ) ) ;
V_34 = 0 ;
}
F_19 ( & V_31 -> V_37 ) ;
F_3 ( V_33 ) ;
return V_34 ;
}
static inline int F_20 ( struct V_30 * V_31 )
{
unsigned int V_33 ;
int V_34 ;
V_33 = F_11 ( V_31 ) ;
F_1 ( V_33 ) ;
F_14 ( & V_31 -> V_37 ) ;
if ( V_31 -> V_35 & V_38 ) {
F_21 ( & V_31 -> V_40 ) ;
V_31 -> V_35 &= ~ V_38 ;
F_22 ( & V_31 -> V_39 ) ;
V_34 = 1 ;
} else
V_34 = 0 ;
F_19 ( & V_31 -> V_37 ) ;
F_3 ( V_33 ) ;
return V_34 ;
}
static inline bool F_23 ( struct V_30 * V_31 )
{
unsigned int V_33 ;
bool V_34 ;
V_33 = F_11 ( V_31 ) ;
F_1 ( V_33 ) ;
F_14 ( & V_31 -> V_37 ) ;
if ( V_31 -> V_35 & V_38 ) {
V_34 = false ;
if ( F_24 ( & V_31 -> V_39 ) ) {
F_21 ( & V_31 -> V_40 ) ;
V_31 -> V_35 &= ~ V_38 ;
V_34 = true ;
}
} else
V_34 = F_25 ( & V_31 -> V_39 ) ? false : true ;
F_19 ( & V_31 -> V_37 ) ;
F_3 ( V_33 ) ;
return V_34 ;
}
static inline struct V_30 *
F_26 ( const struct V_19 * V_20 )
{
unsigned int V_33 ;
struct V_30 * V_31 ;
V_33 = F_9 ( V_20 , false ) ;
F_27 () ;
F_28 (cp, &ip_vs_conn_tab[hash], c_list) {
if ( V_20 -> V_26 == V_31 -> V_26 && V_20 -> V_28 == V_31 -> V_28 &&
V_31 -> V_7 == V_20 -> V_7 &&
F_29 ( V_20 -> V_7 , V_20 -> V_25 , & V_31 -> V_25 ) &&
F_29 ( V_20 -> V_7 , V_20 -> V_27 , & V_31 -> V_27 ) &&
( ( ! V_20 -> V_26 ) ^ ( ! ( V_31 -> V_35 & V_43 ) ) ) &&
V_20 -> V_29 == V_31 -> V_29 &&
V_31 -> V_6 == V_20 -> V_6 ) {
if ( ! F_30 ( V_31 ) )
continue;
F_31 () ;
return V_31 ;
}
}
F_31 () ;
return NULL ;
}
struct V_30 * F_32 ( const struct V_19 * V_20 )
{
struct V_30 * V_31 ;
V_31 = F_26 ( V_20 ) ;
if ( ! V_31 && F_33 ( & V_44 ) ) {
struct V_19 V_45 = * V_20 ;
V_45 . V_26 = 0 ;
V_31 = F_26 ( & V_45 ) ;
}
F_34 ( 9 , L_2 ,
F_35 ( V_20 -> V_29 ) ,
F_36 ( V_20 -> V_7 , V_20 -> V_25 ) , F_37 ( V_20 -> V_26 ) ,
F_36 ( V_20 -> V_7 , V_20 -> V_27 ) , F_37 ( V_20 -> V_28 ) ,
V_31 ? L_3 : L_4 ) ;
return V_31 ;
}
static int
F_38 ( struct V_5 * V_6 ,
int V_7 , const struct V_46 * V_47 ,
const struct V_48 * V_49 ,
struct V_19 * V_20 )
{
T_1 V_50 [ 2 ] , * V_51 ;
V_51 = F_39 ( V_47 , V_49 -> V_52 , sizeof( V_50 ) , V_50 , V_49 ) ;
if ( V_51 == NULL )
return 1 ;
if ( F_10 ( ! F_40 ( V_49 ) ) )
F_12 ( V_6 , V_7 , V_49 -> V_29 , & V_49 -> V_53 ,
V_51 [ 0 ] , & V_49 -> V_54 , V_51 [ 1 ] , V_20 ) ;
else
F_12 ( V_6 , V_7 , V_49 -> V_29 , & V_49 -> V_54 ,
V_51 [ 1 ] , & V_49 -> V_53 , V_51 [ 0 ] , V_20 ) ;
return 0 ;
}
struct V_30 *
F_41 ( struct V_5 * V_6 , int V_7 ,
const struct V_46 * V_47 ,
const struct V_48 * V_49 )
{
struct V_19 V_20 ;
if ( F_38 ( V_6 , V_7 , V_47 , V_49 , & V_20 ) )
return NULL ;
return F_32 ( & V_20 ) ;
}
struct V_30 * F_42 ( const struct V_19 * V_20 )
{
unsigned int V_33 ;
struct V_30 * V_31 ;
V_33 = F_9 ( V_20 , false ) ;
F_27 () ;
F_28 (cp, &ip_vs_conn_tab[hash], c_list) {
if ( F_43 ( V_20 -> V_22 && V_20 -> V_23 -> V_55 ) ) {
if ( V_31 -> V_6 != V_20 -> V_6 )
continue;
if ( V_20 -> V_23 == V_31 -> V_23 && V_20 -> V_23 -> V_55 ( V_20 , V_31 ) ) {
if ( F_30 ( V_31 ) )
goto V_56;
}
continue;
}
if ( V_31 -> V_7 == V_20 -> V_7 &&
F_29 ( V_20 -> V_7 , V_20 -> V_25 , & V_31 -> V_25 ) &&
F_29 ( V_20 -> V_29 == V_57 ? V_58 :
V_20 -> V_7 , V_20 -> V_27 , & V_31 -> V_27 ) &&
V_20 -> V_28 == V_31 -> V_28 && V_20 -> V_26 == V_31 -> V_26 &&
V_31 -> V_35 & V_59 &&
V_20 -> V_29 == V_31 -> V_29 &&
V_31 -> V_6 == V_20 -> V_6 ) {
if ( F_30 ( V_31 ) )
goto V_56;
}
}
V_31 = NULL ;
V_56:
F_31 () ;
F_34 ( 9 , L_5 ,
F_35 ( V_20 -> V_29 ) ,
F_36 ( V_20 -> V_7 , V_20 -> V_25 ) , F_37 ( V_20 -> V_26 ) ,
F_36 ( V_20 -> V_7 , V_20 -> V_27 ) , F_37 ( V_20 -> V_28 ) ,
V_31 ? L_3 : L_4 ) ;
return V_31 ;
}
struct V_30 * F_44 ( const struct V_19 * V_20 )
{
unsigned int V_33 ;
struct V_30 * V_31 , * V_34 = NULL ;
V_33 = F_9 ( V_20 , true ) ;
F_27 () ;
F_28 (cp, &ip_vs_conn_tab[hash], c_list) {
if ( V_20 -> V_28 == V_31 -> V_26 && V_20 -> V_26 == V_31 -> V_60 &&
V_31 -> V_7 == V_20 -> V_7 &&
F_29 ( V_20 -> V_7 , V_20 -> V_27 , & V_31 -> V_25 ) &&
F_29 ( V_20 -> V_7 , V_20 -> V_25 , & V_31 -> V_54 ) &&
V_20 -> V_29 == V_31 -> V_29 &&
V_31 -> V_6 == V_20 -> V_6 ) {
if ( ! F_30 ( V_31 ) )
continue;
V_34 = V_31 ;
break;
}
}
F_31 () ;
F_34 ( 9 , L_6 ,
F_35 ( V_20 -> V_29 ) ,
F_36 ( V_20 -> V_7 , V_20 -> V_25 ) , F_37 ( V_20 -> V_26 ) ,
F_36 ( V_20 -> V_7 , V_20 -> V_27 ) , F_37 ( V_20 -> V_28 ) ,
V_34 ? L_3 : L_4 ) ;
return V_34 ;
}
struct V_30 *
F_45 ( struct V_5 * V_6 , int V_7 ,
const struct V_46 * V_47 ,
const struct V_48 * V_49 )
{
struct V_19 V_20 ;
if ( F_38 ( V_6 , V_7 , V_47 , V_49 , & V_20 ) )
return NULL ;
return F_44 ( & V_20 ) ;
}
static void F_46 ( struct V_30 * V_31 )
{
F_47 ( V_31 ) ;
F_48 ( ( unsigned long ) V_31 ) ;
}
static void F_49 ( struct V_30 * V_31 )
{
unsigned long V_61 = ( V_31 -> V_35 & V_36 ) ?
0 : V_31 -> V_62 ;
F_50 ( & V_31 -> V_63 , V_64 + V_61 ) ;
F_47 ( V_31 ) ;
}
void F_51 ( struct V_30 * V_31 )
{
if ( ( V_31 -> V_35 & V_36 ) &&
( F_25 ( & V_31 -> V_39 ) == 1 ) &&
! F_52 ( & V_31 -> V_63 ) )
F_46 ( V_31 ) ;
else
F_49 ( V_31 ) ;
}
void F_53 ( struct V_30 * V_31 , T_1 V_26 )
{
if ( F_20 ( V_31 ) ) {
F_2 ( & V_31 -> V_37 ) ;
if ( V_31 -> V_35 & V_43 ) {
F_54 ( & V_44 ) ;
V_31 -> V_35 &= ~ V_43 ;
V_31 -> V_26 = V_26 ;
}
F_4 ( & V_31 -> V_37 ) ;
F_13 ( V_31 ) ;
}
}
static inline void F_55 ( struct V_30 * V_31 )
{
switch ( F_56 ( V_31 ) ) {
case V_65 :
V_31 -> V_66 = V_67 ;
break;
case V_68 :
#ifdef F_6
if ( V_31 -> V_69 == V_12 )
V_31 -> V_66 = V_70 ;
else
#endif
V_31 -> V_66 = V_71 ;
break;
case V_72 :
V_31 -> V_66 = V_73 ;
break;
case V_74 :
V_31 -> V_66 = V_75 ;
break;
case V_76 :
V_31 -> V_66 = V_77 ;
break;
}
}
static inline void F_57 ( struct V_30 * V_31 )
{
switch ( F_56 ( V_31 ) ) {
case V_65 :
V_31 -> V_66 = V_78 ;
break;
case V_68 :
if ( V_31 -> V_69 == V_12 )
V_31 -> V_66 = V_70 ;
else
V_31 -> V_66 = V_71 ;
break;
case V_72 :
V_31 -> V_66 = V_79 ;
break;
case V_74 :
V_31 -> V_66 = V_75 ;
break;
case V_76 :
V_31 -> V_66 = V_80 ;
break;
}
}
static inline int F_58 ( struct V_81 * V_82 )
{
return F_33 ( & V_82 -> V_83 )
+ F_33 ( & V_82 -> V_84 ) ;
}
static inline void
F_59 ( struct V_30 * V_31 , struct V_81 * V_82 )
{
unsigned int V_85 ;
T_2 V_35 ;
if ( ! V_82 )
return;
F_60 ( V_82 ) ;
V_85 = F_33 ( & V_82 -> V_85 ) ;
if ( V_31 -> V_29 != V_86 )
V_85 &= ~ V_36 ;
V_35 = V_31 -> V_35 ;
if ( V_35 & V_87 ) {
if ( ! ( V_35 & V_59 ) )
V_85 &= ~ V_88 ;
V_35 &= ~ ( V_89 | V_90 ) ;
}
V_35 |= V_85 ;
V_31 -> V_35 = V_35 ;
V_31 -> V_82 = V_82 ;
F_34 ( 7 , L_7
L_8
L_9 ,
F_35 ( V_31 -> V_29 ) ,
F_36 ( V_31 -> V_7 , & V_31 -> V_25 ) , F_37 ( V_31 -> V_26 ) ,
F_36 ( V_31 -> V_7 , & V_31 -> V_27 ) , F_37 ( V_31 -> V_28 ) ,
F_36 ( V_31 -> V_69 , & V_31 -> V_54 ) , F_37 ( V_31 -> V_60 ) ,
F_61 ( V_31 ) , V_31 -> V_91 ,
V_31 -> V_35 , F_25 ( & V_31 -> V_39 ) ,
F_25 ( & V_82 -> V_39 ) ) ;
if ( ! ( V_35 & V_59 ) ) {
if ( ! ( V_35 & V_88 ) )
F_62 ( & V_82 -> V_83 ) ;
else
F_62 ( & V_82 -> V_84 ) ;
} else {
F_62 ( & V_82 -> V_92 ) ;
}
if ( V_82 -> V_93 != 0 &&
F_58 ( V_82 ) >= V_82 -> V_93 )
V_82 -> V_35 |= V_94 ;
}
void F_63 ( struct V_30 * V_31 )
{
struct V_81 * V_82 ;
F_27 () ;
V_82 = F_64 ( V_31 -> V_6 , V_31 -> V_7 , V_31 -> V_7 , & V_31 -> V_54 ,
V_31 -> V_60 , & V_31 -> V_27 , V_31 -> V_28 ,
V_31 -> V_29 , V_31 -> V_95 , V_31 -> V_35 ) ;
if ( V_82 ) {
struct V_96 * V_97 ;
F_2 ( & V_31 -> V_37 ) ;
if ( V_31 -> V_82 ) {
F_4 ( & V_31 -> V_37 ) ;
F_31 () ;
return;
}
if ( V_31 -> V_98 )
F_65 ( V_31 ) ;
F_59 ( V_31 , V_82 ) ;
F_4 ( & V_31 -> V_37 ) ;
V_31 -> V_66 = NULL ;
#ifdef F_6
if ( V_31 -> V_7 == V_12 )
F_57 ( V_31 ) ;
else
#endif
F_55 ( V_31 ) ;
V_97 = F_66 ( V_31 -> V_6 , V_31 -> V_29 ) ;
if ( V_97 && F_33 ( & V_97 -> V_99 ) )
F_67 ( V_31 , V_97 -> V_100 ) ;
}
F_31 () ;
}
static inline void F_68 ( struct V_30 * V_31 )
{
struct V_81 * V_82 = V_31 -> V_82 ;
if ( ! V_82 )
return;
F_34 ( 7 , L_10
L_8
L_9 ,
F_35 ( V_31 -> V_29 ) ,
F_36 ( V_31 -> V_7 , & V_31 -> V_25 ) , F_37 ( V_31 -> V_26 ) ,
F_36 ( V_31 -> V_7 , & V_31 -> V_27 ) , F_37 ( V_31 -> V_28 ) ,
F_36 ( V_31 -> V_69 , & V_31 -> V_54 ) , F_37 ( V_31 -> V_60 ) ,
F_61 ( V_31 ) , V_31 -> V_91 ,
V_31 -> V_35 , F_25 ( & V_31 -> V_39 ) ,
F_25 ( & V_82 -> V_39 ) ) ;
if ( ! ( V_31 -> V_35 & V_59 ) ) {
if ( V_31 -> V_35 & V_88 ) {
F_54 ( & V_82 -> V_84 ) ;
} else {
F_54 ( & V_82 -> V_83 ) ;
}
} else {
F_54 ( & V_82 -> V_92 ) ;
}
if ( V_82 -> V_101 != 0 ) {
if ( F_58 ( V_82 ) < V_82 -> V_101 )
V_82 -> V_35 &= ~ V_94 ;
} else if ( V_82 -> V_93 != 0 ) {
if ( F_58 ( V_82 ) * 4 < V_82 -> V_93 * 3 )
V_82 -> V_35 &= ~ V_94 ;
} else {
if ( V_82 -> V_35 & V_94 )
V_82 -> V_35 &= ~ V_94 ;
}
F_69 ( V_82 ) ;
}
static int F_70 ( struct V_5 * V_6 ,
struct V_81 * V_82 )
{
#ifdef F_71
return V_6 -> V_102 &&
( F_33 ( & V_82 -> V_103 ) == 0 ) ;
#else
return 0 ;
#endif
}
int F_72 ( struct V_30 * V_104 , struct V_81 * V_105 )
{
struct V_81 * V_82 = V_104 -> V_82 ;
struct V_5 * V_6 = V_104 -> V_6 ;
if ( ( V_82 == NULL ) ||
! ( V_82 -> V_35 & V_106 ) ||
F_70 ( V_6 , V_82 ) ||
( V_105 && ( V_82 != V_105 ) ) ) {
F_34 ( 9 , L_11
L_12
L_13 ,
F_35 ( V_104 -> V_29 ) ,
F_36 ( V_104 -> V_7 , & V_104 -> V_25 ) ,
F_37 ( V_104 -> V_26 ) ,
F_36 ( V_104 -> V_7 , & V_104 -> V_27 ) ,
F_37 ( V_104 -> V_28 ) ,
F_36 ( V_104 -> V_69 , & V_104 -> V_54 ) ,
F_37 ( V_104 -> V_60 ) ) ;
if ( V_104 -> V_28 != F_73 ( 0xffff ) ) {
if ( F_20 ( V_104 ) ) {
V_104 -> V_60 = F_73 ( 0xffff ) ;
V_104 -> V_28 = F_73 ( 0xffff ) ;
V_104 -> V_26 = 0 ;
F_13 ( V_104 ) ;
}
}
F_47 ( V_104 ) ;
return 0 ;
}
return 1 ;
}
static void F_74 ( struct V_107 * V_108 )
{
struct V_30 * V_31 = F_75 ( V_108 , struct V_30 ,
V_107 ) ;
F_76 ( V_31 -> V_23 ) ;
F_77 ( V_31 -> V_22 ) ;
F_78 ( V_109 , V_31 ) ;
}
static void F_48 ( unsigned long V_110 )
{
struct V_30 * V_31 = (struct V_30 * ) V_110 ;
struct V_5 * V_6 = V_31 -> V_6 ;
if ( F_33 ( & V_31 -> V_111 ) )
goto V_112;
if ( F_10 ( F_23 ( V_31 ) ) ) {
F_79 ( & V_31 -> V_63 ) ;
if ( V_31 -> V_113 )
F_80 ( V_31 ) ;
if ( ( V_31 -> V_35 & V_114 ) &&
! ( V_31 -> V_35 & V_36 ) ) {
F_81 () ;
if ( V_6 -> V_115 )
F_82 ( V_31 ) ;
}
if ( F_43 ( V_31 -> V_98 != NULL ) )
F_65 ( V_31 ) ;
F_68 ( V_31 ) ;
if ( V_31 -> V_35 & V_43 )
F_54 ( & V_44 ) ;
if ( V_31 -> V_35 & V_36 )
F_74 ( & V_31 -> V_107 ) ;
else
F_83 ( & V_31 -> V_107 , F_74 ) ;
F_54 ( & V_6 -> V_116 ) ;
return;
}
V_112:
F_84 ( 7 , L_14 ,
F_25 ( & V_31 -> V_39 ) ,
F_33 ( & V_31 -> V_111 ) ) ;
F_15 ( & V_31 -> V_39 ) ;
V_31 -> V_62 = 60 * V_117 ;
if ( V_6 -> V_118 & V_119 )
F_85 ( V_6 , V_31 , F_86 ( V_6 ) ) ;
F_49 ( V_31 ) ;
}
void F_87 ( struct V_30 * V_31 )
{
if ( F_52 ( & V_31 -> V_63 ) &&
F_88 ( V_31 -> V_63 . V_120 , V_64 ) )
F_89 ( & V_31 -> V_63 , V_64 ) ;
}
struct V_30 *
F_90 ( const struct V_19 * V_20 , int V_121 ,
const union V_9 * V_54 , T_1 V_60 , unsigned int V_35 ,
struct V_81 * V_82 , T_2 V_95 )
{
struct V_30 * V_31 ;
struct V_5 * V_6 = V_20 -> V_6 ;
struct V_96 * V_97 = F_66 ( V_20 -> V_6 ,
V_20 -> V_29 ) ;
V_31 = F_91 ( V_109 , V_122 ) ;
if ( V_31 == NULL ) {
F_92 ( L_15 , V_42 ) ;
return NULL ;
}
F_93 ( & V_31 -> V_40 ) ;
F_94 ( & V_31 -> V_63 , F_48 , ( unsigned long ) V_31 ) ;
V_31 -> V_6 = V_6 ;
V_31 -> V_7 = V_20 -> V_7 ;
V_31 -> V_69 = V_121 ;
V_31 -> V_29 = V_20 -> V_29 ;
F_95 ( V_20 -> V_7 , & V_31 -> V_25 , V_20 -> V_25 ) ;
V_31 -> V_26 = V_20 -> V_26 ;
F_95 ( V_20 -> V_29 == V_57 ? V_58 : V_20 -> V_7 ,
& V_31 -> V_27 , V_20 -> V_27 ) ;
V_31 -> V_28 = V_20 -> V_28 ;
F_95 ( V_31 -> V_69 , & V_31 -> V_54 , V_54 ) ;
V_31 -> V_60 = V_60 ;
V_31 -> V_35 = V_35 ;
V_31 -> V_95 = V_95 ;
if ( V_35 & V_59 && V_20 -> V_23 ) {
F_96 ( V_20 -> V_23 ) ;
V_31 -> V_23 = V_20 -> V_23 ;
V_31 -> V_22 = V_20 -> V_22 ;
V_31 -> V_32 = V_20 -> V_32 ;
} else {
V_31 -> V_23 = NULL ;
V_31 -> V_22 = NULL ;
V_31 -> V_32 = 0 ;
}
F_97 ( & V_31 -> V_37 ) ;
F_98 ( & V_31 -> V_39 , 1 ) ;
V_31 -> V_113 = NULL ;
F_99 ( & V_31 -> V_111 , 0 ) ;
F_99 ( & V_31 -> V_123 , 0 ) ;
V_31 -> V_66 = NULL ;
V_31 -> V_98 = NULL ;
V_31 -> V_124 = NULL ;
V_31 -> V_125 . V_126 = 0 ;
V_31 -> V_127 . V_126 = 0 ;
F_62 ( & V_6 -> V_116 ) ;
if ( V_35 & V_43 )
F_62 ( & V_44 ) ;
V_31 -> V_82 = NULL ;
F_59 ( V_31 , V_82 ) ;
V_31 -> V_91 = 0 ;
V_31 -> V_128 = 0 ;
V_31 -> V_62 = 3 * V_117 ;
V_31 -> V_129 = V_64 & ~ 3UL ;
#ifdef F_6
if ( V_20 -> V_7 == V_12 )
F_57 ( V_31 ) ;
else
#endif
F_55 ( V_31 ) ;
if ( F_43 ( V_97 && F_33 ( & V_97 -> V_99 ) ) )
F_67 ( V_31 , V_97 -> V_100 ) ;
if ( F_100 ( V_6 ) )
V_31 -> V_35 |= V_114 ;
F_13 ( V_31 ) ;
return V_31 ;
}
static void * F_101 ( struct V_130 * V_131 , T_3 V_132 )
{
int V_133 ;
struct V_30 * V_31 ;
struct V_134 * V_135 = V_131 -> V_136 ;
for ( V_133 = 0 ; V_133 < V_137 ; V_133 ++ ) {
F_28 (cp, &ip_vs_conn_tab[idx], c_list) {
if ( V_132 -- == 0 ) {
V_135 -> V_4 = & V_41 [ V_133 ] ;
return V_31 ;
}
}
F_102 () ;
}
return NULL ;
}
static void * F_103 ( struct V_130 * V_131 , T_3 * V_132 )
__acquires( T_4 )
{
struct V_134 * V_135 = V_131 -> V_136 ;
V_135 -> V_4 = NULL ;
F_27 () ;
return * V_132 ? F_101 ( V_131 , * V_132 - 1 ) : V_138 ;
}
static void * F_104 ( struct V_130 * V_131 , void * V_139 , T_3 * V_132 )
{
struct V_30 * V_31 = V_139 ;
struct V_134 * V_135 = V_131 -> V_136 ;
struct V_140 * V_141 ;
struct V_142 * V_4 = V_135 -> V_4 ;
int V_133 ;
++ * V_132 ;
if ( V_139 == V_138 )
return F_101 ( V_131 , 0 ) ;
V_141 = F_105 ( F_106 ( & V_31 -> V_40 ) ) ;
if ( V_141 )
return F_107 ( V_141 , struct V_30 , V_40 ) ;
V_133 = V_4 - V_41 ;
while ( ++ V_133 < V_137 ) {
F_28 (cp, &ip_vs_conn_tab[idx], c_list) {
V_135 -> V_4 = & V_41 [ V_133 ] ;
return V_31 ;
}
F_102 () ;
}
V_135 -> V_4 = NULL ;
return NULL ;
}
static void F_108 ( struct V_130 * V_131 , void * V_139 )
__releases( T_4 )
{
F_31 () ;
}
static int F_109 ( struct V_130 * V_131 , void * V_139 )
{
if ( V_139 == V_138 )
F_110 ( V_131 ,
L_16 ) ;
else {
const struct V_30 * V_31 = V_139 ;
struct V_143 * V_143 = F_111 ( V_131 ) ;
char V_22 [ V_144 + V_145 + 3 ] ;
V_16 V_52 = 0 ;
char V_146 [ V_147 ] ;
if ( ! F_112 ( V_31 -> V_6 -> V_143 , V_143 ) )
return 0 ;
if ( V_31 -> V_22 ) {
V_22 [ 0 ] = ' ' ;
V_52 = strlen ( V_31 -> V_23 -> V_148 ) ;
memcpy ( V_22 + 1 , V_31 -> V_23 -> V_148 , V_52 ) ;
V_22 [ V_52 + 1 ] = ' ' ;
V_52 += 2 ;
V_52 += V_31 -> V_23 -> V_149 ( V_31 , V_22 + V_52 ) ;
}
V_22 [ V_52 ] = '\0' ;
#ifdef F_6
if ( V_31 -> V_69 == V_12 )
snprintf ( V_146 , sizeof( V_146 ) , L_17 , & V_31 -> V_54 . V_150 ) ;
else
#endif
snprintf ( V_146 , sizeof( V_146 ) , L_18 ,
F_113 ( V_31 -> V_54 . V_18 ) ) ;
#ifdef F_6
if ( V_31 -> V_7 == V_12 )
F_114 ( V_131 , L_19
L_20 ,
F_35 ( V_31 -> V_29 ) ,
& V_31 -> V_25 . V_150 , F_37 ( V_31 -> V_26 ) ,
& V_31 -> V_27 . V_150 , F_37 ( V_31 -> V_28 ) ,
V_146 , F_37 ( V_31 -> V_60 ) ,
F_115 ( V_31 -> V_29 , V_31 -> V_91 ) ,
( V_31 -> V_63 . V_120 - V_64 ) / V_117 , V_22 ) ;
else
#endif
F_114 ( V_131 ,
L_21
L_22 ,
F_35 ( V_31 -> V_29 ) ,
F_113 ( V_31 -> V_25 . V_18 ) , F_37 ( V_31 -> V_26 ) ,
F_113 ( V_31 -> V_27 . V_18 ) , F_37 ( V_31 -> V_28 ) ,
V_146 , F_37 ( V_31 -> V_60 ) ,
F_115 ( V_31 -> V_29 , V_31 -> V_91 ) ,
( V_31 -> V_63 . V_120 - V_64 ) / V_117 , V_22 ) ;
}
return 0 ;
}
static int F_116 ( struct V_151 * V_151 , struct V_152 * V_152 )
{
return F_117 ( V_151 , V_152 , & V_153 ,
sizeof( struct V_134 ) ) ;
}
static const char * F_118 ( unsigned int V_35 )
{
if ( V_35 & V_87 )
return L_23 ;
else
return L_24 ;
}
static int F_119 ( struct V_130 * V_131 , void * V_139 )
{
char V_146 [ V_147 ] ;
if ( V_139 == V_138 )
F_110 ( V_131 ,
L_25 ) ;
else {
const struct V_30 * V_31 = V_139 ;
struct V_143 * V_143 = F_111 ( V_131 ) ;
if ( ! F_112 ( V_31 -> V_6 -> V_143 , V_143 ) )
return 0 ;
#ifdef F_6
if ( V_31 -> V_69 == V_12 )
snprintf ( V_146 , sizeof( V_146 ) , L_17 , & V_31 -> V_54 . V_150 ) ;
else
#endif
snprintf ( V_146 , sizeof( V_146 ) , L_18 ,
F_113 ( V_31 -> V_54 . V_18 ) ) ;
#ifdef F_6
if ( V_31 -> V_7 == V_12 )
F_114 ( V_131 , L_19
L_26 ,
F_35 ( V_31 -> V_29 ) ,
& V_31 -> V_25 . V_150 , F_37 ( V_31 -> V_26 ) ,
& V_31 -> V_27 . V_150 , F_37 ( V_31 -> V_28 ) ,
V_146 , F_37 ( V_31 -> V_60 ) ,
F_115 ( V_31 -> V_29 , V_31 -> V_91 ) ,
F_118 ( V_31 -> V_35 ) ,
( V_31 -> V_63 . V_120 - V_64 ) / V_117 ) ;
else
#endif
F_114 ( V_131 ,
L_27
L_26 ,
F_35 ( V_31 -> V_29 ) ,
F_113 ( V_31 -> V_25 . V_18 ) , F_37 ( V_31 -> V_26 ) ,
F_113 ( V_31 -> V_27 . V_18 ) , F_37 ( V_31 -> V_28 ) ,
V_146 , F_37 ( V_31 -> V_60 ) ,
F_115 ( V_31 -> V_29 , V_31 -> V_91 ) ,
F_118 ( V_31 -> V_35 ) ,
( V_31 -> V_63 . V_120 - V_64 ) / V_117 ) ;
}
return 0 ;
}
static int F_120 ( struct V_151 * V_151 , struct V_152 * V_152 )
{
return F_117 ( V_151 , V_152 , & V_154 ,
sizeof( struct V_134 ) ) ;
}
static inline int F_121 ( struct V_30 * V_31 )
{
static const char V_155 [ 9 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 } ;
static char V_156 [ 9 ] = { 0 } ;
int V_157 ;
if ( F_122 ( V_31 -> V_62 + V_64 , V_31 -> V_63 . V_120 + 60 * V_117 ) )
return 0 ;
V_157 = F_33 ( & V_31 -> V_123 ) ;
if ( V_157 > 8 || V_157 < 0 ) return 0 ;
if ( ! V_155 [ V_157 ] ) return 0 ;
if ( -- V_156 [ V_157 ] > 0 ) return 0 ;
V_156 [ V_157 ] = V_155 [ V_157 ] ;
return 1 ;
}
static inline bool F_123 ( struct V_30 * V_31 )
{
struct V_158 * V_159 ;
if ( ! V_31 -> V_82 )
return false ;
V_159 = F_105 ( V_31 -> V_82 -> V_159 ) ;
return V_159 && ( V_159 -> V_35 & V_160 ) ;
}
void F_124 ( struct V_5 * V_6 )
{
int V_133 ;
struct V_30 * V_31 , * V_161 ;
F_27 () ;
for ( V_133 = 0 ; V_133 < ( V_137 >> 5 ) ; V_133 ++ ) {
unsigned int V_33 = F_125 () & V_17 ;
F_28 (cp, &ip_vs_conn_tab[hash], c_list) {
if ( V_31 -> V_6 != V_6 )
continue;
if ( V_31 -> V_35 & V_59 ) {
if ( F_33 ( & V_31 -> V_111 ) ||
! F_123 ( V_31 ) )
continue;
else
goto V_162;
}
if ( V_31 -> V_29 == V_163 ) {
switch( V_31 -> V_91 ) {
case V_164 :
case V_165 :
break;
case V_166 :
if ( F_121 ( V_31 ) )
break;
continue;
default:
continue;
}
} else if ( V_31 -> V_29 == V_167 ) {
switch ( V_31 -> V_91 ) {
case V_168 :
case V_169 :
break;
case V_170 :
if ( F_121 ( V_31 ) )
break;
continue;
default:
continue;
}
} else {
V_162:
if ( ! F_121 ( V_31 ) )
continue;
}
F_84 ( 4 , L_28 ) ;
F_87 ( V_31 ) ;
V_161 = V_31 -> V_113 ;
if ( V_161 && F_30 ( V_31 ) ) {
F_84 ( 4 , L_29 ) ;
F_87 ( V_161 ) ;
F_47 ( V_31 ) ;
}
}
F_102 () ;
}
F_31 () ;
}
static void F_126 ( struct V_5 * V_6 )
{
int V_133 ;
struct V_30 * V_31 , * V_161 ;
V_171:
F_27 () ;
for ( V_133 = 0 ; V_133 < V_137 ; V_133 ++ ) {
F_28 (cp, &ip_vs_conn_tab[idx], c_list) {
if ( V_31 -> V_6 != V_6 )
continue;
F_84 ( 4 , L_28 ) ;
F_87 ( V_31 ) ;
V_161 = V_31 -> V_113 ;
if ( V_161 && F_30 ( V_31 ) ) {
F_84 ( 4 , L_29 ) ;
F_87 ( V_161 ) ;
F_47 ( V_31 ) ;
}
}
F_102 () ;
}
F_31 () ;
if ( F_33 ( & V_6 -> V_116 ) != 0 ) {
F_127 () ;
goto V_171;
}
}
int T_5 F_128 ( struct V_5 * V_6 )
{
F_99 ( & V_6 -> V_116 , 0 ) ;
F_129 ( L_30 , 0 , V_6 -> V_143 -> V_172 , & V_173 ) ;
F_129 ( L_31 , 0 , V_6 -> V_143 -> V_172 ,
& V_174 ) ;
return 0 ;
}
void T_6 F_130 ( struct V_5 * V_6 )
{
F_126 ( V_6 ) ;
F_131 ( L_30 , V_6 -> V_143 -> V_172 ) ;
F_131 ( L_31 , V_6 -> V_143 -> V_172 ) ;
}
int T_7 F_132 ( void )
{
int V_133 ;
V_137 = 1 << V_175 ;
V_17 = V_137 - 1 ;
V_41 = F_133 ( V_137 * sizeof( * V_41 ) ) ;
if ( ! V_41 )
return - V_176 ;
V_109 = F_134 ( L_30 ,
sizeof( struct V_30 ) , 0 ,
V_177 , NULL ) ;
if ( ! V_109 ) {
F_135 ( V_41 ) ;
return - V_176 ;
}
F_136 ( L_32
L_33 ,
V_137 ,
( long ) ( V_137 * sizeof( struct V_178 ) ) / 1024 ) ;
F_84 ( 0 , L_34 ,
sizeof( struct V_30 ) ) ;
for ( V_133 = 0 ; V_133 < V_137 ; V_133 ++ )
F_137 ( & V_41 [ V_133 ] ) ;
for ( V_133 = 0 ; V_133 < V_179 ; V_133 ++ ) {
F_97 ( & V_2 [ V_133 ] . V_4 ) ;
}
F_138 ( & V_13 , sizeof( V_13 ) ) ;
return 0 ;
}
void F_139 ( void )
{
F_140 () ;
F_141 ( V_109 ) ;
F_135 ( V_41 ) ;
}
