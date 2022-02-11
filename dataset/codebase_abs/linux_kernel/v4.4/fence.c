unsigned F_1 ( unsigned V_1 )
{
F_2 ( ! V_1 ) ;
return F_3 ( V_1 , & V_2 ) - V_1 ;
}
int F_4 ( struct V_3 * V_3 )
{
struct V_4 * V_5 , * V_6 ;
int V_7 = 0 ;
if ( F_5 ( ! V_3 ) )
return - V_8 ;
if ( ! F_6 ( V_3 -> V_9 ) ) {
V_3 -> V_9 = F_7 () ;
F_8 () ;
}
if ( F_9 ( V_10 , & V_3 -> V_11 ) ) {
V_7 = - V_8 ;
} else
F_10 ( V_3 ) ;
F_11 (cur, tmp, &fence->cb_list, node) {
F_12 ( & V_5 -> V_12 ) ;
V_5 -> V_13 ( V_3 , V_5 ) ;
}
return V_7 ;
}
int F_13 ( struct V_3 * V_3 )
{
unsigned long V_11 ;
if ( ! V_3 )
return - V_8 ;
if ( ! F_6 ( V_3 -> V_9 ) ) {
V_3 -> V_9 = F_7 () ;
F_8 () ;
}
if ( F_9 ( V_10 , & V_3 -> V_11 ) )
return - V_8 ;
F_10 ( V_3 ) ;
if ( F_14 ( V_14 , & V_3 -> V_11 ) ) {
struct V_4 * V_5 , * V_6 ;
F_15 ( V_3 -> V_15 , V_11 ) ;
F_11 (cur, tmp, &fence->cb_list, node) {
F_12 ( & V_5 -> V_12 ) ;
V_5 -> V_13 ( V_3 , V_5 ) ;
}
F_16 ( V_3 -> V_15 , V_11 ) ;
}
return 0 ;
}
signed long
F_17 ( struct V_3 * V_3 , bool V_16 , signed long V_17 )
{
signed long V_7 ;
if ( F_5 ( V_17 < 0 ) )
return - V_8 ;
if ( V_17 == 0 )
return F_18 ( V_3 ) ;
F_19 ( V_3 ) ;
V_7 = V_3 -> V_18 -> V_19 ( V_3 , V_16 , V_17 ) ;
F_20 ( V_3 ) ;
return V_7 ;
}
void F_21 ( struct V_20 * V_20 )
{
struct V_3 * V_3 =
F_22 ( V_20 , struct V_3 , V_21 ) ;
F_23 ( V_3 ) ;
F_2 ( ! F_24 ( & V_3 -> V_22 ) ) ;
if ( V_3 -> V_18 -> V_23 )
V_3 -> V_18 -> V_23 ( V_3 ) ;
else
F_25 ( V_3 ) ;
}
void F_25 ( struct V_3 * V_3 )
{
F_26 ( V_3 , V_24 ) ;
}
void F_27 ( struct V_3 * V_3 )
{
unsigned long V_11 ;
if ( ! F_9 ( V_14 , & V_3 -> V_11 ) &&
! F_14 ( V_10 , & V_3 -> V_11 ) ) {
F_28 ( V_3 ) ;
F_15 ( V_3 -> V_15 , V_11 ) ;
if ( ! V_3 -> V_18 -> V_25 ( V_3 ) )
F_4 ( V_3 ) ;
F_16 ( V_3 -> V_15 , V_11 ) ;
}
}
int F_29 ( struct V_3 * V_3 , struct V_4 * V_26 ,
T_1 V_13 )
{
unsigned long V_11 ;
int V_7 = 0 ;
bool V_27 ;
if ( F_5 ( ! V_3 || ! V_13 ) )
return - V_8 ;
if ( F_14 ( V_10 , & V_3 -> V_11 ) ) {
F_30 ( & V_26 -> V_12 ) ;
return - V_28 ;
}
F_15 ( V_3 -> V_15 , V_11 ) ;
V_27 = F_9 ( V_14 , & V_3 -> V_11 ) ;
if ( F_14 ( V_10 , & V_3 -> V_11 ) )
V_7 = - V_28 ;
else if ( ! V_27 ) {
F_28 ( V_3 ) ;
if ( ! V_3 -> V_18 -> V_25 ( V_3 ) ) {
F_4 ( V_3 ) ;
V_7 = - V_28 ;
}
}
if ( ! V_7 ) {
V_26 -> V_13 = V_13 ;
F_31 ( & V_26 -> V_12 , & V_3 -> V_22 ) ;
} else
F_30 ( & V_26 -> V_12 ) ;
F_16 ( V_3 -> V_15 , V_11 ) ;
return V_7 ;
}
bool
F_32 ( struct V_3 * V_3 , struct V_4 * V_26 )
{
unsigned long V_11 ;
bool V_7 ;
F_15 ( V_3 -> V_15 , V_11 ) ;
V_7 = ! F_24 ( & V_26 -> V_12 ) ;
if ( V_7 )
F_12 ( & V_26 -> V_12 ) ;
F_16 ( V_3 -> V_15 , V_11 ) ;
return V_7 ;
}
static void
F_33 ( struct V_3 * V_3 , struct V_4 * V_26 )
{
struct V_29 * V_19 =
F_22 ( V_26 , struct V_29 , V_30 ) ;
F_34 ( V_19 -> V_31 , V_32 ) ;
}
signed long
F_35 ( struct V_3 * V_3 , bool V_16 , signed long V_17 )
{
struct V_29 V_26 ;
unsigned long V_11 ;
signed long V_7 = V_17 ;
bool V_27 ;
if ( F_14 ( V_10 , & V_3 -> V_11 ) )
return V_17 ;
F_15 ( V_3 -> V_15 , V_11 ) ;
if ( V_16 && F_36 ( V_33 ) ) {
V_7 = - V_34 ;
goto V_35;
}
V_27 = F_9 ( V_14 , & V_3 -> V_11 ) ;
if ( F_14 ( V_10 , & V_3 -> V_11 ) )
goto V_35;
if ( ! V_27 ) {
F_28 ( V_3 ) ;
if ( ! V_3 -> V_18 -> V_25 ( V_3 ) ) {
F_4 ( V_3 ) ;
goto V_35;
}
}
V_26 . V_30 . V_13 = F_33 ;
V_26 . V_31 = V_33 ;
F_37 ( & V_26 . V_30 . V_12 , & V_3 -> V_22 ) ;
while ( ! F_14 ( V_10 , & V_3 -> V_11 ) && V_7 > 0 ) {
if ( V_16 )
F_38 ( V_36 ) ;
else
F_38 ( V_37 ) ;
F_16 ( V_3 -> V_15 , V_11 ) ;
V_7 = F_39 ( V_7 ) ;
F_15 ( V_3 -> V_15 , V_11 ) ;
if ( V_7 > 0 && V_16 && F_36 ( V_33 ) )
V_7 = - V_34 ;
}
if ( ! F_24 ( & V_26 . V_30 . V_12 ) )
F_40 ( & V_26 . V_30 . V_12 ) ;
F_38 ( V_38 ) ;
V_35:
F_16 ( V_3 -> V_15 , V_11 ) ;
return V_7 ;
}
static bool
F_41 ( struct V_3 * * V_39 , T_2 V_40 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_40 ; ++ V_41 ) {
struct V_3 * V_3 = V_39 [ V_41 ] ;
if ( F_14 ( V_10 , & V_3 -> V_11 ) )
return true ;
}
return false ;
}
signed long
F_42 ( struct V_3 * * V_39 , T_2 V_40 ,
bool V_16 , signed long V_17 )
{
struct V_29 * V_26 ;
signed long V_7 = V_17 ;
unsigned V_41 ;
if ( F_5 ( ! V_39 || ! V_40 || V_17 < 0 ) )
return - V_8 ;
if ( V_17 == 0 ) {
for ( V_41 = 0 ; V_41 < V_40 ; ++ V_41 )
if ( F_18 ( V_39 [ V_41 ] ) )
return 1 ;
return 0 ;
}
V_26 = F_43 ( V_40 , sizeof( struct V_29 ) , V_42 ) ;
if ( V_26 == NULL ) {
V_7 = - V_43 ;
goto V_44;
}
for ( V_41 = 0 ; V_41 < V_40 ; ++ V_41 ) {
struct V_3 * V_3 = V_39 [ V_41 ] ;
if ( V_3 -> V_18 -> V_19 != F_35 ) {
V_7 = - V_8 ;
goto V_45;
}
V_26 [ V_41 ] . V_31 = V_33 ;
if ( F_29 ( V_3 , & V_26 [ V_41 ] . V_30 ,
F_33 ) ) {
goto V_45;
}
}
while ( V_7 > 0 ) {
if ( V_16 )
F_44 ( V_36 ) ;
else
F_44 ( V_37 ) ;
if ( F_41 ( V_39 , V_40 ) )
break;
V_7 = F_39 ( V_7 ) ;
if ( V_7 > 0 && V_16 && F_36 ( V_33 ) )
V_7 = - V_34 ;
}
F_38 ( V_38 ) ;
V_45:
while ( V_41 -- > 0 )
F_32 ( V_39 [ V_41 ] , & V_26 [ V_41 ] . V_30 ) ;
V_44:
F_45 ( V_26 ) ;
return V_7 ;
}
void
F_46 ( struct V_3 * V_3 , const struct V_46 * V_18 ,
T_3 * V_15 , unsigned V_47 , unsigned V_48 )
{
F_2 ( ! V_15 ) ;
F_2 ( ! V_18 || ! V_18 -> V_19 || ! V_18 -> V_25 ||
! V_18 -> V_49 || ! V_18 -> V_50 ) ;
F_47 ( & V_3 -> V_21 ) ;
V_3 -> V_18 = V_18 ;
F_30 ( & V_3 -> V_22 ) ;
V_3 -> V_15 = V_15 ;
V_3 -> V_47 = V_47 ;
V_3 -> V_48 = V_48 ;
V_3 -> V_11 = 0UL ;
F_48 ( V_3 ) ;
}
