static inline T_1 F_1 ( int V_1 , int V_2 , int V_3 )
{
T_1 V_4 ;
V_4 = V_5 [ V_2 & 3 ] [ V_1 & 3 ] ;
F_2 ( V_4 == 0xf ) ;
V_4 <<= ( V_3 ) ? 20 : 4 ;
return V_4 ;
}
static inline T_1 F_3 ( struct V_6 * V_7 , unsigned int V_8 ,
int V_1 )
{
T_1 V_9 ;
if ( ! V_7 -> V_10 ) {
V_9 = ( 1 << F_4 ( V_8 ) ) | ( F_5 ( V_8 ) << 8 ) |
( V_1 & ~ 3 ) ;
} else {
V_9 = ( V_7 -> V_10 << 16 ) | ( F_4 ( V_8 ) << 11 ) |
( F_5 ( V_8 ) << 8 ) | ( V_1 & ~ 3 ) | 1 ;
}
return V_9 ;
}
static inline struct V_11 *
F_6 ( struct V_6 * V_7 )
{
struct V_12 * V_13 ;
V_13 = (struct V_12 * ) V_7 -> V_14 ;
return F_7 ( V_13 , struct V_11 , V_15 ) ;
}
static int F_8 ( struct V_11 * V_16 , int V_17 )
{
void T_2 * V_18 = V_16 -> V_19 ;
T_1 V_20 ;
T_1 V_21 ;
V_20 = F_9 ( V_18 + V_22 ) & 3 ;
if ( V_20 ) {
if ( ! V_17 ) {
T_1 V_23 ;
V_23 = F_9 ( V_18 + V_24 ) ;
F_10 ( L_1 ,
L_2 , V_20 , V_23 ) ;
}
F_11 ( V_20 , V_18 + V_22 ) ;
}
V_21 = F_9 ( V_18 + V_25 ) & 1 ;
if ( V_21 ) {
if ( ! V_17 ) {
T_1 V_23 ;
V_23 = F_9 ( V_18 + V_26 ) ;
F_10 ( L_1 ,
L_3 , V_21 , V_23 ) ;
}
F_11 ( V_21 , V_18 + V_25 ) ;
}
return ! ! ( V_21 | V_20 ) ;
}
static inline void F_12 ( struct V_11 * V_16 ,
int V_1 , int V_2 , T_1 V_27 )
{
void T_2 * V_18 = V_16 -> V_19 ;
T_1 V_28 ;
V_27 = V_27 << ( 8 * ( V_1 & 3 ) ) ;
V_28 = V_29 | ( V_1 & ~ 3 ) ;
V_28 |= F_1 ( V_1 , V_2 , 1 ) ;
F_11 ( V_28 , V_18 + V_30 ) ;
F_11 ( V_27 , V_18 + V_31 ) ;
}
static inline int F_13 ( struct V_6 * V_7 ,
unsigned int V_8 ,
int V_1 , int V_2 , T_1 V_32 )
{
struct V_11 * V_16 = F_6 ( V_7 ) ;
void T_2 * V_18 = V_16 -> V_19 ;
T_1 V_23 ;
V_23 = F_3 ( V_7 , V_8 , V_1 ) ;
F_11 ( V_23 , V_18 + V_33 ) ;
F_11 ( V_32 | F_1 ( V_1 , V_2 , 0 ) ,
V_18 + V_34 ) ;
return F_8 ( V_16 , 1 ) ;
}
static int F_14 ( struct V_6 * V_7 , unsigned int V_8 ,
int V_1 , int V_2 , T_1 * V_27 )
{
struct V_11 * V_16 = F_6 ( V_7 ) ;
void T_2 * V_18 = V_16 -> V_19 ;
T_1 V_35 ;
int V_36 ;
int V_9 ;
V_9 = V_37 ;
V_35 = ~ 0 ;
V_36 = F_13 ( V_7 , V_8 , V_1 , V_2 ,
V_38 ) ;
if ( V_36 )
V_9 = V_39 ;
else
V_35 = F_9 ( V_18 + V_40 ) ;
* V_27 = ( V_35 >> ( 8 * ( V_1 & 3 ) ) ) & V_41 [ V_2 & 7 ] ;
return V_9 ;
}
static int F_15 ( struct V_6 * V_7 , unsigned int V_8 ,
int V_1 , int V_2 , T_1 V_27 )
{
struct V_11 * V_16 = F_6 ( V_7 ) ;
void T_2 * V_18 = V_16 -> V_19 ;
int V_36 ;
int V_9 ;
V_27 = V_27 << ( 8 * ( V_1 & 3 ) ) ;
V_9 = V_37 ;
V_36 = F_13 ( V_7 , V_8 , V_1 , V_2 ,
V_42 ) ;
if ( V_36 )
V_9 = V_39 ;
else
F_11 ( V_27 , V_18 + V_43 ) ;
return V_9 ;
}
static void F_16 ( unsigned int V_44 , struct V_45 * V_46 )
{
struct V_11 * V_16 ;
void T_2 * V_18 = V_47 ;
T_1 V_48 ;
V_16 = F_17 ( V_44 ) ;
V_48 = F_9 ( V_18 + V_49 ) &
F_9 ( V_18 + V_50 ) ;
if ( V_48 & V_51 )
F_18 ( V_16 -> V_52 + 0 ) ;
else if ( V_48 & V_53 )
F_18 ( V_16 -> V_52 + 1 ) ;
else if ( V_48 & V_54 )
F_18 ( V_16 -> V_52 + 2 ) ;
else if ( V_48 & V_55 )
F_18 ( V_16 -> V_52 + 4 ) ;
else
F_19 () ;
}
static void F_20 ( struct V_56 * V_57 )
{
struct V_11 * V_16 ;
unsigned int V_44 ;
void T_2 * V_18 = V_47 ;
T_1 V_4 ;
V_16 = F_21 ( V_57 ) ;
V_44 = V_57 -> V_44 - V_16 -> V_52 ;
V_4 = F_9 ( V_18 + V_50 ) ;
F_11 ( V_4 | ( 1 << V_44 ) , V_18 + V_50 ) ;
F_9 ( V_18 + V_50 ) ;
}
static void F_22 ( struct V_56 * V_57 )
{
struct V_11 * V_16 ;
unsigned int V_44 ;
void T_2 * V_18 = V_47 ;
T_1 V_4 ;
V_16 = F_21 ( V_57 ) ;
V_44 = V_57 -> V_44 - V_16 -> V_52 ;
V_4 = F_9 ( V_18 + V_50 ) ;
F_11 ( V_4 & ~ ( 1 << V_44 ) , V_18 + V_50 ) ;
F_9 ( V_18 + V_50 ) ;
}
static void F_23 ( struct V_11 * V_16 )
{
void T_2 * V_18 = V_47 ;
int V_58 ;
F_11 ( 0 , V_18 + V_50 ) ;
F_11 ( 0 , V_18 + V_49 ) ;
F_24 ( V_59 < V_60 ) ;
V_16 -> V_52 = V_61 ;
for ( V_58 = V_16 -> V_52 ;
V_58 < V_16 -> V_52 + V_60 ; V_58 ++ ) {
F_25 ( V_58 , & V_62 ,
V_63 ) ;
F_26 ( V_58 , V_16 ) ;
}
F_27 ( V_16 -> V_44 , V_16 ) ;
F_28 ( V_16 -> V_44 , F_16 ) ;
}
static void F_29 ( void )
{
void T_2 * V_64 = V_65 ;
F_30 ( V_66 | V_67 ) ;
F_31 ( 100 ) ;
F_32 ( V_66 | V_67 ) ;
F_31 ( 100 ) ;
F_11 ( V_68 , V_64 + V_69 ) ;
F_11 ( V_70 , V_64 + V_71 ) ;
F_11 ( V_72 , V_64 + V_73 ) ;
F_11 ( V_74 , V_64 + V_75 ) ;
F_11 ( V_76 , V_64 + V_77 ) ;
F_11 ( V_78 , V_64 + V_79 ) ;
F_11 ( V_80 , V_64 + V_81 ) ;
F_11 ( V_82 , V_64 + V_83 ) ;
F_31 ( 100 ) ;
}
static int F_33 ( struct V_84 * V_85 )
{
struct V_11 * V_16 ;
struct V_86 * V_87 ;
T_1 V_4 ;
V_16 = F_34 ( & V_85 -> V_88 , sizeof( struct V_11 ) ,
V_89 ) ;
if ( ! V_16 )
return - V_90 ;
V_87 = F_35 ( V_85 , V_91 , L_4 ) ;
V_16 -> V_19 = F_36 ( & V_85 -> V_88 , V_87 ) ;
if ( F_37 ( V_16 -> V_19 ) )
return F_38 ( V_16 -> V_19 ) ;
V_16 -> V_44 = F_39 ( V_85 , 0 ) ;
if ( V_16 -> V_44 < 0 )
return - V_92 ;
V_87 = F_35 ( V_85 , V_93 , L_5 ) ;
if ( ! V_87 )
return - V_92 ;
V_16 -> V_94 . V_95 = V_87 ;
V_16 -> V_94 . V_96 = L_6 ;
V_16 -> V_94 . V_97 = V_87 -> V_97 ;
V_16 -> V_94 . V_98 = V_87 -> V_98 ;
V_16 -> V_94 . V_99 = V_93 ;
V_87 = F_35 ( V_85 , V_91 , L_7 ) ;
if ( ! V_87 )
return - V_92 ;
V_16 -> V_100 . V_95 = V_87 ;
V_16 -> V_100 . V_96 = L_8 ;
V_16 -> V_100 . V_97 = V_87 -> V_97 ;
V_16 -> V_100 . V_98 = V_87 -> V_98 ;
V_16 -> V_100 . V_99 = V_91 ;
F_29 () ;
V_4 = V_101 | V_102 | V_103
| V_104 | V_105 | V_106 ;
F_12 ( V_16 , V_107 , 4 , V_4 ) ;
F_8 ( V_16 , 1 ) ;
F_23 ( V_16 ) ;
V_16 -> V_15 . V_108 = & V_109 ;
V_16 -> V_15 . V_110 = & V_16 -> V_100 ;
V_16 -> V_15 . V_111 = & V_16 -> V_94 ;
F_40 ( & V_16 -> V_15 ) ;
return 0 ;
}
static int T_3 F_41 ( void )
{
return F_42 ( & V_112 ) ;
}
