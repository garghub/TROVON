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
break;
case V_9 :
F_7 ( L_9
L_10 ) ;
F_7 ( L_11 ) ;
F_8 ( true ) ;
break;
case V_10 :
F_7 ( L_12 ) ;
F_7 ( L_11 ) ;
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
F_9 ( L_14 ) ;
break;
case V_22 :
F_9 ( L_15 ) ;
F_9 ( L_11 ) ;
break;
case V_23 :
F_9 ( L_16 ) ;
F_9 ( L_11 ) ;
break;
case V_24 :
F_6 ( V_15 -> V_6 ) ;
break;
case V_25 :
F_7 ( L_6 ) ;
F_8 ( true ) ;
break;
case V_26 :
case V_27 :
F_7 ( L_17 ) ;
F_7 ( L_11 ) ;
F_7 ( L_18 ) ;
F_12 () ;
F_13 () ;
break;
default:
F_9 ( L_19 ,
V_16 ) ;
}
}
static T_2 V_5 ( int V_28 , void * V_29 )
{
int V_30 ;
int V_31 ;
int V_32 ;
V_30 = F_14 ( V_33 , V_34 , & V_31 ) ;
if ( V_31 > 3 )
V_32 = 1 ;
else
V_32 = 0 ;
F_15 ( & V_35 ) ;
V_30 = F_16 ( V_3 , 6 , 1 , NULL ,
V_36 ,
F_17 ( V_28 ) ,
V_37 ,
V_32 , F_18 ( & V_38 ) ,
F_19 () ) ;
F_20 ( V_38 , V_39 , 0 ) ;
F_10 ( (struct V_11 * ) V_38 ) ;
F_21 ( & V_35 ) ;
return V_40 ;
}
static T_2 V_4 ( int V_28 , void * V_29 )
{
struct V_11 * V_41 ;
int V_30 ;
int V_42 ;
F_15 ( & V_35 ) ;
V_30 = F_16 ( V_3 , 6 , 1 , NULL ,
V_36 ,
F_17 ( V_28 ) ,
V_43 , 1 ,
F_18 ( & V_38 ) ,
F_19 () ) ;
V_41 = (struct V_11 * ) V_38 ;
if ( V_30 == 0 &&
F_22 ( V_41 ) >= V_44 )
V_42 = 1 ;
else
V_42 = 0 ;
F_20 ( V_38 , V_39 , V_42 ) ;
if ( V_42 ) {
F_7 ( L_20 ) ;
F_7 ( L_11 ) ;
F_7 ( L_18 ) ;
F_12 () ;
F_13 () ;
} else {
F_9 ( L_21 ) ;
}
F_21 ( & V_35 ) ;
return V_40 ;
}
static struct V_11 * F_23 ( struct V_45 * V_46 )
{
unsigned long * V_47 ;
struct V_11 * V_48 , * V_49 = NULL ;
V_46 -> V_50 [ 3 ] &= ~ ( 0x3UL << 62 ) ;
if ( ! F_24 ( V_46 -> V_50 [ 3 ] ) ) {
F_25 ( V_51 L_22 , V_46 -> V_50 [ 3 ] ) ;
return NULL ;
}
V_47 = F_26 ( V_46 -> V_50 [ 3 ] ) ;
V_46 -> V_50 [ 3 ] = V_47 [ 0 ] ;
V_48 = (struct V_11 * ) & V_47 [ 1 ] ;
if ( ! F_27 ( V_48 ) ) {
memcpy ( F_28 ( & V_52 ) , V_48 , sizeof( V_53 ) ) ;
V_49 = (struct V_11 * ) F_28 ( & V_52 ) ;
} else {
int V_54 , V_55 ;
V_55 = 8 + F_29 ( V_48 ) ;
V_54 = F_30 ( int , V_55 , V_56 ) ;
memset ( V_57 , 0 , V_56 ) ;
memcpy ( V_57 , V_48 , V_54 ) ;
V_49 = (struct V_11 * ) V_57 ;
}
return V_49 ;
}
static void F_31 ( void )
{
int V_58 = F_16 ( F_2 ( L_23 ) , 0 , 1 , NULL ) ;
if ( V_58 != 0 )
F_25 ( V_51 L_24 , V_58 ) ;
}
int F_32 ( struct V_45 * V_46 )
{
if ( V_59 ) {
struct V_11 * V_49 = F_23 ( V_46 ) ;
if ( V_49 ) {
}
F_31 () ;
}
return 0 ;
}
static int F_33 ( struct V_45 * V_46 , struct V_11 * V_60 )
{
int V_61 = 0 ;
int V_62 = F_34 ( V_60 ) ;
if ( ! ( V_46 -> V_63 & V_64 ) ) {
V_61 = 0 ;
} else if ( V_62 == V_65 ) {
V_61 = 1 ;
} else if ( V_62 == V_66 ) {
F_25 ( V_51 L_25
L_26 ) ;
V_61 = 1 ;
} else if ( F_35 ( V_46 ) && ! F_36 ( V_67 ) &&
F_22 ( V_60 ) == V_44 ) {
F_25 ( V_51 L_27
L_28 , V_67 -> V_68 , V_67 -> V_69 ) ;
F_37 ( V_70 , V_46 , V_71 , V_46 -> V_72 ) ;
V_61 = 1 ;
}
F_20 ( ( char * ) V_60 , V_39 , 0 ) ;
return V_61 ;
}
int F_38 ( struct V_45 * V_46 )
{
struct V_11 * V_73 ;
if ( V_59 ) {
V_73 = F_23 ( V_46 ) ;
F_31 () ;
if ( V_73 && F_33 ( V_46 , V_73 ) )
return 1 ;
}
return 0 ;
}
