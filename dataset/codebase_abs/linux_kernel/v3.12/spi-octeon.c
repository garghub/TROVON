static void F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
unsigned int V_5 = 0 ;
do {
if ( V_5 ++ )
F_2 ( 500 ) ;
V_4 . V_6 = F_3 ( V_2 -> V_7 + V_8 ) ;
} while ( V_4 . V_9 . V_10 );
}
static int F_4 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
bool V_15 )
{
union V_16 V_17 ;
union V_18 V_19 ;
unsigned int V_20 ;
unsigned int V_21 ;
int V_22 ;
bool V_23 , V_24 ;
const T_1 * V_25 ;
T_1 * V_26 ;
int V_27 ;
int V_28 ;
struct V_29 * V_30 = F_5 ( V_12 -> V_31 ) ;
V_21 = V_30 -> V_32 ;
V_22 = V_30 -> V_22 ;
V_23 = V_22 & V_33 ;
V_24 = V_22 & V_34 ;
if ( V_14 -> V_21 )
V_21 = V_14 -> V_21 ;
if ( V_21 > V_35 )
V_21 = V_35 ;
V_20 = F_6 () / ( 2 * V_21 ) ;
V_17 . V_6 = 0 ;
V_17 . V_9 . V_20 = V_20 ;
V_17 . V_9 . V_36 = ( V_22 & V_37 ) ? 1 : 0 ;
V_17 . V_9 . V_38 = ( V_22 & V_39 ) ? 1 : 0 ;
V_17 . V_9 . V_40 = ( V_22 & V_41 ) ? 1 : 0 ;
V_17 . V_9 . V_42 = V_23 != V_24 ;
V_17 . V_9 . V_43 = V_23 ? 1 : 0 ;
V_17 . V_9 . V_44 = 1 ;
if ( V_30 -> V_45 < 4 )
V_2 -> V_46 |= 1ull << ( 12 + V_30 -> V_45 ) ;
V_17 . V_6 |= V_2 -> V_46 ;
if ( V_17 . V_6 != V_2 -> V_47 ) {
V_2 -> V_47 = V_17 . V_6 ;
F_7 ( V_2 -> V_7 + V_48 , V_17 . V_6 ) ;
}
V_25 = V_14 -> V_25 ;
V_26 = V_14 -> V_26 ;
V_27 = V_14 -> V_27 ;
while ( V_27 > V_49 ) {
for ( V_28 = 0 ; V_28 < V_49 ; V_28 ++ ) {
T_1 V_50 ;
if ( V_25 )
V_50 = * V_25 ++ ;
else
V_50 = 0 ;
F_7 ( V_2 -> V_7 + V_51 + ( 8 * V_28 ) , V_50 ) ;
}
V_19 . V_6 = 0 ;
V_19 . V_9 . V_52 = V_30 -> V_45 ;
V_19 . V_9 . V_53 = 1 ;
V_19 . V_9 . V_54 = V_25 ? V_49 : 0 ;
V_19 . V_9 . V_55 = V_49 ;
F_7 ( V_2 -> V_7 + V_56 , V_19 . V_6 ) ;
F_1 ( V_2 ) ;
if ( V_26 )
for ( V_28 = 0 ; V_28 < V_49 ; V_28 ++ ) {
V_6 V_57 = F_3 ( V_2 -> V_7 + V_51 + ( 8 * V_28 ) ) ;
* V_26 ++ = ( T_1 ) V_57 ;
}
V_27 -= V_49 ;
}
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ ) {
T_1 V_50 ;
if ( V_25 )
V_50 = * V_25 ++ ;
else
V_50 = 0 ;
F_7 ( V_2 -> V_7 + V_51 + ( 8 * V_28 ) , V_50 ) ;
}
V_19 . V_6 = 0 ;
V_19 . V_9 . V_52 = V_30 -> V_45 ;
if ( V_15 )
V_19 . V_9 . V_53 = V_14 -> V_58 ;
else
V_19 . V_9 . V_53 = ! V_14 -> V_58 ;
V_19 . V_9 . V_54 = V_25 ? V_27 : 0 ;
V_19 . V_9 . V_55 = V_27 ;
F_7 ( V_2 -> V_7 + V_56 , V_19 . V_6 ) ;
F_1 ( V_2 ) ;
if ( V_26 )
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ ) {
V_6 V_57 = F_3 ( V_2 -> V_7 + V_51 + ( 8 * V_28 ) ) ;
* V_26 ++ = ( T_1 ) V_57 ;
}
if ( V_14 -> V_59 )
F_8 ( V_14 -> V_59 ) ;
return V_14 -> V_27 ;
}
static int F_9 ( struct V_60 * V_61 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_10 ( V_61 ) ;
unsigned int V_62 = 0 ;
int V_63 = 0 ;
struct V_13 * V_14 ;
if ( F_5 ( V_12 -> V_31 ) == NULL ) {
V_63 = - V_64 ;
goto V_65;
}
F_11 (xfer, &msg->transfers, transfer_list) {
bool V_15 = & V_14 -> V_66 == V_12 -> V_67 . V_68 ;
int V_69 = F_4 ( V_2 , V_12 , V_14 , V_15 ) ;
if ( V_69 < 0 ) {
V_63 = V_69 ;
goto V_65;
}
V_62 += V_69 ;
}
V_65:
V_12 -> V_63 = V_63 ;
V_12 -> V_70 = V_62 ;
F_12 ( V_61 ) ;
return V_63 ;
}
static struct V_29 * F_13 ( struct V_71 * V_31 )
{
struct V_29 * V_72 = F_14 ( sizeof( * V_72 ) , V_73 ) ;
if ( ! V_72 )
return NULL ;
V_72 -> V_32 = V_31 -> V_32 ;
V_72 -> V_45 = V_31 -> V_45 ;
V_72 -> V_22 = V_31 -> V_22 ;
V_72 -> V_74 = V_31 -> V_74 ;
return V_72 ;
}
static int V_29 ( struct V_71 * V_31 )
{
struct V_29 * V_75 ;
struct V_29 * V_76 = F_5 ( V_31 ) ;
V_75 = F_13 ( V_31 ) ;
if ( ! V_75 )
return - V_77 ;
F_15 ( V_31 , V_75 ) ;
F_16 ( V_76 ) ;
return 0 ;
}
static void F_17 ( struct V_71 * V_31 )
{
struct V_29 * V_76 = F_5 ( V_31 ) ;
F_15 ( V_31 , NULL ) ;
F_16 ( V_76 ) ;
}
static int F_18 ( struct V_78 * V_79 )
{
struct V_80 * V_81 ;
struct V_60 * V_61 ;
struct V_1 * V_2 ;
int V_65 = - V_82 ;
V_61 = F_19 ( & V_79 -> V_83 , sizeof( struct V_1 ) ) ;
if ( ! V_61 )
return - V_77 ;
V_2 = F_10 ( V_61 ) ;
F_20 ( V_79 , V_61 ) ;
V_81 = F_21 ( V_79 , V_84 , 0 ) ;
if ( V_81 == NULL ) {
F_22 ( & V_79 -> V_83 , L_1 ) ;
V_65 = - V_85 ;
goto V_86;
}
if ( ! F_23 ( & V_79 -> V_83 , V_81 -> V_87 ,
F_24 ( V_81 ) , V_81 -> V_88 ) ) {
F_22 ( & V_79 -> V_83 , L_2 ) ;
goto V_86;
}
V_2 -> V_7 = ( V_6 ) F_25 ( & V_79 -> V_83 , V_81 -> V_87 ,
F_24 ( V_81 ) ) ;
V_61 -> V_89 = - 1 ;
V_61 -> V_90 = 4 ;
V_61 -> V_91 = V_33 |
V_34 |
V_37 |
V_39 |
V_41 ;
V_61 -> V_72 = V_29 ;
V_61 -> V_92 = F_17 ;
V_61 -> V_93 = F_9 ;
V_61 -> V_94 = F_26 ( 8 ) ;
V_61 -> V_83 . V_95 = V_79 -> V_83 . V_95 ;
V_65 = F_27 ( V_61 ) ;
if ( V_65 ) {
F_22 ( & V_79 -> V_83 , L_3 , V_65 ) ;
goto V_86;
}
F_28 ( & V_79 -> V_83 , L_4 ) ;
return 0 ;
V_86:
F_29 ( V_61 ) ;
return V_65 ;
}
static int F_30 ( struct V_78 * V_79 )
{
struct V_60 * V_61 = F_31 ( V_79 ) ;
struct V_1 * V_2 = F_10 ( V_61 ) ;
V_6 V_7 = V_2 -> V_7 ;
F_32 ( V_61 ) ;
F_7 ( V_7 + V_48 , 0 ) ;
return 0 ;
}
