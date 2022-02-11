static int F_1 ( void * V_1 , T_1 * V_2 )
{
struct V_3 * V_3 = V_1 ;
* V_2 = F_2 ( V_3 ) ;
return 0 ;
}
static int F_3 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_3 = V_1 ;
if ( V_2 )
return F_4 ( V_3 ) ;
else
F_5 ( V_3 ) ;
return 0 ;
}
static int F_6 ( void * V_1 , T_1 * V_2 )
{
struct V_3 * V_3 = V_1 ;
* V_2 = F_7 ( V_3 ) ;
return 0 ;
}
void F_8 ( struct V_3 * V_3 )
{
if ( ! V_4 )
return;
V_3 -> V_5 = F_9 ( V_3 -> V_6 , V_4 ) ;
F_10 ( L_1 , V_7 | V_8 , V_3 -> V_5 , V_3 ,
& V_9 ) ;
F_10 ( L_2 , V_8 , V_3 -> V_5 , V_3 ,
& V_10 ) ;
if ( V_3 -> V_11 ) {
char V_12 [ 100 ] ;
snprintf ( V_12 , 100 , L_3 , V_3 -> V_11 -> V_6 ) ;
V_3 -> V_13 = F_11 ( L_4 ,
V_3 -> V_5 ,
V_12 ) ;
}
}
void F_12 ( struct V_3 * V_3 )
{
if ( V_3 -> V_13 )
F_13 ( V_3 -> V_13 ) ;
if ( V_3 -> V_11 ) {
char V_12 [ 100 ] ;
snprintf ( V_12 , 100 , L_3 , V_3 -> V_11 -> V_6 ) ;
V_3 -> V_13 = F_11 ( L_4 ,
V_3 -> V_5 ,
V_12 ) ;
} else {
V_3 -> V_13 = NULL ;
}
}
void F_14 ( void )
{
V_4 = F_9 ( L_5 , NULL ) ;
if ( F_15 ( V_4 ) )
V_4 = NULL ;
}
