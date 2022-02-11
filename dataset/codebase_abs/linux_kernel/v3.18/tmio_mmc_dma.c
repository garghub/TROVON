void F_1 ( struct V_1 * V_2 , bool V_3 )
{
if ( ! V_2 -> V_4 || ! V_2 -> V_5 )
return;
if ( V_2 -> V_6 -> V_7 & V_8 )
F_2 ( V_2 , V_9 , V_3 ? 2 : 0 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_1 ( V_2 , false ) ;
if ( V_2 -> V_5 )
F_4 ( V_2 -> V_5 ) ;
if ( V_2 -> V_4 )
F_4 ( V_2 -> V_4 ) ;
F_1 ( V_2 , true ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 , * V_13 ;
struct V_14 * V_15 = NULL ;
struct V_16 * V_17 = V_2 -> V_5 ;
struct V_18 * V_6 = V_2 -> V_6 ;
T_1 V_19 ;
int V_20 , V_21 ;
bool V_22 = true , V_23 = true ;
unsigned int V_24 = ( 1 << V_6 -> V_25 -> V_26 ) - 1 ;
F_6 (sg, sg_tmp, host->sg_len, i) {
if ( V_13 -> V_27 & V_24 )
V_22 = false ;
if ( V_13 -> V_28 & V_24 ) {
V_23 = false ;
break;
}
}
if ( ( ! V_22 && ( V_2 -> V_29 > 1 || V_11 -> V_28 > V_30 ||
( V_24 & V_31 ) ) ) || ! V_23 ) {
V_20 = - V_32 ;
goto V_33;
}
if ( V_11 -> V_28 < V_34 ) {
V_2 -> V_35 = true ;
return;
}
F_7 ( V_2 , V_36 ) ;
if ( ! V_22 ) {
F_8 ( & V_2 -> V_37 , V_2 -> V_38 , V_11 -> V_28 ) ;
V_2 -> V_12 = & V_2 -> V_37 ;
V_11 = V_2 -> V_12 ;
}
V_20 = F_9 ( V_17 -> V_39 -> V_40 , V_11 , V_2 -> V_29 , V_41 ) ;
if ( V_20 > 0 )
V_15 = F_10 ( V_17 , V_11 , V_20 ,
V_42 , V_43 ) ;
if ( V_15 ) {
V_19 = F_11 ( V_15 ) ;
if ( V_19 < 0 ) {
V_15 = NULL ;
V_20 = V_19 ;
}
}
F_12 ( & V_2 -> V_44 -> V_40 , L_1 ,
V_45 , V_2 -> V_29 , V_20 , V_19 , V_2 -> V_46 ) ;
V_33:
if ( ! V_15 ) {
F_1 ( V_2 , false ) ;
if ( V_20 >= 0 )
V_20 = - V_47 ;
V_2 -> V_5 = NULL ;
F_13 ( V_17 ) ;
V_17 = V_2 -> V_4 ;
if ( V_17 ) {
V_2 -> V_4 = NULL ;
F_13 ( V_17 ) ;
}
F_14 ( & V_2 -> V_44 -> V_40 ,
L_2 , V_20 ) ;
}
F_12 ( & V_2 -> V_44 -> V_40 , L_3 , V_45 ,
V_15 , V_19 , V_2 -> V_29 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 , * V_13 ;
struct V_14 * V_15 = NULL ;
struct V_16 * V_17 = V_2 -> V_4 ;
struct V_18 * V_6 = V_2 -> V_6 ;
T_1 V_19 ;
int V_20 , V_21 ;
bool V_22 = true , V_23 = true ;
unsigned int V_24 = ( 1 << V_6 -> V_25 -> V_26 ) - 1 ;
F_6 (sg, sg_tmp, host->sg_len, i) {
if ( V_13 -> V_27 & V_24 )
V_22 = false ;
if ( V_13 -> V_28 & V_24 ) {
V_23 = false ;
break;
}
}
if ( ( ! V_22 && ( V_2 -> V_29 > 1 || V_11 -> V_28 > V_30 ||
( V_24 & V_31 ) ) ) || ! V_23 ) {
V_20 = - V_32 ;
goto V_33;
}
if ( V_11 -> V_28 < V_34 ) {
V_2 -> V_35 = true ;
return;
}
F_7 ( V_2 , V_48 ) ;
if ( ! V_22 ) {
unsigned long V_7 ;
void * V_49 = F_16 ( V_11 , & V_7 ) ;
F_8 ( & V_2 -> V_37 , V_2 -> V_38 , V_11 -> V_28 ) ;
memcpy ( V_2 -> V_38 , V_49 , V_2 -> V_37 . V_28 ) ;
F_17 ( V_11 , & V_7 , V_49 ) ;
V_2 -> V_12 = & V_2 -> V_37 ;
V_11 = V_2 -> V_12 ;
}
V_20 = F_9 ( V_17 -> V_39 -> V_40 , V_11 , V_2 -> V_29 , V_50 ) ;
if ( V_20 > 0 )
V_15 = F_10 ( V_17 , V_11 , V_20 ,
V_51 , V_43 ) ;
if ( V_15 ) {
V_19 = F_11 ( V_15 ) ;
if ( V_19 < 0 ) {
V_15 = NULL ;
V_20 = V_19 ;
}
}
F_12 ( & V_2 -> V_44 -> V_40 , L_1 ,
V_45 , V_2 -> V_29 , V_20 , V_19 , V_2 -> V_46 ) ;
V_33:
if ( ! V_15 ) {
F_1 ( V_2 , false ) ;
if ( V_20 >= 0 )
V_20 = - V_47 ;
V_2 -> V_4 = NULL ;
F_13 ( V_17 ) ;
V_17 = V_2 -> V_5 ;
if ( V_17 ) {
V_2 -> V_5 = NULL ;
F_13 ( V_17 ) ;
}
F_14 ( & V_2 -> V_44 -> V_40 ,
L_2 , V_20 ) ;
}
F_12 ( & V_2 -> V_44 -> V_40 , L_4 , V_45 ,
V_15 , V_19 ) ;
}
void F_18 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
if ( V_53 -> V_7 & V_54 ) {
if ( V_2 -> V_5 )
F_5 ( V_2 ) ;
} else {
if ( V_2 -> V_4 )
F_15 ( V_2 ) ;
}
}
static void F_19 ( unsigned long V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_55 ;
struct V_16 * V_17 = NULL ;
F_20 ( & V_2 -> V_56 ) ;
if ( V_2 && V_2 -> V_53 ) {
if ( V_2 -> V_53 -> V_7 & V_54 )
V_17 = V_2 -> V_5 ;
else
V_17 = V_2 -> V_4 ;
}
F_21 ( & V_2 -> V_56 ) ;
F_22 ( V_2 , V_57 ) ;
if ( V_17 )
F_23 ( V_17 ) ;
}
static void F_24 ( unsigned long V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
F_20 ( & V_2 -> V_56 ) ;
if ( ! V_2 -> V_53 )
goto V_59;
if ( V_2 -> V_53 -> V_7 & V_54 )
F_25 ( V_2 -> V_5 -> V_39 -> V_40 ,
V_2 -> V_12 , V_2 -> V_29 ,
V_41 ) ;
else
F_25 ( V_2 -> V_4 -> V_39 -> V_40 ,
V_2 -> V_12 , V_2 -> V_29 ,
V_50 ) ;
F_26 ( V_2 ) ;
V_59:
F_21 ( & V_2 -> V_56 ) ;
}
void F_27 ( struct V_1 * V_2 , struct V_18 * V_6 )
{
if ( ! V_6 -> V_25 || ( ! V_2 -> V_44 -> V_40 . V_60 &&
( ! V_6 -> V_25 -> V_61 || ! V_6 -> V_25 -> V_62 ) ) )
return;
if ( ! V_2 -> V_4 && ! V_2 -> V_5 ) {
struct V_63 * V_64 = F_28 ( V_2 -> V_44 ,
V_65 , 0 ) ;
struct V_66 V_67 = {} ;
T_2 V_68 ;
int V_20 ;
if ( ! V_64 )
return;
F_29 ( V_68 ) ;
F_30 ( V_69 , V_68 ) ;
V_2 -> V_4 = F_31 ( V_68 ,
V_6 -> V_25 -> V_70 , V_6 -> V_25 -> V_61 ,
& V_2 -> V_44 -> V_40 , L_5 ) ;
F_12 ( & V_2 -> V_44 -> V_40 , L_6 , V_45 ,
V_2 -> V_4 ) ;
if ( ! V_2 -> V_4 )
return;
if ( V_6 -> V_25 -> V_61 )
V_67 . V_71 = V_6 -> V_25 -> V_72 ;
V_67 . V_73 = V_51 ;
V_67 . V_74 = V_64 -> V_75 + ( V_76 << V_2 -> V_6 -> V_77 ) ;
V_67 . V_78 = V_79 ;
V_67 . V_80 = 0 ;
V_20 = F_32 ( V_2 -> V_4 , & V_67 ) ;
if ( V_20 < 0 )
goto V_81;
V_2 -> V_5 = F_31 ( V_68 ,
V_6 -> V_25 -> V_70 , V_6 -> V_25 -> V_62 ,
& V_2 -> V_44 -> V_40 , L_7 ) ;
F_12 ( & V_2 -> V_44 -> V_40 , L_8 , V_45 ,
V_2 -> V_5 ) ;
if ( ! V_2 -> V_5 )
goto V_82;
if ( V_6 -> V_25 -> V_62 )
V_67 . V_71 = V_6 -> V_25 -> V_83 ;
V_67 . V_73 = V_42 ;
V_67 . V_80 = V_67 . V_74 + V_6 -> V_25 -> V_84 ;
V_67 . V_85 = V_79 ;
V_67 . V_74 = 0 ;
V_20 = F_32 ( V_2 -> V_5 , & V_67 ) ;
if ( V_20 < 0 )
goto V_86;
V_2 -> V_38 = ( V_87 * ) F_33 ( V_88 | V_89 ) ;
if ( ! V_2 -> V_38 )
goto V_90;
F_34 ( & V_2 -> V_91 , F_24 , ( unsigned long ) V_2 ) ;
F_34 ( & V_2 -> V_92 , F_19 , ( unsigned long ) V_2 ) ;
}
F_1 ( V_2 , true ) ;
return;
V_90:
V_86:
F_13 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_82:
V_81:
F_13 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 ) {
struct V_16 * V_17 = V_2 -> V_4 ;
V_2 -> V_4 = NULL ;
F_13 ( V_17 ) ;
}
if ( V_2 -> V_5 ) {
struct V_16 * V_17 = V_2 -> V_5 ;
V_2 -> V_5 = NULL ;
F_13 ( V_17 ) ;
}
if ( V_2 -> V_38 ) {
F_36 ( ( unsigned long ) V_2 -> V_38 , 0 ) ;
V_2 -> V_38 = NULL ;
}
}
