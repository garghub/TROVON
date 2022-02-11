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
struct V_19 * V_20 ;
int V_16 ;
V_12 = F_1 ( V_10 -> V_13 , V_11 ) ;
if ( ! V_12 )
return - V_21 ;
V_20 = V_11 -> V_4 . V_22 -> V_18 -> V_23 ;
if ( ! F_8 ( V_20 ) )
return - V_24 ;
F_9 ( V_4 ) ;
V_16 = V_10 -> V_25 ( V_11 , V_12 ) ;
if ( V_16 )
F_10 ( V_20 ) ;
return V_16 ;
}
static int F_11 ( struct V_5 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_4 -> V_18 ) ;
struct V_3 * V_11 = F_4 ( V_4 ) ;
struct V_19 * V_20 ;
V_10 -> remove ( V_11 ) ;
V_20 = V_11 -> V_4 . V_22 -> V_18 -> V_23 ;
F_10 ( V_20 ) ;
F_12 ( & V_11 -> V_4 ) ;
return 0 ;
}
static void F_13 ( struct V_5 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_4 -> V_18 ) ;
struct V_3 * V_11 = F_4 ( V_4 ) ;
if ( V_10 && V_10 -> V_26 )
V_10 -> V_26 ( V_11 ) ;
}
static T_1 F_14 ( struct V_5 * V_4 , struct V_27 * V_28 ,
char * V_29 )
{
struct V_30 * V_31 = F_15 ( V_4 ) ;
return F_16 ( V_29 , V_32 , L_2 , V_31 -> V_33 ) ;
}
static T_1 F_17 ( struct V_5 * V_4 , struct V_27 * V_28 ,
char * V_29 )
{
struct V_30 * V_31 = F_15 ( V_4 ) ;
return F_16 ( V_29 , V_32 , L_3 , V_31 -> V_34 ) ;
}
static T_1 F_18 ( struct V_5 * V_4 , struct V_27 * V_28 ,
char * V_29 )
{
struct V_30 * V_31 = F_15 ( V_4 ) ;
return F_16 ( V_29 , V_32 , L_2 , V_31 -> V_35 ) ;
}
static T_1 F_19 ( struct V_5 * V_4 , struct V_27 * V_28 ,
char * V_29 )
{
struct V_30 * V_31 = F_15 ( V_4 ) ;
return F_16 ( V_29 , V_32 , L_4 , V_31 -> V_36 ) ;
}
int F_20 ( struct V_9 * V_8 , struct V_19 * V_23 ,
const char * V_37 )
{
if ( ! V_8 -> V_25 || ! V_8 -> remove )
return - V_24 ;
V_8 -> V_18 . V_23 = V_23 ;
V_8 -> V_18 . V_31 = & V_38 ;
V_8 -> V_18 . V_37 = V_37 ;
return F_21 ( & V_8 -> V_18 ) ;
}
void F_22 ( struct V_9 * V_8 )
{
F_23 ( & V_8 -> V_18 ) ;
}
static void F_24 ( struct V_5 * V_4 )
{
struct V_3 * V_11 = F_4 ( V_4 ) ;
F_25 ( V_11 -> V_31 ) ;
F_26 ( V_11 ) ;
}
int F_27 ( struct V_30 * V_31 , struct V_3 * V_4 )
{
int V_16 ;
int V_39 ;
F_28 ( & V_4 -> V_4 ) ;
F_29 ( V_31 ) ;
V_4 -> V_4 . V_31 = & V_38 ;
V_4 -> V_4 . V_22 = V_31 -> V_4 . V_22 ;
V_4 -> V_4 . V_40 = F_24 ;
V_4 -> V_41 = V_31 -> V_42 ;
V_39 = V_4 -> V_6 ;
F_30 ( & V_4 -> V_4 , L_5 ,
V_31 -> V_43 , V_39 , V_4 -> V_44 , V_4 -> V_45 , V_4 -> V_46 ) ;
V_16 = F_31 ( & V_4 -> V_4 ) ;
if ( V_16 < 0 ) {
F_32 ( L_6 ,
V_39 , V_31 -> V_43 , V_16 ) ;
goto V_47;
}
return 0 ;
V_47:
return V_16 ;
}
static void F_33 ( struct V_5 * V_4 )
{
struct V_30 * V_31 = F_15 ( V_4 ) ;
F_12 ( V_31 -> V_42 ) ;
F_34 ( & V_48 , V_31 -> V_43 ) ;
F_26 ( V_31 ) ;
}
struct V_30 * F_35 ( struct V_5 * V_42 )
{
struct V_30 * V_31 ;
int V_43 ;
int V_49 ;
V_31 = F_36 ( sizeof( struct V_30 ) , V_50 ) ;
if ( ! V_31 )
return F_37 ( - V_17 ) ;
V_43 = F_38 ( & V_48 , 0 , 0 , V_50 ) ;
if ( V_43 < 0 ) {
V_49 = V_43 ;
goto V_51;
}
V_31 -> V_43 = V_43 ;
V_31 -> V_42 = F_9 ( V_42 ) ;
F_28 ( & V_31 -> V_4 ) ;
V_31 -> V_4 . V_22 = V_42 ;
V_31 -> V_4 . V_31 = & V_38 ;
V_31 -> V_4 . type = & V_52 ;
V_31 -> V_4 . V_40 = & F_33 ;
F_30 ( & V_31 -> V_4 , L_7 , V_43 ) ;
V_49 = F_31 ( & V_31 -> V_4 ) ;
if ( V_49 )
goto V_51;
return V_31 ;
V_51:
F_12 ( V_42 ) ;
F_26 ( V_31 ) ;
return F_37 ( V_49 ) ;
}
static int F_39 ( struct V_5 * V_4 , void * V_53 )
{
F_40 ( V_4 ) ;
return 0 ;
}
static void F_41 ( struct V_30 * V_31 )
{
F_42 ( & V_38 , NULL , NULL , F_39 ) ;
}
void F_43 ( struct V_30 * V_31 )
{
F_41 ( V_31 ) ;
}
struct V_30 * F_29 ( struct V_30 * V_31 )
{
if ( V_31 )
F_9 ( & V_31 -> V_4 ) ;
return V_31 ;
}
void F_25 ( struct V_30 * V_31 )
{
if ( V_31 )
F_12 ( & V_31 -> V_4 ) ;
}
struct V_3 * F_44 ( struct V_30 * V_31 )
{
struct V_3 * V_4 ;
V_4 = F_36 ( sizeof( struct V_3 ) , V_50 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_31 = V_31 ;
return V_4 ;
}
void F_45 ( struct V_3 * V_4 )
{
F_26 ( V_4 ) ;
}
static int F_46 ( struct V_5 * V_4 , void * V_53 )
{
struct V_3 * V_11 = F_4 ( V_4 ) ;
int V_54 ;
if ( V_11 -> V_55 )
return 0 ;
V_54 = F_47 ( V_4 ) ;
if ( V_54 < 0 )
F_48 ( V_4 , L_8 , V_54 ) ;
V_11 -> V_55 = true ;
return 0 ;
}
void F_49 ( const struct V_30 * V_31 )
{
F_42 ( & V_38 , NULL , NULL , F_46 ) ;
}
struct V_56 * F_50 ( struct V_3 * V_4 , unsigned int type )
{
if ( type == V_57 )
return & V_4 -> V_58 ;
else if ( type == V_59 )
return & V_4 -> V_60 ;
else
return NULL ;
}
struct V_56 * F_51 ( struct V_3 * V_4 , const char * V_36 )
{
struct V_56 * V_58 ;
T_2 V_61 ;
if ( ! V_36 )
V_36 = V_4 -> V_4 . V_18 -> V_36 ;
V_61 = F_52 ( & V_4 -> V_58 ) ;
V_58 = F_53 ( V_4 -> V_58 . V_62 , V_61 , V_36 ) ;
if ( ! V_58 )
return F_37 ( - V_63 ) ;
return V_58 ;
}
void F_54 ( struct V_56 * V_58 )
{
T_2 V_61 ;
V_61 = F_52 ( V_58 ) ;
F_55 ( V_58 -> V_62 , V_61 ) ;
}
static int F_56 ( struct V_3 * V_4 )
{
struct V_56 * V_60 ;
V_60 = F_50 ( V_4 , V_59 ) ;
return V_60 -> V_62 ;
}
int F_57 ( struct V_3 * V_4 )
{
struct V_30 * V_31 = V_4 -> V_31 ;
if ( V_31 -> V_64 )
return V_31 -> V_64 ( V_4 ) ;
return F_56 ( V_4 ) ;
}
static int F_58 ( void )
{
return F_59 ( & V_38 ) ;
}
static void F_60 ( void )
{
F_61 ( & V_48 ) ;
F_62 ( & V_38 ) ;
}
