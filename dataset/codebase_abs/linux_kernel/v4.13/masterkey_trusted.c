struct V_1 * F_1 ( const char * V_2 ,
const T_1 * * V_3 , T_2 * V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_7 ;
V_7 = F_2 ( & V_8 , V_2 , NULL ) ;
if ( F_3 ( V_7 ) )
goto error;
F_4 ( & V_7 -> V_9 ) ;
V_6 = V_7 -> V_10 . V_11 [ 0 ] ;
* V_3 = V_6 -> V_1 ;
* V_4 = V_6 -> V_12 ;
error:
return V_7 ;
}
