static inline char * F_1 ( int type )
{
switch ( type ) {
case V_1 :
return L_1 ;
case V_2 :
return L_2 ;
case V_3 :
return L_3 ;
case V_4 :
return L_4 ;
default:
return L_5 ;
}
}
static T_1 F_2 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_6 , F_1 ( V_11 -> type ) ) ;
}
static T_1 F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_3 ( V_6 ) ;
return sprintf ( V_9 , L_7 , & V_11 -> V_12 ) ;
}
static void F_5 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = F_3 ( V_6 ) ;
F_6 ( V_11 ) ;
}
static int F_7 ( struct V_5 * V_6 , void * V_13 )
{
return ! strncmp ( F_8 ( V_6 ) , L_8 , 6 ) ;
}
void F_9 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_15 ;
F_10 ( L_9 , V_11 ) ;
V_11 -> V_6 . type = & V_16 ;
V_11 -> V_6 . V_17 = V_18 ;
V_11 -> V_6 . V_19 = & V_15 -> V_6 ;
F_11 ( & V_11 -> V_6 ) ;
}
void F_12 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_15 ;
F_10 ( L_9 , V_11 ) ;
F_13 ( & V_11 -> V_6 , L_10 , V_15 -> V_20 , V_11 -> V_21 ) ;
if ( F_14 ( & V_11 -> V_6 ) < 0 ) {
F_15 ( L_11 ) ;
return;
}
F_16 ( V_15 ) ;
}
void F_17 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_15 ;
if ( ! F_18 ( & V_11 -> V_6 ) )
return;
while ( 1 ) {
struct V_5 * V_6 ;
V_6 = F_19 ( & V_11 -> V_6 , NULL , F_7 ) ;
if ( ! V_6 )
break;
F_20 ( V_6 , NULL , V_22 ) ;
F_21 ( V_6 ) ;
}
F_22 ( & V_11 -> V_6 ) ;
F_23 ( V_15 ) ;
}
static inline char * F_24 ( int type )
{
switch ( type ) {
case V_23 :
return L_12 ;
case V_24 :
return L_13 ;
default:
return L_5 ;
}
}
static T_1 F_25 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_14 * V_15 = F_26 ( V_6 ) ;
return sprintf ( V_9 , L_6 , F_24 ( V_15 -> V_25 ) ) ;
}
static T_1 F_27 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_14 * V_15 = F_26 ( V_6 ) ;
char V_20 [ V_26 + 1 ] ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ )
V_20 [ V_27 ] = V_15 -> F_8 [ V_27 ] ;
V_20 [ V_26 ] = '\0' ;
return sprintf ( V_9 , L_6 , V_20 ) ;
}
static T_1 F_28 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_14 * V_15 = F_26 ( V_6 ) ;
return sprintf ( V_9 , L_7 , & V_15 -> V_28 ) ;
}
static void F_29 ( struct V_5 * V_6 )
{
struct V_14 * V_15 = F_26 ( V_6 ) ;
F_6 ( V_15 ) ;
F_30 ( V_29 ) ;
}
void F_31 ( struct V_14 * V_15 )
{
struct V_5 * V_6 = & V_15 -> V_6 ;
V_6 -> type = & V_30 ;
V_6 -> V_17 = V_18 ;
F_32 ( V_29 ) ;
F_11 ( V_6 ) ;
}
int T_2 F_33 ( void )
{
V_18 = F_34 ( V_29 , L_14 ) ;
return F_35 ( V_18 ) ;
}
void F_36 ( void )
{
F_37 ( V_18 ) ;
}
