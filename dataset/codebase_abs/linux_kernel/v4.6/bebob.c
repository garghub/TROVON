static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
char V_7 [ 24 ] = { 0 } ;
char V_8 [ 32 ] = { 0 } ;
T_1 V_9 ;
T_1 V_10 [ 2 ] = { 0 } ;
T_1 V_11 ;
T_1 V_12 ;
int V_13 ;
V_13 = F_3 ( V_5 -> V_14 + 5 , V_15 ,
V_7 , sizeof( V_7 ) ) ;
if ( V_13 < 0 )
goto V_16;
V_13 = F_3 ( V_2 -> V_6 -> V_17 , V_18 ,
V_8 , sizeof( V_8 ) ) ;
if ( V_13 < 0 )
goto V_16;
V_13 = F_4 ( V_2 -> V_6 , V_19 ,
& V_9 ) ;
if ( V_13 < 0 )
goto V_16;
V_13 = F_4 ( V_2 -> V_6 , V_20 ,
& V_11 ) ;
if ( V_13 < 0 )
goto V_16;
V_13 = F_5 ( V_2 -> V_6 , V_21 ,
V_10 , sizeof( V_10 ) ) ;
if ( V_13 < 0 )
goto V_16;
V_13 = F_4 ( V_2 -> V_6 , V_22 ,
& V_12 ) ;
if ( V_13 < 0 )
goto V_16;
V_2 -> V_12 = V_12 ;
strcpy ( V_2 -> V_23 -> V_24 , L_1 ) ;
strcpy ( V_2 -> V_23 -> V_25 , V_8 ) ;
strcpy ( V_2 -> V_23 -> V_26 , V_8 ) ;
snprintf ( V_2 -> V_23 -> V_27 , sizeof( V_2 -> V_23 -> V_27 ) ,
L_2 ,
V_7 , V_8 , V_9 , V_11 ,
V_10 [ 0 ] , V_10 [ 1 ] , F_6 ( & V_2 -> V_6 -> V_28 ) ,
100 << V_5 -> V_29 ) ;
V_16:
return V_13 ;
}
static void
F_7 ( struct V_30 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_31 ;
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_6 ) ;
F_10 ( V_2 -> V_32 ) ;
if ( V_2 -> V_33 >= 0 ) {
F_11 ( & V_34 ) ;
F_12 ( V_2 -> V_33 , V_35 ) ;
F_13 ( & V_34 ) ;
}
F_14 ( & V_2 -> V_36 ) ;
}
static const struct V_37 *
F_15 ( struct V_38 * V_6 )
{
char V_39 [ 24 ] = { 0 } ;
if ( F_3 ( V_6 -> V_17 , V_18 , V_39 , sizeof( V_39 ) ) < 0 )
return NULL ;
if ( strcmp ( V_39 , L_3 ) == 0 )
return & V_40 ;
else
return & V_41 ;
}
static bool
F_16 ( struct V_38 * V_6 )
{
char V_39 [ 24 ] = { 0 } ;
if ( F_3 ( V_6 -> V_17 , V_18 , V_39 , sizeof( V_39 ) ) < 0 )
return false ;
return strncmp ( V_39 , L_4 , 15 ) != 0 ;
}
static int
F_17 ( struct V_38 * V_6 ,
const struct V_42 * V_43 )
{
struct V_30 * V_23 ;
struct V_1 * V_2 ;
const struct V_37 * V_44 ;
unsigned int V_33 ;
int V_13 ;
F_11 ( & V_34 ) ;
for ( V_33 = 0 ; V_33 < V_45 ; V_33 ++ ) {
if ( ! F_18 ( V_33 , V_35 ) && V_46 [ V_33 ] )
break;
}
if ( V_33 >= V_45 ) {
V_13 = - V_47 ;
goto V_16;
}
if ( ( V_43 -> V_3 == V_48 ) &&
( V_43 -> V_49 == V_50 ) )
V_44 = F_15 ( V_6 ) ;
else if ( ( V_43 -> V_3 == V_51 ) &&
( V_43 -> V_49 == V_52 ) &&
! F_16 ( V_6 ) )
V_44 = NULL ;
else
V_44 = ( const struct V_37 * ) V_43 -> V_53 ;
if ( V_44 == NULL ) {
if ( ( V_43 -> V_3 == V_51 ) ||
( V_43 -> V_3 == V_54 ) )
V_13 = F_19 ( V_6 ) ;
else
V_13 = - V_55 ;
goto V_16;
}
V_13 = F_20 ( & V_6 -> V_28 , V_56 [ V_33 ] , V_57 [ V_33 ] ,
V_58 , sizeof( struct V_1 ) , & V_23 ) ;
if ( V_13 < 0 )
goto V_16;
V_2 = V_23 -> V_31 ;
V_2 -> V_33 = V_33 ;
F_21 ( V_33 , V_35 ) ;
V_23 -> V_59 = F_7 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_6 = F_22 ( V_6 ) ;
V_2 -> V_44 = V_44 ;
F_23 ( & V_2 -> V_36 ) ;
F_24 ( & V_2 -> V_60 ) ;
F_25 ( & V_2 -> V_61 ) ;
V_13 = F_1 ( V_2 , V_43 -> V_3 ) ;
if ( V_13 < 0 )
goto error;
if ( ( V_43 -> V_3 == V_51 ) &&
( V_43 -> V_49 == V_62 ) )
V_13 = F_26 ( V_2 , true ) ;
else if ( ( V_43 -> V_3 == V_51 ) &&
( V_43 -> V_49 == V_63 ) )
V_13 = F_26 ( V_2 , false ) ;
else
V_13 = F_27 ( V_2 ) ;
if ( V_13 < 0 )
goto error;
F_28 ( V_2 ) ;
if ( ( V_2 -> V_64 > 0 ) ||
( V_2 -> V_65 > 0 ) ) {
V_13 = F_29 ( V_2 ) ;
if ( V_13 < 0 )
goto error;
}
V_13 = F_30 ( V_2 ) ;
if ( V_13 < 0 )
goto error;
V_13 = F_31 ( V_2 ) ;
if ( V_13 < 0 )
goto error;
V_13 = F_32 ( V_2 ) ;
if ( V_13 < 0 )
goto error;
if ( ! V_2 -> V_32 ) {
V_13 = F_33 ( V_23 ) ;
if ( V_13 < 0 ) {
F_8 ( V_2 ) ;
goto error;
}
} else {
V_2 -> V_66 = true ;
F_34 ( F_2 ( V_2 -> V_6 ) -> V_23 ,
false , true ) ;
}
F_35 ( & V_6 -> V_28 , V_2 ) ;
V_16:
F_13 ( & V_34 ) ;
return V_13 ;
error:
F_13 ( & V_34 ) ;
F_36 ( V_23 ) ;
return V_13 ;
}
static void
F_37 ( struct V_38 * V_6 )
{
struct V_1 * V_2 = F_38 ( & V_6 -> V_28 ) ;
if ( V_2 == NULL )
return;
F_39 ( V_2 -> V_6 ) ;
if ( V_2 -> V_66 ) {
if ( F_33 ( V_2 -> V_23 ) < 0 ) {
F_8 ( V_2 ) ;
F_36 ( V_2 -> V_23 ) ;
}
V_2 -> V_66 = false ;
}
}
static void F_40 ( struct V_38 * V_6 )
{
struct V_1 * V_2 = F_38 ( & V_6 -> V_28 ) ;
if ( V_2 == NULL )
return;
F_41 ( V_2 -> V_23 ) ;
}
static int T_2
F_42 ( void )
{
return F_43 ( & V_67 . V_24 ) ;
}
static void T_3
F_44 ( void )
{
F_45 ( & V_67 . V_24 ) ;
}
