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
struct V_3 V_24 , V_25 ;
struct V_3 * V_4 , * V_5 ;
T_4 V_26 ;
char V_27 [ V_28 * 5 ] , V_29 [ V_28 * 5 ] ;
F_9 () ;
if ( V_20 && V_19 ) {
F_10 ( & V_24 , V_20 ) ;
V_4 = & V_24 ;
} else {
F_3 ( & V_24 ) ;
V_4 = NULL ;
}
if ( V_4 == NULL )
V_19 = 0 ;
if ( V_22 && V_7 ) {
F_10 ( & V_25 , V_22 ) ;
V_5 = & V_25 ;
} else {
F_3 ( & V_25 ) ;
V_5 = NULL ;
}
F_2 ( V_4 , V_5 , V_6 , V_7 ,
V_8 , V_9 ) ;
V_26 = ( T_4 ) V_18 << V_30 ;
V_23 = F_11 ( V_26 , V_19 ,
F_12 ( V_4 ) ,
V_6 , V_7 , V_21 ,
F_12 ( V_5 ) ,
V_8 , V_9 ) ;
if ( V_23 == 0 )
return;
F_13 ( V_27 , sizeof( V_27 ) , & V_24 ) ;
F_13 ( V_29 , sizeof( V_29 ) , & V_25 ) ;
F_14 ( L_1
L_2 ,
V_26 , V_19 , V_4 , V_27 ,
( unsigned long ) V_6 , V_7 , V_21 ,
V_5 , V_29 ,
V_8 , V_9 , V_23 ) ;
F_15 ( L_3 ) ;
}
static void F_16 ( void * V_31 , int V_32 )
{
int V_12 = F_17 () ;
if ( V_32 == V_12 ) {
F_18 ( V_31 , V_33 ) ;
} else if ( V_32 == V_34 ) {
F_19 ( V_31 , V_33 , 1 ) ;
} else {
F_20 ( V_32 < 0 || V_32 >= V_28 ) ;
F_19 ( V_31 , V_33 , 0 ) ;
}
F_21 () ;
}
void F_22 ( struct V_35 * V_35 , int V_32 )
{
unsigned long V_36 ;
unsigned long V_31 ;
T_5 * V_37 ;
T_5 V_38 ;
if ( V_32 == V_39 )
return;
F_23 ( V_36 ) ;
#ifdef F_24
V_31 = F_25 ( V_40 + F_26 () +
( V_41 * F_27 () ) ) ;
#else
V_31 = F_25 ( V_42 + F_27 () ) ;
#endif
V_37 = F_28 ( V_31 ) ;
V_38 = F_29 ( F_30 ( V_35 ) , V_43 ) ;
F_31 ( V_37 , F_32 ( V_38 , V_32 ) ) ;
F_16 ( ( void * ) V_31 , V_32 ) ;
F_33 ( V_37 ) ;
F_34 ( V_31 , V_33 ) ;
#ifdef F_24
F_35 () ;
#endif
F_36 ( V_36 ) ;
}
static void F_37 ( struct V_35 * V_35 , int V_32 )
{
if ( ! F_38 ( V_35 ) && V_32 == F_39 ( V_35 ) )
F_16 ( F_40 ( V_35 ) , V_32 ) ;
else
F_22 ( V_35 , V_32 ) ;
}
static inline bool F_41 ( int V_32 )
{
return V_32 == V_44 || V_32 == V_45 ;
}
static void F_42 ( struct V_35 * V_35 , int V_46 )
{
int V_32 = F_39 ( V_35 ) ;
if ( V_32 == V_39 )
return;
if ( F_41 ( V_32 ) ) {
int V_12 ;
F_6 (cpu, &cpu_cacheable_map)
F_22 ( V_35 , V_12 ) ;
} else if ( V_46 ) {
F_22 ( V_35 , V_32 ) ;
} else {
F_37 ( V_35 , V_32 ) ;
}
F_43 ( F_44 ( F_30 ( V_35 ) ) , V_33 ) ;
}
void F_45 ( struct V_35 * V_35 )
{
F_42 ( V_35 , 0 ) ;
}
void F_46 ( const struct V_3 * V_10 )
{
F_8 ( 0 , V_47 , V_10 , 0 , 0 , 0 , NULL , NULL , 0 ) ;
}
static int F_47 ( T_5 V_38 )
{
if ( F_48 ( V_38 ) )
return V_44 ;
switch ( F_49 ( V_38 ) ) {
case V_48 :
return F_50 ( V_38 ) ;
case V_49 :
return V_45 ;
case V_50 :
return V_39 ;
case V_51 :
return V_34 ;
}
F_15 ( L_4 , V_38 . V_52 ) ;
}
T_5 F_32 ( T_5 V_38 , int V_32 )
{
if ( F_51 ( V_38 ) )
return V_38 ;
#if F_52 ()
if ( F_49 ( V_38 ) == V_53 )
return V_38 ;
#endif
if ( F_48 ( V_38 ) && V_32 != V_44 ) {
V_38 = F_53 ( V_38 ) ;
F_14 ( L_5 ,
V_38 . V_52 ) ;
}
switch ( V_32 ) {
case V_39 :
V_38 = F_54 ( V_38 , V_50 ) ;
break;
case V_45 :
V_38 = F_54 ( V_38 , V_49 ) ;
break;
case V_44 :
F_20 ( F_55 ( V_38 ) ) ;
if ( F_56 ( V_38 ) ) {
if ( F_49 ( V_38 ) == V_48
&& F_57 ( V_38 ) ) {
V_38 = F_54 ( V_38 ,
V_49 ) ;
}
} else
if ( V_54 )
V_38 = F_54 ( V_38 , V_51 ) ;
else
V_38 = F_54 ( V_38 , V_49 ) ;
V_38 = F_58 ( V_38 ) ;
break;
case V_34 :
V_38 = F_54 ( V_38 , V_51 ) ;
break;
default:
F_20 ( V_32 < 0 || V_32 >= V_28 ||
! F_59 ( V_32 ) ) ;
V_38 = F_54 ( V_38 , V_48 ) ;
V_38 = F_60 ( V_38 , V_32 ) ;
break;
}
if ( V_2 )
V_38 = F_61 ( V_38 ) ;
if ( F_62 ( V_38 ) && F_63 ( V_38 ) &&
F_49 ( V_38 ) == V_49 ) {
V_38 = F_54 ( V_38 , V_50 ) ;
}
F_20 ( F_49 ( V_38 ) == 0 ) ;
return V_38 ;
}
int F_39 ( struct V_35 * V_35 )
{
if ( F_38 ( V_35 ) ) {
return V_34 ;
} else {
unsigned long V_55 = ( unsigned long ) F_40 ( V_35 ) ;
return F_47 ( * F_28 ( V_55 ) ) ;
}
}
void F_64 ( struct V_35 * V_35 , int V_56 , int V_32 )
{
int V_11 , V_57 = ( 1 << V_56 ) ;
unsigned long V_55 ;
F_20 ( F_38 ( V_35 ) ) ;
F_20 ( F_65 ( V_35 ) > 1 ) ;
F_20 ( F_66 ( V_35 ) != 0 ) ;
V_55 = ( unsigned long ) F_40 ( V_35 ) ;
F_8 ( 0 , V_47 , & V_58 ,
V_55 , V_57 * V_33 , V_33 , V_59 ,
NULL , 0 ) ;
for ( V_11 = 0 ; V_11 < V_57 ; ++ V_11 , V_55 += V_33 ) {
T_5 * V_37 = F_28 ( V_55 ) ;
T_5 V_60 = * V_37 ;
F_20 ( ! F_67 ( V_60 ) || F_68 ( V_60 ) ) ;
F_31 ( V_37 , F_32 ( V_60 , V_32 ) ) ;
}
}
struct V_35 * F_69 ( T_6 V_61 ,
unsigned int V_56 , int V_32 )
{
struct V_35 * V_35 ;
F_20 ( V_61 & V_62 ) ;
V_35 = F_70 ( V_61 , V_56 ) ;
if ( V_35 )
F_64 ( V_35 , V_56 , V_32 ) ;
return V_35 ;
}
struct V_35 * F_71 ( int V_63 , T_6 V_61 ,
unsigned int V_56 , int V_32 )
{
struct V_35 * V_35 ;
F_20 ( V_61 & V_62 ) ;
V_35 = F_72 ( V_63 , V_61 , V_56 ) ;
if ( V_35 )
F_64 ( V_35 , V_56 , V_32 ) ;
return V_35 ;
}
void F_73 ( struct V_35 * V_35 , unsigned int V_56 )
{
if ( F_74 ( V_35 ) ) {
F_64 ( V_35 , V_56 , V_34 ) ;
if ( V_56 == 0 ) {
F_75 ( V_35 , 0 ) ;
} else {
F_76 ( V_35 ) ;
F_77 ( V_35 , V_56 ) ;
}
}
}
void F_78 ( unsigned long V_64 , unsigned int V_56 )
{
if ( V_64 != 0 ) {
F_79 ( ! F_80 ( ( void * ) V_64 ) ) ;
F_73 ( F_81 ( ( void * ) V_64 ) , V_56 ) ;
}
}
