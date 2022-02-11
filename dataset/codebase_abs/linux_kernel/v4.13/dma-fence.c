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
if ( F_7 ( V_11 , & V_4 -> V_12 ) ) {
V_8 = - V_10 ;
} else {
V_4 -> V_13 = F_8 () ;
F_9 ( V_14 , & V_4 -> V_12 ) ;
F_10 ( V_4 ) ;
}
F_11 (cur, tmp, &fence->cb_list, node) {
F_12 ( & V_6 -> V_15 ) ;
V_6 -> V_16 ( V_4 , V_6 ) ;
}
return V_8 ;
}
int F_13 ( struct V_3 * V_4 )
{
unsigned long V_12 ;
if ( ! V_4 )
return - V_10 ;
if ( F_7 ( V_11 , & V_4 -> V_12 ) )
return - V_10 ;
V_4 -> V_13 = F_8 () ;
F_9 ( V_14 , & V_4 -> V_12 ) ;
F_10 ( V_4 ) ;
if ( F_14 ( V_17 , & V_4 -> V_12 ) ) {
struct V_5 * V_6 , * V_7 ;
F_15 ( V_4 -> V_9 , V_12 ) ;
F_11 (cur, tmp, &fence->cb_list, node) {
F_12 ( & V_6 -> V_15 ) ;
V_6 -> V_16 ( V_4 , V_6 ) ;
}
F_16 ( V_4 -> V_9 , V_12 ) ;
}
return 0 ;
}
signed long
F_17 ( struct V_3 * V_4 , bool V_18 , signed long V_19 )
{
signed long V_8 ;
if ( F_6 ( V_19 < 0 ) )
return - V_10 ;
F_18 ( V_4 ) ;
V_8 = V_4 -> V_20 -> V_21 ( V_4 , V_18 , V_19 ) ;
F_19 ( V_4 ) ;
return V_8 ;
}
void F_20 ( struct V_22 * V_22 )
{
struct V_3 * V_4 =
F_21 ( V_22 , struct V_3 , V_23 ) ;
F_22 ( V_4 ) ;
F_2 ( ! F_23 ( & V_4 -> V_24 ) ) ;
if ( V_4 -> V_20 -> V_25 )
V_4 -> V_20 -> V_25 ( V_4 ) ;
else
F_24 ( V_4 ) ;
}
void F_24 ( struct V_3 * V_4 )
{
F_25 ( V_4 , V_26 ) ;
}
void F_26 ( struct V_3 * V_4 )
{
unsigned long V_12 ;
if ( ! F_7 ( V_17 ,
& V_4 -> V_12 ) &&
! F_14 ( V_11 , & V_4 -> V_12 ) ) {
F_27 ( V_4 ) ;
F_15 ( V_4 -> V_9 , V_12 ) ;
if ( ! V_4 -> V_20 -> V_27 ( V_4 ) )
F_4 ( V_4 ) ;
F_16 ( V_4 -> V_9 , V_12 ) ;
}
}
int F_28 ( struct V_3 * V_4 , struct V_5 * V_28 ,
T_2 V_16 )
{
unsigned long V_12 ;
int V_8 = 0 ;
bool V_29 ;
if ( F_6 ( ! V_4 || ! V_16 ) )
return - V_10 ;
if ( F_14 ( V_11 , & V_4 -> V_12 ) ) {
F_29 ( & V_28 -> V_15 ) ;
return - V_30 ;
}
F_15 ( V_4 -> V_9 , V_12 ) ;
V_29 = F_7 ( V_17 ,
& V_4 -> V_12 ) ;
if ( F_14 ( V_11 , & V_4 -> V_12 ) )
V_8 = - V_30 ;
else if ( ! V_29 ) {
F_27 ( V_4 ) ;
if ( ! V_4 -> V_20 -> V_27 ( V_4 ) ) {
F_4 ( V_4 ) ;
V_8 = - V_30 ;
}
}
if ( ! V_8 ) {
V_28 -> V_16 = V_16 ;
F_30 ( & V_28 -> V_15 , & V_4 -> V_24 ) ;
} else
F_29 ( & V_28 -> V_15 ) ;
F_16 ( V_4 -> V_9 , V_12 ) ;
return V_8 ;
}
int F_31 ( struct V_3 * V_4 )
{
unsigned long V_12 ;
int V_31 ;
F_15 ( V_4 -> V_9 , V_12 ) ;
V_31 = F_32 ( V_4 ) ;
F_16 ( V_4 -> V_9 , V_12 ) ;
return V_31 ;
}
bool
F_33 ( struct V_3 * V_4 , struct V_5 * V_28 )
{
unsigned long V_12 ;
bool V_8 ;
F_15 ( V_4 -> V_9 , V_12 ) ;
V_8 = ! F_23 ( & V_28 -> V_15 ) ;
if ( V_8 )
F_12 ( & V_28 -> V_15 ) ;
F_16 ( V_4 -> V_9 , V_12 ) ;
return V_8 ;
}
static void
F_34 ( struct V_3 * V_4 , struct V_5 * V_28 )
{
struct V_32 * V_21 =
F_21 ( V_28 , struct V_32 , V_33 ) ;
F_35 ( V_21 -> V_34 , V_35 ) ;
}
signed long
F_36 ( struct V_3 * V_4 , bool V_18 , signed long V_19 )
{
struct V_32 V_28 ;
unsigned long V_12 ;
signed long V_8 = V_19 ? V_19 : 1 ;
bool V_29 ;
if ( F_14 ( V_11 , & V_4 -> V_12 ) )
return V_8 ;
F_15 ( V_4 -> V_9 , V_12 ) ;
if ( V_18 && F_37 ( V_36 ) ) {
V_8 = - V_37 ;
goto V_38;
}
V_29 = F_7 ( V_17 ,
& V_4 -> V_12 ) ;
if ( F_14 ( V_11 , & V_4 -> V_12 ) )
goto V_38;
if ( ! V_29 ) {
F_27 ( V_4 ) ;
if ( ! V_4 -> V_20 -> V_27 ( V_4 ) ) {
F_4 ( V_4 ) ;
goto V_38;
}
}
if ( ! V_19 ) {
V_8 = 0 ;
goto V_38;
}
V_28 . V_33 . V_16 = F_34 ;
V_28 . V_34 = V_36 ;
F_38 ( & V_28 . V_33 . V_15 , & V_4 -> V_24 ) ;
while ( ! F_14 ( V_11 , & V_4 -> V_12 ) && V_8 > 0 ) {
if ( V_18 )
F_39 ( V_39 ) ;
else
F_39 ( V_40 ) ;
F_16 ( V_4 -> V_9 , V_12 ) ;
V_8 = F_40 ( V_8 ) ;
F_15 ( V_4 -> V_9 , V_12 ) ;
if ( V_8 > 0 && V_18 && F_37 ( V_36 ) )
V_8 = - V_37 ;
}
if ( ! F_23 ( & V_28 . V_33 . V_15 ) )
F_41 ( & V_28 . V_33 . V_15 ) ;
F_39 ( V_41 ) ;
V_38:
F_16 ( V_4 -> V_9 , V_12 ) ;
return V_8 ;
}
static bool
F_42 ( struct V_3 * * V_42 , T_3 V_43 ,
T_3 * V_44 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_43 ; ++ V_45 ) {
struct V_3 * V_4 = V_42 [ V_45 ] ;
if ( F_14 ( V_11 , & V_4 -> V_12 ) ) {
if ( V_44 )
* V_44 = V_45 ;
return true ;
}
}
return false ;
}
signed long
F_43 ( struct V_3 * * V_42 , T_3 V_43 ,
bool V_18 , signed long V_19 , T_3 * V_44 )
{
struct V_32 * V_28 ;
signed long V_8 = V_19 ;
unsigned V_45 ;
if ( F_6 ( ! V_42 || ! V_43 || V_19 < 0 ) )
return - V_10 ;
if ( V_19 == 0 ) {
for ( V_45 = 0 ; V_45 < V_43 ; ++ V_45 )
if ( F_44 ( V_42 [ V_45 ] ) ) {
if ( V_44 )
* V_44 = V_45 ;
return 1 ;
}
return 0 ;
}
V_28 = F_45 ( V_43 , sizeof( struct V_32 ) , V_46 ) ;
if ( V_28 == NULL ) {
V_8 = - V_47 ;
goto V_48;
}
for ( V_45 = 0 ; V_45 < V_43 ; ++ V_45 ) {
struct V_3 * V_4 = V_42 [ V_45 ] ;
if ( V_4 -> V_20 -> V_21 != F_36 ) {
V_8 = - V_10 ;
goto V_49;
}
V_28 [ V_45 ] . V_34 = V_36 ;
if ( F_28 ( V_4 , & V_28 [ V_45 ] . V_33 ,
F_34 ) ) {
if ( V_44 )
* V_44 = V_45 ;
goto V_49;
}
}
while ( V_8 > 0 ) {
if ( V_18 )
F_46 ( V_39 ) ;
else
F_46 ( V_40 ) ;
if ( F_42 ( V_42 , V_43 , V_44 ) )
break;
V_8 = F_40 ( V_8 ) ;
if ( V_8 > 0 && V_18 && F_37 ( V_36 ) )
V_8 = - V_37 ;
}
F_39 ( V_41 ) ;
V_49:
while ( V_45 -- > 0 )
F_33 ( V_42 [ V_45 ] , & V_28 [ V_45 ] . V_33 ) ;
V_48:
F_47 ( V_28 ) ;
return V_8 ;
}
void
F_48 ( struct V_3 * V_4 , const struct V_50 * V_20 ,
T_4 * V_9 , T_1 V_51 , unsigned V_52 )
{
F_2 ( ! V_9 ) ;
F_2 ( ! V_20 || ! V_20 -> V_21 || ! V_20 -> V_27 ||
! V_20 -> V_53 || ! V_20 -> V_54 ) ;
F_49 ( & V_4 -> V_23 ) ;
V_4 -> V_20 = V_20 ;
F_29 ( & V_4 -> V_24 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_51 = V_51 ;
V_4 -> V_52 = V_52 ;
V_4 -> V_12 = 0UL ;
V_4 -> error = 0 ;
F_50 ( V_4 ) ;
}
