static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
F_2 ( V_2 , V_3 + V_5 , V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return F_4 ( V_2 , V_3 + V_5 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
F_2 ( V_2 , V_3 + V_6 , V_4 ) ;
}
static inline T_1 F_6 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return F_4 ( V_2 , V_3 + V_6 ) ;
}
static inline T_1 F_7 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return F_4 ( V_2 , V_3 + V_7 ) ;
}
static inline void F_8 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_8 )
{
F_2 ( V_2 , V_3 + V_9 , V_8 ) ;
}
static inline void F_9 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
F_2 ( V_2 , V_3 + V_10 , V_4 ) ;
}
static inline void F_10 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
T_1 V_11 = F_4 ( ( V_2 ) ,
( V_3 ) + V_12 ) ;
F_2 ( V_2 , V_3 + V_12 ,
( V_11 & ~ V_13 ) |
F_11 ( V_4 ) ) ;
}
static inline void F_12 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
T_1 V_11 = F_4 ( V_2 , V_3 + V_12 ) ;
F_2 ( V_2 , V_3 + V_12 ,
( V_11 & ~ V_14 ) |
F_13 ( V_4 ) ) ;
}
static inline void F_14 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
T_1 V_11 = F_4 ( V_2 , V_3 + V_12 ) ;
F_2 ( V_2 , V_3 + V_12 ,
( V_11 & ~ V_15 ) |
F_15 ( V_4 ) ) ;
}
static inline T_1 F_16 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return F_4 ( V_2 , V_3 + V_16 ) ;
}
static inline void F_17 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_8 )
{
F_2 ( V_2 , V_3 + V_17 , V_8 ) ;
}
static inline void F_18 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
F_2 ( V_2 , V_3 + V_18 , V_4 ) ;
}
static inline void F_19 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
T_1 V_8 = F_4 ( V_2 , V_3 + V_19 ) ;
F_2 ( V_2 , V_3 + V_19 ,
( V_8 & ~ V_20 ) |
F_20 ( V_4 ) ) ;
}
static inline void F_21 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
T_1 V_8 = F_4 ( V_2 , V_3 + V_19 ) ;
F_2 ( V_2 , V_3 + V_19 ,
( V_8 & ~ V_21 ) |
F_22 ( V_4 ) ) ;
}
static inline void F_23 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
T_1 V_8 = F_4 ( V_2 , V_3 + V_22 ) ;
F_2 ( V_2 , V_3 + V_22 ,
( V_8 & ~ V_23 ) |
F_24 ( V_4 ) ) ;
}
static inline void F_25 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
T_1 V_8 = F_4 ( V_2 , V_3 + V_22 ) ;
F_2 ( V_2 , V_3 + V_22 ,
( V_8 & ~ V_24 ) |
F_26 ( V_4 ) ) ;
}
static inline void F_27 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_25 = F_4 ( V_2 ,
V_3 + V_26 ) ;
F_2 ( V_2 , V_3 + V_26 ,
V_25 | V_27 ) ;
}
static inline void F_28 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_25 = F_4 ( V_2 ,
V_3 + V_26 ) ;
F_2 ( V_2 , V_3 + V_26 ,
V_25 & ~ V_27 ) ;
}
static inline void F_29 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_25 = F_4 ( V_2 ,
V_3 + V_26 ) ;
F_2 ( V_2 , V_3 + V_26 ,
V_25 & ~ V_28 ) ;
}
static inline void F_30 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_29 = F_4 ( V_2 ,
V_3 + V_30 ) ;
F_2 ( V_2 , V_3 + V_30 ,
V_29 | V_31 ) ;
}
static inline void F_31 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_29 = F_4 ( V_2 ,
V_3 + V_30 ) ;
F_2 ( V_2 , V_3 + V_30 ,
V_29 & ~ V_31 ) ;
}
static inline void F_32 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_32 )
{
F_2 ( V_2 , V_3 + V_33 , V_32 ) ;
}
int F_33 ( struct V_34 * V_35 ,
void * V_36 ,
T_1 V_37 ,
unsigned int V_38 ,
unsigned int V_39 ,
unsigned int V_40 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_41 * V_42 = V_35 -> V_42 ;
struct V_43 * V_44 , * V_45 ;
unsigned int V_46 = V_42 -> V_46 ;
unsigned int V_47 = V_42 -> V_47 ;
unsigned int V_48 = V_42 -> V_48 ;
T_1 V_49 = V_35 -> V_49 ;
T_1 V_50 = 0 ;
int V_51 = 0 ;
if ( V_38 > V_35 -> V_52 )
F_34 ( V_2 , L_1 ,
V_53 , V_38 , V_35 -> V_52 ) ;
if ( F_35 ( F_36 ( V_46 ,
V_48 , V_47 - 1 ) <= 0 ) ) {
V_51 = - V_54 ;
goto exit;
}
V_44 = F_37 ( V_42 -> V_55 ,
V_48 ) ;
V_45 = F_37 ( V_42 -> V_56 , V_48 ) ;
V_50 |= F_38 ( V_39 , V_57 ) ;
if ( V_40 & V_58 )
V_50 |= V_59 ;
if ( V_40 & V_60 )
V_50 |= V_61 ;
V_45 -> V_8 = F_39 ( V_37 ) ;
V_45 -> V_38 = F_40 ( V_38 ) ;
V_45 -> V_40 = F_40 ( V_50 ) ;
* V_44 = * V_45 ;
V_42 -> V_36 [ V_48 ] = V_36 ;
V_48 = F_41 ( V_46 , V_48 ) ;
if ( ! ( V_40 & V_58 ) )
F_5 ( V_2 , V_49 , V_48 ) ;
V_42 -> V_48 = V_48 ;
exit:
return V_51 ;
}
void F_42 ( struct V_34 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_63 * V_64 = F_43 ( V_2 ) ;
struct V_41 * V_42 = V_62 -> V_42 ;
T_1 V_49 = V_62 -> V_49 ;
F_44 ( & V_64 -> V_65 ) ;
if ( F_45 ( V_42 -> V_48 == V_42 -> V_47 ) )
return;
if ( F_45 ( V_42 -> V_48 ==
F_6 ( V_2 , V_49 ) ) )
return;
V_42 -> V_48 -- ;
V_42 -> V_48 &= V_42 -> V_46 ;
V_42 -> V_36 [ V_42 -> V_48 ] = NULL ;
}
int F_46 ( struct V_34 * V_35 ,
void * V_36 ,
T_1 V_37 ,
unsigned int V_38 ,
unsigned int V_39 ,
unsigned int V_40 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_63 * V_64 = F_43 ( V_2 ) ;
int V_51 ;
F_47 ( & V_64 -> V_65 ) ;
V_51 = F_33 ( V_35 , V_36 ,
V_37 , V_38 , V_39 , V_40 ) ;
F_48 ( & V_64 -> V_65 ) ;
return V_51 ;
}
int F_49 ( struct V_34 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_63 * V_64 = F_43 ( V_2 ) ;
int V_66 ;
F_47 ( & V_64 -> V_65 ) ;
V_66 = F_36 ( V_62 -> V_42 -> V_46 ,
V_62 -> V_42 -> V_48 ,
V_62 -> V_42 -> V_47 - 1 ) ;
F_48 ( & V_64 -> V_65 ) ;
return V_66 ;
}
int F_50 ( struct V_34 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_63 * V_64 = F_43 ( V_2 ) ;
struct V_41 * V_67 = V_62 -> V_67 ;
unsigned int V_46 = V_67 -> V_46 ;
unsigned int V_48 = V_67 -> V_48 ;
unsigned int V_47 = V_67 -> V_47 ;
F_44 ( & V_64 -> V_65 ) ;
return F_36 ( V_46 , V_48 , V_47 - 1 ) ;
}
int F_51 ( struct V_34 * V_62 , void * V_68 , T_1 V_69 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_63 * V_64 = F_43 ( V_2 ) ;
struct V_41 * V_67 = V_62 -> V_67 ;
unsigned int V_46 = V_67 -> V_46 ;
unsigned int V_48 = V_67 -> V_48 ;
unsigned int V_47 = V_67 -> V_47 ;
struct V_43 * V_70 = V_67 -> V_55 ;
struct V_43 * V_44 = F_52 ( V_70 , V_48 ) ;
T_1 V_49 = V_62 -> V_49 ;
F_44 ( & V_64 -> V_65 ) ;
if ( F_36 ( V_46 , V_48 , V_47 - 1 ) == 0 )
return - V_71 ;
V_44 -> V_8 = F_39 ( V_69 ) ;
V_44 -> V_38 = 0 ;
V_67 -> V_36 [ V_48 ] = V_68 ;
V_48 = F_41 ( V_46 , V_48 ) ;
F_1 ( V_2 , V_49 , V_48 ) ;
V_67 -> V_48 = V_48 ;
return 0 ;
}
int F_53 ( struct V_34 * V_62 , void * V_68 , T_1 V_69 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_63 * V_64 = F_43 ( V_2 ) ;
int V_51 ;
F_47 ( & V_64 -> V_65 ) ;
V_51 = F_51 ( V_62 , V_68 , V_69 ) ;
F_48 ( & V_64 -> V_65 ) ;
return V_51 ;
}
static int F_54 ( struct V_34 * V_35 ,
void * * V_72 ,
T_1 * V_73 ,
unsigned int * V_74 ,
unsigned int * V_75 ,
unsigned int * V_76 )
{
struct V_41 * V_67 = V_35 -> V_67 ;
unsigned int V_46 = V_67 -> V_46 ;
unsigned int V_47 = V_67 -> V_47 ;
struct V_43 * V_70 = V_67 -> V_55 ;
struct V_43 * V_44 = F_52 ( V_70 , V_47 ) ;
struct V_43 V_45 ;
T_2 V_38 ;
V_45 = * V_44 ;
V_38 = F_55 ( V_45 . V_38 ) ;
if ( V_38 == 0 ) {
return - V_71 ;
}
V_44 -> V_38 = 0 ;
* V_73 = F_56 ( V_45 . V_8 ) ;
* V_74 = V_38 ;
* V_75 = F_57 ( F_55 ( V_45 . V_40 ) , V_57 ) ;
if ( F_55 ( V_45 . V_40 ) & V_61 )
* V_76 = V_77 ;
else
* V_76 = 0 ;
if ( V_72 )
* V_72 =
V_67 -> V_36 [ V_47 ] ;
V_67 -> V_36 [ V_47 ] = NULL ;
V_47 = F_41 ( V_46 , V_47 ) ;
V_67 -> V_47 = V_47 ;
return 0 ;
}
int F_58 ( struct V_34 * V_35 ,
void * * V_72 ,
T_1 * V_73 ,
unsigned int * V_74 ,
unsigned int * V_75 ,
unsigned int * V_76 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_63 * V_64 = F_43 ( V_2 ) ;
int V_51 ;
F_47 ( & V_64 -> V_65 ) ;
V_51 = F_54 ( V_35 ,
V_72 ,
V_73 , V_74 ,
V_75 , V_76 ) ;
F_48 ( & V_64 -> V_65 ) ;
return V_51 ;
}
int F_59 ( struct V_34 * V_35 ,
void * * V_72 ,
T_1 * V_73 )
{
struct V_41 * V_67 ;
unsigned int V_46 ;
unsigned int V_47 ;
unsigned int V_48 ;
int V_51 ;
struct V_1 * V_2 ;
struct V_63 * V_64 ;
V_67 = V_35 -> V_67 ;
if ( ! V_67 )
return - V_71 ;
V_2 = V_35 -> V_2 ;
V_64 = F_43 ( V_2 ) ;
F_47 ( & V_64 -> V_65 ) ;
V_46 = V_67 -> V_46 ;
V_47 = V_67 -> V_47 ;
V_48 = V_67 -> V_48 ;
if ( V_48 != V_47 ) {
struct V_43 * V_70 = V_67 -> V_55 ;
struct V_43 * V_44 = F_52 ( V_70 , V_47 ) ;
* V_73 = F_56 ( V_44 -> V_8 ) ;
if ( V_72 )
* V_72 =
V_67 -> V_36 [ V_47 ] ;
V_67 -> V_36 [ V_47 ] = NULL ;
V_47 = F_41 ( V_46 , V_47 ) ;
V_67 -> V_47 = V_47 ;
V_51 = 0 ;
} else {
V_51 = - V_71 ;
}
F_48 ( & V_64 -> V_65 ) ;
return V_51 ;
}
static int F_60 ( struct V_34 * V_35 ,
void * * V_72 ,
T_1 * V_73 ,
unsigned int * V_74 ,
unsigned int * V_75 )
{
struct V_41 * V_42 = V_35 -> V_42 ;
T_1 V_49 = V_35 -> V_49 ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned int V_46 = V_42 -> V_46 ;
unsigned int V_47 = V_42 -> V_47 ;
struct V_43 * V_45 , * V_78 ;
unsigned int V_79 ;
if ( V_42 -> V_80 == V_47 ) {
V_79 = F_7 ( V_2 , V_49 ) ;
if ( V_79 == 0xffffffff )
return - V_81 ;
V_79 &= V_46 ;
V_42 -> V_80 = V_79 ;
}
V_79 = V_42 -> V_80 ;
if ( V_79 == V_47 )
return - V_71 ;
V_78 = V_42 -> V_56 ;
V_45 = F_37 ( V_78 , V_47 ) ;
* V_73 = F_56 ( V_45 -> V_8 ) ;
* V_74 = F_55 ( V_45 -> V_38 ) ;
* V_75 = F_57 ( F_55 ( V_45 -> V_40 ) ,
V_57 ) ;
if ( V_72 )
* V_72 =
V_42 -> V_36 [ V_47 ] ;
V_42 -> V_36 [ V_47 ] = NULL ;
V_47 = F_41 ( V_46 , V_47 ) ;
V_42 -> V_47 = V_47 ;
return 0 ;
}
int F_61 ( struct V_34 * V_35 ,
void * * V_72 ,
T_1 * V_73 ,
unsigned int * V_74 ,
unsigned int * V_75 )
{
struct V_41 * V_42 ;
unsigned int V_46 ;
unsigned int V_47 ;
unsigned int V_48 ;
int V_51 ;
struct V_1 * V_2 ;
struct V_63 * V_64 ;
V_42 = V_35 -> V_42 ;
if ( ! V_42 )
return - V_71 ;
V_2 = V_35 -> V_2 ;
V_64 = F_43 ( V_2 ) ;
F_47 ( & V_64 -> V_65 ) ;
V_46 = V_42 -> V_46 ;
V_47 = V_42 -> V_47 ;
V_48 = V_42 -> V_48 ;
if ( V_48 != V_47 ) {
struct V_43 * V_70 = V_42 -> V_55 ;
struct V_43 * V_44 = F_37 ( V_70 , V_47 ) ;
* V_73 = F_56 ( V_44 -> V_8 ) ;
* V_74 = F_55 ( V_44 -> V_38 ) ;
* V_75 = F_57 ( F_55 ( V_44 -> V_40 ) ,
V_57 ) ;
if ( V_72 )
* V_72 =
V_42 -> V_36 [ V_47 ] ;
V_42 -> V_36 [ V_47 ] = NULL ;
V_47 = F_41 ( V_46 , V_47 ) ;
V_42 -> V_47 = V_47 ;
V_51 = 0 ;
} else {
V_51 = - V_71 ;
}
F_48 ( & V_64 -> V_65 ) ;
return V_51 ;
}
int F_62 ( struct V_34 * V_35 ,
void * * V_72 ,
T_1 * V_73 ,
unsigned int * V_74 ,
unsigned int * V_75 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_63 * V_64 = F_43 ( V_2 ) ;
int V_51 ;
F_47 ( & V_64 -> V_65 ) ;
V_51 = F_60 ( V_35 ,
V_72 ,
V_73 , V_74 ,
V_75 ) ;
F_48 ( & V_64 -> V_65 ) ;
return V_51 ;
}
void F_63 ( struct V_1 * V_2 , unsigned int V_82 )
{
struct V_63 * V_64 = F_43 ( V_2 ) ;
struct V_34 * V_35 = & V_64 -> V_83 [ V_82 ] ;
T_1 V_49 = V_35 -> V_49 ;
F_47 ( & V_64 -> V_65 ) ;
F_32 ( V_2 , V_49 ,
V_84 ) ;
F_48 ( & V_64 -> V_65 ) ;
if ( V_35 -> V_85 )
V_35 -> V_85 ( V_35 ) ;
if ( V_35 -> V_86 )
V_35 -> V_86 ( V_35 ) ;
F_47 ( & V_64 -> V_65 ) ;
F_32 ( V_2 , V_49 , V_28 ) ;
F_48 ( & V_64 -> V_65 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
int V_82 ;
T_1 V_87 ;
V_87 = F_65 ( V_2 ) ;
for ( V_82 = 0 ; V_87 && ( V_82 < V_88 ) ; V_82 ++ ) {
if ( V_87 & ( 1 << V_82 ) )
V_87 &= ~ ( 1 << V_82 ) ;
else
continue;
F_63 ( V_2 , V_82 ) ;
}
}
static void F_66 ( struct V_34 * V_35 )
{
T_1 V_49 = V_35 -> V_49 ;
struct V_1 * V_2 = V_35 -> V_2 ;
bool V_89 = V_35 -> V_90 & V_91 ;
if ( ( ! V_89 ) &&
( V_35 -> V_86 || V_35 -> V_85 ) )
F_27 ( V_2 , V_49 ) ;
else
F_28 ( V_2 , V_49 ) ;
F_29 ( V_2 , V_49 ) ;
}
int F_67 ( struct V_1 * V_2 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 < V_88 ; V_82 ++ ) {
T_1 V_49 = F_68 ( V_82 ) ;
F_28 ( V_2 , V_49 ) ;
F_31 ( V_2 , V_49 ) ;
F_29 ( V_2 , V_49 ) ;
}
return 0 ;
}
void F_69 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = F_43 ( V_2 ) ;
int V_82 ;
for ( V_82 = 0 ; V_82 < V_88 ; V_82 ++ )
F_66 ( & V_64 -> V_83 [ V_82 ] ) ;
}
static int F_70 ( struct V_1 * V_2 ,
unsigned int V_82 ,
const struct V_92 * V_93 )
{
struct V_63 * V_64 = F_43 ( V_2 ) ;
struct V_34 * V_35 = & V_64 -> V_83 [ V_82 ] ;
struct V_41 * V_42 = V_35 -> V_42 ;
T_1 V_94 , V_49 = F_68 ( V_82 ) ;
V_94 = F_71 ( V_93 -> V_95 ) ;
memset ( V_42 -> V_36 , 0 ,
V_94 * sizeof( * V_42 -> V_36 ) ) ;
V_42 -> V_47 = F_7 ( V_2 , V_49 ) ;
V_42 -> V_47 &= V_42 -> V_46 ;
V_42 -> V_80 = V_42 -> V_47 ;
V_42 -> V_48 =
F_6 ( V_2 , V_49 ) ;
V_42 -> V_48 &= V_42 -> V_46 ;
F_8 ( V_2 , V_49 ,
V_42 -> V_96 ) ;
F_9 ( V_2 , V_49 , V_94 ) ;
F_10 ( V_2 , V_49 , V_93 -> V_52 ) ;
F_12 ( V_2 , V_49 , 0 ) ;
F_21 ( V_2 , V_49 , 0 ) ;
F_19 ( V_2 , V_49 , V_94 ) ;
F_72 ( V_2 , V_97 ,
L_2 ,
V_82 , V_94 , V_42 -> V_55 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
unsigned int V_82 ,
const struct V_92 * V_93 )
{
struct V_63 * V_64 = F_43 ( V_2 ) ;
struct V_34 * V_35 = & V_64 -> V_83 [ V_82 ] ;
struct V_41 * V_67 = V_35 -> V_67 ;
T_1 V_94 , V_49 = F_68 ( V_82 ) ;
V_94 = F_71 ( V_93 -> V_98 ) ;
memset ( V_67 -> V_36 , 0 ,
V_94 * sizeof( * V_67 -> V_36 ) ) ;
V_67 -> V_47 = F_16 ( V_2 , V_49 ) ;
V_67 -> V_47 &= V_67 -> V_46 ;
V_67 -> V_48 =
F_3 ( V_2 , V_49 ) ;
V_67 -> V_48 &= V_67 -> V_46 ;
F_17 ( V_2 , V_49 ,
V_67 -> V_96 ) ;
F_18 ( V_2 , V_49 , V_94 ) ;
F_14 ( V_2 , V_49 , 0 ) ;
F_25 ( V_2 , V_49 , 0 ) ;
F_23 ( V_2 , V_49 , V_94 ) ;
F_72 ( V_2 , V_97 ,
L_3 ,
V_82 , V_94 , V_67 -> V_55 ) ;
return 0 ;
}
static struct V_41 *
F_74 ( struct V_1 * V_2 , unsigned int V_82 ,
const struct V_92 * V_93 )
{
struct V_41 * V_42 ;
T_1 V_94 = V_93 -> V_95 ;
T_3 V_99 ;
V_94 = F_71 ( V_94 ) ;
V_42 = F_75 ( sizeof( * V_42 ) +
( V_94 *
sizeof( * V_42 -> V_36 ) ) ,
V_100 ) ;
if ( V_42 == NULL )
return F_76 ( - V_101 ) ;
V_42 -> V_94 = V_94 ;
V_42 -> V_46 = V_94 - 1 ;
V_42 -> V_102 =
F_77 ( V_2 -> V_103 ,
( V_94 * sizeof( struct V_43 ) +
V_104 ) ,
& V_99 , V_100 ) ;
if ( ! V_42 -> V_102 ) {
F_78 ( V_42 ) ;
return F_76 ( - V_101 ) ;
}
V_42 -> V_105 = V_99 ;
V_42 -> V_55 = F_79 (
V_42 -> V_102 ,
V_104 ) ;
V_42 -> V_96 = F_80 (
V_42 -> V_105 ,
V_104 ) ;
V_42 -> V_106 =
F_81 ( ( V_94 * sizeof( struct V_43 ) +
V_104 ) , V_100 ) ;
if ( ! V_42 -> V_106 ) {
F_82 ( V_2 -> V_103 ,
( V_94 * sizeof( struct V_43 ) +
V_104 ) ,
V_42 -> V_55 ,
V_42 -> V_96 ) ;
F_78 ( V_42 ) ;
return F_76 ( - V_101 ) ;
}
V_42 -> V_56 = F_79 (
V_42 -> V_106 ,
V_104 ) ;
return V_42 ;
}
static struct V_41 *
F_83 ( struct V_1 * V_2 , unsigned int V_82 ,
const struct V_92 * V_93 )
{
struct V_41 * V_67 ;
T_1 V_94 ;
T_3 V_99 ;
V_94 = F_71 ( V_93 -> V_98 ) ;
V_67 = F_75 ( sizeof( * V_67 ) +
( V_94 *
sizeof( * V_67 -> V_36 ) ) ,
V_100 ) ;
if ( V_67 == NULL )
return F_76 ( - V_101 ) ;
V_67 -> V_94 = V_94 ;
V_67 -> V_46 = V_94 - 1 ;
V_67 -> V_102 =
F_77 ( V_2 -> V_103 ,
( V_94 * sizeof( struct V_43 ) +
V_104 ) ,
& V_99 , V_100 ) ;
if ( ! V_67 -> V_102 ) {
F_78 ( V_67 ) ;
return F_76 ( - V_101 ) ;
}
V_67 -> V_105 = V_99 ;
memset ( V_67 -> V_102 , 0 ,
V_94 * sizeof( struct V_43 ) + V_104 ) ;
V_67 -> V_55 = F_79 (
V_67 -> V_102 ,
V_104 ) ;
V_67 -> V_96 = F_80 (
V_67 -> V_105 ,
V_104 ) ;
return V_67 ;
}
int F_84 ( struct V_1 * V_2 , unsigned int V_82 ,
const struct V_92 * V_93 ,
void (* V_86)( struct V_34 * ) ,
void (* V_85)( struct V_34 * ) )
{
struct V_63 * V_64 = F_43 ( V_2 ) ;
struct V_34 * V_35 = & V_64 -> V_83 [ V_82 ] ;
int V_51 ;
F_85 ( 2 * V_107 >
( V_108 - 1 ) ) ;
F_85 ( 2 * V_109 >
( V_108 - 1 ) ) ;
F_47 ( & V_64 -> V_65 ) ;
V_35 -> V_2 = V_2 ;
V_35 -> V_110 = V_82 ;
V_35 -> V_49 = F_68 ( V_82 ) ;
V_35 -> V_90 = V_93 -> V_40 ;
V_35 -> V_52 = V_93 -> V_52 ;
if ( V_93 -> V_95 )
V_35 -> V_86 = V_86 ;
if ( V_93 -> V_98 )
V_35 -> V_85 = V_85 ;
F_48 ( & V_64 -> V_65 ) ;
if ( V_93 -> V_95 ) {
V_51 = F_70 ( V_2 , V_82 , V_93 ) ;
if ( V_51 ) {
F_86 ( V_2 , L_4 ,
V_82 , V_51 ) ;
return V_51 ;
}
}
if ( V_93 -> V_98 ) {
V_51 = F_73 ( V_2 , V_82 , V_93 ) ;
if ( V_51 ) {
F_86 ( V_2 , L_5 ,
V_82 , V_51 ) ;
return V_51 ;
}
}
return 0 ;
}
static void F_87 ( struct V_1 * V_2 , unsigned int V_82 )
{
T_1 V_49 = F_68 ( V_82 ) ;
F_8 ( V_2 , V_49 , 0 ) ;
F_9 ( V_2 , V_49 , 0 ) ;
F_10 ( V_2 , V_49 , 0 ) ;
F_19 ( V_2 , V_49 , 0 ) ;
}
static void F_88 ( struct V_1 * V_2 , unsigned int V_82 )
{
T_1 V_49 = F_68 ( V_82 ) ;
F_17 ( V_2 , V_49 , 0 ) ;
F_18 ( V_2 , V_49 , 0 ) ;
F_23 ( V_2 , V_49 , 0 ) ;
}
void F_89 ( struct V_1 * V_2 , unsigned int V_82 )
{
F_87 ( V_2 , V_82 ) ;
F_88 ( V_2 , V_82 ) ;
}
int F_90 ( struct V_1 * V_2 , int V_82 ,
const struct V_92 * V_93 )
{
struct V_63 * V_64 = F_43 ( V_2 ) ;
struct V_34 * V_35 = & V_64 -> V_83 [ V_82 ] ;
int V_51 ;
if ( V_93 -> V_95 ) {
V_35 -> V_42 = F_74 ( V_2 , V_82 , V_93 ) ;
if ( F_91 ( V_35 -> V_42 ) ) {
V_51 = F_92 ( V_35 -> V_42 ) ;
F_86 ( V_2 , L_6 ,
V_82 , V_51 ) ;
V_35 -> V_42 = NULL ;
return V_51 ;
}
}
if ( V_93 -> V_98 ) {
V_35 -> V_67 = F_83 ( V_2 , V_82 ,
V_93 ) ;
if ( F_91 ( V_35 -> V_67 ) ) {
V_51 = F_92 ( V_35 -> V_67 ) ;
F_86 ( V_2 , L_7 ,
V_82 , V_51 ) ;
V_35 -> V_67 = NULL ;
return V_51 ;
}
}
return 0 ;
}
void F_93 ( struct V_1 * V_2 , int V_82 )
{
struct V_63 * V_64 = F_43 ( V_2 ) ;
struct V_34 * V_35 = & V_64 -> V_83 [ V_82 ] ;
if ( V_35 -> V_42 ) {
F_78 ( V_35 -> V_42 -> V_106 ) ;
F_82 ( V_2 -> V_103 ,
( V_35 -> V_42 -> V_94 *
sizeof( struct V_43 ) +
V_104 ) ,
V_35 -> V_42 -> V_55 ,
V_35 -> V_42 -> V_96 ) ;
F_78 ( V_35 -> V_42 ) ;
}
if ( V_35 -> V_67 ) {
F_82 ( V_2 -> V_103 ,
( V_35 -> V_67 -> V_94 *
sizeof( struct V_43 ) +
V_104 ) ,
V_35 -> V_67 -> V_55 ,
V_35 -> V_67 -> V_96 ) ;
F_78 ( V_35 -> V_67 ) ;
}
V_35 -> V_42 = NULL ;
V_35 -> V_67 = NULL ;
}
