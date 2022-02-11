static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_5 ;
F_2 ( & V_4 -> V_6 ) ;
if ( ! V_4 -> V_7 )
return V_4 ;
F_3 ( & V_4 -> V_6 ) ;
return NULL ;
}
static void F_4 ( struct V_1 * V_4 )
{
F_3 ( & V_4 -> V_6 ) ;
}
static T_1 F_5 ( struct V_2 * V_3 , char T_2 * V_8 ,
T_3 V_9 , T_4 * V_10 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_11 = - V_12 ;
if ( ! V_4 )
return - V_13 ;
if ( V_4 -> V_14 . V_15 )
V_11 = V_4 -> V_14 . V_15 ( V_4 , V_3 -> V_16 , V_8 , V_9 ) ;
F_4 ( V_4 ) ;
return V_11 ;
}
static unsigned int F_6 ( struct V_2 * V_3 , T_5 * V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_18 = 0 ;
if ( ! V_4 )
return - V_13 ;
if ( V_4 -> V_14 . V_19 )
V_18 = V_4 -> V_14 . V_19 ( V_4 , V_3 , V_17 ) ;
F_4 ( V_4 ) ;
return V_18 ;
}
static int F_7 ( int V_20 , struct V_2 * V_3 , int V_21 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_11 = 0 ;
if ( ! V_4 )
return - V_13 ;
if ( V_4 -> V_14 . V_22 )
V_11 = V_4 -> V_14 . V_22 ( V_4 , V_20 , V_3 , V_21 ) ;
F_4 ( V_4 ) ;
return V_11 ;
}
static int F_8 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_11 = - V_13 ;
if ( ! V_4 )
return - V_13 ;
if ( V_4 -> V_14 . V_25 )
V_11 = V_4 -> V_14 . V_25 ( V_4 , V_24 ) ;
F_4 ( V_4 ) ;
return V_11 ;
}
static long F_9 ( struct V_2 * V_3 ,
unsigned int V_26 , unsigned long V_27 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_11 = - V_28 ;
if ( ! V_4 )
return - V_13 ;
if ( V_4 -> V_14 . V_29 )
V_11 = V_4 -> V_14 . V_29 ( V_4 , V_26 , V_27 ) ;
F_4 ( V_4 ) ;
return V_11 ;
}
static long F_10 ( struct V_2 * V_3 ,
unsigned int V_26 , unsigned long V_27 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_11 = - V_28 ;
if ( ! V_4 )
return - V_13 ;
if ( V_4 -> V_14 . V_29 )
V_11 = V_4 -> V_14 . V_29 ( V_4 , V_26 , V_27 ) ;
F_4 ( V_4 ) ;
return V_11 ;
}
static int F_11 ( struct V_30 * V_30 , struct V_2 * V_3 )
{
int V_11 ;
struct V_1 * V_4 =
F_12 ( V_30 -> V_31 , struct V_1 , V_32 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_7 ) {
V_11 = - V_13 ;
goto V_33;
}
if ( V_4 -> V_14 . V_34 )
V_11 = V_4 -> V_14 . V_34 ( V_4 , V_3 -> V_35 ) ;
else
V_11 = 0 ;
if ( ! V_11 ) {
F_13 ( & V_4 -> V_36 ) ;
V_3 -> V_5 = V_4 ;
}
V_33:
F_3 ( & V_4 -> V_6 ) ;
return V_11 ;
}
static int F_14 ( struct V_30 * V_30 , struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_5 ;
int V_11 = 0 ;
if ( V_4 -> V_14 . V_37 )
V_11 = V_4 -> V_14 . V_37 ( V_4 ) ;
F_15 ( & V_4 -> V_36 , V_38 ) ;
V_3 -> V_5 = NULL ;
return V_11 ;
}
int F_16 ( struct V_1 * V_4 , T_6 V_39 )
{
int V_11 ;
F_17 ( & V_4 -> V_36 ) ;
F_18 ( & V_4 -> V_6 ) ;
F_19 ( & V_4 -> V_32 , & V_40 ) ;
V_4 -> V_32 . V_41 = V_4 -> V_14 . V_41 ;
V_11 = F_20 ( & V_4 -> V_32 , V_39 , 1 ) ;
return V_11 ;
}
static void V_38 ( struct V_36 * V_36 )
{
struct V_1 * V_4 = F_12 ( V_36 , struct V_1 , V_36 ) ;
if ( V_4 -> V_37 )
V_4 -> V_37 ( V_4 ) ;
}
void F_21 ( struct V_1 * V_4 )
{
F_22 ( & V_4 -> V_32 ) ;
F_23 ( & V_4 -> V_6 ) ;
V_4 -> V_7 = true ;
F_24 ( & V_4 -> V_6 ) ;
F_15 ( & V_4 -> V_36 , V_38 ) ;
}
static int F_25 ( const T_7 V_42 , struct V_43 * V_44 )
{
struct V_2 * V_3 = F_26 ( F_27 ( V_42 ) ) ;
int V_11 = - V_12 ;
if ( ! V_3 )
return V_11 ;
if ( V_3 -> V_45 -> V_34 != F_11 || ! V_3 -> V_5 )
goto V_33;
V_44 -> V_3 = V_3 ;
V_44 -> V_4 = F_1 ( V_3 ) ;
V_11 = V_44 -> V_4 ? 0 : - V_13 ;
V_33:
if ( V_11 )
F_28 ( V_3 ) ;
return V_11 ;
}
static void F_29 ( struct V_43 * V_44 )
{
F_4 ( V_44 -> V_4 ) ;
F_28 ( V_44 -> V_3 ) ;
}
static int F_30 ( T_7 V_42 , struct V_46 * V_47 )
{
struct V_43 V_44 ;
int V_11 ;
V_11 = F_25 ( V_42 , & V_44 ) ;
if ( V_11 )
return V_11 ;
if ( ( V_44 . V_3 -> V_35 & V_48 ) == 0 ) {
V_11 = - V_49 ;
goto V_33;
}
if ( V_44 . V_4 -> V_14 . V_50 )
V_11 = V_44 . V_4 -> V_14 . V_50 ( V_44 . V_4 , V_47 ) ;
else
V_11 = - V_51 ;
V_33:
F_29 ( & V_44 ) ;
return V_11 ;
}
static int F_31 ( T_7 V_42 , struct V_52 * V_53 )
{
struct V_43 V_44 ;
int V_11 ;
V_11 = F_25 ( V_42 , & V_44 ) ;
if ( V_11 )
return V_11 ;
if ( V_44 . V_4 -> V_14 . V_54 )
V_11 = V_44 . V_4 -> V_14 . V_54 ( V_44 . V_4 , V_53 ) ;
else
V_11 = - V_51 ;
F_29 ( & V_44 ) ;
return V_11 ;
}
static int F_32 ( T_7 V_42 , struct V_52 * V_53 )
{
struct V_43 V_44 ;
int V_11 ;
V_11 = F_25 ( V_42 , & V_44 ) ;
if ( V_11 )
return V_11 ;
if ( V_44 . V_4 -> V_14 . V_55 )
V_11 = V_44 . V_4 -> V_14 . V_55 ( V_44 . V_4 , V_53 ) ;
else
V_11 = - V_51 ;
F_29 ( & V_44 ) ;
return V_11 ;
}
static int F_33 ( T_7 V_42 , const struct V_52 * V_53 )
{
struct V_43 V_44 ;
int V_11 ;
V_11 = F_25 ( V_42 , & V_44 ) ;
if ( V_11 )
return V_11 ;
if ( ( V_44 . V_3 -> V_35 & V_48 ) == 0 ) {
V_11 = - V_49 ;
goto V_33;
}
if ( V_44 . V_4 -> V_14 . V_56 )
V_11 = V_44 . V_4 -> V_14 . V_56 ( V_44 . V_4 , V_53 ) ;
else
V_11 = - V_51 ;
V_33:
F_29 ( & V_44 ) ;
return V_11 ;
}
static int F_34 ( struct V_57 * V_58 )
{
T_7 V_42 = V_58 -> V_59 ;
struct V_43 V_44 ;
int V_11 ;
V_11 = F_25 ( V_42 , & V_44 ) ;
if ( V_11 )
return V_11 ;
if ( V_44 . V_4 -> V_14 . V_60 )
V_11 = V_44 . V_4 -> V_14 . V_60 ( V_44 . V_4 , V_58 ) ;
else
V_11 = - V_51 ;
F_29 ( & V_44 ) ;
return V_11 ;
}
static int F_35 ( struct V_57 * V_58 )
{
T_7 V_42 = V_58 -> V_59 ;
struct V_43 V_44 ;
int V_11 ;
V_11 = F_25 ( V_42 , & V_44 ) ;
if ( V_11 )
return V_11 ;
if ( V_44 . V_4 -> V_14 . V_61 )
V_11 = V_44 . V_4 -> V_14 . V_61 ( V_44 . V_4 , V_58 ) ;
else
V_11 = - V_51 ;
F_29 ( & V_44 ) ;
return V_11 ;
}
static void F_36 ( struct V_57 * V_58 , struct V_62 * V_53 )
{
T_7 V_42 = V_58 -> V_59 ;
struct V_43 V_44 ;
if ( F_25 ( V_42 , & V_44 ) )
return;
if ( V_44 . V_4 -> V_14 . V_63 )
V_44 . V_4 -> V_14 . V_63 ( V_44 . V_4 , V_58 , V_53 ) ;
F_29 ( & V_44 ) ;
}
static int F_37 ( struct V_57 * V_58 , int V_64 ,
struct V_62 * V_53 , struct V_62 * V_65 )
{
T_7 V_42 = V_58 -> V_59 ;
struct V_43 V_44 ;
int V_11 ;
V_11 = F_25 ( V_42 , & V_44 ) ;
if ( V_11 )
return V_11 ;
if ( V_44 . V_4 -> V_14 . V_66 )
V_11 = V_44 . V_4 -> V_14 . V_66 ( V_44 . V_4 , V_58 , V_64 , V_53 , V_65 ) ;
else
V_11 = - V_51 ;
F_29 ( & V_44 ) ;
return V_11 ;
}
