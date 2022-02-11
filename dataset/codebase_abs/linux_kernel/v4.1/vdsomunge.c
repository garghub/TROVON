static void F_1 ( void )
{
if ( V_1 > 0 && V_2 != NULL )
F_2 ( V_2 ) ;
}
static T_1 F_3 ( T_1 V_3 , bool V_4 )
{
return V_4 ? F_4 ( V_3 ) : V_3 ;
}
static T_2 F_5 ( T_2 V_5 , bool V_4 )
{
return V_4 ? F_6 ( V_5 ) : V_5 ;
}
static void F_7 ( T_1 V_6 , T_1 * V_7 , bool V_4 )
{
* V_7 = V_4 ? F_4 ( V_6 ) : V_6 ;
}
int main ( int V_8 , char * * V_9 )
{
const T_3 * V_10 ;
bool V_11 ;
const char * V_12 ;
T_1 V_13 ;
const void * V_14 ;
struct V_15 V_15 ;
void * V_16 ;
bool V_4 ;
int V_17 ;
int V_18 ;
atexit ( F_1 ) ;
if ( V_8 != 3 )
error ( V_19 , 0 , L_1 , V_9 [ 0 ] ) ;
V_12 = V_9 [ 1 ] ;
V_2 = V_9 [ 2 ] ;
V_18 = F_8 ( V_12 , V_20 ) ;
if ( V_18 < 0 )
error ( V_19 , V_21 , L_2 , V_12 ) ;
if ( F_9 ( V_18 , & V_15 ) != 0 )
error ( V_19 , V_21 , L_3 , V_12 ) ;
V_14 = F_10 ( NULL , V_15 . V_22 , V_23 , V_24 , V_18 , 0 ) ;
if ( V_14 == V_25 )
error ( V_19 , V_21 , L_4 , V_12 ) ;
F_11 ( V_18 ) ;
V_10 = V_14 ;
if ( memcmp ( & V_10 -> V_26 , V_27 , V_28 ) != 0 )
error ( V_19 , 0 , L_5 ) ;
if ( V_10 -> V_26 [ V_29 ] != V_30 )
error ( V_19 , 0 , L_6 ) ;
V_4 = V_10 -> V_26 [ V_31 ] != V_32 ;
if ( F_5 ( V_10 -> V_33 , V_4 ) != V_34 )
error ( V_19 , 0 , L_7 ) ;
if ( F_5 ( V_10 -> V_35 , V_4 ) != V_36 ) {
error ( V_19 , 0 , L_8 ,
V_10 -> V_35 ) ;
}
V_13 = F_3 ( V_10 -> V_13 , V_4 ) ;
if ( F_12 ( V_13 ) != V_37 ) {
error ( V_19 , 0 , L_9 ,
F_12 ( V_13 ) ) ;
}
if ( V_13 & V_38 )
error ( V_19 , 0 ,
L_10 ) ;
V_11 = ! ! ( V_13 & V_39 ) ;
V_17 = F_8 ( V_2 , V_40 | V_41 | V_42 , V_43 | V_44 ) ;
if ( V_17 < 0 )
error ( V_19 , V_21 , L_2 , V_2 ) ;
if ( F_13 ( V_17 , V_15 . V_22 ) != 0 )
error ( V_19 , V_21 , L_11 , V_2 ) ;
V_16 = F_10 ( NULL , V_15 . V_22 , V_23 | V_45 , V_46 ,
V_17 , 0 ) ;
if ( V_16 == V_25 )
error ( V_19 , V_21 , L_4 , V_2 ) ;
F_11 ( V_17 ) ;
memcpy ( V_16 , V_14 , V_15 . V_22 ) ;
if ( V_11 ) {
T_3 * V_47 ;
V_47 = V_16 ;
V_13 &= ~ V_39 ;
F_7 ( V_13 , & V_47 -> V_13 , V_4 ) ;
}
if ( F_14 ( V_16 , V_15 . V_22 , V_48 ) != 0 )
error ( V_19 , V_21 , L_12 , V_2 ) ;
return V_49 ;
}
