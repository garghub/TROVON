static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 -> V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_8 = V_4 -> V_9 [ V_7 ] ;
int V_10 ;
if ( ! V_8 )
return - V_11 ;
if ( ! V_8 -> V_12 . V_13 )
return - V_14 ;
V_10 = V_8 -> V_12 . V_13 (
V_8 -> V_9 ) ;
return V_10 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_8 = V_4 -> V_9 [ V_7 ] ;
if ( ! V_8 )
return;
if ( ! V_8 -> V_12 . V_15 )
return;
V_8 -> V_12 . V_15 ( V_8 -> V_9 ) ;
}
void F_5 ( struct V_16 * V_17 )
{
F_6 ( V_17 ) ;
F_7 ( V_17 ) ;
}
void F_8 ( struct V_18 * V_19 )
{
F_9 ( V_19 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_11 ( V_4 -> V_6 ) ;
}
static int F_12 ( struct V_1 * V_20 ,
struct V_21 * V_22 )
{
int V_10 ;
V_10 = F_13 ( V_20 , V_22 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_14 ( V_20 , V_22 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_13 ( V_20 , V_22 ) ;
if ( V_10 )
return V_10 ;
return V_10 ;
}
static void F_15 ( struct V_21 * V_22 )
{
struct V_1 * V_20 = V_22 -> V_20 ;
F_16 ( V_20 , V_22 ) ;
F_17 ( V_20 , V_22 ,
V_23 |
V_24 ) ;
F_18 ( V_20 , V_22 ) ;
F_19 ( V_22 ) ;
F_20 ( V_20 , V_22 ) ;
F_21 ( V_20 , V_22 ) ;
}
int F_22 ( struct V_1 * V_2 , struct V_25 * V_9 ,
struct V_8 * * V_26 , struct V_27 * V_28 ,
const struct V_29 * V_12 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_8 ;
if ( V_4 -> V_32 >= V_33 )
return - V_11 ;
if ( V_4 -> V_2 -> V_34 )
return - V_35 ;
V_8 = F_23 ( sizeof( * V_8 ) , V_36 ) ;
if ( ! V_8 )
return - V_37 ;
V_8 -> V_12 = * V_12 ;
V_8 -> V_9 = V_9 ;
V_9 -> V_31 = V_31 ;
V_4 -> V_9 [ V_4 -> V_32 ++ ] = V_8 ;
* V_26 = V_8 ;
F_24 ( V_9 ,
V_8 -> V_12 . V_38 ) ;
F_25 ( V_2 , V_9 , V_28 , NULL ,
V_8 -> V_12 . V_39 , NULL ) ;
return 0 ;
}
int F_26 ( struct V_8 * V_8 )
{
struct V_3 * V_4 = V_8 -> V_9 -> V_20 -> V_5 ;
unsigned int V_7 = F_27 ( V_8 -> V_9 ) ;
F_28 ( V_8 -> V_9 ) ;
V_4 -> V_9 [ V_7 ] = NULL ;
F_29 ( V_8 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_18 * V_19 , struct V_30 * V_40 )
{
T_1 V_41 = F_31 ( V_2 , V_40 ) ;
if ( V_41 == 0 )
return - V_42 ;
V_19 -> V_43 = V_41 ;
V_19 -> V_44 = ~ 0 ;
return 0 ;
}
static int F_32 ( struct V_45 * V_20 , void * V_46 )
{
struct V_30 * V_40 = V_46 ;
if ( strcmp ( V_20 -> V_47 -> V_48 , L_1 ) == 0 ) {
struct V_49 * V_50 = V_20 -> V_51 ;
return V_50 -> V_52 == V_40 ;
}
if ( F_33 ( V_40 -> V_48 , L_2 ) == 0 ) {
V_40 = F_34 ( V_40 ) ;
F_35 ( V_40 ) ;
}
return V_20 -> V_52 == V_40 ;
}
static int F_36 ( struct V_45 * V_20 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_10 ;
V_2 = F_37 ( & V_53 , V_20 ) ;
if ( F_38 ( V_2 ) )
return F_39 ( V_2 ) ;
V_4 = F_40 ( V_20 , sizeof( * V_4 ) , V_36 ) ;
if ( ! V_4 ) {
V_10 = - V_37 ;
goto V_54;
}
V_4 -> V_2 = V_2 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_55 = true ;
V_2 -> V_56 . V_57 = 1 ;
V_2 -> V_56 . V_58 = 1 ;
V_2 -> V_56 . V_59 = 4096 ;
V_2 -> V_56 . V_60 = 4096 ;
V_2 -> V_56 . V_61 = & V_62 ;
V_2 -> V_56 . V_63 = & V_64 ;
F_41 ( V_2 ) ;
V_10 = F_42 ( V_2 , V_33 ) ;
if ( V_10 )
goto V_65;
F_43 ( V_20 , V_2 ) ;
V_10 = F_44 ( V_20 , V_2 ) ;
if ( V_10 )
goto V_66;
F_45 ( V_2 ) ;
#if F_46 ( V_67 )
if ( V_68 != 16 && V_68 != 32 ) {
F_47 ( V_20 , L_3 ) ;
V_68 = 16 ;
}
V_4 -> V_6 = F_48 ( V_2 , V_68 , V_33 ) ;
if ( F_38 ( V_4 -> V_6 ) ) {
V_10 = F_39 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
goto V_69;
}
#endif
F_49 ( V_2 ) ;
V_10 = F_50 ( V_2 , 0 ) ;
if ( V_10 )
goto V_70;
return 0 ;
V_70:
F_51 ( V_2 ) ;
#if F_46 ( V_67 )
if ( V_4 -> V_6 )
F_52 ( V_4 -> V_6 ) ;
V_69:
#endif
F_53 ( V_2 -> V_20 , V_2 ) ;
V_66:
F_54 ( V_2 ) ;
V_65:
F_55 ( V_2 ) ;
V_54:
F_56 ( V_2 ) ;
return V_10 ;
}
static void F_57 ( struct V_45 * V_20 )
{
struct V_1 * V_2 = F_58 ( V_20 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_59 ( V_2 ) ;
F_51 ( V_2 ) ;
if ( V_4 -> V_6 )
F_52 ( V_4 -> V_6 ) ;
F_55 ( V_2 ) ;
F_53 ( V_2 -> V_20 , V_2 ) ;
F_43 ( V_20 , NULL ) ;
F_56 ( V_2 ) ;
}
static int F_60 ( struct V_71 * V_72 )
{
int V_10 = F_61 ( & V_72 -> V_20 , F_32 , & V_73 ) ;
if ( ! V_10 )
V_10 = F_62 ( & V_72 -> V_20 , F_63 ( 32 ) ) ;
return V_10 ;
}
static int F_64 ( struct V_71 * V_72 )
{
F_65 ( & V_72 -> V_20 , & V_73 ) ;
return 0 ;
}
static int F_66 ( struct V_45 * V_20 )
{
struct V_1 * V_74 = F_58 ( V_20 ) ;
struct V_3 * V_4 ;
if ( V_74 == NULL )
return 0 ;
F_67 ( V_74 ) ;
V_4 = V_74 -> V_5 ;
V_4 -> V_22 = F_68 ( V_74 ) ;
if ( F_38 ( V_4 -> V_22 ) ) {
F_69 ( V_74 ) ;
return F_39 ( V_4 -> V_22 ) ;
}
return 0 ;
}
static int F_70 ( struct V_45 * V_20 )
{
struct V_1 * V_74 = F_58 ( V_20 ) ;
struct V_3 * V_75 ;
if ( V_74 == NULL )
return 0 ;
V_75 = V_74 -> V_5 ;
F_71 ( V_74 , V_75 -> V_22 ) ;
F_69 ( V_74 ) ;
return 0 ;
}
