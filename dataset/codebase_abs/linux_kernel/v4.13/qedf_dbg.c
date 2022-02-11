void
F_1 ( struct V_1 * V_2 , const char * V_3 , T_1 line ,
const char * V_4 , ... )
{
T_2 V_5 ;
struct V_6 V_7 ;
char V_8 [ 32 ] ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
memcpy ( V_8 , V_3 , sizeof( V_8 ) - 1 ) ;
va_start ( V_5 , V_4 ) ;
V_7 . V_4 = V_4 ;
V_7 . V_5 = & V_5 ;
if ( F_2 ( V_2 ) && F_2 ( V_2 -> V_9 ) )
F_3 ( L_1 , F_4 ( & ( V_2 -> V_9 -> V_10 ) ) ,
V_8 , line , V_2 -> V_11 , & V_7 ) ;
else
F_3 ( L_2 , V_8 , line , & V_7 ) ;
va_end ( V_5 ) ;
}
void
F_5 ( struct V_1 * V_2 , const char * V_3 , T_1 line ,
const char * V_4 , ... )
{
T_2 V_5 ;
struct V_6 V_7 ;
char V_8 [ 32 ] ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
memcpy ( V_8 , V_3 , sizeof( V_8 ) - 1 ) ;
va_start ( V_5 , V_4 ) ;
V_7 . V_4 = V_4 ;
V_7 . V_5 = & V_5 ;
if ( ! ( V_12 & V_13 ) )
goto V_14;
if ( F_2 ( V_2 ) && F_2 ( V_2 -> V_9 ) )
F_6 ( L_1 , F_4 ( & ( V_2 -> V_9 -> V_10 ) ) ,
V_8 , line , V_2 -> V_11 , & V_7 ) ;
else
F_6 ( L_2 , V_8 , line , & V_7 ) ;
V_14:
va_end ( V_5 ) ;
}
void
F_7 ( struct V_1 * V_2 , const char * V_3 , T_1 line ,
const char * V_4 , ... )
{
T_2 V_5 ;
struct V_6 V_7 ;
char V_8 [ 32 ] ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
memcpy ( V_8 , V_3 , sizeof( V_8 ) - 1 ) ;
va_start ( V_5 , V_4 ) ;
V_7 . V_4 = V_4 ;
V_7 . V_5 = & V_5 ;
if ( ! ( V_12 & V_15 ) )
goto V_14;
if ( F_2 ( V_2 ) && F_2 ( V_2 -> V_9 ) )
F_8 ( L_1 ,
F_4 ( & ( V_2 -> V_9 -> V_10 ) ) , V_8 , line ,
V_2 -> V_11 , & V_7 ) ;
else
F_8 ( L_2 , V_8 , line , & V_7 ) ;
V_14:
va_end ( V_5 ) ;
}
void
F_9 ( struct V_1 * V_2 , const char * V_3 , T_1 line ,
T_1 V_16 , const char * V_4 , ... )
{
T_2 V_5 ;
struct V_6 V_7 ;
char V_8 [ 32 ] ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
memcpy ( V_8 , V_3 , sizeof( V_8 ) - 1 ) ;
va_start ( V_5 , V_4 ) ;
V_7 . V_4 = V_4 ;
V_7 . V_5 = & V_5 ;
if ( ! ( V_12 & V_16 ) )
goto V_14;
if ( F_2 ( V_2 ) && F_2 ( V_2 -> V_9 ) )
F_10 ( L_1 , F_4 ( & ( V_2 -> V_9 -> V_10 ) ) ,
V_8 , line , V_2 -> V_11 , & V_7 ) ;
else
F_10 ( L_2 , V_8 , line , & V_7 ) ;
V_14:
va_end ( V_5 ) ;
}
int
F_11 ( T_3 * * V_17 , T_4 V_18 )
{
* V_17 = F_12 ( V_18 ) ;
if ( ! ( * V_17 ) )
return - V_19 ;
memset ( * V_17 , 0 , V_18 ) ;
return 0 ;
}
void
F_13 ( T_5 * * V_17 )
{
F_14 ( * V_17 ) ;
* V_17 = NULL ;
}
int
F_15 ( struct V_20 * V_21 , const struct V_22 * V_23 ,
T_3 * * V_17 , T_4 * V_24 )
{
if ( ! * V_17 )
return - V_25 ;
return V_23 -> V_26 ( V_21 , * V_17 , V_24 ) ;
}
void
F_16 ( struct V_27 * V_28 , T_1 V_29 , char * V_30 )
{
char V_31 [ 40 ] ;
char * V_32 [] = { V_31 , NULL } ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
switch ( V_29 ) {
case V_33 :
if ( V_30 )
strncpy ( V_31 , V_30 , strlen ( V_30 ) ) ;
else
sprintf ( V_31 , L_3 , V_28 -> V_11 ) ;
break;
default:
break;
}
F_17 ( & V_28 -> V_34 . V_35 , V_36 , V_32 ) ;
}
int
F_18 ( struct V_27 * V_28 , struct V_37 * V_38 )
{
int V_14 = 0 ;
for (; V_38 -> V_39 ; V_38 ++ ) {
V_14 = F_19 ( & V_28 -> V_34 . V_35 ,
V_38 -> V_40 ) ;
if ( V_14 )
F_3 ( L_4 ,
V_38 -> V_39 , V_14 ) ;
}
return V_14 ;
}
void
F_20 ( struct V_27 * V_28 , struct V_37 * V_38 )
{
for (; V_38 -> V_39 ; V_38 ++ )
F_21 ( & V_28 -> V_34 . V_35 , V_38 -> V_40 ) ;
}
