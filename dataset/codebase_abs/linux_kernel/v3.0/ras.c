static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
V_3 = F_2 ( L_1 ) ;
V_4 = F_2 ( L_2 ) ;
V_2 = F_3 ( L_3 ) ;
if ( V_2 != NULL ) {
F_4 ( V_2 , V_5 ,
L_4 ) ;
F_5 ( V_2 ) ;
}
V_2 = F_3 ( L_5 ) ;
if ( V_2 != NULL ) {
F_4 ( V_2 , V_6 , L_6 ) ;
F_5 ( V_2 ) ;
}
return 0 ;
}
static T_2 V_6 ( int V_7 , void * V_8 )
{
int V_9 = 0xdeadbeef ;
int V_10 = 0 ;
int V_11 ;
V_9 = F_6 ( V_3 , 2 , 2 , & V_10 ,
V_12 , V_13 ) ;
if ( V_10 > 3 )
V_11 = 1 ;
else
V_11 = 0 ;
F_7 ( & V_14 ) ;
V_9 = F_6 ( V_4 , 6 , 1 , NULL ,
V_15 ,
F_8 ( V_7 ) ,
V_16 | V_17 ,
V_11 , F_9 ( & V_18 ) ,
F_10 () ) ;
F_11 ( L_7 ,
* ( ( unsigned long * ) & V_18 ) , V_9 , V_10 ) ;
F_12 ( V_19 L_7 ,
* ( ( unsigned long * ) & V_18 ) , V_9 , V_10 ) ;
F_13 ( V_18 , V_20 , 0 ) ;
F_14 ( & V_14 ) ;
return V_21 ;
}
static T_2 V_5 ( int V_7 , void * V_8 )
{
struct V_22 * V_23 ;
int V_9 = 0xdeadbeef ;
int V_24 ;
F_7 ( & V_14 ) ;
V_9 = F_6 ( V_4 , 6 , 1 , NULL ,
V_15 ,
F_8 ( V_7 ) ,
V_25 , 1 ,
F_9 ( & V_18 ) ,
F_10 () ) ;
V_23 = (struct V_22 * ) V_18 ;
if ( ( V_9 == 0 ) && ( V_23 -> V_26 >= V_27 ) )
V_24 = 1 ;
else
V_24 = 0 ;
F_13 ( V_18 , V_20 , V_24 ) ;
if ( V_24 ) {
F_11 ( L_8 ,
* ( ( unsigned long * ) & V_18 ) , V_9 ) ;
F_12 ( V_28 L_9 ,
* ( ( unsigned long * ) & V_18 ) , V_9 ) ;
#ifndef F_15
V_29 . V_30 () ;
#endif
} else {
F_11 ( L_10 ,
* ( ( unsigned long * ) & V_18 ) , V_9 ) ;
F_12 ( V_19
L_11 ,
* ( ( unsigned long * ) & V_18 ) , V_9 ) ;
}
F_14 ( & V_14 ) ;
return V_21 ;
}
static struct V_22 * F_16 ( struct V_31 * V_32 )
{
unsigned long * V_33 ;
struct V_22 * V_34 , * V_35 = NULL ;
if ( ! F_17 ( V_32 -> V_36 [ 3 ] ) ) {
F_12 ( V_37 L_12 , V_32 -> V_36 [ 3 ] ) ;
return NULL ;
}
V_33 = F_18 ( V_32 -> V_36 [ 3 ] ) ;
V_32 -> V_36 [ 3 ] = V_33 [ 0 ] ;
V_34 = (struct V_22 * ) & V_33 [ 1 ] ;
if ( ! V_34 -> V_38 ) {
memcpy ( & F_19 ( V_39 ) , V_34 , sizeof( V_40 ) ) ;
V_35 = (struct V_22 * ) & F_19 ( V_39 ) ;
} else {
int V_41 ;
V_41 = F_20 ( int , 8 + V_34 -> V_42 , V_43 ) ;
memset ( V_44 , 0 , V_43 ) ;
memcpy ( V_44 , V_34 , V_41 ) ;
V_35 = (struct V_22 * ) V_44 ;
}
return V_35 ;
}
static void F_21 ( void )
{
int V_45 = F_6 ( F_2 ( L_13 ) , 0 , 1 , NULL ) ;
if ( V_45 != 0 )
F_12 ( V_37 L_14 , V_45 ) ;
}
int F_22 ( struct V_31 * V_32 )
{
if ( V_46 ) {
struct V_22 * V_35 = F_16 ( V_32 ) ;
if ( V_35 ) {
}
F_21 () ;
}
return 0 ;
}
static int F_23 ( struct V_31 * V_32 , struct V_22 * V_47 )
{
int V_48 = 0 ;
if ( ! ( V_32 -> V_49 & V_50 ) ) {
V_48 = 0 ;
} else if ( V_47 -> V_51 == V_52 ) {
V_48 = 1 ;
} else if ( V_47 -> V_51 == V_53 ) {
F_12 ( V_37 L_15
L_16 ) ;
V_48 = 1 ;
} else if ( F_24 ( V_32 ) && ! F_25 ( V_54 ) &&
V_47 -> V_26 == V_27 ) {
F_12 ( V_37 L_17
L_18 , V_54 -> V_55 , V_54 -> V_56 ) ;
F_26 ( V_57 , V_32 , V_58 , V_32 -> V_59 ) ;
V_48 = 1 ;
}
F_13 ( ( char * ) V_47 , V_20 , 0 ) ;
return V_48 ;
}
int F_27 ( struct V_31 * V_32 )
{
struct V_22 * V_60 ;
if ( V_46 ) {
V_60 = F_16 ( V_32 ) ;
F_21 () ;
if ( V_60 && F_23 ( V_32 , V_60 ) )
return 1 ;
}
return 0 ;
}
