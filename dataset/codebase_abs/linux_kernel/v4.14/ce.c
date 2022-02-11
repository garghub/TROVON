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
static inline T_1 F_3 ( struct V_6 * V_7 , T_1 V_1 )
{
struct V_8 * V_9 = F_4 ( V_7 ) ;
return V_9 -> V_10 -> V_11 ( V_7 , V_1 ) ;
}
static inline void F_5 ( struct V_6 * V_7 , T_1 V_1 , T_1 V_12 )
{
struct V_8 * V_9 = F_4 ( V_7 ) ;
V_9 -> V_10 -> V_13 ( V_7 , V_1 , V_12 ) ;
}
static inline void F_6 ( struct V_6 * V_7 ,
T_1 V_14 ,
unsigned int V_15 )
{
F_5 ( V_7 , V_14 +
V_7 -> V_16 -> V_17 , V_15 ) ;
}
static inline T_1 F_7 ( struct V_6 * V_7 ,
T_1 V_14 )
{
return F_3 ( V_7 , V_14 +
V_7 -> V_16 -> V_17 ) ;
}
static inline void F_8 ( struct V_6 * V_7 ,
T_1 V_14 ,
unsigned int V_15 )
{
F_5 ( V_7 , V_14 +
V_7 -> V_16 -> V_18 , V_15 ) ;
}
static inline T_1 F_9 ( struct V_6 * V_7 ,
T_1 V_14 )
{
return F_3 ( V_7 , V_14 +
V_7 -> V_16 -> V_18 ) ;
}
static inline T_1 F_10 ( struct V_6 * V_7 ,
T_1 V_14 )
{
return F_3 ( V_7 , V_14 +
V_7 -> V_16 -> V_19 ) ;
}
static inline void F_11 ( struct V_6 * V_7 ,
T_1 V_14 ,
unsigned int V_20 )
{
F_5 ( V_7 , V_14 +
V_7 -> V_16 -> V_21 , V_20 ) ;
}
static inline void F_12 ( struct V_6 * V_7 ,
T_1 V_14 ,
unsigned int V_15 )
{
F_5 ( V_7 , V_14 +
V_7 -> V_16 -> V_22 , V_15 ) ;
}
static inline void F_13 ( struct V_6 * V_7 ,
T_1 V_14 ,
unsigned int V_15 )
{
struct V_23 * V_24 = V_7 -> V_16 -> V_25 ;
T_1 V_26 = F_3 ( V_7 , V_14 +
V_24 -> V_20 ) ;
F_5 ( V_7 , V_14 + V_24 -> V_20 ,
( V_26 & ~ ( V_24 -> V_27 -> V_5 ) ) |
F_1 ( V_15 , V_24 -> V_27 ) ) ;
}
static inline void F_14 ( struct V_6 * V_7 ,
T_1 V_14 ,
unsigned int V_15 )
{
struct V_23 * V_24 = V_7 -> V_16 -> V_25 ;
T_1 V_26 = F_3 ( V_7 , V_14 +
V_24 -> V_20 ) ;
F_5 ( V_7 , V_14 + V_24 -> V_20 ,
( V_26 & ~ ( V_24 -> V_28 -> V_5 ) ) |
F_1 ( V_15 , V_24 -> V_28 ) ) ;
}
static inline void F_15 ( struct V_6 * V_7 ,
T_1 V_14 ,
unsigned int V_15 )
{
struct V_23 * V_24 = V_7 -> V_16 -> V_25 ;
T_1 V_26 = F_3 ( V_7 , V_14 +
V_24 -> V_20 ) ;
F_5 ( V_7 , V_14 + V_24 -> V_20 ,
( V_26 & ~ ( V_24 -> V_29 -> V_5 ) ) |
F_1 ( V_15 , V_24 -> V_29 ) ) ;
}
static inline T_1 F_16 ( struct V_6 * V_7 ,
T_1 V_14 )
{
return F_3 ( V_7 , V_14 +
V_7 -> V_16 -> V_30 ) ;
}
static inline void F_17 ( struct V_6 * V_7 ,
T_1 V_14 ,
T_1 V_20 )
{
F_5 ( V_7 , V_14 +
V_7 -> V_16 -> V_31 , V_20 ) ;
}
static inline void F_18 ( struct V_6 * V_7 ,
T_1 V_14 ,
unsigned int V_15 )
{
F_5 ( V_7 , V_14 +
V_7 -> V_16 -> V_32 , V_15 ) ;
}
static inline void F_19 ( struct V_6 * V_7 ,
T_1 V_14 ,
unsigned int V_15 )
{
struct V_33 * V_34 = V_7 -> V_16 -> V_35 ;
T_1 V_20 = F_3 ( V_7 , V_14 + V_34 -> V_20 ) ;
F_5 ( V_7 , V_14 + V_34 -> V_20 ,
( V_20 & ~ ( V_34 -> V_36 -> V_5 ) ) |
( F_1 ( V_15 , V_34 -> V_36 ) ) ) ;
}
static inline void F_20 ( struct V_6 * V_7 ,
T_1 V_14 ,
unsigned int V_15 )
{
struct V_33 * V_34 = V_7 -> V_16 -> V_35 ;
T_1 V_20 = F_3 ( V_7 , V_14 + V_34 -> V_20 ) ;
F_5 ( V_7 , V_14 + V_34 -> V_20 ,
( V_20 & ~ ( V_34 -> V_37 -> V_5 ) ) |
( F_1 ( V_15 , V_34 -> V_37 ) ) ) ;
}
static inline void F_21 ( struct V_6 * V_7 ,
T_1 V_14 ,
unsigned int V_15 )
{
struct V_33 * V_38 = V_7 -> V_16 -> V_39 ;
T_1 V_20 = F_3 ( V_7 , V_14 + V_38 -> V_20 ) ;
F_5 ( V_7 , V_14 + V_38 -> V_20 ,
( V_20 & ~ ( V_38 -> V_36 -> V_5 ) ) |
( F_1 ( V_15 , V_38 -> V_36 ) ) ) ;
}
static inline void F_22 ( struct V_6 * V_7 ,
T_1 V_14 ,
unsigned int V_15 )
{
struct V_33 * V_38 = V_7 -> V_16 -> V_39 ;
T_1 V_20 = F_3 ( V_7 , V_14 + V_38 -> V_20 ) ;
F_5 ( V_7 , V_14 + V_38 -> V_20 ,
( V_20 & ~ ( V_38 -> V_37 -> V_5 ) ) |
( F_1 ( V_15 , V_38 -> V_37 ) ) ) ;
}
static inline void F_23 ( struct V_6 * V_7 ,
T_1 V_14 )
{
struct V_40 * V_41 = V_7 -> V_16 -> V_41 ;
T_1 V_42 = F_3 ( V_7 , V_14 +
V_7 -> V_16 -> V_42 ) ;
F_5 ( V_7 , V_14 + V_7 -> V_16 -> V_42 ,
V_42 | V_41 -> V_43 -> V_5 ) ;
}
static inline void F_24 ( struct V_6 * V_7 ,
T_1 V_14 )
{
struct V_40 * V_41 = V_7 -> V_16 -> V_41 ;
T_1 V_42 = F_3 ( V_7 , V_14 +
V_7 -> V_16 -> V_42 ) ;
F_5 ( V_7 , V_14 + V_7 -> V_16 -> V_42 ,
V_42 & ~ ( V_41 -> V_43 -> V_5 ) ) ;
}
static inline void F_25 ( struct V_6 * V_7 ,
T_1 V_14 )
{
struct V_44 * V_45 = V_7 -> V_16 -> V_45 ;
T_1 V_42 = F_3 ( V_7 , V_14 +
V_7 -> V_16 -> V_42 ) ;
F_5 ( V_7 , V_14 + V_7 -> V_16 -> V_42 ,
V_42 & ~ ( V_45 -> V_46 ) ) ;
}
static inline void F_26 ( struct V_6 * V_7 ,
T_1 V_14 )
{
struct V_47 * V_48 = V_7 -> V_16 -> V_48 ;
T_1 V_49 = F_3 ( V_7 , V_14 +
V_7 -> V_16 -> V_49 ) ;
F_5 ( V_7 ,
V_14 + V_7 -> V_16 -> V_49 ,
V_49 | V_48 -> V_50 ) ;
}
static inline void F_27 ( struct V_6 * V_7 ,
T_1 V_14 )
{
struct V_47 * V_48 = V_7 -> V_16 -> V_48 ;
T_1 V_49 = F_3 ( V_7 ,
V_14 + V_7 -> V_16 -> V_49 ) ;
F_5 ( V_7 ,
V_14 + V_7 -> V_16 -> V_49 ,
V_49 & ~ ( V_48 -> V_50 ) ) ;
}
static inline void F_28 ( struct V_6 * V_7 ,
T_1 V_14 ,
unsigned int V_5 )
{
struct V_44 * V_45 = V_7 -> V_16 -> V_45 ;
F_5 ( V_7 , V_14 + V_45 -> V_20 , V_5 ) ;
}
int F_29 ( struct V_51 * V_52 ,
void * V_53 ,
T_1 V_54 ,
unsigned int V_55 ,
unsigned int V_56 ,
unsigned int V_57 )
{
struct V_6 * V_7 = V_52 -> V_7 ;
struct V_58 * V_28 = V_52 -> V_28 ;
struct V_59 * V_60 , V_61 ;
unsigned int V_62 = V_28 -> V_62 ;
unsigned int V_63 = V_28 -> V_63 ;
unsigned int V_64 = V_28 -> V_64 ;
T_1 V_65 = V_52 -> V_65 ;
T_1 V_66 = 0 ;
int V_67 = 0 ;
if ( V_55 > V_52 -> V_68 )
F_30 ( V_7 , L_1 ,
V_69 , V_55 , V_52 -> V_68 ) ;
if ( F_31 ( F_32 ( V_62 ,
V_64 , V_63 - 1 ) <= 0 ) ) {
V_67 = - V_70 ;
goto exit;
}
V_60 = F_33 ( V_28 -> V_71 ,
V_64 ) ;
V_66 |= F_34 ( V_56 , V_72 ) ;
if ( V_57 & V_73 )
V_66 |= V_74 ;
if ( V_57 & V_75 )
V_66 |= V_76 ;
V_61 . V_20 = F_35 ( V_54 ) ;
V_61 . V_55 = F_36 ( V_55 ) ;
V_61 . V_57 = F_36 ( V_66 ) ;
* V_60 = V_61 ;
V_28 -> V_53 [ V_64 ] = V_53 ;
V_64 = F_37 ( V_62 , V_64 ) ;
if ( ! ( V_57 & V_73 ) )
F_8 ( V_7 , V_65 , V_64 ) ;
V_28 -> V_64 = V_64 ;
exit:
return V_67 ;
}
void F_38 ( struct V_51 * V_77 )
{
struct V_6 * V_7 = V_77 -> V_7 ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_58 * V_28 = V_77 -> V_28 ;
T_1 V_65 = V_77 -> V_65 ;
F_39 ( & V_9 -> V_78 ) ;
if ( F_40 ( V_28 -> V_64 == V_28 -> V_63 ) )
return;
if ( F_40 ( V_28 -> V_64 ==
F_9 ( V_7 , V_65 ) ) )
return;
V_28 -> V_64 -- ;
V_28 -> V_64 &= V_28 -> V_62 ;
V_28 -> V_53 [ V_28 -> V_64 ] = NULL ;
}
int F_41 ( struct V_51 * V_52 ,
void * V_53 ,
T_1 V_54 ,
unsigned int V_55 ,
unsigned int V_56 ,
unsigned int V_57 )
{
struct V_6 * V_7 = V_52 -> V_7 ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
int V_67 ;
F_42 ( & V_9 -> V_78 ) ;
V_67 = F_29 ( V_52 , V_53 ,
V_54 , V_55 , V_56 , V_57 ) ;
F_43 ( & V_9 -> V_78 ) ;
return V_67 ;
}
int F_44 ( struct V_51 * V_77 )
{
struct V_6 * V_7 = V_77 -> V_7 ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
int V_79 ;
F_42 ( & V_9 -> V_78 ) ;
V_79 = F_32 ( V_77 -> V_28 -> V_62 ,
V_77 -> V_28 -> V_64 ,
V_77 -> V_28 -> V_63 - 1 ) ;
F_43 ( & V_9 -> V_78 ) ;
return V_79 ;
}
int F_45 ( struct V_51 * V_77 )
{
struct V_6 * V_7 = V_77 -> V_7 ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_58 * V_80 = V_77 -> V_80 ;
unsigned int V_62 = V_80 -> V_62 ;
unsigned int V_64 = V_80 -> V_64 ;
unsigned int V_63 = V_80 -> V_63 ;
F_39 ( & V_9 -> V_78 ) ;
return F_32 ( V_62 , V_64 , V_63 - 1 ) ;
}
int F_46 ( struct V_51 * V_77 , void * V_81 , T_1 V_82 )
{
struct V_6 * V_7 = V_77 -> V_7 ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_58 * V_80 = V_77 -> V_80 ;
unsigned int V_62 = V_80 -> V_62 ;
unsigned int V_64 = V_80 -> V_64 ;
unsigned int V_63 = V_80 -> V_63 ;
struct V_59 * V_83 = V_80 -> V_71 ;
struct V_59 * V_60 = F_47 ( V_83 , V_64 ) ;
T_1 V_65 = V_77 -> V_65 ;
F_39 ( & V_9 -> V_78 ) ;
if ( ( V_77 -> V_84 != 5 ) &&
F_32 ( V_62 , V_64 , V_63 - 1 ) == 0 )
return - V_85 ;
V_60 -> V_20 = F_35 ( V_82 ) ;
V_60 -> V_55 = 0 ;
V_80 -> V_53 [ V_64 ] = V_81 ;
V_64 = F_37 ( V_62 , V_64 ) ;
F_6 ( V_7 , V_65 , V_64 ) ;
V_80 -> V_64 = V_64 ;
return 0 ;
}
void F_48 ( struct V_51 * V_77 , T_1 V_86 )
{
struct V_6 * V_7 = V_77 -> V_7 ;
struct V_58 * V_80 = V_77 -> V_80 ;
unsigned int V_62 = V_80 -> V_62 ;
unsigned int V_64 = V_80 -> V_64 ;
T_1 V_65 = V_77 -> V_65 ;
T_1 V_87 = F_7 ( V_7 , V_65 ) ;
if ( ( V_87 + V_86 ) == V_80 -> V_63 )
V_86 -= 1 ;
V_64 = F_49 ( V_62 , V_64 , V_86 ) ;
F_6 ( V_7 , V_65 , V_64 ) ;
V_80 -> V_64 = V_64 ;
}
int F_50 ( struct V_51 * V_77 , void * V_81 , T_1 V_82 )
{
struct V_6 * V_7 = V_77 -> V_7 ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
int V_67 ;
F_42 ( & V_9 -> V_78 ) ;
V_67 = F_46 ( V_77 , V_81 , V_82 ) ;
F_43 ( & V_9 -> V_78 ) ;
return V_67 ;
}
int F_51 ( struct V_51 * V_52 ,
void * * V_88 ,
unsigned int * V_89 )
{
struct V_58 * V_80 = V_52 -> V_80 ;
unsigned int V_62 = V_80 -> V_62 ;
unsigned int V_63 = V_80 -> V_63 ;
struct V_59 * V_83 = V_80 -> V_71 ;
struct V_59 * V_60 = F_47 ( V_83 , V_63 ) ;
struct V_59 V_61 ;
T_2 V_55 ;
V_61 = * V_60 ;
V_55 = F_52 ( V_61 . V_55 ) ;
if ( V_55 == 0 ) {
return - V_90 ;
}
V_60 -> V_55 = 0 ;
* V_89 = V_55 ;
if ( V_88 )
* V_88 =
V_80 -> V_53 [ V_63 ] ;
if ( V_52 -> V_84 != 5 )
V_80 -> V_53 [ V_63 ] = NULL ;
V_63 = F_37 ( V_62 , V_63 ) ;
V_80 -> V_63 = V_63 ;
return 0 ;
}
int F_53 ( struct V_51 * V_52 ,
void * * V_88 ,
unsigned int * V_89 )
{
struct V_6 * V_7 = V_52 -> V_7 ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
int V_67 ;
F_42 ( & V_9 -> V_78 ) ;
V_67 = F_51 ( V_52 ,
V_88 ,
V_89 ) ;
F_43 ( & V_9 -> V_78 ) ;
return V_67 ;
}
int F_54 ( struct V_51 * V_52 ,
void * * V_88 ,
T_1 * V_91 )
{
struct V_58 * V_80 ;
unsigned int V_62 ;
unsigned int V_63 ;
unsigned int V_64 ;
int V_67 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_80 = V_52 -> V_80 ;
if ( ! V_80 )
return - V_90 ;
V_7 = V_52 -> V_7 ;
V_9 = F_4 ( V_7 ) ;
F_42 ( & V_9 -> V_78 ) ;
V_62 = V_80 -> V_62 ;
V_63 = V_80 -> V_63 ;
V_64 = V_80 -> V_64 ;
if ( V_64 != V_63 ) {
struct V_59 * V_83 = V_80 -> V_71 ;
struct V_59 * V_60 = F_47 ( V_83 , V_63 ) ;
* V_91 = F_55 ( V_60 -> V_20 ) ;
if ( V_88 )
* V_88 =
V_80 -> V_53 [ V_63 ] ;
V_80 -> V_53 [ V_63 ] = NULL ;
V_60 -> V_55 = 0 ;
V_63 = F_37 ( V_62 , V_63 ) ;
V_80 -> V_63 = V_63 ;
V_67 = 0 ;
} else {
V_67 = - V_90 ;
}
F_43 ( & V_9 -> V_78 ) ;
return V_67 ;
}
int F_56 ( struct V_51 * V_52 ,
void * * V_88 )
{
struct V_58 * V_28 = V_52 -> V_28 ;
T_1 V_65 = V_52 -> V_65 ;
struct V_6 * V_7 = V_52 -> V_7 ;
unsigned int V_62 = V_28 -> V_62 ;
unsigned int V_63 = V_28 -> V_63 ;
unsigned int V_92 ;
struct V_59 * V_60 ;
if ( V_28 -> V_93 == V_63 ) {
V_92 = F_10 ( V_7 , V_65 ) ;
if ( V_92 == 0xffffffff )
return - V_94 ;
V_92 &= V_62 ;
V_28 -> V_93 = V_92 ;
}
V_92 = V_28 -> V_93 ;
if ( V_92 == V_63 )
return - V_90 ;
if ( V_88 )
* V_88 =
V_28 -> V_53 [ V_63 ] ;
V_28 -> V_53 [ V_63 ] = NULL ;
V_60 = F_33 ( V_28 -> V_71 ,
V_63 ) ;
V_60 -> V_55 = 0 ;
V_63 = F_37 ( V_62 , V_63 ) ;
V_28 -> V_63 = V_63 ;
return 0 ;
}
int F_57 ( struct V_51 * V_52 ,
void * * V_88 ,
T_1 * V_91 ,
unsigned int * V_89 ,
unsigned int * V_95 )
{
struct V_58 * V_28 ;
unsigned int V_62 ;
unsigned int V_63 ;
unsigned int V_64 ;
int V_67 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_28 = V_52 -> V_28 ;
if ( ! V_28 )
return - V_90 ;
V_7 = V_52 -> V_7 ;
V_9 = F_4 ( V_7 ) ;
F_42 ( & V_9 -> V_78 ) ;
V_62 = V_28 -> V_62 ;
V_63 = V_28 -> V_63 ;
V_64 = V_28 -> V_64 ;
if ( V_64 != V_63 ) {
struct V_59 * V_83 = V_28 -> V_71 ;
struct V_59 * V_60 = F_33 ( V_83 , V_63 ) ;
* V_91 = F_55 ( V_60 -> V_20 ) ;
* V_89 = F_52 ( V_60 -> V_55 ) ;
* V_95 = F_58 ( F_52 ( V_60 -> V_57 ) ,
V_72 ) ;
if ( V_88 )
* V_88 =
V_28 -> V_53 [ V_63 ] ;
V_28 -> V_53 [ V_63 ] = NULL ;
V_63 = F_37 ( V_62 , V_63 ) ;
V_28 -> V_63 = V_63 ;
V_67 = 0 ;
} else {
V_67 = - V_90 ;
}
F_43 ( & V_9 -> V_78 ) ;
return V_67 ;
}
int F_59 ( struct V_51 * V_52 ,
void * * V_88 )
{
struct V_6 * V_7 = V_52 -> V_7 ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
int V_67 ;
F_42 ( & V_9 -> V_78 ) ;
V_67 = F_56 ( V_52 ,
V_88 ) ;
F_43 ( & V_9 -> V_78 ) ;
return V_67 ;
}
void F_60 ( struct V_6 * V_7 , unsigned int V_96 )
{
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_51 * V_52 = & V_9 -> V_97 [ V_96 ] ;
struct V_44 * V_45 = V_7 -> V_16 -> V_45 ;
T_1 V_65 = V_52 -> V_65 ;
F_42 ( & V_9 -> V_78 ) ;
F_28 ( V_7 , V_65 ,
V_45 -> V_98 ) ;
F_43 ( & V_9 -> V_78 ) ;
if ( V_52 -> V_99 )
V_52 -> V_99 ( V_52 ) ;
if ( V_52 -> V_100 )
V_52 -> V_100 ( V_52 ) ;
F_42 ( & V_9 -> V_78 ) ;
F_28 ( V_7 , V_65 , V_45 -> V_46 ) ;
F_43 ( & V_9 -> V_78 ) ;
}
void F_61 ( struct V_6 * V_7 )
{
int V_96 ;
T_1 V_101 ;
V_101 = F_62 ( V_7 ) ;
for ( V_96 = 0 ; V_101 && ( V_96 < V_102 ) ; V_96 ++ ) {
if ( V_101 & ( 1 << V_96 ) )
V_101 &= ~ ( 1 << V_96 ) ;
else
continue;
F_60 ( V_7 , V_96 ) ;
}
}
static void F_63 ( struct V_51 * V_52 )
{
T_1 V_65 = V_52 -> V_65 ;
struct V_6 * V_7 = V_52 -> V_7 ;
bool V_103 = V_52 -> V_104 & V_105 ;
if ( ( ! V_103 ) &&
( V_52 -> V_100 || V_52 -> V_99 ) )
F_23 ( V_7 , V_65 ) ;
else
F_24 ( V_7 , V_65 ) ;
F_25 ( V_7 , V_65 ) ;
}
int F_64 ( struct V_6 * V_7 )
{
int V_96 ;
for ( V_96 = 0 ; V_96 < V_102 ; V_96 ++ ) {
T_1 V_65 = F_65 ( V_7 , V_96 ) ;
F_24 ( V_7 , V_65 ) ;
F_27 ( V_7 , V_65 ) ;
F_25 ( V_7 , V_65 ) ;
}
return 0 ;
}
void F_66 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_4 ( V_7 ) ;
int V_96 ;
struct V_51 * V_52 ;
for ( V_96 = 0 ; V_96 < V_102 - 1 ; V_96 ++ ) {
V_52 = & V_9 -> V_97 [ V_96 ] ;
F_63 ( V_52 ) ;
}
}
static int F_67 ( struct V_6 * V_7 ,
unsigned int V_96 ,
const struct V_106 * V_107 )
{
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_51 * V_52 = & V_9 -> V_97 [ V_96 ] ;
struct V_58 * V_28 = V_52 -> V_28 ;
T_1 V_86 , V_65 = F_65 ( V_7 , V_96 ) ;
V_86 = F_68 ( V_107 -> V_108 ) ;
memset ( V_28 -> V_71 , 0 ,
V_86 * sizeof( struct V_59 ) ) ;
V_28 -> V_63 = F_10 ( V_7 , V_65 ) ;
V_28 -> V_63 &= V_28 -> V_62 ;
V_28 -> V_93 = V_28 -> V_63 ;
V_28 -> V_64 =
F_9 ( V_7 , V_65 ) ;
V_28 -> V_64 &= V_28 -> V_62 ;
F_11 ( V_7 , V_65 ,
V_28 -> V_109 ) ;
F_12 ( V_7 , V_65 , V_86 ) ;
F_13 ( V_7 , V_65 , V_107 -> V_68 ) ;
F_14 ( V_7 , V_65 , 0 ) ;
F_20 ( V_7 , V_65 , 0 ) ;
F_19 ( V_7 , V_65 , V_86 ) ;
F_69 ( V_7 , V_110 ,
L_2 ,
V_96 , V_86 , V_28 -> V_71 ) ;
return 0 ;
}
static int F_70 ( struct V_6 * V_7 ,
unsigned int V_96 ,
const struct V_106 * V_107 )
{
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_51 * V_52 = & V_9 -> V_97 [ V_96 ] ;
struct V_58 * V_80 = V_52 -> V_80 ;
T_1 V_86 , V_65 = F_65 ( V_7 , V_96 ) ;
V_86 = F_68 ( V_107 -> V_111 ) ;
memset ( V_80 -> V_71 , 0 ,
V_86 * sizeof( struct V_59 ) ) ;
V_80 -> V_63 = F_16 ( V_7 , V_65 ) ;
V_80 -> V_63 &= V_80 -> V_62 ;
V_80 -> V_64 =
F_7 ( V_7 , V_65 ) ;
V_80 -> V_64 &= V_80 -> V_62 ;
F_17 ( V_7 , V_65 ,
V_80 -> V_109 ) ;
F_18 ( V_7 , V_65 , V_86 ) ;
F_15 ( V_7 , V_65 , 0 ) ;
F_22 ( V_7 , V_65 , 0 ) ;
F_21 ( V_7 , V_65 , V_86 ) ;
F_69 ( V_7 , V_110 ,
L_3 ,
V_96 , V_86 , V_80 -> V_71 ) ;
return 0 ;
}
static struct V_58 *
F_71 ( struct V_6 * V_7 , unsigned int V_96 ,
const struct V_106 * V_107 )
{
struct V_58 * V_28 ;
T_1 V_86 = V_107 -> V_108 ;
T_3 V_112 ;
V_86 = F_68 ( V_86 ) ;
V_28 = F_72 ( sizeof( * V_28 ) +
( V_86 *
sizeof( * V_28 -> V_53 ) ) ,
V_113 ) ;
if ( V_28 == NULL )
return F_73 ( - V_114 ) ;
V_28 -> V_86 = V_86 ;
V_28 -> V_62 = V_86 - 1 ;
V_28 -> V_115 =
F_74 ( V_7 -> V_116 ,
( V_86 * sizeof( struct V_59 ) +
V_117 ) ,
& V_112 , V_113 ) ;
if ( ! V_28 -> V_115 ) {
F_75 ( V_28 ) ;
return F_73 ( - V_114 ) ;
}
V_28 -> V_118 = V_112 ;
V_28 -> V_71 = F_76 (
V_28 -> V_115 ,
V_117 ) ;
V_28 -> V_109 = F_77 (
V_28 -> V_118 ,
V_117 ) ;
return V_28 ;
}
static struct V_58 *
F_78 ( struct V_6 * V_7 , unsigned int V_96 ,
const struct V_106 * V_107 )
{
struct V_58 * V_80 ;
T_1 V_86 ;
T_3 V_112 ;
V_86 = F_68 ( V_107 -> V_111 ) ;
V_80 = F_72 ( sizeof( * V_80 ) +
( V_86 *
sizeof( * V_80 -> V_53 ) ) ,
V_113 ) ;
if ( V_80 == NULL )
return F_73 ( - V_114 ) ;
V_80 -> V_86 = V_86 ;
V_80 -> V_62 = V_86 - 1 ;
V_80 -> V_115 =
F_79 ( V_7 -> V_116 ,
( V_86 * sizeof( struct V_59 ) +
V_117 ) ,
& V_112 , V_113 ) ;
if ( ! V_80 -> V_115 ) {
F_75 ( V_80 ) ;
return F_73 ( - V_114 ) ;
}
V_80 -> V_118 = V_112 ;
V_80 -> V_71 = F_76 (
V_80 -> V_115 ,
V_117 ) ;
V_80 -> V_109 = F_77 (
V_80 -> V_118 ,
V_117 ) ;
return V_80 ;
}
int F_80 ( struct V_6 * V_7 , unsigned int V_96 ,
const struct V_106 * V_107 )
{
int V_67 ;
if ( V_107 -> V_108 ) {
V_67 = F_67 ( V_7 , V_96 , V_107 ) ;
if ( V_67 ) {
F_81 ( V_7 , L_4 ,
V_96 , V_67 ) ;
return V_67 ;
}
}
if ( V_107 -> V_111 ) {
V_67 = F_70 ( V_7 , V_96 , V_107 ) ;
if ( V_67 ) {
F_81 ( V_7 , L_5 ,
V_96 , V_67 ) ;
return V_67 ;
}
}
return 0 ;
}
static void F_82 ( struct V_6 * V_7 , unsigned int V_96 )
{
T_1 V_65 = F_65 ( V_7 , V_96 ) ;
F_11 ( V_7 , V_65 , 0 ) ;
F_12 ( V_7 , V_65 , 0 ) ;
F_13 ( V_7 , V_65 , 0 ) ;
F_19 ( V_7 , V_65 , 0 ) ;
}
static void F_83 ( struct V_6 * V_7 , unsigned int V_96 )
{
T_1 V_65 = F_65 ( V_7 , V_96 ) ;
F_17 ( V_7 , V_65 , 0 ) ;
F_18 ( V_7 , V_65 , 0 ) ;
F_21 ( V_7 , V_65 , 0 ) ;
}
void F_84 ( struct V_6 * V_7 , unsigned int V_96 )
{
F_82 ( V_7 , V_96 ) ;
F_83 ( V_7 , V_96 ) ;
}
int F_85 ( struct V_6 * V_7 , int V_96 ,
const struct V_106 * V_107 )
{
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_51 * V_52 = & V_9 -> V_97 [ V_96 ] ;
int V_67 ;
F_86 ( 2 * V_119 >
( V_120 - 1 ) ) ;
F_86 ( 2 * V_121 >
( V_120 - 1 ) ) ;
F_86 ( 2 * V_122 >
( V_120 - 1 ) ) ;
V_52 -> V_7 = V_7 ;
V_52 -> V_84 = V_96 ;
V_52 -> V_65 = F_65 ( V_7 , V_96 ) ;
V_52 -> V_104 = V_107 -> V_57 ;
V_52 -> V_68 = V_107 -> V_68 ;
if ( V_107 -> V_108 )
V_52 -> V_100 = V_107 -> V_100 ;
if ( V_107 -> V_111 )
V_52 -> V_99 = V_107 -> V_99 ;
if ( V_107 -> V_108 ) {
V_52 -> V_28 = F_71 ( V_7 , V_96 , V_107 ) ;
if ( F_87 ( V_52 -> V_28 ) ) {
V_67 = F_88 ( V_52 -> V_28 ) ;
F_81 ( V_7 , L_6 ,
V_96 , V_67 ) ;
V_52 -> V_28 = NULL ;
return V_67 ;
}
}
if ( V_107 -> V_111 ) {
V_52 -> V_80 = F_78 ( V_7 , V_96 ,
V_107 ) ;
if ( F_87 ( V_52 -> V_80 ) ) {
V_67 = F_88 ( V_52 -> V_80 ) ;
F_81 ( V_7 , L_7 ,
V_96 , V_67 ) ;
V_52 -> V_80 = NULL ;
return V_67 ;
}
}
return 0 ;
}
void F_89 ( struct V_6 * V_7 , int V_96 )
{
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_51 * V_52 = & V_9 -> V_97 [ V_96 ] ;
if ( V_52 -> V_28 ) {
F_90 ( V_7 -> V_116 ,
( V_52 -> V_28 -> V_86 *
sizeof( struct V_59 ) +
V_117 ) ,
V_52 -> V_28 -> V_71 ,
V_52 -> V_28 -> V_109 ) ;
F_75 ( V_52 -> V_28 ) ;
}
if ( V_52 -> V_80 ) {
F_90 ( V_7 -> V_116 ,
( V_52 -> V_80 -> V_86 *
sizeof( struct V_59 ) +
V_117 ) ,
V_52 -> V_80 -> V_71 ,
V_52 -> V_80 -> V_109 ) ;
F_75 ( V_52 -> V_80 ) ;
}
V_52 -> V_28 = NULL ;
V_52 -> V_80 = NULL ;
}
void F_91 ( struct V_6 * V_7 ,
struct V_123 * V_124 )
{
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_125 V_126 ;
T_1 V_20 , V_84 ;
F_39 ( & V_7 -> V_127 ) ;
F_81 ( V_7 , L_8 ) ;
F_42 ( & V_9 -> V_78 ) ;
for ( V_84 = 0 ; V_84 < V_102 ; V_84 ++ ) {
V_20 = F_65 ( V_7 , V_84 ) ;
V_126 . V_112 = F_92 ( V_20 ) ;
V_126 . V_128 =
F_92 ( F_9 ( V_7 , V_20 ) ) ;
V_126 . V_129 =
F_92 ( F_10 ( V_7 , V_20 ) ) ;
V_126 . V_130 =
F_92 ( F_7 ( V_7 , V_20 ) ) ;
V_126 . V_131 =
F_92 ( F_16 ( V_7 , V_20 ) ) ;
if ( V_124 )
V_124 -> V_132 [ V_84 ] = V_126 ;
F_81 ( V_7 , L_9 , V_84 ,
F_93 ( V_126 . V_112 ) ,
F_93 ( V_126 . V_128 ) ,
F_93 ( V_126 . V_129 ) ,
F_93 ( V_126 . V_130 ) ,
F_93 ( V_126 . V_131 ) ) ;
}
F_43 ( & V_9 -> V_78 ) ;
}
