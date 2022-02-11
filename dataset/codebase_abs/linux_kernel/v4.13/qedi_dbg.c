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
F_3 ( L_1 , F_4 ( & V_2 -> V_9 -> V_10 ) ,
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
F_6 ( L_1 , F_4 ( & V_2 -> V_9 -> V_10 ) ,
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
F_4 ( & V_2 -> V_9 -> V_10 ) , V_8 , line ,
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
F_10 ( L_1 , F_4 ( & V_2 -> V_9 -> V_10 ) ,
V_8 , line , V_2 -> V_11 , & V_7 ) ;
else
F_10 ( L_2 , V_8 , line , & V_7 ) ;
V_14:
va_end ( V_5 ) ;
}
int
F_11 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
int V_14 = 0 ;
for (; V_20 -> V_21 ; V_20 ++ ) {
V_14 = F_12 ( & V_18 -> V_22 . V_23 ,
V_20 -> V_24 ) ;
if ( V_14 )
F_3 ( L_3 ,
V_20 -> V_21 , V_14 ) ;
}
return V_14 ;
}
void
F_13 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
for (; V_20 -> V_21 ; V_20 ++ )
F_14 ( & V_18 -> V_22 . V_23 , V_20 -> V_24 ) ;
}
