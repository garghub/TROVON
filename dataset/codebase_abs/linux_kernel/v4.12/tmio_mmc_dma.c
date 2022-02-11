void F_1 ( struct V_1 * V_2 , bool V_3 )
{
if ( ! V_2 -> V_4 || ! V_2 -> V_5 )
return;
if ( V_2 -> V_6 -> V_3 )
V_2 -> V_6 -> V_3 ( V_2 , V_3 ) ;
}
void F_2 ( struct V_1 * V_2 )
{
F_1 ( V_2 , false ) ;
if ( V_2 -> V_5 )
F_3 ( V_2 -> V_5 ) ;
if ( V_2 -> V_4 )
F_3 ( V_2 -> V_4 ) ;
F_1 ( V_2 , true ) ;
}
static void F_4 ( void * V_7 )
{
struct V_1 * V_2 = V_7 ;
F_5 ( & V_2 -> V_8 ) ;
if ( ! V_2 -> V_9 )
goto V_10;
if ( V_2 -> V_9 -> V_11 & V_12 )
F_6 ( V_2 -> V_5 -> V_13 -> V_14 ,
V_2 -> V_15 , V_2 -> V_16 ,
V_17 ) ;
else
F_6 ( V_2 -> V_4 -> V_13 -> V_14 ,
V_2 -> V_15 , V_2 -> V_16 ,
V_18 ) ;
F_7 ( & V_2 -> V_8 ) ;
F_8 ( & V_2 -> V_19 ) ;
F_5 ( & V_2 -> V_8 ) ;
F_9 ( V_2 ) ;
V_10:
F_7 ( & V_2 -> V_8 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_15 , * V_22 ;
struct V_23 * V_24 = NULL ;
struct V_25 * V_26 = V_2 -> V_5 ;
T_1 V_27 ;
int V_28 , V_29 ;
bool V_30 = true , V_31 = true ;
unsigned int V_32 = ( 1 << V_2 -> V_33 -> V_34 ) - 1 ;
F_11 (sg, sg_tmp, host->sg_len, i) {
if ( V_22 -> V_35 & V_32 )
V_30 = false ;
if ( V_22 -> V_36 & V_32 ) {
V_31 = false ;
break;
}
}
if ( ( ! V_30 && ( V_2 -> V_16 > 1 || V_21 -> V_36 > V_37 ||
( V_32 & V_38 ) ) ) || ! V_31 ) {
V_28 = - V_39 ;
goto V_40;
}
if ( V_21 -> V_36 < V_41 ) {
V_2 -> V_42 = true ;
return;
}
F_12 ( V_2 , V_43 ) ;
if ( ! V_30 ) {
F_13 ( & V_2 -> V_44 , V_2 -> V_45 , V_21 -> V_36 ) ;
V_2 -> V_15 = & V_2 -> V_44 ;
V_21 = V_2 -> V_15 ;
}
V_28 = F_14 ( V_26 -> V_13 -> V_14 , V_21 , V_2 -> V_16 , V_17 ) ;
if ( V_28 > 0 )
V_24 = F_15 ( V_26 , V_21 , V_28 ,
V_46 , V_47 ) ;
if ( V_24 ) {
F_16 ( & V_2 -> V_19 ) ;
V_24 -> V_48 = F_4 ;
V_24 -> V_49 = V_2 ;
V_27 = F_17 ( V_24 ) ;
if ( V_27 < 0 ) {
V_24 = NULL ;
V_28 = V_27 ;
}
}
V_40:
if ( ! V_24 ) {
F_1 ( V_2 , false ) ;
if ( V_28 >= 0 )
V_28 = - V_50 ;
V_2 -> V_5 = NULL ;
F_18 ( V_26 ) ;
V_26 = V_2 -> V_4 ;
if ( V_26 ) {
V_2 -> V_4 = NULL ;
F_18 ( V_26 ) ;
}
F_19 ( & V_2 -> V_51 -> V_14 ,
L_1 , V_28 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_15 , * V_22 ;
struct V_23 * V_24 = NULL ;
struct V_25 * V_26 = V_2 -> V_4 ;
T_1 V_27 ;
int V_28 , V_29 ;
bool V_30 = true , V_31 = true ;
unsigned int V_32 = ( 1 << V_2 -> V_33 -> V_34 ) - 1 ;
F_11 (sg, sg_tmp, host->sg_len, i) {
if ( V_22 -> V_35 & V_32 )
V_30 = false ;
if ( V_22 -> V_36 & V_32 ) {
V_31 = false ;
break;
}
}
if ( ( ! V_30 && ( V_2 -> V_16 > 1 || V_21 -> V_36 > V_37 ||
( V_32 & V_38 ) ) ) || ! V_31 ) {
V_28 = - V_39 ;
goto V_40;
}
if ( V_21 -> V_36 < V_41 ) {
V_2 -> V_42 = true ;
return;
}
F_12 ( V_2 , V_52 ) ;
if ( ! V_30 ) {
unsigned long V_11 ;
void * V_53 = F_21 ( V_21 , & V_11 ) ;
F_13 ( & V_2 -> V_44 , V_2 -> V_45 , V_21 -> V_36 ) ;
memcpy ( V_2 -> V_45 , V_53 , V_2 -> V_44 . V_36 ) ;
F_22 ( V_21 , & V_11 , V_53 ) ;
V_2 -> V_15 = & V_2 -> V_44 ;
V_21 = V_2 -> V_15 ;
}
V_28 = F_14 ( V_26 -> V_13 -> V_14 , V_21 , V_2 -> V_16 , V_18 ) ;
if ( V_28 > 0 )
V_24 = F_15 ( V_26 , V_21 , V_28 ,
V_54 , V_47 ) ;
if ( V_24 ) {
F_16 ( & V_2 -> V_19 ) ;
V_24 -> V_48 = F_4 ;
V_24 -> V_49 = V_2 ;
V_27 = F_17 ( V_24 ) ;
if ( V_27 < 0 ) {
V_24 = NULL ;
V_28 = V_27 ;
}
}
V_40:
if ( ! V_24 ) {
F_1 ( V_2 , false ) ;
if ( V_28 >= 0 )
V_28 = - V_50 ;
V_2 -> V_4 = NULL ;
F_18 ( V_26 ) ;
V_26 = V_2 -> V_5 ;
if ( V_26 ) {
V_2 -> V_5 = NULL ;
F_18 ( V_26 ) ;
}
F_19 ( & V_2 -> V_51 -> V_14 ,
L_1 , V_28 ) ;
}
}
void F_23 ( struct V_1 * V_2 ,
struct V_55 * V_9 )
{
if ( V_9 -> V_11 & V_12 ) {
if ( V_2 -> V_5 )
F_10 ( V_2 ) ;
} else {
if ( V_2 -> V_4 )
F_20 ( V_2 ) ;
}
}
static void F_24 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
struct V_25 * V_26 = NULL ;
F_5 ( & V_2 -> V_8 ) ;
if ( V_2 && V_2 -> V_9 ) {
if ( V_2 -> V_9 -> V_11 & V_12 )
V_26 = V_2 -> V_5 ;
else
V_26 = V_2 -> V_4 ;
}
F_7 ( & V_2 -> V_8 ) ;
F_25 ( V_2 , V_57 ) ;
if ( V_26 )
F_26 ( V_26 ) ;
}
void F_27 ( struct V_1 * V_2 , struct V_58 * V_33 )
{
if ( ! V_2 -> V_6 || ( ! V_2 -> V_51 -> V_14 . V_59 &&
( ! V_33 -> V_60 || ! V_33 -> V_61 ) ) )
return;
if ( ! V_2 -> V_4 && ! V_2 -> V_5 ) {
struct V_62 * V_63 = F_28 ( V_2 -> V_51 ,
V_64 , 0 ) ;
struct V_65 V_66 = {} ;
T_2 V_67 ;
int V_28 ;
if ( ! V_63 )
return;
F_29 ( V_67 ) ;
F_30 ( V_68 , V_67 ) ;
V_2 -> V_4 = F_31 ( V_67 ,
V_2 -> V_6 -> V_69 , V_33 -> V_60 ,
& V_2 -> V_51 -> V_14 , L_2 ) ;
F_32 ( & V_2 -> V_51 -> V_14 , L_3 , V_70 ,
V_2 -> V_4 ) ;
if ( ! V_2 -> V_4 )
return;
V_66 . V_71 = V_54 ;
V_66 . V_72 = V_63 -> V_73 + ( V_74 << V_2 -> V_75 ) ;
V_66 . V_76 = V_2 -> V_6 -> V_77 ;
if ( ! V_66 . V_76 )
V_66 . V_76 = V_78 ;
V_66 . V_79 = 0 ;
V_28 = F_33 ( V_2 -> V_4 , & V_66 ) ;
if ( V_28 < 0 )
goto V_80;
V_2 -> V_5 = F_31 ( V_67 ,
V_2 -> V_6 -> V_69 , V_33 -> V_61 ,
& V_2 -> V_51 -> V_14 , L_4 ) ;
F_32 ( & V_2 -> V_51 -> V_14 , L_5 , V_70 ,
V_2 -> V_5 ) ;
if ( ! V_2 -> V_5 )
goto V_81;
V_66 . V_71 = V_46 ;
V_66 . V_79 = V_66 . V_72 + V_2 -> V_33 -> V_82 ;
V_66 . V_83 = V_2 -> V_6 -> V_77 ;
if ( ! V_66 . V_83 )
V_66 . V_83 = V_78 ;
V_66 . V_72 = 0 ;
V_28 = F_33 ( V_2 -> V_5 , & V_66 ) ;
if ( V_28 < 0 )
goto V_84;
V_2 -> V_45 = ( V_85 * ) F_34 ( V_86 | V_87 ) ;
if ( ! V_2 -> V_45 )
goto V_88;
F_35 ( & V_2 -> V_19 ) ;
F_36 ( & V_2 -> V_89 , F_24 , ( unsigned long ) V_2 ) ;
}
F_1 ( V_2 , true ) ;
return;
V_88:
V_84:
F_18 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_81:
V_80:
F_18 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
void F_37 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 ) {
struct V_25 * V_26 = V_2 -> V_4 ;
V_2 -> V_4 = NULL ;
F_18 ( V_26 ) ;
}
if ( V_2 -> V_5 ) {
struct V_25 * V_26 = V_2 -> V_5 ;
V_2 -> V_5 = NULL ;
F_18 ( V_26 ) ;
}
if ( V_2 -> V_45 ) {
F_38 ( ( unsigned long ) V_2 -> V_45 , 0 ) ;
V_2 -> V_45 = NULL ;
}
}
