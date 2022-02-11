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
struct V_18 * V_4 )
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
struct V_42 * V_43 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
int V_44 ;
if ( V_43 -> V_45 != 0 || V_43 -> type != V_23 )
return - V_22 ;
V_43 -> V_46 = F_7 ( V_43 -> V_46 , V_25 , V_27 ) ;
V_44 = V_6 -> V_8 -> V_20 -> V_47 ( V_6 , V_43 -> V_46 ) ;
if ( V_44 == 0 )
V_6 -> V_48 = V_43 -> V_46 ;
return V_44 ;
}
static int F_8 ( struct V_1 * V_1 , void * V_2 ,
struct V_42 * V_43 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
if ( V_43 -> V_45 != 0 )
return - V_22 ;
V_43 -> type = V_23 ;
V_43 -> V_46 = V_6 -> V_48 ;
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
static int F_14 ( struct V_59 * V_60 ,
struct V_61 * V_62 )
{
if ( V_62 -> type == V_63 )
return F_15 ( V_60 , V_62 , 0 ) ;
return - V_22 ;
}
int F_16 ( struct V_64 * V_65 , unsigned int V_66 )
{
struct V_67 * V_8 = V_65 -> V_68 ;
return V_8 -> V_69 || V_8 -> V_70 [ V_66 ] >= 0 ;
}
static bool F_17 ( const struct V_67 * V_8 , int V_58 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_8 -> V_72 ; V_71 ++ )
if ( V_8 -> V_73 [ V_71 ] == V_58 )
return true ;
return false ;
}
int F_18 ( struct V_64 * V_65 , unsigned int V_66 )
{
struct V_67 * V_8 = V_65 -> V_68 ;
const struct V_19 * V_20 = V_8 -> V_20 ;
struct V_74 * V_12 ;
struct V_5 * V_6 ;
int V_44 ;
V_6 = V_8 -> V_20 -> V_75 () ;
if ( V_6 == NULL )
return - V_76 ;
F_19 ( V_65 , V_6 ) ;
V_6 -> V_8 = V_8 ;
V_6 -> V_58 = V_8 -> V_70 [ V_66 ] ;
V_12 = & V_6 -> V_12 ;
F_3 ( V_12 -> V_9 , F_20 ( V_65 ) , sizeof( V_12 -> V_9 ) ) ;
if ( V_8 -> V_69 && V_20 -> V_69 ) {
int V_71 ;
for ( V_71 = 0 ; V_71 < V_8 -> V_72 ; ++ V_71 ) {
int V_58 = V_8 -> V_73 [ V_71 ] ;
if ( F_21 ( V_58 , V_8 -> V_77 , V_12 -> V_9 ) ) {
bool V_78 = V_20 -> V_69 ( V_6 , V_58 ) ;
F_22 ( V_58 , V_8 -> V_77 ) ;
if ( V_78 ) {
V_6 -> V_58 = V_58 ;
break;
}
}
}
}
if ( ! F_17 ( V_8 , V_6 -> V_58 ) ) {
int V_71 ;
if ( V_6 -> V_58 < 0 )
return - V_79 ;
F_23 ( V_12 , L_4 ,
V_8 -> V_73 [ 0 ] ) ;
for ( V_71 = 1 ; V_71 < V_8 -> V_72 ; V_71 ++ )
F_24 ( V_80 L_5 , V_8 -> V_73 [ V_71 ] ) ;
F_24 ( V_80 L_6 ) ;
F_25 ( V_6 ) ;
return - V_22 ;
}
if ( ! F_21 ( V_6 -> V_58 , V_8 -> V_77 , V_12 -> V_9 ) ) {
F_23 ( V_12 , L_7 , V_6 -> V_58 ) ;
F_25 ( V_6 ) ;
return - V_81 ;
}
V_44 = F_26 ( V_65 , V_12 ) ;
if ( V_44 < 0 ) {
F_23 ( V_12 , L_8 ) ;
goto V_82;
}
F_27 ( & V_6 -> V_52 , 1 ) ;
V_6 -> V_83 = F_28 ( & V_6 -> V_52 , & V_84 ,
V_54 , 0 , 1 , 1 , 1 ) ;
if ( V_8 -> V_85 )
V_6 -> V_57 = F_28 ( & V_6 -> V_52 , & V_84 ,
V_86 , 0 , V_8 -> V_85 , 1 ,
V_8 -> V_85 ) ;
V_12 -> V_87 = & V_6 -> V_52 ;
if ( V_6 -> V_52 . error ) {
V_44 = V_6 -> V_52 . error ;
F_23 ( V_12 , L_9 ) ;
goto V_88;
}
if ( V_8 -> V_85 )
F_29 ( 2 , & V_6 -> V_83 ) ;
V_12 -> V_87 = & V_6 -> V_52 ;
F_30 ( & V_6 -> V_89 ) ;
V_6 -> V_90 . V_89 = & V_6 -> V_89 ;
F_3 ( V_6 -> V_90 . V_9 , V_12 -> V_9 , sizeof( V_6 -> V_90 . V_9 ) ) ;
V_6 -> V_90 . V_12 = V_12 ;
V_6 -> V_90 . V_91 = & V_92 ;
V_6 -> V_90 . V_93 = & V_94 ;
V_6 -> V_90 . V_95 = V_96 ;
F_31 ( V_97 , & V_6 -> V_90 . V_98 ) ;
F_32 ( & V_6 -> V_90 , V_6 ) ;
V_6 -> V_48 = V_25 ;
V_6 -> V_37 = V_8 -> V_30 ;
if ( V_20 -> V_99 )
V_44 = V_20 -> V_99 ( V_6 ) ;
if ( ! V_44 )
V_44 = F_33 ( & V_6 -> V_52 ) ;
if ( ! V_44 )
V_44 = V_20 -> V_47 ( V_6 , V_6 -> V_48 ) ;
if ( ! V_44 && V_20 -> V_41 )
V_44 = V_20 -> V_41 ( V_6 , V_6 -> V_37 ) ;
if ( V_44 < 0 ) {
F_23 ( V_12 , L_10 ) ;
goto V_100;
}
V_44 = F_34 ( & V_6 -> V_90 , V_101 ,
V_8 -> V_102 [ V_66 ] ) ;
if ( V_44 < 0 ) {
F_23 ( V_12 , L_11 ) ;
goto V_100;
}
F_12 ( V_12 , L_12 ,
V_8 -> V_10 , V_6 -> V_58 ) ;
return 0 ;
V_100:
F_35 ( & V_6 -> V_52 ) ;
V_88:
F_36 ( & V_6 -> V_12 ) ;
V_82:
F_22 ( V_6 -> V_58 , V_8 -> V_77 ) ;
F_25 ( V_6 ) ;
return V_44 ;
}
int F_37 ( struct V_64 * V_65 , unsigned int V_66 )
{
struct V_5 * V_6 = F_38 ( V_65 ) ;
const struct V_19 * V_20 = V_6 -> V_8 -> V_20 ;
V_20 -> V_55 ( V_6 , true , V_6 -> V_57 ? V_6 -> V_57 -> V_103 . V_56 : 0 ) ;
F_39 ( & V_6 -> V_90 ) ;
F_35 ( & V_6 -> V_52 ) ;
F_36 ( & V_6 -> V_12 ) ;
F_22 ( V_6 -> V_58 , V_6 -> V_8 -> V_77 ) ;
F_12 ( & V_6 -> V_12 , L_13 , V_6 -> V_8 -> V_10 ) ;
F_25 ( V_6 ) ;
return 0 ;
}
