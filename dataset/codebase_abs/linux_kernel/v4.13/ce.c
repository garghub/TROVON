static inline unsigned int
F_1 ( unsigned int V_1 ,
struct V_2 * V_3 )
{
return ( ( V_1 << V_3 -> V_4 ) & V_3 -> V_5 ) ;
}
static inline unsigned int
F_2 ( unsigned int V_1 ,
struct V_2 * V_3 )
{
return ( ( V_1 & V_3 -> V_5 ) >> ( V_3 -> V_4 ) ) ;
}
static inline void F_3 ( struct V_6 * V_7 ,
T_1 V_8 ,
unsigned int V_9 )
{
F_4 ( V_7 , V_8 +
V_7 -> V_10 -> V_11 , V_9 ) ;
}
static inline T_1 F_5 ( struct V_6 * V_7 ,
T_1 V_8 )
{
return F_6 ( V_7 , V_8 +
V_7 -> V_10 -> V_11 ) ;
}
static inline void F_7 ( struct V_6 * V_7 ,
T_1 V_8 ,
unsigned int V_9 )
{
F_4 ( V_7 , V_8 +
V_7 -> V_10 -> V_12 , V_9 ) ;
}
static inline T_1 F_8 ( struct V_6 * V_7 ,
T_1 V_8 )
{
return F_6 ( V_7 , V_8 +
V_7 -> V_10 -> V_12 ) ;
}
static inline T_1 F_9 ( struct V_6 * V_7 ,
T_1 V_8 )
{
return F_6 ( V_7 , V_8 +
V_7 -> V_10 -> V_13 ) ;
}
static inline void F_10 ( struct V_6 * V_7 ,
T_1 V_8 ,
unsigned int V_14 )
{
F_4 ( V_7 , V_8 +
V_7 -> V_10 -> V_15 , V_14 ) ;
}
static inline void F_11 ( struct V_6 * V_7 ,
T_1 V_8 ,
unsigned int V_9 )
{
F_4 ( V_7 , V_8 +
V_7 -> V_10 -> V_16 , V_9 ) ;
}
static inline void F_12 ( struct V_6 * V_7 ,
T_1 V_8 ,
unsigned int V_9 )
{
struct V_17 * V_18 = V_7 -> V_10 -> V_19 ;
T_1 V_20 = F_6 ( V_7 ,
V_8 + V_18 -> V_14 ) ;
F_4 ( V_7 , V_8 + V_18 -> V_14 ,
( V_20 & ~ ( V_18 -> V_21 -> V_5 ) ) |
F_1 ( V_9 , V_18 -> V_21 ) ) ;
}
static inline void F_13 ( struct V_6 * V_7 ,
T_1 V_8 ,
unsigned int V_9 )
{
struct V_17 * V_18 = V_7 -> V_10 -> V_19 ;
T_1 V_20 = F_6 ( V_7 , V_8 + V_18 -> V_14 ) ;
F_4 ( V_7 , V_8 + V_18 -> V_14 ,
( V_20 & ~ ( V_18 -> V_22 -> V_5 ) ) |
F_1 ( V_9 , V_18 -> V_22 ) ) ;
}
static inline void F_14 ( struct V_6 * V_7 ,
T_1 V_8 ,
unsigned int V_9 )
{
struct V_17 * V_18 = V_7 -> V_10 -> V_19 ;
T_1 V_20 = F_6 ( V_7 , V_8 + V_18 -> V_14 ) ;
F_4 ( V_7 , V_8 + V_18 -> V_14 ,
( V_20 & ~ ( V_18 -> V_23 -> V_5 ) ) |
F_1 ( V_9 , V_18 -> V_23 ) ) ;
}
static inline T_1 F_15 ( struct V_6 * V_7 ,
T_1 V_8 )
{
return F_6 ( V_7 , V_8 +
V_7 -> V_10 -> V_24 ) ;
}
static inline void F_16 ( struct V_6 * V_7 ,
T_1 V_8 ,
T_1 V_14 )
{
F_4 ( V_7 , V_8 +
V_7 -> V_10 -> V_25 , V_14 ) ;
}
static inline void F_17 ( struct V_6 * V_7 ,
T_1 V_8 ,
unsigned int V_9 )
{
F_4 ( V_7 , V_8 +
V_7 -> V_10 -> V_26 , V_9 ) ;
}
static inline void F_18 ( struct V_6 * V_7 ,
T_1 V_8 ,
unsigned int V_9 )
{
struct V_27 * V_28 = V_7 -> V_10 -> V_29 ;
T_1 V_14 = F_6 ( V_7 , V_8 + V_28 -> V_14 ) ;
F_4 ( V_7 , V_8 + V_28 -> V_14 ,
( V_14 & ~ ( V_28 -> V_30 -> V_5 ) ) |
( F_1 ( V_9 , V_28 -> V_30 ) ) ) ;
}
static inline void F_19 ( struct V_6 * V_7 ,
T_1 V_8 ,
unsigned int V_9 )
{
struct V_27 * V_28 = V_7 -> V_10 -> V_29 ;
T_1 V_14 = F_6 ( V_7 , V_8 + V_28 -> V_14 ) ;
F_4 ( V_7 , V_8 + V_28 -> V_14 ,
( V_14 & ~ ( V_28 -> V_31 -> V_5 ) ) |
( F_1 ( V_9 , V_28 -> V_31 ) ) ) ;
}
static inline void F_20 ( struct V_6 * V_7 ,
T_1 V_8 ,
unsigned int V_9 )
{
struct V_27 * V_32 = V_7 -> V_10 -> V_33 ;
T_1 V_14 = F_6 ( V_7 , V_8 + V_32 -> V_14 ) ;
F_4 ( V_7 , V_8 + V_32 -> V_14 ,
( V_14 & ~ ( V_32 -> V_30 -> V_5 ) ) |
( F_1 ( V_9 , V_32 -> V_30 ) ) ) ;
}
static inline void F_21 ( struct V_6 * V_7 ,
T_1 V_8 ,
unsigned int V_9 )
{
struct V_27 * V_32 = V_7 -> V_10 -> V_33 ;
T_1 V_14 = F_6 ( V_7 , V_8 + V_32 -> V_14 ) ;
F_4 ( V_7 , V_8 + V_32 -> V_14 ,
( V_14 & ~ ( V_32 -> V_31 -> V_5 ) ) |
( F_1 ( V_9 , V_32 -> V_31 ) ) ) ;
}
static inline void F_22 ( struct V_6 * V_7 ,
T_1 V_8 )
{
struct V_34 * V_35 = V_7 -> V_10 -> V_35 ;
T_1 V_36 = F_6 ( V_7 , V_8 +
V_7 -> V_10 -> V_36 ) ;
F_4 ( V_7 , V_8 + V_7 -> V_10 -> V_36 ,
V_36 | V_35 -> V_37 -> V_5 ) ;
}
static inline void F_23 ( struct V_6 * V_7 ,
T_1 V_8 )
{
struct V_34 * V_35 = V_7 -> V_10 -> V_35 ;
T_1 V_36 = F_6 ( V_7 , V_8 +
V_7 -> V_10 -> V_36 ) ;
F_4 ( V_7 , V_8 + V_7 -> V_10 -> V_36 ,
V_36 & ~ ( V_35 -> V_37 -> V_5 ) ) ;
}
static inline void F_24 ( struct V_6 * V_7 ,
T_1 V_8 )
{
struct V_38 * V_39 = V_7 -> V_10 -> V_39 ;
T_1 V_36 = F_6 ( V_7 , V_8 +
V_7 -> V_10 -> V_36 ) ;
F_4 ( V_7 , V_8 + V_7 -> V_10 -> V_36 ,
V_36 & ~ ( V_39 -> V_40 ) ) ;
}
static inline void F_25 ( struct V_6 * V_7 ,
T_1 V_8 )
{
struct V_41 * V_42 = V_7 -> V_10 -> V_42 ;
T_1 V_43 = F_6 ( V_7 , V_8 +
V_7 -> V_10 -> V_43 ) ;
F_4 ( V_7 , V_8 + V_7 -> V_10 -> V_43 ,
V_43 | V_42 -> V_44 ) ;
}
static inline void F_26 ( struct V_6 * V_7 ,
T_1 V_8 )
{
struct V_41 * V_42 = V_7 -> V_10 -> V_42 ;
T_1 V_43 = F_6 ( V_7 , V_8 +
V_7 -> V_10 -> V_43 ) ;
F_4 ( V_7 , V_8 + V_7 -> V_10 -> V_43 ,
V_43 & ~ ( V_42 -> V_44 ) ) ;
}
static inline void F_27 ( struct V_6 * V_7 ,
T_1 V_8 ,
unsigned int V_5 )
{
struct V_38 * V_39 = V_7 -> V_10 -> V_39 ;
F_4 ( V_7 , V_8 + V_39 -> V_14 , V_5 ) ;
}
int F_28 ( struct V_45 * V_46 ,
void * V_47 ,
T_1 V_48 ,
unsigned int V_49 ,
unsigned int V_50 ,
unsigned int V_51 )
{
struct V_6 * V_7 = V_46 -> V_7 ;
struct V_52 * V_22 = V_46 -> V_22 ;
struct V_53 * V_54 , V_55 ;
unsigned int V_56 = V_22 -> V_56 ;
unsigned int V_57 = V_22 -> V_57 ;
unsigned int V_58 = V_22 -> V_58 ;
T_1 V_59 = V_46 -> V_59 ;
T_1 V_60 = 0 ;
int V_61 = 0 ;
if ( V_49 > V_46 -> V_62 )
F_29 ( V_7 , L_1 ,
V_63 , V_49 , V_46 -> V_62 ) ;
if ( F_30 ( F_31 ( V_56 ,
V_58 , V_57 - 1 ) <= 0 ) ) {
V_61 = - V_64 ;
goto exit;
}
V_54 = F_32 ( V_22 -> V_65 ,
V_58 ) ;
V_60 |= F_33 ( V_50 , V_66 ) ;
if ( V_51 & V_67 )
V_60 |= V_68 ;
if ( V_51 & V_69 )
V_60 |= V_70 ;
V_55 . V_14 = F_34 ( V_48 ) ;
V_55 . V_49 = F_35 ( V_49 ) ;
V_55 . V_51 = F_35 ( V_60 ) ;
* V_54 = V_55 ;
V_22 -> V_47 [ V_58 ] = V_47 ;
V_58 = F_36 ( V_56 , V_58 ) ;
if ( ! ( V_51 & V_67 ) )
F_7 ( V_7 , V_59 , V_58 ) ;
V_22 -> V_58 = V_58 ;
exit:
return V_61 ;
}
void F_37 ( struct V_45 * V_71 )
{
struct V_6 * V_7 = V_71 -> V_7 ;
struct V_72 * V_73 = F_38 ( V_7 ) ;
struct V_52 * V_22 = V_71 -> V_22 ;
T_1 V_59 = V_71 -> V_59 ;
F_39 ( & V_73 -> V_74 ) ;
if ( F_40 ( V_22 -> V_58 == V_22 -> V_57 ) )
return;
if ( F_40 ( V_22 -> V_58 ==
F_8 ( V_7 , V_59 ) ) )
return;
V_22 -> V_58 -- ;
V_22 -> V_58 &= V_22 -> V_56 ;
V_22 -> V_47 [ V_22 -> V_58 ] = NULL ;
}
int F_41 ( struct V_45 * V_46 ,
void * V_47 ,
T_1 V_48 ,
unsigned int V_49 ,
unsigned int V_50 ,
unsigned int V_51 )
{
struct V_6 * V_7 = V_46 -> V_7 ;
struct V_72 * V_73 = F_38 ( V_7 ) ;
int V_61 ;
F_42 ( & V_73 -> V_74 ) ;
V_61 = F_28 ( V_46 , V_47 ,
V_48 , V_49 , V_50 , V_51 ) ;
F_43 ( & V_73 -> V_74 ) ;
return V_61 ;
}
int F_44 ( struct V_45 * V_71 )
{
struct V_6 * V_7 = V_71 -> V_7 ;
struct V_72 * V_73 = F_38 ( V_7 ) ;
int V_75 ;
F_42 ( & V_73 -> V_74 ) ;
V_75 = F_31 ( V_71 -> V_22 -> V_56 ,
V_71 -> V_22 -> V_58 ,
V_71 -> V_22 -> V_57 - 1 ) ;
F_43 ( & V_73 -> V_74 ) ;
return V_75 ;
}
int F_45 ( struct V_45 * V_71 )
{
struct V_6 * V_7 = V_71 -> V_7 ;
struct V_72 * V_73 = F_38 ( V_7 ) ;
struct V_52 * V_76 = V_71 -> V_76 ;
unsigned int V_56 = V_76 -> V_56 ;
unsigned int V_58 = V_76 -> V_58 ;
unsigned int V_57 = V_76 -> V_57 ;
F_39 ( & V_73 -> V_74 ) ;
return F_31 ( V_56 , V_58 , V_57 - 1 ) ;
}
int F_46 ( struct V_45 * V_71 , void * V_77 , T_1 V_78 )
{
struct V_6 * V_7 = V_71 -> V_7 ;
struct V_72 * V_73 = F_38 ( V_7 ) ;
struct V_52 * V_76 = V_71 -> V_76 ;
unsigned int V_56 = V_76 -> V_56 ;
unsigned int V_58 = V_76 -> V_58 ;
unsigned int V_57 = V_76 -> V_57 ;
struct V_53 * V_79 = V_76 -> V_65 ;
struct V_53 * V_54 = F_47 ( V_79 , V_58 ) ;
T_1 V_59 = V_71 -> V_59 ;
F_39 ( & V_73 -> V_74 ) ;
if ( ( V_71 -> V_80 != 5 ) &&
F_31 ( V_56 , V_58 , V_57 - 1 ) == 0 )
return - V_81 ;
V_54 -> V_14 = F_34 ( V_78 ) ;
V_54 -> V_49 = 0 ;
V_76 -> V_47 [ V_58 ] = V_77 ;
V_58 = F_36 ( V_56 , V_58 ) ;
F_3 ( V_7 , V_59 , V_58 ) ;
V_76 -> V_58 = V_58 ;
return 0 ;
}
void F_48 ( struct V_45 * V_71 , T_1 V_82 )
{
struct V_6 * V_7 = V_71 -> V_7 ;
struct V_52 * V_76 = V_71 -> V_76 ;
unsigned int V_56 = V_76 -> V_56 ;
unsigned int V_58 = V_76 -> V_58 ;
T_1 V_59 = V_71 -> V_59 ;
T_1 V_83 = F_5 ( V_7 , V_59 ) ;
if ( ( V_83 + V_82 ) == V_76 -> V_57 )
V_82 -= 1 ;
V_58 = F_49 ( V_56 , V_58 , V_82 ) ;
F_3 ( V_7 , V_59 , V_58 ) ;
V_76 -> V_58 = V_58 ;
}
int F_50 ( struct V_45 * V_71 , void * V_77 , T_1 V_78 )
{
struct V_6 * V_7 = V_71 -> V_7 ;
struct V_72 * V_73 = F_38 ( V_7 ) ;
int V_61 ;
F_42 ( & V_73 -> V_74 ) ;
V_61 = F_46 ( V_71 , V_77 , V_78 ) ;
F_43 ( & V_73 -> V_74 ) ;
return V_61 ;
}
int F_51 ( struct V_45 * V_46 ,
void * * V_84 ,
unsigned int * V_85 )
{
struct V_52 * V_76 = V_46 -> V_76 ;
unsigned int V_56 = V_76 -> V_56 ;
unsigned int V_57 = V_76 -> V_57 ;
struct V_53 * V_79 = V_76 -> V_65 ;
struct V_53 * V_54 = F_47 ( V_79 , V_57 ) ;
struct V_53 V_55 ;
T_2 V_49 ;
V_55 = * V_54 ;
V_49 = F_52 ( V_55 . V_49 ) ;
if ( V_49 == 0 ) {
return - V_86 ;
}
V_54 -> V_49 = 0 ;
* V_85 = V_49 ;
if ( V_84 )
* V_84 =
V_76 -> V_47 [ V_57 ] ;
if ( V_46 -> V_80 != 5 )
V_76 -> V_47 [ V_57 ] = NULL ;
V_57 = F_36 ( V_56 , V_57 ) ;
V_76 -> V_57 = V_57 ;
return 0 ;
}
int F_53 ( struct V_45 * V_46 ,
void * * V_84 ,
unsigned int * V_85 )
{
struct V_6 * V_7 = V_46 -> V_7 ;
struct V_72 * V_73 = F_38 ( V_7 ) ;
int V_61 ;
F_42 ( & V_73 -> V_74 ) ;
V_61 = F_51 ( V_46 ,
V_84 ,
V_85 ) ;
F_43 ( & V_73 -> V_74 ) ;
return V_61 ;
}
int F_54 ( struct V_45 * V_46 ,
void * * V_84 ,
T_1 * V_87 )
{
struct V_52 * V_76 ;
unsigned int V_56 ;
unsigned int V_57 ;
unsigned int V_58 ;
int V_61 ;
struct V_6 * V_7 ;
struct V_72 * V_73 ;
V_76 = V_46 -> V_76 ;
if ( ! V_76 )
return - V_86 ;
V_7 = V_46 -> V_7 ;
V_73 = F_38 ( V_7 ) ;
F_42 ( & V_73 -> V_74 ) ;
V_56 = V_76 -> V_56 ;
V_57 = V_76 -> V_57 ;
V_58 = V_76 -> V_58 ;
if ( V_58 != V_57 ) {
struct V_53 * V_79 = V_76 -> V_65 ;
struct V_53 * V_54 = F_47 ( V_79 , V_57 ) ;
* V_87 = F_55 ( V_54 -> V_14 ) ;
if ( V_84 )
* V_84 =
V_76 -> V_47 [ V_57 ] ;
V_76 -> V_47 [ V_57 ] = NULL ;
V_54 -> V_49 = 0 ;
V_57 = F_36 ( V_56 , V_57 ) ;
V_76 -> V_57 = V_57 ;
V_61 = 0 ;
} else {
V_61 = - V_86 ;
}
F_43 ( & V_73 -> V_74 ) ;
return V_61 ;
}
int F_56 ( struct V_45 * V_46 ,
void * * V_84 )
{
struct V_52 * V_22 = V_46 -> V_22 ;
T_1 V_59 = V_46 -> V_59 ;
struct V_6 * V_7 = V_46 -> V_7 ;
unsigned int V_56 = V_22 -> V_56 ;
unsigned int V_57 = V_22 -> V_57 ;
unsigned int V_88 ;
struct V_53 * V_54 ;
if ( V_22 -> V_89 == V_57 ) {
V_88 = F_9 ( V_7 , V_59 ) ;
if ( V_88 == 0xffffffff )
return - V_90 ;
V_88 &= V_56 ;
V_22 -> V_89 = V_88 ;
}
V_88 = V_22 -> V_89 ;
if ( V_88 == V_57 )
return - V_86 ;
if ( V_84 )
* V_84 =
V_22 -> V_47 [ V_57 ] ;
V_22 -> V_47 [ V_57 ] = NULL ;
V_54 = F_32 ( V_22 -> V_65 ,
V_57 ) ;
V_54 -> V_49 = 0 ;
V_57 = F_36 ( V_56 , V_57 ) ;
V_22 -> V_57 = V_57 ;
return 0 ;
}
int F_57 ( struct V_45 * V_46 ,
void * * V_84 ,
T_1 * V_87 ,
unsigned int * V_85 ,
unsigned int * V_91 )
{
struct V_52 * V_22 ;
unsigned int V_56 ;
unsigned int V_57 ;
unsigned int V_58 ;
int V_61 ;
struct V_6 * V_7 ;
struct V_72 * V_73 ;
V_22 = V_46 -> V_22 ;
if ( ! V_22 )
return - V_86 ;
V_7 = V_46 -> V_7 ;
V_73 = F_38 ( V_7 ) ;
F_42 ( & V_73 -> V_74 ) ;
V_56 = V_22 -> V_56 ;
V_57 = V_22 -> V_57 ;
V_58 = V_22 -> V_58 ;
if ( V_58 != V_57 ) {
struct V_53 * V_79 = V_22 -> V_65 ;
struct V_53 * V_54 = F_32 ( V_79 , V_57 ) ;
* V_87 = F_55 ( V_54 -> V_14 ) ;
* V_85 = F_52 ( V_54 -> V_49 ) ;
* V_91 = F_58 ( F_52 ( V_54 -> V_51 ) ,
V_66 ) ;
if ( V_84 )
* V_84 =
V_22 -> V_47 [ V_57 ] ;
V_22 -> V_47 [ V_57 ] = NULL ;
V_57 = F_36 ( V_56 , V_57 ) ;
V_22 -> V_57 = V_57 ;
V_61 = 0 ;
} else {
V_61 = - V_86 ;
}
F_43 ( & V_73 -> V_74 ) ;
return V_61 ;
}
int F_59 ( struct V_45 * V_46 ,
void * * V_84 )
{
struct V_6 * V_7 = V_46 -> V_7 ;
struct V_72 * V_73 = F_38 ( V_7 ) ;
int V_61 ;
F_42 ( & V_73 -> V_74 ) ;
V_61 = F_56 ( V_46 ,
V_84 ) ;
F_43 ( & V_73 -> V_74 ) ;
return V_61 ;
}
void F_60 ( struct V_6 * V_7 , unsigned int V_92 )
{
struct V_72 * V_73 = F_38 ( V_7 ) ;
struct V_45 * V_46 = & V_73 -> V_93 [ V_92 ] ;
struct V_38 * V_39 = V_7 -> V_10 -> V_39 ;
T_1 V_59 = V_46 -> V_59 ;
F_42 ( & V_73 -> V_74 ) ;
F_27 ( V_7 , V_59 , V_39 -> V_94 ) ;
F_43 ( & V_73 -> V_74 ) ;
if ( V_46 -> V_95 )
V_46 -> V_95 ( V_46 ) ;
if ( V_46 -> V_96 )
V_46 -> V_96 ( V_46 ) ;
F_42 ( & V_73 -> V_74 ) ;
F_27 ( V_7 , V_59 , V_39 -> V_40 ) ;
F_43 ( & V_73 -> V_74 ) ;
}
void F_61 ( struct V_6 * V_7 )
{
int V_92 ;
T_1 V_97 ;
V_97 = F_62 ( V_7 ) ;
for ( V_92 = 0 ; V_97 && ( V_92 < V_98 ) ; V_92 ++ ) {
if ( V_97 & ( 1 << V_92 ) )
V_97 &= ~ ( 1 << V_92 ) ;
else
continue;
F_60 ( V_7 , V_92 ) ;
}
}
static void F_63 ( struct V_45 * V_46 )
{
T_1 V_59 = V_46 -> V_59 ;
struct V_6 * V_7 = V_46 -> V_7 ;
bool V_99 = V_46 -> V_100 & V_101 ;
if ( ( ! V_99 ) &&
( V_46 -> V_96 || V_46 -> V_95 ) )
F_22 ( V_7 , V_59 ) ;
else
F_23 ( V_7 , V_59 ) ;
F_24 ( V_7 , V_59 ) ;
}
int F_64 ( struct V_6 * V_7 )
{
int V_92 ;
for ( V_92 = 0 ; V_92 < V_98 ; V_92 ++ ) {
T_1 V_59 = F_65 ( V_7 , V_92 ) ;
F_23 ( V_7 , V_59 ) ;
F_26 ( V_7 , V_59 ) ;
F_24 ( V_7 , V_59 ) ;
}
return 0 ;
}
void F_66 ( struct V_6 * V_7 )
{
struct V_72 * V_73 = F_38 ( V_7 ) ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_98 - 1 ; V_92 ++ )
F_63 ( & V_73 -> V_93 [ V_92 ] ) ;
}
static int F_67 ( struct V_6 * V_7 ,
unsigned int V_92 ,
const struct V_102 * V_103 )
{
struct V_72 * V_73 = F_38 ( V_7 ) ;
struct V_45 * V_46 = & V_73 -> V_93 [ V_92 ] ;
struct V_52 * V_22 = V_46 -> V_22 ;
T_1 V_82 , V_59 = F_65 ( V_7 , V_92 ) ;
V_82 = F_68 ( V_103 -> V_104 ) ;
memset ( V_22 -> V_65 , 0 ,
V_82 * sizeof( struct V_53 ) ) ;
V_22 -> V_57 = F_9 ( V_7 , V_59 ) ;
V_22 -> V_57 &= V_22 -> V_56 ;
V_22 -> V_89 = V_22 -> V_57 ;
V_22 -> V_58 =
F_8 ( V_7 , V_59 ) ;
V_22 -> V_58 &= V_22 -> V_56 ;
F_10 ( V_7 , V_59 ,
V_22 -> V_105 ) ;
F_11 ( V_7 , V_59 , V_82 ) ;
F_12 ( V_7 , V_59 , V_103 -> V_62 ) ;
F_13 ( V_7 , V_59 , 0 ) ;
F_19 ( V_7 , V_59 , 0 ) ;
F_18 ( V_7 , V_59 , V_82 ) ;
F_69 ( V_7 , V_106 ,
L_2 ,
V_92 , V_82 , V_22 -> V_65 ) ;
return 0 ;
}
static int F_70 ( struct V_6 * V_7 ,
unsigned int V_92 ,
const struct V_102 * V_103 )
{
struct V_72 * V_73 = F_38 ( V_7 ) ;
struct V_45 * V_46 = & V_73 -> V_93 [ V_92 ] ;
struct V_52 * V_76 = V_46 -> V_76 ;
T_1 V_82 , V_59 = F_65 ( V_7 , V_92 ) ;
V_82 = F_68 ( V_103 -> V_107 ) ;
memset ( V_76 -> V_65 , 0 ,
V_82 * sizeof( struct V_53 ) ) ;
V_76 -> V_57 = F_15 ( V_7 , V_59 ) ;
V_76 -> V_57 &= V_76 -> V_56 ;
V_76 -> V_58 =
F_5 ( V_7 , V_59 ) ;
V_76 -> V_58 &= V_76 -> V_56 ;
F_16 ( V_7 , V_59 ,
V_76 -> V_105 ) ;
F_17 ( V_7 , V_59 , V_82 ) ;
F_14 ( V_7 , V_59 , 0 ) ;
F_21 ( V_7 , V_59 , 0 ) ;
F_20 ( V_7 , V_59 , V_82 ) ;
F_69 ( V_7 , V_106 ,
L_3 ,
V_92 , V_82 , V_76 -> V_65 ) ;
return 0 ;
}
static struct V_52 *
F_71 ( struct V_6 * V_7 , unsigned int V_92 ,
const struct V_102 * V_103 )
{
struct V_52 * V_22 ;
T_1 V_82 = V_103 -> V_104 ;
T_3 V_108 ;
V_82 = F_68 ( V_82 ) ;
V_22 = F_72 ( sizeof( * V_22 ) +
( V_82 *
sizeof( * V_22 -> V_47 ) ) ,
V_109 ) ;
if ( V_22 == NULL )
return F_73 ( - V_110 ) ;
V_22 -> V_82 = V_82 ;
V_22 -> V_56 = V_82 - 1 ;
V_22 -> V_111 =
F_74 ( V_7 -> V_112 ,
( V_82 * sizeof( struct V_53 ) +
V_113 ) ,
& V_108 , V_109 ) ;
if ( ! V_22 -> V_111 ) {
F_75 ( V_22 ) ;
return F_73 ( - V_110 ) ;
}
V_22 -> V_114 = V_108 ;
V_22 -> V_65 = F_76 (
V_22 -> V_111 ,
V_113 ) ;
V_22 -> V_105 = F_77 (
V_22 -> V_114 ,
V_113 ) ;
return V_22 ;
}
static struct V_52 *
F_78 ( struct V_6 * V_7 , unsigned int V_92 ,
const struct V_102 * V_103 )
{
struct V_52 * V_76 ;
T_1 V_82 ;
T_3 V_108 ;
V_82 = F_68 ( V_103 -> V_107 ) ;
V_76 = F_72 ( sizeof( * V_76 ) +
( V_82 *
sizeof( * V_76 -> V_47 ) ) ,
V_109 ) ;
if ( V_76 == NULL )
return F_73 ( - V_110 ) ;
V_76 -> V_82 = V_82 ;
V_76 -> V_56 = V_82 - 1 ;
V_76 -> V_111 =
F_79 ( V_7 -> V_112 ,
( V_82 * sizeof( struct V_53 ) +
V_113 ) ,
& V_108 , V_109 ) ;
if ( ! V_76 -> V_111 ) {
F_75 ( V_76 ) ;
return F_73 ( - V_110 ) ;
}
V_76 -> V_114 = V_108 ;
V_76 -> V_65 = F_76 (
V_76 -> V_111 ,
V_113 ) ;
V_76 -> V_105 = F_77 (
V_76 -> V_114 ,
V_113 ) ;
return V_76 ;
}
int F_80 ( struct V_6 * V_7 , unsigned int V_92 ,
const struct V_102 * V_103 )
{
int V_61 ;
if ( V_103 -> V_104 ) {
V_61 = F_67 ( V_7 , V_92 , V_103 ) ;
if ( V_61 ) {
F_81 ( V_7 , L_4 ,
V_92 , V_61 ) ;
return V_61 ;
}
}
if ( V_103 -> V_107 ) {
V_61 = F_70 ( V_7 , V_92 , V_103 ) ;
if ( V_61 ) {
F_81 ( V_7 , L_5 ,
V_92 , V_61 ) ;
return V_61 ;
}
}
return 0 ;
}
static void F_82 ( struct V_6 * V_7 , unsigned int V_92 )
{
T_1 V_59 = F_65 ( V_7 , V_92 ) ;
F_10 ( V_7 , V_59 , 0 ) ;
F_11 ( V_7 , V_59 , 0 ) ;
F_12 ( V_7 , V_59 , 0 ) ;
F_18 ( V_7 , V_59 , 0 ) ;
}
static void F_83 ( struct V_6 * V_7 , unsigned int V_92 )
{
T_1 V_59 = F_65 ( V_7 , V_92 ) ;
F_16 ( V_7 , V_59 , 0 ) ;
F_17 ( V_7 , V_59 , 0 ) ;
F_20 ( V_7 , V_59 , 0 ) ;
}
void F_84 ( struct V_6 * V_7 , unsigned int V_92 )
{
F_82 ( V_7 , V_92 ) ;
F_83 ( V_7 , V_92 ) ;
}
int F_85 ( struct V_6 * V_7 , int V_92 ,
const struct V_102 * V_103 )
{
struct V_72 * V_73 = F_38 ( V_7 ) ;
struct V_45 * V_46 = & V_73 -> V_93 [ V_92 ] ;
int V_61 ;
F_86 ( 2 * V_115 >
( V_116 - 1 ) ) ;
F_86 ( 2 * V_117 >
( V_116 - 1 ) ) ;
F_86 ( 2 * V_118 >
( V_116 - 1 ) ) ;
V_46 -> V_7 = V_7 ;
V_46 -> V_80 = V_92 ;
V_46 -> V_59 = F_65 ( V_7 , V_92 ) ;
V_46 -> V_100 = V_103 -> V_51 ;
V_46 -> V_62 = V_103 -> V_62 ;
if ( V_103 -> V_104 )
V_46 -> V_96 = V_103 -> V_96 ;
if ( V_103 -> V_107 )
V_46 -> V_95 = V_103 -> V_95 ;
if ( V_103 -> V_104 ) {
V_46 -> V_22 = F_71 ( V_7 , V_92 , V_103 ) ;
if ( F_87 ( V_46 -> V_22 ) ) {
V_61 = F_88 ( V_46 -> V_22 ) ;
F_81 ( V_7 , L_6 ,
V_92 , V_61 ) ;
V_46 -> V_22 = NULL ;
return V_61 ;
}
}
if ( V_103 -> V_107 ) {
V_46 -> V_76 = F_78 ( V_7 , V_92 ,
V_103 ) ;
if ( F_87 ( V_46 -> V_76 ) ) {
V_61 = F_88 ( V_46 -> V_76 ) ;
F_81 ( V_7 , L_7 ,
V_92 , V_61 ) ;
V_46 -> V_76 = NULL ;
return V_61 ;
}
}
return 0 ;
}
void F_89 ( struct V_6 * V_7 , int V_92 )
{
struct V_72 * V_73 = F_38 ( V_7 ) ;
struct V_45 * V_46 = & V_73 -> V_93 [ V_92 ] ;
if ( V_46 -> V_22 ) {
F_90 ( V_7 -> V_112 ,
( V_46 -> V_22 -> V_82 *
sizeof( struct V_53 ) +
V_113 ) ,
V_46 -> V_22 -> V_65 ,
V_46 -> V_22 -> V_105 ) ;
F_75 ( V_46 -> V_22 ) ;
}
if ( V_46 -> V_76 ) {
F_90 ( V_7 -> V_112 ,
( V_46 -> V_76 -> V_82 *
sizeof( struct V_53 ) +
V_113 ) ,
V_46 -> V_76 -> V_65 ,
V_46 -> V_76 -> V_105 ) ;
F_75 ( V_46 -> V_76 ) ;
}
V_46 -> V_22 = NULL ;
V_46 -> V_76 = NULL ;
}
void F_91 ( struct V_6 * V_7 ,
struct V_119 * V_120 )
{
struct V_72 * V_73 = F_38 ( V_7 ) ;
struct V_121 V_122 ;
T_1 V_14 , V_80 ;
F_39 ( & V_7 -> V_123 ) ;
F_81 ( V_7 , L_8 ) ;
F_42 ( & V_73 -> V_74 ) ;
for ( V_80 = 0 ; V_80 < V_98 ; V_80 ++ ) {
V_14 = F_65 ( V_7 , V_80 ) ;
V_122 . V_108 = F_92 ( V_14 ) ;
V_122 . V_124 =
F_92 ( F_8 ( V_7 , V_14 ) ) ;
V_122 . V_125 =
F_92 ( F_9 ( V_7 , V_14 ) ) ;
V_122 . V_126 =
F_92 ( F_5 ( V_7 , V_14 ) ) ;
V_122 . V_127 =
F_92 ( F_15 ( V_7 , V_14 ) ) ;
if ( V_120 )
V_120 -> V_128 [ V_80 ] = V_122 ;
F_81 ( V_7 , L_9 , V_80 ,
F_93 ( V_122 . V_108 ) ,
F_93 ( V_122 . V_124 ) ,
F_93 ( V_122 . V_125 ) ,
F_93 ( V_122 . V_126 ) ,
F_93 ( V_122 . V_127 ) ) ;
}
F_43 ( & V_73 -> V_74 ) ;
}
