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
int V_25 ;
const T_1 * V_26 ;
T_1 * V_27 ;
int V_28 ;
int V_29 ;
struct V_30 * V_31 = F_5 ( V_12 -> V_32 ) ;
V_21 = V_31 -> V_33 ;
V_22 = V_31 -> V_22 ;
V_23 = V_22 & V_34 ;
V_24 = V_22 & V_35 ;
V_25 = V_31 -> V_25 ;
if ( V_14 -> V_21 )
V_21 = V_14 -> V_21 ;
if ( V_14 -> V_25 )
V_25 = V_14 -> V_25 ;
if ( V_21 > V_36 )
V_21 = V_36 ;
V_20 = F_6 () / ( 2 * V_21 ) ;
V_17 . V_6 = 0 ;
V_17 . V_9 . V_20 = V_20 ;
V_17 . V_9 . V_37 = ( V_22 & V_38 ) ? 1 : 0 ;
V_17 . V_9 . V_39 = ( V_22 & V_40 ) ? 1 : 0 ;
V_17 . V_9 . V_41 = ( V_22 & V_42 ) ? 1 : 0 ;
V_17 . V_9 . V_43 = V_23 != V_24 ;
V_17 . V_9 . V_44 = V_23 ? 1 : 0 ;
V_17 . V_9 . V_45 = 1 ;
if ( V_31 -> V_46 < 4 )
V_2 -> V_47 |= 1ull << ( 12 + V_31 -> V_46 ) ;
V_17 . V_6 |= V_2 -> V_47 ;
if ( V_17 . V_6 != V_2 -> V_48 ) {
V_2 -> V_48 = V_17 . V_6 ;
F_7 ( V_2 -> V_7 + V_49 , V_17 . V_6 ) ;
}
V_26 = V_14 -> V_26 ;
V_27 = V_14 -> V_27 ;
V_28 = V_14 -> V_28 ;
while ( V_28 > V_50 ) {
for ( V_29 = 0 ; V_29 < V_50 ; V_29 ++ ) {
T_1 V_51 ;
if ( V_26 )
V_51 = * V_26 ++ ;
else
V_51 = 0 ;
F_7 ( V_2 -> V_7 + V_52 + ( 8 * V_29 ) , V_51 ) ;
}
V_19 . V_6 = 0 ;
V_19 . V_9 . V_53 = V_31 -> V_46 ;
V_19 . V_9 . V_54 = 1 ;
V_19 . V_9 . V_55 = V_26 ? V_50 : 0 ;
V_19 . V_9 . V_56 = V_50 ;
F_7 ( V_2 -> V_7 + V_57 , V_19 . V_6 ) ;
F_1 ( V_2 ) ;
if ( V_27 )
for ( V_29 = 0 ; V_29 < V_50 ; V_29 ++ ) {
V_6 V_58 = F_3 ( V_2 -> V_7 + V_52 + ( 8 * V_29 ) ) ;
* V_27 ++ = ( T_1 ) V_58 ;
}
V_28 -= V_50 ;
}
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ ) {
T_1 V_51 ;
if ( V_26 )
V_51 = * V_26 ++ ;
else
V_51 = 0 ;
F_7 ( V_2 -> V_7 + V_52 + ( 8 * V_29 ) , V_51 ) ;
}
V_19 . V_6 = 0 ;
V_19 . V_9 . V_53 = V_31 -> V_46 ;
if ( V_15 )
V_19 . V_9 . V_54 = V_14 -> V_59 ;
else
V_19 . V_9 . V_54 = ! V_14 -> V_59 ;
V_19 . V_9 . V_55 = V_26 ? V_28 : 0 ;
V_19 . V_9 . V_56 = V_28 ;
F_7 ( V_2 -> V_7 + V_57 , V_19 . V_6 ) ;
F_1 ( V_2 ) ;
if ( V_27 )
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ ) {
V_6 V_58 = F_3 ( V_2 -> V_7 + V_52 + ( 8 * V_29 ) ) ;
* V_27 ++ = ( T_1 ) V_58 ;
}
if ( V_14 -> V_60 )
F_8 ( V_14 -> V_60 ) ;
return V_14 -> V_28 ;
}
static int F_9 ( struct V_61 * V_32 , T_2 V_62 )
{
switch ( V_62 ) {
case 8 :
break;
default:
F_10 ( & V_32 -> V_63 , L_1 ,
V_62 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_11 ( struct V_65 * V_66 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_66 ) ;
unsigned int V_67 = 0 ;
int V_68 = 0 ;
struct V_13 * V_14 ;
if ( F_5 ( V_12 -> V_32 ) == NULL ) {
V_68 = - V_64 ;
goto V_69;
}
F_13 (xfer, &msg->transfers, transfer_list) {
if ( V_14 -> V_25 ) {
V_68 = F_9 ( V_12 -> V_32 ,
V_14 -> V_25 ) ;
if ( V_68 )
goto V_69;
}
}
F_13 (xfer, &msg->transfers, transfer_list) {
bool V_15 = & V_14 -> V_70 == V_12 -> V_71 . V_72 ;
int V_73 = F_4 ( V_2 , V_12 , V_14 , V_15 ) ;
if ( V_73 < 0 ) {
V_68 = V_73 ;
goto V_69;
}
V_67 += V_73 ;
}
V_69:
V_12 -> V_68 = V_68 ;
V_12 -> V_74 = V_67 ;
F_14 ( V_66 ) ;
return V_68 ;
}
static struct V_30 * F_15 ( struct V_61 * V_32 )
{
struct V_30 * V_75 = F_16 ( sizeof( * V_75 ) , V_76 ) ;
if ( ! V_75 )
return NULL ;
V_75 -> V_33 = V_32 -> V_33 ;
V_75 -> V_46 = V_32 -> V_46 ;
V_75 -> V_22 = V_32 -> V_22 ;
V_75 -> V_25 = V_32 -> V_25 ;
return V_75 ;
}
static int V_30 ( struct V_61 * V_32 )
{
int V_73 ;
struct V_30 * V_77 ;
struct V_30 * V_78 = F_5 ( V_32 ) ;
V_73 = F_9 ( V_32 , V_32 -> V_25 ) ;
if ( V_73 )
return V_73 ;
V_77 = F_15 ( V_32 ) ;
if ( ! V_77 )
return - V_79 ;
F_17 ( V_32 , V_77 ) ;
F_18 ( V_78 ) ;
return 0 ;
}
static void F_19 ( struct V_61 * V_32 )
{
struct V_30 * V_78 = F_5 ( V_32 ) ;
F_17 ( V_32 , NULL ) ;
F_18 ( V_78 ) ;
}
static int F_20 ( struct V_65 * V_66 )
{
return 0 ;
}
static int T_3 F_21 ( struct V_80 * V_81 )
{
struct V_82 * V_83 ;
struct V_65 * V_66 ;
struct V_1 * V_2 ;
int V_69 = - V_84 ;
V_66 = F_22 ( & V_81 -> V_63 , sizeof( struct V_1 ) ) ;
if ( ! V_66 )
return - V_79 ;
V_2 = F_12 ( V_66 ) ;
F_23 ( V_81 , V_2 ) ;
V_2 -> V_85 = V_66 ;
V_83 = F_24 ( V_81 , V_86 , 0 ) ;
if ( V_83 == NULL ) {
F_10 ( & V_81 -> V_63 , L_2 ) ;
V_69 = - V_87 ;
goto V_88;
}
if ( ! F_25 ( & V_81 -> V_63 , V_83 -> V_89 ,
F_26 ( V_83 ) , V_83 -> V_90 ) ) {
F_10 ( & V_81 -> V_63 , L_3 ) ;
goto V_88;
}
V_2 -> V_7 = ( V_6 ) F_27 ( & V_81 -> V_63 , V_83 -> V_89 ,
F_26 ( V_83 ) ) ;
V_66 -> V_91 = - 1 ;
V_66 -> V_92 = 4 ;
V_66 -> V_93 = V_34 |
V_35 |
V_38 |
V_40 |
V_42 ;
V_66 -> V_75 = V_30 ;
V_66 -> V_94 = F_19 ;
V_66 -> V_95 = F_20 ;
V_66 -> V_96 = F_11 ;
V_66 -> V_97 = F_20 ;
V_66 -> V_63 . V_98 = V_81 -> V_63 . V_98 ;
V_69 = F_28 ( V_66 ) ;
if ( V_69 ) {
F_10 ( & V_81 -> V_63 , L_4 , V_69 ) ;
goto V_88;
}
F_29 ( & V_81 -> V_63 , L_5 ) ;
return 0 ;
V_88:
F_30 ( V_66 ) ;
return V_69 ;
}
static int T_4 F_31 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_32 ( V_81 ) ;
V_6 V_7 = V_2 -> V_7 ;
F_33 ( V_2 -> V_85 ) ;
F_7 ( V_7 + V_49 , 0 ) ;
return 0 ;
}
