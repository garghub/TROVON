void F_1 ( int V_1 )
{
if ( F_2 ( V_1 ) )
return;
if ( V_1 < 0 || V_1 >= V_2 )
return;
F_3 ( L_1 , V_1 ) ;
}
static void F_4 ( int V_3 )
{
char * V_4 ;
switch ( V_3 ) {
case V_5 : V_4 = L_2 ; break;
case V_6 : V_4 = L_3 ; break;
default: return;
}
F_3 ( V_4 ) ;
}
void * F_5 ( unsigned int V_3 , int type )
{
struct V_7 * V_8 ;
void * V_9 ;
if ( V_3 >= F_6 ( V_10 ) )
return NULL ;
F_7 ( & V_11 ) ;
V_8 = V_10 [ V_3 ] ;
if ( V_8 && V_8 -> type == type ) {
V_9 = V_8 -> V_9 ;
if ( V_9 && V_8 -> V_12 )
F_8 ( & V_8 -> V_12 -> V_13 ) ;
} else
V_9 = NULL ;
F_9 ( & V_11 ) ;
return V_9 ;
}
static struct V_7 * F_10 ( unsigned int V_3 )
{
int V_14 ;
F_9 ( & V_11 ) ;
V_14 = F_11 ( V_3 ) ;
if ( V_14 == V_15 ) {
int V_1 = F_12 ( V_3 ) ;
if ( V_16 [ V_1 ] == NULL )
F_1 ( V_1 ) ;
} else if ( V_14 == V_17 ) {
F_4 ( V_3 ) ;
}
F_7 ( & V_11 ) ;
return V_10 [ V_3 ] ;
}
static int F_13 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
unsigned int V_3 = F_14 ( V_18 ) ;
struct V_7 * V_20 = NULL ;
const struct V_21 * V_22 ;
int V_23 = 0 ;
if ( V_3 >= F_6 ( V_10 ) )
return - V_24 ;
F_7 ( & V_11 ) ;
V_20 = V_10 [ V_3 ] ;
if ( V_20 == NULL ) {
V_20 = F_10 ( V_3 ) ;
if ( ! V_20 ) {
F_9 ( & V_11 ) ;
return - V_24 ;
}
}
V_22 = V_19 -> V_25 ;
V_19 -> V_25 = F_15 ( V_20 -> V_26 ) ;
if ( V_19 -> V_25 == NULL ) {
V_19 -> V_25 = V_22 ;
V_23 = - V_24 ;
}
F_9 ( & V_11 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_19 -> V_25 -> V_27 ) {
V_23 = V_19 -> V_25 -> V_27 ( V_18 , V_19 ) ;
if ( V_23 ) {
F_16 ( V_19 -> V_25 ) ;
V_19 -> V_25 = F_15 ( V_22 ) ;
}
}
F_16 ( V_22 ) ;
return V_23 ;
}
static int F_17 ( int type )
{
int V_3 ;
if ( type == V_28 )
return V_5 ;
if ( type == V_29 )
return V_6 ;
for ( V_3 = 0 ; V_3 < F_6 ( V_10 ) ; ++ V_3 ) {
if ( F_11 ( V_3 ) == V_15 )
continue;
if ( V_3 == V_5 ||
V_3 == V_6 )
continue;
if ( ! V_10 [ V_3 ] )
return V_3 ;
}
return - V_30 ;
}
static int F_18 ( int type , struct V_31 * V_1 , int V_14 )
{
int V_3 ;
switch ( type ) {
case V_28 :
case V_29 :
V_3 = type ;
break;
case V_32 :
if ( F_19 ( ! V_1 ) )
return - V_33 ;
V_3 = F_20 ( V_1 -> V_34 , type ) ;
break;
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
if ( F_19 ( ! V_1 ) )
return - V_33 ;
V_3 = F_20 ( V_1 -> V_34 , type + V_14 ) ;
break;
default:
return - V_33 ;
}
if ( F_19 ( V_3 < 0 || V_3 >= V_40 ) )
return - V_33 ;
return V_3 ;
}
int F_21 ( int type , struct V_31 * V_1 , int V_14 ,
const struct V_21 * V_26 ,
void * V_9 ,
const char * V_41 , struct V_42 * V_42 )
{
int V_3 ;
struct V_7 * V_43 ;
if ( F_19 ( ! V_41 ) )
return - V_33 ;
V_43 = F_22 ( sizeof *V_43 , V_44 ) ;
if ( V_43 == NULL )
return - V_45 ;
V_43 -> type = type ;
V_43 -> V_1 = V_1 ? V_1 -> V_34 : - 1 ;
V_43 -> V_42 = V_14 ;
V_43 -> V_26 = V_26 ;
V_43 -> V_9 = V_9 ;
V_43 -> V_12 = V_1 ;
F_7 ( & V_11 ) ;
#ifdef F_23
V_3 = F_17 ( type ) ;
#else
V_3 = F_18 ( type , V_1 , V_14 ) ;
if ( V_3 >= 0 && V_10 [ V_3 ] )
V_3 = - V_30 ;
#endif
if ( V_3 < 0 ) {
F_9 ( & V_11 ) ;
F_24 ( V_43 ) ;
return V_3 ;
}
V_10 [ V_3 ] = V_43 ;
V_43 -> V_14 = F_25 ( V_46 , V_42 , F_26 ( V_47 , V_3 ) ,
V_9 , L_4 , V_41 ) ;
if ( F_27 ( V_43 -> V_14 ) ) {
V_10 [ V_3 ] = NULL ;
F_9 ( & V_11 ) ;
V_3 = F_28 ( V_43 -> V_14 ) ;
F_24 ( V_43 ) ;
return V_3 ;
}
F_9 ( & V_11 ) ;
return 0 ;
}
static int F_29 ( int type , struct V_31 * V_1 , int V_14 )
{
int V_48 , V_3 ;
struct V_7 * V_20 ;
V_48 = V_1 ? V_1 -> V_34 : - 1 ;
for ( V_3 = 0 ; V_3 < F_6 ( V_10 ) ; ++ V_3 )
if ( ( V_20 = V_10 [ V_3 ] ) != NULL &&
V_20 -> type == type &&
V_20 -> V_1 == V_48 &&
V_20 -> V_42 == V_14 )
return V_3 ;
return - 1 ;
}
int F_30 ( int type , struct V_31 * V_1 , int V_14 )
{
int V_3 ;
F_7 ( & V_11 ) ;
V_3 = F_29 ( type , V_1 , V_14 ) ;
if ( V_3 < 0 ) {
F_9 ( & V_11 ) ;
return - V_33 ;
}
F_31 ( V_46 , F_26 ( V_47 , V_3 ) ) ;
F_24 ( V_10 [ V_3 ] ) ;
V_10 [ V_3 ] = NULL ;
F_9 ( & V_11 ) ;
return 0 ;
}
int F_32 ( int type , struct V_31 * V_1 , int V_14 ,
struct V_49 * V_50 )
{
int V_3 , V_51 = - V_33 ;
struct V_42 * V_52 ;
F_7 ( & V_11 ) ;
V_3 = F_29 ( type , V_1 , V_14 ) ;
if ( V_3 >= 0 && ( V_52 = V_10 [ V_3 ] -> V_14 ) != NULL )
V_51 = F_33 ( V_52 , V_50 ) ;
F_9 ( & V_11 ) ;
return V_51 ;
}
static const char * F_34 ( int type )
{
switch ( type ) {
case V_32 :
return L_5 ;
case V_35 :
return L_6 ;
case V_36 :
return L_7 ;
case V_37 :
return L_8 ;
case V_38 :
return L_9 ;
case V_28 :
return L_10 ;
case V_29 :
return L_11 ;
default:
return L_12 ;
}
}
static void F_35 ( struct V_53 * V_54 , struct V_55 * V_56 )
{
int V_3 ;
struct V_7 * V_20 ;
F_7 ( & V_11 ) ;
for ( V_3 = 0 ; V_3 < V_40 ; ++ V_3 ) {
if ( ! ( V_20 = V_10 [ V_3 ] ) )
continue;
if ( V_20 -> V_1 >= 0 ) {
if ( V_20 -> V_42 >= 0 )
F_36 ( V_56 , L_13 ,
V_3 , V_20 -> V_1 , V_20 -> V_42 ,
F_34 ( V_20 -> type ) ) ;
else
F_36 ( V_56 , L_14 ,
V_3 , V_20 -> V_1 ,
F_34 ( V_20 -> type ) ) ;
} else
F_36 ( V_56 , L_15 , V_3 ,
F_34 ( V_20 -> type ) ) ;
}
F_9 ( & V_11 ) ;
}
int T_1 F_37 ( void )
{
struct V_53 * V_54 ;
V_54 = F_38 ( V_57 , L_16 , NULL ) ;
if ( V_54 ) {
V_54 -> V_58 . V_59 . V_60 = F_35 ;
if ( F_39 ( V_54 ) < 0 ) {
F_40 ( V_54 ) ;
V_54 = NULL ;
}
}
V_61 = V_54 ;
return 0 ;
}
int T_2 F_41 ( void )
{
F_40 ( V_61 ) ;
return 0 ;
}
static int T_1 F_42 ( void )
{
V_62 = V_47 ;
V_63 = V_2 ;
if ( F_43 ( V_47 , L_17 , & V_64 ) ) {
F_44 ( V_65 L_18 , V_47 ) ;
return - V_66 ;
}
if ( F_45 () < 0 ) {
F_46 ( V_47 , L_17 ) ;
return - V_45 ;
}
F_47 () ;
#ifndef F_48
F_49 ( V_67 L_19 ) ;
#endif
return 0 ;
}
static void T_2 F_50 ( void )
{
F_51 () ;
F_52 () ;
F_46 ( V_47 , L_17 ) ;
}
