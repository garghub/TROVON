static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
T_1 V_4 = V_3 -> V_4 ;
return F_2 ( V_3 , struct V_1 , V_3 [ V_4 ] ) ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_6 )
{
return (struct V_1 * ) ( V_6 -> V_7 ) ;
}
static inline struct V_5 * F_4 ( struct V_1 * V_1 )
{
return F_2 ( ( void * ) V_1 , struct V_5 , V_7 ) ;
}
static inline void F_5 ( struct V_1 * V_1 )
{
F_4 ( V_1 ) -> V_8 = V_9 ;
}
static void F_6 ( struct V_10 * V_10 )
{
struct V_1 * V_1 = F_7 ( V_10 ) ;
struct V_11 * V_12 = V_1 -> V_13 ;
struct V_5 * V_6 = F_4 ( V_1 ) ;
V_1 -> V_14 += 1 ;
F_8 ( & V_15 ) ;
F_9 ( & V_1 -> V_16 ) ;
V_17 -= 1 ;
F_10 ( & V_15 ) ;
F_11 ( & V_1 -> V_13 -> V_18 , L_1
L_2 , V_6 , V_1 , V_1 -> V_14 , V_12 ) ;
F_12 ( V_6 ) ;
}
static inline void F_13 ( struct V_1 * V_1 )
{
F_14 ( & V_1 -> V_10 , F_6 ) ;
}
static inline void F_15 ( struct V_1 * V_1 )
{
F_16 ( & V_1 -> V_10 ) ;
}
static void F_17 ( struct V_10 * V_10 )
{
struct V_2 * V_3 = F_18 ( V_10 ) ;
V_3 -> V_4 = 0 ;
V_3 -> V_19 = NULL ;
V_3 -> V_20 = 0 ;
V_3 -> V_21 = 0 ;
}
static inline void F_19 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_14 ( & V_3 -> V_10 , F_17 ) ;
}
static inline void F_20 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_21 ( & V_3 -> V_10 ) ;
}
static inline void F_22 ( struct V_1 * V_1 ,
struct V_2 * V_3 )
{
F_16 ( & V_3 -> V_10 ) ;
}
static inline void F_23 ( struct V_1 * V_1 , struct V_22 * V_23 )
{
F_14 ( & V_1 -> V_10 , F_6 ) ;
}
static void F_24 ( struct V_1 * V_1 , struct V_22 * V_23 ,
unsigned int V_24 )
{
if ( V_24 > 0 ) {
if ( F_25 ( V_25 , & V_23 -> V_26 , V_24 ) )
return;
} else if ( F_25 ( V_25 , & V_23 -> V_26 , 0 ) )
return;
F_14 ( & V_1 -> V_10 , F_6 ) ;
}
static void F_26 ( struct V_1 * V_1 , struct V_22 * V_23 ,
unsigned int V_24 )
{
F_21 ( & V_1 -> V_10 ) ;
F_24 ( V_1 , V_23 , V_24 ) ;
}
static void F_27 ( struct V_1 * V_1 , struct V_22 * V_23 )
{
if ( F_28 ( & V_23 -> V_26 ) )
F_14 ( & V_1 -> V_10 , F_6 ) ;
}
static void F_29 ( struct V_10 * V_10 )
{
struct V_27 * V_28 = F_30 ( V_10 ) ;
struct V_1 * V_1 = V_28 -> V_1 ;
T_1 V_20 = V_28 -> V_20 ;
T_1 V_29 = V_28 -> V_29 ;
T_1 V_30 = V_1 -> V_31 [ V_20 ] . V_30 ;
struct V_2 * V_3 = & V_1 -> V_3 [ V_30 ] ;
T_1 V_32 = V_28 -> V_32 ;
struct V_33 * V_34 = V_28 -> V_34 ;
struct V_22 * V_23 = V_28 -> V_23 ;
struct V_35 * V_36 = & V_28 -> V_37 ;
V_23 -> V_38 -= 1 ;
if ( V_28 == V_23 -> V_39 ) {
if ( F_31 ( V_36 ) ) {
V_23 -> V_39 = NULL ;
F_32 ( V_36 ) ;
} else {
struct V_27 * V_40 = F_33 ( V_36 -> V_41 ,
struct V_27 , V_37 ) ;
V_23 -> V_39 = V_40 ;
F_32 ( V_36 ) ;
}
} else
F_32 ( V_36 ) ;
if ( V_28 -> V_42 ) {
V_3 -> V_43 [ V_29 ] = 0 ;
F_19 ( V_1 , V_3 ) ;
}
if ( V_28 -> V_44 ) {
V_3 -> V_45 [ V_29 ] = 0 ;
F_19 ( V_1 , V_3 ) ;
}
V_1 -> V_28 [ V_32 - 1 ] = NULL ;
V_34 -> V_46 = NULL ;
F_34 ( V_28 ) ;
F_13 ( V_1 ) ;
}
static inline void F_35 ( struct V_1 * V_1 , struct V_27 * V_28 )
{
F_14 ( & V_28 -> V_10 , F_29 ) ;
}
static inline void F_36 ( struct V_1 * V_1 , struct V_27 * V_28 )
{
F_21 ( & V_28 -> V_10 ) ;
}
static inline void F_37 ( struct V_1 * V_1 ,
struct V_27 * V_28 )
{
F_16 ( & V_28 -> V_10 ) ;
F_21 ( & V_1 -> V_10 ) ;
}
static void F_38 ( struct V_1 * V_1 , struct V_27 * V_28 ,
unsigned int V_24 )
{
if ( F_25 ( V_25 , & V_28 -> V_26 , V_24 ) )
F_21 ( & V_28 -> V_10 ) ;
}
static void F_39 ( struct V_1 * V_1 , struct V_27 * V_28 )
{
if ( F_28 ( & V_28 -> V_26 ) )
F_14 ( & V_28 -> V_10 , F_29 ) ;
}
static inline void F_40 ( struct V_1 * V_1 )
{
F_14 ( & V_1 -> V_10 , F_6 ) ;
}
static void F_41 ( struct V_1 * V_1 , unsigned int V_24 )
{
if ( F_25 ( V_25 , & V_1 -> V_47 , V_24 ) )
F_21 ( & V_1 -> V_10 ) ;
}
static void F_42 ( struct V_1 * V_1 , unsigned int V_24 )
{
if ( ! F_25 ( V_25 , & V_1 -> V_47 , V_24 ) )
F_14 ( & V_1 -> V_10 , F_6 ) ;
}
static void F_43 ( struct V_1 * V_1 )
{
if ( F_28 ( & V_1 -> V_47 ) )
F_14 ( & V_1 -> V_10 , F_6 ) ;
}
static int F_44 ( struct V_1 * V_1 )
{
T_2 V_48 ;
int V_49 ;
V_49 = F_45 ( V_1 , V_48 , & V_48 ) ;
if ( V_49 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_3
L_4 , V_49 ) ;
return V_49 ;
} else if ( ( V_48 & 0xFF ) == 0x10 ) {
} else if ( ( V_48 & 0xFF ) == 0x11 ) {
} else {
F_46 ( & V_1 -> V_13 -> V_18 , L_5
L_6 , V_48 ) ;
return - V_50 ;
}
V_49 = F_45 ( V_1 , V_51 , & V_1 -> V_52 ) ;
if ( V_49 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_3
L_4 , V_49 ) ;
return V_49 ;
}
V_49 = F_45 ( V_1 , V_53 . V_54 ,
& V_1 -> V_55 ) ;
if ( V_49 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_7
L_8 , V_49 ) ;
return V_49 ;
}
V_49 = F_45 ( V_1 , V_53 . V_56 , & V_1 -> V_57 ) ;
if ( V_49 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_7
L_9 , V_49 ) ;
return V_49 ;
}
{
int V_58 = V_1 -> V_59 ;
int V_60 = 0 ;
while ( V_58 -- > 0 ) {
V_49 = F_45 ( V_1 , V_53 . V_61 [ V_60 ] ,
& V_1 -> V_62 [ V_60 ] ) ;
if ( V_49 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_10
L_11
, V_49 , V_60 ) ;
return V_49 ;
} else
V_60 += 1 ;
}
}
return 0 ;
}
static void F_47 ( struct V_63 * V_64 )
{
struct V_1 * V_1 = F_2 ( V_64 , struct V_1 , V_47 . V_64 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
F_40 ( V_1 ) ;
return;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_13 ) ;
F_40 ( V_1 ) ;
return;
} else {
int V_49 ;
F_8 ( & V_1 -> V_65 ) ;
V_49 = F_44 ( V_1 ) ;
if ( V_49 ) {
struct V_5 * V_6 = F_4 ( V_1 ) ;
F_5 ( V_1 ) ;
V_1 -> V_14 = 1 ;
F_10 ( & V_1 -> V_65 ) ;
F_48 ( V_6 ) ;
F_49 ( V_1 -> V_13 ) ;
F_40 ( V_1 ) ;
return;
} else {
F_42 ( V_1 , 500 ) ;
F_10 ( & V_1 -> V_65 ) ;
return;
}
}
}
static void F_50 ( struct V_1 * V_1 , struct V_27 * V_28 ,
struct V_66 * V_66 , int V_54 )
{
struct V_22 * V_23 ;
unsigned long V_67 ;
struct V_5 * V_6 = F_4 ( V_1 ) ;
V_66 -> V_68 = 0 ;
F_51 ( & V_28 -> V_69 . V_70 , V_67 ) ;
F_52 ( V_6 , V_66 ) ;
V_28 -> V_71 += 1 ;
if ( V_72 > -- V_28 -> V_73 ) {
V_28 -> V_74 = 0 ;
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
} else {
struct V_35 * V_41 = V_28 -> V_75 . V_41 ;
struct V_76 * V_77 = F_33 ( V_41 , struct V_76 ,
V_75 ) ;
F_32 ( V_41 ) ;
V_28 -> V_78 [ V_79 & V_28 -> V_80 ++ ] =
V_77 -> V_66 ;
V_28 -> V_74 = 0 ;
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
F_34 ( V_77 ) ;
}
F_8 ( & V_1 -> V_81 ) ;
V_23 = V_28 -> V_23 ;
V_23 -> V_82 = 0 ;
F_27 ( V_1 , V_23 ) ;
F_26 ( V_1 , V_23 , 0 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_35 ( V_1 , V_28 ) ;
F_54 ( V_6 , V_66 , V_54 ) ;
}
static void F_55 ( struct V_1 * V_1 , struct V_27 * V_28 ,
struct V_66 * V_66 , int V_54 )
{
F_35 ( V_1 , V_28 ) ;
}
static void F_56 ( struct V_1 * V_1 , struct V_27 * V_28 ,
struct V_66 * V_66 , int V_54 )
{
unsigned long V_67 ;
struct V_5 * V_6 = F_4 ( V_1 ) ;
V_66 -> V_68 = 0 ;
F_51 ( & V_28 -> V_69 . V_70 , V_67 ) ;
F_52 ( V_6 , V_66 ) ;
V_28 -> V_71 += 1 ;
if ( V_72 > -- V_28 -> V_73 ) {
V_28 -> V_74 = 0 ;
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
} else {
struct V_35 * V_41 = V_28 -> V_75 . V_41 ;
struct V_76 * V_77 = F_33 ( V_41 , struct V_76 ,
V_75 ) ;
F_32 ( V_41 ) ;
V_28 -> V_78 [ V_79 & V_28 -> V_80 ++ ] =
V_77 -> V_66 ;
V_28 -> V_74 = 0 ;
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
F_34 ( V_77 ) ;
}
F_54 ( V_6 , V_66 , V_54 ) ;
}
static inline int F_57 ( struct V_1 * V_1 , struct V_22 * V_23 ,
struct V_27 * V_28 , struct V_66 * V_66 , T_1 V_30 , T_1 V_83 ,
void (* F_58) ( void * V_28 , struct V_66 * V_66 , T_1 * V_84 , int V_85 ,
int V_83 , int V_68 , int V_86 , int V_87 ,
int V_88 , int V_89 , int V_90 , int V_91 ) )
{
return F_59 ( V_1 -> V_13 , V_23 -> V_92 , V_28 ,
V_66 , V_30 , V_28 -> V_29 , V_83 , F_58 ) ;
}
static inline int F_60 ( struct V_1 * V_1 , struct V_22 * V_23 ,
struct V_27 * V_28 , struct V_66 * V_66 , T_1 V_30 , T_1 V_83 ,
void (* F_58) ( void * V_28 , struct V_66 * V_66 , T_1 * V_84 , int V_85 ,
int V_83 , int V_68 , int V_86 , int V_87 ,
int V_88 , int V_89 , int V_90 , int V_91 ) )
{
return F_61 ( V_1 -> V_13 , V_23 -> V_92 , V_28 ,
V_66 , V_30 , V_28 -> V_29 , V_83 , F_58 ) ;
}
static inline int F_62 ( struct V_1 * V_1 , struct V_22 * V_23 ,
struct V_27 * V_28 , struct V_66 * V_66 , T_1 V_30 , T_1 V_83 ,
void (* F_58) ( void * V_28 , struct V_66 * V_66 , T_1 * V_84 , int V_85 ,
int V_83 , int V_68 , int V_86 , int V_87 ,
int V_88 , int V_89 , int V_90 , int V_91 ) )
{
return F_63 ( V_1 -> V_13 , V_23 -> V_92 ,
V_28 , V_66 , V_30 , V_28 -> V_29 , V_83 , F_58 ) ;
}
static inline int F_64 ( struct V_1 * V_1 , struct V_22 * V_23 ,
struct V_27 * V_28 , struct V_66 * V_66 , T_1 V_30 , T_1 V_83 ,
void (* F_58) ( void * V_28 , struct V_66 * V_66 , T_1 * V_84 , int V_85 ,
int V_83 , int V_68 , int V_86 , int V_87 ,
int V_88 , int V_89 , int V_90 , int V_91 ) )
{
return F_65 ( V_1 -> V_13 , V_23 -> V_92 ,
V_28 , V_66 , V_30 , V_28 -> V_29 , V_83 , F_58 ) ;
}
static void F_66 ( void * V_93 , struct V_66 * V_66 , T_1 * V_84 ,
int V_85 , int V_83 , int V_68 , int V_86 ,
int V_87 , int V_88 , int V_89 , int V_90 , int V_91 )
{
struct V_27 * V_28 = V_93 ;
struct V_1 * V_1 = V_28 -> V_1 ;
T_1 V_30 = V_1 -> V_31 [ V_28 -> V_20 ] . V_30 ;
struct V_2 * V_3 = & V_1 -> V_3 [ V_30 ] ;
F_8 ( & V_1 -> V_81 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_55 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( V_28 -> V_94 ) {
V_28 -> V_94 = 0 ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_95 ) ;
return;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_14
L_15 , V_66 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( ! V_66 -> V_96 ) {
struct V_22 * V_23 = V_28 -> V_23 ;
T_1 * V_97 = V_66 -> V_98 + V_66 -> V_99 ;
T_1 * V_100 = V_84 ;
int V_101 = V_85 ;
while ( V_101 -- > 0 )
* V_97 ++ = * V_100 ++ ;
V_66 -> V_99 += V_85 ;
if ( ( V_86 == V_102 ) &&
( V_66 -> V_103 > V_66 -> V_99 ) ) {
V_28 -> V_83 = V_83 ;
F_67 ( V_3 -> V_19 , V_28 -> V_29 , 0 ,
1 & V_83 ) ;
if ( V_66 -> V_99 > 0 ) {
int V_49 ;
F_10 ( & V_1 -> V_81 ) ;
V_49 = F_62 ( V_1 , V_23 , V_28 , V_66 ,
V_30 , V_28 -> V_83 ,
F_66 ) ;
if ( V_49 != 0 )
F_50 ( V_1 , V_28 , V_66 ,
V_49 ) ;
} else {
V_23 -> V_82 = 0 ;
V_28 -> V_74 = 0 ;
V_28 -> V_104 = V_104 +
F_68 ( V_66 -> V_105 ) ;
F_27 ( V_1 , V_23 ) ;
F_26 ( V_1 , V_23 , 0 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_35 ( V_1 , V_28 ) ;
}
return;
} else if ( ( V_86 == V_106 ) &&
( ( V_66 -> V_107 & V_108 ) == 0 ) ) {
V_28 -> V_83 = V_83 ;
F_67 ( V_3 -> V_19 , V_28 -> V_29 , 0 ,
1 & V_83 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
} else {
if ( V_86 == V_102 ) {
V_28 -> V_83 = V_83 ;
F_67 ( V_3 -> V_19 , V_28 -> V_29 ,
0 , 1 & V_83 ) ;
} else if ( V_86 == V_109 ) {
V_28 -> V_83 = 0x2 ;
F_67 ( V_3 -> V_19 , V_28 -> V_29 ,
0 , 0 ) ;
} else {
V_28 -> V_83 = 0x2 ;
F_67 ( V_3 -> V_19 , V_28 -> V_29 ,
0 , 0 ) ;
F_46 ( & V_1 -> V_13 -> V_18 , L_16
L_17 , V_66 ,
V_110 [ V_86 ] ) ;
}
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 ,
V_111 [ V_86 ] ) ;
return;
}
} else {
F_46 ( & V_1 -> V_13 -> V_18 , L_18
L_19 , V_66 , V_66 -> V_96 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
}
}
static void F_69 ( void * V_93 , struct V_66 * V_66 , T_1 * V_84 ,
int V_85 , int V_83 , int V_68 , int V_86 ,
int V_87 , int V_88 , int V_89 , int V_90 , int V_91 )
{
struct V_27 * V_28 = V_93 ;
struct V_1 * V_1 = V_28 -> V_1 ;
T_1 V_30 = V_1 -> V_31 [ V_28 -> V_20 ] . V_30 ;
F_8 ( & V_1 -> V_81 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_55 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( V_28 -> V_94 ) {
V_28 -> V_94 = 0 ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_95 ) ;
return;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_14
L_15 , V_66 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( ! V_66 -> V_96 ) {
struct V_22 * V_23 = V_28 -> V_23 ;
V_66 -> V_99 += V_85 ;
V_28 -> V_83 = V_83 ;
if ( V_66 -> V_103 > V_66 -> V_99 ) {
int V_49 ;
F_10 ( & V_1 -> V_81 ) ;
V_49 = F_64 ( V_1 , V_23 , V_28 , V_66 , V_30 ,
V_28 -> V_83 , F_69 ) ;
if ( V_49 != 0 )
F_50 ( V_1 , V_28 , V_66 , V_49 ) ;
return;
} else {
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
}
} else {
F_46 ( & V_1 -> V_13 -> V_18 , L_18
L_19 , V_66 , V_66 -> V_96 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
}
}
static void F_70 ( void * V_93 , struct V_66 * V_66 , T_1 * V_84 ,
int V_85 , int V_83 , int V_68 , int V_86 ,
int V_87 , int V_88 , int V_89 , int V_90 , int V_91 )
{
struct V_27 * V_28 = V_93 ;
struct V_1 * V_1 = V_28 -> V_1 ;
T_1 V_30 = V_1 -> V_31 [ V_28 -> V_20 ] . V_30 ;
struct V_2 * V_3 = & V_1 -> V_3 [ V_30 ] ;
F_8 ( & V_1 -> V_81 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_55 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( V_28 -> V_94 ) {
V_28 -> V_94 = 0 ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_95 ) ;
return;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_14
L_15 , V_66 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( ! V_66 -> V_96 ) {
struct V_22 * V_23 = V_28 -> V_23 ;
T_1 * V_97 = V_66 -> V_98 + V_66 -> V_99 ;
T_1 * V_100 = V_84 ;
int V_101 = V_85 ;
while ( V_101 -- > 0 )
* V_97 ++ = * V_100 ++ ;
V_66 -> V_99 += V_85 ;
if ( ( V_86 == V_102 ) &&
( V_66 -> V_103 > V_66 -> V_99 ) ) {
int V_49 ;
V_28 -> V_83 = V_83 ;
F_67 ( V_3 -> V_19 , V_28 -> V_29 , 0 ,
1 & V_83 ) ;
F_10 ( & V_1 -> V_81 ) ;
V_49 = F_59 ( V_1 -> V_13 ,
V_23 -> V_92 , V_28 , V_66 , V_30 ,
V_28 -> V_29 , V_28 -> V_83 ,
F_70 ) ;
if ( V_49 != 0 )
F_50 ( V_1 , V_28 , V_66 , V_49 ) ;
return;
} else if ( V_86 == V_102 ) {
V_28 -> V_83 = V_83 ;
F_67 ( V_3 -> V_19 , V_28 -> V_29 , 0 ,
1 & V_83 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 ,
V_111 [ V_86 ] ) ;
return;
} else if ( ( V_86 == V_106 ) &&
( ( V_66 -> V_107 & V_108 ) == 0 ) ) {
V_28 -> V_83 = V_83 ;
F_67 ( V_3 -> V_19 , V_28 -> V_29 , 0 ,
1 & V_83 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
} else if ( V_86 == V_106 ) {
V_28 -> V_83 = V_83 ;
F_67 ( V_3 -> V_19 , V_28 -> V_29 , 0 ,
1 & V_83 ) ;
F_11 ( & V_1 -> V_13 -> V_18 , L_20
L_21 , V_66 ,
V_110 [ V_86 ] ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
} else if ( V_86 == V_109 ) {
V_28 -> V_83 = 0x2 ;
F_67 ( V_3 -> V_19 , V_28 -> V_29 , 0 , 0 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 ,
V_111 [ V_86 ] ) ;
return;
} else {
V_28 -> V_83 = 0x2 ;
F_67 ( V_3 -> V_19 , V_28 -> V_29 , 0 , 0 ) ;
F_46 ( & V_1 -> V_13 -> V_18 , L_22
L_23 , V_66 , V_86 ,
V_110 [ V_86 ] ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 ,
V_111 [ V_86 ] ) ;
return;
}
} else {
F_46 ( & V_1 -> V_13 -> V_18 , L_18
L_19 , V_66 , V_66 -> V_96 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
}
}
static void F_71 ( void * V_93 , struct V_66 * V_66 , T_1 * V_84 ,
int V_85 , int V_83 , int V_68 , int V_86 ,
int V_87 , int V_88 , int V_89 , int V_90 , int V_91 )
{
struct V_27 * V_28 = V_93 ;
struct V_1 * V_1 = V_28 -> V_1 ;
F_8 ( & V_1 -> V_81 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_55 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( V_28 -> V_94 ) {
V_28 -> V_94 = 0 ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_95 ) ;
return;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_14
L_15 , V_66 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( ! V_66 -> V_96 ) {
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
} else {
F_46 ( & V_1 -> V_13 -> V_18 , L_18
L_19 , V_66 , V_66 -> V_96 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
}
}
static void F_72 ( void * V_93 , struct V_66 * V_66 , T_1 * V_84 ,
int V_85 , int V_83 , int V_68 , int V_86 ,
int V_87 , int V_88 , int V_89 , int V_90 , int V_91 )
{
struct V_27 * V_28 = V_93 ;
struct V_1 * V_1 = V_28 -> V_1 ;
T_1 V_30 = V_1 -> V_31 [ V_28 -> V_20 ] . V_30 ;
F_8 ( & V_1 -> V_81 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_55 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( V_28 -> V_94 ) {
V_28 -> V_94 = 0 ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_95 ) ;
return;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_14
L_15 , V_66 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( ! V_66 -> V_96 ) {
struct V_22 * V_23 = V_28 -> V_23 ;
T_1 * V_97 = V_66 -> V_98 ;
T_1 * V_100 = V_84 ;
int V_101 = V_85 ;
while ( V_101 -- > 0 )
* V_97 ++ = * V_100 ++ ;
V_66 -> V_99 = V_85 ;
if ( ( V_86 == V_102 ) || ( ( V_86 ==
V_106 ) && ( ( V_66 -> V_107 &
V_108 ) == 0 ) ) ) {
int V_49 ;
F_10 ( & V_1 -> V_81 ) ;
V_49 = F_73 ( V_1 -> V_13 ,
V_23 -> V_92 , V_28 , V_66 , V_30 ,
V_28 -> V_29 , 0x3 ,
F_71 ) ;
if ( V_49 != 0 )
F_50 ( V_1 , V_28 , V_66 , V_49 ) ;
return;
} else if ( V_86 == V_109 ) {
F_10 ( & V_1 -> V_81 ) ;
F_11 ( & V_1 -> V_13 -> V_18 , L_24
L_25 , V_66 ) ;
F_50 ( V_1 , V_28 , V_66 ,
V_111 [ V_86 ] ) ;
return;
} else {
F_10 ( & V_1 -> V_81 ) ;
F_46 ( & V_1 -> V_13 -> V_18 , L_26
L_27 , V_110 [ V_86 ] ,
V_66 ) ;
F_50 ( V_1 , V_28 , V_66 ,
V_111 [ V_86 ] ) ;
return;
}
} else {
F_46 ( & V_1 -> V_13 -> V_18 , L_18
L_19 , V_66 , V_66 -> V_96 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
}
}
static void F_74 ( void * V_93 , struct V_66 * V_66 , T_1 * V_84 ,
int V_85 , int V_83 , int V_68 , int V_86 ,
int V_87 , int V_88 , int V_89 , int V_90 , int V_91 )
{
struct V_27 * V_28 = V_93 ;
struct V_1 * V_1 = V_28 -> V_1 ;
F_8 ( & V_1 -> V_81 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_55 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( V_28 -> V_94 ) {
V_28 -> V_94 = 0 ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_95 ) ;
return;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_14
L_15 , V_66 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( ! V_66 -> V_96 ) {
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
} else {
F_46 ( & V_1 -> V_13 -> V_18 , L_18
L_19 , V_66 , V_66 -> V_96 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
}
}
static void F_75 ( void * V_93 , struct V_66 * V_66 , T_1 * V_84 ,
int V_85 , int V_83 , int V_68 , int V_86 ,
int V_87 , int V_88 , int V_89 , int V_90 , int V_91 )
{
struct V_27 * V_28 = V_93 ;
struct V_1 * V_1 = V_28 -> V_1 ;
T_1 V_30 = V_1 -> V_31 [ V_28 -> V_20 ] . V_30 ;
F_8 ( & V_1 -> V_81 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_55 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( V_28 -> V_94 ) {
V_28 -> V_94 = 0 ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_95 ) ;
return;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_14
L_15 , V_66 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( ! V_66 -> V_96 ) {
if ( F_76 ( V_66 -> V_112 ) ) {
int V_49 ;
struct V_22 * V_23 = V_28 -> V_23 ;
F_10 ( & V_1 -> V_81 ) ;
V_49 = F_59 ( V_1 -> V_13 ,
V_23 -> V_92 , V_28 , V_66 , V_30 ,
V_28 -> V_29 , 0 ,
F_72 ) ;
if ( V_49 != 0 )
F_50 ( V_1 , V_28 , V_66 , V_49 ) ;
return;
} else {
int V_49 ;
struct V_22 * V_23 = V_28 -> V_23 ;
F_10 ( & V_1 -> V_81 ) ;
V_49 = F_59 ( V_1 -> V_13 ,
V_23 -> V_92 , V_28 , V_66 , V_30 ,
V_28 -> V_29 , 0 ,
F_74 ) ;
if ( V_49 != 0 )
F_50 ( V_1 , V_28 , V_66 , V_49 ) ;
return;
}
} else {
F_46 ( & V_1 -> V_13 -> V_18 , L_18
L_19 , V_66 , V_66 -> V_96 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
}
}
static void F_77 ( void * V_93 , struct V_66 * V_66 ,
T_1 * V_84 , int V_85 , int V_83 , int V_68 , int V_86 ,
int V_87 , int V_88 , int V_89 , int V_90 , int V_91 )
{
struct V_27 * V_28 = V_93 ;
struct V_1 * V_1 = V_28 -> V_1 ;
T_1 V_30 = V_1 -> V_31 [ V_28 -> V_20 ] . V_30 ;
struct V_2 * V_3 = & V_1 -> V_3 [ V_30 ] ;
F_8 ( & V_1 -> V_81 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_55 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( V_28 -> V_94 ) {
V_28 -> V_94 = 0 ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_95 ) ;
return;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_14
L_15 , V_66 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( ! V_66 -> V_96 ) {
V_1 -> V_31 [ 0 ] . V_30 = 0 ;
V_28 -> V_20 = V_3 -> V_20 ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
} else {
F_46 ( & V_1 -> V_13 -> V_18 , L_18
L_19 , V_66 , V_66 -> V_96 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
}
}
static void F_78 ( void * V_93 , struct V_66 * V_66 ,
T_1 * V_84 , int V_85 , int V_83 , int V_68 , int V_86 ,
int V_87 , int V_88 , int V_89 , int V_90 , int V_91 )
{
struct V_27 * V_28 = V_93 ;
struct V_1 * V_1 = V_28 -> V_1 ;
F_8 ( & V_1 -> V_81 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_55 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( V_28 -> V_94 ) {
V_28 -> V_94 = 0 ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_95 ) ;
return;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_14
L_15 , V_66 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( ! V_66 -> V_96 ) {
int V_49 ;
struct V_22 * V_23 = V_28 -> V_23 ;
F_10 ( & V_1 -> V_81 ) ;
V_49 = F_59 ( V_1 -> V_13 ,
V_23 -> V_92 , V_28 , V_66 , 0 , V_28 -> V_29 , 0 ,
F_77 ) ;
if ( V_49 != 0 )
F_50 ( V_1 , V_28 , V_66 , V_49 ) ;
return;
} else {
F_46 ( & V_1 -> V_13 -> V_18 , L_18
L_19 , V_66 , V_66 -> V_96 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
}
}
static void F_79 ( void * V_93 , struct V_66 * V_66 , T_1 * V_84 ,
int V_85 , int V_83 , int V_68 , int V_86 ,
int V_87 , int V_88 , int V_89 , int V_90 , int V_91 )
{
struct V_27 * V_28 = V_93 ;
struct V_1 * V_1 = V_28 -> V_1 ;
F_8 ( & V_1 -> V_81 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_55 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( V_28 -> V_94 ) {
V_28 -> V_94 = 0 ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_95 ) ;
return;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_14
L_15 , V_66 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( ! V_66 -> V_96 ) {
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
} else {
F_46 ( & V_1 -> V_13 -> V_18 , L_18
L_19 , V_66 , V_66 -> V_96 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
}
}
static void F_80 ( void * V_93 , struct V_66 * V_66 , T_1 * V_84 ,
int V_85 , int V_83 , int V_68 , int V_86 ,
int V_87 , int V_88 , int V_89 , int V_90 , int V_91 )
{
struct V_27 * V_28 = V_93 ;
struct V_1 * V_1 = V_28 -> V_1 ;
T_1 V_30 = V_1 -> V_31 [ V_28 -> V_20 ] . V_30 ;
F_8 ( & V_1 -> V_81 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_55 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( V_28 -> V_94 ) {
V_28 -> V_94 = 0 ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_95 ) ;
return;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_14
L_15 , V_66 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( ! V_66 -> V_96 ) {
int V_49 ;
struct V_22 * V_23 = V_28 -> V_23 ;
T_1 * V_97 = V_66 -> V_98 ;
T_1 * V_100 = V_84 ;
int V_101 = V_85 ;
while ( V_101 -- > 0 )
* V_97 ++ = * V_100 ++ ;
V_66 -> V_99 = V_85 ;
F_10 ( & V_1 -> V_81 ) ;
V_49 = F_73 ( V_1 -> V_13 ,
V_23 -> V_92 , V_28 , V_66 , V_30 , V_28 -> V_29 , 0x3 ,
F_79 ) ;
if ( V_49 != 0 )
F_50 ( V_1 , V_28 , V_66 , V_49 ) ;
return;
} else {
F_46 ( & V_1 -> V_13 -> V_18 , L_18
L_19 , V_66 , V_66 -> V_96 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
}
}
static void F_81 ( void * V_93 , struct V_66 * V_66 , T_1 * V_84 ,
int V_85 , int V_83 , int V_68 , int V_86 ,
int V_87 , int V_88 , int V_89 , int V_90 , int V_91 )
{
struct V_27 * V_28 = V_93 ;
struct V_1 * V_1 = V_28 -> V_1 ;
T_1 V_30 = V_1 -> V_31 [ V_28 -> V_20 ] . V_30 ;
F_8 ( & V_1 -> V_81 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_55 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( V_28 -> V_94 ) {
V_28 -> V_94 = 0 ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_95 ) ;
return;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_14
L_15 , V_66 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , - V_50 ) ;
return;
} else if ( ! V_66 -> V_96 ) {
int V_49 ;
struct V_22 * V_23 = V_28 -> V_23 ;
F_10 ( & V_1 -> V_81 ) ;
V_49 = F_59 ( V_1 -> V_13 ,
V_23 -> V_92 , V_28 , V_66 , V_30 , V_28 -> V_29 , 0 ,
F_80 ) ;
if ( V_49 != 0 )
F_50 ( V_1 , V_28 , V_66 , V_49 ) ;
return;
} else {
F_46 ( & V_1 -> V_13 -> V_18 , L_18
L_19 , V_66 , V_66 -> V_96 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_50 ( V_1 , V_28 , V_66 , 0 ) ;
return;
}
}
static void F_82 ( struct V_63 * V_64 )
{
struct V_22 * V_23 =
F_2 ( V_64 , struct V_22 , V_26 . V_64 ) ;
struct V_1 * V_1 = V_23 -> V_1 ;
F_8 ( & V_1 -> V_81 ) ;
if ( V_23 -> V_82 ) {
F_10 ( & V_1 -> V_81 ) ;
F_23 ( V_1 , V_23 ) ;
return;
} else if ( V_23 -> V_39 ) {
struct V_27 * V_28 , * V_113 = V_23 -> V_39 ;
unsigned long V_114 = 0 ;
F_83 (endp, &last_endp->endp_ring, endp_ring) {
if ( V_28 -> V_71 == V_28 -> V_80 ) {
} else if ( ( V_28 -> V_115 == 0 )
|| F_84 ( V_104 , V_28 -> V_104 ) ) {
V_23 -> V_39 = V_28 ;
F_39 ( V_1 , V_113 ) ;
F_38 ( V_1 , V_113 , 0 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_23 ( V_1 , V_23 ) ;
return;
} else {
unsigned long V_24 = V_28 -> V_104 - V_104 ;
if ( V_24 > V_114 )
V_114 = V_24 ;
}
}
if ( V_113 -> V_71 == V_113 -> V_80 ) {
} else if ( ( V_113 -> V_115 == 0 ) || F_84 ( V_104 ,
V_113 -> V_104 ) ) {
F_39 ( V_1 , V_113 ) ;
F_38 ( V_1 , V_113 , 0 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_23 ( V_1 , V_23 ) ;
return;
} else {
unsigned long V_24 = V_113 -> V_104 - V_104 ;
if ( V_24 > V_114 )
V_114 = V_24 ;
}
if ( V_114 > 0 ) {
F_24 ( V_1 , V_23 , V_114 ) ;
F_10 ( & V_1 -> V_81 ) ;
return;
} else {
F_10 ( & V_1 -> V_81 ) ;
F_23 ( V_1 , V_23 ) ;
return;
}
} else {
F_10 ( & V_1 -> V_81 ) ;
F_23 ( V_1 , V_23 ) ;
return;
}
}
static void F_85 ( struct V_63 * V_64 )
{
struct V_22 * V_23 ;
struct V_27 * V_28 =
F_2 ( V_64 , struct V_27 , V_26 . V_64 ) ;
struct V_1 * V_1 = V_28 -> V_1 ;
F_8 ( & V_1 -> V_81 ) ;
V_23 = V_28 -> V_23 ;
if ( V_28 -> V_116 ) {
V_28 -> V_116 = 0 ;
if ( V_28 -> V_94 )
F_86 ( V_1 -> V_13 ,
V_23 -> V_92 , V_28 ) ;
F_10 ( & V_1 -> V_81 ) ;
F_35 ( V_1 , V_28 ) ;
return;
} else if ( V_28 -> V_74 ) {
F_10 ( & V_1 -> V_81 ) ;
F_35 ( V_1 , V_28 ) ;
return;
} else if ( V_23 -> V_82 ) {
F_10 ( & V_1 -> V_81 ) ;
F_35 ( V_1 , V_28 ) ;
return;
} else if ( V_28 -> V_71 == V_28 -> V_80 ) {
F_10 ( & V_1 -> V_81 ) ;
F_35 ( V_1 , V_28 ) ;
return;
} else if ( V_28 -> V_117 == V_118 ) {
T_1 V_30 = V_1 -> V_31 [ V_28 -> V_20 ] . V_30 ;
if ( V_23 -> V_82 ) {
F_10 ( & V_1 -> V_81 ) ;
F_35 ( V_1 , V_28 ) ;
return;
} else {
int V_49 ;
struct V_66 * V_66 = V_28 -> V_78 [ V_79 &
V_28 -> V_71 ] ;
V_28 -> V_74 = 1 ;
V_23 -> V_39 = V_28 ;
V_23 -> V_82 = 1 ;
F_10 ( & V_1 -> V_81 ) ;
V_49 = F_62 ( V_1 , V_23 , V_28 , V_66 , V_30 ,
V_28 -> V_83 , F_66 ) ;
if ( V_49 != 0 )
F_50 ( V_1 , V_28 , V_66 , V_49 ) ;
return;
}
} else if ( V_28 -> V_117 == V_119 ) {
T_1 V_30 = V_1 -> V_31 [ V_28 -> V_20 ] . V_30 ;
if ( V_23 -> V_82 ) {
F_10 ( & V_1 -> V_81 ) ;
F_35 ( V_1 , V_28 ) ;
return;
} else if ( V_30 == 0 ) {
int V_49 ;
struct V_66 * V_66 = V_28 -> V_78 [ V_79 &
V_28 -> V_71 ] ;
V_28 -> V_74 = 1 ;
V_23 -> V_39 = V_28 ;
V_23 -> V_82 = 1 ;
F_10 ( & V_1 -> V_81 ) ;
V_49 = F_60 ( V_1 , V_23 , V_28 , V_66 , V_30 ,
0x2 , F_81 ) ;
if ( V_49 != 0 )
F_50 ( V_1 , V_28 , V_66 , V_49 ) ;
return;
} else if ( V_28 -> V_20 == 0 ) {
int V_49 ;
struct V_66 * V_66 = V_28 -> V_78 [ V_79 &
V_28 -> V_71 ] ;
V_28 -> V_74 = 1 ;
V_23 -> V_39 = V_28 ;
V_23 -> V_82 = 1 ;
F_10 ( & V_1 -> V_81 ) ;
V_49 = F_60 ( V_1 , V_23 , V_28 , V_66 , 0 , 0x2 ,
F_78 ) ;
if ( V_49 != 0 )
F_50 ( V_1 , V_28 , V_66 , V_49 ) ;
return;
} else {
int V_49 ;
struct V_66 * V_66 = V_28 -> V_78 [ V_79 &
V_28 -> V_71 ] ;
V_30 = V_1 -> V_31 [ V_28 -> V_20 ] . V_30 ;
V_28 -> V_74 = 1 ;
V_23 -> V_39 = V_28 ;
V_23 -> V_82 = 1 ;
F_10 ( & V_1 -> V_81 ) ;
V_49 = F_60 ( V_1 , V_23 , V_28 , V_66 , V_30 ,
0x2 , F_75 ) ;
if ( V_49 != 0 )
F_50 ( V_1 , V_28 , V_66 , V_49 ) ;
return;
}
} else {
if ( V_28 -> V_42 ) {
T_1 V_30 = V_1 -> V_31 [ V_28 -> V_20 ] . V_30 ;
if ( V_23 -> V_82 ) {
F_10 ( & V_1 -> V_81 ) ;
F_35 ( V_1 , V_28 ) ;
return;
} else {
int V_49 ;
struct V_66 * V_66 = V_28 -> V_78 [
V_79 & V_28 -> V_71 ] ;
V_28 -> V_74 = 1 ;
V_23 -> V_39 = V_28 ;
V_23 -> V_82 = 1 ;
F_10 ( & V_1 -> V_81 ) ;
V_49 = F_57 ( V_1 , V_23 , V_28 , V_66 ,
V_30 , V_28 -> V_83 ,
F_70 ) ;
if ( V_49 == 0 ) {
} else
F_50 ( V_1 , V_28 , V_66 ,
V_49 ) ;
return;
}
} else {
T_1 V_30 = V_1 -> V_31 [ V_28 -> V_20 ] . V_30 ;
if ( V_23 -> V_82 ) {
F_10 ( & V_1 -> V_81 ) ;
F_35 ( V_1 , V_28 ) ;
return;
} else {
int V_49 ;
struct V_66 * V_66 = V_28 -> V_78 [
V_79 & V_28 -> V_71 ] ;
V_28 -> V_74 = 1 ;
V_23 -> V_39 = V_28 ;
V_23 -> V_82 = 1 ;
F_10 ( & V_1 -> V_81 ) ;
V_49 = F_64 ( V_1 , V_23 , V_28 , V_66 ,
V_30 , V_28 -> V_83 ,
F_69 ) ;
if ( V_49 == 0 ) {
} else
F_50 ( V_1 , V_28 , V_66 ,
V_49 ) ;
return;
}
}
}
}
static void F_87 ( struct V_1 * V_1 , int V_120 , int V_121 )
{
V_1 -> V_122 [ V_120 ] . V_123 = V_121 ;
}
static void F_88 ( struct V_1 * V_1 , int V_121 )
{
struct V_5 * V_6 = F_4 ( V_1 )
;
if ( V_121 ) {
if ( V_1 -> V_123 )
return;
V_1 -> V_123 = 1 ;
} else {
V_1 -> V_123 = 0 ;
V_6 -> V_8 = V_9 ;
}
}
static int F_89 ( struct V_1 * V_1 )
{
int V_49 ;
T_2 V_124 = V_1 -> V_125 & 0x03fff ;
T_2 V_126 ;
T_2 V_127 ;
V_49 = F_45 ( V_1 , V_127 , & V_127 ) ;
if ( V_49 )
return V_49 ;
V_126 = V_127 & V_128 ;
V_49 = F_90 ( V_1 , V_127 ,
( V_126 ^ V_128 ) | V_1 -> V_125 ) ;
if ( V_49 )
return V_49 ;
return F_90 ( V_1 , V_129 ,
( ( 9 * V_124 ) / 10 ) & 0x3fff ) ;
}
static char * F_91 ( int V_8 )
{
switch ( V_8 ) {
case V_130 :
return L_28 ;
case V_131 :
return L_29 ;
case V_132 :
return L_30 ;
case V_133 :
return L_31 ;
}
return L_32 ;
}
static int F_92 ( struct V_1 * V_1 )
{
int V_49 ;
T_2 V_51 ;
F_5 ( V_1 ) ;
V_1 -> V_134 = V_104 ;
V_49 = F_90 ( V_1 , V_135 , V_136 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_45 ( V_1 , V_51 , & V_51 ) ;
if ( V_49 )
return V_49 ;
if ( V_1 -> V_59 == 0 ) {
T_2 V_137 = - 1 ;
V_49 = F_45 ( V_1 , V_53 . V_56 , & V_137 ) ;
if ( V_49 )
return V_49 ;
V_1 -> V_59 = V_137 & V_138 ;
V_49 = F_44 ( V_1 ) ;
if ( V_49 )
return V_49 ;
}
if ( V_1 -> V_59 > V_139 )
return - V_140 ;
return 0 ;
}
static int F_93 ( struct V_1 * V_1 )
{
int V_49 ;
T_2 V_51 ;
T_2 V_54 ;
T_2 V_127 ;
T_2 V_129 ;
T_2 V_141 ;
T_2 V_142 ;
int V_143 = V_144 ;
int V_145 = V_1 -> V_125 == 0 ;
int V_146 = 0 ;
int V_147 = 30 ;
F_5 ( V_1 ) ;
if ( V_145 ) {
T_2 V_148 ;
V_49 = F_45 ( V_1 , V_127 , & V_148 ) ;
if ( V_49 )
return V_49 ;
V_1 -> V_125 = V_148 & 0x3fff ;
V_1 -> V_125 |= F_94 ( V_1 -> V_125 ) << 16 ;
}
V_49 = F_45 ( V_1 , V_51 , & V_1 -> V_52 ) ;
if ( V_49 )
return V_49 ;
F_95 ( & V_1 -> V_13 -> V_18 , L_33
L_34 , F_91 ( V_1 -> V_52 & V_149 ) ,
V_1 -> V_52 ) ;
switch ( V_1 -> V_52 & V_149 ) {
case V_132 :
V_146 = 0 ;
break;
case V_133 :
case V_131 :
V_1 -> V_52 &= V_150 ;
V_1 -> V_52 |= V_131 ;
V_146 = 10 ;
break;
default:
V_1 -> V_52 &= V_150 ;
V_1 -> V_52 |= V_130 ;
V_146 = 50 ;
break;
}
V_49 = F_90 ( V_1 , V_51 , V_1 -> V_52 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_45 ( V_1 , V_51 , & V_51 ) ;
if ( V_49 )
return V_49 ;
F_96 ( V_146 ) ;
V_49 = F_45 ( V_1 , V_53 . V_56 , & V_142 ) ;
if ( V_49 )
return V_49 ;
if ( ! ( V_142 & V_151 ) ) {
int V_148 ;
for ( V_148 = 0 ; V_148 < V_1 -> V_59 ; V_148 ++ ) {
V_49 = F_90 ( V_1 ,
V_53 . V_61 [ V_148 ] , V_152 ) ;
if ( V_49 )
return V_49 ;
}
}
V_49 = F_45 ( V_1 , V_51 , & V_51 ) ;
if ( V_49 )
return V_49 ;
V_153:
V_49 = F_45 ( V_1 , V_141 , & V_54 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_90 ( V_1 , V_141 , V_154 ) ;
if ( V_49 )
return V_49 ;
V_155: {
V_49 = F_45 ( V_1 , V_141 , & V_54 ) ;
if ( V_49 )
return V_49 ;
if ( 0 != ( V_54 & V_154 ) ) {
if ( -- V_147 == 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_35
L_36 ) ;
return - V_50 ;
} else {
F_96 ( 5 ) ;
goto V_155;
}
}
}
if ( V_1 -> V_156 & V_157 ) {
V_49 = F_90 ( V_1 , V_51 , V_1 -> V_52 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_45 ( V_1 , V_51 , & V_51 ) ;
if ( V_49 )
return V_49 ;
}
V_49 = F_90 ( V_1 , V_158 , 0x00000000 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_90 ( V_1 , V_159 , 0x11000000 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_90 ( V_1 , V_160 , 0x00000000 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_89 ( V_1 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_45 ( V_1 , V_127 , & V_127 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_45 ( V_1 , V_129 , & V_129 ) ;
if ( V_49 )
return V_49 ;
if ( 0 == ( V_127 & 0x3fff0000 ) || 0 == V_129 ) {
if ( ! ( V_1 -> V_156 & V_157 ) ) {
V_1 -> V_156 |= V_157 ;
goto V_153;
} else
F_46 ( & V_1 -> V_13 -> V_18 , L_37
L_38 , V_127 , V_129 ) ;
}
V_1 -> V_52 &= V_150 ;
V_1 -> V_52 |= V_161 | V_162 | V_132 ;
V_49 = F_90 ( V_1 , V_51 , V_1 -> V_52 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_90 ( V_1 , V_141 , V_163 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_45 ( V_1 , V_141 , & V_141 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_45 ( V_1 , V_51 , & V_51 ) ;
if ( V_49 )
return V_49 ;
F_4 ( V_1 ) -> V_8 = V_164 ;
V_49 = F_90 ( V_1 , V_53 . V_54 , V_165 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_90 ( V_1 , V_166 , V_143 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_90 ( V_1 , V_135 ,
V_136 | V_167 | V_168 | V_169 |
V_170 | V_171 | V_172 | V_173 |
V_174 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_45 ( V_1 , V_53 . V_56 , & V_142 ) ;
if ( V_49 )
return V_49 ;
V_142 &= ~ ( V_175 | V_176 ) ;
if ( V_1 -> V_156 & V_177 ) {
V_142 |= V_178 ;
V_142 &= ~ ( V_179 | V_151 ) ;
V_49 = F_90 ( V_1 , V_53 . V_56 , V_142 ) ;
if ( V_49 )
return V_49 ;
} else if ( ( V_1 -> V_156 & V_180 ) || V_181 ) {
V_142 |= V_151 ;
V_49 = F_90 ( V_1 , V_53 . V_56 , V_142 ) ;
if ( V_49 )
return V_49 ;
}
V_49 = F_90 ( V_1 , V_53 . V_54 , V_182 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_90 ( V_1 , V_53 . V_100 ,
( V_142 & V_151 ) ? 0 : V_183 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_45 ( V_1 , V_51 , & V_51 ) ;
if ( V_49 )
return V_49 ;
F_97 ( ( V_142 >> 23 ) & 0x1fe ) ;
F_4 ( V_1 ) -> V_8 = V_164 ;
return 0 ;
}
static void F_98 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_39
L_40 , V_1 , V_6 , V_1 -> V_14 ) ;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_41
L_42 , V_6 ) ;
} else {
F_8 ( & V_1 -> V_65 ) ;
F_96 ( 100 ) ;
F_88 ( V_1 , 0 ) ;
F_10 ( & V_1 -> V_65 ) ;
}
}
static int F_99 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
return - V_50 ;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_13 ) ;
return - V_184 ;
} else if ( V_6 -> V_185 . V_186 ) {
int V_49 ;
struct V_11 * V_12 =
F_100 ( V_6 -> V_185 . V_186 ) ;
T_3 V_187 = ( (struct V_188 * )
F_101 ( & V_12 -> V_18 ) ) -> V_187 ;
T_3 V_189 = ( (struct V_188 * )
F_101 ( & V_12 -> V_18 ) ) -> V_189 ;
F_8 ( & V_1 -> V_65 ) ;
F_96 ( 10 ) ;
if ( V_187 == V_190 && V_189 == 0x740c ) {
V_1 -> V_156 = V_180 ;
} else if ( V_187 == V_191 && V_189 == 0xc861 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_43
L_44 ) ;
} else if ( V_187 == V_192 && V_189 == 0xa0f8 )
V_1 -> V_156 |= V_193 ;
V_49 = F_93 ( V_1 ) ;
if ( V_49 ) {
F_5 ( V_1 ) ;
V_1 -> V_14 = 1 ;
}
F_96 ( 100 ) ;
F_10 ( & V_1 -> V_65 ) ;
return V_49 ;
} else {
F_46 ( & V_1 -> V_13 -> V_18 , L_45 ) ;
return - V_50 ;
}
}
static int F_102 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
return - V_50 ;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_13 ) ;
return - V_184 ;
} else {
int V_49 ;
F_8 ( & V_1 -> V_65 ) ;
V_49 = F_92 ( V_1 ) ;
if ( V_49 ) {
F_5 ( V_1 ) ;
V_1 -> V_14 = 1 ;
}
F_10 ( & V_1 -> V_65 ) ;
return V_49 ;
}
}
static int F_103 ( struct V_1 * V_1 ,
struct V_2 * V_3 , struct V_66 * V_66 ,
struct V_19 * V_194 , T_1 V_20 , T_1 V_29 , T_1 V_30 ,
T_4 V_195 )
{
struct V_22 * V_23 ;
unsigned long V_67 ;
int V_196 ;
T_1 V_32 ;
struct V_27 * V_28 = F_104 ( sizeof( struct V_27 ) , V_195 ) ;
if ( ! V_28 )
return - V_197 ;
F_105 ( & V_28 -> V_69 . V_70 ) ;
F_51 ( & V_28 -> V_69 . V_70 , V_67 ) ;
V_196 = F_106 ( F_4 ( V_1 ) , V_66 ) ;
if ( V_196 ) {
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
F_34 ( V_28 ) ;
return V_196 ;
}
V_32 = ++ V_1 -> V_198 ;
V_66 -> V_199 -> V_46 = V_1 -> V_28 [ V_32 - 1 ] = V_28 ;
F_107 ( & V_28 -> V_26 , F_85 ) ;
F_108 ( & V_28 -> V_75 ) ;
V_23 = V_28 -> V_23 = & V_1 -> V_23 [ 0 ] ;
if ( V_23 -> V_39 ) {
F_109 ( & V_28 -> V_37 , & V_23 -> V_39 -> V_37 ) ;
} else {
F_108 ( & V_28 -> V_37 ) ;
V_23 -> V_39 = V_28 ;
}
V_23 -> V_38 += 1 ;
V_28 -> V_94 = 0 ;
V_28 -> V_116 = 0 ;
V_28 -> V_74 = 0 ;
V_28 -> V_115 = 0 ;
V_28 -> V_32 = V_32 ;
V_28 -> V_1 = V_1 ;
V_28 -> V_34 = V_66 -> V_199 ;
V_28 -> V_117 = F_110 ( V_66 -> V_112 ) ;
F_37 ( V_1 , V_28 ) ;
if ( F_76 ( V_66 -> V_112 ) ) {
V_28 -> V_83 = 0x2 ;
F_67 ( V_3 -> V_19 , V_29 , 0 , 0 ) ;
V_28 -> V_42 = 1 ;
V_28 -> V_44 = 0 ;
V_3 -> V_43 [ V_29 ] = V_32 ;
F_20 ( V_1 , V_3 ) ;
} else {
V_28 -> V_83 = 0x2 ;
F_67 ( V_3 -> V_19 , V_29 , 1 , 0 ) ;
V_28 -> V_42 = 0 ;
V_28 -> V_44 = 1 ;
V_3 -> V_45 [ V_29 ] = V_32 ;
F_20 ( V_1 , V_3 ) ;
}
V_66 -> V_46 = V_1 ;
V_28 -> V_115 = 1 ;
V_28 -> V_104 = V_104 + F_68 ( V_66 -> V_105 ) ;
V_28 -> V_4 = V_30 ;
V_28 -> V_20 = V_20 ;
V_28 -> V_29 = V_29 ;
V_28 -> V_73 = 1 ;
V_28 -> V_80 = 0 ;
V_28 -> V_71 = 0 ;
V_28 -> V_78 [ V_79 & V_28 -> V_80 ++ ] = V_66 ;
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
F_38 ( V_1 , V_28 , F_68 ( V_66 -> V_105 ) ) ;
return 0 ;
}
static int F_111 ( struct V_1 * V_1 ,
struct V_2 * V_3 , struct V_66 * V_66 ,
struct V_19 * V_194 , struct V_27 * V_28 , T_1 V_20 ,
T_1 V_29 , T_1 V_30 )
{
V_66 -> V_46 = V_1 ;
V_28 -> V_115 = 1 ;
V_28 -> V_104 = V_104 + F_68 ( V_66 -> V_105 ) ;
if ( V_28 -> V_73 ++ < V_72 ) {
V_28 -> V_78 [ V_79 & V_28 -> V_80 ++ ] = V_66 ;
} else {
struct V_76 * V_77 = F_104 ( sizeof( struct V_76 ) ,
V_200 ) ;
if ( V_77 == NULL ) {
V_28 -> V_73 -= 1 ;
return - V_197 ;
} else {
F_109 ( & V_77 -> V_75 , & V_28 -> V_75 ) ;
V_77 -> V_66 = V_66 ;
}
}
return 0 ;
}
static int F_112 ( struct V_1 * V_1 ,
struct V_2 * V_3 , struct V_66 * V_66 ,
struct V_19 * V_194 , T_1 V_20 , T_1 V_29 , T_1 V_30 ,
T_4 V_195 )
{
int V_201 ;
struct V_22 * V_23 ;
unsigned long V_67 ;
int V_196 ;
T_1 V_32 ;
struct V_27 * V_28 = F_104 ( sizeof( struct V_27 ) , V_195 ) ;
if ( ! V_28 )
return - V_197 ;
F_105 ( & V_28 -> V_69 . V_70 ) ;
F_51 ( & V_28 -> V_69 . V_70 , V_67 ) ;
V_196 = F_106 ( F_4 ( V_1 ) , V_66 ) ;
if ( V_196 ) {
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
F_34 ( V_28 ) ;
return V_196 ;
}
V_32 = ++ V_1 -> V_198 ;
V_66 -> V_199 -> V_46 = V_1 -> V_28 [ V_32 - 1 ] = V_28 ;
F_107 ( & V_28 -> V_26 , F_85 ) ;
F_108 ( & V_28 -> V_75 ) ;
V_28 -> V_94 = 0 ;
V_28 -> V_116 = 0 ;
V_28 -> V_74 = 0 ;
V_28 -> V_115 = 0 ;
V_28 -> V_32 = V_32 ;
V_28 -> V_1 = V_1 ;
V_28 -> V_34 = V_66 -> V_199 ;
V_28 -> V_117 = F_110 ( V_66 -> V_112 ) ;
F_37 ( V_1 , V_28 ) ;
if ( F_76 ( V_66 -> V_112 ) ) {
V_28 -> V_83 = 0x2 ;
F_67 ( V_3 -> V_19 , V_29 , 0 , 0 ) ;
V_201 = 3 ;
V_28 -> V_42 = 1 ;
V_28 -> V_44 = 0 ;
V_3 -> V_43 [ V_29 ] = V_32 ;
F_20 ( V_1 , V_3 ) ;
} else {
V_28 -> V_83 = 0x2 ;
F_67 ( V_3 -> V_19 , V_29 , 1 , 0 ) ;
V_201 = 2 ;
V_28 -> V_42 = 0 ;
V_28 -> V_44 = 1 ;
V_3 -> V_45 [ V_29 ] = V_32 ;
F_20 ( V_1 , V_3 ) ;
}
V_23 = V_28 -> V_23 = & V_1 -> V_23 [ V_201 - 1 ] ;
if ( V_23 -> V_39 ) {
F_109 ( & V_28 -> V_37 , & V_23 -> V_39 -> V_37 ) ;
} else {
F_108 ( & V_28 -> V_37 ) ;
V_23 -> V_39 = V_28 ;
}
V_23 -> V_38 += 1 ;
V_66 -> V_46 = V_1 ;
V_28 -> V_4 = V_30 ;
V_28 -> V_20 = V_20 ;
V_28 -> V_29 = V_29 ;
V_28 -> V_73 = 1 ;
V_28 -> V_80 = 0 ;
V_28 -> V_71 = 0 ;
V_28 -> V_78 [ V_79 & V_28 -> V_80 ++ ] = V_66 ;
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
F_38 ( V_1 , V_28 , 0 ) ;
return 0 ;
}
static int F_113 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_66 * V_66 ,
struct V_19 * V_194 , struct V_27 * V_28 , T_1 V_20 ,
T_1 V_29 , T_1 V_30 )
{
V_66 -> V_46 = V_1 ;
if ( V_28 -> V_73 ++ < V_72 ) {
V_28 -> V_78 [ V_79 & V_28 -> V_80 ++ ] = V_66 ;
} else {
struct V_76 * V_77 = F_104 ( sizeof( struct V_76 ) ,
V_200 ) ;
if ( V_77 == NULL ) {
V_28 -> V_73 -= 1 ;
return - V_197 ;
} else {
F_109 ( & V_77 -> V_75 , & V_28 -> V_75 ) ;
V_77 -> V_66 = V_66 ;
}
}
return 0 ;
}
static int F_114 ( struct V_1 * V_1 ,
struct V_66 * V_66 ,
struct V_19 * V_194 , T_1 V_20 , T_1 V_29 ,
T_4 V_195 )
{
struct V_22 * V_23 ;
unsigned long V_67 ;
int V_196 ;
T_1 V_32 ;
struct V_27 * V_28 = F_104 ( sizeof( struct V_27 ) , V_195 ) ;
if ( ! V_28 )
return - V_197 ;
F_105 ( & V_28 -> V_69 . V_70 ) ;
F_51 ( & V_28 -> V_69 . V_70 , V_67 ) ;
V_196 = F_106 ( F_4 ( V_1 ) , V_66 ) ;
if ( V_196 ) {
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
F_34 ( V_28 ) ;
return V_196 ;
}
V_32 = ++ V_1 -> V_198 ;
V_66 -> V_199 -> V_46 = V_1 -> V_28 [ V_32 - 1 ] = V_28 ;
F_107 ( & V_28 -> V_26 , F_85 ) ;
F_108 ( & V_28 -> V_75 ) ;
V_23 = V_28 -> V_23 = & V_1 -> V_23 [ 0 ] ;
if ( V_23 -> V_39 ) {
F_109 ( & V_28 -> V_37 , & V_23 -> V_39 -> V_37 ) ;
} else {
F_108 ( & V_28 -> V_37 ) ;
V_23 -> V_39 = V_28 ;
}
V_23 -> V_38 += 1 ;
V_28 -> V_94 = 0 ;
V_28 -> V_116 = 0 ;
V_28 -> V_74 = 0 ;
V_28 -> V_115 = 0 ;
V_28 -> V_32 = V_32 ;
V_28 -> V_1 = V_1 ;
V_28 -> V_34 = V_66 -> V_199 ;
F_37 ( V_1 , V_28 ) ;
F_36 ( V_1 , V_28 ) ;
if ( V_20 == 0 ) {
T_1 V_30 = V_1 -> V_31 [ V_20 ] . V_30 ;
struct V_2 * V_3 = & V_1 -> V_3 [ V_30 ] ;
V_28 -> V_4 = V_30 ;
V_28 -> V_20 = V_20 ;
V_28 -> V_29 = V_29 ;
V_28 -> V_42 = 1 ;
V_28 -> V_44 = 1 ;
V_28 -> V_117 = F_110 ( V_66 -> V_112 ) ;
F_22 ( V_1 , V_3 ) ;
F_20 ( V_1 , V_3 ) ;
V_3 -> V_43 [ V_29 ] = V_32 ;
V_3 -> V_45 [ V_29 ] = V_32 ;
V_66 -> V_46 = V_1 ;
V_28 -> V_73 = 1 ;
V_28 -> V_80 = 0 ;
V_28 -> V_71 = 0 ;
V_28 -> V_78 [ V_79 & V_28 -> V_80 ++ ] = V_66 ;
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
F_38 ( V_1 , V_28 , 0 ) ;
return 0 ;
} else {
T_1 V_30 = V_1 -> V_31 [ V_20 ] . V_30 ;
struct V_2 * V_3 = & V_1 -> V_3 [ V_30 ] ;
V_28 -> V_4 = V_30 ;
V_28 -> V_20 = V_20 ;
V_28 -> V_29 = V_29 ;
V_28 -> V_42 = 1 ;
V_28 -> V_44 = 1 ;
V_28 -> V_117 = F_110 ( V_66 -> V_112 ) ;
F_20 ( V_1 , V_3 ) ;
V_3 -> V_21 = 2 ;
V_3 -> V_43 [ V_29 ] = V_32 ;
V_3 -> V_45 [ V_29 ] = V_32 ;
V_66 -> V_46 = V_1 ;
V_28 -> V_73 = 1 ;
V_28 -> V_80 = 0 ;
V_28 -> V_71 = 0 ;
V_28 -> V_78 [ V_79 & V_28 -> V_80 ++ ] = V_66 ;
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
F_38 ( V_1 , V_28 , 0 ) ;
return 0 ;
}
}
static int F_115 ( struct V_1 * V_1 ,
struct V_66 * V_66 ,
struct V_19 * V_194 , struct V_27 * V_28 , T_1 V_20 ,
T_1 V_29 )
{
if ( V_20 == 0 ) {
if ( F_76 ( V_66 -> V_112 ) ) {
V_66 -> V_46 = V_1 ;
if ( V_28 -> V_73 ++ < V_72 ) {
V_28 -> V_78 [ V_79 &
V_28 -> V_80 ++ ] = V_66 ;
} else {
struct V_76 * V_77 =
F_104 ( sizeof( struct V_76 ) ,
V_200 ) ;
if ( V_77 == NULL ) {
V_28 -> V_73 -= 1 ;
return - V_197 ;
} else {
F_109 ( & V_77 -> V_75 ,
& V_28 -> V_75 ) ;
V_77 -> V_66 = V_66 ;
}
}
return 0 ;
} else {
struct V_202 * V_31 = & V_1 -> V_31 [ V_194 -> V_203 ] ;
int V_58 = V_204 ;
int V_60 = 0 ;
while ( -- V_58 > 0 ) {
struct V_2 * V_3 = & V_1 -> V_3 [ ++ V_60 ] ;
if ( V_3 -> V_19 ) {
continue;
} else {
V_3 -> V_21 = 1 ;
V_1 -> V_31 [ 0 ] . V_30 = V_60 ;
V_28 -> V_4 = V_60 ;
V_3 -> V_4 = V_60 ;
V_3 -> V_20 = V_194 -> V_203 ;
F_22 ( V_1 , V_3 ) ;
V_3 -> V_43 [ V_29 ] =
V_28 -> V_32 ;
F_20 ( V_1 , V_3 ) ;
V_3 -> V_45 [ V_29 ] =
V_28 -> V_32 ;
V_3 -> V_19 = V_194 ;
( ( T_1 * ) ( V_66 -> V_205 ) ) [ 2 ] =
V_31 -> V_30 = V_60 ;
F_20 ( V_1 , V_3 ) ;
break;
}
}
if ( V_58 == 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_46
L_47 ) ;
return - V_140 ;
}
V_66 -> V_46 = V_1 ;
if ( V_28 -> V_73 ++ < V_72 ) {
V_28 -> V_78 [ V_79 &
V_28 -> V_80 ++ ] = V_66 ;
} else {
struct V_76 * V_77 =
F_104 ( sizeof( struct V_76 ) ,
V_200 ) ;
if ( V_77 == NULL ) {
V_28 -> V_73 -= 1 ;
return - V_197 ;
} else {
F_109 ( & V_77 -> V_75 ,
& V_28 -> V_75 ) ;
V_77 -> V_66 = V_66 ;
}
}
return 0 ;
}
} else {
T_1 V_30 = V_1 -> V_31 [ V_20 ] . V_30 ;
struct V_2 * V_3 = & V_1 -> V_3 [ V_30 ] ;
V_66 -> V_46 = V_1 ;
if ( V_3 -> V_21 != 2 )
V_3 -> V_21 = 2 ;
if ( V_28 -> V_73 ++ < V_72 ) {
V_28 -> V_78 [ V_79 & V_28 -> V_80 ++ ] =
V_66 ;
} else {
struct V_76 * V_77 =
F_104 ( sizeof( struct V_76 ) , V_200 ) ;
if ( V_77 == NULL ) {
V_28 -> V_73 -= 1 ;
return - V_197 ;
} else {
F_109 ( & V_77 -> V_75 , & V_28 -> V_75 ) ;
V_77 -> V_66 = V_66 ;
}
}
return 0 ;
}
}
static int F_116 ( struct V_5 * V_6 , struct V_66 * V_66 ,
T_4 V_195 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( F_117 () ) {
if ( F_118 ( V_195 ) ) {
F_119 ( V_206 L_48 ) ;
return - V_140 ;
}
}
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
return - V_50 ;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_14
L_15 , V_66 ) ;
return - V_184 ;
} else {
T_1 V_20 = F_120 ( V_66 -> V_112 ) ;
T_1 V_29 = F_121 ( V_66 -> V_112 ) ;
struct V_19 * V_194 = V_66 -> V_18 ;
if ( F_110 ( V_66 -> V_112 ) == V_118 ) {
T_1 V_30 = V_1 -> V_31 [ V_20 ] . V_30 ;
struct V_2 * V_3 = & V_1 -> V_3 [ V_30 ] ;
struct V_27 * V_28 = V_66 -> V_199 -> V_46 ;
V_66 -> V_99 = 0 ;
if ( V_28 ) {
unsigned long V_67 ;
int V_49 ;
F_51 ( & V_28 -> V_69 . V_70 ,
V_67 ) ;
V_49 = F_106 ( V_6 , V_66 ) ;
if ( V_49 == 0 ) {
V_49 = F_111 (
V_1 , V_3 , V_66 ,
V_194 , V_28 ,
V_20 , V_29 ,
V_30 ) ;
if ( V_49 )
F_52 (
V_6 , V_66 ) ;
}
F_53 ( & V_28 -> V_69 . V_70 ,
V_67 ) ;
if ( V_49 ) {
return V_49 ;
} else {
F_38 ( V_1 , V_28 ,
F_68 ( V_66 -> V_105 ) )
;
return 0 ;
}
} else if ( V_1 -> V_198 == V_207 ) {
return - V_140 ;
} else {
return F_103 ( V_1 , V_3 ,
V_66 , V_194 , V_20 ,
V_29 , V_30 , V_195 ) ;
}
} else if ( F_110 ( V_66 -> V_112 ) == V_208 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_49
L_50 ) ;
return - V_140 ;
} else if ( F_110 ( V_66 -> V_112 ) == V_209 ) {
T_1 V_30 = V_1 -> V_31 [ V_20 ] . V_30 ;
struct V_2 * V_3 = & V_1 -> V_3 [ V_30 ] ;
struct V_27 * V_28 = V_66 -> V_199 -> V_46 ;
V_66 -> V_99 = 0 ;
if ( V_28 ) {
unsigned long V_67 ;
int V_49 ;
F_51 ( & V_28 -> V_69 . V_70 ,
V_67 ) ;
V_49 = F_106 ( V_6 , V_66 ) ;
if ( V_49 == 0 ) {
V_49 = F_113 (
V_1 , V_3 , V_66 ,
V_194 , V_28 ,
V_20 , V_29 ,
V_30 ) ;
if ( V_49 )
F_52 (
V_6 , V_66 ) ;
}
F_53 ( & V_28 -> V_69 . V_70 ,
V_67 ) ;
if ( V_49 ) {
return V_49 ;
} else {
F_38 ( V_1 , V_28 , 0 ) ;
return 0 ;
}
} else if ( V_1 -> V_198 == V_207 ) {
return - V_140 ;
} else
return F_112 ( V_1 ,
V_3 , V_66 , V_194 , V_20 ,
V_29 , V_30 , V_195 ) ;
} else {
struct V_27 * V_28 = V_66 -> V_199 -> V_46 ;
T_3 V_210 = 8 ;
T_1 * V_100 = V_66 -> V_205 ;
int V_60 = 0 ;
char V_93 [ 30 * 3 + 4 ] ;
char * V_211 = V_93 ;
int V_212 = ( sizeof( V_93 ) - 1 ) / 3 ;
int V_213 = 0 ;
V_93 [ 0 ] = 0 ;
while ( V_210 -- > 0 ) {
if ( V_60 > V_212 ) {
} else if ( V_60 ++ < V_212 ) {
int V_214 = sprintf ( V_211 , L_51 , * V_100 ++ ) ;
V_211 += V_214 ;
V_213 += V_214 ;
} else
V_211 += sprintf ( V_211 , L_52 ) ;
}
if ( V_28 ) {
unsigned long V_67 ;
int V_49 ;
F_51 ( & V_28 -> V_69 . V_70 ,
V_67 ) ;
V_49 = F_106 ( V_6 , V_66 ) ;
if ( V_49 == 0 ) {
V_49 = F_115 (
V_1 , V_66 , V_194 ,
V_28 , V_20 ,
V_29 ) ;
if ( V_49 )
F_52 (
V_6 , V_66 ) ;
}
F_53 ( & V_28 -> V_69 . V_70 ,
V_67 ) ;
if ( V_49 ) {
return V_49 ;
} else {
F_38 ( V_1 , V_28 , 0 ) ;
return 0 ;
}
} else if ( V_1 -> V_198 == V_207 ) {
return - V_140 ;
} else
return F_114 ( V_1 ,
V_66 , V_194 , V_20 , V_29 ,
V_195 ) ;
}
}
}
static int F_122 ( struct V_1 * V_1 ,
struct V_27 * V_28 , struct V_66 * V_66 )
{
struct V_76 * V_77 ;
F_83 (urbq, &endp->urb_more, urb_more) {
if ( V_77 -> V_66 == V_66 ) {
struct V_5 * V_6 = F_4 ( V_1 ) ;
F_32 ( & V_77 -> V_75 ) ;
V_28 -> V_73 -= 1 ;
V_66 -> V_68 = 0 ;
F_54 ( V_6 , V_66 , 0 ) ;
return 0 ;
} else
continue;
}
F_46 ( & V_1 -> V_13 -> V_18 , L_53
L_54
L_38 , V_66 , V_28 -> V_32 , V_28 , V_28 -> V_23 -> V_92 ,
V_28 -> V_42 ? 'I' : ' ' , V_28 -> V_44 ? 'O' : ' ' ,
V_28 -> V_29 , V_28 -> V_20 , V_28 -> V_73 ,
V_28 -> V_71 , V_28 -> V_80 ) ;
return - V_140 ;
}
static int F_123 ( struct V_1 * V_1 , struct V_27 * V_28 ,
struct V_66 * V_66 , int V_54 )
{
unsigned long V_67 ;
int V_196 ;
F_51 ( & V_28 -> V_69 . V_70 , V_67 ) ;
V_196 = F_124 ( F_4 ( V_1 ) , V_66 , V_54 ) ;
if ( V_196 ) {
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
return V_196 ;
}
if ( V_28 -> V_73 == 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_55
L_56 , V_66 ,
V_28 -> V_32 , V_28 , V_28 -> V_23 -> V_92 ,
V_28 -> V_42 ? 'I' : ' ' , V_28 -> V_44 ? 'O' : ' ' ,
V_28 -> V_29 , V_28 -> V_20 ) ;
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
return - V_140 ;
}
if ( V_66 == V_28 -> V_78 [ V_79 & V_28 -> V_71 ] ) {
if ( V_28 -> V_74 ) {
V_28 -> V_94 = 1 ;
V_28 -> V_116 = 1 ;
F_38 ( V_1 , V_28 , 0 ) ;
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
return 0 ;
} else {
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
F_56 ( V_1 , V_28 , V_66 , V_54 ) ;
return 0 ;
}
} else {
T_3 V_215 = 0 ;
T_3 V_73 = V_28 -> V_73 ;
T_3 V_216 = V_28 -> V_71 ;
struct V_66 * * V_217 = NULL ;
while ( ++ V_215 < V_72 && -- V_73 > 0 ) {
if ( V_66 == V_28 -> V_78 [ V_79 &
++ V_216 ] ) {
V_217 = & V_28 -> V_78 [ V_79 &
V_216 ] ;
break;
} else
continue;
}
while ( ++ V_215 < V_72 && -- V_73 > 0 ) {
* V_217 = V_28 -> V_78 [ V_79 &
++ V_216 ] ;
V_217 = & V_28 -> V_78 [ V_79 &
V_216 ] ;
}
if ( V_217 ) {
struct V_5 * V_6 = F_4 ( V_1 ) ;
F_52 ( V_6 , V_66 ) ;
V_28 -> V_73 -= 1 ;
if ( F_31 ( & V_28 -> V_75 ) ) {
F_53 ( & V_28 -> V_69 . V_70 ,
V_67 ) ;
} else {
struct V_35 * V_41 = V_28 -> V_75 . V_41 ;
struct V_76 * V_77 = F_33 ( V_41 ,
struct V_76 , V_75 ) ;
F_32 ( V_41 ) ;
* V_217 = V_77 -> V_66 ;
F_53 ( & V_28 -> V_69 . V_70 ,
V_67 ) ;
F_34 ( V_77 ) ;
} V_66 -> V_68 = 0 ;
F_54 ( V_6 , V_66 , V_54 ) ;
return 0 ;
} else if ( F_31 ( & V_28 -> V_75 ) ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_57
L_58
L_59 , V_66 ,
V_28 -> V_32 , V_28 , V_28 -> V_23 -> V_92 ,
V_28 -> V_42 ? 'I' : ' ' ,
V_28 -> V_44 ? 'O' : ' ' , V_28 -> V_29 ,
V_28 -> V_20 , V_28 -> V_73 ,
V_28 -> V_71 , V_28 -> V_80 ) ;
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
return - V_140 ;
} else {
int V_49 ;
F_52 ( F_4 ( V_1 ) , V_66 ) ;
V_49 = F_122 ( V_1 , V_28 ,
V_66 ) ;
F_53 ( & V_28 -> V_69 . V_70 , V_67 ) ;
return V_49 ;
}
}
}
static int F_125 ( struct V_5 * V_6 , struct V_66 * V_66 , int V_54 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_1 -> V_14 > 2 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
return - V_50 ;
} else {
T_1 V_20 = F_120 ( V_66 -> V_112 ) ;
T_1 V_29 = F_121 ( V_66 -> V_112 ) ;
T_1 V_30 = V_1 -> V_31 [ V_20 ] . V_30 ;
struct V_2 * V_3 = & V_1 -> V_3 [ V_30 ] ;
if ( F_76 ( V_66 -> V_112 ) ) {
T_1 V_32 = V_3 -> V_43 [ V_29 ] ;
struct V_27 * V_28 = V_1 -> V_28 [ V_32 - 1 ] ;
return F_123 ( V_1 , V_28 , V_66 , V_54 ) ;
} else {
T_1 V_32 = V_3 -> V_45 [ V_29 ] ;
struct V_27 * V_28 = V_1 -> V_28 [ V_32 - 1 ] ;
return F_123 ( V_1 , V_28 , V_66 , V_54 ) ;
}
}
}
static void F_126 ( struct V_5 * V_6 ,
struct V_33 * V_34 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_1 -> V_14 > 2 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_60
L_61 , V_1 , V_6 , V_34 ,
V_1 -> V_14 ) ;
} else {
struct V_27 * V_28 = V_34 -> V_46 ;
if ( V_28 )
F_35 ( V_1 , V_28 ) ;
}
}
static int F_127 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
return - V_50 ;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_13 ) ;
return - V_184 ;
} else {
int V_218 = 0 ;
F_46 ( & V_1 -> V_13 -> V_18 , L_62 ) ;
F_96 ( 100 ) ;
return V_218 ;
}
}
static int F_128 ( struct V_1 * V_1 ,
struct V_219 * V_220 )
{
int V_49 ;
T_3 V_148 ;
T_2 V_137 = - 1 ;
T_2 V_221 = - 1 ;
V_49 = F_45 ( V_1 , V_53 . V_56 , & V_137 ) ;
if ( V_49 )
return V_49 ;
V_220 -> V_222 = V_223 ;
V_220 -> V_224 = ( V_137 & V_179 ) >> 24 ;
V_220 -> V_225 = 0 ;
V_220 -> V_226 = V_1 -> V_59 ;
V_148 = 1 + ( V_1 -> V_59 / 8 ) ;
V_220 -> V_227 = 7 + 2 * V_148 ;
V_148 = V_228 | V_229 ;
if ( V_137 & V_151 )
V_148 |= V_230 ;
if ( V_137 & V_175 )
V_148 |= V_231 ;
if ( V_137 & V_178 )
V_148 |= V_232 ;
else if ( V_137 & V_176 )
V_148 |= V_233 ;
V_220 -> V_234 = F_129 ( V_148 ) ;
V_49 = F_45 ( V_1 , V_53 . V_100 , & V_221 ) ;
if ( V_49 )
return V_49 ;
memset ( V_220 -> V_97 . V_235 . V_236 , 0xff ,
sizeof( V_220 -> V_97 . V_235 . V_236 ) ) ;
V_220 -> V_97 . V_235 . V_236 [ 0 ] = V_221 & V_237 ;
if ( V_1 -> V_59 > 7 ) {
V_220 -> V_97 . V_235 . V_236 [ 1 ] = ( V_221 & V_237 ) >> 8 ;
V_220 -> V_97 . V_235 . V_236 [ 2 ] = 0xff ;
} else
V_220 -> V_97 . V_235 . V_236 [ 1 ] = 0xff ;
return 0 ;
}
static int F_130 ( struct V_1 * V_1 , T_5 * V_220 )
{
T_2 V_238 = - 1 ;
int V_239 = F_45 ( V_1 , V_53 . V_54 , & V_238 ) ;
* V_220 = F_131 ( V_238 ) ;
return V_239 ;
}
static int F_132 ( struct V_1 * V_1 , T_5 * V_220 , T_3 V_240 )
{
if ( V_240 == 0 || V_240 > V_1 -> V_59 ) {
return - V_140 ;
} else {
int V_122 = V_240 - 1 ;
T_2 V_241 = - 1 ;
int V_242 = F_45 ( V_1 ,
V_53 . V_61 [ V_122 ] , & V_241 ) ;
* V_220 = F_131 ( V_241 ) ;
if ( * ( T_3 * ) ( V_220 + 2 ) ) {
F_95 ( & V_1 -> V_13 -> V_18 , L_63
L_64 , V_122 , * V_220 ) ;
}
return V_242 ;
}
}
static int F_133 ( struct V_1 * V_1 , int V_243 )
{
int V_49 ;
T_2 V_244 ;
T_3 V_245 ;
T_3 V_246 ;
V_49 = F_45 ( V_1 , V_244 , & V_244 ) ;
if ( V_49 )
return V_49 ;
V_245 = V_244 ;
V_246 = V_245 + V_247 ;
do {
T_2 V_248 ;
do {
V_49 = F_45 ( V_1 ,
V_53 . V_61 [ V_243 ] , & V_248 ) ;
if ( V_49 )
return V_49 ;
if ( V_249 & V_248 )
continue;
else
break;
} while ( F_134 ( V_245 , V_246 ) );
if ( V_249 & V_248 )
return - V_50 ;
if ( V_250 & V_248 ) {
if ( V_251 & V_248 ) {
V_49 = F_90 ( V_1 ,
V_53 . V_61 [ V_243 ] ,
V_251 ) ;
if ( V_49 )
return V_49 ;
}
} else
break;
V_49 = F_90 ( V_1 , V_53 . V_61 [ V_243 ] ,
V_249 ) ;
if ( V_49 )
return V_49 ;
F_96 ( V_252 ) ;
V_49 = F_45 ( V_1 , V_244 , & V_244 ) ;
if ( V_49 )
return V_49 ;
V_245 = V_244 ;
} while ( F_134 ( V_245 , V_246 ) );
return 0 ;
}
static int F_135 ( struct V_1 * V_1 , T_3 V_253 ,
T_3 V_240 )
{
if ( V_240 == 0 || V_240 > V_1 -> V_59 ) {
return - V_140 ;
} else {
int V_243 = V_240 - 1 ;
struct V_254 * V_122 = & V_1 -> V_122 [ V_243 ] ;
V_122 -> V_255 &= ~ ( 1 << V_253 ) ;
switch ( V_253 ) {
case V_256 :
return F_90 ( V_1 ,
V_53 . V_61 [ V_243 ] , V_257 ) ;
case V_258 :
return F_90 ( V_1 ,
V_53 . V_61 [ V_243 ] , V_259 ) ;
case V_260 :
return F_133 ( V_1 , V_243 ) ;
default:
return - V_261 ;
}
}
}
static int F_136 ( struct V_1 * V_1 , T_3 V_253 ,
T_3 V_240 )
{
if ( V_240 == 0 || V_240 > V_1 -> V_59 ) {
return - V_140 ;
} else {
int V_243 = V_240 - 1 ;
T_2 V_148 ;
struct V_254 * V_122 = & V_1 -> V_122 [ V_243 ] ;
V_122 -> V_255 &= ~ ( 1 << V_253 ) ;
switch ( V_253 ) {
case V_262 :
V_148 = V_250 ;
break;
case V_263 :
V_148 = V_264 ;
break;
case V_256 :
V_148 = V_265 ;
if ( ( V_1 -> V_52 & V_149 )
!= V_132 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_65
L_66 ) ;
}
break;
case V_266 :
V_148 = V_267 ;
break;
case V_258 :
V_148 = V_152 ;
break;
case V_268 :
V_148 = V_269 ;
break;
case V_270 :
V_148 = V_271 ;
break;
case V_272 :
V_148 = V_251 ;
break;
default:
return - V_261 ;
}
return F_90 ( V_1 , V_53 . V_61 [ V_243 ] ,
V_148 ) ;
}
}
static int F_137 ( struct V_5 * V_6 , char * V_84 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_67
L_68 , V_6 , V_1 -> V_14 ) ;
return - V_50 ;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_41
L_42 , V_6 ) ;
return - V_184 ;
} else {
int V_60 , V_273 = 0 , V_38 = 1 ;
if ( V_1 -> V_156 & V_180 ) {
if ( ( V_1 -> V_57 & V_138 ) > V_274 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_69
L_70 ,
V_1 -> V_57 & V_138 ) ;
goto V_275;
}
}
if ( V_1 -> V_55 & ( V_182 | V_276 ) )
V_84 [ 0 ] = V_273 = 1 ;
else
V_84 [ 0 ] = 0 ;
if ( V_1 -> V_59 > 7 ) {
V_84 [ 1 ] = 0 ;
V_38 ++ ;
}
for ( V_60 = 0 ; V_60 < V_1 -> V_59 ; V_60 ++ ) {
if ( V_1 -> V_62 [ V_60 ] & ( V_269 |
V_264 | V_267 | V_271 |
V_251 ) ) {
V_273 = 1 ;
if ( V_60 < 7 )
V_84 [ 0 ] |= 1 << ( V_60 + 1 ) ;
else
V_84 [ 1 ] |= 1 << ( V_60 - 7 ) ;
continue;
}
if ( ! ( V_1 -> V_62 [ V_60 ] & V_250 ) )
continue;
if ( ( V_1 -> V_62 [ V_60 ] & V_257 ) )
continue;
}
V_275:
return V_273 ? V_38 : 0 ;
}
}
static int F_138 ( struct V_5 * V_6 , T_3 V_277 , T_3 V_253 ,
T_3 V_240 , char * V_84 , T_3 V_278 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
return - V_50 ;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_13 ) ;
return - V_184 ;
} else {
int V_49 = 0 ;
F_8 ( & V_1 -> V_65 ) ;
switch ( V_277 ) {
case V_279 :
switch ( V_253 ) {
case V_280 :
case V_281 :
break;
default:
goto V_282;
}
break;
case V_283 :
switch ( V_253 ) {
case V_280 :
case V_281 :
break;
default:
goto V_282;
}
break;
case V_284 : {
V_49 = F_136 ( V_1 ,
V_253 , V_240 ) ;
if ( V_49 )
goto error;
break;
}
case V_285 : {
V_49 = F_128 ( V_1 ,
(struct V_219 * ) V_84 ) ;
if ( V_49 )
goto error;
break;
}
case V_286 : {
V_49 = F_130 ( V_1 ,
( T_5 * ) V_84 ) ;
if ( V_49 )
goto error;
break;
}
case V_287 : {
V_49 = F_132 ( V_1 ,
( T_5 * ) V_84 , V_240 ) ;
if ( V_49 )
goto error;
break;
}
case V_288 : {
V_49 = F_135 ( V_1 ,
V_253 , V_240 ) ;
if ( V_49 )
goto error;
break;
}
default:
goto V_282;
error:
F_5 ( V_1 ) ;
V_1 -> V_14 = 1 ;
break;
V_282:
V_49 = - V_261 ;
break;
}
F_10 ( & V_1 -> V_65 ) ;
return V_49 ;
}
}
static int F_139 ( struct V_5 * V_6 , unsigned V_289 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
return - V_50 ;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_13 ) ;
return - V_184 ;
} else
return 0 ;
}
static int F_140 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
return - V_50 ;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_13 ) ;
return - V_184 ;
} else
return 0 ;
}
static int F_141 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
return - V_50 ;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_13 ) ;
return - V_184 ;
} else
return 0 ;
}
static int F_142 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = F_143 ( V_12 ) ;
if ( V_6 ) {
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_1 -> V_14 ++ > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_71
L_72 ) ;
return - V_50 ;
} else {
int V_290 = V_291 ;
int V_292 = V_207 ;
F_46 ( & V_1 -> V_13 -> V_18 , L_73
L_74 , V_1 -> V_293 ) ;
F_96 ( 100 ) ;
F_8 ( & V_1 -> V_65 ) ;
F_43 ( V_1 ) ;
while ( V_290 -- > 0 ) {
struct V_22 * V_23 = & V_1 -> V_23 [ V_290 ] ;
F_27 ( V_1 , V_23 ) ;
} while ( V_292 -- > 0 ) {
struct V_27 * V_28 = V_1 -> V_28 [ V_292 ] ;
if ( V_28 )
F_39 ( V_1 , V_28 ) ;
}
V_1 -> V_14 += 1 ;
F_119 ( V_294 L_75 ,
V_1 -> V_293 ) ;
F_10 ( & V_1 -> V_65 ) ;
F_144 ( V_6 ) ;
F_13 ( V_1 ) ;
return 0 ;
}
} else
return 0 ;
}
static void F_145 ( struct V_1 * V_1 , struct V_11 * V_12 )
{
int V_290 = V_291 ;
int V_295 = V_139 ;
int V_296 = V_297 ;
int V_298 = V_204 ;
int V_292 = V_207 ;
V_1 -> V_299 = F_101 ( & V_12 -> V_18 ) ;
V_1 -> V_13 = V_12 ;
V_1 -> V_123 = 0 ;
V_1 -> V_300 = 0 ;
F_146 ( & V_1 -> V_65 ) ;
F_146 ( & V_1 -> V_81 ) ;
while ( V_290 -- > 0 ) {
struct V_22 * V_23 = & V_1 -> V_23 [ V_290 ] ;
V_23 -> V_1 = V_1 ;
V_23 -> V_92 = V_290 + 1 ;
V_23 -> V_38 = 0 ;
V_23 -> V_39 = NULL ;
F_107 ( & V_23 -> V_26 ,
F_82 ) ;
}
F_8 ( & V_1 -> V_65 ) ;
F_107 ( & V_1 -> V_47 , F_47 ) ;
while ( V_295 -- > 0 ) {
struct V_254 * V_122 = & V_1 -> V_122 [ V_295 ] ;
V_122 -> V_1 = V_1 ;
V_122 -> V_300 = 0 ;
V_122 -> V_301 = 0 ;
V_122 -> V_123 = 0 ;
V_122 -> V_255 = 0 ;
}
while ( V_296 -- > 0 ) {
struct V_202 * V_31 = & V_1 -> V_31 [ V_296 ] ;
V_31 -> V_30 = 0 ;
}
while ( V_298 -- > 0 ) {
struct V_2 * V_3 = & V_1 -> V_3 [ V_298 ] ;
int V_60 = F_147 ( V_3 -> V_43 ) ;
int V_302 = F_147 ( V_3 -> V_45 ) ;
V_3 -> V_19 = NULL ;
V_3 -> V_4 = 0 ;
V_3 -> V_20 = 0 ;
V_3 -> V_303 = 0 ;
while ( V_60 -- > 0 )
V_3 -> V_43 [ V_60 ] = 0 ;
while ( V_302 -- > 0 )
V_3 -> V_45 [ V_302 ] = 0 ;
}
while ( V_292 -- > 0 )
V_1 -> V_28 [ V_292 ] = NULL ;
F_10 ( & V_1 -> V_65 ) ;
}
static int F_148 ( struct V_11 * V_12 )
{
struct V_5 * V_6 ;
int V_49 ;
T_2 V_51 ;
T_2 V_137 = - 1 ;
T_2 V_59 ;
F_96 ( 100 ) ;
if ( V_304 > 0 )
return - V_50 ;
V_49 = F_149 ( V_12 , V_135 , V_136 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_150 ( V_12 , V_51 , & V_51 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_150 ( V_12 , V_53 . V_56 , & V_137 ) ;
if ( V_49 )
return V_49 ;
V_59 = V_137 & V_138 ;
if ( V_12 -> V_18 . V_305 )
return - V_140 ;
V_6 = F_151 ( & V_306 , & V_12 -> V_18 , F_152 ( & V_12 -> V_18 ) ) ;
if ( ! V_6 ) {
F_119 ( V_206 L_76
) ;
F_49 ( V_12 ) ;
return - V_197 ;
} else {
struct V_1 * V_1 = F_3 ( V_6 ) ;
V_49 = 0 ;
V_6 -> V_307 = 0 ;
F_8 ( & V_15 ) ;
F_109 ( & V_1 -> V_16 , & V_308 ) ;
V_1 -> V_293 = ++ V_17 ;
F_10 ( & V_15 ) ;
F_15 ( V_1 ) ;
F_145 ( V_1 , V_12 ) ;
V_6 -> V_309 = L_77 ;
V_49 = F_153 ( V_6 , 0 , 0 ) ;
if ( V_49 != 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_78 ,
V_49 ) ;
F_13 ( V_1 ) ;
return V_49 ;
} else {
F_154 ( V_6 -> V_185 . V_186 ) ;
F_41 ( V_1 , 100 ) ;
return 0 ;
}
}
}
static int F_155 ( struct V_11 * V_12 , T_6 V_8 )
{
struct V_5 * V_6 = F_143 ( V_12 ) ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
return - V_50 ;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_13 ) ;
return - V_184 ;
} else {
int V_49 = 0 , V_295 ;
switch ( V_8 . V_310 ) {
case V_311 :
V_49 = F_140 ( V_6 ) ;
break;
case V_312 :
case V_313 :
V_295 = V_139 ;
while ( V_295 -- > 0 ) {
F_87 ( V_1 , V_295 , 0 ) ;
}
break;
}
return V_49 ;
}
}
static int F_156 ( struct V_11 * V_12 )
{
struct V_5 * V_6 = F_143 ( V_12 ) ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_1 -> V_14 > 1 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_12
, V_1 -> V_14 ) ;
return - V_50 ;
} else if ( V_1 -> V_14 > 0 ) {
F_46 ( & V_1 -> V_13 -> V_18 , L_13 ) ;
return - V_184 ;
} else {
int V_49 = 0 ;
if ( ! V_1 -> V_122 [ 0 ] . V_123 ) {
int V_295 = V_139 ;
while ( V_295 -- > 0 ) {
F_87 ( V_1 , V_295 , 1 ) ;
}
V_49 = 0 ;
} else {
V_49 = F_141 ( V_6 ) ;
}
return V_49 ;
}
}
static int T_7 F_157 ( void )
{
int V_49 ;
F_108 ( & V_308 ) ;
V_17 = 0 ;
V_304 = 0 ;
F_146 ( & V_15 ) ;
if ( F_158 () )
return - V_50 ;
F_119 ( V_294 L_79 , V_314 ) ;
V_25 = F_159 ( L_80 ) ;
V_49 = F_160 ( & V_315 ) ;
return V_49 ;
}
static void T_8 F_161 ( void )
{
struct V_1 * V_1 ;
struct V_1 * V_148 ;
F_8 ( & V_15 ) ;
V_304 += 1 ;
F_10 ( & V_15 ) ;
F_162 (u132, temp, &u132_static_list, u132_list) {
F_163 ( V_1 -> V_13 ) ;
}
F_164 ( & V_315 ) ;
F_119 ( V_294 L_81 ) ;
F_165 ( V_316 , V_17 == 0 ) ;
F_166 ( V_25 ) ;
F_167 ( V_25 ) ;
}
