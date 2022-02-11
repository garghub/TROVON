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
F_29 ( V_33 , V_42 -> V_45 -> type , V_42 -> V_37 ) ;
}
if ( V_42 -> V_37 ) {
T_1 * V_15 = F_23 ( V_42 -> V_37 ) ;
V_5 = F_22 ( V_2 , V_42 -> V_37 , V_33 ) ;
if ( V_5 )
return V_5 ;
* V_38 = * V_15 ;
* V_44 = V_42 -> V_46 - V_42 -> V_37 -> V_47 ;
}
}
return 0 ;
}
static struct V_48 * F_30 ( struct V_1 * V_2 ,
struct V_18 * V_18 ,
struct V_21 * V_21 ,
struct V_49 * V_50 ,
struct V_13 * V_14 )
{
T_1 V_51 = F_31 ( V_18 ) ;
struct V_48 * V_52 = & V_2 -> V_53 -> V_48 ;
enum V_54 V_55 = V_56 . V_57 ;
int V_5 ;
if ( ! V_58 . V_59 || ! V_50 -> V_60 )
return NULL ;
V_56 . V_57 = V_61 ;
V_5 = F_32 ( V_21 , & V_62 , V_14 ,
V_50 , NULL , NULL , V_63 ) ;
if ( V_5 ) {
V_56 . V_57 = V_55 ;
return NULL ;
}
F_33 ( & V_62 ) ;
while ( 1 ) {
struct V_64 * V_8 ;
struct V_41 V_42 ;
T_1 V_43 = 0 , V_38 = 0 , V_44 = 0 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_8 = F_34 ( & V_62 ) ;
if ( ! V_8 )
break;
V_42 . V_37 = V_8 -> V_37 ;
V_42 . V_45 = V_8 -> V_45 ;
V_42 . V_18 = V_18 ;
V_42 . V_46 = V_8 -> V_65 ;
if ( V_42 . V_45 && ! V_42 . V_37 )
V_42 . V_37 = F_35 ( V_42 . V_45 -> V_33 , V_66 ,
V_42 . V_46 ) ;
F_27 ( V_2 , & V_42 , & V_43 , & V_38 , & V_44 ) ;
V_52 = F_36 ( V_2 -> V_53 , V_52 ,
V_42 . V_37 , V_8 -> V_65 ,
V_51 ) ;
F_37 ( & V_62 ) ;
}
V_56 . V_57 = V_55 ;
if ( V_52 == & V_2 -> V_53 -> V_48 ) {
return NULL ;
}
return V_52 ;
}
int F_38 ( struct V_1 * V_2 , T_2 V_67 ,
const char * V_68 )
{
if ( V_2 -> V_69 )
return V_2 -> V_69 ( V_2 , V_67 , V_68 ) ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 , union V_70 * V_71 ,
struct V_49 * V_50 , struct V_13 * V_14 ,
struct V_41 * V_42 )
{
struct V_21 * V_21 = V_42 -> V_21 ;
struct V_72 V_73 = {
. V_71 = V_71 ,
. V_50 = V_50 ,
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
V_10 = F_40 ( V_42 -> V_18 , V_22 ) ;
V_5 = F_16 ( V_2 , V_21 , V_42 -> V_18 , V_10 ) ;
if ( V_5 )
goto V_27;
if ( V_10 ) {
V_5 = F_20 ( V_2 , V_10 , V_22 ) ;
if ( V_5 )
goto V_27;
V_73 . V_74 = V_10 -> V_15 ;
}
V_73 . V_15 = ++ V_2 -> V_75 ;
V_5 = F_27 ( V_2 , V_42 , & V_73 . V_43 , & V_73 . V_38 , & V_73 . V_44 ) ;
if ( V_5 )
goto V_27;
if ( V_2 -> V_53 ) {
struct V_48 * V_76 = F_30 ( V_2 , V_42 -> V_18 ,
V_21 , V_50 ,
V_14 ) ;
if ( V_76 ) {
F_41 ( V_2 , V_76 ) ;
V_73 . V_77 = V_76 -> V_15 ;
}
}
if ( ( V_14 -> V_78 . V_79 & V_80 ) &&
F_42 ( & V_14 -> V_78 ) ) {
struct V_41 V_81 ;
F_43 ( V_21 , & V_81 , V_50 ) ;
V_5 = F_27 ( V_2 , & V_81 , & V_73 . V_82 ,
& V_73 . V_83 , & V_73 . V_84 ) ;
if ( V_5 )
goto V_27;
if ( V_2 -> V_12 ) {
V_5 = F_44 ( V_21 , V_10 , V_50 , V_42 ,
& V_81 , V_73 . V_15 ,
V_2 -> V_12 ) ;
if ( V_5 )
goto V_27;
}
}
if ( V_2 -> V_72 )
V_5 = V_2 -> V_72 ( V_2 , & V_73 ) ;
V_27:
F_19 ( V_22 ) ;
return V_5 ;
}
int F_45 ( struct V_1 * V_2 )
{
int V_85 , V_5 = 0 ;
for ( V_85 = 0 ; V_86 [ V_85 ] . V_68 ; V_85 ++ ) {
V_5 = F_38 ( V_2 , V_86 [ V_85 ] . V_67 ,
V_86 [ V_85 ] . V_68 ) ;
if ( V_5 )
break;
}
return V_5 ;
}
int F_41 ( struct V_1 * V_2 , struct V_48 * V_76 )
{
int V_5 ;
if ( V_76 -> V_15 )
return 0 ;
if ( V_76 -> V_87 ) {
V_5 = F_41 ( V_2 , V_76 -> V_87 ) ;
if ( V_5 )
return V_5 ;
}
V_76 -> V_15 = ++ V_2 -> V_88 ;
if ( V_2 -> V_89 )
return V_2 -> V_89 ( V_2 , V_76 ) ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
int V_5 ;
if ( V_91 -> V_15 )
return 0 ;
V_5 = F_41 ( V_2 , V_91 -> V_76 ) ;
if ( V_5 )
return V_5 ;
V_91 -> V_15 = ++ V_2 -> V_92 ;
if ( V_2 -> V_93 )
return V_2 -> V_93 ( V_2 , V_91 ) ;
return 0 ;
}
