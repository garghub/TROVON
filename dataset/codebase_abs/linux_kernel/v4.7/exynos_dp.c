int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_7 ;
if ( ! V_7 -> V_8 )
return - V_9 ;
F_3 ( F_4 ( V_7 -> V_8 ) , V_3 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , true ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , false ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_5 -> V_11 ;
struct V_12 * V_13 ;
int V_14 = 0 ;
if ( V_5 -> V_2 . V_15 )
return V_14 ;
V_13 = F_8 ( V_11 -> V_16 ) ;
if ( ! V_13 ) {
F_9 ( L_1 ) ;
return V_14 ;
}
F_10 ( & V_5 -> V_17 , V_13 ) ;
V_11 -> V_18 . V_19 = V_13 -> V_19 ;
V_11 -> V_18 . V_20 = V_13 -> V_20 ;
V_13 -> type = V_21 | V_22 ;
F_11 ( V_13 ) ;
F_12 ( V_11 , V_13 ) ;
return V_14 + 1 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_10 * V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_7 ;
int V_25 ;
F_14 ( V_11 ) ;
V_5 -> V_11 = V_11 ;
if ( V_5 -> V_26 ) {
V_24 -> V_27 = V_5 -> V_26 ;
V_5 -> V_26 -> V_7 = V_7 ;
V_25 = F_15 ( V_7 -> V_16 , V_5 -> V_26 ) ;
if ( V_25 ) {
F_9 ( L_2 ) ;
V_24 -> V_27 = NULL ;
return V_25 ;
}
}
return 0 ;
}
static void F_16 ( struct V_6 * V_7 ,
struct V_12 * V_13 ,
struct V_12 * V_28 )
{
}
static void F_17 ( struct V_6 * V_7 )
{
}
static int F_18 ( struct V_4 * V_5 )
{
int V_25 ;
V_25 = F_19 ( V_5 -> V_16 -> V_29 , & V_5 -> V_17 , V_30 ) ;
if ( V_25 ) {
F_9 ( L_3 , V_25 ) ;
return V_25 ;
}
return 0 ;
}
static int F_20 ( struct V_31 * V_16 , struct V_31 * V_32 , void * V_33 )
{
struct V_4 * V_5 = F_21 ( V_16 ) ;
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_34 * V_35 = V_33 ;
int V_36 , V_25 ;
F_22 ( V_16 , NULL ) ;
V_5 -> V_16 = V_16 ;
V_5 -> V_35 = V_35 ;
V_5 -> V_2 . V_37 = V_38 ;
V_5 -> V_2 . V_39 = F_5 ;
V_5 -> V_2 . V_40 = F_6 ;
V_5 -> V_2 . V_41 = F_13 ;
V_5 -> V_2 . V_42 = F_7 ;
if ( ! V_5 -> V_2 . V_15 && ! V_5 -> V_26 ) {
V_25 = F_18 ( V_5 ) ;
if ( V_25 )
return V_25 ;
}
V_36 = F_23 ( V_35 ,
V_43 ) ;
if ( V_36 < 0 )
return V_36 ;
V_7 -> V_44 = 1 << V_36 ;
F_24 ( L_4 , V_7 -> V_44 ) ;
F_25 ( V_35 , V_7 , & V_45 ,
V_46 , NULL ) ;
F_26 ( V_7 , & V_47 ) ;
V_5 -> V_2 . V_7 = V_7 ;
return F_27 ( V_16 , V_5 -> V_35 , & V_5 -> V_2 ) ;
}
static void F_28 ( struct V_31 * V_16 , struct V_31 * V_32 ,
void * V_33 )
{
return F_29 ( V_16 , V_32 , V_33 ) ;
}
static int F_30 ( struct V_48 * V_49 )
{
struct V_31 * V_16 = & V_49 -> V_16 ;
struct V_50 * V_51 = NULL , * V_52 = NULL ;
struct V_4 * V_5 ;
V_5 = F_31 ( & V_49 -> V_16 , sizeof( struct V_4 ) ,
V_53 ) ;
if ( ! V_5 )
return - V_54 ;
F_32 ( V_49 , V_5 ) ;
V_51 = F_33 ( V_16 -> V_29 , L_5 , 0 ) ;
if ( V_51 ) {
V_5 -> V_2 . V_15 = F_34 ( V_51 ) ;
F_35 ( V_51 ) ;
if ( ! V_5 -> V_2 . V_15 )
return - V_55 ;
goto V_56;
}
V_52 = F_36 ( V_16 -> V_29 , NULL ) ;
if ( V_52 ) {
V_51 = F_37 ( V_52 ) ;
if ( V_51 ) {
V_5 -> V_2 . V_15 = F_34 ( V_51 ) ;
if ( ! V_5 -> V_2 . V_15 ) {
V_5 -> V_26 = F_38 ( V_51 ) ;
if ( ! V_5 -> V_26 ) {
F_35 ( V_51 ) ;
return - V_55 ;
}
}
F_35 ( V_51 ) ;
} else {
F_9 ( L_6 ) ;
return - V_57 ;
}
} else {
F_9 ( L_7 ) ;
return - V_57 ;
}
V_56:
return F_39 ( & V_49 -> V_16 , & V_58 ) ;
}
static int F_40 ( struct V_48 * V_49 )
{
F_41 ( & V_49 -> V_16 , & V_58 ) ;
return 0 ;
}
static int F_42 ( struct V_31 * V_16 )
{
return F_43 ( V_16 ) ;
}
static int F_44 ( struct V_31 * V_16 )
{
return F_45 ( V_16 ) ;
}
