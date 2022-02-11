static inline void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_7 ;
int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + F_3 ( V_4 ) , V_7 ,
V_7 & V_10 ,
10 , V_11 ) ;
if ( V_8 )
F_4 ( V_6 , L_1 ,
V_4 == V_12 ? L_2 : L_3 ) ;
}
static T_2 F_5 ( int V_13 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
enum V_3 V_4 ;
T_1 V_15 , V_16 ;
V_15 = F_6 ( V_2 -> V_9 + V_17 ) & V_18 ;
if ( V_15 ) {
V_4 = V_19 ;
V_15 = F_6 ( V_2 -> V_9 + V_20 ) ;
if ( V_15 & V_2 -> V_21 ) {
V_2 -> V_21 = 0 ;
F_7 ( & V_2 -> V_22 ) ;
} else {
return V_23 ;
}
} else {
V_16 = F_8 ( V_2 -> V_9 + V_24 ) & V_18 ;
if ( V_16 ) {
V_4 = V_12 ;
F_7 ( & V_2 -> V_22 ) ;
} else {
return V_25 ;
}
}
F_9 ( 0 , V_2 -> V_9 + F_10 ( V_4 ) ) ;
return V_23 ;
}
static int F_11 ( struct V_1 * V_2 , struct F_11 * V_26 )
{
T_1 V_27 , V_28 , V_29 ;
T_1 V_30 , V_31 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_32 -> V_33 ; V_31 ++ ) {
if ( V_2 -> V_32 -> V_34 [ V_31 ] == V_26 -> V_35 )
break;
}
if ( V_31 == V_2 -> V_32 -> V_33 ) {
F_12 ( V_2 -> V_6 , L_4 ,
V_26 -> V_35 ) ;
return - V_36 ;
}
V_27 = V_31 ;
if ( V_26 -> V_4 == V_12 ) {
V_29 = V_26 -> V_37 << 3 ;
V_30 = V_27 | ( V_26 -> V_38 << V_39 ) ;
V_30 |= ( V_29 << V_40 ) ;
F_9 ( V_30 , V_2 -> V_9 + V_41 ) ;
if ( V_26 -> V_38 != V_42 )
F_9 ( F_13 ( V_26 -> V_43 ) ,
V_2 -> V_9 + V_44 ) ;
} else {
V_28 = ( V_26 -> V_37 << 3 ) +
V_26 -> V_35 * V_45 ;
V_30 = V_27 | ( V_26 -> V_38 << V_39 ) ;
V_30 |= ( V_28 << V_40 ) | V_46 ;
V_30 |= V_47 ;
F_9 ( V_30 , V_2 -> V_9 + V_48 ) ;
if ( V_26 -> V_21 )
V_2 -> V_21 = 1 << ( V_26 -> V_21 - 1 ) ;
}
return 0 ;
}
void F_14 ( struct V_1 * V_2 , struct V_49 * V_50 ,
int V_21 )
{
T_1 V_51 , V_31 , V_52 ;
T_1 V_53 = 0 ;
V_50 -> V_54 = 0 ;
V_50 -> V_55 = 0 ;
for ( V_31 = 0 ; V_31 < V_21 ; V_31 ++ ) {
V_51 = ( V_31 >> 2 ) << 2 ;
V_52 = F_8 ( V_2 -> V_9 + V_56 + V_51 ) ;
V_52 = V_52 >> ( ( V_31 % 4 ) * 8 ) ;
V_52 &= V_2 -> V_32 -> V_57 ;
if ( V_52 == V_2 -> V_32 -> V_57 ) {
V_50 -> V_55 ++ ;
continue;
}
V_50 -> V_54 += V_52 ;
V_53 = F_15 ( T_1 , V_53 , V_52 ) ;
}
V_50 -> V_53 = V_53 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_58 ) ;
F_18 ( V_2 -> V_6 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_12 ) ;
F_20 ( V_59 , V_2 -> V_9 + V_60 ) ;
F_1 ( V_2 , V_19 ) ;
F_9 ( V_59 , V_2 -> V_9 + V_61 ) ;
}
static struct V_1 * F_21 ( struct V_62 * V_63 )
{
struct V_64 * V_65 ;
struct V_1 * V_2 ;
V_65 = F_22 ( V_63 ) ;
if ( ! V_65 || ! F_23 ( V_65 ) )
return F_24 ( - V_66 ) ;
F_25 ( & V_65 -> V_6 ) ;
V_2 = F_23 ( V_65 ) ;
F_26 ( V_2 -> V_58 ) ;
F_19 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_27 ( struct V_62 * V_67 )
{
struct V_1 * V_2 = NULL ;
struct V_62 * V_63 ;
V_63 = F_28 ( V_67 , L_5 , 0 ) ;
if ( V_63 ) {
V_2 = F_21 ( V_63 ) ;
F_29 ( V_63 ) ;
}
return V_2 ;
}
int F_30 ( struct V_1 * V_2 , struct F_11 * V_26 )
{
enum V_3 V_4 = V_26 -> V_4 ;
T_3 V_68 ;
int V_8 ;
V_8 = F_31 ( & V_2 -> V_69 ) ;
if ( V_8 ) {
F_12 ( V_2 -> V_6 , L_6 ) ;
return V_8 ;
}
F_1 ( V_2 , V_4 ) ;
V_8 = F_11 ( V_2 , V_26 ) ;
if ( V_8 ) {
F_32 ( & V_2 -> V_69 ) ;
return V_8 ;
}
if ( V_26 -> V_38 != V_42 || V_4 != V_12 ) {
F_33 ( & V_2 -> V_22 ) ;
V_68 = V_18 ;
if ( V_2 -> V_32 -> V_70 && V_26 -> V_38 == V_42 )
V_68 |= V_71 ;
F_20 ( V_68 , V_2 -> V_9 + F_10 ( V_4 ) ) ;
}
F_20 ( V_72 , V_2 -> V_9 + F_34 ( V_4 ) ) ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 )
{
enum V_3 V_4 = V_12 ;
if ( F_6 ( V_2 -> V_9 + F_34 ( V_4 ) ) != V_72 )
V_4 = V_19 ;
F_1 ( V_2 , V_4 ) ;
F_20 ( 0 , V_2 -> V_9 + F_10 ( V_4 ) ) ;
F_20 ( V_59 , V_2 -> V_9 + F_34 ( V_4 ) ) ;
F_32 ( & V_2 -> V_69 ) ;
}
int F_36 ( struct V_1 * V_2 , enum V_3 V_4 )
{
int V_8 ;
V_8 = F_37 ( & V_2 -> V_22 , F_38 ( 500 ) ) ;
if ( ! V_8 ) {
F_12 ( V_2 -> V_6 , L_7 ,
( V_4 == V_12 ) ? L_2 : L_3 ) ;
return - V_73 ;
}
return 0 ;
}
int F_39 ( struct V_1 * V_2 , struct F_11 * V_26 ,
T_4 * V_74 , T_1 V_75 )
{
T_5 V_43 ;
T_1 V_37 ;
int V_8 ;
V_43 = F_40 ( V_2 -> V_6 , V_74 , V_75 , V_76 ) ;
V_8 = F_41 ( V_2 -> V_6 , V_43 ) ;
if ( V_8 ) {
F_12 ( V_2 -> V_6 , L_8 ) ;
return - V_36 ;
}
V_26 -> V_4 = V_12 ;
V_26 -> V_43 = V_43 ;
V_8 = F_30 ( V_2 , V_26 ) ;
if ( V_8 ) {
F_42 ( V_2 -> V_6 , V_43 , V_75 , V_76 ) ;
return V_8 ;
}
V_8 = F_36 ( V_2 , V_12 ) ;
if ( V_8 )
goto V_77;
F_1 ( V_2 , V_12 ) ;
V_37 = ( V_26 -> V_35 * V_45 + 7 ) >> 3 ;
F_43 ( V_2 -> V_78 ,
V_2 -> V_9 + V_2 -> V_32 -> V_79 ,
F_44 ( V_37 , 4 ) ) ;
memcpy ( V_74 + V_75 , V_2 -> V_78 , V_37 ) ;
V_77:
F_42 ( V_2 -> V_6 , V_43 , V_75 , V_76 ) ;
F_35 ( V_2 ) ;
return V_8 ;
}
void F_45 ( struct V_1 * V_2 , T_1 * V_80 )
{
const T_4 * V_34 = V_2 -> V_32 -> V_34 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_32 -> V_33 ; V_31 ++ ) {
if ( * V_80 <= V_34 [ V_31 ] ) {
if ( ! V_31 )
* V_80 = V_34 [ V_31 ] ;
else if ( * V_80 != V_34 [ V_31 ] )
* V_80 = V_34 [ V_31 - 1 ] ;
return;
}
}
* V_80 = V_34 [ V_2 -> V_32 -> V_33 - 1 ] ;
}
static int F_46 ( struct V_64 * V_65 )
{
struct V_5 * V_6 = & V_65 -> V_6 ;
struct V_1 * V_2 ;
struct V_81 * V_82 ;
const struct V_83 * V_84 = NULL ;
T_1 V_85 ;
int V_13 , V_8 ;
V_2 = F_47 ( V_6 , sizeof( * V_2 ) , V_86 ) ;
if ( ! V_2 )
return - V_87 ;
V_84 = F_48 ( V_88 , & V_65 -> V_6 ) ;
if ( ! V_84 )
return - V_89 ;
V_2 -> V_32 = V_84 -> V_74 ;
V_85 = V_2 -> V_32 -> V_33 - 1 ;
V_85 = V_2 -> V_32 -> V_34 [ V_85 ] ;
V_85 = ( V_85 * V_45 + 7 ) >> 3 ;
V_85 = F_44 ( V_85 , 4 ) ;
V_2 -> V_78 = F_47 ( V_6 , V_85 , V_86 ) ;
if ( ! V_2 -> V_78 )
return - V_87 ;
V_82 = F_49 ( V_65 , V_90 , 0 ) ;
V_2 -> V_9 = F_50 ( V_6 , V_82 ) ;
if ( F_51 ( V_2 -> V_9 ) ) {
F_12 ( V_6 , L_9 , F_52 ( V_2 -> V_9 ) ) ;
return F_52 ( V_2 -> V_9 ) ;
}
V_2 -> V_58 = F_53 ( V_6 , NULL ) ;
if ( F_51 ( V_2 -> V_58 ) ) {
F_12 ( V_6 , L_10 , F_52 ( V_2 -> V_58 ) ) ;
return F_52 ( V_2 -> V_58 ) ;
}
V_13 = F_54 ( V_65 , 0 ) ;
if ( V_13 < 0 ) {
F_12 ( V_6 , L_11 , V_13 ) ;
return V_13 ;
}
V_8 = F_55 ( V_6 , F_56 ( 32 ) ) ;
if ( V_8 ) {
F_12 ( V_6 , L_12 ) ;
return V_8 ;
}
V_8 = F_57 ( V_6 , V_13 , F_5 , 0x0 , L_13 , V_2 ) ;
if ( V_8 ) {
F_12 ( V_6 , L_14 ) ;
return - V_36 ;
}
V_2 -> V_6 = V_6 ;
F_58 ( & V_2 -> V_69 ) ;
F_59 ( V_65 , V_2 ) ;
F_60 ( V_6 , L_15 ) ;
return 0 ;
}
static int F_61 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_62 ( V_6 ) ;
F_17 ( V_2 -> V_58 ) ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_62 ( V_6 ) ;
int V_8 ;
V_8 = F_26 ( V_2 -> V_58 ) ;
if ( V_8 ) {
F_12 ( V_6 , L_16 ) ;
return V_8 ;
}
return 0 ;
}
