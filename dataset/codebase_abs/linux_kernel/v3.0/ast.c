static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_1 ,
V_2 -> V_4 ,
( unsigned long long ) V_2 -> V_5 . V_6 ,
V_2 -> V_5 . V_7 ,
V_2 -> V_5 . V_8 ,
V_2 -> V_5 . V_9 ,
V_2 -> V_5 . V_10 ) ;
F_2 ( L_2 ,
V_2 -> V_4 ,
( unsigned long long ) V_2 -> V_11 . V_6 ,
V_2 -> V_11 . V_7 ,
V_2 -> V_11 . V_8 ,
V_2 -> V_11 . V_9 ,
V_2 -> V_11 . V_10 ) ;
for ( V_3 = 0 ; V_3 < V_12 ; V_3 ++ ) {
F_2 ( L_3 ,
V_2 -> V_4 ,
( unsigned long long ) V_2 -> V_13 [ V_3 ] . V_6 ,
V_2 -> V_13 [ V_3 ] . V_7 ,
V_2 -> V_13 [ V_3 ] . V_8 ,
V_2 -> V_13 [ V_3 ] . V_9 ,
V_2 -> V_13 [ V_3 ] . V_10 ) ;
}
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_14 ) ;
if ( ! F_5 ( & V_2 -> V_15 ) )
F_6 ( & V_2 -> V_15 ) ;
F_7 ( & V_14 ) ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_7 , int V_8 ,
int V_16 , T_1 V_17 , T_2 V_6 )
{
struct V_18 * V_19 = V_2 -> V_20 -> V_21 ;
T_2 V_22 ;
int V_23 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_12 ; V_3 ++ ) {
if ( V_2 -> V_13 [ V_3 ] . V_6 )
continue;
if ( ( V_3 > 0 ) && ( V_7 & V_24 ) &&
( V_2 -> V_13 [ V_3 - 1 ] . V_7 & V_24 ) ) {
V_22 = V_2 -> V_13 [ V_3 - 1 ] . V_6 ;
V_23 = V_2 -> V_13 [ V_3 - 1 ] . V_8 ;
if ( ( V_23 == V_8 ) ||
( V_23 > V_8 && V_23 > V_25 ) ) {
F_9 ( V_19 , L_4
L_5 ,
V_2 -> V_4 ,
( unsigned long long ) V_6 ,
V_8 ,
( unsigned long long ) V_22 ,
V_23 ) ;
return 0 ;
}
}
V_2 -> V_13 [ V_3 ] . V_6 = V_6 ;
V_2 -> V_13 [ V_3 ] . V_7 = V_7 ;
V_2 -> V_13 [ V_3 ] . V_8 = V_8 ;
V_2 -> V_13 [ V_3 ] . V_9 = V_16 ;
V_2 -> V_13 [ V_3 ] . V_10 = ( V_17 & 0x000000FF ) ;
break;
}
if ( V_3 == V_12 ) {
F_10 ( V_19 , L_6 ,
V_2 -> V_4 , ( unsigned long long ) V_6 ,
V_7 , V_8 , V_16 , V_17 ) ;
F_1 ( V_2 ) ;
return - 1 ;
}
return 0 ;
}
int F_11 ( struct V_18 * V_19 , struct V_1 * V_2 ,
struct V_26 * V_27 , int * V_28 )
{
int V_3 ;
* V_28 = 0 ;
if ( ! V_2 -> V_13 [ 0 ] . V_6 )
return - V_29 ;
memcpy ( V_27 , & V_2 -> V_13 [ 0 ] , sizeof( struct V_26 ) ) ;
memset ( & V_2 -> V_13 [ 0 ] , 0 , sizeof( struct V_26 ) ) ;
for ( V_3 = 1 ; V_3 < V_12 ; V_3 ++ ) {
if ( ! V_2 -> V_13 [ V_3 ] . V_6 )
break;
memcpy ( & V_2 -> V_13 [ V_3 - 1 ] , & V_2 -> V_13 [ V_3 ] ,
sizeof( struct V_26 ) ) ;
memset ( & V_2 -> V_13 [ V_3 ] , 0 , sizeof( struct V_26 ) ) ;
( * V_28 ) ++ ;
}
if ( ( V_27 -> V_7 & V_24 ) && V_2 -> V_11 . V_6 ) {
if ( F_12 ( V_27 -> V_8 , V_2 -> V_11 . V_8 ) ) {
V_27 -> V_7 |= V_30 ;
F_9 ( V_19 , L_7
L_8 ,
V_2 -> V_4 ,
( unsigned long long ) V_27 -> V_6 ,
V_27 -> V_8 ,
( unsigned long long ) V_2 -> V_11 . V_6 ,
V_2 -> V_11 . V_8 ) ;
return 0 ;
}
}
if ( V_27 -> V_7 & V_31 ) {
memcpy ( & V_2 -> V_11 , V_27 , sizeof( struct V_26 ) ) ;
V_2 -> V_32 = F_13 () ;
}
if ( V_27 -> V_7 & V_24 ) {
memcpy ( & V_2 -> V_5 , V_27 , sizeof( struct V_26 ) ) ;
V_2 -> V_33 = F_13 () ;
}
return 0 ;
}
void F_14 ( struct V_1 * V_2 , T_1 V_7 , int V_8 , int V_16 ,
T_1 V_17 )
{
T_2 V_6 ;
int V_34 ;
F_4 ( & V_14 ) ;
V_6 = ++ V_35 ;
if ( V_2 -> V_36 & V_37 ) {
F_7 ( & V_14 ) ;
F_15 ( V_2 , V_7 , V_8 , V_16 , V_17 , V_6 ) ;
return;
}
V_34 = F_8 ( V_2 , V_7 , V_8 , V_16 , V_17 , V_6 ) ;
if ( V_34 < 0 ) {
F_7 ( & V_14 ) ;
return;
}
if ( F_5 ( & V_2 -> V_15 ) ) {
F_16 ( & V_2 -> V_38 ) ;
F_17 ( & V_2 -> V_15 , & V_39 ) ;
}
F_7 ( & V_14 ) ;
F_18 ( V_40 , & V_41 ) ;
F_19 ( V_42 ) ;
}
static void F_20 ( void )
{
struct V_18 * V_19 = NULL ;
struct V_43 * V_44 = NULL ;
struct V_1 * V_2 ;
void (* F_21) ( void * V_45 );
void (* F_22) ( void * V_45 , int V_8 );
struct V_26 V_46 [ V_12 ] ;
int V_3 , V_34 , V_28 ;
V_47:
F_4 ( & V_14 ) ;
F_23 (lkb, &ast_queue, lkb_astqueue) {
V_44 = V_2 -> V_20 ;
V_19 = V_44 -> V_21 ;
if ( F_24 ( V_19 ) )
continue;
F_6 ( & V_2 -> V_15 ) ;
F_21 = V_2 -> V_48 ;
F_22 = V_2 -> V_49 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
for ( V_3 = 0 ; V_3 < V_12 ; V_3 ++ ) {
V_34 = F_11 ( V_19 , V_2 , & V_46 [ V_3 ] , & V_28 ) ;
if ( V_34 < 0 )
break;
}
F_7 ( & V_14 ) ;
if ( V_28 ) {
F_10 ( V_19 , L_9 ,
V_28 , V_2 -> V_4 ) ;
}
for ( V_3 = 0 ; V_3 < V_12 ; V_3 ++ ) {
if ( ! V_46 [ V_3 ] . V_6 )
break;
if ( V_46 [ V_3 ] . V_7 & V_30 ) {
continue;
} else if ( V_46 [ V_3 ] . V_7 & V_24 ) {
F_22 ( V_2 -> V_50 , V_46 [ V_3 ] . V_8 ) ;
} else if ( V_46 [ V_3 ] . V_7 & V_31 ) {
V_2 -> V_51 -> V_9 = V_46 [ V_3 ] . V_9 ;
V_2 -> V_51 -> V_10 = V_46 [ V_3 ] . V_10 ;
F_21 ( V_2 -> V_50 ) ;
}
}
F_25 ( V_2 ) ;
F_26 () ;
goto V_47;
}
F_7 ( & V_14 ) ;
}
static inline int F_27 ( void )
{
int V_52 ;
F_4 ( & V_14 ) ;
V_52 = F_5 ( & V_39 ) ;
F_7 ( & V_14 ) ;
return V_52 ;
}
static int F_28 ( void * V_53 )
{
while ( ! F_29 () ) {
F_30 ( V_54 ) ;
if ( ! F_31 ( V_40 , & V_41 ) )
F_32 () ;
F_30 ( V_55 ) ;
F_33 ( & V_56 ) ;
if ( F_34 ( V_40 , & V_41 ) )
F_20 () ;
F_35 ( & V_56 ) ;
}
return 0 ;
}
void F_36 ( void )
{
if ( ! F_27 () ) {
F_18 ( V_40 , & V_41 ) ;
F_19 ( V_42 ) ;
}
}
int F_37 ( void )
{
struct V_57 * V_58 ;
int error = 0 ;
F_38 ( & V_39 ) ;
F_39 ( & V_14 ) ;
F_40 ( & V_56 ) ;
V_58 = F_41 ( F_28 , NULL , L_10 ) ;
if ( F_42 ( V_58 ) )
error = F_43 ( V_58 ) ;
else
V_42 = V_58 ;
return error ;
}
void F_44 ( void )
{
F_45 ( V_42 ) ;
}
void F_46 ( void )
{
F_33 ( & V_56 ) ;
}
void F_47 ( void )
{
F_35 ( & V_56 ) ;
}
