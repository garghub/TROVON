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
static void F_3 ( struct V_7 * V_2 ,
unsigned long V_8 ,
int V_9 , int V_10 )
{
struct V_11 * V_12 ;
if ( ! F_4 ( V_8 , V_2 -> V_13 ) ) {
F_5 ( & V_2 -> V_2 ,
L_1 ,
V_8 ) ;
return;
}
V_12 = & V_2 -> V_12 [ V_8 ] ;
V_12 -> V_14 = V_9 ;
V_12 -> V_10 = V_10 ;
}
void F_6 ( struct V_7 * V_15 , bool V_16 )
{
struct V_1 * V_2 = V_15 -> V_2 . V_17 ;
unsigned int V_8 ;
unsigned int V_14 , V_10 ;
bool V_18 ;
F_7 ( V_15 ) ;
if ( ! V_15 -> V_12 )
return;
V_8 = V_16 ? V_19 : V_20 ;
V_18 = F_1 ( V_2 , L_2 ,
F_8 ( V_15 ,
V_8 ) + 1 ,
& V_14 ) |
F_1 ( V_2 , L_3 ,
F_9 ( V_15 , V_8 ) ,
& V_10 ) ;
if ( V_18 )
F_3 ( V_15 , V_8 , V_14 - 1 , V_10 ) ;
V_8 = V_16 ? V_21 : V_22 ;
V_18 = F_1 ( V_2 , L_4 ,
F_8 ( V_15 ,
V_8 ) + 1 ,
& V_14 ) |
F_1 ( V_2 , L_5 ,
F_9 ( V_15 , V_8 ) ,
& V_10 ) ;
if ( V_18 )
F_3 ( V_15 , V_8 , V_14 - 1 , V_10 ) ;
V_8 = V_16 ? V_23 : V_24 ;
V_18 = F_1 ( V_2 ,
L_6 ,
F_8 ( V_15 , V_8 ) ,
& V_14 ) |
F_1 ( V_2 ,
L_7 ,
F_9 ( V_15 , V_8 ) ,
& V_10 ) ;
if ( V_18 )
F_3 ( V_15 , V_8 , V_14 , V_10 ) ;
}
