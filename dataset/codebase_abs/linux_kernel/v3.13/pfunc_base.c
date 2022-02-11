static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( V_2 ) ;
return V_3 ;
}
static int F_3 ( struct V_4 * V_5 )
{
unsigned int V_1 = F_4 ( V_5 -> V_6 , 0 ) ;
if ( V_1 == V_7 )
return - V_8 ;
return F_5 ( V_1 , F_1 , 0 , V_5 -> V_6 -> V_9 , V_5 ) ;
}
static int F_6 ( struct V_4 * V_5 )
{
unsigned int V_1 = F_4 ( V_5 -> V_6 , 0 ) ;
if ( V_1 == V_7 )
return - V_8 ;
F_7 ( V_1 , V_5 ) ;
return 0 ;
}
static int F_8 ( T_2 , T_3 V_10 , T_3 V_11 )
{
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_5 -> V_13 ;
unsigned long V_14 ;
T_3 V_15 ;
if ( args && args -> V_16 && ! args -> V_17 [ 0 ] . V_18 )
V_10 = ~ V_10 ;
F_9 ( & V_19 , V_14 ) ;
V_15 = F_10 ( V_12 ) ;
V_15 = ( V_15 & ~ V_11 ) | ( V_10 & V_11 ) ;
F_11 ( L_1 ,
V_15 , V_5 -> V_6 -> V_20 , V_12 ) ;
F_12 ( V_15 , V_12 ) ;
F_13 ( & V_19 , V_14 ) ;
return 0 ;
}
static int F_14 ( T_2 , T_3 V_11 , int V_21 , T_3 V_22 )
{
T_3 T_4 * V_12 = ( T_3 T_4 * ) V_5 -> V_13 ;
T_5 V_10 ;
if ( args == NULL || args -> V_16 == 0 || args -> V_17 [ 0 ] . V_23 == NULL )
return - V_8 ;
V_10 = F_10 ( V_12 ) ;
* args -> V_17 [ 0 ] . V_23 = ( ( V_10 & V_11 ) >> V_21 ) ^ V_22 ;
return 0 ;
}
static int F_15 ( T_2 , T_5 V_24 )
{
F_16 ( ( V_24 + 999 ) / 1000 ) ;
return 0 ;
}
static void F_17 ( struct V_25 * V_26 )
{
struct V_27 * V_28 , * V_29 ;
for ( V_28 = NULL ;
( V_28 = F_18 ( V_26 -> V_30 , V_28 ) ) != NULL ; )
if ( strcmp ( V_28 -> V_9 , L_2 ) == 0 )
break;
if ( V_28 == NULL )
return;
F_11 ( L_3 ,
V_26 -> V_30 -> V_20 ) ;
for ( V_29 = NULL ; ( V_29 = F_18 ( V_28 , V_29 ) ) != NULL ; ) {
const T_5 * V_31 = F_19 ( V_29 , L_4 , NULL ) ;
unsigned long V_32 ;
if ( V_31 == NULL )
continue;
V_32 = * V_31 ;
if ( V_32 < 0x50 )
V_32 += 0x50 ;
V_32 += ( unsigned long ) V_26 -> V_33 ;
F_20 ( V_29 , & V_34 , ( void * ) V_32 ) ;
}
F_11 ( L_5 ,
V_26 -> V_30 -> V_20 ) ;
for ( V_29 = NULL ; ( V_29 = F_18 ( V_28 , V_29 ) ) != NULL ; )
F_21 ( V_29 , NULL , 0 , V_35 , NULL ) ;
}
static int F_22 ( T_2 , T_5 V_32 , T_5 V_10 , T_5 V_11 )
{
struct V_25 * V_26 = V_5 -> V_13 ;
unsigned long V_14 ;
F_9 ( & V_19 , V_14 ) ;
F_23 ( V_32 , ( F_24 ( V_32 ) & ~ V_11 ) | ( V_10 & V_11 ) ) ;
F_13 ( & V_19 , V_14 ) ;
return 0 ;
}
static int F_25 ( T_2 , T_5 V_32 )
{
struct V_25 * V_26 = V_5 -> V_13 ;
if ( args == NULL || args -> V_16 == 0 || args -> V_17 [ 0 ] . V_23 == NULL )
return - V_8 ;
* args -> V_17 [ 0 ] . V_23 = F_24 ( V_32 ) ;
return 0 ;
}
static int F_26 ( T_2 , T_5 V_32 , T_3 V_10 , T_3 V_11 )
{
struct V_25 * V_26 = V_5 -> V_13 ;
unsigned long V_14 ;
F_9 ( & V_19 , V_14 ) ;
F_27 ( V_32 , ( F_28 ( V_32 ) & ~ V_11 ) | ( V_10 & V_11 ) ) ;
F_13 ( & V_19 , V_14 ) ;
return 0 ;
}
static int F_29 ( T_2 , T_5 V_32 )
{
struct V_25 * V_26 = V_5 -> V_13 ;
if ( args == NULL || args -> V_16 == 0 || args -> V_17 [ 0 ] . V_23 == NULL )
return - V_8 ;
* ( ( T_3 * ) ( args -> V_17 [ 0 ] . V_23 ) ) = F_28 ( V_32 ) ;
return 0 ;
}
static int F_30 ( T_2 , T_5 V_32 , T_5 V_11 ,
T_5 V_36 , T_5 V_22 )
{
struct V_25 * V_26 = V_5 -> V_13 ;
if ( args == NULL || args -> V_16 == 0 || args -> V_17 [ 0 ] . V_23 == NULL )
return - V_8 ;
* args -> V_17 [ 0 ] . V_23 = ( ( F_24 ( V_32 ) & V_11 ) >> V_36 ) ^ V_22 ;
return 0 ;
}
static int F_31 ( T_2 , T_5 V_32 , T_5 V_11 ,
T_5 V_36 , T_5 V_22 )
{
struct V_25 * V_26 = V_5 -> V_13 ;
if ( args == NULL || args -> V_16 == 0 || args -> V_17 [ 0 ] . V_23 == NULL )
return - V_8 ;
* ( ( T_3 * ) ( args -> V_17 [ 0 ] . V_23 ) ) = ( ( F_28 ( V_32 ) & V_11 ) >> V_36 ) ^ V_22 ;
return 0 ;
}
static int F_32 ( T_2 , T_5 V_32 , T_5 V_36 ,
T_5 V_11 )
{
struct V_25 * V_26 = V_5 -> V_13 ;
unsigned long V_14 ;
T_5 V_15 , V_37 ;
if ( args == NULL || args -> V_16 == 0 )
return - V_8 ;
F_9 ( & V_19 , V_14 ) ;
V_15 = F_24 ( V_32 ) ;
V_37 = args -> V_17 [ 0 ] . V_18 << V_36 ;
V_15 = ( V_15 & ~ V_11 ) | ( V_37 & V_11 ) ;
F_23 ( V_32 , V_15 ) ;
F_13 ( & V_19 , V_14 ) ;
return 0 ;
}
static int F_33 ( T_2 , T_5 V_32 , T_5 V_36 ,
T_5 V_11 )
{
struct V_25 * V_26 = V_5 -> V_13 ;
unsigned long V_14 ;
T_5 V_15 , V_37 ;
if ( args == NULL || args -> V_16 == 0 )
return - V_8 ;
F_9 ( & V_19 , V_14 ) ;
V_15 = F_28 ( V_32 ) ;
V_37 = args -> V_17 [ 0 ] . V_18 << V_36 ;
V_15 = ( V_15 & ~ V_11 ) | ( V_37 & V_11 ) ;
F_27 ( V_32 , V_15 ) ;
F_13 ( & V_19 , V_14 ) ;
return 0 ;
}
static void F_34 ( struct V_25 * V_26 )
{
F_11 ( L_6 ,
V_26 -> V_30 -> V_20 ) ;
F_20 ( V_26 -> V_30 , & V_38 , V_26 ) ;
}
static int F_35 ( T_2 , T_5 V_32 , T_5 V_10 , T_5 V_11 )
{
unsigned long V_14 ;
F_9 ( & V_19 , V_14 ) ;
F_36 ( V_32 , ( F_37 ( V_32 ) & ~ V_11 ) | ( V_10 & V_11 ) ) ;
F_13 ( & V_19 , V_14 ) ;
return 0 ;
}
static void F_38 ( void )
{
struct V_27 * V_39 ;
F_11 ( L_7 ,
V_40 -> V_20 ) ;
F_20 ( V_40 , & V_41 , NULL ) ;
F_21 ( V_40 , NULL , 0 , V_35 , NULL ) ;
for ( V_39 = NULL ; ( V_39 = F_18 ( V_40 , V_39 ) ) != NULL ; )
if ( strcmp ( V_39 -> V_9 , L_8 ) == 0 ) {
V_42 = V_39 ;
break;
}
if ( V_42 ) {
F_11 ( L_9 ,
V_42 -> V_20 ) ;
F_20 ( V_42 , & V_41 , NULL ) ;
F_21 ( V_42 , NULL , 0 , V_35 ,
NULL ) ;
}
}
int T_6 F_39 ( void )
{
static int V_43 ;
int V_44 ;
if ( V_43 )
return 0 ;
V_43 = 1 ;
if ( ! F_40 ( V_45 ) )
return 0 ;
F_11 ( L_10 ) ;
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ ) {
if ( V_47 [ V_44 ] . V_30 ) {
F_34 ( & V_47 [ V_44 ] ) ;
F_17 ( & V_47 [ V_44 ] ) ;
}
}
if ( V_40 && V_48 )
F_38 () ;
F_11 ( L_11 ) ;
return 0 ;
}
void F_41 ( void )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ ) {
if ( V_47 [ V_44 ] . V_30 )
F_21 ( V_47 [ V_44 ] . V_30 , NULL , 0 ,
V_49 , NULL ) ;
}
if ( V_40 )
F_21 ( V_40 , NULL , 0 ,
V_49 , NULL ) ;
if ( V_42 )
F_21 ( V_42 , NULL , 0 ,
V_49 , NULL ) ;
}
void F_42 ( void )
{
int V_44 ;
if ( V_42 )
F_21 ( V_42 , NULL , 0 ,
V_50 , NULL ) ;
if ( V_40 )
F_21 ( V_40 , NULL , 0 ,
V_50 , NULL ) ;
for ( V_44 = 0 ; V_44 < V_46 ; V_44 ++ ) {
if ( V_47 [ V_44 ] . V_30 )
F_21 ( V_47 [ V_44 ] . V_30 , NULL , 0 ,
V_50 , NULL ) ;
}
}
