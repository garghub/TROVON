static void
F_1 ( unsigned long V_1 , struct V_2 * V_3 )
{
V_4 ++ ;
F_2 ( V_5 L_1 ) ;
}
T_1 void
F_3 ( unsigned long type , unsigned long V_1 ,
unsigned long V_6 , struct V_2 * V_3 )
{
struct V_2 * V_7 ;
F_4 () ;
switch ( type ) {
case 0 :
#ifdef F_5
F_6 ( V_3 ) ;
return;
#else
V_4 ++ ;
F_2 ( V_5 L_2
L_3 ) ;
#endif
break;
case 1 :
V_7 = F_7 ( V_3 ) ;
F_8 ( V_8 ) ;
F_7 ( V_7 ) ;
return;
case 2 :
V_7 = F_7 ( V_3 ) ;
V_9 . V_10 ( V_1 , V_6 ) ;
F_7 ( V_7 ) ;
return;
case 3 :
V_7 = F_7 ( V_3 ) ;
V_9 . V_11 ( V_1 ) ;
F_7 ( V_7 ) ;
return;
case 4 :
F_9 ( V_6 , V_3 ) ;
return;
default:
F_2 ( V_5 L_4 ,
type , V_1 ) ;
}
F_2 ( V_5 L_5 , V_3 -> V_12 , V_3 -> V_13 ) ;
}
void T_2
F_10 ( void )
{
F_11 ( 0 , V_14 ) ;
F_11 ( 0 , V_15 ) ;
F_11 ( 0 , V_16 ) ;
F_11 ( 0 , V_17 ) ;
}
void T_2
F_12 ( void )
{
F_13 ( V_18 , 0 ) ;
V_9 . V_19 () ;
}
void
F_14 ( unsigned long V_1 , unsigned long V_6 ,
const char * V_20 , int V_21 )
{
struct V_22 * V_23 ;
const char * V_24 ;
#ifdef F_15
if ( V_25 > 1 ) {
F_2 ( V_5 L_6 , V_20 ,
V_21 ? L_7 : L_8 ) ;
}
#endif
if ( V_21 ) {
int V_26 = F_16 () ;
F_17 ( V_26 ) = 0 ;
F_18 ( V_26 ) = 1 ;
return;
}
V_23 = (struct V_22 * ) V_6 ;
F_2 ( V_5 L_9 ,
V_20 , V_1 , F_19 () -> V_12 , V_23 -> V_27 ) ;
switch ( V_23 -> V_27 ) {
case 0x80 : V_24 = L_10 ; break;
case 0x82 : V_24 = L_11 ; break;
case 0x84 : V_24 = L_12 ; break;
case 0x86 : V_24 = L_13 ; break;
case 0x88 : V_24 = L_14 ; break;
case 0x8A : V_24 = L_15 ; break;
case 0x90 : V_24 = L_16 ; break;
case 0x96 : V_24 = L_17 ; break;
case 0x98 : V_24 = L_18 ; break;
case 0x202 : V_24 = L_19 ; break;
case 0x203 : V_24 = L_20 ; break;
case 0x204 : V_24 = L_21 ; break;
case 0x205 : V_24 = L_22 ; break;
case 0x206 : V_24 = L_23 ; break;
case 0x207 : V_24 = L_24 ; break;
case 0x208 : V_24 = L_25 ; break;
case 0x209 : V_24 = L_26 ; break;
case 0x20b : V_24 = L_27 ; break;
case 0x20d : V_24 = L_28 ; break;
case 0x20f : V_24 = L_29 ; break;
case 0x211 : V_24 = L_30 ; break;
case 0x213 : V_24 = L_31 ; break;
case 0x215 : V_24 = L_32 ; break;
case 0x217 : V_24 = L_33 ; break;
case 0x219 : V_24 = L_34 ; break;
case 0x21b : V_24 = L_35 ; break;
case 0x21d : V_24 = L_36 ; break;
case 0x21f : V_24 = L_37 ; break;
case 0x221 : V_24 = L_38 ; break;
default: V_24 = L_39 ; break;
}
F_2 ( V_5 L_40 ,
V_24 , V_23 -> V_28 ? L_41 : L_42 ) ;
F_20 ( F_19 () , NULL ) ;
#ifdef F_15
if ( V_25 > 1 ) {
unsigned long * V_29 = ( unsigned long * ) V_6 ;
long V_30 ;
for ( V_30 = 0 ; V_30 < V_23 -> V_31 / sizeof( long ) ; V_30 += 2 ) {
F_2 ( V_5 L_43 ,
V_30 * sizeof( long ) , V_29 [ V_30 ] , V_29 [ V_30 + 1 ] ) ;
}
}
#endif
}
void T_2
F_21 ( void )
{
F_22 ( V_8 , & V_32 ,
V_33 , L_44 ) ;
F_23 ( V_8 , & V_34 ) ;
}
