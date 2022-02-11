int F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return - V_7 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_8 = V_1 ;
F_3 ( & V_9 ) ;
F_4 ( & V_5 -> V_10 , & V_11 ) ;
F_5 ( & V_9 ) ;
return 0 ;
}
void F_6 ( int V_1 )
{
struct V_4 * V_5 , * V_12 ;
F_3 ( & V_9 ) ;
F_7 (its_msi_chip, t, &iort_msi_chip_list, list) {
if ( V_5 -> V_8 == V_1 ) {
F_8 ( & V_5 -> V_10 ) ;
F_9 ( V_5 ) ;
break;
}
}
F_5 ( & V_9 ) ;
}
struct V_2 * F_10 ( int V_1 )
{
struct V_2 * V_3 = NULL ;
struct V_4 * V_5 ;
F_3 ( & V_9 ) ;
F_11 (its_msi_chip, &iort_msi_chip_list, list) {
if ( V_5 -> V_8 == V_1 ) {
V_3 = V_5 -> V_3 ;
break;
}
}
F_5 ( & V_9 ) ;
return V_3 ;
}
static struct V_13 * F_12 ( enum V_14 type ,
T_1 V_15 ,
void * V_16 )
{
struct V_13 * V_17 , * V_18 ;
struct V_19 * V_20 ;
int V_21 ;
if ( ! V_22 )
return NULL ;
V_20 = (struct V_19 * ) V_22 ;
V_17 = F_13 ( struct V_13 , V_20 ,
V_20 -> V_23 ) ;
V_18 = F_13 ( struct V_13 , V_22 ,
V_22 -> V_24 ) ;
for ( V_21 = 0 ; V_21 < V_20 -> V_25 ; V_21 ++ ) {
if ( F_14 ( V_17 >= V_18 , V_26 ,
L_1 ) )
return NULL ;
if ( V_17 -> type == type &&
F_15 ( V_15 ( V_17 , V_16 ) ) )
return V_17 ;
V_17 = F_13 ( struct V_13 , V_17 ,
V_17 -> V_24 ) ;
}
return NULL ;
}
static T_2 F_16 ( struct V_13 * V_27 ,
void * V_16 )
{
struct V_28 * V_29 = V_16 ;
T_2 V_30 ;
if ( V_27 -> type == V_31 ) {
struct V_32 V_33 = { V_34 , NULL } ;
struct V_35 * V_36 = F_17 ( V_29 -> V_37 ) ;
struct V_38 * V_39 ;
if ( ! V_36 ) {
V_30 = V_40 ;
goto V_41;
}
V_30 = F_18 ( V_36 -> V_42 , V_43 , & V_33 ) ;
if ( F_19 ( V_30 ) ) {
F_20 ( V_29 , L_2 ) ;
goto V_41;
}
V_39 = (struct V_38 * ) V_27 -> V_44 ;
V_30 = ! strcmp ( V_39 -> V_45 , V_33 . V_46 ) ?
V_47 : V_40 ;
F_21 ( V_33 . V_46 ) ;
} else if ( V_27 -> type == V_48 ) {
struct V_49 * V_50 ;
struct V_51 * V_52 ;
V_52 = F_22 ( V_29 ) ;
V_50 = (struct V_49 * ) V_27 -> V_44 ;
V_30 = V_50 -> V_53 == F_23 ( V_52 ) ?
V_47 : V_40 ;
} else {
V_30 = V_40 ;
}
V_41:
return V_30 ;
}
static int F_24 ( struct V_54 * V_55 , T_3 type , T_4 V_56 ,
T_4 * V_57 )
{
if ( V_55 -> V_58 & V_59 ) {
if ( type == V_31 ||
type == V_48 ) {
* V_57 = V_55 -> V_60 ;
return 0 ;
}
F_25 ( V_61 L_3 ,
V_55 , type ) ;
return - V_62 ;
}
if ( V_56 < V_55 -> V_63 ||
( V_56 >= V_55 -> V_63 + V_55 -> V_64 ) )
return - V_62 ;
* V_57 = V_55 -> V_60 + ( V_56 - V_55 -> V_63 ) ;
return 0 ;
}
static struct V_13 * F_26 ( struct V_13 * V_27 ,
T_4 V_56 , T_4 * V_57 ,
T_3 type )
{
T_4 V_65 = V_56 ;
while ( V_27 ) {
struct V_54 * V_55 ;
int V_21 ;
if ( V_27 -> type == type ) {
if ( V_57 )
* V_57 = V_65 ;
return V_27 ;
}
if ( ! V_27 -> V_66 || ! V_27 -> V_67 )
goto V_68;
V_55 = F_13 ( struct V_54 , V_27 ,
V_27 -> V_66 ) ;
if ( ! V_55 -> V_69 ) {
F_27 ( V_61 L_4 ,
V_27 , V_27 -> type ) ;
goto V_68;
}
for ( V_21 = 0 ; V_21 < V_27 -> V_67 ; V_21 ++ , V_55 ++ ) {
if ( ! F_24 ( V_55 , V_27 -> type , V_65 , & V_65 ) )
break;
}
if ( V_21 == V_27 -> V_67 )
goto V_68;
V_27 = F_13 ( struct V_13 , V_22 ,
V_55 -> V_69 ) ;
}
V_68:
if ( V_57 )
* V_57 = V_56 ;
return NULL ;
}
static struct V_13 * F_28 ( struct V_28 * V_29 )
{
struct V_51 * V_70 ;
if ( ! F_29 ( V_29 ) )
return F_12 ( V_31 ,
F_16 , V_29 ) ;
V_70 = F_30 ( V_29 ) -> V_52 ;
while ( ! F_31 ( V_70 ) )
V_70 = V_70 -> V_71 ;
return F_12 ( V_48 ,
F_16 , & V_70 -> V_29 ) ;
}
T_4 F_32 ( struct V_28 * V_29 , T_4 V_72 )
{
struct V_13 * V_27 ;
T_4 V_73 ;
V_27 = F_28 ( V_29 ) ;
if ( ! V_27 )
return V_72 ;
F_26 ( V_27 , V_72 , & V_73 , V_74 ) ;
return V_73 ;
}
static int F_33 ( struct V_28 * V_29 , T_4 V_72 ,
unsigned int V_75 , int * V_76 )
{
struct V_77 * V_78 ;
struct V_13 * V_27 ;
V_27 = F_28 ( V_29 ) ;
if ( ! V_27 )
return - V_62 ;
V_27 = F_26 ( V_27 , V_72 , NULL , V_74 ) ;
if ( ! V_27 )
return - V_62 ;
V_78 = (struct V_77 * ) V_27 -> V_44 ;
if ( V_75 > V_78 -> V_79 ) {
F_34 ( V_29 , L_5 ,
V_75 , V_78 -> V_79 ) ;
return - V_62 ;
}
* V_76 = V_78 -> V_80 [ V_75 ] ;
return 0 ;
}
struct V_81 * F_35 ( struct V_28 * V_29 , T_4 V_72 )
{
struct V_2 * V_42 ;
int V_76 ;
if ( F_33 ( V_29 , V_72 , 0 , & V_76 ) )
return NULL ;
V_42 = F_10 ( V_76 ) ;
if ( ! V_42 )
return NULL ;
return F_36 ( V_42 , V_82 ) ;
}
void T_5 F_37 ( void )
{
T_2 V_30 ;
V_30 = F_38 ( V_83 , 0 , & V_22 ) ;
if ( F_19 ( V_30 ) && V_30 != V_40 ) {
const char * V_84 = F_39 ( V_30 ) ;
F_27 ( L_6 , V_84 ) ;
}
}
