void F_1 ( const struct V_1 * V_2 , const char * V_3 , ... )
{
struct V_4 V_5 ;
T_1 args ;
if ( F_2 ( ! ( V_6 & V_7 ) ) )
return;
va_start ( args , V_3 ) ;
V_5 . V_3 = V_3 ;
V_5 . V_8 = & args ;
if ( V_2 && V_2 -> V_9 && V_2 -> V_9 -> V_10 &&
V_2 -> V_9 -> V_10 -> V_11 )
F_3 ( V_12 , V_2 -> V_9 -> V_10 -> V_11 ,
V_13 L_1 ,
V_2 -> V_14 , & V_5 ) ;
else
F_4 ( L_2 , & V_5 ) ;
va_end ( args ) ;
}
void F_5 ( const struct V_15 * V_16 , const char * V_3 , ... )
{
struct V_4 V_5 ;
T_1 args ;
if ( F_2 ( ! ( V_6 & V_17 ) ) )
return;
va_start ( args , V_3 ) ;
V_5 . V_3 = V_3 ;
V_5 . V_8 = & args ;
if ( V_16 && V_16 -> V_9 && V_16 -> V_9 -> V_10 && V_16 -> V_9 -> V_10 -> V_11 &&
V_16 -> V_18 )
F_3 ( V_12 , V_16 -> V_9 -> V_10 -> V_11 ,
V_13 L_3 ,
V_16 -> V_18 -> V_19 , & V_5 ) ;
else
F_4 ( L_2 , & V_5 ) ;
va_end ( args ) ;
}
void F_6 ( const struct V_20 * V_10 , const char * V_3 , ... )
{
struct V_4 V_5 ;
T_1 args ;
if ( F_2 ( ! ( V_6 & V_21 ) ) )
return;
va_start ( args , V_3 ) ;
V_5 . V_3 = V_3 ;
V_5 . V_8 = & args ;
if ( V_10 && V_10 -> V_11 )
F_3 ( V_12 , V_10 -> V_11 , V_13 L_4 , & V_5 ) ;
else
F_4 ( L_2 , & V_5 ) ;
va_end ( args ) ;
}
