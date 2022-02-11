bool F_1 ( T_1 V_1 )
{
return V_1 . V_2 == V_3 ||
V_1 . V_2 == V_4 ||
V_1 . V_2 == V_5 ;
}
void F_2 ( T_2 * V_6 )
{
V_6 -> V_7 += F_3 ( V_6 -> V_8 ) ;
}
int F_4 ( struct V_9 * V_10 ,
struct V_9 * T_3 V_11 )
{
char * V_6 = V_10 -> V_12 ;
if ( * V_6 == '.' )
V_6 ++ ;
if ( strlen ( V_6 ) >= 3 && ! strncmp ( V_6 , L_1 , 3 ) )
return V_13 ;
if ( strlen ( V_6 ) >= 10 && ! strncmp ( V_6 , L_2 , 10 ) )
return V_13 ;
return V_14 ;
}
int F_5 ( const char * V_15 , const char * V_16 )
{
if ( * V_15 == '.' )
V_15 ++ ;
if ( * V_16 == '.' )
V_16 ++ ;
return strcmp ( V_15 , V_16 ) ;
}
bool F_6 ( void )
{
return true ;
}
void F_7 ( struct V_17 * V_18 ,
struct V_19 * V_20 , struct V_21 * V_21 )
{
if ( ! V_18 -> V_22 && V_21 -> V_23 -> V_24 == V_25 ) {
V_20 -> V_26 . V_27 += V_28 ;
V_20 -> V_26 . V_29 += V_28 ;
}
}
