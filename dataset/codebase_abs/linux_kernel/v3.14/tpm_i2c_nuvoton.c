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
struct V_1 * V_2 = F_7 ( V_10 -> V_7 ) ;
T_1 V_6 ;
T_2 V_5 ;
V_6 = F_1 ( V_2 , V_11 , 1 , & V_5 ) ;
if ( V_6 <= 0 ) {
F_8 ( V_10 -> V_7 , L_2 , V_8 ,
V_6 ) ;
V_5 = V_12 ;
}
return V_5 ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_2 V_5 )
{
T_1 V_6 ;
int V_13 ;
for ( V_13 = 0 , V_6 = - 1 ; V_13 < V_14 && V_6 < 0 ; V_13 ++ ) {
V_6 = F_4 ( V_2 , V_11 , 1 , & V_5 ) ;
F_10 ( V_15 ) ;
}
return V_6 ;
}
static void F_11 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 -> V_7 ) ;
T_1 V_6 ;
V_6 = F_9 ( V_2 , V_16 ) ;
if ( V_6 < 0 )
F_8 ( V_10 -> V_7 ,
L_3 , V_8 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
unsigned long V_17 = V_18 + V_10 -> V_19 . V_20 ;
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
F_10 ( V_15 ) ;
} while ( F_14 ( V_18 , V_17 ) );
return V_21 ;
}
static bool F_15 ( struct V_9 * V_10 , T_2 V_24 , T_2 V_25 )
{
T_2 V_6 = F_6 ( V_10 ) ;
return ( V_6 != V_12 ) && ( ( V_6 & V_24 ) == V_25 ) ;
}
static int F_16 ( struct V_9 * V_10 , T_2 V_24 , T_2 V_25 ,
T_3 V_26 , T_4 * V_27 )
{
if ( V_10 -> V_19 . V_28 && V_27 ) {
T_1 V_29 ;
struct V_30 * V_31 = V_10 -> V_19 . V_31 ;
unsigned int V_32 = V_31 -> V_33 ;
F_17 ( V_10 -> V_19 . V_28 ) ;
V_29 = F_18 ( * V_27 ,
V_32 != V_31 -> V_33 ,
V_26 ) ;
if ( V_29 > 0 )
return 0 ;
} else {
unsigned long V_34 , V_17 ;
bool V_35 ;
V_35 = F_15 ( V_10 , V_24 , V_25 ) ;
if ( V_35 )
return 0 ;
V_34 = V_18 + F_19 ( V_36 ) ;
V_17 = V_18 + V_26 ;
do {
if ( F_14 ( V_18 , V_34 ) )
F_10 ( V_37 ) ;
else
F_10 ( V_36 ) ;
V_35 = F_15 ( V_10 , V_24 ,
V_25 ) ;
if ( V_35 )
return 0 ;
} while ( F_14 ( V_18 , V_17 ) );
}
F_8 ( V_10 -> V_7 , L_4 , V_8 , V_24 ,
V_25 ) ;
return - V_38 ;
}
static int F_20 ( struct V_9 * V_10 , T_3 V_26 ,
T_4 * V_27 )
{
return F_16 ( V_10 ,
V_39 | V_40 ,
V_39 | V_40 ,
V_26 , V_27 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_9 * V_10 , T_2 * V_41 , T_5 V_42 )
{
T_1 V_29 ;
int V_21 , V_43 , V_4 = 0 ;
while ( V_4 < V_42 &&
F_20 ( V_10 ,
V_10 -> V_19 . V_44 ,
& V_10 -> V_19 . V_45 ) == 0 ) {
V_21 = F_12 ( V_2 , V_10 ) ;
if ( V_21 < 0 ) {
F_8 ( V_10 -> V_7 ,
L_5 , V_8 ,
V_21 ) ;
return - V_46 ;
}
V_43 = F_13 ( T_5 , V_21 , V_42 - V_4 ) ;
V_29 = F_1 ( V_2 , V_47 ,
V_43 , & V_41 [ V_4 ] ) ;
if ( V_29 < 0 ) {
F_8 ( V_10 -> V_7 ,
L_6 ,
V_8 , V_29 ) ;
return - V_46 ;
}
F_3 ( V_10 -> V_7 , L_7 , V_8 , V_43 ) ;
V_4 += V_43 ;
}
return V_4 ;
}
static int F_22 ( struct V_9 * V_10 , T_2 * V_41 , T_5 V_42 )
{
struct V_48 * V_7 = V_10 -> V_7 ;
struct V_1 * V_2 = F_7 ( V_7 ) ;
T_1 V_29 ;
int V_49 , V_6 , V_21 , V_50 , V_4 = 0 ;
if ( V_42 < V_51 ) {
F_11 ( V_10 ) ;
F_8 ( V_7 , L_8 , V_8 ) ;
return - V_46 ;
}
for ( V_50 = 0 ; V_50 < V_52 ; V_50 ++ ) {
if ( V_50 > 0 ) {
F_9 ( V_2 ,
V_53 ) ;
}
V_6 = F_20 (
V_10 , V_10 -> V_19 . V_44 , & V_10 -> V_19 . V_45 ) ;
if ( V_6 != 0 ) {
F_8 ( V_7 , L_9 , V_8 ) ;
V_4 = - V_38 ;
continue;
}
V_21 = F_12 ( V_2 , V_10 ) ;
if ( V_21 < 0 ) {
F_8 ( V_7 , L_10 , V_8 ) ;
V_4 = - V_46 ;
continue;
}
V_4 = F_21 ( V_2 , V_10 , V_41 ,
V_21 ) ;
if ( V_4 < V_51 ) {
F_8 ( V_7 , L_11 , V_8 ) ;
V_4 = - V_46 ;
continue;
}
V_49 = F_23 ( * ( V_54 * ) ( V_41 + 2 ) ) ;
if ( V_49 > V_42 ) {
F_8 ( V_7 , L_12 , V_8 ) ;
V_4 = - V_46 ;
continue;
}
V_29 = F_21 ( V_2 , V_10 , & V_41 [ V_4 ] ,
V_49 - V_4 ) ;
V_4 += V_29 ;
if ( V_29 < 0 || V_4 < V_49 ) {
F_8 ( V_7 , L_13 ,
V_8 ) ;
V_4 = - V_46 ;
continue;
}
if ( F_16 (
V_10 , V_40 | V_39 ,
V_40 , V_10 -> V_19 . V_44 ,
NULL ) ) {
F_8 ( V_7 , L_14 , V_8 ) ;
V_4 = - V_38 ;
continue;
}
break;
}
F_11 ( V_10 ) ;
F_3 ( V_10 -> V_7 , L_15 , V_8 , V_4 ) ;
return V_4 ;
}
static int F_24 ( struct V_9 * V_10 , T_2 * V_41 , T_5 V_55 )
{
struct V_48 * V_7 = V_10 -> V_7 ;
struct V_1 * V_2 = F_7 ( V_7 ) ;
T_3 V_56 ;
T_5 V_42 = 0 ;
int V_21 , V_57 , V_50 , V_29 = - V_46 ;
for ( V_50 = 0 ; V_50 < V_52 ; V_50 ++ ) {
F_11 ( V_10 ) ;
if ( F_16 ( V_10 , V_16 ,
V_16 ,
V_10 -> V_19 . V_58 , NULL ) ) {
F_8 ( V_7 , L_16 ,
V_8 ) ;
V_29 = - V_46 ;
continue;
}
V_29 = 0 ;
while ( V_42 < V_55 - 1 ) {
V_21 = F_12 ( V_2 ,
V_10 ) ;
if ( V_21 < 0 ) {
F_8 ( V_7 , L_17 ,
V_8 ) ;
V_29 = - V_46 ;
break;
}
V_57 = F_13 ( T_5 , V_21 ,
V_55 - 1 - V_42 ) ;
V_29 = F_4 ( V_2 , V_59 ,
V_57 , & V_41 [ V_42 ] ) ;
if ( V_29 < 0 ) {
F_8 ( V_7 , L_18 ,
V_8 ) ;
break;
}
F_3 ( V_7 , L_7 , V_8 , V_57 ) ;
V_42 += V_57 ;
V_29 = F_16 ( V_10 ,
V_40 |
V_60 ,
V_40 |
V_60 ,
V_10 -> V_19 . V_44 ,
NULL ) ;
if ( V_29 < 0 ) {
F_8 ( V_7 , L_19 ,
V_8 ) ;
V_29 = - V_38 ;
break;
}
}
if ( V_29 < 0 )
continue;
V_29 = F_4 ( V_2 , V_59 , 1 ,
& V_41 [ V_42 ] ) ;
if ( V_29 < 0 ) {
F_8 ( V_7 , L_20 ,
V_8 ) ;
V_29 = - V_46 ;
continue;
}
F_3 ( V_7 , L_21 , V_8 , V_41 [ V_42 ] ) ;
V_29 = F_16 ( V_10 ,
V_40 | V_60 ,
V_40 ,
V_10 -> V_19 . V_44 , NULL ) ;
if ( V_29 ) {
F_8 ( V_7 , L_22 ,
V_8 ) ;
V_29 = - V_38 ;
continue;
}
break;
}
if ( V_29 < 0 ) {
F_11 ( V_10 ) ;
return V_29 ;
}
V_29 = F_9 ( V_2 , V_61 ) ;
if ( V_29 < 0 ) {
F_8 ( V_7 , L_23 , V_8 ) ;
F_11 ( V_10 ) ;
return V_29 ;
}
V_56 = F_23 ( * ( ( V_54 * ) ( V_41 + 6 ) ) ) ;
V_29 = F_20 ( V_10 ,
F_25 ( V_10 ,
V_56 ) ,
& V_10 -> V_19 . V_45 ) ;
if ( V_29 ) {
F_8 ( V_7 , L_24 , V_8 ) ;
F_11 ( V_10 ) ;
return V_29 ;
}
F_3 ( V_7 , L_25 , V_8 , V_55 ) ;
return V_55 ;
}
static bool F_26 ( struct V_9 * V_10 , T_2 V_6 )
{
return ( V_6 == V_16 ) ;
}
static T_6 F_27 ( int V_62 , void * V_63 )
{
struct V_9 * V_10 = V_63 ;
struct V_30 * V_31 = V_10 -> V_19 . V_31 ;
V_31 -> V_33 ++ ;
F_28 ( & V_10 -> V_19 . V_45 ) ;
F_29 ( V_10 -> V_19 . V_28 ) ;
return V_64 ;
}
static int F_30 ( struct V_1 * V_2 , T_3 * V_65 )
{
static const T_2 V_66 [] = { 0x50 , 0x10 , 0xfe } ;
T_3 V_67 ;
T_1 V_29 ;
if ( ! F_31 ( V_2 -> V_68 , V_69 ) )
return - V_70 ;
V_29 = F_1 ( V_2 , V_71 , 4 , ( T_2 * ) & V_67 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( memcmp ( & V_67 , V_66 , sizeof( V_66 ) ) ) {
V_29 = F_1 ( V_2 , V_59 , 4 ,
( T_2 * ) ( & V_67 ) ) ;
if ( V_29 < 0 )
return V_29 ;
if ( memcmp ( & V_67 , V_66 ,
sizeof( V_66 ) ) )
return - V_70 ;
}
* V_65 = V_67 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_72 * V_73 )
{
int V_29 ;
struct V_9 * V_10 ;
struct V_48 * V_7 = & V_2 -> V_7 ;
T_3 V_74 = 0 ;
V_29 = F_30 ( V_2 , & V_74 ) ;
if ( V_29 )
return V_29 ;
F_33 ( V_7 , L_26 , ( V_75 ) V_74 ,
( T_2 ) ( V_74 >> 16 ) , ( T_2 ) ( V_74 >> 24 ) ) ;
V_10 = F_34 ( V_7 , & V_76 ) ;
if ( ! V_10 ) {
F_8 ( V_7 , L_27 , V_8 ) ;
return - V_70 ;
}
V_10 -> V_19 . V_31 = F_35 ( V_7 , sizeof( struct V_30 ) ,
V_77 ) ;
F_36 ( & V_10 -> V_19 . V_45 ) ;
F_36 ( & V_10 -> V_19 . V_78 ) ;
V_10 -> V_19 . V_79 = F_19 ( V_80 ) ;
V_10 -> V_19 . V_58 = F_19 ( V_81 ) ;
V_10 -> V_19 . V_44 = F_19 ( V_80 ) ;
V_10 -> V_19 . V_20 = F_19 ( V_80 ) ;
V_10 -> V_19 . V_28 = V_2 -> V_28 ;
if ( V_10 -> V_19 . V_28 ) {
F_3 ( V_7 , L_28 , V_8 ) ;
V_29 = F_37 ( V_7 , V_10 -> V_19 . V_28 ,
F_27 ,
V_82 ,
V_10 -> V_19 . V_83 . V_84 ,
V_10 ) ;
if ( V_29 ) {
F_8 ( V_7 , L_29 ,
V_8 , V_10 -> V_19 . V_28 ) ;
V_10 -> V_19 . V_28 = 0 ;
} else {
F_11 ( V_10 ) ;
V_29 = F_16 ( V_10 ,
V_16 ,
V_16 ,
V_10 -> V_19 . V_58 ,
NULL ) ;
if ( V_29 == 0 ) {
V_29 = F_4 ( V_2 ,
V_59 ,
1 , ( T_2 * ) ( & V_29 ) ) ;
if ( V_29 < 0 )
goto V_85;
F_11 ( V_10 ) ;
} else {
if ( F_6 ( V_10 ) !=
V_40 ) {
V_29 = - V_46 ;
goto V_85;
}
}
}
}
if ( F_38 ( V_10 ) ) {
V_29 = - V_70 ;
goto V_85;
}
if ( F_39 ( V_10 ) ) {
V_29 = - V_70 ;
goto V_85;
}
return 0 ;
V_85:
F_40 ( V_10 ) ;
F_41 ( V_10 -> V_7 ) ;
return V_29 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_48 * V_7 = & ( V_2 -> V_7 ) ;
struct V_9 * V_10 = F_43 ( V_7 ) ;
if ( V_10 )
F_40 ( V_10 ) ;
F_41 ( V_7 ) ;
F_44 ( V_10 ) ;
return 0 ;
}
