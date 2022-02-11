static inline bool F_1 ( struct V_1 * V_2 )
{
return ! ! F_2 ( V_3 ,
F_3 ( V_2 -> V_4 + V_5 ) ) ;
}
static inline bool F_4 ( struct V_1 * V_2 )
{
return F_2 ( V_6 | V_7 | V_8 ,
F_3 ( V_2 -> V_4 + V_5 ) ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 )
{
unsigned int V_9 = V_2 -> V_10 ;
unsigned int V_11 = 0 ;
T_1 V_12 = 0 ;
T_2 V_13 ;
while ( V_9 -- ) {
V_13 = * V_2 -> V_14 ++ ;
V_12 |= ( V_13 & 0xff ) << V_11 ;
V_11 += 8 ;
}
V_2 -> V_15 -- ;
return V_12 ;
}
static inline void F_6 ( struct V_1 * V_2 ,
T_1 V_12 )
{
unsigned int V_9 = V_2 -> V_10 ;
unsigned int V_11 = 0 ;
T_2 V_13 ;
while ( V_9 -- ) {
V_13 = ( V_12 >> V_11 ) & 0xff ;
* V_2 -> V_16 ++ = V_13 ;
V_11 += 8 ;
}
V_2 -> V_17 -- ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
while ( V_2 -> V_17 &&
F_4 ( V_2 ) )
F_6 ( V_2 ,
F_3 ( V_2 -> V_4 + V_18 ) ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
while ( V_2 -> V_15 &&
! F_1 ( V_2 ) )
F_9 ( F_5 ( V_2 ) ,
V_2 -> V_4 + V_19 ) ;
}
static inline T_1 F_10 ( struct V_1 * V_2 ,
T_1 V_20 )
{
if ( V_2 -> V_17 > V_21 )
V_20 |= V_22 ;
else
V_20 |= V_23 ;
return V_20 ;
}
static inline void F_11 ( struct V_1 * V_2 ,
unsigned int V_24 )
{
V_2 -> V_15 = V_24 ;
V_2 -> V_17 = V_24 ;
V_2 -> V_25 -= V_24 * V_2 -> V_10 ;
V_2 -> V_26 = false ;
if ( V_24 < V_27 || ! V_2 -> V_25 )
V_2 -> V_28 = true ;
else
V_2 -> V_28 = false ;
F_12 ( V_29 ,
F_13 ( V_29 ,
V_24 ) ,
V_2 -> V_4 + V_30 ) ;
F_8 ( V_2 ) ;
}
static T_3 F_14 ( int V_31 , void * V_12 )
{
struct V_1 * V_2 = ( void * ) V_12 ;
T_1 V_32 = F_3 ( V_2 -> V_4 + V_33 ) ;
T_1 V_34 = F_3 ( V_2 -> V_4 + V_5 ) & V_32 ;
V_32 &= ~ ( V_22 | V_23 ) ;
F_7 ( V_2 ) ;
if ( ! V_2 -> V_15 && ! V_2 -> V_17 ) {
V_2 -> V_26 = true ;
V_32 |= V_35 ;
V_34 = F_3 ( V_2 -> V_4 + V_5 ) & V_32 ;
}
if ( ( V_34 & V_36 ) && V_2 -> V_26 ) {
unsigned int V_24 ;
F_9 ( V_36 , V_2 -> V_4 + V_5 ) ;
V_32 &= ~ V_35 ;
if ( V_2 -> V_28 ) {
F_15 ( 0 , V_2 -> V_4 + V_33 ) ;
F_16 ( V_2 -> V_37 ) ;
return V_38 ;
}
V_24 = F_17 (unsigned int,
spicc->xfer_remain / spicc->bytes_per_word,
SPICC_BURST_MAX) ;
F_11 ( V_2 , V_24 ) ;
F_12 ( V_39 , V_39 ,
V_2 -> V_4 + V_30 ) ;
}
V_32 = F_10 ( V_2 , V_32 ) ;
F_15 ( V_32 , V_2 -> V_4 + V_33 ) ;
return V_38 ;
}
static T_1 F_18 ( struct V_1 * V_2 , T_1 V_40 ,
T_1 V_41 )
{
unsigned long V_42 , V_43 ;
unsigned int V_44 , div ;
V_42 = F_19 ( V_2 -> V_45 ) ;
for ( V_44 = 0 ; V_44 < 7 ; ++ V_44 ) {
V_43 = V_42 >> ( V_44 + 2 ) ;
if ( V_43 <= V_41 )
break;
}
if ( V_44 > 7 ) {
div = 7 ;
F_20 ( & V_2 -> V_46 -> V_47 , L_1 ,
V_41 ) ;
} else
div = V_44 ;
F_21 ( & V_2 -> V_46 -> V_47 , L_2 ,
V_42 , V_41 , V_43 , div ) ;
V_40 &= ~ V_48 ;
V_40 |= F_13 ( V_48 , div ) ;
return V_40 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
T_1 V_40 , V_51 ;
V_40 = V_51 = F_3 ( V_2 -> V_4 + V_30 ) ;
V_40 = F_18 ( V_2 , V_40 , V_50 -> V_52 ) ;
V_40 &= ~ V_53 ;
V_40 |= F_13 ( V_53 ,
( V_2 -> V_10 << 3 ) - 1 ) ;
if ( V_40 != V_51 )
F_9 ( V_40 , V_2 -> V_4 + V_30 ) ;
}
static int F_23 ( struct V_54 * V_37 ,
struct V_55 * V_56 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_24 ( V_37 ) ;
unsigned int V_24 ;
T_1 V_31 = 0 ;
V_2 -> V_50 = V_50 ;
V_2 -> V_14 = ( T_2 * ) V_50 -> V_14 ;
V_2 -> V_16 = ( T_2 * ) V_50 -> V_16 ;
V_2 -> V_25 = V_50 -> V_57 ;
V_2 -> V_10 =
F_25 ( V_2 -> V_50 -> V_58 , 8 ) ;
F_22 ( V_2 , V_50 ) ;
V_24 = F_17 (unsigned int,
spicc->xfer_remain / spicc->bytes_per_word,
SPICC_BURST_MAX) ;
F_11 ( V_2 , V_24 ) ;
V_31 = F_10 ( V_2 , V_31 ) ;
F_12 ( V_39 , V_39 , V_2 -> V_4 + V_30 ) ;
F_9 ( V_31 , V_2 -> V_4 + V_33 ) ;
return 1 ;
}
static int F_26 ( struct V_54 * V_37 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_24 ( V_37 ) ;
struct V_55 * V_56 = V_60 -> V_56 ;
T_1 V_40 = 0 ;
V_2 -> V_60 = V_60 ;
V_40 |= V_61 ;
V_40 |= V_62 ;
if ( V_56 -> V_63 & V_64 )
V_40 |= V_65 ;
else
V_40 &= ~ V_65 ;
if ( V_56 -> V_63 & V_66 )
V_40 |= V_67 ;
else
V_40 &= ~ V_67 ;
if ( V_56 -> V_63 & V_68 )
V_40 |= V_69 ;
else
V_40 &= ~ V_69 ;
if ( V_56 -> V_63 & V_70 )
V_40 |= F_13 ( V_71 , V_72 ) ;
else
V_40 |= F_13 ( V_71 , V_73 ) ;
V_40 |= F_13 ( V_74 , V_56 -> V_75 ) ;
V_40 |= F_13 ( V_53 , 8 - 1 ) ;
F_9 ( V_40 , V_2 -> V_4 + V_30 ) ;
F_9 ( 0 , V_2 -> V_4 + V_76 ) ;
F_12 ( F_27 ( 24 ) , F_27 ( 24 ) , V_2 -> V_4 + V_77 ) ;
return 0 ;
}
static int F_28 ( struct V_54 * V_37 )
{
struct V_1 * V_2 = F_24 ( V_37 ) ;
F_15 ( 0 , V_2 -> V_4 + V_33 ) ;
F_12 ( V_61 , 0 , V_2 -> V_4 + V_30 ) ;
F_29 ( & V_2 -> V_46 -> V_47 ) ;
return 0 ;
}
static int F_30 ( struct V_55 * V_56 )
{
int V_78 = 0 ;
if ( ! V_56 -> V_79 )
V_56 -> V_79 = F_24 ( V_56 -> V_37 ) ;
else if ( F_31 ( V_56 -> V_80 ) )
goto V_81;
else if ( V_56 -> V_80 == - V_82 )
return 0 ;
if ( F_31 ( V_56 -> V_80 ) ) {
V_78 = F_32 ( V_56 -> V_80 , F_33 ( & V_56 -> V_47 ) ) ;
if ( V_78 ) {
F_34 ( & V_56 -> V_47 , L_3 ) ;
return V_78 ;
}
}
V_81:
V_78 = F_35 ( V_56 -> V_80 ,
! ( V_56 -> V_63 & V_68 ) ) ;
return V_78 ;
}
static void F_36 ( struct V_55 * V_56 )
{
if ( F_31 ( V_56 -> V_80 ) )
F_37 ( V_56 -> V_80 ) ;
V_56 -> V_79 = NULL ;
}
static int F_38 ( struct V_83 * V_46 )
{
struct V_54 * V_37 ;
struct V_1 * V_2 ;
struct V_84 * V_85 ;
int V_78 , V_31 , V_86 ;
V_37 = F_39 ( & V_46 -> V_47 , sizeof( * V_2 ) ) ;
if ( ! V_37 ) {
F_34 ( & V_46 -> V_47 , L_4 ) ;
return - V_87 ;
}
V_2 = F_24 ( V_37 ) ;
V_2 -> V_37 = V_37 ;
V_2 -> V_46 = V_46 ;
F_40 ( V_46 , V_2 ) ;
V_85 = F_41 ( V_46 , V_88 , 0 ) ;
V_2 -> V_4 = F_42 ( & V_46 -> V_47 , V_85 ) ;
if ( F_43 ( V_2 -> V_4 ) ) {
F_34 ( & V_46 -> V_47 , L_5 ) ;
V_78 = F_44 ( V_2 -> V_4 ) ;
goto V_89;
}
F_9 ( 0 , V_2 -> V_4 + V_33 ) ;
V_31 = F_45 ( V_46 , 0 ) ;
V_78 = F_46 ( & V_46 -> V_47 , V_31 , F_14 ,
0 , NULL , V_2 ) ;
if ( V_78 ) {
F_34 ( & V_46 -> V_47 , L_6 ) ;
goto V_89;
}
V_2 -> V_45 = F_47 ( & V_46 -> V_47 , L_7 ) ;
if ( F_43 ( V_2 -> V_45 ) ) {
F_34 ( & V_46 -> V_47 , L_8 ) ;
V_78 = F_44 ( V_2 -> V_45 ) ;
goto V_89;
}
V_78 = F_48 ( V_2 -> V_45 ) ;
if ( V_78 ) {
F_34 ( & V_46 -> V_47 , L_9 ) ;
goto V_89;
}
V_86 = F_19 ( V_2 -> V_45 ) ;
F_29 ( & V_46 -> V_47 ) ;
V_37 -> V_90 = 4 ;
V_37 -> V_47 . V_91 = V_46 -> V_47 . V_91 ;
V_37 -> V_92 = V_66 | V_64 | V_68 ;
V_37 -> V_93 = F_49 ( 32 ) |
F_49 ( 24 ) |
F_49 ( 16 ) |
F_49 ( 8 ) ;
V_37 -> V_94 = ( V_95 | V_96 ) ;
V_37 -> V_97 = V_86 >> 9 ;
V_37 -> V_98 = F_30 ;
V_37 -> V_99 = F_36 ;
V_37 -> V_100 = F_26 ;
V_37 -> V_101 = F_28 ;
V_37 -> V_102 = F_23 ;
if ( ( V_86 >> 2 ) > V_103 )
V_37 -> V_104 = V_103 ;
else
V_37 -> V_104 = V_86 >> 2 ;
V_78 = F_50 ( & V_46 -> V_47 , V_37 ) ;
if ( ! V_78 )
return 0 ;
F_34 ( & V_46 -> V_47 , L_10 ) ;
V_89:
F_51 ( V_37 ) ;
return V_78 ;
}
static int F_52 ( struct V_83 * V_46 )
{
struct V_1 * V_2 = F_53 ( V_46 ) ;
F_15 ( 0 , V_2 -> V_4 + V_30 ) ;
F_54 ( V_2 -> V_45 ) ;
return 0 ;
}
