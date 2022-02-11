int F_1 ( T_1 V_1 , int V_2 )
{
struct V_3 * V_4 = F_2 ( V_5 . V_6 ) ;
if ( F_3 ( V_1 . V_7 == V_8 ) ) {
F_4 ( V_4 , V_9 ) ;
return 0 ;
}
if ( F_3 ( F_5 ( V_4 ) ) ) {
F_4 ( V_4 , V_10 ) ;
}
return F_6 ( V_4 , V_1 , V_2 ) ;
}
void F_7 ( void )
{
struct V_3 * V_4 = F_2 ( V_5 . V_6 ) ;
F_4 ( V_4 , V_10 ) ;
F_6 ( V_4 , F_8 () , true ) ;
}
void F_9 ( struct V_3 * V_11 ,
void (* F_10)( struct V_3 * ) ,
T_1 V_12 )
{
V_11 -> V_13 = F_10 ;
F_4 ( V_11 , V_10 ) ;
F_6 ( V_11 , V_12 , true ) ;
}
int F_11 ( void (* F_10)( struct V_3 * ) )
{
struct V_14 * V_15 = F_12 ( & V_5 ) ;
struct V_3 * V_4 = V_15 -> V_6 ;
if ( ! V_4 || ! ( V_4 -> V_16 & V_17 ) ||
! F_13 ( V_4 ) ) {
F_14 ( V_18 L_1
L_2 ) ;
if ( ! V_4 ) {
F_14 ( L_3 ) ;
} else {
if ( ! F_13 ( V_4 ) )
F_14 ( L_4 , V_4 -> V_19 ) ;
else
F_14 ( L_5 ,
V_4 -> V_19 ) ;
}
return - V_20 ;
}
V_15 -> V_21 = V_22 ;
V_4 -> V_13 = F_10 ;
F_4 ( V_4 , V_10 ) ;
F_15 () ;
return 0 ;
}
int F_16 ( void )
{
unsigned long V_23 ;
int V_24 ;
F_17 ( V_23 ) ;
V_24 = F_2 ( V_5 . V_21 ) == V_22 ;
F_18 ( V_23 ) ;
return V_24 ;
}
int F_19 ( void )
{
return F_11 ( V_25 ) ;
}
