static int
F_1 ( struct V_1 * V_2 )
{
struct F_1 * V_3 = F_2 ( V_2 , F_3 ( * V_3 ) , V_2 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
return V_5 -> V_6 ( & V_3 -> V_7 , V_3 -> V_8 , V_2 -> V_9 , V_2 -> V_8 ) ;
}
int
F_4 ( struct V_4 * V_5 , int V_10 )
{
if ( V_10 < F_5 ( V_5 -> V_3 ) ) {
if ( V_5 -> V_3 [ V_10 ] ) {
F_6 ( & V_5 -> V_3 [ V_10 ] -> V_2 ) ;
return 0 ;
}
}
return - V_11 ;
}
int
F_7 ( struct V_4 * V_5 , int V_10 )
{
if ( V_10 < F_5 ( V_5 -> V_3 ) ) {
if ( V_5 -> V_3 [ V_10 ] ) {
F_8 ( & V_5 -> V_3 [ V_10 ] -> V_2 ) ;
return 0 ;
}
}
return - V_11 ;
}
int
F_9 ( struct V_4 * V_5 , int V_10 )
{
if ( V_10 < F_5 ( V_5 -> V_3 ) ) {
if ( V_5 -> V_3 [ V_10 ] ) {
F_10 ( & V_5 -> V_3 [ V_10 ] -> V_2 ) ;
F_11 ( V_5 -> V_3 [ V_10 ] ) ;
V_5 -> V_3 [ V_10 ] = NULL ;
return 0 ;
}
}
return - V_11 ;
}
int
F_12 ( struct V_12 * V_13 ,
struct V_14 * V_15 , void * V_9 , T_1 V_8 )
{
struct V_4 * V_5 = V_4 ( V_13 ) ;
struct F_1 * V_3 ;
union {
struct V_16 V_17 ;
} * V_18 = V_9 ;
T_2 V_10 , V_19 ;
int V_20 ;
for ( V_10 = 0 ; V_10 < F_5 ( V_5 -> V_3 ) ; V_10 ++ ) {
if ( ! V_5 -> V_3 [ V_10 ] )
break;
}
if ( V_10 == F_5 ( V_5 -> V_3 ) )
return - V_21 ;
V_3 = F_13 ( sizeof( * V_3 ) , V_22 ) ;
if ( ! V_3 )
return - V_23 ;
F_14 ( V_5 , L_1 , V_8 ) ;
if ( F_15 ( V_18 -> V_17 , 0 , 0 , true ) ) {
F_14 ( V_5 , L_2
L_3 , V_18 -> V_17 . V_24 ,
V_18 -> V_17 . V_19 , V_18 -> V_17 . V_25 , V_18 -> V_17 . V_26 ) ;
V_3 -> V_24 = V_18 -> V_17 . V_24 ;
V_3 -> V_8 = sizeof( V_3 -> V_7 . V_17 ) ;
V_3 -> V_7 . V_17 . V_24 = V_18 -> V_17 . V_24 ;
V_3 -> V_7 . V_17 . V_25 = V_18 -> V_17 . V_25 ;
V_3 -> V_7 . V_17 . V_26 = V_18 -> V_17 . V_26 ;
V_19 = V_18 -> V_17 . V_19 ;
}
if ( V_20 == 0 ) {
V_20 = F_16 ( V_13 , V_15 , F_1 ,
false , V_9 , V_8 , V_19 , & V_3 -> V_2 ) ;
if ( V_20 == 0 ) {
V_5 -> V_3 [ V_10 ] = V_3 ;
V_3 -> V_5 = V_5 ;
return V_10 ;
}
}
F_11 ( V_3 ) ;
return V_20 ;
}
static int
F_17 ( struct V_12 * V_13 , void * V_9 , T_1 V_8 )
{
union {
struct V_27 V_17 ;
} * args = V_9 ;
int V_20 ;
F_14 ( V_13 , L_4 , V_8 ) ;
if ( F_15 ( args -> V_17 , 0 , 0 , true ) ) {
F_14 ( V_13 , L_5 ,
args -> V_17 . V_24 , args -> V_17 . V_28 ) ;
if ( V_8 == sizeof( args -> V_17 . V_29 [ 0 ] ) * args -> V_17 . V_28 ) {
V_20 = F_18 ( args -> V_17 . V_29 , args -> V_17 . V_28 ) ;
if ( V_20 >= 0 ) {
args -> V_17 . V_28 = V_20 ;
V_20 = 0 ;
}
} else {
V_20 = - V_30 ;
}
}
return V_20 ;
}
static int
F_19 ( struct V_12 * V_13 , T_1 V_31 , void * V_9 , T_1 V_8 )
{
switch ( V_31 ) {
case V_32 :
return F_17 ( V_13 , V_9 , V_8 ) ;
default:
break;
}
return - V_30 ;
}
static void
F_20 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = ( void * ) V_13 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < F_5 ( V_5 -> V_3 ) ; V_33 ++ )
F_9 ( V_5 , V_33 ) ;
F_21 ( NULL , & V_5 -> V_29 ) ;
F_22 ( V_5 -> V_34 ) ;
F_23 ( & V_5 -> V_35 ) ;
}
int
F_24 ( const char * V_36 , T_3 V_37 , const char * V_38 ,
const char * V_39 , int V_40 , void * * V_41 )
{
struct V_12 * V_29 ;
struct V_4 * V_5 ;
int V_20 ;
V_29 = ( void * ) F_25 ( V_37 ) ;
if ( ! V_29 )
return - V_42 ;
V_20 = F_26 ( NULL , NULL , & V_43 ,
V_44 , NULL ,
( 1ULL << V_45 ) ,
V_40 , V_41 ) ;
V_5 = * V_41 ;
if ( V_20 )
return V_20 ;
V_20 = F_27 ( F_28 ( V_5 ) , ~ 0 , ~ 0 , F_28 ( V_5 ) ,
& V_5 -> V_34 ) ;
if ( V_20 )
return V_20 ;
F_29 ( & F_28 ( V_5 ) -> V_46 , 2 ) ;
F_21 ( V_29 , & V_5 -> V_29 ) ;
snprintf ( V_5 -> V_36 , sizeof( V_5 -> V_36 ) , L_6 , V_36 ) ;
V_5 -> V_47 = F_30 ( V_39 , L_7 ) ;
return 0 ;
}
int
F_31 ( struct V_4 * V_5 )
{
int V_20 ;
F_32 ( V_5 , L_8 ) ;
V_20 = F_33 ( V_5 -> V_34 ) ;
F_32 ( V_5 , L_9 , V_20 ) ;
return V_20 ;
}
int
F_34 ( struct V_4 * V_5 , bool V_48 )
{
const char * V_36 [ 2 ] = { L_10 , L_11 } ;
int V_20 , V_33 ;
F_32 ( V_5 , L_12 , V_36 [ V_48 ] ) ;
F_32 ( V_5 , L_13 , V_36 [ V_48 ] ) ;
for ( V_33 = 0 ; V_33 < F_5 ( V_5 -> V_3 ) ; V_33 ++ )
F_4 ( V_5 , V_33 ) ;
F_32 ( V_5 , L_14 , V_36 [ V_48 ] ) ;
V_20 = F_35 ( V_5 -> V_34 , V_48 ) ;
F_32 ( V_5 , L_15 , V_36 [ V_48 ] , V_20 ) ;
return V_20 ;
}
const char *
F_36 ( void * V_49 )
{
const char * V_50 = L_16 ;
struct V_4 * V_5 = V_4 ( V_49 ) ;
if ( V_5 )
V_50 = V_5 -> V_36 ;
return V_50 ;
}
