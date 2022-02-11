static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 & V_5 ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 & V_6 ;
}
static T_1
F_3 ( struct V_1 * V_2 , char * V_7 ,
unsigned V_8 , T_2 V_9 )
{
T_1 V_10 = 0 ;
if ( F_4 ( V_8 >= V_2 -> V_11 ) )
return 0 ;
if ( ( V_8 + V_9 ) > V_2 -> V_11 )
V_9 = V_2 -> V_11 - V_8 ;
if ( F_4 ( ! V_9 ) )
return V_9 ;
F_5 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_3 -> V_13 )
V_2 -> V_3 -> V_13 ( V_2 ) ;
while ( V_9 ) {
struct V_14 V_15 ;
struct V_16 V_17 [ 2 ] = { { 0 } } ;
T_3 V_18 = V_19 << V_2 -> V_20 ;
T_2 V_21 = V_9 ;
int V_22 ;
int V_23 ;
if ( V_2 -> V_20 == 7 ) {
V_18 |= V_8 & 0x7f ;
V_22 = 10 ;
if ( F_1 ( V_2 ) )
V_21 = 1 ;
} else {
V_18 |= ( V_8 >> 1 ) & 0x3f ;
V_22 = 9 ;
if ( F_1 ( V_2 ) )
V_21 = 2 ;
}
F_6 ( & V_2 -> V_24 -> V_25 , L_1 ,
V_18 , V_2 -> V_24 -> V_26 ) ;
F_7 ( & V_15 ) ;
V_17 [ 0 ] . V_27 = ( char * ) & V_18 ;
V_17 [ 0 ] . V_28 = 2 ;
V_17 [ 0 ] . V_29 = V_22 ;
F_8 ( & V_17 [ 0 ] , & V_15 ) ;
V_17 [ 1 ] . V_30 = V_7 ;
V_17 [ 1 ] . V_28 = V_9 ;
V_17 [ 1 ] . V_29 = 8 ;
F_8 ( & V_17 [ 1 ] , & V_15 ) ;
V_23 = F_9 ( V_2 -> V_24 , & V_15 ) ;
F_10 ( 250 ) ;
if ( V_23 ) {
F_11 ( & V_2 -> V_24 -> V_25 , L_2 ,
V_21 , ( int ) V_8 , V_23 ) ;
V_10 = V_23 ;
break;
}
V_7 += V_21 ;
V_8 += V_21 ;
V_9 -= V_21 ;
V_10 += V_21 ;
}
if ( V_2 -> V_3 -> V_31 )
V_2 -> V_3 -> V_31 ( V_2 ) ;
F_12 ( & V_2 -> V_12 ) ;
return V_10 ;
}
static int F_13 ( struct V_1 * V_2 , int V_32 )
{
struct V_14 V_15 ;
struct V_16 V_17 ;
int V_22 , V_10 ;
T_3 V_18 ;
V_18 = V_33 << V_2 -> V_20 ;
if ( V_2 -> V_20 == 7 ) {
V_18 |= ( V_32 ? V_34 : V_35 ) << 1 ;
V_22 = 10 ;
} else {
V_18 |= ( V_32 ? V_34 : V_35 ) ;
V_22 = 9 ;
}
if ( F_2 ( V_2 ) ) {
V_18 <<= 2 ;
V_22 += 2 ;
}
F_6 ( & V_2 -> V_24 -> V_25 , L_3 ,
V_32 ? L_4 : L_5 , V_18 , V_22 ) ;
F_7 ( & V_15 ) ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_27 = & V_18 ;
V_17 . V_28 = 2 ;
V_17 . V_29 = V_22 ;
F_8 ( & V_17 , & V_15 ) ;
F_5 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_3 -> V_13 )
V_2 -> V_3 -> V_13 ( V_2 ) ;
V_10 = F_9 ( V_2 -> V_24 , & V_15 ) ;
F_10 ( 250 ) ;
if ( V_10 )
F_11 ( & V_2 -> V_24 -> V_25 , L_6 ,
V_32 ? L_4 : L_7 , V_10 ) ;
if ( V_2 -> V_3 -> V_31 )
V_2 -> V_3 -> V_31 ( V_2 ) ;
F_12 ( & V_2 -> V_12 ) ;
return V_10 ;
}
static T_1
F_14 ( struct V_1 * V_2 ,
const char * V_7 , unsigned V_8 )
{
struct V_14 V_15 ;
struct V_16 V_17 [ 2 ] ;
int V_22 , V_36 , V_10 ;
T_3 V_18 ;
V_18 = V_37 << V_2 -> V_20 ;
if ( V_2 -> V_20 == 7 ) {
V_18 |= V_8 & 0x7f ;
V_22 = 10 ;
V_36 = 1 ;
} else {
V_18 |= ( V_8 >> 1 ) & 0x3f ;
V_22 = 9 ;
V_36 = 2 ;
}
F_6 ( & V_2 -> V_24 -> V_25 , L_8 , V_18 ) ;
F_7 ( & V_15 ) ;
memset ( V_17 , 0 , sizeof( V_17 ) ) ;
V_17 [ 0 ] . V_27 = ( char * ) & V_18 ;
V_17 [ 0 ] . V_28 = 2 ;
V_17 [ 0 ] . V_29 = V_22 ;
F_8 ( & V_17 [ 0 ] , & V_15 ) ;
V_17 [ 1 ] . V_27 = V_7 ;
V_17 [ 1 ] . V_28 = V_36 ;
V_17 [ 1 ] . V_29 = 8 ;
F_8 ( & V_17 [ 1 ] , & V_15 ) ;
V_10 = F_9 ( V_2 -> V_24 , & V_15 ) ;
F_15 ( 6 ) ;
return V_10 ;
}
static T_1
F_16 ( struct V_1 * V_2 , const char * V_7 ,
T_4 V_8 , T_2 V_9 )
{
int V_38 , V_10 , V_39 = 1 ;
if ( F_4 ( V_8 >= V_2 -> V_11 ) )
return - V_40 ;
if ( ( V_8 + V_9 ) > V_2 -> V_11 )
V_9 = V_2 -> V_11 - V_8 ;
if ( F_4 ( ! V_9 ) )
return V_9 ;
if ( V_2 -> V_20 == 6 ) {
V_39 = 2 ;
V_9 &= ~ 1 ;
}
V_10 = F_13 ( V_2 , 1 ) ;
if ( V_10 )
return V_10 ;
F_5 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_3 -> V_13 )
V_2 -> V_3 -> V_13 ( V_2 ) ;
for ( V_38 = 0 ; V_38 < V_9 ; V_38 += V_39 ) {
V_10 = F_14 ( V_2 , & V_7 [ V_38 ] , V_8 + V_38 ) ;
if ( V_10 ) {
F_11 ( & V_2 -> V_24 -> V_25 , L_9 ,
( int ) V_8 + V_38 , V_10 ) ;
break;
}
}
if ( V_2 -> V_3 -> V_31 )
V_2 -> V_3 -> V_31 ( V_2 ) ;
F_12 ( & V_2 -> V_12 ) ;
F_13 ( V_2 , 0 ) ;
return V_10 ? : V_9 ;
}
static int F_17 ( void * V_41 , const void * V_42 ,
T_2 V_43 , void * V_44 ,
T_2 V_45 )
{
struct V_1 * V_46 = V_41 ;
T_5 V_47 = * ( V_48 * ) V_42 ;
int V_23 ;
V_23 = F_3 ( V_46 , V_44 , V_47 , V_45 ) ;
if ( V_23 )
return V_23 ;
return 0 ;
}
static int F_18 ( void * V_41 , const void * V_49 ,
T_2 V_9 )
{
struct V_1 * V_46 = V_41 ;
const char * V_7 ;
V_48 V_47 ;
T_2 V_28 ;
int V_23 ;
memcpy ( & V_47 , V_49 , sizeof( V_47 ) ) ;
V_7 = ( const char * ) V_49 + sizeof( V_47 ) ;
V_28 = V_9 - sizeof( V_47 ) ;
V_23 = F_16 ( V_46 , V_7 , V_47 , V_28 ) ;
if ( V_23 )
return V_23 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = V_2 -> V_3 ;
struct V_14 V_15 ;
struct V_16 V_17 ;
int V_22 , V_10 ;
T_3 V_18 ;
V_18 = V_33 << V_2 -> V_20 ;
if ( V_2 -> V_20 == 7 ) {
V_18 |= V_52 << 1 ;
V_22 = 10 ;
} else {
V_18 |= V_52 ;
V_22 = 9 ;
}
if ( F_2 ( V_2 ) ) {
V_18 <<= 2 ;
V_22 += 2 ;
}
F_6 ( & V_2 -> V_24 -> V_25 , L_10 , V_18 , V_22 ) ;
F_7 ( & V_15 ) ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_17 . V_27 = & V_18 ;
V_17 . V_28 = 2 ;
V_17 . V_29 = V_22 ;
F_8 ( & V_17 , & V_15 ) ;
F_5 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_3 -> V_13 )
V_2 -> V_3 -> V_13 ( V_2 ) ;
V_10 = F_9 ( V_2 -> V_24 , & V_15 ) ;
if ( V_10 )
F_11 ( & V_2 -> V_24 -> V_25 , L_11 , V_10 ) ;
F_15 ( 6 ) ;
if ( V_51 -> V_31 )
V_51 -> V_31 ( V_2 ) ;
F_12 ( & V_2 -> V_12 ) ;
return V_10 ;
}
static T_1 F_20 ( struct V_53 * V_25 ,
struct V_54 * V_55 ,
const char * V_7 , T_2 V_9 )
{
struct V_1 * V_2 = F_21 ( V_25 ) ;
int V_56 = 0 , V_10 ;
sscanf ( V_7 , L_12 , & V_56 ) ;
if ( V_56 ) {
V_10 = F_13 ( V_2 , 1 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_19 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_13 ( V_2 , 0 ) ;
if ( V_10 )
return V_10 ;
}
return V_9 ;
}
static void F_22 ( void * V_41 )
{
struct V_1 * V_2 = V_41 ;
F_23 ( V_2 -> V_3 -> V_57 , 1 ) ;
}
static void F_24 ( void * V_41 )
{
struct V_1 * V_2 = V_41 ;
F_23 ( V_2 -> V_3 -> V_57 , 0 ) ;
}
static int F_25 ( struct V_58 * V_24 )
{
const struct V_59 * V_60 =
F_26 ( V_61 , & V_24 -> V_25 ) ;
struct V_62 * V_63 = V_24 -> V_25 . V_64 ;
struct V_50 * V_51 ;
V_48 V_65 ;
int V_66 ;
enum V_67 V_68 ;
int V_10 ;
V_51 = F_27 ( & V_24 -> V_25 , sizeof( * V_51 ) , V_69 ) ;
if ( ! V_51 )
return - V_70 ;
V_10 = F_28 ( V_63 , L_13 , & V_65 ) ;
if ( V_10 < 0 ) {
F_11 ( & V_24 -> V_25 , L_14 ) ;
return V_10 ;
}
if ( V_65 == 8 ) {
V_51 -> V_71 |= V_72 ;
} else if ( V_65 == 16 ) {
V_51 -> V_71 |= V_73 ;
} else {
F_11 ( & V_24 -> V_25 , L_15 , V_65 ) ;
return - V_74 ;
}
if ( F_29 ( V_63 , L_16 ) )
V_51 -> V_71 |= V_75 ;
V_66 = F_30 ( V_63 , L_17 , 0 , & V_68 ) ;
if ( F_31 ( V_66 ) ) {
unsigned long V_71 =
V_68 == V_76 ? V_77 : 0 ;
V_10 = F_32 ( & V_24 -> V_25 , V_66 , V_71 ,
L_18 ) ;
if ( V_10 )
return V_10 ;
V_51 -> V_57 = F_33 ( V_66 ) ;
V_51 -> V_13 = F_22 ;
V_51 -> V_31 = F_24 ;
F_34 ( V_51 -> V_57 , 0 ) ;
}
if ( V_60 -> V_49 ) {
const struct V_78 * V_49 = V_60 -> V_49 ;
V_51 -> V_4 = V_49 -> V_4 ;
}
V_24 -> V_25 . V_79 = V_51 ;
return 0 ;
}
static int F_35 ( struct V_58 * V_24 )
{
struct V_50 * V_51 ;
struct V_1 * V_2 ;
struct V_80 * V_80 ;
int V_23 ;
if ( V_24 -> V_25 . V_64 ) {
V_23 = F_25 ( V_24 ) ;
if ( V_23 < 0 )
return V_23 ;
}
V_51 = V_24 -> V_25 . V_79 ;
if ( ! V_51 ) {
F_11 ( & V_24 -> V_25 , L_19 ) ;
return - V_81 ;
}
V_2 = F_36 ( sizeof( * V_2 ) , V_69 ) ;
if ( ! V_2 )
return - V_70 ;
if ( V_51 -> V_71 & V_72 )
V_2 -> V_20 = 7 ;
else if ( V_51 -> V_71 & V_73 )
V_2 -> V_20 = 6 ;
else {
F_11 ( & V_24 -> V_25 , L_20 ) ;
V_23 = - V_74 ;
goto V_82;
}
F_37 ( & V_2 -> V_12 ) ;
V_2 -> V_24 = F_38 ( V_24 ) ;
V_2 -> V_3 = V_51 ;
V_2 -> V_11 = 128 ;
V_2 -> V_83 . V_84 = 32 ;
V_2 -> V_83 . V_85 = 8 ;
V_2 -> V_83 . V_86 = 1 ;
V_2 -> V_83 . V_87 = V_2 -> V_11 - 1 ;
V_80 = F_39 ( & V_24 -> V_25 , & V_88 , V_2 ,
& V_2 -> V_83 ) ;
if ( F_40 ( V_80 ) ) {
F_11 ( & V_24 -> V_25 , L_21 ) ;
V_23 = F_41 ( V_80 ) ;
goto V_82;
}
V_2 -> V_89 . V_90 = F_42 ( & V_24 -> V_25 ) ;
V_2 -> V_89 . V_25 = & V_24 -> V_25 ;
V_2 -> V_89 . V_91 = V_51 -> V_71 & V_75 ;
V_2 -> V_89 . V_92 = true ;
V_2 -> V_89 . V_93 = V_94 ;
V_2 -> V_89 . V_95 = true ;
V_2 -> V_89 . V_96 = & V_24 -> V_25 ;
V_2 -> V_97 = F_43 ( & V_2 -> V_89 ) ;
if ( F_40 ( V_2 -> V_97 ) ) {
V_23 = F_41 ( V_2 -> V_97 ) ;
goto V_82;
}
F_44 ( & V_24 -> V_25 , L_22 ,
( V_51 -> V_71 & V_72 ) ? 8 : 16 ,
( V_51 -> V_71 & V_75 ) ? L_23 : L_24 ) ;
if ( ! ( V_51 -> V_71 & V_75 ) ) {
if ( F_45 ( & V_24 -> V_25 , & V_98 ) )
F_11 ( & V_24 -> V_25 , L_25 ) ;
}
F_46 ( V_24 , V_2 ) ;
return 0 ;
V_82:
F_47 ( V_2 ) ;
return V_23 ;
}
static int F_48 ( struct V_58 * V_24 )
{
struct V_1 * V_2 = F_49 ( V_24 ) ;
F_50 ( V_2 -> V_97 ) ;
if ( ! ( V_2 -> V_3 -> V_71 & V_75 ) )
F_51 ( & V_24 -> V_25 , & V_98 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
