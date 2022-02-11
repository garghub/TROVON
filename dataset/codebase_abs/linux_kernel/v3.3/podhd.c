static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 == NULL )
return;
F_3 ( & V_4 -> V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_6 ;
struct V_7 * V_5 = & V_4 -> V_5 ;
if ( ( V_2 == NULL ) || ( V_4 == NULL ) )
return - V_8 ;
V_6 = F_5 ( V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_6 ( V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_7 ( V_5 , & V_9 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_8 ( V_5 ) ;
return V_6 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_6 = F_4 ( V_2 , V_4 ) ;
if ( V_6 < 0 )
F_1 ( V_2 ) ;
return V_6 ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_2 == NULL )
return;
V_4 = F_2 ( V_2 ) ;
if ( V_4 != NULL ) {
struct V_10 * V_11 = V_4 -> V_5 . V_11 ;
if ( V_11 != NULL )
F_11 ( V_11 ) ;
}
F_1 ( V_2 ) ;
}
