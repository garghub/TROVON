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
long
F_4 ( const char * V_1 , const char * V_2 , long V_5 )
{
long V_6 = V_5 ;
int V_3 ;
char * V_7 ;
V_1 = F_1 ( V_1 , V_2 , & V_3 ) ;
if ( V_1 && ( V_7 = F_5 ( V_1 , V_3 , V_8 ) ) ) {
int V_9 = F_6 ( V_7 , 0 , & V_5 ) ;
if ( V_9 == 0 )
V_6 = V_5 ;
F_7 ( V_7 ) ;
}
return V_6 ;
}
int
F_8 ( const char * V_1 , const char * V_10 )
{
int V_11 = 1 , V_12 = V_13 ;
while ( V_1 ) {
int V_4 = strcspn ( V_1 , L_1 ) ;
switch ( V_1 [ V_4 ] ) {
case '=' :
if ( F_2 ( V_1 , V_10 , V_4 ) )
V_11 = 0 ;
V_1 ++ ;
break;
default:
if ( V_11 ) {
if ( ! F_2 ( V_1 , L_10 , V_4 ) )
V_12 = V_14 ;
else if ( ! F_2 ( V_1 , L_11 , V_4 ) )
V_12 = V_15 ;
else if ( ! F_2 ( V_1 , L_12 , V_4 ) )
V_12 = V_16 ;
else if ( ! F_2 ( V_1 , L_13 , V_4 ) )
V_12 = V_17 ;
else if ( ! F_2 ( V_1 , L_14 , V_4 ) )
V_12 = V_18 ;
else if ( ! F_2 ( V_1 , L_15 , V_4 ) )
V_12 = V_19 ;
else if ( ! F_2 ( V_1 , L_16 , V_4 ) )
V_12 = V_20 ;
else if ( ! F_2 ( V_1 , L_17 , V_4 ) )
V_12 = V_21 ;
}
if ( V_1 [ V_4 ] != '\0' ) {
V_1 ++ ;
V_11 = 1 ;
break;
}
return V_12 ;
}
V_1 += V_4 ;
}
return V_12 ;
}
