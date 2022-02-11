static struct V_1 * F_1 ( struct V_1 * V_2 ,
const char * V_3 )
{
struct V_1 * V_4 , * V_5 ;
if ( V_2 == NULL )
return NULL ;
if ( F_2 ( V_2 -> V_3 , V_3 ) == 0 )
return V_2 ;
F_3 (node, child) {
V_5 = F_1 ( V_4 , V_3 ) ;
if ( V_5 != NULL )
return V_5 ;
}
return NULL ;
}
static T_1 F_4 ( void )
{
struct V_1 * V_2 ;
T_1 T_1 ;
unsigned long V_6 ;
F_5 ( & V_7 , V_6 ) ;
T_1 = 0 ;
F_6 (node) {
if ( V_2 -> T_1 != V_8 &&
V_2 -> T_1 > T_1 )
T_1 = V_2 -> T_1 ;
}
F_7 ( & V_7 , V_6 ) ;
return T_1 ;
}
static void F_8 ( struct V_1 * V_2 ,
int V_9 )
{
struct V_1 * V_4 ;
struct V_10 * V_11 ;
T_1 T_1 ;
if ( V_2 -> T_1 != 0 && V_2 -> T_1 != V_8 )
V_2 -> T_1 += V_9 ;
F_9 (node, prop) {
if ( F_10 ( V_11 -> V_12 , L_1 ) != 0 &&
F_10 ( V_11 -> V_12 , L_2 ) != 0 )
continue;
if ( V_11 -> V_13 < 4 )
continue;
T_1 = F_11 ( V_11 -> V_14 ) ;
if ( T_1 == V_8 )
continue;
* ( V_15 * ) V_11 -> V_14 = F_12 ( V_2 -> T_1 ) ;
}
F_3 (node, child)
F_8 ( V_4 , V_9 ) ;
}
static int F_13 ( struct V_1 * V_2 , struct V_10 * V_16 , int V_14 , bool V_17 )
{
T_1 T_1 ;
struct V_1 * V_18 ;
struct V_10 * V_19 ;
char * V_20 , * V_21 , * V_22 , * V_23 , * V_24 , * V_25 ;
int V_26 , V_27 ;
int V_28 = 0 ;
V_20 = F_14 ( V_16 -> V_13 , V_29 ) ;
if ( ! V_20 ) {
F_15 ( L_3 ,
V_30 , V_16 -> V_12 ) ;
return - V_31 ;
}
memcpy ( V_20 , V_16 -> V_14 , V_16 -> V_13 ) ;
V_22 = V_20 + V_16 -> V_13 ;
for ( V_21 = V_20 ; V_21 < V_22 ; V_21 += V_27 + 1 ) {
V_27 = strlen ( V_21 ) ;
V_23 = V_21 ;
V_25 = strchr ( V_21 , ':' ) ;
if ( ! V_25 ) {
F_15 ( L_4 ,
V_30 , V_21 ) ;
V_28 = - V_32 ;
goto V_33;
}
* V_25 ++ = '\0' ;
V_24 = V_25 ;
V_25 = strchr ( V_25 , ':' ) ;
if ( ! V_25 ) {
F_15 ( L_5 ,
V_30 , ( char * ) V_16 -> V_14 ) ;
V_28 = - V_32 ;
goto V_33;
}
* V_25 ++ = '\0' ;
V_28 = F_16 ( V_25 , 10 , & V_26 ) ;
if ( V_28 != 0 ) {
F_15 ( L_6 ,
V_30 , ( char * ) V_16 -> V_14 ) ;
goto V_33;
}
V_18 = F_1 ( V_2 , V_23 ) ;
if ( ! V_18 ) {
F_17 ( L_7 ,
V_30 , ( char * ) V_16 -> V_14 ) ;
continue;
}
F_9 (refnode, sprop) {
if ( F_10 ( V_19 -> V_12 , V_24 ) == 0 )
break;
}
if ( ! V_19 ) {
F_15 ( L_8 ,
V_30 , ( char * ) V_16 -> V_14 ) ;
V_28 = - V_34 ;
goto V_33;
}
T_1 = V_17 ? F_11 ( V_19 -> V_14 + V_26 ) + V_14 : V_14 ;
* ( V_35 * ) ( V_19 -> V_14 + V_26 ) = F_12 ( T_1 ) ;
}
V_33:
F_18 ( V_20 ) ;
return V_28 ;
}
static int F_19 ( struct V_1 * V_2 ,
int V_9 )
{
struct V_1 * V_4 ;
struct V_10 * V_16 ;
int V_28 ;
F_3 (node, child)
if ( F_2 ( V_4 -> V_12 , L_9 ) == 0 )
break;
if ( ! V_4 )
return 0 ;
F_9 (child, rprop) {
if ( F_10 ( V_16 -> V_12 , L_10 ) == 0 )
continue;
V_28 = F_13 ( V_2 , V_16 , V_9 , true ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_36 )
{
struct V_1 * V_4 , * V_18 ;
struct V_1 * V_37 , * V_38 , * V_39 ;
struct V_10 * V_16 ;
const char * V_40 ;
T_1 T_1 , V_9 ;
int V_28 ;
if ( ! V_36 || ! F_21 ( V_36 , V_41 ) )
return - V_32 ;
V_9 = F_4 () + 1 ;
F_8 ( V_36 , V_9 ) ;
V_28 = F_19 ( V_36 , V_9 ) ;
if ( V_28 != 0 )
return V_28 ;
V_37 = NULL ;
V_38 = NULL ;
V_39 = NULL ;
V_37 = F_22 ( L_11 ) ;
F_3 (resolve, child) {
if ( ! V_38 &&
F_2 ( V_4 -> V_12 , L_12 ) == 0 )
V_38 = V_4 ;
if ( ! V_39 &&
F_2 ( V_4 -> V_12 , L_13 ) == 0 )
V_39 = V_4 ;
if ( V_38 && V_39 )
break;
}
if ( ! V_39 ) {
V_28 = 0 ;
goto V_42;
}
if ( ! V_37 ) {
V_28 = - V_32 ;
goto V_42;
}
F_9 (resolve_fix, rprop) {
if ( F_10 ( V_16 -> V_12 , L_10 ) == 0 )
continue;
V_28 = F_23 ( V_37 ,
V_16 -> V_12 , & V_40 ) ;
if ( V_28 != 0 ) {
F_15 ( L_14 ,
V_30 , V_16 -> V_12 ) ;
goto V_42;
}
V_18 = F_22 ( V_40 ) ;
if ( ! V_18 ) {
F_15 ( L_15 ,
V_30 , V_40 ) ;
V_28 = - V_34 ;
goto V_42;
}
T_1 = V_18 -> T_1 ;
F_24 ( V_18 ) ;
F_25 ( L_16 ,
V_30 , V_16 -> V_12 , T_1 ) ;
V_28 = F_13 ( V_36 , V_16 , T_1 , false ) ;
if ( V_28 )
break;
}
V_42:
F_24 ( V_37 ) ;
return V_28 ;
}
