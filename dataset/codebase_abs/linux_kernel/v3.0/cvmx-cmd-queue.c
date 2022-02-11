static T_1 F_1 ( void )
{
char * V_1 = L_1 ;
#if F_2 ( V_2 ) && V_2
extern T_2 V_3 ;
#endif
if ( F_3 ( V_4 ) )
return V_5 ;
#if F_2 ( V_2 ) && V_2
if ( V_3 )
V_4 =
F_4 ( sizeof( * V_4 ) ,
V_3 ,
V_3 +
( V_2 <<
20 ) - 1 , 128 , V_1 ) ;
else
#endif
V_4 =
F_5 ( sizeof( * V_4 ) ,
128 ,
V_1 ) ;
if ( V_4 )
memset ( V_4 , 0 ,
sizeof( * V_4 ) ) ;
else {
struct V_6 * V_7 =
F_6 ( V_1 ) ;
if ( V_7 )
V_4 =
F_7 ( V_7 -> V_8 ) ;
else {
F_8
( L_2 ,
V_1 ) ;
return V_9 ;
}
}
return V_5 ;
}
T_1 F_9 ( T_3 V_10 ,
int V_11 , int V_12 ,
int V_13 )
{
T_4 * V_14 ;
T_1 V_15 = F_1 () ;
if ( V_15 != V_5 )
return V_15 ;
V_14 = F_10 ( V_10 ) ;
if ( V_14 == NULL )
return V_16 ;
if ( V_17 ) {
if ( ( V_11 < 0 ) || ( V_11 > 1 << 20 ) )
return V_16 ;
} else if ( V_11 != 0 )
return V_16 ;
if ( ( V_12 < 0 ) || ( V_12 > 7 ) )
return V_16 ;
if ( ( V_13 < 128 ) || ( V_13 > 65536 ) )
return V_16 ;
if ( V_14 -> V_18 ) {
if ( V_11 != ( int ) V_14 -> V_11 ) {
F_8 ( L_3
L_4
L_5 ,
( int ) V_14 -> V_11 ) ;
return V_16 ;
}
if ( V_12 != V_14 -> V_12 ) {
F_8 ( L_3
L_4
L_6 ,
V_14 -> V_12 ) ;
return V_16 ;
}
if ( ( V_13 >> 3 ) - 1 != V_14 -> V_19 ) {
F_8 ( L_3
L_4
L_7 ,
( V_14 -> V_19 + 1 ) << 3 ) ;
return V_16 ;
}
V_20 ;
return V_21 ;
} else {
union V_22 V_23 ;
void * V_24 ;
V_23 . V_25 = F_11 ( V_26 ) ;
if ( ! V_23 . V_27 . V_28 ) {
F_8 ( L_3
L_8 ) ;
return V_9 ;
}
V_24 = F_12 ( V_12 ) ;
if ( V_24 == NULL ) {
F_8 ( L_3
L_9 ) ;
return V_9 ;
}
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_14 -> V_11 = V_11 ;
V_14 -> V_12 = V_12 ;
V_14 -> V_19 = ( V_13 >> 3 ) - 1 ;
V_14 -> V_18 = F_13 ( V_24 ) / 128 ;
V_4 ->
V_29 [ F_14 ( V_10 ) ] = 0 ;
V_20 ;
return V_5 ;
}
}
T_1 F_15 ( T_3 V_10 )
{
T_4 * V_30 = F_10 ( V_10 ) ;
if ( V_30 == NULL ) {
F_8 ( L_10
L_11 ) ;
return V_16 ;
}
if ( F_16 ( V_10 ) > 0 ) {
F_8 ( L_12
L_13 ) ;
return V_31 ;
}
F_17 ( V_10 , V_30 ) ;
if ( V_30 -> V_18 ) {
F_18 ( F_7
( ( T_2 ) V_30 -> V_18 << 7 ) ,
V_30 -> V_12 , 0 ) ;
V_30 -> V_18 = 0 ;
}
F_19 ( V_30 ) ;
return V_5 ;
}
int F_16 ( T_3 V_10 )
{
if ( V_32 ) {
if ( F_10 ( V_10 ) == NULL )
return V_16 ;
}
switch ( ( T_3 ) ( V_10 & 0xff0000 ) ) {
case V_33 :
F_20 ( V_34 , V_10 & 0xffff ) ;
if ( F_21 ( V_35 ) ) {
union V_36 V_37 ;
V_37 . V_25 = F_11 ( V_38 ) ;
return V_37 . V_39 . V_40 ;
} else {
union V_41 V_42 ;
V_42 . V_25 = F_11 ( V_43 ) ;
return V_42 . V_44 . V_40 ;
}
case V_45 :
case V_46 :
case V_47 :
return 0 ;
case V_48 :
{
union V_49 V_50 ;
V_50 . V_25 =
F_11 ( F_22
( V_10 & 0x7 ) ) ;
return V_50 . V_27 . V_51 ;
}
case V_52 :
return V_16 ;
}
return V_16 ;
}
void * F_23 ( T_3 V_10 )
{
T_4 * V_30 = F_10 ( V_10 ) ;
if ( V_30 && V_30 -> V_18 )
return F_7 ( ( T_2 ) V_30 -> V_18 << 7 ) ;
else
return NULL ;
}
