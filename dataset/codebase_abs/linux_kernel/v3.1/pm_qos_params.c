static inline int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( & V_2 -> V_3 ) )
return V_2 -> V_4 ;
switch ( V_2 -> type ) {
case V_5 :
return F_3 ( & V_2 -> V_3 ) -> V_6 ;
case V_7 :
return F_4 ( & V_2 -> V_3 ) -> V_6 ;
default:
F_5 () ;
}
}
static inline T_1 F_6 ( struct V_1 * V_2 )
{
return V_2 -> V_8 ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_9 )
{
V_2 -> V_8 = V_9 ;
}
static void F_8 ( struct V_1 * V_2 , struct V_10 * V_11 ,
int V_12 , int V_9 )
{
unsigned long V_13 ;
int V_14 , V_15 ;
F_9 ( & V_16 , V_13 ) ;
V_14 = F_1 ( V_2 ) ;
if ( V_9 != V_17 ) {
F_10 ( V_11 , & V_2 -> V_3 ) ;
F_11 ( V_11 , V_9 ) ;
F_12 ( V_11 , & V_2 -> V_3 ) ;
} else if ( V_12 ) {
F_10 ( V_11 , & V_2 -> V_3 ) ;
} else {
F_12 ( V_11 , & V_2 -> V_3 ) ;
}
V_15 = F_1 ( V_2 ) ;
F_7 ( V_2 , V_15 ) ;
F_13 ( & V_16 , V_13 ) ;
if ( V_14 != V_15 )
F_14 ( V_2 -> V_18 ,
( unsigned long ) V_15 ,
NULL ) ;
}
static int F_15 ( struct V_1 * V_19 )
{
V_19 -> V_20 . V_21 = V_22 ;
V_19 -> V_20 . V_23 = V_19 -> V_23 ;
V_19 -> V_20 . V_24 = & V_25 ;
return F_16 ( & V_19 -> V_20 ) ;
}
static int F_17 ( int V_21 )
{
int V_26 ;
for ( V_26 = 0 ;
V_26 < V_27 ; V_26 ++ ) {
if ( V_21 ==
V_28 [ V_26 ] -> V_20 . V_21 )
return V_26 ;
}
return - 1 ;
}
int F_18 ( int V_26 )
{
return F_6 ( V_28 [ V_26 ] ) ;
}
int F_19 ( struct V_29 * V_30 )
{
return V_30 -> V_26 != 0 ;
}
void F_20 ( struct V_29 * V_31 ,
int V_26 , T_1 V_9 )
{
struct V_1 * V_2 = V_28 [ V_26 ] ;
int V_32 ;
if ( F_19 ( V_31 ) ) {
F_21 ( 1 , V_33 L_1 ) ;
return;
}
if ( V_9 == V_17 )
V_32 = V_2 -> V_4 ;
else
V_32 = V_9 ;
F_11 ( & V_31 -> V_34 , V_32 ) ;
V_31 -> V_26 = V_26 ;
F_8 ( V_2 , & V_31 -> V_34 , 0 , V_17 ) ;
}
void F_22 ( struct V_29 * V_35 ,
T_1 V_32 )
{
T_1 V_36 ;
struct V_1 * V_2 ;
if ( ! V_35 )
return;
if ( ! F_19 ( V_35 ) ) {
F_21 ( 1 , V_33 L_2 ) ;
return;
}
V_2 = V_28 [ V_35 -> V_26 ] ;
if ( V_32 == V_17 )
V_36 = V_2 -> V_4 ;
else
V_36 = V_32 ;
if ( V_36 != V_35 -> V_34 . V_6 )
F_8 ( V_2 , & V_35 -> V_34 , 0 , V_36 ) ;
}
void F_23 ( struct V_29 * V_35 )
{
struct V_1 * V_2 ;
if ( V_35 == NULL )
return;
if ( ! F_19 ( V_35 ) ) {
F_21 ( 1 , V_33 L_3 ) ;
return;
}
V_2 = V_28 [ V_35 -> V_26 ] ;
F_8 ( V_2 , & V_35 -> V_34 , 1 , V_17 ) ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
}
int F_24 ( int V_26 , struct V_37 * V_38 )
{
int V_39 ;
V_39 = F_25 (
V_28 [ V_26 ] -> V_18 , V_38 ) ;
return V_39 ;
}
int F_26 ( int V_26 , struct V_37 * V_38 )
{
int V_39 ;
V_39 = F_27 (
V_28 [ V_26 ] -> V_18 , V_38 ) ;
return V_39 ;
}
static int F_28 ( struct V_40 * V_40 , struct V_41 * V_42 )
{
long V_26 ;
V_26 = F_17 ( F_29 ( V_40 ) ) ;
if ( V_26 >= 0 ) {
struct V_29 * V_30 = F_30 ( sizeof( * V_30 ) , V_43 ) ;
if ( ! V_30 )
return - V_44 ;
F_20 ( V_30 , V_26 , V_17 ) ;
V_42 -> V_45 = V_30 ;
if ( V_42 -> V_45 )
return 0 ;
}
return - V_46 ;
}
static int F_31 ( struct V_40 * V_40 , struct V_41 * V_42 )
{
struct V_29 * V_30 ;
V_30 = V_42 -> V_45 ;
F_23 ( V_30 ) ;
F_32 ( V_30 ) ;
return 0 ;
}
static T_2 F_33 ( struct V_41 * V_42 , char T_3 * V_47 ,
T_4 V_48 , T_5 * V_49 )
{
T_1 V_9 ;
unsigned long V_13 ;
struct V_1 * V_2 ;
struct V_29 * V_35 = V_42 -> V_45 ;
if ( ! V_35 )
return - V_50 ;
if ( ! F_19 ( V_35 ) )
return - V_50 ;
V_2 = V_28 [ V_35 -> V_26 ] ;
F_9 ( & V_16 , V_13 ) ;
V_9 = F_1 ( V_2 ) ;
F_13 ( & V_16 , V_13 ) ;
return F_34 ( V_47 , V_48 , V_49 , & V_9 , sizeof( T_1 ) ) ;
}
static T_2 F_35 ( struct V_41 * V_42 , const char T_3 * V_47 ,
T_4 V_48 , T_5 * V_49 )
{
T_1 V_9 ;
struct V_29 * V_35 ;
if ( V_48 == sizeof( T_1 ) ) {
if ( F_36 ( & V_9 , V_47 , sizeof( T_1 ) ) )
return - V_51 ;
} else if ( V_48 <= 11 ) {
char V_52 [ 11 ] ;
unsigned long int V_53 ;
int V_54 ;
if ( F_36 ( V_52 , V_47 , V_48 ) )
return - V_51 ;
if ( V_48 > 10 ) {
if ( V_52 [ 10 ] == '\n' )
V_52 [ 10 ] = '\0' ;
else
return - V_50 ;
} else {
V_52 [ V_48 ] = '\0' ;
}
V_54 = F_37 ( V_52 , 16 , & V_53 ) ;
if ( V_54 ) {
F_38 ( L_4 , V_52 , V_53 , V_54 ) ;
return - V_50 ;
}
V_9 = ( T_1 ) F_39 ( V_53 ) ;
} else {
return - V_50 ;
}
V_35 = V_42 -> V_45 ;
F_22 ( V_35 , V_9 ) ;
return V_48 ;
}
static int T_6 F_40 ( void )
{
int V_54 = 0 ;
V_54 = F_15 ( & V_55 ) ;
if ( V_54 < 0 ) {
F_41 ( V_33 L_5 ) ;
return V_54 ;
}
V_54 = F_15 ( & V_56 ) ;
if ( V_54 < 0 ) {
F_41 ( V_33 L_6 ) ;
return V_54 ;
}
V_54 = F_15 ( & V_57 ) ;
if ( V_54 < 0 )
F_41 ( V_33
L_7 ) ;
return V_54 ;
}
