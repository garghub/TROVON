static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , & V_4 . V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 , & V_4 . V_5 ) ;
F_5 ( & V_6 ) ;
if ( V_6 & V_4 . V_5 )
F_6 ( & V_7 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_8 )
{
if ( V_8 != V_9 )
return - V_10 ;
return 0 ;
}
static int F_8 ( struct V_11 * V_2 , unsigned int V_12 ,
T_1 V_3 )
{
F_9 ( V_12 , & V_4 ) ;
F_10 ( V_12 , & V_4 . V_13 ,
V_14 ) ;
return 0 ;
}
void F_11 ( T_2 V_15 )
{
int V_16 , V_3 = 0 ;
T_3 V_5 = V_4 . V_5 ;
if ( ! F_12 () && ( V_15 & V_5 ) ) {
V_6 = V_15 ;
F_6 ( & V_7 ) ;
return;
}
while ( V_15 & V_5 ) {
V_3 = F_13 ( V_15 ) - 1 ;
if ( F_14 ( V_3 ) & V_5 ) {
V_16 = F_15 ( V_4 . V_17 ,
V_3 ) ;
if ( V_16 )
F_16 ( V_16 ) ;
}
V_15 &= ~ F_14 ( V_3 ) ;
}
}
static T_4 F_17 ( int V_12 , void * V_18 )
{
T_5 V_15 ;
F_18 ( F_19 ( V_12 ) , & V_15 ) ;
F_11 ( F_20 ( V_15 ) ) ;
return V_19 ;
}
static void F_21 ( struct V_20 * V_21 )
{
F_11 ( F_20 ( V_6 ) ) ;
}
static int F_22 ( struct V_11 * V_22 , struct V_23 * V_24 ,
enum V_25 V_26 )
{
return V_22 -> V_27 == V_24 ;
}
static int F_23 ( struct V_11 * V_22 , struct V_23 * V_28 ,
const T_6 * V_29 , unsigned int V_30 ,
T_1 * V_31 , unsigned int * V_32 )
{
* V_31 = V_29 [ 0 ] ;
* V_32 = V_9 ;
return 0 ;
}
void F_24 ( void )
{
unsigned int V_33 ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
if ( V_35 [ V_33 ] )
F_25 ( V_35 [ V_33 ] , NULL ) ;
V_35 [ V_33 ] = 0 ;
}
}
int T_7 F_26 ( void )
{
struct V_23 * V_36 , * V_37 ;
const T_8 * V_38 ;
int V_33 , V_39 , V_40 = 0 ;
V_37 = F_27 ( L_1 ) ;
if ( ! V_37 ) {
F_28 ( L_2 ) ;
return - V_41 ;
}
V_36 = F_29 ( NULL , NULL , L_3 ) ;
V_4 . V_17 = F_30 ( V_36 , V_42 ,
& V_43 , & V_4 ) ;
F_31 ( V_36 ) ;
if ( ! V_4 . V_17 ) {
F_28 ( L_4 ) ;
V_40 = - V_44 ;
goto V_45;
}
V_38 = F_32 ( V_37 , L_5 , & V_39 ) ;
V_34 = V_38 ? ( V_39 / 4 ) : 0 ;
F_33 ( L_6 , V_34 ) ;
V_35 = F_34 ( V_34 , sizeof( * V_35 ) , V_46 ) ;
for ( V_33 = 0 ; V_38 && V_33 < V_34 ; V_33 ++ , V_38 ++ ) {
unsigned int V_12 , V_16 ;
V_12 = F_35 ( V_38 ) ;
V_16 = F_36 ( NULL , V_12 ) ;
if ( V_16 == V_47 ) {
F_28 ( L_7 , V_12 ) ;
continue;
}
V_40 = F_37 ( V_16 , F_17 , 0 , L_8 , NULL ) ;
if ( V_40 ) {
F_38 ( V_16 ) ;
F_28 ( L_9 ,
V_40 , V_16 , V_12 ) ;
continue;
}
V_35 [ V_33 ] = V_16 ;
}
V_45:
F_31 ( V_37 ) ;
return V_40 ;
}
int F_39 ( unsigned int V_48 )
{
if ( F_40 ( ! V_4 . V_17 ) )
return V_47 ;
return F_36 ( V_4 . V_17 , V_48 ) ;
}
