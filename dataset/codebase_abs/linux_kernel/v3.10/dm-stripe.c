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
T_2 V_20 , V_21 ;
T_3 V_7 ;
T_3 V_22 ;
int V_23 ;
unsigned int V_24 ;
if ( V_19 < 2 ) {
V_5 -> error = L_2 ;
return - V_15 ;
}
if ( F_11 ( V_12 [ 0 ] , 10 , & V_7 ) || ! V_7 ) {
V_5 -> error = L_3 ;
return - V_15 ;
}
if ( F_11 ( V_12 [ 1 ] , 10 , & V_22 ) || ! V_22 ) {
V_5 -> error = L_4 ;
return - V_15 ;
}
V_20 = V_5 -> V_8 ;
if ( F_12 ( V_20 , V_7 ) ) {
V_5 -> error = L_5
L_6 ;
return - V_15 ;
}
V_21 = V_20 ;
if ( F_12 ( V_21 , V_22 ) ) {
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
return - V_25 ;
}
F_13 ( & V_4 -> F_1 , F_1 ) ;
V_4 -> V_5 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_26 = V_20 ;
if ( V_7 & ( V_7 - 1 ) )
V_4 -> V_27 = - 1 ;
else
V_4 -> V_27 = F_14 ( V_7 ) ;
V_23 = F_15 ( V_5 , V_22 ) ;
if ( V_23 )
return V_23 ;
V_5 -> V_28 = V_7 ;
V_5 -> V_29 = V_7 ;
V_5 -> V_30 = V_7 ;
V_4 -> V_22 = V_22 ;
if ( V_22 & ( V_22 - 1 ) )
V_4 -> V_31 = - 1 ;
else
V_4 -> V_31 = F_14 ( V_22 ) ;
for ( V_24 = 0 ; V_24 < V_7 ; V_24 ++ ) {
V_12 += 2 ;
V_23 = F_7 ( V_5 , V_4 , V_24 , V_12 ) ;
if ( V_23 < 0 ) {
V_5 -> error = L_12 ;
while ( V_24 -- )
F_16 ( V_5 , V_4 -> V_9 [ V_24 ] . V_16 ) ;
F_17 ( V_4 ) ;
return V_23 ;
}
F_18 ( & ( V_4 -> V_9 [ V_24 ] . V_32 ) , 0 ) ;
}
V_5 -> V_33 = V_4 ;
return 0 ;
}
static void F_19 ( struct V_11 * V_5 )
{
unsigned int V_24 ;
struct V_3 * V_4 = (struct V_3 * ) V_5 -> V_33 ;
for ( V_24 = 0 ; V_24 < V_4 -> V_7 ; V_24 ++ )
F_16 ( V_5 , V_4 -> V_9 [ V_24 ] . V_16 ) ;
F_20 ( & V_4 -> F_1 ) ;
F_17 ( V_4 ) ;
}
static void F_21 ( struct V_3 * V_4 , T_2 V_34 ,
T_3 * V_9 , T_2 * V_35 )
{
T_2 V_36 = F_22 ( V_4 -> V_5 , V_34 ) ;
T_2 V_37 ;
if ( V_4 -> V_31 < 0 )
V_37 = F_12 ( V_36 , V_4 -> V_22 ) ;
else {
V_37 = V_36 & ( V_4 -> V_22 - 1 ) ;
V_36 >>= V_4 -> V_31 ;
}
if ( V_4 -> V_27 < 0 )
* V_9 = F_12 ( V_36 , V_4 -> V_7 ) ;
else {
* V_9 = V_36 & ( V_4 -> V_7 - 1 ) ;
V_36 >>= V_4 -> V_27 ;
}
if ( V_4 -> V_31 < 0 )
V_36 *= V_4 -> V_22 ;
else
V_36 <<= V_4 -> V_31 ;
* V_35 = V_36 + V_37 ;
}
static void F_23 ( struct V_3 * V_4 , T_2 V_34 ,
T_3 V_38 , T_2 * V_35 )
{
T_3 V_9 ;
F_21 ( V_4 , V_34 , & V_9 , V_35 ) ;
if ( V_9 == V_38 )
return;
V_34 = * V_35 ;
if ( V_4 -> V_31 < 0 )
* V_35 -= F_12 ( V_34 , V_4 -> V_22 ) ;
else
* V_35 = V_34 & ~ ( T_2 ) ( V_4 -> V_22 - 1 ) ;
if ( V_38 < V_9 )
* V_35 += V_4 -> V_22 ;
}
static int F_24 ( struct V_3 * V_4 , struct V_39 * V_39 ,
T_3 V_38 )
{
T_2 V_40 , V_41 ;
F_23 ( V_4 , V_39 -> V_42 , V_38 , & V_40 ) ;
F_23 ( V_4 , F_25 ( V_39 ) ,
V_38 , & V_41 ) ;
if ( V_40 < V_41 ) {
V_39 -> V_43 = V_4 -> V_9 [ V_38 ] . V_16 -> V_44 ;
V_39 -> V_42 = V_40 + V_4 -> V_9 [ V_38 ] . V_18 ;
V_39 -> V_45 = F_26 ( V_41 - V_40 ) ;
return V_46 ;
} else {
F_27 ( V_39 , 0 ) ;
return V_47 ;
}
}
static int F_28 ( struct V_11 * V_5 , struct V_39 * V_39 )
{
struct V_3 * V_4 = V_5 -> V_33 ;
T_3 V_9 ;
unsigned V_48 ;
if ( V_39 -> V_49 & V_50 ) {
V_48 = F_29 ( V_39 ) ;
F_30 ( V_48 >= V_4 -> V_7 ) ;
V_39 -> V_43 = V_4 -> V_9 [ V_48 ] . V_16 -> V_44 ;
return V_46 ;
}
if ( F_31 ( V_39 -> V_49 & V_51 ) ||
F_31 ( V_39 -> V_49 & V_52 ) ) {
V_48 = F_29 ( V_39 ) ;
F_30 ( V_48 >= V_4 -> V_7 ) ;
return F_24 ( V_4 , V_39 , V_48 ) ;
}
F_21 ( V_4 , V_39 -> V_42 , & V_9 , & V_39 -> V_42 ) ;
V_39 -> V_42 += V_4 -> V_9 [ V_9 ] . V_18 ;
V_39 -> V_43 = V_4 -> V_9 [ V_9 ] . V_16 -> V_44 ;
return V_46 ;
}
static void F_32 ( struct V_11 * V_5 , T_4 type ,
unsigned V_53 , char * V_35 , unsigned V_54 )
{
struct V_3 * V_4 = (struct V_3 * ) V_5 -> V_33 ;
char V_55 [ V_4 -> V_7 + 1 ] ;
unsigned int V_56 = 0 ;
unsigned int V_24 ;
switch ( type ) {
case V_57 :
F_33 ( L_13 , V_4 -> V_7 ) ;
for ( V_24 = 0 ; V_24 < V_4 -> V_7 ; V_24 ++ ) {
F_33 ( L_14 , V_4 -> V_9 [ V_24 ] . V_16 -> V_58 ) ;
V_55 [ V_24 ] = F_34 ( & ( V_4 -> V_9 [ V_24 ] . V_32 ) ) ?
'D' : 'A' ;
}
V_55 [ V_24 ] = '\0' ;
F_33 ( L_15 , V_55 ) ;
break;
case V_59 :
F_33 ( L_16 , V_4 -> V_7 ,
( unsigned long long ) V_4 -> V_22 ) ;
for ( V_24 = 0 ; V_24 < V_4 -> V_7 ; V_24 ++ )
F_33 ( L_17 , V_4 -> V_9 [ V_24 ] . V_16 -> V_58 ,
( unsigned long long ) V_4 -> V_9 [ V_24 ] . V_18 ) ;
break;
}
}
static int F_35 ( struct V_11 * V_5 , struct V_39 * V_39 , int error )
{
unsigned V_24 ;
char V_60 [ 16 ] ;
struct V_3 * V_4 = V_5 -> V_33 ;
if ( ! error )
return 0 ;
if ( ( error == - V_61 ) && ( V_39 -> V_49 & V_62 ) )
return error ;
if ( error == - V_63 )
return error ;
memset ( V_60 , 0 , sizeof( V_60 ) ) ;
sprintf ( V_60 , L_18 ,
F_36 ( F_37 ( V_39 -> V_43 -> V_64 ) ) ,
F_38 ( F_37 ( V_39 -> V_43 -> V_64 ) ) ) ;
for ( V_24 = 0 ; V_24 < V_4 -> V_7 ; V_24 ++ )
if ( ! strcmp ( V_4 -> V_9 [ V_24 ] . V_16 -> V_58 , V_60 ) ) {
F_39 ( & ( V_4 -> V_9 [ V_24 ] . V_32 ) ) ;
if ( F_34 ( & ( V_4 -> V_9 [ V_24 ] . V_32 ) ) <
V_65 )
F_40 ( & V_4 -> F_1 ) ;
}
return error ;
}
static int F_41 ( struct V_11 * V_5 ,
T_5 V_66 , void * V_67 )
{
struct V_3 * V_4 = V_5 -> V_33 ;
int V_68 = 0 ;
unsigned V_24 = 0 ;
do {
V_68 = V_66 ( V_5 , V_4 -> V_9 [ V_24 ] . V_16 ,
V_4 -> V_9 [ V_24 ] . V_18 ,
V_4 -> V_26 , V_67 ) ;
} while ( ! V_68 && ++ V_24 < V_4 -> V_7 );
return V_68 ;
}
static void F_42 ( struct V_11 * V_5 ,
struct V_69 * V_70 )
{
struct V_3 * V_4 = V_5 -> V_33 ;
unsigned V_22 = V_4 -> V_22 << V_71 ;
F_43 ( V_70 , V_22 ) ;
F_44 ( V_70 , V_22 * V_4 -> V_7 ) ;
}
static int F_45 ( struct V_11 * V_5 , struct V_72 * V_73 ,
struct V_74 * V_75 , int V_76 )
{
struct V_3 * V_4 = V_5 -> V_33 ;
T_2 V_77 = V_73 -> V_42 ;
T_3 V_9 ;
struct V_78 * V_79 ;
F_21 ( V_4 , V_77 , & V_9 , & V_77 ) ;
V_79 = F_46 ( V_4 -> V_9 [ V_9 ] . V_16 -> V_44 ) ;
if ( ! V_79 -> V_80 )
return V_76 ;
V_73 -> V_43 = V_4 -> V_9 [ V_9 ] . V_16 -> V_44 ;
V_73 -> V_42 = V_4 -> V_9 [ V_9 ] . V_18 + V_77 ;
return F_47 ( V_76 , V_79 -> V_80 ( V_79 , V_73 , V_75 ) ) ;
}
int T_6 F_48 ( void )
{
int V_23 ;
V_23 = F_49 ( & V_81 ) ;
if ( V_23 < 0 ) {
F_50 ( L_19 ) ;
return V_23 ;
}
return V_23 ;
}
void F_51 ( void )
{
F_52 ( & V_81 ) ;
}
