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
static int F_17 ( int type , struct V_28 * V_1 , int V_14 )
{
int V_3 ;
if ( type == V_29 )
return V_5 ;
if ( type == V_30 )
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
return - V_31 ;
}
static int F_17 ( int type , struct V_28 * V_1 , int V_14 )
{
int V_3 ;
switch ( type ) {
case V_29 :
case V_30 :
V_3 = type ;
break;
case V_32 :
if ( F_18 ( ! V_1 ) )
return - V_33 ;
V_3 = F_19 ( V_1 -> V_34 , type ) ;
break;
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
if ( F_18 ( ! V_1 ) )
return - V_33 ;
V_3 = F_19 ( V_1 -> V_34 , type + V_14 ) ;
break;
default:
return - V_33 ;
}
if ( F_18 ( V_3 < 0 || V_3 >= V_40 ) )
return - V_33 ;
if ( V_10 [ V_3 ] )
return - V_31 ;
return V_3 ;
}
int F_20 ( int type , struct V_28 * V_1 , int V_14 ,
const struct V_21 * V_25 ,
void * V_9 , struct V_41 * V_41 )
{
int V_3 ;
int V_23 = 0 ;
struct V_7 * V_42 ;
if ( F_18 ( ! V_41 ) )
return - V_33 ;
V_42 = F_21 ( sizeof *V_42 , V_43 ) ;
if ( V_42 == NULL )
return - V_44 ;
V_42 -> type = type ;
V_42 -> V_1 = V_1 ? V_1 -> V_34 : - 1 ;
V_42 -> V_41 = V_14 ;
V_42 -> V_25 = V_25 ;
V_42 -> V_9 = V_9 ;
V_42 -> V_12 = V_1 ;
F_7 ( & V_11 ) ;
V_3 = F_17 ( type , V_1 , V_14 ) ;
if ( V_3 < 0 ) {
V_23 = V_3 ;
goto error;
}
V_42 -> V_14 = V_41 ;
V_41 -> V_45 = F_22 ( V_46 , V_3 ) ;
V_23 = F_23 ( V_41 ) ;
if ( V_23 < 0 )
goto error;
V_10 [ V_3 ] = V_42 ;
error:
F_9 ( & V_11 ) ;
if ( V_23 < 0 )
F_24 ( V_42 ) ;
return V_23 ;
}
int F_25 ( struct V_41 * V_14 )
{
int V_3 ;
struct V_7 * V_42 ;
F_7 ( & V_11 ) ;
for ( V_3 = 0 ; V_3 < F_6 ( V_10 ) ; ++ V_3 ) {
V_42 = V_10 [ V_3 ] ;
if ( V_42 && V_42 -> V_14 == V_14 ) {
V_10 [ V_3 ] = NULL ;
F_26 ( V_14 ) ;
F_24 ( V_42 ) ;
break;
}
}
F_9 ( & V_11 ) ;
if ( V_3 >= F_6 ( V_10 ) )
return - V_47 ;
return 0 ;
}
static const char * F_27 ( int type )
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
case V_29 :
return L_9 ;
case V_30 :
return L_10 ;
default:
return L_11 ;
}
}
static void F_28 ( struct V_48 * V_49 , struct V_50 * V_51 )
{
int V_3 ;
struct V_7 * V_20 ;
F_7 ( & V_11 ) ;
for ( V_3 = 0 ; V_3 < V_40 ; ++ V_3 ) {
if ( ! ( V_20 = V_10 [ V_3 ] ) )
continue;
if ( V_20 -> V_1 >= 0 ) {
if ( V_20 -> V_41 >= 0 )
F_29 ( V_51 , L_12 ,
V_3 , V_20 -> V_1 , V_20 -> V_41 ,
F_27 ( V_20 -> type ) ) ;
else
F_29 ( V_51 , L_13 ,
V_3 , V_20 -> V_1 ,
F_27 ( V_20 -> type ) ) ;
} else
F_29 ( V_51 , L_14 , V_3 ,
F_27 ( V_20 -> type ) ) ;
}
F_9 ( & V_11 ) ;
}
int T_1 F_30 ( void )
{
struct V_48 * V_49 ;
V_49 = F_31 ( V_52 , L_15 , NULL ) ;
if ( ! V_49 )
return - V_44 ;
V_49 -> V_53 . V_54 . V_55 = F_28 ;
return F_32 ( V_49 ) ;
}
static int T_1 F_33 ( void )
{
V_56 = V_46 ;
V_57 = V_2 ;
if ( F_34 ( V_46 , L_16 , & V_58 ) ) {
F_35 ( L_17 , V_46 ) ;
return - V_59 ;
}
if ( F_36 () < 0 ) {
F_37 ( V_46 , L_16 ) ;
return - V_44 ;
}
#ifndef F_38
F_39 ( L_18 ) ;
#endif
return 0 ;
}
static void T_2 F_40 ( void )
{
F_41 () ;
F_37 ( V_46 , L_16 ) ;
}
