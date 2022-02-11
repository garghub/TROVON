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
T_4 V_13 [ V_2 -> V_14 . V_15 ] ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
F_9 ( V_2 -> V_16 , V_9 , V_10 , V_13 , 0 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_14 . V_15 ; V_12 ++ )
V_11 [ V_12 ] = V_13 [ V_12 ] ;
}
static int F_10 ( struct V_1 * V_2 ,
void * V_9 , T_1 V_10 , T_3 * V_11 )
{
int V_12 ;
T_4 V_13 [ V_2 -> V_14 . V_15 ] ;
for ( V_12 = 0 ; V_12 < V_2 -> V_14 . V_15 ; V_12 ++ )
V_13 [ V_12 ] = V_11 [ V_12 ] ;
return F_11 ( V_2 -> V_16 , V_9 , V_13 , V_10 ,
NULL , 0 , NULL , 0 , NULL ) ;
}
static void T_2 F_12 ( struct V_1 * V_2 ,
unsigned int V_5 , unsigned int V_17 )
{
struct V_18 * V_3 = V_2 -> V_3 ;
T_3 * V_19 = V_3 -> V_9 + V_2 -> F_1 ;
T_3 * V_20 ;
T_3 * V_13 ;
int V_21 = V_2 -> V_14 . V_22 ;
int V_15 = V_2 -> V_14 . V_15 ;
int V_4 = V_21 ;
if ( ! V_15 )
return;
V_20 = V_3 -> V_9 + ( V_5 & ~ ( V_21 - 1 ) ) ;
V_13 = V_2 -> V_23 + ( V_5 / V_21 ) * V_15 ;
do {
if ( V_20 + V_21 > V_19 )
V_4 = V_19 - V_20 ;
F_8 ( V_2 , V_20 , V_4 , V_13 ) ;
V_20 += V_21 ;
V_13 += V_15 ;
} while ( V_20 < V_3 -> V_9 + V_5 + V_17 );
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_18 * V_3 = V_2 -> V_3 ;
if ( ! V_2 -> V_14 . V_15 )
return;
F_8 ( V_2 , ( T_3 * ) V_3 , sizeof( * V_3 ) ,
V_2 -> V_24 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_18 * V_3 = V_2 -> V_3 ;
T_3 * V_20 ;
T_3 * V_13 ;
if ( ! V_2 -> V_14 . V_15 )
return;
V_20 = V_3 -> V_9 ;
V_13 = V_2 -> V_23 ;
while ( V_20 < V_3 -> V_9 + F_1 ( V_2 ) ) {
int V_25 ;
int V_4 = V_2 -> V_14 . V_22 ;
if ( V_20 + V_4 > V_3 -> V_9 + V_2 -> F_1 )
V_4 = V_3 -> V_9 + V_2 -> F_1 - V_20 ;
V_25 = F_10 ( V_2 , V_20 , V_4 , V_13 ) ;
if ( V_25 > 0 ) {
F_15 ( L_1 ,
V_20 , V_25 ) ;
V_2 -> V_26 += V_25 ;
} else if ( V_25 < 0 ) {
F_15 ( L_2 ,
V_20 ) ;
V_2 -> V_27 ++ ;
}
V_20 += V_2 -> V_14 . V_22 ;
V_13 += V_2 -> V_14 . V_15 ;
}
}
static int F_16 ( struct V_1 * V_2 ,
struct V_28 * V_14 )
{
int V_25 ;
struct V_18 * V_3 = V_2 -> V_3 ;
int V_29 ;
T_1 V_30 ;
if ( ! V_14 || ! V_14 -> V_15 )
return 0 ;
V_2 -> V_14 . V_22 = V_14 -> V_22 ? : 128 ;
V_2 -> V_14 . V_15 = V_14 -> V_15 ? : 16 ;
V_2 -> V_14 . V_31 = V_14 -> V_31 ? : 8 ;
V_2 -> V_14 . V_32 = V_14 -> V_32 ? : 0x11d ;
V_29 = F_17 ( V_2 -> F_1 - V_2 -> V_14 . V_15 ,
V_2 -> V_14 . V_22 +
V_2 -> V_14 . V_15 ) ;
V_30 = ( V_29 + 1 ) * V_2 -> V_14 . V_15 ;
if ( V_30 >= V_2 -> F_1 ) {
F_18 ( L_3 ,
V_33 , V_2 -> V_14 . V_15 ,
V_30 , V_2 -> F_1 ) ;
return - V_34 ;
}
V_2 -> F_1 -= V_30 ;
V_2 -> V_23 = V_3 -> V_9 + V_2 -> F_1 ;
V_2 -> V_24 = V_2 -> V_23 +
V_29 * V_2 -> V_14 . V_15 ;
V_2 -> V_16 = F_19 ( V_2 -> V_14 . V_31 , V_2 -> V_14 . V_32 ,
0 , 1 , V_2 -> V_14 . V_15 ) ;
if ( V_2 -> V_16 == NULL ) {
F_20 ( L_4 ) ;
return - V_34 ;
}
V_2 -> V_26 = 0 ;
V_2 -> V_27 = 0 ;
V_25 = F_10 ( V_2 , V_3 , sizeof( * V_3 ) ,
V_2 -> V_24 ) ;
if ( V_25 > 0 ) {
F_20 ( L_5 , V_25 ) ;
V_2 -> V_26 += V_25 ;
} else if ( V_25 < 0 ) {
F_20 ( L_6 ) ;
V_2 -> V_27 ++ ;
}
return 0 ;
}
T_5 F_21 ( struct V_1 * V_2 ,
char * V_35 , T_1 V_10 )
{
T_5 V_36 ;
if ( ! V_2 -> V_14 . V_15 )
return 0 ;
if ( V_2 -> V_26 || V_2 -> V_27 )
V_36 = snprintf ( V_35 , V_10 , L_7
L_8 ,
V_2 -> V_26 , V_2 -> V_27 ) ;
else
V_36 = snprintf ( V_35 , V_10 , L_9 ) ;
return V_36 ;
}
static void T_2 F_22 ( struct V_1 * V_2 ,
const void * V_37 , unsigned int V_5 , unsigned int V_17 )
{
struct V_18 * V_3 = V_2 -> V_3 ;
memcpy ( V_3 -> V_9 + V_5 , V_37 , V_17 ) ;
F_12 ( V_2 , V_5 , V_17 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_18 * V_3 = V_2 -> V_3 ;
T_1 V_4 = F_1 ( V_2 ) ;
T_1 V_5 = F_3 ( V_2 ) ;
if ( ! V_4 )
return;
if ( ! V_2 -> V_38 ) {
F_14 ( V_2 ) ;
V_2 -> V_38 = F_24 ( V_4 , V_39 ) ;
}
if ( ! V_2 -> V_38 ) {
F_18 ( L_10 ) ;
return;
}
V_2 -> V_40 = V_4 ;
memcpy ( V_2 -> V_38 , & V_3 -> V_9 [ V_5 ] , V_4 - V_5 ) ;
memcpy ( V_2 -> V_38 + V_4 - V_5 , & V_3 -> V_9 [ 0 ] , V_5 ) ;
}
int T_2 F_25 ( struct V_1 * V_2 ,
const void * V_37 , unsigned int V_17 )
{
int V_41 ;
int V_42 = V_17 ;
T_1 V_5 ;
if ( F_5 ( V_42 > V_2 -> F_1 ) ) {
V_37 += V_42 - V_2 -> F_1 ;
V_42 = V_2 -> F_1 ;
}
F_7 ( V_2 , V_42 ) ;
V_5 = F_4 ( V_2 , V_42 ) ;
V_41 = V_2 -> F_1 - V_5 ;
if ( F_5 ( V_41 < V_42 ) ) {
F_22 ( V_2 , V_37 , V_5 , V_41 ) ;
V_37 += V_41 ;
V_42 -= V_41 ;
V_5 = 0 ;
}
F_22 ( V_2 , V_37 , V_5 , V_42 ) ;
F_13 ( V_2 ) ;
return V_17 ;
}
T_1 F_26 ( struct V_1 * V_2 )
{
return V_2 -> V_40 ;
}
void * F_27 ( struct V_1 * V_2 )
{
return V_2 -> V_38 ;
}
void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
V_2 -> V_40 = 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_3 -> V_5 , 0 ) ;
F_31 ( & V_2 -> V_3 -> V_4 , 0 ) ;
F_13 ( V_2 ) ;
}
static void * F_32 ( T_6 V_5 , T_1 V_4 )
{
struct V_43 * * V_44 ;
T_6 V_45 ;
unsigned int V_46 ;
T_7 V_47 ;
unsigned int V_12 ;
void * V_48 ;
V_45 = V_5 - F_33 ( V_5 ) ;
V_46 = F_17 ( V_4 + F_33 ( V_5 ) , V_49 ) ;
V_47 = F_34 ( V_50 ) ;
V_44 = F_24 ( sizeof( struct V_43 * ) * V_46 , V_39 ) ;
if ( ! V_44 ) {
F_18 ( L_11 , V_33 ,
V_46 ) ;
return NULL ;
}
for ( V_12 = 0 ; V_12 < V_46 ; V_12 ++ ) {
T_6 V_51 = V_45 + V_12 * V_49 ;
V_44 [ V_12 ] = F_35 ( V_51 >> V_52 ) ;
}
V_48 = F_36 ( V_44 , V_46 , V_53 , V_47 ) ;
F_29 ( V_44 ) ;
return V_48 ;
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
V_2 -> V_54 = V_5 ;
V_2 -> V_4 = V_4 ;
if ( F_41 ( V_5 >> V_52 ) )
V_2 -> V_48 = F_32 ( V_5 , V_4 ) ;
else
V_2 -> V_48 = F_37 ( V_5 , V_4 ) ;
if ( ! V_2 -> V_48 ) {
F_18 ( L_14 , V_33 ,
( unsigned long long ) V_4 , ( unsigned long long ) V_5 ) ;
return - V_55 ;
}
V_2 -> V_3 = V_2 -> V_48 + F_33 ( V_5 ) ;
V_2 -> F_1 = V_4 - sizeof( struct V_18 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , T_8 V_56 ,
struct V_28 * V_14 )
{
int V_36 ;
V_36 = F_16 ( V_2 , V_14 ) ;
if ( V_36 )
return V_36 ;
V_56 ^= V_57 ;
if ( V_2 -> V_3 -> V_56 == V_56 ) {
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
L_19 , V_2 -> V_3 -> V_56 ) ;
}
V_2 -> V_3 -> V_56 = V_56 ;
F_30 ( V_2 ) ;
return 0 ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_48 ) {
if ( F_41 ( V_2 -> V_54 >> V_52 ) ) {
F_45 ( V_2 -> V_48 ) ;
} else {
F_46 ( V_2 -> V_48 ) ;
F_47 ( V_2 -> V_54 , V_2 -> V_4 ) ;
}
V_2 -> V_48 = NULL ;
}
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
}
struct V_1 * F_48 ( T_6 V_5 , T_1 V_4 ,
T_8 V_56 , struct V_28 * V_14 )
{
struct V_1 * V_2 ;
int V_36 = - V_55 ;
V_2 = F_49 ( sizeof( struct V_1 ) , V_39 ) ;
if ( ! V_2 ) {
F_18 ( L_20 ) ;
goto V_58;
}
V_36 = F_40 ( V_5 , V_4 , V_2 ) ;
if ( V_36 )
goto V_58;
V_36 = F_42 ( V_2 , V_56 , V_14 ) ;
if ( V_36 )
goto V_58;
return V_2 ;
V_58:
F_44 ( V_2 ) ;
return F_50 ( V_36 ) ;
}
