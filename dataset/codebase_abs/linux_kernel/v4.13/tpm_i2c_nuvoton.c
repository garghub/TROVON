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
if ( V_6 < 0 )
F_10 ( V_16 , V_16
+ V_17 ) ;
}
return V_6 ;
}
static void F_11 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 -> V_7 . V_11 ) ;
T_1 V_6 ;
V_6 = F_9 ( V_2 , V_18 ) ;
if ( V_6 < 0 )
F_8 ( & V_10 -> V_7 ,
L_3 , V_8 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
unsigned long V_19 = V_20 + V_10 -> V_21 ;
T_1 V_6 ;
int V_22 = - 1 ;
T_2 V_5 ;
do {
V_6 = F_1 ( V_2 , V_23 , 1 ,
& V_5 ) ;
if ( V_6 > 0 && V_5 > 0 ) {
V_22 = F_13 ( T_2 , V_24 , V_5 ) ;
break;
}
F_10 ( V_16 , V_16
+ V_17 ) ;
} while ( F_14 ( V_20 , V_19 ) );
return V_22 ;
}
static bool F_15 ( struct V_9 * V_10 , T_2 V_25 , T_2 V_26 )
{
T_2 V_6 = F_6 ( V_10 ) ;
return ( V_6 != V_13 ) && ( ( V_6 & V_25 ) == V_26 ) ;
}
static int F_16 ( struct V_9 * V_10 , T_2 V_25 , T_2 V_26 ,
T_3 V_27 , T_4 * V_28 )
{
if ( ( V_10 -> V_29 & V_30 ) && V_28 ) {
T_1 V_31 ;
struct V_32 * V_33 = F_17 ( & V_10 -> V_7 ) ;
unsigned int V_34 = V_33 -> V_35 ;
F_18 ( V_33 -> V_36 ) ;
V_31 = F_19 ( * V_28 ,
V_34 != V_33 -> V_35 ,
V_27 ) ;
if ( V_31 > 0 )
return 0 ;
} else {
unsigned long V_37 , V_19 ;
bool V_38 ;
V_38 = F_15 ( V_10 , V_25 , V_26 ) ;
if ( V_38 )
return 0 ;
V_37 = V_20 + F_20 ( V_39 ) ;
V_19 = V_20 + V_27 ;
do {
if ( F_14 ( V_20 , V_37 ) )
F_10 ( V_40 ,
V_40
+ V_17 ) ;
else
F_10 ( V_39 ,
V_39
+ V_17 ) ;
V_38 = F_15 ( V_10 , V_25 ,
V_26 ) ;
if ( V_38 )
return 0 ;
} while ( F_14 ( V_20 , V_19 ) );
}
F_8 ( & V_10 -> V_7 , L_4 , V_8 , V_25 ,
V_26 ) ;
return - V_41 ;
}
static int F_21 ( struct V_9 * V_10 , T_3 V_27 ,
T_4 * V_28 )
{
return F_16 ( V_10 ,
V_42 | V_43 ,
V_42 | V_43 ,
V_27 , V_28 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_9 * V_10 , T_2 * V_44 , T_5 V_45 )
{
struct V_32 * V_33 = F_17 ( & V_10 -> V_7 ) ;
T_1 V_31 ;
int V_22 , V_46 , V_4 = 0 ;
while ( V_4 < V_45 &&
F_21 ( V_10 ,
V_10 -> V_47 ,
& V_33 -> V_48 ) == 0 ) {
V_22 = F_12 ( V_2 , V_10 ) ;
if ( V_22 < 0 ) {
F_8 ( & V_10 -> V_7 ,
L_5 , V_8 ,
V_22 ) ;
return - V_49 ;
}
V_46 = F_13 ( T_5 , V_22 , V_45 - V_4 ) ;
V_31 = F_1 ( V_2 , V_50 ,
V_46 , & V_44 [ V_4 ] ) ;
if ( V_31 < 0 ) {
F_8 ( & V_10 -> V_7 ,
L_6 ,
V_8 , V_31 ) ;
return - V_49 ;
}
F_3 ( & V_10 -> V_7 , L_7 , V_8 , V_46 ) ;
V_4 += V_46 ;
}
return V_4 ;
}
static int F_23 ( struct V_9 * V_10 , T_2 * V_44 , T_5 V_45 )
{
struct V_32 * V_33 = F_17 ( & V_10 -> V_7 ) ;
struct V_51 * V_7 = V_10 -> V_7 . V_11 ;
struct V_1 * V_2 = F_7 ( V_7 ) ;
T_1 V_31 ;
int V_52 , V_6 , V_22 , V_53 , V_4 = 0 ;
if ( V_45 < V_54 ) {
F_11 ( V_10 ) ;
F_8 ( V_7 , L_8 , V_8 ) ;
return - V_49 ;
}
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
if ( V_53 > 0 ) {
F_9 ( V_2 ,
V_56 ) ;
}
V_6 = F_21 (
V_10 , V_10 -> V_47 , & V_33 -> V_48 ) ;
if ( V_6 != 0 ) {
F_8 ( V_7 , L_9 , V_8 ) ;
V_4 = - V_41 ;
continue;
}
V_22 = F_12 ( V_2 , V_10 ) ;
if ( V_22 < 0 ) {
F_8 ( V_7 , L_10 , V_8 ) ;
V_4 = - V_49 ;
continue;
}
V_4 = F_22 ( V_2 , V_10 , V_44 ,
V_22 ) ;
if ( V_4 < V_54 ) {
F_8 ( V_7 , L_11 , V_8 ) ;
V_4 = - V_49 ;
continue;
}
V_52 = F_24 ( * ( V_57 * ) ( V_44 + 2 ) ) ;
if ( V_52 > V_45 ) {
F_8 ( V_7 , L_12 , V_8 ) ;
V_4 = - V_49 ;
continue;
}
V_31 = F_22 ( V_2 , V_10 , & V_44 [ V_4 ] ,
V_52 - V_4 ) ;
V_4 += V_31 ;
if ( V_31 < 0 || V_4 < V_52 ) {
F_8 ( V_7 , L_13 ,
V_8 ) ;
V_4 = - V_49 ;
continue;
}
if ( F_16 (
V_10 , V_43 | V_42 ,
V_43 , V_10 -> V_47 ,
NULL ) ) {
F_8 ( V_7 , L_14 , V_8 ) ;
V_4 = - V_41 ;
continue;
}
break;
}
F_11 ( V_10 ) ;
F_3 ( & V_10 -> V_7 , L_15 , V_8 , V_4 ) ;
return V_4 ;
}
static int F_25 ( struct V_9 * V_10 , T_2 * V_44 , T_5 V_58 )
{
struct V_32 * V_33 = F_17 ( & V_10 -> V_7 ) ;
struct V_51 * V_7 = V_10 -> V_7 . V_11 ;
struct V_1 * V_2 = F_7 ( V_7 ) ;
T_3 V_59 ;
T_5 V_45 = 0 ;
int V_22 , V_60 , V_53 , V_31 = - V_49 ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
F_11 ( V_10 ) ;
if ( F_16 ( V_10 , V_18 ,
V_18 ,
V_10 -> V_61 , NULL ) ) {
F_8 ( V_7 , L_16 ,
V_8 ) ;
V_31 = - V_49 ;
continue;
}
V_31 = 0 ;
while ( V_45 < V_58 - 1 ) {
V_22 = F_12 ( V_2 ,
V_10 ) ;
if ( V_22 < 0 ) {
F_8 ( V_7 , L_17 ,
V_8 ) ;
V_31 = - V_49 ;
break;
}
V_60 = F_13 ( T_5 , V_22 ,
V_58 - 1 - V_45 ) ;
V_31 = F_4 ( V_2 , V_62 ,
V_60 , & V_44 [ V_45 ] ) ;
if ( V_31 < 0 ) {
F_8 ( V_7 , L_18 ,
V_8 ) ;
break;
}
F_3 ( V_7 , L_7 , V_8 , V_60 ) ;
V_45 += V_60 ;
V_31 = F_16 ( V_10 ,
V_43 |
V_63 ,
V_43 |
V_63 ,
V_10 -> V_47 ,
NULL ) ;
if ( V_31 < 0 ) {
F_8 ( V_7 , L_19 ,
V_8 ) ;
V_31 = - V_41 ;
break;
}
}
if ( V_31 < 0 )
continue;
V_31 = F_4 ( V_2 , V_62 , 1 ,
& V_44 [ V_45 ] ) ;
if ( V_31 < 0 ) {
F_8 ( V_7 , L_20 ,
V_8 ) ;
V_31 = - V_49 ;
continue;
}
F_3 ( V_7 , L_21 , V_8 , V_44 [ V_45 ] ) ;
V_31 = F_16 ( V_10 ,
V_43 | V_63 ,
V_43 ,
V_10 -> V_47 , NULL ) ;
if ( V_31 ) {
F_8 ( V_7 , L_22 ,
V_8 ) ;
V_31 = - V_41 ;
continue;
}
break;
}
if ( V_31 < 0 ) {
F_11 ( V_10 ) ;
return V_31 ;
}
V_31 = F_9 ( V_2 , V_64 ) ;
if ( V_31 < 0 ) {
F_8 ( V_7 , L_23 , V_8 ) ;
F_11 ( V_10 ) ;
return V_31 ;
}
V_59 = F_24 ( * ( ( V_57 * ) ( V_44 + 6 ) ) ) ;
V_31 = F_21 ( V_10 ,
F_26 ( V_10 ,
V_59 ) ,
& V_33 -> V_48 ) ;
if ( V_31 ) {
F_8 ( V_7 , L_24 , V_8 ) ;
F_11 ( V_10 ) ;
return V_31 ;
}
F_3 ( V_7 , L_25 , V_8 , V_58 ) ;
return V_58 ;
}
static bool F_27 ( struct V_9 * V_10 , T_2 V_6 )
{
return ( V_6 == V_18 ) ;
}
static T_6 F_28 ( int V_65 , void * V_66 )
{
struct V_9 * V_10 = V_66 ;
struct V_32 * V_33 = F_17 ( & V_10 -> V_7 ) ;
V_33 -> V_35 ++ ;
F_29 ( & V_33 -> V_48 ) ;
F_30 ( V_33 -> V_36 ) ;
return V_67 ;
}
static int F_31 ( struct V_1 * V_2 , T_3 * V_68 )
{
static const T_2 V_69 [] = { 0x50 , 0x10 , 0xfe } ;
T_3 V_70 ;
T_1 V_31 ;
if ( ! F_32 ( V_2 -> V_71 , V_72 ) )
return - V_73 ;
V_31 = F_1 ( V_2 , V_74 , 4 , ( T_2 * ) & V_70 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( memcmp ( & V_70 , V_69 , sizeof( V_69 ) ) ) {
V_31 = F_1 ( V_2 , V_62 , 4 ,
( T_2 * ) ( & V_70 ) ) ;
if ( V_31 < 0 )
return V_31 ;
if ( memcmp ( & V_70 , V_69 ,
sizeof( V_69 ) ) )
return - V_73 ;
}
* V_68 = V_70 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_75 * V_76 )
{
int V_31 ;
struct V_9 * V_10 ;
struct V_51 * V_7 = & V_2 -> V_7 ;
struct V_32 * V_33 ;
T_3 V_77 = 0 ;
V_31 = F_31 ( V_2 , & V_77 ) ;
if ( V_31 )
return V_31 ;
F_34 ( V_7 , L_26 , ( V_78 ) V_77 ,
( T_2 ) ( V_77 >> 16 ) , ( T_2 ) ( V_77 >> 24 ) ) ;
V_10 = F_35 ( V_7 , & V_79 ) ;
if ( F_36 ( V_10 ) )
return F_37 ( V_10 ) ;
V_33 = F_38 ( V_7 , sizeof( struct V_32 ) , V_80 ) ;
if ( ! V_33 )
return - V_81 ;
if ( V_7 -> V_82 ) {
const struct V_83 * V_84 ;
V_84 = F_39 ( V_7 -> V_85 -> V_86 , V_7 ) ;
if ( V_84 && V_84 -> V_5 == V_87 )
V_10 -> V_29 |= V_88 ;
} else
if ( V_76 -> V_89 == V_90 )
V_10 -> V_29 |= V_88 ;
F_40 ( & V_33 -> V_48 ) ;
V_10 -> V_91 = F_41 ( V_92 ) ;
V_10 -> V_61 = F_41 ( V_93 ) ;
V_10 -> V_47 = F_41 ( V_92 ) ;
V_10 -> V_21 = F_41 ( V_92 ) ;
F_42 ( & V_10 -> V_7 , V_33 ) ;
V_33 -> V_36 = V_2 -> V_36 ;
if ( V_2 -> V_36 ) {
F_3 ( V_7 , L_27 , V_8 ) ;
V_31 = F_43 ( V_7 , V_2 -> V_36 ,
F_28 ,
V_94 ,
F_44 ( & V_10 -> V_7 ) ,
V_10 ) ;
if ( V_31 ) {
F_8 ( V_7 , L_28 ,
V_8 , V_33 -> V_36 ) ;
V_33 -> V_36 = 0 ;
} else {
V_10 -> V_29 |= V_30 ;
F_11 ( V_10 ) ;
V_31 = F_16 ( V_10 ,
V_18 ,
V_18 ,
V_10 -> V_61 ,
NULL ) ;
if ( V_31 == 0 ) {
V_31 = F_4 ( V_2 ,
V_62 ,
1 , ( T_2 * ) ( & V_31 ) ) ;
if ( V_31 < 0 )
return V_31 ;
F_11 ( V_10 ) ;
} else {
if ( F_6 ( V_10 ) !=
V_43 )
return - V_49 ;
}
}
}
return F_45 ( V_10 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_47 ( V_2 ) ;
F_48 ( V_10 ) ;
return 0 ;
}
