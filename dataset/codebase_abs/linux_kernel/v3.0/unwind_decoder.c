static T_1
F_1 ( unsigned char * * V_1 )
{
unsigned V_2 = 0 ;
T_1 V_3 , V_4 = 0 ;
unsigned char * V_5 = * V_1 ;
while ( 1 )
{
V_3 = * V_5 ++ ;
V_4 |= ( V_3 & 0x7f ) << V_2 ;
if ( ( V_3 & 0x80 ) == 0 )
break;
V_2 += 7 ;
}
* V_1 = V_5 ;
return V_4 ;
}
static unsigned char *
F_2 ( unsigned char * V_6 , unsigned char V_7 , void * V_8 )
{
unsigned char V_9 , V_10 ;
T_1 V_11 , V_12 ;
V_9 = * V_6 ++ ;
V_11 = F_1 ( & V_6 ) ;
V_12 = F_1 ( & V_6 ) ;
V_10 = ( V_9 & 0x7f ) ;
if ( V_9 & 0x80 )
F_3 ( V_13 , V_11 , V_10 , V_12 , V_8 ) ;
else
F_4 ( V_13 , V_11 , V_10 , V_12 , V_8 ) ;
return V_6 ;
}
static unsigned char *
F_5 ( unsigned char * V_6 , unsigned char V_7 , void * V_8 )
{
unsigned char V_9 , V_14 , V_10 , V_15 , V_16 ;
T_1 V_11 ;
V_9 = * V_6 ++ ; V_14 = * V_6 ++ ;
V_11 = F_1 ( & V_6 ) ;
V_10 = ( V_9 & 0x7f ) ;
V_16 = V_14 ;
V_15 = ( V_9 >> 7 ) & 1 ;
if ( ( V_9 & 0x80 ) == 0 && V_16 == 0 )
F_6 ( V_17 , V_11 , V_10 , V_8 ) ;
else
F_7 ( V_17 , V_11 , V_10 , V_15 , V_16 , V_8 ) ;
return V_6 ;
}
static unsigned char *
F_8 ( unsigned char * V_6 , unsigned char V_7 , void * V_8 )
{
unsigned char V_9 , V_14 , V_10 , V_18 ;
T_1 V_11 , V_12 ;
V_9 = * V_6 ++ ; V_14 = * V_6 ++ ;
V_11 = F_1 ( & V_6 ) ;
V_12 = F_1 ( & V_6 ) ;
V_18 = ( V_9 & 0x3f ) ;
V_10 = ( V_14 & 0x7f ) ;
if ( V_9 & 0x80 )
F_9 ( V_19 , V_18 , V_11 , V_10 , V_12 , V_8 ) ;
else
F_10 ( V_19 , V_18 , V_11 , V_10 , V_12 , V_8 ) ;
return V_6 ;
}
static unsigned char *
F_11 ( unsigned char * V_6 , unsigned char V_7 , void * V_8 )
{
unsigned char V_9 , V_14 , V_20 , V_18 , V_10 , V_15 , V_16 ;
T_1 V_11 ;
V_9 = * V_6 ++ ; V_14 = * V_6 ++ ; V_20 = * V_6 ++ ;
V_11 = F_1 ( & V_6 ) ;
V_18 = ( V_9 & 0x3f ) ;
V_10 = ( V_14 & 0x7f ) ;
V_15 = ( V_14 >> 7 ) & 1 ;
V_16 = V_20 ;
if ( ( V_14 & 0x80 ) == 0 && V_20 == 0 )
F_12 ( V_21 , V_18 , V_11 , V_10 , V_8 ) ;
else
F_13 ( V_21 , V_18 , V_11 , V_10 , V_15 , V_16 , V_8 ) ;
return V_6 ;
}
static unsigned char *
F_14 ( unsigned char * V_6 , unsigned char V_7 , void * V_8 )
{
int V_22 = ( V_7 & 0x20 ) != 0 ;
T_1 V_23 ;
V_23 = ( V_7 & 0x1f ) ;
F_15 ( V_24 , V_22 , V_23 , V_8 ) ;
return V_6 ;
}
static unsigned char *
F_16 ( unsigned char * V_6 , unsigned char V_7 , void * V_8 )
{
unsigned char V_9 , V_25 , V_26 ;
T_1 V_23 ;
V_9 = * V_6 ++ ;
V_25 = ( ( V_7 & 0x7 ) << 1 ) | ( ( V_9 >> 7 ) & 1 ) ;
V_26 = ( V_9 & 0x7f ) ;
V_23 = F_1 ( & V_6 ) ;
F_17 ( V_27 , V_23 , V_25 , V_26 , V_8 ) ;
return V_6 ;
}
static unsigned char *
F_18 ( unsigned char * V_6 , unsigned char V_7 , void * V_8 )
{
T_1 V_23 ;
V_23 = F_1 ( & V_6 ) ;
F_15 ( V_28 , ( ( V_7 & 0x3 ) == 1 ) , V_23 , V_8 ) ;
return V_6 ;
}
static unsigned char *
F_19 ( unsigned char * V_6 , unsigned char V_7 , void * V_8 )
{
unsigned char V_29 = ( V_7 & 0x1f ) ;
F_20 ( V_30 , V_29 , V_8 ) ;
return V_6 ;
}
static unsigned char *
F_21 ( unsigned char * V_6 , unsigned char V_7 , void * V_8 )
{
if ( ( V_7 & 0x10 ) == 0 )
{
unsigned char V_9 = * V_6 ++ ;
F_22 ( V_31 , ( ( V_7 & 0xf ) << 1 ) | ( ( V_9 >> 7 ) & 1 ) ,
( V_9 & 0x7f ) , V_8 ) ;
}
else if ( ( V_7 & 0x08 ) == 0 )
{
unsigned char V_9 = * V_6 ++ , V_32 , V_33 ;
V_32 = ( ( V_7 & 0x7 ) << 1 ) | ( ( V_9 >> 7 ) & 1 ) ;
V_33 = ( V_9 & 0x7f ) ;
switch ( V_32 )
{
case 0 : F_23 ( V_34 , V_35 , V_33 , V_8 ) ; break;
case 1 : F_23 ( V_34 , V_36 , V_33 , V_8 ) ; break;
case 2 : F_23 ( V_34 , V_37 , V_33 , V_8 ) ; break;
case 3 : F_23 ( V_34 , V_38 , V_33 , V_8 ) ; break;
case 4 : F_23 ( V_34 , V_39 , V_33 , V_8 ) ; break;
case 5 : F_23 ( V_34 , V_40 , V_33 , V_8 ) ; break;
case 6 : F_24 ( V_34 , V_33 , V_8 ) ; break;
case 7 : F_23 ( V_34 , V_41 , V_33 , V_8 ) ; break;
case 8 : F_23 ( V_34 , V_42 , V_33 , V_8 ) ; break;
case 9 : F_23 ( V_34 , V_43 , V_33 , V_8 ) ; break;
case 10 : F_23 ( V_34 , V_44 , V_33 , V_8 ) ; break;
case 11 : F_25 ( V_34 , V_33 , V_8 ) ; break;
default: F_26 ( V_32 ) ; break;
}
}
else if ( ( V_7 & 0x7 ) == 0 )
F_27 ( V_45 , V_6 , V_8 ) ;
else if ( ( V_7 & 0x7 ) == 1 )
{
T_1 V_46 , V_47 , V_9 , V_14 , V_20 ;
V_9 = * V_6 ++ ; V_14 = * V_6 ++ ; V_20 = * V_6 ++ ;
V_46 = ( ( V_9 >> 4 ) & 0xf ) ;
V_47 = ( ( V_9 & 0xf ) << 16 ) | ( V_14 << 8 ) | V_20 ;
F_28 ( V_48 , V_46 , V_47 , V_8 ) ;
}
else
F_26 ( V_7 ) ;
return V_6 ;
}
static unsigned char *
F_29 ( unsigned char * V_6 , unsigned char V_7 , void * V_8 )
{
int V_49 = ( V_7 & 0x10 ) != 0 ;
unsigned char V_25 = ( V_7 & 0x0f ) ;
if ( V_49 )
F_30 ( V_50 , V_25 , V_8 ) ;
else
F_31 ( V_50 , V_25 , V_8 ) ;
return V_6 ;
}
static unsigned char *
F_32 ( unsigned char * V_6 , unsigned char V_7 , void * V_8 )
{
unsigned char V_32 , V_9 , V_14 ;
T_1 V_11 , V_51 ;
if ( ( V_7 & 0x10 ) == 0 )
{
V_32 = ( V_7 & 0xf ) ;
V_11 = F_1 ( & V_6 ) ;
switch ( V_32 )
{
case 0 :
V_51 = F_1 ( & V_6 ) ;
F_33 ( V_52 , V_11 , V_51 , V_8 ) ;
break;
case 1 : F_34 ( V_52 , V_11 , V_8 ) ; break;
case 2 : F_35 ( V_52 , V_11 , V_8 ) ; break;
case 3 : F_36 ( V_52 , V_35 , V_11 , V_8 ) ; break;
case 4 : F_37 ( V_52 , V_36 , V_11 , V_8 ) ; break;
case 5 : F_38 ( V_52 , V_36 , V_11 , V_8 ) ; break;
case 6 : F_37 ( V_52 , V_37 , V_11 , V_8 ) ; break;
case 7 : F_38 ( V_52 , V_37 , V_11 , V_8 ) ; break;
case 8 : F_37 ( V_52 , V_38 , V_11 , V_8 ) ; break;
case 9 : F_38 ( V_52 , V_38 , V_11 , V_8 ) ; break;
case 10 : F_37 ( V_52 , V_40 , V_11 , V_8 ) ; break;
case 11 : F_38 ( V_52 , V_40 , V_11 , V_8 ) ; break;
case 12 : F_37 ( V_52 , V_39 , V_11 , V_8 ) ; break;
case 13 : F_38 ( V_52 , V_39 , V_11 , V_8 ) ; break;
case 14 : F_37 ( V_52 , V_44 , V_11 , V_8 ) ; break;
case 15 : F_38 ( V_52 , V_44 , V_11 , V_8 ) ; break;
default: F_26 ( V_32 ) ; break;
}
}
else
{
switch ( V_7 & 0xf )
{
case 0x0 :
{
V_32 = * V_6 ++ ;
V_11 = F_1 ( & V_6 ) ;
switch ( V_32 )
{
case 1 : F_36 ( V_53 , V_36 , V_11 , V_8 ) ; break;
case 2 : F_36 ( V_53 , V_37 , V_11 , V_8 ) ; break;
case 3 : F_36 ( V_53 , V_38 , V_11 , V_8 ) ; break;
case 4 : F_36 ( V_53 , V_40 , V_11 , V_8 ) ; break;
case 5 : F_36 ( V_53 , V_39 , V_11 , V_8 ) ; break;
case 6 : F_36 ( V_53 , V_44 , V_11 , V_8 ) ; break;
case 7 : F_37 ( V_53 , V_42 , V_11 , V_8 ) ; break;
case 8 : F_38 ( V_53 , V_42 , V_11 , V_8 ) ; break;
case 9 : F_36 ( V_53 , V_42 , V_11 , V_8 ) ; break;
case 10 : F_37 ( V_53 , V_43 , V_11 , V_8 ) ; break;
case 11 : F_38 ( V_53 , V_43 , V_11 , V_8 ) ; break;
case 12 : F_36 ( V_53 , V_43 , V_11 , V_8 ) ; break;
case 13 : F_37 ( V_53 , V_41 , V_11 , V_8 ) ; break;
case 14 : F_38 ( V_53 , V_41 , V_11 , V_8 ) ; break;
case 15 : F_36 ( V_53 , V_41 , V_11 , V_8 ) ; break;
case 16 : F_39 ( V_53 , V_11 , V_8 ) ; break;
case 17 : F_40 ( V_53 , V_11 , V_8 ) ; break;
case 18 : F_41 ( V_53 , V_11 , V_8 ) ; break;
case 19 : F_42 ( V_53 , V_11 , V_8 ) ; break;
default: F_26 ( V_32 ) ; break;
}
}
break;
case 0x1 :
V_9 = * V_6 ++ ; V_14 = * V_6 ++ ;
F_43 ( V_54 , ( V_9 & 0xf ) , ( V_14 & 0x7f ) , V_8 ) ;
break;
case 0xf :
V_9 = * V_6 ++ ; V_14 = * V_6 ++ ;
F_44 ( V_55 , V_9 , V_14 , V_8 ) ;
break;
case 0x9 :
return F_2 ( V_6 , V_7 , V_8 ) ;
case 0xa :
return F_5 ( V_6 , V_7 , V_8 ) ;
case 0xb :
return F_8 ( V_6 , V_7 , V_8 ) ;
case 0xc :
return F_11 ( V_6 , V_7 , V_8 ) ;
default:
F_26 ( V_7 ) ;
break;
}
}
return V_6 ;
}
static unsigned char *
F_45 ( unsigned char * V_6 , unsigned char V_7 , void * V_8 )
{
T_1 V_56 = ( V_7 & 0x1f ) ;
if ( ( V_7 & 0x20 ) != 0 )
F_46 ( V_57 , V_56 , V_8 ) ;
else
F_47 ( V_57 , V_56 , V_8 ) ;
return V_6 ;
}
static unsigned char *
F_48 ( unsigned char * V_6 , unsigned char V_7 , void * V_8 )
{
T_1 V_11 ;
V_11 = F_1 ( & V_6 ) ;
F_49 ( V_58 , V_11 , ( V_7 & 0x1f ) , V_8 ) ;
return V_6 ;
}
static unsigned char *
F_50 ( unsigned char * V_6 , unsigned char V_7 , void * V_8 )
{
T_1 V_11 , V_59 , V_56 ;
if ( ( V_7 & 0x10 ) == 0 )
{
V_11 = F_1 ( & V_6 ) ;
V_59 = F_1 ( & V_6 ) ;
F_49 ( V_60 , V_11 , V_59 , V_8 ) ;
}
else if ( ( V_7 & 0x07 ) == 0 )
{
V_56 = F_1 ( & V_6 ) ;
if ( ( V_7 & 0x08 ) != 0 )
F_46 ( V_61 , V_56 , V_8 ) ;
else
F_47 ( V_61 , V_56 , V_8 ) ;
}
else
switch ( V_7 & 0x7 )
{
case 1 : return F_2 ( V_6 , V_7 , V_8 ) ;
case 2 : return F_5 ( V_6 , V_7 , V_8 ) ;
case 3 : return F_8 ( V_6 , V_7 , V_8 ) ;
case 4 : return F_11 ( V_6 , V_7 , V_8 ) ;
default: F_26 ( V_7 ) ; break;
}
return V_6 ;
}
static inline unsigned char *
F_51 ( unsigned char * V_6 , int V_62 , void * V_8 )
{
T_2 V_63 ;
unsigned char V_7 ;
V_7 = * V_6 ++ ;
V_63 = V_64 [ V_62 ] [ V_7 >> 5 ] ;
V_6 = (* V_63) ( V_6 , V_7 , V_8 ) ;
return V_6 ;
}
