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
F_4 ( V_2 , V_5 , L_5 ) ;
F_5 ( V_2 ) ;
}
return 0 ;
}
static void F_6 ( char V_6 )
{
switch ( V_6 ) {
case V_7 :
F_7 ( L_6 ) ;
F_8 ( true ) ;
break;
case V_8 :
F_7 ( L_7
L_8 ) ;
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
default:
F_9 ( L_13 ,
V_6 ) ;
}
}
static void F_10 ( struct V_11 * log )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
char V_16 ;
char V_17 ;
V_13 = F_11 ( log , V_18 ) ;
if ( V_13 == NULL )
return;
V_15 = (struct V_14 * ) V_13 -> V_19 ;
V_16 = V_15 -> V_20 & 0xF ;
V_17 = V_15 -> V_6 & 0xF ;
switch ( V_16 ) {
case V_21 :
if ( V_22 ) {
F_12 ( L_14 ) ;
V_22 -- ;
}
break;
case V_23 :
F_12 ( L_15
L_16 ) ;
break;
case V_24 :
F_12 ( L_17
L_16 ) ;
break;
case V_25 :
F_6 ( V_15 -> V_6 ) ;
break;
case V_26 :
F_7 ( L_18
L_19 ) ;
F_8 ( true ) ;
break;
case V_27 :
case V_28 :
F_7 ( L_20
L_21 ) ;
F_13 () ;
F_14 () ;
break;
default:
F_9 ( L_22 ,
V_16 ) ;
}
if ( V_16 != V_21 )
V_22 ++ ;
}
static T_2 V_5 ( int V_29 , void * V_30 )
{
int V_31 ;
int V_32 ;
int V_33 ;
V_31 = F_15 ( V_34 , V_35 ,
& V_32 ) ;
if ( V_32 > 3 )
V_33 = 1 ;
else
V_33 = 0 ;
F_16 ( & V_36 ) ;
V_31 = F_17 ( V_3 , 6 , 1 , NULL ,
V_37 ,
F_18 ( V_29 ) ,
V_38 ,
V_33 , F_19 ( & V_39 ) ,
F_20 () ) ;
F_21 ( V_39 , V_40 , 0 ) ;
F_10 ( (struct V_11 * ) V_39 ) ;
F_22 ( & V_36 ) ;
return V_41 ;
}
static T_2 V_4 ( int V_29 , void * V_30 )
{
struct V_11 * V_42 ;
int V_31 ;
int V_43 ;
F_16 ( & V_36 ) ;
V_31 = F_17 ( V_3 , 6 , 1 , NULL ,
V_37 ,
F_18 ( V_29 ) ,
V_44 , 1 ,
F_19 ( & V_39 ) ,
F_20 () ) ;
V_42 = (struct V_11 * ) V_39 ;
if ( V_31 == 0 &&
F_23 ( V_42 ) >= V_45 )
V_43 = 1 ;
else
V_43 = 0 ;
F_21 ( V_39 , V_40 , V_43 ) ;
if ( V_43 ) {
F_7 ( L_23
L_24 ) ;
F_13 () ;
F_14 () ;
} else {
F_9 ( L_25 ) ;
}
F_22 ( & V_36 ) ;
return V_41 ;
}
static struct V_11 * F_24 ( struct V_46 * V_47 )
{
unsigned long * V_48 ;
struct V_11 * V_49 , * V_50 = NULL ;
V_47 -> V_51 [ 3 ] &= ~ ( 0x3UL << 62 ) ;
if ( ! F_25 ( V_47 -> V_51 [ 3 ] ) ) {
F_26 ( V_52 L_26 , V_47 -> V_51 [ 3 ] ) ;
return NULL ;
}
V_48 = F_27 ( V_47 -> V_51 [ 3 ] ) ;
V_47 -> V_51 [ 3 ] = V_48 [ 0 ] ;
V_49 = (struct V_11 * ) & V_48 [ 1 ] ;
if ( ! F_28 ( V_49 ) ) {
memcpy ( F_29 ( & V_53 ) , V_49 , sizeof( V_54 ) ) ;
V_50 = (struct V_11 * ) F_29 ( & V_53 ) ;
} else {
int V_55 , V_56 ;
V_56 = 8 + F_30 ( V_49 ) ;
V_55 = F_31 ( int , V_56 , V_57 ) ;
memset ( V_58 , 0 , V_57 ) ;
memcpy ( V_58 , V_49 , V_55 ) ;
V_50 = (struct V_11 * ) V_58 ;
}
return V_50 ;
}
static void F_32 ( void )
{
int V_59 = F_17 ( F_2 ( L_27 ) , 0 , 1 , NULL ) ;
if ( V_59 != 0 )
F_26 ( V_52 L_28 , V_59 ) ;
}
int F_33 ( struct V_46 * V_47 )
{
if ( V_60 ) {
struct V_11 * V_50 = F_24 ( V_47 ) ;
if ( V_50 ) {
}
F_32 () ;
}
return 0 ;
}
static int F_34 ( struct V_46 * V_47 , struct V_11 * V_61 )
{
int V_62 = 0 ;
int V_63 = F_35 ( V_61 ) ;
if ( ! ( V_47 -> V_64 & V_65 ) ) {
V_62 = 0 ;
} else if ( V_63 == V_66 ) {
V_62 = 1 ;
} else if ( V_63 == V_67 ) {
F_26 ( V_52 L_29
L_30 ) ;
V_62 = 1 ;
} else if ( F_36 ( V_47 ) && ! F_37 ( V_68 ) &&
F_23 ( V_61 ) == V_45 ) {
F_26 ( V_52 L_31
L_32 , V_68 -> V_69 , V_68 -> V_70 ) ;
F_38 ( V_71 , V_47 , V_72 , V_47 -> V_73 ) ;
V_62 = 1 ;
}
F_21 ( ( char * ) V_61 , V_40 , 0 ) ;
return V_62 ;
}
int F_39 ( struct V_46 * V_47 )
{
struct V_11 * V_74 ;
if ( V_60 ) {
V_74 = F_24 ( V_47 ) ;
F_32 () ;
if ( V_74 && F_34 ( V_47 , V_74 ) )
return 1 ;
}
return 0 ;
}
