static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( & V_2 -> V_4 -> V_5 ) ;
F_3 ( V_2 -> V_4 , V_6 ) ;
F_4 ( & V_2 -> V_4 -> V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_7 , V_8 ;
F_2 ( & V_2 -> V_9 ) ;
V_8 = F_6 ( V_2 , 1 ) ;
F_4 ( & V_2 -> V_9 ) ;
if ( V_8 < 0 )
return V_8 ;
F_7 ( L_1 , V_8 ) ;
V_7 = F_8 ( V_2 , V_8 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
static long long F_9 ( struct V_1 * V_2 )
{
long long V_10 ;
F_10 ( & V_2 -> V_11 ) ;
V_10 = V_2 -> V_12 . V_13 + V_2 -> V_12 . V_14 + V_2 -> V_12 . V_15 ;
F_11 ( & V_2 -> V_11 ) ;
return V_10 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_7 , V_16 = 0 ;
long long V_17 , V_18 ;
do {
V_17 = F_9 ( V_2 ) ;
F_7 ( L_2 , V_17 ) ;
F_1 ( V_2 , V_19 ) ;
V_18 = F_9 ( V_2 ) ;
if ( V_18 < V_17 )
return - V_20 ;
F_7 ( L_3 , V_18 ) ;
F_7 ( L_4 ) ;
V_7 = F_5 ( V_2 ) ;
if ( ! V_7 )
return - V_20 ;
if ( V_7 != - V_20 && V_7 != - V_21 )
return V_7 ;
F_7 ( L_5 , V_16 ) ;
V_7 = F_13 ( V_2 ) ;
if ( V_7 )
return V_7 ;
} while ( V_16 ++ < V_22 );
return - V_21 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_23 ;
long long V_24 ;
V_24 = V_2 -> V_12 . V_25 + V_2 -> V_12 . V_13 + V_2 -> V_12 . V_26 ;
V_24 += V_24 << 1 ;
V_23 = F_15 ( V_24 + V_2 -> V_27 - 1 , V_2 -> V_27 ) ;
V_23 += 1 ;
if ( V_23 < V_28 )
V_23 = V_28 ;
return V_23 ;
}
long long F_16 ( const struct V_1 * V_2 , int V_29 )
{
int V_30 ;
long long V_31 ;
V_31 = V_2 -> V_32 - V_2 -> V_33 . V_34 ;
V_30 = V_29 ;
V_30 += 1 ;
V_30 += V_2 -> V_35 - 1 ;
V_30 += 1 ;
V_31 -= ( long long ) V_30 * V_2 -> V_36 ;
V_31 -= V_2 -> V_33 . V_37 ;
V_31 -= V_2 -> V_33 . V_38 ;
if ( V_2 -> V_33 . V_23 > V_29 ) {
V_30 = V_2 -> V_33 . V_23 - V_29 ;
V_31 -= V_30 * V_2 -> V_39 ;
}
return V_31 > 0 ? V_31 : 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
if ( F_18 ( F_19 () , V_2 -> V_40 ) || F_20 ( V_41 ) ||
( ! F_21 ( V_2 -> V_42 , V_43 ) && F_22 ( V_2 -> V_42 ) ) )
return 1 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
long long V_44 , V_31 ;
int V_45 , V_46 , V_29 ;
V_29 = F_14 ( V_2 ) ;
if ( V_29 > V_2 -> V_33 . V_23 )
V_46 = V_29 - V_2 -> V_33 . V_23 ;
else
V_46 = 0 ;
V_45 = V_2 -> V_33 . V_47 + V_2 -> V_48 + V_2 -> V_49 -
V_2 -> V_33 . V_50 ;
if ( F_24 ( V_46 > V_45 ) ) {
F_7 ( L_6 ,
V_29 , V_2 -> V_12 . V_29 , V_46 ) ;
return - V_21 ;
}
V_31 = F_16 ( V_2 , V_29 ) ;
V_44 = V_2 -> V_12 . V_14 + V_2 -> V_12 . V_15 ;
if ( F_24 ( V_31 < V_44 ) ) {
F_7 ( L_7 ,
V_31 , V_44 ) ;
return - V_21 ;
}
if ( V_31 - V_44 <= V_2 -> V_51 && ! F_17 ( V_2 ) )
return - V_21 ;
V_2 -> V_12 . V_29 = V_29 ;
return 0 ;
}
static int F_25 ( const struct V_1 * V_2 ,
const struct V_52 * V_53 )
{
int V_54 ;
V_54 = V_53 -> V_55 + ( V_53 -> V_56 << V_57 ) +
V_53 -> V_58 ;
return V_54 * V_2 -> V_59 ;
}
static int F_26 ( const struct V_1 * V_2 ,
const struct V_52 * V_53 )
{
int V_14 ;
V_14 = V_53 -> V_55 ? V_2 -> V_12 . V_60 : 0 ;
if ( V_53 -> V_56 )
V_14 += V_2 -> V_12 . V_61 ;
if ( V_53 -> V_58 )
V_14 += V_2 -> V_12 . V_62 ;
V_14 += V_53 -> V_63 ;
return V_14 ;
}
static int F_27 ( const struct V_1 * V_2 ,
const struct V_52 * V_53 )
{
int V_15 ;
V_15 = V_53 -> V_64 ? V_2 -> V_12 . V_61 : 0 ;
if ( V_53 -> V_65 )
V_15 += V_2 -> V_12 . V_60 << ( V_53 -> V_65 - 1 ) ;
if ( V_53 -> V_66 )
V_15 += V_2 -> V_12 . V_62 ;
V_15 += V_53 -> V_67 ;
return V_15 ;
}
int F_28 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
int V_68 ( V_69 ) , V_68 ( V_70 ) ;
int V_7 , V_13 , V_14 , V_15 , V_71 = 0 ;
F_29 ( V_53 -> V_56 <= 1 ) ;
F_29 ( V_53 -> V_64 <= 1 ) ;
F_29 ( V_53 -> V_58 <= 1 ) ;
F_29 ( V_53 -> V_66 <= 1 ) ;
F_29 ( V_53 -> V_55 <= 1 ) ;
F_29 ( V_53 -> V_63 <= V_72 ) ;
F_29 ( V_53 -> V_65 <= 4 ) ;
F_29 ( V_53 -> V_67 <= V_72 * 4 ) ;
F_29 ( ! ( V_53 -> V_63 & 7 ) ) ;
F_29 ( ! ( V_53 -> V_67 & 7 ) ) ;
V_14 = F_26 ( V_2 , V_53 ) ;
V_15 = F_27 ( V_2 , V_53 ) ;
if ( ! V_14 && ! V_15 )
return 0 ;
V_13 = F_25 ( V_2 , V_53 ) ;
V_73:
F_10 ( & V_2 -> V_11 ) ;
F_29 ( V_2 -> V_12 . V_13 >= 0 ) ;
F_29 ( V_2 -> V_12 . V_14 >= 0 ) ;
F_29 ( V_2 -> V_12 . V_15 >= 0 ) ;
if ( F_24 ( V_2 -> V_12 . V_74 ) && ( V_2 -> V_12 . V_75 || ! F_17 ( V_2 ) ) ) {
F_7 ( L_8 ) ;
F_11 ( & V_2 -> V_11 ) ;
return - V_21 ;
}
V_2 -> V_12 . V_13 += V_13 ;
V_2 -> V_12 . V_14 += V_14 ;
V_2 -> V_12 . V_15 += V_15 ;
V_7 = F_23 ( V_2 ) ;
if ( F_30 ( ! V_7 ) ) {
V_53 -> V_13 = V_13 ;
V_53 -> V_14 = V_14 ;
V_53 -> V_15 = V_15 ;
F_11 ( & V_2 -> V_11 ) ;
return 0 ;
}
V_2 -> V_12 . V_13 -= V_13 ;
V_2 -> V_12 . V_14 -= V_14 ;
V_2 -> V_12 . V_15 -= V_15 ;
F_11 ( & V_2 -> V_11 ) ;
if ( V_53 -> V_76 ) {
F_7 ( L_9 ) ;
return V_7 ;
}
V_7 = F_12 ( V_2 ) ;
F_31 () ;
if ( V_7 == - V_20 ) {
F_7 ( L_10 ) ;
goto V_73;
} else if ( V_7 == - V_21 ) {
if ( ! V_71 ) {
V_71 = 1 ;
F_7 ( L_11 ) ;
goto V_73;
}
F_7 ( L_12 ) ;
V_2 -> V_12 . V_74 = 1 ;
if ( F_17 ( V_2 ) || V_2 -> V_51 == 0 )
V_2 -> V_12 . V_75 = 1 ;
F_32 () ;
} else
F_33 ( L_13 , V_7 ) ;
return V_7 ;
}
void F_34 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
F_29 ( V_53 -> V_56 <= 1 ) ;
F_29 ( V_53 -> V_64 <= 1 ) ;
F_29 ( V_53 -> V_58 <= 1 ) ;
F_29 ( V_53 -> V_66 <= 1 ) ;
F_29 ( V_53 -> V_55 <= 1 ) ;
F_29 ( V_53 -> V_63 <= V_72 ) ;
F_29 ( V_53 -> V_65 <= 4 ) ;
F_29 ( V_53 -> V_67 <= V_72 * 4 ) ;
F_29 ( ! ( V_53 -> V_63 & 7 ) ) ;
F_29 ( ! ( V_53 -> V_67 & 7 ) ) ;
if ( ! V_53 -> V_77 ) {
F_29 ( V_53 -> V_13 >= 0 ) ;
F_29 ( V_53 -> V_14 >= 0 ) ;
F_29 ( V_53 -> V_15 >= 0 ) ;
}
if ( V_53 -> V_77 ) {
V_53 -> V_14 = F_26 ( V_2 , V_53 ) ;
V_53 -> V_15 = F_27 ( V_2 , V_53 ) ;
V_53 -> V_13 = F_25 ( V_2 , V_53 ) ;
}
if ( ! V_53 -> V_14 && ! V_53 -> V_15 )
return;
V_2 -> V_12 . V_74 = V_2 -> V_12 . V_75 = 0 ;
F_32 () ;
F_10 ( & V_2 -> V_11 ) ;
V_2 -> V_12 . V_13 -= V_53 -> V_13 ;
V_2 -> V_12 . V_26 += V_53 -> V_13 ;
V_2 -> V_12 . V_14 -= V_53 -> V_14 ;
V_2 -> V_12 . V_15 -= V_53 -> V_15 ;
V_2 -> V_12 . V_29 = F_14 ( V_2 ) ;
F_29 ( V_2 -> V_12 . V_13 >= 0 ) ;
F_29 ( V_2 -> V_12 . V_14 >= 0 ) ;
F_29 ( V_2 -> V_12 . V_15 >= 0 ) ;
F_29 ( V_2 -> V_12 . V_29 < V_2 -> V_78 ) ;
F_29 ( ! ( V_2 -> V_12 . V_13 & 7 ) ) ;
F_29 ( ! ( V_2 -> V_12 . V_14 & 7 ) ) ;
F_29 ( ! ( V_2 -> V_12 . V_15 & 7 ) ) ;
F_11 ( & V_2 -> V_11 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_11 ) ;
V_2 -> V_12 . V_13 -= V_2 -> V_59 << V_57 ;
V_2 -> V_12 . V_14 -= V_2 -> V_12 . V_61 ;
V_2 -> V_12 . V_15 += V_2 -> V_12 . V_61 ;
V_2 -> V_12 . V_29 = F_14 ( V_2 ) ;
F_11 ( & V_2 -> V_11 ) ;
}
void F_36 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
struct V_52 V_53 ;
memset ( & V_53 , 0 , sizeof( struct V_52 ) ) ;
V_53 . V_15 = V_2 -> V_12 . V_60 + F_37 ( V_80 -> V_81 , 8 ) ;
F_34 ( V_2 , & V_53 ) ;
}
long long F_38 ( const struct V_1 * V_2 , long long free )
{
int V_82 , V_83 , V_84 ;
V_84 = V_2 -> V_85 > 3 ? V_2 -> V_85 >> 1 : 2 ;
V_83 = V_86 ;
V_82 = V_87 ;
V_82 += ( V_2 -> V_59 * 3 ) / ( V_84 - 1 ) ;
free *= V_83 ;
return F_15 ( free , V_82 ) ;
}
long long F_39 ( struct V_1 * V_2 )
{
int V_46 , V_45 ;
long long V_31 , V_44 , free ;
F_29 ( V_2 -> V_12 . V_29 == F_14 ( V_2 ) ) ;
V_44 = V_2 -> V_12 . V_14 + V_2 -> V_12 . V_15 ;
V_31 = F_16 ( V_2 , V_2 -> V_12 . V_29 ) ;
if ( V_2 -> V_12 . V_29 > V_2 -> V_33 . V_23 )
V_46 = V_2 -> V_12 . V_29 - V_2 -> V_33 . V_23 ;
else
V_46 = 0 ;
V_45 = V_2 -> V_33 . V_47 + V_2 -> V_48 + V_2 -> V_49 -
V_2 -> V_33 . V_50 ;
V_45 -= V_46 ;
V_31 += V_45 * ( V_2 -> V_39 - V_2 -> V_88 ) ;
if ( V_31 > V_44 )
free = F_38 ( V_2 , V_31 - V_44 ) ;
else
free = 0 ;
return free ;
}
long long F_40 ( struct V_1 * V_2 )
{
long long free ;
F_10 ( & V_2 -> V_11 ) ;
free = F_39 ( V_2 ) ;
F_11 ( & V_2 -> V_11 ) ;
return free ;
}
