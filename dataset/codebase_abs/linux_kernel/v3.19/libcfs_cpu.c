struct V_1 *
F_1 ( unsigned int V_2 )
{
struct V_1 * V_3 ;
if ( V_2 != 1 ) {
F_2 ( L_1 , V_2 ) ;
return NULL ;
}
F_3 ( V_3 , sizeof( * V_3 ) ) ;
if ( V_3 != NULL ) {
V_3 -> V_4 = V_5 ;
V_3 -> V_6 = V_2 ;
}
return V_3 ;
}
void
F_4 ( struct V_1 * V_3 )
{
F_5 ( V_3 -> V_4 == V_5 ) ;
F_6 ( V_3 , sizeof( * V_3 ) ) ;
}
int
F_7 ( struct V_1 * V_3 , char * V_7 , int V_8 )
{
int V_9 = 0 ;
V_9 = snprintf ( V_7 , V_8 , L_2 , 0 , 0 ) ;
V_8 -= V_9 ;
if ( V_8 <= 0 )
return - V_10 ;
return V_9 ;
}
int
F_8 ( struct V_1 * V_3 )
{
return 1 ;
}
int
F_9 ( struct V_1 * V_3 , int V_11 )
{
return 1 ;
}
int
F_10 ( struct V_1 * V_3 , int V_11 )
{
return 1 ;
}
int
F_11 ( struct V_1 * V_3 , int V_11 , int V_12 )
{
return 1 ;
}
void
F_12 ( struct V_1 * V_3 , int V_11 , int V_12 )
{
}
int
F_13 ( struct V_1 * V_3 , int V_11 , T_1 * V_13 )
{
return 1 ;
}
void
F_14 ( struct V_1 * V_3 , int V_11 , T_1 * V_13 )
{
}
int
F_15 ( struct V_1 * V_3 , int V_11 , int V_14 )
{
return 1 ;
}
void
F_16 ( struct V_1 * V_3 , int V_11 , int V_14 )
{
}
int
F_17 ( struct V_1 * V_3 , int V_11 , T_2 * V_13 )
{
return 1 ;
}
void
F_18 ( struct V_1 * V_3 , int V_11 , T_2 * V_13 )
{
}
void
F_19 ( struct V_1 * V_3 , int V_11 )
{
}
int
F_20 ( struct V_1 * V_3 , int V_11 )
{
return 0 ;
}
int
F_21 ( int V_12 )
{
return 1 ;
}
int
F_22 ( struct V_1 * V_3 , int V_15 )
{
return 0 ;
}
int
F_23 ( struct V_1 * V_3 , int V_12 )
{
return 0 ;
}
int
F_24 ( struct V_1 * V_3 , int V_11 )
{
return 0 ;
}
void
F_25 ( void )
{
if ( V_1 != NULL ) {
F_4 ( V_1 ) ;
V_1 = NULL ;
}
}
int
F_26 ( void )
{
V_1 = F_1 ( 1 ) ;
return V_1 != NULL ? 0 : - 1 ;
}
