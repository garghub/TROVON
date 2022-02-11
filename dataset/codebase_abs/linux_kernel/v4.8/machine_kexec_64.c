int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ )
if ( V_2 -> V_5 [ V_3 ] . V_6 < F_2 ( V_7 ) )
return - V_8 ;
return 0 ;
}
int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned long V_9 , V_10 ;
unsigned long V_11 , V_12 ;
struct V_13 * V_14 ;
const unsigned long * V_15 ;
const unsigned int * V_16 ;
if ( ! V_17 . V_18 )
return - V_19 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ )
if ( V_2 -> V_5 [ V_3 ] . V_6 < F_2 ( V_7 ) )
return - V_8 ;
#ifdef F_3
if ( V_20 ) {
V_11 = F_2 ( V_20 ) ;
V_12 = V_11 + V_21 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
V_9 = V_2 -> V_5 [ V_3 ] . V_6 ;
V_10 = V_9 + V_2 -> V_5 [ V_3 ] . V_22 ;
if ( ( V_9 < V_12 ) && ( V_10 > V_11 ) )
return - V_8 ;
}
}
#endif
F_4 (node, L_1 ) {
V_15 = F_5 ( V_14 , L_2 , NULL ) ;
V_16 = F_5 ( V_14 , L_3 , NULL ) ;
if ( V_15 == NULL || V_16 == NULL )
continue;
V_11 = * V_15 ;
V_12 = V_11 + ( * V_16 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; V_3 ++ ) {
V_9 = V_2 -> V_5 [ V_3 ] . V_6 ;
V_10 = V_9 + V_2 -> V_5 [ V_3 ] . V_22 ;
if ( ( V_9 < V_12 ) && ( V_10 > V_11 ) )
return - V_8 ;
}
}
return 0 ;
}
static void F_6 ( unsigned long V_23 )
{
unsigned long V_24 ;
unsigned long * V_25 ;
void * V_26 ;
void * V_27 ;
V_25 = NULL ;
V_26 = NULL ;
for ( V_24 = V_23 ; ! ( V_24 & V_28 ) ; V_24 = * V_25 ++ ) {
V_27 = F_7 ( V_24 & V_29 ) ;
switch ( V_24 & V_30 ) {
case V_31 :
V_26 = V_27 ;
break;
case V_32 :
V_25 = V_27 ;
break;
case V_33 :
F_8 ( V_26 , V_27 ) ;
V_26 += V_34 ;
}
}
}
void F_9 ( struct V_1 * V_2 )
{
long V_3 , V_4 = V_2 -> V_4 ;
struct V_35 V_36 [ V_37 ] ;
memcpy ( V_36 , V_2 -> V_5 , sizeof( V_36 ) ) ;
F_6 ( V_2 -> V_38 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
F_10 ( ( unsigned long ) F_7 ( V_36 [ V_3 ] . V_6 ) ,
( unsigned long ) F_7 ( V_36 [ V_3 ] . V_6 + V_36 [ V_3 ] . V_22 ) ) ;
}
static void F_11 ( void * V_39 )
{
F_12 () ;
F_13 () ;
F_14 () ;
F_15 () -> V_40 = V_41 ;
while( V_42 == 0 )
F_16 () ;
F_14 () ;
F_17 () ;
if ( V_43 . V_44 )
V_43 . V_44 ( 0 , 1 ) ;
F_18 () ;
}
static void F_19 ( int V_45 )
{
int V_46 , V_3 , V_47 = - 1 ;
F_17 () ;
V_46 = F_20 () ;
F_21 (i) {
if ( V_3 == V_46 )
continue;
while ( V_48 [ V_3 ] . V_40 < V_45 ) {
F_22 () ;
if ( V_3 != V_47 ) {
F_23 ( V_49 L_4
L_5 ,
V_3 , V_48 [ V_3 ] . V_50 , V_45 ) ;
V_47 = V_3 ;
}
}
}
F_14 () ;
}
static void F_24 ( void )
{
int V_51 = 0 ;
F_25 (cpu) {
if ( ! F_26 ( V_51 ) ) {
F_23 ( V_49 L_6 ,
V_51 ) ;
F_27 ( F_28 ( V_51 ) ) ;
}
}
}
static void F_29 ( void )
{
F_24 () ;
F_30 ( F_11 , NULL , 0 ) ;
F_12 () ;
F_13 () ;
F_14 () ;
F_15 () -> V_40 = V_41 ;
F_19 ( V_41 ) ;
V_42 = 1 ;
if ( V_43 . V_44 )
V_43 . V_44 ( 0 , 0 ) ;
F_19 ( V_52 ) ;
F_31 () ;
}
static void F_29 ( void )
{
F_32 () ;
if ( V_43 . V_44 )
V_43 . V_44 ( 0 , 0 ) ;
F_12 () ;
F_13 () ;
}
void F_33 ( struct V_1 * V_2 )
{
if ( ! F_34 () )
F_29 () ;
F_35 ( L_7 ) ;
V_53 . V_54 . V_55 = F_36 () -> V_55 ;
V_53 . V_54 . V_56 = 0 ;
V_53 . V_54 . V_57 = V_58 ;
V_53 . V_54 . V_51 = F_36 () -> V_51 ;
memcpy ( & V_59 , F_15 () , sizeof( struct V_60 ) ) ;
V_59 . V_61 = 0xedeaddeadeeeeeeeUL ;
V_48 = (struct V_60 * ) F_37 ( & V_59 , 0 ) -
V_59 . V_62 ;
F_38 ( & V_59 ) ;
F_39 (&kexec_stack, image->start, image,
page_address(image->control_code_page),
#ifdef F_40
mmu_hash_ops.hpte_clear_all
#else
NULL
#endif
) ;
}
static int T_1 F_41 ( void )
{
struct V_13 * V_14 ;
if ( ! V_20 )
return - V_63 ;
V_14 = F_42 ( L_8 ) ;
if ( ! V_14 )
return - V_63 ;
F_43 ( V_14 , F_44 ( V_14 , V_64 . V_65 , NULL ) ) ;
F_43 ( V_14 , F_44 ( V_14 , V_66 . V_65 , NULL ) ) ;
V_67 = F_45 ( F_2 ( V_20 ) ) ;
F_46 ( V_14 , & V_64 ) ;
V_68 = F_45 ( V_21 ) ;
F_46 ( V_14 , & V_66 ) ;
F_47 ( V_14 ) ;
return 0 ;
}
