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
static int F_2 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 , V_8 , V_9 ;
T_1 * V_10 , * V_11 ;
T_1 V_1 ;
V_10 = V_4 -> V_12 ;
V_11 = V_4 -> V_12 + 1 ;
V_9 = F_3 ( V_6 , V_11 , 3 ) ;
if ( V_9 == 0 )
return 0 ;
if ( V_4 -> V_13 ) {
for ( V_7 = 0 ; V_7 < V_9 ; ++ V_7 ) {
if ( V_11 [ V_7 ] == 0xf7 ) {
V_4 -> V_13 = false ;
break;
}
}
if ( ! V_4 -> V_13 ) {
V_9 = V_7 + 1 ;
* V_10 = ( V_6 -> V_14 << 4 ) | 0x07 ;
} else if ( V_9 == 3 ) {
* V_10 = ( V_6 -> V_14 << 4 ) | 0x04 ;
} else {
return 0 ;
}
V_8 = V_9 ;
} else {
if ( V_11 [ 0 ] == 0xf0 ) {
V_4 -> V_13 = true ;
return 0 ;
} else {
if ( ( V_11 [ 0 ] & 0x80 ) != 0x80 )
V_1 = V_4 -> V_15 ;
else
V_1 = V_11 [ 0 ] ;
V_8 = F_1 ( V_1 ) ;
if ( V_8 <= 0 )
return 0 ;
if ( ( V_11 [ 0 ] & 0x80 ) != 0x80 ) {
if ( V_9 < V_8 - 1 )
return 0 ;
V_9 = V_8 - 1 ;
V_11 [ 2 ] = V_11 [ 1 ] ;
V_11 [ 1 ] = V_11 [ 0 ] ;
V_11 [ 0 ] = V_4 -> V_15 ;
} else {
if ( V_9 < V_8 )
return 0 ;
V_9 = V_8 ;
V_4 -> V_15 = V_11 [ 0 ] ;
}
}
* V_10 = ( V_6 -> V_14 << 4 ) | ( V_11 [ 0 ] >> 4 ) ;
}
if ( V_8 > 0 && V_8 < 3 )
memset ( V_11 + V_8 , 0 , 3 - V_8 ) ;
return V_9 ;
}
static void F_4 ( struct V_16 * V_17 , int V_18 ,
void * V_19 , T_2 V_20 ,
void * V_21 )
{
struct V_3 * V_4 = V_21 ;
struct V_5 * V_6 = F_5 ( V_4 -> V_6 ) ;
if ( V_6 == NULL )
return;
if ( V_18 == V_22 )
F_6 ( V_6 , V_4 -> V_23 ) ;
else if ( ! F_7 ( V_18 ) )
V_4 -> V_24 = 0 ;
else
V_4 -> error = true ;
V_4 -> V_25 = true ;
if ( ! F_8 ( V_6 ) )
F_9 ( & V_4 -> V_26 ) ;
}
static void F_10 ( struct V_27 * V_26 )
{
struct V_3 * V_4 =
F_11 ( V_26 , struct V_3 , V_26 ) ;
struct V_5 * V_6 = F_5 ( V_4 -> V_6 ) ;
int V_28 ;
if ( ! V_4 -> V_25 || V_4 -> error )
return;
if ( V_6 == NULL || F_8 ( V_6 ) )
return;
if ( F_12 ( V_4 -> V_24 , F_13 () ) ) {
F_9 ( & V_4 -> V_26 ) ;
return;
}
memset ( V_4 -> V_12 , 0 , 4 ) ;
V_4 -> V_23 = F_2 ( V_4 , V_6 ) ;
if ( V_4 -> V_23 <= 0 ) {
if ( V_4 -> V_23 == 0 ) {
V_4 -> V_24 = 0 ;
F_9 ( & V_4 -> V_26 ) ;
} else {
V_4 -> error = true ;
}
return;
}
V_4 -> V_24 = F_14 ( F_13 () ,
V_4 -> V_23 * 8 * V_29 / 31250 ) ;
V_4 -> V_25 = false ;
V_28 = V_4 -> V_30 -> V_28 ;
F_15 () ;
F_16 ( V_4 -> V_30 -> V_17 , & V_4 -> V_31 ,
V_32 ,
V_4 -> V_30 -> V_33 , V_28 ,
V_4 -> V_30 -> V_34 ,
V_35 + V_36 ,
V_4 -> V_12 , 4 , F_4 ,
V_4 ) ;
}
void F_17 ( struct V_3 * V_4 )
{
V_4 -> V_25 = true ;
V_4 -> error = false ;
V_4 -> V_15 = 0 ;
V_4 -> V_13 = false ;
}
static void F_18 ( struct V_16 * V_17 , struct V_37 * V_38 ,
int V_39 , int V_40 , int V_41 ,
int V_28 , unsigned long long V_42 ,
void * V_19 , T_2 V_20 , void * V_21 )
{
struct V_43 * V_44 = V_21 ;
T_3 * V_12 = ( T_3 * ) V_19 ;
unsigned int V_45 ;
unsigned int V_7 ;
unsigned int V_4 ;
struct V_5 * V_6 ;
T_1 * V_46 ;
int V_47 ;
if ( V_42 != V_44 -> V_48 . V_42 )
goto V_49;
V_45 = V_20 / 8 ;
for ( V_7 = 0 ; V_7 < V_45 ; V_7 ++ ) {
V_46 = ( T_1 * ) ( V_12 + V_7 * 2 ) ;
V_4 = V_46 [ 0 ] >> 4 ;
if ( V_4 >= V_44 -> V_50 -> V_51 )
goto V_49;
V_47 = F_1 ( V_46 [ 1 ] ) ;
if ( V_47 <= 0 ) {
for ( V_47 = 1 ; V_47 < 4 ; V_47 ++ ) {
if ( V_46 [ V_47 ] == 0xf7 )
break;
}
if ( V_47 == 4 )
V_47 = 3 ;
}
V_6 = F_5 ( V_44 -> V_52 [ V_4 ] ) ;
if ( V_6 != NULL )
F_19 ( V_6 , V_46 + 1 , V_47 ) ;
}
V_49:
F_20 ( V_17 , V_38 , V_22 ) ;
}
int F_21 ( struct V_43 * V_44 )
{
static const struct V_53 V_54 = {
. V_55 = 0xffffe0000000ull ,
. V_49 = 0xffffe000ffffull ,
} ;
unsigned int V_7 ;
int V_56 ;
V_44 -> V_48 . V_20 = 8 * 8 ;
V_44 -> V_48 . V_57 = F_18 ;
V_44 -> V_48 . V_21 = V_44 ;
V_56 = F_22 ( & V_44 -> V_48 ,
& V_54 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_23 ( V_44 ) ;
if ( V_56 < 0 )
goto error;
for ( V_7 = 0 ; V_7 < V_58 ; V_7 ++ ) {
V_44 -> V_59 [ V_7 ] . V_30 = F_24 ( V_44 -> V_60 ) ;
V_44 -> V_59 [ V_7 ] . V_24 = 0 ;
F_25 ( & V_44 -> V_59 [ V_7 ] . V_26 , F_10 ) ;
}
return V_56 ;
error:
F_26 ( & V_44 -> V_48 ) ;
V_44 -> V_48 . V_21 = NULL ;
return V_56 ;
}
int F_23 ( struct V_43 * V_44 )
{
struct V_61 * V_62 = F_24 ( V_44 -> V_60 ) ;
T_4 V_63 ;
int V_56 ;
V_63 = F_27 ( ( V_62 -> V_17 -> V_33 << 16 ) |
( V_44 -> V_48 . V_42 >> 32 ) ) ;
V_56 = F_28 ( V_44 -> V_60 , V_32 ,
V_35 + V_64 ,
& V_63 , sizeof( V_63 ) , 0 ) ;
if ( V_56 < 0 )
return V_56 ;
V_63 = F_27 ( V_44 -> V_48 . V_42 ) ;
V_56 = F_28 ( V_44 -> V_60 , V_32 ,
V_35 + V_65 ,
& V_63 , sizeof( V_63 ) , 0 ) ;
if ( V_56 < 0 )
return V_56 ;
V_63 = F_27 ( 0x00000001 ) ;
V_56 = F_28 ( V_44 -> V_60 , V_32 ,
V_35 + V_66 ,
& V_63 , sizeof( V_63 ) , 0 ) ;
if ( V_56 < 0 )
return V_56 ;
V_63 = F_27 ( 0x0001008e ) ;
return F_28 ( V_44 -> V_60 , V_32 ,
V_35 + V_67 ,
& V_63 , sizeof( V_63 ) , 0 ) ;
}
void F_29 ( struct V_43 * V_44 )
{
T_4 V_63 ;
if ( V_44 -> V_48 . V_21 == NULL )
return;
V_63 = F_27 ( 0x0000008e ) ;
F_28 ( V_44 -> V_60 , V_32 ,
V_35 + V_67 ,
& V_63 , sizeof( V_63 ) , 0 ) ;
V_63 = F_27 ( 0x00000000 ) ;
F_28 ( V_44 -> V_60 , V_32 ,
V_35 + V_66 ,
& V_63 , sizeof( V_63 ) , 0 ) ;
F_28 ( V_44 -> V_60 , V_32 ,
V_35 + V_64 ,
& V_63 , sizeof( V_63 ) , 0 ) ;
F_28 ( V_44 -> V_60 , V_32 ,
V_35 + V_65 ,
& V_63 , sizeof( V_63 ) , 0 ) ;
F_26 ( & V_44 -> V_48 ) ;
V_44 -> V_48 . V_21 = NULL ;
}
