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
unsigned long V_35 ;
T_1 V_36 ;
int V_37 ;
int V_9 ;
V_9 = V_38 ;
V_36 = ~ 0 ;
F_15 ( & V_16 -> V_39 , V_35 ) ;
V_37 = F_13 ( V_7 , V_8 , V_1 , V_2 ,
V_40 ) ;
if ( V_37 )
V_9 = V_41 ;
else
V_36 = F_9 ( V_18 + V_42 ) ;
F_16 ( & V_16 -> V_39 , V_35 ) ;
* V_27 = ( V_36 >> ( 8 * ( V_1 & 3 ) ) ) & V_43 [ V_2 & 7 ] ;
return V_9 ;
}
static int F_17 ( struct V_6 * V_7 , unsigned int V_8 ,
int V_1 , int V_2 , T_1 V_27 )
{
struct V_11 * V_16 = F_6 ( V_7 ) ;
void T_2 * V_18 = V_16 -> V_19 ;
unsigned long V_35 ;
int V_37 ;
int V_9 ;
V_27 = V_27 << ( 8 * ( V_1 & 3 ) ) ;
V_9 = V_38 ;
F_15 ( & V_16 -> V_39 , V_35 ) ;
V_37 = F_13 ( V_7 , V_8 , V_1 , V_2 ,
V_44 ) ;
if ( V_37 )
V_9 = V_41 ;
else
F_11 ( V_27 , V_18 + V_45 ) ;
F_16 ( & V_16 -> V_39 , V_35 ) ;
return V_9 ;
}
static void F_18 ( unsigned int V_46 , struct V_47 * V_48 )
{
struct V_11 * V_16 ;
void T_2 * V_18 = V_49 ;
T_1 V_50 ;
V_16 = F_19 ( V_46 ) ;
V_50 = F_9 ( V_18 + V_51 ) &
F_9 ( V_18 + V_52 ) ;
if ( V_50 & V_53 )
F_20 ( V_16 -> V_54 + 0 ) ;
else if ( V_50 & V_55 )
F_20 ( V_16 -> V_54 + 1 ) ;
else if ( V_50 & V_56 )
F_20 ( V_16 -> V_54 + 2 ) ;
else if ( V_50 & V_57 )
F_20 ( V_16 -> V_54 + 4 ) ;
else
F_21 () ;
}
static void F_22 ( struct V_58 * V_59 )
{
struct V_11 * V_16 ;
unsigned int V_46 ;
void T_2 * V_18 = V_49 ;
T_1 V_4 ;
V_16 = F_23 ( V_59 ) ;
V_46 = V_59 -> V_46 - V_16 -> V_54 ;
V_4 = F_9 ( V_18 + V_52 ) ;
F_11 ( V_4 | ( 1 << V_46 ) , V_18 + V_52 ) ;
F_9 ( V_18 + V_52 ) ;
}
static void F_24 ( struct V_58 * V_59 )
{
struct V_11 * V_16 ;
unsigned int V_46 ;
void T_2 * V_18 = V_49 ;
T_1 V_4 ;
V_16 = F_23 ( V_59 ) ;
V_46 = V_59 -> V_46 - V_16 -> V_54 ;
V_4 = F_9 ( V_18 + V_52 ) ;
F_11 ( V_4 & ~ ( 1 << V_46 ) , V_18 + V_52 ) ;
F_9 ( V_18 + V_52 ) ;
}
static void F_25 ( struct V_11 * V_16 )
{
void T_2 * V_18 = V_49 ;
int V_60 ;
F_11 ( 0 , V_18 + V_52 ) ;
F_11 ( 0 , V_18 + V_51 ) ;
F_26 ( V_61 < V_62 ) ;
V_16 -> V_54 = V_63 ;
for ( V_60 = V_16 -> V_54 ;
V_60 < V_16 -> V_54 + V_62 ; V_60 ++ ) {
F_27 ( V_60 , & V_64 ,
V_65 ) ;
F_28 ( V_60 , V_16 ) ;
}
F_29 ( V_16 -> V_46 , V_16 ) ;
F_30 ( V_16 -> V_46 , F_18 ) ;
}
static void F_31 ( void )
{
void T_2 * V_66 = V_67 ;
F_32 ( V_68 | V_69 ) ;
F_33 ( 100 ) ;
F_34 ( V_68 | V_69 ) ;
F_33 ( 100 ) ;
F_11 ( V_70 , V_66 + V_71 ) ;
F_11 ( V_72 , V_66 + V_73 ) ;
F_11 ( V_74 , V_66 + V_75 ) ;
F_11 ( V_76 , V_66 + V_77 ) ;
F_11 ( V_78 , V_66 + V_79 ) ;
F_11 ( V_80 , V_66 + V_81 ) ;
F_11 ( V_82 , V_66 + V_83 ) ;
F_11 ( V_84 , V_66 + V_85 ) ;
F_33 ( 100 ) ;
}
static int F_35 ( struct V_86 * V_87 )
{
struct V_11 * V_16 ;
struct V_88 * V_89 ;
T_1 V_4 ;
V_16 = F_36 ( & V_87 -> V_90 , sizeof( struct V_11 ) ,
V_91 ) ;
if ( ! V_16 )
return - V_92 ;
F_37 ( & V_16 -> V_39 ) ;
V_89 = F_38 ( V_87 , V_93 , L_4 ) ;
if ( ! V_89 )
return - V_94 ;
V_16 -> V_19 = F_39 ( & V_87 -> V_90 , V_89 ) ;
if ( F_40 ( V_16 -> V_19 ) )
return F_41 ( V_16 -> V_19 ) ;
V_16 -> V_46 = F_42 ( V_87 , 0 ) ;
if ( V_16 -> V_46 < 0 )
return - V_94 ;
V_89 = F_38 ( V_87 , V_95 , L_5 ) ;
if ( ! V_89 )
return - V_94 ;
V_16 -> V_96 . V_97 = V_89 ;
V_16 -> V_96 . V_98 = L_6 ;
V_16 -> V_96 . V_99 = V_89 -> V_99 ;
V_16 -> V_96 . V_100 = V_89 -> V_100 ;
V_16 -> V_96 . V_35 = V_95 ;
V_89 = F_38 ( V_87 , V_93 , L_7 ) ;
if ( ! V_89 )
return - V_94 ;
V_16 -> V_101 . V_97 = V_89 ;
V_16 -> V_101 . V_98 = L_8 ;
V_16 -> V_101 . V_99 = V_89 -> V_99 ;
V_16 -> V_101 . V_100 = V_89 -> V_100 ;
V_16 -> V_101 . V_35 = V_93 ;
F_31 () ;
V_4 = V_102 | V_103 | V_104
| V_105 | V_106 | V_107 ;
F_12 ( V_16 , V_108 , 4 , V_4 ) ;
F_8 ( V_16 , 1 ) ;
F_25 ( V_16 ) ;
V_16 -> V_15 . V_109 = & V_110 ;
V_16 -> V_15 . V_111 = & V_16 -> V_101 ;
V_16 -> V_15 . V_112 = & V_16 -> V_96 ;
F_43 ( & V_16 -> V_15 ) ;
return 0 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_113 ) ;
}
