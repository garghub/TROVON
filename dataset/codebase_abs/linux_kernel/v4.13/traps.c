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
* V_21 = V_23 | V_47 ;
return 1 ;
}
static int F_23 ( struct V_48 * V_49 )
{
unsigned long V_19 , V_50 , V_51 ;
V_19 = * ( unsigned long * ) F_24 ( V_49 ) ;
V_51 = V_19 & ~ ( ( 1ULL << 12 ) - 1 ) ;
if ( V_51 != V_52 )
return 0 ;
V_50 = V_19 & ( ( 1ULL << 12 ) - 1 ) ;
switch ( V_50 ) {
case 0 :
F_25 ( V_53 , L_7 , V_49 , V_19 ,
V_54 , V_26 ) ;
break;
case V_55 :
F_25 ( V_55 , L_7 , V_49 , V_19 ,
V_54 , V_26 ) ;
break;
case V_56 :
F_25 ( V_56 , L_8 , V_49 , V_19 ,
V_54 , V_26 ) ;
break;
default:
return 0 ;
}
return 1 ;
}
void T_3 F_26 ( struct V_48 * V_49 , int V_57 ,
unsigned long V_58 )
{
T_4 V_59 = { 0 } ;
int V_60 , V_23 ;
unsigned long V_61 = 0 ;
T_2 V_62 ;
int V_63 = ! F_27 ( V_49 ) ;
if ( V_63 && V_57 == V_54 && F_23 ( V_49 ) )
return;
if ( ! ( V_49 -> V_64 & V_65 ) )
F_28 () ;
if ( V_63 ) {
const char * V_66 ;
char V_67 [ 100 ] ;
if ( F_29 ( V_49 ) )
return;
if ( V_57 >= 0 &&
V_57 < F_30 ( V_68 ) &&
V_68 [ V_57 ] != NULL )
V_66 = V_68 [ V_57 ] ;
else
V_66 = L_9 ;
if ( V_57 == V_69 )
snprintf ( V_67 , sizeof( V_67 ) , L_10 , V_58 ) ;
#ifdef F_11
else if ( V_57 == V_70 )
snprintf ( V_67 , sizeof( V_67 ) , L_11 , V_58 ) ;
#endif
else
V_67 [ 0 ] = '\0' ;
F_31 ( L_12 ,
V_57 , V_66 , V_49 -> V_71 , V_67 ) ;
F_32 ( V_49 ) ;
F_33 ( V_72 ) ;
}
switch ( V_57 ) {
case V_73 :
V_60 = V_44 ;
V_23 = V_74 ;
break;
case V_54 :
if ( F_34 ( & V_62 , ( void V_75 * ) V_49 -> V_71 ,
sizeof( V_62 ) ) ) {
F_35 ( L_13 ,
V_49 -> V_71 ) ;
F_33 ( V_72 ) ;
}
if ( ! F_10 ( V_62 , & V_60 , & V_23 ) ) {
V_60 = V_38 ;
V_23 = V_76 ;
}
V_61 = V_49 -> V_71 ;
break;
case V_69 :
#if F_36 ()
if ( F_6 ( V_58 ) )
return;
#endif
case V_77 :
case V_78 :
#if F_37 ()
case V_79 :
#endif
V_60 = V_38 ;
V_23 = V_80 ;
V_61 = V_49 -> V_71 ;
break;
case V_81 :
case V_82 :
case V_83 :
V_60 = V_38 ;
V_23 = V_84 ;
V_61 = V_49 -> V_71 ;
break;
case V_85 :
#ifndef F_11
if ( V_2 >= 0 ) {
struct V_86 * V_87 =
F_38 () -> V_88 ;
if ( ! V_87 ||
( void V_75 * ) ( V_49 -> V_71 ) != V_87 -> V_89 ) {
F_39 ( V_49 ) ;
return;
}
}
#endif
V_60 = V_44 ;
V_23 = V_90 ;
V_61 = 0 ;
break;
case V_91 :
V_57 = V_58 ;
V_60 = V_38 ;
V_23 = V_92 ;
V_61 = V_49 -> V_71 ;
break;
#ifdef F_11
case V_70 : {
F_40 () ;
V_60 = V_42 ;
V_61 = V_58 ;
V_23 = V_93 ;
break;
}
#endif
default:
F_41 ( L_14 , V_57 ) ;
}
V_59 . V_94 = V_60 ;
V_59 . V_95 = V_23 ;
V_59 . V_96 = ( void V_75 * ) V_61 ;
if ( V_60 == V_38 )
V_59 . V_97 = V_57 ;
if ( V_60 != V_26 )
F_42 ( L_15 , V_49 , V_61 , V_60 ) ;
F_43 ( V_60 , & V_59 , V_13 ) ;
}
void F_44 ( struct V_48 * V_49 , int V_57 , unsigned long V_58 )
{
F_45 () ;
switch ( V_58 ) {
#ifdef F_46
case V_98 :
F_47 ( V_49 ) ;
break;
#endif
default:
F_41 ( L_16 , V_58 ) ;
}
F_48 () ;
}
void F_49 ( int V_99 , T_5 V_71 , T_5 V_100 , T_5 V_101 , T_5 V_102 )
{
F_50 ( V_99 , V_71 , V_100 , V_101 , V_102 ) ;
F_51 ( L_17 ) ;
F_52 () ;
}
