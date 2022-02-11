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
V_14 , V_5 -> V_6 -> V_19 , V_11 ) ;
F_12 ( V_14 , V_11 ) ;
F_13 ( & V_18 , V_13 ) ;
return 0 ;
}
static int F_14 ( T_2 , T_3 V_10 , int V_20 , T_3 V_21 )
{
T_3 T_4 * V_11 = ( T_3 T_4 * ) V_5 -> V_12 ;
T_5 V_9 ;
if ( args == NULL || args -> V_15 == 0 || args -> V_16 [ 0 ] . V_22 == NULL )
return - V_7 ;
V_9 = F_10 ( V_11 ) ;
* args -> V_16 [ 0 ] . V_22 = ( ( V_9 & V_10 ) >> V_20 ) ^ V_21 ;
return 0 ;
}
static int F_15 ( T_2 , T_5 V_23 )
{
F_16 ( ( V_23 + 999 ) / 1000 ) ;
return 0 ;
}
static void F_17 ( struct V_24 * V_25 )
{
struct V_26 * V_27 , * V_28 ;
for ( V_27 = NULL ;
( V_27 = F_18 ( V_25 -> V_29 , V_27 ) ) != NULL ; )
if ( strcmp ( V_27 -> V_8 , L_2 ) == 0 )
break;
if ( V_27 == NULL )
return;
F_11 ( L_3 ,
V_25 -> V_29 -> V_19 ) ;
for ( V_28 = NULL ; ( V_28 = F_18 ( V_27 , V_28 ) ) != NULL ; ) {
const T_5 * V_30 = F_19 ( V_28 , L_4 , NULL ) ;
unsigned long V_31 ;
if ( V_30 == NULL )
continue;
V_31 = * V_30 ;
if ( V_31 < 0x50 )
V_31 += 0x50 ;
V_31 += ( unsigned long ) V_25 -> V_32 ;
F_20 ( V_28 , & V_33 , ( void * ) V_31 ) ;
}
F_11 ( L_5 ,
V_25 -> V_29 -> V_19 ) ;
for ( V_28 = NULL ; ( V_28 = F_18 ( V_27 , V_28 ) ) != NULL ; )
F_21 ( V_28 , NULL , 0 , V_34 , NULL ) ;
}
static int F_22 ( T_2 , T_5 V_31 , T_5 V_9 , T_5 V_10 )
{
struct V_24 * V_25 = V_5 -> V_12 ;
unsigned long V_13 ;
F_9 ( & V_18 , V_13 ) ;
F_23 ( V_31 , ( F_24 ( V_31 ) & ~ V_10 ) | ( V_9 & V_10 ) ) ;
F_13 ( & V_18 , V_13 ) ;
return 0 ;
}
static int F_25 ( T_2 , T_5 V_31 )
{
struct V_24 * V_25 = V_5 -> V_12 ;
if ( args == NULL || args -> V_15 == 0 || args -> V_16 [ 0 ] . V_22 == NULL )
return - V_7 ;
* args -> V_16 [ 0 ] . V_22 = F_24 ( V_31 ) ;
return 0 ;
}
static int F_26 ( T_2 , T_5 V_31 , T_3 V_9 , T_3 V_10 )
{
struct V_24 * V_25 = V_5 -> V_12 ;
unsigned long V_13 ;
F_9 ( & V_18 , V_13 ) ;
F_27 ( V_31 , ( F_28 ( V_31 ) & ~ V_10 ) | ( V_9 & V_10 ) ) ;
F_13 ( & V_18 , V_13 ) ;
return 0 ;
}
static int F_29 ( T_2 , T_5 V_31 )
{
struct V_24 * V_25 = V_5 -> V_12 ;
if ( args == NULL || args -> V_15 == 0 || args -> V_16 [ 0 ] . V_22 == NULL )
return - V_7 ;
* ( ( T_3 * ) ( args -> V_16 [ 0 ] . V_22 ) ) = F_28 ( V_31 ) ;
return 0 ;
}
static int F_30 ( T_2 , T_5 V_31 , T_5 V_10 ,
T_5 V_35 , T_5 V_21 )
{
struct V_24 * V_25 = V_5 -> V_12 ;
if ( args == NULL || args -> V_15 == 0 || args -> V_16 [ 0 ] . V_22 == NULL )
return - V_7 ;
* args -> V_16 [ 0 ] . V_22 = ( ( F_24 ( V_31 ) & V_10 ) >> V_35 ) ^ V_21 ;
return 0 ;
}
static int F_31 ( T_2 , T_5 V_31 , T_5 V_10 ,
T_5 V_35 , T_5 V_21 )
{
struct V_24 * V_25 = V_5 -> V_12 ;
if ( args == NULL || args -> V_15 == 0 || args -> V_16 [ 0 ] . V_22 == NULL )
return - V_7 ;
* ( ( T_3 * ) ( args -> V_16 [ 0 ] . V_22 ) ) = ( ( F_28 ( V_31 ) & V_10 ) >> V_35 ) ^ V_21 ;
return 0 ;
}
static int F_32 ( T_2 , T_5 V_31 , T_5 V_35 ,
T_5 V_10 )
{
struct V_24 * V_25 = V_5 -> V_12 ;
unsigned long V_13 ;
T_5 V_14 , V_36 ;
if ( args == NULL || args -> V_15 == 0 )
return - V_7 ;
F_9 ( & V_18 , V_13 ) ;
V_14 = F_24 ( V_31 ) ;
V_36 = args -> V_16 [ 0 ] . V_17 << V_35 ;
V_14 = ( V_14 & ~ V_10 ) | ( V_36 & V_10 ) ;
F_23 ( V_31 , V_14 ) ;
F_13 ( & V_18 , V_13 ) ;
return 0 ;
}
static int F_33 ( T_2 , T_5 V_31 , T_5 V_35 ,
T_5 V_10 )
{
struct V_24 * V_25 = V_5 -> V_12 ;
unsigned long V_13 ;
T_5 V_14 , V_36 ;
if ( args == NULL || args -> V_15 == 0 )
return - V_7 ;
F_9 ( & V_18 , V_13 ) ;
V_14 = F_28 ( V_31 ) ;
V_36 = args -> V_16 [ 0 ] . V_17 << V_35 ;
V_14 = ( V_14 & ~ V_10 ) | ( V_36 & V_10 ) ;
F_27 ( V_31 , V_14 ) ;
F_13 ( & V_18 , V_13 ) ;
return 0 ;
}
static void F_34 ( struct V_24 * V_25 )
{
F_11 ( L_6 ,
V_25 -> V_29 -> V_19 ) ;
F_20 ( V_25 -> V_29 , & V_37 , V_25 ) ;
}
static int F_35 ( T_2 , T_5 V_31 , T_5 V_9 , T_5 V_10 )
{
unsigned long V_13 ;
F_9 ( & V_18 , V_13 ) ;
F_36 ( V_31 , ( F_37 ( V_31 ) & ~ V_10 ) | ( V_9 & V_10 ) ) ;
F_13 ( & V_18 , V_13 ) ;
return 0 ;
}
static void F_38 ( void )
{
struct V_26 * V_38 ;
F_11 ( L_7 ,
V_39 -> V_19 ) ;
F_20 ( V_39 , & V_40 , NULL ) ;
F_21 ( V_39 , NULL , 0 , V_34 , NULL ) ;
for ( V_38 = NULL ; ( V_38 = F_18 ( V_39 , V_38 ) ) != NULL ; )
if ( strcmp ( V_38 -> V_8 , L_8 ) == 0 ) {
V_41 = V_38 ;
break;
}
if ( V_41 ) {
F_11 ( L_9 ,
V_41 -> V_19 ) ;
F_20 ( V_41 , & V_40 , NULL ) ;
F_21 ( V_41 , NULL , 0 , V_34 ,
NULL ) ;
}
}
int T_6 F_39 ( void )
{
static int V_42 ;
int V_43 ;
if ( V_42 )
return 0 ;
V_42 = 1 ;
if ( ! F_40 ( V_44 ) )
return 0 ;
F_11 ( L_10 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
if ( V_46 [ V_43 ] . V_29 ) {
F_34 ( & V_46 [ V_43 ] ) ;
F_17 ( & V_46 [ V_43 ] ) ;
}
}
if ( V_39 && V_47 )
F_38 () ;
F_11 ( L_11 ) ;
return 0 ;
}
void F_41 ( void )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
if ( V_46 [ V_43 ] . V_29 )
F_21 ( V_46 [ V_43 ] . V_29 , NULL , 0 ,
V_48 , NULL ) ;
}
if ( V_39 )
F_21 ( V_39 , NULL , 0 ,
V_48 , NULL ) ;
if ( V_41 )
F_21 ( V_41 , NULL , 0 ,
V_48 , NULL ) ;
}
void F_42 ( void )
{
int V_43 ;
if ( V_41 )
F_21 ( V_41 , NULL , 0 ,
V_49 , NULL ) ;
if ( V_39 )
F_21 ( V_39 , NULL , 0 ,
V_49 , NULL ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ ) {
if ( V_46 [ V_43 ] . V_29 )
F_21 ( V_46 [ V_43 ] . V_29 , NULL , 0 ,
V_49 , NULL ) ;
}
}
