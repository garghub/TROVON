struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 , void * V_5 ,
struct V_6 V_7 )
{
if ( F_2 ( ! V_3 ) )
return NULL ;
return V_3 -> V_8 -> V_9 ( V_3 , V_4 , V_5 , V_7 ) ;
}
void F_3 ( struct V_1 * V_10 )
{
if ( V_10 )
V_10 -> V_8 -> V_11 ( V_10 ) ;
}
int F_4 ( struct V_1 * V_10 , void * V_12 , int V_13 )
{
if ( F_2 ( ! V_10 ) )
return - V_14 ;
if ( ! V_10 -> V_8 -> V_15 )
return - V_16 ;
return V_10 -> V_8 -> V_15 ( V_10 , V_12 , V_13 ) ;
}
int F_5 ( struct V_1 * V_10 , void * V_12 , int V_13 , T_2 V_17 )
{
if ( F_2 ( ! V_10 ) )
return - V_14 ;
if ( ! V_10 -> V_8 -> V_18 )
return - V_16 ;
return V_10 -> V_8 -> V_18 ( V_10 , V_12 , V_13 , V_17 ) ;
}
int F_6 ( struct V_1 * V_10 , T_2 V_19 , T_2 V_17 ,
void * V_12 , int V_13 )
{
if ( F_2 ( ! V_10 ) )
return - V_14 ;
if ( ! V_10 -> V_8 -> V_20 )
return - V_16 ;
return V_10 -> V_8 -> V_20 ( V_10 , V_19 , V_17 , V_12 , V_13 ) ;
}
int F_7 ( struct V_1 * V_10 , void * V_12 , int V_13 )
{
if ( F_2 ( ! V_10 ) )
return - V_14 ;
if ( ! V_10 -> V_8 -> V_21 )
return - V_16 ;
return V_10 -> V_8 -> V_21 ( V_10 , V_12 , V_13 ) ;
}
int F_8 ( struct V_1 * V_10 , void * V_12 , int V_13 , T_2 V_17 )
{
if ( F_2 ( ! V_10 ) )
return - V_14 ;
if ( ! V_10 -> V_8 -> V_22 )
return - V_16 ;
return V_10 -> V_8 -> V_22 ( V_10 , V_12 , V_13 , V_17 ) ;
}
unsigned int F_9 ( struct V_1 * V_10 , struct V_23 * V_24 ,
T_3 * V_25 )
{
if ( F_2 ( ! V_10 ) )
return 0 ;
if ( ! V_10 -> V_8 -> V_26 )
return 0 ;
return V_10 -> V_8 -> V_26 ( V_10 , V_24 , V_25 ) ;
}
int F_10 ( struct V_1 * V_10 , T_2 V_19 , T_2 V_17 ,
void * V_12 , int V_13 )
{
if ( F_2 ( ! V_10 ) )
return - V_14 ;
if ( ! V_10 -> V_8 -> V_27 )
return - V_16 ;
return V_10 -> V_8 -> V_27 ( V_10 , V_19 , V_17 , V_12 , V_13 ) ;
}
static int F_11 ( struct V_28 * V_29 , void * V_12 )
{
struct V_6 * V_7 = V_12 ;
struct V_2 * V_3 = F_12 ( V_29 ) ;
if ( V_7 -> V_19 != V_30 && V_7 -> V_19 != V_3 -> V_19 )
return 0 ;
if ( V_7 -> V_17 != V_30 && V_7 -> V_17 != V_3 -> V_17 )
return 0 ;
if ( strncmp ( V_7 -> V_31 , V_3 -> V_32 . V_31 , V_33 ) )
return 0 ;
return 1 ;
}
struct V_28 * F_13 ( struct V_28 * V_34 ,
struct V_6 * V_7 )
{
return F_14 ( V_34 , V_7 , F_11 ) ;
}
static T_4 F_15 ( struct V_28 * V_29 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_2 * V_3 = F_12 ( V_29 ) ;
return sprintf ( V_37 , V_38 L_1 , V_3 -> V_32 . V_31 ) ;
}
static inline int F_16 ( const struct V_2 * V_3 ,
const struct V_39 * V_32 )
{
return strncmp ( V_32 -> V_31 , V_3 -> V_32 . V_31 , V_33 ) == 0 ;
}
static int F_17 ( struct V_28 * V_29 , struct V_40 * V_41 )
{
struct V_2 * V_3 = F_12 ( V_29 ) ;
struct V_42 * V_43 = F_18 ( V_41 ) ;
const struct V_39 * V_44 = V_43 -> V_45 ;
unsigned int V_46 ;
if ( V_3 -> V_47 )
return ! strcmp ( V_3 -> V_47 , V_41 -> V_31 ) ;
if ( V_44 )
for ( V_46 = 0 ; V_44 [ V_46 ] . V_31 [ 0 ] ; V_46 ++ )
if ( F_16 ( V_3 , & V_44 [ V_46 ] ) )
return 1 ;
return F_19 ( V_29 , V_41 ) ;
}
static int F_20 ( struct V_28 * V_29 , struct V_48 * V_49 )
{
struct V_2 * V_3 = F_12 ( V_29 ) ;
return F_21 ( V_49 , L_2 V_38 ,
V_3 -> V_32 . V_31 ) ;
}
static int F_22 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = F_12 ( V_29 ) ;
struct V_42 * V_43 = F_18 ( V_3 -> V_29 . V_50 ) ;
struct V_6 V_7 = {} ;
struct V_1 * V_10 = NULL ;
int V_51 ;
if ( V_43 -> V_52 ) {
strncpy ( V_7 . V_31 , V_3 -> V_32 . V_31 , V_33 ) ;
V_7 . V_19 = V_3 -> V_19 ;
V_7 . V_17 = V_30 ;
V_10 = F_1 ( V_3 , V_43 -> V_52 , NULL , V_7 ) ;
if ( ! V_10 ) {
F_23 ( V_29 , L_3 ) ;
V_51 = - V_53 ;
goto V_54;
}
V_3 -> V_10 = V_10 ;
V_3 -> V_19 = V_10 -> V_55 ;
}
V_51 = V_43 -> V_56 ( V_3 ) ;
if ( V_51 ) {
F_23 ( V_29 , L_4 , V_57 , V_51 ) ;
if ( V_10 )
F_3 ( V_10 ) ;
goto V_54;
}
if ( V_3 -> V_8 -> V_58 )
V_51 = V_3 -> V_8 -> V_58 ( V_3 ) ;
V_54:
return V_51 ;
}
static int F_24 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = F_12 ( V_29 ) ;
struct V_42 * V_43 = F_18 ( V_3 -> V_29 . V_50 ) ;
int V_51 = 0 ;
if ( V_3 -> V_8 -> V_59 )
V_51 = V_3 -> V_8 -> V_59 ( V_3 ) ;
V_43 -> remove ( V_3 ) ;
if ( V_3 -> V_10 )
F_3 ( V_3 -> V_10 ) ;
return V_51 ;
}
static void F_25 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = F_12 ( V_29 ) ;
F_26 ( V_3 ) ;
}
int F_27 ( struct V_2 * V_3 )
{
struct V_28 * V_29 = & V_3 -> V_29 ;
int V_60 ;
F_28 ( & V_3 -> V_29 , L_5 , F_29 ( V_29 -> V_34 ) ,
V_3 -> V_32 . V_31 , V_3 -> V_19 , V_3 -> V_17 ) ;
V_3 -> V_29 . V_61 = & V_62 ;
V_3 -> V_29 . V_63 = F_25 ;
V_60 = F_30 ( & V_3 -> V_29 ) ;
if ( V_60 ) {
F_23 ( V_29 , L_6 , V_60 ) ;
F_31 ( & V_3 -> V_29 ) ;
}
return V_60 ;
}
int F_32 ( struct V_28 * V_34 ,
struct V_6 * V_7 )
{
struct V_28 * V_29 ;
V_29 = F_13 ( V_34 , V_7 ) ;
if ( ! V_29 )
return - V_14 ;
F_33 ( V_29 ) ;
F_31 ( V_29 ) ;
return 0 ;
}
int F_34 ( struct V_42 * V_43 , struct V_64 * V_65 )
{
V_43 -> V_41 . V_61 = & V_62 ;
V_43 -> V_41 . V_65 = V_65 ;
return F_35 ( & V_43 -> V_41 ) ;
}
void F_36 ( struct V_42 * V_43 )
{
F_37 ( & V_43 -> V_41 ) ;
}
static int T_5 F_38 ( void )
{
int V_60 ;
V_60 = F_39 ( & V_62 ) ;
if ( V_60 )
F_40 ( L_7 , V_60 ) ;
return V_60 ;
}
static void T_6 F_41 ( void )
{
F_42 ( & V_62 ) ;
}
