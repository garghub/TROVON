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
V_22 , V_19 , V_9 , V_20 ) ;
return F_5 ( V_14 ) ;
}
V_2 = F_2 ( & V_5 ) ;
if ( ! V_2 ) {
V_21 = F_5 ( - V_23 ) ;
goto V_24;
}
V_21 = F_4 ( V_2 , & V_5 , V_13 ) ;
if ( F_10 ( V_21 ) )
goto V_24;
F_9 ( L_3 ,
V_22 , V_19 , V_9 , V_20 ,
F_11 ( V_21 ) ) ;
V_24:
F_12 ( V_5 . V_9 ) ;
return V_21 ;
}
int F_13 ( struct V_18 * V_9 , const char * V_25 ,
int V_20 , enum V_12 * V_13 )
{
struct V_11 * V_21 ;
V_21 = F_7 ( V_9 , V_25 , V_20 , V_13 ) ;
if ( F_10 ( V_21 ) )
return F_14 ( V_21 ) ;
else
return F_15 ( V_21 ) ;
}
struct V_11 * F_16 ( struct V_26 * V_7 , const char * V_27 ,
unsigned int V_28 ,
enum V_29 * V_13 )
{
char V_30 [ 32 ] ;
enum V_12 V_31 ;
struct V_11 * V_21 ;
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < F_17 ( V_33 ) ; V_32 ++ ) {
if ( V_27 )
snprintf ( V_30 , sizeof( V_30 ) , L_4 , V_27 ,
V_33 [ V_32 ] ) ;
else
snprintf ( V_30 , sizeof( V_30 ) , L_5 ,
V_33 [ V_32 ] ) ;
V_21 = F_7 ( V_7 -> V_8 , V_30 , V_28 ,
& V_31 ) ;
if ( ! F_10 ( V_21 ) || ( F_14 ( V_21 ) != - V_34 ) )
break;
}
if ( F_10 ( V_21 ) )
return V_21 ;
if ( V_31 & V_35 )
* V_13 |= V_36 ;
if ( V_31 & V_37 ) {
if ( V_31 & V_38 )
* V_13 |= V_39 ;
else
* V_13 |= V_40 ;
}
if ( V_31 & V_41 )
* V_13 |= V_42 ;
return V_21 ;
}
static struct V_11 * F_18 ( struct V_18 * V_9 ,
struct V_1 * V_2 ,
unsigned int V_28 , const char * * V_43 ,
enum V_29 * V_44 ,
enum V_45 * V_46 )
{
struct V_18 * V_47 ;
enum V_12 V_48 ;
struct V_4 V_5 ;
struct V_11 * V_21 ;
unsigned int V_32 ;
T_1 V_49 ;
int V_14 ;
V_47 = V_2 -> V_8 ;
if ( ! V_47 )
return F_5 ( - V_17 ) ;
V_48 = 0 ;
* V_44 = 0 ;
* V_46 = 0 ;
V_14 = F_19 ( V_47 , L_1 , & V_49 ) ;
if ( V_14 )
return F_5 ( V_14 ) ;
V_5 . V_9 = V_47 ;
V_5 . V_16 = V_49 ;
for ( V_32 = 0 ; V_32 < V_49 ; V_32 ++ ) {
V_14 = F_20 ( V_9 , L_6 , V_28 * V_49 + V_32 ,
& V_5 . args [ V_32 ] ) ;
if ( V_14 )
return F_5 ( V_14 ) ;
}
V_21 = F_4 ( V_2 , & V_5 , & V_48 ) ;
if ( F_10 ( V_21 ) )
return V_21 ;
if ( V_48 & V_35 )
* V_44 |= V_36 ;
if ( F_21 ( V_9 , L_7 ) )
* V_46 |= V_50 ;
else if ( F_21 ( V_9 , L_8 ) )
* V_46 |= V_51 ;
else if ( F_21 ( V_9 , L_9 ) )
* V_46 |= V_52 ;
else {
F_22 ( L_10 ,
F_15 ( V_21 ) , V_9 -> V_43 ) ;
return F_5 ( - V_17 ) ;
}
if ( V_43 && F_23 ( V_9 , L_11 , V_43 ) )
* V_43 = V_9 -> V_43 ;
return V_21 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_11 * V_21 = NULL ;
struct V_18 * V_9 ;
const char * V_43 ;
enum V_29 V_44 ;
enum V_45 V_46 ;
unsigned int V_32 ;
int V_14 ;
F_25 (chip->of_node, np) {
if ( ! F_21 ( V_9 , L_12 ) )
continue;
for ( V_32 = 0 ; ; V_32 ++ ) {
V_21 = F_18 ( V_9 , V_2 , V_32 , & V_43 , & V_44 ,
& V_46 ) ;
if ( F_10 ( V_21 ) )
break;
V_14 = F_26 ( V_21 , V_43 , V_44 , V_46 ) ;
if ( V_14 < 0 ) {
F_12 ( V_9 ) ;
return V_14 ;
}
}
}
return 0 ;
}
int F_27 ( struct V_1 * V_53 ,
const struct V_4 * V_5 , T_1 * V_13 )
{
if ( V_53 -> V_15 < 2 ) {
F_28 ( 1 ) ;
return - V_17 ;
}
if ( F_28 ( V_5 -> V_16 < V_53 -> V_15 ) )
return - V_17 ;
if ( V_5 -> args [ 0 ] >= V_53 -> V_54 )
return - V_17 ;
if ( V_13 )
* V_13 = V_5 -> args [ 1 ] ;
return V_5 -> args [ 0 ] ;
}
int F_29 ( struct V_18 * V_9 ,
struct V_55 * V_56 ,
void * V_3 )
{
int V_14 = - V_57 ;
struct V_1 * V_53 = & V_56 -> V_53 ;
V_53 -> V_58 = F_30 ( V_59 , L_13 , V_9 ) ;
if ( ! V_53 -> V_58 )
goto V_60;
V_56 -> V_61 = F_31 ( V_9 , 0 ) ;
if ( ! V_56 -> V_61 )
goto V_62;
V_53 -> V_63 = - 1 ;
if ( V_56 -> V_64 )
V_56 -> V_64 ( V_56 ) ;
V_56 -> V_53 . V_8 = V_9 ;
V_14 = F_32 ( V_53 , V_3 ) ;
if ( V_14 )
goto V_65;
return 0 ;
V_65:
F_33 ( V_56 -> V_61 ) ;
V_62:
F_34 ( V_53 -> V_58 ) ;
V_60:
F_35 ( L_14 , V_9 , V_14 ) ;
return V_14 ;
}
void F_36 ( struct V_55 * V_56 )
{
struct V_1 * V_53 = & V_56 -> V_53 ;
if ( ! V_56 )
return;
F_37 ( V_53 ) ;
F_33 ( V_56 -> V_61 ) ;
F_34 ( V_53 -> V_58 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_18 * V_9 = V_2 -> V_8 ;
struct V_4 V_66 ;
struct V_67 * V_68 ;
int V_20 = 0 , V_14 ;
const char * V_43 ;
static const char V_69 [] = L_15 ;
struct V_70 * V_71 ;
if ( ! V_9 )
return 0 ;
V_71 = F_39 ( V_9 , V_69 , NULL ) ;
for (; ; V_20 ++ ) {
V_14 = F_40 ( V_9 , L_16 , 3 ,
V_20 , & V_66 ) ;
if ( V_14 )
break;
V_68 = F_41 ( V_66 . V_9 ) ;
F_12 ( V_66 . V_9 ) ;
if ( ! V_68 )
return - V_23 ;
if ( V_66 . args [ 2 ] ) {
if ( V_71 ) {
F_42 ( V_9 ,
V_69 ,
V_20 , & V_43 ) ;
if ( strlen ( V_43 ) ) {
F_35 ( L_17 ,
V_9 ) ;
break;
}
}
V_14 = F_43 ( V_2 ,
F_44 ( V_68 ) ,
V_66 . args [ 0 ] ,
V_66 . args [ 1 ] ,
V_66 . args [ 2 ] ) ;
if ( V_14 )
return V_14 ;
} else {
if ( V_66 . args [ 1 ] ) {
F_35 ( L_18 ,
V_9 ) ;
break;
}
if ( ! V_71 ) {
F_35 ( L_19 ,
V_9 , V_69 ) ;
break;
}
V_14 = F_42 ( V_9 ,
V_69 ,
V_20 , & V_43 ) ;
if ( V_14 )
break;
if ( ! strlen ( V_43 ) ) {
F_35 ( L_20 ,
V_9 ) ;
break;
}
V_14 = F_45 ( V_2 , V_68 ,
V_66 . args [ 0 ] , V_43 ) ;
if ( V_14 )
return V_14 ;
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ) { return 0 ; }
int F_46 ( struct V_1 * V_2 )
{
int V_72 ;
if ( ( ! V_2 -> V_8 ) && ( V_2 -> V_73 ) )
V_2 -> V_8 = V_2 -> V_73 -> V_8 ;
if ( ! V_2 -> V_8 )
return 0 ;
if ( ! V_2 -> V_10 ) {
V_2 -> V_15 = 2 ;
V_2 -> V_10 = F_27 ;
}
if ( V_2 -> V_15 > V_74 )
return - V_17 ;
V_72 = F_38 ( V_2 ) ;
if ( V_72 )
return V_72 ;
if ( ! V_2 -> V_75 )
F_47 ( V_2 ) ;
F_48 ( V_2 -> V_8 ) ;
return F_24 ( V_2 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
F_50 ( V_2 ) ;
F_12 ( V_2 -> V_8 ) ;
}
