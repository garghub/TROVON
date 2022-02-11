int F_1 ( int V_1 , void * V_2 , struct V_3 * V_4 )
{
int V_5 ;
if ( V_1 < 0 || V_1 >= V_6 )
return - V_7 ;
if ( V_8 [ V_1 ] . V_9 != - 1 && V_1 < 38 ) {
memcpy ( ( void * ) V_4 + V_8 [ V_1 ] . V_9 , V_2 ,
V_8 [ V_1 ] . V_10 ) ;
} else if ( V_11 && V_8 [ V_1 ] . V_9 != - 1 && V_1 < 72 ) {
if ( ! ( V_4 -> V_12 & V_13 ) )
return 0 ;
if ( V_1 == 70 ) {
memcpy ( ( void * ) & V_11 -> V_14 . V_15 . V_16 , V_2 ,
V_8 [ V_1 ] . V_10 ) ;
goto V_17;
} else if ( V_1 == 71 ) {
goto V_17;
}
V_5 = V_8 [ V_1 ] . V_9 ;
memcpy ( ( void * ) & V_11 -> V_14 . V_15 . V_18 [ V_5 ] , V_2 ,
V_8 [ V_1 ] . V_10 ) ;
V_17:
F_2 ( V_11 ) ;
}
return 0 ;
}
char * F_3 ( int V_1 , void * V_2 , struct V_3 * V_4 )
{
int V_5 ;
if ( V_1 >= V_6 || V_1 < 0 )
return NULL ;
if ( V_8 [ V_1 ] . V_9 != - 1 && V_1 < 38 ) {
memcpy ( V_2 , ( void * ) V_4 + V_8 [ V_1 ] . V_9 ,
V_8 [ V_1 ] . V_10 ) ;
} else if ( V_11 && V_8 [ V_1 ] . V_9 != - 1 && V_1 < 72 ) {
if ( ! ( V_4 -> V_12 & V_13 ) )
goto V_19;
F_4 ( V_11 ) ;
if ( V_1 == 70 ) {
memcpy ( V_2 , ( void * ) & V_11 -> V_14 . V_15 . V_16 ,
V_8 [ V_1 ] . V_10 ) ;
goto V_19;
} else if ( V_1 == 71 ) {
memset ( V_2 , 0 , V_8 [ V_1 ] . V_10 ) ;
goto V_19;
}
V_5 = V_8 [ V_1 ] . V_9 ;
memcpy ( V_2 , ( void * ) & V_11 -> V_14 . V_15 . V_18 [ V_5 ] ,
V_8 [ V_1 ] . V_10 ) ;
}
V_19:
return V_8 [ V_1 ] . V_20 ;
}
void F_5 ( void )
{
__asm__ __volatile__(
".globl breakinst\n\t"
".set\tnoreorder\n\t"
"nop\n"
"breakinst:\tbreak\n\t"
"nop\n\t"
".set\treorder");
}
static void F_6 ( void * V_21 )
{
F_7 ( F_8 () , NULL ) ;
}
void F_9 ( unsigned long V_22 )
{
F_10 () ;
F_11 ( F_6 , NULL , 0 ) ;
F_12 () ;
}
static int F_13 ( int V_23 )
{
struct V_24 * V_25 ;
for ( V_25 = V_24 ; V_25 -> V_23 && V_25 -> V_26 ; V_25 ++ )
if ( V_25 -> V_23 == V_23 )
return V_25 -> V_26 ;
return V_27 ;
}
void F_14 ( unsigned long * V_28 , struct V_29 * V_30 )
{
int V_31 ;
struct V_32 * V_33 = F_15 ( V_30 ) ;
unsigned long V_34 = ( unsigned long ) V_33 + V_35 - 32 ;
struct V_3 * V_4 = (struct V_3 * ) V_34 - 1 ;
#if ( V_36 == 32 )
T_1 * V_37 = ( T_1 * ) V_28 ;
#else
T_2 * V_37 = ( T_2 * ) V_28 ;
#endif
for ( V_31 = 0 ; V_31 < 16 ; V_31 ++ )
* ( V_37 ++ ) = V_4 -> V_4 [ V_31 ] ;
for ( V_31 = 16 ; V_31 < 24 ; V_31 ++ )
* ( V_37 ++ ) = V_4 -> V_4 [ V_31 ] ;
for ( V_31 = 24 ; V_31 < 28 ; V_31 ++ )
* ( V_37 ++ ) = 0 ;
for ( V_31 = 28 ; V_31 < 32 ; V_31 ++ )
* ( V_37 ++ ) = V_4 -> V_4 [ V_31 ] ;
* ( V_37 ++ ) = V_4 -> V_12 ;
* ( V_37 ++ ) = V_4 -> V_38 ;
* ( V_37 ++ ) = V_4 -> V_39 ;
* ( V_37 ++ ) = V_4 -> V_40 ;
* ( V_37 ++ ) = V_4 -> V_41 ;
* ( V_37 ++ ) = V_4 -> V_42 ;
}
void F_16 ( struct V_3 * V_4 , unsigned long V_43 )
{
V_4 -> V_42 = V_43 ;
}
static int F_17 ( struct V_44 * V_45 , unsigned long V_46 ,
void * V_37 )
{
struct V_47 * args = (struct V_47 * ) V_37 ;
struct V_3 * V_4 = args -> V_4 ;
int V_48 = ( V_4 -> V_41 & 0x7c ) >> 2 ;
if ( F_18 ( V_4 ) )
return V_49 ;
if ( F_19 ( & V_50 ) != - 1 )
F_7 ( F_20 () , V_4 ) ;
if ( F_21 ( V_48 , F_13 ( V_48 ) , V_46 , V_4 ) )
return V_49 ;
if ( F_19 ( & V_51 ) )
if ( ( V_48 == 9 ) && ( V_4 -> V_42 == ( unsigned long ) V_52 ) )
V_4 -> V_42 += 4 ;
F_10 () ;
F_22 () ;
return V_53 ;
}
int F_23 ( int V_46 , const char * V_54 ,
struct V_3 * V_4 , long V_55 , int V_48 , int V_56 )
{
struct V_47 args = {
. V_4 = V_4 ,
. V_54 = V_54 ,
. V_55 = V_55 ,
. V_57 = V_48 ,
. V_58 = V_56 ,
} ;
if ( ! V_59 )
return V_49 ;
return F_17 ( NULL , V_46 , & args ) ;
}
int F_24 ( int V_60 , int V_26 , int V_61 ,
char * V_62 , char * V_63 ,
struct V_3 * V_4 )
{
char * V_37 ;
unsigned long V_64 ;
switch ( V_62 [ 0 ] ) {
case 'c' :
V_37 = & V_62 [ 1 ] ;
if ( F_25 ( & V_37 , & V_64 ) )
V_4 -> V_42 = V_64 ;
return 0 ;
}
return - 1 ;
}
int F_26 ( void )
{
union V_65 V_66 = {
. V_67 = {
. V_68 = V_69 ,
. V_70 = V_71 ,
}
} ;
memcpy ( V_72 . V_73 , V_66 . V_74 , V_75 ) ;
F_27 ( & V_76 ) ;
return 0 ;
}
void F_28 ( void )
{
F_29 ( & V_76 ) ;
}
