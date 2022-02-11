static inline void F_1 ( unsigned V_1 )
{
F_2 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static inline void F_3 ( unsigned V_1 )
{
F_4 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static inline void F_5 ( unsigned V_1 )
{
F_6 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static inline void F_7 ( unsigned V_1 )
{
F_8 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static inline void F_9 ( unsigned V_1 )
{
F_10 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static inline void F_11 ( unsigned V_1 )
{
F_12 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static inline void F_13 ( unsigned V_1 )
{
F_14 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static inline void F_15 ( unsigned V_1 )
{
F_16 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static unsigned int F_17 ( struct V_5 * V_5 , int V_6 , unsigned V_7 ,
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
unsigned V_32 ;
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
unsigned V_32 ;
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
unsigned V_32 ;
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
unsigned V_32 ;
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
unsigned V_32 ;
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
if ( ! V_82 )
return;
F_29 ( & V_82 -> V_40 ) ;
V_85 = F_41 ( & V_82 -> V_85 ) ;
if ( V_30 -> V_28 != V_86 )
V_85 &= ~ V_35 ;
if ( V_30 -> V_34 & V_87 ) {
if ( ! ( V_30 -> V_34 & V_60 ) )
V_85 &= ~ V_88 ;
V_30 -> V_34 &= ~ V_89 ;
}
V_30 -> V_34 |= V_85 ;
V_30 -> V_82 = V_82 ;
F_42 ( 7 , L_7
L_8
L_9 ,
F_43 ( V_30 -> V_28 ) ,
F_44 ( V_30 -> V_6 , & V_30 -> V_24 ) , F_45 ( V_30 -> V_25 ) ,
F_44 ( V_30 -> V_6 , & V_30 -> V_26 ) , F_45 ( V_30 -> V_27 ) ,
F_44 ( V_30 -> V_6 , & V_30 -> V_55 ) , F_45 ( V_30 -> V_61 ) ,
F_62 ( V_30 ) , V_30 -> V_90 ,
V_30 -> V_34 , F_41 ( & V_30 -> V_40 ) ,
F_41 ( & V_82 -> V_40 ) ) ;
if ( ! ( V_30 -> V_34 & V_60 ) ) {
if ( ( V_30 -> V_34 & V_87 ) &&
( ! ( V_30 -> V_34 & V_88 ) ) )
F_29 ( & V_82 -> V_83 ) ;
else
F_29 ( & V_82 -> V_84 ) ;
} else {
F_29 ( & V_82 -> V_91 ) ;
}
if ( V_82 -> V_92 != 0 &&
F_60 ( V_82 ) >= V_82 -> V_92 )
V_82 -> V_34 |= V_93 ;
}
struct V_81 * F_63 ( struct V_29 * V_30 )
{
struct V_81 * V_82 ;
if ( ( V_30 ) && ( ! V_30 -> V_82 ) ) {
V_82 = F_64 ( F_25 ( V_30 ) , V_30 -> V_6 , & V_30 -> V_55 ,
V_30 -> V_61 , & V_30 -> V_26 , V_30 -> V_27 ,
V_30 -> V_28 , V_30 -> V_94 , V_30 -> V_34 ) ;
F_61 ( V_30 , V_82 ) ;
return V_82 ;
} else
return NULL ;
}
static inline void F_65 ( struct V_29 * V_30 )
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
F_62 ( V_30 ) , V_30 -> V_90 ,
V_30 -> V_34 , F_41 ( & V_30 -> V_40 ) ,
F_41 ( & V_82 -> V_40 ) ) ;
if ( ! ( V_30 -> V_34 & V_60 ) ) {
if ( V_30 -> V_34 & V_88 ) {
F_35 ( & V_82 -> V_84 ) ;
} else {
F_35 ( & V_82 -> V_83 ) ;
}
} else {
F_35 ( & V_82 -> V_91 ) ;
}
if ( V_82 -> V_95 != 0 ) {
if ( F_60 ( V_82 ) < V_82 -> V_95 )
V_82 -> V_34 &= ~ V_93 ;
} else if ( V_82 -> V_92 != 0 ) {
if ( F_60 ( V_82 ) * 4 < V_82 -> V_92 * 3 )
V_82 -> V_34 &= ~ V_93 ;
} else {
if ( V_82 -> V_34 & V_93 )
V_82 -> V_34 &= ~ V_93 ;
}
F_35 ( & V_82 -> V_40 ) ;
}
static int F_66 ( struct V_96 * V_97 ,
struct V_81 * V_82 )
{
#ifdef F_67
return V_97 -> V_98 &&
( F_41 ( & V_82 -> V_99 ) == 0 ) ;
#else
return 0 ;
#endif
}
int F_68 ( struct V_29 * V_100 )
{
struct V_81 * V_82 = V_100 -> V_82 ;
struct V_96 * V_97 = F_69 ( F_25 ( V_100 ) ) ;
if ( ( V_82 == NULL ) ||
! ( V_82 -> V_34 & V_101 ) ||
F_66 ( V_97 , V_82 ) ) {
F_42 ( 9 , L_11
L_12
L_13 ,
F_43 ( V_100 -> V_28 ) ,
F_44 ( V_100 -> V_6 , & V_100 -> V_24 ) ,
F_45 ( V_100 -> V_25 ) ,
F_44 ( V_100 -> V_6 , & V_100 -> V_26 ) ,
F_45 ( V_100 -> V_27 ) ,
F_44 ( V_100 -> V_6 , & V_100 -> V_55 ) ,
F_45 ( V_100 -> V_61 ) ) ;
if ( V_100 -> V_27 != F_70 ( 0xffff ) ) {
if ( F_33 ( V_100 ) ) {
V_100 -> V_61 = F_70 ( 0xffff ) ;
V_100 -> V_27 = F_70 ( 0xffff ) ;
V_100 -> V_25 = 0 ;
F_26 ( V_100 ) ;
}
}
F_35 ( & V_100 -> V_40 ) ;
return 0 ;
}
return 1 ;
}
static void F_71 ( unsigned long V_102 )
{
struct V_29 * V_30 = (struct V_29 * ) V_102 ;
struct V_96 * V_97 = F_69 ( F_25 ( V_30 ) ) ;
V_30 -> V_63 = 60 * V_103 ;
F_29 ( & V_30 -> V_40 ) ;
if ( F_41 ( & V_30 -> V_104 ) )
goto V_105;
if ( ! F_33 ( V_30 ) && ! ( V_30 -> V_34 & V_35 ) )
goto V_105;
if ( F_22 ( F_41 ( & V_30 -> V_40 ) == 1 ) ) {
if ( F_72 ( & V_30 -> V_64 ) )
F_73 ( & V_30 -> V_64 ) ;
if ( V_30 -> V_106 )
F_74 ( V_30 ) ;
if ( V_30 -> V_34 & V_107 ) {
F_75 ( V_30 ) ;
F_76 () ;
if ( V_97 -> V_108 )
F_75 ( V_30 ) ;
}
F_77 ( V_30 -> V_22 ) ;
F_78 ( V_30 -> V_21 ) ;
if ( F_79 ( V_30 -> V_109 != NULL ) )
F_80 ( V_30 ) ;
F_65 ( V_30 ) ;
if ( V_30 -> V_34 & V_44 )
F_35 ( & V_45 ) ;
F_35 ( & V_97 -> V_110 ) ;
F_81 ( V_111 , V_30 ) ;
return;
}
F_26 ( V_30 ) ;
V_105:
F_82 ( 7 , L_14 ,
F_41 ( & V_30 -> V_40 ) - 1 ,
F_41 ( & V_30 -> V_104 ) ) ;
F_53 ( V_30 ) ;
}
void F_83 ( struct V_29 * V_30 )
{
if ( F_73 ( & V_30 -> V_64 ) )
F_54 ( & V_30 -> V_64 , V_65 ) ;
}
struct V_29 *
F_84 ( const struct V_18 * V_19 ,
const union V_8 * V_55 , T_1 V_61 , unsigned V_34 ,
struct V_81 * V_82 , T_2 V_94 )
{
struct V_29 * V_30 ;
struct V_96 * V_97 = F_69 ( V_19 -> V_5 ) ;
struct V_112 * V_113 = F_85 ( V_19 -> V_5 ,
V_19 -> V_28 ) ;
V_30 = F_86 ( V_111 , V_114 ) ;
if ( V_30 == NULL ) {
F_87 ( L_15 , V_41 ) ;
return NULL ;
}
F_88 ( & V_30 -> V_38 ) ;
F_89 ( & V_30 -> V_64 , F_71 , ( unsigned long ) V_30 ) ;
F_90 ( V_30 , V_19 -> V_5 ) ;
V_30 -> V_6 = V_19 -> V_6 ;
V_30 -> V_28 = V_19 -> V_28 ;
F_91 ( V_19 -> V_6 , & V_30 -> V_24 , V_19 -> V_24 ) ;
V_30 -> V_25 = V_19 -> V_25 ;
F_91 ( V_19 -> V_6 , & V_30 -> V_26 , V_19 -> V_26 ) ;
V_30 -> V_27 = V_19 -> V_27 ;
F_91 ( V_19 -> V_28 == V_58 ? V_59 : V_19 -> V_6 ,
& V_30 -> V_55 , V_55 ) ;
V_30 -> V_61 = V_61 ;
V_30 -> V_34 = V_34 ;
V_30 -> V_94 = V_94 ;
if ( V_34 & V_60 && V_19 -> V_22 ) {
F_92 ( V_19 -> V_22 ) ;
V_30 -> V_22 = V_19 -> V_22 ;
V_30 -> V_21 = V_19 -> V_21 ;
V_30 -> V_31 = V_19 -> V_31 ;
}
F_93 ( & V_30 -> V_36 ) ;
F_94 ( & V_30 -> V_40 , 1 ) ;
F_94 ( & V_30 -> V_104 , 0 ) ;
F_94 ( & V_30 -> V_115 , 0 ) ;
F_29 ( & V_97 -> V_110 ) ;
if ( V_34 & V_44 )
F_29 ( & V_45 ) ;
F_61 ( V_30 , V_82 ) ;
V_30 -> V_90 = 0 ;
V_30 -> V_63 = 3 * V_103 ;
#ifdef F_18
if ( V_19 -> V_6 == V_11 )
F_59 ( V_30 ) ;
else
#endif
F_57 ( V_30 ) ;
if ( F_79 ( V_113 && F_41 ( & V_113 -> V_116 ) ) )
F_95 ( V_30 , V_113 -> V_117 ) ;
if ( F_96 ( V_97 ) )
V_30 -> V_34 |= V_107 ;
F_26 ( V_30 ) ;
return V_30 ;
}
static void * F_97 ( struct V_118 * V_119 , T_3 V_120 )
{
int V_121 ;
struct V_29 * V_30 ;
struct V_122 * V_123 = V_119 -> V_124 ;
struct V_42 * V_43 ;
for ( V_121 = 0 ; V_121 < V_125 ; V_121 ++ ) {
F_9 ( V_121 ) ;
F_37 (cp, n, &ip_vs_conn_tab[idx], c_list) {
if ( V_120 -- == 0 ) {
V_123 -> V_4 = & V_39 [ V_121 ] ;
return V_30 ;
}
}
F_11 ( V_121 ) ;
}
return NULL ;
}
static void * F_98 ( struct V_118 * V_119 , T_3 * V_120 )
{
struct V_122 * V_123 = V_119 -> V_124 ;
V_123 -> V_4 = NULL ;
return * V_120 ? F_97 ( V_119 , * V_120 - 1 ) : V_126 ;
}
static void * F_99 ( struct V_118 * V_119 , void * V_127 , T_3 * V_120 )
{
struct V_29 * V_30 = V_127 ;
struct V_122 * V_123 = V_119 -> V_124 ;
struct V_42 * V_128 ;
struct V_129 * V_4 = V_123 -> V_4 ;
int V_121 ;
++ * V_120 ;
if ( V_127 == V_126 )
return F_97 ( V_119 , 0 ) ;
if ( ( V_128 = V_30 -> V_38 . V_130 ) )
return F_100 ( V_128 , struct V_29 , V_38 ) ;
V_121 = V_4 - V_39 ;
F_11 ( V_121 ) ;
while ( ++ V_121 < V_125 ) {
F_9 ( V_121 ) ;
F_37 (cp, e, &ip_vs_conn_tab[idx], c_list) {
V_123 -> V_4 = & V_39 [ V_121 ] ;
return V_30 ;
}
F_11 ( V_121 ) ;
}
V_123 -> V_4 = NULL ;
return NULL ;
}
static void F_101 ( struct V_118 * V_119 , void * V_127 )
{
struct V_122 * V_123 = V_119 -> V_124 ;
struct V_129 * V_4 = V_123 -> V_4 ;
if ( V_4 )
F_11 ( V_4 - V_39 ) ;
}
static int F_102 ( struct V_118 * V_119 , void * V_127 )
{
if ( V_127 == V_126 )
F_103 ( V_119 ,
L_16 ) ;
else {
const struct V_29 * V_30 = V_127 ;
struct V_5 * V_5 = F_104 ( V_119 ) ;
char V_21 [ V_131 + V_132 + 3 ] ;
V_15 V_133 = 0 ;
if ( ! F_39 ( V_30 , V_5 ) )
return 0 ;
if ( V_30 -> V_21 ) {
V_21 [ 0 ] = ' ' ;
V_133 = strlen ( V_30 -> V_22 -> V_134 ) ;
memcpy ( V_21 + 1 , V_30 -> V_22 -> V_134 , V_133 ) ;
V_21 [ V_133 + 1 ] = ' ' ;
V_133 += 2 ;
V_133 += V_30 -> V_22 -> V_135 ( V_30 , V_21 + V_133 ) ;
}
V_21 [ V_133 ] = '\0' ;
#ifdef F_18
if ( V_30 -> V_6 == V_11 )
F_105 ( V_119 , L_17
L_18 ,
F_43 ( V_30 -> V_28 ) ,
& V_30 -> V_24 . V_136 , F_45 ( V_30 -> V_25 ) ,
& V_30 -> V_26 . V_136 , F_45 ( V_30 -> V_27 ) ,
& V_30 -> V_55 . V_136 , F_45 ( V_30 -> V_61 ) ,
F_106 ( V_30 -> V_28 , V_30 -> V_90 ) ,
( V_30 -> V_64 . V_137 - V_65 ) / V_103 , V_21 ) ;
else
#endif
F_105 ( V_119 ,
L_19
L_20 ,
F_43 ( V_30 -> V_28 ) ,
F_107 ( V_30 -> V_24 . V_17 ) , F_45 ( V_30 -> V_25 ) ,
F_107 ( V_30 -> V_26 . V_17 ) , F_45 ( V_30 -> V_27 ) ,
F_107 ( V_30 -> V_55 . V_17 ) , F_45 ( V_30 -> V_61 ) ,
F_106 ( V_30 -> V_28 , V_30 -> V_90 ) ,
( V_30 -> V_64 . V_137 - V_65 ) / V_103 , V_21 ) ;
}
return 0 ;
}
static int F_108 ( struct V_138 * V_138 , struct V_139 * V_139 )
{
return F_109 ( V_138 , V_139 , & V_140 ,
sizeof( struct V_122 ) ) ;
}
static const char * F_110 ( unsigned V_34 )
{
if ( V_34 & V_87 )
return L_21 ;
else
return L_22 ;
}
static int F_111 ( struct V_118 * V_119 , void * V_127 )
{
if ( V_127 == V_126 )
F_103 ( V_119 ,
L_23 ) ;
else {
const struct V_29 * V_30 = V_127 ;
struct V_5 * V_5 = F_104 ( V_119 ) ;
if ( ! F_39 ( V_30 , V_5 ) )
return 0 ;
#ifdef F_18
if ( V_30 -> V_6 == V_11 )
F_105 ( V_119 , L_24 ,
F_43 ( V_30 -> V_28 ) ,
& V_30 -> V_24 . V_136 , F_45 ( V_30 -> V_25 ) ,
& V_30 -> V_26 . V_136 , F_45 ( V_30 -> V_27 ) ,
& V_30 -> V_55 . V_136 , F_45 ( V_30 -> V_61 ) ,
F_106 ( V_30 -> V_28 , V_30 -> V_90 ) ,
F_110 ( V_30 -> V_34 ) ,
( V_30 -> V_64 . V_137 - V_65 ) / V_103 ) ;
else
#endif
F_105 ( V_119 ,
L_25
L_26 ,
F_43 ( V_30 -> V_28 ) ,
F_107 ( V_30 -> V_24 . V_17 ) , F_45 ( V_30 -> V_25 ) ,
F_107 ( V_30 -> V_26 . V_17 ) , F_45 ( V_30 -> V_27 ) ,
F_107 ( V_30 -> V_55 . V_17 ) , F_45 ( V_30 -> V_61 ) ,
F_106 ( V_30 -> V_28 , V_30 -> V_90 ) ,
F_110 ( V_30 -> V_34 ) ,
( V_30 -> V_64 . V_137 - V_65 ) / V_103 ) ;
}
return 0 ;
}
static int F_112 ( struct V_138 * V_138 , struct V_139 * V_139 )
{
return F_109 ( V_138 , V_139 , & V_141 ,
sizeof( struct V_122 ) ) ;
}
static inline int F_113 ( struct V_29 * V_30 )
{
static const char V_142 [ 9 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 } ;
static char V_143 [ 9 ] = { 0 } ;
int V_144 ;
if ( F_114 ( V_30 -> V_63 + V_65 , V_30 -> V_64 . V_137 + 60 * V_103 ) )
return 0 ;
V_144 = F_41 ( & V_30 -> V_115 ) ;
if ( V_144 > 8 || V_144 < 0 ) return 0 ;
if ( ! V_142 [ V_144 ] ) return 0 ;
if ( -- V_143 [ V_144 ] > 0 ) return 0 ;
V_143 [ V_144 ] = V_142 [ V_144 ] ;
return 1 ;
}
void F_115 ( struct V_5 * V_5 )
{
int V_121 ;
struct V_29 * V_30 ;
for ( V_121 = 0 ; V_121 < ( V_125 >> 5 ) ; V_121 ++ ) {
unsigned V_32 = F_116 () & V_16 ;
struct V_42 * V_43 ;
F_13 ( V_32 ) ;
F_37 (cp, n, &ip_vs_conn_tab[hash], c_list) {
if ( V_30 -> V_34 & V_60 )
continue;
if ( ! F_39 ( V_30 , V_5 ) )
continue;
if ( V_30 -> V_28 == V_145 ) {
switch( V_30 -> V_90 ) {
case V_146 :
case V_147 :
break;
case V_148 :
if ( F_113 ( V_30 ) )
break;
continue;
default:
continue;
}
} else {
if ( ! F_113 ( V_30 ) )
continue;
}
F_82 ( 4 , L_27 ) ;
F_83 ( V_30 ) ;
if ( V_30 -> V_106 ) {
F_82 ( 4 , L_28 ) ;
F_83 ( V_30 -> V_106 ) ;
}
}
F_15 ( V_32 ) ;
}
}
static void F_117 ( struct V_5 * V_5 )
{
int V_121 ;
struct V_29 * V_30 ;
struct V_96 * V_97 = F_69 ( V_5 ) ;
V_149:
for ( V_121 = 0 ; V_121 < V_125 ; V_121 ++ ) {
struct V_42 * V_43 ;
F_13 ( V_121 ) ;
F_37 (cp, n, &ip_vs_conn_tab[idx], c_list) {
if ( ! F_39 ( V_30 , V_5 ) )
continue;
F_82 ( 4 , L_27 ) ;
F_83 ( V_30 ) ;
if ( V_30 -> V_106 ) {
F_82 ( 4 , L_28 ) ;
F_83 ( V_30 -> V_106 ) ;
}
}
F_15 ( V_121 ) ;
}
if ( F_41 ( & V_97 -> V_110 ) != 0 ) {
F_118 () ;
goto V_149;
}
}
int T_4 F_119 ( struct V_5 * V_5 )
{
struct V_96 * V_97 = F_69 ( V_5 ) ;
F_94 ( & V_97 -> V_110 , 0 ) ;
F_120 ( V_5 , L_29 , 0 , & V_150 ) ;
F_120 ( V_5 , L_30 , 0 , & V_151 ) ;
return 0 ;
}
void T_5 F_121 ( struct V_5 * V_5 )
{
F_117 ( V_5 ) ;
F_122 ( V_5 , L_29 ) ;
F_122 ( V_5 , L_30 ) ;
}
int T_6 F_123 ( void )
{
int V_121 ;
V_125 = 1 << V_152 ;
V_16 = V_125 - 1 ;
V_39 = F_124 ( V_125 * sizeof( * V_39 ) ) ;
if ( ! V_39 )
return - V_153 ;
V_111 = F_125 ( L_29 ,
sizeof( struct V_29 ) , 0 ,
V_154 , NULL ) ;
if ( ! V_111 ) {
F_126 ( V_39 ) ;
return - V_153 ;
}
F_127 ( L_31
L_32 ,
V_125 ,
( long ) ( V_125 * sizeof( struct V_155 ) ) / 1024 ) ;
F_82 ( 0 , L_33 ,
sizeof( struct V_29 ) ) ;
for ( V_121 = 0 ; V_121 < V_125 ; V_121 ++ )
F_128 ( & V_39 [ V_121 ] ) ;
for ( V_121 = 0 ; V_121 < V_156 ; V_121 ++ ) {
F_129 ( & V_2 [ V_121 ] . V_4 ) ;
}
F_130 ( & V_12 , sizeof( V_12 ) ) ;
return 0 ;
}
void F_131 ( void )
{
F_132 ( V_111 ) ;
F_126 ( V_39 ) ;
}
