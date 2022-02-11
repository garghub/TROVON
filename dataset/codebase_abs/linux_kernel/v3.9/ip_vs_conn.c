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
V_32 = F_21 ( V_19 , false ) ;
F_1 ( V_32 ) ;
F_37 (cp, &ip_vs_conn_tab[hash], c_list) {
if ( V_30 -> V_6 == V_19 -> V_6 &&
V_19 -> V_25 == V_30 -> V_25 && V_19 -> V_27 == V_30 -> V_27 &&
F_38 ( V_19 -> V_6 , V_19 -> V_24 , & V_30 -> V_24 ) &&
F_38 ( V_19 -> V_6 , V_19 -> V_26 , & V_30 -> V_26 ) &&
( ( ! V_19 -> V_25 ) ^ ( ! ( V_30 -> V_34 & V_42 ) ) ) &&
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
if ( ! V_30 && F_41 ( & V_43 ) ) {
struct V_18 V_44 = * V_19 ;
V_44 . V_25 = 0 ;
V_30 = F_36 ( & V_44 ) ;
}
F_42 ( 9 , L_2 ,
F_43 ( V_19 -> V_28 ) ,
F_44 ( V_19 -> V_6 , V_19 -> V_24 ) , F_45 ( V_19 -> V_25 ) ,
F_44 ( V_19 -> V_6 , V_19 -> V_26 ) , F_45 ( V_19 -> V_27 ) ,
V_30 ? L_3 : L_4 ) ;
return V_30 ;
}
static int
F_46 ( int V_6 , const struct V_45 * V_46 ,
const struct V_47 * V_48 ,
int V_20 , struct V_18 * V_19 )
{
T_1 V_49 [ 2 ] , * V_50 ;
struct V_5 * V_5 = F_47 ( V_46 ) ;
V_50 = F_48 ( V_46 , V_48 -> V_51 , sizeof( V_49 ) , V_49 , V_48 ) ;
if ( V_50 == NULL )
return 1 ;
if ( F_22 ( ! V_20 ) )
F_24 ( V_5 , V_6 , V_48 -> V_28 , & V_48 -> V_52 ,
V_50 [ 0 ] , & V_48 -> V_53 , V_50 [ 1 ] , V_19 ) ;
else
F_24 ( V_5 , V_6 , V_48 -> V_28 , & V_48 -> V_53 ,
V_50 [ 1 ] , & V_48 -> V_52 , V_50 [ 0 ] , V_19 ) ;
return 0 ;
}
struct V_29 *
F_49 ( int V_6 , const struct V_45 * V_46 ,
const struct V_47 * V_48 , int V_20 )
{
struct V_18 V_19 ;
if ( F_46 ( V_6 , V_46 , V_48 , V_20 , & V_19 ) )
return NULL ;
return F_40 ( & V_19 ) ;
}
struct V_29 * F_50 ( const struct V_18 * V_19 )
{
unsigned int V_32 ;
struct V_29 * V_30 ;
V_32 = F_21 ( V_19 , false ) ;
F_1 ( V_32 ) ;
F_37 (cp, &ip_vs_conn_tab[hash], c_list) {
if ( ! F_39 ( V_30 , V_19 -> V_5 ) )
continue;
if ( V_19 -> V_21 && V_19 -> V_22 -> V_54 ) {
if ( V_19 -> V_22 == V_30 -> V_22 && V_19 -> V_22 -> V_54 ( V_19 , V_30 ) )
goto V_55;
continue;
}
if ( V_30 -> V_6 == V_19 -> V_6 &&
F_38 ( V_19 -> V_6 , V_19 -> V_24 , & V_30 -> V_24 ) &&
F_38 ( V_19 -> V_28 == V_56 ? V_57 :
V_19 -> V_6 , V_19 -> V_26 , & V_30 -> V_26 ) &&
V_19 -> V_25 == V_30 -> V_25 && V_19 -> V_27 == V_30 -> V_27 &&
V_30 -> V_34 & V_58 &&
V_19 -> V_28 == V_30 -> V_28 )
goto V_55;
}
V_30 = NULL ;
V_55:
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
V_32 = F_21 ( V_19 , true ) ;
F_1 ( V_32 ) ;
F_37 (cp, &ip_vs_conn_tab[hash], c_list) {
if ( V_30 -> V_6 == V_19 -> V_6 &&
V_19 -> V_27 == V_30 -> V_25 && V_19 -> V_25 == V_30 -> V_59 &&
F_38 ( V_19 -> V_6 , V_19 -> V_26 , & V_30 -> V_24 ) &&
F_38 ( V_19 -> V_6 , V_19 -> V_24 , & V_30 -> V_53 ) &&
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
F_52 ( int V_6 , const struct V_45 * V_46 ,
const struct V_47 * V_48 , int V_20 )
{
struct V_18 V_19 ;
if ( F_46 ( V_6 , V_46 , V_48 , V_20 , & V_19 ) )
return NULL ;
return F_51 ( & V_19 ) ;
}
void F_53 ( struct V_29 * V_30 )
{
unsigned long V_60 = ( V_30 -> V_34 & V_35 ) ?
0 : V_30 -> V_61 ;
F_54 ( & V_30 -> V_62 , V_63 + V_60 ) ;
F_55 ( V_30 ) ;
}
void F_56 ( struct V_29 * V_30 , T_1 V_25 )
{
if ( F_33 ( V_30 ) ) {
F_27 ( & V_30 -> V_36 ) ;
if ( V_30 -> V_34 & V_42 ) {
F_35 ( & V_43 ) ;
V_30 -> V_34 &= ~ V_42 ;
V_30 -> V_25 = V_25 ;
}
F_32 ( & V_30 -> V_36 ) ;
F_26 ( V_30 ) ;
}
}
static inline void F_57 ( struct V_29 * V_30 )
{
switch ( F_58 ( V_30 ) ) {
case V_64 :
V_30 -> V_65 = V_66 ;
break;
case V_67 :
V_30 -> V_65 = V_68 ;
break;
case V_69 :
V_30 -> V_65 = V_70 ;
break;
case V_71 :
V_30 -> V_65 = V_72 ;
break;
case V_73 :
V_30 -> V_65 = V_74 ;
break;
}
}
static inline void F_59 ( struct V_29 * V_30 )
{
switch ( F_58 ( V_30 ) ) {
case V_64 :
V_30 -> V_65 = V_75 ;
break;
case V_67 :
V_30 -> V_65 = V_76 ;
break;
case V_69 :
V_30 -> V_65 = V_77 ;
break;
case V_71 :
V_30 -> V_65 = V_72 ;
break;
case V_73 :
V_30 -> V_65 = V_78 ;
break;
}
}
static inline int F_60 ( struct V_79 * V_80 )
{
return F_41 ( & V_80 -> V_81 )
+ F_41 ( & V_80 -> V_82 ) ;
}
static inline void
F_61 ( struct V_29 * V_30 , struct V_79 * V_80 )
{
unsigned int V_83 ;
T_2 V_34 ;
if ( ! V_80 )
return;
F_29 ( & V_80 -> V_40 ) ;
V_83 = F_41 ( & V_80 -> V_83 ) ;
if ( V_30 -> V_28 != V_84 )
V_83 &= ~ V_35 ;
V_34 = V_30 -> V_34 ;
if ( V_34 & V_85 ) {
if ( ! ( V_34 & V_58 ) )
V_83 &= ~ V_86 ;
V_34 &= ~ ( V_87 | V_88 ) ;
}
V_34 |= V_83 ;
V_30 -> V_34 = V_34 ;
V_30 -> V_80 = V_80 ;
F_42 ( 7 , L_7
L_8
L_9 ,
F_43 ( V_30 -> V_28 ) ,
F_44 ( V_30 -> V_6 , & V_30 -> V_24 ) , F_45 ( V_30 -> V_25 ) ,
F_44 ( V_30 -> V_6 , & V_30 -> V_26 ) , F_45 ( V_30 -> V_27 ) ,
F_44 ( V_30 -> V_6 , & V_30 -> V_53 ) , F_45 ( V_30 -> V_59 ) ,
F_62 ( V_30 ) , V_30 -> V_89 ,
V_30 -> V_34 , F_41 ( & V_30 -> V_40 ) ,
F_41 ( & V_80 -> V_40 ) ) ;
if ( ! ( V_34 & V_58 ) ) {
if ( ! ( V_34 & V_86 ) )
F_29 ( & V_80 -> V_81 ) ;
else
F_29 ( & V_80 -> V_82 ) ;
} else {
F_29 ( & V_80 -> V_90 ) ;
}
if ( V_80 -> V_91 != 0 &&
F_60 ( V_80 ) >= V_80 -> V_91 )
V_80 -> V_34 |= V_92 ;
}
struct V_79 * F_63 ( struct V_29 * V_30 )
{
struct V_79 * V_80 ;
V_80 = F_64 ( F_25 ( V_30 ) , V_30 -> V_6 , & V_30 -> V_53 ,
V_30 -> V_59 , & V_30 -> V_26 , V_30 -> V_27 ,
V_30 -> V_28 , V_30 -> V_93 , V_30 -> V_34 ) ;
if ( V_80 ) {
struct V_94 * V_95 ;
F_27 ( & V_30 -> V_36 ) ;
if ( V_30 -> V_80 ) {
F_32 ( & V_30 -> V_36 ) ;
return V_80 ;
}
if ( V_30 -> V_96 )
F_65 ( V_30 ) ;
F_61 ( V_30 , V_80 ) ;
F_32 ( & V_30 -> V_36 ) ;
V_30 -> V_65 = NULL ;
#ifdef F_18
if ( V_30 -> V_6 == V_11 )
F_59 ( V_30 ) ;
else
#endif
F_57 ( V_30 ) ;
V_95 = F_66 ( F_25 ( V_30 ) , V_30 -> V_28 ) ;
if ( V_95 && F_41 ( & V_95 -> V_97 ) )
F_67 ( V_30 , V_95 -> V_98 ) ;
}
return V_80 ;
}
static inline void F_68 ( struct V_29 * V_30 )
{
struct V_79 * V_80 = V_30 -> V_80 ;
if ( ! V_80 )
return;
F_42 ( 7 , L_10
L_8
L_9 ,
F_43 ( V_30 -> V_28 ) ,
F_44 ( V_30 -> V_6 , & V_30 -> V_24 ) , F_45 ( V_30 -> V_25 ) ,
F_44 ( V_30 -> V_6 , & V_30 -> V_26 ) , F_45 ( V_30 -> V_27 ) ,
F_44 ( V_30 -> V_6 , & V_30 -> V_53 ) , F_45 ( V_30 -> V_59 ) ,
F_62 ( V_30 ) , V_30 -> V_89 ,
V_30 -> V_34 , F_41 ( & V_30 -> V_40 ) ,
F_41 ( & V_80 -> V_40 ) ) ;
if ( ! ( V_30 -> V_34 & V_58 ) ) {
if ( V_30 -> V_34 & V_86 ) {
F_35 ( & V_80 -> V_82 ) ;
} else {
F_35 ( & V_80 -> V_81 ) ;
}
} else {
F_35 ( & V_80 -> V_90 ) ;
}
if ( V_80 -> V_99 != 0 ) {
if ( F_60 ( V_80 ) < V_80 -> V_99 )
V_80 -> V_34 &= ~ V_92 ;
} else if ( V_80 -> V_91 != 0 ) {
if ( F_60 ( V_80 ) * 4 < V_80 -> V_91 * 3 )
V_80 -> V_34 &= ~ V_92 ;
} else {
if ( V_80 -> V_34 & V_92 )
V_80 -> V_34 &= ~ V_92 ;
}
F_35 ( & V_80 -> V_40 ) ;
}
static int F_69 ( struct V_100 * V_101 ,
struct V_79 * V_80 )
{
#ifdef F_70
return V_101 -> V_102 &&
( F_41 ( & V_80 -> V_103 ) == 0 ) ;
#else
return 0 ;
#endif
}
int F_71 ( struct V_29 * V_104 )
{
struct V_79 * V_80 = V_104 -> V_80 ;
struct V_100 * V_101 = F_72 ( F_25 ( V_104 ) ) ;
if ( ( V_80 == NULL ) ||
! ( V_80 -> V_34 & V_105 ) ||
F_69 ( V_101 , V_80 ) ) {
F_42 ( 9 , L_11
L_12
L_13 ,
F_43 ( V_104 -> V_28 ) ,
F_44 ( V_104 -> V_6 , & V_104 -> V_24 ) ,
F_45 ( V_104 -> V_25 ) ,
F_44 ( V_104 -> V_6 , & V_104 -> V_26 ) ,
F_45 ( V_104 -> V_27 ) ,
F_44 ( V_104 -> V_6 , & V_104 -> V_53 ) ,
F_45 ( V_104 -> V_59 ) ) ;
if ( V_104 -> V_27 != F_73 ( 0xffff ) ) {
if ( F_33 ( V_104 ) ) {
V_104 -> V_59 = F_73 ( 0xffff ) ;
V_104 -> V_27 = F_73 ( 0xffff ) ;
V_104 -> V_25 = 0 ;
F_26 ( V_104 ) ;
}
}
F_35 ( & V_104 -> V_40 ) ;
return 0 ;
}
return 1 ;
}
static void F_74 ( unsigned long V_106 )
{
struct V_29 * V_30 = (struct V_29 * ) V_106 ;
struct V_5 * V_5 = F_25 ( V_30 ) ;
struct V_100 * V_101 = F_72 ( V_5 ) ;
V_30 -> V_61 = 60 * V_107 ;
F_29 ( & V_30 -> V_40 ) ;
if ( F_41 ( & V_30 -> V_108 ) )
goto V_109;
if ( ! F_33 ( V_30 ) && ! ( V_30 -> V_34 & V_35 ) )
goto V_109;
if ( F_22 ( F_41 ( & V_30 -> V_40 ) == 1 ) ) {
F_75 ( & V_30 -> V_62 ) ;
if ( V_30 -> V_110 )
F_76 ( V_30 ) ;
if ( V_30 -> V_34 & V_111 ) {
F_77 ( V_30 ) ;
F_78 () ;
if ( V_101 -> V_112 )
F_77 ( V_30 ) ;
}
F_79 ( V_30 -> V_22 ) ;
F_80 ( V_30 -> V_21 ) ;
if ( F_81 ( V_30 -> V_96 != NULL ) )
F_65 ( V_30 ) ;
F_68 ( V_30 ) ;
if ( V_30 -> V_34 & V_42 )
F_35 ( & V_43 ) ;
F_35 ( & V_101 -> V_113 ) ;
F_82 ( V_114 , V_30 ) ;
return;
}
F_26 ( V_30 ) ;
V_109:
F_83 ( 7 , L_14 ,
F_41 ( & V_30 -> V_40 ) - 1 ,
F_41 ( & V_30 -> V_108 ) ) ;
if ( V_101 -> V_115 & V_116 )
F_84 ( V_5 , V_30 , F_85 ( V_101 ) ) ;
F_53 ( V_30 ) ;
}
void F_86 ( struct V_29 * V_30 )
{
if ( F_75 ( & V_30 -> V_62 ) )
F_54 ( & V_30 -> V_62 , V_63 ) ;
}
struct V_29 *
F_87 ( const struct V_18 * V_19 ,
const union V_8 * V_53 , T_1 V_59 , unsigned int V_34 ,
struct V_79 * V_80 , T_2 V_93 )
{
struct V_29 * V_30 ;
struct V_100 * V_101 = F_72 ( V_19 -> V_5 ) ;
struct V_94 * V_95 = F_66 ( V_19 -> V_5 ,
V_19 -> V_28 ) ;
V_30 = F_88 ( V_114 , V_117 ) ;
if ( V_30 == NULL ) {
F_89 ( L_15 , V_41 ) ;
return NULL ;
}
F_90 ( & V_30 -> V_38 ) ;
F_91 ( & V_30 -> V_62 , F_74 , ( unsigned long ) V_30 ) ;
F_92 ( V_30 , V_19 -> V_5 ) ;
V_30 -> V_6 = V_19 -> V_6 ;
V_30 -> V_28 = V_19 -> V_28 ;
F_93 ( V_19 -> V_6 , & V_30 -> V_24 , V_19 -> V_24 ) ;
V_30 -> V_25 = V_19 -> V_25 ;
F_93 ( V_19 -> V_6 , & V_30 -> V_26 , V_19 -> V_26 ) ;
V_30 -> V_27 = V_19 -> V_27 ;
F_93 ( V_19 -> V_28 == V_56 ? V_57 : V_19 -> V_6 ,
& V_30 -> V_53 , V_53 ) ;
V_30 -> V_59 = V_59 ;
V_30 -> V_34 = V_34 ;
V_30 -> V_93 = V_93 ;
if ( V_34 & V_58 && V_19 -> V_22 ) {
F_94 ( V_19 -> V_22 ) ;
V_30 -> V_22 = V_19 -> V_22 ;
V_30 -> V_21 = V_19 -> V_21 ;
V_30 -> V_31 = V_19 -> V_31 ;
}
F_95 ( & V_30 -> V_36 ) ;
F_96 ( & V_30 -> V_40 , 1 ) ;
F_96 ( & V_30 -> V_108 , 0 ) ;
F_96 ( & V_30 -> V_118 , 0 ) ;
F_29 ( & V_101 -> V_113 ) ;
if ( V_34 & V_42 )
F_29 ( & V_43 ) ;
F_61 ( V_30 , V_80 ) ;
V_30 -> V_89 = 0 ;
V_30 -> V_61 = 3 * V_107 ;
V_30 -> V_119 = V_63 & ~ 3UL ;
#ifdef F_18
if ( V_19 -> V_6 == V_11 )
F_59 ( V_30 ) ;
else
#endif
F_57 ( V_30 ) ;
if ( F_81 ( V_95 && F_41 ( & V_95 -> V_97 ) ) )
F_67 ( V_30 , V_95 -> V_98 ) ;
if ( F_97 ( V_101 ) )
V_30 -> V_34 |= V_111 ;
F_26 ( V_30 ) ;
return V_30 ;
}
static void * F_98 ( struct V_120 * V_121 , T_3 V_122 )
{
int V_123 ;
struct V_29 * V_30 ;
struct V_124 * V_125 = V_121 -> V_126 ;
for ( V_123 = 0 ; V_123 < V_127 ; V_123 ++ ) {
F_9 ( V_123 ) ;
F_37 (cp, &ip_vs_conn_tab[idx], c_list) {
if ( V_122 -- == 0 ) {
V_125 -> V_4 = & V_39 [ V_123 ] ;
return V_30 ;
}
}
F_11 ( V_123 ) ;
}
return NULL ;
}
static void * F_99 ( struct V_120 * V_121 , T_3 * V_122 )
{
struct V_124 * V_125 = V_121 -> V_126 ;
V_125 -> V_4 = NULL ;
return * V_122 ? F_98 ( V_121 , * V_122 - 1 ) : V_128 ;
}
static void * F_100 ( struct V_120 * V_121 , void * V_129 , T_3 * V_122 )
{
struct V_29 * V_30 = V_129 ;
struct V_124 * V_125 = V_121 -> V_126 ;
struct V_130 * V_4 = V_125 -> V_4 ;
int V_123 ;
++ * V_122 ;
if ( V_129 == V_128 )
return F_98 ( V_121 , 0 ) ;
if ( V_30 -> V_38 . V_131 )
return F_101 ( V_30 -> V_38 . V_131 , struct V_29 , V_38 ) ;
V_123 = V_4 - V_39 ;
F_11 ( V_123 ) ;
while ( ++ V_123 < V_127 ) {
F_9 ( V_123 ) ;
F_37 (cp, &ip_vs_conn_tab[idx], c_list) {
V_125 -> V_4 = & V_39 [ V_123 ] ;
return V_30 ;
}
F_11 ( V_123 ) ;
}
V_125 -> V_4 = NULL ;
return NULL ;
}
static void F_102 ( struct V_120 * V_121 , void * V_129 )
{
struct V_124 * V_125 = V_121 -> V_126 ;
struct V_130 * V_4 = V_125 -> V_4 ;
if ( V_4 )
F_11 ( V_4 - V_39 ) ;
}
static int F_103 ( struct V_120 * V_121 , void * V_129 )
{
if ( V_129 == V_128 )
F_104 ( V_121 ,
L_16 ) ;
else {
const struct V_29 * V_30 = V_129 ;
struct V_5 * V_5 = F_105 ( V_121 ) ;
char V_21 [ V_132 + V_133 + 3 ] ;
V_15 V_51 = 0 ;
if ( ! F_39 ( V_30 , V_5 ) )
return 0 ;
if ( V_30 -> V_21 ) {
V_21 [ 0 ] = ' ' ;
V_51 = strlen ( V_30 -> V_22 -> V_134 ) ;
memcpy ( V_21 + 1 , V_30 -> V_22 -> V_134 , V_51 ) ;
V_21 [ V_51 + 1 ] = ' ' ;
V_51 += 2 ;
V_51 += V_30 -> V_22 -> V_135 ( V_30 , V_21 + V_51 ) ;
}
V_21 [ V_51 ] = '\0' ;
#ifdef F_18
if ( V_30 -> V_6 == V_11 )
F_106 ( V_121 , L_17
L_18 ,
F_43 ( V_30 -> V_28 ) ,
& V_30 -> V_24 . V_136 , F_45 ( V_30 -> V_25 ) ,
& V_30 -> V_26 . V_136 , F_45 ( V_30 -> V_27 ) ,
& V_30 -> V_53 . V_136 , F_45 ( V_30 -> V_59 ) ,
F_107 ( V_30 -> V_28 , V_30 -> V_89 ) ,
( V_30 -> V_62 . V_137 - V_63 ) / V_107 , V_21 ) ;
else
#endif
F_106 ( V_121 ,
L_19
L_20 ,
F_43 ( V_30 -> V_28 ) ,
F_108 ( V_30 -> V_24 . V_17 ) , F_45 ( V_30 -> V_25 ) ,
F_108 ( V_30 -> V_26 . V_17 ) , F_45 ( V_30 -> V_27 ) ,
F_108 ( V_30 -> V_53 . V_17 ) , F_45 ( V_30 -> V_59 ) ,
F_107 ( V_30 -> V_28 , V_30 -> V_89 ) ,
( V_30 -> V_62 . V_137 - V_63 ) / V_107 , V_21 ) ;
}
return 0 ;
}
static int F_109 ( struct V_138 * V_138 , struct V_139 * V_139 )
{
return F_110 ( V_138 , V_139 , & V_140 ,
sizeof( struct V_124 ) ) ;
}
static const char * F_111 ( unsigned int V_34 )
{
if ( V_34 & V_85 )
return L_21 ;
else
return L_22 ;
}
static int F_112 ( struct V_120 * V_121 , void * V_129 )
{
if ( V_129 == V_128 )
F_104 ( V_121 ,
L_23 ) ;
else {
const struct V_29 * V_30 = V_129 ;
struct V_5 * V_5 = F_105 ( V_121 ) ;
if ( ! F_39 ( V_30 , V_5 ) )
return 0 ;
#ifdef F_18
if ( V_30 -> V_6 == V_11 )
F_106 ( V_121 , L_24 ,
F_43 ( V_30 -> V_28 ) ,
& V_30 -> V_24 . V_136 , F_45 ( V_30 -> V_25 ) ,
& V_30 -> V_26 . V_136 , F_45 ( V_30 -> V_27 ) ,
& V_30 -> V_53 . V_136 , F_45 ( V_30 -> V_59 ) ,
F_107 ( V_30 -> V_28 , V_30 -> V_89 ) ,
F_111 ( V_30 -> V_34 ) ,
( V_30 -> V_62 . V_137 - V_63 ) / V_107 ) ;
else
#endif
F_106 ( V_121 ,
L_25
L_26 ,
F_43 ( V_30 -> V_28 ) ,
F_108 ( V_30 -> V_24 . V_17 ) , F_45 ( V_30 -> V_25 ) ,
F_108 ( V_30 -> V_26 . V_17 ) , F_45 ( V_30 -> V_27 ) ,
F_108 ( V_30 -> V_53 . V_17 ) , F_45 ( V_30 -> V_59 ) ,
F_107 ( V_30 -> V_28 , V_30 -> V_89 ) ,
F_111 ( V_30 -> V_34 ) ,
( V_30 -> V_62 . V_137 - V_63 ) / V_107 ) ;
}
return 0 ;
}
static int F_113 ( struct V_138 * V_138 , struct V_139 * V_139 )
{
return F_110 ( V_138 , V_139 , & V_141 ,
sizeof( struct V_124 ) ) ;
}
static inline int F_114 ( struct V_29 * V_30 )
{
static const char V_142 [ 9 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 } ;
static char V_143 [ 9 ] = { 0 } ;
int V_144 ;
if ( F_115 ( V_30 -> V_61 + V_63 , V_30 -> V_62 . V_137 + 60 * V_107 ) )
return 0 ;
V_144 = F_41 ( & V_30 -> V_118 ) ;
if ( V_144 > 8 || V_144 < 0 ) return 0 ;
if ( ! V_142 [ V_144 ] ) return 0 ;
if ( -- V_143 [ V_144 ] > 0 ) return 0 ;
V_143 [ V_144 ] = V_142 [ V_144 ] ;
return 1 ;
}
void F_116 ( struct V_5 * V_5 )
{
int V_123 ;
struct V_29 * V_30 ;
for ( V_123 = 0 ; V_123 < ( V_127 >> 5 ) ; V_123 ++ ) {
unsigned int V_32 = F_117 () & V_16 ;
F_13 ( V_32 ) ;
F_37 (cp, &ip_vs_conn_tab[hash], c_list) {
if ( V_30 -> V_34 & V_58 )
continue;
if ( ! F_39 ( V_30 , V_5 ) )
continue;
if ( V_30 -> V_28 == V_145 ) {
switch( V_30 -> V_89 ) {
case V_146 :
case V_147 :
break;
case V_148 :
if ( F_114 ( V_30 ) )
break;
continue;
default:
continue;
}
} else {
if ( ! F_114 ( V_30 ) )
continue;
}
F_83 ( 4 , L_27 ) ;
F_86 ( V_30 ) ;
if ( V_30 -> V_110 ) {
F_83 ( 4 , L_28 ) ;
F_86 ( V_30 -> V_110 ) ;
}
}
F_15 ( V_32 ) ;
}
}
static void F_118 ( struct V_5 * V_5 )
{
int V_123 ;
struct V_29 * V_30 ;
struct V_100 * V_101 = F_72 ( V_5 ) ;
V_149:
for ( V_123 = 0 ; V_123 < V_127 ; V_123 ++ ) {
F_13 ( V_123 ) ;
F_37 (cp, &ip_vs_conn_tab[idx], c_list) {
if ( ! F_39 ( V_30 , V_5 ) )
continue;
F_83 ( 4 , L_27 ) ;
F_86 ( V_30 ) ;
if ( V_30 -> V_110 ) {
F_83 ( 4 , L_28 ) ;
F_86 ( V_30 -> V_110 ) ;
}
}
F_15 ( V_123 ) ;
}
if ( F_41 ( & V_101 -> V_113 ) != 0 ) {
F_119 () ;
goto V_149;
}
}
int T_4 F_120 ( struct V_5 * V_5 )
{
struct V_100 * V_101 = F_72 ( V_5 ) ;
F_96 ( & V_101 -> V_113 , 0 ) ;
F_121 ( L_29 , 0 , V_5 -> V_150 , & V_151 ) ;
F_121 ( L_30 , 0 , V_5 -> V_150 , & V_152 ) ;
return 0 ;
}
void T_5 F_122 ( struct V_5 * V_5 )
{
F_118 ( V_5 ) ;
F_123 ( L_29 , V_5 -> V_150 ) ;
F_123 ( L_30 , V_5 -> V_150 ) ;
}
int T_6 F_124 ( void )
{
int V_123 ;
V_127 = 1 << V_153 ;
V_16 = V_127 - 1 ;
V_39 = F_125 ( V_127 * sizeof( * V_39 ) ) ;
if ( ! V_39 )
return - V_154 ;
V_114 = F_126 ( L_29 ,
sizeof( struct V_29 ) , 0 ,
V_155 , NULL ) ;
if ( ! V_114 ) {
F_127 ( V_39 ) ;
return - V_154 ;
}
F_128 ( L_31
L_32 ,
V_127 ,
( long ) ( V_127 * sizeof( struct V_156 ) ) / 1024 ) ;
F_83 ( 0 , L_33 ,
sizeof( struct V_29 ) ) ;
for ( V_123 = 0 ; V_123 < V_127 ; V_123 ++ )
F_129 ( & V_39 [ V_123 ] ) ;
for ( V_123 = 0 ; V_123 < V_157 ; V_123 ++ ) {
F_130 ( & V_2 [ V_123 ] . V_4 ) ;
}
F_131 ( & V_12 , sizeof( V_12 ) ) ;
return 0 ;
}
void F_132 ( void )
{
F_133 ( V_114 ) ;
F_127 ( V_39 ) ;
}
