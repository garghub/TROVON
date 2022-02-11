static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
char V_6 [ 24 ] = { 0 } ;
char V_7 [ 32 ] = { 0 } ;
T_1 V_8 ;
T_1 V_9 [ 2 ] = { 0 } ;
T_1 V_10 ;
T_1 V_11 ;
int V_12 ;
V_12 = F_3 ( V_4 -> V_13 + 5 , V_14 ,
V_6 , sizeof( V_6 ) ) ;
if ( V_12 < 0 )
goto V_15;
V_12 = F_3 ( V_2 -> V_5 -> V_16 , V_17 ,
V_7 , sizeof( V_7 ) ) ;
if ( V_12 < 0 )
goto V_15;
V_12 = F_4 ( V_2 -> V_5 , V_18 ,
& V_8 ) ;
if ( V_12 < 0 )
goto V_15;
V_12 = F_4 ( V_2 -> V_5 , V_19 ,
& V_10 ) ;
if ( V_12 < 0 )
goto V_15;
V_12 = F_5 ( V_2 -> V_5 , V_20 ,
V_9 , sizeof( V_9 ) ) ;
if ( V_12 < 0 )
goto V_15;
V_12 = F_4 ( V_2 -> V_5 , V_21 ,
& V_11 ) ;
if ( V_12 < 0 )
goto V_15;
V_2 -> V_11 = V_11 ;
strcpy ( V_2 -> V_22 -> V_23 , L_1 ) ;
strcpy ( V_2 -> V_22 -> V_24 , V_7 ) ;
strcpy ( V_2 -> V_22 -> V_25 , V_7 ) ;
snprintf ( V_2 -> V_22 -> V_26 , sizeof( V_2 -> V_22 -> V_26 ) ,
L_2 ,
V_6 , V_7 , V_8 , V_10 ,
V_9 [ 0 ] , V_9 [ 1 ] , F_6 ( & V_2 -> V_5 -> V_27 ) ,
100 << V_4 -> V_28 ) ;
V_15:
return V_12 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_5 ) ;
F_10 ( V_2 -> V_29 ) ;
F_11 ( & V_2 -> V_30 ) ;
F_10 ( V_2 ) ;
}
static void
F_12 ( struct V_31 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_32 ;
F_13 ( & V_33 ) ;
F_14 ( V_2 -> V_34 , V_35 ) ;
F_15 ( & V_33 ) ;
F_7 ( V_22 -> V_32 ) ;
}
static const struct V_36 *
F_16 ( struct V_37 * V_5 )
{
char V_38 [ 24 ] = { 0 } ;
if ( F_3 ( V_5 -> V_16 , V_17 , V_38 , sizeof( V_38 ) ) < 0 )
return NULL ;
if ( strcmp ( V_38 , L_3 ) == 0 )
return & V_39 ;
else
return & V_40 ;
}
static bool
F_17 ( struct V_37 * V_5 )
{
char V_38 [ 28 ] = { 0 } ;
if ( F_3 ( V_5 -> V_16 , V_17 , V_38 , sizeof( V_38 ) ) < 0 )
return false ;
return strncmp ( V_38 , L_4 , 24 ) != 0 ;
}
static void
F_18 ( struct V_41 * V_42 )
{
struct V_1 * V_2 =
F_19 ( V_42 , struct V_1 , V_43 . V_42 ) ;
unsigned int V_34 ;
int V_12 ;
if ( V_2 -> V_44 )
return;
F_13 ( & V_33 ) ;
for ( V_34 = 0 ; V_34 < V_45 ; V_34 ++ ) {
if ( ! F_20 ( V_34 , V_35 ) && V_46 [ V_34 ] )
break;
}
if ( V_34 >= V_45 ) {
F_15 ( & V_33 ) ;
return;
}
V_12 = F_21 ( & V_2 -> V_5 -> V_27 , V_47 [ V_34 ] ,
V_48 [ V_34 ] , V_49 , 0 , & V_2 -> V_22 ) ;
if ( V_12 < 0 ) {
F_15 ( & V_33 ) ;
return;
}
V_12 = F_1 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
if ( V_2 -> V_50 == & V_51 ) {
if ( V_2 -> V_52 -> V_53 == V_54 )
V_12 = F_22 ( V_2 , true ) ;
else
V_12 = F_22 ( V_2 , false ) ;
} else {
V_12 = F_23 ( V_2 ) ;
}
if ( V_12 < 0 )
goto error;
V_12 = F_24 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
F_25 ( V_2 ) ;
if ( V_2 -> V_55 > 0 || V_2 -> V_56 > 0 ) {
V_12 = F_26 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
}
V_12 = F_27 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_28 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_29 ( V_2 -> V_22 ) ;
if ( V_12 < 0 )
goto error;
F_30 ( V_34 , V_35 ) ;
F_15 ( & V_33 ) ;
V_2 -> V_22 -> V_57 = F_12 ;
V_2 -> V_22 -> V_32 = V_2 ;
V_2 -> V_44 = true ;
return;
error:
F_15 ( & V_33 ) ;
F_8 ( V_2 ) ;
F_31 ( V_2 -> V_22 ) ;
F_32 ( & V_2 -> V_5 -> V_27 ,
L_5 , V_12 ) ;
}
static int
F_33 ( struct V_37 * V_5 , const struct V_58 * V_52 )
{
struct V_1 * V_2 ;
const struct V_36 * V_50 ;
if ( V_52 -> V_59 == V_60 &&
V_52 -> V_53 == V_61 )
V_50 = F_16 ( V_5 ) ;
else if ( V_52 -> V_59 == V_62 &&
V_52 -> V_53 == V_63 &&
! F_17 ( V_5 ) )
V_50 = NULL ;
else
V_50 = ( const struct V_36 * ) V_52 -> V_64 ;
if ( V_50 == NULL ) {
if ( V_52 -> V_59 == V_62 ||
V_52 -> V_59 == V_65 )
return F_34 ( V_5 ) ;
else
return - V_66 ;
}
V_2 = F_35 ( sizeof( struct V_1 ) , V_67 ) ;
if ( V_2 == NULL )
return - V_68 ;
V_2 -> V_5 = F_36 ( V_5 ) ;
V_2 -> V_52 = V_52 ;
V_2 -> V_50 = V_50 ;
F_37 ( & V_5 -> V_27 , V_2 ) ;
F_38 ( & V_2 -> V_30 ) ;
F_39 ( & V_2 -> V_69 ) ;
F_40 ( & V_2 -> V_70 ) ;
F_41 ( & V_2 -> V_43 , F_18 ) ;
if ( V_52 -> V_59 != V_62 ||
( V_52 -> V_53 != V_54 &&
V_52 -> V_53 != V_71 ) ) {
F_42 ( V_5 , & V_2 -> V_43 ) ;
} else {
F_43 ( F_2 ( V_2 -> V_5 ) -> V_22 ,
false , true ) ;
}
return 0 ;
}
static void
F_44 ( struct V_37 * V_5 )
{
struct V_1 * V_2 = F_45 ( & V_5 -> V_27 ) ;
if ( V_2 == NULL )
return;
if ( ! V_2 -> V_44 )
F_42 ( V_5 , & V_2 -> V_43 ) ;
else
F_46 ( V_2 -> V_5 ) ;
}
static void F_47 ( struct V_37 * V_5 )
{
struct V_1 * V_2 = F_45 ( & V_5 -> V_27 ) ;
if ( V_2 == NULL )
return;
F_48 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_44 ) {
F_49 ( V_2 -> V_22 ) ;
} else {
F_7 ( V_2 ) ;
}
}
static int T_2
F_50 ( void )
{
return F_51 ( & V_72 . V_23 ) ;
}
static void T_3
F_52 ( void )
{
F_53 ( & V_72 . V_23 ) ;
}
