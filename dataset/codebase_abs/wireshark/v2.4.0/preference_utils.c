void
F_1 ( void )
{
#ifdef F_2
V_1 . V_2 . V_3 = V_4 . V_5 ;
V_1 . V_6 = V_4 . V_7 ;
V_1 . V_8 = V_4 . V_9 ;
V_1 . V_10 = V_4 . V_11 ;
V_12 = V_4 . V_13 ;
#endif
}
void
F_3 ( void )
{
int V_14 ;
char * V_15 ;
char * V_16 ;
if ( F_4 ( & V_15 ) == - 1 ) {
F_5 ( V_17 , V_18 ,
L_1 , V_15 ,
F_6 ( V_19 ) ) ;
F_7 ( V_15 ) ;
} else {
V_14 = F_8 ( & V_16 ) ;
if ( V_14 != 0 ) {
F_5 ( V_17 , V_18 ,
L_2 , V_16 ,
F_6 ( V_14 ) ) ;
F_7 ( V_16 ) ;
}
}
}
static T_1
F_9 ( const char * V_20 , const char * V_21 , const char * V_22 )
{
T_2 * V_23 = NULL ;
T_3 * V_24 = NULL ;
T_1 V_25 = TRUE ;
if ( ! F_10 ( V_20 ) )
return FALSE ;
V_23 = F_11 ( V_20 ) ;
if ( ! V_23 )
return FALSE ;
V_24 = F_12 ( V_23 , V_21 ) ;
if ( ! V_24 )
return FALSE ;
if ( F_13 ( V_24 ) == V_26 )
{
V_25 = F_14 ( V_24 , V_22 , V_27 ) ;
if ( ! V_25 || F_15 ( V_24 , V_27 ) != 0 )
V_25 = F_14 ( V_24 , V_22 , V_28 ) ;
}
return V_25 ;
}
T_1
F_16 ( const char * V_20 , const char * V_21 , const char * V_22 )
{
if ( F_9 ( V_20 , V_21 , V_22 ) )
{
F_3 () ;
F_17 () ;
F_1 () ;
return TRUE ;
}
return FALSE ;
}
T_1
F_18 ( const char * V_23 , T_4 * V_29 )
{
T_1 V_25 = FALSE ;
T_5 * V_30 = NULL ;
if ( ! F_10 ( V_23 ) )
return V_25 ;
V_30 = F_19 ( V_29 ) ;
if ( ! V_30 )
return V_25 ;
while ( V_30 != NULL )
{
T_6 * V_21 = ( T_6 * ) V_30 -> V_31 ;
T_6 * V_22 = ( T_6 * ) F_20 ( V_29 , V_30 -> V_31 ) ;
if ( V_21 && V_22 )
{
if ( F_9 ( V_23 , V_21 , V_22 ) )
V_25 = TRUE ;
}
V_30 = F_21 ( V_30 ) ;
}
if ( V_25 )
{
F_3 () ;
F_17 () ;
F_1 () ;
}
return TRUE ;
}
T_7
F_22 ( T_7 V_32 , const T_6 * V_33 , const T_6 * V_34 , T_7 V_35 )
{
T_5 * V_36 ;
T_8 * V_37 , * V_38 ;
T_7 V_39 ;
V_37 = ( T_8 * ) F_23 ( sizeof( T_8 ) ) ;
V_37 -> V_33 = F_24 ( V_33 ) ;
V_37 -> V_32 = V_32 ;
V_37 -> V_34 = F_24 ( V_34 ) ;
V_37 -> V_35 = V_35 ;
V_37 -> V_40 = TRUE ;
V_39 = F_25 ( V_4 . V_41 ) ;
if ( V_34 ) {
V_37 -> V_42 = TRUE ;
V_36 = F_26 ( V_4 . V_41 ) ;
V_38 = ( T_8 * ) V_36 -> V_31 ;
if ( V_38 -> V_32 == V_43 ) {
V_39 -= 1 ;
V_4 . V_41 = F_27 ( V_4 . V_41 , V_37 , V_39 ) ;
} else {
V_4 . V_41 = F_28 ( V_4 . V_41 , V_37 ) ;
}
} else {
V_37 -> V_42 = FALSE ;
V_4 . V_41 = F_28 ( V_4 . V_41 , V_37 ) ;
}
return V_39 ;
}
void
F_29 ( T_5 * V_44 )
{
T_8 * V_37 ;
if ( ! V_44 || ! V_44 -> V_31 ) return;
V_37 = ( T_8 * ) V_44 -> V_31 ;
F_7 ( V_37 -> V_33 ) ;
F_7 ( V_37 -> V_34 ) ;
F_7 ( V_37 ) ;
V_4 . V_41 = F_30 ( V_4 . V_41 , V_44 ) ;
}
void
F_31 ( T_7 V_45 )
{
F_29 ( F_32 ( V_4 . V_41 , V_45 ) ) ;
}
