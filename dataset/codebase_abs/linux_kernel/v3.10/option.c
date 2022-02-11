static inline int
F_1 ( const char * V_1 , const char * V_2 , T_1 V_3 )
{
if ( strlen ( V_2 ) != V_3 )
return V_3 ;
return strncasecmp ( V_1 , V_2 , V_3 ) ;
}
const char *
F_2 ( const char * V_4 , const char * V_5 , int * V_6 )
{
while ( V_4 && * V_4 != '\0' ) {
int V_3 = strcspn ( V_4 , L_1 ) ;
switch ( V_4 [ V_3 ] ) {
case '=' :
if ( ! F_1 ( V_4 , V_5 , V_3 ) ) {
V_4 += V_3 + 1 ;
* V_6 = strcspn ( V_4 , L_1 ) ;
return * V_6 ? V_4 : NULL ;
}
V_4 ++ ;
break;
case ',' :
V_4 ++ ;
break;
default:
break;
}
V_4 += V_3 ;
}
return NULL ;
}
bool
F_3 ( const char * V_4 , const char * V_5 , bool V_7 )
{
int V_6 ;
V_4 = F_2 ( V_4 , V_5 , & V_6 ) ;
if ( V_4 ) {
if ( ! F_1 ( V_4 , L_2 , V_6 ) ||
! F_1 ( V_4 , L_3 , V_6 ) ||
! F_1 ( V_4 , L_4 , V_6 ) ||
! F_1 ( V_4 , L_5 , V_6 ) )
V_7 = false ;
else
if ( ! F_1 ( V_4 , L_6 , V_6 ) ||
! F_1 ( V_4 , L_7 , V_6 ) ||
! F_1 ( V_4 , L_8 , V_6 ) ||
! F_1 ( V_4 , L_9 , V_6 ) )
V_7 = true ;
}
return V_7 ;
}
int
F_4 ( const char * V_4 , const char * V_8 )
{
int V_9 = 1 , V_10 = V_11 ;
while ( V_4 ) {
int V_3 = strcspn ( V_4 , L_1 ) ;
switch ( V_4 [ V_3 ] ) {
case '=' :
if ( F_1 ( V_4 , V_8 , V_3 ) )
V_9 = 0 ;
V_4 ++ ;
break;
default:
if ( V_9 ) {
if ( ! F_1 ( V_4 , L_10 , V_3 ) )
V_10 = V_12 ;
else if ( ! F_1 ( V_4 , L_11 , V_3 ) )
V_10 = V_13 ;
else if ( ! F_1 ( V_4 , L_12 , V_3 ) )
V_10 = V_14 ;
else if ( ! F_1 ( V_4 , L_13 , V_3 ) )
V_10 = V_15 ;
else if ( ! F_1 ( V_4 , L_14 , V_3 ) )
V_10 = V_16 ;
else if ( ! F_1 ( V_4 , L_15 , V_3 ) )
V_10 = V_17 ;
else if ( ! F_1 ( V_4 , L_16 , V_3 ) )
V_10 = V_18 ;
else if ( ! F_1 ( V_4 , L_17 , V_3 ) )
V_10 = V_19 ;
}
if ( V_4 [ V_3 ] != '\0' ) {
V_4 ++ ;
V_9 = 1 ;
break;
}
return V_10 ;
}
V_4 += V_3 ;
}
return V_10 ;
}
