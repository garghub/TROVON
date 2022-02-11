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
if ( ! V_6 -> V_23 ) {
F_2 ( V_26 L_6 , V_2 -> V_14 ) ;
return 0 ;
}
memset ( V_6 -> V_23 , 0 , sizeof( struct V_24 ) ) ;
V_6 -> V_27 = V_28 ;
V_6 -> V_29 = F_15 ( 0x30 ) ;
F_16 ( V_3 , V_2 , V_6 ) ;
for ( V_7 = 0 ; V_7 < ( sizeof( struct V_24 ) + V_20 * 4 ) ; V_7 ++ )
( ( unsigned char * ) V_6 -> V_23 ) [ V_7 ] = F_12 ( V_2 , V_3 + ( 0x10 + V_7 ) * V_19 ) ;
V_6 -> V_23 -> V_30 = F_17 ( V_6 -> V_23 -> V_30 ) ;
V_6 -> V_23 -> V_31 = F_17 ( V_6 -> V_23 -> V_31 ) ;
V_6 -> V_23 -> V_32 = F_17 ( V_6 -> V_23 -> V_32 ) ;
V_6 -> V_23 -> V_33 = F_17 ( V_6 -> V_23 -> V_33 ) ;
V_6 -> V_23 -> V_34 = F_17 ( V_6 -> V_23 -> V_34 ) ;
V_6 -> V_23 -> V_35 = F_17 ( V_6 -> V_23 -> V_35 ) ;
#ifdef F_13
F_18 ( V_6 -> V_23 ) ;
#endif
for ( V_7 = 0 ; V_7 < V_6 -> V_23 -> V_36 ; V_7 ++ ) {
V_6 -> V_23 -> V_37 [ V_7 ] = F_19 ( V_6 -> V_23 -> V_37 [ V_7 ] ) ;
#ifdef F_13
F_2 ( L_7 ,
V_7 , ( V_6 -> V_23 -> V_37 [ V_7 ] >> 8 ) & ~ 0xff ,
( V_6 -> V_23 -> V_37 [ V_7 ] & 0xffff ) + 1 ) ;
#endif
}
if ( V_6 -> V_23 -> V_30 == V_38 ) {
V_21 = 0x5555 ;
V_22 = 0x2AAA ;
}
F_20 ( 0xf0 , 0 , V_3 , V_2 , V_6 , V_6 -> V_17 , NULL ) ;
F_20 ( 0xaa , V_21 , V_3 , V_2 , V_6 , V_6 -> V_17 , NULL ) ;
F_20 ( 0x55 , V_22 , V_3 , V_2 , V_6 , V_6 -> V_17 , NULL ) ;
F_20 ( 0x90 , V_21 , V_3 , V_2 , V_6 , V_6 -> V_17 , NULL ) ;
V_6 -> V_39 = F_21 ( V_2 , V_3 ) ;
V_6 -> V_40 = F_21 ( V_2 , V_3 + V_19 ) ;
if ( V_6 -> V_39 == V_41 && ( V_6 -> V_40 & 0xff ) == 0x7e )
V_6 -> V_40 = F_12 ( V_2 , V_3 + 0xe * V_19 ) << 8 |
F_12 ( V_2 , V_3 + 0xf * V_19 ) ;
F_9 ( V_3 , V_2 , V_6 ) ;
F_10 ( V_3 , V_2 ) ;
F_2 ( V_15 L_8 ,
V_2 -> V_14 , V_6 -> V_16 , V_6 -> V_17 * 8 , V_3 ,
V_2 -> V_18 * 8 , V_6 -> V_39 , V_6 -> V_40 ) ;
return 1 ;
}
static char * F_22 ( T_3 V_42 )
{
switch ( V_42 ) {
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
case V_52 :
return L_18 ;
case V_38 :
return L_19 ;
case V_53 :
return L_20 ;
case V_54 :
return L_21 ;
case V_55 :
return L_22 ;
default:
return L_23 ;
}
}
static void F_18 ( struct V_24 * V_56 )
{
#if 0
if (cfip->qry[0] != 'Q' || cfip->qry[1] != 'R' || cfip->qry[2] != 'Y') {
printk("Invalid CFI ident structure.\n");
return;
}
#endif
F_2 ( L_24 , V_56 -> V_30 , F_22 ( V_56 -> V_30 ) ) ;
if ( V_56 -> V_31 )
F_2 ( L_25 , V_56 -> V_31 ) ;
else
F_2 ( L_26 ) ;
F_2 ( L_27 , V_56 -> V_32 , F_22 ( V_56 -> V_32 ) ) ;
if ( V_56 -> V_33 )
F_2 ( L_28 , V_56 -> V_33 ) ;
else
F_2 ( L_29 ) ;
F_2 ( L_30 , V_56 -> V_57 >> 4 , V_56 -> V_57 & 0xf ) ;
F_2 ( L_31 , V_56 -> V_58 >> 4 , V_56 -> V_58 & 0xf ) ;
if ( V_56 -> V_59 ) {
F_2 ( L_32 , V_56 -> V_59 >> 4 , V_56 -> V_59 & 0xf ) ;
F_2 ( L_33 , V_56 -> V_60 >> 4 , V_56 -> V_60 & 0xf ) ;
}
else
F_2 ( L_34 ) ;
F_2 ( L_35 , 1 << V_56 -> V_61 ) ;
F_2 ( L_36 , ( 1 << V_56 -> V_62 ) * ( 1 << V_56 -> V_61 ) ) ;
if ( V_56 -> V_63 || V_56 -> V_64 ) {
F_2 ( L_37 , 1 << V_56 -> V_63 ) ;
F_2 ( L_38 , ( 1 << V_56 -> V_64 ) * ( 1 << V_56 -> V_63 ) ) ;
}
else
F_2 ( L_39 ) ;
F_2 ( L_40 , 1 << V_56 -> V_65 ) ;
F_2 ( L_41 , ( 1 << V_56 -> V_66 ) * ( 1 << V_56 -> V_65 ) ) ;
if ( V_56 -> V_67 || V_56 -> V_68 ) {
F_2 ( L_42 , 1 << V_56 -> V_67 ) ;
F_2 ( L_43 , ( 1 << V_56 -> V_68 ) * ( 1 << V_56 -> V_67 ) ) ;
}
else
F_2 ( L_44 ) ;
F_2 ( L_45 , 1 << V_56 -> V_69 , 1 << ( V_56 -> V_69 - 20 ) ) ;
F_2 ( L_46 , V_56 -> V_34 ) ;
switch( V_56 -> V_34 ) {
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
case V_75 :
F_2 ( L_52 ) ;
break;
default:
F_2 ( L_53 ) ;
break;
}
F_2 ( L_54 , 1 << V_56 -> V_35 ) ;
F_2 ( L_55 , V_56 -> V_36 ) ;
}
struct V_76 * F_23 ( struct V_1 * V_2 )
{
return F_24 ( V_2 , & V_77 ) ;
}
static int T_4 F_25 ( void )
{
F_26 ( & V_78 ) ;
return 0 ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_78 ) ;
}
