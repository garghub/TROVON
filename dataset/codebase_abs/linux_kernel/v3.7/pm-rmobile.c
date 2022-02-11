static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = 1 << V_4 -> V_6 ;
if ( V_4 -> V_7 ) {
int V_8 = V_4 -> V_7 () ;
if ( V_8 )
return V_8 ;
}
if ( F_3 ( V_9 ) & V_5 ) {
unsigned int V_10 ;
F_4 ( V_5 , V_11 ) ;
for ( V_10 = V_12 ; V_10 ; V_10 -- ) {
if ( ! ( F_3 ( V_11 ) & V_5 ) )
break;
F_5 () ;
}
}
if ( ! V_4 -> V_13 )
F_6 ( L_1 ,
V_2 -> V_14 , V_5 , F_3 ( V_9 ) ) ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 ,
bool V_15 )
{
unsigned int V_5 = 1 << V_4 -> V_6 ;
unsigned int V_10 ;
int V_8 = 0 ;
if ( F_3 ( V_9 ) & V_5 )
goto V_16;
F_4 ( V_5 , V_17 ) ;
for ( V_10 = 2 * V_12 ; V_10 ; V_10 -- ) {
if ( ! ( F_3 ( V_17 ) & V_5 ) )
break;
if ( V_10 > V_12 )
F_8 ( V_18 ) ;
else
F_5 () ;
}
if ( ! V_10 )
V_8 = - V_19 ;
if ( ! V_4 -> V_13 )
F_6 ( L_2 ,
V_4 -> V_2 . V_14 , V_5 , F_3 ( V_9 ) ) ;
V_16:
if ( V_8 == 0 && V_4 -> V_20 && V_15 )
V_4 -> V_20 () ;
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_7 ( F_2 ( V_2 ) , true ) ;
}
static bool F_10 ( struct V_21 * V_22 )
{
bool (* F_11)( struct V_21 * V_22 );
F_11 = F_12 ( V_22 ) -> V_23 . F_11 ;
return F_11 ? F_11 ( V_22 ) : true ;
}
static int F_13 ( struct V_21 * V_22 )
{
int (* F_14)( struct V_21 * V_22 );
F_14 = F_12 ( V_22 ) -> V_23 . F_14 ;
if ( F_14 ) {
int V_8 = F_14 ( V_22 ) ;
if ( V_8 )
return V_8 ;
}
return F_15 ( V_22 ) ;
}
static int F_16 ( struct V_21 * V_22 )
{
int (* F_17)( struct V_21 * V_22 );
int V_8 ;
V_8 = F_18 ( V_22 ) ;
if ( V_8 )
return V_8 ;
F_17 = F_12 ( V_22 ) -> V_23 . F_17 ;
if ( F_17 )
V_8 = F_17 ( V_22 ) ;
return V_8 ;
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_24 * V_25 = V_4 -> V_25 ;
F_20 ( V_2 , V_25 ? : & V_26 , false ) ;
V_2 -> V_27 . F_14 = F_13 ;
V_2 -> V_27 . F_17 = F_16 ;
V_2 -> V_27 . F_11 = F_10 ;
V_2 -> V_28 = true ;
V_2 -> V_29 = F_1 ;
V_2 -> V_30 = F_9 ;
F_7 ( V_4 , false ) ;
}
void F_21 ( struct V_3 V_31 [] , int V_32 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ )
F_19 ( & V_31 [ V_33 ] ) ;
}
void F_22 ( const char * V_34 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_21 * V_22 = & V_36 -> V_22 ;
F_23 ( V_34 , V_22 , V_38 ) ;
if ( F_24 ( V_22 ) )
F_25 ( V_22 , NULL ) ;
}
void F_26 ( struct V_39 V_40 [] ,
int V_41 )
{
struct V_37 V_42 = {
. V_43 = V_44 ,
. V_45 = V_44 ,
. V_46 = V_44 ,
. V_47 = V_44 ,
} ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_41 ; V_33 ++ )
F_22 ( V_40 [ V_33 ] . V_34 ,
V_40 [ V_33 ] . V_36 , & V_42 ) ;
}
