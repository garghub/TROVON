static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_2 -> V_5 -> V_6 . V_7 , V_4 -> V_8 ,
& V_4 -> V_9 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_4 ( V_2 -> V_5 -> V_6 . V_7 , V_4 -> V_8 ,
& V_4 -> V_9 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_12 * V_9 )
{
unsigned int V_13 = F_6 ( V_2 -> V_5 -> V_14 ) ;
unsigned int V_15 = V_16 / V_13 ;
bool V_17 = false ;
unsigned int V_18 ;
int V_19 , V_20 ;
T_1 V_21 ;
V_19 = F_7 ( V_11 , L_1 , & V_21 ) ;
if ( ! V_19 ) {
V_17 = true ;
V_18 = F_8 ( V_21 , V_15 ) ;
if ( V_18 > V_22 ) {
V_19 = - V_23 ;
goto V_24;
}
if ( V_18 < V_25 )
V_18 = V_25 ;
V_9 -> V_26 |= F_9 ( V_18 ) ;
}
for ( V_20 = 0 ; V_20 < F_10 ( V_27 ) ; V_20 ++ ) {
const struct V_28 * V_29 ;
V_29 = & V_27 [ V_20 ] ;
V_19 = F_7 ( V_11 , V_29 -> V_30 , & V_21 ) ;
if ( V_19 ) {
if ( ! V_17 )
continue;
else
break;
}
if ( ! V_17 ) {
V_19 = - V_23 ;
break;
}
V_18 = F_8 ( V_21 , V_15 ) ;
V_19 = V_29 -> V_31 ( V_9 , V_29 -> V_32 , V_18 ) ;
if ( V_19 )
goto V_24;
}
V_24:
if ( V_19 ) {
F_11 ( V_2 -> V_5 -> V_33 ,
L_2 ,
V_11 -> V_34 ) ;
return V_19 ;
}
return V_17 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_3 * V_4 )
{
struct V_12 * V_9 = & V_4 -> V_9 ;
bool V_17 = false ;
const char * V_35 ;
T_1 V_36 ;
int V_19 ;
V_19 = F_7 ( V_11 , L_3 , & V_36 ) ;
if ( ! V_19 ) {
switch ( V_36 ) {
case 8 :
V_9 -> V_26 |= V_37 ;
break;
case 16 :
V_9 -> V_26 |= V_38 ;
break;
case 32 :
V_9 -> V_26 |= V_39 ;
break;
default:
return - V_23 ;
}
V_17 = true ;
}
if ( F_13 ( V_11 , L_4 ) ) {
V_9 -> V_26 |= V_40 ;
V_17 = true ;
}
V_35 = NULL ;
F_14 ( V_11 , L_5 , & V_35 ) ;
if ( V_35 && ! strcmp ( V_35 , L_6 ) ) {
V_9 -> V_26 |= V_41 ;
V_17 = true ;
}
V_35 = NULL ;
F_14 ( V_11 , L_7 , & V_35 ) ;
if ( V_35 && ! strcmp ( V_35 , L_8 ) ) {
V_9 -> V_26 |= V_42 ;
V_17 = true ;
}
V_35 = NULL ;
F_14 ( V_11 , L_9 , & V_35 ) ;
if ( V_35 && ! strcmp ( V_35 , L_10 ) ) {
V_9 -> V_26 |= V_43 ;
V_17 = true ;
}
V_35 = NULL ;
F_14 ( V_11 , L_11 , & V_35 ) ;
if ( V_35 ) {
if ( ! strcmp ( V_35 , L_12 ) )
V_9 -> V_26 |= V_44 ;
else if ( ! strcmp ( V_35 , L_13 ) )
V_9 -> V_26 |= V_45 ;
else if ( strcmp ( V_35 , L_14 ) )
return - V_23 ;
V_17 = true ;
}
V_19 = F_7 ( V_11 , L_15 , & V_36 ) ;
if ( ! V_19 ) {
switch ( V_36 ) {
case 4 :
V_9 -> V_26 |= V_46 ;
break;
case 8 :
V_9 -> V_26 |= V_47 ;
break;
case 16 :
V_9 -> V_26 |= V_48 ;
break;
case 32 :
V_9 -> V_26 |= V_49 ;
break;
default:
return - V_23 ;
}
V_9 -> V_26 |= V_50 ;
V_17 = true ;
}
V_19 = F_5 ( V_2 , V_11 , & V_4 -> V_9 ) ;
if ( V_19 < 0 )
return - V_23 ;
if ( ( V_19 > 0 && ! V_17 ) || ( ! V_19 && V_17 ) ) {
F_11 ( V_2 -> V_5 -> V_33 , L_16 ,
V_11 -> V_34 ) ;
return - V_23 ;
}
return V_17 ;
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
F_18 ( V_2 -> V_5 -> V_6 . V_7 , V_4 -> V_8 ,
& V_4 -> V_9 ) ;
}
static int F_19 ( struct V_51 * V_5 , struct V_10 * V_11 ,
int V_52 )
{
const struct V_53 * V_54 = V_5 -> V_54 ;
struct V_3 V_4 = { } ;
struct V_55 * V_33 = V_5 -> V_33 ;
struct V_1 * V_2 ;
unsigned long V_56 = 0 ;
int V_19 , V_57 = 0 , V_58 , V_20 ;
bool V_59 = false ;
T_1 V_8 ;
V_58 = F_20 ( V_11 , L_17 ,
V_52 * sizeof( T_1 ) ) ;
for ( V_20 = 0 ; V_20 < V_58 ; V_20 ++ ) {
V_19 = F_21 ( V_11 , L_17 , V_20 * V_52 ,
& V_8 ) ;
if ( V_19 )
return V_19 ;
if ( V_8 >= V_60 ||
! ( V_5 -> V_54 -> V_61 & F_22 ( V_8 ) ) ) {
F_11 ( V_33 , L_18 ,
V_11 -> V_34 ) ;
return - V_23 ;
}
if ( ! F_23 ( V_8 , & V_56 ) )
V_57 ++ ;
}
if ( ! V_57 ) {
F_11 ( V_33 , L_18 , V_11 -> V_34 ) ;
return - V_23 ;
}
V_2 = F_24 ( V_5 -> V_33 ,
sizeof( * V_2 ) + ( V_57 * sizeof( * V_2 -> V_62 ) ) ,
V_63 ) ;
if ( ! V_2 )
return - V_64 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_57 = V_57 ;
V_19 = V_54 -> V_65 ( V_2 , V_11 , & V_4 ) ;
if ( V_19 < 0 )
return V_19 ;
else if ( V_19 )
V_59 = true ;
V_20 = 0 ;
F_25 (cs, &cslines, AT91_MATRIX_EBI_NUM_CS) {
V_2 -> V_62 [ V_20 ] . V_8 = V_8 ;
if ( V_59 ) {
V_4 . V_8 = V_8 ;
V_54 -> V_66 ( V_2 , & V_4 ) ;
}
V_54 -> V_67 ( V_2 , & V_2 -> V_62 [ V_20 ] ) ;
if ( V_5 -> V_54 -> V_68 && V_59 )
F_26 ( V_5 -> V_69 ,
V_5 -> V_54 -> V_68 ,
F_22 ( V_8 ) , 0 ) ;
V_20 ++ ;
}
F_27 ( & V_2 -> V_70 , & V_5 -> V_71 ) ;
return 0 ;
}
static int F_28 ( struct V_51 * V_5 , struct V_10 * V_11 )
{
struct V_55 * V_33 = V_5 -> V_33 ;
struct V_72 * V_73 ;
V_73 = F_24 ( V_33 , sizeof( * V_73 ) , V_63 ) ;
if ( ! V_73 )
return - V_64 ;
V_73 -> V_30 = F_29 ( V_33 , L_19 , V_63 ) ;
if ( ! V_73 -> V_30 )
return - V_64 ;
V_73 -> V_74 = F_29 ( V_33 , L_14 , V_63 ) ;
if ( ! V_73 -> V_74 )
return - V_64 ;
V_73 -> V_75 = sizeof( L_14 ) ;
return F_30 ( V_11 , V_73 ) ;
}
static int F_31 ( struct V_76 * V_77 )
{
struct V_55 * V_33 = & V_77 -> V_33 ;
struct V_10 * V_78 , * V_11 = V_33 -> V_79 , * V_80 ;
const struct V_81 * V_82 ;
struct V_51 * V_5 ;
int V_19 , V_52 ;
struct V_14 * V_14 ;
T_1 V_21 ;
V_82 = F_32 ( V_83 , V_33 ) ;
if ( ! V_82 || ! V_82 -> V_84 )
return - V_23 ;
V_5 = F_24 ( V_33 , sizeof( * V_5 ) , V_63 ) ;
if ( ! V_5 )
return - V_64 ;
F_33 ( V_77 , V_5 ) ;
F_34 ( & V_5 -> V_71 ) ;
V_5 -> V_54 = V_82 -> V_84 ;
V_5 -> V_33 = V_33 ;
V_14 = F_35 ( V_33 , NULL ) ;
if ( F_36 ( V_14 ) )
return F_37 ( V_14 ) ;
V_5 -> V_14 = V_14 ;
V_80 = F_38 ( V_33 -> V_79 , L_20 , 0 ) ;
V_5 -> V_6 . V_7 = F_39 ( V_80 ) ;
if ( F_36 ( V_5 -> V_6 . V_7 ) )
return F_37 ( V_5 -> V_6 . V_7 ) ;
V_5 -> V_6 . V_14 = F_40 ( V_80 , 0 ) ;
if ( F_36 ( V_5 -> V_6 . V_14 ) ) {
if ( F_37 ( V_5 -> V_6 . V_14 ) != - V_85 )
return F_37 ( V_5 -> V_6 . V_14 ) ;
V_5 -> V_6 . V_14 = NULL ;
}
V_19 = F_41 ( V_5 -> V_6 . V_14 ) ;
if ( V_19 )
return V_19 ;
if ( V_5 -> V_54 -> V_68 ) {
V_5 -> V_69 =
F_42 ( V_11 , L_21 ) ;
if ( F_36 ( V_5 -> V_69 ) )
return F_37 ( V_5 -> V_69 ) ;
}
V_19 = F_7 ( V_11 , L_22 , & V_21 ) ;
if ( V_19 ) {
F_11 ( V_33 , L_23 ) ;
return V_19 ;
}
V_52 = V_21 ;
V_19 = F_7 ( V_11 , L_24 , & V_21 ) ;
if ( V_19 ) {
F_11 ( V_33 , L_23 ) ;
return V_19 ;
}
V_52 += V_21 ;
F_43 (np, child) {
if ( ! F_44 ( V_78 , L_17 , NULL ) )
continue;
V_19 = F_19 ( V_5 , V_78 , V_52 ) ;
if ( V_19 ) {
F_11 ( V_33 , L_25 ,
V_78 -> V_34 ) ;
V_19 = F_28 ( V_5 , V_78 ) ;
if ( V_19 )
return V_19 ;
}
}
return F_45 ( V_11 , NULL , NULL , V_33 ) ;
}
static T_2 int F_46 ( struct V_55 * V_33 )
{
struct V_51 * V_5 = F_47 ( V_33 ) ;
struct V_1 * V_2 ;
F_48 (ebid, &ebi->devs, node) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_57 ; V_20 ++ )
V_2 -> V_5 -> V_54 -> V_66 ( V_2 , & V_2 -> V_62 [ V_20 ] ) ;
}
return 0 ;
}
