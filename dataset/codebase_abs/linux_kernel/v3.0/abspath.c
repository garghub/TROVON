static const char * F_1 ( void )
{
static char V_1 [ V_2 + 1 ] ;
char * V_3 ;
struct V_4 V_5 , V_6 ;
if ( F_2 ( V_1 , V_2 ) == NULL )
return NULL ;
V_3 = getenv ( L_1 ) ;
if ( V_3 && strcmp ( V_3 , V_1 ) ) {
V_4 ( V_1 , & V_5 ) ;
if ( ! V_4 ( V_3 , & V_6 ) &&
V_6 . V_7 == V_5 . V_7 &&
V_6 . V_8 == V_5 . V_8 ) {
F_3 ( V_1 , V_3 , V_2 ) ;
}
}
return V_1 ;
}
const char * F_4 ( const char * V_9 )
{
static char V_10 [ V_2 + 1 ] ;
if ( F_5 ( V_9 ) ) {
if ( F_3 ( V_10 , V_9 , V_2 ) >= V_2 )
F_6 ( L_2 , 60 , V_9 ) ;
} else {
const char * V_1 = F_1 () ;
if ( ! V_1 )
F_6 ( L_3 ) ;
if ( snprintf ( V_10 , V_2 , L_4 , V_1 , V_9 ) >= V_2 )
F_6 ( L_2 , 60 , V_9 ) ;
}
return V_10 ;
}
