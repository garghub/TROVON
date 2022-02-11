static void F_1 ( void )
{
F_2 ( ! F_3 ( V_1 ) ) ;
F_4 ( V_1 , ! V_2 ) ;
F_5 ( 100 ) ;
F_6 ( V_1 , V_2 ) ;
F_5 ( 100 ) ;
F_6 ( V_1 , ! V_2 ) ;
F_5 ( 3000 ) ;
F_7 ( 1 ) ;
}
static int F_8 ( struct V_3 * V_4 )
{
enum V_5 V_6 ;
bool V_7 = false ;
int V_8 ;
if ( V_9 != NULL ) {
F_9 ( L_1 ,
V_10 ) ;
return - V_11 ;
}
V_1 = F_10 ( V_4 -> V_12 . V_13 , 0 , & V_6 ) ;
if ( ! F_3 ( V_1 ) )
return V_1 ;
V_2 = V_6 & V_14 ;
V_7 = F_11 ( V_4 -> V_12 . V_13 , L_2 ) ;
V_8 = F_12 ( V_1 , L_3 ) ;
if ( V_8 ) {
F_9 ( L_4 , V_10 , V_1 ) ;
return V_8 ;
}
if ( V_7 ) {
if ( F_13 ( V_1 ) ) {
F_9 ( L_5 ,
V_1 ) ;
goto V_15;
}
} else {
if ( F_4 ( V_1 , V_2 ) ) {
F_9 ( L_6 , V_1 ) ;
goto V_15;
}
}
V_9 = & F_1 ;
return 0 ;
V_15:
F_14 ( V_1 ) ;
return - V_16 ;
}
static int F_15 ( struct V_3 * V_4 )
{
F_14 ( V_1 ) ;
if ( V_9 == & F_1 )
V_9 = NULL ;
return 0 ;
}
