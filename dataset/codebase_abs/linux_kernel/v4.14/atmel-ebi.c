static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_2 -> V_5 -> V_6 . V_7 , V_4 -> V_8 ,
& V_4 -> V_9 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_4 ( V_2 -> V_5 -> V_6 . V_7 , V_2 -> V_5 -> V_6 . V_10 ,
V_4 -> V_8 , & V_4 -> V_9 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_13 * V_9 )
{
unsigned int V_14 = F_6 ( V_2 -> V_5 -> V_15 ) ;
unsigned int V_16 = V_17 / V_14 ;
bool V_18 = false ;
unsigned int V_19 ;
int V_20 , V_21 ;
T_1 V_22 ;
V_20 = F_7 ( V_12 , L_1 , & V_22 ) ;
if ( ! V_20 ) {
V_18 = true ;
V_19 = F_8 ( V_22 , V_16 ) ;
if ( V_19 > V_23 ) {
V_20 = - V_24 ;
goto V_25;
}
if ( V_19 < V_26 )
V_19 = V_26 ;
V_9 -> V_27 |= F_9 ( V_19 ) ;
}
for ( V_21 = 0 ; V_21 < F_10 ( V_28 ) ; V_21 ++ ) {
const struct V_29 * V_30 ;
V_30 = & V_28 [ V_21 ] ;
V_20 = F_7 ( V_12 , V_30 -> V_31 , & V_22 ) ;
if ( V_20 ) {
if ( ! V_18 )
continue;
else
break;
}
if ( ! V_18 ) {
V_20 = - V_24 ;
break;
}
V_19 = F_8 ( V_22 , V_16 ) ;
V_20 = V_30 -> V_32 ( V_9 , V_30 -> V_33 , V_19 ) ;
if ( V_20 )
goto V_25;
}
V_25:
if ( V_20 ) {
F_11 ( V_2 -> V_5 -> V_34 ,
L_2 ,
V_12 ) ;
return V_20 ;
}
return V_18 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_13 * V_9 = & V_4 -> V_9 ;
bool V_18 = false ;
const char * V_35 ;
T_1 V_36 ;
int V_20 ;
V_20 = F_7 ( V_12 , L_3 , & V_36 ) ;
if ( ! V_20 ) {
switch ( V_36 ) {
case 8 :
V_9 -> V_27 |= V_37 ;
break;
case 16 :
V_9 -> V_27 |= V_38 ;
break;
case 32 :
V_9 -> V_27 |= V_39 ;
break;
default:
return - V_24 ;
}
V_18 = true ;
}
if ( F_13 ( V_12 , L_4 ) ) {
V_9 -> V_27 |= V_40 ;
V_18 = true ;
}
V_35 = NULL ;
F_14 ( V_12 , L_5 , & V_35 ) ;
if ( V_35 && ! strcmp ( V_35 , L_6 ) ) {
V_9 -> V_27 |= V_41 ;
V_18 = true ;
}
V_35 = NULL ;
F_14 ( V_12 , L_7 , & V_35 ) ;
if ( V_35 && ! strcmp ( V_35 , L_8 ) ) {
V_9 -> V_27 |= V_42 ;
V_18 = true ;
}
V_35 = NULL ;
F_14 ( V_12 , L_9 , & V_35 ) ;
if ( V_35 && ! strcmp ( V_35 , L_10 ) ) {
V_9 -> V_27 |= V_43 ;
V_18 = true ;
}
V_35 = NULL ;
F_14 ( V_12 , L_11 , & V_35 ) ;
if ( V_35 ) {
if ( ! strcmp ( V_35 , L_12 ) )
V_9 -> V_27 |= V_44 ;
else if ( ! strcmp ( V_35 , L_13 ) )
V_9 -> V_27 |= V_45 ;
else if ( strcmp ( V_35 , L_14 ) )
return - V_24 ;
V_18 = true ;
}
V_20 = F_7 ( V_12 , L_15 , & V_36 ) ;
if ( ! V_20 ) {
switch ( V_36 ) {
case 4 :
V_9 -> V_27 |= V_46 ;
break;
case 8 :
V_9 -> V_27 |= V_47 ;
break;
case 16 :
V_9 -> V_27 |= V_48 ;
break;
case 32 :
V_9 -> V_27 |= V_49 ;
break;
default:
return - V_24 ;
}
V_9 -> V_27 |= V_50 ;
V_18 = true ;
}
V_20 = F_5 ( V_2 , V_12 , & V_4 -> V_9 ) ;
if ( V_20 < 0 )
return - V_24 ;
if ( ( V_20 > 0 && ! V_18 ) || ( ! V_20 && V_18 ) ) {
F_11 ( V_2 -> V_5 -> V_34 , L_16 ,
V_12 ) ;
return - V_24 ;
}
return V_18 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_16 ( V_2 -> V_5 -> V_6 . V_7 , V_4 -> V_8 ,
& V_4 -> V_9 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_18 ( V_2 -> V_5 -> V_6 . V_7 , V_2 -> V_5 -> V_6 . V_10 ,
V_4 -> V_8 , & V_4 -> V_9 ) ;
}
static int F_19 ( struct V_51 * V_5 , struct V_11 * V_12 ,
int V_52 )
{
const struct V_53 * V_54 = V_5 -> V_54 ;
struct V_3 V_4 = { } ;
struct V_55 * V_34 = V_5 -> V_34 ;
struct V_1 * V_2 ;
unsigned long V_56 = 0 ;
int V_20 , V_57 = 0 , V_58 , V_21 ;
bool V_59 = false ;
T_1 V_8 ;
V_58 = F_20 ( V_12 , L_17 ,
V_52 * sizeof( T_1 ) ) ;
for ( V_21 = 0 ; V_21 < V_58 ; V_21 ++ ) {
V_20 = F_21 ( V_12 , L_17 , V_21 * V_52 ,
& V_8 ) ;
if ( V_20 )
return V_20 ;
if ( V_8 >= V_60 ||
! ( V_5 -> V_54 -> V_61 & F_22 ( V_8 ) ) ) {
F_11 ( V_34 , L_18 , V_12 ) ;
return - V_24 ;
}
if ( ! F_23 ( V_8 , & V_56 ) )
V_57 ++ ;
}
if ( ! V_57 ) {
F_11 ( V_34 , L_18 , V_12 ) ;
return - V_24 ;
}
V_2 = F_24 ( V_5 -> V_34 ,
sizeof( * V_2 ) + ( V_57 * sizeof( * V_2 -> V_62 ) ) ,
V_63 ) ;
if ( ! V_2 )
return - V_64 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_57 = V_57 ;
V_20 = V_54 -> V_65 ( V_2 , V_12 , & V_4 ) ;
if ( V_20 < 0 )
return V_20 ;
else if ( V_20 )
V_59 = true ;
V_21 = 0 ;
F_25 (cs, &cslines, AT91_MATRIX_EBI_NUM_CS) {
V_2 -> V_62 [ V_21 ] . V_8 = V_8 ;
if ( V_59 ) {
V_4 . V_8 = V_8 ;
V_54 -> V_66 ( V_2 , & V_4 ) ;
}
V_54 -> V_67 ( V_2 , & V_2 -> V_62 [ V_21 ] ) ;
if ( V_5 -> V_54 -> V_68 && V_59 )
F_26 ( V_5 -> V_69 ,
V_5 -> V_54 -> V_68 ,
F_22 ( V_8 ) , 0 ) ;
V_21 ++ ;
}
F_27 ( & V_2 -> V_70 , & V_5 -> V_71 ) ;
return 0 ;
}
static int F_28 ( struct V_51 * V_5 , struct V_11 * V_12 )
{
struct V_55 * V_34 = V_5 -> V_34 ;
struct V_72 * V_73 ;
V_73 = F_24 ( V_34 , sizeof( * V_73 ) , V_63 ) ;
if ( ! V_73 )
return - V_64 ;
V_73 -> V_31 = F_29 ( V_34 , L_19 , V_63 ) ;
if ( ! V_73 -> V_31 )
return - V_64 ;
V_73 -> V_74 = F_29 ( V_34 , L_14 , V_63 ) ;
if ( ! V_73 -> V_74 )
return - V_64 ;
V_73 -> V_75 = sizeof( L_14 ) ;
return F_30 ( V_12 , V_73 ) ;
}
static int F_31 ( struct V_76 * V_77 )
{
struct V_55 * V_34 = & V_77 -> V_34 ;
struct V_11 * V_78 , * V_12 = V_34 -> V_79 , * V_80 ;
const struct V_81 * V_82 ;
struct V_51 * V_5 ;
int V_20 , V_52 ;
struct V_15 * V_15 ;
T_1 V_22 ;
V_82 = F_32 ( V_83 , V_34 ) ;
if ( ! V_82 || ! V_82 -> V_84 )
return - V_24 ;
V_5 = F_24 ( V_34 , sizeof( * V_5 ) , V_63 ) ;
if ( ! V_5 )
return - V_64 ;
F_33 ( V_77 , V_5 ) ;
F_34 ( & V_5 -> V_71 ) ;
V_5 -> V_54 = V_82 -> V_84 ;
V_5 -> V_34 = V_34 ;
V_15 = F_35 ( V_34 , NULL ) ;
if ( F_36 ( V_15 ) )
return F_37 ( V_15 ) ;
V_5 -> V_15 = V_15 ;
V_80 = F_38 ( V_34 -> V_79 , L_20 , 0 ) ;
V_5 -> V_6 . V_7 = F_39 ( V_80 ) ;
if ( F_36 ( V_5 -> V_6 . V_7 ) )
return F_37 ( V_5 -> V_6 . V_7 ) ;
V_5 -> V_6 . V_10 = F_40 ( V_80 ) ;
if ( F_36 ( V_5 -> V_6 . V_10 ) )
return F_37 ( V_5 -> V_6 . V_10 ) ;
V_5 -> V_6 . V_15 = F_41 ( V_80 , 0 ) ;
if ( F_36 ( V_5 -> V_6 . V_15 ) ) {
if ( F_37 ( V_5 -> V_6 . V_15 ) != - V_85 )
return F_37 ( V_5 -> V_6 . V_15 ) ;
V_5 -> V_6 . V_15 = NULL ;
}
V_20 = F_42 ( V_5 -> V_6 . V_15 ) ;
if ( V_20 )
return V_20 ;
if ( V_5 -> V_54 -> V_68 ) {
V_5 -> V_69 =
F_43 ( V_12 , L_21 ) ;
if ( F_36 ( V_5 -> V_69 ) )
return F_37 ( V_5 -> V_69 ) ;
}
V_20 = F_7 ( V_12 , L_22 , & V_22 ) ;
if ( V_20 ) {
F_11 ( V_34 , L_23 ) ;
return V_20 ;
}
V_52 = V_22 ;
V_20 = F_7 ( V_12 , L_24 , & V_22 ) ;
if ( V_20 ) {
F_11 ( V_34 , L_23 ) ;
return V_20 ;
}
V_52 += V_22 ;
F_44 (np, child) {
if ( ! F_45 ( V_78 , L_17 , NULL ) )
continue;
V_20 = F_19 ( V_5 , V_78 , V_52 ) ;
if ( V_20 ) {
F_11 ( V_34 , L_25 ,
V_78 ) ;
V_20 = F_28 ( V_5 , V_78 ) ;
if ( V_20 )
return V_20 ;
}
}
return F_46 ( V_12 , NULL , NULL , V_34 ) ;
}
static T_2 int F_47 ( struct V_55 * V_34 )
{
struct V_51 * V_5 = F_48 ( V_34 ) ;
struct V_1 * V_2 ;
F_49 (ebid, &ebi->devs, node) {
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_57 ; V_21 ++ )
V_2 -> V_5 -> V_54 -> V_66 ( V_2 , & V_2 -> V_62 [ V_21 ] ) ;
}
return 0 ;
}
