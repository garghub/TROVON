static void F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 )
{
V_1 -> V_2 = V_3 ;
}
int F_2 ( struct V_1 * V_1 , struct V_4 * V_4 ,
bool * V_5 )
{
const char * V_6 ;
enum V_7 V_7 ;
struct V_2 * V_3 = V_8 ;
int V_9 ;
if ( V_1 -> V_10 ) {
F_3 ( L_1 ,
V_4 -> V_11 -> V_12 ) ;
if ( V_5 )
* V_5 = true ;
return 0 ;
}
if ( ! V_1 -> V_13 -> V_14 -> V_15 || ! V_1 -> V_13 -> V_14 -> V_15 -> V_6 )
goto V_16;
V_7 = F_4 ( V_4 -> V_11 , V_1 -> V_13 -> V_14 ) ;
if ( V_7 == V_17 )
return 0 ;
V_6 = F_5 ( V_1 -> V_13 -> V_14 -> V_15 -> V_6 ) ;
if ( ! strcmp ( V_6 , L_2 ) ) {
if ( V_7 != V_18 )
V_3 = V_19 ;
} else if ( ! strcmp ( V_6 , L_3 ) || ! strcmp ( V_6 , L_4 ) ) {
if ( V_7 == V_18 )
V_3 = V_20 ;
}
if ( ! V_3 ) {
F_6 ( L_5 , V_6 ) ;
return 0 ;
}
V_16:
F_1 ( V_1 , V_3 ) ;
V_9 = V_1 -> V_2 -> V_21 ( V_1 ) ;
if ( V_5 )
* V_5 = V_9 ? false : true ;
return V_9 ;
}
void F_7 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 )
V_1 -> V_2 -> V_22 ( V_1 ) ;
}
void F_8 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 )
V_1 -> V_2 -> V_23 ( V_1 ) ;
}
int F_9 ( T_1 V_24 , void * V_25 ,
struct V_1 * V_1 ,
struct V_26 * V_27 , int V_28 )
{
if ( V_1 -> V_2 )
return V_1 -> V_2 -> V_29 ( V_24 , V_25 , V_1 , V_27 , V_28 ) ;
return 0 ;
}
