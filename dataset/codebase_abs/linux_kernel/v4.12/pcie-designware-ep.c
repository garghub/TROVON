void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_4 ) ;
}
static void F_3 ( struct V_5 * V_6 , enum V_7 V_8 )
{
T_1 V_9 ;
V_9 = V_10 + ( 4 * V_8 ) ;
F_4 ( V_6 , V_9 , 0x0 ) ;
F_5 ( V_6 , V_9 , 0x0 ) ;
}
static int F_6 ( struct V_3 * V_4 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
struct V_5 * V_6 = F_8 ( V_2 ) ;
F_9 ( V_6 , V_13 , V_12 -> V_14 ) ;
F_9 ( V_6 , V_15 , V_12 -> V_16 ) ;
F_10 ( V_6 , V_17 , V_12 -> V_18 ) ;
F_10 ( V_6 , V_19 , V_12 -> V_20 ) ;
F_9 ( V_6 , V_21 ,
V_12 -> V_22 | V_12 -> V_23 << 8 ) ;
F_10 ( V_6 , V_24 ,
V_12 -> V_25 ) ;
F_9 ( V_6 , V_26 ,
V_12 -> V_27 ) ;
F_9 ( V_6 , V_28 , V_12 -> V_29 ) ;
F_10 ( V_6 , V_30 ,
V_12 -> V_31 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , enum V_7 V_8 ,
T_2 V_32 ,
enum V_33 V_34 )
{
int V_35 ;
T_1 V_36 ;
struct V_5 * V_6 = F_8 ( V_2 ) ;
V_36 = F_12 ( & V_2 -> V_37 ,
sizeof( V_2 -> V_37 ) ) ;
if ( V_36 >= V_2 -> V_38 ) {
F_13 ( V_6 -> V_39 , L_1 ) ;
return - V_40 ;
}
V_35 = F_14 ( V_6 , V_36 , V_8 , V_32 ,
V_34 ) ;
if ( V_35 < 0 ) {
F_13 ( V_6 -> V_39 , L_2 ) ;
return V_35 ;
}
V_2 -> V_41 [ V_8 ] = V_36 ;
F_15 ( V_36 , & V_2 -> V_37 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_3 V_42 ,
T_4 V_43 , T_5 V_44 )
{
T_1 V_36 ;
struct V_5 * V_6 = F_8 ( V_2 ) ;
V_36 = F_12 ( & V_2 -> V_45 ,
sizeof( V_2 -> V_45 ) ) ;
if ( V_36 >= V_2 -> V_46 ) {
F_13 ( V_6 -> V_39 , L_3 ) ;
return - V_40 ;
}
F_17 ( V_6 , V_36 , V_47 ,
V_42 , V_43 , V_44 ) ;
F_15 ( V_36 , & V_2 -> V_45 ) ;
V_2 -> V_48 [ V_36 ] = V_42 ;
return 0 ;
}
static void F_18 ( struct V_3 * V_4 , enum V_7 V_8 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
struct V_5 * V_6 = F_8 ( V_2 ) ;
T_1 V_49 = V_2 -> V_41 [ V_8 ] ;
F_3 ( V_6 , V_8 ) ;
F_19 ( V_6 , V_49 , V_50 ) ;
F_20 ( V_49 , & V_2 -> V_37 ) ;
}
static int F_21 ( struct V_3 * V_4 , enum V_7 V_8 ,
T_2 V_51 , T_5 V_44 , int V_52 )
{
int V_35 ;
struct V_1 * V_2 = F_7 ( V_4 ) ;
struct V_5 * V_6 = F_8 ( V_2 ) ;
enum V_33 V_34 ;
T_1 V_9 = V_10 + ( 4 * V_8 ) ;
if ( ! ( V_52 & V_53 ) )
V_34 = V_54 ;
else
V_34 = V_55 ;
V_35 = F_11 ( V_2 , V_8 , V_51 , V_34 ) ;
if ( V_35 )
return V_35 ;
F_4 ( V_6 , V_9 , V_44 - 1 ) ;
F_5 ( V_6 , V_9 , V_52 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_3 V_56 ,
T_1 * V_49 )
{
T_1 V_57 ;
for ( V_57 = 0 ; V_57 < V_2 -> V_46 ; V_57 ++ ) {
if ( V_2 -> V_48 [ V_57 ] != V_56 )
continue;
* V_49 = V_57 ;
return 0 ;
}
return - V_40 ;
}
static void F_23 ( struct V_3 * V_4 , T_3 V_56 )
{
int V_35 ;
T_1 V_49 ;
struct V_1 * V_2 = F_7 ( V_4 ) ;
struct V_5 * V_6 = F_8 ( V_2 ) ;
V_35 = F_22 ( V_2 , V_56 , & V_49 ) ;
if ( V_35 < 0 )
return;
F_19 ( V_6 , V_49 , V_58 ) ;
F_20 ( V_49 , & V_2 -> V_45 ) ;
}
static int F_24 ( struct V_3 * V_4 , T_3 V_56 ,
T_4 V_43 , T_5 V_44 )
{
int V_35 ;
struct V_1 * V_2 = F_7 ( V_4 ) ;
struct V_5 * V_6 = F_8 ( V_2 ) ;
V_35 = F_16 ( V_2 , V_56 , V_43 , V_44 ) ;
if ( V_35 ) {
F_13 ( V_6 -> V_39 , L_4 ) ;
return V_35 ;
}
return 0 ;
}
static int F_25 ( struct V_3 * V_4 )
{
int V_59 ;
T_1 V_60 ;
T_1 V_61 ;
struct V_1 * V_2 = F_7 ( V_4 ) ;
struct V_5 * V_6 = F_8 ( V_2 ) ;
V_59 = F_26 ( V_6 , V_62 ) ;
V_59 = ( V_59 & V_63 ) >> V_64 ;
V_60 = F_27 ( V_6 , V_65 ) ;
V_61 = F_27 ( V_6 , V_66 ) ;
if ( ! ( V_60 || V_61 ) )
return - V_40 ;
return V_59 ;
}
static int F_28 ( struct V_3 * V_4 , T_6 V_67 )
{
int V_59 ;
struct V_1 * V_2 = F_7 ( V_4 ) ;
struct V_5 * V_6 = F_8 ( V_2 ) ;
V_59 = ( V_67 << V_68 ) ;
F_9 ( V_6 , V_62 , V_59 ) ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 ,
enum V_69 type , T_6 V_70 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
if ( ! V_2 -> V_71 -> V_72 )
return - V_40 ;
return V_2 -> V_71 -> V_72 ( V_2 , type , V_70 ) ;
}
static void F_30 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
struct V_5 * V_6 = F_8 ( V_2 ) ;
if ( ! V_6 -> V_71 -> V_73 )
return;
V_6 -> V_71 -> V_73 ( V_6 ) ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_7 ( V_4 ) ;
struct V_5 * V_6 = F_8 ( V_2 ) ;
if ( ! V_6 -> V_71 -> V_74 )
return - V_40 ;
return V_6 -> V_71 -> V_74 ( V_6 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_33 ( V_4 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_35 ;
void * V_56 ;
enum V_7 V_8 ;
struct V_3 * V_4 ;
struct V_5 * V_6 = F_8 ( V_2 ) ;
struct V_75 * V_39 = V_6 -> V_39 ;
struct V_76 * V_77 = V_39 -> V_78 ;
if ( ! V_6 -> V_79 || ! V_6 -> V_80 ) {
F_13 ( V_39 , L_5 ) ;
return - V_40 ;
}
V_35 = F_35 ( V_77 , L_6 , & V_2 -> V_38 ) ;
if ( V_35 < 0 ) {
F_13 ( V_39 , L_7 ) ;
return V_35 ;
}
V_35 = F_35 ( V_77 , L_8 , & V_2 -> V_46 ) ;
if ( V_35 < 0 ) {
F_13 ( V_39 , L_9 ) ;
return V_35 ;
}
V_56 = F_36 ( V_39 , sizeof( T_3 ) * V_2 -> V_46 ,
V_81 ) ;
if ( ! V_56 )
return - V_82 ;
V_2 -> V_48 = V_56 ;
for ( V_8 = V_83 ; V_8 <= V_84 ; V_8 ++ )
F_3 ( V_6 , V_8 ) ;
if ( V_2 -> V_71 -> V_85 )
V_2 -> V_71 -> V_85 ( V_2 ) ;
V_4 = F_37 ( V_39 , & V_86 ) ;
if ( F_38 ( V_4 ) ) {
F_13 ( V_39 , L_10 ) ;
return F_39 ( V_4 ) ;
}
V_35 = F_40 ( V_77 , L_11 , & V_4 -> V_87 ) ;
if ( V_35 < 0 )
V_4 -> V_87 = 1 ;
V_35 = F_41 ( V_4 , V_2 -> V_88 , V_2 -> V_89 ) ;
if ( V_35 < 0 ) {
F_13 ( V_39 , L_12 ) ;
return V_35 ;
}
V_2 -> V_4 = V_4 ;
F_42 ( V_4 , V_2 ) ;
F_43 ( V_6 ) ;
return 0 ;
}
