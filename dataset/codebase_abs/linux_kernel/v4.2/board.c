static bool F_1 ( T_1 V_1 )
{
struct V_2 * V_3 = F_2 ( NULL ) ;
struct V_4 V_5 ;
while ( V_3 ) {
if ( ! F_3 ( V_3 , 0 , & V_5 ) ) {
if ( V_5 . V_6 == V_1 ) {
F_4 ( V_3 ) ;
return true ;
}
}
V_3 = F_2 ( V_3 ) ;
}
return false ;
}
bool T_2 F_5 ( const struct V_4 * V_4 ,
unsigned int V_7 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
const struct V_4 * V_9 = V_4 + V_8 ;
if ( F_6 ( V_9 ) == V_10 )
if ( F_1 ( V_9 -> V_6 ) )
return true ;
}
return false ;
}
int T_2 F_7 ( const char * V_11 ,
unsigned int V_12 )
{
F_8 ( V_13 ) ;
V_13 = F_9 ( NULL , NULL , V_11 ) ;
F_8 ( ! V_13 ) ;
if ( ! V_13 )
return - V_14 ;
V_15 = V_12 ;
return 0 ;
}
static void T_2 F_10 ( struct V_4 * V_5 )
{
struct V_16 V_17 ;
unsigned int V_18 = V_5 -> V_6 ;
unsigned int V_19 ;
if ( F_6 ( V_5 ) != V_20 || ! V_13 )
return;
V_17 . V_21 = V_13 ;
V_17 . V_22 = 3 ;
V_17 . args [ 0 ] = 0 ;
V_17 . args [ 1 ] = V_18 - V_15 ;
switch ( V_5 -> V_23 &
( V_24 | V_25 |
V_26 | V_27 ) ) {
case V_24 :
V_17 . args [ 2 ] = V_28 ;
break;
case V_25 :
V_17 . args [ 2 ] = V_29 ;
break;
case V_26 :
V_17 . args [ 2 ] = V_30 ;
break;
case V_27 :
default:
V_17 . args [ 2 ] = V_31 ;
break;
}
V_19 = F_11 ( & V_17 ) ;
if ( F_8 ( ! V_19 ) )
return;
F_12 ( L_1 , V_18 , V_19 ) ;
V_5 -> V_6 = V_19 ;
}
void T_2 F_13 ( struct V_4 * V_5 ,
unsigned int V_32 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_32 ; V_8 ++ )
F_10 ( & V_5 [ V_8 ] ) ;
}
int T_2 F_14 ( const struct V_33 * V_34 )
{
int error ;
F_12 ( L_2 , V_34 -> V_35 ,
V_34 -> V_36 , V_34 -> V_37 ) ;
error = F_15 ( V_34 -> V_36 , V_34 -> V_37 , V_34 -> V_35 , NULL ) ;
if ( error )
F_16 ( L_3 , V_34 -> V_35 , error ) ;
return error ;
}
int T_2 F_17 ( const struct V_38 * V_39 )
{
struct V_40 * V_41 = V_39 -> V_41 ;
unsigned int V_8 ;
int error ;
F_12 ( L_4 , V_41 -> V_42 ) ;
if ( F_5 ( V_41 -> V_4 ,
V_41 -> V_7 ) ) {
F_18 ( L_5 , V_41 -> V_42 ) ;
return - V_43 ;
}
F_13 ( V_41 -> V_4 , V_41 -> V_7 ) ;
for ( V_8 = 0 ; V_8 < V_39 -> V_44 ; V_8 ++ )
F_14 ( & V_39 -> V_45 [ V_8 ] ) ;
error = F_19 ( V_41 ) ;
if ( error ) {
F_16 ( L_6 , V_41 -> V_42 ,
error ) ;
return error ;
}
if ( V_39 -> V_46 )
F_20 ( V_39 -> V_46 , & V_41 -> V_39 , NULL ) ;
return error ;
}
void T_2 F_21 ( const struct V_38 * V_47 ,
unsigned int V_48 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_48 ; V_8 ++ )
F_17 ( & V_47 [ V_8 ] ) ;
}
