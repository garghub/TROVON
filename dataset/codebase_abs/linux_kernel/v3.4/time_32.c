unsigned long F_1 ( struct V_1 * V_2 )
{
extern char V_3 [] , V_4 [] ;
extern char V_5 [] , V_6 [] ;
extern char V_7 [] , V_8 [] ;
unsigned long V_9 = V_2 -> V_9 ;
if ( F_2 ( V_9 ) ||
( V_9 >= ( unsigned long ) V_3 &&
V_9 < ( unsigned long ) V_4 ) ||
( V_9 >= ( unsigned long ) V_5 &&
V_9 < ( unsigned long ) V_6 ) ||
( V_9 >= ( unsigned long ) V_7 &&
V_9 < ( unsigned long ) V_8 ) )
V_9 = V_2 -> V_10 [ V_11 ] ;
return V_9 ;
}
int F_3 ( struct V_12 V_13 )
{
return F_4 ( V_13 . V_14 ) ;
}
static T_1 F_5 ( int V_15 , void * V_16 )
{
#ifndef F_6
F_7 ( V_17 ) ;
#endif
F_8 () ;
F_9 ( 1 ) ;
#ifndef F_6
F_10 ( F_11 ( F_12 () ) ) ;
#endif
return V_18 ;
}
static unsigned char F_13 ( struct V_19 * V_20 , T_2 V_21 )
{
struct V_22 * V_23 = F_14 ( V_20 ) ;
struct V_24 * V_25 = V_23 -> V_20 . V_26 ;
return F_15 ( V_25 -> V_27 + V_21 ) ;
}
static void F_16 ( struct V_19 * V_20 , T_2 V_21 , T_3 V_28 )
{
struct V_22 * V_23 = F_14 ( V_20 ) ;
struct V_24 * V_25 = V_23 -> V_20 . V_26 ;
F_17 ( V_28 , V_25 -> V_27 + V_21 ) ;
}
static int T_4 F_18 ( struct V_22 * V_29 )
{
struct V_30 * V_31 = V_29 -> V_20 . V_32 ;
const char * V_33 = F_19 ( V_31 , L_1 , NULL ) ;
if ( ! V_33 )
return - V_34 ;
if ( ! F_20 ( V_31 , L_2 , NULL ) )
return - V_34 ;
V_35 . V_36 = & V_29 -> V_36 [ 0 ] ;
if ( ! strcmp ( V_33 , L_3 ) ) {
V_37 . V_27 = F_21 ( & V_29 -> V_36 [ 0 ] , 0 ,
2048 , L_4 ) ;
V_37 . type = V_38 ;
} else if ( ! strcmp ( V_33 , L_5 ) ) {
V_37 . V_27 = F_21 ( & V_29 -> V_36 [ 0 ] , 0 ,
8192 , L_4 ) ;
V_37 . type = V_39 ;
} else
return - V_34 ;
if ( F_22 ( & V_35 ) < 0 )
F_23 ( V_40 L_6 ) ;
return 0 ;
}
static int T_5 F_24 ( void )
{
return F_25 ( & V_41 ) ;
}
T_2 F_26 ( void )
{
unsigned long V_28 = * V_42 ;
unsigned long V_43 = ( V_28 >> 10 ) & 0x1fffff ;
if ( V_28 & 0x80000000 )
V_43 += 1000000 / V_44 ;
return V_43 * 1000 ;
}
T_2 F_27 ( void )
{
if ( F_28 ( ! V_45 ) )
return 0 ;
return V_45 () ;
}
static void T_5 F_29 ( void )
{
V_45 = F_26 ;
F_30 () ;
V_46 . V_47 ( F_5 ) ;
}
void T_5 F_31 ( void )
{
if ( F_32 () )
F_33 () ;
else
F_29 () ;
}
static int F_4 ( unsigned long V_48 )
{
struct V_49 * V_50 = F_34 ( L_7 ) ;
int V_51 = - 1 ;
if ( V_50 ) {
V_51 = F_35 ( V_50 , V_48 ) ;
F_36 ( V_50 ) ;
}
return V_51 ;
}
