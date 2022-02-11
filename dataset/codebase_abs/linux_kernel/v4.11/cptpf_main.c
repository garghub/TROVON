static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 type , T_2 V_4 )
{
T_1 V_5 ;
T_3 V_6 = 100 ;
T_1 V_7 = 0 ;
struct V_8 * V_9 = & V_2 -> V_10 -> V_9 ;
if ( type == V_11 )
V_3 = ( V_3 << V_2 -> V_12 ) ;
V_7 = F_2 ( V_2 -> V_13 , F_3 ( 0 , V_4 ) ) ;
F_4 ( V_2 -> V_13 , F_3 ( 0 , V_4 ) ,
( V_7 & ~ V_3 ) ) ;
F_5 ( V_14 ) ;
V_4 = F_2 ( V_2 -> V_13 , F_6 ( 0 ) ) ;
while ( V_4 & V_3 ) {
F_7 ( V_9 , L_1 , V_3 ) ;
V_4 = F_2 ( V_2 -> V_13 ,
F_6 ( 0 ) ) ;
if ( V_6 -- )
break;
F_5 ( V_14 ) ;
}
V_5 = F_2 ( V_2 -> V_13 , F_8 ( 0 ) ) ;
F_4 ( V_2 -> V_13 , F_8 ( 0 ) ,
( V_5 & ~ V_3 ) ) ;
F_5 ( V_14 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 type )
{
T_1 V_5 ;
if ( type == V_11 )
V_3 = ( V_3 << V_2 -> V_12 ) ;
V_5 = F_2 ( V_2 -> V_13 , F_8 ( 0 ) ) ;
F_4 ( V_2 -> V_13 , F_8 ( 0 ) ,
( V_5 | V_3 ) ) ;
F_5 ( V_14 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_2 V_4 ,
T_1 V_3 , T_2 type )
{
T_1 V_15 = 0 ;
if ( type == V_11 )
V_3 = ( V_3 << V_2 -> V_12 ) ;
V_15 = F_2 ( V_2 -> V_13 , F_3 ( 0 , V_4 ) ) ;
F_4 ( V_2 -> V_13 , F_3 ( 0 , V_4 ) ,
( V_15 | V_3 ) ) ;
F_5 ( V_14 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_13 , F_12 ( 0 , 0 ) , ~ 0ull ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_13 , F_14 ( 0 ) , ~ 0ull ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_13 , F_16 ( 0 ) , ~ 0ull ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_13 ( V_2 ) ;
F_15 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_13 , F_19 ( 0 , 0 ) , ~ 0ull ) ;
}
static int F_20 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
int V_18 = 0 , V_19 = 0 , V_20 = 0 ;
T_3 V_21 = 0 ;
struct V_8 * V_9 = & V_2 -> V_10 -> V_9 ;
if ( ! V_17 || ! V_17 -> V_22 ) {
F_7 ( V_9 , L_2 ) ;
return - V_23 ;
}
if ( V_17 -> V_24 == 0 ) {
F_7 ( V_9 , L_3 ) ;
return - V_23 ;
}
if ( V_17 -> V_25 ) {
V_19 = V_26 ;
V_21 = V_27 ;
} else {
V_19 = 0 ;
V_21 = V_26 ;
}
for (; V_19 < V_21 ; V_19 ++ , V_20 ++ ) {
if ( V_17 -> V_28 & ( 1 << V_20 ) ) {
F_4 ( V_2 -> V_13 ,
F_21 ( 0 , V_19 ) ,
( T_1 ) V_17 -> V_29 ) ;
}
}
return V_18 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
int V_18 = 0 ;
struct V_8 * V_9 = & V_2 -> V_10 -> V_9 ;
V_2 -> V_30 &= ~ V_31 ;
F_17 ( V_2 ) ;
if ( V_17 -> V_25 ) {
if ( V_17 -> V_32 > V_2 -> V_33 ) {
F_7 ( V_9 , L_4 ) ;
V_18 = - V_23 ;
goto V_34;
}
if ( V_2 -> V_35 >= V_36 ) {
F_7 ( V_9 , L_5 ) ;
return - V_37 ;
}
V_17 -> V_38 = V_2 -> V_35 ;
V_17 -> V_28 = F_23 ( V_17 -> V_32 , 0 ) ;
F_1 ( V_2 , V_17 -> V_28 , V_11 ,
V_17 -> V_38 ) ;
V_18 = F_20 ( V_2 , V_17 ) ;
if ( V_18 ) {
F_7 ( V_9 , L_6 ,
V_17 -> V_39 ) ;
goto V_34;
}
V_2 -> V_35 ++ ;
F_10 ( V_2 , V_17 -> V_38 , V_17 -> V_28 ,
V_11 ) ;
F_9 ( V_2 , V_17 -> V_28 , V_11 ) ;
} else {
if ( V_17 -> V_32 > V_2 -> V_12 ) {
F_7 ( V_9 , L_7 ) ;
V_18 = - V_23 ;
goto V_34;
}
if ( V_2 -> V_35 >= V_36 ) {
F_7 ( V_9 , L_5 ) ;
return - V_37 ;
}
V_17 -> V_38 = V_2 -> V_35 ;
V_17 -> V_28 = F_23 ( V_17 -> V_32 , 0 ) ;
F_1 ( V_2 , V_17 -> V_28 , V_40 ,
V_17 -> V_38 ) ;
V_18 = F_20 ( V_2 , V_17 ) ;
if ( V_18 ) {
F_7 ( V_9 , L_6 ,
V_17 -> V_39 ) ;
goto V_34;
}
V_2 -> V_35 ++ ;
F_10 ( V_2 , V_17 -> V_38 , V_17 -> V_28 ,
V_40 ) ;
F_9 ( V_2 , V_17 -> V_28 , V_40 ) ;
}
F_18 ( V_2 ) ;
V_2 -> V_30 |= V_31 ;
return V_18 ;
V_34:
F_18 ( V_2 ) ;
return V_18 ;
}
static int F_24 ( struct V_1 * V_2 , const T_2 * V_41 , bool V_25 )
{
const struct V_42 * V_43 ;
struct V_8 * V_9 = & V_2 -> V_10 -> V_9 ;
struct V_44 * V_45 ;
struct V_16 * V_17 ;
int V_46 , V_18 = 0 ;
V_18 = F_25 ( & V_43 , V_41 , V_9 ) ;
if ( V_18 )
return V_18 ;
V_45 = (struct V_44 * ) V_43 -> V_47 ;
V_17 = & V_2 -> V_17 [ V_2 -> V_48 ] ;
memcpy ( V_17 -> V_39 , ( T_2 * ) V_43 -> V_47 , V_49 ) ;
V_17 -> V_24 = F_26 ( V_45 -> V_50 ) * 2 ;
if ( ! V_17 -> V_24 )
return - V_23 ;
V_17 -> V_25 = V_25 ;
V_17 -> V_28 = 0ULL ;
V_17 -> V_32 = V_25 ? 6 : 10 ;
V_17 -> V_22 = F_27 ( & V_2 -> V_10 -> V_9 , V_17 -> V_24 ,
& V_17 -> V_29 , V_51 ) ;
if ( ! V_17 -> V_22 ) {
F_7 ( V_9 , L_8 ) ;
return - V_52 ;
}
memcpy ( ( void * ) V_17 -> V_22 , ( void * ) ( V_43 -> V_47 + sizeof( * V_45 ) ) ,
V_17 -> V_24 ) ;
for ( V_46 = 0 ; V_46 < ( V_17 -> V_24 / 8 ) ; V_46 ++ )
( ( T_1 * ) V_17 -> V_22 ) [ V_46 ] = F_28 ( ( ( T_1 * ) V_17 -> V_22 ) [ V_46 ] ) ;
for ( V_46 = 0 ; V_46 < ( V_17 -> V_24 / 2 ) ; V_46 ++ )
( ( V_53 * ) V_17 -> V_22 ) [ V_46 ] = F_29 ( ( ( V_53 * ) V_17 -> V_22 ) [ V_46 ] ) ;
F_30 ( V_9 , L_9 , V_17 -> V_24 ) ;
F_30 ( V_9 , L_10 , V_17 -> V_25 ) ;
F_30 ( V_9 , L_11 , V_17 -> V_32 ) ;
F_30 ( V_9 , L_12 , ( T_1 ) V_17 -> V_22 ) ;
F_30 ( V_9 , L_13 , V_17 -> V_29 ) ;
V_18 = F_22 ( V_2 , V_17 ) ;
if ( V_18 ) {
F_7 ( V_9 , L_14 , V_18 ) ;
return V_18 ;
}
F_31 ( V_9 , L_15 , V_17 -> V_39 ) ;
V_17 -> V_54 = 1 ;
V_2 -> V_48 ++ ;
F_32 ( V_43 ) ;
return V_18 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_18 = 0 ;
struct V_8 * V_9 = & V_2 -> V_10 -> V_9 ;
V_18 = F_24 ( V_2 , L_16 , true ) ;
if ( V_18 ) {
F_7 ( V_9 , L_17 , V_18 ) ;
return V_18 ;
}
V_18 = F_24 ( V_2 , L_18 , false ) ;
if ( V_18 ) {
F_7 ( V_9 , L_19 , V_18 ) ;
return V_18 ;
}
return V_18 ;
}
static T_4 F_34 ( int V_55 , void * V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
F_35 ( V_2 , 0 ) ;
return V_57 ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_13 , F_37 ( 0 ) , 1 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
union V_58 V_59 = { 0 } ;
V_59 . V_60 = F_2 ( V_2 -> V_13 , F_39 ( 0 ) ) ;
V_2 -> V_12 = V_59 . V_61 . V_62 ;
V_2 -> V_33 = V_59 . V_61 . V_63 ;
}
static T_3 F_40 ( struct V_1 * V_2 )
{
union V_64 V_65 = { 0 } ;
V_65 . V_60 = F_2 ( V_2 -> V_13 ,
F_41 ( 0 ) ) ;
return V_65 . V_60 ;
}
static T_1 F_42 ( struct V_1 * V_2 )
{
union V_66 V_65 = { 0 } ;
V_65 . V_60 = F_2 ( V_2 -> V_13 ,
F_43 ( 0 ) ) ;
return V_65 . V_60 ;
}
static void F_44 ( struct V_1 * V_2 )
{
T_3 V_4 , V_6 = 100 ;
struct V_8 * V_9 = & V_2 -> V_10 -> V_9 ;
for ( V_4 = 0 ; V_4 < V_36 ; V_4 ++ ) {
F_4 ( V_2 -> V_13 , F_3 ( 0 , V_4 ) , 0 ) ;
F_5 ( V_14 ) ;
}
V_4 = F_2 ( V_2 -> V_13 , F_6 ( 0 ) ) ;
while ( V_4 ) {
F_7 ( V_9 , L_20 ) ;
V_4 = F_2 ( V_2 -> V_13 ,
F_6 ( 0 ) ) ;
if ( V_6 -- )
break;
F_5 ( V_14 ) ;
}
F_4 ( V_2 -> V_13 , F_8 ( 0 ) , 0 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
T_3 V_4 = 0 , V_19 ;
for ( V_4 = 0 ; V_4 < V_36 ; V_4 ++ ) {
struct V_16 * V_17 = & V_2 -> V_17 [ V_4 ] ;
if ( V_2 -> V_17 [ V_4 ] . V_22 )
F_46 ( & V_2 -> V_10 -> V_9 , V_17 -> V_24 ,
V_17 -> V_22 , V_17 -> V_29 ) ;
V_17 -> V_22 = NULL ;
}
for ( V_19 = 0 ; V_19 < V_27 ; V_19 ++ )
F_4 ( V_2 -> V_13 ,
F_21 ( 0 , V_19 ) , 0ull ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
T_1 V_67 ;
struct V_8 * V_9 = & V_2 -> V_10 -> V_9 ;
F_36 ( V_2 ) ;
F_48 ( 100 ) ;
V_67 = ( T_1 ) F_40 ( V_2 ) ;
if ( V_67 ) {
F_7 ( V_9 , L_21 , V_67 ) ;
return - V_68 ;
}
V_67 = F_42 ( V_2 ) ;
if ( V_67 ) {
F_7 ( V_9 , L_22 , V_67 ) ;
return - V_68 ;
}
F_38 ( V_2 ) ;
F_44 ( V_2 ) ;
V_2 -> V_48 = 0 ;
V_2 -> V_35 = 0 ;
V_2 -> V_30 |= V_31 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_8 * V_9 = & V_2 -> V_10 -> V_9 ;
V_18 = F_50 ( V_2 -> V_10 , V_69 ,
V_69 , V_70 ) ;
if ( V_18 < 0 ) {
F_7 ( & V_2 -> V_10 -> V_9 , L_23 ,
V_69 ) ;
return V_18 ;
}
V_18 = F_51 ( F_52 ( V_2 -> V_10 , F_53 ( 0 ) ) ,
F_34 , 0 , L_24 , V_2 ) ;
if ( V_18 )
goto V_71;
F_18 ( V_2 ) ;
return 0 ;
V_71:
F_7 ( V_9 , L_25 ) ;
F_54 ( V_2 -> V_10 ) ;
return V_18 ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_56 ( F_52 ( V_2 -> V_10 , F_53 ( 0 ) ) , V_2 ) ;
F_54 ( V_2 -> V_10 ) ;
}
static int F_57 ( struct V_1 * V_2 , int V_72 )
{
int V_73 = 0 ;
int V_74 ;
V_53 V_75 ;
struct V_76 * V_10 = V_2 -> V_10 ;
V_73 = F_58 ( V_10 , V_77 ) ;
if ( ! V_73 ) {
F_7 ( & V_10 -> V_9 , L_26 ) ;
return - V_68 ;
}
V_2 -> V_78 = V_72 ;
F_59 ( V_10 , ( V_73 + V_79 ) , & V_75 ) ;
if ( V_75 < V_2 -> V_78 )
V_2 -> V_78 = V_75 ;
if ( ! V_75 )
return 0 ;
V_74 = F_60 ( V_10 , V_2 -> V_78 ) ;
if ( V_74 ) {
F_7 ( & V_10 -> V_9 , L_27 ,
V_2 -> V_78 ) ;
V_2 -> V_78 = 0 ;
return V_74 ;
}
F_31 ( & V_10 -> V_9 , L_28 ,
V_2 -> V_78 ) ;
V_2 -> V_30 |= V_80 ;
return 0 ;
}
static int F_61 ( struct V_76 * V_10 , const struct V_81 * V_82 )
{
struct V_8 * V_9 = & V_10 -> V_9 ;
struct V_1 * V_2 ;
int V_74 ;
if ( V_72 > 16 || V_72 < 4 ) {
F_62 ( V_9 , L_29 ,
V_72 ) ;
V_72 = 4 ;
}
V_2 = F_63 ( V_9 , sizeof( * V_2 ) , V_51 ) ;
if ( ! V_2 )
return - V_52 ;
F_64 ( V_10 , V_2 ) ;
V_2 -> V_10 = V_10 ;
V_74 = F_65 ( V_10 ) ;
if ( V_74 ) {
F_7 ( V_9 , L_30 ) ;
F_64 ( V_10 , NULL ) ;
return V_74 ;
}
V_74 = F_66 ( V_10 , V_83 ) ;
if ( V_74 ) {
F_7 ( V_9 , L_31 , V_74 ) ;
goto V_84;
}
V_74 = F_67 ( V_10 , F_68 ( 48 ) ) ;
if ( V_74 ) {
F_7 ( V_9 , L_32 ) ;
goto V_85;
}
V_74 = F_69 ( V_10 , F_68 ( 48 ) ) ;
if ( V_74 ) {
F_7 ( V_9 , L_33 ) ;
goto V_85;
}
V_2 -> V_13 = F_70 ( V_10 , 0 , 0 ) ;
if ( ! V_2 -> V_13 ) {
F_7 ( V_9 , L_34 ) ;
V_74 = - V_52 ;
goto V_85;
}
F_47 ( V_2 ) ;
V_74 = F_49 ( V_2 ) ;
if ( V_74 )
goto V_85;
V_74 = F_33 ( V_2 ) ;
if ( V_74 )
goto V_86;
V_74 = F_57 ( V_2 , V_72 ) ;
if ( V_74 )
goto V_86;
return 0 ;
V_86:
F_55 ( V_2 ) ;
V_85:
F_71 ( V_10 ) ;
V_84:
F_72 ( V_10 ) ;
F_64 ( V_10 , NULL ) ;
return V_74 ;
}
static void F_73 ( struct V_76 * V_10 )
{
struct V_1 * V_2 = F_74 ( V_10 ) ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_55 ( V_2 ) ;
F_75 ( V_10 ) ;
F_71 ( V_10 ) ;
F_72 ( V_10 ) ;
F_64 ( V_10 , NULL ) ;
}
static void F_76 ( struct V_76 * V_10 )
{
struct V_1 * V_2 = F_74 ( V_10 ) ;
if ( ! V_2 )
return;
F_31 ( & V_10 -> V_9 , L_35 ,
( T_3 ) V_10 -> V_87 , ( T_3 ) V_10 -> V_8 ) ;
F_55 ( V_2 ) ;
F_71 ( V_10 ) ;
F_72 ( V_10 ) ;
F_64 ( V_10 , NULL ) ;
}
