void F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( F_2 ( & V_2 -> V_4 , ( const void * * ) & V_3 ) ) {
F_3 ( & V_2 -> V_5 ) ;
} else {
F_4 ( L_1 , V_2 -> V_6 ) ;
V_2 -> V_7 ( V_2 , V_3 ) ;
}
}
void F_5 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
T_1 V_5 = F_6 ( & V_2 -> V_5 ) ;
F_7 ( V_5 , & V_2 -> V_10 ) ;
F_8 ( V_5 , & V_2 -> V_5 ) ;
F_9 ( V_9 , & V_2 -> V_11 ) ;
}
static void F_10 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_11 ( V_13 , struct V_1 , V_11 ) ;
T_1 V_10 = F_6 ( & V_2 -> V_10 ) ;
void * V_3 = NULL ;
F_8 ( V_10 , & V_2 -> V_10 ) ;
while( V_10 -- )
if ( ! F_12 ( ! F_13 ( & V_2 -> V_4 , & V_3 ) ) )
V_2 -> V_7 ( V_2 , V_3 ) ;
}
int F_14 ( struct V_1 * V_2 , int V_14 ,
const char * V_6 , T_2 V_7 )
{
int V_15 ;
V_2 -> V_6 = V_6 ;
F_15 ( & V_2 -> V_10 , 0 ) ;
F_15 ( & V_2 -> V_5 , 0 ) ;
V_2 -> V_7 = V_7 ;
V_15 = F_16 ( & V_2 -> V_4 , V_14 , V_16 ) ;
if ( V_15 ) {
F_4 ( L_2 , V_6 ) ;
return V_15 ;
}
F_17 ( & V_2 -> V_11 , F_10 ) ;
return 0 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_12 ( ! F_19 ( & V_2 -> V_4 ) ) ;
F_20 ( & V_2 -> V_4 ) ;
}
