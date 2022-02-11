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
static int F_17 ( struct V_38 * V_39 ,
const char * V_40 )
{
struct V_16 V_41 ;
struct V_42 * V_43 ;
struct V_2 * V_21 ;
V_21 = F_18 ( V_40 ) ;
if ( ! V_21 ) {
F_16 ( L_4 , V_40 ) ;
return - V_14 ;
}
V_41 . V_21 = V_21 ;
V_41 . V_22 = 0 ;
V_43 = F_19 ( & V_41 ) ;
if ( F_20 ( V_43 ) ) {
F_16 ( L_5 , V_40 , F_21 ( V_43 ) ) ;
return F_21 ( V_43 ) ;
}
F_12 ( L_6 , V_43 -> V_44 , V_39 -> V_44 ) ;
return F_22 ( V_43 , & V_39 -> V_45 ) ;
}
static inline int F_17 ( struct V_38 * V_39 ,
const char * V_40 )
{
return 0 ;
}
int T_2 F_23 ( const struct V_46 * V_45 )
{
struct V_38 * V_39 = V_45 -> V_39 ;
unsigned int V_8 ;
int error ;
F_12 ( L_7 , V_39 -> V_44 ) ;
if ( F_5 ( V_39 -> V_4 ,
V_39 -> V_7 ) ) {
F_24 ( L_8 , V_39 -> V_44 ) ;
return - V_47 ;
}
F_13 ( V_39 -> V_4 , V_39 -> V_7 ) ;
for ( V_8 = 0 ; V_8 < V_45 -> V_48 ; V_8 ++ )
F_14 ( & V_45 -> V_49 [ V_8 ] ) ;
if ( V_45 -> V_40 )
F_17 ( V_39 , V_45 -> V_40 ) ;
error = F_25 ( V_39 ) ;
if ( error ) {
F_16 ( L_9 , V_39 -> V_44 ,
error ) ;
return error ;
}
return error ;
}
void T_2 F_26 ( const struct V_46 * V_50 ,
unsigned int V_51 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_51 ; V_8 ++ )
F_23 ( & V_50 [ V_8 ] ) ;
}
