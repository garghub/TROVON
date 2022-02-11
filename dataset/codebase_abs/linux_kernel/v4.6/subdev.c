void
F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 )
V_2 -> V_3 -> V_4 ( V_2 ) ;
}
int
F_2 ( struct V_1 * V_2 , bool V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
const char * V_8 = V_5 ? L_1 : L_2 ;
T_1 V_9 = V_2 -> V_9 ;
T_2 time ;
F_3 ( V_2 , L_3 , V_8 ) ;
time = F_4 ( F_5 () ) ;
if ( V_2 -> V_3 -> V_10 ) {
int V_11 = V_2 -> V_3 -> V_10 ( V_2 , V_5 ) ;
if ( V_11 ) {
F_6 ( V_2 , L_4 , V_8 , V_11 ) ;
if ( V_5 )
return V_11 ;
}
}
if ( V_9 ) {
F_7 ( V_7 , 0x000200 , V_9 , 0x00000000 ) ;
F_7 ( V_7 , 0x000200 , V_9 , V_9 ) ;
F_8 ( V_7 , 0x000200 ) ;
}
time = F_4 ( F_5 () ) - time ;
F_3 ( V_2 , L_5 , V_8 , time ) ;
return 0 ;
}
int
F_9 ( struct V_1 * V_2 )
{
T_2 time ;
F_3 ( V_2 , L_6 ) ;
time = F_4 ( F_5 () ) ;
if ( V_2 -> V_3 -> V_12 ) {
int V_11 = V_2 -> V_3 -> V_12 ( V_2 ) ;
if ( V_11 ) {
F_6 ( V_2 , L_7 , V_11 ) ;
return V_11 ;
}
}
time = F_4 ( F_5 () ) - time ;
F_3 ( V_2 , L_8 , time ) ;
return 0 ;
}
int
F_10 ( struct V_1 * V_2 )
{
T_2 time ;
int V_11 ;
F_3 ( V_2 , L_9 ) ;
time = F_4 ( F_5 () ) ;
if ( V_2 -> V_3 -> V_13 && ! V_2 -> V_13 ) {
T_2 time ;
F_3 ( V_2 , L_10 ) ;
time = F_4 ( F_5 () ) ;
V_11 = V_2 -> V_3 -> V_13 ( V_2 ) ;
if ( V_11 ) {
F_6 ( V_2 , L_11 , V_11 ) ;
return V_11 ;
}
V_2 -> V_13 = true ;
time = F_4 ( F_5 () ) - time ;
F_3 ( V_2 , L_12 , time ) ;
}
if ( V_2 -> V_3 -> V_14 ) {
V_11 = V_2 -> V_3 -> V_14 ( V_2 ) ;
if ( V_11 ) {
F_6 ( V_2 , L_13 , V_11 ) ;
return V_11 ;
}
}
time = F_4 ( F_5 () ) - time ;
F_3 ( V_2 , L_14 , time ) ;
return 0 ;
}
void
F_11 ( struct V_1 * * V_15 )
{
struct V_1 * V_2 = * V_15 ;
T_2 time ;
if ( V_2 && ! F_12 ( ! V_2 -> V_3 ) ) {
F_3 ( V_2 , L_15 ) ;
time = F_4 ( F_5 () ) ;
if ( V_2 -> V_3 -> V_16 )
* V_15 = V_2 -> V_3 -> V_16 ( V_2 ) ;
time = F_4 ( F_5 () ) - time ;
F_3 ( V_2 , L_16 , time ) ;
F_13 ( * V_15 ) ;
* V_15 = NULL ;
}
}
void
F_14 ( const struct V_17 * V_3 ,
struct V_6 * V_7 , int V_18 , T_1 V_9 ,
struct V_1 * V_2 )
{
const char * V_19 = V_20 [ V_18 ] ;
V_2 -> V_3 = V_3 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_9 = V_9 ;
F_15 ( & V_2 -> V_21 , V_19 , & V_22 [ V_18 ] ) ;
V_2 -> V_23 = F_16 ( V_7 -> V_24 , V_19 ) ;
}
