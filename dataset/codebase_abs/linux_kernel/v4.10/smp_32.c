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
unsigned long V_10 = 0 ;
int V_11 , V_12 = 0 ;
F_8 (cpu) {
V_12 ++ ;
V_10 += F_2 ( V_11 ) . V_4 ;
}
F_6 ( L_3 ,
V_12 , V_10 / ( 500000 / V_13 ) ,
( V_10 / ( 5000 / V_13 ) ) % 100 ) ;
switch( V_14 ) {
case V_15 :
F_9 () ;
break;
case V_16 :
F_10 () ;
break;
case V_17 :
F_11 () ;
break;
case V_18 :
F_6 ( L_4 ) ;
F_12 () ;
break;
case V_19 :
F_6 ( L_5 ) ;
F_12 () ;
break;
default:
F_6 ( L_6 ) ;
F_12 () ;
break;
}
}
void F_13 ( void )
{
F_6 ( L_7 , F_14 () ) ;
F_15 ( L_8 ) ;
}
void F_16 ( int V_11 )
{
V_20 -> V_21 ( V_11 ) ;
}
void F_17 ( void )
{
}
void F_18 ( int V_11 )
{
V_20 -> V_22 ( V_11 ) ;
}
void F_19 ( const struct V_23 * V_24 )
{
int V_11 ;
F_20 (cpu, mask)
V_20 -> V_25 ( V_11 ) ;
}
void F_21 ( void )
{
F_22 () ;
F_23 () ;
F_24 () . V_26 ++ ;
F_25 () ;
}
void F_26 ( void )
{
F_22 () ;
F_27 () ;
F_24 () . V_27 ++ ;
F_25 () ;
}
void F_28 ( void )
{
F_22 () ;
F_29 () ;
F_24 () . V_27 ++ ;
F_25 () ;
}
int F_30 ( unsigned int V_28 )
{
return - V_29 ;
}
void T_1 F_31 ( unsigned int V_9 )
{
int V_30 , V_31 , V_32 ;
F_6 ( L_9 ) ;
V_32 = 0 ;
for ( V_30 = 0 ; ! F_32 ( V_30 , NULL , & V_31 ) ; V_30 ++ ) {
if ( V_31 >= V_33 )
V_32 ++ ;
}
if ( V_32 && V_9 > V_30 - V_32 )
F_6 ( L_10 ) ;
F_1 ( V_34 ) ;
switch( V_14 ) {
case V_15 :
F_33 () ;
break;
case V_16 :
F_34 () ;
break;
case V_17 :
F_35 () ;
break;
case V_18 :
F_6 ( L_4 ) ;
F_12 () ;
break;
case V_19 :
F_6 ( L_5 ) ;
F_12 () ;
break;
default:
F_6 ( L_6 ) ;
F_12 () ;
break;
}
}
void T_1 F_36 ( void )
{
int V_35 , V_3 ;
V_35 = 0 ;
while ( ! F_32 ( V_35 , NULL , & V_3 ) ) {
if ( V_3 < V_33 ) {
F_37 ( V_3 , true ) ;
F_38 ( V_3 , true ) ;
}
V_35 ++ ;
}
}
void T_1 F_39 ( void )
{
int V_31 = F_40 () ;
if ( V_31 >= V_33 ) {
F_41 ( L_11 ) ;
F_42 () ;
}
if ( V_31 != 0 )
F_6 ( L_12 ) ;
F_43 () -> V_11 = V_31 ;
F_44 ( V_31 , true ) ;
F_37 ( V_31 , true ) ;
}
int F_45 ( unsigned int V_11 , struct V_36 * V_37 )
{
int V_38 = 0 ;
switch( V_14 ) {
case V_15 :
V_38 = F_46 ( V_11 , V_37 ) ;
break;
case V_16 :
V_38 = F_47 ( V_11 , V_37 ) ;
break;
case V_17 :
V_38 = F_48 ( V_11 , V_37 ) ;
break;
case V_18 :
F_6 ( L_4 ) ;
F_12 () ;
break;
case V_19 :
F_6 ( L_5 ) ;
F_12 () ;
break;
default:
F_6 ( L_6 ) ;
F_12 () ;
break;
}
if ( ! V_38 ) {
F_49 ( V_11 , & V_39 ) ;
while ( ! F_50 ( V_11 ) )
F_51 () ;
}
return V_38 ;
}
static void F_52 ( void * V_40 )
{
V_41 -> V_42 () ;
V_41 -> V_43 () ;
switch( V_14 ) {
case V_15 :
F_53 ( V_40 ) ;
break;
case V_16 :
F_54 ( V_40 ) ;
break;
case V_17 :
F_55 ( V_40 ) ;
break;
default:
F_12 () ;
}
}
static void F_56 ( void * V_40 )
{
unsigned int V_31 = F_40 () ;
F_57 ( V_31 ) ;
F_58 () ;
F_1 ( V_31 ) ;
V_41 -> V_42 () ;
V_41 -> V_43 () ;
switch( V_14 ) {
case V_15 :
F_59 ( V_40 ) ;
break;
case V_16 :
F_60 ( V_40 ) ;
break;
case V_17 :
F_61 ( V_40 ) ;
break;
default:
F_12 () ;
}
}
static void F_62 ( void * V_40 )
{
unsigned int V_11 ;
F_52 ( V_40 ) ;
F_63 () ;
V_11 = F_14 () ;
F_64 ( V_11 ) ;
F_56 ( V_40 ) ;
F_44 ( V_11 , true ) ;
F_65 () ;
F_66 () ;
F_67 ( V_44 ) ;
F_12 () ;
}
void F_68 ( void )
{
F_62 ( NULL ) ;
}
void F_69 ( struct V_45 * V_46 )
{
int V_30 ;
F_8 (i) {
F_70 ( V_46 ,
L_13 ,
V_30 ,
F_2 ( V_30 ) . V_4 / ( 500000 / V_13 ) ,
( F_2 ( V_30 ) . V_4 / ( 5000 / V_13 ) ) % 100 ) ;
}
}
void F_71 ( struct V_45 * V_46 )
{
int V_30 ;
F_70 ( V_46 , L_14 ) ;
F_8 (i)
F_70 ( V_46 , L_15 , V_30 ) ;
}
