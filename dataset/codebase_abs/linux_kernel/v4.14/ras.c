static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
V_3 = F_2 ( L_1 ) ;
V_2 = F_3 ( L_2 ) ;
if ( V_2 != NULL ) {
F_4 ( V_2 , V_4 ,
L_3 ) ;
F_5 ( V_2 ) ;
}
V_2 = F_3 ( L_4 ) ;
if ( V_2 != NULL ) {
F_4 ( V_2 , V_5 ,
L_5 ) ;
F_5 ( V_2 ) ;
}
V_2 = F_3 ( L_6 ) ;
if ( V_2 != NULL ) {
F_4 ( V_2 , V_6 , L_7 ) ;
F_5 ( V_2 ) ;
}
return 0 ;
}
static void F_6 ( char V_7 )
{
switch ( V_7 ) {
case V_8 :
F_7 ( L_8 ) ;
F_8 ( true ) ;
break;
case V_9 :
F_7 ( L_9
L_10 ) ;
F_8 ( true ) ;
break;
case V_10 :
F_7 ( L_11
L_12 ) ;
F_8 ( true ) ;
break;
case V_11 :
F_7 ( L_13
L_14 ) ;
F_8 ( true ) ;
break;
default:
F_9 ( L_15 ,
V_7 ) ;
}
}
static void F_10 ( struct V_12 * log )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
char V_17 ;
char V_18 ;
V_14 = F_11 ( log , V_19 ) ;
if ( V_14 == NULL )
return;
V_16 = (struct V_15 * ) V_14 -> V_20 ;
V_17 = V_16 -> V_21 & 0xF ;
V_18 = V_16 -> V_7 & 0xF ;
switch ( V_17 ) {
case V_22 :
if ( V_23 ) {
F_12 ( L_16 ) ;
V_23 -- ;
}
break;
case V_24 :
F_12 ( L_17
L_18 ) ;
break;
case V_25 :
F_12 ( L_19
L_18 ) ;
break;
case V_26 :
F_6 ( V_16 -> V_7 ) ;
break;
case V_27 :
F_7 ( L_20
L_21 ) ;
F_8 ( true ) ;
break;
case V_28 :
case V_29 :
F_7 ( L_22
L_23 ) ;
F_13 () ;
F_14 () ;
break;
default:
F_9 ( L_24 ,
V_17 ) ;
}
if ( V_17 != V_22 )
V_23 ++ ;
}
static T_2 V_5 ( int V_30 , void * V_31 )
{
struct V_13 * V_14 ;
struct V_32 * V_33 ;
F_15 ( & V_34 ) ;
F_16 ( V_3 , 6 , 1 , NULL ,
V_35 , F_17 ( V_30 ) ,
V_36 , 0 , F_18 ( & V_37 ) ,
F_19 () ) ;
V_14 = F_11 ( (struct V_12 * ) V_37 ,
V_38 ) ;
V_33 = (struct V_32 * ) V_14 -> V_20 ;
if ( V_33 -> V_39 == V_40 ||
V_33 -> V_39 == V_41 )
F_20 ( V_33 , NULL , NULL ) ;
else
F_21 ( V_37 , V_42 , 0 ) ;
F_22 ( & V_34 ) ;
return V_43 ;
}
static T_2 V_6 ( int V_30 , void * V_31 )
{
int V_44 ;
int V_45 ;
int V_46 ;
V_44 = F_23 ( V_47 , V_48 ,
& V_45 ) ;
if ( V_45 > 3 )
V_46 = 1 ;
else
V_46 = 0 ;
F_15 ( & V_34 ) ;
V_44 = F_16 ( V_3 , 6 , 1 , NULL ,
V_35 ,
F_17 ( V_30 ) ,
V_49 ,
V_46 , F_18 ( & V_37 ) ,
F_19 () ) ;
F_21 ( V_37 , V_42 , 0 ) ;
F_10 ( (struct V_12 * ) V_37 ) ;
F_22 ( & V_34 ) ;
return V_43 ;
}
static T_2 V_4 ( int V_30 , void * V_31 )
{
struct V_12 * V_50 ;
int V_44 ;
int V_51 ;
F_15 ( & V_34 ) ;
V_44 = F_16 ( V_3 , 6 , 1 , NULL ,
V_35 ,
F_17 ( V_30 ) ,
V_52 , 1 ,
F_18 ( & V_37 ) ,
F_19 () ) ;
V_50 = (struct V_12 * ) V_37 ;
if ( V_44 == 0 &&
F_24 ( V_50 ) >= V_53 )
V_51 = 1 ;
else
V_51 = 0 ;
F_21 ( V_37 , V_42 , V_51 ) ;
if ( V_51 ) {
F_7 ( L_25
L_26 ) ;
F_13 () ;
F_14 () ;
} else {
F_9 ( L_27 ) ;
}
F_22 ( & V_34 ) ;
return V_43 ;
}
static struct V_12 * F_25 ( struct V_54 * V_55 )
{
unsigned long * V_56 ;
struct V_12 * V_57 , * V_58 = NULL ;
V_55 -> V_59 [ 3 ] &= ~ ( 0x3UL << 62 ) ;
if ( ! F_26 ( V_55 -> V_59 [ 3 ] ) ) {
F_27 ( V_60 L_28 , V_55 -> V_59 [ 3 ] ) ;
return NULL ;
}
V_56 = F_28 ( V_55 -> V_59 [ 3 ] ) ;
V_55 -> V_59 [ 3 ] = V_56 [ 0 ] ;
V_57 = (struct V_12 * ) & V_56 [ 1 ] ;
if ( ! F_29 ( V_57 ) ) {
memcpy ( F_30 ( & V_61 ) , V_57 , sizeof( V_62 ) ) ;
V_58 = (struct V_12 * ) F_30 ( & V_61 ) ;
} else {
int V_63 , V_64 ;
V_64 = 8 + F_31 ( V_57 ) ;
V_63 = F_32 ( int , V_64 , V_65 ) ;
memset ( V_66 , 0 , V_65 ) ;
memcpy ( V_66 , V_57 , V_63 ) ;
V_58 = (struct V_12 * ) V_66 ;
}
return V_58 ;
}
static void F_33 ( void )
{
int V_67 = F_16 ( F_2 ( L_29 ) , 0 , 1 , NULL ) ;
if ( V_67 != 0 )
F_27 ( V_60 L_30 , V_67 ) ;
}
int F_34 ( struct V_54 * V_55 )
{
#ifdef F_35
if ( ( F_36 ( V_55 -> V_68 ) &
( V_69 | V_70 | V_71 | V_72 | V_73 | V_74 |
V_75 | V_76 | V_77 ) ) == ( V_71 | V_77 ) ) {
V_55 -> V_78 = F_36 ( ( V_79 ) V_55 -> V_78 ) ;
V_55 -> V_68 = 0 ;
}
#endif
if ( V_80 ) {
struct V_12 * V_58 = F_25 ( V_55 ) ;
if ( V_58 ) {
}
F_33 () ;
}
if ( F_37 ( V_55 ) )
return 1 ;
return 0 ;
}
static int F_38 ( struct V_54 * V_55 , struct V_12 * V_81 )
{
int V_82 = 0 ;
int V_83 = F_39 ( V_81 ) ;
if ( ! ( V_55 -> V_68 & V_70 ) ) {
V_82 = 0 ;
} else if ( V_83 == V_84 ) {
V_82 = 1 ;
} else if ( V_83 == V_85 ) {
F_27 ( V_60 L_31
L_32 ) ;
V_82 = 1 ;
} else if ( F_40 ( V_55 ) && ! F_41 ( V_86 ) &&
F_24 ( V_81 ) == V_53 ) {
F_27 ( V_60 L_33
L_34 , V_86 -> V_87 , V_86 -> V_88 ) ;
F_42 ( V_89 , V_55 , V_90 , V_55 -> V_78 ) ;
V_82 = 1 ;
}
F_21 ( ( char * ) V_81 , V_42 , 0 ) ;
return V_82 ;
}
int F_43 ( struct V_54 * V_55 )
{
struct V_12 * V_91 ;
if ( V_80 ) {
V_91 = F_25 ( V_55 ) ;
F_33 () ;
if ( V_91 && F_38 ( V_55 , V_91 ) )
return 1 ;
}
return 0 ;
}
