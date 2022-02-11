static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 == V_3 )
return;
F_2 () ;
V_2 -> V_4 = V_3 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 != V_3 )
return;
F_2 () ;
V_2 -> V_4 = 0 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
if ( V_5 & V_6 )
F_1 ( V_2 , V_3 ) ;
if ( V_5 & V_7 )
F_5 ( V_3 , V_2 -> V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
const struct V_9 * V_10 ;
struct V_11 * V_12 = NULL ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int V_17 ;
if ( F_7 ( V_3 , V_2 -> V_18 ) ) {
F_4 ( V_2 , V_3 , V_5 ) ;
return 0 ;
}
if ( V_3 ) {
if ( V_2 -> V_19 ) {
V_12 = V_2 -> V_20 . V_21 ;
V_14 = V_12 -> V_14 ;
V_16 = V_12 -> V_16 ;
} else {
V_14 = V_2 -> V_20 . V_14 ;
V_16 = V_14 -> V_16 ;
}
V_10 = V_16 -> V_22 ;
if ( V_12 && ( V_16 -> V_23 & V_24 ) ) {
V_17 = V_10 -> V_25 ( V_16 , F_8 ( V_26 ) ,
V_3 ) ;
if ( V_17 )
return V_17 ;
}
V_17 = F_9 ( V_14 , V_12 , V_16 -> V_27 , V_3 ) ;
if ( V_17 ) {
F_10 ( V_14 , L_1
L_2 ) ;
goto V_28;
}
}
F_5 ( V_3 , V_2 -> V_18 ) ;
V_2 -> V_29 ++ ;
F_4 ( V_2 , V_3 , V_5 ) ;
return 0 ;
V_28:
if ( V_12 && ( V_16 -> V_23 & V_24 ) )
V_10 -> V_30 ( V_16 , F_8 ( V_26 ) , V_3 ) ;
return V_17 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! F_7 ( V_3 , V_2 -> V_18 ) )
return - V_31 ;
F_3 ( V_2 , V_3 ) ;
F_12 ( V_3 , V_2 -> V_8 ) ;
if ( V_2 -> V_19 && V_3 ) {
struct V_15 * V_16 = V_2 -> V_20 . V_21 -> V_16 ;
const struct V_9 * V_10 = V_16 -> V_22 ;
if ( V_16 -> V_23 & V_24 )
V_10 -> V_30 ( V_16 , F_8 ( V_26 ) , V_3 ) ;
}
F_12 ( V_3 , V_2 -> V_18 ) ;
V_2 -> V_29 -- ;
if ( F_13 ( V_2 -> V_18 , V_32 ) ) {
if ( V_2 -> V_19 )
F_14 ( V_2 -> V_20 . V_21 -> V_33 , NULL ) ;
else
F_14 ( V_2 -> V_20 . V_14 -> V_33 , NULL ) ;
F_15 ( V_2 , V_34 ) ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_2 () ;
V_2 -> V_4 = 0 ;
F_17 ( V_2 -> V_18 , V_32 ) ;
if ( V_2 -> V_19 )
F_14 ( V_2 -> V_20 . V_21 -> V_33 , NULL ) ;
else
F_14 ( V_2 -> V_20 . V_14 -> V_33 , NULL ) ;
F_15 ( V_2 , V_34 ) ;
}
static struct V_35 * F_18 ( struct V_35 * V_36 )
{
if ( V_36 -> V_37 != F_8 ( V_26 ) ) {
V_36 -> V_38 = 0 ;
return V_36 ;
}
V_36 -> V_38 = 0 ;
V_36 = F_19 ( V_36 ) ;
if ( V_36 )
V_36 -> V_38 = 0 ;
return V_36 ;
}
struct V_35 * F_20 ( struct V_13 * V_14 ,
const struct V_1 * V_39 ,
struct V_35 * V_36 )
{
T_1 V_3 ;
if ( ! V_14 -> V_40 )
goto V_41;
F_21 ( V_36 , & V_3 ) ;
if ( F_7 ( V_3 , V_39 -> V_8 ) )
V_36 = F_18 ( V_36 ) ;
else {
if ( V_36 -> V_37 != F_8 ( V_26 ) &&
V_39 -> V_19 == 0 ) {
F_22 ( V_36 , V_42 ) ;
V_36 = F_23 ( V_36 , V_36 -> V_43 , V_36 -> V_38 ) ;
if ( ! V_36 )
goto V_41;
F_24 ( V_36 , V_42 ) ;
V_36 -> V_38 = 0 ;
}
}
V_41:
return V_36 ;
}
bool F_25 ( struct V_13 * V_14 , struct V_1 * V_2 ,
struct V_35 * V_36 , T_1 * V_3 )
{
if ( ! V_14 -> V_40 )
return true ;
if ( ! V_2 )
return false ;
if ( F_21 ( V_36 , V_3 ) ) {
T_1 V_4 = F_26 ( V_2 ) ;
if ( V_4 == V_32 )
return false ;
F_27 ( V_36 , F_8 ( V_26 ) , V_4 ) ;
return true ;
}
if ( F_7 ( * V_3 , V_2 -> V_18 ) )
return true ;
return false ;
}
bool F_28 ( struct V_13 * V_14 ,
const struct V_1 * V_2 ,
const struct V_35 * V_36 )
{
T_1 V_3 ;
if ( ! V_14 -> V_40 )
return true ;
if ( ! V_2 )
return false ;
F_21 ( V_36 , & V_3 ) ;
if ( F_7 ( V_3 , V_2 -> V_18 ) )
return true ;
return false ;
}
int F_29 ( struct V_13 * V_14 , T_1 V_3 , T_1 V_5 )
{
struct V_1 * V_39 = NULL ;
int V_17 ;
F_30 () ;
V_39 = F_31 ( V_14 -> V_33 ) ;
if ( V_39 )
return F_6 ( V_39 , V_3 , V_5 ) ;
V_39 = F_32 ( sizeof( * V_39 ) , V_44 ) ;
if ( ! V_39 )
return - V_45 ;
V_39 -> V_20 . V_14 = V_14 ;
V_17 = F_6 ( V_39 , V_3 , V_5 ) ;
if ( V_17 )
goto V_41;
F_14 ( V_14 -> V_33 , V_39 ) ;
return 0 ;
V_41:
F_33 ( V_39 ) ;
return V_17 ;
}
int F_34 ( struct V_13 * V_14 , T_1 V_3 )
{
struct V_1 * V_39 ;
F_30 () ;
V_39 = F_31 ( V_14 -> V_33 ) ;
if ( ! V_39 )
return - V_31 ;
if ( V_3 ) {
F_35 ( & V_14 -> V_46 ) ;
F_36 ( V_14 , V_14 -> V_16 -> V_27 , V_3 ) ;
F_37 ( & V_14 -> V_46 ) ;
}
F_11 ( V_39 , V_3 ) ;
return 0 ;
}
void F_38 ( struct V_13 * V_14 )
{
struct V_1 * V_39 ;
F_30 () ;
V_39 = F_31 ( V_14 -> V_33 ) ;
if ( ! V_39 )
return;
F_16 ( V_39 ) ;
}
int F_39 ( struct V_13 * V_14 , unsigned long V_47 )
{
if ( ! F_40 () )
return F_41 () ;
if ( V_14 -> V_40 == V_47 )
goto V_48;
V_14 -> V_40 = V_47 ;
V_48:
F_42 () ;
return 0 ;
}
int F_43 ( struct V_11 * V_21 , T_1 V_3 , T_1 V_5 )
{
struct V_1 * V_39 = NULL ;
int V_17 ;
F_30 () ;
V_39 = F_31 ( V_21 -> V_33 ) ;
if ( V_39 )
return F_6 ( V_39 , V_3 , V_5 ) ;
V_39 = F_32 ( sizeof( * V_39 ) , V_44 ) ;
if ( ! V_39 ) {
V_17 = - V_45 ;
goto V_49;
}
V_39 -> V_19 = V_21 -> V_50 ;
V_39 -> V_20 . V_21 = V_21 ;
V_17 = F_6 ( V_39 , V_3 , V_5 ) ;
if ( V_17 )
goto V_49;
F_14 ( V_21 -> V_33 , V_39 ) ;
return 0 ;
V_49:
F_33 ( V_39 ) ;
return V_17 ;
}
int F_44 ( struct V_11 * V_21 , T_1 V_3 )
{
struct V_1 * V_39 ;
F_30 () ;
V_39 = F_31 ( V_21 -> V_33 ) ;
if ( ! V_39 )
return - V_31 ;
if ( V_3 ) {
F_35 ( & V_21 -> V_14 -> V_46 ) ;
F_36 ( V_21 -> V_14 , V_21 -> V_16 -> V_27 , V_3 ) ;
F_37 ( & V_21 -> V_14 -> V_46 ) ;
}
return F_11 ( V_39 , V_3 ) ;
}
void F_45 ( struct V_11 * V_21 )
{
struct V_1 * V_39 ;
F_30 () ;
V_39 = F_31 ( V_21 -> V_33 ) ;
if ( ! V_39 )
return;
F_16 ( V_39 ) ;
}
bool F_46 ( struct V_11 * V_21 , T_1 V_3 )
{
struct V_1 * V_39 ;
bool V_51 = false ;
F_47 () ;
V_39 = F_48 ( V_21 -> V_33 ) ;
if ( ! V_39 )
goto V_41;
if ( F_7 ( V_3 , V_39 -> V_18 ) )
V_51 = true ;
V_41:
F_49 () ;
return V_51 ;
}
