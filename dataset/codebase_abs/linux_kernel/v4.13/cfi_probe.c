static int T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 ,
unsigned long * V_4 , struct V_5 * V_6 )
{
int V_7 ;
if ( ( V_3 + 0 ) >= V_2 -> V_8 ) {
F_2 ( V_9
L_1 ,
( unsigned long ) V_3 , V_2 -> V_8 - 1 ) ;
return 0 ;
}
if ( ( V_3 + 0xff ) >= V_2 -> V_8 ) {
F_2 ( V_9
L_2 ,
( unsigned long ) V_3 + 0x55 , V_2 -> V_8 - 1 ) ;
return 0 ;
}
F_3 () ;
if ( ! F_4 ( V_3 , V_2 , V_6 ) ) {
F_5 ( V_3 , V_2 , V_6 ) ;
return 0 ;
}
if ( ! V_6 -> V_10 ) {
return F_6 ( V_2 , V_6 ) ;
}
for ( V_7 = 0 ; V_7 < ( V_3 >> V_6 -> V_11 ) ; V_7 ++ ) {
unsigned long V_12 ;
if( ! F_7 ( V_7 , V_4 ) ) {
continue;
}
V_12 = V_7 << V_6 -> V_11 ;
if ( F_8 ( V_2 , V_12 , V_6 ) ) {
F_9 ( V_12 , V_2 , V_6 ) ;
if ( ! F_8 ( V_2 , V_12 , V_6 ) ) {
F_10 ( V_3 , V_2 ) ;
F_2 ( V_13 L_3 ,
V_2 -> V_14 , V_3 , V_12 ) ;
return 0 ;
}
F_9 ( V_3 , V_2 , V_6 ) ;
if ( F_8 ( V_2 , V_3 , V_6 ) ) {
F_10 ( V_3 , V_2 ) ;
F_2 ( V_13 L_3 ,
V_2 -> V_14 , V_3 , V_12 ) ;
return 0 ;
}
}
}
F_11 ( ( V_3 >> V_6 -> V_11 ) , V_4 ) ;
V_6 -> V_10 ++ ;
F_9 ( V_3 , V_2 , V_6 ) ;
F_10 ( V_3 , V_2 ) ;
F_2 ( V_15 L_4 ,
V_2 -> V_14 , V_6 -> V_16 , V_6 -> V_17 * 8 , V_3 ,
V_2 -> V_18 * 8 ) ;
return 1 ;
}
static int T_1 F_6 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
int V_19 = V_6 -> V_16 * V_6 -> V_17 ;
T_2 V_3 = 0 ;
int V_20 = F_12 ( V_2 , V_3 + ( 0x10 + 28 ) * V_19 ) ;
int V_7 ;
int V_21 = 0x555 , V_22 = 0x2AA ;
F_5 ( V_3 , V_2 , V_6 ) ;
#ifdef F_13
F_2 ( L_5 , V_20 ) ;
#endif
if ( ! V_20 )
return 0 ;
V_6 -> V_23 = F_14 ( sizeof( struct V_24 ) + V_20 * 4 , V_25 ) ;
if ( ! V_6 -> V_23 )
return 0 ;
memset ( V_6 -> V_23 , 0 , sizeof( struct V_24 ) ) ;
V_6 -> V_26 = V_27 ;
V_6 -> V_28 = F_15 ( 0x30 ) ;
F_16 ( V_3 , V_2 , V_6 ) ;
for ( V_7 = 0 ; V_7 < ( sizeof( struct V_24 ) + V_20 * 4 ) ; V_7 ++ )
( ( unsigned char * ) V_6 -> V_23 ) [ V_7 ] = F_12 ( V_2 , V_3 + ( 0x10 + V_7 ) * V_19 ) ;
V_6 -> V_23 -> V_29 = F_17 ( V_6 -> V_23 -> V_29 ) ;
V_6 -> V_23 -> V_30 = F_17 ( V_6 -> V_23 -> V_30 ) ;
V_6 -> V_23 -> V_31 = F_17 ( V_6 -> V_23 -> V_31 ) ;
V_6 -> V_23 -> V_32 = F_17 ( V_6 -> V_23 -> V_32 ) ;
V_6 -> V_23 -> V_33 = F_17 ( V_6 -> V_23 -> V_33 ) ;
V_6 -> V_23 -> V_34 = F_17 ( V_6 -> V_23 -> V_34 ) ;
#ifdef F_13
F_18 ( V_6 -> V_23 ) ;
#endif
for ( V_7 = 0 ; V_7 < V_6 -> V_23 -> V_35 ; V_7 ++ ) {
V_6 -> V_23 -> V_36 [ V_7 ] = F_19 ( V_6 -> V_23 -> V_36 [ V_7 ] ) ;
#ifdef F_13
F_2 ( L_6 ,
V_7 , ( V_6 -> V_23 -> V_36 [ V_7 ] >> 8 ) & ~ 0xff ,
( V_6 -> V_23 -> V_36 [ V_7 ] & 0xffff ) + 1 ) ;
#endif
}
if ( V_6 -> V_23 -> V_29 == V_37 ) {
V_21 = 0x5555 ;
V_22 = 0x2AAA ;
}
F_20 ( 0xf0 , 0 , V_3 , V_2 , V_6 , V_6 -> V_17 , NULL ) ;
F_20 ( 0xaa , V_21 , V_3 , V_2 , V_6 , V_6 -> V_17 , NULL ) ;
F_20 ( 0x55 , V_22 , V_3 , V_2 , V_6 , V_6 -> V_17 , NULL ) ;
F_20 ( 0x90 , V_21 , V_3 , V_2 , V_6 , V_6 -> V_17 , NULL ) ;
V_6 -> V_38 = F_21 ( V_2 , V_3 ) ;
V_6 -> V_39 = F_21 ( V_2 , V_3 + V_19 ) ;
if ( V_6 -> V_38 == V_40 && ( V_6 -> V_39 & 0xff ) == 0x7e )
V_6 -> V_39 = F_12 ( V_2 , V_3 + 0xe * V_19 ) << 8 |
F_12 ( V_2 , V_3 + 0xf * V_19 ) ;
F_9 ( V_3 , V_2 , V_6 ) ;
F_10 ( V_3 , V_2 ) ;
F_2 ( V_15 L_7 ,
V_2 -> V_14 , V_6 -> V_16 , V_6 -> V_17 * 8 , V_3 ,
V_2 -> V_18 * 8 , V_6 -> V_38 , V_6 -> V_39 ) ;
return 1 ;
}
static char * F_22 ( T_3 V_41 )
{
switch ( V_41 ) {
case V_42 :
return L_8 ;
case V_43 :
return L_9 ;
case V_44 :
return L_10 ;
case V_45 :
return L_11 ;
case V_46 :
return L_12 ;
case V_47 :
return L_13 ;
case V_48 :
return L_14 ;
case V_49 :
return L_15 ;
case V_50 :
return L_16 ;
case V_51 :
return L_17 ;
case V_37 :
return L_18 ;
case V_52 :
return L_19 ;
case V_53 :
return L_20 ;
case V_54 :
return L_21 ;
default:
return L_22 ;
}
}
static void F_18 ( struct V_24 * V_55 )
{
#if 0
if (cfip->qry[0] != 'Q' || cfip->qry[1] != 'R' || cfip->qry[2] != 'Y') {
printk("Invalid CFI ident structure.\n");
return;
}
#endif
F_2 ( L_23 , V_55 -> V_29 , F_22 ( V_55 -> V_29 ) ) ;
if ( V_55 -> V_30 )
F_2 ( L_24 , V_55 -> V_30 ) ;
else
F_2 ( L_25 ) ;
F_2 ( L_26 , V_55 -> V_31 , F_22 ( V_55 -> V_31 ) ) ;
if ( V_55 -> V_32 )
F_2 ( L_27 , V_55 -> V_32 ) ;
else
F_2 ( L_28 ) ;
F_2 ( L_29 , V_55 -> V_56 >> 4 , V_55 -> V_56 & 0xf ) ;
F_2 ( L_30 , V_55 -> V_57 >> 4 , V_55 -> V_57 & 0xf ) ;
if ( V_55 -> V_58 ) {
F_2 ( L_31 , V_55 -> V_58 >> 4 , V_55 -> V_58 & 0xf ) ;
F_2 ( L_32 , V_55 -> V_59 >> 4 , V_55 -> V_59 & 0xf ) ;
}
else
F_2 ( L_33 ) ;
F_2 ( L_34 , 1 << V_55 -> V_60 ) ;
F_2 ( L_35 , ( 1 << V_55 -> V_61 ) * ( 1 << V_55 -> V_60 ) ) ;
if ( V_55 -> V_62 || V_55 -> V_63 ) {
F_2 ( L_36 , 1 << V_55 -> V_62 ) ;
F_2 ( L_37 , ( 1 << V_55 -> V_63 ) * ( 1 << V_55 -> V_62 ) ) ;
}
else
F_2 ( L_38 ) ;
F_2 ( L_39 , 1 << V_55 -> V_64 ) ;
F_2 ( L_40 , ( 1 << V_55 -> V_65 ) * ( 1 << V_55 -> V_64 ) ) ;
if ( V_55 -> V_66 || V_55 -> V_67 ) {
F_2 ( L_41 , 1 << V_55 -> V_66 ) ;
F_2 ( L_42 , ( 1 << V_55 -> V_67 ) * ( 1 << V_55 -> V_66 ) ) ;
}
else
F_2 ( L_43 ) ;
F_2 ( L_44 , 1 << V_55 -> V_68 , 1 << ( V_55 -> V_68 - 20 ) ) ;
F_2 ( L_45 , V_55 -> V_33 ) ;
switch( V_55 -> V_33 ) {
case V_69 :
F_2 ( L_46 ) ;
break;
case V_70 :
F_2 ( L_47 ) ;
break;
case V_71 :
F_2 ( L_48 ) ;
break;
case V_72 :
F_2 ( L_49 ) ;
break;
case V_73 :
F_2 ( L_50 ) ;
break;
case V_74 :
F_2 ( L_51 ) ;
break;
default:
F_2 ( L_52 ) ;
break;
}
F_2 ( L_53 , 1 << V_55 -> V_34 ) ;
F_2 ( L_54 , V_55 -> V_35 ) ;
}
struct V_75 * F_23 ( struct V_1 * V_2 )
{
return F_24 ( V_2 , & V_76 ) ;
}
static int T_4 F_25 ( void )
{
F_26 ( & V_77 ) ;
return 0 ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_77 ) ;
}
