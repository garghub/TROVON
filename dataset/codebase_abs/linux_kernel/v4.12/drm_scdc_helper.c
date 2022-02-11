T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 , void * V_4 ,
T_3 V_5 )
{
int V_6 ;
struct V_7 V_8 [ 2 ] = {
{
. V_9 = V_10 ,
. V_11 = 0 ,
. V_12 = 1 ,
. V_13 = & V_3 ,
} , {
. V_9 = V_10 ,
. V_11 = V_14 ,
. V_12 = V_5 ,
. V_13 = V_4 ,
}
} ;
V_6 = F_2 ( V_2 , V_8 , F_3 ( V_8 ) ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 != F_3 ( V_8 ) )
return - V_15 ;
return 0 ;
}
T_1 F_4 ( struct V_1 * V_2 , T_2 V_3 ,
const void * V_4 , T_3 V_5 )
{
struct V_7 V_16 = {
. V_9 = V_10 ,
. V_11 = 0 ,
. V_12 = 1 + V_5 ,
. V_13 = NULL ,
} ;
void * V_17 ;
int V_18 ;
V_17 = F_5 ( 1 + V_5 , V_19 ) ;
if ( ! V_17 )
return - V_20 ;
V_16 . V_13 = V_17 ;
memcpy ( V_17 , & V_3 , sizeof( V_3 ) ) ;
memcpy ( V_17 + 1 , V_4 , V_5 ) ;
V_18 = F_2 ( V_2 , & V_16 , 1 ) ;
F_6 ( V_17 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_18 != 1 )
return - V_15 ;
return 0 ;
}
bool F_7 ( struct V_1 * V_2 )
{
T_2 V_21 ;
int V_6 ;
V_6 = F_8 ( V_2 , V_22 , & V_21 ) ;
if ( V_6 < 0 ) {
F_9 ( L_1 , V_6 ) ;
return false ;
}
return V_21 & V_23 ;
}
bool F_10 ( struct V_1 * V_2 , bool V_24 )
{
T_2 V_25 ;
int V_6 ;
V_6 = F_8 ( V_2 , V_26 , & V_25 ) ;
if ( V_6 < 0 ) {
F_9 ( L_2 , V_6 ) ;
return false ;
}
if ( V_24 )
V_25 |= V_27 ;
else
V_25 &= ~ V_27 ;
V_6 = F_11 ( V_2 , V_26 , V_25 ) ;
if ( V_6 < 0 ) {
F_9 ( L_3 , V_6 ) ;
return false ;
}
return true ;
}
bool F_12 ( struct V_1 * V_2 , bool V_28 )
{
T_2 V_25 ;
int V_6 ;
V_6 = F_8 ( V_2 , V_26 , & V_25 ) ;
if ( V_6 < 0 ) {
F_9 ( L_2 , V_6 ) ;
return false ;
}
if ( V_28 )
V_25 |= V_29 ;
else
V_25 &= ~ V_29 ;
V_6 = F_11 ( V_2 , V_26 , V_25 ) ;
if ( V_6 < 0 ) {
F_9 ( L_4 , V_6 ) ;
return false ;
}
F_13 ( 1000 , 2000 ) ;
return true ;
}
