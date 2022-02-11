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
F_16 ( & V_6 -> V_4 . V_20 . V_12 ) ;
}
static inline void F_17 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_6 -> V_4 . V_12 . type == V_29 )
F_14 ( V_4 ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_6 -> V_4 . V_12 . type == V_29 )
F_13 ( V_4 ) ;
}
static int F_19 ( struct V_5 * V_6 )
{
unsigned int V_30 , V_31 ;
V_30 = V_6 -> V_7 & V_11 ;
V_31 = ( V_30 < 56 ) ? ( 56 - V_30 ) : ( 64 + 56 - V_30 ) ;
return V_31 ;
}
static int F_20 ( struct V_5 * V_6 , T_2 * V_32 )
{
unsigned int V_30 , V_31 ;
V_32 [ 0 ] = 0x80 ;
V_30 = V_6 -> V_7 & V_11 ;
V_31 = F_19 ( V_6 ) ;
memset ( V_32 + 1 , 0 , V_31 - 1 ) ;
if ( V_6 -> V_33 ) {
T_3 V_34 = F_21 ( V_6 -> V_7 << 3 ) ;
memcpy ( V_32 + V_31 , & V_34 , sizeof( V_34 ) ) ;
} else {
T_4 V_34 = F_22 ( V_6 -> V_7 << 3 ) ;
memcpy ( V_32 + V_31 , & V_34 , sizeof( V_34 ) ) ;
}
return V_31 + 8 ;
}
static void F_23 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_35 * V_36 = & V_6 -> V_4 . V_37 ;
struct V_38 * V_39 = V_36 -> V_12 . V_39 ;
struct V_40 * V_41 ;
unsigned int V_42 = 0 ;
T_5 V_43 ;
T_6 V_7 ;
if ( V_6 -> V_9 )
F_24 ( V_39 -> V_44 + V_45 ,
V_6 -> V_18 , V_6 -> V_9 ) ;
V_7 = F_25 ( T_6 , V_4 -> V_8 + V_6 -> V_9 - V_36 -> V_46 ,
V_47 ) ;
if ( ! V_6 -> V_10 ) {
V_42 = V_7 & V_11 ;
V_7 &= ~ V_11 ;
}
if ( V_7 - V_6 -> V_9 )
V_36 -> V_46 += F_26 ( V_4 -> V_13 , V_6 -> V_28 ,
V_39 -> V_44 +
V_45 +
V_6 -> V_9 ,
V_7 - V_6 -> V_9 ,
V_36 -> V_46 ) ;
V_41 = & V_6 -> V_48 ;
V_43 = F_27 ( V_41 ) & V_49 ;
if ( V_6 -> V_10 && V_36 -> V_46 == V_4 -> V_8 &&
V_6 -> V_7 <= V_50 ) {
if ( V_43 == V_51 )
V_43 = V_52 ;
else if ( V_43 == V_53 )
V_43 = V_54 ;
}
if ( V_43 == V_52 ||
V_43 == V_54 ) {
if ( V_7 &&
V_6 -> V_7 <= V_50 ) {
F_28 ( V_41 , V_6 -> V_7 ) ;
} else {
int V_55 = F_19 ( V_6 ) + 8 ;
if ( V_7 + V_55 > V_47 ) {
V_7 &= V_11 ;
V_42 = 64 - V_55 ;
F_29 ( V_6 -> V_18 ,
V_39 -> V_44 +
V_45 + V_7 ,
V_42 ) ;
} else {
V_7 += F_20 ( V_6 ,
V_39 -> V_44 + V_7 +
V_45 ) ;
}
if ( V_43 == V_54 )
V_43 = V_53 ;
else
V_43 = V_51 ;
}
}
F_30 ( V_41 , V_7 ) ;
F_31 ( V_41 , V_43 , V_49 ) ;
F_24 ( V_39 -> V_44 , V_41 , sizeof( * V_41 ) ) ;
if ( V_43 == V_51 )
F_31 ( V_41 , V_53 ,
V_49 ) ;
V_6 -> V_9 = V_42 ;
F_32 ( V_39 , V_56 ) ;
F_33 ( V_57 , V_39 -> V_58 + V_59 ) ;
F_34 ( V_60 , V_39 -> V_58 + V_61 ) ;
}
static int F_35 ( struct V_3 * V_4 , T_5 V_62 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_35 * V_36 = & V_6 -> V_4 . V_37 ;
if ( V_36 -> V_46 < ( V_4 -> V_8 - V_6 -> V_9 ) )
return - V_63 ;
return 0 ;
}
static inline void F_36 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_64 * V_65 = & V_6 -> V_4 . V_20 . V_12 ;
F_37 ( V_65 , V_65 -> V_12 . V_39 ) ;
}
static void F_38 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_35 * V_36 = & V_6 -> V_4 . V_37 ;
struct V_38 * V_39 = V_36 -> V_12 . V_39 ;
V_36 -> V_46 = 0 ;
F_39 ( V_39 , & V_6 -> V_48 ) ;
F_24 ( V_39 -> V_44 , & V_6 -> V_48 , sizeof( V_6 -> V_48 ) ) ;
}
static void F_40 ( struct V_66 * V_4 )
{
struct V_3 * V_67 = F_41 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_67 ) ;
if ( V_6 -> V_4 . V_12 . type == V_29 )
F_42 ( & V_6 -> V_4 . V_20 . V_12 ) ;
else
F_23 ( V_67 ) ;
}
static int F_43 ( struct V_66 * V_4 , T_5 V_62 )
{
struct V_3 * V_67 = F_41 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_67 ) ;
struct V_38 * V_39 = V_6 -> V_4 . V_12 . V_39 ;
unsigned int V_68 ;
int V_69 , V_70 ;
if ( V_6 -> V_4 . V_12 . type == V_29 )
V_69 = F_44 ( & V_6 -> V_4 . V_20 . V_12 , V_62 ) ;
else
V_69 = F_35 ( V_67 , V_62 ) ;
if ( V_69 == - V_63 )
return V_69 ;
V_68 = F_45 ( F_46 ( V_67 ) ) ;
for ( V_70 = 0 ; V_70 < V_68 / 4 ; V_70 ++ )
V_6 -> V_71 [ V_70 ] = F_47 ( V_39 -> V_58 + F_48 ( V_70 ) ) ;
if ( V_6 -> V_9 )
F_26 ( V_67 -> V_13 , V_6 -> V_28 ,
V_6 -> V_18 ,
V_6 -> V_9 ,
V_67 -> V_8 - V_6 -> V_9 ) ;
if ( V_6 -> V_10 ) {
if ( V_6 -> V_33 ) {
T_7 * V_72 = ( void * ) V_67 -> V_72 ;
for ( V_70 = 0 ; V_70 < V_68 / 4 ; V_70 ++ )
V_72 [ V_70 ] = F_49 ( V_6 -> V_71 [ V_70 ] ) ;
} else {
T_8 * V_72 = ( void * ) V_67 -> V_72 ;
for ( V_70 = 0 ; V_70 < V_68 / 4 ; V_70 ++ )
V_72 [ V_70 ] = F_50 ( V_6 -> V_71 [ V_70 ] ) ;
}
}
return V_69 ;
}
static void F_51 ( struct V_66 * V_4 ,
struct V_38 * V_39 )
{
struct V_3 * V_67 = F_41 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_67 ) ;
unsigned int V_68 ;
int V_70 ;
V_6 -> V_4 . V_12 . V_39 = V_39 ;
if ( V_6 -> V_4 . V_12 . type == V_29 )
F_36 ( V_67 ) ;
else
F_38 ( V_67 ) ;
V_68 = F_45 ( F_46 ( V_67 ) ) ;
for ( V_70 = 0 ; V_70 < V_68 / 4 ; V_70 ++ )
F_33 ( V_6 -> V_71 [ V_70 ] , V_39 -> V_58 + F_48 ( V_70 ) ) ;
}
static void F_52 ( struct V_66 * V_4 )
{
struct V_3 * V_67 = F_41 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_67 ) ;
if ( V_6 -> V_10 )
F_18 ( V_67 ) ;
F_17 ( V_67 ) ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_40 * V_73 , bool V_33 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_31 ( V_73 ,
V_74 |
V_51 ,
V_75 |
V_49 ) ;
F_28 ( V_73 , 0 ) ;
F_30 ( V_73 , 0 ) ;
V_6 -> V_48 = * V_73 ;
V_6 -> V_7 = 0 ;
V_6 -> V_33 = V_33 ;
return 0 ;
}
static inline int F_54 ( struct V_76 * V_77 )
{
struct V_78 * V_79 = F_55 ( V_77 ) ;
V_79 -> V_12 . V_80 = & V_81 ;
F_56 ( F_57 ( V_77 ) ,
sizeof( struct V_5 ) ) ;
return 0 ;
}
static int F_58 ( struct V_3 * V_4 , bool * V_82 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_6 -> V_9 + V_4 -> V_8 < 64 && ! V_6 -> V_10 ) {
* V_82 = true ;
if ( ! V_4 -> V_8 )
return 0 ;
F_26 ( V_4 -> V_13 , V_6 -> V_28 ,
V_6 -> V_18 + V_6 -> V_9 ,
V_4 -> V_8 , 0 ) ;
V_6 -> V_9 += V_4 -> V_8 ;
}
return 0 ;
}
static struct V_40 *
F_59 ( struct V_83 * V_84 ,
struct V_40 * V_73 , unsigned int V_85 ,
T_1 V_17 )
{
struct V_40 * V_41 ;
int V_69 ;
V_41 = F_60 ( V_84 , V_73 , false , V_17 ) ;
if ( F_61 ( V_41 ) )
return V_41 ;
F_30 ( V_41 , V_85 ) ;
V_69 = F_62 ( V_84 , V_17 ) ;
if ( V_69 )
return F_63 ( V_69 ) ;
if ( F_64 ( V_73 ) )
F_31 ( V_73 ,
V_53 ,
V_49 ) ;
return V_41 ;
}
static int
F_65 ( struct V_83 * V_84 ,
struct V_1 * V_86 ,
struct V_5 * V_6 ,
T_1 V_17 )
{
struct V_16 * V_87 = & V_6 -> V_4 . V_20 ;
int V_69 ;
if ( ! V_6 -> V_9 )
return 0 ;
V_69 = F_7 ( V_87 , V_17 ) ;
if ( V_69 )
return V_69 ;
memcpy ( V_87 -> V_18 , V_6 -> V_18 , V_6 -> V_9 ) ;
return F_66 ( V_84 ,
V_45 ,
V_87 -> V_22 ,
V_6 -> V_9 ,
V_88 ,
V_17 ) ;
}
static struct V_40 *
F_67 ( struct V_83 * V_84 ,
struct V_1 * V_86 ,
struct V_5 * V_6 ,
unsigned int V_85 , T_1 V_17 )
{
struct V_16 * V_87 = & V_6 -> V_4 . V_20 ;
unsigned int V_7 , V_55 , V_89 = 0 ;
struct V_40 * V_41 ;
int V_69 ;
if ( V_6 -> V_7 <= V_50 && V_85 ) {
V_41 = F_59 ( V_84 , & V_6 -> V_48 , V_85 ,
V_17 ) ;
if ( F_61 ( V_41 ) )
return V_41 ;
F_28 ( V_41 , V_6 -> V_7 ) ;
F_31 ( V_41 , F_64 ( V_41 ) ?
V_52 :
V_54 ,
V_49 ) ;
return V_41 ;
}
V_69 = F_11 ( V_87 , V_17 ) ;
if ( V_69 )
return F_63 ( V_69 ) ;
V_55 = F_20 ( V_6 , V_87 -> V_24 ) ;
V_7 = F_68 ( V_47 - V_85 , V_55 ) ;
if ( V_7 ) {
V_69 = F_66 ( V_84 ,
V_45 +
V_85 ,
V_87 -> V_26 ,
V_7 , V_88 ,
V_17 ) ;
if ( V_69 )
return F_63 ( V_69 ) ;
V_41 = F_59 ( V_84 , & V_6 -> V_48 , V_85 + V_7 ,
V_17 ) ;
if ( F_61 ( V_41 ) )
return V_41 ;
if ( V_7 == V_55 )
return V_41 ;
V_89 += V_7 ;
}
V_69 = F_66 ( V_84 ,
V_45 ,
V_87 -> V_26 +
V_89 ,
V_55 - V_89 ,
V_88 ,
V_17 ) ;
if ( V_69 )
return F_63 ( V_69 ) ;
return F_59 ( V_84 , & V_6 -> V_48 , V_55 - V_89 ,
V_17 ) ;
}
static int F_69 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 V_17 = ( V_4 -> V_12 . V_17 & V_90 ) ?
V_91 : V_92 ;
struct V_16 * V_87 = & V_6 -> V_4 . V_20 ;
struct V_64 * V_65 = & V_87 -> V_12 ;
struct V_1 V_2 ;
struct V_40 * V_41 = NULL ;
unsigned int V_85 ;
int V_69 ;
V_65 -> V_84 . V_93 = NULL ;
V_65 -> V_84 . V_94 = NULL ;
if ( V_6 -> V_28 ) {
V_69 = F_70 ( V_19 -> V_27 , V_4 -> V_13 , V_6 -> V_28 ,
V_14 ) ;
if ( ! V_69 ) {
V_69 = - V_23 ;
goto V_95;
}
}
F_71 ( & V_65 -> V_84 ) ;
F_1 ( & V_2 , V_4 ) ;
V_69 = F_65 ( & V_65 -> V_84 , & V_2 , V_6 , V_17 ) ;
if ( V_69 )
goto V_96;
if ( V_2 . V_13 . V_97 ) {
while ( true ) {
V_69 = F_72 ( & V_65 -> V_84 ,
& V_2 . V_12 ,
& V_2 . V_13 , V_17 ) ;
if ( V_69 )
goto V_96;
V_85 = V_2 . V_12 . V_98 ;
if ( ! F_5 ( & V_2 ) )
break;
V_41 = F_59 ( & V_65 -> V_84 , & V_6 -> V_48 ,
V_85 , V_17 ) ;
if ( F_61 ( V_41 ) ) {
V_69 = F_73 ( V_41 ) ;
goto V_96;
}
}
} else {
V_85 = V_2 . V_12 . V_98 ;
}
if ( V_6 -> V_10 )
V_41 = F_67 ( & V_65 -> V_84 , & V_2 , V_6 ,
V_85 , V_17 ) ;
else if ( V_85 )
V_41 = F_59 ( & V_65 -> V_84 , & V_6 -> V_48 ,
V_85 , V_17 ) ;
if ( F_61 ( V_41 ) ) {
V_69 = F_73 ( V_41 ) ;
goto V_96;
}
if ( V_41 ) {
V_69 = F_74 ( & V_65 -> V_84 , V_17 ) ;
if ( V_69 )
goto V_96;
}
if ( ! V_6 -> V_10 )
V_6 -> V_9 = V_4 -> V_8 + V_6 -> V_9 -
V_2 . V_12 . V_7 ;
else
V_6 -> V_9 = 0 ;
return 0 ;
V_96:
F_16 ( V_65 ) ;
F_15 ( V_19 -> V_27 , V_4 -> V_13 , V_6 -> V_28 , V_14 ) ;
V_95:
F_18 ( V_4 ) ;
return V_69 ;
}
static int F_75 ( struct V_3 * V_4 , bool * V_82 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_69 ;
if ( V_19 -> V_99 -> V_100 )
V_6 -> V_4 . V_12 . type = V_29 ;
else
V_6 -> V_4 . V_12 . type = V_101 ;
V_6 -> V_28 = F_76 ( V_4 -> V_13 , V_4 -> V_8 ) ;
if ( V_6 -> V_28 < 0 ) {
F_77 ( V_19 -> V_27 , L_1 ) ;
return V_6 -> V_28 ;
}
V_69 = F_58 ( V_4 , V_82 ) ;
if ( V_69 )
return V_69 ;
if ( * V_82 )
return 0 ;
if ( V_6 -> V_4 . V_12 . type == V_29 )
V_69 = F_69 ( V_4 ) ;
return V_69 ;
}
static int F_78 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
bool V_82 = false ;
int V_69 ;
V_6 -> V_7 += V_4 -> V_8 ;
V_69 = F_75 ( V_4 , & V_82 ) ;
if ( V_69 )
return V_69 ;
if ( V_82 )
return 0 ;
V_69 = F_79 ( & V_4 -> V_12 ) ;
if ( F_80 ( & V_4 -> V_12 , V_69 ) )
F_17 ( V_4 ) ;
return V_69 ;
}
static int F_81 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_40 * V_73 = & V_6 -> V_48 ;
bool V_82 = false ;
int V_69 ;
F_28 ( V_73 , V_6 -> V_7 ) ;
V_6 -> V_10 = true ;
V_4 -> V_8 = 0 ;
V_69 = F_75 ( V_4 , & V_82 ) ;
if ( V_69 )
return V_69 ;
if ( V_82 )
return 0 ;
V_69 = F_79 ( & V_4 -> V_12 ) ;
if ( F_80 ( & V_4 -> V_12 , V_69 ) )
F_17 ( V_4 ) ;
return V_69 ;
}
static int F_82 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_40 * V_73 = & V_6 -> V_48 ;
bool V_82 = false ;
int V_69 ;
V_6 -> V_7 += V_4 -> V_8 ;
F_28 ( V_73 , V_6 -> V_7 ) ;
V_6 -> V_10 = true ;
V_69 = F_75 ( V_4 , & V_82 ) ;
if ( V_69 )
return V_69 ;
if ( V_82 )
return 0 ;
V_69 = F_79 ( & V_4 -> V_12 ) ;
if ( F_80 ( & V_4 -> V_12 , V_69 ) )
F_17 ( V_4 ) ;
return V_69 ;
}
static int F_83 ( struct V_3 * V_4 , void * V_102 ,
T_9 * V_7 , void * V_18 )
{
struct V_103 * V_104 = F_46 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned int V_68 = F_45 ( V_104 ) ;
unsigned int V_105 ;
V_105 = F_84 ( V_104 ) ;
* V_7 = V_6 -> V_7 ;
memcpy ( V_102 , V_6 -> V_71 , V_68 ) ;
memset ( V_18 , 0 , V_105 ) ;
if ( V_6 -> V_18 )
memcpy ( V_18 , V_6 -> V_18 , V_6 -> V_9 ) ;
return 0 ;
}
static int F_85 ( struct V_3 * V_4 , const void * V_102 ,
T_9 V_7 , const void * V_18 )
{
struct V_103 * V_104 = F_46 ( V_4 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned int V_68 = F_45 ( V_104 ) ;
unsigned int V_105 ;
unsigned int V_9 ;
int V_69 ;
V_69 = F_86 ( V_4 ) ;
if ( V_69 )
return V_69 ;
V_105 = F_84 ( V_104 ) ;
if ( V_7 >= V_105 )
F_31 ( & V_6 -> V_48 ,
V_53 ,
V_49 ) ;
V_6 -> V_7 = V_7 ;
memcpy ( V_6 -> V_71 , V_102 , V_68 ) ;
V_6 -> V_9 = 0 ;
V_9 = F_87 ( V_7 , V_105 ) ;
if ( ! V_9 )
return 0 ;
memcpy ( V_6 -> V_18 , V_18 , V_9 ) ;
V_6 -> V_9 = V_9 ;
return 0 ;
}
static int F_88 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_40 V_73 = { } ;
F_89 ( & V_73 , V_106 ) ;
V_6 -> V_71 [ 0 ] = V_107 ;
V_6 -> V_71 [ 1 ] = V_108 ;
V_6 -> V_71 [ 2 ] = V_109 ;
V_6 -> V_71 [ 3 ] = V_110 ;
F_53 ( V_4 , & V_73 , true ) ;
return 0 ;
}
static int F_90 ( struct V_3 * V_4 , void * V_111 )
{
struct V_112 * V_113 = V_111 ;
return F_83 ( V_4 , V_113 -> V_102 ,
& V_113 -> V_114 , V_113 -> V_115 ) ;
}
static int F_91 ( struct V_3 * V_4 , const void * V_116 )
{
const struct V_112 * V_117 = V_116 ;
return F_85 ( V_4 , V_117 -> V_102 , V_117 -> V_114 ,
V_117 -> V_115 ) ;
}
static int F_92 ( struct V_3 * V_4 )
{
int V_69 ;
V_69 = F_88 ( V_4 ) ;
if ( V_69 )
return V_69 ;
return F_82 ( V_4 ) ;
}
static int F_93 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_40 V_73 = { } ;
F_89 ( & V_73 , V_118 ) ;
V_6 -> V_71 [ 0 ] = V_119 ;
V_6 -> V_71 [ 1 ] = V_120 ;
V_6 -> V_71 [ 2 ] = V_121 ;
V_6 -> V_71 [ 3 ] = V_122 ;
V_6 -> V_71 [ 4 ] = V_123 ;
F_53 ( V_4 , & V_73 , false ) ;
return 0 ;
}
static int F_94 ( struct V_3 * V_4 , void * V_111 )
{
struct V_124 * V_113 = V_111 ;
return F_83 ( V_4 , V_113 -> V_71 , & V_113 -> V_125 ,
V_113 -> V_126 ) ;
}
static int F_95 ( struct V_3 * V_4 , const void * V_116 )
{
const struct V_124 * V_117 = V_116 ;
return F_85 ( V_4 , V_117 -> V_71 , V_117 -> V_125 ,
V_117 -> V_126 ) ;
}
static int F_96 ( struct V_3 * V_4 )
{
int V_69 ;
V_69 = F_93 ( V_4 ) ;
if ( V_69 )
return V_69 ;
return F_82 ( V_4 ) ;
}
static int F_97 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_40 V_73 = { } ;
F_89 ( & V_73 , V_127 ) ;
V_6 -> V_71 [ 0 ] = V_128 ;
V_6 -> V_71 [ 1 ] = V_129 ;
V_6 -> V_71 [ 2 ] = V_130 ;
V_6 -> V_71 [ 3 ] = V_131 ;
V_6 -> V_71 [ 4 ] = V_132 ;
V_6 -> V_71 [ 5 ] = V_133 ;
V_6 -> V_71 [ 6 ] = V_134 ;
V_6 -> V_71 [ 7 ] = V_135 ;
F_53 ( V_4 , & V_73 , false ) ;
return 0 ;
}
static int F_98 ( struct V_3 * V_4 )
{
int V_69 ;
V_69 = F_97 ( V_4 ) ;
if ( V_69 )
return V_69 ;
return F_82 ( V_4 ) ;
}
static int F_99 ( struct V_3 * V_4 , void * V_111 )
{
struct V_136 * V_113 = V_111 ;
return F_83 ( V_4 , V_113 -> V_71 , & V_113 -> V_125 ,
V_113 -> V_32 ) ;
}
static int F_100 ( struct V_3 * V_4 , const void * V_116 )
{
const struct V_136 * V_117 = V_116 ;
return F_85 ( V_4 , V_117 -> V_71 , V_117 -> V_125 ,
V_117 -> V_32 ) ;
}
static void F_101 ( struct V_66 * V_4 ,
int error )
{
struct V_137 * V_72 = V_4 -> V_138 ;
if ( error == - V_63 )
return;
V_72 -> error = error ;
F_102 ( & V_72 -> V_139 ) ;
}
static int F_103 ( struct V_3 * V_4 , T_2 * V_140 ,
void * V_71 , unsigned int V_105 )
{
struct V_137 V_72 ;
struct V_141 V_97 ;
int V_69 ;
F_104 ( V_4 , V_142 ,
F_101 , & V_72 ) ;
F_105 ( & V_97 , V_140 , V_105 ) ;
F_106 ( V_4 , & V_97 , V_140 , V_105 ) ;
F_107 ( & V_72 . V_139 ) ;
V_69 = F_86 ( V_4 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_108 ( V_4 ) ;
if ( V_69 && V_69 != - V_63 )
return V_69 ;
F_109 ( & V_72 . V_139 ) ;
if ( V_72 . error )
return V_72 . error ;
V_69 = F_110 ( V_4 , V_71 ) ;
if ( V_69 )
return V_69 ;
return 0 ;
}
static int F_111 ( struct V_3 * V_4 ,
const T_2 * V_143 , unsigned int V_144 ,
T_2 * V_145 , T_2 * V_146 ,
unsigned int V_105 )
{
struct V_137 V_72 ;
struct V_141 V_97 ;
int V_69 ;
int V_70 ;
if ( V_144 <= V_105 ) {
memcpy ( V_145 , V_143 , V_144 ) ;
} else {
T_2 * V_147 = F_112 ( V_143 , V_144 , V_91 ) ;
if ( ! V_147 )
return - V_23 ;
F_104 ( V_4 , V_142 ,
F_101 ,
& V_72 ) ;
F_105 ( & V_97 , V_147 , V_144 ) ;
F_106 ( V_4 , & V_97 , V_145 , V_144 ) ;
F_107 ( & V_72 . V_139 ) ;
V_69 = F_113 ( V_4 ) ;
if ( V_69 == - V_63 ) {
F_109 ( & V_72 . V_139 ) ;
V_69 = V_72 . error ;
}
memset ( V_147 , 0 , V_144 ) ;
F_114 ( V_147 ) ;
if ( V_69 )
return V_69 ;
V_144 = F_45 ( F_46 ( V_4 ) ) ;
}
memset ( V_145 + V_144 , 0 , V_105 - V_144 ) ;
memcpy ( V_146 , V_145 , V_105 ) ;
for ( V_70 = 0 ; V_70 < V_105 ; V_70 ++ ) {
V_145 [ V_70 ] ^= 0x36 ;
V_146 [ V_70 ] ^= 0x5c ;
}
return 0 ;
}
static int F_115 ( const char * V_148 ,
const T_2 * V_143 , unsigned int V_144 ,
void * V_149 , void * V_150 )
{
struct V_3 * V_4 ;
struct V_103 * V_77 ;
unsigned int V_105 ;
T_2 * V_145 = NULL ;
T_2 * V_146 ;
int V_69 ;
V_77 = F_116 ( V_148 , V_151 ,
V_152 ) ;
if ( F_61 ( V_77 ) )
return F_73 ( V_77 ) ;
V_4 = F_117 ( V_77 , V_91 ) ;
if ( ! V_4 ) {
V_69 = - V_23 ;
goto V_153;
}
F_118 ( V_77 , ~ 0 ) ;
V_105 = F_119 ( F_120 ( V_77 ) ) ;
V_145 = F_121 ( 2 * V_105 , V_91 ) ;
if ( ! V_145 ) {
V_69 = - V_23 ;
goto V_154;
}
V_146 = V_145 + V_105 ;
V_69 = F_111 ( V_4 , V_143 , V_144 , V_145 , V_146 , V_105 ) ;
if ( V_69 )
goto V_155;
V_69 = F_103 ( V_4 , V_145 , V_149 , V_105 ) ;
if ( V_69 )
goto V_155;
V_69 = F_103 ( V_4 , V_146 , V_150 , V_105 ) ;
V_155:
F_114 ( V_145 ) ;
V_154:
F_122 ( V_4 ) ;
V_153:
F_123 ( V_77 ) ;
return V_69 ;
}
static int F_124 ( struct V_76 * V_77 )
{
struct V_156 * V_79 = F_55 ( V_77 ) ;
V_79 -> V_12 . V_80 = & V_81 ;
F_56 ( F_57 ( V_77 ) ,
sizeof( struct V_5 ) ) ;
return 0 ;
}
static int F_125 ( struct V_3 * V_4 )
{
struct V_156 * V_79 = F_55 ( V_4 -> V_12 . V_77 ) ;
struct V_40 V_73 = { } ;
F_89 ( & V_73 , V_157 ) ;
memcpy ( V_73 . V_79 . V_102 . V_158 , V_79 -> V_158 , sizeof( V_79 -> V_158 ) ) ;
F_53 ( V_4 , & V_73 , true ) ;
return 0 ;
}
static int F_126 ( struct V_103 * V_77 , const T_2 * V_143 ,
unsigned int V_144 )
{
struct V_156 * V_79 = F_55 ( F_120 ( V_77 ) ) ;
struct V_112 V_149 , V_150 ;
int V_69 , V_70 ;
V_69 = F_115 ( L_2 , V_143 , V_144 , & V_149 , & V_150 ) ;
if ( V_69 )
return V_69 ;
for ( V_70 = 0 ; V_70 < F_127 ( V_149 . V_102 ) ; V_70 ++ )
V_79 -> V_158 [ V_70 ] = F_128 ( V_149 . V_102 [ V_70 ] ) ;
for ( V_70 = 0 ; V_70 < F_127 ( V_150 . V_102 ) ; V_70 ++ )
V_79 -> V_158 [ V_70 + 8 ] = F_128 ( V_150 . V_102 [ V_70 ] ) ;
return 0 ;
}
static int F_129 ( struct V_3 * V_4 )
{
int V_69 ;
V_69 = F_125 ( V_4 ) ;
if ( V_69 )
return V_69 ;
return F_82 ( V_4 ) ;
}
static int F_130 ( struct V_3 * V_4 )
{
struct V_156 * V_79 = F_55 ( V_4 -> V_12 . V_77 ) ;
struct V_40 V_73 = { } ;
F_89 ( & V_73 , V_159 ) ;
memcpy ( V_73 . V_79 . V_102 . V_158 , V_79 -> V_158 , sizeof( V_79 -> V_158 ) ) ;
F_53 ( V_4 , & V_73 , false ) ;
return 0 ;
}
static int F_131 ( struct V_103 * V_77 , const T_2 * V_143 ,
unsigned int V_144 )
{
struct V_156 * V_79 = F_55 ( F_120 ( V_77 ) ) ;
struct V_124 V_149 , V_150 ;
int V_69 , V_70 ;
V_69 = F_115 ( L_3 , V_143 , V_144 , & V_149 , & V_150 ) ;
if ( V_69 )
return V_69 ;
for ( V_70 = 0 ; V_70 < F_127 ( V_149 . V_71 ) ; V_70 ++ )
V_79 -> V_158 [ V_70 ] = F_128 ( V_149 . V_71 [ V_70 ] ) ;
for ( V_70 = 0 ; V_70 < F_127 ( V_150 . V_71 ) ; V_70 ++ )
V_79 -> V_158 [ V_70 + 8 ] = F_128 ( V_150 . V_71 [ V_70 ] ) ;
return 0 ;
}
static int F_132 ( struct V_3 * V_4 )
{
int V_69 ;
V_69 = F_130 ( V_4 ) ;
if ( V_69 )
return V_69 ;
return F_82 ( V_4 ) ;
}
static int F_133 ( struct V_103 * V_77 , const T_2 * V_143 ,
unsigned int V_144 )
{
struct V_156 * V_79 = F_55 ( F_120 ( V_77 ) ) ;
struct V_136 V_149 , V_150 ;
int V_69 , V_70 ;
V_69 = F_115 ( L_4 , V_143 , V_144 , & V_149 , & V_150 ) ;
if ( V_69 )
return V_69 ;
for ( V_70 = 0 ; V_70 < F_127 ( V_149 . V_71 ) ; V_70 ++ )
V_79 -> V_158 [ V_70 ] = F_128 ( V_149 . V_71 [ V_70 ] ) ;
for ( V_70 = 0 ; V_70 < F_127 ( V_150 . V_71 ) ; V_70 ++ )
V_79 -> V_158 [ V_70 + 8 ] = F_128 ( V_150 . V_71 [ V_70 ] ) ;
return 0 ;
}
static int F_134 ( struct V_3 * V_4 )
{
struct V_156 * V_79 = F_55 ( V_4 -> V_12 . V_77 ) ;
struct V_40 V_73 = { } ;
F_89 ( & V_73 , V_160 ) ;
memcpy ( V_73 . V_79 . V_102 . V_158 , V_79 -> V_158 , sizeof( V_79 -> V_158 ) ) ;
F_53 ( V_4 , & V_73 , false ) ;
return 0 ;
}
static int F_135 ( struct V_3 * V_4 )
{
int V_69 ;
V_69 = F_134 ( V_4 ) ;
if ( V_69 )
return V_69 ;
return F_82 ( V_4 ) ;
}
