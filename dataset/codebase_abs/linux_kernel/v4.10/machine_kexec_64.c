int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned long V_4 , V_5 ;
unsigned long V_6 , V_7 ;
struct V_8 * V_9 ;
const unsigned long * V_10 ;
const unsigned int * V_11 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_12 ; V_3 ++ )
if ( V_2 -> V_13 [ V_3 ] . V_14 < F_2 ( V_15 ) )
return - V_16 ;
F_3 (node, L_1 ) {
V_10 = F_4 ( V_9 , L_2 , NULL ) ;
V_11 = F_4 ( V_9 , L_3 , NULL ) ;
if ( V_10 == NULL || V_11 == NULL )
continue;
V_6 = * V_10 ;
V_7 = V_6 + ( * V_11 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_12 ; V_3 ++ ) {
V_4 = V_2 -> V_13 [ V_3 ] . V_14 ;
V_5 = V_4 + V_2 -> V_13 [ V_3 ] . V_17 ;
if ( ( V_4 < V_7 ) && ( V_5 > V_6 ) )
return - V_16 ;
}
}
return 0 ;
}
static void F_5 ( unsigned long V_18 )
{
unsigned long V_19 ;
unsigned long * V_20 ;
void * V_21 ;
void * V_22 ;
V_20 = NULL ;
V_21 = NULL ;
for ( V_19 = V_18 ; ! ( V_19 & V_23 ) ; V_19 = * V_20 ++ ) {
V_22 = F_6 ( V_19 & V_24 ) ;
switch ( V_19 & V_25 ) {
case V_26 :
V_21 = V_22 ;
break;
case V_27 :
V_20 = V_22 ;
break;
case V_28 :
F_7 ( V_21 , V_22 ) ;
V_21 += V_29 ;
}
}
}
void F_8 ( struct V_1 * V_2 )
{
long V_3 , V_12 = V_2 -> V_12 ;
struct V_30 V_31 [ V_32 ] ;
memcpy ( V_31 , V_2 -> V_13 , sizeof( V_31 ) ) ;
F_5 ( V_2 -> V_33 ) ;
for ( V_3 = 0 ; V_3 < V_12 ; V_3 ++ )
F_9 ( ( unsigned long ) F_6 ( V_31 [ V_3 ] . V_14 ) ,
( unsigned long ) F_6 ( V_31 [ V_3 ] . V_14 + V_31 [ V_3 ] . V_17 ) ) ;
}
static void F_10 ( void * V_34 )
{
F_11 () ;
F_12 () ;
F_13 () ;
F_14 () -> V_35 = V_36 ;
while( V_37 == 0 )
F_15 () ;
F_13 () ;
F_16 () ;
if ( V_38 . V_39 )
V_38 . V_39 ( 0 , 1 ) ;
F_17 () ;
}
static void F_18 ( int V_40 )
{
int V_41 , V_3 , V_42 = - 1 ;
F_16 () ;
V_41 = F_19 () ;
F_20 (i) {
if ( V_3 == V_41 )
continue;
while ( V_43 [ V_3 ] . V_35 < V_40 ) {
F_21 () ;
if ( V_3 != V_42 ) {
F_22 ( V_44 L_4
L_5 ,
V_3 , V_43 [ V_3 ] . V_45 , V_40 ) ;
V_42 = V_3 ;
}
}
}
F_13 () ;
}
static void F_23 ( void )
{
int V_46 = 0 ;
F_24 (cpu) {
if ( ! F_25 ( V_46 ) ) {
F_22 ( V_44 L_6 ,
V_46 ) ;
F_26 ( F_27 ( V_46 ) ) ;
}
}
}
static void F_28 ( void )
{
F_23 () ;
F_29 ( F_10 , NULL , 0 ) ;
F_11 () ;
F_12 () ;
F_13 () ;
F_14 () -> V_35 = V_36 ;
F_18 ( V_36 ) ;
V_37 = 1 ;
if ( V_38 . V_39 )
V_38 . V_39 ( 0 , 0 ) ;
F_18 ( V_47 ) ;
F_30 () ;
}
static void F_28 ( void )
{
F_31 () ;
if ( V_38 . V_39 )
V_38 . V_39 ( 0 , 0 ) ;
F_11 () ;
F_12 () ;
}
void F_32 ( struct V_1 * V_2 )
{
bool V_48 ;
if ( ! F_33 () )
F_28 () ;
F_22 ( L_7 ) ;
V_49 . V_50 . V_51 = F_34 () -> V_51 ;
V_49 . V_50 . V_52 = 0 ;
V_49 . V_50 . V_53 = V_54 ;
V_49 . V_50 . V_46 = F_34 () -> V_46 ;
memcpy ( & V_55 , F_14 () , sizeof( struct V_56 ) ) ;
V_55 . V_57 = 0xedeaddeadeeeeeeeUL ;
V_43 = (struct V_56 * ) F_35 ( & V_55 , 0 ) -
V_55 . V_58 ;
F_36 ( & V_55 ) ;
#ifdef F_37
V_48 = false ;
#else
V_48 = F_38 () ||
! ( F_39 ( V_59 ) ||
F_39 ( V_60 ) ) ;
#endif
F_40 ( & V_49 , V_2 -> V_61 , V_2 ,
F_41 ( V_2 -> V_62 ) ,
V_63 , V_48 ) ;
}
static int T_1 F_42 ( void )
{
struct V_8 * V_9 ;
if ( ! V_64 )
return - V_65 ;
V_9 = F_43 ( L_8 ) ;
if ( ! V_9 )
return - V_65 ;
F_44 ( V_9 , F_45 ( V_9 , V_66 . V_67 , NULL ) ) ;
F_44 ( V_9 , F_45 ( V_9 , V_68 . V_67 , NULL ) ) ;
V_69 = F_46 ( F_2 ( V_64 ) ) ;
F_47 ( V_9 , & V_66 ) ;
V_70 = F_46 ( V_71 ) ;
F_47 ( V_9 , & V_68 ) ;
F_48 ( V_9 ) ;
return 0 ;
}
