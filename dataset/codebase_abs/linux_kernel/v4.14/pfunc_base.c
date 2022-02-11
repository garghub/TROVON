static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( V_2 ) ;
return V_3 ;
}
static int F_3 ( struct V_4 * V_5 )
{
unsigned int V_1 = F_4 ( V_5 -> V_6 , 0 ) ;
if ( ! V_1 )
return - V_7 ;
return F_5 ( V_1 , F_1 , 0 , V_5 -> V_6 -> V_8 , V_5 ) ;
}
static int F_6 ( struct V_4 * V_5 )
{
unsigned int V_1 = F_4 ( V_5 -> V_6 , 0 ) ;
if ( ! V_1 )
return - V_7 ;
F_7 ( V_1 , V_5 ) ;
return 0 ;
}
static int F_8 ( T_2 , T_3 V_9 , T_3 V_10 )
{
T_3 T_4 * V_11 = ( T_3 T_4 * ) V_5 -> V_12 ;
unsigned long V_13 ;
T_3 V_14 ;
if ( args && args -> V_15 && ! args -> V_16 [ 0 ] . V_17 )
V_9 = ~ V_9 ;
F_9 ( & V_18 , V_13 ) ;
V_14 = F_10 ( V_11 ) ;
V_14 = ( V_14 & ~ V_10 ) | ( V_9 & V_10 ) ;
F_11 ( L_1 ,
V_14 , V_5 -> V_6 , V_11 ) ;
F_12 ( V_14 , V_11 ) ;
F_13 ( & V_18 , V_13 ) ;
return 0 ;
}
static int F_14 ( T_2 , T_3 V_10 , int V_19 , T_3 V_20 )
{
T_3 T_4 * V_11 = ( T_3 T_4 * ) V_5 -> V_12 ;
T_5 V_9 ;
if ( args == NULL || args -> V_15 == 0 || args -> V_16 [ 0 ] . V_21 == NULL )
return - V_7 ;
V_9 = F_10 ( V_11 ) ;
* args -> V_16 [ 0 ] . V_21 = ( ( V_9 & V_10 ) >> V_19 ) ^ V_20 ;
return 0 ;
}
static int F_15 ( T_2 , T_5 V_22 )
{
F_16 ( ( V_22 + 999 ) / 1000 ) ;
return 0 ;
}
static void F_17 ( struct V_23 * V_24 )
{
struct V_25 * V_26 , * V_27 ;
for ( V_26 = NULL ;
( V_26 = F_18 ( V_24 -> V_28 , V_26 ) ) != NULL ; )
if ( strcmp ( V_26 -> V_8 , L_2 ) == 0 )
break;
if ( V_26 == NULL )
return;
F_11 ( L_3 ,
V_24 -> V_28 ) ;
for ( V_27 = NULL ; ( V_27 = F_18 ( V_26 , V_27 ) ) != NULL ; ) {
const T_5 * V_29 = F_19 ( V_27 , L_4 , NULL ) ;
unsigned long V_30 ;
if ( V_29 == NULL )
continue;
V_30 = * V_29 ;
if ( V_30 < 0x50 )
V_30 += 0x50 ;
V_30 += ( unsigned long ) V_24 -> V_31 ;
F_20 ( V_27 , & V_32 , ( void * ) V_30 ) ;
}
F_11 ( L_5 ,
V_24 -> V_28 ) ;
for ( V_27 = NULL ; ( V_27 = F_18 ( V_26 , V_27 ) ) != NULL ; )
F_21 ( V_27 , NULL , 0 , V_33 , NULL ) ;
}
static int F_22 ( T_2 , T_5 V_30 , T_5 V_9 , T_5 V_10 )
{
struct V_23 * V_24 = V_5 -> V_12 ;
unsigned long V_13 ;
F_9 ( & V_18 , V_13 ) ;
F_23 ( V_30 , ( F_24 ( V_30 ) & ~ V_10 ) | ( V_9 & V_10 ) ) ;
F_13 ( & V_18 , V_13 ) ;
return 0 ;
}
static int F_25 ( T_2 , T_5 V_30 )
{
struct V_23 * V_24 = V_5 -> V_12 ;
if ( args == NULL || args -> V_15 == 0 || args -> V_16 [ 0 ] . V_21 == NULL )
return - V_7 ;
* args -> V_16 [ 0 ] . V_21 = F_24 ( V_30 ) ;
return 0 ;
}
static int F_26 ( T_2 , T_5 V_30 , T_3 V_9 , T_3 V_10 )
{
struct V_23 * V_24 = V_5 -> V_12 ;
unsigned long V_13 ;
F_9 ( & V_18 , V_13 ) ;
F_27 ( V_30 , ( F_28 ( V_30 ) & ~ V_10 ) | ( V_9 & V_10 ) ) ;
F_13 ( & V_18 , V_13 ) ;
return 0 ;
}
static int F_29 ( T_2 , T_5 V_30 )
{
struct V_23 * V_24 = V_5 -> V_12 ;
if ( args == NULL || args -> V_15 == 0 || args -> V_16 [ 0 ] . V_21 == NULL )
return - V_7 ;
* ( ( T_3 * ) ( args -> V_16 [ 0 ] . V_21 ) ) = F_28 ( V_30 ) ;
return 0 ;
}
static int F_30 ( T_2 , T_5 V_30 , T_5 V_10 ,
T_5 V_34 , T_5 V_20 )
{
struct V_23 * V_24 = V_5 -> V_12 ;
if ( args == NULL || args -> V_15 == 0 || args -> V_16 [ 0 ] . V_21 == NULL )
return - V_7 ;
* args -> V_16 [ 0 ] . V_21 = ( ( F_24 ( V_30 ) & V_10 ) >> V_34 ) ^ V_20 ;
return 0 ;
}
static int F_31 ( T_2 , T_5 V_30 , T_5 V_10 ,
T_5 V_34 , T_5 V_20 )
{
struct V_23 * V_24 = V_5 -> V_12 ;
if ( args == NULL || args -> V_15 == 0 || args -> V_16 [ 0 ] . V_21 == NULL )
return - V_7 ;
* ( ( T_3 * ) ( args -> V_16 [ 0 ] . V_21 ) ) = ( ( F_28 ( V_30 ) & V_10 ) >> V_34 ) ^ V_20 ;
return 0 ;
}
static int F_32 ( T_2 , T_5 V_30 , T_5 V_34 ,
T_5 V_10 )
{
struct V_23 * V_24 = V_5 -> V_12 ;
unsigned long V_13 ;
T_5 V_14 , V_35 ;
if ( args == NULL || args -> V_15 == 0 )
return - V_7 ;
F_9 ( & V_18 , V_13 ) ;
V_14 = F_24 ( V_30 ) ;
V_35 = args -> V_16 [ 0 ] . V_17 << V_34 ;
V_14 = ( V_14 & ~ V_10 ) | ( V_35 & V_10 ) ;
F_23 ( V_30 , V_14 ) ;
F_13 ( & V_18 , V_13 ) ;
return 0 ;
}
static int F_33 ( T_2 , T_5 V_30 , T_5 V_34 ,
T_5 V_10 )
{
struct V_23 * V_24 = V_5 -> V_12 ;
unsigned long V_13 ;
T_5 V_14 , V_35 ;
if ( args == NULL || args -> V_15 == 0 )
return - V_7 ;
F_9 ( & V_18 , V_13 ) ;
V_14 = F_28 ( V_30 ) ;
V_35 = args -> V_16 [ 0 ] . V_17 << V_34 ;
V_14 = ( V_14 & ~ V_10 ) | ( V_35 & V_10 ) ;
F_27 ( V_30 , V_14 ) ;
F_13 ( & V_18 , V_13 ) ;
return 0 ;
}
static void F_34 ( struct V_23 * V_24 )
{
F_11 ( L_6 ,
V_24 -> V_28 ) ;
F_20 ( V_24 -> V_28 , & V_36 , V_24 ) ;
}
static int F_35 ( T_2 , T_5 V_30 , T_5 V_9 , T_5 V_10 )
{
unsigned long V_13 ;
F_9 ( & V_18 , V_13 ) ;
F_36 ( V_30 , ( F_37 ( V_30 ) & ~ V_10 ) | ( V_9 & V_10 ) ) ;
F_13 ( & V_18 , V_13 ) ;
return 0 ;
}
static void F_38 ( void )
{
struct V_25 * V_37 ;
F_11 ( L_7 ,
V_38 ) ;
F_20 ( V_38 , & V_39 , NULL ) ;
F_21 ( V_38 , NULL , 0 , V_33 , NULL ) ;
for ( V_37 = NULL ; ( V_37 = F_18 ( V_38 , V_37 ) ) != NULL ; )
if ( strcmp ( V_37 -> V_8 , L_8 ) == 0 ) {
V_40 = V_37 ;
break;
}
if ( V_40 ) {
F_11 ( L_9 ,
V_40 ) ;
F_20 ( V_40 , & V_39 , NULL ) ;
F_21 ( V_40 , NULL , 0 , V_33 ,
NULL ) ;
}
}
int T_6 F_39 ( void )
{
static int V_41 ;
int V_42 ;
if ( V_41 )
return 0 ;
V_41 = 1 ;
if ( ! F_40 ( V_43 ) )
return 0 ;
F_11 ( L_10 ) ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
if ( V_45 [ V_42 ] . V_28 ) {
F_34 ( & V_45 [ V_42 ] ) ;
F_17 ( & V_45 [ V_42 ] ) ;
}
}
if ( V_38 && V_46 )
F_38 () ;
F_11 ( L_11 ) ;
return 0 ;
}
void F_41 ( void )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
if ( V_45 [ V_42 ] . V_28 )
F_21 ( V_45 [ V_42 ] . V_28 , NULL , 0 ,
V_47 , NULL ) ;
}
if ( V_38 )
F_21 ( V_38 , NULL , 0 ,
V_47 , NULL ) ;
if ( V_40 )
F_21 ( V_40 , NULL , 0 ,
V_47 , NULL ) ;
}
void F_42 ( void )
{
int V_42 ;
if ( V_40 )
F_21 ( V_40 , NULL , 0 ,
V_48 , NULL ) ;
if ( V_38 )
F_21 ( V_38 , NULL , 0 ,
V_48 , NULL ) ;
for ( V_42 = 0 ; V_42 < V_44 ; V_42 ++ ) {
if ( V_45 [ V_42 ] . V_28 )
F_21 ( V_45 [ V_42 ] . V_28 , NULL , 0 ,
V_48 , NULL ) ;
}
}
