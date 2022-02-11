static inline void F_1 ( struct V_1 * V_1 ,
T_1 V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_1 -> V_4 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_1 , T_1 V_3 )
{
return F_4 ( V_1 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_1 )
{
while ( F_3 ( V_1 , V_5 ) & V_6 )
F_6 () ;
}
static inline void F_7 ( struct V_1 * V_1 ,
unsigned long V_2 , T_2 V_3 )
{
F_5 ( V_1 ) ;
F_1 ( V_1 , V_7 | V_3 , V_5 ) ;
F_1 ( V_1 , V_2 , V_8 ) ;
F_5 ( V_1 ) ;
}
static inline T_2 F_8 ( struct V_1 * V_1 , T_2 V_3 )
{
F_5 ( V_1 ) ;
F_1 ( V_1 , V_9 | V_7 | V_3 ,
V_5 ) ;
F_5 ( V_1 ) ;
return F_3 ( V_1 , V_8 ) ;
}
static inline void F_9 ( struct V_1 * V_1 )
{
while ( F_8 ( V_1 , V_10 ) &
V_11 )
F_6 () ;
}
static T_3 F_10 ( int V_12 , void * V_13 )
{
struct V_1 * V_1 = V_13 ;
unsigned long V_14 = 0 ;
T_1 V_15 ;
T_2 V_16 , V_17 ;
T_2 V_18 , V_19 ;
int V_20 = V_21 ;
V_15 = F_3 ( V_1 , V_22 ) &
V_23 ;
V_16 = F_8 ( V_1 , V_10 ) &
V_24 ;
V_17 = F_8 ( V_1 , V_25 ) &
V_26 ;
if ( V_15 ) {
if ( V_16 ) {
V_14 |= V_27 | V_28 ;
V_19 = F_8 ( V_1 , V_10 ) ;
V_19 |= V_24 ;
F_7 ( V_1 , V_19 , V_10 ) ;
} else if ( V_17 ) {
V_14 |= V_27 | V_29 ;
V_18 = F_8 ( V_1 , V_25 ) ;
V_18 |= V_26 ;
F_7 ( V_1 , V_18 , V_25 ) ;
}
F_1 ( V_1 , V_23 ,
V_22 ) ;
F_11 ( V_1 -> V_30 , 1 , V_14 ) ;
V_20 = V_31 ;
}
return V_20 ;
}
static int
F_12 ( struct V_32 * V_33 , unsigned int V_34 , unsigned long V_35 )
{
struct V_1 * V_1 = F_13 ( V_33 ) ;
T_2 V_18 ;
unsigned long V_36 ;
int V_20 = 0 ;
F_14 ( & V_37 , V_36 ) ;
V_18 = F_8 ( V_1 , V_25 ) ;
switch ( V_34 ) {
case V_38 :
V_18 |= V_39 | V_40 ;
break;
case V_41 :
V_18 &= ~ V_39 ;
break;
default:
V_20 = - V_42 ;
}
F_7 ( V_1 , V_18 , V_25 ) ;
F_15 ( & V_37 , V_36 ) ;
return V_20 ;
}
static int F_16 ( T_4 V_43 , struct V_44 * V_45 )
{
int V_46 , V_47 , V_48 ;
for ( V_47 = 2000 ; ; V_47 ++ ) {
V_46 = F_17 ( 1 , 12 , V_47 ) ;
if ( V_43 >= V_46 )
V_43 -= V_46 ;
else {
for ( V_48 = 0 ; ; V_48 ++ ) {
V_46 = F_18 ( V_48 , V_47 ) ;
if ( V_43 >= V_46 ) {
V_43 -= V_46 ;
} else {
V_45 -> V_49 = V_47 - 1900 ;
V_45 -> V_50 = V_48 ;
V_45 -> V_51 = V_43 + 1 ;
break;
}
}
break;
}
}
return 0 ;
}
static int F_19 ( T_4 * V_43 , struct V_44 * V_45 )
{
int V_52 ;
* V_43 = 0 ;
if ( V_45 -> V_49 < 100 || V_45 -> V_49 > 199 )
return - V_53 ;
for ( V_52 = 2000 ; V_52 < 1900 + V_45 -> V_49 ; V_52 ++ )
* V_43 += F_17 ( 1 , 12 , V_52 ) ;
* V_43 += F_17 ( V_45 -> V_51 , V_45 -> V_50 , 1900 + V_45 -> V_49 ) ;
return 0 ;
}
static int F_20 ( struct V_32 * V_33 , struct V_44 * V_45 )
{
struct V_1 * V_1 = F_13 ( V_33 ) ;
T_4 V_43 = 0 ;
T_2 V_54 , V_55 ;
unsigned long V_36 ;
F_14 ( & V_37 , V_36 ) ;
F_9 ( V_1 ) ;
V_45 -> V_56 = F_21 ( F_8 ( V_1 , V_57 ) ) ;
F_9 ( V_1 ) ;
V_45 -> V_58 = F_21 ( F_8 ( V_1 , V_59 ) ) ;
F_9 ( V_1 ) ;
V_45 -> V_60 = F_21 ( F_8 ( V_1 , V_61 ) ) ;
F_9 ( V_1 ) ;
V_54 = F_8 ( V_1 , V_62 ) ;
F_9 ( V_1 ) ;
V_55 = F_8 ( V_1 , V_63 ) ;
F_15 ( & V_37 , V_36 ) ;
V_43 |= V_55 ;
V_43 <<= 8 ;
V_43 |= V_54 ;
if ( F_16 ( V_43 , V_45 ) < 0 )
return - V_53 ;
return 0 ;
}
static int F_22 ( struct V_32 * V_33 , struct V_44 * V_45 )
{
struct V_1 * V_1 = F_13 ( V_33 ) ;
T_4 V_43 ;
T_2 V_19 ;
unsigned long V_36 ;
if ( F_19 ( & V_43 , V_45 ) < 0 )
return - V_53 ;
F_14 ( & V_37 , V_36 ) ;
F_9 ( V_1 ) ;
F_7 ( V_1 , F_23 ( V_45 -> V_56 ) , V_57 ) ;
F_9 ( V_1 ) ;
F_7 ( V_1 , F_23 ( V_45 -> V_58 ) , V_59 ) ;
F_9 ( V_1 ) ;
F_7 ( V_1 , F_23 ( V_45 -> V_60 ) , V_61 ) ;
F_9 ( V_1 ) ;
F_7 ( V_1 , V_43 & 0xFF , V_62 ) ;
F_9 ( V_1 ) ;
F_7 ( V_1 , ( V_43 & 0xFF00 ) >> 8 , V_63 ) ;
V_19 = F_8 ( V_1 , V_10 ) ;
V_19 |= V_64 ;
F_7 ( V_1 , V_19 , V_10 ) ;
F_15 ( & V_37 , V_36 ) ;
return 0 ;
}
static int F_24 ( struct V_32 * V_33 ,
unsigned int V_65 )
{
struct V_1 * V_1 = F_13 ( V_33 ) ;
unsigned long V_36 ;
T_2 V_19 = F_8 ( V_1 , V_10 ) ;
F_14 ( & V_37 , V_36 ) ;
if ( V_65 )
V_19 |= V_66 |
V_67 |
V_68 |
V_24 |
V_69 ;
else
V_19 &= ~ V_69 ;
F_9 ( V_1 ) ;
F_7 ( V_1 , V_19 , V_10 ) ;
F_15 ( & V_37 , V_36 ) ;
return 0 ;
}
static int F_25 ( struct V_32 * V_33 , struct V_70 * V_71 )
{
struct V_1 * V_1 = F_13 ( V_33 ) ;
T_4 V_43 = 0 ;
T_2 V_54 , V_55 ;
unsigned long V_36 ;
V_71 -> time . V_56 = 0 ;
F_14 ( & V_37 , V_36 ) ;
F_9 ( V_1 ) ;
V_71 -> time . V_58 = F_21 ( F_8 ( V_1 , V_72 ) ) ;
F_9 ( V_1 ) ;
V_71 -> time . V_60 = F_21 ( F_8 ( V_1 , V_73 ) ) ;
F_9 ( V_1 ) ;
V_54 = F_8 ( V_1 , V_74 ) ;
F_9 ( V_1 ) ;
V_55 = F_8 ( V_1 , V_75 ) ;
F_15 ( & V_37 , V_36 ) ;
V_43 |= V_55 ;
V_43 <<= 8 ;
V_43 |= V_54 ;
if ( F_16 ( V_43 , & V_71 -> time ) < 0 )
return - V_53 ;
V_71 -> V_76 = ! ! ( F_8 ( V_1 ,
V_10 ) &
V_69 ) ;
V_71 -> V_65 = V_71 -> V_76 && F_26 ( V_33 ) ;
return 0 ;
}
static int F_27 ( struct V_32 * V_33 , struct V_70 * V_71 )
{
struct V_1 * V_1 = F_13 ( V_33 ) ;
unsigned long V_36 ;
T_4 V_43 ;
if ( V_71 -> time . V_51 <= 0 && V_71 -> time . V_50 < 0
&& V_71 -> time . V_49 < 0 ) {
struct V_44 V_45 ;
unsigned long V_77 , V_78 ;
F_20 ( V_33 , & V_45 ) ;
F_28 ( & V_45 , & V_77 ) ;
V_71 -> time . V_51 = V_45 . V_51 ;
V_71 -> time . V_50 = V_45 . V_50 ;
V_71 -> time . V_49 = V_45 . V_49 ;
F_28 ( & V_71 -> time , & V_78 ) ;
if ( V_78 < V_77 ) {
F_29 ( V_77 + 24 * 60 * 60 , & V_45 ) ;
V_71 -> time . V_51 = V_45 . V_51 ;
V_71 -> time . V_50 = V_45 . V_50 ;
V_71 -> time . V_49 = V_45 . V_49 ;
}
}
if ( F_19 ( & V_43 , & V_71 -> time ) < 0 )
return - V_53 ;
F_14 ( & V_37 , V_36 ) ;
F_9 ( V_1 ) ;
F_7 ( V_1 , F_23 ( V_71 -> time . V_58 ) , V_72 ) ;
F_9 ( V_1 ) ;
F_7 ( V_1 , F_23 ( V_71 -> time . V_60 ) , V_73 ) ;
F_9 ( V_1 ) ;
F_7 ( V_1 , V_43 & 0xFF , V_74 ) ;
F_9 ( V_1 ) ;
F_7 ( V_1 , ( V_43 & 0xFF00 ) >> 8 , V_75 ) ;
F_15 ( & V_37 , V_36 ) ;
return 0 ;
}
static int T_5 F_30 ( struct V_79 * V_80 )
{
struct V_32 * V_33 = & V_80 -> V_33 ;
struct V_1 * V_1 ;
struct V_81 * V_82 ;
int V_20 = 0 ;
V_1 = F_31 ( & V_80 -> V_33 , sizeof( struct V_1 ) , V_83 ) ;
if ( ! V_1 )
return - V_84 ;
V_1 -> V_12 = F_32 ( V_80 , 0 ) ;
if ( V_1 -> V_12 < 0 ) {
F_33 ( V_33 , L_1 ) ;
return V_1 -> V_12 ;
}
V_82 = F_34 ( V_80 , V_85 , 0 ) ;
V_1 -> V_4 = F_35 ( V_33 , V_82 ) ;
if ( F_36 ( V_1 -> V_4 ) )
return F_37 ( V_1 -> V_4 ) ;
F_38 ( V_80 , V_1 ) ;
V_1 -> V_30 = F_39 ( & V_80 -> V_33 , V_80 -> V_86 ,
& V_87 , V_88 ) ;
if ( F_36 ( V_1 -> V_30 ) ) {
F_33 ( V_33 , L_2 ,
V_20 ) ;
return F_37 ( V_1 -> V_30 ) ;
}
F_1 ( V_1 , V_23 , V_22 ) ;
F_1 ( V_1 , 0 , V_89 ) ;
F_7 ( V_1 , 0 , V_90 ) ;
F_7 ( V_1 , 0 , V_25 ) ;
F_7 ( V_1 , 0 , V_10 ) ;
V_20 = F_40 ( V_33 , V_1 -> V_12 , F_10 ,
0 , L_3 , V_1 ) ;
if ( V_20 < 0 ) {
F_33 ( V_33 , L_4 ) ;
return V_20 ;
}
F_1 ( V_1 , V_91 , V_89 ) ;
F_7 ( V_1 , V_92 ,
V_90 ) ;
F_7 ( V_1 , V_64 , V_10 ) ;
F_41 ( & V_80 -> V_33 , 0 ) ;
return 0 ;
}
static int T_6 F_42 ( struct V_79 * V_80 )
{
struct V_1 * V_1 = F_43 ( V_80 ) ;
F_41 ( & V_80 -> V_33 , 0 ) ;
F_1 ( V_1 , 0 , V_89 ) ;
return 0 ;
}
