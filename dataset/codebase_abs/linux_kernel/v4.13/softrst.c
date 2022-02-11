static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 ,
V_2 ) ;
int V_6 = V_3 / V_5 -> V_7 ;
int V_8 = V_3 % V_5 -> V_7 ;
if ( V_5 -> V_9 & V_10 ) {
F_3 ( F_4 ( V_8 ) | ( F_4 ( V_8 ) << 16 ) ,
V_5 -> V_11 + ( V_6 * 4 ) ) ;
} else {
unsigned long V_9 ;
T_1 V_12 ;
F_5 ( & V_5 -> V_13 , V_9 ) ;
V_12 = F_6 ( V_5 -> V_11 + ( V_6 * 4 ) ) ;
F_3 ( V_12 | F_4 ( V_8 ) , V_5 -> V_11 + ( V_6 * 4 ) ) ;
F_7 ( & V_5 -> V_13 , V_9 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 ,
V_2 ) ;
int V_6 = V_3 / V_5 -> V_7 ;
int V_8 = V_3 % V_5 -> V_7 ;
if ( V_5 -> V_9 & V_10 ) {
F_3 ( ( F_4 ( V_8 ) << 16 ) , V_5 -> V_11 + ( V_6 * 4 ) ) ;
} else {
unsigned long V_9 ;
T_1 V_12 ;
F_5 ( & V_5 -> V_13 , V_9 ) ;
V_12 = F_6 ( V_5 -> V_11 + ( V_6 * 4 ) ) ;
F_3 ( V_12 & ~ F_4 ( V_8 ) , V_5 -> V_11 + ( V_6 * 4 ) ) ;
F_7 ( & V_5 -> V_13 , V_9 ) ;
}
return 0 ;
}
void T_2 F_9 ( struct V_14 * V_15 ,
unsigned int V_16 ,
void T_3 * V_17 , T_4 V_9 )
{
struct V_4 * V_5 ;
int V_18 ;
V_5 = F_10 ( sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 )
return;
F_11 ( & V_5 -> V_13 ) ;
V_5 -> V_11 = V_17 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_16 = V_16 ;
V_5 -> V_7 = ( V_9 & V_10 ) ? 16
: 32 ;
V_5 -> V_2 . V_20 = V_21 ;
V_5 -> V_2 . V_22 = V_16 * V_5 -> V_7 ;
V_5 -> V_2 . V_23 = & V_24 ;
V_5 -> V_2 . V_25 = V_15 ;
V_18 = F_12 ( & V_5 -> V_2 ) ;
if ( V_18 ) {
F_13 ( L_1 ,
V_26 , V_18 ) ;
F_14 ( V_5 ) ;
}
}
