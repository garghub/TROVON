static int F_1 ( struct V_1 * V_2 ,
enum V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 )
* V_4 = V_6 -> V_4 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 ) {
F_3 ( & V_2 -> V_8 ,
L_1 ) ;
return 0 ;
}
F_4 ( & V_2 -> V_9 ) ;
if ( V_4 == V_10 &&
! V_6 -> V_11 -> V_12 . V_13 )
V_2 -> V_14 = V_15 ;
else
V_2 -> V_14 = 0 ;
F_5 ( & V_2 -> V_9 ) ;
V_6 -> V_4 = V_4 ;
F_6 ( V_2 ) ;
F_7 ( V_6 -> V_11 -> V_16 ,
L_2 ,
V_2 -> V_14 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_17 ,
enum V_18 * type )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_19 = V_6 -> V_11 -> V_12 . V_20 ;
int V_21 ;
if ( V_17 < 0 || V_17 >= V_19 )
return - V_22 ;
V_21 = V_6 -> V_11 -> V_12 . V_21 [ V_17 ] ;
if ( V_21 == V_23 )
* type = V_24 ;
else if ( V_21 == V_25 )
* type = V_26 ;
else if ( V_21 == V_27 )
* type = V_28 ;
else
return - V_22 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_17 ,
unsigned long * V_29 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_19 = V_6 -> V_11 -> V_12 . V_20 ;
if ( V_17 < 0 || V_17 >= V_19 )
return - V_22 ;
* V_29 = V_6 -> V_11 -> V_12 . V_30 [ V_17 ] ;
* V_29 = * V_29 * V_31 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long * V_29 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_19 = V_6 -> V_11 -> V_12 . V_20 ;
return F_9 ( V_2 , V_19 - 1 , V_29 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
int V_34 = 0 , V_35 , V_36 , V_37 ;
struct V_38 * V_39 , * V_40 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_41 * V_42 = V_6 -> V_11 ;
V_39 = (struct V_38 * ) V_42 -> V_43 . V_44 ;
V_36 = V_42 -> V_43 . V_45 ;
if ( V_39 == NULL || V_36 == 0 )
return 0 ;
for ( V_35 = 0 ; V_35 < V_6 -> V_46 ; V_35 ++ )
if ( V_33 == V_6 -> V_47 [ V_35 ] )
break;
if ( V_35 == V_6 -> V_46 )
return 0 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_40 = (struct V_38 * ) & ( V_39 [ V_35 ] ) ;
V_37 = F_12 ( 0 , V_40 -> V_48 ) ;
if ( V_37 == V_49 )
return 0 ;
switch ( F_13 ( V_35 ) ) {
case V_50 :
case V_51 :
if ( F_14 ( V_2 , V_35 , V_33 ,
V_37 , 0 ) ) {
F_3 ( V_42 -> V_16 ,
L_3 , V_35 ) ;
V_34 = - V_22 ;
}
V_6 -> V_52 = true ;
break;
default:
V_34 = - V_22 ;
}
}
return V_34 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
int V_34 = 0 , V_35 , V_36 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_41 * V_42 = V_6 -> V_11 ;
if ( V_6 -> V_52 == false )
return 0 ;
V_36 = V_42 -> V_43 . V_45 ;
if ( V_36 == 0 )
return 0 ;
for ( V_35 = 0 ; V_35 < V_6 -> V_46 ; V_35 ++ )
if ( V_33 == V_6 -> V_47 [ V_35 ] )
break;
if ( V_35 == V_6 -> V_46 )
return 0 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
switch ( F_13 ( V_35 ) ) {
case V_50 :
case V_51 :
if ( F_16 ( V_2 , V_35 ,
V_33 ) ) {
F_3 ( V_42 -> V_16 ,
L_3 , V_35 ) ;
V_34 = - V_22 ;
}
V_6 -> V_52 = false ;
break;
default:
V_34 = - V_22 ;
}
}
return V_34 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned long * V_29 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
void * V_42 ;
if ( ! V_6 -> V_11 ) {
F_3 ( & V_2 -> V_8 ,
L_4 ) ;
return - V_22 ;
}
V_42 = V_6 -> V_11 -> V_53 ;
* V_29 = V_6 -> V_11 -> V_54 ( V_42 ) ;
* V_29 = * V_29 * V_31 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned long V_29 )
{
void * V_42 ;
int V_34 = - V_22 ;
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 -> V_11 ) {
F_3 ( & V_2 -> V_8 ,
L_4 ) ;
return - V_22 ;
}
V_42 = V_6 -> V_11 -> V_53 ;
if ( V_6 -> V_11 -> V_55 )
V_34 = V_6 -> V_11 -> V_55 ( V_42 , V_29 ) ;
return V_34 ;
}
static int F_19 ( struct V_1 * V_2 ,
int V_17 , enum V_56 * V_57 )
{
int V_34 ;
unsigned long V_58 ;
V_34 = F_9 ( V_2 , V_17 , & V_58 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_2 -> V_59 >= V_58 )
* V_57 = V_60 ;
else
* V_57 = V_61 ;
return 0 ;
}
void F_20 ( struct V_41 * V_62 )
{
unsigned int V_35 ;
char V_42 [ 10 ] ;
char * V_63 [] = { V_42 , NULL } ;
struct V_5 * V_6 ;
if ( ! V_62 || ! V_62 -> V_64 ) {
F_21 ( L_5 ) ;
return;
}
V_6 = V_62 -> V_64 ;
if ( V_6 -> V_52 == false ) {
for ( V_35 = 0 ; V_35 < V_6 -> V_46 ; V_35 ++ ) {
if ( ! V_6 -> V_47 [ V_35 ] )
continue;
F_11 ( V_6 -> V_65 ,
V_6 -> V_47 [ V_35 ] ) ;
}
}
F_6 ( V_6 -> V_65 ) ;
F_4 ( & V_6 -> V_65 -> V_9 ) ;
for ( V_35 = 0 ; V_35 < V_6 -> V_11 -> V_12 . V_20 ; V_35 ++ ) {
if ( V_6 -> V_65 -> V_66 <
V_6 -> V_11 -> V_12 . V_30 [ V_35 ] * V_31 )
break;
}
if ( V_6 -> V_4 == V_10 &&
! V_6 -> V_11 -> V_12 . V_13 ) {
if ( V_35 > 0 )
V_6 -> V_65 -> V_14 = V_67 ;
else
V_6 -> V_65 -> V_14 = V_15 ;
}
snprintf ( V_42 , sizeof( V_42 ) , L_6 , V_35 ) ;
F_22 ( & V_6 -> V_65 -> V_8 . V_68 , V_69 , V_63 ) ;
F_5 ( & V_6 -> V_65 -> V_9 ) ;
}
int F_23 ( struct V_41 * V_11 )
{
int V_34 ;
struct V_70 V_71 ;
struct V_5 * V_6 ;
if ( ! V_11 || ! V_11 -> V_54 ) {
F_21 ( L_4 ) ;
return - V_22 ;
}
V_6 = F_24 ( V_11 -> V_16 ,
sizeof( struct V_5 ) , V_72 ) ;
if ( ! V_6 )
return - V_73 ;
V_6 -> V_11 = V_11 ;
if ( V_11 -> V_43 . V_45 > 0 ) {
F_25 ( 0 , & V_71 ) ;
V_6 -> V_47 [ V_6 -> V_46 ] =
F_26 ( & V_71 ) ;
if ( F_27 ( V_6 -> V_47 [ V_6 -> V_46 ] ) ) {
F_3 ( V_11 -> V_16 ,
L_7 ) ;
V_34 = - V_22 ;
goto V_74;
}
V_6 -> V_46 ++ ;
}
V_6 -> V_65 = F_28 (
V_11 -> V_75 , V_11 -> V_12 . V_20 ,
0 , V_6 , & V_76 , NULL , 0 ,
V_11 -> V_12 . V_13 ? 0 :
V_15 ) ;
if ( F_27 ( V_6 -> V_65 ) ) {
F_3 ( V_11 -> V_16 ,
L_8 ) ;
V_34 = F_29 ( V_6 -> V_65 ) ;
goto V_74;
}
V_6 -> V_4 = V_10 ;
V_11 -> V_64 = V_6 ;
F_30 ( V_11 -> V_16 ,
L_9 , V_11 -> V_75 ) ;
return 0 ;
V_74:
F_31 ( V_11 ) ;
return V_34 ;
}
void F_31 ( struct V_41 * V_11 )
{
int V_35 ;
struct V_5 * V_6 ;
if ( ! V_11 || ! V_11 -> V_64 ) {
F_21 ( L_5 ) ;
return;
}
V_6 = V_11 -> V_64 ;
F_32 ( V_6 -> V_65 ) ;
for ( V_35 = 0 ; V_35 < V_6 -> V_46 ; ++ V_35 )
F_33 ( V_6 -> V_47 [ V_35 ] ) ;
F_30 ( V_11 -> V_16 ,
L_10 ) ;
}
