int F_1 ( void * V_1 , T_1 V_2 , unsigned char V_3 ,
const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
V_7 -> V_8 = F_2 ( V_4 , V_5 ) ;
if ( ! V_7 -> V_8 )
return - V_9 ;
if ( V_10 && ( F_3 ( V_7 -> V_8 ) != 256 &&
F_3 ( V_7 -> V_8 ) != 384 ) ) {
F_4 ( L_1 ) ;
F_5 ( V_7 -> V_8 ) ;
V_7 -> V_8 = NULL ;
return - V_11 ;
}
return 0 ;
}
int F_6 ( void * V_1 , T_1 V_2 , unsigned char V_3 ,
const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
V_7 -> V_12 = F_2 ( V_4 , V_5 ) ;
if ( ! V_7 -> V_12 )
return - V_9 ;
return 0 ;
}
int F_7 ( void * V_1 , T_1 V_2 , unsigned char V_3 ,
const void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
V_7 -> V_13 = F_2 ( V_4 , V_5 ) ;
if ( ! V_7 -> V_13 )
return - V_9 ;
if ( V_10 && ( F_3 ( V_7 -> V_13 ) != 256 &&
F_3 ( V_7 -> V_13 ) != 384 ) ) {
F_4 ( L_1 ) ;
F_5 ( V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
return - V_11 ;
}
return 0 ;
}
static void F_8 ( struct V_6 * V_7 )
{
F_5 ( V_7 -> V_8 ) ;
F_5 ( V_7 -> V_12 ) ;
F_5 ( V_7 -> V_13 ) ;
V_7 -> V_8 = NULL ;
V_7 -> V_12 = NULL ;
V_7 -> V_13 = NULL ;
}
void F_9 ( struct V_6 * V_7 )
{
F_8 ( V_7 ) ;
}
int F_10 ( struct V_6 * V_6 , const void * V_7 ,
unsigned int V_14 )
{
int V_15 ;
F_8 ( V_6 ) ;
V_15 = F_11 ( & V_16 , V_6 , V_7 , V_14 ) ;
if ( V_15 < 0 )
goto error;
return 0 ;
error:
F_8 ( V_6 ) ;
return V_15 ;
}
