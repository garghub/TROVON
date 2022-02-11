static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_8 ;
int V_9 = V_8 -> V_9 ;
int V_10 = V_8 -> V_10 ;
int V_11 ;
F_2 ( V_2 , L_1 ) ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
if ( V_11 == V_10 ) {
F_3 ( V_2 , L_2 ,
V_11 , '-' , '-' , '-' ) ;
} else {
F_3 ( V_2 , L_3 ,
V_11 ,
V_12 [ F_4 ( V_8 , V_11 ) ] ,
F_5 ( V_8 , V_11 ) ? 'Y' : 'N' ,
F_6 ( V_8 -> V_13 . V_14 , V_11 ) ? 'Y' : 'N' ) ;
}
}
return 0 ;
}
static int F_7 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
return F_8 ( V_16 , F_1 , V_15 -> V_17 ) ;
}
void F_9 ( struct V_4 * V_5 )
{
const char * V_18 = F_10 ( & V_5 -> V_19 -> V_20 ) ;
struct V_21 * V_22 ;
V_5 -> V_23 = F_11 ( V_18 , V_24 ) ;
if ( ! V_5 -> V_23 ) {
F_12 ( & V_5 -> V_19 -> V_20 ,
L_4 , V_18 ) ;
return;
}
V_22 = F_13 ( L_5 , 0444 , V_5 -> V_23 ,
V_5 , & V_25 ) ;
if ( ! V_22 )
F_12 ( & V_5 -> V_19 -> V_20 ,
L_6 , V_18 ) ;
}
void F_14 ( struct V_4 * V_5 )
{
F_15 ( V_5 -> V_23 ) ;
V_5 -> V_23 = NULL ;
}
void F_16 ( void )
{
V_24 = F_11 ( V_26 , NULL ) ;
if ( ! V_24 )
F_17 ( L_7 ) ;
}
void F_18 ( void )
{
F_15 ( V_24 ) ;
V_24 = NULL ;
}
