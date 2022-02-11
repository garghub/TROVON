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
F_7 ( V_17 L_1 ) ;
return - V_18 ;
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
F_10 ( & V_19 ) ;
}
void F_11 ( void )
{
F_12 ( & V_19 ) ;
}
void F_13 ( void )
{
F_14 ( & V_19 ) ;
}
void F_15 ( void )
{
F_16 ( & V_19 ) ;
}
enum V_20 F_17 ( void )
{
if ( F_18 () )
return V_21 ;
if ( F_19 () )
return V_22 ;
return V_23 ;
}
int F_20 ( struct V_3 * V_4 , int V_24 )
__acquires( &tcd->tc_lock
void F_21 ( struct V_3 * V_4 , int V_24 )
__releases( &tcd->tcd_lock
void
F_22 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
unsigned long V_29 )
{
struct V_30 V_31 ;
F_23 ( & V_31 ) ;
V_26 -> V_32 = V_28 -> V_33 ;
V_26 -> V_34 = V_28 -> V_35 ;
V_26 -> V_36 = F_24 () ;
V_26 -> V_37 = F_17 () ;
V_26 -> V_38 = ( V_39 ) V_31 . V_40 ;
V_26 -> V_41 = V_31 . V_42 / V_43 ;
V_26 -> V_44 = V_29 ;
V_26 -> V_45 = V_46 -> V_47 ;
V_26 -> V_48 = V_28 -> V_49 ;
V_26 -> V_50 = 0 ;
}
static char *
F_25 ( struct V_25 * V_51 )
{
switch ( V_51 -> V_32 ) {
case V_52 :
case V_53 :
return L_2 ;
default:
return L_3 ;
}
}
static char *
F_26 ( struct V_25 * V_51 )
{
switch ( V_51 -> V_32 ) {
case V_52 :
case V_53 :
return L_4 ;
default:
return L_5 ;
}
}
void F_27 ( struct V_25 * V_51 , int V_54 ,
const char * V_55 , int V_56 , const char * V_57 ,
const char * V_58 )
{
char * V_59 = L_5 , * V_60 = NULL ;
if ( ( V_54 & V_61 ) != 0 ) {
V_59 = F_25 ( V_51 ) ;
V_60 = V_62 ;
} else if ( ( V_54 & V_63 ) != 0 ) {
V_59 = F_25 ( V_51 ) ;
V_60 = V_17 ;
} else if ( ( V_54 & V_64 ) != 0 ) {
V_59 = F_26 ( V_51 ) ;
V_60 = V_65 ;
} else if ( ( V_54 & ( V_66 | V_67 ) ) != 0 ) {
V_59 = F_26 ( V_51 ) ;
V_60 = V_68 ;
}
if ( ( V_54 & V_66 ) != 0 ) {
F_7 ( L_6 , V_60 , V_59 , V_56 , V_55 ) ;
} else {
F_7 ( L_7 , V_60 , V_59 ,
V_51 -> V_45 , V_51 -> V_50 , V_57 , V_51 -> V_48 ,
V_58 , V_56 , V_55 ) ;
}
}
int F_28 ( void )
{
int V_69 = ( V_70 >> ( 20 - V_71 ) ) ;
return F_29 ( 512 , ( V_69 * 80 ) / 100 ) ;
}
