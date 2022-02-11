static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 & V_5 ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 & V_6 ;
}
static int F_3 ( void * V_7 , unsigned int V_8 ,
void * V_9 , T_1 V_10 )
{
struct V_1 * V_2 = V_7 ;
char * V_11 = V_9 ;
int V_12 = 0 ;
if ( F_4 ( V_8 >= V_2 -> V_13 ) )
return 0 ;
if ( ( V_8 + V_10 ) > V_2 -> V_13 )
V_10 = V_2 -> V_13 - V_8 ;
if ( F_4 ( ! V_10 ) )
return V_10 ;
F_5 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_3 -> V_15 )
V_2 -> V_3 -> V_15 ( V_2 ) ;
while ( V_10 ) {
struct V_16 V_17 ;
struct V_18 V_19 [ 2 ] = { { 0 } } ;
T_2 V_20 = V_21 << V_2 -> V_22 ;
T_1 V_23 = V_10 ;
int V_24 ;
if ( V_2 -> V_22 == 7 ) {
V_20 |= V_8 & 0x7f ;
V_24 = 10 ;
if ( F_1 ( V_2 ) )
V_23 = 1 ;
} else {
V_20 |= ( V_8 >> 1 ) & 0x3f ;
V_24 = 9 ;
if ( F_1 ( V_2 ) )
V_23 = 2 ;
}
F_6 ( & V_2 -> V_25 -> V_26 , L_1 ,
V_20 , V_2 -> V_25 -> V_27 ) ;
F_7 ( & V_17 ) ;
V_19 [ 0 ] . V_28 = ( char * ) & V_20 ;
V_19 [ 0 ] . V_29 = 2 ;
V_19 [ 0 ] . V_30 = V_24 ;
F_8 ( & V_19 [ 0 ] , & V_17 ) ;
V_19 [ 1 ] . V_31 = V_11 ;
V_19 [ 1 ] . V_29 = V_10 ;
V_19 [ 1 ] . V_30 = 8 ;
F_8 ( & V_19 [ 1 ] , & V_17 ) ;
V_12 = F_9 ( V_2 -> V_25 , & V_17 ) ;
F_10 ( 250 ) ;
if ( V_12 ) {
F_11 ( & V_2 -> V_25 -> V_26 , L_2 ,
V_23 , ( int ) V_8 , V_12 ) ;
break;
}
V_11 += V_23 ;
V_8 += V_23 ;
V_10 -= V_23 ;
}
if ( V_2 -> V_3 -> V_32 )
V_2 -> V_3 -> V_32 ( V_2 ) ;
F_12 ( & V_2 -> V_14 ) ;
return V_12 ;
}
static int F_13 ( struct V_1 * V_2 , int V_33 )
{
struct V_16 V_17 ;
struct V_18 V_19 ;
int V_24 , V_34 ;
T_2 V_20 ;
V_20 = V_35 << V_2 -> V_22 ;
if ( V_2 -> V_22 == 7 ) {
V_20 |= ( V_33 ? V_36 : V_37 ) << 1 ;
V_24 = 10 ;
} else {
V_20 |= ( V_33 ? V_36 : V_37 ) ;
V_24 = 9 ;
}
if ( F_2 ( V_2 ) ) {
V_20 <<= 2 ;
V_24 += 2 ;
}
F_6 ( & V_2 -> V_25 -> V_26 , L_3 ,
V_33 ? L_4 : L_5 , V_20 , V_24 ) ;
F_7 ( & V_17 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_28 = & V_20 ;
V_19 . V_29 = 2 ;
V_19 . V_30 = V_24 ;
F_8 ( & V_19 , & V_17 ) ;
F_5 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_3 -> V_15 )
V_2 -> V_3 -> V_15 ( V_2 ) ;
V_34 = F_9 ( V_2 -> V_25 , & V_17 ) ;
F_10 ( 250 ) ;
if ( V_34 )
F_11 ( & V_2 -> V_25 -> V_26 , L_6 ,
V_33 ? L_4 : L_7 , V_34 ) ;
if ( V_2 -> V_3 -> V_32 )
V_2 -> V_3 -> V_32 ( V_2 ) ;
F_12 ( & V_2 -> V_14 ) ;
return V_34 ;
}
static T_3
F_14 ( struct V_1 * V_2 ,
const char * V_11 , unsigned V_8 )
{
struct V_16 V_17 ;
struct V_18 V_19 [ 2 ] ;
int V_24 , V_38 , V_34 ;
T_2 V_20 ;
V_20 = V_39 << V_2 -> V_22 ;
if ( V_2 -> V_22 == 7 ) {
V_20 |= V_8 & 0x7f ;
V_24 = 10 ;
V_38 = 1 ;
} else {
V_20 |= ( V_8 >> 1 ) & 0x3f ;
V_24 = 9 ;
V_38 = 2 ;
}
F_6 ( & V_2 -> V_25 -> V_26 , L_8 , V_20 ) ;
F_7 ( & V_17 ) ;
memset ( V_19 , 0 , sizeof( V_19 ) ) ;
V_19 [ 0 ] . V_28 = ( char * ) & V_20 ;
V_19 [ 0 ] . V_29 = 2 ;
V_19 [ 0 ] . V_30 = V_24 ;
F_8 ( & V_19 [ 0 ] , & V_17 ) ;
V_19 [ 1 ] . V_28 = V_11 ;
V_19 [ 1 ] . V_29 = V_38 ;
V_19 [ 1 ] . V_30 = 8 ;
F_8 ( & V_19 [ 1 ] , & V_17 ) ;
V_34 = F_9 ( V_2 -> V_25 , & V_17 ) ;
F_15 ( 6 ) ;
return V_34 ;
}
static int F_16 ( void * V_7 , unsigned int V_8 ,
void * V_9 , T_1 V_10 )
{
struct V_1 * V_2 = V_7 ;
char * V_11 = V_9 ;
int V_40 , V_34 , V_41 = 1 ;
if ( F_4 ( V_8 >= V_2 -> V_13 ) )
return - V_42 ;
if ( ( V_8 + V_10 ) > V_2 -> V_13 )
V_10 = V_2 -> V_13 - V_8 ;
if ( F_4 ( ! V_10 ) )
return V_10 ;
if ( V_2 -> V_22 == 6 ) {
V_41 = 2 ;
V_10 &= ~ 1 ;
}
V_34 = F_13 ( V_2 , 1 ) ;
if ( V_34 )
return V_34 ;
F_5 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_3 -> V_15 )
V_2 -> V_3 -> V_15 ( V_2 ) ;
for ( V_40 = 0 ; V_40 < V_10 ; V_40 += V_41 ) {
V_34 = F_14 ( V_2 , & V_11 [ V_40 ] , V_8 + V_40 ) ;
if ( V_34 ) {
F_11 ( & V_2 -> V_25 -> V_26 , L_9 ,
( int ) V_8 + V_40 , V_34 ) ;
break;
}
}
if ( V_2 -> V_3 -> V_32 )
V_2 -> V_3 -> V_32 ( V_2 ) ;
F_12 ( & V_2 -> V_14 ) ;
F_13 ( V_2 , 0 ) ;
return V_34 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_3 ;
struct V_16 V_17 ;
struct V_18 V_19 ;
int V_24 , V_34 ;
T_2 V_20 ;
V_20 = V_35 << V_2 -> V_22 ;
if ( V_2 -> V_22 == 7 ) {
V_20 |= V_45 << 1 ;
V_24 = 10 ;
} else {
V_20 |= V_45 ;
V_24 = 9 ;
}
if ( F_2 ( V_2 ) ) {
V_20 <<= 2 ;
V_24 += 2 ;
}
F_6 ( & V_2 -> V_25 -> V_26 , L_10 , V_20 , V_24 ) ;
F_7 ( & V_17 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_28 = & V_20 ;
V_19 . V_29 = 2 ;
V_19 . V_30 = V_24 ;
F_8 ( & V_19 , & V_17 ) ;
F_5 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_3 -> V_15 )
V_2 -> V_3 -> V_15 ( V_2 ) ;
V_34 = F_9 ( V_2 -> V_25 , & V_17 ) ;
if ( V_34 )
F_11 ( & V_2 -> V_25 -> V_26 , L_11 , V_34 ) ;
F_15 ( 6 ) ;
if ( V_44 -> V_32 )
V_44 -> V_32 ( V_2 ) ;
F_12 ( & V_2 -> V_14 ) ;
return V_34 ;
}
static T_3 F_18 ( struct V_46 * V_26 ,
struct V_47 * V_48 ,
const char * V_11 , T_1 V_10 )
{
struct V_1 * V_2 = F_19 ( V_26 ) ;
int V_49 = 0 , V_34 ;
sscanf ( V_11 , L_12 , & V_49 ) ;
if ( V_49 ) {
V_34 = F_13 ( V_2 , 1 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_17 ( V_2 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_13 ( V_2 , 0 ) ;
if ( V_34 )
return V_34 ;
}
return V_10 ;
}
static void F_20 ( void * V_50 )
{
struct V_1 * V_2 = V_50 ;
F_21 ( V_2 -> V_3 -> V_51 , 1 ) ;
}
static void F_22 ( void * V_50 )
{
struct V_1 * V_2 = V_50 ;
F_21 ( V_2 -> V_3 -> V_51 , 0 ) ;
}
static int F_23 ( struct V_52 * V_25 )
{
const struct V_53 * V_54 =
F_24 ( V_55 , & V_25 -> V_26 ) ;
struct V_56 * V_57 = V_25 -> V_26 . V_58 ;
struct V_43 * V_44 ;
T_4 V_59 ;
int V_60 ;
enum V_61 V_62 ;
int V_34 ;
V_44 = F_25 ( & V_25 -> V_26 , sizeof( * V_44 ) , V_63 ) ;
if ( ! V_44 )
return - V_64 ;
V_34 = F_26 ( V_57 , L_13 , & V_59 ) ;
if ( V_34 < 0 ) {
F_11 ( & V_25 -> V_26 , L_14 ) ;
return V_34 ;
}
if ( V_59 == 8 ) {
V_44 -> V_65 |= V_66 ;
} else if ( V_59 == 16 ) {
V_44 -> V_65 |= V_67 ;
} else {
F_11 ( & V_25 -> V_26 , L_15 , V_59 ) ;
return - V_68 ;
}
if ( F_27 ( V_57 , L_16 ) )
V_44 -> V_65 |= V_69 ;
V_60 = F_28 ( V_57 , L_17 , 0 , & V_62 ) ;
if ( F_29 ( V_60 ) ) {
unsigned long V_65 =
V_62 == V_70 ? V_71 : 0 ;
V_34 = F_30 ( & V_25 -> V_26 , V_60 , V_65 ,
L_18 ) ;
if ( V_34 )
return V_34 ;
V_44 -> V_51 = F_31 ( V_60 ) ;
V_44 -> V_15 = F_20 ;
V_44 -> V_32 = F_22 ;
F_32 ( V_44 -> V_51 , 0 ) ;
}
if ( V_54 -> V_72 ) {
const struct V_73 * V_72 = V_54 -> V_72 ;
V_44 -> V_4 = V_72 -> V_4 ;
}
V_25 -> V_26 . V_74 = V_44 ;
return 0 ;
}
static int F_33 ( struct V_52 * V_25 )
{
struct V_43 * V_44 ;
struct V_1 * V_2 ;
int V_12 ;
if ( V_25 -> V_26 . V_58 ) {
V_12 = F_23 ( V_25 ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_44 = V_25 -> V_26 . V_74 ;
if ( ! V_44 ) {
F_11 ( & V_25 -> V_26 , L_19 ) ;
return - V_75 ;
}
V_2 = F_34 ( sizeof( * V_2 ) , V_63 ) ;
if ( ! V_2 )
return - V_64 ;
if ( V_44 -> V_65 & V_66 )
V_2 -> V_22 = 7 ;
else if ( V_44 -> V_65 & V_67 )
V_2 -> V_22 = 6 ;
else {
F_11 ( & V_25 -> V_26 , L_20 ) ;
V_12 = - V_68 ;
goto V_76;
}
F_35 ( & V_2 -> V_14 ) ;
V_2 -> V_25 = V_25 ;
V_2 -> V_3 = V_44 ;
V_2 -> V_13 = 128 ;
V_2 -> V_77 . V_78 = F_36 ( & V_25 -> V_26 ) ;
V_2 -> V_77 . V_26 = & V_25 -> V_26 ;
V_2 -> V_77 . V_79 = V_44 -> V_65 & V_69 ;
V_2 -> V_77 . V_80 = true ;
V_2 -> V_77 . V_81 = V_82 ;
V_2 -> V_77 . V_83 = true ;
V_2 -> V_77 . V_84 = & V_25 -> V_26 ;
V_2 -> V_77 . V_85 = F_3 ;
V_2 -> V_77 . V_86 = F_16 ;
V_2 -> V_77 . V_7 = V_2 ;
V_2 -> V_77 . V_87 = 4 ;
V_2 -> V_77 . V_88 = 1 ;
V_2 -> V_77 . V_13 = V_2 -> V_13 ;
V_2 -> V_89 = F_37 ( & V_2 -> V_77 ) ;
if ( F_38 ( V_2 -> V_89 ) ) {
V_12 = F_39 ( V_2 -> V_89 ) ;
goto V_76;
}
F_40 ( & V_25 -> V_26 , L_21 ,
( V_44 -> V_65 & V_66 ) ? 8 : 16 ,
( V_44 -> V_65 & V_69 ) ? L_22 : L_23 ) ;
if ( ! ( V_44 -> V_65 & V_69 ) ) {
if ( F_41 ( & V_25 -> V_26 , & V_90 ) )
F_11 ( & V_25 -> V_26 , L_24 ) ;
}
F_42 ( V_25 , V_2 ) ;
return 0 ;
V_76:
F_43 ( V_2 ) ;
return V_12 ;
}
static int F_44 ( struct V_52 * V_25 )
{
struct V_1 * V_2 = F_45 ( V_25 ) ;
F_46 ( V_2 -> V_89 ) ;
if ( ! ( V_2 -> V_3 -> V_65 & V_69 ) )
F_47 ( & V_25 -> V_26 , & V_90 ) ;
F_43 ( V_2 ) ;
return 0 ;
}
