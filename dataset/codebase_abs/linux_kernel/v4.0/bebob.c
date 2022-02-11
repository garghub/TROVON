static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
char V_7 [ 24 ] = { 0 } ;
char V_8 [ 32 ] = { 0 } ;
T_1 V_9 ;
T_1 V_10 [ 2 ] = { 0 } ;
T_1 V_11 ;
int V_12 ;
V_12 = F_3 ( V_5 -> V_13 + 5 , V_14 ,
V_7 , sizeof( V_7 ) ) ;
if ( V_12 < 0 )
goto V_15;
V_12 = F_3 ( V_2 -> V_6 -> V_16 , V_17 ,
V_8 , sizeof( V_8 ) ) ;
if ( V_12 < 0 )
goto V_15;
V_12 = F_4 ( V_2 -> V_6 , V_18 ,
& V_9 ) ;
if ( V_12 < 0 )
goto V_15;
V_12 = F_4 ( V_2 -> V_6 , V_19 ,
& V_11 ) ;
if ( V_12 < 0 )
goto V_15;
V_12 = F_5 ( V_2 -> V_6 , V_20 ,
V_10 , sizeof( V_10 ) ) ;
if ( V_12 < 0 )
goto V_15;
strcpy ( V_2 -> V_21 -> V_22 , L_1 ) ;
strcpy ( V_2 -> V_21 -> V_23 , V_8 ) ;
strcpy ( V_2 -> V_21 -> V_24 , V_8 ) ;
snprintf ( V_2 -> V_21 -> V_25 , sizeof( V_2 -> V_21 -> V_25 ) ,
L_2 ,
V_7 , V_8 , V_9 , V_11 ,
V_10 [ 0 ] , V_10 [ 1 ] , F_6 ( & V_2 -> V_6 -> V_26 ) ,
100 << V_5 -> V_27 ) ;
V_15:
return V_12 ;
}
static void
F_7 ( struct V_28 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_29 ;
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_6 ) ;
F_10 ( V_2 -> V_30 ) ;
if ( V_2 -> V_31 >= 0 ) {
F_11 ( & V_32 ) ;
F_12 ( V_2 -> V_31 , V_33 ) ;
F_13 ( & V_32 ) ;
}
F_14 ( & V_2 -> V_34 ) ;
}
static const struct V_35 *
F_15 ( struct V_36 * V_6 )
{
char V_37 [ 24 ] = { 0 } ;
if ( F_3 ( V_6 -> V_16 , V_17 , V_37 , sizeof( V_37 ) ) < 0 )
return NULL ;
if ( strcmp ( V_37 , L_3 ) == 0 )
return & V_38 ;
else
return & V_39 ;
}
static bool
F_16 ( struct V_36 * V_6 )
{
char V_37 [ 24 ] = { 0 } ;
if ( F_3 ( V_6 -> V_16 , V_17 , V_37 , sizeof( V_37 ) ) < 0 )
return false ;
return strncmp ( V_37 , L_4 , 15 ) != 0 ;
}
static int
F_17 ( struct V_36 * V_6 ,
const struct V_40 * V_41 )
{
struct V_28 * V_21 ;
struct V_1 * V_2 ;
const struct V_35 * V_42 ;
unsigned int V_31 ;
int V_12 ;
F_11 ( & V_32 ) ;
for ( V_31 = 0 ; V_31 < V_43 ; V_31 ++ ) {
if ( ! F_18 ( V_31 , V_33 ) && V_44 [ V_31 ] )
break;
}
if ( V_31 >= V_43 ) {
V_12 = - V_45 ;
goto V_15;
}
if ( ( V_41 -> V_3 == V_46 ) &&
( V_41 -> V_47 == V_48 ) )
V_42 = F_15 ( V_6 ) ;
else if ( ( V_41 -> V_3 == V_49 ) &&
( V_41 -> V_47 == V_50 ) &&
! F_16 ( V_6 ) )
V_42 = NULL ;
else
V_42 = ( const struct V_35 * ) V_41 -> V_51 ;
if ( V_42 == NULL ) {
if ( ( V_41 -> V_3 == V_49 ) ||
( V_41 -> V_3 == V_52 ) )
V_12 = F_19 ( V_6 ) ;
else
V_12 = - V_53 ;
goto V_15;
}
V_12 = F_20 ( & V_6 -> V_26 , V_54 [ V_31 ] , V_55 [ V_31 ] ,
V_56 , sizeof( struct V_1 ) , & V_21 ) ;
if ( V_12 < 0 )
goto V_15;
V_2 = V_21 -> V_29 ;
V_2 -> V_31 = V_31 ;
F_21 ( V_31 , V_33 ) ;
V_21 -> V_57 = F_7 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_6 = F_22 ( V_6 ) ;
V_2 -> V_42 = V_42 ;
F_23 ( & V_2 -> V_34 ) ;
F_24 ( & V_2 -> V_58 ) ;
F_25 ( & V_2 -> V_59 ) ;
V_12 = F_1 ( V_2 , V_41 -> V_3 ) ;
if ( V_12 < 0 )
goto error;
if ( ( V_41 -> V_3 == V_49 ) &&
( V_41 -> V_47 == V_60 ) )
V_12 = F_26 ( V_2 , true ) ;
else if ( ( V_41 -> V_3 == V_49 ) &&
( V_41 -> V_47 == V_61 ) )
V_12 = F_26 ( V_2 , false ) ;
else
V_12 = F_27 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
F_28 ( V_2 ) ;
if ( ( V_2 -> V_62 > 0 ) ||
( V_2 -> V_63 > 0 ) ) {
V_12 = F_29 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
}
V_12 = F_30 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_31 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_32 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
if ( ! V_2 -> V_30 ) {
V_12 = F_33 ( V_21 ) ;
if ( V_12 < 0 ) {
F_8 ( V_2 ) ;
goto error;
}
} else {
V_2 -> V_64 = true ;
F_34 ( F_2 ( V_2 -> V_6 ) -> V_21 ,
false , true ) ;
}
F_35 ( & V_6 -> V_26 , V_2 ) ;
V_15:
F_13 ( & V_32 ) ;
return V_12 ;
error:
F_13 ( & V_32 ) ;
F_36 ( V_21 ) ;
return V_12 ;
}
static void
F_37 ( struct V_36 * V_6 )
{
struct V_1 * V_2 = F_38 ( & V_6 -> V_26 ) ;
if ( V_2 == NULL )
return;
F_39 ( V_2 -> V_6 ) ;
F_40 ( V_2 ) ;
if ( V_2 -> V_64 ) {
if ( F_33 ( V_2 -> V_21 ) < 0 ) {
F_8 ( V_2 ) ;
F_36 ( V_2 -> V_21 ) ;
}
V_2 -> V_64 = false ;
}
}
static void F_41 ( struct V_36 * V_6 )
{
struct V_1 * V_2 = F_38 ( & V_6 -> V_26 ) ;
if ( V_2 == NULL )
return;
if ( ! F_42 ( & V_2 -> V_65 ) )
F_43 ( & V_2 -> V_65 ) ;
F_44 ( V_2 -> V_21 ) ;
}
static int T_2
F_45 ( void )
{
return F_46 ( & V_66 . V_22 ) ;
}
static void T_3
F_47 ( void )
{
F_48 ( & V_66 . V_22 ) ;
}
