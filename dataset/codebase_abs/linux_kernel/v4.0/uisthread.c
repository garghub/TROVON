int
F_1 ( struct V_1 * V_2 ,
int (* F_2)( void * ) , void * V_3 , char * V_4 )
{
V_2 -> V_5 = 0 ;
F_3 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = F_4 ( F_2 , V_3 , V_4 , NULL ) ;
if ( F_5 ( V_2 -> V_7 ) ) {
V_2 -> V_8 = 0 ;
return 0 ;
}
V_2 -> V_8 = V_2 -> V_7 -> V_9 ;
F_6 ( V_2 -> V_7 ) ;
F_7 ( L_1 , V_2 -> V_8 ) ;
return 1 ;
}
void
F_8 ( struct V_1 * V_2 )
{
int V_10 ;
int V_11 = 0 ;
if ( V_2 -> V_8 == 0 )
return;
F_7 ( L_2 , V_2 -> V_8 ) ;
V_2 -> V_5 = 1 ;
V_10 = F_9 ( V_2 -> V_8 , V_12 , 1 ) ;
if ( V_10 ) {
F_10 ( L_3 , V_10 ) ;
} else {
if ( F_11 ( & V_2 -> V_6 , 60 * V_13 ) )
V_11 = 1 ;
else
F_10 ( L_4 ) ;
}
if ( V_11 ) {
F_7 ( L_5 , V_2 -> V_8 ) ;
V_2 -> V_8 = 0 ;
}
}
