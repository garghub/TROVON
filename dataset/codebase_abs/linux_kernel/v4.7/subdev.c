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
T_1 time ;
F_3 ( V_2 , L_3 , V_8 ) ;
time = F_4 ( F_5 () ) ;
if ( V_2 -> V_3 -> V_9 ) {
int V_10 = V_2 -> V_3 -> V_9 ( V_2 , V_5 ) ;
if ( V_10 ) {
F_6 ( V_2 , L_4 , V_8 , V_10 ) ;
if ( V_5 )
return V_10 ;
}
}
F_7 ( V_7 -> V_11 , V_2 -> V_12 ) ;
time = F_4 ( F_5 () ) - time ;
F_3 ( V_2 , L_5 , V_8 , time ) ;
return 0 ;
}
int
F_8 ( struct V_1 * V_2 )
{
T_1 time ;
F_3 ( V_2 , L_6 ) ;
time = F_4 ( F_5 () ) ;
if ( V_2 -> V_3 -> V_13 ) {
int V_10 = V_2 -> V_3 -> V_13 ( V_2 ) ;
if ( V_10 ) {
F_6 ( V_2 , L_7 , V_10 ) ;
return V_10 ;
}
}
time = F_4 ( F_5 () ) - time ;
F_3 ( V_2 , L_8 , time ) ;
return 0 ;
}
int
F_9 ( struct V_1 * V_2 )
{
T_1 time ;
int V_10 ;
F_3 ( V_2 , L_9 ) ;
time = F_4 ( F_5 () ) ;
if ( V_2 -> V_3 -> V_14 && ! V_2 -> V_14 ) {
T_1 time ;
F_3 ( V_2 , L_10 ) ;
time = F_4 ( F_5 () ) ;
V_10 = V_2 -> V_3 -> V_14 ( V_2 ) ;
if ( V_10 ) {
F_6 ( V_2 , L_11 , V_10 ) ;
return V_10 ;
}
V_2 -> V_14 = true ;
time = F_4 ( F_5 () ) - time ;
F_3 ( V_2 , L_12 , time ) ;
}
if ( V_2 -> V_3 -> V_15 ) {
V_10 = V_2 -> V_3 -> V_15 ( V_2 ) ;
if ( V_10 ) {
F_6 ( V_2 , L_13 , V_10 ) ;
return V_10 ;
}
}
time = F_4 ( F_5 () ) - time ;
F_3 ( V_2 , L_14 , time ) ;
return 0 ;
}
void
F_10 ( struct V_1 * * V_16 )
{
struct V_1 * V_2 = * V_16 ;
T_1 time ;
if ( V_2 && ! F_11 ( ! V_2 -> V_3 ) ) {
F_3 ( V_2 , L_15 ) ;
time = F_4 ( F_5 () ) ;
if ( V_2 -> V_3 -> V_17 )
* V_16 = V_2 -> V_3 -> V_17 ( V_2 ) ;
time = F_4 ( F_5 () ) - time ;
F_3 ( V_2 , L_16 , time ) ;
F_12 ( * V_16 ) ;
* V_16 = NULL ;
}
}
void
F_13 ( const struct V_18 * V_3 ,
struct V_6 * V_7 , int V_12 ,
struct V_1 * V_2 )
{
const char * V_19 = V_20 [ V_12 ] ;
V_2 -> V_3 = V_3 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_12 = V_12 ;
F_14 ( & V_2 -> V_21 , V_19 , & V_22 [ V_12 ] ) ;
V_2 -> V_23 = F_15 ( V_7 -> V_24 , V_19 ) ;
}
