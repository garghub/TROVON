static inline T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 -> V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 -> V_5 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_2 , T_1 V_6 )
{
int V_7 ;
int V_8 ;
do {
V_7 = F_2 ( & V_2 -> V_3 -> V_5 ) ;
V_8 = V_7 + V_6 ;
while ( F_5 ( V_8 > V_2 -> F_1 ) )
V_8 -= V_2 -> F_1 ;
} while ( F_6 ( & V_2 -> V_3 -> V_5 , V_7 , V_8 ) != V_7 );
return V_7 ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_6 )
{
T_1 V_7 ;
T_1 V_8 ;
if ( F_2 ( & V_2 -> V_3 -> V_4 ) == V_2 -> F_1 )
return;
do {
V_7 = F_2 ( & V_2 -> V_3 -> V_4 ) ;
V_8 = V_7 + V_6 ;
if ( V_8 > V_2 -> F_1 )
V_8 = V_2 -> F_1 ;
} while ( F_6 ( & V_2 -> V_3 -> V_4 , V_7 , V_8 ) != V_7 );
}
static void T_2 F_8 ( struct V_1 * V_2 ,
T_3 * V_9 , T_1 V_10 , T_3 * V_11 )
{
int V_12 ;
T_4 V_13 [ V_2 -> V_14 ] ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
F_9 ( V_2 -> V_15 , V_9 , V_10 , V_13 , 0 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_14 ; V_12 ++ )
V_11 [ V_12 ] = V_13 [ V_12 ] ;
}
static int F_10 ( struct V_1 * V_2 ,
void * V_9 , T_1 V_10 , T_3 * V_11 )
{
int V_12 ;
T_4 V_13 [ V_2 -> V_14 ] ;
for ( V_12 = 0 ; V_12 < V_2 -> V_14 ; V_12 ++ )
V_13 [ V_12 ] = V_11 [ V_12 ] ;
return F_11 ( V_2 -> V_15 , V_9 , V_13 , V_10 ,
NULL , 0 , NULL , 0 , NULL ) ;
}
static void T_2 F_12 ( struct V_1 * V_2 ,
unsigned int V_5 , unsigned int V_16 )
{
struct V_17 * V_3 = V_2 -> V_3 ;
T_3 * V_18 = V_3 -> V_9 + V_2 -> F_1 ;
T_3 * V_19 ;
T_3 * V_13 ;
int V_20 = V_2 -> V_20 ;
int V_14 = V_2 -> V_14 ;
int V_4 = V_2 -> V_20 ;
if ( ! V_2 -> V_14 )
return;
V_19 = V_3 -> V_9 + ( V_5 & ~ ( V_20 - 1 ) ) ;
V_13 = V_2 -> V_21 + ( V_5 / V_20 ) * V_2 -> V_14 ;
do {
if ( V_19 + V_20 > V_18 )
V_4 = V_18 - V_19 ;
F_8 ( V_2 , V_19 , V_4 , V_13 ) ;
V_19 += V_20 ;
V_13 += V_14 ;
} while ( V_19 < V_3 -> V_9 + V_5 + V_16 );
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_17 * V_3 = V_2 -> V_3 ;
if ( ! V_2 -> V_14 )
return;
F_8 ( V_2 , ( T_3 * ) V_3 , sizeof( * V_3 ) ,
V_2 -> V_22 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_17 * V_3 = V_2 -> V_3 ;
T_3 * V_19 ;
T_3 * V_13 ;
if ( ! V_2 -> V_14 )
return;
V_19 = V_3 -> V_9 ;
V_13 = V_2 -> V_21 ;
while ( V_19 < V_3 -> V_9 + F_1 ( V_2 ) ) {
int V_23 ;
int V_4 = V_2 -> V_20 ;
if ( V_19 + V_4 > V_3 -> V_9 + V_2 -> F_1 )
V_4 = V_3 -> V_9 + V_2 -> F_1 - V_19 ;
V_23 = F_10 ( V_2 , V_19 , V_4 , V_13 ) ;
if ( V_23 > 0 ) {
F_15 ( L_1 ,
V_19 , V_23 ) ;
V_2 -> V_24 += V_23 ;
} else if ( V_23 < 0 ) {
F_15 ( L_2 ,
V_19 ) ;
V_2 -> V_25 ++ ;
}
V_19 += V_2 -> V_20 ;
V_13 += V_2 -> V_14 ;
}
}
static int F_16 ( struct V_1 * V_2 ,
int V_14 )
{
int V_23 ;
struct V_17 * V_3 = V_2 -> V_3 ;
int V_26 ;
T_1 V_27 ;
int V_28 = 8 ;
int V_29 = 0x11d ;
if ( ! V_14 )
return 0 ;
V_2 -> V_20 = 128 ;
V_2 -> V_14 = V_14 ;
V_26 = F_17 ( V_2 -> F_1 , V_2 -> V_20 ) ;
V_27 = ( V_26 + 1 ) * V_2 -> V_14 ;
if ( V_27 >= V_2 -> F_1 ) {
F_18 ( L_3 ,
V_30 , V_2 -> V_14 , V_27 , V_2 -> F_1 ) ;
return - V_31 ;
}
V_2 -> F_1 -= V_27 ;
V_2 -> V_21 = V_3 -> V_9 + V_2 -> F_1 ;
V_2 -> V_22 = V_2 -> V_21 + V_26 * V_2 -> V_14 ;
V_2 -> V_15 = F_19 ( V_28 , V_29 , 0 , 1 , V_2 -> V_14 ) ;
if ( V_2 -> V_15 == NULL ) {
F_20 ( L_4 ) ;
return - V_31 ;
}
V_2 -> V_24 = 0 ;
V_2 -> V_25 = 0 ;
V_23 = F_10 ( V_2 , V_3 , sizeof( * V_3 ) ,
V_2 -> V_22 ) ;
if ( V_23 > 0 ) {
F_20 ( L_5 , V_23 ) ;
V_2 -> V_24 += V_23 ;
} else if ( V_23 < 0 ) {
F_20 ( L_6 ) ;
V_2 -> V_25 ++ ;
}
return 0 ;
}
T_5 F_21 ( struct V_1 * V_2 ,
char * V_32 , T_1 V_10 )
{
T_5 V_33 ;
if ( V_2 -> V_24 || V_2 -> V_25 )
V_33 = snprintf ( V_32 , V_10 , L_7
L_8 ,
V_2 -> V_24 , V_2 -> V_25 ) ;
else
V_33 = snprintf ( V_32 , V_10 , L_9 ) ;
return V_33 ;
}
static void T_2 F_22 ( struct V_1 * V_2 ,
const void * V_34 , unsigned int V_5 , unsigned int V_16 )
{
struct V_17 * V_3 = V_2 -> V_3 ;
memcpy ( V_3 -> V_9 + V_5 , V_34 , V_16 ) ;
F_12 ( V_2 , V_5 , V_16 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_17 * V_3 = V_2 -> V_3 ;
T_1 V_4 = F_1 ( V_2 ) ;
T_1 V_5 = F_3 ( V_2 ) ;
if ( ! V_4 )
return;
if ( ! V_2 -> V_35 ) {
F_14 ( V_2 ) ;
V_2 -> V_35 = F_24 ( V_4 , V_36 ) ;
}
if ( ! V_2 -> V_35 ) {
F_18 ( L_10 ) ;
return;
}
V_2 -> V_37 = V_4 ;
memcpy ( V_2 -> V_35 , & V_3 -> V_9 [ V_5 ] , V_4 - V_5 ) ;
memcpy ( V_2 -> V_35 + V_4 - V_5 , & V_3 -> V_9 [ 0 ] , V_5 ) ;
}
int T_2 F_25 ( struct V_1 * V_2 ,
const void * V_34 , unsigned int V_16 )
{
int V_38 ;
int V_39 = V_16 ;
T_1 V_5 ;
if ( F_5 ( V_39 > V_2 -> F_1 ) ) {
V_34 += V_39 - V_2 -> F_1 ;
V_39 = V_2 -> F_1 ;
}
F_7 ( V_2 , V_39 ) ;
V_5 = F_4 ( V_2 , V_39 ) ;
V_38 = V_2 -> F_1 - V_5 ;
if ( F_5 ( V_38 < V_39 ) ) {
F_22 ( V_2 , V_34 , V_5 , V_38 ) ;
V_34 += V_38 ;
V_39 -= V_38 ;
V_5 = 0 ;
}
F_22 ( V_2 , V_34 , V_5 , V_39 ) ;
F_13 ( V_2 ) ;
return V_16 ;
}
T_1 F_26 ( struct V_1 * V_2 )
{
return V_2 -> V_37 ;
}
void * F_27 ( struct V_1 * V_2 )
{
return V_2 -> V_35 ;
}
void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_2 -> V_35 ) ;
V_2 -> V_35 = NULL ;
V_2 -> V_37 = 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_3 -> V_5 , 0 ) ;
F_31 ( & V_2 -> V_3 -> V_4 , 0 ) ;
F_13 ( V_2 ) ;
}
static void * F_32 ( T_6 V_5 , T_1 V_4 )
{
struct V_40 * * V_41 ;
T_6 V_42 ;
unsigned int V_43 ;
T_7 V_44 ;
unsigned int V_12 ;
void * V_45 ;
V_42 = V_5 - F_33 ( V_5 ) ;
V_43 = F_17 ( V_4 + F_33 ( V_5 ) , V_46 ) ;
V_44 = F_34 ( V_47 ) ;
V_41 = F_24 ( sizeof( struct V_40 * ) * V_43 , V_36 ) ;
if ( ! V_41 ) {
F_18 ( L_11 , V_30 ,
V_43 ) ;
return NULL ;
}
for ( V_12 = 0 ; V_12 < V_43 ; V_12 ++ ) {
T_6 V_48 = V_42 + V_12 * V_46 ;
V_41 [ V_12 ] = F_35 ( V_48 >> V_49 ) ;
}
V_45 = F_36 ( V_41 , V_43 , V_50 , V_44 ) ;
F_29 ( V_41 ) ;
return V_45 ;
}
static void * F_37 ( T_6 V_5 , T_1 V_4 )
{
if ( ! F_38 ( V_5 , V_4 , L_12 ) ) {
F_18 ( L_13 ,
( unsigned long long ) V_4 , ( unsigned long long ) V_5 ) ;
return NULL ;
}
return F_39 ( V_5 , V_4 ) ;
}
static int F_40 ( T_6 V_5 , T_6 V_4 ,
struct V_1 * V_2 )
{
V_2 -> V_51 = V_5 ;
V_2 -> V_4 = V_4 ;
if ( F_41 ( V_5 >> V_49 ) )
V_2 -> V_45 = F_32 ( V_5 , V_4 ) ;
else
V_2 -> V_45 = F_37 ( V_5 , V_4 ) ;
if ( ! V_2 -> V_45 ) {
F_18 ( L_14 , V_30 ,
( unsigned long long ) V_4 , ( unsigned long long ) V_5 ) ;
return - V_52 ;
}
V_2 -> V_3 = V_2 -> V_45 + F_33 ( V_5 ) ;
V_2 -> F_1 = V_4 - sizeof( struct V_17 ) ;
return 0 ;
}
static int T_8 F_42 ( struct V_1 * V_2 ,
T_9 V_53 , int V_14 )
{
int V_33 ;
V_33 = F_16 ( V_2 , V_14 ) ;
if ( V_33 )
return V_33 ;
V_53 ^= V_54 ;
if ( V_2 -> V_3 -> V_53 == V_53 ) {
if ( F_1 ( V_2 ) > V_2 -> F_1 ||
F_3 ( V_2 ) > F_1 ( V_2 ) )
F_20 ( L_15
L_16 ,
F_1 ( V_2 ) , F_3 ( V_2 ) ) ;
else {
F_43 ( L_17
L_16 ,
F_1 ( V_2 ) , F_3 ( V_2 ) ) ;
F_23 ( V_2 ) ;
return 0 ;
}
} else {
F_43 ( L_18
L_19 , V_2 -> V_3 -> V_53 ) ;
}
V_2 -> V_3 -> V_53 = V_53 ;
F_30 ( V_2 ) ;
return 0 ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_45 ) {
if ( F_41 ( V_2 -> V_51 >> V_49 ) ) {
F_45 ( V_2 -> V_45 ) ;
} else {
F_46 ( V_2 -> V_45 ) ;
F_47 ( V_2 -> V_51 , V_2 -> V_4 ) ;
}
V_2 -> V_45 = NULL ;
}
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
}
struct V_1 * T_8 F_48 ( T_6 V_5 ,
T_1 V_4 , T_9 V_53 ,
int V_14 )
{
struct V_1 * V_2 ;
int V_33 = - V_52 ;
V_2 = F_49 ( sizeof( struct V_1 ) , V_36 ) ;
if ( ! V_2 ) {
F_18 ( L_20 ) ;
goto V_55;
}
V_33 = F_40 ( V_5 , V_4 , V_2 ) ;
if ( V_33 )
goto V_55;
V_33 = F_42 ( V_2 , V_53 , V_14 ) ;
if ( V_33 )
goto V_55;
return V_2 ;
V_55:
F_44 ( V_2 ) ;
return F_50 ( V_33 ) ;
}
