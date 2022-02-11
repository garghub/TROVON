static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
if ( ! V_5 -> V_8 || V_5 -> V_8 () )
V_7 = & V_5 -> V_9 ;
else
V_7 = & V_5 -> V_10 ;
V_7 -> V_2 . V_11 = V_2 -> V_11 ;
return V_12 . V_13 ( & V_7 -> V_2 , V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_8 )
return 0 ;
return V_5 -> V_8 () ? 0 : 1 ;
}
void T_2 F_4 ( int V_14 , const char * V_15 ,
const char * V_16 , struct V_11 * V_11 )
{
if ( ! F_5 ( V_11 ) && ( V_14 != V_17 ) )
V_18 [ V_14 ] = V_11 ;
if ( ! F_5 ( V_11 ) )
F_6 ( V_11 , V_15 , V_16 ) ;
}
int T_2 F_7 ( struct V_4 * V_19 , int V_20 )
{
int V_21 ;
struct V_4 * V_5 ;
struct V_11 * V_11 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
V_5 = V_19 + V_21 ;
V_5 -> V_22 . V_23 = & V_23 ;
V_11 = F_8 ( NULL , V_5 -> V_24 ,
V_5 -> V_25 , 2 ,
& V_5 -> V_2 , & V_26 ,
& V_5 -> V_2 , & V_27 ,
& V_5 -> V_22 . V_2 , & V_28 ,
V_5 -> V_29 ) ;
F_4 ( V_5 -> V_14 , V_5 -> V_15 , V_5 -> V_16 ,
V_11 ) ;
}
return 0 ;
}
static void T_2 F_9 ( struct V_30 * V_31 )
{
F_10 ( V_31 , V_32 , & V_33 ) ;
}
