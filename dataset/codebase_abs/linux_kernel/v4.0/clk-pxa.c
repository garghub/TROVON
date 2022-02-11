static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
if ( ! V_5 -> V_8 || V_5 -> V_8 () )
V_7 = & V_5 -> V_9 ;
else
V_7 = & V_5 -> V_10 ;
F_3 ( & V_7 -> V_2 , V_2 ) ;
return V_11 . V_12 ( & V_7 -> V_2 , V_3 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_8 )
return 0 ;
return V_5 -> V_8 () ? 0 : 1 ;
}
void T_2 F_5 ( int V_13 , const char * V_14 ,
const char * V_15 , struct V_16 * V_16 )
{
if ( ! F_6 ( V_16 ) && ( V_13 != V_17 ) )
V_18 [ V_13 ] = V_16 ;
if ( ! F_6 ( V_16 ) )
F_7 ( V_16 , V_14 , V_15 ) ;
}
int T_2 F_8 ( const struct V_19 * V_20 , int V_21 )
{
int V_22 ;
struct V_4 * V_4 ;
struct V_16 * V_16 ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ ) {
V_4 = F_9 ( sizeof( * V_4 ) , V_23 ) ;
V_4 -> V_8 = V_20 [ V_22 ] . V_8 ;
V_4 -> V_9 = V_20 [ V_22 ] . V_9 ;
V_4 -> V_10 = V_20 [ V_22 ] . V_10 ;
V_4 -> V_24 = V_20 [ V_22 ] . V_24 ;
V_4 -> V_24 . V_25 = & V_25 ;
V_16 = F_10 ( NULL , V_20 [ V_22 ] . V_26 ,
V_20 [ V_22 ] . V_27 , 2 ,
& V_4 -> V_2 , & V_28 ,
& V_4 -> V_2 , & V_29 ,
& V_4 -> V_24 . V_2 , & V_30 ,
V_20 [ V_22 ] . V_31 ) ;
F_5 ( V_20 [ V_22 ] . V_13 , V_20 [ V_22 ] . V_14 ,
V_20 [ V_22 ] . V_15 , V_16 ) ;
}
return 0 ;
}
void T_2 F_11 ( struct V_32 * V_33 )
{
F_12 ( V_33 , V_34 , & V_35 ) ;
}
