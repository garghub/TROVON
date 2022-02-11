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
F_8 ( 1 ) ;
break;
case V_8 :
F_7 ( L_7
L_8 ) ;
break;
case V_9 :
F_7 ( L_9
L_10 ) ;
F_7 ( L_11 ) ;
F_8 ( 1 ) ;
break;
case V_10 :
F_7 ( L_12 ) ;
F_7 ( L_11 ) ;
F_8 ( 1 ) ;
break;
default:
F_9 ( L_13 ,
V_6 ) ;
}
}
void F_10 ( struct V_11 * log )
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
F_8 ( 1 ) ;
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
if ( ( V_30 == 0 ) && ( V_41 -> V_44 >= V_45 ) )
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
static struct V_11 * F_22 ( struct V_46 * V_47 )
{
unsigned long * V_48 ;
struct V_11 * V_49 , * V_50 = NULL ;
if ( ! F_23 ( V_47 -> V_51 [ 3 ] ) ) {
F_24 ( V_52 L_22 , V_47 -> V_51 [ 3 ] ) ;
return NULL ;
}
V_48 = F_25 ( V_47 -> V_51 [ 3 ] ) ;
V_47 -> V_51 [ 3 ] = V_48 [ 0 ] ;
V_49 = (struct V_11 * ) & V_48 [ 1 ] ;
if ( ! V_49 -> V_53 ) {
memcpy ( & F_26 ( V_54 ) , V_49 , sizeof( V_55 ) ) ;
V_50 = (struct V_11 * ) & F_26 ( V_54 ) ;
} else {
int V_56 ;
V_56 = F_27 ( int , 8 + V_49 -> V_57 , V_58 ) ;
memset ( V_59 , 0 , V_58 ) ;
memcpy ( V_59 , V_49 , V_56 ) ;
V_50 = (struct V_11 * ) V_59 ;
}
return V_50 ;
}
static void F_28 ( void )
{
int V_60 = F_16 ( F_2 ( L_23 ) , 0 , 1 , NULL ) ;
if ( V_60 != 0 )
F_24 ( V_52 L_24 , V_60 ) ;
}
int F_29 ( struct V_46 * V_47 )
{
if ( V_61 ) {
struct V_11 * V_50 = F_22 ( V_47 ) ;
if ( V_50 ) {
}
F_28 () ;
}
return 0 ;
}
static int F_30 ( struct V_46 * V_47 , struct V_11 * V_62 )
{
int V_63 = 0 ;
if ( ! ( V_47 -> V_64 & V_65 ) ) {
V_63 = 0 ;
} else if ( V_62 -> V_66 == V_67 ) {
V_63 = 1 ;
} else if ( V_62 -> V_66 == V_68 ) {
F_24 ( V_52 L_25
L_26 ) ;
V_63 = 1 ;
} else if ( F_31 ( V_47 ) && ! F_32 ( V_69 ) &&
V_62 -> V_44 == V_45 ) {
F_24 ( V_52 L_27
L_28 , V_69 -> V_70 , V_69 -> V_71 ) ;
F_33 ( V_72 , V_47 , V_73 , V_47 -> V_74 ) ;
V_63 = 1 ;
}
F_20 ( ( char * ) V_62 , V_39 , 0 ) ;
return V_63 ;
}
int F_34 ( struct V_46 * V_47 )
{
struct V_11 * V_75 ;
if ( V_61 ) {
V_75 = F_22 ( V_47 ) ;
F_28 () ;
if ( V_75 && F_30 ( V_47 , V_75 ) )
return 1 ;
}
return 0 ;
}
