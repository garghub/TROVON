static struct V_1 * F_1 ( struct V_1 * V_2 ,
const char * V_3 )
{
struct V_1 * V_4 , * V_5 ;
if ( ! V_2 )
return NULL ;
if ( ! F_2 ( V_2 -> V_3 , V_3 ) )
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
static void F_10 ( struct V_1 * V_9 ,
int V_10 )
{
struct V_1 * V_4 ;
struct V_11 * V_12 ;
T_1 T_1 ;
if ( V_9 -> T_1 != 0 && V_9 -> T_1 != V_8 )
V_9 -> T_1 += V_10 ;
F_11 (overlay, prop) {
if ( F_12 ( V_12 -> V_13 , L_1 ) &&
F_12 ( V_12 -> V_13 , L_2 ) )
continue;
if ( V_12 -> V_14 < 4 )
continue;
T_1 = F_13 ( V_12 -> V_15 ) ;
if ( T_1 == V_8 )
continue;
* ( V_16 * ) V_12 -> V_15 = F_14 ( V_9 -> T_1 ) ;
}
F_4 (overlay, child)
F_10 ( V_4 , V_10 ) ;
}
static int F_15 ( struct V_1 * V_9 ,
struct V_11 * V_17 , T_1 T_1 )
{
struct V_1 * V_18 ;
struct V_11 * V_12 ;
char * V_15 , * V_19 , * V_20 , * V_21 , * V_22 , * V_23 ;
int V_24 , V_25 ;
int V_26 = 0 ;
V_15 = F_16 ( V_17 -> V_14 , V_27 ) ;
if ( ! V_15 )
return - V_28 ;
memcpy ( V_15 , V_17 -> V_15 , V_17 -> V_14 ) ;
V_20 = V_15 + V_17 -> V_14 ;
for ( V_19 = V_15 ; V_19 < V_20 ; V_19 += V_25 + 1 ) {
V_25 = strlen ( V_19 ) ;
V_21 = V_19 ;
V_23 = strchr ( V_19 , ':' ) ;
if ( ! V_23 ) {
V_26 = - V_29 ;
goto V_30;
}
* V_23 ++ = '\0' ;
V_22 = V_23 ;
V_23 = strchr ( V_23 , ':' ) ;
if ( ! V_23 ) {
V_26 = - V_29 ;
goto V_30;
}
* V_23 ++ = '\0' ;
V_26 = F_17 ( V_23 , 10 , & V_24 ) ;
if ( V_26 )
goto V_30;
V_18 = F_1 ( V_9 , V_21 ) ;
if ( ! V_18 )
continue;
F_11 (refnode, prop) {
if ( ! F_12 ( V_12 -> V_13 , V_22 ) )
break;
}
F_5 ( V_18 ) ;
if ( ! V_12 ) {
V_26 = - V_31 ;
goto V_30;
}
* ( V_16 * ) ( V_12 -> V_15 + V_24 ) = F_14 ( T_1 ) ;
}
V_30:
F_18 ( V_15 ) ;
return V_26 ;
}
static int F_19 ( const struct V_1 * V_32 ,
const struct V_1 * V_33 )
{
const char * V_34 = strrchr ( V_32 -> V_3 , '/' ) ? : L_3 ;
const char * V_35 = strrchr ( V_33 -> V_3 , '/' ) ? : L_3 ;
return F_2 ( V_34 , V_35 ) ;
}
static int F_20 ( struct V_1 * V_36 ,
struct V_1 * V_9 , int V_10 )
{
struct V_1 * V_4 , * V_37 ;
struct V_11 * V_38 , * V_12 ;
int V_26 , V_39 , V_40 ;
unsigned int V_41 ;
T_1 T_1 ;
if ( ! V_36 )
return 0 ;
F_11 (local_fixups, prop_fix) {
if ( ! F_12 ( V_38 -> V_13 , L_4 ) ||
! F_12 ( V_38 -> V_13 , L_1 ) ||
! F_12 ( V_38 -> V_13 , L_2 ) )
continue;
if ( ( V_38 -> V_14 % 4 ) != 0 || V_38 -> V_14 == 0 )
return - V_29 ;
V_40 = V_38 -> V_14 / sizeof( V_16 ) ;
F_11 (overlay, prop) {
if ( ! F_12 ( V_12 -> V_13 , V_38 -> V_13 ) )
break;
}
if ( ! V_12 )
return - V_29 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
V_41 = F_21 ( ( ( V_16 * ) V_38 -> V_15 ) [ V_39 ] ) ;
if ( ( V_41 + 4 ) > V_12 -> V_14 )
return - V_29 ;
T_1 = F_21 ( * ( V_16 * ) ( V_12 -> V_15 + V_41 ) ) ;
T_1 += V_10 ;
* ( V_16 * ) ( V_12 -> V_15 + V_41 ) = F_14 ( T_1 ) ;
}
}
F_4 (local_fixups, child) {
F_4 (overlay, overlay_child)
if ( ! F_19 ( V_4 , V_37 ) )
break;
if ( ! V_37 )
return - V_29 ;
V_26 = F_20 ( V_4 , V_37 ,
V_10 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_9 )
{
struct V_1 * V_4 , * V_36 , * V_18 ;
struct V_1 * V_42 , * V_43 ;
struct V_11 * V_12 ;
const char * V_44 ;
T_1 T_1 , V_10 ;
int V_26 ;
V_42 = NULL ;
if ( ! V_9 ) {
F_23 ( L_5 ) ;
V_26 = - V_29 ;
goto V_45;
}
if ( ! F_24 ( V_9 , V_46 ) ) {
F_23 ( L_6 ) ;
V_26 = - V_29 ;
goto V_45;
}
V_10 = F_6 () + 1 ;
F_10 ( V_9 , V_10 ) ;
F_4 (overlay, local_fixups)
if ( ! F_2 ( V_36 -> V_13 , L_7 ) )
break;
V_26 = F_20 ( V_36 , V_9 , V_10 ) ;
if ( V_26 )
goto V_45;
V_43 = NULL ;
F_4 (overlay, child) {
if ( ! F_2 ( V_4 -> V_13 , L_8 ) )
V_43 = V_4 ;
}
if ( ! V_43 ) {
V_26 = 0 ;
goto V_45;
}
V_42 = F_25 ( L_9 ) ;
if ( ! V_42 ) {
F_23 ( L_10 ) ;
V_26 = - V_29 ;
goto V_45;
}
F_11 (overlay_fixups, prop) {
if ( ! F_12 ( V_12 -> V_13 , L_4 ) )
continue;
V_26 = F_26 ( V_42 ,
V_12 -> V_13 , & V_44 ) ;
if ( V_26 )
goto V_45;
V_18 = F_25 ( V_44 ) ;
if ( ! V_18 ) {
V_26 = - V_31 ;
goto V_45;
}
T_1 = V_18 -> T_1 ;
F_5 ( V_18 ) ;
V_26 = F_15 ( V_9 , V_12 , T_1 ) ;
if ( V_26 )
break;
}
V_45:
if ( V_26 )
F_23 ( L_11 , V_26 ) ;
F_5 ( V_42 ) ;
return V_26 ;
}
