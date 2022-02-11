static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = V_3 ;
int V_5 ;
if ( ( V_2 -> V_6 != V_4 -> V_7 . V_8 ) ||
( V_2 -> V_9 != V_4 -> V_7 . V_10 ) ||
( ! V_2 -> V_11 ) )
return false ;
V_5 = V_2 -> V_11 ( V_2 , & V_4 -> V_7 , V_4 -> V_12 ) ;
if ( V_5 < 0 ) {
V_4 -> V_13 = F_2 ( V_5 ) ;
return false ;
}
V_4 -> V_13 = F_3 ( V_2 , V_5 ) ;
return true ;
}
struct V_14 * F_4 ( struct V_15 * V_8 ,
const char * V_16 , int V_17 , enum V_18 * V_12 )
{
struct V_4 V_4 = {
. V_12 = V_12 ,
. V_13 = F_2 (-EPROBE_DEFER)
} ;
int V_5 ;
if ( V_12 )
* V_12 = 0 ;
V_5 = F_5 ( V_8 , V_16 , L_1 , V_17 ,
& V_4 . V_7 ) ;
if ( V_5 ) {
F_6 ( L_2 ,
V_19 , V_16 , V_8 -> V_20 , V_17 ) ;
return F_2 ( V_5 ) ;
}
F_7 ( & V_4 , F_1 ) ;
F_8 ( V_4 . V_7 . V_8 ) ;
F_6 ( L_3 ,
V_19 , V_16 , V_8 -> V_20 , V_17 ,
F_9 ( V_4 . V_13 ) ) ;
return V_4 . V_13 ;
}
int F_10 ( struct V_15 * V_8 , const char * V_21 ,
int V_17 , enum V_18 * V_12 )
{
struct V_14 * V_22 ;
V_22 = F_4 ( V_8 , V_21 , V_17 , V_12 ) ;
if ( F_11 ( V_22 ) )
return F_12 ( V_22 ) ;
else
return F_13 ( V_22 ) ;
}
static struct V_14 * F_14 ( struct V_15 * V_8 ,
const char * * V_23 ,
enum V_24 * V_25 ,
enum V_26 * V_27 )
{
struct V_15 * V_28 ;
enum V_18 V_29 ;
struct V_4 V_4 = {
. V_12 = & V_29 ,
} ;
T_1 V_30 ;
int V_31 , V_5 ;
V_28 = V_8 -> V_32 ;
if ( ! V_28 )
return F_2 ( - V_33 ) ;
V_29 = 0 ;
* V_25 = 0 ;
* V_27 = 0 ;
V_5 = F_15 ( V_28 , L_1 , & V_30 ) ;
if ( V_5 )
return F_2 ( V_5 ) ;
if ( V_30 > V_34 )
return F_2 ( - V_33 ) ;
V_4 . V_7 . V_10 = V_30 ;
V_4 . V_7 . V_8 = V_28 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
V_5 = F_16 ( V_8 , L_4 , V_31 ,
& V_4 . V_7 . args [ V_31 ] ) ;
if ( V_5 )
return F_2 ( V_5 ) ;
}
F_7 ( & V_4 , F_1 ) ;
if ( ! V_4 . V_13 ) {
if ( V_8 -> V_32 == V_8 )
return F_2 ( - V_35 ) ;
else
return F_2 ( - V_33 ) ;
}
if ( V_29 & V_36 )
* V_25 |= V_37 ;
if ( F_17 ( V_8 , L_5 ) )
* V_27 |= V_38 ;
else if ( F_17 ( V_8 , L_6 ) )
* V_27 |= V_39 ;
else if ( F_17 ( V_8 , L_7 ) )
* V_27 |= V_40 ;
else {
F_18 ( L_8 ,
F_13 ( V_4 . V_13 ) , V_8 -> V_23 ) ;
return F_2 ( - V_33 ) ;
}
if ( V_23 && F_19 ( V_8 , L_9 , V_23 ) )
* V_23 = V_8 -> V_23 ;
return V_4 . V_13 ;
}
static void F_20 ( struct V_1 * V_41 )
{
struct V_14 * V_22 = NULL ;
struct V_15 * V_8 ;
const char * V_23 ;
enum V_24 V_25 ;
enum V_26 V_27 ;
F_21 (chip->of_node, np) {
if ( ! F_17 ( V_8 , L_10 ) )
continue;
V_22 = F_14 ( V_8 , & V_23 , & V_25 , & V_27 ) ;
if ( F_11 ( V_22 ) )
continue;
if ( F_22 ( V_22 , V_23 , V_25 , V_27 ) )
continue;
}
}
int F_23 ( struct V_1 * V_2 ,
const struct V_42 * V_7 , T_1 * V_12 )
{
if ( V_2 -> V_9 < 2 ) {
F_24 ( 1 ) ;
return - V_33 ;
}
if ( F_24 ( V_7 -> V_10 < V_2 -> V_9 ) )
return - V_33 ;
if ( V_7 -> args [ 0 ] >= V_2 -> V_43 )
return - V_33 ;
if ( V_12 )
* V_12 = V_7 -> args [ 1 ] ;
return V_7 -> args [ 0 ] ;
}
int F_25 ( struct V_15 * V_8 ,
struct V_44 * V_45 ,
void * V_3 )
{
int V_5 = - V_46 ;
struct V_1 * V_2 = & V_45 -> V_2 ;
V_2 -> V_47 = F_26 ( V_8 -> V_20 , V_48 ) ;
if ( ! V_2 -> V_47 )
goto V_49;
V_45 -> V_50 = F_27 ( V_8 , 0 ) ;
if ( ! V_45 -> V_50 )
goto V_51;
V_2 -> V_52 = - 1 ;
if ( V_45 -> V_53 )
V_45 -> V_53 ( V_45 ) ;
V_45 -> V_2 . V_6 = V_8 ;
V_5 = F_28 ( V_2 , V_3 ) ;
if ( V_5 )
goto V_54;
return 0 ;
V_54:
F_29 ( V_45 -> V_50 ) ;
V_51:
F_30 ( V_2 -> V_47 ) ;
V_49:
F_31 ( L_11 ,
V_8 -> V_20 , V_5 ) ;
return V_5 ;
}
void F_32 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = & V_45 -> V_2 ;
if ( ! V_45 )
return;
F_33 ( V_2 ) ;
F_29 ( V_45 -> V_50 ) ;
F_30 ( V_2 -> V_47 ) ;
}
static int F_34 ( struct V_1 * V_41 )
{
struct V_15 * V_8 = V_41 -> V_6 ;
struct V_42 V_55 ;
struct V_56 * V_57 ;
int V_17 = 0 , V_5 ;
const char * V_23 ;
static const char V_58 [] = L_12 ;
struct V_59 * V_60 ;
if ( ! V_8 )
return 0 ;
V_60 = F_35 ( V_8 , V_58 , NULL ) ;
for (; ; V_17 ++ ) {
V_5 = F_36 ( V_8 , L_13 , 3 ,
V_17 , & V_55 ) ;
if ( V_5 )
break;
V_57 = F_37 ( V_55 . V_8 ) ;
if ( ! V_57 )
return - V_61 ;
if ( V_55 . args [ 2 ] ) {
if ( V_60 ) {
F_38 ( V_8 ,
V_58 ,
V_17 , & V_23 ) ;
if ( strlen ( V_23 ) ) {
F_31 ( L_14 ,
V_8 -> V_20 ) ;
break;
}
}
V_5 = F_39 ( V_41 ,
F_40 ( V_57 ) ,
V_55 . args [ 0 ] ,
V_55 . args [ 1 ] ,
V_55 . args [ 2 ] ) ;
if ( V_5 )
return V_5 ;
} else {
if ( V_55 . args [ 1 ] ) {
F_31 ( L_15 ,
V_8 -> V_20 ) ;
break;
}
if ( ! V_60 ) {
F_31 ( L_16 ,
V_8 -> V_20 , V_58 ) ;
break;
}
V_5 = F_38 ( V_8 ,
V_58 ,
V_17 , & V_23 ) ;
if ( V_5 )
break;
if ( ! strlen ( V_23 ) ) {
F_31 ( L_17 ,
V_8 -> V_20 ) ;
break;
}
V_5 = F_41 ( V_41 , V_57 ,
V_55 . args [ 0 ] , V_23 ) ;
if ( V_5 )
return V_5 ;
}
}
return 0 ;
}
static int F_34 ( struct V_1 * V_41 ) { return 0 ; }
int F_42 ( struct V_1 * V_41 )
{
int V_62 ;
if ( ( ! V_41 -> V_6 ) && ( V_41 -> V_32 ) )
V_41 -> V_6 = V_41 -> V_32 -> V_6 ;
if ( ! V_41 -> V_6 )
return 0 ;
if ( ! V_41 -> V_11 ) {
V_41 -> V_9 = 2 ;
V_41 -> V_11 = F_23 ;
}
V_62 = F_34 ( V_41 ) ;
if ( V_62 )
return V_62 ;
F_43 ( V_41 -> V_6 ) ;
F_20 ( V_41 ) ;
return 0 ;
}
void F_44 ( struct V_1 * V_41 )
{
F_45 ( V_41 ) ;
F_8 ( V_41 -> V_6 ) ;
}
