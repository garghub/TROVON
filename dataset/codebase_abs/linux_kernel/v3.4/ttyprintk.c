static int F_1 ( const unsigned char * V_1 , int V_2 )
{
static char V_3 [ V_4 + 4 ] ;
int V_5 = V_6 ;
if ( V_1 == NULL ) {
if ( V_6 > 0 ) {
V_3 [ V_6 + 0 ] = '\n' ;
V_3 [ V_6 + 1 ] = '\0' ;
F_2 ( V_7 L_1 , V_8 , V_3 ) ;
V_6 = 0 ;
}
return V_5 ;
}
for ( V_5 = 0 ; V_5 < V_2 ; V_5 ++ ) {
V_3 [ V_6 ] = V_1 [ V_5 ] ;
if ( V_6 < V_4 ) {
switch ( V_1 [ V_5 ] ) {
case '\r' :
V_3 [ V_6 + 0 ] = '\n' ;
V_3 [ V_6 + 1 ] = '\0' ;
F_2 ( V_7 L_1 , V_8 , V_3 ) ;
V_6 = 0 ;
if ( V_1 [ V_5 + 1 ] == '\n' )
V_5 ++ ;
break;
case '\n' :
V_3 [ V_6 + 1 ] = '\0' ;
F_2 ( V_7 L_1 , V_8 , V_3 ) ;
V_6 = 0 ;
break;
default:
V_6 ++ ;
}
} else {
V_3 [ V_6 + 1 ] = '\\' ;
V_3 [ V_6 + 2 ] = '\n' ;
V_3 [ V_6 + 3 ] = '\0' ;
F_2 ( V_7 L_1 , V_8 , V_3 ) ;
V_6 = 0 ;
}
}
return V_2 ;
}
static int F_3 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
V_10 -> V_13 = & V_14 ;
return F_4 ( & V_14 . V_15 , V_10 , V_12 ) ;
}
static void F_5 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_16 * V_17 = V_10 -> V_13 ;
F_6 ( & V_17 -> V_18 ) ;
F_1 ( NULL , 0 ) ;
F_7 ( & V_17 -> V_18 ) ;
F_8 ( & V_17 -> V_15 , V_10 , V_12 ) ;
}
static int F_9 ( struct V_9 * V_10 ,
const unsigned char * V_1 , int V_2 )
{
struct V_16 * V_17 = V_10 -> V_13 ;
int V_19 ;
F_6 ( & V_17 -> V_18 ) ;
V_19 = F_1 ( V_1 , V_2 ) ;
F_7 ( & V_17 -> V_18 ) ;
return V_19 ;
}
static int F_10 ( struct V_9 * V_10 )
{
return V_20 ;
}
static int F_11 ( struct V_9 * V_10 ,
unsigned int V_21 , unsigned long V_22 )
{
struct V_16 * V_17 = V_10 -> V_13 ;
if ( ! V_17 )
return - V_23 ;
switch ( V_21 ) {
case V_24 :
return - V_25 ;
default:
return - V_26 ;
}
return 0 ;
}
static int T_1 F_12 ( void )
{
int V_19 = - V_27 ;
void * V_28 ;
V_29 = F_13 ( 1 ) ;
if ( ! V_29 )
return V_19 ;
V_29 -> V_30 = L_2 ;
V_29 -> V_31 = L_2 ;
V_29 -> V_32 = V_33 ;
V_29 -> V_34 = 3 ;
V_29 -> type = V_35 ;
V_29 -> V_36 = V_37 ;
V_29 -> V_36 . V_38 = V_39 | V_40 | V_41 | V_42 ;
V_29 -> V_43 = V_44 |
V_45 | V_46 ;
F_14 ( V_29 , & V_47 ) ;
V_19 = F_15 ( V_29 ) ;
if ( V_19 < 0 ) {
F_2 ( V_48 L_3 ) ;
goto error;
}
V_28 = F_16 ( V_49 , NULL , F_17 ( V_33 , 3 ) , NULL ,
V_29 -> V_31 ) ;
if ( F_18 ( V_28 ) ) {
F_2 ( V_48 L_4 ) ;
V_19 = F_19 ( V_28 ) ;
goto error;
}
F_20 ( & V_14 . V_15 ) ;
V_14 . V_15 . V_50 = & V_51 ;
F_21 ( & V_14 . V_18 ) ;
return 0 ;
error:
F_22 ( V_29 ) ;
V_29 = NULL ;
return V_19 ;
}
