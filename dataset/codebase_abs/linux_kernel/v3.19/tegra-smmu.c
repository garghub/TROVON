static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned long V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , unsigned long V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , struct V_6 * V_6 ,
unsigned long V_4 )
{
T_2 V_7 = V_6 ? F_6 ( V_6 ) : 0 ;
T_1 V_3 ;
if ( V_6 ) {
V_4 &= ~ ( V_2 -> V_8 -> V_9 -> V_10 - 1 ) ;
if ( V_2 -> V_8 -> V_9 -> V_11 > 32 ) {
#ifdef F_7
V_3 = ( V_7 >> 32 ) & V_12 ;
#else
V_3 = 0 ;
#endif
F_1 ( V_2 , V_3 , V_13 ) ;
}
V_3 = ( V_7 + V_4 ) | V_14 ;
} else {
V_3 = V_15 ;
}
F_1 ( V_2 , V_3 , V_16 ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_17 , V_18 ) ;
}
static inline void F_9 ( struct V_1 * V_2 ,
unsigned long V_19 )
{
T_1 V_3 ;
V_3 = V_20 | F_10 ( V_19 ) |
V_17 ;
F_1 ( V_2 , V_3 , V_18 ) ;
}
static inline void F_11 ( struct V_1 * V_2 ,
unsigned long V_19 ,
unsigned long V_21 )
{
T_1 V_3 ;
V_3 = V_20 | F_10 ( V_19 ) |
F_12 ( V_21 ) ;
F_1 ( V_2 , V_3 , V_18 ) ;
}
static inline void F_13 ( struct V_1 * V_2 ,
unsigned long V_19 ,
unsigned long V_21 )
{
T_1 V_3 ;
V_3 = V_20 | F_10 ( V_19 ) |
F_14 ( V_21 ) ;
F_1 ( V_2 , V_3 , V_18 ) ;
}
static inline void F_15 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_22 ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int * V_23 )
{
unsigned long V_24 ;
F_17 ( & V_2 -> V_25 ) ;
V_24 = F_18 ( V_2 -> V_26 , V_2 -> V_9 -> V_27 ) ;
if ( V_24 >= V_2 -> V_9 -> V_27 ) {
F_19 ( & V_2 -> V_25 ) ;
return - V_28 ;
}
F_20 ( V_24 , V_2 -> V_26 ) ;
* V_23 = V_24 ;
F_19 ( & V_2 -> V_25 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , unsigned int V_24 )
{
F_17 ( & V_2 -> V_25 ) ;
F_22 ( V_24 , V_2 -> V_26 ) ;
F_19 ( & V_2 -> V_25 ) ;
}
static bool F_23 ( enum V_29 V_30 )
{
return false ;
}
static int F_24 ( struct V_31 * V_32 )
{
struct V_33 * V_34 ;
unsigned int V_35 ;
T_3 * V_36 ;
V_34 = F_25 ( sizeof( * V_34 ) , V_37 ) ;
if ( ! V_34 )
return - V_38 ;
V_34 -> V_39 = V_40 | V_41 | V_42 ;
V_34 -> V_32 = V_32 ;
V_34 -> V_36 = F_26 ( V_37 | V_43 ) ;
if ( ! V_34 -> V_36 ) {
F_27 ( V_34 ) ;
return - V_38 ;
}
V_34 -> V_44 = F_26 ( V_37 ) ;
if ( ! V_34 -> V_44 ) {
F_28 ( V_34 -> V_36 ) ;
F_27 ( V_34 ) ;
return - V_38 ;
}
V_36 = F_29 ( V_34 -> V_36 ) ;
F_30 ( V_34 -> V_36 ) ;
for ( V_35 = 0 ; V_35 < V_45 ; V_35 ++ )
V_36 [ V_35 ] = 0 ;
V_36 = F_29 ( V_34 -> V_44 ) ;
F_30 ( V_34 -> V_44 ) ;
for ( V_35 = 0 ; V_35 < V_45 ; V_35 ++ )
V_36 [ V_35 ] = 0 ;
V_32 -> V_46 = V_34 ;
return 0 ;
}
static void F_31 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_46 ;
F_32 ( V_34 -> V_36 ) ;
F_27 ( V_34 ) ;
}
static const struct V_47 *
F_33 ( struct V_1 * V_2 , unsigned int V_48 )
{
const struct V_47 * V_49 = NULL ;
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_9 -> V_50 ; V_35 ++ ) {
if ( V_2 -> V_9 -> V_51 [ V_35 ] . V_48 == V_48 ) {
V_49 = & V_2 -> V_9 -> V_51 [ V_35 ] ;
break;
}
}
return V_49 ;
}
static void F_34 ( struct V_1 * V_2 , unsigned int V_48 ,
unsigned int V_19 )
{
const struct V_47 * V_49 ;
unsigned int V_35 ;
T_1 V_3 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_9 -> V_52 ; V_35 ++ ) {
const struct V_53 * V_54 = & V_2 -> V_9 -> V_55 [ V_35 ] ;
if ( V_54 -> V_48 != V_48 )
continue;
V_3 = F_3 ( V_2 , V_54 -> V_2 . V_56 ) ;
V_3 |= F_35 ( V_54 -> V_2 . V_57 ) ;
F_1 ( V_2 , V_3 , V_54 -> V_2 . V_56 ) ;
}
V_49 = F_33 ( V_2 , V_48 ) ;
if ( V_49 ) {
V_3 = F_3 ( V_2 , V_49 -> V_56 ) ;
V_3 &= ~ V_58 ;
V_3 |= F_36 ( V_19 ) ;
V_3 |= V_59 ;
F_1 ( V_2 , V_3 , V_49 -> V_56 ) ;
}
}
static void F_37 ( struct V_1 * V_2 , unsigned int V_48 ,
unsigned int V_19 )
{
const struct V_47 * V_49 ;
unsigned int V_35 ;
T_1 V_3 ;
V_49 = F_33 ( V_2 , V_48 ) ;
if ( V_49 ) {
V_3 = F_3 ( V_2 , V_49 -> V_56 ) ;
V_3 &= ~ V_58 ;
V_3 |= F_36 ( V_19 ) ;
V_3 &= ~ V_59 ;
F_1 ( V_2 , V_3 , V_49 -> V_56 ) ;
}
for ( V_35 = 0 ; V_35 < V_2 -> V_9 -> V_52 ; V_35 ++ ) {
const struct V_53 * V_54 = & V_2 -> V_9 -> V_55 [ V_35 ] ;
if ( V_54 -> V_48 != V_48 )
continue;
V_3 = F_3 ( V_2 , V_54 -> V_2 . V_56 ) ;
V_3 &= ~ F_35 ( V_54 -> V_2 . V_57 ) ;
F_1 ( V_2 , V_3 , V_54 -> V_2 . V_56 ) ;
}
}
static int F_38 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
T_1 V_3 ;
int V_60 ;
if ( V_34 -> V_61 > 0 ) {
V_34 -> V_61 ++ ;
return 0 ;
}
V_60 = F_16 ( V_2 , & V_34 -> V_24 ) ;
if ( V_60 < 0 )
return V_60 ;
V_2 -> V_9 -> V_62 -> V_63 ( V_34 -> V_36 , 0 , V_64 ) ;
F_5 ( V_2 , V_34 -> V_36 , 0 ) ;
F_9 ( V_2 , V_34 -> V_24 ) ;
F_1 ( V_2 , V_34 -> V_24 & 0x7f , V_65 ) ;
V_3 = F_39 ( V_34 -> V_36 , V_34 -> V_39 ) ;
F_1 ( V_2 , V_3 , V_66 ) ;
F_15 ( V_2 ) ;
V_34 -> V_2 = V_2 ;
V_34 -> V_61 ++ ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
if ( -- V_34 -> V_61 > 0 )
return;
F_21 ( V_2 , V_34 -> V_24 ) ;
V_34 -> V_2 = NULL ;
}
static int F_41 ( struct V_31 * V_32 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_69 . V_70 ;
struct V_33 * V_34 = V_32 -> V_46 ;
struct V_71 * V_72 = V_68 -> V_73 ;
struct V_74 args ;
unsigned int V_75 = 0 ;
int V_60 = 0 ;
while ( ! F_42 ( V_72 , L_1 , L_2 , V_75 ,
& args ) ) {
unsigned int V_48 = args . args [ 0 ] ;
if ( args . V_72 != V_2 -> V_68 -> V_73 ) {
F_43 ( args . V_72 ) ;
continue;
}
F_43 ( args . V_72 ) ;
V_60 = F_38 ( V_2 , V_34 ) ;
if ( V_60 < 0 )
return V_60 ;
F_34 ( V_2 , V_48 , V_34 -> V_24 ) ;
V_75 ++ ;
}
if ( V_75 == 0 )
return - V_76 ;
return 0 ;
}
static void F_44 ( struct V_31 * V_32 , struct V_67 * V_68 )
{
struct V_33 * V_34 = V_32 -> V_46 ;
struct V_71 * V_72 = V_68 -> V_73 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_74 args ;
unsigned int V_75 = 0 ;
while ( ! F_42 ( V_72 , L_1 , L_2 , V_75 ,
& args ) ) {
unsigned int V_48 = args . args [ 0 ] ;
if ( args . V_72 != V_2 -> V_68 -> V_73 ) {
F_43 ( args . V_72 ) ;
continue;
}
F_43 ( args . V_72 ) ;
F_37 ( V_2 , V_48 , V_34 -> V_24 ) ;
F_40 ( V_2 , V_34 ) ;
V_75 ++ ;
}
}
static T_1 * F_45 ( struct V_33 * V_34 , T_4 V_21 ,
struct V_6 * * V_77 )
{
T_1 * V_36 = F_29 ( V_34 -> V_36 ) , * V_78 , * V_44 ;
T_1 V_79 = ( V_21 >> V_80 ) & 0x3ff ;
T_1 V_81 = ( V_21 >> V_82 ) & 0x3ff ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_6 * V_6 ;
unsigned int V_35 ;
if ( V_36 [ V_79 ] == 0 ) {
V_6 = F_26 ( V_37 | V_43 ) ;
if ( ! V_6 )
return NULL ;
V_78 = F_29 ( V_6 ) ;
F_30 ( V_6 ) ;
for ( V_35 = 0 ; V_35 < V_83 ; V_35 ++ )
V_78 [ V_35 ] = 0 ;
V_2 -> V_9 -> V_62 -> V_63 ( V_6 , 0 , V_84 ) ;
V_36 [ V_79 ] = F_46 ( V_6 , V_85 | V_86 ) ;
V_2 -> V_9 -> V_62 -> V_63 ( V_34 -> V_36 , V_79 << 2 , 4 ) ;
F_5 ( V_2 , V_34 -> V_36 , V_79 << 2 ) ;
F_11 ( V_2 , V_34 -> V_24 , V_21 ) ;
F_15 ( V_2 ) ;
} else {
V_6 = F_47 ( V_36 [ V_79 ] & V_87 ) ;
V_78 = F_29 ( V_6 ) ;
}
* V_77 = V_6 ;
V_44 = F_29 ( V_34 -> V_44 ) ;
if ( V_78 [ V_81 ] == 0 )
V_44 [ V_79 ] ++ ;
return & V_78 [ V_81 ] ;
}
static void F_48 ( struct V_33 * V_34 , T_4 V_21 )
{
T_1 V_79 = ( V_21 >> V_80 ) & 0x3ff ;
T_1 V_81 = ( V_21 >> V_82 ) & 0x3ff ;
T_1 * V_44 = F_29 ( V_34 -> V_44 ) ;
T_1 * V_36 = F_29 ( V_34 -> V_36 ) , * V_78 ;
struct V_6 * V_6 ;
V_6 = F_47 ( V_36 [ V_79 ] & V_87 ) ;
V_78 = F_29 ( V_6 ) ;
if ( V_78 [ V_81 ] != 0 ) {
if ( -- V_44 [ V_79 ] == 0 ) {
F_32 ( V_6 ) ;
F_28 ( V_6 ) ;
V_36 [ V_79 ] = 0 ;
}
V_78 [ V_81 ] = 0 ;
}
}
static int F_49 ( struct V_31 * V_32 , unsigned long V_21 ,
T_2 V_88 , T_5 V_89 , int V_90 )
{
struct V_33 * V_34 = V_32 -> V_46 ;
struct V_1 * V_2 = V_34 -> V_2 ;
unsigned long V_4 ;
struct V_6 * V_6 ;
T_1 * V_81 ;
V_81 = F_45 ( V_34 , V_21 , & V_6 ) ;
if ( ! V_81 )
return - V_38 ;
* V_81 = F_50 ( V_88 ) | V_91 ;
V_4 = F_51 ( V_81 ) ;
V_2 -> V_9 -> V_62 -> V_63 ( V_6 , V_4 , 4 ) ;
F_5 ( V_2 , V_6 , V_4 ) ;
F_13 ( V_2 , V_34 -> V_24 , V_21 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
static T_5 F_52 ( struct V_31 * V_32 , unsigned long V_21 ,
T_5 V_89 )
{
struct V_33 * V_34 = V_32 -> V_46 ;
struct V_1 * V_2 = V_34 -> V_2 ;
unsigned long V_4 ;
struct V_6 * V_6 ;
T_1 * V_81 ;
V_81 = F_45 ( V_34 , V_21 , & V_6 ) ;
if ( ! V_81 )
return 0 ;
V_4 = F_51 ( V_81 ) ;
F_48 ( V_34 , V_21 ) ;
V_2 -> V_9 -> V_62 -> V_63 ( V_6 , V_4 , 4 ) ;
F_5 ( V_2 , V_6 , V_4 ) ;
F_13 ( V_2 , V_34 -> V_24 , V_21 ) ;
F_15 ( V_2 ) ;
return V_89 ;
}
static T_2 F_53 ( struct V_31 * V_32 ,
T_4 V_21 )
{
struct V_33 * V_34 = V_32 -> V_46 ;
struct V_6 * V_6 ;
unsigned long V_92 ;
T_1 * V_81 ;
V_81 = F_45 ( V_34 , V_21 , & V_6 ) ;
V_92 = * V_81 & V_87 ;
return F_54 ( V_92 ) ;
}
static struct V_1 * F_55 ( struct V_71 * V_72 )
{
struct V_93 * V_94 ;
struct V_95 * V_8 ;
V_94 = F_56 ( V_72 ) ;
if ( ! V_94 )
return NULL ;
V_8 = F_57 ( V_94 ) ;
if ( ! V_8 )
return NULL ;
return V_8 -> V_2 ;
}
static int F_58 ( struct V_67 * V_68 )
{
struct V_71 * V_72 = V_68 -> V_73 ;
struct V_74 args ;
unsigned int V_75 = 0 ;
while ( F_42 ( V_72 , L_1 , L_2 , V_75 ,
& args ) == 0 ) {
struct V_1 * V_2 ;
V_2 = F_55 ( args . V_72 ) ;
if ( V_2 ) {
V_68 -> V_69 . V_70 = V_2 ;
break;
}
V_75 ++ ;
}
return 0 ;
}
static void F_59 ( struct V_67 * V_68 )
{
V_68 -> V_69 . V_70 = NULL ;
}
static void F_60 ( void )
{
static const struct V_96 V_97 [] = {
{ . V_98 = L_3 , } ,
{ }
} ;
struct V_71 * V_99 ;
V_99 = F_61 ( NULL , V_97 ) ;
if ( V_99 ) {
F_62 ( V_99 ) ;
F_43 ( V_99 ) ;
}
}
struct V_1 * F_63 ( struct V_67 * V_68 ,
const struct V_100 * V_9 ,
struct V_95 * V_8 )
{
struct V_1 * V_2 ;
T_5 V_89 ;
T_1 V_3 ;
int V_60 ;
if ( ! V_9 )
return NULL ;
V_2 = F_64 ( V_68 , sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 )
return F_65 ( - V_38 ) ;
V_8 -> V_2 = V_2 ;
V_89 = F_66 ( V_9 -> V_27 ) * sizeof( long ) ;
V_2 -> V_26 = F_64 ( V_68 , V_89 , V_37 ) ;
if ( ! V_2 -> V_26 )
return F_65 ( - V_38 ) ;
F_67 ( & V_2 -> V_25 ) ;
V_2 -> V_5 = V_8 -> V_5 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_68 = V_68 ;
V_2 -> V_8 = V_8 ;
V_3 = V_101 | F_68 ( 0x3f ) ;
if ( V_9 -> V_102 )
V_3 |= F_69 ( 8 ) ;
F_1 ( V_2 , V_3 , V_103 ) ;
V_3 = V_104 |
F_70 ( 0x20 ) ;
if ( V_9 -> V_105 )
V_3 |= V_106 ;
F_1 ( V_2 , V_3 , V_107 ) ;
F_5 ( V_2 , NULL , 0 ) ;
F_8 ( V_2 ) ;
F_1 ( V_2 , V_108 , V_22 ) ;
F_15 ( V_2 ) ;
F_60 () ;
V_60 = F_71 ( & V_109 , & V_110 ) ;
if ( V_60 < 0 )
return F_65 ( V_60 ) ;
return V_2 ;
}
