void F_1 ( int V_1 )
{
int V_2 ;
int V_3 ;
F_2 ( V_1 ) . V_4 = V_5 ;
F_3 ( V_1 , & V_2 ) ;
F_2 ( V_1 ) . V_6 = F_4 ( V_2 ,
L_1 , 0 ) ;
F_2 ( V_1 ) . V_7 = V_2 ;
V_3 = F_5 ( V_2 ) ;
if ( V_3 < 0 ) {
F_6 ( V_8 L_2 , V_1 , V_2 ) ;
V_3 = 0 ;
}
F_2 ( V_1 ) . V_3 = V_3 ;
}
void T_1 F_7 ( unsigned int V_9 )
{
extern void V_10 ( void ) ;
extern void V_11 ( void ) ;
unsigned long V_12 = 0 ;
int V_13 , V_14 = 0 ;
F_8 (cpu) {
V_14 ++ ;
V_12 += F_2 ( V_13 ) . V_4 ;
}
F_6 ( L_3 ,
V_14 , V_12 / ( 500000 / V_15 ) ,
( V_12 / ( 5000 / V_15 ) ) % 100 ) ;
switch( V_16 ) {
case V_17 :
V_10 () ;
break;
case V_18 :
V_11 () ;
break;
case V_19 :
F_9 () ;
break;
case V_20 :
F_6 ( L_4 ) ;
F_10 () ;
break;
case V_21 :
F_6 ( L_5 ) ;
F_10 () ;
break;
default:
F_6 ( L_6 ) ;
F_10 () ;
break;
}
}
void F_11 ( void )
{
F_6 ( L_7 , F_12 () ) ;
F_13 ( L_8 ) ;
}
void F_14 ( int V_13 )
{
V_22 -> V_23 ( V_13 ) ;
}
void F_15 ( void )
{
}
void F_16 ( int V_13 )
{
V_22 -> V_24 ( V_13 ) ;
}
void F_17 ( const struct V_25 * V_26 )
{
int V_13 ;
F_18 (cpu, mask)
V_22 -> V_27 ( V_13 ) ;
}
void F_19 ( void )
{
F_20 () ;
F_21 () ;
F_22 () . V_28 ++ ;
F_23 () ;
}
void F_24 ( void )
{
F_20 () ;
F_25 () ;
F_22 () . V_29 ++ ;
F_23 () ;
}
void F_26 ( void )
{
F_20 () ;
F_27 () ;
F_22 () . V_29 ++ ;
F_23 () ;
}
int F_28 ( unsigned int V_30 )
{
return - V_31 ;
}
void T_1 F_29 ( unsigned int V_9 )
{
extern void T_1 V_32 ( void ) ;
extern void T_1 V_33 ( void ) ;
int V_34 , V_35 , V_36 ;
F_6 ( L_9 ) ;
V_36 = 0 ;
for ( V_34 = 0 ; ! F_30 ( V_34 , NULL , & V_35 ) ; V_34 ++ ) {
if ( V_35 >= V_37 )
V_36 ++ ;
}
if ( V_36 && V_9 > V_34 - V_36 )
F_6 ( L_10 ) ;
F_1 ( V_38 ) ;
switch( V_16 ) {
case V_17 :
V_32 () ;
break;
case V_18 :
V_33 () ;
break;
case V_19 :
F_31 () ;
break;
case V_20 :
F_6 ( L_4 ) ;
F_10 () ;
break;
case V_21 :
F_6 ( L_5 ) ;
F_10 () ;
break;
default:
F_6 ( L_6 ) ;
F_10 () ;
break;
}
}
void T_1 F_32 ( void )
{
int V_39 , V_3 ;
V_39 = 0 ;
while ( ! F_30 ( V_39 , NULL , & V_3 ) ) {
if ( V_3 < V_37 ) {
F_33 ( V_3 , true ) ;
F_34 ( V_3 , true ) ;
}
V_39 ++ ;
}
}
void T_1 F_35 ( void )
{
int V_35 = F_36 () ;
if ( V_35 >= V_37 ) {
F_37 ( L_11 ) ;
F_38 () ;
}
if ( V_35 != 0 )
F_6 ( L_12 ) ;
F_39 () -> V_13 = V_35 ;
F_40 ( V_35 , true ) ;
F_33 ( V_35 , true ) ;
}
int F_41 ( unsigned int V_13 , struct V_40 * V_41 )
{
extern int V_42 ( int , struct V_40 * ) ;
extern int V_43 ( int , struct V_40 * ) ;
int V_44 = 0 ;
switch( V_16 ) {
case V_17 :
V_44 = V_42 ( V_13 , V_41 ) ;
break;
case V_18 :
V_44 = V_43 ( V_13 , V_41 ) ;
break;
case V_19 :
V_44 = F_42 ( V_13 , V_41 ) ;
break;
case V_20 :
F_6 ( L_4 ) ;
F_10 () ;
break;
case V_21 :
F_6 ( L_5 ) ;
F_10 () ;
break;
default:
F_6 ( L_6 ) ;
F_10 () ;
break;
}
if ( ! V_44 ) {
F_43 ( V_13 , & V_45 ) ;
while ( ! F_44 ( V_13 ) )
F_45 () ;
}
return V_44 ;
}
void F_46 ( void * V_46 )
{
V_47 -> V_48 () ;
V_47 -> V_49 () ;
switch( V_16 ) {
case V_17 :
F_47 ( V_46 ) ;
break;
case V_18 :
F_48 ( V_46 ) ;
break;
case V_19 :
F_49 ( V_46 ) ;
break;
default:
F_10 () ;
}
}
void F_50 ( void * V_46 )
{
unsigned int V_35 = F_36 () ;
F_51 ( V_35 ) ;
F_52 () ;
F_1 ( V_35 ) ;
V_47 -> V_48 () ;
V_47 -> V_49 () ;
switch( V_16 ) {
case V_17 :
F_53 ( V_46 ) ;
break;
case V_18 :
F_54 ( V_46 ) ;
break;
case V_19 :
F_55 ( V_46 ) ;
break;
default:
F_10 () ;
}
}
void F_56 ( void * V_46 )
{
unsigned int V_13 ;
F_46 ( V_46 ) ;
F_57 () ;
V_13 = F_12 () ;
F_58 ( V_13 ) ;
F_50 ( V_46 ) ;
F_40 ( V_13 , true ) ;
F_59 () ;
F_60 () ;
F_61 ( V_50 ) ;
F_10 () ;
}
void F_62 ( void )
{
F_56 ( NULL ) ;
}
void F_63 ( struct V_51 * V_52 )
{
int V_34 ;
F_8 (i) {
F_64 ( V_52 ,
L_13 ,
V_34 ,
F_2 ( V_34 ) . V_4 / ( 500000 / V_15 ) ,
( F_2 ( V_34 ) . V_4 / ( 5000 / V_15 ) ) % 100 ) ;
}
}
void F_65 ( struct V_51 * V_52 )
{
int V_34 ;
F_64 ( V_52 , L_14 ) ;
F_8 (i)
F_64 ( V_52 , L_15 , V_34 ) ;
}
