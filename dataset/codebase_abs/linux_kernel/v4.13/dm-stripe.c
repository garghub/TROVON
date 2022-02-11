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
int V_15 ;
if ( sscanf ( V_12 [ 1 ] , L_1 , & V_13 , & V_14 ) != 1 )
return - V_16 ;
V_15 = F_8 ( V_5 , V_12 [ 0 ] , F_9 ( V_5 -> V_6 ) ,
& V_4 -> V_9 [ V_9 ] . V_17 ) ;
if ( V_15 )
return V_15 ;
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
return - V_16 ;
}
if ( F_11 ( V_12 [ 0 ] , 10 , & V_7 ) || ! V_7 ) {
V_5 -> error = L_3 ;
return - V_16 ;
}
if ( F_11 ( V_12 [ 1 ] , 10 , & V_22 ) || ! V_22 ) {
V_5 -> error = L_4 ;
return - V_16 ;
}
V_20 = V_5 -> V_8 ;
if ( F_12 ( V_20 , V_7 ) ) {
V_5 -> error = L_5
L_6 ;
return - V_16 ;
}
V_21 = V_20 ;
if ( F_12 ( V_21 , V_22 ) ) {
V_5 -> error = L_5
L_7 ;
return - V_16 ;
}
if ( V_19 != ( 2 + 2 * V_7 ) ) {
V_5 -> error = L_8
L_9 ;
return - V_16 ;
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
if ( V_23 ) {
F_16 ( V_4 ) ;
return V_23 ;
}
V_5 -> V_28 = V_7 ;
V_5 -> V_29 = V_7 ;
V_5 -> V_30 = V_7 ;
V_5 -> V_31 = V_7 ;
V_4 -> V_22 = V_22 ;
if ( V_22 & ( V_22 - 1 ) )
V_4 -> V_32 = - 1 ;
else
V_4 -> V_32 = F_14 ( V_22 ) ;
for ( V_24 = 0 ; V_24 < V_7 ; V_24 ++ ) {
V_12 += 2 ;
V_23 = F_7 ( V_5 , V_4 , V_24 , V_12 ) ;
if ( V_23 < 0 ) {
V_5 -> error = L_12 ;
while ( V_24 -- )
F_17 ( V_5 , V_4 -> V_9 [ V_24 ] . V_17 ) ;
F_16 ( V_4 ) ;
return V_23 ;
}
F_18 ( & ( V_4 -> V_9 [ V_24 ] . V_33 ) , 0 ) ;
}
V_5 -> V_34 = V_4 ;
return 0 ;
}
static void F_19 ( struct V_11 * V_5 )
{
unsigned int V_24 ;
struct V_3 * V_4 = (struct V_3 * ) V_5 -> V_34 ;
for ( V_24 = 0 ; V_24 < V_4 -> V_7 ; V_24 ++ )
F_17 ( V_5 , V_4 -> V_9 [ V_24 ] . V_17 ) ;
F_20 ( & V_4 -> F_1 ) ;
F_16 ( V_4 ) ;
}
static void F_21 ( struct V_3 * V_4 , T_2 V_35 ,
T_3 * V_9 , T_2 * V_36 )
{
T_2 V_37 = F_22 ( V_4 -> V_5 , V_35 ) ;
T_2 V_38 ;
if ( V_4 -> V_32 < 0 )
V_38 = F_12 ( V_37 , V_4 -> V_22 ) ;
else {
V_38 = V_37 & ( V_4 -> V_22 - 1 ) ;
V_37 >>= V_4 -> V_32 ;
}
if ( V_4 -> V_27 < 0 )
* V_9 = F_12 ( V_37 , V_4 -> V_7 ) ;
else {
* V_9 = V_37 & ( V_4 -> V_7 - 1 ) ;
V_37 >>= V_4 -> V_27 ;
}
if ( V_4 -> V_32 < 0 )
V_37 *= V_4 -> V_22 ;
else
V_37 <<= V_4 -> V_32 ;
* V_36 = V_37 + V_38 ;
}
static void F_23 ( struct V_3 * V_4 , T_2 V_35 ,
T_3 V_39 , T_2 * V_36 )
{
T_3 V_9 ;
F_21 ( V_4 , V_35 , & V_9 , V_36 ) ;
if ( V_9 == V_39 )
return;
V_35 = * V_36 ;
if ( V_4 -> V_32 < 0 )
* V_36 -= F_12 ( V_35 , V_4 -> V_22 ) ;
else
* V_36 = V_35 & ~ ( T_2 ) ( V_4 -> V_22 - 1 ) ;
if ( V_39 < V_9 )
* V_36 += V_4 -> V_22 ;
}
static int F_24 ( struct V_3 * V_4 , struct V_40 * V_40 ,
T_3 V_39 )
{
T_2 V_41 , V_42 ;
F_23 ( V_4 , V_40 -> V_43 . V_44 ,
V_39 , & V_41 ) ;
F_23 ( V_4 , F_25 ( V_40 ) ,
V_39 , & V_42 ) ;
if ( V_41 < V_42 ) {
V_40 -> V_45 = V_4 -> V_9 [ V_39 ] . V_17 -> V_46 ;
V_40 -> V_43 . V_44 = V_41 +
V_4 -> V_9 [ V_39 ] . V_18 ;
V_40 -> V_43 . V_47 = F_26 ( V_42 - V_41 ) ;
return V_48 ;
} else {
F_27 ( V_40 ) ;
return V_49 ;
}
}
static int F_28 ( struct V_11 * V_5 , struct V_40 * V_40 )
{
struct V_3 * V_4 = V_5 -> V_34 ;
T_3 V_9 ;
unsigned V_50 ;
if ( V_40 -> V_51 & V_52 ) {
V_50 = F_29 ( V_40 ) ;
F_30 ( V_50 >= V_4 -> V_7 ) ;
V_40 -> V_45 = V_4 -> V_9 [ V_50 ] . V_17 -> V_46 ;
return V_48 ;
}
if ( F_31 ( F_32 ( V_40 ) == V_53 ) ||
F_31 ( F_32 ( V_40 ) == V_54 ) ||
F_31 ( F_32 ( V_40 ) == V_55 ) ) {
V_50 = F_29 ( V_40 ) ;
F_30 ( V_50 >= V_4 -> V_7 ) ;
return F_24 ( V_4 , V_40 , V_50 ) ;
}
F_21 ( V_4 , V_40 -> V_43 . V_44 ,
& V_9 , & V_40 -> V_43 . V_44 ) ;
V_40 -> V_43 . V_44 += V_4 -> V_9 [ V_9 ] . V_18 ;
V_40 -> V_45 = V_4 -> V_9 [ V_9 ] . V_17 -> V_46 ;
return V_48 ;
}
static long F_33 ( struct V_11 * V_5 , T_4 V_56 ,
long V_57 , void * * V_58 , T_5 * V_59 )
{
T_2 V_60 , V_35 = V_56 * V_61 ;
struct V_3 * V_4 = V_5 -> V_34 ;
struct V_62 * V_63 ;
struct V_64 * V_46 ;
T_3 V_9 ;
long V_15 ;
F_21 ( V_4 , V_35 , & V_9 , & V_60 ) ;
V_60 += V_4 -> V_9 [ V_9 ] . V_18 ;
V_63 = V_4 -> V_9 [ V_9 ] . V_17 -> V_63 ;
V_46 = V_4 -> V_9 [ V_9 ] . V_17 -> V_46 ;
V_15 = F_34 ( V_46 , V_60 , V_57 * V_65 , & V_56 ) ;
if ( V_15 )
return V_15 ;
return F_35 ( V_63 , V_56 , V_57 , V_58 , V_59 ) ;
}
static T_1 F_36 ( struct V_11 * V_5 , T_4 V_56 ,
void * V_66 , T_1 V_67 , struct V_68 * V_24 )
{
T_2 V_60 , V_35 = V_56 * V_61 ;
struct V_3 * V_4 = V_5 -> V_34 ;
struct V_62 * V_63 ;
struct V_64 * V_46 ;
T_3 V_9 ;
F_21 ( V_4 , V_35 , & V_9 , & V_60 ) ;
V_60 += V_4 -> V_9 [ V_9 ] . V_18 ;
V_63 = V_4 -> V_9 [ V_9 ] . V_17 -> V_63 ;
V_46 = V_4 -> V_9 [ V_9 ] . V_17 -> V_46 ;
if ( F_34 ( V_46 , V_60 , F_37 ( V_67 , V_65 ) , & V_56 ) )
return 0 ;
return F_38 ( V_63 , V_56 , V_66 , V_67 , V_24 ) ;
}
static void F_39 ( struct V_11 * V_5 , T_4 V_56 , void * V_66 ,
T_1 V_69 )
{
T_2 V_60 , V_35 = V_56 * V_61 ;
struct V_3 * V_4 = V_5 -> V_34 ;
struct V_62 * V_63 ;
struct V_64 * V_46 ;
T_3 V_9 ;
F_21 ( V_4 , V_35 , & V_9 , & V_60 ) ;
V_60 += V_4 -> V_9 [ V_9 ] . V_18 ;
V_63 = V_4 -> V_9 [ V_9 ] . V_17 -> V_63 ;
V_46 = V_4 -> V_9 [ V_9 ] . V_17 -> V_46 ;
if ( F_34 ( V_46 , V_60 , F_37 ( V_69 , V_65 ) , & V_56 ) )
return;
F_40 ( V_63 , V_56 , V_66 , V_69 ) ;
}
static void F_41 ( struct V_11 * V_5 , T_6 type ,
unsigned V_70 , char * V_36 , unsigned V_71 )
{
struct V_3 * V_4 = (struct V_3 * ) V_5 -> V_34 ;
char V_72 [ V_4 -> V_7 + 1 ] ;
unsigned int V_73 = 0 ;
unsigned int V_24 ;
switch ( type ) {
case V_74 :
F_42 ( L_13 , V_4 -> V_7 ) ;
for ( V_24 = 0 ; V_24 < V_4 -> V_7 ; V_24 ++ ) {
F_42 ( L_14 , V_4 -> V_9 [ V_24 ] . V_17 -> V_75 ) ;
V_72 [ V_24 ] = F_43 ( & ( V_4 -> V_9 [ V_24 ] . V_33 ) ) ?
'D' : 'A' ;
}
V_72 [ V_24 ] = '\0' ;
F_42 ( L_15 , V_72 ) ;
break;
case V_76 :
F_42 ( L_16 , V_4 -> V_7 ,
( unsigned long long ) V_4 -> V_22 ) ;
for ( V_24 = 0 ; V_24 < V_4 -> V_7 ; V_24 ++ )
F_42 ( L_17 , V_4 -> V_9 [ V_24 ] . V_17 -> V_75 ,
( unsigned long long ) V_4 -> V_9 [ V_24 ] . V_18 ) ;
break;
}
}
static int F_44 ( struct V_11 * V_5 , struct V_40 * V_40 ,
T_7 * error )
{
unsigned V_24 ;
char V_77 [ 16 ] ;
struct V_3 * V_4 = V_5 -> V_34 ;
if ( ! * error )
return V_78 ;
if ( V_40 -> V_51 & V_79 )
return V_78 ;
if ( * error == V_80 )
return V_78 ;
memset ( V_77 , 0 , sizeof( V_77 ) ) ;
sprintf ( V_77 , L_18 ,
F_45 ( F_46 ( V_40 -> V_45 -> V_81 ) ) ,
F_47 ( F_46 ( V_40 -> V_45 -> V_81 ) ) ) ;
for ( V_24 = 0 ; V_24 < V_4 -> V_7 ; V_24 ++ )
if ( ! strcmp ( V_4 -> V_9 [ V_24 ] . V_17 -> V_75 , V_77 ) ) {
F_48 ( & ( V_4 -> V_9 [ V_24 ] . V_33 ) ) ;
if ( F_43 ( & ( V_4 -> V_9 [ V_24 ] . V_33 ) ) <
V_82 )
F_49 ( & V_4 -> F_1 ) ;
}
return V_78 ;
}
static int F_50 ( struct V_11 * V_5 ,
T_8 V_83 , void * V_84 )
{
struct V_3 * V_4 = V_5 -> V_34 ;
int V_15 = 0 ;
unsigned V_24 = 0 ;
do {
V_15 = V_83 ( V_5 , V_4 -> V_9 [ V_24 ] . V_17 ,
V_4 -> V_9 [ V_24 ] . V_18 ,
V_4 -> V_26 , V_84 ) ;
} while ( ! V_15 && ++ V_24 < V_4 -> V_7 );
return V_15 ;
}
static void F_51 ( struct V_11 * V_5 ,
struct V_85 * V_86 )
{
struct V_3 * V_4 = V_5 -> V_34 ;
unsigned V_22 = V_4 -> V_22 << V_87 ;
F_52 ( V_86 , V_22 ) ;
F_53 ( V_86 , V_22 * V_4 -> V_7 ) ;
}
int T_9 F_54 ( void )
{
int V_23 ;
V_23 = F_55 ( & V_88 ) ;
if ( V_23 < 0 )
F_56 ( L_19 ) ;
return V_23 ;
}
void F_57 ( void )
{
F_58 ( & V_88 ) ;
}
