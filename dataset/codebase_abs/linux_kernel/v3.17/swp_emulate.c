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
if ( type == V_27 )
F_14 ( * V_25 , V_24 , V_26 , V_29 ) ;
else
F_15 ( * V_25 , V_24 , V_26 , V_29 ) ;
if ( F_16 ( V_26 != - V_30 ) || F_17 ( V_14 ) )
break;
F_18 () ;
}
if ( V_26 == 0 ) {
if ( type == V_27 )
V_5 ++ ;
else
V_4 ++ ;
}
return V_26 ;
}
static int F_19 ( struct V_10 * V_11 , unsigned int V_31 )
{
unsigned int V_24 , V_32 , V_25 , type ;
unsigned int V_26 = 0 ;
F_20 ( V_33 , 1 , V_11 , V_11 -> V_34 ) ;
V_26 = F_21 ( V_31 , V_11 -> V_35 ) ;
switch ( V_26 ) {
case V_36 :
break;
case V_37 :
V_11 -> V_34 += 4 ;
return 0 ;
case V_38 :
return - V_28 ;
default:
return - V_39 ;
}
if ( V_14 -> V_40 != V_7 ) {
F_11 ( L_8 ,
V_14 -> V_41 , ( unsigned long ) V_14 -> V_40 ) ;
V_7 = V_14 -> V_40 ;
}
V_24 = V_11 -> V_42 [ F_22 ( V_31 , V_43 ) ] ;
V_25 = V_11 -> V_42 [ F_22 ( V_31 , V_44 ) ] ;
V_32 = F_22 ( V_31 , V_45 ) ;
type = V_31 & V_27 ;
F_11 ( L_9 ,
F_22 ( V_31 , V_43 ) , V_24 ,
V_32 , F_22 ( V_31 , V_44 ) , V_25 ) ;
if ( ! F_23 ( V_46 , ( V_24 & ~ 3 ) , 4 ) ) {
F_11 ( L_10 ,
( void * ) V_24 ) ;
V_26 = - V_28 ;
} else {
V_26 = F_13 ( V_24 , & V_25 , type ) ;
}
if ( V_26 == 0 ) {
V_11 -> V_34 += 4 ;
V_11 -> V_42 [ V_32 ] = V_25 ;
} else if ( V_26 == - V_28 ) {
F_6 ( V_11 , V_24 ) ;
}
return 0 ;
}
static int T_2 F_24 ( void )
{
if ( F_25 () < V_47 )
return 0 ;
#ifdef F_26
if ( ! F_27 ( L_11 , V_48 , NULL , & V_49 ) )
return - V_50 ;
#endif
F_28 ( V_51 L_12 ) ;
F_29 ( & V_52 ) ;
return 0 ;
}
