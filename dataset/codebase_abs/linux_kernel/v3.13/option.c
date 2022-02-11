const char *
F_1 ( const char * V_1 , const char * V_2 , int * V_3 )
{
while ( V_1 && * V_1 != '\0' ) {
int V_4 = strcspn ( V_1 , L_1 ) ;
switch ( V_1 [ V_4 ] ) {
case '=' :
if ( ! F_2 ( V_1 , V_2 , V_4 ) ) {
V_1 += V_4 + 1 ;
* V_3 = strcspn ( V_1 , L_1 ) ;
return * V_3 ? V_1 : NULL ;
}
V_1 ++ ;
break;
case ',' :
V_1 ++ ;
break;
default:
break;
}
V_1 += V_4 ;
}
return NULL ;
}
bool
F_3 ( const char * V_1 , const char * V_2 , bool V_5 )
{
int V_3 ;
V_1 = F_1 ( V_1 , V_2 , & V_3 ) ;
if ( V_1 ) {
if ( ! F_2 ( V_1 , L_2 , V_3 ) ||
! F_2 ( V_1 , L_3 , V_3 ) ||
! F_2 ( V_1 , L_4 , V_3 ) ||
! F_2 ( V_1 , L_5 , V_3 ) )
V_5 = false ;
else
if ( ! F_2 ( V_1 , L_6 , V_3 ) ||
! F_2 ( V_1 , L_7 , V_3 ) ||
! F_2 ( V_1 , L_8 , V_3 ) ||
! F_2 ( V_1 , L_9 , V_3 ) )
V_5 = true ;
}
return V_5 ;
}
int
F_4 ( const char * V_1 , const char * V_6 )
{
int V_7 = 1 , V_8 = V_9 ;
while ( V_1 ) {
int V_4 = strcspn ( V_1 , L_1 ) ;
switch ( V_1 [ V_4 ] ) {
case '=' :
if ( F_2 ( V_1 , V_6 , V_4 ) )
V_7 = 0 ;
V_1 ++ ;
break;
default:
if ( V_7 ) {
if ( ! F_2 ( V_1 , L_10 , V_4 ) )
V_8 = V_10 ;
else if ( ! F_2 ( V_1 , L_11 , V_4 ) )
V_8 = V_11 ;
else if ( ! F_2 ( V_1 , L_12 , V_4 ) )
V_8 = V_12 ;
else if ( ! F_2 ( V_1 , L_13 , V_4 ) )
V_8 = V_13 ;
else if ( ! F_2 ( V_1 , L_14 , V_4 ) )
V_8 = V_14 ;
else if ( ! F_2 ( V_1 , L_15 , V_4 ) )
V_8 = V_15 ;
else if ( ! F_2 ( V_1 , L_16 , V_4 ) )
V_8 = V_16 ;
else if ( ! F_2 ( V_1 , L_17 , V_4 ) )
V_8 = V_17 ;
}
if ( V_1 [ V_4 ] != '\0' ) {
V_1 ++ ;
V_7 = 1 ;
break;
}
return V_8 ;
}
V_1 += V_4 ;
}
return V_8 ;
}
