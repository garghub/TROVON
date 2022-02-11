static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_3 -> V_4 ) ) {
F_3 ( V_5 L_1 ,
V_6 , F_4 ( & V_2 -> V_7 ) ) ;
return;
}
F_5 ( L_2 , F_6 ( V_2 ) ,
V_6 , V_2 -> V_8 -> V_9 ) ;
F_7 ( & V_2 -> V_3 -> V_4 , & V_2 -> V_8 -> V_3 -> V_10 ) ;
if ( V_2 -> V_11 )
F_8 ( & V_2 -> V_11 -> V_3 -> V_12 ,
V_13 , V_2 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_14 ;
if ( V_2 -> V_11 )
F_8 ( & V_2 -> V_11 -> V_3 -> V_12 ,
V_15 , V_2 ) ;
V_14 = F_10 ( & V_2 -> V_8 -> V_3 -> V_7 , & V_2 -> V_7 ,
F_4 ( & V_2 -> V_7 ) ) ;
if ( V_14 == 0 ) {
V_14 = F_10 ( & V_2 -> V_7 , & V_2 -> V_8 -> V_3 -> V_7 ,
L_3 ) ;
if ( V_14 )
F_11 ( & V_2 -> V_8 -> V_3 -> V_7 ,
F_4 ( & V_2 -> V_7 ) ) ;
}
return V_14 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_8 ;
if ( V_17 ) {
F_11 ( & V_17 -> V_3 -> V_7 , F_4 ( & V_2 -> V_7 ) ) ;
F_11 ( & V_2 -> V_7 , L_3 ) ;
}
}
int F_13 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_9 ( V_2 ) ;
if ( ! V_14 )
F_1 ( V_2 ) ;
return V_14 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
int V_14 = 0 ;
F_15 ( & V_18 ) ;
F_5 ( L_4 ,
V_17 -> V_11 -> V_9 , V_6 , V_17 -> V_9 , F_6 ( V_2 ) ) ;
F_16 ( ! F_17 ( & V_2 -> V_19 ) ) ;
V_2 -> V_8 = V_17 ;
if ( F_9 ( V_2 ) ) {
F_3 ( V_20 L_5 ,
V_6 , F_6 ( V_2 ) ) ;
goto V_21;
}
if ( V_2 -> V_11 -> V_22 ) {
V_14 = V_2 -> V_11 -> V_22 ( V_2 ) ;
if ( V_14 )
goto V_21;
} else if ( V_17 -> V_22 ) {
V_14 = V_17 -> V_22 ( V_2 ) ;
if ( V_14 )
goto V_21;
}
F_1 ( V_2 ) ;
V_14 = 1 ;
F_5 ( L_6 ,
V_17 -> V_11 -> V_9 , V_6 , F_6 ( V_2 ) , V_17 -> V_9 ) ;
goto V_23;
V_21:
F_18 ( V_2 ) ;
F_12 ( V_2 ) ;
V_2 -> V_8 = NULL ;
if ( V_14 != - V_24 && V_14 != - V_25 ) {
F_3 ( V_5
L_7 ,
V_17 -> V_9 , F_6 ( V_2 ) , V_14 ) ;
} else {
F_5 ( L_8 ,
V_17 -> V_9 , F_6 ( V_2 ) , V_14 ) ;
}
V_14 = 0 ;
V_23:
F_19 ( & V_18 ) ;
F_20 ( & V_26 ) ;
return V_14 ;
}
int F_21 ( void )
{
F_5 ( L_9 , V_6 ,
F_22 ( & V_18 ) ) ;
if ( F_22 ( & V_18 ) )
return - V_27 ;
return 0 ;
}
void F_23 ( void )
{
F_24 ( V_26 , F_22 ( & V_18 ) == 0 ) ;
F_25 () ;
}
int F_26 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
int V_14 = 0 ;
if ( ! F_27 ( V_2 ) )
return - V_24 ;
F_5 ( L_10 ,
V_17 -> V_11 -> V_9 , V_6 , F_6 ( V_2 ) , V_17 -> V_9 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
V_14 = F_14 ( V_2 , V_17 ) ;
F_30 ( V_2 ) ;
return V_14 ;
}
static int F_31 ( struct V_16 * V_17 , void * V_28 )
{
struct V_1 * V_2 = V_28 ;
if ( ! F_32 ( V_17 , V_2 ) )
return 0 ;
return F_26 ( V_17 , V_2 ) ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_14 = 0 ;
F_34 ( V_2 ) ;
if ( V_2 -> V_8 ) {
if ( F_2 ( & V_2 -> V_3 -> V_4 ) ) {
V_14 = 1 ;
goto V_29;
}
V_14 = F_13 ( V_2 ) ;
if ( V_14 == 0 )
V_14 = 1 ;
else {
V_2 -> V_8 = NULL ;
V_14 = 0 ;
}
} else {
F_28 ( V_2 ) ;
V_14 = F_35 ( V_2 -> V_11 , NULL , V_2 , F_31 ) ;
F_30 ( V_2 ) ;
}
V_29:
F_36 ( V_2 ) ;
return V_14 ;
}
static int F_37 ( struct V_1 * V_2 , void * V_28 )
{
struct V_16 * V_17 = V_28 ;
if ( ! F_32 ( V_17 , V_2 ) )
return 0 ;
if ( V_2 -> V_30 )
F_34 ( V_2 -> V_30 ) ;
F_34 ( V_2 ) ;
if ( ! V_2 -> V_8 )
F_26 ( V_17 , V_2 ) ;
F_36 ( V_2 ) ;
if ( V_2 -> V_30 )
F_36 ( V_2 -> V_30 ) ;
return 0 ;
}
int F_38 ( struct V_16 * V_17 )
{
return F_39 ( V_17 -> V_11 , NULL , V_17 , F_37 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
V_17 = V_2 -> V_8 ;
if ( V_17 ) {
F_41 ( V_2 ) ;
F_12 ( V_2 ) ;
if ( V_2 -> V_11 )
F_8 ( & V_2 -> V_11 -> V_3 -> V_12 ,
V_31 ,
V_2 ) ;
F_30 ( V_2 ) ;
if ( V_2 -> V_11 && V_2 -> V_11 -> remove )
V_2 -> V_11 -> remove ( V_2 ) ;
else if ( V_17 -> remove )
V_17 -> remove ( V_2 ) ;
F_18 ( V_2 ) ;
V_2 -> V_8 = NULL ;
F_42 ( & V_2 -> V_3 -> V_4 ) ;
if ( V_2 -> V_11 )
F_8 ( & V_2 -> V_11 -> V_3 -> V_12 ,
V_32 ,
V_2 ) ;
}
}
void F_43 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
F_40 ( V_2 ) ;
F_36 ( V_2 ) ;
}
void F_44 ( struct V_16 * V_17 )
{
struct V_33 * V_34 ;
struct V_1 * V_2 ;
for (; ; ) {
F_45 ( & V_17 -> V_3 -> V_10 . V_35 ) ;
if ( F_17 ( & V_17 -> V_3 -> V_10 . V_36 ) ) {
F_46 ( & V_17 -> V_3 -> V_10 . V_35 ) ;
break;
}
V_34 = F_47 ( V_17 -> V_3 -> V_10 . V_36 . V_37 ,
struct V_33 ,
V_4 . V_38 ) ;
V_2 = V_34 -> V_1 ;
F_48 ( V_2 ) ;
F_46 ( & V_17 -> V_3 -> V_10 . V_35 ) ;
if ( V_2 -> V_30 )
F_34 ( V_2 -> V_30 ) ;
F_34 ( V_2 ) ;
if ( V_2 -> V_8 == V_17 )
F_40 ( V_2 ) ;
F_36 ( V_2 ) ;
if ( V_2 -> V_30 )
F_36 ( V_2 -> V_30 ) ;
F_49 ( V_2 ) ;
}
}
void * F_50 ( const struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_3 )
return V_2 -> V_3 -> V_39 ;
return NULL ;
}
int F_51 ( struct V_1 * V_2 , void * V_28 )
{
int error ;
if ( ! V_2 -> V_3 ) {
error = F_52 ( V_2 ) ;
if ( error )
return error ;
}
V_2 -> V_3 -> V_39 = V_28 ;
return 0 ;
}
