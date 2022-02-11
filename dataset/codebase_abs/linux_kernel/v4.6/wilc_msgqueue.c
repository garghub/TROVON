int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 , 0 ) ;
F_4 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = false ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_2 -> V_7 = true ;
while ( V_2 -> V_6 > 0 ) {
F_6 ( & V_2 -> V_4 ) ;
V_2 -> V_6 -- ;
}
while ( ! F_7 ( & V_2 -> V_5 ) ) {
V_9 = F_8 ( & V_2 -> V_5 , struct V_8 , V_10 ) ;
F_9 ( & V_9 -> V_10 ) ;
F_10 ( V_9 -> V_11 ) ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 ,
const void * V_12 , T_1 V_13 )
{
unsigned long V_14 ;
struct V_8 * V_15 = NULL ;
if ( ! V_2 || ( V_13 == 0 ) || ! V_12 )
return - V_16 ;
if ( V_2 -> V_7 )
return - V_17 ;
V_15 = F_12 ( sizeof( * V_15 ) , V_18 ) ;
if ( ! V_15 )
return - V_19 ;
V_15 -> V_20 = V_13 ;
F_4 ( & V_15 -> V_10 ) ;
V_15 -> V_11 = F_13 ( V_12 , V_13 , V_18 ) ;
if ( ! V_15 -> V_11 ) {
F_10 ( V_15 ) ;
return - V_19 ;
}
F_14 ( & V_2 -> V_3 , V_14 ) ;
F_15 ( & V_15 -> V_10 , & V_2 -> V_5 ) ;
F_16 ( & V_2 -> V_3 , V_14 ) ;
F_6 ( & V_2 -> V_4 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 ,
void * V_21 , T_1 V_22 , T_1 * V_23 )
{
struct V_8 * V_9 ;
unsigned long V_14 ;
if ( ! V_2 || ( V_22 == 0 ) || ! V_21 || ! V_23 )
return - V_16 ;
if ( V_2 -> V_7 )
return - V_17 ;
F_14 ( & V_2 -> V_3 , V_14 ) ;
V_2 -> V_6 ++ ;
F_16 ( & V_2 -> V_3 , V_14 ) ;
F_18 ( & V_2 -> V_4 ) ;
F_14 ( & V_2 -> V_3 , V_14 ) ;
if ( F_7 ( & V_2 -> V_5 ) ) {
F_16 ( & V_2 -> V_3 , V_14 ) ;
F_6 ( & V_2 -> V_4 ) ;
return - V_17 ;
}
V_9 = F_8 ( & V_2 -> V_5 , struct V_8 , V_10 ) ;
if ( V_22 < V_9 -> V_20 ) {
F_16 ( & V_2 -> V_3 , V_14 ) ;
F_6 ( & V_2 -> V_4 ) ;
return - V_24 ;
}
V_2 -> V_6 -- ;
memcpy ( V_21 , V_9 -> V_11 , V_9 -> V_20 ) ;
* V_23 = V_9 -> V_20 ;
F_9 ( & V_9 -> V_10 ) ;
F_10 ( V_9 -> V_11 ) ;
F_10 ( V_9 ) ;
F_16 ( & V_2 -> V_3 , V_14 ) ;
return 0 ;
}
