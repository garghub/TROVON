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
if ( V_2 -> V_30 >= 0 ) {
F_8 ( & V_31 ) ;
F_9 ( V_2 -> V_30 , V_32 ) ;
F_10 ( & V_31 ) ;
}
F_11 ( & V_2 -> V_33 ) ;
}
static const struct V_34 *
F_12 ( struct V_35 * V_6 )
{
char V_36 [ 24 ] = { 0 } ;
if ( F_3 ( V_6 -> V_16 , V_17 , V_36 , sizeof( V_36 ) ) < 0 )
return NULL ;
if ( strcmp ( V_36 , L_3 ) == 0 )
return & V_37 ;
else
return & V_38 ;
}
static bool
F_13 ( struct V_35 * V_6 )
{
char V_36 [ 24 ] = { 0 } ;
if ( F_3 ( V_6 -> V_16 , V_17 , V_36 , sizeof( V_36 ) ) < 0 )
return false ;
return strncmp ( V_36 , L_4 , 15 ) != 0 ;
}
static int
F_14 ( struct V_35 * V_6 ,
const struct V_39 * V_40 )
{
struct V_28 * V_21 ;
struct V_1 * V_2 ;
const struct V_34 * V_41 ;
unsigned int V_30 ;
int V_12 ;
F_8 ( & V_31 ) ;
for ( V_30 = 0 ; V_30 < V_42 ; V_30 ++ ) {
if ( ! F_15 ( V_30 , V_32 ) && V_43 [ V_30 ] )
break;
}
if ( V_30 >= V_42 ) {
V_12 = - V_44 ;
goto V_15;
}
if ( ( V_40 -> V_3 == V_45 ) &&
( V_40 -> V_46 == V_47 ) )
V_41 = F_12 ( V_6 ) ;
else if ( ( V_40 -> V_3 == V_48 ) &&
( V_40 -> V_46 == V_49 ) &&
! F_13 ( V_6 ) )
V_41 = NULL ;
else
V_41 = ( const struct V_34 * ) V_40 -> V_50 ;
if ( V_41 == NULL ) {
if ( ( V_40 -> V_3 == V_48 ) ||
( V_40 -> V_3 == V_51 ) )
V_12 = F_16 ( V_6 ) ;
else
V_12 = - V_52 ;
goto V_15;
}
V_12 = F_17 ( & V_6 -> V_26 , V_53 [ V_30 ] , V_54 [ V_30 ] ,
V_55 , sizeof( struct V_1 ) , & V_21 ) ;
if ( V_12 < 0 )
goto V_15;
V_2 = V_21 -> V_29 ;
V_2 -> V_30 = V_30 ;
F_18 ( V_30 , V_32 ) ;
V_21 -> V_56 = F_7 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_41 = V_41 ;
F_19 ( & V_2 -> V_33 ) ;
F_20 ( & V_2 -> V_57 ) ;
F_21 ( & V_2 -> V_58 ) ;
V_12 = F_1 ( V_2 , V_40 -> V_3 ) ;
if ( V_12 < 0 )
goto error;
if ( ( V_40 -> V_3 == V_48 ) &&
( V_40 -> V_46 == V_59 ) )
V_12 = F_22 ( V_2 , true ) ;
else if ( ( V_40 -> V_3 == V_48 ) &&
( V_40 -> V_46 == V_60 ) )
V_12 = F_22 ( V_2 , false ) ;
else
V_12 = F_23 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
F_24 ( V_2 ) ;
if ( ( V_2 -> V_61 > 0 ) ||
( V_2 -> V_62 > 0 ) ) {
V_12 = F_25 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
}
V_12 = F_26 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_27 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
V_12 = F_28 ( V_2 ) ;
if ( V_12 < 0 )
goto error;
if ( ! V_2 -> V_63 ) {
V_12 = F_29 ( V_21 ) ;
if ( V_12 < 0 ) {
F_30 ( V_2 ) ;
goto error;
}
} else {
V_2 -> V_64 = true ;
F_31 ( F_2 ( V_2 -> V_6 ) -> V_21 ,
false , true ) ;
}
F_32 ( & V_6 -> V_26 , V_2 ) ;
V_15:
F_10 ( & V_31 ) ;
return V_12 ;
error:
F_10 ( & V_31 ) ;
F_33 ( V_21 ) ;
return V_12 ;
}
static void
F_34 ( struct V_35 * V_6 )
{
struct V_1 * V_2 = F_35 ( & V_6 -> V_26 ) ;
if ( V_2 == NULL )
return;
F_36 ( V_2 -> V_6 ) ;
F_37 ( V_2 ) ;
if ( V_2 -> V_64 ) {
if ( F_29 ( V_2 -> V_21 ) < 0 ) {
F_30 ( V_2 ) ;
F_33 ( V_2 -> V_21 ) ;
}
V_2 -> V_64 = false ;
}
}
static void F_38 ( struct V_35 * V_6 )
{
struct V_1 * V_2 = F_35 ( & V_6 -> V_26 ) ;
if ( V_2 == NULL )
return;
F_39 ( V_2 -> V_63 ) ;
F_30 ( V_2 ) ;
F_40 ( V_2 -> V_21 ) ;
F_41 ( V_2 -> V_21 ) ;
}
static int T_2
F_42 ( void )
{
return F_43 ( & V_65 . V_22 ) ;
}
static void T_3
F_44 ( void )
{
F_45 ( & V_65 . V_22 ) ;
}
