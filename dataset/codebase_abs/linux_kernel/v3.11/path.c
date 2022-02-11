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
F_8 ( & V_20 ) ;
} else {
V_10 = F_9 ( V_6 , V_7 , V_2 ) ;
if ( ! F_10 ( V_6 -> V_12 ) )
V_11 = 0 ;
}
if ( ! V_10 || F_4 ( V_10 ) ) {
if ( F_5 ( V_10 ) == - V_5 )
return - V_5 ;
V_11 = 0 ;
V_10 = F_11 ( V_6 -> V_15 , V_7 , V_2 ) ;
if ( F_4 ( V_10 ) ) {
error = F_5 ( V_10 ) ;
* V_8 = V_7 ;
goto V_23;
} ;
} else if ( ! F_10 ( V_6 -> V_12 ) )
V_11 = 0 ;
* V_8 = V_10 ;
if ( F_12 ( V_6 -> V_15 ) && V_6 -> V_15 -> V_24 &&
! ( V_9 & V_25 ) ) {
error = - V_26 ;
goto V_23;
}
if ( ! V_11 ) {
if ( ! ( V_9 & V_27 ) &&
! ( ( ( V_9 & V_28 ) == V_28 ) &&
F_10 ( V_6 -> V_12 ) ) ) {
error = - V_29 ;
if ( * V_10 == '/' )
* V_8 = V_10 + 1 ;
}
}
V_23:
return error ;
}
static int F_13 ( struct V_6 * V_6 , int V_9 , char * V_1 ,
int V_30 , char * * V_8 , const char * * V_31 )
{
int V_32 = ( V_9 & V_33 ) ? 1 : 0 ;
int error = F_2 ( V_6 , V_1 , V_30 - V_32 , V_8 , V_9 ) ;
if ( ! error && ( V_9 & V_33 ) && ( * V_8 ) [ 1 ] != '\0' )
strcpy ( & V_1 [ V_30 - 2 ] , L_3 ) ;
if ( V_31 && error ) {
if ( error == - V_26 )
* V_31 = L_4 ;
else if ( error == - V_29 )
* V_31 = L_5 ;
else if ( error == - V_5 )
* V_31 = L_6 ;
else
* V_31 = L_7 ;
}
return error ;
}
int F_14 ( struct V_6 * V_6 , int V_9 , char * * V_1 , const char * * V_8 ,
const char * * V_31 )
{
char * V_7 , * V_3 = NULL ;
int V_30 = 256 ;
int error ;
* V_8 = NULL ;
* V_1 = NULL ;
for (; ; ) {
V_7 = F_15 ( V_30 , V_34 ) ;
if ( ! V_7 )
return - V_35 ;
error = F_13 ( V_6 , V_9 , V_7 , V_30 , & V_3 , V_31 ) ;
if ( error != - V_5 )
break;
F_16 ( V_7 ) ;
V_30 <<= 1 ;
if ( V_30 > V_36 )
return - V_5 ;
* V_31 = NULL ;
}
* V_1 = V_7 ;
* V_8 = V_3 ;
return error ;
}
