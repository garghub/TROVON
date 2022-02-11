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
static void F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 , * V_10 ;
struct V_11 * V_12 = NULL ;
struct V_13 * V_14 = V_2 -> V_5 ;
T_1 V_15 ;
int V_16 , V_17 ;
bool V_18 = true , V_19 = true ;
unsigned int V_20 = ( 1 << V_2 -> V_21 -> V_22 ) - 1 ;
F_5 (sg, sg_tmp, host->sg_len, i) {
if ( V_10 -> V_23 & V_20 )
V_18 = false ;
if ( V_10 -> V_24 & V_20 ) {
V_19 = false ;
break;
}
}
if ( ( ! V_18 && ( V_2 -> V_25 > 1 || V_8 -> V_24 > V_26 ||
( V_20 & V_27 ) ) ) || ! V_19 ) {
V_16 = - V_28 ;
goto V_29;
}
if ( V_8 -> V_24 < V_30 ) {
V_2 -> V_31 = true ;
return;
}
F_6 ( V_2 , V_32 ) ;
if ( ! V_18 ) {
F_7 ( & V_2 -> V_33 , V_2 -> V_34 , V_8 -> V_24 ) ;
V_2 -> V_9 = & V_2 -> V_33 ;
V_8 = V_2 -> V_9 ;
}
V_16 = F_8 ( V_14 -> V_35 -> V_36 , V_8 , V_2 -> V_25 , V_37 ) ;
if ( V_16 > 0 )
V_12 = F_9 ( V_14 , V_8 , V_16 ,
V_38 , V_39 ) ;
if ( V_12 ) {
V_15 = F_10 ( V_12 ) ;
if ( V_15 < 0 ) {
V_12 = NULL ;
V_16 = V_15 ;
}
}
F_11 ( & V_2 -> V_40 -> V_36 , L_1 ,
V_41 , V_2 -> V_25 , V_16 , V_15 , V_2 -> V_42 ) ;
V_29:
if ( ! V_12 ) {
F_1 ( V_2 , false ) ;
if ( V_16 >= 0 )
V_16 = - V_43 ;
V_2 -> V_5 = NULL ;
F_12 ( V_14 ) ;
V_14 = V_2 -> V_4 ;
if ( V_14 ) {
V_2 -> V_4 = NULL ;
F_12 ( V_14 ) ;
}
F_13 ( & V_2 -> V_40 -> V_36 ,
L_2 , V_16 ) ;
}
F_11 ( & V_2 -> V_40 -> V_36 , L_3 , V_41 ,
V_12 , V_15 , V_2 -> V_25 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 , * V_10 ;
struct V_11 * V_12 = NULL ;
struct V_13 * V_14 = V_2 -> V_4 ;
T_1 V_15 ;
int V_16 , V_17 ;
bool V_18 = true , V_19 = true ;
unsigned int V_20 = ( 1 << V_2 -> V_21 -> V_22 ) - 1 ;
F_5 (sg, sg_tmp, host->sg_len, i) {
if ( V_10 -> V_23 & V_20 )
V_18 = false ;
if ( V_10 -> V_24 & V_20 ) {
V_19 = false ;
break;
}
}
if ( ( ! V_18 && ( V_2 -> V_25 > 1 || V_8 -> V_24 > V_26 ||
( V_20 & V_27 ) ) ) || ! V_19 ) {
V_16 = - V_28 ;
goto V_29;
}
if ( V_8 -> V_24 < V_30 ) {
V_2 -> V_31 = true ;
return;
}
F_6 ( V_2 , V_44 ) ;
if ( ! V_18 ) {
unsigned long V_45 ;
void * V_46 = F_15 ( V_8 , & V_45 ) ;
F_7 ( & V_2 -> V_33 , V_2 -> V_34 , V_8 -> V_24 ) ;
memcpy ( V_2 -> V_34 , V_46 , V_2 -> V_33 . V_24 ) ;
F_16 ( V_8 , & V_45 , V_46 ) ;
V_2 -> V_9 = & V_2 -> V_33 ;
V_8 = V_2 -> V_9 ;
}
V_16 = F_8 ( V_14 -> V_35 -> V_36 , V_8 , V_2 -> V_25 , V_47 ) ;
if ( V_16 > 0 )
V_12 = F_9 ( V_14 , V_8 , V_16 ,
V_48 , V_39 ) ;
if ( V_12 ) {
V_15 = F_10 ( V_12 ) ;
if ( V_15 < 0 ) {
V_12 = NULL ;
V_16 = V_15 ;
}
}
F_11 ( & V_2 -> V_40 -> V_36 , L_1 ,
V_41 , V_2 -> V_25 , V_16 , V_15 , V_2 -> V_42 ) ;
V_29:
if ( ! V_12 ) {
F_1 ( V_2 , false ) ;
if ( V_16 >= 0 )
V_16 = - V_43 ;
V_2 -> V_4 = NULL ;
F_12 ( V_14 ) ;
V_14 = V_2 -> V_5 ;
if ( V_14 ) {
V_2 -> V_5 = NULL ;
F_12 ( V_14 ) ;
}
F_13 ( & V_2 -> V_40 -> V_36 ,
L_2 , V_16 ) ;
}
F_11 ( & V_2 -> V_40 -> V_36 , L_4 , V_41 ,
V_12 , V_15 ) ;
}
void F_17 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
if ( V_50 -> V_45 & V_51 ) {
if ( V_2 -> V_5 )
F_4 ( V_2 ) ;
} else {
if ( V_2 -> V_4 )
F_14 ( V_2 ) ;
}
}
static void F_18 ( unsigned long V_52 )
{
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
struct V_13 * V_14 = NULL ;
F_19 ( & V_2 -> V_53 ) ;
if ( V_2 && V_2 -> V_50 ) {
if ( V_2 -> V_50 -> V_45 & V_51 )
V_14 = V_2 -> V_5 ;
else
V_14 = V_2 -> V_4 ;
}
F_20 ( & V_2 -> V_53 ) ;
F_21 ( V_2 , V_54 ) ;
if ( V_14 )
F_22 ( V_14 ) ;
}
static void F_23 ( unsigned long V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_55 ;
F_19 ( & V_2 -> V_53 ) ;
if ( ! V_2 -> V_50 )
goto V_56;
if ( V_2 -> V_50 -> V_45 & V_51 )
F_24 ( V_2 -> V_5 -> V_35 -> V_36 ,
V_2 -> V_9 , V_2 -> V_25 ,
V_37 ) ;
else
F_24 ( V_2 -> V_4 -> V_35 -> V_36 ,
V_2 -> V_9 , V_2 -> V_25 ,
V_47 ) ;
F_25 ( V_2 ) ;
V_56:
F_20 ( & V_2 -> V_53 ) ;
}
void F_26 ( struct V_1 * V_2 , struct V_57 * V_21 )
{
if ( ! V_2 -> V_6 || ( ! V_2 -> V_40 -> V_36 . V_58 &&
( ! V_2 -> V_6 -> V_59 || ! V_2 -> V_6 -> V_60 ) ) )
return;
if ( ! V_2 -> V_4 && ! V_2 -> V_5 ) {
struct V_61 * V_62 = F_27 ( V_2 -> V_40 ,
V_63 , 0 ) ;
struct V_64 V_65 = {} ;
T_2 V_66 ;
int V_16 ;
if ( ! V_62 )
return;
F_28 ( V_66 ) ;
F_29 ( V_67 , V_66 ) ;
V_2 -> V_4 = F_30 ( V_66 ,
V_2 -> V_6 -> V_68 , V_2 -> V_6 -> V_59 ,
& V_2 -> V_40 -> V_36 , L_5 ) ;
F_11 ( & V_2 -> V_40 -> V_36 , L_6 , V_41 ,
V_2 -> V_4 ) ;
if ( ! V_2 -> V_4 )
return;
if ( V_2 -> V_6 -> V_59 )
V_65 . V_69 = V_2 -> V_6 -> V_70 ;
V_65 . V_71 = V_48 ;
V_65 . V_72 = V_62 -> V_73 + ( V_74 << V_2 -> V_75 ) ;
V_65 . V_76 = V_2 -> V_6 -> V_77 ;
if ( ! V_65 . V_76 )
V_65 . V_76 = V_78 ;
V_65 . V_79 = 0 ;
V_16 = F_31 ( V_2 -> V_4 , & V_65 ) ;
if ( V_16 < 0 )
goto V_80;
V_2 -> V_5 = F_30 ( V_66 ,
V_2 -> V_6 -> V_68 , V_2 -> V_6 -> V_60 ,
& V_2 -> V_40 -> V_36 , L_7 ) ;
F_11 ( & V_2 -> V_40 -> V_36 , L_8 , V_41 ,
V_2 -> V_5 ) ;
if ( ! V_2 -> V_5 )
goto V_81;
if ( V_2 -> V_6 -> V_60 )
V_65 . V_69 = V_2 -> V_6 -> V_82 ;
V_65 . V_71 = V_38 ;
V_65 . V_79 = V_65 . V_72 + V_2 -> V_21 -> V_83 ;
V_65 . V_84 = V_2 -> V_6 -> V_77 ;
if ( ! V_65 . V_84 )
V_65 . V_84 = V_78 ;
V_65 . V_72 = 0 ;
V_16 = F_31 ( V_2 -> V_5 , & V_65 ) ;
if ( V_16 < 0 )
goto V_85;
V_2 -> V_34 = ( V_86 * ) F_32 ( V_87 | V_88 ) ;
if ( ! V_2 -> V_34 )
goto V_89;
F_33 ( & V_2 -> V_90 , F_23 , ( unsigned long ) V_2 ) ;
F_33 ( & V_2 -> V_91 , F_18 , ( unsigned long ) V_2 ) ;
}
F_1 ( V_2 , true ) ;
return;
V_89:
V_85:
F_12 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_81:
V_80:
F_12 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 ) {
struct V_13 * V_14 = V_2 -> V_4 ;
V_2 -> V_4 = NULL ;
F_12 ( V_14 ) ;
}
if ( V_2 -> V_5 ) {
struct V_13 * V_14 = V_2 -> V_5 ;
V_2 -> V_5 = NULL ;
F_12 ( V_14 ) ;
}
if ( V_2 -> V_34 ) {
F_35 ( ( unsigned long ) V_2 -> V_34 , 0 ) ;
V_2 -> V_34 = NULL ;
}
}
