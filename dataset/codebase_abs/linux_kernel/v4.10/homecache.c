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
V_26 = ( T_4 ) V_18 << V_27 ;
V_23 = F_11 ( V_26 , V_19 ,
F_12 ( V_4 ) ,
V_6 , V_7 , V_21 ,
F_12 ( V_5 ) ,
V_8 , V_9 ) ;
if ( V_23 == 0 )
return;
F_13 ( L_1 ,
V_26 , V_19 , V_4 ,
F_14 ( & V_24 ) ,
( unsigned long ) V_6 , V_7 , V_21 , V_5 ,
F_14 ( & V_25 ) , V_8 , V_9 , V_23 ) ;
F_15 ( L_2 ) ;
}
static void F_16 ( void * V_28 , int V_29 )
{
int V_12 = F_17 () ;
if ( V_29 == V_12 ) {
F_18 ( V_28 , V_30 ) ;
} else if ( V_29 == V_31 ) {
F_19 ( V_28 , V_30 , 1 ) ;
} else {
F_20 ( V_29 < 0 || V_29 >= V_32 ) ;
F_19 ( V_28 , V_30 , 0 ) ;
}
F_21 () ;
}
void F_22 ( struct V_33 * V_33 , int V_29 )
{
unsigned long V_34 ;
unsigned long V_28 ;
T_5 * V_35 ;
T_5 V_36 ;
if ( V_29 == V_37 )
return;
F_23 ( V_34 ) ;
#ifdef F_24
V_28 = F_25 ( V_38 + F_26 () +
( V_39 * F_27 () ) ) ;
#else
V_28 = F_25 ( V_40 + F_27 () ) ;
#endif
V_35 = F_28 ( V_28 ) ;
V_36 = F_29 ( F_30 ( V_33 ) , V_41 ) ;
F_31 ( V_35 , F_32 ( V_36 , V_29 ) ) ;
F_16 ( ( void * ) V_28 , V_29 ) ;
F_33 ( V_35 ) ;
F_34 ( V_28 , V_30 ) ;
#ifdef F_24
F_35 () ;
#endif
F_36 ( V_34 ) ;
}
static void F_37 ( struct V_33 * V_33 , int V_29 )
{
if ( ! F_38 ( V_33 ) && V_29 == F_39 ( V_33 ) )
F_16 ( F_40 ( V_33 ) , V_29 ) ;
else
F_22 ( V_33 , V_29 ) ;
}
static inline bool F_41 ( int V_29 )
{
return V_29 == V_42 || V_29 == V_43 ;
}
static void F_42 ( struct V_33 * V_33 , int V_44 )
{
int V_29 = F_39 ( V_33 ) ;
if ( V_29 == V_37 )
return;
if ( F_41 ( V_29 ) ) {
int V_12 ;
F_6 (cpu, &cpu_cacheable_map)
F_22 ( V_33 , V_12 ) ;
} else if ( V_44 ) {
F_22 ( V_33 , V_29 ) ;
} else {
F_37 ( V_33 , V_29 ) ;
}
F_43 ( F_44 ( F_30 ( V_33 ) ) , V_30 ) ;
}
void F_45 ( struct V_33 * V_33 )
{
F_42 ( V_33 , 0 ) ;
}
void F_46 ( const struct V_3 * V_10 )
{
F_8 ( 0 , V_45 , V_10 , 0 , 0 , 0 , NULL , NULL , 0 ) ;
}
static int F_47 ( T_5 V_36 )
{
if ( F_48 ( V_36 ) )
return V_42 ;
switch ( F_49 ( V_36 ) ) {
case V_46 :
return F_50 ( V_36 ) ;
case V_47 :
return V_43 ;
case V_48 :
return V_37 ;
case V_49 :
return V_31 ;
}
F_15 ( L_3 , V_36 . V_50 ) ;
}
T_5 F_32 ( T_5 V_36 , int V_29 )
{
#if F_51 ()
if ( F_49 ( V_36 ) == V_51 )
return V_36 ;
#endif
if ( F_48 ( V_36 ) && V_29 != V_42 ) {
V_36 = F_52 ( V_36 ) ;
F_13 ( L_4 ,
V_36 . V_50 ) ;
}
switch ( V_29 ) {
case V_37 :
V_36 = F_53 ( V_36 , V_48 ) ;
break;
case V_43 :
V_36 = F_53 ( V_36 , V_47 ) ;
break;
case V_42 :
F_20 ( F_54 ( V_36 ) ) ;
if ( F_55 ( V_36 ) ) {
if ( F_49 ( V_36 ) == V_46
&& F_56 ( V_36 ) ) {
V_36 = F_53 ( V_36 ,
V_47 ) ;
}
} else
if ( V_52 )
V_36 = F_53 ( V_36 , V_49 ) ;
else
V_36 = F_53 ( V_36 , V_47 ) ;
V_36 = F_57 ( V_36 ) ;
break;
case V_31 :
V_36 = F_53 ( V_36 , V_49 ) ;
break;
default:
F_20 ( V_29 < 0 || V_29 >= V_32 ||
! F_58 ( V_29 ) ) ;
V_36 = F_53 ( V_36 , V_46 ) ;
V_36 = F_59 ( V_36 , V_29 ) ;
break;
}
if ( V_2 )
V_36 = F_60 ( V_36 ) ;
if ( F_61 ( V_36 ) && F_62 ( V_36 ) &&
F_49 ( V_36 ) == V_47 ) {
V_36 = F_53 ( V_36 , V_48 ) ;
}
F_20 ( F_49 ( V_36 ) == 0 ) ;
return V_36 ;
}
int F_39 ( struct V_33 * V_33 )
{
if ( F_38 ( V_33 ) ) {
return V_31 ;
} else {
unsigned long V_53 = ( unsigned long ) F_40 ( V_33 ) ;
return F_47 ( * F_28 ( V_53 ) ) ;
}
}
void F_63 ( struct V_33 * V_33 , int V_54 , int V_29 )
{
int V_11 , V_55 = ( 1 << V_54 ) ;
unsigned long V_53 ;
F_20 ( F_38 ( V_33 ) ) ;
F_20 ( F_64 ( V_33 ) > 1 ) ;
F_20 ( F_65 ( V_33 ) != 0 ) ;
V_53 = ( unsigned long ) F_40 ( V_33 ) ;
F_8 ( 0 , V_45 , & V_56 ,
V_53 , V_55 * V_30 , V_30 , V_57 ,
NULL , 0 ) ;
for ( V_11 = 0 ; V_11 < V_55 ; ++ V_11 , V_53 += V_30 ) {
T_5 * V_35 = F_28 ( V_53 ) ;
T_5 V_58 = * V_35 ;
F_20 ( ! F_66 ( V_58 ) || F_67 ( V_58 ) ) ;
F_31 ( V_35 , F_32 ( V_58 , V_29 ) ) ;
}
}
struct V_33 * F_68 ( T_6 V_59 ,
unsigned int V_54 , int V_29 )
{
struct V_33 * V_33 ;
F_20 ( V_59 & V_60 ) ;
V_33 = F_69 ( V_59 , V_54 ) ;
if ( V_33 )
F_63 ( V_33 , V_54 , V_29 ) ;
return V_33 ;
}
struct V_33 * F_70 ( int V_61 , T_6 V_59 ,
unsigned int V_54 , int V_29 )
{
struct V_33 * V_33 ;
F_20 ( V_59 & V_60 ) ;
V_33 = F_71 ( V_61 , V_59 , V_54 ) ;
if ( V_33 )
F_63 ( V_33 , V_54 , V_29 ) ;
return V_33 ;
}
void F_72 ( struct V_33 * V_33 , unsigned int V_54 )
{
if ( F_73 ( V_33 ) ) {
F_63 ( V_33 , V_54 , V_31 ) ;
if ( V_54 == 0 ) {
F_74 ( V_33 , false ) ;
} else {
F_75 ( V_33 ) ;
F_76 ( V_33 , V_54 ) ;
}
}
}
void F_77 ( unsigned long V_62 , unsigned int V_54 )
{
if ( V_62 != 0 ) {
F_78 ( ! F_79 ( ( void * ) V_62 ) ) ;
F_72 ( F_80 ( ( void * ) V_62 ) , V_54 ) ;
}
}
