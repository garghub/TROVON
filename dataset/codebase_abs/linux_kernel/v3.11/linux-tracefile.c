int F_1 ()
{
int V_1 ;
int V_2 ;
struct V_3 * V_4 ;
F_2 ( & V_5 ) ;
memset ( V_6 , 0 , sizeof( V_6 ) ) ;
for ( V_1 = 0 ; V_1 < V_7 ; V_1 ++ ) {
V_6 [ V_1 ] =
F_3 ( sizeof( union V_8 ) *
F_4 () , V_9 ) ;
if ( V_6 [ V_1 ] == NULL )
goto V_10;
}
F_5 (tcd, i, j) {
F_6 ( & V_4 -> V_11 ) ;
V_4 -> V_12 = V_13 [ V_1 ] ;
V_4 -> V_14 = V_1 ;
V_4 -> V_15 = V_2 ;
}
for ( V_1 = 0 ; V_1 < F_4 () ; V_1 ++ )
for ( V_2 = 0 ; V_2 < 3 ; V_2 ++ ) {
V_16 [ V_1 ] [ V_2 ] =
F_3 ( V_17 ,
V_9 ) ;
if ( V_16 [ V_1 ] [ V_2 ] == NULL )
goto V_10;
}
return 0 ;
V_10:
F_7 () ;
F_8 ( V_18 L_1 ) ;
return - V_19 ;
}
void F_7 ()
{
int V_1 ;
int V_2 ;
for ( V_1 = 0 ; V_1 < F_4 () ; V_1 ++ )
for ( V_2 = 0 ; V_2 < 3 ; V_2 ++ )
if ( V_16 [ V_1 ] [ V_2 ] != NULL ) {
F_9 ( V_16 [ V_1 ] [ V_2 ] ) ;
V_16 [ V_1 ] [ V_2 ] = NULL ;
}
for ( V_1 = 0 ; V_6 [ V_1 ] != NULL ; V_1 ++ ) {
F_9 ( V_6 [ V_1 ] ) ;
V_6 [ V_1 ] = NULL ;
}
F_10 ( & V_5 ) ;
}
void F_11 ()
{
F_12 ( & V_5 ) ;
}
void F_13 ()
{
F_14 ( & V_5 ) ;
}
void F_15 ()
{
F_16 ( & V_5 ) ;
}
void F_17 ()
{
F_18 ( & V_5 ) ;
}
T_1 F_19 ()
{
if ( F_20 () )
return V_20 ;
else if ( F_21 () )
return V_21 ;
else
return V_22 ;
}
int F_22 ( struct V_3 * V_4 , int V_23 )
{
F_23 ( V_4 -> V_14 < V_7 ) ;
if ( V_4 -> V_14 == V_20 )
F_24 ( & V_4 -> V_11 , V_4 -> V_24 ) ;
else if ( V_4 -> V_14 == V_21 )
F_25 ( & V_4 -> V_11 ) ;
else if ( F_26 ( V_23 ) )
F_27 ( & V_4 -> V_11 ) ;
else
F_28 ( & V_4 -> V_11 ) ;
return 1 ;
}
void F_29 ( struct V_3 * V_4 , int V_23 )
{
F_23 ( V_4 -> V_14 < V_7 ) ;
if ( V_4 -> V_14 == V_20 )
F_30 ( & V_4 -> V_11 , V_4 -> V_24 ) ;
else if ( V_4 -> V_14 == V_21 )
F_31 ( & V_4 -> V_11 ) ;
else if ( F_26 ( V_23 ) )
F_32 ( & V_4 -> V_11 ) ;
else
F_33 ( & V_4 -> V_11 ) ;
}
int F_34 ( struct V_3 * V_4 ,
struct V_25 * V_26 )
{
return V_4 -> V_15 == V_26 -> V_27 ;
}
void
F_35 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
unsigned long V_32 )
{
struct V_33 V_34 ;
F_36 ( & V_34 ) ;
V_29 -> V_35 = V_31 -> V_36 ;
V_29 -> V_37 = V_31 -> V_38 ;
V_29 -> V_39 = F_37 () ;
V_29 -> V_40 = F_19 () ;
V_29 -> V_41 = ( V_42 ) V_34 . V_43 ;
V_29 -> V_44 = V_34 . V_45 ;
V_29 -> V_46 = V_32 ;
V_29 -> V_47 = V_48 -> V_49 ;
V_29 -> V_50 = V_31 -> V_51 ;
V_29 -> V_52 = 0 ;
return;
}
static char *
F_38 ( struct V_28 * V_53 )
{
switch ( V_53 -> V_35 ) {
case V_54 :
case V_55 :
return L_2 ;
default:
return L_3 ;
}
}
static char *
F_39 ( struct V_28 * V_53 )
{
switch ( V_53 -> V_35 ) {
case V_54 :
case V_55 :
return L_4 ;
default:
return L_5 ;
}
}
void F_40 ( struct V_28 * V_53 , int V_56 ,
const char * V_57 , int V_58 , const char * V_59 ,
const char * V_60 )
{
char * V_61 = L_5 , * V_62 = NULL ;
if ( ( V_56 & V_63 ) != 0 ) {
V_61 = F_38 ( V_53 ) ;
V_62 = V_64 ;
} else if ( ( V_56 & V_65 ) != 0 ) {
V_61 = F_38 ( V_53 ) ;
V_62 = V_18 ;
} else if ( ( V_56 & V_66 ) != 0 ) {
V_61 = F_39 ( V_53 ) ;
V_62 = V_67 ;
} else if ( ( V_56 & ( V_68 | V_69 ) ) != 0 ) {
V_61 = F_39 ( V_53 ) ;
V_62 = V_70 ;
}
if ( ( V_56 & V_68 ) != 0 ) {
F_8 ( L_6 , V_62 , V_61 , V_58 , V_57 ) ;
} else {
F_8 ( L_7 , V_62 , V_61 ,
V_53 -> V_47 , V_53 -> V_52 , V_59 , V_53 -> V_50 ,
V_60 , V_58 , V_57 ) ;
}
return;
}
int F_41 ( void )
{
int V_71 = ( V_72 >> ( 20 - V_73 ) ) ;
return F_42 ( 512 , ( V_71 * 80 ) / 100 ) ;
}
