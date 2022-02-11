static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 V_9 = V_7 -> V_10 + 1 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ )
V_4 -> V_12 . V_13 [ V_11 ] . V_14 = V_11 ;
if ( F_2 ( V_4 -> V_15 ,
V_4 -> V_12 . V_13 ,
V_9 ) ) {
F_3 ( L_1 ) ;
return - V_16 ;
}
return 0 ;
}
static void F_4 ( struct V_3 * V_4 )
{
F_5 ( V_4 -> V_15 ) ;
}
static T_2 F_6 ( int V_17 , void * V_18 )
{
struct V_19 * V_20 = V_18 ;
F_7 ( V_20 -> V_21 , V_20 -> V_22 , 0 ) ;
F_8 ( & V_20 -> V_23 ) ;
return V_24 ;
}
static T_2 F_9 ( int V_17 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
F_10 ( L_2 , V_2 -> V_26 ) ;
return V_24 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_27 * V_28 = V_4 -> V_12 . V_13 ;
struct V_29 * V_30 = V_2 -> V_31 ;
int V_32 , V_11 ;
char * V_33 ;
for ( V_11 = 0 ; V_11 < V_7 -> V_10 ; V_11 ++ ) {
struct V_19 * V_20 = & V_30 -> V_34 [ V_11 ] ;
unsigned int V_35 , V_36 = F_12 () ;
V_33 = * ( V_4 -> V_12 . V_37 + V_11 ) ;
snprintf ( V_33 , V_38 ,
L_3 , V_2 -> V_26 , V_11 ) ;
V_32 = F_13 ( V_28 [ V_11 ] . V_39 ,
F_6 , 0 , V_33 , V_20 ) ;
if ( V_32 ) {
F_3 ( L_4 ,
V_28 [ V_11 ] . V_39 , V_33 ) ;
return V_32 ;
}
V_35 = ( ( V_2 -> V_26 * V_7 -> V_10 ) + V_11 ) % V_36 ;
F_14 ( V_28 [ V_11 ] . V_39 , F_15 ( V_35 ) ) ;
}
V_33 = * ( V_4 -> V_12 . V_37 + V_11 ) ;
snprintf ( V_33 , V_38 ,
L_5 , V_2 -> V_26 ) ;
V_32 = F_13 ( V_28 [ V_11 ] . V_39 , F_9 , 0 , V_33 , V_2 ) ;
if ( V_32 ) {
F_3 ( L_6 ,
V_28 [ V_11 ] . V_39 , V_33 ) ;
return V_32 ;
}
return V_32 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_27 * V_28 = V_4 -> V_12 . V_13 ;
struct V_29 * V_30 = V_2 -> V_31 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_7 -> V_10 ; V_11 ++ ) {
F_14 ( V_28 [ V_11 ] . V_39 , NULL ) ;
F_17 ( V_28 [ V_11 ] . V_39 , & V_30 -> V_34 [ V_11 ] ) ;
}
F_14 ( V_28 [ V_11 ] . V_39 , NULL ) ;
F_17 ( V_28 [ V_11 ] . V_39 , V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_11 ;
char * * V_37 ;
struct V_27 * V_13 ;
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 V_9 = V_7 -> V_10 + 1 ;
V_13 = F_19 ( V_9 * sizeof( * V_13 ) ,
V_40 , F_20 ( & F_21 ( V_2 ) ) ) ;
if ( ! V_13 )
return - V_41 ;
V_37 = F_22 ( V_9 , sizeof( char * ) , V_40 ) ;
if ( ! V_37 ) {
F_23 ( V_13 ) ;
return - V_41 ;
}
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
* ( V_37 + V_11 ) = F_24 ( V_38 , V_40 ) ;
if ( ! ( * ( V_37 + V_11 ) ) )
goto V_42;
}
V_2 -> V_5 . V_12 . V_13 = V_13 ;
V_2 -> V_5 . V_12 . V_37 = V_37 ;
return 0 ;
V_42:
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ )
F_23 ( * ( V_37 + V_11 ) ) ;
F_23 ( V_13 ) ;
F_23 ( V_37 ) ;
return - V_41 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 V_9 = V_7 -> V_10 + 1 ;
char * * V_37 = V_2 -> V_5 . V_12 . V_37 ;
int V_11 ;
F_23 ( V_2 -> V_5 . V_12 . V_13 ) ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ )
F_23 ( * ( V_37 + V_11 ) ) ;
F_23 ( V_37 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_29 * V_43 = V_2 -> V_31 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_7 -> V_10 ; V_11 ++ )
F_27 ( & V_43 -> V_34 [ V_11 ] . V_23 ,
V_44 ,
( unsigned long ) & V_43 -> V_34 [ V_11 ] ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_29 * V_43 = V_2 -> V_31 ;
struct V_6 * V_7 = V_2 -> V_8 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_7 -> V_10 ; V_11 ++ ) {
F_29 ( & V_43 -> V_34 [ V_11 ] . V_23 ) ;
F_30 ( & V_43 -> V_34 [ V_11 ] . V_23 ) ;
}
}
void F_31 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_28 ( V_2 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_25 ( V_2 ) ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_32 ;
V_32 = F_18 ( V_2 ) ;
if ( V_32 )
return V_32 ;
if ( F_1 ( V_2 ) )
goto V_45;
if ( F_26 ( V_2 ) )
goto V_45;
if ( F_11 ( V_2 ) )
goto V_45;
return 0 ;
V_45:
F_31 ( V_2 ) ;
return - V_16 ;
}
