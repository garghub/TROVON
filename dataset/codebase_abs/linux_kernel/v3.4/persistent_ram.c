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
static inline T_2 F_8 ( struct V_1 * V_2 ,
T_1 V_6 )
{
T_1 V_7 ;
T_1 V_8 ;
do {
V_7 = F_2 ( & V_2 -> V_3 -> V_4 ) ;
V_8 = V_7 + V_6 ;
if ( V_8 > V_2 -> F_1 )
return - V_9 ;
} while ( F_6 ( & V_2 -> V_3 -> V_4 , V_7 , V_8 ) != V_7 );
return 0 ;
}
static void T_3 F_9 ( struct V_1 * V_2 ,
T_4 * V_10 , T_1 V_11 , T_4 * V_12 )
{
int V_13 ;
T_5 V_14 [ V_2 -> V_15 ] ;
memset ( V_14 , 0 , sizeof( V_14 ) ) ;
F_10 ( V_2 -> V_16 , V_10 , V_11 , V_14 , 0 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_15 ; V_13 ++ )
V_12 [ V_13 ] = V_14 [ V_13 ] ;
}
static int F_11 ( struct V_1 * V_2 ,
void * V_10 , T_1 V_11 , T_4 * V_12 )
{
int V_13 ;
T_5 V_14 [ V_2 -> V_15 ] ;
for ( V_13 = 0 ; V_13 < V_2 -> V_15 ; V_13 ++ )
V_14 [ V_13 ] = V_12 [ V_13 ] ;
return F_12 ( V_2 -> V_16 , V_10 , V_14 , V_11 ,
NULL , 0 , NULL , 0 , NULL ) ;
}
static void T_3 F_13 ( struct V_1 * V_2 ,
unsigned int V_5 , unsigned int V_17 )
{
struct V_18 * V_3 = V_2 -> V_3 ;
T_4 * V_19 = V_3 -> V_10 + V_2 -> F_1 ;
T_4 * V_20 ;
T_4 * V_14 ;
int V_21 = V_2 -> V_21 ;
int V_15 = V_2 -> V_15 ;
int V_4 = V_2 -> V_21 ;
if ( ! V_2 -> V_12 )
return;
V_20 = V_3 -> V_10 + ( V_5 & ~ ( V_21 - 1 ) ) ;
V_14 = V_2 -> V_22 + ( V_5 / V_21 ) * V_2 -> V_15 ;
do {
if ( V_20 + V_21 > V_19 )
V_4 = V_19 - V_20 ;
F_9 ( V_2 , V_20 , V_4 , V_14 ) ;
V_20 += V_21 ;
V_14 += V_15 ;
} while ( V_20 < V_3 -> V_10 + V_5 + V_17 );
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_18 * V_3 = V_2 -> V_3 ;
if ( ! V_2 -> V_12 )
return;
F_9 ( V_2 , ( T_4 * ) V_3 , sizeof( * V_3 ) ,
V_2 -> V_23 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_18 * V_3 = V_2 -> V_3 ;
T_4 * V_20 ;
T_4 * V_14 ;
if ( ! V_2 -> V_12 )
return;
V_20 = V_3 -> V_10 ;
V_14 = V_2 -> V_22 ;
while ( V_20 < V_3 -> V_10 + F_1 ( V_2 ) ) {
int V_24 ;
int V_4 = V_2 -> V_21 ;
if ( V_20 + V_4 > V_3 -> V_10 + V_2 -> F_1 )
V_4 = V_3 -> V_10 + V_2 -> F_1 - V_20 ;
V_24 = F_11 ( V_2 , V_20 , V_4 , V_14 ) ;
if ( V_24 > 0 ) {
F_16 ( L_1 ,
V_20 , V_24 ) ;
V_2 -> V_25 += V_24 ;
} else if ( V_24 < 0 ) {
F_16 ( L_2 ,
V_20 ) ;
V_2 -> V_26 ++ ;
}
V_20 += V_2 -> V_21 ;
V_14 += V_2 -> V_15 ;
}
}
static int F_17 ( struct V_1 * V_2 ,
T_1 F_1 )
{
int V_24 ;
struct V_18 * V_3 = V_2 -> V_3 ;
int V_27 ;
if ( ! V_2 -> V_12 )
return 0 ;
V_2 -> V_21 = 128 ;
V_2 -> V_15 = 16 ;
V_2 -> V_28 = 8 ;
V_2 -> V_29 = 0x11d ;
V_27 = F_18 ( V_2 -> F_1 , V_2 -> V_21 ) ;
V_2 -> F_1 -= ( V_27 + 1 ) * V_2 -> V_15 ;
if ( V_2 -> F_1 > F_1 ) {
F_19 ( L_3 ,
F_1 , V_2 -> F_1 ) ;
return - V_30 ;
}
V_2 -> V_22 = V_3 -> V_10 + V_2 -> F_1 ;
V_2 -> V_23 = V_2 -> V_22 + V_27 * V_2 -> V_15 ;
V_2 -> V_16 = F_20 ( V_2 -> V_28 , V_2 -> V_29 , 0 , 1 ,
V_2 -> V_15 ) ;
if ( V_2 -> V_16 == NULL ) {
F_21 ( L_4 ) ;
return - V_30 ;
}
V_2 -> V_25 = 0 ;
V_2 -> V_26 = 0 ;
V_24 = F_11 ( V_2 , V_3 , sizeof( * V_3 ) ,
V_2 -> V_23 ) ;
if ( V_24 > 0 ) {
F_21 ( L_5 , V_24 ) ;
V_2 -> V_25 += V_24 ;
} else if ( V_24 < 0 ) {
F_21 ( L_6 ) ;
V_2 -> V_26 ++ ;
}
return 0 ;
}
T_2 F_22 ( struct V_1 * V_2 ,
char * V_31 , T_1 V_11 )
{
T_2 V_32 ;
if ( V_2 -> V_25 || V_2 -> V_26 )
V_32 = snprintf ( V_31 , V_11 , L_7
L_8 ,
V_2 -> V_25 , V_2 -> V_26 ) ;
else
V_32 = snprintf ( V_31 , V_11 , L_9 ) ;
return V_32 ;
}
static void T_3 F_23 ( struct V_1 * V_2 ,
const void * V_33 , unsigned int V_5 , unsigned int V_17 )
{
struct V_18 * V_3 = V_2 -> V_3 ;
memcpy ( V_3 -> V_10 + V_5 , V_33 , V_17 ) ;
F_13 ( V_2 , V_5 , V_17 ) ;
}
static void T_6
F_24 ( struct V_1 * V_2 )
{
struct V_18 * V_3 = V_2 -> V_3 ;
T_1 V_4 = F_1 ( V_2 ) ;
T_1 V_5 = F_3 ( V_2 ) ;
char * V_34 ;
F_15 ( V_2 ) ;
V_34 = F_25 ( V_4 , V_35 ) ;
if ( V_34 == NULL ) {
F_19 ( L_10 ) ;
return;
}
V_2 -> V_36 = V_34 ;
V_2 -> V_37 = V_4 ;
memcpy ( V_2 -> V_36 , & V_3 -> V_10 [ V_5 ] , V_4 - V_5 ) ;
memcpy ( V_2 -> V_36 + V_4 - V_5 , & V_3 -> V_10 [ 0 ] , V_5 ) ;
}
int T_3 F_26 ( struct V_1 * V_2 ,
const void * V_33 , unsigned int V_17 )
{
int V_38 ;
int V_39 = V_17 ;
T_1 V_5 ;
if ( F_5 ( V_39 > V_2 -> F_1 ) ) {
V_33 += V_39 - V_2 -> F_1 ;
V_39 = V_2 -> F_1 ;
}
F_8 ( V_2 , V_39 ) ;
V_5 = F_4 ( V_2 , V_39 ) ;
V_38 = V_2 -> F_1 - V_5 ;
if ( F_5 ( V_38 < V_39 ) ) {
F_23 ( V_2 , V_33 , V_5 , V_38 ) ;
V_33 += V_38 ;
V_39 -= V_38 ;
V_5 = 0 ;
}
F_23 ( V_2 , V_33 , V_5 , V_39 ) ;
F_14 ( V_2 ) ;
return V_17 ;
}
T_1 F_27 ( struct V_1 * V_2 )
{
return V_2 -> V_37 ;
}
void * F_28 ( struct V_1 * V_2 )
{
return V_2 -> V_36 ;
}
void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
V_2 -> V_37 = 0 ;
}
static int F_31 ( T_7 V_5 , T_7 V_4 ,
struct V_1 * V_2 )
{
struct V_40 * * V_41 ;
T_7 V_42 ;
unsigned int V_43 ;
T_8 V_44 ;
unsigned int V_13 ;
V_42 = V_5 - F_32 ( V_5 ) ;
V_43 = F_18 ( V_4 + F_32 ( V_5 ) , V_45 ) ;
V_44 = F_33 ( V_46 ) ;
V_41 = F_25 ( sizeof( struct V_40 * ) * V_43 , V_35 ) ;
if ( ! V_41 ) {
F_19 ( L_11 , V_47 ,
V_43 ) ;
return - V_9 ;
}
for ( V_13 = 0 ; V_13 < V_43 ; V_13 ++ ) {
T_7 V_48 = V_42 + V_13 * V_45 ;
V_41 [ V_13 ] = F_34 ( V_48 >> V_49 ) ;
}
V_2 -> V_50 = F_35 ( V_41 , V_43 , V_51 , V_44 ) ;
F_30 ( V_41 ) ;
if ( ! V_2 -> V_50 ) {
F_19 ( L_12 , V_47 , V_43 ) ;
return - V_9 ;
}
V_2 -> V_3 = V_2 -> V_50 + F_32 ( V_5 ) ;
V_2 -> F_1 = V_4 - sizeof( struct V_18 ) ;
return 0 ;
}
static int T_6 F_36 ( const char * V_52 ,
struct V_1 * V_2 )
{
int V_13 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
T_7 V_5 ;
F_37 (ram, &persistent_ram_list, node) {
V_5 = V_54 -> V_5 ;
for ( V_13 = 0 ; V_13 < V_54 -> V_57 ; V_13 ++ ) {
V_56 = & V_54 -> V_58 [ V_13 ] ;
if ( ! strcmp ( V_56 -> V_52 , V_52 ) )
return F_31 ( V_5 ,
V_56 -> V_4 , V_2 ) ;
V_5 += V_56 -> V_4 ;
}
}
return - V_30 ;
}
V_1 * T_6
F_38 ( struct V_59 * V_60 , bool V_12 )
{
return F_39 ( V_60 , V_12 ) ;
}
int T_6 F_40 ( struct V_53 * V_54 )
{
int V_32 ;
V_32 = F_41 ( V_54 -> V_5 , V_54 -> V_4 ) ;
if ( V_32 ) {
F_19 ( L_13 ,
( long ) V_54 -> V_5 , ( long ) ( V_54 -> V_5 + V_54 -> V_4 - 1 ) ) ;
return V_32 ;
}
F_42 ( & V_54 -> V_61 , & V_62 ) ;
F_21 ( L_14 ,
( long ) V_54 -> V_5 , ( long ) ( V_54 -> V_5 + V_54 -> V_4 - 1 ) ) ;
return 0 ;
}
