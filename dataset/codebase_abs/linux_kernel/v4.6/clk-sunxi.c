static void F_1 ( struct V_1 * V_2 )
{
T_1 div ;
div = V_2 -> V_3 / 6000000 ;
V_2 -> V_3 = 6000000 * div ;
V_2 -> V_4 = 0 ;
if ( V_2 -> V_3 >= 768000000 || V_2 -> V_3 == 42000000 ||
V_2 -> V_3 == 54000000 )
V_2 -> V_5 = 1 ;
else
V_2 -> V_5 = 0 ;
if ( div < 10 )
V_2 -> V_6 = 3 ;
else if ( div < 20 || ( div < 32 && ( div & 1 ) ) )
V_2 -> V_6 = 2 ;
else if ( div < 40 || ( div < 64 && ( div & 2 ) ) )
V_2 -> V_6 = 1 ;
else
V_2 -> V_6 = 0 ;
div <<= V_2 -> V_6 ;
div /= ( V_2 -> V_5 + 1 ) ;
V_2 -> V_7 = div / 4 ;
}
static void F_2 ( struct V_1 * V_2 )
{
T_2 V_8 = V_2 -> V_3 / 1000000 ;
T_2 V_9 = V_2 -> V_10 / 1000000 ;
T_2 V_11 = F_3 ( V_8 , 6 ) ;
T_2 V_12 = F_3 ( V_8 , 16 ) ;
if ( V_11 > V_12 )
V_8 = V_11 ;
else
V_8 = V_12 ;
V_2 -> V_3 = V_8 * 1000000 ;
if ( ! ( V_8 % 32 ) )
V_2 -> V_5 = 3 ;
else if ( ! ( V_8 % 9 ) )
V_2 -> V_5 = 2 ;
else if ( ! ( V_8 % 8 ) )
V_2 -> V_5 = 1 ;
else
V_2 -> V_5 = 0 ;
if ( ( V_8 % 6 ) == 2 || ( V_8 % 6 ) == 4 )
V_2 -> V_4 = 2 ;
else if ( ( V_8 / 6 ) & 1 )
V_2 -> V_4 = 3 ;
else
V_2 -> V_4 = 1 ;
V_2 -> V_7 = V_8 * ( V_2 -> V_4 + 1 ) / ( ( V_2 -> V_5 + 1 ) * V_9 )
- 1 ;
if ( ( V_2 -> V_7 + 1 ) > 31 && ( V_2 -> V_4 + 1 ) > 1 ) {
V_2 -> V_7 = ( V_2 -> V_7 + 1 ) / 2 - 1 ;
V_2 -> V_4 = ( V_2 -> V_4 + 1 ) / 2 - 1 ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 div ;
div = V_2 -> V_3 / 6000000 ;
V_2 -> V_3 = 6000000 * div ;
V_2 -> V_4 = 0 ;
if ( V_2 -> V_3 >= 768000000 || V_2 -> V_3 == 42000000 ||
V_2 -> V_3 == 54000000 )
V_2 -> V_5 = 1 ;
else
V_2 -> V_5 = 0 ;
if ( div < 20 || ( div < 32 && ( div & 1 ) ) )
V_2 -> V_6 = 2 ;
else if ( div < 40 || ( div < 64 && ( div & 2 ) ) )
V_2 -> V_6 = 1 ;
else
V_2 -> V_6 = 0 ;
div <<= V_2 -> V_6 ;
div /= ( V_2 -> V_5 + 1 ) ;
V_2 -> V_7 = div / 4 - 1 ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 div ;
div = V_2 -> V_3 / V_2 -> V_10 ;
V_2 -> V_3 = V_2 -> V_10 * div ;
if ( div < 31 )
V_2 -> V_5 = 0 ;
else if ( div / 2 < 31 )
V_2 -> V_5 = 1 ;
else if ( div / 3 < 31 )
V_2 -> V_5 = 2 ;
else
V_2 -> V_5 = 3 ;
V_2 -> V_7 = F_6 ( div , ( V_2 -> V_5 + 1 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 div ;
div = V_2 -> V_3 / V_2 -> V_10 ;
V_2 -> V_3 = V_2 -> V_10 * div ;
V_2 -> V_5 = div / 32 ;
if ( V_2 -> V_5 > 3 )
V_2 -> V_5 = 3 ;
V_2 -> V_7 = F_6 ( div , ( V_2 -> V_5 + 1 ) ) - 1 ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_2 div ;
if ( V_2 -> V_10 < V_2 -> V_3 )
V_2 -> V_3 = V_2 -> V_10 ;
if ( V_2 -> V_3 < 8000 )
V_2 -> V_3 = 8000 ;
if ( V_2 -> V_3 > 300000000 )
V_2 -> V_3 = 300000000 ;
div = F_9 ( F_6 ( V_2 -> V_10 , V_2 -> V_3 ) ) ;
if ( div > 3 )
div = 3 ;
V_2 -> V_3 = V_2 -> V_10 >> div ;
V_2 -> V_6 = div ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 div , V_13 , V_14 = 1 ;
if ( V_2 -> V_10 && V_2 -> V_3 > V_2 -> V_10 )
V_2 -> V_3 = V_2 -> V_10 ;
div = F_6 ( V_2 -> V_10 , V_2 -> V_3 ) ;
if ( V_2 -> V_15 == V_16 ) {
if ( div < 4 )
V_13 = 0 ;
else if ( div / 2 < 4 )
V_13 = 1 ;
else if ( div / 4 < 4 )
V_13 = 2 ;
else
V_13 = 3 ;
V_14 = F_6 ( div , 1 << V_13 ) ;
} else {
V_13 = F_11 ( div ) ;
V_13 = V_13 > 3 ? 3 : V_13 ;
}
V_2 -> V_3 = ( V_2 -> V_10 / V_14 ) >> V_13 ;
V_2 -> V_6 = V_13 ;
V_2 -> V_4 = V_14 - 1 ;
}
static void F_12 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_10 ;
if ( V_2 -> V_15 == V_16 )
V_2 -> V_3 /= V_2 -> V_4 + 1 ;
V_2 -> V_3 >>= V_2 -> V_6 ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_14 , V_13 ;
int div ;
if ( V_2 -> V_10 < V_2 -> V_3 )
V_2 -> V_3 = V_2 -> V_10 ;
div = F_6 ( V_2 -> V_10 , V_2 -> V_3 ) ;
if ( div > 32 )
return;
if ( div <= 4 )
V_13 = 0 ;
else if ( div <= 8 )
V_13 = 1 ;
else if ( div <= 16 )
V_13 = 2 ;
else
V_13 = 3 ;
V_14 = ( V_2 -> V_10 >> V_13 ) - 1 ;
V_2 -> V_3 = ( V_2 -> V_10 >> V_13 ) / ( V_14 + 1 ) ;
V_2 -> V_4 = V_14 ;
V_2 -> V_6 = V_13 ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 div , V_14 , V_13 ;
if ( V_2 -> V_3 > V_2 -> V_10 )
V_2 -> V_3 = V_2 -> V_10 ;
div = F_6 ( V_2 -> V_10 , V_2 -> V_3 ) ;
if ( div < 32 )
V_13 = 0 ;
else if ( div / 2 < 32 )
V_13 = 1 ;
else if ( div / 4 < 32 )
V_13 = 2 ;
else
V_13 = 3 ;
V_14 = F_6 ( div , 1 << V_13 ) ;
V_2 -> V_3 = ( V_2 -> V_10 >> V_13 ) / V_14 ;
V_2 -> V_4 = V_14 - 1 ;
V_2 -> V_6 = V_13 ;
}
static struct V_17 * T_3 F_15 ( struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
void T_4 * V_22 ;
V_22 = F_16 ( V_19 , 0 ) ;
if ( ! V_22 ) {
F_17 ( L_1 ,
V_19 -> V_23 ) ;
return NULL ;
}
return F_18 ( V_19 , V_21 , & V_24 , V_22 ) ;
}
static void T_3 F_19 ( struct V_18 * V_19 )
{
F_15 ( V_19 , & V_25 ) ;
}
static void T_3 F_20 ( struct V_18 * V_19 )
{
F_15 ( V_19 , & V_26 ) ;
}
static void T_3 F_21 ( struct V_18 * V_19 )
{
F_15 ( V_19 , & V_27 ) ;
}
static void T_3 F_22 ( struct V_18 * V_19 )
{
F_15 ( V_19 , & V_28 ) ;
}
static void T_3 F_23 ( struct V_18 * V_19 )
{
F_15 ( V_19 , & V_29 ) ;
}
static void T_3 F_24 ( struct V_18 * V_19 )
{
F_15 ( V_19 , & V_30 ) ;
}
static void T_3 F_25 ( struct V_18 * V_19 )
{
F_15 ( V_19 , & V_31 ) ;
}
static void T_3 F_26 ( struct V_18 * V_19 )
{
F_15 ( V_19 , & V_32 ) ;
}
static struct V_17 * T_3 F_27 ( struct V_18 * V_19 ,
const struct V_33 * V_21 )
{
struct V_17 * V_17 ;
const char * V_34 = V_19 -> V_23 ;
const char * V_35 [ V_36 ] ;
void T_4 * V_22 ;
int V_37 ;
V_22 = F_16 ( V_19 , 0 ) ;
if ( ! V_22 ) {
F_17 ( L_2 ,
F_28 ( V_19 ) ) ;
return NULL ;
}
V_37 = F_29 ( V_19 , V_35 , V_36 ) ;
if ( F_30 ( V_19 , L_3 , & V_34 ) ) {
F_17 ( L_4 ,
V_38 , F_28 ( V_19 ) ) ;
goto V_39;
}
V_17 = F_31 ( NULL , V_34 , V_35 , V_37 ,
V_40 , V_22 ,
V_21 -> V_41 , V_42 ,
0 , & V_24 ) ;
if ( F_32 ( V_17 ) ) {
F_17 ( L_5 , V_38 ,
V_34 , F_33 ( V_17 ) ) ;
goto V_39;
}
if ( F_34 ( V_19 , V_43 , V_17 ) ) {
F_17 ( L_6 ,
V_38 , V_34 ) ;
F_35 ( V_17 ) ;
goto V_39;
}
return V_17 ;
V_39:
F_36 ( V_22 ) ;
return NULL ;
}
static void T_3 F_37 ( struct V_18 * V_19 )
{
struct V_17 * V_17 ;
V_17 = F_27 ( V_19 , & V_44 ) ;
if ( ! V_17 )
return;
F_38 ( V_17 ) ;
F_39 ( V_17 ) ;
}
static void T_3 F_40 ( struct V_18 * V_19 )
{
F_27 ( V_19 , & V_45 ) ;
}
static void T_3 F_41 ( struct V_18 * V_19 )
{
F_27 ( V_19 , & V_46 ) ;
}
static void T_3 F_42 ( struct V_18 * V_19 ,
const struct V_47 * V_21 )
{
struct V_17 * V_17 ;
const char * V_34 = V_19 -> V_23 ;
const char * V_48 ;
void T_4 * V_22 ;
V_22 = F_16 ( V_19 , 0 ) ;
if ( ! V_22 ) {
F_17 ( L_2 ,
F_28 ( V_19 ) ) ;
return;
}
V_48 = F_43 ( V_19 , 0 ) ;
if ( F_30 ( V_19 , L_3 , & V_34 ) ) {
F_17 ( L_4 ,
V_38 , F_28 ( V_19 ) ) ;
goto V_39;
}
V_17 = F_44 ( NULL , V_34 , V_48 , 0 ,
V_22 , V_21 -> V_41 , V_21 -> V_49 ,
V_21 -> pow ? V_50 : 0 ,
V_21 -> V_51 , & V_24 ) ;
if ( F_32 ( V_17 ) ) {
F_17 ( L_7 ,
V_38 , V_34 , F_33 ( V_17 ) ) ;
goto V_39;
}
if ( F_34 ( V_19 , V_43 , V_17 ) ) {
F_17 ( L_6 ,
V_38 , V_34 ) ;
goto V_52;
}
if ( F_45 ( V_17 , V_34 , NULL ) ) {
F_46 ( V_19 ) ;
goto V_52;
}
return;
V_52:
F_35 ( V_17 ) ;
V_39:
F_36 ( V_22 ) ;
}
static void T_3 F_47 ( struct V_18 * V_19 )
{
F_42 ( V_19 , & V_53 ) ;
}
static void T_3 F_48 ( struct V_18 * V_19 )
{
F_42 ( V_19 , & V_54 ) ;
}
static void T_3 F_49 ( struct V_18 * V_19 )
{
F_42 ( V_19 , & V_55 ) ;
}
static void T_3 F_50 ( struct V_18 * V_19 )
{
F_42 ( V_19 , & V_56 ) ;
}
static struct V_17 * * T_3 F_51 ( struct V_18 * V_19 ,
const struct V_57 * V_21 )
{
struct V_58 * V_59 ;
const char * V_60 ;
const char * V_34 ;
struct V_17 * * V_61 , * V_62 ;
struct V_63 * V_64 , * V_65 ;
const struct V_66 * V_67 ;
struct V_68 * V_69 = NULL ;
struct V_70 * V_71 ;
struct V_72 * V_73 ;
void T_4 * V_22 ;
int V_74 = V_75 , V_37 = 0 ;
int V_76 , V_77 ;
if ( V_21 -> V_74 )
V_74 = V_21 -> V_74 ;
V_62 = F_15 ( V_19 , V_21 -> V_78 ) ;
if ( ! V_62 )
return NULL ;
V_60 = F_52 ( V_62 ) ;
V_22 = F_16 ( V_19 , 0 ) ;
if ( ! V_22 ) {
F_17 ( L_8 ,
F_28 ( V_19 ) ) ;
return NULL ;
}
V_59 = F_53 ( sizeof( struct V_58 ) , V_79 ) ;
if ( ! V_59 )
goto V_39;
V_61 = F_54 ( V_74 , sizeof( * V_61 ) , V_79 ) ;
if ( ! V_61 )
goto V_80;
V_59 -> V_61 = V_61 ;
V_77 = ! strcmp ( L_9 , V_60 ) ? 0 : V_40 ;
for ( V_37 = 0 ; V_37 < V_74 ; V_37 ++ ) {
if ( F_55 ( V_19 , L_3 ,
V_37 , & V_34 ) != 0 )
break;
if ( V_21 -> div [ V_37 ] . V_81 ) {
V_59 -> V_61 [ V_37 ] = V_62 ;
continue;
}
V_64 = NULL ;
V_65 = NULL ;
V_67 = NULL ;
if ( V_21 -> div [ V_37 ] . V_69 ) {
V_69 = F_56 ( sizeof( * V_69 ) , V_79 ) ;
if ( ! V_69 )
goto V_82;
V_69 -> V_22 = V_22 ;
V_69 -> V_83 = V_21 -> div [ V_37 ] . V_69 ;
V_69 -> V_84 = & V_24 ;
V_64 = & V_69 -> V_85 ;
}
if ( V_21 -> div [ V_37 ] . V_86 ) {
V_71 = F_56 ( sizeof( * V_71 ) , V_79 ) ;
if ( ! V_71 )
goto V_87;
V_71 -> V_88 = 1 ;
V_71 -> div = V_21 -> div [ V_37 ] . V_86 ;
V_65 = & V_71 -> V_85 ;
V_67 = & V_89 ;
} else {
V_73 = F_56 ( sizeof( * V_73 ) , V_79 ) ;
if ( ! V_73 )
goto V_87;
V_76 = V_21 -> div [ V_37 ] . pow ? V_50 : 0 ;
V_73 -> V_22 = V_22 ;
V_73 -> V_41 = V_21 -> div [ V_37 ] . V_41 ;
V_73 -> V_49 = V_90 ;
V_73 -> V_76 = V_76 ;
V_73 -> V_84 = & V_24 ;
V_73 -> V_51 = V_21 -> div [ V_37 ] . V_51 ;
V_65 = & V_73 -> V_85 ;
V_67 = & V_91 ;
}
V_61 [ V_37 ] = F_57 ( NULL , V_34 , & V_60 , 1 ,
NULL , NULL ,
V_65 , V_67 ,
V_64 , & V_92 ,
V_77 ) ;
F_58 ( F_32 ( V_59 -> V_61 [ V_37 ] ) ) ;
}
V_59 -> V_93 = V_37 ;
if ( F_34 ( V_19 , V_94 , V_59 ) ) {
F_17 ( L_6 ,
V_38 , V_34 ) ;
goto V_87;
}
return V_61 ;
V_87:
F_59 ( V_69 ) ;
V_82:
F_59 ( V_61 ) ;
V_80:
F_59 ( V_59 ) ;
V_39:
F_36 ( V_22 ) ;
return NULL ;
}
static void T_3 F_60 ( struct V_18 * V_19 )
{
struct V_17 * * V_61 ;
V_61 = F_51 ( V_19 , & V_95 ) ;
if ( ! V_61 )
return;
F_38 ( V_61 [ 0 ] ) ;
F_39 ( V_61 [ 0 ] ) ;
}
static void T_3 F_61 ( struct V_18 * V_19 )
{
F_51 ( V_19 , & V_96 ) ;
}
static void T_3 F_62 ( struct V_18 * V_19 )
{
F_51 ( V_19 , & V_97 ) ;
}
