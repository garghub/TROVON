void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 V_4 = F_2 ( V_3 ) ;
F_3 ( & V_2 -> V_5 -> V_6 ) ;
F_4 ( V_2 , V_7 , & V_4 , NULL ) ;
F_5 ( & V_2 -> V_5 -> V_6 ) ;
}
static int F_6 ( const T_2 V_8 )
{
int error = 0 ;
struct V_1 * V_9 ;
const T_3 V_10 = F_7 ( V_8 ) ;
if ( F_8 ( V_8 ) >= V_11 )
return - V_12 ;
if ( V_10 == 0 )
return 0 ;
F_9 () ;
V_9 = F_10 ( V_10 ) ;
if ( ! V_9 || ! ( F_11 ( V_8 ) ?
F_12 ( V_9 , V_13 ) : F_13 ( V_9 ) ) ) {
error = - V_12 ;
}
F_14 () ;
return error ;
}
static inline unsigned long long
F_15 ( const T_2 V_8 , const struct V_14 * V_15 )
{
unsigned long long V_16 ;
V_16 = 0 ;
if ( F_8 ( V_8 ) == V_17 ) {
V_16 = ( unsigned long long ) V_15 -> V_18 * V_19 + V_15 -> V_20 ;
} else {
V_16 = F_16 ( F_17 ( V_15 ) ) ;
}
return V_16 ;
}
static void F_18 ( const T_2 V_8 ,
unsigned long long V_21 ,
struct V_14 * V_15 )
{
if ( F_8 ( V_8 ) == V_17 )
* V_15 = F_19 ( V_21 ) ;
else
F_20 ( ( V_22 T_1 ) V_21 , V_15 ) ;
}
static void F_21 ( struct V_23 * V_24 ,
unsigned long long V_25 )
{
int V_26 ;
unsigned long long V_27 , V_28 ;
if ( V_24 -> V_29 . V_30 . V_28 == 0 )
return;
if ( V_25 < V_24 -> V_29 . V_30 . V_21 )
return;
V_28 = V_24 -> V_29 . V_30 . V_28 ;
V_27 = V_25 + V_28 - V_24 -> V_29 . V_30 . V_21 ;
for ( V_26 = 0 ; V_28 < V_27 - V_28 ; V_26 ++ )
V_28 = V_28 << 1 ;
for (; V_26 >= 0 ; V_28 >>= 1 , V_26 -- ) {
if ( V_27 < V_28 )
continue;
V_24 -> V_29 . V_30 . V_21 += V_28 ;
V_24 -> V_31 += 1 << V_26 ;
V_27 -= V_28 ;
}
}
static inline int F_22 ( const struct V_32 * V_4 )
{
if ( ! V_4 -> V_33 && ! V_4 -> V_34 && ! V_4 -> V_35 )
return 1 ;
return 0 ;
}
static inline unsigned long long F_23 ( struct V_1 * V_9 )
{
T_1 V_33 , V_34 ;
V_32 ( V_9 , & V_33 , & V_34 ) ;
return F_16 ( V_33 + V_34 ) ;
}
static inline unsigned long long F_24 ( struct V_1 * V_9 )
{
T_1 V_33 ;
V_32 ( V_9 , & V_33 , NULL ) ;
return F_16 ( V_33 ) ;
}
static int
F_25 ( const T_2 V_8 , struct V_14 * V_15 )
{
int error = F_6 ( V_8 ) ;
if ( ! error ) {
V_15 -> V_18 = 0 ;
V_15 -> V_20 = ( ( V_19 + V_36 - 1 ) / V_36 ) ;
if ( F_8 ( V_8 ) == V_17 ) {
V_15 -> V_20 = 1 ;
}
}
return error ;
}
static int
F_26 ( const T_2 V_8 , const struct V_14 * V_15 )
{
int error = F_6 ( V_8 ) ;
if ( error == 0 ) {
error = - V_37 ;
}
return error ;
}
static int F_27 ( const T_2 V_8 , struct V_1 * V_9 ,
unsigned long long * V_38 )
{
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
* V_38 = F_23 ( V_9 ) ;
break;
case V_39 :
* V_38 = F_24 ( V_9 ) ;
break;
case V_17 :
* V_38 = F_28 ( V_9 ) ;
break;
}
return 0 ;
}
static void F_29 ( struct V_32 * V_40 , struct V_32 * V_41 )
{
if ( V_41 -> V_33 > V_40 -> V_33 )
V_40 -> V_33 = V_41 -> V_33 ;
if ( V_41 -> V_34 > V_40 -> V_34 )
V_40 -> V_34 = V_41 -> V_34 ;
if ( V_41 -> V_35 > V_40 -> V_35 )
V_40 -> V_35 = V_41 -> V_35 ;
}
void F_30 ( struct V_1 * V_42 , struct V_32 * V_43 )
{
struct F_30 * V_44 = & V_42 -> signal -> V_44 ;
struct V_32 V_45 ;
unsigned long V_46 ;
if ( ! V_44 -> V_47 ) {
F_31 ( V_42 , & V_45 ) ;
F_32 ( & V_44 -> V_48 , V_46 ) ;
V_44 -> V_47 = 1 ;
F_29 ( & V_44 -> V_4 , & V_45 ) ;
} else
F_32 ( & V_44 -> V_48 , V_46 ) ;
* V_43 = V_44 -> V_4 ;
F_33 ( & V_44 -> V_48 , V_46 ) ;
}
static int F_34 ( const T_2 V_8 ,
struct V_1 * V_9 ,
unsigned long long * V_38 )
{
struct V_32 V_4 ;
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
F_31 ( V_9 , & V_4 ) ;
* V_38 = F_16 ( V_4 . V_33 + V_4 . V_34 ) ;
break;
case V_39 :
F_31 ( V_9 , & V_4 ) ;
* V_38 = F_16 ( V_4 . V_33 ) ;
break;
case V_17 :
F_31 ( V_9 , & V_4 ) ;
* V_38 = V_4 . V_35 ;
break;
}
return 0 ;
}
static int F_35 ( const T_2 V_8 , struct V_14 * V_15 )
{
const T_3 V_10 = F_7 ( V_8 ) ;
int error = - V_12 ;
unsigned long long V_49 ;
if ( V_10 == 0 ) {
if ( F_11 ( V_8 ) ) {
error = F_27 ( V_8 ,
V_13 , & V_49 ) ;
} else {
F_36 ( & V_50 ) ;
error = F_34 ( V_8 ,
V_13 , & V_49 ) ;
F_37 ( & V_50 ) ;
}
} else {
struct V_1 * V_9 ;
F_9 () ;
V_9 = F_10 ( V_10 ) ;
if ( V_9 ) {
if ( F_11 ( V_8 ) ) {
if ( F_12 ( V_9 , V_13 ) ) {
error = F_27 ( V_8 ,
V_9 , & V_49 ) ;
}
} else {
F_36 ( & V_50 ) ;
if ( F_38 ( V_9 ) && V_9 -> V_5 ) {
error =
F_34 ( V_8 ,
V_9 , & V_49 ) ;
}
F_37 ( & V_50 ) ;
}
}
F_14 () ;
}
if ( error )
return error ;
F_18 ( V_8 , V_49 , V_15 ) ;
return 0 ;
}
static int F_39 ( struct V_23 * V_51 )
{
int V_16 = 0 ;
const T_3 V_10 = F_7 ( V_51 -> V_52 ) ;
struct V_1 * V_9 ;
if ( F_8 ( V_51 -> V_52 ) >= V_11 )
return - V_12 ;
F_40 ( & V_51 -> V_29 . V_30 . V_53 ) ;
F_9 () ;
if ( F_11 ( V_51 -> V_52 ) ) {
if ( V_10 == 0 ) {
V_9 = V_13 ;
} else {
V_9 = F_10 ( V_10 ) ;
if ( V_9 && ! F_12 ( V_9 , V_13 ) )
V_9 = NULL ;
}
} else {
if ( V_10 == 0 ) {
V_9 = V_13 -> V_54 ;
} else {
V_9 = F_10 ( V_10 ) ;
if ( V_9 && ! F_13 ( V_9 ) )
V_9 = NULL ;
}
}
V_51 -> V_29 . V_30 . V_2 = V_9 ;
if ( V_9 ) {
F_41 ( V_9 ) ;
} else {
V_16 = - V_12 ;
}
F_14 () ;
return V_16 ;
}
static int F_42 ( struct V_23 * V_24 )
{
struct V_1 * V_9 = V_24 -> V_29 . V_30 . V_2 ;
int V_16 = 0 ;
if ( F_43 ( V_9 != NULL ) ) {
F_36 ( & V_50 ) ;
if ( F_44 ( V_9 -> V_5 == NULL ) ) {
F_45 ( ! F_46 ( & V_24 -> V_29 . V_30 . V_53 ) ) ;
} else {
F_47 ( & V_9 -> V_5 -> V_6 ) ;
if ( V_24 -> V_29 . V_30 . V_55 )
V_16 = V_56 ;
else
F_48 ( & V_24 -> V_29 . V_30 . V_53 ) ;
F_49 ( & V_9 -> V_5 -> V_6 ) ;
}
F_37 ( & V_50 ) ;
if ( ! V_16 )
F_50 ( V_9 ) ;
}
return V_16 ;
}
static void F_51 ( struct V_57 * V_58 ,
unsigned long long V_59 )
{
struct V_60 * V_24 , * V_61 ;
F_52 (timer, next, head, entry)
F_53 ( & V_24 -> V_53 ) ;
}
static void F_54 ( struct V_57 * V_58 ,
T_1 V_33 , T_1 V_34 ,
unsigned long long V_35 )
{
T_1 V_62 = V_33 + V_34 ;
F_51 ( V_58 , F_16 ( V_62 ) ) ;
F_51 ( ++ V_58 , F_16 ( V_33 ) ) ;
F_51 ( ++ V_58 , V_35 ) ;
}
void F_55 ( struct V_1 * V_42 )
{
T_1 V_33 , V_34 ;
F_56 ( ( const void * ) & V_42 -> V_63 . V_35 ,
sizeof( unsigned long long ) ) ;
V_32 ( V_42 , & V_33 , & V_34 ) ;
F_54 ( V_42 -> V_64 ,
V_33 , V_34 , V_42 -> V_63 . V_35 ) ;
}
void F_57 ( struct V_1 * V_42 )
{
struct V_65 * const V_66 = V_42 -> signal ;
T_1 V_33 , V_34 ;
V_32 ( V_42 , & V_33 , & V_34 ) ;
F_54 ( V_42 -> signal -> V_64 ,
V_33 + V_66 -> V_33 , V_34 + V_66 -> V_34 ,
V_42 -> V_63 . V_35 + V_66 -> V_67 ) ;
}
static void F_58 ( struct V_23 * V_68 , unsigned long long V_25 )
{
struct V_60 * V_24 = & V_68 -> V_29 . V_30 ;
F_50 ( V_24 -> V_2 ) ;
V_24 -> V_2 = NULL ;
if ( V_24 -> V_21 < V_25 ) {
V_24 -> V_21 = 0 ;
} else {
V_24 -> V_21 -= V_25 ;
}
}
static inline int F_59 ( T_1 V_21 , T_1 V_69 )
{
return V_21 == 0 || V_21 > V_69 ;
}
static void F_60 ( struct V_23 * V_24 )
{
struct V_1 * V_9 = V_24 -> V_29 . V_30 . V_2 ;
struct V_57 * V_58 , * V_70 ;
struct V_32 * V_71 ;
struct V_60 * const V_72 = & V_24 -> V_29 . V_30 ;
struct V_60 * V_61 ;
if ( F_11 ( V_24 -> V_52 ) ) {
V_58 = V_9 -> V_64 ;
V_71 = & V_9 -> V_71 ;
} else {
V_58 = V_9 -> signal -> V_64 ;
V_71 = & V_9 -> signal -> V_71 ;
}
V_58 += F_8 ( V_24 -> V_52 ) ;
V_70 = V_58 ;
F_61 (next, head, entry) {
if ( V_72 -> V_21 < V_61 -> V_21 )
break;
V_70 = & V_61 -> V_53 ;
}
F_62 ( & V_72 -> V_53 , V_70 ) ;
if ( V_70 == V_58 ) {
unsigned long long exp = V_72 -> V_21 ;
switch ( F_8 ( V_24 -> V_52 ) ) {
case V_7 :
if ( F_59 ( V_71 -> V_73 , F_63 ( exp ) ) )
V_71 -> V_73 = F_63 ( exp ) ;
break;
case V_39 :
if ( F_59 ( V_71 -> V_74 , F_63 ( exp ) ) )
V_71 -> V_74 = F_63 ( exp ) ;
break;
case V_17 :
if ( V_71 -> V_75 == 0 ||
V_71 -> V_75 > exp )
V_71 -> V_75 = exp ;
break;
}
}
}
static void F_64 ( struct V_23 * V_24 )
{
if ( ( V_24 -> V_76 & ~ V_77 ) == V_78 ) {
V_24 -> V_29 . V_30 . V_21 = 0 ;
} else if ( F_44 ( V_24 -> V_79 == NULL ) ) {
F_65 ( V_24 -> V_80 ) ;
V_24 -> V_29 . V_30 . V_21 = 0 ;
} else if ( V_24 -> V_29 . V_30 . V_28 == 0 ) {
F_66 ( V_24 , 0 ) ;
V_24 -> V_29 . V_30 . V_21 = 0 ;
} else if ( F_66 ( V_24 , ++ V_24 -> V_81 ) ) {
F_67 ( V_24 ) ;
}
}
static int F_68 ( const T_2 V_8 ,
struct V_1 * V_9 ,
unsigned long long * V_38 )
{
struct V_32 V_4 ;
F_30 ( V_9 , & V_4 ) ;
switch ( F_8 ( V_8 ) ) {
default:
return - V_12 ;
case V_7 :
* V_38 = F_16 ( V_4 . V_33 + V_4 . V_34 ) ;
break;
case V_39 :
* V_38 = F_16 ( V_4 . V_33 ) ;
break;
case V_17 :
* V_38 = V_4 . V_35 + F_69 ( V_9 ) ;
break;
}
return 0 ;
}
static void F_70 ( struct V_82 * V_83 )
{
F_71 () ;
}
static void F_72 ( void )
{
F_73 ( & V_84 ) ;
}
bool F_74 ( struct V_1 * V_42 )
{
if ( ! F_22 ( & V_42 -> V_71 ) )
return false ;
if ( V_42 -> signal -> V_44 . V_47 )
return false ;
return true ;
}
static inline void F_72 ( void ) { }
static int F_75 ( struct V_23 * V_24 , int V_46 ,
struct V_85 * V_86 , struct V_85 * V_87 )
{
struct V_1 * V_9 = V_24 -> V_29 . V_30 . V_2 ;
unsigned long long V_88 , V_89 , V_90 , V_91 ;
int V_16 ;
if ( F_44 ( V_9 == NULL ) ) {
return - V_92 ;
}
V_89 = F_15 ( V_24 -> V_52 , & V_86 -> V_93 ) ;
F_36 ( & V_50 ) ;
if ( F_44 ( V_9 -> V_5 == NULL ) ) {
F_37 ( & V_50 ) ;
F_50 ( V_9 ) ;
V_24 -> V_29 . V_30 . V_2 = NULL ;
return - V_92 ;
}
F_45 ( ! F_76 () ) ;
V_16 = 0 ;
V_90 = V_24 -> V_29 . V_30 . V_28 ;
F_47 ( & V_9 -> V_5 -> V_6 ) ;
V_88 = V_24 -> V_29 . V_30 . V_21 ;
if ( F_44 ( V_24 -> V_29 . V_30 . V_55 ) ) {
V_24 -> V_29 . V_30 . V_55 = - 1 ;
V_16 = V_56 ;
} else
F_53 ( & V_24 -> V_29 . V_30 . V_53 ) ;
if ( F_11 ( V_24 -> V_52 ) ) {
F_27 ( V_24 -> V_52 , V_9 , & V_91 ) ;
} else {
F_68 ( V_24 -> V_52 , V_9 , & V_91 ) ;
}
if ( V_87 ) {
if ( V_88 == 0 ) {
V_87 -> V_93 . V_18 = 0 ;
V_87 -> V_93 . V_20 = 0 ;
} else {
F_21 ( V_24 , V_91 ) ;
if ( V_91 < V_24 -> V_29 . V_30 . V_21 ) {
V_88 = V_24 -> V_29 . V_30 . V_21 - V_91 ;
F_18 ( V_24 -> V_52 ,
V_88 ,
& V_87 -> V_93 ) ;
} else {
V_87 -> V_93 . V_20 = 1 ;
V_87 -> V_93 . V_18 = 0 ;
}
}
}
if ( F_44 ( V_16 ) ) {
F_49 ( & V_9 -> V_5 -> V_6 ) ;
F_37 ( & V_50 ) ;
goto V_94;
}
if ( V_89 != 0 && ! ( V_46 & V_95 ) ) {
V_89 += V_91 ;
}
V_24 -> V_29 . V_30 . V_21 = V_89 ;
if ( V_89 != 0 && V_91 < V_89 ) {
F_60 ( V_24 ) ;
}
F_49 ( & V_9 -> V_5 -> V_6 ) ;
F_37 ( & V_50 ) ;
V_24 -> V_29 . V_30 . V_28 = F_15 ( V_24 -> V_52 ,
& V_86 -> V_96 ) ;
V_24 -> V_81 = ( V_24 -> V_81 + 2 ) &
~ V_97 ;
V_24 -> V_98 = 0 ;
V_24 -> V_31 = - 1 ;
if ( V_89 != 0 && ! ( V_91 < V_89 ) ) {
F_64 ( V_24 ) ;
}
V_16 = 0 ;
V_94:
if ( V_87 ) {
F_18 ( V_24 -> V_52 ,
V_90 , & V_87 -> V_96 ) ;
}
if ( ! V_16 )
F_72 () ;
return V_16 ;
}
static void F_77 ( struct V_23 * V_24 , struct V_85 * V_99 )
{
unsigned long long V_25 ;
struct V_1 * V_9 = V_24 -> V_29 . V_30 . V_2 ;
int V_100 ;
F_18 ( V_24 -> V_52 ,
V_24 -> V_29 . V_30 . V_28 , & V_99 -> V_96 ) ;
if ( V_24 -> V_29 . V_30 . V_21 == 0 ) {
V_99 -> V_93 . V_18 = V_99 -> V_93 . V_20 = 0 ;
return;
}
if ( F_44 ( V_9 == NULL ) ) {
V_101:
F_18 ( V_24 -> V_52 , V_24 -> V_29 . V_30 . V_21 ,
& V_99 -> V_93 ) ;
return;
}
if ( F_11 ( V_24 -> V_52 ) ) {
F_27 ( V_24 -> V_52 , V_9 , & V_25 ) ;
V_100 = V_9 -> V_102 ;
} else {
F_36 ( & V_50 ) ;
if ( F_44 ( V_9 -> V_5 == NULL ) ) {
F_50 ( V_9 ) ;
V_24 -> V_29 . V_30 . V_2 = NULL ;
V_24 -> V_29 . V_30 . V_21 = 0 ;
F_37 ( & V_50 ) ;
goto V_101;
} else {
F_68 ( V_24 -> V_52 , V_9 , & V_25 ) ;
V_100 = ( F_44 ( V_9 -> V_102 ) &&
F_78 ( V_9 ) ) ;
}
F_37 ( & V_50 ) ;
}
if ( F_44 ( V_100 ) ) {
F_58 ( V_24 , V_25 ) ;
goto V_101;
}
if ( V_25 < V_24 -> V_29 . V_30 . V_21 ) {
F_18 ( V_24 -> V_52 ,
V_24 -> V_29 . V_30 . V_21 - V_25 ,
& V_99 -> V_93 ) ;
} else {
V_99 -> V_93 . V_20 = 1 ;
V_99 -> V_93 . V_18 = 0 ;
}
}
static unsigned long long
F_79 ( struct V_57 * V_103 ,
struct V_57 * V_55 ,
unsigned long long V_59 )
{
int V_104 = 20 ;
while ( ! F_46 ( V_103 ) ) {
struct V_60 * V_105 ;
V_105 = F_80 ( V_103 , struct V_60 , V_53 ) ;
if ( ! -- V_104 || V_59 < V_105 -> V_21 )
return V_105 -> V_21 ;
V_105 -> V_55 = 1 ;
F_81 ( & V_105 -> V_53 , V_55 ) ;
}
return 0 ;
}
static void F_82 ( struct V_1 * V_42 ,
struct V_57 * V_55 )
{
struct V_57 * V_103 = V_42 -> V_64 ;
struct V_65 * const V_66 = V_42 -> signal ;
struct V_32 * V_106 = & V_42 -> V_71 ;
unsigned long long V_21 ;
unsigned long V_107 ;
V_21 = F_79 ( V_103 , V_55 , F_23 ( V_42 ) ) ;
V_106 -> V_73 = F_63 ( V_21 ) ;
V_21 = F_79 ( ++ V_103 , V_55 , F_24 ( V_42 ) ) ;
V_106 -> V_74 = F_63 ( V_21 ) ;
V_106 -> V_75 = F_79 ( ++ V_103 , V_55 ,
V_42 -> V_63 . V_35 ) ;
V_107 = F_83 ( V_66 -> V_108 [ V_109 ] . V_110 ) ;
if ( V_107 != V_111 ) {
unsigned long V_112 =
F_83 ( V_66 -> V_108 [ V_109 ] . V_113 ) ;
if ( V_112 != V_111 &&
V_42 -> V_114 . V_115 > F_84 ( V_112 , V_116 / V_36 ) ) {
F_85 ( V_117 , V_118 , V_42 ) ;
return;
}
if ( V_42 -> V_114 . V_115 > F_84 ( V_107 , V_116 / V_36 ) ) {
if ( V_107 < V_112 ) {
V_107 += V_116 ;
V_66 -> V_108 [ V_109 ] . V_110 = V_107 ;
}
F_86 ( V_119
L_1 ,
V_42 -> V_120 , F_87 ( V_42 ) ) ;
F_85 ( V_121 , V_118 , V_42 ) ;
}
}
}
static void F_88 ( struct V_65 * V_66 )
{
struct F_30 * V_44 = & V_66 -> V_44 ;
unsigned long V_46 ;
F_32 ( & V_44 -> V_48 , V_46 ) ;
V_44 -> V_47 = 0 ;
F_33 ( & V_44 -> V_48 , V_46 ) ;
}
static void F_89 ( struct V_1 * V_42 , struct V_122 * V_29 ,
unsigned long long * V_21 ,
unsigned long long V_123 , int V_124 )
{
if ( ! V_29 -> V_21 )
return;
if ( V_123 >= V_29 -> V_21 ) {
if ( V_29 -> V_28 ) {
V_29 -> V_21 += V_29 -> V_28 ;
V_29 -> error += V_29 -> V_125 ;
if ( V_29 -> error >= V_126 ) {
V_29 -> V_21 -= V_127 ;
V_29 -> error -= V_126 ;
}
} else {
V_29 -> V_21 = 0 ;
}
F_90 ( V_124 == V_128 ?
V_129 : V_130 ,
V_42 -> signal -> V_131 , V_123 ) ;
F_85 ( V_124 , V_118 , V_42 ) ;
}
if ( V_29 -> V_21 && ( ! * V_21 || V_29 -> V_21 < * V_21 ) ) {
* V_21 = V_29 -> V_21 ;
}
}
static void F_91 ( struct V_1 * V_42 ,
struct V_57 * V_55 )
{
struct V_65 * const V_66 = V_42 -> signal ;
unsigned long long V_33 , V_62 , V_132 , V_133 ;
unsigned long long V_67 , V_134 ;
struct V_57 * V_103 = V_66 -> V_64 ;
struct V_32 V_4 ;
unsigned long V_107 ;
F_30 ( V_42 , & V_4 ) ;
V_33 = F_16 ( V_4 . V_33 ) ;
V_62 = V_33 + F_16 ( V_4 . V_34 ) ;
V_67 = V_4 . V_35 ;
V_133 = F_79 ( V_103 , V_55 , V_62 ) ;
V_132 = F_79 ( ++ V_103 , V_55 , V_33 ) ;
V_134 = F_79 ( ++ V_103 , V_55 , V_67 ) ;
F_89 ( V_42 , & V_66 -> V_29 [ V_7 ] , & V_133 , V_62 ,
V_128 ) ;
F_89 ( V_42 , & V_66 -> V_29 [ V_39 ] , & V_132 , V_33 ,
V_135 ) ;
V_107 = F_83 ( V_66 -> V_108 [ V_136 ] . V_110 ) ;
if ( V_107 != V_111 ) {
unsigned long V_137 = F_92 ( V_62 ) ;
unsigned long V_112 =
F_83 ( V_66 -> V_108 [ V_136 ] . V_113 ) ;
T_1 V_138 ;
if ( V_137 >= V_112 ) {
F_85 ( V_117 , V_118 , V_42 ) ;
return;
}
if ( V_137 >= V_107 ) {
F_85 ( V_121 , V_118 , V_42 ) ;
if ( V_107 < V_112 ) {
V_107 ++ ;
V_66 -> V_108 [ V_136 ] . V_110 = V_107 ;
}
}
V_138 = F_2 ( V_107 ) ;
if ( ! V_133 || V_138 < V_133 ) {
V_133 = V_138 ;
}
}
V_66 -> V_71 . V_73 = F_63 ( V_133 ) ;
V_66 -> V_71 . V_74 = F_63 ( V_132 ) ;
V_66 -> V_71 . V_75 = V_134 ;
if ( F_22 ( & V_66 -> V_71 ) )
F_88 ( V_66 ) ;
}
void F_67 ( struct V_23 * V_24 )
{
struct V_1 * V_9 = V_24 -> V_29 . V_30 . V_2 ;
unsigned long long V_25 ;
if ( F_44 ( V_9 == NULL ) )
goto V_94;
if ( F_11 ( V_24 -> V_52 ) ) {
F_27 ( V_24 -> V_52 , V_9 , & V_25 ) ;
F_21 ( V_24 , V_25 ) ;
if ( F_44 ( V_9 -> V_102 ) ) {
F_58 ( V_24 , V_25 ) ;
goto V_94;
}
F_36 ( & V_50 ) ;
F_47 ( & V_9 -> V_5 -> V_6 ) ;
} else {
F_36 ( & V_50 ) ;
if ( F_44 ( V_9 -> V_5 == NULL ) ) {
F_50 ( V_9 ) ;
V_24 -> V_29 . V_30 . V_2 = V_9 = NULL ;
V_24 -> V_29 . V_30 . V_21 = 0 ;
goto V_139;
} else if ( F_44 ( V_9 -> V_102 ) && F_78 ( V_9 ) ) {
F_68 ( V_24 -> V_52 , V_9 , & V_25 ) ;
F_58 ( V_24 , V_25 ) ;
goto V_139;
}
F_47 ( & V_9 -> V_5 -> V_6 ) ;
F_68 ( V_24 -> V_52 , V_9 , & V_25 ) ;
F_21 ( V_24 , V_25 ) ;
}
F_45 ( ! F_76 () ) ;
F_60 ( V_24 ) ;
F_49 ( & V_9 -> V_5 -> V_6 ) ;
V_139:
F_37 ( & V_50 ) ;
V_94:
V_24 -> V_98 = V_24 -> V_31 ;
V_24 -> V_31 = - 1 ;
++ V_24 -> V_81 ;
}
static inline int F_93 ( const struct V_32 * V_38 ,
const struct V_32 * V_21 )
{
if ( V_21 -> V_33 && V_38 -> V_33 >= V_21 -> V_33 )
return 1 ;
if ( V_21 -> V_34 && V_38 -> V_33 + V_38 -> V_34 >= V_21 -> V_34 )
return 1 ;
if ( V_21 -> V_35 != 0 &&
V_38 -> V_35 >= V_21 -> V_35 )
return 1 ;
return 0 ;
}
static inline int F_94 ( struct V_1 * V_42 )
{
struct V_65 * V_66 ;
T_1 V_33 , V_34 ;
V_32 ( V_42 , & V_33 , & V_34 ) ;
if ( ! F_22 ( & V_42 -> V_71 ) ) {
struct V_32 V_140 = {
. V_33 = V_33 ,
. V_34 = V_34 ,
. V_35 = V_42 -> V_63 . V_35
} ;
if ( F_93 ( & V_140 , & V_42 -> V_71 ) )
return 1 ;
}
V_66 = V_42 -> signal ;
if ( V_66 -> V_44 . V_47 ) {
struct V_32 V_141 ;
F_95 ( & V_66 -> V_44 . V_48 ) ;
V_141 = V_66 -> V_44 . V_4 ;
F_96 ( & V_66 -> V_44 . V_48 ) ;
if ( F_93 ( & V_141 , & V_66 -> V_71 ) )
return 1 ;
}
return 0 ;
}
void F_97 ( struct V_1 * V_42 )
{
F_98 ( V_55 ) ;
struct V_23 * V_24 , * V_61 ;
unsigned long V_46 ;
F_45 ( ! F_76 () ) ;
if ( ! F_94 ( V_42 ) )
return;
if ( ! F_99 ( V_42 , & V_46 ) )
return;
F_82 ( V_42 , & V_55 ) ;
if ( V_42 -> signal -> V_44 . V_47 )
F_91 ( V_42 , & V_55 ) ;
F_100 ( V_42 , & V_46 ) ;
F_52 (timer, next, &firing, it.cpu.entry) {
int V_142 ;
F_47 ( & V_24 -> V_143 ) ;
F_53 ( & V_24 -> V_29 . V_30 . V_53 ) ;
V_142 = V_24 -> V_29 . V_30 . V_55 ;
V_24 -> V_29 . V_30 . V_55 = 0 ;
if ( F_43 ( V_142 >= 0 ) )
F_64 ( V_24 ) ;
F_49 ( & V_24 -> V_143 ) ;
}
if ( V_42 -> signal -> V_44 . V_47 )
F_72 () ;
}
void F_4 ( struct V_1 * V_42 , unsigned int V_144 ,
T_1 * V_145 , T_1 * V_146 )
{
unsigned long long V_25 ;
F_45 ( V_144 == V_17 ) ;
F_68 ( V_144 , V_42 , & V_25 ) ;
if ( V_146 ) {
if ( * V_146 ) {
if ( * V_146 <= V_25 ) {
* V_146 = V_127 ;
} else {
* V_146 -= V_25 ;
}
}
if ( ! * V_145 )
goto V_94;
* V_145 += V_25 ;
}
switch ( V_144 ) {
case V_7 :
if ( F_59 ( V_42 -> signal -> V_71 . V_73 , * V_145 ) )
V_42 -> signal -> V_71 . V_73 = * V_145 ;
break;
case V_39 :
if ( F_59 ( V_42 -> signal -> V_71 . V_74 , * V_145 ) )
V_42 -> signal -> V_71 . V_74 = * V_145 ;
break;
}
V_94:
F_72 () ;
}
static int F_101 ( const T_2 V_8 , int V_46 ,
struct V_14 * V_147 , struct V_85 * V_29 )
{
struct V_23 V_24 ;
int error ;
memset ( & V_24 , 0 , sizeof V_24 ) ;
F_102 ( & V_24 . V_143 ) ;
V_24 . V_52 = V_8 ;
V_24 . V_31 = - 1 ;
error = F_39 ( & V_24 ) ;
V_24 . V_80 = V_13 ;
if ( ! error ) {
static struct V_85 V_148 ;
memset ( V_29 , 0 , sizeof *V_29 ) ;
V_29 -> V_93 = * V_147 ;
F_3 ( & V_24 . V_143 ) ;
error = F_75 ( & V_24 , V_46 , V_29 , NULL ) ;
if ( error ) {
F_5 ( & V_24 . V_143 ) ;
return error ;
}
while ( ! F_103 ( V_13 ) ) {
if ( V_24 . V_29 . V_30 . V_21 == 0 ) {
F_42 ( & V_24 ) ;
F_5 ( & V_24 . V_143 ) ;
return 0 ;
}
F_104 ( V_149 ) ;
F_5 ( & V_24 . V_143 ) ;
F_105 () ;
F_3 ( & V_24 . V_143 ) ;
}
F_18 ( V_8 , V_24 . V_29 . V_30 . V_21 , V_147 ) ;
error = F_75 ( & V_24 , 0 , & V_148 , V_29 ) ;
if ( ! error ) {
F_42 ( & V_24 ) ;
}
F_5 ( & V_24 . V_143 ) ;
while ( error == V_56 ) {
F_3 ( & V_24 . V_143 ) ;
error = F_42 ( & V_24 ) ;
F_5 ( & V_24 . V_143 ) ;
}
if ( ( V_29 -> V_93 . V_18 | V_29 -> V_93 . V_20 ) == 0 ) {
return 0 ;
}
error = - V_150 ;
}
return error ;
}
static int F_106 ( const T_2 V_8 , int V_46 ,
struct V_14 * V_147 , struct V_14 T_4 * V_151 )
{
struct V_152 * V_152 =
& F_107 () -> V_152 ;
struct V_85 V_29 ;
int error ;
if ( F_11 ( V_8 ) &&
( F_7 ( V_8 ) == 0 ||
F_7 ( V_8 ) == V_13 -> V_10 ) )
return - V_12 ;
error = F_101 ( V_8 , V_46 , V_147 , & V_29 ) ;
if ( error == - V_150 ) {
if ( V_46 & V_95 )
return - V_153 ;
if ( V_151 && F_108 ( V_151 , & V_29 . V_93 , sizeof *V_151 ) )
return - V_154 ;
V_152 -> V_155 = V_156 ;
V_152 -> V_157 . V_158 = V_8 ;
V_152 -> V_157 . V_151 = V_151 ;
V_152 -> V_157 . V_21 = F_109 ( V_147 ) ;
}
return error ;
}
static long V_156 ( struct V_152 * V_152 )
{
T_2 V_8 = V_152 -> V_157 . V_158 ;
struct V_14 V_105 ;
struct V_85 V_29 ;
int error ;
V_105 = F_19 ( V_152 -> V_157 . V_21 ) ;
error = F_101 ( V_8 , V_95 , & V_105 , & V_29 ) ;
if ( error == - V_150 ) {
struct V_14 T_4 * V_151 = V_152 -> V_157 . V_151 ;
if ( V_151 && F_108 ( V_151 , & V_29 . V_93 , sizeof *V_151 ) )
return - V_154 ;
V_152 -> V_157 . V_21 = F_109 ( & V_105 ) ;
}
return error ;
}
static int F_110 ( const T_2 V_8 ,
struct V_14 * V_15 )
{
return F_25 ( V_159 , V_15 ) ;
}
static int F_111 ( const T_2 V_8 ,
struct V_14 * V_15 )
{
return F_35 ( V_159 , V_15 ) ;
}
static int F_112 ( struct V_23 * V_24 )
{
V_24 -> V_52 = V_159 ;
return F_39 ( V_24 ) ;
}
static int F_113 ( const T_2 V_8 , int V_46 ,
struct V_14 * V_147 ,
struct V_14 T_4 * V_151 )
{
return F_106 ( V_159 , V_46 , V_147 , V_151 ) ;
}
static long F_114 ( struct V_152 * V_152 )
{
return - V_12 ;
}
static int F_115 ( const T_2 V_8 ,
struct V_14 * V_15 )
{
return F_25 ( V_160 , V_15 ) ;
}
static int F_116 ( const T_2 V_8 ,
struct V_14 * V_15 )
{
return F_35 ( V_160 , V_15 ) ;
}
static int F_117 ( struct V_23 * V_24 )
{
V_24 -> V_52 = V_160 ;
return F_39 ( V_24 ) ;
}
static T_5 int F_118 ( void )
{
struct V_161 V_162 = {
. V_163 = F_110 ,
. V_164 = F_111 ,
. V_165 = F_112 ,
. V_166 = F_113 ,
. V_167 = F_114 ,
} ;
struct V_161 V_168 = {
. V_163 = F_115 ,
. V_164 = F_116 ,
. V_165 = F_117 ,
} ;
struct V_14 V_169 ;
F_119 ( V_170 , & V_162 ) ;
F_119 ( V_171 , & V_168 ) ;
F_20 ( V_127 , & V_169 ) ;
V_126 = V_169 . V_20 ;
F_120 ( V_169 . V_18 != 0 ) ;
return 0 ;
}
