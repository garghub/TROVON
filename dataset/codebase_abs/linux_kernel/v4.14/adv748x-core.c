static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
if ( ! V_2 -> V_5 [ V_3 ] )
return - V_6 ;
V_2 -> V_7 [ V_3 ] =
F_2 ( V_2 -> V_5 [ V_3 ] ,
& V_8 [ V_3 ] ) ;
if ( F_3 ( V_2 -> V_7 [ V_3 ] ) ) {
V_4 = F_4 ( V_2 -> V_7 [ V_3 ] ) ;
F_5 ( V_2 ,
L_1 ,
V_3 , V_4 ) ;
return - V_9 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
int V_10 , T_1 V_11 )
{
struct V_12 * V_13 = V_2 -> V_5 [ V_10 ] ;
int V_4 ;
unsigned int V_14 ;
V_4 = F_7 ( V_2 -> V_7 [ V_10 ] , V_11 , & V_14 ) ;
if ( V_4 ) {
F_5 ( V_2 , L_2 ,
V_13 -> V_15 , V_11 ) ;
return V_4 ;
}
return V_14 ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_11 )
{
return F_6 ( V_2 , V_16 , V_11 ) ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_11 , T_1 V_17 )
{
return F_10 ( V_2 -> V_7 [ V_16 ] , V_11 , V_17 ) ;
}
int F_11 ( struct V_1 * V_2 , int V_10 ,
unsigned int V_18 , const void * V_14 ,
T_2 V_19 )
{
struct V_7 * V_7 = V_2 -> V_7 [ V_10 ] ;
if ( V_19 > V_20 )
V_19 = V_20 ;
return F_12 ( V_7 , V_18 , V_14 , V_19 ) ;
}
static struct V_12 * F_13 ( struct V_1 * V_2 ,
T_1 V_15 , T_1 V_21 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
if ( V_15 )
F_14 ( V_2 , V_21 , V_15 << 1 ) ;
return F_15 ( V_13 -> V_22 , F_16 ( V_2 , V_21 ) >> 1 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
unsigned int V_23 ;
for ( V_23 = 1 ; V_23 < F_18 ( V_2 -> V_5 ) ; ++ V_23 ) {
if ( V_2 -> V_5 [ V_23 ] )
F_19 ( V_2 -> V_5 [ V_23 ] ) ;
}
}
static int F_20 ( struct V_1 * V_2 )
{
int V_23 ;
int V_24 ;
for ( V_23 = V_25 ; V_23 < V_26 ; ++ V_23 ) {
V_2 -> V_5 [ V_23 ] =
F_13 ( V_2 , V_27 [ V_23 ] ,
V_28 + V_23 ) ;
if ( V_2 -> V_5 [ V_23 ] == NULL ) {
F_5 ( V_2 , L_3 , V_23 ) ;
return - V_29 ;
}
V_24 = F_1 ( V_2 , V_23 ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_30 * V_31 )
{
int V_24 ;
while ( V_31 -> V_16 != V_32 ) {
if ( V_31 -> V_16 == V_33 ) {
F_22 ( V_31 -> V_17 ) ;
} else {
V_24 = F_9 ( V_2 , V_31 -> V_16 , V_31 -> V_11 ,
V_31 -> V_17 ) ;
if ( V_24 < 0 ) {
F_5 ( V_2 ,
L_4 ,
V_31 -> V_16 , V_31 -> V_11 ) ;
return V_24 ;
}
}
V_31 ++ ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 , bool V_34 )
{
int V_14 ;
V_14 = F_24 ( V_2 , V_35 ) ;
if ( V_14 < 0 )
return V_14 ;
F_25 ( ( V_34 && V_14 & V_36 ) ,
L_5 ) ;
if ( V_34 )
return F_21 ( V_2 , V_37 ) ;
return F_21 ( V_2 , V_38 ) ;
}
int F_26 ( struct V_1 * V_2 , bool V_34 )
{
int V_14 ;
V_14 = F_27 ( V_2 , V_35 ) ;
if ( V_14 < 0 )
return V_14 ;
F_25 ( ( V_34 && V_14 & V_36 ) ,
L_5 ) ;
if ( V_34 )
return F_21 ( V_2 , V_39 ) ;
return F_21 ( V_2 , V_40 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_24 ;
V_24 = F_21 ( V_2 , V_41 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_21 ( V_2 , V_42 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_21 ( V_2 , V_43 ) ;
if ( V_24 )
return V_24 ;
F_23 ( V_2 , 0 ) ;
V_24 = F_21 ( V_2 , V_44 ) ;
if ( V_24 )
return V_24 ;
F_26 ( V_2 , 0 ) ;
F_14 ( V_2 , V_45 , V_46 ) ;
F_14 ( V_2 , V_47 , V_48 |
V_49 |
V_50 ) ;
F_29 ( V_2 , V_51 , V_52 ,
V_52 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_53 , V_54 ;
V_54 = F_16 ( V_2 , V_55 ) ;
V_53 = F_16 ( V_2 , V_56 ) ;
if ( V_54 < 0 || V_53 < 0 ) {
F_5 ( V_2 , L_6 ) ;
return - V_57 ;
}
F_31 ( V_2 , L_7 ,
V_2 -> V_13 -> V_15 << 1 , V_54 , V_53 ) ;
return 0 ;
}
void F_32 ( struct V_58 * V_59 , struct V_1 * V_2 ,
const struct V_60 * V_61 , T_3 V_62 ,
const char * V_63 )
{
F_33 ( V_59 , V_61 ) ;
V_59 -> V_64 |= V_65 ;
V_59 -> V_66 = V_2 -> V_67 -> V_68 -> V_66 ;
V_59 -> V_67 = V_2 -> V_67 ;
F_34 ( V_59 , V_2 ) ;
snprintf ( V_59 -> V_69 , sizeof( V_59 -> V_69 ) , L_8 ,
V_2 -> V_67 -> V_68 -> V_69 ,
F_35 ( V_2 -> V_13 -> V_22 ) ,
V_2 -> V_13 -> V_15 , V_63 ) ;
V_59 -> V_70 . V_62 = V_62 ;
V_59 -> V_70 . V_61 = & V_71 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_72 * V_73 = NULL ;
struct V_74 V_75 ;
bool V_76 = false ;
F_37 (state->dev->of_node, ep_np) {
F_38 ( V_73 , & V_75 ) ;
F_31 ( V_2 , L_9 ,
F_39 ( V_75 . V_77 ) ,
V_75 . V_78 ) ;
if ( V_75 . V_78 >= V_79 ) {
F_5 ( V_2 , L_10 ,
F_39 ( V_75 . V_77 ) ,
V_75 . V_78 ) ;
continue;
}
if ( V_2 -> V_80 [ V_75 . V_78 ] ) {
F_5 ( V_2 ,
L_11 ) ;
continue;
}
F_40 ( V_73 ) ;
V_2 -> V_80 [ V_75 . V_78 ] = V_73 ;
V_76 = true ;
}
return V_76 ? 0 : - V_6 ;
}
static void F_41 ( struct V_1 * V_2 )
{
unsigned int V_23 ;
for ( V_23 = 0 ; V_23 < V_79 ; V_23 ++ )
F_42 ( V_2 -> V_80 [ V_23 ] ) ;
}
static int F_43 ( struct V_12 * V_13 ,
const struct V_81 * V_82 )
{
struct V_1 * V_2 ;
int V_24 ;
if ( ! F_44 ( V_13 -> V_22 , V_83 ) )
return - V_57 ;
V_2 = F_45 ( sizeof( struct V_1 ) , V_84 ) ;
if ( ! V_2 )
return - V_29 ;
F_46 ( & V_2 -> V_85 ) ;
V_2 -> V_67 = & V_13 -> V_67 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_5 [ V_86 ] = V_13 ;
F_47 ( V_13 , V_2 ) ;
V_24 = F_36 ( V_2 ) ;
if ( V_24 ) {
F_5 ( V_2 , L_12 ) ;
goto V_87;
}
V_24 = F_1 ( V_2 , V_86 ) ;
if ( V_24 ) {
F_5 ( V_2 , L_13 ) ;
goto V_88;
}
V_24 = F_30 ( V_2 ) ;
if ( V_24 ) {
F_5 ( V_2 , L_14 ) ;
goto V_89;
}
V_24 = F_20 ( V_2 ) ;
if ( V_24 ) {
F_5 ( V_2 , L_15 ) ;
goto V_89;
}
V_24 = F_28 ( V_2 ) ;
if ( V_24 ) {
F_5 ( V_2 , L_16 ) ;
goto V_89;
}
V_24 = F_48 ( & V_2 -> V_90 ) ;
if ( V_24 ) {
F_5 ( V_2 , L_17 ) ;
goto V_89;
}
V_24 = F_49 ( & V_2 -> V_91 ) ;
if ( V_24 ) {
F_5 ( V_2 , L_18 ) ;
goto V_92;
}
V_24 = F_50 ( V_2 , & V_2 -> V_93 ) ;
if ( V_24 ) {
F_5 ( V_2 , L_19 ) ;
goto V_94;
}
V_24 = F_50 ( V_2 , & V_2 -> V_95 ) ;
if ( V_24 ) {
F_5 ( V_2 , L_20 ) ;
goto V_96;
}
return 0 ;
V_96:
F_51 ( & V_2 -> V_93 ) ;
V_94:
F_52 ( & V_2 -> V_91 ) ;
V_92:
F_53 ( & V_2 -> V_90 ) ;
V_89:
F_17 ( V_2 ) ;
V_88:
F_41 ( V_2 ) ;
V_87:
F_54 ( & V_2 -> V_85 ) ;
F_55 ( V_2 ) ;
return V_24 ;
}
static int F_56 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_57 ( V_13 ) ;
F_52 ( & V_2 -> V_91 ) ;
F_53 ( & V_2 -> V_90 ) ;
F_51 ( & V_2 -> V_93 ) ;
F_51 ( & V_2 -> V_95 ) ;
F_17 ( V_2 ) ;
F_41 ( V_2 ) ;
F_54 ( & V_2 -> V_85 ) ;
F_55 ( V_2 ) ;
return 0 ;
}
