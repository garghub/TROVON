void
F_1 ( int V_1 , unsigned char * V_2 , int V_3 )
{
switch ( V_2 [ 0 ] & 0xf0 )
{
case 0x90 :
if ( V_2 [ 2 ] != 0 )
{
F_2 ( F_3 ( V_1 , V_2 [ 0 ] & 0x0f , V_2 [ 1 ] , V_2 [ 2 ] ) ) ;
break;
}
V_2 [ 2 ] = 64 ;
case 0x80 :
F_2 ( F_4 ( V_1 , V_2 [ 0 ] & 0x0f , V_2 [ 1 ] , V_2 [ 2 ] ) ) ;
break;
case 0xA0 :
F_2 ( F_5 ( V_1 , V_2 [ 0 ] & 0x0f , V_2 [ 1 ] , V_2 [ 2 ] ) ) ;
break;
case 0xB0 :
F_2 ( F_6 ( V_1 , V_2 [ 0 ] & 0x0f ,
V_2 [ 1 ] , V_2 [ 2 ] ) ) ;
break;
case 0xC0 :
F_2 ( F_7 ( V_1 , V_2 [ 0 ] & 0x0f , V_2 [ 1 ] ) ) ;
break;
case 0xD0 :
F_2 ( F_8 ( V_1 , V_2 [ 0 ] & 0x0f , V_2 [ 1 ] ) ) ;
break;
case 0xE0 :
F_2 ( F_9 ( V_1 , V_2 [ 0 ] & 0x0f ,
( V_2 [ 1 ] & 0x7f ) | ( ( V_2 [ 2 ] & 0x7f ) << 7 ) ) ) ;
break;
default:
;
}
}
static void
F_10 ( int V_4 , int V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < 3200 ; V_6 ++ )
if ( V_7 [ V_4 ] -> F_11 ( V_4 , ( unsigned char ) ( V_5 & 0xff ) ) )
{
if ( V_5 & 0x80 )
V_8 [ V_4 ] =
( unsigned char ) ( V_5 & 0xff ) ;
return;
}
F_12 ( L_1 ) ;
}
static int
F_13 ( int V_4 , unsigned char V_9 )
{
if ( ( char * ) V_7 [ V_4 ] -> F_13 == NULL )
return 1 ;
return V_7 [ V_4 ] -> F_13 ( V_4 , V_9 ) ;
}
static void
F_14 ( int V_10 , unsigned char V_5 )
{
int V_11 ;
struct V_12 * V_13 ;
static unsigned char V_14 [] =
{
2 ,
2 ,
2 ,
2 ,
1 ,
1 ,
2 ,
0
} ;
if ( V_10 < 0 || V_10 > V_15 || V_7 [ V_10 ] == NULL )
return;
if ( V_5 == 0xfe )
return;
V_11 = V_16 [ V_10 ] ;
V_13 = & V_7 [ V_10 ] -> V_17 ;
switch ( V_13 -> V_18 )
{
case V_19 :
if ( V_5 & 0x80 )
{
if ( ( V_5 & 0xf0 ) == 0xf0 )
{
switch ( V_5 )
{
case 0xf0 :
V_13 -> V_18 = V_20 ;
break;
case 0xf1 :
case 0xf3 :
V_13 -> V_18 = V_21 ;
V_13 -> V_22 = 1 ;
V_13 -> V_23 = 1 ;
V_13 -> V_24 [ 0 ] = V_5 ;
break;
case 0xf2 :
V_13 -> V_18 = V_21 ;
V_13 -> V_22 = 1 ;
V_13 -> V_23 = 2 ;
V_13 -> V_24 [ 0 ] = V_5 ;
break;
default:
V_13 -> V_24 [ 0 ] = V_5 ;
V_13 -> V_22 = 1 ;
F_1 ( V_11 , V_13 -> V_24 , V_13 -> V_22 ) ;
V_13 -> V_22 = 0 ;
V_13 -> V_23 = 0 ;
}
} else
{
V_13 -> V_18 = V_21 ;
V_13 -> V_22 = 1 ;
V_13 -> V_23 = V_14 [ ( V_5 >> 4 ) - 8 ] ;
V_13 -> V_24 [ 0 ] = V_13 -> V_25 = V_5 ;
}
} else if ( V_13 -> V_25 & 0x80 ) {
V_13 -> V_22 = 2 ;
V_13 -> V_24 [ 1 ] = V_5 ;
V_13 -> V_24 [ 0 ] = V_13 -> V_25 ;
V_13 -> V_23 = V_14 [ ( V_13 -> V_24 [ 0 ] >> 4 ) - 8 ] - 1 ;
if ( V_13 -> V_23 > 0 )
V_13 -> V_18 = V_21 ;
else {
V_13 -> V_18 = V_19 ;
F_1 ( V_11 , V_13 -> V_24 , V_13 -> V_22 ) ;
V_13 -> V_22 = 0 ;
}
}
break;
case V_21 :
V_13 -> V_24 [ V_13 -> V_22 ++ ] = V_5 ;
if ( -- V_13 -> V_23 <= 0 )
{
V_13 -> V_18 = V_19 ;
F_1 ( V_11 , V_13 -> V_24 , V_13 -> V_22 ) ;
V_13 -> V_22 = 0 ;
}
break;
case V_20 :
if ( V_5 == 0xf7 )
{
V_13 -> V_18 = V_19 ;
V_13 -> V_23 = 0 ;
V_13 -> V_22 = 0 ;
}
break;
default:
F_12 ( L_2 , V_10 , V_13 -> V_18 , ( int ) V_5 ) ;
V_13 -> V_18 = V_19 ;
}
}
static void
F_15 ( int V_11 )
{
int V_10 = V_26 [ V_11 ] -> V_4 ;
int V_6 = 0 ;
if ( ! V_27 [ V_11 ] )
return;
V_27 [ V_11 ] = 0 ;
while ( ! V_7 [ V_10 ] -> F_11 ( V_10 , 0xf7 ) &&
V_6 < 1000 )
V_6 ++ ;
V_27 [ V_11 ] = 0 ;
}
static void
F_16 ( int V_11 )
{
}
int F_17 ( int V_11 , unsigned int V_28 , void T_1 * V_29 )
{
switch ( V_28 ) {
case V_30 :
if ( F_18 ( V_29 , V_26 [ V_11 ] -> V_31 , sizeof( struct V_32 ) ) )
return - V_33 ;
return 0 ;
case V_34 :
return 0x7fffffff ;
default:
return - V_35 ;
}
}
int
F_19 ( int V_11 , int V_36 , int V_37 , int V_38 )
{
int V_10 = V_26 [ V_11 ] -> V_4 ;
int V_2 , V_39 ;
if ( V_37 < 0 || V_37 > 127 )
return 0 ;
if ( V_36 < 0 || V_36 > 15 )
return 0 ;
if ( V_38 < 0 )
V_38 = 0 ;
if ( V_38 > 127 )
V_38 = 127 ;
F_15 ( V_11 ) ;
V_2 = V_8 [ V_10 ] & 0xf0 ;
V_39 = V_8 [ V_10 ] & 0x0f ;
if ( V_39 == V_36 && ( ( V_2 == 0x90 && V_38 == 64 ) || V_2 == 0x80 ) )
{
if ( ! F_13 ( V_10 , V_37 ) )
return 0 ;
F_10 ( V_10 , V_37 ) ;
if ( V_2 == 0x90 )
F_10 ( V_10 , 0 ) ;
else
F_10 ( V_10 , V_38 ) ;
} else
{
if ( V_38 == 64 )
{
if ( ! F_13 ( V_10 , 0x90 | ( V_36 & 0x0f ) ) )
return 0 ;
F_10 ( V_10 , 0x90 | ( V_36 & 0x0f ) ) ;
F_10 ( V_10 , V_37 ) ;
F_10 ( V_10 , 0 ) ;
} else
{
if ( ! F_13 ( V_10 , 0x80 | ( V_36 & 0x0f ) ) )
return 0 ;
F_10 ( V_10 , 0x80 | ( V_36 & 0x0f ) ) ;
F_10 ( V_10 , V_37 ) ;
F_10 ( V_10 , V_38 ) ;
}
}
return 0 ;
}
int
F_20 ( int V_11 , int V_36 , int V_40 )
{
int V_10 = V_26 [ V_11 ] -> V_4 ;
if ( V_40 < 0 || V_40 > 127 )
V_40 = 0 ;
if ( V_36 < 0 || V_36 > 15 )
return 0 ;
F_15 ( V_11 ) ;
if ( ! F_13 ( V_10 , 0xc0 | ( V_36 & 0x0f ) ) )
return 0 ;
F_10 ( V_10 , 0xc0 | ( V_36 & 0x0f ) ) ;
F_10 ( V_10 , V_40 ) ;
return 0 ;
}
int
F_21 ( int V_11 , int V_36 , int V_37 , int V_38 )
{
int V_10 = V_26 [ V_11 ] -> V_4 ;
int V_2 , V_39 ;
if ( V_37 < 0 || V_37 > 127 )
return 0 ;
if ( V_36 < 0 || V_36 > 15 )
return 0 ;
if ( V_38 < 0 )
V_38 = 0 ;
if ( V_38 > 127 )
V_38 = 127 ;
F_15 ( V_11 ) ;
V_2 = V_8 [ V_10 ] & 0xf0 ;
V_39 = V_8 [ V_10 ] & 0x0f ;
if ( V_39 == V_36 && V_2 == 0x90 )
{
if ( ! F_13 ( V_10 , V_37 ) )
return 0 ;
F_10 ( V_10 , V_37 ) ;
F_10 ( V_10 , V_38 ) ;
} else
{
if ( ! F_13 ( V_10 , 0x90 | ( V_36 & 0x0f ) ) )
return 0 ;
F_10 ( V_10 , 0x90 | ( V_36 & 0x0f ) ) ;
F_10 ( V_10 , V_37 ) ;
F_10 ( V_10 , V_38 ) ;
}
return 0 ;
}
void
F_22 ( int V_11 )
{
F_15 ( V_11 ) ;
}
int
F_23 ( int V_11 , int V_41 )
{
int V_10 = V_26 [ V_11 ] -> V_4 ;
int V_42 ;
struct V_12 * V_13 ;
if ( V_10 < 0 || V_10 >= V_15 || V_7 [ V_10 ] == NULL )
return - V_43 ;
V_16 [ V_10 ] = V_11 ;
V_27 [ V_11 ] = 0 ;
V_8 [ V_10 ] = 0 ;
if ( ( V_42 = V_7 [ V_10 ] -> F_24 ( V_10 , V_41 ,
F_14 , F_16 ) ) < 0 )
return V_42 ;
V_13 = & V_7 [ V_10 ] -> V_17 ;
V_13 -> V_44 = 0 ;
V_13 -> V_18 = V_19 ;
V_13 -> V_22 = 0 ;
V_13 -> V_23 = 0 ;
V_13 -> V_25 = 0x00 ;
return 1 ;
}
void
F_25 ( int V_11 )
{
int V_10 = V_26 [ V_11 ] -> V_4 ;
F_15 ( V_11 ) ;
V_7 [ V_10 ] -> F_11 ( V_10 , 0xfe ) ;
V_7 [ V_10 ] -> F_26 ( V_10 ) ;
}
void
F_27 ( int V_11 , unsigned char * V_45 )
{
}
int
F_28 ( int V_11 , int V_46 , const char T_1 * V_47 ,
int V_48 , int V_49 )
{
int V_10 = V_26 [ V_11 ] -> V_4 ;
struct V_50 V_51 ;
int V_52 ;
unsigned long V_53 , V_54 , V_55 = 0 ;
int V_56 = 1 ;
int V_57 = ( unsigned long ) & V_51 . V_5 [ 0 ] - ( unsigned long ) & V_51 ;
F_15 ( V_11 ) ;
if ( ! F_13 ( V_10 , 0xf0 ) )
return 0 ;
if ( V_46 != V_58 )
return - V_35 ;
if ( V_48 < V_57 )
return - V_35 ;
V_48 -= V_57 ;
if ( F_29 ( & V_51 , V_47 , V_57 ) )
return - V_33 ;
if ( ( unsigned ) V_48 < ( unsigned ) V_51 . V_59 )
V_51 . V_59 = V_48 ;
V_53 = V_51 . V_59 ;
V_54 = 0 ;
for ( V_52 = 0 ; V_52 < V_53 && ! F_30 ( V_60 ) ; V_52 ++ )
{
unsigned char V_5 ;
if ( F_31 ( V_5 ,
( unsigned char T_1 * ) ( V_47 + V_57 + V_52 ) ) )
return - V_33 ;
V_55 = ( V_52 > 0 && V_5 & 0x80 ) ;
if ( V_55 && V_5 != 0xf7 )
V_5 = 0xf7 ;
if ( V_52 == 0 )
{
if ( V_5 != 0xf0 )
{
F_12 ( V_61 L_3 ) ;
return - V_35 ;
}
}
while ( ! V_7 [ V_10 ] -> F_11 ( V_10 , ( unsigned char ) ( V_5 & 0xff ) ) &&
! F_30 ( V_60 ) )
F_32 () ;
if ( ! V_56 && V_5 & 0x80 )
return 0 ;
V_56 = 0 ;
}
if ( ! V_55 )
F_10 ( V_10 , 0xf7 ) ;
return 0 ;
}
void F_33 ( int V_11 , int V_36 , int V_62 )
{
}
void F_34 ( int V_11 , int V_36 , int V_62 )
{
int V_10 = V_26 [ V_11 ] -> V_4 ;
int V_2 , V_39 ;
if ( V_62 < 0 || V_62 > 127 )
return;
if ( V_36 < 0 || V_36 > 15 )
return;
F_15 ( V_11 ) ;
V_2 = V_8 [ V_10 ] & 0xf0 ;
V_39 = V_8 [ V_10 ] & 0x0f ;
if ( V_2 != 0xd0 || V_39 != V_36 )
{
if ( ! F_13 ( V_10 , 0xd0 | ( V_36 & 0x0f ) ) )
return;
F_10 ( V_10 , 0xd0 | ( V_36 & 0x0f ) ) ;
} else if ( ! F_13 ( V_10 , V_62 ) )
return;
F_10 ( V_10 , V_62 ) ;
}
void
F_35 ( int V_11 , int V_36 , int V_63 , int V_64 )
{
int V_10 = V_26 [ V_11 ] -> V_4 ;
int V_39 , V_2 ;
if ( V_63 < 0 || V_63 > 127 )
return;
if ( V_36 < 0 || V_36 > 15 )
return;
F_15 ( V_11 ) ;
V_2 = V_8 [ V_10 ] & 0xf0 ;
V_39 = V_8 [ V_10 ] & 0x0f ;
if ( V_2 != 0xb0 || V_39 != V_36 )
{
if ( ! F_13 ( V_10 , 0xb0 | ( V_36 & 0x0f ) ) )
return;
F_10 ( V_10 , 0xb0 | ( V_36 & 0x0f ) ) ;
} else if ( ! F_13 ( V_10 , V_63 ) )
return;
F_10 ( V_10 , V_63 ) ;
F_10 ( V_10 , V_64 & 0x7f ) ;
}
void
F_36 ( int V_11 , int V_36 , int V_64 )
{
int V_10 = V_26 [ V_11 ] -> V_4 ;
int V_2 , V_65 ;
if ( V_36 < 0 || V_36 > 15 )
return;
if ( V_64 < 0 || V_64 > 16383 )
return;
F_15 ( V_11 ) ;
V_2 = V_8 [ V_10 ] & 0xf0 ;
V_65 = V_8 [ V_10 ] & 0x0f ;
if ( V_2 != 0xd0 || V_65 != V_36 )
{
if ( ! F_13 ( V_10 , 0xe0 | ( V_36 & 0x0f ) ) )
return;
F_10 ( V_10 , 0xe0 | ( V_36 & 0x0f ) ) ;
} else if ( ! F_13 ( V_10 , V_64 & 0x7f ) )
return;
F_10 ( V_10 , V_64 & 0x7f ) ;
F_10 ( V_10 , ( V_64 >> 7 ) & 0x7f ) ;
}
void
F_37 ( int V_11 , int V_66 , int V_36 )
{
}
int
F_38 ( int V_11 , unsigned char * V_67 , int V_59 )
{
int V_10 = V_26 [ V_11 ] -> V_4 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_59 ; V_52 ++ )
{
switch ( V_67 [ V_52 ] )
{
case 0xf0 :
if ( ! F_13 ( V_10 , 0xf0 ) )
return 0 ;
V_27 [ V_11 ] = 1 ;
break;
case 0xf7 :
if ( ! V_27 [ V_11 ] )
return 0 ;
V_27 [ V_11 ] = 0 ;
break;
default:
if ( ! V_27 [ V_11 ] )
return 0 ;
if ( V_67 [ V_52 ] & 0x80 )
{
V_67 [ V_52 ] = 0xf7 ;
V_27 [ V_11 ] = 0 ;
}
}
if ( ! V_7 [ V_10 ] -> F_11 ( V_10 , V_67 [ V_52 ] ) )
{
int V_6 = 0 ;
V_67 [ V_52 ] = 0xf7 ;
V_27 [ V_11 ] = 0 ;
while ( ! V_7 [ V_10 ] -> F_11 ( V_10 , V_67 [ V_52 ] ) &&
V_6 < 1000 )
V_6 ++ ;
}
if ( ! V_27 [ V_11 ] )
return 0 ;
}
return 0 ;
}
