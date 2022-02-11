static struct V_1 * F_1 ( struct V_1 * V_2 ,
const char * V_3 )
{
struct V_1 * V_4 , * V_5 ;
if ( V_2 == NULL )
return NULL ;
if ( F_2 ( V_2 -> V_3 , V_3 ) == 0 )
return F_3 ( V_2 ) ;
F_4 (node, child) {
V_5 = F_1 ( V_4 , V_3 ) ;
if ( V_5 != NULL ) {
F_5 ( V_4 ) ;
return V_5 ;
}
}
return NULL ;
}
static T_1 F_6 ( void )
{
struct V_1 * V_2 ;
T_1 T_1 ;
unsigned long V_6 ;
F_7 ( & V_7 , V_6 ) ;
T_1 = 0 ;
F_8 (node) {
if ( V_2 -> T_1 != V_8 &&
V_2 -> T_1 > T_1 )
T_1 = V_2 -> T_1 ;
}
F_9 ( & V_7 , V_6 ) ;
return T_1 ;
}
static void F_10 ( struct V_1 * V_2 ,
int V_9 )
{
struct V_1 * V_4 ;
struct V_10 * V_11 ;
T_1 T_1 ;
if ( V_2 -> T_1 != 0 && V_2 -> T_1 != V_8 )
V_2 -> T_1 += V_9 ;
F_11 (node, prop) {
if ( F_12 ( V_11 -> V_12 , L_1 ) != 0 &&
F_12 ( V_11 -> V_12 , L_2 ) != 0 )
continue;
if ( V_11 -> V_13 < 4 )
continue;
T_1 = F_13 ( V_11 -> V_14 ) ;
if ( T_1 == V_8 )
continue;
* ( V_15 * ) V_11 -> V_14 = F_14 ( V_2 -> T_1 ) ;
}
F_4 (node, child)
F_10 ( V_4 , V_9 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_10 * V_16 , int V_14 )
{
T_1 T_1 ;
struct V_1 * V_17 ;
struct V_10 * V_18 ;
char * V_19 , * V_20 , * V_21 , * V_22 , * V_23 , * V_24 ;
int V_25 , V_26 ;
int V_27 = 0 ;
V_19 = F_16 ( V_16 -> V_13 , V_28 ) ;
if ( ! V_19 ) {
F_17 ( L_3 ,
V_29 , V_16 -> V_12 ) ;
return - V_30 ;
}
memcpy ( V_19 , V_16 -> V_14 , V_16 -> V_13 ) ;
V_21 = V_19 + V_16 -> V_13 ;
for ( V_20 = V_19 ; V_20 < V_21 ; V_20 += V_26 + 1 ) {
V_26 = strlen ( V_20 ) ;
V_22 = V_20 ;
V_24 = strchr ( V_20 , ':' ) ;
if ( ! V_24 ) {
F_17 ( L_4 ,
V_29 , V_20 ) ;
V_27 = - V_31 ;
goto V_32;
}
* V_24 ++ = '\0' ;
V_23 = V_24 ;
V_24 = strchr ( V_24 , ':' ) ;
if ( ! V_24 ) {
F_17 ( L_5 ,
V_29 , ( char * ) V_16 -> V_14 ) ;
V_27 = - V_31 ;
goto V_32;
}
* V_24 ++ = '\0' ;
V_27 = F_18 ( V_24 , 10 , & V_25 ) ;
if ( V_27 != 0 ) {
F_17 ( L_6 ,
V_29 , ( char * ) V_16 -> V_14 ) ;
goto V_32;
}
V_17 = F_1 ( V_2 , V_22 ) ;
if ( ! V_17 ) {
F_19 ( L_7 ,
V_29 , ( char * ) V_16 -> V_14 ) ;
continue;
}
F_11 (refnode, sprop) {
if ( F_12 ( V_18 -> V_12 , V_23 ) == 0 )
break;
}
F_5 ( V_17 ) ;
if ( ! V_18 ) {
F_17 ( L_8 ,
V_29 , ( char * ) V_16 -> V_14 ) ;
V_27 = - V_33 ;
goto V_32;
}
T_1 = V_14 ;
* ( V_34 * ) ( V_18 -> V_14 + V_25 ) = F_14 ( T_1 ) ;
}
V_32:
F_20 ( V_19 ) ;
return V_27 ;
}
static int F_21 ( const struct V_1 * V_35 ,
const struct V_1 * V_36 )
{
const char * V_37 = strrchr ( V_35 -> V_3 , '/' ) ? : L_9 ;
const char * V_38 = strrchr ( V_36 -> V_3 , '/' ) ? : L_9 ;
return F_2 ( V_37 , V_38 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_1 * V_39 , int V_9 )
{
struct V_1 * V_4 , * V_40 ;
struct V_10 * V_16 , * V_18 ;
int V_27 , V_41 , V_42 ;
unsigned int V_43 ;
T_1 T_1 ;
if ( V_2 == NULL )
return 0 ;
F_11 (node, rprop) {
if ( F_12 ( V_16 -> V_12 , L_10 ) == 0 ||
F_12 ( V_16 -> V_12 , L_1 ) == 0 ||
F_12 ( V_16 -> V_12 , L_2 ) == 0 )
continue;
if ( ( V_16 -> V_13 % 4 ) != 0 || V_16 -> V_13 == 0 ) {
F_17 ( L_11 ,
V_29 , V_16 -> V_12 , V_2 -> V_3 ) ;
return - V_31 ;
}
V_42 = V_16 -> V_13 / sizeof( V_34 ) ;
F_11 (target, sprop) {
if ( F_12 ( V_18 -> V_12 , V_16 -> V_12 ) == 0 )
break;
}
if ( V_18 == NULL ) {
F_17 ( L_12 ,
V_29 , V_16 -> V_12 , V_2 -> V_3 ) ;
return - V_31 ;
}
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
V_43 = F_23 ( ( ( V_34 * ) V_16 -> V_14 ) [ V_41 ] ) ;
if ( V_43 >= V_18 -> V_13 ||
( V_43 + 4 ) > V_18 -> V_13 ) {
F_17 ( L_13 ,
V_29 , V_16 -> V_12 ,
V_2 -> V_3 ) ;
return - V_31 ;
}
if ( V_9 ) {
T_1 = F_23 ( * ( V_34 * ) ( V_18 -> V_14 + V_43 ) ) ;
T_1 += V_9 ;
* ( V_34 * ) ( V_18 -> V_14 + V_43 ) = F_14 ( T_1 ) ;
}
}
}
F_4 (node, child) {
F_4 (target, childtarget)
if ( F_21 ( V_4 , V_40 ) == 0 )
break;
if ( ! V_40 ) {
F_17 ( L_14 ,
V_29 , V_4 -> V_12 , V_2 -> V_3 ) ;
return - V_31 ;
}
V_27 = F_22 ( V_4 , V_40 ,
V_9 ) ;
if ( V_27 != 0 )
return V_27 ;
}
return 0 ;
}
int F_24 ( struct V_1 * V_44 )
{
struct V_1 * V_4 , * V_45 , * V_17 ;
struct V_1 * V_46 , * V_47 , * V_48 ;
struct V_10 * V_16 ;
const char * V_49 ;
T_1 T_1 , V_9 ;
int V_27 ;
if ( ! V_44 || ! F_25 ( V_44 , V_50 ) )
return - V_31 ;
V_9 = F_6 () + 1 ;
F_10 ( V_44 , V_9 ) ;
V_45 = NULL ;
F_4 (resolve, childroot)
if ( F_2 ( V_45 -> V_12 , L_15 ) == 0 )
break;
if ( V_45 != NULL ) {
V_27 = F_22 ( V_45 ,
V_44 , 0 ) ;
if ( V_27 != 0 )
return V_27 ;
F_26 ( F_22 ( V_45 ,
V_44 , V_9 ) ) ;
}
V_46 = NULL ;
V_47 = NULL ;
V_48 = NULL ;
V_46 = F_27 ( L_16 ) ;
F_4 (resolve, child) {
if ( ! V_47 &&
F_2 ( V_4 -> V_12 , L_17 ) == 0 )
V_47 = V_4 ;
if ( ! V_48 &&
F_2 ( V_4 -> V_12 , L_18 ) == 0 )
V_48 = V_4 ;
if ( V_47 && V_48 )
break;
}
if ( ! V_48 ) {
V_27 = 0 ;
goto V_51;
}
if ( ! V_46 ) {
V_27 = - V_31 ;
goto V_51;
}
F_11 (resolve_fix, rprop) {
if ( F_12 ( V_16 -> V_12 , L_10 ) == 0 )
continue;
V_27 = F_28 ( V_46 ,
V_16 -> V_12 , & V_49 ) ;
if ( V_27 != 0 ) {
F_17 ( L_19 ,
V_29 , V_16 -> V_12 ) ;
goto V_51;
}
V_17 = F_27 ( V_49 ) ;
if ( ! V_17 ) {
F_17 ( L_20 ,
V_29 , V_49 ) ;
V_27 = - V_33 ;
goto V_51;
}
T_1 = V_17 -> T_1 ;
F_5 ( V_17 ) ;
F_29 ( L_21 ,
V_29 , V_16 -> V_12 , T_1 ) ;
V_27 = F_15 ( V_44 , V_16 , T_1 ) ;
if ( V_27 )
break;
}
V_51:
F_5 ( V_46 ) ;
return V_27 ;
}
