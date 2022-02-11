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
if ( V_5 [ V_1 ] == NULL )
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
if ( V_15 [ V_1 ] [ V_2 ] == NULL )
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
for ( V_1 = 0 ; V_5 [ V_1 ] != NULL ; V_1 ++ ) {
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
T_1 F_17 ( void )
{
if ( F_18 () )
return V_20 ;
else if ( F_19 () )
return V_21 ;
else
return V_22 ;
}
int F_20 ( struct V_3 * V_4 , int V_23 )
__acquires( &tcd->tc_lock
void F_21 ( struct V_3 * V_4 , int V_23 )
__releases( &tcd->tcd_lock
int F_22 ( struct V_3 * V_4 ,
struct V_24 * V_25 )
{
return V_4 -> V_14 == V_25 -> V_26 ;
}
void
F_23 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
unsigned long V_31 )
{
struct V_32 V_33 ;
F_24 ( & V_33 ) ;
V_28 -> V_34 = V_30 -> V_35 ;
V_28 -> V_36 = V_30 -> V_37 ;
V_28 -> V_38 = F_25 () ;
V_28 -> V_39 = F_17 () ;
V_28 -> V_40 = ( V_41 ) V_33 . V_42 ;
V_28 -> V_43 = V_33 . V_44 ;
V_28 -> V_45 = V_31 ;
V_28 -> V_46 = V_47 -> V_48 ;
V_28 -> V_49 = V_30 -> V_50 ;
V_28 -> V_51 = 0 ;
return;
}
static char *
F_26 ( struct V_27 * V_52 )
{
switch ( V_52 -> V_34 ) {
case V_53 :
case V_54 :
return L_2 ;
default:
return L_3 ;
}
}
static char *
F_27 ( struct V_27 * V_52 )
{
switch ( V_52 -> V_34 ) {
case V_53 :
case V_54 :
return L_4 ;
default:
return L_5 ;
}
}
void F_28 ( struct V_27 * V_52 , int V_55 ,
const char * V_56 , int V_57 , const char * V_58 ,
const char * V_59 )
{
char * V_60 = L_5 , * V_61 = NULL ;
if ( ( V_55 & V_62 ) != 0 ) {
V_60 = F_26 ( V_52 ) ;
V_61 = V_63 ;
} else if ( ( V_55 & V_64 ) != 0 ) {
V_60 = F_26 ( V_52 ) ;
V_61 = V_17 ;
} else if ( ( V_55 & V_65 ) != 0 ) {
V_60 = F_27 ( V_52 ) ;
V_61 = V_66 ;
} else if ( ( V_55 & ( V_67 | V_68 ) ) != 0 ) {
V_60 = F_27 ( V_52 ) ;
V_61 = V_69 ;
}
if ( ( V_55 & V_67 ) != 0 ) {
F_7 ( L_6 , V_61 , V_60 , V_57 , V_56 ) ;
} else {
F_7 ( L_7 , V_61 , V_60 ,
V_52 -> V_46 , V_52 -> V_51 , V_58 , V_52 -> V_49 ,
V_59 , V_57 , V_56 ) ;
}
return;
}
int F_29 ( void )
{
int V_70 = ( V_71 >> ( 20 - V_72 ) ) ;
return F_30 ( 512 , ( V_70 * 80 ) / 100 ) ;
}
