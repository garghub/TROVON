int F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 , 0 ) && F_3 ( V_2 , 0 ) <= 1 &&
! F_4 ( V_2 , 0 ) && F_5 ( V_2 , 0 ) <= 1 &&
F_6 ( V_2 , 0 ) == - 1 && F_7 ( V_2 , 0 ) == - 1 )
return 0 ;
else
return 1 ;
}
void F_8 ( T_1 V_3 , char * V_4 )
{
V_3 = F_9 ( V_3 ) ;
V_4 [ 0 ] = 'A' + ( ( V_3 >> 26 ) & 0x3f ) - 1 ;
V_4 [ 1 ] = 'A' + ( ( V_3 >> 21 ) & 0x1f ) - 1 ;
V_4 [ 2 ] = 'A' + ( ( V_3 >> 16 ) & 0x1f ) - 1 ;
V_4 [ 3 ] = F_10 ( V_3 >> 8 ) ;
V_4 [ 4 ] = F_11 ( V_3 >> 8 ) ;
V_4 [ 5 ] = F_10 ( V_3 ) ;
V_4 [ 6 ] = F_11 ( V_3 ) ;
V_4 [ 7 ] = '\0' ;
}
char * F_12 ( struct V_5 * V_6 )
{
switch ( F_13 ( V_6 ) ) {
case V_7 :
return L_1 ;
case V_8 :
return L_2 ;
case V_9 :
return L_3 ;
case V_10 :
return L_4 ;
case V_11 :
return L_5 ;
}
return L_6 ;
}
void F_14 ( struct V_1 * V_2 , char * V_12 )
{
struct V_13 * V_14 ;
if ( F_15 ( & V_2 -> V_15 ) )
F_16 ( & V_2 -> V_2 , L_7 , V_12 ) ;
else {
F_16 ( & V_2 -> V_2 , L_8 , V_12 ) ;
F_17 (pnp_res, &dev->resources, list)
F_16 ( & V_2 -> V_2 , L_9 , & V_14 -> V_6 ) ;
}
}
char * F_18 ( struct V_16 * V_17 )
{
switch ( F_19 ( V_17 ) ) {
case V_18 :
return L_10 ;
case V_19 :
return L_11 ;
case V_20 :
return L_12 ;
}
return L_13 ;
}
void F_20 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
char V_21 [ 128 ] ;
int V_22 = 0 , V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct F_6 * V_28 ;
struct F_7 * V_29 ;
if ( F_21 ( V_17 ) )
V_22 += F_22 ( V_21 + V_22 , sizeof( V_21 ) - V_22 ,
L_14 ,
F_23 ( V_17 ) ,
F_18 ( V_17 ) ) ;
else
V_22 += F_22 ( V_21 + V_22 , sizeof( V_21 ) - V_22 ,
L_15 ) ;
switch ( V_17 -> type ) {
case V_7 :
V_25 = & V_17 -> V_30 . V_25 ;
V_22 += F_22 ( V_21 + V_22 , sizeof( V_21 ) - V_22 , L_16
L_17 ,
( unsigned long long ) V_25 -> V_31 ,
( unsigned long long ) V_25 -> V_32 ,
( unsigned long long ) V_25 -> V_33 ,
( unsigned long long ) V_25 -> V_34 , V_25 -> V_35 ) ;
break;
case V_8 :
V_27 = & V_17 -> V_30 . V_27 ;
V_22 += F_22 ( V_21 + V_22 , sizeof( V_21 ) - V_22 , L_18
L_17 ,
( unsigned long long ) V_27 -> V_31 ,
( unsigned long long ) V_27 -> V_32 ,
( unsigned long long ) V_27 -> V_33 ,
( unsigned long long ) V_27 -> V_34 , V_27 -> V_35 ) ;
break;
case V_9 :
V_28 = & V_17 -> V_30 . V_28 ;
V_22 += F_22 ( V_21 + V_22 , sizeof( V_21 ) - V_22 , L_3 ) ;
if ( F_24 ( V_28 -> V_36 . V_37 , V_38 ) )
V_22 += F_22 ( V_21 + V_22 , sizeof( V_21 ) - V_22 ,
L_19 ) ;
else {
for ( V_23 = 0 ; V_23 < V_38 ; V_23 ++ )
if ( F_25 ( V_23 , V_28 -> V_36 . V_37 ) )
V_22 += F_22 ( V_21 + V_22 ,
sizeof( V_21 ) - V_22 ,
L_20 , V_23 ) ;
}
V_22 += F_22 ( V_21 + V_22 , sizeof( V_21 ) - V_22 , L_21 ,
V_28 -> V_35 ) ;
if ( V_28 -> V_35 & V_39 )
V_22 += F_22 ( V_21 + V_22 , sizeof( V_21 ) - V_22 ,
L_22 ) ;
break;
case V_10 :
V_29 = & V_17 -> V_30 . V_29 ;
V_22 += F_22 ( V_21 + V_22 , sizeof( V_21 ) - V_22 , L_4 ) ;
if ( ! V_29 -> V_36 )
V_22 += F_22 ( V_21 + V_22 , sizeof( V_21 ) - V_22 ,
L_19 ) ;
else {
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ )
if ( V_29 -> V_36 & ( 1 << V_23 ) )
V_22 += F_22 ( V_21 + V_22 ,
sizeof( V_21 ) - V_22 ,
L_20 , V_23 ) ;
}
V_22 += F_22 ( V_21 + V_22 , sizeof( V_21 ) - V_22 , L_23
L_24 , V_29 -> V_36 , V_29 -> V_35 ) ;
break;
}
F_16 ( & V_2 -> V_2 , L_25 , V_21 ) ;
}
