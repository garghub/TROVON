void F_1 ( struct V_1 * V_2 , bool V_3 )
{
if ( ! V_2 -> V_4 || ! V_2 -> V_5 )
return;
#if F_2 ( V_6 ) || F_2 ( V_7 )
F_3 ( V_2 , V_8 , V_3 ? 2 : 0 ) ;
#endif
}
void F_4 ( struct V_1 * V_2 )
{
F_1 ( V_2 , false ) ;
if ( V_2 -> V_5 )
F_5 ( V_2 -> V_5 ) ;
if ( V_2 -> V_4 )
F_5 ( V_2 -> V_4 ) ;
F_1 ( V_2 , true ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 , * V_12 ;
struct V_13 * V_14 = NULL ;
struct V_15 * V_16 = V_2 -> V_5 ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_19 ;
int V_20 , V_21 ;
bool V_22 = true , V_23 = true ;
unsigned int V_24 = ( 1 << V_18 -> V_25 -> V_26 ) - 1 ;
F_7 (sg, sg_tmp, host->sg_len, i) {
if ( V_12 -> V_27 & V_24 )
V_22 = false ;
if ( V_12 -> V_28 & V_24 ) {
V_23 = false ;
break;
}
}
if ( ( ! V_22 && ( V_2 -> V_29 > 1 || V_10 -> V_28 > V_30 ||
( V_24 & V_31 ) ) ) || ! V_23 ) {
V_20 = - V_32 ;
goto V_33;
}
if ( V_10 -> V_28 < V_34 ) {
V_2 -> V_35 = true ;
return;
}
F_8 ( V_2 , V_36 ) ;
if ( ! V_22 ) {
F_9 ( & V_2 -> V_37 , V_2 -> V_38 , V_10 -> V_28 ) ;
V_2 -> V_11 = & V_2 -> V_37 ;
V_10 = V_2 -> V_11 ;
}
V_20 = F_10 ( V_16 -> V_39 -> V_40 , V_10 , V_2 -> V_29 , V_41 ) ;
if ( V_20 > 0 )
V_14 = V_16 -> V_39 -> V_42 ( V_16 , V_10 , V_20 ,
V_43 , V_44 ) ;
if ( V_14 ) {
V_19 = F_11 ( V_14 ) ;
if ( V_19 < 0 ) {
V_14 = NULL ;
V_20 = V_19 ;
}
}
F_12 ( & V_2 -> V_45 -> V_40 , L_1 ,
V_46 , V_2 -> V_29 , V_20 , V_19 , V_2 -> V_47 ) ;
V_33:
if ( ! V_14 ) {
if ( V_20 >= 0 )
V_20 = - V_48 ;
V_2 -> V_5 = NULL ;
F_13 ( V_16 ) ;
V_16 = V_2 -> V_4 ;
if ( V_16 ) {
V_2 -> V_4 = NULL ;
F_13 ( V_16 ) ;
}
F_14 ( & V_2 -> V_45 -> V_40 ,
L_2 , V_20 ) ;
F_1 ( V_2 , false ) ;
}
F_12 ( & V_2 -> V_45 -> V_40 , L_3 , V_46 ,
V_14 , V_19 , V_2 -> V_29 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 , * V_12 ;
struct V_13 * V_14 = NULL ;
struct V_15 * V_16 = V_2 -> V_4 ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_19 ;
int V_20 , V_21 ;
bool V_22 = true , V_23 = true ;
unsigned int V_24 = ( 1 << V_18 -> V_25 -> V_26 ) - 1 ;
F_7 (sg, sg_tmp, host->sg_len, i) {
if ( V_12 -> V_27 & V_24 )
V_22 = false ;
if ( V_12 -> V_28 & V_24 ) {
V_23 = false ;
break;
}
}
if ( ( ! V_22 && ( V_2 -> V_29 > 1 || V_10 -> V_28 > V_30 ||
( V_24 & V_31 ) ) ) || ! V_23 ) {
V_20 = - V_32 ;
goto V_33;
}
if ( V_10 -> V_28 < V_34 ) {
V_2 -> V_35 = true ;
return;
}
F_8 ( V_2 , V_49 ) ;
if ( ! V_22 ) {
unsigned long V_50 ;
void * V_51 = F_16 ( V_10 , & V_50 ) ;
F_9 ( & V_2 -> V_37 , V_2 -> V_38 , V_10 -> V_28 ) ;
memcpy ( V_2 -> V_38 , V_51 , V_2 -> V_37 . V_28 ) ;
F_17 ( V_10 , & V_50 , V_51 ) ;
V_2 -> V_11 = & V_2 -> V_37 ;
V_10 = V_2 -> V_11 ;
}
V_20 = F_10 ( V_16 -> V_39 -> V_40 , V_10 , V_2 -> V_29 , V_52 ) ;
if ( V_20 > 0 )
V_14 = V_16 -> V_39 -> V_42 ( V_16 , V_10 , V_20 ,
V_53 , V_44 ) ;
if ( V_14 ) {
V_19 = F_11 ( V_14 ) ;
if ( V_19 < 0 ) {
V_14 = NULL ;
V_20 = V_19 ;
}
}
F_12 ( & V_2 -> V_45 -> V_40 , L_1 ,
V_46 , V_2 -> V_29 , V_20 , V_19 , V_2 -> V_47 ) ;
V_33:
if ( ! V_14 ) {
if ( V_20 >= 0 )
V_20 = - V_48 ;
V_2 -> V_4 = NULL ;
F_13 ( V_16 ) ;
V_16 = V_2 -> V_5 ;
if ( V_16 ) {
V_2 -> V_5 = NULL ;
F_13 ( V_16 ) ;
}
F_14 ( & V_2 -> V_45 -> V_40 ,
L_2 , V_20 ) ;
F_1 ( V_2 , false ) ;
}
F_12 ( & V_2 -> V_45 -> V_40 , L_4 , V_46 ,
V_14 , V_19 ) ;
}
void F_18 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
if ( V_55 -> V_50 & V_56 ) {
if ( V_2 -> V_5 )
F_6 ( V_2 ) ;
} else {
if ( V_2 -> V_4 )
F_15 ( V_2 ) ;
}
}
static void F_19 ( unsigned long V_57 )
{
struct V_1 * V_2 = (struct V_1 * ) V_57 ;
struct V_15 * V_16 = NULL ;
F_20 ( & V_2 -> V_58 ) ;
if ( V_2 && V_2 -> V_55 ) {
if ( V_2 -> V_55 -> V_50 & V_56 )
V_16 = V_2 -> V_5 ;
else
V_16 = V_2 -> V_4 ;
}
F_21 ( & V_2 -> V_58 ) ;
F_22 ( V_2 , V_59 ) ;
if ( V_16 )
F_23 ( V_16 ) ;
}
static void F_24 ( unsigned long V_60 )
{
struct V_1 * V_2 = (struct V_1 * ) V_60 ;
F_20 ( & V_2 -> V_58 ) ;
if ( ! V_2 -> V_55 )
goto V_61;
if ( V_2 -> V_55 -> V_50 & V_56 )
F_25 ( V_2 -> V_5 -> V_39 -> V_40 ,
V_2 -> V_11 , V_2 -> V_29 ,
V_41 ) ;
else
F_25 ( V_2 -> V_4 -> V_39 -> V_40 ,
V_2 -> V_11 , V_2 -> V_29 ,
V_52 ) ;
F_26 ( V_2 ) ;
V_61:
F_21 ( & V_2 -> V_58 ) ;
}
static bool F_27 ( struct V_15 * V_16 , void * V_60 )
{
F_12 ( V_16 -> V_39 -> V_40 , L_5 , V_46 , V_60 ) ;
V_16 -> V_62 = V_60 ;
return true ;
}
void F_28 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
if ( ! V_18 -> V_25 )
return;
if ( ! V_2 -> V_4 && ! V_2 -> V_5 ) {
T_2 V_63 ;
F_29 ( V_63 ) ;
F_30 ( V_64 , V_63 ) ;
V_2 -> V_4 = F_31 ( V_63 , F_27 ,
V_18 -> V_25 -> V_65 ) ;
F_12 ( & V_2 -> V_45 -> V_40 , L_6 , V_46 ,
V_2 -> V_4 ) ;
if ( ! V_2 -> V_4 )
return;
V_2 -> V_5 = F_31 ( V_63 , F_27 ,
V_18 -> V_25 -> V_66 ) ;
F_12 ( & V_2 -> V_45 -> V_40 , L_7 , V_46 ,
V_2 -> V_5 ) ;
if ( ! V_2 -> V_5 )
goto V_67;
V_2 -> V_38 = ( V_68 * ) F_32 ( V_69 | V_70 ) ;
if ( ! V_2 -> V_38 )
goto V_71;
F_33 ( & V_2 -> V_72 , F_24 , ( unsigned long ) V_2 ) ;
F_33 ( & V_2 -> V_73 , F_19 , ( unsigned long ) V_2 ) ;
}
F_1 ( V_2 , true ) ;
return;
V_71:
F_13 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_67:
F_13 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 ) {
struct V_15 * V_16 = V_2 -> V_4 ;
V_2 -> V_4 = NULL ;
F_13 ( V_16 ) ;
}
if ( V_2 -> V_5 ) {
struct V_15 * V_16 = V_2 -> V_5 ;
V_2 -> V_5 = NULL ;
F_13 ( V_16 ) ;
}
if ( V_2 -> V_38 ) {
F_35 ( ( unsigned long ) V_2 -> V_38 , 0 ) ;
V_2 -> V_38 = NULL ;
}
}
