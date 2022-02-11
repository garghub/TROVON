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
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 ;
if ( F_7 ( V_3 , V_2 -> V_16 ) ) {
F_4 ( V_2 , V_3 , V_5 ) ;
return 0 ;
}
if ( V_3 ) {
if ( V_2 -> V_17 ) {
V_10 = V_2 -> V_18 . V_19 ;
V_12 = V_10 -> V_12 ;
V_14 = V_10 -> V_14 ;
} else {
V_12 = V_2 -> V_18 . V_12 ;
V_14 = V_12 -> V_14 ;
}
if ( V_10 && ( V_14 -> V_20 & V_21 ) ) {
V_15 = V_14 -> V_22 -> V_23 ( V_14 , V_3 ) ;
if ( V_15 )
return V_15 ;
}
V_15 = F_8 ( V_12 , V_10 , V_14 -> V_24 , V_3 ) ;
if ( V_15 ) {
F_9 ( V_12 , L_1
L_2 ) ;
goto V_25;
}
}
F_5 ( V_3 , V_2 -> V_16 ) ;
V_2 -> V_26 ++ ;
F_4 ( V_2 , V_3 , V_5 ) ;
return 0 ;
V_25:
if ( V_10 && ( V_14 -> V_20 & V_21 ) )
V_14 -> V_22 -> V_27 ( V_14 , V_3 ) ;
return V_15 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! F_7 ( V_3 , V_2 -> V_16 ) )
return - V_28 ;
F_3 ( V_2 , V_3 ) ;
F_11 ( V_3 , V_2 -> V_8 ) ;
if ( V_2 -> V_17 && V_3 ) {
struct V_13 * V_14 = V_2 -> V_18 . V_19 -> V_14 ;
if ( V_14 -> V_20 & V_21 )
V_14 -> V_22 -> V_27 ( V_14 , V_3 ) ;
}
F_11 ( V_3 , V_2 -> V_16 ) ;
V_2 -> V_26 -- ;
if ( F_12 ( V_2 -> V_16 , V_29 ) ) {
if ( V_2 -> V_17 )
F_13 ( V_2 -> V_18 . V_19 -> V_30 , NULL ) ;
else
F_13 ( V_2 -> V_18 . V_12 -> V_30 , NULL ) ;
F_14 ( V_2 , V_31 ) ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_2 () ;
V_2 -> V_4 = 0 ;
F_16 ( V_2 -> V_16 , V_29 ) ;
if ( V_2 -> V_17 )
F_13 ( V_2 -> V_18 . V_19 -> V_30 , NULL ) ;
else
F_13 ( V_2 -> V_18 . V_12 -> V_30 , NULL ) ;
F_14 ( V_2 , V_31 ) ;
}
static struct V_32 * F_17 ( struct V_32 * V_33 )
{
if ( V_33 -> V_34 != F_18 ( V_35 ) ) {
V_33 -> V_36 = 0 ;
return V_33 ;
}
V_33 -> V_36 = 0 ;
V_33 = F_19 ( V_33 ) ;
if ( V_33 )
V_33 -> V_36 = 0 ;
return V_33 ;
}
struct V_32 * F_20 ( struct V_11 * V_12 ,
const struct V_1 * V_37 ,
struct V_32 * V_33 )
{
T_1 V_3 ;
if ( ! V_12 -> V_38 )
goto V_39;
F_21 ( V_33 , & V_3 ) ;
if ( F_7 ( V_3 , V_37 -> V_8 ) )
V_33 = F_17 ( V_33 ) ;
else {
if ( V_33 -> V_34 != F_18 ( V_35 ) &&
V_37 -> V_17 == 0 ) {
F_22 ( V_33 , V_40 ) ;
V_33 = F_23 ( V_33 , V_33 -> V_36 ) ;
if ( ! V_33 )
goto V_39;
F_24 ( V_33 , V_40 ) ;
V_33 -> V_36 = 0 ;
}
}
V_39:
return V_33 ;
}
bool F_25 ( struct V_11 * V_12 , struct V_1 * V_2 ,
struct V_32 * V_33 , T_1 * V_3 )
{
if ( ! V_12 -> V_38 )
return true ;
if ( ! V_2 )
return false ;
if ( F_21 ( V_33 , V_3 ) ) {
T_1 V_4 = F_26 ( V_2 ) ;
if ( V_4 == V_41 )
return false ;
F_27 ( V_33 , V_4 ) ;
return true ;
}
if ( F_7 ( * V_3 , V_2 -> V_16 ) )
return true ;
return false ;
}
bool F_28 ( struct V_11 * V_12 ,
const struct V_1 * V_2 ,
const struct V_32 * V_33 )
{
T_1 V_3 ;
if ( ! V_12 -> V_38 )
return true ;
if ( ! V_2 )
return false ;
F_21 ( V_33 , & V_3 ) ;
if ( F_7 ( V_3 , V_2 -> V_16 ) )
return true ;
return false ;
}
int F_29 ( struct V_11 * V_12 , T_1 V_3 , T_1 V_5 )
{
struct V_1 * V_37 = NULL ;
int V_15 ;
F_30 () ;
V_37 = F_31 ( V_12 -> V_30 ) ;
if ( V_37 )
return F_6 ( V_37 , V_3 , V_5 ) ;
V_37 = F_32 ( sizeof( * V_37 ) , V_42 ) ;
if ( ! V_37 )
return - V_43 ;
V_37 -> V_18 . V_12 = V_12 ;
V_15 = F_6 ( V_37 , V_3 , V_5 ) ;
if ( V_15 )
goto V_39;
F_13 ( V_12 -> V_30 , V_37 ) ;
return 0 ;
V_39:
F_33 ( V_37 ) ;
return V_15 ;
}
int F_34 ( struct V_11 * V_12 , T_1 V_3 )
{
struct V_1 * V_37 ;
F_30 () ;
V_37 = F_31 ( V_12 -> V_30 ) ;
if ( ! V_37 )
return - V_28 ;
if ( V_3 ) {
F_35 ( & V_12 -> V_44 ) ;
F_36 ( V_12 , V_12 -> V_14 -> V_24 , V_3 ) ;
F_37 ( & V_12 -> V_44 ) ;
}
F_10 ( V_37 , V_3 ) ;
return 0 ;
}
void F_38 ( struct V_11 * V_12 )
{
struct V_1 * V_37 ;
F_30 () ;
V_37 = F_31 ( V_12 -> V_30 ) ;
if ( ! V_37 )
return;
F_15 ( V_37 ) ;
}
int F_39 ( struct V_11 * V_12 , unsigned long V_45 )
{
if ( ! F_40 () )
return F_41 () ;
if ( V_12 -> V_38 == V_45 )
goto V_46;
V_12 -> V_38 = V_45 ;
V_46:
F_42 () ;
return 0 ;
}
int F_43 ( struct V_9 * V_19 , T_1 V_3 , T_1 V_5 )
{
struct V_1 * V_37 = NULL ;
int V_15 ;
F_30 () ;
V_37 = F_31 ( V_19 -> V_30 ) ;
if ( V_37 )
return F_6 ( V_37 , V_3 , V_5 ) ;
V_37 = F_32 ( sizeof( * V_37 ) , V_42 ) ;
if ( ! V_37 ) {
V_15 = - V_43 ;
goto V_47;
}
V_37 -> V_17 = V_19 -> V_48 ;
V_37 -> V_18 . V_19 = V_19 ;
V_15 = F_6 ( V_37 , V_3 , V_5 ) ;
if ( V_15 )
goto V_47;
F_13 ( V_19 -> V_30 , V_37 ) ;
return 0 ;
V_47:
F_33 ( V_37 ) ;
return V_15 ;
}
int F_44 ( struct V_9 * V_19 , T_1 V_3 )
{
struct V_1 * V_37 ;
F_30 () ;
V_37 = F_31 ( V_19 -> V_30 ) ;
if ( ! V_37 )
return - V_28 ;
if ( V_3 ) {
F_35 ( & V_19 -> V_12 -> V_44 ) ;
F_36 ( V_19 -> V_12 , V_19 -> V_14 -> V_24 , V_3 ) ;
F_37 ( & V_19 -> V_12 -> V_44 ) ;
}
return F_10 ( V_37 , V_3 ) ;
}
void F_45 ( struct V_9 * V_19 )
{
struct V_1 * V_37 ;
F_30 () ;
V_37 = F_31 ( V_19 -> V_30 ) ;
if ( ! V_37 )
return;
F_15 ( V_37 ) ;
}
bool F_46 ( struct V_9 * V_19 , T_1 V_3 )
{
struct V_1 * V_37 ;
bool V_49 = false ;
F_47 () ;
V_37 = F_48 ( V_19 -> V_30 ) ;
if ( ! V_37 )
goto V_39;
if ( F_7 ( V_3 , V_37 -> V_16 ) )
V_49 = true ;
V_39:
F_49 () ;
return V_49 ;
}
