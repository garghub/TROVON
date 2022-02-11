struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 , void * V_5 ,
struct V_6 V_7 )
{
if ( F_2 ( ! V_3 ) )
return F_3 ( - V_8 ) ;
return V_3 -> V_9 -> V_10 ( V_3 , V_4 , V_5 , V_7 ) ;
}
void F_4 ( struct V_1 * V_11 )
{
if ( V_11 )
V_11 -> V_9 -> V_12 ( V_11 ) ;
}
int F_5 ( struct V_1 * V_11 , void * V_13 , int V_14 )
{
if ( F_2 ( ! V_11 ) )
return - V_8 ;
if ( ! V_11 -> V_9 -> V_15 )
return - V_16 ;
return V_11 -> V_9 -> V_15 ( V_11 , V_13 , V_14 ) ;
}
int F_6 ( struct V_1 * V_11 , void * V_13 , int V_14 , T_2 V_17 )
{
if ( F_2 ( ! V_11 ) )
return - V_8 ;
if ( ! V_11 -> V_9 -> V_18 )
return - V_16 ;
return V_11 -> V_9 -> V_18 ( V_11 , V_13 , V_14 , V_17 ) ;
}
int F_7 ( struct V_1 * V_11 , T_2 V_19 , T_2 V_17 ,
void * V_13 , int V_14 )
{
if ( F_2 ( ! V_11 ) )
return - V_8 ;
if ( ! V_11 -> V_9 -> V_20 )
return - V_16 ;
return V_11 -> V_9 -> V_20 ( V_11 , V_19 , V_17 , V_13 , V_14 ) ;
}
int F_8 ( struct V_1 * V_11 , void * V_13 , int V_14 )
{
if ( F_2 ( ! V_11 ) )
return - V_8 ;
if ( ! V_11 -> V_9 -> V_21 )
return - V_16 ;
return V_11 -> V_9 -> V_21 ( V_11 , V_13 , V_14 ) ;
}
int F_9 ( struct V_1 * V_11 , void * V_13 , int V_14 , T_2 V_17 )
{
if ( F_2 ( ! V_11 ) )
return - V_8 ;
if ( ! V_11 -> V_9 -> V_22 )
return - V_16 ;
return V_11 -> V_9 -> V_22 ( V_11 , V_13 , V_14 , V_17 ) ;
}
int F_10 ( struct V_1 * V_11 , T_2 V_19 , T_2 V_17 ,
void * V_13 , int V_14 )
{
if ( F_2 ( ! V_11 ) )
return - V_8 ;
if ( ! V_11 -> V_9 -> V_23 )
return - V_16 ;
return V_11 -> V_9 -> V_23 ( V_11 , V_19 , V_17 , V_13 , V_14 ) ;
}
static int F_11 ( struct V_24 * V_25 , void * V_13 )
{
struct V_6 * V_7 = V_13 ;
struct V_2 * V_3 = F_12 ( V_25 ) ;
if ( V_7 -> V_19 != V_26 && V_7 -> V_19 != V_3 -> V_19 )
return 0 ;
if ( V_7 -> V_17 != V_26 && V_7 -> V_17 != V_3 -> V_17 )
return 0 ;
if ( strncmp ( V_7 -> V_27 , V_3 -> V_28 . V_27 , V_29 ) )
return 0 ;
return 1 ;
}
struct V_24 * F_13 ( struct V_24 * V_30 ,
struct V_6 * V_7 )
{
return F_14 ( V_30 , V_7 , F_11 ) ;
}
static T_3 F_15 ( struct V_24 * V_25 ,
struct V_31 * V_32 , char * V_33 )
{
struct V_2 * V_3 = F_12 ( V_25 ) ;
return sprintf ( V_33 , V_34 L_1 , V_3 -> V_28 . V_27 ) ;
}
static inline int F_16 ( const struct V_2 * V_3 ,
const struct V_35 * V_28 )
{
return strncmp ( V_28 -> V_27 , V_3 -> V_28 . V_27 , V_29 ) == 0 ;
}
static int F_17 ( struct V_24 * V_25 , struct V_36 * V_37 )
{
struct V_2 * V_3 = F_12 ( V_25 ) ;
struct V_38 * V_39 = F_18 ( V_37 ) ;
const struct V_35 * V_40 = V_39 -> V_41 ;
unsigned int V_42 ;
if ( V_3 -> V_43 )
return ! strcmp ( V_3 -> V_43 , V_37 -> V_27 ) ;
if ( V_40 )
for ( V_42 = 0 ; V_40 [ V_42 ] . V_27 [ 0 ] ; V_42 ++ )
if ( F_16 ( V_3 , & V_40 [ V_42 ] ) )
return 1 ;
return F_19 ( V_25 , V_37 ) ;
}
static int F_20 ( struct V_24 * V_25 , struct V_44 * V_45 )
{
struct V_2 * V_3 = F_12 ( V_25 ) ;
return F_21 ( V_45 , L_2 V_34 ,
V_3 -> V_28 . V_27 ) ;
}
static int F_22 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_12 ( V_25 ) ;
struct V_38 * V_39 = F_18 ( V_3 -> V_25 . V_46 ) ;
struct V_6 V_7 = {} ;
struct V_1 * V_11 = NULL ;
int V_47 ;
if ( V_39 -> V_48 ) {
strncpy ( V_7 . V_27 , V_3 -> V_28 . V_27 , V_29 ) ;
V_7 . V_19 = V_3 -> V_19 ;
V_7 . V_17 = V_26 ;
V_11 = F_1 ( V_3 , V_39 -> V_48 , NULL , V_7 ) ;
if ( ! V_11 ) {
F_23 ( V_25 , L_3 ) ;
V_47 = - V_49 ;
goto V_50;
}
V_3 -> V_11 = V_11 ;
V_3 -> V_19 = V_11 -> V_51 ;
}
V_47 = V_39 -> V_52 ( V_3 ) ;
if ( V_47 ) {
F_23 ( V_25 , L_4 , V_53 , V_47 ) ;
if ( V_11 )
F_4 ( V_11 ) ;
goto V_50;
}
if ( V_3 -> V_9 -> V_54 )
V_47 = V_3 -> V_9 -> V_54 ( V_3 ) ;
V_50:
return V_47 ;
}
static int F_24 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_12 ( V_25 ) ;
struct V_38 * V_39 = F_18 ( V_3 -> V_25 . V_46 ) ;
int V_47 = 0 ;
if ( V_3 -> V_9 -> V_55 )
V_47 = V_3 -> V_9 -> V_55 ( V_3 ) ;
V_39 -> remove ( V_3 ) ;
if ( V_3 -> V_11 )
F_4 ( V_3 -> V_11 ) ;
return V_47 ;
}
static void F_25 ( struct V_24 * V_25 )
{
struct V_2 * V_3 = F_12 ( V_25 ) ;
F_26 ( V_3 ) ;
}
int F_27 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = & V_3 -> V_25 ;
int V_56 ;
F_28 ( & V_3 -> V_25 , L_5 , F_29 ( V_25 -> V_30 ) ,
V_3 -> V_28 . V_27 , V_3 -> V_19 , V_3 -> V_17 ) ;
V_3 -> V_25 . V_57 = & V_58 ;
V_3 -> V_25 . V_59 = F_25 ;
V_56 = F_30 ( & V_3 -> V_25 ) ;
if ( V_56 ) {
F_23 ( V_25 , L_6 , V_56 ) ;
F_31 ( & V_3 -> V_25 ) ;
}
return V_56 ;
}
int F_32 ( struct V_24 * V_30 ,
struct V_6 * V_7 )
{
struct V_24 * V_25 ;
V_25 = F_13 ( V_30 , V_7 ) ;
if ( ! V_25 )
return - V_8 ;
F_33 ( V_25 ) ;
F_31 ( V_25 ) ;
return 0 ;
}
int F_34 ( struct V_38 * V_39 , struct V_60 * V_61 )
{
V_39 -> V_37 . V_57 = & V_58 ;
V_39 -> V_37 . V_61 = V_61 ;
return F_35 ( & V_39 -> V_37 ) ;
}
void F_36 ( struct V_38 * V_39 )
{
F_37 ( & V_39 -> V_37 ) ;
}
static int T_4 F_38 ( void )
{
int V_56 ;
V_56 = F_39 ( & V_58 ) ;
if ( V_56 )
F_40 ( L_7 , V_56 ) ;
return V_56 ;
}
static void T_5 F_41 ( void )
{
F_42 ( & V_58 ) ;
}
