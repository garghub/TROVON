int F_1 ( T_1 V_1 , int V_2 )
{
struct V_3 * V_4 = F_2 ( V_5 . V_6 ) ;
return F_3 ( V_4 , V_1 , V_2 ) ;
}
void F_4 ( void )
{
struct V_3 * V_4 = F_2 ( V_5 . V_6 ) ;
F_5 ( V_4 , V_7 ) ;
F_3 ( V_4 , F_6 () , true ) ;
}
void F_7 ( struct V_3 * V_8 ,
void (* F_8)( struct V_3 * ) ,
T_1 V_9 )
{
V_8 -> V_10 = F_8 ;
F_5 ( V_8 , V_7 ) ;
F_3 ( V_8 , V_9 , true ) ;
}
int F_9 ( void (* F_8)( struct V_3 * ) )
{
struct V_11 * V_12 = F_10 ( & V_5 ) ;
struct V_3 * V_4 = V_12 -> V_6 ;
if ( ! V_4 || ! ( V_4 -> V_13 & V_14 ) ||
! F_11 ( V_4 ) ) {
F_12 ( V_15 L_1
L_2 ) ;
if ( ! V_4 ) {
F_12 ( L_3 ) ;
} else {
if ( ! F_11 ( V_4 ) )
F_12 ( L_4 , V_4 -> V_16 ) ;
else
F_12 ( L_5 ,
V_4 -> V_16 ) ;
}
return - V_17 ;
}
V_12 -> V_18 = V_19 ;
V_4 -> V_10 = F_8 ;
F_5 ( V_4 , V_7 ) ;
F_13 () ;
return 0 ;
}
int F_14 ( void )
{
unsigned long V_20 ;
int V_21 ;
F_15 ( V_20 ) ;
V_21 = F_2 ( V_5 . V_18 ) == V_19 ;
F_16 ( V_20 ) ;
return V_21 ;
}
int F_17 ( void )
{
return F_9 ( V_22 ) ;
}
