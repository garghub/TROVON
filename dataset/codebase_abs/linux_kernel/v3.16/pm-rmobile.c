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
return true ;
}
static void F_11 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_23 * V_24 = V_4 -> V_24 ;
F_12 ( V_2 , V_24 ? : & V_25 , false ) ;
V_2 -> V_26 . V_27 = V_28 ;
V_2 -> V_26 . V_29 = V_30 ;
V_2 -> V_26 . V_31 = F_10 ;
V_2 -> V_32 = true ;
V_2 -> V_33 = F_1 ;
V_2 -> V_34 = F_9 ;
F_7 ( V_4 , false ) ;
}
void F_13 ( struct V_3 V_35 [] , int V_36 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ )
F_11 ( & V_35 [ V_37 ] ) ;
}
void F_14 ( const char * V_38 ,
struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_21 * V_22 = & V_40 -> V_22 ;
F_15 ( V_38 , V_22 , V_42 ) ;
if ( F_16 ( V_22 ) )
F_17 ( V_22 , NULL ) ;
}
void F_18 ( struct V_43 V_44 [] ,
int V_45 )
{
struct V_41 V_46 = {
. V_47 = V_48 ,
. V_49 = V_48 ,
. V_50 = V_48 ,
. V_51 = V_48 ,
} ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_45 ; V_37 ++ )
F_14 ( V_44 [ V_37 ] . V_38 ,
V_44 [ V_37 ] . V_40 , & V_46 ) ;
}
