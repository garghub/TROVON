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
F_3 ( & V_17 -> V_18 -> V_19 ) ;
if ( F_4 ( V_17 -> V_18 , V_15 ) == NULL )
V_16 . V_20 = V_21 ;
else
V_16 . V_20 = V_22 ;
F_5 ( & V_17 -> V_18 -> V_19 ) ;
V_16 . V_23 = V_24 ;
V_16 . V_25 = 0 ;
V_16 . V_26 = ( void * ) F_6 ( V_14 ) ;
F_7 ( L_5 ) ;
F_8 ( L_6 , V_14 , & V_16 , 0 , 0 ) ;
V_11 ++ ;
}
static int F_9 ( unsigned int V_27 , unsigned int * V_6 ,
unsigned int type )
{
unsigned int V_28 = 0 ;
if ( ( type != V_29 ) && ( V_27 & 0x3 ) ) {
F_7 ( L_7 ) ;
return - V_30 ;
}
while ( 1 ) {
unsigned long V_31 ;
F_10 () ;
if ( type == V_29 )
F_11 ( * V_6 , V_27 , V_28 , V_31 ) ;
else
F_12 ( * V_6 , V_27 , V_28 , V_31 ) ;
if ( F_13 ( V_28 != - V_32 ) || F_14 ( V_17 ) )
break;
F_15 () ;
}
if ( V_28 == 0 ) {
F_10 () ;
if ( type == V_29 )
V_10 ++ ;
else
V_9 ++ ;
}
return V_28 ;
}
static int F_16 ( struct V_13 * V_14 , unsigned int V_33 )
{
unsigned int V_27 , V_34 , V_6 , type ;
unsigned int V_28 = 0 ;
F_17 ( V_35 , 1 , V_14 , V_14 -> V_36 ) ;
V_28 = F_18 ( V_33 , V_14 -> V_37 ) ;
switch ( V_28 ) {
case V_38 :
break;
case V_39 :
V_14 -> V_36 += 4 ;
return 0 ;
case V_40 :
return - V_30 ;
default:
return - V_41 ;
}
if ( V_17 -> V_42 != V_12 ) {
F_7 ( L_8 ,
V_17 -> V_43 , ( unsigned long ) V_17 -> V_42 ) ;
V_12 = V_17 -> V_42 ;
}
V_27 = V_14 -> V_44 [ F_19 ( V_33 , V_45 ) ] ;
V_6 = V_14 -> V_44 [ F_19 ( V_33 , V_46 ) ] ;
V_34 = F_19 ( V_33 , V_47 ) ;
type = V_33 & V_29 ;
F_7 ( L_9 ,
F_19 ( V_33 , V_45 ) , V_27 ,
V_34 , F_19 ( V_33 , V_46 ) , V_6 ) ;
if ( ! F_20 ( V_48 , ( V_27 & ~ 3 ) , 4 ) ) {
F_7 ( L_10 ,
( void * ) V_27 ) ;
V_28 = - V_30 ;
} else {
V_28 = F_9 ( V_27 , & V_6 , type ) ;
}
if ( V_28 == 0 ) {
V_14 -> V_36 += 4 ;
V_14 -> V_44 [ V_34 ] = V_6 ;
} else if ( V_28 == - V_30 ) {
F_2 ( V_14 , V_27 ) ;
}
return 0 ;
}
static int T_3 F_21 ( void )
{
#ifdef F_22
struct V_49 * V_28 ;
V_28 = F_23 ( L_11 , V_50 , NULL ) ;
if ( ! V_28 )
return - V_51 ;
V_28 -> V_52 = F_1 ;
#endif
F_24 ( V_53 L_12 ) ;
F_25 ( & V_54 ) ;
return 0 ;
}
