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
V_22 = F_15 ( V_20 -> V_25 ) ;
F_9 ( & V_11 ) ;
if ( ! V_22 )
return - V_24 ;
F_16 ( V_19 , V_22 ) ;
if ( V_19 -> V_26 -> V_27 )
V_23 = V_19 -> V_26 -> V_27 ( V_18 , V_19 ) ;
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
const struct V_21 * V_25 ,
void * V_9 , struct V_41 * V_41 )
{
int V_3 ;
int V_23 = 0 ;
struct V_7 * V_42 ;
if ( F_19 ( ! V_41 ) )
return - V_33 ;
V_42 = F_22 ( sizeof *V_42 , V_43 ) ;
if ( V_42 == NULL )
return - V_44 ;
V_42 -> type = type ;
V_42 -> V_1 = V_1 ? V_1 -> V_34 : - 1 ;
V_42 -> V_41 = V_14 ;
V_42 -> V_25 = V_25 ;
V_42 -> V_9 = V_9 ;
V_42 -> V_12 = V_1 ;
F_7 ( & V_11 ) ;
#ifdef F_23
V_3 = F_17 ( type ) ;
#else
V_3 = F_18 ( type , V_1 , V_14 ) ;
if ( V_3 >= 0 && V_10 [ V_3 ] )
V_3 = - V_30 ;
#endif
if ( V_3 < 0 ) {
V_23 = V_3 ;
goto error;
}
V_42 -> V_14 = V_41 ;
V_41 -> V_45 = F_24 ( V_46 , V_3 ) ;
V_23 = F_25 ( V_41 ) ;
if ( V_23 < 0 )
goto error;
V_10 [ V_3 ] = V_42 ;
error:
F_9 ( & V_11 ) ;
if ( V_23 < 0 )
F_26 ( V_42 ) ;
return V_23 ;
}
int F_27 ( struct V_41 * V_14 )
{
int V_3 ;
struct V_7 * V_42 ;
F_7 ( & V_11 ) ;
for ( V_3 = 0 ; V_3 < F_6 ( V_10 ) ; ++ V_3 ) {
V_42 = V_10 [ V_3 ] ;
if ( V_42 && V_42 -> V_14 == V_14 ) {
V_10 [ V_3 ] = NULL ;
F_28 ( V_14 ) ;
F_26 ( V_42 ) ;
break;
}
}
F_9 ( & V_11 ) ;
if ( V_3 >= F_6 ( V_10 ) )
return - V_47 ;
return 0 ;
}
static const char * F_29 ( int type )
{
switch ( type ) {
case V_32 :
return L_4 ;
case V_35 :
return L_5 ;
case V_36 :
return L_6 ;
case V_37 :
return L_7 ;
case V_38 :
return L_8 ;
case V_28 :
return L_9 ;
case V_29 :
return L_10 ;
default:
return L_11 ;
}
}
static void F_30 ( struct V_48 * V_49 , struct V_50 * V_51 )
{
int V_3 ;
struct V_7 * V_20 ;
F_7 ( & V_11 ) ;
for ( V_3 = 0 ; V_3 < V_40 ; ++ V_3 ) {
if ( ! ( V_20 = V_10 [ V_3 ] ) )
continue;
if ( V_20 -> V_1 >= 0 ) {
if ( V_20 -> V_41 >= 0 )
F_31 ( V_51 , L_12 ,
V_3 , V_20 -> V_1 , V_20 -> V_41 ,
F_29 ( V_20 -> type ) ) ;
else
F_31 ( V_51 , L_13 ,
V_3 , V_20 -> V_1 ,
F_29 ( V_20 -> type ) ) ;
} else
F_31 ( V_51 , L_14 , V_3 ,
F_29 ( V_20 -> type ) ) ;
}
F_9 ( & V_11 ) ;
}
int T_1 F_32 ( void )
{
struct V_48 * V_49 ;
V_49 = F_33 ( V_52 , L_15 , NULL ) ;
if ( V_49 ) {
V_49 -> V_53 . V_54 . V_55 = F_30 ;
if ( F_34 ( V_49 ) < 0 ) {
F_35 ( V_49 ) ;
V_49 = NULL ;
}
}
V_56 = V_49 ;
return 0 ;
}
int T_2 F_36 ( void )
{
F_35 ( V_56 ) ;
return 0 ;
}
static int T_1 F_37 ( void )
{
V_57 = V_46 ;
V_58 = V_2 ;
if ( F_38 ( V_46 , L_16 , & V_59 ) ) {
F_39 ( L_17 , V_46 ) ;
return - V_60 ;
}
if ( F_40 () < 0 ) {
F_41 ( V_46 , L_16 ) ;
return - V_44 ;
}
F_42 () ;
#ifndef F_43
F_44 ( L_18 ) ;
#endif
return 0 ;
}
static void T_2 F_45 ( void )
{
F_46 () ;
F_47 () ;
F_41 ( V_46 , L_16 ) ;
}
