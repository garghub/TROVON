static T_1 F_1 ( T_2 V_1 , char * V_2 )
{
char * V_3 ;
if ( F_2 ( V_1 , V_4 ) )
V_3 = L_1 ;
else if ( F_2 ( V_1 , V_5 ) )
V_3 = L_2 ;
else
V_3 = L_3 ;
return snprintf ( V_2 , V_6 , L_4 , V_3 ) ;
}
static T_1 F_3 ( T_2 V_1 , const char * V_2 , T_3 V_7 )
{
if ( ! strncasecmp ( V_2 , L_1 , 5 ) ) {
F_4 ( V_1 , V_4 ) ;
F_5 ( V_1 , V_5 ) ;
} else if ( ! strncasecmp ( V_2 , L_2 , 4 ) ) {
F_4 ( V_1 , V_5 ) ;
F_5 ( V_1 , V_4 ) ;
} else if ( ! strncasecmp ( V_2 , L_3 , 3 ) ) {
F_5 ( V_1 , V_5 ) ;
F_5 ( V_1 , V_4 ) ;
} else
return - V_8 ;
return V_7 ;
}
void F_6 ( const T_2 * V_1 , const char * V_9 , int line ,
const char * V_10 , ... )
{
struct V_11 V_12 ;
T_4 args ;
const char * V_13 ;
const char * V_14 = L_5 ;
if ( ! F_2 ( * V_1 , V_4 ) ||
F_2 ( * V_1 , V_5 ) )
return;
if ( * V_1 & V_15 ) {
V_13 = V_16 ;
V_14 = L_6 ;
} else if ( * V_1 & V_17 ) {
V_13 = V_18 ;
} else {
V_13 = V_19 ;
}
va_start ( args , V_10 ) ;
V_12 . V_10 = V_10 ;
V_12 . V_20 = & args ;
F_7 ( L_7 ,
V_13 , V_21 -> V_22 , F_8 ( V_21 ) ,
F_9 () , V_9 , line , V_14 , & V_12 ) ;
va_end ( args ) ;
}
static T_1 F_10 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_2 )
{
struct V_27 * V_28 = F_11 ( V_26 ) ;
return F_1 ( V_28 -> V_1 , V_2 ) ;
}
static T_1 F_12 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_2 , T_3 V_7 )
{
struct V_27 * V_28 = F_11 ( V_26 ) ;
return F_3 ( V_28 -> V_1 , V_2 , V_7 ) ;
}
int F_13 ( struct V_29 * V_30 )
{
int V_31 = 0 ;
while ( V_32 [ V_31 ] . V_26 . V_33 ) {
V_34 [ V_31 ] = & V_32 [ V_31 ] . V_26 ;
V_31 ++ ;
}
V_34 [ V_31 ] = NULL ;
F_14 ( & V_35 . V_36 , L_8 ) ;
V_35 . V_36 . V_29 = V_30 ;
return F_15 ( & V_35 ) ;
}
void F_16 ( void )
{
F_17 ( & V_35 ) ;
}
