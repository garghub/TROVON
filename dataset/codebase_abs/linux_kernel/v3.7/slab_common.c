static int F_1 ( const char * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = NULL ;
if ( ! V_1 || F_2 () || V_2 < sizeof( void * ) ||
V_2 > V_5 ) {
F_3 ( L_1 , V_1 ) ;
return - V_6 ;
}
F_4 (s, &slab_caches, list) {
char V_7 ;
int V_8 ;
V_8 = F_5 ( V_4 -> V_1 , V_7 ) ;
if ( V_8 ) {
F_3 ( L_2 ,
V_4 -> V_9 ) ;
continue;
}
if ( ! strcmp ( V_4 -> V_1 , V_1 ) ) {
F_3 ( L_3 ,
V_10 , V_1 ) ;
F_6 () ;
V_4 = NULL ;
return - V_6 ;
}
}
F_7 ( strchr ( V_1 , ' ' ) ) ;
return 0 ;
}
static inline int F_1 ( const char * V_1 , T_1 V_2 )
{
return 0 ;
}
struct V_3 * F_8 ( const char * V_1 , T_1 V_2 , T_1 V_11 ,
unsigned long V_12 , void (* F_9)( void * ) )
{
struct V_3 * V_4 = NULL ;
int V_13 = 0 ;
F_10 () ;
F_11 ( & V_14 ) ;
if ( ! F_1 ( V_1 , V_2 ) == 0 )
goto V_15;
V_4 = F_12 ( V_1 , V_2 , V_11 , V_12 , F_9 ) ;
if ( V_4 )
goto V_15;
V_4 = F_13 ( V_3 , V_16 ) ;
if ( V_4 ) {
V_4 -> V_9 = V_4 -> V_2 = V_2 ;
V_4 -> V_11 = V_11 ;
V_4 -> F_9 = F_9 ;
V_4 -> V_1 = F_14 ( V_1 , V_16 ) ;
if ( ! V_4 -> V_1 ) {
F_15 ( V_3 , V_4 ) ;
V_13 = - V_17 ;
goto V_15;
}
V_13 = F_16 ( V_4 , V_12 ) ;
if ( ! V_13 ) {
V_4 -> V_18 = 1 ;
F_17 ( & V_4 -> V_19 , & V_20 ) ;
} else {
F_18 ( V_4 -> V_1 ) ;
F_15 ( V_3 , V_4 ) ;
}
} else
V_13 = - V_17 ;
V_15:
F_19 ( & V_14 ) ;
F_20 () ;
if ( V_13 ) {
if ( V_12 & V_21 )
F_21 ( L_4 ,
V_1 , V_13 ) ;
else {
F_22 ( V_22 L_5 ,
V_1 , V_13 ) ;
F_6 () ;
}
return NULL ;
}
return V_4 ;
}
void F_23 ( struct V_3 * V_4 )
{
F_10 () ;
F_11 ( & V_14 ) ;
V_4 -> V_18 -- ;
if ( ! V_4 -> V_18 ) {
F_24 ( & V_4 -> V_19 ) ;
if ( ! F_25 ( V_4 ) ) {
F_19 ( & V_14 ) ;
if ( V_4 -> V_12 & V_23 )
F_26 () ;
F_18 ( V_4 -> V_1 ) ;
F_15 ( V_3 , V_4 ) ;
} else {
F_17 ( & V_4 -> V_19 , & V_20 ) ;
F_19 ( & V_14 ) ;
F_22 ( V_24 L_6 ,
V_4 -> V_1 ) ;
F_6 () ;
}
} else {
F_19 ( & V_14 ) ;
}
F_20 () ;
}
int F_27 ( void )
{
return V_25 >= V_26 ;
}
