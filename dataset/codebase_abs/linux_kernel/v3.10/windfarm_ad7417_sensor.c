static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_7 [ 2 ] ;
T_3 V_8 ;
int V_9 ;
* V_3 = 0 ;
F_2 ( & V_5 -> V_10 ) ;
V_7 [ 0 ] = 0 ;
V_9 = F_3 ( V_5 -> V_11 , V_7 , 1 ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_4 ( V_5 -> V_11 , V_7 , 2 ) ;
if ( V_9 < 0 )
goto error;
V_8 = F_5 ( ( V_12 * ) V_7 ) ;
* V_3 = ( ( T_1 ) V_8 ) << 8 ;
F_6 ( & V_5 -> V_10 ) ;
return 0 ;
error:
F_6 ( & V_5 -> V_10 ) ;
return - 1 ;
}
static void F_7 ( struct V_4 * V_5 ,
int V_13 , T_1 V_8 , T_1 * V_3 )
{
switch( V_13 ) {
case 1 :
* V_3 = ( V_8 * ( T_1 ) V_5 -> V_14 -> V_15 +
( ( T_1 ) V_5 -> V_14 -> V_16 << 12 ) ) >> 2 ;
break;
case 2 :
* V_3 = V_8 * V_17 ;
break;
case 3 :
* V_3 = V_8 * V_18 ;
break;
case 4 :
* V_3 = V_8 * V_19 ;
break;
}
}
static int F_8 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_13 = V_2 - V_5 -> V_20 ;
int V_21 , V_9 ;
T_2 V_7 [ 2 ] ;
T_4 V_8 ;
* V_3 = 0 ;
F_2 ( & V_5 -> V_10 ) ;
for ( V_21 = 0 ; V_21 < 10 ; V_21 ++ ) {
V_7 [ 0 ] = 1 ;
V_7 [ 1 ] = ( V_5 -> V_22 & 0x1f ) | ( V_13 << 5 ) ;
V_9 = F_3 ( V_5 -> V_11 , V_7 , 2 ) ;
if ( V_9 < 0 )
goto error;
F_9 ( 1 ) ;
V_7 [ 0 ] = 4 ;
V_9 = F_3 ( V_5 -> V_11 , V_7 , 1 ) ;
if ( V_9 < 0 )
goto error;
V_9 = F_4 ( V_5 -> V_11 , V_7 , 2 ) ;
if ( V_9 < 0 )
goto error;
V_8 = F_5 ( ( V_12 * ) V_7 ) >> 6 ;
F_7 ( V_5 , V_13 , V_8 , V_3 ) ;
F_10 ( & V_5 -> V_11 -> V_23 , L_1
L_2 ,
V_13 , V_2 -> V_24 , V_8 , * V_3 ) ;
F_6 ( & V_5 -> V_10 ) ;
return 0 ;
error:
F_11 ( & V_5 -> V_11 -> V_23 ,
L_3 , V_21 ) ;
if ( V_21 < 9 )
F_9 ( 10 ) ;
}
F_6 ( & V_5 -> V_10 ) ;
return - 1 ;
}
static void F_12 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = F_13 ( V_26 ,
struct V_4 , V_26 ) ;
F_14 ( V_5 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_14 ( V_2 -> V_24 ) ;
F_16 ( & V_5 -> V_26 , F_12 ) ;
}
static void F_17 ( struct V_4 * V_5 ,
int V_27 , const char * V_24 ,
const struct V_28 * V_29 )
{
V_5 -> V_20 [ V_27 ] . V_24 = F_18 ( V_30 , L_4 , V_24 , V_5 -> V_31 ) ;
V_5 -> V_20 [ V_27 ] . V_6 = V_5 ;
V_5 -> V_20 [ V_27 ] . V_29 = V_29 ;
if ( ! F_19 ( & V_5 -> V_20 [ V_27 ] ) )
F_20 ( & V_5 -> V_26 ) ;
}
static void F_21 ( struct V_4 * V_5 )
{
int V_9 ;
T_2 V_7 [ 2 ] ;
T_2 V_22 = 0 ;
V_7 [ 0 ] = 5 ;
V_7 [ 1 ] = 0 ;
F_3 ( V_5 -> V_11 , V_7 , 2 ) ;
V_7 [ 0 ] = 1 ;
V_9 = F_3 ( V_5 -> V_11 , V_7 , 1 ) ;
if ( V_9 > 0 ) {
V_9 = F_4 ( V_5 -> V_11 , V_7 , 1 ) ;
if ( V_9 > 0 ) {
V_22 = V_7 [ 0 ] ;
F_11 ( & V_5 -> V_11 -> V_23 , L_5 ,
V_22 ) ;
V_22 &= 0xfe ;
V_7 [ 0 ] = 1 ;
V_7 [ 1 ] = V_22 ;
V_9 = F_3 ( V_5 -> V_11 , V_7 , 2 ) ;
}
}
if ( V_9 <= 0 )
F_22 ( & V_5 -> V_11 -> V_23 , L_6 ) ;
V_5 -> V_22 = V_22 ;
}
static int F_23 ( struct V_32 * V_33 ,
const struct V_34 * V_35 )
{
struct V_4 * V_5 ;
const struct V_36 * V_14 ;
const char * V_37 ;
int V_38 ;
V_37 = F_24 ( V_33 -> V_23 . V_39 , L_7 , NULL ) ;
if ( ! V_37 ) {
F_25 ( & V_33 -> V_23 , L_8 ) ;
return - V_40 ;
}
if ( ! strncmp ( V_37 , L_9 , 5 ) )
V_38 = 0 ;
else if ( ! strncmp ( V_37 , L_10 , 5 ) )
V_38 = 1 ;
else {
F_26 ( L_11 , V_37 ) ;
return - V_40 ;
}
V_14 = F_27 ( V_38 ) ;
if ( ! V_14 ) {
F_22 ( & V_33 -> V_23 , L_12 ) ;
return - V_40 ;
}
V_5 = F_28 ( sizeof( struct V_4 ) , V_30 ) ;
if ( V_5 == NULL )
return - V_41 ;
F_29 ( & V_5 -> V_26 ) ;
F_30 ( & V_5 -> V_10 ) ;
V_5 -> V_11 = V_33 ;
V_5 -> V_31 = V_38 ;
V_5 -> V_14 = V_14 ;
F_31 ( & V_33 -> V_23 , V_5 ) ;
F_21 ( V_5 ) ;
F_17 ( V_5 , 0 , L_13 , & V_42 ) ;
F_17 ( V_5 , 1 , L_14 , & V_43 ) ;
F_17 ( V_5 , 2 , L_15 , & V_43 ) ;
F_17 ( V_5 , 3 , L_16 , & V_43 ) ;
F_17 ( V_5 , 4 , L_17 , & V_43 ) ;
return 0 ;
}
static int F_32 ( struct V_32 * V_33 )
{
struct V_4 * V_5 = F_33 ( & V_33 -> V_23 ) ;
int V_21 ;
V_5 -> V_11 = NULL ;
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ )
F_34 ( & V_5 -> V_20 [ V_21 ] ) ;
F_16 ( & V_5 -> V_26 , F_12 ) ;
return 0 ;
}
static int F_35 ( void )
{
if ( ! F_36 ( L_18 ) &&
! F_36 ( L_19 ) &&
! F_36 ( L_20 ) )
return - V_41 ;
return F_37 ( & V_44 ) ;
}
static void F_38 ( void )
{
F_39 ( & V_44 ) ;
}
