static bool F_1 ( struct V_1 * V_2 )
{
const char * const V_3 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 } ;
char V_4 [ 32 ] ;
unsigned int V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_8 ,
V_4 , sizeof( V_4 ) ) ;
if ( V_6 < 0 )
return false ;
for ( V_5 = 0 ; V_5 < F_3 ( V_3 ) ; V_5 ++ ) {
if ( strcmp ( V_3 [ V_5 ] , V_4 ) == 0 )
break;
}
return ( V_5 < F_3 ( V_3 ) ) ;
}
static int F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 -> V_2 ) ;
const struct V_13 * V_14 ;
char V_15 [ 24 ] ;
char V_4 [ 32 ] ;
const char * V_16 , * V_17 , * V_18 ;
T_1 V_19 ;
int V_6 ;
V_6 = F_2 ( V_12 -> V_20 + 5 , V_21 ,
V_15 , sizeof( V_15 ) ) ;
if ( V_6 < 0 )
goto V_22;
V_6 = F_2 ( V_10 -> V_2 -> V_7 , V_8 ,
V_4 , sizeof( V_4 ) ) ;
if ( V_6 < 0 )
goto V_22;
V_6 = F_6 ( V_10 -> V_2 , V_23 ,
V_24 , & V_19 , 4 , 0 ) ;
if ( V_6 < 0 )
goto V_22;
F_7 ( & V_19 ) ;
if ( V_10 -> V_25 -> V_26 == V_27 ||
V_10 -> V_25 -> V_26 == V_28 ) {
V_14 = ( const struct V_13 * ) V_10 -> V_25 -> V_29 ;
V_16 = V_14 -> V_30 ;
V_17 = V_14 -> V_31 ;
V_18 = V_14 -> V_32 ;
} else {
V_16 = L_7 ;
V_17 = V_15 ;
V_18 = V_4 ;
}
strcpy ( V_10 -> V_33 -> V_34 , V_16 ) ;
strcpy ( V_10 -> V_33 -> V_35 , V_18 ) ;
strcpy ( V_10 -> V_33 -> V_36 , V_18 ) ;
snprintf ( V_10 -> V_33 -> V_37 , sizeof( V_10 -> V_33 -> V_37 ) ,
L_8 ,
V_17 , V_18 , V_19 >> 20 , V_19 & 0xffff ,
V_12 -> V_20 [ 3 ] , V_12 -> V_20 [ 4 ] ,
F_8 ( & V_10 -> V_2 -> V_38 ) , 100 << V_12 -> V_39 ) ;
V_22:
return V_6 ;
}
static void F_9 ( struct V_9 * V_10 )
{
unsigned int V_5 ;
F_10 ( V_10 , & V_10 -> V_40 ) ;
if ( V_10 -> V_41 )
F_10 ( V_10 , & V_10 -> V_42 ) ;
F_11 ( V_10 -> V_2 ) ;
for ( V_5 = 0 ; V_5 < V_43 ; V_5 ++ ) {
F_12 ( V_10 -> V_44 [ V_5 ] ) ;
F_12 ( V_10 -> V_45 [ V_5 ] ) ;
}
F_12 ( V_10 -> V_46 ) ;
F_13 ( & V_10 -> V_47 ) ;
}
static void F_14 ( struct V_48 * V_33 )
{
F_9 ( V_33 -> V_49 ) ;
}
static int F_15 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 -> V_2 ) ;
struct V_50 V_51 ;
int V_52 , V_53 ;
int V_15 , V_4 ;
if ( V_10 -> V_25 -> V_26 == V_27 )
return F_16 ( V_10 , false ) ;
if ( V_10 -> V_25 -> V_26 == V_28 )
return F_16 ( V_10 , true ) ;
if ( V_10 -> V_25 -> V_26 == V_54 ) {
V_10 -> V_55 = 0 ;
V_10 -> V_56 = 0 ;
V_10 -> V_41 = false ;
return F_17 ( V_10 ) ;
}
if ( V_10 -> V_25 -> V_26 == V_57 ) {
V_10 -> V_55 ++ ;
V_10 -> V_56 ++ ;
return 0 ;
}
V_15 = V_4 = 0 ;
F_18 ( & V_51 , V_12 -> V_20 + 5 ) ;
while ( F_19 ( & V_51 , & V_52 , & V_53 ) ) {
if ( V_52 == V_21 )
V_15 = V_53 ;
else if ( V_52 == V_8 )
V_4 = V_53 ;
}
if ( V_15 == V_58 && V_4 == V_59 )
V_10 -> V_60 = true ;
return 0 ;
}
static void F_20 ( struct V_61 * V_62 )
{
struct V_9 * V_10 = F_21 ( V_62 , struct V_9 , V_63 . V_62 ) ;
int V_6 ;
if ( V_10 -> V_64 )
return;
V_6 = F_22 ( & V_10 -> V_2 -> V_38 , - 1 , NULL , V_65 , 0 ,
& V_10 -> V_33 ) ;
if ( V_6 < 0 )
return;
V_6 = F_4 ( V_10 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_15 ( V_10 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_23 ( V_10 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_24 ( V_10 , & V_10 -> V_40 ) ;
if ( V_6 < 0 )
goto error;
if ( V_10 -> V_41 ) {
V_6 = F_24 ( V_10 , & V_10 -> V_42 ) ;
if ( V_6 < 0 )
goto error;
}
V_6 = F_25 ( V_10 ) ;
if ( V_6 < 0 )
goto error;
F_26 ( V_10 ) ;
V_6 = F_27 ( V_10 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_28 ( V_10 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_29 ( V_10 -> V_33 ) ;
if ( V_6 < 0 )
goto error;
V_10 -> V_33 -> V_66 = F_14 ;
V_10 -> V_33 -> V_49 = V_10 ;
V_10 -> V_64 = true ;
return;
error:
F_10 ( V_10 , & V_10 -> V_40 ) ;
if ( V_10 -> V_41 )
F_10 ( V_10 , & V_10 -> V_42 ) ;
F_30 ( V_10 -> V_33 ) ;
F_31 ( & V_10 -> V_2 -> V_38 ,
L_9 , V_6 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_67 * V_25 )
{
struct V_9 * V_10 ;
if ( V_25 -> V_26 == V_58 && ! F_1 ( V_2 ) )
return - V_68 ;
V_10 = F_33 ( sizeof( struct V_9 ) , V_69 ) ;
if ( V_10 == NULL )
return - V_70 ;
V_10 -> V_25 = V_25 ;
V_10 -> V_2 = F_34 ( V_2 ) ;
F_35 ( & V_2 -> V_38 , V_10 ) ;
F_36 ( & V_10 -> V_47 ) ;
F_37 ( & V_10 -> V_71 ) ;
F_38 ( & V_10 -> V_72 ) ;
F_39 ( & V_10 -> V_63 , F_20 ) ;
F_40 ( V_2 , & V_10 -> V_63 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_42 ( & V_2 -> V_38 ) ;
if ( ! V_10 -> V_64 )
F_40 ( V_2 , & V_10 -> V_63 ) ;
F_43 ( V_10 -> V_2 ) ;
if ( V_10 -> V_64 ) {
F_44 ( & V_10 -> V_47 ) ;
F_45 ( V_10 , & V_10 -> V_40 ) ;
if ( V_10 -> V_41 )
F_45 ( V_10 , & V_10 -> V_42 ) ;
F_46 ( & V_10 -> V_47 ) ;
if ( V_10 -> V_25 -> V_26 == V_54 )
F_47 ( V_10 ) ;
}
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_42 ( & V_2 -> V_38 ) ;
F_49 ( & V_10 -> V_63 ) ;
if ( V_10 -> V_64 ) {
F_50 ( V_10 -> V_33 ) ;
} else {
F_9 ( V_10 ) ;
}
}
static int T_2 F_51 ( void )
{
return F_52 ( & V_73 . V_34 ) ;
}
static void T_3 F_53 ( void )
{
F_54 ( & V_73 . V_34 ) ;
}
