static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
return V_2 -> V_6 -> V_7 . V_8 == V_5 -> V_9 &&
V_2 -> V_10 ( V_2 , V_5 , NULL ) >= 0 ;
}
static struct V_1 * F_2 (
struct V_4 * V_5 )
{
return F_3 ( V_5 , F_1 ) ;
}
static struct V_11 * F_4 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
enum V_12 * V_13 )
{
int V_14 ;
if ( V_2 -> V_15 != V_5 -> V_16 )
return F_5 ( - V_17 ) ;
V_14 = V_2 -> V_10 ( V_2 , V_5 , V_13 ) ;
if ( V_14 < 0 )
return F_5 ( V_14 ) ;
return F_6 ( V_2 , V_14 ) ;
}
struct V_11 * F_7 ( struct V_18 * V_9 ,
const char * V_19 , int V_20 , enum V_12 * V_13 )
{
struct V_4 V_5 ;
struct V_1 * V_2 ;
struct V_11 * V_21 ;
int V_14 ;
V_14 = F_8 ( V_9 , V_19 , L_1 , V_20 ,
& V_5 ) ;
if ( V_14 ) {
F_9 ( L_2 ,
V_22 , V_19 , V_9 -> V_23 , V_20 ) ;
return F_5 ( V_14 ) ;
}
V_2 = F_2 ( & V_5 ) ;
if ( ! V_2 ) {
V_21 = F_5 ( - V_24 ) ;
goto V_25;
}
V_21 = F_4 ( V_2 , & V_5 , V_13 ) ;
if ( F_10 ( V_21 ) )
goto V_25;
F_9 ( L_3 ,
V_22 , V_19 , V_9 -> V_23 , V_20 ,
F_11 ( V_21 ) ) ;
V_25:
F_12 ( V_5 . V_9 ) ;
return V_21 ;
}
int F_13 ( struct V_18 * V_9 , const char * V_26 ,
int V_20 , enum V_12 * V_13 )
{
struct V_11 * V_21 ;
V_21 = F_7 ( V_9 , V_26 , V_20 , V_13 ) ;
if ( F_10 ( V_21 ) )
return F_14 ( V_21 ) ;
else
return F_15 ( V_21 ) ;
}
struct V_11 * F_16 ( struct V_27 * V_7 , const char * V_28 ,
unsigned int V_29 ,
enum V_30 * V_13 )
{
char V_31 [ 32 ] ;
enum V_12 V_32 ;
struct V_11 * V_21 ;
unsigned int V_33 ;
for ( V_33 = 0 ; V_33 < F_17 ( V_34 ) ; V_33 ++ ) {
if ( V_28 )
snprintf ( V_31 , sizeof( V_31 ) , L_4 , V_28 ,
V_34 [ V_33 ] ) ;
else
snprintf ( V_31 , sizeof( V_31 ) , L_5 ,
V_34 [ V_33 ] ) ;
V_21 = F_7 ( V_7 -> V_8 , V_31 , V_29 ,
& V_32 ) ;
if ( ! F_10 ( V_21 ) || ( F_14 ( V_21 ) != - V_35 ) )
break;
}
if ( F_10 ( V_21 ) )
return V_21 ;
if ( V_32 & V_36 )
* V_13 |= V_37 ;
if ( V_32 & V_38 ) {
if ( V_32 & V_36 )
* V_13 |= V_39 ;
else
* V_13 |= V_40 ;
}
return V_21 ;
}
static struct V_11 * F_18 ( struct V_18 * V_9 ,
struct V_1 * V_2 ,
const char * * V_41 ,
enum V_30 * V_42 ,
enum V_43 * V_44 )
{
struct V_18 * V_45 ;
enum V_12 V_46 ;
struct V_4 V_5 ;
struct V_11 * V_21 ;
T_1 V_47 ;
int V_14 ;
V_45 = V_2 -> V_8 ;
if ( ! V_45 )
return F_5 ( - V_17 ) ;
V_46 = 0 ;
* V_42 = 0 ;
* V_44 = 0 ;
V_14 = F_19 ( V_45 , L_1 , & V_47 ) ;
if ( V_14 )
return F_5 ( V_14 ) ;
V_5 . V_9 = V_45 ;
V_5 . V_16 = V_47 ;
V_14 = F_20 ( V_9 , L_6 , V_5 . args , V_47 ) ;
if ( V_14 )
return F_5 ( V_14 ) ;
V_21 = F_4 ( V_2 , & V_5 , & V_46 ) ;
if ( F_10 ( V_21 ) )
return V_21 ;
if ( V_46 & V_36 )
* V_42 |= V_37 ;
if ( F_21 ( V_9 , L_7 ) )
* V_44 |= V_48 ;
else if ( F_21 ( V_9 , L_8 ) )
* V_44 |= V_49 ;
else if ( F_21 ( V_9 , L_9 ) )
* V_44 |= V_50 ;
else {
F_22 ( L_10 ,
F_15 ( V_21 ) , V_9 -> V_41 ) ;
return F_5 ( - V_17 ) ;
}
if ( V_41 && F_23 ( V_9 , L_11 , V_41 ) )
* V_41 = V_9 -> V_41 ;
return V_21 ;
}
static void F_24 ( struct V_1 * V_51 )
{
struct V_52 * V_53 = V_51 -> V_6 ;
struct V_18 * V_9 = V_51 -> V_8 ;
int V_33 ;
int V_54 ;
V_54 = F_25 ( V_9 , L_12 ) ;
if ( V_54 <= 0 )
return;
if ( V_53 -> V_55 != V_54 )
F_26 ( & V_53 -> V_7 , L_13
L_14 ,
V_54 , V_53 -> V_55 ) ;
for ( V_33 = 0 ; V_33 < V_53 -> V_55 ; V_33 ++ ) {
const char * V_41 ;
int V_14 ;
V_14 = F_27 ( V_9 ,
L_12 ,
V_33 ,
& V_41 ) ;
if ( V_14 ) {
if ( V_14 != - V_56 )
F_28 ( & V_53 -> V_7 ,
L_15 ,
V_33 , V_14 ) ;
break;
}
V_53 -> V_57 [ V_33 ] . V_41 = V_41 ;
}
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_11 * V_21 = NULL ;
struct V_18 * V_9 ;
const char * V_41 ;
enum V_30 V_42 ;
enum V_43 V_44 ;
int V_14 ;
F_30 (chip->of_node, np) {
if ( ! F_21 ( V_9 , L_16 ) )
continue;
V_21 = F_18 ( V_9 , V_2 , & V_41 , & V_42 , & V_44 ) ;
if ( F_10 ( V_21 ) )
continue;
V_14 = F_31 ( V_21 , V_41 , V_42 , V_44 ) ;
if ( V_14 < 0 )
return V_14 ;
}
return 0 ;
}
int F_32 ( struct V_1 * V_51 ,
const struct V_4 * V_5 , T_1 * V_13 )
{
if ( V_51 -> V_15 < 2 ) {
F_33 ( 1 ) ;
return - V_17 ;
}
if ( F_33 ( V_5 -> V_16 < V_51 -> V_15 ) )
return - V_17 ;
if ( V_5 -> args [ 0 ] >= V_51 -> V_55 )
return - V_17 ;
if ( V_13 )
* V_13 = V_5 -> args [ 1 ] ;
return V_5 -> args [ 0 ] ;
}
int F_34 ( struct V_18 * V_9 ,
struct V_58 * V_59 ,
void * V_3 )
{
int V_14 = - V_60 ;
struct V_1 * V_51 = & V_59 -> V_51 ;
V_51 -> V_61 = F_35 ( V_9 -> V_23 , V_62 ) ;
if ( ! V_51 -> V_61 )
goto V_63;
V_59 -> V_64 = F_36 ( V_9 , 0 ) ;
if ( ! V_59 -> V_64 )
goto V_65;
V_51 -> V_66 = - 1 ;
if ( V_59 -> V_67 )
V_59 -> V_67 ( V_59 ) ;
V_59 -> V_51 . V_8 = V_9 ;
V_14 = F_37 ( V_51 , V_3 ) ;
if ( V_14 )
goto V_68;
return 0 ;
V_68:
F_38 ( V_59 -> V_64 ) ;
V_65:
F_39 ( V_51 -> V_61 ) ;
V_63:
F_40 ( L_17 ,
V_9 -> V_23 , V_14 ) ;
return V_14 ;
}
void F_41 ( struct V_58 * V_59 )
{
struct V_1 * V_51 = & V_59 -> V_51 ;
if ( ! V_59 )
return;
F_42 ( V_51 ) ;
F_38 ( V_59 -> V_64 ) ;
F_39 ( V_51 -> V_61 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_18 * V_9 = V_2 -> V_8 ;
struct V_4 V_69 ;
struct V_70 * V_71 ;
int V_20 = 0 , V_14 ;
const char * V_41 ;
static const char V_72 [] = L_18 ;
struct V_73 * V_74 ;
if ( ! V_9 )
return 0 ;
V_74 = F_44 ( V_9 , V_72 , NULL ) ;
for (; ; V_20 ++ ) {
V_14 = F_45 ( V_9 , L_19 , 3 ,
V_20 , & V_69 ) ;
if ( V_14 )
break;
V_71 = F_46 ( V_69 . V_9 ) ;
F_12 ( V_69 . V_9 ) ;
if ( ! V_71 )
return - V_24 ;
if ( V_69 . args [ 2 ] ) {
if ( V_74 ) {
F_27 ( V_9 ,
V_72 ,
V_20 , & V_41 ) ;
if ( strlen ( V_41 ) ) {
F_40 ( L_20 ,
V_9 -> V_23 ) ;
break;
}
}
V_14 = F_47 ( V_2 ,
F_48 ( V_71 ) ,
V_69 . args [ 0 ] ,
V_69 . args [ 1 ] ,
V_69 . args [ 2 ] ) ;
if ( V_14 )
return V_14 ;
} else {
if ( V_69 . args [ 1 ] ) {
F_40 ( L_21 ,
V_9 -> V_23 ) ;
break;
}
if ( ! V_74 ) {
F_40 ( L_22 ,
V_9 -> V_23 , V_72 ) ;
break;
}
V_14 = F_27 ( V_9 ,
V_72 ,
V_20 , & V_41 ) ;
if ( V_14 )
break;
if ( ! strlen ( V_41 ) ) {
F_40 ( L_23 ,
V_9 -> V_23 ) ;
break;
}
V_14 = F_49 ( V_2 , V_71 ,
V_69 . args [ 0 ] , V_41 ) ;
if ( V_14 )
return V_14 ;
}
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ) { return 0 ; }
int F_50 ( struct V_1 * V_2 )
{
int V_75 ;
if ( ( ! V_2 -> V_8 ) && ( V_2 -> V_76 ) )
V_2 -> V_8 = V_2 -> V_76 -> V_8 ;
if ( ! V_2 -> V_8 )
return 0 ;
if ( ! V_2 -> V_10 ) {
V_2 -> V_15 = 2 ;
V_2 -> V_10 = F_32 ;
}
if ( V_2 -> V_15 > V_77 )
return - V_17 ;
V_75 = F_43 ( V_2 ) ;
if ( V_75 )
return V_75 ;
if ( ! V_2 -> V_78 )
F_24 ( V_2 ) ;
F_51 ( V_2 -> V_8 ) ;
return F_29 ( V_2 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
F_53 ( V_2 ) ;
F_12 ( V_2 -> V_8 ) ;
}
