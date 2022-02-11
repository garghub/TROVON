void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = NULL ;
V_2 -> V_4 = false ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
}
int F_2 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 = & V_2 -> V_14 ;
int V_15 ;
V_2 -> V_5 = V_6 ;
F_3 ( V_13 , V_2 ) ;
V_15 = F_4 ( V_13 , V_16 ) ;
if ( V_15 < 0 ) {
F_5 ( V_2 -> V_2 , L_1 , V_15 ) ;
return V_15 ;
}
V_15 = F_6 ( V_13 , V_11 , NULL ) ;
V_2 -> V_5 = V_6 ;
return V_15 ;
}
struct V_17 * F_7 ( struct V_1 * V_2 ,
struct V_18 * V_18 )
{
struct V_17 * V_19 ;
F_8 (cb, &dev->amthif_rd_complete_list.list, list)
if ( V_19 -> V_20 == V_18 )
return V_19 ;
return NULL ;
}
int F_9 ( struct V_1 * V_2 , struct V_18 * V_18 ,
char T_1 * V_21 , T_2 V_22 , T_3 * V_23 )
{
struct V_12 * V_13 = V_18 -> V_24 ;
struct V_17 * V_19 ;
unsigned long V_25 ;
int V_26 ;
int V_27 ;
if ( ! V_13 ) {
F_5 ( V_2 -> V_2 , L_2 ) ;
return - V_28 ;
}
F_10 ( V_2 -> V_2 , L_3 ) ;
V_19 = F_7 ( V_2 , V_18 ) ;
if ( V_19 == NULL && V_18 -> V_29 & V_30 )
return - V_31 ;
F_10 ( V_2 -> V_2 , L_4 ) ;
while ( V_19 == NULL ) {
F_11 ( & V_2 -> V_32 ) ;
V_27 = F_12 ( V_2 -> V_14 . V_33 ,
( V_19 = F_7 ( V_2 , V_18 ) ) ) ;
F_13 ( & V_2 -> V_32 ) ;
if ( V_27 )
return - V_34 ;
F_10 ( V_2 -> V_2 , L_5 ) ;
}
if ( V_19 -> V_35 ) {
V_26 = V_19 -> V_35 ;
F_10 ( V_2 -> V_2 , L_6 , V_26 ) ;
goto free;
}
F_10 ( V_2 -> V_2 , L_7 ) ;
V_2 -> V_7 = 0 ;
V_25 = V_19 -> V_36 +
F_14 ( V_37 ) ;
F_10 ( V_2 -> V_2 , L_8 ,
V_25 ) ;
if ( F_15 ( V_38 , V_25 ) ) {
F_10 ( V_2 -> V_2 , L_9 ) ;
F_16 ( & V_19 -> V_39 ) ;
V_26 = - V_28 ;
goto free;
}
if ( V_19 -> V_40 >= * V_23 && V_22 >= ( V_19 -> V_40 - * V_23 ) )
F_16 ( & V_19 -> V_39 ) ;
else if ( V_19 -> V_40 > 0 && V_19 -> V_40 <= * V_23 ) {
F_16 ( & V_19 -> V_39 ) ;
V_26 = 0 ;
goto free;
}
F_10 ( V_2 -> V_2 , L_10 ,
V_19 -> V_41 . V_42 ) ;
F_10 ( V_2 -> V_2 , L_11 , V_19 -> V_40 ) ;
V_22 = F_17 ( T_2 , V_22 , ( V_19 -> V_40 - * V_23 ) ) ;
if ( F_18 ( V_21 , V_19 -> V_41 . V_43 + * V_23 , V_22 ) ) {
F_10 ( V_2 -> V_2 , L_12 ) ;
V_26 = - V_44 ;
} else {
V_26 = V_22 ;
if ( ( * V_23 + V_22 ) < V_19 -> V_40 ) {
* V_23 += V_22 ;
goto V_45;
}
}
free:
F_10 ( V_2 -> V_2 , L_13 ) ;
* V_23 = 0 ;
F_19 ( V_19 ) ;
V_45:
return V_26 ;
}
static int F_20 ( struct V_12 * V_13 , struct V_18 * V_18 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_17 * V_19 ;
int V_26 ;
V_19 = F_21 ( V_13 , V_46 , V_18 ) ;
if ( ! V_19 ) {
V_26 = - V_47 ;
goto V_48;
}
V_26 = F_22 ( V_19 , F_23 ( V_13 ) ) ;
if ( V_26 )
goto V_48;
F_24 ( & V_19 -> V_39 , & V_2 -> V_49 . V_39 ) ;
V_2 -> V_5 = V_50 ;
V_2 -> V_51 = V_19 -> V_20 ;
V_2 -> V_3 = V_19 ;
return 0 ;
V_48:
F_19 ( V_19 ) ;
return V_26 ;
}
static int F_25 ( struct V_12 * V_13 , struct V_17 * V_19 )
{
struct V_1 * V_2 ;
int V_15 ;
if ( ! V_13 -> V_2 || ! V_19 )
return - V_52 ;
V_2 = V_13 -> V_2 ;
V_2 -> V_5 = V_53 ;
V_2 -> V_3 = V_19 ;
V_2 -> V_51 = V_19 -> V_20 ;
V_2 -> V_4 = false ;
V_15 = F_26 ( V_13 , V_19 , false ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_19 -> V_54 )
V_19 -> V_35 = F_20 ( V_13 , V_19 -> V_20 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = & V_2 -> V_14 ;
struct V_17 * V_19 ;
V_2 -> V_4 = false ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = 0 ;
V_2 -> V_51 = NULL ;
F_10 ( V_2 -> V_2 , L_14 ) ;
V_19 = F_28 ( & V_2 -> V_55 . V_39 ,
F_29 ( * V_19 ) , V_39 ) ;
if ( ! V_19 )
return 0 ;
F_16 ( & V_19 -> V_39 ) ;
return F_25 ( V_13 , V_19 ) ;
}
int F_30 ( struct V_12 * V_13 , struct V_17 * V_19 )
{
struct V_1 * V_2 ;
if ( F_31 ( ! V_13 || ! V_13 -> V_2 ) )
return - V_52 ;
if ( F_31 ( ! V_19 ) )
return - V_56 ;
V_2 = V_13 -> V_2 ;
F_24 ( & V_19 -> V_39 , & V_2 -> V_55 . V_39 ) ;
return F_27 ( V_2 ) ;
}
unsigned int F_32 ( struct V_1 * V_2 ,
struct V_18 * V_18 , T_4 * V_33 )
{
unsigned int V_57 = 0 ;
F_33 ( V_18 , & V_2 -> V_14 . V_33 , V_33 ) ;
if ( V_2 -> V_5 == V_58 &&
V_2 -> V_51 == V_18 ) {
V_57 |= V_59 | V_60 ;
F_27 ( V_2 ) ;
}
return V_57 ;
}
int F_34 ( struct V_12 * V_13 , struct V_17 * V_19 ,
struct V_17 * V_61 )
{
int V_15 ;
V_15 = F_35 ( V_13 , V_19 , V_61 ) ;
if ( V_15 )
return V_15 ;
if ( V_19 -> V_54 )
V_19 -> V_35 = F_20 ( V_13 , V_19 -> V_20 ) ;
return 0 ;
}
int F_36 ( struct V_12 * V_13 ,
struct V_62 * V_63 ,
struct V_17 * V_61 )
{
struct V_1 * V_2 ;
int V_15 ;
V_2 = V_13 -> V_2 ;
if ( V_2 -> V_5 != V_50 )
return 0 ;
V_15 = F_37 ( V_13 , V_63 , V_61 ) ;
if ( V_15 )
return V_15 ;
if ( ! V_63 -> V_64 )
return 0 ;
F_10 ( V_2 -> V_2 , L_15 ) ;
V_2 -> V_3 = NULL ;
V_2 -> V_8 = 0 ;
return 0 ;
}
void F_38 ( struct V_1 * V_2 , struct V_17 * V_19 )
{
if ( V_19 -> V_65 == V_66 ) {
if ( ! V_19 -> V_35 ) {
V_2 -> V_8 = V_67 ;
F_19 ( V_19 ) ;
return;
}
F_24 ( & V_19 -> V_39 , & V_2 -> V_68 . V_39 ) ;
F_39 ( & V_2 -> V_14 . V_33 ) ;
return;
}
if ( V_2 -> V_4 != 1 ) {
V_2 -> V_5 = V_58 ;
V_2 -> V_8 = 0 ;
F_24 ( & V_19 -> V_39 , & V_2 -> V_68 . V_39 ) ;
F_10 ( V_2 -> V_2 , L_16 ) ;
V_2 -> V_7 = V_38 ;
F_10 ( V_2 -> V_2 , L_17 ,
V_2 -> V_7 ) ;
} else {
F_27 ( V_2 ) ;
}
F_10 ( V_2 -> V_2 , L_18 ) ;
F_39 ( & V_2 -> V_14 . V_33 ) ;
}
static bool F_40 ( struct V_1 * V_2 ,
const struct V_18 * V_18 , struct V_69 * V_70 )
{
struct V_12 * V_13 = & V_2 -> V_14 ;
struct V_17 * V_19 , * V_71 ;
bool V_72 = false ;
F_41 (cb, next, mei_cb_list, list) {
if ( V_18 == V_19 -> V_20 ) {
if ( V_2 -> V_3 == V_19 ) {
V_2 -> V_3 = NULL ;
F_42 ( V_2 , V_13 ) ;
}
F_19 ( V_19 ) ;
V_72 = true ;
}
}
return V_72 ;
}
static bool F_43 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
bool V_72 = false ;
F_40 ( V_2 , V_18 , & V_2 -> V_55 . V_39 ) ;
if ( F_40 ( V_2 , V_18 , & V_2 -> V_68 . V_39 ) )
V_72 = true ;
F_40 ( V_2 , V_18 , & V_2 -> V_73 . V_39 ) ;
if ( F_40 ( V_2 , V_18 , & V_2 -> V_49 . V_39 ) )
V_72 = true ;
if ( F_40 ( V_2 , V_18 , & V_2 -> V_74 . V_39 ) )
V_72 = true ;
if ( F_40 ( V_2 , V_18 , & V_2 -> V_75 . V_39 ) )
V_72 = true ;
if ( V_2 -> V_3 && ! V_72 ) {
if ( V_2 -> V_3 -> V_20 == V_18 ) {
F_19 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_72 = true ;
}
}
return V_72 ;
}
int F_44 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
if ( V_2 -> V_9 > 0 )
V_2 -> V_9 -- ;
if ( V_2 -> V_51 == V_18 &&
V_2 -> V_5 != V_6 ) {
F_10 ( V_2 -> V_2 , L_19 ,
V_2 -> V_5 ) ;
V_2 -> V_4 = true ;
if ( V_2 -> V_5 == V_58 ) {
F_10 ( V_2 -> V_2 , L_20 ) ;
F_27 ( V_2 ) ;
}
}
if ( F_43 ( V_2 , V_18 ) )
V_2 -> V_5 = V_6 ;
return 0 ;
}
