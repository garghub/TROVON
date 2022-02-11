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
struct V_1 * V_2 = F_7 ( V_10 -> V_11 ) ;
T_1 V_6 ;
T_2 V_5 ;
V_6 = F_1 ( V_2 , V_12 , 1 , & V_5 ) ;
if ( V_6 <= 0 ) {
F_8 ( V_10 -> V_11 , L_2 , V_8 ,
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
struct V_1 * V_2 = F_7 ( V_10 -> V_11 ) ;
T_1 V_6 ;
V_6 = F_9 ( V_2 , V_17 ) ;
if ( V_6 < 0 )
F_8 ( V_10 -> V_11 ,
L_3 , V_8 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
unsigned long V_18 = V_19 + V_10 -> V_20 . V_21 ;
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
F_10 ( V_16 ) ;
} while ( F_14 ( V_19 , V_18 ) );
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
if ( V_10 -> V_20 . V_29 && V_28 ) {
T_1 V_30 ;
struct V_31 * V_32 = V_10 -> V_20 . V_32 ;
unsigned int V_33 = V_32 -> V_34 ;
F_17 ( V_10 -> V_20 . V_29 ) ;
V_30 = F_18 ( * V_28 ,
V_33 != V_32 -> V_34 ,
V_27 ) ;
if ( V_30 > 0 )
return 0 ;
} else {
unsigned long V_35 , V_18 ;
bool V_36 ;
V_36 = F_15 ( V_10 , V_25 , V_26 ) ;
if ( V_36 )
return 0 ;
V_35 = V_19 + F_19 ( V_37 ) ;
V_18 = V_19 + V_27 ;
do {
if ( F_14 ( V_19 , V_35 ) )
F_10 ( V_38 ) ;
else
F_10 ( V_37 ) ;
V_36 = F_15 ( V_10 , V_25 ,
V_26 ) ;
if ( V_36 )
return 0 ;
} while ( F_14 ( V_19 , V_18 ) );
}
F_8 ( V_10 -> V_11 , L_4 , V_8 , V_25 ,
V_26 ) ;
return - V_39 ;
}
static int F_20 ( struct V_9 * V_10 , T_3 V_27 ,
T_4 * V_28 )
{
return F_16 ( V_10 ,
V_40 | V_41 ,
V_40 | V_41 ,
V_27 , V_28 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_9 * V_10 , T_2 * V_42 , T_5 V_43 )
{
T_1 V_30 ;
int V_22 , V_44 , V_4 = 0 ;
while ( V_4 < V_43 &&
F_20 ( V_10 ,
V_10 -> V_20 . V_45 ,
& V_10 -> V_20 . V_46 ) == 0 ) {
V_22 = F_12 ( V_2 , V_10 ) ;
if ( V_22 < 0 ) {
F_8 ( V_10 -> V_11 ,
L_5 , V_8 ,
V_22 ) ;
return - V_47 ;
}
V_44 = F_13 ( T_5 , V_22 , V_43 - V_4 ) ;
V_30 = F_1 ( V_2 , V_48 ,
V_44 , & V_42 [ V_4 ] ) ;
if ( V_30 < 0 ) {
F_8 ( V_10 -> V_11 ,
L_6 ,
V_8 , V_30 ) ;
return - V_47 ;
}
F_3 ( V_10 -> V_11 , L_7 , V_8 , V_44 ) ;
V_4 += V_44 ;
}
return V_4 ;
}
static int F_22 ( struct V_9 * V_10 , T_2 * V_42 , T_5 V_43 )
{
struct V_49 * V_7 = V_10 -> V_11 ;
struct V_1 * V_2 = F_7 ( V_7 ) ;
T_1 V_30 ;
int V_50 , V_6 , V_22 , V_51 , V_4 = 0 ;
if ( V_43 < V_52 ) {
F_11 ( V_10 ) ;
F_8 ( V_7 , L_8 , V_8 ) ;
return - V_47 ;
}
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ ) {
if ( V_51 > 0 ) {
F_9 ( V_2 ,
V_54 ) ;
}
V_6 = F_20 (
V_10 , V_10 -> V_20 . V_45 , & V_10 -> V_20 . V_46 ) ;
if ( V_6 != 0 ) {
F_8 ( V_7 , L_9 , V_8 ) ;
V_4 = - V_39 ;
continue;
}
V_22 = F_12 ( V_2 , V_10 ) ;
if ( V_22 < 0 ) {
F_8 ( V_7 , L_10 , V_8 ) ;
V_4 = - V_47 ;
continue;
}
V_4 = F_21 ( V_2 , V_10 , V_42 ,
V_22 ) ;
if ( V_4 < V_52 ) {
F_8 ( V_7 , L_11 , V_8 ) ;
V_4 = - V_47 ;
continue;
}
V_50 = F_23 ( * ( V_55 * ) ( V_42 + 2 ) ) ;
if ( V_50 > V_43 ) {
F_8 ( V_7 , L_12 , V_8 ) ;
V_4 = - V_47 ;
continue;
}
V_30 = F_21 ( V_2 , V_10 , & V_42 [ V_4 ] ,
V_50 - V_4 ) ;
V_4 += V_30 ;
if ( V_30 < 0 || V_4 < V_50 ) {
F_8 ( V_7 , L_13 ,
V_8 ) ;
V_4 = - V_47 ;
continue;
}
if ( F_16 (
V_10 , V_41 | V_40 ,
V_41 , V_10 -> V_20 . V_45 ,
NULL ) ) {
F_8 ( V_7 , L_14 , V_8 ) ;
V_4 = - V_39 ;
continue;
}
break;
}
F_11 ( V_10 ) ;
F_3 ( V_10 -> V_11 , L_15 , V_8 , V_4 ) ;
return V_4 ;
}
static int F_24 ( struct V_9 * V_10 , T_2 * V_42 , T_5 V_56 )
{
struct V_49 * V_7 = V_10 -> V_11 ;
struct V_1 * V_2 = F_7 ( V_7 ) ;
T_3 V_57 ;
T_5 V_43 = 0 ;
int V_22 , V_58 , V_51 , V_30 = - V_47 ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ ) {
F_11 ( V_10 ) ;
if ( F_16 ( V_10 , V_17 ,
V_17 ,
V_10 -> V_20 . V_59 , NULL ) ) {
F_8 ( V_7 , L_16 ,
V_8 ) ;
V_30 = - V_47 ;
continue;
}
V_30 = 0 ;
while ( V_43 < V_56 - 1 ) {
V_22 = F_12 ( V_2 ,
V_10 ) ;
if ( V_22 < 0 ) {
F_8 ( V_7 , L_17 ,
V_8 ) ;
V_30 = - V_47 ;
break;
}
V_58 = F_13 ( T_5 , V_22 ,
V_56 - 1 - V_43 ) ;
V_30 = F_4 ( V_2 , V_60 ,
V_58 , & V_42 [ V_43 ] ) ;
if ( V_30 < 0 ) {
F_8 ( V_7 , L_18 ,
V_8 ) ;
break;
}
F_3 ( V_7 , L_7 , V_8 , V_58 ) ;
V_43 += V_58 ;
V_30 = F_16 ( V_10 ,
V_41 |
V_61 ,
V_41 |
V_61 ,
V_10 -> V_20 . V_45 ,
NULL ) ;
if ( V_30 < 0 ) {
F_8 ( V_7 , L_19 ,
V_8 ) ;
V_30 = - V_39 ;
break;
}
}
if ( V_30 < 0 )
continue;
V_30 = F_4 ( V_2 , V_60 , 1 ,
& V_42 [ V_43 ] ) ;
if ( V_30 < 0 ) {
F_8 ( V_7 , L_20 ,
V_8 ) ;
V_30 = - V_47 ;
continue;
}
F_3 ( V_7 , L_21 , V_8 , V_42 [ V_43 ] ) ;
V_30 = F_16 ( V_10 ,
V_41 | V_61 ,
V_41 ,
V_10 -> V_20 . V_45 , NULL ) ;
if ( V_30 ) {
F_8 ( V_7 , L_22 ,
V_8 ) ;
V_30 = - V_39 ;
continue;
}
break;
}
if ( V_30 < 0 ) {
F_11 ( V_10 ) ;
return V_30 ;
}
V_30 = F_9 ( V_2 , V_62 ) ;
if ( V_30 < 0 ) {
F_8 ( V_7 , L_23 , V_8 ) ;
F_11 ( V_10 ) ;
return V_30 ;
}
V_57 = F_23 ( * ( ( V_55 * ) ( V_42 + 6 ) ) ) ;
V_30 = F_20 ( V_10 ,
F_25 ( V_10 ,
V_57 ) ,
& V_10 -> V_20 . V_46 ) ;
if ( V_30 ) {
F_8 ( V_7 , L_24 , V_8 ) ;
F_11 ( V_10 ) ;
return V_30 ;
}
F_3 ( V_7 , L_25 , V_8 , V_56 ) ;
return V_56 ;
}
static bool F_26 ( struct V_9 * V_10 , T_2 V_6 )
{
return ( V_6 == V_17 ) ;
}
static T_6 F_27 ( int V_63 , void * V_64 )
{
struct V_9 * V_10 = V_64 ;
struct V_31 * V_32 = V_10 -> V_20 . V_32 ;
V_32 -> V_34 ++ ;
F_28 ( & V_10 -> V_20 . V_46 ) ;
F_29 ( V_10 -> V_20 . V_29 ) ;
return V_65 ;
}
static int F_30 ( struct V_1 * V_2 , T_3 * V_66 )
{
static const T_2 V_67 [] = { 0x50 , 0x10 , 0xfe } ;
T_3 V_68 ;
T_1 V_30 ;
if ( ! F_31 ( V_2 -> V_69 , V_70 ) )
return - V_71 ;
V_30 = F_1 ( V_2 , V_72 , 4 , ( T_2 * ) & V_68 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( memcmp ( & V_68 , V_67 , sizeof( V_67 ) ) ) {
V_30 = F_1 ( V_2 , V_60 , 4 ,
( T_2 * ) ( & V_68 ) ) ;
if ( V_30 < 0 )
return V_30 ;
if ( memcmp ( & V_68 , V_67 ,
sizeof( V_67 ) ) )
return - V_71 ;
}
* V_66 = V_68 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_73 * V_74 )
{
int V_30 ;
struct V_9 * V_10 ;
struct V_49 * V_7 = & V_2 -> V_7 ;
T_3 V_75 = 0 ;
V_30 = F_30 ( V_2 , & V_75 ) ;
if ( V_30 )
return V_30 ;
F_33 ( V_7 , L_26 , ( V_76 ) V_75 ,
( T_2 ) ( V_75 >> 16 ) , ( T_2 ) ( V_75 >> 24 ) ) ;
V_10 = F_34 ( V_7 , & V_77 ) ;
if ( F_35 ( V_10 ) )
return F_36 ( V_10 ) ;
V_10 -> V_20 . V_32 = F_37 ( V_7 , sizeof( struct V_31 ) ,
V_78 ) ;
if ( ! V_10 -> V_20 . V_32 )
return - V_79 ;
F_38 ( & V_10 -> V_20 . V_46 ) ;
F_38 ( & V_10 -> V_20 . V_80 ) ;
V_10 -> V_20 . V_81 = F_19 ( V_82 ) ;
V_10 -> V_20 . V_59 = F_19 ( V_83 ) ;
V_10 -> V_20 . V_45 = F_19 ( V_82 ) ;
V_10 -> V_20 . V_21 = F_19 ( V_82 ) ;
V_10 -> V_20 . V_29 = V_2 -> V_29 ;
if ( V_10 -> V_20 . V_29 ) {
F_3 ( V_7 , L_27 , V_8 ) ;
V_30 = F_39 ( V_7 , V_10 -> V_20 . V_29 ,
F_27 ,
V_84 ,
V_10 -> V_85 ,
V_10 ) ;
if ( V_30 ) {
F_8 ( V_7 , L_28 ,
V_8 , V_10 -> V_20 . V_29 ) ;
V_10 -> V_20 . V_29 = 0 ;
} else {
F_11 ( V_10 ) ;
V_30 = F_16 ( V_10 ,
V_17 ,
V_17 ,
V_10 -> V_20 . V_59 ,
NULL ) ;
if ( V_30 == 0 ) {
V_30 = F_4 ( V_2 ,
V_60 ,
1 , ( T_2 * ) ( & V_30 ) ) ;
if ( V_30 < 0 )
return V_30 ;
F_11 ( V_10 ) ;
} else {
if ( F_6 ( V_10 ) !=
V_41 )
return - V_47 ;
}
}
}
if ( F_40 ( V_10 ) )
return - V_71 ;
if ( F_41 ( V_10 ) )
return - V_71 ;
return F_42 ( V_10 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_49 * V_7 = & ( V_2 -> V_7 ) ;
struct V_9 * V_10 = F_44 ( V_7 ) ;
F_45 ( V_10 ) ;
return 0 ;
}
