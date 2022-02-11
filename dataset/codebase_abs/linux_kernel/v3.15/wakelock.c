T_1 F_1 ( char * V_1 , bool V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
char * V_7 = V_1 ;
char * V_8 = V_1 + V_9 ;
F_2 ( & V_10 ) ;
for ( V_4 = F_3 ( & V_11 ) ; V_4 ; V_4 = F_4 ( V_4 ) ) {
V_6 = F_5 ( V_4 , struct V_5 , V_4 ) ;
if ( V_6 -> V_12 . V_13 == V_2 )
V_7 += F_6 ( V_7 , V_8 - V_7 , L_1 , V_6 -> V_14 ) ;
}
if ( V_7 > V_1 )
V_7 -- ;
V_7 += F_6 ( V_7 , V_8 - V_7 , L_2 ) ;
F_7 ( & V_10 ) ;
return ( V_7 - V_1 ) ;
}
static inline bool F_8 ( void )
{
return V_15 > V_16 ;
}
static inline void F_9 ( void )
{
V_15 ++ ;
}
static inline void F_10 ( void )
{
V_15 -- ;
}
static inline bool F_8 ( void ) { return false ; }
static inline void F_9 ( void ) {}
static inline void F_10 ( void ) {}
static inline void F_11 ( struct V_5 * V_6 )
{
F_12 ( & V_6 -> V_17 , & V_18 ) ;
}
static inline void F_13 ( struct V_5 * V_6 )
{
F_14 ( & V_6 -> V_17 , & V_18 ) ;
}
static void F_15 ( void )
{
struct V_5 * V_6 , * V_19 ;
T_2 V_20 ;
if ( ++ V_21 <= V_22 )
return;
V_20 = F_16 () ;
F_17 (wl, aux, &wakelocks_lru_list, lru) {
T_3 V_23 ;
bool V_13 ;
F_18 ( & V_6 -> V_12 . V_24 ) ;
V_23 = F_19 ( F_20 ( V_20 , V_6 -> V_12 . V_25 ) ) ;
V_13 = V_6 -> V_12 . V_13 ;
F_21 ( & V_6 -> V_12 . V_24 ) ;
if ( V_23 < ( ( T_3 ) V_26 * V_27 ) )
break;
if ( ! V_13 ) {
F_22 ( & V_6 -> V_12 ) ;
F_23 ( & V_6 -> V_4 , & V_11 ) ;
F_24 ( & V_6 -> V_17 ) ;
F_25 ( V_6 -> V_14 ) ;
F_25 ( V_6 ) ;
F_10 () ;
}
}
V_21 = 0 ;
}
static inline void F_11 ( struct V_5 * V_6 ) {}
static inline void F_13 ( struct V_5 * V_6 ) {}
static inline void F_15 ( void ) {}
static struct V_5 * F_26 ( const char * V_14 , T_4 V_28 ,
bool V_29 )
{
struct V_3 * * V_4 = & V_11 . V_3 ;
struct V_3 * V_30 = * V_4 ;
struct V_5 * V_6 ;
while ( * V_4 ) {
int V_31 ;
V_30 = * V_4 ;
V_6 = F_5 ( * V_4 , struct V_5 , V_4 ) ;
V_31 = strncmp ( V_14 , V_6 -> V_14 , V_28 ) ;
if ( V_31 == 0 ) {
if ( V_6 -> V_14 [ V_28 ] )
V_31 = - 1 ;
else
return V_6 ;
}
if ( V_31 < 0 )
V_4 = & ( * V_4 ) -> V_32 ;
else
V_4 = & ( * V_4 ) -> V_33 ;
}
if ( ! V_29 )
return F_27 ( - V_34 ) ;
if ( F_8 () )
return F_27 ( - V_35 ) ;
V_6 = F_28 ( sizeof( * V_6 ) , V_36 ) ;
if ( ! V_6 )
return F_27 ( - V_37 ) ;
V_6 -> V_14 = F_29 ( V_14 , V_28 , V_36 ) ;
if ( ! V_6 -> V_14 ) {
F_25 ( V_6 ) ;
return F_27 ( - V_37 ) ;
}
V_6 -> V_12 . V_14 = V_6 -> V_14 ;
F_30 ( & V_6 -> V_12 ) ;
F_31 ( & V_6 -> V_4 , V_30 , V_4 ) ;
F_32 ( & V_6 -> V_4 , & V_11 ) ;
F_11 ( V_6 ) ;
F_9 () ;
return V_6 ;
}
int F_33 ( const char * V_1 )
{
const char * V_7 = V_1 ;
struct V_5 * V_6 ;
T_3 V_38 = 0 ;
T_4 V_28 ;
int V_39 = 0 ;
if ( ! F_34 ( V_40 ) )
return - V_41 ;
while ( * V_7 && ! isspace ( * V_7 ) )
V_7 ++ ;
V_28 = V_7 - V_1 ;
if ( ! V_28 )
return - V_34 ;
if ( * V_7 && * V_7 != '\n' ) {
V_39 = F_35 ( F_36 ( V_7 ) , 10 , & V_38 ) ;
if ( V_39 )
return - V_34 ;
}
F_2 ( & V_10 ) ;
V_6 = F_26 ( V_1 , V_28 , true ) ;
if ( F_37 ( V_6 ) ) {
V_39 = F_38 ( V_6 ) ;
goto V_42;
}
if ( V_38 ) {
T_3 V_43 = V_38 + V_44 - 1 ;
F_39 ( V_43 , V_44 ) ;
F_40 ( & V_6 -> V_12 , V_43 ) ;
} else {
F_41 ( & V_6 -> V_12 ) ;
}
F_13 ( V_6 ) ;
V_42:
F_7 ( & V_10 ) ;
return V_39 ;
}
int F_42 ( const char * V_1 )
{
struct V_5 * V_6 ;
T_4 V_28 ;
int V_39 = 0 ;
if ( ! F_34 ( V_40 ) )
return - V_41 ;
V_28 = strlen ( V_1 ) ;
if ( ! V_28 )
return - V_34 ;
if ( V_1 [ V_28 - 1 ] == '\n' )
V_28 -- ;
if ( ! V_28 )
return - V_34 ;
F_2 ( & V_10 ) ;
V_6 = F_26 ( V_1 , V_28 , false ) ;
if ( F_37 ( V_6 ) ) {
V_39 = F_38 ( V_6 ) ;
goto V_42;
}
F_43 ( & V_6 -> V_12 ) ;
F_13 ( V_6 ) ;
F_15 () ;
V_42:
F_7 ( & V_10 ) ;
return V_39 ;
}
