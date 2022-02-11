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
static long F_7 ( struct V_2 * V_3 ,
unsigned int V_21 , unsigned long V_22 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_11 = - V_23 ;
if ( ! V_4 )
return - V_13 ;
if ( V_4 -> V_14 . V_24 )
V_11 = V_4 -> V_14 . V_24 ( V_4 , V_21 , V_22 ) ;
F_4 ( V_4 ) ;
return V_11 ;
}
static long F_8 ( struct V_2 * V_3 ,
unsigned int V_21 , unsigned long V_22 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_11 = - V_23 ;
if ( ! V_4 )
return - V_13 ;
if ( V_4 -> V_14 . V_24 )
V_11 = V_4 -> V_14 . V_24 ( V_4 , V_21 , V_22 ) ;
F_4 ( V_4 ) ;
return V_11 ;
}
static int F_9 ( struct V_25 * V_25 , struct V_2 * V_3 )
{
int V_11 ;
struct V_1 * V_4 =
F_10 ( V_25 -> V_26 , struct V_1 , V_27 ) ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_7 ) {
V_11 = - V_13 ;
goto V_28;
}
if ( V_4 -> V_14 . V_29 )
V_11 = V_4 -> V_14 . V_29 ( V_4 , V_3 -> V_30 ) ;
else
V_11 = 0 ;
if ( ! V_11 ) {
F_11 ( & V_4 -> V_31 ) ;
V_3 -> V_5 = V_4 ;
}
V_28:
F_3 ( & V_4 -> V_6 ) ;
return V_11 ;
}
static int F_12 ( struct V_25 * V_25 , struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_5 ;
int V_11 = 0 ;
if ( V_4 -> V_14 . V_32 )
V_11 = V_4 -> V_14 . V_32 ( V_4 ) ;
F_13 ( & V_4 -> V_31 , V_33 ) ;
V_3 -> V_5 = NULL ;
return V_11 ;
}
int F_14 ( struct V_1 * V_4 , T_6 V_34 )
{
int V_11 ;
F_15 ( & V_4 -> V_31 ) ;
F_16 ( & V_4 -> V_6 ) ;
F_17 ( & V_4 -> V_27 , & V_35 ) ;
V_4 -> V_27 . V_36 = V_4 -> V_14 . V_36 ;
V_11 = F_18 ( & V_4 -> V_27 , V_34 , 1 ) ;
return V_11 ;
}
static void V_33 ( struct V_31 * V_31 )
{
struct V_1 * V_4 = F_10 ( V_31 , struct V_1 , V_31 ) ;
if ( V_4 -> V_32 )
V_4 -> V_32 ( V_4 ) ;
}
void F_19 ( struct V_1 * V_4 )
{
F_20 ( & V_4 -> V_27 ) ;
F_21 ( & V_4 -> V_6 ) ;
V_4 -> V_7 = true ;
F_22 ( & V_4 -> V_6 ) ;
F_13 ( & V_4 -> V_31 , V_33 ) ;
}
static int F_23 ( const T_7 V_37 , struct V_38 * V_39 )
{
struct V_2 * V_3 = F_24 ( F_25 ( V_37 ) ) ;
int V_11 = - V_12 ;
if ( ! V_3 )
return V_11 ;
if ( V_3 -> V_40 -> V_29 != F_9 || ! V_3 -> V_5 )
goto V_28;
V_39 -> V_3 = V_3 ;
V_39 -> V_4 = F_1 ( V_3 ) ;
V_11 = V_39 -> V_4 ? 0 : - V_13 ;
V_28:
if ( V_11 )
F_26 ( V_3 ) ;
return V_11 ;
}
static void F_27 ( struct V_38 * V_39 )
{
F_4 ( V_39 -> V_4 ) ;
F_26 ( V_39 -> V_3 ) ;
}
static int F_28 ( T_7 V_37 , struct V_41 * V_42 )
{
struct V_38 V_39 ;
int V_11 ;
V_11 = F_23 ( V_37 , & V_39 ) ;
if ( V_11 )
return V_11 ;
if ( ( V_39 . V_3 -> V_30 & V_43 ) == 0 ) {
V_11 = - V_44 ;
goto V_28;
}
if ( V_39 . V_4 -> V_14 . V_45 )
V_11 = V_39 . V_4 -> V_14 . V_45 ( V_39 . V_4 , V_42 ) ;
else
V_11 = - V_46 ;
V_28:
F_27 ( & V_39 ) ;
return V_11 ;
}
static int F_29 ( T_7 V_37 , struct V_47 * V_48 )
{
struct V_38 V_39 ;
int V_11 ;
V_11 = F_23 ( V_37 , & V_39 ) ;
if ( V_11 )
return V_11 ;
if ( V_39 . V_4 -> V_14 . V_49 )
V_11 = V_39 . V_4 -> V_14 . V_49 ( V_39 . V_4 , V_48 ) ;
else
V_11 = - V_46 ;
F_27 ( & V_39 ) ;
return V_11 ;
}
static int F_30 ( T_7 V_37 , struct V_47 * V_48 )
{
struct V_38 V_39 ;
int V_11 ;
V_11 = F_23 ( V_37 , & V_39 ) ;
if ( V_11 )
return V_11 ;
if ( V_39 . V_4 -> V_14 . V_50 )
V_11 = V_39 . V_4 -> V_14 . V_50 ( V_39 . V_4 , V_48 ) ;
else
V_11 = - V_46 ;
F_27 ( & V_39 ) ;
return V_11 ;
}
static int F_31 ( T_7 V_37 , const struct V_47 * V_48 )
{
struct V_38 V_39 ;
int V_11 ;
V_11 = F_23 ( V_37 , & V_39 ) ;
if ( V_11 )
return V_11 ;
if ( ( V_39 . V_3 -> V_30 & V_43 ) == 0 ) {
V_11 = - V_44 ;
goto V_28;
}
if ( V_39 . V_4 -> V_14 . V_51 )
V_11 = V_39 . V_4 -> V_14 . V_51 ( V_39 . V_4 , V_48 ) ;
else
V_11 = - V_46 ;
V_28:
F_27 ( & V_39 ) ;
return V_11 ;
}
