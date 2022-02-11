static void F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = V_7 -> V_8 ;
if ( V_4 & V_9 ) {
#error Missing headerfiles. No way to fix this. -tglx
switch ( V_3 ) {
case V_10 :
F_2 ( ( unsigned long ) V_11 ) ;
break;
case V_12 :
F_3 ( ( unsigned long ) V_11 ) ;
break;
case V_13 :
F_4 ( ( unsigned long ) V_11 ) ;
break;
case V_14 :
F_5 ( ( unsigned long ) V_11 ) ;
break;
case V_15 :
F_6 ( ( unsigned long ) V_11 ) ;
break;
case V_16 :
F_7 ( ( unsigned long ) V_11 ) ;
break;
}
}
if ( V_3 != V_17 )
F_8 ( V_3 , V_6 -> V_18 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = V_7 -> V_8 ;
if ( V_4 & V_9 ) {
#error Missing headerfiles. No way to fix this. -tglx
switch ( V_3 ) {
case V_10 :
F_2 ( ( unsigned long ) V_19 ) ;
break;
case V_12 :
F_3 ( ( unsigned long ) V_19 ) ;
break;
case V_13 :
F_4 ( ( unsigned long ) V_19 ) ;
break;
case V_14 :
F_5 ( ( unsigned long ) V_19 ) ;
break;
case V_15 :
F_6 ( ( unsigned long ) V_19 ) ;
break;
case V_16 :
F_7 ( ( unsigned long ) V_19 ) ;
break;
}
}
if ( V_3 != V_17 )
F_8 ( V_3 , V_6 -> V_18 ) ;
}
static int F_10 ( struct V_1 * V_20 )
{
if ( F_11 ( ( volatile unsigned * ) V_21 ) & V_22 )
return 1 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_20 )
{
if ( F_11 ( ( volatile unsigned * ) V_21 ) & V_23 )
return 1 ;
return 0 ;
}
static int T_1 F_13 ( void )
{
struct V_5 * V_24 ;
void T_2 * V_25 ;
void T_2 * V_26 ;
V_27 = F_14 ( sizeof( struct V_1 ) + sizeof( struct V_5 ) , V_28 ) ;
if ( ! V_27 ) {
F_15 ( L_1 ) ;
return - V_29 ;
}
V_25 = F_16 ( V_30 , V_31 ) ;
if ( ! V_25 ) {
F_15 ( L_2 ) ;
F_17 ( V_27 ) ;
return - V_32 ;
}
V_24 = (struct V_5 * ) ( & V_27 [ 1 ] ) ;
memset ( V_27 , 0 , sizeof( struct V_1 ) ) ;
memset ( V_24 , 0 , sizeof( struct V_5 ) ) ;
V_27 -> V_8 = V_24 ;
V_27 -> V_33 = V_34 ;
F_18 ( ( volatile unsigned * ) V_35 , F_11 ( ( volatile unsigned * ) V_35 ) & 0xC0FFFFFF ) ;
F_18 ( ( volatile unsigned * ) V_36 , F_11 ( ( volatile unsigned * ) V_36 ) & 0xC0FFFFFF ) ;
F_18 ( ( volatile unsigned * ) V_37 ,
F_11 ( ( volatile unsigned * ) V_37 ) | V_38 | V_39 | V_40 ) ;
#ifdef F_19
F_18 ( ( volatile unsigned * ) V_36 , F_11 ( ( volatile unsigned * ) V_36 ) & 0xFF3FFFFF ) ;
F_18 ( ( volatile unsigned * ) V_37 , F_11 ( ( volatile unsigned * ) V_37 ) & ( ~ V_22 ) ) ;
F_18 ( ( volatile unsigned * ) V_41 ,
( F_11 ( ( volatile unsigned * ) V_41 ) & 0xFF3FFFFF ) | 0x00400000 ) ;
#endif
V_24 -> V_42 = V_25 ;
V_24 -> V_18 = V_25 ;
V_24 -> V_43 = F_1 ;
#ifdef F_19
V_24 -> V_44 = F_10 ;
#endif
V_24 -> V_45 = V_46 ;
V_24 -> V_47 . V_48 = V_49 ;
if ( F_20 ( V_27 , 1 ) ) {
F_21 ( ( void * ) V_25 ) ;
V_25 = NULL ;
F_17 ( V_27 ) ;
goto V_50;
}
#ifndef F_19
if ( V_27 -> V_51 == V_52 )
V_24 -> V_45 = V_53 ;
#endif
V_27 -> V_54 = L_3 ;
F_22 ( V_27 , NULL , 0 ,
V_27 -> V_51 == V_52 ?
V_55 :
V_56 ,
V_57 ) ;
V_50:
V_58 = F_14 ( sizeof( struct V_1 ) + sizeof( struct V_5 ) , V_28 ) ;
if ( ! V_58 ) {
F_15 ( L_4 ) ;
if ( V_25 )
F_21 ( V_25 ) ;
return - V_29 ;
}
V_26 = F_16 ( V_59 , V_31 ) ;
if ( ! V_26 ) {
F_15 ( L_5 ) ;
F_17 ( V_58 ) ;
if ( V_25 )
F_21 ( V_25 ) ;
return - V_32 ;
}
V_24 = (struct V_5 * ) ( & V_58 [ 1 ] ) ;
memset ( V_58 , 0 , sizeof( struct V_1 ) ) ;
memset ( V_24 , 0 , sizeof( struct V_5 ) ) ;
V_58 -> V_8 = V_24 ;
F_18 ( ( volatile unsigned * ) V_35 , F_11 ( ( volatile unsigned * ) V_35 ) & 0xFFFFFFF0 ) ;
F_18 ( ( volatile unsigned * ) V_60 , F_11 ( ( volatile unsigned * ) V_60 ) & 0x3FFFFFFF ) ;
F_18 ( ( volatile unsigned * ) V_36 , F_11 ( ( volatile unsigned * ) V_36 ) & 0xFFFFFFF0 ) ;
F_18 ( ( volatile unsigned * ) V_61 , F_11 ( ( volatile unsigned * ) V_61 ) & 0x3FFFFFFF ) ;
F_18 ( ( volatile unsigned * ) V_37 , F_11 ( ( volatile unsigned * ) V_37 ) | V_62 |
V_63 | V_64 ) ;
#ifdef F_19
F_18 ( ( volatile unsigned * ) V_61 , F_11 ( ( volatile unsigned * ) V_61 ) & 0xFFFFFFFC ) ;
F_18 ( ( volatile unsigned * ) V_37 , F_11 ( ( volatile unsigned * ) V_37 ) & ( ~ V_23 ) ) ;
F_18 ( ( volatile unsigned * ) V_65 ,
( F_11 ( ( volatile unsigned * ) V_65 ) & 0xFFFFFFFC ) | 0x00000001 ) ;
#endif
V_24 -> V_42 = V_26 ;
V_24 -> V_18 = V_26 ;
V_24 -> V_43 = F_9 ;
#ifdef F_19
V_24 -> V_44 = F_12 ;
#endif
V_24 -> V_45 = V_53 ;
V_24 -> V_47 . V_48 = V_49 ;
if ( F_20 ( V_58 , 1 ) ) {
F_21 ( ( void * ) V_26 ) ;
F_17 ( V_58 ) ;
if ( V_25 )
F_21 ( V_25 ) ;
return - V_66 ;
}
V_58 -> V_54 = V_67 ;
F_22 ( V_58 , NULL , 0 ,
V_27 -> V_51 == V_52 ?
V_55 :
V_56 ,
V_57 ) ;
return 0 ;
}
static void T_3 F_23 ( void )
{
struct V_5 * V_24 ;
F_24 ( V_27 ) ;
F_24 ( V_58 ) ;
V_24 = (struct V_5 * ) & V_27 [ 1 ] ;
F_21 ( ( void * ) V_24 -> V_42 ) ;
V_24 = (struct V_5 * ) & V_58 [ 1 ] ;
F_21 ( ( void * ) V_24 -> V_42 ) ;
F_17 ( V_27 ) ;
F_17 ( V_58 ) ;
}
