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
F_15 ( V_27 ) ;
F_16 ( & V_27 -> V_23 -> V_33 , & V_27 -> V_2 ) ;
F_17 ( & V_3 -> V_26 ) ;
V_23 -> V_28 = V_28 ;
}
static void F_18 ( struct V_4 * V_23 , const int V_25 )
{
struct V_3 * V_3 = V_23 -> V_3 ;
struct V_1 * V_27 = NULL ;
void T_2 * V_34 = V_23 -> V_3 -> V_35 [ V_23 -> V_36 ] . V_37 ;
V_23 -> V_28 = 1 ;
if ( F_2 () && V_23 -> V_7 ) {
struct V_6 * V_38 = V_23 -> V_3 -> V_6 ;
int V_39 ;
if ( V_23 -> V_40 ) {
F_19 ( V_34 , V_41 ,
V_42 | V_43 ) ;
F_19 ( V_34 , V_41 ,
0 | V_43 ) ;
} else {
F_19 ( V_34 , V_44 ,
0 | V_45 ) ;
F_19 ( V_34 , V_44 ,
0 | V_45 ) ;
}
V_39 = V_38 -> V_46 ( V_23 -> V_7 ) ;
F_20 ( V_3 , L_2 , V_23 -> V_47 , V_39 ) ;
V_38 -> V_48 ( V_23 -> V_7 ) ;
V_23 -> V_7 = NULL ;
}
while ( ! F_21 ( & V_23 -> V_49 ) ) {
V_27 = F_22 ( & V_23 -> V_49 , struct V_1 , V_29 ) ;
F_11 ( V_23 , & V_27 -> V_2 , V_25 ) ;
}
}
static inline int F_23 ( struct V_3 * V_3 , struct V_4 * V_23 )
{
if ( F_24 ( V_3 , V_23 -> type ) )
return V_23 -> V_50 -> V_51 ;
else
return V_23 -> V_11 ;
}
static void F_25 ( struct V_3 * V_3 , struct V_1 * V_27 )
{
T_3 V_52 = V_27 -> V_52 ;
struct V_4 * V_4 ;
void T_2 * V_34 = V_3 -> V_35 [ V_52 ] . V_37 ;
struct V_24 * V_2 ;
T_4 V_53 = 0 , V_54 ;
int V_55 = 0 ;
V_4 = V_27 -> V_23 ;
if ( ! V_4 -> V_56 ) {
F_20 ( V_3 , L_3 ,
V_4 -> V_33 . V_47 ) ;
return;
}
if ( F_26 ( V_4 -> V_7 ) == V_57 ) {
F_20 ( V_3 , L_4 ) ;
return;
}
V_54 = F_27 ( V_34 , V_41 ) ;
V_2 = & V_27 -> V_2 ;
V_53 = F_28 ( F_23 ( V_3 , V_4 ) ,
( int ) ( V_2 -> V_13 - V_2 -> V_58 ) ) ;
if ( V_54 & V_59 ) {
F_20 ( V_3 , L_5 ,
V_4 -> V_33 . V_47 , V_54 ) ;
return;
}
if ( V_54 & V_60 ) {
F_20 ( V_3 , L_6 ,
V_4 -> V_33 . V_47 , V_54 ) ;
return;
}
F_20 ( V_3 , L_7 ,
V_52 , V_4 -> V_11 , V_53 ,
V_54 ) ;
#ifndef F_29
if ( F_7 ( V_27 ) ) {
struct V_6 * V_38 = V_3 -> V_6 ;
T_5 V_61 ;
V_61 = F_30 ( T_5 , V_2 -> V_13 - V_2 -> V_58 ,
V_4 -> V_7 -> V_62 ) ;
V_55 = ( V_2 -> V_7 != V_14 && V_61 ) ;
if ( F_31 ( V_3 ) || F_32 ( V_3 ) ) {
if ( V_61 < V_4 -> V_11 )
V_4 -> V_7 -> V_63 = 0 ;
else
V_4 -> V_7 -> V_63 = 1 ;
V_55 = V_55 && V_38 -> V_64 (
V_4 -> V_7 , V_4 -> V_11 ,
V_4 -> V_7 -> V_63 ,
V_2 -> V_7 + V_2 -> V_58 , V_61 ) ;
if ( V_55 ) {
if ( V_4 -> V_7 -> V_63 == 0 ) {
V_54 &= ~ ( V_65
| V_66 ) ;
F_19 ( V_34 , V_41 , V_54
| V_67 ) ;
V_54 &= ~ V_42 ;
V_54 |= ( V_66 |
V_68 ) ;
} else {
V_54 |= ( V_66
| V_42
| V_68 ) ;
if ( ! V_4 -> V_69 ||
F_24 ( V_3 ,
V_4 -> type ) )
V_54 |= V_65 ;
}
V_54 &= ~ V_70 ;
F_19 ( V_34 , V_41 , V_54 ) ;
}
}
if ( F_33 ( V_3 ) ) {
V_54 &= ~ ( V_70 | V_59 ) ;
V_54 |= V_66 | V_42 |
V_68 ;
F_19 ( V_34 , V_41 , ( V_67 &
~ V_70 ) | V_54 ) ;
V_54 = F_27 ( V_34 , V_41 ) ;
V_55 = V_55 && V_38 -> V_64 (
V_4 -> V_7 , V_4 -> V_11 ,
0 ,
V_2 -> V_7 + V_2 -> V_58 ,
V_61 ) ;
if ( ! V_55 ) {
V_38 -> V_48 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
V_54 &= ~ V_66 ;
F_19 ( V_34 , V_41 , V_54 ) ;
}
} else if ( F_34 ( V_3 ) )
V_55 = V_55 && V_38 -> V_64 (
V_4 -> V_7 , V_4 -> V_11 ,
V_2 -> V_71 ,
V_2 -> V_7 + V_2 -> V_58 ,
V_61 ) ;
}
#endif
if ( ! V_55 ) {
F_6 ( V_27 , V_3 ) ;
F_35 ( V_4 -> V_50 , V_53 ,
( T_3 * ) ( V_2 -> V_12 + V_2 -> V_58 ) ) ;
V_2 -> V_58 += V_53 ;
V_54 |= V_59 ;
V_54 &= ~ V_70 ;
F_19 ( V_34 , V_41 , V_54 ) ;
}
F_20 ( V_3 , L_8 ,
V_4 -> V_33 . V_47 , V_55 ? L_9 : L_10 ,
V_2 -> V_58 , V_2 -> V_13 ,
F_27 ( V_34 , V_41 ) ,
V_53 ,
F_27 ( V_34 , V_72 ) ) ;
}
void F_36 ( struct V_3 * V_3 , T_3 V_52 )
{
T_4 V_54 ;
struct V_1 * V_27 ;
struct V_24 * V_2 ;
T_3 T_2 * V_73 = V_3 -> V_74 ;
struct V_4 * V_4 = & V_3 -> V_35 [ V_52 ] . V_75 ;
void T_2 * V_34 = V_3 -> V_35 [ V_52 ] . V_37 ;
struct V_76 * V_7 ;
F_37 ( V_73 , V_52 ) ;
V_27 = F_38 ( V_4 ) ;
V_2 = & V_27 -> V_2 ;
F_39 ( V_27 ) ;
V_54 = F_27 ( V_34 , V_41 ) ;
F_20 ( V_3 , L_11 , V_4 -> V_33 . V_47 , V_54 ) ;
V_7 = F_2 () ? V_4 -> V_7 : NULL ;
if ( V_54 & V_77 ) {
V_54 |= V_67 ;
V_54 &= ~ V_77 ;
F_19 ( V_34 , V_41 , V_54 ) ;
return;
}
if ( V_54 & V_70 ) {
V_54 |= V_67 ;
V_54 &= ~ ( V_70 | V_59 ) ;
F_19 ( V_34 , V_41 , V_54 ) ;
F_8 ( V_3 -> V_17 , L_12 ,
V_52 , V_2 ) ;
}
if ( F_26 ( V_7 ) == V_57 ) {
F_20 ( V_3 , L_13 , V_4 -> V_33 . V_47 ) ;
return;
}
if ( V_2 ) {
T_3 V_78 = 0 ;
bool V_79 = false ;
if ( V_7 && ( V_54 & V_66 ) ) {
V_78 = 1 ;
V_54 |= V_67 ;
V_54 &= ~ ( V_66 | V_70 |
V_59 | V_65 ) ;
F_19 ( V_34 , V_41 , V_54 ) ;
V_54 = F_27 ( V_34 , V_41 ) ;
V_2 -> V_58 += V_4 -> V_7 -> V_80 ;
F_20 ( V_3 , L_14 ,
V_52 , V_54 , V_4 -> V_7 -> V_80 , V_2 ) ;
}
if ( ( V_2 -> V_71 && V_2 -> V_13 )
&& ( V_2 -> V_13 % V_4 -> V_11 == 0 )
&& ( V_2 -> V_58 == V_2 -> V_13 ) )
V_79 = true ;
if ( ( F_31 ( V_3 ) || F_32 ( V_3 ) ) &&
( V_78 && ( ! V_7 -> V_63 ||
( V_2 -> V_58 &
( V_4 -> V_11 - 1 ) ) ) ) )
V_79 = true ;
if ( V_79 ) {
if ( V_54 & V_59 )
return;
F_19 ( V_34 , V_41 , V_68
| V_59 ) ;
V_2 -> V_71 = 0 ;
}
if ( V_2 -> V_58 == V_2 -> V_13 ) {
F_11 ( V_4 , V_2 , 0 ) ;
F_37 ( V_73 , V_52 ) ;
V_27 = V_4 -> V_56 ? F_38 ( V_4 ) : NULL ;
if ( ! V_27 ) {
F_20 ( V_3 , L_15 ,
V_4 -> V_33 . V_47 ) ;
return;
}
}
F_25 ( V_3 , V_27 ) ;
}
}
static void F_40 ( struct V_3 * V_3 , struct V_1 * V_27 )
{
const T_3 V_52 = V_27 -> V_52 ;
struct V_24 * V_2 = & V_27 -> V_2 ;
struct V_4 * V_4 ;
void T_2 * V_34 = V_3 -> V_35 [ V_52 ] . V_37 ;
unsigned V_81 = 0 ;
T_4 V_53 ;
T_4 V_54 = F_27 ( V_34 , V_44 ) ;
struct V_82 * V_50 = & V_3 -> V_35 [ V_52 ] ;
T_3 V_83 ;
if ( V_50 -> V_84 )
V_4 = & V_50 -> V_75 ;
else
V_4 = & V_50 -> V_85 ;
V_53 = V_4 -> V_11 ;
if ( ! V_4 -> V_56 ) {
F_20 ( V_3 , L_3 ,
V_4 -> V_33 . V_47 ) ;
return;
}
if ( F_26 ( V_4 -> V_7 ) == V_57 ) {
F_20 ( V_3 , L_16 ) ;
return;
}
if ( V_54 & V_86 ) {
F_20 ( V_3 , L_17 ,
V_4 -> V_33 . V_47 , V_54 ) ;
return;
}
if ( F_33 ( V_3 ) && F_7 ( V_27 ) ) {
struct V_6 * V_38 = V_3 -> V_6 ;
struct V_76 * V_87 = V_4 -> V_7 ;
if ( V_38 -> V_64 ( V_87 ,
V_4 -> V_11 ,
! V_2 -> V_88 ,
V_2 -> V_7 + V_2 -> V_58 ,
V_2 -> V_13 - V_2 -> V_58 ) ) {
V_54 &= ~ ( V_89
| V_90 ) ;
V_54 |= V_91 | V_92 ;
F_19 ( V_34 , V_44 , V_54 ) ;
return;
}
}
if ( V_54 & V_93 ) {
V_53 = F_27 ( V_34 , V_94 ) ;
if ( V_2 -> V_88 && V_53 == V_4 -> V_11 )
V_83 = 1 ;
else
V_83 = 0 ;
if ( V_2 -> V_58 < V_2 -> V_13 ) {
if ( ! F_7 ( V_27 ) )
goto V_95;
if ( F_31 ( V_3 ) ) {
struct V_6 * V_38 ;
struct V_76 * V_87 ;
int V_55 = 0 ;
unsigned int V_96 ;
V_38 = V_3 -> V_6 ;
V_87 = V_4 -> V_7 ;
if ( V_83 ) {
V_54 |= V_89 ;
F_19 ( V_34 , V_44 , V_54 ) ;
V_54 |= V_91 ;
F_19 ( V_34 , V_44 , V_54 ) ;
F_19 ( V_34 , V_44 ,
V_54 | V_90 ) ;
F_19 ( V_34 , V_44 , V_54 ) ;
V_96 = F_30 (unsigned int,
request->length -
request->actual,
channel->max_len) ;
V_4 -> V_7 -> V_63 = 1 ;
} else {
if ( ! V_4 -> V_69 &&
V_4 -> V_50 -> V_97 )
V_54 |= V_89 ;
V_54 |= V_91 ;
F_19 ( V_34 , V_44 , V_54 ) ;
V_96 = F_28 ( V_2 -> V_13 - V_2 -> V_58 ,
( unsigned ) V_53 ) ;
V_4 -> V_7 -> V_63 = 0 ;
}
V_55 = V_38 -> V_64 (
V_87 ,
V_4 -> V_11 ,
V_87 -> V_63 ,
V_2 -> V_7
+ V_2 -> V_58 ,
V_96 ) ;
if ( V_55 )
return;
}
if ( ( F_32 ( V_3 ) ) &&
( V_2 -> V_58 < V_2 -> V_13 ) ) {
struct V_6 * V_38 ;
struct V_76 * V_87 ;
unsigned int V_96 = 0 ;
V_38 = V_3 -> V_6 ;
V_87 = V_4 -> V_7 ;
if ( V_53 < V_4 -> V_11 )
V_96 = V_53 ;
else if ( V_2 -> V_88 )
V_96 = F_30 (unsigned int,
request->length -
request->actual,
channel->max_len) ;
else
V_96 = F_30 (unsigned int,
request->length -
request->actual,
(unsigned)fifo_count) ;
V_54 &= ~ V_90 ;
V_54 |= ( V_91 |
V_89 ) ;
F_19 ( V_34 , V_44 , V_54 ) ;
if ( V_96 <= V_4 -> V_11 ) {
V_4 -> V_7 -> V_63 = 0 ;
} else {
V_4 -> V_7 -> V_63 = 1 ;
V_54 |= V_90 ;
F_19 ( V_34 , V_44 , V_54 ) ;
}
if ( V_38 -> V_64 ( V_87 ,
V_4 -> V_11 ,
V_87 -> V_63 ,
V_2 -> V_7
+ V_2 -> V_58 ,
V_96 ) )
return;
}
V_81 = V_2 -> V_13 - V_2 -> V_58 ;
F_20 ( V_3 , L_18 ,
V_4 -> V_33 . V_47 ,
V_53 , V_81 ,
V_4 -> V_11 ) ;
V_53 = F_30 ( unsigned , V_81 , V_53 ) ;
if ( F_34 ( V_3 ) ) {
struct V_6 * V_38 = V_3 -> V_6 ;
struct V_76 * V_87 = V_4 -> V_7 ;
T_6 V_15 = V_2 -> V_7 + V_2 -> V_58 ;
int V_16 ;
V_16 = V_38 -> V_64 ( V_87 ,
V_4 -> V_11 ,
V_87 -> V_63 ,
V_15 ,
V_53 ) ;
if ( V_16 )
return;
}
F_6 ( V_27 , V_3 ) ;
V_54 &= ~ ( V_91 | V_89 ) ;
F_19 ( V_34 , V_44 , V_54 ) ;
V_95:
F_41 ( V_4 -> V_50 , V_53 , ( T_3 * )
( V_2 -> V_12 + V_2 -> V_58 ) ) ;
V_2 -> V_58 += V_53 ;
V_54 |= V_92 ;
V_54 &= ~ V_93 ;
F_19 ( V_34 , V_44 , V_54 ) ;
}
}
if ( V_2 -> V_58 == V_2 -> V_13 ||
V_53 < V_4 -> V_11 )
F_11 ( V_4 , V_2 , 0 ) ;
}
void F_42 ( struct V_3 * V_3 , T_3 V_52 )
{
T_4 V_54 ;
struct V_1 * V_27 ;
struct V_24 * V_2 ;
void T_2 * V_73 = V_3 -> V_74 ;
struct V_4 * V_4 ;
void T_2 * V_34 = V_3 -> V_35 [ V_52 ] . V_37 ;
struct V_76 * V_7 ;
struct V_82 * V_50 = & V_3 -> V_35 [ V_52 ] ;
if ( V_50 -> V_84 )
V_4 = & V_50 -> V_75 ;
else
V_4 = & V_50 -> V_85 ;
F_37 ( V_73 , V_52 ) ;
V_27 = F_38 ( V_4 ) ;
if ( ! V_27 )
return;
F_43 ( V_27 ) ;
V_2 = & V_27 -> V_2 ;
V_54 = F_27 ( V_34 , V_44 ) ;
V_7 = F_2 () ? V_4 -> V_7 : NULL ;
F_20 ( V_3 , L_19 , V_4 -> V_33 . V_47 ,
V_54 , V_7 ? L_20 : L_21 , V_2 ) ;
if ( V_54 & V_98 ) {
V_54 |= V_92 ;
V_54 &= ~ V_98 ;
F_19 ( V_34 , V_44 , V_54 ) ;
return;
}
if ( V_54 & V_99 ) {
V_54 &= ~ V_99 ;
F_19 ( V_34 , V_44 , V_54 ) ;
F_20 ( V_3 , L_22 , V_4 -> V_47 , V_2 ) ;
if ( V_2 -> V_25 == - V_30 )
V_2 -> V_25 = - V_100 ;
}
if ( V_54 & V_101 ) {
F_20 ( V_3 , L_23 , V_4 -> V_33 . V_47 ) ;
}
if ( F_26 ( V_7 ) == V_57 ) {
F_20 ( V_3 , L_24 ,
V_4 -> V_33 . V_47 , V_54 ) ;
return;
}
if ( V_7 && ( V_54 & V_91 ) ) {
V_54 &= ~ ( V_89
| V_91
| V_90 ) ;
F_19 ( V_34 , V_44 ,
V_92 | V_54 ) ;
V_2 -> V_58 += V_4 -> V_7 -> V_80 ;
#if F_44 ( V_102 ) || F_44 ( V_103 ) || \
F_44 ( V_104 )
if ( ( V_7 -> V_63 == 0 && ! V_50 -> V_97 )
|| ( V_7 -> V_80
& ( V_4 -> V_11 - 1 ) ) ) {
V_54 &= ~ V_93 ;
F_19 ( V_34 , V_44 , V_54 ) ;
}
if ( ( V_2 -> V_58 < V_2 -> V_13 )
&& ( V_4 -> V_7 -> V_80
== V_4 -> V_11 ) ) {
V_54 = F_27 ( V_34 , V_44 ) ;
if ( ( V_54 & V_93 ) &&
V_50 -> V_97 )
goto exit;
return;
}
#endif
F_11 ( V_4 , V_2 , 0 ) ;
F_37 ( V_73 , V_52 ) ;
V_27 = F_38 ( V_4 ) ;
if ( ! V_27 )
return;
}
#if F_44 ( V_102 ) || F_44 ( V_103 ) || \
F_44 ( V_104 )
exit:
#endif
F_40 ( V_3 , V_27 ) ;
}
static int F_45 ( struct V_105 * V_23 ,
const struct V_106 * V_56 )
{
unsigned long V_107 ;
struct V_4 * V_4 ;
struct V_82 * V_50 ;
void T_2 * V_37 ;
struct V_3 * V_3 ;
void T_2 * V_73 ;
T_3 V_52 ;
T_4 V_54 ;
unsigned V_108 ;
int V_25 = - V_109 ;
if ( ! V_23 || ! V_56 )
return - V_109 ;
V_4 = F_46 ( V_23 ) ;
V_50 = V_4 -> V_50 ;
V_37 = V_50 -> V_37 ;
V_3 = V_4 -> V_3 ;
V_73 = V_3 -> V_74 ;
V_52 = V_4 -> V_36 ;
F_47 ( & V_3 -> V_26 , V_107 ) ;
if ( V_4 -> V_56 ) {
V_25 = - V_110 ;
goto V_111;
}
V_4 -> type = F_48 ( V_56 ) ;
if ( F_49 ( V_56 ) != V_52 )
goto V_111;
V_108 = F_50 ( V_56 ) ;
if ( V_108 & ~ 0x07ff ) {
int V_112 ;
if ( F_51 ( V_56 ) )
V_112 = V_3 -> V_113 ;
else
V_112 = V_3 -> V_114 ;
if ( ! V_112 ) {
F_20 ( V_3 , L_25 ) ;
goto V_111;
}
V_4 -> V_69 = ( V_108 >> 11 ) & 3 ;
} else {
V_4 -> V_69 = 0 ;
}
V_4 -> V_11 = V_108 & 0x7ff ;
V_108 = V_4 -> V_11 * ( V_4 -> V_69 + 1 ) ;
F_37 ( V_73 , V_52 ) ;
if ( F_51 ( V_56 ) ) {
if ( V_50 -> V_84 )
V_4 -> V_40 = 1 ;
if ( ! V_4 -> V_40 )
goto V_111;
if ( V_108 > V_50 -> V_51 ) {
F_20 ( V_3 , L_26 ) ;
goto V_111;
}
V_3 -> V_115 |= ( 1 << V_52 ) ;
F_19 ( V_73 , V_116 , V_3 -> V_115 ) ;
if ( V_3 -> V_117 ) {
F_19 ( V_37 , V_72 , V_50 -> V_51 ) ;
} else {
if ( F_24 ( V_3 , V_4 -> type ) )
V_4 -> V_69 = ( V_50 -> V_51 /
V_4 -> V_11 ) - 1 ;
F_19 ( V_37 , V_72 , V_4 -> V_11
| ( V_4 -> V_69 << 11 ) ) ;
}
V_54 = V_68 | V_118 ;
if ( F_27 ( V_37 , V_41 )
& V_119 )
V_54 |= V_43 ;
if ( V_4 -> type == V_120 )
V_54 |= V_121 ;
F_19 ( V_37 , V_41 , V_54 ) ;
F_19 ( V_37 , V_41 , V_54 ) ;
} else {
if ( V_50 -> V_84 )
V_4 -> V_40 = 0 ;
if ( V_4 -> V_40 )
goto V_111;
if ( V_108 > V_50 -> V_122 ) {
F_20 ( V_3 , L_26 ) ;
goto V_111;
}
V_3 -> V_123 |= ( 1 << V_52 ) ;
F_19 ( V_73 , V_124 , V_3 -> V_123 ) ;
if ( V_3 -> V_117 )
F_19 ( V_37 , V_125 , V_50 -> V_51 ) ;
else
F_19 ( V_37 , V_125 , V_4 -> V_11
| ( V_4 -> V_69 << 11 ) ) ;
if ( V_50 -> V_84 ) {
V_54 = F_27 ( V_37 , V_41 ) ;
V_54 &= ~ ( V_68 | V_59 ) ;
F_19 ( V_37 , V_41 , V_54 ) ;
}
V_54 = V_45 | V_126 ;
if ( V_4 -> type == V_120 )
V_54 |= V_127 ;
else if ( V_4 -> type == V_128 )
V_54 |= V_129 ;
F_19 ( V_37 , V_44 , V_54 ) ;
F_19 ( V_37 , V_44 , V_54 ) ;
}
if ( F_2 () && V_3 -> V_6 ) {
struct V_6 * V_38 = V_3 -> V_6 ;
V_4 -> V_7 = V_38 -> V_130 ( V_38 , V_50 ,
( V_56 -> V_131 & V_132 ) ) ;
} else
V_4 -> V_7 = NULL ;
V_4 -> V_56 = V_56 ;
V_4 -> V_28 = 0 ;
V_4 -> V_133 = 0 ;
V_25 = 0 ;
F_52 ( L_27 ,
musb_driver_name, musb_ep->end_point.name,
({ char *s; switch (musb_ep->type) {
case USB_ENDPOINT_XFER_BULK: s = L_28; break;
case USB_ENDPOINT_XFER_INT: s = L_29; break;
default: s = L_30; break;
} s; }),
musb_ep->is_in ? L_31 : L_32 ,
musb_ep->dma ? L_33 : L_21 ,
musb_ep->packet_sz) ;
F_53 ( & V_3 -> V_134 ) ;
V_111:
F_54 ( & V_3 -> V_26 , V_107 ) ;
return V_25 ;
}
static int F_55 ( struct V_105 * V_23 )
{
unsigned long V_107 ;
struct V_3 * V_3 ;
T_3 V_52 ;
struct V_4 * V_4 ;
void T_2 * V_34 ;
int V_25 = 0 ;
V_4 = F_46 ( V_23 ) ;
V_3 = V_4 -> V_3 ;
V_52 = V_4 -> V_36 ;
V_34 = V_3 -> V_35 [ V_52 ] . V_37 ;
F_47 ( & V_3 -> V_26 , V_107 ) ;
F_37 ( V_3 -> V_74 , V_52 ) ;
if ( V_4 -> V_40 ) {
V_3 -> V_115 &= ~ ( 1 << V_52 ) ;
F_19 ( V_3 -> V_74 , V_116 , V_3 -> V_115 ) ;
F_19 ( V_34 , V_72 , 0 ) ;
} else {
V_3 -> V_123 &= ~ ( 1 << V_52 ) ;
F_19 ( V_3 -> V_74 , V_124 , V_3 -> V_123 ) ;
F_19 ( V_34 , V_125 , 0 ) ;
}
F_18 ( V_4 , - V_135 ) ;
V_4 -> V_56 = NULL ;
V_4 -> V_33 . V_56 = NULL ;
F_53 ( & V_3 -> V_134 ) ;
F_54 ( & ( V_3 -> V_26 ) , V_107 ) ;
F_20 ( V_3 , L_34 , V_4 -> V_33 . V_47 ) ;
return V_25 ;
}
struct V_24 * F_56 ( struct V_105 * V_23 , T_7 V_136 )
{
struct V_4 * V_4 = F_46 ( V_23 ) ;
struct V_1 * V_2 = NULL ;
V_2 = F_57 ( sizeof *V_2 , V_136 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_2 . V_7 = V_14 ;
V_2 -> V_52 = V_4 -> V_36 ;
V_2 -> V_23 = V_4 ;
F_58 ( V_2 ) ;
return & V_2 -> V_2 ;
}
void F_59 ( struct V_105 * V_23 , struct V_24 * V_27 )
{
struct V_1 * V_2 = F_12 ( V_27 ) ;
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
}
void F_62 ( struct V_3 * V_3 , struct V_1 * V_27 )
{
F_63 ( V_27 ) ;
F_37 ( V_3 -> V_74 , V_27 -> V_52 ) ;
if ( V_27 -> V_18 )
F_25 ( V_3 , V_27 ) ;
else
F_40 ( V_3 , V_27 ) ;
}
static int F_64 ( struct V_105 * V_23 , struct V_24 * V_27 ,
T_7 V_136 )
{
struct V_4 * V_4 ;
struct V_1 * V_2 ;
struct V_3 * V_3 ;
int V_25 = 0 ;
unsigned long V_137 ;
if ( ! V_23 || ! V_27 )
return - V_109 ;
if ( ! V_27 -> V_12 )
return - V_138 ;
V_4 = F_46 ( V_23 ) ;
V_3 = V_4 -> V_3 ;
V_2 = F_12 ( V_27 ) ;
V_2 -> V_3 = V_3 ;
if ( V_2 -> V_23 != V_4 )
return - V_109 ;
F_65 ( V_2 ) ;
V_2 -> V_2 . V_58 = 0 ;
V_2 -> V_2 . V_25 = - V_30 ;
V_2 -> V_52 = V_4 -> V_36 ;
V_2 -> V_18 = V_4 -> V_40 ;
F_1 ( V_2 , V_3 , V_4 ) ;
F_47 ( & V_3 -> V_26 , V_137 ) ;
if ( ! V_4 -> V_56 ) {
F_20 ( V_3 , L_35 ,
V_27 , V_23 -> V_47 , L_36 ) ;
V_25 = - V_135 ;
F_6 ( V_2 , V_3 ) ;
goto V_139;
}
F_66 ( & V_2 -> V_29 , & V_4 -> V_49 ) ;
if ( ! V_4 -> V_28 && & V_2 -> V_29 == V_4 -> V_49 . V_140 )
F_62 ( V_3 , V_2 ) ;
V_139:
F_54 ( & V_3 -> V_26 , V_137 ) ;
return V_25 ;
}
static int F_67 ( struct V_105 * V_23 , struct V_24 * V_2 )
{
struct V_4 * V_4 = F_46 ( V_23 ) ;
struct V_1 * V_27 = F_12 ( V_2 ) ;
struct V_1 * V_141 ;
unsigned long V_107 ;
int V_25 = 0 ;
struct V_3 * V_3 = V_4 -> V_3 ;
if ( ! V_23 || ! V_2 || V_27 -> V_23 != V_4 )
return - V_109 ;
F_68 ( V_27 ) ;
F_47 ( & V_3 -> V_26 , V_107 ) ;
F_69 (r, &musb_ep->req_list, list) {
if ( V_141 == V_27 )
break;
}
if ( V_141 != V_27 ) {
F_70 ( V_3 -> V_17 , L_37 ,
V_2 , V_23 -> V_47 ) ;
V_25 = - V_109 ;
goto V_142;
}
if ( V_4 -> V_49 . V_140 != & V_27 -> V_29 || V_4 -> V_28 )
F_11 ( V_4 , V_2 , - V_143 ) ;
else if ( F_2 () && V_4 -> V_7 ) {
struct V_6 * V_38 = V_3 -> V_6 ;
F_37 ( V_3 -> V_74 , V_4 -> V_36 ) ;
if ( V_38 -> V_46 )
V_25 = V_38 -> V_46 ( V_4 -> V_7 ) ;
else
V_25 = - V_110 ;
if ( V_25 == 0 )
F_11 ( V_4 , V_2 , - V_143 ) ;
} else {
F_11 ( V_4 , V_2 , - V_143 ) ;
}
V_142:
F_54 ( & V_3 -> V_26 , V_107 ) ;
return V_25 ;
}
static int F_71 ( struct V_105 * V_23 , int V_39 )
{
struct V_4 * V_4 = F_46 ( V_23 ) ;
T_3 V_52 = V_4 -> V_36 ;
struct V_3 * V_3 = V_4 -> V_3 ;
void T_2 * V_34 = V_3 -> V_35 [ V_52 ] . V_37 ;
void T_2 * V_73 ;
unsigned long V_107 ;
T_4 V_54 ;
struct V_1 * V_2 ;
int V_25 = 0 ;
if ( ! V_23 )
return - V_109 ;
V_73 = V_3 -> V_74 ;
F_47 ( & V_3 -> V_26 , V_107 ) ;
if ( ( V_120 == V_4 -> type ) ) {
V_25 = - V_109 ;
goto V_142;
}
F_37 ( V_73 , V_52 ) ;
V_2 = F_38 ( V_4 ) ;
if ( V_39 ) {
if ( V_2 ) {
F_20 ( V_3 , L_38 ,
V_23 -> V_47 ) ;
V_25 = - V_144 ;
goto V_142;
}
if ( V_4 -> V_40 ) {
V_54 = F_27 ( V_34 , V_41 ) ;
if ( V_54 & V_119 ) {
F_20 ( V_3 , L_39 ,
V_23 -> V_47 ) ;
V_25 = - V_144 ;
goto V_142;
}
}
} else
V_4 -> V_133 = 0 ;
F_20 ( V_3 , L_40 , V_23 -> V_47 , V_39 ? L_41 : L_42 ) ;
if ( V_4 -> V_40 ) {
V_54 = F_27 ( V_34 , V_41 ) ;
V_54 |= V_67
| V_118 ;
if ( V_39 )
V_54 |= V_60 ;
else
V_54 &= ~ ( V_60
| V_77 ) ;
V_54 &= ~ V_59 ;
F_19 ( V_34 , V_41 , V_54 ) ;
} else {
V_54 = F_27 ( V_34 , V_44 ) ;
V_54 |= V_92
| V_45
| V_126 ;
if ( V_39 )
V_54 |= V_86 ;
else
V_54 &= ~ ( V_86
| V_98 ) ;
F_19 ( V_34 , V_44 , V_54 ) ;
}
if ( ! V_4 -> V_28 && ! V_39 && V_2 ) {
F_20 ( V_3 , L_43 ) ;
F_62 ( V_3 , V_2 ) ;
}
V_142:
F_54 ( & V_3 -> V_26 , V_107 ) ;
return V_25 ;
}
static int F_72 ( struct V_105 * V_23 )
{
struct V_4 * V_4 = F_46 ( V_23 ) ;
if ( ! V_23 )
return - V_109 ;
V_4 -> V_133 = 1 ;
return F_73 ( V_23 ) ;
}
static int F_74 ( struct V_105 * V_23 )
{
struct V_4 * V_4 = F_46 ( V_23 ) ;
void T_2 * V_34 = V_4 -> V_50 -> V_37 ;
int V_145 = - V_109 ;
if ( V_4 -> V_56 && ! V_4 -> V_40 ) {
struct V_3 * V_3 = V_4 -> V_3 ;
int V_52 = V_4 -> V_36 ;
void T_2 * V_73 = V_3 -> V_74 ;
unsigned long V_107 ;
F_47 ( & V_3 -> V_26 , V_107 ) ;
F_37 ( V_73 , V_52 ) ;
V_145 = F_27 ( V_34 , V_94 ) ;
F_54 ( & V_3 -> V_26 , V_107 ) ;
}
return V_145 ;
}
static void F_75 ( struct V_105 * V_23 )
{
struct V_4 * V_4 = F_46 ( V_23 ) ;
struct V_3 * V_3 = V_4 -> V_3 ;
T_3 V_52 = V_4 -> V_36 ;
void T_2 * V_34 = V_3 -> V_35 [ V_52 ] . V_37 ;
void T_2 * V_73 ;
unsigned long V_107 ;
T_4 V_54 ;
V_73 = V_3 -> V_74 ;
F_47 ( & V_3 -> V_26 , V_107 ) ;
F_37 ( V_73 , ( T_3 ) V_52 ) ;
F_19 ( V_73 , V_116 , V_3 -> V_115 & ~ ( 1 << V_52 ) ) ;
if ( V_4 -> V_40 ) {
V_54 = F_27 ( V_34 , V_41 ) ;
if ( V_54 & V_119 ) {
V_54 |= V_43 | V_67 ;
V_54 &= ~ V_59 ;
F_19 ( V_34 , V_41 , V_54 ) ;
F_19 ( V_34 , V_41 , V_54 ) ;
}
} else {
V_54 = F_27 ( V_34 , V_44 ) ;
V_54 |= V_45 | V_92 ;
F_19 ( V_34 , V_44 , V_54 ) ;
F_19 ( V_34 , V_44 , V_54 ) ;
}
F_19 ( V_73 , V_116 , V_3 -> V_115 ) ;
F_54 ( & V_3 -> V_26 , V_107 ) ;
}
static int F_76 ( struct V_146 * V_147 )
{
struct V_3 * V_3 = F_77 ( V_147 ) ;
return ( int ) F_27 ( V_3 -> V_74 , V_148 ) ;
}
static int F_78 ( struct V_146 * V_147 )
{
struct V_3 * V_3 = F_77 ( V_147 ) ;
void T_2 * V_74 = V_3 -> V_74 ;
unsigned long V_107 ;
int V_25 = - V_109 ;
T_3 V_149 , V_150 ;
int V_151 ;
F_47 ( & V_3 -> V_26 , V_107 ) ;
switch ( V_3 -> V_152 -> V_153 -> V_154 ) {
case V_155 :
if ( V_3 -> V_156 && V_3 -> V_157 )
break;
goto V_142;
case V_158 :
V_150 = F_79 ( V_74 , V_159 ) ;
F_20 ( V_3 , L_44 , V_150 ) ;
V_150 |= V_160 ;
F_80 ( V_74 , V_159 , V_150 ) ;
V_150 = F_79 ( V_74 , V_159 ) ;
V_151 = 100 ;
while ( ! ( V_150 & V_160 ) ) {
V_150 = F_79 ( V_74 , V_159 ) ;
if ( V_151 -- < 1 )
break;
}
V_151 = 10000 ;
while ( V_150 & V_160 ) {
V_150 = F_79 ( V_74 , V_159 ) ;
if ( V_151 -- < 1 )
break;
}
F_54 ( & V_3 -> V_26 , V_107 ) ;
F_81 ( V_3 -> V_152 -> V_153 ) ;
F_47 ( & V_3 -> V_26 , V_107 ) ;
F_82 ( V_3 ,
V_161 + F_83 ( 1 * V_162 ) ) ;
V_25 = 0 ;
goto V_142;
default:
F_20 ( V_3 , L_45 ,
F_84 ( V_3 -> V_152 -> V_153 -> V_154 ) ) ;
goto V_142;
}
V_25 = 0 ;
V_149 = F_79 ( V_74 , V_163 ) ;
V_149 |= V_164 ;
F_80 ( V_74 , V_163 , V_149 ) ;
F_20 ( V_3 , L_46 ) ;
F_85 ( 2 ) ;
V_149 = F_79 ( V_74 , V_163 ) ;
V_149 &= ~ V_164 ;
F_80 ( V_74 , V_163 , V_149 ) ;
V_142:
F_54 ( & V_3 -> V_26 , V_107 ) ;
return V_25 ;
}
static int
F_86 ( struct V_146 * V_147 , int V_165 )
{
V_147 -> V_165 = ! ! V_165 ;
return 0 ;
}
static void F_87 ( struct V_3 * V_3 , int V_166 )
{
T_3 V_149 ;
V_149 = F_79 ( V_3 -> V_74 , V_163 ) ;
if ( V_166 )
V_149 |= V_167 ;
else
V_149 &= ~ V_167 ;
F_20 ( V_3 , L_47 ,
V_166 ? L_48 : L_49 ) ;
F_80 ( V_3 -> V_74 , V_163 , V_149 ) ;
}
static int F_88 ( struct V_146 * V_147 , unsigned V_168 )
{
struct V_3 * V_3 = F_77 ( V_147 ) ;
if ( ! V_3 -> V_152 -> V_169 )
return - V_170 ;
return F_89 ( V_3 -> V_152 , V_168 ) ;
}
static void F_90 ( struct V_171 * V_172 )
{
struct V_3 * V_3 ;
unsigned long V_107 ;
V_3 = F_91 ( V_172 , struct V_3 , V_173 . V_172 ) ;
F_92 ( V_3 -> V_17 ) ;
F_47 ( & V_3 -> V_26 , V_107 ) ;
F_87 ( V_3 , V_3 -> V_174 ) ;
F_54 ( & V_3 -> V_26 , V_107 ) ;
F_93 ( V_3 -> V_17 ) ;
F_94 ( V_3 -> V_17 ) ;
}
static int F_95 ( struct V_146 * V_147 , int V_166 )
{
struct V_3 * V_3 = F_77 ( V_147 ) ;
unsigned long V_107 ;
V_166 = ! ! V_166 ;
F_47 ( & V_3 -> V_26 , V_107 ) ;
if ( V_166 != V_3 -> V_174 ) {
V_3 -> V_174 = V_166 ;
F_96 ( & V_3 -> V_173 , 0 ) ;
}
F_54 ( & V_3 -> V_26 , V_107 ) ;
return 0 ;
}
static struct V_105 * F_97 ( struct V_146 * V_31 ,
struct V_106 * V_56 ,
struct V_175 * V_176 )
{
struct V_105 * V_23 = NULL ;
switch ( F_48 ( V_56 ) ) {
case V_120 :
case V_177 :
if ( F_51 ( V_56 ) )
V_23 = F_98 ( V_31 , L_50 ) ;
else
V_23 = F_98 ( V_31 , L_51 ) ;
break;
case V_128 :
if ( F_51 ( V_56 ) )
V_23 = F_98 ( V_31 , L_52 ) ;
else
V_23 = F_98 ( V_31 , L_53 ) ;
break;
default:
break;
}
if ( V_23 && F_99 ( V_31 , V_23 , V_56 , V_176 ) )
return V_23 ;
return NULL ;
}
static void
F_100 ( struct V_3 * V_3 , struct V_4 * V_23 , T_3 V_52 , int V_40 )
{
struct V_82 * V_50 = V_3 -> V_35 + V_52 ;
memset ( V_23 , 0 , sizeof *V_23 ) ;
V_23 -> V_36 = V_52 ;
V_23 -> V_3 = V_3 ;
V_23 -> V_50 = V_50 ;
V_23 -> V_40 = V_40 ;
F_101 ( & V_23 -> V_49 ) ;
sprintf ( V_23 -> V_47 , L_54 , V_52 ,
( ! V_52 || V_50 -> V_84 ) ? L_21 : (
V_40 ? L_55 : L_56 ) ) ;
V_23 -> V_33 . V_47 = V_23 -> V_47 ;
F_101 ( & V_23 -> V_33 . V_178 ) ;
if ( ! V_52 ) {
F_102 ( & V_23 -> V_33 , 64 ) ;
V_23 -> V_33 . V_179 . V_180 = true ;
V_23 -> V_33 . V_181 = & V_182 ;
V_3 -> V_31 . V_183 = & V_23 -> V_33 ;
} else {
if ( V_40 )
F_102 ( & V_23 -> V_33 , V_50 -> V_51 ) ;
else
F_102 ( & V_23 -> V_33 , V_50 -> V_122 ) ;
V_23 -> V_33 . V_179 . V_184 = true ;
V_23 -> V_33 . V_179 . V_185 = true ;
V_23 -> V_33 . V_179 . V_186 = true ;
V_23 -> V_33 . V_181 = & V_187 ;
F_66 ( & V_23 -> V_33 . V_178 , & V_3 -> V_31 . V_178 ) ;
}
if ( ! V_52 || V_50 -> V_84 ) {
V_23 -> V_33 . V_179 . V_188 = true ;
V_23 -> V_33 . V_179 . V_189 = true ;
} else if ( V_40 )
V_23 -> V_33 . V_179 . V_188 = true ;
else
V_23 -> V_33 . V_179 . V_189 = true ;
}
static inline void F_103 ( struct V_3 * V_3 )
{
T_3 V_52 ;
struct V_82 * V_50 ;
unsigned V_190 = 0 ;
F_101 ( & ( V_3 -> V_31 . V_178 ) ) ;
for ( V_52 = 0 , V_50 = V_3 -> V_35 ;
V_52 < V_3 -> V_191 ;
V_52 ++ , V_50 ++ ) {
if ( V_50 -> V_84 ) {
F_100 ( V_3 , & V_50 -> V_75 , V_52 , 0 ) ;
V_190 ++ ;
} else {
if ( V_50 -> V_51 ) {
F_100 ( V_3 , & V_50 -> V_75 ,
V_52 , 1 ) ;
V_190 ++ ;
}
if ( V_50 -> V_122 ) {
F_100 ( V_3 , & V_50 -> V_85 ,
V_52 , 0 ) ;
V_190 ++ ;
}
}
}
}
int F_104 ( struct V_3 * V_3 )
{
int V_25 ;
V_3 -> V_31 . V_181 = & V_192 ;
V_3 -> V_31 . V_193 = V_194 ;
V_3 -> V_31 . V_195 = V_196 ;
F_105 ( V_3 ) ;
V_3 -> V_152 -> V_153 -> V_197 = 0 ;
V_3 -> V_152 -> V_153 -> V_154 = V_158 ;
V_3 -> V_31 . V_47 = V_198 ;
#if F_106 ( V_199 )
V_3 -> V_31 . V_200 = 1 ;
#elif F_106 ( V_201 )
V_3 -> V_31 . V_200 = 0 ;
#endif
F_107 ( & V_3 -> V_173 , F_90 ) ;
F_103 ( V_3 ) ;
V_3 -> V_202 = 0 ;
F_82 ( V_3 , 0 ) ;
V_25 = F_108 ( V_3 -> V_17 , & V_3 -> V_31 ) ;
if ( V_25 )
goto V_203;
return 0 ;
V_203:
V_3 -> V_31 . V_32 . V_204 = NULL ;
F_109 ( & V_3 -> V_31 . V_32 ) ;
return V_25 ;
}
void F_110 ( struct V_3 * V_3 )
{
if ( V_3 -> V_205 == V_206 )
return;
F_111 ( & V_3 -> V_173 ) ;
F_112 ( & V_3 -> V_31 ) ;
}
static int F_113 ( struct V_146 * V_31 ,
struct V_207 * V_208 )
{
struct V_3 * V_3 = F_77 ( V_31 ) ;
struct V_209 * V_153 = V_3 -> V_152 -> V_153 ;
unsigned long V_107 ;
int V_145 = 0 ;
if ( V_208 -> V_193 < V_194 ) {
V_145 = - V_109 ;
goto V_203;
}
F_92 ( V_3 -> V_17 ) ;
V_3 -> V_174 = 0 ;
V_3 -> V_210 = V_208 ;
F_47 ( & V_3 -> V_26 , V_107 ) ;
V_3 -> V_202 = 1 ;
F_114 ( V_153 , & V_3 -> V_31 ) ;
V_3 -> V_152 -> V_153 -> V_154 = V_158 ;
F_54 ( & V_3 -> V_26 , V_107 ) ;
F_115 ( V_3 ) ;
if ( V_3 -> V_152 -> V_211 == V_212 )
F_116 ( V_3 , 1 ) ;
F_93 ( V_3 -> V_17 ) ;
F_94 ( V_3 -> V_17 ) ;
return 0 ;
V_203:
return V_145 ;
}
static int F_117 ( struct V_146 * V_31 )
{
struct V_3 * V_3 = F_77 ( V_31 ) ;
unsigned long V_107 ;
F_92 ( V_3 -> V_17 ) ;
F_47 ( & V_3 -> V_26 , V_107 ) ;
F_118 ( V_3 ) ;
( void ) F_88 ( & V_3 -> V_31 , 0 ) ;
V_3 -> V_152 -> V_153 -> V_154 = V_213 ;
F_119 ( V_3 ) ;
F_114 ( V_3 -> V_152 -> V_153 , NULL ) ;
V_3 -> V_202 = 0 ;
V_3 -> V_210 = NULL ;
F_82 ( V_3 , 0 ) ;
F_54 ( & V_3 -> V_26 , V_107 ) ;
F_93 ( V_3 -> V_17 ) ;
F_94 ( V_3 -> V_17 ) ;
return 0 ;
}
void F_120 ( struct V_3 * V_3 )
{
V_3 -> V_157 = 0 ;
switch ( V_3 -> V_152 -> V_153 -> V_154 ) {
case V_158 :
break;
case V_214 :
case V_155 :
V_3 -> V_202 = 1 ;
if ( V_3 -> V_210 && V_3 -> V_210 -> V_215 ) {
F_14 ( & V_3 -> V_26 ) ;
V_3 -> V_210 -> V_215 ( & V_3 -> V_31 ) ;
F_17 ( & V_3 -> V_26 ) ;
}
break;
default:
F_121 ( L_57 ,
F_84 ( V_3 -> V_152 -> V_153 -> V_154 ) ) ;
}
}
void F_122 ( struct V_3 * V_3 )
{
T_3 V_150 ;
V_150 = F_79 ( V_3 -> V_74 , V_159 ) ;
F_20 ( V_3 , L_58 , V_150 ) ;
switch ( V_3 -> V_152 -> V_153 -> V_154 ) {
case V_158 :
if ( ( V_150 & V_216 ) == V_216 )
V_3 -> V_152 -> V_153 -> V_154 = V_155 ;
break;
case V_155 :
V_3 -> V_157 = 1 ;
if ( V_3 -> V_210 && V_3 -> V_210 -> V_217 ) {
F_14 ( & V_3 -> V_26 ) ;
V_3 -> V_210 -> V_217 ( & V_3 -> V_31 ) ;
F_17 ( & V_3 -> V_26 ) ;
}
break;
default:
F_121 ( L_59 ,
F_84 ( V_3 -> V_152 -> V_153 -> V_154 ) ) ;
}
}
void F_123 ( struct V_3 * V_3 )
{
F_78 ( & V_3 -> V_31 ) ;
}
void F_124 ( struct V_3 * V_3 )
{
void T_2 * V_74 = V_3 -> V_74 ;
T_3 V_150 = F_79 ( V_74 , V_159 ) ;
F_20 ( V_3 , L_60 , V_150 ) ;
F_80 ( V_74 , V_159 , V_150 & V_160 ) ;
( void ) F_88 ( & V_3 -> V_31 , 0 ) ;
V_3 -> V_31 . V_195 = V_196 ;
if ( V_3 -> V_210 && V_3 -> V_210 -> V_218 ) {
F_14 ( & V_3 -> V_26 ) ;
V_3 -> V_210 -> V_218 ( & V_3 -> V_31 ) ;
F_17 ( & V_3 -> V_26 ) ;
}
switch ( V_3 -> V_152 -> V_153 -> V_154 ) {
default:
F_20 ( V_3 , L_61 ,
F_84 ( V_3 -> V_152 -> V_153 -> V_154 ) ) ;
V_3 -> V_152 -> V_153 -> V_154 = V_219 ;
F_125 ( V_3 ) ;
break;
case V_220 :
V_3 -> V_152 -> V_153 -> V_154 = V_221 ;
F_125 ( V_3 ) ;
break;
case V_214 :
case V_222 :
case V_155 :
case V_158 :
V_3 -> V_152 -> V_153 -> V_154 = V_158 ;
break;
case V_223 :
break;
}
V_3 -> V_202 = 0 ;
}
void F_126 ( struct V_3 * V_3 )
__releases( V_3 -> V_26 )
__acquires( V_3 -> V_26 )
{
void T_2 * V_73 = V_3 -> V_74 ;
T_3 V_150 = F_79 ( V_73 , V_159 ) ;
T_3 V_149 ;
F_20 ( V_3 , L_62 ,
( V_150 & V_224 )
? L_63 : L_64 ,
V_3 -> V_210
? V_3 -> V_210 -> V_208 . V_47
: NULL
) ;
if ( V_3 -> V_210 && V_3 -> V_31 . V_195 != V_196 ) {
F_14 ( & V_3 -> V_26 ) ;
F_127 ( & V_3 -> V_31 , V_3 -> V_210 ) ;
F_17 ( & V_3 -> V_26 ) ;
}
else if ( V_150 & V_225 )
F_80 ( V_73 , V_159 , V_160 ) ;
V_149 = F_79 ( V_73 , V_163 ) ;
V_3 -> V_31 . V_195 = ( V_149 & V_226 )
? V_194 : V_227 ;
V_3 -> V_202 = 1 ;
V_3 -> V_157 = 0 ;
F_105 ( V_3 ) ;
V_3 -> V_228 = 0 ;
V_3 -> V_229 = V_230 ;
V_3 -> V_156 = 0 ;
V_3 -> V_31 . V_231 = 0 ;
V_3 -> V_31 . V_232 = 0 ;
V_3 -> V_31 . V_233 = 0 ;
V_3 -> V_31 . V_234 = 1 ;
if ( ! V_3 -> V_31 . V_200 ) {
V_3 -> V_152 -> V_153 -> V_154 = V_155 ;
V_3 -> V_31 . V_235 = 0 ;
} else if ( V_150 & V_224 ) {
V_3 -> V_152 -> V_153 -> V_154 = V_155 ;
V_3 -> V_31 . V_235 = 0 ;
} else {
V_3 -> V_152 -> V_153 -> V_154 = V_220 ;
V_3 -> V_31 . V_235 = 1 ;
}
( void ) F_88 ( & V_3 -> V_31 , 8 ) ;
}
