static int F_1 ( struct V_1 * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
F_3 ( V_4 -> V_7 , V_6 -> V_8 -> V_7 . V_7 . V_9 , sizeof( V_4 -> V_7 ) ) ;
F_3 ( V_4 -> V_10 , V_6 -> V_8 -> V_10 , sizeof( V_4 -> V_10 ) ) ;
snprintf ( V_4 -> V_11 , sizeof( V_4 -> V_11 ) , L_1 , V_6 -> V_12 . V_9 ) ;
V_4 -> V_13 = V_14 | V_15 ;
V_4 -> V_16 = V_4 -> V_13 | V_17 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , void * V_2 ,
struct V_18 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
const struct V_19 * V_20 = V_6 -> V_8 -> V_20 ;
if ( V_4 -> V_21 > 0 )
return - V_22 ;
F_3 ( V_4 -> V_9 , L_2 , sizeof( V_4 -> V_9 ) ) ;
V_4 -> type = V_23 ;
V_4 -> V_24 = V_25 ;
V_4 -> V_26 = V_27 ;
V_4 -> V_28 = V_29 ;
if ( V_6 -> V_8 -> V_30 )
V_4 -> V_28 |= V_31 ;
if ( V_20 -> V_32 )
V_4 -> V_33 = V_20 -> V_32 ( V_6 ) ;
else
V_4 -> V_33 = V_34 | V_35 ;
V_4 -> V_36 = V_6 -> V_37 ? V_38 : V_39 ;
if ( V_20 -> V_40 )
V_4 -> signal = V_20 -> V_40 ( V_6 ) ;
else
V_4 -> signal = ( V_4 -> V_33 & V_35 ) ?
0xffff : 0 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , void * V_2 ,
const struct V_18 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
const struct V_19 * V_20 = V_6 -> V_8 -> V_20 ;
if ( V_4 -> V_21 )
return - V_22 ;
if ( V_20 -> V_41 ) {
V_6 -> V_37 = ( V_4 -> V_36 == V_38 ) ;
return V_20 -> V_41 ( V_6 , V_6 -> V_37 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , void * V_2 ,
const struct V_42 * V_43 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
T_1 V_44 = V_43 -> V_45 ;
int V_46 ;
if ( V_43 -> V_47 != 0 || V_43 -> type != V_23 )
return - V_22 ;
V_44 = F_7 ( V_44 , V_25 , V_27 ) ;
V_46 = V_6 -> V_8 -> V_20 -> V_48 ( V_6 , V_44 ) ;
if ( V_46 == 0 )
V_6 -> V_44 = V_44 ;
return V_46 ;
}
static int F_8 ( struct V_1 * V_1 , void * V_2 ,
struct V_42 * V_43 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
if ( V_43 -> V_47 != 0 )
return - V_22 ;
V_43 -> type = V_23 ;
V_43 -> V_45 = V_6 -> V_44 ;
return 0 ;
}
static int F_9 ( struct V_49 * V_50 )
{
struct V_5 * V_6 =
F_10 ( V_50 -> V_51 , struct V_5 , V_52 ) ;
switch ( V_50 -> V_53 ) {
case V_54 :
return V_6 -> V_8 -> V_20 -> V_55 ( V_6 , V_50 -> V_56 ,
V_6 -> V_57 ? V_6 -> V_57 -> V_56 : 0 ) ;
}
return - V_22 ;
}
static int F_11 ( struct V_1 * V_1 , void * V_2 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
F_12 ( & V_6 -> V_12 , L_3 , V_6 -> V_58 ) ;
F_13 ( & V_6 -> V_52 , V_6 -> V_12 . V_9 ) ;
return 0 ;
}
int F_14 ( struct V_59 * V_60 , unsigned int V_61 )
{
struct V_62 * V_8 = V_60 -> V_63 ;
return V_8 -> V_64 || V_8 -> V_65 [ V_61 ] >= 0 ;
}
static bool F_15 ( const struct V_62 * V_8 , int V_58 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_8 -> V_67 ; V_66 ++ )
if ( V_8 -> V_68 [ V_66 ] == V_58 )
return true ;
return false ;
}
static struct V_5 * F_16 ( struct V_62 * V_8 ,
struct V_59 * V_60 )
{
struct V_69 * V_12 ;
struct V_5 * V_6 = V_8 -> V_20 -> V_70 () ;
if ( ! V_6 )
return NULL ;
F_17 ( V_60 , V_6 ) ;
V_6 -> V_8 = V_8 ;
V_12 = & V_6 -> V_12 ;
F_3 ( V_12 -> V_9 , F_18 ( V_60 ) , sizeof( V_12 -> V_9 ) ) ;
return V_6 ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_59 * V_60 ,
int V_71 , unsigned V_72 )
{
const struct V_62 * V_8 = V_6 -> V_8 ;
const struct V_19 * V_20 = V_8 -> V_20 ;
struct V_69 * V_12 = & V_6 -> V_12 ;
int V_46 ;
if ( ! F_20 ( V_6 -> V_58 , V_72 , V_12 -> V_9 ) ) {
F_21 ( V_12 , L_4 , V_6 -> V_58 ) ;
F_22 ( V_6 ) ;
return - V_73 ;
}
V_46 = F_23 ( V_60 , V_12 ) ;
if ( V_46 < 0 ) {
F_21 ( V_12 , L_5 ) ;
goto V_74;
}
F_24 ( & V_6 -> V_52 , 1 ) ;
V_6 -> V_75 = F_25 ( & V_6 -> V_52 , & V_76 ,
V_54 , 0 , 1 , 1 , 1 ) ;
if ( V_8 -> V_77 )
V_6 -> V_57 = F_25 ( & V_6 -> V_52 , & V_76 ,
V_78 , 0 , V_8 -> V_77 , 1 ,
V_8 -> V_77 ) ;
V_12 -> V_79 = & V_6 -> V_52 ;
if ( V_6 -> V_52 . error ) {
V_46 = V_6 -> V_52 . error ;
F_21 ( V_12 , L_6 ) ;
goto V_80;
}
if ( V_8 -> V_77 )
F_26 ( 2 , & V_6 -> V_75 ) ;
V_12 -> V_79 = & V_6 -> V_52 ;
F_27 ( & V_6 -> V_81 ) ;
V_6 -> V_82 . V_81 = & V_6 -> V_81 ;
F_3 ( V_6 -> V_82 . V_9 , V_12 -> V_9 , sizeof( V_6 -> V_82 . V_9 ) ) ;
V_6 -> V_82 . V_12 = V_12 ;
V_6 -> V_82 . V_83 = & V_84 ;
V_6 -> V_82 . V_85 = & V_86 ;
V_6 -> V_82 . V_87 = V_88 ;
F_28 ( & V_6 -> V_82 , V_6 ) ;
V_6 -> V_44 = V_25 ;
V_6 -> V_37 = V_8 -> V_30 ;
if ( V_20 -> V_89 )
V_46 = V_20 -> V_89 ( V_6 ) ;
if ( ! V_46 )
V_46 = F_29 ( & V_6 -> V_52 ) ;
if ( ! V_46 )
V_46 = V_20 -> V_48 ( V_6 , V_6 -> V_44 ) ;
if ( ! V_46 && V_20 -> V_41 )
V_46 = V_20 -> V_41 ( V_6 , V_6 -> V_37 ) ;
if ( V_46 < 0 ) {
F_21 ( V_12 , L_7 ) ;
goto V_80;
}
V_46 = F_30 ( & V_6 -> V_82 , V_90 , V_71 ) ;
if ( V_46 < 0 ) {
F_21 ( V_12 , L_8 ) ;
goto V_80;
}
F_12 ( V_12 , L_9 ,
V_8 -> V_10 , V_6 -> V_58 ) ;
return 0 ;
V_80:
F_31 ( & V_6 -> V_52 ) ;
V_74:
F_32 ( V_6 -> V_58 , V_72 ) ;
F_22 ( V_6 ) ;
return V_46 ;
}
static int F_33 ( struct V_5 * V_6 ,
unsigned V_72 )
{
const struct V_19 * V_20 = V_6 -> V_8 -> V_20 ;
V_20 -> V_55 ( V_6 , true , V_6 -> V_57 ? V_6 -> V_57 -> V_91 . V_56 : 0 ) ;
F_34 ( & V_6 -> V_82 ) ;
F_31 ( & V_6 -> V_52 ) ;
F_35 ( & V_6 -> V_12 ) ;
F_32 ( V_6 -> V_58 , V_72 ) ;
F_12 ( & V_6 -> V_12 , L_10 , V_6 -> V_8 -> V_10 ) ;
F_22 ( V_6 ) ;
return 0 ;
}
int F_36 ( struct V_59 * V_60 , unsigned int V_61 )
{
struct V_62 * V_8 = V_60 -> V_63 ;
const struct V_19 * V_20 = V_8 -> V_20 ;
struct V_69 * V_12 ;
struct V_5 * V_6 ;
V_6 = F_16 ( V_8 , V_60 ) ;
if ( ! V_6 )
return - V_92 ;
V_6 -> V_58 = V_8 -> V_65 [ V_61 ] ;
V_12 = & V_6 -> V_12 ;
if ( V_8 -> V_64 && V_20 -> V_64 ) {
int V_66 ;
for ( V_66 = 0 ; V_66 < V_8 -> V_67 ; ++ V_66 ) {
int V_58 = V_8 -> V_68 [ V_66 ] ;
if ( F_20 ( V_58 , V_8 -> V_72 , V_12 -> V_9 ) ) {
bool V_93 = V_20 -> V_64 ( V_6 , V_58 ) ;
F_32 ( V_58 , V_8 -> V_72 ) ;
if ( V_93 ) {
V_6 -> V_58 = V_58 ;
break;
}
}
}
}
if ( ! F_15 ( V_8 , V_6 -> V_58 ) ) {
int V_66 ;
if ( V_6 -> V_58 < 0 )
return - V_94 ;
F_21 ( V_12 , L_11 ,
V_8 -> V_68 [ 0 ] ) ;
for ( V_66 = 1 ; V_66 < V_8 -> V_67 ; V_66 ++ )
F_37 ( V_95 L_12 , V_8 -> V_68 [ V_66 ] ) ;
F_37 ( V_95 L_13 ) ;
F_22 ( V_6 ) ;
return - V_22 ;
}
return F_19 ( V_6 , V_60 , V_8 -> V_96 [ V_61 ] ,
V_8 -> V_72 ) ;
}
int F_38 ( struct V_59 * V_60 , unsigned int V_61 )
{
struct V_5 * V_6 = F_39 ( V_60 ) ;
return F_33 ( V_6 , V_6 -> V_8 -> V_72 ) ;
}
int F_40 ( struct V_97 * V_61 , const struct V_98 * V_99 )
{
struct V_100 * V_101 = F_41 ( V_61 -> V_61 . V_7 ) ;
struct V_62 * V_8 = F_10 ( V_101 ,
struct V_62 , V_100 ) ;
struct V_5 * V_6 ;
if ( ! F_42 ( V_61 , 0 ) )
return - V_94 ;
V_6 = F_16 ( V_8 , & V_61 -> V_61 ) ;
if ( ! V_6 )
return - V_92 ;
V_6 -> V_58 = F_43 ( V_61 , 0 ) ;
return F_19 ( V_6 , & V_61 -> V_61 , V_8 -> V_96 [ 0 ] ,
F_44 ( V_61 , 0 ) ) ;
}
void F_45 ( struct V_97 * V_61 )
{
struct V_5 * V_6 = F_39 ( & V_61 -> V_61 ) ;
F_33 ( V_6 , F_44 ( V_61 , 0 ) ) ;
}
