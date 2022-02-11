struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 , void * V_5 ,
struct V_6 V_7 )
{
return V_3 -> V_8 -> V_9 ( V_3 , V_4 , V_5 , V_7 ) ;
}
void F_2 ( struct V_1 * V_10 )
{
V_10 -> V_8 -> V_11 ( V_10 ) ;
}
int F_3 ( struct V_1 * V_10 , void * V_12 , int V_13 )
{
return V_10 -> V_8 -> V_14 ( V_10 , V_12 , V_13 ) ;
}
int F_4 ( struct V_1 * V_10 , void * V_12 , int V_13 , T_2 V_15 )
{
return V_10 -> V_8 -> V_16 ( V_10 , V_12 , V_13 , V_15 ) ;
}
int F_5 ( struct V_1 * V_10 , T_2 V_17 , T_2 V_15 ,
void * V_12 , int V_13 )
{
return V_10 -> V_8 -> V_18 ( V_10 , V_17 , V_15 , V_12 , V_13 ) ;
}
int F_6 ( struct V_1 * V_10 , void * V_12 , int V_13 )
{
return V_10 -> V_8 -> V_19 ( V_10 , V_12 , V_13 ) ;
}
int F_7 ( struct V_1 * V_10 , void * V_12 , int V_13 , T_2 V_15 )
{
return V_10 -> V_8 -> V_20 ( V_10 , V_12 , V_13 , V_15 ) ;
}
int F_8 ( struct V_1 * V_10 , T_2 V_17 , T_2 V_15 ,
void * V_12 , int V_13 )
{
return V_10 -> V_8 -> V_21 ( V_10 , V_17 , V_15 , V_12 , V_13 ) ;
}
static int F_9 ( struct V_22 * V_23 , void * V_12 )
{
struct V_6 * V_7 = V_12 ;
struct V_2 * V_3 = F_10 ( V_23 ) ;
if ( V_7 -> V_17 != V_24 && V_7 -> V_17 != V_3 -> V_17 )
return 0 ;
if ( V_7 -> V_15 != V_24 && V_7 -> V_15 != V_3 -> V_15 )
return 0 ;
if ( strncmp ( V_7 -> V_25 , V_3 -> V_26 . V_25 , V_27 ) )
return 0 ;
return 1 ;
}
struct V_22 * F_11 ( struct V_22 * V_28 ,
struct V_6 * V_7 )
{
return F_12 ( V_28 , V_7 , F_9 ) ;
}
static T_3 F_13 ( struct V_22 * V_23 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_2 * V_3 = F_10 ( V_23 ) ;
return sprintf ( V_31 , V_32 L_1 , V_3 -> V_26 . V_25 ) ;
}
static inline int F_14 ( const struct V_2 * V_3 ,
const struct V_33 * V_26 )
{
return strncmp ( V_26 -> V_25 , V_3 -> V_26 . V_25 , V_27 ) == 0 ;
}
static int F_15 ( struct V_22 * V_23 , struct V_34 * V_35 )
{
struct V_2 * V_3 = F_10 ( V_23 ) ;
struct V_36 * V_37 = F_16 ( V_35 ) ;
const struct V_33 * V_38 = V_37 -> V_39 ;
unsigned int V_40 ;
if ( V_38 )
for ( V_40 = 0 ; V_38 [ V_40 ] . V_25 [ 0 ] ; V_40 ++ )
if ( F_14 ( V_3 , & V_38 [ V_40 ] ) )
return 1 ;
return F_17 ( V_23 , V_35 ) ;
}
static int F_18 ( struct V_22 * V_23 , struct V_41 * V_42 )
{
struct V_2 * V_3 = F_10 ( V_23 ) ;
return F_19 ( V_42 , L_2 V_32 ,
V_3 -> V_26 . V_25 ) ;
}
static int F_20 ( struct V_22 * V_23 )
{
struct V_2 * V_3 = F_10 ( V_23 ) ;
struct V_36 * V_37 = F_16 ( V_3 -> V_23 . V_43 ) ;
struct V_6 V_7 = {} ;
struct V_1 * V_10 ;
int V_44 ;
strncpy ( V_7 . V_25 , V_3 -> V_26 . V_25 , V_27 ) ;
V_7 . V_17 = V_3 -> V_17 ;
V_7 . V_15 = V_24 ;
V_10 = F_1 ( V_3 , V_37 -> V_45 , NULL , V_7 ) ;
if ( ! V_10 ) {
F_21 ( V_23 , L_3 ) ;
V_44 = - V_46 ;
goto V_47;
}
V_3 -> V_10 = V_10 ;
V_3 -> V_17 = V_10 -> V_48 ;
V_44 = V_37 -> V_49 ( V_3 ) ;
if ( V_44 ) {
F_21 ( V_23 , L_4 , V_50 , V_44 ) ;
F_2 ( V_10 ) ;
goto V_47;
}
if ( V_3 -> V_8 -> V_51 )
V_44 = V_3 -> V_8 -> V_51 ( V_3 ) ;
V_47:
return V_44 ;
}
static int F_22 ( struct V_22 * V_23 )
{
struct V_2 * V_3 = F_10 ( V_23 ) ;
struct V_36 * V_37 = F_16 ( V_3 -> V_23 . V_43 ) ;
int V_44 = 0 ;
if ( V_3 -> V_8 -> V_52 )
V_44 = V_3 -> V_8 -> V_52 ( V_3 ) ;
V_37 -> remove ( V_3 ) ;
F_2 ( V_3 -> V_10 ) ;
return V_44 ;
}
static void F_23 ( struct V_22 * V_23 )
{
struct V_2 * V_3 = F_10 ( V_23 ) ;
F_24 ( V_3 ) ;
}
int F_25 ( struct V_2 * V_3 )
{
struct V_22 * V_23 = & V_3 -> V_23 ;
int V_53 ;
F_26 ( & V_3 -> V_23 , L_5 ,
F_27 ( V_23 -> V_28 ) , V_3 -> V_26 . V_25 ) ;
V_3 -> V_23 . V_54 = & V_55 ;
V_3 -> V_23 . V_56 = F_23 ;
V_53 = F_28 ( & V_3 -> V_23 ) ;
if ( V_53 ) {
F_21 ( V_23 , L_6 , V_53 ) ;
F_29 ( & V_3 -> V_23 ) ;
}
return V_53 ;
}
int F_30 ( struct V_22 * V_28 ,
struct V_6 * V_7 )
{
struct V_22 * V_23 ;
V_23 = F_11 ( V_28 , V_7 ) ;
if ( ! V_23 )
return - V_57 ;
F_31 ( V_23 ) ;
F_29 ( V_23 ) ;
return 0 ;
}
int F_32 ( struct V_36 * V_37 , struct V_58 * V_59 )
{
V_37 -> V_35 . V_54 = & V_55 ;
V_37 -> V_35 . V_59 = V_59 ;
return F_33 ( & V_37 -> V_35 ) ;
}
void F_34 ( struct V_36 * V_37 )
{
F_35 ( & V_37 -> V_35 ) ;
}
static int T_4 F_36 ( void )
{
int V_53 ;
V_53 = F_37 ( & V_55 ) ;
if ( V_53 )
F_38 ( L_7 , V_53 ) ;
return V_53 ;
}
static void T_5 F_39 ( void )
{
F_40 ( & V_55 ) ;
}
