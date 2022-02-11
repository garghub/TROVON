static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
while ( ! F_2 ( & V_2 -> V_6 ) ) {
V_4 = F_3 ( V_2 -> V_6 . V_7 , struct V_3 ,
V_8 ) ;
V_5 = V_2 -> V_9 ( V_2 , V_4 -> V_10 ) ;
F_4 ( & V_4 -> V_8 ) ;
free ( V_4 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
while ( ! F_2 ( & V_2 -> V_6 ) ) {
V_4 = F_3 ( V_2 -> V_6 . V_7 , struct V_3 ,
V_8 ) ;
F_4 ( & V_4 -> V_8 ) ;
free ( V_4 ) ;
}
}
static int F_6 ( struct V_1 * V_2 , struct V_10 * V_10 )
{
struct V_3 * V_4 ;
V_4 = F_7 ( sizeof( struct V_3 ) ) ;
if ( ! V_4 )
return - V_11 ;
V_4 -> V_10 = V_10 ;
F_8 ( & V_4 -> V_8 , & V_2 -> V_6 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_10 ( & V_2 -> V_6 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_13 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
int F_14 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
if ( V_14 -> V_15 )
return 0 ;
V_14 -> V_15 = ++ V_2 -> V_16 ;
if ( V_2 -> V_17 )
return V_2 -> V_17 ( V_2 , V_14 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
if ( V_18 -> V_15 )
return 0 ;
V_18 -> V_15 = ++ V_2 -> V_19 ;
if ( V_2 -> V_20 )
return V_2 -> V_20 ( V_2 , V_18 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , struct V_21 * V_21 ,
struct V_18 * V_18 , struct V_10 * V_10 )
{
struct V_21 * V_22 ;
T_1 V_23 = 0 ;
int V_5 ;
if ( V_21 -> V_15 )
return 0 ;
V_21 -> V_15 = ++ V_2 -> V_24 ;
if ( V_21 -> V_25 != - 1 ) {
if ( V_21 -> V_25 == V_21 -> V_26 ) {
V_22 = V_21 ;
} else {
V_22 = F_17 ( V_18 ,
V_21 -> V_25 ,
V_21 -> V_25 ) ;
if ( ! V_22 )
return - V_11 ;
V_5 = F_16 ( V_2 , V_22 , V_18 ,
V_10 ) ;
if ( V_5 )
goto V_27;
if ( V_10 ) {
V_5 = F_18 ( V_2 , V_10 , V_21 ) ;
if ( V_5 )
goto V_27;
}
}
V_23 = V_22 -> V_15 ;
if ( V_22 != V_21 )
F_19 ( V_22 ) ;
}
if ( V_2 -> V_28 )
return V_2 -> V_28 ( V_2 , V_21 , V_23 ,
V_18 ) ;
return 0 ;
V_27:
F_19 ( V_22 ) ;
return V_5 ;
}
int F_20 ( struct V_1 * V_2 , struct V_10 * V_10 ,
struct V_21 * V_22 )
{
int V_5 ;
if ( V_10 -> V_15 )
return 0 ;
V_10 -> V_15 = ++ V_2 -> V_29 ;
if ( V_2 -> V_9 ) {
if ( V_22 -> V_30 )
V_5 = V_2 -> V_9 ( V_2 , V_10 ) ;
else
V_5 = F_6 ( V_2 , V_10 ) ;
if ( V_5 )
return V_5 ;
}
return F_18 ( V_2 , V_10 , V_22 ) ;
}
int F_18 ( struct V_1 * V_2 , struct V_10 * V_10 ,
struct V_21 * V_21 )
{
T_1 V_15 ;
V_15 = ++ V_2 -> V_31 ;
if ( V_2 -> V_32 )
return V_2 -> V_32 ( V_2 , V_15 , V_10 , V_21 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , struct V_33 * V_33 ,
struct V_18 * V_18 )
{
if ( V_33 -> V_15 )
return 0 ;
V_33 -> V_15 = ++ V_2 -> V_34 ;
if ( V_2 -> V_35 )
return V_2 -> V_35 ( V_2 , V_33 , V_18 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , struct V_36 * V_37 ,
struct V_33 * V_33 )
{
T_1 * V_38 = F_23 ( V_37 ) ;
if ( * V_38 )
return 0 ;
* V_38 = ++ V_2 -> V_39 ;
if ( V_2 -> V_40 )
return V_2 -> V_40 ( V_2 , V_37 , V_33 ) ;
return 0 ;
}
static struct V_21 * F_24 ( struct V_18 * V_18 , struct V_21 * V_21 )
{
if ( V_21 -> V_25 == V_21 -> V_26 )
return F_25 ( V_21 ) ;
if ( V_21 -> V_25 == - 1 )
return NULL ;
return F_26 ( V_18 , V_21 -> V_25 , V_21 -> V_25 ) ;
}
static int F_27 ( struct V_1 * V_2 , struct V_41 * V_42 ,
T_1 * V_43 , T_1 * V_38 , T_1 * V_44 )
{
int V_5 ;
if ( V_42 -> V_45 ) {
struct V_33 * V_33 = V_42 -> V_45 -> V_33 ;
V_5 = F_21 ( V_2 , V_33 , V_42 -> V_18 ) ;
if ( V_5 )
return V_5 ;
* V_43 = V_33 -> V_15 ;
if ( ! V_42 -> V_37 ) {
V_42 -> V_37 = F_28 ( V_42 -> V_46 , 0 , 0 , L_1 ) ;
if ( V_42 -> V_37 )
F_29 ( & V_33 -> V_47 [ V_42 -> V_45 -> type ] ,
V_42 -> V_37 ) ;
}
if ( V_42 -> V_37 ) {
T_1 * V_15 = F_23 ( V_42 -> V_37 ) ;
V_5 = F_22 ( V_2 , V_42 -> V_37 , V_33 ) ;
if ( V_5 )
return V_5 ;
* V_38 = * V_15 ;
* V_44 = V_42 -> V_46 - V_42 -> V_37 -> V_48 ;
}
}
return 0 ;
}
int F_30 ( struct V_1 * V_2 , T_2 V_49 ,
const char * V_50 )
{
if ( V_2 -> V_51 )
return V_2 -> V_51 ( V_2 , V_49 , V_50 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , union V_52 * V_53 ,
struct V_54 * V_55 , struct V_13 * V_14 ,
struct V_41 * V_42 )
{
struct V_21 * V_21 = V_42 -> V_21 ;
struct V_56 V_57 = {
. V_53 = V_53 ,
. V_55 = V_55 ,
. V_14 = V_14 ,
. V_42 = V_42 ,
} ;
struct V_21 * V_22 ;
struct V_10 * V_10 = NULL ;
int V_5 ;
V_5 = F_14 ( V_2 , V_14 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_15 ( V_2 , V_42 -> V_18 ) ;
if ( V_5 )
return V_5 ;
V_22 = F_24 ( V_42 -> V_18 , V_21 ) ;
if ( V_22 )
V_10 = F_32 ( V_42 -> V_18 , V_22 ) ;
V_5 = F_16 ( V_2 , V_21 , V_42 -> V_18 , V_10 ) ;
if ( V_5 )
goto V_27;
if ( V_10 ) {
V_5 = F_20 ( V_2 , V_10 , V_22 ) ;
if ( V_5 )
goto V_27;
V_57 . V_58 = V_10 -> V_15 ;
}
V_57 . V_15 = ++ V_2 -> V_59 ;
V_5 = F_27 ( V_2 , V_42 , & V_57 . V_43 , & V_57 . V_38 , & V_57 . V_44 ) ;
if ( V_5 )
goto V_27;
if ( ( V_14 -> V_60 . V_61 & V_62 ) &&
F_33 ( & V_14 -> V_60 ) ) {
struct V_41 V_63 ;
F_34 ( V_21 , & V_63 , V_55 ) ;
V_5 = F_27 ( V_2 , & V_63 , & V_57 . V_64 ,
& V_57 . V_65 , & V_57 . V_66 ) ;
if ( V_5 )
goto V_27;
if ( V_2 -> V_12 ) {
V_5 = F_35 ( V_21 , V_10 , V_55 , V_42 ,
& V_63 , V_57 . V_15 ,
V_2 -> V_12 ) ;
if ( V_5 )
goto V_27;
}
}
if ( V_2 -> V_56 )
V_5 = V_2 -> V_56 ( V_2 , & V_57 ) ;
V_27:
F_19 ( V_22 ) ;
return V_5 ;
}
int F_36 ( struct V_1 * V_2 )
{
int V_67 , V_5 = 0 ;
for ( V_67 = 0 ; V_68 [ V_67 ] . V_50 ; V_67 ++ ) {
V_5 = F_30 ( V_2 , V_68 [ V_67 ] . V_49 ,
V_68 [ V_67 ] . V_50 ) ;
if ( V_5 )
break;
}
return V_5 ;
}
int F_37 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
int V_5 ;
if ( V_70 -> V_15 )
return 0 ;
if ( V_70 -> V_71 ) {
V_5 = F_37 ( V_2 , V_70 -> V_71 ) ;
if ( V_5 )
return V_5 ;
}
V_70 -> V_15 = ++ V_2 -> V_72 ;
if ( V_2 -> V_73 )
return V_2 -> V_73 ( V_2 , V_70 ) ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
int V_5 ;
if ( V_75 -> V_15 )
return 0 ;
V_5 = F_37 ( V_2 , V_75 -> V_70 ) ;
if ( V_5 )
return V_5 ;
V_75 -> V_15 = ++ V_2 -> V_76 ;
if ( V_2 -> V_77 )
return V_2 -> V_77 ( V_2 , V_75 ) ;
return 0 ;
}
