struct V_1 *
F_1 ( const struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_1 * V_4 = NULL ;
if ( ! V_2 )
return NULL ;
if ( ! V_3 ) {
struct V_1 * V_5 ;
V_5 = F_2 ( V_2 , L_1 ) ;
if ( V_5 )
V_2 = V_5 ;
V_4 = F_2 ( V_2 , L_2 ) ;
F_3 ( V_5 ) ;
} else {
struct V_1 * V_5 ;
V_5 = F_4 ( V_3 ) ;
if ( ! V_5 )
return NULL ;
do {
V_4 = F_5 ( V_5 , V_3 ) ;
if ( ! V_4 ) {
F_3 ( V_5 ) ;
return NULL ;
}
V_3 = V_4 ;
} while ( F_6 ( V_4 -> V_6 , L_2 ) != 0 );
}
return V_4 ;
}
struct V_1 *
F_7 ( const struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_1 * V_7 = NULL ;
if ( ! V_2 )
return NULL ;
do {
V_7 = F_5 ( V_2 , V_3 ) ;
if ( ! V_7 )
return NULL ;
V_3 = V_7 ;
} while ( F_6 ( V_7 -> V_6 , L_3 ) != 0 );
return V_7 ;
}
static struct V_1 *
F_8 ( const struct V_1 * V_8 )
{
struct V_1 * V_9 ;
int V_10 ;
V_9 = F_9 ( V_8 , L_4 , 0 ) ;
if ( ! V_9 )
return NULL ;
V_9 = F_10 ( V_9 ) ;
for ( V_10 = 0 ; V_10 < 3 && V_9 ; ++ V_10 ) {
struct V_11 * V_12 ;
V_12 = F_11 ( V_9 , L_5 , NULL ) ;
if ( V_12 )
return V_9 ;
V_9 = F_10 ( V_9 ) ;
}
return NULL ;
}
struct V_1 *
F_12 ( const struct V_1 * V_2 )
{
struct V_1 * V_4 , * V_7 ;
V_4 = F_1 ( V_2 , NULL ) ;
if ( ! V_4 )
return NULL ;
V_7 = F_7 ( V_4 , NULL ) ;
F_3 ( V_4 ) ;
return V_7 ;
}
struct V_13 *
F_13 ( struct V_1 * V_8 )
{
struct V_1 * V_7 ;
struct V_1 * V_14 ;
struct V_13 * V_15 ;
V_7 = F_12 ( V_8 ) ;
if ( ! V_7 )
return F_14 ( - V_16 ) ;
V_14 = F_8 ( V_7 ) ;
F_3 ( V_7 ) ;
if ( ! V_14 )
return F_14 ( - V_16 ) ;
V_15 = F_15 ( V_14 ) ;
F_3 ( V_14 ) ;
if ( ! V_15 )
return F_14 ( - V_17 ) ;
return V_15 ;
}
