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
F_3 ( V_5 ) ;
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
struct V_1 * F_8 ( struct V_1 * V_4 )
{
struct V_1 * V_8 ;
int V_9 ;
if ( ! V_4 )
return NULL ;
V_8 = F_4 ( V_4 ) ;
for ( V_9 = 0 ; V_9 < 2 && V_8 ; ++ V_9 ) {
struct V_10 * V_11 ;
V_11 = F_9 ( V_8 , L_4 , NULL ) ;
if ( V_11 )
return V_8 ;
V_8 = F_10 ( V_8 ) ;
}
return NULL ;
}
T_1 F_11 ( struct V_1 * V_4 )
{
int V_12 ;
T_1 V_13 ;
V_12 = F_12 ( V_4 , L_5 , & V_13 ) ;
if ( V_12 )
V_13 = 0 ;
return V_13 ;
}
static struct V_1 * F_13 ( const struct V_1 * V_14 )
{
struct V_1 * V_8 , * V_15 ;
V_8 = F_14 ( V_14 , L_6 , 0 ) ;
if ( ! V_8 )
return NULL ;
V_15 = F_10 ( V_8 ) ;
F_3 ( V_8 ) ;
return V_15 ;
}
struct V_1 *
F_15 ( const struct V_1 * V_2 )
{
struct V_1 * V_4 , * V_7 ;
V_4 = F_1 ( V_2 , NULL ) ;
if ( ! V_4 )
return NULL ;
V_7 = F_7 ( V_4 , NULL ) ;
F_3 ( V_4 ) ;
return V_7 ;
}
struct V_16 *
F_16 ( struct V_1 * V_14 )
{
struct V_1 * V_7 ;
struct V_1 * V_17 ;
struct V_16 * V_18 ;
V_7 = F_15 ( V_14 ) ;
if ( ! V_7 )
return F_17 ( - V_19 ) ;
V_17 = F_13 ( V_7 ) ;
if ( ! V_17 ) {
F_3 ( V_7 ) ;
return F_17 ( - V_19 ) ;
}
F_3 ( V_7 ) ;
V_18 = F_18 ( V_17 ) ;
F_3 ( V_17 ) ;
return V_18 ? V_18 : F_17 ( - V_20 ) ;
}
