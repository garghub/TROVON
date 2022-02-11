void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 ) ;
F_2 () ;
}
static int F_4 ( struct V_2 * V_3 )
{
return V_3 -> V_4 & 0xffc0 ;
}
T_2 T_3 void F_5 ( struct V_2 * V_5 )
{
#ifdef F_6
int V_6 ;
#endif
#ifdef F_7
int V_7 ;
#endif
unsigned int V_8 = F_8 () ;
const char * strerror = NULL ;
int V_9 = 0 ;
T_4 V_10 ;
unsigned long V_11 = V_5 -> V_12 & V_13 ;
F_9 ( V_6 ) ;
#if F_10 ( V_14 ) || F_10 ( V_15 )
V_16 = ( V_17 ) V_5 -> V_12 ;
#endif
V_5 -> V_18 = V_5 -> V_19 ;
switch ( V_11 ) {
case V_20 :
V_10 . V_21 = V_22 ;
V_9 = V_23 ;
F_11 () ;
if ( F_4 ( V_5 ) )
goto V_24;
else
break;
case V_25 :
V_10 . V_21 = V_26 ;
V_9 = V_27 ;
strerror = V_28 F_12 ( V_28 ) ;
F_11 () ;
break;
case V_29 :
#ifdef F_13
V_10 . V_21 = V_22 ;
V_9 = V_23 ;
F_14 () ;
goto V_24;
#endif
case V_30 ... V_31 :
V_10 . V_21 = V_32 ;
V_9 = V_33 ;
strerror = V_28 F_15 ( V_28 ) ;
F_11 () ;
break;
case V_34 :
V_10 . V_21 = V_35 ;
V_9 = V_23 ;
F_11 () ;
if ( F_4 ( V_5 ) )
goto V_24;
else
break;
case V_36 :
V_10 . V_21 = V_37 ;
V_9 = V_23 ;
strerror = V_28 F_16 ( V_28 ) ;
F_11 () ;
break;
case V_38 :
#ifdef F_17
if ( F_4 ( V_5 ) ) {
switch ( F_18 ( V_5 -> V_39 , V_5 ) ) {
case V_40 :
break;
case V_41 :
F_19 () ;
V_5 -> V_39 += 2 ;
goto V_24;
case V_42 :
F_20 ( L_1 ) ;
}
}
#endif
#ifdef F_7
if ( ! F_4 ( V_5 ) && F_21 ( & V_7 , ( unsigned short * ) V_5 -> V_39 ) ) {
if ( F_22 ( V_5 , V_7 ) )
goto V_24;
if ( F_23 ( V_5 , V_7 ) )
goto V_24;
}
#endif
V_10 . V_21 = V_43 ;
V_9 = V_33 ;
strerror = V_28 F_24 ( V_28 ) ;
F_11 () ;
break;
case V_44 :
V_10 . V_21 = V_32 ;
V_9 = V_33 ;
strerror = V_28 F_25 ( V_28 ) ;
F_11 () ;
break;
case V_45 :
V_10 . V_21 = V_46 ;
V_9 = V_27 ;
strerror = V_28 F_26 ( V_28 ) ;
F_11 () ;
break;
case V_47 :
V_10 . V_21 = V_48 ;
V_9 = V_49 ;
strerror = V_28 F_27 ( V_28 ) ;
F_11 () ;
break;
case V_50 :
V_10 . V_21 = V_51 ;
V_9 = V_33 ;
strerror = V_28 F_28 ( V_28 ) ;
F_11 () ;
break;
case V_52 :
V_10 . V_21 = V_48 ;
V_9 = V_49 ;
strerror = V_28 F_29 ( V_28 ) ;
break;
case V_53 :
V_10 . V_21 = V_54 ;
V_9 = V_27 ;
#ifdef F_30
if ( V_55 [ V_8 ] . V_56 < V_57 )
strerror = V_28 L_2 ;
else
#endif
strerror = V_28 F_31 ( V_28 ) ;
F_11 () ;
break;
case V_58 :
V_10 . V_21 = V_59 ;
V_9 = V_23 ;
F_32 ( F_33 ( V_60 ) ) ;
F_11 () ;
if ( F_4 ( V_5 ) )
goto V_24;
else
break;
#ifdef F_34
case V_61 :
V_10 . V_21 = V_62 ;
V_9 = V_49 ;
strerror = V_28 L_3 ;
F_11 () ;
break;
#else
#endif
case V_63 :
V_10 . V_21 = V_48 ;
V_9 = V_49 ;
strerror = V_28 F_35 ( V_28 ) ;
F_11 () ;
break;
case V_64 :
V_10 . V_21 = V_46 ;
V_9 = V_49 ;
strerror = V_28 F_36 ( V_28 ) ;
F_11 () ;
break;
case V_65 :
V_10 . V_21 = V_66 ;
V_9 = V_49 ;
strerror = V_28 F_37 ( V_28 ) ;
break;
case V_67 :
V_10 . V_21 = V_54 ;
V_9 = V_27 ;
#ifdef F_30
if ( V_55 [ V_8 ] . V_68 < V_57 )
strerror = V_28 L_4 ;
else
#endif
strerror = V_28 F_38 ( V_28 ) ;
F_11 () ;
break;
case V_69 :
V_10 . V_21 = V_70 ;
V_9 = V_33 ;
strerror = V_28 F_39 ( V_28 ) ;
F_11 () ;
break;
case V_71 :
V_10 . V_21 = V_48 ;
V_9 = V_49 ;
switch ( V_5 -> V_12 & V_72 ) {
case ( V_73 ) :
V_10 . V_21 = V_48 ;
V_9 = V_49 ;
strerror = V_28 F_40 ( V_28 ) ;
break;
case ( V_74 ) :
if ( V_75 ) {
static unsigned long V_76 ;
if ( ( V_5 -> V_39 >= ( V_77 + V_78 - 512 ) ) &&
( V_5 -> V_39 < ( V_77 + V_78 ) ) ) {
V_76 = V_5 -> V_79 ;
goto V_24;
} else if ( V_5 -> V_79 == V_76 ) {
goto V_24;
} else if ( ( V_5 -> V_79 >= ( V_77 + V_78 - 512 ) ) &&
( V_5 -> V_79 < ( V_77 + V_78 ) ) ) {
goto V_24;
} else
V_76 = 0 ;
}
V_10 . V_21 = V_80 ;
V_9 = V_49 ;
strerror = V_28 F_41 ( V_28 ) ;
break;
case ( V_81 ) :
strerror = V_28 F_42 ( V_28 ) ;
break;
case ( V_82 ) :
F_43 (KERN_NOTICE HWC_x18(KERN_NOTICE)) ;
break;
default:
F_43 (KERN_NOTICE HWC_default(KERN_NOTICE)) ;
break;
}
F_11 () ;
break;
default:
V_10 . V_21 = V_32 ;
V_9 = V_33 ;
F_44 ( V_83 L_5 ,
( V_5 -> V_12 & V_13 ) ) ;
F_11 () ;
break;
}
F_45 ( V_9 == 0 ) ;
if ( F_4 ( V_5 ) || ( V_84 && ! V_84 -> V_85 ) ) {
F_46 () ;
V_86 = 1 ;
}
if ( V_9 != V_23 ) {
if ( strerror )
F_44 ( strerror ) ;
F_47 ( V_5 ) ;
F_48 ( V_5 ) ;
F_49 ( V_5 ) ;
#ifndef F_50
if ( V_11 == V_65 || V_11 == V_52 )
F_44 ( V_28 L_6
L_7 ) ;
else
#endif
F_19 () ;
if ( V_86 ) {
F_44 ( V_28 L_8 ) ;
F_51 ( V_84 , NULL ) ;
F_52 () ;
#ifndef F_53
F_44 ( V_83 L_9
L_10 ) ;
#endif
F_20 ( L_11 ) ;
} else {
#ifdef F_54
unsigned long * V_87 ;
V_87 = ( unsigned long * ) F_55 () ;
F_44 ( V_28 L_12 ) ;
F_51 ( NULL , V_87 ) ;
#endif
}
}
#ifdef F_56
if ( ! F_57 ( V_5 -> V_12 & 0x3f , V_5 ) )
#endif
{
V_10 . V_88 = V_9 ;
V_10 . V_89 = 0 ;
switch ( V_11 ) {
case V_45 :
case V_47 :
case V_52 :
case V_53 :
V_10 . V_90 = ( void V_91 * ) V_55 [ V_8 ] . V_56 ;
break;
default:
V_10 . V_90 = ( void V_91 * ) V_5 -> V_39 ;
break;
}
F_58 ( V_9 , & V_10 , V_84 ) ;
}
if ( ( V_92 && V_11 == V_71 && ! F_59 ( V_93 , V_5 -> V_39 , 8 ) ) ||
( V_94 && V_11 == V_71 ) ||
( V_95 && ( V_11 == V_64 || V_11 == V_45 ) ) )
V_5 -> V_39 = V_96 ;
V_24:
F_60 ( V_6 ) ;
}
T_2 void F_61 ( struct V_2 * V_5 )
{
#ifdef F_6
int V_6 ;
F_9 ( V_6 ) ;
#endif
F_46 () ;
V_86 = 1 ;
#ifdef F_54
F_43 ( V_83 L_13 ) ;
#ifdef F_62
if ( ( ( long ) V_5 -> V_12 & V_13 ) == V_50 ) {
unsigned int V_8 = F_8 () ;
char V_97 [ 150 ] ;
F_63 ( V_97 , V_55 [ V_8 ] . V_98 ) ;
F_43 ( V_83 L_14 ,
( unsigned int ) V_55 [ V_8 ] . V_99 & V_13 , V_97 ) ;
F_63 ( V_97 , V_55 [ V_8 ] . V_100 ) ;
F_43 ( V_28 L_15 , V_97 ) ;
F_63 ( V_97 , V_55 [ V_8 ] . V_101 ) ;
F_43 ( V_28 L_16 , V_97 ) ;
F_63 ( V_97 , V_5 -> V_19 ) ;
F_43 ( V_28 L_17 , V_97 ) ;
} else
#endif
{
F_47 ( V_5 ) ;
F_48 ( V_5 ) ;
F_49 ( V_5 ) ;
F_19 () ;
}
#endif
F_20 ( L_18 ) ;
}
void F_64 ( int V_102 , struct V_2 * V_5 )
{
switch ( V_102 ) {
case V_103 :
F_43 ( V_83 L_19 ) ;
break;
case V_104 :
return;
case V_105 :
return;
case V_106 :
F_43 ( V_83 L_20 ) ;
break;
}
V_86 = 1 ;
F_47 ( V_5 ) ;
F_48 ( V_5 ) ;
F_49 ( V_5 ) ;
F_65 () ;
F_20 ( L_21 ) ;
}
int F_66 ( unsigned long V_107 )
{
unsigned int V_7 ;
if ( ! F_21 ( & V_7 , ( unsigned short * ) V_107 ) )
return 0 ;
return V_7 == V_108 ;
}
void F_49 ( struct V_2 * V_5 )
{
}
