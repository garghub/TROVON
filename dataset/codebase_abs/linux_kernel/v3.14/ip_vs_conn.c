static inline void F_1 ( unsigned int V_1 )
{
F_2 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static inline void F_3 ( unsigned int V_1 )
{
F_4 ( & V_2 [ V_1 & V_3 ] . V_4 ) ;
}
static unsigned int F_5 ( struct V_5 * V_5 , int V_6 , unsigned int V_7 ,
const union V_8 * V_9 ,
T_1 V_10 )
{
#ifdef F_6
if ( V_6 == V_11 )
return ( F_7 ( F_8 ( V_9 , 16 , V_12 ) ,
( V_13 V_14 ) V_10 , V_7 , V_12 ) ^
( ( V_15 ) V_5 >> 8 ) ) & V_16 ;
#endif
return ( F_7 ( ( V_13 V_14 ) V_9 -> V_17 , ( V_13 V_14 ) V_10 , V_7 ,
V_12 ) ^
( ( V_15 ) V_5 >> 8 ) ) & V_16 ;
}
static unsigned int F_9 ( const struct V_18 * V_19 ,
bool V_20 )
{
const union V_8 * V_9 ;
T_1 V_10 ;
if ( V_19 -> V_21 && V_19 -> V_22 -> V_23 )
return V_19 -> V_22 -> V_23 ( V_19 , V_12 , V_20 ) &
V_16 ;
if ( F_10 ( ! V_20 ) ) {
V_9 = V_19 -> V_24 ;
V_10 = V_19 -> V_25 ;
} else {
V_9 = V_19 -> V_26 ;
V_10 = V_19 -> V_27 ;
}
return F_5 ( V_19 -> V_5 , V_19 -> V_6 , V_19 -> V_28 , V_9 , V_10 ) ;
}
static unsigned int F_11 ( const struct V_29 * V_30 )
{
struct V_18 V_19 ;
F_12 ( F_13 ( V_30 ) , V_30 -> V_6 , V_30 -> V_28 ,
& V_30 -> V_24 , V_30 -> V_25 , NULL , 0 , & V_19 ) ;
if ( V_30 -> V_22 ) {
V_19 . V_22 = V_30 -> V_22 ;
V_19 . V_21 = V_30 -> V_21 ;
V_19 . V_31 = V_30 -> V_31 ;
}
return F_9 ( & V_19 , false ) ;
}
static inline int F_14 ( struct V_29 * V_30 )
{
unsigned int V_32 ;
int V_33 ;
if ( V_30 -> V_34 & V_35 )
return 0 ;
V_32 = F_11 ( V_30 ) ;
F_1 ( V_32 ) ;
F_15 ( & V_30 -> V_36 ) ;
if ( ! ( V_30 -> V_34 & V_37 ) ) {
V_30 -> V_34 |= V_37 ;
F_16 ( & V_30 -> V_38 ) ;
F_17 ( & V_30 -> V_39 , & V_40 [ V_32 ] ) ;
V_33 = 1 ;
} else {
F_18 ( L_1 ,
V_41 , F_19 ( 0 ) ) ;
V_33 = 0 ;
}
F_20 ( & V_30 -> V_36 ) ;
F_3 ( V_32 ) ;
return V_33 ;
}
static inline int F_21 ( struct V_29 * V_30 )
{
unsigned int V_32 ;
int V_33 ;
V_32 = F_11 ( V_30 ) ;
F_1 ( V_32 ) ;
F_15 ( & V_30 -> V_36 ) ;
if ( V_30 -> V_34 & V_37 ) {
F_22 ( & V_30 -> V_39 ) ;
V_30 -> V_34 &= ~ V_37 ;
F_23 ( & V_30 -> V_38 ) ;
V_33 = 1 ;
} else
V_33 = 0 ;
F_20 ( & V_30 -> V_36 ) ;
F_3 ( V_32 ) ;
return V_33 ;
}
static inline bool F_24 ( struct V_29 * V_30 )
{
unsigned int V_32 ;
bool V_33 ;
V_32 = F_11 ( V_30 ) ;
F_1 ( V_32 ) ;
F_15 ( & V_30 -> V_36 ) ;
if ( V_30 -> V_34 & V_37 ) {
V_33 = false ;
if ( F_25 ( & V_30 -> V_38 , 1 , 0 ) == 1 ) {
F_22 ( & V_30 -> V_39 ) ;
V_30 -> V_34 &= ~ V_37 ;
V_33 = true ;
}
} else
V_33 = F_26 ( & V_30 -> V_38 ) ? false : true ;
F_20 ( & V_30 -> V_36 ) ;
F_3 ( V_32 ) ;
return V_33 ;
}
static inline struct V_29 *
F_27 ( const struct V_18 * V_19 )
{
unsigned int V_32 ;
struct V_29 * V_30 ;
V_32 = F_9 ( V_19 , false ) ;
F_28 () ;
F_29 (cp, &ip_vs_conn_tab[hash], c_list) {
if ( V_19 -> V_25 == V_30 -> V_25 && V_19 -> V_27 == V_30 -> V_27 &&
V_30 -> V_6 == V_19 -> V_6 &&
F_30 ( V_19 -> V_6 , V_19 -> V_24 , & V_30 -> V_24 ) &&
F_30 ( V_19 -> V_6 , V_19 -> V_26 , & V_30 -> V_26 ) &&
( ( ! V_19 -> V_25 ) ^ ( ! ( V_30 -> V_34 & V_42 ) ) ) &&
V_19 -> V_28 == V_30 -> V_28 &&
F_31 ( V_30 , V_19 -> V_5 ) ) {
if ( ! F_32 ( V_30 ) )
continue;
F_33 () ;
return V_30 ;
}
}
F_33 () ;
return NULL ;
}
struct V_29 * F_34 ( const struct V_18 * V_19 )
{
struct V_29 * V_30 ;
V_30 = F_27 ( V_19 ) ;
if ( ! V_30 && F_26 ( & V_43 ) ) {
struct V_18 V_44 = * V_19 ;
V_44 . V_25 = 0 ;
V_30 = F_27 ( & V_44 ) ;
}
F_35 ( 9 , L_2 ,
F_36 ( V_19 -> V_28 ) ,
F_37 ( V_19 -> V_6 , V_19 -> V_24 ) , F_38 ( V_19 -> V_25 ) ,
F_37 ( V_19 -> V_6 , V_19 -> V_26 ) , F_38 ( V_19 -> V_27 ) ,
V_30 ? L_3 : L_4 ) ;
return V_30 ;
}
static int
F_39 ( int V_6 , const struct V_45 * V_46 ,
const struct V_47 * V_48 ,
int V_20 , struct V_18 * V_19 )
{
T_1 V_49 [ 2 ] , * V_50 ;
struct V_5 * V_5 = F_40 ( V_46 ) ;
V_50 = F_41 ( V_46 , V_48 -> V_51 , sizeof( V_49 ) , V_49 , V_48 ) ;
if ( V_50 == NULL )
return 1 ;
if ( F_10 ( ! V_20 ) )
F_12 ( V_5 , V_6 , V_48 -> V_28 , & V_48 -> V_52 ,
V_50 [ 0 ] , & V_48 -> V_53 , V_50 [ 1 ] , V_19 ) ;
else
F_12 ( V_5 , V_6 , V_48 -> V_28 , & V_48 -> V_53 ,
V_50 [ 1 ] , & V_48 -> V_52 , V_50 [ 0 ] , V_19 ) ;
return 0 ;
}
struct V_29 *
F_42 ( int V_6 , const struct V_45 * V_46 ,
const struct V_47 * V_48 , int V_20 )
{
struct V_18 V_19 ;
if ( F_39 ( V_6 , V_46 , V_48 , V_20 , & V_19 ) )
return NULL ;
return F_34 ( & V_19 ) ;
}
struct V_29 * F_43 ( const struct V_18 * V_19 )
{
unsigned int V_32 ;
struct V_29 * V_30 ;
V_32 = F_9 ( V_19 , false ) ;
F_28 () ;
F_29 (cp, &ip_vs_conn_tab[hash], c_list) {
if ( F_44 ( V_19 -> V_21 && V_19 -> V_22 -> V_54 ) ) {
if ( ! F_31 ( V_30 , V_19 -> V_5 ) )
continue;
if ( V_19 -> V_22 == V_30 -> V_22 && V_19 -> V_22 -> V_54 ( V_19 , V_30 ) ) {
if ( F_32 ( V_30 ) )
goto V_55;
}
continue;
}
if ( V_30 -> V_6 == V_19 -> V_6 &&
F_30 ( V_19 -> V_6 , V_19 -> V_24 , & V_30 -> V_24 ) &&
F_30 ( V_19 -> V_28 == V_56 ? V_57 :
V_19 -> V_6 , V_19 -> V_26 , & V_30 -> V_26 ) &&
V_19 -> V_27 == V_30 -> V_27 && V_19 -> V_25 == V_30 -> V_25 &&
V_30 -> V_34 & V_58 &&
V_19 -> V_28 == V_30 -> V_28 &&
F_31 ( V_30 , V_19 -> V_5 ) ) {
if ( F_32 ( V_30 ) )
goto V_55;
}
}
V_30 = NULL ;
V_55:
F_33 () ;
F_35 ( 9 , L_5 ,
F_36 ( V_19 -> V_28 ) ,
F_37 ( V_19 -> V_6 , V_19 -> V_24 ) , F_38 ( V_19 -> V_25 ) ,
F_37 ( V_19 -> V_6 , V_19 -> V_26 ) , F_38 ( V_19 -> V_27 ) ,
V_30 ? L_3 : L_4 ) ;
return V_30 ;
}
struct V_29 * F_45 ( const struct V_18 * V_19 )
{
unsigned int V_32 ;
struct V_29 * V_30 , * V_33 = NULL ;
V_32 = F_9 ( V_19 , true ) ;
F_28 () ;
F_29 (cp, &ip_vs_conn_tab[hash], c_list) {
if ( V_19 -> V_27 == V_30 -> V_25 && V_19 -> V_25 == V_30 -> V_59 &&
V_30 -> V_6 == V_19 -> V_6 &&
F_30 ( V_19 -> V_6 , V_19 -> V_26 , & V_30 -> V_24 ) &&
F_30 ( V_19 -> V_6 , V_19 -> V_24 , & V_30 -> V_53 ) &&
V_19 -> V_28 == V_30 -> V_28 &&
F_31 ( V_30 , V_19 -> V_5 ) ) {
if ( ! F_32 ( V_30 ) )
continue;
V_33 = V_30 ;
break;
}
}
F_33 () ;
F_35 ( 9 , L_6 ,
F_36 ( V_19 -> V_28 ) ,
F_37 ( V_19 -> V_6 , V_19 -> V_24 ) , F_38 ( V_19 -> V_25 ) ,
F_37 ( V_19 -> V_6 , V_19 -> V_26 ) , F_38 ( V_19 -> V_27 ) ,
V_33 ? L_3 : L_4 ) ;
return V_33 ;
}
struct V_29 *
F_46 ( int V_6 , const struct V_45 * V_46 ,
const struct V_47 * V_48 , int V_20 )
{
struct V_18 V_19 ;
if ( F_39 ( V_6 , V_46 , V_48 , V_20 , & V_19 ) )
return NULL ;
return F_45 ( & V_19 ) ;
}
void F_47 ( struct V_29 * V_30 )
{
unsigned long V_60 = ( V_30 -> V_34 & V_35 ) ?
0 : V_30 -> V_61 ;
F_48 ( & V_30 -> V_62 , V_63 + V_60 ) ;
F_49 ( V_30 ) ;
}
void F_50 ( struct V_29 * V_30 , T_1 V_25 )
{
if ( F_21 ( V_30 ) ) {
F_2 ( & V_30 -> V_36 ) ;
if ( V_30 -> V_34 & V_42 ) {
F_23 ( & V_43 ) ;
V_30 -> V_34 &= ~ V_42 ;
V_30 -> V_25 = V_25 ;
}
F_4 ( & V_30 -> V_36 ) ;
F_14 ( V_30 ) ;
}
}
static inline void F_51 ( struct V_29 * V_30 )
{
switch ( F_52 ( V_30 ) ) {
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
static inline void F_53 ( struct V_29 * V_30 )
{
switch ( F_52 ( V_30 ) ) {
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
static inline int F_54 ( struct V_79 * V_80 )
{
return F_26 ( & V_80 -> V_81 )
+ F_26 ( & V_80 -> V_82 ) ;
}
static inline void
F_55 ( struct V_29 * V_30 , struct V_79 * V_80 )
{
unsigned int V_83 ;
T_2 V_34 ;
if ( ! V_80 )
return;
F_56 ( V_80 ) ;
V_83 = F_26 ( & V_80 -> V_83 ) ;
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
F_35 ( 7 , L_7
L_8
L_9 ,
F_36 ( V_30 -> V_28 ) ,
F_37 ( V_30 -> V_6 , & V_30 -> V_24 ) , F_38 ( V_30 -> V_25 ) ,
F_37 ( V_30 -> V_6 , & V_30 -> V_26 ) , F_38 ( V_30 -> V_27 ) ,
F_37 ( V_30 -> V_6 , & V_30 -> V_53 ) , F_38 ( V_30 -> V_59 ) ,
F_57 ( V_30 ) , V_30 -> V_89 ,
V_30 -> V_34 , F_26 ( & V_30 -> V_38 ) ,
F_26 ( & V_80 -> V_38 ) ) ;
if ( ! ( V_34 & V_58 ) ) {
if ( ! ( V_34 & V_86 ) )
F_16 ( & V_80 -> V_81 ) ;
else
F_16 ( & V_80 -> V_82 ) ;
} else {
F_16 ( & V_80 -> V_90 ) ;
}
if ( V_80 -> V_91 != 0 &&
F_54 ( V_80 ) >= V_80 -> V_91 )
V_80 -> V_34 |= V_92 ;
}
void F_58 ( struct V_29 * V_30 )
{
struct V_79 * V_80 ;
F_28 () ;
V_80 = F_59 ( F_13 ( V_30 ) , V_30 -> V_6 , & V_30 -> V_53 ,
V_30 -> V_59 , & V_30 -> V_26 , V_30 -> V_27 ,
V_30 -> V_28 , V_30 -> V_93 , V_30 -> V_34 ) ;
if ( V_80 ) {
struct V_94 * V_95 ;
F_2 ( & V_30 -> V_36 ) ;
if ( V_30 -> V_80 ) {
F_4 ( & V_30 -> V_36 ) ;
F_33 () ;
return;
}
if ( V_30 -> V_96 )
F_60 ( V_30 ) ;
F_55 ( V_30 , V_80 ) ;
F_4 ( & V_30 -> V_36 ) ;
V_30 -> V_65 = NULL ;
#ifdef F_6
if ( V_30 -> V_6 == V_11 )
F_53 ( V_30 ) ;
else
#endif
F_51 ( V_30 ) ;
V_95 = F_61 ( F_13 ( V_30 ) , V_30 -> V_28 ) ;
if ( V_95 && F_26 ( & V_95 -> V_97 ) )
F_62 ( V_30 , V_95 -> V_98 ) ;
}
F_33 () ;
}
static inline void F_63 ( struct V_29 * V_30 )
{
struct V_79 * V_80 = V_30 -> V_80 ;
if ( ! V_80 )
return;
F_35 ( 7 , L_10
L_8
L_9 ,
F_36 ( V_30 -> V_28 ) ,
F_37 ( V_30 -> V_6 , & V_30 -> V_24 ) , F_38 ( V_30 -> V_25 ) ,
F_37 ( V_30 -> V_6 , & V_30 -> V_26 ) , F_38 ( V_30 -> V_27 ) ,
F_37 ( V_30 -> V_6 , & V_30 -> V_53 ) , F_38 ( V_30 -> V_59 ) ,
F_57 ( V_30 ) , V_30 -> V_89 ,
V_30 -> V_34 , F_26 ( & V_30 -> V_38 ) ,
F_26 ( & V_80 -> V_38 ) ) ;
if ( ! ( V_30 -> V_34 & V_58 ) ) {
if ( V_30 -> V_34 & V_86 ) {
F_23 ( & V_80 -> V_82 ) ;
} else {
F_23 ( & V_80 -> V_81 ) ;
}
} else {
F_23 ( & V_80 -> V_90 ) ;
}
if ( V_80 -> V_99 != 0 ) {
if ( F_54 ( V_80 ) < V_80 -> V_99 )
V_80 -> V_34 &= ~ V_92 ;
} else if ( V_80 -> V_91 != 0 ) {
if ( F_54 ( V_80 ) * 4 < V_80 -> V_91 * 3 )
V_80 -> V_34 &= ~ V_92 ;
} else {
if ( V_80 -> V_34 & V_92 )
V_80 -> V_34 &= ~ V_92 ;
}
F_64 ( V_80 ) ;
}
static int F_65 ( struct V_100 * V_101 ,
struct V_79 * V_80 )
{
#ifdef F_66
return V_101 -> V_102 &&
( F_26 ( & V_80 -> V_103 ) == 0 ) ;
#else
return 0 ;
#endif
}
int F_67 ( struct V_29 * V_104 )
{
struct V_79 * V_80 = V_104 -> V_80 ;
struct V_100 * V_101 = F_68 ( F_13 ( V_104 ) ) ;
if ( ( V_80 == NULL ) ||
! ( V_80 -> V_34 & V_105 ) ||
F_65 ( V_101 , V_80 ) ) {
F_35 ( 9 , L_11
L_12
L_13 ,
F_36 ( V_104 -> V_28 ) ,
F_37 ( V_104 -> V_6 , & V_104 -> V_24 ) ,
F_38 ( V_104 -> V_25 ) ,
F_37 ( V_104 -> V_6 , & V_104 -> V_26 ) ,
F_38 ( V_104 -> V_27 ) ,
F_37 ( V_104 -> V_6 , & V_104 -> V_53 ) ,
F_38 ( V_104 -> V_59 ) ) ;
if ( V_104 -> V_27 != F_69 ( 0xffff ) ) {
if ( F_21 ( V_104 ) ) {
V_104 -> V_59 = F_69 ( 0xffff ) ;
V_104 -> V_27 = F_69 ( 0xffff ) ;
V_104 -> V_25 = 0 ;
F_14 ( V_104 ) ;
}
}
F_49 ( V_104 ) ;
return 0 ;
}
return 1 ;
}
static void F_70 ( struct V_106 * V_107 )
{
struct V_29 * V_30 = F_71 ( V_107 , struct V_29 ,
V_106 ) ;
F_72 ( V_30 -> V_22 ) ;
F_73 ( V_30 -> V_21 ) ;
F_74 ( V_108 , V_30 ) ;
}
static void F_75 ( unsigned long V_109 )
{
struct V_29 * V_30 = (struct V_29 * ) V_109 ;
struct V_5 * V_5 = F_13 ( V_30 ) ;
struct V_100 * V_101 = F_68 ( V_5 ) ;
if ( F_26 ( & V_30 -> V_110 ) )
goto V_111;
if ( F_10 ( F_24 ( V_30 ) ) ) {
F_76 ( & V_30 -> V_62 ) ;
if ( V_30 -> V_112 )
F_77 ( V_30 ) ;
if ( V_30 -> V_34 & V_113 ) {
F_78 ( V_30 ) ;
F_79 () ;
if ( V_101 -> V_114 )
F_78 ( V_30 ) ;
}
if ( F_44 ( V_30 -> V_96 != NULL ) )
F_60 ( V_30 ) ;
F_63 ( V_30 ) ;
if ( V_30 -> V_34 & V_42 )
F_23 ( & V_43 ) ;
F_80 ( & V_30 -> V_106 , F_70 ) ;
F_23 ( & V_101 -> V_115 ) ;
return;
}
V_111:
F_81 ( 7 , L_14 ,
F_26 ( & V_30 -> V_38 ) ,
F_26 ( & V_30 -> V_110 ) ) ;
F_16 ( & V_30 -> V_38 ) ;
V_30 -> V_61 = 60 * V_116 ;
if ( V_101 -> V_117 & V_118 )
F_82 ( V_5 , V_30 , F_83 ( V_101 ) ) ;
F_47 ( V_30 ) ;
}
void F_84 ( struct V_29 * V_30 )
{
if ( F_85 ( & V_30 -> V_62 ) &&
F_86 ( V_30 -> V_62 . V_119 , V_63 ) )
F_87 ( & V_30 -> V_62 , V_63 ) ;
}
struct V_29 *
F_88 ( const struct V_18 * V_19 ,
const union V_8 * V_53 , T_1 V_59 , unsigned int V_34 ,
struct V_79 * V_80 , T_2 V_93 )
{
struct V_29 * V_30 ;
struct V_100 * V_101 = F_68 ( V_19 -> V_5 ) ;
struct V_94 * V_95 = F_61 ( V_19 -> V_5 ,
V_19 -> V_28 ) ;
V_30 = F_89 ( V_108 , V_120 ) ;
if ( V_30 == NULL ) {
F_90 ( L_15 , V_41 ) ;
return NULL ;
}
F_91 ( & V_30 -> V_39 ) ;
F_92 ( & V_30 -> V_62 , F_75 , ( unsigned long ) V_30 ) ;
F_93 ( V_30 , V_19 -> V_5 ) ;
V_30 -> V_6 = V_19 -> V_6 ;
V_30 -> V_28 = V_19 -> V_28 ;
F_94 ( V_19 -> V_6 , & V_30 -> V_24 , V_19 -> V_24 ) ;
V_30 -> V_25 = V_19 -> V_25 ;
F_94 ( V_19 -> V_28 == V_56 ? V_57 : V_19 -> V_6 ,
& V_30 -> V_26 , V_19 -> V_26 ) ;
V_30 -> V_27 = V_19 -> V_27 ;
F_94 ( V_19 -> V_6 , & V_30 -> V_53 , V_53 ) ;
V_30 -> V_59 = V_59 ;
V_30 -> V_34 = V_34 ;
V_30 -> V_93 = V_93 ;
if ( V_34 & V_58 && V_19 -> V_22 ) {
F_95 ( V_19 -> V_22 ) ;
V_30 -> V_22 = V_19 -> V_22 ;
V_30 -> V_21 = V_19 -> V_21 ;
V_30 -> V_31 = V_19 -> V_31 ;
} else {
V_30 -> V_22 = NULL ;
V_30 -> V_21 = NULL ;
V_30 -> V_31 = 0 ;
}
F_96 ( & V_30 -> V_36 ) ;
F_97 ( & V_30 -> V_38 , 1 ) ;
V_30 -> V_112 = NULL ;
F_97 ( & V_30 -> V_110 , 0 ) ;
F_97 ( & V_30 -> V_121 , 0 ) ;
V_30 -> V_65 = NULL ;
V_30 -> V_96 = NULL ;
V_30 -> V_122 = NULL ;
V_30 -> V_123 . V_124 = 0 ;
V_30 -> V_125 . V_124 = 0 ;
F_16 ( & V_101 -> V_115 ) ;
if ( V_34 & V_42 )
F_16 ( & V_43 ) ;
V_30 -> V_80 = NULL ;
F_55 ( V_30 , V_80 ) ;
V_30 -> V_89 = 0 ;
V_30 -> V_126 = 0 ;
V_30 -> V_61 = 3 * V_116 ;
V_30 -> V_127 = V_63 & ~ 3UL ;
#ifdef F_6
if ( V_19 -> V_6 == V_11 )
F_53 ( V_30 ) ;
else
#endif
F_51 ( V_30 ) ;
if ( F_44 ( V_95 && F_26 ( & V_95 -> V_97 ) ) )
F_62 ( V_30 , V_95 -> V_98 ) ;
if ( F_98 ( V_101 ) )
V_30 -> V_34 |= V_113 ;
F_14 ( V_30 ) ;
return V_30 ;
}
static void * F_99 ( struct V_128 * V_129 , T_3 V_130 )
{
int V_131 ;
struct V_29 * V_30 ;
struct V_132 * V_133 = V_129 -> V_134 ;
for ( V_131 = 0 ; V_131 < V_135 ; V_131 ++ ) {
F_29 (cp, &ip_vs_conn_tab[idx], c_list) {
if ( V_130 -- == 0 ) {
V_133 -> V_4 = & V_40 [ V_131 ] ;
return V_30 ;
}
}
F_100 () ;
}
return NULL ;
}
static void * F_101 ( struct V_128 * V_129 , T_3 * V_130 )
__acquires( T_4 )
{
struct V_132 * V_133 = V_129 -> V_134 ;
V_133 -> V_4 = NULL ;
F_28 () ;
return * V_130 ? F_99 ( V_129 , * V_130 - 1 ) : V_136 ;
}
static void * F_102 ( struct V_128 * V_129 , void * V_137 , T_3 * V_130 )
{
struct V_29 * V_30 = V_137 ;
struct V_132 * V_133 = V_129 -> V_134 ;
struct V_138 * V_139 ;
struct V_140 * V_4 = V_133 -> V_4 ;
int V_131 ;
++ * V_130 ;
if ( V_137 == V_136 )
return F_99 ( V_129 , 0 ) ;
V_139 = F_103 ( F_104 ( & V_30 -> V_39 ) ) ;
if ( V_139 )
return F_105 ( V_139 , struct V_29 , V_39 ) ;
V_131 = V_4 - V_40 ;
while ( ++ V_131 < V_135 ) {
F_29 (cp, &ip_vs_conn_tab[idx], c_list) {
V_133 -> V_4 = & V_40 [ V_131 ] ;
return V_30 ;
}
F_100 () ;
}
V_133 -> V_4 = NULL ;
return NULL ;
}
static void F_106 ( struct V_128 * V_129 , void * V_137 )
__releases( T_4 )
{
F_33 () ;
}
static int F_107 ( struct V_128 * V_129 , void * V_137 )
{
if ( V_137 == V_136 )
F_108 ( V_129 ,
L_16 ) ;
else {
const struct V_29 * V_30 = V_137 ;
struct V_5 * V_5 = F_109 ( V_129 ) ;
char V_21 [ V_141 + V_142 + 3 ] ;
V_15 V_51 = 0 ;
if ( ! F_31 ( V_30 , V_5 ) )
return 0 ;
if ( V_30 -> V_21 ) {
V_21 [ 0 ] = ' ' ;
V_51 = strlen ( V_30 -> V_22 -> V_143 ) ;
memcpy ( V_21 + 1 , V_30 -> V_22 -> V_143 , V_51 ) ;
V_21 [ V_51 + 1 ] = ' ' ;
V_51 += 2 ;
V_51 += V_30 -> V_22 -> V_144 ( V_30 , V_21 + V_51 ) ;
}
V_21 [ V_51 ] = '\0' ;
#ifdef F_6
if ( V_30 -> V_6 == V_11 )
F_110 ( V_129 , L_17
L_18 ,
F_36 ( V_30 -> V_28 ) ,
& V_30 -> V_24 . V_145 , F_38 ( V_30 -> V_25 ) ,
& V_30 -> V_26 . V_145 , F_38 ( V_30 -> V_27 ) ,
& V_30 -> V_53 . V_145 , F_38 ( V_30 -> V_59 ) ,
F_111 ( V_30 -> V_28 , V_30 -> V_89 ) ,
( V_30 -> V_62 . V_119 - V_63 ) / V_116 , V_21 ) ;
else
#endif
F_110 ( V_129 ,
L_19
L_20 ,
F_36 ( V_30 -> V_28 ) ,
F_112 ( V_30 -> V_24 . V_17 ) , F_38 ( V_30 -> V_25 ) ,
F_112 ( V_30 -> V_26 . V_17 ) , F_38 ( V_30 -> V_27 ) ,
F_112 ( V_30 -> V_53 . V_17 ) , F_38 ( V_30 -> V_59 ) ,
F_111 ( V_30 -> V_28 , V_30 -> V_89 ) ,
( V_30 -> V_62 . V_119 - V_63 ) / V_116 , V_21 ) ;
}
return 0 ;
}
static int F_113 ( struct V_146 * V_146 , struct V_147 * V_147 )
{
return F_114 ( V_146 , V_147 , & V_148 ,
sizeof( struct V_132 ) ) ;
}
static const char * F_115 ( unsigned int V_34 )
{
if ( V_34 & V_85 )
return L_21 ;
else
return L_22 ;
}
static int F_116 ( struct V_128 * V_129 , void * V_137 )
{
if ( V_137 == V_136 )
F_108 ( V_129 ,
L_23 ) ;
else {
const struct V_29 * V_30 = V_137 ;
struct V_5 * V_5 = F_109 ( V_129 ) ;
if ( ! F_31 ( V_30 , V_5 ) )
return 0 ;
#ifdef F_6
if ( V_30 -> V_6 == V_11 )
F_110 ( V_129 , L_24 ,
F_36 ( V_30 -> V_28 ) ,
& V_30 -> V_24 . V_145 , F_38 ( V_30 -> V_25 ) ,
& V_30 -> V_26 . V_145 , F_38 ( V_30 -> V_27 ) ,
& V_30 -> V_53 . V_145 , F_38 ( V_30 -> V_59 ) ,
F_111 ( V_30 -> V_28 , V_30 -> V_89 ) ,
F_115 ( V_30 -> V_34 ) ,
( V_30 -> V_62 . V_119 - V_63 ) / V_116 ) ;
else
#endif
F_110 ( V_129 ,
L_25
L_26 ,
F_36 ( V_30 -> V_28 ) ,
F_112 ( V_30 -> V_24 . V_17 ) , F_38 ( V_30 -> V_25 ) ,
F_112 ( V_30 -> V_26 . V_17 ) , F_38 ( V_30 -> V_27 ) ,
F_112 ( V_30 -> V_53 . V_17 ) , F_38 ( V_30 -> V_59 ) ,
F_111 ( V_30 -> V_28 , V_30 -> V_89 ) ,
F_115 ( V_30 -> V_34 ) ,
( V_30 -> V_62 . V_119 - V_63 ) / V_116 ) ;
}
return 0 ;
}
static int F_117 ( struct V_146 * V_146 , struct V_147 * V_147 )
{
return F_114 ( V_146 , V_147 , & V_149 ,
sizeof( struct V_132 ) ) ;
}
static inline int F_118 ( struct V_29 * V_30 )
{
static const char V_150 [ 9 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 } ;
static char V_151 [ 9 ] = { 0 } ;
int V_152 ;
if ( F_119 ( V_30 -> V_61 + V_63 , V_30 -> V_62 . V_119 + 60 * V_116 ) )
return 0 ;
V_152 = F_26 ( & V_30 -> V_121 ) ;
if ( V_152 > 8 || V_152 < 0 ) return 0 ;
if ( ! V_150 [ V_152 ] ) return 0 ;
if ( -- V_151 [ V_152 ] > 0 ) return 0 ;
V_151 [ V_152 ] = V_150 [ V_152 ] ;
return 1 ;
}
void F_120 ( struct V_5 * V_5 )
{
int V_131 ;
struct V_29 * V_30 , * V_153 ;
F_28 () ;
for ( V_131 = 0 ; V_131 < ( V_135 >> 5 ) ; V_131 ++ ) {
unsigned int V_32 = F_121 () & V_16 ;
F_29 (cp, &ip_vs_conn_tab[hash], c_list) {
if ( V_30 -> V_34 & V_58 )
continue;
if ( ! F_31 ( V_30 , V_5 ) )
continue;
if ( V_30 -> V_28 == V_154 ) {
switch( V_30 -> V_89 ) {
case V_155 :
case V_156 :
break;
case V_157 :
if ( F_118 ( V_30 ) )
break;
continue;
default:
continue;
}
} else if ( V_30 -> V_28 == V_158 ) {
switch ( V_30 -> V_89 ) {
case V_159 :
case V_160 :
break;
case V_161 :
if ( F_118 ( V_30 ) )
break;
continue;
default:
continue;
}
} else {
if ( ! F_118 ( V_30 ) )
continue;
}
F_81 ( 4 , L_27 ) ;
F_84 ( V_30 ) ;
V_153 = V_30 -> V_112 ;
if ( V_153 && F_32 ( V_30 ) ) {
F_81 ( 4 , L_28 ) ;
F_84 ( V_153 ) ;
F_49 ( V_30 ) ;
}
}
F_100 () ;
}
F_33 () ;
}
static void F_122 ( struct V_5 * V_5 )
{
int V_131 ;
struct V_29 * V_30 , * V_153 ;
struct V_100 * V_101 = F_68 ( V_5 ) ;
V_162:
F_28 () ;
for ( V_131 = 0 ; V_131 < V_135 ; V_131 ++ ) {
F_29 (cp, &ip_vs_conn_tab[idx], c_list) {
if ( ! F_31 ( V_30 , V_5 ) )
continue;
F_81 ( 4 , L_27 ) ;
F_84 ( V_30 ) ;
V_153 = V_30 -> V_112 ;
if ( V_153 && F_32 ( V_30 ) ) {
F_81 ( 4 , L_28 ) ;
F_84 ( V_153 ) ;
F_49 ( V_30 ) ;
}
}
F_100 () ;
}
F_33 () ;
if ( F_26 ( & V_101 -> V_115 ) != 0 ) {
F_123 () ;
goto V_162;
}
}
int T_5 F_124 ( struct V_5 * V_5 )
{
struct V_100 * V_101 = F_68 ( V_5 ) ;
F_97 ( & V_101 -> V_115 , 0 ) ;
F_125 ( L_29 , 0 , V_5 -> V_163 , & V_164 ) ;
F_125 ( L_30 , 0 , V_5 -> V_163 , & V_165 ) ;
return 0 ;
}
void T_6 F_126 ( struct V_5 * V_5 )
{
F_122 ( V_5 ) ;
F_127 ( L_29 , V_5 -> V_163 ) ;
F_127 ( L_30 , V_5 -> V_163 ) ;
}
int T_7 F_128 ( void )
{
int V_131 ;
V_135 = 1 << V_166 ;
V_16 = V_135 - 1 ;
V_40 = F_129 ( V_135 * sizeof( * V_40 ) ) ;
if ( ! V_40 )
return - V_167 ;
V_108 = F_130 ( L_29 ,
sizeof( struct V_29 ) , 0 ,
V_168 , NULL ) ;
if ( ! V_108 ) {
F_131 ( V_40 ) ;
return - V_167 ;
}
F_132 ( L_31
L_32 ,
V_135 ,
( long ) ( V_135 * sizeof( struct V_169 ) ) / 1024 ) ;
F_81 ( 0 , L_33 ,
sizeof( struct V_29 ) ) ;
for ( V_131 = 0 ; V_131 < V_135 ; V_131 ++ )
F_133 ( & V_40 [ V_131 ] ) ;
for ( V_131 = 0 ; V_131 < V_170 ; V_131 ++ ) {
F_96 ( & V_2 [ V_131 ] . V_4 ) ;
}
F_134 ( & V_12 , sizeof( V_12 ) ) ;
return 0 ;
}
void F_135 ( void )
{
F_136 () ;
F_137 ( V_108 ) ;
F_131 ( V_40 ) ;
}
