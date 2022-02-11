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
V_44 = F_27 ( F_28 ( V_4 ) ) ;
for ( V_45 = 0 ; V_45 < V_44 / 4 ; V_45 ++ )
F_29 ( V_6 -> V_48 [ V_45 ] , V_39 -> V_49 + F_30 ( V_45 ) ) ;
F_25 ( V_39 , & V_6 -> V_46 ) ;
F_26 ( V_39 -> V_47 , & V_6 -> V_46 , sizeof( V_6 -> V_46 ) ) ;
if ( V_6 -> V_9 )
F_26 ( V_39 -> V_47 + V_50 ,
V_6 -> V_18 , V_6 -> V_9 ) ;
V_7 = F_31 ( T_6 , V_4 -> V_8 + V_6 -> V_9 - V_36 -> V_51 ,
V_52 ) ;
if ( ! V_6 -> V_10 ) {
V_42 = V_7 & V_11 ;
V_7 &= ~ V_11 ;
}
if ( V_7 - V_6 -> V_9 )
V_36 -> V_51 += F_32 ( V_4 -> V_13 , V_6 -> V_28 ,
V_39 -> V_47 +
V_50 +
V_6 -> V_9 ,
V_7 - V_6 -> V_9 ,
V_36 -> V_51 ) ;
V_41 = & V_6 -> V_46 ;
V_43 = F_33 ( V_41 ) & V_53 ;
if ( V_6 -> V_10 && V_36 -> V_51 == V_4 -> V_8 &&
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
V_50 + V_7 ,
V_42 ) ;
} else {
V_7 += F_21 ( V_6 ,
V_39 -> V_47 + V_7 +
V_50 ) ;
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
F_29 ( V_61 , V_39 -> V_49 + V_62 ) ;
F_39 ( F_40 ( V_39 -> V_49 + V_63 ) &
V_64 ) ;
F_41 ( V_64 , V_39 -> V_49 + V_63 ) ;
}
static int F_42 ( struct V_3 * V_4 , T_5 V_65 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_35 * V_36 = & V_6 -> V_4 . V_37 ;
if ( V_36 -> V_51 < ( V_4 -> V_8 - V_6 -> V_9 ) )
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
V_36 -> V_51 = 0 ;
}
static void F_46 ( struct V_69 * V_4 )
{
struct V_3 * V_70 = F_47 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_70 ) ;
if ( F_18 ( & V_6 -> V_12 ) == V_29 )
F_48 ( & V_6 -> V_12 ) ;
else
F_24 ( V_70 ) ;
}
static int F_49 ( struct V_69 * V_4 , T_5 V_65 )
{
struct V_3 * V_70 = F_47 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_70 ) ;
if ( F_18 ( & V_6 -> V_12 ) == V_29 )
return F_50 ( & V_6 -> V_12 , V_65 ) ;
return F_42 ( V_70 , V_65 ) ;
}
static void F_51 ( struct V_69 * V_4 )
{
struct V_3 * V_70 = F_47 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_70 ) ;
struct V_38 * V_39 = V_6 -> V_12 . V_39 ;
unsigned int V_44 ;
int V_45 ;
V_44 = F_27 ( F_28 ( V_70 ) ) ;
for ( V_45 = 0 ; V_45 < V_44 / 4 ; V_45 ++ )
V_6 -> V_48 [ V_45 ] = F_52 ( V_39 -> V_49 + F_30 ( V_45 ) ) ;
if ( V_6 -> V_10 ) {
if ( V_6 -> V_33 ) {
T_7 * V_71 = ( void * ) V_70 -> V_71 ;
for ( V_45 = 0 ; V_45 < V_44 / 4 ; V_45 ++ )
V_71 [ V_45 ] = F_53 ( V_6 -> V_48 [ V_45 ] ) ;
} else {
T_8 * V_71 = ( void * ) V_70 -> V_71 ;
for ( V_45 = 0 ; V_45 < V_44 / 4 ; V_45 ++ )
V_71 [ V_45 ] = F_54 ( V_6 -> V_48 [ V_45 ] ) ;
}
}
F_55 ( V_70 -> V_8 , & V_39 -> V_72 ) ;
}
static void F_56 ( struct V_69 * V_4 ,
struct V_38 * V_39 )
{
struct V_3 * V_70 = F_47 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_70 ) ;
V_6 -> V_12 . V_39 = V_39 ;
if ( F_18 ( & V_6 -> V_12 ) == V_29 )
F_43 ( V_70 ) ;
else
F_45 ( V_70 ) ;
}
static void F_57 ( struct V_69 * V_4 )
{
struct V_3 * V_70 = F_47 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_70 ) ;
if ( V_6 -> V_10 )
F_19 ( V_70 ) ;
F_17 ( V_70 ) ;
if ( V_6 -> V_9 )
F_32 ( V_70 -> V_13 , V_6 -> V_28 ,
V_6 -> V_18 ,
V_6 -> V_9 ,
V_70 -> V_8 - V_6 -> V_9 ) ;
}
static int F_58 ( struct V_3 * V_4 ,
struct V_40 * V_73 , bool V_33 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_37 ( V_73 ,
V_74 |
V_55 ,
V_75 |
V_53 ) ;
F_34 ( V_73 , 0 ) ;
F_36 ( V_73 , 0 ) ;
V_6 -> V_46 = * V_73 ;
V_6 -> V_7 = 0 ;
V_6 -> V_33 = V_33 ;
return 0 ;
}
static inline int F_59 ( struct V_76 * V_77 )
{
struct V_78 * V_79 = F_60 ( V_77 ) ;
V_79 -> V_12 . V_80 = & V_81 ;
F_61 ( F_62 ( V_77 ) ,
sizeof( struct V_5 ) ) ;
return 0 ;
}
static int F_63 ( struct V_3 * V_4 , bool * V_82 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_6 -> V_9 + V_4 -> V_8 < 64 && ! V_6 -> V_10 ) {
* V_82 = true ;
if ( ! V_4 -> V_8 )
return 0 ;
F_32 ( V_4 -> V_13 , V_6 -> V_28 ,
V_6 -> V_18 + V_6 -> V_9 ,
V_4 -> V_8 , 0 ) ;
V_6 -> V_9 += V_4 -> V_8 ;
}
return 0 ;
}
static struct V_40 *
F_64 ( struct V_83 * V_84 ,
struct V_40 * V_73 , unsigned int V_85 ,
T_1 V_17 )
{
struct V_40 * V_41 ;
int V_86 ;
V_41 = F_65 ( V_84 , V_73 , false , V_17 ) ;
if ( F_66 ( V_41 ) )
return V_41 ;
F_36 ( V_41 , V_85 ) ;
V_86 = F_67 ( V_84 , V_17 ) ;
if ( V_86 )
return F_68 ( V_86 ) ;
if ( F_69 ( V_73 ) )
F_37 ( V_73 ,
V_57 ,
V_53 ) ;
return V_41 ;
}
static int
F_70 ( struct V_83 * V_84 ,
struct V_1 * V_87 ,
struct V_5 * V_6 ,
T_1 V_17 )
{
struct V_16 * V_88 = & V_6 -> V_4 . V_20 ;
int V_86 ;
if ( ! V_6 -> V_9 )
return 0 ;
V_86 = F_7 ( V_88 , V_17 ) ;
if ( V_86 )
return V_86 ;
memcpy ( V_88 -> V_18 , V_6 -> V_18 , V_6 -> V_9 ) ;
return F_71 ( V_84 ,
V_50 ,
V_88 -> V_22 ,
V_6 -> V_9 ,
V_89 ,
V_17 ) ;
}
static struct V_40 *
F_72 ( struct V_83 * V_84 ,
struct V_1 * V_87 ,
struct V_5 * V_6 ,
unsigned int V_85 , T_1 V_17 )
{
struct V_16 * V_88 = & V_6 -> V_4 . V_20 ;
unsigned int V_7 , V_59 , V_90 = 0 ;
struct V_40 * V_41 ;
int V_86 ;
if ( V_6 -> V_7 <= V_54 && V_85 ) {
V_41 = F_64 ( V_84 , & V_6 -> V_46 , V_85 ,
V_17 ) ;
if ( F_66 ( V_41 ) )
return V_41 ;
F_34 ( V_41 , V_6 -> V_7 ) ;
F_37 ( V_41 , F_69 ( V_41 ) ?
V_56 :
V_58 ,
V_53 ) ;
return V_41 ;
}
V_86 = F_11 ( V_88 , V_17 ) ;
if ( V_86 )
return F_68 ( V_86 ) ;
V_59 = F_21 ( V_6 , V_88 -> V_24 ) ;
V_7 = F_73 ( V_52 - V_85 , V_59 ) ;
if ( V_7 ) {
V_86 = F_71 ( V_84 ,
V_50 +
V_85 ,
V_88 -> V_26 ,
V_7 , V_89 ,
V_17 ) ;
if ( V_86 )
return F_68 ( V_86 ) ;
V_41 = F_64 ( V_84 , & V_6 -> V_46 , V_85 + V_7 ,
V_17 ) ;
if ( F_66 ( V_41 ) )
return V_41 ;
if ( V_7 == V_59 )
return V_41 ;
V_90 += V_7 ;
}
V_86 = F_71 ( V_84 ,
V_50 ,
V_88 -> V_26 +
V_90 ,
V_59 - V_90 ,
V_89 ,
V_17 ) ;
if ( V_86 )
return F_68 ( V_86 ) ;
return F_64 ( V_84 , & V_6 -> V_46 , V_59 - V_90 ,
V_17 ) ;
}
static int F_74 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 V_17 = ( V_4 -> V_12 . V_17 & V_91 ) ?
V_92 : V_93 ;
struct V_67 * V_68 = & V_6 -> V_12 ;
struct V_1 V_2 ;
struct V_40 * V_41 = NULL ;
unsigned int V_85 ;
int V_86 ;
V_68 -> V_84 . V_94 = NULL ;
V_68 -> V_84 . V_95 = NULL ;
if ( V_6 -> V_28 ) {
V_86 = F_75 ( V_19 -> V_27 , V_4 -> V_13 , V_6 -> V_28 ,
V_14 ) ;
if ( ! V_86 ) {
V_86 = - V_23 ;
goto V_96;
}
}
F_76 ( & V_68 -> V_84 ) ;
F_1 ( & V_2 , V_4 ) ;
V_86 = F_70 ( & V_68 -> V_84 , & V_2 , V_6 , V_17 ) ;
if ( V_86 )
goto V_97;
if ( V_2 . V_13 . V_98 ) {
while ( true ) {
V_86 = F_77 ( & V_68 -> V_84 ,
& V_2 . V_12 ,
& V_2 . V_13 , V_17 ) ;
if ( V_86 )
goto V_97;
V_85 = V_2 . V_12 . V_99 ;
if ( ! F_5 ( & V_2 ) )
break;
V_41 = F_64 ( & V_68 -> V_84 , & V_6 -> V_46 ,
V_85 , V_17 ) ;
if ( F_66 ( V_41 ) ) {
V_86 = F_78 ( V_41 ) ;
goto V_97;
}
}
} else {
V_85 = V_2 . V_12 . V_99 ;
}
if ( V_6 -> V_10 )
V_41 = F_72 ( & V_68 -> V_84 , & V_2 , V_6 ,
V_85 , V_17 ) ;
else if ( V_85 )
V_41 = F_64 ( & V_68 -> V_84 , & V_6 -> V_46 ,
V_85 , V_17 ) ;
if ( F_66 ( V_41 ) ) {
V_86 = F_78 ( V_41 ) ;
goto V_97;
}
if ( V_41 ) {
V_86 = F_79 ( & V_68 -> V_84 , V_17 ) ;
if ( V_86 )
goto V_97;
}
if ( ! V_6 -> V_10 )
V_6 -> V_9 = V_4 -> V_8 + V_6 -> V_9 -
V_2 . V_12 . V_7 ;
else
V_6 -> V_9 = 0 ;
V_68 -> V_84 . V_95 -> V_17 |= ( V_100 |
V_101 ) ;
return 0 ;
V_97:
F_16 ( V_68 ) ;
F_15 ( V_19 -> V_27 , V_4 -> V_13 , V_6 -> V_28 , V_14 ) ;
V_96:
F_19 ( V_4 ) ;
return V_86 ;
}
static int F_80 ( struct V_3 * V_4 , bool * V_82 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_86 ;
V_6 -> V_28 = F_81 ( V_4 -> V_13 , V_4 -> V_8 ) ;
if ( V_6 -> V_28 < 0 ) {
F_82 ( V_19 -> V_27 , L_1 ) ;
return V_6 -> V_28 ;
}
V_86 = F_63 ( V_4 , V_82 ) ;
if ( V_86 )
return V_86 ;
if ( * V_82 )
return 0 ;
if ( V_19 -> V_102 -> V_103 )
V_86 = F_74 ( V_4 ) ;
return V_86 ;
}
static int F_83 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_38 * V_39 ;
bool V_82 = false ;
int V_86 ;
V_86 = F_80 ( V_4 , & V_82 ) ;
if ( V_86 )
return V_86 ;
if ( V_82 )
return 0 ;
V_39 = F_84 ( V_4 -> V_8 ) ;
F_56 ( & V_4 -> V_12 , V_39 ) ;
V_86 = F_85 ( & V_4 -> V_12 , & V_6 -> V_12 ) ;
if ( F_86 ( & V_4 -> V_12 , V_86 ) )
F_17 ( V_4 ) ;
return V_86 ;
}
static int F_87 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_6 -> V_7 += V_4 -> V_8 ;
return F_83 ( V_4 ) ;
}
static int F_88 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_40 * V_73 = & V_6 -> V_46 ;
F_34 ( V_73 , V_6 -> V_7 ) ;
V_6 -> V_10 = true ;
V_4 -> V_8 = 0 ;
return F_83 ( V_4 ) ;
}
static int F_89 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_40 * V_73 = & V_6 -> V_46 ;
V_6 -> V_7 += V_4 -> V_8 ;
F_34 ( V_73 , V_6 -> V_7 ) ;
V_6 -> V_10 = true ;
return F_83 ( V_4 ) ;
}
static int F_90 ( struct V_3 * V_4 , void * V_104 ,
T_9 * V_7 , void * V_18 )
{
struct V_105 * V_106 = F_28 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned int V_44 = F_27 ( V_106 ) ;
unsigned int V_107 ;
V_107 = F_91 ( V_106 ) ;
* V_7 = V_6 -> V_7 ;
memcpy ( V_104 , V_6 -> V_48 , V_44 ) ;
memset ( V_18 , 0 , V_107 ) ;
memcpy ( V_18 , V_6 -> V_18 , V_6 -> V_9 ) ;
return 0 ;
}
static int F_92 ( struct V_3 * V_4 , const void * V_104 ,
T_9 V_7 , const void * V_18 )
{
struct V_105 * V_106 = F_28 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned int V_44 = F_27 ( V_106 ) ;
unsigned int V_107 ;
unsigned int V_9 ;
int V_86 ;
V_86 = F_93 ( V_4 ) ;
if ( V_86 )
return V_86 ;
V_107 = F_91 ( V_106 ) ;
if ( V_7 >= V_107 )
F_37 ( & V_6 -> V_46 ,
V_57 ,
V_53 ) ;
V_6 -> V_7 = V_7 ;
memcpy ( V_6 -> V_48 , V_104 , V_44 ) ;
V_6 -> V_9 = 0 ;
V_9 = F_94 ( V_7 , V_107 ) ;
if ( ! V_9 )
return 0 ;
memcpy ( V_6 -> V_18 , V_18 , V_9 ) ;
V_6 -> V_9 = V_9 ;
return 0 ;
}
static int F_95 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_40 V_73 = { } ;
F_96 ( & V_73 , V_108 ) ;
V_6 -> V_48 [ 0 ] = V_109 ;
V_6 -> V_48 [ 1 ] = V_110 ;
V_6 -> V_48 [ 2 ] = V_111 ;
V_6 -> V_48 [ 3 ] = V_112 ;
F_58 ( V_4 , & V_73 , true ) ;
return 0 ;
}
static int F_97 ( struct V_3 * V_4 , void * V_113 )
{
struct V_114 * V_115 = V_113 ;
return F_90 ( V_4 , V_115 -> V_104 ,
& V_115 -> V_116 , V_115 -> V_117 ) ;
}
static int F_98 ( struct V_3 * V_4 , const void * V_118 )
{
const struct V_114 * V_119 = V_118 ;
return F_92 ( V_4 , V_119 -> V_104 , V_119 -> V_116 ,
V_119 -> V_117 ) ;
}
static int F_99 ( struct V_3 * V_4 )
{
int V_86 ;
V_86 = F_95 ( V_4 ) ;
if ( V_86 )
return V_86 ;
return F_89 ( V_4 ) ;
}
static int F_100 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_40 V_73 = { } ;
F_96 ( & V_73 , V_120 ) ;
V_6 -> V_48 [ 0 ] = V_121 ;
V_6 -> V_48 [ 1 ] = V_122 ;
V_6 -> V_48 [ 2 ] = V_123 ;
V_6 -> V_48 [ 3 ] = V_124 ;
V_6 -> V_48 [ 4 ] = V_125 ;
F_58 ( V_4 , & V_73 , false ) ;
return 0 ;
}
static int F_101 ( struct V_3 * V_4 , void * V_113 )
{
struct V_126 * V_115 = V_113 ;
return F_90 ( V_4 , V_115 -> V_48 , & V_115 -> V_127 ,
V_115 -> V_128 ) ;
}
static int F_102 ( struct V_3 * V_4 , const void * V_118 )
{
const struct V_126 * V_119 = V_118 ;
return F_92 ( V_4 , V_119 -> V_48 , V_119 -> V_127 ,
V_119 -> V_128 ) ;
}
static int F_103 ( struct V_3 * V_4 )
{
int V_86 ;
V_86 = F_100 ( V_4 ) ;
if ( V_86 )
return V_86 ;
return F_89 ( V_4 ) ;
}
static int F_104 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_40 V_73 = { } ;
F_96 ( & V_73 , V_129 ) ;
V_6 -> V_48 [ 0 ] = V_130 ;
V_6 -> V_48 [ 1 ] = V_131 ;
V_6 -> V_48 [ 2 ] = V_132 ;
V_6 -> V_48 [ 3 ] = V_133 ;
V_6 -> V_48 [ 4 ] = V_134 ;
V_6 -> V_48 [ 5 ] = V_135 ;
V_6 -> V_48 [ 6 ] = V_136 ;
V_6 -> V_48 [ 7 ] = V_137 ;
F_58 ( V_4 , & V_73 , false ) ;
return 0 ;
}
static int F_105 ( struct V_3 * V_4 )
{
int V_86 ;
V_86 = F_104 ( V_4 ) ;
if ( V_86 )
return V_86 ;
return F_89 ( V_4 ) ;
}
static int F_106 ( struct V_3 * V_4 , void * V_113 )
{
struct V_138 * V_115 = V_113 ;
return F_90 ( V_4 , V_115 -> V_48 , & V_115 -> V_127 ,
V_115 -> V_32 ) ;
}
static int F_107 ( struct V_3 * V_4 , const void * V_118 )
{
const struct V_138 * V_119 = V_118 ;
return F_92 ( V_4 , V_119 -> V_48 , V_119 -> V_127 ,
V_119 -> V_32 ) ;
}
static void F_108 ( struct V_69 * V_4 ,
int error )
{
struct V_139 * V_71 = V_4 -> V_140 ;
if ( error == - V_66 )
return;
V_71 -> error = error ;
F_109 ( & V_71 -> V_141 ) ;
}
static int F_110 ( struct V_3 * V_4 , T_2 * V_142 ,
void * V_48 , unsigned int V_107 )
{
struct V_139 V_71 ;
struct V_143 V_98 ;
int V_86 ;
F_111 ( V_4 , V_144 ,
F_108 , & V_71 ) ;
F_112 ( & V_98 , V_142 , V_107 ) ;
F_113 ( V_4 , & V_98 , V_142 , V_107 ) ;
F_114 ( & V_71 . V_141 ) ;
V_86 = F_93 ( V_4 ) ;
if ( V_86 )
return V_86 ;
V_86 = F_115 ( V_4 ) ;
if ( V_86 && V_86 != - V_66 )
return V_86 ;
F_116 ( & V_71 . V_141 ) ;
if ( V_71 . error )
return V_71 . error ;
V_86 = F_117 ( V_4 , V_48 ) ;
if ( V_86 )
return V_86 ;
return 0 ;
}
static int F_118 ( struct V_3 * V_4 ,
const T_2 * V_145 , unsigned int V_146 ,
T_2 * V_147 , T_2 * V_148 ,
unsigned int V_107 )
{
struct V_139 V_71 ;
struct V_143 V_98 ;
int V_86 ;
int V_45 ;
if ( V_146 <= V_107 ) {
memcpy ( V_147 , V_145 , V_146 ) ;
} else {
T_2 * V_149 = F_119 ( V_145 , V_146 , V_92 ) ;
if ( ! V_149 )
return - V_23 ;
F_111 ( V_4 , V_144 ,
F_108 ,
& V_71 ) ;
F_112 ( & V_98 , V_149 , V_146 ) ;
F_113 ( V_4 , & V_98 , V_147 , V_146 ) ;
F_114 ( & V_71 . V_141 ) ;
V_86 = F_120 ( V_4 ) ;
if ( V_86 == - V_66 ) {
F_116 ( & V_71 . V_141 ) ;
V_86 = V_71 . error ;
}
memset ( V_149 , 0 , V_146 ) ;
F_121 ( V_149 ) ;
if ( V_86 )
return V_86 ;
V_146 = F_27 ( F_28 ( V_4 ) ) ;
}
memset ( V_147 + V_146 , 0 , V_107 - V_146 ) ;
memcpy ( V_148 , V_147 , V_107 ) ;
for ( V_45 = 0 ; V_45 < V_107 ; V_45 ++ ) {
V_147 [ V_45 ] ^= 0x36 ;
V_148 [ V_45 ] ^= 0x5c ;
}
return 0 ;
}
static int F_122 ( const char * V_150 ,
const T_2 * V_145 , unsigned int V_146 ,
void * V_151 , void * V_152 )
{
struct V_3 * V_4 ;
struct V_105 * V_77 ;
unsigned int V_107 ;
T_2 * V_147 = NULL ;
T_2 * V_148 ;
int V_86 ;
V_77 = F_123 ( V_150 , V_153 ,
V_154 ) ;
if ( F_66 ( V_77 ) )
return F_78 ( V_77 ) ;
V_4 = F_124 ( V_77 , V_92 ) ;
if ( ! V_4 ) {
V_86 = - V_23 ;
goto V_155;
}
F_125 ( V_77 , ~ 0 ) ;
V_107 = F_126 ( F_127 ( V_77 ) ) ;
V_147 = F_128 ( 2 * V_107 , V_92 ) ;
if ( ! V_147 ) {
V_86 = - V_23 ;
goto V_156;
}
V_148 = V_147 + V_107 ;
V_86 = F_118 ( V_4 , V_145 , V_146 , V_147 , V_148 , V_107 ) ;
if ( V_86 )
goto V_157;
V_86 = F_110 ( V_4 , V_147 , V_151 , V_107 ) ;
if ( V_86 )
goto V_157;
V_86 = F_110 ( V_4 , V_148 , V_152 , V_107 ) ;
V_157:
F_121 ( V_147 ) ;
V_156:
F_129 ( V_4 ) ;
V_155:
F_130 ( V_77 ) ;
return V_86 ;
}
static int F_131 ( struct V_76 * V_77 )
{
struct V_158 * V_79 = F_60 ( V_77 ) ;
V_79 -> V_12 . V_80 = & V_81 ;
F_61 ( F_62 ( V_77 ) ,
sizeof( struct V_5 ) ) ;
return 0 ;
}
static int F_132 ( struct V_3 * V_4 )
{
struct V_158 * V_79 = F_60 ( V_4 -> V_12 . V_77 ) ;
struct V_40 V_73 = { } ;
F_96 ( & V_73 , V_159 ) ;
memcpy ( V_73 . V_79 . V_104 . V_160 , V_79 -> V_160 , sizeof( V_79 -> V_160 ) ) ;
F_58 ( V_4 , & V_73 , true ) ;
return 0 ;
}
static int F_133 ( struct V_105 * V_77 , const T_2 * V_145 ,
unsigned int V_146 )
{
struct V_158 * V_79 = F_60 ( F_127 ( V_77 ) ) ;
struct V_114 V_151 , V_152 ;
int V_86 , V_45 ;
V_86 = F_122 ( L_2 , V_145 , V_146 , & V_151 , & V_152 ) ;
if ( V_86 )
return V_86 ;
for ( V_45 = 0 ; V_45 < F_134 ( V_151 . V_104 ) ; V_45 ++ )
V_79 -> V_160 [ V_45 ] = F_135 ( V_151 . V_104 [ V_45 ] ) ;
for ( V_45 = 0 ; V_45 < F_134 ( V_152 . V_104 ) ; V_45 ++ )
V_79 -> V_160 [ V_45 + 8 ] = F_135 ( V_152 . V_104 [ V_45 ] ) ;
return 0 ;
}
static int F_136 ( struct V_3 * V_4 )
{
int V_86 ;
V_86 = F_132 ( V_4 ) ;
if ( V_86 )
return V_86 ;
return F_89 ( V_4 ) ;
}
static int F_137 ( struct V_3 * V_4 )
{
struct V_158 * V_79 = F_60 ( V_4 -> V_12 . V_77 ) ;
struct V_40 V_73 = { } ;
F_96 ( & V_73 , V_161 ) ;
memcpy ( V_73 . V_79 . V_104 . V_160 , V_79 -> V_160 , sizeof( V_79 -> V_160 ) ) ;
F_58 ( V_4 , & V_73 , false ) ;
return 0 ;
}
static int F_138 ( struct V_105 * V_77 , const T_2 * V_145 ,
unsigned int V_146 )
{
struct V_158 * V_79 = F_60 ( F_127 ( V_77 ) ) ;
struct V_126 V_151 , V_152 ;
int V_86 , V_45 ;
V_86 = F_122 ( L_3 , V_145 , V_146 , & V_151 , & V_152 ) ;
if ( V_86 )
return V_86 ;
for ( V_45 = 0 ; V_45 < F_134 ( V_151 . V_48 ) ; V_45 ++ )
V_79 -> V_160 [ V_45 ] = F_135 ( V_151 . V_48 [ V_45 ] ) ;
for ( V_45 = 0 ; V_45 < F_134 ( V_152 . V_48 ) ; V_45 ++ )
V_79 -> V_160 [ V_45 + 8 ] = F_135 ( V_152 . V_48 [ V_45 ] ) ;
return 0 ;
}
static int F_139 ( struct V_3 * V_4 )
{
int V_86 ;
V_86 = F_137 ( V_4 ) ;
if ( V_86 )
return V_86 ;
return F_89 ( V_4 ) ;
}
static int F_140 ( struct V_105 * V_77 , const T_2 * V_145 ,
unsigned int V_146 )
{
struct V_158 * V_79 = F_60 ( F_127 ( V_77 ) ) ;
struct V_138 V_151 , V_152 ;
int V_86 , V_45 ;
V_86 = F_122 ( L_4 , V_145 , V_146 , & V_151 , & V_152 ) ;
if ( V_86 )
return V_86 ;
for ( V_45 = 0 ; V_45 < F_134 ( V_151 . V_48 ) ; V_45 ++ )
V_79 -> V_160 [ V_45 ] = F_135 ( V_151 . V_48 [ V_45 ] ) ;
for ( V_45 = 0 ; V_45 < F_134 ( V_152 . V_48 ) ; V_45 ++ )
V_79 -> V_160 [ V_45 + 8 ] = F_135 ( V_152 . V_48 [ V_45 ] ) ;
return 0 ;
}
static int F_141 ( struct V_3 * V_4 )
{
struct V_158 * V_79 = F_60 ( V_4 -> V_12 . V_77 ) ;
struct V_40 V_73 = { } ;
F_96 ( & V_73 , V_162 ) ;
memcpy ( V_73 . V_79 . V_104 . V_160 , V_79 -> V_160 , sizeof( V_79 -> V_160 ) ) ;
F_58 ( V_4 , & V_73 , false ) ;
return 0 ;
}
static int F_142 ( struct V_3 * V_4 )
{
int V_86 ;
V_86 = F_141 ( V_4 ) ;
if ( V_86 )
return V_86 ;
return F_89 ( V_4 ) ;
}
