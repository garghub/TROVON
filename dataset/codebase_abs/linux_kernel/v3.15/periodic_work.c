static void F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 =
F_2 ( V_2 , struct V_4 , V_2 . V_2 ) ;
(* V_3 -> V_5 )( V_3 -> V_6 ) ;
}
T_1 * F_3 ( T_2 V_7 ,
struct V_8 * V_9 ,
void (* V_5)( void * ) ,
void * V_6 ,
const char * V_10 )
{
T_1 * V_3 = F_4 ( sizeof( T_1 ) ,
V_11 | V_12 ) ;
if ( V_3 == NULL ) {
F_5 ( L_1 ) ;
return NULL ;
}
F_6 ( & V_3 -> V_13 ) ;
V_3 -> V_7 = V_7 ;
V_3 -> V_9 = V_9 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_10 = V_10 ;
return V_3 ;
}
void F_7 ( T_1 * V_3 )
{
if ( V_3 == NULL )
return;
F_8 ( V_3 ) ;
}
BOOL F_9 ( T_1 * V_3 )
{
BOOL V_14 = FALSE ;
F_10 ( & V_3 -> V_13 ) ;
if ( V_3 -> V_15 ) {
V_3 -> V_16 = FALSE ;
V_3 -> V_15 = FALSE ;
V_14 = TRUE ;
goto V_17;
} else if ( F_11 ( V_3 -> V_9 ,
& V_3 -> V_2 ,
V_3 -> V_7 ) < 0 ) {
F_12 ( V_3 -> V_10 , L_2 ) ;
V_3 -> V_16 = FALSE ;
V_14 = FALSE ;
goto V_17;
}
V_14 = TRUE ;
V_17:
F_13 ( & V_3 -> V_13 ) ;
return V_14 ;
}
BOOL F_14 ( T_1 * V_3 )
{
BOOL V_14 = FALSE ;
F_10 ( & V_3 -> V_13 ) ;
if ( V_3 -> V_16 ) {
V_14 = FALSE ;
goto V_17;
}
if ( V_3 -> V_15 ) {
F_12 ( V_3 -> V_10 ,
L_3 ) ;
V_14 = FALSE ;
goto V_17;
}
F_15 ( & V_3 -> V_2 , & F_1 ) ;
if ( F_11 ( V_3 -> V_9 ,
& V_3 -> V_2 ,
V_3 -> V_7 ) < 0 ) {
F_12 ( V_3 -> V_10 ,
L_4 , V_18 ) ;
V_14 = FALSE ;
goto V_17;
}
V_3 -> V_16 = TRUE ;
V_14 = TRUE ;
V_17:
F_13 ( & V_3 -> V_13 ) ;
return V_14 ;
}
BOOL F_16 ( T_1 * V_3 )
{
BOOL V_19 = FALSE ;
F_10 ( & V_3 -> V_13 ) ;
V_19 = V_3 -> V_16 &&
( ! V_3 -> V_15 ) ;
while ( V_3 -> V_16 ) {
V_3 -> V_15 = TRUE ;
if ( F_17 ( & V_3 -> V_2 ) ) {
ASSERT ( V_3 -> V_16 ) ;
V_3 -> V_16 = FALSE ;
} else {
}
if ( V_3 -> V_16 ) {
F_13 ( & V_3 -> V_13 ) ;
F_18 ( V_3 -> V_10 ,
L_5 ) ;
F_19 ( 10 ) ;
F_10 ( & V_3 -> V_13 ) ;
} else
V_3 -> V_15 = FALSE ;
}
F_13 ( & V_3 -> V_13 ) ;
return V_19 ;
}
