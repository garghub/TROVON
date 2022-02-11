static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 ) ;
}
static struct V_1 * F_3 ( const char * V_4 ,
const char * V_5 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_6 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_3 = F_4 ( V_7 + V_8 +
F_5 ( V_5 ) , V_6 ) ;
if ( ! V_2 -> V_3 ) {
F_2 ( V_2 ) ;
return NULL ;
}
V_2 -> V_9 [ 0 ] = V_2 -> V_3 ;
V_2 -> V_9 [ 1 ] = V_2 -> V_9 [ 0 ] + V_7 ;
V_2 -> V_9 [ 2 ] = V_2 -> V_9 [ 1 ] + V_8 ;
V_2 -> V_9 [ 3 ] = NULL ;
snprintf ( V_2 -> V_9 [ 0 ] , V_7 , V_10 L_1 , V_4 ) ;
snprintf ( V_2 -> V_9 [ 1 ] , V_8 , V_11 L_1 , V_12 ) ;
snprintf ( V_2 -> V_9 [ 2 ] , F_5 ( V_5 ) , V_13 L_1 , V_5 ) ;
return V_2 ;
}
static void F_6 ( struct V_14 * V_15 )
{
F_7 ( V_16 ) ;
struct V_1 * V_17 , * V_18 ;
struct V_19 * V_20 ;
V_20 = F_8 ( V_21 ) ;
if ( ! V_20 )
return;
F_9 ( & V_22 ) ;
F_10 ( & V_23 , & V_16 ) ;
F_11 ( & V_22 ) ;
F_12 (p, n, &event_queue, list) {
F_13 ( & V_17 -> V_24 ) ;
F_14 ( & V_20 -> V_25 , V_26 , V_17 -> V_9 ) ;
F_1 ( V_17 ) ;
}
F_15 ( V_20 ) ;
}
static void F_16 ( const char * V_4 , char * V_5 )
{
struct V_1 * V_27 ;
if ( V_28 && strlen ( V_28 ) > 0 && strcmp ( V_4 , V_28 ) != 0 )
return;
V_5 += strlen ( V_12 ) ;
while ( * V_5 && isspace ( * V_5 ) )
V_5 ++ ;
if ( * V_5 == '\0' )
return;
V_27 = F_3 ( V_4 , V_5 ) ;
if ( ! V_27 )
return;
F_17 ( & V_22 ) ;
F_18 ( & V_27 -> V_24 , & V_23 ) ;
F_19 ( & V_22 ) ;
F_20 ( & V_29 ) ;
return;
}
static int T_1 F_21 ( void )
{
struct V_30 * V_31 ;
int V_32 ;
if ( ! V_33 )
return - V_34 ;
V_21 = F_4 ( sizeof( * V_21 ) , V_35 ) ;
if ( ! V_21 )
return - V_36 ;
V_31 = F_22 ( V_37 , & V_38 ) ;
if ( ! V_31 ) {
F_2 ( V_21 ) ;
return - V_34 ;
}
V_32 = F_23 ( V_21 , V_39 ) ;
if ( V_32 ) {
F_2 ( V_21 ) ;
goto V_40;
}
V_21 -> V_41 = & V_38 ;
V_21 -> V_42 = V_43 ;
V_21 -> V_44 = ( void ( * ) ( struct V_19 * ) ) F_2 ;
V_21 -> V_45 = V_31 ;
V_32 = F_24 ( V_21 ) ;
if ( V_32 ) {
F_15 ( V_21 ) ;
goto V_40;
}
if ( V_28 ) {
int V_46 = strlen ( V_28 ) ;
while ( V_46 -- )
V_28 [ V_46 ] = toupper ( V_28 [ V_46 ] ) ;
}
V_32 = F_25 ( V_12 , F_16 ) ;
if ( V_32 ) {
F_26 ( V_21 ) ;
goto V_40;
}
V_32 = 0 ;
V_40:
return V_32 ;
}
static void T_2 F_27 ( void )
{
F_28 ( V_12 , F_16 ) ;
F_29 ( & V_29 ) ;
F_6 ( & V_29 ) ;
F_26 ( V_21 ) ;
}
