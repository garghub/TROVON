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
if ( V_8 && V_8 -> type == type )
V_9 = V_8 -> V_9 ;
else
V_9 = NULL ;
F_8 ( & V_11 ) ;
return V_9 ;
}
static struct V_7 * F_9 ( unsigned int V_3 )
{
int V_12 ;
F_8 ( & V_11 ) ;
V_12 = F_10 ( V_3 ) ;
if ( V_12 == V_13 ) {
int V_1 = F_11 ( V_3 ) ;
if ( V_14 [ V_1 ] == NULL )
F_1 ( V_1 ) ;
} else if ( V_12 == V_15 ) {
F_4 ( V_3 ) ;
}
F_7 ( & V_11 ) ;
return V_10 [ V_3 ] ;
}
static int F_12 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
unsigned int V_3 = F_13 ( V_16 ) ;
struct V_7 * V_18 = NULL ;
const struct V_19 * V_20 ;
int V_21 = 0 ;
if ( V_3 >= F_6 ( V_10 ) )
return - V_22 ;
F_7 ( & V_11 ) ;
V_18 = V_10 [ V_3 ] ;
if ( V_18 == NULL ) {
V_18 = F_9 ( V_3 ) ;
if ( ! V_18 ) {
F_8 ( & V_11 ) ;
return - V_22 ;
}
}
V_20 = V_17 -> V_23 ;
V_17 -> V_23 = F_14 ( V_18 -> V_24 ) ;
if ( V_17 -> V_23 == NULL ) {
V_17 -> V_23 = V_20 ;
V_21 = - V_22 ;
}
F_8 ( & V_11 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_17 -> V_23 -> V_25 ) {
V_21 = V_17 -> V_23 -> V_25 ( V_16 , V_17 ) ;
if ( V_21 ) {
F_15 ( V_17 -> V_23 ) ;
V_17 -> V_23 = F_14 ( V_20 ) ;
}
}
F_15 ( V_20 ) ;
return V_21 ;
}
static int F_16 ( int type )
{
int V_3 ;
if ( type == V_26 )
return V_5 ;
if ( type == V_27 )
return V_6 ;
for ( V_3 = 0 ; V_3 < F_6 ( V_10 ) ; ++ V_3 ) {
if ( F_10 ( V_3 ) == V_13 )
continue;
if ( V_3 == V_5 ||
V_3 == V_6 )
continue;
if ( ! V_10 [ V_3 ] )
return V_3 ;
}
return - V_28 ;
}
static int F_17 ( int type , struct V_29 * V_1 , int V_12 )
{
int V_3 ;
switch ( type ) {
case V_26 :
case V_27 :
V_3 = type ;
break;
case V_30 :
if ( F_18 ( ! V_1 ) )
return - V_31 ;
V_3 = F_19 ( V_1 -> V_32 , type ) ;
break;
case V_33 :
case V_34 :
case V_35 :
case V_36 :
if ( F_18 ( ! V_1 ) )
return - V_31 ;
V_3 = F_19 ( V_1 -> V_32 , type + V_12 ) ;
break;
default:
return - V_31 ;
}
if ( F_18 ( V_3 < 0 || V_3 >= V_37 ) )
return - V_31 ;
return V_3 ;
}
int F_20 ( int type , struct V_29 * V_1 , int V_12 ,
const struct V_19 * V_24 ,
void * V_9 ,
const char * V_38 , struct V_39 * V_39 )
{
int V_3 ;
struct V_7 * V_40 ;
if ( F_18 ( ! V_38 ) )
return - V_31 ;
V_40 = F_21 ( sizeof *V_40 , V_41 ) ;
if ( V_40 == NULL )
return - V_42 ;
V_40 -> type = type ;
V_40 -> V_1 = V_1 ? V_1 -> V_32 : - 1 ;
V_40 -> V_39 = V_12 ;
V_40 -> V_24 = V_24 ;
V_40 -> V_9 = V_9 ;
F_7 ( & V_11 ) ;
#ifdef F_22
V_3 = F_16 ( type ) ;
#else
V_3 = F_17 ( type , V_1 , V_12 ) ;
if ( V_3 >= 0 && V_10 [ V_3 ] )
V_3 = - V_28 ;
#endif
if ( V_3 < 0 ) {
F_8 ( & V_11 ) ;
F_23 ( V_40 ) ;
return V_3 ;
}
V_10 [ V_3 ] = V_40 ;
V_40 -> V_12 = F_24 ( V_43 , V_39 , F_25 ( V_44 , V_3 ) ,
V_9 , L_4 , V_38 ) ;
if ( F_26 ( V_40 -> V_12 ) ) {
V_10 [ V_3 ] = NULL ;
F_8 ( & V_11 ) ;
V_3 = F_27 ( V_40 -> V_12 ) ;
F_23 ( V_40 ) ;
return V_3 ;
}
F_8 ( & V_11 ) ;
return 0 ;
}
static int F_28 ( int type , struct V_29 * V_1 , int V_12 )
{
int V_45 , V_3 ;
struct V_7 * V_18 ;
V_45 = V_1 ? V_1 -> V_32 : - 1 ;
for ( V_3 = 0 ; V_3 < F_6 ( V_10 ) ; ++ V_3 )
if ( ( V_18 = V_10 [ V_3 ] ) != NULL &&
V_18 -> type == type &&
V_18 -> V_1 == V_45 &&
V_18 -> V_39 == V_12 )
return V_3 ;
return - 1 ;
}
int F_29 ( int type , struct V_29 * V_1 , int V_12 )
{
int V_3 ;
F_7 ( & V_11 ) ;
V_3 = F_28 ( type , V_1 , V_12 ) ;
if ( V_3 < 0 ) {
F_8 ( & V_11 ) ;
return - V_31 ;
}
F_30 ( V_43 , F_25 ( V_44 , V_3 ) ) ;
F_23 ( V_10 [ V_3 ] ) ;
V_10 [ V_3 ] = NULL ;
F_8 ( & V_11 ) ;
return 0 ;
}
int F_31 ( int type , struct V_29 * V_1 , int V_12 ,
struct V_46 * V_47 )
{
int V_3 , V_48 = - V_31 ;
struct V_39 * V_49 ;
F_7 ( & V_11 ) ;
V_3 = F_28 ( type , V_1 , V_12 ) ;
if ( V_3 >= 0 && ( V_49 = V_10 [ V_3 ] -> V_12 ) != NULL )
V_48 = F_32 ( V_49 , V_47 ) ;
F_8 ( & V_11 ) ;
return V_48 ;
}
static const char * F_33 ( int type )
{
switch ( type ) {
case V_30 :
return L_5 ;
case V_33 :
return L_6 ;
case V_34 :
return L_7 ;
case V_35 :
return L_8 ;
case V_36 :
return L_9 ;
case V_26 :
return L_10 ;
case V_27 :
return L_11 ;
default:
return L_12 ;
}
}
static void F_34 ( struct V_50 * V_51 , struct V_52 * V_53 )
{
int V_3 ;
struct V_7 * V_18 ;
F_7 ( & V_11 ) ;
for ( V_3 = 0 ; V_3 < V_37 ; ++ V_3 ) {
if ( ! ( V_18 = V_10 [ V_3 ] ) )
continue;
if ( V_18 -> V_1 >= 0 ) {
if ( V_18 -> V_39 >= 0 )
F_35 ( V_53 , L_13 ,
V_3 , V_18 -> V_1 , V_18 -> V_39 ,
F_33 ( V_18 -> type ) ) ;
else
F_35 ( V_53 , L_14 ,
V_3 , V_18 -> V_1 ,
F_33 ( V_18 -> type ) ) ;
} else
F_35 ( V_53 , L_15 , V_3 ,
F_33 ( V_18 -> type ) ) ;
}
F_8 ( & V_11 ) ;
}
int T_1 F_36 ( void )
{
struct V_50 * V_51 ;
V_51 = F_37 ( V_54 , L_16 , NULL ) ;
if ( V_51 ) {
V_51 -> V_55 . V_56 . V_57 = F_34 ;
if ( F_38 ( V_51 ) < 0 ) {
F_39 ( V_51 ) ;
V_51 = NULL ;
}
}
V_58 = V_51 ;
return 0 ;
}
int T_2 F_40 ( void )
{
F_39 ( V_58 ) ;
return 0 ;
}
static int T_1 F_41 ( void )
{
V_59 = V_44 ;
V_60 = V_2 ;
if ( F_42 ( V_44 , L_17 , & V_61 ) ) {
F_43 ( V_62 L_18 , V_44 ) ;
return - V_63 ;
}
if ( F_44 () < 0 ) {
F_45 ( V_44 , L_17 ) ;
return - V_42 ;
}
F_46 () ;
#ifndef F_47
F_48 (KERN_INFO L_19 CONFIG_SND_VERSION CONFIG_SND_DATE L_20 ) ;
#endif
return 0 ;
}
static void T_2 F_49 ( void )
{
F_50 () ;
F_51 () ;
F_45 ( V_44 , L_17 ) ;
}
