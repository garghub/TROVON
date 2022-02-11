void F_1 ( T_1 V_1 )
{
int V_2 , V_3 = 0 ;
T_2 V_4 = V_5 . V_4 ;
if ( ! F_2 () && ( V_1 & V_4 ) ) {
V_6 = V_1 ;
F_3 ( & V_7 ) ;
return;
}
while ( V_1 & V_4 ) {
V_3 = F_4 ( V_1 ) - 1 ;
if ( F_5 ( V_3 ) & V_4 ) {
V_2 = F_6 ( V_5 . V_8 ,
V_3 ) ;
if ( V_2 )
F_7 ( V_2 ) ;
}
V_1 &= ~ F_5 ( V_3 ) ;
}
}
static void F_8 ( struct V_9 * V_10 )
{
F_9 ( V_10 -> V_3 , & V_5 . V_4 ) ;
}
static void F_10 ( struct V_9 * V_10 )
{
T_3 V_1 ;
F_11 ( V_10 -> V_3 , & V_5 . V_4 ) ;
F_12 ( & V_1 ) ;
V_6 = F_13 ( V_1 ) ;
if ( V_6 & V_5 . V_4 )
F_3 ( & V_7 ) ;
}
static int F_14 ( struct V_9 * V_10 , unsigned int V_11 )
{
if ( V_11 != V_12 )
return - V_13 ;
return 0 ;
}
static int F_15 ( struct V_14 * V_10 , unsigned int V_15 ,
T_4 V_3 )
{
F_16 ( V_15 , & V_5 ) ;
F_17 ( V_15 , & V_5 . V_16 ,
V_17 ) ;
return 0 ;
}
static T_5 F_18 ( int V_15 , void * V_18 )
{
T_3 V_1 ;
F_19 ( F_20 ( V_15 ) , & V_1 ) ;
F_1 ( F_13 ( V_1 ) ) ;
return V_19 ;
}
static void F_21 ( struct V_20 * V_21 )
{
F_1 ( V_6 ) ;
}
static int F_22 ( struct V_14 * V_22 , struct V_23 * V_24 ,
enum V_25 V_26 )
{
return F_23 ( V_22 ) == V_24 ;
}
static int F_24 ( struct V_14 * V_22 , struct V_23 * V_27 ,
const T_6 * V_28 , unsigned int V_29 ,
T_4 * V_30 , unsigned int * V_31 )
{
* V_30 = V_28 [ 0 ] ;
* V_31 = V_12 ;
return 0 ;
}
void F_25 ( void )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
if ( V_34 [ V_32 ] )
F_26 ( V_34 [ V_32 ] , NULL ) ;
V_34 [ V_32 ] = 0 ;
}
}
int T_7 F_27 ( void )
{
struct V_23 * V_35 , * V_36 ;
const char * * V_37 ;
T_6 * V_38 ;
int V_32 , V_39 ;
V_36 = F_28 ( L_1 ) ;
if ( ! V_36 ) {
F_29 ( L_2 ) ;
return - V_40 ;
}
V_35 = F_30 ( NULL , NULL , L_3 ) ;
V_5 . V_8 = F_31 ( V_35 , V_41 ,
& V_42 , & V_5 ) ;
F_32 ( V_35 ) ;
if ( ! V_5 . V_8 ) {
F_29 ( L_4 ) ;
V_39 = - V_43 ;
goto V_44;
}
V_39 = F_33 ( V_36 , L_5 ) ;
if ( V_39 < 0 )
goto V_44;
V_33 = V_39 ;
F_34 ( L_6 , V_33 ) ;
V_38 = F_35 ( V_33 , sizeof( * V_38 ) , V_45 ) ;
V_37 = F_35 ( V_33 , sizeof( * V_37 ) , V_45 ) ;
V_34 = F_35 ( V_33 , sizeof( * V_34 ) , V_45 ) ;
if ( F_36 ( ! V_38 || ! V_37 || ! V_34 ) )
goto V_46;
V_39 = F_37 ( V_36 , L_5 ,
V_38 , V_33 ) ;
if ( V_39 < 0 ) {
F_38 ( L_7 , V_39 ) ;
goto V_46;
}
F_39 ( V_36 , L_8 ,
V_37 , V_33 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
unsigned int V_2 ;
char * V_47 ;
V_2 = F_40 ( NULL , V_38 [ V_32 ] ) ;
if ( ! V_2 ) {
F_29 ( L_9 , V_38 [ V_32 ] ) ;
continue;
}
if ( V_37 [ V_32 ] && strlen ( V_37 [ V_32 ] ) )
V_47 = F_41 ( V_45 , L_10 , V_37 [ V_32 ] ) ;
else
V_47 = F_41 ( V_45 , L_11 ) ;
V_39 = F_42 ( V_2 , F_18 , V_48 ,
V_47 , NULL ) ;
if ( V_39 ) {
F_43 ( V_2 ) ;
F_29 ( L_12 ,
V_39 , V_2 , V_38 [ V_32 ] ) ;
continue;
}
V_34 [ V_32 ] = V_2 ;
}
V_46:
F_44 ( V_38 ) ;
F_44 ( V_37 ) ;
V_44:
F_32 ( V_36 ) ;
return V_39 ;
}
int F_45 ( unsigned int V_49 )
{
if ( F_46 ( ! V_5 . V_8 ) )
return 0 ;
return F_40 ( V_5 . V_8 , V_49 ) ;
}
