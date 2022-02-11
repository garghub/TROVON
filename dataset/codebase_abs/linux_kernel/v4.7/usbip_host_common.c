static T_1 F_1 ( struct V_1 * V_2 )
{
char V_3 [ V_4 ] ;
int V_5 ;
int V_6 ;
char V_7 ;
int V_8 = 0 ;
snprintf ( V_3 , V_4 , L_1 ,
V_2 -> V_9 ) ;
V_5 = F_2 ( V_3 , V_10 ) ;
if ( V_5 < 0 ) {
F_3 ( L_2 , V_3 ) ;
return - 1 ;
}
V_6 = F_4 ( V_5 , & V_7 , 1 ) ;
if ( V_6 < 0 ) {
F_3 ( L_3 , V_3 ) ;
F_5 ( V_5 ) ;
return - 1 ;
}
V_8 = atoi ( & V_7 ) ;
return V_8 ;
}
static
struct V_11 * F_6 (
struct V_12 * V_13 , const char * V_14 )
{
struct V_11 * V_15 = NULL ;
struct V_11 * V_16 ;
T_2 V_17 ;
int V_18 ;
V_15 = calloc ( 1 , sizeof( struct V_11 ) ) ;
V_15 -> V_19 =
F_7 ( V_20 , V_14 ) ;
if ( ! V_15 -> V_19 ) {
F_3 ( L_4 , V_14 ) ;
goto F_3;
}
if ( V_13 -> V_21 . V_22 ( V_15 -> V_19 , & V_15 -> V_2 ) < 0 )
goto F_3;
V_15 -> V_7 = F_1 ( & V_15 -> V_2 ) ;
if ( V_15 -> V_7 < 0 )
goto F_3;
V_17 = sizeof( struct V_11 ) +
V_15 -> V_2 . V_23 * sizeof( struct V_24 ) ;
V_16 = V_15 ;
V_15 = realloc ( V_15 , V_17 ) ;
if ( ! V_15 ) {
V_15 = V_16 ;
F_8 ( L_5 ) ;
goto F_3;
}
for ( V_18 = 0 ; V_18 < V_15 -> V_2 . V_23 ; V_18 ++ ) {
if ( ! V_13 -> V_21 . V_25 )
break;
V_13 -> V_21 . V_25 ( & V_15 -> V_2 , V_18 , & V_15 -> V_26 [ V_18 ] ) ;
}
return V_15 ;
F_3:
if ( V_15 -> V_19 )
F_9 ( V_15 -> V_19 ) ;
if ( V_15 )
free ( V_15 ) ;
return NULL ;
}
static int F_10 ( struct V_12 * V_13 )
{
struct V_11 * V_15 ;
struct V_27 * V_28 ;
struct V_29 * V_30 , * V_31 ;
struct V_32 * V_33 ;
const char * V_9 ;
V_28 = F_11 ( V_20 ) ;
F_12 ( V_28 , V_13 -> V_34 ) ;
F_13 ( V_28 ) ;
V_30 = F_14 ( V_28 ) ;
F_15 (dev_list_entry, devices) {
V_9 = F_16 ( V_31 ) ;
V_33 = F_7 ( V_20 ,
V_9 ) ;
if ( V_33 == NULL )
continue;
if ( V_13 -> V_21 . V_35 ( V_33 ) ) {
V_15 = F_6 ( V_13 , V_9 ) ;
if ( ! V_15 ) {
F_8 ( L_6 ) ;
continue;
}
F_17 ( & V_15 -> V_36 , & V_13 -> V_37 ) ;
V_13 -> V_38 ++ ;
}
}
return 0 ;
}
static void F_18 ( struct V_39 * V_40 )
{
struct V_39 * V_18 , * V_41 ;
struct V_11 * V_15 ;
F_19 (i, tmp, devs) {
V_15 = F_20 ( V_18 , struct V_11 , V_36 ) ;
F_21 ( V_18 ) ;
free ( V_15 ) ;
}
}
int F_22 ( struct V_12 * V_13 )
{
int V_42 ;
V_20 = F_23 () ;
if ( ! V_20 ) {
F_3 ( L_7 ) ;
return - 1 ;
}
V_42 = F_10 ( V_13 ) ;
if ( V_42 < 0 )
goto F_3;
return 0 ;
F_3:
F_24 ( V_20 ) ;
return - 1 ;
}
void F_25 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return;
F_18 ( & V_13 -> V_37 ) ;
F_24 ( V_20 ) ;
}
int F_26 ( struct V_12 * V_13 )
{
int V_42 ;
F_18 ( & V_13 -> V_37 ) ;
V_13 -> V_38 = 0 ;
F_27 ( & V_13 -> V_37 ) ;
V_42 = F_10 ( V_13 ) ;
if ( V_42 < 0 )
return - 1 ;
return 0 ;
}
int F_28 ( struct V_11 * V_15 , int V_43 )
{
char V_44 [] = L_8 ;
char V_45 [ V_4 ] ;
char V_46 [ 30 ] ;
int V_47 ;
if ( V_15 -> V_7 != V_48 ) {
F_8 ( L_9 , V_15 -> V_2 . V_49 ) ;
switch ( V_15 -> V_7 ) {
case V_50 :
F_8 ( L_10 ) ;
break;
case V_51 :
F_8 ( L_11 ) ;
break;
default:
F_8 ( L_12 , V_15 -> V_7 ) ;
}
return - 1 ;
}
snprintf ( V_45 , sizeof( V_45 ) , L_13 ,
V_15 -> V_2 . V_9 , V_44 ) ;
snprintf ( V_46 , sizeof( V_46 ) , L_14 , V_43 ) ;
V_47 = F_29 ( V_45 , V_46 ,
strlen ( V_46 ) ) ;
if ( V_47 < 0 ) {
F_3 ( L_15 ,
V_46 , V_45 ) ;
return V_47 ;
}
F_30 ( L_16 , V_15 -> V_2 . V_49 ) ;
return V_47 ;
}
struct V_11 * F_31 (
struct V_12 * V_13 , int V_52 )
{
struct V_39 * V_18 ;
struct V_11 * V_15 ;
int V_53 = 0 ;
F_32 (i, &hdriver->edev_list) {
V_15 = F_20 ( V_18 , struct V_11 , V_36 ) ;
if ( V_52 == V_53 )
return V_15 ;
V_53 ++ ;
}
return NULL ;
}
