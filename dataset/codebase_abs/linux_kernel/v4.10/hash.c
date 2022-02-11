static inline void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned int V_7 = V_4 -> V_8 + V_6 -> V_9 ;
if ( ! V_6 -> V_10 )
V_7 &= ~ V_11 ;
F_3 ( & V_2 -> V_12 , V_7 ) ;
F_4 ( & V_2 -> V_13 , V_4 -> V_13 , V_14 ) ;
V_2 -> V_13 . V_15 = V_6 -> V_9 ;
}
static inline bool
F_5 ( struct V_1 * V_2 )
{
V_2 -> V_13 . V_15 = 0 ;
return F_6 ( & V_2 -> V_12 ) ;
}
static inline int
F_7 ( struct V_16 * V_4 , T_1 V_17 )
{
V_4 -> V_18 = F_8 ( V_19 -> V_20 -> V_21 , V_17 ,
& V_4 -> V_22 ) ;
if ( ! V_4 -> V_18 )
return - V_23 ;
return 0 ;
}
static inline void
F_9 ( struct V_16 * V_4 )
{
if ( ! V_4 -> V_18 )
return;
F_10 ( V_19 -> V_20 -> V_21 , V_4 -> V_18 ,
V_4 -> V_22 ) ;
}
static int F_11 ( struct V_16 * V_4 ,
T_1 V_17 )
{
if ( V_4 -> V_24 )
return 0 ;
V_4 -> V_24 = F_8 ( V_19 -> V_20 -> V_25 , V_17 ,
& V_4 -> V_26 ) ;
if ( ! V_4 -> V_24 )
return - V_23 ;
return 0 ;
}
static void F_12 ( struct V_16 * V_4 )
{
if ( ! V_4 -> V_24 )
return;
F_10 ( V_19 -> V_20 -> V_25 , V_4 -> V_24 ,
V_4 -> V_26 ) ;
V_4 -> V_24 = NULL ;
}
static inline void F_13 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_12 ( & V_6 -> V_4 . V_20 ) ;
}
static inline void F_14 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_15 ( V_19 -> V_27 , V_4 -> V_13 , V_6 -> V_28 , V_14 ) ;
F_9 ( & V_6 -> V_4 . V_20 ) ;
F_16 ( & V_6 -> V_12 ) ;
}
static inline void F_17 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( F_18 ( & V_6 -> V_12 ) == V_29 )
F_14 ( V_4 ) ;
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( F_18 ( & V_6 -> V_12 ) == V_29 )
F_13 ( V_4 ) ;
}
static int F_20 ( struct V_5 * V_6 )
{
unsigned int V_30 , V_31 ;
V_30 = V_6 -> V_7 & V_11 ;
V_31 = ( V_30 < 56 ) ? ( 56 - V_30 ) : ( 64 + 56 - V_30 ) ;
return V_31 ;
}
static int F_21 ( struct V_5 * V_6 , T_2 * V_32 )
{
unsigned int V_30 , V_31 ;
V_32 [ 0 ] = 0x80 ;
V_30 = V_6 -> V_7 & V_11 ;
V_31 = F_20 ( V_6 ) ;
memset ( V_32 + 1 , 0 , V_31 - 1 ) ;
if ( V_6 -> V_33 ) {
T_3 V_34 = F_22 ( V_6 -> V_7 << 3 ) ;
memcpy ( V_32 + V_31 , & V_34 , sizeof( V_34 ) ) ;
} else {
T_4 V_34 = F_23 ( V_6 -> V_7 << 3 ) ;
memcpy ( V_32 + V_31 , & V_34 , sizeof( V_34 ) ) ;
}
return V_31 + 8 ;
}
static void F_24 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_35 * V_36 = & V_6 -> V_4 . V_37 ;
struct V_38 * V_39 = V_6 -> V_12 . V_39 ;
struct V_40 * V_41 ;
unsigned int V_42 = 0 ;
T_5 V_43 ;
T_6 V_7 ;
unsigned int V_44 ;
int V_45 ;
F_25 ( V_39 , & V_6 -> V_46 ) ;
F_26 ( V_39 -> V_47 , & V_6 -> V_46 , sizeof( V_6 -> V_46 ) ) ;
if ( ! V_36 -> V_48 ) {
V_44 = F_27 ( F_28 ( V_4 ) ) ;
for ( V_45 = 0 ; V_45 < V_44 / 4 ; V_45 ++ )
F_29 ( V_6 -> V_49 [ V_45 ] , V_39 -> V_50 + F_30 ( V_45 ) ) ;
}
if ( V_6 -> V_9 )
F_26 ( V_39 -> V_47 + V_51 ,
V_6 -> V_18 , V_6 -> V_9 ) ;
V_7 = F_31 ( T_6 , V_4 -> V_8 + V_6 -> V_9 - V_36 -> V_48 ,
V_52 ) ;
if ( ! V_6 -> V_10 ) {
V_42 = V_7 & V_11 ;
V_7 &= ~ V_11 ;
}
if ( V_7 - V_6 -> V_9 )
V_36 -> V_48 += F_32 ( V_4 -> V_13 , V_6 -> V_28 ,
V_39 -> V_47 +
V_51 +
V_6 -> V_9 ,
V_7 - V_6 -> V_9 ,
V_36 -> V_48 ) ;
V_41 = & V_6 -> V_46 ;
V_43 = F_33 ( V_41 ) & V_53 ;
if ( V_6 -> V_10 && V_36 -> V_48 == V_4 -> V_8 &&
V_6 -> V_7 <= V_54 ) {
if ( V_43 == V_55 )
V_43 = V_56 ;
else if ( V_43 == V_57 )
V_43 = V_58 ;
}
if ( V_43 == V_56 ||
V_43 == V_58 ) {
if ( V_7 &&
V_6 -> V_7 <= V_54 ) {
F_34 ( V_41 , V_6 -> V_7 ) ;
} else {
int V_59 = F_20 ( V_6 ) + 8 ;
if ( V_7 + V_59 > V_52 ) {
V_7 &= V_11 ;
V_42 = 64 - V_59 ;
F_35 ( V_6 -> V_18 ,
V_39 -> V_47 +
V_51 + V_7 ,
V_42 ) ;
} else {
V_7 += F_21 ( V_6 ,
V_39 -> V_47 + V_7 +
V_51 ) ;
}
if ( V_43 == V_58 )
V_43 = V_57 ;
else
V_43 = V_55 ;
}
}
F_36 ( V_41 , V_7 ) ;
F_37 ( V_41 , V_43 , V_53 ) ;
F_26 ( V_39 -> V_47 , V_41 , sizeof( * V_41 ) ) ;
if ( V_43 == V_55 )
F_37 ( V_41 , V_57 ,
V_53 ) ;
V_6 -> V_9 = V_42 ;
F_38 ( V_39 , V_60 ) ;
F_29 ( V_61 , V_39 -> V_50 + V_62 ) ;
F_39 ( F_40 ( V_39 -> V_50 + V_63 ) &
V_64 ) ;
F_41 ( V_64 , V_39 -> V_50 + V_63 ) ;
}
static int F_42 ( struct V_3 * V_4 , T_5 V_65 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_35 * V_36 = & V_6 -> V_4 . V_37 ;
if ( V_36 -> V_48 < ( V_4 -> V_8 - V_6 -> V_9 ) )
return - V_66 ;
return 0 ;
}
static inline void F_43 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_67 * V_68 = & V_6 -> V_12 ;
F_44 ( V_68 , V_68 -> V_39 ) ;
}
static void F_45 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_35 * V_36 = & V_6 -> V_4 . V_37 ;
V_36 -> V_48 = 0 ;
}
static void F_46 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_67 * V_12 = & V_6 -> V_12 ;
if ( V_12 -> V_69 . V_70 -> V_17 & V_71 ) {
struct V_38 * V_39 = V_12 -> V_39 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < F_47 ( V_6 -> V_49 ) ; V_45 ++ )
F_29 ( V_6 -> V_49 [ V_45 ] , V_39 -> V_50 +
F_30 ( V_45 ) ) ;
}
F_48 ( V_12 ) ;
}
static void F_49 ( struct V_72 * V_4 )
{
struct V_3 * V_73 = F_50 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_73 ) ;
if ( F_18 ( & V_6 -> V_12 ) == V_29 )
F_46 ( V_73 ) ;
else
F_24 ( V_73 ) ;
}
static int F_51 ( struct V_72 * V_4 , T_5 V_65 )
{
struct V_3 * V_73 = F_50 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_73 ) ;
if ( F_18 ( & V_6 -> V_12 ) == V_29 )
return F_52 ( & V_6 -> V_12 , V_65 ) ;
return F_42 ( V_73 , V_65 ) ;
}
static void F_53 ( struct V_72 * V_4 )
{
struct V_3 * V_73 = F_50 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_73 ) ;
struct V_38 * V_39 = V_6 -> V_12 . V_39 ;
unsigned int V_44 ;
int V_45 ;
V_44 = F_27 ( F_28 ( V_73 ) ) ;
if ( F_18 ( & V_6 -> V_12 ) == V_29 &&
( V_6 -> V_12 . V_69 . V_74 -> V_17 & V_75 ) == V_76 ) {
T_7 * V_77 = NULL ;
V_77 = V_6 -> V_12 . V_69 . V_74 -> V_41 -> V_78 . V_79 . V_79 ;
for ( V_45 = 0 ; V_45 < V_44 / 4 ; V_45 ++ )
V_6 -> V_49 [ V_45 ] = F_54 ( V_77 [ V_45 ] ) ;
memcpy ( V_73 -> V_80 , V_77 , V_44 ) ;
} else {
for ( V_45 = 0 ; V_45 < V_44 / 4 ; V_45 ++ )
V_6 -> V_49 [ V_45 ] = F_55 ( V_39 -> V_50 +
F_30 ( V_45 ) ) ;
if ( V_6 -> V_10 ) {
if ( V_6 -> V_33 ) {
T_7 * V_80 = ( void * ) V_73 -> V_80 ;
for ( V_45 = 0 ; V_45 < V_44 / 4 ; V_45 ++ )
V_80 [ V_45 ] = F_54 ( V_6 -> V_49 [ V_45 ] ) ;
} else {
T_8 * V_80 = ( void * ) V_73 -> V_80 ;
for ( V_45 = 0 ; V_45 < V_44 / 4 ; V_45 ++ )
V_80 [ V_45 ] = F_56 ( V_6 -> V_49 [ V_45 ] ) ;
}
}
}
F_57 ( V_73 -> V_8 , & V_39 -> V_81 ) ;
}
static void F_58 ( struct V_72 * V_4 ,
struct V_38 * V_39 )
{
struct V_3 * V_73 = F_50 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_73 ) ;
V_6 -> V_12 . V_39 = V_39 ;
if ( F_18 ( & V_6 -> V_12 ) == V_29 )
F_43 ( V_73 ) ;
else
F_45 ( V_73 ) ;
}
static void F_59 ( struct V_72 * V_4 )
{
struct V_3 * V_73 = F_50 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_73 ) ;
if ( V_6 -> V_10 )
F_19 ( V_73 ) ;
F_17 ( V_73 ) ;
if ( V_6 -> V_9 )
F_32 ( V_73 -> V_13 , V_6 -> V_28 ,
V_6 -> V_18 ,
V_6 -> V_9 ,
V_73 -> V_8 - V_6 -> V_9 ) ;
}
static void F_60 ( struct V_3 * V_4 ,
struct V_40 * V_82 , bool V_33 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_37 ( V_82 ,
V_83 |
V_55 ,
V_84 |
V_53 ) ;
F_34 ( V_82 , 0 ) ;
F_36 ( V_82 , 0 ) ;
V_6 -> V_46 = * V_82 ;
V_6 -> V_7 = 0 ;
V_6 -> V_33 = V_33 ;
}
static inline int F_61 ( struct V_85 * V_86 )
{
struct V_87 * V_78 = F_62 ( V_86 ) ;
V_78 -> V_12 . V_88 = & V_89 ;
F_63 ( F_64 ( V_86 ) ,
sizeof( struct V_5 ) ) ;
return 0 ;
}
static bool F_65 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
bool V_90 = false ;
if ( V_6 -> V_9 + V_4 -> V_8 < V_91 && ! V_6 -> V_10 ) {
V_90 = true ;
if ( ! V_4 -> V_8 )
return V_90 ;
F_32 ( V_4 -> V_13 , V_6 -> V_28 ,
V_6 -> V_18 + V_6 -> V_9 ,
V_4 -> V_8 , 0 ) ;
V_6 -> V_9 += V_4 -> V_8 ;
}
return V_90 ;
}
static struct V_40 *
F_66 ( struct V_92 * V_69 ,
struct V_40 * V_82 , unsigned int V_93 ,
T_1 V_17 )
{
struct V_40 * V_41 ;
int V_94 ;
V_41 = F_67 ( V_69 , V_82 , false , V_17 ) ;
if ( F_68 ( V_41 ) )
return V_41 ;
F_36 ( V_41 , V_93 ) ;
V_94 = F_69 ( V_69 , V_17 ) ;
if ( V_94 )
return F_70 ( V_94 ) ;
if ( F_71 ( V_82 ) )
F_37 ( V_82 ,
V_57 ,
V_53 ) ;
return V_41 ;
}
static int
F_72 ( struct V_92 * V_69 ,
struct V_5 * V_6 ,
T_1 V_17 )
{
struct V_16 * V_95 = & V_6 -> V_4 . V_20 ;
int V_94 ;
if ( ! V_6 -> V_9 )
return 0 ;
V_94 = F_7 ( V_95 , V_17 ) ;
if ( V_94 )
return V_94 ;
memcpy ( V_95 -> V_18 , V_6 -> V_18 , V_6 -> V_9 ) ;
return F_73 ( V_69 ,
V_51 ,
V_95 -> V_22 ,
V_6 -> V_9 ,
V_96 ,
V_17 ) ;
}
static struct V_40 *
F_74 ( struct V_92 * V_69 ,
struct V_1 * V_97 ,
struct V_5 * V_6 ,
unsigned int V_93 , T_1 V_17 )
{
struct V_16 * V_95 = & V_6 -> V_4 . V_20 ;
unsigned int V_7 , V_59 , V_98 = 0 ;
struct V_40 * V_41 ;
int V_94 ;
if ( V_6 -> V_7 <= V_54 && V_93 ) {
V_41 = F_66 ( V_69 , & V_6 -> V_46 , V_93 ,
V_17 ) ;
if ( F_68 ( V_41 ) )
return V_41 ;
F_34 ( V_41 , V_6 -> V_7 ) ;
F_37 ( V_41 , F_71 ( V_41 ) ?
V_56 :
V_58 ,
V_53 ) ;
V_94 = F_75 ( V_69 ,
V_99 ,
V_51 ,
V_100 , V_17 ) ;
if ( V_94 )
return F_70 ( - V_23 ) ;
return V_41 ;
}
V_94 = F_11 ( V_95 , V_17 ) ;
if ( V_94 )
return F_70 ( V_94 ) ;
V_59 = F_21 ( V_6 , V_95 -> V_24 ) ;
V_7 = F_76 ( V_52 - V_93 , V_59 ) ;
if ( V_7 ) {
V_94 = F_73 ( V_69 ,
V_51 +
V_93 ,
V_95 -> V_26 ,
V_7 , V_96 ,
V_17 ) ;
if ( V_94 )
return F_70 ( V_94 ) ;
V_41 = F_66 ( V_69 , & V_6 -> V_46 , V_93 + V_7 ,
V_17 ) ;
if ( F_68 ( V_41 ) )
return V_41 ;
if ( V_7 == V_59 )
return V_41 ;
V_98 += V_7 ;
}
V_94 = F_73 ( V_69 ,
V_51 ,
V_95 -> V_26 +
V_98 ,
V_59 - V_98 ,
V_96 ,
V_17 ) ;
if ( V_94 )
return F_70 ( V_94 ) ;
return F_66 ( V_69 , & V_6 -> V_46 , V_59 - V_98 ,
V_17 ) ;
}
static int F_77 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 V_17 = ( V_4 -> V_12 . V_17 & V_101 ) ?
V_102 : V_103 ;
struct V_67 * V_68 = & V_6 -> V_12 ;
struct V_1 V_2 ;
struct V_40 * V_41 = NULL ;
unsigned int V_93 ;
bool V_104 = false ;
int V_94 ;
T_5 type ;
V_68 -> V_69 . V_70 = NULL ;
V_68 -> V_69 . V_74 = NULL ;
if ( ! F_71 ( & V_6 -> V_46 ) )
V_104 = true ;
if ( V_6 -> V_28 ) {
V_94 = F_78 ( V_19 -> V_27 , V_4 -> V_13 , V_6 -> V_28 ,
V_14 ) ;
if ( ! V_94 ) {
V_94 = - V_23 ;
goto V_105;
}
}
F_79 ( & V_68 -> V_69 ) ;
F_1 ( & V_2 , V_4 ) ;
V_94 = F_72 ( & V_68 -> V_69 , V_6 , V_17 ) ;
if ( V_94 )
goto V_106;
if ( V_2 . V_13 . V_107 ) {
while ( true ) {
V_94 = F_80 ( & V_68 -> V_69 ,
& V_2 . V_12 ,
& V_2 . V_13 , V_17 ) ;
if ( V_94 )
goto V_106;
V_93 = V_2 . V_12 . V_108 ;
if ( ! F_5 ( & V_2 ) )
break;
V_41 = F_66 ( & V_68 -> V_69 , & V_6 -> V_46 ,
V_93 , V_17 ) ;
if ( F_68 ( V_41 ) ) {
V_94 = F_81 ( V_41 ) ;
goto V_106;
}
}
} else {
V_93 = V_2 . V_12 . V_108 ;
}
if ( V_6 -> V_10 )
V_41 = F_74 ( & V_68 -> V_69 , & V_2 , V_6 ,
V_93 , V_17 ) ;
else if ( V_93 )
V_41 = F_66 ( & V_68 -> V_69 , & V_6 -> V_46 ,
V_93 , V_17 ) ;
if ( F_68 ( V_41 ) ) {
V_94 = F_81 ( V_41 ) ;
goto V_106;
}
type = V_68 -> V_69 . V_74 -> V_17 & V_75 ;
if ( V_41 && type != V_76 ) {
V_94 = F_82 ( & V_68 -> V_69 , V_17 ) ;
if ( V_94 )
goto V_106;
}
if ( ! V_6 -> V_10 )
V_6 -> V_9 = V_4 -> V_8 + V_6 -> V_9 -
V_2 . V_12 . V_7 ;
else
V_6 -> V_9 = 0 ;
V_68 -> V_69 . V_74 -> V_17 |= V_109 ;
if ( type != V_76 )
V_68 -> V_69 . V_74 -> V_17 |= V_110 ;
if ( V_104 ) {
V_68 -> V_69 . V_70 -> V_17 |= V_71 ;
}
return 0 ;
V_106:
F_16 ( V_68 ) ;
F_15 ( V_19 -> V_27 , V_4 -> V_13 , V_6 -> V_28 , V_14 ) ;
V_105:
F_19 ( V_4 ) ;
return V_94 ;
}
static int F_83 ( struct V_3 * V_4 , bool * V_90 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_6 -> V_28 = F_84 ( V_4 -> V_13 , V_4 -> V_8 ) ;
if ( V_6 -> V_28 < 0 ) {
F_85 ( V_19 -> V_27 , L_1 ) ;
return V_6 -> V_28 ;
}
* V_90 = F_65 ( V_4 ) ;
if ( * V_90 )
return 0 ;
if ( V_19 -> V_111 -> V_112 )
return F_77 ( V_4 ) ;
else
return 0 ;
}
static int F_86 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_38 * V_39 ;
bool V_90 = false ;
int V_94 ;
V_94 = F_83 ( V_4 , & V_90 ) ;
if ( V_94 )
return V_94 ;
if ( V_90 )
return 0 ;
V_39 = F_87 ( V_4 -> V_8 ) ;
F_58 ( & V_4 -> V_12 , V_39 ) ;
V_94 = F_88 ( & V_4 -> V_12 , & V_6 -> V_12 ) ;
if ( F_89 ( & V_4 -> V_12 , V_94 ) )
F_17 ( V_4 ) ;
return V_94 ;
}
static int F_90 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_6 -> V_7 += V_4 -> V_8 ;
return F_86 ( V_4 ) ;
}
static int F_91 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_40 * V_82 = & V_6 -> V_46 ;
F_34 ( V_82 , V_6 -> V_7 ) ;
V_6 -> V_10 = true ;
V_4 -> V_8 = 0 ;
return F_86 ( V_4 ) ;
}
static int F_92 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_40 * V_82 = & V_6 -> V_46 ;
V_6 -> V_7 += V_4 -> V_8 ;
F_34 ( V_82 , V_6 -> V_7 ) ;
V_6 -> V_10 = true ;
return F_86 ( V_4 ) ;
}
static int F_93 ( struct V_3 * V_4 , void * V_79 ,
T_9 * V_7 , void * V_18 )
{
struct V_113 * V_114 = F_28 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned int V_44 = F_27 ( V_114 ) ;
unsigned int V_115 ;
V_115 = F_94 ( V_114 ) ;
* V_7 = V_6 -> V_7 ;
memcpy ( V_79 , V_6 -> V_49 , V_44 ) ;
memset ( V_18 , 0 , V_115 ) ;
memcpy ( V_18 , V_6 -> V_18 , V_6 -> V_9 ) ;
return 0 ;
}
static int F_95 ( struct V_3 * V_4 , const void * V_79 ,
T_9 V_7 , const void * V_18 )
{
struct V_113 * V_114 = F_28 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned int V_44 = F_27 ( V_114 ) ;
unsigned int V_115 ;
unsigned int V_9 ;
int V_94 ;
V_94 = F_96 ( V_4 ) ;
if ( V_94 )
return V_94 ;
V_115 = F_94 ( V_114 ) ;
if ( V_7 >= V_115 )
F_37 ( & V_6 -> V_46 ,
V_57 ,
V_53 ) ;
V_6 -> V_7 = V_7 ;
memcpy ( V_6 -> V_49 , V_79 , V_44 ) ;
V_6 -> V_9 = 0 ;
V_9 = F_97 ( V_7 , V_115 ) ;
if ( ! V_9 )
return 0 ;
memcpy ( V_6 -> V_18 , V_18 , V_9 ) ;
V_6 -> V_9 = V_9 ;
return 0 ;
}
static int F_98 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_40 V_82 = { } ;
F_99 ( & V_82 , V_116 ) ;
F_60 ( V_4 , & V_82 , true ) ;
V_6 -> V_49 [ 0 ] = V_117 ;
V_6 -> V_49 [ 1 ] = V_118 ;
V_6 -> V_49 [ 2 ] = V_119 ;
V_6 -> V_49 [ 3 ] = V_120 ;
return 0 ;
}
static int F_100 ( struct V_3 * V_4 , void * V_121 )
{
struct V_122 * V_123 = V_121 ;
return F_93 ( V_4 , V_123 -> V_79 ,
& V_123 -> V_124 , V_123 -> V_125 ) ;
}
static int F_101 ( struct V_3 * V_4 , const void * V_126 )
{
const struct V_122 * V_127 = V_126 ;
return F_95 ( V_4 , V_127 -> V_79 , V_127 -> V_124 ,
V_127 -> V_125 ) ;
}
static int F_102 ( struct V_3 * V_4 )
{
int V_94 ;
V_94 = F_98 ( V_4 ) ;
if ( V_94 )
return V_94 ;
return F_92 ( V_4 ) ;
}
static int F_103 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_40 V_82 = { } ;
F_99 ( & V_82 , V_128 ) ;
F_60 ( V_4 , & V_82 , false ) ;
V_6 -> V_49 [ 0 ] = V_129 ;
V_6 -> V_49 [ 1 ] = V_130 ;
V_6 -> V_49 [ 2 ] = V_131 ;
V_6 -> V_49 [ 3 ] = V_132 ;
V_6 -> V_49 [ 4 ] = V_133 ;
return 0 ;
}
static int F_104 ( struct V_3 * V_4 , void * V_121 )
{
struct V_134 * V_123 = V_121 ;
return F_93 ( V_4 , V_123 -> V_49 , & V_123 -> V_135 ,
V_123 -> V_136 ) ;
}
static int F_105 ( struct V_3 * V_4 , const void * V_126 )
{
const struct V_134 * V_127 = V_126 ;
return F_95 ( V_4 , V_127 -> V_49 , V_127 -> V_135 ,
V_127 -> V_136 ) ;
}
static int F_106 ( struct V_3 * V_4 )
{
int V_94 ;
V_94 = F_103 ( V_4 ) ;
if ( V_94 )
return V_94 ;
return F_92 ( V_4 ) ;
}
static int F_107 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_40 V_82 = { } ;
F_99 ( & V_82 , V_137 ) ;
F_60 ( V_4 , & V_82 , false ) ;
V_6 -> V_49 [ 0 ] = V_138 ;
V_6 -> V_49 [ 1 ] = V_139 ;
V_6 -> V_49 [ 2 ] = V_140 ;
V_6 -> V_49 [ 3 ] = V_141 ;
V_6 -> V_49 [ 4 ] = V_142 ;
V_6 -> V_49 [ 5 ] = V_143 ;
V_6 -> V_49 [ 6 ] = V_144 ;
V_6 -> V_49 [ 7 ] = V_145 ;
return 0 ;
}
static int F_108 ( struct V_3 * V_4 )
{
int V_94 ;
V_94 = F_107 ( V_4 ) ;
if ( V_94 )
return V_94 ;
return F_92 ( V_4 ) ;
}
static int F_109 ( struct V_3 * V_4 , void * V_121 )
{
struct V_146 * V_123 = V_121 ;
return F_93 ( V_4 , V_123 -> V_49 , & V_123 -> V_135 ,
V_123 -> V_32 ) ;
}
static int F_110 ( struct V_3 * V_4 , const void * V_126 )
{
const struct V_146 * V_127 = V_126 ;
return F_95 ( V_4 , V_127 -> V_49 , V_127 -> V_135 ,
V_127 -> V_32 ) ;
}
static void F_111 ( struct V_72 * V_4 ,
int error )
{
struct V_147 * V_80 = V_4 -> V_77 ;
if ( error == - V_66 )
return;
V_80 -> error = error ;
F_112 ( & V_80 -> V_148 ) ;
}
static int F_113 ( struct V_3 * V_4 , T_2 * V_149 ,
void * V_49 , unsigned int V_115 )
{
struct V_147 V_80 ;
struct V_150 V_107 ;
int V_94 ;
F_114 ( V_4 , V_151 ,
F_111 , & V_80 ) ;
F_115 ( & V_107 , V_149 , V_115 ) ;
F_116 ( V_4 , & V_107 , V_149 , V_115 ) ;
F_117 ( & V_80 . V_148 ) ;
V_94 = F_96 ( V_4 ) ;
if ( V_94 )
return V_94 ;
V_94 = F_118 ( V_4 ) ;
if ( V_94 && V_94 != - V_66 )
return V_94 ;
F_119 ( & V_80 . V_148 ) ;
if ( V_80 . error )
return V_80 . error ;
V_94 = F_120 ( V_4 , V_49 ) ;
if ( V_94 )
return V_94 ;
return 0 ;
}
static int F_121 ( struct V_3 * V_4 ,
const T_2 * V_152 , unsigned int V_153 ,
T_2 * V_154 , T_2 * V_155 ,
unsigned int V_115 )
{
struct V_147 V_80 ;
struct V_150 V_107 ;
int V_94 ;
int V_45 ;
if ( V_153 <= V_115 ) {
memcpy ( V_154 , V_152 , V_153 ) ;
} else {
T_2 * V_156 = F_122 ( V_152 , V_153 , V_102 ) ;
if ( ! V_156 )
return - V_23 ;
F_114 ( V_4 , V_151 ,
F_111 ,
& V_80 ) ;
F_115 ( & V_107 , V_156 , V_153 ) ;
F_116 ( V_4 , & V_107 , V_154 , V_153 ) ;
F_117 ( & V_80 . V_148 ) ;
V_94 = F_123 ( V_4 ) ;
if ( V_94 == - V_66 ) {
F_119 ( & V_80 . V_148 ) ;
V_94 = V_80 . error ;
}
memset ( V_156 , 0 , V_153 ) ;
F_124 ( V_156 ) ;
if ( V_94 )
return V_94 ;
V_153 = F_27 ( F_28 ( V_4 ) ) ;
}
memset ( V_154 + V_153 , 0 , V_115 - V_153 ) ;
memcpy ( V_155 , V_154 , V_115 ) ;
for ( V_45 = 0 ; V_45 < V_115 ; V_45 ++ ) {
V_154 [ V_45 ] ^= 0x36 ;
V_155 [ V_45 ] ^= 0x5c ;
}
return 0 ;
}
static int F_125 ( const char * V_157 ,
const T_2 * V_152 , unsigned int V_153 ,
void * V_158 , void * V_159 )
{
struct V_3 * V_4 ;
struct V_113 * V_86 ;
unsigned int V_115 ;
T_2 * V_154 = NULL ;
T_2 * V_155 ;
int V_94 ;
V_86 = F_126 ( V_157 , V_160 ,
V_161 ) ;
if ( F_68 ( V_86 ) )
return F_81 ( V_86 ) ;
V_4 = F_127 ( V_86 , V_102 ) ;
if ( ! V_4 ) {
V_94 = - V_23 ;
goto V_162;
}
F_128 ( V_86 , ~ 0 ) ;
V_115 = F_129 ( F_130 ( V_86 ) ) ;
V_154 = F_131 ( 2 * V_115 , V_102 ) ;
if ( ! V_154 ) {
V_94 = - V_23 ;
goto V_163;
}
V_155 = V_154 + V_115 ;
V_94 = F_121 ( V_4 , V_152 , V_153 , V_154 , V_155 , V_115 ) ;
if ( V_94 )
goto V_164;
V_94 = F_113 ( V_4 , V_154 , V_158 , V_115 ) ;
if ( V_94 )
goto V_164;
V_94 = F_113 ( V_4 , V_155 , V_159 , V_115 ) ;
V_164:
F_124 ( V_154 ) ;
V_163:
F_132 ( V_4 ) ;
V_162:
F_133 ( V_86 ) ;
return V_94 ;
}
static int F_134 ( struct V_85 * V_86 )
{
struct V_165 * V_78 = F_62 ( V_86 ) ;
V_78 -> V_12 . V_88 = & V_89 ;
F_63 ( F_64 ( V_86 ) ,
sizeof( struct V_5 ) ) ;
return 0 ;
}
static int F_135 ( struct V_3 * V_4 )
{
struct V_165 * V_78 = F_62 ( V_4 -> V_12 . V_86 ) ;
struct V_40 V_82 = { } ;
F_99 ( & V_82 , V_166 ) ;
memcpy ( V_82 . V_78 . V_79 . V_167 , V_78 -> V_167 , sizeof( V_78 -> V_167 ) ) ;
F_60 ( V_4 , & V_82 , true ) ;
return 0 ;
}
static int F_136 ( struct V_113 * V_86 , const T_2 * V_152 ,
unsigned int V_153 )
{
struct V_165 * V_78 = F_62 ( F_130 ( V_86 ) ) ;
struct V_122 V_158 , V_159 ;
int V_94 , V_45 ;
V_94 = F_125 ( L_2 , V_152 , V_153 , & V_158 , & V_159 ) ;
if ( V_94 )
return V_94 ;
for ( V_45 = 0 ; V_45 < F_47 ( V_158 . V_79 ) ; V_45 ++ )
V_78 -> V_167 [ V_45 ] = F_137 ( V_158 . V_79 [ V_45 ] ) ;
for ( V_45 = 0 ; V_45 < F_47 ( V_159 . V_79 ) ; V_45 ++ )
V_78 -> V_167 [ V_45 + 8 ] = F_137 ( V_159 . V_79 [ V_45 ] ) ;
return 0 ;
}
static int F_138 ( struct V_3 * V_4 )
{
int V_94 ;
V_94 = F_135 ( V_4 ) ;
if ( V_94 )
return V_94 ;
return F_92 ( V_4 ) ;
}
static int F_139 ( struct V_3 * V_4 )
{
struct V_165 * V_78 = F_62 ( V_4 -> V_12 . V_86 ) ;
struct V_40 V_82 = { } ;
F_99 ( & V_82 , V_168 ) ;
memcpy ( V_82 . V_78 . V_79 . V_167 , V_78 -> V_167 , sizeof( V_78 -> V_167 ) ) ;
F_60 ( V_4 , & V_82 , false ) ;
return 0 ;
}
static int F_140 ( struct V_113 * V_86 , const T_2 * V_152 ,
unsigned int V_153 )
{
struct V_165 * V_78 = F_62 ( F_130 ( V_86 ) ) ;
struct V_134 V_158 , V_159 ;
int V_94 , V_45 ;
V_94 = F_125 ( L_3 , V_152 , V_153 , & V_158 , & V_159 ) ;
if ( V_94 )
return V_94 ;
for ( V_45 = 0 ; V_45 < F_47 ( V_158 . V_49 ) ; V_45 ++ )
V_78 -> V_167 [ V_45 ] = F_137 ( V_158 . V_49 [ V_45 ] ) ;
for ( V_45 = 0 ; V_45 < F_47 ( V_159 . V_49 ) ; V_45 ++ )
V_78 -> V_167 [ V_45 + 8 ] = F_137 ( V_159 . V_49 [ V_45 ] ) ;
return 0 ;
}
static int F_141 ( struct V_3 * V_4 )
{
int V_94 ;
V_94 = F_139 ( V_4 ) ;
if ( V_94 )
return V_94 ;
return F_92 ( V_4 ) ;
}
static int F_142 ( struct V_113 * V_86 , const T_2 * V_152 ,
unsigned int V_153 )
{
struct V_165 * V_78 = F_62 ( F_130 ( V_86 ) ) ;
struct V_146 V_158 , V_159 ;
int V_94 , V_45 ;
V_94 = F_125 ( L_4 , V_152 , V_153 , & V_158 , & V_159 ) ;
if ( V_94 )
return V_94 ;
for ( V_45 = 0 ; V_45 < F_47 ( V_158 . V_49 ) ; V_45 ++ )
V_78 -> V_167 [ V_45 ] = F_137 ( V_158 . V_49 [ V_45 ] ) ;
for ( V_45 = 0 ; V_45 < F_47 ( V_159 . V_49 ) ; V_45 ++ )
V_78 -> V_167 [ V_45 + 8 ] = F_137 ( V_159 . V_49 [ V_45 ] ) ;
return 0 ;
}
static int F_143 ( struct V_3 * V_4 )
{
struct V_165 * V_78 = F_62 ( V_4 -> V_12 . V_86 ) ;
struct V_40 V_82 = { } ;
F_99 ( & V_82 , V_169 ) ;
memcpy ( V_82 . V_78 . V_79 . V_167 , V_78 -> V_167 , sizeof( V_78 -> V_167 ) ) ;
F_60 ( V_4 , & V_82 , false ) ;
return 0 ;
}
static int F_144 ( struct V_3 * V_4 )
{
int V_94 ;
V_94 = F_143 ( V_4 ) ;
if ( V_94 )
return V_94 ;
return F_92 ( V_4 ) ;
}
