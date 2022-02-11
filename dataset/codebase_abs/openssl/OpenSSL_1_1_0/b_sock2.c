int F_1 ( int V_1 , int V_2 , int V_3 , int V_4 )
{
int V_5 = - 1 ;
if ( F_2 () != 1 )
return V_6 ;
V_5 = F_3 ( V_1 , V_2 , V_3 ) ;
if ( V_5 == - 1 ) {
F_4 ( V_7 , F_5 () ) ;
F_6 ( V_8 , V_9 ) ;
return V_6 ;
}
return V_5 ;
}
int F_7 ( int V_5 , const T_1 * V_10 , int V_4 )
{
int V_11 = 1 ;
if ( V_5 == - 1 ) {
F_6 ( V_12 , V_13 ) ;
return 0 ;
}
if ( ! F_8 ( V_5 , ( V_4 & V_14 ) != 0 ) )
return 0 ;
if ( V_4 & V_15 ) {
if ( F_9 ( V_5 , V_16 , V_17 , & V_11 , sizeof( V_11 ) ) != 0 ) {
F_4 ( V_18 , F_5 () ) ;
F_6 ( V_12 , V_19 ) ;
return 0 ;
}
}
if ( V_4 & V_20 ) {
if ( F_9 ( V_5 , V_21 , V_22 , & V_11 , sizeof( V_11 ) ) != 0 ) {
F_4 ( V_18 , F_5 () ) ;
F_6 ( V_12 , V_23 ) ;
return 0 ;
}
}
if ( F_10 ( V_5 , F_11 ( V_10 ) ,
F_12 ( V_10 ) ) == - 1 ) {
if ( ! F_13 ( - 1 ) ) {
F_4 ( V_24 , F_5 () ) ;
F_6 ( V_12 , V_25 ) ;
}
return 0 ;
}
return 1 ;
}
int F_14 ( int V_5 , const T_1 * V_10 , int V_4 )
{
int V_11 = 1 ;
int V_2 ;
T_2 V_26 = sizeof( V_2 ) ;
if ( V_5 == - 1 ) {
F_6 ( V_27 , V_13 ) ;
return 0 ;
}
if ( F_15 ( V_5 , V_16 , V_28 , & V_2 , & V_26 ) != 0
|| V_26 != sizeof( V_2 ) ) {
F_4 ( V_29 , F_5 () ) ;
F_6 ( V_27 , V_30 ) ;
return 0 ;
}
if ( ! F_8 ( V_5 , ( V_4 & V_14 ) != 0 ) )
return 0 ;
# ifndef F_16
if ( V_4 & V_31 ) {
if ( F_9 ( V_5 , V_16 , V_32 , & V_11 , sizeof( V_11 ) ) != 0 ) {
F_4 ( V_18 , F_5 () ) ;
F_6 ( V_27 , V_33 ) ;
return 0 ;
}
}
# endif
if ( V_4 & V_15 ) {
if ( F_9 ( V_5 , V_16 , V_17 , & V_11 , sizeof( V_11 ) ) != 0 ) {
F_4 ( V_18 , F_5 () ) ;
F_6 ( V_27 , V_19 ) ;
return 0 ;
}
}
if ( V_4 & V_20 ) {
if ( F_9 ( V_5 , V_21 , V_22 , & V_11 , sizeof( V_11 ) ) != 0 ) {
F_4 ( V_18 , F_5 () ) ;
F_6 ( V_27 , V_23 ) ;
return 0 ;
}
}
# ifdef F_17
if ( ( V_4 & V_34 ) && F_18 ( V_10 ) == V_35 ) {
if ( F_9 ( V_5 , V_36 , F_17 , & V_11 , sizeof( V_11 ) ) != 0 ) {
F_4 ( V_18 , F_5 () ) ;
F_6 ( V_27 , V_37 ) ;
return 0 ;
}
}
# endif
if ( F_19 ( V_5 , F_11 ( V_10 ) , F_12 ( V_10 ) ) != 0 ) {
F_4 ( V_38 , F_5 () ) ;
F_6 ( V_27 , V_39 ) ;
return 0 ;
}
if ( V_2 != V_40 && F_20 ( V_5 , V_41 ) == - 1 ) {
F_4 ( V_42 , F_5 () ) ;
F_6 ( V_27 , V_43 ) ;
return 0 ;
}
return 1 ;
}
int F_21 ( int V_44 , T_1 * V_45 , int V_4 )
{
T_2 V_46 ;
int V_47 ;
T_1 V_48 ;
T_1 * V_10 = V_45 == NULL ? & V_48 : V_45 ;
V_46 = sizeof( * V_10 ) ;
V_47 = F_22 ( V_44 ,
F_23 ( V_10 ) , & V_46 ) ;
if ( V_47 == - 1 ) {
if ( ! F_13 ( V_47 ) ) {
F_4 ( V_49 , F_5 () ) ;
F_6 ( V_50 , V_51 ) ;
}
return V_6 ;
}
if ( ! F_8 ( V_47 , ( V_4 & V_14 ) != 0 ) ) {
F_24 ( V_47 ) ;
return V_6 ;
}
return V_47 ;
}
int F_25 ( int V_5 )
{
if ( F_24 ( V_5 ) < 0 )
return 0 ;
return 1 ;
}
