struct V_1 *
F_1 ( const char * V_2 , T_1 V_3 ,
int V_4 , void * V_5 , unsigned int V_6 )
{
struct V_1 * V_7 ;
int V_8 ;
V_7 = F_2 ( sizeof *V_7 , V_9 ) ;
if ( ! V_7 )
return F_3 ( - V_10 ) ;
V_7 -> V_7 . V_11 = V_2 ;
V_7 -> V_12 . V_13 = V_3 ;
V_7 -> V_12 . V_14 = V_3 + V_15 - 1 ;
V_7 -> V_12 . V_16 = V_17 ;
V_7 -> V_18 = F_4 ( 32 ) ;
V_7 -> V_7 . V_19 = F_4 ( 32 ) ;
V_7 -> V_4 [ 0 ] = V_4 ;
V_7 -> V_4 [ 1 ] = V_20 ;
V_7 -> V_6 = V_6 ;
V_7 -> V_7 . V_21 = V_5 ;
V_8 = F_5 ( V_7 , & V_22 ) ;
if ( V_8 ) {
F_6 ( V_7 ) ;
return F_3 ( V_8 ) ;
}
return V_7 ;
}
static struct V_23 *
F_7 ( const char * V_2 , int V_24 , void * V_5 ,
struct V_25 * V_12 , int V_26 )
{
struct V_23 * V_7 ;
int V_8 ;
V_7 = F_8 ( V_2 , V_24 ) ;
if ( ! V_7 )
return F_3 ( - V_10 ) ;
V_7 -> V_7 . V_19 = F_4 ( 32 ) ;
V_7 -> V_7 . V_18 = & V_7 -> V_7 . V_19 ;
V_8 = F_9 ( V_7 , V_12 , V_26 ) ;
if ( V_8 )
goto V_27;
V_7 -> V_7 . V_21 = V_5 ;
V_8 = F_10 ( V_7 ) ;
if ( V_8 )
goto V_27;
return V_7 ;
V_27:
F_11 ( V_7 ) ;
return F_3 ( V_8 ) ;
}
struct V_23 *
F_12 ( const char * V_2 , int V_24 ,
T_1 V_3 ,
int V_4 , void * V_5 )
{
struct V_25 V_28 [] = {
[ 0 ] = {
. V_13 = V_3 ,
. V_14 = V_3 + V_15 - 1 ,
. V_16 = V_17 ,
} ,
[ 1 ] = {
. V_13 = V_4 ,
. V_14 = V_4 ,
. V_16 = V_29 ,
}
} ;
return F_7 ( V_2 , V_24 , V_5 , V_28 ,
F_13 ( V_28 ) ) ;
}
static struct V_23 *
F_14 ( int V_24 , T_1 V_30 , int V_4 ,
struct V_31 * V_5 )
{
struct V_25 V_28 [] = {
{
. V_13 = V_30 ,
. V_14 = V_30 + 127 ,
. V_16 = V_17 ,
} ,
{
. V_13 = V_4 ,
. V_14 = V_4 ,
. V_16 = V_29 ,
}
} ;
return F_15 ( NULL , L_1 , V_24 ,
V_28 , F_13 ( V_28 ) ,
V_5 , sizeof( * V_5 ) ) ;
}
void F_16 ( T_1 * V_3 , int V_32 , int V_4 ,
struct V_31 * V_5 )
{
int V_33 = 0 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ , V_33 += 32 , V_4 ++ ) {
V_5 -> V_35 = V_33 ;
V_5 -> V_36 = F_17 ( V_33 ) ;
V_5 -> V_37 = 32 ;
F_14 ( V_34 , V_3 [ V_34 ] , V_4 , V_5 ) ;
}
}
