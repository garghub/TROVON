static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , struct V_4 * V_4 )
{
int V_5 = true ;
struct V_6 * V_7 = V_3 -> V_6 ;
V_2 -> V_8 = V_9 ;
if ( ! F_2 () || ! V_4 -> V_7 )
return;
if ( V_7 -> V_10 )
V_5 = V_7 -> V_10 ( V_4 -> V_7 ,
V_4 -> V_11 , V_2 -> V_2 . V_12 ,
V_2 -> V_2 . V_13 ) ;
if ( ! V_5 )
return;
if ( V_2 -> V_2 . V_7 == V_14 ) {
T_1 V_15 ;
int V_16 ;
V_15 = F_3 (
V_3 -> V_17 ,
V_2 -> V_2 . V_12 ,
V_2 -> V_2 . V_13 ,
V_2 -> V_18
? V_19
: V_20 ) ;
V_16 = F_4 ( V_3 -> V_17 , V_15 ) ;
if ( V_16 )
return;
V_2 -> V_2 . V_7 = V_15 ;
V_2 -> V_8 = V_21 ;
} else {
F_5 ( V_3 -> V_17 ,
V_2 -> V_2 . V_7 ,
V_2 -> V_2 . V_13 ,
V_2 -> V_18
? V_19
: V_20 ) ;
V_2 -> V_8 = V_22 ;
}
}
static inline void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_4 * V_4 = V_2 -> V_23 ;
if ( ! F_7 ( V_2 ) || ! V_4 -> V_7 )
return;
if ( V_2 -> V_2 . V_7 == V_14 ) {
F_8 ( V_3 -> V_17 ,
L_1 ) ;
return;
}
if ( V_2 -> V_8 == V_21 ) {
F_9 ( V_3 -> V_17 ,
V_2 -> V_2 . V_7 ,
V_2 -> V_2 . V_13 ,
V_2 -> V_18
? V_19
: V_20 ) ;
V_2 -> V_2 . V_7 = V_14 ;
} else {
F_10 ( V_3 -> V_17 ,
V_2 -> V_2 . V_7 ,
V_2 -> V_2 . V_13 ,
V_2 -> V_18
? V_19
: V_20 ) ;
}
V_2 -> V_8 = V_9 ;
}
void F_11 (
struct V_4 * V_23 ,
struct V_24 * V_2 ,
int V_25 )
__releases( V_23 -> V_3 -> V_26 )
__acquires( V_23 -> V_3 -> V_26 )
{
struct V_1 * V_27 ;
struct V_3 * V_3 ;
int V_28 = V_23 -> V_28 ;
V_27 = F_12 ( V_2 ) ;
F_13 ( & V_27 -> V_29 ) ;
if ( V_27 -> V_2 . V_25 == - V_30 )
V_27 -> V_2 . V_25 = V_25 ;
V_3 = V_27 -> V_3 ;
V_23 -> V_28 = 1 ;
F_14 ( & V_3 -> V_26 ) ;
if ( ! F_4 ( & V_3 -> V_31 . V_32 , V_2 -> V_7 ) )
F_6 ( V_27 , V_3 ) ;
if ( V_2 -> V_25 == 0 )
F_15 ( V_3 -> V_17 , L_2 ,
V_23 -> V_33 . V_34 , V_2 ,
V_27 -> V_2 . V_35 , V_27 -> V_2 . V_13 ) ;
else
F_15 ( V_3 -> V_17 , L_3 ,
V_23 -> V_33 . V_34 , V_2 ,
V_27 -> V_2 . V_35 , V_27 -> V_2 . V_13 ,
V_2 -> V_25 ) ;
V_27 -> V_2 . V_36 ( & V_27 -> V_23 -> V_33 , & V_27 -> V_2 ) ;
F_16 ( & V_3 -> V_26 ) ;
V_23 -> V_28 = V_28 ;
}
static void F_17 ( struct V_4 * V_23 , const int V_25 )
{
struct V_3 * V_3 = V_23 -> V_3 ;
struct V_1 * V_27 = NULL ;
void T_2 * V_37 = V_23 -> V_3 -> V_38 [ V_23 -> V_39 ] . V_40 ;
V_23 -> V_28 = 1 ;
if ( F_2 () && V_23 -> V_7 ) {
struct V_6 * V_41 = V_23 -> V_3 -> V_6 ;
int V_42 ;
if ( V_23 -> V_43 ) {
F_18 ( V_37 , V_44 ,
V_45 | V_46 ) ;
F_18 ( V_37 , V_44 ,
0 | V_46 ) ;
} else {
F_18 ( V_37 , V_47 ,
0 | V_48 ) ;
F_18 ( V_37 , V_47 ,
0 | V_48 ) ;
}
V_42 = V_41 -> V_49 ( V_23 -> V_7 ) ;
F_15 ( V_3 -> V_17 , L_4 ,
V_23 -> V_34 , V_42 ) ;
V_41 -> V_50 ( V_23 -> V_7 ) ;
V_23 -> V_7 = NULL ;
}
while ( ! F_19 ( & V_23 -> V_51 ) ) {
V_27 = F_20 ( & V_23 -> V_51 , struct V_1 , V_29 ) ;
F_11 ( V_23 , & V_27 -> V_2 , V_25 ) ;
}
}
static inline int F_21 ( struct V_3 * V_3 , struct V_4 * V_23 )
{
if ( F_22 ( V_3 , V_23 -> type ) )
return V_23 -> V_52 -> V_53 ;
else
return V_23 -> V_11 ;
}
static void F_23 ( struct V_3 * V_3 , struct V_1 * V_27 )
{
T_3 V_54 = V_27 -> V_54 ;
struct V_4 * V_4 ;
void T_2 * V_37 = V_3 -> V_38 [ V_54 ] . V_40 ;
struct V_24 * V_2 ;
T_4 V_55 = 0 , V_56 ;
int V_57 = 0 ;
V_4 = V_27 -> V_23 ;
if ( ! V_4 -> V_58 ) {
F_15 ( V_3 -> V_17 , L_5 ,
V_4 -> V_33 . V_34 ) ;
return;
}
if ( F_24 ( V_4 -> V_7 ) == V_59 ) {
F_15 ( V_3 -> V_17 , L_6 ) ;
return;
}
V_56 = F_25 ( V_37 , V_44 ) ;
V_2 = & V_27 -> V_2 ;
V_55 = F_26 ( F_21 ( V_3 , V_4 ) ,
( int ) ( V_2 -> V_13 - V_2 -> V_35 ) ) ;
if ( V_56 & V_60 ) {
F_15 ( V_3 -> V_17 , L_7 ,
V_4 -> V_33 . V_34 , V_56 ) ;
return;
}
if ( V_56 & V_61 ) {
F_15 ( V_3 -> V_17 , L_8 ,
V_4 -> V_33 . V_34 , V_56 ) ;
return;
}
F_15 ( V_3 -> V_17 , L_9 ,
V_54 , V_4 -> V_11 , V_55 ,
V_56 ) ;
#ifndef F_27
if ( F_7 ( V_27 ) ) {
struct V_6 * V_41 = V_3 -> V_6 ;
T_5 V_62 ;
V_62 = F_28 ( T_5 , V_2 -> V_13 - V_2 -> V_35 ,
V_4 -> V_7 -> V_63 ) ;
V_57 = ( V_2 -> V_7 != V_14 && V_62 ) ;
#if F_29 ( V_64 ) || F_29 ( V_65 )
{
if ( V_62 < V_4 -> V_11 )
V_4 -> V_7 -> V_66 = 0 ;
else
V_4 -> V_7 -> V_66 = 1 ;
V_57 = V_57 && V_41 -> V_67 (
V_4 -> V_7 , V_4 -> V_11 ,
V_4 -> V_7 -> V_66 ,
V_2 -> V_7 + V_2 -> V_35 , V_62 ) ;
if ( V_57 ) {
if ( V_4 -> V_7 -> V_66 == 0 ) {
V_56 &= ~ ( V_68
| V_69 ) ;
F_18 ( V_37 , V_44 , V_56
| V_70 ) ;
V_56 &= ~ V_45 ;
V_56 |= ( V_69 |
V_71 ) ;
} else {
V_56 |= ( V_69
| V_45
| V_71 ) ;
if ( ! V_4 -> V_72 ||
( V_4 -> V_72 &&
F_22 ( V_3 ,
V_4 -> type ) ) )
V_56 |= V_68 ;
}
V_56 &= ~ V_73 ;
F_18 ( V_37 , V_44 , V_56 ) ;
}
}
#endif
if ( F_30 () ) {
V_56 &= ~ ( V_73 | V_60 ) ;
V_56 |= V_69 | V_45 |
V_71 ;
F_18 ( V_37 , V_44 , ( V_70 &
~ V_73 ) | V_56 ) ;
V_56 = F_25 ( V_37 , V_44 ) ;
V_57 = V_57 && V_41 -> V_67 (
V_4 -> V_7 , V_4 -> V_11 ,
0 ,
V_2 -> V_7 + V_2 -> V_35 ,
V_62 ) ;
if ( ! V_57 ) {
V_41 -> V_50 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
V_56 &= ~ V_69 ;
F_18 ( V_37 , V_44 , V_56 ) ;
}
} else if ( F_31 () )
V_57 = V_57 && V_41 -> V_67 (
V_4 -> V_7 , V_4 -> V_11 ,
V_2 -> V_74 ,
V_2 -> V_7 + V_2 -> V_35 ,
V_62 ) ;
}
#endif
if ( ! V_57 ) {
F_6 ( V_27 , V_3 ) ;
F_32 ( V_4 -> V_52 , V_55 ,
( T_3 * ) ( V_2 -> V_12 + V_2 -> V_35 ) ) ;
V_2 -> V_35 += V_55 ;
V_56 |= V_60 ;
V_56 &= ~ V_73 ;
F_18 ( V_37 , V_44 , V_56 ) ;
}
F_15 ( V_3 -> V_17 , L_10 ,
V_4 -> V_33 . V_34 , V_57 ? L_11 : L_12 ,
V_2 -> V_35 , V_2 -> V_13 ,
F_25 ( V_37 , V_44 ) ,
V_55 ,
F_25 ( V_37 , V_75 ) ) ;
}
void F_33 ( struct V_3 * V_3 , T_3 V_54 )
{
T_4 V_56 ;
struct V_1 * V_27 ;
struct V_24 * V_2 ;
T_3 T_2 * V_76 = V_3 -> V_77 ;
struct V_4 * V_4 = & V_3 -> V_38 [ V_54 ] . V_78 ;
void T_2 * V_37 = V_3 -> V_38 [ V_54 ] . V_40 ;
struct V_79 * V_7 ;
F_34 ( V_76 , V_54 ) ;
V_27 = F_35 ( V_4 ) ;
V_2 = & V_27 -> V_2 ;
V_56 = F_25 ( V_37 , V_44 ) ;
F_15 ( V_3 -> V_17 , L_13 , V_4 -> V_33 . V_34 , V_56 ) ;
V_7 = F_2 () ? V_4 -> V_7 : NULL ;
if ( V_56 & V_80 ) {
V_56 |= V_70 ;
V_56 &= ~ V_80 ;
F_18 ( V_37 , V_44 , V_56 ) ;
return;
}
if ( V_56 & V_73 ) {
V_56 |= V_70 ;
V_56 &= ~ ( V_73 | V_60 ) ;
F_18 ( V_37 , V_44 , V_56 ) ;
F_8 ( V_3 -> V_17 , L_14 ,
V_54 , V_2 ) ;
}
if ( F_24 ( V_7 ) == V_59 ) {
F_15 ( V_3 -> V_17 , L_15 , V_4 -> V_33 . V_34 ) ;
return;
}
if ( V_2 ) {
T_3 V_81 = 0 ;
if ( V_7 && ( V_56 & V_69 ) ) {
V_81 = 1 ;
V_56 |= V_70 ;
V_56 &= ~ ( V_69 | V_73 |
V_60 | V_68 ) ;
F_18 ( V_37 , V_44 , V_56 ) ;
V_56 = F_25 ( V_37 , V_44 ) ;
V_2 -> V_35 += V_4 -> V_7 -> V_82 ;
F_15 ( V_3 -> V_17 , L_16 ,
V_54 , V_56 , V_4 -> V_7 -> V_82 , V_2 ) ;
}
if ( ( V_2 -> V_74 && V_2 -> V_13
&& ( V_2 -> V_13 % V_4 -> V_11 == 0 )
&& ( V_2 -> V_35 == V_2 -> V_13 ) )
#if F_29 ( V_64 ) || F_29 ( V_65 )
|| ( V_81 && ( ! V_7 -> V_66 ||
( V_2 -> V_35 &
( V_4 -> V_11 - 1 ) ) ) )
#endif
) {
if ( V_56 & V_60 )
return;
F_15 ( V_3 -> V_17 , L_17 ) ;
F_18 ( V_37 , V_44 , V_71
| V_60 ) ;
V_2 -> V_74 = 0 ;
}
if ( V_2 -> V_35 == V_2 -> V_13 ) {
F_11 ( V_4 , V_2 , 0 ) ;
F_34 ( V_76 , V_54 ) ;
V_27 = V_4 -> V_58 ? F_35 ( V_4 ) : NULL ;
if ( ! V_27 ) {
F_15 ( V_3 -> V_17 , L_18 ,
V_4 -> V_33 . V_34 ) ;
return;
}
}
F_23 ( V_3 , V_27 ) ;
}
}
static void F_36 ( struct V_3 * V_3 , struct V_1 * V_27 )
{
const T_3 V_54 = V_27 -> V_54 ;
struct V_24 * V_2 = & V_27 -> V_2 ;
struct V_4 * V_4 ;
void T_2 * V_37 = V_3 -> V_38 [ V_54 ] . V_40 ;
unsigned V_83 = 0 ;
T_4 V_55 ;
T_4 V_56 = F_25 ( V_37 , V_47 ) ;
struct V_84 * V_52 = & V_3 -> V_38 [ V_54 ] ;
T_3 V_85 ;
if ( V_52 -> V_86 )
V_4 = & V_52 -> V_78 ;
else
V_4 = & V_52 -> V_87 ;
V_55 = V_4 -> V_11 ;
if ( ! V_4 -> V_58 ) {
F_15 ( V_3 -> V_17 , L_5 ,
V_4 -> V_33 . V_34 ) ;
return;
}
if ( F_24 ( V_4 -> V_7 ) == V_59 ) {
F_15 ( V_3 -> V_17 , L_19 ) ;
return;
}
if ( V_56 & V_88 ) {
F_15 ( V_3 -> V_17 , L_20 ,
V_4 -> V_33 . V_34 , V_56 ) ;
return;
}
if ( F_30 () && F_7 ( V_27 ) ) {
struct V_6 * V_41 = V_3 -> V_6 ;
struct V_79 * V_89 = V_4 -> V_7 ;
if ( V_41 -> V_67 ( V_89 ,
V_4 -> V_11 ,
! V_2 -> V_90 ,
V_2 -> V_7 + V_2 -> V_35 ,
V_2 -> V_13 - V_2 -> V_35 ) ) {
V_56 &= ~ ( V_91
| V_92 ) ;
V_56 |= V_93 | V_94 ;
F_18 ( V_37 , V_47 , V_56 ) ;
return;
}
}
if ( V_56 & V_95 ) {
V_55 = F_25 ( V_37 , V_96 ) ;
if ( V_2 -> V_90 && V_55 == V_4 -> V_11 )
V_85 = 1 ;
else
V_85 = 0 ;
if ( V_2 -> V_35 < V_2 -> V_13 ) {
#ifdef V_64
if ( F_7 ( V_27 ) ) {
struct V_6 * V_41 ;
struct V_79 * V_89 ;
int V_57 = 0 ;
unsigned int V_97 ;
V_41 = V_3 -> V_6 ;
V_89 = V_4 -> V_7 ;
if ( V_85 ) {
V_56 |= V_91 ;
F_18 ( V_37 , V_47 , V_56 ) ;
V_56 |= V_93 ;
F_18 ( V_37 , V_47 , V_56 ) ;
F_18 ( V_37 , V_47 ,
V_56 | V_92 ) ;
F_18 ( V_37 , V_47 , V_56 ) ;
V_97 = F_28 (unsigned int,
request->length -
request->actual,
channel->max_len) ;
V_4 -> V_7 -> V_66 = 1 ;
} else {
if ( ! V_4 -> V_72 &&
V_4 -> V_52 -> V_98 )
V_56 |= V_91 ;
V_56 |= V_93 ;
F_18 ( V_37 , V_47 , V_56 ) ;
V_97 = F_26 ( V_2 -> V_13 - V_2 -> V_35 ,
( unsigned ) V_55 ) ;
V_4 -> V_7 -> V_66 = 0 ;
}
V_57 = V_41 -> V_67 (
V_89 ,
V_4 -> V_11 ,
V_89 -> V_66 ,
V_2 -> V_7
+ V_2 -> V_35 ,
V_97 ) ;
if ( V_57 )
return;
}
#elif F_29 ( V_65 )
if ( ( F_7 ( V_27 ) ) &&
( V_2 -> V_35 < V_2 -> V_13 ) ) {
struct V_6 * V_41 ;
struct V_79 * V_89 ;
unsigned int V_97 = 0 ;
V_41 = V_3 -> V_6 ;
V_89 = V_4 -> V_7 ;
if ( V_55 < V_4 -> V_11 )
V_97 = V_55 ;
else if ( V_2 -> V_90 )
V_97 = F_28 (unsigned int,
request->length -
request->actual,
channel->max_len) ;
else
V_97 = F_28 (unsigned int,
request->length -
request->actual,
(unsigned)fifo_count) ;
V_56 &= ~ V_92 ;
V_56 |= ( V_93 |
V_91 ) ;
F_18 ( V_37 , V_47 , V_56 ) ;
if ( V_97 <= V_4 -> V_11 ) {
V_4 -> V_7 -> V_66 = 0 ;
} else {
V_4 -> V_7 -> V_66 = 1 ;
V_56 |= V_92 ;
F_18 ( V_37 , V_47 , V_56 ) ;
}
if ( V_41 -> V_67 ( V_89 ,
V_4 -> V_11 ,
V_89 -> V_66 ,
V_2 -> V_7
+ V_2 -> V_35 ,
V_97 ) )
return;
}
#endif
V_83 = V_2 -> V_13 - V_2 -> V_35 ;
F_15 ( V_3 -> V_17 , L_21 ,
V_4 -> V_33 . V_34 ,
V_55 , V_83 ,
V_4 -> V_11 ) ;
V_55 = F_28 ( unsigned , V_83 , V_55 ) ;
#ifdef F_37
if ( F_31 () && F_7 ( V_27 ) ) {
struct V_6 * V_41 = V_3 -> V_6 ;
struct V_79 * V_89 = V_4 -> V_7 ;
T_6 V_15 = V_2 -> V_7 + V_2 -> V_35 ;
int V_16 ;
V_16 = V_41 -> V_67 ( V_89 ,
V_4 -> V_11 ,
V_89 -> V_66 ,
V_15 ,
V_55 ) ;
if ( V_16 )
return;
}
#endif
if ( F_7 ( V_27 ) ) {
F_6 ( V_27 , V_3 ) ;
V_56 &= ~ ( V_93 | V_91 ) ;
F_18 ( V_37 , V_47 , V_56 ) ;
}
F_38 ( V_4 -> V_52 , V_55 , ( T_3 * )
( V_2 -> V_12 + V_2 -> V_35 ) ) ;
V_2 -> V_35 += V_55 ;
V_56 |= V_94 ;
V_56 &= ~ V_95 ;
F_18 ( V_37 , V_47 , V_56 ) ;
}
}
if ( V_2 -> V_35 == V_2 -> V_13 ||
V_55 < V_4 -> V_11 )
F_11 ( V_4 , V_2 , 0 ) ;
}
void F_39 ( struct V_3 * V_3 , T_3 V_54 )
{
T_4 V_56 ;
struct V_1 * V_27 ;
struct V_24 * V_2 ;
void T_2 * V_76 = V_3 -> V_77 ;
struct V_4 * V_4 ;
void T_2 * V_37 = V_3 -> V_38 [ V_54 ] . V_40 ;
struct V_79 * V_7 ;
struct V_84 * V_52 = & V_3 -> V_38 [ V_54 ] ;
if ( V_52 -> V_86 )
V_4 = & V_52 -> V_78 ;
else
V_4 = & V_52 -> V_87 ;
F_34 ( V_76 , V_54 ) ;
V_27 = F_35 ( V_4 ) ;
if ( ! V_27 )
return;
V_2 = & V_27 -> V_2 ;
V_56 = F_25 ( V_37 , V_47 ) ;
V_7 = F_2 () ? V_4 -> V_7 : NULL ;
F_15 ( V_3 -> V_17 , L_22 , V_4 -> V_33 . V_34 ,
V_56 , V_7 ? L_23 : L_24 , V_2 ) ;
if ( V_56 & V_99 ) {
V_56 |= V_94 ;
V_56 &= ~ V_99 ;
F_18 ( V_37 , V_47 , V_56 ) ;
return;
}
if ( V_56 & V_100 ) {
V_56 &= ~ V_100 ;
F_18 ( V_37 , V_47 , V_56 ) ;
F_15 ( V_3 -> V_17 , L_25 , V_4 -> V_34 , V_2 ) ;
if ( V_2 -> V_25 == - V_30 )
V_2 -> V_25 = - V_101 ;
}
if ( V_56 & V_102 ) {
F_15 ( V_3 -> V_17 , L_26 , V_4 -> V_33 . V_34 ) ;
}
if ( F_24 ( V_7 ) == V_59 ) {
F_15 ( V_3 -> V_17 , L_27 ,
V_4 -> V_33 . V_34 , V_56 ) ;
return;
}
if ( V_7 && ( V_56 & V_93 ) ) {
V_56 &= ~ ( V_91
| V_93
| V_92 ) ;
F_18 ( V_37 , V_47 ,
V_94 | V_56 ) ;
V_2 -> V_35 += V_4 -> V_7 -> V_82 ;
F_15 ( V_3 -> V_17 , L_28 ,
V_54 , V_56 ,
F_25 ( V_37 , V_47 ) ,
V_4 -> V_7 -> V_82 , V_2 ) ;
#if F_29 ( V_64 ) || F_29 ( F_37 ) || \
F_29 ( V_65 )
if ( ( V_7 -> V_66 == 0 && ! V_52 -> V_98 )
|| ( V_7 -> V_82
& ( V_4 -> V_11 - 1 ) ) ) {
V_56 &= ~ V_95 ;
F_18 ( V_37 , V_47 , V_56 ) ;
}
if ( ( V_2 -> V_35 < V_2 -> V_13 )
&& ( V_4 -> V_7 -> V_82
== V_4 -> V_11 ) ) {
V_56 = F_25 ( V_37 , V_47 ) ;
if ( ( V_56 & V_95 ) &&
V_52 -> V_98 )
goto exit;
return;
}
#endif
F_11 ( V_4 , V_2 , 0 ) ;
F_34 ( V_76 , V_54 ) ;
V_27 = F_35 ( V_4 ) ;
if ( ! V_27 )
return;
}
#if F_29 ( V_64 ) || F_29 ( F_37 ) || \
F_29 ( V_65 )
exit:
#endif
F_36 ( V_3 , V_27 ) ;
}
static int F_40 ( struct V_103 * V_23 ,
const struct V_104 * V_58 )
{
unsigned long V_105 ;
struct V_4 * V_4 ;
struct V_84 * V_52 ;
void T_2 * V_40 ;
struct V_3 * V_3 ;
void T_2 * V_76 ;
T_3 V_54 ;
T_4 V_56 ;
unsigned V_106 ;
int V_25 = - V_107 ;
if ( ! V_23 || ! V_58 )
return - V_107 ;
V_4 = F_41 ( V_23 ) ;
V_52 = V_4 -> V_52 ;
V_40 = V_52 -> V_40 ;
V_3 = V_4 -> V_3 ;
V_76 = V_3 -> V_77 ;
V_54 = V_4 -> V_39 ;
F_42 ( & V_3 -> V_26 , V_105 ) ;
if ( V_4 -> V_58 ) {
V_25 = - V_108 ;
goto V_109;
}
V_4 -> type = F_43 ( V_58 ) ;
if ( F_44 ( V_58 ) != V_54 )
goto V_109;
V_106 = F_45 ( V_58 ) ;
if ( V_106 & ~ 0x07ff ) {
int V_110 ;
if ( F_46 ( V_58 ) )
V_110 = V_3 -> V_111 ;
else
V_110 = V_3 -> V_112 ;
if ( ! V_110 ) {
F_15 ( V_3 -> V_17 , L_29 ) ;
goto V_109;
}
V_4 -> V_72 = ( V_106 >> 11 ) & 3 ;
} else {
V_4 -> V_72 = 0 ;
}
V_4 -> V_11 = V_106 & 0x7ff ;
V_106 = V_4 -> V_11 * ( V_4 -> V_72 + 1 ) ;
F_34 ( V_76 , V_54 ) ;
if ( F_46 ( V_58 ) ) {
if ( V_52 -> V_86 )
V_4 -> V_43 = 1 ;
if ( ! V_4 -> V_43 )
goto V_109;
if ( V_106 > V_52 -> V_53 ) {
F_15 ( V_3 -> V_17 , L_30 ) ;
goto V_109;
}
V_3 -> V_113 |= ( 1 << V_54 ) ;
F_18 ( V_76 , V_114 , V_3 -> V_113 ) ;
if ( V_3 -> V_115 ) {
F_18 ( V_40 , V_75 , V_52 -> V_53 ) ;
} else {
if ( F_22 ( V_3 , V_4 -> type ) )
V_4 -> V_72 = ( V_52 -> V_53 /
V_4 -> V_11 ) - 1 ;
F_18 ( V_40 , V_75 , V_4 -> V_11
| ( V_4 -> V_72 << 11 ) ) ;
}
V_56 = V_71 | V_116 ;
if ( F_25 ( V_40 , V_44 )
& V_117 )
V_56 |= V_46 ;
if ( V_4 -> type == V_118 )
V_56 |= V_119 ;
F_18 ( V_40 , V_44 , V_56 ) ;
F_18 ( V_40 , V_44 , V_56 ) ;
} else {
if ( V_52 -> V_86 )
V_4 -> V_43 = 0 ;
if ( V_4 -> V_43 )
goto V_109;
if ( V_106 > V_52 -> V_120 ) {
F_15 ( V_3 -> V_17 , L_30 ) ;
goto V_109;
}
V_3 -> V_121 |= ( 1 << V_54 ) ;
F_18 ( V_76 , V_122 , V_3 -> V_121 ) ;
if ( V_3 -> V_115 )
F_18 ( V_40 , V_123 , V_52 -> V_53 ) ;
else
F_18 ( V_40 , V_123 , V_4 -> V_11
| ( V_4 -> V_72 << 11 ) ) ;
if ( V_52 -> V_86 ) {
V_56 = F_25 ( V_40 , V_44 ) ;
V_56 &= ~ ( V_71 | V_60 ) ;
F_18 ( V_40 , V_44 , V_56 ) ;
}
V_56 = V_48 | V_124 ;
if ( V_4 -> type == V_118 )
V_56 |= V_125 ;
else if ( V_4 -> type == V_126 )
V_56 |= V_127 ;
F_18 ( V_40 , V_47 , V_56 ) ;
F_18 ( V_40 , V_47 , V_56 ) ;
}
if ( F_2 () && V_3 -> V_6 ) {
struct V_6 * V_41 = V_3 -> V_6 ;
V_4 -> V_7 = V_41 -> V_128 ( V_41 , V_52 ,
( V_58 -> V_129 & V_130 ) ) ;
} else
V_4 -> V_7 = NULL ;
V_4 -> V_58 = V_58 ;
V_4 -> V_28 = 0 ;
V_4 -> V_131 = 0 ;
V_25 = 0 ;
F_47 ( L_31 ,
musb_driver_name, musb_ep->end_point.name,
({ char *s; switch (musb_ep->type) {
case USB_ENDPOINT_XFER_BULK: s = L_32; break;
case USB_ENDPOINT_XFER_INT: s = L_33; break;
default: s = L_34; break;
}; s; }),
musb_ep->is_in ? L_35 : L_36 ,
musb_ep->dma ? L_37 : L_24 ,
musb_ep->packet_sz) ;
F_48 ( & V_3 -> V_132 ) ;
V_109:
F_49 ( & V_3 -> V_26 , V_105 ) ;
return V_25 ;
}
static int F_50 ( struct V_103 * V_23 )
{
unsigned long V_105 ;
struct V_3 * V_3 ;
T_3 V_54 ;
struct V_4 * V_4 ;
void T_2 * V_37 ;
int V_25 = 0 ;
V_4 = F_41 ( V_23 ) ;
V_3 = V_4 -> V_3 ;
V_54 = V_4 -> V_39 ;
V_37 = V_3 -> V_38 [ V_54 ] . V_40 ;
F_42 ( & V_3 -> V_26 , V_105 ) ;
F_34 ( V_3 -> V_77 , V_54 ) ;
if ( V_4 -> V_43 ) {
V_3 -> V_113 &= ~ ( 1 << V_54 ) ;
F_18 ( V_3 -> V_77 , V_114 , V_3 -> V_113 ) ;
F_18 ( V_37 , V_75 , 0 ) ;
} else {
V_3 -> V_121 &= ~ ( 1 << V_54 ) ;
F_18 ( V_3 -> V_77 , V_122 , V_3 -> V_121 ) ;
F_18 ( V_37 , V_123 , 0 ) ;
}
V_4 -> V_58 = NULL ;
V_4 -> V_33 . V_58 = NULL ;
F_17 ( V_4 , - V_133 ) ;
F_48 ( & V_3 -> V_132 ) ;
F_49 ( & ( V_3 -> V_26 ) , V_105 ) ;
F_15 ( V_3 -> V_17 , L_38 , V_4 -> V_33 . V_34 ) ;
return V_25 ;
}
struct V_24 * F_51 ( struct V_103 * V_23 , T_7 V_134 )
{
struct V_4 * V_4 = F_41 ( V_23 ) ;
struct V_3 * V_3 = V_4 -> V_3 ;
struct V_1 * V_2 = NULL ;
V_2 = F_52 ( sizeof *V_2 , V_134 ) ;
if ( ! V_2 ) {
F_15 ( V_3 -> V_17 , L_39 ) ;
return NULL ;
}
V_2 -> V_2 . V_7 = V_14 ;
V_2 -> V_54 = V_4 -> V_39 ;
V_2 -> V_23 = V_4 ;
return & V_2 -> V_2 ;
}
void F_53 ( struct V_103 * V_23 , struct V_24 * V_27 )
{
F_54 ( F_12 ( V_27 ) ) ;
}
void F_55 ( struct V_3 * V_3 , struct V_1 * V_27 )
{
F_15 ( V_3 -> V_17 , L_40 ,
V_27 -> V_18 ? L_41 : L_42 ,
& V_27 -> V_2 , V_27 -> V_2 . V_13 , V_27 -> V_54 ) ;
F_34 ( V_3 -> V_77 , V_27 -> V_54 ) ;
if ( V_27 -> V_18 )
F_23 ( V_3 , V_27 ) ;
else
F_36 ( V_3 , V_27 ) ;
}
static int F_56 ( struct V_103 * V_23 , struct V_24 * V_27 ,
T_7 V_134 )
{
struct V_4 * V_4 ;
struct V_1 * V_2 ;
struct V_3 * V_3 ;
int V_25 = 0 ;
unsigned long V_135 ;
if ( ! V_23 || ! V_27 )
return - V_107 ;
if ( ! V_27 -> V_12 )
return - V_136 ;
V_4 = F_41 ( V_23 ) ;
V_3 = V_4 -> V_3 ;
V_2 = F_12 ( V_27 ) ;
V_2 -> V_3 = V_3 ;
if ( V_2 -> V_23 != V_4 )
return - V_107 ;
F_15 ( V_3 -> V_17 , L_43 , V_23 -> V_34 , V_27 ) ;
V_2 -> V_2 . V_35 = 0 ;
V_2 -> V_2 . V_25 = - V_30 ;
V_2 -> V_54 = V_4 -> V_39 ;
V_2 -> V_18 = V_4 -> V_43 ;
F_1 ( V_2 , V_3 , V_4 ) ;
F_42 ( & V_3 -> V_26 , V_135 ) ;
if ( ! V_4 -> V_58 ) {
F_15 ( V_3 -> V_17 , L_44 ,
V_27 , V_23 -> V_34 , L_45 ) ;
V_25 = - V_133 ;
F_6 ( V_2 , V_3 ) ;
goto V_137;
}
F_57 ( & V_2 -> V_29 , & V_4 -> V_51 ) ;
if ( ! V_4 -> V_28 && & V_2 -> V_29 == V_4 -> V_51 . V_138 )
F_55 ( V_3 , V_2 ) ;
V_137:
F_49 ( & V_3 -> V_26 , V_135 ) ;
return V_25 ;
}
static int F_58 ( struct V_103 * V_23 , struct V_24 * V_2 )
{
struct V_4 * V_4 = F_41 ( V_23 ) ;
struct V_1 * V_27 = F_12 ( V_2 ) ;
struct V_1 * V_139 ;
unsigned long V_105 ;
int V_25 = 0 ;
struct V_3 * V_3 = V_4 -> V_3 ;
if ( ! V_23 || ! V_2 || F_12 ( V_2 ) -> V_23 != V_4 )
return - V_107 ;
F_42 ( & V_3 -> V_26 , V_105 ) ;
F_59 (r, &musb_ep->req_list, list) {
if ( V_139 == V_27 )
break;
}
if ( V_139 != V_27 ) {
F_15 ( V_3 -> V_17 , L_46 , V_2 , V_23 -> V_34 ) ;
V_25 = - V_107 ;
goto V_140;
}
if ( V_4 -> V_51 . V_138 != & V_27 -> V_29 || V_4 -> V_28 )
F_11 ( V_4 , V_2 , - V_141 ) ;
else if ( F_2 () && V_4 -> V_7 ) {
struct V_6 * V_41 = V_3 -> V_6 ;
F_34 ( V_3 -> V_77 , V_4 -> V_39 ) ;
if ( V_41 -> V_49 )
V_25 = V_41 -> V_49 ( V_4 -> V_7 ) ;
else
V_25 = - V_108 ;
if ( V_25 == 0 )
F_11 ( V_4 , V_2 , - V_141 ) ;
} else {
F_11 ( V_4 , V_2 , - V_141 ) ;
}
V_140:
F_49 ( & V_3 -> V_26 , V_105 ) ;
return V_25 ;
}
static int F_60 ( struct V_103 * V_23 , int V_42 )
{
struct V_4 * V_4 = F_41 ( V_23 ) ;
T_3 V_54 = V_4 -> V_39 ;
struct V_3 * V_3 = V_4 -> V_3 ;
void T_2 * V_37 = V_3 -> V_38 [ V_54 ] . V_40 ;
void T_2 * V_76 ;
unsigned long V_105 ;
T_4 V_56 ;
struct V_1 * V_2 ;
int V_25 = 0 ;
if ( ! V_23 )
return - V_107 ;
V_76 = V_3 -> V_77 ;
F_42 ( & V_3 -> V_26 , V_105 ) ;
if ( ( V_118 == V_4 -> type ) ) {
V_25 = - V_107 ;
goto V_140;
}
F_34 ( V_76 , V_54 ) ;
V_2 = F_35 ( V_4 ) ;
if ( V_42 ) {
if ( V_2 ) {
F_15 ( V_3 -> V_17 , L_47 ,
V_23 -> V_34 ) ;
V_25 = - V_142 ;
goto V_140;
}
if ( V_4 -> V_43 ) {
V_56 = F_25 ( V_37 , V_44 ) ;
if ( V_56 & V_117 ) {
F_15 ( V_3 -> V_17 , L_48 , V_23 -> V_34 ) ;
V_25 = - V_142 ;
goto V_140;
}
}
} else
V_4 -> V_131 = 0 ;
F_15 ( V_3 -> V_17 , L_49 , V_23 -> V_34 , V_42 ? L_50 : L_51 ) ;
if ( V_4 -> V_43 ) {
V_56 = F_25 ( V_37 , V_44 ) ;
V_56 |= V_70
| V_116 ;
if ( V_42 )
V_56 |= V_61 ;
else
V_56 &= ~ ( V_61
| V_80 ) ;
V_56 &= ~ V_60 ;
F_18 ( V_37 , V_44 , V_56 ) ;
} else {
V_56 = F_25 ( V_37 , V_47 ) ;
V_56 |= V_94
| V_48
| V_124 ;
if ( V_42 )
V_56 |= V_88 ;
else
V_56 &= ~ ( V_88
| V_99 ) ;
F_18 ( V_37 , V_47 , V_56 ) ;
}
if ( ! V_4 -> V_28 && ! V_42 && V_2 ) {
F_15 ( V_3 -> V_17 , L_52 ) ;
F_55 ( V_3 , V_2 ) ;
}
V_140:
F_49 ( & V_3 -> V_26 , V_105 ) ;
return V_25 ;
}
static int F_61 ( struct V_103 * V_23 )
{
struct V_4 * V_4 = F_41 ( V_23 ) ;
if ( ! V_23 )
return - V_107 ;
V_4 -> V_131 = 1 ;
return F_62 ( V_23 ) ;
}
static int F_63 ( struct V_103 * V_23 )
{
struct V_4 * V_4 = F_41 ( V_23 ) ;
void T_2 * V_37 = V_4 -> V_52 -> V_40 ;
int V_143 = - V_107 ;
if ( V_4 -> V_58 && ! V_4 -> V_43 ) {
struct V_3 * V_3 = V_4 -> V_3 ;
int V_54 = V_4 -> V_39 ;
void T_2 * V_76 = V_3 -> V_77 ;
unsigned long V_105 ;
F_42 ( & V_3 -> V_26 , V_105 ) ;
F_34 ( V_76 , V_54 ) ;
V_143 = F_25 ( V_37 , V_96 ) ;
F_49 ( & V_3 -> V_26 , V_105 ) ;
}
return V_143 ;
}
static void F_64 ( struct V_103 * V_23 )
{
struct V_4 * V_4 = F_41 ( V_23 ) ;
struct V_3 * V_3 = V_4 -> V_3 ;
T_3 V_54 = V_4 -> V_39 ;
void T_2 * V_37 = V_3 -> V_38 [ V_54 ] . V_40 ;
void T_2 * V_76 ;
unsigned long V_105 ;
T_4 V_56 ;
V_76 = V_3 -> V_77 ;
F_42 ( & V_3 -> V_26 , V_105 ) ;
F_34 ( V_76 , ( T_3 ) V_54 ) ;
F_18 ( V_76 , V_114 , V_3 -> V_113 & ~ ( 1 << V_54 ) ) ;
if ( V_4 -> V_43 ) {
V_56 = F_25 ( V_37 , V_44 ) ;
if ( V_56 & V_117 ) {
V_56 |= V_46 | V_70 ;
V_56 &= ~ V_60 ;
F_18 ( V_37 , V_44 , V_56 ) ;
F_18 ( V_37 , V_44 , V_56 ) ;
}
} else {
V_56 = F_25 ( V_37 , V_47 ) ;
V_56 |= V_48 | V_94 ;
F_18 ( V_37 , V_47 , V_56 ) ;
F_18 ( V_37 , V_47 , V_56 ) ;
}
F_18 ( V_76 , V_114 , V_3 -> V_113 ) ;
F_49 ( & V_3 -> V_26 , V_105 ) ;
}
static int F_65 ( struct V_144 * V_145 )
{
struct V_3 * V_3 = F_66 ( V_145 ) ;
return ( int ) F_25 ( V_3 -> V_77 , V_146 ) ;
}
static int F_67 ( struct V_144 * V_145 )
{
struct V_3 * V_3 = F_66 ( V_145 ) ;
void T_2 * V_77 = V_3 -> V_77 ;
unsigned long V_105 ;
int V_25 = - V_107 ;
T_3 V_147 , V_148 ;
int V_149 ;
F_42 ( & V_3 -> V_26 , V_105 ) ;
switch ( V_3 -> V_150 -> V_151 ) {
case V_152 :
if ( V_3 -> V_153 && V_3 -> V_154 )
break;
goto V_140;
case V_155 :
V_148 = F_68 ( V_77 , V_156 ) ;
F_15 ( V_3 -> V_17 , L_53 , V_148 ) ;
V_148 |= V_157 ;
F_69 ( V_77 , V_156 , V_148 ) ;
V_148 = F_68 ( V_77 , V_156 ) ;
V_149 = 100 ;
while ( ! ( V_148 & V_157 ) ) {
V_148 = F_68 ( V_77 , V_156 ) ;
if ( V_149 -- < 1 )
break;
}
V_149 = 10000 ;
while ( V_148 & V_157 ) {
V_148 = F_68 ( V_77 , V_156 ) ;
if ( V_149 -- < 1 )
break;
}
F_49 ( & V_3 -> V_26 , V_105 ) ;
F_70 ( V_3 -> V_150 -> V_158 ) ;
F_42 ( & V_3 -> V_26 , V_105 ) ;
F_71 ( V_3 ,
V_159 + F_72 ( 1 * V_160 ) ) ;
V_25 = 0 ;
goto V_140;
default:
F_15 ( V_3 -> V_17 , L_54 ,
F_73 ( V_3 -> V_150 -> V_151 ) ) ;
goto V_140;
}
V_25 = 0 ;
V_147 = F_68 ( V_77 , V_161 ) ;
V_147 |= V_162 ;
F_69 ( V_77 , V_161 , V_147 ) ;
F_15 ( V_3 -> V_17 , L_55 ) ;
F_74 ( 2 ) ;
V_147 = F_68 ( V_77 , V_161 ) ;
V_147 &= ~ V_162 ;
F_69 ( V_77 , V_161 , V_147 ) ;
V_140:
F_49 ( & V_3 -> V_26 , V_105 ) ;
return V_25 ;
}
static int
F_75 ( struct V_144 * V_145 , int V_163 )
{
struct V_3 * V_3 = F_66 ( V_145 ) ;
V_3 -> V_164 = ! ! V_163 ;
return 0 ;
}
static void F_76 ( struct V_3 * V_3 , int V_165 )
{
T_3 V_147 ;
V_147 = F_68 ( V_3 -> V_77 , V_161 ) ;
if ( V_165 )
V_147 |= V_166 ;
else
V_147 &= ~ V_166 ;
F_15 ( V_3 -> V_17 , L_56 ,
V_165 ? L_57 : L_58 ) ;
F_69 ( V_3 -> V_77 , V_161 , V_147 ) ;
}
static int F_77 ( struct V_144 * V_145 , unsigned V_167 )
{
struct V_3 * V_3 = F_66 ( V_145 ) ;
if ( ! V_3 -> V_150 -> V_168 )
return - V_169 ;
return F_78 ( V_3 -> V_150 , V_167 ) ;
}
static int F_79 ( struct V_144 * V_145 , int V_165 )
{
struct V_3 * V_3 = F_66 ( V_145 ) ;
unsigned long V_105 ;
V_165 = ! ! V_165 ;
F_80 ( V_3 -> V_17 ) ;
F_42 ( & V_3 -> V_26 , V_105 ) ;
if ( V_165 != V_3 -> V_170 ) {
V_3 -> V_170 = V_165 ;
F_76 ( V_3 , V_165 ) ;
}
F_49 ( & V_3 -> V_26 , V_105 ) ;
F_81 ( V_3 -> V_17 ) ;
return 0 ;
}
static void
F_82 ( struct V_3 * V_3 , struct V_4 * V_23 , T_3 V_54 , int V_43 )
{
struct V_84 * V_52 = V_3 -> V_38 + V_54 ;
memset ( V_23 , 0 , sizeof *V_23 ) ;
V_23 -> V_39 = V_54 ;
V_23 -> V_3 = V_3 ;
V_23 -> V_52 = V_52 ;
V_23 -> V_43 = V_43 ;
F_83 ( & V_23 -> V_51 ) ;
sprintf ( V_23 -> V_34 , L_59 , V_54 ,
( ! V_54 || V_52 -> V_86 ) ? L_24 : (
V_43 ? L_60 : L_61 ) ) ;
V_23 -> V_33 . V_34 = V_23 -> V_34 ;
F_83 ( & V_23 -> V_33 . V_171 ) ;
if ( ! V_54 ) {
V_23 -> V_33 . V_172 = 64 ;
V_23 -> V_33 . V_173 = & V_174 ;
V_3 -> V_31 . V_175 = & V_23 -> V_33 ;
} else {
if ( V_43 )
V_23 -> V_33 . V_172 = V_52 -> V_53 ;
else
V_23 -> V_33 . V_172 = V_52 -> V_120 ;
V_23 -> V_33 . V_173 = & V_176 ;
F_57 ( & V_23 -> V_33 . V_171 , & V_3 -> V_31 . V_171 ) ;
}
}
static inline void F_84 ( struct V_3 * V_3 )
{
T_3 V_54 ;
struct V_84 * V_52 ;
unsigned V_177 = 0 ;
F_83 ( & ( V_3 -> V_31 . V_171 ) ) ;
for ( V_54 = 0 , V_52 = V_3 -> V_38 ;
V_54 < V_3 -> V_178 ;
V_54 ++ , V_52 ++ ) {
if ( V_52 -> V_86 ) {
F_82 ( V_3 , & V_52 -> V_78 , V_54 , 0 ) ;
V_177 ++ ;
} else {
if ( V_52 -> V_53 ) {
F_82 ( V_3 , & V_52 -> V_78 ,
V_54 , 1 ) ;
V_177 ++ ;
}
if ( V_52 -> V_120 ) {
F_82 ( V_3 , & V_52 -> V_87 ,
V_54 , 0 ) ;
V_177 ++ ;
}
}
}
}
int F_85 ( struct V_3 * V_3 )
{
int V_25 ;
V_3 -> V_31 . V_173 = & V_179 ;
V_3 -> V_31 . V_180 = V_181 ;
V_3 -> V_31 . V_182 = V_183 ;
F_86 ( V_3 ) ;
V_3 -> V_150 -> V_158 -> V_184 = 0 ;
V_3 -> V_150 -> V_151 = V_155 ;
V_3 -> V_31 . V_34 = V_185 ;
V_3 -> V_31 . V_186 = 1 ;
F_84 ( V_3 ) ;
V_3 -> V_187 = 0 ;
F_71 ( V_3 , 0 ) ;
V_25 = F_87 ( V_3 -> V_17 , & V_3 -> V_31 ) ;
if ( V_25 )
goto V_188;
return 0 ;
V_188:
V_3 -> V_31 . V_32 . V_189 = NULL ;
F_88 ( & V_3 -> V_31 . V_32 ) ;
return V_25 ;
}
void F_89 ( struct V_3 * V_3 )
{
if ( V_3 -> V_190 == V_191 )
return;
F_90 ( & V_3 -> V_31 ) ;
}
static int F_91 ( struct V_144 * V_31 ,
struct V_192 * V_193 )
{
struct V_3 * V_3 = F_66 ( V_31 ) ;
struct V_194 * V_158 = V_3 -> V_150 -> V_158 ;
unsigned long V_105 ;
int V_143 = 0 ;
if ( V_193 -> V_180 < V_181 ) {
V_143 = - V_107 ;
goto V_188;
}
F_80 ( V_3 -> V_17 ) ;
F_15 ( V_3 -> V_17 , L_62 , V_193 -> V_195 ) ;
V_3 -> V_170 = 0 ;
V_3 -> V_196 = V_193 ;
F_42 ( & V_3 -> V_26 , V_105 ) ;
V_3 -> V_187 = 1 ;
F_92 ( V_158 , & V_3 -> V_31 ) ;
V_3 -> V_150 -> V_151 = V_155 ;
F_49 ( & V_3 -> V_26 , V_105 ) ;
F_93 ( V_3 ) ;
if ( V_3 -> V_150 -> V_197 == V_198 )
F_94 ( V_3 , 1 ) ;
if ( V_3 -> V_150 -> V_197 == V_199 )
F_81 ( V_3 -> V_17 ) ;
return 0 ;
V_188:
return V_143 ;
}
static void F_95 ( struct V_3 * V_3 , struct V_192 * V_193 )
{
int V_200 ;
struct V_84 * V_52 ;
if ( V_3 -> V_31 . V_182 == V_183 )
V_193 = NULL ;
else
V_3 -> V_31 . V_182 = V_183 ;
if ( V_3 -> V_170 ) {
V_3 -> V_170 = 0 ;
F_76 ( V_3 , 0 ) ;
}
F_96 ( V_3 ) ;
if ( V_193 ) {
for ( V_200 = 0 , V_52 = V_3 -> V_38 ;
V_200 < V_3 -> V_178 ;
V_200 ++ , V_52 ++ ) {
F_34 ( V_3 -> V_77 , V_200 ) ;
if ( V_52 -> V_86 ) {
F_17 ( & V_52 -> V_78 , - V_133 ) ;
} else {
if ( V_52 -> V_53 )
F_17 ( & V_52 -> V_78 , - V_133 ) ;
if ( V_52 -> V_120 )
F_17 ( & V_52 -> V_87 , - V_133 ) ;
}
}
}
}
static int F_97 ( struct V_144 * V_31 ,
struct V_192 * V_193 )
{
struct V_3 * V_3 = F_66 ( V_31 ) ;
unsigned long V_105 ;
if ( V_3 -> V_150 -> V_197 == V_199 )
F_80 ( V_3 -> V_17 ) ;
F_42 ( & V_3 -> V_26 , V_105 ) ;
F_98 ( V_3 ) ;
( void ) F_77 ( & V_3 -> V_31 , 0 ) ;
V_3 -> V_150 -> V_151 = V_201 ;
F_95 ( V_3 , V_193 ) ;
F_92 ( V_3 -> V_150 -> V_158 , NULL ) ;
F_15 ( V_3 -> V_17 , L_63 ,
V_193 ? V_193 -> V_195 : L_64 ) ;
V_3 -> V_187 = 0 ;
V_3 -> V_196 = NULL ;
F_71 ( V_3 , 0 ) ;
F_49 ( & V_3 -> V_26 , V_105 ) ;
F_81 ( V_3 -> V_17 ) ;
return 0 ;
}
void F_99 ( struct V_3 * V_3 )
{
V_3 -> V_154 = 0 ;
switch ( V_3 -> V_150 -> V_151 ) {
case V_155 :
break;
case V_202 :
case V_152 :
V_3 -> V_187 = 1 ;
if ( V_3 -> V_196 && V_3 -> V_196 -> V_203 ) {
F_14 ( & V_3 -> V_26 ) ;
V_3 -> V_196 -> V_203 ( & V_3 -> V_31 ) ;
F_16 ( & V_3 -> V_26 ) ;
}
break;
default:
F_100 ( L_65 ,
F_73 ( V_3 -> V_150 -> V_151 ) ) ;
}
}
void F_101 ( struct V_3 * V_3 )
{
T_3 V_148 ;
V_148 = F_68 ( V_3 -> V_77 , V_156 ) ;
F_15 ( V_3 -> V_17 , L_66 , V_148 ) ;
switch ( V_3 -> V_150 -> V_151 ) {
case V_155 :
if ( ( V_148 & V_204 ) == V_204 )
V_3 -> V_150 -> V_151 = V_152 ;
break;
case V_152 :
V_3 -> V_154 = 1 ;
if ( V_3 -> V_196 && V_3 -> V_196 -> V_205 ) {
F_14 ( & V_3 -> V_26 ) ;
V_3 -> V_196 -> V_205 ( & V_3 -> V_31 ) ;
F_16 ( & V_3 -> V_26 ) ;
}
break;
default:
F_100 ( L_67 ,
F_73 ( V_3 -> V_150 -> V_151 ) ) ;
}
}
void F_102 ( struct V_3 * V_3 )
{
F_67 ( & V_3 -> V_31 ) ;
}
void F_103 ( struct V_3 * V_3 )
{
void T_2 * V_77 = V_3 -> V_77 ;
T_3 V_148 = F_68 ( V_77 , V_156 ) ;
F_15 ( V_3 -> V_17 , L_66 , V_148 ) ;
F_69 ( V_77 , V_156 , V_148 & V_157 ) ;
( void ) F_77 ( & V_3 -> V_31 , 0 ) ;
V_3 -> V_31 . V_182 = V_183 ;
if ( V_3 -> V_196 && V_3 -> V_196 -> V_206 ) {
F_14 ( & V_3 -> V_26 ) ;
V_3 -> V_196 -> V_206 ( & V_3 -> V_31 ) ;
F_16 ( & V_3 -> V_26 ) ;
}
switch ( V_3 -> V_150 -> V_151 ) {
default:
F_15 ( V_3 -> V_17 , L_68 ,
F_73 ( V_3 -> V_150 -> V_151 ) ) ;
V_3 -> V_150 -> V_151 = V_207 ;
F_104 ( V_3 ) ;
break;
case V_208 :
V_3 -> V_150 -> V_151 = V_209 ;
F_104 ( V_3 ) ;
break;
case V_202 :
case V_210 :
case V_152 :
case V_155 :
V_3 -> V_150 -> V_151 = V_155 ;
break;
case V_211 :
break;
}
V_3 -> V_187 = 0 ;
}
void F_105 ( struct V_3 * V_3 )
__releases( V_3 -> V_26 )
__acquires( V_3 -> V_26 )
{
void T_2 * V_76 = V_3 -> V_77 ;
T_3 V_148 = F_68 ( V_76 , V_156 ) ;
T_3 V_147 ;
F_15 ( V_3 -> V_17 , L_69 ,
( V_148 & V_212 )
? L_70 : L_71 ,
V_3 -> V_196
? V_3 -> V_196 -> V_193 . V_34
: NULL
) ;
if ( V_3 -> V_31 . V_182 != V_183 )
F_103 ( V_3 ) ;
else if ( V_148 & V_213 )
F_69 ( V_76 , V_156 , V_157 ) ;
V_147 = F_68 ( V_76 , V_161 ) ;
V_3 -> V_31 . V_182 = ( V_147 & V_214 )
? V_181 : V_215 ;
V_3 -> V_187 = 1 ;
V_3 -> V_154 = 0 ;
F_86 ( V_3 ) ;
V_3 -> V_216 = 0 ;
V_3 -> V_217 = V_218 ;
V_3 -> V_153 = 0 ;
V_3 -> V_31 . V_219 = 0 ;
V_3 -> V_31 . V_220 = 0 ;
V_3 -> V_31 . V_221 = 0 ;
if ( V_148 & V_212 ) {
V_3 -> V_150 -> V_151 = V_152 ;
V_3 -> V_31 . V_222 = 0 ;
} else {
V_3 -> V_150 -> V_151 = V_208 ;
V_3 -> V_31 . V_222 = 1 ;
}
( void ) F_77 ( & V_3 -> V_31 , 8 ) ;
}
