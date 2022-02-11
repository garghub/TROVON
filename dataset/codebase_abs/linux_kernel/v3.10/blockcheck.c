static unsigned int F_1 ( unsigned int V_1 , unsigned int * V_2 )
{
unsigned int V_3 , V_4 = 0 ;
V_3 = V_1 + 1 ;
if ( V_2 )
V_4 = * V_2 ;
V_3 += V_4 ;
for (; ( 1 << V_4 ) < ( V_3 + 1 ) ; V_4 ++ )
V_3 ++ ;
if ( V_2 )
* V_2 = V_4 ;
return V_3 ;
}
T_1 F_2 ( T_1 V_5 , void * V_6 , unsigned int V_7 , unsigned int V_8 )
{
unsigned int V_1 , V_3 , V_4 = 0 ;
F_3 ( ! V_7 ) ;
for ( V_1 = 0 ; ( V_1 = F_4 ( V_6 , V_7 , V_1 ) ) < V_7 ; V_1 ++ )
{
V_3 = F_1 ( V_8 + V_1 , & V_4 ) ;
V_5 ^= V_3 ;
}
return V_5 ;
}
T_1 F_5 ( void * V_6 , unsigned int V_9 )
{
return F_2 ( 0 , V_6 , V_9 * 8 , 0 ) ;
}
void F_6 ( void * V_6 , unsigned int V_7 , unsigned int V_8 ,
unsigned int V_10 )
{
unsigned int V_1 , V_3 ;
F_3 ( ! V_7 ) ;
if ( F_7 ( V_10 ) == 1 )
return;
if ( V_10 >= F_1 ( V_8 + V_7 , NULL ) )
return;
V_3 = F_1 ( V_8 , NULL ) ;
if ( V_10 < V_3 )
return;
for ( V_1 = 0 ; V_1 < V_7 ; V_1 ++ , V_3 ++ )
{
while ( F_7 ( V_3 ) == 1 )
V_3 ++ ;
if ( V_3 == V_10 )
{
if ( F_8 ( V_1 , V_6 ) )
F_9 ( V_1 , V_6 ) ;
else
F_10 ( V_1 , V_6 ) ;
break;
}
}
}
void F_11 ( void * V_6 , unsigned int V_9 ,
unsigned int V_10 )
{
F_6 ( V_6 , V_9 * 8 , 0 , V_10 ) ;
}
static int F_12 ( void * V_6 , T_2 * V_11 )
{
* V_11 = * ( T_2 * ) V_6 ;
return 0 ;
}
static struct V_12 * F_13 ( const char * V_13 ,
struct V_12 * V_14 ,
T_2 * V_15 )
{
return F_14 ( V_13 , V_16 | V_17 , V_14 , V_15 ,
& V_18 ) ;
}
static void F_15 ( struct V_19 * V_20 )
{
if ( V_20 ) {
F_16 ( V_20 -> V_21 ) ;
V_20 -> V_21 = NULL ;
F_16 ( V_20 -> V_22 ) ;
V_20 -> V_22 = NULL ;
F_16 ( V_20 -> V_23 ) ;
V_20 -> V_23 = NULL ;
F_16 ( V_20 -> V_24 ) ;
V_20 -> V_24 = NULL ;
}
}
static int F_17 ( struct V_19 * V_20 ,
struct V_12 * V_14 )
{
int V_25 = - V_26 ;
if ( ! V_20 )
goto V_27;
V_20 -> V_24 = F_18 ( L_1 , V_14 ) ;
if ( ! V_20 -> V_24 )
goto V_27;
V_20 -> V_21 =
F_13 ( L_2 ,
V_20 -> V_24 ,
& V_20 -> V_28 ) ;
V_20 -> V_22 =
F_13 ( L_3 ,
V_20 -> V_24 ,
& V_20 -> V_29 ) ;
V_20 -> V_23 =
F_13 ( L_4 ,
V_20 -> V_24 ,
& V_20 -> V_30 ) ;
if ( V_20 -> V_21 && V_20 -> V_22 &&
V_20 -> V_23 )
V_25 = 0 ;
V_27:
if ( V_25 )
F_15 ( V_20 ) ;
return V_25 ;
}
static inline int F_17 ( struct V_19 * V_20 ,
struct V_12 * V_14 )
{
return 0 ;
}
static inline void F_15 ( struct V_19 * V_20 )
{
}
int F_19 ( struct V_19 * V_20 ,
struct V_12 * V_14 )
{
return F_17 ( V_20 , V_14 ) ;
}
void F_20 ( struct V_19 * V_20 )
{
F_15 ( V_20 ) ;
}
static void F_21 ( struct V_19 * V_20 )
{
T_2 V_31 ;
if ( ! V_20 )
return;
F_22 ( & V_20 -> V_32 ) ;
V_20 -> V_28 ++ ;
V_31 = V_20 -> V_28 ;
F_23 ( & V_20 -> V_32 ) ;
if ( ! V_31 )
F_24 ( V_33 , L_5 ) ;
}
static void F_25 ( struct V_19 * V_20 )
{
T_2 V_31 ;
if ( ! V_20 )
return;
F_22 ( & V_20 -> V_32 ) ;
V_20 -> V_29 ++ ;
V_31 = V_20 -> V_29 ;
F_23 ( & V_20 -> V_32 ) ;
if ( ! V_31 )
F_24 ( V_33 , L_6 ) ;
}
static void F_26 ( struct V_19 * V_20 )
{
T_2 V_31 ;
if ( ! V_20 )
return;
F_22 ( & V_20 -> V_32 ) ;
V_20 -> V_30 ++ ;
V_31 = V_20 -> V_30 ;
F_23 ( & V_20 -> V_32 ) ;
if ( ! V_31 )
F_24 ( V_33 , L_7 ) ;
}
void F_27 ( void * V_6 , T_3 V_9 ,
struct V_34 * V_35 )
{
T_1 V_36 ;
T_1 V_37 ;
memset ( V_35 , 0 , sizeof( struct V_34 ) ) ;
V_36 = F_28 ( ~ 0 , V_6 , V_9 ) ;
V_37 = F_5 ( V_6 , V_9 ) ;
F_3 ( V_37 > V_38 ) ;
V_35 -> V_39 = F_29 ( V_36 ) ;
V_35 -> V_40 = F_30 ( ( V_41 ) V_37 ) ;
}
int F_31 ( void * V_6 , T_3 V_9 ,
struct V_34 * V_35 ,
struct V_19 * V_20 )
{
int V_25 = 0 ;
T_1 V_39 ;
V_41 V_40 ;
T_1 V_36 , V_37 ;
F_21 ( V_20 ) ;
V_39 = F_32 ( V_35 -> V_39 ) ;
V_40 = F_33 ( V_35 -> V_40 ) ;
memset ( V_35 , 0 , sizeof( struct V_34 ) ) ;
V_36 = F_28 ( ~ 0 , V_6 , V_9 ) ;
if ( V_36 == V_39 )
goto V_27;
F_25 ( V_20 ) ;
F_24 ( V_42 ,
L_8 ,
( unsigned int ) V_39 , ( unsigned int ) V_36 ) ;
V_37 = F_5 ( V_6 , V_9 ) ;
F_11 ( V_6 , V_9 , V_37 ^ V_40 ) ;
V_36 = F_28 ( ~ 0 , V_6 , V_9 ) ;
if ( V_36 == V_39 ) {
F_26 ( V_20 ) ;
goto V_27;
}
F_24 ( V_42 , L_9 ,
( unsigned int ) V_39 , ( unsigned int ) V_36 ) ;
V_25 = - V_43 ;
V_27:
V_35 -> V_39 = F_29 ( V_39 ) ;
V_35 -> V_40 = F_30 ( V_40 ) ;
return V_25 ;
}
void F_34 ( struct V_44 * * V_45 , int V_8 ,
struct V_34 * V_35 )
{
int V_1 ;
T_1 V_36 , V_37 ;
F_3 ( V_8 < 0 ) ;
if ( ! V_8 )
return;
memset ( V_35 , 0 , sizeof( struct V_34 ) ) ;
for ( V_1 = 0 , V_36 = ~ 0 , V_37 = 0 ; V_1 < V_8 ; V_1 ++ ) {
V_36 = F_28 ( V_36 , V_45 [ V_1 ] -> V_46 , V_45 [ V_1 ] -> V_47 ) ;
V_37 = ( V_41 ) F_2 ( V_37 , V_45 [ V_1 ] -> V_46 ,
V_45 [ V_1 ] -> V_47 * 8 ,
V_45 [ V_1 ] -> V_47 * 8 * V_1 ) ;
}
F_3 ( V_37 > V_38 ) ;
V_35 -> V_39 = F_29 ( V_36 ) ;
V_35 -> V_40 = F_30 ( ( V_41 ) V_37 ) ;
}
int F_35 ( struct V_44 * * V_45 , int V_8 ,
struct V_34 * V_35 ,
struct V_19 * V_20 )
{
int V_1 , V_25 = 0 ;
T_1 V_39 ;
V_41 V_40 ;
T_1 V_36 , V_37 , V_10 ;
F_3 ( V_8 < 0 ) ;
if ( ! V_8 )
return 0 ;
F_21 ( V_20 ) ;
V_39 = F_32 ( V_35 -> V_39 ) ;
V_40 = F_33 ( V_35 -> V_40 ) ;
memset ( V_35 , 0 , sizeof( struct V_34 ) ) ;
for ( V_1 = 0 , V_36 = ~ 0 ; V_1 < V_8 ; V_1 ++ )
V_36 = F_28 ( V_36 , V_45 [ V_1 ] -> V_46 , V_45 [ V_1 ] -> V_47 ) ;
if ( V_36 == V_39 )
goto V_27;
F_25 ( V_20 ) ;
F_24 ( V_42 ,
L_10 ,
( unsigned int ) V_39 , ( unsigned int ) V_36 ) ;
for ( V_1 = 0 , V_37 = 0 ; V_1 < V_8 ; V_1 ++ ) {
V_37 = ( V_41 ) F_2 ( V_37 , V_45 [ V_1 ] -> V_46 ,
V_45 [ V_1 ] -> V_47 * 8 ,
V_45 [ V_1 ] -> V_47 * 8 * V_1 ) ;
}
V_10 = V_37 ^ V_40 ;
for ( V_1 = 0 ; V_1 < V_8 ; V_1 ++ ) {
F_6 ( V_45 [ V_1 ] -> V_46 , V_45 [ V_1 ] -> V_47 * 8 ,
V_45 [ V_1 ] -> V_47 * 8 * V_1 , V_10 ) ;
}
for ( V_1 = 0 , V_36 = ~ 0 ; V_1 < V_8 ; V_1 ++ )
V_36 = F_28 ( V_36 , V_45 [ V_1 ] -> V_46 , V_45 [ V_1 ] -> V_47 ) ;
if ( V_36 == V_39 ) {
F_26 ( V_20 ) ;
goto V_27;
}
F_24 ( V_42 , L_11 ,
( unsigned int ) V_39 , ( unsigned int ) V_36 ) ;
V_25 = - V_43 ;
V_27:
V_35 -> V_39 = F_29 ( V_39 ) ;
V_35 -> V_40 = F_30 ( V_40 ) ;
return V_25 ;
}
void F_36 ( struct V_48 * V_49 , void * V_6 ,
struct V_34 * V_35 )
{
if ( F_37 ( F_38 ( V_49 ) ) )
F_27 ( V_6 , V_49 -> V_50 , V_35 ) ;
}
int F_39 ( struct V_48 * V_49 , void * V_6 ,
struct V_34 * V_35 )
{
int V_25 = 0 ;
struct V_51 * V_52 = F_38 ( V_49 ) ;
if ( F_37 ( V_52 ) )
V_25 = F_31 ( V_6 , V_49 -> V_50 , V_35 ,
& V_52 -> V_53 ) ;
return V_25 ;
}
void F_40 ( struct V_48 * V_49 ,
struct V_44 * * V_45 , int V_8 ,
struct V_34 * V_35 )
{
if ( F_37 ( F_38 ( V_49 ) ) )
F_34 ( V_45 , V_8 , V_35 ) ;
}
int F_41 ( struct V_48 * V_49 ,
struct V_44 * * V_45 , int V_8 ,
struct V_34 * V_35 )
{
int V_25 = 0 ;
struct V_51 * V_52 = F_38 ( V_49 ) ;
if ( F_37 ( V_52 ) )
V_25 = F_35 ( V_45 , V_8 , V_35 ,
& V_52 -> V_53 ) ;
return V_25 ;
}
