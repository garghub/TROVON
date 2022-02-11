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
struct V_6 * V_7 = F_6 ( V_2 ) ;
void T_2 * V_8 ;
if ( ! F_7 ( V_9 , V_7 -> V_10 ) ) {
F_2 ( V_2 , V_3 + V_11 , V_4 ) ;
return;
}
V_8 = V_7 -> V_12 + V_3 + V_13 ;
if ( V_3 == F_8 ( V_14 ) ) {
F_9 ( ( V_15 | V_4 ) , V_8 ) ;
} else {
unsigned long V_16 ;
F_10 ( V_16 ) ;
F_9 ( 1 , V_8 ) ;
( void ) F_11 ( V_8 ) ;
( void ) F_11 ( V_8 ) ;
F_2 ( V_2 , V_3 + V_11 , V_4 ) ;
F_9 ( 0 , V_8 ) ;
F_12 ( V_16 ) ;
}
}
static inline T_1 F_13 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return F_4 ( V_2 , V_3 + V_11 ) ;
}
static inline T_1 F_14 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return F_4 ( V_2 , V_3 + V_17 ) ;
}
static inline void F_15 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_18 )
{
F_2 ( V_2 , V_3 + V_19 , V_18 ) ;
}
static inline void F_16 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
F_2 ( V_2 , V_3 + V_20 , V_4 ) ;
}
static inline void F_17 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
T_1 V_21 = F_4 ( ( V_2 ) ,
( V_3 ) + V_22 ) ;
F_2 ( V_2 , V_3 + V_22 ,
( V_21 & ~ V_23 ) |
F_18 ( V_4 ) ) ;
}
static inline void F_19 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
T_1 V_21 = F_4 ( V_2 , V_3 + V_22 ) ;
F_2 ( V_2 , V_3 + V_22 ,
( V_21 & ~ V_24 ) |
F_20 ( V_4 ) ) ;
}
static inline void F_21 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
T_1 V_21 = F_4 ( V_2 , V_3 + V_22 ) ;
F_2 ( V_2 , V_3 + V_22 ,
( V_21 & ~ V_25 ) |
F_22 ( V_4 ) ) ;
}
static inline T_1 F_23 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return F_4 ( V_2 , V_3 + V_26 ) ;
}
static inline void F_24 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_18 )
{
F_2 ( V_2 , V_3 + V_27 , V_18 ) ;
}
static inline void F_25 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
F_2 ( V_2 , V_3 + V_28 , V_4 ) ;
}
static inline void F_26 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
T_1 V_18 = F_4 ( V_2 , V_3 + V_29 ) ;
F_2 ( V_2 , V_3 + V_29 ,
( V_18 & ~ V_30 ) |
F_27 ( V_4 ) ) ;
}
static inline void F_28 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
T_1 V_18 = F_4 ( V_2 , V_3 + V_29 ) ;
F_2 ( V_2 , V_3 + V_29 ,
( V_18 & ~ V_31 ) |
F_29 ( V_4 ) ) ;
}
static inline void F_30 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
T_1 V_18 = F_4 ( V_2 , V_3 + V_13 ) ;
F_2 ( V_2 , V_3 + V_13 ,
( V_18 & ~ V_32 ) |
F_31 ( V_4 ) ) ;
}
static inline void F_32 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_4 )
{
T_1 V_18 = F_4 ( V_2 , V_3 + V_13 ) ;
F_2 ( V_2 , V_3 + V_13 ,
( V_18 & ~ V_33 ) |
F_33 ( V_4 ) ) ;
}
static inline void F_34 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_34 = F_4 ( V_2 ,
V_3 + V_35 ) ;
F_2 ( V_2 , V_3 + V_35 ,
V_34 | V_36 ) ;
}
static inline void F_35 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_34 = F_4 ( V_2 ,
V_3 + V_35 ) ;
F_2 ( V_2 , V_3 + V_35 ,
V_34 & ~ V_36 ) ;
}
static inline void F_36 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_34 = F_4 ( V_2 ,
V_3 + V_35 ) ;
F_2 ( V_2 , V_3 + V_35 ,
V_34 & ~ V_37 ) ;
}
static inline void F_37 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_38 = F_4 ( V_2 ,
V_3 + V_39 ) ;
F_2 ( V_2 , V_3 + V_39 ,
V_38 | V_40 ) ;
}
static inline void F_38 ( struct V_1 * V_2 ,
T_1 V_3 ,
unsigned int V_41 )
{
F_2 ( V_2 , V_3 + V_42 , V_41 ) ;
}
static int F_39 ( struct V_43 * V_43 ,
void * V_44 ,
T_1 V_45 ,
unsigned int V_46 ,
unsigned int V_47 ,
unsigned int V_48 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_49 * V_50 = V_43 -> V_50 ;
struct V_51 * V_52 , * V_53 ;
unsigned int V_54 = V_50 -> V_54 ;
unsigned int V_55 = V_50 -> V_55 ;
unsigned int V_56 = V_50 -> V_56 ;
T_1 V_57 = V_43 -> V_57 ;
T_1 V_58 = 0 ;
int V_59 = 0 ;
if ( V_46 > V_43 -> V_60 )
F_40 ( L_1 ,
V_61 , V_46 , V_43 -> V_60 ) ;
F_41 ( V_2 ) ;
if ( F_42 ( F_43 ( V_54 ,
V_56 , V_55 - 1 ) <= 0 ) ) {
V_59 = - V_62 ;
goto exit;
}
V_52 = F_44 ( V_50 -> V_63 ,
V_56 ) ;
V_53 = F_44 ( V_50 -> V_64 , V_56 ) ;
V_58 |= F_45 ( V_47 , V_65 ) ;
if ( V_48 & V_66 )
V_58 |= V_67 ;
if ( V_48 & V_68 )
V_58 |= V_69 ;
V_53 -> V_18 = F_46 ( V_45 ) ;
V_53 -> V_46 = F_47 ( V_46 ) ;
V_53 -> V_48 = F_47 ( V_58 ) ;
* V_52 = * V_53 ;
V_50 -> V_44 [ V_56 ] = V_44 ;
V_56 = F_48 ( V_54 , V_56 ) ;
if ( ! ( V_48 & V_66 ) )
F_5 ( V_2 , V_57 , V_56 ) ;
V_50 -> V_56 = V_56 ;
exit:
F_49 ( V_2 ) ;
return V_59 ;
}
int F_50 ( struct V_43 * V_43 ,
void * V_44 ,
T_1 V_45 ,
unsigned int V_46 ,
unsigned int V_47 ,
unsigned int V_48 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_6 * V_7 = F_6 ( V_2 ) ;
int V_59 ;
F_51 ( & V_7 -> V_70 ) ;
V_59 = F_39 ( V_43 , V_44 ,
V_45 , V_46 , V_47 , V_48 ) ;
F_52 ( & V_7 -> V_70 ) ;
return V_59 ;
}
void F_53 ( struct V_71 * V_72 , T_1 V_45 ,
unsigned int V_46 , T_1 V_48 )
{
unsigned int V_73 = V_72 -> V_73 ;
struct V_74 * V_75 ;
V_75 = & V_72 -> V_75 [ V_73 ] ;
V_75 -> V_76 = V_45 ;
V_75 -> V_77 . V_46 = V_46 ;
V_75 -> V_48 = V_48 ;
V_72 -> V_73 ++ ;
}
int F_54 ( struct V_43 * V_43 ,
void * V_44 ,
struct V_71 * V_72 ,
unsigned int V_47 )
{
struct V_49 * V_50 = V_43 -> V_50 ;
struct V_74 * V_75 ;
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_6 * V_7 = F_6 ( V_2 ) ;
unsigned int V_54 = V_50 -> V_54 ;
unsigned int V_73 = V_72 -> V_73 ;
unsigned int V_55 ;
unsigned int V_56 ;
int V_78 , V_79 , V_59 = - V_80 ;
F_51 ( & V_7 -> V_70 ) ;
V_55 = V_50 -> V_55 ;
V_56 = V_50 -> V_56 ;
V_79 = F_43 ( V_54 , V_56 , V_55 - 1 ) ;
if ( V_79 >= V_73 ) {
for ( V_78 = 0 ; V_78 < V_73 - 1 ; V_78 ++ ) {
V_75 = & V_72 -> V_75 [ V_78 ] ;
V_59 = F_39 ( V_43 ,
V_81 ,
( T_1 ) V_75 -> V_76 ,
V_75 -> V_77 . V_46 , V_47 ,
V_75 -> V_48 |
V_66 ) ;
if ( V_59 )
F_40 ( L_2 , V_78 ) ;
}
V_75 = & V_72 -> V_75 [ V_78 ] ;
V_59 = F_39 ( V_43 , V_44 ,
( T_1 ) V_75 -> V_76 , V_75 -> V_77 . V_46 ,
V_47 , V_75 -> V_48 ) ;
if ( V_59 )
F_40 ( L_3 , V_78 ) ;
}
F_52 ( & V_7 -> V_70 ) ;
return V_59 ;
}
int F_55 ( struct V_43 * V_43 ,
void * V_82 ,
T_1 V_45 )
{
struct V_49 * V_83 = V_43 -> V_83 ;
T_1 V_57 = V_43 -> V_57 ;
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_6 * V_7 = F_6 ( V_2 ) ;
unsigned int V_54 = V_83 -> V_54 ;
unsigned int V_56 ;
unsigned int V_55 ;
int V_59 ;
F_51 ( & V_7 -> V_70 ) ;
V_56 = V_83 -> V_56 ;
V_55 = V_83 -> V_55 ;
F_41 ( V_2 ) ;
if ( F_43 ( V_54 , V_56 , V_55 - 1 ) > 0 ) {
struct V_51 * V_84 = V_83 -> V_63 ;
struct V_51 * V_52 = F_56 ( V_84 , V_56 ) ;
V_52 -> V_18 = F_46 ( V_45 ) ;
V_52 -> V_46 = 0 ;
V_83 -> V_44 [ V_56 ] =
V_82 ;
V_56 = F_48 ( V_54 , V_56 ) ;
F_1 ( V_2 , V_57 , V_56 ) ;
V_83 -> V_56 = V_56 ;
V_59 = 0 ;
} else {
V_59 = - V_62 ;
}
F_49 ( V_2 ) ;
F_52 ( & V_7 -> V_70 ) ;
return V_59 ;
}
static int F_57 ( struct V_43 * V_43 ,
void * * V_85 ,
T_1 * V_86 ,
unsigned int * V_87 ,
unsigned int * V_88 ,
unsigned int * V_89 )
{
struct V_49 * V_83 = V_43 -> V_83 ;
unsigned int V_54 = V_83 -> V_54 ;
unsigned int V_55 = V_83 -> V_55 ;
struct V_51 * V_84 = V_83 -> V_63 ;
struct V_51 * V_52 = F_56 ( V_84 , V_55 ) ;
struct V_51 V_53 ;
T_3 V_46 ;
V_53 = * V_52 ;
V_46 = F_58 ( V_53 . V_46 ) ;
if ( V_46 == 0 ) {
return - V_62 ;
}
V_52 -> V_46 = 0 ;
* V_86 = F_59 ( V_53 . V_18 ) ;
* V_87 = V_46 ;
* V_88 = F_60 ( F_58 ( V_53 . V_48 ) , V_65 ) ;
if ( F_58 ( V_53 . V_48 ) & V_69 )
* V_89 = V_90 ;
else
* V_89 = 0 ;
if ( V_85 )
* V_85 =
V_83 -> V_44 [ V_55 ] ;
V_83 -> V_44 [ V_55 ] = NULL ;
V_55 = F_48 ( V_54 , V_55 ) ;
V_83 -> V_55 = V_55 ;
return 0 ;
}
int F_61 ( struct V_43 * V_43 ,
void * * V_85 ,
T_1 * V_86 ,
unsigned int * V_87 ,
unsigned int * V_88 ,
unsigned int * V_89 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_6 * V_7 = F_6 ( V_2 ) ;
int V_59 ;
F_51 ( & V_7 -> V_70 ) ;
V_59 = F_57 ( V_43 ,
V_85 ,
V_86 , V_87 ,
V_88 , V_89 ) ;
F_52 ( & V_7 -> V_70 ) ;
return V_59 ;
}
int F_62 ( struct V_43 * V_43 ,
void * * V_85 ,
T_1 * V_86 )
{
struct V_49 * V_83 ;
unsigned int V_54 ;
unsigned int V_55 ;
unsigned int V_56 ;
int V_59 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_83 = V_43 -> V_83 ;
if ( ! V_83 )
return - V_62 ;
V_2 = V_43 -> V_2 ;
V_7 = F_6 ( V_2 ) ;
F_51 ( & V_7 -> V_70 ) ;
V_54 = V_83 -> V_54 ;
V_55 = V_83 -> V_55 ;
V_56 = V_83 -> V_56 ;
if ( V_56 != V_55 ) {
struct V_51 * V_84 = V_83 -> V_63 ;
struct V_51 * V_52 = F_56 ( V_84 , V_55 ) ;
* V_86 = F_59 ( V_52 -> V_18 ) ;
if ( V_85 )
* V_85 =
V_83 -> V_44 [ V_55 ] ;
V_83 -> V_44 [ V_55 ] = NULL ;
V_55 = F_48 ( V_54 , V_55 ) ;
V_83 -> V_55 = V_55 ;
V_59 = 0 ;
} else {
V_59 = - V_62 ;
}
F_52 ( & V_7 -> V_70 ) ;
return V_59 ;
}
static int F_63 ( struct V_43 * V_43 ,
void * * V_85 ,
T_1 * V_86 ,
unsigned int * V_87 ,
unsigned int * V_88 )
{
struct V_49 * V_50 = V_43 -> V_50 ;
T_1 V_57 = V_43 -> V_57 ;
struct V_1 * V_2 = V_43 -> V_2 ;
unsigned int V_54 = V_50 -> V_54 ;
unsigned int V_55 = V_50 -> V_55 ;
unsigned int V_91 ;
int V_59 = - V_62 ;
if ( V_50 -> V_92 == V_55 ) {
F_41 ( V_2 ) ;
V_50 -> V_92 =
F_14 ( V_2 , V_57 ) ;
V_50 -> V_92 &= V_54 ;
F_49 ( V_2 ) ;
}
V_91 = V_50 -> V_92 ;
if ( ( V_91 != V_55 ) && ( V_91 != 0xffffffff ) ) {
struct V_51 * V_93 = V_50 -> V_64 ;
struct V_51 * V_53 = F_44 ( V_93 , V_55 ) ;
* V_86 = F_59 ( V_53 -> V_18 ) ;
* V_87 = F_58 ( V_53 -> V_46 ) ;
* V_88 = F_60 ( F_58 ( V_53 -> V_48 ) ,
V_65 ) ;
if ( V_85 )
* V_85 =
V_50 -> V_44 [ V_55 ] ;
V_50 -> V_44 [ V_55 ] = NULL ;
V_55 = F_48 ( V_54 , V_55 ) ;
V_50 -> V_55 = V_55 ;
V_59 = 0 ;
}
return V_59 ;
}
int F_64 ( struct V_43 * V_43 ,
void * * V_85 ,
T_1 * V_86 ,
unsigned int * V_87 ,
unsigned int * V_88 )
{
struct V_49 * V_50 ;
unsigned int V_54 ;
unsigned int V_55 ;
unsigned int V_56 ;
int V_59 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_50 = V_43 -> V_50 ;
if ( ! V_50 )
return - V_62 ;
V_2 = V_43 -> V_2 ;
V_7 = F_6 ( V_2 ) ;
F_51 ( & V_7 -> V_70 ) ;
V_54 = V_50 -> V_54 ;
V_55 = V_50 -> V_55 ;
V_56 = V_50 -> V_56 ;
if ( V_56 != V_55 ) {
struct V_51 * V_84 = V_50 -> V_63 ;
struct V_51 * V_52 = F_44 ( V_84 , V_55 ) ;
* V_86 = F_59 ( V_52 -> V_18 ) ;
* V_87 = F_58 ( V_52 -> V_46 ) ;
* V_88 = F_60 ( F_58 ( V_52 -> V_48 ) ,
V_65 ) ;
if ( V_85 )
* V_85 =
V_50 -> V_44 [ V_55 ] ;
V_50 -> V_44 [ V_55 ] = NULL ;
V_55 = F_48 ( V_54 , V_55 ) ;
V_50 -> V_55 = V_55 ;
V_59 = 0 ;
} else {
V_59 = - V_62 ;
}
F_52 ( & V_7 -> V_70 ) ;
return V_59 ;
}
int F_65 ( struct V_43 * V_43 ,
void * * V_85 ,
T_1 * V_86 ,
unsigned int * V_87 ,
unsigned int * V_88 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_6 * V_7 = F_6 ( V_2 ) ;
int V_59 ;
F_51 ( & V_7 -> V_70 ) ;
V_59 = F_63 ( V_43 ,
V_85 ,
V_86 , V_87 ,
V_88 ) ;
F_52 ( & V_7 -> V_70 ) ;
return V_59 ;
}
void F_66 ( struct V_1 * V_2 , unsigned int V_94 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
struct V_43 * V_43 = V_7 -> V_95 [ V_94 ] ;
T_1 V_57 = V_43 -> V_57 ;
void * V_96 ;
T_1 V_97 ;
unsigned int V_46 ;
unsigned int V_98 ;
unsigned int V_48 ;
F_41 ( V_2 ) ;
F_51 ( & V_7 -> V_70 ) ;
F_38 ( V_2 , V_57 ,
V_99 ) ;
if ( V_43 -> V_100 ) {
while ( F_57 ( V_43 ,
& V_96 ,
& V_97 , & V_46 ,
& V_98 , & V_48 ) == 0 ) {
F_52 ( & V_7 -> V_70 ) ;
V_43 -> V_100 ( V_43 , V_96 , V_97 ,
V_46 , V_98 , V_48 ) ;
F_51 ( & V_7 -> V_70 ) ;
}
}
if ( V_43 -> V_101 ) {
while ( F_63 ( V_43 ,
& V_96 ,
& V_97 ,
& V_46 ,
& V_98 ) == 0 ) {
F_52 ( & V_7 -> V_70 ) ;
V_43 -> V_101 ( V_43 , V_96 ,
V_97 , V_46 , V_98 ) ;
F_51 ( & V_7 -> V_70 ) ;
}
}
F_38 ( V_2 , V_57 , V_37 ) ;
F_52 ( & V_7 -> V_70 ) ;
F_49 ( V_2 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
int V_94 ;
T_1 V_102 ;
F_41 ( V_2 ) ;
V_102 = F_68 ( V_2 ) ;
for ( V_94 = 0 ; V_102 && ( V_94 < V_7 -> V_103 ) ; V_94 ++ ) {
if ( V_102 & ( 1 << V_94 ) )
V_102 &= ~ ( 1 << V_94 ) ;
else
continue;
F_66 ( V_2 , V_94 ) ;
}
F_49 ( V_2 ) ;
}
static void F_69 ( struct V_43 * V_43 ,
int V_104 )
{
T_1 V_57 = V_43 -> V_57 ;
struct V_1 * V_2 = V_43 -> V_2 ;
F_41 ( V_2 ) ;
if ( ( ! V_104 ) &&
( V_43 -> V_101 || V_43 -> V_100 ) )
F_34 ( V_2 , V_57 ) ;
else
F_35 ( V_2 , V_57 ) ;
F_36 ( V_2 , V_57 ) ;
F_49 ( V_2 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
int V_94 ;
F_41 ( V_2 ) ;
for ( V_94 = 0 ; V_94 < V_7 -> V_103 ; V_94 ++ ) {
struct V_43 * V_43 = V_7 -> V_95 [ V_94 ] ;
T_1 V_57 = V_43 -> V_57 ;
F_35 ( V_2 , V_57 ) ;
}
F_49 ( V_2 ) ;
}
void F_71 ( struct V_43 * V_43 ,
void (* V_101) ( struct V_43 * V_43 ,
void * V_96 ,
T_1 V_45 ,
unsigned int V_46 ,
unsigned int V_47 ) ,
int V_105 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_6 * V_7 = F_6 ( V_2 ) ;
F_51 ( & V_7 -> V_70 ) ;
V_43 -> V_101 = V_101 ;
F_69 ( V_43 , V_105 ) ;
F_52 ( & V_7 -> V_70 ) ;
}
void F_72 ( struct V_43 * V_43 ,
void (* V_100) ( struct V_43 * V_43 ,
void * V_96 ,
T_1 V_45 ,
unsigned int V_46 ,
unsigned int V_47 ,
unsigned int V_48 ) )
{
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_6 * V_7 = F_6 ( V_2 ) ;
F_51 ( & V_7 -> V_70 ) ;
V_43 -> V_100 = V_100 ;
F_69 ( V_43 , 0 ) ;
F_52 ( & V_7 -> V_70 ) ;
}
static int F_73 ( struct V_1 * V_2 ,
unsigned int V_94 ,
struct V_43 * V_43 ,
const struct V_106 * V_107 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
struct V_49 * V_50 ;
unsigned int V_108 = V_107 -> V_109 ;
unsigned int V_110 ;
T_1 V_57 = F_8 ( V_94 ) ;
T_4 V_111 ;
char * V_112 ;
V_108 = F_74 ( V_108 ) ;
if ( V_43 -> V_50 ) {
F_75 ( V_43 -> V_50 -> V_108 != V_108 ) ;
return 0 ;
}
V_110 = sizeof( struct V_49 ) + ( V_108 * sizeof( void * ) ) ;
V_112 = F_76 ( V_110 , V_113 ) ;
if ( V_112 == NULL )
return - V_80 ;
V_43 -> V_50 = (struct V_49 * ) V_112 ;
V_50 = V_43 -> V_50 ;
V_112 += sizeof( struct V_49 ) ;
V_50 -> V_108 = V_108 ;
V_50 -> V_54 = V_108 - 1 ;
F_41 ( V_2 ) ;
V_50 -> V_55 = F_14 ( V_2 , V_57 ) ;
V_50 -> V_55 &= V_50 -> V_54 ;
V_50 -> V_92 = V_50 -> V_55 ;
V_50 -> V_56 =
F_13 ( V_2 , V_57 ) ;
V_50 -> V_56 &= V_50 -> V_54 ;
F_49 ( V_2 ) ;
V_50 -> V_44 = ( void * * ) V_112 ;
V_50 -> V_114 =
F_77 ( V_7 -> V_115 ,
( V_108 * sizeof( struct V_51 ) +
V_116 ) ,
& V_111 ) ;
V_50 -> V_117 = V_111 ;
V_50 -> V_63 = F_78 (
V_50 -> V_114 ,
V_116 ) ;
V_50 -> V_118 = F_79 (
V_50 -> V_117 ,
V_116 ) ;
V_50 -> V_119 =
F_80 ( ( V_108 * sizeof( struct V_51 ) +
V_116 ) , V_113 ) ;
V_50 -> V_64 = F_78 (
V_50 -> V_119 ,
V_116 ) ;
F_41 ( V_2 ) ;
F_15 ( V_2 , V_57 ,
V_50 -> V_118 ) ;
F_16 ( V_2 , V_57 , V_108 ) ;
F_17 ( V_2 , V_57 , V_107 -> V_60 ) ;
F_19 ( V_2 , V_57 , 0 ) ;
F_28 ( V_2 , V_57 , 0 ) ;
F_26 ( V_2 , V_57 , V_108 ) ;
F_49 ( V_2 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
unsigned int V_94 ,
struct V_43 * V_43 ,
const struct V_106 * V_107 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
struct V_49 * V_83 ;
unsigned int V_108 = V_107 -> V_120 ;
unsigned int V_110 ;
T_1 V_57 = F_8 ( V_94 ) ;
T_4 V_111 ;
char * V_112 ;
V_108 = F_74 ( V_108 ) ;
if ( V_43 -> V_83 ) {
F_75 ( V_43 -> V_83 -> V_108 != V_108 ) ;
return 0 ;
}
V_110 = sizeof( struct V_49 ) + ( V_108 * sizeof( void * ) ) ;
V_112 = F_76 ( V_110 , V_113 ) ;
if ( V_112 == NULL )
return - V_80 ;
V_43 -> V_83 = (struct V_49 * ) V_112 ;
V_83 = V_43 -> V_83 ;
V_112 += sizeof( struct V_49 ) ;
V_83 -> V_108 = V_108 ;
V_83 -> V_54 = V_108 - 1 ;
F_41 ( V_2 ) ;
V_83 -> V_55 = F_23 ( V_2 , V_57 ) ;
V_83 -> V_55 &= V_83 -> V_54 ;
V_83 -> V_56 =
F_3 ( V_2 , V_57 ) ;
V_83 -> V_56 &= V_83 -> V_54 ;
F_49 ( V_2 ) ;
V_83 -> V_44 = ( void * * ) V_112 ;
V_83 -> V_114 =
F_77 ( V_7 -> V_115 ,
( V_108 * sizeof( struct V_51 ) +
V_116 ) ,
& V_111 ) ;
V_83 -> V_117 = V_111 ;
memset ( V_83 -> V_114 , 0 ,
V_108 * sizeof( struct V_51 ) + V_116 ) ;
V_83 -> V_63 = F_78 (
V_83 -> V_114 ,
V_116 ) ;
V_83 -> V_118 = F_79 (
V_83 -> V_117 ,
V_116 ) ;
F_41 ( V_2 ) ;
F_24 ( V_2 , V_57 ,
V_83 -> V_118 ) ;
F_25 ( V_2 , V_57 , V_108 ) ;
F_21 ( V_2 , V_57 , 0 ) ;
F_32 ( V_2 , V_57 , 0 ) ;
F_30 ( V_2 , V_57 , V_108 ) ;
F_49 ( V_2 ) ;
return 0 ;
}
static struct V_43 * F_82 ( struct V_1 * V_2 ,
unsigned int V_94 ,
const struct V_106 * V_107 )
{
struct V_6 * V_7 = F_6 ( V_2 ) ;
struct V_43 * V_43 = NULL ;
T_1 V_57 = F_8 ( V_94 ) ;
F_51 ( & V_7 -> V_70 ) ;
if ( ! V_7 -> V_95 [ V_94 ] ) {
V_43 = F_76 ( sizeof( * V_43 ) , V_121 ) ;
if ( V_43 == NULL ) {
F_52 ( & V_7 -> V_70 ) ;
return NULL ;
}
V_7 -> V_95 [ V_94 ] = V_43 ;
V_43 -> V_2 = V_2 ;
V_43 -> V_98 = V_94 ;
V_43 -> V_57 = V_57 ;
V_43 -> V_122 = V_123 ;
V_43 -> V_124 = V_107 -> V_48 ;
V_43 -> V_60 = V_107 -> V_60 ;
}
F_52 ( & V_7 -> V_70 ) ;
return V_43 ;
}
struct V_43 * F_83 ( struct V_1 * V_2 ,
unsigned int V_94 ,
const struct V_106 * V_107 )
{
struct V_43 * V_43 ;
T_1 V_57 = F_8 ( V_94 ) ;
V_43 = F_82 ( V_2 , V_94 , V_107 ) ;
if ( ! V_43 ) {
F_84 ( L_4 , V_94 ) ;
return NULL ;
}
if ( V_107 -> V_109 ) {
if ( F_73 ( V_2 , V_94 , V_43 , V_107 ) ) {
F_84 ( L_5 ,
V_94 ) ;
F_85 ( V_43 ) ;
return NULL ;
}
}
if ( V_107 -> V_120 ) {
if ( F_81 ( V_2 , V_94 , V_43 , V_107 ) ) {
F_84 ( L_6 ,
V_94 ) ;
F_85 ( V_43 ) ;
return NULL ;
}
}
F_41 ( V_2 ) ;
F_37 ( V_2 , V_57 ) ;
F_49 ( V_2 ) ;
return V_43 ;
}
void F_85 ( struct V_43 * V_43 )
{
unsigned int V_94 = V_43 -> V_98 ;
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_6 * V_7 = F_6 ( V_2 ) ;
V_43 -> V_122 = V_125 ;
V_7 -> V_95 [ V_94 ] = NULL ;
if ( V_43 -> V_50 ) {
F_86 ( V_43 -> V_50 -> V_119 ) ;
F_87 ( V_7 -> V_115 ,
( V_43 -> V_50 -> V_108 *
sizeof( struct V_51 ) +
V_116 ) ,
V_43 -> V_50 -> V_63 ,
V_43 -> V_50 -> V_118 ) ;
F_86 ( V_43 -> V_50 ) ;
}
if ( V_43 -> V_83 ) {
F_87 ( V_7 -> V_115 ,
( V_43 -> V_83 -> V_108 *
sizeof( struct V_51 ) +
V_116 ) ,
V_43 -> V_83 -> V_63 ,
V_43 -> V_83 -> V_118 ) ;
F_86 ( V_43 -> V_83 ) ;
}
F_86 ( V_43 ) ;
}
