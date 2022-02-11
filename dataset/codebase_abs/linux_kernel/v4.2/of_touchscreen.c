static bool F_1 ( struct V_1 * V_2 ,
const char * V_3 ,
unsigned int V_4 ,
unsigned int * V_5 )
{
T_1 V_6 ;
int error ;
error = F_2 ( V_2 , V_3 , & V_6 ) ;
if ( error ) {
* V_5 = V_4 ;
return false ;
}
* V_5 = V_6 ;
return true ;
}
static void F_3 ( struct V_7 * V_8 ,
unsigned long V_9 ,
int V_10 , int V_11 )
{
struct V_12 * V_13 ;
if ( ! F_4 ( V_9 , V_8 -> V_14 ) ) {
if ( ! F_5 ( V_9 ) )
F_6 ( & V_8 -> V_8 ,
L_1 ) ;
return;
}
V_13 = & V_8 -> V_13 [ V_9 ] ;
V_13 -> V_15 = V_10 ;
V_13 -> V_11 = V_11 ;
}
void F_7 ( struct V_7 * V_8 , bool V_16 )
{
struct V_1 * V_2 = V_8 -> V_8 . V_17 -> V_18 ;
unsigned int V_9 ;
unsigned int V_15 , V_11 ;
bool V_19 ;
F_8 ( V_8 ) ;
if ( ! V_8 -> V_13 )
return;
V_9 = V_16 ? V_20 : V_21 ;
V_19 = F_1 ( V_2 , L_2 ,
F_9 ( V_8 , V_9 ) ,
& V_15 ) |
F_1 ( V_2 , L_3 ,
F_10 ( V_8 , V_9 ) ,
& V_11 ) ;
if ( V_19 )
F_3 ( V_8 , V_9 , V_15 , V_11 ) ;
V_9 = V_16 ? V_22 : V_23 ;
V_19 = F_1 ( V_2 , L_4 ,
F_9 ( V_8 , V_9 ) ,
& V_15 ) |
F_1 ( V_2 , L_5 ,
F_10 ( V_8 , V_9 ) ,
& V_11 ) ;
if ( V_19 )
F_3 ( V_8 , V_9 , V_15 , V_11 ) ;
V_9 = V_16 ? V_24 : V_25 ;
V_19 = F_1 ( V_2 , L_6 ,
F_9 ( V_8 , V_9 ) ,
& V_15 ) |
F_1 ( V_2 , L_7 ,
F_10 ( V_8 , V_9 ) ,
& V_11 ) ;
if ( V_19 )
F_3 ( V_8 , V_9 , V_15 , V_11 ) ;
}
