static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = V_3 ;
#ifdef F_2
F_3 ( L_1 ,
V_2 -> V_5 , 24 , V_2 -> V_5 ) ;
#endif
F_4 ( V_4 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 ;
if ( V_7 -> type != V_10 ||
V_9 -> V_11 != V_12 ||
V_9 -> V_13 . V_14 . V_15 != V_16 ||
V_7 -> V_17 < V_18 )
return;
#ifdef F_2
F_3 ( L_2 ,
V_7 , 24 , V_7 ) ;
#endif
V_19 = V_9 -> V_13 . V_14 . V_20 ;
V_21 = V_9 -> V_13 . V_14 . V_22 ;
V_23 = V_9 -> V_13 . V_14 . V_17 ;
F_4 ( & V_24 ) ;
}
static int F_6 ( const struct V_25 * V_14 )
{
struct V_4 V_4 ;
struct V_26 * V_5 ;
struct V_1 * V_2 ;
T_1 V_27 ;
int V_28 ;
V_2 = F_7 ( sizeof( * V_2 ) , V_29 ) ;
V_5 = ( void * ) F_8 ( V_29 | V_30 ) ;
if ( ! V_2 || ! V_5 ) {
V_28 = - V_31 ;
goto V_32;
}
V_5 -> V_33 . V_17 = V_18 +
sizeof( struct V_34 ) ;
V_5 -> V_7 . V_33 . type = V_10 ;
V_5 -> V_7 . V_33 . V_17 = V_18 ;
V_5 -> V_7 . V_33 . V_35 = 0 ;
V_5 -> V_7 . V_11 = V_12 ;
V_5 -> V_7 . V_13 . V_14 . V_15 = V_16 ;
V_5 -> V_7 . V_13 . V_14 . V_36 = 0 ;
V_5 -> V_7 . V_13 . V_14 . V_37 = 0 ;
V_5 -> V_7 . V_13 . V_14 . V_38 = V_39 ;
V_5 -> V_7 . V_13 . V_14 . V_20 = V_40 ;
V_5 -> V_7 . V_13 . V_14 . V_22 = 0 ;
V_5 -> V_7 . V_13 . V_14 . V_41 = V_14 -> V_42 ;
V_5 -> V_7 . V_13 . V_14 . V_43 = V_14 -> V_44 ;
V_5 -> V_7 . V_13 . V_14 . V_17 = V_14 -> V_27 ;
V_5 -> V_7 . V_13 . V_14 . V_45 = F_9 ( V_14 -> V_46 ) ;
V_27 = F_10 ( V_5 -> V_7 . V_13 . V_14 . V_47 , V_14 -> V_48 ,
V_49 ) ;
if ( V_27 >= V_49 ) {
V_28 = - V_50 ;
goto V_32;
}
V_2 -> V_51 = V_52 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_53 = V_54 ;
V_2 -> V_55 = F_1 ;
V_2 -> V_56 = & V_4 ;
F_11 ( & V_4 ) ;
V_28 = F_12 ( V_2 ) ;
if ( V_28 )
goto V_32;
F_13 ( & V_4 ) ;
#ifdef F_2
F_3 ( L_3 ,
V_5 -> V_33 . V_57 , V_5 -> V_7 . V_33 . V_35 ) ;
#endif
if ( V_2 -> V_53 != V_58 ||
( V_5 -> V_7 . V_33 . V_35 & 0x80 ) == 0 ||
( V_5 -> V_33 . V_57 & 0xffU ) != 0x20U ) {
V_28 = - V_59 ;
}
V_32:
F_14 ( ( unsigned long ) V_5 ) ;
F_15 ( V_2 ) ;
return V_28 ;
}
T_2 F_16 ( const struct V_25 * V_14 , T_1 * V_22 )
{
T_2 V_27 ;
#ifdef F_2
unsigned long V_60 ;
F_3 ( L_4 ,
V_14 -> V_42 , V_14 -> V_48 , ( long long ) V_14 -> V_44 , V_14 -> V_27 ) ;
V_60 = V_61 ;
#endif
F_11 ( & V_24 ) ;
V_27 = F_6 ( V_14 ) ;
if ( V_27 )
goto V_62;
F_13 ( & V_24 ) ;
#ifdef F_2
F_3 ( L_5 ,
( V_61 - V_60 ) * 1000 / V_63 ) ;
F_3 ( L_6 ,
V_19 , V_23 , V_21 ) ;
#endif
switch ( V_19 ) {
case V_64 :
V_27 = V_23 ;
if ( V_22 )
* V_22 = V_21 ;
break;
case V_65 :
V_27 = - V_66 ;
break;
case V_67 :
V_27 = - V_68 ;
break;
case V_40 :
V_27 = - V_69 ;
break;
default:
V_27 = - V_59 ;
break;
}
V_62:
return V_27 ;
}
int F_17 ( void )
{
#ifdef F_2
unsigned long V_70 ;
#endif
int V_28 ;
V_28 = F_18 ( & V_71 ) ;
if ( V_28 )
return V_28 ;
#ifdef F_2
V_70 = F_8 ( V_29 ) ;
if ( V_70 != 0 ) {
struct V_72 * V_73 = (struct V_72 * ) V_70 ;
if ( ! F_19 ( V_73 , 2 , 2 , 2 ) ) {
V_73 -> V_74 [ sizeof( V_73 -> V_74 ) - 1 ] = '\0' ;
F_20 ( V_73 -> V_74 , sizeof( V_73 -> V_74 ) - 1 ) ;
F_3 ( L_7 ,
V_73 -> V_75 , V_73 -> V_74 ) ;
}
F_14 ( V_70 ) ;
}
#endif
return 0 ;
}
void F_21 ( void )
{
F_22 ( & V_71 ) ;
}
