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
#ifdef F_5
{
long V_8 ;
F_8 ( V_3 ) ;
V_8 = F_9 () ;
if ( V_8 != V_9 ) {
F_10 ( V_10 , F_11 ( V_10 ) ) ;
} else {
F_12 ( V_10 ) ;
}
}
#else
F_12 ( V_10 ) ;
#endif
F_7 ( V_7 ) ;
return;
case 2 :
V_7 = F_7 ( V_3 ) ;
V_11 . V_12 ( V_1 , V_6 ) ;
F_7 ( V_7 ) ;
return;
case 3 :
V_7 = F_7 ( V_3 ) ;
V_11 . V_13 ( V_1 ) ;
F_7 ( V_7 ) ;
return;
case 4 :
F_13 ( V_6 , V_3 ) ;
return;
default:
F_2 ( V_5 L_4 ,
type , V_1 ) ;
}
F_2 ( V_5 L_5 , V_3 -> V_14 , V_3 -> V_15 ) ;
}
void T_2
F_14 ( void )
{
F_15 ( 0 , V_16 ) ;
F_15 ( 0 , V_17 ) ;
F_15 ( 0 , V_18 ) ;
F_15 ( 0 , V_19 ) ;
}
void T_2
F_16 ( void )
{
F_17 ( V_20 , 0 ) ;
V_11 . V_21 () ;
}
void
F_18 ( unsigned long V_1 , unsigned long V_6 ,
const char * V_22 , int V_23 )
{
struct V_24 * V_25 ;
const char * V_26 ;
#ifdef F_19
if ( V_27 > 1 ) {
F_2 ( V_5 L_6 , V_22 ,
V_23 ? L_7 : L_8 ) ;
}
#endif
if ( V_23 ) {
int V_8 = F_9 () ;
F_20 ( V_8 ) = 0 ;
F_21 ( V_8 ) = 1 ;
return;
}
V_25 = (struct V_24 * ) V_6 ;
F_2 ( V_5 L_9 ,
V_22 , V_1 , F_22 () -> V_14 , V_25 -> V_28 ) ;
switch ( V_25 -> V_28 ) {
case 0x80 : V_26 = L_10 ; break;
case 0x82 : V_26 = L_11 ; break;
case 0x84 : V_26 = L_12 ; break;
case 0x86 : V_26 = L_13 ; break;
case 0x88 : V_26 = L_14 ; break;
case 0x8A : V_26 = L_15 ; break;
case 0x90 : V_26 = L_16 ; break;
case 0x96 : V_26 = L_17 ; break;
case 0x98 : V_26 = L_18 ; break;
case 0x202 : V_26 = L_19 ; break;
case 0x203 : V_26 = L_20 ; break;
case 0x204 : V_26 = L_21 ; break;
case 0x205 : V_26 = L_22 ; break;
case 0x206 : V_26 = L_23 ; break;
case 0x207 : V_26 = L_24 ; break;
case 0x208 : V_26 = L_25 ; break;
case 0x209 : V_26 = L_26 ; break;
case 0x20b : V_26 = L_27 ; break;
case 0x20d : V_26 = L_28 ; break;
case 0x20f : V_26 = L_29 ; break;
case 0x211 : V_26 = L_30 ; break;
case 0x213 : V_26 = L_31 ; break;
case 0x215 : V_26 = L_32 ; break;
case 0x217 : V_26 = L_33 ; break;
case 0x219 : V_26 = L_34 ; break;
case 0x21b : V_26 = L_35 ; break;
case 0x21d : V_26 = L_36 ; break;
case 0x21f : V_26 = L_37 ; break;
case 0x221 : V_26 = L_38 ; break;
default: V_26 = L_39 ; break;
}
F_2 ( V_5 L_40 ,
V_26 , V_25 -> V_29 ? L_41 : L_42 ) ;
F_23 ( F_22 () , NULL ) ;
#ifdef F_19
if ( V_27 > 1 ) {
unsigned long * V_30 = ( unsigned long * ) V_6 ;
long V_31 ;
for ( V_31 = 0 ; V_31 < V_25 -> V_32 / sizeof( long ) ; V_31 += 2 ) {
F_2 ( V_5 L_43 ,
V_31 * sizeof( long ) , V_30 [ V_31 ] , V_30 [ V_31 + 1 ] ) ;
}
}
#endif
}
void T_2
F_24 ( void )
{
F_25 ( V_10 , & V_33 ,
V_34 , L_44 ) ;
F_26 ( V_10 , & V_35 ) ;
}
