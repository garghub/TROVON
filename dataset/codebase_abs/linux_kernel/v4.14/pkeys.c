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
V_7 -> V_8 . V_9 . V_10 &&
! F_4 ( F_5 () , V_4 ) ) {
F_6 () ;
return V_4 ;
}
F_6 () ;
V_6 = F_7 ( V_7 , V_4 ,
V_11 ) ;
if ( V_6 ) {
F_8 ( V_2 , V_4 ) ;
return - 1 ;
}
if ( V_3 )
V_2 -> V_5 . V_4 = V_4 ;
return V_4 ;
}
static inline bool F_9 ( struct V_12 * V_13 )
{
if ( ( V_13 -> V_14 & ( V_15 | V_16 | V_17 ) ) != V_17 )
return false ;
if ( F_10 ( V_13 ) != V_13 -> V_18 -> V_5 . V_4 )
return false ;
return true ;
}
int F_11 ( struct V_12 * V_13 , int V_19 , int V_20 )
{
if ( V_20 != - 1 )
return V_20 ;
if ( F_9 ( V_13 ) &&
( V_19 & ( V_21 | V_22 ) ) ) {
return 0 ;
}
if ( V_19 == V_23 ) {
V_20 = V_4 ( V_13 -> V_18 ) ;
if ( V_20 > 0 )
return V_20 ;
}
return F_10 ( V_13 ) ;
}
void F_12 ( void )
{
T_1 V_24 = F_13 ( V_25 ) ;
if ( ! V_24 && ! F_5 () )
return;
F_14 ( V_24 ) ;
}
static T_2 F_15 ( struct V_26 * V_26 , char T_3 * V_27 ,
T_4 V_28 , T_5 * V_29 )
{
char V_30 [ 32 ] ;
unsigned int V_31 ;
V_31 = sprintf ( V_30 , L_1 , V_25 ) ;
return F_16 ( V_27 , V_28 , V_29 , V_30 , V_31 ) ;
}
static T_2 F_17 ( struct V_26 * V_26 ,
const char T_3 * V_27 , T_4 V_28 , T_5 * V_29 )
{
char V_30 [ 32 ] ;
T_2 V_31 ;
T_1 V_32 ;
V_31 = F_18 ( V_28 , sizeof( V_30 ) - 1 ) ;
if ( F_19 ( V_30 , V_27 , V_31 ) )
return - V_33 ;
V_30 [ V_31 ] = '\0' ;
if ( F_20 ( V_30 , 0 , & V_32 ) )
return - V_34 ;
if ( V_32 & ( V_35 | V_36 ) )
return - V_34 ;
F_21 ( V_25 , V_32 ) ;
return V_28 ;
}
static int T_6 F_22 ( void )
{
F_23 ( L_2 , V_37 | V_38 ,
V_39 , NULL , & V_40 ) ;
return 0 ;
}
static T_6 int F_24 ( char * V_41 )
{
T_1 V_32 ;
if ( F_20 ( V_41 , 0 , & V_32 ) )
return 1 ;
F_21 ( V_25 , V_32 ) ;
return 1 ;
}
