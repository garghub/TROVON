static void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 , * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
unsigned long V_11 ;
bool V_12 = false ;
int V_13 , V_14 ;
F_2 ( & V_2 -> V_15 , V_11 ) ;
if ( V_2 -> V_16 )
goto V_17;
if ( V_2 -> V_18 ) {
F_3 ( V_2 -> V_19 , & V_2 -> V_20 ) ;
goto V_17;
}
if ( ! F_4 ( & V_2 -> V_21 ) || ! V_2 -> V_22 ) {
if ( ! V_2 -> V_23 )
goto V_17;
if ( ! V_3 ) {
F_3 ( V_2 -> V_19 ,
& V_2 -> V_20 ) ;
goto V_17;
}
V_2 -> V_23 = false ;
V_2 -> V_18 = true ;
F_5 ( & V_2 -> V_15 , V_11 ) ;
if ( V_2 -> V_24 &&
V_2 -> V_24 ( V_2 ) )
F_6 ( V_2 -> V_25 , L_1 ) ;
F_2 ( & V_2 -> V_15 , V_11 ) ;
V_2 -> V_18 = false ;
goto V_17;
}
V_6 = F_7 ( & V_2 -> V_21 ) ;
V_5 = F_8 ( & V_2 -> V_21 ) ;
if ( ! V_5 )
goto V_17;
V_2 -> V_16 = V_5 ;
if ( V_6 )
V_6 -> V_26 ( V_6 , - V_27 ) ;
if ( V_2 -> V_23 )
V_12 = true ;
else
V_2 -> V_23 = true ;
F_5 ( & V_2 -> V_15 , V_11 ) ;
V_14 = F_9 ( V_2 -> V_16 -> V_28 ) ;
if ( ! V_12 && V_2 -> V_29 ) {
V_13 = V_2 -> V_29 ( V_2 ) ;
if ( V_13 ) {
F_6 ( V_2 -> V_25 , L_2 ) ;
goto V_30;
}
}
switch ( V_14 ) {
case V_31 :
V_8 = F_10 ( V_2 -> V_16 ) ;
if ( V_2 -> V_32 ) {
V_13 = V_2 -> V_32 ( V_2 , V_8 ) ;
if ( V_13 ) {
F_6 ( V_2 -> V_25 , L_3 ,
V_13 ) ;
goto V_30;
}
V_2 -> V_33 = true ;
}
V_13 = V_2 -> V_34 ( V_2 , V_8 ) ;
if ( V_13 ) {
F_6 ( V_2 -> V_25 , L_4 ) ;
goto V_30;
}
return;
case V_35 :
V_10 = F_11 ( V_2 -> V_16 ) ;
if ( V_2 -> V_36 ) {
V_13 = V_2 -> V_36 ( V_2 , V_10 ) ;
if ( V_13 ) {
F_6 ( V_2 -> V_25 , L_3 ,
V_13 ) ;
goto V_30;
}
V_2 -> V_33 = true ;
}
V_13 = V_2 -> V_37 ( V_2 , V_10 ) ;
if ( V_13 ) {
F_6 ( V_2 -> V_25 , L_5 ) ;
goto V_30;
}
return;
default:
F_6 ( V_2 -> V_25 , L_6 ) ;
return;
}
V_30:
switch ( V_14 ) {
case V_31 :
V_8 = F_10 ( V_2 -> V_16 ) ;
F_12 ( V_2 , V_8 , V_13 ) ;
break;
case V_35 :
V_10 = F_11 ( V_2 -> V_16 ) ;
F_13 ( V_2 , V_10 , V_13 ) ;
break;
}
return;
V_17:
F_5 ( & V_2 -> V_15 , V_11 ) ;
}
static void F_14 ( struct V_38 * V_39 )
{
struct V_1 * V_2 =
F_15 ( V_39 , struct V_1 , V_20 ) ;
F_1 ( V_2 , true ) ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_9 * V_40 ,
bool V_41 )
{
unsigned long V_11 ;
int V_13 ;
F_2 ( & V_2 -> V_15 , V_11 ) ;
if ( ! V_2 -> V_22 ) {
F_5 ( & V_2 -> V_15 , V_11 ) ;
return - V_42 ;
}
V_13 = F_17 ( & V_2 -> V_21 , V_40 ) ;
if ( ! V_2 -> V_23 && V_41 )
F_3 ( V_2 -> V_19 , & V_2 -> V_20 ) ;
F_5 ( & V_2 -> V_15 , V_11 ) ;
return V_13 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_9 * V_40 )
{
return F_16 ( V_2 , V_40 , true ) ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_7 * V_40 , bool V_41 )
{
unsigned long V_11 ;
int V_13 ;
F_2 ( & V_2 -> V_15 , V_11 ) ;
if ( ! V_2 -> V_22 ) {
F_5 ( & V_2 -> V_15 , V_11 ) ;
return - V_42 ;
}
V_13 = F_20 ( & V_2 -> V_21 , V_40 ) ;
if ( ! V_2 -> V_23 && V_41 )
F_3 ( V_2 -> V_19 , & V_2 -> V_20 ) ;
F_5 ( & V_2 -> V_15 , V_11 ) ;
return V_13 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_7 * V_40 )
{
return F_19 ( V_2 , V_40 , true ) ;
}
void F_13 ( struct V_1 * V_2 ,
struct V_9 * V_40 , int V_43 )
{
unsigned long V_11 ;
bool V_44 = false ;
int V_13 ;
F_2 ( & V_2 -> V_15 , V_11 ) ;
if ( V_2 -> V_16 == & V_40 -> V_45 )
V_44 = true ;
F_5 ( & V_2 -> V_15 , V_11 ) ;
if ( V_44 ) {
if ( V_2 -> V_33 &&
V_2 -> V_46 ) {
V_13 = V_2 -> V_46 ( V_2 , V_40 ) ;
if ( V_13 )
F_6 ( V_2 -> V_25 , L_7 ) ;
}
F_2 ( & V_2 -> V_15 , V_11 ) ;
V_2 -> V_16 = NULL ;
V_2 -> V_33 = false ;
F_5 ( & V_2 -> V_15 , V_11 ) ;
}
V_40 -> V_45 . V_26 ( & V_40 -> V_45 , V_43 ) ;
F_3 ( V_2 -> V_19 , & V_2 -> V_20 ) ;
}
void F_12 ( struct V_1 * V_2 ,
struct V_7 * V_40 , int V_43 )
{
unsigned long V_11 ;
bool V_44 = false ;
int V_13 ;
F_2 ( & V_2 -> V_15 , V_11 ) ;
if ( V_2 -> V_16 == & V_40 -> V_45 )
V_44 = true ;
F_5 ( & V_2 -> V_15 , V_11 ) ;
if ( V_44 ) {
if ( V_2 -> V_33 &&
V_2 -> V_47 ) {
V_13 = V_2 -> V_47 ( V_2 , V_40 ) ;
if ( V_13 )
F_6 ( V_2 -> V_25 , L_7 ) ;
}
F_2 ( & V_2 -> V_15 , V_11 ) ;
V_2 -> V_16 = NULL ;
V_2 -> V_33 = false ;
F_5 ( & V_2 -> V_15 , V_11 ) ;
}
V_40 -> V_45 . V_26 ( & V_40 -> V_45 , V_43 ) ;
F_3 ( V_2 -> V_19 , & V_2 -> V_20 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
F_2 ( & V_2 -> V_15 , V_11 ) ;
if ( V_2 -> V_22 || V_2 -> V_23 ) {
F_5 ( & V_2 -> V_15 , V_11 ) ;
return - V_48 ;
}
V_2 -> V_22 = true ;
F_5 ( & V_2 -> V_15 , V_11 ) ;
F_3 ( V_2 -> V_19 , & V_2 -> V_20 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
unsigned int V_49 = 500 ;
int V_13 = 0 ;
F_2 ( & V_2 -> V_15 , V_11 ) ;
while ( ( F_4 ( & V_2 -> V_21 ) || V_2 -> V_23 ) && V_49 -- ) {
F_5 ( & V_2 -> V_15 , V_11 ) ;
F_24 ( 20 ) ;
F_2 ( & V_2 -> V_15 , V_11 ) ;
}
if ( F_4 ( & V_2 -> V_21 ) || V_2 -> V_23 )
V_13 = - V_48 ;
else
V_2 -> V_22 = false ;
F_5 ( & V_2 -> V_15 , V_11 ) ;
if ( V_13 )
F_25 ( V_2 -> V_25 , L_8 ) ;
return V_13 ;
}
struct V_1 * F_26 ( struct V_50 * V_25 , bool V_51 )
{
struct V_52 V_53 = { . V_54 = V_55 - 1 } ;
struct V_1 * V_2 ;
if ( ! V_25 )
return NULL ;
V_2 = F_27 ( V_25 , sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_25 = V_25 ;
V_2 -> V_51 = V_51 ;
V_2 -> V_22 = false ;
V_2 -> V_23 = false ;
V_2 -> V_18 = false ;
V_2 -> V_33 = false ;
V_2 -> V_57 = V_25 ;
snprintf ( V_2 -> V_58 , sizeof( V_2 -> V_58 ) ,
L_9 , F_28 ( V_25 ) ) ;
F_29 ( & V_2 -> V_21 , V_59 ) ;
F_30 ( & V_2 -> V_15 ) ;
V_2 -> V_19 = F_31 ( 0 , L_10 , V_2 -> V_58 ) ;
if ( F_32 ( V_2 -> V_19 ) ) {
F_6 ( V_25 , L_11 ) ;
return NULL ;
}
F_33 ( & V_2 -> V_20 , F_14 ) ;
if ( V_2 -> V_51 ) {
F_34 ( V_25 , L_12 ) ;
F_35 ( V_2 -> V_19 -> V_60 , V_61 , & V_53 ) ;
}
return V_2 ;
}
int F_36 ( struct V_1 * V_2 )
{
int V_13 ;
V_13 = F_23 ( V_2 ) ;
if ( V_13 )
return V_13 ;
F_37 ( V_2 -> V_19 ) ;
return 0 ;
}
