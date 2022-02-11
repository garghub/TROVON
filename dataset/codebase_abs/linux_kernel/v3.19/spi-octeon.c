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
V_23 = V_14 -> V_23 ? : V_17 -> V_33 ;
V_22 = F_5 () / ( 2 * V_23 ) ;
V_19 . V_6 = 0 ;
V_19 . V_9 . V_22 = V_22 ;
V_19 . V_9 . V_34 = ( V_24 & V_35 ) ? 1 : 0 ;
V_19 . V_9 . V_36 = ( V_24 & V_37 ) ? 1 : 0 ;
V_19 . V_9 . V_38 = ( V_24 & V_39 ) ? 1 : 0 ;
V_19 . V_9 . V_40 = V_25 != V_26 ;
V_19 . V_9 . V_41 = V_25 ? 1 : 0 ;
V_19 . V_9 . V_42 = 1 ;
if ( V_17 -> V_43 < 4 )
V_2 -> V_44 |= 1ull << ( 12 + V_17 -> V_43 ) ;
V_19 . V_6 |= V_2 -> V_44 ;
if ( V_19 . V_6 != V_2 -> V_45 ) {
V_2 -> V_45 = V_19 . V_6 ;
F_6 ( V_2 -> V_7 + V_46 , V_19 . V_6 ) ;
}
V_27 = V_14 -> V_27 ;
V_28 = V_14 -> V_28 ;
V_29 = V_14 -> V_29 ;
while ( V_29 > V_47 ) {
for ( V_30 = 0 ; V_30 < V_47 ; V_30 ++ ) {
T_1 V_48 ;
if ( V_27 )
V_48 = * V_27 ++ ;
else
V_48 = 0 ;
F_6 ( V_2 -> V_7 + V_49 + ( 8 * V_30 ) , V_48 ) ;
}
V_21 . V_6 = 0 ;
V_21 . V_9 . V_50 = V_17 -> V_43 ;
V_21 . V_9 . V_51 = 1 ;
V_21 . V_9 . V_52 = V_27 ? V_47 : 0 ;
V_21 . V_9 . V_53 = V_47 ;
F_6 ( V_2 -> V_7 + V_54 , V_21 . V_6 ) ;
F_1 ( V_2 ) ;
if ( V_28 )
for ( V_30 = 0 ; V_30 < V_47 ; V_30 ++ ) {
V_6 V_55 = F_3 ( V_2 -> V_7 + V_49 + ( 8 * V_30 ) ) ;
* V_28 ++ = ( T_1 ) V_55 ;
}
V_29 -= V_47 ;
}
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
T_1 V_48 ;
if ( V_27 )
V_48 = * V_27 ++ ;
else
V_48 = 0 ;
F_6 ( V_2 -> V_7 + V_49 + ( 8 * V_30 ) , V_48 ) ;
}
V_21 . V_6 = 0 ;
V_21 . V_9 . V_50 = V_17 -> V_43 ;
if ( V_15 )
V_21 . V_9 . V_51 = V_14 -> V_56 ;
else
V_21 . V_9 . V_51 = ! V_14 -> V_56 ;
V_21 . V_9 . V_52 = V_27 ? V_29 : 0 ;
V_21 . V_9 . V_53 = V_29 ;
F_6 ( V_2 -> V_7 + V_54 , V_21 . V_6 ) ;
F_1 ( V_2 ) ;
if ( V_28 )
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
V_6 V_55 = F_3 ( V_2 -> V_7 + V_49 + ( 8 * V_30 ) ) ;
* V_28 ++ = ( T_1 ) V_55 ;
}
if ( V_14 -> V_57 )
F_7 ( V_14 -> V_57 ) ;
return V_14 -> V_29 ;
}
static int F_8 ( struct V_58 * V_59 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_9 ( V_59 ) ;
unsigned int V_60 = 0 ;
int V_61 = 0 ;
struct V_13 * V_14 ;
F_10 (xfer, &msg->transfers, transfer_list) {
bool V_15 = F_11 ( & V_14 -> V_62 ,
& V_12 -> V_63 ) ;
int V_64 = F_4 ( V_2 , V_12 , V_14 , V_15 ) ;
if ( V_64 < 0 ) {
V_61 = V_64 ;
goto V_65;
}
V_60 += V_64 ;
}
V_65:
V_12 -> V_61 = V_61 ;
V_12 -> V_66 = V_60 ;
F_12 ( V_59 ) ;
return V_61 ;
}
static int F_13 ( struct V_67 * V_68 )
{
struct V_69 * V_70 ;
struct V_58 * V_59 ;
struct V_1 * V_2 ;
int V_65 = - V_71 ;
V_59 = F_14 ( & V_68 -> V_72 , sizeof( struct V_1 ) ) ;
if ( ! V_59 )
return - V_73 ;
V_2 = F_9 ( V_59 ) ;
F_15 ( V_68 , V_59 ) ;
V_70 = F_16 ( V_68 , V_74 , 0 ) ;
if ( V_70 == NULL ) {
F_17 ( & V_68 -> V_72 , L_1 ) ;
V_65 = - V_75 ;
goto V_76;
}
if ( ! F_18 ( & V_68 -> V_72 , V_70 -> V_77 ,
F_19 ( V_70 ) , V_70 -> V_78 ) ) {
F_17 ( & V_68 -> V_72 , L_2 ) ;
goto V_76;
}
V_2 -> V_7 = ( V_6 ) F_20 ( & V_68 -> V_72 , V_70 -> V_77 ,
F_19 ( V_70 ) ) ;
V_59 -> V_79 = 4 ;
V_59 -> V_80 = V_31 |
V_32 |
V_35 |
V_37 |
V_39 ;
V_59 -> V_81 = F_8 ;
V_59 -> V_82 = F_21 ( 8 ) ;
V_59 -> V_33 = V_83 ;
V_59 -> V_72 . V_84 = V_68 -> V_72 . V_84 ;
V_65 = F_22 ( & V_68 -> V_72 , V_59 ) ;
if ( V_65 ) {
F_17 ( & V_68 -> V_72 , L_3 , V_65 ) ;
goto V_76;
}
F_23 ( & V_68 -> V_72 , L_4 ) ;
return 0 ;
V_76:
F_24 ( V_59 ) ;
return V_65 ;
}
static int F_25 ( struct V_67 * V_68 )
{
struct V_58 * V_59 = F_26 ( V_68 ) ;
struct V_1 * V_2 = F_9 ( V_59 ) ;
V_6 V_7 = V_2 -> V_7 ;
F_6 ( V_7 + V_46 , 0 ) ;
return 0 ;
}
