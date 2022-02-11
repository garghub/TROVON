int F_1 ( void )
{
int V_1 ;
int V_2 ;
struct V_3 * V_4 ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
for ( V_1 = 0 ; V_1 < V_6 ; V_1 ++ ) {
V_5 [ V_1 ] =
F_2 ( sizeof( union V_7 ) *
F_3 () , V_8 ) ;
if ( ! V_5 [ V_1 ] )
goto V_9;
}
F_4 (tcd, i, j) {
F_5 ( & V_4 -> V_10 ) ;
V_4 -> V_11 = V_12 [ V_1 ] ;
V_4 -> V_13 = V_1 ;
V_4 -> V_14 = V_2 ;
}
for ( V_1 = 0 ; V_1 < F_3 () ; V_1 ++ )
for ( V_2 = 0 ; V_2 < 3 ; V_2 ++ ) {
V_15 [ V_1 ] [ V_2 ] =
F_2 ( V_16 ,
V_8 ) ;
if ( ! V_15 [ V_1 ] [ V_2 ] )
goto V_9;
}
return 0 ;
V_9:
F_6 () ;
F_7 ( L_1 ) ;
return - V_17 ;
}
void F_6 ( void )
{
int V_1 ;
int V_2 ;
for ( V_1 = 0 ; V_1 < F_3 () ; V_1 ++ )
for ( V_2 = 0 ; V_2 < 3 ; V_2 ++ ) {
F_8 ( V_15 [ V_1 ] [ V_2 ] ) ;
V_15 [ V_1 ] [ V_2 ] = NULL ;
}
for ( V_1 = 0 ; V_5 [ V_1 ] ; V_1 ++ ) {
F_8 ( V_5 [ V_1 ] ) ;
V_5 [ V_1 ] = NULL ;
}
}
void F_9 ( void )
{
F_10 ( & V_18 ) ;
}
void F_11 ( void )
{
F_12 ( & V_18 ) ;
}
void F_13 ( void )
{
F_14 ( & V_18 ) ;
}
void F_15 ( void )
{
F_16 ( & V_18 ) ;
}
enum V_19 F_17 ( void )
{
if ( F_18 () )
return V_20 ;
if ( F_19 () )
return V_21 ;
return V_22 ;
}
int F_20 ( struct V_3 * V_4 , int V_23 )
__acquires( &tcd->tc_lock
void F_21 ( struct V_3 * V_4 , int V_23 )
__releases( &tcd->tcd_lock
void
F_22 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
unsigned long V_28 )
{
struct V_29 V_30 ;
F_23 ( & V_30 ) ;
V_25 -> V_31 = V_27 -> V_32 ;
V_25 -> V_33 = V_27 -> V_34 ;
V_25 -> V_35 = F_24 () ;
V_25 -> V_36 = F_17 () ;
V_25 -> V_37 = ( V_38 ) V_30 . V_39 ;
V_25 -> V_40 = V_30 . V_41 / V_42 ;
V_25 -> V_43 = V_28 ;
V_25 -> V_44 = V_45 -> V_46 ;
V_25 -> V_47 = V_27 -> V_48 ;
V_25 -> V_49 = 0 ;
}
static char *
F_25 ( struct V_24 * V_50 )
{
switch ( V_50 -> V_31 ) {
case V_51 :
case V_52 :
return L_2 ;
default:
return L_3 ;
}
}
static char *
F_26 ( struct V_24 * V_50 )
{
switch ( V_50 -> V_31 ) {
case V_51 :
case V_52 :
return L_4 ;
default:
return L_5 ;
}
}
void F_27 ( struct V_24 * V_50 , int V_53 ,
const char * V_54 , int V_55 , const char * V_56 ,
const char * V_57 )
{
char * V_58 = L_5 , * V_59 = NULL ;
if ( V_53 & V_60 ) {
V_58 = F_25 ( V_50 ) ;
V_59 = V_61 ;
} else if ( V_53 & V_62 ) {
V_58 = F_25 ( V_50 ) ;
V_59 = V_63 ;
} else if ( V_53 & V_64 ) {
V_58 = F_26 ( V_50 ) ;
V_59 = V_65 ;
} else if ( V_53 & ( V_66 | V_67 ) ) {
V_58 = F_26 ( V_50 ) ;
V_59 = V_68 ;
}
if ( V_53 & V_66 ) {
F_28 ( L_6 , V_59 , V_58 , V_55 , V_54 ) ;
} else {
F_28 ( L_7 , V_59 , V_58 ,
V_50 -> V_44 , V_50 -> V_49 , V_56 ,
V_50 -> V_47 , V_57 , V_55 , V_54 ) ;
}
}
int F_29 ( void )
{
int V_69 = ( V_70 >> ( 20 - V_71 ) ) ;
return F_30 ( 512 , ( V_69 * 80 ) / 100 ) ;
}
