static int F_1 ( char * * V_1 , int V_2 , const char * V_3 , int V_4 )
{
V_2 -= V_4 ;
if ( V_2 < 0 )
return - V_5 ;
* V_1 -= V_4 ;
memcpy ( * V_1 , V_3 , V_4 ) ;
return 0 ;
}
static int F_2 ( struct V_6 * V_6 , char * V_7 , int V_2 ,
char * * V_8 , int V_9 )
{
char * V_10 ;
int error = 0 ;
int V_11 = 1 ;
if ( V_6 -> V_12 -> V_13 & V_14 ) {
V_10 = F_3 ( V_6 -> V_15 , V_7 , V_2 ) ;
* V_8 = V_10 ;
if ( F_4 ( V_10 ) ) {
* V_8 = V_7 ;
return F_5 ( V_10 ) ;
}
if ( V_6 -> V_15 -> V_16 -> V_17 == V_18 &&
strncmp ( * V_8 , L_1 , 5 ) == 0 ) {
return F_1 ( V_8 , * V_8 - V_7 , L_2 , 5 ) ;
}
return 0 ;
}
if ( V_9 & V_19 ) {
struct V_6 V_20 ;
F_6 ( V_21 -> V_22 , & V_20 ) ;
V_10 = F_7 ( V_6 , & V_20 , V_7 , V_2 ) ;
if ( V_10 && ! F_4 ( V_10 ) ) {
* V_8 = V_10 ;
F_8 ( & V_20 ) ;
goto V_23;
}
F_8 ( & V_20 ) ;
V_11 = 0 ;
}
V_10 = F_9 ( V_6 , V_7 , V_2 ) ;
* V_8 = V_10 ;
if ( F_4 ( V_10 ) ) {
error = F_5 ( V_10 ) ;
* V_8 = V_7 ;
goto V_24;
}
if ( ! F_10 ( V_6 -> V_12 ) )
V_11 = 0 ;
V_23:
if ( F_11 ( V_6 -> V_15 ) && V_6 -> V_15 -> V_25 &&
! ( V_9 & V_26 ) ) {
error = - V_27 ;
goto V_24;
}
if ( ! V_11 ) {
if ( ! ( V_9 & V_28 ) &&
! ( ( ( V_9 & V_29 ) == V_29 ) &&
F_10 ( V_6 -> V_12 ) ) ) {
error = - V_30 ;
if ( * V_10 == '/' )
* V_8 = V_10 + 1 ;
}
}
V_24:
return error ;
}
static int F_12 ( struct V_6 * V_6 , int V_9 , char * V_1 ,
int V_31 , char * * V_8 )
{
int V_32 = ( V_9 & V_33 ) ? 1 : 0 ;
int error = F_2 ( V_6 , V_1 , V_31 - V_32 , V_8 , V_9 ) ;
if ( ! error && ( V_9 & V_33 ) && ( * V_8 ) [ 1 ] != '\0' )
strcpy ( & V_1 [ V_31 - 2 ] , L_3 ) ;
return error ;
}
int F_13 ( struct V_6 * V_6 , int V_9 , char * * V_1 , const char * * V_8 )
{
char * V_7 , * V_3 = NULL ;
int V_31 = 256 ;
int error ;
* V_8 = NULL ;
* V_1 = NULL ;
for (; ; ) {
V_7 = F_14 ( V_31 , V_34 ) ;
if ( ! V_7 )
return - V_35 ;
error = F_12 ( V_6 , V_9 , V_7 , V_31 , & V_3 ) ;
if ( error != - V_5 )
break;
F_15 ( V_7 ) ;
V_31 <<= 1 ;
if ( V_31 > V_36 )
return - V_5 ;
}
* V_1 = V_7 ;
* V_8 = V_3 ;
return error ;
}
