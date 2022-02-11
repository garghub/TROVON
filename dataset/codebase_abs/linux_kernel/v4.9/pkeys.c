int F_1 ( struct V_1 * V_2 )
{
bool V_3 = false ;
int V_4 = V_2 -> V_5 . V_4 ;
int V_6 ;
if ( V_4 == - 1 ) {
V_4 = F_2 ( V_2 ) ;
if ( V_4 < 0 )
return - 1 ;
V_3 = true ;
}
F_3 () ;
if ( ! V_3 &&
F_4 () &&
! F_5 ( F_6 () , V_4 ) ) {
F_7 () ;
return V_4 ;
}
F_7 () ;
V_6 = F_8 ( V_7 , V_4 ,
V_8 ) ;
if ( V_6 ) {
F_9 ( V_2 , V_4 ) ;
return - 1 ;
}
if ( V_3 )
V_2 -> V_5 . V_4 = V_4 ;
return V_4 ;
}
static inline bool F_10 ( struct V_9 * V_10 )
{
if ( ( V_10 -> V_11 & ( V_12 | V_13 | V_14 ) ) != V_14 )
return false ;
if ( F_11 ( V_10 ) != V_10 -> V_15 -> V_5 . V_4 )
return false ;
return true ;
}
int F_12 ( struct V_9 * V_10 , int V_16 , int V_17 )
{
if ( V_17 != - 1 )
return V_17 ;
if ( F_10 ( V_10 ) &&
( V_16 & ( V_18 | V_19 ) ) ) {
return 0 ;
}
if ( V_16 == V_20 ) {
V_17 = V_4 ( V_10 -> V_15 ) ;
if ( V_17 > 0 )
return V_17 ;
}
return F_11 ( V_10 ) ;
}
void F_13 ( void )
{
T_1 V_21 = F_14 ( V_22 ) ;
if ( ! V_21 && ! F_6 () )
return;
F_15 ( V_21 ) ;
}
static T_2 F_16 ( struct V_23 * V_23 , char T_3 * V_24 ,
T_4 V_25 , T_5 * V_26 )
{
char V_27 [ 32 ] ;
unsigned int V_28 ;
V_28 = sprintf ( V_27 , L_1 , V_22 ) ;
return F_17 ( V_24 , V_25 , V_26 , V_27 , V_28 ) ;
}
static T_2 F_18 ( struct V_23 * V_23 ,
const char T_3 * V_24 , T_4 V_25 , T_5 * V_26 )
{
char V_27 [ 32 ] ;
T_2 V_28 ;
T_1 V_29 ;
V_28 = F_19 ( V_25 , sizeof( V_27 ) - 1 ) ;
if ( F_20 ( V_27 , V_24 , V_28 ) )
return - V_30 ;
V_27 [ V_28 ] = '\0' ;
if ( F_21 ( V_27 , 0 , & V_29 ) )
return - V_31 ;
if ( V_29 & ( V_32 | V_33 ) )
return - V_31 ;
F_22 ( V_22 , V_29 ) ;
return V_25 ;
}
static int T_6 F_23 ( void )
{
F_24 ( L_2 , V_34 | V_35 ,
V_36 , NULL , & V_37 ) ;
return 0 ;
}
static T_6 int F_25 ( char * V_38 )
{
T_1 V_29 ;
if ( F_21 ( V_38 , 0 , & V_29 ) )
return 1 ;
F_22 ( V_22 , V_29 ) ;
return 1 ;
}
