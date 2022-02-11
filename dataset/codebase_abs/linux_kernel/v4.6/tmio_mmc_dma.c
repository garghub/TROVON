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
V_29:
if ( ! V_12 ) {
F_1 ( V_2 , false ) ;
if ( V_16 >= 0 )
V_16 = - V_40 ;
V_2 -> V_5 = NULL ;
F_11 ( V_14 ) ;
V_14 = V_2 -> V_4 ;
if ( V_14 ) {
V_2 -> V_4 = NULL ;
F_11 ( V_14 ) ;
}
F_12 ( & V_2 -> V_41 -> V_36 ,
L_1 , V_16 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
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
F_6 ( V_2 , V_42 ) ;
if ( ! V_18 ) {
unsigned long V_43 ;
void * V_44 = F_14 ( V_8 , & V_43 ) ;
F_7 ( & V_2 -> V_33 , V_2 -> V_34 , V_8 -> V_24 ) ;
memcpy ( V_2 -> V_34 , V_44 , V_2 -> V_33 . V_24 ) ;
F_15 ( V_8 , & V_43 , V_44 ) ;
V_2 -> V_9 = & V_2 -> V_33 ;
V_8 = V_2 -> V_9 ;
}
V_16 = F_8 ( V_14 -> V_35 -> V_36 , V_8 , V_2 -> V_25 , V_45 ) ;
if ( V_16 > 0 )
V_12 = F_9 ( V_14 , V_8 , V_16 ,
V_46 , V_39 ) ;
if ( V_12 ) {
V_15 = F_10 ( V_12 ) ;
if ( V_15 < 0 ) {
V_12 = NULL ;
V_16 = V_15 ;
}
}
V_29:
if ( ! V_12 ) {
F_1 ( V_2 , false ) ;
if ( V_16 >= 0 )
V_16 = - V_40 ;
V_2 -> V_4 = NULL ;
F_11 ( V_14 ) ;
V_14 = V_2 -> V_5 ;
if ( V_14 ) {
V_2 -> V_5 = NULL ;
F_11 ( V_14 ) ;
}
F_12 ( & V_2 -> V_41 -> V_36 ,
L_1 , V_16 ) ;
}
}
void F_16 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
if ( V_48 -> V_43 & V_49 ) {
if ( V_2 -> V_5 )
F_4 ( V_2 ) ;
} else {
if ( V_2 -> V_4 )
F_13 ( V_2 ) ;
}
}
static void F_17 ( unsigned long V_50 )
{
struct V_1 * V_2 = (struct V_1 * ) V_50 ;
struct V_13 * V_14 = NULL ;
F_18 ( & V_2 -> V_51 ) ;
if ( V_2 && V_2 -> V_48 ) {
if ( V_2 -> V_48 -> V_43 & V_49 )
V_14 = V_2 -> V_5 ;
else
V_14 = V_2 -> V_4 ;
}
F_19 ( & V_2 -> V_51 ) ;
F_20 ( V_2 , V_52 ) ;
if ( V_14 )
F_21 ( V_14 ) ;
}
static void F_22 ( unsigned long V_53 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
F_18 ( & V_2 -> V_51 ) ;
if ( ! V_2 -> V_48 )
goto V_54;
if ( V_2 -> V_48 -> V_43 & V_49 )
F_23 ( V_2 -> V_5 -> V_35 -> V_36 ,
V_2 -> V_9 , V_2 -> V_25 ,
V_37 ) ;
else
F_23 ( V_2 -> V_4 -> V_35 -> V_36 ,
V_2 -> V_9 , V_2 -> V_25 ,
V_45 ) ;
F_24 ( V_2 ) ;
V_54:
F_19 ( & V_2 -> V_51 ) ;
}
void F_25 ( struct V_1 * V_2 , struct V_55 * V_21 )
{
if ( ! V_2 -> V_6 || ( ! V_2 -> V_41 -> V_36 . V_56 &&
( ! V_21 -> V_57 || ! V_21 -> V_58 ) ) )
return;
if ( ! V_2 -> V_4 && ! V_2 -> V_5 ) {
struct V_59 * V_60 = F_26 ( V_2 -> V_41 ,
V_61 , 0 ) ;
struct V_62 V_63 = {} ;
T_2 V_64 ;
int V_16 ;
if ( ! V_60 )
return;
F_27 ( V_64 ) ;
F_28 ( V_65 , V_64 ) ;
V_2 -> V_4 = F_29 ( V_64 ,
V_2 -> V_6 -> V_66 , V_21 -> V_57 ,
& V_2 -> V_41 -> V_36 , L_2 ) ;
F_30 ( & V_2 -> V_41 -> V_36 , L_3 , V_67 ,
V_2 -> V_4 ) ;
if ( ! V_2 -> V_4 )
return;
V_63 . V_68 = V_46 ;
V_63 . V_69 = V_60 -> V_70 + ( V_71 << V_2 -> V_72 ) ;
V_63 . V_73 = V_2 -> V_6 -> V_74 ;
if ( ! V_63 . V_73 )
V_63 . V_73 = V_75 ;
V_63 . V_76 = 0 ;
V_16 = F_31 ( V_2 -> V_4 , & V_63 ) ;
if ( V_16 < 0 )
goto V_77;
V_2 -> V_5 = F_29 ( V_64 ,
V_2 -> V_6 -> V_66 , V_21 -> V_58 ,
& V_2 -> V_41 -> V_36 , L_4 ) ;
F_30 ( & V_2 -> V_41 -> V_36 , L_5 , V_67 ,
V_2 -> V_5 ) ;
if ( ! V_2 -> V_5 )
goto V_78;
V_63 . V_68 = V_38 ;
V_63 . V_76 = V_63 . V_69 + V_2 -> V_21 -> V_79 ;
V_63 . V_80 = V_2 -> V_6 -> V_74 ;
if ( ! V_63 . V_80 )
V_63 . V_80 = V_75 ;
V_63 . V_69 = 0 ;
V_16 = F_31 ( V_2 -> V_5 , & V_63 ) ;
if ( V_16 < 0 )
goto V_81;
V_2 -> V_34 = ( V_82 * ) F_32 ( V_83 | V_84 ) ;
if ( ! V_2 -> V_34 )
goto V_85;
F_33 ( & V_2 -> V_86 , F_22 , ( unsigned long ) V_2 ) ;
F_33 ( & V_2 -> V_87 , F_17 , ( unsigned long ) V_2 ) ;
}
F_1 ( V_2 , true ) ;
return;
V_85:
V_81:
F_11 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_78:
V_77:
F_11 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 ) {
struct V_13 * V_14 = V_2 -> V_4 ;
V_2 -> V_4 = NULL ;
F_11 ( V_14 ) ;
}
if ( V_2 -> V_5 ) {
struct V_13 * V_14 = V_2 -> V_5 ;
V_2 -> V_5 = NULL ;
F_11 ( V_14 ) ;
}
if ( V_2 -> V_34 ) {
F_35 ( ( unsigned long ) V_2 -> V_34 , 0 ) ;
V_2 -> V_34 = NULL ;
}
}
