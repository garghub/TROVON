T_1 F_1 ( unsigned V_1 )
{
F_2 ( ! V_1 ) ;
return F_3 ( V_1 , & V_2 ) - V_1 ;
}
int F_4 ( struct V_3 * V_4 )
{
struct V_5 * V_6 , * V_7 ;
int V_8 = 0 ;
F_5 ( V_4 -> V_9 ) ;
if ( F_6 ( ! V_4 ) )
return - V_10 ;
if ( ! F_7 ( V_4 -> V_11 ) ) {
V_4 -> V_11 = F_8 () ;
F_9 () ;
}
if ( F_10 ( V_12 , & V_4 -> V_13 ) ) {
V_8 = - V_10 ;
} else
F_11 ( V_4 ) ;
F_12 (cur, tmp, &fence->cb_list, node) {
F_13 ( & V_6 -> V_14 ) ;
V_6 -> V_15 ( V_4 , V_6 ) ;
}
return V_8 ;
}
int F_14 ( struct V_3 * V_4 )
{
unsigned long V_13 ;
if ( ! V_4 )
return - V_10 ;
if ( ! F_7 ( V_4 -> V_11 ) ) {
V_4 -> V_11 = F_8 () ;
F_9 () ;
}
if ( F_10 ( V_12 , & V_4 -> V_13 ) )
return - V_10 ;
F_11 ( V_4 ) ;
if ( F_15 ( V_16 , & V_4 -> V_13 ) ) {
struct V_5 * V_6 , * V_7 ;
F_16 ( V_4 -> V_9 , V_13 ) ;
F_12 (cur, tmp, &fence->cb_list, node) {
F_13 ( & V_6 -> V_14 ) ;
V_6 -> V_15 ( V_4 , V_6 ) ;
}
F_17 ( V_4 -> V_9 , V_13 ) ;
}
return 0 ;
}
signed long
F_18 ( struct V_3 * V_4 , bool V_17 , signed long V_18 )
{
signed long V_8 ;
if ( F_6 ( V_18 < 0 ) )
return - V_10 ;
F_19 ( V_4 ) ;
V_8 = V_4 -> V_19 -> V_20 ( V_4 , V_17 , V_18 ) ;
F_20 ( V_4 ) ;
return V_8 ;
}
void F_21 ( struct V_21 * V_21 )
{
struct V_3 * V_4 =
F_22 ( V_21 , struct V_3 , V_22 ) ;
F_23 ( V_4 ) ;
F_2 ( ! F_24 ( & V_4 -> V_23 ) ) ;
if ( V_4 -> V_19 -> V_24 )
V_4 -> V_19 -> V_24 ( V_4 ) ;
else
F_25 ( V_4 ) ;
}
void F_25 ( struct V_3 * V_4 )
{
F_26 ( V_4 , V_25 ) ;
}
void F_27 ( struct V_3 * V_4 )
{
unsigned long V_13 ;
if ( ! F_10 ( V_16 ,
& V_4 -> V_13 ) &&
! F_15 ( V_12 , & V_4 -> V_13 ) ) {
F_28 ( V_4 ) ;
F_16 ( V_4 -> V_9 , V_13 ) ;
if ( ! V_4 -> V_19 -> V_26 ( V_4 ) )
F_4 ( V_4 ) ;
F_17 ( V_4 -> V_9 , V_13 ) ;
}
}
int F_29 ( struct V_3 * V_4 , struct V_5 * V_27 ,
T_2 V_15 )
{
unsigned long V_13 ;
int V_8 = 0 ;
bool V_28 ;
if ( F_6 ( ! V_4 || ! V_15 ) )
return - V_10 ;
if ( F_15 ( V_12 , & V_4 -> V_13 ) ) {
F_30 ( & V_27 -> V_14 ) ;
return - V_29 ;
}
F_16 ( V_4 -> V_9 , V_13 ) ;
V_28 = F_10 ( V_16 ,
& V_4 -> V_13 ) ;
if ( F_15 ( V_12 , & V_4 -> V_13 ) )
V_8 = - V_29 ;
else if ( ! V_28 ) {
F_28 ( V_4 ) ;
if ( ! V_4 -> V_19 -> V_26 ( V_4 ) ) {
F_4 ( V_4 ) ;
V_8 = - V_29 ;
}
}
if ( ! V_8 ) {
V_27 -> V_15 = V_15 ;
F_31 ( & V_27 -> V_14 , & V_4 -> V_23 ) ;
} else
F_30 ( & V_27 -> V_14 ) ;
F_17 ( V_4 -> V_9 , V_13 ) ;
return V_8 ;
}
bool
F_32 ( struct V_3 * V_4 , struct V_5 * V_27 )
{
unsigned long V_13 ;
bool V_8 ;
F_16 ( V_4 -> V_9 , V_13 ) ;
V_8 = ! F_24 ( & V_27 -> V_14 ) ;
if ( V_8 )
F_13 ( & V_27 -> V_14 ) ;
F_17 ( V_4 -> V_9 , V_13 ) ;
return V_8 ;
}
static void
F_33 ( struct V_3 * V_4 , struct V_5 * V_27 )
{
struct V_30 * V_20 =
F_22 ( V_27 , struct V_30 , V_31 ) ;
F_34 ( V_20 -> V_32 , V_33 ) ;
}
signed long
F_35 ( struct V_3 * V_4 , bool V_17 , signed long V_18 )
{
struct V_30 V_27 ;
unsigned long V_13 ;
signed long V_8 = V_18 ? V_18 : 1 ;
bool V_28 ;
if ( F_15 ( V_12 , & V_4 -> V_13 ) )
return V_8 ;
F_16 ( V_4 -> V_9 , V_13 ) ;
if ( V_17 && F_36 ( V_34 ) ) {
V_8 = - V_35 ;
goto V_36;
}
V_28 = F_10 ( V_16 ,
& V_4 -> V_13 ) ;
if ( F_15 ( V_12 , & V_4 -> V_13 ) )
goto V_36;
if ( ! V_28 ) {
F_28 ( V_4 ) ;
if ( ! V_4 -> V_19 -> V_26 ( V_4 ) ) {
F_4 ( V_4 ) ;
goto V_36;
}
}
V_27 . V_31 . V_15 = F_33 ;
V_27 . V_32 = V_34 ;
F_37 ( & V_27 . V_31 . V_14 , & V_4 -> V_23 ) ;
while ( ! F_15 ( V_12 , & V_4 -> V_13 ) && V_8 > 0 ) {
if ( V_17 )
F_38 ( V_37 ) ;
else
F_38 ( V_38 ) ;
F_17 ( V_4 -> V_9 , V_13 ) ;
V_8 = F_39 ( V_8 ) ;
F_16 ( V_4 -> V_9 , V_13 ) ;
if ( V_8 > 0 && V_17 && F_36 ( V_34 ) )
V_8 = - V_35 ;
}
if ( ! F_24 ( & V_27 . V_31 . V_14 ) )
F_40 ( & V_27 . V_31 . V_14 ) ;
F_38 ( V_39 ) ;
V_36:
F_17 ( V_4 -> V_9 , V_13 ) ;
return V_8 ;
}
static bool
F_41 ( struct V_3 * * V_40 , T_3 V_41 ,
T_3 * V_42 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_41 ; ++ V_43 ) {
struct V_3 * V_4 = V_40 [ V_43 ] ;
if ( F_15 ( V_12 , & V_4 -> V_13 ) ) {
if ( V_42 )
* V_42 = V_43 ;
return true ;
}
}
return false ;
}
signed long
F_42 ( struct V_3 * * V_40 , T_3 V_41 ,
bool V_17 , signed long V_18 , T_3 * V_42 )
{
struct V_30 * V_27 ;
signed long V_8 = V_18 ;
unsigned V_43 ;
if ( F_6 ( ! V_40 || ! V_41 || V_18 < 0 ) )
return - V_10 ;
if ( V_18 == 0 ) {
for ( V_43 = 0 ; V_43 < V_41 ; ++ V_43 )
if ( F_43 ( V_40 [ V_43 ] ) ) {
if ( V_42 )
* V_42 = V_43 ;
return 1 ;
}
return 0 ;
}
V_27 = F_44 ( V_41 , sizeof( struct V_30 ) , V_44 ) ;
if ( V_27 == NULL ) {
V_8 = - V_45 ;
goto V_46;
}
for ( V_43 = 0 ; V_43 < V_41 ; ++ V_43 ) {
struct V_3 * V_4 = V_40 [ V_43 ] ;
if ( V_4 -> V_19 -> V_20 != F_35 ) {
V_8 = - V_10 ;
goto V_47;
}
V_27 [ V_43 ] . V_32 = V_34 ;
if ( F_29 ( V_4 , & V_27 [ V_43 ] . V_31 ,
F_33 ) ) {
if ( V_42 )
* V_42 = V_43 ;
goto V_47;
}
}
while ( V_8 > 0 ) {
if ( V_17 )
F_45 ( V_37 ) ;
else
F_45 ( V_38 ) ;
if ( F_41 ( V_40 , V_41 , V_42 ) )
break;
V_8 = F_39 ( V_8 ) ;
if ( V_8 > 0 && V_17 && F_36 ( V_34 ) )
V_8 = - V_35 ;
}
F_38 ( V_39 ) ;
V_47:
while ( V_43 -- > 0 )
F_32 ( V_40 [ V_43 ] , & V_27 [ V_43 ] . V_31 ) ;
V_46:
F_46 ( V_27 ) ;
return V_8 ;
}
void
F_47 ( struct V_3 * V_4 , const struct V_48 * V_19 ,
T_4 * V_9 , T_1 V_49 , unsigned V_50 )
{
F_2 ( ! V_9 ) ;
F_2 ( ! V_19 || ! V_19 -> V_20 || ! V_19 -> V_26 ||
! V_19 -> V_51 || ! V_19 -> V_52 ) ;
F_48 ( & V_4 -> V_22 ) ;
V_4 -> V_19 = V_19 ;
F_30 ( & V_4 -> V_23 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_49 = V_49 ;
V_4 -> V_50 = V_50 ;
V_4 -> V_13 = 0UL ;
F_49 ( V_4 ) ;
}
