int F_1 ( unsigned int V_1 , unsigned char * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
* V_2 ++ = F_2 ( V_1 ++ ) ;
return 0 ;
}
int F_3 ( unsigned int V_1 , unsigned char * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
F_4 ( V_1 ++ , * V_2 ++ ) ;
return 0 ;
}
static void F_5 ( void )
{
unsigned long * V_5 = V_6 . V_7 ;
unsigned long * V_8 = V_6 . V_9 ;
int V_4 ;
V_8 [ V_10 ] = 0x40000 ;
V_8 [ V_11 ] = 0xC0000 ;
V_8 [ V_12 ] = 0x100000 ;
if ( ! F_6 () ) {
V_6 . V_13 = 0x1e000000 ;
V_5 [ V_10 ] = 0x1e400000 ;
if ( V_6 . V_14 > 0x200000 ) {
V_8 [ V_15 ] = 0x100000 ;
V_8 [ V_16 ] = 0x500000 ;
}
} else {
V_6 . V_13 = 0x10000000 ;
if ( V_6 . V_14 < 0x1000000 ) {
V_5 [ V_10 ] = 0x10000000 ;
V_8 [ V_15 ] = 0x100000 ;
if ( V_6 . V_14 >= 0x400000 )
V_8 [ V_16 ] =
V_6 . V_14 - 0x300000 ;
}
}
for ( V_4 = 1 ; V_4 < V_17 ; V_4 ++ )
V_5 [ V_4 ] = V_5 [ V_4 - 1 ] + V_8 [ V_4 - 1 ] ;
}
int F_7 ( void )
{
int V_18 ;
unsigned long V_19 ;
unsigned long V_20 , V_21 ;
const struct V_22 * V_23 ;
int V_24 = V_25 ;
const char * const * V_26 = V_27 ;
int V_28 = V_29 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
F_1 ( 0 , ( unsigned char * ) & V_6 . V_30 ,
sizeof( struct V_31 ) ) ;
V_19 = F_8 ( ( unsigned char * ) ( & V_6 . V_30 ) ,
sizeof( struct V_31 ) - 4 ) ;
if ( V_19 != V_6 . V_30 . V_32 ) {
F_9 ( V_33 L_1
L_2 ) ;
}
if ( V_6 . V_30 . V_34 != V_35 ) {
F_9 ( V_33 L_3
L_4 ,
( unsigned int ) V_6 . V_30 . V_34 ,
V_35 ) ;
}
V_20 = V_6 . V_30 . V_36 [ 0 ] ;
V_21 = V_6 . V_30 . V_36 [ 1 ] ;
if ( F_10 ( V_20 ) != 1 ) {
F_9 ( V_33 L_5
L_6
L_7 ) ;
}
switch ( F_11 ( V_20 ) ) {
case 0 :
V_6 . V_37 = 0x0800000 ;
break;
case 1 :
V_6 . V_37 = 0x1000000 ;
break;
case 2 :
V_6 . V_37 = 0x2000000 ;
break;
case 3 :
V_6 . V_37 = 0x4000000 ;
break;
case 4 :
V_6 . V_37 = 0x8000000 ;
break;
default:
V_6 . V_37 = 0 ;
}
switch ( F_12 ( V_20 ) ) {
case 0 :
break;
case 1 :
V_6 . V_37 *= 2 ;
break;
default:
break;
}
switch ( F_13 ( V_20 ) ) {
case 0x0 :
V_6 . V_38 = 60000000 ;
break;
case 0x1 :
V_6 . V_38 = 66000000 ;
break;
case 0x2 :
V_6 . V_38 = 66666667 ;
break;
case 0x3 :
V_6 . V_38 = 80000000 ;
break;
case 0x4 :
V_6 . V_38 = 83333333 ;
break;
case 0x5 :
V_6 . V_38 = 100000000 ;
break;
}
switch ( F_14 ( V_20 ) ) {
case 0x0 :
V_6 . V_39 =
V_6 . V_38 ;
break;
case 0x1 :
V_6 . V_39 =
V_6 . V_38 +
( V_6 . V_38 >> 1 ) ;
break;
case 0x2 :
V_6 . V_39 =
V_6 . V_38 +
V_6 . V_38 ;
break;
case 0x3 :
V_6 . V_39 =
V_6 . V_38 +
V_6 . V_38 +
( V_6 . V_38 >> 1 ) ;
break;
case 0x4 :
V_6 . V_39 =
V_6 . V_38 +
V_6 . V_38 +
V_6 . V_38 ;
break;
}
switch ( F_15 ( V_21 ) ) {
case 0 :
V_6 . V_14 = 0x200000 ;
break;
case 1 :
V_6 . V_14 = 0x400000 ;
break;
case 2 :
V_6 . V_14 = 0x800000 ;
break;
case 3 :
V_6 . V_14 = 0x1000000 ;
break;
case 4 :
V_6 . V_14 = 0x2000000 ;
break;
}
F_5 () ;
V_6 . V_40 = F_16 ( V_20 ) ;
V_6 . V_41 = V_6 . V_30 . V_42 ;
if ( V_6 . V_41 == 0xffff || V_6 . V_41 == 0 )
V_6 . V_41 = V_6 . V_40 ;
if ( V_6 . V_40 > V_24 )
V_6 . V_40 = V_24 ;
strcpy ( V_6 . V_43 ,
V_26 [ V_6 . V_40 ] ) ;
V_18 = V_6 . V_41 ;
if ( V_18 >= V_28 ) {
strcpy ( V_6 . V_44 , L_8 ) ;
strcpy ( V_6 . V_45 , L_9 ) ;
} else {
V_23 = & V_46 [ 0 ] . V_47 [ V_18 ] ;
strcpy ( V_6 . V_44 , V_23 -> V_48 ) ;
if ( V_23 -> V_49 )
strcpy ( V_6 . V_45 , V_23 -> V_49 ) ;
else
sprintf ( V_6 . V_45 , L_10 , 10 * V_18 ) ;
}
return 0 ;
}
void F_17 ( void )
{
unsigned long V_19 ;
F_18 ( & V_50 ) ;
V_19 = F_8 ( ( unsigned char * ) ( & V_6 . V_30 ) ,
sizeof( struct V_31 ) - 4 ) ;
V_6 . V_30 . V_32 = V_19 ;
F_3 ( 0 , ( unsigned char * ) & V_6 . V_30 ,
sizeof( struct V_31 ) ) ;
F_19 ( & V_50 ) ;
}
