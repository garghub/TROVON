static T_1 F_1 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_9 = F_2 ( V_7 -> V_10 , V_7 -> V_9 ) ;
return F_3 ( V_3 , V_4 , V_5 , V_7 -> V_10 , V_9 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_11 * V_11 = V_2 -> V_8 ;
unsigned int V_12 ;
char V_13 [ 30 ] ;
int V_14 ;
V_12 = V_11 -> V_12 > V_15 ? V_15 : V_11 -> V_12 ;
V_14 = snprintf ( V_13 , 30 , L_1 , V_16 [ V_12 ] ,
V_11 -> V_12 ) ;
return F_3 ( V_3 , V_4 , V_5 , V_13 , V_14 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_11 * V_11 = V_2 -> V_8 ;
char V_13 [ 100 ] ;
int V_14 ;
V_14 = snprintf ( V_13 , sizeof( V_13 ) , L_2 , V_11 -> V_17 ) ;
return F_3 ( V_3 , V_4 , V_5 , V_13 , V_14 ) ;
}
void F_6 ( struct V_18 * V_19 )
{
F_7 ( V_19 ) ;
}
struct V_18 * F_8 ( const char * V_17 , struct V_11 * V_11 ,
struct V_6 * V_7 )
{
struct V_18 * V_19 ;
V_19 = F_9 ( V_17 , 0400 , V_11 -> V_20 ,
V_7 , & V_21 ) ;
if ( ! V_19 ) {
F_10 ( & V_11 -> V_22 , L_3 ) ;
return NULL ;
}
return V_19 ;
}
void F_11 ( struct V_11 * V_11 )
{
if ( ! V_11 -> V_20 )
return;
F_12 ( V_11 -> V_20 ) ;
}
void F_13 ( struct V_11 * V_11 )
{
struct V_23 * V_22 = & V_11 -> V_22 ;
if ( ! V_24 )
return;
V_11 -> V_20 = F_14 ( F_15 ( V_22 ) , V_24 ) ;
if ( ! V_11 -> V_20 )
return;
F_9 ( L_4 , 0400 , V_11 -> V_20 ,
V_11 , & V_25 ) ;
F_9 ( L_5 , 0400 , V_11 -> V_20 ,
V_11 , & V_26 ) ;
}
void T_5 F_16 ( void )
{
if ( F_17 () ) {
V_24 = F_14 ( V_27 , NULL ) ;
if ( ! V_24 )
F_18 ( L_6 ) ;
}
}
void T_6 F_19 ( void )
{
if ( V_24 )
F_7 ( V_24 ) ;
}
