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
if ( sscanf ( V_12 [ 1 ] , L_1 , & V_13 ) != 1 )
return - V_14 ;
if ( F_8 ( V_5 , V_12 [ 0 ] , F_9 ( V_5 -> V_6 ) ,
& V_4 -> V_9 [ V_9 ] . V_15 ) )
return - V_16 ;
V_4 -> V_9 [ V_9 ] . V_17 = V_13 ;
return 0 ;
}
static int F_10 ( struct V_11 * V_5 , unsigned int V_18 , char * * V_12 )
{
struct V_3 * V_4 ;
T_2 V_19 ;
T_3 V_7 ;
T_3 V_20 ;
char * V_21 ;
int V_22 ;
unsigned int V_23 ;
if ( V_18 < 2 ) {
V_5 -> error = L_2 ;
return - V_14 ;
}
V_7 = F_11 ( V_12 [ 0 ] , & V_21 , 10 ) ;
if ( ! V_7 || * V_21 ) {
V_5 -> error = L_3 ;
return - V_14 ;
}
V_20 = F_11 ( V_12 [ 1 ] , & V_21 , 10 ) ;
if ( * V_21 ) {
V_5 -> error = L_4 ;
return - V_14 ;
}
if ( ! F_12 ( V_20 ) ||
( V_20 < ( V_24 >> V_25 ) ) ) {
V_5 -> error = L_5 ;
return - V_14 ;
}
if ( V_5 -> V_8 & ( V_20 - 1 ) ) {
V_5 -> error = L_6
L_7 ;
return - V_14 ;
}
V_19 = V_5 -> V_8 ;
if ( F_13 ( V_19 , V_7 ) ) {
V_5 -> error = L_6
L_8 ;
return - V_14 ;
}
if ( V_18 != ( 2 + 2 * V_7 ) ) {
V_5 -> error = L_9
L_10 ;
return - V_14 ;
}
V_4 = F_4 ( V_7 ) ;
if ( ! V_4 ) {
V_5 -> error = L_11
L_12 ;
return - V_26 ;
}
F_14 ( & V_4 -> F_1 , F_1 ) ;
V_4 -> V_5 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_27 = V_19 ;
if ( V_7 & ( V_7 - 1 ) )
V_4 -> V_28 = - 1 ;
else {
V_4 -> V_28 = F_15 ( V_7 ) - 1 ;
V_4 -> V_29 = ( ( T_2 ) V_7 ) - 1 ;
}
V_5 -> V_30 = V_20 ;
V_5 -> V_31 = V_7 ;
V_5 -> V_32 = V_7 ;
V_4 -> V_33 = F_15 ( V_20 ) - 1 ;
V_4 -> V_34 = ( ( T_2 ) V_20 ) - 1 ;
for ( V_23 = 0 ; V_23 < V_7 ; V_23 ++ ) {
V_12 += 2 ;
V_22 = F_7 ( V_5 , V_4 , V_23 , V_12 ) ;
if ( V_22 < 0 ) {
V_5 -> error = L_13 ;
while ( V_23 -- )
F_16 ( V_5 , V_4 -> V_9 [ V_23 ] . V_15 ) ;
F_17 ( V_4 ) ;
return V_22 ;
}
F_18 ( & ( V_4 -> V_9 [ V_23 ] . V_35 ) , 0 ) ;
}
V_5 -> V_36 = V_4 ;
return 0 ;
}
static void F_19 ( struct V_11 * V_5 )
{
unsigned int V_23 ;
struct V_3 * V_4 = (struct V_3 * ) V_5 -> V_36 ;
for ( V_23 = 0 ; V_23 < V_4 -> V_7 ; V_23 ++ )
F_16 ( V_5 , V_4 -> V_9 [ V_23 ] . V_15 ) ;
F_20 ( & V_4 -> F_1 ) ;
F_17 ( V_4 ) ;
}
static void F_21 ( struct V_3 * V_4 , T_2 V_37 ,
T_3 * V_9 , T_2 * V_38 )
{
T_2 V_39 = F_22 ( V_4 -> V_5 , V_37 ) ;
T_2 V_40 = V_39 >> V_4 -> V_33 ;
if ( V_4 -> V_28 < 0 )
* V_9 = F_13 ( V_40 , V_4 -> V_7 ) ;
else {
* V_9 = V_40 & V_4 -> V_29 ;
V_40 >>= V_4 -> V_28 ;
}
* V_38 = ( V_40 << V_4 -> V_33 ) | ( V_39 & V_4 -> V_34 ) ;
}
static void F_23 ( struct V_3 * V_4 , T_2 V_37 ,
T_3 V_41 , T_2 * V_38 )
{
T_3 V_9 ;
F_21 ( V_4 , V_37 , & V_9 , V_38 ) ;
if ( V_9 == V_41 )
return;
* V_38 &= ~ V_4 -> V_34 ;
if ( V_41 < V_9 )
* V_38 += V_4 -> V_34 + 1 ;
}
static int F_24 ( struct V_3 * V_4 , struct V_42 * V_42 ,
T_3 V_41 )
{
T_2 V_43 , V_21 ;
F_23 ( V_4 , V_42 -> V_44 , V_41 , & V_43 ) ;
F_23 ( V_4 , V_42 -> V_44 + F_25 ( V_42 ) ,
V_41 , & V_21 ) ;
if ( V_43 < V_21 ) {
V_42 -> V_45 = V_4 -> V_9 [ V_41 ] . V_15 -> V_46 ;
V_42 -> V_44 = V_43 + V_4 -> V_9 [ V_41 ] . V_17 ;
V_42 -> V_47 = F_26 ( V_21 - V_43 ) ;
return V_48 ;
} else {
F_27 ( V_42 , 0 ) ;
return V_49 ;
}
}
static int F_28 ( struct V_11 * V_5 , struct V_42 * V_42 ,
union V_50 * V_51 )
{
struct V_3 * V_4 = V_5 -> V_36 ;
T_3 V_9 ;
unsigned V_52 ;
if ( V_42 -> V_53 & V_54 ) {
V_52 = V_51 -> V_52 ;
F_29 ( V_52 >= V_4 -> V_7 ) ;
V_42 -> V_45 = V_4 -> V_9 [ V_52 ] . V_15 -> V_46 ;
return V_48 ;
}
if ( F_30 ( V_42 -> V_53 & V_55 ) ) {
V_52 = V_51 -> V_52 ;
F_29 ( V_52 >= V_4 -> V_7 ) ;
return F_24 ( V_4 , V_42 , V_52 ) ;
}
F_21 ( V_4 , V_42 -> V_44 , & V_9 , & V_42 -> V_44 ) ;
V_42 -> V_44 += V_4 -> V_9 [ V_9 ] . V_17 ;
V_42 -> V_45 = V_4 -> V_9 [ V_9 ] . V_15 -> V_46 ;
return V_48 ;
}
static int F_31 ( struct V_11 * V_5 ,
T_4 type , char * V_38 , unsigned int V_56 )
{
struct V_3 * V_4 = (struct V_3 * ) V_5 -> V_36 ;
char V_57 [ V_4 -> V_7 + 1 ] ;
unsigned int V_58 = 0 ;
unsigned int V_23 ;
switch ( type ) {
case V_59 :
F_32 ( L_14 , V_4 -> V_7 ) ;
for ( V_23 = 0 ; V_23 < V_4 -> V_7 ; V_23 ++ ) {
F_32 ( L_15 , V_4 -> V_9 [ V_23 ] . V_15 -> V_60 ) ;
V_57 [ V_23 ] = F_33 ( & ( V_4 -> V_9 [ V_23 ] . V_35 ) ) ?
'D' : 'A' ;
}
V_57 [ V_23 ] = '\0' ;
F_32 ( L_16 , V_57 ) ;
break;
case V_61 :
F_32 ( L_17 , V_4 -> V_7 ,
( unsigned long long ) V_4 -> V_34 + 1 ) ;
for ( V_23 = 0 ; V_23 < V_4 -> V_7 ; V_23 ++ )
F_32 ( L_18 , V_4 -> V_9 [ V_23 ] . V_15 -> V_60 ,
( unsigned long long ) V_4 -> V_9 [ V_23 ] . V_17 ) ;
break;
}
return 0 ;
}
static int F_34 ( struct V_11 * V_5 , struct V_42 * V_42 ,
int error , union V_50 * V_51 )
{
unsigned V_23 ;
char V_62 [ 16 ] ;
struct V_3 * V_4 = V_5 -> V_36 ;
if ( ! error )
return 0 ;
if ( ( error == - V_63 ) && ( V_42 -> V_53 & V_64 ) )
return error ;
if ( error == - V_65 )
return error ;
memset ( V_62 , 0 , sizeof( V_62 ) ) ;
sprintf ( V_62 , L_19 ,
F_35 ( F_36 ( V_42 -> V_45 -> V_66 ) ) ,
F_37 ( F_36 ( V_42 -> V_45 -> V_66 ) ) ) ;
for ( V_23 = 0 ; V_23 < V_4 -> V_7 ; V_23 ++ )
if ( ! strcmp ( V_4 -> V_9 [ V_23 ] . V_15 -> V_60 , V_62 ) ) {
F_38 ( & ( V_4 -> V_9 [ V_23 ] . V_35 ) ) ;
if ( F_33 ( & ( V_4 -> V_9 [ V_23 ] . V_35 ) ) <
V_67 )
F_39 ( & V_4 -> F_1 ) ;
}
return error ;
}
static int F_40 ( struct V_11 * V_5 ,
T_5 V_68 , void * V_69 )
{
struct V_3 * V_4 = V_5 -> V_36 ;
int V_70 = 0 ;
unsigned V_23 = 0 ;
do {
V_70 = V_68 ( V_5 , V_4 -> V_9 [ V_23 ] . V_15 ,
V_4 -> V_9 [ V_23 ] . V_17 ,
V_4 -> V_27 , V_69 ) ;
} while ( ! V_70 && ++ V_23 < V_4 -> V_7 );
return V_70 ;
}
static void F_41 ( struct V_11 * V_5 ,
struct V_71 * V_72 )
{
struct V_3 * V_4 = V_5 -> V_36 ;
unsigned V_20 = ( V_4 -> V_34 + 1 ) << 9 ;
F_42 ( V_72 , V_20 ) ;
F_43 ( V_72 , V_20 * V_4 -> V_7 ) ;
}
static int F_44 ( struct V_11 * V_5 , struct V_73 * V_74 ,
struct V_75 * V_76 , int V_77 )
{
struct V_3 * V_4 = V_5 -> V_36 ;
T_2 V_78 = V_74 -> V_44 ;
T_3 V_9 ;
struct V_79 * V_80 ;
F_21 ( V_4 , V_78 , & V_9 , & V_78 ) ;
V_80 = F_45 ( V_4 -> V_9 [ V_9 ] . V_15 -> V_46 ) ;
if ( ! V_80 -> V_81 )
return V_77 ;
V_74 -> V_45 = V_4 -> V_9 [ V_9 ] . V_15 -> V_46 ;
V_74 -> V_44 = V_4 -> V_9 [ V_9 ] . V_17 + V_78 ;
return F_46 ( V_77 , V_80 -> V_81 ( V_80 , V_74 , V_76 ) ) ;
}
int T_6 F_47 ( void )
{
int V_22 ;
V_22 = F_48 ( & V_82 ) ;
if ( V_22 < 0 ) {
F_49 ( L_20 ) ;
return V_22 ;
}
return V_22 ;
}
void F_50 ( void )
{
F_51 ( & V_82 ) ;
}
