static inline int F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case 0xf6 :
case 0xf8 :
case 0xfa :
case 0xfb :
case 0xfc :
case 0xfe :
case 0xff :
return 1 ;
case 0xf1 :
case 0xf3 :
return 2 ;
case 0xf2 :
return 3 ;
case 0xf0 :
return 0 ;
case 0xf7 :
break;
case 0xf4 :
case 0xf5 :
case 0xf9 :
case 0xfd :
break;
default:
switch ( V_1 & 0xf0 ) {
case 0x80 :
case 0x90 :
case 0xa0 :
case 0xb0 :
case 0xe0 :
return 3 ;
case 0xc0 :
case 0xd0 :
return 2 ;
default:
break;
}
break;
}
return - V_2 ;
}
static int F_2 ( struct V_3 * V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 -> V_9 ;
unsigned int V_10 = V_4 -> V_11 ;
int V_12 , V_13 , V_14 ;
T_1 * V_15 , * V_16 ;
T_1 V_1 ;
V_15 = V_5 ;
V_16 = V_5 + 1 ;
V_14 = F_3 ( V_4 , V_16 , 3 ) ;
if ( V_14 == 0 )
return 0 ;
if ( V_7 -> V_17 [ V_10 ] ) {
for ( V_12 = 0 ; V_12 < V_14 ; ++ V_12 ) {
if ( V_16 [ V_12 ] == 0xf7 ) {
V_7 -> V_17 [ V_10 ] = false ;
break;
}
}
if ( ! V_7 -> V_17 [ V_10 ] ) {
V_14 = V_12 + 1 ;
* V_15 = ( V_10 << 4 ) | 0x07 ;
} else if ( V_14 == 3 ) {
* V_15 = ( V_10 << 4 ) | 0x04 ;
} else {
return 0 ;
}
V_13 = V_14 ;
} else {
if ( V_16 [ 0 ] == 0xf0 ) {
V_7 -> V_17 [ V_10 ] = true ;
return 0 ;
} else {
if ( ( V_16 [ 0 ] & 0x80 ) != 0x80 )
V_1 = V_7 -> V_18 [ V_10 ] ;
else
V_1 = V_16 [ 0 ] ;
V_13 = F_1 ( V_1 ) ;
if ( V_13 <= 0 )
return 0 ;
if ( ( V_16 [ 0 ] & 0x80 ) != 0x80 ) {
if ( V_14 < V_13 - 1 )
return 0 ;
V_14 = V_13 - 1 ;
V_16 [ 2 ] = V_16 [ 1 ] ;
V_16 [ 1 ] = V_16 [ 0 ] ;
V_16 [ 0 ] = V_7 -> V_18 [ V_10 ] ;
} else {
if ( V_14 < V_13 )
return 0 ;
V_14 = V_13 ;
V_7 -> V_18 [ V_10 ] = V_16 [ 0 ] ;
}
}
* V_15 = ( V_10 << 4 ) | ( V_16 [ 0 ] >> 4 ) ;
}
if ( V_13 > 0 && V_13 < 3 )
memset ( V_16 + V_13 , 0 , 3 - V_13 ) ;
return V_14 ;
}
static void F_4 ( struct V_19 * V_20 , struct V_21 * V_22 ,
int V_23 , int V_24 , int V_25 ,
int V_26 , unsigned long long V_27 ,
void * V_28 , T_2 V_29 , void * V_30 )
{
struct V_6 * V_7 = V_30 ;
T_3 * V_5 = ( T_3 * ) V_28 ;
unsigned int V_31 ;
unsigned int V_12 ;
unsigned int V_10 ;
struct V_3 * V_4 ;
T_1 * V_32 ;
int V_33 ;
if ( V_27 != V_7 -> V_34 . V_27 )
goto V_35;
V_31 = V_29 / 8 ;
for ( V_12 = 0 ; V_12 < V_31 ; V_12 ++ ) {
V_32 = ( T_1 * ) ( V_5 + V_12 * 2 ) ;
V_10 = V_32 [ 0 ] >> 4 ;
if ( V_10 >= V_7 -> V_36 -> V_37 )
goto V_35;
V_33 = F_1 ( V_32 [ 1 ] ) ;
if ( V_33 <= 0 ) {
for ( V_33 = 1 ; V_33 < 4 ; V_33 ++ ) {
if ( V_32 [ V_33 ] == 0xf7 )
break;
}
if ( V_33 == 4 )
V_33 = 3 ;
}
V_4 = F_5 ( V_7 -> V_38 [ V_10 ] ) ;
if ( V_4 != NULL )
F_6 ( V_4 , V_32 + 1 , V_33 ) ;
}
V_35:
F_7 ( V_20 , V_22 , V_39 ) ;
}
int F_8 ( struct V_6 * V_7 )
{
static const struct V_40 V_41 = {
. V_42 = 0xffffe0000000ull ,
. V_35 = 0xffffe000ffffull ,
} ;
unsigned int V_12 ;
int V_43 ;
V_7 -> V_34 . V_29 = 8 * 8 ;
V_7 -> V_34 . V_44 = F_4 ;
V_7 -> V_34 . V_30 = V_7 ;
V_43 = F_9 ( & V_7 -> V_34 ,
& V_41 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_10 ( V_7 ) ;
if ( V_43 < 0 )
goto error;
for ( V_12 = 0 ; V_12 < V_45 ; V_12 ++ ) {
V_43 = F_11 (
& V_7 -> V_46 [ V_12 ] , V_7 -> V_47 ,
V_48 + V_49 ,
4 , F_2 ) ;
if ( V_43 < 0 )
goto error;
}
return V_43 ;
error:
F_12 ( & V_7 -> V_34 ) ;
return V_43 ;
}
int F_10 ( struct V_6 * V_7 )
{
struct V_50 * V_51 = F_13 ( V_7 -> V_47 ) ;
T_4 V_52 ;
int V_43 ;
V_52 = F_14 ( ( V_51 -> V_20 -> V_53 << 16 ) |
( V_7 -> V_34 . V_27 >> 32 ) ) ;
V_43 = F_15 ( V_7 -> V_47 , V_54 ,
V_48 + V_55 ,
& V_52 , sizeof( V_52 ) , 0 ) ;
if ( V_43 < 0 )
return V_43 ;
V_52 = F_14 ( V_7 -> V_34 . V_27 ) ;
V_43 = F_15 ( V_7 -> V_47 , V_54 ,
V_48 + V_56 ,
& V_52 , sizeof( V_52 ) , 0 ) ;
if ( V_43 < 0 )
return V_43 ;
V_52 = F_14 ( 0x00000001 ) ;
V_43 = F_15 ( V_7 -> V_47 , V_54 ,
V_48 + V_57 ,
& V_52 , sizeof( V_52 ) , 0 ) ;
if ( V_43 < 0 )
return V_43 ;
V_52 = F_14 ( 0x0001008e ) ;
return F_15 ( V_7 -> V_47 , V_54 ,
V_48 + V_58 ,
& V_52 , sizeof( V_52 ) , 0 ) ;
}
void F_16 ( struct V_6 * V_7 )
{
T_4 V_52 ;
unsigned int V_12 ;
V_52 = F_14 ( 0x0000008e ) ;
F_15 ( V_7 -> V_47 , V_54 ,
V_48 + V_58 ,
& V_52 , sizeof( V_52 ) , 0 ) ;
V_52 = F_14 ( 0x00000000 ) ;
F_15 ( V_7 -> V_47 , V_54 ,
V_48 + V_57 ,
& V_52 , sizeof( V_52 ) , 0 ) ;
F_15 ( V_7 -> V_47 , V_54 ,
V_48 + V_55 ,
& V_52 , sizeof( V_52 ) , 0 ) ;
F_15 ( V_7 -> V_47 , V_54 ,
V_48 + V_56 ,
& V_52 , sizeof( V_52 ) , 0 ) ;
F_12 ( & V_7 -> V_34 ) ;
for ( V_12 = 0 ; V_12 < V_45 ; V_12 ++ )
F_17 ( & V_7 -> V_46 [ V_12 ] ) ;
}
