static void F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 )
{
int V_4 , V_5 , V_6 , V_7 = ( V_3 - V_2 ) ;
V_8 [ 0 ] = V_1 ;
for ( V_5 = 1 ; V_5 < ( V_9 / 16 ) ; ++ V_5 )
V_8 [ V_5 ] = V_2 ;
V_6 = V_9 * 15 / 16 ;
for ( V_4 = 0 ; V_4 < V_6 ; ++ V_4 )
V_8 [ V_5 + V_4 ] = V_2 + ( V_7 * ( V_4 + 1 ) / V_6 ) ;
}
static int F_2 ( int V_10 )
{
int V_11 = ( V_9 - 1 ) ;
int V_4 , V_3 = 0 ;
for ( V_4 = 0 ; V_4 < V_9 ; V_4 ++ )
V_3 = V_3 ( ( int ) V_8 [ V_4 ] , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_9 ; V_4 ++ ) {
int V_12 = abs ( V_8 [ V_4 ] - V_10 ) ;
if ( V_12 < V_3 ) {
V_3 = V_12 ;
V_11 = V_4 ;
}
}
return V_11 ;
}
static int F_3 ( int V_11 )
{
int V_13 ;
V_13 = V_8 [ V_11 ] * V_14 / V_15 ;
if ( V_13 < 0 )
V_13 = 0 ;
else if ( V_13 > V_15 )
V_13 = V_15 ;
return V_13 ;
}
static int F_4 ( struct V_16 * V_17 )
{
struct V_18 V_19 ;
int V_11 = V_17 -> V_20 . V_21 ;
if ( V_17 -> V_20 . V_22 != V_23 ||
V_17 -> V_20 . V_24 != V_23 )
V_11 = 0 ;
if ( V_11 > 0 ) {
int V_13 = F_3 ( V_11 ) ;
F_5 ( & V_19 , NULL , 2 , V_25 , V_13 ) ;
F_6 ( & V_19 ) ;
F_5 ( & V_19 , NULL , 2 , V_26 ,
V_27 | V_28 ) ;
F_6 ( & V_19 ) ;
} else {
F_5 ( & V_19 , NULL , 2 , V_26 ,
V_27 | V_29 ) ;
F_6 ( & V_19 ) ;
}
return 0 ;
}
static int F_7 ( struct V_16 * V_17 )
{
unsigned long V_30 ;
int V_31 = 0 ;
F_8 ( & V_32 , V_30 ) ;
if ( ! V_33 )
V_31 = F_4 ( V_17 ) ;
F_9 ( & V_32 , V_30 ) ;
return V_31 ;
}
static int F_10 ( struct V_16 * V_17 )
{
return V_17 -> V_20 . V_21 ;
}
void F_11 ( int V_34 )
{
unsigned long V_30 ;
F_8 ( & V_32 , V_30 ) ;
V_33 = V_34 ;
if ( V_35 && V_36 ) {
if ( V_34 ) {
struct V_18 V_19 ;
F_5 ( & V_19 , NULL , 2 , V_26 ,
V_27 | V_29 ) ;
F_6 ( & V_19 ) ;
} else
F_4 ( V_35 ) ;
}
F_9 ( & V_32 , V_30 ) ;
}
void T_2 F_12 ()
{
struct V_37 V_20 ;
struct V_16 * V_17 ;
char V_38 [ 10 ] ;
int V_11 , V_39 ;
V_39 =
F_13 ( L_1 ) ||
F_13 ( L_2 ) ;
if ( ! V_39 &&
! F_14 ( L_3 ) &&
! F_13 ( L_4 ) &&
! F_13 ( L_5 ) )
return;
snprintf ( V_38 , sizeof( V_38 ) , L_6 ) ;
memset ( & V_20 , 0 , sizeof( struct V_37 ) ) ;
V_20 . type = V_40 ;
V_20 . V_41 = V_9 - 1 ;
V_17 = F_15 ( V_38 , NULL , NULL , & V_42 ,
& V_20 ) ;
if ( F_16 ( V_17 ) ) {
F_17 ( V_43 L_7 ) ;
return;
}
V_36 = 1 ;
F_1 ( 0x7F , 0x46 , 0x0E ) ;
V_11 = V_17 -> V_20 . V_41 ;
if ( V_39 ) {
struct V_18 V_19 ;
F_5 ( & V_19 , NULL , 2 , 0xd9 , 0 ) ;
F_6 ( & V_19 ) ;
V_11 = F_2 (
( V_19 . V_44 [ 0 ] >> 4 ) *
V_17 -> V_20 . V_41 / 15 ) ;
}
V_17 -> V_20 . V_21 = V_11 ;
V_17 -> V_20 . V_22 = V_23 ;
F_18 ( V_17 ) ;
F_17 ( V_45 L_8 , V_38 ) ;
}
