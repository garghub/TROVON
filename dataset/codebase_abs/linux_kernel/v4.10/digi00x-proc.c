static int F_1 ( struct V_1 * V_2 ,
enum V_3 * V_4 )
{
T_1 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_8 ,
V_9 + V_10 ,
& V_5 , sizeof( V_5 ) , 0 ) ;
if ( V_6 >= 0 )
* V_4 = F_3 ( V_5 ) & 0x01 ;
return V_6 ;
}
static void F_4 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
static const char * const V_15 [] = {
[ V_16 ] = L_1 ,
[ V_17 ] = L_2 ,
[ V_18 ] = L_3 ,
[ V_19 ] = L_4 ,
} ;
static const char * const V_20 [] = {
[ V_21 ] = L_3 ,
[ V_22 ] = L_2 ,
} ;
struct V_1 * V_2 = V_12 -> V_23 ;
enum V_3 V_4 ;
unsigned int V_24 ;
enum V_25 clock ;
bool V_26 ;
if ( F_1 ( V_2 , & V_4 ) < 0 )
return;
if ( F_5 ( V_2 , & V_24 ) < 0 )
return;
if ( F_6 ( V_2 , & clock ) < 0 )
return;
F_7 ( V_14 , L_5 , V_20 [ V_4 ] ) ;
F_7 ( V_14 , L_6 , V_24 ) ;
F_7 ( V_14 , L_7 , V_15 [ clock ] ) ;
if ( clock == V_16 )
return;
if ( F_8 ( V_2 , & V_26 ) < 0 )
return;
F_7 ( V_14 , L_8 , V_26 ? L_9 : L_10 ) ;
if ( ! V_26 )
return;
if ( F_9 ( V_2 , & V_24 ) >= 0 )
F_7 ( V_14 , L_11 , V_24 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_11 * V_27 , * V_12 ;
V_27 = F_11 ( V_2 -> V_28 , L_12 ,
V_2 -> V_28 -> V_29 ) ;
if ( V_27 == NULL )
return;
V_27 -> V_4 = V_30 | V_31 | V_32 ;
if ( F_12 ( V_27 ) < 0 ) {
F_13 ( V_27 ) ;
return;
}
V_12 = F_11 ( V_2 -> V_28 , L_13 , V_27 ) ;
if ( V_12 == NULL ) {
F_13 ( V_27 ) ;
return;
}
F_14 ( V_12 , V_2 , F_4 ) ;
if ( F_12 ( V_12 ) < 0 ) {
F_13 ( V_12 ) ;
F_13 ( V_27 ) ;
}
}
