static bool T_1
F_1 ( const struct V_1 * V_2 , int V_3 )
{
F_2 ( V_3 != V_4 || F_3 () ) ;
return F_4 ( F_5 () , V_2 -> V_5 ,
V_2 -> V_6 ,
V_2 -> V_7 ) ;
}
static bool
F_6 ( const struct V_1 * V_2 ,
int V_3 )
{
F_2 ( V_3 != V_4 || F_3 () ) ;
return ( F_7 () & V_8 . V_9 ) !=
( V_8 . V_10 & V_8 . V_9 ) ;
}
static int F_8 ( void * V_11 )
{
F_9 ( V_12 , 0 ) ;
return 0 ;
}
void F_10 ( void )
{
const struct V_1 * V_13 = V_14 ;
for (; V_13 -> V_15 ; V_13 ++ )
if ( ! F_11 ( V_13 -> V_16 ) &&
V_13 -> V_15 ( V_13 , V_4 ) ) {
F_12 ( L_1
L_2 ,
F_13 () ,
V_13 -> V_17 ? : L_3 ) ;
F_14 () ;
}
}
void F_15 ( void )
{
F_16 ( V_14 , L_4 ) ;
}
void T_2 F_17 ( void )
{
F_18 ( V_14 ) ;
}
