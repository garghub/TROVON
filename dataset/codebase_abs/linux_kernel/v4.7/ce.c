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
struct V_43 * V_44 , V_45 ;
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
V_50 |= F_38 ( V_39 , V_56 ) ;
if ( V_40 & V_57 )
V_50 |= V_58 ;
if ( V_40 & V_59 )
V_50 |= V_60 ;
V_45 . V_8 = F_39 ( V_37 ) ;
V_45 . V_38 = F_40 ( V_38 ) ;
V_45 . V_40 = F_40 ( V_50 ) ;
* V_44 = V_45 ;
V_42 -> V_36 [ V_48 ] = V_36 ;
V_48 = F_41 ( V_46 , V_48 ) ;
if ( ! ( V_40 & V_57 ) )
F_5 ( V_2 , V_49 , V_48 ) ;
V_42 -> V_48 = V_48 ;
exit:
return V_51 ;
}
void F_42 ( struct V_34 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_62 * V_63 = F_43 ( V_2 ) ;
struct V_41 * V_42 = V_61 -> V_42 ;
T_1 V_49 = V_61 -> V_49 ;
F_44 ( & V_63 -> V_64 ) ;
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
struct V_62 * V_63 = F_43 ( V_2 ) ;
int V_51 ;
F_47 ( & V_63 -> V_64 ) ;
V_51 = F_33 ( V_35 , V_36 ,
V_37 , V_38 , V_39 , V_40 ) ;
F_48 ( & V_63 -> V_64 ) ;
return V_51 ;
}
int F_49 ( struct V_34 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_62 * V_63 = F_43 ( V_2 ) ;
int V_65 ;
F_47 ( & V_63 -> V_64 ) ;
V_65 = F_36 ( V_61 -> V_42 -> V_46 ,
V_61 -> V_42 -> V_48 ,
V_61 -> V_42 -> V_47 - 1 ) ;
F_48 ( & V_63 -> V_64 ) ;
return V_65 ;
}
int F_50 ( struct V_34 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_62 * V_63 = F_43 ( V_2 ) ;
struct V_41 * V_66 = V_61 -> V_66 ;
unsigned int V_46 = V_66 -> V_46 ;
unsigned int V_48 = V_66 -> V_48 ;
unsigned int V_47 = V_66 -> V_47 ;
F_44 ( & V_63 -> V_64 ) ;
return F_36 ( V_46 , V_48 , V_47 - 1 ) ;
}
int F_51 ( struct V_34 * V_61 , void * V_67 , T_1 V_68 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_62 * V_63 = F_43 ( V_2 ) ;
struct V_41 * V_66 = V_61 -> V_66 ;
unsigned int V_46 = V_66 -> V_46 ;
unsigned int V_48 = V_66 -> V_48 ;
unsigned int V_47 = V_66 -> V_47 ;
struct V_43 * V_69 = V_66 -> V_55 ;
struct V_43 * V_44 = F_52 ( V_69 , V_48 ) ;
T_1 V_49 = V_61 -> V_49 ;
F_44 ( & V_63 -> V_64 ) ;
if ( ( V_61 -> V_70 != 5 ) &&
F_36 ( V_46 , V_48 , V_47 - 1 ) == 0 )
return - V_71 ;
V_44 -> V_8 = F_39 ( V_68 ) ;
V_44 -> V_38 = 0 ;
V_66 -> V_36 [ V_48 ] = V_67 ;
V_48 = F_41 ( V_46 , V_48 ) ;
F_1 ( V_2 , V_49 , V_48 ) ;
V_66 -> V_48 = V_48 ;
return 0 ;
}
void F_53 ( struct V_34 * V_61 , T_1 V_72 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_41 * V_66 = V_61 -> V_66 ;
unsigned int V_46 = V_66 -> V_46 ;
unsigned int V_48 = V_66 -> V_48 ;
T_1 V_49 = V_61 -> V_49 ;
V_48 = F_54 ( V_46 , V_48 , V_72 ) ;
F_1 ( V_2 , V_49 , V_48 ) ;
V_66 -> V_48 = V_48 ;
}
int F_55 ( struct V_34 * V_61 , void * V_67 , T_1 V_68 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_62 * V_63 = F_43 ( V_2 ) ;
int V_51 ;
F_47 ( & V_63 -> V_64 ) ;
V_51 = F_51 ( V_61 , V_67 , V_68 ) ;
F_48 ( & V_63 -> V_64 ) ;
return V_51 ;
}
int F_56 ( struct V_34 * V_35 ,
void * * V_73 ,
unsigned int * V_74 )
{
struct V_41 * V_66 = V_35 -> V_66 ;
unsigned int V_46 = V_66 -> V_46 ;
unsigned int V_47 = V_66 -> V_47 ;
struct V_43 * V_69 = V_66 -> V_55 ;
struct V_43 * V_44 = F_52 ( V_69 , V_47 ) ;
struct V_43 V_45 ;
T_2 V_38 ;
V_45 = * V_44 ;
V_38 = F_57 ( V_45 . V_38 ) ;
if ( V_38 == 0 ) {
return - V_75 ;
}
V_44 -> V_38 = 0 ;
* V_74 = V_38 ;
if ( V_73 )
* V_73 =
V_66 -> V_36 [ V_47 ] ;
if ( V_35 -> V_70 != 5 )
V_66 -> V_36 [ V_47 ] = NULL ;
V_47 = F_41 ( V_46 , V_47 ) ;
V_66 -> V_47 = V_47 ;
return 0 ;
}
int F_58 ( struct V_34 * V_35 ,
void * * V_73 ,
unsigned int * V_74 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_62 * V_63 = F_43 ( V_2 ) ;
int V_51 ;
F_47 ( & V_63 -> V_64 ) ;
V_51 = F_56 ( V_35 ,
V_73 ,
V_74 ) ;
F_48 ( & V_63 -> V_64 ) ;
return V_51 ;
}
int F_59 ( struct V_34 * V_35 ,
void * * V_73 ,
T_1 * V_76 )
{
struct V_41 * V_66 ;
unsigned int V_46 ;
unsigned int V_47 ;
unsigned int V_48 ;
int V_51 ;
struct V_1 * V_2 ;
struct V_62 * V_63 ;
V_66 = V_35 -> V_66 ;
if ( ! V_66 )
return - V_75 ;
V_2 = V_35 -> V_2 ;
V_63 = F_43 ( V_2 ) ;
F_47 ( & V_63 -> V_64 ) ;
V_46 = V_66 -> V_46 ;
V_47 = V_66 -> V_47 ;
V_48 = V_66 -> V_48 ;
if ( V_48 != V_47 ) {
struct V_43 * V_69 = V_66 -> V_55 ;
struct V_43 * V_44 = F_52 ( V_69 , V_47 ) ;
* V_76 = F_60 ( V_44 -> V_8 ) ;
if ( V_73 )
* V_73 =
V_66 -> V_36 [ V_47 ] ;
V_66 -> V_36 [ V_47 ] = NULL ;
V_44 -> V_38 = 0 ;
V_47 = F_41 ( V_46 , V_47 ) ;
V_66 -> V_47 = V_47 ;
V_51 = 0 ;
} else {
V_51 = - V_75 ;
}
F_48 ( & V_63 -> V_64 ) ;
return V_51 ;
}
int F_61 ( struct V_34 * V_35 ,
void * * V_73 )
{
struct V_41 * V_42 = V_35 -> V_42 ;
T_1 V_49 = V_35 -> V_49 ;
struct V_1 * V_2 = V_35 -> V_2 ;
unsigned int V_46 = V_42 -> V_46 ;
unsigned int V_47 = V_42 -> V_47 ;
unsigned int V_77 ;
if ( V_42 -> V_78 == V_47 ) {
V_77 = F_7 ( V_2 , V_49 ) ;
if ( V_77 == 0xffffffff )
return - V_79 ;
V_77 &= V_46 ;
V_42 -> V_78 = V_77 ;
}
V_77 = V_42 -> V_78 ;
if ( V_77 == V_47 )
return - V_75 ;
if ( V_73 )
* V_73 =
V_42 -> V_36 [ V_47 ] ;
V_42 -> V_36 [ V_47 ] = NULL ;
V_47 = F_41 ( V_46 , V_47 ) ;
V_42 -> V_47 = V_47 ;
return 0 ;
}
int F_62 ( struct V_34 * V_35 ,
void * * V_73 ,
T_1 * V_76 ,
unsigned int * V_74 ,
unsigned int * V_80 )
{
struct V_41 * V_42 ;
unsigned int V_46 ;
unsigned int V_47 ;
unsigned int V_48 ;
int V_51 ;
struct V_1 * V_2 ;
struct V_62 * V_63 ;
V_42 = V_35 -> V_42 ;
if ( ! V_42 )
return - V_75 ;
V_2 = V_35 -> V_2 ;
V_63 = F_43 ( V_2 ) ;
F_47 ( & V_63 -> V_64 ) ;
V_46 = V_42 -> V_46 ;
V_47 = V_42 -> V_47 ;
V_48 = V_42 -> V_48 ;
if ( V_48 != V_47 ) {
struct V_43 * V_69 = V_42 -> V_55 ;
struct V_43 * V_44 = F_37 ( V_69 , V_47 ) ;
* V_76 = F_60 ( V_44 -> V_8 ) ;
* V_74 = F_57 ( V_44 -> V_38 ) ;
* V_80 = F_63 ( F_57 ( V_44 -> V_40 ) ,
V_56 ) ;
if ( V_73 )
* V_73 =
V_42 -> V_36 [ V_47 ] ;
V_42 -> V_36 [ V_47 ] = NULL ;
V_47 = F_41 ( V_46 , V_47 ) ;
V_42 -> V_47 = V_47 ;
V_51 = 0 ;
} else {
V_51 = - V_75 ;
}
F_48 ( & V_63 -> V_64 ) ;
return V_51 ;
}
int F_64 ( struct V_34 * V_35 ,
void * * V_73 )
{
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_62 * V_63 = F_43 ( V_2 ) ;
int V_51 ;
F_47 ( & V_63 -> V_64 ) ;
V_51 = F_61 ( V_35 ,
V_73 ) ;
F_48 ( & V_63 -> V_64 ) ;
return V_51 ;
}
void F_65 ( struct V_1 * V_2 , unsigned int V_81 )
{
struct V_62 * V_63 = F_43 ( V_2 ) ;
struct V_34 * V_35 = & V_63 -> V_82 [ V_81 ] ;
T_1 V_49 = V_35 -> V_49 ;
F_47 ( & V_63 -> V_64 ) ;
F_32 ( V_2 , V_49 ,
V_83 ) ;
F_48 ( & V_63 -> V_64 ) ;
if ( V_35 -> V_84 )
V_35 -> V_84 ( V_35 ) ;
if ( V_35 -> V_85 )
V_35 -> V_85 ( V_35 ) ;
F_47 ( & V_63 -> V_64 ) ;
F_32 ( V_2 , V_49 , V_28 ) ;
F_48 ( & V_63 -> V_64 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
int V_81 ;
T_1 V_86 ;
V_86 = F_67 ( V_2 ) ;
for ( V_81 = 0 ; V_86 && ( V_81 < V_87 ) ; V_81 ++ ) {
if ( V_86 & ( 1 << V_81 ) )
V_86 &= ~ ( 1 << V_81 ) ;
else
continue;
F_65 ( V_2 , V_81 ) ;
}
}
static void F_68 ( struct V_34 * V_35 )
{
T_1 V_49 = V_35 -> V_49 ;
struct V_1 * V_2 = V_35 -> V_2 ;
bool V_88 = V_35 -> V_89 & V_90 ;
if ( ( ! V_88 ) &&
( V_35 -> V_85 || V_35 -> V_84 ) )
F_27 ( V_2 , V_49 ) ;
else
F_28 ( V_2 , V_49 ) ;
F_29 ( V_2 , V_49 ) ;
}
int F_69 ( struct V_1 * V_2 )
{
int V_81 ;
for ( V_81 = 0 ; V_81 < V_87 ; V_81 ++ ) {
T_1 V_49 = F_70 ( V_2 , V_81 ) ;
F_28 ( V_2 , V_49 ) ;
F_31 ( V_2 , V_49 ) ;
F_29 ( V_2 , V_49 ) ;
}
return 0 ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_62 * V_63 = F_43 ( V_2 ) ;
int V_81 ;
for ( V_81 = 0 ; V_81 < V_87 - 1 ; V_81 ++ )
F_68 ( & V_63 -> V_82 [ V_81 ] ) ;
}
static int F_72 ( struct V_1 * V_2 ,
unsigned int V_81 ,
const struct V_91 * V_92 )
{
struct V_62 * V_63 = F_43 ( V_2 ) ;
struct V_34 * V_35 = & V_63 -> V_82 [ V_81 ] ;
struct V_41 * V_42 = V_35 -> V_42 ;
T_1 V_72 , V_49 = F_70 ( V_2 , V_81 ) ;
V_72 = F_73 ( V_92 -> V_93 ) ;
memset ( V_42 -> V_55 , 0 ,
V_72 * sizeof( struct V_43 ) ) ;
V_42 -> V_47 = F_7 ( V_2 , V_49 ) ;
V_42 -> V_47 &= V_42 -> V_46 ;
V_42 -> V_78 = V_42 -> V_47 ;
V_42 -> V_48 =
F_6 ( V_2 , V_49 ) ;
V_42 -> V_48 &= V_42 -> V_46 ;
F_8 ( V_2 , V_49 ,
V_42 -> V_94 ) ;
F_9 ( V_2 , V_49 , V_72 ) ;
F_10 ( V_2 , V_49 , V_92 -> V_52 ) ;
F_12 ( V_2 , V_49 , 0 ) ;
F_21 ( V_2 , V_49 , 0 ) ;
F_19 ( V_2 , V_49 , V_72 ) ;
F_74 ( V_2 , V_95 ,
L_2 ,
V_81 , V_72 , V_42 -> V_55 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
unsigned int V_81 ,
const struct V_91 * V_92 )
{
struct V_62 * V_63 = F_43 ( V_2 ) ;
struct V_34 * V_35 = & V_63 -> V_82 [ V_81 ] ;
struct V_41 * V_66 = V_35 -> V_66 ;
T_1 V_72 , V_49 = F_70 ( V_2 , V_81 ) ;
V_72 = F_73 ( V_92 -> V_96 ) ;
memset ( V_66 -> V_55 , 0 ,
V_72 * sizeof( struct V_43 ) ) ;
V_66 -> V_47 = F_16 ( V_2 , V_49 ) ;
V_66 -> V_47 &= V_66 -> V_46 ;
V_66 -> V_48 =
F_3 ( V_2 , V_49 ) ;
V_66 -> V_48 &= V_66 -> V_46 ;
F_17 ( V_2 , V_49 ,
V_66 -> V_94 ) ;
F_18 ( V_2 , V_49 , V_72 ) ;
F_14 ( V_2 , V_49 , 0 ) ;
F_25 ( V_2 , V_49 , 0 ) ;
F_23 ( V_2 , V_49 , V_72 ) ;
F_74 ( V_2 , V_95 ,
L_3 ,
V_81 , V_72 , V_66 -> V_55 ) ;
return 0 ;
}
static struct V_41 *
F_76 ( struct V_1 * V_2 , unsigned int V_81 ,
const struct V_91 * V_92 )
{
struct V_41 * V_42 ;
T_1 V_72 = V_92 -> V_93 ;
T_3 V_97 ;
V_72 = F_73 ( V_72 ) ;
V_42 = F_77 ( sizeof( * V_42 ) +
( V_72 *
sizeof( * V_42 -> V_36 ) ) ,
V_98 ) ;
if ( V_42 == NULL )
return F_78 ( - V_99 ) ;
V_42 -> V_72 = V_72 ;
V_42 -> V_46 = V_72 - 1 ;
V_42 -> V_100 =
F_79 ( V_2 -> V_101 ,
( V_72 * sizeof( struct V_43 ) +
V_102 ) ,
& V_97 , V_98 ) ;
if ( ! V_42 -> V_100 ) {
F_80 ( V_42 ) ;
return F_78 ( - V_99 ) ;
}
V_42 -> V_103 = V_97 ;
V_42 -> V_55 = F_81 (
V_42 -> V_100 ,
V_102 ) ;
V_42 -> V_94 = F_82 (
V_42 -> V_103 ,
V_102 ) ;
return V_42 ;
}
static struct V_41 *
F_83 ( struct V_1 * V_2 , unsigned int V_81 ,
const struct V_91 * V_92 )
{
struct V_41 * V_66 ;
T_1 V_72 ;
T_3 V_97 ;
V_72 = F_73 ( V_92 -> V_96 ) ;
V_66 = F_77 ( sizeof( * V_66 ) +
( V_72 *
sizeof( * V_66 -> V_36 ) ) ,
V_98 ) ;
if ( V_66 == NULL )
return F_78 ( - V_99 ) ;
V_66 -> V_72 = V_72 ;
V_66 -> V_46 = V_72 - 1 ;
V_66 -> V_100 =
F_79 ( V_2 -> V_101 ,
( V_72 * sizeof( struct V_43 ) +
V_102 ) ,
& V_97 , V_98 ) ;
if ( ! V_66 -> V_100 ) {
F_80 ( V_66 ) ;
return F_78 ( - V_99 ) ;
}
V_66 -> V_103 = V_97 ;
memset ( V_66 -> V_100 , 0 ,
V_72 * sizeof( struct V_43 ) + V_102 ) ;
V_66 -> V_55 = F_81 (
V_66 -> V_100 ,
V_102 ) ;
V_66 -> V_94 = F_82 (
V_66 -> V_103 ,
V_102 ) ;
return V_66 ;
}
int F_84 ( struct V_1 * V_2 , unsigned int V_81 ,
const struct V_91 * V_92 )
{
int V_51 ;
if ( V_92 -> V_93 ) {
V_51 = F_72 ( V_2 , V_81 , V_92 ) ;
if ( V_51 ) {
F_85 ( V_2 , L_4 ,
V_81 , V_51 ) ;
return V_51 ;
}
}
if ( V_92 -> V_96 ) {
V_51 = F_75 ( V_2 , V_81 , V_92 ) ;
if ( V_51 ) {
F_85 ( V_2 , L_5 ,
V_81 , V_51 ) ;
return V_51 ;
}
}
return 0 ;
}
static void F_86 ( struct V_1 * V_2 , unsigned int V_81 )
{
T_1 V_49 = F_70 ( V_2 , V_81 ) ;
F_8 ( V_2 , V_49 , 0 ) ;
F_9 ( V_2 , V_49 , 0 ) ;
F_10 ( V_2 , V_49 , 0 ) ;
F_19 ( V_2 , V_49 , 0 ) ;
}
static void F_87 ( struct V_1 * V_2 , unsigned int V_81 )
{
T_1 V_49 = F_70 ( V_2 , V_81 ) ;
F_17 ( V_2 , V_49 , 0 ) ;
F_18 ( V_2 , V_49 , 0 ) ;
F_23 ( V_2 , V_49 , 0 ) ;
}
void F_88 ( struct V_1 * V_2 , unsigned int V_81 )
{
F_86 ( V_2 , V_81 ) ;
F_87 ( V_2 , V_81 ) ;
}
int F_89 ( struct V_1 * V_2 , int V_81 ,
const struct V_91 * V_92 )
{
struct V_62 * V_63 = F_43 ( V_2 ) ;
struct V_34 * V_35 = & V_63 -> V_82 [ V_81 ] ;
int V_51 ;
F_90 ( 2 * V_104 >
( V_105 - 1 ) ) ;
F_90 ( 2 * V_106 >
( V_105 - 1 ) ) ;
F_90 ( 2 * V_107 >
( V_105 - 1 ) ) ;
V_35 -> V_2 = V_2 ;
V_35 -> V_70 = V_81 ;
V_35 -> V_49 = F_70 ( V_2 , V_81 ) ;
V_35 -> V_89 = V_92 -> V_40 ;
V_35 -> V_52 = V_92 -> V_52 ;
if ( V_92 -> V_93 )
V_35 -> V_85 = V_92 -> V_85 ;
if ( V_92 -> V_96 )
V_35 -> V_84 = V_92 -> V_84 ;
if ( V_92 -> V_93 ) {
V_35 -> V_42 = F_76 ( V_2 , V_81 , V_92 ) ;
if ( F_91 ( V_35 -> V_42 ) ) {
V_51 = F_92 ( V_35 -> V_42 ) ;
F_85 ( V_2 , L_6 ,
V_81 , V_51 ) ;
V_35 -> V_42 = NULL ;
return V_51 ;
}
}
if ( V_92 -> V_96 ) {
V_35 -> V_66 = F_83 ( V_2 , V_81 ,
V_92 ) ;
if ( F_91 ( V_35 -> V_66 ) ) {
V_51 = F_92 ( V_35 -> V_66 ) ;
F_85 ( V_2 , L_7 ,
V_81 , V_51 ) ;
V_35 -> V_66 = NULL ;
return V_51 ;
}
}
return 0 ;
}
void F_93 ( struct V_1 * V_2 , int V_81 )
{
struct V_62 * V_63 = F_43 ( V_2 ) ;
struct V_34 * V_35 = & V_63 -> V_82 [ V_81 ] ;
if ( V_35 -> V_42 ) {
F_94 ( V_2 -> V_101 ,
( V_35 -> V_42 -> V_72 *
sizeof( struct V_43 ) +
V_102 ) ,
V_35 -> V_42 -> V_55 ,
V_35 -> V_42 -> V_94 ) ;
F_80 ( V_35 -> V_42 ) ;
}
if ( V_35 -> V_66 ) {
F_94 ( V_2 -> V_101 ,
( V_35 -> V_66 -> V_72 *
sizeof( struct V_43 ) +
V_102 ) ,
V_35 -> V_66 -> V_55 ,
V_35 -> V_66 -> V_94 ) ;
F_80 ( V_35 -> V_66 ) ;
}
V_35 -> V_42 = NULL ;
V_35 -> V_66 = NULL ;
}
