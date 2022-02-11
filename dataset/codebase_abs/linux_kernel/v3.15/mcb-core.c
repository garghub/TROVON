static const struct V_1 * F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 ) {
while ( V_2 -> V_5 ) {
if ( V_2 -> V_5 == V_4 -> V_6 )
return V_2 ;
V_2 ++ ;
}
}
return NULL ;
}
static int F_2 ( struct V_5 * V_4 , struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_3 * V_11 = F_4 ( V_4 ) ;
const struct V_1 * V_12 ;
V_12 = F_1 ( V_10 -> V_13 , V_11 ) ;
if ( V_12 )
return 1 ;
return 0 ;
}
static int F_5 ( struct V_5 * V_4 , struct V_14 * V_15 )
{
struct V_3 * V_11 = F_4 ( V_4 ) ;
int V_16 ;
V_16 = F_6 ( V_15 , L_1 , V_11 -> V_6 ) ;
if ( V_16 )
return - V_17 ;
return 0 ;
}
static int F_7 ( struct V_5 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_4 -> V_18 ) ;
struct V_3 * V_11 = F_4 ( V_4 ) ;
const struct V_1 * V_12 ;
V_12 = F_1 ( V_10 -> V_13 , V_11 ) ;
if ( ! V_12 )
return - V_19 ;
return V_10 -> V_20 ( V_11 , V_12 ) ;
}
static int F_8 ( struct V_5 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_4 -> V_18 ) ;
struct V_3 * V_11 = F_4 ( V_4 ) ;
V_10 -> remove ( V_11 ) ;
F_9 ( & V_11 -> V_4 ) ;
return 0 ;
}
static void F_10 ( struct V_5 * V_4 )
{
struct V_3 * V_11 = F_4 ( V_4 ) ;
struct V_9 * V_10 = V_11 -> V_18 ;
if ( V_10 && V_10 -> V_21 )
V_10 -> V_21 ( V_11 ) ;
}
int F_11 ( struct V_9 * V_8 , struct V_22 * V_23 ,
const char * V_24 )
{
if ( ! V_8 -> V_20 || ! V_8 -> remove )
return - V_25 ;
V_8 -> V_18 . V_23 = V_23 ;
V_8 -> V_18 . V_26 = & V_27 ;
V_8 -> V_18 . V_24 = V_24 ;
return F_12 ( & V_8 -> V_18 ) ;
}
void F_13 ( struct V_9 * V_8 )
{
F_14 ( & V_8 -> V_18 ) ;
}
static void F_15 ( struct V_5 * V_4 )
{
struct V_3 * V_11 = F_4 ( V_4 ) ;
F_16 ( V_11 -> V_26 ) ;
F_17 ( V_11 ) ;
}
int F_18 ( struct V_28 * V_26 , struct V_3 * V_4 )
{
int V_16 ;
int V_29 ;
F_19 ( & V_4 -> V_4 ) ;
V_4 -> V_4 . V_26 = & V_27 ;
V_4 -> V_4 . V_30 = V_26 -> V_4 . V_30 ;
V_4 -> V_4 . V_31 = F_15 ;
V_29 = V_4 -> V_6 ;
F_20 ( & V_4 -> V_4 , L_2 ,
V_26 -> V_32 , V_29 , V_4 -> V_33 , V_4 -> V_34 , V_4 -> V_35 ) ;
V_16 = F_21 ( & V_4 -> V_4 ) ;
if ( V_16 < 0 ) {
F_22 ( L_3 ,
V_29 , V_26 -> V_32 , V_16 ) ;
goto V_36;
}
return 0 ;
V_36:
return V_16 ;
}
struct V_28 * F_23 ( void )
{
struct V_28 * V_26 ;
int V_32 ;
V_26 = F_24 ( sizeof( struct V_28 ) , V_37 ) ;
if ( ! V_26 )
return NULL ;
V_32 = F_25 ( & V_38 , 0 , 0 , V_37 ) ;
if ( V_32 < 0 ) {
F_17 ( V_26 ) ;
return F_26 ( V_32 ) ;
}
F_27 ( & V_26 -> V_39 ) ;
V_26 -> V_32 = V_32 ;
return V_26 ;
}
static int F_28 ( struct V_5 * V_4 , void * V_40 )
{
F_29 ( V_4 ) ;
return 0 ;
}
static void F_30 ( struct V_28 * V_26 )
{
F_31 ( & V_27 , NULL , NULL , F_28 ) ;
}
void F_32 ( struct V_28 * V_26 )
{
F_30 ( V_26 ) ;
F_33 ( & V_38 , V_26 -> V_32 ) ;
F_17 ( V_26 ) ;
}
struct V_28 * F_34 ( struct V_28 * V_26 )
{
if ( V_26 )
F_35 ( & V_26 -> V_4 ) ;
return V_26 ;
}
void F_16 ( struct V_28 * V_26 )
{
if ( V_26 )
F_9 ( & V_26 -> V_4 ) ;
}
struct V_3 * F_36 ( struct V_28 * V_26 )
{
struct V_3 * V_4 ;
V_4 = F_24 ( sizeof( struct V_3 ) , V_37 ) ;
if ( ! V_4 )
return NULL ;
F_27 ( & V_4 -> V_41 ) ;
V_4 -> V_26 = V_26 ;
return V_4 ;
}
void F_37 ( struct V_3 * V_4 )
{
F_17 ( V_4 ) ;
}
static int F_38 ( struct V_5 * V_4 , void * V_40 )
{
struct V_3 * V_11 = F_4 ( V_4 ) ;
int V_42 ;
if ( V_11 -> V_43 )
return 0 ;
V_42 = F_39 ( V_4 ) ;
if ( V_42 < 0 )
F_40 ( V_4 , L_4 , V_42 ) ;
V_11 -> V_43 = true ;
return 0 ;
}
static int F_41 ( struct V_5 * V_4 , void * V_40 )
{
struct V_3 * V_11 = F_4 ( V_4 ) ;
struct V_28 * V_44 ;
F_42 ( ! V_11 -> V_43 ) ;
V_44 = V_11 -> V_45 ;
if ( V_44 )
F_43 ( V_44 ) ;
return 0 ;
}
void F_43 ( const struct V_28 * V_26 )
{
F_31 ( & V_27 , NULL , NULL , F_38 ) ;
F_31 ( & V_27 , NULL , NULL , F_41 ) ;
}
struct V_46 * F_44 ( struct V_3 * V_4 , const char * V_47 )
{
struct V_46 * V_48 ;
T_1 V_49 ;
if ( ! V_47 )
V_47 = V_4 -> V_4 . V_18 -> V_47 ;
V_49 = F_45 ( & V_4 -> V_48 ) ;
V_48 = F_46 ( V_4 -> V_48 . V_50 , V_49 , V_47 ) ;
if ( ! V_48 )
return F_26 ( - V_51 ) ;
return V_48 ;
}
void F_47 ( struct V_46 * V_48 )
{
T_1 V_49 ;
V_49 = F_45 ( V_48 ) ;
F_48 ( V_48 -> V_50 , V_49 ) ;
}
int F_49 ( struct V_3 * V_4 )
{
struct V_46 * V_52 = & V_4 -> V_52 ;
return V_52 -> V_50 ;
}
static int F_50 ( void )
{
return F_51 ( & V_27 ) ;
}
static void F_52 ( void )
{
F_53 ( & V_27 ) ;
}
