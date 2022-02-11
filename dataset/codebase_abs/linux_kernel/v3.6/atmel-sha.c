static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_6 , V_7 ) ;
if ( F_1 ( V_2 , V_6 ) & V_7 )
V_2 -> V_8 |= V_9 ;
}
static T_2 F_6 ( struct V_10 * V_11 )
{
T_2 V_12 ;
while ( ( V_11 -> V_13 < V_11 -> V_14 ) && V_11 -> V_15 ) {
V_12 = F_7 ( V_11 -> V_16 -> V_17 - V_11 -> V_3 , V_11 -> V_15 ) ;
V_12 = F_7 ( V_12 , V_11 -> V_14 - V_11 -> V_13 ) ;
if ( V_12 <= 0 )
break;
F_8 ( V_11 -> V_18 + V_11 -> V_13 , V_11 -> V_16 ,
V_11 -> V_3 , V_12 , 0 ) ;
V_11 -> V_13 += V_12 ;
V_11 -> V_3 += V_12 ;
V_11 -> V_15 -= V_12 ;
if ( V_11 -> V_3 == V_11 -> V_16 -> V_17 ) {
V_11 -> V_16 = F_9 ( V_11 -> V_16 ) ;
if ( V_11 -> V_16 )
V_11 -> V_3 = 0 ;
else
V_11 -> V_15 = 0 ;
}
}
return 0 ;
}
static void F_10 ( struct V_10 * V_11 , int V_17 )
{
unsigned int V_19 , V_20 ;
T_3 V_21 ;
T_3 V_22 ;
V_21 = ( V_11 -> V_13 + V_11 -> V_23 + V_17 ) << 3 ;
V_22 = F_11 ( V_21 ) ;
V_19 = V_11 -> V_13 & 0x3f ;
V_20 = ( V_19 < 56 ) ? ( 56 - V_19 ) : ( ( 64 + 56 ) - V_19 ) ;
* ( V_11 -> V_18 + V_11 -> V_13 ) = 0x80 ;
memset ( V_11 -> V_18 + V_11 -> V_13 + 1 , 0 , V_20 - 1 ) ;
memcpy ( V_11 -> V_18 + V_11 -> V_13 + V_20 , & V_22 , 8 ) ;
V_11 -> V_13 += V_20 + 8 ;
V_11 -> V_8 |= V_24 ;
}
static int F_12 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_13 ( V_26 ) ;
struct V_29 * V_30 = F_14 ( V_28 ) ;
struct V_10 * V_11 = F_15 ( V_26 ) ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_31 ;
F_16 ( & V_32 . V_33 ) ;
if ( ! V_30 -> V_2 ) {
F_17 (tmp, &atmel_sha.dev_list, list) {
V_2 = V_31 ;
break;
}
V_30 -> V_2 = V_2 ;
} else {
V_2 = V_30 -> V_2 ;
}
F_18 ( & V_32 . V_33 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_8 = 0 ;
F_19 ( V_2 -> V_34 , L_1 ,
F_20 ( V_28 ) ) ;
if ( F_20 ( V_28 ) == V_35 )
V_11 -> V_8 |= V_36 ;
else if ( F_20 ( V_28 ) == V_37 )
V_11 -> V_8 |= V_38 ;
V_11 -> V_13 = 0 ;
V_11 -> V_23 = 0 ;
V_11 -> V_14 = V_39 ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , int V_40 )
{
struct V_10 * V_11 = F_15 ( V_2 -> V_26 ) ;
T_1 V_41 = 0 , V_42 = V_43 ;
if ( F_22 ( V_40 ) ) {
F_3 ( V_2 , V_44 , V_45 ) ;
V_42 = V_46 ;
if ( V_2 -> V_8 & V_9 )
V_42 = V_7 ;
} else {
F_3 ( V_2 , V_44 , V_47 ) ;
}
if ( V_11 -> V_8 & V_38 )
V_42 |= V_48 ;
if ( ! V_11 -> V_23 )
V_41 = V_49 ;
F_3 ( V_2 , V_50 , V_41 ) ;
F_3 ( V_2 , V_6 , V_42 ) ;
}
static int F_23 ( struct V_1 * V_2 , const T_4 * V_51 ,
T_2 V_17 , int V_52 )
{
struct V_10 * V_11 = F_15 ( V_2 -> V_26 ) ;
int V_12 , V_53 ;
const T_1 * V_18 = ( const T_1 * ) V_51 ;
F_19 ( V_2 -> V_34 , L_2 ,
V_11 -> V_23 , V_17 , V_52 ) ;
F_21 ( V_2 , 0 ) ;
V_11 -> V_23 += V_17 ;
if ( V_52 )
V_2 -> V_8 |= V_54 ;
V_53 = F_24 ( V_17 , sizeof( T_1 ) ) ;
V_2 -> V_8 |= V_55 ;
for ( V_12 = 0 ; V_12 < V_53 ; V_12 ++ )
F_3 ( V_2 , F_25 ( V_12 ) , V_18 [ V_12 ] ) ;
return - V_56 ;
}
static int F_26 ( struct V_1 * V_2 , T_5 V_57 ,
T_2 V_58 , T_5 V_59 , T_2 V_60 , int V_52 )
{
struct V_10 * V_11 = F_15 ( V_2 -> V_26 ) ;
int V_53 ;
F_19 ( V_2 -> V_34 , L_3 ,
V_11 -> V_23 , V_58 , V_52 ) ;
V_53 = F_24 ( V_58 , sizeof( T_1 ) ) ;
F_3 ( V_2 , V_61 , V_62 ) ;
F_3 ( V_2 , V_63 , V_57 ) ;
F_3 ( V_2 , V_64 , V_53 ) ;
V_53 = F_24 ( V_60 , sizeof( T_1 ) ) ;
F_3 ( V_2 , V_65 , V_59 ) ;
F_3 ( V_2 , V_66 , V_53 ) ;
F_21 ( V_2 , 1 ) ;
V_11 -> V_23 += V_58 ;
if ( V_52 )
V_2 -> V_8 |= V_54 ;
V_2 -> V_8 |= V_67 ;
F_3 ( V_2 , V_61 , V_68 ) ;
return - V_56 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_15 ( V_2 -> V_26 ) ;
int V_13 ;
F_6 ( V_11 ) ;
F_10 ( V_11 , 0 ) ;
V_13 = V_11 -> V_13 ;
V_11 -> V_13 = 0 ;
return F_23 ( V_2 , V_11 -> V_18 , V_13 , 1 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
T_2 V_17 , int V_52 )
{
V_11 -> V_69 = F_29 ( V_2 -> V_34 , V_11 -> V_18 ,
V_11 -> V_14 + V_70 , V_71 ) ;
if ( F_30 ( V_2 -> V_34 , V_11 -> V_69 ) ) {
F_31 ( V_2 -> V_34 , L_4 , V_11 -> V_14 +
V_70 ) ;
return - V_72 ;
}
V_11 -> V_8 &= ~ V_73 ;
return F_26 ( V_2 , V_11 -> V_69 , V_17 , 0 , 0 , V_52 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_15 ( V_2 -> V_26 ) ;
unsigned int V_52 ;
T_2 V_12 ;
F_6 ( V_11 ) ;
V_52 = ( V_11 -> V_8 & V_74 ) && ! V_11 -> V_15 ;
F_19 ( V_2 -> V_34 , L_5 ,
V_11 -> V_13 , V_11 -> V_23 , V_52 ) ;
if ( V_52 )
F_10 ( V_11 , 0 ) ;
if ( V_52 || ( V_11 -> V_13 == V_11 -> V_14 && V_11 -> V_15 ) ) {
V_12 = V_11 -> V_13 ;
V_11 -> V_13 = 0 ;
return F_28 ( V_2 , V_11 , V_12 , V_52 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_15 ( V_2 -> V_26 ) ;
unsigned int V_17 , V_52 , V_75 ;
struct V_76 * V_16 ;
unsigned int V_12 ;
if ( ! V_11 -> V_15 )
return 0 ;
if ( V_11 -> V_13 || V_11 -> V_3 )
return F_32 ( V_2 ) ;
F_19 ( V_2 -> V_34 , L_6 ,
V_11 -> V_23 , V_11 -> V_13 , V_11 -> V_15 ) ;
V_16 = V_11 -> V_16 ;
if ( ! F_34 ( V_16 -> V_3 , sizeof( T_1 ) ) )
return F_32 ( V_2 ) ;
if ( ! F_35 ( V_16 ) && ! F_34 ( V_16 -> V_17 , V_70 ) )
return F_32 ( V_2 ) ;
V_17 = F_7 ( V_11 -> V_15 , V_16 -> V_17 ) ;
if ( F_35 ( V_16 ) ) {
if ( ! ( V_11 -> V_8 & V_74 ) ) {
V_75 = V_17 & ( V_70 - 1 ) ;
V_17 -= V_75 ;
if ( V_17 == 0 ) {
V_11 -> V_3 = V_17 ;
return F_32 ( V_2 ) ;
}
}
}
V_11 -> V_15 -= V_17 ;
V_11 -> V_3 = V_17 ;
V_52 = ( V_11 -> V_8 & V_74 ) && ! V_11 -> V_15 ;
if ( V_52 ) {
V_75 = V_17 & ( V_70 - 1 ) ;
V_17 -= V_75 ;
V_11 -> V_15 += V_75 ;
V_11 -> V_3 = V_17 ;
V_16 = V_11 -> V_16 ;
F_6 ( V_11 ) ;
F_10 ( V_11 , V_17 ) ;
V_11 -> V_69 = F_29 ( V_2 -> V_34 , V_11 -> V_18 ,
V_11 -> V_14 + V_70 , V_71 ) ;
if ( F_30 ( V_2 -> V_34 , V_11 -> V_69 ) ) {
F_31 ( V_2 -> V_34 , L_4 ,
V_11 -> V_14 + V_70 ) ;
return - V_72 ;
}
if ( V_17 == 0 ) {
V_11 -> V_8 &= ~ V_73 ;
V_12 = V_11 -> V_13 ;
V_11 -> V_13 = 0 ;
return F_26 ( V_2 , V_11 -> V_69 , V_12 , 0 ,
0 , V_52 ) ;
} else {
V_11 -> V_16 = V_16 ;
if ( ! F_36 ( V_2 -> V_34 , V_11 -> V_16 , 1 ,
V_71 ) ) {
F_31 ( V_2 -> V_34 , L_7 ) ;
return - V_72 ;
}
V_11 -> V_8 |= V_73 ;
V_12 = V_11 -> V_13 ;
V_11 -> V_13 = 0 ;
return F_26 ( V_2 , F_37 ( V_11 -> V_16 ) ,
V_17 , V_11 -> V_69 , V_12 , V_52 ) ;
}
}
if ( ! F_36 ( V_2 -> V_34 , V_11 -> V_16 , 1 , V_71 ) ) {
F_31 ( V_2 -> V_34 , L_7 ) ;
return - V_72 ;
}
V_11 -> V_8 |= V_73 ;
return F_26 ( V_2 , F_37 ( V_11 -> V_16 ) , V_17 , 0 ,
0 , V_52 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_15 ( V_2 -> V_26 ) ;
if ( V_11 -> V_8 & V_73 ) {
F_39 ( V_2 -> V_34 , V_11 -> V_16 , 1 , V_71 ) ;
if ( V_11 -> V_16 -> V_17 == V_11 -> V_3 ) {
V_11 -> V_16 = F_9 ( V_11 -> V_16 ) ;
if ( V_11 -> V_16 )
V_11 -> V_3 = 0 ;
}
if ( V_11 -> V_8 & V_24 )
F_40 ( V_2 -> V_34 , V_11 -> V_69 ,
V_11 -> V_14 + V_70 , V_71 ) ;
} else {
F_40 ( V_2 -> V_34 , V_11 -> V_69 , V_11 -> V_14 +
V_70 , V_71 ) ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_10 * V_11 = F_15 ( V_26 ) ;
int V_77 ;
F_19 ( V_2 -> V_34 , L_8 ,
V_11 -> V_15 , V_11 -> V_23 , ( V_11 -> V_8 & V_74 ) != 0 ) ;
if ( V_11 -> V_8 & V_55 )
V_77 = F_27 ( V_2 ) ;
else
V_77 = F_33 ( V_2 ) ;
F_19 ( V_2 -> V_34 , L_9 ,
V_77 , V_11 -> V_23 ) ;
return V_77 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_10 * V_11 = F_15 ( V_26 ) ;
int V_77 = 0 ;
int V_12 ;
if ( V_11 -> V_13 >= V_78 ) {
F_10 ( V_11 , 0 ) ;
V_12 = V_11 -> V_13 ;
V_11 -> V_13 = 0 ;
V_77 = F_28 ( V_2 , V_11 , V_12 , 1 ) ;
}
else {
F_10 ( V_11 , 0 ) ;
V_12 = V_11 -> V_13 ;
V_11 -> V_13 = 0 ;
V_77 = F_23 ( V_2 , V_11 -> V_18 , V_12 , 1 ) ;
}
F_19 ( V_2 -> V_34 , L_10 , V_77 ) ;
return V_77 ;
}
static void F_43 ( struct V_25 * V_26 )
{
struct V_10 * V_11 = F_15 ( V_26 ) ;
T_1 * V_79 = ( T_1 * ) V_11 -> V_80 ;
int V_81 ;
if ( F_22 ( V_11 -> V_8 & V_36 ) )
for ( V_81 = 0 ; V_81 < V_35 / sizeof( T_1 ) ; V_81 ++ )
V_79 [ V_81 ] = F_1 ( V_11 -> V_2 , F_44 ( V_81 ) ) ;
else
for ( V_81 = 0 ; V_81 < V_37 / sizeof( T_1 ) ; V_81 ++ )
V_79 [ V_81 ] = F_1 ( V_11 -> V_2 , F_44 ( V_81 ) ) ;
}
static void F_45 ( struct V_25 * V_26 )
{
struct V_10 * V_11 = F_15 ( V_26 ) ;
if ( ! V_26 -> V_82 )
return;
if ( F_22 ( V_11 -> V_8 & V_36 ) )
memcpy ( V_26 -> V_82 , V_11 -> V_80 , V_35 ) ;
else
memcpy ( V_26 -> V_82 , V_11 -> V_80 , V_37 ) ;
}
static int F_46 ( struct V_25 * V_26 )
{
struct V_10 * V_11 = F_15 ( V_26 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
int V_77 = 0 ;
if ( V_11 -> V_23 )
F_45 ( V_26 ) ;
F_19 ( V_2 -> V_34 , L_11 , V_11 -> V_23 ,
V_11 -> V_13 ) ;
return V_77 ;
}
static void F_47 ( struct V_25 * V_26 , int V_77 )
{
struct V_10 * V_11 = F_15 ( V_26 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
if ( ! V_77 ) {
F_43 ( V_26 ) ;
if ( V_54 & V_2 -> V_8 )
V_77 = F_46 ( V_26 ) ;
} else {
V_11 -> V_8 |= V_83 ;
}
V_2 -> V_8 &= ~ ( V_84 | V_54 | V_55 |
V_85 | V_86 ) ;
F_48 ( V_2 -> V_87 ) ;
if ( V_26 -> V_88 . V_89 )
V_26 -> V_88 . V_89 ( & V_26 -> V_88 , V_77 ) ;
F_49 ( & V_2 -> V_90 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
F_51 ( V_2 -> V_87 ) ;
if ( V_91 & V_2 -> V_8 ) {
F_3 ( V_2 , V_50 , V_92 ) ;
F_5 ( V_2 ) ;
V_2 -> V_8 |= V_91 ;
V_2 -> V_77 = 0 ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_93 * V_94 , * V_95 ;
struct V_10 * V_11 ;
unsigned long V_8 ;
int V_77 = 0 , V_96 = 0 ;
F_53 ( & V_2 -> V_33 , V_8 ) ;
if ( V_26 )
V_96 = F_54 ( & V_2 -> V_97 , V_26 ) ;
if ( V_84 & V_2 -> V_8 ) {
F_55 ( & V_2 -> V_33 , V_8 ) ;
return V_96 ;
}
V_95 = F_56 ( & V_2 -> V_97 ) ;
V_94 = F_57 ( & V_2 -> V_97 ) ;
if ( V_94 )
V_2 -> V_8 |= V_84 ;
F_55 ( & V_2 -> V_33 , V_8 ) ;
if ( ! V_94 )
return V_96 ;
if ( V_95 )
V_95 -> V_89 ( V_95 , - V_56 ) ;
V_26 = F_58 ( V_94 ) ;
V_2 -> V_26 = V_26 ;
V_11 = F_15 ( V_26 ) ;
F_19 ( V_2 -> V_34 , L_12 ,
V_11 -> V_98 , V_26 -> V_99 ) ;
V_77 = F_50 ( V_2 ) ;
if ( V_77 )
goto V_100;
if ( V_11 -> V_98 == V_101 ) {
V_77 = F_41 ( V_2 ) ;
if ( V_77 != - V_56 && ( V_11 -> V_8 & V_74 ) ) {
V_77 = F_42 ( V_2 ) ;
}
} else if ( V_11 -> V_98 == V_102 ) {
V_77 = F_42 ( V_2 ) ;
}
V_100:
if ( V_77 != - V_56 )
F_47 ( V_26 , V_77 ) ;
F_19 ( V_2 -> V_34 , L_13 , V_77 ) ;
return V_96 ;
}
static int F_59 ( struct V_25 * V_26 , unsigned int V_98 )
{
struct V_10 * V_11 = F_15 ( V_26 ) ;
struct V_29 * V_30 = F_60 ( V_26 -> V_88 . V_28 ) ;
struct V_1 * V_2 = V_30 -> V_2 ;
V_11 -> V_98 = V_98 ;
return F_52 ( V_2 , V_26 ) ;
}
static int F_61 ( struct V_25 * V_26 )
{
struct V_10 * V_11 = F_15 ( V_26 ) ;
if ( ! V_26 -> V_99 )
return 0 ;
V_11 -> V_15 = V_26 -> V_99 ;
V_11 -> V_16 = V_26 -> V_103 ;
V_11 -> V_3 = 0 ;
if ( V_11 -> V_8 & V_74 ) {
if ( V_11 -> V_13 + V_11 -> V_15 < V_78 )
V_11 -> V_8 |= V_55 ;
} else if ( V_11 -> V_13 + V_11 -> V_15 < V_11 -> V_14 ) {
F_6 ( V_11 ) ;
return 0 ;
}
return F_59 ( V_26 , V_101 ) ;
}
static int F_62 ( struct V_25 * V_26 )
{
struct V_10 * V_11 = F_15 ( V_26 ) ;
struct V_29 * V_30 = F_60 ( V_26 -> V_88 . V_28 ) ;
struct V_1 * V_2 = V_30 -> V_2 ;
int V_77 = 0 ;
V_11 -> V_8 |= V_74 ;
if ( V_11 -> V_8 & V_83 )
return 0 ;
if ( V_11 -> V_13 ) {
return F_59 ( V_26 , V_102 ) ;
} else if ( ! ( V_11 -> V_8 & V_24 ) ) {
V_77 = F_50 ( V_2 ) ;
if ( V_77 )
goto V_100;
V_2 -> V_8 |= V_84 ;
V_77 = F_42 ( V_2 ) ;
} else {
return F_46 ( V_26 ) ;
}
V_100:
if ( V_77 != - V_56 )
F_47 ( V_26 , V_77 ) ;
return V_77 ;
}
static int F_63 ( struct V_25 * V_26 )
{
struct V_10 * V_11 = F_15 ( V_26 ) ;
int V_100 , V_104 ;
V_11 -> V_8 |= V_74 ;
V_100 = F_61 ( V_26 ) ;
if ( V_100 == - V_56 || V_100 == - V_105 )
return V_100 ;
V_104 = F_62 ( V_26 ) ;
return V_100 ? : V_104 ;
}
static int F_64 ( struct V_25 * V_26 )
{
return F_12 ( V_26 ) ? : F_63 ( V_26 ) ;
}
static int F_65 ( struct V_106 * V_28 , const char * V_107 )
{
struct V_29 * V_30 = F_60 ( V_28 ) ;
const char * V_108 = F_66 ( V_28 ) ;
V_30 -> V_109 = F_67 ( V_108 , 0 ,
V_110 ) ;
if ( F_68 ( V_30 -> V_109 ) ) {
F_69 ( L_14 ,
V_108 ) ;
return F_70 ( V_30 -> V_109 ) ;
}
F_71 ( F_72 ( V_28 ) ,
sizeof( struct V_10 ) +
V_39 + V_111 ) ;
return 0 ;
}
static int F_73 ( struct V_106 * V_28 )
{
return F_65 ( V_28 , NULL ) ;
}
static void F_74 ( struct V_106 * V_28 )
{
struct V_29 * V_30 = F_60 ( V_28 ) ;
F_75 ( V_30 -> V_109 ) ;
V_30 -> V_109 = NULL ;
}
static void F_76 ( unsigned long V_112 )
{
struct V_1 * V_2 = (struct V_1 * ) V_112 ;
int V_77 = 0 ;
if ( ! ( V_84 & V_2 -> V_8 ) ) {
F_52 ( V_2 , NULL ) ;
return;
}
if ( V_55 & V_2 -> V_8 ) {
if ( V_86 & V_2 -> V_8 ) {
V_2 -> V_8 &= ~ V_86 ;
goto V_113;
}
} else if ( V_85 & V_2 -> V_8 ) {
if ( V_67 & V_2 -> V_8 ) {
V_2 -> V_8 &= ~ V_67 ;
F_38 ( V_2 ) ;
if ( V_2 -> V_77 ) {
V_77 = V_2 -> V_77 ;
goto V_113;
}
}
if ( V_86 & V_2 -> V_8 ) {
V_2 -> V_8 &= ~ ( V_85 |
V_86 ) ;
V_77 = F_33 ( V_2 ) ;
if ( V_77 != - V_56 )
goto V_113;
}
}
return;
V_113:
F_47 ( V_2 -> V_26 , V_77 ) ;
}
static T_6 F_77 ( int V_114 , void * V_115 )
{
struct V_1 * V_116 = V_115 ;
T_1 V_117 ;
V_117 = F_1 ( V_116 , V_118 ) ;
if ( V_117 & F_1 ( V_116 , V_119 ) ) {
F_3 ( V_116 , V_120 , V_117 ) ;
if ( V_84 & V_116 -> V_8 ) {
V_116 -> V_8 |= V_86 ;
if ( ! ( V_55 & V_116 -> V_8 ) )
V_116 -> V_8 |= V_85 ;
F_49 ( & V_116 -> V_90 ) ;
} else {
F_78 ( V_116 -> V_34 , L_15 ) ;
}
return V_121 ;
}
return V_122 ;
}
static void F_79 ( struct V_1 * V_2 )
{
int V_81 ;
for ( V_81 = 0 ; V_81 < F_80 ( V_123 ) ; V_81 ++ )
F_81 ( & V_123 [ V_81 ] ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
int V_77 , V_81 , V_124 ;
for ( V_81 = 0 ; V_81 < F_80 ( V_123 ) ; V_81 ++ ) {
V_77 = F_83 ( & V_123 [ V_81 ] ) ;
if ( V_77 )
goto V_125;
}
return 0 ;
V_125:
for ( V_124 = 0 ; V_124 < V_81 ; V_124 ++ )
F_81 ( & V_123 [ V_124 ] ) ;
return V_77 ;
}
static int T_7 F_84 ( struct V_126 * V_127 )
{
struct V_1 * V_116 ;
struct V_128 * V_34 = & V_127 -> V_34 ;
struct V_129 * V_130 ;
unsigned long V_131 ;
int V_77 ;
V_116 = F_85 ( sizeof( struct V_1 ) , V_132 ) ;
if ( V_116 == NULL ) {
F_31 ( V_34 , L_16 ) ;
V_77 = - V_133 ;
goto V_134;
}
V_116 -> V_34 = V_34 ;
F_86 ( V_127 , V_116 ) ;
F_87 ( & V_116 -> V_135 ) ;
F_88 ( & V_116 -> V_90 , F_76 ,
( unsigned long ) V_116 ) ;
F_89 ( & V_116 -> V_97 , V_136 ) ;
V_116 -> V_114 = - 1 ;
V_130 = F_90 ( V_127 , V_137 , 0 ) ;
if ( ! V_130 ) {
F_31 ( V_34 , L_17 ) ;
V_77 = - V_138 ;
goto V_139;
}
V_116 -> V_140 = V_130 -> V_141 ;
V_131 = F_91 ( V_130 ) ;
V_116 -> V_114 = F_92 ( V_127 , 0 ) ;
if ( V_116 -> V_114 < 0 ) {
F_31 ( V_34 , L_18 ) ;
V_77 = V_116 -> V_114 ;
goto V_139;
}
V_77 = F_93 ( V_116 -> V_114 , F_77 , V_142 , L_19 ,
V_116 ) ;
if ( V_77 ) {
F_31 ( V_34 , L_20 ) ;
goto V_139;
}
V_116 -> V_87 = F_94 ( & V_127 -> V_34 , NULL ) ;
if ( F_68 ( V_116 -> V_87 ) ) {
F_31 ( V_34 , L_21 ) ;
V_77 = F_70 ( V_116 -> V_87 ) ;
goto V_143;
}
V_116 -> V_4 = F_95 ( V_116 -> V_140 , V_131 ) ;
if ( ! V_116 -> V_4 ) {
F_31 ( V_34 , L_22 ) ;
V_77 = - V_133 ;
goto V_144;
}
F_96 ( & V_32 . V_33 ) ;
F_97 ( & V_116 -> V_135 , & V_32 . V_145 ) ;
F_98 ( & V_32 . V_33 ) ;
V_77 = F_82 ( V_116 ) ;
if ( V_77 )
goto V_146;
F_99 ( V_34 , L_23 ) ;
return 0 ;
V_146:
F_96 ( & V_32 . V_33 ) ;
F_100 ( & V_116 -> V_135 ) ;
F_98 ( & V_32 . V_33 ) ;
F_101 ( V_116 -> V_4 ) ;
V_144:
F_102 ( V_116 -> V_87 ) ;
V_143:
F_103 ( V_116 -> V_114 , V_116 ) ;
V_139:
F_104 ( & V_116 -> V_90 ) ;
F_105 ( V_116 ) ;
V_116 = NULL ;
V_134:
F_31 ( V_34 , L_24 ) ;
return V_77 ;
}
static int T_8 F_106 ( struct V_126 * V_127 )
{
static struct V_1 * V_116 ;
V_116 = F_107 ( V_127 ) ;
if ( ! V_116 )
return - V_138 ;
F_96 ( & V_32 . V_33 ) ;
F_100 ( & V_116 -> V_135 ) ;
F_98 ( & V_32 . V_33 ) ;
F_79 ( V_116 ) ;
F_104 ( & V_116 -> V_90 ) ;
F_101 ( V_116 -> V_4 ) ;
F_102 ( V_116 -> V_87 ) ;
if ( V_116 -> V_114 >= 0 )
F_103 ( V_116 -> V_114 , V_116 ) ;
F_105 ( V_116 ) ;
V_116 = NULL ;
return 0 ;
}
