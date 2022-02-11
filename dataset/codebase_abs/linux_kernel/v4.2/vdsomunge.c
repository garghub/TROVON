static void F_1 ( const char * V_1 , ... )
{
T_1 V_2 ;
V_3 = 1 ;
fprintf ( V_4 , L_1 , V_5 ) ;
va_start ( V_2 , V_1 ) ;
vfprintf ( V_4 , V_1 , V_2 ) ;
va_end ( V_2 ) ;
exit ( V_6 ) ;
}
static void F_2 ( void )
{
if ( V_3 && V_7 != NULL )
F_3 ( V_7 ) ;
}
static T_2 F_4 ( T_2 V_8 , bool V_9 )
{
return V_9 ? F_5 ( V_8 ) : V_8 ;
}
static T_3 F_6 ( T_3 V_10 , bool V_9 )
{
return V_9 ? F_7 ( V_10 ) : V_10 ;
}
static void F_8 ( T_2 V_11 , T_2 * V_12 , bool V_9 )
{
* V_12 = V_9 ? F_5 ( V_11 ) : V_11 ;
}
int main ( int V_13 , char * * V_14 )
{
const T_4 * V_15 ;
bool V_16 ;
const char * V_17 ;
T_2 V_18 ;
const void * V_19 ;
struct V_20 V_20 ;
void * V_21 ;
bool V_9 ;
int V_22 ;
int V_23 ;
atexit ( F_2 ) ;
V_5 = V_14 [ 0 ] ;
if ( V_13 != 3 )
F_1 ( L_2 , V_14 [ 0 ] ) ;
V_17 = V_14 [ 1 ] ;
V_7 = V_14 [ 2 ] ;
V_23 = F_9 ( V_17 , V_24 ) ;
if ( V_23 < 0 )
F_1 ( L_3 , V_17 , strerror ( V_25 ) ) ;
if ( F_10 ( V_23 , & V_20 ) != 0 )
F_1 ( L_4 , V_17 , strerror ( V_25 ) ) ;
V_19 = F_11 ( NULL , V_20 . V_26 , V_27 , V_28 , V_23 , 0 ) ;
if ( V_19 == V_29 )
F_1 ( L_5 , V_17 , strerror ( V_25 ) ) ;
F_12 ( V_23 ) ;
V_15 = V_19 ;
if ( memcmp ( & V_15 -> V_30 , V_31 , V_32 ) != 0 )
F_1 ( L_6 ) ;
if ( V_15 -> V_30 [ V_33 ] != V_34 )
F_1 ( L_7 ) ;
V_9 = V_15 -> V_30 [ V_35 ] != V_36 ;
if ( F_6 ( V_15 -> V_37 , V_9 ) != V_38 )
F_1 ( L_8 ) ;
if ( F_6 ( V_15 -> V_39 , V_9 ) != V_40 )
F_1 ( L_9 , V_15 -> V_39 ) ;
V_18 = F_4 ( V_15 -> V_18 , V_9 ) ;
if ( F_13 ( V_18 ) != V_41 ) {
F_1 ( L_10 ,
F_13 ( V_18 ) ) ;
}
if ( V_18 & V_42 )
F_1 ( L_11 ) ;
V_16 = ! ! ( V_18 & V_43 ) ;
V_22 = F_9 ( V_7 , V_44 | V_45 | V_46 , V_47 | V_48 ) ;
if ( V_22 < 0 )
F_1 ( L_3 , V_7 , strerror ( V_25 ) ) ;
if ( F_14 ( V_22 , V_20 . V_26 ) != 0 )
F_1 ( L_12 , V_7 , strerror ( V_25 ) ) ;
V_21 = F_11 ( NULL , V_20 . V_26 , V_27 | V_49 , V_50 ,
V_22 , 0 ) ;
if ( V_21 == V_29 )
F_1 ( L_5 , V_7 , strerror ( V_25 ) ) ;
F_12 ( V_22 ) ;
memcpy ( V_21 , V_19 , V_20 . V_26 ) ;
if ( V_16 ) {
T_4 * V_51 ;
V_51 = V_21 ;
V_18 &= ~ V_43 ;
F_8 ( V_18 , & V_51 -> V_18 , V_9 ) ;
}
if ( F_15 ( V_21 , V_20 . V_26 , V_52 ) != 0 )
F_1 ( L_13 , V_7 , strerror ( V_25 ) ) ;
return V_53 ;
}
