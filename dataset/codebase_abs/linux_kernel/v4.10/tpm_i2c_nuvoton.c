static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 ,
T_2 * V_5 )
{
T_1 V_6 ;
V_6 = F_2 ( V_2 , V_3 , V_4 , V_5 ) ;
F_3 ( & V_2 -> V_7 ,
L_1 , V_8 ,
V_3 , V_4 , ( int ) V_4 , V_5 , V_6 ) ;
return V_6 ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 ,
T_2 * V_5 )
{
T_1 V_6 ;
V_6 = F_5 ( V_2 , V_3 , V_4 , V_5 ) ;
F_3 ( & V_2 -> V_7 ,
L_1 , V_8 ,
V_3 , V_4 , ( int ) V_4 , V_5 , V_6 ) ;
return V_6 ;
}
static T_2 F_6 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 -> V_7 . V_11 ) ;
T_1 V_6 ;
T_2 V_5 ;
V_6 = F_1 ( V_2 , V_12 , 1 , & V_5 ) ;
if ( V_6 <= 0 ) {
F_8 ( & V_10 -> V_7 , L_2 , V_8 ,
V_6 ) ;
V_5 = V_13 ;
}
return V_5 ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_2 V_5 )
{
T_1 V_6 ;
int V_14 ;
for ( V_14 = 0 , V_6 = - 1 ; V_14 < V_15 && V_6 < 0 ; V_14 ++ ) {
V_6 = F_4 ( V_2 , V_12 , 1 , & V_5 ) ;
F_10 ( V_16 ) ;
}
return V_6 ;
}
static void F_11 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 -> V_7 . V_11 ) ;
T_1 V_6 ;
V_6 = F_9 ( V_2 , V_17 ) ;
if ( V_6 < 0 )
F_8 ( & V_10 -> V_7 ,
L_3 , V_8 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
unsigned long V_18 = V_19 + V_10 -> V_20 ;
T_1 V_6 ;
int V_21 = - 1 ;
T_2 V_5 ;
do {
V_6 = F_1 ( V_2 , V_22 , 1 ,
& V_5 ) ;
if ( V_6 > 0 && V_5 > 0 ) {
V_21 = F_13 ( T_2 , V_23 , V_5 ) ;
break;
}
F_10 ( V_16 ) ;
} while ( F_14 ( V_19 , V_18 ) );
return V_21 ;
}
static bool F_15 ( struct V_9 * V_10 , T_2 V_24 , T_2 V_25 )
{
T_2 V_6 = F_6 ( V_10 ) ;
return ( V_6 != V_13 ) && ( ( V_6 & V_24 ) == V_25 ) ;
}
static int F_16 ( struct V_9 * V_10 , T_2 V_24 , T_2 V_25 ,
T_3 V_26 , T_4 * V_27 )
{
if ( ( V_10 -> V_28 & V_29 ) && V_27 ) {
T_1 V_30 ;
struct V_31 * V_32 = F_17 ( & V_10 -> V_7 ) ;
unsigned int V_33 = V_32 -> V_34 ;
F_18 ( V_32 -> V_35 ) ;
V_30 = F_19 ( * V_27 ,
V_33 != V_32 -> V_34 ,
V_26 ) ;
if ( V_30 > 0 )
return 0 ;
} else {
unsigned long V_36 , V_18 ;
bool V_37 ;
V_37 = F_15 ( V_10 , V_24 , V_25 ) ;
if ( V_37 )
return 0 ;
V_36 = V_19 + F_20 ( V_38 ) ;
V_18 = V_19 + V_26 ;
do {
if ( F_14 ( V_19 , V_36 ) )
F_10 ( V_39 ) ;
else
F_10 ( V_38 ) ;
V_37 = F_15 ( V_10 , V_24 ,
V_25 ) ;
if ( V_37 )
return 0 ;
} while ( F_14 ( V_19 , V_18 ) );
}
F_8 ( & V_10 -> V_7 , L_4 , V_8 , V_24 ,
V_25 ) ;
return - V_40 ;
}
static int F_21 ( struct V_9 * V_10 , T_3 V_26 ,
T_4 * V_27 )
{
return F_16 ( V_10 ,
V_41 | V_42 ,
V_41 | V_42 ,
V_26 , V_27 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_9 * V_10 , T_2 * V_43 , T_5 V_44 )
{
struct V_31 * V_32 = F_17 ( & V_10 -> V_7 ) ;
T_1 V_30 ;
int V_21 , V_45 , V_4 = 0 ;
while ( V_4 < V_44 &&
F_21 ( V_10 ,
V_10 -> V_46 ,
& V_32 -> V_47 ) == 0 ) {
V_21 = F_12 ( V_2 , V_10 ) ;
if ( V_21 < 0 ) {
F_8 ( & V_10 -> V_7 ,
L_5 , V_8 ,
V_21 ) ;
return - V_48 ;
}
V_45 = F_13 ( T_5 , V_21 , V_44 - V_4 ) ;
V_30 = F_1 ( V_2 , V_49 ,
V_45 , & V_43 [ V_4 ] ) ;
if ( V_30 < 0 ) {
F_8 ( & V_10 -> V_7 ,
L_6 ,
V_8 , V_30 ) ;
return - V_48 ;
}
F_3 ( & V_10 -> V_7 , L_7 , V_8 , V_45 ) ;
V_4 += V_45 ;
}
return V_4 ;
}
static int F_23 ( struct V_9 * V_10 , T_2 * V_43 , T_5 V_44 )
{
struct V_31 * V_32 = F_17 ( & V_10 -> V_7 ) ;
struct V_50 * V_7 = V_10 -> V_7 . V_11 ;
struct V_1 * V_2 = F_7 ( V_7 ) ;
T_1 V_30 ;
int V_51 , V_6 , V_21 , V_52 , V_4 = 0 ;
if ( V_44 < V_53 ) {
F_11 ( V_10 ) ;
F_8 ( V_7 , L_8 , V_8 ) ;
return - V_48 ;
}
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
if ( V_52 > 0 ) {
F_9 ( V_2 ,
V_55 ) ;
}
V_6 = F_21 (
V_10 , V_10 -> V_46 , & V_32 -> V_47 ) ;
if ( V_6 != 0 ) {
F_8 ( V_7 , L_9 , V_8 ) ;
V_4 = - V_40 ;
continue;
}
V_21 = F_12 ( V_2 , V_10 ) ;
if ( V_21 < 0 ) {
F_8 ( V_7 , L_10 , V_8 ) ;
V_4 = - V_48 ;
continue;
}
V_4 = F_22 ( V_2 , V_10 , V_43 ,
V_21 ) ;
if ( V_4 < V_53 ) {
F_8 ( V_7 , L_11 , V_8 ) ;
V_4 = - V_48 ;
continue;
}
V_51 = F_24 ( * ( V_56 * ) ( V_43 + 2 ) ) ;
if ( V_51 > V_44 ) {
F_8 ( V_7 , L_12 , V_8 ) ;
V_4 = - V_48 ;
continue;
}
V_30 = F_22 ( V_2 , V_10 , & V_43 [ V_4 ] ,
V_51 - V_4 ) ;
V_4 += V_30 ;
if ( V_30 < 0 || V_4 < V_51 ) {
F_8 ( V_7 , L_13 ,
V_8 ) ;
V_4 = - V_48 ;
continue;
}
if ( F_16 (
V_10 , V_42 | V_41 ,
V_42 , V_10 -> V_46 ,
NULL ) ) {
F_8 ( V_7 , L_14 , V_8 ) ;
V_4 = - V_40 ;
continue;
}
break;
}
F_11 ( V_10 ) ;
F_3 ( & V_10 -> V_7 , L_15 , V_8 , V_4 ) ;
return V_4 ;
}
static int F_25 ( struct V_9 * V_10 , T_2 * V_43 , T_5 V_57 )
{
struct V_31 * V_32 = F_17 ( & V_10 -> V_7 ) ;
struct V_50 * V_7 = V_10 -> V_7 . V_11 ;
struct V_1 * V_2 = F_7 ( V_7 ) ;
T_3 V_58 ;
T_5 V_44 = 0 ;
int V_21 , V_59 , V_52 , V_30 = - V_48 ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
F_11 ( V_10 ) ;
if ( F_16 ( V_10 , V_17 ,
V_17 ,
V_10 -> V_60 , NULL ) ) {
F_8 ( V_7 , L_16 ,
V_8 ) ;
V_30 = - V_48 ;
continue;
}
V_30 = 0 ;
while ( V_44 < V_57 - 1 ) {
V_21 = F_12 ( V_2 ,
V_10 ) ;
if ( V_21 < 0 ) {
F_8 ( V_7 , L_17 ,
V_8 ) ;
V_30 = - V_48 ;
break;
}
V_59 = F_13 ( T_5 , V_21 ,
V_57 - 1 - V_44 ) ;
V_30 = F_4 ( V_2 , V_61 ,
V_59 , & V_43 [ V_44 ] ) ;
if ( V_30 < 0 ) {
F_8 ( V_7 , L_18 ,
V_8 ) ;
break;
}
F_3 ( V_7 , L_7 , V_8 , V_59 ) ;
V_44 += V_59 ;
V_30 = F_16 ( V_10 ,
V_42 |
V_62 ,
V_42 |
V_62 ,
V_10 -> V_46 ,
NULL ) ;
if ( V_30 < 0 ) {
F_8 ( V_7 , L_19 ,
V_8 ) ;
V_30 = - V_40 ;
break;
}
}
if ( V_30 < 0 )
continue;
V_30 = F_4 ( V_2 , V_61 , 1 ,
& V_43 [ V_44 ] ) ;
if ( V_30 < 0 ) {
F_8 ( V_7 , L_20 ,
V_8 ) ;
V_30 = - V_48 ;
continue;
}
F_3 ( V_7 , L_21 , V_8 , V_43 [ V_44 ] ) ;
V_30 = F_16 ( V_10 ,
V_42 | V_62 ,
V_42 ,
V_10 -> V_46 , NULL ) ;
if ( V_30 ) {
F_8 ( V_7 , L_22 ,
V_8 ) ;
V_30 = - V_40 ;
continue;
}
break;
}
if ( V_30 < 0 ) {
F_11 ( V_10 ) ;
return V_30 ;
}
V_30 = F_9 ( V_2 , V_63 ) ;
if ( V_30 < 0 ) {
F_8 ( V_7 , L_23 , V_8 ) ;
F_11 ( V_10 ) ;
return V_30 ;
}
V_58 = F_24 ( * ( ( V_56 * ) ( V_43 + 6 ) ) ) ;
V_30 = F_21 ( V_10 ,
F_26 ( V_10 ,
V_58 ) ,
& V_32 -> V_47 ) ;
if ( V_30 ) {
F_8 ( V_7 , L_24 , V_8 ) ;
F_11 ( V_10 ) ;
return V_30 ;
}
F_3 ( V_7 , L_25 , V_8 , V_57 ) ;
return V_57 ;
}
static bool F_27 ( struct V_9 * V_10 , T_2 V_6 )
{
return ( V_6 == V_17 ) ;
}
static T_6 F_28 ( int V_64 , void * V_65 )
{
struct V_9 * V_10 = V_65 ;
struct V_31 * V_32 = F_17 ( & V_10 -> V_7 ) ;
V_32 -> V_34 ++ ;
F_29 ( & V_32 -> V_47 ) ;
F_30 ( V_32 -> V_35 ) ;
return V_66 ;
}
static int F_31 ( struct V_1 * V_2 , T_3 * V_67 )
{
static const T_2 V_68 [] = { 0x50 , 0x10 , 0xfe } ;
T_3 V_69 ;
T_1 V_30 ;
if ( ! F_32 ( V_2 -> V_70 , V_71 ) )
return - V_72 ;
V_30 = F_1 ( V_2 , V_73 , 4 , ( T_2 * ) & V_69 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( memcmp ( & V_69 , V_68 , sizeof( V_68 ) ) ) {
V_30 = F_1 ( V_2 , V_61 , 4 ,
( T_2 * ) ( & V_69 ) ) ;
if ( V_30 < 0 )
return V_30 ;
if ( memcmp ( & V_69 , V_68 ,
sizeof( V_68 ) ) )
return - V_72 ;
}
* V_67 = V_69 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_74 * V_75 )
{
int V_30 ;
struct V_9 * V_10 ;
struct V_50 * V_7 = & V_2 -> V_7 ;
struct V_31 * V_32 ;
T_3 V_76 = 0 ;
V_30 = F_31 ( V_2 , & V_76 ) ;
if ( V_30 )
return V_30 ;
F_34 ( V_7 , L_26 , ( V_77 ) V_76 ,
( T_2 ) ( V_76 >> 16 ) , ( T_2 ) ( V_76 >> 24 ) ) ;
V_10 = F_35 ( V_7 , & V_78 ) ;
if ( F_36 ( V_10 ) )
return F_37 ( V_10 ) ;
V_32 = F_38 ( V_7 , sizeof( struct V_31 ) , V_79 ) ;
if ( ! V_32 )
return - V_80 ;
if ( V_7 -> V_81 ) {
const struct V_82 * V_83 ;
V_83 = F_39 ( V_7 -> V_84 -> V_85 , V_7 ) ;
if ( V_83 && V_83 -> V_5 == V_86 )
V_10 -> V_28 |= V_87 ;
} else
if ( V_75 -> V_88 == V_89 )
V_10 -> V_28 |= V_87 ;
F_40 ( & V_32 -> V_47 ) ;
V_10 -> V_90 = F_20 ( V_91 ) ;
V_10 -> V_60 = F_20 ( V_92 ) ;
V_10 -> V_46 = F_20 ( V_91 ) ;
V_10 -> V_20 = F_20 ( V_91 ) ;
F_41 ( & V_10 -> V_7 , V_32 ) ;
V_32 -> V_35 = V_2 -> V_35 ;
if ( V_2 -> V_35 ) {
F_3 ( V_7 , L_27 , V_8 ) ;
V_30 = F_42 ( V_7 , V_2 -> V_35 ,
F_28 ,
V_93 ,
F_43 ( & V_10 -> V_7 ) ,
V_10 ) ;
if ( V_30 ) {
F_8 ( V_7 , L_28 ,
V_8 , V_32 -> V_35 ) ;
V_32 -> V_35 = 0 ;
} else {
V_10 -> V_28 |= V_29 ;
F_11 ( V_10 ) ;
V_30 = F_16 ( V_10 ,
V_17 ,
V_17 ,
V_10 -> V_60 ,
NULL ) ;
if ( V_30 == 0 ) {
V_30 = F_4 ( V_2 ,
V_61 ,
1 , ( T_2 * ) ( & V_30 ) ) ;
if ( V_30 < 0 )
return V_30 ;
F_11 ( V_10 ) ;
} else {
if ( F_6 ( V_10 ) !=
V_42 )
return - V_48 ;
}
}
}
return F_44 ( V_10 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_46 ( V_2 ) ;
F_47 ( V_10 ) ;
return 0 ;
}
