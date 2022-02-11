void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
unsigned long V_6 ;
F_3 ( & V_7 , V_6 ) ;
if ( V_5 -> V_3 . V_8 != V_3 -> V_8 ) {
F_4 ( V_5 -> V_9 , V_5 -> V_10 + 2 , V_5 -> V_11 ) ;
F_5 ( V_5 -> V_9 , V_5 -> V_10 + 4 , V_3 -> V_8 ) ;
}
if ( V_5 -> V_3 . V_12 != V_3 -> V_12 ) {
F_4 ( V_5 -> V_9 , V_5 -> V_10 + 2 , V_5 -> V_11 + 1 ) ;
F_5 ( V_5 -> V_9 , V_5 -> V_10 + 4 , V_3 -> V_12 ) ;
}
if ( V_5 -> V_13 )
V_5 -> V_13 ( V_5 -> V_9 , V_1 , V_3 ) ;
F_6 ( & V_7 , V_6 ) ;
V_5 -> V_3 = * V_3 ;
}
void F_7 ( unsigned int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
* V_3 = V_5 -> V_3 ;
}
void F_8 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = F_9 ( V_15 ) ;
struct V_2 V_3 = V_5 -> V_3 ;
V_3 . V_8 |= 1 ;
F_1 ( V_15 -> V_1 , & V_3 ) ;
}
void F_10 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = F_9 ( V_15 ) ;
struct V_2 V_3 = V_5 -> V_3 ;
V_3 . V_8 &= ~ 1 ;
F_1 ( V_15 -> V_1 , & V_3 ) ;
}
int F_11 ( struct V_16 * V_9 , int V_11 , T_1 * V_13 )
{
struct V_4 * V_5 ;
unsigned long V_6 ;
T_2 V_15 ;
int V_17 ;
int V_10 ;
int V_1 ;
int V_18 ;
V_10 = F_12 ( V_9 , V_19 ) ;
if ( ! V_10 )
return - V_20 ;
F_3 ( & V_7 , V_6 ) ;
F_4 ( V_9 , V_10 + 2 , 1 ) ;
F_13 ( V_9 , V_10 + 4 , & V_15 ) ;
F_6 ( & V_7 , V_6 ) ;
V_17 = ( V_15 >> 16 ) & 0xff ;
if ( V_11 > V_17 )
return - V_20 ;
V_5 = F_14 ( sizeof( * V_5 ) , V_21 ) ;
if ( ! V_5 )
return - V_22 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_13 = V_13 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_11 = 0x10 + ( V_11 * 2 ) ;
V_5 -> V_3 . V_8 = 0xffffffff ;
V_5 -> V_3 . V_12 = 0xffffffff ;
V_18 = F_15 ( & V_9 -> V_9 ) ;
V_1 = F_16 ( 0 , V_18 ) ;
if ( V_1 <= 0 ) {
F_17 ( V_5 ) ;
return - V_23 ;
}
F_18 ( V_1 , V_5 ) ;
if ( F_19 ( V_1 , V_9 ) < 0 ) {
F_20 ( V_1 ) ;
return - V_23 ;
}
return V_1 ;
}
int F_21 ( struct V_16 * V_9 , int V_11 )
{
return F_11 ( V_9 , V_11 , NULL ) ;
}
void F_20 ( unsigned int V_1 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_1 ) ;
F_22 ( V_1 , NULL ) ;
F_18 ( V_1 , NULL ) ;
F_23 ( V_1 ) ;
F_17 ( V_5 ) ;
}
