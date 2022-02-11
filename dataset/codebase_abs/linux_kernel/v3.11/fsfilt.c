static struct V_1 * F_1 ( const char * type )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
F_2 (p, &fsfilt_types) {
V_2 = F_3 ( V_4 , struct V_1 , V_5 ) ;
if ( ! strcmp ( V_2 -> V_6 , type ) ) {
return V_2 ;
}
}
return NULL ;
}
int F_4 ( struct V_1 * V_7 )
{
struct V_1 * V_2 ;
if ( ( V_2 = F_1 ( V_7 -> V_6 ) ) ) {
if ( V_2 != V_7 ) {
F_5 ( L_1 ,
V_7 -> V_6 ) ;
RETURN ( - V_8 ) ;
}
} else {
F_6 ( V_9 ) ;
F_7 ( & V_7 -> V_5 , & V_10 ) ;
}
return 0 ;
}
void F_8 ( struct V_1 * V_7 )
{
struct V_3 * V_4 ;
F_2 (p, &fsfilt_types) {
struct V_1 * V_2 ;
V_2 = F_3 ( V_4 , F_9 ( * V_2 ) , V_5 ) ;
if ( V_2 == V_7 ) {
F_10 ( V_4 ) ;
F_11 ( V_9 ) ;
break;
}
}
}
struct V_1 * F_12 ( const char * type )
{
struct V_1 * V_7 ;
if ( ! ( V_7 = F_1 ( type ) ) ) {
char V_11 [ 32 ] ;
int V_12 ;
snprintf ( V_11 , sizeof( V_11 ) - 1 , L_2 , type ) ;
V_11 [ sizeof( V_11 ) - 1 ] = '\0' ;
if ( ! ( V_12 = F_13 ( L_3 , V_11 ) ) ) {
V_7 = F_1 ( type ) ;
F_14 ( V_13 , L_4 , V_11 ) ;
if ( ! V_7 )
V_12 = - V_14 ;
}
if ( V_12 ) {
F_5 ( L_5 , V_11 ) ;
RETURN ( F_15 ( V_12 < 0 ? V_12 : - V_12 ) ) ;
}
}
F_6 ( V_7 -> V_15 ) ;
return V_7 ;
}
void F_16 ( struct V_1 * V_7 )
{
F_11 ( V_7 -> V_15 ) ;
}
