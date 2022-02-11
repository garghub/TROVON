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
struct V_16 * V_17 = V_12 -> V_17 ;
union V_18 V_19 ;
union V_20 V_21 ;
unsigned int V_22 ;
unsigned int V_23 ;
int V_24 ;
bool V_25 , V_26 ;
const T_1 * V_27 ;
T_1 * V_28 ;
int V_29 ;
int V_30 ;
V_24 = V_17 -> V_24 ;
V_25 = V_24 & V_31 ;
V_26 = V_24 & V_32 ;
V_23 = V_14 -> V_23 ;
V_22 = F_5 () / ( 2 * V_23 ) ;
V_19 . V_6 = 0 ;
V_19 . V_9 . V_22 = V_22 ;
V_19 . V_9 . V_33 = ( V_24 & V_34 ) ? 1 : 0 ;
V_19 . V_9 . V_35 = ( V_24 & V_36 ) ? 1 : 0 ;
V_19 . V_9 . V_37 = ( V_24 & V_38 ) ? 1 : 0 ;
V_19 . V_9 . V_39 = V_25 != V_26 ;
V_19 . V_9 . V_40 = V_25 ? 1 : 0 ;
V_19 . V_9 . V_41 = 1 ;
if ( V_17 -> V_42 < 4 )
V_2 -> V_43 |= 1ull << ( 12 + V_17 -> V_42 ) ;
V_19 . V_6 |= V_2 -> V_43 ;
if ( V_19 . V_6 != V_2 -> V_44 ) {
V_2 -> V_44 = V_19 . V_6 ;
F_6 ( V_2 -> V_7 + V_45 , V_19 . V_6 ) ;
}
V_27 = V_14 -> V_27 ;
V_28 = V_14 -> V_28 ;
V_29 = V_14 -> V_29 ;
while ( V_29 > V_46 ) {
for ( V_30 = 0 ; V_30 < V_46 ; V_30 ++ ) {
T_1 V_47 ;
if ( V_27 )
V_47 = * V_27 ++ ;
else
V_47 = 0 ;
F_6 ( V_2 -> V_7 + V_48 + ( 8 * V_30 ) , V_47 ) ;
}
V_21 . V_6 = 0 ;
V_21 . V_9 . V_49 = V_17 -> V_42 ;
V_21 . V_9 . V_50 = 1 ;
V_21 . V_9 . V_51 = V_27 ? V_46 : 0 ;
V_21 . V_9 . V_52 = V_46 ;
F_6 ( V_2 -> V_7 + V_53 , V_21 . V_6 ) ;
F_1 ( V_2 ) ;
if ( V_28 )
for ( V_30 = 0 ; V_30 < V_46 ; V_30 ++ ) {
V_6 V_54 = F_3 ( V_2 -> V_7 + V_48 + ( 8 * V_30 ) ) ;
* V_28 ++ = ( T_1 ) V_54 ;
}
V_29 -= V_46 ;
}
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
T_1 V_47 ;
if ( V_27 )
V_47 = * V_27 ++ ;
else
V_47 = 0 ;
F_6 ( V_2 -> V_7 + V_48 + ( 8 * V_30 ) , V_47 ) ;
}
V_21 . V_6 = 0 ;
V_21 . V_9 . V_49 = V_17 -> V_42 ;
if ( V_15 )
V_21 . V_9 . V_50 = V_14 -> V_55 ;
else
V_21 . V_9 . V_50 = ! V_14 -> V_55 ;
V_21 . V_9 . V_51 = V_27 ? V_29 : 0 ;
V_21 . V_9 . V_52 = V_29 ;
F_6 ( V_2 -> V_7 + V_53 , V_21 . V_6 ) ;
F_1 ( V_2 ) ;
if ( V_28 )
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
V_6 V_54 = F_3 ( V_2 -> V_7 + V_48 + ( 8 * V_30 ) ) ;
* V_28 ++ = ( T_1 ) V_54 ;
}
if ( V_14 -> V_56 )
F_7 ( V_14 -> V_56 ) ;
return V_14 -> V_29 ;
}
static int F_8 ( struct V_57 * V_58 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_9 ( V_58 ) ;
unsigned int V_59 = 0 ;
int V_60 = 0 ;
struct V_13 * V_14 ;
F_10 (xfer, &msg->transfers, transfer_list) {
bool V_15 = F_11 ( & V_14 -> V_61 ,
& V_12 -> V_62 ) ;
int V_63 = F_4 ( V_2 , V_12 , V_14 , V_15 ) ;
if ( V_63 < 0 ) {
V_60 = V_63 ;
goto V_64;
}
V_59 += V_63 ;
}
V_64:
V_12 -> V_60 = V_60 ;
V_12 -> V_65 = V_59 ;
F_12 ( V_58 ) ;
return V_60 ;
}
static int F_13 ( struct V_66 * V_67 )
{
struct V_68 * V_69 ;
void T_2 * V_70 ;
struct V_57 * V_58 ;
struct V_1 * V_2 ;
int V_64 = - V_71 ;
V_58 = F_14 ( & V_67 -> V_72 , sizeof( struct V_1 ) ) ;
if ( ! V_58 )
return - V_73 ;
V_2 = F_9 ( V_58 ) ;
F_15 ( V_67 , V_58 ) ;
V_69 = F_16 ( V_67 , V_74 , 0 ) ;
V_70 = F_17 ( & V_67 -> V_72 , V_69 ) ;
if ( F_18 ( V_70 ) ) {
V_64 = F_19 ( V_70 ) ;
goto V_75;
}
V_2 -> V_7 = ( V_6 ) V_70 ;
V_58 -> V_76 = 4 ;
V_58 -> V_77 = V_31 |
V_32 |
V_34 |
V_36 |
V_38 ;
V_58 -> V_78 = F_8 ;
V_58 -> V_79 = F_20 ( 8 ) ;
V_58 -> V_80 = V_81 ;
V_58 -> V_72 . V_82 = V_67 -> V_72 . V_82 ;
V_64 = F_21 ( & V_67 -> V_72 , V_58 ) ;
if ( V_64 ) {
F_22 ( & V_67 -> V_72 , L_1 , V_64 ) ;
goto V_75;
}
F_23 ( & V_67 -> V_72 , L_2 ) ;
return 0 ;
V_75:
F_24 ( V_58 ) ;
return V_64 ;
}
static int F_25 ( struct V_66 * V_67 )
{
struct V_57 * V_58 = F_26 ( V_67 ) ;
struct V_1 * V_2 = F_9 ( V_58 ) ;
V_6 V_7 = V_2 -> V_7 ;
F_6 ( V_7 + V_45 , 0 ) ;
return 0 ;
}
