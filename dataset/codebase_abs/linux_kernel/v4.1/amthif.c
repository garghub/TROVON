void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = NULL ;
V_2 -> V_4 = false ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
}
int F_2 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_12 ;
struct V_13 * V_14 ;
int V_15 ;
V_2 -> V_5 = V_6 ;
F_3 ( V_11 , V_2 ) ;
V_14 = F_4 ( V_2 , & V_16 ) ;
if ( ! V_14 ) {
F_5 ( V_2 -> V_2 , L_1 ) ;
return - V_17 ;
}
V_11 -> V_18 = V_14 -> V_19 ;
V_11 -> V_20 = V_14 -> V_21 . V_22 ;
V_2 -> V_23 = V_14 -> V_21 . V_24 ;
F_6 ( V_2 -> V_2 , L_2 , V_2 -> V_23 ) ;
V_15 = F_7 ( V_11 , V_25 ) ;
if ( V_15 < 0 ) {
F_8 ( V_2 -> V_2 , L_3 , V_15 ) ;
goto V_26;
}
V_15 = F_9 ( V_11 , NULL ) ;
V_2 -> V_5 = V_6 ;
V_26:
F_10 ( V_14 ) ;
return V_15 ;
}
struct V_27 * F_11 ( struct V_1 * V_2 ,
struct V_28 * V_28 )
{
struct V_27 * V_29 ;
F_12 (cb, &dev->amthif_rd_complete_list.list, list)
if ( V_29 -> V_30 == V_28 )
return V_29 ;
return NULL ;
}
int F_13 ( struct V_1 * V_2 , struct V_28 * V_28 ,
char T_1 * V_31 , T_2 V_32 , T_3 * V_33 )
{
struct V_10 * V_11 = V_28 -> V_34 ;
struct V_27 * V_29 ;
unsigned long V_35 ;
int V_36 ;
int V_37 ;
if ( ! V_11 ) {
F_8 ( V_2 -> V_2 , L_4 ) ;
return - V_38 ;
}
F_6 ( V_2 -> V_2 , L_5 ) ;
V_29 = F_11 ( V_2 , V_28 ) ;
if ( V_29 == NULL && V_28 -> V_39 & V_40 )
return - V_41 ;
F_6 ( V_2 -> V_2 , L_6 ) ;
while ( V_29 == NULL ) {
F_14 ( & V_2 -> V_42 ) ;
V_37 = F_15 ( V_2 -> V_12 . V_43 ,
( V_29 = F_11 ( V_2 , V_28 ) ) ) ;
F_16 ( & V_2 -> V_42 ) ;
if ( V_37 )
return - V_44 ;
F_6 ( V_2 -> V_2 , L_7 ) ;
}
if ( V_29 -> V_45 ) {
V_36 = V_29 -> V_45 ;
F_6 ( V_2 -> V_2 , L_8 , V_36 ) ;
goto free;
}
F_6 ( V_2 -> V_2 , L_9 ) ;
V_2 -> V_7 = 0 ;
V_35 = V_29 -> V_46 +
F_17 ( V_47 ) ;
F_6 ( V_2 -> V_2 , L_10 ,
V_35 ) ;
if ( F_18 ( V_48 , V_35 ) ) {
F_6 ( V_2 -> V_2 , L_11 ) ;
F_19 ( & V_29 -> V_49 ) ;
V_36 = - V_38 ;
goto free;
}
if ( V_29 -> V_50 >= * V_33 && V_32 >= ( V_29 -> V_50 - * V_33 ) )
F_19 ( & V_29 -> V_49 ) ;
else if ( V_29 -> V_50 > 0 && V_29 -> V_50 <= * V_33 ) {
F_19 ( & V_29 -> V_49 ) ;
V_36 = 0 ;
goto free;
}
F_6 ( V_2 -> V_2 , L_12 ,
V_29 -> V_51 . V_52 ) ;
F_6 ( V_2 -> V_2 , L_13 , V_29 -> V_50 ) ;
V_32 = F_20 ( T_2 , V_32 , ( V_29 -> V_50 - * V_33 ) ) ;
if ( F_21 ( V_31 , V_29 -> V_51 . V_53 + * V_33 , V_32 ) ) {
F_6 ( V_2 -> V_2 , L_14 ) ;
V_36 = - V_54 ;
} else {
V_36 = V_32 ;
if ( ( * V_33 + V_32 ) < V_29 -> V_50 ) {
* V_33 += V_32 ;
goto V_26;
}
}
free:
F_6 ( V_2 -> V_2 , L_15 ) ;
* V_33 = 0 ;
F_22 ( V_29 ) ;
V_26:
return V_36 ;
}
static int F_23 ( struct V_10 * V_11 , struct V_28 * V_28 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_27 * V_29 ;
T_2 V_32 = V_2 -> V_23 ;
int V_36 ;
V_29 = F_24 ( V_11 , V_55 , V_28 ) ;
if ( ! V_29 ) {
V_36 = - V_56 ;
goto V_57;
}
V_36 = F_25 ( V_29 , V_32 ) ;
if ( V_36 )
goto V_57;
F_26 ( & V_29 -> V_49 , & V_2 -> V_58 . V_49 ) ;
V_2 -> V_5 = V_59 ;
V_2 -> V_60 = V_29 -> V_30 ;
V_2 -> V_3 = V_29 ;
return 0 ;
V_57:
F_22 ( V_29 ) ;
return V_36 ;
}
static int F_27 ( struct V_10 * V_11 , struct V_27 * V_29 )
{
struct V_1 * V_2 ;
int V_15 ;
if ( ! V_11 -> V_2 || ! V_29 )
return - V_61 ;
V_2 = V_11 -> V_2 ;
V_2 -> V_5 = V_62 ;
V_2 -> V_3 = V_29 ;
V_2 -> V_60 = V_29 -> V_30 ;
V_2 -> V_4 = false ;
V_15 = F_28 ( V_11 , V_29 , false ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_29 -> V_63 )
V_29 -> V_45 = F_23 ( V_11 , V_29 -> V_30 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_12 ;
struct V_27 * V_29 ;
V_2 -> V_4 = false ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = 0 ;
V_2 -> V_60 = NULL ;
F_6 ( V_2 -> V_2 , L_16 ) ;
V_29 = F_30 ( & V_2 -> V_64 . V_49 ,
F_31 ( * V_29 ) , V_49 ) ;
if ( ! V_29 )
return 0 ;
F_19 ( & V_29 -> V_49 ) ;
return F_27 ( V_11 , V_29 ) ;
}
int F_32 ( struct V_10 * V_11 , struct V_27 * V_29 )
{
struct V_1 * V_2 ;
if ( F_33 ( ! V_11 || ! V_11 -> V_2 ) )
return - V_61 ;
if ( F_33 ( ! V_29 ) )
return - V_65 ;
V_2 = V_11 -> V_2 ;
F_26 ( & V_29 -> V_49 , & V_2 -> V_64 . V_49 ) ;
return F_29 ( V_2 ) ;
}
unsigned int F_34 ( struct V_1 * V_2 ,
struct V_28 * V_28 , T_4 * V_43 )
{
unsigned int V_66 = 0 ;
F_35 ( V_28 , & V_2 -> V_12 . V_43 , V_43 ) ;
if ( V_2 -> V_5 == V_67 &&
V_2 -> V_60 == V_28 ) {
V_66 |= V_68 | V_69 ;
F_29 ( V_2 ) ;
}
return V_66 ;
}
int F_36 ( struct V_10 * V_11 , struct V_27 * V_29 ,
struct V_27 * V_70 )
{
int V_15 ;
V_15 = F_37 ( V_11 , V_29 , V_70 ) ;
if ( V_15 )
return V_15 ;
if ( V_29 -> V_63 )
V_29 -> V_45 = F_23 ( V_11 , V_29 -> V_30 ) ;
return 0 ;
}
int F_38 ( struct V_10 * V_11 ,
struct V_71 * V_72 ,
struct V_27 * V_70 )
{
struct V_1 * V_2 ;
int V_15 ;
V_2 = V_11 -> V_2 ;
if ( V_2 -> V_5 != V_59 )
return 0 ;
V_15 = F_39 ( V_11 , V_72 , V_70 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_72 -> V_73 )
return 0 ;
F_6 ( V_2 -> V_2 , L_17 ) ;
V_2 -> V_3 = NULL ;
V_2 -> V_8 = 0 ;
return 0 ;
}
void F_40 ( struct V_1 * V_2 , struct V_27 * V_29 )
{
if ( V_29 -> V_74 == V_75 ) {
if ( ! V_29 -> V_45 ) {
V_2 -> V_8 = V_76 ;
F_22 ( V_29 ) ;
return;
}
F_26 ( & V_29 -> V_49 , & V_2 -> V_77 . V_49 ) ;
F_41 ( & V_2 -> V_12 . V_43 ) ;
return;
}
if ( V_2 -> V_4 != 1 ) {
V_2 -> V_5 = V_67 ;
V_2 -> V_8 = 0 ;
F_26 ( & V_29 -> V_49 , & V_2 -> V_77 . V_49 ) ;
F_6 ( V_2 -> V_2 , L_18 ) ;
V_2 -> V_7 = V_48 ;
F_6 ( V_2 -> V_2 , L_19 ,
V_2 -> V_7 ) ;
} else {
F_29 ( V_2 ) ;
}
F_6 ( V_2 -> V_2 , L_20 ) ;
F_41 ( & V_2 -> V_12 . V_43 ) ;
}
static bool F_42 ( struct V_1 * V_2 ,
const struct V_28 * V_28 , struct V_78 * V_79 )
{
struct V_10 * V_11 = & V_2 -> V_12 ;
struct V_27 * V_29 , * V_80 ;
bool V_81 = false ;
F_43 (cb, next, mei_cb_list, list) {
if ( V_28 == V_29 -> V_30 ) {
if ( V_2 -> V_3 == V_29 ) {
V_2 -> V_3 = NULL ;
F_44 ( V_2 , V_11 ) ;
}
F_22 ( V_29 ) ;
V_81 = true ;
}
}
return V_81 ;
}
static bool F_45 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
bool V_81 = false ;
F_42 ( V_2 , V_28 , & V_2 -> V_64 . V_49 ) ;
if ( F_42 ( V_2 , V_28 , & V_2 -> V_77 . V_49 ) )
V_81 = true ;
F_42 ( V_2 , V_28 , & V_2 -> V_82 . V_49 ) ;
if ( F_42 ( V_2 , V_28 , & V_2 -> V_58 . V_49 ) )
V_81 = true ;
if ( F_42 ( V_2 , V_28 , & V_2 -> V_83 . V_49 ) )
V_81 = true ;
if ( F_42 ( V_2 , V_28 , & V_2 -> V_84 . V_49 ) )
V_81 = true ;
if ( V_2 -> V_3 && ! V_81 ) {
if ( V_2 -> V_3 -> V_30 == V_28 ) {
F_22 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_81 = true ;
}
}
return V_81 ;
}
int F_46 ( struct V_1 * V_2 , struct V_28 * V_28 )
{
if ( V_2 -> V_9 > 0 )
V_2 -> V_9 -- ;
if ( V_2 -> V_60 == V_28 &&
V_2 -> V_5 != V_6 ) {
F_6 ( V_2 -> V_2 , L_21 ,
V_2 -> V_5 ) ;
V_2 -> V_4 = true ;
if ( V_2 -> V_5 == V_67 ) {
F_6 ( V_2 -> V_2 , L_22 ) ;
F_29 ( V_2 ) ;
}
}
if ( F_45 ( V_2 , V_28 ) )
V_2 -> V_5 = V_6 ;
return 0 ;
}
