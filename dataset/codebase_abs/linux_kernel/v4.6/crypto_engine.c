static void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 , * V_6 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
bool V_10 = false ;
int V_11 ;
F_2 ( & V_2 -> V_12 , V_9 ) ;
if ( V_2 -> V_13 )
goto V_14;
if ( V_2 -> V_15 ) {
F_3 ( & V_2 -> V_16 , & V_2 -> V_17 ) ;
goto V_14;
}
if ( ! F_4 ( & V_2 -> V_18 ) || ! V_2 -> V_19 ) {
if ( ! V_2 -> V_20 )
goto V_14;
if ( ! V_3 ) {
F_3 ( & V_2 -> V_16 ,
& V_2 -> V_17 ) ;
goto V_14;
}
V_2 -> V_20 = false ;
V_2 -> V_15 = true ;
F_5 ( & V_2 -> V_12 , V_9 ) ;
if ( V_2 -> V_21 &&
V_2 -> V_21 ( V_2 ) )
F_6 ( L_1 ) ;
F_2 ( & V_2 -> V_12 , V_9 ) ;
V_2 -> V_15 = false ;
goto V_14;
}
V_6 = F_7 ( & V_2 -> V_18 ) ;
V_5 = F_8 ( & V_2 -> V_18 ) ;
if ( ! V_5 )
goto V_14;
V_8 = F_9 ( V_5 ) ;
V_2 -> V_13 = V_8 ;
if ( V_6 )
V_6 -> V_22 ( V_6 , - V_23 ) ;
if ( V_2 -> V_20 )
V_10 = true ;
else
V_2 -> V_20 = true ;
F_5 ( & V_2 -> V_12 , V_9 ) ;
if ( ! V_10 && V_2 -> V_24 ) {
V_11 = V_2 -> V_24 ( V_2 ) ;
if ( V_11 ) {
F_6 ( L_2 ) ;
goto V_25;
}
}
if ( V_2 -> V_26 ) {
V_11 = V_2 -> V_26 ( V_2 , V_2 -> V_13 ) ;
if ( V_11 ) {
F_6 ( L_3 , V_11 ) ;
goto V_25;
}
V_2 -> V_27 = true ;
}
V_11 = V_2 -> V_28 ( V_2 , V_2 -> V_13 ) ;
if ( V_11 ) {
F_6 ( L_4 ) ;
goto V_25;
}
return;
V_25:
F_10 ( V_2 , V_2 -> V_13 , V_11 ) ;
return;
V_14:
F_5 ( & V_2 -> V_12 , V_9 ) ;
}
static void F_11 ( struct V_29 * V_30 )
{
struct V_1 * V_2 =
F_12 ( V_30 , struct V_1 , V_17 ) ;
F_1 ( V_2 , true ) ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_7 * V_8 , bool V_31 )
{
unsigned long V_9 ;
int V_11 ;
F_2 ( & V_2 -> V_12 , V_9 ) ;
if ( ! V_2 -> V_19 ) {
F_5 ( & V_2 -> V_12 , V_9 ) ;
return - V_32 ;
}
V_11 = F_14 ( & V_2 -> V_18 , V_8 ) ;
if ( ! V_2 -> V_20 && V_31 )
F_3 ( & V_2 -> V_16 , & V_2 -> V_17 ) ;
F_5 ( & V_2 -> V_12 , V_9 ) ;
return V_11 ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
return F_13 ( V_2 , V_8 , true ) ;
}
void F_10 ( struct V_1 * V_2 ,
struct V_7 * V_8 , int V_33 )
{
unsigned long V_9 ;
bool V_34 = false ;
int V_11 ;
F_2 ( & V_2 -> V_12 , V_9 ) ;
if ( V_2 -> V_13 == V_8 )
V_34 = true ;
F_5 ( & V_2 -> V_12 , V_9 ) ;
if ( V_34 ) {
if ( V_2 -> V_27 && V_2 -> V_35 ) {
V_11 = V_2 -> V_35 ( V_2 , V_8 ) ;
if ( V_11 )
F_6 ( L_5 ) ;
}
F_2 ( & V_2 -> V_12 , V_9 ) ;
V_2 -> V_13 = NULL ;
V_2 -> V_27 = false ;
F_5 ( & V_2 -> V_12 , V_9 ) ;
}
V_8 -> V_36 . V_22 ( & V_8 -> V_36 , V_33 ) ;
F_3 ( & V_2 -> V_16 , & V_2 -> V_17 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
F_2 ( & V_2 -> V_12 , V_9 ) ;
if ( V_2 -> V_19 || V_2 -> V_20 ) {
F_5 ( & V_2 -> V_12 , V_9 ) ;
return - V_37 ;
}
V_2 -> V_19 = true ;
F_5 ( & V_2 -> V_12 , V_9 ) ;
F_3 ( & V_2 -> V_16 , & V_2 -> V_17 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
unsigned V_38 = 500 ;
int V_11 = 0 ;
F_2 ( & V_2 -> V_12 , V_9 ) ;
while ( ( F_4 ( & V_2 -> V_18 ) || V_2 -> V_20 ) && V_38 -- ) {
F_5 ( & V_2 -> V_12 , V_9 ) ;
F_18 ( 20 ) ;
F_2 ( & V_2 -> V_12 , V_9 ) ;
}
if ( F_4 ( & V_2 -> V_18 ) || V_2 -> V_20 )
V_11 = - V_37 ;
else
V_2 -> V_19 = false ;
F_5 ( & V_2 -> V_12 , V_9 ) ;
if ( V_11 )
F_19 ( L_6 ) ;
return V_11 ;
}
struct V_1 * F_20 ( struct V_39 * V_40 , bool V_41 )
{
struct V_42 V_43 = { . V_44 = V_45 - 1 } ;
struct V_1 * V_2 ;
if ( ! V_40 )
return NULL ;
V_2 = F_21 ( V_40 , sizeof( * V_2 ) , V_46 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_41 = V_41 ;
V_2 -> V_19 = false ;
V_2 -> V_20 = false ;
V_2 -> V_15 = false ;
V_2 -> V_27 = false ;
V_2 -> V_47 = V_40 ;
snprintf ( V_2 -> V_48 , sizeof( V_2 -> V_48 ) ,
L_7 , F_22 ( V_40 ) ) ;
F_23 ( & V_2 -> V_18 , V_49 ) ;
F_24 ( & V_2 -> V_12 ) ;
F_25 ( & V_2 -> V_16 ) ;
V_2 -> V_50 = F_26 ( V_51 ,
& V_2 -> V_16 , L_8 ,
V_2 -> V_48 ) ;
if ( F_27 ( V_2 -> V_50 ) ) {
F_28 ( V_40 , L_9 ) ;
return NULL ;
}
F_29 ( & V_2 -> V_17 , F_11 ) ;
if ( V_2 -> V_41 ) {
F_30 ( V_40 , L_10 ) ;
F_31 ( V_2 -> V_50 , V_52 , & V_43 ) ;
}
return V_2 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_17 ( V_2 ) ;
if ( V_11 )
return V_11 ;
F_33 ( & V_2 -> V_16 ) ;
F_34 ( V_2 -> V_50 ) ;
return 0 ;
}
