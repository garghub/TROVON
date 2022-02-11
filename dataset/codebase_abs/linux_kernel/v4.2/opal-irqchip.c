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
static int F_22 ( struct V_11 * V_22 , struct V_23 * V_24 )
{
return V_22 -> V_25 == V_24 ;
}
static int F_23 ( struct V_11 * V_22 , struct V_23 * V_26 ,
const T_6 * V_27 , unsigned int V_28 ,
T_1 * V_29 , unsigned int * V_30 )
{
* V_29 = V_27 [ 0 ] ;
* V_30 = V_9 ;
return 0 ;
}
void F_24 ( void )
{
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
if ( V_33 [ V_31 ] )
F_25 ( V_33 [ V_31 ] , NULL ) ;
V_33 [ V_31 ] = 0 ;
}
}
int T_7 F_26 ( void )
{
struct V_23 * V_34 , * V_35 ;
const T_8 * V_36 ;
int V_31 , V_37 , V_38 = 0 ;
V_35 = F_27 ( L_1 ) ;
if ( ! V_35 ) {
F_28 ( L_2 ) ;
return - V_39 ;
}
V_34 = F_29 ( NULL , NULL , L_3 ) ;
V_4 . V_17 = F_30 ( V_34 , V_40 ,
& V_41 , & V_4 ) ;
F_31 ( V_34 ) ;
if ( ! V_4 . V_17 ) {
F_28 ( L_4 ) ;
V_38 = - V_42 ;
goto V_43;
}
V_36 = F_32 ( V_35 , L_5 , & V_37 ) ;
V_32 = V_36 ? ( V_37 / 4 ) : 0 ;
F_33 ( L_6 , V_32 ) ;
V_33 = F_34 ( V_32 , sizeof( * V_33 ) , V_44 ) ;
for ( V_31 = 0 ; V_36 && V_31 < V_32 ; V_31 ++ , V_36 ++ ) {
unsigned int V_12 , V_16 ;
V_12 = F_35 ( V_36 ) ;
V_16 = F_36 ( NULL , V_12 ) ;
if ( V_16 == V_45 ) {
F_28 ( L_7 , V_12 ) ;
continue;
}
V_38 = F_37 ( V_16 , F_17 , 0 , L_8 , NULL ) ;
if ( V_38 ) {
F_38 ( V_16 ) ;
F_28 ( L_9 ,
V_38 , V_16 , V_12 ) ;
continue;
}
V_33 [ V_31 ] = V_16 ;
}
V_43:
F_31 ( V_35 ) ;
return V_38 ;
}
int F_39 ( unsigned int V_46 )
{
if ( F_40 ( ! V_4 . V_17 ) )
return V_45 ;
return F_36 ( V_4 . V_17 , V_46 ) ;
}
