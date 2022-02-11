static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( V_2 , L_1 , V_4 ) ;
F_2 ( V_2 , L_2 , V_5 ) ;
F_2 ( V_2 , L_3 , V_6 ) ;
if ( V_7 != 0 )
F_2 ( V_2 , L_4 , V_7 ) ;
return 0 ;
}
static int F_3 ( struct V_8 * V_8 , struct V_9 * V_9 )
{
return F_4 ( V_9 , F_1 , F_5 ( V_8 ) ) ;
}
static void F_6 ( struct V_10 * V_11 , unsigned long V_12 )
{
T_1 V_13 ;
F_7 ( & V_14 -> V_15 -> V_16 ) ;
if ( F_8 ( V_14 -> V_15 , V_12 ) == NULL )
V_13 . V_17 = V_18 ;
else
V_13 . V_17 = V_19 ;
F_9 ( & V_14 -> V_15 -> V_16 ) ;
V_13 . V_20 = V_21 ;
V_13 . V_22 = 0 ;
V_13 . V_23 = ( void * ) F_10 ( V_11 ) ;
F_11 ( L_5 ) ;
F_12 ( L_6 , V_11 , & V_13 , 0 , 0 ) ;
V_6 ++ ;
}
static int F_13 ( unsigned int V_24 , unsigned int * V_25 ,
unsigned int type )
{
unsigned int V_26 = 0 ;
if ( ( type != V_27 ) && ( V_24 & 0x3 ) ) {
F_11 ( L_7 ) ;
return - V_28 ;
}
while ( 1 ) {
unsigned long V_29 ;
unsigned int V_30 ;
V_30 = F_14 () ;
if ( type == V_27 )
F_15 ( * V_25 , V_24 , V_26 , V_29 ) ;
else
F_16 ( * V_25 , V_24 , V_26 , V_29 ) ;
F_17 ( V_30 ) ;
if ( F_18 ( V_26 != - V_31 ) || F_19 ( V_14 ) )
break;
F_20 () ;
}
if ( V_26 == 0 ) {
if ( type == V_27 )
V_5 ++ ;
else
V_4 ++ ;
}
return V_26 ;
}
static int F_21 ( struct V_10 * V_11 , unsigned int V_32 )
{
unsigned int V_24 , V_33 , V_25 , type ;
unsigned int V_26 = 0 ;
F_22 ( V_34 , 1 , V_11 , V_11 -> V_35 ) ;
V_26 = F_23 ( V_32 , V_11 -> V_36 ) ;
switch ( V_26 ) {
case V_37 :
break;
case V_38 :
V_11 -> V_35 += 4 ;
return 0 ;
case V_39 :
return - V_28 ;
default:
return - V_40 ;
}
if ( V_14 -> V_41 != V_7 ) {
F_11 ( L_8 ,
V_14 -> V_42 , ( unsigned long ) V_14 -> V_41 ) ;
V_7 = V_14 -> V_41 ;
}
V_24 = V_11 -> V_43 [ F_24 ( V_32 , V_44 ) ] ;
V_25 = V_11 -> V_43 [ F_24 ( V_32 , V_45 ) ] ;
V_33 = F_24 ( V_32 , V_46 ) ;
type = V_32 & V_27 ;
F_11 ( L_9 ,
F_24 ( V_32 , V_44 ) , V_24 ,
V_33 , F_24 ( V_32 , V_45 ) , V_25 ) ;
if ( ! F_25 ( V_47 , ( V_24 & ~ 3 ) , 4 ) ) {
F_11 ( L_10 ,
( void * ) V_24 ) ;
V_26 = - V_28 ;
} else {
V_26 = F_13 ( V_24 , & V_25 , type ) ;
}
if ( V_26 == 0 ) {
V_11 -> V_35 += 4 ;
V_11 -> V_43 [ V_33 ] = V_25 ;
} else if ( V_26 == - V_28 ) {
F_6 ( V_11 , V_24 ) ;
}
return 0 ;
}
static int T_2 F_26 ( void )
{
if ( F_27 () < V_48 )
return 0 ;
#ifdef F_28
if ( ! F_29 ( L_11 , V_49 , NULL , & V_50 ) )
return - V_51 ;
#endif
F_30 ( L_12 ) ;
F_31 ( & V_52 ) ;
return 0 ;
}
