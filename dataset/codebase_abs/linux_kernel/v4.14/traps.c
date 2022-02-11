void T_1 F_1 ( void )
{
}
static int T_1 F_2 ( char * V_1 )
{
if ( F_3 ( V_1 , 0 , & V_2 ) != 0 )
return 0 ;
F_4 ( L_1 ,
V_2 >= 0 ?
( V_2 ? L_2 : L_3 ) :
L_4 ) ;
return 1 ;
}
static int T_1 F_5 ( char * V_1 )
{
F_4 ( L_5 ) ;
V_3 = 1 ;
return 1 ;
}
static int F_6 ( unsigned int V_4 )
{
int V_5 ;
if ( V_4 & V_6 )
return 0 ;
F_7 ( ( V_4 & ( V_7 | V_8 ) ) == 0 ) ;
V_5 = ( V_4 & V_9 ) >> V_10 ;
if ( V_5 == V_11 && ! V_3 ) {
F_8 ( V_12 L_6 ,
V_13 -> V_14 , V_13 -> V_15 ) ;
F_7 ( V_13 -> V_16 . V_17 . V_18 ) ;
V_13 -> V_16 . V_17 . V_18 = 1 ;
F_9 () ;
return 1 ;
}
return 0 ;
}
static int F_10 ( T_2 V_19 , int * V_20 , int * V_21 )
{
int V_22 , V_23 , V_24 ;
if ( V_19 == V_25 ) {
* V_20 = V_26 ;
* V_21 = V_27 ;
return 1 ;
}
#ifdef F_11
if ( ( V_19 & V_28 ) != 0 )
return 0 ;
if ( F_12 ( V_19 ) != V_29 )
return 0 ;
if ( F_13 ( V_19 ) != V_30 )
return 0 ;
if ( F_14 ( V_19 ) != V_31 )
return 0 ;
#else
if ( V_19 & V_32 )
return 0 ;
if ( F_12 ( V_19 ) != V_33 )
return 0 ;
if ( F_15 ( V_19 ) != V_34 )
return 0 ;
if ( F_16 ( V_19 ) != V_35 )
return 0 ;
#endif
if ( F_17 ( V_19 ) != 29 || F_18 ( V_19 ) != 37 )
return 0 ;
if ( F_19 ( V_19 ) != V_36 )
return 0 ;
if ( F_20 ( V_19 ) != V_37 )
return 0 ;
if ( F_21 ( V_19 ) != V_37 )
return 0 ;
V_22 = F_22 ( V_19 ) & 0x3f ;
switch ( V_22 ) {
case V_38 :
V_24 = V_39 ;
break;
case V_40 :
V_24 = V_41 ;
break;
case V_42 :
V_24 = V_43 ;
break;
case V_44 :
V_24 = V_45 ;
break;
case V_26 :
V_24 = V_46 ;
break;
default:
return 0 ;
}
V_23 = ( F_22 ( V_19 ) >> 6 ) & 0xf ;
if ( V_23 <= 0 || V_23 > V_24 )
return 0 ;
* V_20 = V_22 ;
* V_21 = V_23 ;
return 1 ;
}
static int F_23 ( struct V_47 * V_48 )
{
unsigned long V_19 , V_49 , V_50 ;
V_19 = * ( unsigned long * ) F_24 ( V_48 ) ;
V_50 = V_19 & ~ ( ( 1ULL << 12 ) - 1 ) ;
if ( V_50 != V_51 )
return 0 ;
V_49 = V_19 & ( ( 1ULL << 12 ) - 1 ) ;
switch ( V_49 ) {
case 0 :
F_25 ( V_52 , L_7 , V_48 , V_19 ,
V_53 , V_26 ) ;
break;
case V_54 :
F_25 ( V_54 , L_7 , V_48 , V_19 ,
V_53 , V_26 ) ;
break;
case V_55 :
F_25 ( V_55 , L_8 , V_48 , V_19 ,
V_53 , V_26 ) ;
break;
default:
return 0 ;
}
return 1 ;
}
void T_3 F_26 ( struct V_47 * V_48 , int V_56 ,
unsigned long V_57 )
{
T_4 V_58 = { 0 } ;
int V_59 , V_23 ;
unsigned long V_60 = 0 ;
T_2 V_61 ;
int V_62 = ! F_27 ( V_48 ) ;
if ( V_62 && V_56 == V_53 && F_23 ( V_48 ) )
return;
if ( ! ( V_48 -> V_63 & V_64 ) )
F_28 () ;
if ( V_62 ) {
const char * V_65 ;
char V_66 [ 100 ] ;
if ( F_29 ( V_48 ) )
return;
if ( V_56 >= 0 &&
V_56 < F_30 ( V_67 ) &&
V_67 [ V_56 ] != NULL )
V_65 = V_67 [ V_56 ] ;
else
V_65 = L_9 ;
if ( V_56 == V_68 )
snprintf ( V_66 , sizeof( V_66 ) , L_10 , V_57 ) ;
#ifdef F_11
else if ( V_56 == V_69 )
snprintf ( V_66 , sizeof( V_66 ) , L_11 , V_57 ) ;
#endif
else
V_66 [ 0 ] = '\0' ;
F_31 ( L_12 ,
V_56 , V_65 , V_48 -> V_70 , V_66 ) ;
F_32 ( V_48 ) ;
F_33 ( V_71 ) ;
}
switch ( V_56 ) {
case V_72 :
V_59 = V_44 ;
V_23 = V_73 ;
break;
case V_53 :
if ( F_34 ( & V_61 , ( void V_74 * ) V_48 -> V_70 ,
sizeof( V_61 ) ) ) {
F_35 ( L_13 ,
V_48 -> V_70 ) ;
F_33 ( V_71 ) ;
}
if ( ! F_10 ( V_61 , & V_59 , & V_23 ) ) {
V_59 = V_38 ;
V_23 = V_75 ;
}
V_60 = V_48 -> V_70 ;
break;
case V_68 :
#if F_36 ()
if ( F_6 ( V_57 ) )
return;
#endif
case V_76 :
case V_77 :
#if F_37 ()
case V_78 :
#endif
V_59 = V_38 ;
V_23 = V_79 ;
V_60 = V_48 -> V_70 ;
break;
case V_80 :
case V_81 :
case V_82 :
V_59 = V_38 ;
V_23 = V_83 ;
V_60 = V_48 -> V_70 ;
break;
case V_84 :
#ifndef F_11
if ( V_2 >= 0 ) {
struct V_85 * V_86 =
F_38 () -> V_87 ;
if ( ! V_86 ||
( void V_74 * ) ( V_48 -> V_70 ) != V_86 -> V_88 ) {
F_39 ( V_48 ) ;
return;
}
}
#endif
V_59 = V_44 ;
V_23 = V_89 ;
V_60 = 0 ;
break;
case V_90 :
V_56 = V_57 ;
V_59 = V_38 ;
V_23 = V_91 ;
V_60 = V_48 -> V_70 ;
break;
#ifdef F_11
case V_69 : {
F_40 () ;
V_59 = V_42 ;
V_60 = V_57 ;
V_23 = V_92 ;
break;
}
#endif
default:
F_41 ( L_14 , V_56 ) ;
}
V_58 . V_93 = V_59 ;
V_58 . V_94 = V_23 ;
V_58 . V_95 = ( void V_74 * ) V_60 ;
if ( V_59 == V_38 )
V_58 . V_96 = V_56 ;
if ( V_59 != V_26 )
F_42 ( L_15 , V_48 , V_60 , V_59 ) ;
F_43 ( V_59 , & V_58 , V_13 ) ;
}
void F_44 ( struct V_47 * V_48 , int V_56 , unsigned long V_57 )
{
F_45 () ;
switch ( V_57 ) {
#ifdef F_46
case V_97 :
F_47 ( V_48 ) ;
break;
#endif
default:
F_41 ( L_16 , V_57 ) ;
}
F_48 () ;
}
void F_49 ( int V_98 , T_5 V_70 , T_5 V_99 , T_5 V_100 , T_5 V_101 )
{
F_50 ( V_98 , V_70 , V_99 , V_100 , V_101 ) ;
F_51 ( L_17 ) ;
F_52 () ;
}
