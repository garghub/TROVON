static T_1 F_1 ( void )
{
struct V_1 * V_2 ;
T_1 T_1 ;
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
T_1 = 0 ;
F_3 (node) {
if ( V_2 -> T_1 != V_5 &&
V_2 -> T_1 > T_1 )
T_1 = V_2 -> T_1 ;
}
F_4 ( & V_4 , V_3 ) ;
return T_1 ;
}
static void F_5 ( struct V_1 * V_6 ,
int V_7 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
T_1 T_1 ;
if ( V_6 -> T_1 != 0 && V_6 -> T_1 != V_5 )
V_6 -> T_1 += V_7 ;
F_6 (overlay, prop) {
if ( F_7 ( V_10 -> V_11 , L_1 ) &&
F_7 ( V_10 -> V_11 , L_2 ) )
continue;
if ( V_10 -> V_12 < 4 )
continue;
T_1 = F_8 ( V_10 -> V_13 ) ;
if ( T_1 == V_5 )
continue;
* ( V_14 * ) V_10 -> V_13 = F_9 ( V_6 -> T_1 ) ;
}
F_10 (overlay, child)
F_5 ( V_8 , V_7 ) ;
}
static int F_11 ( struct V_1 * V_6 ,
struct V_9 * V_15 , T_1 T_1 )
{
struct V_1 * V_16 ;
struct V_9 * V_10 ;
char * V_13 , * V_17 , * V_18 , * V_19 , * V_20 , * V_21 ;
int V_22 , V_23 ;
int V_24 = 0 ;
V_13 = F_12 ( V_15 -> V_12 , V_25 ) ;
if ( ! V_13 )
return - V_26 ;
memcpy ( V_13 , V_15 -> V_13 , V_15 -> V_12 ) ;
V_18 = V_13 + V_15 -> V_12 ;
for ( V_17 = V_13 ; V_17 < V_18 ; V_17 += V_23 + 1 ) {
V_23 = strlen ( V_17 ) ;
V_19 = V_17 ;
V_21 = strchr ( V_17 , ':' ) ;
if ( ! V_21 ) {
V_24 = - V_27 ;
goto V_28;
}
* V_21 ++ = '\0' ;
V_20 = V_21 ;
V_21 = strchr ( V_21 , ':' ) ;
if ( ! V_21 ) {
V_24 = - V_27 ;
goto V_28;
}
* V_21 ++ = '\0' ;
V_24 = F_13 ( V_21 , 10 , & V_22 ) ;
if ( V_24 )
goto V_28;
V_16 = F_14 ( F_15 ( V_6 ) , V_19 ) ;
if ( ! V_16 )
continue;
F_6 (refnode, prop) {
if ( ! F_7 ( V_10 -> V_11 , V_20 ) )
break;
}
F_16 ( V_16 ) ;
if ( ! V_10 ) {
V_24 = - V_29 ;
goto V_28;
}
* ( V_14 * ) ( V_10 -> V_13 + V_22 ) = F_9 ( T_1 ) ;
}
V_28:
F_17 ( V_13 ) ;
return V_24 ;
}
static int F_18 ( const struct V_1 * V_30 ,
const struct V_1 * V_31 )
{
const char * V_32 = F_19 ( V_30 -> V_33 ) ;
const char * V_34 = F_19 ( V_31 -> V_33 ) ;
return F_20 ( V_32 , V_34 ) ;
}
static int F_21 ( struct V_1 * V_35 ,
struct V_1 * V_6 , int V_7 )
{
struct V_1 * V_8 , * V_36 ;
struct V_9 * V_37 , * V_10 ;
int V_24 , V_38 , V_39 ;
unsigned int V_40 ;
T_1 T_1 ;
if ( ! V_35 )
return 0 ;
F_6 (local_fixups, prop_fix) {
if ( ! F_7 ( V_37 -> V_11 , L_3 ) ||
! F_7 ( V_37 -> V_11 , L_1 ) ||
! F_7 ( V_37 -> V_11 , L_2 ) )
continue;
if ( ( V_37 -> V_12 % 4 ) != 0 || V_37 -> V_12 == 0 )
return - V_27 ;
V_39 = V_37 -> V_12 / sizeof( V_14 ) ;
F_6 (overlay, prop) {
if ( ! F_7 ( V_10 -> V_11 , V_37 -> V_11 ) )
break;
}
if ( ! V_10 )
return - V_27 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_40 = F_22 ( ( ( V_14 * ) V_37 -> V_13 ) [ V_38 ] ) ;
if ( ( V_40 + 4 ) > V_10 -> V_12 )
return - V_27 ;
T_1 = F_22 ( * ( V_14 * ) ( V_10 -> V_13 + V_40 ) ) ;
T_1 += V_7 ;
* ( V_14 * ) ( V_10 -> V_13 + V_40 ) = F_9 ( T_1 ) ;
}
}
F_10 (local_fixups, child) {
F_10 (overlay, overlay_child)
if ( ! F_18 ( V_8 , V_36 ) )
break;
if ( ! V_36 )
return - V_27 ;
V_24 = F_21 ( V_8 , V_36 ,
V_7 ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_6 )
{
struct V_1 * V_8 , * V_35 , * V_16 ;
struct V_1 * V_41 , * V_42 ;
struct V_9 * V_10 ;
const char * V_43 ;
T_1 T_1 , V_7 ;
int V_24 ;
V_41 = NULL ;
if ( ! V_6 ) {
F_24 ( L_4 ) ;
V_24 = - V_27 ;
goto V_44;
}
if ( ! F_25 ( V_6 , V_45 ) ) {
F_24 ( L_5 ) ;
V_24 = - V_27 ;
goto V_44;
}
V_7 = F_1 () + 1 ;
F_5 ( V_6 , V_7 ) ;
F_10 (overlay, local_fixups)
if ( ! F_20 ( V_35 -> V_11 , L_6 ) )
break;
V_24 = F_21 ( V_35 , V_6 , V_7 ) ;
if ( V_24 )
goto V_44;
V_42 = NULL ;
F_10 (overlay, child) {
if ( ! F_20 ( V_8 -> V_11 , L_7 ) )
V_42 = V_8 ;
}
if ( ! V_42 ) {
V_24 = 0 ;
goto V_44;
}
V_41 = F_26 ( L_8 ) ;
if ( ! V_41 ) {
F_24 ( L_9 ) ;
V_24 = - V_27 ;
goto V_44;
}
F_6 (overlay_fixups, prop) {
if ( ! F_7 ( V_10 -> V_11 , L_3 ) )
continue;
V_24 = F_27 ( V_41 ,
V_10 -> V_11 , & V_43 ) ;
if ( V_24 )
goto V_44;
V_16 = F_26 ( V_43 ) ;
if ( ! V_16 ) {
V_24 = - V_29 ;
goto V_44;
}
T_1 = V_16 -> T_1 ;
F_16 ( V_16 ) ;
V_24 = F_11 ( V_6 , V_10 , T_1 ) ;
if ( V_24 )
break;
}
V_44:
if ( V_24 )
F_24 ( L_10 , V_24 ) ;
F_16 ( V_41 ) ;
return V_24 ;
}
