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
char * V_22 ;
int V_23 ;
unsigned int V_24 ;
if ( V_19 < 2 ) {
V_5 -> error = L_2 ;
return - V_15 ;
}
V_7 = F_11 ( V_12 [ 0 ] , & V_22 , 10 ) ;
if ( ! V_7 || * V_22 ) {
V_5 -> error = L_3 ;
return - V_15 ;
}
V_21 = F_11 ( V_12 [ 1 ] , & V_22 , 10 ) ;
if ( * V_22 ) {
V_5 -> error = L_4 ;
return - V_15 ;
}
if ( ! F_12 ( V_21 ) ||
( V_21 < ( V_25 >> V_26 ) ) ) {
V_5 -> error = L_5 ;
return - V_15 ;
}
if ( V_5 -> V_8 & ( V_21 - 1 ) ) {
V_5 -> error = L_6
L_7 ;
return - V_15 ;
}
V_20 = V_5 -> V_8 ;
if ( F_13 ( V_20 , V_7 ) ) {
V_5 -> error = L_6
L_8 ;
return - V_15 ;
}
if ( V_19 != ( 2 + 2 * V_7 ) ) {
V_5 -> error = L_9
L_10 ;
return - V_15 ;
}
V_4 = F_4 ( V_7 ) ;
if ( ! V_4 ) {
V_5 -> error = L_11
L_12 ;
return - V_27 ;
}
F_14 ( & V_4 -> F_1 , F_1 ) ;
V_4 -> V_5 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_28 = V_20 ;
if ( V_7 & ( V_7 - 1 ) )
V_4 -> V_29 = - 1 ;
else {
V_4 -> V_29 = F_15 ( V_7 ) - 1 ;
V_4 -> V_30 = ( ( T_2 ) V_7 ) - 1 ;
}
V_5 -> V_31 = V_21 ;
V_5 -> V_32 = V_7 ;
V_5 -> V_33 = V_7 ;
V_4 -> V_34 = F_15 ( V_21 ) - 1 ;
V_4 -> V_35 = ( ( T_2 ) V_21 ) - 1 ;
for ( V_24 = 0 ; V_24 < V_7 ; V_24 ++ ) {
V_12 += 2 ;
V_23 = F_7 ( V_5 , V_4 , V_24 , V_12 ) ;
if ( V_23 < 0 ) {
V_5 -> error = L_13 ;
while ( V_24 -- )
F_16 ( V_5 , V_4 -> V_9 [ V_24 ] . V_16 ) ;
F_17 ( V_4 ) ;
return V_23 ;
}
F_18 ( & ( V_4 -> V_9 [ V_24 ] . V_36 ) , 0 ) ;
}
V_5 -> V_37 = V_4 ;
return 0 ;
}
static void F_19 ( struct V_11 * V_5 )
{
unsigned int V_24 ;
struct V_3 * V_4 = (struct V_3 * ) V_5 -> V_37 ;
for ( V_24 = 0 ; V_24 < V_4 -> V_7 ; V_24 ++ )
F_16 ( V_5 , V_4 -> V_9 [ V_24 ] . V_16 ) ;
F_20 ( & V_4 -> F_1 ) ;
F_17 ( V_4 ) ;
}
static void F_21 ( struct V_3 * V_4 , T_2 V_38 ,
T_3 * V_9 , T_2 * V_39 )
{
T_2 V_40 = F_22 ( V_4 -> V_5 , V_38 ) ;
T_2 V_41 = V_40 >> V_4 -> V_34 ;
if ( V_4 -> V_29 < 0 )
* V_9 = F_13 ( V_41 , V_4 -> V_7 ) ;
else {
* V_9 = V_41 & V_4 -> V_30 ;
V_41 >>= V_4 -> V_29 ;
}
* V_39 = ( V_41 << V_4 -> V_34 ) | ( V_40 & V_4 -> V_35 ) ;
}
static void F_23 ( struct V_3 * V_4 , T_2 V_38 ,
T_3 V_42 , T_2 * V_39 )
{
T_3 V_9 ;
F_21 ( V_4 , V_38 , & V_9 , V_39 ) ;
if ( V_9 == V_42 )
return;
* V_39 &= ~ V_4 -> V_35 ;
if ( V_42 < V_9 )
* V_39 += V_4 -> V_35 + 1 ;
}
static int F_24 ( struct V_3 * V_4 , struct V_43 * V_43 ,
T_3 V_42 )
{
T_2 V_44 , V_22 ;
F_23 ( V_4 , V_43 -> V_45 , V_42 , & V_44 ) ;
F_23 ( V_4 , V_43 -> V_45 + F_25 ( V_43 ) ,
V_42 , & V_22 ) ;
if ( V_44 < V_22 ) {
V_43 -> V_46 = V_4 -> V_9 [ V_42 ] . V_16 -> V_47 ;
V_43 -> V_45 = V_44 + V_4 -> V_9 [ V_42 ] . V_18 ;
V_43 -> V_48 = F_26 ( V_22 - V_44 ) ;
return V_49 ;
} else {
F_27 ( V_43 , 0 ) ;
return V_50 ;
}
}
static int F_28 ( struct V_11 * V_5 , struct V_43 * V_43 ,
union V_51 * V_52 )
{
struct V_3 * V_4 = V_5 -> V_37 ;
T_3 V_9 ;
unsigned V_53 ;
if ( V_43 -> V_54 & V_55 ) {
V_53 = V_52 -> V_53 ;
F_29 ( V_53 >= V_4 -> V_7 ) ;
V_43 -> V_46 = V_4 -> V_9 [ V_53 ] . V_16 -> V_47 ;
return V_49 ;
}
if ( F_30 ( V_43 -> V_54 & V_56 ) ) {
V_53 = V_52 -> V_53 ;
F_29 ( V_53 >= V_4 -> V_7 ) ;
return F_24 ( V_4 , V_43 , V_53 ) ;
}
F_21 ( V_4 , V_43 -> V_45 , & V_9 , & V_43 -> V_45 ) ;
V_43 -> V_45 += V_4 -> V_9 [ V_9 ] . V_18 ;
V_43 -> V_46 = V_4 -> V_9 [ V_9 ] . V_16 -> V_47 ;
return V_49 ;
}
static int F_31 ( struct V_11 * V_5 ,
T_4 type , char * V_39 , unsigned int V_57 )
{
struct V_3 * V_4 = (struct V_3 * ) V_5 -> V_37 ;
char V_58 [ V_4 -> V_7 + 1 ] ;
unsigned int V_59 = 0 ;
unsigned int V_24 ;
switch ( type ) {
case V_60 :
F_32 ( L_14 , V_4 -> V_7 ) ;
for ( V_24 = 0 ; V_24 < V_4 -> V_7 ; V_24 ++ ) {
F_32 ( L_15 , V_4 -> V_9 [ V_24 ] . V_16 -> V_61 ) ;
V_58 [ V_24 ] = F_33 ( & ( V_4 -> V_9 [ V_24 ] . V_36 ) ) ?
'D' : 'A' ;
}
V_58 [ V_24 ] = '\0' ;
F_32 ( L_16 , V_58 ) ;
break;
case V_62 :
F_32 ( L_17 , V_4 -> V_7 ,
( unsigned long long ) V_4 -> V_35 + 1 ) ;
for ( V_24 = 0 ; V_24 < V_4 -> V_7 ; V_24 ++ )
F_32 ( L_18 , V_4 -> V_9 [ V_24 ] . V_16 -> V_61 ,
( unsigned long long ) V_4 -> V_9 [ V_24 ] . V_18 ) ;
break;
}
return 0 ;
}
static int F_34 ( struct V_11 * V_5 , struct V_43 * V_43 ,
int error , union V_51 * V_52 )
{
unsigned V_24 ;
char V_63 [ 16 ] ;
struct V_3 * V_4 = V_5 -> V_37 ;
if ( ! error )
return 0 ;
if ( ( error == - V_64 ) && ( V_43 -> V_54 & V_65 ) )
return error ;
if ( error == - V_66 )
return error ;
memset ( V_63 , 0 , sizeof( V_63 ) ) ;
sprintf ( V_63 , L_19 ,
F_35 ( F_36 ( V_43 -> V_46 -> V_67 ) ) ,
F_37 ( F_36 ( V_43 -> V_46 -> V_67 ) ) ) ;
for ( V_24 = 0 ; V_24 < V_4 -> V_7 ; V_24 ++ )
if ( ! strcmp ( V_4 -> V_9 [ V_24 ] . V_16 -> V_61 , V_63 ) ) {
F_38 ( & ( V_4 -> V_9 [ V_24 ] . V_36 ) ) ;
if ( F_33 ( & ( V_4 -> V_9 [ V_24 ] . V_36 ) ) <
V_68 )
F_39 ( & V_4 -> F_1 ) ;
}
return error ;
}
static int F_40 ( struct V_11 * V_5 ,
T_5 V_69 , void * V_70 )
{
struct V_3 * V_4 = V_5 -> V_37 ;
int V_71 = 0 ;
unsigned V_24 = 0 ;
do {
V_71 = V_69 ( V_5 , V_4 -> V_9 [ V_24 ] . V_16 ,
V_4 -> V_9 [ V_24 ] . V_18 ,
V_4 -> V_28 , V_70 ) ;
} while ( ! V_71 && ++ V_24 < V_4 -> V_7 );
return V_71 ;
}
static void F_41 ( struct V_11 * V_5 ,
struct V_72 * V_73 )
{
struct V_3 * V_4 = V_5 -> V_37 ;
unsigned V_21 = ( V_4 -> V_35 + 1 ) << 9 ;
F_42 ( V_73 , V_21 ) ;
F_43 ( V_73 , V_21 * V_4 -> V_7 ) ;
}
static int F_44 ( struct V_11 * V_5 , struct V_74 * V_75 ,
struct V_76 * V_77 , int V_78 )
{
struct V_3 * V_4 = V_5 -> V_37 ;
T_2 V_79 = V_75 -> V_45 ;
T_3 V_9 ;
struct V_80 * V_81 ;
F_21 ( V_4 , V_79 , & V_9 , & V_79 ) ;
V_81 = F_45 ( V_4 -> V_9 [ V_9 ] . V_16 -> V_47 ) ;
if ( ! V_81 -> V_82 )
return V_78 ;
V_75 -> V_46 = V_4 -> V_9 [ V_9 ] . V_16 -> V_47 ;
V_75 -> V_45 = V_4 -> V_9 [ V_9 ] . V_18 + V_79 ;
return F_46 ( V_78 , V_81 -> V_82 ( V_81 , V_75 , V_77 ) ) ;
}
int T_6 F_47 ( void )
{
int V_23 ;
V_23 = F_48 ( & V_83 ) ;
if ( V_23 < 0 ) {
F_49 ( L_20 ) ;
return V_23 ;
}
return V_23 ;
}
void F_50 ( void )
{
F_51 ( & V_83 ) ;
}
