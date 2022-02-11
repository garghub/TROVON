static inline void F_1 ( T_1 T_2 * V_1 )
{
F_2 ( L_1
L_2
L_3
L_4
L_5 ,
F_3 ( V_2 , V_1 ) ,
F_4 ( V_3 , V_1 ) ,
F_5 ( V_4 , V_1 ) ,
F_5 ( V_5 , V_1 ) ,
F_5 ( V_6 , V_1 ) ) ;
}
static inline int F_6 ( struct V_7 * V_8 , T_3 V_9 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
T_3 V_12 , V_13 = V_14 , V_15 ;
T_1 T_2 * V_1 = V_11 -> V_16 ;
V_15 = V_11 -> V_17 ;
while ( V_13 -- ) {
V_12 = F_5 ( V_18 + 4 , V_1 ) & V_19 ;
if ( ( V_15 == V_12 ) ||
( V_15 > V_12 &&
( V_11 -> V_20 . V_21 - V_15 + V_12 ) >= V_9 ) ||
( V_15 < V_12 && ( V_12 - V_15 ) >= V_9 ) ) {
return 0 ;
}
}
F_2 ( L_6 ) ;
F_1 ( V_1 ) ;
V_11 -> V_22 |= V_23 ;
V_8 -> V_24 . V_25 = 1 ;
return 1 ;
}
static inline int F_7 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
T_1 T_2 * V_1 = V_11 -> V_16 ;
int V_13 = V_14 ;
if ( F_6 ( V_8 , V_11 -> V_20 . V_21 ) )
return 1 ;
while( ( F_3 ( V_26 , V_1 ) & 0x7B ) != 0x7B && -- V_13 ) ;
if ( V_13 ) return 0 ;
F_2 ( L_7 ) ;
F_2 ( L_8 , F_5 ( V_26 , V_1 ) ) ;
F_1 ( V_1 ) ;
V_11 -> V_22 |= V_23 ;
V_8 -> V_24 . V_25 = 1 ;
return 1 ;
}
static inline T_3 F_8 ( struct V_7 * V_8 , T_3 V_9 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
if ( V_11 -> V_22 & V_27 )
F_7 ( V_8 ) ;
return F_6 ( V_8 , V_9 ) ;
}
static inline void F_9 ( struct V_10 * V_11 )
{
T_1 T_2 * V_1 = V_11 -> V_16 ;
F_10 ( V_18 , V_1 , V_11 -> V_17 ) ;
}
static inline void F_11 ( int V_28 , int V_29 , int V_30 ,
int V_31 , int V_32 , int V_33 , int V_34 ,
int V_35 , struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
if ( F_8 ( V_8 , 24 + V_36 ) ) return;
F_12 ( V_37 | V_38 | 4 ) ;
F_12 ( V_31 | V_34 << 16 | V_30 | V_39 | V_35 ) ;
F_12 ( V_29 << 16 | V_28 ) ;
F_12 ( V_33 ) ;
F_12 ( V_30 ) ;
F_12 ( V_32 ) ;
F_9 ( V_11 ) ;
}
static inline void F_13 ( int V_40 , int V_41 , int V_42 , int V_33 ,
int V_34 , int V_43 , int V_35 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
if ( F_8 ( V_8 , 24 + V_36 ) ) return;
F_12 ( V_37 | V_44 | 3 ) ;
F_12 ( V_34 << 16 | V_42 | V_45 | V_39 | V_35 ) ;
F_12 ( V_41 << 16 | V_40 ) ;
F_12 ( V_33 ) ;
F_12 ( V_43 ) ;
F_12 ( V_46 ) ;
F_9 ( V_11 ) ;
}
static inline void F_14 ( int V_28 , int V_29 , int V_30 ,
int V_47 , int V_35 , int V_34 ,
int V_33 , const T_3 * V_32 , int V_48 ,
int V_49 , struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
if ( F_8 ( V_8 , 24 + ( V_47 << 2 ) + V_36 ) ) return;
F_12 ( V_37 | V_50 | ( 4 + V_47 ) ) ;
F_12 ( V_39 | V_35 | V_34 << 16 | V_30 ) ;
F_12 ( V_29 << 16 | V_28 ) ;
F_12 ( V_33 ) ;
F_12 ( V_48 ) ;
F_12 ( V_49 ) ;
while ( V_47 -- )
F_12 ( * V_32 ++ ) ;
F_9 ( V_11 ) ;
}
static inline void F_15 ( int V_51 , struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
if ( F_8 ( V_8 , 8 + V_36 ) ) return;
F_12 ( V_52 | V_53 ) ;
F_12 ( V_46 ) ;
F_9 ( V_11 ) ;
if ( F_8 ( V_8 , 8 + V_36 ) ) return;
F_12 ( V_52 | V_54 | ( ( V_11 -> V_42 >> 3 ) << 8 ) ) ;
F_12 ( ( V_11 -> V_55 . V_51 << 12 ) + V_51 ) ;
F_9 ( V_11 ) ;
}
static inline void F_16 ( struct V_10 * V_11 , T_3 V_56 )
{
T_3 V_57 ;
T_1 T_2 * V_1 = V_11 -> V_16 ;
V_57 = F_5 ( V_18 + 12 , V_1 ) ;
if ( V_56 == V_58 )
V_57 &= ~ 1 ;
else
V_57 |= 1 ;
F_17 () ;
F_10 ( V_18 + 12 , V_1 , V_57 ) ;
}
void F_18 ( struct V_7 * V_8 , const struct V_59 * V_60 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
T_3 V_61 , V_62 , V_40 , V_41 , V_33 , V_34 = 0 , V_63 = 0 ;
if ( ! V_8 -> V_64 . V_65 || V_11 -> V_22 & V_23 ||
V_11 -> V_66 == 4 ) {
F_19 ( V_8 , V_60 ) ;
return;
}
if ( V_11 -> V_66 == 1 )
V_63 = V_60 -> V_63 ;
else
V_63 = ( ( T_3 * ) ( V_8 -> V_67 ) ) [ V_60 -> V_63 ] ;
V_34 = V_68 [ V_60 -> V_34 ] ;
V_61 = V_60 -> V_61 * V_11 -> V_66 ;
V_40 = V_60 -> V_40 * V_11 -> V_66 ;
V_62 = V_60 -> V_62 ;
V_41 = V_60 -> V_41 ;
V_33 = V_8 -> V_69 . V_70 + ( V_62 * V_8 -> V_69 . V_71 ) + V_61 ;
F_13 ( V_40 , V_41 , V_8 -> V_69 . V_71 , V_33 , V_34 , V_63 ,
V_11 -> V_35 , V_8 ) ;
}
void F_20 ( struct V_7 * V_8 , const struct V_72 * V_73 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
T_3 V_74 , V_75 , V_61 , V_62 , V_42 , V_40 , V_41 , V_32 , V_33 , V_31 ;
if ( ! V_8 -> V_64 . V_65 || V_11 -> V_22 & V_23 ||
V_11 -> V_66 == 4 ) {
F_21 ( V_8 , V_73 ) ;
return;
}
V_61 = V_73 -> V_61 * V_11 -> V_66 ;
V_74 = V_73 -> V_74 * V_11 -> V_66 ;
V_40 = V_73 -> V_40 * V_11 -> V_66 ;
V_75 = V_73 -> V_75 ;
V_62 = V_73 -> V_62 ;
V_41 = V_73 -> V_41 ;
if ( V_61 <= V_74 ) {
V_31 = V_76 ;
}
else {
V_31 = V_77 ;
V_74 += V_40 - 1 ;
V_61 += V_40 - 1 ;
}
if ( V_62 <= V_75 ) {
V_42 = V_8 -> V_69 . V_71 ;
}
else {
V_42 = ( - ( V_8 -> V_69 . V_71 ) ) & 0xFFFF ;
V_75 += V_41 - 1 ;
V_62 += V_41 - 1 ;
}
V_32 = V_8 -> V_69 . V_70 + ( V_75 * V_8 -> V_69 . V_71 ) + V_74 ;
V_33 = V_8 -> V_69 . V_70 + ( V_62 * V_8 -> V_69 . V_71 ) + V_61 ;
F_11 ( V_40 , V_41 , V_42 , V_31 , V_32 , V_33 ,
V_78 , V_11 -> V_35 , V_8 ) ;
}
void F_22 ( struct V_7 * V_8 , const struct V_79 * V_80 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
T_3 V_49 = 0 , V_48 = 0 , V_21 , V_81 ;
if ( ! V_8 -> V_64 . V_65 || V_11 -> V_22 & V_23 ||
V_11 -> V_66 == 4 || V_80 -> V_66 != 1 ) {
F_23 ( V_8 , V_80 ) ;
return;
}
switch ( V_8 -> V_64 . V_82 ) {
case 8 :
V_49 = V_80 -> V_83 ;
V_48 = V_80 -> V_84 ;
break;
case 16 :
case 24 :
V_49 = ( ( T_3 * ) ( V_8 -> V_67 ) ) [ V_80 -> V_83 ] ;
V_48 = ( ( T_3 * ) ( V_8 -> V_67 ) ) [ V_80 -> V_84 ] ;
break;
}
V_81 = V_8 -> V_69 . V_70 + ( V_80 -> V_62 * V_8 -> V_69 . V_71 ) +
( V_80 -> V_61 * V_11 -> V_66 ) ;
V_21 = ( V_80 -> V_40 + 7 ) / 8 + 1 ;
V_21 &= ~ 1 ;
V_21 *= V_80 -> V_41 ;
V_21 += 7 ;
V_21 &= ~ 7 ;
F_14 ( V_80 -> V_40 * V_11 -> V_66 ,
V_80 -> V_41 , V_8 -> V_69 . V_71 ,
V_21 / 4 , V_11 -> V_35 ,
V_78 , V_81 , ( T_3 * ) V_80 -> V_85 ,
V_48 , V_49 , V_8 ) ;
}
int F_24 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
if ( ! V_8 -> V_64 . V_65 || V_11 -> V_22 & V_23 )
return 0 ;
return F_7 ( V_8 ) ;
}
void F_25 ( T_3 V_51 , struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
T_1 T_2 * V_1 = V_11 -> V_16 ;
if ( ! V_8 -> V_64 . V_65 || V_11 -> V_22 & V_23 )
F_10 ( V_86 , V_1 , V_11 -> V_55 . V_87 + V_51 ) ;
else
F_15 ( V_51 , V_8 ) ;
}
void F_26 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_11 ;
T_3 V_88 , V_89 ;
T_1 T_2 * V_1 = V_11 -> V_16 ;
F_7 ( V_8 ) ;
F_16 ( V_11 , V_58 ) ;
F_10 ( V_18 , V_1 , 0 ) ;
F_10 ( V_18 + 4 , V_1 , 0 ) ;
V_11 -> V_17 = 0 ;
V_89 = F_5 ( V_18 + 8 , V_1 ) & ~ V_90 ;
V_88 = V_11 -> V_20 . V_87 ;
F_10 ( V_18 + 8 , V_1 , V_89 | V_88 ) ;
V_88 = F_5 ( V_18 + 12 , V_1 ) ;
V_88 &= ~ V_91 ;
V_89 = ( V_11 -> V_20 . V_21 - V_92 ) & V_91 ;
F_10 ( V_18 + 12 , V_1 , V_88 | V_89 ) ;
F_16 ( V_11 , V_93 ) ;
}
