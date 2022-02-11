static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , V_2 -> V_4 ,
V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
V_2 -> V_6 = V_2 -> V_7 = V_2 -> V_8 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 1 ;
}
static void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_4 = 1000000000 / V_2 -> V_11 ;
}
static int F_7 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
V_15 -> V_16 = V_17 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_6 = V_2 -> V_7 = V_2 -> V_8 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 1 ;
V_2 -> V_18 -> V_19 ( V_2 -> V_18 ) ;
return 0 ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
V_2 -> V_13 = NULL ;
F_3 ( V_2 ) ;
V_2 -> V_18 -> V_20 ( V_2 -> V_18 ) ;
return 0 ;
}
static int F_10 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
return F_11 ( V_13 ,
F_12 ( V_22 ) ) ;
}
static int F_13 ( struct V_12 * V_13 )
{
return F_14 ( V_13 ) ;
}
static int F_15 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
struct V_14 * V_15 = V_2 -> V_13 -> V_15 ;
V_2 -> V_23 = V_15 -> V_23 ;
memset ( V_2 -> V_8 , 0 , V_2 -> V_18 -> V_23 ) ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 , int V_24 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
switch ( V_24 ) {
case V_25 :
F_1 ( V_2 ) ;
break;
case V_26 :
V_2 -> V_6 = V_2 -> V_7 = V_2 -> V_8 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 1 ;
F_3 ( V_2 ) ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static int F_17 ( struct V_12 * V_13 ,
int V_28 , unsigned long V_29 ,
void T_1 * V_30 , unsigned long V_31 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
if ( F_18 ( V_2 -> V_8 + V_29 , V_30 , V_31 ) )
return - V_32 ;
V_2 -> V_7 = V_2 -> V_8 + V_29 + V_31 ;
if ( V_2 -> V_10 ) {
V_2 -> V_10 = 0 ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static int F_19 ( struct V_12 * V_13 ,
int V_28 , unsigned long V_29 ,
void * V_30 , unsigned long V_31 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
F_20 ( V_2 -> V_8 + V_29 , V_30 , V_31 ) ;
V_2 -> V_7 = V_2 -> V_8 + V_29 + V_31 ;
if ( V_2 -> V_10 ) {
V_2 -> V_10 = 0 ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static int F_21 ( struct V_12 * V_13 ,
int V_28 , unsigned long V_29 ,
unsigned long V_31 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
F_22 ( V_2 -> V_8 + V_29 , 0 , V_31 ) ;
V_2 -> V_7 = V_2 -> V_8 + V_29 + V_31 ;
if ( V_2 -> V_10 ) {
V_2 -> V_10 = 0 ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static
T_2 F_23 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_13 ) ;
int V_33 = V_2 -> V_6 - V_2 -> V_8 ;
return V_33 ;
}
static int F_24 ( struct V_1 * V_2 , int V_34 )
{
int V_35 ;
struct V_36 * V_37 ;
V_35 = F_25 ( V_2 -> V_38 , L_1 , V_34 , 1 , 0 , & V_37 ) ;
if ( V_35 < 0 )
return V_35 ;
V_37 -> V_39 = V_2 ;
strcpy ( V_37 -> V_40 , L_1 ) ;
F_26 ( V_37 , V_41 , & V_42 ) ;
F_27 ( V_37 , V_43 ,
F_28 ( V_44 ) ,
48 * 1024 ,
48 * 1024 ) ;
return 0 ;
}
static int F_29 ( struct V_45 * V_46 )
{
F_30 ( F_31 ( V_46 ) ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
F_33 ( V_2 -> V_8 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_47 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_48 ;
return F_32 ( V_2 ) ;
}
static enum V_49 F_35 ( struct V_3 * V_50 )
{
struct V_1 * V_2 = F_36 ( V_50 , struct V_1 ,
V_3 ) ;
struct V_14 * V_15 = V_2 -> V_13 -> V_15 ;
T_3 V_51 = F_37 ( V_15 , V_15 -> V_52 ) ;
if ( ! V_2 -> V_10 ) {
F_38 ( * V_2 -> V_6 , V_2 -> V_18 -> V_28 ) ;
V_2 -> V_6 ++ ;
V_2 -> V_9 ++ ;
if ( V_2 -> V_9 >= V_51 ) {
V_2 -> V_9 -= V_51 ;
F_39 ( V_2 -> V_13 ) ;
}
if ( V_2 -> V_6 == ( V_2 -> V_8 +
V_2 -> V_23 - 1 ) )
V_2 -> V_6 = V_2 -> V_8 ;
if ( V_2 -> V_6 == V_2 -> V_7 )
V_2 -> V_10 = 1 ;
}
if ( ! V_2 -> V_10 )
F_2 ( & V_2 -> V_3 , V_2 -> V_4 ,
V_5 ) ;
return V_53 ;
}
static int F_40 ( struct V_54 * V_38 ,
struct V_45 * V_46 ,
struct V_1 * * V_55 )
{
struct V_1 * V_2 ;
int V_35 ;
static struct V_56 V_57 = {
. V_58 = F_34 ,
} ;
* V_55 = NULL ;
V_2 = F_41 ( sizeof( * V_2 ) , V_44 ) ;
if ( V_2 == NULL )
return - V_59 ;
V_2 -> V_38 = V_38 ;
F_42 ( & V_2 -> V_3 , V_60 , V_5 ) ;
V_2 -> V_3 . V_61 = F_35 ;
F_5 ( V_2 ) ;
V_2 -> V_11 = 8000 ;
F_6 ( V_2 ) ;
V_2 -> V_18 = V_46 -> V_62 . V_63 ;
V_2 -> V_8 = F_43 ( V_2 -> V_18 -> V_23 , V_44 ) ;
if ( V_2 -> V_8 == NULL ) {
F_33 ( V_2 ) ;
return - V_59 ;
}
V_35 = F_44 ( V_38 , V_64 , V_2 , & V_57 ) ;
if ( V_35 < 0 ) {
F_32 ( V_2 ) ;
return V_35 ;
}
* V_55 = V_2 ;
return 0 ;
}
static int F_45 ( struct V_45 * V_46 )
{
struct V_1 * V_2 ;
struct V_54 * V_38 ;
int V_35 ;
V_35 = F_46 ( & V_46 -> V_62 , V_65 , V_66 , V_67 , 0 , & V_38 ) ;
if ( V_35 < 0 ) {
F_47 ( V_68 L_2 ) ;
return V_35 ;
}
V_35 = F_40 ( V_38 , V_46 , & V_2 ) ;
if ( V_35 < 0 )
goto V_69;
V_35 = F_24 ( V_2 , 0 ) ;
if ( V_35 < 0 )
goto V_69;
strcpy ( V_38 -> V_70 , L_3 ) ;
strcpy ( V_38 -> V_71 , L_4 ) ;
F_48 ( V_72 L_5 , V_38 -> V_73 , V_38 -> V_71 ) ;
V_35 = F_49 ( V_38 ) ;
if ( V_35 < 0 )
goto V_69;
F_47 ( L_6 ) ;
F_50 ( V_46 , V_38 ) ;
return 0 ;
V_69:
F_30 ( V_38 ) ;
return V_35 ;
}
