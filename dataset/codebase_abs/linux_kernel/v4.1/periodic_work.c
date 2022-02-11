static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 . V_2 ) ;
(* V_4 -> V_5 )( V_4 -> V_6 ) ;
}
struct V_3 * F_3 ( T_1 V_7 ,
struct V_8 * V_9 ,
void (* V_5)( void * ) ,
void * V_6 ,
const char * V_10 )
{
struct V_3 * V_4 ;
V_4 = F_4 ( sizeof( * V_4 ) , V_11 | V_12 ) ;
if ( ! V_4 )
return NULL ;
F_5 ( & V_4 -> V_13 ) ;
V_4 -> V_7 = V_7 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_10 = V_10 ;
return V_4 ;
}
void F_6 ( struct V_3 * V_4 )
{
F_7 ( V_4 ) ;
}
BOOL F_8 ( struct V_3 * V_4 )
{
BOOL V_14 = FALSE ;
F_9 ( & V_4 -> V_13 ) ;
if ( V_4 -> V_15 ) {
V_4 -> V_16 = FALSE ;
V_4 -> V_15 = FALSE ;
V_14 = TRUE ;
goto V_17;
} else if ( F_10 ( V_4 -> V_9 , & V_4 -> V_2 ,
V_4 -> V_7 ) < 0 ) {
V_4 -> V_16 = FALSE ;
V_14 = FALSE ;
goto V_17;
}
V_14 = TRUE ;
V_17:
F_11 ( & V_4 -> V_13 ) ;
return V_14 ;
}
BOOL F_12 ( struct V_3 * V_4 )
{
BOOL V_14 = FALSE ;
F_9 ( & V_4 -> V_13 ) ;
if ( V_4 -> V_16 ) {
V_14 = FALSE ;
goto V_17;
}
if ( V_4 -> V_15 ) {
V_14 = FALSE ;
goto V_17;
}
F_13 ( & V_4 -> V_2 , & F_1 ) ;
if ( F_10 ( V_4 -> V_9 , & V_4 -> V_2 ,
V_4 -> V_7 ) < 0 ) {
V_14 = FALSE ;
goto V_17;
}
V_4 -> V_16 = TRUE ;
V_14 = TRUE ;
V_17:
F_11 ( & V_4 -> V_13 ) ;
return V_14 ;
}
BOOL F_14 ( struct V_3 * V_4 )
{
BOOL V_18 = FALSE ;
F_9 ( & V_4 -> V_13 ) ;
V_18 = V_4 -> V_16 && ( ! V_4 -> V_15 ) ;
while ( V_4 -> V_16 ) {
V_4 -> V_15 = TRUE ;
if ( F_15 ( & V_4 -> V_2 ) ) {
F_16 ( ! V_4 -> V_16 ) ;
V_4 -> V_16 = FALSE ;
} else {
}
if ( V_4 -> V_16 ) {
F_11 ( & V_4 -> V_13 ) ;
F_17 ( 10 ) ;
F_9 ( & V_4 -> V_13 ) ;
} else {
V_4 -> V_15 = FALSE ;
}
}
F_11 ( & V_4 -> V_13 ) ;
return V_18 ;
}
