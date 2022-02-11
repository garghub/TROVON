void F_1 ( struct V_1 * V_2 , bool V_3 )
{
if ( ! V_2 -> V_4 || ! V_2 -> V_5 )
return;
#if F_2 ( V_6 ) || F_2 ( V_7 )
F_3 ( V_2 , V_8 , V_3 ? 2 : 0 ) ;
#endif
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 , * V_12 ;
struct V_13 * V_14 = NULL ;
struct V_15 * V_16 = V_2 -> V_5 ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_19 ;
int V_20 , V_21 ;
bool V_22 = true , V_23 = true ;
unsigned int V_24 = ( 1 << V_18 -> V_25 -> V_26 ) - 1 ;
F_5 (sg, sg_tmp, host->sg_len, i) {
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
F_6 ( V_2 , V_36 ) ;
if ( ! V_22 ) {
F_7 ( & V_2 -> V_37 , V_2 -> V_38 , V_10 -> V_28 ) ;
V_2 -> V_11 = & V_2 -> V_37 ;
V_10 = V_2 -> V_11 ;
}
V_20 = F_8 ( V_16 -> V_39 -> V_40 , V_10 , V_2 -> V_29 , V_41 ) ;
if ( V_20 > 0 )
V_14 = V_16 -> V_39 -> V_42 ( V_16 , V_10 , V_20 ,
V_41 , V_43 ) ;
if ( V_14 ) {
V_19 = F_9 ( V_14 ) ;
if ( V_19 < 0 ) {
V_14 = NULL ;
V_20 = V_19 ;
}
}
F_10 ( & V_2 -> V_44 -> V_40 , L_1 ,
V_45 , V_2 -> V_29 , V_20 , V_19 , V_2 -> V_46 ) ;
V_33:
if ( ! V_14 ) {
if ( V_20 >= 0 )
V_20 = - V_47 ;
V_2 -> V_5 = NULL ;
F_11 ( V_16 ) ;
V_16 = V_2 -> V_4 ;
if ( V_16 ) {
V_2 -> V_4 = NULL ;
F_11 ( V_16 ) ;
}
F_12 ( & V_2 -> V_44 -> V_40 ,
L_2 , V_20 ) ;
F_1 ( V_2 , false ) ;
}
F_10 ( & V_2 -> V_44 -> V_40 , L_3 , V_45 ,
V_14 , V_19 , V_2 -> V_29 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 , * V_12 ;
struct V_13 * V_14 = NULL ;
struct V_15 * V_16 = V_2 -> V_4 ;
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 V_19 ;
int V_20 , V_21 ;
bool V_22 = true , V_23 = true ;
unsigned int V_24 = ( 1 << V_18 -> V_25 -> V_26 ) - 1 ;
F_5 (sg, sg_tmp, host->sg_len, i) {
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
F_6 ( V_2 , V_48 ) ;
if ( ! V_22 ) {
unsigned long V_49 ;
void * V_50 = F_14 ( V_10 , & V_49 ) ;
F_7 ( & V_2 -> V_37 , V_2 -> V_38 , V_10 -> V_28 ) ;
memcpy ( V_2 -> V_38 , V_50 , V_2 -> V_37 . V_28 ) ;
F_15 ( V_10 , & V_49 , V_50 ) ;
V_2 -> V_11 = & V_2 -> V_37 ;
V_10 = V_2 -> V_11 ;
}
V_20 = F_8 ( V_16 -> V_39 -> V_40 , V_10 , V_2 -> V_29 , V_51 ) ;
if ( V_20 > 0 )
V_14 = V_16 -> V_39 -> V_42 ( V_16 , V_10 , V_20 ,
V_51 , V_43 ) ;
if ( V_14 ) {
V_19 = F_9 ( V_14 ) ;
if ( V_19 < 0 ) {
V_14 = NULL ;
V_20 = V_19 ;
}
}
F_10 ( & V_2 -> V_44 -> V_40 , L_1 ,
V_45 , V_2 -> V_29 , V_20 , V_19 , V_2 -> V_46 ) ;
V_33:
if ( ! V_14 ) {
if ( V_20 >= 0 )
V_20 = - V_47 ;
V_2 -> V_4 = NULL ;
F_11 ( V_16 ) ;
V_16 = V_2 -> V_5 ;
if ( V_16 ) {
V_2 -> V_5 = NULL ;
F_11 ( V_16 ) ;
}
F_12 ( & V_2 -> V_44 -> V_40 ,
L_2 , V_20 ) ;
F_1 ( V_2 , false ) ;
}
F_10 ( & V_2 -> V_44 -> V_40 , L_4 , V_45 ,
V_14 , V_19 ) ;
}
void F_16 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
if ( V_53 -> V_49 & V_54 ) {
if ( V_2 -> V_5 )
F_4 ( V_2 ) ;
} else {
if ( V_2 -> V_4 )
F_13 ( V_2 ) ;
}
}
static void F_17 ( unsigned long V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_55 ;
struct V_15 * V_16 = NULL ;
F_18 ( & V_2 -> V_56 ) ;
if ( V_2 && V_2 -> V_53 ) {
if ( V_2 -> V_53 -> V_49 & V_54 )
V_16 = V_2 -> V_5 ;
else
V_16 = V_2 -> V_4 ;
}
F_19 ( & V_2 -> V_56 ) ;
F_20 ( V_2 , V_57 ) ;
if ( V_16 )
F_21 ( V_16 ) ;
}
static void F_22 ( unsigned long V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
F_18 ( & V_2 -> V_56 ) ;
if ( ! V_2 -> V_53 )
goto V_59;
if ( V_2 -> V_53 -> V_49 & V_54 )
F_23 ( V_2 -> V_5 -> V_39 -> V_40 ,
V_2 -> V_11 , V_2 -> V_29 ,
V_41 ) ;
else
F_23 ( V_2 -> V_4 -> V_39 -> V_40 ,
V_2 -> V_11 , V_2 -> V_29 ,
V_51 ) ;
F_24 ( V_2 ) ;
V_59:
F_19 ( & V_2 -> V_56 ) ;
}
static bool F_25 ( struct V_15 * V_16 , void * V_58 )
{
F_10 ( V_16 -> V_39 -> V_40 , L_5 , V_45 , V_58 ) ;
V_16 -> V_60 = V_58 ;
return true ;
}
void F_26 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
if ( ! V_18 -> V_25 )
return;
if ( ! V_2 -> V_4 && ! V_2 -> V_5 ) {
T_2 V_61 ;
F_27 ( V_61 ) ;
F_28 ( V_62 , V_61 ) ;
V_2 -> V_4 = F_29 ( V_61 , F_25 ,
V_18 -> V_25 -> V_63 ) ;
F_10 ( & V_2 -> V_44 -> V_40 , L_6 , V_45 ,
V_2 -> V_4 ) ;
if ( ! V_2 -> V_4 )
return;
V_2 -> V_5 = F_29 ( V_61 , F_25 ,
V_18 -> V_25 -> V_64 ) ;
F_10 ( & V_2 -> V_44 -> V_40 , L_7 , V_45 ,
V_2 -> V_5 ) ;
if ( ! V_2 -> V_5 )
goto V_65;
V_2 -> V_38 = ( V_66 * ) F_30 ( V_67 | V_68 ) ;
if ( ! V_2 -> V_38 )
goto V_69;
F_31 ( & V_2 -> V_70 , F_22 , ( unsigned long ) V_2 ) ;
F_31 ( & V_2 -> V_71 , F_17 , ( unsigned long ) V_2 ) ;
}
F_1 ( V_2 , true ) ;
return;
V_69:
F_11 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_65:
F_11 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
void F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 ) {
struct V_15 * V_16 = V_2 -> V_4 ;
V_2 -> V_4 = NULL ;
F_11 ( V_16 ) ;
}
if ( V_2 -> V_5 ) {
struct V_15 * V_16 = V_2 -> V_5 ;
V_2 -> V_5 = NULL ;
F_11 ( V_16 ) ;
}
if ( V_2 -> V_38 ) {
F_33 ( ( unsigned long ) V_2 -> V_38 , 0 ) ;
V_2 -> V_38 = NULL ;
}
}
