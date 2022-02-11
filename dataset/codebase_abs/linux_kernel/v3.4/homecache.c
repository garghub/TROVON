static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static void F_2 ( const struct V_3 * V_4 ,
struct V_3 * V_5 ,
unsigned long V_6 , unsigned long V_7 ,
T_2 * V_8 , int V_9 )
{
struct V_3 V_10 ;
int V_11 , V_12 ;
F_3 ( & V_10 ) ;
if ( V_4 )
F_4 ( & V_10 , & V_10 , V_4 ) ;
if ( V_5 && V_7 ) {
F_4 ( & V_10 , & V_10 , V_5 ) ;
}
for ( V_11 = 0 ; V_11 < V_9 ; ++ V_11 )
F_5 ( V_8 [ V_11 ] . V_13 * V_14 + V_8 [ V_11 ] . V_15 , & V_10 ) ;
F_6 ( V_12 , & V_10 )
++ F_7 ( V_16 , V_12 ) . V_17 ;
}
void F_8 ( unsigned long V_18 , unsigned long V_19 ,
const struct V_3 * V_20 ,
T_3 V_6 , unsigned long V_7 ,
unsigned long V_21 ,
const struct V_3 * V_22 ,
T_2 * V_8 , int V_9 )
{
int V_23 ;
int V_24 = 0 ;
struct V_3 V_25 , V_26 ;
struct V_3 * V_4 , * V_5 ;
T_4 V_27 ;
char V_28 [ V_29 * 5 ] , V_30 [ V_29 * 5 ] ;
F_9 () ;
if ( V_20 && V_19 ) {
F_10 ( & V_25 , V_20 ) ;
V_4 = & V_25 ;
} else {
F_3 ( & V_25 ) ;
V_4 = NULL ;
}
if ( V_4 == NULL )
V_19 = 0 ;
if ( V_22 && V_7 ) {
F_10 ( & V_26 , V_22 ) ;
V_5 = & V_26 ;
} else {
F_3 ( & V_26 ) ;
V_5 = NULL ;
}
F_2 ( V_4 , V_5 , V_6 , V_7 ,
V_8 , V_9 ) ;
V_27 = ( T_4 ) V_18 << V_31 ;
if ( V_19 & V_32 )
V_24 = F_11 () ;
V_23 = F_12 ( V_27 , V_19 ,
F_13 ( V_4 ) ,
V_6 , V_7 , V_21 ,
F_13 ( V_5 ) ,
V_8 , V_9 ) ;
if ( V_19 & V_32 )
F_14 ( V_4 , V_24 ) ;
if ( V_23 == 0 )
return;
F_15 ( V_28 , sizeof( V_28 ) , & V_25 ) ;
F_15 ( V_30 , sizeof( V_30 ) , & V_26 ) ;
F_16 ( L_1
L_2 ,
V_27 , V_19 , V_4 , V_28 ,
( unsigned long ) V_6 , V_7 , V_21 ,
V_5 , V_30 ,
V_8 , V_9 , V_23 ) ;
F_17 ( L_3 ) ;
}
void F_18 ( struct V_33 * V_33 , int V_34 )
{
int V_11 , V_35 = ( 1 << V_34 ) ;
for ( V_11 = 0 ; V_11 < V_35 ; ++ V_11 , ++ V_33 ) {
void * V_36 = F_19 ( V_33 ) ;
int V_37 = 0 ;
int V_38 = F_20 ( V_33 ) ;
#if F_21 ()
if ( V_38 == V_39 )
V_37 = 1 ;
else
#endif
F_22 ( V_38 < 0 || V_38 >= V_29 ) ;
F_23 ( V_36 , V_40 , V_37 ) ;
F_24 ( V_36 ) ;
}
}
void F_25 ( const struct V_3 * V_10 )
{
F_8 ( 0 , V_32 , V_10 , 0 , 0 , 0 , NULL , NULL , 0 ) ;
}
static int F_26 ( struct V_33 * V_33 , int V_35 ,
struct V_3 * V_41 )
{
int V_11 ;
int V_42 = 1 ;
F_3 ( V_41 ) ;
for ( V_11 = 0 ; V_11 < V_35 ; ++ V_11 ) {
int V_38 = F_20 ( & V_33 [ V_11 ] ) ;
if ( V_38 == V_43 ||
V_38 == V_44 ) {
F_10 ( V_41 , V_45 ) ;
return 0 ;
}
#if F_21 ()
if ( V_38 == V_39 ) {
F_4 ( V_41 , V_41 , & V_46 ) ;
continue;
}
#endif
if ( V_38 == V_47 ) {
V_42 = 0 ;
continue;
}
F_22 ( V_38 < 0 || V_38 >= V_29 ) ;
F_5 ( V_38 , V_41 ) ;
}
return V_42 ;
}
static unsigned long F_27 ( unsigned long V_48 )
{
return ( V_48 >= F_28 () ) ? V_32 : V_48 ;
}
void F_29 ( struct V_33 * V_33 , int V_34 )
{
int V_35 = 1 << V_34 ;
int V_48 = F_27 ( V_35 * V_40 ) ;
unsigned long V_49 = F_30 ( V_33 ) ;
struct V_3 V_41 ;
F_26 ( V_33 , V_35 , & V_41 ) ;
F_8 ( V_49 , V_48 , & V_41 , 0 , 0 , 0 , NULL , NULL , 0 ) ;
F_31 ( F_32 ( V_49 ) , V_35 * V_40 ) ;
}
static int F_33 ( T_5 V_50 )
{
if ( F_34 ( V_50 ) )
return V_43 ;
switch ( F_35 ( V_50 ) ) {
case V_51 :
return F_36 ( V_50 ) ;
case V_52 :
return V_44 ;
case V_53 :
return V_47 ;
#if F_21 ()
case V_54 :
return V_39 ;
#endif
}
F_17 ( L_4 , V_50 . V_55 ) ;
}
T_5 F_37 ( T_5 V_50 , int V_38 )
{
if ( F_38 ( V_50 ) )
return V_50 ;
#if F_39 ()
if ( F_35 ( V_50 ) == V_56 )
return V_50 ;
#endif
if ( F_34 ( V_50 ) && V_38 != V_43 ) {
V_50 = F_40 ( V_50 ) ;
F_16 ( L_5 ,
V_50 . V_55 ) ;
}
switch ( V_38 ) {
case V_47 :
V_50 = F_41 ( V_50 , V_53 ) ;
break;
case V_44 :
V_50 = F_41 ( V_50 , V_52 ) ;
break;
case V_43 :
F_22 ( F_42 ( V_50 ) ) ;
if ( F_43 ( V_50 ) ) {
if ( F_35 ( V_50 ) == V_51
&& F_44 ( V_50 ) ) {
V_50 = F_41 ( V_50 ,
V_52 ) ;
}
} else
#if F_21 ()
if ( V_57 )
V_50 = F_41 ( V_50 , V_54 ) ;
else
#endif
V_50 = F_41 ( V_50 , V_52 ) ;
V_50 = F_45 ( V_50 ) ;
break;
#if F_21 ()
case V_39 :
V_50 = F_41 ( V_50 , V_54 ) ;
break;
#endif
default:
F_22 ( V_38 < 0 || V_38 >= V_29 ||
! F_46 ( V_38 ) ) ;
V_50 = F_41 ( V_50 , V_51 ) ;
V_50 = F_47 ( V_50 , V_38 ) ;
break;
}
#if F_48 ()
if ( V_2 )
V_50 = F_49 ( V_50 ) ;
if ( F_50 ( V_50 ) && F_51 ( V_50 ) &&
F_35 ( V_50 ) == V_52 ) {
V_50 = F_41 ( V_50 , V_53 ) ;
}
#endif
F_22 ( F_35 ( V_50 ) == 0 ) ;
return V_50 ;
}
static inline int F_52 ( void ) { return V_39 ; }
static inline int F_52 ( void ) { return 0 ; }
int F_20 ( struct V_33 * V_33 )
{
if ( F_53 ( V_33 ) ) {
return F_52 () ;
} else {
unsigned long V_58 = ( unsigned long ) F_54 ( V_33 ) ;
return F_33 ( * F_55 ( NULL , V_58 ) ) ;
}
}
void F_56 ( struct V_33 * V_33 , int V_34 , int V_38 )
{
int V_11 , V_35 = ( 1 << V_34 ) ;
unsigned long V_58 ;
F_22 ( F_53 ( V_33 ) ) ;
F_22 ( F_57 ( V_33 ) > 1 ) ;
F_22 ( F_58 ( V_33 ) != 0 ) ;
V_58 = ( unsigned long ) F_54 ( V_33 ) ;
F_8 ( 0 , V_32 , & V_59 ,
V_58 , V_35 * V_40 , V_40 , V_60 ,
NULL , 0 ) ;
for ( V_11 = 0 ; V_11 < V_35 ; ++ V_11 , V_58 += V_40 ) {
T_5 * V_61 = F_55 ( NULL , V_58 ) ;
T_5 V_62 = * V_61 ;
F_22 ( ! F_59 ( V_62 ) || F_60 ( V_62 ) ) ;
F_61 ( V_61 , F_37 ( V_62 , V_38 ) ) ;
}
}
struct V_33 * F_62 ( T_6 V_63 ,
unsigned int V_34 , int V_38 )
{
struct V_33 * V_33 ;
F_22 ( V_63 & V_64 ) ;
V_33 = F_63 ( V_63 , V_34 ) ;
if ( V_33 )
F_56 ( V_33 , V_34 , V_38 ) ;
return V_33 ;
}
struct V_33 * F_64 ( int V_65 , T_6 V_63 ,
unsigned int V_34 , int V_38 )
{
struct V_33 * V_33 ;
F_22 ( V_63 & V_64 ) ;
V_33 = F_65 ( V_65 , V_63 , V_34 ) ;
if ( V_33 )
F_56 ( V_33 , V_34 , V_38 ) ;
return V_33 ;
}
void F_66 ( unsigned long V_66 , unsigned int V_34 )
{
struct V_33 * V_33 ;
if ( V_66 == 0 )
return;
F_67 ( ! F_68 ( ( void * ) V_66 ) ) ;
V_33 = F_69 ( ( void * ) V_66 ) ;
if ( F_70 ( V_33 ) ) {
F_56 ( V_33 , V_34 , F_52 () ) ;
if ( V_34 == 0 ) {
F_71 ( V_33 , 0 ) ;
} else {
F_72 ( V_33 ) ;
F_73 ( V_33 , V_34 ) ;
}
}
}
