static T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 ;
V_3 = V_2 -> V_4 . V_5 -> V_3 ;
return ( V_3 << ( 32 - V_6 ) ) | V_2 -> V_4 . V_7 ;
}
static void F_2 ( T_3 * V_8 , struct V_1 * V_2 )
{
V_8 -> V_2 = V_2 ;
V_8 -> V_9 = F_1 ( V_2 ) ;
}
static int F_3 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
unsigned int V_14 , T_1 V_9 ,
T_3 * V_8 )
{
return F_4 ( V_11 , V_14 , V_9 ,
V_13 -> V_15 , V_13 -> V_16 ) ;
}
static void F_5 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = V_13 -> V_18 ;
F_6 ( ! V_18 ) ;
if ( V_18 -> V_19 == NULL )
V_18 -> V_19 = F_3 ;
if ( V_18 -> V_20 == NULL )
V_18 -> V_20 = F_2 ;
}
static void F_7 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_8 ( V_22 ) ;
struct V_25 * V_26 ;
V_26 = V_2 -> V_4 . V_5 ;
V_26 -> V_27 ( V_2 , V_24 ) ;
}
static void F_9 ( struct V_12 * V_13 )
{
struct V_28 * V_15 = V_13 -> V_15 ;
F_6 ( ! V_15 ) ;
if ( ! V_15 -> V_29 )
V_15 -> V_29 = V_30 ;
if ( ! V_15 -> V_31 )
V_15 -> V_31 = V_32 ;
if ( ! V_15 -> V_33 )
V_15 -> V_33 = V_34 ;
if ( ! V_15 -> V_35 )
V_15 -> V_35 = V_36 ;
if ( ! V_15 -> V_37 )
V_15 -> V_37 = F_7 ;
}
static void F_10 ( struct V_38 * V_39 , int V_40 , int V_41 )
{
struct V_1 * V_2 , * V_42 ;
F_11 (desc, tmp, dev_to_msi_list(dev), list) {
if ( V_2 -> V_4 . V_7 >= V_40 &&
V_2 -> V_4 . V_7 < ( V_40 + V_41 ) ) {
F_12 ( & V_2 -> V_43 ) ;
F_13 ( V_2 ) ;
}
}
}
static int F_14 ( struct V_38 * V_39 , int V_14 ,
int V_41 ,
struct V_25 * V_22 )
{
struct V_1 * V_2 ;
int V_44 , V_40 = 0 ;
if ( ! F_15 ( F_16 ( V_39 ) ) ) {
V_2 = F_17 ( F_16 ( V_39 ) ,
struct V_1 , V_43 ) ;
V_40 = V_2 -> V_4 . V_7 + 1 ;
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
V_2 = F_18 ( V_39 , 1 , NULL ) ;
if ( ! V_2 )
break;
V_2 -> V_4 . V_5 = V_22 ;
V_2 -> V_4 . V_7 = V_40 + V_44 ;
V_2 -> V_45 = V_14 ? V_14 + V_44 : 0 ;
F_19 ( & V_2 -> V_43 , F_16 ( V_39 ) ) ;
}
if ( V_44 != V_41 ) {
F_10 ( V_39 , V_40 , V_41 ) ;
return - V_46 ;
}
return 0 ;
}
static int F_20 ( struct V_38 * V_39 , int V_41 ,
struct V_25 * V_22 )
{
return F_14 ( V_39 , 0 , V_41 , V_22 ) ;
}
struct V_10 * F_21 ( struct V_47 * V_48 ,
struct V_12 * V_13 ,
struct V_10 * V_49 )
{
struct V_10 * V_11 ;
if ( V_13 -> V_50 & V_51 )
F_5 ( V_13 ) ;
if ( V_13 -> V_50 & V_52 )
F_9 ( V_13 ) ;
V_11 = F_22 ( V_48 , V_13 , V_49 ) ;
if ( V_11 )
V_11 -> V_53 = V_54 ;
return V_11 ;
}
static struct V_25 *
F_23 ( struct V_38 * V_39 , unsigned int V_41 ,
T_4 V_55 )
{
struct V_25 * V_56 ;
if ( ! V_39 -> V_57 || ! V_55 || ! V_41 || V_41 > V_58 )
return F_24 ( - V_59 ) ;
if ( V_39 -> V_57 -> V_53 != V_54 ) {
F_25 ( V_39 , L_1 ) ;
return F_24 ( - V_59 ) ;
}
if ( ! F_15 ( F_16 ( V_39 ) ) )
return F_24 ( - V_60 ) ;
V_56 = F_26 ( sizeof( * V_56 ) , V_61 ) ;
if ( ! V_56 )
return F_24 ( - V_46 ) ;
V_56 -> V_3 = F_27 ( & V_62 ,
0 , 1 << V_6 , V_61 ) ;
if ( V_56 -> V_3 < 0 ) {
int V_63 = V_56 -> V_3 ;
F_28 ( V_56 ) ;
return F_24 ( V_63 ) ;
}
V_56 -> V_27 = V_55 ;
V_56 -> V_39 = V_39 ;
return V_56 ;
}
static void F_29 ( struct V_25 * V_22 )
{
F_30 ( & V_62 , V_22 -> V_3 ) ;
F_28 ( V_22 ) ;
}
int F_31 ( struct V_38 * V_39 , unsigned int V_41 ,
T_4 V_55 )
{
struct V_25 * V_26 ;
int V_63 ;
V_26 = F_23 ( V_39 , V_41 , V_55 ) ;
if ( F_32 ( V_26 ) )
return F_33 ( V_26 ) ;
V_63 = F_20 ( V_39 , V_41 , V_26 ) ;
if ( V_63 )
goto V_64;
V_63 = F_34 ( V_39 -> V_57 , V_39 , V_41 ) ;
if ( V_63 )
goto V_65;
return 0 ;
V_65:
F_10 ( V_39 , 0 , V_41 ) ;
V_64:
F_29 ( V_26 ) ;
return V_63 ;
}
void F_35 ( struct V_38 * V_39 )
{
if ( ! F_15 ( F_16 ( V_39 ) ) ) {
struct V_1 * V_2 ;
V_2 = F_36 ( V_39 ) ;
F_29 ( V_2 -> V_4 . V_5 ) ;
}
F_37 ( V_39 -> V_57 , V_39 ) ;
F_10 ( V_39 , 0 , V_58 ) ;
}
void * F_38 ( struct V_10 * V_11 )
{
struct V_25 * V_22 = V_11 -> V_66 ;
return V_22 -> V_66 ;
}
struct V_10 *
F_39 ( struct V_38 * V_39 ,
unsigned int V_41 ,
T_4 V_55 ,
const struct V_67 * V_18 ,
void * V_66 )
{
struct V_25 * V_22 ;
struct V_10 * V_11 ;
int V_63 ;
V_22 = F_23 ( V_39 , V_41 , V_55 ) ;
if ( F_32 ( V_22 ) )
return NULL ;
V_22 -> V_66 = V_66 ;
V_11 = F_40 ( V_39 -> V_57 , 0 , V_41 ,
F_41 ( V_39 -> V_68 ) ,
V_18 , V_22 ) ;
if ( ! V_11 )
goto V_69;
V_63 = F_42 ( V_11 -> V_49 , V_39 , V_41 , & V_22 -> V_8 ) ;
if ( V_63 )
goto V_70;
return V_11 ;
V_70:
F_43 ( V_11 ) ;
V_69:
F_29 ( V_22 ) ;
return NULL ;
}
void F_44 ( struct V_10 * V_11 , unsigned int V_14 ,
unsigned int V_41 )
{
struct V_25 * V_22 = V_11 -> V_66 ;
struct V_1 * V_2 ;
F_45 (desc, data->dev) {
if ( F_46 ( ! V_2 -> V_45 || V_2 -> V_71 != 1 ) )
return;
if ( ! ( V_2 -> V_45 >= V_14 && V_2 -> V_45 < ( V_14 + V_41 ) ) )
continue;
F_47 ( V_11 , V_2 -> V_45 , 1 ) ;
}
}
int F_48 ( struct V_10 * V_11 , unsigned int V_14 ,
unsigned int V_72 )
{
struct V_25 * V_22 = V_11 -> V_66 ;
int V_63 ;
V_63 = F_14 ( V_22 -> V_39 , V_14 , V_72 , V_22 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_49 ( V_11 -> V_49 , V_22 -> V_39 ,
V_14 , V_72 , & V_22 -> V_8 ) ;
if ( V_63 )
F_44 ( V_11 , V_14 , V_72 ) ;
return V_63 ;
}
