static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_7 ;
F_2 ( & V_4 -> V_8 ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
struct V_10 * V_11 = & V_4 -> V_12 [ V_7 ] ;
if ( ! V_11 -> V_13 )
continue;
F_3 ( & V_4 -> V_8 ) ;
F_4 ( V_2 , V_6 , V_11 -> V_14 ) ;
F_2 ( & V_4 -> V_8 ) ;
}
F_3 ( & V_4 -> V_8 ) ;
}
static inline void F_5 ( int V_15 , struct V_16 * V_17 )
{
int V_18 ;
V_18 = V_15 << V_19 ;
V_20 -> V_21 [ V_15 ] . V_22 = V_17 ;
F_6 ( V_18 , V_23 ) ;
F_7 ( V_18 ) ;
}
static inline void F_5 ( int V_15 , struct V_16 * V_17 ) { }
static inline int F_8 ( int V_24 ,
struct V_25 * V_21 , int V_26 , int V_27 )
{
bool V_28 ;
int V_29 ;
union V_30 V_31 , V_32 ;
for ( V_29 = V_24 + 1 ; V_29 < V_26 ; V_29 ++ ) {
V_31 = V_32 = F_9 ( V_21 [ V_29 ] . V_33 ) ;
if ( ! V_31 . V_34 || V_31 . V_35 )
continue;
V_32 . V_35 = V_27 ;
V_28 = F_10 ( & V_21 [ V_29 ] . V_33 . V_36 ,
V_31 . V_36 , V_32 . V_36 ) == V_31 . V_36 ;
if ( V_28 ) {
F_11 () ;
return V_29 ;
}
}
return - 1 ;
}
static inline int F_12 ( int V_27 )
{
int V_29 ;
int V_37 = F_13 () >> V_19 ;
struct V_25 * V_21 = V_20 -> V_21 ;
V_29 = F_8 ( V_37 , V_21 , F_14 () , V_27 ) ;
if ( V_29 == - 1 )
V_29 = F_8 ( V_29 , V_21 , V_37 , V_27 ) ;
return V_29 ;
}
static void F_15 ( struct V_16 * V_17 ,
struct V_16 * V_38 )
{
struct V_5 * V_39 = V_38 -> V_40 . V_6 ;
int V_41 ;
int V_15 ;
V_17 -> V_42 . V_43 ++ ;
F_16 ( V_44 , & V_17 -> V_40 . V_45 ) ;
if ( V_17 == V_38 ) {
F_17 ( V_46 , F_18 ( V_46 ) | V_47 ) ;
return;
}
V_41 = V_17 -> V_40 . V_48 ;
if ( V_41 < 0 || V_41 >= V_49 ) {
V_15 = - 1 ;
if ( V_20 && V_50 )
V_15 = F_12 ( V_51 ) ;
if ( V_15 != - 1 ) {
F_5 ( V_15 , V_17 ) ;
} else {
V_39 -> V_35 |= V_51 ;
V_39 -> V_52 = V_17 ;
}
return;
}
F_19 () ;
F_20 ( V_41 ) ;
}
static void F_21 ( struct V_16 * V_17 )
{
F_22 ( V_44 ,
& V_17 -> V_40 . V_45 ) ;
F_17 ( V_46 , F_18 ( V_46 ) & ~ V_47 ) ;
}
static inline bool F_23 ( struct V_5 * V_6 ,
union V_53 V_31 ,
union V_53 V_32 )
{
struct V_16 * V_38 = V_54 -> V_55 . V_16 ;
bool V_28 ;
V_32 . V_56 = ( V_32 . V_57 && ( V_32 . V_58 < V_32 . V_59 ) ) ;
V_28 = F_10 ( & V_6 -> V_11 . V_36 , V_31 . V_36 , V_32 . V_36 ) == V_31 . V_36 ;
if ( ! V_28 )
goto V_60;
if ( V_32 . V_56 )
F_15 ( V_6 -> V_17 , V_38 ) ;
V_38 -> V_40 . V_6 -> V_61 = V_32 ;
V_38 -> V_40 . V_6 -> V_62 = V_6 -> V_17 ;
V_60:
return V_28 ;
}
static inline int F_24 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
return ( V_2 -> V_63 || V_6 -> V_35 ) ? V_64 : V_65 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_66 ;
F_26 () ;
F_27 (icsid, icp->resend_map, xics->max_icsid + 1 ) {
struct V_3 * V_4 = V_2 -> V_4 [ V_66 ] ;
if ( ! F_28 ( V_66 , V_6 -> V_67 ) )
continue;
if ( ! V_4 )
continue;
F_1 ( V_2 , V_4 , V_6 ) ;
}
}
static bool F_29 ( struct V_5 * V_6 , T_1 V_68 , T_2 V_69 ,
T_1 * V_70 )
{
union V_53 V_71 , V_72 ;
bool V_28 ;
do {
V_71 = V_72 = F_9 ( V_6 -> V_11 ) ;
* V_70 = 0 ;
V_28 = V_72 . V_59 > V_69 &&
V_72 . V_73 > V_69 &&
V_72 . V_58 > V_69 ;
if ( V_28 ) {
* V_70 = V_72 . V_57 ;
V_72 . V_57 = V_68 ;
V_72 . V_58 = V_69 ;
} else {
V_72 . V_74 = true ;
}
} while ( ! F_23 ( V_6 , V_71 , V_72 ) );
return V_28 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_1 V_75 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 ;
T_1 V_70 ;
T_3 V_76 ;
V_77:
V_4 = F_30 ( V_2 , V_75 , & V_76 ) ;
if ( ! V_4 ) {
V_2 -> V_78 ++ ;
return;
}
V_11 = & V_4 -> V_12 [ V_76 ] ;
F_2 ( & V_4 -> V_8 ) ;
if ( ! V_6 || V_11 -> V_79 != V_6 -> V_80 ) {
V_6 = F_31 ( V_2 -> V_81 , V_11 -> V_79 ) ;
if ( ! V_6 ) {
V_2 -> V_82 ++ ;
goto V_83;
}
}
V_11 -> V_13 = 0 ;
if ( V_11 -> V_69 == V_84 ) {
V_11 -> V_85 = 1 ;
goto V_83;
}
if ( F_29 ( V_6 , V_75 , V_11 -> V_69 , & V_70 ) ) {
if ( V_70 && V_70 != V_86 ) {
F_3 ( & V_4 -> V_8 ) ;
V_75 = V_70 ;
goto V_77;
}
} else {
F_16 ( V_4 -> V_66 , V_6 -> V_67 ) ;
V_11 -> V_13 = 1 ;
F_19 () ;
if ( ! V_6 -> V_11 . V_74 ) {
F_3 ( & V_4 -> V_8 ) ;
goto V_77;
}
}
V_83:
F_3 ( & V_4 -> V_8 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_2 V_87 )
{
union V_53 V_71 , V_72 ;
bool V_13 ;
do {
V_71 = V_72 = F_9 ( V_6 -> V_11 ) ;
V_72 . V_59 = V_87 ;
if ( V_72 . V_73 < V_87 &&
V_72 . V_73 <= V_72 . V_58 ) {
V_72 . V_58 = V_72 . V_73 ;
V_72 . V_57 = V_86 ;
}
V_13 = V_72 . V_74 ;
V_72 . V_74 = 0 ;
} while ( ! F_23 ( V_6 , V_71 , V_72 ) );
if ( V_13 ) {
V_6 -> V_88 ++ ;
F_25 ( V_2 , V_6 ) ;
}
}
unsigned long F_33 ( struct V_16 * V_17 )
{
union V_53 V_71 , V_72 ;
struct V_1 * V_2 = V_17 -> V_81 -> V_40 . V_2 ;
struct V_5 * V_6 = V_17 -> V_40 . V_6 ;
T_1 V_89 ;
if ( ! V_2 || ! V_2 -> V_90 )
return V_64 ;
F_21 ( V_6 -> V_17 ) ;
do {
V_71 = V_72 = F_9 ( V_6 -> V_11 ) ;
V_89 = V_71 . V_57 | ( ( ( T_1 ) V_71 . V_59 ) << 24 ) ;
if ( ! V_71 . V_57 )
break;
V_72 . V_59 = V_72 . V_58 ;
V_72 . V_58 = 0xff ;
V_72 . V_57 = 0 ;
} while ( ! F_23 ( V_6 , V_71 , V_72 ) );
V_17 -> V_40 . V_91 [ 4 ] = V_89 ;
return F_24 ( V_2 , V_6 ) ;
}
int F_34 ( struct V_16 * V_17 , unsigned long V_79 ,
unsigned long V_73 )
{
union V_53 V_71 , V_72 ;
struct V_1 * V_2 = V_17 -> V_81 -> V_40 . V_2 ;
struct V_5 * V_6 , * V_39 = V_17 -> V_40 . V_6 ;
T_1 V_70 ;
bool V_13 ;
bool V_92 ;
if ( ! V_2 || ! V_2 -> V_90 )
return V_64 ;
V_92 = V_39 -> V_80 == V_79 ;
if ( V_92 )
V_6 = V_39 ;
else
V_6 = F_31 ( V_17 -> V_81 , V_79 ) ;
if ( ! V_6 )
return V_93 ;
do {
V_71 = V_72 = F_9 ( V_6 -> V_11 ) ;
V_72 . V_73 = V_73 ;
V_70 = 0 ;
V_13 = false ;
if ( V_73 < V_72 . V_59 ) {
if ( V_73 <= V_72 . V_58 ) {
V_70 = V_72 . V_57 ;
V_72 . V_58 = V_73 ;
V_72 . V_57 = V_86 ;
}
}
if ( V_73 > V_71 . V_73 ) {
V_13 = V_72 . V_74 ;
V_72 . V_74 = 0 ;
}
} while ( ! F_23 ( V_6 , V_71 , V_72 ) );
if ( V_70 && V_70 != V_86 ) {
V_39 -> V_94 ++ ;
F_4 ( V_2 , V_6 , V_70 ) ;
}
if ( V_13 ) {
V_39 -> V_88 ++ ;
F_25 ( V_2 , V_6 ) ;
}
return F_24 ( V_2 , V_39 ) ;
}
int F_35 ( struct V_16 * V_17 , unsigned long V_59 )
{
union V_53 V_71 , V_72 ;
struct V_1 * V_2 = V_17 -> V_81 -> V_40 . V_2 ;
struct V_5 * V_6 = V_17 -> V_40 . V_6 ;
T_1 V_70 ;
if ( ! V_2 || ! V_2 -> V_90 )
return V_64 ;
if ( V_59 > V_6 -> V_11 . V_59 ) {
F_32 ( V_2 , V_6 , V_59 ) ;
goto V_60;
} else if ( V_59 == V_6 -> V_11 . V_59 )
return V_65 ;
F_21 ( V_6 -> V_17 ) ;
do {
V_71 = V_72 = F_9 ( V_6 -> V_11 ) ;
V_70 = 0 ;
V_72 . V_59 = V_59 ;
if ( V_59 <= V_72 . V_58 ) {
V_70 = V_72 . V_57 ;
V_72 . V_57 = 0 ;
V_72 . V_58 = 0xff ;
}
} while ( ! F_23 ( V_6 , V_71 , V_72 ) );
if ( V_70 && V_70 != V_86 ) {
V_6 -> V_94 ++ ;
F_4 ( V_2 , V_6 , V_70 ) ;
}
V_60:
return F_24 ( V_2 , V_6 ) ;
}
int F_36 ( struct V_16 * V_17 , unsigned long V_89 )
{
struct V_1 * V_2 = V_17 -> V_81 -> V_40 . V_2 ;
struct V_5 * V_6 = V_17 -> V_40 . V_6 ;
struct V_3 * V_4 ;
struct V_10 * V_11 ;
T_1 V_68 = V_89 & 0x00ffffff ;
T_3 V_76 ;
if ( ! V_2 || ! V_2 -> V_90 )
return V_64 ;
F_32 ( V_2 , V_6 , V_89 >> 24 ) ;
if ( V_68 == V_86 )
goto V_60;
V_4 = F_30 ( V_2 , V_68 , & V_76 ) ;
if ( ! V_4 )
goto V_60;
V_11 = & V_4 -> V_12 [ V_76 ] ;
if ( V_11 -> V_95 ) {
V_6 -> V_94 ++ ;
F_4 ( V_2 , V_6 , V_68 ) ;
}
if ( ! F_37 ( & V_17 -> V_81 -> V_96 ) ) {
V_6 -> V_35 |= V_97 ;
V_6 -> V_98 = V_68 ;
}
V_60:
return F_24 ( V_2 , V_6 ) ;
}
static void F_38 ( int V_27 , void * V_99 )
{
switch ( V_27 ) {
case V_51 :
V_20 -> V_100 ( V_99 ) ;
break;
default:
F_39 ( 1 , L_1 , V_27 , V_99 ) ;
break;
}
}
void F_40 ( void )
{
int V_29 ;
unsigned int V_41 = F_13 () ;
struct V_25 * V_101 ;
V_29 = V_41 >> V_19 ;
V_101 = & V_20 -> V_21 [ V_29 ] ;
if ( V_101 -> V_22 ) {
F_38 ( V_101 -> V_33 . V_35 ,
V_101 -> V_22 ) ;
V_101 -> V_22 = NULL ;
F_11 () ;
V_101 -> V_33 . V_35 = 0 ;
}
}
