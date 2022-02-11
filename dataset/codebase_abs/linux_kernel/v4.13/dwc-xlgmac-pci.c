static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 V_8 ;
int V_9 , V_10 ;
V_10 = F_2 ( V_2 ) ;
if ( V_10 ) {
F_3 ( V_6 , L_1 ) ;
return V_10 ;
}
for ( V_9 = 0 ; V_9 <= V_11 ; V_9 ++ ) {
if ( F_4 ( V_2 , V_9 ) == 0 )
continue;
V_10 = F_5 ( V_2 , F_6 ( V_9 ) , V_12 ) ;
if ( V_10 )
return V_10 ;
break;
}
F_7 ( V_2 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_13 = V_2 -> V_13 ;
V_8 . V_14 = F_8 ( V_2 ) [ V_9 ] ;
return F_9 ( & V_2 -> V_6 , & V_8 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_6 ) ;
}
