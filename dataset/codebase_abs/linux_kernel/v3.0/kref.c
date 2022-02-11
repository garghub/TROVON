void F_1 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_2 , 1 ) ;
F_3 () ;
}
void F_4 ( struct V_1 * V_1 )
{
F_5 ( ! F_6 ( & V_1 -> V_2 ) ) ;
F_7 ( & V_1 -> V_2 ) ;
F_8 () ;
}
int F_9 ( struct V_1 * V_1 , void (* F_10)( struct V_1 * V_1 ) )
{
F_5 ( F_10 == NULL ) ;
F_5 ( F_10 == ( void ( * ) ( struct V_1 * ) ) V_3 ) ;
if ( F_11 ( & V_1 -> V_2 ) ) {
F_10 ( V_1 ) ;
return 1 ;
}
return 0 ;
}
int F_12 ( struct V_1 * V_1 , unsigned int V_4 ,
void (* F_10)( struct V_1 * V_1 ) )
{
F_5 ( F_10 == NULL ) ;
F_5 ( F_10 == ( void ( * ) ( struct V_1 * ) ) V_3 ) ;
if ( F_13 ( ( int ) V_4 , & V_1 -> V_2 ) ) {
F_10 ( V_1 ) ;
return 1 ;
}
return 0 ;
}
