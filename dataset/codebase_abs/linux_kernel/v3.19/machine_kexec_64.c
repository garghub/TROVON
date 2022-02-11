int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned long V_4 , V_5 ;
unsigned long V_6 , V_7 ;
struct V_8 * V_9 ;
const unsigned long * V_10 ;
const unsigned int * V_11 ;
if ( ! V_12 . V_13 )
return - V_14 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_15 ; V_3 ++ )
if ( V_2 -> V_16 [ V_3 ] . V_17 < F_2 ( V_18 ) )
return - V_19 ;
if ( V_20 ) {
V_6 = F_2 ( V_20 ) ;
V_7 = V_6 + V_21 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_15 ; V_3 ++ ) {
V_4 = V_2 -> V_16 [ V_3 ] . V_17 ;
V_5 = V_4 + V_2 -> V_16 [ V_3 ] . V_22 ;
if ( ( V_4 < V_7 ) && ( V_5 > V_6 ) )
return - V_19 ;
}
}
F_3 (node, L_1 ) {
V_10 = F_4 ( V_9 , L_2 , NULL ) ;
V_11 = F_4 ( V_9 , L_3 , NULL ) ;
if ( V_10 == NULL || V_11 == NULL )
continue;
V_6 = * V_10 ;
V_7 = V_6 + ( * V_11 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_15 ; V_3 ++ ) {
V_4 = V_2 -> V_16 [ V_3 ] . V_17 ;
V_5 = V_4 + V_2 -> V_16 [ V_3 ] . V_22 ;
if ( ( V_4 < V_7 ) && ( V_5 > V_6 ) )
return - V_19 ;
}
}
return 0 ;
}
static void F_5 ( unsigned long V_23 )
{
unsigned long V_24 ;
unsigned long * V_25 ;
void * V_26 ;
void * V_27 ;
V_25 = NULL ;
V_26 = NULL ;
for ( V_24 = V_23 ; ! ( V_24 & V_28 ) ; V_24 = * V_25 ++ ) {
V_27 = F_6 ( V_24 & V_29 ) ;
switch ( V_24 & V_30 ) {
case V_31 :
V_26 = V_27 ;
break;
case V_32 :
V_25 = V_27 ;
break;
case V_33 :
F_7 ( V_26 , V_27 ) ;
V_26 += V_34 ;
}
}
}
void F_8 ( struct V_1 * V_2 )
{
long V_3 , V_15 = V_2 -> V_15 ;
struct V_35 V_36 [ V_37 ] ;
memcpy ( V_36 , V_2 -> V_16 , sizeof( V_36 ) ) ;
F_5 ( V_2 -> V_38 ) ;
for ( V_3 = 0 ; V_3 < V_15 ; V_3 ++ )
F_9 ( ( unsigned long ) F_6 ( V_36 [ V_3 ] . V_17 ) ,
( unsigned long ) F_6 ( V_36 [ V_3 ] . V_17 + V_36 [ V_3 ] . V_22 ) ) ;
}
static void F_10 ( void * V_39 )
{
F_11 () ;
F_12 () ;
F_13 () ;
F_14 () -> V_40 = V_41 ;
while( V_42 == 0 )
F_15 () ;
F_13 () ;
F_16 () ;
if ( V_12 . V_43 )
V_12 . V_43 ( 0 , 1 ) ;
F_17 () ;
}
static void F_18 ( int V_44 )
{
int V_45 , V_3 , V_46 = - 1 ;
F_16 () ;
V_45 = F_19 () ;
F_20 (i) {
if ( V_3 == V_45 )
continue;
while ( V_47 [ V_3 ] . V_40 < V_44 ) {
F_21 () ;
if ( V_3 != V_46 ) {
F_22 ( V_48 L_4
L_5 ,
V_3 , V_47 [ V_3 ] . V_49 , V_44 ) ;
V_46 = V_3 ;
}
}
}
F_13 () ;
}
static void F_23 ( void )
{
int V_50 = 0 ;
F_24 (cpu) {
if ( ! F_25 ( V_50 ) ) {
F_22 ( V_48 L_6 ,
V_50 ) ;
F_26 ( F_27 ( V_50 ) ) ;
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
F_14 () -> V_40 = V_41 ;
F_18 ( V_41 ) ;
V_42 = 1 ;
if ( V_12 . V_43 )
V_12 . V_43 ( 0 , 0 ) ;
F_18 ( V_51 ) ;
F_30 () ;
}
static void F_28 ( void )
{
F_31 () ;
if ( V_12 . V_43 )
V_12 . V_43 ( 0 , 0 ) ;
F_11 () ;
F_12 () ;
}
void F_32 ( struct V_1 * V_2 )
{
if ( ! F_33 () )
F_28 () ;
F_34 ( L_7 ) ;
V_52 . V_53 . V_54 = F_35 () -> V_54 ;
V_52 . V_53 . V_55 = 0 ;
V_52 . V_53 . V_56 = V_57 ;
V_52 . V_53 . V_50 = F_35 () -> V_50 ;
memcpy ( & V_58 , F_14 () , sizeof( struct V_59 ) ) ;
V_58 . V_60 = 0xedeaddeadeeeeeeeUL ;
V_47 = (struct V_59 * ) F_36 ( & V_58 , 0 ) -
V_58 . V_61 ;
F_37 ( & V_58 ) ;
F_38 ( & V_52 , V_2 -> V_62 , V_2 ,
F_39 ( V_2 -> V_63 ) ,
V_12 . V_13 ) ;
}
static int T_1 F_40 ( void )
{
struct V_8 * V_9 ;
struct V_64 * V_65 ;
if ( ! V_20 )
return - V_66 ;
V_9 = F_41 ( L_8 ) ;
if ( ! V_9 )
return - V_66 ;
V_65 = F_42 ( V_9 , V_67 . V_68 , NULL ) ;
if ( V_65 )
F_43 ( V_9 , V_65 ) ;
V_65 = F_42 ( V_9 , V_69 . V_68 , NULL ) ;
if ( V_65 )
F_43 ( V_9 , V_65 ) ;
V_70 = F_44 ( F_2 ( V_20 ) ) ;
F_45 ( V_9 , & V_67 ) ;
V_71 = F_44 ( V_21 ) ;
F_45 ( V_9 , & V_69 ) ;
F_46 ( V_9 ) ;
return 0 ;
}
