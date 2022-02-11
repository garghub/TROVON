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
unsigned int V_18 = 0 ;
if ( ! V_4 )
return V_19 ;
if ( V_4 -> V_14 . V_20 )
V_18 = V_4 -> V_14 . V_20 ( V_4 , V_3 , V_17 ) ;
F_4 ( V_4 ) ;
return V_18 ;
}
static int F_7 ( int V_21 , struct V_2 * V_3 , int V_22 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_11 = 0 ;
if ( ! V_4 )
return - V_13 ;
if ( V_4 -> V_14 . V_23 )
V_11 = V_4 -> V_14 . V_23 ( V_4 , V_21 , V_3 , V_22 ) ;
F_4 ( V_4 ) ;
return V_11 ;
}
static int F_8 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_11 = - V_13 ;
if ( ! V_4 )
return - V_13 ;
if ( V_4 -> V_14 . V_26 )
V_11 = V_4 -> V_14 . V_26 ( V_4 , V_25 ) ;
F_4 ( V_4 ) ;
return V_11 ;
}
static long F_9 ( struct V_2 * V_3 ,
unsigned int V_27 , unsigned long V_28 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_11 = - V_29 ;
if ( ! V_4 )
return - V_13 ;
if ( V_4 -> V_14 . V_30 )
V_11 = V_4 -> V_14 . V_30 ( V_4 , V_27 , V_28 ) ;
F_4 ( V_4 ) ;
return V_11 ;
}
static long F_10 ( struct V_2 * V_3 ,
unsigned int V_27 , unsigned long V_28 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_11 = - V_29 ;
if ( ! V_4 )
return - V_13 ;
if ( V_4 -> V_14 . V_30 )
V_11 = V_4 -> V_14 . V_30 ( V_4 , V_27 , V_28 ) ;
F_4 ( V_4 ) ;
return V_11 ;
}
static int F_11 ( struct V_31 * V_31 , struct V_2 * V_3 )
{
int V_11 ;
struct V_1 * V_4 =
F_12 ( V_31 -> V_32 , struct V_1 , V_33 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_7 ) {
V_11 = - V_13 ;
goto V_34;
}
if ( V_4 -> V_14 . V_35 )
V_11 = V_4 -> V_14 . V_35 ( V_4 , V_3 -> V_36 ) ;
else
V_11 = 0 ;
if ( ! V_11 ) {
F_13 ( & V_4 -> V_37 ) ;
V_3 -> V_5 = V_4 ;
}
V_34:
F_3 ( & V_4 -> V_6 ) ;
return V_11 ;
}
static int F_14 ( struct V_31 * V_31 , struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_5 ;
int V_11 = 0 ;
if ( V_4 -> V_14 . V_38 )
V_11 = V_4 -> V_14 . V_38 ( V_4 ) ;
F_15 ( & V_4 -> V_37 , V_39 ) ;
V_3 -> V_5 = NULL ;
return V_11 ;
}
int F_16 ( struct V_1 * V_4 , T_6 V_40 )
{
int V_11 ;
F_17 ( & V_4 -> V_37 ) ;
F_18 ( & V_4 -> V_6 ) ;
F_19 ( & V_4 -> V_33 , & V_41 ) ;
V_4 -> V_33 . V_42 = V_4 -> V_14 . V_42 ;
V_11 = F_20 ( & V_4 -> V_33 , V_40 , 1 ) ;
return V_11 ;
}
static void V_39 ( struct V_37 * V_37 )
{
struct V_1 * V_4 = F_12 ( V_37 , struct V_1 , V_37 ) ;
if ( V_4 -> V_38 )
V_4 -> V_38 ( V_4 ) ;
}
void F_21 ( struct V_1 * V_4 )
{
F_22 ( & V_4 -> V_33 ) ;
F_23 ( & V_4 -> V_6 ) ;
V_4 -> V_7 = true ;
F_24 ( & V_4 -> V_6 ) ;
F_15 ( & V_4 -> V_37 , V_39 ) ;
}
static int F_25 ( const T_7 V_43 , struct V_44 * V_45 )
{
struct V_2 * V_3 = F_26 ( F_27 ( V_43 ) ) ;
int V_11 = - V_12 ;
if ( ! V_3 )
return V_11 ;
if ( V_3 -> V_46 -> V_35 != F_11 || ! V_3 -> V_5 )
goto V_34;
V_45 -> V_3 = V_3 ;
V_45 -> V_4 = F_1 ( V_3 ) ;
V_11 = V_45 -> V_4 ? 0 : - V_13 ;
V_34:
if ( V_11 )
F_28 ( V_3 ) ;
return V_11 ;
}
static void F_29 ( struct V_44 * V_45 )
{
F_4 ( V_45 -> V_4 ) ;
F_28 ( V_45 -> V_3 ) ;
}
static int F_30 ( T_7 V_43 , struct V_47 * V_48 )
{
struct V_44 V_45 ;
int V_11 ;
V_11 = F_25 ( V_43 , & V_45 ) ;
if ( V_11 )
return V_11 ;
if ( ( V_45 . V_3 -> V_36 & V_49 ) == 0 ) {
V_11 = - V_50 ;
goto V_34;
}
if ( V_45 . V_4 -> V_14 . V_51 )
V_11 = V_45 . V_4 -> V_14 . V_51 ( V_45 . V_4 , V_48 ) ;
else
V_11 = - V_52 ;
V_34:
F_29 ( & V_45 ) ;
return V_11 ;
}
static int F_31 ( T_7 V_43 , struct V_53 * V_54 )
{
struct V_44 V_45 ;
int V_11 ;
V_11 = F_25 ( V_43 , & V_45 ) ;
if ( V_11 )
return V_11 ;
if ( V_45 . V_4 -> V_14 . V_55 )
V_11 = V_45 . V_4 -> V_14 . V_55 ( V_45 . V_4 , V_54 ) ;
else
V_11 = - V_52 ;
F_29 ( & V_45 ) ;
return V_11 ;
}
static int F_32 ( T_7 V_43 , struct V_53 * V_54 )
{
struct V_44 V_45 ;
int V_11 ;
V_11 = F_25 ( V_43 , & V_45 ) ;
if ( V_11 )
return V_11 ;
if ( V_45 . V_4 -> V_14 . V_56 )
V_11 = V_45 . V_4 -> V_14 . V_56 ( V_45 . V_4 , V_54 ) ;
else
V_11 = - V_52 ;
F_29 ( & V_45 ) ;
return V_11 ;
}
static int F_33 ( T_7 V_43 , const struct V_53 * V_54 )
{
struct V_44 V_45 ;
int V_11 ;
V_11 = F_25 ( V_43 , & V_45 ) ;
if ( V_11 )
return V_11 ;
if ( ( V_45 . V_3 -> V_36 & V_49 ) == 0 ) {
V_11 = - V_50 ;
goto V_34;
}
if ( V_45 . V_4 -> V_14 . V_57 )
V_11 = V_45 . V_4 -> V_14 . V_57 ( V_45 . V_4 , V_54 ) ;
else
V_11 = - V_52 ;
V_34:
F_29 ( & V_45 ) ;
return V_11 ;
}
static int F_34 ( struct V_58 * V_59 )
{
T_7 V_43 = V_59 -> V_60 ;
struct V_44 V_45 ;
int V_11 ;
V_11 = F_25 ( V_43 , & V_45 ) ;
if ( V_11 )
return V_11 ;
if ( V_45 . V_4 -> V_14 . V_61 )
V_11 = V_45 . V_4 -> V_14 . V_61 ( V_45 . V_4 , V_59 ) ;
else
V_11 = - V_52 ;
F_29 ( & V_45 ) ;
return V_11 ;
}
static int F_35 ( struct V_58 * V_59 )
{
T_7 V_43 = V_59 -> V_60 ;
struct V_44 V_45 ;
int V_11 ;
V_11 = F_25 ( V_43 , & V_45 ) ;
if ( V_11 )
return V_11 ;
if ( V_45 . V_4 -> V_14 . V_62 )
V_11 = V_45 . V_4 -> V_14 . V_62 ( V_45 . V_4 , V_59 ) ;
else
V_11 = - V_52 ;
F_29 ( & V_45 ) ;
return V_11 ;
}
static void F_36 ( struct V_58 * V_59 , struct V_63 * V_54 )
{
T_7 V_43 = V_59 -> V_60 ;
struct V_44 V_45 ;
if ( F_25 ( V_43 , & V_45 ) )
return;
if ( V_45 . V_4 -> V_14 . V_64 )
V_45 . V_4 -> V_14 . V_64 ( V_45 . V_4 , V_59 , V_54 ) ;
F_29 ( & V_45 ) ;
}
static int F_37 ( struct V_58 * V_59 , int V_65 ,
struct V_63 * V_54 , struct V_63 * V_66 )
{
T_7 V_43 = V_59 -> V_60 ;
struct V_44 V_45 ;
int V_11 ;
V_11 = F_25 ( V_43 , & V_45 ) ;
if ( V_11 )
return V_11 ;
if ( V_45 . V_4 -> V_14 . V_67 )
V_11 = V_45 . V_4 -> V_14 . V_67 ( V_45 . V_4 , V_59 , V_65 , V_54 , V_66 ) ;
else
V_11 = - V_52 ;
F_29 ( & V_45 ) ;
return V_11 ;
}
