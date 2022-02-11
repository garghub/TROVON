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
const char * V_25 = 0 ;
int V_26 = 0 ;
struct V_27 * V_28 = 0 ;
void T_2 * V_29 ;
void T_2 * V_30 ;
V_31 = F_14 ( sizeof( struct V_1 ) + sizeof( struct V_5 ) , V_32 ) ;
if ( ! V_31 ) {
F_15 ( L_1 ) ;
return - V_33 ;
}
V_29 = F_16 ( V_34 , V_35 ) ;
if ( ! V_29 ) {
F_15 ( L_2 ) ;
F_17 ( V_31 ) ;
return - V_36 ;
}
V_24 = (struct V_5 * ) ( & V_31 [ 1 ] ) ;
memset ( V_31 , 0 , sizeof( struct V_1 ) ) ;
memset ( V_24 , 0 , sizeof( struct V_5 ) ) ;
V_31 -> V_8 = V_24 ;
V_31 -> V_37 = V_38 ;
F_18 ( ( volatile unsigned * ) V_39 , F_11 ( ( volatile unsigned * ) V_39 ) & 0xC0FFFFFF ) ;
F_18 ( ( volatile unsigned * ) V_40 , F_11 ( ( volatile unsigned * ) V_40 ) & 0xC0FFFFFF ) ;
F_18 ( ( volatile unsigned * ) V_41 ,
F_11 ( ( volatile unsigned * ) V_41 ) | V_42 | V_43 | V_44 ) ;
#ifdef F_19
F_18 ( ( volatile unsigned * ) V_40 , F_11 ( ( volatile unsigned * ) V_40 ) & 0xFF3FFFFF ) ;
F_18 ( ( volatile unsigned * ) V_41 , F_11 ( ( volatile unsigned * ) V_41 ) & ( ~ V_22 ) ) ;
F_18 ( ( volatile unsigned * ) V_45 ,
( F_11 ( ( volatile unsigned * ) V_45 ) & 0xFF3FFFFF ) | 0x00400000 ) ;
#endif
V_24 -> V_46 = V_29 ;
V_24 -> V_18 = V_29 ;
V_24 -> V_47 = F_1 ;
#ifdef F_19
V_24 -> V_48 = F_10 ;
#endif
V_24 -> V_49 = V_50 ;
V_24 -> V_51 . V_52 = V_53 ;
if ( F_20 ( V_31 , 1 ) ) {
F_21 ( ( void * ) V_29 ) ;
V_29 = NULL ;
F_17 ( V_31 ) ;
goto V_54;
}
#ifndef F_19
if ( V_31 -> V_55 == V_56 )
V_24 -> V_49 = V_57 ;
#endif
V_31 -> V_58 = L_3 ;
V_26 = F_22 ( V_31 , V_59 , & V_28 , 0 ) ;
if ( V_26 > 0 )
V_25 = L_4 ;
else
V_26 = 0 ;
if ( V_26 == 0 ) {
if ( V_31 -> V_55 == V_56 )
V_28 = V_60 ;
else
V_28 = V_61 ;
V_26 = V_62 ;
V_25 = L_5 ;
}
F_15 ( V_63 L_6 , V_25 ) ;
F_23 ( V_31 , V_28 , V_26 ) ;
V_54:
V_64 = F_14 ( sizeof( struct V_1 ) + sizeof( struct V_5 ) , V_32 ) ;
if ( ! V_64 ) {
F_15 ( L_7 ) ;
if ( V_29 )
F_21 ( V_29 ) ;
return - V_33 ;
}
V_30 = F_16 ( V_65 , V_35 ) ;
if ( ! V_30 ) {
F_15 ( L_8 ) ;
F_17 ( V_64 ) ;
if ( V_29 )
F_21 ( V_29 ) ;
return - V_36 ;
}
V_24 = (struct V_5 * ) ( & V_64 [ 1 ] ) ;
memset ( V_64 , 0 , sizeof( struct V_1 ) ) ;
memset ( V_24 , 0 , sizeof( struct V_5 ) ) ;
V_64 -> V_8 = V_24 ;
F_18 ( ( volatile unsigned * ) V_39 , F_11 ( ( volatile unsigned * ) V_39 ) & 0xFFFFFFF0 ) ;
F_18 ( ( volatile unsigned * ) V_66 , F_11 ( ( volatile unsigned * ) V_66 ) & 0x3FFFFFFF ) ;
F_18 ( ( volatile unsigned * ) V_40 , F_11 ( ( volatile unsigned * ) V_40 ) & 0xFFFFFFF0 ) ;
F_18 ( ( volatile unsigned * ) V_67 , F_11 ( ( volatile unsigned * ) V_67 ) & 0x3FFFFFFF ) ;
F_18 ( ( volatile unsigned * ) V_41 , F_11 ( ( volatile unsigned * ) V_41 ) | V_68 |
V_69 | V_70 ) ;
#ifdef F_19
F_18 ( ( volatile unsigned * ) V_67 , F_11 ( ( volatile unsigned * ) V_67 ) & 0xFFFFFFFC ) ;
F_18 ( ( volatile unsigned * ) V_41 , F_11 ( ( volatile unsigned * ) V_41 ) & ( ~ V_23 ) ) ;
F_18 ( ( volatile unsigned * ) V_71 ,
( F_11 ( ( volatile unsigned * ) V_71 ) & 0xFFFFFFFC ) | 0x00000001 ) ;
#endif
V_24 -> V_46 = V_30 ;
V_24 -> V_18 = V_30 ;
V_24 -> V_47 = F_9 ;
#ifdef F_19
V_24 -> V_48 = F_12 ;
#endif
V_24 -> V_49 = V_57 ;
V_24 -> V_51 . V_52 = V_53 ;
if ( F_20 ( V_64 , 1 ) ) {
F_21 ( ( void * ) V_30 ) ;
F_17 ( V_64 ) ;
if ( V_29 )
F_21 ( V_29 ) ;
return - V_72 ;
}
V_64 -> V_58 = V_73 ;
V_26 = F_22 ( V_64 , V_74 , & V_28 , 0 ) ;
if ( V_26 > 0 )
V_25 = L_4 ;
else
V_26 = 0 ;
if ( V_26 == 0 ) {
V_28 = V_75 ;
V_26 = V_62 ;
V_25 = L_5 ;
}
F_15 ( V_63 L_6 , V_25 ) ;
F_23 ( V_64 , V_28 , V_26 ) ;
return 0 ;
}
static void T_3 F_24 ( void )
{
struct V_5 * V_24 ;
F_25 ( V_31 ) ;
F_25 ( V_64 ) ;
V_24 = (struct V_5 * ) & V_31 [ 1 ] ;
F_21 ( ( void * ) V_24 -> V_46 ) ;
V_24 = (struct V_5 * ) & V_64 [ 1 ] ;
F_21 ( ( void * ) V_24 -> V_46 ) ;
F_17 ( V_31 ) ;
F_17 ( V_64 ) ;
}
