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
if ( V_32 & V_39 )
* V_13 |= V_40 ;
else
* V_13 |= V_41 ;
}
if ( V_32 & V_42 )
* V_13 |= V_43 ;
return V_21 ;
}
static struct V_11 * F_18 ( struct V_18 * V_9 ,
struct V_1 * V_2 ,
unsigned int V_29 , const char * * V_44 ,
enum V_30 * V_45 ,
enum V_46 * V_47 )
{
struct V_18 * V_48 ;
enum V_12 V_49 ;
struct V_4 V_5 ;
struct V_11 * V_21 ;
unsigned int V_33 ;
T_1 V_50 ;
int V_14 ;
V_48 = V_2 -> V_8 ;
if ( ! V_48 )
return F_5 ( - V_17 ) ;
V_49 = 0 ;
* V_45 = 0 ;
* V_47 = 0 ;
V_14 = F_19 ( V_48 , L_1 , & V_50 ) ;
if ( V_14 )
return F_5 ( V_14 ) ;
V_5 . V_9 = V_48 ;
V_5 . V_16 = V_50 ;
for ( V_33 = 0 ; V_33 < V_50 ; V_33 ++ ) {
V_14 = F_20 ( V_9 , L_6 , V_29 * V_50 + V_33 ,
& V_5 . args [ V_33 ] ) ;
if ( V_14 )
return F_5 ( V_14 ) ;
}
V_21 = F_4 ( V_2 , & V_5 , & V_49 ) ;
if ( F_10 ( V_21 ) )
return V_21 ;
if ( V_49 & V_36 )
* V_45 |= V_37 ;
if ( F_21 ( V_9 , L_7 ) )
* V_47 |= V_51 ;
else if ( F_21 ( V_9 , L_8 ) )
* V_47 |= V_52 ;
else if ( F_21 ( V_9 , L_9 ) )
* V_47 |= V_53 ;
else {
F_22 ( L_10 ,
F_15 ( V_21 ) , V_9 -> V_44 ) ;
return F_5 ( - V_17 ) ;
}
if ( V_44 && F_23 ( V_9 , L_11 , V_44 ) )
* V_44 = V_9 -> V_44 ;
return V_21 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_11 * V_21 = NULL ;
struct V_18 * V_9 ;
const char * V_44 ;
enum V_30 V_45 ;
enum V_46 V_47 ;
unsigned int V_33 ;
int V_14 ;
F_25 (chip->of_node, np) {
if ( ! F_21 ( V_9 , L_12 ) )
continue;
for ( V_33 = 0 ; ; V_33 ++ ) {
V_21 = F_18 ( V_9 , V_2 , V_33 , & V_44 , & V_45 ,
& V_47 ) ;
if ( F_10 ( V_21 ) )
break;
V_14 = F_26 ( V_21 , V_44 , V_45 , V_47 ) ;
if ( V_14 < 0 ) {
F_12 ( V_9 ) ;
return V_14 ;
}
}
}
return 0 ;
}
int F_27 ( struct V_1 * V_54 ,
const struct V_4 * V_5 , T_1 * V_13 )
{
if ( V_54 -> V_15 < 2 ) {
F_28 ( 1 ) ;
return - V_17 ;
}
if ( F_28 ( V_5 -> V_16 < V_54 -> V_15 ) )
return - V_17 ;
if ( V_5 -> args [ 0 ] >= V_54 -> V_55 )
return - V_17 ;
if ( V_13 )
* V_13 = V_5 -> args [ 1 ] ;
return V_5 -> args [ 0 ] ;
}
int F_29 ( struct V_18 * V_9 ,
struct V_56 * V_57 ,
void * V_3 )
{
int V_14 = - V_58 ;
struct V_1 * V_54 = & V_57 -> V_54 ;
V_54 -> V_59 = F_30 ( V_9 -> V_23 , V_60 ) ;
if ( ! V_54 -> V_59 )
goto V_61;
V_57 -> V_62 = F_31 ( V_9 , 0 ) ;
if ( ! V_57 -> V_62 )
goto V_63;
V_54 -> V_64 = - 1 ;
if ( V_57 -> V_65 )
V_57 -> V_65 ( V_57 ) ;
V_57 -> V_54 . V_8 = V_9 ;
V_14 = F_32 ( V_54 , V_3 ) ;
if ( V_14 )
goto V_66;
return 0 ;
V_66:
F_33 ( V_57 -> V_62 ) ;
V_63:
F_34 ( V_54 -> V_59 ) ;
V_61:
F_35 ( L_13 ,
V_9 -> V_23 , V_14 ) ;
return V_14 ;
}
void F_36 ( struct V_56 * V_57 )
{
struct V_1 * V_54 = & V_57 -> V_54 ;
if ( ! V_57 )
return;
F_37 ( V_54 ) ;
F_33 ( V_57 -> V_62 ) ;
F_34 ( V_54 -> V_59 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_18 * V_9 = V_2 -> V_8 ;
struct V_4 V_67 ;
struct V_68 * V_69 ;
int V_20 = 0 , V_14 ;
const char * V_44 ;
static const char V_70 [] = L_14 ;
struct V_71 * V_72 ;
if ( ! V_9 )
return 0 ;
V_72 = F_39 ( V_9 , V_70 , NULL ) ;
for (; ; V_20 ++ ) {
V_14 = F_40 ( V_9 , L_15 , 3 ,
V_20 , & V_67 ) ;
if ( V_14 )
break;
V_69 = F_41 ( V_67 . V_9 ) ;
F_12 ( V_67 . V_9 ) ;
if ( ! V_69 )
return - V_24 ;
if ( V_67 . args [ 2 ] ) {
if ( V_72 ) {
F_42 ( V_9 ,
V_70 ,
V_20 , & V_44 ) ;
if ( strlen ( V_44 ) ) {
F_35 ( L_16 ,
V_9 -> V_23 ) ;
break;
}
}
V_14 = F_43 ( V_2 ,
F_44 ( V_69 ) ,
V_67 . args [ 0 ] ,
V_67 . args [ 1 ] ,
V_67 . args [ 2 ] ) ;
if ( V_14 )
return V_14 ;
} else {
if ( V_67 . args [ 1 ] ) {
F_35 ( L_17 ,
V_9 -> V_23 ) ;
break;
}
if ( ! V_72 ) {
F_35 ( L_18 ,
V_9 -> V_23 , V_70 ) ;
break;
}
V_14 = F_42 ( V_9 ,
V_70 ,
V_20 , & V_44 ) ;
if ( V_14 )
break;
if ( ! strlen ( V_44 ) ) {
F_35 ( L_19 ,
V_9 -> V_23 ) ;
break;
}
V_14 = F_45 ( V_2 , V_69 ,
V_67 . args [ 0 ] , V_44 ) ;
if ( V_14 )
return V_14 ;
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ) { return 0 ; }
int F_46 ( struct V_1 * V_2 )
{
int V_73 ;
if ( ( ! V_2 -> V_8 ) && ( V_2 -> V_74 ) )
V_2 -> V_8 = V_2 -> V_74 -> V_8 ;
if ( ! V_2 -> V_8 )
return 0 ;
if ( ! V_2 -> V_10 ) {
V_2 -> V_15 = 2 ;
V_2 -> V_10 = F_27 ;
}
if ( V_2 -> V_15 > V_75 )
return - V_17 ;
V_73 = F_38 ( V_2 ) ;
if ( V_73 )
return V_73 ;
if ( ! V_2 -> V_76 )
F_47 ( V_2 ) ;
F_48 ( V_2 -> V_8 ) ;
return F_24 ( V_2 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
F_50 ( V_2 ) ;
F_12 ( V_2 -> V_8 ) ;
}
