static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 -> V_4 , V_2 -> V_5 , 0 , & V_3 ) ;
return V_3 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_6 )
{
F_2 ( V_2 -> V_4 , V_2 -> V_7 , V_6 << ( 32 - V_2 -> V_8 ) , NULL ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_12 )
{
int V_13 ;
if ( V_2 -> V_8 <= 8 ) {
T_2 * V_14 = V_12 -> V_15 ;
const T_2 * V_16 = V_12 -> V_17 ;
for ( V_13 = 0 ; V_13 < V_12 -> V_18 ; V_13 += 1 ) {
if ( V_12 -> V_17 )
F_3 ( V_2 , * V_16 ++ ) ;
if ( V_12 -> V_15 )
* V_14 ++ = F_1 ( V_2 ) ;
}
} else if ( V_2 -> V_8 <= 16 ) {
T_3 * V_14 = V_12 -> V_15 ;
const T_3 * V_16 = V_12 -> V_17 ;
for ( V_13 = 0 ; V_13 < V_12 -> V_18 ; V_13 += 2 ) {
if ( V_12 -> V_17 )
F_3 ( V_2 , * V_16 ++ ) ;
if ( V_12 -> V_15 )
* V_14 ++ = F_1 ( V_2 ) ;
}
} else {
T_1 * V_14 = V_12 -> V_15 ;
const T_1 * V_16 = V_12 -> V_17 ;
for ( V_13 = 0 ; V_13 < V_12 -> V_18 ; V_13 += 4 ) {
if ( V_12 -> V_17 )
F_3 ( V_2 , * V_16 ++ ) ;
if ( V_12 -> V_15 )
* V_14 ++ = F_1 ( V_2 ) ;
}
}
V_10 -> V_19 += V_13 ;
F_5 ( & V_10 -> V_20 -> V_4 , L_1 ,
V_12 -> V_17 ? L_2 : L_3 , V_12 -> V_15 ? L_4 : L_3 , V_12 -> V_18 ,
V_2 -> V_8 , V_13 , ( V_13 < V_12 -> V_18 ) ? L_5 : L_3 ) ;
return ( V_13 < V_12 -> V_18 ) ? - V_21 : 0 ;
}
static void F_6 ( struct V_1 * V_2 , int V_22 )
{
V_22 = ! ! V_22 ;
if ( V_22 == V_2 -> V_22 )
return;
F_2 ( V_2 -> V_4 , V_22 ? V_2 -> V_23 : V_2 -> V_24 , 0 , NULL ) ;
V_2 -> V_22 = V_22 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_8 , T_2 V_25 )
{
int error , V_26 = 0 ;
T_1 V_27 [ 16 ] ;
T_1 V_28 , V_29 , V_30 ;
T_1 V_31 , V_32 ;
V_25 &= V_33 ;
if ( V_25 == V_2 -> V_25 && V_8 == V_2 -> V_8 )
return 0 ;
V_28 = ( V_25 & V_34 ) ? V_35 : V_36 ;
V_29 = ( V_25 & V_34 ) ? V_36 : V_35 ;
V_30 = ( V_25 & V_37 ) ? V_38 : V_39 ;
V_2 -> V_24 = V_26 ;
V_27 [ V_26 ++ ] = V_40 | V_41 | V_29 | V_30 ;
V_27 [ V_26 ++ ] = V_42 | V_41 | V_29 | V_30 ;
V_2 -> V_23 = V_26 ;
V_27 [ V_26 ++ ] = V_40 | V_41 | V_28 | V_30 ;
V_27 [ V_26 ++ ] = V_42 | V_41 | V_28 | V_30 ;
V_31 = ( V_8 > 16 ) ? 16 : V_8 ;
V_32 = V_8 - V_31 ;
V_2 -> V_7 = V_26 ;
V_27 [ V_26 ++ ] = F_8 ( V_31 ) | V_43 ;
if ( V_32 )
V_27 [ V_26 ++ ] = F_8 ( V_32 ) | V_44 ;
V_27 [ V_26 ++ ] = V_42 | V_41 | V_28 | V_30 ;
V_2 -> V_5 = V_26 ;
if ( V_32 )
V_27 [ V_26 ++ ] = F_9 ( V_32 ) | V_43 ;
V_27 [ V_26 ++ ] = F_9 ( V_31 ) | V_44 ;
V_27 [ V_26 ++ ] = V_42 | V_41 | V_28 | V_30 ;
error = F_10 ( V_2 -> V_4 , 0 , V_27 , V_26 ) ;
if ( error < 0 )
return error ;
error = F_11 ( V_2 -> V_4 , ( ( V_25 & V_45 ) ?
0 : V_46 ) ) ;
if ( error < 0 )
return error ;
V_2 -> V_8 = V_8 ;
V_2 -> V_25 = V_25 ;
return error ;
}
static void F_12 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_13 ( V_48 , struct V_1 , V_48 ) ;
F_14 ( & V_2 -> V_49 ) ;
while ( ! F_15 ( & V_2 -> V_50 ) ) {
struct V_9 * V_51 ;
struct V_52 * V_20 ;
struct V_11 * V_12 = NULL ;
int V_53 = 0 ;
V_51 = F_13 ( V_2 -> V_50 . V_54 , struct V_9 ,
V_55 ) ;
F_16 ( & V_51 -> V_55 ) ;
F_17 ( & V_2 -> V_49 ) ;
V_20 = V_51 -> V_20 ;
if ( V_2 -> V_56 )
V_2 -> V_56 ( V_20 -> V_57 ) ;
F_18 (t, &m->transfers, transfer_list) {
int V_8 = V_20 -> V_58 ;
int V_59 ;
if ( V_12 -> V_58 )
V_8 = V_12 -> V_58 ;
if ( F_7 ( V_2 , V_8 , V_20 -> V_25 ) < 0 )
break;
F_6 ( V_2 , 1 ) ;
V_59 = F_4 ( V_2 , V_51 , V_12 ) ;
if ( V_59 < 0 )
V_53 = V_59 ;
if ( V_12 -> V_60 )
F_19 ( V_12 -> V_60 ) ;
if ( V_12 -> V_61 )
F_6 ( V_2 , 0 ) ;
}
F_6 ( V_2 , 0 ) ;
V_51 -> V_53 = V_53 ;
V_51 -> V_62 ( V_51 -> V_63 ) ;
F_14 ( & V_2 -> V_49 ) ;
}
if ( V_2 -> V_64 )
V_62 ( & V_2 -> V_62 ) ;
F_17 ( & V_2 -> V_49 ) ;
}
static int F_20 ( struct V_52 * V_20 , struct V_9 * V_51 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
int error = 0 ;
V_51 -> V_19 = 0 ;
V_51 -> V_53 = - V_65 ;
V_2 = F_21 ( V_20 -> V_66 ) ;
if ( F_15 ( & V_51 -> V_67 ) || ! V_51 -> V_62 )
return - V_68 ;
F_18 (t, &m->transfers, transfer_list) {
if ( V_12 -> V_18 && ! ( V_12 -> V_15 || V_12 -> V_17 ) ) {
F_22 ( & V_20 -> V_4 , L_6 ) ;
return - V_68 ;
}
if ( V_12 -> V_18 && V_12 -> V_15 && V_12 -> V_17 ) {
F_22 ( & V_20 -> V_4 , L_7 ) ;
return - V_68 ;
}
}
F_14 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_64 ) {
error = - V_69 ;
goto V_70;
}
F_23 ( & V_51 -> V_55 , & V_2 -> V_50 ) ;
F_24 ( V_2 -> V_71 , & V_2 -> V_48 ) ;
V_70:
F_17 ( & V_2 -> V_49 ) ;
return error ;
}
static int F_25 ( struct V_72 * V_73 )
{
const struct V_74 * V_75 ;
struct V_1 * V_2 ;
struct V_76 * V_66 ;
struct V_77 * V_4 = & V_73 -> V_4 ;
int error = 0 ;
V_75 = F_26 ( V_4 ) ;
if ( ! V_75 ) {
F_22 ( V_4 , L_8 ) ;
return - V_68 ;
}
V_66 = F_27 ( V_4 , sizeof( struct V_1 ) ) ;
if ( ! V_66 ) {
F_22 ( V_4 , L_9 ) ;
return - V_78 ;
}
V_2 = F_21 ( V_66 ) ;
F_28 ( V_73 , V_2 ) ;
V_2 -> V_66 = V_66 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_56 = V_75 -> V_56 ;
F_29 ( & V_2 -> V_49 ) ;
F_30 ( & V_2 -> V_62 ) ;
F_31 ( & V_2 -> V_50 ) ;
F_32 ( & V_2 -> V_48 , F_12 ) ;
V_2 -> V_71 = F_33 ( F_34 ( V_4 ) ) ;
if ( ! V_2 -> V_71 ) {
error = - V_78 ;
F_22 ( V_4 , L_10 ) ;
goto V_79;
}
error = F_35 ( V_2 -> V_4 , V_75 -> V_80 ) ;
if ( error < 0 ) {
F_22 ( V_4 , L_11 ) ;
goto V_81;
}
V_66 -> V_82 = V_73 -> V_83 ;
V_66 -> V_84 = V_75 -> V_85 ;
V_66 -> V_86 = V_33 ;
V_66 -> V_87 = F_36 ( 1 , 32 ) ;
V_66 -> V_88 = V_89 ;
V_66 -> V_90 = F_20 ;
error = F_37 ( V_66 ) ;
if ( error ) {
F_22 ( V_4 , L_12 ) ;
goto V_91;
}
return 0 ;
V_91:
V_81:
F_38 ( V_2 -> V_71 ) ;
V_79:
F_39 ( V_66 ) ;
return error ;
}
static int F_40 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_41 ( V_73 ) ;
int error ;
V_2 -> V_64 = 1 ;
while ( ! F_15 ( & V_2 -> V_50 ) ) {
error = F_42 ( & V_2 -> V_62 ) ;
if ( error < 0 ) {
V_2 -> V_64 = 0 ;
return error ;
}
}
F_38 ( V_2 -> V_71 ) ;
F_43 ( V_2 -> V_66 ) ;
return 0 ;
}
