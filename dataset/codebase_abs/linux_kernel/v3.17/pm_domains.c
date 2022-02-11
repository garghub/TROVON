static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 ;
void T_1 * V_6 ;
T_2 V_7 , V_8 ;
char * V_9 ;
V_5 = F_2 ( V_2 , struct V_4 , V_5 ) ;
V_6 = V_5 -> V_6 ;
if ( ! V_3 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( F_3 ( V_5 -> V_12 [ V_10 ] ) )
break;
if ( F_4 ( V_5 -> V_12 [ V_10 ] , V_5 -> V_13 ) )
F_5 ( L_1 ,
V_5 -> V_14 , V_10 ) ;
}
}
V_8 = V_3 ? V_15 : 0 ;
F_6 ( V_8 , V_6 ) ;
V_7 = 10 ;
while ( ( F_7 ( V_6 + 0x4 ) & V_15 ) != V_8 ) {
if ( ! V_7 ) {
V_9 = ( V_3 ) ? L_2 : L_3 ;
F_5 ( L_4 , V_2 -> V_14 , V_9 ) ;
return - V_16 ;
}
V_7 -- ;
F_8 () ;
F_9 ( 80 , 100 ) ;
}
if ( V_3 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( F_3 ( V_5 -> V_12 [ V_10 ] ) )
break;
if ( F_4 ( V_5 -> V_12 [ V_10 ] , V_5 -> V_17 [ V_10 ] ) )
F_5 ( L_5 ,
V_5 -> V_14 , V_10 ) ;
}
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , true ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , false ) ;
}
static void F_12 ( struct V_4 * V_5 ,
struct V_18 * V_19 )
{
int V_20 ;
F_13 ( V_19 , L_6 , V_5 -> V_5 . V_14 ) ;
while ( 1 ) {
V_20 = F_14 ( & V_5 -> V_5 , V_19 ) ;
if ( V_20 != - V_21 )
break;
F_15 () ;
}
F_16 ( V_19 , true ) ;
}
static void F_17 ( struct V_18 * V_19 )
{
struct V_1 * V_22 = F_18 ( V_19 ) ;
int V_20 ;
F_13 ( V_19 , L_7 , V_22 -> V_14 ) ;
while ( 1 ) {
V_20 = F_19 ( V_22 , V_19 ) ;
if ( V_20 != - V_21 )
break;
F_15 () ;
}
}
static void F_20 ( struct V_18 * V_19 )
{
struct V_23 * V_24 ;
struct V_4 * V_5 ;
struct V_25 * V_26 ;
V_26 = F_21 ( V_19 -> V_27 , L_8 , 0 ) ;
if ( ! V_26 )
return;
V_24 = F_22 ( V_26 ) ;
if ( ! V_24 )
return;
V_5 = F_23 ( V_24 ) ;
F_12 ( V_5 , V_19 ) ;
}
static int F_24 ( struct V_28 * V_29 ,
unsigned long V_30 , void * V_31 )
{
struct V_18 * V_19 = V_31 ;
switch ( V_30 ) {
case V_32 :
if ( V_19 -> V_27 )
F_20 ( V_19 ) ;
break;
case V_33 :
F_17 ( V_19 ) ;
break;
}
return V_34 ;
}
static T_3 int F_25 ( void )
{
struct V_23 * V_35 ;
struct V_25 * V_36 ;
F_26 (np, NULL, L_9 ) {
struct V_4 * V_5 ;
int V_37 , V_10 ;
struct V_18 * V_19 ;
V_35 = F_22 ( V_36 ) ;
V_19 = & V_35 -> V_19 ;
V_5 = F_27 ( sizeof( * V_5 ) , V_38 ) ;
if ( ! V_5 ) {
F_5 ( L_10 ,
V_39 ) ;
return - V_40 ;
}
V_5 -> V_5 . V_14 = F_28 ( V_36 -> V_14 , V_38 ) ;
V_5 -> V_14 = V_5 -> V_5 . V_14 ;
V_5 -> V_6 = F_29 ( V_36 , 0 ) ;
V_5 -> V_5 . V_41 = F_11 ;
V_5 -> V_5 . V_3 = F_10 ;
V_5 -> V_5 . V_27 = V_36 ;
V_5 -> V_13 = F_30 ( V_19 , L_11 ) ;
if ( F_3 ( V_5 -> V_13 ) )
goto V_42;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
char V_43 [ 8 ] ;
snprintf ( V_43 , sizeof( V_43 ) , L_12 , V_10 ) ;
V_5 -> V_12 [ V_10 ] = F_30 ( V_19 , V_43 ) ;
if ( F_3 ( V_5 -> V_12 [ V_10 ] ) )
break;
snprintf ( V_43 , sizeof( V_43 ) , L_13 , V_10 ) ;
V_5 -> V_17 [ V_10 ] = F_30 ( V_19 , V_43 ) ;
if ( F_3 ( V_5 -> V_17 [ V_10 ] ) ) {
F_31 ( V_5 -> V_12 [ V_10 ] ) ;
V_5 -> V_12 [ V_10 ] = F_32 ( - V_44 ) ;
break;
}
}
if ( F_3 ( V_5 -> V_12 [ 0 ] ) )
F_31 ( V_5 -> V_13 ) ;
V_42:
F_33 ( V_35 , V_5 ) ;
V_37 = F_7 ( V_5 -> V_6 + 0x4 ) & V_15 ;
F_34 ( & V_5 -> V_5 , NULL , ! V_37 ) ;
}
F_35 ( & V_45 , & V_46 ) ;
return 0 ;
}
