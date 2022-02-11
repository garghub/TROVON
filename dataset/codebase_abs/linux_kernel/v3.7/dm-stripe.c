static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
F_1 ) ;
F_3 ( V_4 -> V_5 -> V_6 ) ;
}
static inline struct V_3 * F_4 ( unsigned int V_7 )
{
T_1 V_8 ;
if ( F_5 ( sizeof( struct V_3 ) , sizeof( struct V_9 ) ,
V_7 ) )
return NULL ;
V_8 = sizeof( struct V_3 ) + ( sizeof( struct V_9 ) * V_7 ) ;
return F_6 ( V_8 , V_10 ) ;
}
static int F_7 ( struct V_11 * V_5 , struct V_3 * V_4 ,
unsigned int V_9 , char * * V_12 )
{
unsigned long long V_13 ;
char V_14 ;
if ( sscanf ( V_12 [ 1 ] , L_1 , & V_13 , & V_14 ) != 1 )
return - V_15 ;
if ( F_8 ( V_5 , V_12 [ 0 ] , F_9 ( V_5 -> V_6 ) ,
& V_4 -> V_9 [ V_9 ] . V_16 ) )
return - V_17 ;
V_4 -> V_9 [ V_9 ] . V_18 = V_13 ;
return 0 ;
}
static int F_10 ( struct V_11 * V_5 , unsigned int V_19 , char * * V_12 )
{
struct V_3 * V_4 ;
T_2 V_20 ;
T_3 V_7 ;
T_3 V_21 ;
int V_22 ;
unsigned int V_23 ;
if ( V_19 < 2 ) {
V_5 -> error = L_2 ;
return - V_15 ;
}
if ( F_11 ( V_12 [ 0 ] , 10 , & V_7 ) || ! V_7 ) {
V_5 -> error = L_3 ;
return - V_15 ;
}
if ( F_11 ( V_12 [ 1 ] , 10 , & V_21 ) || ! V_21 ) {
V_5 -> error = L_4 ;
return - V_15 ;
}
V_20 = V_5 -> V_8 ;
if ( F_12 ( V_20 , V_21 ) ) {
V_5 -> error = L_5
L_6 ;
return - V_15 ;
}
if ( F_12 ( V_20 , V_7 ) ) {
V_5 -> error = L_5
L_7 ;
return - V_15 ;
}
if ( V_19 != ( 2 + 2 * V_7 ) ) {
V_5 -> error = L_8
L_9 ;
return - V_15 ;
}
V_4 = F_4 ( V_7 ) ;
if ( ! V_4 ) {
V_5 -> error = L_10
L_11 ;
return - V_24 ;
}
F_13 ( & V_4 -> F_1 , F_1 ) ;
V_4 -> V_5 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_25 = V_20 ;
if ( V_7 & ( V_7 - 1 ) )
V_4 -> V_26 = - 1 ;
else
V_4 -> V_26 = F_14 ( V_7 ) ;
V_22 = F_15 ( V_5 , V_21 ) ;
if ( V_22 )
return V_22 ;
V_5 -> V_27 = V_7 ;
V_5 -> V_28 = V_7 ;
V_4 -> V_21 = V_21 ;
if ( V_21 & ( V_21 - 1 ) )
V_4 -> V_29 = - 1 ;
else
V_4 -> V_29 = F_14 ( V_21 ) ;
for ( V_23 = 0 ; V_23 < V_7 ; V_23 ++ ) {
V_12 += 2 ;
V_22 = F_7 ( V_5 , V_4 , V_23 , V_12 ) ;
if ( V_22 < 0 ) {
V_5 -> error = L_12 ;
while ( V_23 -- )
F_16 ( V_5 , V_4 -> V_9 [ V_23 ] . V_16 ) ;
F_17 ( V_4 ) ;
return V_22 ;
}
F_18 ( & ( V_4 -> V_9 [ V_23 ] . V_30 ) , 0 ) ;
}
V_5 -> V_31 = V_4 ;
return 0 ;
}
static void F_19 ( struct V_11 * V_5 )
{
unsigned int V_23 ;
struct V_3 * V_4 = (struct V_3 * ) V_5 -> V_31 ;
for ( V_23 = 0 ; V_23 < V_4 -> V_7 ; V_23 ++ )
F_16 ( V_5 , V_4 -> V_9 [ V_23 ] . V_16 ) ;
F_20 ( & V_4 -> F_1 ) ;
F_17 ( V_4 ) ;
}
static void F_21 ( struct V_3 * V_4 , T_2 V_32 ,
T_3 * V_9 , T_2 * V_33 )
{
T_2 V_34 = F_22 ( V_4 -> V_5 , V_32 ) ;
T_2 V_35 ;
if ( V_4 -> V_29 < 0 )
V_35 = F_12 ( V_34 , V_4 -> V_21 ) ;
else {
V_35 = V_34 & ( V_4 -> V_21 - 1 ) ;
V_34 >>= V_4 -> V_29 ;
}
if ( V_4 -> V_26 < 0 )
* V_9 = F_12 ( V_34 , V_4 -> V_7 ) ;
else {
* V_9 = V_34 & ( V_4 -> V_7 - 1 ) ;
V_34 >>= V_4 -> V_26 ;
}
if ( V_4 -> V_29 < 0 )
V_34 *= V_4 -> V_21 ;
else
V_34 <<= V_4 -> V_29 ;
* V_33 = V_34 + V_35 ;
}
static void F_23 ( struct V_3 * V_4 , T_2 V_32 ,
T_3 V_36 , T_2 * V_33 )
{
T_3 V_9 ;
F_21 ( V_4 , V_32 , & V_9 , V_33 ) ;
if ( V_9 == V_36 )
return;
V_32 = * V_33 ;
if ( V_4 -> V_29 < 0 )
* V_33 -= F_12 ( V_32 , V_4 -> V_21 ) ;
else
* V_33 = V_32 & ~ ( T_2 ) ( V_4 -> V_21 - 1 ) ;
if ( V_36 < V_9 )
* V_33 += V_4 -> V_21 ;
}
static int F_24 ( struct V_3 * V_4 , struct V_37 * V_37 ,
T_3 V_36 )
{
T_2 V_38 , V_39 ;
F_23 ( V_4 , V_37 -> V_40 , V_36 , & V_38 ) ;
F_23 ( V_4 , V_37 -> V_40 + F_25 ( V_37 ) ,
V_36 , & V_39 ) ;
if ( V_38 < V_39 ) {
V_37 -> V_41 = V_4 -> V_9 [ V_36 ] . V_16 -> V_42 ;
V_37 -> V_40 = V_38 + V_4 -> V_9 [ V_36 ] . V_18 ;
V_37 -> V_43 = F_26 ( V_39 - V_38 ) ;
return V_44 ;
} else {
F_27 ( V_37 , 0 ) ;
return V_45 ;
}
}
static int F_28 ( struct V_11 * V_5 , struct V_37 * V_37 ,
union V_46 * V_47 )
{
struct V_3 * V_4 = V_5 -> V_31 ;
T_3 V_9 ;
unsigned V_48 ;
if ( V_37 -> V_49 & V_50 ) {
V_48 = V_47 -> V_48 ;
F_29 ( V_48 >= V_4 -> V_7 ) ;
V_37 -> V_41 = V_4 -> V_9 [ V_48 ] . V_16 -> V_42 ;
return V_44 ;
}
if ( F_30 ( V_37 -> V_49 & V_51 ) ) {
V_48 = V_47 -> V_48 ;
F_29 ( V_48 >= V_4 -> V_7 ) ;
return F_24 ( V_4 , V_37 , V_48 ) ;
}
F_21 ( V_4 , V_37 -> V_40 , & V_9 , & V_37 -> V_40 ) ;
V_37 -> V_40 += V_4 -> V_9 [ V_9 ] . V_18 ;
V_37 -> V_41 = V_4 -> V_9 [ V_9 ] . V_16 -> V_42 ;
return V_44 ;
}
static int F_31 ( struct V_11 * V_5 , T_4 type ,
unsigned V_52 , char * V_33 , unsigned V_53 )
{
struct V_3 * V_4 = (struct V_3 * ) V_5 -> V_31 ;
char V_54 [ V_4 -> V_7 + 1 ] ;
unsigned int V_55 = 0 ;
unsigned int V_23 ;
switch ( type ) {
case V_56 :
F_32 ( L_13 , V_4 -> V_7 ) ;
for ( V_23 = 0 ; V_23 < V_4 -> V_7 ; V_23 ++ ) {
F_32 ( L_14 , V_4 -> V_9 [ V_23 ] . V_16 -> V_57 ) ;
V_54 [ V_23 ] = F_33 ( & ( V_4 -> V_9 [ V_23 ] . V_30 ) ) ?
'D' : 'A' ;
}
V_54 [ V_23 ] = '\0' ;
F_32 ( L_15 , V_54 ) ;
break;
case V_58 :
F_32 ( L_16 , V_4 -> V_7 ,
( unsigned long long ) V_4 -> V_21 ) ;
for ( V_23 = 0 ; V_23 < V_4 -> V_7 ; V_23 ++ )
F_32 ( L_17 , V_4 -> V_9 [ V_23 ] . V_16 -> V_57 ,
( unsigned long long ) V_4 -> V_9 [ V_23 ] . V_18 ) ;
break;
}
return 0 ;
}
static int F_34 ( struct V_11 * V_5 , struct V_37 * V_37 ,
int error , union V_46 * V_47 )
{
unsigned V_23 ;
char V_59 [ 16 ] ;
struct V_3 * V_4 = V_5 -> V_31 ;
if ( ! error )
return 0 ;
if ( ( error == - V_60 ) && ( V_37 -> V_49 & V_61 ) )
return error ;
if ( error == - V_62 )
return error ;
memset ( V_59 , 0 , sizeof( V_59 ) ) ;
sprintf ( V_59 , L_18 ,
F_35 ( F_36 ( V_37 -> V_41 -> V_63 ) ) ,
F_37 ( F_36 ( V_37 -> V_41 -> V_63 ) ) ) ;
for ( V_23 = 0 ; V_23 < V_4 -> V_7 ; V_23 ++ )
if ( ! strcmp ( V_4 -> V_9 [ V_23 ] . V_16 -> V_57 , V_59 ) ) {
F_38 ( & ( V_4 -> V_9 [ V_23 ] . V_30 ) ) ;
if ( F_33 ( & ( V_4 -> V_9 [ V_23 ] . V_30 ) ) <
V_64 )
F_39 ( & V_4 -> F_1 ) ;
}
return error ;
}
static int F_40 ( struct V_11 * V_5 ,
T_5 V_65 , void * V_66 )
{
struct V_3 * V_4 = V_5 -> V_31 ;
int V_67 = 0 ;
unsigned V_23 = 0 ;
do {
V_67 = V_65 ( V_5 , V_4 -> V_9 [ V_23 ] . V_16 ,
V_4 -> V_9 [ V_23 ] . V_18 ,
V_4 -> V_25 , V_66 ) ;
} while ( ! V_67 && ++ V_23 < V_4 -> V_7 );
return V_67 ;
}
static void F_41 ( struct V_11 * V_5 ,
struct V_68 * V_69 )
{
struct V_3 * V_4 = V_5 -> V_31 ;
unsigned V_21 = V_4 -> V_21 << V_70 ;
F_42 ( V_69 , V_21 ) ;
F_43 ( V_69 , V_21 * V_4 -> V_7 ) ;
}
static int F_44 ( struct V_11 * V_5 , struct V_71 * V_72 ,
struct V_73 * V_74 , int V_75 )
{
struct V_3 * V_4 = V_5 -> V_31 ;
T_2 V_76 = V_72 -> V_40 ;
T_3 V_9 ;
struct V_77 * V_78 ;
F_21 ( V_4 , V_76 , & V_9 , & V_76 ) ;
V_78 = F_45 ( V_4 -> V_9 [ V_9 ] . V_16 -> V_42 ) ;
if ( ! V_78 -> V_79 )
return V_75 ;
V_72 -> V_41 = V_4 -> V_9 [ V_9 ] . V_16 -> V_42 ;
V_72 -> V_40 = V_4 -> V_9 [ V_9 ] . V_18 + V_76 ;
return F_46 ( V_75 , V_78 -> V_79 ( V_78 , V_72 , V_74 ) ) ;
}
int T_6 F_47 ( void )
{
int V_22 ;
V_22 = F_48 ( & V_80 ) ;
if ( V_22 < 0 ) {
F_49 ( L_19 ) ;
return V_22 ;
}
return V_22 ;
}
void F_50 ( void )
{
F_51 ( & V_80 ) ;
}
