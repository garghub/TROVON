static void F_1 ( unsigned V_1 , struct V_2 * V_3 )
{
V_3 -> V_4 ( V_1 , V_3 ) ;
}
void F_2 ( void )
{
unsigned V_1 ;
V_5 = F_3 () ;
V_6 = 1000000000UL / V_5 ;
for ( V_1 = 0 ; V_1 < V_7 ; ++ V_1 )
F_4 ( V_8 ,
V_1 ,
( V_9 ) & V_10 ,
NULL ,
& F_1 ,
V_11 | V_12 ) ;
}
void F_5 ( unsigned V_1 , struct V_13 * V_14 )
{
struct V_15 * V_16 = F_6 () ;
struct V_17 * V_18 , * V_19 ;
struct V_20 * V_21 , * V_22 ;
struct V_23 * V_24 ;
int V_25 , V_26 = - 1 ;
V_25 = ( V_14 == NULL || V_1 == V_27 || V_1 == V_28 ) ;
V_18 = V_29 ;
V_24 = & V_18 -> V_30 [ V_1 ] ;
if ( F_7 ( F_8 ( V_31 , & V_24 -> V_32 ) ) )
V_21 = & V_18 -> V_33 ;
else {
V_21 = V_34 . V_35 ;
V_19 = F_9 ( V_21 , struct V_17 , V_33 ) ;
V_24 = & V_19 -> V_30 [ V_1 ] ;
if ( F_10 ( F_8 ( V_36 , & V_24 -> V_32 ) ) ) {
if ( ! V_25 && V_24 -> V_37 != NULL )
V_24 -> V_37 ( V_1 , F_11 ( V_1 ) ) ;
if ( F_8 ( V_38 , & V_16 -> V_39 ) )
V_26 = F_12 ( V_40 ,
& V_16 -> V_39 ) ;
F_13 ( V_19 , V_1 ) ;
goto V_41;
}
}
V_22 = V_21 ;
while ( V_22 != & V_34 ) {
V_19 = F_9 ( V_22 , struct V_17 , V_33 ) ;
V_24 = & V_19 -> V_30 [ V_1 ] ;
if ( F_8 ( V_42 , & V_24 -> V_32 ) ) {
F_14 ( V_19 , V_1 ) ;
if ( ! V_25 && V_24 -> V_37 != NULL ) {
V_24 -> V_37 ( V_1 , F_11 ( V_1 ) ) ;
V_25 = 1 ;
}
}
if ( ! F_8 ( V_43 , & V_24 -> V_32 ) )
break;
V_22 = V_19 -> V_33 . V_35 ;
}
if ( F_8 ( V_38 , & V_16 -> V_39 ) )
V_26 = F_12 ( V_40 , & V_16 -> V_39 ) ;
if ( F_8 ( V_44 , & V_18 -> V_45 ) &&
! F_15 ( F_16 () ) )
goto V_41;
F_17 ( V_21 ) ;
V_41:
if ( ! V_26 )
F_18 ( V_40 , & V_16 -> V_39 ) ;
}
void F_19 ( struct V_17 * V_46 , unsigned V_1 )
{
struct V_2 * V_3 = F_11 ( V_1 ) ;
int V_47 = F_20 ( V_1 ) ;
V_3 -> V_48 = 0 ;
if ( V_46 != & V_49 &&
F_21 ( & V_50 [ V_47 ] ) == 1 )
F_22 ( V_47 , & V_51 ) ;
}
void F_23 ( struct V_17 * V_46 , unsigned V_1 )
{
int V_47 = F_20 ( V_1 ) ;
if ( V_46 != & V_49 &&
F_24 ( & V_50 [ V_47 ] ) )
F_18 ( V_47 , & V_51 ) ;
}
T_1 int F_25 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
void (* F_26)( void );
int V_52 ;
F_27 ( F_28 () ) ;
F_26 = ( F_29 ( F_26 ) ) V_53 ;
F_26 () ;
if ( ! F_30 ( V_54 , V_14 -> V_55 ) ||
! F_31 ( V_56 ) )
return 0 ;
V_52 = F_32 ( V_56 , V_14 ) ;
F_33 () ;
if ( V_54 -> V_57 & V_58 ) {
V_54 -> V_57 &= ~ V_58 ;
F_32 ( V_59 , V_14 ) ;
}
if ( ! V_60 )
V_52 = - 1 ;
else {
V_16 = F_6 () ;
if ( F_15 ( V_16 ) )
F_34 () ;
}
F_35 () ;
return - V_52 ;
}
static void F_36 ( void )
{
}
int F_37 ( struct V_61 * V_62 )
{
V_62 -> V_63 = F_38 () ;
V_62 -> V_64 = F_39 () ;
V_62 -> V_65 = V_66 ;
V_62 -> V_67 = V_5 ;
V_62 -> V_68 = V_5 ;
return 0 ;
}
int F_40 ( unsigned V_1 )
{
unsigned long V_45 ;
#ifdef F_41
if ( V_1 >= V_69 ||
( F_42 ( V_1 )
&& ! F_8 ( V_1 - V_70 , & V_71 ) ) )
return - V_72 ;
#endif
V_45 = F_43 () ;
F_5 ( V_1 , NULL ) ;
F_44 ( V_45 ) ;
return 1 ;
}
T_1 void F_45 ( void )
{
void (* F_46)( void ) = ( void ( * ) ( void ) ) V_53 ;
struct V_15 * V_16 ;
unsigned long V_45 ;
F_47 ( F_48 () ) ;
V_45 = F_43 () ;
if ( F_46 )
F_46 () ;
F_49 ( V_73 ) ;
V_16 = F_6 () ;
if ( F_15 ( V_16 ) )
F_34 () ;
F_44 ( V_45 ) ;
}
void F_50 ( void )
{
if ( V_60 &&
F_8 ( V_38 , & F_51 ( V_39 ) ) )
return;
F_52 () ;
}
void F_53 ( void )
{
F_54 ( V_51 ) ;
F_22 ( V_40 , & F_51 ( V_39 ) ) ;
}
void F_55 ( void )
{
F_18 ( V_40 , & F_51 ( V_39 ) ) ;
F_54 ( V_74 ) ;
}
void F_56 ( void )
{
unsigned long * V_16 , V_45 ;
V_45 = F_43 () ;
V_16 = & V_75 ;
F_22 ( V_40 , V_16 ) ;
F_44 ( V_45 ) ;
}
unsigned long F_57 ( void )
{
unsigned long * V_16 , V_45 ;
int V_76 ;
V_45 = F_43 () ;
V_16 = & V_75 ;
V_76 = F_12 ( V_40 , V_16 ) ;
F_44 ( V_45 ) ;
return V_76 ;
}
unsigned long F_58 ( void )
{
const unsigned long * V_16 ;
unsigned long V_45 ;
int V_76 ;
V_45 = F_59 () ;
V_16 = & V_75 ;
V_76 = F_8 ( V_40 , V_16 ) ;
F_60 ( V_45 ) ;
return V_76 ;
}
void F_61 ( void )
{
unsigned long * V_16 , V_45 ;
V_45 = F_43 () ;
V_16 = & V_75 ;
F_22 ( V_38 , V_16 ) ;
F_44 ( V_45 ) ;
}
void F_62 ( void )
{
unsigned long * V_16 , V_45 ;
V_45 = F_43 () ;
V_16 = & V_75 ;
F_18 ( V_38 , V_16 ) ;
F_44 ( V_45 ) ;
}
