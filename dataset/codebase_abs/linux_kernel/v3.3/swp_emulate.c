static int F_1 ( char * V_1 , char * * V_2 , T_1 V_3 , int V_4 ,
int * V_5 , void * V_6 )
{
char * V_7 = V_1 ;
int V_8 ;
V_7 += sprintf ( V_7 , L_1 , V_9 ) ;
V_7 += sprintf ( V_7 , L_2 , V_10 ) ;
V_7 += sprintf ( V_7 , L_3 , V_11 ) ;
if ( V_12 != 0 )
V_7 += sprintf ( V_7 , L_4 , V_12 ) ;
V_8 = ( V_7 - V_1 ) - V_3 ;
if ( V_8 < 0 )
V_8 = 0 ;
* V_5 = ( V_8 <= V_4 ) ? 1 : 0 ;
* V_2 = V_1 + V_3 ;
return V_8 ;
}
static void F_2 ( struct V_13 * V_14 , unsigned long V_15 )
{
T_2 V_16 ;
if ( F_3 ( V_17 -> V_18 , V_15 ) == NULL )
V_16 . V_19 = V_20 ;
else
V_16 . V_19 = V_21 ;
V_16 . V_22 = V_23 ;
V_16 . V_24 = 0 ;
V_16 . V_25 = ( void * ) F_4 ( V_14 ) ;
F_5 ( L_5 ) ;
F_6 ( L_6 , V_14 , & V_16 , 0 , 0 ) ;
V_11 ++ ;
}
static int F_7 ( unsigned int V_26 , unsigned int * V_6 ,
unsigned int type )
{
unsigned int V_27 = 0 ;
if ( ( type != V_28 ) && ( V_26 & 0x3 ) ) {
F_5 ( L_7 ) ;
return - V_29 ;
}
while ( 1 ) {
unsigned long V_30 ;
F_8 () ;
if ( type == V_28 )
F_9 ( * V_6 , V_26 , V_27 , V_30 ) ;
else
F_10 ( * V_6 , V_26 , V_27 , V_30 ) ;
if ( F_11 ( V_27 != - V_31 ) || F_12 ( V_17 ) )
break;
F_13 () ;
}
if ( V_27 == 0 ) {
F_8 () ;
if ( type == V_28 )
V_10 ++ ;
else
V_9 ++ ;
}
return V_27 ;
}
static int F_14 ( struct V_13 * V_14 , unsigned int V_32 )
{
unsigned int V_26 , V_33 , V_6 , type ;
unsigned int V_27 = 0 ;
F_15 ( V_34 , 1 , V_14 , V_14 -> V_35 ) ;
V_27 = F_16 ( V_32 , V_14 -> V_36 ) ;
switch ( V_27 ) {
case V_37 :
break;
case V_38 :
V_14 -> V_35 += 4 ;
return 0 ;
case V_39 :
return - V_29 ;
default:
return - V_40 ;
}
if ( V_17 -> V_41 != V_12 ) {
F_5 ( L_8 ,
V_17 -> V_42 , ( unsigned long ) V_17 -> V_41 ) ;
V_12 = V_17 -> V_41 ;
}
V_26 = V_14 -> V_43 [ F_17 ( V_32 , V_44 ) ] ;
V_6 = V_14 -> V_43 [ F_17 ( V_32 , V_45 ) ] ;
V_33 = F_17 ( V_32 , V_46 ) ;
type = V_32 & V_28 ;
F_5 ( L_9 ,
F_17 ( V_32 , V_44 ) , V_26 ,
V_33 , F_17 ( V_32 , V_45 ) , V_6 ) ;
if ( ! F_18 ( V_47 , ( V_26 & ~ 3 ) , 4 ) ) {
F_5 ( L_10 ,
( void * ) V_26 ) ;
V_27 = - V_29 ;
} else {
V_27 = F_7 ( V_26 , & V_6 , type ) ;
}
if ( V_27 == 0 ) {
V_14 -> V_35 += 4 ;
V_14 -> V_43 [ V_33 ] = V_6 ;
} else if ( V_27 == - V_29 ) {
F_2 ( V_14 , V_26 ) ;
}
return 0 ;
}
static int T_3 F_19 ( void )
{
#ifdef F_20
struct V_48 * V_27 ;
V_27 = F_21 ( L_11 , V_49 , NULL ) ;
if ( ! V_27 )
return - V_50 ;
V_27 -> V_51 = F_1 ;
#endif
F_22 ( V_52 L_12 ) ;
F_23 ( & V_53 ) ;
return 0 ;
}
