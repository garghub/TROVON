static bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 , & V_2 -> V_4 ) ;
}
static void F_3 ( const char * V_5 ,
struct V_1 * V_6 )
{
F_4 ( L_1 , V_5 , V_6 -> V_7 ,
V_6 -> line & V_8 , V_6 -> V_9 & V_10 ) ;
}
static bool F_5 ( struct V_1 * V_6 )
{
return V_11 -> V_12 || F_1 ( V_6 ) ;
}
static bool F_6 ( struct V_13 * type )
{
return type -> V_14 == V_15 ;
}
static bool F_7 ( struct V_13 * type )
{
F_8 ( ! F_6 ( type ) ) ;
return type -> V_16 & 1 ;
}
static unsigned F_9 ( struct V_13 * type )
{
return 1 << ( type -> V_16 >> 1 ) ;
}
static bool F_10 ( struct V_13 * type )
{
unsigned V_17 = sizeof( unsigned long ) * 8 ;
unsigned V_18 = F_9 ( type ) ;
F_8 ( ! F_6 ( type ) ) ;
return V_18 <= V_17 ;
}
static T_1 F_11 ( struct V_13 * type , unsigned long V_19 )
{
if ( F_10 ( type ) ) {
unsigned V_20 = sizeof( T_1 ) * 8 - F_9 ( type ) ;
return ( ( T_1 ) V_19 ) << V_20 >> V_20 ;
}
if ( F_9 ( type ) == 64 )
return * ( V_21 * ) V_19 ;
return * ( T_1 * ) V_19 ;
}
static bool F_12 ( struct V_13 * type , unsigned long V_19 )
{
return F_7 ( type ) && F_11 ( type , V_19 ) < 0 ;
}
static T_2 F_13 ( struct V_13 * type , unsigned long V_19 )
{
if ( F_10 ( type ) )
return V_19 ;
if ( F_9 ( type ) == 64 )
return * ( V_22 * ) V_19 ;
return * ( T_2 * ) V_19 ;
}
static void F_14 ( char * V_23 , T_3 V_24 , struct V_13 * type ,
unsigned long V_25 )
{
if ( F_6 ( type ) ) {
if ( F_9 ( type ) == 128 ) {
#if F_15 ( V_26 ) && F_15 ( V_27 )
T_2 V_19 = F_13 ( type , V_25 ) ;
F_16 ( V_23 , V_24 , L_2 ,
( V_28 ) ( V_19 >> 96 ) ,
( V_28 ) ( V_19 >> 64 ) ,
( V_28 ) ( V_19 >> 32 ) ,
( V_28 ) ( V_19 ) ) ;
#else
F_8 ( 1 ) ;
#endif
} else if ( F_7 ( type ) ) {
F_16 ( V_23 , V_24 , L_3 ,
( V_21 ) F_11 ( type , V_25 ) ) ;
} else {
F_16 ( V_23 , V_24 , L_4 ,
( V_22 ) F_13 ( type , V_25 ) ) ;
}
}
}
static bool F_17 ( struct V_1 * V_6 )
{
return V_6 -> V_7 != NULL ;
}
static void F_18 ( struct V_1 * V_2 ,
unsigned long * V_29 )
{
V_11 -> V_12 ++ ;
F_19 ( & V_30 , * V_29 ) ;
F_4 ( L_5
L_6 ) ;
F_3 ( L_7 , V_2 ) ;
}
static void F_20 ( unsigned long * V_29 )
{
F_21 () ;
F_4 ( L_5
L_6 ) ;
F_22 ( & V_30 , * V_29 ) ;
V_11 -> V_12 -- ;
}
static void F_23 ( struct V_31 * V_32 , unsigned long V_33 ,
unsigned long V_34 , char V_35 )
{
struct V_13 * type = V_32 -> type ;
unsigned long V_29 ;
char V_36 [ V_37 ] ;
char V_38 [ V_37 ] ;
if ( F_5 ( & V_32 -> V_2 ) )
return;
F_18 ( & V_32 -> V_2 , & V_29 ) ;
F_14 ( V_36 , sizeof( V_36 ) , type , V_33 ) ;
F_14 ( V_38 , sizeof( V_38 ) , type , V_34 ) ;
F_4 ( L_8 ,
F_7 ( type ) ? L_9 : L_10 ) ;
F_4 ( L_11 ,
V_36 ,
V_35 ,
V_38 ,
type -> V_39 ) ;
F_20 ( & V_29 ) ;
}
void F_24 ( struct V_31 * V_32 ,
unsigned long V_33 ,
unsigned long V_34 )
{
F_23 ( V_32 , V_33 , V_34 , '+' ) ;
}
void F_25 ( struct V_31 * V_32 ,
unsigned long V_33 ,
unsigned long V_34 )
{
F_23 ( V_32 , V_33 , V_34 , '-' ) ;
}
void F_26 ( struct V_31 * V_32 ,
unsigned long V_33 ,
unsigned long V_34 )
{
F_23 ( V_32 , V_33 , V_34 , '*' ) ;
}
void F_27 ( struct V_31 * V_32 ,
unsigned long V_40 )
{
unsigned long V_29 ;
char V_41 [ V_37 ] ;
if ( F_5 ( & V_32 -> V_2 ) )
return;
F_18 ( & V_32 -> V_2 , & V_29 ) ;
F_14 ( V_41 , sizeof( V_41 ) , V_32 -> type , V_40 ) ;
F_4 ( L_12 ,
V_41 , V_32 -> type -> V_39 ) ;
F_20 ( & V_29 ) ;
}
void F_28 ( struct V_31 * V_32 ,
unsigned long V_33 ,
unsigned long V_34 )
{
unsigned long V_29 ;
char V_38 [ V_37 ] ;
if ( F_5 ( & V_32 -> V_2 ) )
return;
F_18 ( & V_32 -> V_2 , & V_29 ) ;
F_14 ( V_38 , sizeof( V_38 ) , V_32 -> type , V_34 ) ;
if ( F_7 ( V_32 -> type ) && F_11 ( V_32 -> type , V_34 ) == - 1 )
F_4 ( L_13 ,
V_38 , V_32 -> type -> V_39 ) ;
else
F_4 ( L_14 ) ;
F_20 ( & V_29 ) ;
}
static void F_29 ( struct V_42 * V_32 )
{
unsigned long V_29 ;
if ( F_5 ( & V_32 -> V_2 ) )
return;
F_18 ( & V_32 -> V_2 , & V_29 ) ;
F_4 ( L_15 ,
V_43 [ V_32 -> V_44 ] ,
V_32 -> type -> V_39 ) ;
F_20 ( & V_29 ) ;
}
static void F_30 ( struct V_42 * V_32 ,
unsigned long V_45 )
{
unsigned long V_29 ;
if ( F_5 ( & V_32 -> V_2 ) )
return;
F_18 ( & V_32 -> V_2 , & V_29 ) ;
F_4 ( L_16 ,
V_43 [ V_32 -> V_44 ] ,
( void * ) V_45 , V_32 -> type -> V_39 ) ;
F_4 ( L_17 , V_32 -> V_46 ) ;
F_20 ( & V_29 ) ;
}
static void F_31 ( struct V_42 * V_32 ,
unsigned long V_45 )
{
unsigned long V_29 ;
if ( F_5 ( & V_32 -> V_2 ) )
return;
F_18 ( & V_32 -> V_2 , & V_29 ) ;
F_4 ( L_18 ,
V_43 [ V_32 -> V_44 ] ,
( void * ) V_45 ) ;
F_4 ( L_19 , V_32 -> type -> V_39 ) ;
F_20 ( & V_29 ) ;
}
void F_32 ( struct V_42 * V_32 ,
unsigned long V_45 )
{
if ( ! V_45 )
F_29 ( V_32 ) ;
else if ( V_32 -> V_46 && ! F_33 ( V_45 , V_32 -> V_46 ) )
F_30 ( V_32 , V_45 ) ;
else
F_31 ( V_32 , V_45 ) ;
}
void F_34 ( struct V_47 * V_32 )
{
unsigned long V_29 ;
if ( F_5 ( & V_32 -> V_2 ) )
return;
F_18 ( & V_32 -> V_2 , & V_29 ) ;
F_4 ( L_20 ) ;
if ( F_17 ( & V_32 -> V_48 ) )
F_3 ( L_21 ,
& V_32 -> V_48 ) ;
F_20 ( & V_29 ) ;
}
void F_35 ( struct V_49 * V_32 ,
unsigned long V_50 )
{
unsigned long V_29 ;
char V_51 [ V_37 ] ;
if ( F_5 ( & V_32 -> V_2 ) )
return;
F_18 ( & V_32 -> V_2 , & V_29 ) ;
F_14 ( V_51 , sizeof( V_51 ) , V_32 -> type , V_50 ) ;
F_4 ( L_22 , V_51 ) ;
F_20 ( & V_29 ) ;
}
void F_36 ( struct V_52 * V_32 ,
unsigned long V_53 )
{
unsigned long V_29 ;
char V_54 [ V_37 ] ;
if ( F_5 ( & V_32 -> V_2 ) )
return;
F_18 ( & V_32 -> V_2 , & V_29 ) ;
F_14 ( V_54 , sizeof( V_54 ) , V_32 -> V_55 , V_53 ) ;
F_4 ( L_23 , V_54 ,
V_32 -> V_56 -> V_39 ) ;
F_20 ( & V_29 ) ;
}
void F_37 ( struct V_57 * V_32 ,
unsigned long V_33 , unsigned long V_34 )
{
unsigned long V_29 ;
struct V_13 * V_58 = V_32 -> V_58 ;
struct V_13 * V_59 = V_32 -> V_59 ;
char V_60 [ V_37 ] ;
char V_61 [ V_37 ] ;
if ( F_5 ( & V_32 -> V_2 ) )
return;
F_18 ( & V_32 -> V_2 , & V_29 ) ;
F_14 ( V_60 , sizeof( V_60 ) , V_58 , V_34 ) ;
F_14 ( V_61 , sizeof( V_61 ) , V_59 , V_33 ) ;
if ( F_12 ( V_58 , V_34 ) )
F_4 ( L_24 , V_60 ) ;
else if ( F_13 ( V_58 , V_34 ) >=
F_9 ( V_59 ) )
F_4 ( L_25 ,
V_60 ,
F_9 ( V_59 ) ,
V_59 -> V_39 ) ;
else if ( F_12 ( V_59 , V_33 ) )
F_4 ( L_26 ,
V_61 ) ;
else
F_4 ( L_27
L_28 ,
V_61 , V_60 ,
V_59 -> V_39 ) ;
F_20 ( & V_29 ) ;
}
void T_4
F_38 ( struct V_62 * V_32 )
{
unsigned long V_29 ;
F_18 ( & V_32 -> V_2 , & V_29 ) ;
F_4 ( L_29 ) ;
F_20 ( & V_29 ) ;
F_39 ( L_30 ) ;
}
void F_40 ( struct V_63 * V_32 ,
unsigned long V_19 )
{
unsigned long V_29 ;
char V_64 [ V_37 ] ;
if ( F_5 ( & V_32 -> V_2 ) )
return;
F_18 ( & V_32 -> V_2 , & V_29 ) ;
F_14 ( V_64 , sizeof( V_64 ) , V_32 -> type , V_19 ) ;
F_4 ( L_31 ,
V_64 , V_32 -> type -> V_39 ) ;
F_20 ( & V_29 ) ;
}
