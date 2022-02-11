static inline T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 -> V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 -> V_5 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_1 V_6 )
{
int V_7 ;
int V_8 ;
unsigned long V_9 ;
F_5 ( & V_10 , V_9 ) ;
V_7 = F_2 ( & V_2 -> V_3 -> V_5 ) ;
V_8 = V_7 + V_6 ;
while ( F_6 ( V_8 >= V_2 -> F_1 ) )
V_8 -= V_2 -> F_1 ;
F_7 ( & V_2 -> V_3 -> V_5 , V_8 ) ;
F_8 ( & V_10 , V_9 ) ;
return V_7 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_6 )
{
T_1 V_7 ;
T_1 V_8 ;
unsigned long V_9 ;
F_5 ( & V_10 , V_9 ) ;
V_7 = F_2 ( & V_2 -> V_3 -> V_4 ) ;
if ( V_7 == V_2 -> F_1 )
goto exit;
V_8 = V_7 + V_6 ;
if ( V_8 > V_2 -> F_1 )
V_8 = V_2 -> F_1 ;
F_7 ( & V_2 -> V_3 -> V_4 , V_8 ) ;
exit:
F_8 ( & V_10 , V_9 ) ;
}
static void T_2 F_10 ( struct V_1 * V_2 ,
T_3 * V_11 , T_1 V_12 , T_3 * V_13 )
{
int V_14 ;
T_4 V_15 [ V_2 -> V_16 . V_17 ] ;
memset ( V_15 , 0 , sizeof( V_15 ) ) ;
F_11 ( V_2 -> V_18 , V_11 , V_12 , V_15 , 0 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_17 ; V_14 ++ )
V_13 [ V_14 ] = V_15 [ V_14 ] ;
}
static int F_12 ( struct V_1 * V_2 ,
void * V_11 , T_1 V_12 , T_3 * V_13 )
{
int V_14 ;
T_4 V_15 [ V_2 -> V_16 . V_17 ] ;
for ( V_14 = 0 ; V_14 < V_2 -> V_16 . V_17 ; V_14 ++ )
V_15 [ V_14 ] = V_13 [ V_14 ] ;
return F_13 ( V_2 -> V_18 , V_11 , V_15 , V_12 ,
NULL , 0 , NULL , 0 , NULL ) ;
}
static void T_2 F_14 ( struct V_1 * V_2 ,
unsigned int V_5 , unsigned int V_19 )
{
struct V_20 * V_3 = V_2 -> V_3 ;
T_3 * V_21 = V_3 -> V_11 + V_2 -> F_1 ;
T_3 * V_22 ;
T_3 * V_15 ;
int V_23 = V_2 -> V_16 . V_24 ;
int V_17 = V_2 -> V_16 . V_17 ;
int V_4 = V_23 ;
if ( ! V_17 )
return;
V_22 = V_3 -> V_11 + ( V_5 & ~ ( V_23 - 1 ) ) ;
V_15 = V_2 -> V_25 + ( V_5 / V_23 ) * V_17 ;
do {
if ( V_22 + V_23 > V_21 )
V_4 = V_21 - V_22 ;
F_10 ( V_2 , V_22 , V_4 , V_15 ) ;
V_22 += V_23 ;
V_15 += V_17 ;
} while ( V_22 < V_3 -> V_11 + V_5 + V_19 );
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_20 * V_3 = V_2 -> V_3 ;
if ( ! V_2 -> V_16 . V_17 )
return;
F_10 ( V_2 , ( T_3 * ) V_3 , sizeof( * V_3 ) ,
V_2 -> V_26 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_20 * V_3 = V_2 -> V_3 ;
T_3 * V_22 ;
T_3 * V_15 ;
if ( ! V_2 -> V_16 . V_17 )
return;
V_22 = V_3 -> V_11 ;
V_15 = V_2 -> V_25 ;
while ( V_22 < V_3 -> V_11 + F_1 ( V_2 ) ) {
int V_27 ;
int V_4 = V_2 -> V_16 . V_24 ;
if ( V_22 + V_4 > V_3 -> V_11 + V_2 -> F_1 )
V_4 = V_3 -> V_11 + V_2 -> F_1 - V_22 ;
V_27 = F_12 ( V_2 , V_22 , V_4 , V_15 ) ;
if ( V_27 > 0 ) {
F_17 ( L_1 , V_22 , V_27 ) ;
V_2 -> V_28 += V_27 ;
} else if ( V_27 < 0 ) {
F_17 ( L_2 , V_22 ) ;
V_2 -> V_29 ++ ;
}
V_22 += V_2 -> V_16 . V_24 ;
V_15 += V_2 -> V_16 . V_17 ;
}
}
static int F_18 ( struct V_1 * V_2 ,
struct V_30 * V_16 )
{
int V_27 ;
struct V_20 * V_3 = V_2 -> V_3 ;
int V_31 ;
T_1 V_32 ;
if ( ! V_16 || ! V_16 -> V_17 )
return 0 ;
V_2 -> V_16 . V_24 = V_16 -> V_24 ? : 128 ;
V_2 -> V_16 . V_17 = V_16 -> V_17 ? : 16 ;
V_2 -> V_16 . V_33 = V_16 -> V_33 ? : 8 ;
V_2 -> V_16 . V_34 = V_16 -> V_34 ? : 0x11d ;
V_31 = F_19 ( V_2 -> F_1 - V_2 -> V_16 . V_17 ,
V_2 -> V_16 . V_24 +
V_2 -> V_16 . V_17 ) ;
V_32 = ( V_31 + 1 ) * V_2 -> V_16 . V_17 ;
if ( V_32 >= V_2 -> F_1 ) {
F_20 ( L_3 ,
V_35 , V_2 -> V_16 . V_17 ,
V_32 , V_2 -> F_1 ) ;
return - V_36 ;
}
V_2 -> F_1 -= V_32 ;
V_2 -> V_25 = V_3 -> V_11 + V_2 -> F_1 ;
V_2 -> V_26 = V_2 -> V_25 +
V_31 * V_2 -> V_16 . V_17 ;
V_2 -> V_18 = F_21 ( V_2 -> V_16 . V_33 , V_2 -> V_16 . V_34 ,
0 , 1 , V_2 -> V_16 . V_17 ) ;
if ( V_2 -> V_18 == NULL ) {
F_22 ( L_4 ) ;
return - V_36 ;
}
V_2 -> V_28 = 0 ;
V_2 -> V_29 = 0 ;
V_27 = F_12 ( V_2 , V_3 , sizeof( * V_3 ) ,
V_2 -> V_26 ) ;
if ( V_27 > 0 ) {
F_22 ( L_5 , V_27 ) ;
V_2 -> V_28 += V_27 ;
} else if ( V_27 < 0 ) {
F_22 ( L_6 ) ;
V_2 -> V_29 ++ ;
}
return 0 ;
}
T_5 F_23 ( struct V_1 * V_2 ,
char * V_37 , T_1 V_12 )
{
T_5 V_38 ;
if ( ! V_2 -> V_16 . V_17 )
return 0 ;
if ( V_2 -> V_28 || V_2 -> V_29 )
V_38 = snprintf ( V_37 , V_12 , L_7
L_8 ,
V_2 -> V_28 , V_2 -> V_29 ) ;
else
V_38 = snprintf ( V_37 , V_12 , L_9 ) ;
return V_38 ;
}
static void T_2 F_24 ( struct V_1 * V_2 ,
const void * V_39 , unsigned int V_5 , unsigned int V_19 )
{
struct V_20 * V_3 = V_2 -> V_3 ;
F_25 ( V_3 -> V_11 + V_5 , V_39 , V_19 ) ;
F_14 ( V_2 , V_5 , V_19 ) ;
}
static int T_2 F_26 ( struct V_1 * V_2 ,
const void T_6 * V_39 , unsigned int V_5 , unsigned int V_19 )
{
struct V_20 * V_3 = V_2 -> V_3 ;
int V_38 = F_6 ( F_27 ( V_3 -> V_11 + V_5 , V_39 , V_19 ) ) ?
- V_40 : 0 ;
F_14 ( V_2 , V_5 , V_19 ) ;
return V_38 ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_20 * V_3 = V_2 -> V_3 ;
T_1 V_4 = F_1 ( V_2 ) ;
T_1 V_5 = F_3 ( V_2 ) ;
if ( ! V_4 )
return;
if ( ! V_2 -> V_41 ) {
F_16 ( V_2 ) ;
V_2 -> V_41 = F_29 ( V_4 , V_42 ) ;
}
if ( ! V_2 -> V_41 ) {
F_20 ( L_10 ) ;
return;
}
V_2 -> V_43 = V_4 ;
F_30 ( V_2 -> V_41 , & V_3 -> V_11 [ V_5 ] , V_4 - V_5 ) ;
F_30 ( V_2 -> V_41 + V_4 - V_5 , & V_3 -> V_11 [ 0 ] , V_5 ) ;
}
int T_2 F_31 ( struct V_1 * V_2 ,
const void * V_39 , unsigned int V_19 )
{
int V_44 ;
int V_45 = V_19 ;
T_1 V_5 ;
if ( F_6 ( V_45 > V_2 -> F_1 ) ) {
V_39 += V_45 - V_2 -> F_1 ;
V_45 = V_2 -> F_1 ;
}
F_9 ( V_2 , V_45 ) ;
V_5 = F_4 ( V_2 , V_45 ) ;
V_44 = V_2 -> F_1 - V_5 ;
if ( F_6 ( V_44 < V_45 ) ) {
F_24 ( V_2 , V_39 , V_5 , V_44 ) ;
V_39 += V_44 ;
V_45 -= V_44 ;
V_5 = 0 ;
}
F_24 ( V_2 , V_39 , V_5 , V_45 ) ;
F_15 ( V_2 ) ;
return V_19 ;
}
int T_2 F_32 ( struct V_1 * V_2 ,
const void T_6 * V_39 , unsigned int V_19 )
{
int V_44 , V_38 = 0 , V_45 = V_19 ;
T_1 V_5 ;
if ( F_6 ( ! F_33 ( V_46 , V_39 , V_19 ) ) )
return - V_40 ;
if ( F_6 ( V_45 > V_2 -> F_1 ) ) {
V_39 += V_45 - V_2 -> F_1 ;
V_45 = V_2 -> F_1 ;
}
F_9 ( V_2 , V_45 ) ;
V_5 = F_4 ( V_2 , V_45 ) ;
V_44 = V_2 -> F_1 - V_5 ;
if ( F_6 ( V_44 < V_45 ) ) {
V_38 = F_26 ( V_2 , V_39 , V_5 , V_44 ) ;
V_39 += V_44 ;
V_45 -= V_44 ;
V_5 = 0 ;
}
if ( F_34 ( ! V_38 ) )
V_38 = F_26 ( V_2 , V_39 , V_5 , V_45 ) ;
F_15 ( V_2 ) ;
return F_6 ( V_38 ) ? V_38 : V_19 ;
}
T_1 F_35 ( struct V_1 * V_2 )
{
return V_2 -> V_43 ;
}
void * F_36 ( struct V_1 * V_2 )
{
return V_2 -> V_41 ;
}
void F_37 ( struct V_1 * V_2 )
{
F_38 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
V_2 -> V_43 = 0 ;
}
void F_39 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_3 -> V_5 , 0 ) ;
F_7 ( & V_2 -> V_3 -> V_4 , 0 ) ;
F_15 ( V_2 ) ;
}
static void * F_40 ( T_7 V_5 , T_1 V_4 ,
unsigned int V_47 )
{
struct V_48 * * V_49 ;
T_7 V_50 ;
unsigned int V_51 ;
T_8 V_52 ;
unsigned int V_14 ;
void * V_53 ;
V_50 = V_5 - F_41 ( V_5 ) ;
V_51 = F_19 ( V_4 + F_41 ( V_5 ) , V_54 ) ;
if ( V_47 )
V_52 = F_42 ( V_55 ) ;
else
V_52 = F_43 ( V_55 ) ;
V_49 = F_44 ( V_51 , sizeof( struct V_48 * ) , V_42 ) ;
if ( ! V_49 ) {
F_20 ( L_11 ,
V_35 , V_51 ) ;
return NULL ;
}
for ( V_14 = 0 ; V_14 < V_51 ; V_14 ++ ) {
T_7 V_56 = V_50 + V_14 * V_54 ;
V_49 [ V_14 ] = F_45 ( V_56 >> V_57 ) ;
}
V_53 = F_46 ( V_49 , V_51 , V_58 , V_52 ) ;
F_38 ( V_49 ) ;
return V_53 ;
}
static void * F_47 ( T_7 V_5 , T_1 V_4 ,
unsigned int V_47 )
{
void * V_59 ;
if ( ! F_48 ( V_5 , V_4 , L_12 ) ) {
F_20 ( L_13 ,
( unsigned long long ) V_4 , ( unsigned long long ) V_5 ) ;
return NULL ;
}
if ( V_47 )
V_59 = F_49 ( V_5 , V_4 ) ;
else
V_59 = F_50 ( V_5 , V_4 ) ;
return V_59 ;
}
static int F_51 ( T_7 V_5 , T_7 V_4 ,
struct V_1 * V_2 , int V_47 )
{
V_2 -> V_60 = V_5 ;
V_2 -> V_4 = V_4 ;
if ( F_52 ( V_5 >> V_57 ) )
V_2 -> V_53 = F_40 ( V_5 , V_4 , V_47 ) ;
else
V_2 -> V_53 = F_47 ( V_5 , V_4 , V_47 ) ;
if ( ! V_2 -> V_53 ) {
F_20 ( L_14 , V_35 ,
( unsigned long long ) V_4 , ( unsigned long long ) V_5 ) ;
return - V_61 ;
}
V_2 -> V_3 = V_2 -> V_53 + F_41 ( V_5 ) ;
V_2 -> F_1 = V_4 - sizeof( struct V_20 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , T_9 V_62 ,
struct V_30 * V_16 )
{
int V_38 ;
V_38 = F_18 ( V_2 , V_16 ) ;
if ( V_38 )
return V_38 ;
V_62 ^= V_63 ;
if ( V_2 -> V_3 -> V_62 == V_62 ) {
if ( F_1 ( V_2 ) > V_2 -> F_1 ||
F_3 ( V_2 ) > F_1 ( V_2 ) )
F_22 ( L_15 ,
F_1 ( V_2 ) , F_3 ( V_2 ) ) ;
else {
F_54 ( L_16 ,
F_1 ( V_2 ) , F_3 ( V_2 ) ) ;
F_28 ( V_2 ) ;
return 0 ;
}
} else {
F_54 ( L_17 ,
V_2 -> V_3 -> V_62 ) ;
}
V_2 -> V_3 -> V_62 = V_62 ;
F_39 ( V_2 ) ;
return 0 ;
}
void F_55 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_53 ) {
if ( F_52 ( V_2 -> V_60 >> V_57 ) ) {
F_56 ( V_2 -> V_53 ) ;
} else {
F_57 ( V_2 -> V_53 ) ;
F_58 ( V_2 -> V_60 , V_2 -> V_4 ) ;
}
V_2 -> V_53 = NULL ;
}
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
}
struct V_1 * F_59 ( T_7 V_5 , T_1 V_4 ,
T_9 V_62 , struct V_30 * V_16 ,
unsigned int V_47 )
{
struct V_1 * V_2 ;
int V_38 = - V_61 ;
V_2 = F_60 ( sizeof( struct V_1 ) , V_42 ) ;
if ( ! V_2 ) {
F_20 ( L_18 ) ;
goto V_64;
}
V_38 = F_51 ( V_5 , V_4 , V_2 , V_47 ) ;
if ( V_38 )
goto V_64;
V_38 = F_53 ( V_2 , V_62 , V_16 ) ;
if ( V_38 )
goto V_64;
return V_2 ;
V_64:
F_55 ( V_2 ) ;
return F_61 ( V_38 ) ;
}
