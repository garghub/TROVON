static inline unsigned int F_1 ( T_1 V_1 )
{
return F_2 ( V_2 , V_1 ) ;
}
static inline unsigned int F_3 ( T_1 V_1 )
{
return F_2 ( V_3 , V_1 ) ;
}
static inline unsigned int F_4 ( T_1 V_1 )
{
return F_2 ( V_4 , V_1 ) ;
}
static inline unsigned int F_5 ( T_1 V_1 )
{
return F_2 ( V_5 , V_1 ) ;
}
static const char * F_6 ( T_1 V_1 )
{
unsigned int V_6 = F_4 ( V_1 ) & 0xf0 ;
unsigned int V_7 = F_1 ( V_1 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_7 ( V_9 ) ; ++ V_8 ) {
if ( V_9 [ V_8 ] . V_10 == V_7 &&
V_9 [ V_8 ] . V_11 == V_6 )
return V_9 [ V_8 ] . V_12 ;
}
return L_1 ;
}
static const char * F_8 ( T_1 V_1 )
{
unsigned int V_13 = F_1 ( V_1 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < F_7 ( V_14 ) ; ++ V_8 ) {
if ( V_14 [ V_8 ] . V_13 == V_13 )
return V_14 [ V_8 ] . V_12 ;
}
return L_1 ;
}
int T_2 F_9 ( void )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_21 ;
unsigned int V_1 ;
struct V_22 * V_23 ;
int V_24 ;
V_20 = F_10 ( NULL , NULL , L_2 ) ;
if ( ! V_20 )
return - V_25 ;
if ( ! F_11 ( V_20 ) )
return - V_25 ;
if ( ! F_12 ( V_20 , L_3 ) )
return - V_25 ;
V_21 = F_13 ( V_20 ) ;
F_14 ( V_20 ) ;
if ( F_15 ( V_21 ) ) {
F_16 ( L_4 , V_26 ) ;
return - V_25 ;
}
V_24 = F_17 ( V_21 , V_27 , & V_1 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( ! V_1 ) {
F_16 ( L_5 , V_26 ) ;
return - V_28 ;
}
V_16 = F_18 ( sizeof( * V_16 ) , V_29 ) ;
if ( ! V_16 )
return - V_25 ;
V_16 -> V_30 = L_6 ;
V_20 = F_19 ( L_7 ) ;
F_20 ( V_20 , L_8 , & V_16 -> V_31 ) ;
F_14 ( V_20 ) ;
V_16 -> V_32 = F_21 ( V_29 , L_9 ,
F_1 ( V_1 ) ,
F_3 ( V_1 ) ,
F_4 ( V_1 ) ,
F_5 ( V_1 ) ) ;
V_16 -> V_33 = F_21 ( V_29 , L_10 ,
F_8 ( V_1 ) ,
F_6 ( V_1 ) ) ;
V_18 = F_22 ( V_16 ) ;
if ( F_15 ( V_18 ) ) {
F_23 ( V_16 -> V_32 ) ;
F_24 ( V_16 -> V_33 ) ;
F_23 ( V_16 ) ;
return F_25 ( V_18 ) ;
}
V_23 = F_26 ( V_18 ) ;
F_27 ( V_23 , L_11 ,
V_16 -> V_33 ,
F_1 ( V_1 ) ,
F_3 ( V_1 ) ,
F_4 ( V_1 ) ,
F_5 ( V_1 ) ) ;
return 0 ;
}
