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
F_7 ( struct V_1 * V_3 )
{
return 1 ;
}
int
F_8 ( struct V_1 * V_3 , int V_7 )
{
return 1 ;
}
int
F_9 ( struct V_1 * V_3 , int V_7 )
{
return 1 ;
}
int
F_10 ( struct V_1 * V_3 , int V_7 , int V_8 )
{
return 1 ;
}
void
F_11 ( struct V_1 * V_3 , int V_7 , int V_8 )
{
}
int
F_12 ( struct V_1 * V_3 , int V_7 , T_1 * V_9 )
{
return 1 ;
}
void
F_13 ( struct V_1 * V_3 , int V_7 , T_1 * V_9 )
{
}
int
F_14 ( struct V_1 * V_3 , int V_7 , int V_10 )
{
return 1 ;
}
void
F_15 ( struct V_1 * V_3 , int V_7 , int V_10 )
{
}
int
F_16 ( struct V_1 * V_3 , int V_7 , T_2 * V_9 )
{
return 1 ;
}
void
F_17 ( struct V_1 * V_3 , int V_7 , T_2 * V_9 )
{
}
void
F_18 ( struct V_1 * V_3 , int V_7 )
{
}
int
F_19 ( struct V_1 * V_3 , int V_7 )
{
return 0 ;
}
int
F_20 ( struct V_1 * V_3 , int V_11 )
{
return 0 ;
}
int
F_21 ( struct V_1 * V_3 , int V_8 )
{
return 0 ;
}
int
F_22 ( struct V_1 * V_3 , int V_7 )
{
return 0 ;
}
void
F_23 ( void )
{
if ( V_1 != NULL ) {
F_4 ( V_1 ) ;
V_1 = NULL ;
}
}
int
F_24 ( void )
{
V_1 = F_1 ( 1 ) ;
return V_1 != NULL ? 0 : - 1 ;
}
