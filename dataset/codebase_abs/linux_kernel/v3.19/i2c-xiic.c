static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
if ( V_2 -> V_5 == V_6 )
F_2 ( V_4 , V_2 -> V_7 + V_3 ) ;
else
F_2 ( V_4 , V_2 -> V_7 + V_3 + 3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_8 ;
if ( V_2 -> V_5 == V_6 )
V_8 = F_4 ( V_2 -> V_7 + V_3 ) ;
else
V_8 = F_4 ( V_2 -> V_7 + V_3 + 3 ) ;
return V_8 ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_3 , T_2 V_4 )
{
if ( V_2 -> V_5 == V_6 )
F_6 ( V_4 , V_2 -> V_7 + V_3 ) ;
else
F_7 ( V_4 , V_2 -> V_7 + V_3 + 2 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
if ( V_2 -> V_5 == V_6 )
F_9 ( V_4 , V_2 -> V_7 + V_3 ) ;
else
F_10 ( V_4 , V_2 -> V_7 + V_3 ) ;
}
static inline int F_11 ( struct V_1 * V_2 , int V_3 )
{
T_3 V_8 ;
if ( V_2 -> V_5 == V_6 )
V_8 = F_12 ( V_2 -> V_7 + V_3 ) ;
else
V_8 = F_13 ( V_2 -> V_7 + V_3 ) ;
return V_8 ;
}
static inline void F_14 ( struct V_1 * V_2 , T_3 V_9 )
{
T_3 V_10 = F_11 ( V_2 , V_11 ) ;
F_8 ( V_2 , V_11 , V_10 & ~ V_9 ) ;
}
static inline void F_15 ( struct V_1 * V_2 , T_3 V_9 )
{
T_3 V_10 = F_11 ( V_2 , V_11 ) ;
F_8 ( V_2 , V_11 , V_10 | V_9 ) ;
}
static inline void F_16 ( struct V_1 * V_2 , T_3 V_9 )
{
T_3 V_12 = F_11 ( V_2 , V_13 ) ;
F_8 ( V_2 , V_13 , V_12 & V_9 ) ;
}
static inline void F_17 ( struct V_1 * V_2 , T_3 V_9 )
{
F_16 ( V_2 , V_9 ) ;
F_15 ( V_2 , V_9 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_14 ;
for ( V_14 = F_3 ( V_2 , V_15 ) ;
! ( V_14 & V_16 ) ;
V_14 = F_3 ( V_2 , V_15 ) )
F_3 ( V_2 , V_17 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_18 , V_19 ) ;
F_1 ( V_2 , V_20 , V_21 - 1 ) ;
F_1 ( V_2 , V_22 , V_23 ) ;
F_1 ( V_2 , V_22 , V_24 ) ;
F_18 ( V_2 ) ;
F_8 ( V_2 , V_25 , V_26 ) ;
F_17 ( V_2 , V_27 | V_28 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_29 ;
F_8 ( V_2 , V_18 , V_19 ) ;
V_29 = F_3 ( V_2 , V_22 ) ;
F_1 ( V_2 , V_22 , V_29 & ~ V_24 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_1 V_30 ;
int V_31 ;
V_30 = F_3 ( V_2 , V_32 ) + 1 ;
F_22 ( V_2 -> V_33 . V_34 . V_35 ,
L_1 ,
V_36 , V_30 , F_23 ( V_2 ) ,
F_3 ( V_2 , V_15 ) ,
F_3 ( V_2 , V_22 ) ) ;
if ( V_30 > F_23 ( V_2 ) )
V_30 = F_23 ( V_2 ) ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ )
V_2 -> V_37 -> V_38 [ V_2 -> V_39 ++ ] =
F_3 ( V_2 , V_17 ) ;
F_1 ( V_2 , V_20 ,
( F_23 ( V_2 ) > V_21 ) ?
V_21 - 1 : F_23 ( V_2 ) - 1 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
return V_40 - F_3 ( V_2 , V_41 ) - 1 ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 V_42 = F_24 ( V_2 ) ;
int V_43 = F_26 ( V_2 ) ;
V_43 = ( V_43 > V_42 ) ? V_42 : V_43 ;
F_22 ( V_2 -> V_33 . V_34 . V_35 , L_2 ,
V_36 , V_43 , V_42 ) ;
while ( V_43 -- ) {
T_2 V_44 = V_2 -> V_45 -> V_38 [ V_2 -> V_46 ++ ] ;
if ( ( F_26 ( V_2 ) == 0 ) && ( V_2 -> V_47 == 1 ) ) {
V_44 |= V_48 ;
F_22 ( V_2 -> V_33 . V_34 . V_35 , L_3 , V_36 ) ;
}
F_5 ( V_2 , V_49 , V_44 ) ;
}
}
static void F_27 ( struct V_1 * V_2 , int V_50 )
{
V_2 -> V_45 = NULL ;
V_2 -> V_37 = NULL ;
V_2 -> V_47 = 0 ;
V_2 -> V_51 = V_50 ;
F_28 ( & V_2 -> V_52 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
T_3 V_53 , V_12 , V_10 ;
T_3 V_54 = 0 ;
V_12 = F_11 ( V_2 , V_13 ) ;
V_10 = F_11 ( V_2 , V_11 ) ;
V_53 = V_12 & V_10 ;
F_22 ( V_2 -> V_33 . V_34 . V_35 , L_4 ,
V_36 , V_10 , V_12 , V_53 ) ;
F_22 ( V_2 -> V_33 . V_34 . V_35 , L_5 ,
V_36 , F_3 ( V_2 , V_15 ) ,
V_2 -> V_45 , V_2 -> V_47 ) ;
if ( ! V_53 )
return;
if ( ( V_53 & V_28 ) ||
( ( V_53 & V_55 ) &&
! ( V_53 & V_56 ) ) ) {
F_22 ( V_2 -> V_33 . V_34 . V_35 , L_6 , V_36 ) ;
F_19 ( V_2 ) ;
if ( V_2 -> V_45 )
F_27 ( V_2 , V_57 ) ;
} else if ( V_53 & V_56 ) {
V_54 = V_56 ;
if ( ! V_2 -> V_37 ) {
F_22 ( V_2 -> V_33 . V_34 . V_35 ,
L_7 , V_36 ) ;
F_18 ( V_2 ) ;
goto V_58;
}
F_21 ( V_2 ) ;
if ( F_23 ( V_2 ) == 0 ) {
V_2 -> V_37 = NULL ;
V_54 |= ( V_12 & V_55 ) ;
F_22 ( V_2 -> V_33 . V_34 . V_35 ,
L_8 ,
V_36 , V_2 -> V_47 ) ;
if ( V_2 -> V_47 > 1 ) {
V_2 -> V_47 -- ;
V_2 -> V_45 ++ ;
F_22 ( V_2 -> V_33 . V_34 . V_35 ,
L_9 , V_36 ) ;
F_30 ( V_2 ) ;
}
}
} else if ( V_53 & V_59 ) {
V_54 = V_59 ;
F_14 ( V_2 , V_59 ) ;
if ( ! V_2 -> V_45 )
goto V_58;
if ( ( V_2 -> V_47 == 1 ) && ! V_2 -> V_37 &&
F_26 ( V_2 ) == 0 )
F_27 ( V_2 , V_60 ) ;
else
F_27 ( V_2 , V_57 ) ;
} else if ( V_53 & ( V_61 | V_62 ) ) {
V_54 = V_53 &
( V_61 | V_62 ) ;
if ( ! V_2 -> V_45 ) {
F_22 ( V_2 -> V_33 . V_34 . V_35 ,
L_10 , V_36 ) ;
goto V_58;
}
F_25 ( V_2 ) ;
if ( ! F_26 ( V_2 ) && F_24 ( V_2 ) >= 2 ) {
F_22 ( V_2 -> V_33 . V_34 . V_35 ,
L_11 ,
V_36 , V_2 -> V_47 ) ;
if ( V_2 -> V_47 > 1 ) {
V_2 -> V_47 -- ;
V_2 -> V_45 ++ ;
F_30 ( V_2 ) ;
} else {
F_14 ( V_2 , V_62 ) ;
F_22 ( V_2 -> V_33 . V_34 . V_35 ,
L_12 ,
V_36 ) ;
}
} else if ( ! F_26 ( V_2 ) && ( V_2 -> V_47 == 1 ) )
F_14 ( V_2 , V_62 ) ;
} else {
F_31 ( V_2 -> V_33 . V_34 . V_35 , L_13 ,
V_36 ) ;
V_54 = V_53 ;
}
V_58:
F_22 ( V_2 -> V_33 . V_34 . V_35 , L_14 , V_36 , V_54 ) ;
F_8 ( V_2 , V_13 , V_54 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_1 V_14 = F_3 ( V_2 , V_15 ) ;
return ( V_14 & V_63 ) ? - V_64 : 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_65 = 3 ;
int V_66 ;
if ( V_2 -> V_45 )
return - V_64 ;
V_66 = F_32 ( V_2 ) ;
while ( V_66 && V_65 -- ) {
F_34 ( 1 ) ;
V_66 = F_32 ( V_2 ) ;
}
return V_66 ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 V_67 ;
struct V_68 * V_69 = V_2 -> V_37 = V_2 -> V_45 ;
F_17 ( V_2 , V_56 | V_55 ) ;
V_67 = V_69 -> V_43 ;
if ( V_67 > V_21 )
V_67 = V_21 ;
F_1 ( V_2 , V_20 , V_67 - 1 ) ;
if ( ! ( V_69 -> V_70 & V_71 ) )
F_5 ( V_2 , V_49 ,
( V_69 -> V_72 << 1 ) | V_73 |
V_74 ) ;
F_17 ( V_2 , V_59 ) ;
F_5 ( V_2 , V_49 ,
V_69 -> V_43 | ( ( V_2 -> V_47 == 1 ) ? V_48 : 0 ) ) ;
if ( V_2 -> V_47 == 1 )
F_17 ( V_2 , V_59 ) ;
V_2 -> V_46 = V_69 -> V_43 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = V_2 -> V_45 ;
F_16 ( V_2 , V_55 ) ;
F_22 ( V_2 -> V_33 . V_34 . V_35 , L_15 ,
V_36 , V_69 , V_69 -> V_43 ) ;
F_22 ( V_2 -> V_33 . V_34 . V_35 , L_16 ,
V_36 , F_11 ( V_2 , V_13 ) ,
F_3 ( V_2 , V_22 ) ) ;
if ( ! ( V_69 -> V_70 & V_71 ) ) {
T_2 V_44 = ( ( V_69 -> V_72 << 1 ) & 0xfe ) | V_75 |
V_74 ;
if ( ( V_2 -> V_47 == 1 ) && V_69 -> V_43 == 0 )
V_44 |= V_48 ;
F_5 ( V_2 , V_49 , V_44 ) ;
}
F_25 ( V_2 ) ;
F_17 ( V_2 , V_61 | V_55 |
V_59 ) ;
}
static T_4 F_37 ( int V_76 , void * V_77 )
{
struct V_1 * V_2 = V_77 ;
F_38 ( & V_2 -> V_78 ) ;
F_8 ( V_2 , V_25 , 0 ) ;
F_22 ( V_2 -> V_33 . V_34 . V_35 , L_17 , V_36 ) ;
F_29 ( V_2 ) ;
F_8 ( V_2 , V_25 , V_26 ) ;
F_39 ( & V_2 -> V_78 ) ;
return V_79 ;
}
static void F_30 ( struct V_1 * V_2 )
{
int V_80 = 1 ;
int V_42 = F_24 ( V_2 ) ;
F_22 ( V_2 -> V_33 . V_34 . V_35 , L_18 ,
V_36 , V_2 -> V_45 , V_42 ) ;
if ( ! V_2 -> V_45 )
return;
V_2 -> V_39 = 0 ;
V_2 -> V_46 = 0 ;
V_2 -> V_51 = V_81 ;
while ( ( V_42 >= 2 ) && ( V_80 || ( V_2 -> V_47 > 1 ) ) ) {
if ( ! V_80 ) {
V_2 -> V_47 -- ;
V_2 -> V_45 ++ ;
V_2 -> V_46 = 0 ;
} else
V_80 = 0 ;
if ( V_2 -> V_45 -> V_70 & V_82 ) {
F_35 ( V_2 ) ;
return;
} else {
F_36 ( V_2 ) ;
if ( F_26 ( V_2 ) != 0 ) {
break;
}
}
V_42 = F_24 ( V_2 ) ;
}
if ( V_2 -> V_47 > 1 || F_26 ( V_2 ) )
F_17 ( V_2 , V_62 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
unsigned long V_70 ;
F_41 ( & V_2 -> V_78 , V_70 ) ;
F_19 ( V_2 ) ;
F_8 ( V_2 , V_25 , 0 ) ;
F_42 ( & V_2 -> V_78 , V_70 ) ;
F_30 ( V_2 ) ;
F_8 ( V_2 , V_25 , V_26 ) ;
}
static int F_43 ( struct V_83 * V_33 , struct V_68 * V_84 , int V_85 )
{
struct V_1 * V_2 = F_44 ( V_33 ) ;
int V_66 ;
F_22 ( V_33 -> V_34 . V_35 , L_19 , V_36 ,
F_3 ( V_2 , V_15 ) ) ;
V_66 = F_33 ( V_2 ) ;
if ( V_66 )
return V_66 ;
V_2 -> V_45 = V_84 ;
V_2 -> V_47 = V_85 ;
F_40 ( V_2 ) ;
if ( F_45 ( V_2 -> V_52 , ( V_2 -> V_51 == V_57 ) ||
( V_2 -> V_51 == V_60 ) , V_86 ) )
return ( V_2 -> V_51 == V_60 ) ? V_85 : - V_87 ;
else {
V_2 -> V_45 = NULL ;
V_2 -> V_37 = NULL ;
V_2 -> V_47 = 0 ;
return - V_88 ;
}
}
static T_3 F_46 ( struct V_83 * V_33 )
{
return V_89 | V_90 ;
}
static int F_47 ( struct V_91 * V_92 )
{
struct V_1 * V_2 ;
struct V_93 * V_94 ;
struct V_95 * V_96 ;
int V_8 , V_76 ;
T_1 V_31 ;
T_3 V_14 ;
V_2 = F_48 ( & V_92 -> V_34 , sizeof( * V_2 ) , V_97 ) ;
if ( ! V_2 )
return - V_98 ;
V_96 = F_49 ( V_92 , V_99 , 0 ) ;
V_2 -> V_7 = F_50 ( & V_92 -> V_34 , V_96 ) ;
if ( F_51 ( V_2 -> V_7 ) )
return F_52 ( V_2 -> V_7 ) ;
V_76 = F_53 ( V_92 , 0 ) ;
if ( V_76 < 0 )
return V_76 ;
V_94 = F_54 ( & V_92 -> V_34 ) ;
F_55 ( V_92 , V_2 ) ;
V_2 -> V_33 = V_100 ;
F_56 ( & V_2 -> V_33 , V_2 ) ;
V_2 -> V_33 . V_34 . V_35 = & V_92 -> V_34 ;
V_2 -> V_33 . V_34 . V_101 = V_92 -> V_34 . V_101 ;
F_57 ( & V_2 -> V_78 ) ;
F_58 ( & V_2 -> V_52 ) ;
V_8 = F_59 ( & V_92 -> V_34 , V_76 , F_37 , 0 , V_92 -> V_102 , V_2 ) ;
if ( V_8 < 0 ) {
F_31 ( & V_92 -> V_34 , L_20 ) ;
return V_8 ;
}
V_2 -> V_5 = V_6 ;
F_8 ( V_2 , V_22 , V_23 ) ;
V_14 = F_11 ( V_2 , V_15 ) ;
if ( ! ( V_14 & V_103 ) )
V_2 -> V_5 = V_104 ;
F_19 ( V_2 ) ;
V_8 = F_60 ( & V_2 -> V_33 ) ;
if ( V_8 ) {
F_31 ( & V_92 -> V_34 , L_21 ) ;
F_20 ( V_2 ) ;
return V_8 ;
}
if ( V_94 ) {
for ( V_31 = 0 ; V_31 < V_94 -> V_105 ; V_31 ++ )
F_61 ( & V_2 -> V_33 , V_94 -> V_106 + V_31 ) ;
}
return 0 ;
}
static int F_62 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_63 ( V_92 ) ;
F_64 ( & V_2 -> V_33 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
