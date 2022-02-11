void F_1 ( char * V_1 , T_1 V_2 , unsigned char * V_3 )
{
int V_4 ;
F_2 (KERN_DEBUG __FILE__ L_1 , msg, cmd) ;
for ( V_4 = 0 ; V_4 < F_3 ( V_2 ) ; V_4 ++ )
F_2 ( L_2 , V_3 [ V_4 ] ) ;
F_2 ( L_3 ) ;
}
int F_4 ( struct V_5 * V_5 , T_1 V_2 , unsigned char * V_3 )
{
int V_6 = F_3 ( V_2 ) ;
int V_7 ;
int V_8 ;
int V_9 , V_10 ;
unsigned long V_11 ;
F_5 ( & V_5 -> V_12 , V_11 ) ;
V_9 = V_5 -> V_13 . V_9 ;
V_10 = V_5 -> V_13 . V_10 ;
if ( F_6 ( V_9 , V_10 , V_14 ) < V_6 + 2 ) {
F_7 ( & V_5 -> V_15 -> V_15 ,
L_4 ) ;
F_8 ( & V_5 -> V_12 , V_11 ) ;
return - 1 ;
}
V_8 = V_9 == V_10 ;
F_9 ( V_5 -> V_13 . V_9 , V_6 + 2 ) ;
V_5 -> V_13 . V_16 [ V_9 ] = F_10 ( V_2 ) ;
F_9 ( V_9 , 1 ) ;
V_5 -> V_13 . V_16 [ V_9 ] = F_3 ( V_2 ) ;
F_9 ( V_9 , 1 ) ;
V_7 = F_11 ( V_9 , V_10 , V_14 ) ;
if ( V_6 < V_7 ) V_7 = V_6 ;
memcpy ( & V_5 -> V_13 . V_16 [ V_9 ] ,
V_3 ,
V_7 ) ;
if ( V_6 != V_7 ) {
memcpy ( & V_5 -> V_13 . V_16 [ 0 ] ,
V_3 + V_7 ,
V_6 - V_7 ) ;
}
F_9 ( V_9 , V_6 ) ;
F_8 ( & V_5 -> V_12 , V_11 ) ;
switch ( V_5 -> V_17 ) {
#ifdef F_12
case V_18 :
if ( V_8 )
F_13 ( V_5 ) ;
break;
#endif
#ifdef F_14
case V_19 :
if ( V_5 -> V_20 && V_8 &&
! F_15 ( V_21 , V_5 -> V_22 ) ) {
F_16 ( V_5 ) ;
}
break;
#endif
}
return 0 ;
}
int F_17 ( struct V_5 * V_5 , T_1 V_23 , unsigned int V_24 )
{
unsigned char V_3 [ 3 ] ;
V_3 [ 0 ] = F_3 ( V_23 ) ;
V_3 [ 1 ] = ( V_24 > 0 ) ? ( ( V_24 > 1 ) ? 0x41 : 0x01 ) : 0 ;
V_3 [ 2 ] = F_3 ( V_24 ) ;
return F_4 ( V_5 , V_25 , V_3 ) ;
}
static int F_18 ( struct V_5 * V_5 , unsigned short V_26 )
{
int V_4 ;
if ( ! V_5 -> V_15 -> V_27 )
return 0 ;
for ( V_4 = 0 ; V_4 < V_5 -> V_15 -> V_27 -> V_28 ; ++ V_4 ) {
if ( F_19 ( V_29 , V_5 -> V_30 [ V_4 ] . V_11 ) &&
( V_5 -> V_30 [ V_4 ] . V_31 . V_32 == V_26 ||
V_5 -> V_30 [ V_4 ] . V_33 . V_32 == V_26 ) ) {
F_20 ( V_34 , V_5 -> V_30 [ V_4 ] . V_11 ) ;
return 0 ;
}
}
F_7 ( & V_5 -> V_15 -> V_15 , L_5 , V_26 ) ;
return - 1 ;
}
void F_21 ( struct V_5 * V_5 , T_1 V_2 , unsigned char * V_3 )
{
struct V_35 * V_15 = V_5 -> V_15 ;
int V_4 ;
static int V_36 = 0 ;
if ( V_36 )
F_7 ( & V_5 -> V_15 -> V_15 ,
L_6 , V_36 ) ;
V_36 ++ ;
#ifdef F_12
if ( F_10 ( V_5 -> V_37 ) == F_10 ( V_2 ) ) {
V_5 -> V_37 = 0 ;
V_5 -> V_38 = V_2 ;
memcpy ( V_5 -> V_39 , V_3 , V_40 ) ;
}
#endif
F_22 ( & V_5 -> V_41 ) ;
if ( ! V_5 -> type ) {
V_36 -- ;
return;
}
switch ( F_10 ( V_2 ) ) {
case 0x01 :
case 0x03 :
if ( F_10 ( V_2 ) == 1 ) {
F_23 ( V_15 , V_42 , ( V_43 ) ( ( ( V_43 ) V_3 [ 1 ] << 8 ) | V_3 [ 0 ] ) ) ;
F_23 ( V_15 , V_44 , ( V_43 ) ( ( ( V_43 ) V_3 [ 3 ] << 8 ) | V_3 [ 2 ] ) ) ;
F_23 ( V_15 , V_45 , 255 - V_3 [ 4 ] ) ;
if ( F_3 ( V_2 ) >= 8 && F_19 ( V_46 , V_15 -> V_47 ) )
F_23 ( V_15 , V_46 , ( V_48 ) V_3 [ 7 ] ) ;
} else {
F_23 ( V_15 , V_49 , ( V_43 ) ( ( ( V_43 ) V_3 [ 1 ] << 8 ) | V_3 [ 0 ] ) ) ;
F_23 ( V_15 , V_50 , 255 - V_3 [ 2 ] ) ;
F_23 ( V_15 , V_51 , 255 - V_3 [ 3 ] ) ;
}
F_23 ( V_15 , V_52 , V_53 [ V_3 [ 6 ] >> 4 ] . V_54 ) ;
F_23 ( V_15 , V_55 , V_53 [ V_3 [ 6 ] >> 4 ] . V_56 ) ;
for ( V_4 = 0 ; V_5 -> type -> V_57 [ V_4 ] >= 0 ; V_4 ++ )
F_24 ( V_15 , V_5 -> type -> V_57 [ V_4 ] , V_3 [ ( V_4 >> 3 ) + 5 ] & ( 1 << ( V_4 & 7 ) ) ) ;
if ( V_4 <= 8 ) {
int V_58 = V_3 [ 6 ] ;
if ( F_19 ( V_59 , V_15 -> V_47 ) ) {
if ( V_58 & 8 ) F_23 ( V_15 , V_59 , - 1 ) ;
else if ( V_58 & 2 ) F_23 ( V_15 , V_59 , 1 ) ;
else F_23 ( V_15 , V_59 , 0 ) ;
}
if ( F_19 ( V_60 , V_15 -> V_47 ) ) {
if ( V_58 & 1 ) F_23 ( V_15 , V_60 , - 1 ) ;
else if ( V_58 & 4 ) F_23 ( V_15 , V_60 , 1 ) ;
else F_23 ( V_15 , V_60 , 0 ) ;
}
}
F_25 ( V_15 ) ;
break;
case 0x02 :
F_24 ( V_15 , V_61 , V_3 [ 0 ] & 0x02 ) ;
F_25 ( V_15 ) ;
V_4 = V_3 [ 1 ] & 0x7f ;
if ( V_3 [ 1 ] & 0x80 ) {
if ( ! F_15 ( V_62 , V_5 -> V_30 [ V_4 ] . V_11 ) ) {
F_26 ( V_15 , V_4 , V_63 ) ;
}
} else if ( F_27 ( V_62 , V_5 -> V_30 [ V_4 ] . V_11 ) ) {
F_26 ( V_15 , V_4 , V_64 ) ;
}
if ( F_3 ( V_2 ) > 3 ) {
int V_65 ;
for ( V_65 = 3 ; V_65 < F_3 ( V_2 ) ; V_65 += 2 )
F_18 ( V_5 , V_3 [ V_65 ] | ( V_3 [ V_65 + 1 ] << 8 ) ) ;
}
break;
}
V_36 -- ;
}
int F_28 ( struct V_5 * V_5 , char * V_66 )
{
switch ( V_5 -> V_17 ) {
case V_19 : {
#ifdef F_14
int V_67 ;
V_5 -> V_68 . V_69 = V_66 [ 0 ] ;
V_5 -> V_70 -> V_15 = V_5 -> V_20 ;
V_67 = F_29 ( V_5 -> V_70 , V_71 ) ;
if ( V_67 ) {
F_30 ( & V_5 -> V_72 -> V_15 ,
L_7 , V_67 ) ;
return - 1 ;
}
F_31 ( V_5 -> V_41 ,
V_5 -> V_70 -> V_67 != - V_73 , V_74 ) ;
if ( V_5 -> V_70 -> V_67 ) {
F_32 ( & V_5 -> V_72 -> V_15 ,
L_8 ,
V_5 -> V_70 -> V_67 ) ;
F_33 ( V_5 -> V_70 ) ;
return - 1 ;
}
#else
F_2 ( V_75 L_9 ) ;
#endif
}
break;
case V_18 :
#ifdef F_12
V_5 -> V_37 = V_76 ;
F_4 ( V_5 , V_76 , V_66 ) ;
F_31 ( V_5 -> V_41 ,
! V_5 -> V_37 , V_74 ) ;
if ( V_5 -> V_37 ) {
V_5 -> V_37 = 0 ;
return - 1 ;
}
#else
F_30 ( & V_5 -> V_15 -> V_15 ,
L_10 ) ;
#endif
break;
default:
F_30 ( & V_5 -> V_15 -> V_15 ,
L_11 ,
V_5 -> V_17 ) ;
break;
}
return - ( V_5 -> V_39 [ 0 ] != V_66 [ 0 ] ) ;
}
