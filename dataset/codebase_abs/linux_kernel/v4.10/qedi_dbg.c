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
return;
if ( F_2 ( V_2 ) && F_2 ( V_2 -> V_9 ) )
F_6 ( L_1 , F_4 ( & V_2 -> V_9 -> V_10 ) ,
V_8 , line , V_2 -> V_11 , & V_7 ) ;
else
F_6 ( L_2 , V_8 , line , & V_7 ) ;
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
if ( ! ( V_12 & V_14 ) )
return;
if ( F_2 ( V_2 ) && F_2 ( V_2 -> V_9 ) )
F_8 ( L_1 ,
F_4 ( & V_2 -> V_9 -> V_10 ) , V_8 , line ,
V_2 -> V_11 , & V_7 ) ;
else
F_8 ( L_2 , V_8 , line , & V_7 ) ;
va_end ( V_5 ) ;
}
void
F_9 ( struct V_1 * V_2 , const char * V_3 , T_1 line ,
T_1 V_15 , const char * V_4 , ... )
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
return;
if ( F_2 ( V_2 ) && F_2 ( V_2 -> V_9 ) )
F_10 ( L_1 , F_4 ( & V_2 -> V_9 -> V_10 ) ,
V_8 , line , V_2 -> V_11 , & V_7 ) ;
else
F_10 ( L_2 , V_8 , line , & V_7 ) ;
va_end ( V_5 ) ;
}
int
F_11 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
int V_20 = 0 ;
for (; V_19 -> V_21 ; V_19 ++ ) {
V_20 = F_12 ( & V_17 -> V_22 . V_23 ,
V_19 -> V_24 ) ;
if ( V_20 )
F_3 ( L_3 ,
V_19 -> V_21 , V_20 ) ;
}
return V_20 ;
}
void
F_13 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
for (; V_19 -> V_21 ; V_19 ++ )
F_14 ( & V_17 -> V_22 . V_23 , V_19 -> V_24 ) ;
}
