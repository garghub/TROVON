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
struct V_6 V_10 , V_11 ;
char * V_12 ;
int V_13 , error = 0 ;
if ( V_9 & V_14 ) {
F_3 ( V_15 -> V_16 , & V_10 ) ;
} else {
V_10 . V_17 = V_15 -> V_18 -> V_19 -> V_10 ;
V_10 . V_20 = V_10 . V_17 -> V_21 ;
F_4 ( & V_10 ) ;
}
V_11 = V_10 ;
V_12 = F_5 ( V_6 , & V_11 , V_7 , V_2 ) ;
* V_8 = V_12 ;
if ( F_6 ( V_12 ) ) {
error = F_7 ( V_12 ) ;
* V_8 = V_7 ;
goto V_22;
}
if ( F_8 ( V_6 -> V_20 ) && V_6 -> V_20 -> V_23 &&
! ( V_9 & V_24 ) ) {
error = - V_25 ;
goto V_22;
}
V_13 = V_11 . V_20 == V_10 . V_20 && V_11 . V_17 == V_10 . V_17 ;
if ( ! V_13 ) {
if ( V_11 . V_20 -> V_26 -> V_27 == V_28 &&
strncmp ( * V_8 , L_1 , 5 ) == 0 ) {
error = F_1 ( V_8 , * V_8 - V_7 , L_2 , 5 ) ;
} else if ( ! ( V_9 & V_29 ) &&
! ( ( ( V_9 & V_30 ) == V_30 ) &&
( V_11 . V_17 == V_15 -> V_18 -> V_19 -> V_10 &&
V_11 . V_20 == V_11 . V_17 -> V_21 ) ) ) {
error = - V_31 ;
if ( * V_12 == '/' )
* V_8 = V_12 + 1 ;
}
}
V_22:
F_9 ( & V_10 ) ;
return error ;
}
static int F_10 ( struct V_6 * V_6 , int V_9 , char * V_1 ,
int V_32 , char * * V_8 )
{
int V_33 = ( V_9 & V_34 ) ? 1 : 0 ;
int error = F_2 ( V_6 , V_1 , V_32 - V_33 , V_8 , V_9 ) ;
if ( ! error && ( V_9 & V_34 ) && ( * V_8 ) [ 1 ] != '\0' )
strcpy ( & V_1 [ V_32 - 2 ] , L_3 ) ;
return error ;
}
int F_11 ( struct V_6 * V_6 , int V_9 , char * * V_1 , const char * * V_8 )
{
char * V_7 , * V_3 = NULL ;
int V_32 = 256 ;
int error ;
* V_8 = NULL ;
* V_1 = NULL ;
for (; ; ) {
V_7 = F_12 ( V_32 , V_35 ) ;
if ( ! V_7 )
return - V_36 ;
error = F_10 ( V_6 , V_9 , V_7 , V_32 , & V_3 ) ;
if ( error != - V_5 )
break;
F_13 ( V_7 ) ;
V_32 <<= 1 ;
if ( V_32 > V_37 )
return - V_5 ;
}
* V_1 = V_7 ;
* V_8 = V_3 ;
return error ;
}
